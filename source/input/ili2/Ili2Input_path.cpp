#include "Ili2Input.h"
#include "Ili2Input_helper.h"
#include "../../metamodel/MetaModelInput.h"
#include "../../util/Logger.h"

using namespace input;
using namespace parser;
using namespace metamodel;

antlrcpp::Any Ili2Input::visitPath(parser::Ili2Parser::PathContext * ctx)
{

   /* path
   : INTERLIS DOT (SIGN | URI | REFSYSTEM | BOOLEAN | HALIGNMENT | VALIGNMENT)
   | (INTERLIS DOT)? NAME (DOT NAME)*
   */
            
   string path = "";
   
   if (ctx->SIGN() != nullptr) {
      path = "INTERLIS.SIGN";
   }
   else if (ctx->URI() != nullptr) {
      path = "INTERLIS.URI";
   }
   else if (ctx->REFSYSTEM() != nullptr) {
      path = "INTERLIS.REFSYSTEM";
   }
   else if (ctx->BOOLEAN() != nullptr) {
      path = "INTERLIS.BOOLEAN";
   }
   else if (ctx->HALIGNMENT() != nullptr) {
      path = "INTERLIS.HALIGNMENT";
   }
   else if (ctx->VALIGNMENT() != nullptr) {
      path = "INTERLIS.VALIGNMENT";
   }
   else {

      if (ctx->INTERLIS() != nullptr) {
         path = "INTERLIS";
      }
   
      for (auto n : ctx->NAME()) {
         string name = n->getSymbol()->getText();
         if (path == "") {
            path = name;
         }
         else {
            path = path + "." + name;
         }
      }
      
   }

   debug(ctx,"visitPath(" + path + ")");

   return path;

}

antlrcpp::Any Ili2Input::visitRestrictedRef(parser::Ili2Parser::RestrictedRefContext * ctx)
{

   /* restrictedRef
   : (typeref=path | ANYCLASS | ANYSTRUCTURE)
     restriction?
   */

   /* class RestricedRef : public MMObject {
   // for ilic internal purposes only
   public:
      Type *BaseType = nullptr;
      list<Type *> TypeRestriction;
   */

   debug(ctx,">>> visitRestrictedRef()");
   Log.incNestLevel();
   
   RestrictedRef *r = new RestrictedRef();
   init_mmobject(r,ctx->start->getLine());
   
   if (ctx->typeref != nullptr) {
      string path = visitPath(ctx->typeref);
      r->_baseclass = find_class_type(path,get_line(ctx->typeref));
   }
   else if (ctx->ANYCLASS() != nullptr) {
      // returns Class / Type
      r->_baseclass = find_class("ANYCLASS",get_line(ctx->ANYCLASS()->getSymbol()));
   }
   else {
      // returns Class / Type
      r->_baseclass = find_class("ANYSTRUCTURE", get_line(ctx->ANYSTRUCTURE()->getSymbol()));
   }
   
   if (ctx->restriction() != nullptr) {
      list<Class *> t = visitRestriction(ctx->restriction());
      r->_classrestriction = t;
   }
   
   for (auto c : r->_classrestriction) {
      if (!c->isSubClassOf(r->_baseclass->getClass())) {
         Log.error(c->getClass() + " is no extension of " + r->_baseclass->getClass(),c->_line);
      }
   }
      
   Log.decNestLevel();
   if (r == nullptr) {
      debug(ctx,"<<< visitRestrictedRef() returns nullptr");
   }
   else if (r->_baseclass == nullptr) {
      debug(ctx,"<<< visitRestrictedRef() BaseClass is nullptr");
   }
   else {
      debug(ctx,"<<< visitRestrictedRef() returns " + r->_baseclass->getClass());
   }
   return r;

}

antlrcpp::Any Ili2Input::visitRestriction(parser::Ili2Parser::RestrictionContext * ctx)
{

   /* restriction
   :  RESTRICTION LPAREN path (COMMA path)* RPAREN)?
   */

   debug(ctx,">>> visitRestriction()");
   Log.incNestLevel();
   
   list<Class *> r;
   for (auto p : ctx->path()) {
      Class *c = find_class_or_structure(visitPath(p),get_line(ctx));
      if (c != nullptr) {
         r.push_back(c);
      }
   }

   Log.decNestLevel();
   debug(ctx,"<<< visitRestriction(" + to_string(r.size()) + ")");

   return r;

}

antlrcpp::Any Ili2Input::visitBaseAttrRef(parser::Ili2Parser::BaseAttrRefContext *ctx)
{
   
   /* baseAttrRef
   : NAME (SLASH POSNUMBER)?
   | NAME SLASH baseattr=path
   */

   debug(ctx,"visitBaseAttrRef()");
   return nullptr;

}

antlrcpp::Any Ili2Input::visitMetaObjectRef(parser::Ili2Parser::MetaObjectRefContext *ctx)
{

   /* metaObjectRef
   : (metaDataBasketRef DOT)? metaobjectname=NAME
   */

   debug(ctx,"visitMetaObjectRef()");
   return nullptr;

}

static Class* pathel_context;

antlrcpp::Any Ili2Input::visitObjectOrAttributePath(parser::Ili2Parser::ObjectOrAttributePathContext *ctx)
{

   /* objectOrAttributePath
   : pathEl (RARROW pathEl)*
   */
  
   /* struct PathEl : public MMObject {
   public:
      enum {
         This, ThisArea, ThatArea, Parent,
         ReferenceAttr, AssocPath, Role, ViewBase,
         Attribute, MetaObject
      } Kind;
      MetaElement* Ref = nullptr;
      int NumIndex;
      enum { First, Last } SpecIndex;

   struct PathOrInspFactor : public Factor {
   public:
      list <PathEl *> PathEls;
      View *Inspection = nullptr;
      string _path = "";
   */

   debug(ctx, ">>> visitObjectOrAttributePath()");
   Log.incNestLevel();
   
   PathOrInspFactor *f = new PathOrInspFactor();
   init_factor(f,ctx->start->getLine());

   if (get_context()->getClass() == "Graphic") {
      Graphic *g = static_cast<Graphic *>(get_context());
      pathel_context = g->Base;
   }
   else {
      pathel_context = get_class_context();
   }

   for (auto p : ctx->pathEl()) {
      f->PathEls.push_back(visitPathEl(p));
      if (f->_path != "") {
         f->_path += "->";
      }
      f->_path += p->getText();
   }

   f->_type = "???";
   if (f->PathEls.back()->Ref != nullptr) {
      if (f->PathEls.back()->Ref->getClass() == "AttrOrParam") {
         AttrOrParam *a = static_cast<AttrOrParam*>(f->PathEls.back()->Ref);
         if (a->Type != nullptr) {
            f->_type = a->Type->getClass();
         }
      }
   }

   Log.decNestLevel();
   debug(ctx, "<<< visitObjectOrAttributePath(" + f->_path + ")");
   return f;

}

antlrcpp::Any Ili2Input::visitAttributePath(parser::Ili2Parser::AttributePathContext *ctx)
{
   debug(ctx, ">>> visitAttributePath()");
   Factor *f = visitObjectOrAttributePath(ctx->objectOrAttributePath());
   debug(ctx, "<<< visitAttributePath()");
   return f;
}

antlrcpp::Any Ili2Input::visitPathEl(parser::Ili2Parser::PathElContext *ctx)
{
   
   /* pathEl
   : THIS
   | THISAREA 
   | THATAREA
   | PARENT
   | objectRef 
   */

   /* objectRef 
   : (BACKSLASH)? (name=NAME (LBRACE (FIRST | LAST | axislistindex=POSNUMBER | associationname=NAME) RBRACE)? | AGGREGATES)
   */

   /* struct PathEl : public MMObject {
   public:
      enum {
         This, ThisArea, ThatArea, Parent,
         ReferenceAttr, AssocPath, Role, ViewBase,
         Attribute, MetaObject
      } Kind;
      MetaElement* Ref = nullptr;
      int NumIndex;
      enum { First, Last } SpecIndex;
   */

   debug(ctx, ">>> visitPathEl()");
   Log.incNestLevel();

   PathEl *e = new PathEl();
   init_mmobject(e,ctx->start->getLine());
   string kind = "";
   e->Ref = nullptr; // ???
   e->NumIndex = -1; // ???
   e->SpecIndex = PathEl::First; // ???
   
   if (ctx->THIS() != nullptr) {
      e->Kind = PathEl::This;
      kind = "This";
   }
   else if (ctx->THISAREA() != nullptr) {
      e->Kind = PathEl::ThisArea;
      kind = "ThisArea";
   }
   else if (ctx->PARENT() != nullptr) {
      e->Kind = PathEl::Parent;
      kind = "Parent";
   }
   else if (ctx->objectRef() != nullptr) {

      e->Kind = PathEl::Attribute;
      kind = "Attribute";
      string name = ctx->objectRef()->name->getText();

      // role
      Role *r = find_role(pathel_context,name);
      if (r != nullptr) {
         pathel_context = r->_baseclass;
         e->Ref = r;
         goto end;
      }

      // attribute
      AttrOrParam *a = find_attribute(pathel_context,name);
      e->Ref = a;
      if (a == nullptr) {
         Log.error("attribute " + name + " not found",get_line(ctx->objectRef()));
         pathel_context = nullptr;
      }
      else if (a != nullptr && a->Type != nullptr) {
         if (a->Type->isSubClassOf("ClassRelatedType")) {
            ClassRelatedType *t = static_cast<ClassRelatedType *>(a->Type);
            pathel_context = t->_baseclass;
         }
         else if (a->Type->isSubClassOf("TypeRelatedType")) {
            TypeRelatedType *t = static_cast<TypeRelatedType *>(a->Type);
            if (t->BaseType != nullptr && t->BaseType->getClass() == "Class") {
               pathel_context = static_cast<Class *>(t->BaseType);
            }
         }
      }

   }

   end:
   Log.decNestLevel();
   debug(ctx, "<<< visitPathEl() " + kind);

   return e;

}
