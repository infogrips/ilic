#include "Ili2Input.h"
#include "Ili2Input_helper.h"
#include "InterlisModel.h"
#include "../parser/IliParserErrorListener.h"
#include "../parser/generated/Ili2Lexer.cpp"
#include "../parser/generated/Ili2Parser.cpp"
#include "../../metamodel/MetaModelInput.h"
#include "../../util/Logger.h"

using namespace input;
using namespace parser;
using namespace metamodel;

string input_file = "";

// general methods

/*
antlrcpp::Any::Base::~Base()
{
   // to satisfy microsoft linker
}
*/

static antlr4::ANTLRInputStream open_inputstream(string input,ifstream &stream)
{
   if (input == "INTERLIS") {
      return antlr4::ANTLRInputStream(getInterlisModel23());
   }
   else {
      stream.open(input);
      return antlr4::ANTLRInputStream(stream);
   }
}

static void close_inputstream(string input,ifstream &stream)
{
   if (input != "INTERLIS") {
      stream.close();
   }
}

void input::parseIli2(string ilifile)
{

   try {

      input_file = ilifile;

      // open input
      ifstream stream;
      antlr4::ANTLRInputStream inputstream = open_inputstream(ilifile,stream);
      
      Log.debug("creating ili2 lexer ...");
      lexer::Ili2Lexer ili2lexer(&inputstream);
      antlr4::CommonTokenStream tokens(&ili2lexer);

      Log.debug("creating ili2 parser ...");
      parser::Ili2Parser ili2parser(&tokens);
      ili2parser.removeErrorListeners();
      ili2parser.addErrorListener(new parser::IliParserErrorListener());
      parser::Ili2Parser::Interlis2DefContext *ili2d = ili2parser.interlis2Def();

      Log.debug("ili2 building meta model ...");
      input::Ili2Input ili2input;
      ili2input.visit(ili2d);

      close_inputstream(ilifile,stream);

   }
   catch (exception e) {
      Log.setLevel(1);
      Log.internal_error(string(e.what()),1);
   }
   
}

// parser visitor interface

antlrcpp::Any Ili2Input::visitInterlis2Def(Ili2Parser::Interlis2DefContext *ctx)
{

   /* interlis2Def
   : INTERLIS 
     ({ili23}? iliversion=ILI23 
     |{ili24}? iliversion=ILI24
     )
     SEMI (modelDef)* EOF
   */

   iliversion = ctx->iliversion->getText();
   debug(ctx,">>> visitInterlis2Def(" + iliversion + ")");
   Log.incNestLevel();
   visitChildren(ctx);
   Log.decNestLevel();
   debug(ctx,"<<< visitInterlis2Def(" + iliversion + ")");
   return nullptr;

}

antlrcpp::Any Ili2Input::visitMetaDataBasketRef(parser::Ili2Parser::MetaDataBasketRefContext *ctx)
{
   debug(ctx,">>> visitMetaDataBasketRef()");
   // to do !!!
   debug(ctx,"<<< visitMetaDataBasketRef()");
   return nullptr;
}

antlrcpp::Any Ili2Input::visitParameterDef(parser::Ili2Parser::ParameterDefContext *ctx)
{
   debug(ctx,">>> visitParameterDef()");
   // to do !!!
   debug(ctx,"<<< visitParameterDef()");
   return nullptr;
}
   
antlrcpp::Any Ili2Input::visitMetaDataBasketDef(parser::Ili2Parser::MetaDataBasketDefContext *ctx)
{

   /* metaDataBasketDef
   : (SIGN | REFSYSTEM) BASKET basketname=NAME
     (LPAREN FINAL RPAREN)?
     (EXTENDS metaDataBasketRef)?
     TILDE path 
     (OBJECTS OF classname=NAME COLON metabjectname=NAME 
                         ( COMMA metaobjectname=NAME)*)* SEMI
   */

   debug(ctx,">>> visitMetaDataBasketDef()");
   // ... to do !!!
   debug(ctx,"<<< visitMetaDataBasketDef()");

   return nullptr;

}

antlrcpp::Any Ili2Input::visitRunTimeParameterDef(parser::Ili2Parser::RunTimeParameterDefContext *ctx)
{

   /*
   runTimeParameterDef
   : PARAMETER (runtimeparametername=NAME COLON attrTypeDef SEMI)*
   */

   debug(ctx,">>> visitRunTimeParameterDef()");
   // ... to do !!!
   debug(ctx,"<<< visitRunTimeParameterDef()");

   return nullptr;

}
