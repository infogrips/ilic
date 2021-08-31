virtual bool preVisitOverride() {return typeid(&MetaModelVisitor::preVisit) != typeid(&MMV_VISITOR::preVisit);};
virtual bool postVisitOverride() {return typeid(&MetaModelVisitor::postVisit) != typeid(&MMV_VISITOR::postVisit);};
   
virtual bool preVisitModelOverride() {return typeid(&MetaModelVisitor::preVisitModel) != typeid(&MMV_VISITOR::preVisitModel);};
virtual bool visitModelOverride() {return typeid(&MetaModelVisitor::visitModel) != typeid(&MMV_VISITOR::visitModel);};
virtual bool postVisitModelOverride() {return typeid(&MetaModelVisitor::postVisitModel) != typeid(&MMV_VISITOR::postVisitModel);};

virtual bool visitImportOverride() {return typeid(&MetaModelVisitor::visitImport) != typeid(&MMV_VISITOR::visitImport);};

virtual bool visitUnitOverride() {return typeid(&MetaModelVisitor::visitUnit) != typeid(&MMV_VISITOR::visitUnit);};

virtual bool visitMMObjectOverride() {return typeid(&MetaModelVisitor::visitMMObject) != typeid(&MMV_VISITOR::visitMMObject);};

virtual bool visitNumTypeOverride() {return typeid(&MetaModelVisitor::visitNumType) != typeid(&MMV_VISITOR::visitNumType);};
virtual bool visitTextTypeOverride() {return typeid(&MetaModelVisitor::visitTextType) != typeid(&MMV_VISITOR::visitTextType);};
virtual bool visitFormattedTypeOverride() {return typeid(&MetaModelVisitor::visitFormattedType) != typeid(&MMV_VISITOR::visitFormattedType);};
virtual bool visitEnumTypeOverride() {return typeid(&MetaModelVisitor::visitEnumType) != typeid(&MMV_VISITOR::visitEnumType);};
virtual bool visitCoordTypeOverride() {return typeid(&MetaModelVisitor::visitCoordType) != typeid(&MMV_VISITOR::visitCoordType);};
virtual bool visitLineFormOverride() {return typeid(&MetaModelVisitor::visitLineForm) != typeid(&MMV_VISITOR::visitLineForm);};
 
virtual bool visitFunctionDefOverride() {return typeid(&MetaModelVisitor::visitFunctionDef) != typeid(&MMV_VISITOR::visitFunctionDef);};

virtual bool preVisitSubModelOverride() {return typeid(&MetaModelVisitor::preVisitSubModel) != typeid(&MMV_VISITOR::preVisitSubModel);};
virtual bool visitSubModelOverride() {return typeid(&MetaModelVisitor::visitSubModel) != typeid(&MMV_VISITOR::visitSubModel);};
virtual bool postVisitSubModelOverride() {return typeid(&MetaModelVisitor::postVisitSubModel) != typeid(&MMV_VISITOR::postVisitSubModel);};
      
virtual bool preVisitClassOverride() {return typeid(&MetaModelVisitor::preVisitClass) != typeid(&MMV_VISITOR::preVisitClass);};
virtual bool visitClassOverride() {return typeid(&MetaModelVisitor::visitClass) != typeid(&MMV_VISITOR::visitClass);};
virtual bool postVisitClassOverride() {return typeid(&MetaModelVisitor::postVisitClass) != typeid(&MMV_VISITOR::postVisitClass);};

virtual bool visitAttrOrParamOverride() {return typeid(&MetaModelVisitor::visitAttrOrParam) != typeid(&MMV_VISITOR::visitAttrOrParam);};

virtual bool visitDocTextOverride() {return typeid(&MetaModelVisitor::visitDocText) != typeid(&MMV_VISITOR::visitDocText);};
virtual bool visitMetaAttributeOverride() {return typeid(&MetaModelVisitor::visitMetaAttribute) != typeid(&MMV_VISITOR::visitMetaAttribute);};
virtual bool visitMetaElementOverride() {return typeid(&MetaModelVisitor::visitMetaElement) != typeid(&MMV_VISITOR::visitMetaElement);};
virtual bool visitExtendableMEOverride() {return typeid(&MetaModelVisitor::visitExtendableME) != typeid(&MMV_VISITOR::visitExtendableME);};
virtual bool visitPackageOverride() {return typeid(&MetaModelVisitor::visitPackage) != typeid(&MMV_VISITOR::visitPackage);};
virtual bool visitIli1FormatOverride() {return typeid(&MetaModelVisitor::visitIli1Format) != typeid(&MMV_VISITOR::visitIli1Format);};
virtual bool visitExpressionOverride() {return typeid(&MetaModelVisitor::visitExpression) != typeid(&MMV_VISITOR::visitExpression);};
virtual bool visitMultiplicityOverride() {return typeid(&MetaModelVisitor::visitMultiplicity) != typeid(&MMV_VISITOR::visitMultiplicity);};
virtual bool visitConstraintOverride() {return typeid(&MetaModelVisitor::visitConstraint) != typeid(&MMV_VISITOR::visitConstraint);};
virtual bool visitDomainTypeOverride() {return typeid(&MetaModelVisitor::visitDomainType) != typeid(&MMV_VISITOR::visitDomainType);};
virtual bool visitTypeOverride() {return typeid(&MetaModelVisitor::visitType) != typeid(&MMV_VISITOR::visitType);};
virtual bool visitTypeRelatedTypeOverride() {return typeid(&MetaModelVisitor::visitTypeRelatedType) != typeid(&MMV_VISITOR::visitTypeRelatedType);};
virtual bool visitTypeRestrictionOverride() {return typeid(&MetaModelVisitor::visitTypeRestriction) != typeid(&MMV_VISITOR::visitTypeRestriction);};
virtual bool visitMultiValueOverride() {return typeid(&MetaModelVisitor::visitMultiValue) != typeid(&MMV_VISITOR::visitMultiValue);};
virtual bool visitClassRelatedTypeOverride() {return typeid(&MetaModelVisitor::visitClassRelatedType) != typeid(&MMV_VISITOR::visitClassRelatedType);};
virtual bool visitBaseClassOverride() {return typeid(&MetaModelVisitor::visitBaseClass) != typeid(&MMV_VISITOR::visitBaseClass);};
virtual bool visitClassRestrictionOverride() {return typeid(&MetaModelVisitor::visitClassRestriction) != typeid(&MMV_VISITOR::visitClassRestriction);};
virtual bool visitReferenceTypeOverride() {return typeid(&MetaModelVisitor::visitReferenceType) != typeid(&MMV_VISITOR::visitReferenceType);};
virtual bool visitRoleOverride() {return typeid(&MetaModelVisitor::visitRole) != typeid(&MMV_VISITOR::visitRole);};
virtual bool visitExplicitAssocAccessOverride() {return typeid(&MetaModelVisitor::visitExplicitAssocAccess) != typeid(&MMV_VISITOR::visitExplicitAssocAccess);};
virtual bool visitAssocAccOverride() {return typeid(&MetaModelVisitor::visitAssocAcc) != typeid(&MMV_VISITOR::visitAssocAcc);};
virtual bool visitTransferElementOverride() {return typeid(&MetaModelVisitor::visitTransferElement) != typeid(&MMV_VISITOR::visitTransferElement);};
virtual bool visitIli1TransferElementOverride() {return typeid(&MetaModelVisitor::visitIli1TransferElement) != typeid(&MMV_VISITOR::visitIli1TransferElement);};
virtual bool visitDataUnitOverride() {return typeid(&MetaModelVisitor::visitDataUnit) != typeid(&MMV_VISITOR::visitDataUnit);};
virtual bool visitAllowedInBasketOverride() {return typeid(&MetaModelVisitor::visitAllowedInBasket) != typeid(&MMV_VISITOR::visitAllowedInBasket);};
virtual bool visitMetaBasketDefOverride() {return typeid(&MetaModelVisitor::visitMetaBasketDef) != typeid(&MMV_VISITOR::visitMetaBasketDef);};
virtual bool visitMetaObjectDefOverride() {return typeid(&MetaModelVisitor::visitMetaObjectDef) != typeid(&MMV_VISITOR::visitMetaObjectDef);};
virtual bool visitBooleanTypeOverride() {return typeid(&MetaModelVisitor::visitBooleanType) != typeid(&MMV_VISITOR::visitBooleanType);};
virtual bool visitBlackboxTypeOverride() {return typeid(&MetaModelVisitor::visitBlackboxType) != typeid(&MMV_VISITOR::visitBlackboxType);};
virtual bool visitAxisSpecOverride() {return typeid(&MetaModelVisitor::visitAxisSpec) != typeid(&MMV_VISITOR::visitAxisSpec);};
virtual bool visitNumsRefSysOverride() {return typeid(&MetaModelVisitor::visitNumsRefSys) != typeid(&MMV_VISITOR::visitNumsRefSys);};
virtual bool visitAnyOIDTypeOverride() {return typeid(&MetaModelVisitor::visitAnyOIDType) != typeid(&MMV_VISITOR::visitAnyOIDType);};
virtual bool visitArgumentOverride() {return typeid(&MetaModelVisitor::visitArgument) != typeid(&MMV_VISITOR::visitArgument);};
virtual bool visitClassRefTypeOverride() {return typeid(&MetaModelVisitor::visitClassRefType) != typeid(&MMV_VISITOR::visitClassRefType);};
virtual bool visitObjectTypeOverride() {return typeid(&MetaModelVisitor::visitObjectType) != typeid(&MMV_VISITOR::visitObjectType);};
virtual bool visitAttributeRefTypeOverride() {return typeid(&MetaModelVisitor::visitAttributeRefType) != typeid(&MMV_VISITOR::visitAttributeRefType);};
virtual bool visitARefRestrictionOverride() {return typeid(&MetaModelVisitor::visitARefRestriction) != typeid(&MMV_VISITOR::visitARefRestriction);};
virtual bool visitEnumNodeOverride() {return typeid(&MetaModelVisitor::visitEnumNode) != typeid(&MMV_VISITOR::visitEnumNode);};
virtual bool visitEnumTreeValueTypeOverride() {return typeid(&MetaModelVisitor::visitEnumTreeValueType) != typeid(&MMV_VISITOR::visitEnumTreeValueType);};
virtual bool visitLineTypeOverride() {return typeid(&MetaModelVisitor::visitLineType) != typeid(&MMV_VISITOR::visitLineType);};
virtual bool visitLinesFormOverride() {return typeid(&MetaModelVisitor::visitLinesForm) != typeid(&MMV_VISITOR::visitLinesForm);};
virtual bool visitViewOverride() {return typeid(&MetaModelVisitor::visitView) != typeid(&MMV_VISITOR::visitView);};
virtual bool visitRenamedBaseViewOverride() {return typeid(&MetaModelVisitor::visitRenamedBaseView) != typeid(&MMV_VISITOR::visitRenamedBaseView);};
virtual bool visitUnaryExprOverride() {return typeid(&MetaModelVisitor::visitUnaryExpr) != typeid(&MMV_VISITOR::visitUnaryExpr);};
virtual bool visitCompoundExprOverride() {return typeid(&MetaModelVisitor::visitCompoundExpr) != typeid(&MMV_VISITOR::visitCompoundExpr);};
virtual bool visitFactorOverride() {return typeid(&MetaModelVisitor::visitFactor) != typeid(&MMV_VISITOR::visitFactor);};
virtual bool visitPathElOverride() {return typeid(&MetaModelVisitor::visitPathEl) != typeid(&MMV_VISITOR::visitPathEl);};
virtual bool visitPathOrInspFactorOverride() {return typeid(&MetaModelVisitor::visitPathOrInspFactor) != typeid(&MMV_VISITOR::visitPathOrInspFactor);};
virtual bool visitEnumAssignmentOverride() {return typeid(&MetaModelVisitor::visitEnumAssignment) != typeid(&MMV_VISITOR::visitEnumAssignment);};
virtual bool visitEnumMappingOverride() {return typeid(&MetaModelVisitor::visitEnumMapping) != typeid(&MMV_VISITOR::visitEnumMapping);};
virtual bool visitClassRefOverride() {return typeid(&MetaModelVisitor::visitClassRef) != typeid(&MMV_VISITOR::visitClassRef);};
virtual bool visitActualArgumentOverride() {return typeid(&MetaModelVisitor::visitActualArgument) != typeid(&MMV_VISITOR::visitActualArgument);};
virtual bool visitFunctionCallOverride() {return typeid(&MetaModelVisitor::visitFunctionCall) != typeid(&MMV_VISITOR::visitFunctionCall);};
virtual bool visitRuntimeParamRefOverride() {return typeid(&MetaModelVisitor::visitRuntimeParamRef) != typeid(&MMV_VISITOR::visitRuntimeParamRef);};
virtual bool visitConstantOverride() {return typeid(&MetaModelVisitor::visitConstant) != typeid(&MMV_VISITOR::visitConstant);};
virtual bool visitClassConstOverride() {return typeid(&MetaModelVisitor::visitClassConst) != typeid(&MMV_VISITOR::visitClassConst);};
virtual bool visitAttributeConstOverride() {return typeid(&MetaModelVisitor::visitAttributeConst) != typeid(&MMV_VISITOR::visitAttributeConst);};
virtual bool visitUnitRefOverride() {return typeid(&MetaModelVisitor::visitUnitRef) != typeid(&MMV_VISITOR::visitUnitRef);};
virtual bool visitUnitFunctionOverride() {return typeid(&MetaModelVisitor::visitUnitFunction) != typeid(&MMV_VISITOR::visitUnitFunction);};
virtual bool visitSimpleConstraintOverride() {return typeid(&MetaModelVisitor::visitSimpleConstraint) != typeid(&MMV_VISITOR::visitSimpleConstraint);};
virtual bool visitExistenceDefOverride() {return typeid(&MetaModelVisitor::visitExistenceDef) != typeid(&MMV_VISITOR::visitExistenceDef);};
virtual bool visitExistenceConstraintOverride() {return typeid(&MetaModelVisitor::visitExistenceConstraint) != typeid(&MMV_VISITOR::visitExistenceConstraint);};
virtual bool visitUniqueConstraintOverride() {return typeid(&MetaModelVisitor::visitUniqueConstraint) != typeid(&MMV_VISITOR::visitUniqueConstraint);};
virtual bool visitSetConstraintOverride() {return typeid(&MetaModelVisitor::visitSetConstraint) != typeid(&MMV_VISITOR::visitSetConstraint);};
virtual bool visitGraphicOverride() {return typeid(&MetaModelVisitor::visitGraphic) != typeid(&MMV_VISITOR::visitGraphic);};
virtual bool visitSignParamAssignmentOverride() {return typeid(&MetaModelVisitor::visitSignParamAssignment) != typeid(&MMV_VISITOR::visitSignParamAssignment);};
virtual bool visitCondSignParamAssignmentOverride() {return typeid(&MetaModelVisitor::visitCondSignParamAssignment) != typeid(&MMV_VISITOR::visitCondSignParamAssignment);};
virtual bool visitDrawingRuleOverride() {return typeid(&MetaModelVisitor::visitDrawingRule) != typeid(&MMV_VISITOR::visitDrawingRule);};
virtual bool visitDocTextTranslationOverride() {return typeid(&MetaModelVisitor::visitDocTextTranslation) != typeid(&MMV_VISITOR::visitDocTextTranslation);};
virtual bool visitMETranslationOverride() {return typeid(&MetaModelVisitor::visitMETranslation) != typeid(&MMV_VISITOR::visitMETranslation);};
virtual bool visitTranslationOverride() {return typeid(&MetaModelVisitor::visitTranslation) != typeid(&MMV_VISITOR::visitTranslation);};

// 2.4
virtual bool visitContextOverride() {return typeid(&MetaModelVisitor::visitContext) != typeid(&MMV_VISITOR::visitContext);};
virtual bool visitGenericDefOverride() {return typeid(&MetaModelVisitor::visitGenericDef) != typeid(&MMV_VISITOR::visitGenericDef);};

