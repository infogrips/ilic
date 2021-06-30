
// Generated from ..\..\..\..\source\c\ilic\input\parser\generated\Ili2Parser.g4 by ANTLR 4.7.1


#include "Ili2ParserVisitor.h"

#include "Ili2Parser.h"


using namespace antlrcpp;
using namespace parser;
using namespace antlr4;

Ili2Parser::Ili2Parser(TokenStream *input) : Parser(input) {
  _interpreter = new atn::ParserATNSimulator(this, _atn, _decisionToDFA, _sharedContextCache);
}

Ili2Parser::~Ili2Parser() {
  delete _interpreter;
}

std::string Ili2Parser::getGrammarFileName() const {
  return "Ili2Parser.g4";
}

const std::vector<std::string>& Ili2Parser::getRuleNames() const {
  return _ruleNames;
}

dfa::Vocabulary& Ili2Parser::getVocabulary() const {
  return _vocabulary;
}


//----------------- DecimalContext ------------------------------------------------------------------

Ili2Parser::DecimalContext::DecimalContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* Ili2Parser::DecimalContext::DEC() {
  return getToken(Ili2Parser::DEC, 0);
}

tree::TerminalNode* Ili2Parser::DecimalContext::POSNUMBER() {
  return getToken(Ili2Parser::POSNUMBER, 0);
}

tree::TerminalNode* Ili2Parser::DecimalContext::NUMBER() {
  return getToken(Ili2Parser::NUMBER, 0);
}


size_t Ili2Parser::DecimalContext::getRuleIndex() const {
  return Ili2Parser::RuleDecimal;
}

antlrcpp::Any Ili2Parser::DecimalContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<Ili2ParserVisitor*>(visitor))
    return parserVisitor->visitDecimal(this);
  else
    return visitor->visitChildren(this);
}

Ili2Parser::DecimalContext* Ili2Parser::decimal() {
  DecimalContext *_localctx = _tracker.createInstance<DecimalContext>(_ctx, getState());
  enterRule(_localctx, 0, Ili2Parser::RuleDecimal);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(222);
    _la = _input->LA(1);
    if (!(((((_la - 182) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 182)) & ((1ULL << (Ili2Parser::POSNUMBER - 182))
      | (1ULL << (Ili2Parser::NUMBER - 182))
      | (1ULL << (Ili2Parser::DEC - 182)))) != 0))) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- PathContext ------------------------------------------------------------------

Ili2Parser::PathContext::PathContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* Ili2Parser::PathContext::INTERLIS() {
  return getToken(Ili2Parser::INTERLIS, 0);
}

std::vector<tree::TerminalNode *> Ili2Parser::PathContext::NAME() {
  return getTokens(Ili2Parser::NAME);
}

tree::TerminalNode* Ili2Parser::PathContext::NAME(size_t i) {
  return getToken(Ili2Parser::NAME, i);
}

std::vector<tree::TerminalNode *> Ili2Parser::PathContext::DOT() {
  return getTokens(Ili2Parser::DOT);
}

tree::TerminalNode* Ili2Parser::PathContext::DOT(size_t i) {
  return getToken(Ili2Parser::DOT, i);
}


size_t Ili2Parser::PathContext::getRuleIndex() const {
  return Ili2Parser::RulePath;
}

antlrcpp::Any Ili2Parser::PathContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<Ili2ParserVisitor*>(visitor))
    return parserVisitor->visitPath(this);
  else
    return visitor->visitChildren(this);
}

Ili2Parser::PathContext* Ili2Parser::path() {
  PathContext *_localctx = _tracker.createInstance<PathContext>(_ctx, getState());
  enterRule(_localctx, 2, Ili2Parser::RulePath);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(224);
    _la = _input->LA(1);
    if (!(_la == Ili2Parser::INTERLIS || _la == Ili2Parser::NAME)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
    setState(229);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 0, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(225);
        match(Ili2Parser::DOT);
        setState(226);
        match(Ili2Parser::NAME); 
      }
      setState(231);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 0, _ctx);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Interlis2DefContext ------------------------------------------------------------------

Ili2Parser::Interlis2DefContext::Interlis2DefContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* Ili2Parser::Interlis2DefContext::INTERLIS() {
  return getToken(Ili2Parser::INTERLIS, 0);
}

tree::TerminalNode* Ili2Parser::Interlis2DefContext::SEMI() {
  return getToken(Ili2Parser::SEMI, 0);
}

tree::TerminalNode* Ili2Parser::Interlis2DefContext::EOF() {
  return getToken(Ili2Parser::EOF, 0);
}

tree::TerminalNode* Ili2Parser::Interlis2DefContext::ILI23() {
  return getToken(Ili2Parser::ILI23, 0);
}

tree::TerminalNode* Ili2Parser::Interlis2DefContext::ILI24() {
  return getToken(Ili2Parser::ILI24, 0);
}

std::vector<Ili2Parser::ModelDefContext *> Ili2Parser::Interlis2DefContext::modelDef() {
  return getRuleContexts<Ili2Parser::ModelDefContext>();
}

Ili2Parser::ModelDefContext* Ili2Parser::Interlis2DefContext::modelDef(size_t i) {
  return getRuleContext<Ili2Parser::ModelDefContext>(i);
}


size_t Ili2Parser::Interlis2DefContext::getRuleIndex() const {
  return Ili2Parser::RuleInterlis2Def;
}

antlrcpp::Any Ili2Parser::Interlis2DefContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<Ili2ParserVisitor*>(visitor))
    return parserVisitor->visitInterlis2Def(this);
  else
    return visitor->visitChildren(this);
}

Ili2Parser::Interlis2DefContext* Ili2Parser::interlis2Def() {
  Interlis2DefContext *_localctx = _tracker.createInstance<Interlis2DefContext>(_ctx, getState());
  enterRule(_localctx, 4, Ili2Parser::RuleInterlis2Def);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(232);
    match(Ili2Parser::INTERLIS);
    setState(237);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case Ili2Parser::ILI23: {
        setState(233);
        dynamic_cast<Interlis2DefContext *>(_localctx)->iliversion = match(Ili2Parser::ILI23);
        ili23=true;
        break;
      }

      case Ili2Parser::ILI24: {
        setState(235);
        dynamic_cast<Interlis2DefContext *>(_localctx)->iliversion = match(Ili2Parser::ILI24);
        ili24=true;
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    setState(239);
    match(Ili2Parser::SEMI);
    setState(243);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << Ili2Parser::CONTRACTED)
      | (1ULL << Ili2Parser::REFSYSTEM)
      | (1ULL << Ili2Parser::SYMBOLOGY)
      | (1ULL << Ili2Parser::TYPE)
      | (1ULL << Ili2Parser::MODEL))) != 0)) {
      setState(240);
      modelDef();
      setState(245);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(246);
    match(Ili2Parser::EOF);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ModelDefContext ------------------------------------------------------------------

Ili2Parser::ModelDefContext::ModelDefContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* Ili2Parser::ModelDefContext::MODEL() {
  return getToken(Ili2Parser::MODEL, 0);
}

tree::TerminalNode* Ili2Parser::ModelDefContext::ATT() {
  return getToken(Ili2Parser::ATT, 0);
}

tree::TerminalNode* Ili2Parser::ModelDefContext::VERSION() {
  return getToken(Ili2Parser::VERSION, 0);
}

tree::TerminalNode* Ili2Parser::ModelDefContext::EQUAL() {
  return getToken(Ili2Parser::EQUAL, 0);
}

tree::TerminalNode* Ili2Parser::ModelDefContext::END() {
  return getToken(Ili2Parser::END, 0);
}

tree::TerminalNode* Ili2Parser::ModelDefContext::DOT() {
  return getToken(Ili2Parser::DOT, 0);
}

std::vector<tree::TerminalNode *> Ili2Parser::ModelDefContext::NAME() {
  return getTokens(Ili2Parser::NAME);
}

tree::TerminalNode* Ili2Parser::ModelDefContext::NAME(size_t i) {
  return getToken(Ili2Parser::NAME, i);
}

std::vector<tree::TerminalNode *> Ili2Parser::ModelDefContext::STRING() {
  return getTokens(Ili2Parser::STRING);
}

tree::TerminalNode* Ili2Parser::ModelDefContext::STRING(size_t i) {
  return getToken(Ili2Parser::STRING, i);
}

tree::TerminalNode* Ili2Parser::ModelDefContext::LPAREN() {
  return getToken(Ili2Parser::LPAREN, 0);
}

tree::TerminalNode* Ili2Parser::ModelDefContext::RPAREN() {
  return getToken(Ili2Parser::RPAREN, 0);
}

tree::TerminalNode* Ili2Parser::ModelDefContext::NOINCREMENTALTRANSFER() {
  return getToken(Ili2Parser::NOINCREMENTALTRANSFER, 0);
}

tree::TerminalNode* Ili2Parser::ModelDefContext::TRANSLATION() {
  return getToken(Ili2Parser::TRANSLATION, 0);
}

tree::TerminalNode* Ili2Parser::ModelDefContext::OF() {
  return getToken(Ili2Parser::OF, 0);
}

tree::TerminalNode* Ili2Parser::ModelDefContext::LBRACE() {
  return getToken(Ili2Parser::LBRACE, 0);
}

tree::TerminalNode* Ili2Parser::ModelDefContext::RBRACE() {
  return getToken(Ili2Parser::RBRACE, 0);
}

tree::TerminalNode* Ili2Parser::ModelDefContext::CHARSET() {
  return getToken(Ili2Parser::CHARSET, 0);
}

std::vector<tree::TerminalNode *> Ili2Parser::ModelDefContext::SEMI() {
  return getTokens(Ili2Parser::SEMI);
}

tree::TerminalNode* Ili2Parser::ModelDefContext::SEMI(size_t i) {
  return getToken(Ili2Parser::SEMI, i);
}

tree::TerminalNode* Ili2Parser::ModelDefContext::XMLNS() {
  return getToken(Ili2Parser::XMLNS, 0);
}

std::vector<Ili2Parser::ImportDefContext *> Ili2Parser::ModelDefContext::importDef() {
  return getRuleContexts<Ili2Parser::ImportDefContext>();
}

Ili2Parser::ImportDefContext* Ili2Parser::ModelDefContext::importDef(size_t i) {
  return getRuleContext<Ili2Parser::ImportDefContext>(i);
}

std::vector<Ili2Parser::MetaDataBasketDefContext *> Ili2Parser::ModelDefContext::metaDataBasketDef() {
  return getRuleContexts<Ili2Parser::MetaDataBasketDefContext>();
}

Ili2Parser::MetaDataBasketDefContext* Ili2Parser::ModelDefContext::metaDataBasketDef(size_t i) {
  return getRuleContext<Ili2Parser::MetaDataBasketDefContext>(i);
}

std::vector<Ili2Parser::UnitDeclContext *> Ili2Parser::ModelDefContext::unitDecl() {
  return getRuleContexts<Ili2Parser::UnitDeclContext>();
}

Ili2Parser::UnitDeclContext* Ili2Parser::ModelDefContext::unitDecl(size_t i) {
  return getRuleContext<Ili2Parser::UnitDeclContext>(i);
}

std::vector<Ili2Parser::FunctionDefContext *> Ili2Parser::ModelDefContext::functionDef() {
  return getRuleContexts<Ili2Parser::FunctionDefContext>();
}

Ili2Parser::FunctionDefContext* Ili2Parser::ModelDefContext::functionDef(size_t i) {
  return getRuleContext<Ili2Parser::FunctionDefContext>(i);
}

std::vector<Ili2Parser::LineFormTypeDefContext *> Ili2Parser::ModelDefContext::lineFormTypeDef() {
  return getRuleContexts<Ili2Parser::LineFormTypeDefContext>();
}

Ili2Parser::LineFormTypeDefContext* Ili2Parser::ModelDefContext::lineFormTypeDef(size_t i) {
  return getRuleContext<Ili2Parser::LineFormTypeDefContext>(i);
}

std::vector<Ili2Parser::DomainDeclContext *> Ili2Parser::ModelDefContext::domainDecl() {
  return getRuleContexts<Ili2Parser::DomainDeclContext>();
}

Ili2Parser::DomainDeclContext* Ili2Parser::ModelDefContext::domainDecl(size_t i) {
  return getRuleContext<Ili2Parser::DomainDeclContext>(i);
}

std::vector<Ili2Parser::ContextDefContext *> Ili2Parser::ModelDefContext::contextDef() {
  return getRuleContexts<Ili2Parser::ContextDefContext>();
}

Ili2Parser::ContextDefContext* Ili2Parser::ModelDefContext::contextDef(size_t i) {
  return getRuleContext<Ili2Parser::ContextDefContext>(i);
}

std::vector<Ili2Parser::RunTimeParameterDefContext *> Ili2Parser::ModelDefContext::runTimeParameterDef() {
  return getRuleContexts<Ili2Parser::RunTimeParameterDefContext>();
}

Ili2Parser::RunTimeParameterDefContext* Ili2Parser::ModelDefContext::runTimeParameterDef(size_t i) {
  return getRuleContext<Ili2Parser::RunTimeParameterDefContext>(i);
}

std::vector<Ili2Parser::ClassDefContext *> Ili2Parser::ModelDefContext::classDef() {
  return getRuleContexts<Ili2Parser::ClassDefContext>();
}

Ili2Parser::ClassDefContext* Ili2Parser::ModelDefContext::classDef(size_t i) {
  return getRuleContext<Ili2Parser::ClassDefContext>(i);
}

std::vector<Ili2Parser::StructureDefContext *> Ili2Parser::ModelDefContext::structureDef() {
  return getRuleContexts<Ili2Parser::StructureDefContext>();
}

Ili2Parser::StructureDefContext* Ili2Parser::ModelDefContext::structureDef(size_t i) {
  return getRuleContext<Ili2Parser::StructureDefContext>(i);
}

std::vector<Ili2Parser::TopicDefContext *> Ili2Parser::ModelDefContext::topicDef() {
  return getRuleContexts<Ili2Parser::TopicDefContext>();
}

Ili2Parser::TopicDefContext* Ili2Parser::ModelDefContext::topicDef(size_t i) {
  return getRuleContext<Ili2Parser::TopicDefContext>(i);
}

tree::TerminalNode* Ili2Parser::ModelDefContext::CONTRACTED() {
  return getToken(Ili2Parser::CONTRACTED, 0);
}

tree::TerminalNode* Ili2Parser::ModelDefContext::REFSYSTEM() {
  return getToken(Ili2Parser::REFSYSTEM, 0);
}

tree::TerminalNode* Ili2Parser::ModelDefContext::SYMBOLOGY() {
  return getToken(Ili2Parser::SYMBOLOGY, 0);
}

tree::TerminalNode* Ili2Parser::ModelDefContext::TYPE() {
  return getToken(Ili2Parser::TYPE, 0);
}

tree::TerminalNode* Ili2Parser::ModelDefContext::EXPLANATION() {
  return getToken(Ili2Parser::EXPLANATION, 0);
}


size_t Ili2Parser::ModelDefContext::getRuleIndex() const {
  return Ili2Parser::RuleModelDef;
}

antlrcpp::Any Ili2Parser::ModelDefContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<Ili2ParserVisitor*>(visitor))
    return parserVisitor->visitModelDef(this);
  else
    return visitor->visitChildren(this);
}

Ili2Parser::ModelDefContext* Ili2Parser::modelDef() {
  ModelDefContext *_localctx = _tracker.createInstance<ModelDefContext>(_ctx, getState());
  enterRule(_localctx, 6, Ili2Parser::RuleModelDef);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(249);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == Ili2Parser::CONTRACTED) {
      setState(248);
      dynamic_cast<ModelDefContext *>(_localctx)->contracted = match(Ili2Parser::CONTRACTED);
    }
    setState(254);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case Ili2Parser::REFSYSTEM: {
        setState(251);
        dynamic_cast<ModelDefContext *>(_localctx)->refsystemmodel = match(Ili2Parser::REFSYSTEM);
        break;
      }

      case Ili2Parser::SYMBOLOGY: {
        setState(252);
        dynamic_cast<ModelDefContext *>(_localctx)->symbologymodel = match(Ili2Parser::SYMBOLOGY);
        break;
      }

      case Ili2Parser::TYPE: {
        setState(253);
        dynamic_cast<ModelDefContext *>(_localctx)->typemodel = match(Ili2Parser::TYPE);
        break;
      }

      case Ili2Parser::MODEL: {
        break;
      }

    default:
      break;
    }
    setState(256);
    match(Ili2Parser::MODEL);
    setState(257);
    dynamic_cast<ModelDefContext *>(_localctx)->modelname1 = match(Ili2Parser::NAME);
    setState(261);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 5, _ctx)) {
    case 1: {
      setState(258);
      match(Ili2Parser::LPAREN);
      setState(259);
      dynamic_cast<ModelDefContext *>(_localctx)->language = match(Ili2Parser::NAME);
      setState(260);
      match(Ili2Parser::RPAREN);
      break;
    }

    }
    setState(265);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 6, _ctx)) {
    case 1: {
      setState(263);

      if (!(ili24)) throw FailedPredicateException(this, "ili24");
      setState(264);
      match(Ili2Parser::NOINCREMENTALTRANSFER);
      break;
    }

    }
    setState(267);
    match(Ili2Parser::ATT);
    setState(268);
    dynamic_cast<ModelDefContext *>(_localctx)->issuerurl = match(Ili2Parser::STRING);
    setState(269);
    match(Ili2Parser::VERSION);
    setState(270);
    dynamic_cast<ModelDefContext *>(_localctx)->modelversion = match(Ili2Parser::STRING);
    setState(272);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == Ili2Parser::EXPLANATION) {
      setState(271);
      dynamic_cast<ModelDefContext *>(_localctx)->modelversion_expl = match(Ili2Parser::EXPLANATION);
    }
    setState(280);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == Ili2Parser::TRANSLATION) {
      setState(274);
      match(Ili2Parser::TRANSLATION);
      setState(275);
      match(Ili2Parser::OF);
      setState(276);
      dynamic_cast<ModelDefContext *>(_localctx)->translationOf = match(Ili2Parser::NAME);
      setState(277);
      match(Ili2Parser::LBRACE);
      setState(278);
      dynamic_cast<ModelDefContext *>(_localctx)->translationOfVersion = match(Ili2Parser::STRING);
      setState(279);
      match(Ili2Parser::RBRACE);
    }
    setState(282);
    match(Ili2Parser::EQUAL);
    setState(287);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 9, _ctx)) {
    case 1: {
      setState(283);

      if (!(ili24)) throw FailedPredicateException(this, "ili24");
      setState(284);
      match(Ili2Parser::CHARSET);
      setState(285);
      dynamic_cast<ModelDefContext *>(_localctx)->iananame = match(Ili2Parser::STRING);
      setState(286);
      match(Ili2Parser::SEMI);
      break;
    }

    }
    setState(293);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 10, _ctx)) {
    case 1: {
      setState(289);

      if (!(ili24)) throw FailedPredicateException(this, "ili24");
      setState(290);
      match(Ili2Parser::XMLNS);
      setState(291);
      dynamic_cast<ModelDefContext *>(_localctx)->xmlns = match(Ili2Parser::STRING);
      setState(292);
      match(Ili2Parser::SEMI);
      break;
    }

    }
    setState(298);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 11, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(295);
        importDef(); 
      }
      setState(300);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 11, _ctx);
    }
    setState(314);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 13, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(312);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 12, _ctx)) {
        case 1: {
          setState(301);
          metaDataBasketDef();
          break;
        }

        case 2: {
          setState(302);
          unitDecl();
          break;
        }

        case 3: {
          setState(303);
          functionDef();
          break;
        }

        case 4: {
          setState(304);
          lineFormTypeDef();
          break;
        }

        case 5: {
          setState(305);
          domainDecl();
          break;
        }

        case 6: {
          setState(306);

          if (!(ili24)) throw FailedPredicateException(this, "ili24");
          setState(307);
          contextDef();
          break;
        }

        case 7: {
          setState(308);
          runTimeParameterDef();
          break;
        }

        case 8: {
          setState(309);
          classDef();
          break;
        }

        case 9: {
          setState(310);
          structureDef();
          break;
        }

        case 10: {
          setState(311);
          topicDef();
          break;
        }

        } 
      }
      setState(316);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 13, _ctx);
    }
    setState(317);
    match(Ili2Parser::END);
    setState(318);
    dynamic_cast<ModelDefContext *>(_localctx)->modelname2 = match(Ili2Parser::NAME);
    setState(319);
    match(Ili2Parser::DOT);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ImportDefContext ------------------------------------------------------------------

Ili2Parser::ImportDefContext::ImportDefContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* Ili2Parser::ImportDefContext::IMPORTS() {
  return getToken(Ili2Parser::IMPORTS, 0);
}

std::vector<Ili2Parser::ImportingContext *> Ili2Parser::ImportDefContext::importing() {
  return getRuleContexts<Ili2Parser::ImportingContext>();
}

Ili2Parser::ImportingContext* Ili2Parser::ImportDefContext::importing(size_t i) {
  return getRuleContext<Ili2Parser::ImportingContext>(i);
}

tree::TerminalNode* Ili2Parser::ImportDefContext::SEMI() {
  return getToken(Ili2Parser::SEMI, 0);
}

std::vector<tree::TerminalNode *> Ili2Parser::ImportDefContext::COMMA() {
  return getTokens(Ili2Parser::COMMA);
}

tree::TerminalNode* Ili2Parser::ImportDefContext::COMMA(size_t i) {
  return getToken(Ili2Parser::COMMA, i);
}


size_t Ili2Parser::ImportDefContext::getRuleIndex() const {
  return Ili2Parser::RuleImportDef;
}

antlrcpp::Any Ili2Parser::ImportDefContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<Ili2ParserVisitor*>(visitor))
    return parserVisitor->visitImportDef(this);
  else
    return visitor->visitChildren(this);
}

Ili2Parser::ImportDefContext* Ili2Parser::importDef() {
  ImportDefContext *_localctx = _tracker.createInstance<ImportDefContext>(_ctx, getState());
  enterRule(_localctx, 8, Ili2Parser::RuleImportDef);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(321);
    match(Ili2Parser::IMPORTS);
    setState(322);
    importing();
    setState(327);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == Ili2Parser::COMMA) {
      setState(323);
      match(Ili2Parser::COMMA);
      setState(324);
      importing();
      setState(329);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(330);
    match(Ili2Parser::SEMI);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ImportingContext ------------------------------------------------------------------

Ili2Parser::ImportingContext::ImportingContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* Ili2Parser::ImportingContext::UNQUALIFIED() {
  return getToken(Ili2Parser::UNQUALIFIED, 0);
}

Ili2Parser::PathContext* Ili2Parser::ImportingContext::path() {
  return getRuleContext<Ili2Parser::PathContext>(0);
}


size_t Ili2Parser::ImportingContext::getRuleIndex() const {
  return Ili2Parser::RuleImporting;
}

antlrcpp::Any Ili2Parser::ImportingContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<Ili2ParserVisitor*>(visitor))
    return parserVisitor->visitImporting(this);
  else
    return visitor->visitChildren(this);
}

Ili2Parser::ImportingContext* Ili2Parser::importing() {
  ImportingContext *_localctx = _tracker.createInstance<ImportingContext>(_ctx, getState());
  enterRule(_localctx, 10, Ili2Parser::RuleImporting);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(333);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == Ili2Parser::UNQUALIFIED) {
      setState(332);
      match(Ili2Parser::UNQUALIFIED);
    }

    setState(335);
    dynamic_cast<ImportingContext *>(_localctx)->importname = path();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- TopicDefContext ------------------------------------------------------------------

Ili2Parser::TopicDefContext::TopicDefContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* Ili2Parser::TopicDefContext::TOPIC() {
  return getToken(Ili2Parser::TOPIC, 0);
}

tree::TerminalNode* Ili2Parser::TopicDefContext::EQUAL() {
  return getToken(Ili2Parser::EQUAL, 0);
}

tree::TerminalNode* Ili2Parser::TopicDefContext::END() {
  return getToken(Ili2Parser::END, 0);
}

std::vector<tree::TerminalNode *> Ili2Parser::TopicDefContext::SEMI() {
  return getTokens(Ili2Parser::SEMI);
}

tree::TerminalNode* Ili2Parser::TopicDefContext::SEMI(size_t i) {
  return getToken(Ili2Parser::SEMI, i);
}

std::vector<tree::TerminalNode *> Ili2Parser::TopicDefContext::NAME() {
  return getTokens(Ili2Parser::NAME);
}

tree::TerminalNode* Ili2Parser::TopicDefContext::NAME(size_t i) {
  return getToken(Ili2Parser::NAME, i);
}

tree::TerminalNode* Ili2Parser::TopicDefContext::VIEW() {
  return getToken(Ili2Parser::VIEW, 0);
}

Ili2Parser::PropertiesContext* Ili2Parser::TopicDefContext::properties() {
  return getRuleContext<Ili2Parser::PropertiesContext>(0);
}

tree::TerminalNode* Ili2Parser::TopicDefContext::EXTENDS() {
  return getToken(Ili2Parser::EXTENDS, 0);
}

tree::TerminalNode* Ili2Parser::TopicDefContext::BASKET() {
  return getToken(Ili2Parser::BASKET, 0);
}

std::vector<tree::TerminalNode *> Ili2Parser::TopicDefContext::OID() {
  return getTokens(Ili2Parser::OID);
}

tree::TerminalNode* Ili2Parser::TopicDefContext::OID(size_t i) {
  return getToken(Ili2Parser::OID, i);
}

std::vector<tree::TerminalNode *> Ili2Parser::TopicDefContext::AS() {
  return getTokens(Ili2Parser::AS);
}

tree::TerminalNode* Ili2Parser::TopicDefContext::AS(size_t i) {
  return getToken(Ili2Parser::AS, i);
}

std::vector<tree::TerminalNode *> Ili2Parser::TopicDefContext::DEPENDS() {
  return getTokens(Ili2Parser::DEPENDS);
}

tree::TerminalNode* Ili2Parser::TopicDefContext::DEPENDS(size_t i) {
  return getToken(Ili2Parser::DEPENDS, i);
}

std::vector<tree::TerminalNode *> Ili2Parser::TopicDefContext::ON() {
  return getTokens(Ili2Parser::ON);
}

tree::TerminalNode* Ili2Parser::TopicDefContext::ON(size_t i) {
  return getToken(Ili2Parser::ON, i);
}

tree::TerminalNode* Ili2Parser::TopicDefContext::DEFERRED() {
  return getToken(Ili2Parser::DEFERRED, 0);
}

tree::TerminalNode* Ili2Parser::TopicDefContext::GENERICS() {
  return getToken(Ili2Parser::GENERICS, 0);
}

std::vector<Ili2Parser::MetaDataBasketDefContext *> Ili2Parser::TopicDefContext::metaDataBasketDef() {
  return getRuleContexts<Ili2Parser::MetaDataBasketDefContext>();
}

Ili2Parser::MetaDataBasketDefContext* Ili2Parser::TopicDefContext::metaDataBasketDef(size_t i) {
  return getRuleContext<Ili2Parser::MetaDataBasketDefContext>(i);
}

std::vector<Ili2Parser::UnitDeclContext *> Ili2Parser::TopicDefContext::unitDecl() {
  return getRuleContexts<Ili2Parser::UnitDeclContext>();
}

Ili2Parser::UnitDeclContext* Ili2Parser::TopicDefContext::unitDecl(size_t i) {
  return getRuleContext<Ili2Parser::UnitDeclContext>(i);
}

std::vector<Ili2Parser::FunctionDefContext *> Ili2Parser::TopicDefContext::functionDef() {
  return getRuleContexts<Ili2Parser::FunctionDefContext>();
}

Ili2Parser::FunctionDefContext* Ili2Parser::TopicDefContext::functionDef(size_t i) {
  return getRuleContext<Ili2Parser::FunctionDefContext>(i);
}

std::vector<Ili2Parser::DomainDeclContext *> Ili2Parser::TopicDefContext::domainDecl() {
  return getRuleContexts<Ili2Parser::DomainDeclContext>();
}

Ili2Parser::DomainDeclContext* Ili2Parser::TopicDefContext::domainDecl(size_t i) {
  return getRuleContext<Ili2Parser::DomainDeclContext>(i);
}

std::vector<Ili2Parser::ClassDefContext *> Ili2Parser::TopicDefContext::classDef() {
  return getRuleContexts<Ili2Parser::ClassDefContext>();
}

Ili2Parser::ClassDefContext* Ili2Parser::TopicDefContext::classDef(size_t i) {
  return getRuleContext<Ili2Parser::ClassDefContext>(i);
}

std::vector<Ili2Parser::StructureDefContext *> Ili2Parser::TopicDefContext::structureDef() {
  return getRuleContexts<Ili2Parser::StructureDefContext>();
}

Ili2Parser::StructureDefContext* Ili2Parser::TopicDefContext::structureDef(size_t i) {
  return getRuleContext<Ili2Parser::StructureDefContext>(i);
}

std::vector<Ili2Parser::AssociationDefContext *> Ili2Parser::TopicDefContext::associationDef() {
  return getRuleContexts<Ili2Parser::AssociationDefContext>();
}

Ili2Parser::AssociationDefContext* Ili2Parser::TopicDefContext::associationDef(size_t i) {
  return getRuleContext<Ili2Parser::AssociationDefContext>(i);
}

std::vector<Ili2Parser::ConstraintsDefContext *> Ili2Parser::TopicDefContext::constraintsDef() {
  return getRuleContexts<Ili2Parser::ConstraintsDefContext>();
}

Ili2Parser::ConstraintsDefContext* Ili2Parser::TopicDefContext::constraintsDef(size_t i) {
  return getRuleContext<Ili2Parser::ConstraintsDefContext>(i);
}

std::vector<Ili2Parser::ViewDefContext *> Ili2Parser::TopicDefContext::viewDef() {
  return getRuleContexts<Ili2Parser::ViewDefContext>();
}

Ili2Parser::ViewDefContext* Ili2Parser::TopicDefContext::viewDef(size_t i) {
  return getRuleContext<Ili2Parser::ViewDefContext>(i);
}

std::vector<Ili2Parser::GraphicDefContext *> Ili2Parser::TopicDefContext::graphicDef() {
  return getRuleContexts<Ili2Parser::GraphicDefContext>();
}

Ili2Parser::GraphicDefContext* Ili2Parser::TopicDefContext::graphicDef(size_t i) {
  return getRuleContext<Ili2Parser::GraphicDefContext>(i);
}

std::vector<Ili2Parser::PathContext *> Ili2Parser::TopicDefContext::path() {
  return getRuleContexts<Ili2Parser::PathContext>();
}

Ili2Parser::PathContext* Ili2Parser::TopicDefContext::path(size_t i) {
  return getRuleContext<Ili2Parser::PathContext>(i);
}

std::vector<tree::TerminalNode *> Ili2Parser::TopicDefContext::COMMA() {
  return getTokens(Ili2Parser::COMMA);
}

tree::TerminalNode* Ili2Parser::TopicDefContext::COMMA(size_t i) {
  return getToken(Ili2Parser::COMMA, i);
}


size_t Ili2Parser::TopicDefContext::getRuleIndex() const {
  return Ili2Parser::RuleTopicDef;
}

antlrcpp::Any Ili2Parser::TopicDefContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<Ili2ParserVisitor*>(visitor))
    return parserVisitor->visitTopicDef(this);
  else
    return visitor->visitChildren(this);
}

Ili2Parser::TopicDefContext* Ili2Parser::topicDef() {
  TopicDefContext *_localctx = _tracker.createInstance<TopicDefContext>(_ctx, getState());
  enterRule(_localctx, 12, Ili2Parser::RuleTopicDef);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(338);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == Ili2Parser::VIEW) {
      setState(337);
      match(Ili2Parser::VIEW);
    }
    setState(340);
    match(Ili2Parser::TOPIC);
    setState(341);
    dynamic_cast<TopicDefContext *>(_localctx)->topicname1 = match(Ili2Parser::NAME);
    setState(343);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == Ili2Parser::LPAREN) {
      setState(342);
      properties();
    }
    setState(347);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == Ili2Parser::EXTENDS) {
      setState(345);
      match(Ili2Parser::EXTENDS);
      setState(346);
      dynamic_cast<TopicDefContext *>(_localctx)->topicbase = path();
    }
    setState(349);
    match(Ili2Parser::EQUAL);
    setState(356);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 19, _ctx)) {
    case 1: {
      setState(350);
      match(Ili2Parser::BASKET);
      setState(351);
      match(Ili2Parser::OID);
      setState(352);
      match(Ili2Parser::AS);
      setState(353);
      dynamic_cast<TopicDefContext *>(_localctx)->basketOid = path();
      setState(354);
      match(Ili2Parser::SEMI);
      break;
    }

    }
    setState(363);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 20, _ctx)) {
    case 1: {
      setState(358);
      match(Ili2Parser::OID);
      setState(359);
      match(Ili2Parser::AS);
      setState(360);
      dynamic_cast<TopicDefContext *>(_localctx)->topicOid = path();
      setState(361);
      match(Ili2Parser::SEMI);
      break;
    }

    }
    setState(379);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 22, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(365);
        match(Ili2Parser::DEPENDS);
        setState(366);
        match(Ili2Parser::ON);
        setState(367);
        dynamic_cast<TopicDefContext *>(_localctx)->depTopic = path();
        setState(372);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while (_la == Ili2Parser::COMMA) {
          setState(368);
          match(Ili2Parser::COMMA);
          setState(369);
          dynamic_cast<TopicDefContext *>(_localctx)->depTopic = path();
          setState(374);
          _errHandler->sync(this);
          _la = _input->LA(1);
        }
        setState(375);
        match(Ili2Parser::SEMI); 
      }
      setState(381);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 22, _ctx);
    }
    setState(395);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 24, _ctx)) {
    case 1: {
      setState(382);

      if (!(ili24)) throw FailedPredicateException(this, "ili24");
      setState(383);
      match(Ili2Parser::DEFERRED);
      setState(384);
      match(Ili2Parser::GENERICS);
      setState(385);
      dynamic_cast<TopicDefContext *>(_localctx)->genericref = path();
      setState(390);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == Ili2Parser::COMMA) {
        setState(386);
        match(Ili2Parser::COMMA);
        setState(387);
        dynamic_cast<TopicDefContext *>(_localctx)->genericref = path();
        setState(392);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(393);
      match(Ili2Parser::SEMI);
      break;
    }

    }
    setState(409);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << Ili2Parser::REFSYSTEM)
      | (1ULL << Ili2Parser::VIEW)
      | (1ULL << Ili2Parser::CLASS))) != 0) || ((((_la - 81) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 81)) & ((1ULL << (Ili2Parser::STRUCTURE - 81))
      | (1ULL << (Ili2Parser::ASSOCIATION - 81))
      | (1ULL << (Ili2Parser::ILIDOMAIN - 81))
      | (1ULL << (Ili2Parser::UNIT - 81))
      | (1ULL << (Ili2Parser::FUNCTION - 81))
      | (1ULL << (Ili2Parser::SIGN - 81))
      | (1ULL << (Ili2Parser::CONSTRAINTS - 81)))) != 0) || _la == Ili2Parser::GRAPHIC) {
      setState(407);
      _errHandler->sync(this);
      switch (_input->LA(1)) {
        case Ili2Parser::REFSYSTEM:
        case Ili2Parser::SIGN: {
          setState(397);
          metaDataBasketDef();
          break;
        }

        case Ili2Parser::UNIT: {
          setState(398);
          unitDecl();
          break;
        }

        case Ili2Parser::FUNCTION: {
          setState(399);
          functionDef();
          break;
        }

        case Ili2Parser::ILIDOMAIN: {
          setState(400);
          domainDecl();
          break;
        }

        case Ili2Parser::CLASS: {
          setState(401);
          classDef();
          break;
        }

        case Ili2Parser::STRUCTURE: {
          setState(402);
          structureDef();
          break;
        }

        case Ili2Parser::ASSOCIATION: {
          setState(403);
          associationDef();
          break;
        }

        case Ili2Parser::CONSTRAINTS: {
          setState(404);
          constraintsDef();
          break;
        }

        case Ili2Parser::VIEW: {
          setState(405);
          viewDef();
          break;
        }

        case Ili2Parser::GRAPHIC: {
          setState(406);
          graphicDef();
          break;
        }

      default:
        throw NoViableAltException(this);
      }
      setState(411);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(412);
    match(Ili2Parser::END);
    setState(413);
    dynamic_cast<TopicDefContext *>(_localctx)->topicname2 = match(Ili2Parser::NAME);
    setState(414);
    match(Ili2Parser::SEMI);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ClassDefContext ------------------------------------------------------------------

Ili2Parser::ClassDefContext::ClassDefContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* Ili2Parser::ClassDefContext::CLASS() {
  return getToken(Ili2Parser::CLASS, 0);
}

tree::TerminalNode* Ili2Parser::ClassDefContext::EQUAL() {
  return getToken(Ili2Parser::EQUAL, 0);
}

Ili2Parser::ClassOrStructureDefContext* Ili2Parser::ClassDefContext::classOrStructureDef() {
  return getRuleContext<Ili2Parser::ClassOrStructureDefContext>(0);
}

tree::TerminalNode* Ili2Parser::ClassDefContext::END() {
  return getToken(Ili2Parser::END, 0);
}

std::vector<tree::TerminalNode *> Ili2Parser::ClassDefContext::SEMI() {
  return getTokens(Ili2Parser::SEMI);
}

tree::TerminalNode* Ili2Parser::ClassDefContext::SEMI(size_t i) {
  return getToken(Ili2Parser::SEMI, i);
}

std::vector<tree::TerminalNode *> Ili2Parser::ClassDefContext::NAME() {
  return getTokens(Ili2Parser::NAME);
}

tree::TerminalNode* Ili2Parser::ClassDefContext::NAME(size_t i) {
  return getToken(Ili2Parser::NAME, i);
}

Ili2Parser::PropertiesContext* Ili2Parser::ClassDefContext::properties() {
  return getRuleContext<Ili2Parser::PropertiesContext>(0);
}

tree::TerminalNode* Ili2Parser::ClassDefContext::EXTENDS() {
  return getToken(Ili2Parser::EXTENDS, 0);
}

std::vector<Ili2Parser::PathContext *> Ili2Parser::ClassDefContext::path() {
  return getRuleContexts<Ili2Parser::PathContext>();
}

Ili2Parser::PathContext* Ili2Parser::ClassDefContext::path(size_t i) {
  return getRuleContext<Ili2Parser::PathContext>(i);
}

tree::TerminalNode* Ili2Parser::ClassDefContext::OID() {
  return getToken(Ili2Parser::OID, 0);
}

tree::TerminalNode* Ili2Parser::ClassDefContext::AS() {
  return getToken(Ili2Parser::AS, 0);
}

tree::TerminalNode* Ili2Parser::ClassDefContext::NO() {
  return getToken(Ili2Parser::NO, 0);
}


size_t Ili2Parser::ClassDefContext::getRuleIndex() const {
  return Ili2Parser::RuleClassDef;
}

antlrcpp::Any Ili2Parser::ClassDefContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<Ili2ParserVisitor*>(visitor))
    return parserVisitor->visitClassDef(this);
  else
    return visitor->visitChildren(this);
}

Ili2Parser::ClassDefContext* Ili2Parser::classDef() {
  ClassDefContext *_localctx = _tracker.createInstance<ClassDefContext>(_ctx, getState());
  enterRule(_localctx, 14, Ili2Parser::RuleClassDef);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(416);
    match(Ili2Parser::CLASS);
    setState(417);
    dynamic_cast<ClassDefContext *>(_localctx)->classname1 = match(Ili2Parser::NAME);
    setState(419);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == Ili2Parser::LPAREN) {
      setState(418);
      properties();
    }
    setState(423);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == Ili2Parser::EXTENDS) {
      setState(421);
      match(Ili2Parser::EXTENDS);
      setState(422);
      dynamic_cast<ClassDefContext *>(_localctx)->classbase = path();
    }
    setState(425);
    match(Ili2Parser::EQUAL);
    setState(434);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == Ili2Parser::OID

    || _la == Ili2Parser::NO) {
      setState(431);
      _errHandler->sync(this);
      switch (_input->LA(1)) {
        case Ili2Parser::OID: {
          setState(426);
          match(Ili2Parser::OID);
          setState(427);
          match(Ili2Parser::AS);
          setState(428);
          dynamic_cast<ClassDefContext *>(_localctx)->classoid = path();
          break;
        }

        case Ili2Parser::NO: {
          setState(429);
          match(Ili2Parser::NO);
          setState(430);
          match(Ili2Parser::OID);
          break;
        }

      default:
        throw NoViableAltException(this);
      }
      setState(433);
      match(Ili2Parser::SEMI);
    }
    setState(436);
    classOrStructureDef();
    setState(437);
    match(Ili2Parser::END);
    setState(438);
    dynamic_cast<ClassDefContext *>(_localctx)->classname2 = match(Ili2Parser::NAME);
    setState(439);
    match(Ili2Parser::SEMI);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- StructureDefContext ------------------------------------------------------------------

Ili2Parser::StructureDefContext::StructureDefContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* Ili2Parser::StructureDefContext::STRUCTURE() {
  return getToken(Ili2Parser::STRUCTURE, 0);
}

tree::TerminalNode* Ili2Parser::StructureDefContext::EQUAL() {
  return getToken(Ili2Parser::EQUAL, 0);
}

Ili2Parser::ClassOrStructureDefContext* Ili2Parser::StructureDefContext::classOrStructureDef() {
  return getRuleContext<Ili2Parser::ClassOrStructureDefContext>(0);
}

tree::TerminalNode* Ili2Parser::StructureDefContext::END() {
  return getToken(Ili2Parser::END, 0);
}

tree::TerminalNode* Ili2Parser::StructureDefContext::SEMI() {
  return getToken(Ili2Parser::SEMI, 0);
}

std::vector<tree::TerminalNode *> Ili2Parser::StructureDefContext::NAME() {
  return getTokens(Ili2Parser::NAME);
}

tree::TerminalNode* Ili2Parser::StructureDefContext::NAME(size_t i) {
  return getToken(Ili2Parser::NAME, i);
}

Ili2Parser::PropertiesContext* Ili2Parser::StructureDefContext::properties() {
  return getRuleContext<Ili2Parser::PropertiesContext>(0);
}

tree::TerminalNode* Ili2Parser::StructureDefContext::EXTENDS() {
  return getToken(Ili2Parser::EXTENDS, 0);
}

Ili2Parser::PathContext* Ili2Parser::StructureDefContext::path() {
  return getRuleContext<Ili2Parser::PathContext>(0);
}


size_t Ili2Parser::StructureDefContext::getRuleIndex() const {
  return Ili2Parser::RuleStructureDef;
}

antlrcpp::Any Ili2Parser::StructureDefContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<Ili2ParserVisitor*>(visitor))
    return parserVisitor->visitStructureDef(this);
  else
    return visitor->visitChildren(this);
}

Ili2Parser::StructureDefContext* Ili2Parser::structureDef() {
  StructureDefContext *_localctx = _tracker.createInstance<StructureDefContext>(_ctx, getState());
  enterRule(_localctx, 16, Ili2Parser::RuleStructureDef);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(441);
    match(Ili2Parser::STRUCTURE);
    setState(442);
    dynamic_cast<StructureDefContext *>(_localctx)->structurename1 = match(Ili2Parser::NAME);
    setState(444);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == Ili2Parser::LPAREN) {
      setState(443);
      properties();
    }
    setState(448);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == Ili2Parser::EXTENDS) {
      setState(446);
      match(Ili2Parser::EXTENDS);
      setState(447);
      dynamic_cast<StructureDefContext *>(_localctx)->structurebase = path();
    }
    setState(450);
    match(Ili2Parser::EQUAL);
    setState(451);
    classOrStructureDef();
    setState(452);
    match(Ili2Parser::END);
    setState(453);
    dynamic_cast<StructureDefContext *>(_localctx)->structurename2 = match(Ili2Parser::NAME);
    setState(454);
    match(Ili2Parser::SEMI);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ClassOrStructureDefContext ------------------------------------------------------------------

Ili2Parser::ClassOrStructureDefContext::ClassOrStructureDefContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* Ili2Parser::ClassOrStructureDefContext::ATTRIBUTE() {
  return getToken(Ili2Parser::ATTRIBUTE, 0);
}

std::vector<Ili2Parser::AttributeDefContext *> Ili2Parser::ClassOrStructureDefContext::attributeDef() {
  return getRuleContexts<Ili2Parser::AttributeDefContext>();
}

Ili2Parser::AttributeDefContext* Ili2Parser::ClassOrStructureDefContext::attributeDef(size_t i) {
  return getRuleContext<Ili2Parser::AttributeDefContext>(i);
}

std::vector<Ili2Parser::ConstraintDefContext *> Ili2Parser::ClassOrStructureDefContext::constraintDef() {
  return getRuleContexts<Ili2Parser::ConstraintDefContext>();
}

Ili2Parser::ConstraintDefContext* Ili2Parser::ClassOrStructureDefContext::constraintDef(size_t i) {
  return getRuleContext<Ili2Parser::ConstraintDefContext>(i);
}

tree::TerminalNode* Ili2Parser::ClassOrStructureDefContext::PARAMETER() {
  return getToken(Ili2Parser::PARAMETER, 0);
}

std::vector<Ili2Parser::ParameterDefContext *> Ili2Parser::ClassOrStructureDefContext::parameterDef() {
  return getRuleContexts<Ili2Parser::ParameterDefContext>();
}

Ili2Parser::ParameterDefContext* Ili2Parser::ClassOrStructureDefContext::parameterDef(size_t i) {
  return getRuleContext<Ili2Parser::ParameterDefContext>(i);
}


size_t Ili2Parser::ClassOrStructureDefContext::getRuleIndex() const {
  return Ili2Parser::RuleClassOrStructureDef;
}

antlrcpp::Any Ili2Parser::ClassOrStructureDefContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<Ili2ParserVisitor*>(visitor))
    return parserVisitor->visitClassOrStructureDef(this);
  else
    return visitor->visitChildren(this);
}

Ili2Parser::ClassOrStructureDefContext* Ili2Parser::classOrStructureDef() {
  ClassOrStructureDefContext *_localctx = _tracker.createInstance<ClassOrStructureDefContext>(_ctx, getState());
  enterRule(_localctx, 18, Ili2Parser::RuleClassOrStructureDef);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(457);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == Ili2Parser::ATTRIBUTE) {
      setState(456);
      match(Ili2Parser::ATTRIBUTE);
    }
    setState(462);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == Ili2Parser::CONTINUOUS

    || _la == Ili2Parser::SUBDIVISION || _la == Ili2Parser::NAME) {
      setState(459);
      attributeDef();
      setState(464);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(468);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (((((_la - 83) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 83)) & ((1ULL << (Ili2Parser::MANDATORY - 83))
      | (1ULL << (Ili2Parser::CONSTRAINT - 83))
      | (1ULL << (Ili2Parser::EXISTENCE - 83)))) != 0) || _la == Ili2Parser::UNIQUE

    || _la == Ili2Parser::SET) {
      setState(465);
      constraintDef();
      setState(470);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(478);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == Ili2Parser::PARAMETER) {
      setState(471);
      match(Ili2Parser::PARAMETER);
      setState(475);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == Ili2Parser::NAME) {
        setState(472);
        parameterDef();
        setState(477);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- AttributeDefContext ------------------------------------------------------------------

Ili2Parser::AttributeDefContext::AttributeDefContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* Ili2Parser::AttributeDefContext::COLON() {
  return getToken(Ili2Parser::COLON, 0);
}

Ili2Parser::AttrTypeDefContext* Ili2Parser::AttributeDefContext::attrTypeDef() {
  return getRuleContext<Ili2Parser::AttrTypeDefContext>(0);
}

tree::TerminalNode* Ili2Parser::AttributeDefContext::SEMI() {
  return getToken(Ili2Parser::SEMI, 0);
}

tree::TerminalNode* Ili2Parser::AttributeDefContext::NAME() {
  return getToken(Ili2Parser::NAME, 0);
}

tree::TerminalNode* Ili2Parser::AttributeDefContext::SUBDIVISION() {
  return getToken(Ili2Parser::SUBDIVISION, 0);
}

Ili2Parser::PropertiesContext* Ili2Parser::AttributeDefContext::properties() {
  return getRuleContext<Ili2Parser::PropertiesContext>(0);
}

tree::TerminalNode* Ili2Parser::AttributeDefContext::COLONEQUAL() {
  return getToken(Ili2Parser::COLONEQUAL, 0);
}

std::vector<Ili2Parser::FactorContext *> Ili2Parser::AttributeDefContext::factor() {
  return getRuleContexts<Ili2Parser::FactorContext>();
}

Ili2Parser::FactorContext* Ili2Parser::AttributeDefContext::factor(size_t i) {
  return getRuleContext<Ili2Parser::FactorContext>(i);
}

tree::TerminalNode* Ili2Parser::AttributeDefContext::CONTINUOUS() {
  return getToken(Ili2Parser::CONTINUOUS, 0);
}

std::vector<tree::TerminalNode *> Ili2Parser::AttributeDefContext::COMMA() {
  return getTokens(Ili2Parser::COMMA);
}

tree::TerminalNode* Ili2Parser::AttributeDefContext::COMMA(size_t i) {
  return getToken(Ili2Parser::COMMA, i);
}


size_t Ili2Parser::AttributeDefContext::getRuleIndex() const {
  return Ili2Parser::RuleAttributeDef;
}

antlrcpp::Any Ili2Parser::AttributeDefContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<Ili2ParserVisitor*>(visitor))
    return parserVisitor->visitAttributeDef(this);
  else
    return visitor->visitChildren(this);
}

Ili2Parser::AttributeDefContext* Ili2Parser::attributeDef() {
  AttributeDefContext *_localctx = _tracker.createInstance<AttributeDefContext>(_ctx, getState());
  enterRule(_localctx, 20, Ili2Parser::RuleAttributeDef);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(484);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == Ili2Parser::CONTINUOUS

    || _la == Ili2Parser::SUBDIVISION) {
      setState(481);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == Ili2Parser::CONTINUOUS) {
        setState(480);
        match(Ili2Parser::CONTINUOUS);
      }
      setState(483);
      match(Ili2Parser::SUBDIVISION);
    }
    setState(486);
    dynamic_cast<AttributeDefContext *>(_localctx)->attributname = match(Ili2Parser::NAME);
    setState(488);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == Ili2Parser::LPAREN) {
      setState(487);
      properties();
    }
    setState(490);
    match(Ili2Parser::COLON);
    setState(491);
    attrTypeDef();
    setState(501);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == Ili2Parser::COLONEQUAL) {
      setState(492);
      match(Ili2Parser::COLONEQUAL);
      setState(493);
      factor();
      setState(498);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == Ili2Parser::COMMA) {
        setState(494);
        match(Ili2Parser::COMMA);
        setState(495);
        factor();
        setState(500);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
    }
    setState(503);
    match(Ili2Parser::SEMI);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- AttrTypeDefContext ------------------------------------------------------------------

Ili2Parser::AttrTypeDefContext::AttrTypeDefContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

Ili2Parser::AttrTypeContext* Ili2Parser::AttrTypeDefContext::attrType() {
  return getRuleContext<Ili2Parser::AttrTypeContext>(0);
}

tree::TerminalNode* Ili2Parser::AttrTypeDefContext::MANDATORY() {
  return getToken(Ili2Parser::MANDATORY, 0);
}

Ili2Parser::BagOrListTypeContext* Ili2Parser::AttrTypeDefContext::bagOrListType() {
  return getRuleContext<Ili2Parser::BagOrListTypeContext>(0);
}


size_t Ili2Parser::AttrTypeDefContext::getRuleIndex() const {
  return Ili2Parser::RuleAttrTypeDef;
}

antlrcpp::Any Ili2Parser::AttrTypeDefContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<Ili2ParserVisitor*>(visitor))
    return parserVisitor->visitAttrTypeDef(this);
  else
    return visitor->visitChildren(this);
}

Ili2Parser::AttrTypeDefContext* Ili2Parser::attrTypeDef() {
  AttrTypeDefContext *_localctx = _tracker.createInstance<AttrTypeDefContext>(_ctx, getState());
  enterRule(_localctx, 22, Ili2Parser::RuleAttrTypeDef);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(510);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 44, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(506);
      _errHandler->sync(this);

      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 43, _ctx)) {
      case 1: {
        setState(505);
        match(Ili2Parser::MANDATORY);
        break;
      }

      }
      setState(508);
      attrType();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(509);
      bagOrListType();
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- BagOrListTypeContext ------------------------------------------------------------------

Ili2Parser::BagOrListTypeContext::BagOrListTypeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* Ili2Parser::BagOrListTypeContext::OF() {
  return getToken(Ili2Parser::OF, 0);
}

tree::TerminalNode* Ili2Parser::BagOrListTypeContext::BAG() {
  return getToken(Ili2Parser::BAG, 0);
}

tree::TerminalNode* Ili2Parser::BagOrListTypeContext::LIST() {
  return getToken(Ili2Parser::LIST, 0);
}

Ili2Parser::RestrictedRefContext* Ili2Parser::BagOrListTypeContext::restrictedRef() {
  return getRuleContext<Ili2Parser::RestrictedRefContext>(0);
}

Ili2Parser::AttrTypeContext* Ili2Parser::BagOrListTypeContext::attrType() {
  return getRuleContext<Ili2Parser::AttrTypeContext>(0);
}

Ili2Parser::CardinalityContext* Ili2Parser::BagOrListTypeContext::cardinality() {
  return getRuleContext<Ili2Parser::CardinalityContext>(0);
}


size_t Ili2Parser::BagOrListTypeContext::getRuleIndex() const {
  return Ili2Parser::RuleBagOrListType;
}

antlrcpp::Any Ili2Parser::BagOrListTypeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<Ili2ParserVisitor*>(visitor))
    return parserVisitor->visitBagOrListType(this);
  else
    return visitor->visitChildren(this);
}

Ili2Parser::BagOrListTypeContext* Ili2Parser::bagOrListType() {
  BagOrListTypeContext *_localctx = _tracker.createInstance<BagOrListTypeContext>(_ctx, getState());
  enterRule(_localctx, 24, Ili2Parser::RuleBagOrListType);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(512);
    _la = _input->LA(1);
    if (!(_la == Ili2Parser::BAG

    || _la == Ili2Parser::LIST)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
    setState(514);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == Ili2Parser::LCURLY) {
      setState(513);
      cardinality();
    }
    setState(516);
    match(Ili2Parser::OF);
    setState(521);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 46, _ctx)) {
    case 1: {
      setState(517);

      if (!(ili23)) throw FailedPredicateException(this, "ili23");
      setState(518);
      restrictedRef();
      break;
    }

    case 2: {
      setState(519);

      if (!(ili24)) throw FailedPredicateException(this, "ili24");
      setState(520);
      attrType();
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- AttrTypeContext ------------------------------------------------------------------

Ili2Parser::AttrTypeContext::AttrTypeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

Ili2Parser::TypeContext* Ili2Parser::AttrTypeContext::type() {
  return getRuleContext<Ili2Parser::TypeContext>(0);
}

Ili2Parser::PathContext* Ili2Parser::AttrTypeContext::path() {
  return getRuleContext<Ili2Parser::PathContext>(0);
}

Ili2Parser::ReferenceAttrContext* Ili2Parser::AttrTypeContext::referenceAttr() {
  return getRuleContext<Ili2Parser::ReferenceAttrContext>(0);
}

Ili2Parser::RestrictedRefContext* Ili2Parser::AttrTypeContext::restrictedRef() {
  return getRuleContext<Ili2Parser::RestrictedRefContext>(0);
}


size_t Ili2Parser::AttrTypeContext::getRuleIndex() const {
  return Ili2Parser::RuleAttrType;
}

antlrcpp::Any Ili2Parser::AttrTypeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<Ili2ParserVisitor*>(visitor))
    return parserVisitor->visitAttrType(this);
  else
    return visitor->visitChildren(this);
}

Ili2Parser::AttrTypeContext* Ili2Parser::attrType() {
  AttrTypeContext *_localctx = _tracker.createInstance<AttrTypeContext>(_ctx, getState());
  enterRule(_localctx, 26, Ili2Parser::RuleAttrType);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(527);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 47, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(523);
      type();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(524);
      path();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(525);
      referenceAttr();
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(526);
      restrictedRef();
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ReferenceAttrContext ------------------------------------------------------------------

Ili2Parser::ReferenceAttrContext::ReferenceAttrContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* Ili2Parser::ReferenceAttrContext::REFERENCE() {
  return getToken(Ili2Parser::REFERENCE, 0);
}

tree::TerminalNode* Ili2Parser::ReferenceAttrContext::TO() {
  return getToken(Ili2Parser::TO, 0);
}

Ili2Parser::RestrictedRefContext* Ili2Parser::ReferenceAttrContext::restrictedRef() {
  return getRuleContext<Ili2Parser::RestrictedRefContext>(0);
}

tree::TerminalNode* Ili2Parser::ReferenceAttrContext::LPAREN() {
  return getToken(Ili2Parser::LPAREN, 0);
}

tree::TerminalNode* Ili2Parser::ReferenceAttrContext::EXTERNAL() {
  return getToken(Ili2Parser::EXTERNAL, 0);
}

tree::TerminalNode* Ili2Parser::ReferenceAttrContext::RPAREN() {
  return getToken(Ili2Parser::RPAREN, 0);
}


size_t Ili2Parser::ReferenceAttrContext::getRuleIndex() const {
  return Ili2Parser::RuleReferenceAttr;
}

antlrcpp::Any Ili2Parser::ReferenceAttrContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<Ili2ParserVisitor*>(visitor))
    return parserVisitor->visitReferenceAttr(this);
  else
    return visitor->visitChildren(this);
}

Ili2Parser::ReferenceAttrContext* Ili2Parser::referenceAttr() {
  ReferenceAttrContext *_localctx = _tracker.createInstance<ReferenceAttrContext>(_ctx, getState());
  enterRule(_localctx, 28, Ili2Parser::RuleReferenceAttr);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(529);
    match(Ili2Parser::REFERENCE);
    setState(530);
    match(Ili2Parser::TO);
    setState(534);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == Ili2Parser::LPAREN) {
      setState(531);
      match(Ili2Parser::LPAREN);
      setState(532);
      match(Ili2Parser::EXTERNAL);
      setState(533);
      match(Ili2Parser::RPAREN);
    }
    setState(536);
    restrictedRef();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- RestrictedRefContext ------------------------------------------------------------------

Ili2Parser::RestrictedRefContext::RestrictedRefContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* Ili2Parser::RestrictedRefContext::ANYCLASS() {
  return getToken(Ili2Parser::ANYCLASS, 0);
}

tree::TerminalNode* Ili2Parser::RestrictedRefContext::ANYSTRUCTURE() {
  return getToken(Ili2Parser::ANYSTRUCTURE, 0);
}

Ili2Parser::PathContext* Ili2Parser::RestrictedRefContext::path() {
  return getRuleContext<Ili2Parser::PathContext>(0);
}

Ili2Parser::RestrictionContext* Ili2Parser::RestrictedRefContext::restriction() {
  return getRuleContext<Ili2Parser::RestrictionContext>(0);
}


size_t Ili2Parser::RestrictedRefContext::getRuleIndex() const {
  return Ili2Parser::RuleRestrictedRef;
}

antlrcpp::Any Ili2Parser::RestrictedRefContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<Ili2ParserVisitor*>(visitor))
    return parserVisitor->visitRestrictedRef(this);
  else
    return visitor->visitChildren(this);
}

Ili2Parser::RestrictedRefContext* Ili2Parser::restrictedRef() {
  RestrictedRefContext *_localctx = _tracker.createInstance<RestrictedRefContext>(_ctx, getState());
  enterRule(_localctx, 30, Ili2Parser::RuleRestrictedRef);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(541);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case Ili2Parser::INTERLIS:
      case Ili2Parser::NAME: {
        setState(538);
        dynamic_cast<RestrictedRefContext *>(_localctx)->typeref = path();
        break;
      }

      case Ili2Parser::ANYCLASS: {
        setState(539);
        match(Ili2Parser::ANYCLASS);
        break;
      }

      case Ili2Parser::ANYSTRUCTURE: {
        setState(540);
        match(Ili2Parser::ANYSTRUCTURE);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    setState(544);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == Ili2Parser::RESTRICTION) {
      setState(543);
      restriction();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- RestrictionContext ------------------------------------------------------------------

Ili2Parser::RestrictionContext::RestrictionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* Ili2Parser::RestrictionContext::RESTRICTION() {
  return getToken(Ili2Parser::RESTRICTION, 0);
}

tree::TerminalNode* Ili2Parser::RestrictionContext::LPAREN() {
  return getToken(Ili2Parser::LPAREN, 0);
}

std::vector<Ili2Parser::PathContext *> Ili2Parser::RestrictionContext::path() {
  return getRuleContexts<Ili2Parser::PathContext>();
}

Ili2Parser::PathContext* Ili2Parser::RestrictionContext::path(size_t i) {
  return getRuleContext<Ili2Parser::PathContext>(i);
}

tree::TerminalNode* Ili2Parser::RestrictionContext::RPAREN() {
  return getToken(Ili2Parser::RPAREN, 0);
}

std::vector<tree::TerminalNode *> Ili2Parser::RestrictionContext::COMMA() {
  return getTokens(Ili2Parser::COMMA);
}

tree::TerminalNode* Ili2Parser::RestrictionContext::COMMA(size_t i) {
  return getToken(Ili2Parser::COMMA, i);
}


size_t Ili2Parser::RestrictionContext::getRuleIndex() const {
  return Ili2Parser::RuleRestriction;
}

antlrcpp::Any Ili2Parser::RestrictionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<Ili2ParserVisitor*>(visitor))
    return parserVisitor->visitRestriction(this);
  else
    return visitor->visitChildren(this);
}

Ili2Parser::RestrictionContext* Ili2Parser::restriction() {
  RestrictionContext *_localctx = _tracker.createInstance<RestrictionContext>(_ctx, getState());
  enterRule(_localctx, 32, Ili2Parser::RuleRestriction);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(546);
    match(Ili2Parser::RESTRICTION);
    setState(547);
    match(Ili2Parser::LPAREN);
    setState(548);
    path();
    setState(553);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == Ili2Parser::COMMA) {
      setState(549);
      match(Ili2Parser::COMMA);
      setState(550);
      path();
      setState(555);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(556);
    match(Ili2Parser::RPAREN);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- AssociationDefContext ------------------------------------------------------------------

Ili2Parser::AssociationDefContext::AssociationDefContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* Ili2Parser::AssociationDefContext::ASSOCIATION() {
  return getToken(Ili2Parser::ASSOCIATION, 0);
}

std::vector<tree::TerminalNode *> Ili2Parser::AssociationDefContext::EQUAL() {
  return getTokens(Ili2Parser::EQUAL);
}

tree::TerminalNode* Ili2Parser::AssociationDefContext::EQUAL(size_t i) {
  return getToken(Ili2Parser::EQUAL, i);
}

tree::TerminalNode* Ili2Parser::AssociationDefContext::END() {
  return getToken(Ili2Parser::END, 0);
}

std::vector<tree::TerminalNode *> Ili2Parser::AssociationDefContext::SEMI() {
  return getTokens(Ili2Parser::SEMI);
}

tree::TerminalNode* Ili2Parser::AssociationDefContext::SEMI(size_t i) {
  return getToken(Ili2Parser::SEMI, i);
}

std::vector<tree::TerminalNode *> Ili2Parser::AssociationDefContext::NAME() {
  return getTokens(Ili2Parser::NAME);
}

tree::TerminalNode* Ili2Parser::AssociationDefContext::NAME(size_t i) {
  return getToken(Ili2Parser::NAME, i);
}

Ili2Parser::PropertiesContext* Ili2Parser::AssociationDefContext::properties() {
  return getRuleContext<Ili2Parser::PropertiesContext>(0);
}

tree::TerminalNode* Ili2Parser::AssociationDefContext::EXTENDS() {
  return getToken(Ili2Parser::EXTENDS, 0);
}

Ili2Parser::AssociationRefContext* Ili2Parser::AssociationDefContext::associationRef() {
  return getRuleContext<Ili2Parser::AssociationRefContext>(0);
}

tree::TerminalNode* Ili2Parser::AssociationDefContext::DERIVED() {
  return getToken(Ili2Parser::DERIVED, 0);
}

tree::TerminalNode* Ili2Parser::AssociationDefContext::FROM() {
  return getToken(Ili2Parser::FROM, 0);
}

Ili2Parser::RenamedViewableRefContext* Ili2Parser::AssociationDefContext::renamedViewableRef() {
  return getRuleContext<Ili2Parser::RenamedViewableRefContext>(0);
}

std::vector<Ili2Parser::RoleDefContext *> Ili2Parser::AssociationDefContext::roleDef() {
  return getRuleContexts<Ili2Parser::RoleDefContext>();
}

Ili2Parser::RoleDefContext* Ili2Parser::AssociationDefContext::roleDef(size_t i) {
  return getRuleContext<Ili2Parser::RoleDefContext>(i);
}

tree::TerminalNode* Ili2Parser::AssociationDefContext::ATTRIBUTE() {
  return getToken(Ili2Parser::ATTRIBUTE, 0);
}

std::vector<Ili2Parser::AttributeDefContext *> Ili2Parser::AssociationDefContext::attributeDef() {
  return getRuleContexts<Ili2Parser::AttributeDefContext>();
}

Ili2Parser::AttributeDefContext* Ili2Parser::AssociationDefContext::attributeDef(size_t i) {
  return getRuleContext<Ili2Parser::AttributeDefContext>(i);
}

tree::TerminalNode* Ili2Parser::AssociationDefContext::CARDINALITY() {
  return getToken(Ili2Parser::CARDINALITY, 0);
}

Ili2Parser::CardinalityContext* Ili2Parser::AssociationDefContext::cardinality() {
  return getRuleContext<Ili2Parser::CardinalityContext>(0);
}

std::vector<Ili2Parser::ConstraintDefContext *> Ili2Parser::AssociationDefContext::constraintDef() {
  return getRuleContexts<Ili2Parser::ConstraintDefContext>();
}

Ili2Parser::ConstraintDefContext* Ili2Parser::AssociationDefContext::constraintDef(size_t i) {
  return getRuleContext<Ili2Parser::ConstraintDefContext>(i);
}

tree::TerminalNode* Ili2Parser::AssociationDefContext::OID() {
  return getToken(Ili2Parser::OID, 0);
}

tree::TerminalNode* Ili2Parser::AssociationDefContext::AS() {
  return getToken(Ili2Parser::AS, 0);
}

tree::TerminalNode* Ili2Parser::AssociationDefContext::NO() {
  return getToken(Ili2Parser::NO, 0);
}

Ili2Parser::PathContext* Ili2Parser::AssociationDefContext::path() {
  return getRuleContext<Ili2Parser::PathContext>(0);
}


size_t Ili2Parser::AssociationDefContext::getRuleIndex() const {
  return Ili2Parser::RuleAssociationDef;
}

antlrcpp::Any Ili2Parser::AssociationDefContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<Ili2ParserVisitor*>(visitor))
    return parserVisitor->visitAssociationDef(this);
  else
    return visitor->visitChildren(this);
}

Ili2Parser::AssociationDefContext* Ili2Parser::associationDef() {
  AssociationDefContext *_localctx = _tracker.createInstance<AssociationDefContext>(_ctx, getState());
  enterRule(_localctx, 34, Ili2Parser::RuleAssociationDef);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(558);
    match(Ili2Parser::ASSOCIATION);
    setState(559);
    dynamic_cast<AssociationDefContext *>(_localctx)->associationname1 = match(Ili2Parser::NAME);
    setState(561);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == Ili2Parser::LPAREN) {
      setState(560);
      properties();
    }
    setState(565);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == Ili2Parser::EXTENDS) {
      setState(563);
      match(Ili2Parser::EXTENDS);
      setState(564);
      associationRef();
    }
    setState(570);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == Ili2Parser::DERIVED) {
      setState(567);
      match(Ili2Parser::DERIVED);
      setState(568);
      match(Ili2Parser::FROM);
      setState(569);
      renamedViewableRef();
    }
    setState(572);
    match(Ili2Parser::EQUAL);
    setState(581);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == Ili2Parser::OID

    || _la == Ili2Parser::NO) {
      setState(578);
      _errHandler->sync(this);
      switch (_input->LA(1)) {
        case Ili2Parser::OID: {
          setState(573);
          match(Ili2Parser::OID);
          setState(574);
          match(Ili2Parser::AS);
          setState(575);
          dynamic_cast<AssociationDefContext *>(_localctx)->assocoid = path();
          break;
        }

        case Ili2Parser::NO: {
          setState(576);
          match(Ili2Parser::NO);
          setState(577);
          match(Ili2Parser::OID);
          break;
        }

      default:
        throw NoViableAltException(this);
      }
      setState(580);
      match(Ili2Parser::SEMI);
    }
    setState(586);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 57, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(583);
        roleDef(); 
      }
      setState(588);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 57, _ctx);
    }
    setState(590);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == Ili2Parser::ATTRIBUTE) {
      setState(589);
      match(Ili2Parser::ATTRIBUTE);
    }
    setState(595);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == Ili2Parser::CONTINUOUS

    || _la == Ili2Parser::SUBDIVISION || _la == Ili2Parser::NAME) {
      setState(592);
      attributeDef();
      setState(597);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(603);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == Ili2Parser::CARDINALITY) {
      setState(598);
      match(Ili2Parser::CARDINALITY);
      setState(599);
      match(Ili2Parser::EQUAL);
      setState(600);
      cardinality();
      setState(601);
      match(Ili2Parser::SEMI);
    }
    setState(608);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (((((_la - 83) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 83)) & ((1ULL << (Ili2Parser::MANDATORY - 83))
      | (1ULL << (Ili2Parser::CONSTRAINT - 83))
      | (1ULL << (Ili2Parser::EXISTENCE - 83)))) != 0) || _la == Ili2Parser::UNIQUE

    || _la == Ili2Parser::SET) {
      setState(605);
      constraintDef();
      setState(610);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(611);
    match(Ili2Parser::END);
    setState(612);
    dynamic_cast<AssociationDefContext *>(_localctx)->associationname2 = match(Ili2Parser::NAME);
    setState(613);
    match(Ili2Parser::SEMI);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- AssociationRefContext ------------------------------------------------------------------

Ili2Parser::AssociationRefContext::AssociationRefContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<tree::TerminalNode *> Ili2Parser::AssociationRefContext::NAME() {
  return getTokens(Ili2Parser::NAME);
}

tree::TerminalNode* Ili2Parser::AssociationRefContext::NAME(size_t i) {
  return getToken(Ili2Parser::NAME, i);
}

std::vector<tree::TerminalNode *> Ili2Parser::AssociationRefContext::DOT() {
  return getTokens(Ili2Parser::DOT);
}

tree::TerminalNode* Ili2Parser::AssociationRefContext::DOT(size_t i) {
  return getToken(Ili2Parser::DOT, i);
}


size_t Ili2Parser::AssociationRefContext::getRuleIndex() const {
  return Ili2Parser::RuleAssociationRef;
}

antlrcpp::Any Ili2Parser::AssociationRefContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<Ili2ParserVisitor*>(visitor))
    return parserVisitor->visitAssociationRef(this);
  else
    return visitor->visitChildren(this);
}

Ili2Parser::AssociationRefContext* Ili2Parser::associationRef() {
  AssociationRefContext *_localctx = _tracker.createInstance<AssociationRefContext>(_ctx, getState());
  enterRule(_localctx, 36, Ili2Parser::RuleAssociationRef);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(621);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 63, _ctx)) {
    case 1: {
      setState(617);
      _errHandler->sync(this);

      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 62, _ctx)) {
      case 1: {
        setState(615);
        dynamic_cast<AssociationRefContext *>(_localctx)->modelname = match(Ili2Parser::NAME);
        setState(616);
        match(Ili2Parser::DOT);
        break;
      }

      }
      setState(619);
      dynamic_cast<AssociationRefContext *>(_localctx)->topicname = match(Ili2Parser::NAME);
      setState(620);
      match(Ili2Parser::DOT);
      break;
    }

    }
    setState(623);
    dynamic_cast<AssociationRefContext *>(_localctx)->associationname = match(Ili2Parser::NAME);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- RoleDefContext ------------------------------------------------------------------

Ili2Parser::RoleDefContext::RoleDefContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<Ili2Parser::RestrictedRefContext *> Ili2Parser::RoleDefContext::restrictedRef() {
  return getRuleContexts<Ili2Parser::RestrictedRefContext>();
}

Ili2Parser::RestrictedRefContext* Ili2Parser::RoleDefContext::restrictedRef(size_t i) {
  return getRuleContext<Ili2Parser::RestrictedRefContext>(i);
}

tree::TerminalNode* Ili2Parser::RoleDefContext::SEMI() {
  return getToken(Ili2Parser::SEMI, 0);
}

tree::TerminalNode* Ili2Parser::RoleDefContext::NAME() {
  return getToken(Ili2Parser::NAME, 0);
}

tree::TerminalNode* Ili2Parser::RoleDefContext::ASSOCIATE() {
  return getToken(Ili2Parser::ASSOCIATE, 0);
}

tree::TerminalNode* Ili2Parser::RoleDefContext::AGGREGATE() {
  return getToken(Ili2Parser::AGGREGATE, 0);
}

tree::TerminalNode* Ili2Parser::RoleDefContext::COMPOSITE() {
  return getToken(Ili2Parser::COMPOSITE, 0);
}

Ili2Parser::PropertiesContext* Ili2Parser::RoleDefContext::properties() {
  return getRuleContext<Ili2Parser::PropertiesContext>(0);
}

Ili2Parser::CardinalityContext* Ili2Parser::RoleDefContext::cardinality() {
  return getRuleContext<Ili2Parser::CardinalityContext>(0);
}

std::vector<tree::TerminalNode *> Ili2Parser::RoleDefContext::OR() {
  return getTokens(Ili2Parser::OR);
}

tree::TerminalNode* Ili2Parser::RoleDefContext::OR(size_t i) {
  return getToken(Ili2Parser::OR, i);
}

tree::TerminalNode* Ili2Parser::RoleDefContext::COLONEQUAL() {
  return getToken(Ili2Parser::COLONEQUAL, 0);
}

Ili2Parser::FactorContext* Ili2Parser::RoleDefContext::factor() {
  return getRuleContext<Ili2Parser::FactorContext>(0);
}


size_t Ili2Parser::RoleDefContext::getRuleIndex() const {
  return Ili2Parser::RuleRoleDef;
}

antlrcpp::Any Ili2Parser::RoleDefContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<Ili2ParserVisitor*>(visitor))
    return parserVisitor->visitRoleDef(this);
  else
    return visitor->visitChildren(this);
}

Ili2Parser::RoleDefContext* Ili2Parser::roleDef() {
  RoleDefContext *_localctx = _tracker.createInstance<RoleDefContext>(_ctx, getState());
  enterRule(_localctx, 38, Ili2Parser::RuleRoleDef);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(625);
    dynamic_cast<RoleDefContext *>(_localctx)->rolename = match(Ili2Parser::NAME);
    setState(627);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == Ili2Parser::LPAREN) {
      setState(626);
      properties();
    }
    setState(629);
    _la = _input->LA(1);
    if (!(((((_la - 78) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 78)) & ((1ULL << (Ili2Parser::AGGREGATE - 78))
      | (1ULL << (Ili2Parser::ASSOCIATE - 78))
      | (1ULL << (Ili2Parser::COMPOSITE - 78)))) != 0))) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
    setState(631);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == Ili2Parser::LCURLY) {
      setState(630);
      cardinality();
    }
    setState(633);
    restrictedRef();
    setState(638);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == Ili2Parser::OR) {
      setState(634);
      match(Ili2Parser::OR);
      setState(635);
      restrictedRef();
      setState(640);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(643);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == Ili2Parser::COLONEQUAL) {
      setState(641);
      match(Ili2Parser::COLONEQUAL);
      setState(642);
      dynamic_cast<RoleDefContext *>(_localctx)->role = factor();
    }
    setState(645);
    match(Ili2Parser::SEMI);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- CardinalityContext ------------------------------------------------------------------

Ili2Parser::CardinalityContext::CardinalityContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* Ili2Parser::CardinalityContext::LCURLY() {
  return getToken(Ili2Parser::LCURLY, 0);
}

tree::TerminalNode* Ili2Parser::CardinalityContext::RCURLY() {
  return getToken(Ili2Parser::RCURLY, 0);
}

tree::TerminalNode* Ili2Parser::CardinalityContext::STAR() {
  return getToken(Ili2Parser::STAR, 0);
}

std::vector<tree::TerminalNode *> Ili2Parser::CardinalityContext::POSNUMBER() {
  return getTokens(Ili2Parser::POSNUMBER);
}

tree::TerminalNode* Ili2Parser::CardinalityContext::POSNUMBER(size_t i) {
  return getToken(Ili2Parser::POSNUMBER, i);
}

tree::TerminalNode* Ili2Parser::CardinalityContext::DOTDOT() {
  return getToken(Ili2Parser::DOTDOT, 0);
}


size_t Ili2Parser::CardinalityContext::getRuleIndex() const {
  return Ili2Parser::RuleCardinality;
}

antlrcpp::Any Ili2Parser::CardinalityContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<Ili2ParserVisitor*>(visitor))
    return parserVisitor->visitCardinality(this);
  else
    return visitor->visitChildren(this);
}

Ili2Parser::CardinalityContext* Ili2Parser::cardinality() {
  CardinalityContext *_localctx = _tracker.createInstance<CardinalityContext>(_ctx, getState());
  enterRule(_localctx, 40, Ili2Parser::RuleCardinality);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(647);
    match(Ili2Parser::LCURLY);
    setState(657);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case Ili2Parser::STAR: {
        setState(648);
        match(Ili2Parser::STAR);
        break;
      }

      case Ili2Parser::POSNUMBER: {
        setState(649);
        dynamic_cast<CardinalityContext *>(_localctx)->min = match(Ili2Parser::POSNUMBER);
        setState(655);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == Ili2Parser::DOTDOT) {
          setState(650);
          match(Ili2Parser::DOTDOT);
          setState(653);
          _errHandler->sync(this);
          switch (_input->LA(1)) {
            case Ili2Parser::POSNUMBER: {
              setState(651);
              dynamic_cast<CardinalityContext *>(_localctx)->max = match(Ili2Parser::POSNUMBER);
              break;
            }

            case Ili2Parser::STAR: {
              setState(652);
              match(Ili2Parser::STAR);
              break;
            }

          default:
            throw NoViableAltException(this);
          }
        }
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    setState(659);
    match(Ili2Parser::RCURLY);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- DomainDeclContext ------------------------------------------------------------------

Ili2Parser::DomainDeclContext::DomainDeclContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* Ili2Parser::DomainDeclContext::ILIDOMAIN() {
  return getToken(Ili2Parser::ILIDOMAIN, 0);
}

std::vector<Ili2Parser::DomainDefContext *> Ili2Parser::DomainDeclContext::domainDef() {
  return getRuleContexts<Ili2Parser::DomainDefContext>();
}

Ili2Parser::DomainDefContext* Ili2Parser::DomainDeclContext::domainDef(size_t i) {
  return getRuleContext<Ili2Parser::DomainDefContext>(i);
}


size_t Ili2Parser::DomainDeclContext::getRuleIndex() const {
  return Ili2Parser::RuleDomainDecl;
}

antlrcpp::Any Ili2Parser::DomainDeclContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<Ili2ParserVisitor*>(visitor))
    return parserVisitor->visitDomainDecl(this);
  else
    return visitor->visitChildren(this);
}

Ili2Parser::DomainDeclContext* Ili2Parser::domainDecl() {
  DomainDeclContext *_localctx = _tracker.createInstance<DomainDeclContext>(_ctx, getState());
  enterRule(_localctx, 42, Ili2Parser::RuleDomainDecl);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(661);
    match(Ili2Parser::ILIDOMAIN);
    setState(665);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 71, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(662);
        domainDef(); 
      }
      setState(667);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 71, _ctx);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- DomainDefContext ------------------------------------------------------------------

Ili2Parser::DomainDefContext::DomainDefContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* Ili2Parser::DomainDefContext::EQUAL() {
  return getToken(Ili2Parser::EQUAL, 0);
}

tree::TerminalNode* Ili2Parser::DomainDefContext::SEMI() {
  return getToken(Ili2Parser::SEMI, 0);
}

std::vector<tree::TerminalNode *> Ili2Parser::DomainDefContext::NAME() {
  return getTokens(Ili2Parser::NAME);
}

tree::TerminalNode* Ili2Parser::DomainDefContext::NAME(size_t i) {
  return getToken(Ili2Parser::NAME, i);
}

tree::TerminalNode* Ili2Parser::DomainDefContext::MANDATORY() {
  return getToken(Ili2Parser::MANDATORY, 0);
}

Ili2Parser::TypeContext* Ili2Parser::DomainDefContext::type() {
  return getRuleContext<Ili2Parser::TypeContext>(0);
}

Ili2Parser::PropertiesContext* Ili2Parser::DomainDefContext::properties() {
  return getRuleContext<Ili2Parser::PropertiesContext>(0);
}

tree::TerminalNode* Ili2Parser::DomainDefContext::EXTENDS() {
  return getToken(Ili2Parser::EXTENDS, 0);
}

tree::TerminalNode* Ili2Parser::DomainDefContext::CONSTRAINTS() {
  return getToken(Ili2Parser::CONSTRAINTS, 0);
}

std::vector<tree::TerminalNode *> Ili2Parser::DomainDefContext::COLON() {
  return getTokens(Ili2Parser::COLON);
}

tree::TerminalNode* Ili2Parser::DomainDefContext::COLON(size_t i) {
  return getToken(Ili2Parser::COLON, i);
}

std::vector<Ili2Parser::ExpressionContext *> Ili2Parser::DomainDefContext::expression() {
  return getRuleContexts<Ili2Parser::ExpressionContext>();
}

Ili2Parser::ExpressionContext* Ili2Parser::DomainDefContext::expression(size_t i) {
  return getRuleContext<Ili2Parser::ExpressionContext>(i);
}

Ili2Parser::PathContext* Ili2Parser::DomainDefContext::path() {
  return getRuleContext<Ili2Parser::PathContext>(0);
}

std::vector<tree::TerminalNode *> Ili2Parser::DomainDefContext::COMMA() {
  return getTokens(Ili2Parser::COMMA);
}

tree::TerminalNode* Ili2Parser::DomainDefContext::COMMA(size_t i) {
  return getToken(Ili2Parser::COMMA, i);
}


size_t Ili2Parser::DomainDefContext::getRuleIndex() const {
  return Ili2Parser::RuleDomainDef;
}

antlrcpp::Any Ili2Parser::DomainDefContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<Ili2ParserVisitor*>(visitor))
    return parserVisitor->visitDomainDef(this);
  else
    return visitor->visitChildren(this);
}

Ili2Parser::DomainDefContext* Ili2Parser::domainDef() {
  DomainDefContext *_localctx = _tracker.createInstance<DomainDefContext>(_ctx, getState());
  enterRule(_localctx, 44, Ili2Parser::RuleDomainDef);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(668);
    dynamic_cast<DomainDefContext *>(_localctx)->domainname = match(Ili2Parser::NAME);
    setState(670);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == Ili2Parser::LPAREN) {
      setState(669);
      properties();
    }
    setState(674);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == Ili2Parser::EXTENDS) {
      setState(672);
      match(Ili2Parser::EXTENDS);
      setState(673);
      dynamic_cast<DomainDefContext *>(_localctx)->basedomain = path();
    }
    setState(676);
    match(Ili2Parser::EQUAL);
    setState(682);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 75, _ctx)) {
    case 1: {
      setState(677);
      match(Ili2Parser::MANDATORY);
      setState(679);
      _errHandler->sync(this);

      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 74, _ctx)) {
      case 1: {
        setState(678);
        type();
        break;
      }

      }
      break;
    }

    case 2: {
      setState(681);
      type();
      break;
    }

    }
    setState(698);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 77, _ctx)) {
    case 1: {
      setState(684);

      if (!(ili24)) throw FailedPredicateException(this, "ili24");
      setState(685);
      match(Ili2Parser::CONSTRAINTS);
      setState(686);
      match(Ili2Parser::NAME);
      setState(687);
      match(Ili2Parser::COLON);
      setState(688);
      expression();
      setState(695);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == Ili2Parser::COMMA) {
        setState(689);
        match(Ili2Parser::COMMA);
        setState(690);
        match(Ili2Parser::NAME);
        setState(691);
        match(Ili2Parser::COLON);
        setState(692);
        expression();
        setState(697);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      break;
    }

    }
    setState(700);
    match(Ili2Parser::SEMI);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- TypeContext ------------------------------------------------------------------

Ili2Parser::TypeContext::TypeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

Ili2Parser::BaseTypeContext* Ili2Parser::TypeContext::baseType() {
  return getRuleContext<Ili2Parser::BaseTypeContext>(0);
}

Ili2Parser::LineTypeContext* Ili2Parser::TypeContext::lineType() {
  return getRuleContext<Ili2Parser::LineTypeContext>(0);
}


size_t Ili2Parser::TypeContext::getRuleIndex() const {
  return Ili2Parser::RuleType;
}

antlrcpp::Any Ili2Parser::TypeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<Ili2ParserVisitor*>(visitor))
    return parserVisitor->visitType(this);
  else
    return visitor->visitChildren(this);
}

Ili2Parser::TypeContext* Ili2Parser::type() {
  TypeContext *_localctx = _tracker.createInstance<TypeContext>(_ctx, getState());
  enterRule(_localctx, 46, Ili2Parser::RuleType);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(704);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 78, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(702);
      baseType();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(703);
      lineType();
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- BaseTypeContext ------------------------------------------------------------------

Ili2Parser::BaseTypeContext::BaseTypeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

Ili2Parser::TextTypeContext* Ili2Parser::BaseTypeContext::textType() {
  return getRuleContext<Ili2Parser::TextTypeContext>(0);
}

Ili2Parser::EnumerationTypeContext* Ili2Parser::BaseTypeContext::enumerationType() {
  return getRuleContext<Ili2Parser::EnumerationTypeContext>(0);
}

Ili2Parser::EnumTreeValueTypeContext* Ili2Parser::BaseTypeContext::enumTreeValueType() {
  return getRuleContext<Ili2Parser::EnumTreeValueTypeContext>(0);
}

Ili2Parser::NumericTypeContext* Ili2Parser::BaseTypeContext::numericType() {
  return getRuleContext<Ili2Parser::NumericTypeContext>(0);
}

Ili2Parser::FormattedTypeContext* Ili2Parser::BaseTypeContext::formattedType() {
  return getRuleContext<Ili2Parser::FormattedTypeContext>(0);
}

Ili2Parser::DateTimeTypeContext* Ili2Parser::BaseTypeContext::dateTimeType() {
  return getRuleContext<Ili2Parser::DateTimeTypeContext>(0);
}

Ili2Parser::CoordinateTypeContext* Ili2Parser::BaseTypeContext::coordinateType() {
  return getRuleContext<Ili2Parser::CoordinateTypeContext>(0);
}

Ili2Parser::OIDTypeContext* Ili2Parser::BaseTypeContext::oIDType() {
  return getRuleContext<Ili2Parser::OIDTypeContext>(0);
}

Ili2Parser::BlackboxTypeContext* Ili2Parser::BaseTypeContext::blackboxType() {
  return getRuleContext<Ili2Parser::BlackboxTypeContext>(0);
}

Ili2Parser::ClassTypeContext* Ili2Parser::BaseTypeContext::classType() {
  return getRuleContext<Ili2Parser::ClassTypeContext>(0);
}

Ili2Parser::AttributeTypeContext* Ili2Parser::BaseTypeContext::attributeType() {
  return getRuleContext<Ili2Parser::AttributeTypeContext>(0);
}


size_t Ili2Parser::BaseTypeContext::getRuleIndex() const {
  return Ili2Parser::RuleBaseType;
}

antlrcpp::Any Ili2Parser::BaseTypeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<Ili2ParserVisitor*>(visitor))
    return parserVisitor->visitBaseType(this);
  else
    return visitor->visitChildren(this);
}

Ili2Parser::BaseTypeContext* Ili2Parser::baseType() {
  BaseTypeContext *_localctx = _tracker.createInstance<BaseTypeContext>(_ctx, getState());
  enterRule(_localctx, 48, Ili2Parser::RuleBaseType);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(718);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 79, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(706);
      textType();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(707);
      enumerationType();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(708);
      enumTreeValueType();
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(709);
      numericType();
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
      setState(710);
      formattedType();
      break;
    }

    case 6: {
      enterOuterAlt(_localctx, 6);
      setState(711);

      if (!(ili24)) throw FailedPredicateException(this, "ili24");
      setState(712);
      dateTimeType();
      break;
    }

    case 7: {
      enterOuterAlt(_localctx, 7);
      setState(713);
      coordinateType();
      break;
    }

    case 8: {
      enterOuterAlt(_localctx, 8);
      setState(714);
      oIDType();
      break;
    }

    case 9: {
      enterOuterAlt(_localctx, 9);
      setState(715);
      blackboxType();
      break;
    }

    case 10: {
      enterOuterAlt(_localctx, 10);
      setState(716);
      classType();
      break;
    }

    case 11: {
      enterOuterAlt(_localctx, 11);
      setState(717);
      attributeType();
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ConstantContext ------------------------------------------------------------------

Ili2Parser::ConstantContext::ConstantContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* Ili2Parser::ConstantContext::UNDEFINED() {
  return getToken(Ili2Parser::UNDEFINED, 0);
}

Ili2Parser::NumericConstContext* Ili2Parser::ConstantContext::numericConst() {
  return getRuleContext<Ili2Parser::NumericConstContext>(0);
}

Ili2Parser::TextConstContext* Ili2Parser::ConstantContext::textConst() {
  return getRuleContext<Ili2Parser::TextConstContext>(0);
}

Ili2Parser::FormattedConstContext* Ili2Parser::ConstantContext::formattedConst() {
  return getRuleContext<Ili2Parser::FormattedConstContext>(0);
}

Ili2Parser::EnumConstContext* Ili2Parser::ConstantContext::enumConst() {
  return getRuleContext<Ili2Parser::EnumConstContext>(0);
}

Ili2Parser::ClassConstContext* Ili2Parser::ConstantContext::classConst() {
  return getRuleContext<Ili2Parser::ClassConstContext>(0);
}

Ili2Parser::AttributeConstContext* Ili2Parser::ConstantContext::attributeConst() {
  return getRuleContext<Ili2Parser::AttributeConstContext>(0);
}


size_t Ili2Parser::ConstantContext::getRuleIndex() const {
  return Ili2Parser::RuleConstant;
}

antlrcpp::Any Ili2Parser::ConstantContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<Ili2ParserVisitor*>(visitor))
    return parserVisitor->visitConstant(this);
  else
    return visitor->visitChildren(this);
}

Ili2Parser::ConstantContext* Ili2Parser::constant() {
  ConstantContext *_localctx = _tracker.createInstance<ConstantContext>(_ctx, getState());
  enterRule(_localctx, 50, Ili2Parser::RuleConstant);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(727);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 80, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(720);
      match(Ili2Parser::UNDEFINED);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(721);
      numericConst();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(722);
      textConst();
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(723);
      formattedConst();
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
      setState(724);
      enumConst();
      break;
    }

    case 6: {
      enterOuterAlt(_localctx, 6);
      setState(725);
      classConst();
      break;
    }

    case 7: {
      enterOuterAlt(_localctx, 7);
      setState(726);
      attributeConst();
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- TextTypeContext ------------------------------------------------------------------

Ili2Parser::TextTypeContext::TextTypeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* Ili2Parser::TextTypeContext::MTEXT() {
  return getToken(Ili2Parser::MTEXT, 0);
}

tree::TerminalNode* Ili2Parser::TextTypeContext::STAR() {
  return getToken(Ili2Parser::STAR, 0);
}

tree::TerminalNode* Ili2Parser::TextTypeContext::POSNUMBER() {
  return getToken(Ili2Parser::POSNUMBER, 0);
}

tree::TerminalNode* Ili2Parser::TextTypeContext::TEXT() {
  return getToken(Ili2Parser::TEXT, 0);
}


size_t Ili2Parser::TextTypeContext::getRuleIndex() const {
  return Ili2Parser::RuleTextType;
}

antlrcpp::Any Ili2Parser::TextTypeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<Ili2ParserVisitor*>(visitor))
    return parserVisitor->visitTextType(this);
  else
    return visitor->visitChildren(this);
}

Ili2Parser::TextTypeContext* Ili2Parser::textType() {
  TextTypeContext *_localctx = _tracker.createInstance<TextTypeContext>(_ctx, getState());
  enterRule(_localctx, 52, Ili2Parser::RuleTextType);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(739);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case Ili2Parser::MTEXT: {
        enterOuterAlt(_localctx, 1);
        setState(729);
        match(Ili2Parser::MTEXT);
        setState(732);
        _errHandler->sync(this);

        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 81, _ctx)) {
        case 1: {
          setState(730);
          match(Ili2Parser::STAR);
          setState(731);
          dynamic_cast<TextTypeContext *>(_localctx)->maxlength = match(Ili2Parser::POSNUMBER);
          break;
        }

        }
        break;
      }

      case Ili2Parser::TEXT: {
        enterOuterAlt(_localctx, 2);
        setState(734);
        match(Ili2Parser::TEXT);
        setState(737);
        _errHandler->sync(this);

        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 82, _ctx)) {
        case 1: {
          setState(735);
          match(Ili2Parser::STAR);
          setState(736);
          dynamic_cast<TextTypeContext *>(_localctx)->maxlength = match(Ili2Parser::POSNUMBER);
          break;
        }

        }
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- TextConstContext ------------------------------------------------------------------

Ili2Parser::TextConstContext::TextConstContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* Ili2Parser::TextConstContext::STRING() {
  return getToken(Ili2Parser::STRING, 0);
}


size_t Ili2Parser::TextConstContext::getRuleIndex() const {
  return Ili2Parser::RuleTextConst;
}

antlrcpp::Any Ili2Parser::TextConstContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<Ili2ParserVisitor*>(visitor))
    return parserVisitor->visitTextConst(this);
  else
    return visitor->visitChildren(this);
}

Ili2Parser::TextConstContext* Ili2Parser::textConst() {
  TextConstContext *_localctx = _tracker.createInstance<TextConstContext>(_ctx, getState());
  enterRule(_localctx, 54, Ili2Parser::RuleTextConst);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(741);
    dynamic_cast<TextConstContext *>(_localctx)->textconst = match(Ili2Parser::STRING);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- EnumerationTypeContext ------------------------------------------------------------------

Ili2Parser::EnumerationTypeContext::EnumerationTypeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

Ili2Parser::EnumerationContext* Ili2Parser::EnumerationTypeContext::enumeration() {
  return getRuleContext<Ili2Parser::EnumerationContext>(0);
}

tree::TerminalNode* Ili2Parser::EnumerationTypeContext::ORDERED() {
  return getToken(Ili2Parser::ORDERED, 0);
}

tree::TerminalNode* Ili2Parser::EnumerationTypeContext::CIRCULAR() {
  return getToken(Ili2Parser::CIRCULAR, 0);
}


size_t Ili2Parser::EnumerationTypeContext::getRuleIndex() const {
  return Ili2Parser::RuleEnumerationType;
}

antlrcpp::Any Ili2Parser::EnumerationTypeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<Ili2ParserVisitor*>(visitor))
    return parserVisitor->visitEnumerationType(this);
  else
    return visitor->visitChildren(this);
}

Ili2Parser::EnumerationTypeContext* Ili2Parser::enumerationType() {
  EnumerationTypeContext *_localctx = _tracker.createInstance<EnumerationTypeContext>(_ctx, getState());
  enterRule(_localctx, 56, Ili2Parser::RuleEnumerationType);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(743);
    enumeration();
    setState(745);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 84, _ctx)) {
    case 1: {
      setState(744);
      _la = _input->LA(1);
      if (!(_la == Ili2Parser::CIRCULAR

      || _la == Ili2Parser::ORDERED)) {
      _errHandler->recoverInline(this);
      }
      else {
        _errHandler->reportMatch(this);
        consume();
      }
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- EnumTreeValueTypeContext ------------------------------------------------------------------

Ili2Parser::EnumTreeValueTypeContext::EnumTreeValueTypeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* Ili2Parser::EnumTreeValueTypeContext::ALL() {
  return getToken(Ili2Parser::ALL, 0);
}

tree::TerminalNode* Ili2Parser::EnumTreeValueTypeContext::OF() {
  return getToken(Ili2Parser::OF, 0);
}

Ili2Parser::PathContext* Ili2Parser::EnumTreeValueTypeContext::path() {
  return getRuleContext<Ili2Parser::PathContext>(0);
}


size_t Ili2Parser::EnumTreeValueTypeContext::getRuleIndex() const {
  return Ili2Parser::RuleEnumTreeValueType;
}

antlrcpp::Any Ili2Parser::EnumTreeValueTypeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<Ili2ParserVisitor*>(visitor))
    return parserVisitor->visitEnumTreeValueType(this);
  else
    return visitor->visitChildren(this);
}

Ili2Parser::EnumTreeValueTypeContext* Ili2Parser::enumTreeValueType() {
  EnumTreeValueTypeContext *_localctx = _tracker.createInstance<EnumTreeValueTypeContext>(_ctx, getState());
  enterRule(_localctx, 58, Ili2Parser::RuleEnumTreeValueType);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(747);
    match(Ili2Parser::ALL);
    setState(748);
    match(Ili2Parser::OF);
    setState(749);
    dynamic_cast<EnumTreeValueTypeContext *>(_localctx)->typeref = path();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- EnumerationContext ------------------------------------------------------------------

Ili2Parser::EnumerationContext::EnumerationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* Ili2Parser::EnumerationContext::LPAREN() {
  return getToken(Ili2Parser::LPAREN, 0);
}

std::vector<Ili2Parser::EnumElementContext *> Ili2Parser::EnumerationContext::enumElement() {
  return getRuleContexts<Ili2Parser::EnumElementContext>();
}

Ili2Parser::EnumElementContext* Ili2Parser::EnumerationContext::enumElement(size_t i) {
  return getRuleContext<Ili2Parser::EnumElementContext>(i);
}

tree::TerminalNode* Ili2Parser::EnumerationContext::RPAREN() {
  return getToken(Ili2Parser::RPAREN, 0);
}

std::vector<tree::TerminalNode *> Ili2Parser::EnumerationContext::COMMA() {
  return getTokens(Ili2Parser::COMMA);
}

tree::TerminalNode* Ili2Parser::EnumerationContext::COMMA(size_t i) {
  return getToken(Ili2Parser::COMMA, i);
}

tree::TerminalNode* Ili2Parser::EnumerationContext::FINAL() {
  return getToken(Ili2Parser::FINAL, 0);
}

tree::TerminalNode* Ili2Parser::EnumerationContext::COLON() {
  return getToken(Ili2Parser::COLON, 0);
}


size_t Ili2Parser::EnumerationContext::getRuleIndex() const {
  return Ili2Parser::RuleEnumeration;
}

antlrcpp::Any Ili2Parser::EnumerationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<Ili2ParserVisitor*>(visitor))
    return parserVisitor->visitEnumeration(this);
  else
    return visitor->visitChildren(this);
}

Ili2Parser::EnumerationContext* Ili2Parser::enumeration() {
  EnumerationContext *_localctx = _tracker.createInstance<EnumerationContext>(_ctx, getState());
  enterRule(_localctx, 60, Ili2Parser::RuleEnumeration);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(751);
    match(Ili2Parser::LPAREN);
    setState(752);
    enumElement();
    setState(757);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == Ili2Parser::COMMA) {
      setState(753);
      match(Ili2Parser::COMMA);
      setState(754);
      enumElement();
      setState(759);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(765);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 87, _ctx)) {
    case 1: {
      setState(762);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == Ili2Parser::COLON) {
        setState(760);
        match(Ili2Parser::COLON);
        setState(761);
        match(Ili2Parser::FINAL);
      }
      break;
    }

    case 2: {
      setState(764);
      match(Ili2Parser::FINAL);
      break;
    }

    }
    setState(767);
    match(Ili2Parser::RPAREN);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- EnumElementContext ------------------------------------------------------------------

Ili2Parser::EnumElementContext::EnumElementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<tree::TerminalNode *> Ili2Parser::EnumElementContext::NAME() {
  return getTokens(Ili2Parser::NAME);
}

tree::TerminalNode* Ili2Parser::EnumElementContext::NAME(size_t i) {
  return getToken(Ili2Parser::NAME, i);
}

std::vector<tree::TerminalNode *> Ili2Parser::EnumElementContext::DOT() {
  return getTokens(Ili2Parser::DOT);
}

tree::TerminalNode* Ili2Parser::EnumElementContext::DOT(size_t i) {
  return getToken(Ili2Parser::DOT, i);
}

Ili2Parser::EnumerationContext* Ili2Parser::EnumElementContext::enumeration() {
  return getRuleContext<Ili2Parser::EnumerationContext>(0);
}


size_t Ili2Parser::EnumElementContext::getRuleIndex() const {
  return Ili2Parser::RuleEnumElement;
}

antlrcpp::Any Ili2Parser::EnumElementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<Ili2ParserVisitor*>(visitor))
    return parserVisitor->visitEnumElement(this);
  else
    return visitor->visitChildren(this);
}

Ili2Parser::EnumElementContext* Ili2Parser::enumElement() {
  EnumElementContext *_localctx = _tracker.createInstance<EnumElementContext>(_ctx, getState());
  enterRule(_localctx, 62, Ili2Parser::RuleEnumElement);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(769);
    match(Ili2Parser::NAME);
    setState(774);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == Ili2Parser::DOT) {
      setState(770);
      match(Ili2Parser::DOT);
      setState(771);
      match(Ili2Parser::NAME);
      setState(776);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(778);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == Ili2Parser::LPAREN) {
      setState(777);
      dynamic_cast<EnumElementContext *>(_localctx)->sub = enumeration();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- EnumConstContext ------------------------------------------------------------------

Ili2Parser::EnumConstContext::EnumConstContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* Ili2Parser::EnumConstContext::HASH() {
  return getToken(Ili2Parser::HASH, 0);
}

std::vector<tree::TerminalNode *> Ili2Parser::EnumConstContext::NAME() {
  return getTokens(Ili2Parser::NAME);
}

tree::TerminalNode* Ili2Parser::EnumConstContext::NAME(size_t i) {
  return getToken(Ili2Parser::NAME, i);
}

tree::TerminalNode* Ili2Parser::EnumConstContext::OTHERS() {
  return getToken(Ili2Parser::OTHERS, 0);
}

std::vector<tree::TerminalNode *> Ili2Parser::EnumConstContext::DOT() {
  return getTokens(Ili2Parser::DOT);
}

tree::TerminalNode* Ili2Parser::EnumConstContext::DOT(size_t i) {
  return getToken(Ili2Parser::DOT, i);
}


size_t Ili2Parser::EnumConstContext::getRuleIndex() const {
  return Ili2Parser::RuleEnumConst;
}

antlrcpp::Any Ili2Parser::EnumConstContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<Ili2ParserVisitor*>(visitor))
    return parserVisitor->visitEnumConst(this);
  else
    return visitor->visitChildren(this);
}

Ili2Parser::EnumConstContext* Ili2Parser::enumConst() {
  EnumConstContext *_localctx = _tracker.createInstance<EnumConstContext>(_ctx, getState());
  enterRule(_localctx, 64, Ili2Parser::RuleEnumConst);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(780);
    match(Ili2Parser::HASH);
    setState(794);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case Ili2Parser::NAME: {
        setState(781);
        match(Ili2Parser::NAME);
        setState(786);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 90, _ctx);
        while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
          if (alt == 1) {
            setState(782);
            match(Ili2Parser::DOT);
            setState(783);
            match(Ili2Parser::NAME); 
          }
          setState(788);
          _errHandler->sync(this);
          alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 90, _ctx);
        }
        setState(791);
        _errHandler->sync(this);

        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 91, _ctx)) {
        case 1: {
          setState(789);
          match(Ili2Parser::DOT);
          setState(790);
          match(Ili2Parser::OTHERS);
          break;
        }

        }
        break;
      }

      case Ili2Parser::OTHERS: {
        setState(793);
        match(Ili2Parser::OTHERS);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- NumericTypeContext ------------------------------------------------------------------

Ili2Parser::NumericTypeContext::NumericTypeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* Ili2Parser::NumericTypeContext::DOTDOT() {
  return getToken(Ili2Parser::DOTDOT, 0);
}

tree::TerminalNode* Ili2Parser::NumericTypeContext::NUMERIC() {
  return getToken(Ili2Parser::NUMERIC, 0);
}

std::vector<Ili2Parser::DecimalContext *> Ili2Parser::NumericTypeContext::decimal() {
  return getRuleContexts<Ili2Parser::DecimalContext>();
}

Ili2Parser::DecimalContext* Ili2Parser::NumericTypeContext::decimal(size_t i) {
  return getRuleContext<Ili2Parser::DecimalContext>(i);
}

tree::TerminalNode* Ili2Parser::NumericTypeContext::CIRCULAR() {
  return getToken(Ili2Parser::CIRCULAR, 0);
}

tree::TerminalNode* Ili2Parser::NumericTypeContext::LBRACE() {
  return getToken(Ili2Parser::LBRACE, 0);
}

tree::TerminalNode* Ili2Parser::NumericTypeContext::RBRACE() {
  return getToken(Ili2Parser::RBRACE, 0);
}

tree::TerminalNode* Ili2Parser::NumericTypeContext::CLOCKWISE() {
  return getToken(Ili2Parser::CLOCKWISE, 0);
}

tree::TerminalNode* Ili2Parser::NumericTypeContext::COUNTERCLOCKWISE() {
  return getToken(Ili2Parser::COUNTERCLOCKWISE, 0);
}

Ili2Parser::RefSysContext* Ili2Parser::NumericTypeContext::refSys() {
  return getRuleContext<Ili2Parser::RefSysContext>(0);
}

Ili2Parser::PathContext* Ili2Parser::NumericTypeContext::path() {
  return getRuleContext<Ili2Parser::PathContext>(0);
}


size_t Ili2Parser::NumericTypeContext::getRuleIndex() const {
  return Ili2Parser::RuleNumericType;
}

antlrcpp::Any Ili2Parser::NumericTypeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<Ili2ParserVisitor*>(visitor))
    return parserVisitor->visitNumericType(this);
  else
    return visitor->visitChildren(this);
}

Ili2Parser::NumericTypeContext* Ili2Parser::numericType() {
  NumericTypeContext *_localctx = _tracker.createInstance<NumericTypeContext>(_ctx, getState());
  enterRule(_localctx, 66, Ili2Parser::RuleNumericType);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(801);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case Ili2Parser::POSNUMBER:
      case Ili2Parser::NUMBER:
      case Ili2Parser::DEC: {
        setState(796);
        dynamic_cast<NumericTypeContext *>(_localctx)->min = decimal();
        setState(797);
        match(Ili2Parser::DOTDOT);
        setState(798);
        dynamic_cast<NumericTypeContext *>(_localctx)->max = decimal();
        break;
      }

      case Ili2Parser::NUMERIC: {
        setState(800);
        match(Ili2Parser::NUMERIC);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    setState(804);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 94, _ctx)) {
    case 1: {
      setState(803);
      match(Ili2Parser::CIRCULAR);
      break;
    }

    }
    setState(810);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 95, _ctx)) {
    case 1: {
      setState(806);
      match(Ili2Parser::LBRACE);
      setState(807);
      dynamic_cast<NumericTypeContext *>(_localctx)->unitref = path();
      setState(808);
      match(Ili2Parser::RBRACE);
      break;
    }

    }
    setState(815);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 96, _ctx)) {
    case 1: {
      setState(812);
      match(Ili2Parser::CLOCKWISE);
      break;
    }

    case 2: {
      setState(813);
      match(Ili2Parser::COUNTERCLOCKWISE);
      break;
    }

    case 3: {
      setState(814);
      refSys();
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- DateTimeTypeContext ------------------------------------------------------------------

Ili2Parser::DateTimeTypeContext::DateTimeTypeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* Ili2Parser::DateTimeTypeContext::DATE() {
  return getToken(Ili2Parser::DATE, 0);
}

tree::TerminalNode* Ili2Parser::DateTimeTypeContext::TIMEOFDAY() {
  return getToken(Ili2Parser::TIMEOFDAY, 0);
}

tree::TerminalNode* Ili2Parser::DateTimeTypeContext::DATETIME() {
  return getToken(Ili2Parser::DATETIME, 0);
}


size_t Ili2Parser::DateTimeTypeContext::getRuleIndex() const {
  return Ili2Parser::RuleDateTimeType;
}

antlrcpp::Any Ili2Parser::DateTimeTypeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<Ili2ParserVisitor*>(visitor))
    return parserVisitor->visitDateTimeType(this);
  else
    return visitor->visitChildren(this);
}

Ili2Parser::DateTimeTypeContext* Ili2Parser::dateTimeType() {
  DateTimeTypeContext *_localctx = _tracker.createInstance<DateTimeTypeContext>(_ctx, getState());
  enterRule(_localctx, 68, Ili2Parser::RuleDateTimeType);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(817);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << Ili2Parser::DATE)
      | (1ULL << Ili2Parser::TIMEOFDAY)
      | (1ULL << Ili2Parser::DATETIME))) != 0))) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- RefSysContext ------------------------------------------------------------------

Ili2Parser::RefSysContext::RefSysContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* Ili2Parser::RefSysContext::LCURLY() {
  return getToken(Ili2Parser::LCURLY, 0);
}

tree::TerminalNode* Ili2Parser::RefSysContext::RCURLY() {
  return getToken(Ili2Parser::RCURLY, 0);
}

tree::TerminalNode* Ili2Parser::RefSysContext::LESS() {
  return getToken(Ili2Parser::LESS, 0);
}

tree::TerminalNode* Ili2Parser::RefSysContext::GREATER() {
  return getToken(Ili2Parser::GREATER, 0);
}

Ili2Parser::MetaObjectRefContext* Ili2Parser::RefSysContext::metaObjectRef() {
  return getRuleContext<Ili2Parser::MetaObjectRefContext>(0);
}

Ili2Parser::PathContext* Ili2Parser::RefSysContext::path() {
  return getRuleContext<Ili2Parser::PathContext>(0);
}

tree::TerminalNode* Ili2Parser::RefSysContext::LBRACE() {
  return getToken(Ili2Parser::LBRACE, 0);
}

tree::TerminalNode* Ili2Parser::RefSysContext::RBRACE() {
  return getToken(Ili2Parser::RBRACE, 0);
}

tree::TerminalNode* Ili2Parser::RefSysContext::POSNUMBER() {
  return getToken(Ili2Parser::POSNUMBER, 0);
}


size_t Ili2Parser::RefSysContext::getRuleIndex() const {
  return Ili2Parser::RuleRefSys;
}

antlrcpp::Any Ili2Parser::RefSysContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<Ili2ParserVisitor*>(visitor))
    return parserVisitor->visitRefSys(this);
  else
    return visitor->visitChildren(this);
}

Ili2Parser::RefSysContext* Ili2Parser::refSys() {
  RefSysContext *_localctx = _tracker.createInstance<RefSysContext>(_ctx, getState());
  enterRule(_localctx, 70, Ili2Parser::RuleRefSys);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(837);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case Ili2Parser::LCURLY: {
        setState(819);
        match(Ili2Parser::LCURLY);
        setState(820);
        dynamic_cast<RefSysContext *>(_localctx)->refsys = metaObjectRef();
        setState(824);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == Ili2Parser::LBRACE) {
          setState(821);
          match(Ili2Parser::LBRACE);
          setState(822);
          dynamic_cast<RefSysContext *>(_localctx)->axis = match(Ili2Parser::POSNUMBER);
          setState(823);
          match(Ili2Parser::RBRACE);
        }
        setState(826);
        match(Ili2Parser::RCURLY);
        break;
      }

      case Ili2Parser::LESS: {
        setState(828);
        match(Ili2Parser::LESS);
        setState(829);
        dynamic_cast<RefSysContext *>(_localctx)->coord = path();
        setState(833);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == Ili2Parser::LBRACE) {
          setState(830);
          match(Ili2Parser::LBRACE);
          setState(831);
          dynamic_cast<RefSysContext *>(_localctx)->axis = match(Ili2Parser::POSNUMBER);
          setState(832);
          match(Ili2Parser::RBRACE);
        }
        setState(835);
        match(Ili2Parser::GREATER);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- DecConstContext ------------------------------------------------------------------

Ili2Parser::DecConstContext::DecConstContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

Ili2Parser::DecimalContext* Ili2Parser::DecConstContext::decimal() {
  return getRuleContext<Ili2Parser::DecimalContext>(0);
}

tree::TerminalNode* Ili2Parser::DecConstContext::PI() {
  return getToken(Ili2Parser::PI, 0);
}

tree::TerminalNode* Ili2Parser::DecConstContext::LNBASE() {
  return getToken(Ili2Parser::LNBASE, 0);
}


size_t Ili2Parser::DecConstContext::getRuleIndex() const {
  return Ili2Parser::RuleDecConst;
}

antlrcpp::Any Ili2Parser::DecConstContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<Ili2ParserVisitor*>(visitor))
    return parserVisitor->visitDecConst(this);
  else
    return visitor->visitChildren(this);
}

Ili2Parser::DecConstContext* Ili2Parser::decConst() {
  DecConstContext *_localctx = _tracker.createInstance<DecConstContext>(_ctx, getState());
  enterRule(_localctx, 72, Ili2Parser::RuleDecConst);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(842);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case Ili2Parser::POSNUMBER:
      case Ili2Parser::NUMBER:
      case Ili2Parser::DEC: {
        enterOuterAlt(_localctx, 1);
        setState(839);
        dynamic_cast<DecConstContext *>(_localctx)->dec = decimal();
        break;
      }

      case Ili2Parser::PI: {
        enterOuterAlt(_localctx, 2);
        setState(840);
        match(Ili2Parser::PI);
        break;
      }

      case Ili2Parser::LNBASE: {
        enterOuterAlt(_localctx, 3);
        setState(841);
        match(Ili2Parser::LNBASE);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- NumericConstContext ------------------------------------------------------------------

Ili2Parser::NumericConstContext::NumericConstContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

Ili2Parser::DecConstContext* Ili2Parser::NumericConstContext::decConst() {
  return getRuleContext<Ili2Parser::DecConstContext>(0);
}

tree::TerminalNode* Ili2Parser::NumericConstContext::LBRACE() {
  return getToken(Ili2Parser::LBRACE, 0);
}

tree::TerminalNode* Ili2Parser::NumericConstContext::RBRACE() {
  return getToken(Ili2Parser::RBRACE, 0);
}

Ili2Parser::PathContext* Ili2Parser::NumericConstContext::path() {
  return getRuleContext<Ili2Parser::PathContext>(0);
}


size_t Ili2Parser::NumericConstContext::getRuleIndex() const {
  return Ili2Parser::RuleNumericConst;
}

antlrcpp::Any Ili2Parser::NumericConstContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<Ili2ParserVisitor*>(visitor))
    return parserVisitor->visitNumericConst(this);
  else
    return visitor->visitChildren(this);
}

Ili2Parser::NumericConstContext* Ili2Parser::numericConst() {
  NumericConstContext *_localctx = _tracker.createInstance<NumericConstContext>(_ctx, getState());
  enterRule(_localctx, 74, Ili2Parser::RuleNumericConst);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(844);
    decConst();
    setState(849);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 101, _ctx)) {
    case 1: {
      setState(845);
      match(Ili2Parser::LBRACE);
      setState(846);
      dynamic_cast<NumericConstContext *>(_localctx)->unitref = path();
      setState(847);
      match(Ili2Parser::RBRACE);
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FormattedTypeContext ------------------------------------------------------------------

Ili2Parser::FormattedTypeContext::FormattedTypeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* Ili2Parser::FormattedTypeContext::FORMAT() {
  return getToken(Ili2Parser::FORMAT, 0);
}

tree::TerminalNode* Ili2Parser::FormattedTypeContext::BASED() {
  return getToken(Ili2Parser::BASED, 0);
}

tree::TerminalNode* Ili2Parser::FormattedTypeContext::ON() {
  return getToken(Ili2Parser::ON, 0);
}

Ili2Parser::FormatDefContext* Ili2Parser::FormattedTypeContext::formatDef() {
  return getRuleContext<Ili2Parser::FormatDefContext>(0);
}

tree::TerminalNode* Ili2Parser::FormattedTypeContext::DOTDOT() {
  return getToken(Ili2Parser::DOTDOT, 0);
}

Ili2Parser::PathContext* Ili2Parser::FormattedTypeContext::path() {
  return getRuleContext<Ili2Parser::PathContext>(0);
}

std::vector<tree::TerminalNode *> Ili2Parser::FormattedTypeContext::STRING() {
  return getTokens(Ili2Parser::STRING);
}

tree::TerminalNode* Ili2Parser::FormattedTypeContext::STRING(size_t i) {
  return getToken(Ili2Parser::STRING, i);
}


size_t Ili2Parser::FormattedTypeContext::getRuleIndex() const {
  return Ili2Parser::RuleFormattedType;
}

antlrcpp::Any Ili2Parser::FormattedTypeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<Ili2ParserVisitor*>(visitor))
    return parserVisitor->visitFormattedType(this);
  else
    return visitor->visitChildren(this);
}

Ili2Parser::FormattedTypeContext* Ili2Parser::formattedType() {
  FormattedTypeContext *_localctx = _tracker.createInstance<FormattedTypeContext>(_ctx, getState());
  enterRule(_localctx, 76, Ili2Parser::RuleFormattedType);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(870);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 104, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(857);
      _errHandler->sync(this);

      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 102, _ctx)) {
      case 1: {
        setState(851);
        match(Ili2Parser::FORMAT);
        setState(852);
        match(Ili2Parser::BASED);
        setState(853);
        match(Ili2Parser::ON);
        setState(854);
        dynamic_cast<FormattedTypeContext *>(_localctx)->typeref = path();
        setState(855);
        formatDef();
        break;
      }

      }
      setState(862);
      _errHandler->sync(this);

      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 103, _ctx)) {
      case 1: {
        setState(859);
        dynamic_cast<FormattedTypeContext *>(_localctx)->min = match(Ili2Parser::STRING);
        setState(860);
        match(Ili2Parser::DOTDOT);
        setState(861);
        dynamic_cast<FormattedTypeContext *>(_localctx)->max = match(Ili2Parser::STRING);
        break;
      }

      }
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(864);
      match(Ili2Parser::FORMAT);
      setState(865);
      dynamic_cast<FormattedTypeContext *>(_localctx)->typeref = path();
      setState(866);
      dynamic_cast<FormattedTypeContext *>(_localctx)->min = match(Ili2Parser::STRING);
      setState(867);
      match(Ili2Parser::DOTDOT);
      setState(868);
      dynamic_cast<FormattedTypeContext *>(_localctx)->max = match(Ili2Parser::STRING);
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FormatDefContext ------------------------------------------------------------------

Ili2Parser::FormatDefContext::FormatDefContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* Ili2Parser::FormatDefContext::LPAREN() {
  return getToken(Ili2Parser::LPAREN, 0);
}

std::vector<Ili2Parser::BaseAttrRefContext *> Ili2Parser::FormatDefContext::baseAttrRef() {
  return getRuleContexts<Ili2Parser::BaseAttrRefContext>();
}

Ili2Parser::BaseAttrRefContext* Ili2Parser::FormatDefContext::baseAttrRef(size_t i) {
  return getRuleContext<Ili2Parser::BaseAttrRefContext>(i);
}

tree::TerminalNode* Ili2Parser::FormatDefContext::RPAREN() {
  return getToken(Ili2Parser::RPAREN, 0);
}

tree::TerminalNode* Ili2Parser::FormatDefContext::INHERITANCE() {
  return getToken(Ili2Parser::INHERITANCE, 0);
}

std::vector<tree::TerminalNode *> Ili2Parser::FormatDefContext::STRING() {
  return getTokens(Ili2Parser::STRING);
}

tree::TerminalNode* Ili2Parser::FormatDefContext::STRING(size_t i) {
  return getToken(Ili2Parser::STRING, i);
}


size_t Ili2Parser::FormatDefContext::getRuleIndex() const {
  return Ili2Parser::RuleFormatDef;
}

antlrcpp::Any Ili2Parser::FormatDefContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<Ili2ParserVisitor*>(visitor))
    return parserVisitor->visitFormatDef(this);
  else
    return visitor->visitChildren(this);
}

Ili2Parser::FormatDefContext* Ili2Parser::formatDef() {
  FormatDefContext *_localctx = _tracker.createInstance<FormatDefContext>(_ctx, getState());
  enterRule(_localctx, 78, Ili2Parser::RuleFormatDef);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(872);
    match(Ili2Parser::LPAREN);
    setState(874);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == Ili2Parser::INHERITANCE) {
      setState(873);
      match(Ili2Parser::INHERITANCE);
    }
    setState(877);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == Ili2Parser::STRING) {
      setState(876);
      dynamic_cast<FormatDefContext *>(_localctx)->nonnumeric = match(Ili2Parser::STRING);
    }
    setState(884);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 107, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(879);
        baseAttrRef();
        setState(880);
        dynamic_cast<FormatDefContext *>(_localctx)->nonnumeric = match(Ili2Parser::STRING); 
      }
      setState(886);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 107, _ctx);
    }
    setState(887);
    baseAttrRef();
    setState(889);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == Ili2Parser::STRING) {
      setState(888);
      dynamic_cast<FormatDefContext *>(_localctx)->nonnumeric = match(Ili2Parser::STRING);
    }
    setState(891);
    match(Ili2Parser::RPAREN);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- BaseAttrRefContext ------------------------------------------------------------------

Ili2Parser::BaseAttrRefContext::BaseAttrRefContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* Ili2Parser::BaseAttrRefContext::NAME() {
  return getToken(Ili2Parser::NAME, 0);
}

tree::TerminalNode* Ili2Parser::BaseAttrRefContext::SLASH() {
  return getToken(Ili2Parser::SLASH, 0);
}

tree::TerminalNode* Ili2Parser::BaseAttrRefContext::POSNUMBER() {
  return getToken(Ili2Parser::POSNUMBER, 0);
}

Ili2Parser::PathContext* Ili2Parser::BaseAttrRefContext::path() {
  return getRuleContext<Ili2Parser::PathContext>(0);
}


size_t Ili2Parser::BaseAttrRefContext::getRuleIndex() const {
  return Ili2Parser::RuleBaseAttrRef;
}

antlrcpp::Any Ili2Parser::BaseAttrRefContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<Ili2ParserVisitor*>(visitor))
    return parserVisitor->visitBaseAttrRef(this);
  else
    return visitor->visitChildren(this);
}

Ili2Parser::BaseAttrRefContext* Ili2Parser::baseAttrRef() {
  BaseAttrRefContext *_localctx = _tracker.createInstance<BaseAttrRefContext>(_ctx, getState());
  enterRule(_localctx, 80, Ili2Parser::RuleBaseAttrRef);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(901);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 110, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(893);
      match(Ili2Parser::NAME);
      setState(896);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == Ili2Parser::SLASH) {
        setState(894);
        match(Ili2Parser::SLASH);
        setState(895);
        match(Ili2Parser::POSNUMBER);
      }
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(898);
      match(Ili2Parser::NAME);
      setState(899);
      match(Ili2Parser::SLASH);
      setState(900);
      dynamic_cast<BaseAttrRefContext *>(_localctx)->baseattr = path();
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FormattedConstContext ------------------------------------------------------------------

Ili2Parser::FormattedConstContext::FormattedConstContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* Ili2Parser::FormattedConstContext::STRING() {
  return getToken(Ili2Parser::STRING, 0);
}


size_t Ili2Parser::FormattedConstContext::getRuleIndex() const {
  return Ili2Parser::RuleFormattedConst;
}

antlrcpp::Any Ili2Parser::FormattedConstContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<Ili2ParserVisitor*>(visitor))
    return parserVisitor->visitFormattedConst(this);
  else
    return visitor->visitChildren(this);
}

Ili2Parser::FormattedConstContext* Ili2Parser::formattedConst() {
  FormattedConstContext *_localctx = _tracker.createInstance<FormattedConstContext>(_ctx, getState());
  enterRule(_localctx, 82, Ili2Parser::RuleFormattedConst);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(903);
    dynamic_cast<FormattedConstContext *>(_localctx)->formattedconst = match(Ili2Parser::STRING);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ContextDefContext ------------------------------------------------------------------

Ili2Parser::ContextDefContext::ContextDefContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* Ili2Parser::ContextDefContext::CONTEXT() {
  return getToken(Ili2Parser::CONTEXT, 0);
}

std::vector<Ili2Parser::ContextDeclContext *> Ili2Parser::ContextDefContext::contextDecl() {
  return getRuleContexts<Ili2Parser::ContextDeclContext>();
}

Ili2Parser::ContextDeclContext* Ili2Parser::ContextDefContext::contextDecl(size_t i) {
  return getRuleContext<Ili2Parser::ContextDeclContext>(i);
}

std::vector<tree::TerminalNode *> Ili2Parser::ContextDefContext::SEMI() {
  return getTokens(Ili2Parser::SEMI);
}

tree::TerminalNode* Ili2Parser::ContextDefContext::SEMI(size_t i) {
  return getToken(Ili2Parser::SEMI, i);
}


size_t Ili2Parser::ContextDefContext::getRuleIndex() const {
  return Ili2Parser::RuleContextDef;
}

antlrcpp::Any Ili2Parser::ContextDefContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<Ili2ParserVisitor*>(visitor))
    return parserVisitor->visitContextDef(this);
  else
    return visitor->visitChildren(this);
}

Ili2Parser::ContextDefContext* Ili2Parser::contextDef() {
  ContextDefContext *_localctx = _tracker.createInstance<ContextDefContext>(_ctx, getState());
  enterRule(_localctx, 84, Ili2Parser::RuleContextDef);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(905);
    match(Ili2Parser::CONTEXT);
    setState(911);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 111, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(906);
        contextDecl();
        setState(907);
        match(Ili2Parser::SEMI); 
      }
      setState(913);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 111, _ctx);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ContextDeclContext ------------------------------------------------------------------

Ili2Parser::ContextDeclContext::ContextDeclContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* Ili2Parser::ContextDeclContext::EQUAL() {
  return getToken(Ili2Parser::EQUAL, 0);
}

std::vector<Ili2Parser::PathContext *> Ili2Parser::ContextDeclContext::path() {
  return getRuleContexts<Ili2Parser::PathContext>();
}

Ili2Parser::PathContext* Ili2Parser::ContextDeclContext::path(size_t i) {
  return getRuleContext<Ili2Parser::PathContext>(i);
}

tree::TerminalNode* Ili2Parser::ContextDeclContext::NAME() {
  return getToken(Ili2Parser::NAME, 0);
}

std::vector<tree::TerminalNode *> Ili2Parser::ContextDeclContext::OR() {
  return getTokens(Ili2Parser::OR);
}

tree::TerminalNode* Ili2Parser::ContextDeclContext::OR(size_t i) {
  return getToken(Ili2Parser::OR, i);
}


size_t Ili2Parser::ContextDeclContext::getRuleIndex() const {
  return Ili2Parser::RuleContextDecl;
}

antlrcpp::Any Ili2Parser::ContextDeclContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<Ili2ParserVisitor*>(visitor))
    return parserVisitor->visitContextDecl(this);
  else
    return visitor->visitChildren(this);
}

Ili2Parser::ContextDeclContext* Ili2Parser::contextDecl() {
  ContextDeclContext *_localctx = _tracker.createInstance<ContextDeclContext>(_ctx, getState());
  enterRule(_localctx, 86, Ili2Parser::RuleContextDecl);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(914);
    dynamic_cast<ContextDeclContext *>(_localctx)->name = match(Ili2Parser::NAME);
    setState(915);
    match(Ili2Parser::EQUAL);
    setState(916);
    path();
    setState(921);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == Ili2Parser::OR) {
      setState(917);
      match(Ili2Parser::OR);
      setState(918);
      path();
      setState(923);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- CoordinateTypeContext ------------------------------------------------------------------

Ili2Parser::CoordinateTypeContext::CoordinateTypeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<Ili2Parser::NumericTypeContext *> Ili2Parser::CoordinateTypeContext::numericType() {
  return getRuleContexts<Ili2Parser::NumericTypeContext>();
}

Ili2Parser::NumericTypeContext* Ili2Parser::CoordinateTypeContext::numericType(size_t i) {
  return getRuleContext<Ili2Parser::NumericTypeContext>(i);
}

tree::TerminalNode* Ili2Parser::CoordinateTypeContext::COORD() {
  return getToken(Ili2Parser::COORD, 0);
}

tree::TerminalNode* Ili2Parser::CoordinateTypeContext::MULTICOORD() {
  return getToken(Ili2Parser::MULTICOORD, 0);
}

std::vector<tree::TerminalNode *> Ili2Parser::CoordinateTypeContext::COMMA() {
  return getTokens(Ili2Parser::COMMA);
}

tree::TerminalNode* Ili2Parser::CoordinateTypeContext::COMMA(size_t i) {
  return getToken(Ili2Parser::COMMA, i);
}

Ili2Parser::RotationDefContext* Ili2Parser::CoordinateTypeContext::rotationDef() {
  return getRuleContext<Ili2Parser::RotationDefContext>(0);
}


size_t Ili2Parser::CoordinateTypeContext::getRuleIndex() const {
  return Ili2Parser::RuleCoordinateType;
}

antlrcpp::Any Ili2Parser::CoordinateTypeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<Ili2ParserVisitor*>(visitor))
    return parserVisitor->visitCoordinateType(this);
  else
    return visitor->visitChildren(this);
}

Ili2Parser::CoordinateTypeContext* Ili2Parser::coordinateType() {
  CoordinateTypeContext *_localctx = _tracker.createInstance<CoordinateTypeContext>(_ctx, getState());
  enterRule(_localctx, 88, Ili2Parser::RuleCoordinateType);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(928);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 113, _ctx)) {
    case 1: {
      setState(924);

      if (!(ili23)) throw FailedPredicateException(this, "ili23");
      setState(925);
      match(Ili2Parser::COORD);
      break;
    }

    case 2: {
      setState(926);

      if (!(ili24)) throw FailedPredicateException(this, "ili24");
      setState(927);
      match(Ili2Parser::MULTICOORD);
      break;
    }

    }
    setState(930);
    dynamic_cast<CoordinateTypeContext *>(_localctx)->numtype1 = numericType();
    setState(937);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 115, _ctx)) {
    case 1: {
      setState(931);
      match(Ili2Parser::COMMA);
      setState(932);
      dynamic_cast<CoordinateTypeContext *>(_localctx)->numtype2 = numericType();
      setState(935);
      _errHandler->sync(this);

      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 114, _ctx)) {
      case 1: {
        setState(933);
        match(Ili2Parser::COMMA);
        setState(934);
        dynamic_cast<CoordinateTypeContext *>(_localctx)->numtype3 = numericType();
        break;
      }

      }
      break;
    }

    }
    setState(941);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 116, _ctx)) {
    case 1: {
      setState(939);
      match(Ili2Parser::COMMA);
      setState(940);
      rotationDef();
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- RotationDefContext ------------------------------------------------------------------

Ili2Parser::RotationDefContext::RotationDefContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* Ili2Parser::RotationDefContext::ROTATION() {
  return getToken(Ili2Parser::ROTATION, 0);
}

tree::TerminalNode* Ili2Parser::RotationDefContext::RARROW() {
  return getToken(Ili2Parser::RARROW, 0);
}

std::vector<tree::TerminalNode *> Ili2Parser::RotationDefContext::POSNUMBER() {
  return getTokens(Ili2Parser::POSNUMBER);
}

tree::TerminalNode* Ili2Parser::RotationDefContext::POSNUMBER(size_t i) {
  return getToken(Ili2Parser::POSNUMBER, i);
}


size_t Ili2Parser::RotationDefContext::getRuleIndex() const {
  return Ili2Parser::RuleRotationDef;
}

antlrcpp::Any Ili2Parser::RotationDefContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<Ili2ParserVisitor*>(visitor))
    return parserVisitor->visitRotationDef(this);
  else
    return visitor->visitChildren(this);
}

Ili2Parser::RotationDefContext* Ili2Parser::rotationDef() {
  RotationDefContext *_localctx = _tracker.createInstance<RotationDefContext>(_ctx, getState());
  enterRule(_localctx, 90, Ili2Parser::RuleRotationDef);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(943);
    match(Ili2Parser::ROTATION);
    setState(944);
    dynamic_cast<RotationDefContext *>(_localctx)->nullaxis = match(Ili2Parser::POSNUMBER);
    setState(945);
    match(Ili2Parser::RARROW);
    setState(946);
    dynamic_cast<RotationDefContext *>(_localctx)->pihalfaxis = match(Ili2Parser::POSNUMBER);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- OIDTypeContext ------------------------------------------------------------------

Ili2Parser::OIDTypeContext::OIDTypeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* Ili2Parser::OIDTypeContext::OID() {
  return getToken(Ili2Parser::OID, 0);
}

tree::TerminalNode* Ili2Parser::OIDTypeContext::ANY() {
  return getToken(Ili2Parser::ANY, 0);
}

Ili2Parser::NumericTypeContext* Ili2Parser::OIDTypeContext::numericType() {
  return getRuleContext<Ili2Parser::NumericTypeContext>(0);
}

Ili2Parser::TextTypeContext* Ili2Parser::OIDTypeContext::textType() {
  return getRuleContext<Ili2Parser::TextTypeContext>(0);
}


size_t Ili2Parser::OIDTypeContext::getRuleIndex() const {
  return Ili2Parser::RuleOIDType;
}

antlrcpp::Any Ili2Parser::OIDTypeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<Ili2ParserVisitor*>(visitor))
    return parserVisitor->visitOIDType(this);
  else
    return visitor->visitChildren(this);
}

Ili2Parser::OIDTypeContext* Ili2Parser::oIDType() {
  OIDTypeContext *_localctx = _tracker.createInstance<OIDTypeContext>(_ctx, getState());
  enterRule(_localctx, 92, Ili2Parser::RuleOIDType);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(948);
    match(Ili2Parser::OID);
    setState(952);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case Ili2Parser::ANY: {
        setState(949);
        match(Ili2Parser::ANY);
        break;
      }

      case Ili2Parser::NUMERIC:
      case Ili2Parser::POSNUMBER:
      case Ili2Parser::NUMBER:
      case Ili2Parser::DEC: {
        setState(950);
        numericType();
        break;
      }

      case Ili2Parser::TEXT:
      case Ili2Parser::MTEXT: {
        setState(951);
        textType();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- BlackboxTypeContext ------------------------------------------------------------------

Ili2Parser::BlackboxTypeContext::BlackboxTypeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* Ili2Parser::BlackboxTypeContext::BLACKBOX() {
  return getToken(Ili2Parser::BLACKBOX, 0);
}

tree::TerminalNode* Ili2Parser::BlackboxTypeContext::XML() {
  return getToken(Ili2Parser::XML, 0);
}

tree::TerminalNode* Ili2Parser::BlackboxTypeContext::BINARY() {
  return getToken(Ili2Parser::BINARY, 0);
}


size_t Ili2Parser::BlackboxTypeContext::getRuleIndex() const {
  return Ili2Parser::RuleBlackboxType;
}

antlrcpp::Any Ili2Parser::BlackboxTypeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<Ili2ParserVisitor*>(visitor))
    return parserVisitor->visitBlackboxType(this);
  else
    return visitor->visitChildren(this);
}

Ili2Parser::BlackboxTypeContext* Ili2Parser::blackboxType() {
  BlackboxTypeContext *_localctx = _tracker.createInstance<BlackboxTypeContext>(_ctx, getState());
  enterRule(_localctx, 94, Ili2Parser::RuleBlackboxType);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(954);
    match(Ili2Parser::BLACKBOX);
    setState(955);
    _la = _input->LA(1);
    if (!(_la == Ili2Parser::XML

    || _la == Ili2Parser::BINARY)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ClassTypeContext ------------------------------------------------------------------

Ili2Parser::ClassTypeContext::ClassTypeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* Ili2Parser::ClassTypeContext::CLASS() {
  return getToken(Ili2Parser::CLASS, 0);
}

Ili2Parser::RestrictionContext* Ili2Parser::ClassTypeContext::restriction() {
  return getRuleContext<Ili2Parser::RestrictionContext>(0);
}

tree::TerminalNode* Ili2Parser::ClassTypeContext::STRUCTURE() {
  return getToken(Ili2Parser::STRUCTURE, 0);
}


size_t Ili2Parser::ClassTypeContext::getRuleIndex() const {
  return Ili2Parser::RuleClassType;
}

antlrcpp::Any Ili2Parser::ClassTypeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<Ili2ParserVisitor*>(visitor))
    return parserVisitor->visitClassType(this);
  else
    return visitor->visitChildren(this);
}

Ili2Parser::ClassTypeContext* Ili2Parser::classType() {
  ClassTypeContext *_localctx = _tracker.createInstance<ClassTypeContext>(_ctx, getState());
  enterRule(_localctx, 96, Ili2Parser::RuleClassType);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(965);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case Ili2Parser::CLASS: {
        enterOuterAlt(_localctx, 1);
        setState(957);
        match(Ili2Parser::CLASS);
        setState(959);
        _errHandler->sync(this);

        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 118, _ctx)) {
        case 1: {
          setState(958);
          restriction();
          break;
        }

        }
        break;
      }

      case Ili2Parser::STRUCTURE: {
        enterOuterAlt(_localctx, 2);
        setState(961);
        match(Ili2Parser::STRUCTURE);
        setState(963);
        _errHandler->sync(this);

        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 119, _ctx)) {
        case 1: {
          setState(962);
          restriction();
          break;
        }

        }
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- AttributeTypeContext ------------------------------------------------------------------

Ili2Parser::AttributeTypeContext::AttributeTypeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* Ili2Parser::AttributeTypeContext::ATTRIBUTE() {
  return getToken(Ili2Parser::ATTRIBUTE, 0);
}

tree::TerminalNode* Ili2Parser::AttributeTypeContext::OF() {
  return getToken(Ili2Parser::OF, 0);
}

tree::TerminalNode* Ili2Parser::AttributeTypeContext::RESTRICTION() {
  return getToken(Ili2Parser::RESTRICTION, 0);
}

tree::TerminalNode* Ili2Parser::AttributeTypeContext::LPAREN() {
  return getToken(Ili2Parser::LPAREN, 0);
}

std::vector<Ili2Parser::AttrTypeDefContext *> Ili2Parser::AttributeTypeContext::attrTypeDef() {
  return getRuleContexts<Ili2Parser::AttrTypeDefContext>();
}

Ili2Parser::AttrTypeDefContext* Ili2Parser::AttributeTypeContext::attrTypeDef(size_t i) {
  return getRuleContext<Ili2Parser::AttrTypeDefContext>(i);
}

tree::TerminalNode* Ili2Parser::AttributeTypeContext::RPAREN() {
  return getToken(Ili2Parser::RPAREN, 0);
}

Ili2Parser::AttributePathContext* Ili2Parser::AttributeTypeContext::attributePath() {
  return getRuleContext<Ili2Parser::AttributePathContext>(0);
}

tree::TerminalNode* Ili2Parser::AttributeTypeContext::ATT() {
  return getToken(Ili2Parser::ATT, 0);
}

tree::TerminalNode* Ili2Parser::AttributeTypeContext::NAME() {
  return getToken(Ili2Parser::NAME, 0);
}

std::vector<tree::TerminalNode *> Ili2Parser::AttributeTypeContext::COLON() {
  return getTokens(Ili2Parser::COLON);
}

tree::TerminalNode* Ili2Parser::AttributeTypeContext::COLON(size_t i) {
  return getToken(Ili2Parser::COLON, i);
}


size_t Ili2Parser::AttributeTypeContext::getRuleIndex() const {
  return Ili2Parser::RuleAttributeType;
}

antlrcpp::Any Ili2Parser::AttributeTypeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<Ili2ParserVisitor*>(visitor))
    return parserVisitor->visitAttributeType(this);
  else
    return visitor->visitChildren(this);
}

Ili2Parser::AttributeTypeContext* Ili2Parser::attributeType() {
  AttributeTypeContext *_localctx = _tracker.createInstance<AttributeTypeContext>(_ctx, getState());
  enterRule(_localctx, 98, Ili2Parser::RuleAttributeType);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(967);
    match(Ili2Parser::ATTRIBUTE);
    setState(974);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 122, _ctx)) {
    case 1: {
      setState(968);
      match(Ili2Parser::OF);
      setState(972);
      _errHandler->sync(this);
      switch (_input->LA(1)) {
        case Ili2Parser::BACKSLASH:
        case Ili2Parser::THIS:
        case Ili2Parser::THISAREA:
        case Ili2Parser::THATAREA:
        case Ili2Parser::PARENT:
        case Ili2Parser::AGGREGATES:
        case Ili2Parser::NAME: {
          setState(969);
          attributePath();
          break;
        }

        case Ili2Parser::ATT: {
          setState(970);
          match(Ili2Parser::ATT);
          setState(971);
          match(Ili2Parser::NAME);
          break;
        }

      default:
        throw NoViableAltException(this);
      }
      break;
    }

    }
    setState(988);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 124, _ctx)) {
    case 1: {
      setState(976);
      match(Ili2Parser::RESTRICTION);
      setState(977);
      match(Ili2Parser::LPAREN);
      setState(978);
      attrTypeDef();
      setState(983);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == Ili2Parser::COLON) {
        setState(979);
        match(Ili2Parser::COLON);
        setState(980);
        attrTypeDef();
        setState(985);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(986);
      match(Ili2Parser::RPAREN);
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ClassConstContext ------------------------------------------------------------------

Ili2Parser::ClassConstContext::ClassConstContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* Ili2Parser::ClassConstContext::GREATER() {
  return getToken(Ili2Parser::GREATER, 0);
}

Ili2Parser::PathContext* Ili2Parser::ClassConstContext::path() {
  return getRuleContext<Ili2Parser::PathContext>(0);
}


size_t Ili2Parser::ClassConstContext::getRuleIndex() const {
  return Ili2Parser::RuleClassConst;
}

antlrcpp::Any Ili2Parser::ClassConstContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<Ili2ParserVisitor*>(visitor))
    return parserVisitor->visitClassConst(this);
  else
    return visitor->visitChildren(this);
}

Ili2Parser::ClassConstContext* Ili2Parser::classConst() {
  ClassConstContext *_localctx = _tracker.createInstance<ClassConstContext>(_ctx, getState());
  enterRule(_localctx, 100, Ili2Parser::RuleClassConst);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(990);
    match(Ili2Parser::GREATER);
    setState(991);
    dynamic_cast<ClassConstContext *>(_localctx)->classref = path();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- AttributeConstContext ------------------------------------------------------------------

Ili2Parser::AttributeConstContext::AttributeConstContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* Ili2Parser::AttributeConstContext::GREATERGREATER() {
  return getToken(Ili2Parser::GREATERGREATER, 0);
}

tree::TerminalNode* Ili2Parser::AttributeConstContext::NAME() {
  return getToken(Ili2Parser::NAME, 0);
}

tree::TerminalNode* Ili2Parser::AttributeConstContext::DOT() {
  return getToken(Ili2Parser::DOT, 0);
}

Ili2Parser::PathContext* Ili2Parser::AttributeConstContext::path() {
  return getRuleContext<Ili2Parser::PathContext>(0);
}


size_t Ili2Parser::AttributeConstContext::getRuleIndex() const {
  return Ili2Parser::RuleAttributeConst;
}

antlrcpp::Any Ili2Parser::AttributeConstContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<Ili2ParserVisitor*>(visitor))
    return parserVisitor->visitAttributeConst(this);
  else
    return visitor->visitChildren(this);
}

Ili2Parser::AttributeConstContext* Ili2Parser::attributeConst() {
  AttributeConstContext *_localctx = _tracker.createInstance<AttributeConstContext>(_ctx, getState());
  enterRule(_localctx, 102, Ili2Parser::RuleAttributeConst);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(993);
    match(Ili2Parser::GREATERGREATER);
    setState(997);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 125, _ctx)) {
    case 1: {
      setState(994);
      dynamic_cast<AttributeConstContext *>(_localctx)->classref = path();
      setState(995);
      match(Ili2Parser::DOT);
      break;
    }

    }
    setState(999);
    dynamic_cast<AttributeConstContext *>(_localctx)->attribute = match(Ili2Parser::NAME);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- LineTypeContext ------------------------------------------------------------------

Ili2Parser::LineTypeContext::LineTypeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* Ili2Parser::LineTypeContext::POLYLINE() {
  return getToken(Ili2Parser::POLYLINE, 0);
}

tree::TerminalNode* Ili2Parser::LineTypeContext::SURFACE() {
  return getToken(Ili2Parser::SURFACE, 0);
}

tree::TerminalNode* Ili2Parser::LineTypeContext::AREA() {
  return getToken(Ili2Parser::AREA, 0);
}

Ili2Parser::LineFormContext* Ili2Parser::LineTypeContext::lineForm() {
  return getRuleContext<Ili2Parser::LineFormContext>(0);
}

tree::TerminalNode* Ili2Parser::LineTypeContext::VERTEX() {
  return getToken(Ili2Parser::VERTEX, 0);
}

tree::TerminalNode* Ili2Parser::LineTypeContext::WITHOUT() {
  return getToken(Ili2Parser::WITHOUT, 0);
}

tree::TerminalNode* Ili2Parser::LineTypeContext::OVERLAPS() {
  return getToken(Ili2Parser::OVERLAPS, 0);
}

tree::TerminalNode* Ili2Parser::LineTypeContext::LINE() {
  return getToken(Ili2Parser::LINE, 0);
}

tree::TerminalNode* Ili2Parser::LineTypeContext::ATTRIBUTES() {
  return getToken(Ili2Parser::ATTRIBUTES, 0);
}

std::vector<Ili2Parser::PathContext *> Ili2Parser::LineTypeContext::path() {
  return getRuleContexts<Ili2Parser::PathContext>();
}

Ili2Parser::PathContext* Ili2Parser::LineTypeContext::path(size_t i) {
  return getRuleContext<Ili2Parser::PathContext>(i);
}

std::vector<tree::TerminalNode *> Ili2Parser::LineTypeContext::DIRECTED() {
  return getTokens(Ili2Parser::DIRECTED);
}

tree::TerminalNode* Ili2Parser::LineTypeContext::DIRECTED(size_t i) {
  return getToken(Ili2Parser::DIRECTED, i);
}

tree::TerminalNode* Ili2Parser::LineTypeContext::MULTIPOLYLINE() {
  return getToken(Ili2Parser::MULTIPOLYLINE, 0);
}

tree::TerminalNode* Ili2Parser::LineTypeContext::MULTISURFACE() {
  return getToken(Ili2Parser::MULTISURFACE, 0);
}

tree::TerminalNode* Ili2Parser::LineTypeContext::MULTIAREA() {
  return getToken(Ili2Parser::MULTIAREA, 0);
}

tree::TerminalNode* Ili2Parser::LineTypeContext::GREATER() {
  return getToken(Ili2Parser::GREATER, 0);
}

Ili2Parser::DecimalContext* Ili2Parser::LineTypeContext::decimal() {
  return getRuleContext<Ili2Parser::DecimalContext>(0);
}


size_t Ili2Parser::LineTypeContext::getRuleIndex() const {
  return Ili2Parser::RuleLineType;
}

antlrcpp::Any Ili2Parser::LineTypeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<Ili2ParserVisitor*>(visitor))
    return parserVisitor->visitLineType(this);
  else
    return visitor->visitChildren(this);
}

Ili2Parser::LineTypeContext* Ili2Parser::lineType() {
  LineTypeContext *_localctx = _tracker.createInstance<LineTypeContext>(_ctx, getState());
  enterRule(_localctx, 104, Ili2Parser::RuleLineType);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1007);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case Ili2Parser::DIRECTED:
      case Ili2Parser::POLYLINE: {
        setState(1002);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == Ili2Parser::DIRECTED) {
          setState(1001);
          match(Ili2Parser::DIRECTED);
        }
        setState(1004);
        match(Ili2Parser::POLYLINE);
        break;
      }

      case Ili2Parser::SURFACE: {
        setState(1005);
        match(Ili2Parser::SURFACE);
        break;
      }

      case Ili2Parser::AREA: {
        setState(1006);
        match(Ili2Parser::AREA);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    setState(1018);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 130, _ctx)) {
    case 1: {
      setState(1009);

      if (!(ili24)) throw FailedPredicateException(this, "ili24");
      setState(1016);
      _errHandler->sync(this);
      switch (_input->LA(1)) {
        case Ili2Parser::MULTIPOLYLINE:
        case Ili2Parser::DIRECTED: {
          setState(1011);
          _errHandler->sync(this);

          _la = _input->LA(1);
          if (_la == Ili2Parser::DIRECTED) {
            setState(1010);
            match(Ili2Parser::DIRECTED);
          }
          setState(1013);
          match(Ili2Parser::MULTIPOLYLINE);
          break;
        }

        case Ili2Parser::MULTISURFACE: {
          setState(1014);
          match(Ili2Parser::MULTISURFACE);
          break;
        }

        case Ili2Parser::MULTIAREA: {
          setState(1015);
          match(Ili2Parser::MULTIAREA);
          break;
        }

      default:
        throw NoViableAltException(this);
      }
      break;
    }

    }
    setState(1021);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 131, _ctx)) {
    case 1: {
      setState(1020);
      lineForm();
      break;
    }

    }
    setState(1025);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 132, _ctx)) {
    case 1: {
      setState(1023);
      match(Ili2Parser::VERTEX);
      setState(1024);
      dynamic_cast<LineTypeContext *>(_localctx)->coordref = path();
      break;
    }

    }
    setState(1033);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 134, _ctx)) {
    case 1: {
      setState(1027);
      match(Ili2Parser::WITHOUT);
      setState(1028);
      match(Ili2Parser::OVERLAPS);
      setState(1031);
      _errHandler->sync(this);

      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 133, _ctx)) {
      case 1: {
        setState(1029);
        match(Ili2Parser::GREATER);
        setState(1030);
        dynamic_cast<LineTypeContext *>(_localctx)->overlap = decimal();
        break;
      }

      }
      break;
    }

    }
    setState(1038);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 135, _ctx)) {
    case 1: {
      setState(1035);
      match(Ili2Parser::LINE);
      setState(1036);
      match(Ili2Parser::ATTRIBUTES);
      setState(1037);
      dynamic_cast<LineTypeContext *>(_localctx)->lineattrstruct = path();
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- LineFormContext ------------------------------------------------------------------

Ili2Parser::LineFormContext::LineFormContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* Ili2Parser::LineFormContext::WITH() {
  return getToken(Ili2Parser::WITH, 0);
}

tree::TerminalNode* Ili2Parser::LineFormContext::LPAREN() {
  return getToken(Ili2Parser::LPAREN, 0);
}

std::vector<Ili2Parser::LineFormTypeContext *> Ili2Parser::LineFormContext::lineFormType() {
  return getRuleContexts<Ili2Parser::LineFormTypeContext>();
}

Ili2Parser::LineFormTypeContext* Ili2Parser::LineFormContext::lineFormType(size_t i) {
  return getRuleContext<Ili2Parser::LineFormTypeContext>(i);
}

tree::TerminalNode* Ili2Parser::LineFormContext::RPAREN() {
  return getToken(Ili2Parser::RPAREN, 0);
}

std::vector<tree::TerminalNode *> Ili2Parser::LineFormContext::COMMA() {
  return getTokens(Ili2Parser::COMMA);
}

tree::TerminalNode* Ili2Parser::LineFormContext::COMMA(size_t i) {
  return getToken(Ili2Parser::COMMA, i);
}


size_t Ili2Parser::LineFormContext::getRuleIndex() const {
  return Ili2Parser::RuleLineForm;
}

antlrcpp::Any Ili2Parser::LineFormContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<Ili2ParserVisitor*>(visitor))
    return parserVisitor->visitLineForm(this);
  else
    return visitor->visitChildren(this);
}

Ili2Parser::LineFormContext* Ili2Parser::lineForm() {
  LineFormContext *_localctx = _tracker.createInstance<LineFormContext>(_ctx, getState());
  enterRule(_localctx, 106, Ili2Parser::RuleLineForm);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1040);
    match(Ili2Parser::WITH);
    setState(1041);
    match(Ili2Parser::LPAREN);
    setState(1042);
    lineFormType();
    setState(1047);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == Ili2Parser::COMMA) {
      setState(1043);
      match(Ili2Parser::COMMA);
      setState(1044);
      lineFormType();
      setState(1049);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(1050);
    match(Ili2Parser::RPAREN);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- LineFormTypeContext ------------------------------------------------------------------

Ili2Parser::LineFormTypeContext::LineFormTypeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* Ili2Parser::LineFormTypeContext::STRAIGHTS() {
  return getToken(Ili2Parser::STRAIGHTS, 0);
}

tree::TerminalNode* Ili2Parser::LineFormTypeContext::ARCS() {
  return getToken(Ili2Parser::ARCS, 0);
}

Ili2Parser::PathContext* Ili2Parser::LineFormTypeContext::path() {
  return getRuleContext<Ili2Parser::PathContext>(0);
}


size_t Ili2Parser::LineFormTypeContext::getRuleIndex() const {
  return Ili2Parser::RuleLineFormType;
}

antlrcpp::Any Ili2Parser::LineFormTypeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<Ili2ParserVisitor*>(visitor))
    return parserVisitor->visitLineFormType(this);
  else
    return visitor->visitChildren(this);
}

Ili2Parser::LineFormTypeContext* Ili2Parser::lineFormType() {
  LineFormTypeContext *_localctx = _tracker.createInstance<LineFormTypeContext>(_ctx, getState());
  enterRule(_localctx, 108, Ili2Parser::RuleLineFormType);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(1055);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case Ili2Parser::STRAIGHTS: {
        enterOuterAlt(_localctx, 1);
        setState(1052);
        match(Ili2Parser::STRAIGHTS);
        break;
      }

      case Ili2Parser::ARCS: {
        enterOuterAlt(_localctx, 2);
        setState(1053);
        match(Ili2Parser::ARCS);
        break;
      }

      case Ili2Parser::INTERLIS:
      case Ili2Parser::NAME: {
        enterOuterAlt(_localctx, 3);
        setState(1054);
        path();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- LineFormTypeDefContext ------------------------------------------------------------------

Ili2Parser::LineFormTypeDefContext::LineFormTypeDefContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* Ili2Parser::LineFormTypeDefContext::LINE() {
  return getToken(Ili2Parser::LINE, 0);
}

tree::TerminalNode* Ili2Parser::LineFormTypeDefContext::FORM() {
  return getToken(Ili2Parser::FORM, 0);
}

std::vector<Ili2Parser::LineFormTypeDeclContext *> Ili2Parser::LineFormTypeDefContext::lineFormTypeDecl() {
  return getRuleContexts<Ili2Parser::LineFormTypeDeclContext>();
}

Ili2Parser::LineFormTypeDeclContext* Ili2Parser::LineFormTypeDefContext::lineFormTypeDecl(size_t i) {
  return getRuleContext<Ili2Parser::LineFormTypeDeclContext>(i);
}


size_t Ili2Parser::LineFormTypeDefContext::getRuleIndex() const {
  return Ili2Parser::RuleLineFormTypeDef;
}

antlrcpp::Any Ili2Parser::LineFormTypeDefContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<Ili2ParserVisitor*>(visitor))
    return parserVisitor->visitLineFormTypeDef(this);
  else
    return visitor->visitChildren(this);
}

Ili2Parser::LineFormTypeDefContext* Ili2Parser::lineFormTypeDef() {
  LineFormTypeDefContext *_localctx = _tracker.createInstance<LineFormTypeDefContext>(_ctx, getState());
  enterRule(_localctx, 110, Ili2Parser::RuleLineFormTypeDef);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(1057);
    match(Ili2Parser::LINE);
    setState(1058);
    match(Ili2Parser::FORM);
    setState(1062);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 138, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(1059);
        lineFormTypeDecl(); 
      }
      setState(1064);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 138, _ctx);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- LineFormTypeDeclContext ------------------------------------------------------------------

Ili2Parser::LineFormTypeDeclContext::LineFormTypeDeclContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* Ili2Parser::LineFormTypeDeclContext::SEMI() {
  return getToken(Ili2Parser::SEMI, 0);
}

std::vector<tree::TerminalNode *> Ili2Parser::LineFormTypeDeclContext::NAME() {
  return getTokens(Ili2Parser::NAME);
}

tree::TerminalNode* Ili2Parser::LineFormTypeDeclContext::NAME(size_t i) {
  return getToken(Ili2Parser::NAME, i);
}

tree::TerminalNode* Ili2Parser::LineFormTypeDeclContext::COLON() {
  return getToken(Ili2Parser::COLON, 0);
}


size_t Ili2Parser::LineFormTypeDeclContext::getRuleIndex() const {
  return Ili2Parser::RuleLineFormTypeDecl;
}

antlrcpp::Any Ili2Parser::LineFormTypeDeclContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<Ili2ParserVisitor*>(visitor))
    return parserVisitor->visitLineFormTypeDecl(this);
  else
    return visitor->visitChildren(this);
}

Ili2Parser::LineFormTypeDeclContext* Ili2Parser::lineFormTypeDecl() {
  LineFormTypeDeclContext *_localctx = _tracker.createInstance<LineFormTypeDeclContext>(_ctx, getState());
  enterRule(_localctx, 112, Ili2Parser::RuleLineFormTypeDecl);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1065);
    dynamic_cast<LineFormTypeDeclContext *>(_localctx)->lineformtype = match(Ili2Parser::NAME);
    setState(1068);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == Ili2Parser::COLON) {
      setState(1066);
      match(Ili2Parser::COLON);
      setState(1067);
      dynamic_cast<LineFormTypeDeclContext *>(_localctx)->linestructurename = match(Ili2Parser::NAME);
    }
    setState(1070);
    match(Ili2Parser::SEMI);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- UnitDeclContext ------------------------------------------------------------------

Ili2Parser::UnitDeclContext::UnitDeclContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* Ili2Parser::UnitDeclContext::UNIT() {
  return getToken(Ili2Parser::UNIT, 0);
}

std::vector<Ili2Parser::UnitDefContext *> Ili2Parser::UnitDeclContext::unitDef() {
  return getRuleContexts<Ili2Parser::UnitDefContext>();
}

Ili2Parser::UnitDefContext* Ili2Parser::UnitDeclContext::unitDef(size_t i) {
  return getRuleContext<Ili2Parser::UnitDefContext>(i);
}


size_t Ili2Parser::UnitDeclContext::getRuleIndex() const {
  return Ili2Parser::RuleUnitDecl;
}

antlrcpp::Any Ili2Parser::UnitDeclContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<Ili2ParserVisitor*>(visitor))
    return parserVisitor->visitUnitDecl(this);
  else
    return visitor->visitChildren(this);
}

Ili2Parser::UnitDeclContext* Ili2Parser::unitDecl() {
  UnitDeclContext *_localctx = _tracker.createInstance<UnitDeclContext>(_ctx, getState());
  enterRule(_localctx, 114, Ili2Parser::RuleUnitDecl);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(1072);
    match(Ili2Parser::UNIT);
    setState(1076);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 140, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(1073);
        unitDef(); 
      }
      setState(1078);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 140, _ctx);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- UnitDefContext ------------------------------------------------------------------

Ili2Parser::UnitDefContext::UnitDefContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* Ili2Parser::UnitDefContext::SEMI() {
  return getToken(Ili2Parser::SEMI, 0);
}

tree::TerminalNode* Ili2Parser::UnitDefContext::NAME() {
  return getToken(Ili2Parser::NAME, 0);
}

tree::TerminalNode* Ili2Parser::UnitDefContext::LPAREN() {
  return getToken(Ili2Parser::LPAREN, 0);
}

tree::TerminalNode* Ili2Parser::UnitDefContext::ABSTRACT() {
  return getToken(Ili2Parser::ABSTRACT, 0);
}

tree::TerminalNode* Ili2Parser::UnitDefContext::RPAREN() {
  return getToken(Ili2Parser::RPAREN, 0);
}

tree::TerminalNode* Ili2Parser::UnitDefContext::LBRACE() {
  return getToken(Ili2Parser::LBRACE, 0);
}

tree::TerminalNode* Ili2Parser::UnitDefContext::RBRACE() {
  return getToken(Ili2Parser::RBRACE, 0);
}

tree::TerminalNode* Ili2Parser::UnitDefContext::EXTENDS() {
  return getToken(Ili2Parser::EXTENDS, 0);
}

tree::TerminalNode* Ili2Parser::UnitDefContext::EQUAL() {
  return getToken(Ili2Parser::EQUAL, 0);
}

std::vector<Ili2Parser::PathContext *> Ili2Parser::UnitDefContext::path() {
  return getRuleContexts<Ili2Parser::PathContext>();
}

Ili2Parser::PathContext* Ili2Parser::UnitDefContext::path(size_t i) {
  return getRuleContext<Ili2Parser::PathContext>(i);
}

Ili2Parser::DerivedUnitContext* Ili2Parser::UnitDefContext::derivedUnit() {
  return getRuleContext<Ili2Parser::DerivedUnitContext>(0);
}

Ili2Parser::ComposedUnitContext* Ili2Parser::UnitDefContext::composedUnit() {
  return getRuleContext<Ili2Parser::ComposedUnitContext>(0);
}


size_t Ili2Parser::UnitDefContext::getRuleIndex() const {
  return Ili2Parser::RuleUnitDef;
}

antlrcpp::Any Ili2Parser::UnitDefContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<Ili2ParserVisitor*>(visitor))
    return parserVisitor->visitUnitDef(this);
  else
    return visitor->visitChildren(this);
}

Ili2Parser::UnitDefContext* Ili2Parser::unitDef() {
  UnitDefContext *_localctx = _tracker.createInstance<UnitDefContext>(_ctx, getState());
  enterRule(_localctx, 116, Ili2Parser::RuleUnitDef);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1079);
    dynamic_cast<UnitDefContext *>(_localctx)->unitname = match(Ili2Parser::NAME);
    setState(1087);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case Ili2Parser::LPAREN: {
        setState(1080);
        match(Ili2Parser::LPAREN);
        setState(1081);
        match(Ili2Parser::ABSTRACT);
        setState(1082);
        match(Ili2Parser::RPAREN);
        break;
      }

      case Ili2Parser::LBRACE: {
        setState(1083);
        match(Ili2Parser::LBRACE);
        setState(1084);
        dynamic_cast<UnitDefContext *>(_localctx)->unitshort = path();
        setState(1085);
        match(Ili2Parser::RBRACE);
        break;
      }

      case Ili2Parser::EXTENDS:
      case Ili2Parser::SEMI:
      case Ili2Parser::EQUAL: {
        break;
      }

    default:
      break;
    }
    setState(1091);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == Ili2Parser::EXTENDS) {
      setState(1089);
      match(Ili2Parser::EXTENDS);
      setState(1090);
      dynamic_cast<UnitDefContext *>(_localctx)->super = path();
    }
    setState(1098);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == Ili2Parser::EQUAL) {
      setState(1093);
      match(Ili2Parser::EQUAL);
      setState(1096);
      _errHandler->sync(this);
      switch (_input->LA(1)) {
        case Ili2Parser::LBRACE:
        case Ili2Parser::PI:
        case Ili2Parser::LNBASE:
        case Ili2Parser::FUNCTION:
        case Ili2Parser::POSNUMBER:
        case Ili2Parser::NUMBER:
        case Ili2Parser::DEC: {
          setState(1094);
          derivedUnit();
          break;
        }

        case Ili2Parser::LPAREN: {
          setState(1095);
          composedUnit();
          break;
        }

      default:
        throw NoViableAltException(this);
      }
    }
    setState(1100);
    match(Ili2Parser::SEMI);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- DerivedUnitContext ------------------------------------------------------------------

Ili2Parser::DerivedUnitContext::DerivedUnitContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* Ili2Parser::DerivedUnitContext::LBRACE() {
  return getToken(Ili2Parser::LBRACE, 0);
}

tree::TerminalNode* Ili2Parser::DerivedUnitContext::RBRACE() {
  return getToken(Ili2Parser::RBRACE, 0);
}

Ili2Parser::PathContext* Ili2Parser::DerivedUnitContext::path() {
  return getRuleContext<Ili2Parser::PathContext>(0);
}

std::vector<Ili2Parser::DecConstContext *> Ili2Parser::DerivedUnitContext::decConst() {
  return getRuleContexts<Ili2Parser::DecConstContext>();
}

Ili2Parser::DecConstContext* Ili2Parser::DerivedUnitContext::decConst(size_t i) {
  return getRuleContext<Ili2Parser::DecConstContext>(i);
}

tree::TerminalNode* Ili2Parser::DerivedUnitContext::FUNCTION() {
  return getToken(Ili2Parser::FUNCTION, 0);
}

tree::TerminalNode* Ili2Parser::DerivedUnitContext::EXPLANATION() {
  return getToken(Ili2Parser::EXPLANATION, 0);
}

std::vector<tree::TerminalNode *> Ili2Parser::DerivedUnitContext::STAR() {
  return getTokens(Ili2Parser::STAR);
}

tree::TerminalNode* Ili2Parser::DerivedUnitContext::STAR(size_t i) {
  return getToken(Ili2Parser::STAR, i);
}

std::vector<tree::TerminalNode *> Ili2Parser::DerivedUnitContext::SLASH() {
  return getTokens(Ili2Parser::SLASH);
}

tree::TerminalNode* Ili2Parser::DerivedUnitContext::SLASH(size_t i) {
  return getToken(Ili2Parser::SLASH, i);
}


size_t Ili2Parser::DerivedUnitContext::getRuleIndex() const {
  return Ili2Parser::RuleDerivedUnit;
}

antlrcpp::Any Ili2Parser::DerivedUnitContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<Ili2ParserVisitor*>(visitor))
    return parserVisitor->visitDerivedUnit(this);
  else
    return visitor->visitChildren(this);
}

Ili2Parser::DerivedUnitContext* Ili2Parser::derivedUnit() {
  DerivedUnitContext *_localctx = _tracker.createInstance<DerivedUnitContext>(_ctx, getState());
  enterRule(_localctx, 118, Ili2Parser::RuleDerivedUnit);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1112);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case Ili2Parser::PI:
      case Ili2Parser::LNBASE:
      case Ili2Parser::POSNUMBER:
      case Ili2Parser::NUMBER:
      case Ili2Parser::DEC: {
        setState(1102);
        decConst();
        setState(1107);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while (_la == Ili2Parser::STAR

        || _la == Ili2Parser::SLASH) {
          setState(1103);
          dynamic_cast<DerivedUnitContext *>(_localctx)->op = _input->LT(1);
          _la = _input->LA(1);
          if (!(_la == Ili2Parser::STAR

          || _la == Ili2Parser::SLASH)) {
            dynamic_cast<DerivedUnitContext *>(_localctx)->op = _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(1104);
          decConst();
          setState(1109);
          _errHandler->sync(this);
          _la = _input->LA(1);
        }
        break;
      }

      case Ili2Parser::FUNCTION: {
        setState(1110);
        match(Ili2Parser::FUNCTION);
        setState(1111);
        match(Ili2Parser::EXPLANATION);
        break;
      }

      case Ili2Parser::LBRACE: {
        break;
      }

    default:
      break;
    }
    setState(1114);
    match(Ili2Parser::LBRACE);
    setState(1115);
    dynamic_cast<DerivedUnitContext *>(_localctx)->unitref = path();
    setState(1116);
    match(Ili2Parser::RBRACE);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ComposedUnitContext ------------------------------------------------------------------

Ili2Parser::ComposedUnitContext::ComposedUnitContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* Ili2Parser::ComposedUnitContext::LPAREN() {
  return getToken(Ili2Parser::LPAREN, 0);
}

tree::TerminalNode* Ili2Parser::ComposedUnitContext::RPAREN() {
  return getToken(Ili2Parser::RPAREN, 0);
}

Ili2Parser::ExpressionContext* Ili2Parser::ComposedUnitContext::expression() {
  return getRuleContext<Ili2Parser::ExpressionContext>(0);
}


size_t Ili2Parser::ComposedUnitContext::getRuleIndex() const {
  return Ili2Parser::RuleComposedUnit;
}

antlrcpp::Any Ili2Parser::ComposedUnitContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<Ili2ParserVisitor*>(visitor))
    return parserVisitor->visitComposedUnit(this);
  else
    return visitor->visitChildren(this);
}

Ili2Parser::ComposedUnitContext* Ili2Parser::composedUnit() {
  ComposedUnitContext *_localctx = _tracker.createInstance<ComposedUnitContext>(_ctx, getState());
  enterRule(_localctx, 120, Ili2Parser::RuleComposedUnit);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1118);
    match(Ili2Parser::LPAREN);
    setState(1119);
    dynamic_cast<ComposedUnitContext *>(_localctx)->unitref = expression();
    setState(1120);
    match(Ili2Parser::RPAREN);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- MetaDataBasketDefContext ------------------------------------------------------------------

Ili2Parser::MetaDataBasketDefContext::MetaDataBasketDefContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* Ili2Parser::MetaDataBasketDefContext::BASKET() {
  return getToken(Ili2Parser::BASKET, 0);
}

tree::TerminalNode* Ili2Parser::MetaDataBasketDefContext::TILDE() {
  return getToken(Ili2Parser::TILDE, 0);
}

Ili2Parser::PathContext* Ili2Parser::MetaDataBasketDefContext::path() {
  return getRuleContext<Ili2Parser::PathContext>(0);
}

tree::TerminalNode* Ili2Parser::MetaDataBasketDefContext::SEMI() {
  return getToken(Ili2Parser::SEMI, 0);
}

tree::TerminalNode* Ili2Parser::MetaDataBasketDefContext::SIGN() {
  return getToken(Ili2Parser::SIGN, 0);
}

tree::TerminalNode* Ili2Parser::MetaDataBasketDefContext::REFSYSTEM() {
  return getToken(Ili2Parser::REFSYSTEM, 0);
}

std::vector<tree::TerminalNode *> Ili2Parser::MetaDataBasketDefContext::NAME() {
  return getTokens(Ili2Parser::NAME);
}

tree::TerminalNode* Ili2Parser::MetaDataBasketDefContext::NAME(size_t i) {
  return getToken(Ili2Parser::NAME, i);
}

tree::TerminalNode* Ili2Parser::MetaDataBasketDefContext::LPAREN() {
  return getToken(Ili2Parser::LPAREN, 0);
}

tree::TerminalNode* Ili2Parser::MetaDataBasketDefContext::FINAL() {
  return getToken(Ili2Parser::FINAL, 0);
}

tree::TerminalNode* Ili2Parser::MetaDataBasketDefContext::RPAREN() {
  return getToken(Ili2Parser::RPAREN, 0);
}

tree::TerminalNode* Ili2Parser::MetaDataBasketDefContext::EXTENDS() {
  return getToken(Ili2Parser::EXTENDS, 0);
}

Ili2Parser::MetaDataBasketRefContext* Ili2Parser::MetaDataBasketDefContext::metaDataBasketRef() {
  return getRuleContext<Ili2Parser::MetaDataBasketRefContext>(0);
}

std::vector<tree::TerminalNode *> Ili2Parser::MetaDataBasketDefContext::OBJECTS() {
  return getTokens(Ili2Parser::OBJECTS);
}

tree::TerminalNode* Ili2Parser::MetaDataBasketDefContext::OBJECTS(size_t i) {
  return getToken(Ili2Parser::OBJECTS, i);
}

std::vector<tree::TerminalNode *> Ili2Parser::MetaDataBasketDefContext::OF() {
  return getTokens(Ili2Parser::OF);
}

tree::TerminalNode* Ili2Parser::MetaDataBasketDefContext::OF(size_t i) {
  return getToken(Ili2Parser::OF, i);
}

std::vector<tree::TerminalNode *> Ili2Parser::MetaDataBasketDefContext::COLON() {
  return getTokens(Ili2Parser::COLON);
}

tree::TerminalNode* Ili2Parser::MetaDataBasketDefContext::COLON(size_t i) {
  return getToken(Ili2Parser::COLON, i);
}

std::vector<tree::TerminalNode *> Ili2Parser::MetaDataBasketDefContext::COMMA() {
  return getTokens(Ili2Parser::COMMA);
}

tree::TerminalNode* Ili2Parser::MetaDataBasketDefContext::COMMA(size_t i) {
  return getToken(Ili2Parser::COMMA, i);
}


size_t Ili2Parser::MetaDataBasketDefContext::getRuleIndex() const {
  return Ili2Parser::RuleMetaDataBasketDef;
}

antlrcpp::Any Ili2Parser::MetaDataBasketDefContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<Ili2ParserVisitor*>(visitor))
    return parserVisitor->visitMetaDataBasketDef(this);
  else
    return visitor->visitChildren(this);
}

Ili2Parser::MetaDataBasketDefContext* Ili2Parser::metaDataBasketDef() {
  MetaDataBasketDefContext *_localctx = _tracker.createInstance<MetaDataBasketDefContext>(_ctx, getState());
  enterRule(_localctx, 122, Ili2Parser::RuleMetaDataBasketDef);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1122);
    _la = _input->LA(1);
    if (!(_la == Ili2Parser::REFSYSTEM || _la == Ili2Parser::SIGN)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
    setState(1123);
    match(Ili2Parser::BASKET);
    setState(1124);
    dynamic_cast<MetaDataBasketDefContext *>(_localctx)->basketname = match(Ili2Parser::NAME);
    setState(1128);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == Ili2Parser::LPAREN) {
      setState(1125);
      match(Ili2Parser::LPAREN);
      setState(1126);
      match(Ili2Parser::FINAL);
      setState(1127);
      match(Ili2Parser::RPAREN);
    }
    setState(1132);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == Ili2Parser::EXTENDS) {
      setState(1130);
      match(Ili2Parser::EXTENDS);
      setState(1131);
      metaDataBasketRef();
    }
    setState(1134);
    match(Ili2Parser::TILDE);
    setState(1135);
    path();
    setState(1150);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == Ili2Parser::OBJECTS) {
      setState(1136);
      match(Ili2Parser::OBJECTS);
      setState(1137);
      match(Ili2Parser::OF);
      setState(1138);
      dynamic_cast<MetaDataBasketDefContext *>(_localctx)->classname = match(Ili2Parser::NAME);
      setState(1139);
      match(Ili2Parser::COLON);
      setState(1140);
      dynamic_cast<MetaDataBasketDefContext *>(_localctx)->metabjectname = match(Ili2Parser::NAME);
      setState(1145);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == Ili2Parser::COMMA) {
        setState(1141);
        match(Ili2Parser::COMMA);
        setState(1142);
        dynamic_cast<MetaDataBasketDefContext *>(_localctx)->metaobjectname = match(Ili2Parser::NAME);
        setState(1147);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(1152);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(1153);
    match(Ili2Parser::SEMI);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- MetaDataBasketRefContext ------------------------------------------------------------------

Ili2Parser::MetaDataBasketRefContext::MetaDataBasketRefContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<tree::TerminalNode *> Ili2Parser::MetaDataBasketRefContext::NAME() {
  return getTokens(Ili2Parser::NAME);
}

tree::TerminalNode* Ili2Parser::MetaDataBasketRefContext::NAME(size_t i) {
  return getToken(Ili2Parser::NAME, i);
}

std::vector<tree::TerminalNode *> Ili2Parser::MetaDataBasketRefContext::DOT() {
  return getTokens(Ili2Parser::DOT);
}

tree::TerminalNode* Ili2Parser::MetaDataBasketRefContext::DOT(size_t i) {
  return getToken(Ili2Parser::DOT, i);
}


size_t Ili2Parser::MetaDataBasketRefContext::getRuleIndex() const {
  return Ili2Parser::RuleMetaDataBasketRef;
}

antlrcpp::Any Ili2Parser::MetaDataBasketRefContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<Ili2ParserVisitor*>(visitor))
    return parserVisitor->visitMetaDataBasketRef(this);
  else
    return visitor->visitChildren(this);
}

Ili2Parser::MetaDataBasketRefContext* Ili2Parser::metaDataBasketRef() {
  MetaDataBasketRefContext *_localctx = _tracker.createInstance<MetaDataBasketRefContext>(_ctx, getState());
  enterRule(_localctx, 124, Ili2Parser::RuleMetaDataBasketRef);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1161);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 152, _ctx)) {
    case 1: {
      setState(1157);
      _errHandler->sync(this);

      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 151, _ctx)) {
      case 1: {
        setState(1155);
        dynamic_cast<MetaDataBasketRefContext *>(_localctx)->modelname = match(Ili2Parser::NAME);
        setState(1156);
        match(Ili2Parser::DOT);
        break;
      }

      }
      setState(1159);
      dynamic_cast<MetaDataBasketRefContext *>(_localctx)->topicname = match(Ili2Parser::NAME);
      setState(1160);
      match(Ili2Parser::DOT);
      break;
    }

    }
    setState(1163);
    dynamic_cast<MetaDataBasketRefContext *>(_localctx)->basketname = match(Ili2Parser::NAME);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- MetaObjectRefContext ------------------------------------------------------------------

Ili2Parser::MetaObjectRefContext::MetaObjectRefContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* Ili2Parser::MetaObjectRefContext::NAME() {
  return getToken(Ili2Parser::NAME, 0);
}

Ili2Parser::MetaDataBasketRefContext* Ili2Parser::MetaObjectRefContext::metaDataBasketRef() {
  return getRuleContext<Ili2Parser::MetaDataBasketRefContext>(0);
}

tree::TerminalNode* Ili2Parser::MetaObjectRefContext::DOT() {
  return getToken(Ili2Parser::DOT, 0);
}


size_t Ili2Parser::MetaObjectRefContext::getRuleIndex() const {
  return Ili2Parser::RuleMetaObjectRef;
}

antlrcpp::Any Ili2Parser::MetaObjectRefContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<Ili2ParserVisitor*>(visitor))
    return parserVisitor->visitMetaObjectRef(this);
  else
    return visitor->visitChildren(this);
}

Ili2Parser::MetaObjectRefContext* Ili2Parser::metaObjectRef() {
  MetaObjectRefContext *_localctx = _tracker.createInstance<MetaObjectRefContext>(_ctx, getState());
  enterRule(_localctx, 126, Ili2Parser::RuleMetaObjectRef);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1168);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 153, _ctx)) {
    case 1: {
      setState(1165);
      metaDataBasketRef();
      setState(1166);
      match(Ili2Parser::DOT);
      break;
    }

    }
    setState(1170);
    dynamic_cast<MetaObjectRefContext *>(_localctx)->metaobjectname = match(Ili2Parser::NAME);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ParameterDefContext ------------------------------------------------------------------

Ili2Parser::ParameterDefContext::ParameterDefContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* Ili2Parser::ParameterDefContext::COLON() {
  return getToken(Ili2Parser::COLON, 0);
}

tree::TerminalNode* Ili2Parser::ParameterDefContext::SEMI() {
  return getToken(Ili2Parser::SEMI, 0);
}

tree::TerminalNode* Ili2Parser::ParameterDefContext::NAME() {
  return getToken(Ili2Parser::NAME, 0);
}

Ili2Parser::AttrTypeDefContext* Ili2Parser::ParameterDefContext::attrTypeDef() {
  return getRuleContext<Ili2Parser::AttrTypeDefContext>(0);
}

tree::TerminalNode* Ili2Parser::ParameterDefContext::METAOBJECT() {
  return getToken(Ili2Parser::METAOBJECT, 0);
}

Ili2Parser::PropertiesContext* Ili2Parser::ParameterDefContext::properties() {
  return getRuleContext<Ili2Parser::PropertiesContext>(0);
}

tree::TerminalNode* Ili2Parser::ParameterDefContext::OF() {
  return getToken(Ili2Parser::OF, 0);
}

Ili2Parser::PathContext* Ili2Parser::ParameterDefContext::path() {
  return getRuleContext<Ili2Parser::PathContext>(0);
}


size_t Ili2Parser::ParameterDefContext::getRuleIndex() const {
  return Ili2Parser::RuleParameterDef;
}

antlrcpp::Any Ili2Parser::ParameterDefContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<Ili2ParserVisitor*>(visitor))
    return parserVisitor->visitParameterDef(this);
  else
    return visitor->visitChildren(this);
}

Ili2Parser::ParameterDefContext* Ili2Parser::parameterDef() {
  ParameterDefContext *_localctx = _tracker.createInstance<ParameterDefContext>(_ctx, getState());
  enterRule(_localctx, 128, Ili2Parser::RuleParameterDef);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1172);
    dynamic_cast<ParameterDefContext *>(_localctx)->parameterName = match(Ili2Parser::NAME);
    setState(1174);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == Ili2Parser::LPAREN) {
      setState(1173);
      properties();
    }
    setState(1176);
    match(Ili2Parser::COLON);
    setState(1183);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 156, _ctx)) {
    case 1: {
      setState(1177);
      attrTypeDef();
      break;
    }

    case 2: {
      setState(1178);
      match(Ili2Parser::METAOBJECT);
      setState(1181);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == Ili2Parser::OF) {
        setState(1179);
        match(Ili2Parser::OF);
        setState(1180);
        path();
      }
      break;
    }

    }
    setState(1185);
    match(Ili2Parser::SEMI);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- PropertiesContext ------------------------------------------------------------------

Ili2Parser::PropertiesContext::PropertiesContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* Ili2Parser::PropertiesContext::LPAREN() {
  return getToken(Ili2Parser::LPAREN, 0);
}

tree::TerminalNode* Ili2Parser::PropertiesContext::RPAREN() {
  return getToken(Ili2Parser::RPAREN, 0);
}

std::vector<tree::TerminalNode *> Ili2Parser::PropertiesContext::ABSTRACT() {
  return getTokens(Ili2Parser::ABSTRACT);
}

tree::TerminalNode* Ili2Parser::PropertiesContext::ABSTRACT(size_t i) {
  return getToken(Ili2Parser::ABSTRACT, i);
}

std::vector<tree::TerminalNode *> Ili2Parser::PropertiesContext::EXTENDED() {
  return getTokens(Ili2Parser::EXTENDED);
}

tree::TerminalNode* Ili2Parser::PropertiesContext::EXTENDED(size_t i) {
  return getToken(Ili2Parser::EXTENDED, i);
}

std::vector<tree::TerminalNode *> Ili2Parser::PropertiesContext::FINAL() {
  return getTokens(Ili2Parser::FINAL);
}

tree::TerminalNode* Ili2Parser::PropertiesContext::FINAL(size_t i) {
  return getToken(Ili2Parser::FINAL, i);
}

std::vector<tree::TerminalNode *> Ili2Parser::PropertiesContext::TRANSIENT() {
  return getTokens(Ili2Parser::TRANSIENT);
}

tree::TerminalNode* Ili2Parser::PropertiesContext::TRANSIENT(size_t i) {
  return getToken(Ili2Parser::TRANSIENT, i);
}

std::vector<tree::TerminalNode *> Ili2Parser::PropertiesContext::OID() {
  return getTokens(Ili2Parser::OID);
}

tree::TerminalNode* Ili2Parser::PropertiesContext::OID(size_t i) {
  return getToken(Ili2Parser::OID, i);
}

std::vector<tree::TerminalNode *> Ili2Parser::PropertiesContext::HIDING() {
  return getTokens(Ili2Parser::HIDING);
}

tree::TerminalNode* Ili2Parser::PropertiesContext::HIDING(size_t i) {
  return getToken(Ili2Parser::HIDING, i);
}

std::vector<tree::TerminalNode *> Ili2Parser::PropertiesContext::ORDERED() {
  return getTokens(Ili2Parser::ORDERED);
}

tree::TerminalNode* Ili2Parser::PropertiesContext::ORDERED(size_t i) {
  return getToken(Ili2Parser::ORDERED, i);
}

std::vector<tree::TerminalNode *> Ili2Parser::PropertiesContext::EXTERNAL() {
  return getTokens(Ili2Parser::EXTERNAL);
}

tree::TerminalNode* Ili2Parser::PropertiesContext::EXTERNAL(size_t i) {
  return getToken(Ili2Parser::EXTERNAL, i);
}

std::vector<tree::TerminalNode *> Ili2Parser::PropertiesContext::COMMA() {
  return getTokens(Ili2Parser::COMMA);
}

tree::TerminalNode* Ili2Parser::PropertiesContext::COMMA(size_t i) {
  return getToken(Ili2Parser::COMMA, i);
}


size_t Ili2Parser::PropertiesContext::getRuleIndex() const {
  return Ili2Parser::RuleProperties;
}

antlrcpp::Any Ili2Parser::PropertiesContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<Ili2ParserVisitor*>(visitor))
    return parserVisitor->visitProperties(this);
  else
    return visitor->visitChildren(this);
}

Ili2Parser::PropertiesContext* Ili2Parser::properties() {
  PropertiesContext *_localctx = _tracker.createInstance<PropertiesContext>(_ctx, getState());
  enterRule(_localctx, 130, Ili2Parser::RuleProperties);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1187);
    match(Ili2Parser::LPAREN);
    setState(1188);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << Ili2Parser::OID)
      | (1ULL << Ili2Parser::ABSTRACT)
      | (1ULL << Ili2Parser::EXTENDED)
      | (1ULL << Ili2Parser::FINAL)
      | (1ULL << Ili2Parser::TRANSIENT))) != 0) || ((((_la - 99) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 99)) & ((1ULL << (Ili2Parser::EXTERNAL - 99))
      | (1ULL << (Ili2Parser::HIDING - 99))
      | (1ULL << (Ili2Parser::ORDERED - 99)))) != 0))) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
    setState(1193);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == Ili2Parser::COMMA) {
      setState(1189);
      match(Ili2Parser::COMMA);
      setState(1190);
      _la = _input->LA(1);
      if (!((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & ((1ULL << Ili2Parser::OID)
        | (1ULL << Ili2Parser::ABSTRACT)
        | (1ULL << Ili2Parser::EXTENDED)
        | (1ULL << Ili2Parser::FINAL)
        | (1ULL << Ili2Parser::TRANSIENT))) != 0) || ((((_la - 99) & ~ 0x3fULL) == 0) &&
        ((1ULL << (_la - 99)) & ((1ULL << (Ili2Parser::EXTERNAL - 99))
        | (1ULL << (Ili2Parser::HIDING - 99))
        | (1ULL << (Ili2Parser::ORDERED - 99)))) != 0))) {
      _errHandler->recoverInline(this);
      }
      else {
        _errHandler->reportMatch(this);
        consume();
      }
      setState(1195);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(1196);
    match(Ili2Parser::RPAREN);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- RunTimeParameterDefContext ------------------------------------------------------------------

Ili2Parser::RunTimeParameterDefContext::RunTimeParameterDefContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* Ili2Parser::RunTimeParameterDefContext::PARAMETER() {
  return getToken(Ili2Parser::PARAMETER, 0);
}

std::vector<tree::TerminalNode *> Ili2Parser::RunTimeParameterDefContext::COLON() {
  return getTokens(Ili2Parser::COLON);
}

tree::TerminalNode* Ili2Parser::RunTimeParameterDefContext::COLON(size_t i) {
  return getToken(Ili2Parser::COLON, i);
}

std::vector<Ili2Parser::AttrTypeDefContext *> Ili2Parser::RunTimeParameterDefContext::attrTypeDef() {
  return getRuleContexts<Ili2Parser::AttrTypeDefContext>();
}

Ili2Parser::AttrTypeDefContext* Ili2Parser::RunTimeParameterDefContext::attrTypeDef(size_t i) {
  return getRuleContext<Ili2Parser::AttrTypeDefContext>(i);
}

std::vector<tree::TerminalNode *> Ili2Parser::RunTimeParameterDefContext::SEMI() {
  return getTokens(Ili2Parser::SEMI);
}

tree::TerminalNode* Ili2Parser::RunTimeParameterDefContext::SEMI(size_t i) {
  return getToken(Ili2Parser::SEMI, i);
}

std::vector<tree::TerminalNode *> Ili2Parser::RunTimeParameterDefContext::NAME() {
  return getTokens(Ili2Parser::NAME);
}

tree::TerminalNode* Ili2Parser::RunTimeParameterDefContext::NAME(size_t i) {
  return getToken(Ili2Parser::NAME, i);
}


size_t Ili2Parser::RunTimeParameterDefContext::getRuleIndex() const {
  return Ili2Parser::RuleRunTimeParameterDef;
}

antlrcpp::Any Ili2Parser::RunTimeParameterDefContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<Ili2ParserVisitor*>(visitor))
    return parserVisitor->visitRunTimeParameterDef(this);
  else
    return visitor->visitChildren(this);
}

Ili2Parser::RunTimeParameterDefContext* Ili2Parser::runTimeParameterDef() {
  RunTimeParameterDefContext *_localctx = _tracker.createInstance<RunTimeParameterDefContext>(_ctx, getState());
  enterRule(_localctx, 132, Ili2Parser::RuleRunTimeParameterDef);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(1198);
    match(Ili2Parser::PARAMETER);
    setState(1206);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 158, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(1199);
        dynamic_cast<RunTimeParameterDefContext *>(_localctx)->runtimeparametername = match(Ili2Parser::NAME);
        setState(1200);
        match(Ili2Parser::COLON);
        setState(1201);
        attrTypeDef();
        setState(1202);
        match(Ili2Parser::SEMI); 
      }
      setState(1208);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 158, _ctx);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ConstraintDefContext ------------------------------------------------------------------

Ili2Parser::ConstraintDefContext::ConstraintDefContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

Ili2Parser::MandatoryConstraintContext* Ili2Parser::ConstraintDefContext::mandatoryConstraint() {
  return getRuleContext<Ili2Parser::MandatoryConstraintContext>(0);
}

Ili2Parser::PlausibilityConstraintContext* Ili2Parser::ConstraintDefContext::plausibilityConstraint() {
  return getRuleContext<Ili2Parser::PlausibilityConstraintContext>(0);
}

Ili2Parser::ExistenceConstraintContext* Ili2Parser::ConstraintDefContext::existenceConstraint() {
  return getRuleContext<Ili2Parser::ExistenceConstraintContext>(0);
}

Ili2Parser::UniquenessConstraintContext* Ili2Parser::ConstraintDefContext::uniquenessConstraint() {
  return getRuleContext<Ili2Parser::UniquenessConstraintContext>(0);
}

Ili2Parser::SetConstraintContext* Ili2Parser::ConstraintDefContext::setConstraint() {
  return getRuleContext<Ili2Parser::SetConstraintContext>(0);
}


size_t Ili2Parser::ConstraintDefContext::getRuleIndex() const {
  return Ili2Parser::RuleConstraintDef;
}

antlrcpp::Any Ili2Parser::ConstraintDefContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<Ili2ParserVisitor*>(visitor))
    return parserVisitor->visitConstraintDef(this);
  else
    return visitor->visitChildren(this);
}

Ili2Parser::ConstraintDefContext* Ili2Parser::constraintDef() {
  ConstraintDefContext *_localctx = _tracker.createInstance<ConstraintDefContext>(_ctx, getState());
  enterRule(_localctx, 134, Ili2Parser::RuleConstraintDef);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(1214);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case Ili2Parser::MANDATORY: {
        enterOuterAlt(_localctx, 1);
        setState(1209);
        mandatoryConstraint();
        break;
      }

      case Ili2Parser::CONSTRAINT: {
        enterOuterAlt(_localctx, 2);
        setState(1210);
        plausibilityConstraint();
        break;
      }

      case Ili2Parser::EXISTENCE: {
        enterOuterAlt(_localctx, 3);
        setState(1211);
        existenceConstraint();
        break;
      }

      case Ili2Parser::UNIQUE: {
        enterOuterAlt(_localctx, 4);
        setState(1212);
        uniquenessConstraint();
        break;
      }

      case Ili2Parser::SET: {
        enterOuterAlt(_localctx, 5);
        setState(1213);
        setConstraint();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- MandatoryConstraintContext ------------------------------------------------------------------

Ili2Parser::MandatoryConstraintContext::MandatoryConstraintContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* Ili2Parser::MandatoryConstraintContext::MANDATORY() {
  return getToken(Ili2Parser::MANDATORY, 0);
}

tree::TerminalNode* Ili2Parser::MandatoryConstraintContext::CONSTRAINT() {
  return getToken(Ili2Parser::CONSTRAINT, 0);
}

tree::TerminalNode* Ili2Parser::MandatoryConstraintContext::SEMI() {
  return getToken(Ili2Parser::SEMI, 0);
}

Ili2Parser::ExpressionContext* Ili2Parser::MandatoryConstraintContext::expression() {
  return getRuleContext<Ili2Parser::ExpressionContext>(0);
}


size_t Ili2Parser::MandatoryConstraintContext::getRuleIndex() const {
  return Ili2Parser::RuleMandatoryConstraint;
}

antlrcpp::Any Ili2Parser::MandatoryConstraintContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<Ili2ParserVisitor*>(visitor))
    return parserVisitor->visitMandatoryConstraint(this);
  else
    return visitor->visitChildren(this);
}

Ili2Parser::MandatoryConstraintContext* Ili2Parser::mandatoryConstraint() {
  MandatoryConstraintContext *_localctx = _tracker.createInstance<MandatoryConstraintContext>(_ctx, getState());
  enterRule(_localctx, 136, Ili2Parser::RuleMandatoryConstraint);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1216);
    match(Ili2Parser::MANDATORY);
    setState(1217);
    match(Ili2Parser::CONSTRAINT);
    setState(1218);
    dynamic_cast<MandatoryConstraintContext *>(_localctx)->booleanexp = expression();
    setState(1219);
    match(Ili2Parser::SEMI);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- PlausibilityConstraintContext ------------------------------------------------------------------

Ili2Parser::PlausibilityConstraintContext::PlausibilityConstraintContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* Ili2Parser::PlausibilityConstraintContext::CONSTRAINT() {
  return getToken(Ili2Parser::CONSTRAINT, 0);
}

tree::TerminalNode* Ili2Parser::PlausibilityConstraintContext::PERCENT() {
  return getToken(Ili2Parser::PERCENT, 0);
}

Ili2Parser::ExpressionContext* Ili2Parser::PlausibilityConstraintContext::expression() {
  return getRuleContext<Ili2Parser::ExpressionContext>(0);
}

tree::TerminalNode* Ili2Parser::PlausibilityConstraintContext::SEMI() {
  return getToken(Ili2Parser::SEMI, 0);
}

tree::TerminalNode* Ili2Parser::PlausibilityConstraintContext::LESSEQUAL() {
  return getToken(Ili2Parser::LESSEQUAL, 0);
}

tree::TerminalNode* Ili2Parser::PlausibilityConstraintContext::GREATEREQUAL() {
  return getToken(Ili2Parser::GREATEREQUAL, 0);
}

Ili2Parser::DecimalContext* Ili2Parser::PlausibilityConstraintContext::decimal() {
  return getRuleContext<Ili2Parser::DecimalContext>(0);
}


size_t Ili2Parser::PlausibilityConstraintContext::getRuleIndex() const {
  return Ili2Parser::RulePlausibilityConstraint;
}

antlrcpp::Any Ili2Parser::PlausibilityConstraintContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<Ili2ParserVisitor*>(visitor))
    return parserVisitor->visitPlausibilityConstraint(this);
  else
    return visitor->visitChildren(this);
}

Ili2Parser::PlausibilityConstraintContext* Ili2Parser::plausibilityConstraint() {
  PlausibilityConstraintContext *_localctx = _tracker.createInstance<PlausibilityConstraintContext>(_ctx, getState());
  enterRule(_localctx, 138, Ili2Parser::RulePlausibilityConstraint);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1221);
    match(Ili2Parser::CONSTRAINT);
    setState(1222);
    _la = _input->LA(1);
    if (!(_la == Ili2Parser::LESSEQUAL

    || _la == Ili2Parser::GREATEREQUAL)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
    setState(1223);
    dynamic_cast<PlausibilityConstraintContext *>(_localctx)->percentage = decimal();
    setState(1224);
    match(Ili2Parser::PERCENT);
    setState(1225);
    expression();
    setState(1226);
    match(Ili2Parser::SEMI);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ExistenceConstraintContext ------------------------------------------------------------------

Ili2Parser::ExistenceConstraintContext::ExistenceConstraintContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* Ili2Parser::ExistenceConstraintContext::EXISTENCE() {
  return getToken(Ili2Parser::EXISTENCE, 0);
}

tree::TerminalNode* Ili2Parser::ExistenceConstraintContext::CONSTRAINT() {
  return getToken(Ili2Parser::CONSTRAINT, 0);
}

std::vector<Ili2Parser::AttributePathContext *> Ili2Parser::ExistenceConstraintContext::attributePath() {
  return getRuleContexts<Ili2Parser::AttributePathContext>();
}

Ili2Parser::AttributePathContext* Ili2Parser::ExistenceConstraintContext::attributePath(size_t i) {
  return getRuleContext<Ili2Parser::AttributePathContext>(i);
}

tree::TerminalNode* Ili2Parser::ExistenceConstraintContext::REQUIRED() {
  return getToken(Ili2Parser::REQUIRED, 0);
}

tree::TerminalNode* Ili2Parser::ExistenceConstraintContext::IN() {
  return getToken(Ili2Parser::IN, 0);
}

std::vector<Ili2Parser::PathContext *> Ili2Parser::ExistenceConstraintContext::path() {
  return getRuleContexts<Ili2Parser::PathContext>();
}

Ili2Parser::PathContext* Ili2Parser::ExistenceConstraintContext::path(size_t i) {
  return getRuleContext<Ili2Parser::PathContext>(i);
}

std::vector<tree::TerminalNode *> Ili2Parser::ExistenceConstraintContext::COLON() {
  return getTokens(Ili2Parser::COLON);
}

tree::TerminalNode* Ili2Parser::ExistenceConstraintContext::COLON(size_t i) {
  return getToken(Ili2Parser::COLON, i);
}

tree::TerminalNode* Ili2Parser::ExistenceConstraintContext::SEMI() {
  return getToken(Ili2Parser::SEMI, 0);
}

std::vector<tree::TerminalNode *> Ili2Parser::ExistenceConstraintContext::OR() {
  return getTokens(Ili2Parser::OR);
}

tree::TerminalNode* Ili2Parser::ExistenceConstraintContext::OR(size_t i) {
  return getToken(Ili2Parser::OR, i);
}


size_t Ili2Parser::ExistenceConstraintContext::getRuleIndex() const {
  return Ili2Parser::RuleExistenceConstraint;
}

antlrcpp::Any Ili2Parser::ExistenceConstraintContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<Ili2ParserVisitor*>(visitor))
    return parserVisitor->visitExistenceConstraint(this);
  else
    return visitor->visitChildren(this);
}

Ili2Parser::ExistenceConstraintContext* Ili2Parser::existenceConstraint() {
  ExistenceConstraintContext *_localctx = _tracker.createInstance<ExistenceConstraintContext>(_ctx, getState());
  enterRule(_localctx, 140, Ili2Parser::RuleExistenceConstraint);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1228);
    match(Ili2Parser::EXISTENCE);
    setState(1229);
    match(Ili2Parser::CONSTRAINT);
    setState(1230);
    attributePath();
    setState(1231);
    match(Ili2Parser::REQUIRED);
    setState(1232);
    match(Ili2Parser::IN);
    setState(1233);
    path();
    setState(1234);
    match(Ili2Parser::COLON);
    setState(1235);
    attributePath();
    setState(1243);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == Ili2Parser::OR) {
      setState(1236);
      match(Ili2Parser::OR);
      setState(1237);
      path();
      setState(1238);
      match(Ili2Parser::COLON);
      setState(1239);
      attributePath();
      setState(1245);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(1246);
    match(Ili2Parser::SEMI);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- UniquenessConstraintContext ------------------------------------------------------------------

Ili2Parser::UniquenessConstraintContext::UniquenessConstraintContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* Ili2Parser::UniquenessConstraintContext::UNIQUE() {
  return getToken(Ili2Parser::UNIQUE, 0);
}

tree::TerminalNode* Ili2Parser::UniquenessConstraintContext::SEMI() {
  return getToken(Ili2Parser::SEMI, 0);
}

Ili2Parser::GlobalUniquenessContext* Ili2Parser::UniquenessConstraintContext::globalUniqueness() {
  return getRuleContext<Ili2Parser::GlobalUniquenessContext>(0);
}

Ili2Parser::LocalUniquenessContext* Ili2Parser::UniquenessConstraintContext::localUniqueness() {
  return getRuleContext<Ili2Parser::LocalUniquenessContext>(0);
}

tree::TerminalNode* Ili2Parser::UniquenessConstraintContext::WHERE() {
  return getToken(Ili2Parser::WHERE, 0);
}

Ili2Parser::ExpressionContext* Ili2Parser::UniquenessConstraintContext::expression() {
  return getRuleContext<Ili2Parser::ExpressionContext>(0);
}

tree::TerminalNode* Ili2Parser::UniquenessConstraintContext::COLON() {
  return getToken(Ili2Parser::COLON, 0);
}


size_t Ili2Parser::UniquenessConstraintContext::getRuleIndex() const {
  return Ili2Parser::RuleUniquenessConstraint;
}

antlrcpp::Any Ili2Parser::UniquenessConstraintContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<Ili2ParserVisitor*>(visitor))
    return parserVisitor->visitUniquenessConstraint(this);
  else
    return visitor->visitChildren(this);
}

Ili2Parser::UniquenessConstraintContext* Ili2Parser::uniquenessConstraint() {
  UniquenessConstraintContext *_localctx = _tracker.createInstance<UniquenessConstraintContext>(_ctx, getState());
  enterRule(_localctx, 142, Ili2Parser::RuleUniquenessConstraint);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1248);
    match(Ili2Parser::UNIQUE);
    setState(1253);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == Ili2Parser::WHERE) {
      setState(1249);
      match(Ili2Parser::WHERE);
      setState(1250);
      expression();
      setState(1251);
      match(Ili2Parser::COLON);
    }
    setState(1257);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case Ili2Parser::BACKSLASH:
      case Ili2Parser::THIS:
      case Ili2Parser::THISAREA:
      case Ili2Parser::THATAREA:
      case Ili2Parser::PARENT:
      case Ili2Parser::AGGREGATES:
      case Ili2Parser::NAME: {
        setState(1255);
        globalUniqueness();
        break;
      }

      case Ili2Parser::LPAREN: {
        setState(1256);
        localUniqueness();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    setState(1259);
    match(Ili2Parser::SEMI);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- GlobalUniquenessContext ------------------------------------------------------------------

Ili2Parser::GlobalUniquenessContext::GlobalUniquenessContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

Ili2Parser::UniqueElContext* Ili2Parser::GlobalUniquenessContext::uniqueEl() {
  return getRuleContext<Ili2Parser::UniqueElContext>(0);
}


size_t Ili2Parser::GlobalUniquenessContext::getRuleIndex() const {
  return Ili2Parser::RuleGlobalUniqueness;
}

antlrcpp::Any Ili2Parser::GlobalUniquenessContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<Ili2ParserVisitor*>(visitor))
    return parserVisitor->visitGlobalUniqueness(this);
  else
    return visitor->visitChildren(this);
}

Ili2Parser::GlobalUniquenessContext* Ili2Parser::globalUniqueness() {
  GlobalUniquenessContext *_localctx = _tracker.createInstance<GlobalUniquenessContext>(_ctx, getState());
  enterRule(_localctx, 144, Ili2Parser::RuleGlobalUniqueness);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1261);
    uniqueEl();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- UniqueElContext ------------------------------------------------------------------

Ili2Parser::UniqueElContext::UniqueElContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<Ili2Parser::ObjectOrAttributePathContext *> Ili2Parser::UniqueElContext::objectOrAttributePath() {
  return getRuleContexts<Ili2Parser::ObjectOrAttributePathContext>();
}

Ili2Parser::ObjectOrAttributePathContext* Ili2Parser::UniqueElContext::objectOrAttributePath(size_t i) {
  return getRuleContext<Ili2Parser::ObjectOrAttributePathContext>(i);
}

std::vector<tree::TerminalNode *> Ili2Parser::UniqueElContext::COMMA() {
  return getTokens(Ili2Parser::COMMA);
}

tree::TerminalNode* Ili2Parser::UniqueElContext::COMMA(size_t i) {
  return getToken(Ili2Parser::COMMA, i);
}


size_t Ili2Parser::UniqueElContext::getRuleIndex() const {
  return Ili2Parser::RuleUniqueEl;
}

antlrcpp::Any Ili2Parser::UniqueElContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<Ili2ParserVisitor*>(visitor))
    return parserVisitor->visitUniqueEl(this);
  else
    return visitor->visitChildren(this);
}

Ili2Parser::UniqueElContext* Ili2Parser::uniqueEl() {
  UniqueElContext *_localctx = _tracker.createInstance<UniqueElContext>(_ctx, getState());
  enterRule(_localctx, 146, Ili2Parser::RuleUniqueEl);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1263);
    objectOrAttributePath();
    setState(1268);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == Ili2Parser::COMMA) {
      setState(1264);
      match(Ili2Parser::COMMA);
      setState(1265);
      objectOrAttributePath();
      setState(1270);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- LocalUniquenessContext ------------------------------------------------------------------

Ili2Parser::LocalUniquenessContext::LocalUniquenessContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* Ili2Parser::LocalUniquenessContext::LPAREN() {
  return getToken(Ili2Parser::LPAREN, 0);
}

tree::TerminalNode* Ili2Parser::LocalUniquenessContext::LOCAL() {
  return getToken(Ili2Parser::LOCAL, 0);
}

tree::TerminalNode* Ili2Parser::LocalUniquenessContext::RPAREN() {
  return getToken(Ili2Parser::RPAREN, 0);
}

tree::TerminalNode* Ili2Parser::LocalUniquenessContext::COLON() {
  return getToken(Ili2Parser::COLON, 0);
}

std::vector<tree::TerminalNode *> Ili2Parser::LocalUniquenessContext::NAME() {
  return getTokens(Ili2Parser::NAME);
}

tree::TerminalNode* Ili2Parser::LocalUniquenessContext::NAME(size_t i) {
  return getToken(Ili2Parser::NAME, i);
}

std::vector<tree::TerminalNode *> Ili2Parser::LocalUniquenessContext::RARROW() {
  return getTokens(Ili2Parser::RARROW);
}

tree::TerminalNode* Ili2Parser::LocalUniquenessContext::RARROW(size_t i) {
  return getToken(Ili2Parser::RARROW, i);
}

std::vector<tree::TerminalNode *> Ili2Parser::LocalUniquenessContext::COMMA() {
  return getTokens(Ili2Parser::COMMA);
}

tree::TerminalNode* Ili2Parser::LocalUniquenessContext::COMMA(size_t i) {
  return getToken(Ili2Parser::COMMA, i);
}


size_t Ili2Parser::LocalUniquenessContext::getRuleIndex() const {
  return Ili2Parser::RuleLocalUniqueness;
}

antlrcpp::Any Ili2Parser::LocalUniquenessContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<Ili2ParserVisitor*>(visitor))
    return parserVisitor->visitLocalUniqueness(this);
  else
    return visitor->visitChildren(this);
}

Ili2Parser::LocalUniquenessContext* Ili2Parser::localUniqueness() {
  LocalUniquenessContext *_localctx = _tracker.createInstance<LocalUniquenessContext>(_ctx, getState());
  enterRule(_localctx, 148, Ili2Parser::RuleLocalUniqueness);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1271);
    match(Ili2Parser::LPAREN);
    setState(1272);
    match(Ili2Parser::LOCAL);
    setState(1273);
    match(Ili2Parser::RPAREN);
    setState(1274);
    dynamic_cast<LocalUniquenessContext *>(_localctx)->structureattributename = match(Ili2Parser::NAME);
    setState(1279);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == Ili2Parser::RARROW) {
      setState(1275);
      match(Ili2Parser::RARROW);
      setState(1276);
      dynamic_cast<LocalUniquenessContext *>(_localctx)->structureattributename = match(Ili2Parser::NAME);
      setState(1281);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(1282);
    match(Ili2Parser::COLON);
    setState(1283);
    dynamic_cast<LocalUniquenessContext *>(_localctx)->attributename = match(Ili2Parser::NAME);
    setState(1288);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == Ili2Parser::COMMA) {
      setState(1284);
      match(Ili2Parser::COMMA);
      setState(1285);
      dynamic_cast<LocalUniquenessContext *>(_localctx)->attributename = match(Ili2Parser::NAME);
      setState(1290);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- SetConstraintContext ------------------------------------------------------------------

Ili2Parser::SetConstraintContext::SetConstraintContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* Ili2Parser::SetConstraintContext::SET() {
  return getToken(Ili2Parser::SET, 0);
}

tree::TerminalNode* Ili2Parser::SetConstraintContext::CONSTRAINT() {
  return getToken(Ili2Parser::CONSTRAINT, 0);
}

std::vector<Ili2Parser::ExpressionContext *> Ili2Parser::SetConstraintContext::expression() {
  return getRuleContexts<Ili2Parser::ExpressionContext>();
}

Ili2Parser::ExpressionContext* Ili2Parser::SetConstraintContext::expression(size_t i) {
  return getRuleContext<Ili2Parser::ExpressionContext>(i);
}

tree::TerminalNode* Ili2Parser::SetConstraintContext::SEMI() {
  return getToken(Ili2Parser::SEMI, 0);
}

std::vector<tree::TerminalNode *> Ili2Parser::SetConstraintContext::COLON() {
  return getTokens(Ili2Parser::COLON);
}

tree::TerminalNode* Ili2Parser::SetConstraintContext::COLON(size_t i) {
  return getToken(Ili2Parser::COLON, i);
}

tree::TerminalNode* Ili2Parser::SetConstraintContext::WHERE() {
  return getToken(Ili2Parser::WHERE, 0);
}

tree::TerminalNode* Ili2Parser::SetConstraintContext::NAME() {
  return getToken(Ili2Parser::NAME, 0);
}


size_t Ili2Parser::SetConstraintContext::getRuleIndex() const {
  return Ili2Parser::RuleSetConstraint;
}

antlrcpp::Any Ili2Parser::SetConstraintContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<Ili2ParserVisitor*>(visitor))
    return parserVisitor->visitSetConstraint(this);
  else
    return visitor->visitChildren(this);
}

Ili2Parser::SetConstraintContext* Ili2Parser::setConstraint() {
  SetConstraintContext *_localctx = _tracker.createInstance<SetConstraintContext>(_ctx, getState());
  enterRule(_localctx, 150, Ili2Parser::RuleSetConstraint);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1291);
    match(Ili2Parser::SET);
    setState(1292);
    match(Ili2Parser::CONSTRAINT);
    setState(1296);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 166, _ctx)) {
    case 1: {
      setState(1293);

      if (!(ili24)) throw FailedPredicateException(this, "ili24");
      setState(1294);
      dynamic_cast<SetConstraintContext *>(_localctx)->name = match(Ili2Parser::NAME);
      setState(1295);
      match(Ili2Parser::COLON);
      break;
    }

    }
    setState(1302);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == Ili2Parser::WHERE) {
      setState(1298);
      match(Ili2Parser::WHERE);
      setState(1299);
      dynamic_cast<SetConstraintContext *>(_localctx)->logical = expression();
      setState(1300);
      match(Ili2Parser::COLON);
    }
    setState(1304);
    expression();
    setState(1305);
    match(Ili2Parser::SEMI);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ConstraintsDefContext ------------------------------------------------------------------

Ili2Parser::ConstraintsDefContext::ConstraintsDefContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* Ili2Parser::ConstraintsDefContext::CONSTRAINTS() {
  return getToken(Ili2Parser::CONSTRAINTS, 0);
}

tree::TerminalNode* Ili2Parser::ConstraintsDefContext::OF() {
  return getToken(Ili2Parser::OF, 0);
}

Ili2Parser::PathContext* Ili2Parser::ConstraintsDefContext::path() {
  return getRuleContext<Ili2Parser::PathContext>(0);
}

tree::TerminalNode* Ili2Parser::ConstraintsDefContext::EQUAL() {
  return getToken(Ili2Parser::EQUAL, 0);
}

tree::TerminalNode* Ili2Parser::ConstraintsDefContext::END() {
  return getToken(Ili2Parser::END, 0);
}

tree::TerminalNode* Ili2Parser::ConstraintsDefContext::SEMI() {
  return getToken(Ili2Parser::SEMI, 0);
}

std::vector<Ili2Parser::ConstraintDefContext *> Ili2Parser::ConstraintsDefContext::constraintDef() {
  return getRuleContexts<Ili2Parser::ConstraintDefContext>();
}

Ili2Parser::ConstraintDefContext* Ili2Parser::ConstraintsDefContext::constraintDef(size_t i) {
  return getRuleContext<Ili2Parser::ConstraintDefContext>(i);
}


size_t Ili2Parser::ConstraintsDefContext::getRuleIndex() const {
  return Ili2Parser::RuleConstraintsDef;
}

antlrcpp::Any Ili2Parser::ConstraintsDefContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<Ili2ParserVisitor*>(visitor))
    return parserVisitor->visitConstraintsDef(this);
  else
    return visitor->visitChildren(this);
}

Ili2Parser::ConstraintsDefContext* Ili2Parser::constraintsDef() {
  ConstraintsDefContext *_localctx = _tracker.createInstance<ConstraintsDefContext>(_ctx, getState());
  enterRule(_localctx, 152, Ili2Parser::RuleConstraintsDef);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1307);
    match(Ili2Parser::CONSTRAINTS);
    setState(1308);
    match(Ili2Parser::OF);
    setState(1309);
    path();
    setState(1310);
    match(Ili2Parser::EQUAL);
    setState(1314);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (((((_la - 83) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 83)) & ((1ULL << (Ili2Parser::MANDATORY - 83))
      | (1ULL << (Ili2Parser::CONSTRAINT - 83))
      | (1ULL << (Ili2Parser::EXISTENCE - 83)))) != 0) || _la == Ili2Parser::UNIQUE

    || _la == Ili2Parser::SET) {
      setState(1311);
      constraintDef();
      setState(1316);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(1317);
    match(Ili2Parser::END);
    setState(1318);
    match(Ili2Parser::SEMI);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ExpressionContext ------------------------------------------------------------------

Ili2Parser::ExpressionContext::ExpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

Ili2Parser::OrTermContext* Ili2Parser::ExpressionContext::orTerm() {
  return getRuleContext<Ili2Parser::OrTermContext>(0);
}


size_t Ili2Parser::ExpressionContext::getRuleIndex() const {
  return Ili2Parser::RuleExpression;
}

antlrcpp::Any Ili2Parser::ExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<Ili2ParserVisitor*>(visitor))
    return parserVisitor->visitExpression(this);
  else
    return visitor->visitChildren(this);
}

Ili2Parser::ExpressionContext* Ili2Parser::expression() {
  ExpressionContext *_localctx = _tracker.createInstance<ExpressionContext>(_ctx, getState());
  enterRule(_localctx, 154, Ili2Parser::RuleExpression);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1320);
    orTerm();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- OrTermContext ------------------------------------------------------------------

Ili2Parser::OrTermContext::OrTermContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<Ili2Parser::AndTermContext *> Ili2Parser::OrTermContext::andTerm() {
  return getRuleContexts<Ili2Parser::AndTermContext>();
}

Ili2Parser::AndTermContext* Ili2Parser::OrTermContext::andTerm(size_t i) {
  return getRuleContext<Ili2Parser::AndTermContext>(i);
}

std::vector<tree::TerminalNode *> Ili2Parser::OrTermContext::OR() {
  return getTokens(Ili2Parser::OR);
}

tree::TerminalNode* Ili2Parser::OrTermContext::OR(size_t i) {
  return getToken(Ili2Parser::OR, i);
}

std::vector<tree::TerminalNode *> Ili2Parser::OrTermContext::PLUS() {
  return getTokens(Ili2Parser::PLUS);
}

tree::TerminalNode* Ili2Parser::OrTermContext::PLUS(size_t i) {
  return getToken(Ili2Parser::PLUS, i);
}

std::vector<tree::TerminalNode *> Ili2Parser::OrTermContext::MINUS() {
  return getTokens(Ili2Parser::MINUS);
}

tree::TerminalNode* Ili2Parser::OrTermContext::MINUS(size_t i) {
  return getToken(Ili2Parser::MINUS, i);
}


size_t Ili2Parser::OrTermContext::getRuleIndex() const {
  return Ili2Parser::RuleOrTerm;
}

antlrcpp::Any Ili2Parser::OrTermContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<Ili2ParserVisitor*>(visitor))
    return parserVisitor->visitOrTerm(this);
  else
    return visitor->visitChildren(this);
}

Ili2Parser::OrTermContext* Ili2Parser::orTerm() {
  OrTermContext *_localctx = _tracker.createInstance<OrTermContext>(_ctx, getState());
  enterRule(_localctx, 156, Ili2Parser::RuleOrTerm);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(1322);
    andTerm();
    setState(1333);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 170, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(1328);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 169, _ctx)) {
        case 1: {
          setState(1323);
          match(Ili2Parser::OR);
          break;
        }

        case 2: {
          setState(1324);

          if (!(ili24)) throw FailedPredicateException(this, "ili24");
          setState(1325);
          match(Ili2Parser::PLUS);
          break;
        }

        case 3: {
          setState(1326);

          if (!(ili24)) throw FailedPredicateException(this, "ili24");
          setState(1327);
          match(Ili2Parser::MINUS);
          break;
        }

        }
        setState(1330);
        andTerm(); 
      }
      setState(1335);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 170, _ctx);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- AndTermContext ------------------------------------------------------------------

Ili2Parser::AndTermContext::AndTermContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<Ili2Parser::PredicateTermContext *> Ili2Parser::AndTermContext::predicateTerm() {
  return getRuleContexts<Ili2Parser::PredicateTermContext>();
}

Ili2Parser::PredicateTermContext* Ili2Parser::AndTermContext::predicateTerm(size_t i) {
  return getRuleContext<Ili2Parser::PredicateTermContext>(i);
}

std::vector<tree::TerminalNode *> Ili2Parser::AndTermContext::AND() {
  return getTokens(Ili2Parser::AND);
}

tree::TerminalNode* Ili2Parser::AndTermContext::AND(size_t i) {
  return getToken(Ili2Parser::AND, i);
}

std::vector<tree::TerminalNode *> Ili2Parser::AndTermContext::STAR() {
  return getTokens(Ili2Parser::STAR);
}

tree::TerminalNode* Ili2Parser::AndTermContext::STAR(size_t i) {
  return getToken(Ili2Parser::STAR, i);
}

std::vector<tree::TerminalNode *> Ili2Parser::AndTermContext::SLASH() {
  return getTokens(Ili2Parser::SLASH);
}

tree::TerminalNode* Ili2Parser::AndTermContext::SLASH(size_t i) {
  return getToken(Ili2Parser::SLASH, i);
}


size_t Ili2Parser::AndTermContext::getRuleIndex() const {
  return Ili2Parser::RuleAndTerm;
}

antlrcpp::Any Ili2Parser::AndTermContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<Ili2ParserVisitor*>(visitor))
    return parserVisitor->visitAndTerm(this);
  else
    return visitor->visitChildren(this);
}

Ili2Parser::AndTermContext* Ili2Parser::andTerm() {
  AndTermContext *_localctx = _tracker.createInstance<AndTermContext>(_ctx, getState());
  enterRule(_localctx, 158, Ili2Parser::RuleAndTerm);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(1336);
    predicateTerm();
    setState(1347);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 172, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(1342);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 171, _ctx)) {
        case 1: {
          setState(1337);
          match(Ili2Parser::AND);
          break;
        }

        case 2: {
          setState(1338);

          if (!(ili24)) throw FailedPredicateException(this, "ili24");
          setState(1339);
          match(Ili2Parser::STAR);
          break;
        }

        case 3: {
          setState(1340);

          if (!(ili24)) throw FailedPredicateException(this, "ili24");
          setState(1341);
          match(Ili2Parser::SLASH);
          break;
        }

        }
        setState(1344);
        predicateTerm(); 
      }
      setState(1349);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 172, _ctx);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- PredicateTermContext ------------------------------------------------------------------

Ili2Parser::PredicateTermContext::PredicateTermContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<Ili2Parser::PredicateContext *> Ili2Parser::PredicateTermContext::predicate() {
  return getRuleContexts<Ili2Parser::PredicateContext>();
}

Ili2Parser::PredicateContext* Ili2Parser::PredicateTermContext::predicate(size_t i) {
  return getRuleContext<Ili2Parser::PredicateContext>(i);
}

Ili2Parser::RelationContext* Ili2Parser::PredicateTermContext::relation() {
  return getRuleContext<Ili2Parser::RelationContext>(0);
}


size_t Ili2Parser::PredicateTermContext::getRuleIndex() const {
  return Ili2Parser::RulePredicateTerm;
}

antlrcpp::Any Ili2Parser::PredicateTermContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<Ili2ParserVisitor*>(visitor))
    return parserVisitor->visitPredicateTerm(this);
  else
    return visitor->visitChildren(this);
}

Ili2Parser::PredicateTermContext* Ili2Parser::predicateTerm() {
  PredicateTermContext *_localctx = _tracker.createInstance<PredicateTermContext>(_ctx, getState());
  enterRule(_localctx, 160, Ili2Parser::RulePredicateTerm);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1350);
    dynamic_cast<PredicateTermContext *>(_localctx)->predicate1 = predicate();
    setState(1354);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 173, _ctx)) {
    case 1: {
      setState(1351);
      relation();
      setState(1352);
      dynamic_cast<PredicateTermContext *>(_localctx)->predicate2 = predicate();
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- PredicateContext ------------------------------------------------------------------

Ili2Parser::PredicateContext::PredicateContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

Ili2Parser::FactorContext* Ili2Parser::PredicateContext::factor() {
  return getRuleContext<Ili2Parser::FactorContext>(0);
}

tree::TerminalNode* Ili2Parser::PredicateContext::LPAREN() {
  return getToken(Ili2Parser::LPAREN, 0);
}

Ili2Parser::ExpressionContext* Ili2Parser::PredicateContext::expression() {
  return getRuleContext<Ili2Parser::ExpressionContext>(0);
}

tree::TerminalNode* Ili2Parser::PredicateContext::RPAREN() {
  return getToken(Ili2Parser::RPAREN, 0);
}

tree::TerminalNode* Ili2Parser::PredicateContext::NOT() {
  return getToken(Ili2Parser::NOT, 0);
}

tree::TerminalNode* Ili2Parser::PredicateContext::DEFINED() {
  return getToken(Ili2Parser::DEFINED, 0);
}


size_t Ili2Parser::PredicateContext::getRuleIndex() const {
  return Ili2Parser::RulePredicate;
}

antlrcpp::Any Ili2Parser::PredicateContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<Ili2ParserVisitor*>(visitor))
    return parserVisitor->visitPredicate(this);
  else
    return visitor->visitChildren(this);
}

Ili2Parser::PredicateContext* Ili2Parser::predicate() {
  PredicateContext *_localctx = _tracker.createInstance<PredicateContext>(_ctx, getState());
  enterRule(_localctx, 162, Ili2Parser::RulePredicate);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(1369);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case Ili2Parser::INTERLIS:
      case Ili2Parser::BACKSLASH:
      case Ili2Parser::HASH:
      case Ili2Parser::GREATERGREATER:
      case Ili2Parser::GREATER:
      case Ili2Parser::PARAMETER:
      case Ili2Parser::UNDEFINED:
      case Ili2Parser::PI:
      case Ili2Parser::LNBASE:
      case Ili2Parser::AREA:
      case Ili2Parser::INSPECTION:
      case Ili2Parser::THIS:
      case Ili2Parser::THISAREA:
      case Ili2Parser::THATAREA:
      case Ili2Parser::PARENT:
      case Ili2Parser::AGGREGATES:
      case Ili2Parser::STRING:
      case Ili2Parser::POSNUMBER:
      case Ili2Parser::NUMBER:
      case Ili2Parser::DEC:
      case Ili2Parser::NAME: {
        enterOuterAlt(_localctx, 1);
        setState(1356);
        factor();
        break;
      }

      case Ili2Parser::LPAREN:
      case Ili2Parser::NOT: {
        enterOuterAlt(_localctx, 2);
        setState(1358);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == Ili2Parser::NOT) {
          setState(1357);
          match(Ili2Parser::NOT);
        }
        setState(1360);
        match(Ili2Parser::LPAREN);
        setState(1361);
        expression();
        setState(1362);
        match(Ili2Parser::RPAREN);
        break;
      }

      case Ili2Parser::DEFINED: {
        enterOuterAlt(_localctx, 3);
        setState(1364);
        match(Ili2Parser::DEFINED);
        setState(1365);
        match(Ili2Parser::LPAREN);
        setState(1366);
        factor();
        setState(1367);
        match(Ili2Parser::RPAREN);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- RelationContext ------------------------------------------------------------------

Ili2Parser::RelationContext::RelationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* Ili2Parser::RelationContext::EQUALEQUAL() {
  return getToken(Ili2Parser::EQUALEQUAL, 0);
}

tree::TerminalNode* Ili2Parser::RelationContext::NOTEQUAL() {
  return getToken(Ili2Parser::NOTEQUAL, 0);
}

tree::TerminalNode* Ili2Parser::RelationContext::LESSGREATER() {
  return getToken(Ili2Parser::LESSGREATER, 0);
}

tree::TerminalNode* Ili2Parser::RelationContext::LESSEQUAL() {
  return getToken(Ili2Parser::LESSEQUAL, 0);
}

tree::TerminalNode* Ili2Parser::RelationContext::GREATEREQUAL() {
  return getToken(Ili2Parser::GREATEREQUAL, 0);
}

tree::TerminalNode* Ili2Parser::RelationContext::LESS() {
  return getToken(Ili2Parser::LESS, 0);
}

tree::TerminalNode* Ili2Parser::RelationContext::GREATER() {
  return getToken(Ili2Parser::GREATER, 0);
}


size_t Ili2Parser::RelationContext::getRuleIndex() const {
  return Ili2Parser::RuleRelation;
}

antlrcpp::Any Ili2Parser::RelationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<Ili2ParserVisitor*>(visitor))
    return parserVisitor->visitRelation(this);
  else
    return visitor->visitChildren(this);
}

Ili2Parser::RelationContext* Ili2Parser::relation() {
  RelationContext *_localctx = _tracker.createInstance<RelationContext>(_ctx, getState());
  enterRule(_localctx, 164, Ili2Parser::RuleRelation);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1371);
    _la = _input->LA(1);
    if (!(((((_la - 58) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 58)) & ((1ULL << (Ili2Parser::LESS - 58))
      | (1ULL << (Ili2Parser::LESSEQUAL - 58))
      | (1ULL << (Ili2Parser::GREATER - 58))
      | (1ULL << (Ili2Parser::GREATEREQUAL - 58))
      | (1ULL << (Ili2Parser::EQUALEQUAL - 58))
      | (1ULL << (Ili2Parser::LESSGREATER - 58))
      | (1ULL << (Ili2Parser::NOTEQUAL - 58)))) != 0))) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FactorContext ------------------------------------------------------------------

Ili2Parser::FactorContext::FactorContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

Ili2Parser::ObjectOrAttributePathContext* Ili2Parser::FactorContext::objectOrAttributePath() {
  return getRuleContext<Ili2Parser::ObjectOrAttributePathContext>(0);
}

Ili2Parser::InspectionContext* Ili2Parser::FactorContext::inspection() {
  return getRuleContext<Ili2Parser::InspectionContext>(0);
}

tree::TerminalNode* Ili2Parser::FactorContext::INSPECTION() {
  return getToken(Ili2Parser::INSPECTION, 0);
}

Ili2Parser::PathContext* Ili2Parser::FactorContext::path() {
  return getRuleContext<Ili2Parser::PathContext>(0);
}

tree::TerminalNode* Ili2Parser::FactorContext::OF() {
  return getToken(Ili2Parser::OF, 0);
}

Ili2Parser::FunctionCallContext* Ili2Parser::FactorContext::functionCall() {
  return getRuleContext<Ili2Parser::FunctionCallContext>(0);
}

tree::TerminalNode* Ili2Parser::FactorContext::PARAMETER() {
  return getToken(Ili2Parser::PARAMETER, 0);
}

std::vector<tree::TerminalNode *> Ili2Parser::FactorContext::NAME() {
  return getTokens(Ili2Parser::NAME);
}

tree::TerminalNode* Ili2Parser::FactorContext::NAME(size_t i) {
  return getToken(Ili2Parser::NAME, i);
}

std::vector<tree::TerminalNode *> Ili2Parser::FactorContext::DOT() {
  return getTokens(Ili2Parser::DOT);
}

tree::TerminalNode* Ili2Parser::FactorContext::DOT(size_t i) {
  return getToken(Ili2Parser::DOT, i);
}

Ili2Parser::ConstantContext* Ili2Parser::FactorContext::constant() {
  return getRuleContext<Ili2Parser::ConstantContext>(0);
}


size_t Ili2Parser::FactorContext::getRuleIndex() const {
  return Ili2Parser::RuleFactor;
}

antlrcpp::Any Ili2Parser::FactorContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<Ili2ParserVisitor*>(visitor))
    return parserVisitor->visitFactor(this);
  else
    return visitor->visitChildren(this);
}

Ili2Parser::FactorContext* Ili2Parser::factor() {
  FactorContext *_localctx = _tracker.createInstance<FactorContext>(_ctx, getState());
  enterRule(_localctx, 166, Ili2Parser::RuleFactor);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    size_t alt;
    setState(1394);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 179, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(1373);
      dynamic_cast<FactorContext *>(_localctx)->objectpath = objectOrAttributePath();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(1377);
      _errHandler->sync(this);
      switch (_input->LA(1)) {
        case Ili2Parser::AREA: {
          setState(1374);
          inspection();
          break;
        }

        case Ili2Parser::INSPECTION: {
          setState(1375);
          match(Ili2Parser::INSPECTION);
          setState(1376);
          path();
          break;
        }

      default:
        throw NoViableAltException(this);
      }
      setState(1381);
      _errHandler->sync(this);

      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 177, _ctx)) {
      case 1: {
        setState(1379);
        match(Ili2Parser::OF);
        setState(1380);
        dynamic_cast<FactorContext *>(_localctx)->inspaectionpath = objectOrAttributePath();
        break;
      }

      }
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(1383);
      functionCall();
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(1384);
      match(Ili2Parser::PARAMETER);
      setState(1389);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 178, _ctx);
      while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
        if (alt == 1) {
          setState(1385);
          dynamic_cast<FactorContext *>(_localctx)->modelname = match(Ili2Parser::NAME);
          setState(1386);
          match(Ili2Parser::DOT); 
        }
        setState(1391);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 178, _ctx);
      }
      setState(1392);
      dynamic_cast<FactorContext *>(_localctx)->runtimeparametername = match(Ili2Parser::NAME);
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
      setState(1393);
      constant();
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ObjectOrAttributePathContext ------------------------------------------------------------------

Ili2Parser::ObjectOrAttributePathContext::ObjectOrAttributePathContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<Ili2Parser::PathElContext *> Ili2Parser::ObjectOrAttributePathContext::pathEl() {
  return getRuleContexts<Ili2Parser::PathElContext>();
}

Ili2Parser::PathElContext* Ili2Parser::ObjectOrAttributePathContext::pathEl(size_t i) {
  return getRuleContext<Ili2Parser::PathElContext>(i);
}

std::vector<tree::TerminalNode *> Ili2Parser::ObjectOrAttributePathContext::RARROW() {
  return getTokens(Ili2Parser::RARROW);
}

tree::TerminalNode* Ili2Parser::ObjectOrAttributePathContext::RARROW(size_t i) {
  return getToken(Ili2Parser::RARROW, i);
}


size_t Ili2Parser::ObjectOrAttributePathContext::getRuleIndex() const {
  return Ili2Parser::RuleObjectOrAttributePath;
}

antlrcpp::Any Ili2Parser::ObjectOrAttributePathContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<Ili2ParserVisitor*>(visitor))
    return parserVisitor->visitObjectOrAttributePath(this);
  else
    return visitor->visitChildren(this);
}

Ili2Parser::ObjectOrAttributePathContext* Ili2Parser::objectOrAttributePath() {
  ObjectOrAttributePathContext *_localctx = _tracker.createInstance<ObjectOrAttributePathContext>(_ctx, getState());
  enterRule(_localctx, 168, Ili2Parser::RuleObjectOrAttributePath);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(1396);
    pathEl();
    setState(1401);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 180, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(1397);
        match(Ili2Parser::RARROW);
        setState(1398);
        pathEl(); 
      }
      setState(1403);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 180, _ctx);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- AttributePathContext ------------------------------------------------------------------

Ili2Parser::AttributePathContext::AttributePathContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

Ili2Parser::ObjectOrAttributePathContext* Ili2Parser::AttributePathContext::objectOrAttributePath() {
  return getRuleContext<Ili2Parser::ObjectOrAttributePathContext>(0);
}


size_t Ili2Parser::AttributePathContext::getRuleIndex() const {
  return Ili2Parser::RuleAttributePath;
}

antlrcpp::Any Ili2Parser::AttributePathContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<Ili2ParserVisitor*>(visitor))
    return parserVisitor->visitAttributePath(this);
  else
    return visitor->visitChildren(this);
}

Ili2Parser::AttributePathContext* Ili2Parser::attributePath() {
  AttributePathContext *_localctx = _tracker.createInstance<AttributePathContext>(_ctx, getState());
  enterRule(_localctx, 170, Ili2Parser::RuleAttributePath);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1404);
    objectOrAttributePath();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- PathElContext ------------------------------------------------------------------

Ili2Parser::PathElContext::PathElContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* Ili2Parser::PathElContext::THIS() {
  return getToken(Ili2Parser::THIS, 0);
}

tree::TerminalNode* Ili2Parser::PathElContext::THISAREA() {
  return getToken(Ili2Parser::THISAREA, 0);
}

tree::TerminalNode* Ili2Parser::PathElContext::THATAREA() {
  return getToken(Ili2Parser::THATAREA, 0);
}

tree::TerminalNode* Ili2Parser::PathElContext::PARENT() {
  return getToken(Ili2Parser::PARENT, 0);
}

std::vector<tree::TerminalNode *> Ili2Parser::PathElContext::NAME() {
  return getTokens(Ili2Parser::NAME);
}

tree::TerminalNode* Ili2Parser::PathElContext::NAME(size_t i) {
  return getToken(Ili2Parser::NAME, i);
}

Ili2Parser::AssociationPathContext* Ili2Parser::PathElContext::associationPath() {
  return getRuleContext<Ili2Parser::AssociationPathContext>(0);
}

tree::TerminalNode* Ili2Parser::PathElContext::LBRACE() {
  return getToken(Ili2Parser::LBRACE, 0);
}

tree::TerminalNode* Ili2Parser::PathElContext::RBRACE() {
  return getToken(Ili2Parser::RBRACE, 0);
}

Ili2Parser::AttributeRefContext* Ili2Parser::PathElContext::attributeRef() {
  return getRuleContext<Ili2Parser::AttributeRefContext>(0);
}


size_t Ili2Parser::PathElContext::getRuleIndex() const {
  return Ili2Parser::RulePathEl;
}

antlrcpp::Any Ili2Parser::PathElContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<Ili2ParserVisitor*>(visitor))
    return parserVisitor->visitPathEl(this);
  else
    return visitor->visitChildren(this);
}

Ili2Parser::PathElContext* Ili2Parser::pathEl() {
  PathElContext *_localctx = _tracker.createInstance<PathElContext>(_ctx, getState());
  enterRule(_localctx, 172, Ili2Parser::RulePathEl);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(1420);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 182, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(1406);
      match(Ili2Parser::THIS);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(1407);
      match(Ili2Parser::THISAREA);
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(1408);
      match(Ili2Parser::THATAREA);
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(1409);
      match(Ili2Parser::PARENT);
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
      setState(1410);
      dynamic_cast<PathElContext *>(_localctx)->referenceattributename = match(Ili2Parser::NAME);
      break;
    }

    case 6: {
      enterOuterAlt(_localctx, 6);
      setState(1411);
      associationPath();
      break;
    }

    case 7: {
      enterOuterAlt(_localctx, 7);
      setState(1412);
      dynamic_cast<PathElContext *>(_localctx)->rolename = match(Ili2Parser::NAME);
      setState(1416);
      _errHandler->sync(this);

      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 181, _ctx)) {
      case 1: {
        setState(1413);
        match(Ili2Parser::LBRACE);
        setState(1414);
        dynamic_cast<PathElContext *>(_localctx)->associationname = match(Ili2Parser::NAME);
        setState(1415);
        match(Ili2Parser::RBRACE);
        break;
      }

      }
      break;
    }

    case 8: {
      enterOuterAlt(_localctx, 8);
      setState(1418);
      dynamic_cast<PathElContext *>(_localctx)->basename = match(Ili2Parser::NAME);
      break;
    }

    case 9: {
      enterOuterAlt(_localctx, 9);
      setState(1419);
      attributeRef();
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- AssociationPathContext ------------------------------------------------------------------

Ili2Parser::AssociationPathContext::AssociationPathContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* Ili2Parser::AssociationPathContext::NAME() {
  return getToken(Ili2Parser::NAME, 0);
}

tree::TerminalNode* Ili2Parser::AssociationPathContext::BACKSLASH() {
  return getToken(Ili2Parser::BACKSLASH, 0);
}


size_t Ili2Parser::AssociationPathContext::getRuleIndex() const {
  return Ili2Parser::RuleAssociationPath;
}

antlrcpp::Any Ili2Parser::AssociationPathContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<Ili2ParserVisitor*>(visitor))
    return parserVisitor->visitAssociationPath(this);
  else
    return visitor->visitChildren(this);
}

Ili2Parser::AssociationPathContext* Ili2Parser::associationPath() {
  AssociationPathContext *_localctx = _tracker.createInstance<AssociationPathContext>(_ctx, getState());
  enterRule(_localctx, 174, Ili2Parser::RuleAssociationPath);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1423);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == Ili2Parser::BACKSLASH) {
      setState(1422);
      match(Ili2Parser::BACKSLASH);
    }
    setState(1425);
    dynamic_cast<AssociationPathContext *>(_localctx)->associationaccessmame = match(Ili2Parser::NAME);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- AttributeRefContext ------------------------------------------------------------------

Ili2Parser::AttributeRefContext::AttributeRefContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* Ili2Parser::AttributeRefContext::AGGREGATES() {
  return getToken(Ili2Parser::AGGREGATES, 0);
}

tree::TerminalNode* Ili2Parser::AttributeRefContext::NAME() {
  return getToken(Ili2Parser::NAME, 0);
}

tree::TerminalNode* Ili2Parser::AttributeRefContext::LBRACE() {
  return getToken(Ili2Parser::LBRACE, 0);
}

tree::TerminalNode* Ili2Parser::AttributeRefContext::RBRACE() {
  return getToken(Ili2Parser::RBRACE, 0);
}

tree::TerminalNode* Ili2Parser::AttributeRefContext::FIRST() {
  return getToken(Ili2Parser::FIRST, 0);
}

tree::TerminalNode* Ili2Parser::AttributeRefContext::LAST() {
  return getToken(Ili2Parser::LAST, 0);
}

tree::TerminalNode* Ili2Parser::AttributeRefContext::POSNUMBER() {
  return getToken(Ili2Parser::POSNUMBER, 0);
}


size_t Ili2Parser::AttributeRefContext::getRuleIndex() const {
  return Ili2Parser::RuleAttributeRef;
}

antlrcpp::Any Ili2Parser::AttributeRefContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<Ili2ParserVisitor*>(visitor))
    return parserVisitor->visitAttributeRef(this);
  else
    return visitor->visitChildren(this);
}

Ili2Parser::AttributeRefContext* Ili2Parser::attributeRef() {
  AttributeRefContext *_localctx = _tracker.createInstance<AttributeRefContext>(_ctx, getState());
  enterRule(_localctx, 176, Ili2Parser::RuleAttributeRef);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1438);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case Ili2Parser::NAME: {
        setState(1427);
        dynamic_cast<AttributeRefContext *>(_localctx)->attributename = match(Ili2Parser::NAME);

        setState(1435);
        _errHandler->sync(this);

        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 185, _ctx)) {
        case 1: {
          setState(1428);
          match(Ili2Parser::LBRACE);
          setState(1432);
          _errHandler->sync(this);
          switch (_input->LA(1)) {
            case Ili2Parser::FIRST: {
              setState(1429);
              match(Ili2Parser::FIRST);
              break;
            }

            case Ili2Parser::LAST: {
              setState(1430);
              match(Ili2Parser::LAST);
              break;
            }

            case Ili2Parser::POSNUMBER: {
              setState(1431);
              dynamic_cast<AttributeRefContext *>(_localctx)->axislistindex = match(Ili2Parser::POSNUMBER);
              break;
            }

          default:
            throw NoViableAltException(this);
          }
          setState(1434);
          match(Ili2Parser::RBRACE);
          break;
        }

        }
        break;
      }

      case Ili2Parser::AGGREGATES: {
        setState(1437);
        match(Ili2Parser::AGGREGATES);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FunctionCallContext ------------------------------------------------------------------

Ili2Parser::FunctionCallContext::FunctionCallContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* Ili2Parser::FunctionCallContext::LPAREN() {
  return getToken(Ili2Parser::LPAREN, 0);
}

tree::TerminalNode* Ili2Parser::FunctionCallContext::RPAREN() {
  return getToken(Ili2Parser::RPAREN, 0);
}

Ili2Parser::PathContext* Ili2Parser::FunctionCallContext::path() {
  return getRuleContext<Ili2Parser::PathContext>(0);
}

std::vector<Ili2Parser::FunctionCallArgumentContext *> Ili2Parser::FunctionCallContext::functionCallArgument() {
  return getRuleContexts<Ili2Parser::FunctionCallArgumentContext>();
}

Ili2Parser::FunctionCallArgumentContext* Ili2Parser::FunctionCallContext::functionCallArgument(size_t i) {
  return getRuleContext<Ili2Parser::FunctionCallArgumentContext>(i);
}

std::vector<tree::TerminalNode *> Ili2Parser::FunctionCallContext::COMMA() {
  return getTokens(Ili2Parser::COMMA);
}

tree::TerminalNode* Ili2Parser::FunctionCallContext::COMMA(size_t i) {
  return getToken(Ili2Parser::COMMA, i);
}


size_t Ili2Parser::FunctionCallContext::getRuleIndex() const {
  return Ili2Parser::RuleFunctionCall;
}

antlrcpp::Any Ili2Parser::FunctionCallContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<Ili2ParserVisitor*>(visitor))
    return parserVisitor->visitFunctionCall(this);
  else
    return visitor->visitChildren(this);
}

Ili2Parser::FunctionCallContext* Ili2Parser::functionCall() {
  FunctionCallContext *_localctx = _tracker.createInstance<FunctionCallContext>(_ctx, getState());
  enterRule(_localctx, 178, Ili2Parser::RuleFunctionCall);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1440);
    dynamic_cast<FunctionCallContext *>(_localctx)->functionref = path();
    setState(1441);
    match(Ili2Parser::LPAREN);
    setState(1450);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << Ili2Parser::INTERLIS)
      | (1ULL << Ili2Parser::LPAREN)
      | (1ULL << Ili2Parser::BACKSLASH)
      | (1ULL << Ili2Parser::HASH)
      | (1ULL << Ili2Parser::GREATERGREATER)
      | (1ULL << Ili2Parser::GREATER))) != 0) || ((((_la - 82) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 82)) & ((1ULL << (Ili2Parser::PARAMETER - 82))
      | (1ULL << (Ili2Parser::UNDEFINED - 82))
      | (1ULL << (Ili2Parser::ALL - 82))
      | (1ULL << (Ili2Parser::PI - 82))
      | (1ULL << (Ili2Parser::LNBASE - 82))
      | (1ULL << (Ili2Parser::AREA - 82)))) != 0) || ((((_la - 152) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 152)) & ((1ULL << (Ili2Parser::NOT - 152))
      | (1ULL << (Ili2Parser::DEFINED - 152))
      | (1ULL << (Ili2Parser::INSPECTION - 152))
      | (1ULL << (Ili2Parser::THIS - 152))
      | (1ULL << (Ili2Parser::THISAREA - 152))
      | (1ULL << (Ili2Parser::THATAREA - 152))
      | (1ULL << (Ili2Parser::PARENT - 152))
      | (1ULL << (Ili2Parser::AGGREGATES - 152))
      | (1ULL << (Ili2Parser::STRING - 152))
      | (1ULL << (Ili2Parser::POSNUMBER - 152))
      | (1ULL << (Ili2Parser::NUMBER - 152))
      | (1ULL << (Ili2Parser::DEC - 152))
      | (1ULL << (Ili2Parser::NAME - 152)))) != 0)) {
      setState(1442);
      functionCallArgument();
      setState(1447);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == Ili2Parser::COMMA) {
        setState(1443);
        match(Ili2Parser::COMMA);
        setState(1444);
        functionCallArgument();
        setState(1449);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
    }
    setState(1452);
    match(Ili2Parser::RPAREN);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FunctionCallArgumentContext ------------------------------------------------------------------

Ili2Parser::FunctionCallArgumentContext::FunctionCallArgumentContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

Ili2Parser::ExpressionContext* Ili2Parser::FunctionCallArgumentContext::expression() {
  return getRuleContext<Ili2Parser::ExpressionContext>(0);
}

tree::TerminalNode* Ili2Parser::FunctionCallArgumentContext::ALL() {
  return getToken(Ili2Parser::ALL, 0);
}

std::vector<tree::TerminalNode *> Ili2Parser::FunctionCallArgumentContext::LPAREN() {
  return getTokens(Ili2Parser::LPAREN);
}

tree::TerminalNode* Ili2Parser::FunctionCallArgumentContext::LPAREN(size_t i) {
  return getToken(Ili2Parser::LPAREN, i);
}

std::vector<Ili2Parser::RestrictedRefContext *> Ili2Parser::FunctionCallArgumentContext::restrictedRef() {
  return getRuleContexts<Ili2Parser::RestrictedRefContext>();
}

Ili2Parser::RestrictedRefContext* Ili2Parser::FunctionCallArgumentContext::restrictedRef(size_t i) {
  return getRuleContext<Ili2Parser::RestrictedRefContext>(i);
}

std::vector<Ili2Parser::PathContext *> Ili2Parser::FunctionCallArgumentContext::path() {
  return getRuleContexts<Ili2Parser::PathContext>();
}

Ili2Parser::PathContext* Ili2Parser::FunctionCallArgumentContext::path(size_t i) {
  return getRuleContext<Ili2Parser::PathContext>(i);
}

std::vector<tree::TerminalNode *> Ili2Parser::FunctionCallArgumentContext::RPAREN() {
  return getTokens(Ili2Parser::RPAREN);
}

tree::TerminalNode* Ili2Parser::FunctionCallArgumentContext::RPAREN(size_t i) {
  return getToken(Ili2Parser::RPAREN, i);
}


size_t Ili2Parser::FunctionCallArgumentContext::getRuleIndex() const {
  return Ili2Parser::RuleFunctionCallArgument;
}

antlrcpp::Any Ili2Parser::FunctionCallArgumentContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<Ili2ParserVisitor*>(visitor))
    return parserVisitor->visitFunctionCallArgument(this);
  else
    return visitor->visitChildren(this);
}

Ili2Parser::FunctionCallArgumentContext* Ili2Parser::functionCallArgument() {
  FunctionCallArgumentContext *_localctx = _tracker.createInstance<FunctionCallArgumentContext>(_ctx, getState());
  enterRule(_localctx, 180, Ili2Parser::RuleFunctionCallArgument);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(1466);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case Ili2Parser::INTERLIS:
      case Ili2Parser::LPAREN:
      case Ili2Parser::BACKSLASH:
      case Ili2Parser::HASH:
      case Ili2Parser::GREATERGREATER:
      case Ili2Parser::GREATER:
      case Ili2Parser::PARAMETER:
      case Ili2Parser::UNDEFINED:
      case Ili2Parser::PI:
      case Ili2Parser::LNBASE:
      case Ili2Parser::AREA:
      case Ili2Parser::NOT:
      case Ili2Parser::DEFINED:
      case Ili2Parser::INSPECTION:
      case Ili2Parser::THIS:
      case Ili2Parser::THISAREA:
      case Ili2Parser::THATAREA:
      case Ili2Parser::PARENT:
      case Ili2Parser::AGGREGATES:
      case Ili2Parser::STRING:
      case Ili2Parser::POSNUMBER:
      case Ili2Parser::NUMBER:
      case Ili2Parser::DEC:
      case Ili2Parser::NAME: {
        enterOuterAlt(_localctx, 1);
        setState(1454);
        expression();
        break;
      }

      case Ili2Parser::ALL: {
        enterOuterAlt(_localctx, 2);
        setState(1455);
        match(Ili2Parser::ALL);
        setState(1463);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while (_la == Ili2Parser::INTERLIS

        || _la == Ili2Parser::LPAREN || _la == Ili2Parser::NAME) {
          setState(1461);
          _errHandler->sync(this);
          switch (_input->LA(1)) {
            case Ili2Parser::LPAREN: {
              setState(1456);
              match(Ili2Parser::LPAREN);
              setState(1457);
              restrictedRef();
              break;
            }

            case Ili2Parser::INTERLIS:
            case Ili2Parser::NAME: {
              setState(1458);
              path();
              setState(1459);
              match(Ili2Parser::RPAREN);
              break;
            }

          default:
            throw NoViableAltException(this);
          }
          setState(1465);
          _errHandler->sync(this);
          _la = _input->LA(1);
        }
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FunctionDefContext ------------------------------------------------------------------

Ili2Parser::FunctionDefContext::FunctionDefContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* Ili2Parser::FunctionDefContext::FUNCTION() {
  return getToken(Ili2Parser::FUNCTION, 0);
}

tree::TerminalNode* Ili2Parser::FunctionDefContext::LPAREN() {
  return getToken(Ili2Parser::LPAREN, 0);
}

tree::TerminalNode* Ili2Parser::FunctionDefContext::RPAREN() {
  return getToken(Ili2Parser::RPAREN, 0);
}

tree::TerminalNode* Ili2Parser::FunctionDefContext::COLON() {
  return getToken(Ili2Parser::COLON, 0);
}

std::vector<tree::TerminalNode *> Ili2Parser::FunctionDefContext::SEMI() {
  return getTokens(Ili2Parser::SEMI);
}

tree::TerminalNode* Ili2Parser::FunctionDefContext::SEMI(size_t i) {
  return getToken(Ili2Parser::SEMI, i);
}

tree::TerminalNode* Ili2Parser::FunctionDefContext::NAME() {
  return getToken(Ili2Parser::NAME, 0);
}

Ili2Parser::ArgumentTypeContext* Ili2Parser::FunctionDefContext::argumentType() {
  return getRuleContext<Ili2Parser::ArgumentTypeContext>(0);
}

std::vector<Ili2Parser::FunctionDefParamContext *> Ili2Parser::FunctionDefContext::functionDefParam() {
  return getRuleContexts<Ili2Parser::FunctionDefParamContext>();
}

Ili2Parser::FunctionDefParamContext* Ili2Parser::FunctionDefContext::functionDefParam(size_t i) {
  return getRuleContext<Ili2Parser::FunctionDefParamContext>(i);
}

tree::TerminalNode* Ili2Parser::FunctionDefContext::EXPLANATION() {
  return getToken(Ili2Parser::EXPLANATION, 0);
}


size_t Ili2Parser::FunctionDefContext::getRuleIndex() const {
  return Ili2Parser::RuleFunctionDef;
}

antlrcpp::Any Ili2Parser::FunctionDefContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<Ili2ParserVisitor*>(visitor))
    return parserVisitor->visitFunctionDef(this);
  else
    return visitor->visitChildren(this);
}

Ili2Parser::FunctionDefContext* Ili2Parser::functionDef() {
  FunctionDefContext *_localctx = _tracker.createInstance<FunctionDefContext>(_ctx, getState());
  enterRule(_localctx, 182, Ili2Parser::RuleFunctionDef);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1468);
    match(Ili2Parser::FUNCTION);
    setState(1469);
    dynamic_cast<FunctionDefContext *>(_localctx)->functioname = match(Ili2Parser::NAME);
    setState(1470);
    match(Ili2Parser::LPAREN);
    setState(1479);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == Ili2Parser::NAME) {
      setState(1471);
      functionDefParam();
      setState(1476);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == Ili2Parser::SEMI) {
        setState(1472);
        match(Ili2Parser::SEMI);
        setState(1473);
        functionDefParam();
        setState(1478);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
    }
    setState(1481);
    match(Ili2Parser::RPAREN);
    setState(1482);
    match(Ili2Parser::COLON);
    setState(1483);
    dynamic_cast<FunctionDefContext *>(_localctx)->result = argumentType();
    setState(1485);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == Ili2Parser::EXPLANATION) {
      setState(1484);
      match(Ili2Parser::EXPLANATION);
    }
    setState(1487);
    match(Ili2Parser::SEMI);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FunctionDefParamContext ------------------------------------------------------------------

Ili2Parser::FunctionDefParamContext::FunctionDefParamContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* Ili2Parser::FunctionDefParamContext::COLON() {
  return getToken(Ili2Parser::COLON, 0);
}

Ili2Parser::ArgumentTypeContext* Ili2Parser::FunctionDefParamContext::argumentType() {
  return getRuleContext<Ili2Parser::ArgumentTypeContext>(0);
}

tree::TerminalNode* Ili2Parser::FunctionDefParamContext::NAME() {
  return getToken(Ili2Parser::NAME, 0);
}


size_t Ili2Parser::FunctionDefParamContext::getRuleIndex() const {
  return Ili2Parser::RuleFunctionDefParam;
}

antlrcpp::Any Ili2Parser::FunctionDefParamContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<Ili2ParserVisitor*>(visitor))
    return parserVisitor->visitFunctionDefParam(this);
  else
    return visitor->visitChildren(this);
}

Ili2Parser::FunctionDefParamContext* Ili2Parser::functionDefParam() {
  FunctionDefParamContext *_localctx = _tracker.createInstance<FunctionDefParamContext>(_ctx, getState());
  enterRule(_localctx, 184, Ili2Parser::RuleFunctionDefParam);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1489);
    dynamic_cast<FunctionDefParamContext *>(_localctx)->argumentname = match(Ili2Parser::NAME);
    setState(1490);
    match(Ili2Parser::COLON);
    setState(1491);
    argumentType();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ArgumentTypeContext ------------------------------------------------------------------

Ili2Parser::ArgumentTypeContext::ArgumentTypeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

Ili2Parser::AttrTypeDefContext* Ili2Parser::ArgumentTypeContext::attrTypeDef() {
  return getRuleContext<Ili2Parser::AttrTypeDefContext>(0);
}

tree::TerminalNode* Ili2Parser::ArgumentTypeContext::OF() {
  return getToken(Ili2Parser::OF, 0);
}

tree::TerminalNode* Ili2Parser::ArgumentTypeContext::OBJECT() {
  return getToken(Ili2Parser::OBJECT, 0);
}

tree::TerminalNode* Ili2Parser::ArgumentTypeContext::OBJECTS() {
  return getToken(Ili2Parser::OBJECTS, 0);
}

Ili2Parser::RestrictedRefContext* Ili2Parser::ArgumentTypeContext::restrictedRef() {
  return getRuleContext<Ili2Parser::RestrictedRefContext>(0);
}

Ili2Parser::PathContext* Ili2Parser::ArgumentTypeContext::path() {
  return getRuleContext<Ili2Parser::PathContext>(0);
}

tree::TerminalNode* Ili2Parser::ArgumentTypeContext::ENUMVAL() {
  return getToken(Ili2Parser::ENUMVAL, 0);
}

tree::TerminalNode* Ili2Parser::ArgumentTypeContext::ENUMTREEVAL() {
  return getToken(Ili2Parser::ENUMTREEVAL, 0);
}


size_t Ili2Parser::ArgumentTypeContext::getRuleIndex() const {
  return Ili2Parser::RuleArgumentType;
}

antlrcpp::Any Ili2Parser::ArgumentTypeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<Ili2ParserVisitor*>(visitor))
    return parserVisitor->visitArgumentType(this);
  else
    return visitor->visitChildren(this);
}

Ili2Parser::ArgumentTypeContext* Ili2Parser::argumentType() {
  ArgumentTypeContext *_localctx = _tracker.createInstance<ArgumentTypeContext>(_ctx, getState());
  enterRule(_localctx, 186, Ili2Parser::RuleArgumentType);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(1502);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 196, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(1493);
      attrTypeDef();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(1494);
      _la = _input->LA(1);
      if (!(_la == Ili2Parser::OBJECTS

      || _la == Ili2Parser::OBJECT)) {
      _errHandler->recoverInline(this);
      }
      else {
        _errHandler->reportMatch(this);
        consume();
      }
      setState(1495);
      match(Ili2Parser::OF);
      setState(1498);
      _errHandler->sync(this);
      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 195, _ctx)) {
      case 1: {
        setState(1496);
        restrictedRef();
        break;
      }

      case 2: {
        setState(1497);
        dynamic_cast<ArgumentTypeContext *>(_localctx)->viewref = path();
        break;
      }

      }
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(1500);
      match(Ili2Parser::ENUMVAL);
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(1501);
      match(Ili2Parser::ENUMTREEVAL);
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ViewDefContext ------------------------------------------------------------------

Ili2Parser::ViewDefContext::ViewDefContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* Ili2Parser::ViewDefContext::VIEW() {
  return getToken(Ili2Parser::VIEW, 0);
}

tree::TerminalNode* Ili2Parser::ViewDefContext::EQUAL() {
  return getToken(Ili2Parser::EQUAL, 0);
}

tree::TerminalNode* Ili2Parser::ViewDefContext::END() {
  return getToken(Ili2Parser::END, 0);
}

tree::TerminalNode* Ili2Parser::ViewDefContext::SEMI() {
  return getToken(Ili2Parser::SEMI, 0);
}

std::vector<tree::TerminalNode *> Ili2Parser::ViewDefContext::NAME() {
  return getTokens(Ili2Parser::NAME);
}

tree::TerminalNode* Ili2Parser::ViewDefContext::NAME(size_t i) {
  return getToken(Ili2Parser::NAME, i);
}

Ili2Parser::FormationDefContext* Ili2Parser::ViewDefContext::formationDef() {
  return getRuleContext<Ili2Parser::FormationDefContext>(0);
}

tree::TerminalNode* Ili2Parser::ViewDefContext::EXTENDS() {
  return getToken(Ili2Parser::EXTENDS, 0);
}

Ili2Parser::PropertiesContext* Ili2Parser::ViewDefContext::properties() {
  return getRuleContext<Ili2Parser::PropertiesContext>(0);
}

Ili2Parser::PathContext* Ili2Parser::ViewDefContext::path() {
  return getRuleContext<Ili2Parser::PathContext>(0);
}

std::vector<Ili2Parser::BaseExtensionDefContext *> Ili2Parser::ViewDefContext::baseExtensionDef() {
  return getRuleContexts<Ili2Parser::BaseExtensionDefContext>();
}

Ili2Parser::BaseExtensionDefContext* Ili2Parser::ViewDefContext::baseExtensionDef(size_t i) {
  return getRuleContext<Ili2Parser::BaseExtensionDefContext>(i);
}

std::vector<Ili2Parser::SelectionContext *> Ili2Parser::ViewDefContext::selection() {
  return getRuleContexts<Ili2Parser::SelectionContext>();
}

Ili2Parser::SelectionContext* Ili2Parser::ViewDefContext::selection(size_t i) {
  return getRuleContext<Ili2Parser::SelectionContext>(i);
}

Ili2Parser::ViewAttributesContext* Ili2Parser::ViewDefContext::viewAttributes() {
  return getRuleContext<Ili2Parser::ViewAttributesContext>(0);
}

std::vector<Ili2Parser::ConstraintDefContext *> Ili2Parser::ViewDefContext::constraintDef() {
  return getRuleContexts<Ili2Parser::ConstraintDefContext>();
}

Ili2Parser::ConstraintDefContext* Ili2Parser::ViewDefContext::constraintDef(size_t i) {
  return getRuleContext<Ili2Parser::ConstraintDefContext>(i);
}


size_t Ili2Parser::ViewDefContext::getRuleIndex() const {
  return Ili2Parser::RuleViewDef;
}

antlrcpp::Any Ili2Parser::ViewDefContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<Ili2ParserVisitor*>(visitor))
    return parserVisitor->visitViewDef(this);
  else
    return visitor->visitChildren(this);
}

Ili2Parser::ViewDefContext* Ili2Parser::viewDef() {
  ViewDefContext *_localctx = _tracker.createInstance<ViewDefContext>(_ctx, getState());
  enterRule(_localctx, 188, Ili2Parser::RuleViewDef);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1504);
    match(Ili2Parser::VIEW);
    setState(1505);
    dynamic_cast<ViewDefContext *>(_localctx)->viewname1 = match(Ili2Parser::NAME);
    setState(1507);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == Ili2Parser::LPAREN) {
      setState(1506);
      properties();
    }
    setState(1512);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case Ili2Parser::AREA:
      case Ili2Parser::PROJECTION:
      case Ili2Parser::JOIN:
      case Ili2Parser::UNION:
      case Ili2Parser::AGGREGATION: {
        setState(1509);
        formationDef();
        break;
      }

      case Ili2Parser::EXTENDS: {
        setState(1510);
        match(Ili2Parser::EXTENDS);
        setState(1511);
        dynamic_cast<ViewDefContext *>(_localctx)->viewref = path();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    setState(1517);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == Ili2Parser::BASE) {
      setState(1514);
      baseExtensionDef();
      setState(1519);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(1523);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == Ili2Parser::WHERE) {
      setState(1520);
      selection();
      setState(1525);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(1526);
    match(Ili2Parser::EQUAL);
    setState(1528);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 201, _ctx)) {
    case 1: {
      setState(1527);
      viewAttributes();
      break;
    }

    }
    setState(1533);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (((((_la - 83) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 83)) & ((1ULL << (Ili2Parser::MANDATORY - 83))
      | (1ULL << (Ili2Parser::CONSTRAINT - 83))
      | (1ULL << (Ili2Parser::EXISTENCE - 83)))) != 0) || _la == Ili2Parser::UNIQUE

    || _la == Ili2Parser::SET) {
      setState(1530);
      constraintDef();
      setState(1535);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(1536);
    match(Ili2Parser::END);
    setState(1537);
    dynamic_cast<ViewDefContext *>(_localctx)->viewname2 = match(Ili2Parser::NAME);
    setState(1538);
    match(Ili2Parser::SEMI);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FormationDefContext ------------------------------------------------------------------

Ili2Parser::FormationDefContext::FormationDefContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* Ili2Parser::FormationDefContext::SEMI() {
  return getToken(Ili2Parser::SEMI, 0);
}

Ili2Parser::ProjectionContext* Ili2Parser::FormationDefContext::projection() {
  return getRuleContext<Ili2Parser::ProjectionContext>(0);
}

Ili2Parser::JoinContext* Ili2Parser::FormationDefContext::join() {
  return getRuleContext<Ili2Parser::JoinContext>(0);
}

Ili2Parser::IliunionContext* Ili2Parser::FormationDefContext::iliunion() {
  return getRuleContext<Ili2Parser::IliunionContext>(0);
}

Ili2Parser::AggregationContext* Ili2Parser::FormationDefContext::aggregation() {
  return getRuleContext<Ili2Parser::AggregationContext>(0);
}

Ili2Parser::InspectionContext* Ili2Parser::FormationDefContext::inspection() {
  return getRuleContext<Ili2Parser::InspectionContext>(0);
}


size_t Ili2Parser::FormationDefContext::getRuleIndex() const {
  return Ili2Parser::RuleFormationDef;
}

antlrcpp::Any Ili2Parser::FormationDefContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<Ili2ParserVisitor*>(visitor))
    return parserVisitor->visitFormationDef(this);
  else
    return visitor->visitChildren(this);
}

Ili2Parser::FormationDefContext* Ili2Parser::formationDef() {
  FormationDefContext *_localctx = _tracker.createInstance<FormationDefContext>(_ctx, getState());
  enterRule(_localctx, 190, Ili2Parser::RuleFormationDef);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1545);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case Ili2Parser::PROJECTION: {
        setState(1540);
        projection();
        break;
      }

      case Ili2Parser::JOIN: {
        setState(1541);
        join();
        break;
      }

      case Ili2Parser::UNION: {
        setState(1542);
        iliunion();
        break;
      }

      case Ili2Parser::AGGREGATION: {
        setState(1543);
        aggregation();
        break;
      }

      case Ili2Parser::AREA: {
        setState(1544);
        inspection();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    setState(1547);
    match(Ili2Parser::SEMI);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ProjectionContext ------------------------------------------------------------------

Ili2Parser::ProjectionContext::ProjectionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* Ili2Parser::ProjectionContext::PROJECTION() {
  return getToken(Ili2Parser::PROJECTION, 0);
}

tree::TerminalNode* Ili2Parser::ProjectionContext::OF() {
  return getToken(Ili2Parser::OF, 0);
}

Ili2Parser::RenamedViewableRefContext* Ili2Parser::ProjectionContext::renamedViewableRef() {
  return getRuleContext<Ili2Parser::RenamedViewableRefContext>(0);
}


size_t Ili2Parser::ProjectionContext::getRuleIndex() const {
  return Ili2Parser::RuleProjection;
}

antlrcpp::Any Ili2Parser::ProjectionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<Ili2ParserVisitor*>(visitor))
    return parserVisitor->visitProjection(this);
  else
    return visitor->visitChildren(this);
}

Ili2Parser::ProjectionContext* Ili2Parser::projection() {
  ProjectionContext *_localctx = _tracker.createInstance<ProjectionContext>(_ctx, getState());
  enterRule(_localctx, 192, Ili2Parser::RuleProjection);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1549);
    match(Ili2Parser::PROJECTION);
    setState(1550);
    match(Ili2Parser::OF);
    setState(1551);
    renamedViewableRef();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- JoinContext ------------------------------------------------------------------

Ili2Parser::JoinContext::JoinContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* Ili2Parser::JoinContext::JOIN() {
  return getToken(Ili2Parser::JOIN, 0);
}

tree::TerminalNode* Ili2Parser::JoinContext::OF() {
  return getToken(Ili2Parser::OF, 0);
}

std::vector<Ili2Parser::RenamedViewableRefContext *> Ili2Parser::JoinContext::renamedViewableRef() {
  return getRuleContexts<Ili2Parser::RenamedViewableRefContext>();
}

Ili2Parser::RenamedViewableRefContext* Ili2Parser::JoinContext::renamedViewableRef(size_t i) {
  return getRuleContext<Ili2Parser::RenamedViewableRefContext>(i);
}

std::vector<tree::TerminalNode *> Ili2Parser::JoinContext::COMMA() {
  return getTokens(Ili2Parser::COMMA);
}

tree::TerminalNode* Ili2Parser::JoinContext::COMMA(size_t i) {
  return getToken(Ili2Parser::COMMA, i);
}

std::vector<tree::TerminalNode *> Ili2Parser::JoinContext::LPAREN() {
  return getTokens(Ili2Parser::LPAREN);
}

tree::TerminalNode* Ili2Parser::JoinContext::LPAREN(size_t i) {
  return getToken(Ili2Parser::LPAREN, i);
}

std::vector<tree::TerminalNode *> Ili2Parser::JoinContext::OR() {
  return getTokens(Ili2Parser::OR);
}

tree::TerminalNode* Ili2Parser::JoinContext::OR(size_t i) {
  return getToken(Ili2Parser::OR, i);
}

std::vector<tree::TerminalNode *> Ili2Parser::JoinContext::ILINULL() {
  return getTokens(Ili2Parser::ILINULL);
}

tree::TerminalNode* Ili2Parser::JoinContext::ILINULL(size_t i) {
  return getToken(Ili2Parser::ILINULL, i);
}

std::vector<tree::TerminalNode *> Ili2Parser::JoinContext::RPAREN() {
  return getTokens(Ili2Parser::RPAREN);
}

tree::TerminalNode* Ili2Parser::JoinContext::RPAREN(size_t i) {
  return getToken(Ili2Parser::RPAREN, i);
}


size_t Ili2Parser::JoinContext::getRuleIndex() const {
  return Ili2Parser::RuleJoin;
}

antlrcpp::Any Ili2Parser::JoinContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<Ili2ParserVisitor*>(visitor))
    return parserVisitor->visitJoin(this);
  else
    return visitor->visitChildren(this);
}

Ili2Parser::JoinContext* Ili2Parser::join() {
  JoinContext *_localctx = _tracker.createInstance<JoinContext>(_ctx, getState());
  enterRule(_localctx, 194, Ili2Parser::RuleJoin);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1553);
    match(Ili2Parser::JOIN);
    setState(1554);
    match(Ili2Parser::OF);
    setState(1555);
    renamedViewableRef();
    setState(1564); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(1556);
      match(Ili2Parser::COMMA);
      setState(1557);
      renamedViewableRef();
      setState(1562);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == Ili2Parser::LPAREN) {
        setState(1558);
        match(Ili2Parser::LPAREN);
        setState(1559);
        match(Ili2Parser::OR);
        setState(1560);
        match(Ili2Parser::ILINULL);
        setState(1561);
        match(Ili2Parser::RPAREN);
      }
      setState(1566); 
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while (_la == Ili2Parser::COMMA);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- IliunionContext ------------------------------------------------------------------

Ili2Parser::IliunionContext::IliunionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* Ili2Parser::IliunionContext::UNION() {
  return getToken(Ili2Parser::UNION, 0);
}

tree::TerminalNode* Ili2Parser::IliunionContext::OF() {
  return getToken(Ili2Parser::OF, 0);
}

std::vector<Ili2Parser::RenamedViewableRefContext *> Ili2Parser::IliunionContext::renamedViewableRef() {
  return getRuleContexts<Ili2Parser::RenamedViewableRefContext>();
}

Ili2Parser::RenamedViewableRefContext* Ili2Parser::IliunionContext::renamedViewableRef(size_t i) {
  return getRuleContext<Ili2Parser::RenamedViewableRefContext>(i);
}

std::vector<tree::TerminalNode *> Ili2Parser::IliunionContext::COMMA() {
  return getTokens(Ili2Parser::COMMA);
}

tree::TerminalNode* Ili2Parser::IliunionContext::COMMA(size_t i) {
  return getToken(Ili2Parser::COMMA, i);
}


size_t Ili2Parser::IliunionContext::getRuleIndex() const {
  return Ili2Parser::RuleIliunion;
}

antlrcpp::Any Ili2Parser::IliunionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<Ili2ParserVisitor*>(visitor))
    return parserVisitor->visitIliunion(this);
  else
    return visitor->visitChildren(this);
}

Ili2Parser::IliunionContext* Ili2Parser::iliunion() {
  IliunionContext *_localctx = _tracker.createInstance<IliunionContext>(_ctx, getState());
  enterRule(_localctx, 196, Ili2Parser::RuleIliunion);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1568);
    match(Ili2Parser::UNION);
    setState(1569);
    match(Ili2Parser::OF);
    setState(1570);
    renamedViewableRef();
    setState(1575);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == Ili2Parser::COMMA) {
      setState(1571);
      match(Ili2Parser::COMMA);
      setState(1572);
      renamedViewableRef();
      setState(1577);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- AggregationContext ------------------------------------------------------------------

Ili2Parser::AggregationContext::AggregationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* Ili2Parser::AggregationContext::AGGREGATION() {
  return getToken(Ili2Parser::AGGREGATION, 0);
}

tree::TerminalNode* Ili2Parser::AggregationContext::OF() {
  return getToken(Ili2Parser::OF, 0);
}

Ili2Parser::RenamedViewableRefContext* Ili2Parser::AggregationContext::renamedViewableRef() {
  return getRuleContext<Ili2Parser::RenamedViewableRefContext>(0);
}

tree::TerminalNode* Ili2Parser::AggregationContext::ALL() {
  return getToken(Ili2Parser::ALL, 0);
}

tree::TerminalNode* Ili2Parser::AggregationContext::EQUAL() {
  return getToken(Ili2Parser::EQUAL, 0);
}

tree::TerminalNode* Ili2Parser::AggregationContext::LPAREN() {
  return getToken(Ili2Parser::LPAREN, 0);
}

Ili2Parser::UniqueElContext* Ili2Parser::AggregationContext::uniqueEl() {
  return getRuleContext<Ili2Parser::UniqueElContext>(0);
}

tree::TerminalNode* Ili2Parser::AggregationContext::RPAREN() {
  return getToken(Ili2Parser::RPAREN, 0);
}


size_t Ili2Parser::AggregationContext::getRuleIndex() const {
  return Ili2Parser::RuleAggregation;
}

antlrcpp::Any Ili2Parser::AggregationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<Ili2ParserVisitor*>(visitor))
    return parserVisitor->visitAggregation(this);
  else
    return visitor->visitChildren(this);
}

Ili2Parser::AggregationContext* Ili2Parser::aggregation() {
  AggregationContext *_localctx = _tracker.createInstance<AggregationContext>(_ctx, getState());
  enterRule(_localctx, 198, Ili2Parser::RuleAggregation);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1578);
    match(Ili2Parser::AGGREGATION);
    setState(1579);
    match(Ili2Parser::OF);
    setState(1580);
    renamedViewableRef();
    setState(1587);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case Ili2Parser::ALL: {
        setState(1581);
        match(Ili2Parser::ALL);
        break;
      }

      case Ili2Parser::EQUAL: {
        setState(1582);
        match(Ili2Parser::EQUAL);
        setState(1583);
        match(Ili2Parser::LPAREN);
        setState(1584);
        uniqueEl();
        setState(1585);
        match(Ili2Parser::RPAREN);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- InspectionContext ------------------------------------------------------------------

Ili2Parser::InspectionContext::InspectionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* Ili2Parser::InspectionContext::AREA() {
  return getToken(Ili2Parser::AREA, 0);
}

tree::TerminalNode* Ili2Parser::InspectionContext::INSPECTION() {
  return getToken(Ili2Parser::INSPECTION, 0);
}

tree::TerminalNode* Ili2Parser::InspectionContext::OF() {
  return getToken(Ili2Parser::OF, 0);
}

Ili2Parser::RenamedViewableRefContext* Ili2Parser::InspectionContext::renamedViewableRef() {
  return getRuleContext<Ili2Parser::RenamedViewableRefContext>(0);
}

std::vector<tree::TerminalNode *> Ili2Parser::InspectionContext::RARROW() {
  return getTokens(Ili2Parser::RARROW);
}

tree::TerminalNode* Ili2Parser::InspectionContext::RARROW(size_t i) {
  return getToken(Ili2Parser::RARROW, i);
}

std::vector<tree::TerminalNode *> Ili2Parser::InspectionContext::NAME() {
  return getTokens(Ili2Parser::NAME);
}

tree::TerminalNode* Ili2Parser::InspectionContext::NAME(size_t i) {
  return getToken(Ili2Parser::NAME, i);
}


size_t Ili2Parser::InspectionContext::getRuleIndex() const {
  return Ili2Parser::RuleInspection;
}

antlrcpp::Any Ili2Parser::InspectionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<Ili2ParserVisitor*>(visitor))
    return parserVisitor->visitInspection(this);
  else
    return visitor->visitChildren(this);
}

Ili2Parser::InspectionContext* Ili2Parser::inspection() {
  InspectionContext *_localctx = _tracker.createInstance<InspectionContext>(_ctx, getState());
  enterRule(_localctx, 200, Ili2Parser::RuleInspection);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(1589);
    match(Ili2Parser::AREA);
    setState(1590);
    match(Ili2Parser::INSPECTION);
    setState(1591);
    match(Ili2Parser::OF);
    setState(1592);
    renamedViewableRef();
    setState(1593);
    match(Ili2Parser::RARROW);
    setState(1594);
    dynamic_cast<InspectionContext *>(_localctx)->structureorlineattributename = match(Ili2Parser::NAME);
    setState(1599);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 208, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(1595);
        match(Ili2Parser::RARROW);
        setState(1596);
        dynamic_cast<InspectionContext *>(_localctx)->structureorlineattributename = match(Ili2Parser::NAME); 
      }
      setState(1601);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 208, _ctx);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- RenamedViewableRefContext ------------------------------------------------------------------

Ili2Parser::RenamedViewableRefContext::RenamedViewableRefContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

Ili2Parser::PathContext* Ili2Parser::RenamedViewableRefContext::path() {
  return getRuleContext<Ili2Parser::PathContext>(0);
}

tree::TerminalNode* Ili2Parser::RenamedViewableRefContext::TILDE() {
  return getToken(Ili2Parser::TILDE, 0);
}

tree::TerminalNode* Ili2Parser::RenamedViewableRefContext::NAME() {
  return getToken(Ili2Parser::NAME, 0);
}


size_t Ili2Parser::RenamedViewableRefContext::getRuleIndex() const {
  return Ili2Parser::RuleRenamedViewableRef;
}

antlrcpp::Any Ili2Parser::RenamedViewableRefContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<Ili2ParserVisitor*>(visitor))
    return parserVisitor->visitRenamedViewableRef(this);
  else
    return visitor->visitChildren(this);
}

Ili2Parser::RenamedViewableRefContext* Ili2Parser::renamedViewableRef() {
  RenamedViewableRefContext *_localctx = _tracker.createInstance<RenamedViewableRefContext>(_ctx, getState());
  enterRule(_localctx, 202, Ili2Parser::RuleRenamedViewableRef);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1604);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 209, _ctx)) {
    case 1: {
      setState(1602);
      dynamic_cast<RenamedViewableRefContext *>(_localctx)->basename = match(Ili2Parser::NAME);
      setState(1603);
      match(Ili2Parser::TILDE);
      break;
    }

    }
    setState(1606);
    path();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- BaseExtensionDefContext ------------------------------------------------------------------

Ili2Parser::BaseExtensionDefContext::BaseExtensionDefContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* Ili2Parser::BaseExtensionDefContext::BASE() {
  return getToken(Ili2Parser::BASE, 0);
}

tree::TerminalNode* Ili2Parser::BaseExtensionDefContext::EXTENDED() {
  return getToken(Ili2Parser::EXTENDED, 0);
}

tree::TerminalNode* Ili2Parser::BaseExtensionDefContext::BY() {
  return getToken(Ili2Parser::BY, 0);
}

std::vector<Ili2Parser::RenamedViewableRefContext *> Ili2Parser::BaseExtensionDefContext::renamedViewableRef() {
  return getRuleContexts<Ili2Parser::RenamedViewableRefContext>();
}

Ili2Parser::RenamedViewableRefContext* Ili2Parser::BaseExtensionDefContext::renamedViewableRef(size_t i) {
  return getRuleContext<Ili2Parser::RenamedViewableRefContext>(i);
}

tree::TerminalNode* Ili2Parser::BaseExtensionDefContext::NAME() {
  return getToken(Ili2Parser::NAME, 0);
}

std::vector<tree::TerminalNode *> Ili2Parser::BaseExtensionDefContext::COMMA() {
  return getTokens(Ili2Parser::COMMA);
}

tree::TerminalNode* Ili2Parser::BaseExtensionDefContext::COMMA(size_t i) {
  return getToken(Ili2Parser::COMMA, i);
}


size_t Ili2Parser::BaseExtensionDefContext::getRuleIndex() const {
  return Ili2Parser::RuleBaseExtensionDef;
}

antlrcpp::Any Ili2Parser::BaseExtensionDefContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<Ili2ParserVisitor*>(visitor))
    return parserVisitor->visitBaseExtensionDef(this);
  else
    return visitor->visitChildren(this);
}

Ili2Parser::BaseExtensionDefContext* Ili2Parser::baseExtensionDef() {
  BaseExtensionDefContext *_localctx = _tracker.createInstance<BaseExtensionDefContext>(_ctx, getState());
  enterRule(_localctx, 204, Ili2Parser::RuleBaseExtensionDef);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1608);
    match(Ili2Parser::BASE);
    setState(1609);
    dynamic_cast<BaseExtensionDefContext *>(_localctx)->basename = match(Ili2Parser::NAME);
    setState(1610);
    match(Ili2Parser::EXTENDED);
    setState(1611);
    match(Ili2Parser::BY);
    setState(1612);
    renamedViewableRef();
    setState(1617);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == Ili2Parser::COMMA) {
      setState(1613);
      match(Ili2Parser::COMMA);
      setState(1614);
      renamedViewableRef();
      setState(1619);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- SelectionContext ------------------------------------------------------------------

Ili2Parser::SelectionContext::SelectionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* Ili2Parser::SelectionContext::WHERE() {
  return getToken(Ili2Parser::WHERE, 0);
}

Ili2Parser::ExpressionContext* Ili2Parser::SelectionContext::expression() {
  return getRuleContext<Ili2Parser::ExpressionContext>(0);
}

tree::TerminalNode* Ili2Parser::SelectionContext::SEMI() {
  return getToken(Ili2Parser::SEMI, 0);
}


size_t Ili2Parser::SelectionContext::getRuleIndex() const {
  return Ili2Parser::RuleSelection;
}

antlrcpp::Any Ili2Parser::SelectionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<Ili2ParserVisitor*>(visitor))
    return parserVisitor->visitSelection(this);
  else
    return visitor->visitChildren(this);
}

Ili2Parser::SelectionContext* Ili2Parser::selection() {
  SelectionContext *_localctx = _tracker.createInstance<SelectionContext>(_ctx, getState());
  enterRule(_localctx, 206, Ili2Parser::RuleSelection);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1620);
    match(Ili2Parser::WHERE);
    setState(1621);
    expression();
    setState(1622);
    match(Ili2Parser::SEMI);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ViewAttributesContext ------------------------------------------------------------------

Ili2Parser::ViewAttributesContext::ViewAttributesContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* Ili2Parser::ViewAttributesContext::ATTRIBUTE() {
  return getToken(Ili2Parser::ATTRIBUTE, 0);
}

std::vector<tree::TerminalNode *> Ili2Parser::ViewAttributesContext::ALL() {
  return getTokens(Ili2Parser::ALL);
}

tree::TerminalNode* Ili2Parser::ViewAttributesContext::ALL(size_t i) {
  return getToken(Ili2Parser::ALL, i);
}

std::vector<tree::TerminalNode *> Ili2Parser::ViewAttributesContext::OF() {
  return getTokens(Ili2Parser::OF);
}

tree::TerminalNode* Ili2Parser::ViewAttributesContext::OF(size_t i) {
  return getToken(Ili2Parser::OF, i);
}

std::vector<tree::TerminalNode *> Ili2Parser::ViewAttributesContext::SEMI() {
  return getTokens(Ili2Parser::SEMI);
}

tree::TerminalNode* Ili2Parser::ViewAttributesContext::SEMI(size_t i) {
  return getToken(Ili2Parser::SEMI, i);
}

std::vector<Ili2Parser::AttributeDefContext *> Ili2Parser::ViewAttributesContext::attributeDef() {
  return getRuleContexts<Ili2Parser::AttributeDefContext>();
}

Ili2Parser::AttributeDefContext* Ili2Parser::ViewAttributesContext::attributeDef(size_t i) {
  return getRuleContext<Ili2Parser::AttributeDefContext>(i);
}

std::vector<tree::TerminalNode *> Ili2Parser::ViewAttributesContext::COLONEQUAL() {
  return getTokens(Ili2Parser::COLONEQUAL);
}

tree::TerminalNode* Ili2Parser::ViewAttributesContext::COLONEQUAL(size_t i) {
  return getToken(Ili2Parser::COLONEQUAL, i);
}

std::vector<Ili2Parser::FactorContext *> Ili2Parser::ViewAttributesContext::factor() {
  return getRuleContexts<Ili2Parser::FactorContext>();
}

Ili2Parser::FactorContext* Ili2Parser::ViewAttributesContext::factor(size_t i) {
  return getRuleContext<Ili2Parser::FactorContext>(i);
}

std::vector<tree::TerminalNode *> Ili2Parser::ViewAttributesContext::NAME() {
  return getTokens(Ili2Parser::NAME);
}

tree::TerminalNode* Ili2Parser::ViewAttributesContext::NAME(size_t i) {
  return getToken(Ili2Parser::NAME, i);
}

std::vector<Ili2Parser::PropertiesContext *> Ili2Parser::ViewAttributesContext::properties() {
  return getRuleContexts<Ili2Parser::PropertiesContext>();
}

Ili2Parser::PropertiesContext* Ili2Parser::ViewAttributesContext::properties(size_t i) {
  return getRuleContext<Ili2Parser::PropertiesContext>(i);
}


size_t Ili2Parser::ViewAttributesContext::getRuleIndex() const {
  return Ili2Parser::RuleViewAttributes;
}

antlrcpp::Any Ili2Parser::ViewAttributesContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<Ili2ParserVisitor*>(visitor))
    return parserVisitor->visitViewAttributes(this);
  else
    return visitor->visitChildren(this);
}

Ili2Parser::ViewAttributesContext* Ili2Parser::viewAttributes() {
  ViewAttributesContext *_localctx = _tracker.createInstance<ViewAttributesContext>(_ctx, getState());
  enterRule(_localctx, 208, Ili2Parser::RuleViewAttributes);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1625);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == Ili2Parser::ATTRIBUTE) {
      setState(1624);
      match(Ili2Parser::ATTRIBUTE);
    }
    setState(1642);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == Ili2Parser::CONTINUOUS

    || _la == Ili2Parser::SUBDIVISION || _la == Ili2Parser::ALL || _la == Ili2Parser::NAME) {
      setState(1640);
      _errHandler->sync(this);
      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 213, _ctx)) {
      case 1: {
        setState(1627);
        match(Ili2Parser::ALL);
        setState(1628);
        match(Ili2Parser::OF);
        setState(1629);
        dynamic_cast<ViewAttributesContext *>(_localctx)->basename = match(Ili2Parser::NAME);
        setState(1630);
        match(Ili2Parser::SEMI);
        break;
      }

      case 2: {
        setState(1631);
        attributeDef();
        break;
      }

      case 3: {
        setState(1632);
        dynamic_cast<ViewAttributesContext *>(_localctx)->attributename = match(Ili2Parser::NAME);
        setState(1634);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == Ili2Parser::LPAREN) {
          setState(1633);
          properties();
        }
        setState(1636);
        match(Ili2Parser::COLONEQUAL);
        setState(1637);
        factor();
        setState(1638);
        match(Ili2Parser::SEMI);
        break;
      }

      }
      setState(1644);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- GraphicDefContext ------------------------------------------------------------------

Ili2Parser::GraphicDefContext::GraphicDefContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* Ili2Parser::GraphicDefContext::GRAPHIC() {
  return getToken(Ili2Parser::GRAPHIC, 0);
}

tree::TerminalNode* Ili2Parser::GraphicDefContext::EQUAL() {
  return getToken(Ili2Parser::EQUAL, 0);
}

tree::TerminalNode* Ili2Parser::GraphicDefContext::END() {
  return getToken(Ili2Parser::END, 0);
}

tree::TerminalNode* Ili2Parser::GraphicDefContext::SEMI() {
  return getToken(Ili2Parser::SEMI, 0);
}

std::vector<tree::TerminalNode *> Ili2Parser::GraphicDefContext::NAME() {
  return getTokens(Ili2Parser::NAME);
}

tree::TerminalNode* Ili2Parser::GraphicDefContext::NAME(size_t i) {
  return getToken(Ili2Parser::NAME, i);
}

Ili2Parser::PropertiesContext* Ili2Parser::GraphicDefContext::properties() {
  return getRuleContext<Ili2Parser::PropertiesContext>(0);
}

tree::TerminalNode* Ili2Parser::GraphicDefContext::EXTENDS() {
  return getToken(Ili2Parser::EXTENDS, 0);
}

std::vector<Ili2Parser::PathContext *> Ili2Parser::GraphicDefContext::path() {
  return getRuleContexts<Ili2Parser::PathContext>();
}

Ili2Parser::PathContext* Ili2Parser::GraphicDefContext::path(size_t i) {
  return getRuleContext<Ili2Parser::PathContext>(i);
}

tree::TerminalNode* Ili2Parser::GraphicDefContext::BASED() {
  return getToken(Ili2Parser::BASED, 0);
}

tree::TerminalNode* Ili2Parser::GraphicDefContext::ON() {
  return getToken(Ili2Parser::ON, 0);
}

std::vector<Ili2Parser::SelectionContext *> Ili2Parser::GraphicDefContext::selection() {
  return getRuleContexts<Ili2Parser::SelectionContext>();
}

Ili2Parser::SelectionContext* Ili2Parser::GraphicDefContext::selection(size_t i) {
  return getRuleContext<Ili2Parser::SelectionContext>(i);
}

std::vector<Ili2Parser::DrawingRuleContext *> Ili2Parser::GraphicDefContext::drawingRule() {
  return getRuleContexts<Ili2Parser::DrawingRuleContext>();
}

Ili2Parser::DrawingRuleContext* Ili2Parser::GraphicDefContext::drawingRule(size_t i) {
  return getRuleContext<Ili2Parser::DrawingRuleContext>(i);
}


size_t Ili2Parser::GraphicDefContext::getRuleIndex() const {
  return Ili2Parser::RuleGraphicDef;
}

antlrcpp::Any Ili2Parser::GraphicDefContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<Ili2ParserVisitor*>(visitor))
    return parserVisitor->visitGraphicDef(this);
  else
    return visitor->visitChildren(this);
}

Ili2Parser::GraphicDefContext* Ili2Parser::graphicDef() {
  GraphicDefContext *_localctx = _tracker.createInstance<GraphicDefContext>(_ctx, getState());
  enterRule(_localctx, 210, Ili2Parser::RuleGraphicDef);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1645);
    match(Ili2Parser::GRAPHIC);
    setState(1646);
    dynamic_cast<GraphicDefContext *>(_localctx)->graphicname1 = match(Ili2Parser::NAME);
    setState(1648);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == Ili2Parser::LPAREN) {
      setState(1647);
      properties();
    }
    setState(1652);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == Ili2Parser::EXTENDS) {
      setState(1650);
      match(Ili2Parser::EXTENDS);
      setState(1651);
      path();
    }
    setState(1657);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == Ili2Parser::BASED) {
      setState(1654);
      match(Ili2Parser::BASED);
      setState(1655);
      match(Ili2Parser::ON);
      setState(1656);
      path();
    }
    setState(1659);
    match(Ili2Parser::EQUAL);
    setState(1663);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == Ili2Parser::WHERE) {
      setState(1660);
      selection();
      setState(1665);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(1669);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == Ili2Parser::NAME) {
      setState(1666);
      drawingRule();
      setState(1671);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(1672);
    match(Ili2Parser::END);
    setState(1673);
    dynamic_cast<GraphicDefContext *>(_localctx)->graphicname2 = match(Ili2Parser::NAME);
    setState(1674);
    match(Ili2Parser::SEMI);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- DrawingRuleContext ------------------------------------------------------------------

Ili2Parser::DrawingRuleContext::DrawingRuleContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* Ili2Parser::DrawingRuleContext::COLON() {
  return getToken(Ili2Parser::COLON, 0);
}

std::vector<Ili2Parser::CondSignParamAssignmentContext *> Ili2Parser::DrawingRuleContext::condSignParamAssignment() {
  return getRuleContexts<Ili2Parser::CondSignParamAssignmentContext>();
}

Ili2Parser::CondSignParamAssignmentContext* Ili2Parser::DrawingRuleContext::condSignParamAssignment(size_t i) {
  return getRuleContext<Ili2Parser::CondSignParamAssignmentContext>(i);
}

tree::TerminalNode* Ili2Parser::DrawingRuleContext::SEMI() {
  return getToken(Ili2Parser::SEMI, 0);
}

tree::TerminalNode* Ili2Parser::DrawingRuleContext::NAME() {
  return getToken(Ili2Parser::NAME, 0);
}

Ili2Parser::PropertiesContext* Ili2Parser::DrawingRuleContext::properties() {
  return getRuleContext<Ili2Parser::PropertiesContext>(0);
}

tree::TerminalNode* Ili2Parser::DrawingRuleContext::OF() {
  return getToken(Ili2Parser::OF, 0);
}

Ili2Parser::PathContext* Ili2Parser::DrawingRuleContext::path() {
  return getRuleContext<Ili2Parser::PathContext>(0);
}

std::vector<tree::TerminalNode *> Ili2Parser::DrawingRuleContext::COMMA() {
  return getTokens(Ili2Parser::COMMA);
}

tree::TerminalNode* Ili2Parser::DrawingRuleContext::COMMA(size_t i) {
  return getToken(Ili2Parser::COMMA, i);
}


size_t Ili2Parser::DrawingRuleContext::getRuleIndex() const {
  return Ili2Parser::RuleDrawingRule;
}

antlrcpp::Any Ili2Parser::DrawingRuleContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<Ili2ParserVisitor*>(visitor))
    return parserVisitor->visitDrawingRule(this);
  else
    return visitor->visitChildren(this);
}

Ili2Parser::DrawingRuleContext* Ili2Parser::drawingRule() {
  DrawingRuleContext *_localctx = _tracker.createInstance<DrawingRuleContext>(_ctx, getState());
  enterRule(_localctx, 212, Ili2Parser::RuleDrawingRule);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1676);
    dynamic_cast<DrawingRuleContext *>(_localctx)->drawingrulename = match(Ili2Parser::NAME);
    setState(1678);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == Ili2Parser::LPAREN) {
      setState(1677);
      properties();
    }
    setState(1682);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == Ili2Parser::OF) {
      setState(1680);
      match(Ili2Parser::OF);
      setState(1681);
      path();
    }
    setState(1684);
    match(Ili2Parser::COLON);
    setState(1685);
    condSignParamAssignment();
    setState(1690);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == Ili2Parser::COMMA) {
      setState(1686);
      match(Ili2Parser::COMMA);
      setState(1687);
      condSignParamAssignment();
      setState(1692);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(1693);
    match(Ili2Parser::SEMI);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- CondSignParamAssignmentContext ------------------------------------------------------------------

Ili2Parser::CondSignParamAssignmentContext::CondSignParamAssignmentContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* Ili2Parser::CondSignParamAssignmentContext::LPAREN() {
  return getToken(Ili2Parser::LPAREN, 0);
}

std::vector<Ili2Parser::SignParamAssignmentContext *> Ili2Parser::CondSignParamAssignmentContext::signParamAssignment() {
  return getRuleContexts<Ili2Parser::SignParamAssignmentContext>();
}

Ili2Parser::SignParamAssignmentContext* Ili2Parser::CondSignParamAssignmentContext::signParamAssignment(size_t i) {
  return getRuleContext<Ili2Parser::SignParamAssignmentContext>(i);
}

tree::TerminalNode* Ili2Parser::CondSignParamAssignmentContext::RPAREN() {
  return getToken(Ili2Parser::RPAREN, 0);
}

tree::TerminalNode* Ili2Parser::CondSignParamAssignmentContext::WHERE() {
  return getToken(Ili2Parser::WHERE, 0);
}

std::vector<tree::TerminalNode *> Ili2Parser::CondSignParamAssignmentContext::COMMA() {
  return getTokens(Ili2Parser::COMMA);
}

tree::TerminalNode* Ili2Parser::CondSignParamAssignmentContext::COMMA(size_t i) {
  return getToken(Ili2Parser::COMMA, i);
}

Ili2Parser::ExpressionContext* Ili2Parser::CondSignParamAssignmentContext::expression() {
  return getRuleContext<Ili2Parser::ExpressionContext>(0);
}


size_t Ili2Parser::CondSignParamAssignmentContext::getRuleIndex() const {
  return Ili2Parser::RuleCondSignParamAssignment;
}

antlrcpp::Any Ili2Parser::CondSignParamAssignmentContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<Ili2ParserVisitor*>(visitor))
    return parserVisitor->visitCondSignParamAssignment(this);
  else
    return visitor->visitChildren(this);
}

Ili2Parser::CondSignParamAssignmentContext* Ili2Parser::condSignParamAssignment() {
  CondSignParamAssignmentContext *_localctx = _tracker.createInstance<CondSignParamAssignmentContext>(_ctx, getState());
  enterRule(_localctx, 214, Ili2Parser::RuleCondSignParamAssignment);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1697);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == Ili2Parser::WHERE) {
      setState(1695);
      match(Ili2Parser::WHERE);
      setState(1696);
      dynamic_cast<CondSignParamAssignmentContext *>(_localctx)->logical = expression();
    }
    setState(1699);
    match(Ili2Parser::LPAREN);
    setState(1700);
    signParamAssignment();
    setState(1705);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == Ili2Parser::COMMA) {
      setState(1701);
      match(Ili2Parser::COMMA);
      setState(1702);
      signParamAssignment();
      setState(1707);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(1708);
    match(Ili2Parser::RPAREN);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- SignParamAssignmentContext ------------------------------------------------------------------

Ili2Parser::SignParamAssignmentContext::SignParamAssignmentContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* Ili2Parser::SignParamAssignmentContext::COLONEQUAL() {
  return getToken(Ili2Parser::COLONEQUAL, 0);
}

tree::TerminalNode* Ili2Parser::SignParamAssignmentContext::NAME() {
  return getToken(Ili2Parser::NAME, 0);
}

tree::TerminalNode* Ili2Parser::SignParamAssignmentContext::LCURLY() {
  return getToken(Ili2Parser::LCURLY, 0);
}

Ili2Parser::MetaObjectRefContext* Ili2Parser::SignParamAssignmentContext::metaObjectRef() {
  return getRuleContext<Ili2Parser::MetaObjectRefContext>(0);
}

tree::TerminalNode* Ili2Parser::SignParamAssignmentContext::RCURLY() {
  return getToken(Ili2Parser::RCURLY, 0);
}

Ili2Parser::FactorContext* Ili2Parser::SignParamAssignmentContext::factor() {
  return getRuleContext<Ili2Parser::FactorContext>(0);
}

tree::TerminalNode* Ili2Parser::SignParamAssignmentContext::ACCORDING() {
  return getToken(Ili2Parser::ACCORDING, 0);
}

tree::TerminalNode* Ili2Parser::SignParamAssignmentContext::LPAREN() {
  return getToken(Ili2Parser::LPAREN, 0);
}

std::vector<Ili2Parser::EnumAssignmentContext *> Ili2Parser::SignParamAssignmentContext::enumAssignment() {
  return getRuleContexts<Ili2Parser::EnumAssignmentContext>();
}

Ili2Parser::EnumAssignmentContext* Ili2Parser::SignParamAssignmentContext::enumAssignment(size_t i) {
  return getRuleContext<Ili2Parser::EnumAssignmentContext>(i);
}

tree::TerminalNode* Ili2Parser::SignParamAssignmentContext::RPAREN() {
  return getToken(Ili2Parser::RPAREN, 0);
}

Ili2Parser::AttributePathContext* Ili2Parser::SignParamAssignmentContext::attributePath() {
  return getRuleContext<Ili2Parser::AttributePathContext>(0);
}

std::vector<tree::TerminalNode *> Ili2Parser::SignParamAssignmentContext::COMMA() {
  return getTokens(Ili2Parser::COMMA);
}

tree::TerminalNode* Ili2Parser::SignParamAssignmentContext::COMMA(size_t i) {
  return getToken(Ili2Parser::COMMA, i);
}


size_t Ili2Parser::SignParamAssignmentContext::getRuleIndex() const {
  return Ili2Parser::RuleSignParamAssignment;
}

antlrcpp::Any Ili2Parser::SignParamAssignmentContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<Ili2ParserVisitor*>(visitor))
    return parserVisitor->visitSignParamAssignment(this);
  else
    return visitor->visitChildren(this);
}

Ili2Parser::SignParamAssignmentContext* Ili2Parser::signParamAssignment() {
  SignParamAssignmentContext *_localctx = _tracker.createInstance<SignParamAssignmentContext>(_ctx, getState());
  enterRule(_localctx, 216, Ili2Parser::RuleSignParamAssignment);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1710);
    dynamic_cast<SignParamAssignmentContext *>(_localctx)->signparametername = match(Ili2Parser::NAME);
    setState(1711);
    match(Ili2Parser::COLONEQUAL);
    setState(1730);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case Ili2Parser::LCURLY: {
        setState(1712);
        match(Ili2Parser::LCURLY);
        setState(1713);
        metaObjectRef();
        setState(1714);
        match(Ili2Parser::RCURLY);
        break;
      }

      case Ili2Parser::INTERLIS:
      case Ili2Parser::BACKSLASH:
      case Ili2Parser::HASH:
      case Ili2Parser::GREATERGREATER:
      case Ili2Parser::GREATER:
      case Ili2Parser::PARAMETER:
      case Ili2Parser::UNDEFINED:
      case Ili2Parser::PI:
      case Ili2Parser::LNBASE:
      case Ili2Parser::AREA:
      case Ili2Parser::INSPECTION:
      case Ili2Parser::THIS:
      case Ili2Parser::THISAREA:
      case Ili2Parser::THATAREA:
      case Ili2Parser::PARENT:
      case Ili2Parser::AGGREGATES:
      case Ili2Parser::STRING:
      case Ili2Parser::POSNUMBER:
      case Ili2Parser::NUMBER:
      case Ili2Parser::DEC:
      case Ili2Parser::NAME: {
        setState(1716);
        factor();
        break;
      }

      case Ili2Parser::ACCORDING: {
        setState(1717);
        match(Ili2Parser::ACCORDING);
        setState(1718);
        dynamic_cast<SignParamAssignmentContext *>(_localctx)->enumpath = attributePath();
        setState(1719);
        match(Ili2Parser::LPAREN);
        setState(1720);
        enumAssignment();
        setState(1725);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while (_la == Ili2Parser::COMMA) {
          setState(1721);
          match(Ili2Parser::COMMA);
          setState(1722);
          enumAssignment();
          setState(1727);
          _errHandler->sync(this);
          _la = _input->LA(1);
        }
        setState(1728);
        match(Ili2Parser::RPAREN);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- EnumAssignmentContext ------------------------------------------------------------------

Ili2Parser::EnumAssignmentContext::EnumAssignmentContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* Ili2Parser::EnumAssignmentContext::WHEN() {
  return getToken(Ili2Parser::WHEN, 0);
}

tree::TerminalNode* Ili2Parser::EnumAssignmentContext::IN() {
  return getToken(Ili2Parser::IN, 0);
}

Ili2Parser::EnumRangeContext* Ili2Parser::EnumAssignmentContext::enumRange() {
  return getRuleContext<Ili2Parser::EnumRangeContext>(0);
}

tree::TerminalNode* Ili2Parser::EnumAssignmentContext::LCURLY() {
  return getToken(Ili2Parser::LCURLY, 0);
}

Ili2Parser::MetaObjectRefContext* Ili2Parser::EnumAssignmentContext::metaObjectRef() {
  return getRuleContext<Ili2Parser::MetaObjectRefContext>(0);
}

tree::TerminalNode* Ili2Parser::EnumAssignmentContext::RCURLY() {
  return getToken(Ili2Parser::RCURLY, 0);
}

Ili2Parser::ConstantContext* Ili2Parser::EnumAssignmentContext::constant() {
  return getRuleContext<Ili2Parser::ConstantContext>(0);
}


size_t Ili2Parser::EnumAssignmentContext::getRuleIndex() const {
  return Ili2Parser::RuleEnumAssignment;
}

antlrcpp::Any Ili2Parser::EnumAssignmentContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<Ili2ParserVisitor*>(visitor))
    return parserVisitor->visitEnumAssignment(this);
  else
    return visitor->visitChildren(this);
}

Ili2Parser::EnumAssignmentContext* Ili2Parser::enumAssignment() {
  EnumAssignmentContext *_localctx = _tracker.createInstance<EnumAssignmentContext>(_ctx, getState());
  enterRule(_localctx, 218, Ili2Parser::RuleEnumAssignment);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1737);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case Ili2Parser::LCURLY: {
        setState(1732);
        match(Ili2Parser::LCURLY);
        setState(1733);
        metaObjectRef();
        setState(1734);
        match(Ili2Parser::RCURLY);
        break;
      }

      case Ili2Parser::HASH:
      case Ili2Parser::GREATERGREATER:
      case Ili2Parser::GREATER:
      case Ili2Parser::UNDEFINED:
      case Ili2Parser::PI:
      case Ili2Parser::LNBASE:
      case Ili2Parser::STRING:
      case Ili2Parser::POSNUMBER:
      case Ili2Parser::NUMBER:
      case Ili2Parser::DEC: {
        setState(1736);
        constant();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    setState(1739);
    match(Ili2Parser::WHEN);
    setState(1740);
    match(Ili2Parser::IN);
    setState(1741);
    enumRange();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- EnumRangeContext ------------------------------------------------------------------

Ili2Parser::EnumRangeContext::EnumRangeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<Ili2Parser::EnumConstContext *> Ili2Parser::EnumRangeContext::enumConst() {
  return getRuleContexts<Ili2Parser::EnumConstContext>();
}

Ili2Parser::EnumConstContext* Ili2Parser::EnumRangeContext::enumConst(size_t i) {
  return getRuleContext<Ili2Parser::EnumConstContext>(i);
}

tree::TerminalNode* Ili2Parser::EnumRangeContext::DOTDOT() {
  return getToken(Ili2Parser::DOTDOT, 0);
}


size_t Ili2Parser::EnumRangeContext::getRuleIndex() const {
  return Ili2Parser::RuleEnumRange;
}

antlrcpp::Any Ili2Parser::EnumRangeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<Ili2ParserVisitor*>(visitor))
    return parserVisitor->visitEnumRange(this);
  else
    return visitor->visitChildren(this);
}

Ili2Parser::EnumRangeContext* Ili2Parser::enumRange() {
  EnumRangeContext *_localctx = _tracker.createInstance<EnumRangeContext>(_ctx, getState());
  enterRule(_localctx, 220, Ili2Parser::RuleEnumRange);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1743);
    enumConst();
    setState(1746);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == Ili2Parser::DOTDOT) {
      setState(1744);
      match(Ili2Parser::DOTDOT);
      setState(1745);
      enumConst();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

bool Ili2Parser::sempred(RuleContext *context, size_t ruleIndex, size_t predicateIndex) {
  switch (ruleIndex) {
    case 3: return modelDefSempred(dynamic_cast<ModelDefContext *>(context), predicateIndex);
    case 6: return topicDefSempred(dynamic_cast<TopicDefContext *>(context), predicateIndex);
    case 12: return bagOrListTypeSempred(dynamic_cast<BagOrListTypeContext *>(context), predicateIndex);
    case 22: return domainDefSempred(dynamic_cast<DomainDefContext *>(context), predicateIndex);
    case 24: return baseTypeSempred(dynamic_cast<BaseTypeContext *>(context), predicateIndex);
    case 44: return coordinateTypeSempred(dynamic_cast<CoordinateTypeContext *>(context), predicateIndex);
    case 52: return lineTypeSempred(dynamic_cast<LineTypeContext *>(context), predicateIndex);
    case 75: return setConstraintSempred(dynamic_cast<SetConstraintContext *>(context), predicateIndex);
    case 78: return orTermSempred(dynamic_cast<OrTermContext *>(context), predicateIndex);
    case 79: return andTermSempred(dynamic_cast<AndTermContext *>(context), predicateIndex);

  default:
    break;
  }
  return true;
}

bool Ili2Parser::modelDefSempred(ModelDefContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 0: return ili24;
    case 1: return ili24;
    case 2: return ili24;
    case 3: return ili24;

  default:
    break;
  }
  return true;
}

bool Ili2Parser::topicDefSempred(TopicDefContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 4: return ili24;

  default:
    break;
  }
  return true;
}

bool Ili2Parser::bagOrListTypeSempred(BagOrListTypeContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 5: return ili23;
    case 6: return ili24;

  default:
    break;
  }
  return true;
}

bool Ili2Parser::domainDefSempred(DomainDefContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 7: return ili24;

  default:
    break;
  }
  return true;
}

bool Ili2Parser::baseTypeSempred(BaseTypeContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 8: return ili24;

  default:
    break;
  }
  return true;
}

bool Ili2Parser::coordinateTypeSempred(CoordinateTypeContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 9: return ili23;
    case 10: return ili24;

  default:
    break;
  }
  return true;
}

bool Ili2Parser::lineTypeSempred(LineTypeContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 11: return ili24;

  default:
    break;
  }
  return true;
}

bool Ili2Parser::setConstraintSempred(SetConstraintContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 12: return ili24;

  default:
    break;
  }
  return true;
}

bool Ili2Parser::orTermSempred(OrTermContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 13: return ili24;
    case 14: return ili24;

  default:
    break;
  }
  return true;
}

bool Ili2Parser::andTermSempred(AndTermContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 15: return ili24;
    case 16: return ili24;

  default:
    break;
  }
  return true;
}

// Static vars and initialization.
std::vector<dfa::DFA> Ili2Parser::_decisionToDFA;
atn::PredictionContextCache Ili2Parser::_sharedContextCache;

// We own the ATN which in turn owns the ATN states.
atn::ATN Ili2Parser::_atn;
std::vector<uint16_t> Ili2Parser::_serializedATN;

std::vector<std::string> Ili2Parser::_ruleNames = {
  "decimal", "path", "interlis2Def", "modelDef", "importDef", "importing", 
  "topicDef", "classDef", "structureDef", "classOrStructureDef", "attributeDef", 
  "attrTypeDef", "bagOrListType", "attrType", "referenceAttr", "restrictedRef", 
  "restriction", "associationDef", "associationRef", "roleDef", "cardinality", 
  "domainDecl", "domainDef", "type", "baseType", "constant", "textType", 
  "textConst", "enumerationType", "enumTreeValueType", "enumeration", "enumElement", 
  "enumConst", "numericType", "dateTimeType", "refSys", "decConst", "numericConst", 
  "formattedType", "formatDef", "baseAttrRef", "formattedConst", "contextDef", 
  "contextDecl", "coordinateType", "rotationDef", "oIDType", "blackboxType", 
  "classType", "attributeType", "classConst", "attributeConst", "lineType", 
  "lineForm", "lineFormType", "lineFormTypeDef", "lineFormTypeDecl", "unitDecl", 
  "unitDef", "derivedUnit", "composedUnit", "metaDataBasketDef", "metaDataBasketRef", 
  "metaObjectRef", "parameterDef", "properties", "runTimeParameterDef", 
  "constraintDef", "mandatoryConstraint", "plausibilityConstraint", "existenceConstraint", 
  "uniquenessConstraint", "globalUniqueness", "uniqueEl", "localUniqueness", 
  "setConstraint", "constraintsDef", "expression", "orTerm", "andTerm", 
  "predicateTerm", "predicate", "relation", "factor", "objectOrAttributePath", 
  "attributePath", "pathEl", "associationPath", "attributeRef", "functionCall", 
  "functionCallArgument", "functionDef", "functionDefParam", "argumentType", 
  "viewDef", "formationDef", "projection", "join", "iliunion", "aggregation", 
  "inspection", "renamedViewableRef", "baseExtensionDef", "selection", "viewAttributes", 
  "graphicDef", "drawingRule", "condSignParamAssignment", "signParamAssignment", 
  "enumAssignment", "enumRange"
};

std::vector<std::string> Ili2Parser::_literalNames = {
  "", "", "", "", "", "", "'INTERLIS'", "'2.3'", "'2.4'", "'CONTRACTED'", 
  "'REFSYSTEM'", "'SYMBOLOGY'", "'TYPE'", "'MODEL'", "'END'", "'VERSION'", 
  "'NOINCREMENTALTRANSFER'", "'TRANSLATION'", "'OF'", "'AT'", "'CHARSET'", 
  "'XMLNS'", "'IMPORTS'", "'UNQUALIFIED'", "'TOPIC'", "'DEPENDS'", "'ON'", 
  "'AS'", "'VIEW'", "'EXTENDS'", "'BASKET'", "'OID'", "'CLASS'", "'ABSTRACT'", 
  "'EXTENDED'", "'FINAL'", "'TRANSIENT'", "'CONTINUOUS'", "'SUBDIVISION'", 
  "'NO'", "'ATTRIBUTE'", "'TEXT'", "'DATE'", "'TIMEOFDAY'", "'DATETIME'", 
  "'('", "')'", "'['", "']'", "'{'", "'}'", "'*'", "'/'", "'\\'", "'%'", 
  "'@'", "'#'", "'~'", "'<'", "'<='", "'=>'", "'>>'", "'>'", "'>='", "';'", 
  "'='", "'=='", "'<>'", "'!='", "':='", "'.'", "'..'", "':'", "','", "'<-'", 
  "'->'", "'+'", "'-'", "'-<>'", "'--'", "'-<#>'", "'STRUCTURE'", "'PARAMETER'", 
  "'MANDATORY'", "'GENERICS'", "'DEFERRED'", "'CONTEXT'", "'MULTICOORD'", 
  "'MULTIPOLYLINE'", "'MULTISURFACE'", "'MULTIAREA'", "'BAG'", "'LIST'", 
  "'REFERENCE'", "'TO'", "'ANYCLASS'", "'RESTRICTION'", "'ASSOCIATION'", 
  "'DERIVED'", "'EXTERNAL'", "'FROM'", "'UNDEFINED'", "'MTEXT'", "'ALL'", 
  "'CIRCULAR'", "'OTHERS'", "'NUMERIC'", "'CLOCKWISE'", "'COUNTERCLOCKWISE'", 
  "'CARDINALITY'", "'OR'", "'HIDING'", "'ORDERED'", "'DOMAIN'", "'PI'", 
  "'LNBASE'", "'FORMAT'", "'INHERIT'", "'COORD'", "'ROTATION'", "'ANY'", 
  "'BLACKBOX'", "'XML'", "'BINARY'", "'DIRECTED'", "'POLYLINE'", "'SURFACE'", 
  "'AREA'", "'WITH'", "'STRAIGHTS'", "'ARCS'", "'VERTEX'", "'WITHOUT'", 
  "'OVERLAPS'", "'LINE'", "'ATTRIBUTES'", "'FORM'", "'UNIT'", "'FUNCTION'", 
  "'SIGN'", "'OBJECTS'", "'METAOBJECT'", "'CONSTRAINT'", "'CONSTRAINTS'", 
  "'EXISTENCE'", "'REQUIRED'", "'IN'", "'UNIQUE'", "'WHERE'", "'LOCAL'", 
  "'SET'", "'AND'", "'NOT'", "'BASED'", "'BASE'", "'INHERITANCE'", "'DEFINED'", 
  "'INSPECTION'", "'THIS'", "'THISAREA'", "'THATAREA'", "'PARENT'", "'FIRST'", 
  "'LAST'", "'AGGREGATES'", "'OBJECT'", "'ENUMVAL'", "'ENUMTREEVAL'", "'PROJECTION'", 
  "'JOIN'", "'NULL'", "'UNION'", "'AGGREGATION'", "'BY'", "'GRAPHIC'", "'ACCORDING'", 
  "'WHEN'", "'ANYSTRUCTURE'", "'TRANSFER'"
};

std::vector<std::string> Ili2Parser::_symbolicNames = {
  "", "WS", "SL_COMMENT", "ILI_DOC", "ILI_OPTION", "ILI_BLOCKCOMMENT", "INTERLIS", 
  "ILI23", "ILI24", "CONTRACTED", "REFSYSTEM", "SYMBOLOGY", "TYPE", "MODEL", 
  "END", "VERSION", "NOINCREMENTALTRANSFER", "TRANSLATION", "OF", "ATT", 
  "CHARSET", "XMLNS", "IMPORTS", "UNQUALIFIED", "TOPIC", "DEPENDS", "ON", 
  "AS", "VIEW", "EXTENDS", "BASKET", "OID", "CLASS", "ABSTRACT", "EXTENDED", 
  "FINAL", "TRANSIENT", "CONTINUOUS", "SUBDIVISION", "NO", "ATTRIBUTE", 
  "TEXT", "DATE", "TIMEOFDAY", "DATETIME", "LPAREN", "RPAREN", "LBRACE", 
  "RBRACE", "LCURLY", "RCURLY", "STAR", "SLASH", "BACKSLASH", "PERCENT", 
  "AT", "HASH", "TILDE", "LESS", "LESSEQUAL", "IMPL", "GREATERGREATER", 
  "GREATER", "GREATEREQUAL", "SEMI", "EQUAL", "EQUALEQUAL", "LESSGREATER", 
  "NOTEQUAL", "COLONEQUAL", "DOT", "DOTDOT", "COLON", "COMMA", "LARROW", 
  "RARROW", "PLUS", "MINUS", "AGGREGATE", "ASSOCIATE", "COMPOSITE", "STRUCTURE", 
  "PARAMETER", "MANDATORY", "GENERICS", "DEFERRED", "CONTEXT", "MULTICOORD", 
  "MULTIPOLYLINE", "MULTISURFACE", "MULTIAREA", "BAG", "LIST", "REFERENCE", 
  "TO", "ANYCLASS", "RESTRICTION", "ASSOCIATION", "DERIVED", "EXTERNAL", 
  "FROM", "UNDEFINED", "MTEXT", "ALL", "CIRCULAR", "OTHERS", "NUMERIC", 
  "CLOCKWISE", "COUNTERCLOCKWISE", "CARDINALITY", "OR", "HIDING", "ORDERED", 
  "ILIDOMAIN", "PI", "LNBASE", "FORMAT", "INHERIT", "COORD", "ROTATION", 
  "ANY", "BLACKBOX", "XML", "BINARY", "DIRECTED", "POLYLINE", "SURFACE", 
  "AREA", "WITH", "STRAIGHTS", "ARCS", "VERTEX", "WITHOUT", "OVERLAPS", 
  "LINE", "ATTRIBUTES", "FORM", "UNIT", "FUNCTION", "SIGN", "OBJECTS", "METAOBJECT", 
  "CONSTRAINT", "CONSTRAINTS", "EXISTENCE", "REQUIRED", "IN", "UNIQUE", 
  "WHERE", "LOCAL", "SET", "AND", "NOT", "BASED", "BASE", "INHERITANCE", 
  "DEFINED", "INSPECTION", "THIS", "THISAREA", "THATAREA", "PARENT", "FIRST", 
  "LAST", "AGGREGATES", "OBJECT", "ENUMVAL", "ENUMTREEVAL", "PROJECTION", 
  "JOIN", "ILINULL", "UNION", "AGGREGATION", "BY", "GRAPHIC", "ACCORDING", 
  "WHEN", "ANYSTRUCTURE", "TRANSFER", "EXPLANATION", "ESC", "STRING", "POSNUMBER", 
  "NUMBER", "DEC", "SCALING", "DECIMAL", "HEXNUMBER", "NAME"
};

dfa::Vocabulary Ili2Parser::_vocabulary(_literalNames, _symbolicNames);

std::vector<std::string> Ili2Parser::_tokenNames;

Ili2Parser::Initializer::Initializer() {
	for (size_t i = 0; i < _symbolicNames.size(); ++i) {
		std::string name = _vocabulary.getLiteralName(i);
		if (name.empty()) {
			name = _vocabulary.getSymbolicName(i);
		}

		if (name.empty()) {
			_tokenNames.push_back("<INVALID>");
		} else {
      _tokenNames.push_back(name);
    }
	}

  _serializedATN = {
    0x3, 0x608b, 0xa72a, 0x8133, 0xb9ed, 0x417c, 0x3be7, 0x7786, 0x5964, 
    0x3, 0xbe, 0x6d7, 0x4, 0x2, 0x9, 0x2, 0x4, 0x3, 0x9, 0x3, 0x4, 0x4, 
    0x9, 0x4, 0x4, 0x5, 0x9, 0x5, 0x4, 0x6, 0x9, 0x6, 0x4, 0x7, 0x9, 0x7, 
    0x4, 0x8, 0x9, 0x8, 0x4, 0x9, 0x9, 0x9, 0x4, 0xa, 0x9, 0xa, 0x4, 0xb, 
    0x9, 0xb, 0x4, 0xc, 0x9, 0xc, 0x4, 0xd, 0x9, 0xd, 0x4, 0xe, 0x9, 0xe, 
    0x4, 0xf, 0x9, 0xf, 0x4, 0x10, 0x9, 0x10, 0x4, 0x11, 0x9, 0x11, 0x4, 
    0x12, 0x9, 0x12, 0x4, 0x13, 0x9, 0x13, 0x4, 0x14, 0x9, 0x14, 0x4, 0x15, 
    0x9, 0x15, 0x4, 0x16, 0x9, 0x16, 0x4, 0x17, 0x9, 0x17, 0x4, 0x18, 0x9, 
    0x18, 0x4, 0x19, 0x9, 0x19, 0x4, 0x1a, 0x9, 0x1a, 0x4, 0x1b, 0x9, 0x1b, 
    0x4, 0x1c, 0x9, 0x1c, 0x4, 0x1d, 0x9, 0x1d, 0x4, 0x1e, 0x9, 0x1e, 0x4, 
    0x1f, 0x9, 0x1f, 0x4, 0x20, 0x9, 0x20, 0x4, 0x21, 0x9, 0x21, 0x4, 0x22, 
    0x9, 0x22, 0x4, 0x23, 0x9, 0x23, 0x4, 0x24, 0x9, 0x24, 0x4, 0x25, 0x9, 
    0x25, 0x4, 0x26, 0x9, 0x26, 0x4, 0x27, 0x9, 0x27, 0x4, 0x28, 0x9, 0x28, 
    0x4, 0x29, 0x9, 0x29, 0x4, 0x2a, 0x9, 0x2a, 0x4, 0x2b, 0x9, 0x2b, 0x4, 
    0x2c, 0x9, 0x2c, 0x4, 0x2d, 0x9, 0x2d, 0x4, 0x2e, 0x9, 0x2e, 0x4, 0x2f, 
    0x9, 0x2f, 0x4, 0x30, 0x9, 0x30, 0x4, 0x31, 0x9, 0x31, 0x4, 0x32, 0x9, 
    0x32, 0x4, 0x33, 0x9, 0x33, 0x4, 0x34, 0x9, 0x34, 0x4, 0x35, 0x9, 0x35, 
    0x4, 0x36, 0x9, 0x36, 0x4, 0x37, 0x9, 0x37, 0x4, 0x38, 0x9, 0x38, 0x4, 
    0x39, 0x9, 0x39, 0x4, 0x3a, 0x9, 0x3a, 0x4, 0x3b, 0x9, 0x3b, 0x4, 0x3c, 
    0x9, 0x3c, 0x4, 0x3d, 0x9, 0x3d, 0x4, 0x3e, 0x9, 0x3e, 0x4, 0x3f, 0x9, 
    0x3f, 0x4, 0x40, 0x9, 0x40, 0x4, 0x41, 0x9, 0x41, 0x4, 0x42, 0x9, 0x42, 
    0x4, 0x43, 0x9, 0x43, 0x4, 0x44, 0x9, 0x44, 0x4, 0x45, 0x9, 0x45, 0x4, 
    0x46, 0x9, 0x46, 0x4, 0x47, 0x9, 0x47, 0x4, 0x48, 0x9, 0x48, 0x4, 0x49, 
    0x9, 0x49, 0x4, 0x4a, 0x9, 0x4a, 0x4, 0x4b, 0x9, 0x4b, 0x4, 0x4c, 0x9, 
    0x4c, 0x4, 0x4d, 0x9, 0x4d, 0x4, 0x4e, 0x9, 0x4e, 0x4, 0x4f, 0x9, 0x4f, 
    0x4, 0x50, 0x9, 0x50, 0x4, 0x51, 0x9, 0x51, 0x4, 0x52, 0x9, 0x52, 0x4, 
    0x53, 0x9, 0x53, 0x4, 0x54, 0x9, 0x54, 0x4, 0x55, 0x9, 0x55, 0x4, 0x56, 
    0x9, 0x56, 0x4, 0x57, 0x9, 0x57, 0x4, 0x58, 0x9, 0x58, 0x4, 0x59, 0x9, 
    0x59, 0x4, 0x5a, 0x9, 0x5a, 0x4, 0x5b, 0x9, 0x5b, 0x4, 0x5c, 0x9, 0x5c, 
    0x4, 0x5d, 0x9, 0x5d, 0x4, 0x5e, 0x9, 0x5e, 0x4, 0x5f, 0x9, 0x5f, 0x4, 
    0x60, 0x9, 0x60, 0x4, 0x61, 0x9, 0x61, 0x4, 0x62, 0x9, 0x62, 0x4, 0x63, 
    0x9, 0x63, 0x4, 0x64, 0x9, 0x64, 0x4, 0x65, 0x9, 0x65, 0x4, 0x66, 0x9, 
    0x66, 0x4, 0x67, 0x9, 0x67, 0x4, 0x68, 0x9, 0x68, 0x4, 0x69, 0x9, 0x69, 
    0x4, 0x6a, 0x9, 0x6a, 0x4, 0x6b, 0x9, 0x6b, 0x4, 0x6c, 0x9, 0x6c, 0x4, 
    0x6d, 0x9, 0x6d, 0x4, 0x6e, 0x9, 0x6e, 0x4, 0x6f, 0x9, 0x6f, 0x4, 0x70, 
    0x9, 0x70, 0x3, 0x2, 0x3, 0x2, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x7, 0x3, 
    0xe6, 0xa, 0x3, 0xc, 0x3, 0xe, 0x3, 0xe9, 0xb, 0x3, 0x3, 0x4, 0x3, 0x4, 
    0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x5, 0x4, 0xf0, 0xa, 0x4, 0x3, 0x4, 0x3, 
    0x4, 0x7, 0x4, 0xf4, 0xa, 0x4, 0xc, 0x4, 0xe, 0x4, 0xf7, 0xb, 0x4, 0x3, 
    0x4, 0x3, 0x4, 0x3, 0x5, 0x5, 0x5, 0xfc, 0xa, 0x5, 0x3, 0x5, 0x3, 0x5, 
    0x3, 0x5, 0x5, 0x5, 0x101, 0xa, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 
    0x5, 0x3, 0x5, 0x5, 0x5, 0x108, 0xa, 0x5, 0x3, 0x5, 0x3, 0x5, 0x5, 0x5, 
    0x10c, 0xa, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x5, 
    0x5, 0x113, 0xa, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 
    0x3, 0x5, 0x5, 0x5, 0x11b, 0xa, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 
    0x5, 0x3, 0x5, 0x5, 0x5, 0x122, 0xa, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 
    0x3, 0x5, 0x5, 0x5, 0x128, 0xa, 0x5, 0x3, 0x5, 0x7, 0x5, 0x12b, 0xa, 
    0x5, 0xc, 0x5, 0xe, 0x5, 0x12e, 0xb, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 
    0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 
    0x3, 0x5, 0x7, 0x5, 0x13b, 0xa, 0x5, 0xc, 0x5, 0xe, 0x5, 0x13e, 0xb, 
    0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x6, 0x3, 0x6, 0x3, 
    0x6, 0x3, 0x6, 0x7, 0x6, 0x148, 0xa, 0x6, 0xc, 0x6, 0xe, 0x6, 0x14b, 
    0xb, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x7, 0x5, 0x7, 0x150, 0xa, 0x7, 0x3, 
    0x7, 0x3, 0x7, 0x3, 0x8, 0x5, 0x8, 0x155, 0xa, 0x8, 0x3, 0x8, 0x3, 0x8, 
    0x3, 0x8, 0x5, 0x8, 0x15a, 0xa, 0x8, 0x3, 0x8, 0x3, 0x8, 0x5, 0x8, 0x15e, 
    0xa, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 
    0x3, 0x8, 0x5, 0x8, 0x167, 0xa, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 
    0x8, 0x3, 0x8, 0x5, 0x8, 0x16e, 0xa, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 
    0x3, 0x8, 0x3, 0x8, 0x7, 0x8, 0x175, 0xa, 0x8, 0xc, 0x8, 0xe, 0x8, 0x178, 
    0xb, 0x8, 0x3, 0x8, 0x3, 0x8, 0x7, 0x8, 0x17c, 0xa, 0x8, 0xc, 0x8, 0xe, 
    0x8, 0x17f, 0xb, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 
    0x3, 0x8, 0x7, 0x8, 0x187, 0xa, 0x8, 0xc, 0x8, 0xe, 0x8, 0x18a, 0xb, 
    0x8, 0x3, 0x8, 0x3, 0x8, 0x5, 0x8, 0x18e, 0xa, 0x8, 0x3, 0x8, 0x3, 0x8, 
    0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 
    0x3, 0x8, 0x7, 0x8, 0x19a, 0xa, 0x8, 0xc, 0x8, 0xe, 0x8, 0x19d, 0xb, 
    0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x9, 0x3, 0x9, 0x3, 
    0x9, 0x5, 0x9, 0x1a6, 0xa, 0x9, 0x3, 0x9, 0x3, 0x9, 0x5, 0x9, 0x1aa, 
    0xa, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 
    0x5, 0x9, 0x1b2, 0xa, 0x9, 0x3, 0x9, 0x5, 0x9, 0x1b5, 0xa, 0x9, 0x3, 
    0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0xa, 0x3, 0xa, 0x3, 
    0xa, 0x5, 0xa, 0x1bf, 0xa, 0xa, 0x3, 0xa, 0x3, 0xa, 0x5, 0xa, 0x1c3, 
    0xa, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 
    0x3, 0xb, 0x5, 0xb, 0x1cc, 0xa, 0xb, 0x3, 0xb, 0x7, 0xb, 0x1cf, 0xa, 
    0xb, 0xc, 0xb, 0xe, 0xb, 0x1d2, 0xb, 0xb, 0x3, 0xb, 0x7, 0xb, 0x1d5, 
    0xa, 0xb, 0xc, 0xb, 0xe, 0xb, 0x1d8, 0xb, 0xb, 0x3, 0xb, 0x3, 0xb, 0x7, 
    0xb, 0x1dc, 0xa, 0xb, 0xc, 0xb, 0xe, 0xb, 0x1df, 0xb, 0xb, 0x5, 0xb, 
    0x1e1, 0xa, 0xb, 0x3, 0xc, 0x5, 0xc, 0x1e4, 0xa, 0xc, 0x3, 0xc, 0x5, 
    0xc, 0x1e7, 0xa, 0xc, 0x3, 0xc, 0x3, 0xc, 0x5, 0xc, 0x1eb, 0xa, 0xc, 
    0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x7, 0xc, 
    0x1f3, 0xa, 0xc, 0xc, 0xc, 0xe, 0xc, 0x1f6, 0xb, 0xc, 0x5, 0xc, 0x1f8, 
    0xa, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xd, 0x5, 0xd, 0x1fd, 0xa, 0xd, 0x3, 
    0xd, 0x3, 0xd, 0x5, 0xd, 0x201, 0xa, 0xd, 0x3, 0xe, 0x3, 0xe, 0x5, 0xe, 
    0x205, 0xa, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x5, 
    0xe, 0x20c, 0xa, 0xe, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x5, 0xf, 
    0x212, 0xa, 0xf, 0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 
    0x5, 0x10, 0x219, 0xa, 0x10, 0x3, 0x10, 0x3, 0x10, 0x3, 0x11, 0x3, 0x11, 
    0x3, 0x11, 0x5, 0x11, 0x220, 0xa, 0x11, 0x3, 0x11, 0x5, 0x11, 0x223, 
    0xa, 0x11, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x7, 
    0x12, 0x22a, 0xa, 0x12, 0xc, 0x12, 0xe, 0x12, 0x22d, 0xb, 0x12, 0x3, 
    0x12, 0x3, 0x12, 0x3, 0x13, 0x3, 0x13, 0x3, 0x13, 0x5, 0x13, 0x234, 
    0xa, 0x13, 0x3, 0x13, 0x3, 0x13, 0x5, 0x13, 0x238, 0xa, 0x13, 0x3, 0x13, 
    0x3, 0x13, 0x3, 0x13, 0x5, 0x13, 0x23d, 0xa, 0x13, 0x3, 0x13, 0x3, 0x13, 
    0x3, 0x13, 0x3, 0x13, 0x3, 0x13, 0x3, 0x13, 0x5, 0x13, 0x245, 0xa, 0x13, 
    0x3, 0x13, 0x5, 0x13, 0x248, 0xa, 0x13, 0x3, 0x13, 0x7, 0x13, 0x24b, 
    0xa, 0x13, 0xc, 0x13, 0xe, 0x13, 0x24e, 0xb, 0x13, 0x3, 0x13, 0x5, 0x13, 
    0x251, 0xa, 0x13, 0x3, 0x13, 0x7, 0x13, 0x254, 0xa, 0x13, 0xc, 0x13, 
    0xe, 0x13, 0x257, 0xb, 0x13, 0x3, 0x13, 0x3, 0x13, 0x3, 0x13, 0x3, 0x13, 
    0x3, 0x13, 0x5, 0x13, 0x25e, 0xa, 0x13, 0x3, 0x13, 0x7, 0x13, 0x261, 
    0xa, 0x13, 0xc, 0x13, 0xe, 0x13, 0x264, 0xb, 0x13, 0x3, 0x13, 0x3, 0x13, 
    0x3, 0x13, 0x3, 0x13, 0x3, 0x14, 0x3, 0x14, 0x5, 0x14, 0x26c, 0xa, 0x14, 
    0x3, 0x14, 0x3, 0x14, 0x5, 0x14, 0x270, 0xa, 0x14, 0x3, 0x14, 0x3, 0x14, 
    0x3, 0x15, 0x3, 0x15, 0x5, 0x15, 0x276, 0xa, 0x15, 0x3, 0x15, 0x3, 0x15, 
    0x5, 0x15, 0x27a, 0xa, 0x15, 0x3, 0x15, 0x3, 0x15, 0x3, 0x15, 0x7, 0x15, 
    0x27f, 0xa, 0x15, 0xc, 0x15, 0xe, 0x15, 0x282, 0xb, 0x15, 0x3, 0x15, 
    0x3, 0x15, 0x5, 0x15, 0x286, 0xa, 0x15, 0x3, 0x15, 0x3, 0x15, 0x3, 0x16, 
    0x3, 0x16, 0x3, 0x16, 0x3, 0x16, 0x3, 0x16, 0x3, 0x16, 0x5, 0x16, 0x290, 
    0xa, 0x16, 0x5, 0x16, 0x292, 0xa, 0x16, 0x5, 0x16, 0x294, 0xa, 0x16, 
    0x3, 0x16, 0x3, 0x16, 0x3, 0x17, 0x3, 0x17, 0x7, 0x17, 0x29a, 0xa, 0x17, 
    0xc, 0x17, 0xe, 0x17, 0x29d, 0xb, 0x17, 0x3, 0x18, 0x3, 0x18, 0x5, 0x18, 
    0x2a1, 0xa, 0x18, 0x3, 0x18, 0x3, 0x18, 0x5, 0x18, 0x2a5, 0xa, 0x18, 
    0x3, 0x18, 0x3, 0x18, 0x3, 0x18, 0x5, 0x18, 0x2aa, 0xa, 0x18, 0x3, 0x18, 
    0x5, 0x18, 0x2ad, 0xa, 0x18, 0x3, 0x18, 0x3, 0x18, 0x3, 0x18, 0x3, 0x18, 
    0x3, 0x18, 0x3, 0x18, 0x3, 0x18, 0x3, 0x18, 0x3, 0x18, 0x7, 0x18, 0x2b8, 
    0xa, 0x18, 0xc, 0x18, 0xe, 0x18, 0x2bb, 0xb, 0x18, 0x5, 0x18, 0x2bd, 
    0xa, 0x18, 0x3, 0x18, 0x3, 0x18, 0x3, 0x19, 0x3, 0x19, 0x5, 0x19, 0x2c3, 
    0xa, 0x19, 0x3, 0x1a, 0x3, 0x1a, 0x3, 0x1a, 0x3, 0x1a, 0x3, 0x1a, 0x3, 
    0x1a, 0x3, 0x1a, 0x3, 0x1a, 0x3, 0x1a, 0x3, 0x1a, 0x3, 0x1a, 0x3, 0x1a, 
    0x5, 0x1a, 0x2d1, 0xa, 0x1a, 0x3, 0x1b, 0x3, 0x1b, 0x3, 0x1b, 0x3, 0x1b, 
    0x3, 0x1b, 0x3, 0x1b, 0x3, 0x1b, 0x5, 0x1b, 0x2da, 0xa, 0x1b, 0x3, 0x1c, 
    0x3, 0x1c, 0x3, 0x1c, 0x5, 0x1c, 0x2df, 0xa, 0x1c, 0x3, 0x1c, 0x3, 0x1c, 
    0x3, 0x1c, 0x5, 0x1c, 0x2e4, 0xa, 0x1c, 0x5, 0x1c, 0x2e6, 0xa, 0x1c, 
    0x3, 0x1d, 0x3, 0x1d, 0x3, 0x1e, 0x3, 0x1e, 0x5, 0x1e, 0x2ec, 0xa, 0x1e, 
    0x3, 0x1f, 0x3, 0x1f, 0x3, 0x1f, 0x3, 0x1f, 0x3, 0x20, 0x3, 0x20, 0x3, 
    0x20, 0x3, 0x20, 0x7, 0x20, 0x2f6, 0xa, 0x20, 0xc, 0x20, 0xe, 0x20, 
    0x2f9, 0xb, 0x20, 0x3, 0x20, 0x3, 0x20, 0x5, 0x20, 0x2fd, 0xa, 0x20, 
    0x3, 0x20, 0x5, 0x20, 0x300, 0xa, 0x20, 0x3, 0x20, 0x3, 0x20, 0x3, 0x21, 
    0x3, 0x21, 0x3, 0x21, 0x7, 0x21, 0x307, 0xa, 0x21, 0xc, 0x21, 0xe, 0x21, 
    0x30a, 0xb, 0x21, 0x3, 0x21, 0x5, 0x21, 0x30d, 0xa, 0x21, 0x3, 0x22, 
    0x3, 0x22, 0x3, 0x22, 0x3, 0x22, 0x7, 0x22, 0x313, 0xa, 0x22, 0xc, 0x22, 
    0xe, 0x22, 0x316, 0xb, 0x22, 0x3, 0x22, 0x3, 0x22, 0x5, 0x22, 0x31a, 
    0xa, 0x22, 0x3, 0x22, 0x5, 0x22, 0x31d, 0xa, 0x22, 0x3, 0x23, 0x3, 0x23, 
    0x3, 0x23, 0x3, 0x23, 0x3, 0x23, 0x5, 0x23, 0x324, 0xa, 0x23, 0x3, 0x23, 
    0x5, 0x23, 0x327, 0xa, 0x23, 0x3, 0x23, 0x3, 0x23, 0x3, 0x23, 0x3, 0x23, 
    0x5, 0x23, 0x32d, 0xa, 0x23, 0x3, 0x23, 0x3, 0x23, 0x3, 0x23, 0x5, 0x23, 
    0x332, 0xa, 0x23, 0x3, 0x24, 0x3, 0x24, 0x3, 0x25, 0x3, 0x25, 0x3, 0x25, 
    0x3, 0x25, 0x3, 0x25, 0x5, 0x25, 0x33b, 0xa, 0x25, 0x3, 0x25, 0x3, 0x25, 
    0x3, 0x25, 0x3, 0x25, 0x3, 0x25, 0x3, 0x25, 0x3, 0x25, 0x5, 0x25, 0x344, 
    0xa, 0x25, 0x3, 0x25, 0x3, 0x25, 0x5, 0x25, 0x348, 0xa, 0x25, 0x3, 0x26, 
    0x3, 0x26, 0x3, 0x26, 0x5, 0x26, 0x34d, 0xa, 0x26, 0x3, 0x27, 0x3, 0x27, 
    0x3, 0x27, 0x3, 0x27, 0x3, 0x27, 0x5, 0x27, 0x354, 0xa, 0x27, 0x3, 0x28, 
    0x3, 0x28, 0x3, 0x28, 0x3, 0x28, 0x3, 0x28, 0x3, 0x28, 0x5, 0x28, 0x35c, 
    0xa, 0x28, 0x3, 0x28, 0x3, 0x28, 0x3, 0x28, 0x5, 0x28, 0x361, 0xa, 0x28, 
    0x3, 0x28, 0x3, 0x28, 0x3, 0x28, 0x3, 0x28, 0x3, 0x28, 0x3, 0x28, 0x5, 
    0x28, 0x369, 0xa, 0x28, 0x3, 0x29, 0x3, 0x29, 0x5, 0x29, 0x36d, 0xa, 
    0x29, 0x3, 0x29, 0x5, 0x29, 0x370, 0xa, 0x29, 0x3, 0x29, 0x3, 0x29, 
    0x3, 0x29, 0x7, 0x29, 0x375, 0xa, 0x29, 0xc, 0x29, 0xe, 0x29, 0x378, 
    0xb, 0x29, 0x3, 0x29, 0x3, 0x29, 0x5, 0x29, 0x37c, 0xa, 0x29, 0x3, 0x29, 
    0x3, 0x29, 0x3, 0x2a, 0x3, 0x2a, 0x3, 0x2a, 0x5, 0x2a, 0x383, 0xa, 0x2a, 
    0x3, 0x2a, 0x3, 0x2a, 0x3, 0x2a, 0x5, 0x2a, 0x388, 0xa, 0x2a, 0x3, 0x2b, 
    0x3, 0x2b, 0x3, 0x2c, 0x3, 0x2c, 0x3, 0x2c, 0x3, 0x2c, 0x7, 0x2c, 0x390, 
    0xa, 0x2c, 0xc, 0x2c, 0xe, 0x2c, 0x393, 0xb, 0x2c, 0x3, 0x2d, 0x3, 0x2d, 
    0x3, 0x2d, 0x3, 0x2d, 0x3, 0x2d, 0x7, 0x2d, 0x39a, 0xa, 0x2d, 0xc, 0x2d, 
    0xe, 0x2d, 0x39d, 0xb, 0x2d, 0x3, 0x2e, 0x3, 0x2e, 0x3, 0x2e, 0x3, 0x2e, 
    0x5, 0x2e, 0x3a3, 0xa, 0x2e, 0x3, 0x2e, 0x3, 0x2e, 0x3, 0x2e, 0x3, 0x2e, 
    0x3, 0x2e, 0x5, 0x2e, 0x3aa, 0xa, 0x2e, 0x5, 0x2e, 0x3ac, 0xa, 0x2e, 
    0x3, 0x2e, 0x3, 0x2e, 0x5, 0x2e, 0x3b0, 0xa, 0x2e, 0x3, 0x2f, 0x3, 0x2f, 
    0x3, 0x2f, 0x3, 0x2f, 0x3, 0x2f, 0x3, 0x30, 0x3, 0x30, 0x3, 0x30, 0x3, 
    0x30, 0x5, 0x30, 0x3bb, 0xa, 0x30, 0x3, 0x31, 0x3, 0x31, 0x3, 0x31, 
    0x3, 0x32, 0x3, 0x32, 0x5, 0x32, 0x3c2, 0xa, 0x32, 0x3, 0x32, 0x3, 0x32, 
    0x5, 0x32, 0x3c6, 0xa, 0x32, 0x5, 0x32, 0x3c8, 0xa, 0x32, 0x3, 0x33, 
    0x3, 0x33, 0x3, 0x33, 0x3, 0x33, 0x3, 0x33, 0x5, 0x33, 0x3cf, 0xa, 0x33, 
    0x5, 0x33, 0x3d1, 0xa, 0x33, 0x3, 0x33, 0x3, 0x33, 0x3, 0x33, 0x3, 0x33, 
    0x3, 0x33, 0x7, 0x33, 0x3d8, 0xa, 0x33, 0xc, 0x33, 0xe, 0x33, 0x3db, 
    0xb, 0x33, 0x3, 0x33, 0x3, 0x33, 0x5, 0x33, 0x3df, 0xa, 0x33, 0x3, 0x34, 
    0x3, 0x34, 0x3, 0x34, 0x3, 0x35, 0x3, 0x35, 0x3, 0x35, 0x3, 0x35, 0x5, 
    0x35, 0x3e8, 0xa, 0x35, 0x3, 0x35, 0x3, 0x35, 0x3, 0x36, 0x5, 0x36, 
    0x3ed, 0xa, 0x36, 0x3, 0x36, 0x3, 0x36, 0x3, 0x36, 0x5, 0x36, 0x3f2, 
    0xa, 0x36, 0x3, 0x36, 0x3, 0x36, 0x5, 0x36, 0x3f6, 0xa, 0x36, 0x3, 0x36, 
    0x3, 0x36, 0x3, 0x36, 0x5, 0x36, 0x3fb, 0xa, 0x36, 0x5, 0x36, 0x3fd, 
    0xa, 0x36, 0x3, 0x36, 0x5, 0x36, 0x400, 0xa, 0x36, 0x3, 0x36, 0x3, 0x36, 
    0x5, 0x36, 0x404, 0xa, 0x36, 0x3, 0x36, 0x3, 0x36, 0x3, 0x36, 0x3, 0x36, 
    0x5, 0x36, 0x40a, 0xa, 0x36, 0x5, 0x36, 0x40c, 0xa, 0x36, 0x3, 0x36, 
    0x3, 0x36, 0x3, 0x36, 0x5, 0x36, 0x411, 0xa, 0x36, 0x3, 0x37, 0x3, 0x37, 
    0x3, 0x37, 0x3, 0x37, 0x3, 0x37, 0x7, 0x37, 0x418, 0xa, 0x37, 0xc, 0x37, 
    0xe, 0x37, 0x41b, 0xb, 0x37, 0x3, 0x37, 0x3, 0x37, 0x3, 0x38, 0x3, 0x38, 
    0x3, 0x38, 0x5, 0x38, 0x422, 0xa, 0x38, 0x3, 0x39, 0x3, 0x39, 0x3, 0x39, 
    0x7, 0x39, 0x427, 0xa, 0x39, 0xc, 0x39, 0xe, 0x39, 0x42a, 0xb, 0x39, 
    0x3, 0x3a, 0x3, 0x3a, 0x3, 0x3a, 0x5, 0x3a, 0x42f, 0xa, 0x3a, 0x3, 0x3a, 
    0x3, 0x3a, 0x3, 0x3b, 0x3, 0x3b, 0x7, 0x3b, 0x435, 0xa, 0x3b, 0xc, 0x3b, 
    0xe, 0x3b, 0x438, 0xb, 0x3b, 0x3, 0x3c, 0x3, 0x3c, 0x3, 0x3c, 0x3, 0x3c, 
    0x3, 0x3c, 0x3, 0x3c, 0x3, 0x3c, 0x3, 0x3c, 0x5, 0x3c, 0x442, 0xa, 0x3c, 
    0x3, 0x3c, 0x3, 0x3c, 0x5, 0x3c, 0x446, 0xa, 0x3c, 0x3, 0x3c, 0x3, 0x3c, 
    0x3, 0x3c, 0x5, 0x3c, 0x44b, 0xa, 0x3c, 0x5, 0x3c, 0x44d, 0xa, 0x3c, 
    0x3, 0x3c, 0x3, 0x3c, 0x3, 0x3d, 0x3, 0x3d, 0x3, 0x3d, 0x7, 0x3d, 0x454, 
    0xa, 0x3d, 0xc, 0x3d, 0xe, 0x3d, 0x457, 0xb, 0x3d, 0x3, 0x3d, 0x3, 0x3d, 
    0x5, 0x3d, 0x45b, 0xa, 0x3d, 0x3, 0x3d, 0x3, 0x3d, 0x3, 0x3d, 0x3, 0x3d, 
    0x3, 0x3e, 0x3, 0x3e, 0x3, 0x3e, 0x3, 0x3e, 0x3, 0x3f, 0x3, 0x3f, 0x3, 
    0x3f, 0x3, 0x3f, 0x3, 0x3f, 0x3, 0x3f, 0x5, 0x3f, 0x46b, 0xa, 0x3f, 
    0x3, 0x3f, 0x3, 0x3f, 0x5, 0x3f, 0x46f, 0xa, 0x3f, 0x3, 0x3f, 0x3, 0x3f, 
    0x3, 0x3f, 0x3, 0x3f, 0x3, 0x3f, 0x3, 0x3f, 0x3, 0x3f, 0x3, 0x3f, 0x3, 
    0x3f, 0x7, 0x3f, 0x47a, 0xa, 0x3f, 0xc, 0x3f, 0xe, 0x3f, 0x47d, 0xb, 
    0x3f, 0x7, 0x3f, 0x47f, 0xa, 0x3f, 0xc, 0x3f, 0xe, 0x3f, 0x482, 0xb, 
    0x3f, 0x3, 0x3f, 0x3, 0x3f, 0x3, 0x40, 0x3, 0x40, 0x5, 0x40, 0x488, 
    0xa, 0x40, 0x3, 0x40, 0x3, 0x40, 0x5, 0x40, 0x48c, 0xa, 0x40, 0x3, 0x40, 
    0x3, 0x40, 0x3, 0x41, 0x3, 0x41, 0x3, 0x41, 0x5, 0x41, 0x493, 0xa, 0x41, 
    0x3, 0x41, 0x3, 0x41, 0x3, 0x42, 0x3, 0x42, 0x5, 0x42, 0x499, 0xa, 0x42, 
    0x3, 0x42, 0x3, 0x42, 0x3, 0x42, 0x3, 0x42, 0x3, 0x42, 0x5, 0x42, 0x4a0, 
    0xa, 0x42, 0x5, 0x42, 0x4a2, 0xa, 0x42, 0x3, 0x42, 0x3, 0x42, 0x3, 0x43, 
    0x3, 0x43, 0x3, 0x43, 0x3, 0x43, 0x7, 0x43, 0x4aa, 0xa, 0x43, 0xc, 0x43, 
    0xe, 0x43, 0x4ad, 0xb, 0x43, 0x3, 0x43, 0x3, 0x43, 0x3, 0x44, 0x3, 0x44, 
    0x3, 0x44, 0x3, 0x44, 0x3, 0x44, 0x3, 0x44, 0x7, 0x44, 0x4b7, 0xa, 0x44, 
    0xc, 0x44, 0xe, 0x44, 0x4ba, 0xb, 0x44, 0x3, 0x45, 0x3, 0x45, 0x3, 0x45, 
    0x3, 0x45, 0x3, 0x45, 0x5, 0x45, 0x4c1, 0xa, 0x45, 0x3, 0x46, 0x3, 0x46, 
    0x3, 0x46, 0x3, 0x46, 0x3, 0x46, 0x3, 0x47, 0x3, 0x47, 0x3, 0x47, 0x3, 
    0x47, 0x3, 0x47, 0x3, 0x47, 0x3, 0x47, 0x3, 0x48, 0x3, 0x48, 0x3, 0x48, 
    0x3, 0x48, 0x3, 0x48, 0x3, 0x48, 0x3, 0x48, 0x3, 0x48, 0x3, 0x48, 0x3, 
    0x48, 0x3, 0x48, 0x3, 0x48, 0x3, 0x48, 0x7, 0x48, 0x4dc, 0xa, 0x48, 
    0xc, 0x48, 0xe, 0x48, 0x4df, 0xb, 0x48, 0x3, 0x48, 0x3, 0x48, 0x3, 0x49, 
    0x3, 0x49, 0x3, 0x49, 0x3, 0x49, 0x3, 0x49, 0x5, 0x49, 0x4e8, 0xa, 0x49, 
    0x3, 0x49, 0x3, 0x49, 0x5, 0x49, 0x4ec, 0xa, 0x49, 0x3, 0x49, 0x3, 0x49, 
    0x3, 0x4a, 0x3, 0x4a, 0x3, 0x4b, 0x3, 0x4b, 0x3, 0x4b, 0x7, 0x4b, 0x4f5, 
    0xa, 0x4b, 0xc, 0x4b, 0xe, 0x4b, 0x4f8, 0xb, 0x4b, 0x3, 0x4c, 0x3, 0x4c, 
    0x3, 0x4c, 0x3, 0x4c, 0x3, 0x4c, 0x3, 0x4c, 0x7, 0x4c, 0x500, 0xa, 0x4c, 
    0xc, 0x4c, 0xe, 0x4c, 0x503, 0xb, 0x4c, 0x3, 0x4c, 0x3, 0x4c, 0x3, 0x4c, 
    0x3, 0x4c, 0x7, 0x4c, 0x509, 0xa, 0x4c, 0xc, 0x4c, 0xe, 0x4c, 0x50c, 
    0xb, 0x4c, 0x3, 0x4d, 0x3, 0x4d, 0x3, 0x4d, 0x3, 0x4d, 0x3, 0x4d, 0x5, 
    0x4d, 0x513, 0xa, 0x4d, 0x3, 0x4d, 0x3, 0x4d, 0x3, 0x4d, 0x3, 0x4d, 
    0x5, 0x4d, 0x519, 0xa, 0x4d, 0x3, 0x4d, 0x3, 0x4d, 0x3, 0x4d, 0x3, 0x4e, 
    0x3, 0x4e, 0x3, 0x4e, 0x3, 0x4e, 0x3, 0x4e, 0x7, 0x4e, 0x523, 0xa, 0x4e, 
    0xc, 0x4e, 0xe, 0x4e, 0x526, 0xb, 0x4e, 0x3, 0x4e, 0x3, 0x4e, 0x3, 0x4e, 
    0x3, 0x4f, 0x3, 0x4f, 0x3, 0x50, 0x3, 0x50, 0x3, 0x50, 0x3, 0x50, 0x3, 
    0x50, 0x3, 0x50, 0x5, 0x50, 0x533, 0xa, 0x50, 0x3, 0x50, 0x7, 0x50, 
    0x536, 0xa, 0x50, 0xc, 0x50, 0xe, 0x50, 0x539, 0xb, 0x50, 0x3, 0x51, 
    0x3, 0x51, 0x3, 0x51, 0x3, 0x51, 0x3, 0x51, 0x3, 0x51, 0x5, 0x51, 0x541, 
    0xa, 0x51, 0x3, 0x51, 0x7, 0x51, 0x544, 0xa, 0x51, 0xc, 0x51, 0xe, 0x51, 
    0x547, 0xb, 0x51, 0x3, 0x52, 0x3, 0x52, 0x3, 0x52, 0x3, 0x52, 0x5, 0x52, 
    0x54d, 0xa, 0x52, 0x3, 0x53, 0x3, 0x53, 0x5, 0x53, 0x551, 0xa, 0x53, 
    0x3, 0x53, 0x3, 0x53, 0x3, 0x53, 0x3, 0x53, 0x3, 0x53, 0x3, 0x53, 0x3, 
    0x53, 0x3, 0x53, 0x3, 0x53, 0x5, 0x53, 0x55c, 0xa, 0x53, 0x3, 0x54, 
    0x3, 0x54, 0x3, 0x55, 0x3, 0x55, 0x3, 0x55, 0x3, 0x55, 0x5, 0x55, 0x564, 
    0xa, 0x55, 0x3, 0x55, 0x3, 0x55, 0x5, 0x55, 0x568, 0xa, 0x55, 0x3, 0x55, 
    0x3, 0x55, 0x3, 0x55, 0x3, 0x55, 0x7, 0x55, 0x56e, 0xa, 0x55, 0xc, 0x55, 
    0xe, 0x55, 0x571, 0xb, 0x55, 0x3, 0x55, 0x3, 0x55, 0x5, 0x55, 0x575, 
    0xa, 0x55, 0x3, 0x56, 0x3, 0x56, 0x3, 0x56, 0x7, 0x56, 0x57a, 0xa, 0x56, 
    0xc, 0x56, 0xe, 0x56, 0x57d, 0xb, 0x56, 0x3, 0x57, 0x3, 0x57, 0x3, 0x58, 
    0x3, 0x58, 0x3, 0x58, 0x3, 0x58, 0x3, 0x58, 0x3, 0x58, 0x3, 0x58, 0x3, 
    0x58, 0x3, 0x58, 0x3, 0x58, 0x5, 0x58, 0x58b, 0xa, 0x58, 0x3, 0x58, 
    0x3, 0x58, 0x5, 0x58, 0x58f, 0xa, 0x58, 0x3, 0x59, 0x5, 0x59, 0x592, 
    0xa, 0x59, 0x3, 0x59, 0x3, 0x59, 0x3, 0x5a, 0x3, 0x5a, 0x3, 0x5a, 0x3, 
    0x5a, 0x3, 0x5a, 0x5, 0x5a, 0x59b, 0xa, 0x5a, 0x3, 0x5a, 0x5, 0x5a, 
    0x59e, 0xa, 0x5a, 0x3, 0x5a, 0x5, 0x5a, 0x5a1, 0xa, 0x5a, 0x3, 0x5b, 
    0x3, 0x5b, 0x3, 0x5b, 0x3, 0x5b, 0x3, 0x5b, 0x7, 0x5b, 0x5a8, 0xa, 0x5b, 
    0xc, 0x5b, 0xe, 0x5b, 0x5ab, 0xb, 0x5b, 0x5, 0x5b, 0x5ad, 0xa, 0x5b, 
    0x3, 0x5b, 0x3, 0x5b, 0x3, 0x5c, 0x3, 0x5c, 0x3, 0x5c, 0x3, 0x5c, 0x3, 
    0x5c, 0x3, 0x5c, 0x3, 0x5c, 0x7, 0x5c, 0x5b8, 0xa, 0x5c, 0xc, 0x5c, 
    0xe, 0x5c, 0x5bb, 0xb, 0x5c, 0x5, 0x5c, 0x5bd, 0xa, 0x5c, 0x3, 0x5d, 
    0x3, 0x5d, 0x3, 0x5d, 0x3, 0x5d, 0x3, 0x5d, 0x3, 0x5d, 0x7, 0x5d, 0x5c5, 
    0xa, 0x5d, 0xc, 0x5d, 0xe, 0x5d, 0x5c8, 0xb, 0x5d, 0x5, 0x5d, 0x5ca, 
    0xa, 0x5d, 0x3, 0x5d, 0x3, 0x5d, 0x3, 0x5d, 0x3, 0x5d, 0x5, 0x5d, 0x5d0, 
    0xa, 0x5d, 0x3, 0x5d, 0x3, 0x5d, 0x3, 0x5e, 0x3, 0x5e, 0x3, 0x5e, 0x3, 
    0x5e, 0x3, 0x5f, 0x3, 0x5f, 0x3, 0x5f, 0x3, 0x5f, 0x3, 0x5f, 0x5, 0x5f, 
    0x5dd, 0xa, 0x5f, 0x3, 0x5f, 0x3, 0x5f, 0x5, 0x5f, 0x5e1, 0xa, 0x5f, 
    0x3, 0x60, 0x3, 0x60, 0x3, 0x60, 0x5, 0x60, 0x5e6, 0xa, 0x60, 0x3, 0x60, 
    0x3, 0x60, 0x3, 0x60, 0x5, 0x60, 0x5eb, 0xa, 0x60, 0x3, 0x60, 0x7, 0x60, 
    0x5ee, 0xa, 0x60, 0xc, 0x60, 0xe, 0x60, 0x5f1, 0xb, 0x60, 0x3, 0x60, 
    0x7, 0x60, 0x5f4, 0xa, 0x60, 0xc, 0x60, 0xe, 0x60, 0x5f7, 0xb, 0x60, 
    0x3, 0x60, 0x3, 0x60, 0x5, 0x60, 0x5fb, 0xa, 0x60, 0x3, 0x60, 0x7, 0x60, 
    0x5fe, 0xa, 0x60, 0xc, 0x60, 0xe, 0x60, 0x601, 0xb, 0x60, 0x3, 0x60, 
    0x3, 0x60, 0x3, 0x60, 0x3, 0x60, 0x3, 0x61, 0x3, 0x61, 0x3, 0x61, 0x3, 
    0x61, 0x3, 0x61, 0x5, 0x61, 0x60c, 0xa, 0x61, 0x3, 0x61, 0x3, 0x61, 
    0x3, 0x62, 0x3, 0x62, 0x3, 0x62, 0x3, 0x62, 0x3, 0x63, 0x3, 0x63, 0x3, 
    0x63, 0x3, 0x63, 0x3, 0x63, 0x3, 0x63, 0x3, 0x63, 0x3, 0x63, 0x3, 0x63, 
    0x5, 0x63, 0x61d, 0xa, 0x63, 0x6, 0x63, 0x61f, 0xa, 0x63, 0xd, 0x63, 
    0xe, 0x63, 0x620, 0x3, 0x64, 0x3, 0x64, 0x3, 0x64, 0x3, 0x64, 0x3, 0x64, 
    0x7, 0x64, 0x628, 0xa, 0x64, 0xc, 0x64, 0xe, 0x64, 0x62b, 0xb, 0x64, 
    0x3, 0x65, 0x3, 0x65, 0x3, 0x65, 0x3, 0x65, 0x3, 0x65, 0x3, 0x65, 0x3, 
    0x65, 0x3, 0x65, 0x3, 0x65, 0x5, 0x65, 0x636, 0xa, 0x65, 0x3, 0x66, 
    0x3, 0x66, 0x3, 0x66, 0x3, 0x66, 0x3, 0x66, 0x3, 0x66, 0x3, 0x66, 0x3, 
    0x66, 0x7, 0x66, 0x640, 0xa, 0x66, 0xc, 0x66, 0xe, 0x66, 0x643, 0xb, 
    0x66, 0x3, 0x67, 0x3, 0x67, 0x5, 0x67, 0x647, 0xa, 0x67, 0x3, 0x67, 
    0x3, 0x67, 0x3, 0x68, 0x3, 0x68, 0x3, 0x68, 0x3, 0x68, 0x3, 0x68, 0x3, 
    0x68, 0x3, 0x68, 0x7, 0x68, 0x652, 0xa, 0x68, 0xc, 0x68, 0xe, 0x68, 
    0x655, 0xb, 0x68, 0x3, 0x69, 0x3, 0x69, 0x3, 0x69, 0x3, 0x69, 0x3, 0x6a, 
    0x5, 0x6a, 0x65c, 0xa, 0x6a, 0x3, 0x6a, 0x3, 0x6a, 0x3, 0x6a, 0x3, 0x6a, 
    0x3, 0x6a, 0x3, 0x6a, 0x3, 0x6a, 0x5, 0x6a, 0x665, 0xa, 0x6a, 0x3, 0x6a, 
    0x3, 0x6a, 0x3, 0x6a, 0x3, 0x6a, 0x7, 0x6a, 0x66b, 0xa, 0x6a, 0xc, 0x6a, 
    0xe, 0x6a, 0x66e, 0xb, 0x6a, 0x3, 0x6b, 0x3, 0x6b, 0x3, 0x6b, 0x5, 0x6b, 
    0x673, 0xa, 0x6b, 0x3, 0x6b, 0x3, 0x6b, 0x5, 0x6b, 0x677, 0xa, 0x6b, 
    0x3, 0x6b, 0x3, 0x6b, 0x3, 0x6b, 0x5, 0x6b, 0x67c, 0xa, 0x6b, 0x3, 0x6b, 
    0x3, 0x6b, 0x7, 0x6b, 0x680, 0xa, 0x6b, 0xc, 0x6b, 0xe, 0x6b, 0x683, 
    0xb, 0x6b, 0x3, 0x6b, 0x7, 0x6b, 0x686, 0xa, 0x6b, 0xc, 0x6b, 0xe, 0x6b, 
    0x689, 0xb, 0x6b, 0x3, 0x6b, 0x3, 0x6b, 0x3, 0x6b, 0x3, 0x6b, 0x3, 0x6c, 
    0x3, 0x6c, 0x5, 0x6c, 0x691, 0xa, 0x6c, 0x3, 0x6c, 0x3, 0x6c, 0x5, 0x6c, 
    0x695, 0xa, 0x6c, 0x3, 0x6c, 0x3, 0x6c, 0x3, 0x6c, 0x3, 0x6c, 0x7, 0x6c, 
    0x69b, 0xa, 0x6c, 0xc, 0x6c, 0xe, 0x6c, 0x69e, 0xb, 0x6c, 0x3, 0x6c, 
    0x3, 0x6c, 0x3, 0x6d, 0x3, 0x6d, 0x5, 0x6d, 0x6a4, 0xa, 0x6d, 0x3, 0x6d, 
    0x3, 0x6d, 0x3, 0x6d, 0x3, 0x6d, 0x7, 0x6d, 0x6aa, 0xa, 0x6d, 0xc, 0x6d, 
    0xe, 0x6d, 0x6ad, 0xb, 0x6d, 0x3, 0x6d, 0x3, 0x6d, 0x3, 0x6e, 0x3, 0x6e, 
    0x3, 0x6e, 0x3, 0x6e, 0x3, 0x6e, 0x3, 0x6e, 0x3, 0x6e, 0x3, 0x6e, 0x3, 
    0x6e, 0x3, 0x6e, 0x3, 0x6e, 0x3, 0x6e, 0x3, 0x6e, 0x7, 0x6e, 0x6be, 
    0xa, 0x6e, 0xc, 0x6e, 0xe, 0x6e, 0x6c1, 0xb, 0x6e, 0x3, 0x6e, 0x3, 0x6e, 
    0x5, 0x6e, 0x6c5, 0xa, 0x6e, 0x3, 0x6f, 0x3, 0x6f, 0x3, 0x6f, 0x3, 0x6f, 
    0x3, 0x6f, 0x5, 0x6f, 0x6cc, 0xa, 0x6f, 0x3, 0x6f, 0x3, 0x6f, 0x3, 0x6f, 
    0x3, 0x6f, 0x3, 0x70, 0x3, 0x70, 0x3, 0x70, 0x5, 0x70, 0x6d5, 0xa, 0x70, 
    0x3, 0x70, 0x2, 0x2, 0x71, 0x2, 0x4, 0x6, 0x8, 0xa, 0xc, 0xe, 0x10, 
    0x12, 0x14, 0x16, 0x18, 0x1a, 0x1c, 0x1e, 0x20, 0x22, 0x24, 0x26, 0x28, 
    0x2a, 0x2c, 0x2e, 0x30, 0x32, 0x34, 0x36, 0x38, 0x3a, 0x3c, 0x3e, 0x40, 
    0x42, 0x44, 0x46, 0x48, 0x4a, 0x4c, 0x4e, 0x50, 0x52, 0x54, 0x56, 0x58, 
    0x5a, 0x5c, 0x5e, 0x60, 0x62, 0x64, 0x66, 0x68, 0x6a, 0x6c, 0x6e, 0x70, 
    0x72, 0x74, 0x76, 0x78, 0x7a, 0x7c, 0x7e, 0x80, 0x82, 0x84, 0x86, 0x88, 
    0x8a, 0x8c, 0x8e, 0x90, 0x92, 0x94, 0x96, 0x98, 0x9a, 0x9c, 0x9e, 0xa0, 
    0xa2, 0xa4, 0xa6, 0xa8, 0xaa, 0xac, 0xae, 0xb0, 0xb2, 0xb4, 0xb6, 0xb8, 
    0xba, 0xbc, 0xbe, 0xc0, 0xc2, 0xc4, 0xc6, 0xc8, 0xca, 0xcc, 0xce, 0xd0, 
    0xd2, 0xd4, 0xd6, 0xd8, 0xda, 0xdc, 0xde, 0x2, 0xf, 0x3, 0x2, 0xb8, 
    0xba, 0x4, 0x2, 0x8, 0x8, 0xbe, 0xbe, 0x3, 0x2, 0x5d, 0x5e, 0x3, 0x2, 
    0x50, 0x52, 0x4, 0x2, 0x6a, 0x6a, 0x72, 0x72, 0x3, 0x2, 0x2c, 0x2e, 
    0x3, 0x2, 0x7c, 0x7d, 0x3, 0x2, 0x35, 0x36, 0x4, 0x2, 0xc, 0xc, 0x8d, 
    0x8d, 0x6, 0x2, 0x21, 0x21, 0x23, 0x26, 0x65, 0x65, 0x71, 0x72, 0x4, 
    0x2, 0x3d, 0x3d, 0x41, 0x41, 0x5, 0x2, 0x3c, 0x3d, 0x40, 0x41, 0x44, 
    0x46, 0x4, 0x2, 0x8e, 0x8e, 0xa7, 0xa7, 0x2, 0x791, 0x2, 0xe0, 0x3, 
    0x2, 0x2, 0x2, 0x4, 0xe2, 0x3, 0x2, 0x2, 0x2, 0x6, 0xea, 0x3, 0x2, 0x2, 
    0x2, 0x8, 0xfb, 0x3, 0x2, 0x2, 0x2, 0xa, 0x143, 0x3, 0x2, 0x2, 0x2, 
    0xc, 0x14f, 0x3, 0x2, 0x2, 0x2, 0xe, 0x154, 0x3, 0x2, 0x2, 0x2, 0x10, 
    0x1a2, 0x3, 0x2, 0x2, 0x2, 0x12, 0x1bb, 0x3, 0x2, 0x2, 0x2, 0x14, 0x1cb, 
    0x3, 0x2, 0x2, 0x2, 0x16, 0x1e6, 0x3, 0x2, 0x2, 0x2, 0x18, 0x200, 0x3, 
    0x2, 0x2, 0x2, 0x1a, 0x202, 0x3, 0x2, 0x2, 0x2, 0x1c, 0x211, 0x3, 0x2, 
    0x2, 0x2, 0x1e, 0x213, 0x3, 0x2, 0x2, 0x2, 0x20, 0x21f, 0x3, 0x2, 0x2, 
    0x2, 0x22, 0x224, 0x3, 0x2, 0x2, 0x2, 0x24, 0x230, 0x3, 0x2, 0x2, 0x2, 
    0x26, 0x26f, 0x3, 0x2, 0x2, 0x2, 0x28, 0x273, 0x3, 0x2, 0x2, 0x2, 0x2a, 
    0x289, 0x3, 0x2, 0x2, 0x2, 0x2c, 0x297, 0x3, 0x2, 0x2, 0x2, 0x2e, 0x29e, 
    0x3, 0x2, 0x2, 0x2, 0x30, 0x2c2, 0x3, 0x2, 0x2, 0x2, 0x32, 0x2d0, 0x3, 
    0x2, 0x2, 0x2, 0x34, 0x2d9, 0x3, 0x2, 0x2, 0x2, 0x36, 0x2e5, 0x3, 0x2, 
    0x2, 0x2, 0x38, 0x2e7, 0x3, 0x2, 0x2, 0x2, 0x3a, 0x2e9, 0x3, 0x2, 0x2, 
    0x2, 0x3c, 0x2ed, 0x3, 0x2, 0x2, 0x2, 0x3e, 0x2f1, 0x3, 0x2, 0x2, 0x2, 
    0x40, 0x303, 0x3, 0x2, 0x2, 0x2, 0x42, 0x30e, 0x3, 0x2, 0x2, 0x2, 0x44, 
    0x323, 0x3, 0x2, 0x2, 0x2, 0x46, 0x333, 0x3, 0x2, 0x2, 0x2, 0x48, 0x347, 
    0x3, 0x2, 0x2, 0x2, 0x4a, 0x34c, 0x3, 0x2, 0x2, 0x2, 0x4c, 0x34e, 0x3, 
    0x2, 0x2, 0x2, 0x4e, 0x368, 0x3, 0x2, 0x2, 0x2, 0x50, 0x36a, 0x3, 0x2, 
    0x2, 0x2, 0x52, 0x387, 0x3, 0x2, 0x2, 0x2, 0x54, 0x389, 0x3, 0x2, 0x2, 
    0x2, 0x56, 0x38b, 0x3, 0x2, 0x2, 0x2, 0x58, 0x394, 0x3, 0x2, 0x2, 0x2, 
    0x5a, 0x3a2, 0x3, 0x2, 0x2, 0x2, 0x5c, 0x3b1, 0x3, 0x2, 0x2, 0x2, 0x5e, 
    0x3b6, 0x3, 0x2, 0x2, 0x2, 0x60, 0x3bc, 0x3, 0x2, 0x2, 0x2, 0x62, 0x3c7, 
    0x3, 0x2, 0x2, 0x2, 0x64, 0x3c9, 0x3, 0x2, 0x2, 0x2, 0x66, 0x3e0, 0x3, 
    0x2, 0x2, 0x2, 0x68, 0x3e3, 0x3, 0x2, 0x2, 0x2, 0x6a, 0x3f1, 0x3, 0x2, 
    0x2, 0x2, 0x6c, 0x412, 0x3, 0x2, 0x2, 0x2, 0x6e, 0x421, 0x3, 0x2, 0x2, 
    0x2, 0x70, 0x423, 0x3, 0x2, 0x2, 0x2, 0x72, 0x42b, 0x3, 0x2, 0x2, 0x2, 
    0x74, 0x432, 0x3, 0x2, 0x2, 0x2, 0x76, 0x439, 0x3, 0x2, 0x2, 0x2, 0x78, 
    0x45a, 0x3, 0x2, 0x2, 0x2, 0x7a, 0x460, 0x3, 0x2, 0x2, 0x2, 0x7c, 0x464, 
    0x3, 0x2, 0x2, 0x2, 0x7e, 0x48b, 0x3, 0x2, 0x2, 0x2, 0x80, 0x492, 0x3, 
    0x2, 0x2, 0x2, 0x82, 0x496, 0x3, 0x2, 0x2, 0x2, 0x84, 0x4a5, 0x3, 0x2, 
    0x2, 0x2, 0x86, 0x4b0, 0x3, 0x2, 0x2, 0x2, 0x88, 0x4c0, 0x3, 0x2, 0x2, 
    0x2, 0x8a, 0x4c2, 0x3, 0x2, 0x2, 0x2, 0x8c, 0x4c7, 0x3, 0x2, 0x2, 0x2, 
    0x8e, 0x4ce, 0x3, 0x2, 0x2, 0x2, 0x90, 0x4e2, 0x3, 0x2, 0x2, 0x2, 0x92, 
    0x4ef, 0x3, 0x2, 0x2, 0x2, 0x94, 0x4f1, 0x3, 0x2, 0x2, 0x2, 0x96, 0x4f9, 
    0x3, 0x2, 0x2, 0x2, 0x98, 0x50d, 0x3, 0x2, 0x2, 0x2, 0x9a, 0x51d, 0x3, 
    0x2, 0x2, 0x2, 0x9c, 0x52a, 0x3, 0x2, 0x2, 0x2, 0x9e, 0x52c, 0x3, 0x2, 
    0x2, 0x2, 0xa0, 0x53a, 0x3, 0x2, 0x2, 0x2, 0xa2, 0x548, 0x3, 0x2, 0x2, 
    0x2, 0xa4, 0x55b, 0x3, 0x2, 0x2, 0x2, 0xa6, 0x55d, 0x3, 0x2, 0x2, 0x2, 
    0xa8, 0x574, 0x3, 0x2, 0x2, 0x2, 0xaa, 0x576, 0x3, 0x2, 0x2, 0x2, 0xac, 
    0x57e, 0x3, 0x2, 0x2, 0x2, 0xae, 0x58e, 0x3, 0x2, 0x2, 0x2, 0xb0, 0x591, 
    0x3, 0x2, 0x2, 0x2, 0xb2, 0x5a0, 0x3, 0x2, 0x2, 0x2, 0xb4, 0x5a2, 0x3, 
    0x2, 0x2, 0x2, 0xb6, 0x5bc, 0x3, 0x2, 0x2, 0x2, 0xb8, 0x5be, 0x3, 0x2, 
    0x2, 0x2, 0xba, 0x5d3, 0x3, 0x2, 0x2, 0x2, 0xbc, 0x5e0, 0x3, 0x2, 0x2, 
    0x2, 0xbe, 0x5e2, 0x3, 0x2, 0x2, 0x2, 0xc0, 0x60b, 0x3, 0x2, 0x2, 0x2, 
    0xc2, 0x60f, 0x3, 0x2, 0x2, 0x2, 0xc4, 0x613, 0x3, 0x2, 0x2, 0x2, 0xc6, 
    0x622, 0x3, 0x2, 0x2, 0x2, 0xc8, 0x62c, 0x3, 0x2, 0x2, 0x2, 0xca, 0x637, 
    0x3, 0x2, 0x2, 0x2, 0xcc, 0x646, 0x3, 0x2, 0x2, 0x2, 0xce, 0x64a, 0x3, 
    0x2, 0x2, 0x2, 0xd0, 0x656, 0x3, 0x2, 0x2, 0x2, 0xd2, 0x65b, 0x3, 0x2, 
    0x2, 0x2, 0xd4, 0x66f, 0x3, 0x2, 0x2, 0x2, 0xd6, 0x68e, 0x3, 0x2, 0x2, 
    0x2, 0xd8, 0x6a3, 0x3, 0x2, 0x2, 0x2, 0xda, 0x6b0, 0x3, 0x2, 0x2, 0x2, 
    0xdc, 0x6cb, 0x3, 0x2, 0x2, 0x2, 0xde, 0x6d1, 0x3, 0x2, 0x2, 0x2, 0xe0, 
    0xe1, 0x9, 0x2, 0x2, 0x2, 0xe1, 0x3, 0x3, 0x2, 0x2, 0x2, 0xe2, 0xe7, 
    0x9, 0x3, 0x2, 0x2, 0xe3, 0xe4, 0x7, 0x48, 0x2, 0x2, 0xe4, 0xe6, 0x7, 
    0xbe, 0x2, 0x2, 0xe5, 0xe3, 0x3, 0x2, 0x2, 0x2, 0xe6, 0xe9, 0x3, 0x2, 
    0x2, 0x2, 0xe7, 0xe5, 0x3, 0x2, 0x2, 0x2, 0xe7, 0xe8, 0x3, 0x2, 0x2, 
    0x2, 0xe8, 0x5, 0x3, 0x2, 0x2, 0x2, 0xe9, 0xe7, 0x3, 0x2, 0x2, 0x2, 
    0xea, 0xef, 0x7, 0x8, 0x2, 0x2, 0xeb, 0xec, 0x7, 0x9, 0x2, 0x2, 0xec, 
    0xf0, 0x8, 0x4, 0x1, 0x2, 0xed, 0xee, 0x7, 0xa, 0x2, 0x2, 0xee, 0xf0, 
    0x8, 0x4, 0x1, 0x2, 0xef, 0xeb, 0x3, 0x2, 0x2, 0x2, 0xef, 0xed, 0x3, 
    0x2, 0x2, 0x2, 0xf0, 0xf1, 0x3, 0x2, 0x2, 0x2, 0xf1, 0xf5, 0x7, 0x42, 
    0x2, 0x2, 0xf2, 0xf4, 0x5, 0x8, 0x5, 0x2, 0xf3, 0xf2, 0x3, 0x2, 0x2, 
    0x2, 0xf4, 0xf7, 0x3, 0x2, 0x2, 0x2, 0xf5, 0xf3, 0x3, 0x2, 0x2, 0x2, 
    0xf5, 0xf6, 0x3, 0x2, 0x2, 0x2, 0xf6, 0xf8, 0x3, 0x2, 0x2, 0x2, 0xf7, 
    0xf5, 0x3, 0x2, 0x2, 0x2, 0xf8, 0xf9, 0x7, 0x2, 0x2, 0x3, 0xf9, 0x7, 
    0x3, 0x2, 0x2, 0x2, 0xfa, 0xfc, 0x7, 0xb, 0x2, 0x2, 0xfb, 0xfa, 0x3, 
    0x2, 0x2, 0x2, 0xfb, 0xfc, 0x3, 0x2, 0x2, 0x2, 0xfc, 0x100, 0x3, 0x2, 
    0x2, 0x2, 0xfd, 0x101, 0x7, 0xc, 0x2, 0x2, 0xfe, 0x101, 0x7, 0xd, 0x2, 
    0x2, 0xff, 0x101, 0x7, 0xe, 0x2, 0x2, 0x100, 0xfd, 0x3, 0x2, 0x2, 0x2, 
    0x100, 0xfe, 0x3, 0x2, 0x2, 0x2, 0x100, 0xff, 0x3, 0x2, 0x2, 0x2, 0x100, 
    0x101, 0x3, 0x2, 0x2, 0x2, 0x101, 0x102, 0x3, 0x2, 0x2, 0x2, 0x102, 
    0x103, 0x7, 0xf, 0x2, 0x2, 0x103, 0x107, 0x7, 0xbe, 0x2, 0x2, 0x104, 
    0x105, 0x7, 0x2f, 0x2, 0x2, 0x105, 0x106, 0x7, 0xbe, 0x2, 0x2, 0x106, 
    0x108, 0x7, 0x30, 0x2, 0x2, 0x107, 0x104, 0x3, 0x2, 0x2, 0x2, 0x107, 
    0x108, 0x3, 0x2, 0x2, 0x2, 0x108, 0x10b, 0x3, 0x2, 0x2, 0x2, 0x109, 
    0x10a, 0x6, 0x5, 0x2, 0x2, 0x10a, 0x10c, 0x7, 0x12, 0x2, 0x2, 0x10b, 
    0x109, 0x3, 0x2, 0x2, 0x2, 0x10b, 0x10c, 0x3, 0x2, 0x2, 0x2, 0x10c, 
    0x10d, 0x3, 0x2, 0x2, 0x2, 0x10d, 0x10e, 0x7, 0x15, 0x2, 0x2, 0x10e, 
    0x10f, 0x7, 0xb7, 0x2, 0x2, 0x10f, 0x110, 0x7, 0x11, 0x2, 0x2, 0x110, 
    0x112, 0x7, 0xb7, 0x2, 0x2, 0x111, 0x113, 0x7, 0xb5, 0x2, 0x2, 0x112, 
    0x111, 0x3, 0x2, 0x2, 0x2, 0x112, 0x113, 0x3, 0x2, 0x2, 0x2, 0x113, 
    0x11a, 0x3, 0x2, 0x2, 0x2, 0x114, 0x115, 0x7, 0x13, 0x2, 0x2, 0x115, 
    0x116, 0x7, 0x14, 0x2, 0x2, 0x116, 0x117, 0x7, 0xbe, 0x2, 0x2, 0x117, 
    0x118, 0x7, 0x31, 0x2, 0x2, 0x118, 0x119, 0x7, 0xb7, 0x2, 0x2, 0x119, 
    0x11b, 0x7, 0x32, 0x2, 0x2, 0x11a, 0x114, 0x3, 0x2, 0x2, 0x2, 0x11a, 
    0x11b, 0x3, 0x2, 0x2, 0x2, 0x11b, 0x11c, 0x3, 0x2, 0x2, 0x2, 0x11c, 
    0x121, 0x7, 0x43, 0x2, 0x2, 0x11d, 0x11e, 0x6, 0x5, 0x3, 0x2, 0x11e, 
    0x11f, 0x7, 0x16, 0x2, 0x2, 0x11f, 0x120, 0x7, 0xb7, 0x2, 0x2, 0x120, 
    0x122, 0x7, 0x42, 0x2, 0x2, 0x121, 0x11d, 0x3, 0x2, 0x2, 0x2, 0x121, 
    0x122, 0x3, 0x2, 0x2, 0x2, 0x122, 0x127, 0x3, 0x2, 0x2, 0x2, 0x123, 
    0x124, 0x6, 0x5, 0x4, 0x2, 0x124, 0x125, 0x7, 0x17, 0x2, 0x2, 0x125, 
    0x126, 0x7, 0xb7, 0x2, 0x2, 0x126, 0x128, 0x7, 0x42, 0x2, 0x2, 0x127, 
    0x123, 0x3, 0x2, 0x2, 0x2, 0x127, 0x128, 0x3, 0x2, 0x2, 0x2, 0x128, 
    0x12c, 0x3, 0x2, 0x2, 0x2, 0x129, 0x12b, 0x5, 0xa, 0x6, 0x2, 0x12a, 
    0x129, 0x3, 0x2, 0x2, 0x2, 0x12b, 0x12e, 0x3, 0x2, 0x2, 0x2, 0x12c, 
    0x12a, 0x3, 0x2, 0x2, 0x2, 0x12c, 0x12d, 0x3, 0x2, 0x2, 0x2, 0x12d, 
    0x13c, 0x3, 0x2, 0x2, 0x2, 0x12e, 0x12c, 0x3, 0x2, 0x2, 0x2, 0x12f, 
    0x13b, 0x5, 0x7c, 0x3f, 0x2, 0x130, 0x13b, 0x5, 0x74, 0x3b, 0x2, 0x131, 
    0x13b, 0x5, 0xb8, 0x5d, 0x2, 0x132, 0x13b, 0x5, 0x70, 0x39, 0x2, 0x133, 
    0x13b, 0x5, 0x2c, 0x17, 0x2, 0x134, 0x135, 0x6, 0x5, 0x5, 0x2, 0x135, 
    0x13b, 0x5, 0x56, 0x2c, 0x2, 0x136, 0x13b, 0x5, 0x86, 0x44, 0x2, 0x137, 
    0x13b, 0x5, 0x10, 0x9, 0x2, 0x138, 0x13b, 0x5, 0x12, 0xa, 0x2, 0x139, 
    0x13b, 0x5, 0xe, 0x8, 0x2, 0x13a, 0x12f, 0x3, 0x2, 0x2, 0x2, 0x13a, 
    0x130, 0x3, 0x2, 0x2, 0x2, 0x13a, 0x131, 0x3, 0x2, 0x2, 0x2, 0x13a, 
    0x132, 0x3, 0x2, 0x2, 0x2, 0x13a, 0x133, 0x3, 0x2, 0x2, 0x2, 0x13a, 
    0x134, 0x3, 0x2, 0x2, 0x2, 0x13a, 0x136, 0x3, 0x2, 0x2, 0x2, 0x13a, 
    0x137, 0x3, 0x2, 0x2, 0x2, 0x13a, 0x138, 0x3, 0x2, 0x2, 0x2, 0x13a, 
    0x139, 0x3, 0x2, 0x2, 0x2, 0x13b, 0x13e, 0x3, 0x2, 0x2, 0x2, 0x13c, 
    0x13a, 0x3, 0x2, 0x2, 0x2, 0x13c, 0x13d, 0x3, 0x2, 0x2, 0x2, 0x13d, 
    0x13f, 0x3, 0x2, 0x2, 0x2, 0x13e, 0x13c, 0x3, 0x2, 0x2, 0x2, 0x13f, 
    0x140, 0x7, 0x10, 0x2, 0x2, 0x140, 0x141, 0x7, 0xbe, 0x2, 0x2, 0x141, 
    0x142, 0x7, 0x48, 0x2, 0x2, 0x142, 0x9, 0x3, 0x2, 0x2, 0x2, 0x143, 0x144, 
    0x7, 0x18, 0x2, 0x2, 0x144, 0x149, 0x5, 0xc, 0x7, 0x2, 0x145, 0x146, 
    0x7, 0x4b, 0x2, 0x2, 0x146, 0x148, 0x5, 0xc, 0x7, 0x2, 0x147, 0x145, 
    0x3, 0x2, 0x2, 0x2, 0x148, 0x14b, 0x3, 0x2, 0x2, 0x2, 0x149, 0x147, 
    0x3, 0x2, 0x2, 0x2, 0x149, 0x14a, 0x3, 0x2, 0x2, 0x2, 0x14a, 0x14c, 
    0x3, 0x2, 0x2, 0x2, 0x14b, 0x149, 0x3, 0x2, 0x2, 0x2, 0x14c, 0x14d, 
    0x7, 0x42, 0x2, 0x2, 0x14d, 0xb, 0x3, 0x2, 0x2, 0x2, 0x14e, 0x150, 0x7, 
    0x19, 0x2, 0x2, 0x14f, 0x14e, 0x3, 0x2, 0x2, 0x2, 0x14f, 0x150, 0x3, 
    0x2, 0x2, 0x2, 0x150, 0x151, 0x3, 0x2, 0x2, 0x2, 0x151, 0x152, 0x5, 
    0x4, 0x3, 0x2, 0x152, 0xd, 0x3, 0x2, 0x2, 0x2, 0x153, 0x155, 0x7, 0x1e, 
    0x2, 0x2, 0x154, 0x153, 0x3, 0x2, 0x2, 0x2, 0x154, 0x155, 0x3, 0x2, 
    0x2, 0x2, 0x155, 0x156, 0x3, 0x2, 0x2, 0x2, 0x156, 0x157, 0x7, 0x1a, 
    0x2, 0x2, 0x157, 0x159, 0x7, 0xbe, 0x2, 0x2, 0x158, 0x15a, 0x5, 0x84, 
    0x43, 0x2, 0x159, 0x158, 0x3, 0x2, 0x2, 0x2, 0x159, 0x15a, 0x3, 0x2, 
    0x2, 0x2, 0x15a, 0x15d, 0x3, 0x2, 0x2, 0x2, 0x15b, 0x15c, 0x7, 0x1f, 
    0x2, 0x2, 0x15c, 0x15e, 0x5, 0x4, 0x3, 0x2, 0x15d, 0x15b, 0x3, 0x2, 
    0x2, 0x2, 0x15d, 0x15e, 0x3, 0x2, 0x2, 0x2, 0x15e, 0x15f, 0x3, 0x2, 
    0x2, 0x2, 0x15f, 0x166, 0x7, 0x43, 0x2, 0x2, 0x160, 0x161, 0x7, 0x20, 
    0x2, 0x2, 0x161, 0x162, 0x7, 0x21, 0x2, 0x2, 0x162, 0x163, 0x7, 0x1d, 
    0x2, 0x2, 0x163, 0x164, 0x5, 0x4, 0x3, 0x2, 0x164, 0x165, 0x7, 0x42, 
    0x2, 0x2, 0x165, 0x167, 0x3, 0x2, 0x2, 0x2, 0x166, 0x160, 0x3, 0x2, 
    0x2, 0x2, 0x166, 0x167, 0x3, 0x2, 0x2, 0x2, 0x167, 0x16d, 0x3, 0x2, 
    0x2, 0x2, 0x168, 0x169, 0x7, 0x21, 0x2, 0x2, 0x169, 0x16a, 0x7, 0x1d, 
    0x2, 0x2, 0x16a, 0x16b, 0x5, 0x4, 0x3, 0x2, 0x16b, 0x16c, 0x7, 0x42, 
    0x2, 0x2, 0x16c, 0x16e, 0x3, 0x2, 0x2, 0x2, 0x16d, 0x168, 0x3, 0x2, 
    0x2, 0x2, 0x16d, 0x16e, 0x3, 0x2, 0x2, 0x2, 0x16e, 0x17d, 0x3, 0x2, 
    0x2, 0x2, 0x16f, 0x170, 0x7, 0x1b, 0x2, 0x2, 0x170, 0x171, 0x7, 0x1c, 
    0x2, 0x2, 0x171, 0x176, 0x5, 0x4, 0x3, 0x2, 0x172, 0x173, 0x7, 0x4b, 
    0x2, 0x2, 0x173, 0x175, 0x5, 0x4, 0x3, 0x2, 0x174, 0x172, 0x3, 0x2, 
    0x2, 0x2, 0x175, 0x178, 0x3, 0x2, 0x2, 0x2, 0x176, 0x174, 0x3, 0x2, 
    0x2, 0x2, 0x176, 0x177, 0x3, 0x2, 0x2, 0x2, 0x177, 0x179, 0x3, 0x2, 
    0x2, 0x2, 0x178, 0x176, 0x3, 0x2, 0x2, 0x2, 0x179, 0x17a, 0x7, 0x42, 
    0x2, 0x2, 0x17a, 0x17c, 0x3, 0x2, 0x2, 0x2, 0x17b, 0x16f, 0x3, 0x2, 
    0x2, 0x2, 0x17c, 0x17f, 0x3, 0x2, 0x2, 0x2, 0x17d, 0x17b, 0x3, 0x2, 
    0x2, 0x2, 0x17d, 0x17e, 0x3, 0x2, 0x2, 0x2, 0x17e, 0x18d, 0x3, 0x2, 
    0x2, 0x2, 0x17f, 0x17d, 0x3, 0x2, 0x2, 0x2, 0x180, 0x181, 0x6, 0x8, 
    0x6, 0x2, 0x181, 0x182, 0x7, 0x57, 0x2, 0x2, 0x182, 0x183, 0x7, 0x56, 
    0x2, 0x2, 0x183, 0x188, 0x5, 0x4, 0x3, 0x2, 0x184, 0x185, 0x7, 0x4b, 
    0x2, 0x2, 0x185, 0x187, 0x5, 0x4, 0x3, 0x2, 0x186, 0x184, 0x3, 0x2, 
    0x2, 0x2, 0x187, 0x18a, 0x3, 0x2, 0x2, 0x2, 0x188, 0x186, 0x3, 0x2, 
    0x2, 0x2, 0x188, 0x189, 0x3, 0x2, 0x2, 0x2, 0x189, 0x18b, 0x3, 0x2, 
    0x2, 0x2, 0x18a, 0x188, 0x3, 0x2, 0x2, 0x2, 0x18b, 0x18c, 0x7, 0x42, 
    0x2, 0x2, 0x18c, 0x18e, 0x3, 0x2, 0x2, 0x2, 0x18d, 0x180, 0x3, 0x2, 
    0x2, 0x2, 0x18d, 0x18e, 0x3, 0x2, 0x2, 0x2, 0x18e, 0x19b, 0x3, 0x2, 
    0x2, 0x2, 0x18f, 0x19a, 0x5, 0x7c, 0x3f, 0x2, 0x190, 0x19a, 0x5, 0x74, 
    0x3b, 0x2, 0x191, 0x19a, 0x5, 0xb8, 0x5d, 0x2, 0x192, 0x19a, 0x5, 0x2c, 
    0x17, 0x2, 0x193, 0x19a, 0x5, 0x10, 0x9, 0x2, 0x194, 0x19a, 0x5, 0x12, 
    0xa, 0x2, 0x195, 0x19a, 0x5, 0x24, 0x13, 0x2, 0x196, 0x19a, 0x5, 0x9a, 
    0x4e, 0x2, 0x197, 0x19a, 0x5, 0xbe, 0x60, 0x2, 0x198, 0x19a, 0x5, 0xd4, 
    0x6b, 0x2, 0x199, 0x18f, 0x3, 0x2, 0x2, 0x2, 0x199, 0x190, 0x3, 0x2, 
    0x2, 0x2, 0x199, 0x191, 0x3, 0x2, 0x2, 0x2, 0x199, 0x192, 0x3, 0x2, 
    0x2, 0x2, 0x199, 0x193, 0x3, 0x2, 0x2, 0x2, 0x199, 0x194, 0x3, 0x2, 
    0x2, 0x2, 0x199, 0x195, 0x3, 0x2, 0x2, 0x2, 0x199, 0x196, 0x3, 0x2, 
    0x2, 0x2, 0x199, 0x197, 0x3, 0x2, 0x2, 0x2, 0x199, 0x198, 0x3, 0x2, 
    0x2, 0x2, 0x19a, 0x19d, 0x3, 0x2, 0x2, 0x2, 0x19b, 0x199, 0x3, 0x2, 
    0x2, 0x2, 0x19b, 0x19c, 0x3, 0x2, 0x2, 0x2, 0x19c, 0x19e, 0x3, 0x2, 
    0x2, 0x2, 0x19d, 0x19b, 0x3, 0x2, 0x2, 0x2, 0x19e, 0x19f, 0x7, 0x10, 
    0x2, 0x2, 0x19f, 0x1a0, 0x7, 0xbe, 0x2, 0x2, 0x1a0, 0x1a1, 0x7, 0x42, 
    0x2, 0x2, 0x1a1, 0xf, 0x3, 0x2, 0x2, 0x2, 0x1a2, 0x1a3, 0x7, 0x22, 0x2, 
    0x2, 0x1a3, 0x1a5, 0x7, 0xbe, 0x2, 0x2, 0x1a4, 0x1a6, 0x5, 0x84, 0x43, 
    0x2, 0x1a5, 0x1a4, 0x3, 0x2, 0x2, 0x2, 0x1a5, 0x1a6, 0x3, 0x2, 0x2, 
    0x2, 0x1a6, 0x1a9, 0x3, 0x2, 0x2, 0x2, 0x1a7, 0x1a8, 0x7, 0x1f, 0x2, 
    0x2, 0x1a8, 0x1aa, 0x5, 0x4, 0x3, 0x2, 0x1a9, 0x1a7, 0x3, 0x2, 0x2, 
    0x2, 0x1a9, 0x1aa, 0x3, 0x2, 0x2, 0x2, 0x1aa, 0x1ab, 0x3, 0x2, 0x2, 
    0x2, 0x1ab, 0x1b4, 0x7, 0x43, 0x2, 0x2, 0x1ac, 0x1ad, 0x7, 0x21, 0x2, 
    0x2, 0x1ad, 0x1ae, 0x7, 0x1d, 0x2, 0x2, 0x1ae, 0x1b2, 0x5, 0x4, 0x3, 
    0x2, 0x1af, 0x1b0, 0x7, 0x29, 0x2, 0x2, 0x1b0, 0x1b2, 0x7, 0x21, 0x2, 
    0x2, 0x1b1, 0x1ac, 0x3, 0x2, 0x2, 0x2, 0x1b1, 0x1af, 0x3, 0x2, 0x2, 
    0x2, 0x1b2, 0x1b3, 0x3, 0x2, 0x2, 0x2, 0x1b3, 0x1b5, 0x7, 0x42, 0x2, 
    0x2, 0x1b4, 0x1b1, 0x3, 0x2, 0x2, 0x2, 0x1b4, 0x1b5, 0x3, 0x2, 0x2, 
    0x2, 0x1b5, 0x1b6, 0x3, 0x2, 0x2, 0x2, 0x1b6, 0x1b7, 0x5, 0x14, 0xb, 
    0x2, 0x1b7, 0x1b8, 0x7, 0x10, 0x2, 0x2, 0x1b8, 0x1b9, 0x7, 0xbe, 0x2, 
    0x2, 0x1b9, 0x1ba, 0x7, 0x42, 0x2, 0x2, 0x1ba, 0x11, 0x3, 0x2, 0x2, 
    0x2, 0x1bb, 0x1bc, 0x7, 0x53, 0x2, 0x2, 0x1bc, 0x1be, 0x7, 0xbe, 0x2, 
    0x2, 0x1bd, 0x1bf, 0x5, 0x84, 0x43, 0x2, 0x1be, 0x1bd, 0x3, 0x2, 0x2, 
    0x2, 0x1be, 0x1bf, 0x3, 0x2, 0x2, 0x2, 0x1bf, 0x1c2, 0x3, 0x2, 0x2, 
    0x2, 0x1c0, 0x1c1, 0x7, 0x1f, 0x2, 0x2, 0x1c1, 0x1c3, 0x5, 0x4, 0x3, 
    0x2, 0x1c2, 0x1c0, 0x3, 0x2, 0x2, 0x2, 0x1c2, 0x1c3, 0x3, 0x2, 0x2, 
    0x2, 0x1c3, 0x1c4, 0x3, 0x2, 0x2, 0x2, 0x1c4, 0x1c5, 0x7, 0x43, 0x2, 
    0x2, 0x1c5, 0x1c6, 0x5, 0x14, 0xb, 0x2, 0x1c6, 0x1c7, 0x7, 0x10, 0x2, 
    0x2, 0x1c7, 0x1c8, 0x7, 0xbe, 0x2, 0x2, 0x1c8, 0x1c9, 0x7, 0x42, 0x2, 
    0x2, 0x1c9, 0x13, 0x3, 0x2, 0x2, 0x2, 0x1ca, 0x1cc, 0x7, 0x2a, 0x2, 
    0x2, 0x1cb, 0x1ca, 0x3, 0x2, 0x2, 0x2, 0x1cb, 0x1cc, 0x3, 0x2, 0x2, 
    0x2, 0x1cc, 0x1d0, 0x3, 0x2, 0x2, 0x2, 0x1cd, 0x1cf, 0x5, 0x16, 0xc, 
    0x2, 0x1ce, 0x1cd, 0x3, 0x2, 0x2, 0x2, 0x1cf, 0x1d2, 0x3, 0x2, 0x2, 
    0x2, 0x1d0, 0x1ce, 0x3, 0x2, 0x2, 0x2, 0x1d0, 0x1d1, 0x3, 0x2, 0x2, 
    0x2, 0x1d1, 0x1d6, 0x3, 0x2, 0x2, 0x2, 0x1d2, 0x1d0, 0x3, 0x2, 0x2, 
    0x2, 0x1d3, 0x1d5, 0x5, 0x88, 0x45, 0x2, 0x1d4, 0x1d3, 0x3, 0x2, 0x2, 
    0x2, 0x1d5, 0x1d8, 0x3, 0x2, 0x2, 0x2, 0x1d6, 0x1d4, 0x3, 0x2, 0x2, 
    0x2, 0x1d6, 0x1d7, 0x3, 0x2, 0x2, 0x2, 0x1d7, 0x1e0, 0x3, 0x2, 0x2, 
    0x2, 0x1d8, 0x1d6, 0x3, 0x2, 0x2, 0x2, 0x1d9, 0x1dd, 0x7, 0x54, 0x2, 
    0x2, 0x1da, 0x1dc, 0x5, 0x82, 0x42, 0x2, 0x1db, 0x1da, 0x3, 0x2, 0x2, 
    0x2, 0x1dc, 0x1df, 0x3, 0x2, 0x2, 0x2, 0x1dd, 0x1db, 0x3, 0x2, 0x2, 
    0x2, 0x1dd, 0x1de, 0x3, 0x2, 0x2, 0x2, 0x1de, 0x1e1, 0x3, 0x2, 0x2, 
    0x2, 0x1df, 0x1dd, 0x3, 0x2, 0x2, 0x2, 0x1e0, 0x1d9, 0x3, 0x2, 0x2, 
    0x2, 0x1e0, 0x1e1, 0x3, 0x2, 0x2, 0x2, 0x1e1, 0x15, 0x3, 0x2, 0x2, 0x2, 
    0x1e2, 0x1e4, 0x7, 0x27, 0x2, 0x2, 0x1e3, 0x1e2, 0x3, 0x2, 0x2, 0x2, 
    0x1e3, 0x1e4, 0x3, 0x2, 0x2, 0x2, 0x1e4, 0x1e5, 0x3, 0x2, 0x2, 0x2, 
    0x1e5, 0x1e7, 0x7, 0x28, 0x2, 0x2, 0x1e6, 0x1e3, 0x3, 0x2, 0x2, 0x2, 
    0x1e6, 0x1e7, 0x3, 0x2, 0x2, 0x2, 0x1e7, 0x1e8, 0x3, 0x2, 0x2, 0x2, 
    0x1e8, 0x1ea, 0x7, 0xbe, 0x2, 0x2, 0x1e9, 0x1eb, 0x5, 0x84, 0x43, 0x2, 
    0x1ea, 0x1e9, 0x3, 0x2, 0x2, 0x2, 0x1ea, 0x1eb, 0x3, 0x2, 0x2, 0x2, 
    0x1eb, 0x1ec, 0x3, 0x2, 0x2, 0x2, 0x1ec, 0x1ed, 0x7, 0x4a, 0x2, 0x2, 
    0x1ed, 0x1f7, 0x5, 0x18, 0xd, 0x2, 0x1ee, 0x1ef, 0x7, 0x47, 0x2, 0x2, 
    0x1ef, 0x1f4, 0x5, 0xa8, 0x55, 0x2, 0x1f0, 0x1f1, 0x7, 0x4b, 0x2, 0x2, 
    0x1f1, 0x1f3, 0x5, 0xa8, 0x55, 0x2, 0x1f2, 0x1f0, 0x3, 0x2, 0x2, 0x2, 
    0x1f3, 0x1f6, 0x3, 0x2, 0x2, 0x2, 0x1f4, 0x1f2, 0x3, 0x2, 0x2, 0x2, 
    0x1f4, 0x1f5, 0x3, 0x2, 0x2, 0x2, 0x1f5, 0x1f8, 0x3, 0x2, 0x2, 0x2, 
    0x1f6, 0x1f4, 0x3, 0x2, 0x2, 0x2, 0x1f7, 0x1ee, 0x3, 0x2, 0x2, 0x2, 
    0x1f7, 0x1f8, 0x3, 0x2, 0x2, 0x2, 0x1f8, 0x1f9, 0x3, 0x2, 0x2, 0x2, 
    0x1f9, 0x1fa, 0x7, 0x42, 0x2, 0x2, 0x1fa, 0x17, 0x3, 0x2, 0x2, 0x2, 
    0x1fb, 0x1fd, 0x7, 0x55, 0x2, 0x2, 0x1fc, 0x1fb, 0x3, 0x2, 0x2, 0x2, 
    0x1fc, 0x1fd, 0x3, 0x2, 0x2, 0x2, 0x1fd, 0x1fe, 0x3, 0x2, 0x2, 0x2, 
    0x1fe, 0x201, 0x5, 0x1c, 0xf, 0x2, 0x1ff, 0x201, 0x5, 0x1a, 0xe, 0x2, 
    0x200, 0x1fc, 0x3, 0x2, 0x2, 0x2, 0x200, 0x1ff, 0x3, 0x2, 0x2, 0x2, 
    0x201, 0x19, 0x3, 0x2, 0x2, 0x2, 0x202, 0x204, 0x9, 0x4, 0x2, 0x2, 0x203, 
    0x205, 0x5, 0x2a, 0x16, 0x2, 0x204, 0x203, 0x3, 0x2, 0x2, 0x2, 0x204, 
    0x205, 0x3, 0x2, 0x2, 0x2, 0x205, 0x206, 0x3, 0x2, 0x2, 0x2, 0x206, 
    0x20b, 0x7, 0x14, 0x2, 0x2, 0x207, 0x208, 0x6, 0xe, 0x7, 0x2, 0x208, 
    0x20c, 0x5, 0x20, 0x11, 0x2, 0x209, 0x20a, 0x6, 0xe, 0x8, 0x2, 0x20a, 
    0x20c, 0x5, 0x1c, 0xf, 0x2, 0x20b, 0x207, 0x3, 0x2, 0x2, 0x2, 0x20b, 
    0x209, 0x3, 0x2, 0x2, 0x2, 0x20c, 0x1b, 0x3, 0x2, 0x2, 0x2, 0x20d, 0x212, 
    0x5, 0x30, 0x19, 0x2, 0x20e, 0x212, 0x5, 0x4, 0x3, 0x2, 0x20f, 0x212, 
    0x5, 0x1e, 0x10, 0x2, 0x210, 0x212, 0x5, 0x20, 0x11, 0x2, 0x211, 0x20d, 
    0x3, 0x2, 0x2, 0x2, 0x211, 0x20e, 0x3, 0x2, 0x2, 0x2, 0x211, 0x20f, 
    0x3, 0x2, 0x2, 0x2, 0x211, 0x210, 0x3, 0x2, 0x2, 0x2, 0x212, 0x1d, 0x3, 
    0x2, 0x2, 0x2, 0x213, 0x214, 0x7, 0x5f, 0x2, 0x2, 0x214, 0x218, 0x7, 
    0x60, 0x2, 0x2, 0x215, 0x216, 0x7, 0x2f, 0x2, 0x2, 0x216, 0x217, 0x7, 
    0x65, 0x2, 0x2, 0x217, 0x219, 0x7, 0x30, 0x2, 0x2, 0x218, 0x215, 0x3, 
    0x2, 0x2, 0x2, 0x218, 0x219, 0x3, 0x2, 0x2, 0x2, 0x219, 0x21a, 0x3, 
    0x2, 0x2, 0x2, 0x21a, 0x21b, 0x5, 0x20, 0x11, 0x2, 0x21b, 0x1f, 0x3, 
    0x2, 0x2, 0x2, 0x21c, 0x220, 0x5, 0x4, 0x3, 0x2, 0x21d, 0x220, 0x7, 
    0x61, 0x2, 0x2, 0x21e, 0x220, 0x7, 0xb3, 0x2, 0x2, 0x21f, 0x21c, 0x3, 
    0x2, 0x2, 0x2, 0x21f, 0x21d, 0x3, 0x2, 0x2, 0x2, 0x21f, 0x21e, 0x3, 
    0x2, 0x2, 0x2, 0x220, 0x222, 0x3, 0x2, 0x2, 0x2, 0x221, 0x223, 0x5, 
    0x22, 0x12, 0x2, 0x222, 0x221, 0x3, 0x2, 0x2, 0x2, 0x222, 0x223, 0x3, 
    0x2, 0x2, 0x2, 0x223, 0x21, 0x3, 0x2, 0x2, 0x2, 0x224, 0x225, 0x7, 0x62, 
    0x2, 0x2, 0x225, 0x226, 0x7, 0x2f, 0x2, 0x2, 0x226, 0x22b, 0x5, 0x4, 
    0x3, 0x2, 0x227, 0x228, 0x7, 0x4b, 0x2, 0x2, 0x228, 0x22a, 0x5, 0x4, 
    0x3, 0x2, 0x229, 0x227, 0x3, 0x2, 0x2, 0x2, 0x22a, 0x22d, 0x3, 0x2, 
    0x2, 0x2, 0x22b, 0x229, 0x3, 0x2, 0x2, 0x2, 0x22b, 0x22c, 0x3, 0x2, 
    0x2, 0x2, 0x22c, 0x22e, 0x3, 0x2, 0x2, 0x2, 0x22d, 0x22b, 0x3, 0x2, 
    0x2, 0x2, 0x22e, 0x22f, 0x7, 0x30, 0x2, 0x2, 0x22f, 0x23, 0x3, 0x2, 
    0x2, 0x2, 0x230, 0x231, 0x7, 0x63, 0x2, 0x2, 0x231, 0x233, 0x7, 0xbe, 
    0x2, 0x2, 0x232, 0x234, 0x5, 0x84, 0x43, 0x2, 0x233, 0x232, 0x3, 0x2, 
    0x2, 0x2, 0x233, 0x234, 0x3, 0x2, 0x2, 0x2, 0x234, 0x237, 0x3, 0x2, 
    0x2, 0x2, 0x235, 0x236, 0x7, 0x1f, 0x2, 0x2, 0x236, 0x238, 0x5, 0x26, 
    0x14, 0x2, 0x237, 0x235, 0x3, 0x2, 0x2, 0x2, 0x237, 0x238, 0x3, 0x2, 
    0x2, 0x2, 0x238, 0x23c, 0x3, 0x2, 0x2, 0x2, 0x239, 0x23a, 0x7, 0x64, 
    0x2, 0x2, 0x23a, 0x23b, 0x7, 0x66, 0x2, 0x2, 0x23b, 0x23d, 0x5, 0xcc, 
    0x67, 0x2, 0x23c, 0x239, 0x3, 0x2, 0x2, 0x2, 0x23c, 0x23d, 0x3, 0x2, 
    0x2, 0x2, 0x23d, 0x23e, 0x3, 0x2, 0x2, 0x2, 0x23e, 0x247, 0x7, 0x43, 
    0x2, 0x2, 0x23f, 0x240, 0x7, 0x21, 0x2, 0x2, 0x240, 0x241, 0x7, 0x1d, 
    0x2, 0x2, 0x241, 0x245, 0x5, 0x4, 0x3, 0x2, 0x242, 0x243, 0x7, 0x29, 
    0x2, 0x2, 0x243, 0x245, 0x7, 0x21, 0x2, 0x2, 0x244, 0x23f, 0x3, 0x2, 
    0x2, 0x2, 0x244, 0x242, 0x3, 0x2, 0x2, 0x2, 0x245, 0x246, 0x3, 0x2, 
    0x2, 0x2, 0x246, 0x248, 0x7, 0x42, 0x2, 0x2, 0x247, 0x244, 0x3, 0x2, 
    0x2, 0x2, 0x247, 0x248, 0x3, 0x2, 0x2, 0x2, 0x248, 0x24c, 0x3, 0x2, 
    0x2, 0x2, 0x249, 0x24b, 0x5, 0x28, 0x15, 0x2, 0x24a, 0x249, 0x3, 0x2, 
    0x2, 0x2, 0x24b, 0x24e, 0x3, 0x2, 0x2, 0x2, 0x24c, 0x24a, 0x3, 0x2, 
    0x2, 0x2, 0x24c, 0x24d, 0x3, 0x2, 0x2, 0x2, 0x24d, 0x250, 0x3, 0x2, 
    0x2, 0x2, 0x24e, 0x24c, 0x3, 0x2, 0x2, 0x2, 0x24f, 0x251, 0x7, 0x2a, 
    0x2, 0x2, 0x250, 0x24f, 0x3, 0x2, 0x2, 0x2, 0x250, 0x251, 0x3, 0x2, 
    0x2, 0x2, 0x251, 0x255, 0x3, 0x2, 0x2, 0x2, 0x252, 0x254, 0x5, 0x16, 
    0xc, 0x2, 0x253, 0x252, 0x3, 0x2, 0x2, 0x2, 0x254, 0x257, 0x3, 0x2, 
    0x2, 0x2, 0x255, 0x253, 0x3, 0x2, 0x2, 0x2, 0x255, 0x256, 0x3, 0x2, 
    0x2, 0x2, 0x256, 0x25d, 0x3, 0x2, 0x2, 0x2, 0x257, 0x255, 0x3, 0x2, 
    0x2, 0x2, 0x258, 0x259, 0x7, 0x6f, 0x2, 0x2, 0x259, 0x25a, 0x7, 0x43, 
    0x2, 0x2, 0x25a, 0x25b, 0x5, 0x2a, 0x16, 0x2, 0x25b, 0x25c, 0x7, 0x42, 
    0x2, 0x2, 0x25c, 0x25e, 0x3, 0x2, 0x2, 0x2, 0x25d, 0x258, 0x3, 0x2, 
    0x2, 0x2, 0x25d, 0x25e, 0x3, 0x2, 0x2, 0x2, 0x25e, 0x262, 0x3, 0x2, 
    0x2, 0x2, 0x25f, 0x261, 0x5, 0x88, 0x45, 0x2, 0x260, 0x25f, 0x3, 0x2, 
    0x2, 0x2, 0x261, 0x264, 0x3, 0x2, 0x2, 0x2, 0x262, 0x260, 0x3, 0x2, 
    0x2, 0x2, 0x262, 0x263, 0x3, 0x2, 0x2, 0x2, 0x263, 0x265, 0x3, 0x2, 
    0x2, 0x2, 0x264, 0x262, 0x3, 0x2, 0x2, 0x2, 0x265, 0x266, 0x7, 0x10, 
    0x2, 0x2, 0x266, 0x267, 0x7, 0xbe, 0x2, 0x2, 0x267, 0x268, 0x7, 0x42, 
    0x2, 0x2, 0x268, 0x25, 0x3, 0x2, 0x2, 0x2, 0x269, 0x26a, 0x7, 0xbe, 
    0x2, 0x2, 0x26a, 0x26c, 0x7, 0x48, 0x2, 0x2, 0x26b, 0x269, 0x3, 0x2, 
    0x2, 0x2, 0x26b, 0x26c, 0x3, 0x2, 0x2, 0x2, 0x26c, 0x26d, 0x3, 0x2, 
    0x2, 0x2, 0x26d, 0x26e, 0x7, 0xbe, 0x2, 0x2, 0x26e, 0x270, 0x7, 0x48, 
    0x2, 0x2, 0x26f, 0x26b, 0x3, 0x2, 0x2, 0x2, 0x26f, 0x270, 0x3, 0x2, 
    0x2, 0x2, 0x270, 0x271, 0x3, 0x2, 0x2, 0x2, 0x271, 0x272, 0x7, 0xbe, 
    0x2, 0x2, 0x272, 0x27, 0x3, 0x2, 0x2, 0x2, 0x273, 0x275, 0x7, 0xbe, 
    0x2, 0x2, 0x274, 0x276, 0x5, 0x84, 0x43, 0x2, 0x275, 0x274, 0x3, 0x2, 
    0x2, 0x2, 0x275, 0x276, 0x3, 0x2, 0x2, 0x2, 0x276, 0x277, 0x3, 0x2, 
    0x2, 0x2, 0x277, 0x279, 0x9, 0x5, 0x2, 0x2, 0x278, 0x27a, 0x5, 0x2a, 
    0x16, 0x2, 0x279, 0x278, 0x3, 0x2, 0x2, 0x2, 0x279, 0x27a, 0x3, 0x2, 
    0x2, 0x2, 0x27a, 0x27b, 0x3, 0x2, 0x2, 0x2, 0x27b, 0x280, 0x5, 0x20, 
    0x11, 0x2, 0x27c, 0x27d, 0x7, 0x70, 0x2, 0x2, 0x27d, 0x27f, 0x5, 0x20, 
    0x11, 0x2, 0x27e, 0x27c, 0x3, 0x2, 0x2, 0x2, 0x27f, 0x282, 0x3, 0x2, 
    0x2, 0x2, 0x280, 0x27e, 0x3, 0x2, 0x2, 0x2, 0x280, 0x281, 0x3, 0x2, 
    0x2, 0x2, 0x281, 0x285, 0x3, 0x2, 0x2, 0x2, 0x282, 0x280, 0x3, 0x2, 
    0x2, 0x2, 0x283, 0x284, 0x7, 0x47, 0x2, 0x2, 0x284, 0x286, 0x5, 0xa8, 
    0x55, 0x2, 0x285, 0x283, 0x3, 0x2, 0x2, 0x2, 0x285, 0x286, 0x3, 0x2, 
    0x2, 0x2, 0x286, 0x287, 0x3, 0x2, 0x2, 0x2, 0x287, 0x288, 0x7, 0x42, 
    0x2, 0x2, 0x288, 0x29, 0x3, 0x2, 0x2, 0x2, 0x289, 0x293, 0x7, 0x33, 
    0x2, 0x2, 0x28a, 0x294, 0x7, 0x35, 0x2, 0x2, 0x28b, 0x291, 0x7, 0xb8, 
    0x2, 0x2, 0x28c, 0x28f, 0x7, 0x49, 0x2, 0x2, 0x28d, 0x290, 0x7, 0xb8, 
    0x2, 0x2, 0x28e, 0x290, 0x7, 0x35, 0x2, 0x2, 0x28f, 0x28d, 0x3, 0x2, 
    0x2, 0x2, 0x28f, 0x28e, 0x3, 0x2, 0x2, 0x2, 0x290, 0x292, 0x3, 0x2, 
    0x2, 0x2, 0x291, 0x28c, 0x3, 0x2, 0x2, 0x2, 0x291, 0x292, 0x3, 0x2, 
    0x2, 0x2, 0x292, 0x294, 0x3, 0x2, 0x2, 0x2, 0x293, 0x28a, 0x3, 0x2, 
    0x2, 0x2, 0x293, 0x28b, 0x3, 0x2, 0x2, 0x2, 0x294, 0x295, 0x3, 0x2, 
    0x2, 0x2, 0x295, 0x296, 0x7, 0x34, 0x2, 0x2, 0x296, 0x2b, 0x3, 0x2, 
    0x2, 0x2, 0x297, 0x29b, 0x7, 0x73, 0x2, 0x2, 0x298, 0x29a, 0x5, 0x2e, 
    0x18, 0x2, 0x299, 0x298, 0x3, 0x2, 0x2, 0x2, 0x29a, 0x29d, 0x3, 0x2, 
    0x2, 0x2, 0x29b, 0x299, 0x3, 0x2, 0x2, 0x2, 0x29b, 0x29c, 0x3, 0x2, 
    0x2, 0x2, 0x29c, 0x2d, 0x3, 0x2, 0x2, 0x2, 0x29d, 0x29b, 0x3, 0x2, 0x2, 
    0x2, 0x29e, 0x2a0, 0x7, 0xbe, 0x2, 0x2, 0x29f, 0x2a1, 0x5, 0x84, 0x43, 
    0x2, 0x2a0, 0x29f, 0x3, 0x2, 0x2, 0x2, 0x2a0, 0x2a1, 0x3, 0x2, 0x2, 
    0x2, 0x2a1, 0x2a4, 0x3, 0x2, 0x2, 0x2, 0x2a2, 0x2a3, 0x7, 0x1f, 0x2, 
    0x2, 0x2a3, 0x2a5, 0x5, 0x4, 0x3, 0x2, 0x2a4, 0x2a2, 0x3, 0x2, 0x2, 
    0x2, 0x2a4, 0x2a5, 0x3, 0x2, 0x2, 0x2, 0x2a5, 0x2a6, 0x3, 0x2, 0x2, 
    0x2, 0x2a6, 0x2ac, 0x7, 0x43, 0x2, 0x2, 0x2a7, 0x2a9, 0x7, 0x55, 0x2, 
    0x2, 0x2a8, 0x2aa, 0x5, 0x30, 0x19, 0x2, 0x2a9, 0x2a8, 0x3, 0x2, 0x2, 
    0x2, 0x2a9, 0x2aa, 0x3, 0x2, 0x2, 0x2, 0x2aa, 0x2ad, 0x3, 0x2, 0x2, 
    0x2, 0x2ab, 0x2ad, 0x5, 0x30, 0x19, 0x2, 0x2ac, 0x2a7, 0x3, 0x2, 0x2, 
    0x2, 0x2ac, 0x2ab, 0x3, 0x2, 0x2, 0x2, 0x2ad, 0x2bc, 0x3, 0x2, 0x2, 
    0x2, 0x2ae, 0x2af, 0x6, 0x18, 0x9, 0x2, 0x2af, 0x2b0, 0x7, 0x91, 0x2, 
    0x2, 0x2b0, 0x2b1, 0x7, 0xbe, 0x2, 0x2, 0x2b1, 0x2b2, 0x7, 0x4a, 0x2, 
    0x2, 0x2b2, 0x2b9, 0x5, 0x9c, 0x4f, 0x2, 0x2b3, 0x2b4, 0x7, 0x4b, 0x2, 
    0x2, 0x2b4, 0x2b5, 0x7, 0xbe, 0x2, 0x2, 0x2b5, 0x2b6, 0x7, 0x4a, 0x2, 
    0x2, 0x2b6, 0x2b8, 0x5, 0x9c, 0x4f, 0x2, 0x2b7, 0x2b3, 0x3, 0x2, 0x2, 
    0x2, 0x2b8, 0x2bb, 0x3, 0x2, 0x2, 0x2, 0x2b9, 0x2b7, 0x3, 0x2, 0x2, 
    0x2, 0x2b9, 0x2ba, 0x3, 0x2, 0x2, 0x2, 0x2ba, 0x2bd, 0x3, 0x2, 0x2, 
    0x2, 0x2bb, 0x2b9, 0x3, 0x2, 0x2, 0x2, 0x2bc, 0x2ae, 0x3, 0x2, 0x2, 
    0x2, 0x2bc, 0x2bd, 0x3, 0x2, 0x2, 0x2, 0x2bd, 0x2be, 0x3, 0x2, 0x2, 
    0x2, 0x2be, 0x2bf, 0x7, 0x42, 0x2, 0x2, 0x2bf, 0x2f, 0x3, 0x2, 0x2, 
    0x2, 0x2c0, 0x2c3, 0x5, 0x32, 0x1a, 0x2, 0x2c1, 0x2c3, 0x5, 0x6a, 0x36, 
    0x2, 0x2c2, 0x2c0, 0x3, 0x2, 0x2, 0x2, 0x2c2, 0x2c1, 0x3, 0x2, 0x2, 
    0x2, 0x2c3, 0x31, 0x3, 0x2, 0x2, 0x2, 0x2c4, 0x2d1, 0x5, 0x36, 0x1c, 
    0x2, 0x2c5, 0x2d1, 0x5, 0x3a, 0x1e, 0x2, 0x2c6, 0x2d1, 0x5, 0x3c, 0x1f, 
    0x2, 0x2c7, 0x2d1, 0x5, 0x44, 0x23, 0x2, 0x2c8, 0x2d1, 0x5, 0x4e, 0x28, 
    0x2, 0x2c9, 0x2ca, 0x6, 0x1a, 0xa, 0x2, 0x2ca, 0x2d1, 0x5, 0x46, 0x24, 
    0x2, 0x2cb, 0x2d1, 0x5, 0x5a, 0x2e, 0x2, 0x2cc, 0x2d1, 0x5, 0x5e, 0x30, 
    0x2, 0x2cd, 0x2d1, 0x5, 0x60, 0x31, 0x2, 0x2ce, 0x2d1, 0x5, 0x62, 0x32, 
    0x2, 0x2cf, 0x2d1, 0x5, 0x64, 0x33, 0x2, 0x2d0, 0x2c4, 0x3, 0x2, 0x2, 
    0x2, 0x2d0, 0x2c5, 0x3, 0x2, 0x2, 0x2, 0x2d0, 0x2c6, 0x3, 0x2, 0x2, 
    0x2, 0x2d0, 0x2c7, 0x3, 0x2, 0x2, 0x2, 0x2d0, 0x2c8, 0x3, 0x2, 0x2, 
    0x2, 0x2d0, 0x2c9, 0x3, 0x2, 0x2, 0x2, 0x2d0, 0x2cb, 0x3, 0x2, 0x2, 
    0x2, 0x2d0, 0x2cc, 0x3, 0x2, 0x2, 0x2, 0x2d0, 0x2cd, 0x3, 0x2, 0x2, 
    0x2, 0x2d0, 0x2ce, 0x3, 0x2, 0x2, 0x2, 0x2d0, 0x2cf, 0x3, 0x2, 0x2, 
    0x2, 0x2d1, 0x33, 0x3, 0x2, 0x2, 0x2, 0x2d2, 0x2da, 0x7, 0x67, 0x2, 
    0x2, 0x2d3, 0x2da, 0x5, 0x4c, 0x27, 0x2, 0x2d4, 0x2da, 0x5, 0x38, 0x1d, 
    0x2, 0x2d5, 0x2da, 0x5, 0x54, 0x2b, 0x2, 0x2d6, 0x2da, 0x5, 0x42, 0x22, 
    0x2, 0x2d7, 0x2da, 0x5, 0x66, 0x34, 0x2, 0x2d8, 0x2da, 0x5, 0x68, 0x35, 
    0x2, 0x2d9, 0x2d2, 0x3, 0x2, 0x2, 0x2, 0x2d9, 0x2d3, 0x3, 0x2, 0x2, 
    0x2, 0x2d9, 0x2d4, 0x3, 0x2, 0x2, 0x2, 0x2d9, 0x2d5, 0x3, 0x2, 0x2, 
    0x2, 0x2d9, 0x2d6, 0x3, 0x2, 0x2, 0x2, 0x2d9, 0x2d7, 0x3, 0x2, 0x2, 
    0x2, 0x2d9, 0x2d8, 0x3, 0x2, 0x2, 0x2, 0x2da, 0x35, 0x3, 0x2, 0x2, 0x2, 
    0x2db, 0x2de, 0x7, 0x68, 0x2, 0x2, 0x2dc, 0x2dd, 0x7, 0x35, 0x2, 0x2, 
    0x2dd, 0x2df, 0x7, 0xb8, 0x2, 0x2, 0x2de, 0x2dc, 0x3, 0x2, 0x2, 0x2, 
    0x2de, 0x2df, 0x3, 0x2, 0x2, 0x2, 0x2df, 0x2e6, 0x3, 0x2, 0x2, 0x2, 
    0x2e0, 0x2e3, 0x7, 0x2b, 0x2, 0x2, 0x2e1, 0x2e2, 0x7, 0x35, 0x2, 0x2, 
    0x2e2, 0x2e4, 0x7, 0xb8, 0x2, 0x2, 0x2e3, 0x2e1, 0x3, 0x2, 0x2, 0x2, 
    0x2e3, 0x2e4, 0x3, 0x2, 0x2, 0x2, 0x2e4, 0x2e6, 0x3, 0x2, 0x2, 0x2, 
    0x2e5, 0x2db, 0x3, 0x2, 0x2, 0x2, 0x2e5, 0x2e0, 0x3, 0x2, 0x2, 0x2, 
    0x2e6, 0x37, 0x3, 0x2, 0x2, 0x2, 0x2e7, 0x2e8, 0x7, 0xb7, 0x2, 0x2, 
    0x2e8, 0x39, 0x3, 0x2, 0x2, 0x2, 0x2e9, 0x2eb, 0x5, 0x3e, 0x20, 0x2, 
    0x2ea, 0x2ec, 0x9, 0x6, 0x2, 0x2, 0x2eb, 0x2ea, 0x3, 0x2, 0x2, 0x2, 
    0x2eb, 0x2ec, 0x3, 0x2, 0x2, 0x2, 0x2ec, 0x3b, 0x3, 0x2, 0x2, 0x2, 0x2ed, 
    0x2ee, 0x7, 0x69, 0x2, 0x2, 0x2ee, 0x2ef, 0x7, 0x14, 0x2, 0x2, 0x2ef, 
    0x2f0, 0x5, 0x4, 0x3, 0x2, 0x2f0, 0x3d, 0x3, 0x2, 0x2, 0x2, 0x2f1, 0x2f2, 
    0x7, 0x2f, 0x2, 0x2, 0x2f2, 0x2f7, 0x5, 0x40, 0x21, 0x2, 0x2f3, 0x2f4, 
    0x7, 0x4b, 0x2, 0x2, 0x2f4, 0x2f6, 0x5, 0x40, 0x21, 0x2, 0x2f5, 0x2f3, 
    0x3, 0x2, 0x2, 0x2, 0x2f6, 0x2f9, 0x3, 0x2, 0x2, 0x2, 0x2f7, 0x2f5, 
    0x3, 0x2, 0x2, 0x2, 0x2f7, 0x2f8, 0x3, 0x2, 0x2, 0x2, 0x2f8, 0x2ff, 
    0x3, 0x2, 0x2, 0x2, 0x2f9, 0x2f7, 0x3, 0x2, 0x2, 0x2, 0x2fa, 0x2fb, 
    0x7, 0x4a, 0x2, 0x2, 0x2fb, 0x2fd, 0x7, 0x25, 0x2, 0x2, 0x2fc, 0x2fa, 
    0x3, 0x2, 0x2, 0x2, 0x2fc, 0x2fd, 0x3, 0x2, 0x2, 0x2, 0x2fd, 0x300, 
    0x3, 0x2, 0x2, 0x2, 0x2fe, 0x300, 0x7, 0x25, 0x2, 0x2, 0x2ff, 0x2fc, 
    0x3, 0x2, 0x2, 0x2, 0x2ff, 0x2fe, 0x3, 0x2, 0x2, 0x2, 0x2ff, 0x300, 
    0x3, 0x2, 0x2, 0x2, 0x300, 0x301, 0x3, 0x2, 0x2, 0x2, 0x301, 0x302, 
    0x7, 0x30, 0x2, 0x2, 0x302, 0x3f, 0x3, 0x2, 0x2, 0x2, 0x303, 0x308, 
    0x7, 0xbe, 0x2, 0x2, 0x304, 0x305, 0x7, 0x48, 0x2, 0x2, 0x305, 0x307, 
    0x7, 0xbe, 0x2, 0x2, 0x306, 0x304, 0x3, 0x2, 0x2, 0x2, 0x307, 0x30a, 
    0x3, 0x2, 0x2, 0x2, 0x308, 0x306, 0x3, 0x2, 0x2, 0x2, 0x308, 0x309, 
    0x3, 0x2, 0x2, 0x2, 0x309, 0x30c, 0x3, 0x2, 0x2, 0x2, 0x30a, 0x308, 
    0x3, 0x2, 0x2, 0x2, 0x30b, 0x30d, 0x5, 0x3e, 0x20, 0x2, 0x30c, 0x30b, 
    0x3, 0x2, 0x2, 0x2, 0x30c, 0x30d, 0x3, 0x2, 0x2, 0x2, 0x30d, 0x41, 0x3, 
    0x2, 0x2, 0x2, 0x30e, 0x31c, 0x7, 0x3a, 0x2, 0x2, 0x30f, 0x314, 0x7, 
    0xbe, 0x2, 0x2, 0x310, 0x311, 0x7, 0x48, 0x2, 0x2, 0x311, 0x313, 0x7, 
    0xbe, 0x2, 0x2, 0x312, 0x310, 0x3, 0x2, 0x2, 0x2, 0x313, 0x316, 0x3, 
    0x2, 0x2, 0x2, 0x314, 0x312, 0x3, 0x2, 0x2, 0x2, 0x314, 0x315, 0x3, 
    0x2, 0x2, 0x2, 0x315, 0x319, 0x3, 0x2, 0x2, 0x2, 0x316, 0x314, 0x3, 
    0x2, 0x2, 0x2, 0x317, 0x318, 0x7, 0x48, 0x2, 0x2, 0x318, 0x31a, 0x7, 
    0x6b, 0x2, 0x2, 0x319, 0x317, 0x3, 0x2, 0x2, 0x2, 0x319, 0x31a, 0x3, 
    0x2, 0x2, 0x2, 0x31a, 0x31d, 0x3, 0x2, 0x2, 0x2, 0x31b, 0x31d, 0x7, 
    0x6b, 0x2, 0x2, 0x31c, 0x30f, 0x3, 0x2, 0x2, 0x2, 0x31c, 0x31b, 0x3, 
    0x2, 0x2, 0x2, 0x31d, 0x43, 0x3, 0x2, 0x2, 0x2, 0x31e, 0x31f, 0x5, 0x2, 
    0x2, 0x2, 0x31f, 0x320, 0x7, 0x49, 0x2, 0x2, 0x320, 0x321, 0x5, 0x2, 
    0x2, 0x2, 0x321, 0x324, 0x3, 0x2, 0x2, 0x2, 0x322, 0x324, 0x7, 0x6c, 
    0x2, 0x2, 0x323, 0x31e, 0x3, 0x2, 0x2, 0x2, 0x323, 0x322, 0x3, 0x2, 
    0x2, 0x2, 0x324, 0x326, 0x3, 0x2, 0x2, 0x2, 0x325, 0x327, 0x7, 0x6a, 
    0x2, 0x2, 0x326, 0x325, 0x3, 0x2, 0x2, 0x2, 0x326, 0x327, 0x3, 0x2, 
    0x2, 0x2, 0x327, 0x32c, 0x3, 0x2, 0x2, 0x2, 0x328, 0x329, 0x7, 0x31, 
    0x2, 0x2, 0x329, 0x32a, 0x5, 0x4, 0x3, 0x2, 0x32a, 0x32b, 0x7, 0x32, 
    0x2, 0x2, 0x32b, 0x32d, 0x3, 0x2, 0x2, 0x2, 0x32c, 0x328, 0x3, 0x2, 
    0x2, 0x2, 0x32c, 0x32d, 0x3, 0x2, 0x2, 0x2, 0x32d, 0x331, 0x3, 0x2, 
    0x2, 0x2, 0x32e, 0x332, 0x7, 0x6d, 0x2, 0x2, 0x32f, 0x332, 0x7, 0x6e, 
    0x2, 0x2, 0x330, 0x332, 0x5, 0x48, 0x25, 0x2, 0x331, 0x32e, 0x3, 0x2, 
    0x2, 0x2, 0x331, 0x32f, 0x3, 0x2, 0x2, 0x2, 0x331, 0x330, 0x3, 0x2, 
    0x2, 0x2, 0x331, 0x332, 0x3, 0x2, 0x2, 0x2, 0x332, 0x45, 0x3, 0x2, 0x2, 
    0x2, 0x333, 0x334, 0x9, 0x7, 0x2, 0x2, 0x334, 0x47, 0x3, 0x2, 0x2, 0x2, 
    0x335, 0x336, 0x7, 0x33, 0x2, 0x2, 0x336, 0x33a, 0x5, 0x80, 0x41, 0x2, 
    0x337, 0x338, 0x7, 0x31, 0x2, 0x2, 0x338, 0x339, 0x7, 0xb8, 0x2, 0x2, 
    0x339, 0x33b, 0x7, 0x32, 0x2, 0x2, 0x33a, 0x337, 0x3, 0x2, 0x2, 0x2, 
    0x33a, 0x33b, 0x3, 0x2, 0x2, 0x2, 0x33b, 0x33c, 0x3, 0x2, 0x2, 0x2, 
    0x33c, 0x33d, 0x7, 0x34, 0x2, 0x2, 0x33d, 0x348, 0x3, 0x2, 0x2, 0x2, 
    0x33e, 0x33f, 0x7, 0x3c, 0x2, 0x2, 0x33f, 0x343, 0x5, 0x4, 0x3, 0x2, 
    0x340, 0x341, 0x7, 0x31, 0x2, 0x2, 0x341, 0x342, 0x7, 0xb8, 0x2, 0x2, 
    0x342, 0x344, 0x7, 0x32, 0x2, 0x2, 0x343, 0x340, 0x3, 0x2, 0x2, 0x2, 
    0x343, 0x344, 0x3, 0x2, 0x2, 0x2, 0x344, 0x345, 0x3, 0x2, 0x2, 0x2, 
    0x345, 0x346, 0x7, 0x40, 0x2, 0x2, 0x346, 0x348, 0x3, 0x2, 0x2, 0x2, 
    0x347, 0x335, 0x3, 0x2, 0x2, 0x2, 0x347, 0x33e, 0x3, 0x2, 0x2, 0x2, 
    0x348, 0x49, 0x3, 0x2, 0x2, 0x2, 0x349, 0x34d, 0x5, 0x2, 0x2, 0x2, 0x34a, 
    0x34d, 0x7, 0x74, 0x2, 0x2, 0x34b, 0x34d, 0x7, 0x75, 0x2, 0x2, 0x34c, 
    0x349, 0x3, 0x2, 0x2, 0x2, 0x34c, 0x34a, 0x3, 0x2, 0x2, 0x2, 0x34c, 
    0x34b, 0x3, 0x2, 0x2, 0x2, 0x34d, 0x4b, 0x3, 0x2, 0x2, 0x2, 0x34e, 0x353, 
    0x5, 0x4a, 0x26, 0x2, 0x34f, 0x350, 0x7, 0x31, 0x2, 0x2, 0x350, 0x351, 
    0x5, 0x4, 0x3, 0x2, 0x351, 0x352, 0x7, 0x32, 0x2, 0x2, 0x352, 0x354, 
    0x3, 0x2, 0x2, 0x2, 0x353, 0x34f, 0x3, 0x2, 0x2, 0x2, 0x353, 0x354, 
    0x3, 0x2, 0x2, 0x2, 0x354, 0x4d, 0x3, 0x2, 0x2, 0x2, 0x355, 0x356, 0x7, 
    0x76, 0x2, 0x2, 0x356, 0x357, 0x7, 0x9b, 0x2, 0x2, 0x357, 0x358, 0x7, 
    0x1c, 0x2, 0x2, 0x358, 0x359, 0x5, 0x4, 0x3, 0x2, 0x359, 0x35a, 0x5, 
    0x50, 0x29, 0x2, 0x35a, 0x35c, 0x3, 0x2, 0x2, 0x2, 0x35b, 0x355, 0x3, 
    0x2, 0x2, 0x2, 0x35b, 0x35c, 0x3, 0x2, 0x2, 0x2, 0x35c, 0x360, 0x3, 
    0x2, 0x2, 0x2, 0x35d, 0x35e, 0x7, 0xb7, 0x2, 0x2, 0x35e, 0x35f, 0x7, 
    0x49, 0x2, 0x2, 0x35f, 0x361, 0x7, 0xb7, 0x2, 0x2, 0x360, 0x35d, 0x3, 
    0x2, 0x2, 0x2, 0x360, 0x361, 0x3, 0x2, 0x2, 0x2, 0x361, 0x369, 0x3, 
    0x2, 0x2, 0x2, 0x362, 0x363, 0x7, 0x76, 0x2, 0x2, 0x363, 0x364, 0x5, 
    0x4, 0x3, 0x2, 0x364, 0x365, 0x7, 0xb7, 0x2, 0x2, 0x365, 0x366, 0x7, 
    0x49, 0x2, 0x2, 0x366, 0x367, 0x7, 0xb7, 0x2, 0x2, 0x367, 0x369, 0x3, 
    0x2, 0x2, 0x2, 0x368, 0x35b, 0x3, 0x2, 0x2, 0x2, 0x368, 0x362, 0x3, 
    0x2, 0x2, 0x2, 0x369, 0x4f, 0x3, 0x2, 0x2, 0x2, 0x36a, 0x36c, 0x7, 0x2f, 
    0x2, 0x2, 0x36b, 0x36d, 0x7, 0x9d, 0x2, 0x2, 0x36c, 0x36b, 0x3, 0x2, 
    0x2, 0x2, 0x36c, 0x36d, 0x3, 0x2, 0x2, 0x2, 0x36d, 0x36f, 0x3, 0x2, 
    0x2, 0x2, 0x36e, 0x370, 0x7, 0xb7, 0x2, 0x2, 0x36f, 0x36e, 0x3, 0x2, 
    0x2, 0x2, 0x36f, 0x370, 0x3, 0x2, 0x2, 0x2, 0x370, 0x376, 0x3, 0x2, 
    0x2, 0x2, 0x371, 0x372, 0x5, 0x52, 0x2a, 0x2, 0x372, 0x373, 0x7, 0xb7, 
    0x2, 0x2, 0x373, 0x375, 0x3, 0x2, 0x2, 0x2, 0x374, 0x371, 0x3, 0x2, 
    0x2, 0x2, 0x375, 0x378, 0x3, 0x2, 0x2, 0x2, 0x376, 0x374, 0x3, 0x2, 
    0x2, 0x2, 0x376, 0x377, 0x3, 0x2, 0x2, 0x2, 0x377, 0x379, 0x3, 0x2, 
    0x2, 0x2, 0x378, 0x376, 0x3, 0x2, 0x2, 0x2, 0x379, 0x37b, 0x5, 0x52, 
    0x2a, 0x2, 0x37a, 0x37c, 0x7, 0xb7, 0x2, 0x2, 0x37b, 0x37a, 0x3, 0x2, 
    0x2, 0x2, 0x37b, 0x37c, 0x3, 0x2, 0x2, 0x2, 0x37c, 0x37d, 0x3, 0x2, 
    0x2, 0x2, 0x37d, 0x37e, 0x7, 0x30, 0x2, 0x2, 0x37e, 0x51, 0x3, 0x2, 
    0x2, 0x2, 0x37f, 0x382, 0x7, 0xbe, 0x2, 0x2, 0x380, 0x381, 0x7, 0x36, 
    0x2, 0x2, 0x381, 0x383, 0x7, 0xb8, 0x2, 0x2, 0x382, 0x380, 0x3, 0x2, 
    0x2, 0x2, 0x382, 0x383, 0x3, 0x2, 0x2, 0x2, 0x383, 0x388, 0x3, 0x2, 
    0x2, 0x2, 0x384, 0x385, 0x7, 0xbe, 0x2, 0x2, 0x385, 0x386, 0x7, 0x36, 
    0x2, 0x2, 0x386, 0x388, 0x5, 0x4, 0x3, 0x2, 0x387, 0x37f, 0x3, 0x2, 
    0x2, 0x2, 0x387, 0x384, 0x3, 0x2, 0x2, 0x2, 0x388, 0x53, 0x3, 0x2, 0x2, 
    0x2, 0x389, 0x38a, 0x7, 0xb7, 0x2, 0x2, 0x38a, 0x55, 0x3, 0x2, 0x2, 
    0x2, 0x38b, 0x391, 0x7, 0x58, 0x2, 0x2, 0x38c, 0x38d, 0x5, 0x58, 0x2d, 
    0x2, 0x38d, 0x38e, 0x7, 0x42, 0x2, 0x2, 0x38e, 0x390, 0x3, 0x2, 0x2, 
    0x2, 0x38f, 0x38c, 0x3, 0x2, 0x2, 0x2, 0x390, 0x393, 0x3, 0x2, 0x2, 
    0x2, 0x391, 0x38f, 0x3, 0x2, 0x2, 0x2, 0x391, 0x392, 0x3, 0x2, 0x2, 
    0x2, 0x392, 0x57, 0x3, 0x2, 0x2, 0x2, 0x393, 0x391, 0x3, 0x2, 0x2, 0x2, 
    0x394, 0x395, 0x7, 0xbe, 0x2, 0x2, 0x395, 0x396, 0x7, 0x43, 0x2, 0x2, 
    0x396, 0x39b, 0x5, 0x4, 0x3, 0x2, 0x397, 0x398, 0x7, 0x70, 0x2, 0x2, 
    0x398, 0x39a, 0x5, 0x4, 0x3, 0x2, 0x399, 0x397, 0x3, 0x2, 0x2, 0x2, 
    0x39a, 0x39d, 0x3, 0x2, 0x2, 0x2, 0x39b, 0x399, 0x3, 0x2, 0x2, 0x2, 
    0x39b, 0x39c, 0x3, 0x2, 0x2, 0x2, 0x39c, 0x59, 0x3, 0x2, 0x2, 0x2, 0x39d, 
    0x39b, 0x3, 0x2, 0x2, 0x2, 0x39e, 0x39f, 0x6, 0x2e, 0xb, 0x2, 0x39f, 
    0x3a3, 0x7, 0x78, 0x2, 0x2, 0x3a0, 0x3a1, 0x6, 0x2e, 0xc, 0x2, 0x3a1, 
    0x3a3, 0x7, 0x59, 0x2, 0x2, 0x3a2, 0x39e, 0x3, 0x2, 0x2, 0x2, 0x3a2, 
    0x3a0, 0x3, 0x2, 0x2, 0x2, 0x3a3, 0x3a4, 0x3, 0x2, 0x2, 0x2, 0x3a4, 
    0x3ab, 0x5, 0x44, 0x23, 0x2, 0x3a5, 0x3a6, 0x7, 0x4b, 0x2, 0x2, 0x3a6, 
    0x3a9, 0x5, 0x44, 0x23, 0x2, 0x3a7, 0x3a8, 0x7, 0x4b, 0x2, 0x2, 0x3a8, 
    0x3aa, 0x5, 0x44, 0x23, 0x2, 0x3a9, 0x3a7, 0x3, 0x2, 0x2, 0x2, 0x3a9, 
    0x3aa, 0x3, 0x2, 0x2, 0x2, 0x3aa, 0x3ac, 0x3, 0x2, 0x2, 0x2, 0x3ab, 
    0x3a5, 0x3, 0x2, 0x2, 0x2, 0x3ab, 0x3ac, 0x3, 0x2, 0x2, 0x2, 0x3ac, 
    0x3af, 0x3, 0x2, 0x2, 0x2, 0x3ad, 0x3ae, 0x7, 0x4b, 0x2, 0x2, 0x3ae, 
    0x3b0, 0x5, 0x5c, 0x2f, 0x2, 0x3af, 0x3ad, 0x3, 0x2, 0x2, 0x2, 0x3af, 
    0x3b0, 0x3, 0x2, 0x2, 0x2, 0x3b0, 0x5b, 0x3, 0x2, 0x2, 0x2, 0x3b1, 0x3b2, 
    0x7, 0x79, 0x2, 0x2, 0x3b2, 0x3b3, 0x7, 0xb8, 0x2, 0x2, 0x3b3, 0x3b4, 
    0x7, 0x4d, 0x2, 0x2, 0x3b4, 0x3b5, 0x7, 0xb8, 0x2, 0x2, 0x3b5, 0x5d, 
    0x3, 0x2, 0x2, 0x2, 0x3b6, 0x3ba, 0x7, 0x21, 0x2, 0x2, 0x3b7, 0x3bb, 
    0x7, 0x7a, 0x2, 0x2, 0x3b8, 0x3bb, 0x5, 0x44, 0x23, 0x2, 0x3b9, 0x3bb, 
    0x5, 0x36, 0x1c, 0x2, 0x3ba, 0x3b7, 0x3, 0x2, 0x2, 0x2, 0x3ba, 0x3b8, 
    0x3, 0x2, 0x2, 0x2, 0x3ba, 0x3b9, 0x3, 0x2, 0x2, 0x2, 0x3bb, 0x5f, 0x3, 
    0x2, 0x2, 0x2, 0x3bc, 0x3bd, 0x7, 0x7b, 0x2, 0x2, 0x3bd, 0x3be, 0x9, 
    0x8, 0x2, 0x2, 0x3be, 0x61, 0x3, 0x2, 0x2, 0x2, 0x3bf, 0x3c1, 0x7, 0x22, 
    0x2, 0x2, 0x3c0, 0x3c2, 0x5, 0x22, 0x12, 0x2, 0x3c1, 0x3c0, 0x3, 0x2, 
    0x2, 0x2, 0x3c1, 0x3c2, 0x3, 0x2, 0x2, 0x2, 0x3c2, 0x3c8, 0x3, 0x2, 
    0x2, 0x2, 0x3c3, 0x3c5, 0x7, 0x53, 0x2, 0x2, 0x3c4, 0x3c6, 0x5, 0x22, 
    0x12, 0x2, 0x3c5, 0x3c4, 0x3, 0x2, 0x2, 0x2, 0x3c5, 0x3c6, 0x3, 0x2, 
    0x2, 0x2, 0x3c6, 0x3c8, 0x3, 0x2, 0x2, 0x2, 0x3c7, 0x3bf, 0x3, 0x2, 
    0x2, 0x2, 0x3c7, 0x3c3, 0x3, 0x2, 0x2, 0x2, 0x3c8, 0x63, 0x3, 0x2, 0x2, 
    0x2, 0x3c9, 0x3d0, 0x7, 0x2a, 0x2, 0x2, 0x3ca, 0x3ce, 0x7, 0x14, 0x2, 
    0x2, 0x3cb, 0x3cf, 0x5, 0xac, 0x57, 0x2, 0x3cc, 0x3cd, 0x7, 0x15, 0x2, 
    0x2, 0x3cd, 0x3cf, 0x7, 0xbe, 0x2, 0x2, 0x3ce, 0x3cb, 0x3, 0x2, 0x2, 
    0x2, 0x3ce, 0x3cc, 0x3, 0x2, 0x2, 0x2, 0x3cf, 0x3d1, 0x3, 0x2, 0x2, 
    0x2, 0x3d0, 0x3ca, 0x3, 0x2, 0x2, 0x2, 0x3d0, 0x3d1, 0x3, 0x2, 0x2, 
    0x2, 0x3d1, 0x3de, 0x3, 0x2, 0x2, 0x2, 0x3d2, 0x3d3, 0x7, 0x62, 0x2, 
    0x2, 0x3d3, 0x3d4, 0x7, 0x2f, 0x2, 0x2, 0x3d4, 0x3d9, 0x5, 0x18, 0xd, 
    0x2, 0x3d5, 0x3d6, 0x7, 0x4a, 0x2, 0x2, 0x3d6, 0x3d8, 0x5, 0x18, 0xd, 
    0x2, 0x3d7, 0x3d5, 0x3, 0x2, 0x2, 0x2, 0x3d8, 0x3db, 0x3, 0x2, 0x2, 
    0x2, 0x3d9, 0x3d7, 0x3, 0x2, 0x2, 0x2, 0x3d9, 0x3da, 0x3, 0x2, 0x2, 
    0x2, 0x3da, 0x3dc, 0x3, 0x2, 0x2, 0x2, 0x3db, 0x3d9, 0x3, 0x2, 0x2, 
    0x2, 0x3dc, 0x3dd, 0x7, 0x30, 0x2, 0x2, 0x3dd, 0x3df, 0x3, 0x2, 0x2, 
    0x2, 0x3de, 0x3d2, 0x3, 0x2, 0x2, 0x2, 0x3de, 0x3df, 0x3, 0x2, 0x2, 
    0x2, 0x3df, 0x65, 0x3, 0x2, 0x2, 0x2, 0x3e0, 0x3e1, 0x7, 0x40, 0x2, 
    0x2, 0x3e1, 0x3e2, 0x5, 0x4, 0x3, 0x2, 0x3e2, 0x67, 0x3, 0x2, 0x2, 0x2, 
    0x3e3, 0x3e7, 0x7, 0x3f, 0x2, 0x2, 0x3e4, 0x3e5, 0x5, 0x4, 0x3, 0x2, 
    0x3e5, 0x3e6, 0x7, 0x48, 0x2, 0x2, 0x3e6, 0x3e8, 0x3, 0x2, 0x2, 0x2, 
    0x3e7, 0x3e4, 0x3, 0x2, 0x2, 0x2, 0x3e7, 0x3e8, 0x3, 0x2, 0x2, 0x2, 
    0x3e8, 0x3e9, 0x3, 0x2, 0x2, 0x2, 0x3e9, 0x3ea, 0x7, 0xbe, 0x2, 0x2, 
    0x3ea, 0x69, 0x3, 0x2, 0x2, 0x2, 0x3eb, 0x3ed, 0x7, 0x7e, 0x2, 0x2, 
    0x3ec, 0x3eb, 0x3, 0x2, 0x2, 0x2, 0x3ec, 0x3ed, 0x3, 0x2, 0x2, 0x2, 
    0x3ed, 0x3ee, 0x3, 0x2, 0x2, 0x2, 0x3ee, 0x3f2, 0x7, 0x7f, 0x2, 0x2, 
    0x3ef, 0x3f2, 0x7, 0x80, 0x2, 0x2, 0x3f0, 0x3f2, 0x7, 0x81, 0x2, 0x2, 
    0x3f1, 0x3ec, 0x3, 0x2, 0x2, 0x2, 0x3f1, 0x3ef, 0x3, 0x2, 0x2, 0x2, 
    0x3f1, 0x3f0, 0x3, 0x2, 0x2, 0x2, 0x3f2, 0x3fc, 0x3, 0x2, 0x2, 0x2, 
    0x3f3, 0x3fa, 0x6, 0x36, 0xd, 0x2, 0x3f4, 0x3f6, 0x7, 0x7e, 0x2, 0x2, 
    0x3f5, 0x3f4, 0x3, 0x2, 0x2, 0x2, 0x3f5, 0x3f6, 0x3, 0x2, 0x2, 0x2, 
    0x3f6, 0x3f7, 0x3, 0x2, 0x2, 0x2, 0x3f7, 0x3fb, 0x7, 0x5a, 0x2, 0x2, 
    0x3f8, 0x3fb, 0x7, 0x5b, 0x2, 0x2, 0x3f9, 0x3fb, 0x7, 0x5c, 0x2, 0x2, 
    0x3fa, 0x3f5, 0x3, 0x2, 0x2, 0x2, 0x3fa, 0x3f8, 0x3, 0x2, 0x2, 0x2, 
    0x3fa, 0x3f9, 0x3, 0x2, 0x2, 0x2, 0x3fb, 0x3fd, 0x3, 0x2, 0x2, 0x2, 
    0x3fc, 0x3f3, 0x3, 0x2, 0x2, 0x2, 0x3fc, 0x3fd, 0x3, 0x2, 0x2, 0x2, 
    0x3fd, 0x3ff, 0x3, 0x2, 0x2, 0x2, 0x3fe, 0x400, 0x5, 0x6c, 0x37, 0x2, 
    0x3ff, 0x3fe, 0x3, 0x2, 0x2, 0x2, 0x3ff, 0x400, 0x3, 0x2, 0x2, 0x2, 
    0x400, 0x403, 0x3, 0x2, 0x2, 0x2, 0x401, 0x402, 0x7, 0x85, 0x2, 0x2, 
    0x402, 0x404, 0x5, 0x4, 0x3, 0x2, 0x403, 0x401, 0x3, 0x2, 0x2, 0x2, 
    0x403, 0x404, 0x3, 0x2, 0x2, 0x2, 0x404, 0x40b, 0x3, 0x2, 0x2, 0x2, 
    0x405, 0x406, 0x7, 0x86, 0x2, 0x2, 0x406, 0x409, 0x7, 0x87, 0x2, 0x2, 
    0x407, 0x408, 0x7, 0x40, 0x2, 0x2, 0x408, 0x40a, 0x5, 0x2, 0x2, 0x2, 
    0x409, 0x407, 0x3, 0x2, 0x2, 0x2, 0x409, 0x40a, 0x3, 0x2, 0x2, 0x2, 
    0x40a, 0x40c, 0x3, 0x2, 0x2, 0x2, 0x40b, 0x405, 0x3, 0x2, 0x2, 0x2, 
    0x40b, 0x40c, 0x3, 0x2, 0x2, 0x2, 0x40c, 0x410, 0x3, 0x2, 0x2, 0x2, 
    0x40d, 0x40e, 0x7, 0x88, 0x2, 0x2, 0x40e, 0x40f, 0x7, 0x89, 0x2, 0x2, 
    0x40f, 0x411, 0x5, 0x4, 0x3, 0x2, 0x410, 0x40d, 0x3, 0x2, 0x2, 0x2, 
    0x410, 0x411, 0x3, 0x2, 0x2, 0x2, 0x411, 0x6b, 0x3, 0x2, 0x2, 0x2, 0x412, 
    0x413, 0x7, 0x82, 0x2, 0x2, 0x413, 0x414, 0x7, 0x2f, 0x2, 0x2, 0x414, 
    0x419, 0x5, 0x6e, 0x38, 0x2, 0x415, 0x416, 0x7, 0x4b, 0x2, 0x2, 0x416, 
    0x418, 0x5, 0x6e, 0x38, 0x2, 0x417, 0x415, 0x3, 0x2, 0x2, 0x2, 0x418, 
    0x41b, 0x3, 0x2, 0x2, 0x2, 0x419, 0x417, 0x3, 0x2, 0x2, 0x2, 0x419, 
    0x41a, 0x3, 0x2, 0x2, 0x2, 0x41a, 0x41c, 0x3, 0x2, 0x2, 0x2, 0x41b, 
    0x419, 0x3, 0x2, 0x2, 0x2, 0x41c, 0x41d, 0x7, 0x30, 0x2, 0x2, 0x41d, 
    0x6d, 0x3, 0x2, 0x2, 0x2, 0x41e, 0x422, 0x7, 0x83, 0x2, 0x2, 0x41f, 
    0x422, 0x7, 0x84, 0x2, 0x2, 0x420, 0x422, 0x5, 0x4, 0x3, 0x2, 0x421, 
    0x41e, 0x3, 0x2, 0x2, 0x2, 0x421, 0x41f, 0x3, 0x2, 0x2, 0x2, 0x421, 
    0x420, 0x3, 0x2, 0x2, 0x2, 0x422, 0x6f, 0x3, 0x2, 0x2, 0x2, 0x423, 0x424, 
    0x7, 0x88, 0x2, 0x2, 0x424, 0x428, 0x7, 0x8a, 0x2, 0x2, 0x425, 0x427, 
    0x5, 0x72, 0x3a, 0x2, 0x426, 0x425, 0x3, 0x2, 0x2, 0x2, 0x427, 0x42a, 
    0x3, 0x2, 0x2, 0x2, 0x428, 0x426, 0x3, 0x2, 0x2, 0x2, 0x428, 0x429, 
    0x3, 0x2, 0x2, 0x2, 0x429, 0x71, 0x3, 0x2, 0x2, 0x2, 0x42a, 0x428, 0x3, 
    0x2, 0x2, 0x2, 0x42b, 0x42e, 0x7, 0xbe, 0x2, 0x2, 0x42c, 0x42d, 0x7, 
    0x4a, 0x2, 0x2, 0x42d, 0x42f, 0x7, 0xbe, 0x2, 0x2, 0x42e, 0x42c, 0x3, 
    0x2, 0x2, 0x2, 0x42e, 0x42f, 0x3, 0x2, 0x2, 0x2, 0x42f, 0x430, 0x3, 
    0x2, 0x2, 0x2, 0x430, 0x431, 0x7, 0x42, 0x2, 0x2, 0x431, 0x73, 0x3, 
    0x2, 0x2, 0x2, 0x432, 0x436, 0x7, 0x8b, 0x2, 0x2, 0x433, 0x435, 0x5, 
    0x76, 0x3c, 0x2, 0x434, 0x433, 0x3, 0x2, 0x2, 0x2, 0x435, 0x438, 0x3, 
    0x2, 0x2, 0x2, 0x436, 0x434, 0x3, 0x2, 0x2, 0x2, 0x436, 0x437, 0x3, 
    0x2, 0x2, 0x2, 0x437, 0x75, 0x3, 0x2, 0x2, 0x2, 0x438, 0x436, 0x3, 0x2, 
    0x2, 0x2, 0x439, 0x441, 0x7, 0xbe, 0x2, 0x2, 0x43a, 0x43b, 0x7, 0x2f, 
    0x2, 0x2, 0x43b, 0x43c, 0x7, 0x23, 0x2, 0x2, 0x43c, 0x442, 0x7, 0x30, 
    0x2, 0x2, 0x43d, 0x43e, 0x7, 0x31, 0x2, 0x2, 0x43e, 0x43f, 0x5, 0x4, 
    0x3, 0x2, 0x43f, 0x440, 0x7, 0x32, 0x2, 0x2, 0x440, 0x442, 0x3, 0x2, 
    0x2, 0x2, 0x441, 0x43a, 0x3, 0x2, 0x2, 0x2, 0x441, 0x43d, 0x3, 0x2, 
    0x2, 0x2, 0x441, 0x442, 0x3, 0x2, 0x2, 0x2, 0x442, 0x445, 0x3, 0x2, 
    0x2, 0x2, 0x443, 0x444, 0x7, 0x1f, 0x2, 0x2, 0x444, 0x446, 0x5, 0x4, 
    0x3, 0x2, 0x445, 0x443, 0x3, 0x2, 0x2, 0x2, 0x445, 0x446, 0x3, 0x2, 
    0x2, 0x2, 0x446, 0x44c, 0x3, 0x2, 0x2, 0x2, 0x447, 0x44a, 0x7, 0x43, 
    0x2, 0x2, 0x448, 0x44b, 0x5, 0x78, 0x3d, 0x2, 0x449, 0x44b, 0x5, 0x7a, 
    0x3e, 0x2, 0x44a, 0x448, 0x3, 0x2, 0x2, 0x2, 0x44a, 0x449, 0x3, 0x2, 
    0x2, 0x2, 0x44b, 0x44d, 0x3, 0x2, 0x2, 0x2, 0x44c, 0x447, 0x3, 0x2, 
    0x2, 0x2, 0x44c, 0x44d, 0x3, 0x2, 0x2, 0x2, 0x44d, 0x44e, 0x3, 0x2, 
    0x2, 0x2, 0x44e, 0x44f, 0x7, 0x42, 0x2, 0x2, 0x44f, 0x77, 0x3, 0x2, 
    0x2, 0x2, 0x450, 0x455, 0x5, 0x4a, 0x26, 0x2, 0x451, 0x452, 0x9, 0x9, 
    0x2, 0x2, 0x452, 0x454, 0x5, 0x4a, 0x26, 0x2, 0x453, 0x451, 0x3, 0x2, 
    0x2, 0x2, 0x454, 0x457, 0x3, 0x2, 0x2, 0x2, 0x455, 0x453, 0x3, 0x2, 
    0x2, 0x2, 0x455, 0x456, 0x3, 0x2, 0x2, 0x2, 0x456, 0x45b, 0x3, 0x2, 
    0x2, 0x2, 0x457, 0x455, 0x3, 0x2, 0x2, 0x2, 0x458, 0x459, 0x7, 0x8c, 
    0x2, 0x2, 0x459, 0x45b, 0x7, 0xb5, 0x2, 0x2, 0x45a, 0x450, 0x3, 0x2, 
    0x2, 0x2, 0x45a, 0x458, 0x3, 0x2, 0x2, 0x2, 0x45a, 0x45b, 0x3, 0x2, 
    0x2, 0x2, 0x45b, 0x45c, 0x3, 0x2, 0x2, 0x2, 0x45c, 0x45d, 0x7, 0x31, 
    0x2, 0x2, 0x45d, 0x45e, 0x5, 0x4, 0x3, 0x2, 0x45e, 0x45f, 0x7, 0x32, 
    0x2, 0x2, 0x45f, 0x79, 0x3, 0x2, 0x2, 0x2, 0x460, 0x461, 0x7, 0x2f, 
    0x2, 0x2, 0x461, 0x462, 0x5, 0x9c, 0x4f, 0x2, 0x462, 0x463, 0x7, 0x30, 
    0x2, 0x2, 0x463, 0x7b, 0x3, 0x2, 0x2, 0x2, 0x464, 0x465, 0x9, 0xa, 0x2, 
    0x2, 0x465, 0x466, 0x7, 0x20, 0x2, 0x2, 0x466, 0x46a, 0x7, 0xbe, 0x2, 
    0x2, 0x467, 0x468, 0x7, 0x2f, 0x2, 0x2, 0x468, 0x469, 0x7, 0x25, 0x2, 
    0x2, 0x469, 0x46b, 0x7, 0x30, 0x2, 0x2, 0x46a, 0x467, 0x3, 0x2, 0x2, 
    0x2, 0x46a, 0x46b, 0x3, 0x2, 0x2, 0x2, 0x46b, 0x46e, 0x3, 0x2, 0x2, 
    0x2, 0x46c, 0x46d, 0x7, 0x1f, 0x2, 0x2, 0x46d, 0x46f, 0x5, 0x7e, 0x40, 
    0x2, 0x46e, 0x46c, 0x3, 0x2, 0x2, 0x2, 0x46e, 0x46f, 0x3, 0x2, 0x2, 
    0x2, 0x46f, 0x470, 0x3, 0x2, 0x2, 0x2, 0x470, 0x471, 0x7, 0x3b, 0x2, 
    0x2, 0x471, 0x480, 0x5, 0x4, 0x3, 0x2, 0x472, 0x473, 0x7, 0x8e, 0x2, 
    0x2, 0x473, 0x474, 0x7, 0x14, 0x2, 0x2, 0x474, 0x475, 0x7, 0xbe, 0x2, 
    0x2, 0x475, 0x476, 0x7, 0x4a, 0x2, 0x2, 0x476, 0x47b, 0x7, 0xbe, 0x2, 
    0x2, 0x477, 0x478, 0x7, 0x4b, 0x2, 0x2, 0x478, 0x47a, 0x7, 0xbe, 0x2, 
    0x2, 0x479, 0x477, 0x3, 0x2, 0x2, 0x2, 0x47a, 0x47d, 0x3, 0x2, 0x2, 
    0x2, 0x47b, 0x479, 0x3, 0x2, 0x2, 0x2, 0x47b, 0x47c, 0x3, 0x2, 0x2, 
    0x2, 0x47c, 0x47f, 0x3, 0x2, 0x2, 0x2, 0x47d, 0x47b, 0x3, 0x2, 0x2, 
    0x2, 0x47e, 0x472, 0x3, 0x2, 0x2, 0x2, 0x47f, 0x482, 0x3, 0x2, 0x2, 
    0x2, 0x480, 0x47e, 0x3, 0x2, 0x2, 0x2, 0x480, 0x481, 0x3, 0x2, 0x2, 
    0x2, 0x481, 0x483, 0x3, 0x2, 0x2, 0x2, 0x482, 0x480, 0x3, 0x2, 0x2, 
    0x2, 0x483, 0x484, 0x7, 0x42, 0x2, 0x2, 0x484, 0x7d, 0x3, 0x2, 0x2, 
    0x2, 0x485, 0x486, 0x7, 0xbe, 0x2, 0x2, 0x486, 0x488, 0x7, 0x48, 0x2, 
    0x2, 0x487, 0x485, 0x3, 0x2, 0x2, 0x2, 0x487, 0x488, 0x3, 0x2, 0x2, 
    0x2, 0x488, 0x489, 0x3, 0x2, 0x2, 0x2, 0x489, 0x48a, 0x7, 0xbe, 0x2, 
    0x2, 0x48a, 0x48c, 0x7, 0x48, 0x2, 0x2, 0x48b, 0x487, 0x3, 0x2, 0x2, 
    0x2, 0x48b, 0x48c, 0x3, 0x2, 0x2, 0x2, 0x48c, 0x48d, 0x3, 0x2, 0x2, 
    0x2, 0x48d, 0x48e, 0x7, 0xbe, 0x2, 0x2, 0x48e, 0x7f, 0x3, 0x2, 0x2, 
    0x2, 0x48f, 0x490, 0x5, 0x7e, 0x40, 0x2, 0x490, 0x491, 0x7, 0x48, 0x2, 
    0x2, 0x491, 0x493, 0x3, 0x2, 0x2, 0x2, 0x492, 0x48f, 0x3, 0x2, 0x2, 
    0x2, 0x492, 0x493, 0x3, 0x2, 0x2, 0x2, 0x493, 0x494, 0x3, 0x2, 0x2, 
    0x2, 0x494, 0x495, 0x7, 0xbe, 0x2, 0x2, 0x495, 0x81, 0x3, 0x2, 0x2, 
    0x2, 0x496, 0x498, 0x7, 0xbe, 0x2, 0x2, 0x497, 0x499, 0x5, 0x84, 0x43, 
    0x2, 0x498, 0x497, 0x3, 0x2, 0x2, 0x2, 0x498, 0x499, 0x3, 0x2, 0x2, 
    0x2, 0x499, 0x49a, 0x3, 0x2, 0x2, 0x2, 0x49a, 0x4a1, 0x7, 0x4a, 0x2, 
    0x2, 0x49b, 0x4a2, 0x5, 0x18, 0xd, 0x2, 0x49c, 0x49f, 0x7, 0x8f, 0x2, 
    0x2, 0x49d, 0x49e, 0x7, 0x14, 0x2, 0x2, 0x49e, 0x4a0, 0x5, 0x4, 0x3, 
    0x2, 0x49f, 0x49d, 0x3, 0x2, 0x2, 0x2, 0x49f, 0x4a0, 0x3, 0x2, 0x2, 
    0x2, 0x4a0, 0x4a2, 0x3, 0x2, 0x2, 0x2, 0x4a1, 0x49b, 0x3, 0x2, 0x2, 
    0x2, 0x4a1, 0x49c, 0x3, 0x2, 0x2, 0x2, 0x4a2, 0x4a3, 0x3, 0x2, 0x2, 
    0x2, 0x4a3, 0x4a4, 0x7, 0x42, 0x2, 0x2, 0x4a4, 0x83, 0x3, 0x2, 0x2, 
    0x2, 0x4a5, 0x4a6, 0x7, 0x2f, 0x2, 0x2, 0x4a6, 0x4ab, 0x9, 0xb, 0x2, 
    0x2, 0x4a7, 0x4a8, 0x7, 0x4b, 0x2, 0x2, 0x4a8, 0x4aa, 0x9, 0xb, 0x2, 
    0x2, 0x4a9, 0x4a7, 0x3, 0x2, 0x2, 0x2, 0x4aa, 0x4ad, 0x3, 0x2, 0x2, 
    0x2, 0x4ab, 0x4a9, 0x3, 0x2, 0x2, 0x2, 0x4ab, 0x4ac, 0x3, 0x2, 0x2, 
    0x2, 0x4ac, 0x4ae, 0x3, 0x2, 0x2, 0x2, 0x4ad, 0x4ab, 0x3, 0x2, 0x2, 
    0x2, 0x4ae, 0x4af, 0x7, 0x30, 0x2, 0x2, 0x4af, 0x85, 0x3, 0x2, 0x2, 
    0x2, 0x4b0, 0x4b8, 0x7, 0x54, 0x2, 0x2, 0x4b1, 0x4b2, 0x7, 0xbe, 0x2, 
    0x2, 0x4b2, 0x4b3, 0x7, 0x4a, 0x2, 0x2, 0x4b3, 0x4b4, 0x5, 0x18, 0xd, 
    0x2, 0x4b4, 0x4b5, 0x7, 0x42, 0x2, 0x2, 0x4b5, 0x4b7, 0x3, 0x2, 0x2, 
    0x2, 0x4b6, 0x4b1, 0x3, 0x2, 0x2, 0x2, 0x4b7, 0x4ba, 0x3, 0x2, 0x2, 
    0x2, 0x4b8, 0x4b6, 0x3, 0x2, 0x2, 0x2, 0x4b8, 0x4b9, 0x3, 0x2, 0x2, 
    0x2, 0x4b9, 0x87, 0x3, 0x2, 0x2, 0x2, 0x4ba, 0x4b8, 0x3, 0x2, 0x2, 0x2, 
    0x4bb, 0x4c1, 0x5, 0x8a, 0x46, 0x2, 0x4bc, 0x4c1, 0x5, 0x8c, 0x47, 0x2, 
    0x4bd, 0x4c1, 0x5, 0x8e, 0x48, 0x2, 0x4be, 0x4c1, 0x5, 0x90, 0x49, 0x2, 
    0x4bf, 0x4c1, 0x5, 0x98, 0x4d, 0x2, 0x4c0, 0x4bb, 0x3, 0x2, 0x2, 0x2, 
    0x4c0, 0x4bc, 0x3, 0x2, 0x2, 0x2, 0x4c0, 0x4bd, 0x3, 0x2, 0x2, 0x2, 
    0x4c0, 0x4be, 0x3, 0x2, 0x2, 0x2, 0x4c0, 0x4bf, 0x3, 0x2, 0x2, 0x2, 
    0x4c1, 0x89, 0x3, 0x2, 0x2, 0x2, 0x4c2, 0x4c3, 0x7, 0x55, 0x2, 0x2, 
    0x4c3, 0x4c4, 0x7, 0x90, 0x2, 0x2, 0x4c4, 0x4c5, 0x5, 0x9c, 0x4f, 0x2, 
    0x4c5, 0x4c6, 0x7, 0x42, 0x2, 0x2, 0x4c6, 0x8b, 0x3, 0x2, 0x2, 0x2, 
    0x4c7, 0x4c8, 0x7, 0x90, 0x2, 0x2, 0x4c8, 0x4c9, 0x9, 0xc, 0x2, 0x2, 
    0x4c9, 0x4ca, 0x5, 0x2, 0x2, 0x2, 0x4ca, 0x4cb, 0x7, 0x38, 0x2, 0x2, 
    0x4cb, 0x4cc, 0x5, 0x9c, 0x4f, 0x2, 0x4cc, 0x4cd, 0x7, 0x42, 0x2, 0x2, 
    0x4cd, 0x8d, 0x3, 0x2, 0x2, 0x2, 0x4ce, 0x4cf, 0x7, 0x92, 0x2, 0x2, 
    0x4cf, 0x4d0, 0x7, 0x90, 0x2, 0x2, 0x4d0, 0x4d1, 0x5, 0xac, 0x57, 0x2, 
    0x4d1, 0x4d2, 0x7, 0x93, 0x2, 0x2, 0x4d2, 0x4d3, 0x7, 0x94, 0x2, 0x2, 
    0x4d3, 0x4d4, 0x5, 0x4, 0x3, 0x2, 0x4d4, 0x4d5, 0x7, 0x4a, 0x2, 0x2, 
    0x4d5, 0x4dd, 0x5, 0xac, 0x57, 0x2, 0x4d6, 0x4d7, 0x7, 0x70, 0x2, 0x2, 
    0x4d7, 0x4d8, 0x5, 0x4, 0x3, 0x2, 0x4d8, 0x4d9, 0x7, 0x4a, 0x2, 0x2, 
    0x4d9, 0x4da, 0x5, 0xac, 0x57, 0x2, 0x4da, 0x4dc, 0x3, 0x2, 0x2, 0x2, 
    0x4db, 0x4d6, 0x3, 0x2, 0x2, 0x2, 0x4dc, 0x4df, 0x3, 0x2, 0x2, 0x2, 
    0x4dd, 0x4db, 0x3, 0x2, 0x2, 0x2, 0x4dd, 0x4de, 0x3, 0x2, 0x2, 0x2, 
    0x4de, 0x4e0, 0x3, 0x2, 0x2, 0x2, 0x4df, 0x4dd, 0x3, 0x2, 0x2, 0x2, 
    0x4e0, 0x4e1, 0x7, 0x42, 0x2, 0x2, 0x4e1, 0x8f, 0x3, 0x2, 0x2, 0x2, 
    0x4e2, 0x4e7, 0x7, 0x95, 0x2, 0x2, 0x4e3, 0x4e4, 0x7, 0x96, 0x2, 0x2, 
    0x4e4, 0x4e5, 0x5, 0x9c, 0x4f, 0x2, 0x4e5, 0x4e6, 0x7, 0x4a, 0x2, 0x2, 
    0x4e6, 0x4e8, 0x3, 0x2, 0x2, 0x2, 0x4e7, 0x4e3, 0x3, 0x2, 0x2, 0x2, 
    0x4e7, 0x4e8, 0x3, 0x2, 0x2, 0x2, 0x4e8, 0x4eb, 0x3, 0x2, 0x2, 0x2, 
    0x4e9, 0x4ec, 0x5, 0x92, 0x4a, 0x2, 0x4ea, 0x4ec, 0x5, 0x96, 0x4c, 0x2, 
    0x4eb, 0x4e9, 0x3, 0x2, 0x2, 0x2, 0x4eb, 0x4ea, 0x3, 0x2, 0x2, 0x2, 
    0x4ec, 0x4ed, 0x3, 0x2, 0x2, 0x2, 0x4ed, 0x4ee, 0x7, 0x42, 0x2, 0x2, 
    0x4ee, 0x91, 0x3, 0x2, 0x2, 0x2, 0x4ef, 0x4f0, 0x5, 0x94, 0x4b, 0x2, 
    0x4f0, 0x93, 0x3, 0x2, 0x2, 0x2, 0x4f1, 0x4f6, 0x5, 0xaa, 0x56, 0x2, 
    0x4f2, 0x4f3, 0x7, 0x4b, 0x2, 0x2, 0x4f3, 0x4f5, 0x5, 0xaa, 0x56, 0x2, 
    0x4f4, 0x4f2, 0x3, 0x2, 0x2, 0x2, 0x4f5, 0x4f8, 0x3, 0x2, 0x2, 0x2, 
    0x4f6, 0x4f4, 0x3, 0x2, 0x2, 0x2, 0x4f6, 0x4f7, 0x3, 0x2, 0x2, 0x2, 
    0x4f7, 0x95, 0x3, 0x2, 0x2, 0x2, 0x4f8, 0x4f6, 0x3, 0x2, 0x2, 0x2, 0x4f9, 
    0x4fa, 0x7, 0x2f, 0x2, 0x2, 0x4fa, 0x4fb, 0x7, 0x97, 0x2, 0x2, 0x4fb, 
    0x4fc, 0x7, 0x30, 0x2, 0x2, 0x4fc, 0x501, 0x7, 0xbe, 0x2, 0x2, 0x4fd, 
    0x4fe, 0x7, 0x4d, 0x2, 0x2, 0x4fe, 0x500, 0x7, 0xbe, 0x2, 0x2, 0x4ff, 
    0x4fd, 0x3, 0x2, 0x2, 0x2, 0x500, 0x503, 0x3, 0x2, 0x2, 0x2, 0x501, 
    0x4ff, 0x3, 0x2, 0x2, 0x2, 0x501, 0x502, 0x3, 0x2, 0x2, 0x2, 0x502, 
    0x504, 0x3, 0x2, 0x2, 0x2, 0x503, 0x501, 0x3, 0x2, 0x2, 0x2, 0x504, 
    0x505, 0x7, 0x4a, 0x2, 0x2, 0x505, 0x50a, 0x7, 0xbe, 0x2, 0x2, 0x506, 
    0x507, 0x7, 0x4b, 0x2, 0x2, 0x507, 0x509, 0x7, 0xbe, 0x2, 0x2, 0x508, 
    0x506, 0x3, 0x2, 0x2, 0x2, 0x509, 0x50c, 0x3, 0x2, 0x2, 0x2, 0x50a, 
    0x508, 0x3, 0x2, 0x2, 0x2, 0x50a, 0x50b, 0x3, 0x2, 0x2, 0x2, 0x50b, 
    0x97, 0x3, 0x2, 0x2, 0x2, 0x50c, 0x50a, 0x3, 0x2, 0x2, 0x2, 0x50d, 0x50e, 
    0x7, 0x98, 0x2, 0x2, 0x50e, 0x512, 0x7, 0x90, 0x2, 0x2, 0x50f, 0x510, 
    0x6, 0x4d, 0xe, 0x2, 0x510, 0x511, 0x7, 0xbe, 0x2, 0x2, 0x511, 0x513, 
    0x7, 0x4a, 0x2, 0x2, 0x512, 0x50f, 0x3, 0x2, 0x2, 0x2, 0x512, 0x513, 
    0x3, 0x2, 0x2, 0x2, 0x513, 0x518, 0x3, 0x2, 0x2, 0x2, 0x514, 0x515, 
    0x7, 0x96, 0x2, 0x2, 0x515, 0x516, 0x5, 0x9c, 0x4f, 0x2, 0x516, 0x517, 
    0x7, 0x4a, 0x2, 0x2, 0x517, 0x519, 0x3, 0x2, 0x2, 0x2, 0x518, 0x514, 
    0x3, 0x2, 0x2, 0x2, 0x518, 0x519, 0x3, 0x2, 0x2, 0x2, 0x519, 0x51a, 
    0x3, 0x2, 0x2, 0x2, 0x51a, 0x51b, 0x5, 0x9c, 0x4f, 0x2, 0x51b, 0x51c, 
    0x7, 0x42, 0x2, 0x2, 0x51c, 0x99, 0x3, 0x2, 0x2, 0x2, 0x51d, 0x51e, 
    0x7, 0x91, 0x2, 0x2, 0x51e, 0x51f, 0x7, 0x14, 0x2, 0x2, 0x51f, 0x520, 
    0x5, 0x4, 0x3, 0x2, 0x520, 0x524, 0x7, 0x43, 0x2, 0x2, 0x521, 0x523, 
    0x5, 0x88, 0x45, 0x2, 0x522, 0x521, 0x3, 0x2, 0x2, 0x2, 0x523, 0x526, 
    0x3, 0x2, 0x2, 0x2, 0x524, 0x522, 0x3, 0x2, 0x2, 0x2, 0x524, 0x525, 
    0x3, 0x2, 0x2, 0x2, 0x525, 0x527, 0x3, 0x2, 0x2, 0x2, 0x526, 0x524, 
    0x3, 0x2, 0x2, 0x2, 0x527, 0x528, 0x7, 0x10, 0x2, 0x2, 0x528, 0x529, 
    0x7, 0x42, 0x2, 0x2, 0x529, 0x9b, 0x3, 0x2, 0x2, 0x2, 0x52a, 0x52b, 
    0x5, 0x9e, 0x50, 0x2, 0x52b, 0x9d, 0x3, 0x2, 0x2, 0x2, 0x52c, 0x537, 
    0x5, 0xa0, 0x51, 0x2, 0x52d, 0x533, 0x7, 0x70, 0x2, 0x2, 0x52e, 0x52f, 
    0x6, 0x50, 0xf, 0x2, 0x52f, 0x533, 0x7, 0x4e, 0x2, 0x2, 0x530, 0x531, 
    0x6, 0x50, 0x10, 0x2, 0x531, 0x533, 0x7, 0x4f, 0x2, 0x2, 0x532, 0x52d, 
    0x3, 0x2, 0x2, 0x2, 0x532, 0x52e, 0x3, 0x2, 0x2, 0x2, 0x532, 0x530, 
    0x3, 0x2, 0x2, 0x2, 0x533, 0x534, 0x3, 0x2, 0x2, 0x2, 0x534, 0x536, 
    0x5, 0xa0, 0x51, 0x2, 0x535, 0x532, 0x3, 0x2, 0x2, 0x2, 0x536, 0x539, 
    0x3, 0x2, 0x2, 0x2, 0x537, 0x535, 0x3, 0x2, 0x2, 0x2, 0x537, 0x538, 
    0x3, 0x2, 0x2, 0x2, 0x538, 0x9f, 0x3, 0x2, 0x2, 0x2, 0x539, 0x537, 0x3, 
    0x2, 0x2, 0x2, 0x53a, 0x545, 0x5, 0xa2, 0x52, 0x2, 0x53b, 0x541, 0x7, 
    0x99, 0x2, 0x2, 0x53c, 0x53d, 0x6, 0x51, 0x11, 0x2, 0x53d, 0x541, 0x7, 
    0x35, 0x2, 0x2, 0x53e, 0x53f, 0x6, 0x51, 0x12, 0x2, 0x53f, 0x541, 0x7, 
    0x36, 0x2, 0x2, 0x540, 0x53b, 0x3, 0x2, 0x2, 0x2, 0x540, 0x53c, 0x3, 
    0x2, 0x2, 0x2, 0x540, 0x53e, 0x3, 0x2, 0x2, 0x2, 0x541, 0x542, 0x3, 
    0x2, 0x2, 0x2, 0x542, 0x544, 0x5, 0xa2, 0x52, 0x2, 0x543, 0x540, 0x3, 
    0x2, 0x2, 0x2, 0x544, 0x547, 0x3, 0x2, 0x2, 0x2, 0x545, 0x543, 0x3, 
    0x2, 0x2, 0x2, 0x545, 0x546, 0x3, 0x2, 0x2, 0x2, 0x546, 0xa1, 0x3, 0x2, 
    0x2, 0x2, 0x547, 0x545, 0x3, 0x2, 0x2, 0x2, 0x548, 0x54c, 0x5, 0xa4, 
    0x53, 0x2, 0x549, 0x54a, 0x5, 0xa6, 0x54, 0x2, 0x54a, 0x54b, 0x5, 0xa4, 
    0x53, 0x2, 0x54b, 0x54d, 0x3, 0x2, 0x2, 0x2, 0x54c, 0x549, 0x3, 0x2, 
    0x2, 0x2, 0x54c, 0x54d, 0x3, 0x2, 0x2, 0x2, 0x54d, 0xa3, 0x3, 0x2, 0x2, 
    0x2, 0x54e, 0x55c, 0x5, 0xa8, 0x55, 0x2, 0x54f, 0x551, 0x7, 0x9a, 0x2, 
    0x2, 0x550, 0x54f, 0x3, 0x2, 0x2, 0x2, 0x550, 0x551, 0x3, 0x2, 0x2, 
    0x2, 0x551, 0x552, 0x3, 0x2, 0x2, 0x2, 0x552, 0x553, 0x7, 0x2f, 0x2, 
    0x2, 0x553, 0x554, 0x5, 0x9c, 0x4f, 0x2, 0x554, 0x555, 0x7, 0x30, 0x2, 
    0x2, 0x555, 0x55c, 0x3, 0x2, 0x2, 0x2, 0x556, 0x557, 0x7, 0x9e, 0x2, 
    0x2, 0x557, 0x558, 0x7, 0x2f, 0x2, 0x2, 0x558, 0x559, 0x5, 0xa8, 0x55, 
    0x2, 0x559, 0x55a, 0x7, 0x30, 0x2, 0x2, 0x55a, 0x55c, 0x3, 0x2, 0x2, 
    0x2, 0x55b, 0x54e, 0x3, 0x2, 0x2, 0x2, 0x55b, 0x550, 0x3, 0x2, 0x2, 
    0x2, 0x55b, 0x556, 0x3, 0x2, 0x2, 0x2, 0x55c, 0xa5, 0x3, 0x2, 0x2, 0x2, 
    0x55d, 0x55e, 0x9, 0xd, 0x2, 0x2, 0x55e, 0xa7, 0x3, 0x2, 0x2, 0x2, 0x55f, 
    0x575, 0x5, 0xaa, 0x56, 0x2, 0x560, 0x564, 0x5, 0xca, 0x66, 0x2, 0x561, 
    0x562, 0x7, 0x9f, 0x2, 0x2, 0x562, 0x564, 0x5, 0x4, 0x3, 0x2, 0x563, 
    0x560, 0x3, 0x2, 0x2, 0x2, 0x563, 0x561, 0x3, 0x2, 0x2, 0x2, 0x564, 
    0x567, 0x3, 0x2, 0x2, 0x2, 0x565, 0x566, 0x7, 0x14, 0x2, 0x2, 0x566, 
    0x568, 0x5, 0xaa, 0x56, 0x2, 0x567, 0x565, 0x3, 0x2, 0x2, 0x2, 0x567, 
    0x568, 0x3, 0x2, 0x2, 0x2, 0x568, 0x575, 0x3, 0x2, 0x2, 0x2, 0x569, 
    0x575, 0x5, 0xb4, 0x5b, 0x2, 0x56a, 0x56f, 0x7, 0x54, 0x2, 0x2, 0x56b, 
    0x56c, 0x7, 0xbe, 0x2, 0x2, 0x56c, 0x56e, 0x7, 0x48, 0x2, 0x2, 0x56d, 
    0x56b, 0x3, 0x2, 0x2, 0x2, 0x56e, 0x571, 0x3, 0x2, 0x2, 0x2, 0x56f, 
    0x56d, 0x3, 0x2, 0x2, 0x2, 0x56f, 0x570, 0x3, 0x2, 0x2, 0x2, 0x570, 
    0x572, 0x3, 0x2, 0x2, 0x2, 0x571, 0x56f, 0x3, 0x2, 0x2, 0x2, 0x572, 
    0x575, 0x7, 0xbe, 0x2, 0x2, 0x573, 0x575, 0x5, 0x34, 0x1b, 0x2, 0x574, 
    0x55f, 0x3, 0x2, 0x2, 0x2, 0x574, 0x563, 0x3, 0x2, 0x2, 0x2, 0x574, 
    0x569, 0x3, 0x2, 0x2, 0x2, 0x574, 0x56a, 0x3, 0x2, 0x2, 0x2, 0x574, 
    0x573, 0x3, 0x2, 0x2, 0x2, 0x575, 0xa9, 0x3, 0x2, 0x2, 0x2, 0x576, 0x57b, 
    0x5, 0xae, 0x58, 0x2, 0x577, 0x578, 0x7, 0x4d, 0x2, 0x2, 0x578, 0x57a, 
    0x5, 0xae, 0x58, 0x2, 0x579, 0x577, 0x3, 0x2, 0x2, 0x2, 0x57a, 0x57d, 
    0x3, 0x2, 0x2, 0x2, 0x57b, 0x579, 0x3, 0x2, 0x2, 0x2, 0x57b, 0x57c, 
    0x3, 0x2, 0x2, 0x2, 0x57c, 0xab, 0x3, 0x2, 0x2, 0x2, 0x57d, 0x57b, 0x3, 
    0x2, 0x2, 0x2, 0x57e, 0x57f, 0x5, 0xaa, 0x56, 0x2, 0x57f, 0xad, 0x3, 
    0x2, 0x2, 0x2, 0x580, 0x58f, 0x7, 0xa0, 0x2, 0x2, 0x581, 0x58f, 0x7, 
    0xa1, 0x2, 0x2, 0x582, 0x58f, 0x7, 0xa2, 0x2, 0x2, 0x583, 0x58f, 0x7, 
    0xa3, 0x2, 0x2, 0x584, 0x58f, 0x7, 0xbe, 0x2, 0x2, 0x585, 0x58f, 0x5, 
    0xb0, 0x59, 0x2, 0x586, 0x58a, 0x7, 0xbe, 0x2, 0x2, 0x587, 0x588, 0x7, 
    0x31, 0x2, 0x2, 0x588, 0x589, 0x7, 0xbe, 0x2, 0x2, 0x589, 0x58b, 0x7, 
    0x32, 0x2, 0x2, 0x58a, 0x587, 0x3, 0x2, 0x2, 0x2, 0x58a, 0x58b, 0x3, 
    0x2, 0x2, 0x2, 0x58b, 0x58f, 0x3, 0x2, 0x2, 0x2, 0x58c, 0x58f, 0x7, 
    0xbe, 0x2, 0x2, 0x58d, 0x58f, 0x5, 0xb2, 0x5a, 0x2, 0x58e, 0x580, 0x3, 
    0x2, 0x2, 0x2, 0x58e, 0x581, 0x3, 0x2, 0x2, 0x2, 0x58e, 0x582, 0x3, 
    0x2, 0x2, 0x2, 0x58e, 0x583, 0x3, 0x2, 0x2, 0x2, 0x58e, 0x584, 0x3, 
    0x2, 0x2, 0x2, 0x58e, 0x585, 0x3, 0x2, 0x2, 0x2, 0x58e, 0x586, 0x3, 
    0x2, 0x2, 0x2, 0x58e, 0x58c, 0x3, 0x2, 0x2, 0x2, 0x58e, 0x58d, 0x3, 
    0x2, 0x2, 0x2, 0x58f, 0xaf, 0x3, 0x2, 0x2, 0x2, 0x590, 0x592, 0x7, 0x37, 
    0x2, 0x2, 0x591, 0x590, 0x3, 0x2, 0x2, 0x2, 0x591, 0x592, 0x3, 0x2, 
    0x2, 0x2, 0x592, 0x593, 0x3, 0x2, 0x2, 0x2, 0x593, 0x594, 0x7, 0xbe, 
    0x2, 0x2, 0x594, 0xb1, 0x3, 0x2, 0x2, 0x2, 0x595, 0x59d, 0x7, 0xbe, 
    0x2, 0x2, 0x596, 0x59a, 0x7, 0x31, 0x2, 0x2, 0x597, 0x59b, 0x7, 0xa4, 
    0x2, 0x2, 0x598, 0x59b, 0x7, 0xa5, 0x2, 0x2, 0x599, 0x59b, 0x7, 0xb8, 
    0x2, 0x2, 0x59a, 0x597, 0x3, 0x2, 0x2, 0x2, 0x59a, 0x598, 0x3, 0x2, 
    0x2, 0x2, 0x59a, 0x599, 0x3, 0x2, 0x2, 0x2, 0x59b, 0x59c, 0x3, 0x2, 
    0x2, 0x2, 0x59c, 0x59e, 0x7, 0x32, 0x2, 0x2, 0x59d, 0x596, 0x3, 0x2, 
    0x2, 0x2, 0x59d, 0x59e, 0x3, 0x2, 0x2, 0x2, 0x59e, 0x5a1, 0x3, 0x2, 
    0x2, 0x2, 0x59f, 0x5a1, 0x7, 0xa6, 0x2, 0x2, 0x5a0, 0x595, 0x3, 0x2, 
    0x2, 0x2, 0x5a0, 0x59f, 0x3, 0x2, 0x2, 0x2, 0x5a1, 0xb3, 0x3, 0x2, 0x2, 
    0x2, 0x5a2, 0x5a3, 0x5, 0x4, 0x3, 0x2, 0x5a3, 0x5ac, 0x7, 0x2f, 0x2, 
    0x2, 0x5a4, 0x5a9, 0x5, 0xb6, 0x5c, 0x2, 0x5a5, 0x5a6, 0x7, 0x4b, 0x2, 
    0x2, 0x5a6, 0x5a8, 0x5, 0xb6, 0x5c, 0x2, 0x5a7, 0x5a5, 0x3, 0x2, 0x2, 
    0x2, 0x5a8, 0x5ab, 0x3, 0x2, 0x2, 0x2, 0x5a9, 0x5a7, 0x3, 0x2, 0x2, 
    0x2, 0x5a9, 0x5aa, 0x3, 0x2, 0x2, 0x2, 0x5aa, 0x5ad, 0x3, 0x2, 0x2, 
    0x2, 0x5ab, 0x5a9, 0x3, 0x2, 0x2, 0x2, 0x5ac, 0x5a4, 0x3, 0x2, 0x2, 
    0x2, 0x5ac, 0x5ad, 0x3, 0x2, 0x2, 0x2, 0x5ad, 0x5ae, 0x3, 0x2, 0x2, 
    0x2, 0x5ae, 0x5af, 0x7, 0x30, 0x2, 0x2, 0x5af, 0xb5, 0x3, 0x2, 0x2, 
    0x2, 0x5b0, 0x5bd, 0x5, 0x9c, 0x4f, 0x2, 0x5b1, 0x5b9, 0x7, 0x69, 0x2, 
    0x2, 0x5b2, 0x5b3, 0x7, 0x2f, 0x2, 0x2, 0x5b3, 0x5b8, 0x5, 0x20, 0x11, 
    0x2, 0x5b4, 0x5b5, 0x5, 0x4, 0x3, 0x2, 0x5b5, 0x5b6, 0x7, 0x30, 0x2, 
    0x2, 0x5b6, 0x5b8, 0x3, 0x2, 0x2, 0x2, 0x5b7, 0x5b2, 0x3, 0x2, 0x2, 
    0x2, 0x5b7, 0x5b4, 0x3, 0x2, 0x2, 0x2, 0x5b8, 0x5bb, 0x3, 0x2, 0x2, 
    0x2, 0x5b9, 0x5b7, 0x3, 0x2, 0x2, 0x2, 0x5b9, 0x5ba, 0x3, 0x2, 0x2, 
    0x2, 0x5ba, 0x5bd, 0x3, 0x2, 0x2, 0x2, 0x5bb, 0x5b9, 0x3, 0x2, 0x2, 
    0x2, 0x5bc, 0x5b0, 0x3, 0x2, 0x2, 0x2, 0x5bc, 0x5b1, 0x3, 0x2, 0x2, 
    0x2, 0x5bd, 0xb7, 0x3, 0x2, 0x2, 0x2, 0x5be, 0x5bf, 0x7, 0x8c, 0x2, 
    0x2, 0x5bf, 0x5c0, 0x7, 0xbe, 0x2, 0x2, 0x5c0, 0x5c9, 0x7, 0x2f, 0x2, 
    0x2, 0x5c1, 0x5c6, 0x5, 0xba, 0x5e, 0x2, 0x5c2, 0x5c3, 0x7, 0x42, 0x2, 
    0x2, 0x5c3, 0x5c5, 0x5, 0xba, 0x5e, 0x2, 0x5c4, 0x5c2, 0x3, 0x2, 0x2, 
    0x2, 0x5c5, 0x5c8, 0x3, 0x2, 0x2, 0x2, 0x5c6, 0x5c4, 0x3, 0x2, 0x2, 
    0x2, 0x5c6, 0x5c7, 0x3, 0x2, 0x2, 0x2, 0x5c7, 0x5ca, 0x3, 0x2, 0x2, 
    0x2, 0x5c8, 0x5c6, 0x3, 0x2, 0x2, 0x2, 0x5c9, 0x5c1, 0x3, 0x2, 0x2, 
    0x2, 0x5c9, 0x5ca, 0x3, 0x2, 0x2, 0x2, 0x5ca, 0x5cb, 0x3, 0x2, 0x2, 
    0x2, 0x5cb, 0x5cc, 0x7, 0x30, 0x2, 0x2, 0x5cc, 0x5cd, 0x7, 0x4a, 0x2, 
    0x2, 0x5cd, 0x5cf, 0x5, 0xbc, 0x5f, 0x2, 0x5ce, 0x5d0, 0x7, 0xb5, 0x2, 
    0x2, 0x5cf, 0x5ce, 0x3, 0x2, 0x2, 0x2, 0x5cf, 0x5d0, 0x3, 0x2, 0x2, 
    0x2, 0x5d0, 0x5d1, 0x3, 0x2, 0x2, 0x2, 0x5d1, 0x5d2, 0x7, 0x42, 0x2, 
    0x2, 0x5d2, 0xb9, 0x3, 0x2, 0x2, 0x2, 0x5d3, 0x5d4, 0x7, 0xbe, 0x2, 
    0x2, 0x5d4, 0x5d5, 0x7, 0x4a, 0x2, 0x2, 0x5d5, 0x5d6, 0x5, 0xbc, 0x5f, 
    0x2, 0x5d6, 0xbb, 0x3, 0x2, 0x2, 0x2, 0x5d7, 0x5e1, 0x5, 0x18, 0xd, 
    0x2, 0x5d8, 0x5d9, 0x9, 0xe, 0x2, 0x2, 0x5d9, 0x5dc, 0x7, 0x14, 0x2, 
    0x2, 0x5da, 0x5dd, 0x5, 0x20, 0x11, 0x2, 0x5db, 0x5dd, 0x5, 0x4, 0x3, 
    0x2, 0x5dc, 0x5da, 0x3, 0x2, 0x2, 0x2, 0x5dc, 0x5db, 0x3, 0x2, 0x2, 
    0x2, 0x5dd, 0x5e1, 0x3, 0x2, 0x2, 0x2, 0x5de, 0x5e1, 0x7, 0xa8, 0x2, 
    0x2, 0x5df, 0x5e1, 0x7, 0xa9, 0x2, 0x2, 0x5e0, 0x5d7, 0x3, 0x2, 0x2, 
    0x2, 0x5e0, 0x5d8, 0x3, 0x2, 0x2, 0x2, 0x5e0, 0x5de, 0x3, 0x2, 0x2, 
    0x2, 0x5e0, 0x5df, 0x3, 0x2, 0x2, 0x2, 0x5e1, 0xbd, 0x3, 0x2, 0x2, 0x2, 
    0x5e2, 0x5e3, 0x7, 0x1e, 0x2, 0x2, 0x5e3, 0x5e5, 0x7, 0xbe, 0x2, 0x2, 
    0x5e4, 0x5e6, 0x5, 0x84, 0x43, 0x2, 0x5e5, 0x5e4, 0x3, 0x2, 0x2, 0x2, 
    0x5e5, 0x5e6, 0x3, 0x2, 0x2, 0x2, 0x5e6, 0x5ea, 0x3, 0x2, 0x2, 0x2, 
    0x5e7, 0x5eb, 0x5, 0xc0, 0x61, 0x2, 0x5e8, 0x5e9, 0x7, 0x1f, 0x2, 0x2, 
    0x5e9, 0x5eb, 0x5, 0x4, 0x3, 0x2, 0x5ea, 0x5e7, 0x3, 0x2, 0x2, 0x2, 
    0x5ea, 0x5e8, 0x3, 0x2, 0x2, 0x2, 0x5eb, 0x5ef, 0x3, 0x2, 0x2, 0x2, 
    0x5ec, 0x5ee, 0x5, 0xce, 0x68, 0x2, 0x5ed, 0x5ec, 0x3, 0x2, 0x2, 0x2, 
    0x5ee, 0x5f1, 0x3, 0x2, 0x2, 0x2, 0x5ef, 0x5ed, 0x3, 0x2, 0x2, 0x2, 
    0x5ef, 0x5f0, 0x3, 0x2, 0x2, 0x2, 0x5f0, 0x5f5, 0x3, 0x2, 0x2, 0x2, 
    0x5f1, 0x5ef, 0x3, 0x2, 0x2, 0x2, 0x5f2, 0x5f4, 0x5, 0xd0, 0x69, 0x2, 
    0x5f3, 0x5f2, 0x3, 0x2, 0x2, 0x2, 0x5f4, 0x5f7, 0x3, 0x2, 0x2, 0x2, 
    0x5f5, 0x5f3, 0x3, 0x2, 0x2, 0x2, 0x5f5, 0x5f6, 0x3, 0x2, 0x2, 0x2, 
    0x5f6, 0x5f8, 0x3, 0x2, 0x2, 0x2, 0x5f7, 0x5f5, 0x3, 0x2, 0x2, 0x2, 
    0x5f8, 0x5fa, 0x7, 0x43, 0x2, 0x2, 0x5f9, 0x5fb, 0x5, 0xd2, 0x6a, 0x2, 
    0x5fa, 0x5f9, 0x3, 0x2, 0x2, 0x2, 0x5fa, 0x5fb, 0x3, 0x2, 0x2, 0x2, 
    0x5fb, 0x5ff, 0x3, 0x2, 0x2, 0x2, 0x5fc, 0x5fe, 0x5, 0x88, 0x45, 0x2, 
    0x5fd, 0x5fc, 0x3, 0x2, 0x2, 0x2, 0x5fe, 0x601, 0x3, 0x2, 0x2, 0x2, 
    0x5ff, 0x5fd, 0x3, 0x2, 0x2, 0x2, 0x5ff, 0x600, 0x3, 0x2, 0x2, 0x2, 
    0x600, 0x602, 0x3, 0x2, 0x2, 0x2, 0x601, 0x5ff, 0x3, 0x2, 0x2, 0x2, 
    0x602, 0x603, 0x7, 0x10, 0x2, 0x2, 0x603, 0x604, 0x7, 0xbe, 0x2, 0x2, 
    0x604, 0x605, 0x7, 0x42, 0x2, 0x2, 0x605, 0xbf, 0x3, 0x2, 0x2, 0x2, 
    0x606, 0x60c, 0x5, 0xc2, 0x62, 0x2, 0x607, 0x60c, 0x5, 0xc4, 0x63, 0x2, 
    0x608, 0x60c, 0x5, 0xc6, 0x64, 0x2, 0x609, 0x60c, 0x5, 0xc8, 0x65, 0x2, 
    0x60a, 0x60c, 0x5, 0xca, 0x66, 0x2, 0x60b, 0x606, 0x3, 0x2, 0x2, 0x2, 
    0x60b, 0x607, 0x3, 0x2, 0x2, 0x2, 0x60b, 0x608, 0x3, 0x2, 0x2, 0x2, 
    0x60b, 0x609, 0x3, 0x2, 0x2, 0x2, 0x60b, 0x60a, 0x3, 0x2, 0x2, 0x2, 
    0x60c, 0x60d, 0x3, 0x2, 0x2, 0x2, 0x60d, 0x60e, 0x7, 0x42, 0x2, 0x2, 
    0x60e, 0xc1, 0x3, 0x2, 0x2, 0x2, 0x60f, 0x610, 0x7, 0xaa, 0x2, 0x2, 
    0x610, 0x611, 0x7, 0x14, 0x2, 0x2, 0x611, 0x612, 0x5, 0xcc, 0x67, 0x2, 
    0x612, 0xc3, 0x3, 0x2, 0x2, 0x2, 0x613, 0x614, 0x7, 0xab, 0x2, 0x2, 
    0x614, 0x615, 0x7, 0x14, 0x2, 0x2, 0x615, 0x61e, 0x5, 0xcc, 0x67, 0x2, 
    0x616, 0x617, 0x7, 0x4b, 0x2, 0x2, 0x617, 0x61c, 0x5, 0xcc, 0x67, 0x2, 
    0x618, 0x619, 0x7, 0x2f, 0x2, 0x2, 0x619, 0x61a, 0x7, 0x70, 0x2, 0x2, 
    0x61a, 0x61b, 0x7, 0xac, 0x2, 0x2, 0x61b, 0x61d, 0x7, 0x30, 0x2, 0x2, 
    0x61c, 0x618, 0x3, 0x2, 0x2, 0x2, 0x61c, 0x61d, 0x3, 0x2, 0x2, 0x2, 
    0x61d, 0x61f, 0x3, 0x2, 0x2, 0x2, 0x61e, 0x616, 0x3, 0x2, 0x2, 0x2, 
    0x61f, 0x620, 0x3, 0x2, 0x2, 0x2, 0x620, 0x61e, 0x3, 0x2, 0x2, 0x2, 
    0x620, 0x621, 0x3, 0x2, 0x2, 0x2, 0x621, 0xc5, 0x3, 0x2, 0x2, 0x2, 0x622, 
    0x623, 0x7, 0xad, 0x2, 0x2, 0x623, 0x624, 0x7, 0x14, 0x2, 0x2, 0x624, 
    0x629, 0x5, 0xcc, 0x67, 0x2, 0x625, 0x626, 0x7, 0x4b, 0x2, 0x2, 0x626, 
    0x628, 0x5, 0xcc, 0x67, 0x2, 0x627, 0x625, 0x3, 0x2, 0x2, 0x2, 0x628, 
    0x62b, 0x3, 0x2, 0x2, 0x2, 0x629, 0x627, 0x3, 0x2, 0x2, 0x2, 0x629, 
    0x62a, 0x3, 0x2, 0x2, 0x2, 0x62a, 0xc7, 0x3, 0x2, 0x2, 0x2, 0x62b, 0x629, 
    0x3, 0x2, 0x2, 0x2, 0x62c, 0x62d, 0x7, 0xae, 0x2, 0x2, 0x62d, 0x62e, 
    0x7, 0x14, 0x2, 0x2, 0x62e, 0x635, 0x5, 0xcc, 0x67, 0x2, 0x62f, 0x636, 
    0x7, 0x69, 0x2, 0x2, 0x630, 0x631, 0x7, 0x43, 0x2, 0x2, 0x631, 0x632, 
    0x7, 0x2f, 0x2, 0x2, 0x632, 0x633, 0x5, 0x94, 0x4b, 0x2, 0x633, 0x634, 
    0x7, 0x30, 0x2, 0x2, 0x634, 0x636, 0x3, 0x2, 0x2, 0x2, 0x635, 0x62f, 
    0x3, 0x2, 0x2, 0x2, 0x635, 0x630, 0x3, 0x2, 0x2, 0x2, 0x636, 0xc9, 0x3, 
    0x2, 0x2, 0x2, 0x637, 0x638, 0x7, 0x81, 0x2, 0x2, 0x638, 0x639, 0x7, 
    0x9f, 0x2, 0x2, 0x639, 0x63a, 0x7, 0x14, 0x2, 0x2, 0x63a, 0x63b, 0x5, 
    0xcc, 0x67, 0x2, 0x63b, 0x63c, 0x7, 0x4d, 0x2, 0x2, 0x63c, 0x641, 0x7, 
    0xbe, 0x2, 0x2, 0x63d, 0x63e, 0x7, 0x4d, 0x2, 0x2, 0x63e, 0x640, 0x7, 
    0xbe, 0x2, 0x2, 0x63f, 0x63d, 0x3, 0x2, 0x2, 0x2, 0x640, 0x643, 0x3, 
    0x2, 0x2, 0x2, 0x641, 0x63f, 0x3, 0x2, 0x2, 0x2, 0x641, 0x642, 0x3, 
    0x2, 0x2, 0x2, 0x642, 0xcb, 0x3, 0x2, 0x2, 0x2, 0x643, 0x641, 0x3, 0x2, 
    0x2, 0x2, 0x644, 0x645, 0x7, 0xbe, 0x2, 0x2, 0x645, 0x647, 0x7, 0x3b, 
    0x2, 0x2, 0x646, 0x644, 0x3, 0x2, 0x2, 0x2, 0x646, 0x647, 0x3, 0x2, 
    0x2, 0x2, 0x647, 0x648, 0x3, 0x2, 0x2, 0x2, 0x648, 0x649, 0x5, 0x4, 
    0x3, 0x2, 0x649, 0xcd, 0x3, 0x2, 0x2, 0x2, 0x64a, 0x64b, 0x7, 0x9c, 
    0x2, 0x2, 0x64b, 0x64c, 0x7, 0xbe, 0x2, 0x2, 0x64c, 0x64d, 0x7, 0x24, 
    0x2, 0x2, 0x64d, 0x64e, 0x7, 0xaf, 0x2, 0x2, 0x64e, 0x653, 0x5, 0xcc, 
    0x67, 0x2, 0x64f, 0x650, 0x7, 0x4b, 0x2, 0x2, 0x650, 0x652, 0x5, 0xcc, 
    0x67, 0x2, 0x651, 0x64f, 0x3, 0x2, 0x2, 0x2, 0x652, 0x655, 0x3, 0x2, 
    0x2, 0x2, 0x653, 0x651, 0x3, 0x2, 0x2, 0x2, 0x653, 0x654, 0x3, 0x2, 
    0x2, 0x2, 0x654, 0xcf, 0x3, 0x2, 0x2, 0x2, 0x655, 0x653, 0x3, 0x2, 0x2, 
    0x2, 0x656, 0x657, 0x7, 0x96, 0x2, 0x2, 0x657, 0x658, 0x5, 0x9c, 0x4f, 
    0x2, 0x658, 0x659, 0x7, 0x42, 0x2, 0x2, 0x659, 0xd1, 0x3, 0x2, 0x2, 
    0x2, 0x65a, 0x65c, 0x7, 0x2a, 0x2, 0x2, 0x65b, 0x65a, 0x3, 0x2, 0x2, 
    0x2, 0x65b, 0x65c, 0x3, 0x2, 0x2, 0x2, 0x65c, 0x66c, 0x3, 0x2, 0x2, 
    0x2, 0x65d, 0x65e, 0x7, 0x69, 0x2, 0x2, 0x65e, 0x65f, 0x7, 0x14, 0x2, 
    0x2, 0x65f, 0x660, 0x7, 0xbe, 0x2, 0x2, 0x660, 0x66b, 0x7, 0x42, 0x2, 
    0x2, 0x661, 0x66b, 0x5, 0x16, 0xc, 0x2, 0x662, 0x664, 0x7, 0xbe, 0x2, 
    0x2, 0x663, 0x665, 0x5, 0x84, 0x43, 0x2, 0x664, 0x663, 0x3, 0x2, 0x2, 
    0x2, 0x664, 0x665, 0x3, 0x2, 0x2, 0x2, 0x665, 0x666, 0x3, 0x2, 0x2, 
    0x2, 0x666, 0x667, 0x7, 0x47, 0x2, 0x2, 0x667, 0x668, 0x5, 0xa8, 0x55, 
    0x2, 0x668, 0x669, 0x7, 0x42, 0x2, 0x2, 0x669, 0x66b, 0x3, 0x2, 0x2, 
    0x2, 0x66a, 0x65d, 0x3, 0x2, 0x2, 0x2, 0x66a, 0x661, 0x3, 0x2, 0x2, 
    0x2, 0x66a, 0x662, 0x3, 0x2, 0x2, 0x2, 0x66b, 0x66e, 0x3, 0x2, 0x2, 
    0x2, 0x66c, 0x66a, 0x3, 0x2, 0x2, 0x2, 0x66c, 0x66d, 0x3, 0x2, 0x2, 
    0x2, 0x66d, 0xd3, 0x3, 0x2, 0x2, 0x2, 0x66e, 0x66c, 0x3, 0x2, 0x2, 0x2, 
    0x66f, 0x670, 0x7, 0xb0, 0x2, 0x2, 0x670, 0x672, 0x7, 0xbe, 0x2, 0x2, 
    0x671, 0x673, 0x5, 0x84, 0x43, 0x2, 0x672, 0x671, 0x3, 0x2, 0x2, 0x2, 
    0x672, 0x673, 0x3, 0x2, 0x2, 0x2, 0x673, 0x676, 0x3, 0x2, 0x2, 0x2, 
    0x674, 0x675, 0x7, 0x1f, 0x2, 0x2, 0x675, 0x677, 0x5, 0x4, 0x3, 0x2, 
    0x676, 0x674, 0x3, 0x2, 0x2, 0x2, 0x676, 0x677, 0x3, 0x2, 0x2, 0x2, 
    0x677, 0x67b, 0x3, 0x2, 0x2, 0x2, 0x678, 0x679, 0x7, 0x9b, 0x2, 0x2, 
    0x679, 0x67a, 0x7, 0x1c, 0x2, 0x2, 0x67a, 0x67c, 0x5, 0x4, 0x3, 0x2, 
    0x67b, 0x678, 0x3, 0x2, 0x2, 0x2, 0x67b, 0x67c, 0x3, 0x2, 0x2, 0x2, 
    0x67c, 0x67d, 0x3, 0x2, 0x2, 0x2, 0x67d, 0x681, 0x7, 0x43, 0x2, 0x2, 
    0x67e, 0x680, 0x5, 0xd0, 0x69, 0x2, 0x67f, 0x67e, 0x3, 0x2, 0x2, 0x2, 
    0x680, 0x683, 0x3, 0x2, 0x2, 0x2, 0x681, 0x67f, 0x3, 0x2, 0x2, 0x2, 
    0x681, 0x682, 0x3, 0x2, 0x2, 0x2, 0x682, 0x687, 0x3, 0x2, 0x2, 0x2, 
    0x683, 0x681, 0x3, 0x2, 0x2, 0x2, 0x684, 0x686, 0x5, 0xd6, 0x6c, 0x2, 
    0x685, 0x684, 0x3, 0x2, 0x2, 0x2, 0x686, 0x689, 0x3, 0x2, 0x2, 0x2, 
    0x687, 0x685, 0x3, 0x2, 0x2, 0x2, 0x687, 0x688, 0x3, 0x2, 0x2, 0x2, 
    0x688, 0x68a, 0x3, 0x2, 0x2, 0x2, 0x689, 0x687, 0x3, 0x2, 0x2, 0x2, 
    0x68a, 0x68b, 0x7, 0x10, 0x2, 0x2, 0x68b, 0x68c, 0x7, 0xbe, 0x2, 0x2, 
    0x68c, 0x68d, 0x7, 0x42, 0x2, 0x2, 0x68d, 0xd5, 0x3, 0x2, 0x2, 0x2, 
    0x68e, 0x690, 0x7, 0xbe, 0x2, 0x2, 0x68f, 0x691, 0x5, 0x84, 0x43, 0x2, 
    0x690, 0x68f, 0x3, 0x2, 0x2, 0x2, 0x690, 0x691, 0x3, 0x2, 0x2, 0x2, 
    0x691, 0x694, 0x3, 0x2, 0x2, 0x2, 0x692, 0x693, 0x7, 0x14, 0x2, 0x2, 
    0x693, 0x695, 0x5, 0x4, 0x3, 0x2, 0x694, 0x692, 0x3, 0x2, 0x2, 0x2, 
    0x694, 0x695, 0x3, 0x2, 0x2, 0x2, 0x695, 0x696, 0x3, 0x2, 0x2, 0x2, 
    0x696, 0x697, 0x7, 0x4a, 0x2, 0x2, 0x697, 0x69c, 0x5, 0xd8, 0x6d, 0x2, 
    0x698, 0x699, 0x7, 0x4b, 0x2, 0x2, 0x699, 0x69b, 0x5, 0xd8, 0x6d, 0x2, 
    0x69a, 0x698, 0x3, 0x2, 0x2, 0x2, 0x69b, 0x69e, 0x3, 0x2, 0x2, 0x2, 
    0x69c, 0x69a, 0x3, 0x2, 0x2, 0x2, 0x69c, 0x69d, 0x3, 0x2, 0x2, 0x2, 
    0x69d, 0x69f, 0x3, 0x2, 0x2, 0x2, 0x69e, 0x69c, 0x3, 0x2, 0x2, 0x2, 
    0x69f, 0x6a0, 0x7, 0x42, 0x2, 0x2, 0x6a0, 0xd7, 0x3, 0x2, 0x2, 0x2, 
    0x6a1, 0x6a2, 0x7, 0x96, 0x2, 0x2, 0x6a2, 0x6a4, 0x5, 0x9c, 0x4f, 0x2, 
    0x6a3, 0x6a1, 0x3, 0x2, 0x2, 0x2, 0x6a3, 0x6a4, 0x3, 0x2, 0x2, 0x2, 
    0x6a4, 0x6a5, 0x3, 0x2, 0x2, 0x2, 0x6a5, 0x6a6, 0x7, 0x2f, 0x2, 0x2, 
    0x6a6, 0x6ab, 0x5, 0xda, 0x6e, 0x2, 0x6a7, 0x6a8, 0x7, 0x4b, 0x2, 0x2, 
    0x6a8, 0x6aa, 0x5, 0xda, 0x6e, 0x2, 0x6a9, 0x6a7, 0x3, 0x2, 0x2, 0x2, 
    0x6aa, 0x6ad, 0x3, 0x2, 0x2, 0x2, 0x6ab, 0x6a9, 0x3, 0x2, 0x2, 0x2, 
    0x6ab, 0x6ac, 0x3, 0x2, 0x2, 0x2, 0x6ac, 0x6ae, 0x3, 0x2, 0x2, 0x2, 
    0x6ad, 0x6ab, 0x3, 0x2, 0x2, 0x2, 0x6ae, 0x6af, 0x7, 0x30, 0x2, 0x2, 
    0x6af, 0xd9, 0x3, 0x2, 0x2, 0x2, 0x6b0, 0x6b1, 0x7, 0xbe, 0x2, 0x2, 
    0x6b1, 0x6c4, 0x7, 0x47, 0x2, 0x2, 0x6b2, 0x6b3, 0x7, 0x33, 0x2, 0x2, 
    0x6b3, 0x6b4, 0x5, 0x80, 0x41, 0x2, 0x6b4, 0x6b5, 0x7, 0x34, 0x2, 0x2, 
    0x6b5, 0x6c5, 0x3, 0x2, 0x2, 0x2, 0x6b6, 0x6c5, 0x5, 0xa8, 0x55, 0x2, 
    0x6b7, 0x6b8, 0x7, 0xb1, 0x2, 0x2, 0x6b8, 0x6b9, 0x5, 0xac, 0x57, 0x2, 
    0x6b9, 0x6ba, 0x7, 0x2f, 0x2, 0x2, 0x6ba, 0x6bf, 0x5, 0xdc, 0x6f, 0x2, 
    0x6bb, 0x6bc, 0x7, 0x4b, 0x2, 0x2, 0x6bc, 0x6be, 0x5, 0xdc, 0x6f, 0x2, 
    0x6bd, 0x6bb, 0x3, 0x2, 0x2, 0x2, 0x6be, 0x6c1, 0x3, 0x2, 0x2, 0x2, 
    0x6bf, 0x6bd, 0x3, 0x2, 0x2, 0x2, 0x6bf, 0x6c0, 0x3, 0x2, 0x2, 0x2, 
    0x6c0, 0x6c2, 0x3, 0x2, 0x2, 0x2, 0x6c1, 0x6bf, 0x3, 0x2, 0x2, 0x2, 
    0x6c2, 0x6c3, 0x7, 0x30, 0x2, 0x2, 0x6c3, 0x6c5, 0x3, 0x2, 0x2, 0x2, 
    0x6c4, 0x6b2, 0x3, 0x2, 0x2, 0x2, 0x6c4, 0x6b6, 0x3, 0x2, 0x2, 0x2, 
    0x6c4, 0x6b7, 0x3, 0x2, 0x2, 0x2, 0x6c5, 0xdb, 0x3, 0x2, 0x2, 0x2, 0x6c6, 
    0x6c7, 0x7, 0x33, 0x2, 0x2, 0x6c7, 0x6c8, 0x5, 0x80, 0x41, 0x2, 0x6c8, 
    0x6c9, 0x7, 0x34, 0x2, 0x2, 0x6c9, 0x6cc, 0x3, 0x2, 0x2, 0x2, 0x6ca, 
    0x6cc, 0x5, 0x34, 0x1b, 0x2, 0x6cb, 0x6c6, 0x3, 0x2, 0x2, 0x2, 0x6cb, 
    0x6ca, 0x3, 0x2, 0x2, 0x2, 0x6cc, 0x6cd, 0x3, 0x2, 0x2, 0x2, 0x6cd, 
    0x6ce, 0x7, 0xb2, 0x2, 0x2, 0x6ce, 0x6cf, 0x7, 0x94, 0x2, 0x2, 0x6cf, 
    0x6d0, 0x5, 0xde, 0x70, 0x2, 0x6d0, 0xdd, 0x3, 0x2, 0x2, 0x2, 0x6d1, 
    0x6d4, 0x5, 0x42, 0x22, 0x2, 0x6d2, 0x6d3, 0x7, 0x49, 0x2, 0x2, 0x6d3, 
    0x6d5, 0x5, 0x42, 0x22, 0x2, 0x6d4, 0x6d2, 0x3, 0x2, 0x2, 0x2, 0x6d4, 
    0x6d5, 0x3, 0x2, 0x2, 0x2, 0x6d5, 0xdf, 0x3, 0x2, 0x2, 0x2, 0xe7, 0xe7, 
    0xef, 0xf5, 0xfb, 0x100, 0x107, 0x10b, 0x112, 0x11a, 0x121, 0x127, 0x12c, 
    0x13a, 0x13c, 0x149, 0x14f, 0x154, 0x159, 0x15d, 0x166, 0x16d, 0x176, 
    0x17d, 0x188, 0x18d, 0x199, 0x19b, 0x1a5, 0x1a9, 0x1b1, 0x1b4, 0x1be, 
    0x1c2, 0x1cb, 0x1d0, 0x1d6, 0x1dd, 0x1e0, 0x1e3, 0x1e6, 0x1ea, 0x1f4, 
    0x1f7, 0x1fc, 0x200, 0x204, 0x20b, 0x211, 0x218, 0x21f, 0x222, 0x22b, 
    0x233, 0x237, 0x23c, 0x244, 0x247, 0x24c, 0x250, 0x255, 0x25d, 0x262, 
    0x26b, 0x26f, 0x275, 0x279, 0x280, 0x285, 0x28f, 0x291, 0x293, 0x29b, 
    0x2a0, 0x2a4, 0x2a9, 0x2ac, 0x2b9, 0x2bc, 0x2c2, 0x2d0, 0x2d9, 0x2de, 
    0x2e3, 0x2e5, 0x2eb, 0x2f7, 0x2fc, 0x2ff, 0x308, 0x30c, 0x314, 0x319, 
    0x31c, 0x323, 0x326, 0x32c, 0x331, 0x33a, 0x343, 0x347, 0x34c, 0x353, 
    0x35b, 0x360, 0x368, 0x36c, 0x36f, 0x376, 0x37b, 0x382, 0x387, 0x391, 
    0x39b, 0x3a2, 0x3a9, 0x3ab, 0x3af, 0x3ba, 0x3c1, 0x3c5, 0x3c7, 0x3ce, 
    0x3d0, 0x3d9, 0x3de, 0x3e7, 0x3ec, 0x3f1, 0x3f5, 0x3fa, 0x3fc, 0x3ff, 
    0x403, 0x409, 0x40b, 0x410, 0x419, 0x421, 0x428, 0x42e, 0x436, 0x441, 
    0x445, 0x44a, 0x44c, 0x455, 0x45a, 0x46a, 0x46e, 0x47b, 0x480, 0x487, 
    0x48b, 0x492, 0x498, 0x49f, 0x4a1, 0x4ab, 0x4b8, 0x4c0, 0x4dd, 0x4e7, 
    0x4eb, 0x4f6, 0x501, 0x50a, 0x512, 0x518, 0x524, 0x532, 0x537, 0x540, 
    0x545, 0x54c, 0x550, 0x55b, 0x563, 0x567, 0x56f, 0x574, 0x57b, 0x58a, 
    0x58e, 0x591, 0x59a, 0x59d, 0x5a0, 0x5a9, 0x5ac, 0x5b7, 0x5b9, 0x5bc, 
    0x5c6, 0x5c9, 0x5cf, 0x5dc, 0x5e0, 0x5e5, 0x5ea, 0x5ef, 0x5f5, 0x5fa, 
    0x5ff, 0x60b, 0x61c, 0x620, 0x629, 0x635, 0x641, 0x646, 0x653, 0x65b, 
    0x664, 0x66a, 0x66c, 0x672, 0x676, 0x67b, 0x681, 0x687, 0x690, 0x694, 
    0x69c, 0x6a3, 0x6ab, 0x6bf, 0x6c4, 0x6cb, 0x6d4, 
  };

  atn::ATNDeserializer deserializer;
  _atn = deserializer.deserialize(_serializedATN);

  size_t count = _atn.getNumberOfDecisions();
  _decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    _decisionToDFA.emplace_back(_atn.getDecisionState(i), i);
  }
}

Ili2Parser::Initializer Ili2Parser::_init;
