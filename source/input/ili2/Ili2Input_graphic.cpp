#pragma once

#include "Ili2Input.h"
#include "Ili2Input_helper.h"
#include "../../metamodel/MetaModelInput.h"
#include "../../util/Logger.h"

using namespace input;
using namespace parser;
using namespace metamodel;

/*

   class Graphic : public ExtendableME {
      // MetaElement.Name := Name as defined in the INTERLIS-Model
   public:
      Expression *Where;
      // role from ASSOCIATION GraphicBase
      Class *Base;
      // role from ASSOCIATION GraphicRule
      list<DrawingRule *> DrawingRule;
      virtual string getClass() { return "Graphic"; }
   };

   struct SignParamAssignment : public MMObject {
   public:
      AttrOrParam *Param;
      Expression *Assignment;
      virtual string getClass() { return "SignParamAssignment"; }
   };

   struct CondSignParamAssignment : public MMObject {
   public:
      Expression *Where;
      list<SignParamAssignment *> Assignments;
      virtual string getClass() { return "CondSignParamAssignment"; }
   };

   class DrawingRule : public ExtendableME {
      // MetaElement.Name := Name as defined in the INTERLIS-Model
   public:
      list<CondSignParamAssignment *> Rule;
      // role from ASSOCIATION GraphicRule
      Graphic *Graphic;
      // role from ASSOCIATION SignClass
      Class *Class;
      virtual string getClass() { return "DrawingRule"; }
   };

*/

antlrcpp::Any Ili2Input::visitGraphicDef(parser::Ili2Parser::GraphicDefContext *ctx)
{

   /* graphicDef
   : GRAPHIC graphicname1=NAME properties? // ABSTRACT|FINAL
     (EXTENDS path)?
     (BASED ON path)? EQUAL
     (selection)*
     (drawingRule)*
     END graphicname2=NAME SEMI
   */

   string name1 = ctx->graphicname1->getText();
   string name2 = ctx->graphicname2->getText();
   
   debug(ctx,"visitGrahicDef(" + name1 + ")");
   
   if (name1 != name2) {
      Log.warning(name2 + " does not match " + name1,ctx->graphicname2->getLine());
   }
   
   Graphic *g = new Graphic();
   init_extendableme(g,ctx->start->getLine());

   map<string,bool> properties = get_properties(ctx->properties(),vector({ABSTRACT,FINAL}));
   if (properties[ABSTRACT]) {
      g->Abstract = true;
   }
   else if (properties[FINAL]) {
      g->Final = true;
   }
   
   if (ctx->EXTENDS() != nullptr) {
      // to do !!!
   }
   
   if (ctx->BASED() != nullptr) {
      // to do !!!
      // g->Base = find_graphic(ctx->path());
   }
   
   for (auto s : ctx->selection()) {
      // to do !!!
   }
   
   for (auto r : ctx->drawingRule()) {
      // to do !!!
   }
   
   return g;

}
             
antlrcpp::Any Ili2Input::visitDrawingRule(parser::Ili2Parser::DrawingRuleContext *ctx)
{

   /* drawingRule
   : drawingrulename=NAME properties? // ABSTRACT|EXTENDED|FINAL
     (OF path)?
     COLON condSignParamAssignment (COMMA condSignParamAssignment)* SEMI
   */
   
   string name = ctx->drawingrulename->getText();
   
   debug(ctx,"visitDrawingRule(" + name + ")");
   return nullptr;

}
             
antlrcpp::Any Ili2Input::visitCondSignParamAssignment(parser::Ili2Parser::CondSignParamAssignmentContext *ctx)
{

   /* condSignParamAssignment
   : (WHERE logical=expression)?
     LPAREN signParamAssignment (COMMA signParamAssignment)* RPAREN
   */
   
   debug(ctx,"visitCondSignParamAssignment()");
   return nullptr;

}
             
antlrcpp::Any Ili2Input::visitSignParamAssignment(parser::Ili2Parser::SignParamAssignmentContext *ctx)
{

   /* signParamAssignment
   : signparametername=NAME
     COLONEQUAL ( 
       LCURLY metaObjectRef RCURLY
       | factor
       | ACCORDING enumpath=attributePath
         LPAREN enumAssignment (COMMA enumAssignment)* RPAREN
     )
   */

   debug(ctx,"visitSignParamAssignment");
   return nullptr;

}
