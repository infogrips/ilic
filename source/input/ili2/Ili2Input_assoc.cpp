#pragma once

#include "Ili2Input.h"
#include "Ili2Input_helper.h"
#include "../../metamodel/MetaModelInput.h"
#include "../../util/Logger.h"

using namespace input;
using namespace parser;
using namespace metamodel;

antlrcpp::Any Ili2Input::visitAssociationDef(parser::Ili2Parser::AssociationDefContext *ctx)
{

   /* associationDef
   : ASSOCIATION (associationname1=NAME)? properties? // ABSTRACT|EXTENDED|FINAL|OID +++
     (EXTENDS associationRef)?
     (DERIVED FROM renamedViewableRef)? +++
     EQUAL
     ((OID AS assocoid=path | NO OID) SEMI)?
     (roleDef)* +++
     ATTRIBUTE? (attributeDef)*
     (CARDINALITY EQUAL cardinality SEMI)? +++
     (constraintDef)*
     END (associationname2=NAME)? SEMI
   */

   /* class Class : public Type {
      // MetaElement.Name := StructureName, ClassName,
      //                     AssociationName, ViewName
      //                     as defined in the INTERLIS-Model
   public:
      enum {Structure,ClassVal,ViewVal,Association} Kind;
      Multiplicity Multiplicity; // for associations only
      list<Constraint *> Constraints;
      bool EmbeddedRoleTransfer = false;
      bool ili1OptionalTable = false;
      // role from ASSOCIATION LocalType
      metamodel::AttrOrParam *LTParent = nullptr;
      // role from ASSOCIATION ClassAttr
      list<metamodel::AttrOrParam *> ClassAttribute;
      // role from ASSOCIATION AssocRole
      list<Role *> Role;
      // role from ExplicitAssocAcc
      list<ExplicitAssocAccess *> ExplicitAssocAccess;
      // role from ASSOCIATION MetaObjectClass
      list<MetaObjectDef *> MetaObjectDef;
      // role from ASSOCIATION StructOfFormat
      list<FormattedType *> FormattedType;
      // role form ASSOCIATION ObjectOID
      DomainType *Oid = nullptr; // RESTRICTION(TextType; NumType; AnyOIDType)
      // role from ASSOCIATION ARefOf
      list<AttributeRefType *> ForARef;
      // role from ASSOCIATION LineFormStructure
      list<LineForm *> LineForm;
      // role from ASSOCIATION LineAttr
      list<LineType *> LineType;
      // role from ASSOCIATION BaseViewRef
      list<RenamedBaseView *> RenamedBaseView;
      // role from ASSOCIATION DerivedAssoc
      View *View = nullptr;
      // role from ASSOCIATION GraphicBase
      //list<Graphic *> Graphic;
      // role from ASSOCIATION SignClass
      list <DrawingRule *> DrawingRule;
      // from from ASSOCIATION ClassConstraint
      list<Constraint *> Constraint;
   */

   string name1 = "???";
   if (ctx->associationname1 != nullptr) {
      name1 = ctx->associationname1->getText();
   }
   
   string name2 = "???";
   if (ctx->associationname2 != nullptr) {
      name2 = ctx->associationname2->getText();
   }
   
   debug(ctx,">>> visitAssociationDef(" + name1 + ")");
   Log.incNestLevel();
   
   if (name1 != name2) {
      Log.error(name2 + " does not match " + name1,ctx->associationname2->getLine());
   }

   // init Class
   Class *c = new Class();
   init_type(c,get_line(ctx));

   // MetaElement Attributes
   c->Name = name1;

   // ExtendableME Attributes
   map<string,bool> properties = get_properties(ctx->properties(),vector<string>({ABSTRACT,EXTENDED,FINAL,OID}));
   c->Abstract = properties[ABSTRACT];
   c->Final = properties[FINAL];
   if (properties[EXTENDED]) {
      Package* p = get_package_context();
      int line = get_line(ctx);
      DataUnit* u = find_dataunit(get_path(p),line);
      if (u->Super == nullptr) {
         Log.error(string("EXTENDED can only by used in extended topics"), line);
      }
      else {
         bool found = false;
         while (u->Super != nullptr) {
            DataUnit* uu = static_cast<DataUnit*>(u->Super);
            Package* pp = find_package(get_path(uu),line);
            Class* cc = find_association(pp,name1,line);
            if (cc != nullptr) {
               found = true;
               break;
            }
            u = static_cast<DataUnit*>(u->Super);
         }
         if (!found) {
            Log.error("association " + name1 + " not found in basetopic(s)", line);
         }
      }
   }
   if (properties[OID]) {
      // to do !!!
   }
   
   if (ctx->associationRef() != nullptr) {
      c->Super = find_association(ctx->associationRef()->getText(),get_line(ctx->associationRef()));
      if (c->Super != nullptr) {
         c->Super->Sub.push_back(c);
      }
   }
   
   if (ctx->DERIVED() != nullptr) {
      // from view
      // to do !!!
   }

   // Class Attributes
   c->Kind = Class::Association;

   // role from ASSOCIATION LocalType
   // metamodel::AttrOrParam *LTParent;

   if (ctx->assocoid != nullptr) {
      DomainType *t = find_domaintype(ctx->assocoid->getText(),get_line(ctx->assocoid));
      c->Oid = t;
   }

   // role from ASSOCIATION DerivedAssoc
   // View *View;
   
   add_class(c);
   push_context(c);

   for (auto rctx : ctx->roleDef()) {
      Role *r = visitRoleDef(rctx);
      r->Association = c;
      c->Role.push_back(r);
   }
   
   if (ctx->CARDINALITY() != nullptr) {
      // to do !!!
   }

   for (auto *actx : ctx->attributeDef()) {
      AttrOrParam *a = visitAttributeDef(actx);
      a->AttrParent = c;
      c->ClassAttribute.push_back(a);
   }

   for (auto cctx : ctx->constraintDef()) {
      Constraint *cc = visitConstraintDef(cctx);
      c->Constraints.push_back(cc);
   }
   
   pop_context();

   Log.decNestLevel();
   debug(ctx,"<<< visitAssociationDef(" + name1 + ")");
   
   return c;

}

antlrcpp::Any Ili2Input::visitRoleDef(parser::Ili2Parser::RoleDefContext *ctx)
{
   
   /* roleDef
   : rolename=NAME 
     properties? // ABSTRACT|EXTENDED|FINAL|HIDING|ORDERED|EXTERNAL
     (ASSOCIATE | AGGREGATE | COMPOSITE ) cardinality?
     restrictedRef (OR restrictedRef)*
     (COLONEQUAL role=factor)? SEMI
   */
   
   /*
   class Role : public ReferenceType {
      // MetaElement.Name := RoleName as defined in the INTERLIS-Model
   public:
      enum {Assoc, Aggr, Comp} Strongness;
      bool Ordered = false;
      Multiplicity Multiplicity;
      list<Expression *> Derivates;
      bool EmbeddedTransfer = false;
      // role from ASSOCIATION AssocRole
      Class *Association;
      // role from ASSOCIATION AssocAccOrign
      list<ExplicitAssocAccess *> UseAsOrigin;
      // role from ASSOCIATION AssocAccTarget
      list<ExplicitAssocAccess *> UseAsTarget;

   class ExplicitAssocAccess : public ExtendableME {
   public:
      // role from ASSOCIATION ExplicitAssocAcc
      Class* AssocAccOf;
      // role from ASSOCIATION AssocAccOrign
      Role* OriginRole;
      // role from ASSOCIATION AssocAccTarget
      Role* TargetRole;
   */
   
   /* struct RestrictedRef : public MMObject {
   // for ilic internal purposes only
   public:
      Type *BaseType = nullptr;
      list<Type *> TypeRestriction;
   */

   /* class BaseClass : public MMObject { // ASSOCIATION
   public:
      ClassRelatedType *CRT = nullptr;
      Class *BaseClass = nullptr;
   */

   debug(ctx,"visitRoleDef()");

   Role *r = new Role;
   init_domaintype(r,ctx->start->getLine());

   r->Name = ctx->rolename->getText();
   r->ElementInPackage = nullptr;

   map<string,bool> properties = get_properties(ctx->properties(),vector<string>({ABSTRACT,EXTENDED,FINAL,HIDING,ORDERED,EXTERNAL}));
   r->Abstract = properties[ABSTRACT];
   r->Final = properties[FINAL];
   r->Ordered = properties[ORDERED];
   // HIDING ???
   // EXTERNAL ???
   r->Association = get_class_context();

   if (ctx->ASSOCIATE() != nullptr) {
      r->Strongness = Role::Assoc;
   }
   else if (ctx->AGGREGATE() != nullptr) {
      r->Strongness = Role::Aggr;
   }
   else {
      r->Strongness = Role::Comp;
   }
   
   if (ctx->cardinality() != nullptr) {
      r->Multiplicity = visitCardinality(ctx->cardinality());
   }

/* to do !!!
   for (auto rr : ctx->restrictedRef()) {
      Log.message(">>> gugus");
      RestrictedRef *rrr = visitRestrictedRef(rr);
      Log.message("<<< gugus1");
      if (rrr == nullptr) {
         continue;
      }
      Log.message("<<< gugus2");
      for (auto t : rrr->TypeRestriction) {
         if (!t->isSubClassOf("Class")) {
            Log.error(t->getClass() + " must be extension of class",t->_line);
            continue;
         }
         ExplicitAssocAccess *a = new ExplicitAssocAccess();
         a->AssocAccOf = static_cast<Class *>(t);
         // Role* OriginRole; to do !!!
         // Role* TargetRole; to do !!!
         r->UseAsTarget.push_back(a);
      }
      BaseClass *b = new BaseClass();
      init_mmobject(b,r->_line);
      b->CRT = r;
      if (rrr->BaseType->isSubClassOf("Class")) {
         b->BaseClass = dynamic_cast<Class *>(rrr->BaseType);
      };
      add_baseclass(b);
   }
*/
   
   return r;
   
}

antlrcpp::Any Ili2Input::visitCardinality(parser::Ili2Parser::CardinalityContext *ctx)
{

   /* 
   struct Multiplicity : public MMObject {
   public:
      int Min;
      int Max;
   };
   */

   /* cardinality
   : LCURLY (STAR | min=POSNUMBER (DOTDOT (max=POSNUMBER | STAR))?) RCURLY
   */

   debug(ctx,"visitCardinality()");
   
   Multiplicity m;
   m.Min = -1;
   m.Max = -1;
   
   if (ctx->min != nullptr) {
      m.Min = stoi(ctx->min->getText());
   }
   
   if (ctx->max != nullptr) {
      m.Max = stoi(ctx->max->getText());
   }
   else {
      m.Max = m.Min;
   }
   
   if (ctx->STAR() != nullptr) {
      m.Max = -1;
   }

   return m;
   
}
