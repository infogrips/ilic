// this .cpp was generated from MetaModel.h by genvisitor.cfg

#include <typeinfo>

#include "MetaModelVisitor.h"
#include "../util/Logger.h"

namespace metamodel {

// forward declarations
static void visitModel(MetaModelVisitor *visitor, Model *m);
static void visitSubModel(MetaModelVisitor *visitor, SubModel *m);
static void visitConstraint(MetaModelVisitor *visitor, Constraint *c);
static void visitContext(MetaModelVisitor *visitor, Context *c);
static void visitMetaObjectDef(MetaModelVisitor *visitor, MetaObjectDef *d);
static void visitFunctionDef(MetaModelVisitor *visitor, FunctionDef *f);
static void visitArgument(MetaModelVisitor *visitor, Argument *a);
static void visitLineForm(MetaModelVisitor *visitor, LineForm *f);
static void visitAttrOrParam(MetaModelVisitor *visitor, AttrOrParam *a);
static void visitExplicitAssocAccess(MetaModelVisitor *visitor, ExplicitAssocAccess *a);
static void visitDataUnit(MetaModelVisitor *visitor, DataUnit *u);
static void visitMetaBasketDef(MetaModelVisitor *visitor, MetaBasketDef *d);
static void visitEnumNode(MetaModelVisitor *visitor, EnumNode *n);
static void visitRenamedBaseView(MetaModelVisitor *visitor, RenamedBaseView *v);
static void visitGraphic(MetaModelVisitor *visitor, Graphic *g);
static void visitDrawingRule(MetaModelVisitor *visitor, DrawingRule *r);
static void visitClass(MetaModelVisitor *visitor, Class *c);
static void visitBooleanType(MetaModelVisitor *visitor, BooleanType *b);
static void visitTextType(MetaModelVisitor *visitor, TextType *t);
static void visitBlackboxType(MetaModelVisitor *visitor, BlackboxType *t);
static void visitNumType(MetaModelVisitor *visitor, NumType *t);
static void visitCoordType(MetaModelVisitor *visitor, CoordType *t);
static void visitAnyOIDType(MetaModelVisitor *visitor, AnyOIDType *t);
static void visitAttributeRefType(MetaModelVisitor *visitor, AttributeRefType *t);
static void visitEnumType(MetaModelVisitor *visitor, EnumType *t);
static void visitEnumTreeValueType(MetaModelVisitor *visitor, EnumTreeValueType *t);
static void visitLineType(MetaModelVisitor *visitor, LineType *t);
static void visitMultiValue(MetaModelVisitor *visitor, MultiValue *v);
static void visitReferenceType(MetaModelVisitor *visitor, ReferenceType *t);
static void visitClassRefType(MetaModelVisitor *visitor, ClassRefType *t);
static void visitObjectType(MetaModelVisitor *visitor, ObjectType *t);
static void visitRole(MetaModelVisitor *visitor, Role *r);
static void visitUnit(MetaModelVisitor *visitor, Unit *r);
static void visitExplicitAssocAccess(MetaModelVisitor *visitor, ExplicitAssocAccess *t);
static void visitRenamedBaseView(MetaModelVisitor *visitor, RenamedBaseView *t);
static void visitDrawingRule(MetaModelVisitor *visitor, DrawingRule *t);
static void visitLineForm(MetaModelVisitor *visitor, LineForm *t);
static void visitFormattedType(MetaModelVisitor *visitor, FormattedType *t);
static void visitAttributeRefType(MetaModelVisitor *visitor, AttributeRefType *t);
static void visitRole(MetaModelVisitor *visitor, Role *t);
static void visitMetaObjectDef(MetaModelVisitor *visitor, MetaObjectDef *t);
static void visitLineType(MetaModelVisitor *visitor, LineType *t);
static void visitFunctionDef(MetaModelVisitor *visitor, FunctionDef *t);
static void visitArgument(MetaModelVisitor *visitor, Argument *t);

// helpers

static void display_debug(MetaModelVisitor *visitor, MMObject *o)
{
   string shortname;
   if (visitor == nullptr) {
      shortname = MMV;
   }
   else {
      shortname = visitor->getShortName();
   }
   Log.debug(shortname + ":visit" + o->getClass() + "(" + get_path(o) + ")");
}

static string metamodel_ignore_visit_exception = "ignoreVisit";
void MetaModelVisitor::ignoreVisit()
{
   throw metamodel_ignore_visit_exception;
}

// implementation

static void visitClassRelatedType(MetaModelVisitor* visitor, ClassRelatedType* t)
{
   if (visitor->visitClassRelatedTypeOverride()) {
      Log.debug("visitClassRelatedType()");
      visitor->visitClassRelatedType(t);
   }
}

static void visitBaseClass(MetaModelVisitor* visitor, BaseClass* c)
{
   if (visitor->visitBaseClassOverride()) {
      Log.debug("visitBaseClass()");
      visitor->visitBaseClass(c);
   }
}

static void visitClassRestriction(MetaModelVisitor* visitor, ClassRestriction* r)
{
   if (visitor->visitClassRestrictionOverride()) {
      Log.debug("visitBaseClass()");
      visitor->visitClassRestriction(r);
   }
}

static void visitTransferElement(MetaModelVisitor* visitor, TransferElement* e)
{
   if (visitor->visitTransferElementOverride()) {
      Log.debug("visitTransferElement()");
      visitor->visitTransferElement(e);
   }
}

static void visitIli1TransferElement(MetaModelVisitor* visitor, Ili1TransferElement* e)
{
   if (visitor->visitIli1TransferElementOverride()) {
      Log.debug("visitIli1TransferElement()");
      visitor->visitIli1TransferElement(e);
   }
}

static void visitAllowedInBasket(MetaModelVisitor* visitor, AllowedInBasket* b)
{
   if (visitor->visitAllowedInBasketOverride()) {
      Log.debug("visitAllowedInBasket()");
      visitor->visitAllowedInBasket(b);
   }
}

static void visitSimpleConstraint(MetaModelVisitor* visitor, SimpleConstraint* c)
{
   if (visitor->visitSimpleConstraintOverride()) {
      Log.debug("visitSimpleConstraint()");
      visitor->visitSimpleConstraint(c);
   }
}

static void visitAxisSpec(MetaModelVisitor* visitor, AxisSpec* s)
{
   if (visitor->visitAxisSpecOverride()) {
      Log.debug("visitAxisSpec()");
      visitor->visitAxisSpec(s);
   }
}

static void visitNumsRefSys(MetaModelVisitor* visitor, NumsRefSys* s)
{
   if (visitor->visitNumsRefSysOverride()) {
      Log.debug("visitNumRefSys()");
      visitor->visitNumsRefSys(s);
   }
}

static void visitARefRestriction(MetaModelVisitor* visitor, ARefRestriction* r)
{
   if (visitor->visitARefRestrictionOverride()) {
      Log.debug("visitARefRestriction()");
      visitor->visit(r);
   }
}

static void visitLinesForm(MetaModelVisitor* visitor, LinesForm* f)
{
   if (visitor->visitLinesFormOverride()) {
      Log.debug("visitLinesForm()");
      visitor->visitLinesForm(f);
   }
}

static void visitFactor(MetaModelVisitor* visitor, Factor* f)
{
   if (visitor->visitFactorOverride()) {
      Log.debug("visitFactor()");
      visitor->visitFactor(f);
   }
}

static void visitExistenceDef(MetaModelVisitor* visitor, ExistenceDef* d)
{
   if (visitor->visitExistenceDefOverride()) {
      Log.debug("visitExistenceDef()");
      visitor->visitExistenceDef(d);
   }
}

static void visitExistenceConstraint(MetaModelVisitor* visitor, ExistenceConstraint* c)
{
   if (visitor->visitExistenceConstraintOverride()) {
      Log.debug("visitExistenceConstraint()");
      visitor->visitExistenceConstraint(c);
   }
}

static void visitUniqueConstraint(MetaModelVisitor* visitor, UniqueConstraint* c)
{
   if (visitor->visitUniqueConstraintOverride()) {
      Log.debug("visitUniqueConstraint()");
      visitor->visitUniqueConstraint(c);
   }
}

static void visitSetConstraint(MetaModelVisitor* visitor, SetConstraint* s)
{
   if (visitor->visitSetConstraintOverride()) {
      Log.debug("visitSetConstraint()");
      visitor->visitSetConstraint(s);
   }
}

static void visitDocText(MetaModelVisitor *visitor, DocText *t)
{

   /*
   struct DocText : public MMObject {
   public:
      string Name;
      string Text;
   */

   if (visitor->visitDocTextOverride()) {
      display_debug(visitor,t);
   }

   visitor->visitMMObject(t);
   visitor->visitDocText(t);

}

static void visitMetaAttribute(MetaModelVisitor *visitor, MetaAttribute *t)
{

   /*
   class MetaAttribute : public MMObject {
      // OID: <Parent-OID>.METAOBJECT.Name
   public:
      string Name;
      string Value;
      // ROLE from ASSOCIATION MetaAttributes
      MetaElement *MetaElement;
   */

   if (visitor->visitMetaAttributeOverride()) {
      display_debug(visitor,t);
   }

   visitor->visitMMObject(t);
   visitor->visitMetaAttribute(t);

}

static void visitMetaElement(MetaModelVisitor *visitor, MetaElement *t)
{

   /*
   class MetaElement : public MMObject { // ABSTRACT
      // OID: <Parent-OID>.Name
   public:
      string Name;
      list <DocText> Documentation;
      // ROLE from ASSOCIATION MetaAttributes
      list <MetaAttribute *> MetaAttribute;
      // ROLE from ASSOCIATION PackageElements
      Package *ElementInPackage;
   */

   if (visitor->visitMetaElementOverride()) {
      display_debug(visitor, t);
   }

   visitor->visitMMObject(t);
   visitor->visitMetaElement(t);

   for (auto v : t->Documentation) {
      visitDocText(visitor, v);
   }

   for (auto v : t->MetaAttribute) {
      visitMetaAttribute(visitor, v);
   }

};

static void visitExtendableME(MetaModelVisitor *visitor, ExtendableME *t)
{

   /*
   class ExtendableME : public MetaElement {
   public:
      bool Abstract = false;
      bool Generic = false; // 2.4
      bool Final = false;
      // ROLE from ASSOCIATION Inheritance
      ExtendableME *Super;
      // ROLE from ASSOCIATION Inheritance
      list <ExtendableME *> Sub;
   */

   if (visitor->visitExtendableMEOverride()) {
      display_debug(visitor,t);
   }

   visitor->visitMetaElement(t);
   visitor->visitExtendableME(t);

   for (auto v : t->Sub) {
      visitExtendableME(visitor,v);
   }

}

static void visitPackage(MetaModelVisitor *visitor, Package *t)
{

   /*
   class Package : public MetaElement {
   public:
      // ROLE from ASSOCIATION PackageElements
      list <MetaElement *> Element;
   */

   if (visitor->visitPackageOverride()) {
      display_debug(visitor,t);
   }
   
   visitor->visitMetaElement(t);
   visitor->visitPackage(t);

   for (auto *me : t->Element) {
      if (me->getClass() == "Package") {
         visitPackage(visitor,static_cast<Package *>(me));
      }
      else if (me->getClass() == "Model") {
         visitModel(visitor, static_cast<Model *>(me));
      }
      else if (me->getClass() == "SubModel") {
         visitSubModel(visitor, static_cast<SubModel *>(me));
      }
      else if (me->getClass() == "Constraint") {
         visitConstraint(visitor,static_cast<Constraint *>(me));
      }
      else if (me->getClass() == "Context") {
         visitContext(visitor,static_cast<Context *>(me));
      }
      else if (me->getClass() == "MetaObjectDef") {
         visitMetaObjectDef(visitor,static_cast<MetaObjectDef *>(me));
      }
      else if (me->getClass() == "FunctionDef") {
         visitFunctionDef(visitor,static_cast<FunctionDef *>(me));
      }
      else if (me->getClass() == "Argument") {
         visitArgument(visitor,static_cast<Argument *>(me));
      }
      else if (me->getClass() == "LineForm") {
         visitLineForm(visitor,static_cast<LineForm *>(me));
      }
      else if (me->getClass() == "AttrOrParam") {
         visitAttrOrParam(visitor,static_cast<AttrOrParam *>(me));
      }
      else if (me->getClass() == "ExplicitAssocAccess") {
         visitExplicitAssocAccess(visitor,static_cast<ExplicitAssocAccess *>(me));
      }
      else if (me->getClass() == "DataUnit") {
         visitDataUnit(visitor,static_cast<DataUnit *>(me));
      }
      else if (me->getClass() == "Unit") {
         visitUnit(visitor,static_cast<Unit *>(me));
      }
      else if (me->getClass() == "MetaBasketDef") {
         visitMetaBasketDef(visitor,static_cast<MetaBasketDef *>(me));
      }
      else if (me->getClass() == "EnumNode") {
         visitEnumNode(visitor,static_cast<EnumNode *>(me));
      }
      else if (me->getClass() == "RenamedBaseView") {
         visitRenamedBaseView(visitor,static_cast<RenamedBaseView *>(me));
      }
      else if (me->getClass() == "Graphic") {
         visitGraphic(visitor,static_cast<Graphic *>(me));
      }
      else if (me->getClass() == "DrawingRule") {
         visitDrawingRule(visitor,static_cast<DrawingRule *>(me));
      }
      else if (me->getClass() == "Class") {
         visitClass(visitor,static_cast<Class *>(me));
      }
      else if (me->getClass() == "BooleanType") {
         visitBooleanType(visitor,static_cast<BooleanType *>(me));
      }
      else if (me->getClass() == "TextType") {
         visitTextType(visitor,static_cast<TextType *>(me));
      }
      else if (me->getClass() == "BlackboxType") {
         visitBlackboxType(visitor,static_cast<BlackboxType *>(me));
      }
      else if (me->getClass() == "NumType") {
         visitNumType(visitor,static_cast<NumType *>(me));
      }
      else if (me->getClass() == "CoordType") {
         visitCoordType(visitor,static_cast<CoordType *>(me));
      }
      else if (me->getClass() == "AnyOIDType") {
         visitAnyOIDType(visitor,static_cast<AnyOIDType *>(me));
      }
      else if (me->getClass() == "AttributeRefType") {
         visitAttributeRefType(visitor,static_cast<AttributeRefType *>(me));
      }
      else if (me->getClass() == "EnumType") {
         visitEnumType(visitor,static_cast<EnumType *>(me));
      }
      else if (me->getClass() == "EnumTreeValueType") {
         visitEnumTreeValueType(visitor,static_cast<EnumTreeValueType *>(me));
      }
      else if (me->getClass() == "LineType") {
         visitLineType(visitor,static_cast<LineType *>(me));
      }
      else if (me->getClass() == "MultiValue") {
         visitMultiValue(visitor,static_cast<MultiValue *>(me));
      }
      else if (me->getClass() == "ReferenceType") {
         visitReferenceType(visitor,static_cast<ReferenceType *>(me));
      }
      else if (me->getClass() == "ClassRefType") {
         visitClassRefType(visitor,static_cast<ClassRefType *>(me));
      }
      else if (me->getClass() == "ObjectType") {
         visitObjectType(visitor,static_cast<ObjectType *>(me));
      }
      else if (me->getClass() == "Role") {
         visitRole(visitor,static_cast<Role *>(me));
      }
      else {
         Log.debug(visitor->getShortName() + ":visitPackage.Element(" + get_path(me) + ") unsupported type " + me->getClass());
      }
   }

}

static void visitIli1Format(MetaModelVisitor *visitor, Ili1Format *t)
{

   /*
   struct Ili1Format : public MMObject {
   public:
      bool isFree = false;
      int LineSize = 80;
      int tidSize = 10;
      char blankCode = ' ';
      char undefinedCode = '@';
      char continueCode = '\\';
      string Font = "";
      enum { TID_I16, TID_I32, TID_ANY, TID_EXPLANATION } tidKind = TID_ANY;
      string tidExplanation = ""; // defined when tidKind == TID_EXPLANATION
   */

   if (visitor->visitIli1FormatOverride()) {
      display_debug(visitor,t);
   }

   display_debug(visitor,t);
   visitor->visitMMObject(t);
   visitor->visitIli1Format(t);

}

static void preVisitSubModel(MetaModelVisitor *visitor,SubModel *m)
{
   if (visitor->preVisitSubModelOverride()) {
      Log.debug(visitor->getShortName() + ":preVisitSubModel(" + get_path(m) + ")");
   }
   visitor->preVisitSubModel(m);
}

static void postVisitSubModel(MetaModelVisitor *visitor,SubModel *m)
{
   if (visitor->postVisitSubModelOverride()) {
      Log.debug(visitor->getShortName() + ":postVisitSubModel(" + get_path(m) + ")");
   }
   visitor->postVisitSubModel(m);
}

static void visitSubModel(MetaModelVisitor *visitor, SubModel *t)
{

   /*
   class SubModel : public Package {
      // MetaElement.Name := TopicName as defined in the INTERLIS-Model
   public:
   */

   if (visitor->visitSubModelOverride()) {
      display_debug(visitor,t);
   }

   preVisitSubModel(visitor,t);
   visitPackage(visitor,t);

   visitor->visitPackage(t);
   visitor->visitSubModel(t);

   postVisitSubModel(visitor,t);

}

static void visitMultiplicity(MetaModelVisitor *visitor, Multiplicity *t)
{

   /*
   struct Multiplicity : public MMObject {
   public:
      int Min;
      int Max;
   */

   if (visitor->visitMultiplicityOverride()) {
      display_debug(visitor,t);
   }

   visitor->visitMMObject(t);
   visitor->visitMultiplicity(t);

}

static void visitConstraint(MetaModelVisitor *visitor, Constraint *t)
{

   /*
   class Constraint : public MetaElement { // ABSTRACT, 2.4
   public:
      // role from ASSOCIATION DomainConstraint
      DomainType *toDomain; // 2.4
      // role from ASSOCIATION ClassConstraint
      Class *ToClass; // 2.4
   */

   if (visitor->visitConstraintOverride()) {
      display_debug(visitor, t);
   }

   visitor->visitMetaElement(t);
   visitor->visitConstraint(t);

}

static void visitDataUnit(MetaModelVisitor *visitor, DataUnit *t);

static void visitDomainType(MetaModelVisitor *visitor, DomainType *t)
{

   /*
   class DomainType : public Type { // ABSTRACT
      // MetaElement.Name :=
      // DomainName if defined explicitly as a domain,
      // "Type" if defined within an attribute definition
   public:
      bool Mandatory = false;
      // role from ASSOCIATION BasketOID
      list <DataUnit *> ForDataUnit;
      // role form ASSOCIATION DomainConstraint
      list <Constraint *> Constraint;
      // role form ASSOCIATION ConcreteForGeneric
      GenericDef *GenericDef;
   */

   if (visitor->visitDomainTypeOverride()) {
      display_debug(visitor, t);
   }

   visitor->visitType(t);
   visitor->visitDomainType(t);

   for (auto v : t->ForDataUnit) {
      visitDataUnit(visitor, v);
   }

   for (auto v : t->Constraint) {
      visitConstraint(visitor, v);
   }

}

static void visitTypeRelatedType(MetaModelVisitor *visitor, TypeRelatedType *t)
{

   /*
   class TypeRelatedType : public DomainType { // ABSTRACT
   public:
      // Role from ASSOCIATION BaseType
      Type *BaseType;
   */

   if (visitor->visitTypeRelatedTypeOverride()) {
      display_debug(visitor, t);
   }

   visitor->visitDomainType(t);
   visitor->visitTypeRelatedType(t);

}

static void visitType(MetaModelVisitor *visitor, Type *t)
{

   /*
   class Type : public ExtendableME { // ABSTRACT
   public:
      // role from ASSOCIATION AttrOrParamType
      list<AttrOrParam *> AttrOrParam;
      // role form ASSOCIATION BaseType
      list<TypeRelatedType *> TRT;
      // role from ASSOCIATION LocalFType
      FunctionDef *LFTParent;
      // role from ASSOCIATION ResultType
      list <FunctionDef *> Function;
      // role form ASSOCIATION ArgumentType
      list<Argument *> Argument;
   */

   if (visitor->visitTypeOverride()) {
      display_debug(visitor, t);
   }

   visitor->visitExtendableME(t);
   visitor->visitType(t);

   for (auto v : t->AttrOrParam) {
      visitAttrOrParam(visitor, v);
   }

   for (auto v : t->TRT) {
      visitTypeRelatedType(visitor, v);
   }

   for (auto v : t->Function) {
      visitFunctionDef(visitor, v);
   }

   for (auto v : t->Argument) {
      visitArgument(visitor, v);
   }

}

static void preVisitClass(MetaModelVisitor *visitor,Class *c)
{
   if (visitor->preVisitClassOverride()) {
      Log.debug(visitor->getShortName() + ":preVisitClass(" + get_path(c) + ")");
      visitor->preVisitClass(c);
   }
}

static void postVisitClass(MetaModelVisitor *visitor,Class *c)
{
   if (visitor->postVisitClassOverride()) {
      Log.debug(visitor->getShortName() + ":postVisitClass(" + get_path(c) + ")");
      visitor->postVisitClass(c);
   }
}

static void visitClass(MetaModelVisitor *visitor, Class *t)
{

   /*
   class Class : public Type {
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
      metamodel::AttrOrParam *LTParent;
      // role from ASSOCIATION ClassAttr
      list<AttrOrParam *> ClassAttribute;
      // role from ASSOCIATION AssocRole
      list<Role *> Role;
      // role from ExplicitAssocAcc
      list<ExplicitAssocAccess *> ExplicitAssocAccess;
      // role from ASSOCIATION MetaObjectClass
      list<MetaObjectDef *> MetaObjectDef;
      // role from ASSOCIATION StructOfFormat
      list<FormattedType *> FormattedType;
      // role form ASSOCIATION ObjectOID
      DomainType * Oid; // RESTRICTION(TextType; NumType; AnyOIDType)
      // role from ASSOCIATION ARefOf
      list<AttributeRefType *> ForARef;
      // role from ASSOCIATION LineFormStructure
      list<LineForm *> LineForm;
      // role from ASSOCIATION LineAttr
      list<LineType *> LineType;
      // role from ASSOCIATION BaseViewRef
      list<RenamedBaseView *> RenamedBaseView;
      // role from ASSOCIATION DerivedAssoc
      View *View;
      // role from ASSOCIATION GraphicBase
      //list<Graphic *> Graphic;
      // role from ASSOCIATION SignClass
      list <DrawingRule *> DrawingRule;
      // from from ASSOCIATION ClassConstraint
      list<Constraint *> Constraint;
   */

   if (visitor->visitClassOverride()) {
      display_debug(visitor, t);
   }
   
   preVisitClass(visitor,t);

   visitor->visitType(t);
   visitor->visitClass(t);

   for (auto v : t->Constraints) {
      visitConstraint(visitor,v);
   }

   for (auto v : t->ClassAttribute) {
      visitAttrOrParam(visitor,v);
   }

   for (auto v : t->Role) {
      visitRole(visitor,v);
   }

   for (auto v : t->ExplicitAssocAccess) {
      visitExplicitAssocAccess(visitor,v);
   }

   for (auto v : t->MetaObjectDef) {
      visitMetaObjectDef(visitor,v);
   }

   for (auto v : t->FormattedType) {
      visitFormattedType(visitor,v);
   }

   for (auto v : t->ForARef) {
      visitAttributeRefType(visitor,v);
   }

   for (auto v : t->LineForm) {
      visitLineForm(visitor,v);
   }

   for (auto v : t->LineType) {
      visitLineType(visitor,v);
   }

   for (auto v : t->RenamedBaseView) {
      visitRenamedBaseView(visitor,v);
   }

   for (auto v : t->DrawingRule) {
      visitDrawingRule(visitor,v);
   }

   for (auto v : t->Constraint) {
      visitConstraint(visitor,v);
   }

   postVisitClass(visitor,t);

}

static void visitExpression(MetaModelVisitor *visitor, Expression *t)
{

   /*
   class Expression : public MMObject { // ABSTRACT
   public:
   */

   if (visitor->visitExpressionOverride()) {
      display_debug(visitor, t);
   }

   visitor->visitMMObject(t);
   visitor->visitExpression(t);

}

static void visitAttrOrParam(MetaModelVisitor *visitor, AttrOrParam *t)
{

   /*
   class AttrOrParam : public ExtendableME {
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

   if (visitor->visitAttrOrParamOverride()) {
      display_debug(visitor,t);
   }

   visitor->visitExtendableME(t);
   visitor->visitAttrOrParam(t);

   for (auto v : t->Derivates) {
      visitExpression(visitor,v);
   }

   for (auto v : t->LocalType) {
      visitType(visitor,v);
   }

}

static void visitTypeRestriction(MetaModelVisitor *visitor, TypeRestriction *t)
{

   /*
   class TypeRestriction : public MMObject {
   public:
      TypeRelatedType *TRTR;
      Type *TypeRestriction;
   */

   if (visitor->visitTypeRestrictionOverride()) {
      display_debug(visitor,t);
   }

   visitor->visitMMObject(t);
   visitor->visitTypeRestriction(t);

}

static void visitMultiValue(MetaModelVisitor *visitor, MultiValue *t)
{

   /*
   class MultiValue : public TypeRelatedType {
      // MetaElement.Name := "Type" because always defined
      //                     within an attribute definition
   public:
      bool Ordered = false;
      Multiplicity Multiplicity;
   */

   if (visitor->visitMultiValueOverride()) {
      display_debug(visitor,t);
   }

   visitor->visitTypeRelatedType(t);
   visitor->visitMultiValue(t);

}

static void visitReferenceType(MetaModelVisitor *visitor, ReferenceType *t)
{

   /*
   class ReferenceType : public ClassRelatedType {
   public:
      bool External = false;
   */

   if (visitor->visitReferenceTypeOverride()) {
      display_debug(visitor,t);
   }

   visitor->visitClassRelatedType(t);
   visitor->visitReferenceType(t);

}

static void visitRole(MetaModelVisitor *visitor, Role *t)
{

   /*
   class Role : public ReferenceType {
      // MetaElement.Name := RoleName as defined in the INTERLIS-Model
   public:
      enum { Assoc, Aggr, Comp } Strongness;
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
   */

   if (visitor->visitRoleOverride()) {
      display_debug(visitor,t);
   }

   visitor->visitReferenceType(t);
   visitor->visitRole(t);

   for (auto v : t->Derivates) {
      visitExpression(visitor,v);
   }

   for (auto v : t->UseAsOrigin) {
      visitExplicitAssocAccess(visitor,v);
   }

   for (auto v : t->UseAsTarget) {
      visitExplicitAssocAccess(visitor,v);
   }

}

static void visitExplicitAssocAccess(MetaModelVisitor *visitor, ExplicitAssocAccess *t)
{

   /*
   class ExplicitAssocAccess : public ExtendableME {
   public:
      // role from ASSOCIATION ExplicitAssocAcc
      Class *AssocAccOf;
      // role from ASSOCIATION AssocAccOrign
      Role *OriginRole;
      // role from ASSOCIATION AssocAccTarget
      Role *TargetRole;
   */

   if (visitor->visitExplicitAssocAccessOverride()) {
      display_debug(visitor,t);
   }

   visitor->visitExtendableME(t);
   visitor->visitExplicitAssocAccess(t);

}

static void visitAssocAcc(MetaModelVisitor *visitor, AssocAcc *t)
{

   /*
   class AssocAcc : public MMObject { // ASSOCIATION
   public:
      Class *Class;
      Role *AssocAcc; // Role OR ExplicitAssocAccess, to do !!!
   */

   if (visitor->visitAssocAccOverride()) {
      display_debug(visitor, t);
   }

   visitor->visitMMObject(t);
   visitor->visitAssocAcc(t);

}

static void visitMetaBasketDef(MetaModelVisitor *visitor, MetaBasketDef *t);

static void visitDataUnit(MetaModelVisitor *visitor, DataUnit *t)
{

   /*
   class DataUnit : public ExtendableME {
   public:
      // Name (EXTENDED): TEXT := "BASKET";
      bool ViewUnit = false;
      string DataUnitName;
      // role from ASSOCIATION MetaDataUnit 
      list <MetaBasketDef *> MetaBasketDef;
      // role from ASSOCIATION BasketOID
      DomainType *Oid; // RESTRICTION(TextType; NumType; AnyOIDType);
   */

   if (visitor->visitDataUnitOverride()) {
      display_debug(visitor,t);
   }

   visitor->visitExtendableME(t);
   visitor->visitDataUnit(t);

   for (auto v : t->MetaBasketDef) {
      visitMetaBasketDef(visitor,v);
   }

}

static void visitContext(MetaModelVisitor *visitor, Context *t)
{

   /*
   class Context : public MetaElement {
   public:
   */

   if (visitor->visitContextOverride()) {
      display_debug(visitor,t);
   }

   visitor->visitMetaElement(t);
   visitor->visitContext(t);

}

static void visitGenericDef(MetaModelVisitor *visitor, GenericDef *t)
{

   /*
   class GenericDef : public MMObject { 
   public:
      DomainType *OID; 
      Context *Context;
      list<DomainType *> GenericDomain;
      // role from ASSOCIATION ConcreteForGeneric
      list<DomainType *> ConcreteDomain;
   */

   if (visitor->visitGenericDefOverride()) {
      display_debug(visitor,t);
   }

   visitor->visitMMObject(t);
   visitor->visitGenericDef(t);

   for (auto v : t->GenericDomain) {
      visitDomainType(visitor,v);
   }

   for (auto v : t->ConcreteDomain) {
      visitDomainType(visitor,v);
   }

}

static void visitNumType(MetaModelVisitor *visitor, NumType *t);

static void visitUnit(MetaModelVisitor *visitor, Unit *t)
{

   /*
   class Unit : public ExtendableME {
      // MetaElement.Name := ShortName as defined in the INTERLIS-Model
   public:
      enum { BaseU, DerivedU, ComposedU } Kind;
      Expression *Definition;
      // role from ASSOCIATION NumUnit
      list <NumType *> Num;
      string _unitshort;
   */

   if (visitor->visitUnitOverride()) {
      display_debug(visitor,t);
   }

   visitor->visitExtendableME(t);
   visitor->visitUnit(t);

   for (auto v : t->Num) {
      visitNumType(visitor,v);
   }

}

static void visitMetaBasketDef(MetaModelVisitor *visitor, MetaBasketDef *t)
{

   /*
   class MetaBasketDef : public ExtendableME {
      // MetaElement.Name := BasketName as defined in the INTERLIS-Model
   public:
      enum { SignB, RefSystemB } Kind;
      // role from ASSOCIATION MetaDataUnit
      DataUnit *MetaDataTopic;
      // role from ASSOCIATION MetaBasketMembers
      MetaObjectDef * Member;
   */

   if (visitor->visitMetaBasketDefOverride()) {
      display_debug(visitor,t);
   }

   visitor->visitExtendableME(t);
   visitor->visitMetaBasketDef(t);

}

static void visitMetaObjectDef(MetaModelVisitor *visitor, MetaObjectDef *t)
{

   /*
   class MetaObjectDef : public MetaElement {
      // MetaElement.Name := MetaObjectName as defined
      // in the INTERLIS-Model
   public:
      bool IsRefSystem = false;
      // role from ASSOCIATION MetaBasketMembers
      list <MetaBasketDef *> MetaBasketDef;
      // role from ASSOCIATION MetaObjectClass
      Class *Class;
   */

   if (visitor->visitMetaObjectDefOverride()) {
      display_debug(visitor,t);
   }

   visitor->visitMetaElement(t);
   visitor->visitMetaObjectDef(t);

   for (auto v : t->MetaBasketDef) {
      visitMetaBasketDef(visitor,v);
   }

}

static void visitBooleanType(MetaModelVisitor *visitor, BooleanType *t)
{

   /*
   class BooleanType : public DomainType {
   public:
   */

   if (visitor->visitBooleanTypeOverride()) {
      display_debug(visitor,t);
   }

   visitor->visitDomainType(t);
   visitor->visitBooleanType(t);

}

static void visitTextType(MetaModelVisitor *visitor, TextType *t)
{

   /*
   class TextType : public DomainType {
   public:
      enum { MText, Text, Name, Uri } Kind;
      int MaxLength = 0;
   */

   if (visitor->visitTextTypeOverride()) {
      display_debug(visitor,t);
   }

   visitor->visitDomainType(t);
   visitor->visitTextType(t);

}

static void visitBlackboxType(MetaModelVisitor *visitor, BlackboxType *t)
{

   /*
   class BlackboxType : public DomainType {
   public:
      enum { Binary, Xml } Kind;
   */

   if (visitor->visitBlackboxTypeOverride()) {
      display_debug(visitor,t);
   }

   visitor->visitDomainType(t);
   visitor->visitBlackboxType(t);

}

static void visitNumType(MetaModelVisitor *visitor, NumType *t)
{

   /*
   class NumType : public DomainType {
      // MetaElement.Name :=
      // DomainName if defined explicitly as a domain,
      // "Type" if defined within an attribute definition,
      // "C1", "C2", "C3" if defined within a coordinate type
   public:
      string Min;
      string Max;
      bool Circular = false;
      bool Clockwise = false;
      // frole from ASSOCIATION NumUnit
      Unit *Unit;
   */

   if (visitor->visitNumTypeOverride()) {
      display_debug(visitor,t);
   }

   visitor->visitDomainType(t);
   visitor->visitNumType(t);

}

static void visitCoordType(MetaModelVisitor *visitor, CoordType *t)
{

   /*
   class CoordType : public DomainType {
   public:
      int NullAxis;
      int PiHalfAxis;
      bool Multi = false; // 2.4
      // role from ASSOCIATION LineCoord
      list <LineType *> LineType;
   */

   if (visitor->visitCoordTypeOverride()) {
      display_debug(visitor,t);
   }

   visitor->visitDomainType(t);
   visitor->visitCoordType(t);

   for (auto v : t->LineType) {
      visitLineType(visitor,v);
   }

}

static void visitFormattedType(MetaModelVisitor *visitor, FormattedType *t)
{

   /*
   class FormattedType : public NumType {
   public:
      string Format;
      // role from ASSOCIATION
      Class *Struct;
   */

   if (visitor->visitFormattedTypeOverride()) {
      display_debug(visitor,t);
   }

   visitor->visitNumType(t);
   visitor->visitFormattedType(t);

}

static void visitAnyOIDType(MetaModelVisitor *visitor, AnyOIDType *t)
{

   /*
   class AnyOIDType : public DomainType {
   public:
      // role from ASSOCIATION ObjectOID
      list<Class *> Class;
   */

   if (visitor->visitAnyOIDTypeOverride()) {
      display_debug(visitor,t);
   }

   visitor->visitDomainType(t);
   visitor->visitAnyOIDType(t);

   for (auto v : t->Class) {
      visitClass(visitor,v);
   }

}

static void visitFunctionDef(MetaModelVisitor *visitor, FunctionDef *t)
{

   /*
   class FunctionDef : public MetaElement {
      // MetaElement.Name := FunctionName as defined in the INTERLIS-Model
   public:
      string Explanation;
      // role from ASSOCIATION LocalFType
      Type *LocalType;
      Type *ResultType;
      // role from ASSOCIATION FormalArgument
      list <Argument *> Argument;
   */

   if (visitor->visitFunctionDefOverride()) {
      display_debug(visitor,t);
   }

   visitor->visitMetaElement(t);
   visitor->visitFunctionDef(t);

   for (auto v : t->Argument) {
      visitArgument(visitor,v);
   }

}

static void visitArgument(MetaModelVisitor *visitor, Argument *t)
{

   /*
   class Argument : public MetaElement {
      // MetaElement.Name := ArgumentName as defined in the INTERLIS-Model
   public:
      enum { TypeVal, EnumVal, EnumTreeVal } Kind;
      // role from ASSOCIATION FormalArgument =
      FunctionDef * Function;
      // role from ASSOCIATION ArgumentType
      Type *Type;
   */

   if (visitor->visitArgumentOverride()) {
      display_debug(visitor,t);
   }

   visitor->visitMetaElement(t);
   visitor->visitArgument(t);

}

static void visitClassRefType(MetaModelVisitor *visitor, ClassRefType *t)
{

   /*
   class ClassRefType : public ClassRelatedType {
   public:
   */

   if (visitor->visitClassRefTypeOverride()) {
      display_debug(visitor,t);
   }

   visitor->visitClassRelatedType(t);
   visitor->visitClassRefType(t);

}

static void visitObjectType(MetaModelVisitor *visitor, ObjectType *t)
{

   /*
   class ObjectType : public ClassRelatedType {
   public:
      bool Multiple = false;
   */

   if (visitor->visitObjectTypeOverride()) {
      display_debug(visitor,t);
   }

   visitor->visitClassRelatedType(t);
   visitor->visitObjectType(t);

}

static void visitAttributeRefType(MetaModelVisitor *visitor, AttributeRefType *t)
{

   /*
   class AttributeRefType : public DomainType {
   public:
      // role from ASSOCIATION ARefOf
      Class *Of; // Class OR AttrOrParam OR Argument, to do !!!
   */

   if (visitor->visitAttributeRefTypeOverride()) {
      display_debug(visitor,t);
   }

   visitor->visitDomainType(t);
   visitor->visitAttributeRefType(t);

}

static void visitEnumType(MetaModelVisitor *visitor, EnumType *t)
{

   /*
   class EnumType : public DomainType {
   public:
      enum {Unordered, Ordered, Circular} Order;
      // role from ASSOCIATION TopNode
      list <EnumNode *> TopNode;
      // role from ASSOCIATION TreeValueTypeOf
      list <EnumTreeValueType *> ETVT;
   */

   if (visitor->visitEnumTypeOverride()) {
      display_debug(visitor,t);
   }

   visitor->visitDomainType(t);
   visitor->visitEnumType(t);

   for (auto v : t->TopNode) {
      visitEnumNode(visitor,v);
   }

   for (auto v : t->ETVT) {
      visitEnumTreeValueType(visitor,v);
   }

}

static void visitEnumNode(MetaModelVisitor *visitor, EnumNode *t)
{

   /*
   class EnumNode : public ExtendableME {
      // MetaElement.Name := "TOP" for topnode,
      //                     enumeration value (without constant prefix #)
      //                     for all real nodes
   public:
      // role from ASSOCIATION TopNode
      EnumType *EnumType;
      // roles from ASSOCIATION SubNode
      EnumNode *ParentNode;
      list <EnumNode *> Node;
   */

   if (visitor->visitEnumNodeOverride()) {
      display_debug(visitor,t);
   }

   visitor->visitExtendableME(t);
   visitor->visitEnumNode(t);

   for (auto v : t->Node) {
      visitEnumNode(visitor,v);
   }

}

static void visitEnumTreeValueType(MetaModelVisitor *visitor, EnumTreeValueType *t)
{

   /*
   class EnumTreeValueType : public DomainType {
   public:
      // role from ASSOCIATION TreeValueTypeOf
      EnumType *ET;
   */

   if (visitor->visitEnumTreeValueTypeOverride()) {
      display_debug(visitor,t);
   }

   visitor->visitDomainType(t);
   visitor->visitEnumTreeValueType(t);

}

static void visitLineForm(MetaModelVisitor *visitor, LineForm *t)
{

   /*
   class LineForm : public MetaElement {
      // MetaElement.Name := LineFormName as defined in the INTERLIS-Model
   public:
      // role from ASSOCIATION LineFormStructure
      Class *Structure;
   */

   if (visitor->visitLineFormOverride()) {
      display_debug(visitor,t);
   }

   visitor->visitMetaElement(t);
   visitor->visitLineForm(t);

}

static void visitLineType(MetaModelVisitor *visitor, LineType *t)
{

   /*
   class LineType : public DomainType {
   public:
      enum {Polyline, DirectedPolyline, Surface, Area} Kind;
      string MaxOverlap;
      bool Multi = false; // 2.4
      // role from ASSOCIATION LineCoord
      CoordType *CoordType;
      // role from ASSOCIATION LineAttr
      Class *LAStructure;
   */

   if (visitor->visitLineTypeOverride()) {
      display_debug(visitor,t);
   }

   visitor->visitDomainType(t);
   visitor->visitLineType(t);

}

static void visitView(MetaModelVisitor *visitor, View *t)
{

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
   */

   if (visitor->visitViewOverride()) {
      display_debug(visitor,t);
   }

   visitor->visitClass(t);
   visitor->visitView(t);

   for (auto v : t->FormationParameter) {
      visitExpression(visitor,v);
   }

   for (auto v : t->DeriAssoc) {
      visitClass(visitor,v);
   }

}

static void visitRenamedBaseView(MetaModelVisitor *visitor, RenamedBaseView *t)
{

   /*
   class RenamedBaseView : public ExtendableME {
      // MetaElement.Name := Name as defined in the INTERLIS-Model
   public:
      bool OrNull = false;
      // role from ASSOCIATION BaseViewDef
      View *View;
      // role from ASSOCIATION BaseViewRef
      Class *BaseView;
   */

   if (visitor->visitRenamedBaseViewOverride()) {
      display_debug(visitor,t);
   }

   visitor->visitExtendableME(t);
   visitor->visitRenamedBaseView(t);

}

static void visitUnaryExpr(MetaModelVisitor *visitor, UnaryExpr *t)
{

   /*
   struct UnaryExpr : public Expression {
   public:
      enum {Not, Defined} Operation;
      Expression *SubExpression;
   */

   if (visitor->visitUnaryExprOverride()) {
      display_debug(visitor,t);
   }

   visitor->visitExpression(t);
   visitor->visitUnaryExpr(t);

}

static void visitCompoundExpr(MetaModelVisitor *visitor, CompoundExpr *t)
{

   /*
   struct CompoundExpr : public Expression {
   public:
      enum {Implication, And, Or, Mult, Div, // 2.4 Implication
            Relation_Equal, Relation_NotEqual,
            Relation_LessOrEqual, Relation_GreaterOrEqual,
            Relation_Less, Relation_Greater} Operation;
      list <Expression *> SubExpressions;
   */

   if (visitor->visitCompoundExprOverride()) {
      display_debug(visitor,t);
   }

   visitor->visitExpression(t);
   visitor->visitCompoundExpr(t);

   for (auto v : t->SubExpressions) {
      visitExpression(visitor,v);
   }

}

static void visitPathEl(MetaModelVisitor *visitor, PathEl *t)
{

   /*
   struct PathEl : public MMObject {
   public:
      enum {This, ThisArea, ThatArea, Parent,
            ReferenceAttr, AssocPath, Role, ViewBase,
            Attribute, MetaObject} Kind;
      MetaElement *Ref;
      int NumIndex;
      enum {First, Last} SpecIndex;
   */

   if (visitor->visitPathElOverride()) {
      display_debug(visitor,t);
   }

   visitor->visitMMObject(t);
   visitor->visitPathEl(t);

}

static void visitPathOrInspFactor(MetaModelVisitor *visitor, PathOrInspFactor *t)
{

   /*
   struct PathOrInspFactor : public Factor {
   public:
      list <PathEl *> PathEls;
      View *Inspection;
   */

   if (visitor->visitPathOrInspFactorOverride()) {
      display_debug(visitor,t);
   }

   visitor->visitFactor(t);
   visitor->visitPathOrInspFactor(t);

   for (auto v : t->PathEls) {
      visitPathEl(visitor,v);
   }

}

static void visitEnumAssignment(MetaModelVisitor *visitor, EnumAssignment *t)
{

   /*
   struct EnumAssignment : public MMObject {
   public:
      Expression *ValueToAssign;
      EnumNode *MinEnumValue;
      EnumNode *MaxEnumValue;
   */

   if (visitor->visitEnumAssignmentOverride()) {
      display_debug(visitor,t);
   }

   visitor->visitMMObject(t);
   visitor->visitEnumAssignment(t);

}

static void visitEnumMapping(MetaModelVisitor *visitor, EnumMapping *t)
{

   /*
   struct EnumMapping : public Factor {
   public:
      PathOrInspFactor *EnumValue;
      list <EnumAssignment *> Cases;
   */

   if (visitor->visitEnumMappingOverride()) {
      display_debug(visitor,t);
   }

   visitor->visitFactor(t);
   visitor->visitEnumMapping(t);

   for (auto v : t->Cases) {
      visitEnumAssignment(visitor,v);
   }

}

static void visitClassRef(MetaModelVisitor *visitor, ClassRef *t)
{

   /*
   struct ClassRef : public MMObject {
   public:
      Class *Ref;
   */

   if (visitor->visitClassRefOverride()) {
      display_debug(visitor,t);
   }

   visitor->visitMMObject(t);
   visitor->visitClassRef(t);

}

static void visitActualArgument(MetaModelVisitor *visitor, ActualArgument *t)
{

   /*
   struct ActualArgument : public MMObject {
   public:
      Argument *FormalArgument;
      enum {ExpressionVal, AllOf} Kind;
      list <Expression *> Expression;
      list <ClassRef *> ObjectClasses;
   */

   if (visitor->visitActualArgumentOverride()) {
      display_debug(visitor,t);
   }

   visitor->visitMMObject(t);
   visitor->visitActualArgument(t);

   for (auto v : t->Expression) {
      visitExpression(visitor,v);
   }

   for (auto v : t->ObjectClasses) {
      visitClassRef(visitor,v);
   }

}

static void visitFunctionCall(MetaModelVisitor *visitor, FunctionCall *t)
{

   /*
   struct FunctionCall : public Factor {
   public:
      FunctionDef *Function;
      list <ActualArgument *> Arguments;
   */

   if (visitor->visitFunctionCallOverride()) {
      display_debug(visitor,t);
   }

   visitor->visitFactor(t);
   visitor->visitFunctionCall(t);

   for (auto v : t->Arguments) {
      visitActualArgument(visitor,v);
   }

}

static void visitRuntimeParamRef(MetaModelVisitor *visitor, RuntimeParamRef *t)
{

   /*
   struct RuntimeParamRef : public Factor {
   public:
      AttrOrParam *RuntimeParam;
   */

   if (visitor->visitRuntimeParamRefOverride()) {
      display_debug(visitor,t);
   }

   visitor->visitFactor(t);
   visitor->visitRuntimeParamRef(t);

}

static void visitConstant(MetaModelVisitor *visitor, Constant *t)
{

   /*
   struct Constant : public Factor {
   public:
      string Value;
      enum {Undefined, Numeric, Text, Enumeration} Kind;
   */

   if (visitor->visitConstantOverride()) {
      display_debug(visitor,t);
   }

   visitor->visitFactor(t);
   visitor->visitConstant(t);

}

static void visitClassConst(MetaModelVisitor *visitor, ClassConst *t)
{

   /*
   struct ClassConst : public Factor {
   public:
      Class *Class;
   */

   if (visitor->visitClassConstOverride()) {
      display_debug(visitor,t);
   }

   visitor->visitFactor(t);
   visitor->visitClassConst(t);

}

static void visitAttributeConst(MetaModelVisitor *visitor, AttributeConst *t)
{

   /*
   struct AttributeConst : public Factor {
   public:
      AttrOrParam *Attribute;
   */

   if (visitor->visitAttributeConstOverride()) {
      display_debug(visitor,t);
   }

   visitor->visitFactor(t);
   visitor->visitAttributeConst(t);

}

static void visitUnitRef(MetaModelVisitor *visitor, UnitRef *t)
{

   /*
   struct UnitRef : public Factor {
   public:
      Unit *Unit;
   */

   if (visitor->visitUnitRefOverride()) {
      display_debug(visitor,t);
   }

   visitor->visitFactor(t);
   visitor->visitUnitRef(t);

}

static void visitUnitFunction(MetaModelVisitor *visitor, UnitFunction *t)
{

   /*
   struct UnitFunction : public Factor {
   public:
      string Explanation;
   */

   if (visitor->visitUnitFunctionOverride()) {
      display_debug(visitor,t);
   }

   visitor->visitFactor(t);
   visitor->visitUnitFunction(t);

}

static void visitGraphic(MetaModelVisitor *visitor, Graphic *t)
{

   /*
   class Graphic : public ExtendableME {
      // MetaElement.Name := Name as defined in the INTERLIS-Model
   public:
      Expression *Where;
      // role from ASSOCIATION GraphicBase
      Class *Base;
      // role from ASSOCIATION GraphicRule
      list<DrawingRule *> DrawingRule;
   */

   if (visitor->visitGraphicOverride()) {
      display_debug(visitor,t);
   }

   visitor->visitExtendableME(t);
   visitor->visitGraphic(t);

   for (auto v : t->DrawingRule) {
      visitDrawingRule(visitor,v);
   }

}

static void visitSignParamAssignment(MetaModelVisitor *visitor, SignParamAssignment *t)
{

   /*
   struct SignParamAssignment : public MMObject {
   public:
      AttrOrParam *Param;
      Expression *Assignment;
   */

   if (visitor->visitSignParamAssignmentOverride()) {
      display_debug(visitor,t);
   }

   visitor->visitMMObject(t);
   visitor->visitSignParamAssignment(t);

}

static void visitCondSignParamAssignment(MetaModelVisitor *visitor, CondSignParamAssignment *t)
{

   /*
   struct CondSignParamAssignment : public MMObject {
   public:
      Expression *Where;
      list<SignParamAssignment *> Assignments;
   */

   if (visitor->visitCondSignParamAssignmentOverride()) {
      display_debug(visitor,t);
   }

   visitor->visitMMObject(t);
   visitor->visitCondSignParamAssignment(t);

   for (auto v : t->Assignments) {
      visitSignParamAssignment(visitor,v);
   }

}

static void visitDrawingRule(MetaModelVisitor *visitor, DrawingRule *t)
{

   /*
   class DrawingRule : public ExtendableME {
      // MetaElement.Name := Name as defined in the INTERLIS-Model
   public:
      list<CondSignParamAssignment *> Rule;
      // role from ASSOCIATION GraphicRule
      Graphic *Graphic;
      // role from ASSOCIATION SignClass
      Class *Class;
   */

   if (visitor->visitDrawingRuleOverride()) {
      display_debug(visitor,t);
   }

   visitor->visitExtendableME(t);
   visitor->visitDrawingRule(t);

   for (auto v : t->Rule) {
      visitCondSignParamAssignment(visitor,v);
   }

}

static void visitDocTextTranslation(MetaModelVisitor *visitor, DocTextTranslation *t)
{

   /*
   class DocTextTranslation : public MMObject {
   public:
      string Text;
   */

   if (visitor->visitDocTextTranslationOverride()) {
      display_debug(visitor,t);
   }

   visitor->visitMMObject(t);
   visitor->visitDocTextTranslation(t);

}

static void visitMETranslation(MetaModelVisitor *visitor, METranslation *t)
{

   /*
   struct METranslation : public MMObject {
   public:
      MetaElement *Of;
      string TranslatedName;
      list <DocTextTranslation *> TranslatedDoc;
   */

   if (visitor->visitMETranslationOverride()) {
      display_debug(visitor,t);
   }

   visitor->visitMMObject(t);
   visitor->visitMETranslation(t);

   for (auto v : t->TranslatedDoc) {
      visitDocTextTranslation(visitor,v);
   }

}

static void visitTranslation(MetaModelVisitor *visitor, Translation *t)
{

   /*
   class Translation : public MMObject {
   public:
      string Language;
      list <METranslation *> Translations;
   */

   if (visitor->visitTranslationOverride()) {
      display_debug(visitor,t);
   }

   visitor->visitMMObject(t);
   visitor->visitTranslation(t);

   for (auto v : t->Translations) {
      visitMETranslation(visitor,v);
   }

}

static void visitImport(MetaModelVisitor *visitor, Import *i)
{

   /* class Import : public MMObject { // ASSOCIATION
   public:
      Package *ImportingP;
      Package *ImportedP;
   */

   if (visitor->visitImportOverride()) {
      display_debug(visitor,i);
   }
   
   visitor->visitMMObject(i);
   visitor->visitImport(i);

}

static void preVisitModel(MetaModelVisitor *visitor,Model *m)
{
   if (visitor->preVisitModelOverride()) {
      Log.debug(visitor->getShortName() + ":preVisitModel()");
      visitor->preVisitModel(m);
   }
}

static void postVisitModel(MetaModelVisitor *visitor,Model *m)
{
   if (visitor->postVisitModelOverride()) {
      Log.debug(visitor->getShortName() + ":postVisitModel(" + get_path(m) + ")");
      visitor->postVisitModel(m);
   }
}

static void visitModel(MetaModelVisitor *visitor, Model *m)
{

   /*
   class Model : public Package {
   public:
      string iliVersion;
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
   */

   try {

      preVisitModel(visitor,m);
      Log.incNestLevel();

      for (auto i : get_all_imports()) {
         if (i->ImportingP->Name == m->Name) {
            visitImport(visitor,i);
         }
      }
      visitPackage(visitor,m);
      if (visitor->visitModelOverride()) {
         display_debug(visitor,m);
         visitor->visitModel(m);
      }
      
      Log.decNestLevel();
      postVisitModel(visitor,m);
      
   }
   catch (string e) {
   }

}

static void visitMMObject(MetaModelVisitor *visitor, MMObject *t)
{

   /*
   class MMObject {
   public:
      int _line;
   */

   if (visitor->visitMMObjectOverride()) {
      Log.debug("visitMMObject()");
   }

}

static void preVisit(MetaModelVisitor *visitor)
{
   if (visitor->preVisitOverride()) {
      Log.debug("preVisit()");
   }
   visitor->preVisit();
}

static void postVisit(MetaModelVisitor *visitor)
{
   if (visitor->postVisitOverride()) {
      Log.debug("postVisit()");
   }
   visitor->postVisit();
}

static void visitAllModels(MetaModelVisitor *visitor)
{

   preVisit(visitor);

   for (Model *m : get_all_models()) {
      Log.incNestLevel();
      visitModel(visitor,m);
      Log.decNestLevel();
   }

   postVisit(visitor);

}

} // metamodel

// public interface

void metamodel::MetaModelVisitor::visit(MMObject *o)
{

   if (o->getClass() == "MMObject") {
      metamodel::visitMMObject(this,static_cast<MMObject *>(o));
   }
   else if (o->getClass() == "MMObject") {
      metamodel::visitMMObject(this,static_cast<MMObject *>(o));
   }
   else if (o->getClass() == "Model") {
      metamodel::visitModel(this,static_cast<Model *>(o));
   }
   else if (o->getClass() == "Import") {
      metamodel::visitImport(this,static_cast<Import *>(o));
   }
   else if (o->getClass() == "Unit") {
      metamodel::visitUnit(this,static_cast<Unit *>(o));
   }
   else if (o->getClass() == "NumType") {
      metamodel::visitNumType(this,static_cast<NumType *>(o));
   }
   else if (o->getClass() == "TextType") {
      metamodel::visitTextType(this,static_cast<TextType *>(o));
   }
   else if (o->getClass() == "FormattedType") {
      metamodel::visitFormattedType(this,static_cast<FormattedType *>(o));
   }
   else if (o->getClass() == "EnumType") {
      metamodel::visitEnumType(this,static_cast<EnumType *>(o));
   }
   else if (o->getClass() == "CoordType") {
      metamodel::visitCoordType(this,static_cast<CoordType *>(o));
   }
   else if (o->getClass() == "LineForm") {
      metamodel::visitLineForm(this,static_cast<LineForm *>(o));
   }
   else if (o->getClass() == "FunctionDef") {
      metamodel::visitFunctionDef(this,static_cast<FunctionDef *>(o));
   }
   else if (o->getClass() == "SubModel") {
      metamodel::visitSubModel(this,static_cast<SubModel *>(o));
   }
   else if (o->getClass() == "Class") {
      metamodel::visitClass(this,static_cast<Class *>(o));
   }
   else if (o->getClass() == "DocText") {
      metamodel::visitDocText(this,static_cast<DocText *>(o));
   }
   else if (o->getClass() == "MetaAttribute") {
      metamodel::visitMetaAttribute(this,static_cast<MetaAttribute *>(o));
   }
   else if (o->getClass() == "MetaElement") {
      metamodel::visitMetaElement(this,static_cast<MetaElement *>(o));
   }
   else if (o->getClass() == "ExtendableME") {
      metamodel::visitExtendableME(this,static_cast<ExtendableME *>(o));
   }
   else if (o->getClass() == "Package") {
      metamodel::visitPackage(this,static_cast<Package *>(o));
   }
   else if (o->getClass() == "Ili1Format") {
      metamodel::visitIli1Format(this,static_cast<Ili1Format *>(o));
   }
   else if (o->getClass() == "Expression") {
      metamodel::visitExpression(this,static_cast<Expression *>(o));
   }
   else if (o->getClass() == "Multiplicity") {
      metamodel::visitMultiplicity(this,static_cast<Multiplicity *>(o));
   }
   else if (o->getClass() == "Constraint") {
      metamodel::visitConstraint(this,static_cast<Constraint *>(o));
   }
   else if (o->getClass() == "DomainType") {
      metamodel::visitDomainType(this,static_cast<DomainType *>(o));
   }
   else if (o->getClass() == "Type") {
      metamodel::visitType(this,static_cast<Type *>(o));
   }
   else if (o->getClass() == "AttrOrParam") {
      metamodel::visitAttrOrParam(this,static_cast<AttrOrParam *>(o));
   }
   else if (o->getClass() == "TypeRelatedType") {
      metamodel::visitTypeRelatedType(this,static_cast<TypeRelatedType *>(o));
   }
   else if (o->getClass() == "TypeRestriction") {
      metamodel::visitTypeRestriction(this,static_cast<TypeRestriction *>(o));
   }
   else if (o->getClass() == "MultiValue") {
      metamodel::visitMultiValue(this,static_cast<MultiValue *>(o));
   }
   else if (o->getClass() == "ClassRelatedType") {
      metamodel::visitClassRelatedType(this,static_cast<ClassRelatedType *>(o));
   }
   else if (o->getClass() == "BaseClass") {
      metamodel::visitBaseClass(this,static_cast<BaseClass *>(o));
   }
   else if (o->getClass() == "ClassRestriction") {
      metamodel::visitClassRestriction(this,static_cast<ClassRestriction *>(o));
   }
   else if (o->getClass() == "ReferenceType") {
      metamodel::visitReferenceType(this,static_cast<ReferenceType *>(o));
   }
   else if (o->getClass() == "Role") {
      metamodel::visitRole(this,static_cast<Role *>(o));
   }
   else if (o->getClass() == "ExplicitAssocAccess") {
      metamodel::visitExplicitAssocAccess(this,static_cast<ExplicitAssocAccess *>(o));
   }
   else if (o->getClass() == "AssocAcc") {
      metamodel::visitAssocAcc(this,static_cast<AssocAcc *>(o));
   }
   else if (o->getClass() == "TransferElement") {
      metamodel::visitTransferElement(this,static_cast<TransferElement *>(o));
   }
   else if (o->getClass() == "Ili1TransferElement") {
      metamodel::visitIli1TransferElement(this,static_cast<Ili1TransferElement *>(o));
   }
   else if (o->getClass() == "DataUnit") {
      metamodel::visitDataUnit(this,static_cast<DataUnit *>(o));
   }
   else if (o->getClass() == "AllowedInBasket") {
      metamodel::visitAllowedInBasket(this,static_cast<AllowedInBasket *>(o));
   }
   else if (o->getClass() == "MetaBasketDef") {
      metamodel::visitMetaBasketDef(this,static_cast<MetaBasketDef *>(o));
   }
   else if (o->getClass() == "MetaObjectDef") {
      metamodel::visitMetaObjectDef(this,static_cast<MetaObjectDef *>(o));
   }
   else if (o->getClass() == "BooleanType") {
      metamodel::visitBooleanType(this,static_cast<BooleanType *>(o));
   }
   else if (o->getClass() == "BlackboxType") {
      metamodel::visitBlackboxType(this,static_cast<BlackboxType *>(o));
   }
   else if (o->getClass() == "AxisSpec") {
      metamodel::visitAxisSpec(this,static_cast<AxisSpec *>(o));
   }
   else if (o->getClass() == "NumsRefSys") {
      metamodel::visitNumsRefSys(this,static_cast<NumsRefSys *>(o));
   }
   else if (o->getClass() == "AnyOIDType") {
      metamodel::visitAnyOIDType(this,static_cast<AnyOIDType *>(o));
   }
   else if (o->getClass() == "Argument") {
      metamodel::visitArgument(this,static_cast<Argument *>(o));
   }
   else if (o->getClass() == "ClassRefType") {
      metamodel::visitClassRefType(this,static_cast<ClassRefType *>(o));
   }
   else if (o->getClass() == "ObjectType") {
      metamodel::visitObjectType(this,static_cast<ObjectType *>(o));
   }
   else if (o->getClass() == "AttributeRefType") {
      metamodel::visitAttributeRefType(this,static_cast<AttributeRefType *>(o));
   }
   else if (o->getClass() == "ARefRestriction") {
      metamodel::visitARefRestriction(this,static_cast<ARefRestriction *>(o));
   }
   else if (o->getClass() == "EnumNode") {
      metamodel::visitEnumNode(this,static_cast<EnumNode *>(o));
   }
   else if (o->getClass() == "EnumTreeValueType") {
      metamodel::visitEnumTreeValueType(this,static_cast<EnumTreeValueType *>(o));
   }
   else if (o->getClass() == "LineType") {
      metamodel::visitLineType(this,static_cast<LineType *>(o));
   }
   else if (o->getClass() == "LinesForm") {
      metamodel::visitLinesForm(this,static_cast<LinesForm *>(o));
   }
   else if (o->getClass() == "View") {
      metamodel::visitView(this,static_cast<View *>(o));
   }
   else if (o->getClass() == "RenamedBaseView") {
      metamodel::visitRenamedBaseView(this,static_cast<RenamedBaseView *>(o));
   }
   else if (o->getClass() == "UnaryExpr") {
      metamodel::visitUnaryExpr(this,static_cast<UnaryExpr *>(o));
   }
   else if (o->getClass() == "CompoundExpr") {
      metamodel::visitCompoundExpr(this,static_cast<CompoundExpr *>(o));
   }
   else if (o->getClass() == "Factor") {
      metamodel::visitFactor(this,static_cast<Factor *>(o));
   }
   else if (o->getClass() == "PathEl") {
      metamodel::visitPathEl(this,static_cast<PathEl *>(o));
   }
   else if (o->getClass() == "PathOrInspFactor") {
      metamodel::visitPathOrInspFactor(this,static_cast<PathOrInspFactor *>(o));
   }
   else if (o->getClass() == "EnumAssignment") {
      metamodel::visitEnumAssignment(this,static_cast<EnumAssignment *>(o));
   }
   else if (o->getClass() == "EnumMapping") {
      metamodel::visitEnumMapping(this,static_cast<EnumMapping *>(o));
   }
   else if (o->getClass() == "ClassRef") {
      metamodel::visitClassRef(this,static_cast<ClassRef *>(o));
   }
   else if (o->getClass() == "ActualArgument") {
      metamodel::visitActualArgument(this,static_cast<ActualArgument *>(o));
   }
   else if (o->getClass() == "FunctionCall") {
      metamodel::visitFunctionCall(this,static_cast<FunctionCall *>(o));
   }
   else if (o->getClass() == "RuntimeParamRef") {
      metamodel::visitRuntimeParamRef(this,static_cast<RuntimeParamRef *>(o));
   }
   else if (o->getClass() == "Constant") {
      metamodel::visitConstant(this,static_cast<Constant *>(o));
   }
   else if (o->getClass() == "ClassConst") {
      metamodel::visitClassConst(this,static_cast<ClassConst *>(o));
   }
   else if (o->getClass() == "AttributeConst") {
      metamodel::visitAttributeConst(this,static_cast<AttributeConst *>(o));
   }
   else if (o->getClass() == "UnitRef") {
      metamodel::visitUnitRef(this,static_cast<UnitRef *>(o));
   }
   else if (o->getClass() == "UnitFunction") {
      metamodel::visitUnitFunction(this,static_cast<UnitFunction *>(o));
   }
   else if (o->getClass() == "SimpleConstraint") {
      metamodel::visitSimpleConstraint(this,static_cast<SimpleConstraint *>(o));
   }
   else if (o->getClass() == "ExistenceDef") {
      metamodel::visitExistenceDef(this,static_cast<ExistenceDef *>(o));
   }
   else if (o->getClass() == "ExistenceConstraint") {
      metamodel::visitExistenceConstraint(this,static_cast<ExistenceConstraint *>(o));
   }
   else if (o->getClass() == "UniqueConstraint") {
      metamodel::visitUniqueConstraint(this,static_cast<UniqueConstraint *>(o));
   }
   else if (o->getClass() == "SetConstraint") {
      metamodel::visitSetConstraint(this,static_cast<SetConstraint *>(o));
   }
   else if (o->getClass() == "Graphic") {
      metamodel::visitGraphic(this,static_cast<Graphic *>(o));
   }
   else if (o->getClass() == "SignParamAssignment") {
      metamodel::visitSignParamAssignment(this,static_cast<SignParamAssignment *>(o));
   }
   else if (o->getClass() == "CondSignParamAssignment") {
      metamodel::visitCondSignParamAssignment(this,static_cast<CondSignParamAssignment *>(o));
   }
   else if (o->getClass() == "DrawingRule") {
      metamodel::visitDrawingRule(this,static_cast<DrawingRule *>(o));
   }
   else if (o->getClass() == "DocTextTranslation") {
      metamodel::visitDocTextTranslation(this,static_cast<DocTextTranslation *>(o));
   }
   else if (o->getClass() == "METranslation") {
      metamodel::visitMETranslation(this,static_cast<METranslation *>(o));
   }
   else if (o->getClass() == "Translation") {
      metamodel::visitTranslation(this,static_cast<Translation *>(o));
   }
   else if (o->getClass() == "Context") {
      metamodel::visitContext(this,static_cast<Context *>(o));
   }
   else if (o->getClass() == "GenericDef") {
      metamodel::visitGenericDef(this,static_cast<GenericDef *>(o));
   }
   else {
      Log.internal_error("unknown class " + o->getClass(),1);
   }

}

void metamodel::MetaModelVisitor::visitAllModels()
{
   metamodel::visitAllModels(this);
}