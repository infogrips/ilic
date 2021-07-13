#pragma once

#include "Ili2Input.h"
#include "Ili2Input_helper.h"
#include "../../metamodel/MetaModelInput.h"
#include "../../util/Logger.h"

using namespace input;
using namespace parser;
using namespace metamodel;

antlrcpp::Any Ili2Input::visitViewDef(parser::Ili2Parser::ViewDefContext *ctx)
{

   /* viewDef
   : VIEW viewname1=NAME
     properties? // ABSTRACT|EXTENDED|FINAL|TRANSIENT
     (formationDef | EXTENDS viewref=path)
     (baseExtensionDef)*
     (selection)*
     EQUAL
     ATTRIBUTES?
     viewAttribute*
     constraintDef*
     END viewname2=NAME SEMI
   */

   /* class View : public Class {
   public:
      enum {Projection, Join, Union,
            Aggregation_All, Aggregation_Equal,
            Inspection_Normal, Inspection_Area} FormationKind;

      list<Expression *> FormationParameter; // PathOrInspFactor only
                          // Aggr.Equal: UniqueEl
                          // Inspection: Attributepath
      Expression *Where;
      bool Transient = false;
      // role from ASSOCIATION BaseViewDef
      list<RenamedBaseView *> RenamedBaseView;
      // role from ASSOCIATION DerivedAssoc
      list <Class *> DeriAssoc;
   */

   string name1 = ctx->viewname1->getText();
   string name2 = ctx->viewname2->getText();

   debug(ctx,"visitViewDef(" + name1 + ")");
   
   if (name1 != name2) {
      Log.error(name1 + " expected",get_line(ctx->viewname2));
   }

   View* v = nullptr;
   if (ctx->EXTENDS() != nullptr) {
      View* vv = find_view(visitPath(ctx->viewref),get_line(ctx->viewref));
      v = static_cast<View *>(vv->clone());
   }
   else {
      v = new View();
   }

   v->Name = name1;
   init_class(v,get_line(ctx));
   add_class(v);
      
   /* formationDef
   : (projection | join | iliunion  | aggregation | inspection) SEMI
   */
   
   /* enum {Projection, Join, Union,
         Aggregation_All, Aggregation_Equal,
         Inspection_Normal, Inspection_Area} FormationKind; */

   parser::Ili2Parser::FormationDefContext *fctx = ctx->formationDef();

   if (fctx->projection() != nullptr) {
      /* PROJECTION OF renamedViewableRef
      */
      v->FormationKind = View::Projection;
      // FormationParameter ???, to do !!!
   }
   else if (fctx->join() != nullptr) {
      /* JOIN OF renamedViewableRef
         (COMMA renamedViewableRef (LPAREN OR ILINULL RPAREN)?)+
      */
      v->FormationKind = View::Join;
      // FormationParameter ???, to do !!!
   }
   else if (fctx->iliunion() != nullptr) {
      /* UNION OF renamedViewableRef
         (COMMA renamedViewableRef)*
      */
      v->FormationKind = View::Union;
      // FormationParameter ???, to do !!!
   }
   else if (fctx->aggregation() != nullptr) {
      /* AGGREGATION OF renamedViewableRef
         (ALL | EQUAL LPAREN uniqueEl RPAREN)
      */
      v->FormationKind = View::Aggregation_All; // ???, to do !!!
      // FormationParameter ???, to do !!!
   }
   else {
      /* inspection
      : AREA? INSPECTION OF renamedViewableRef
      (RARROW structureorlineattributename=NAME)+
      */
      if (fctx->inspection()->AREA() != nullptr) {
         v->FormationKind = View::Inspection_Area;
      }
      else {
         v->FormationKind = View::Inspection_Normal;
      }
      // FormationParameter ???, to do !!!
   }
   
   if (ctx->selection().size() == 1) {
      v->Where = visitSelection(ctx->selection().front());
   }
   else if (ctx->selection().size() > 1) {
      CompoundExpr *e = new CompoundExpr();
      e->Operation = CompoundExpr_OperationType::And;
      for (auto sctx : ctx->selection()) {
         e->SubExpressions.push_back(visitSelection(sctx));
      }
      v->Where = e;
   }

   // bool Transient = false;
   
   for (auto actx : ctx->viewAttribute()) {
      visitViewAttribute(actx);
   }
   
   for (auto cctx : ctx->constraintDef()) {
      v->Constraints.push_back(visitConstraintDef(cctx));
   }

   // role from ASSOCIATION BaseViewDef
   // list<RenamedBaseView *> RenamedBaseView;
   // to do !!!

   // role from ASSOCIATION DerivedAssoc
   // list <Class *> DeriAssoc;
   // to do !!!

   return v;
   
}

antlrcpp::Any Ili2Input::visitSelection(parser::Ili2Parser::SelectionContext *ctx)
{

   /* selection
   : WHERE expression SEMI
   */

   debug(ctx,">>> visitSelection()");
   Log.incNestLevel();

   Expression *e = visitExpression(ctx->expression());

   Log.decNestLevel();
   debug(ctx,"<<< visitSelection()");

   return e;
   
}

antlrcpp::Any Ili2Input::visitRenamedViewableRef(parser::Ili2Parser::RenamedViewableRefContext *ctx)
{

   /* renamedViewableRef
   : (basename=NAME TILDE)? path
   */

   /* class RenamedBaseView : public ExtendableME {
      // MetaElement.Name := Name as defined in the INTERLIS-Model
   public:
      bool OrNull = false;
      // role from ASSOCIATION BaseViewDef
      View *View = nullptr;
      // role from ASSOCIATION BaseViewRef
      Class *BaseView = nullptr;
   */

   debug(ctx,">>> renameViewableRef()");
   
   RenamedBaseView *v = new RenamedBaseView();
   v->Name = "";
   if (ctx->basename == nullptr) {
      v->Name = ctx->basename->getText();
   }
   init_extendableme(v,get_line(ctx));
   
   // OrNull, to do !!!
   v->View = find_view(visitPath(ctx->path()),get_line(ctx->path()));
   // BaseView, to do !!!

   debug(ctx,"<<< renameViewableRef() " + v->Name);

   return v;
   
}

antlrcpp::Any Ili2Input::visitBaseExtensionDef(parser::Ili2Parser::BaseExtensionDefContext *ctx)
{

   /* baseExtensionDef
   : BASE basename=NAME EXTENDED BY
     renamedViewableRef (COMMA renamedViewableRef)*
   */

   debug(ctx,">>> visitBaseExtensionDef()");
   // to do !!!
   debug(ctx,"<<< visitBaseExtensionDef()");
   return nullptr;
   
}

antlrcpp::Any Ili2Input::visitViewAttribute(parser::Ili2Parser::ViewAttributeContext *ctx)
{

   /* viewAttribute
   : ALL OF basename=NAME SEMI
   | attributeDef
   | attributename=NAME properties? // ABSTRACT|EXTENDED|FINAL|TRANSIENT
        COLONEQUAL factor SEMI
   */

   debug(ctx,">>> visitViewAttribute()");
   Log.incNestLevel();

   if (ctx->ALL() != nullptr) {
      // to do !!!
   }
   else if (ctx->attributeDef() != nullptr) {
      visitAttributeDef(ctx->attributeDef());
   }
   else {
      // to do !!!
   }
   
   Log.decNestLevel();
   debug(ctx,"<<< visitViewAttribute()");

   return nullptr;

}