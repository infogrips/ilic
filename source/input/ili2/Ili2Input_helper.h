#pragma once

#include <string>
#include <map>
#include <vector>
#include "antlr4-runtime.h"
#include "../parser/generated/Ili2Parser.h"

using namespace std;

namespace input {

   const string ABSTRACT  = "ABSTRACT";
   const string EXTENDED  = "EXTENDED";
   const string FINAL     = "FINAL";
   const string TRANSIENT = "TRANSIENT";
   const string OID       = "OID";
   const string HIDING    = "HIDING";
   const string ORDERED   = "ORDERED";
   const string EXTERNAL  = "EXTERNAL";

   string visitString(antlr4::Token *t);
   map<string,bool> get_properties(parser::Ili2Parser::PropertiesContext *ctx,vector<string> allowed_properties);

}