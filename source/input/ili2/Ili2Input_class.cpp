#pragma once

#include "Ili2Input.h"
#include "Ili2Input_helper.h"
#include "../../metamodel/MetaModelInput.h"
#include "../../util/StringUtil.h"
#include "../../util/Logger.h"

using namespace input;
using namespace parser;
using namespace metamodel;

antlrcpp::Any Ili2Input::visitClassDef(Ili2Parser::ClassDefContext *ctx)
{

   /* classDef
   : CLASS classname1=NAME properties? // ABSTRACT|EXTENDED|FINAL
     (EXTENDS classbase=path)? EQUAL
     ((OID AS classoid=path | NO OID) SEMI )?
     classOrStructureDef
     END classname2=NAME SEMI
   */
   
   string name1 = ctx->classname1->getText();
   if (util::starts_with(name1,"ILIC_")) {
      name1 = name1.substr(5);
   }

   string name2 = ctx->classname2->getText();
   if (util::starts_with(name1,"ILIC_")) {
      name1 = name1.substr(5);
   }

   if (name1 != name2) {
      Log.warning(
         "classname " + name2 + " must match " + name1,
         ctx->classname2->getLine()
      );
   }

   debug(ctx,"visitClassDef(" + name1 + ")");
   Log.incNestLevel();

   // init Class
   Class *c = new Class();
   init_type(c,ctx->classname1->getLine());

   // MetaElement Attributes
   c->Name = name1;
   c->ElementInPackage = get_package_context();
   get_package_context()->Element.push_back(c);

   // ExtendableME Attributes
   if (ctx->properties() != nullptr) {
      map<string,bool> properties = get_properties(ctx->properties(),vector<string>({ABSTRACT,FINAL,EXTENDED}));
      c->Abstract = properties[ABSTRACT];
      c->Final = properties[FINAL];
      if (properties[EXTENDED]) {
         Package *p = get_package_context();
         DataUnit* u = find_dataunit(get_path(p));
         int line = ctx->properties()->start->getLine();
         if (u->Super == nullptr) {
            Log.error(string("EXTENDED can only by used in extended topics"),line);
         }
         else {
            bool found = false;
            while (u->Super != nullptr) {
               DataUnit *uu = static_cast<DataUnit *>(u->Super);

               string package_path = get_path(uu);

               if (util::ends_with(package_path,".BASKET")) {
                  package_path = package_path.substr(0,package_path.length()-7);
               }

               Package* pp = find_package(package_path);
               Class *cc = find_class(pp,name1);
               if (cc != nullptr) {
                  found = true;
                  break;
               }
               u = static_cast<DataUnit *>(u->Super);
            }
            if (!found) {
               Log.error("class " + name1 + " not found in basetopic(s)",line);
            }
         }
      }
   }

   if (ctx->classbase != nullptr) {
      c->Super = find_class(ctx->classbase->getText());
      if (c->Super != nullptr) {
         c->Super->Sub.push_back(c);
      }
   }

   // Class Attributes
   c->Kind = Class::ClassVal;

   // role from ASSOCIATION LocalType
   // metamodel::AttrOrParam *LTParent;

   if (ctx->classoid != nullptr) {
      c->Oid = find_domaintype(ctx->classoid->getText());
      // DomainType *Oid; // RESTRICTION(TextType; NumType; AnyOIDType), to do !!!
   }

   // role from ASSOCIATION DerivedAssoc
   // View *View;

   add_type(c);
   add_class(c);
   push_context(c);

   /* classOrStructureDef
   : ATTRIBUTE? 
     attributeDef*
     constraintDef*
     (PARAMETER parameterDef*)?
   */

   for (auto *actx : ctx->classOrStructureDef()->attributeDef()) {
      visitAttributeDef(actx);
   }

   for (auto cctx : ctx->classOrStructureDef()->constraintDef()) {
      visitConstraintDef(cctx);
   }

   for (auto pctx : ctx->classOrStructureDef()->parameterDef()) {
      // to do !!!
      // visitParamDef(pctx);
   }

   pop_context();
   Log.decNestLevel();
   
   return c;

}

antlrcpp::Any Ili2Input::visitStructureDef(Ili2Parser::StructureDefContext *ctx)
{

   /* structureDef
   : STRUCTURE structurename1=NAME properties? // ABSTRACT|EXTENDED|FINAL
     (EXTENDS structurebase=path)? EQUAL
     classOrStructureDef
     END structurename2=NAME SEMI
   */

   string name1 = ctx->structurename1->getText();
   string name2 = ctx->structurename2->getText();
   if (name1 != name2) {
      Log.error(
         "structurename " + name2 + " must match " + name1,
         ctx->structurename2->getLine()
      );
   }

   debug(ctx,"visitStructureDef(" + name1 + ")");
   Log.incNestLevel();

   // init Class
   Class *c = new Class();
   init_type(c,ctx->structurename1->getLine());

   // MetaElement Attributes
   c->Name = name1;
   c->ElementInPackage = get_package_context();
   get_package_context()->Element.push_back(c);

   // ExtendableME Attributes
   if (ctx->properties() != nullptr) {
      map<string,bool> properties = get_properties(ctx->properties(),vector<string>({ABSTRACT,FINAL,EXTENDED}));
      c->Abstract = properties[ABSTRACT];
      c->Final = properties[FINAL];
      if (properties[EXTENDED]) {
         Package* p = get_package_context();
         DataUnit* u = find_dataunit(get_path(p));
         int line = ctx->properties()->start->getLine();
         if (u->Super == nullptr) {
            Log.error(string("EXTENDED can only by used in extended topics"), line);
         }
         else {
            bool found = false;
            while (u->Super != nullptr) {
               DataUnit* uu = static_cast<DataUnit*>(u->Super);
               Package* pp = find_package(get_path(uu));
               Class* cc = find_structure(pp, name1);
               if (cc != nullptr) {
                  found = true;
                  break;
               }
               u = static_cast<DataUnit*>(u->Super);
            }
            if (!found) {
               Log.error("structure " + name1 + " not found in basetopic(s)", line);
            }
         }
      }
   }

   if (ctx->structurebase != nullptr) {
      c->Super = find_structure(ctx->structurebase->getText());
      if (c->Super != nullptr) {
         c->Super->Sub.push_back(c);
      }
   }

   // Class Attributes
   c->Kind = Class::Structure;

   // role from ASSOCIATION LocalType
   // metamodel::AttrOrParam *LTParent;

   // role from ASSOCIATION DerivedAssoc
   // View *View;

   add_type(c);
   add_class(c);
   push_context(c);

   /* classOrStructureDef
   : ATTRIBUTE? 
     attributeDef*
     constraintDef*
     (PARAMETER parameterDef*)?
   */

   for (auto *actx : ctx->classOrStructureDef()->attributeDef()) {
      AttrOrParam *a = visitAttributeDef(actx);
   }

   for (auto cctx : ctx->classOrStructureDef()->constraintDef()) {
      visitConstraintDef(cctx);
   }

   for (auto pctx : ctx->classOrStructureDef()->parameterDef()) {
      // to do !!!
      // visitParamDef(pctx);
   }

   pop_context();
   Log.decNestLevel();
   
   return c;

}

static Type* any_to_type(antlrcpp::Any any) 
{
   
   try {
      return any.as<TextType *>();
   }
   catch (exception e) {
   }
   
   try {
      return any.as<NumType *>();
   }
   catch (exception e) {
   }
   
   try {
      return any.as<BooleanType *>();
   }
   catch (exception e) {
   }

   try {
      return any.as<EnumType *>();
   }
   catch (exception e) {
   }

   try {
      return any.as<CoordType *>();
   }
   catch (exception e) {
   }

   try {
      return any.as<BlackboxType *>();
   }
   catch (exception e) {
   }

   try {
      return any.as<AnyOIDType *>();
   }
   catch (exception e) {
   }

   try {
      return any.as<LineType *>();
   }
   catch (exception e) {
   }

   try {
      DomainType * t = any.as<DomainType *>();
      return nullptr;
   }
   catch (exception e) {
   }

   try {
      Type * t = any.as<Type *>();
      return nullptr;
   }
   catch (exception e) {
   }

   Log.error("any_to_type: unsupported type");
   return nullptr;

}

static void check_type_restriction(Type *base_type,Type *extended_type, string name, int line)
{

   if (!extended_type->isSubClassOf(base_type->getClass())) {
      Log.error("type of attribute " + name + " must have same type as baseclass attr",line);
      return;
   }

   if (base_type->getClass() == "NumType") {
      NumType* b = static_cast<NumType*>(base_type);
      double min_b = atoi(b->Min.c_str());
      double max_b = atoi(b->Max.c_str());
      NumType* e = static_cast<NumType*>(extended_type);
      double min_e = atoi(e->Min.c_str());
      double max_e = atoi(e->Max.c_str());
      if (min_e < min_b) {
         Log.error("numeric range of " + name + " must be a subrange of baseclass type");
      }
      else if (max_e > max_b) {
         Log.error("numeric range of " + name + " must be a subrange of baseclass type");
      }
      return;
   }

   // other type, to do !!!

}
   
antlrcpp::Any Ili2Input::visitAttributeDef(parser::Ili2Parser::AttributeDefContext * ctx)
{

   /* attributeDef
   : (CONTINUOUS? SUBDIVISION)? attributname=NAME
     properties? // ABSTRACT|EXTENDED|FINAL
     COLON attrTypeDef
     (COLONEQUAL factor (COMMA factor)*)? SEMI
   */

   /* class AttrOrParam : public ExtendableME {
      // MetaElement.Name := AttributeName, ParameterName
      //                    as defined in the INTERLIS-Model
   public:
      enum { NoSubDiv, SubDiv, ContSubDiv } SubdivisionKind;
      bool Transient = false;
      list<Expression *> Derivates;
      // ROLE from ASSOCIATION LocalType
      list<Type *> LocalType;
      // ROLE from ASSOCIATION AttrOrParamType
      Type *Type;
      // ROLE from ASSOCIATION ClassAttr
      Class *AttrParent;
   */

   string name = ctx->attributname->getText();
   debug(ctx,">>> visitAttributeDef(" + name + ")");
   Log.incNestLevel();

   // init AttrOrParam
   AttrOrParam *a = new AttrOrParam();
   init_extendableme(a, ctx->attributname->getLine());

   // MetaElement attributes
   a->Name = name;
   
   push_context(a);
   a->Type = visitAttrTypeDef(ctx->attrTypeDef());
   pop_context();

   // ExtendableME attributes
   if (ctx->properties() != nullptr) {
      map <string,bool> properties = get_properties(ctx->properties(),vector<string>({ABSTRACT,FINAL,EXTENDED}));
      a->Abstract = properties[ABSTRACT];
      a->Final = properties[FINAL];
      if (properties[EXTENDED]) {
         Class *c = get_class_context();
         if (c->Super == nullptr) {
            //Log.error(string("EXTENDED can only by used in extended classes / structures / associations"),ctx->attributname->getLine());
         }
         else {
            Class* s = static_cast<Class*>(c->Super);
            AttrOrParam *aa = metamodel::find_attribute(s,name);
            if (aa == nullptr) {
               Log.error("attribute " + name + " not found in baseclass", ctx->attributname->getLine());
            }
            else {
               check_type_restriction(aa->Type, a->Type, name, ctx->attributname->getLine());
            }
         }
      }
   }

   // AttrOrParam Attributes
   if (ctx->SUBDIVISION() != nullptr) {
      if (ctx->CONTINUOUS() != nullptr) {
         a->SubdivisionKind = AttrOrParam::ContSubDiv;
      }
      else {
         a->SubdivisionKind = AttrOrParam::SubDiv;
      }
   }
   else {
      a->SubdivisionKind = AttrOrParam::NoSubDiv;
   }

   a->Transient = false; // to do !!!

   // ASSOCIATION ClassAttr
   a->AttrParent = get_class_context();
   get_class_context()->ClassAttribute.push_back(a);
   
   for (auto fctx : ctx->factor()) {
      // to do !!!
   }
   
   Log.decNestLevel();
   debug(ctx,"<<< visitAttributeDef(" + name + ")");

   return a;

}

antlrcpp::Any Ili2Input::visitAttrTypeDef(parser::Ili2Parser::AttrTypeDefContext *ctx)
{
   
   /* attrTypeDef
   : MANDATORY? attrType
   | bagOrListType
   */

   debug(ctx,">>> visitAttrTypeDef()");
   Log.incNestLevel();

   Type *t;
   
   if (ctx->attrType() != nullptr) {
      t = visitAttrType(ctx->attrType());
      if (t != nullptr && ctx->MANDATORY() != nullptr) {
         try {
            DomainType *dt = static_cast<DomainType *>(t);
            dt->Mandatory = true;
            t = dt;
         }
         catch (exception e) {
            Log.internal_error("unable to cast to DomainType, line=" + to_string(ctx->start->getLine()),e,1);
         }
      }
   }
   else {
      MultiValue *m = visitBagOrListType(ctx->bagOrListType());
      t = m;
   }
   
   t->_attr = dynamic_cast<AttrOrParam *>(get_context());

   Log.decNestLevel();
   if (t != nullptr) {
      debug(ctx,"<<< visitAttrTypeDef() " + t->Name + ":" + t->getClass());
   }
   else {
      debug(ctx,"<<< visitAttrTypeDef() ???");
   }

   return t;

}

antlrcpp::Any Ili2Input::visitAttrType(parser::Ili2Parser::AttrTypeContext * ctx)
{

   /* attrType
   : type
   | path
   | referenceAttr
   | restrictedRef
   */

   debug(ctx,">>> visitAttrType()");
   Log.incNestLevel();

   Type *t;

   if (ctx->type() != nullptr) {
      t = visitType(ctx->type());
   }
   else if (ctx->path() != nullptr) {
      Type *tt = find_type(visitPath(ctx->path()));
      t = static_cast<Type *>(tt->clone());
      t->Super = tt;
   }
   else if (ctx->referenceAttr() != nullptr) {
      ReferenceType *rt = visitReferenceAttr(ctx->referenceAttr());
      t = rt;
   }
   else if (ctx->restrictedRef() != nullptr) {
      RestrictedRef *r =  visitRestrictedRef(ctx->restrictedRef());
      t = r->BaseType;
   }

   t->LTParent = dynamic_cast<AttrOrParam *>(get_context());
   t->ElementInPackage = nullptr;

   Log.decNestLevel();
   if (t != nullptr) {
      debug(ctx,"<<< visitAttrType() " + t->Name + ":" + t->getClass());
   }
   else {
      debug(ctx,"<<< visitAttrType() ???");
   }

   return t;

}

antlrcpp::Any Ili2Input::visitReferenceAttr(parser::Ili2Parser::ReferenceAttrContext * ctx)
{

   /* referenceAttr
   : REFERENCE TO (LPAREN EXTERNAL RPAREN)? restrictedRef
   */
   
   /* class ClassRelatedType : public DomainType { // ABSTRACT
   */

   /* class ReferenceType : public ClassRelatedType {
   public:
      bool External = false;
      virtual string getClass() { return "ReferenceType"; }
      virtual string getBaseClass() { return "ClassRelatedType"; };
   */

   debug(ctx,"visitReferenceAttr()");
   
   ReferenceType *t = new ReferenceType();
   init_domaintype(t,ctx->start->getLine());
   
   if (ctx->EXTERNAL() != nullptr) {
      t->External = true;
   }
   
   RestrictedRef *r = visitRestrictedRef(ctx->restrictedRef());
   if (r->BaseType->getClass() == "Class") {
      Class *c = static_cast<Class *>(r->BaseType);
      t->BaseClass = c;
      if (c->Kind == Class::Structure) {
         Log.error("target of reference type must be a class or association, found structure",ctx->start->getLine());
         t->BaseClass = nullptr;
      }
   }
   else {
      Log.error("target of reference type must be a class or association, found " + r->BaseType->getClass(),ctx->start->getLine());
   }
   
   return t;

}


