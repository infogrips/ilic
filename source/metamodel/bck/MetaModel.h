// implements IlisMeta16.ili

#pragma once

#include <string>
#include <list>

using namespace std;

namespace metamodel {

   // forward declarations to support
   // recursive classes / structures
   // roles
   class Package;
   class Class;
   class AttrOrParam;
   class Expression;
   class EnumNode;
   class Argument;
   class AttributeRefType;
   class DataUnit;
   class DrawingRule;
   struct EnumAssignment;
   class EnumTreeValueType;
   class ExplicitAssocAccess;
   class FormattedType;
   class FunctionDef;
   class Graphic;
   class LineForm;
   class FormattedType;
   class LineType;
   class MetaObjectDef;
   class NumType;
   class MetaBasketDef;
   class Role;
   class RenamedBaseView;
   class TypeRelatedType;
   class MetaElement;
   class View;
   class Axis;
   class Type;
   class GenericDef;
   class DomainType;

   // general

   class MMObject {
   public:
      int _line;
      virtual string getClass() { return "MMObject"; };
      virtual string getBaseClass() { return ""; };
      virtual bool isAbstract() { return false; };
      bool isInstanceOf(string classname);
   };

   // topic ModelData

   struct DocText : public MMObject {
   public:
      string Name;
      string Text;
      virtual string getClass() { return "DocText"; }
      virtual string getBaseClass() { return "MMObject"; };
   };

   class MetaAttribute : public MMObject {
      // OID: <Parent-OID>.METAOBJECT.Name
   public:
      string Name;
      string Value;
      // ROLE from ASSOCIATION MetaAttributes
      MetaElement *MetaElement;
      virtual string getClass() { return "MetaAttribute"; }
      virtual string getBaseClass() { return "MMObject"; };
   };

   class MetaElement : public MMObject { // ABSTRACT
      // OID: <Parent-OID>.Name
   public:
      string Name;
      list <DocText *> Documentation;
      // ROLE from ASSOCIATION MetaAttributes
      list <MetaAttribute *> MetaAttribute;
      // ROLE from ASSOCIATION PackageElements
      Package *ElementInPackage;
      virtual string getClass() { return "MetaElement"; }
      virtual string getBaseClass() { return "MMObject"; };
      virtual bool isAbstract() { return true; }
   };

   class ExtendableME : public MetaElement {
   public:
      bool Abstract = false;
      bool Generic = false; // 2.4
      bool Final = false;
      // ROLE from ASSOCIATION Inheritance
      ExtendableME *Super;
      // ROLE from ASSOCIATION Inheritance
      list <ExtendableME *> Sub;
      virtual string getClass() { return "ExtendableME"; }
      virtual string getBaseClass() { return "MetaElement"; };
   };

   class Package : public MetaElement {
   public:
      // ROLE from ASSOCIATION PackageElements
      list <MetaElement *> Element;
      virtual string getClass() { return "Package"; }
      virtual string getBaseClass() { return "MetaElement"; };
   };

   class Import : public MMObject { // ASSOCIATION
   public:
      Package *ImportingP;
      Package *ImportedP;
      bool _unqualified = false;
      virtual string getClass() { return "Import"; }
      virtual string getBaseClass() { return "MMObject"; };
   };

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
      virtual string getClass() { return "Ili1Format"; }
      virtual string getBaseClass() { return "MMObject"; };
   };

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
      virtual string getClass() { return "Model"; }
      virtual string getBaseClass() { return "Package"; };
   };

   class SubModel : public Package {
      // MetaElement.Name := TopicName as defined in the INTERLIS-Model
   public:
      virtual string getClass() { return "SubModel"; }
      virtual string getBaseClass() { return "Package"; };
   };

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
      virtual string getClass() { return "Type"; }
      virtual string getBaseClass() { return "ExtendableME"; };
      virtual bool isAbstract() { return true; }
   };

   struct Multiplicity : public MMObject {
   public:
      int Min;
      int Max;
      virtual string getClass() { return "Multiplicity"; }
      virtual string getBaseClass() { return "MMObject"; };
   };

   class Constraint : public MetaElement { // ABSTRACT, 2.4
   public:
      // role from ASSOCIATION DomainConstraint
      DomainType *toDomain; // 2.4
      // role from ASSOCIATION ClassConstraint
      Class *ToClass; // 2.4
      virtual string getClass() { return "Constraint"; }
      virtual string getBaseClass() { return "MetaElement"; };
      virtual bool isAbstract() { return true; }
   };

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
      virtual string getClass() { return "DomainType"; }
       virtual string getBaseClass() { return "Type"; };
     virtual bool isAbstract() { return true; }
   };

   // classes

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
      virtual string getClass() { return "Class"; }
      virtual string getBaseClass() { return "Type"; };
   };

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
      virtual string getClass() { return "AttrOrParam"; }
      virtual string getBaseClass() { return "ExtendableME"; };
   };

   // types related to other types

   class TypeRelatedType : public DomainType { // ABSTRACT
   public:
      // Role from ASSOCIATION BaseType
      Type *BaseType;
      virtual string getClass() { return "TypeRelatedType"; }
      virtual string getBaseClass() { return "DomainType"; };
      virtual bool isAbstract() { return true; }
   };

   class TypeRestriction : public MMObject {
   public:
      TypeRelatedType *TRTR;
      Type *TypeRestriction;
      virtual string getClass() { return "TypeRestriction"; }
      virtual string getBaseClass() { return "MMObject"; };
   };

   // bag type

   class MultiValue : public TypeRelatedType {
      // MetaElement.Name := "Type" because always defined
      //                     within an attribute definition
   public:
      bool Ordered = false;
      Multiplicity Multiplicity;
      virtual string getClass() { return "MultiValue"; }
      virtual string getBaseClass() { return "TypeRelatedType"; };
   };

   // references and associations

   class ClassRelatedType : public DomainType { // ABSTRACT
   public:
      virtual string getClass() { return "ClassRelatedType"; }
      virtual string getBaseClass() { return "DomainType"; };
      virtual bool isAbstract() { return true; }
   };

   class BaseClass : public MMObject { // ASSOCIATION
   public:
      ClassRelatedType *CRT;
      Class *BaseClass;
      virtual string getClass() { return "BaseClass"; }
      virtual string getBaseClass() { return "MMObject"; };
   };

   class ClassRestriction : public MMObject { // ASSOCIATION
   public:
      ClassRelatedType *CRTR;
      Class *ClassRestriction;
      virtual string getClass() { return "ClassRestriction"; }
      virtual string getBaseClass() { return "MMObject"; };
   };

   class ReferenceType : public ClassRelatedType {
   public:
      bool External = false;
      virtual string getClass() { return "ReferenceType"; }
      virtual string getBaseClass() { return "ClassRelatedType"; };
   };

   class Role : public ReferenceType {
      // MetaElement.Name := RoleName as defined in the INTERLIS-Model
   public:
      enum { Assoc, Aggr, Comp } Strongness = Assoc;
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
      virtual string getClass() { return "Role"; }
      virtual string getBaseClass() { return "ReferenceType"; };
   };

   class ExplicitAssocAccess : public ExtendableME {
   public:
      // role from ASSOCIATION ExplicitAssocAcc
      Class *AssocAccOf;
      // role from ASSOCIATION AssocAccOrign
      Role *OriginRole;
      // role from ASSOCIATION AssocAccTarget
      Role *TargetRole;
      virtual string getClass() { return "ExplicitAssocAccess"; }
      virtual string getBaseClass() { return "ExtendableME"; };
   };

   class AssocAcc : public MMObject { // ASSOCIATION
   public:
      Class *Class;
      Role *AssocAcc; // Role OR ExplicitAssocAccess, to do !!!
      virtual string getClass() { return "AssocAcc"; }
      virtual string getBaseClass() { return "MMObject"; };
   };

   // Information for easy transfer

   class TransferElement : public MMObject { // ASSOCIATION
   public:
      Class *TransferClass;
      AttrOrParam *TransferElement; // AttrOrParam OR ExplicitAssocAccess OR Role, to do !!!
      virtual string getClass() { return "TransferElement"; }
      virtual string getBaseClass() { return "MMObject"; };
   };

   class Ili1TransferElement : public MMObject { // ASSOCIATION
   public:
      Class *Ili1TransferClass;
      AttrOrParam *Ili1RefAttr; // ORDERED AttrOrParam OR Role, to do !!!
      virtual string getClass() { return "Ili1TransferElement"; }
      virtual string getBaseClass() { return "MMObject"; };
   };

   // DataUnits

   class DataUnit : public ExtendableME {
   public:
      // Name (EXTENDED): TEXT := "BASKET";
      bool ViewUnit = false;
      string DataUnitName;
      // role from ASSOCIATION MetaDataUnit 
      list <MetaBasketDef *> MetaBasketDef;
      // role from ASSOCIATION BasketOID
      DomainType *Oid; // RESTRICTION(TextType; NumType; AnyOIDType);
      virtual string getClass() { return "DataUnit"; }
      virtual string getBaseClass() { return "ExtendableME"; };
   };

   class Dependency : public MMObject { // m:n ASSOCIATION
   public:
      DataUnit *Using;
      DataUnit *Dependent;
      virtual string getClass() { return "Dependency"; }
      virtual string getBaseClass() { return "MMObject"; };
   };

   class AllowedInBasket : public MMObject { // m:n ASSOCIATION
   public:
      DataUnit *OfDataUnit;
      Class *ClassInBasket;
      virtual string getClass() { return "AllowedInBasket"; }
      virtual string getBaseClass() { return "MMObject"; };
   };

   // Generics and Contexts 2.4

   class Context : public MetaElement {
   public:
      virtual string getClass() { return "Context"; }
      virtual string getBaseClass() { return "MetaElement"; };
   };
       
   class GenericDef : public MMObject { 
   public:
      DomainType *OID; 
      Context *Context;
      list<DomainType *> GenericDomain;
      // role from ASSOCIATION ConcreteForGeneric
      list<DomainType *> ConcreteDomain;
      virtual string getClass() { return "GenericDef"; }
      virtual string getBaseClass() { return "MMObject"; };
   };
    
   // Units

   class Unit : public ExtendableME {
      // MetaElement.Name := ShortName as defined in the INTERLIS-Model
   public:
      enum { BaseU, DerivedU, ComposedU } Kind;
      Expression *Definition;
      // role from ASSOCIATION NumUnit
      list <NumType *> Num;
      string _unitshort;
      virtual string getClass() { return "Unit"; }
      virtual string getBaseClass() { return "ExtendableME"; };
   };

   // MetaObjects 

   class MetaBasketDef : public ExtendableME {
      // MetaElement.Name := BasketName as defined in the INTERLIS-Model
   public:
      enum { SignB, RefSystemB } Kind;
      // role from ASSOCIATION MetaDataUnit
      DataUnit *MetaDataTopic;
      // role from ASSOCIATION MetaBasketMembers
      MetaObjectDef * Member;
      virtual string getClass() { return "MetaBasketDef"; }
      virtual string getBaseClass() { return "ExtendableME"; };
   };

   class MetaObjectDef : public MetaElement {
      // MetaElement.Name := MetaObjectName as defined
      // in the INTERLIS-Model
   public:
      bool IsRefSystem = false;
      // role from ASSOCIATION MetaBasketMembers
      list <MetaBasketDef *> MetaBasketDef;
      // role from ASSOCIATION MetaObjectClass
      Class *Class;
      virtual string getClass() { return "MetaObjectDef"; }
      virtual string getBaseClass() { return "MetaElement"; };
   };

   // base types

   class BooleanType : public DomainType {
   public:
      virtual string getClass() { return "BooleanType"; }
      virtual string getBaseClass() { return "DomainType"; };
   };

   class TextType : public DomainType {
   public:
      enum { MText, Text, Name, Uri } Kind;
      int MaxLength = 0;
      virtual string getClass() { return "TextType"; }
      virtual string getBaseClass() { return "DomainType"; };
   };

   class BlackboxType : public DomainType {
   public:
      enum { Binary, Xml } Kind;
      virtual string getClass() { return "BlackboxType"; }
      virtual string getBaseClass() { return "DomainType"; };
   };

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
      virtual string getClass() { return "NumType"; }
      virtual string getBaseClass() { return "DomainType"; };
   };

   class CoordType : public DomainType {
   public:
      int NullAxis = 1;
      int PiHalfAxis = 2;
      bool Multi = false; // 2.4
      // role from ASSOCIATION LineCoord
      list <NumType *> Axis;
      virtual string getClass() { return "CoordType"; }
      virtual string getBaseClass() { return "DomainType"; };
   };

   class AxisSpec : public MMObject { // ASSOCIATION
   public:
      CoordType *CoordType;
      NumType *Axis;
      virtual string getClass() { return "AxisSpec"; }
      virtual string getBaseClass() { return "MMObject"; };
   };

   class NumsRefSys : public MMObject { // ASSOCIATION
   public:
      NumType *NumType;
      MetaObjectDef *RefSys; // MetaObjectDef OR CoordType, to do !!!
      Axis *AxisInd;
      virtual string getClass() { return "NumsRefSys"; }
      virtual string getBaseClass() { return "MMObject"; };
   };

   class FormattedType : public NumType {
   public:
      string Format;
      // role from ASSOCIATION
      Class *Struct;
      virtual string getClass() { return "FormattedType"; }
      virtual string getBaseClass() { return "NumType"; };
   };

   // OID Definition

   class AnyOIDType : public DomainType {
   public:
      // role from ASSOCIATION ObjectOID
      list<Class *> Class;
      virtual string getClass() { return "AnyOIDType"; }
      virtual string getBaseClass() { return "DomainType"; };
   };

   // Functions

   class FunctionDef : public MetaElement {
      // MetaElement.Name := FunctionName as defined in the INTERLIS-Model
   public:
      string Explanation;
      // role from ASSOCIATION LocalFType
      Type *LocalType;
      Type *ResultType;
      // role from ASSOCIATION FormalArgument
      list <Argument *> Argument;
      virtual string getClass() { return "FunctionDef"; }
      virtual string getBaseClass() { return "MetaElement"; };
   };

   class Argument : public MetaElement {
      // MetaElement.Name := ArgumentName as defined in the INTERLIS-Model
   public:
      enum { TypeVal, EnumVal, EnumTreeVal } Kind;
      // role from ASSOCIATION FormalArgument =
      FunctionDef * Function;
      // role from ASSOCIATION ArgumentType
      Type *Type;
      virtual string getClass() { return "Argument"; }
      virtual string getBaseClass() { return "MetaElement"; };
   };

   // Class and attribute reference types

   class ClassRefType : public ClassRelatedType {
   public:
      virtual string getClass() { return "ClassRefType"; }
      virtual string getBaseClass() { return "ClassReltatedType"; };
   };

   class ObjectType : public ClassRelatedType {
   public:
      bool Multiple = false;
      virtual string getClass() { return "ObjectType"; }
      virtual string getBaseClass() { return "ClassRelatedType"; };
   };

   class AttributeRefType : public DomainType {
   public:
      // role from ASSOCIATION ARefOf
      Class *Of; // Class OR AttrOrParam OR Argument, to do !!!
      virtual string getClass() { return "AttributeRefType"; }
      virtual string getBaseClass() { return "DomainType"; };
   };

   class ARefRestriction : public MMObject { // ASSOCIATION
   public:
      AttributeRefType * ARef;
      Type *Type;
      virtual string getClass() { return "ARefRestriction"; }
      virtual string getBaseClass() { return "MMObject"; };
   };

   // Enumerations

   class EnumType : public DomainType {
   public:
      enum {Unordered, Ordered, Circular} Order;
      // role from ASSOCIATION TopNode
      list <EnumNode *> TopNode;
      // role from ASSOCIATION TreeValueTypeOf
      list <EnumTreeValueType *> ETVT;
      virtual string getClass() { return "EnumType"; }
      virtual string getBaseClass() { return "DomainType"; };
   };

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
      virtual string getClass() { return "EnumNode"; }
      virtual string getBaseClass() { return "ExtendableME"; };
   };

   // Extended enumerations have complete definitions.
   // Inherited nodes refer to base node

   class EnumTreeValueType : public DomainType {
   public:
      // role from ASSOCIATION TreeValueTypeOf
      EnumType *ET;
      virtual string getClass() { return "EnumTreeValueType"; }
      virtual string getBaseClass() { return "DomainType"; };
   };

   // Line types

   class LineForm : public MetaElement {
      // MetaElement.Name := LineFormName as defined in the INTERLIS-Model
   public:
      // role from ASSOCIATION LineFormStructure
      Class *Structure;
      virtual string getClass() { return "LineForm"; }
      virtual string getBaseClass() { return "MetaElement"; };
   };

   class LineType : public DomainType {
   public:
      enum {Polyline, DirectedPolyline, Surface, Area} Kind;
      string MaxOverlap;
      bool Multi = false; // 2.4
      // role from ASSOCIATION LineCoord
      CoordType *CoordType;
      // role from ASSOCIATION LineAttr
      Class *LAStructure;
      virtual string getClass() { return "LineType"; }
      virtual string getBaseClass() { return "DomainType"; };
   };

   class LinesForm : public MMObject { // ASSOCIATION
   public:
      LineType *LineType;
      LineForm *LineForm;
      virtual string getClass() { return "LinesForm"; }
      virtual string getBaseClass() { return "MMObject"; };
   };

   // Views

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
      virtual string getBaseClass() { return "Class"; };
   };

   class RenamedBaseView : public ExtendableME {
      // MetaElement.Name := Name as defined in the INTERLIS-Model
   public:
      bool OrNull = false;
      // role from ASSOCIATION BaseViewDef
      View *View;
      // role from ASSOCIATION BaseViewRef
      Class *BaseView;
      virtual string getClass() { return "RenamedBaseView"; }
      virtual string getBaseClass() { return "ExtendableME"; };
   };

   // Expressions, factors

   struct Expression : public MMObject { // ABSTRACT
   public:
      string _type;
      virtual string getClass() { return "Expression"; }
      virtual string getBaseClass() { return "MMObject"; };
      virtual bool isAbstract() { return true; }
   };

   struct UnaryExpr : public Expression {
   public:
      enum {Not, Defined} Operation;
      Expression *SubExpression;
      virtual string getClass() { return "UnaryExpr"; }
      virtual string getBaseClass() { return "Expression"; };
   };

   struct CompoundExpr : public Expression {
   public:
      enum {Implication, And, Or, Mult, Div, // 2.4 Implication
            Relation_Equal, Relation_NotEqual,
            Relation_LessOrEqual, Relation_GreaterOrEqual,
            Relation_Less, Relation_Greater} Operation;
      list <Expression *> SubExpressions;
      virtual string getClass() { return "CompoundExpr"; }
      virtual string getBaseClass() { return "Expression"; };
   };

   struct Factor : public Expression { // ABSTRACT
   public:
      virtual string getClass() { return "Factor"; }
      virtual string getBaseClass() { return "Expression"; };
      virtual bool isAbstract() { return true; }
   };

   struct PathEl : public MMObject {
   public:
      enum {This, ThisArea, ThatArea, Parent,
            ReferenceAttr, AssocPath, Role, ViewBase,
            Attribute, MetaObject} Kind;
      MetaElement *Ref;
      int NumIndex;
      enum {First, Last} SpecIndex;
      virtual string getClass() { return "PathEl"; }
      virtual string getBaseClass() { return "MMObject"; };
   };

   struct PathOrInspFactor : public Factor {
   public:
      list <PathEl *> PathEls;
      View *Inspection;
      virtual string getClass() { return "PathOrInspFactor"; }
      virtual string getBaseClass() { return "Factor"; };
   };

   struct EnumAssignment : public MMObject {
   public:
      Expression *ValueToAssign;
      EnumNode *MinEnumValue;
      EnumNode *MaxEnumValue;
      virtual string getClass() { return "EnumAssignment"; }
      virtual string getBaseClass() { return "MMObject"; };
   };

   struct EnumMapping : public Factor {
   public:
      PathOrInspFactor *EnumValue;
      list <EnumAssignment *> Cases;
      virtual string getClass() { return "EnumMapping"; }
      virtual string getBaseClass() { return "Factor"; };
   };

   struct ClassRef : public MMObject {
   public:
      Class *Ref;
      virtual string getClass() { return "ClassRef"; }
      virtual string getBaseClass() { return "MMObject"; };
   };

   struct ActualArgument : public MMObject {
   public:
      Argument *FormalArgument;
      enum {ExpressionVal, AllOf} Kind;
      list <Expression *> Expression;
      list <ClassRef *> ObjectClasses;
      virtual string getClass() { return "ActualArgument"; }
      virtual string getBaseClass() { return "MMObject"; };
   };

   struct FunctionCall : public Factor {
   public:
      FunctionDef *Function;
      list <ActualArgument *> Arguments;
      virtual string getClass() { return "FunctionCall"; }
      virtual string getBaseClass() { return "Factor"; };
   };

   struct RuntimeParamRef : public Factor {
   public:
      AttrOrParam *RuntimeParam;
      virtual string getClass() { return "RuntimeParamRef"; }
      virtual string getBaseClass() { return "Factor"; };
   };

   struct Constant : public Factor {
   public:
      string Value;
      enum {Undefined, Numeric, Text, Enumeration} Kind;
      virtual string getClass() { return "Constant"; }
      virtual string getBaseClass() { return "Factor"; };
   };

   struct ClassConst : public Factor {
   public:
      Class *Class;
      virtual string getClass() { return "ClassConst"; }
      virtual string getBaseClass() { return "Factor"; };
   };

   struct AttributeConst : public Factor {
   public:
      AttrOrParam *Attribute;
      virtual string getClass() { return "AttributeConst"; }
      virtual string getBaseClass() { return "Factor"; };
   };

   struct UnitRef : public Factor {
   public:
      Unit *Unit;
      virtual string getClass() { return "UnitRef"; }
      virtual string getBaseClass() { return "Factor"; };
   };

   struct UnitFunction : public Factor {
   public:
      string Explanation;
      virtual string getClass() { return "UnitFunction"; }
      virtual string getBaseClass() { return "Factor"; };
   };

   // Constraints

   class SimpleConstraint : public Constraint { // 2.4 struct -> class
   public:
      enum {MandC, LowPercC, HighPercC} Kind;
      double Percentage;
      Expression *LogicalExpression;
      virtual string getClass() { return "SimpleConstraint"; }
      virtual string getBaseClass() { return "Constraint"; };
   };

   class ExistenceDef : public PathOrInspFactor { // 2.4 struct -> class
   public:
      Class *Viewable;
      virtual string getClass() { return "ExistenceDef"; }
      virtual string getBaseClass() { return "PathOrInspFactor"; };
   };

   class ExistenceConstraint : public Constraint { // 2.4 struct -> class
   public:
      PathOrInspFactor *Attr;
      list<ExistenceDef *> ExistsIn;
      virtual string getClass() { return "ExistenceConstraint"; }
      virtual string getBaseClass() { return "Constraint"; };
   };

   class UniqueConstraint : public Constraint { // 2.4 struct -> class
   public:
      list<Expression *> Where;
      enum {GlobalU, LocalU} Kind;
      list<PathOrInspFactor *> UniqueDef;
      virtual string getClass() { return "UniqueConstraint"; }
      virtual string getBaseClass() { return "Constraint"; };
   };

   class SetConstraint : public Constraint { // 2.4 struct -> class
   public:
      list<Expression *> Where;
      Expression *Constraint;
      virtual string getClass() { return "SetConstraint"; }
      virtual string getBaseClass() { return "Constraint"; };
   };

   // Graphic

   class Graphic : public ExtendableME {
      // MetaElement.Name := Name as defined in the INTERLIS-Model
   public:
      Expression *Where;
      // role from ASSOCIATION GraphicBase
      Class *Base;
      // role from ASSOCIATION GraphicRule
      list<DrawingRule *> DrawingRule;
      virtual string getClass() { return "Graphic"; }
      virtual string getBaseClass() { return "ExtendableME"; };
   };

   struct SignParamAssignment : public MMObject {
   public:
      AttrOrParam *Param;
      Expression *Assignment;
      virtual string getClass() { return "SignParamAssignment"; }
      virtual string getBaseClass() { return "MMObject"; };
   };

   struct CondSignParamAssignment : public MMObject {
   public:
      Expression *Where;
      list<SignParamAssignment *> Assignments;
      virtual string getClass() { return "CondSignParamAssignment"; }
      virtual string getBaseClass() { return "MMObject"; };
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
      virtual string getBaseClass() { return "ExtandbleME"; };
   };

   // topic ModelTranslation

   class DocTextTranslation : public MMObject {
   public:
      string Text;
      virtual string getClass() { return "DocTextTranslation"; }
      virtual string getBaseClass() { return "MMObject"; };
   };
   
   struct METranslation : public MMObject {
   public:
      MetaElement *Of;
      string TranslatedName;
      list <DocTextTranslation *> TranslatedDoc;
      virtual string getClass() { return "METranslation"; }
      virtual string getBaseClass() { return "MMObject"; };
   };

   class Translation : public MMObject {
   public:
      string Language;
      list <METranslation *> Translations;
      virtual string getClass() { return "Translation"; }
      virtual string getBaseClass() { return "MMObject"; };
   };

   // global Variables
   extern Model *INTERLIS;

   // initialization
   void init(string version);

   // model helpers
   list <Model *> get_all_models();
   list <Import *> get_all_imports();
   
   // path helpers
   string get_path(MMObject *o);
   string get_parent_path(MetaElement *e);

};
