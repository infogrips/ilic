//
//  start of grammar
//

parser grammar Ili2Parser;

@members {
   bool ili23=true; 
   bool ili24=false;
}

options
{
   tokenVocab = Ili2Lexer;
}

decimal
   : DEC
   | POSNUMBER
   | NUMBER
   ;
   
path
   : (INTERLIS | NAME) (DOT NAME)*
   ;
   
interlis2Def
   : INTERLIS 
     ({ili23}? iliversion=ILI23 
     |{ili24}? iliversion=ILI24
     )
     SEMI (modelDef)* EOF
   ;

modelDef
   : (contracted=CONTRACTED)? 
     (refsystemmodel=REFSYSTEM | symbologymodel=SYMBOLOGY | typemodel=TYPE)? 
     MODEL modelname1=NAME (LPAREN language=NAME RPAREN)?
//     {ili24}? (noincrementaltransfer=NOINCREMENTALTRANSFER)?
     ATT issuerurl=STRING 
     VERSION modelversion=STRING (modelversion_expl=EXPLANATION)?
     (TRANSLATION OF translationOf=NAME LBRACE translationOfVersion=STRING RBRACE)?
     EQUAL
//    {ili24}? (CHARSET iananame=STRING SEMI)?
//    {ili24}? (XMLNS xmlns=STRING SEMI)?      
     (importDef)*
     (metaDataBasketDef
     |unitDecl
     |functionDef
     |lineFormTypeDef
     |domainDecl
     |runTimeParameterDef
     |classDef
     |structureDef
     |topicDef 
     )*
     END modelname2=NAME DOT
   ;

importDef
   : IMPORTS importing (COMMA importing)* SEMI
   ;

importing
   : UNQUALIFIED? (importname=path)
   ;

topicDef
   : VIEW? TOPIC topicname1=NAME
     properties? // ABSTRACT|FINAL
     (EXTENDS topicbase=path)?
     EQUAL
     (BASKET OID AS topicOid1=path SEMI)?
     (OID AS topicOid2=path SEMI)?
     (DEPENDS ON depTopic=path (COMMA depTopic=path)* SEMI)*
     (metaDataBasketDef
     |unitDecl
     |functionDef
     |domainDecl
     |classDef
     |structureDef
     |associationDef
     |constraintsDef
     |viewDef
     |graphicDef
     )*
     END topicname2=NAME SEMI
   ;
   
classDef
   : CLASS classname1=NAME properties? // ABSTRACT|EXTENDED|FINAL
     (EXTENDS classbase=path)? EQUAL
     ((OID AS classoid=path | NO OID) SEMI )?
     classOrStructureDef
     END classname2=NAME SEMI
   ;

structureDef
   : STRUCTURE structurename1=NAME properties? // ABSTRACT|EXTENDED|FINAL
     (EXTENDS structurebase=path)? EQUAL
     classOrStructureDef
     END structurename2=NAME SEMI
   ;
               
classOrStructureDef
   : ATTRIBUTE? 
     attributeDef*
     constraintDef*
     (PARAMETER parameterDef*)?
   ;

attributeDef
   : (CONTINUOUS? SUBDIVISION)? attributname=NAME
     properties? // ABSTRACT|EXTENDED|FINAL
     COLON attrTypeDef
     (COLONEQUAL factor (COMMA factor)*)? SEMI
   ;

attrTypeDef
   : MANDATORY? attrType
   | bagOrListType
   ;
   
bagOrListType
   : (BAG | LIST) cardinality? OF restrictedRef
   ;
      
attrType
   : type
   | path
   | referenceAttr
   | restrictedRef
   ;

referenceAttr
   : REFERENCE TO (LPAREN EXTERNAL RPAREN)? restrictedRef
   ;

restrictedRef
   : (typeref=path | ANYCLASS | ANYSTRUCTURE)
     (RESTRICTION LPAREN path (COMMA path)* RPAREN)?
   ;

associationDef
   : ASSOCIATION associationname1=NAME
     properties? // ABSTRACT|EXTENDED|FINAL|OID
     (EXTENDS associationRef)?
     (DERIVED FROM renamedViewableRef)? EQUAL
     ((OID AS assocoid=path | NO OID) SEMI)?
     (roleDef)*
     ATTRIBUTE? (attributeDef)*
     (CARDINALITY EQUAL cardinality SEMI)?
     (constraintDef)*
     END associationname2=NAME SEMI
   ;

associationRef
   : ((modelname=NAME DOT)? topicname=NAME DOT)? associationname=NAME
   ;

roleDef
   : rolename=NAME 
     properties? // ABSTRACT|EXTENDED|FINAL|HIDING|ORDERED|EXTERNAL
     (ASSOCIATE | AGGREGATE | COMPOSITE ) cardinality?
     restrictedRef (OR restrictedRef)*
     (COLONEQUAL role=factor)? SEMI
   ;

cardinality
   : LCURLY (STAR | min=POSNUMBER (DOTDOT (max=POSNUMBER | STAR))?) RCURLY
   ;

domainDecl
   : ILIDOMAIN domainDef*
   ;
                
domainDef
   : domainname=NAME properties? // ABSTRACT|FINAL
     (EXTENDS basedomain=path)? EQUAL
     (MANDATORY type? | type) SEMI
   ;
                
type
   : baseType 
   | lineType
   ;
   
baseType
   : textType
   | enumerationType
   | enumTreeValueType
   | alignmentType
   | booleanType
   | numericType
   | formattedType
   | coordinateType
   | oIDType
   | blackboxType
   | classType
   | attributeType
   ;

constant
   : UNDEFINED
   | numericConst
   | textConst
   | formattedConst
   | enumConst
   | classConst
   | attributeConst
   ;

textType
   : MTEXT (STAR maxlength=POSNUMBER)?
   | TEXT (STAR maxlength=POSNUMBER)?
   | NAME
   | URI
   ;

textConst
   : STRING
   ;

enumerationType
   : enumeration (ORDERED | CIRCULAR)?
   ;

enumTreeValueType
   : ALL OF typeref=path
   ;

enumeration
   : LPAREN enumElement (COMMA enumElement)* 
     ((COLON FINAL)? | FINAL)? 
     RPAREN
   ;

enumElement
   : NAME (DOT NAME)* (sub=enumeration)?
   ;

enumConst
   : HASH (NAME (DOT NAME)* (DOT OTHERS)?
   | OTHERS)
   ;

alignmentType
   : HALIGNMENT 
   | VALIGNMENT
   ;

booleanType
   : BOOLEAN
   ;
      
numericType
   : (min=decimal DOTDOT max=decimal | NUMERIC ) CIRCULAR?
     (LBRACE unitref=path RBRACE)?
     (CLOCKWISE | COUNTERCLOCKWISE | refSys)?
   ;

refSys
   : (LCURLY refsys=metaObjectRef (LBRACE axis=POSNUMBER RBRACE)? RCURLY
   | LESS coord=path (LBRACE axis=POSNUMBER RBRACE)? GREATER)
   ;

decConst
   : decimal
   | PI 
   | LNBASE
   ;

numericConst
   : decConst (LBRACE unitref=path RBRACE)?
   ;

formattedType
   : (FORMAT BASED ON typeref=path formatDef)?
     (min=STRING DOTDOT max=STRING)?
	| FORMAT typeref=path min=STRING DOTDOT max=STRING
   ;

formatDef 
   : LPAREN INHERITANCE?
     nonnumeric=STRING? (baseAttrRef nonnumeric=STRING)*
     baseAttrRef nonnumeric=STRING? RPAREN
   ;

baseAttrRef
   : NAME (SLASH POSNUMBER)?
   | NAME SLASH baseattr=path
   ;

formattedConst
   : STRING
   ;

coordinateType
   : COORD numtype1=numericType (COMMA numtype2=numericType (COMMA numtype3=numericType)?)? (COMMA rotationDef)?
   ;
   
rotationDef
   : ROTATION nullaxis=POSNUMBER RARROW pihalfaxis=POSNUMBER
   ;

oIDType
   : OID (ANY | numericType | textType)
   ;

blackboxType
   : BLACKBOX (XML | BINARY)
   ;

classType
   : (CLASS (RESTRICTION LPAREN path (COLON path)* RPAREN)?
   | STRUCTURE (RESTRICTION LPAREN path (COLON path)* RPAREN)?)
   ;

attributeType
   : ATTRIBUTE (OF (attributePath | ATT NAME))?
     (RESTRICTION LPAREN attrTypeDef (COLON attrTypeDef)* RPAREN)? 
   ;

classConst
   : GREATER classref=path
   ;

attributeConst
   : GREATERGREATER (classref=path DOT)? attribute=NAME
   ;

lineType
   : DIRECTED? (POLYLINE|SURFACE|AREA)
     lineForm? 
     (VERTEX coordref=path)? 
     (WITHOUT OVERLAPS GREATER overlap=decimal)? 
     (LINE ATTRIBUTES lineattrstruct=path)?
   ;

lineForm 
   : WITH LPAREN lineFormType (COMMA lineFormType)* RPAREN
   ;

lineFormType
   : (STRAIGHTS | ARCS | path)
   ;

lineFormTypeDef
   : LINE FORM (lineFormTypeDecl)*
   ;
   
lineFormTypeDecl
   : lineformtype=NAME COLON linestructurename=NAME SEMI
   ;
   
unitDecl
   : UNIT (unitDef)*
   ;

unitDef
   : unitname=NAME 
     (LPAREN ABSTRACT RPAREN | LBRACE unitshort=path RBRACE)?
     (EXTENDS super=path)?
     (EQUAL (derivedUnit | composedUnit))? 
     SEMI 
   ;

derivedUnit 
   : (decConst ((STAR | SLASH) decConst)* | FUNCTION EXPLANATION)? 
     LBRACE unitref=path RBRACE
   ;

composedUnit
   : LPAREN unitref=path ((STAR | SLASH) unitref=path)* RPAREN
   ;

metaDataBasketDef
   : (SIGN | REFSYSTEM) BASKET basketname=NAME
     (LPAREN FINAL RPAREN)?
     (EXTENDS metaDataBasketRef)?
     TILDE path 
     (OBJECTS OF classname=NAME COLON metabjectname=NAME 
                         ( COMMA metaobjectname=NAME)*)* SEMI
   ;

metaDataBasketRef
   : ((modelname=NAME DOT)? topicname=NAME DOT)? basketname=NAME
   ;

metaObjectRef
   : (metaDataBasketRef DOT)? metaobjectname=NAME
   ;

parameterDef 
   : parameterName=NAME
     properties? // ABSTRACT,EXTENDED,FINAL
     COLON (attrTypeDef | METAOBJECT (OF path)?) SEMI
   ;

properties
   : LPAREN 
     (ABSTRACT|EXTENDED|FINAL|TRANSIENT|OID|HIDING|ORDERED|EXTERNAL) 
     (COMMA (ABSTRACT|EXTENDED|FINAL|TRANSIENT|OID|HIDING|ORDERED|EXTERNAL))* 
     RPAREN
   ;

runTimeParameterDef
   : PARAMETER (runtimeparametername=NAME COLON attrTypeDef SEMI)*
   ;

constraintDef
   : mandatoryConstraint
   | plausibilityConstraint
   | existenceConstraint
   | uniquenessConstraint
   | setConstraint 
   ;

mandatoryConstraint
   : MANDATORY CONSTRAINT booleanexp=expression SEMI
   ;

plausibilityConstraint
   : CONSTRAINT
     (LESSEQUAL | GREATEREQUAL) percentage=decimal PERCENT
     expression SEMI
   ;

existenceConstraint
   : EXISTENCE CONSTRAINT attributePath REQUIRED IN
     path COLON attributePath
     (OR path COLON attributePath )* SEMI
   ;

uniquenessConstraint
   : UNIQUE 
     (WHERE expression COLON)?
     (globalUniqueness | localUniqueness) SEMI
   ;

globalUniqueness
   : uniqueEl
   ;

uniqueEl
   : objectOrAttributePath (COMMA objectOrAttributePath)*
   ;

localUniqueness
   : LPAREN LOCAL RPAREN structureattributename=NAME
     (RARROW structureattributename=NAME)* COLON
     attributename=NAME (COMMA attributename=NAME)*
   ;

setConstraint
   : SET CONSTRAINT (WHERE logical=expression COLON)? expression SEMI
   ;

constraintsDef
   : CONSTRAINTS OF path EQUAL
     (constraintDef)*
     END SEMI
   ;

expression
   : orTerm
   ;

orTerm
   : andTerm (OR andTerm)*
   ;

andTerm
   : predicateTerm (AND predicateTerm)*
   ;

predicateTerm
   : predicate1=predicate (relation predicate2=predicate)?
   ;

predicate
   : factor                       
   | NOT? LPAREN expression RPAREN
   | DEFINED LPAREN factor RPAREN
   ;
   
relation
   : EQUALEQUAL
   | NOTEQUAL
   | LESSGREATER
   | LESSEQUAL
   | GREATEREQUAL
   | LESS
   | GREATER
   ;

factor
   : objectOrAttributePath 
   | (inspection | INSPECTION path) (OF objectOrAttributePath)? 
   | functionCall
   | PARAMETER (modelname=NAME DOT)* runtimeparametername=NAME
   | constant 
   ;

objectOrAttributePath
   : pathEl (RARROW pathEl)*
   ;

attributePath
   : objectOrAttributePath
   ;

pathEl
   : THIS
   | THISAREA 
   | THATAREA
   | PARENT
   | referenceattributename=NAME
   | associationPath
   | rolename=NAME (LBRACE associationname=NAME RBRACE)?
   | basename=NAME
   | attributeRef 
   ;

associationPath
   : (BACKSLASH)? associationaccessmame=NAME
   ;

attributeRef 
   : ( attributename=NAME ((LBRACE (FIRST | LAST | axislistindex=POSNUMBER) RBRACE)?) | AGGREGATES)
   ;

functionCall
   : functionref=path LPAREN functionCallArgument (COMMA functionCallArgument)* RPAREN
   ;

functionCallArgument
   : (expression
     | ALL (LPAREN restrictedRef | path RPAREN)* )
   ;

functionDef
   : FUNCTION functioname=NAME
     LPAREN functionDefParam (SEMI functionDefParam)* RPAREN
     COLON result=argumentType 
     EXPLANATION? 
     SEMI
   ;

functionDefParam
   : argumentname=NAME COLON argumentType
   ;
 
argumentType
   : attrTypeDef 
   | (OBJECT | OBJECTS) OF (restrictedRef | viewref=path)
   | ENUMVAL 
	| ENUMTREEVAL
   ;

viewDef
   : VIEW viewname1=NAME
     properties? // ABSTRACT|EXTENDED|FINAL|TRANSIENT
     (formationDef | EXTENDS viewref=path)
     (baseExtensionDef)*
     (selection)*
     EQUAL
     viewAttributes?
     (constraintDef)*
     END viewname2=NAME SEMI
   ;

formationDef
   : (projection | join | iliunion  | aggregation | inspection) SEMI
   ;

projection
   : PROJECTION OF renamedViewableRef
   ;

join
   : JOIN OF renamedViewableRef
     (COMMA renamedViewableRef (LPAREN OR ILINULL RPAREN)?)+
   ;

iliunion
   : UNION OF renamedViewableRef
     (COMMA renamedViewableRef)*
   ;

aggregation
   : AGGREGATION OF renamedViewableRef
    (ALL | EQUAL LPAREN uniqueEl RPAREN)
   ;

inspection
   : AREA INSPECTION OF renamedViewableRef
     RARROW structureorlineattributename=NAME
     (RARROW structureorlineattributename=NAME)*
   ;

renamedViewableRef
   : (basename=NAME TILDE)? path
   ;

baseExtensionDef
   : BASE basename=NAME EXTENDED BY
     renamedViewableRef (COMMA renamedViewableRef)*
   ;

selection
   : WHERE expression SEMI
   ;

viewAttributes
   : ATTRIBUTE?
     (ALL OF basename=NAME SEMI
      | attributeDef
      | attributename=NAME properties? // ABSTRACT|EXTENDED|FINAL|TRANSIENT
        COLONEQUAL factor SEMI 
     )*
   ;

graphicDef
   : GRAPHIC graphicname1=NAME properties? // ABSTRACT|FINAL
     (EXTENDS path)?
     (BASED ON path)? EQUAL
     (selection)*
     (drawingRule)*
     END graphicname2=NAME SEMI
   ;
             
drawingRule
   : drawingrulename=NAME properties? // ABSTRACT|EXTENDED|FINAL
     (OF path)?
     COLON condSignParamAssignment (COMMA condSignParamAssignment)* SEMI
   ;

condSignParamAssignment
   : (WHERE logical=expression)?
     LPAREN signParamAssignment (COMMA signParamAssignment)* RPAREN
   ;

signParamAssignment
   : signparametername=NAME
     COLONEQUAL ( 
       LCURLY metaObjectRef RCURLY
       | factor
       | ACCORDING enumpath=attributePath
         LPAREN enumAssignment (COMMA enumAssignment)* RPAREN
     )
   ;

enumAssignment
   : (LCURLY metaObjectRef RCURLY | constant) 
     WHEN IN enumRange
   ;

enumRange
   : enumConst (DOTDOT enumConst)?
   ;
