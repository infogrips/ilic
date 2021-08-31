virtual bool preVisitOverride() {return typeid(&MetaModelClassVisitor::preVisit) != typeid(&MMV_VISITOR::preVisit);};
virtual bool postVisitOverride() {return typeid(&MetaModelClassVisitor::postVisit) != typeid(&MMV_VISITOR::postVisit);};
   
virtual bool preVisitModelOverride() {return typeid(&MetaModelClassVisitor::preVisitModel) != typeid(&MMV_VISITOR::preVisitModel);};
virtual bool visitModelOverride() {return typeid(&MetaModelClassVisitor::visitModel) != typeid(&MMV_VISITOR::visitModel);};
virtual bool postVisitModelOverride() {return typeid(&MetaModelClassVisitor::postVisitModel) != typeid(&MMV_VISITOR::postVisitModel);};

virtual bool visitImportOverride() {return typeid(&MetaModelClassVisitor::visitImport) != typeid(&MMV_VISITOR::visitImport);};

virtual bool visitUnitOverride() {return typeid(&MetaModelClassVisitor::visitUnit) != typeid(&MMV_VISITOR::visitUnit);};

virtual bool visitMMObjectOverride() {return typeid(&MetaModelClassVisitor::visitMMObject) != typeid(&MMV_VISITOR::visitMMObject);};

virtual bool visitNumTypeOverride() {return typeid(&MetaModelClassVisitor::visitNumType) != typeid(&MMV_VISITOR::visitNumType);};
virtual bool visitTextTypeOverride() {return typeid(&MetaModelClassVisitor::visitTextType) != typeid(&MMV_VISITOR::visitTextType);};
virtual bool visitFormattedTypeOverride() {return typeid(&MetaModelClassVisitor::visitFormattedType) != typeid(&MMV_VISITOR::visitFormattedType);};
virtual bool visitEnumTypeOverride() {return typeid(&MetaModelClassVisitor::visitEnumType) != typeid(&MMV_VISITOR::visitEnumType);};
virtual bool visitCoordTypeOverride() {return typeid(&MetaModelClassVisitor::visitCoordType) != typeid(&MMV_VISITOR::visitCoordType);};
virtual bool visitLineFormOverride() {return typeid(&MetaModelClassVisitor::visitLineForm) != typeid(&MMV_VISITOR::visitLineForm);};
 
virtual bool visitFunctionDefOverride() {return typeid(&MetaModelClassVisitor::visitFunctionDef) != typeid(&MMV_VISITOR::visitFunctionDef);};

virtual bool preVisitSubModelOverride() {return typeid(&MetaModelClassVisitor::preVisitSubModel) != typeid(&MMV_VISITOR::preVisitSubModel);};
virtual bool visitSubModelOverride() {return typeid(&MetaModelClassVisitor::visitSubModel) != typeid(&MMV_VISITOR::visitSubModel);};
virtual bool postVisitSubModelOverride() {return typeid(&MetaModelClassVisitor::postVisitSubModel) != typeid(&MMV_VISITOR::postVisitSubModel);};
      
virtual bool preVisitClassOverride() {return typeid(&MetaModelClassVisitor::preVisitClass) != typeid(&MMV_VISITOR::preVisitClass);};
virtual bool visitClassOverride() {return typeid(&MetaModelClassVisitor::visitClass) != typeid(&MMV_VISITOR::visitClass);};
virtual bool postVisitClassOverride() {return typeid(&MetaModelClassVisitor::postVisitClass) != typeid(&MMV_VISITOR::postVisitClass);};

virtual bool visitAttrOrParamOverride() {return typeid(&MetaModelClassVisitor::visitAttrOrParam) != typeid(&MMV_VISITOR::visitAttrOrParam);};

virtual bool visitDocTextOverride() {return typeid(&MetaModelClassVisitor::visitDocText) != typeid(&MMV_VISITOR::visitDocText);};
virtual bool visitMetaAttributeOverride() {return typeid(&MetaModelClassVisitor::visitMetaAttribute) != typeid(&MMV_VISITOR::visitMetaAttribute);};
virtual bool visitMetaElementOverride() {return typeid(&MetaModelClassVisitor::visitMetaElement) != typeid(&MMV_VISITOR::visitMetaElement);};
virtual bool visitExtendableMEOverride() {return typeid(&MetaModelClassVisitor::visitExtendableME) != typeid(&MMV_VISITOR::visitExtendableME);};
virtual bool visitPackageOverride() {return typeid(&MetaModelClassVisitor::visitPackage) != typeid(&MMV_VISITOR::visitPackage);};
virtual bool visitIli1FormatOverride() {return typeid(&MetaModelClassVisitor::visitIli1Format) != typeid(&MMV_VISITOR::visitIli1Format);};
virtual bool visitExpressionOverride() {return typeid(&MetaModelClassVisitor::visitExpression) != typeid(&MMV_VISITOR::visitExpression);};
virtual bool visitMultiplicityOverride() {return typeid(&MetaModelClassVisitor::visitMultiplicity) != typeid(&MMV_VISITOR::visitMultiplicity);};
virtual bool visitConstraintOverride() {return typeid(&MetaModelClassVisitor::visitConstraint) != typeid(&MMV_VISITOR::visitConstraint);};
virtual bool visitDomainTypeOverride() {return typeid(&MetaModelClassVisitor::visitDomainType) != typeid(&MMV_VISITOR::visitDomainType);};
virtual bool visitTypeOverride() {return typeid(&MetaModelClassVisitor::visitType) != typeid(&MMV_VISITOR::visitType);};
virtual bool visitTypeRelatedTypeOverride() {return typeid(&MetaModelClassVisitor::visitTypeRelatedType) != typeid(&MMV_VISITOR::visitTypeRelatedType);};
virtual bool visitTypeRestrictionOverride() {return typeid(&MetaModelClassVisitor::visitTypeRestriction) != typeid(&MMV_VISITOR::visitTypeRestriction);};
virtual bool visitMultiValueOverride() {return typeid(&MetaModelClassVisitor::visitMultiValue) != typeid(&MMV_VISITOR::visitMultiValue);};
virtual bool visitClassRelatedTypeOverride() {return typeid(&MetaModelClassVisitor::visitClassRelatedType) != typeid(&MMV_VISITOR::visitClassRelatedType);};
virtual bool visitBaseClassOverride() {return typeid(&MetaModelClassVisitor::visitBaseClass) != typeid(&MMV_VISITOR::visitBaseClass);};
virtual bool visitClassRestrictionOverride() {return typeid(&MetaModelClassVisitor::visitClassRestriction) != typeid(&MMV_VISITOR::visitClassRestriction);};
virtual bool visitReferenceTypeOverride() {return typeid(&MetaModelClassVisitor::visitReferenceType) != typeid(&MMV_VISITOR::visitReferenceType);};
virtual bool visitRoleOverride() {return typeid(&MetaModelClassVisitor::visitRole) != typeid(&MMV_VISITOR::visitRole);};
virtual bool visitExplicitAssocAccessOverride() {return typeid(&MetaModelClassVisitor::visitExplicitAssocAccess) != typeid(&MMV_VISITOR::visitExplicitAssocAccess);};
virtual bool visitAssocAccOverride() {return typeid(&MetaModelClassVisitor::visitAssocAcc) != typeid(&MMV_VISITOR::visitAssocAcc);};
virtual bool visitTransferElementOverride() {return typeid(&MetaModelClassVisitor::visitTransferElement) != typeid(&MMV_VISITOR::visitTransferElement);};
virtual bool visitIli1TransferElementOverride() {return typeid(&MetaModelClassVisitor::visitIli1TransferElement) != typeid(&MMV_VISITOR::visitIli1TransferElement);};
virtual bool visitDataUnitOverride() {return typeid(&MetaModelClassVisitor::visitDataUnit) != typeid(&MMV_VISITOR::visitDataUnit);};
virtual bool visitAllowedInBasketOverride() {return typeid(&MetaModelClassVisitor::visitAllowedInBasket) != typeid(&MMV_VISITOR::visitAllowedInBasket);};
virtual bool visitMetaBasketDefOverride() {return typeid(&MetaModelClassVisitor::visitMetaBasketDef) != typeid(&MMV_VISITOR::visitMetaBasketDef);};
virtual bool visitMetaObjectDefOverride() {return typeid(&MetaModelClassVisitor::visitMetaObjectDef) != typeid(&MMV_VISITOR::visitMetaObjectDef);};
virtual bool visitBooleanTypeOverride() {return typeid(&MetaModelClassVisitor::visitBooleanType) != typeid(&MMV_VISITOR::visitBooleanType);};
virtual bool visitBlackboxTypeOverride() {return typeid(&MetaModelClassVisitor::visitBlackboxType) != typeid(&MMV_VISITOR::visitBlackboxType);};
virtual bool visitAxisSpecOverride() {return typeid(&MetaModelClassVisitor::visitAxisSpec) != typeid(&MMV_VISITOR::visitAxisSpec);};
virtual bool visitNumsRefSysOverride() {return typeid(&MetaModelClassVisitor::visitNumsRefSys) != typeid(&MMV_VISITOR::visitNumsRefSys);};
virtual bool visitAnyOIDTypeOverride() {return typeid(&MetaModelClassVisitor::visitAnyOIDType) != typeid(&MMV_VISITOR::visitAnyOIDType);};
virtual bool visitArgumentOverride() {return typeid(&MetaModelClassVisitor::visitArgument) != typeid(&MMV_VISITOR::visitArgument);};
virtual bool visitClassRefTypeOverride() {return typeid(&MetaModelClassVisitor::visitClassRefType) != typeid(&MMV_VISITOR::visitClassRefType);};
virtual bool visitObjectTypeOverride() {return typeid(&MetaModelClassVisitor::visitObjectType) != typeid(&MMV_VISITOR::visitObjectType);};
virtual bool visitAttributeRefTypeOverride() {return typeid(&MetaModelClassVisitor::visitAttributeRefType) != typeid(&MMV_VISITOR::visitAttributeRefType);};
virtual bool visitARefRestrictionOverride() {return typeid(&MetaModelClassVisitor::visitARefRestriction) != typeid(&MMV_VISITOR::visitARefRestriction);};
virtual bool visitEnumNodeOverride() {return typeid(&MetaModelClassVisitor::visitEnumNode) != typeid(&MMV_VISITOR::visitEnumNode);};
virtual bool visitEnumTreeValueTypeOverride() {return typeid(&MetaModelClassVisitor::visitEnumTreeValueType) != typeid(&MMV_VISITOR::visitEnumTreeValueType);};
virtual bool visitLineTypeOverride() {return typeid(&MetaModelClassVisitor::visitLineType) != typeid(&MMV_VISITOR::visitLineType);};
virtual bool visitLinesFormOverride() {return typeid(&MetaModelClassVisitor::visitLinesForm) != typeid(&MMV_VISITOR::visitLinesForm);};
virtual bool visitViewOverride() {return typeid(&MetaModelClassVisitor::visitView) != typeid(&MMV_VISITOR::visitView);};
virtual bool visitRenamedBaseViewOverride() {return typeid(&MetaModelClassVisitor::visitRenamedBaseView) != typeid(&MMV_VISITOR::visitRenamedBaseView);};
virtual bool visitUnaryExprOverride() {return typeid(&MetaModelClassVisitor::visitUnaryExpr) != typeid(&MMV_VISITOR::visitUnaryExpr);};
virtual bool visitCompoundExprOverride() {return typeid(&MetaModelClassVisitor::visitCompoundExpr) != typeid(&MMV_VISITOR::visitCompoundExpr);};
virtual bool visitFactorOverride() {return typeid(&MetaModelClassVisitor::visitFactor) != typeid(&MMV_VISITOR::visitFactor);};
virtual bool visitPathElOverride() {return typeid(&MetaModelClassVisitor::visitPathEl) != typeid(&MMV_VISITOR::visitPathEl);};
virtual bool visitPathOrInspFactorOverride() {return typeid(&MetaModelClassVisitor::visitPathOrInspFactor) != typeid(&MMV_VISITOR::visitPathOrInspFactor);};
virtual bool visitEnumAssignmentOverride() {return typeid(&MetaModelClassVisitor::visitEnumAssignment) != typeid(&MMV_VISITOR::visitEnumAssignment);};
virtual bool visitEnumMappingOverride() {return typeid(&MetaModelClassVisitor::visitEnumMapping) != typeid(&MMV_VISITOR::visitEnumMapping);};
virtual bool visitClassRefOverride() {return typeid(&MetaModelClassVisitor::visitClassRef) != typeid(&MMV_VISITOR::visitClassRef);};
virtual bool visitActualArgumentOverride() {return typeid(&MetaModelClassVisitor::visitActualArgument) != typeid(&MMV_VISITOR::visitActualArgument);};
virtual bool visitFunctionCallOverride() {return typeid(&MetaModelClassVisitor::visitFunctionCall) != typeid(&MMV_VISITOR::visitFunctionCall);};
virtual bool visitRuntimeParamRefOverride() {return typeid(&MetaModelClassVisitor::visitRuntimeParamRef) != typeid(&MMV_VISITOR::visitRuntimeParamRef);};
virtual bool visitConstantOverride() {return typeid(&MetaModelClassVisitor::visitConstant) != typeid(&MMV_VISITOR::visitConstant);};
virtual bool visitClassConstOverride() {return typeid(&MetaModelClassVisitor::visitClassConst) != typeid(&MMV_VISITOR::visitClassConst);};
virtual bool visitAttributeConstOverride() {return typeid(&MetaModelClassVisitor::visitAttributeConst) != typeid(&MMV_VISITOR::visitAttributeConst);};
virtual bool visitUnitRefOverride() {return typeid(&MetaModelClassVisitor::visitUnitRef) != typeid(&MMV_VISITOR::visitUnitRef);};
virtual bool visitUnitFunctionOverride() {return typeid(&MetaModelClassVisitor::visitUnitFunction) != typeid(&MMV_VISITOR::visitUnitFunction);};
virtual bool visitSimpleConstraintOverride() {return typeid(&MetaModelClassVisitor::visitSimpleConstraint) != typeid(&MMV_VISITOR::visitSimpleConstraint);};
virtual bool visitExistenceDefOverride() {return typeid(&MetaModelClassVisitor::visitExistenceDef) != typeid(&MMV_VISITOR::visitExistenceDef);};
virtual bool visitExistenceConstraintOverride() {return typeid(&MetaModelClassVisitor::visitExistenceConstraint) != typeid(&MMV_VISITOR::visitExistenceConstraint);};
virtual bool visitUniqueConstraintOverride() {return typeid(&MetaModelClassVisitor::visitUniqueConstraint) != typeid(&MMV_VISITOR::visitUniqueConstraint);};
virtual bool visitSetConstraintOverride() {return typeid(&MetaModelClassVisitor::visitSetConstraint) != typeid(&MMV_VISITOR::visitSetConstraint);};
virtual bool visitGraphicOverride() {return typeid(&MetaModelClassVisitor::visitGraphic) != typeid(&MMV_VISITOR::visitGraphic);};
virtual bool visitSignParamAssignmentOverride() {return typeid(&MetaModelClassVisitor::visitSignParamAssignment) != typeid(&MMV_VISITOR::visitSignParamAssignment);};
virtual bool visitCondSignParamAssignmentOverride() {return typeid(&MetaModelClassVisitor::visitCondSignParamAssignment) != typeid(&MMV_VISITOR::visitCondSignParamAssignment);};
virtual bool visitDrawingRuleOverride() {return typeid(&MetaModelClassVisitor::visitDrawingRule) != typeid(&MMV_VISITOR::visitDrawingRule);};
virtual bool visitDocTextTranslationOverride() {return typeid(&MetaModelClassVisitor::visitDocTextTranslation) != typeid(&MMV_VISITOR::visitDocTextTranslation);};
virtual bool visitMETranslationOverride() {return typeid(&MetaModelClassVisitor::visitMETranslation) != typeid(&MMV_VISITOR::visitMETranslation);};
virtual bool visitTranslationOverride() {return typeid(&MetaModelClassVisitor::visitTranslation) != typeid(&MMV_VISITOR::visitTranslation);};

// 2.4
virtual bool visitContextOverride() {return typeid(&MetaModelClassVisitor::visitContext) != typeid(&MMV_VISITOR::visitContext);};
virtual bool visitGenericDefOverride() {return typeid(&MetaModelClassVisitor::visitGenericDef) != typeid(&MMV_VISITOR::visitGenericDef);};

