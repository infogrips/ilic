//
//  start of grammar
//

parser grammar Ili1Parser;

options
{
   tokenVocab = Ili1Lexer;
}

interlis1Def
   : TRANSFER transfername=NAME SEMI
     domainDefs?
     derivatives?
     modelDef
     view*
     formatEncoding
     EOF
   ;

modelDef
   : MODEL modelname1=NAME
     domainDefs?
     topicDef+
     END modelname2=NAME DOT
   ;

domainDefs
   : ILIDOMAIN domainDef+
   ;

domainDef
   : domainname=NAME EQUAL type SEMI
   ;

topicDef
   : TOPIC topicname1=NAME EQUAL
     (tableDef | domainDefs)+
     END topicname2=NAME
     DOT
   ;

tableDef
   : OPTIONAL?
     TABLE
     tablename1=NAME EQUAL
     attribute+
     identifications
     END tablename2=NAME SEMI
   ;

attribute
   : attributename=NAME
     COLON
     OPTIONAL?
     (type | RARROW tablename=NAME)
     (explanation=EXPLANATION)?
     SEMI
   ;

identifications
   : NO IDENT
   | IDENT identification+
   ;

identification
   : NAME (COMMA NAME)* SEMI
   ;

type
   : baseType 
   | lineType 
   | areaType
   | name=NAME
   ;

baseType
   : coord2
   | coord3
   | dim1Type
   | dim2Type
   | angleType
   | numericRange
   | textType
   | dateType
   | enumerationType
   | horizAlignment
   | vertAlignment
   ;

coord2
   : COORD2 
     emin=decimal nmin=decimal
     emax=decimal nmax=decimal
   ;

coord3
   : COORD3 
     emin=decimal nmin=decimal hmin = decimal
     emax=decimal nmax=decimal hmax=decimal
   ;

numericRange
   : LBRACE
     min = decimal
     DOTDOT
     max = decimal
     RBRACE
   ;

dim1Type
   : DIM1 min = decimal max=decimal
   ;

dim2Type
   : DIM2 min = decimal max=decimal
   ;

angleType 
   : (RADIANS | DEGREES | GRADS) min=decimal max=decimal
   ;

textType
   : TEXT STAR numchars=POSNUMBER
   ;

dateType
   : date=DATE
   ;

enumerationType
   : LPAREN enumElement (COMMA enumElement)* 
     RPAREN
   ;

enumElement
   : enumelement=NAME (DOT enumelement=NAME)* enumerationType?
   ;

horizAlignment
   : HALIGNMENT
   ;

vertAlignment
   : VALIGNMENT
   ;

lineType
   : POLYLINE
     form
     controlPoints
     intersectionDef?
   ;

areaType
   : ( SURFACE form controlPoints intersectionDef?
     | AREA form controlPoints intersectionDef
     )
     lineAttributes?
   ;

form
   : WITH LPAREN
    lineForm (COMMA lineForm)*
    RPAREN
   ;

lineForm
   : STRAIGHTS
   | ARCS
   | explanation=EXPLANATION
   ;

intersectionDef
   : WITHOUT OVERLAPS GREATER maxoverlap=decimal
   ;

controlPoints
   : VERTEX
     (coord2 | coord3 | NAME)
     (BASE EXPLANATION)?
   ;

lineAttributes
   : LINEATTR EQUAL
     attribute+
     identifications?
     END
   ;

derivatives
   : DERIVATIVES derivativename1=NAME
     domainDefs?
     topicDef+
     END derivativename2=NAME
   ;

view
   : VIEW
     modelname1=NAME (
        topicname=NAME DOT tablename=NAME COLON
        viewDef (COMMA viewDef)* SEMI
     )*
     END
     modelname2=NAME
     DOT
   ;

viewDef
   : VERTEXINFO vertexinfo=NAME explanation=EXPLANATION
   | WITH PERIPHERY periphery=NAME
   | CONTOUR contour=NAME ( WITH PERIPHERY )?
   | LARROW table=NAME DOT attr=NAME
   ;

formatEncoding
   : FORMAT 
   (
     FREE
   | FIX WITH
     LINESIZE EQUAL lineSize = POSNUMBER COMMA
     TIDSIZE EQUAL tidSize = POSNUMBER
   )
   SEMI
   CODE
   font?
   BLANK EQUAL ( DEFAULT | blankcode=code) COMMA
   UNDEFINED EQUAL (DEFAULT | undefinedcode=code) COMMA
   CONTINUE EQUAL (DEFAULT | continuecode=code) SEMI
   TID EQUAL (I16 | I32 | ANY | EXPLANATION) SEMI
   END DOT
   ;

font
   : FONT EQUAL expl=EXPLANATION SEMI
   ;

code
   : POSNUMBER
   | HEXNUMBER
   ;

decimal
	: DEC
	| POSNUMBER
	| NUMBER
	;