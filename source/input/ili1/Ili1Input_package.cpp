#pragma once

#include "Ili1Input.h"
#include "../../metamodel/MetaModelInput.h"
#include "../../util/Logger.h"

using namespace input;
using namespace parser;
using namespace metamodel;

antlrcpp::Any Ili1Input::visitModelDef(Ili1Parser::ModelDefContext *ctx)
{
   
   /*
   class Model : public Package {
   public:
      string ili Version;
      bool Contracted = false;
      enum { NormalM, TypeM, RefSystemM, SymbologyM } Kind;
      string Language;
      string At;
      string Version;
      string VersionExplanation;
      bool NoIncrementalTransfer = true; // 2.4
      string CharSetIANAName; // 2.4
      string xmlns; // 2.4
      string ili1Transfername;
      Ili1Format *ili1Format;
   };
   */

   /* modelDef
   : MODEL modelname1=NAME
     domainDefs?
     topicDef+
     END modelname2=NAME DOT
   */

   string modelname1 = ctx->modelname1->getText();
   string modelname2 = ctx->modelname2->getText();

   debug(ctx,">>> visitModelDef(" + modelname1 + ")");
   Log.incNestLevel();

   if (modelname1 != modelname2) {
      Log.error(
         "modelname " + modelname2 + " must match " + modelname1,
         ctx->modelname2->getLine()
      );
   }

   Model *m = new Model();
   init_package(m,ctx->modelname1->getLine());

   // Package -> MetaElement, to do !!!

   // Model Attributes
   m->Name = ctx->modelname1->getText();
   m->iliVersion = "1.0";
   m->Version = "";
   m->Contracted = false;
   m->Kind = Model::NormalM;
   m->Language = "";

   push_context(m);
   add_model(m);
   
   if (ctx->domainDefs() != nullptr) {
      visitDomainDefs(ctx->domainDefs());
   }
   
   for (auto tctx : ctx->topicDef()) {
      SubModel *s = visitTopicDef(tctx);
      s->ElementInPackage = m;
      m->Element.push_back(s);
   }
   
   pop_context();

   Log.decNestLevel();
   debug(ctx,"<<< visitModelDef(" + modelname1 + ")");
   
   return m;

}

antlrcpp::Any Ili1Input::visitTopicDef(Ili1Parser::TopicDefContext *ctx)
{

   /* topicDef
   : TOPIC topicname1=NAME EQUAL
     (tableDef | domainDefs)+
     END topicname2=NAME
     DOT
   */

   string name1 = ctx->topicname1->getText();
   string name2 = ctx->topicname2->getText();

   debug(ctx,">>> visitTopicDef(" + name1 + ")");
   Log.incNestLevel();

   if (name1 != name2) {
      Log.error(
         "topicname " + name2 + " must match " + name1,
         ctx->topicname2->getLine()
      );
   }

   SubModel *s = new SubModel();

   // SubModel Attributes
   s->Name = name1;

   // ASSOCIATION PackageElements
   s->ElementInPackage = get_package_context();
   get_package_context()->Element.push_back(s);
   //add_package(s);
   
   push_context(s);

   for (auto dctx : ctx->domainDefs()) {      
      visitDomainDefs(dctx);
   }
   
   for (auto tctx : ctx->tableDef()) {
      Class *c = visitTableDef(tctx);
      c->ElementInPackage = s;
      s->Element.push_back(c);
   }

   pop_context();

   Log.decNestLevel();
   debug(ctx,"<<< visitTopicDef(" + name1 + ")");

   return s;

};
