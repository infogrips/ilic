#pragma once

#include "../util/TextWriter.h"
#include "../metamodel/MetaModelTreeVisitor.h"

namespace output {
   
   class XsdOutput : public metamodel::MetaModelTreeVisitor {
   public:

      XsdOutput(string ilifile,string iliversion,string ilic_version);

      void preVisit(void) override;
      void postVisit(void) override;
   
      void preVisitModel(metamodel::Model* m) override;
      void visitModel(metamodel::Model *m) override {};
      void postVisitModel(metamodel::Model *m) override {};

      void visitImport(metamodel::Import *i) override {};

      void visitUnit(metamodel::Unit *u) override {};

      void visitNumType(metamodel::NumType *t) override {};
      void visitTextType(metamodel::TextType *t) override {};
      void visitFormattedType(metamodel::FormattedType *t) override {};
      void visitEnumType(metamodel::EnumType *t) override {};
      void visitCoordType(metamodel::CoordType *t) override {};
      void visitLineType(metamodel::LineType *t) override {};
      void visitLineForm(metamodel::LineForm *l) override {};
 
      void visitFunctionDef(metamodel::FunctionDef *f) override {};

      void preVisitSubModel(metamodel::SubModel *s) override {};
      void visitSubModel(metamodel::SubModel *s) override {};
      void postVisitSubModel(metamodel::SubModel *s) override;
      
      void preVisitClass(metamodel::Class *c) override;
      void visitClass(metamodel::Class *c) override {};
      void postVisitClass(metamodel::Class *c) override;

      void visitDocText(metamodel::DocText *t) override {};
      void visitMetaAttribute(metamodel::MetaAttribute *a) override {};
      void visitMetaElement(metamodel::MetaElement *e) override {};
      void visitExtendableME(metamodel::ExtendableME *e) override {};
      void visitPackage(metamodel::Package *p) override {};
      void visitIli1Format(metamodel::Ili1Format *f) override {};
      void visitExpression(metamodel::Expression *e) override {};
      void visitMultiplicity(metamodel::Multiplicity *m) override {};
      void visitConstraint(metamodel::Constraint *c) override {};
      void visitDomainType(metamodel::DomainType *d) override;
      void visitType(metamodel::Type *t) override {};
      void visitAttrOrParam(metamodel::AttrOrParam *a) override;
      void visitTypeRelatedType(metamodel::TypeRelatedType *r) override {};
      void visitTypeRestriction(metamodel::TypeRestriction *r) override {};
      void visitMultiValue(metamodel::MultiValue* m) override {};
      void visitClassRelatedType(metamodel::ClassRelatedType *t) override {};
      void visitBaseClass(metamodel::BaseClass *b) override {};
      void visitClassRestriction(metamodel::ClassRestriction *r) override {};
      void visitReferenceType(metamodel::ReferenceType *r) override {};
      void visitRole(metamodel::Role *r) override;
      void visitExplicitAssocAccess(metamodel::ExplicitAssocAccess *a) override {};
      void visitAssocAcc(metamodel::AssocAcc *a) override {};
      void visitTransferElement(metamodel::TransferElement *t) override {};
      void visitIli1TransferElement(metamodel::Ili1TransferElement *t) override {};
      void visitDataUnit(metamodel::DataUnit *d) override {}
      void visitAllowedInBasket(metamodel::AllowedInBasket *b) override {};
      void visitMetaBasketDef(metamodel::MetaBasketDef *m) override {};
      void visitMetaObjectDef(metamodel::MetaObjectDef *o) override {};
      void visitBooleanType(metamodel::BooleanType *t) override {};
      void visitBlackboxType(metamodel::BlackboxType *t) override {};
      void visitAxisSpec(metamodel::AxisSpec *a) override {};
      void visitNumsRefSys(metamodel::NumsRefSys *s) override {};
      void visitAnyOIDType(metamodel::AnyOIDType *t) override {};
      void visitArgument(metamodel::Argument *a) override {};
      void visitObjectType(metamodel::ObjectType *t) override {};
      void visitAttributeRefType(metamodel::AttributeRefType *r) override {};
      void visitARefRestriction(metamodel::ARefRestriction *r) override {};
      void visitEnumNode(metamodel::EnumNode *n) override {};
      void visitEnumTreeValueType(metamodel::EnumTreeValueType *t) override {};
      
      void visitLinesForm(metamodel::LinesForm *f) override {};
      void visitView(metamodel::View *v) override {};
      void visitRenamedBaseView(metamodel::RenamedBaseView *v) override {};
      void visitUnaryExpr(metamodel::UnaryExpr *e) override {};
      void visitCompoundExpr(metamodel::CompoundExpr *e) override {};
      void visitFactor(metamodel::Factor *f) override {};
      void visitPathEl(metamodel::PathEl *e) override {};
      void visitPathOrInspFactor(metamodel::PathOrInspFactor *f) override {};
      void visitEnumAssignment(metamodel::EnumAssignment *a) override {};
      void visitEnumMapping(metamodel::EnumMapping *m) override {};
      void visitClassRef(metamodel::ClassRef *r) override {};
      void visitActualArgument(metamodel::ActualArgument *a) override {};
      void visitFunctionCall(metamodel::FunctionCall *f) override {};
      void visitRuntimeParamRef(metamodel::RuntimeParamRef *r) override {};
      void visitConstant(metamodel::Constant *c) override {};
      void visitClassConst(metamodel::ClassConst *c) override {};
      void visitAttributeConst(metamodel::AttributeConst *c) override {};
      void visitUnitRef(metamodel::UnitRef *u) override {};
      void visitUnitFunction(metamodel::UnitFunction *f) override {};
      void visitSimpleConstraint(metamodel::SimpleConstraint *c) override {};
      void visitExistenceDef(metamodel::ExistenceDef *e) override {};
      void visitExistenceConstraint(metamodel::ExistenceConstraint *c) override {};
      void visitUniqueConstraint(metamodel::UniqueConstraint *u) override {};
      void visitSetConstraint(metamodel::SetConstraint *c) override {};
      void visitGraphic(metamodel::Graphic *g) override {};
      void visitSignParamAssignment(metamodel::SignParamAssignment *a) override {};
      void visitCondSignParamAssignment(metamodel::CondSignParamAssignment *a) override {};
      void visitDrawingRule(metamodel::DrawingRule *d) override {};
      void visitDocTextTranslation(metamodel::DocTextTranslation *t) override {};
      void visitMETranslation(metamodel::METranslation *t) override {};
      void visitTranslation(metamodel::Translation *t) override {};

      void writeAnnotations();
      void writeFixTypes1();
      void writeAliasTables();
      void writeFixTypes2();
      void writeDatasection();

      void writeInterlisReferenceTypes();
      void writeHeadersection();

      void writeType(metamodel::DomainType *t);
      void write_texttype(metamodel::TextType *t);
      void write_coordtype(metamodel::CoordType *t);
      void write_enumtype(metamodel::EnumType *t);
      void write_numtype(metamodel::NumType *t);
      void write_linetype(metamodel::LineType *t);
      void write_formattedtype(metamodel::FormattedType *t);
      void write_blackboxtype(metamodel::BlackboxType *t);
      void write_referencetype(metamodel::ReferenceType *t);
      void write_multivalue(metamodel::MultiValue* t);

      void buildEnum(list<string> *list, string prefix, metamodel::EnumNode *enumNode);

      string getShortName() override { return "xsd"; };

// create visit...Override() methods
#undef MMV_VISITOR
#define MMV_VISITOR XsdOutput
#include "../metamodel/MetaModelTreeVisitor.inc"

   private:
      string iliversion;
      string ilic_version;
      string xsd_file;
      util::TextWriter xsd;
   };

};
