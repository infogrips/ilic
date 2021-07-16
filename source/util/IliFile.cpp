#include "stdio.h"
#include <iostream>
#include <filesystem>

// antlr4
#include "Exceptions.h"

#include "../input/parser/generated/IliFileLexer.cpp"
#include "../input/parser/generated/IliFileParser.cpp"

#include "StringUtil.h"
#include "IliFile.h"
#include "Logger.h"

using namespace std;
using namespace parser;

namespace util {

   // constructor

   IliFile::IliFile(string ilifile)
   {
      this->filepath = ilifile;
   }

   // visitor interface

   antlrcpp::Any IliFile::visitIliFile(IliFileParser::IliFileContext *context)
   {
      // root method
      Log.debug(">>> visitIliFile(" + filepath + ")");
      Log.incNestLevel();
      antlrcpp::Any result = visitChildren(context);
      Log.decNestLevel();
      Log.debug("<<< visitILiFile(" + filepath + ")");
      return result;
   }

   antlrcpp::Any IliFile::visitVersion(IliFileParser::VersionContext *context)
   {
      Log.debug(">>> visitVersion()");
      if (context->majorversion != nullptr) {
         this->iliversion = context->majorversion->getText() + "." + context->minorversion->getText();
      }
      else {
         this->iliversion = "1.0";
      }
      antlrcpp::Any result = visitChildren(context);
      Log.debug("<<< visitVersion(" + this->iliversion + ")");
      return result;
   }

   antlrcpp::Any IliFile::visitModelName(IliFileParser::ModelNameContext *context)
   {
      Log.debug(">>> visitModelName()");
      string name = context->modelname->getText();
      this->models.push_back(name);
      antlrcpp::Any result = visitChildren(context);
      Log.debug("<<< visitModelName(" + name + ")");
      return result;
   }

   antlrcpp::Any IliFile::visitTranslationOf(IliFileParser::TranslationOfContext *context)
   {
      Log.debug(">>> vistTranslationOf()");
      Log.incNestLevel();
      antlrcpp::Any result = visitChildren(context);
      Log.decNestLevel();
      Log.debug("<<< vistTranslationOf()");
      return result;
   }

   antlrcpp::Any IliFile::visitModelImport(IliFileParser::ModelImportContext *context)
   {
      Log.debug(">>> vistModelImport()");
      string modelname = context->modelname->getText();
      this->imports.push_back(modelname);
      antlrcpp::Any result = visitChildren(context);
      Log.debug("<<< vistModelImport(" + modelname + ")");
      return result;
   }
   
   // public interface

   string IliFile::getFilePath()
   {
      return filepath;
   }

   string IliFile::getIliVersion()
   {
      return iliversion;
   }

   list<string> IliFile::getImports()
   {
      return imports;
   }

   list<string> IliFile::getModels()
   {
      return models;
   }
   
   void IliFile::setAutoSearch(bool auto_search)
   {
      this->auto_search = auto_search;
   }
   
   bool IliFile::getAutoSearch()
   {
      return auto_search;
   }
   
   list <IliFile *> AllIliFiles;
   static bool auto_search=true;
   static list<string> ilidirs;
   
   void setAutoSearch(bool auto_search)
   {
      util::auto_search = auto_search;
   }
   
   void setIliDirs(string dirs)
   {
      while (true) {
         int pos = dirs.find(";");
         string dir;
         if (pos > 0) {
            dir = dirs.substr(0,pos);
            dirs = dirs.substr(pos+1);
         }
         else {
            dir = dirs;
         }
         if (dir != "" && !filesystem::is_directory(dir)) {
            Log.error("ilidirs: " + dir + " is not a directory");
            exit(1);
         }
         ilidirs.push_back(dir);
         if (pos < 0) {
            break;
         }
      }
   }
   
   static void addIliFile(IliFile *ilifile,bool front) 
   {
      if (ilifile == nullptr) {
         return;
      }
      for (IliFile *f : AllIliFiles) {
         if (f->getFilePath() == ilifile->getFilePath()) {
            return;
         }
      }
      if (front) {
         AllIliFiles.push_front(ilifile);
      }
      else {
         AllIliFiles.push_back(ilifile);
      }
   }

   static IliFile* loadIliFile(string filepath)
   {

      Log.debug(">>> loadIliFile(" + filepath + ")");
      Log.incNestLevel();

      // open file
      Log.debug("opening file " + filepath);
      ifstream stream;
      stream.open(filepath);
      if (!stream.is_open()) {
         Log.error("unable to open " + filepath);
         exit(1);
      }

      // create lexer
      Log.debug("creating lexer");
      antlr4::ANTLRInputStream input(stream);
      lexer::IliFileLexer lexer(&input);
      lexer.removeErrorListeners();

      // create parser
      Log.debug("creating lexer");
      antlr4::CommonTokenStream tokens(&lexer);
      parser::IliFileParser parser(&tokens);
      parser::IliFileParser::IliFileContext *context = parser.iliFile();
      if (context == nullptr) {
         Log.error("unable to parse ili file structure " + filepath);
         return nullptr;
      }

      // run parser
      Log.debug("running parser");
      util::IliFile *ilifile = new IliFile(filepath);
      ilifile->visitIliFile(context);

      Log.decNestLevel();
      Log.debug("<<< loadIliFile(" + filepath + ")");

      return ilifile;

   }

   IliFile* loadIliFilesByFile(string filepath)
   {
      IliFile *f = loadIliFile(filepath);
      if (f != nullptr) {
         addIliFile(f,false);
         return f;
      }
      else {
         return nullptr;
      }
   }

   IliFile* loadIliFilesByModel(string modelname)
   {
      
      // model already loaded?
      for (IliFile *ilifile : AllIliFiles) {
         for (string mname : ilifile->getModels()) {
            if (mname == modelname) {
               return ilifile;
            }
         }
      }
      
      if (modelname == "INTERLIS") {
         IliFile *interlis = new IliFile("INTERLIS");
         addIliFile(interlis,true);
         return interlis;
      }

      if (!auto_search) {
         Log.error("model " + modelname + " not found (no_auto).");
         return nullptr;
      }

      ifstream stream;

      // 1. try: search <modelname>.ili in ilidirs
      string filepath = "";
      for (string ilidir : ilidirs) {
         if (ilidir != "") {
            filepath = ilidir + "\\";
         }
         filepath += modelname + ".ili";
         stream.open(filepath);
         if (stream.is_open()) {
            break;
         }
      }

      if (!stream.is_open()) {

         // 2. try: search in any .ili in ilidirs
         for (string ilidir : ilidirs) {
            if (ilidir == "") {
               ilidir = "./"; // clang does not like empty directory names
            }
            Log.debug("searching .ili files in directory " + ilidir);
            for (filesystem::directory_entry entry : filesystem::directory_iterator(ilidir)) {
               string path = entry.path().string();
               if (!ends_with(path, ".ili")) {
                  continue;
               }
               Log.debug("loading " + path);
               for (IliFile *f : AllIliFiles) {
                  if (path == f->getFilePath()) {
                     continue; // .ili already loaded
                  }
                  IliFile *ff = loadIliFile(path);
                  for (string model : ff->getModels()) {
                     // search for model in .ili file
                     if (model == modelname) {
								ff->setAutoSearch(true);
                        addIliFile(ff, true);
                        return ff;
                     }
                  }
               }
            }
         }
      }
      if (!stream.is_open()) {
         Log.error("model " + modelname + " not found in ilidirs.");
         return nullptr;
      }

      // create lexer
      antlr4::ANTLRInputStream input(stream);
      lexer::IliFileLexer lexer(&input);
      lexer.removeErrorListeners();

      // create parser
      antlr4::CommonTokenStream tokens(&lexer);
      parser::IliFileParser parser(&tokens);
      parser::IliFileParser::IliFileContext *context = parser.iliFile();

      // execute parser
      util::IliFile *ilifile = new IliFile(filepath);
      ilifile->visitIliFile(context);
      ilifile->setAutoSearch(true);

      addIliFile(ilifile,true);

      return ilifile;
      
   }

}
