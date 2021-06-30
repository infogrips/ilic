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

   IliFile::IliFile(string ilifile)
   {
      this->filepath = ilifile;
   }

   antlrcpp::Any IliFile::visitIliFile(IliFileParser::IliFileContext *context)
   {
      // root method
      Log.debug("vistIliFile()");
      return visitChildren(context);
   }

   antlrcpp::Any IliFile::visitVersion(IliFileParser::VersionContext *context)
   {
      if (context->majorversion != nullptr) {
         this->iliversion = context->majorversion->getText() + "." + context->minorversion->getText();
      }
      else {
         this->iliversion = "1.0";
      }
      Log.debug("visitVersion(" + this->iliversion + ")");
      return visitChildren(context);
   }

   antlrcpp::Any IliFile::visitModelName(IliFileParser::ModelNameContext *context)
   {
      Log.debug("visitModelName()");
      this->models.push_back(context->modelname->getText());
      return visitChildren(context);
   }

   antlrcpp::Any IliFile::visitTranslationOf(IliFileParser::TranslationOfContext *context)
   {
      Log.debug("vistTranslationOf()");
      return visitChildren(context);
   }

   antlrcpp::Any IliFile::visitModelImport(IliFileParser::ModelImportContext *context)
   {
      Log.debug("vistModelImport()");
      this->imports.push_back(context->modelname->getText());
      return visitChildren(context);
   }

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
         if (pos > 0) {
            ilidirs.push_back(dirs.substr(0,pos));
            dirs = dirs.substr(pos);
         }
         else {
            ilidirs.push_back(dirs);
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

      // create lexer
      ifstream stream;
      stream.open(filepath);
      if (!stream.is_open()) {
         Log.error("unable to open " + filepath);
         return nullptr;
      }
      antlr4::ANTLRInputStream input(stream);
      lexer::IliFileLexer lexer(&input);
      lexer.removeErrorListeners();

      // create parser
      antlr4::CommonTokenStream tokens(&lexer);
      parser::IliFileParser parser(&tokens);
      parser::IliFileParser::IliFileContext *context = parser.iliFile();
      if (context == nullptr) {
         Log.error("unable to parse ili file structure " + filepath);
         return nullptr;
      }

      // run parser
      Log.debug("loading " + filepath + " ...");
      Log.incNestLevel();
      util::IliFile *ilifile = new IliFile(filepath);
      ilifile->visitIliFile(context);
      Log.decNestLevel();
      Log.debug(filepath + " loaded.");

      return ilifile;

   }

   bool loadIliFilesByFile(string filepath)
   {
      addIliFile(loadIliFile(filepath),false);
      return true;
   }

   bool loadIliFilesByModel(string modelname)
   {
      
      // model already loaded?
      for (IliFile *ilifile : AllIliFiles) {
         for (string mname : ilifile->getModels()) {
            if (mname == modelname) {
               return true;
            }
         }
      }
      
      if (modelname == "INTERLIS") {
         IliFile *interlis = new IliFile("INTERLIS");
         addIliFile(interlis,true);
         return true;
      }

      if (!auto_search) {
         Log.error("model " + modelname + " not found (no_auto).");
         return false;
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
                        return true;
                     }
                  }
               }
            }
         }
      }
      if (!stream.is_open()) {
         Log.error("model " + modelname + " not found in ilidirs.");
         return false;
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

      addIliFile(ilifile,true);

      return true;
      
   }

}
