#pragma once

#include "Ili2Input.h"
#include "Ili2Input_helper.h"
#include "../../metamodel/MetaModelInput.h"
#include "../../util/Logger.h"

using namespace input;
using namespace parser;
using namespace metamodel;

static Class* viewbase = nullptr;

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

   /* formationDef
   : (projection | join | iliunion  | aggregation | inspection) SEMI
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

   debug(ctx,">>> visitViewDef(" + name1 + ")");
   Log.incNestLevel();
   
   if (name1 != name2) {
      Log.error(name1 + " expected",get_line(ctx->viewname2));
   }

   View* v = new View;
   v->Name = name1;
   v->Kind = Class::ViewVal;
   init_class(v,get_line(ctx));
   add_class(v); 

   map<string,bool> properties = get_properties(ctx->properties(),vector({ABSTRACT,FINAL,TRANSIENT,EXTENDED}));
   if (properties[ABSTRACT]) {
      v->Abstract = true;
   }
   if (properties[FINAL]) {
      v->Final = true;
   }
   if (properties[TRANSIENT]) {
      v->Transient = true;
   }
   
   if (properties[EXTENDED]) {
      // to do !!!
   }

   if (ctx->EXTENDS() != nullptr) {
      View* vv = find_view(visitPath(ctx->viewref),get_line(ctx->viewref));
      v->Super = vv;
   }

   /* formationDef
   : (projection | join | iliunion  | aggregation | inspection) SEMI
   */
   
   /* enum {Projection, Join, Union,
         Aggregation_All, Aggregation_Equal,
         Inspection_Normal, Inspection_Area} FormationKind; */

   auto *fctx = ctx->formationDef();
   
   push_context(v);

   if (fctx != nullptr) {

      /* renamedViewableRef
      : (basename=NAME TILDE)? path
      */
      
      if (fctx->projection() != nullptr) {
         /* PROJECTION OF renamedViewableRef
         */
         v->FormationKind = View::Projection;
         visitRenamedViewableRef(fctx->projection()->renamedViewableRef());
      }
      else if (fctx->join() != nullptr) {
         /* JOIN OF renamedViewableRef
            (COMMA renamedViewableRef (LPAREN OR ILINULL RPAREN)?)+
         */
         v->FormationKind = View::Join;
         for (auto vr: fctx->join()->renamedViewableRef()) {
            visitRenamedViewableRef(vr);
         }
         // ILINULL ???
      }
      else if (fctx->iliunion() != nullptr) {
         /* UNION OF renamedViewableRef
            (COMMA renamedViewableRef)*
         */
         v->FormationKind = View::Union;
         for (auto vr: fctx->join()->renamedViewableRef()) {
            visitRenamedViewableRef(vr);
         }
      }
      else if (fctx->aggregation() != nullptr) {
         /* AGGREGATION OF renamedViewableRef
            (ALL | EQUAL LPAREN uniqueEl RPAREN)
         */
         v->FormationKind = View::Aggregation_All; // ???, to do !!!
         visitRenamedViewableRef(fctx->aggregation()->renamedViewableRef());
      }
      else if (fctx->inspection() != nullptr) {
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
         visitRenamedViewableRef(fctx->inspection()->renamedViewableRef());
         if (viewbase != nullptr) {
            string attrname = fctx->inspection()->NAME(0)->getText();
            int line = get_line(fctx->inspection()->NAME(0));
            AttrOrParam *attr = find_attribute(viewbase,attrname);
            if (attr == nullptr) {
               Log.error("inspection attribute " + attrname + " not found",line);
            }
            else if (attr->Type != nullptr) {
               Class *basestructure = nullptr;
               if (attr->Type->getClass() == "LineType") {
                  basestructure = find_structure("INTERLIS.SurfaceBoundary",line);
               }
               else if (attr->Type->getClass() == "MultiValue") {
                  MultiValue *mv = static_cast<MultiValue*>(attr->Type);
                  basestructure = static_cast<Class *>(mv->BaseType);
               }
               else {
                  Log.error("attribute " + attrname + " can not be instpected",line);
               }
               if (basestructure != nullptr) {
                  for (auto aa : basestructure->ClassAttribute) {
                     AttrOrParam *aac = static_cast<AttrOrParam *>(aa->clone());
                     aac->_visible = true; // to do !!!
                     PathEl *pe = new PathEl;
                     pe->Kind = PathEl::Attribute;
                     pe->Ref = aa;
                     PathOrInspFactor *pi = new PathOrInspFactor;
                     pi->PathEls.push_back(pe);
                     aac->Derivates.push_back(pi);
                     viewbase->ClassAttribute.push_back(aac);
                  }
               }
            }
         }
      }
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
   
   pop_context();

   // role from ASSOCIATION BaseViewDef
   // list<RenamedBaseView *> RenamedBaseView;
   // to do !!!

   // role from ASSOCIATION DerivedAssoc
   // list <Class *> DeriAssoc;
   // to do !!!

   Log.decNestLevel();
   debug(ctx,"<<< visitViewDef(" + name1 + ")");
   
   return v;
   
}

antlrcpp::Any Ili2Input::visitRenamedViewableRef(parser::Ili2Parser::RenamedViewableRefContext *ctx)
{

   /* renamedViewableRef
   : (basename=NAME TILDE)? path
   */

   Log.debug(">>> visitRenamedViewableRef()");
   Log.incNestLevel();

   viewbase = find_class_or_view(ctx->path()->getText(),get_line(ctx));
   string name = "";
   if (ctx->basename != nullptr) {
      name = ctx->basename->getText();
   }
   else if (viewbase != nullptr) {
      name = viewbase->Name;
   }

   ObjectType *o = new ObjectType;
   o->ElementInPackage = nullptr;
   o->Name = "TYPE";
   o->_baseclass = viewbase;

   AttrOrParam *a = new AttrOrParam;
   a->_visible = false;
   a->AttrParent = get_class_context();
   a->Name = name;
   a->Type = o;
   o->LTParent = a;
   get_class_context()->ClassAttribute.push_back(a);

   Log.decNestLevel();
   Log.debug("<<< visitRenamedViewableRef(" + name + ")");
   
   return a;

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
      AttrOrParam *baseattr = nullptr;
      string name = ctx->basename->getText();
      ObjectType* basetype = nullptr;;
      for (auto a : get_class_context()->ClassAttribute) {
         if (a->Type == nullptr) {
            continue;
         }
         if (a->Type->getClass() != "ObjectType") {
            continue;
         }
         if (a->Name == name) {
            baseattr = a;
            basetype = static_cast<ObjectType *>(a->Type);
            break;
         }
      }
      if (baseattr == nullptr) {
         Log.error("alias " + name + " not found",get_line(ctx->ALL()));
      }
      else {
         baseattr->_visible = true;
         if (basetype != nullptr) {
            for (auto aa : basetype->_baseclass->ClassAttribute) {
               AttrOrParam *aac = static_cast<AttrOrParam *>(aa->clone());
               aac->_visible = true; // to do !!!
               PathEl *pe = new PathEl;
               pe->Kind = PathEl::Attribute;
               pe->Ref = aa;
               PathOrInspFactor *pi = new PathOrInspFactor;
               pi->PathEls.push_back(pe);
               aac->Derivates.push_back(pi);
               get_class_context()->ClassAttribute.push_back(aac);
            }
         }
      }
   }
   else if (ctx->attributeDef() != nullptr) {
      visitAttributeDef(ctx->attributeDef());
   }
   else {

      string name = ctx->attributename->getText();
      map<string,bool> properties = get_properties(ctx->properties(),vector({ABSTRACT,FINAL,TRANSIENT,EXTENDED}));
      Factor *f = visitFactor(ctx->factor());
      
      AttrOrParam *a = new AttrOrParam;
      //init_attr(a,get_line(ctx->attributename));
      
      Type *t = new TextType; // to do !!!
      if (properties[ABSTRACT]) {
         t->Abstract = true;
      }
      if (properties[FINAL]) {
         t->Final = true;
      }
      if (properties[TRANSIENT]) {
         //t->Transient = true;
      }
      
      a->Type = t;

      a->AttrParent = get_class_context();
      get_class_context()->ClassAttribute.push_back(a);

   }
   
   Log.decNestLevel();
   debug(ctx,"<<< visitViewAttribute()");

   return nullptr;

}