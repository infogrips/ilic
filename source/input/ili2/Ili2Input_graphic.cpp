#pragma once

#include "Ili2Input.h"
#include "Ili2Input_helper.h"
#include "../../metamodel/MetaModelInput.h"
#include "../../util/Logger.h"

using namespace input;
using namespace parser;
using namespace metamodel;

/*

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
     (EXTENDS ((INTERLIS DOT)? SIGN | path))?
     (BASED ON path)? EQUAL
     (selection)*
     (drawingRule)*
     END graphicname2=NAME SEMI
   */

   /* class Graphic : public ExtendableME {
      // MetaElement.Name := Name as defined in the INTERLIS-Model
   public:
      Expression *Where;
      // role from ASSOCIATION GraphicBase
      Class *Base;
      // role from ASSOCIATION GraphicRule
      list<DrawingRule *> DrawingRule;
      virtual string getClass() { return "Graphic"; }
   */

   string name1 = ctx->graphicname1->getText();
   string name2 = ctx->graphicname2->getText();
   
   debug(ctx,">>> visitGrahicDef(" + name1 + ")");
   
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
      if (g->Where == nullptr) {
         g->Where = visitSelection(s);
      }
      else {

         /* struct CompoundExpr : public Expression {
         public:
            CompoundExpr_OperationType Operation = Relation_Equal;
            list <Expression *> SubExpressions; // LIST
         */

         if (g->Where->getClass() != "CompoundExpression") {
            CompoundExpr *e = new CompoundExpr();
            e->Operation = CompoundExpr_OperationType::And;
            e->SubExpressions.push_back(g->Where);
            Expression* ee = visitSelection(s);
            e->SubExpressions.push_back(ee);
         }
         else {
            CompoundExpr *e = static_cast<CompoundExpr *>(g->Where);
            Expression* ee = visitSelection(s);
            e->SubExpressions.push_back(ee);
         }
         
      }
   }
   
   for (auto r : ctx->drawingRule()) {
      g->DrawingRule.push_back(visitDrawingRule(r));
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
   
   debug(ctx,">>> visitDrawingRule(" + name + ")");
   Log.incNestLevel();

   DrawingRule *r = new DrawingRule();
   // to do !!!

   Log.decNestLevel();
   debug(ctx,"<<< visitDrawingRule(" + name + ")");
   return r;

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
