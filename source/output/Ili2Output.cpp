#pragma once

#include "Ili2Output.h"
#include "../metamodel/MetaModelOutput.h"
#include "../util/TextWriter.h"
#include "../util/Logger.h"

using namespace util;
using namespace metamodel;
using namespace output;

Ili2Output::Ili2Output(string ili_file,string model_version)
{
   this->ili_file = ili_file;
   this->model_version = model_version;
}
   
void Ili2Output::preVisit()
{

   Log.warning("INTERLIS " + model_version + " generation is not fully implemented yet");

   ili2.openFile(ili_file);
   ili2.writeln("INTERLIS " + model_version + ";");

}

void Ili2Output::postVisit()
{
   ili2.closeFile();
}

namespace output {
   static Model *act_model = nullptr;
}

static void write_type(TextWriter *ili2,Type *t);

string multiplicity_to_string(Multiplicity m)
{
   string multiplicity = "{";
   if (m.Min == m.Max) {
      multiplicity = to_string(m.Min);
   }
   else if (m.Max == -1) {
      multiplicity = to_string(m.Min) + "..*";
   }
   else {
      multiplicity = to_string(m.Min) + ".." + to_string(m.Max);
   }
   return multiplicity + "}";
}

static void write_texttype(TextWriter *ili2,TextType *t) 
{
   ili2->write(0, "TEXT*" + to_string(t->MaxLength));
}

static void write_coordtype(TextWriter *ili2,CoordType *t) 
{

   /* class CoordType : public DomainType {
   public:
      int NullAxis = 1;
      int PiHalfAxis = 2;
      bool Multi = false; // 2.4
      // role from ASSOCIATION LineCoord
      list <NumType *> Axis;
   */

   if (t->Multi) {
      ili2->write(0, "MULTICOORD ");
   }
   else {
      ili2->write(0, "COORD ");
   }
   string axis = "";
   for (auto a : t->Axis) {
      if (axis != "") {
         axis += ", ";
      }
      axis += a->Min + ".." + a->Max;
   }
   ili2->write(0,axis);
   ili2->write(0,", ROTATION " + to_string(t->NullAxis) + "->" + to_string(t->PiHalfAxis));

}

static void write_numtype(TextWriter *ili2,NumType *t) 
{

   /* class NumType : public DomainType {
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

   ili2->write(0,t->Min + ".." + t->Max);
   if (t->Circular) {
      ili2->write(0," CIRCULAR");
   }
   if (t->Unit != nullptr) {
      ili2->write(0," [");
      ili2->write(0,t->Unit->Name);
      ili2->write(0,"]");
   }

}

static void write_linetype(TextWriter *ili2,LineType *t) 
{
   
   /*class LineType : public DomainType {
   public:
      enum {Polyline, DirectedPolyline, Surface, Area} Kind;
      string MaxOverlap;
      bool Multi = false; // 2.4
      // role from ASSOCIATION LineCoord
      CoordType *CoordType;
      // role from ASSOCIATION LineAttr
      Class *LAStructure;
   */

   switch (t->Kind) {
      case LineType::Polyline:
         ili2->write(0,"POLYLINE");
         break;
      case LineType::DirectedPolyline:
         ili2->write(0,"DIRECTED POLYLINE");
         break;
      case LineType::Surface:
         ili2->write(0,"SURFACE");
         break;
      case LineType::Area:
         ili2->write(0,"AREA");
         break;
   }
   
   ili2->write(0," WITH (STRAIGHTS)"); // to do !!!
   if (t->CoordType != nullptr) {
      ili2->write(0, " VERTEX " + t->CoordType->Name);
   }
   else {
      ili2->write(0, " VERTEX ?x?");
   }
   if (t->MaxOverlap != "") {
      ili2->write(0," WITHOUT OVERLAPS>" + t->MaxOverlap);
   }
   if (t->LAStructure != nullptr) {
      ili2->write(0," LINE ATTRIBUTES " + get_path(t->LAStructure));
   }

}

static void write_referencetype(TextWriter *ili2,ReferenceType *t) 
{

   /* class ClassRelatedType : public DomainType { // ABSTRACT
   public:
      Class *BaseClass = nullptr;
   */

   /* class ReferenceType : public ClassRelatedType {
   public:
      bool External = false;
   */

   ili2->write(0, "REFERENCE TO " + get_path(t->BaseClass));

}

static void write_multivalue(TextWriter *ili2,MultiValue *t) 
{

   /* class TypeRelatedType : public DomainType { // ABSTRACT
   public:
      // Role from ASSOCIATION BaseType
      Type *BaseType = nullptr;
   */

   /* class MultiValue : public TypeRelatedType {
   public:
      bool Ordered = false;
      Multiplicity Multiplicity;
      list<Type *> TypeRestriction;
   */

   if (t->Ordered) {
      ili2->write(0,"LIST ");
   }
   else {
      ili2->write(0,"BAG ");
   }

   ili2->write(0,multiplicity_to_string(t->Multiplicity));
   ili2->write(0," OF ???");
//   write_type(ili2,t->TypeRestriction.front()); // multiple type restrictions, to do !!!

}

static void write_type(TextWriter *ili2,Type *t) 
{
   try {
      if (t->Super != nullptr) {
         ili2->write(0,get_path(t->Super));
      }
      else if (t->getClass() == "TextType") {
         write_texttype(ili2,static_cast<TextType *>(t));
      }
      else if (t->getClass() == "CoordType") {
         write_coordtype(ili2,static_cast<CoordType *>(t));
      }
      else if (t->getClass() == "EnumType") {
         write_enumtype(ili2,static_cast<EnumType *>(t));
      }
      else if (t->getClass() == "NumType") {
         write_numtype(ili2,static_cast<NumType *>(t));
      }
      else if (t->getClass() == "LineType") {
         write_linetype(ili2,static_cast<LineType *>(t));
      }
      else if (t->getClass() == "ReferenceType") {
         write_referencetype(ili2,static_cast<ReferenceType *>(t));
      }
      else if (t->getClass() == "MultiValue") {
         write_multivalue(ili2,static_cast<MultiValue *>(t));
      }
      else {
         Log.internal_error("write_class(): <" + t->getClass() + "> not implemented yet",1);
      }
   } 
   catch (exception e) {
      Log.error("unexected exception " + string(e.what()));
   }
}

void Ili2Output::preVisitModel(Model *m)
{

   /* class Model : public Package {
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

   /* MODEL RoadsExdm2ben (de)
      AT "http://www.interlis.ch/models"
      VERSION "2005-06-16"  =
   */

   if (m->Name == "INTERLIS") {
      ignoreVisit();
   }

   ili2.writeln("");
   ili2.writeln("MODEL " + m->Name + " (" + m->Language + ")");
   ili2.incNestLevel();
   ili2.writeln("AT \"" + m->At + "\"");
   ili2.writeln("VERSION \"" + m->Version + "\" =");
   
   Model *act_model = m;

}
   
void Ili2Output::visitModel(Model *m)
{
   
   if (m->Name == "INTERLIS") {
      ignoreVisit();
   }

   // imports
   for (auto i : get_all_imports()) {
      if (i->ImportingP->Name == m->Name) {
         visit(i);
      }
   }

   // all functions
   for (auto e : m->Element) {
      if (e->isSubClassOf("Function")) {
         visit(e);
      }
   }

   // all units
   if (count_metaelement(m->Element,"Unit") > 0) {
      ili2.writeln("");
      ili2.writeln("UNIT");
      ili2.incNestLevel();
      for (auto e : m->Element) {
         if (e->isSubClassOf("Unit")) {
            visit(e);
         }
      }
      ili2.decNestLevel();
   }

   // all domaintypes

   for (auto e : m->Element) {
      if (e->ElementInPackage == nullptr) {
         continue;
      }
      else if (e->isSubClassOf("DomainType")) {
         ili2.writeln("");
         ili2.writeln("DOMAIN");
         break;
      }
   }
         
   ili2.incNestLevel();
   for (auto e : m->Element) {
      if (e->isSubClassOf("DomainType")) {
         if (e->ElementInPackage == nullptr) {
            continue;
         }
         visit(e);
      }
   }
   ili2.decNestLevel();

   // all topics
   for (auto e : m->Element) {
      if (e->isSubClassOf("SubModel")) {
         Log.incNestLevel();
         visit(e);
         Log.decNestLevel();
      }
   }

   ignoreVisit();

}

void Ili2Output::postVisitModel(Model *m)
{

   if (m->Name == "INTERLIS") {
      ignoreVisit();
   }

   ili2.decNestLevel();
   ili2.writeln("");
   ili2.writeln("END " + m->Name + ".");

}

void Ili2Output::visitImport(metamodel::Import *i) 
{

   /* class Import : public MMObject { // ASSOCIATION
   public:
      Package *ImportingP;
      Package *ImportedP;
      bool _unqualified = false;
   */
   
   /* importDef
   : IMPORTS importing (COMMA importing)* SEMI

   importing
   : UNQUALIFIED? (importname=path)
   */

   ili2.write("IMPORTS ");
   if (i->_unqualified) {
      ili2.writeNoIdent("UNQUALIFIED ");
   }
   ili2.writelnNoIdent(i->ImportedP->Name + ";");

}

void Ili2Output::preVisitSubModel(SubModel *s)
{

   ili2.writeln("");
   ili2.write("TOPIC " + s->Name);
   if (s->_super != nullptr) {
      ili2.write(0," EXTENDS " + get_path(s->_super));
   }
   ili2.writeln(0," =");
   ili2.incNestLevel();

   // all domaintypes

   for (auto e : s->Element) {
      if (e->ElementInPackage == nullptr) {
         continue;
      }
      else if (e->isSubClassOf("DomainType")) {
         ili2.writeln("");
         ili2.writeln("DOMAIN");
         break;
      }
   }

   ili2.incNestLevel();
   for (auto e : s->Element) {
      if (e->isSubClassOf("DomainType")) {
         if (e->ElementInPackage == nullptr) {
            continue;
         }
         visit(e);
      }
   }
   ili2.decNestLevel();

}

void Ili2Output::postVisitSubModel(SubModel *s)
{

   ili2.decNestLevel();
   ili2.writeln("");
   ili2.writeln("END " + s->Name + ";");

}

void Ili2Output::preVisitClass(Class *c)
{

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

   ili2.writeln("");

   if (c->Kind == Class::ClassVal) {
      ili2.write("CLASS " + c->Name);
   }
   else if (c->Kind == Class::Structure) {
      ili2.write("STRUCTURE " + c->Name);
   }
   else if (c->Kind == Class::ViewVal) {
      ili2.write("VIEW " + c->Name);
   }
   else if (c->Kind == Class::Association) {
      ili2.write("ASSOCIATION " + c->Name);
   }

   if (c->Super != nullptr) {
      if (c->Super->Name == c->Name) {
         ili2.write(0," (EXTENDED)");
      }
      else {
         ili2.write(0," EXTENDS " + get_path(c->Super));
      }
   }
   ili2.writeln(0," =");

   ili2.incNestLevel();

}

void Ili2Output::postVisitClass(Class *c)
{
   ili2.decNestLevel();
   ili2.writeln("END " + c->Name + ";");
}

void Ili2Output::visitSimpleConstraint(metamodel::SimpleConstraint *c)
{

   /* class SimpleConstraint : public Constraint {
   public:
      enum {MandC, LowPercC, HighPercC} Kind;
      double Percentage = 100.0;
      Expression *LogicalExpression = nullptr;
      enum {Equal, LessEqual, GreaterEqual} _percentage_operation = Equal;
   */

   switch (c->Kind) {
      case SimpleConstraint::MandC:
         ili2.writeln("MANDATORY CONSTRAINT");
         ili2.incNestLevel();
         ili2.write("");write_expression(&ili2,c->LogicalExpression);
         ili2.writeln(0,";");
         ili2.decNestLevel();
         break;
      case SimpleConstraint::LowPercC:
         ili2.writeln("PLAUSIBILITY CONSTRAINT");
         ili2.incNestLevel();
         ili2.write("");write_expression(&ili2,c->LogicalExpression);
         ili2.writeln(0,";");
         ili2.decNestLevel();
         break;
      case SimpleConstraint::HighPercC: // High vs. Low ???, to do !!!
         ili2.writeln("PLAUSIBILITY CONSTRAINT");
         ili2.incNestLevel();
         ili2.write("");write_expression(&ili2,c->LogicalExpression);
         ili2.writeln(0,";");
         ili2.decNestLevel();
         break;
      default:
         Log.internal_error("visitSimpleConstraint(): unknown Kind id " + to_string(c->Kind));
   }
      
}

static string get_properties(metamodel::Type* t)
{
   string properties = "";
   if (t->Abstract) {
      properties = "ABSTRACT";
   }
   if (t->Super != nullptr) {
      if (properties == "") {
         properties = "EXTENDED";
      }
      else {
         properties += ",EXTENDED";
      }
   }
   if (t->Generic) {
      if (properties == "") {
         properties = "GENERIC";
      }
      else {
         properties += ",GENERIC";
      }
   }
   if (t->Final) {
      if (properties == "") {
         properties = "FINAL";
      }
      else {
         properties += ",FINAL";
      }
   }
   if (properties == "") {
      return "";
   }
   else {
      return " (" + properties + ")";
   }
}  

void Ili2Output::visitAttrOrParam(AttrOrParam *a)
{
   
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
      virtual string getClass() { return "AttrOrParam"; }
      virtual string getBaseClass() { return "ExtendableME"; };
   */

   if (a->AttrParent == nullptr) {
      return; // ???, to do !!!
   }

   if (a->Type != nullptr) {
      try {
         DomainType *t = dynamic_cast<DomainType *>(a->Type);
         // ili2.write(a->Name + get_properties(t) + ": "); // properties, to do !!!
         ili2.write(a->Name + ": ");
         if (t->Mandatory) {
            ili2.write(0,"MANDATORY ");
         }
         write_type(&ili2,t);
         // visit(t); ???, to do !!!
         ili2.writeln(0,";");
      }
      catch (exception e) {
         Log.error("unable to cast " + a->Type->getClass() + " to DomainType");
      }
   }
   else {
      ili2.writeln(a->Name + ": ???;");
   }

}

void Ili2Output::visitRole(Role *r)
{

   /* class Role : public ReferenceType {
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
   
   /* struct Multiplicity : public MMObject {
   public:
      int Min;
      int Max;
   */

   /* ASSOCIATION StreetAxisAssoc =
      Street -- {1} Street;
      StreetAxis -- {0..*} StreetAxis;
   END StreetAxisAssoc;
   */

   string strongness;
   if (r->Strongness == Role::Assoc) {
      strongness = "--";
   }
   else if (r->Strongness == Role::Aggr) {
      strongness = "<>--";
   }
   else { // Role::Comp
      strongness = "<#>--";
   }
   
   string target = "???";
   for (auto b : get_all_baseclasses()) {
      if (b->CRT != r) {
         continue;
      }
      target = get_path(b->BaseClass);
   }

   ili2.writeln(r->Name + " " + strongness + " " + multiplicity_to_string(r->Multiplicity) + " " + target + ";");

}

void Ili2Output::visitUnit(metamodel::Unit* u)
{

   /*
   class Unit : public ExtendableME {
      // MetaElement.Name := ShortName as defined in the INTERLIS-Model
   public:
      enum { BaseU, DerivedU, ComposedU } Kind;
      Expression* Definition;
      // role from ASSOCIATION NumUnit
      list <NumType*> Num;
      string _unitshort;
   */

   /* unitDecl
      : UNIT(unitDef)*

   unitDef
      : unitname=NAME
      (LPAREN ABSTRACT RPAREN | LBRACE unitshort = path RBRACE) ?
      (EXTENDS super=path) ?
      (EQUAL (derivedUnit | composedUnit)) ?
      SEMI
    */

   ili2.write(u->Name);
   if (u->Abstract) {
      ili2.write(0," (ABSTRACT)");
   }
   if (u->Kind == Unit::DerivedU) {
      ili2.write(0," = ");
      write_expression(&ili2,u->Definition);
   }
   else if (u->Kind == Unit::ComposedU) {
      ili2.write(0," = ");
      // to do !!!
   }
   
   if (u->Super != nullptr) {
      ili2.write(0," [" + u->Super->Name + "]");
   }
   ili2.writeln(0,";");

}

void Ili2Output::visitDomainType(metamodel::DomainType* t)
{

   if (t->ElementInPackage == nullptr) {
      return; // local attribute type, function argument type, COORD Axis Types
   }

   ili2.write(t->Name + get_properties(t) + " = ");
   write_type(&ili2,t);
   ili2.writeln(0,";");

}
