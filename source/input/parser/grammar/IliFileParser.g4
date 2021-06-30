//
//  start of grammar
//

parser grammar IliFileParser;

options
{
   tokenVocab = IliFileLexer;
}

iliFile
   : version
     (modelName | translationOf | imports | . )*?
	;
   
version
   : (INTERLIS majorversion=DIGIT DOT minorversion=DIGIT)
   | (TRANSFER transfername=NAME SEMI)
   ;
   
modelName
   : MODEL modelname=NAME
   ;
   
translationOf
   : TRANSLATION OF modelname=NAME
   ;
   
imports
   : IMPORTS modelImport (COMMA modelImport)*
   ;
   
modelImport
   : UNQUALIFIED?
   ( modelname=NAME
   | modelname=INTERLIS
   )
   ;
