#include "Ili2Input_helper.h"
#include "../../util/StringUtil.h"
#include "../../util/Logger.h"

using namespace std;
using namespace util;

void input::debug(antlr4::ParserRuleContext *ctx, string message)
{
   Log.debug(message + ", line=" + to_string(ctx->start->getLine()));
}

string input::visitString(antlr4::Token *t)
{
   string value = t->getText();
   return value.substr(1,value.size()-2);
}
   
map<string,bool> input::get_properties(parser::Ili2Parser::PropertiesContext *ctx,vector<string> allowed_properties)
{

   map<string,bool> properties;
   int line = -1;
   
   if (ctx != nullptr) {
      line = ctx->start->getLine();
   }

   // ABSTRACT
   if (ctx == nullptr) {
      properties[ABSTRACT] = false;
   }
   else if (ctx->ABSTRACT().size() == 0) {
      properties[ABSTRACT] = false;
   }
   else if (ctx->ABSTRACT().size() == 1) {
      if (find_string(allowed_properties,ABSTRACT)) {
         properties[ABSTRACT] = true;
      }
      else {
         Log.error("property " + ABSTRACT + " not allowed",line);
      }
   }
   else if (ctx->ABSTRACT().size() > 1) {
      Log.warning("multiple declarations of " + ABSTRACT,line);
      properties[ABSTRACT] = true;
   }

   // EXTENDED
   if (ctx == nullptr) {
      properties[EXTENDED] = false;
   }
   else if (ctx->EXTENDED().size() == 0) {
      properties[EXTENDED] = false;
   }
   else if (ctx->EXTENDED().size() == 1) {
      if (find_string(allowed_properties,EXTENDED)) {
         properties[EXTENDED] = true;
      }
      else {
         Log.error("property " + EXTENDED + " not allowed",line);
      }
   }
   else if (EXTENDED.size() > 1) {
      Log.warning("multiple declarations of " + EXTENDED,line);
      properties[EXTENDED] = true;
   }

   // FINAL
   if (ctx == nullptr) {
      properties[FINAL] = false;
   }
   else if (ctx->FINAL().size() == 0) {
      properties[FINAL] = false;
   }
   else if (ctx->FINAL().size() == 1) {
      if (find_string(allowed_properties,FINAL)) {
         properties[FINAL] = true;
      }
      else {
         Log.error("property " + FINAL + " not allowed",line);
      }
   }
   else if (ctx->FINAL().size() > 1) {
      Log.warning("multiple declarations of " + FINAL,line);
      properties[FINAL] = true;
   }

   // TRANSIENT
   if (ctx == nullptr) {
      properties[TRANSIENT] = false;      
   }
   else if (ctx->TRANSIENT().size() == 0) {
      properties[TRANSIENT] = false;      
   }
   else if (ctx->TRANSIENT().size() == 1) {
      if (find_string(allowed_properties,TRANSIENT)) {
         properties[TRANSIENT] = true;
      }
      else {
         Log.error("property " + TRANSIENT + " not allowed",line);
      }
   }
   else if (ctx->TRANSIENT().size() > 1) {
      Log.warning("multiple declarations of " + TRANSIENT,line);
      properties[TRANSIENT] = true;
   }

   // OID
   if (ctx == nullptr) {
      properties[OID] = false;      
   }
   else if (ctx->OID().size() == 0) {
      properties[OID] = false;      
   }
   else if (ctx->OID().size() == 1) {
      if (find_string(allowed_properties,OID)) {
         properties[OID] = true;
      }
      else {
         Log.error("property " + OID + " not allowed",line);
      }
   }
   else if (ctx->OID().size() > 1) {
      Log.warning("multiple declarations of " + OID,line);
      properties[OID] = true;
   }

   // HIDING
   if (ctx == nullptr) {
      properties[HIDING] = false;      
   }
   else if (ctx->HIDING().size() == 0) {
      properties[HIDING] = false;      
   }
   else if (ctx->HIDING().size() == 1) {
      if (find_string(allowed_properties,HIDING)) {
         properties[HIDING] = true;
      }
      else {
         Log.error("property " + HIDING + " not allowed",line);
      }
   }
   else if (ctx->HIDING().size() > 1) {
      Log.warning("multiple declarations of " + HIDING,line);
      properties[HIDING] = true;
   }

   // ORDERED
   if (ctx == nullptr) {
      properties[ORDERED] = false;      
   }
   else if (ctx->ORDERED().size() == 0) {
      properties[ORDERED] = false;      
   }
   else if (ctx->ORDERED().size() == 1) {
      if (find_string(allowed_properties,ORDERED)) {
         properties[ORDERED] = true;
      }
      else {
         Log.error("property " + ORDERED + " not allowed",line);
      }
   }
   else if (ctx->ORDERED().size() > 1) {
      Log.warning("multiple declarations of " + ORDERED,line);
      properties[ORDERED] = true;
   }

   // EXTERNAL
   if (ctx == nullptr) {
      properties[EXTERNAL] = false;
   }
   else if (ctx->EXTERNAL().size() == 0) {
      properties[EXTERNAL] = false;
   }
   else if (ctx->EXTERNAL().size() == 1) {
      if (find_string(allowed_properties,EXTERNAL)) {
         properties[EXTERNAL] = true;
      }
      else {
         Log.error("property " + EXTERNAL + " not allowed",line);
      }
   }
   else if (ctx->EXTERNAL().size() > 1) {
      Log.warning("multiple declarations of " + EXTERNAL,line);
      properties[EXTERNAL] = true;
   }
   
   if (properties[ABSTRACT] && properties[FINAL]) {
      Log.error(ABSTRACT + " and " + FINAL + " can not be used at the same time",line);
   }

   return properties;

}
