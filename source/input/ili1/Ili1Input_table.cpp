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

   debug(ctx,">>> visitTableDef(" + name1 + ")");
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

   pop_context();
   Log.decNestLevel();
   debug(ctx,"<<< visitTableDef(" + name1 + ")");
   
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
   debug(ctx,">>> visitAttribute(" + name + ")");
   Log.incNestLevel();

   AttrOrParam *a = new AttrOrParam();
   init_extendableme(a,ctx->attributename->getLine());
   a->Name = name;
   
   push_context(a);
   DomainType *dt;
   if (ctx->type() != nullptr) {
      Type *t = visitType(ctx->type());
      dt = static_cast<DomainType*>(t);
      if (t != nullptr) {
         a->Type = dt;
      }
   }
   else {
      // reference attribute
      string tablename = ctx->tablename->toString();
      ReferenceType *rt = new ReferenceType();
      init_domaintype(rt,ctx->start->getLine());
      dt = static_cast<DomainType*>(rt);
      a->Type = dt;
      // to do !!!
   }
   pop_context();

   if (ctx->OPTIONAL() == nullptr && dt != nullptr) {
      dt->Mandatory = true;
   }
   
   if (ctx->EXPLANATION() != nullptr) {
      // to do !!!
   }

   // ASSOCIATION ClassAttr
   a->AttrParent = get_class_context();
   get_class_context()->ClassAttribute.push_back(a);

   Log.decNestLevel();
   debug(ctx,"<<< visitAttribute(" + name + ")");

   return a;

}

antlrcpp::Any Ili1Input::visitIdentifications(Ili1Parser::IdentificationsContext *ctx)
{

   /* identifications
   : NO IDENT
   | IDENT identification+
   */

   debug(ctx,">>> visitIdentifications()");
   Log.incNestLevel();

   if (ctx->NO() == nullptr) {
      for (auto ictx : ctx->identification()) {
         vector<string> attr_names = visitIdentification(ictx);
         // create constraint, to do !!!
      }
   }
   
   Log.decNestLevel();
   debug(ctx,"<<< visitIdentifications()");
   return nullptr;

}

antlrcpp::Any Ili1Input::visitIdentification(Ili1Parser::IdentificationContext *ctx)
{

   /* identification
   : NAME (COMMA NAME)* SEMI
   */

   debug(ctx,">>> visitIdentification()");
   Log.incNestLevel();

   vector<string> attr_names;
   for (auto n : ctx->NAME()) {
      attr_names.push_back(n->getText());
   }
  
   Log.decNestLevel();
   debug(ctx,"<<< visitIdentification()");

   return attr_names;

}