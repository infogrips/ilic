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

   // global variables

   list <IliFile*> all_ilifiles;
   static map <string, IliFile*> all_ilimodels;
   static bool auto_search = true;
   static list<string> ilidirs;

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
      all_ilimodels[name] = this;
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
   
   void set_autosearch(bool auto_search)
   {
      util::auto_search = auto_search;
   }
   
   void set_ilidirs(string dirs)
   {
      while (true) {
         int pos = dirs.find(";"); // for ili2c compatiblity
         if (pos < 0) {
            pos = dirs.find(",");
         }
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
   
   static void add_ilifile(IliFile *ilifile,bool front) 
   {
      if (ilifile == nullptr) {
         return;
      }
      for (IliFile *f : all_ilifiles) {
         if (f->getFilePath() == ilifile->getFilePath()) {
            return;
         }
      }
      if (front) {
         all_ilifiles.push_front(ilifile);
      }
      else {
         all_ilifiles.push_back(ilifile);
      }
   }

   static IliFile* load_ilifile(string filepath)
   {
      
      for (auto f : all_ilifiles) {
         if (f->getFilePath() == filepath) {
            return f;
         }
      }

      Log.debug(">>> load_ilifile(" + filepath + ")");
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
      Log.debug("creating parser");
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
      
      all_ilifiles.push_back(ilifile);

      Log.decNestLevel();
      Log.debug("<<< load_ilifile(" + filepath + ")");

      return ilifile;

   }

   IliFile* load_ilifiles_by_file(string filepath)
   {
      IliFile *f = load_ilifile(filepath);
      if (f != nullptr) {
         add_ilifile(f,false);
         return f;
      }
      else {
         return nullptr;
      }
   }

   IliFile* load_ilifiles_by_model(string modelname)
   {
      
      // model already loaded?
      if (all_ilimodels.find(modelname) != all_ilimodels.end()) {
         return all_ilimodels[modelname];
      }
      
      if (modelname == "INTERLIS") {
         IliFile *interlis = new IliFile("INTERLIS");
         add_ilifile(interlis,true);
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
            Log.info("loading .ili files in directory " + ilidir + " ...");
            for (filesystem::directory_entry entry : filesystem::directory_iterator(ilidir)) {
               string path = entry.path().string();
               if (!ends_with(path, ".ili")) {
                  continue;
               }
               for (IliFile *f : all_ilifiles) {
                  if (path == f->getFilePath()) {
                     continue; // .ili already loaded
                  }
                  IliFile *ff = load_ilifile(path);
                  for (string model : ff->getModels()) {
                     // search for model in .ili file
                     if (model == modelname) {
								ff->setAutoSearch(true);
                        add_ilifile(ff, true);
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

      add_ilifile(ilifile,true);

      return ilifile;
      
   }

}
