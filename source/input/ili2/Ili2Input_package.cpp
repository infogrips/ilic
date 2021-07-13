#pragma once

#include "Ili2Input.h"
#include "Ili2Input_helper.h"
#include "../../metamodel/MetaModelInput.h"
#include "../../util/Logger.h"

using namespace input;
using namespace parser;
using namespace metamodel;

extern string input_file;

antlrcpp::Any Ili2Input::visitModelDef(Ili2Parser::ModelDefContext *ctx)
{

   /* modelDef
   : (contracted=CONTRACTED)? 
     (refsystemmodel=REFSYSTEM | symbologymodel=SYMBOLOGY | typemodel=TYPE)? 
     MODEL modelname1=NAME (LPAREN language=NAME RPAREN)?
     {ili24}? (noincrementaltransfer=NOINCREMENTALTRANSFER)?
     ATT issuerurl=string 
     VERSION modelversion=STRING (modelversion_expl=EXPLANATION)?
     (TRANSLATION OF translationOf=NAME LBRACE translationOfVersion=STRING RBRACE)?
     EQUAL
     {ili24}? (CHARSET iananame=STRING SEMI)?
     {ili24}? (XMLNS xmlns=STRING SEMI)?      
     (importDef)*
     (metaDataBasketDef
     |unitDecl
     |functionDef
     |lineFormTypeDef
     |domainDef
     |runTimeParameterDef
     |classDef
     |structureDef
     |topicDef 
     )*
     END modelname2=NAME DOT
   */
   
   string modelname1 = ctx->modelname1->getText();
   if (modelname1 == "ILIC_INTERLIS") {
      modelname1 = "INTERLIS";
   }
   string modelname2 = ctx->modelname2->getText();
   if (modelname2 == "ILIC_INTERLIS") {
      modelname2 = "INTERLIS";
   }

   debug(ctx,">>> visitModelDef(" + ctx->modelname1->getText() + ")");
   Log.incNestLevel();
   if (modelname1 != modelname2) {
      Log.warning(
         "modelname " + modelname2 + " must match " + modelname1,
         ctx->modelname2->getLine()
      );
   }
   
   Model *m = new Model();
   init_package(m,ctx->modelname1->getLine());

   // Model Attributes
   m->Name = modelname1;
   m->iliVersion = iliversion;
   if (ctx->contracted != nullptr) {
      m->Contracted = true;
   }
   else {
      m->Contracted = false;
   }
   if (ctx->typemodel != nullptr) {
      m->Kind = Model::TypeM;
   }
   else if (ctx->refsystemmodel != nullptr) {
      m->Kind = Model::RefSystemM;
   }
   else if (ctx->symbologymodel != nullptr) {
      m->Kind = Model::SymbologyM;
   }
   else {
      m->Kind = Model::NormalM;
   }
   m->Language = ctx->language->getText();
   m->At = visitString(ctx->issuerurl);
   m->Version = visitString(ctx->modelversion);
   if (ctx->modelversion_expl != nullptr) { // nullptr test required, because modelversion_expl is optional
      m->VersionExplanation = ctx->modelversion_expl->getText();
   }

   // Topic ModelTranslation, to do !!!
   // ctx->translationOf->getText();
   // ctx->translationOfVersion->getText();

   if (ili24) {
      if (ctx->NOINCREMENTALTRANSFER() != nullptr) {
         m->NoIncrementalTransfer = true; // 2.4
      }
      if (ctx->iananame != nullptr) {
         m->CharSetIANAName = ctx->iananame->getText(); // 2.4
      }
      if (ctx->xmlns != nullptr) {
         m->xmlns = ctx->xmlns->getText(); // 2.4
         debug(ctx,"xmlns is " + m->xmlns);
      }
   }

   m->_ilifile = input_file;
   add_model(m);
   add_package(m);
   push_context(m);

   visitChildren(ctx);

   pop_context();
   Log.decNestLevel();
   debug(ctx,"<<< visitModelDef(" + ctx->modelname1->getText() + ")");

   return nullptr;

}

antlrcpp::Any Ili2Input::visitImporting(parser::Ili2Parser::ImportingContext *ctx)
{

   /* importDef
   : IMPORTS importing (COMMA importing)* SEMI

   importing
   : UNQUALIFIED? (importname=path)
   */

   debug(ctx,"visitImportDef()");
   Import *i = new Import();
   i->ImportingP = get_package_context();
   i->ImportedP = find_model(ctx->importname->getText(),get_line(ctx));
   if (ctx->UNQUALIFIED() != nullptr) {
      i->_unqualified = true;
   }
   add_import(i);

   return nullptr;

}

static void checkTopicDef(Ili2Parser::TopicDefContext *ctx,SubModel *s)
{
   string topicname1 = ctx->topicname1->getText();
   string topicname2 = ctx->topicname2->getText();
   if (topicname1 != topicname2) {
      Log.warning(
         "topicname " + topicname2 + " must match " + topicname1,
         ctx->topicname2->getLine()
      );
   }
}

antlrcpp::Any Ili2Input::visitTopicDef(Ili2Parser::TopicDefContext *ctx)
{

   /* topicDef
   : VIEW? TOPIC topicname1=NAME
     properties? // ABSTRACT|FINAL
     (EXTENDS topicbase=path)?
     EQUAL
     (BASKET OID AS basketOid=path SEMI)?
     (OID AS topicOid=path SEMI)?
     (DEPENDS ON depTopic=path (COMMA depTopic=path)* SEMI)*
     (metaDataBasketDef
     |unitDecl
     |functionDef
     |domainDef
     |classDef
     |structureDef
     |associationDef
     |constraintsDef
     |viewDef
     |graphicDef
     )*
     END topicname2=NAME SEMI
   */
   
   string name1 = ctx->topicname1->getText();

   debug(ctx,"visitTopicDef(" + name1 + ")");
   Log.incNestLevel();

   // init topic
   SubModel *s = new SubModel();
   init_package(s,ctx->topicname1->getLine());
   DataUnit *d = new DataUnit();
   init_extendableme(d,ctx->topicname1->getLine());
      
   // MetaElement Attributes
   s->Name = name1;

   d->Name = "BASKET";
   d->ElementInPackage = s;
   s->Element.push_back(d);
   
   // ExtendableME Attributes
   if (ctx->properties() != nullptr) {
      map<string,bool> properties = get_properties(ctx->properties(),vector<string>({ABSTRACT,FINAL}));
      d->Abstract = properties[ABSTRACT];
      d->Final = properties[FINAL];
   }

   if (ctx->topicbase != nullptr) {
      s->_super = find_package(visitPath(ctx->topicbase),get_line(ctx->topicbase));
      d->Super = find_dataunit(visitPath(ctx->topicbase),get_line(ctx->topicbase));
      if (d->Super != nullptr) {
         s->_super->_sub.push_back(s);
         d->Super->Sub.push_back(d);
      }
   }

   // DataUnit attributes
   if (ctx->VIEW() != nullptr) {
      d->ViewUnit = true;
   }
   // role from ASSOCIATION MetaDataUnit, to do !!!
   if (ctx->basketOid != nullptr) {
      d->Oid = find_domaintype(ctx->basketOid->getText(),get_line(ctx->basketOid));
   }
   if (ctx->topicOid != nullptr) {
      // topicOid where???, to do !!!
      // s->Oid = find_domaintype(ctx->topicOid->getText());
   }

   if (ctx->DEPENDS().size() > 0) {
      // (DEPENDS ON depTopic=path (COMMA depTopic=path)* SEMI)*
      /* class Dependency : public MMObject { // m:n ASSOCIATION
         DataUnit *Using = nullptr;
         DataUnit *Dependent = nullptr;
      */
      for (auto p : ctx->path()) {
         string path = visitPath(p);
         DataUnit *du = find_dataunit(path,get_line(ctx));
         if (du != nullptr) {
            Dependency *dd = new Dependency();
            init_mmobject(dd,p->start->getLine());
            dd->Using = d;
            dd->Dependent = du;
            add_dependency(dd);
         }
      }
   }

   checkTopicDef(ctx,s);
   add_dataunit(d);
   add_package(s);
   push_context(s);

   // metaDataBasketDef
   // unitDecl
   // functionDef
   // domainDef
   // classDef
   // structureDef
   // associationDef
   // constraintsDef
   // viewDef
   // graphicDef
   visitChildren(ctx);

   pop_context();
   Log.decNestLevel();

   return nullptr;

};
