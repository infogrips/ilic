#pragma once

#include "../util/TextWriter.h"
#include "../metamodel/MetaModelTreeVisitor.h"

namespace output {
   
   class Ili2Output : public metamodel::MetaModelTreeVisitor {
   public:

      Ili2Output(string ilifile,string model_version);

      void preVisit() override;
      void postVisit() override;
   
      void preVisitModel(metamodel::Model* m) override;
      void visitModel(metamodel::Model* m) override;
      void postVisitModel(metamodel::Model *m) override;

      void visitImport(metamodel::Import *i) override;

      void preVisitSubModel(metamodel::SubModel *s) override;
      void postVisitSubModel(metamodel::SubModel *s) override;

      void preVisitClass(metamodel::Class *c) override;
      void postVisitClass(metamodel::Class *c) override;

      void visitDomainType(metamodel::DomainType *t) override;

      void visitAttrOrParam(metamodel::AttrOrParam *a) override;
      void visitRole(metamodel::Role* r) override;

      void visitUnit(metamodel::Unit* u) override;

      string getShortName() override { return "ili2"; };

// create visit...Override() methods
#undef MMV_VISITOR
#define MMV_VISITOR Ili2Output
#include "../metamodel/MetaModelTreeVisitor.inc"

   private:
      util::TextWriter ili2;
      string ili_file;
      string model_version;
   };

};
