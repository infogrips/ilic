#include "MetaModel.h"
#include "InterlisModel.h"
#include "../util/Logger.h"

using namespace util;

namespace metamodel {

   // global variables

   Model *INTERLIS;

   static list <Model *> AllModels;
   static list <Import *> AllImports;
   
   // helper functions

   void init(string version)
   {
      INTERLIS = new InterlisModel(version);
   }
   
   // model helpers
   
   list <Model *> get_all_models()
   {
      return AllModels;
   }

   list <Import *> get_all_imports()
   {
      return AllImports;
   }
   
   // path utilities

   string get_path(MMObject *o)
   {

      if (o == nullptr) {
         return "nullptr";
      }
      else if (!dynamic_cast<MetaElement *>(o)) {
         return "unknown";
      }

      MetaElement *e = dynamic_cast<MetaElement *>(o);
      string path = "";

      while (e != nullptr) {
         if (path == "") {
            path = e->Name;
         }
         else {
            path = e->Name + "." + path;
         }
         e = e->ElementInPackage;
      }

      return path;

   }

   string get_parent_path(MetaElement *e)
   {
      if (e == nullptr) {
         return "nullptr";
      }
      return get_path(e->ElementInPackage);
   }

   // instance methods
   
   static MMObject *get_instance(string classname)
   {
      if (classname == "Model") {
         return new Model();
      }
      else if (classname == "MMObject") {
         return new MMObject();
      }
      else if (classname == "DocText") {
         return new DocText();
      }
      else if (classname == "MetaAttribute") {
         return new MetaAttribute();
      }
      else if (classname == "MetaElement") {
         return new MetaElement();
      }
      else if (classname == "ExtendableME") {
         return new ExtendableME();
      }
      else if (classname == "Package") {
         return new Package();
      }
      else if (classname == "Import") {
         return new Import();
      }
      else if (classname == "Ili1Format") {
         return new Ili1Format();
      }
      else if (classname == "Model") {
         return new Model();
      }
      else if (classname == "SubModel") {
         return new SubModel();
      }
      else if (classname == "Type") {
         return new Type();
      }
      else if (classname == "Multiplicity") {
         return new Multiplicity();
      }
      else if (classname == "Constraint") {
         return new Constraint();
      }
      else if (classname == "DomainType") {
         return new DomainType();
      }
      else if (classname == "Class") {
         return new Class();
      }
      else if (classname == "AttrOrParam") {
         return new AttrOrParam();
      }
      else if (classname == "TypeRelatedType") {
         return new TypeRelatedType();
      }
      else if (classname == "TypeRestriction") {
         return new TypeRestriction();
      }
      else if (classname == "MultiValue") {
         return new MultiValue();
      }
      else if (classname == "ClassRelatedType") {
         return new ClassRelatedType();
      }
      else if (classname == "BaseClass") {
         return new BaseClass();
      }
      else if (classname == "ClassRestriction") {
         return new ClassRestriction();
      }
      else if (classname == "ReferenceType") {
         return new ReferenceType();
      }
      else if (classname == "Role") {
         return new Role();
      }
      else if (classname == "ExplicitAssocAccess") {
         return new ExplicitAssocAccess();
      }
      else if (classname == "AssocAcc") {
         return new AssocAcc();
      }
      else if (classname == "TransferElement") {
         return new TransferElement();
      }
      else if (classname == "Ili1TransferElement") {
         return new Ili1TransferElement();
      }
      else if (classname == "DataUnit") {
         return new DataUnit();
      }
      else if (classname == "Dependency") {
         return new Dependency();
      }
      else if (classname == "AllowedInBasket") {
         return new AllowedInBasket();
      }
      else if (classname == "Context") {
         return new Context();
      }
      else if (classname == "GenericDef") {
         return new GenericDef();
      }
      else if (classname == "Unit") {
         return new Unit();
      }
      else if (classname == "MetaBasketDef") {
         return new MetaBasketDef();
      }
      else if (classname == "MetaObjectDef") {
         return new MetaObjectDef();
      }
      else if (classname == "BooleanType") {
         return new BooleanType();
      }
      else if (classname == "TextType") {
         return new TextType();
      }
      else if (classname == "BlackboxType") {
         return new BlackboxType();
      }
      else if (classname == "NumType") {
         return new NumType();
      }
      else if (classname == "CoordType") {
         return new CoordType();
      }
      else if (classname == "AxisSpec") {
         return new AxisSpec();
      }
      else if (classname == "NumsRefSys") {
         return new NumsRefSys();
      }
      else if (classname == "FormattedType") {
         return new FormattedType();
      }
      else if (classname == "AnyOIDType") {
         return new AnyOIDType();
      }
      else if (classname == "FunctionDef") {
         return new FunctionDef();
      }
      else if (classname == "Argument") {
         return new Argument();
      }
      else if (classname == "ClassRefType") {
         return new ClassRefType();
      }
      else if (classname == "ObjectType") {
         return new ObjectType();
      }
      else if (classname == "AttributeRefType") {
         return new AttributeRefType();
      }
      else if (classname == "ARefRestriction") {
         return new ARefRestriction();
      }
      else if (classname == "EnumType") {
         return new EnumType();
      }
      else if (classname == "EnumNode") {
         return new EnumNode();
      }
      else if (classname == "EnumTreeValueType") {
         return new EnumTreeValueType();
      }
      else if (classname == "LineForm") {
         return new LineForm();
      }
      else if (classname == "LineType") {
         return new LineType();
      }
      else if (classname == "LinesForm") {
         return new LinesForm();
      }
      else if (classname == "View") {
         return new View();
      }
      else if (classname == "Expression") {
         return new Expression();
      }
      else if (classname == "UnaryExpr") {
         return new UnaryExpr();
      }
      else if (classname == "CompoundExpr") {
         return new CompoundExpr();
      }
      else if (classname == "Factor") {
         return new Factor();
      }
      else if (classname == "PathEl") {
         return new PathEl();
      }
      else if (classname == "PathOrInspFactor") {
         return new PathOrInspFactor();
      }
      else if (classname == "EnumAssignment") {
         return new EnumAssignment();
      }
      else if (classname == "EnumMapping") {
         return new EnumMapping();
      }
      else if (classname == "ClassRef") {
         return new ClassRef();
      }
      else if (classname == "ActualArgument") {
         return new ActualArgument();
      }
      else if (classname == "FunctionCall") {
         return new FunctionCall();
      }
      else if (classname == "RuntimeParamRef") {
         return new RuntimeParamRef();
      }
      else if (classname == "Constant") {
         return new Constant();
      }
      else if (classname == "ClassConst") {
         return new ClassConst();
      }
      else if (classname == "AttributeConst") {
         return new AttributeConst();
      }
      else if (classname == "UnitRef") {
         return new UnitRef();
      }
      else if (classname == "UnitFunction") {
         return new UnitFunction();
      }
      else if (classname == "Constraint") {
         return new Constraint();
      }
      else if (classname == "SimpleConstraint") {
         return new SimpleConstraint();
      }
      else if (classname == "ExistenceDef") {
         return new ExistenceDef();
      }
      else if (classname == "ExistenceConstraint") {
         return new ExistenceConstraint();
      }
      else if (classname == "UniqueConstraint") {
         return new UniqueConstraint();
      }
      else if (classname == "SetConstraint") {
         return new SetConstraint();
      }
      else if (classname == "Graphic") {
         return new Graphic();
      }
      else if (classname == "SignParamAssignment") {
         return new SignParamAssignment();
      }
      else if (classname == "CondSignParamAssignment") {
         return new CondSignParamAssignment();
      }
      else if (classname == "DrawingRule") {
         return new DrawingRule();
      }
      else if (classname == "DocTextTranslation") {
         return new DocTextTranslation();
      }
      else if (classname == "METranslation") {
         return new METranslation();
      }
      else if (classname == "Translation") {
         return new Translation();
      }
      else {
         return nullptr;
      }

   }

   bool MMObject::isInstanceOf(string classname)
   {

      MMObject *o = this;

      while (true) {
         if (o->getClass() == classname) {
            break;
         }
         else if (o->getBaseClass() == classname) {
            break;
         }
         else {
            string basename = o->getBaseClass();
            if (o != this) {
               delete o;
            }
            o = get_instance(basename);
            if (o == nullptr) {
               break;
            }
         }
      }

      if (o == nullptr) {
         return false;
      }
      else {
         if (o != this) {
            delete o;
         }
         return true;
      }

   }
   
}
