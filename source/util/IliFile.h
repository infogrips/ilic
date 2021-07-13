#pragma once

#include <string>
#include <list>

#include "antlr4-runtime.h"

#include "../input/parser/generated/IliFileParserBaseVisitor.h"

using namespace std;

namespace util {

   class IliFile : public parser::IliFileParserBaseVisitor {
   public:

      IliFile(string filepath);

      antlrcpp::Any visitIliFile(parser::IliFileParser::IliFileContext *context) override;
      antlrcpp::Any visitVersion(parser::IliFileParser::VersionContext *context) override;
      antlrcpp::Any visitModelName(parser::IliFileParser::ModelNameContext *context) override;
      antlrcpp::Any visitTranslationOf(parser::IliFileParser::TranslationOfContext *context) override;
      antlrcpp::Any visitModelImport(parser::IliFileParser::ModelImportContext *context) override;

      string getFilePath();
      string getIliVersion();
      list<string> getImports();
      list<string> getModels();
      void setAutoSearch(bool autosearch);
      bool getAutoSearch();

   private:

      string filepath = "";
      string iliversion = "2.3";
      string translation_of = "";
      list<string> imports;
      list<string> models;      
      bool auto_search = false;

   };

   extern list<IliFile *> AllIliFiles;
   void setAutoSearch(bool auto_search);
   void setIliDirs(string ilidirs);
   IliFile* loadIliFilesByFile(string filepath);
   IliFile* loadIliFilesByModel(string modelname);

};
