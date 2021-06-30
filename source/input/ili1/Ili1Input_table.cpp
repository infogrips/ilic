#pragma once

#include "Ili1Input.h"
#include "../../metamodel/MetaModelInput.h"
#include "../../util/Logger.h"

using namespace input;
using namespace parser;
using namespace metamodel;

antlrcpp::Any Ili1Input::visitTableDef(Ili1Parser::TableDefContext *ctx)
{

   /* tableDef
   : OPTIONAL?
     TABLE
     tablename1=NAME EQUAL
     attribute+
     identifications
     END tablename2=NAME SEMI
   */

   string name1 = ctx->tablename1->getText();
   string name2 = ctx->tablename2->getText();

   Log.debug("visitTableDef(" + name1 + ")");
   Log.incNestLevel();

   if (name1 != name2) {
      Log.error(
         "classname " + name2 + " must match " + name1,
         ctx->tablename2->getLine()
      );
   }

   Class *c = new Class();

   // Class Attributes
   c->Name = name1;
   c->Kind = Class::ClassVal;
   if (ctx->OPTIONAL() != nullptr) {
      c->ili1OptionalTable = true;
   }
   list<metamodel::AttrOrParam *> classattribute;
   c->ClassAttribute = classattribute;

   // ASSOCIATION PackageElements
   c->ElementInPackage = get_package_context();
   push_context(c);

   for (auto actx : ctx->attribute()) {
      visitAttribute(actx);
   }
   
   visitIdentifications(ctx->identifications());

   Log.decNestLevel();
   
   return c;

}

antlrcpp::Any Ili1Input::visitAttribute(Ili1Parser::AttributeContext *ctx)
{

   /* attribute
   : attributename=NAME
     COLON
     OPTIONAL?
     (type | RARROW tablename=NAME)
     (explanation=EXPLANATION)?
     SEMI
   */

   string name = ctx->attributename->getText();
   Log.debug("visitAttribute(" + name + ")");

   if (ctx->OPTIONAL() != nullptr) {
      // to do !!!
   }
   
   if (ctx->type() != nullptr) {
      DomainType *t = visitType(ctx->type());
      // to do !!!
   }
   else {
      // reference attribute
      string tablename = ctx->tablename->toString();
      // to do !!!
   }

   if (ctx->EXPLANATION() != nullptr) {
      // to do !!!
   }

   return nullptr;

}

antlrcpp::Any Ili1Input::visitIdentifications(Ili1Parser::IdentificationsContext *ctx)
{

   /* identifications
   : NO IDENT
   | IDENT identification+
   */

   Log.debug("visitIdentifications()");

   if (ctx->NO() != nullptr) {
      return nullptr;
   }
   
   for (auto ictx : ctx->identification()) {
      string attr_names = visitIdentification(ictx);
      // create constraint, to do !!!
   }
   
   return nullptr;

}

antlrcpp::Any Ili1Input::visitIdentification(Ili1Parser::IdentificationContext *ctx)
{

   /* identification
   : NAME (COMMA NAME)* SEMI
   */

   Log.debug("visitIdentifications()");

   vector<string> attr_names;
   for (auto n : ctx->NAME()) {
      attr_names.push_back(n->getText());
   }
  
   return attr_names;

}