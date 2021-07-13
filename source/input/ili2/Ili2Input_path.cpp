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
   : INTERLIS
   | (INTERLIS DOT)? SIGN
   | (INTERLIS DOT)? NAME
   | NAME (DOT NAME)*
   */
         
   string path = "";
   
   if (ctx->SIGN() != nullptr) {
      path = "INTERLIS.SIGN";
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
            path += "." + name;
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
      // returns DomainType
      r->BaseType = find_type(visitPath(ctx->typeref),get_line(ctx->typeref));
   }
   else if (ctx->ANYCLASS() != nullptr) {
      // returns Class / Type
      r->BaseType = find_class("INTERLIS.ANYCLASS",get_line(ctx->ANYCLASS()->getSymbol()));
   }
   else {
      // returns Class / Type
      r->BaseType = find_class("INTERLIS.ANYSTRUCTURE", get_line(ctx->ANYSTRUCTURE()->getSymbol()));
   }
   
   if (ctx->restriction() != nullptr) {
      list<Type *> t = visitRestriction(ctx->restriction());
      r->TypeRestriction = t;
   }
   
   for (auto t : r->TypeRestriction) {
      if (!t->isSubClassOf(r->BaseType->getClass())) {
         Log.error(t->getClass() + " is no extension of " + r->BaseType->getClass(),t->_line);
      }
   }
      
   Log.decNestLevel();
   if (r == nullptr || r->BaseType == nullptr) {
      debug(ctx,"<<< visitRestrictedRef() returns nullptr");
   }
   else {
      debug(ctx,"<<< visitRestrictedRef() returns " + r->BaseType->getClass());
   }
   return r;

}

antlrcpp::Any Ili2Input::visitRestriction(parser::Ili2Parser::RestrictionContext * ctx)
{

   /* restriction
   :  RESTRICTION LPAREN path (COMMA path)* RPAREN)?
   */

   debug(ctx,"visitRestriction()");

   list<Type *> r;
   for (auto p : ctx->path()) {
      Type *t = find_type(visitPath(p),get_line(ctx));
      r.push_back(t);
   }

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

antlrcpp::Any Ili2Input::visitAttributeRef(parser::Ili2Parser::AttributeRefContext *ctx)
{

   /* attributeRef 
   : (attributename=NAME ((LBRACE (FIRST | LAST | axislistindex=POSNUMBER) RBRACE)?) | AGGREGATES)
   */

   debug(ctx,"visitAttributeRef()");
   return nullptr;

}

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
   f->_type = "???"; // to do !!!

   list<PathEl *> pathels;
   for (auto p : ctx->pathEl()) {
      f->PathEls.push_back(visitPathEl(p));
      if (f->_path != "") {
         f->_path += "->";
      }
      f->_path += p->getText();
   }

   Log.decNestLevel();
   debug(ctx, "<<< visitObjectOrAttributePath(" + f->_path + ")");
   return f;

}

antlrcpp::Any Ili2Input::visitAttributePath(parser::Ili2Parser::AttributePathContext *ctx)
{

   /* attributePath
   : objectOrAttributePath
   */

   debug(ctx,"visitAttributePath()");
   return nullptr;

}

antlrcpp::Any Ili2Input::visitPathEl(parser::Ili2Parser::PathElContext *ctx)
{
   
   /* pathEl
   : THIS
   | THISAREA 
   | THATAREA
   | PARENT
   | referenceattributename=NAME
   | associationPath
   | rolename=NAME (LBRACE associationname=NAME RBRACE)?
   | basename=NAME
   | attributeRef 
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
   PathEl *e = new PathEl();
   init_mmobject(e,ctx->start->getLine());
   string kind = "";

   if (ctx->THIS() != nullptr) {
      e->Kind = PathEl::This;
      e->_kind = "This";
   }
   else if (ctx->THISAREA() != nullptr) {
      e->Kind = PathEl::ThisArea;
      e->_kind = "ThisArea";
   }
   else if (ctx->PARENT() != nullptr) {
      e->Kind = PathEl::Parent;
      e->_kind = "Parent";
   }
   else if (ctx->referenceattributename != nullptr) {
      e->Kind = PathEl::ReferenceAttr;
      e->_kind = "ReferenceAttr";
   }
   else if (ctx->associationPath() != nullptr) {
      e->Kind = PathEl::AssocPath;
      e->_kind = "AssocPath";
   }
   else if (ctx->rolename != nullptr) {
      e->Kind = PathEl::Role;
      e->_kind = "Role";
   }
   else if (ctx->basename != nullptr) {
      e->Kind = PathEl::ViewBase;
      e->_kind = "ViewBase";
   }
   else if (ctx->attributeRef() != nullptr) {
      e->Kind = PathEl::Attribute;
      e->_kind = "Attribute";
   }
   e->Ref = nullptr; // ???
   e->NumIndex = -1; // ???
   e->SpecIndex = PathEl::First; // ???

   debug(ctx, "<<< visitPathEl() " + e->_kind);

   return e;

}

antlrcpp::Any Ili2Input::visitAssociationPath(parser::Ili2Parser::AssociationPathContext *ctx)
{

   /* associationPath
   : (BACKSLASH)? associationaccessmame=NAME
   */

   debug(ctx,"visitAssociationPath()");
   return nullptr;

}
