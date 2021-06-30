#pragma once

#include "Ili2Input.h"
#include "Ili2Input_helper.h"
#include "../../metamodel/MetaModelInput.h"
#include "../../util/Logger.h"

using namespace input;
using namespace parser;
using namespace metamodel;

/*

   class View : public Class {
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
      // list<RenamedBaseView *> RenamedBaseView;
      // role from ASSOCIATION DerivedAssoc
      list <Class *> DeriAssoc;
      virtual string getClass() { return "View"; }
   };

   class RenamedBaseView : public ExtendableME {
      // MetaElement.Name := Name as defined in the INTERLIS-Model
   public:
      bool OrNull = false;
      // role from ASSOCIATION BaseViewDef
      View *View;
      // role from ASSOCIATION BaseViewRef
      Class *BaseView;
      virtual string getClass() { return "ExtendableME"; }
   };

*/

antlrcpp::Any Ili2Input::visitViewDef(parser::Ili2Parser::ViewDefContext *ctx)
{

   /* viewDef
   : VIEW viewname1=NAME
     properties? // ABSTRACT|EXTENDED|FINAL|TRANSIENT
     (formationDef | EXTENDS viewref=path)
     (baseExtensionDef)*
     (selection)*
     EQUAL
     viewAttributes?
     (constraintDef)*
     END viewname2=NAME SEMI
   */

   string name1 = ctx->viewname1->getText();
   string name2 = ctx->viewname2->getText();

   debug(ctx,"visitViewDef(" + name1 + ")");
   
   if (name1 != name2) {
      Log.error(name1 + " expected",ctx->viewname2->getLine());
   }

   View *v = new View();
   init_class(v,ctx->start->getLine());

   // view attributes
   
   if (ctx->EXTENDS() != nullptr) {
      // to do !!!
      return v;
   }
   
   /* formationDef
   : (projection | join | iliunion  | aggregation | inspection) SEMI
   */
   
   /* enum {Projection, Join, Union,
         Aggregation_All, Aggregation_Equal,
         Inspection_Normal, Inspection_Area} FormationKind; */

   parser::Ili2Parser::FormationDefContext *fctx = ctx->formationDef();
   if (fctx->join() != nullptr) {
      v->FormationKind = View::Join;
   }
   else if (fctx->iliunion() != nullptr) {
      v->FormationKind = View::Union;
   }
   else if (fctx->aggregation() != nullptr) {
      v->FormationKind = View::Aggregation_All; // ???, to do !!!
   }
   else { // inspection
      v->FormationKind = View::Inspection_Normal; // ???, to do !!!
   }
   
   /* to do !!!
   list<Expression *> FormationParameter; // PathOrInspFactor only
                       // Aggr.Equal: UniqueEl
                       // Inspection: Attributepath

   v->Where = visitExpression(;
   bool Transient = false;
   // role from ASSOCIATION BaseViewDef
   // list<RenamedBaseView *> RenamedBaseView;
   // role from ASSOCIATION DerivedAssoc
   list <Class *> DeriAssoc;
   */

   return v;
   
}

static map<string,string> rename_map;

antlrcpp::Any Ili2Input::visitRenamedViewableRef(parser::Ili2Parser::RenamedViewableRefContext *ctx)
{

   /* renamedViewableRef
   : (basename=NAME TILDE)? path
   */

   debug(ctx,"renameViewableRef()");

   if (ctx->NAME() == nullptr) {
      //rename_map[visitPath(ctx->path)] = get_path(ctx->path);
      return nullptr;
   }

   //rename_map[ctx->NAME->getSymbol()->getText()] = get_path(ctx->path);
   return nullptr;
   
}

antlrcpp::Any Ili2Input::visitProjection(parser::Ili2Parser::ProjectionContext *ctx)
{

   /* projection
   : PROJECTION OF renamedViewableRef
   */

   debug(ctx,"visitProjection()");
   rename_map.clear();

   // to do !!!
   
   return nullptr;
   
}

antlrcpp::Any Ili2Input::visitJoin(parser::Ili2Parser::JoinContext *ctx)
{

   /* join
   : JOIN OF renamedViewableRef
     (COMMA renamedViewableRef (LPAREN OR ILINULL RPAREN)?)+
   */

   debug(ctx,"visitJoin()");
   return nullptr;
   
}

antlrcpp::Any Ili2Input::visitIliunion(parser::Ili2Parser::IliunionContext *ctx)
{

   /* iliunion
   : UNION OF renamedViewableRef
     (COMMA renamedViewableRef)*
   */

   debug(ctx,"visitIliunition()");
   return nullptr;
   
}

antlrcpp::Any Ili2Input::visitAggregation(parser::Ili2Parser::AggregationContext *ctx)
{

   /* aggregation
   : AGGREGATION OF renamedViewableRef
    (ALL | EQUAL LPAREN uniqueEl RPAREN)
   */

   debug(ctx,"visitAggregation()");
   return nullptr;
   
}

antlrcpp::Any Ili2Input::visitInspection(parser::Ili2Parser::InspectionContext *ctx)
{

   /* inspection
   : AREA INSPECTION OF renamedViewableRef
     RARROW structureorlineattributename=NAME
     (RARROW structureorlineattributename=NAME)*
   */

   debug(ctx,"visitInspection()");
   return nullptr;
   
}

antlrcpp::Any Ili2Input::visitBaseExtensionDef(parser::Ili2Parser::BaseExtensionDefContext *ctx)
{

   /* baseExtensionDef
   : BASE basename=NAME EXTENDED BY
     renamedViewableRef (COMMA renamedViewableRef)*
   */

   debug(ctx,"visitBaseExtensionDef()");
   return nullptr;
   
}

antlrcpp::Any Ili2Input::visitSelection(parser::Ili2Parser::SelectionContext *ctx)
{

   /* selection
   : WHERE expression SEMI
   */

   debug(ctx,"visitSelection()");
   return nullptr;
   
}

antlrcpp::Any Ili2Input::visitViewAttributes(parser::Ili2Parser::ViewAttributesContext *ctx)
{

   /* viewAttributes
   : ATTRIBUTE?
     (ALL OF basename=NAME SEMI
      | attributeDef
      | attributename=NAME properties? // ABSTRACT|EXTENDED|FINAL|TRANSIENT
        COLONEQUAL factor SEMI 
     )*
   */

   debug(ctx,"visitViewAttributes()");
   return nullptr;
   
}
