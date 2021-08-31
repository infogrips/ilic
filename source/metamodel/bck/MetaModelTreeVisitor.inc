virtual bool preVisitOverride() {return typeid(&MetaModelTreeVisitor::preVisit) != typeid(&MMV_VISITOR::preVisit);};
virtual bool postVisitOverride() {return typeid(&MetaModelTreeVisitor::postVisit) != typeid(&MMV_VISITOR::postVisit);};
   
virtual bool preVisitModelOverride() {return typeid(&MetaModelTreeVisitor::preVisitModel) != typeid(&MMV_VISITOR::preVisitModel);};
virtual bool visitModelOverride() {return typeid(&MetaModelTreeVisitor::visitModel) != typeid(&MMV_VISITOR::visitModel);};
virtual bool postVisitModelOverride() {return typeid(&MetaModelTreeVisitor::postVisitModel) != typeid(&MMV_VISITOR::postVisitModel);};

virtual bool visitImportOverride() {return typeid(&MetaModelTreeVisitor::visitImport) != typeid(&MMV_VISITOR::visitImport);};

virtual bool visitUnitOverride() {return typeid(&MetaModelTreeVisitor::visitUnit) != typeid(&MMV_VISITOR::visitUnit);};

virtual bool visitMMObjectOverride() {return typeid(&MetaModelTreeVisitor::visitMMObject) != typeid(&MMV_VISITOR::visitMMObject);};

virtual bool visitNumTypeOverride() {return typeid(&MetaModelTreeVisitor::visitNumType) != typeid(&MMV_VISITOR::visitNumType);};
virtual bool visitTextTypeOverride() {return typeid(&MetaModelTreeVisitor::visitTextType) != typeid(&MMV_VISITOR::visitTextType);};
virtual bool visitFormattedTypeOverride() {return typeid(&MetaModelTreeVisitor::visitFormattedType) != typeid(&MMV_VISITOR::visitFormattedType);};
virtual bool visitEnumTypeOverride() {return typeid(&MetaModelTreeVisitor::visitEnumType) != typeid(&MMV_VISITOR::visitEnumType);};
virtual bool visitCoordTypeOverride() {return typeid(&MetaModelTreeVisitor::visitCoordType) != typeid(&MMV_VISITOR::visitCoordType);};
virtual bool visitLineFormOverride() {return typeid(&MetaModelTreeVisitor::visitLineForm) != typeid(&MMV_VISITOR::visitLineForm);};
 
virtual bool visitFunctionDefOverride() {return typeid(&MetaModelTreeVisitor::visitFunctionDef) != typeid(&MMV_VISITOR::visitFunctionDef);};

virtual bool preVisitSubModelOverride() {return typeid(&MetaModelTreeVisitor::preVisitSubModel) != typeid(&MMV_VISITOR::preVisitSubModel);};
virtual bool visitSubModelOverride() {return typeid(&MetaModelTreeVisitor::visitSubModel) != typeid(&MMV_VISITOR::visitSubModel);};
virtual bool postVisitSubModelOverride() {return typeid(&MetaModelTreeVisitor::postVisitSubModel) != typeid(&MMV_VISITOR::postVisitSubModel);};
      
virtual bool preVisitClassOverride() {return typeid(&MetaModelTreeVisitor::preVisitClass) != typeid(&MMV_VISITOR::preVisitClass);};
virtual bool visitClassOverride() {return typeid(&MetaModelTreeVisitor::visitClass) != typeid(&MMV_VISITOR::visitClass);};
virtual bool postVisitClassOverride() {return typeid(&MetaModelTreeVisitor::postVisitClass) != typeid(&MMV_VISITOR::postVisitClass);};

virtual bool visitAttrOrParamOverride() {return typeid(&MetaModelTreeVisitor::visitAttrOrParam) != typeid(&MMV_VISITOR::visitAttrOrParam);};

virtual bool visitDocTextOverride() {return typeid(&MetaModelTreeVisitor::visitDocText) != typeid(&MMV_VISITOR::visitDocText);};
virtual bool visitMetaAttributeOverride() {return typeid(&MetaModelTreeVisitor::visitMetaAttribute) != typeid(&MMV_VISITOR::visitMetaAttribute);};
virtual bool visitMetaElementOverride() {return typeid(&MetaModelTreeVisitor::visitMetaElement) != typeid(&MMV_VISITOR::visitMetaElement);};
virtual bool visitExtendableMEOverride() {return typeid(&MetaModelTreeVisitor::visitExtendableME) != typeid(&MMV_VISITOR::visitExtendableME);};
virtual bool visitPackageOverride() {return typeid(&MetaModelTreeVisitor::visitPackage) != typeid(&MMV_VISITOR::visitPackage);};
virtual bool visitIli1FormatOverride() {return typeid(&MetaModelTreeVisitor::visitIli1Format) != typeid(&MMV_VISITOR::visitIli1Format);};
virtual bool visitExpressionOverride() {return typeid(&MetaModelTreeVisitor::visitExpression) != typeid(&MMV_VISITOR::visitExpression);};
virtual bool visitMultiplicityOverride() {return typeid(&MetaModelTreeVisitor::visitMultiplicity) != typeid(&MMV_VISITOR::visitMultiplicity);};
virtual bool visitConstraintOverride() {return typeid(&MetaModelTreeVisitor::visitConstraint) != typeid(&MMV_VISITOR::visitConstraint);};
virtual bool visitDomainTypeOverride() {return typeid(&MetaModelTreeVisitor::visitDomainType) != typeid(&MMV_VISITOR::visitDomainType);};
virtual bool visitTypeOverride() {return typeid(&MetaModelTreeVisitor::visitType) != typeid(&MMV_VISITOR::visitType);};
virtual bool visitTypeRelatedTypeOverride() {return typeid(&MetaModelTreeVisitor::visitTypeRelatedType) != typeid(&MMV_VISITOR::visitTypeRelatedType);};
virtual bool visitTypeRestrictionOverride() {return typeid(&MetaModelTreeVisitor::visitTypeRestriction) != typeid(&MMV_VISITOR::visitTypeRestriction);};
virtual bool visitMultiValueOverride() {return typeid(&MetaModelTreeVisitor::visitMultiValue) != typeid(&MMV_VISITOR::visitMultiValue);};
virtual bool visitClassRelatedTypeOverride() {return typeid(&MetaModelTreeVisitor::visitClassRelatedType) != typeid(&MMV_VISITOR::visitClassRelatedType);};
virtual bool visitBaseClassOverride() {return typeid(&MetaModelTreeVisitor::visitBaseClass) != typeid(&MMV_VISITOR::visitBaseClass);};
virtual bool visitClassRestrictionOverride() {return typeid(&MetaModelTreeVisitor::visitClassRestriction) != typeid(&MMV_VISITOR::visitClassRestriction);};
virtual bool visitReferenceTypeOverride() {return typeid(&MetaModelTreeVisitor::visitReferenceType) != typeid(&MMV_VISITOR::visitReferenceType);};
virtual bool visitRoleOverride() {return typeid(&MetaModelTreeVisitor::visitRole) != typeid(&MMV_VISITOR::visitRole);};
virtual bool visitExplicitAssocAccessOverride() {return typeid(&MetaModelTreeVisitor::visitExplicitAssocAccess) != typeid(&MMV_VISITOR::visitExplicitAssocAccess);};
virtual bool visitAssocAccOverride() {return typeid(&MetaModelTreeVisitor::visitAssocAcc) != typeid(&MMV_VISITOR::visitAssocAcc);};
virtual bool visitTransferElementOverride() {return typeid(&MetaModelTreeVisitor::visitTransferElement) != typeid(&MMV_VISITOR::visitTransferElement);};
virtual bool visitIli1TransferElementOverride() {return typeid(&MetaModelTreeVisitor::visitIli1TransferElement) != typeid(&MMV_VISITOR::visitIli1TransferElement);};
virtual bool visitDataUnitOverride() {return typeid(&MetaModelTreeVisitor::visitDataUnit) != typeid(&MMV_VISITOR::visitDataUnit);};
virtual bool visitAllowedInBasketOverride() {return typeid(&MetaModelTreeVisitor::visitAllowedInBasket) != typeid(&MMV_VISITOR::visitAllowedInBasket);};
virtual bool visitMetaBasketDefOverride() {return typeid(&MetaModelTreeVisitor::visitMetaBasketDef) != typeid(&MMV_VISITOR::visitMetaBasketDef);};
virtual bool visitMetaObjectDefOverride() {return typeid(&MetaModelTreeVisitor::visitMetaObjectDef) != typeid(&MMV_VISITOR::visitMetaObjectDef);};
virtual bool visitBooleanTypeOverride() {return typeid(&MetaModelTreeVisitor::visitBooleanType) != typeid(&MMV_VISITOR::visitBooleanType);};
virtual bool visitBlackboxTypeOverride() {return typeid(&MetaModelTreeVisitor::visitBlackboxType) != typeid(&MMV_VISITOR::visitBlackboxType);};
virtual bool visitAxisSpecOverride() {return typeid(&MetaModelTreeVisitor::visitAxisSpec) != typeid(&MMV_VISITOR::visitAxisSpec);};
virtual bool visitNumsRefSysOverride() {return typeid(&MetaModelTreeVisitor::visitNumsRefSys) != typeid(&MMV_VISITOR::visitNumsRefSys);};
virtual bool visitAnyOIDTypeOverride() {return typeid(&MetaModelTreeVisitor::visitAnyOIDType) != typeid(&MMV_VISITOR::visitAnyOIDType);};
virtual bool visitArgumentOverride() {return typeid(&MetaModelTreeVisitor::visitArgument) != typeid(&MMV_VISITOR::visitArgument);};
virtual bool visitClassRefTypeOverride() {return typeid(&MetaModelTreeVisitor::visitClassRefType) != typeid(&MMV_VISITOR::visitClassRefType);};
virtual bool visitObjectTypeOverride() {return typeid(&MetaModelTreeVisitor::visitObjectType) != typeid(&MMV_VISITOR::visitObjectType);};
virtual bool visitAttributeRefTypeOverride() {return typeid(&MetaModelTreeVisitor::visitAttributeRefType) != typeid(&MMV_VISITOR::visitAttributeRefType);};
virtual bool visitARefRestrictionOverride() {return typeid(&MetaModelTreeVisitor::visitARefRestriction) != typeid(&MMV_VISITOR::visitARefRestriction);};
virtual bool visitEnumNodeOverride() {return typeid(&MetaModelTreeVisitor::visitEnumNode) != typeid(&MMV_VISITOR::visitEnumNode);};
virtual bool visitEnumTreeValueTypeOverride() {return typeid(&MetaModelTreeVisitor::visitEnumTreeValueType) != typeid(&MMV_VISITOR::visitEnumTreeValueType);};
virtual bool visitLineTypeOverride() {return typeid(&MetaModelTreeVisitor::visitLineType) != typeid(&MMV_VISITOR::visitLineType);};
virtual bool visitLinesFormOverride() {return typeid(&MetaModelTreeVisitor::visitLinesForm) != typeid(&MMV_VISITOR::visitLinesForm);};
virtual bool visitViewOverride() {return typeid(&MetaModelTreeVisitor::visitView) != typeid(&MMV_VISITOR::visitView);};
virtual bool visitRenamedBaseViewOverride() {return typeid(&MetaModelTreeVisitor::visitRenamedBaseView) != typeid(&MMV_VISITOR::visitRenamedBaseView);};
virtual bool visitUnaryExprOverride() {return typeid(&MetaModelTreeVisitor::visitUnaryExpr) != typeid(&MMV_VISITOR::visitUnaryExpr);};
virtual bool visitCompoundExprOverride() {return typeid(&MetaModelTreeVisitor::visitCompoundExpr) != typeid(&MMV_VISITOR::visitCompoundExpr);};
virtual bool visitFactorOverride() {return typeid(&MetaModelTreeVisitor::visitFactor) != typeid(&MMV_VISITOR::visitFactor);};
virtual bool visitPathElOverride() {return typeid(&MetaModelTreeVisitor::visitPathEl) != typeid(&MMV_VISITOR::visitPathEl);};
virtual bool visitPathOrInspFactorOverride() {return typeid(&MetaModelTreeVisitor::visitPathOrInspFactor) != typeid(&MMV_VISITOR::visitPathOrInspFactor);};
virtual bool visitEnumAssignmentOverride() {return typeid(&MetaModelTreeVisitor::visitEnumAssignment) != typeid(&MMV_VISITOR::visitEnumAssignment);};
virtual bool visitEnumMappingOverride() {return typeid(&MetaModelTreeVisitor::visitEnumMapping) != typeid(&MMV_VISITOR::visitEnumMapping);};
virtual bool visitClassRefOverride() {return typeid(&MetaModelTreeVisitor::visitClassRef) != typeid(&MMV_VISITOR::visitClassRef);};
virtual bool visitActualArgumentOverride() {return typeid(&MetaModelTreeVisitor::visitActualArgument) != typeid(&MMV_VISITOR::visitActualArgument);};
virtual bool visitFunctionCallOverride() {return typeid(&MetaModelTreeVisitor::visitFunctionCall) != typeid(&MMV_VISITOR::visitFunctionCall);};
virtual bool visitRuntimeParamRefOverride() {return typeid(&MetaModelTreeVisitor::visitRuntimeParamRef) != typeid(&MMV_VISITOR::visitRuntimeParamRef);};
virtual bool visitConstantOverride() {return typeid(&MetaModelTreeVisitor::visitConstant) != typeid(&MMV_VISITOR::visitConstant);};
virtual bool visitClassConstOverride() {return typeid(&MetaModelTreeVisitor::visitClassConst) != typeid(&MMV_VISITOR::visitClassConst);};
virtual bool visitAttributeConstOverride() {return typeid(&MetaModelTreeVisitor::visitAttributeConst) != typeid(&MMV_VISITOR::visitAttributeConst);};
virtual bool visitUnitRefOverride() {return typeid(&MetaModelTreeVisitor::visitUnitRef) != typeid(&MMV_VISITOR::visitUnitRef);};
virtual bool visitUnitFunctionOverride() {return typeid(&MetaModelTreeVisitor::visitUnitFunction) != typeid(&MMV_VISITOR::visitUnitFunction);};
virtual bool visitSimpleConstraintOverride() {return typeid(&MetaModelTreeVisitor::visitSimpleConstraint) != typeid(&MMV_VISITOR::visitSimpleConstraint);};
virtual bool visitExistenceDefOverride() {return typeid(&MetaModelTreeVisitor::visitExistenceDef) != typeid(&MMV_VISITOR::visitExistenceDef);};
virtual bool visitExistenceConstraintOverride() {return typeid(&MetaModelTreeVisitor::visitExistenceConstraint) != typeid(&MMV_VISITOR::visitExistenceConstraint);};
virtual bool visitUniqueConstraintOverride() {return typeid(&MetaModelTreeVisitor::visitUniqueConstraint) != typeid(&MMV_VISITOR::visitUniqueConstraint);};
virtual bool visitSetConstraintOverride() {return typeid(&MetaModelTreeVisitor::visitSetConstraint) != typeid(&MMV_VISITOR::visitSetConstraint);};
virtual bool visitGraphicOverride() {return typeid(&MetaModelTreeVisitor::visitGraphic) != typeid(&MMV_VISITOR::visitGraphic);};
virtual bool visitSignParamAssignmentOverride() {return typeid(&MetaModelTreeVisitor::visitSignParamAssignment) != typeid(&MMV_VISITOR::visitSignParamAssignment);};
virtual bool visitCondSignParamAssignmentOverride() {return typeid(&MetaModelTreeVisitor::visitCondSignParamAssignment) != typeid(&MMV_VISITOR::visitCondSignParamAssignment);};
virtual bool visitDrawingRuleOverride() {return typeid(&MetaModelTreeVisitor::visitDrawingRule) != typeid(&MMV_VISITOR::visitDrawingRule);};
virtual bool visitDocTextTranslationOverride() {return typeid(&MetaModelTreeVisitor::visitDocTextTranslation) != typeid(&MMV_VISITOR::visitDocTextTranslation);};
virtual bool visitMETranslationOverride() {return typeid(&MetaModelTreeVisitor::visitMETranslation) != typeid(&MMV_VISITOR::visitMETranslation);};
virtual bool visitTranslationOverride() {return typeid(&MetaModelTreeVisitor::visitTranslation) != typeid(&MMV_VISITOR::visitTranslation);};

// 2.4
virtual bool visitContextOverride() {return typeid(&MetaModelTreeVisitor::visitContext) != typeid(&MMV_VISITOR::visitContext);};
virtual bool visitGenericDefOverride() {return typeid(&MetaModelTreeVisitor::visitGenericDef) != typeid(&MMV_VISITOR::visitGenericDef);};

