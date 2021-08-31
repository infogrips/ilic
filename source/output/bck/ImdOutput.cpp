#include "ImdOutput.h"

#include "../metamodel/MetaModelOutput.h"
#include "../util/XTFWriter.h"
#include "../util/Logger.h"
#include "../util/Converter.h"

using namespace util;
using namespace metamodel;
using namespace output;

// private helper functions

// class implementation

static void debug(string message)
{
   Log.debug("imd: " + message);
}

ImdOutput::ImdOutput(string xtf_file)
{
   this->xtf_file = xtf_file;
}

void ImdOutput::preVisit(void)
{
   Log.warning("imd generation not fully implemented yet");
   xtf.openFile(xtf_file, get_all_models());
}

void ImdOutput::postVisit(void)
{
   xtf.closeFile();
}

void ImdOutput::preVisitModel(Model *m)
{
   debug(">>> preVisitModel(" + m->Name + ")");
   xtf.openBasket("IlisMeta07", "ModelData", "MODEL." + m->Name);
   debug("<<< preVisitModel(" + m->Name + ")");
}

void ImdOutput::postVisitModel(Model* m)
{
   debug(">>> postVisitModel(" + m->Name + ")");
   xtf.closeBasket();
   debug("<<< postVisitModel(" + m->Name + ")");
}

void ImdOutput::visitDocText(DocText *t)
{

   debug(">>> visitDocText(" + t->Name + ")");
   Log.incNestLevel();

   xtf.openObject("IlisMeta07", "ModelData", "DocText", get_path(t));

   // DocText
   xtf.writeTag("Name", t->Name);
   xtf.writeTag("Text", t->Text);

   xtf.closeObject();

   Log.decNestLevel();
   debug("<<< visitDocText(" + t->Name + ")");

}

void ImdOutput::visitMetaAttribute(MetaAttribute *t)
{

   debug(">>> visitMetaAttribute(" + t->Name + ")");
   Log.incNestLevel();

   xtf.openObject("IlisMeta07", "ModelData", "MetaAttribute", get_path(t));

   // MetaAttribute
   xtf.writeTag("Name", t->Name);
   xtf.writeTag("Value", t->Value);
   xtf.writeRole("MetaElement", get_path(t->MetaElement));

   xtf.closeObject();

   Log.decNestLevel();
   debug("<<< visitMetaAttribute(" + t->Name + ")");

}

void ImdOutput::visitImport(Import *t)
{

   debug(">>> visitImport()");
   Log.incNestLevel();

   xtf.openObject("IlisMeta07", "ModelData", "Import", get_path(t));

   // Import
   xtf.writeRole("ImportingP", get_path(t->ImportingP));
   xtf.writeRole("ImportedP", get_path(t->ImportedP));

   xtf.closeObject();

   Log.decNestLevel();
   debug("<<< visitImport()");

}

void ImdOutput::visitIli1Format(Ili1Format *t)
{

   debug(">>> visitIli1Format()");
   Log.incNestLevel();

   xtf.openObject("IlisMeta07", "ModelData", "Ili1Format", get_path(t));

   // Ili1Format
   xtf.writeTag("LineSize", to_string(t->LineSize));
   xtf.writeTag("tidSize", to_string(t->tidSize));
   xtf.writeTag("blankCode", to_string_bool(t->blankCode));
   xtf.writeTag("undefinedCode", to_string_bool(t->undefinedCode));
   xtf.writeTag("continueCode", to_string_bool(t->continueCode));
   xtf.writeTag("Font", t->Font);
   switch (t->tidKind) {
      case Ili1Format::TID_I16:
         xtf.writeTag("tidKind","TID_I16");
         break;
      case Ili1Format::TID_I32:
         xtf.writeTag("tidKind","TID_I32");
         break;
      case Ili1Format::TID_ANY:
         xtf.writeTag("tidKind","TID_ANY");
         break;
      case Ili1Format::TID_EXPLANATION:
         xtf.writeTag("tidKind","TID_EXPLANATION");
         break;
      default:
         Log.error("unsupported Ili1Format.tidKind value " + to_string(t->tidKind));
         break;
   }
   xtf.writeTag("tidExplanation", t->tidExplanation);

   xtf.closeObject();

   Log.decNestLevel();
   debug("<<< visitIli1Format()");

}

void ImdOutput::visitModel(Model *t)
{

   debug(">>> visitModel(" + t->Name + ")");
   Log.incNestLevel();

   xtf.openObject("IlisMeta07", "ModelData", "Model", get_path(t));

   // MetaElement
   xtf.writeTag("Name", t->Name);
   if (t->Documentation.size() > 0) {
      xtf.openTag("Documentation");
      for (auto tt : t->Documentation) {
         visit(tt); // DocText
      }
      xtf.closeTag();
   }
   if (t->MetaAttribute.size() > 0) {
      xtf.openTag("MetaAttribute");
      for (auto tt : t->MetaAttribute) {
         visit(tt); // MetaAttribute
      }
      xtf.closeTag();
   }

   // Package

   // Model
   xtf.writeTag("iliVersion", t->iliVersion);
   xtf.writeTag("Contracted", to_string_bool(t->Contracted));
   switch (t->Kind) {
      case Model::NormalM:
         xtf.writeTag("Kind","NormalM");
         break;
      case Model::TypeM:
         xtf.writeTag("Kind","TypeM");
         break;
      case Model::RefSystemM:
         xtf.writeTag("Kind","RefSystemM");
         break;
      case Model::SymbologyM:
         xtf.writeTag("Kind","SymbologyM");
         break;
      default:
         Log.error("unsupported Model.Kind value " + to_string(t->Kind));
         break;
   }
   xtf.writeTag("Language", t->Language);
   xtf.writeTag("At", t->At);
   xtf.writeTag("Version", t->Version);
   xtf.writeTag("VersionExplanation", t->VersionExplanation);
   xtf.writeTag("NoIncrementalTransfer", to_string_bool(t->NoIncrementalTransfer));
   xtf.writeTag("CharSetIANAName", t->CharSetIANAName);
   xtf.writeTag("xmlns", t->xmlns);
   xtf.writeTag("ili1Transfername", t->ili1Transfername);
   xtf.writeRole("ili1Format", get_path(t->ili1Format));

   xtf.closeObject();

   Log.decNestLevel();
   debug("<<< visitModel(" + t->Name + ")");

}

void ImdOutput::visitSubModel(SubModel *t)
{

   debug(">>> visitSubModel(" + t->Name + ")");
   Log.incNestLevel();

   xtf.openObject("IlisMeta07", "ModelData", "SubModel", get_path(t));

   // MetaElement
   xtf.writeTag("Name", t->Name);
   xtf.openTag("Documentation");
   for (auto tt : t->Documentation) {
      visit(tt); // DocText
   }
   xtf.closeTag();
   xtf.openTag("MetaAttribute");
   for (auto tt : t->MetaAttribute) {
      visit(tt); // MetaAttribute
   }
   xtf.closeTag();
   xtf.writeRole("ElementInPackage", get_path(t->ElementInPackage));

   // Package
   xtf.openTag("Element");
   for (auto tt : t->Element) {
      visit(tt); // MetaElement
   }
   xtf.closeTag();

   // SubModel

   xtf.closeObject();

   Log.decNestLevel();
   debug("<<< visitSubModel(" + t->Name + ")");

}

void ImdOutput::visitMultiplicity(Multiplicity *t)
{

   debug(">>> visitMultiplicity()");
   Log.incNestLevel();

   xtf.openObject("IlisMeta07", "ModelData", "Multiplicity", get_path(t));

   // Multiplicity
   xtf.writeTag("Min", to_string(t->Min));
   xtf.writeTag("Max", to_string(t->Max));

   xtf.closeObject();

   Log.decNestLevel();
   debug("<<< visitMultiplicity()");

}

void ImdOutput::visitClass(Class *t)
{

   debug(">>> visitClass(" + t->Name + ")");
   Log.incNestLevel();

   xtf.openObject("IlisMeta07", "ModelData", "Class", get_path(t));

   // MetaElement
   xtf.writeTag("Name", t->Name);
   xtf.openTag("Documentation");
   for (auto tt : t->Documentation) {
      visit(tt); // DocText
   }
   xtf.closeTag();
   xtf.openTag("MetaAttribute");
   for (auto tt : t->MetaAttribute) {
      visit(tt); // MetaAttribute
   }
   xtf.closeTag();
   xtf.writeRole("ElementInPackage", get_path(t->ElementInPackage));

   // ExtendableME
   xtf.writeTag("Abstract", to_string_bool(t->Abstract));
   xtf.writeTag("Generic", to_string_bool(t->Generic));
   xtf.writeTag("Final", to_string_bool(t->Final));
   // xtf.writeRole("Super", get_path(t->Super)); to do !!!
   xtf.openTag("Sub");
   for (auto tt : t->Sub) {
      visit(tt); // ExtendableME
   }
   xtf.closeTag();

   // Type
   xtf.openTag("AttrOrParam");
   for (auto tt : t->AttrOrParam) {
      visit(tt); // AttrOrParam
   }
   xtf.closeTag();
   xtf.openTag("TRT");
   for (auto tt : t->TRT) {
      visit(tt); // TypeRelatedType
   }
   xtf.closeTag();
   xtf.writeRole("LFTParent", get_path(t->LFTParent));
   xtf.openTag("Function");
   for (auto tt : t->Function) {
      visit(tt); // FunctionDef
   }
   xtf.closeTag();
   xtf.openTag("Argument");
   for (auto tt : t->Argument) {
      visit(tt); // Argument
   }
   xtf.closeTag();

   // Class
   switch (t->Kind) {
      case Class::Structure:
         xtf.writeTag("Kind","Structure");
         break;
      case Class::ClassVal:
         xtf.writeTag("Kind","ClassVal");
         break;
      case Class::ViewVal:
         xtf.writeTag("Kind","ViewVal");
         break;
      case Class::Association:
         xtf.writeTag("Kind","Association");
         break;
      default:
         Log.error("unsupported Class.Kind value " + to_string(t->Kind));
         break;
   }
   xtf.openTag("Multiplicity");
   visit(&t->Multiplicity); // Multiplicity
   xtf.closeTag();
   xtf.openTag("Constraints");
   for (auto tt : t->Constraints) {
      visit(tt); // Constraint
   }
   xtf.closeTag();
   xtf.writeTag("EmbeddedRoleTransfer", to_string_bool(t->EmbeddedRoleTransfer));
   xtf.writeTag("ili1OptionalTable", to_string_bool(t->ili1OptionalTable));
   xtf.writeRole("LTParent", get_path(t->LTParent));
   xtf.openTag("ClassAttribute");
   for (auto tt : t->ClassAttribute) {
      visit(tt); // metamodel::AttrOrParam
   }
   xtf.closeTag();
   xtf.openTag("Role");
   for (auto tt : t->Role) {
      visit(tt); // Role
   }
   xtf.closeTag();
   xtf.openTag("ExplicitAssocAccess");
   for (auto tt : t->ExplicitAssocAccess) {
      visit(tt); // ExplicitAssocAccess
   }
   xtf.closeTag();
   xtf.openTag("MetaObjectDef");
   for (auto tt : t->MetaObjectDef) {
      visit(tt); // MetaObjectDef
   }
   xtf.closeTag();
   xtf.openTag("FormattedType");
   for (auto tt : t->FormattedType) {
      visit(tt); // FormattedType
   }
   xtf.closeTag();
   xtf.writeRole("Oid", get_path(t->Oid));
   xtf.openTag("ForARef");
   for (auto tt : t->ForARef) {
      visit(tt); // AttributeRefType
   }
   xtf.closeTag();
   xtf.openTag("LineForm");
   for (auto tt : t->LineForm) {
      visit(tt); // LineForm
   }
   xtf.closeTag();
   xtf.openTag("LineType");
   for (auto tt : t->LineType) {
      visit(tt); // LineType
   }
   xtf.closeTag();
   xtf.openTag("RenamedBaseView");
   for (auto tt : t->RenamedBaseView) {
      visit(tt); // RenamedBaseView
   }
   xtf.closeTag();
   xtf.writeRole("View", get_path(t->View));
   xtf.openTag("DrawingRule");
   for (auto tt : t->DrawingRule) {
      visit(tt); // DrawingRule
   }
   xtf.closeTag();
   xtf.openTag("Constraint");
   for (auto tt : t->Constraint) {
      visit(tt); // Constraint
   }
   xtf.closeTag();

   xtf.closeObject();

   Log.decNestLevel();
   debug("<<< visitClass(" + t->Name + ")");

}

void ImdOutput::visitAttrOrParam(AttrOrParam *t)
{

   debug(">>> visitAttrOrParam(" + t->Name + ")");
   Log.incNestLevel();

   xtf.openObject("IlisMeta07", "ModelData", "AttrOrParam", get_path(t));

   // MetaElement
   xtf.writeTag("Name", t->Name);
   xtf.openTag("Documentation");
   for (auto tt : t->Documentation) {
      visit(tt); // DocText
   }
   xtf.closeTag();
   xtf.openTag("MetaAttribute");
   for (auto tt : t->MetaAttribute) {
      visit(tt); // MetaAttribute
   }
   xtf.closeTag();
   xtf.writeRole("ElementInPackage", get_path(t->ElementInPackage));

   // ExtendableME
   xtf.writeTag("Abstract", to_string_bool(t->Abstract));
   xtf.writeTag("Generic", to_string_bool(t->Generic));
   xtf.writeTag("Final", to_string_bool(t->Final));
   // xtf.writeRole("Super", get_path(t->Super)); to do !!!
   xtf.openTag("Sub");
   for (auto tt : t->Sub) {
      visit(tt); // ExtendableME
   }
   xtf.closeTag();

   // AttrOrParam
   switch (t->SubdivisionKind) {
      case AttrOrParam::NoSubDiv:
         xtf.writeTag("SubdivisionKind","NoSubDiv");
         break;
      case AttrOrParam::SubDiv:
         xtf.writeTag("SubdivisionKind","SubDiv");
         break;
      case AttrOrParam::ContSubDiv:
         xtf.writeTag("SubdivisionKind","ContSubDiv");
         break;
      default:
         Log.error("unsupported AttrOrParam.SubdivisionKind value " + to_string(t->SubdivisionKind));
         break;
   }
   xtf.writeTag("Transient", to_string_bool(t->Transient));
   xtf.openTag("Derivates");
   for (auto tt : t->Derivates) {
      visit(tt); // Expression
   }
   xtf.closeTag();
   xtf.openTag("LocalType");
   for (auto tt : t->LocalType) {
      visit(tt); // Type
   }
   xtf.closeTag();
   xtf.writeRole("Type", get_path(t->Type));
   xtf.writeRole("AttrParent", get_path(t->AttrParent));

   xtf.closeObject();

   Log.decNestLevel();
   debug("<<< visitAttrOrParam(" + t->Name + ")");

}

void ImdOutput::visitTypeRestriction(TypeRestriction *t)
{

   debug(">>> visitTypeRestriction()");
   Log.incNestLevel();

   xtf.openObject("IlisMeta07", "ModelData", "TypeRestriction", get_path(t));

   // TypeRestriction
   xtf.writeRole("TRTR", get_path(t->TRTR));
   xtf.writeRole("TypeRestriction", get_path(t->TypeRestriction));

   xtf.closeObject();

   Log.decNestLevel();
   debug("<<< visitTypeRestriction()");

}

void ImdOutput::visitMultiValue(MultiValue *t)
{

   debug(">>> visitMultiValue(" + t->Name + ")");
   Log.incNestLevel();

   xtf.openObject("IlisMeta07", "ModelData", "MultiValue", get_path(t));

   // MetaElement
   xtf.writeTag("Name", t->Name);
   xtf.openTag("Documentation");
   for (auto tt : t->Documentation) {
      visit(tt); // DocText
   }
   xtf.closeTag();
   xtf.openTag("MetaAttribute");
   for (auto tt : t->MetaAttribute) {
      visit(tt); // MetaAttribute
   }
   xtf.closeTag();
   xtf.writeRole("ElementInPackage", get_path(t->ElementInPackage));

   // ExtendableME
   xtf.writeTag("Abstract", to_string_bool(t->Abstract));
   xtf.writeTag("Generic", to_string_bool(t->Generic));
   xtf.writeTag("Final", to_string_bool(t->Final));
   // xtf.writeRole("Super", get_path(t->Super)); to do !!!
   xtf.openTag("Sub");
   for (auto tt : t->Sub) {
      visit(tt); // ExtendableME
   }
   xtf.closeTag();

   // Type
   xtf.openTag("AttrOrParam");
   for (auto tt : t->AttrOrParam) {
      visit(tt); // AttrOrParam
   }
   xtf.closeTag();
   xtf.openTag("TRT");
   for (auto tt : t->TRT) {
      visit(tt); // TypeRelatedType
   }
   xtf.closeTag();
   xtf.writeRole("LFTParent", get_path(t->LFTParent));
   xtf.openTag("Function");
   for (auto tt : t->Function) {
      visit(tt); // FunctionDef
   }
   xtf.closeTag();
   xtf.openTag("Argument");
   for (auto tt : t->Argument) {
      visit(tt); // Argument
   }
   xtf.closeTag();

   // DomainType
   xtf.writeTag("Mandatory", to_string_bool(t->Mandatory));
   xtf.openTag("ForDataUnit");
   for (auto tt : t->ForDataUnit) {
      visit(tt); // DataUnit
   }
   xtf.closeTag();
   xtf.openTag("Constraint");
   for (auto tt : t->Constraint) {
      visit(tt); // Constraint
   }
   xtf.closeTag();
   xtf.writeRole("GenericDef", get_path(t->GenericDef));

   // TypeRelatedType
   xtf.writeRole("BaseType", get_path(t->BaseType));

   // MultiValue
   xtf.writeTag("Ordered", to_string_bool(t->Ordered));
   xtf.openTag("Multiplicity");
   visit(t->Multiplicity); // Multiplicity
   xtf.closeTag();
   xtf.openTag("TypeRestriction");
   for (auto tt : t->TypeRestriction) {
      visit(tt); // Type
   }
   xtf.closeTag();

   xtf.closeObject();

   Log.decNestLevel();
   debug("<<< visitMultiValue(" + t->Name + ")");

}

void ImdOutput::visitBaseClass(BaseClass *t)
{

   debug(">>> visitBaseClass()");
   Log.incNestLevel();

   xtf.openObject("IlisMeta07", "ModelData", "BaseClass", get_path(t));

   // BaseClass
   xtf.writeRole("CRT", get_path(t->CRT));
   xtf.writeRole("BaseClass", get_path(t->BaseClass));

   xtf.closeObject();

   Log.decNestLevel();
   debug("<<< visitBaseClass()");

}

void ImdOutput::visitClassRestriction(ClassRestriction *t)
{

   debug(">>> visitClassRestriction()");
   Log.incNestLevel();

   xtf.openObject("IlisMeta07", "ModelData", "ClassRestriction", get_path(t));

   // ClassRestriction
   xtf.writeRole("CRTR", get_path(t->CRTR));
   xtf.writeRole("ClassRestriction", get_path(t->ClassRestriction));

   xtf.closeObject();

   Log.decNestLevel();
   debug("<<< visitClassRestriction()");

}

void ImdOutput::visitReferenceType(ReferenceType *t)
{

   debug(">>> visitReferenceType(" + t->Name + ")");
   Log.incNestLevel();

   xtf.openObject("IlisMeta07", "ModelData", "ReferenceType", get_path(t));

   // MetaElement
   xtf.writeTag("Name", t->Name);
   xtf.openTag("Documentation");
   for (auto tt : t->Documentation) {
      visit(tt); // DocText
   }
   xtf.closeTag();
   xtf.openTag("MetaAttribute");
   for (auto tt : t->MetaAttribute) {
      visit(tt); // MetaAttribute
   }
   xtf.closeTag();
   xtf.writeRole("ElementInPackage", get_path(t->ElementInPackage));

   // ExtendableME
   xtf.writeTag("Abstract", to_string_bool(t->Abstract));
   xtf.writeTag("Generic", to_string_bool(t->Generic));
   xtf.writeTag("Final", to_string_bool(t->Final));
   // xtf.writeRole("Super", get_path(t->Super)); to do !!!
   xtf.openTag("Sub");
   for (auto tt : t->Sub) {
      visit(tt); // ExtendableME
   }
   xtf.closeTag();

   // Type
   xtf.openTag("AttrOrParam");
   for (auto tt : t->AttrOrParam) {
      visit(tt); // AttrOrParam
   }
   xtf.closeTag();
   xtf.openTag("TRT");
   for (auto tt : t->TRT) {
      visit(tt); // TypeRelatedType
   }
   xtf.closeTag();
   xtf.writeRole("LFTParent", get_path(t->LFTParent));
   xtf.openTag("Function");
   for (auto tt : t->Function) {
      visit(tt); // FunctionDef
   }
   xtf.closeTag();
   xtf.openTag("Argument");
   for (auto tt : t->Argument) {
      visit(tt); // Argument
   }
   xtf.closeTag();

   // DomainType
   xtf.writeTag("Mandatory", to_string_bool(t->Mandatory));
   xtf.openTag("ForDataUnit");
   for (auto tt : t->ForDataUnit) {
      visit(tt); // DataUnit
   }
   xtf.closeTag();
   xtf.openTag("Constraint");
   for (auto tt : t->Constraint) {
      visit(tt); // Constraint
   }
   xtf.closeTag();
   xtf.writeRole("GenericDef", get_path(t->GenericDef));

   // ClassRelatedType
   xtf.writeRole("BaseClass", get_path(t->BaseClass));

   // ReferenceType
   xtf.writeTag("External", to_string_bool(t->External));

   xtf.closeObject();

   Log.decNestLevel();
   debug("<<< visitReferenceType(" + t->Name + ")");

}

void ImdOutput::visitRole(Role *t)
{

   debug(">>> visitRole(" + t->Name + ")");
   Log.incNestLevel();

   xtf.openObject("IlisMeta07", "ModelData", "Role", get_path(t));

   // MetaElement
   xtf.writeTag("Name", t->Name);
   xtf.openTag("Documentation");
   for (auto tt : t->Documentation) {
      visit(tt); // DocText
   }
   xtf.closeTag();
   xtf.openTag("MetaAttribute");
   for (auto tt : t->MetaAttribute) {
      visit(tt); // MetaAttribute
   }
   xtf.closeTag();
   xtf.writeRole("ElementInPackage", get_path(t->ElementInPackage));

   // ExtendableME
   xtf.writeTag("Abstract", to_string_bool(t->Abstract));
   xtf.writeTag("Generic", to_string_bool(t->Generic));
   xtf.writeTag("Final", to_string_bool(t->Final));
   // xtf.writeRole("Super", get_path(t->Super)); to do !!!
   xtf.openTag("Sub");
   for (auto tt : t->Sub) {
      visit(tt); // ExtendableME
   }
   xtf.closeTag();

   // Type
   xtf.openTag("AttrOrParam");
   for (auto tt : t->AttrOrParam) {
      visit(tt); // AttrOrParam
   }
   xtf.closeTag();
   xtf.openTag("TRT");
   for (auto tt : t->TRT) {
      visit(tt); // TypeRelatedType
   }
   xtf.closeTag();
   xtf.writeRole("LFTParent", get_path(t->LFTParent));
   xtf.openTag("Function");
   for (auto tt : t->Function) {
      visit(tt); // FunctionDef
   }
   xtf.closeTag();
   xtf.openTag("Argument");
   for (auto tt : t->Argument) {
      visit(tt); // Argument
   }
   xtf.closeTag();

   // DomainType
   xtf.writeTag("Mandatory", to_string_bool(t->Mandatory));
   xtf.openTag("ForDataUnit");
   for (auto tt : t->ForDataUnit) {
      visit(tt); // DataUnit
   }
   xtf.closeTag();
   xtf.openTag("Constraint");
   for (auto tt : t->Constraint) {
      visit(tt); // Constraint
   }
   xtf.closeTag();
   xtf.writeRole("GenericDef", get_path(t->GenericDef));

   // ClassRelatedType
   xtf.writeRole("BaseClass", get_path(t->BaseClass));

   // ReferenceType
   xtf.writeTag("External", to_string_bool(t->External));

   // Role
   switch (t->Strongness) {
      case Role::Assoc:
         xtf.writeTag("Strongness","Assoc");
         break;
      case Role::Aggr:
         xtf.writeTag("Strongness","Aggr");
         break;
      case Role::Comp:
         xtf.writeTag("Strongness","Comp");
         break;
      default:
         Log.error("unsupported Role.Strongness value " + to_string(t->Strongness));
         break;
   }
   xtf.writeTag("Ordered", to_string_bool(t->Ordered));
   xtf.openTag("Multiplicity");
   visit(t->Multiplicity); // Multiplicity
   xtf.closeTag();
   xtf.openTag("Derivates");
   for (auto tt : t->Derivates) {
      visit(tt); // Expression
   }
   xtf.closeTag();
   xtf.writeTag("EmbeddedTransfer", to_string_bool(t->EmbeddedTransfer));
   xtf.writeRole("Association", get_path(t->Association));
   xtf.openTag("UseAsOrigin");
   for (auto tt : t->UseAsOrigin) {
      visit(tt); // ExplicitAssocAccess
   }
   xtf.closeTag();
   xtf.openTag("UseAsTarget");
   for (auto tt : t->UseAsTarget) {
      visit(tt); // ExplicitAssocAccess
   }
   xtf.closeTag();

   xtf.closeObject();

   Log.decNestLevel();
   debug("<<< visitRole(" + t->Name + ")");

}

void ImdOutput::visitExplicitAssocAccess(ExplicitAssocAccess *t)
{

   debug(">>> visitExplicitAssocAccess(" + t->Name + ")");
   Log.incNestLevel();

   xtf.openObject("IlisMeta07", "ModelData", "ExplicitAssocAccess", get_path(t));

   // MetaElement
   xtf.writeTag("Name", t->Name);
   xtf.openTag("Documentation");
   for (auto tt : t->Documentation) {
      visit(tt); // DocText
   }
   xtf.closeTag();
   xtf.openTag("MetaAttribute");
   for (auto tt : t->MetaAttribute) {
      visit(tt); // MetaAttribute
   }
   xtf.closeTag();
   xtf.writeRole("ElementInPackage", get_path(t->ElementInPackage));

   // ExtendableME
   xtf.writeTag("Abstract", to_string_bool(t->Abstract));
   xtf.writeTag("Generic", to_string_bool(t->Generic));
   xtf.writeTag("Final", to_string_bool(t->Final));
   // xtf.writeRole("Super", get_path(t->Super)); to do !!!
   xtf.openTag("Sub");
   for (auto tt : t->Sub) {
      visit(tt); // ExtendableME
   }
   xtf.closeTag();

   // ExplicitAssocAccess
   xtf.writeRole("AssocAccOf", get_path(t->AssocAccOf));
   xtf.writeRole("OriginRole", get_path(t->OriginRole));
   xtf.writeRole("TargetRole", get_path(t->TargetRole));

   xtf.closeObject();

   Log.decNestLevel();
   debug("<<< visitExplicitAssocAccess(" + t->Name + ")");

}

void ImdOutput::visitAssocAcc(AssocAcc *t)
{

   debug(">>> visitAssocAcc()");
   Log.incNestLevel();

   xtf.openObject("IlisMeta07", "ModelData", "AssocAcc", get_path(t));

   // AssocAcc
   xtf.writeRole("Class", get_path(t->Class));
   xtf.writeRole("AssocAcc", get_path(t->AssocAcc));

   xtf.closeObject();

   Log.decNestLevel();
   debug("<<< visitAssocAcc()");

}

void ImdOutput::visitTransferElement(TransferElement *t)
{

   debug(">>> visitTransferElement()");
   Log.incNestLevel();

   xtf.openObject("IlisMeta07", "ModelData", "TransferElement", get_path(t));

   // TransferElement
   xtf.writeRole("TransferClass", get_path(t->TransferClass));
   xtf.writeRole("TransferElement", get_path(t->TransferElement));

   xtf.closeObject();

   Log.decNestLevel();
   debug("<<< visitTransferElement()");

}

void ImdOutput::visitIli1TransferElement(Ili1TransferElement *t)
{

   debug(">>> visitIli1TransferElement()");
   Log.incNestLevel();

   xtf.openObject("IlisMeta07", "ModelData", "Ili1TransferElement", get_path(t));

   // Ili1TransferElement
   xtf.writeRole("Ili1TransferClass", get_path(t->Ili1TransferClass));
   xtf.writeRole("Ili1RefAttr", get_path(t->Ili1RefAttr));

   xtf.closeObject();

   Log.decNestLevel();
   debug("<<< visitIli1TransferElement()");

}

void ImdOutput::visitDataUnit(DataUnit *t)
{

   debug(">>> visitDataUnit(" + t->Name + ")");
   Log.incNestLevel();

   xtf.openObject("IlisMeta07", "ModelData", "DataUnit", get_path(t));

   // MetaElement
   xtf.writeTag("Name", t->Name);
   xtf.openTag("Documentation");
   for (auto tt : t->Documentation) {
      visit(tt); // DocText
   }
   xtf.closeTag();
   xtf.openTag("MetaAttribute");
   for (auto tt : t->MetaAttribute) {
      visit(tt); // MetaAttribute
   }
   xtf.closeTag();
   xtf.writeRole("ElementInPackage", get_path(t->ElementInPackage));

   // ExtendableME
   xtf.writeTag("Abstract", to_string_bool(t->Abstract));
   xtf.writeTag("Generic", to_string_bool(t->Generic));
   xtf.writeTag("Final", to_string_bool(t->Final));
   // xtf.writeRole("Super", get_path(t->Super)); to do !!!
   xtf.openTag("Sub");
   for (auto tt : t->Sub) {
      visit(tt); // ExtendableME
   }
   xtf.closeTag();

   // DataUnit
   xtf.writeTag("ViewUnit", to_string_bool(t->ViewUnit));
   xtf.writeTag("DataUnitName", t->DataUnitName);
   xtf.openTag("MetaBasketDef");
   for (auto tt : t->MetaBasketDef) {
      visit(tt); // MetaBasketDef
   }
   xtf.closeTag();
   xtf.writeRole("Oid", get_path(t->Oid));

   xtf.closeObject();

   Log.decNestLevel();
   debug("<<< visitDataUnit(" + t->Name + ")");

}

void ImdOutput::visitDependency(Dependency *t)
{

   debug(">>> visitDependency()");
   Log.incNestLevel();

   xtf.openObject("IlisMeta07", "ModelData", "Dependency", get_path(t));

   // Dependency
   xtf.writeRole("Using", get_path(t->Using));
   xtf.writeRole("Dependent", get_path(t->Dependent));

   xtf.closeObject();

   Log.decNestLevel();
   debug("<<< visitDependency()");

}

void ImdOutput::visitAllowedInBasket(AllowedInBasket *t)
{

   debug(">>> visitAllowedInBasket()");
   Log.incNestLevel();

   xtf.openObject("IlisMeta07", "ModelData", "AllowedInBasket", get_path(t));

   // AllowedInBasket
   xtf.writeRole("OfDataUnit", get_path(t->OfDataUnit));
   xtf.writeRole("ClassInBasket", get_path(t->ClassInBasket));

   xtf.closeObject();

   Log.decNestLevel();
   debug("<<< visitAllowedInBasket()");

}

void ImdOutput::visitContext(Context *t)
{

   debug(">>> visitContext(" + t->Name + ")");
   Log.incNestLevel();

   xtf.openObject("IlisMeta07", "ModelData", "Context", get_path(t));

   // MetaElement
   xtf.writeTag("Name", t->Name);
   xtf.openTag("Documentation");
   for (auto tt : t->Documentation) {
      visit(tt); // DocText
   }
   xtf.closeTag();
   xtf.openTag("MetaAttribute");
   for (auto tt : t->MetaAttribute) {
      visit(tt); // MetaAttribute
   }
   xtf.closeTag();
   xtf.writeRole("ElementInPackage", get_path(t->ElementInPackage));

   // Context

   xtf.closeObject();

   Log.decNestLevel();
   debug("<<< visitContext(" + t->Name + ")");

}

void ImdOutput::visitGenericDef(GenericDef *t)
{

   debug(">>> visitGenericDef()");
   Log.incNestLevel();

   xtf.openObject("IlisMeta07", "ModelData", "GenericDef", get_path(t));

   // GenericDef
   xtf.writeRole("OID", get_path(t->OID));
   xtf.writeRole("Context", get_path(t->Context));
   xtf.openTag("GenericDomain");
   for (auto tt : t->GenericDomain) {
      visit(tt); // DomainType
   }
   xtf.closeTag();
   xtf.openTag("ConcreteDomain");
   for (auto tt : t->ConcreteDomain) {
      visit(tt); // DomainType
   }
   xtf.closeTag();

   xtf.closeObject();

   Log.decNestLevel();
   debug("<<< visitGenericDef()");

}

void ImdOutput::visitUnit(Unit *t)
{

   debug(">>> visitUnit(" + t->Name + ")");
   Log.incNestLevel();

   xtf.openObject("IlisMeta07", "ModelData", "Unit", get_path(t));

   // MetaElement
   xtf.writeTag("Name", t->Name);
   xtf.openTag("Documentation");
   for (auto tt : t->Documentation) {
      visit(tt); // DocText
   }
   xtf.closeTag();
   xtf.openTag("MetaAttribute");
   for (auto tt : t->MetaAttribute) {
      visit(tt); // MetaAttribute
   }
   xtf.closeTag();
   xtf.writeRole("ElementInPackage", get_path(t->ElementInPackage));

   // ExtendableME
   xtf.writeTag("Abstract", to_string_bool(t->Abstract));
   xtf.writeTag("Generic", to_string_bool(t->Generic));
   xtf.writeTag("Final", to_string_bool(t->Final));
   // // xtf.writeRole("Super", get_path(t->Super)); to do !!! to do !!!
   xtf.openTag("Sub");
   for (auto tt : t->Sub) {
      visit(tt); // ExtendableME
   }
   xtf.closeTag();

   // Unit
   switch (t->Kind) {
      case Unit::BaseU:
         xtf.writeTag("Kind","BaseU");
         break;
      case Unit::DerivedU:
         xtf.writeTag("Kind","DerivedU");
         break;
      case Unit::ComposedU:
         xtf.writeTag("Kind","ComposedU");
         break;
      default:
         Log.error("unsupported Unit.Kind value " + to_string(t->Kind));
         break;
   }
   xtf.writeRole("Definition", get_path(t->Definition));
   if (t->Num.size() > 0) {
      xtf.openTag("Num");
      for (auto tt : t->Num) {
         visit(tt); // NumType
      }
      xtf.closeTag();
   }

   xtf.closeObject();

   Log.decNestLevel();
   debug("<<< visitUnit(" + t->Name + ")");

}

void ImdOutput::visitMetaBasketDef(MetaBasketDef *t)
{

   debug(">>> visitMetaBasketDef(" + t->Name + ")");
   Log.incNestLevel();

   xtf.openObject("IlisMeta07", "ModelData", "MetaBasketDef", get_path(t));

   // MetaElement
   xtf.writeTag("Name", t->Name);
   xtf.openTag("Documentation");
   for (auto tt : t->Documentation) {
      visit(tt); // DocText
   }
   xtf.closeTag();
   xtf.openTag("MetaAttribute");
   for (auto tt : t->MetaAttribute) {
      visit(tt); // MetaAttribute
   }
   xtf.closeTag();
   xtf.writeRole("ElementInPackage", get_path(t->ElementInPackage));

   // ExtendableME
   xtf.writeTag("Abstract", to_string_bool(t->Abstract));
   xtf.writeTag("Generic", to_string_bool(t->Generic));
   xtf.writeTag("Final", to_string_bool(t->Final));
   // xtf.writeRole("Super", get_path(t->Super)); to do !!!
   xtf.openTag("Sub");
   for (auto tt : t->Sub) {
      visit(tt); // ExtendableME
   }
   xtf.closeTag();

   // MetaBasketDef
   switch (t->Kind) {
      case MetaBasketDef::SignB:
         xtf.writeTag("Kind","SignB");
         break;
      case MetaBasketDef::RefSystemB:
         xtf.writeTag("Kind","RefSystemB");
         break;
      default:
         Log.error("unsupported MetaBasketDef.Kind value " + to_string(t->Kind));
         break;
   }
   xtf.writeRole("MetaDataTopic", get_path(t->MetaDataTopic));
   xtf.writeRole("Member", get_path(t->Member));

   xtf.closeObject();

   Log.decNestLevel();
   debug("<<< visitMetaBasketDef(" + t->Name + ")");

}

void ImdOutput::visitMetaObjectDef(MetaObjectDef *t)
{

   debug(">>> visitMetaObjectDef(" + t->Name + ")");
   Log.incNestLevel();

   xtf.openObject("IlisMeta07", "ModelData", "MetaObjectDef", get_path(t));

   // MetaElement
   xtf.writeTag("Name", t->Name);
   xtf.openTag("Documentation");
   for (auto tt : t->Documentation) {
      visit(tt); // DocText
   }
   xtf.closeTag();
   xtf.openTag("MetaAttribute");
   for (auto tt : t->MetaAttribute) {
      visit(tt); // MetaAttribute
   }
   xtf.closeTag();
   xtf.writeRole("ElementInPackage", get_path(t->ElementInPackage));

   // MetaObjectDef
   xtf.writeTag("IsRefSystem", to_string_bool(t->IsRefSystem));
   xtf.openTag("MetaBasketDef");
   for (auto tt : t->MetaBasketDef) {
      visit(tt); // MetaBasketDef
   }
   xtf.closeTag();
   xtf.writeRole("Class", get_path(t->Class));

   xtf.closeObject();

   Log.decNestLevel();
   debug("<<< visitMetaObjectDef(" + t->Name + ")");

}

void ImdOutput::visitBooleanType(BooleanType *t)
{

   debug(">>> visitBooleanType(" + t->Name + ")");
   Log.incNestLevel();

   xtf.openObject("IlisMeta07", "ModelData", "BooleanType", get_path(t));

   // MetaElement
   xtf.writeTag("Name", t->Name);
   xtf.openTag("Documentation");
   for (auto tt : t->Documentation) {
      visit(tt); // DocText
   }
   xtf.closeTag();
   xtf.openTag("MetaAttribute");
   for (auto tt : t->MetaAttribute) {
      visit(tt); // MetaAttribute
   }
   xtf.closeTag();
   xtf.writeRole("ElementInPackage", get_path(t->ElementInPackage));

   // ExtendableME
   xtf.writeTag("Abstract", to_string_bool(t->Abstract));
   xtf.writeTag("Generic", to_string_bool(t->Generic));
   xtf.writeTag("Final", to_string_bool(t->Final));
   // xtf.writeRole("Super", get_path(t->Super)); to do !!!
   xtf.openTag("Sub");
   for (auto tt : t->Sub) {
      visit(tt); // ExtendableME
   }
   xtf.closeTag();

   // Type
   xtf.openTag("AttrOrParam");
   for (auto tt : t->AttrOrParam) {
      visit(tt); // AttrOrParam
   }
   xtf.closeTag();
   xtf.openTag("TRT");
   for (auto tt : t->TRT) {
      visit(tt); // TypeRelatedType
   }
   xtf.closeTag();
   xtf.writeRole("LFTParent", get_path(t->LFTParent));
   xtf.openTag("Function");
   for (auto tt : t->Function) {
      visit(tt); // FunctionDef
   }
   xtf.closeTag();
   xtf.openTag("Argument");
   for (auto tt : t->Argument) {
      visit(tt); // Argument
   }
   xtf.closeTag();

   // DomainType
   xtf.writeTag("Mandatory", to_string_bool(t->Mandatory));
   xtf.openTag("ForDataUnit");
   for (auto tt : t->ForDataUnit) {
      visit(tt); // DataUnit
   }
   xtf.closeTag();
   xtf.openTag("Constraint");
   for (auto tt : t->Constraint) {
      visit(tt); // Constraint
   }
   xtf.closeTag();
   xtf.writeRole("GenericDef", get_path(t->GenericDef));

   // BooleanType

   xtf.closeObject();

   Log.decNestLevel();
   debug("<<< visitBooleanType(" + t->Name + ")");

}

void ImdOutput::visitTextType(TextType *t)
{

   debug(">>> visitTextType(" + t->Name + ")");
   Log.incNestLevel();

   xtf.openObject("IlisMeta07", "ModelData", "TextType", get_path(t));

   // MetaElement
   xtf.writeTag("Name", t->Name);
   xtf.openTag("Documentation");
   for (auto tt : t->Documentation) {
      visit(tt); // DocText
   }
   xtf.closeTag();
   xtf.openTag("MetaAttribute");
   for (auto tt : t->MetaAttribute) {
      visit(tt); // MetaAttribute
   }
   xtf.closeTag();
   xtf.writeRole("ElementInPackage", get_path(t->ElementInPackage));

   // ExtendableME
   xtf.writeTag("Abstract", to_string_bool(t->Abstract));
   xtf.writeTag("Generic", to_string_bool(t->Generic));
   xtf.writeTag("Final", to_string_bool(t->Final));
//   // xtf.writeRole("Super", get_path(t->Super)); to do !!!
   xtf.openTag("Sub");
   for (auto tt : t->Sub) {
      visit(tt); // ExtendableME
   }
   xtf.closeTag();

   // Type
   xtf.openTag("AttrOrParam");
   for (auto tt : t->AttrOrParam) {
      visit(tt); // AttrOrParam
   }
   xtf.closeTag();
   xtf.openTag("TRT");
   for (auto tt : t->TRT) {
      visit(tt); // TypeRelatedType
   }
   xtf.closeTag();
   xtf.writeRole("LFTParent", get_path(t->LFTParent));
   xtf.openTag("Function");
   for (auto tt : t->Function) {
      visit(tt); // FunctionDef
   }
   xtf.closeTag();
   xtf.openTag("Argument");
   for (auto tt : t->Argument) {
      visit(tt); // Argument
   }
   xtf.closeTag();

   // DomainType
   xtf.writeTag("Mandatory", to_string_bool(t->Mandatory));
   xtf.openTag("ForDataUnit");
   for (auto tt : t->ForDataUnit) {
      visit(tt); // DataUnit
   }
   xtf.closeTag();
   xtf.openTag("Constraint");
   for (auto tt : t->Constraint) {
      visit(tt); // Constraint
   }
   xtf.closeTag();
   xtf.writeRole("GenericDef", get_path(t->GenericDef));

   // TextType
   switch (t->Kind) {
      case TextType::MText:
         xtf.writeTag("Kind","MText");
         break;
      case TextType::Text:
         xtf.writeTag("Kind","Text");
         break;
      case TextType::NameVal:
         xtf.writeTag("Kind","NameVal");
         break;
      case TextType::Uri:
         xtf.writeTag("Kind","Uri");
         break;
      default:
         Log.error("unsupported TextType.Kind value " + to_string(t->Kind));
         break;
   }
   xtf.writeTag("MaxLength", to_string(t->MaxLength));

   xtf.closeObject();

   Log.decNestLevel();
   debug("<<< visitTextType(" + t->Name + ")");

}

void ImdOutput::visitBlackboxType(BlackboxType *t)
{

   debug(">>> visitBlackboxType(" + t->Name + ")");
   Log.incNestLevel();

   xtf.openObject("IlisMeta07", "ModelData", "BlackboxType", get_path(t));

   // MetaElement
   xtf.writeTag("Name", t->Name);
   xtf.openTag("Documentation");
   for (auto tt : t->Documentation) {
      visit(tt); // DocText
   }
   xtf.closeTag();
   xtf.openTag("MetaAttribute");
   for (auto tt : t->MetaAttribute) {
      visit(tt); // MetaAttribute
   }
   xtf.closeTag();
   xtf.writeRole("ElementInPackage", get_path(t->ElementInPackage));

   // ExtendableME
   xtf.writeTag("Abstract", to_string_bool(t->Abstract));
   xtf.writeTag("Generic", to_string_bool(t->Generic));
   xtf.writeTag("Final", to_string_bool(t->Final));
   // xtf.writeRole("Super", get_path(t->Super)); to do !!!
   xtf.openTag("Sub");
   for (auto tt : t->Sub) {
      visit(tt); // ExtendableME
   }
   xtf.closeTag();

   // Type
   xtf.openTag("AttrOrParam");
   for (auto tt : t->AttrOrParam) {
      visit(tt); // AttrOrParam
   }
   xtf.closeTag();
   xtf.openTag("TRT");
   for (auto tt : t->TRT) {
      visit(tt); // TypeRelatedType
   }
   xtf.closeTag();
   xtf.writeRole("LFTParent", get_path(t->LFTParent));
   xtf.openTag("Function");
   for (auto tt : t->Function) {
      visit(tt); // FunctionDef
   }
   xtf.closeTag();
   xtf.openTag("Argument");
   for (auto tt : t->Argument) {
      visit(tt); // Argument
   }
   xtf.closeTag();

   // DomainType
   xtf.writeTag("Mandatory", to_string_bool(t->Mandatory));
   xtf.openTag("ForDataUnit");
   for (auto tt : t->ForDataUnit) {
      visit(tt); // DataUnit
   }
   xtf.closeTag();
   xtf.openTag("Constraint");
   for (auto tt : t->Constraint) {
      visit(tt); // Constraint
   }
   xtf.closeTag();
   xtf.writeRole("GenericDef", get_path(t->GenericDef));

   // BlackboxType
   switch (t->Kind) {
      case BlackboxType::Binary:
         xtf.writeTag("Kind","Binary");
         break;
      case BlackboxType::Xml:
         xtf.writeTag("Kind","Xml");
         break;
      default:
         Log.error("unsupported BlackboxType.Kind value " + to_string(t->Kind));
         break;
   }

   xtf.closeObject();

   Log.decNestLevel();
   debug("<<< visitBlackboxType(" + t->Name + ")");

}

void ImdOutput::visitNumType(NumType *t)
{

   debug(">>> visitNumType(" + t->Name + ")");
   Log.incNestLevel();

   xtf.openObject("IlisMeta07", "ModelData", "NumType", get_path(t));

   // MetaElement
   xtf.writeTag("Name", t->Name);
   xtf.openTag("Documentation");
   for (auto tt : t->Documentation) {
      visit(tt); // DocText
   }
   xtf.closeTag();
   xtf.openTag("MetaAttribute");
   for (auto tt : t->MetaAttribute) {
      visit(tt); // MetaAttribute
   }
   xtf.closeTag();
   xtf.writeRole("ElementInPackage", get_path(t->ElementInPackage));

   // ExtendableME
   xtf.writeTag("Abstract", to_string_bool(t->Abstract));
   xtf.writeTag("Generic", to_string_bool(t->Generic));
   xtf.writeTag("Final", to_string_bool(t->Final));
   // xtf.writeRole("Super", get_path(t->Super)); to do !!!
   xtf.openTag("Sub");
   for (auto tt : t->Sub) {
      visit(tt); // ExtendableME
   }
   xtf.closeTag();

   // Type
   xtf.openTag("AttrOrParam");
   for (auto tt : t->AttrOrParam) {
      visit(tt); // AttrOrParam
   }
   xtf.closeTag();
   xtf.openTag("TRT");
   for (auto tt : t->TRT) {
      visit(tt); // TypeRelatedType
   }
   xtf.closeTag();
   xtf.writeRole("LFTParent", get_path(t->LFTParent));
   xtf.openTag("Function");
   for (auto tt : t->Function) {
      visit(tt); // FunctionDef
   }
   xtf.closeTag();
   xtf.openTag("Argument");
   for (auto tt : t->Argument) {
      visit(tt); // Argument
   }
   xtf.closeTag();

   // DomainType
   xtf.writeTag("Mandatory", to_string_bool(t->Mandatory));
   xtf.openTag("ForDataUnit");
   for (auto tt : t->ForDataUnit) {
      visit(tt); // DataUnit
   }
   xtf.closeTag();
   xtf.openTag("Constraint");
   for (auto tt : t->Constraint) {
      visit(tt); // Constraint
   }
   xtf.closeTag();
   xtf.writeRole("GenericDef", get_path(t->GenericDef));

   // NumType
   xtf.writeTag("Min", t->Min);
   xtf.writeTag("Max", t->Max);
   xtf.writeTag("Circular", to_string_bool(t->Circular));
   xtf.writeTag("Clockwise", to_string_bool(t->Clockwise));
   xtf.writeRole("Unit", get_path(t->Unit));

   xtf.closeObject();

   Log.decNestLevel();
   debug("<<< visitNumType(" + t->Name + ")");

}

void ImdOutput::visitCoordType(CoordType *t)
{

   debug(">>> visitCoordType(" + t->Name + ")");
   Log.incNestLevel();

   xtf.openObject("IlisMeta07", "ModelData", "CoordType", get_path(t));

   // MetaElement
   xtf.writeTag("Name", t->Name);
   xtf.openTag("Documentation");
   for (auto tt : t->Documentation) {
      visit(tt); // DocText
   }
   xtf.closeTag();
   xtf.openTag("MetaAttribute");
   for (auto tt : t->MetaAttribute) {
      visit(tt); // MetaAttribute
   }
   xtf.closeTag();
   xtf.writeRole("ElementInPackage", get_path(t->ElementInPackage));

   // ExtendableME
   xtf.writeTag("Abstract", to_string_bool(t->Abstract));
   xtf.writeTag("Generic", to_string_bool(t->Generic));
   xtf.writeTag("Final", to_string_bool(t->Final));
   // xtf.writeRole("Super", get_path(t->Super)); to do !!!
   xtf.openTag("Sub");
   for (auto tt : t->Sub) {
      visit(tt); // ExtendableME
   }
   xtf.closeTag();

   // Type
   xtf.openTag("AttrOrParam");
   for (auto tt : t->AttrOrParam) {
      visit(tt); // AttrOrParam
   }
   xtf.closeTag();
   xtf.openTag("TRT");
   for (auto tt : t->TRT) {
      visit(tt); // TypeRelatedType
   }
   xtf.closeTag();
   xtf.writeRole("LFTParent", get_path(t->LFTParent));
   xtf.openTag("Function");
   for (auto tt : t->Function) {
      visit(tt); // FunctionDef
   }
   xtf.closeTag();
   xtf.openTag("Argument");
   for (auto tt : t->Argument) {
      visit(tt); // Argument
   }
   xtf.closeTag();

   // DomainType
   xtf.writeTag("Mandatory", to_string_bool(t->Mandatory));
   xtf.openTag("ForDataUnit");
   for (auto tt : t->ForDataUnit) {
      visit(tt); // DataUnit
   }
   xtf.closeTag();
   xtf.openTag("Constraint");
   for (auto tt : t->Constraint) {
      visit(tt); // Constraint
   }
   xtf.closeTag();
   xtf.writeRole("GenericDef", get_path(t->GenericDef));

   // CoordType
   xtf.writeTag("NullAxis", to_string(t->NullAxis));
   xtf.writeTag("PiHalfAxis", to_string(t->PiHalfAxis));
   xtf.writeTag("Multi", to_string_bool(t->Multi));
   xtf.openTag("Axis");
   for (auto tt : t->Axis) {
      visit(tt); // NumType
   }
   xtf.closeTag();

   xtf.closeObject();

   Log.decNestLevel();
   debug("<<< visitCoordType(" + t->Name + ")");

}

void ImdOutput::visitAxisSpec(AxisSpec *t)
{

   debug(">>> visitAxisSpec()");
   Log.incNestLevel();

   xtf.openObject("IlisMeta07", "ModelData", "AxisSpec", get_path(t));

   // AxisSpec
   xtf.writeRole("CoordType", get_path(t->CoordType));
   xtf.writeRole("Axis", get_path(t->Axis));

   xtf.closeObject();

   Log.decNestLevel();
   debug("<<< visitAxisSpec()");

}

void ImdOutput::visitNumsRefSys(NumsRefSys *t)
{

   debug(">>> visitNumsRefSys()");
   Log.incNestLevel();

   xtf.openObject("IlisMeta07", "ModelData", "NumsRefSys", get_path(t));

   // NumsRefSys
   xtf.writeRole("NumType", get_path(t->NumType));
   xtf.writeRole("RefSys", get_path(t->RefSys));
   xtf.writeTag("AxisInd", to_string(t->AxisInd));

   xtf.closeObject();

   Log.decNestLevel();
   debug("<<< visitNumsRefSys()");

}

void ImdOutput::visitFormattedType(FormattedType *t)
{

   debug(">>> visitFormattedType(" + t->Name + ")");
   Log.incNestLevel();

   xtf.openObject("IlisMeta07", "ModelData", "FormattedType", get_path(t));

   // MetaElement
   xtf.writeTag("Name", t->Name);
   xtf.openTag("Documentation");
   for (auto tt : t->Documentation) {
      visit(tt); // DocText
   }
   xtf.closeTag();
   xtf.openTag("MetaAttribute");
   for (auto tt : t->MetaAttribute) {
      visit(tt); // MetaAttribute
   }
   xtf.closeTag();
   xtf.writeRole("ElementInPackage", get_path(t->ElementInPackage));

   // ExtendableME
   xtf.writeTag("Abstract", to_string_bool(t->Abstract));
   xtf.writeTag("Generic", to_string_bool(t->Generic));
   xtf.writeTag("Final", to_string_bool(t->Final));
   // xtf.writeRole("Super", get_path(t->Super)); to do !!!
   xtf.openTag("Sub");
   for (auto tt : t->Sub) {
      visit(tt); // ExtendableME
   }
   xtf.closeTag();

   // Type
   xtf.openTag("AttrOrParam");
   for (auto tt : t->AttrOrParam) {
      visit(tt); // AttrOrParam
   }
   xtf.closeTag();
   xtf.openTag("TRT");
   for (auto tt : t->TRT) {
      visit(tt); // TypeRelatedType
   }
   xtf.closeTag();
   xtf.writeRole("LFTParent", get_path(t->LFTParent));
   xtf.openTag("Function");
   for (auto tt : t->Function) {
      visit(tt); // FunctionDef
   }
   xtf.closeTag();
   xtf.openTag("Argument");
   for (auto tt : t->Argument) {
      visit(tt); // Argument
   }
   xtf.closeTag();

   // DomainType
   xtf.writeTag("Mandatory", to_string_bool(t->Mandatory));
   xtf.openTag("ForDataUnit");
   for (auto tt : t->ForDataUnit) {
      visit(tt); // DataUnit
   }
   xtf.closeTag();
   xtf.openTag("Constraint");
   for (auto tt : t->Constraint) {
      visit(tt); // Constraint
   }
   xtf.closeTag();
   xtf.writeRole("GenericDef", get_path(t->GenericDef));

   // NumType
   xtf.writeTag("Min", t->Min);
   xtf.writeTag("Max", t->Max);
   xtf.writeTag("Circular", to_string_bool(t->Circular));
   xtf.writeTag("Clockwise", to_string_bool(t->Clockwise));
   xtf.writeRole("Unit", get_path(t->Unit));

   // FormattedType
   xtf.writeTag("Format", t->Format);
   xtf.writeRole("Struct", get_path(t->Struct));

   xtf.closeObject();

   Log.decNestLevel();
   debug("<<< visitFormattedType()");

}

void ImdOutput::visitAnyOIDType(AnyOIDType *t)
{

   debug(">>> visitAnyOIDType(" + t->Name + ")");
   Log.incNestLevel();

   xtf.openObject("IlisMeta07", "ModelData", "AnyOIDType", get_path(t));

   // MetaElement
   xtf.writeTag("Name", t->Name);
   xtf.openTag("Documentation");
   for (auto tt : t->Documentation) {
      visit(tt); // DocText
   }
   xtf.closeTag();
   xtf.openTag("MetaAttribute");
   for (auto tt : t->MetaAttribute) {
      visit(tt); // MetaAttribute
   }
   xtf.closeTag();
   xtf.writeRole("ElementInPackage", get_path(t->ElementInPackage));

   // ExtendableME
   xtf.writeTag("Abstract", to_string_bool(t->Abstract));
   xtf.writeTag("Generic", to_string_bool(t->Generic));
   xtf.writeTag("Final", to_string_bool(t->Final));
   // xtf.writeRole("Super", get_path(t->Super)); to do !!!
   xtf.openTag("Sub");
   for (auto tt : t->Sub) {
      visit(tt); // ExtendableME
   }
   xtf.closeTag();

   // Type
   xtf.openTag("AttrOrParam");
   for (auto tt : t->AttrOrParam) {
      visit(tt); // AttrOrParam
   }
   xtf.closeTag();
   xtf.openTag("TRT");
   for (auto tt : t->TRT) {
      visit(tt); // TypeRelatedType
   }
   xtf.closeTag();
   xtf.writeRole("LFTParent", get_path(t->LFTParent));
   xtf.openTag("Function");
   for (auto tt : t->Function) {
      visit(tt); // FunctionDef
   }
   xtf.closeTag();
   xtf.openTag("Argument");
   for (auto tt : t->Argument) {
      visit(tt); // Argument
   }
   xtf.closeTag();

   // DomainType
   xtf.writeTag("Mandatory", to_string_bool(t->Mandatory));
   xtf.openTag("ForDataUnit");
   for (auto tt : t->ForDataUnit) {
      visit(tt); // DataUnit
   }
   xtf.closeTag();
   xtf.openTag("Constraint");
   for (auto tt : t->Constraint) {
      visit(tt); // Constraint
   }
   xtf.closeTag();
   xtf.writeRole("GenericDef", get_path(t->GenericDef));

   // AnyOIDType
   xtf.openTag("Class");
   for (auto tt : t->Class) {
      visit(tt); // Class
   }
   xtf.closeTag();

   xtf.closeObject();

   Log.decNestLevel();
   debug("<<< visitAnyOIDType(" + t->Name + ")");

}

void ImdOutput::visitFunctionDef(FunctionDef *t)
{

   debug(">>> visitFunctionDef(" + t->Name + ")");
   Log.incNestLevel();

   xtf.openObject("IlisMeta07", "ModelData", "FunctionDef", get_path(t));

   // MetaElement
   xtf.writeTag("Name", t->Name);
   xtf.openTag("Documentation");
   for (auto tt : t->Documentation) {
      visit(tt); // DocText
   }
   xtf.closeTag();
   xtf.openTag("MetaAttribute");
   for (auto tt : t->MetaAttribute) {
      visit(tt); // MetaAttribute
   }
   xtf.closeTag();
   xtf.writeRole("ElementInPackage", get_path(t->ElementInPackage));

   // FunctionDef
   xtf.writeTag("Explanation", t->Explanation);
   xtf.writeRole("LocalType", get_path(t->LocalType));
   xtf.writeRole("ResultType", get_path(t->ResultType));
   xtf.openTag("Argument");
   for (auto tt : t->Argument) {
      visit(tt); // Argument
   }
   xtf.closeTag();

   xtf.closeObject();

   Log.decNestLevel();
   debug("<<< visitFunctionDef(" + t->Name + ")");

}

void ImdOutput::visitArgument(Argument *t)
{

   debug(">>> visitArgument(" + t->Name + ")");
   Log.incNestLevel();

   xtf.openObject("IlisMeta07", "ModelData", "Argument", get_path(t));

   // MetaElement
   xtf.writeTag("Name", t->Name);
   xtf.openTag("Documentation");
   for (auto tt : t->Documentation) {
      visit(tt); // DocText
   }
   xtf.closeTag();
   xtf.openTag("MetaAttribute");
   for (auto tt : t->MetaAttribute) {
      visit(tt); // MetaAttribute
   }
   xtf.closeTag();
   xtf.writeRole("ElementInPackage", get_path(t->ElementInPackage));

   // Argument
   switch (t->Kind) {
      case Argument::TypeVal:
         xtf.writeTag("Kind","TypeVal");
         break;
      case Argument::EnumVal:
         xtf.writeTag("Kind","EnumVal");
         break;
      case Argument::EnumTreeVal:
         xtf.writeTag("Kind","EnumTreeVal");
         break;
      default:
         Log.error("unsupported Argument.Kind value " + to_string(t->Kind));
         break;
   }
   xtf.writeRole("Function", get_path(t->Function));
   xtf.writeRole("Type", get_path(t->Type));

   xtf.closeObject();

   Log.decNestLevel();
   debug("<<< visitArgument(" + t->Name + ")");

}

void ImdOutput::visitClassRefType(ClassRefType *t)
{

   debug(">>> visitClassRefType(" + t->Name + ")");
   Log.incNestLevel();

   xtf.openObject("IlisMeta07", "ModelData", "ClassRefType", get_path(t));

   // MetaElement
   xtf.writeTag("Name", t->Name);
   xtf.openTag("Documentation");
   for (auto tt : t->Documentation) {
      visit(tt); // DocText
   }
   xtf.closeTag();
   xtf.openTag("MetaAttribute");
   for (auto tt : t->MetaAttribute) {
      visit(tt); // MetaAttribute
   }
   xtf.closeTag();
   xtf.writeRole("ElementInPackage", get_path(t->ElementInPackage));

   // ExtendableME
   xtf.writeTag("Abstract", to_string_bool(t->Abstract));
   xtf.writeTag("Generic", to_string_bool(t->Generic));
   xtf.writeTag("Final", to_string_bool(t->Final));
   // xtf.writeRole("Super", get_path(t->Super)); to do !!!
   xtf.openTag("Sub");
   for (auto tt : t->Sub) {
      visit(tt); // ExtendableME
   }
   xtf.closeTag();

   // Type
   xtf.openTag("AttrOrParam");
   for (auto tt : t->AttrOrParam) {
      visit(tt); // AttrOrParam
   }
   xtf.closeTag();
   xtf.openTag("TRT");
   for (auto tt : t->TRT) {
      visit(tt); // TypeRelatedType
   }
   xtf.closeTag();
   xtf.writeRole("LFTParent", get_path(t->LFTParent));
   xtf.openTag("Function");
   for (auto tt : t->Function) {
      visit(tt); // FunctionDef
   }
   xtf.closeTag();
   xtf.openTag("Argument");
   for (auto tt : t->Argument) {
      visit(tt); // Argument
   }
   xtf.closeTag();

   // DomainType
   xtf.writeTag("Mandatory", to_string_bool(t->Mandatory));
   xtf.openTag("ForDataUnit");
   for (auto tt : t->ForDataUnit) {
      visit(tt); // DataUnit
   }
   xtf.closeTag();
   xtf.openTag("Constraint");
   for (auto tt : t->Constraint) {
      visit(tt); // Constraint
   }
   xtf.closeTag();
   xtf.writeRole("GenericDef", get_path(t->GenericDef));

   // ClassRelatedType
   xtf.writeRole("BaseClass", get_path(t->BaseClass));

   // ClassRefType

   xtf.closeObject();

   Log.decNestLevel();
   debug("<<< visitClassRefType(" + t->Name + ")");

}

void ImdOutput::visitObjectType(ObjectType *t)
{

   debug(">>> visitObjectType(" + t->Name + ")");
   Log.incNestLevel();

   xtf.openObject("IlisMeta07", "ModelData", "ObjectType", get_path(t));

   // MetaElement
   xtf.writeTag("Name", t->Name);
   xtf.openTag("Documentation");
   for (auto tt : t->Documentation) {
      visit(tt); // DocText
   }
   xtf.closeTag();
   xtf.openTag("MetaAttribute");
   for (auto tt : t->MetaAttribute) {
      visit(tt); // MetaAttribute
   }
   xtf.closeTag();
   xtf.writeRole("ElementInPackage", get_path(t->ElementInPackage));

   // ExtendableME
   xtf.writeTag("Abstract", to_string_bool(t->Abstract));
   xtf.writeTag("Generic", to_string_bool(t->Generic));
   xtf.writeTag("Final", to_string_bool(t->Final));
   // xtf.writeRole("Super", get_path(t->Super)); to do !!!
   xtf.openTag("Sub");
   for (auto tt : t->Sub) {
      visit(tt); // ExtendableME
   }
   xtf.closeTag();

   // Type
   xtf.openTag("AttrOrParam");
   for (auto tt : t->AttrOrParam) {
      visit(tt); // AttrOrParam
   }
   xtf.closeTag();
   xtf.openTag("TRT");
   for (auto tt : t->TRT) {
      visit(tt); // TypeRelatedType
   }
   xtf.closeTag();
   xtf.writeRole("LFTParent", get_path(t->LFTParent));
   xtf.openTag("Function");
   for (auto tt : t->Function) {
      visit(tt); // FunctionDef
   }
   xtf.closeTag();
   xtf.openTag("Argument");
   for (auto tt : t->Argument) {
      visit(tt); // Argument
   }
   xtf.closeTag();

   // DomainType
   xtf.writeTag("Mandatory", to_string_bool(t->Mandatory));
   xtf.openTag("ForDataUnit");
   for (auto tt : t->ForDataUnit) {
      visit(tt); // DataUnit
   }
   xtf.closeTag();
   xtf.openTag("Constraint");
   for (auto tt : t->Constraint) {
      visit(tt); // Constraint
   }
   xtf.closeTag();
   xtf.writeRole("GenericDef", get_path(t->GenericDef));

   // ClassRelatedType
   xtf.writeRole("BaseClass", get_path(t->BaseClass));

   // ObjectType
   xtf.writeTag("Multiple", to_string_bool(t->Multiple));

   xtf.closeObject();

   Log.decNestLevel();
   debug("<<< visitObjectType(" + t->Name + ")");

}

void ImdOutput::visitAttributeRefType(AttributeRefType *t)
{

   debug(">>> visitAttributeRefType(" + t->Name + ")");
   Log.incNestLevel();

   xtf.openObject("IlisMeta07", "ModelData", "AttributeRefType", get_path(t));

   // MetaElement
   xtf.writeTag("Name", t->Name);
   xtf.openTag("Documentation");
   for (auto tt : t->Documentation) {
      visit(tt); // DocText
   }
   xtf.closeTag();
   xtf.openTag("MetaAttribute");
   for (auto tt : t->MetaAttribute) {
      visit(tt); // MetaAttribute
   }
   xtf.closeTag();
   xtf.writeRole("ElementInPackage", get_path(t->ElementInPackage));

   // ExtendableME
   xtf.writeTag("Abstract", to_string_bool(t->Abstract));
   xtf.writeTag("Generic", to_string_bool(t->Generic));
   xtf.writeTag("Final", to_string_bool(t->Final));
   // xtf.writeRole("Super", get_path(t->Super)); to do !!!
   xtf.openTag("Sub");
   for (auto tt : t->Sub) {
      visit(tt); // ExtendableME
   }
   xtf.closeTag();

   // Type
   xtf.openTag("AttrOrParam");
   for (auto tt : t->AttrOrParam) {
      visit(tt); // AttrOrParam
   }
   xtf.closeTag();
   xtf.openTag("TRT");
   for (auto tt : t->TRT) {
      visit(tt); // TypeRelatedType
   }
   xtf.closeTag();
   xtf.writeRole("LFTParent", get_path(t->LFTParent));
   xtf.openTag("Function");
   for (auto tt : t->Function) {
      visit(tt); // FunctionDef
   }
   xtf.closeTag();
   xtf.openTag("Argument");
   for (auto tt : t->Argument) {
      visit(tt); // Argument
   }
   xtf.closeTag();

   // DomainType
   xtf.writeTag("Mandatory", to_string_bool(t->Mandatory));
   xtf.openTag("ForDataUnit");
   for (auto tt : t->ForDataUnit) {
      visit(tt); // DataUnit
   }
   xtf.closeTag();
   xtf.openTag("Constraint");
   for (auto tt : t->Constraint) {
      visit(tt); // Constraint
   }
   xtf.closeTag();
   xtf.writeRole("GenericDef", get_path(t->GenericDef));

   // AttributeRefType
   xtf.writeRole("Of", get_path(t->Of));

   xtf.closeObject();

   Log.decNestLevel();
   debug("<<< visitAttributeRefType(" + t->Name + ")");

}

/* to do !!!
void ImdOutput::visitARefRestriction(ARefRestriction *t)
{

   debug(">>> visitARefRestriction()");
   Log.incNestLevel();

   xtf.openObject("IlisMeta07", "ModelData", "ARefRestriction", get_path(t));

   // ARefRestriction
   xtf.writeRole("ARef", get_path(t->ARef));
   xtf.writeRole("Type", get_path(t->Type));

   xtf.closeObject();

   Log.decNestLevel();
   debug("<<< visitARefRestriction()");

}
*/

void ImdOutput::visitEnumType(EnumType *t)
{

   debug(">>> visitEnumType(" + t->Name + ")");
   Log.incNestLevel();

   xtf.openObject("IlisMeta07", "ModelData", "EnumType", get_path(t));

   // MetaElement
   xtf.writeTag("Name", t->Name);
   xtf.openTag("Documentation");
   for (auto tt : t->Documentation) {
      visit(tt); // DocText
   }
   xtf.closeTag();
   xtf.openTag("MetaAttribute");
   for (auto tt : t->MetaAttribute) {
      visit(tt); // MetaAttribute
   }
   xtf.closeTag();
   xtf.writeRole("ElementInPackage", get_path(t->ElementInPackage));

   // ExtendableME
   xtf.writeTag("Abstract", to_string_bool(t->Abstract));
   xtf.writeTag("Generic", to_string_bool(t->Generic));
   xtf.writeTag("Final", to_string_bool(t->Final));
   // xtf.writeRole("Super", get_path(t->Super)); to do !!!
   xtf.openTag("Sub");
   for (auto tt : t->Sub) {
      visit(tt); // ExtendableME
   }
   xtf.closeTag();

   // Type
   xtf.openTag("AttrOrParam");
   for (auto tt : t->AttrOrParam) {
      visit(tt); // AttrOrParam
   }
   xtf.closeTag();
   xtf.openTag("TRT");
   for (auto tt : t->TRT) {
      visit(tt); // TypeRelatedType
   }
   xtf.closeTag();
   xtf.writeRole("LFTParent", get_path(t->LFTParent));
   xtf.openTag("Function");
   for (auto tt : t->Function) {
      visit(tt); // FunctionDef
   }
   xtf.closeTag();
   xtf.openTag("Argument");
   for (auto tt : t->Argument) {
      visit(tt); // Argument
   }
   xtf.closeTag();

   // DomainType
   xtf.writeTag("Mandatory", to_string_bool(t->Mandatory));
   xtf.openTag("ForDataUnit");
   for (auto tt : t->ForDataUnit) {
      visit(tt); // DataUnit
   }
   xtf.closeTag();
   xtf.openTag("Constraint");
   for (auto tt : t->Constraint) {
      visit(tt); // Constraint
   }
   xtf.closeTag();
   xtf.writeRole("GenericDef", get_path(t->GenericDef));

   // EnumType
   switch (t->Order) {
      case EnumType::Unordered:
         xtf.writeTag("Order","Unordered");
         break;
      case EnumType::Ordered:
         xtf.writeTag("Order","Ordered");
         break;
      case EnumType::Circular:
         xtf.writeTag("Order","Circular");
         break;
      default:
         Log.error("unsupported EnumType.Order value " + to_string(t->Order));
         break;
   }
   xtf.openTag("TopNode");
   for (auto tt : t->TopNode) {
      visit(tt); // EnumNode
   }
   xtf.closeTag();
   xtf.openTag("ETVT");
   for (auto tt : t->ETVT) {
      visit(tt); // EnumTreeValueType
   }
   xtf.closeTag();

   xtf.closeObject();

   Log.decNestLevel();
   debug("<<< visitEnumType(" + t->Name + ")");

}

void ImdOutput::visitEnumNode(EnumNode *t)
{

   debug(">>> visitEnumNode(" + t->Name + ")");
   Log.incNestLevel();

   xtf.openObject("IlisMeta07", "ModelData", "EnumNode", get_path(t));

   // MetaElement
   xtf.writeTag("Name", t->Name);
   xtf.openTag("Documentation");
   for (auto tt : t->Documentation) {
      visit(tt); // DocText
   }
   xtf.closeTag();
   xtf.openTag("MetaAttribute");
   for (auto tt : t->MetaAttribute) {
      visit(tt); // MetaAttribute
   }
   xtf.closeTag();
   xtf.writeRole("ElementInPackage", get_path(t->ElementInPackage));

   // ExtendableME
   xtf.writeTag("Abstract", to_string_bool(t->Abstract));
   xtf.writeTag("Generic", to_string_bool(t->Generic));
   xtf.writeTag("Final", to_string_bool(t->Final));
   // xtf.writeRole("Super", get_path(t->Super)); to do !!!
   xtf.openTag("Sub");
   for (auto tt : t->Sub) {
      visit(tt); // ExtendableME
   }
   xtf.closeTag();

   // EnumNode
   xtf.writeRole("EnumType", get_path(t->EnumType));
   xtf.writeRole("ParentNode", get_path(t->ParentNode));
   xtf.openTag("Node");
   for (auto tt : t->Node) {
      visit(tt); // EnumNode
   }
   xtf.closeTag();

   xtf.closeObject();

   Log.decNestLevel();
   debug("<<< visitEnumNode(" + t->Name + ")");

}

void ImdOutput::visitEnumTreeValueType(EnumTreeValueType *t)
{

   debug(">>> visitEnumTreeValueType(" + t->Name + ")");
   Log.incNestLevel();

   xtf.openObject("IlisMeta07", "ModelData", "EnumTreeValueType", get_path(t));

   // MetaElement
   xtf.writeTag("Name", t->Name);
   xtf.openTag("Documentation");
   for (auto tt : t->Documentation) {
      visit(tt); // DocText
   }
   xtf.closeTag();
   xtf.openTag("MetaAttribute");
   for (auto tt : t->MetaAttribute) {
      visit(tt); // MetaAttribute
   }
   xtf.closeTag();
   xtf.writeRole("ElementInPackage", get_path(t->ElementInPackage));

   // ExtendableME
   xtf.writeTag("Abstract", to_string_bool(t->Abstract));
   xtf.writeTag("Generic", to_string_bool(t->Generic));
   xtf.writeTag("Final", to_string_bool(t->Final));
   // xtf.writeRole("Super", get_path(t->Super)); to do !!!
   xtf.openTag("Sub");
   for (auto tt : t->Sub) {
      visit(tt); // ExtendableME
   }
   xtf.closeTag();

   // Type
   xtf.openTag("AttrOrParam");
   for (auto tt : t->AttrOrParam) {
      visit(tt); // AttrOrParam
   }
   xtf.closeTag();
   xtf.openTag("TRT");
   for (auto tt : t->TRT) {
      visit(tt); // TypeRelatedType
   }
   xtf.closeTag();
   xtf.writeRole("LFTParent", get_path(t->LFTParent));
   xtf.openTag("Function");
   for (auto tt : t->Function) {
      visit(tt); // FunctionDef
   }
   xtf.closeTag();
   xtf.openTag("Argument");
   for (auto tt : t->Argument) {
      visit(tt); // Argument
   }
   xtf.closeTag();

   // DomainType
   xtf.writeTag("Mandatory", to_string_bool(t->Mandatory));
   xtf.openTag("ForDataUnit");
   for (auto tt : t->ForDataUnit) {
      visit(tt); // DataUnit
   }
   xtf.closeTag();
   xtf.openTag("Constraint");
   for (auto tt : t->Constraint) {
      visit(tt); // Constraint
   }
   xtf.closeTag();
   xtf.writeRole("GenericDef", get_path(t->GenericDef));

   // EnumTreeValueType
   xtf.writeRole("ET", get_path(t->ET));

   xtf.closeObject();

   Log.decNestLevel();
   debug("<<< visitEnumTreeValueType(" + t->Name + ")");

}

void ImdOutput::visitLineForm(LineForm *t)
{

   debug(">>> visitLineForm(" + t->Name + ")");
   Log.incNestLevel();

   xtf.openObject("IlisMeta07", "ModelData", "LineForm", get_path(t));

   // MetaElement
   xtf.writeTag("Name", t->Name);
   xtf.openTag("Documentation");
   for (auto tt : t->Documentation) {
      visit(tt); // DocText
   }
   xtf.closeTag();
   xtf.openTag("MetaAttribute");
   for (auto tt : t->MetaAttribute) {
      visit(tt); // MetaAttribute
   }
   xtf.closeTag();
   xtf.writeRole("ElementInPackage", get_path(t->ElementInPackage));

   // LineForm
   xtf.writeRole("Structure", get_path(t->Structure));

   xtf.closeObject();

   Log.decNestLevel();
   debug("<<< visitLineForm(" + t->Name + ")");

}

void ImdOutput::visitLineType(LineType *t)
{

   debug(">>> visitLineType(" + t->Name + ")");
   Log.incNestLevel();

   xtf.openObject("IlisMeta07", "ModelData", "LineType", get_path(t));

   // MetaElement
   xtf.writeTag("Name", t->Name);
   xtf.openTag("Documentation");
   for (auto tt : t->Documentation) {
      visit(tt); // DocText
   }
   xtf.closeTag();
   xtf.openTag("MetaAttribute");
   for (auto tt : t->MetaAttribute) {
      visit(tt); // MetaAttribute
   }
   xtf.closeTag();
   xtf.writeRole("ElementInPackage", get_path(t->ElementInPackage));

   // ExtendableME
   xtf.writeTag("Abstract", to_string_bool(t->Abstract));
   xtf.writeTag("Generic", to_string_bool(t->Generic));
   xtf.writeTag("Final", to_string_bool(t->Final));
   // xtf.writeRole("Super", get_path(t->Super)); to do !!!
   xtf.openTag("Sub");
   for (auto tt : t->Sub) {
      visit(tt); // ExtendableME
   }
   xtf.closeTag();

   // Type
   xtf.openTag("AttrOrParam");
   for (auto tt : t->AttrOrParam) {
      visit(tt); // AttrOrParam
   }
   xtf.closeTag();
   xtf.openTag("TRT");
   for (auto tt : t->TRT) {
      visit(tt); // TypeRelatedType
   }
   xtf.closeTag();
   xtf.writeRole("LFTParent", get_path(t->LFTParent));
   xtf.openTag("Function");
   for (auto tt : t->Function) {
      visit(tt); // FunctionDef
   }
   xtf.closeTag();
   xtf.openTag("Argument");
   for (auto tt : t->Argument) {
      visit(tt); // Argument
   }
   xtf.closeTag();

   // DomainType
   xtf.writeTag("Mandatory", to_string_bool(t->Mandatory));
   xtf.openTag("ForDataUnit");
   for (auto tt : t->ForDataUnit) {
      visit(tt); // DataUnit
   }
   xtf.closeTag();
   xtf.openTag("Constraint");
   for (auto tt : t->Constraint) {
      visit(tt); // Constraint
   }
   xtf.closeTag();
   xtf.writeRole("GenericDef", get_path(t->GenericDef));

   // LineType
   switch (t->Kind) {
      case LineType::Polyline:
         xtf.writeTag("Kind","Polyline");
         break;
      case LineType::DirectedPolyline:
         xtf.writeTag("Kind","DirectedPolyline");
         break;
      case LineType::Surface:
         xtf.writeTag("Kind","Surface");
         break;
      case LineType::Area:
         xtf.writeTag("Kind","Area");
         break;
      default:
         Log.error("unsupported LineType.Kind value " + to_string(t->Kind));
         break;
   }
   xtf.writeTag("MaxOverlap", t->MaxOverlap);
   xtf.writeTag("Multi", to_string_bool(t->Multi));
   xtf.writeRole("CoordType", get_path(t->CoordType));
   xtf.writeRole("LAStructure", get_path(t->LAStructure));
   xtf.openTag("LineForm");
   for (auto tt : t->LineForm) {
      visit(tt); // LineForm
   }
   xtf.closeTag();

   xtf.closeObject();

   Log.decNestLevel();
   debug("<<< visitLineType(" + t->Name + ")");

}

void ImdOutput::visitLinesForm(LinesForm *t)
{

   debug(">>> visitLinesForm()");
   Log.incNestLevel();

   xtf.openObject("IlisMeta07", "ModelData", "LinesForm", get_path(t));

   // LinesForm
   xtf.writeRole("LineType", get_path(t->LineType));
   xtf.writeRole("LineForm", get_path(t->LineForm));

   xtf.closeObject();

   Log.decNestLevel();
   debug("<<< visitLinesForm()");

}

void ImdOutput::visitView(View *t)
{

   debug(">>> visitView(" + t->Name + ")");
   Log.incNestLevel();

   xtf.openObject("IlisMeta07", "ModelData", "View", get_path(t));

   // MetaElement
   xtf.writeTag("Name", t->Name);
   xtf.openTag("Documentation");
   for (auto tt : t->Documentation) {
      visit(tt); // DocText
   }
   xtf.closeTag();
   xtf.openTag("MetaAttribute");
   for (auto tt : t->MetaAttribute) {
      visit(tt); // MetaAttribute
   }
   xtf.closeTag();
   xtf.writeRole("ElementInPackage", get_path(t->ElementInPackage));

   // ExtendableME
   xtf.writeTag("Abstract", to_string_bool(t->Abstract));
   xtf.writeTag("Generic", to_string_bool(t->Generic));
   xtf.writeTag("Final", to_string_bool(t->Final));
   // xtf.writeRole("Super", get_path(t->Super)); to do !!!
   xtf.openTag("Sub");
   for (auto tt : t->Sub) {
      visit(tt); // ExtendableME
   }
   xtf.closeTag();

   // Type
   xtf.openTag("AttrOrParam");
   for (auto tt : t->AttrOrParam) {
      visit(tt); // AttrOrParam
   }
   xtf.closeTag();
   xtf.openTag("TRT");
   for (auto tt : t->TRT) {
      visit(tt); // TypeRelatedType
   }
   xtf.closeTag();
   xtf.writeRole("LFTParent", get_path(t->LFTParent));
   xtf.openTag("Function");
   for (auto tt : t->Function) {
      visit(tt); // FunctionDef
   }
   xtf.closeTag();
   xtf.openTag("Argument");
   for (auto tt : t->Argument) {
      visit(tt); // Argument
   }
   xtf.closeTag();

   // Class
   switch (t->Kind) {
      case Class::Structure:
         xtf.writeTag("Kind","Structure");
         break;
      case Class::ClassVal:
         xtf.writeTag("Kind","ClassVal");
         break;
      case Class::ViewVal:
         xtf.writeTag("Kind","ViewVal");
         break;
      case Class::Association:
         xtf.writeTag("Kind","Association");
         break;
      default:
         Log.error("unsupported Class.Kind value " + to_string(t->Kind));
         break;
   }
   xtf.openTag("Multiplicity");
   visit(t->Multiplicity); // Multiplicity
   xtf.closeTag();
   xtf.openTag("Constraints");
   for (auto tt : t->Constraints) {
      visit(tt); // Constraint
   }
   xtf.closeTag();
   xtf.writeTag("EmbeddedRoleTransfer", to_string_bool(t->EmbeddedRoleTransfer));
   xtf.writeTag("ili1OptionalTable", to_string_bool(t->ili1OptionalTable));
   xtf.writeRole("LTParent", get_path(t->LTParent));
   xtf.openTag("ClassAttribute");
   for (auto tt : t->ClassAttribute) {
      visit(tt); // metamodel::AttrOrParam
   }
   xtf.closeTag();
   xtf.openTag("Role");
   for (auto tt : t->Role) {
      visit(tt); // Role
   }
   xtf.closeTag();
   xtf.openTag("ExplicitAssocAccess");
   for (auto tt : t->ExplicitAssocAccess) {
      visit(tt); // ExplicitAssocAccess
   }
   xtf.closeTag();
   xtf.openTag("MetaObjectDef");
   for (auto tt : t->MetaObjectDef) {
      visit(tt); // MetaObjectDef
   }
   xtf.closeTag();
   xtf.openTag("FormattedType");
   for (auto tt : t->FormattedType) {
      visit(tt); // FormattedType
   }
   xtf.closeTag();
   xtf.writeRole("Oid", get_path(t->Oid));
   xtf.openTag("ForARef");
   for (auto tt : t->ForARef) {
      visit(tt); // AttributeRefType
   }
   xtf.closeTag();
   xtf.openTag("LineForm");
   for (auto tt : t->LineForm) {
      visit(tt); // LineForm
   }
   xtf.closeTag();
   xtf.openTag("LineType");
   for (auto tt : t->LineType) {
      visit(tt); // LineType
   }
   xtf.closeTag();
   xtf.openTag("RenamedBaseView");
   for (auto tt : t->RenamedBaseView) {
      visit(tt); // RenamedBaseView
   }
   xtf.closeTag();
   // xtf.writeRole("View", get_path(t->View)); to do !!!
   xtf.openTag("DrawingRule");
   for (auto tt : t->DrawingRule) {
      visit(tt); // DrawingRule
   }
   xtf.closeTag();
   xtf.openTag("Constraint");
   for (auto tt : t->Constraint) {
      visit(tt); // Constraint
   }
   xtf.closeTag();

   // View
   switch (t->FormationKind) {
      case View::Projection:
         xtf.writeTag("FormationKind","Projection");
         break;
      case View::Join:
         xtf.writeTag("FormationKind","Join");
         break;
      case View::Union:
         xtf.writeTag("FormationKind","Union");
         break;
      case View::Aggregation_All:
         xtf.writeTag("FormationKind","Aggregation_All");
         break;
      case View::Aggregation_Equal:
         xtf.writeTag("FormationKind","Aggregation_Equal");
         break;
      case View::Inspection_Normal:
         xtf.writeTag("FormationKind","Inspection_Normal");
         break;
      case View::Inspection_Area:
         xtf.writeTag("FormationKind","Inspection_Area");
         break;
      default:
         Log.error("unsupported View.FormationKind value " + to_string(t->FormationKind));
         break;
   }
   xtf.openTag("FormationParameter; // PathOrInspFactor onl");
   for (auto tt : t->FormationParameter) {
      visit(tt); // Expression
   }
   xtf.closeTag();
   xtf.writeRole("Where", get_path(t->Where));
   xtf.writeTag("Transient", to_string_bool(t->Transient));
   xtf.openTag("DeriAssoc");
   for (auto tt : t->DeriAssoc) {
      visit(tt); // Class
   }
   xtf.closeTag();

   xtf.closeObject();

   Log.decNestLevel();
   debug("<<< visitView()");

}

void ImdOutput::visitRenamedBaseView(RenamedBaseView *t)
{

   debug(">>> visitRenamedBaseView(" + t->Name + ")");
   Log.incNestLevel();

   xtf.openObject("IlisMeta07", "ModelData", "RenamedBaseView", get_path(t));

   // MetaElement
   xtf.writeTag("Name", t->Name);
   xtf.openTag("Documentation");
   for (auto tt : t->Documentation) {
      visit(tt); // DocText
   }
   xtf.closeTag();
   xtf.openTag("MetaAttribute");
   for (auto tt : t->MetaAttribute) {
      visit(tt); // MetaAttribute
   }
   xtf.closeTag();
   xtf.writeRole("ElementInPackage", get_path(t->ElementInPackage));

   // ExtendableME
   xtf.writeTag("Abstract", to_string_bool(t->Abstract));
   xtf.writeTag("Generic", to_string_bool(t->Generic));
   xtf.writeTag("Final", to_string_bool(t->Final));
   // xtf.writeRole("Super", get_path(t->Super)); to do !!!
   xtf.openTag("Sub");
   for (auto tt : t->Sub) {
      visit(tt); // ExtendableME
   }
   xtf.closeTag();

   // RenamedBaseView
   xtf.writeTag("OrNull", to_string_bool(t->OrNull));
   xtf.writeRole("View", get_path(t->View));
   xtf.writeRole("BaseView", get_path(t->BaseView));

   xtf.closeObject();

   Log.decNestLevel();
   debug("<<< visitRenamedBaseView(" + t->Name + ")");

}

void ImdOutput::visitUnaryExpr(UnaryExpr *t)
{

   debug(">>> visitUnaryExpr()");
   Log.incNestLevel();

   xtf.openObject("IlisMeta07", "ModelData", "UnaryExpr", get_path(t));

   // Expression

   // UnaryExpr
   switch (t->Operation) {
      case UnaryExpr::Not:
         xtf.writeTag("Operation","Not");
         break;
      case UnaryExpr::Defined:
         xtf.writeTag("Operation","Defined");
         break;
      default:
         Log.error("unsupported UnaryExpr.Operation value " + to_string(t->Operation));
         break;
   }
   xtf.writeRole("SubExpression", get_path(t->SubExpression));

   xtf.closeObject();

   Log.decNestLevel();
   debug("<<< visitUnaryExpr()");

}

void ImdOutput::visitCompoundExpr(CompoundExpr* t)
{

   debug(">>> visitCompoundExpr()");
   Log.incNestLevel();

   xtf.openObject("IlisMeta07", "ModelData", "CompoundExpr", get_path(t));

   // Expression

   // CompoundExpr
   /* switch (t->Operation) { // to do !!!
      case CompoundExpr_OperationType::Implication:
         xtf.writeTag("Operation", "Implication");
         break;
      case CompoundExpr_OperationType::And:
         xtf.writeTag("Operation", "And");
         break;
      case CompoundExpr_OperationType::Or:
         xtf.writeTag("Operation", "Or");
         break;
      case CompoundExpr_OperationType::Mult:
         xtf.writeTag("Operation", "Mult");
         break;
      case CompoundExpr_OperationType::Div:
         xtf.writeTag("Operation", "Div");
         break;
      case CompoundExpr_OperationType::Relation_Equal:
         xtf.writeTag("Operation", "Relation_Equal");
         break;
      case CompoundExpr_OperationType::Relation_NotEqual:
         xtf.writeTag("Operation", "Relation_NotEqual");
         break;
      case CompoundExpr_OperationType::Relation_LessOrEqual:
         xtf.writeTag("Operation", "Relation_LessOrEqual");
         break;
      case CompoundExpr_OperationType::Relation_GreaterOrEqual:
         xtf.writeTag("Operation", "Relation_GreaterOrEqual");
         break;
      case CompoundExpr_OperationType::Relation_Less:
         xtf.writeTag("Operation", "Relation_Less");
         break;
      case CompoundExpr_OperationType::Relation_Greater:
         xtf.writeTag("Operation", "Relation_Greater");
         break;
      default:
         Log.error("unsupported UnaryExpr.Operation value " + to_string(t->Operation));
         break;
      }
   } */

   xtf.closeTag();
   xtf.openTag("SubExpressions");
   for (auto tt : t->SubExpressions) {
      visit(tt); // Expression
   }
   xtf.closeTag();

   xtf.closeObject();

   Log.decNestLevel();
   debug("<<< visitCompoundExpr()");

}

void ImdOutput::visitPathEl(PathEl *t)
{

   debug(">>> visitPathEl()");
   Log.incNestLevel();

   xtf.openObject("IlisMeta07", "ModelData", "PathEl", get_path(t));

   // PathEl
   switch (t->Kind) {
      case PathEl::This:
         xtf.writeTag("Kind","This");
         break;
      case PathEl::ThisArea:
         xtf.writeTag("Kind","ThisArea");
         break;
      case PathEl::ThatArea:
         xtf.writeTag("Kind","ThatArea");
         break;
      case PathEl::Parent:
         xtf.writeTag("Kind","Parent");
         break;
      case PathEl::ReferenceAttr:
         xtf.writeTag("Kind","ReferenceAttr");
         break;
      case PathEl::AssocPath:
         xtf.writeTag("Kind","AssocPath");
         break;
      case PathEl::Role:
         xtf.writeTag("Kind","Role");
         break;
      case PathEl::ViewBase:
         xtf.writeTag("Kind","ViewBase");
         break;
      case PathEl::Attribute:
         xtf.writeTag("Kind","Attribute");
         break;
      case PathEl::MetaObject:
         xtf.writeTag("Kind","MetaObject");
         break;
      default:
         Log.error("unsupported PathEl.Kind value " + to_string(t->Kind));
         break;
   }
   xtf.writeRole("Ref", get_path(t->Ref));
   xtf.writeTag("NumIndex", to_string(t->NumIndex));
   switch (t->SpecIndex) {
      case PathEl::First:
         xtf.writeTag("SpecIndex","First");
         break;
      case PathEl::Last:
         xtf.writeTag("SpecIndex","Last");
         break;
      default:
         Log.error("unsupported PathEl.SpecIndex value " + to_string(t->SpecIndex));
         break;
   }

   xtf.closeObject();

   Log.decNestLevel();
   debug("<<< visitPathEl()");

}

void ImdOutput::visitPathOrInspFactor(PathOrInspFactor *t)
{

   debug(">>> visitPathOrInspFactor()");
   Log.incNestLevel();

   xtf.openObject("IlisMeta07", "ModelData", "PathOrInspFactor", get_path(t));

   // Expression

   // Factor

   // PathOrInspFactor
   xtf.openTag("PathEls");
   for (auto tt : t->PathEls) {
      visit(tt); // PathEl
   }
   xtf.closeTag();
   xtf.writeRole("Inspection", get_path(t->Inspection));

   xtf.closeObject();

   Log.decNestLevel();
   debug("<<< visitPathOrInspFactor()");

}

void ImdOutput::visitEnumAssignment(EnumAssignment *t)
{

   debug(">>> visitEnumAssignment()");
   Log.incNestLevel();

   xtf.openObject("IlisMeta07", "ModelData", "EnumAssignment", get_path(t));

   // EnumAssignment
   xtf.writeRole("ValueToAssign", get_path(t->ValueToAssign));
   xtf.writeRole("MinEnumValue", get_path(t->MinEnumValue));
   xtf.writeRole("MaxEnumValue", get_path(t->MaxEnumValue));

   xtf.closeObject();

   Log.decNestLevel();
   debug("<<< visitEnumAssignment()");

}

void ImdOutput::visitEnumMapping(EnumMapping *t)
{

   debug(">>> visitEnumMapping()");
   Log.incNestLevel();

   xtf.openObject("IlisMeta07", "ModelData", "EnumMapping", get_path(t));

   // Expression

   // Factor

   // EnumMapping
   xtf.writeRole("EnumValue", get_path(t->EnumValue));
   xtf.openTag("Cases");
   for (auto tt : t->Cases) {
      visit(tt); // EnumAssignment
   }
   xtf.closeTag();

   xtf.closeObject();

   Log.decNestLevel();
   debug("<<< visitEnumMapping()");

}

void ImdOutput::visitClassRef(ClassRef *t)
{

   debug(">>> visitClassRef()");
   Log.incNestLevel();

   xtf.openObject("IlisMeta07", "ModelData", "ClassRef", get_path(t));

   // ClassRef
   xtf.writeRole("Ref", get_path(t->Ref));

   xtf.closeObject();

   Log.decNestLevel();
   debug("<<< visitClassRef()");

}

void ImdOutput::visitActualArgument(ActualArgument *t)
{

   debug(">>> visitActualArgument()");
   Log.incNestLevel();

   xtf.openObject("IlisMeta07", "ModelData", "ActualArgument", get_path(t));

   // ActualArgument
   xtf.writeRole("FormalArgument", get_path(t->FormalArgument));
   switch (t->Kind) {
      case ActualArgument::ExpressionVal:
         xtf.writeTag("Kind","ExpressionVal");
         break;
      case ActualArgument::AllOf:
         xtf.writeTag("Kind","AllOf");
         break;
      default:
         Log.error("unsupported ActualArgument.Kind value " + to_string(t->Kind));
         break;
   }
   xtf.writeRole("Expression", get_path(t->Expression));
   xtf.openTag("ObjectClasses");
   for (auto tt : t->ObjectClasses) {
      visit(tt); // ClassRef
   }
   xtf.closeTag();

   xtf.closeObject();

   Log.decNestLevel();
   debug("<<< visitActualArgument()");

}

void ImdOutput::visitFunctionCall(FunctionCall *t)
{

   debug(">>> visitFunctionCall()");
   Log.incNestLevel();

   xtf.openObject("IlisMeta07", "ModelData", "FunctionCall", get_path(t));

   // Expression

   // Factor

   // FunctionCall
   xtf.writeRole("Function", get_path(t->Function));
   xtf.openTag("Arguments");
   for (auto tt : t->Arguments) {
      visit(tt); // ActualArgument
   }
   xtf.closeTag();

   xtf.closeObject();

   Log.decNestLevel();
   debug("<<< visitFunctionCall()");

}

void ImdOutput::visitRuntimeParamRef(RuntimeParamRef *t)
{

   debug(">>> visitRuntimeParamRef()");
   Log.incNestLevel();

   xtf.openObject("IlisMeta07", "ModelData", "RuntimeParamRef", get_path(t));

   // Expression

   // Factor

   // RuntimeParamRef
   xtf.writeRole("RuntimeParam", get_path(t->RuntimeParam));

   xtf.closeObject();

   Log.decNestLevel();
   debug("<<< visitRuntimeParamRef()");

}

void ImdOutput::visitConstant(Constant *t)
{

   debug(">>> visitConstant()");
   Log.incNestLevel();

   xtf.openObject("IlisMeta07", "ModelData", "Constant", get_path(t));

   // Expression

   // Factor

   // Constant
   xtf.writeTag("Value", t->Value);
   switch (t->Kind) {
      case Constant::Undefined:
         xtf.writeTag("Kind","Undefined");
         break;
      case Constant::Numeric:
         xtf.writeTag("Kind","Numeric");
         break;
      case Constant::Text:
         xtf.writeTag("Kind","Text");
         break;
      case Constant::Enumeration:
         xtf.writeTag("Kind","Enumeration");
         break;
      default:
         Log.error("unsupported Constant.Kind value " + to_string(t->Kind));
         break;
   }

   xtf.closeObject();

   Log.decNestLevel();
   debug("<<< visitConstant()");

}

void ImdOutput::visitClassConst(ClassConst *t)
{

   debug(">>> visitClassConst()");
   Log.incNestLevel();

   xtf.openObject("IlisMeta07", "ModelData", "ClassConst", get_path(t));

   // Expression

   // Factor

   // ClassConst
   xtf.writeRole("Class", get_path(t->Class));

   xtf.closeObject();

   Log.decNestLevel();
   debug("<<< visitClassConst()");

}

void ImdOutput::visitAttributeConst(AttributeConst *t)
{

   debug(">>> visitAttributeConst()");
   Log.incNestLevel();

   xtf.openObject("IlisMeta07", "ModelData", "AttributeConst", get_path(t));

   // Expression

   // Factor

   // AttributeConst
   xtf.writeRole("Attribute", get_path(t->Attribute));

   xtf.closeObject();

   Log.decNestLevel();
   debug("<<< visitAttributeConst()");

}

void ImdOutput::visitUnitRef(UnitRef *t)
{

   debug(">>> visitUnitRef()");
   Log.incNestLevel();

   xtf.openObject("IlisMeta07", "ModelData", "UnitRef", get_path(t));

   // Expression

   // Factor

   // UnitRef
   xtf.writeRole("Unit", get_path(t->Unit));

   xtf.closeObject();

   Log.decNestLevel();
   debug("<<< visitUnitRef()");

}

void ImdOutput::visitUnitFunction(UnitFunction *t)
{

   debug(">>> visitUnitFunction()");
   Log.incNestLevel();

   xtf.openObject("IlisMeta07", "ModelData", "UnitFunction", get_path(t));

   // Expression

   // Factor

   // UnitFunction
   xtf.writeTag("Explanation", t->Explanation);

   xtf.closeObject();

   Log.decNestLevel();
   debug("<<< visitUnitFunction()");

}

void ImdOutput::visitSimpleConstraint(SimpleConstraint *t)
{

   debug(">>> visitSimpleConstraint(" + t->Name + ")");
   Log.incNestLevel();

   xtf.openObject("IlisMeta07", "ModelData", "SimpleConstraint", get_path(t));

   // MetaElement
   xtf.writeTag("Name", t->Name);
   xtf.openTag("Documentation");
   for (auto tt : t->Documentation) {
      visit(tt); // DocText
   }
   xtf.closeTag();
   xtf.openTag("MetaAttribute");
   for (auto tt : t->MetaAttribute) {
      visit(tt); // MetaAttribute
   }
   xtf.closeTag();
   xtf.writeRole("ElementInPackage", get_path(t->ElementInPackage));

   // Constraint
   xtf.writeRole("toDomain", get_path(t->toDomain));
   xtf.writeRole("ToClass", get_path(t->ToClass));

   // SimpleConstraint
   switch (t->Kind) {
      case SimpleConstraint::MandC:
         xtf.writeTag("Kind","MandC");
         break;
      case SimpleConstraint::LowPercC:
         xtf.writeTag("Kind","LowPercC");
         break;
      case SimpleConstraint::HighPercC:
         xtf.writeTag("Kind","HighPercC");
         break;
      default:
         Log.error("unsupported SimpleConstraint.Kind value " + to_string(t->Kind));
         break;
   }
   xtf.writeTag("Percentage",to_string(t->Percentage)); // double
   xtf.closeTag();
   xtf.writeRole("LogicalExpression", get_path(t->LogicalExpression));

   xtf.closeObject();

   Log.decNestLevel();
   debug("<<< visitSimpleConstraint(" + t->Name + ")");

}

void ImdOutput::visitExistenceDef(ExistenceDef *t)
{

   debug(">>> visitExistenceDef()");
   Log.incNestLevel();

   xtf.openObject("IlisMeta07", "ModelData", "ExistenceDef", get_path(t));

   // Expression

   // Factor

   // PathOrInspFactor
   xtf.openTag("PathEls");
   for (auto tt : t->PathEls) {
      visit(tt); // PathEl
   }
   xtf.closeTag();
   xtf.writeRole("Inspection", get_path(t->Inspection));

   // ExistenceDef
   xtf.writeRole("Viewable", get_path(t->Viewable));

   xtf.closeObject();

   Log.decNestLevel();
   debug("<<< visitExistenceDef()");

}

void ImdOutput::visitExistenceConstraint(ExistenceConstraint *t)
{

   debug(">>> visitExistenceConstraint(" + t->Name + ")");
   Log.incNestLevel();

   xtf.openObject("IlisMeta07", "ModelData", "ExistenceConstraint", get_path(t));

   // MetaElement
   xtf.writeTag("Name", t->Name);
   xtf.openTag("Documentation");
   for (auto tt : t->Documentation) {
      visit(tt); // DocText
   }
   xtf.closeTag();
   xtf.openTag("MetaAttribute");
   for (auto tt : t->MetaAttribute) {
      visit(tt); // MetaAttribute
   }
   xtf.closeTag();
   xtf.writeRole("ElementInPackage", get_path(t->ElementInPackage));

   // Constraint
   xtf.writeRole("toDomain", get_path(t->toDomain));
   xtf.writeRole("ToClass", get_path(t->ToClass));

   // ExistenceConstraint
   xtf.writeRole("Attr", get_path(t->Attr));
   xtf.openTag("ExistsIn");
   for (auto tt : t->ExistsIn) {
      visit(tt); // ExistenceDef
   }
   xtf.closeTag();

   xtf.closeObject();

   Log.decNestLevel();
   debug("<<< visitExistenceConstraint(" + t->Name + ")");

}

void ImdOutput::visitUniqueConstraint(UniqueConstraint *t)
{

   debug(">>> visitUniqueConstraint(" + t->Name + ")");
   Log.incNestLevel();

   xtf.openObject("IlisMeta07", "ModelData", "UniqueConstraint", get_path(t));

   // MetaElement
   xtf.writeTag("Name", t->Name);
   xtf.openTag("Documentation");
   for (auto tt : t->Documentation) {
      visit(tt); // DocText
   }
   xtf.closeTag();
   xtf.openTag("MetaAttribute");
   for (auto tt : t->MetaAttribute) {
      visit(tt); // MetaAttribute
   }
   xtf.closeTag();
   xtf.writeRole("ElementInPackage", get_path(t->ElementInPackage));

   // Constraint
   xtf.writeRole("toDomain", get_path(t->toDomain));
   xtf.writeRole("ToClass", get_path(t->ToClass));

   // UniqueConstraint
   xtf.openTag("Where");
   for (auto tt : t->Where) {
      visit(tt); // Expression
   }
   xtf.closeTag();
   switch (t->Kind) {
      case UniqueConstraint::GlobalU:
         xtf.writeTag("Kind","GlobalU");
         break;
      case UniqueConstraint::LocalU:
         xtf.writeTag("Kind","LocalU");
         break;
      default:
         Log.error("unsupported UniqueConstraint.Kind value " + to_string(t->Kind));
         break;
   }
   xtf.openTag("UniqueDef");
   for (auto tt : t->UniqueDef) {
      visit(tt); // PathOrInspFactor
   }
   xtf.closeTag();

   xtf.closeObject();

   Log.decNestLevel();
   debug("<<< visitUniqueConstraint(" + t->Name + ")");

}

void ImdOutput::visitSetConstraint(SetConstraint *t)
{

   debug(">>> visitSetConstraint(" + t->Name + ")");
   Log.incNestLevel();

   xtf.openObject("IlisMeta07", "ModelData", "SetConstraint", get_path(t));

   // MetaElement
   xtf.writeTag("Name", t->Name);
   xtf.openTag("Documentation");
   for (auto tt : t->Documentation) {
      visit(tt); // DocText
   }
   xtf.closeTag();
   xtf.openTag("MetaAttribute");
   for (auto tt : t->MetaAttribute) {
      visit(tt); // MetaAttribute
   }
   xtf.closeTag();
   xtf.writeRole("ElementInPackage", get_path(t->ElementInPackage));

   // Constraint
   xtf.writeRole("toDomain", get_path(t->toDomain));
   xtf.writeRole("ToClass", get_path(t->ToClass));

   // SetConstraint
   xtf.openTag("Where");
   for (auto tt : t->Where) {
      visit(tt); // Expression
   }
   xtf.closeTag();
   xtf.writeRole("Constraint", get_path(t->Constraint));

   xtf.closeObject();

   Log.decNestLevel();
   debug("<<< visitSetConstraint(" + t->Name + ")");

}

void ImdOutput::visitGraphic(Graphic *t)
{

   debug(">>> visitGraphic(" + t->Name + ")");
   Log.incNestLevel();

   xtf.openObject("IlisMeta07", "ModelData", "Graphic", get_path(t));

   // MetaElement
   xtf.writeTag("Name", t->Name);
   xtf.openTag("Documentation");
   for (auto tt : t->Documentation) {
      visit(tt); // DocText
   }
   xtf.closeTag();
   xtf.openTag("MetaAttribute");
   for (auto tt : t->MetaAttribute) {
      visit(tt); // MetaAttribute
   }
   xtf.closeTag();
   xtf.writeRole("ElementInPackage", get_path(t->ElementInPackage));

   // ExtendableME
   xtf.writeTag("Abstract", to_string_bool(t->Abstract));
   xtf.writeTag("Generic", to_string_bool(t->Generic));
   xtf.writeTag("Final", to_string_bool(t->Final));
   // xtf.writeRole("Super", get_path(t->Super)); to do !!!
   xtf.openTag("Sub");
   for (auto tt : t->Sub) {
      visit(tt); // ExtendableME
   }
   xtf.closeTag();

   // Graphic
   xtf.writeRole("Where", get_path(t->Where));
   xtf.writeRole("Base", get_path(t->Base));
   xtf.openTag("DrawingRule");
   for (auto tt : t->DrawingRule) {
      visit(tt); // DrawingRule
   }
   xtf.closeTag();

   xtf.closeObject();

   Log.decNestLevel();
   debug("<<< visitGraphic(" + t->Name + ")");

}

void ImdOutput::visitSignParamAssignment(SignParamAssignment *t)
{

   debug(">>> visitSignParamAssignment()");
   Log.incNestLevel();

   xtf.openObject("IlisMeta07", "ModelData", "SignParamAssignment", get_path(t));

   // SignParamAssignment
   xtf.writeRole("Param", get_path(t->Param));
   xtf.writeRole("Assignment", get_path(t->Assignment));

   xtf.closeObject();

   Log.decNestLevel();
   debug("<<< visitSignParamAssignment()");

}

void ImdOutput::visitCondSignParamAssignment(CondSignParamAssignment *t)
{

   debug(">>> visitCondSignParamAssignment()");
   Log.incNestLevel();

   xtf.openObject("IlisMeta07", "ModelData", "CondSignParamAssignment", get_path(t));

   // CondSignParamAssignment
   xtf.writeRole("Where", get_path(t->Where));
   xtf.openTag("Assignments");
   for (auto tt : t->Assignments) {
      visit(tt); // SignParamAssignment
   }
   xtf.closeTag();

   xtf.closeObject();

   Log.decNestLevel();
   debug("<<< visitCondSignParamAssignment()");

}

void ImdOutput::visitDrawingRule(DrawingRule *t)
{

   debug(">>> visitDrawingRule(" + t->Name + ")");
   Log.incNestLevel();

   xtf.openObject("IlisMeta07", "ModelData", "DrawingRule", get_path(t));

   // MetaElement
   xtf.writeTag("Name", t->Name);
   xtf.openTag("Documentation");
   for (auto tt : t->Documentation) {
      visit(tt); // DocText
   }
   xtf.closeTag();
   xtf.openTag("MetaAttribute");
   for (auto tt : t->MetaAttribute) {
      visit(tt); // MetaAttribute
   }
   xtf.closeTag();
   xtf.writeRole("ElementInPackage", get_path(t->ElementInPackage));

   // ExtendableME
   xtf.writeTag("Abstract", to_string_bool(t->Abstract));
   xtf.writeTag("Generic", to_string_bool(t->Generic));
   xtf.writeTag("Final", to_string_bool(t->Final));
   // xtf.writeRole("Super", get_path(t->Super)); to do !!!
   xtf.openTag("Sub");
   for (auto tt : t->Sub) {
      visit(tt); // ExtendableME
   }
   xtf.closeTag();

   // DrawingRule
   xtf.openTag("Rule");
   for (auto tt : t->Rule) {
      visit(tt); // CondSignParamAssignment
   }
   xtf.closeTag();
   xtf.writeRole("Graphic", get_path(t->Graphic));
   xtf.writeRole("Class", get_path(t->Class));

   xtf.closeObject();

   Log.decNestLevel();
   debug("<<< visitDrawingRule(" + t->Name + ")");

}

void ImdOutput::visitDocTextTranslation(DocTextTranslation *t)
{

   debug(">>> visitDocTextTranslation()");
   Log.incNestLevel();

   xtf.openObject("IlisMeta07", "ModelData", "DocTextTranslation", get_path(t));

   // DocTextTranslation
   xtf.writeTag("Text", t->Text);

   xtf.closeObject();

   Log.decNestLevel();
   debug("<<< visitDocTextTranslation()");

}

void ImdOutput::visitMETranslation(METranslation *t)
{

   debug(">>> visitMETranslation()");
   Log.incNestLevel();

   xtf.openObject("IlisMeta07", "ModelData", "METranslation", get_path(t));

   // METranslation
   xtf.writeRole("Of", get_path(t->Of));
   xtf.writeTag("TranslatedName", t->TranslatedName);
   xtf.openTag("TranslatedDoc");
   for (auto tt : t->TranslatedDoc) {
      visit(tt); // DocTextTranslation
   }
   xtf.closeTag();

   xtf.closeObject();

   Log.decNestLevel();
   debug("<<< visitMETranslation()");

}

void ImdOutput::visitTranslation(Translation *t)
{

   debug(">>> visitTranslation()");
   Log.incNestLevel();

   xtf.openObject("IlisMeta07", "ModelData", "Translation", get_path(t));

   // Translation
   xtf.writeTag("Language", t->Language);
   xtf.openTag("Translations");
   for (auto tt : t->Translations) {
      visit(tt); // METranslation
   }
   xtf.closeTag();

   xtf.closeObject();

   Log.decNestLevel();
   debug("<<< visitTranslation()");

}
