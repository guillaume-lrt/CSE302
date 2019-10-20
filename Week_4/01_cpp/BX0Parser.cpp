
// Generated from BX0.g4 by ANTLR 4.7.2


#include "BX0Listener.h"

#include "BX0Parser.h"


using namespace antlrcpp;
using namespace bx;
using namespace antlr4;

BX0Parser::BX0Parser(TokenStream *input) : Parser(input) {
  _interpreter = new atn::ParserATNSimulator(this, _atn, _decisionToDFA, _sharedContextCache);
}

BX0Parser::~BX0Parser() {
  delete _interpreter;
}

std::string BX0Parser::getGrammarFileName() const {
  return "BX0.g4";
}

const std::vector<std::string>& BX0Parser::getRuleNames() const {
  return _ruleNames;
}

dfa::Vocabulary& BX0Parser::getVocabulary() const {
  return _vocabulary;
}


//----------------- ProgramContext ------------------------------------------------------------------

BX0Parser::ProgramContext::ProgramContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<BX0Parser::GlobalvarContext *> BX0Parser::ProgramContext::globalvar() {
  return getRuleContexts<BX0Parser::GlobalvarContext>();
}

BX0Parser::GlobalvarContext* BX0Parser::ProgramContext::globalvar(size_t i) {
  return getRuleContext<BX0Parser::GlobalvarContext>(i);
}

std::vector<BX0Parser::FunctionContext *> BX0Parser::ProgramContext::function() {
  return getRuleContexts<BX0Parser::FunctionContext>();
}

BX0Parser::FunctionContext* BX0Parser::ProgramContext::function(size_t i) {
  return getRuleContext<BX0Parser::FunctionContext>(i);
}

std::vector<BX0Parser::ProcedureContext *> BX0Parser::ProgramContext::procedure() {
  return getRuleContexts<BX0Parser::ProcedureContext>();
}

BX0Parser::ProcedureContext* BX0Parser::ProgramContext::procedure(size_t i) {
  return getRuleContext<BX0Parser::ProcedureContext>(i);
}


size_t BX0Parser::ProgramContext::getRuleIndex() const {
  return BX0Parser::RuleProgram;
}

void BX0Parser::ProgramContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<BX0Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterProgram(this);
}

void BX0Parser::ProgramContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<BX0Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitProgram(this);
}

BX0Parser::ProgramContext* BX0Parser::program() {
  ProgramContext *_localctx = _tracker.createInstance<ProgramContext>(_ctx, getState());
  enterRule(_localctx, 0, BX0Parser::RuleProgram);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(45);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << BX0Parser::T__0)
      | (1ULL << BX0Parser::T__5)
      | (1ULL << BX0Parser::T__8))) != 0)) {
      setState(43);
      _errHandler->sync(this);
      switch (_input->LA(1)) {
        case BX0Parser::T__0: {
          setState(40);
          globalvar();
          break;
        }

        case BX0Parser::T__5: {
          setState(41);
          function();
          break;
        }

        case BX0Parser::T__8: {
          setState(42);
          procedure();
          break;
        }

      default:
        throw NoViableAltException(this);
      }
      setState(47);
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

//----------------- GlobalvarContext ------------------------------------------------------------------

BX0Parser::GlobalvarContext::GlobalvarContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<BX0Parser::Globalvar_initContext *> BX0Parser::GlobalvarContext::globalvar_init() {
  return getRuleContexts<BX0Parser::Globalvar_initContext>();
}

BX0Parser::Globalvar_initContext* BX0Parser::GlobalvarContext::globalvar_init(size_t i) {
  return getRuleContext<BX0Parser::Globalvar_initContext>(i);
}

BX0Parser::TypeContext* BX0Parser::GlobalvarContext::type() {
  return getRuleContext<BX0Parser::TypeContext>(0);
}


size_t BX0Parser::GlobalvarContext::getRuleIndex() const {
  return BX0Parser::RuleGlobalvar;
}

void BX0Parser::GlobalvarContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<BX0Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterGlobalvar(this);
}

void BX0Parser::GlobalvarContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<BX0Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitGlobalvar(this);
}

BX0Parser::GlobalvarContext* BX0Parser::globalvar() {
  GlobalvarContext *_localctx = _tracker.createInstance<GlobalvarContext>(_ctx, getState());
  enterRule(_localctx, 2, BX0Parser::RuleGlobalvar);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(48);
    match(BX0Parser::T__0);
    setState(49);
    globalvar_init();
    setState(54);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == BX0Parser::T__1) {
      setState(50);
      match(BX0Parser::T__1);
      setState(51);
      globalvar_init();
      setState(56);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(57);
    match(BX0Parser::T__2);
    setState(58);
    type();
    setState(59);
    match(BX0Parser::T__3);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Globalvar_initContext ------------------------------------------------------------------

BX0Parser::Globalvar_initContext::Globalvar_initContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* BX0Parser::Globalvar_initContext::VAR() {
  return getToken(BX0Parser::VAR, 0);
}

tree::TerminalNode* BX0Parser::Globalvar_initContext::NUM() {
  return getToken(BX0Parser::NUM, 0);
}

tree::TerminalNode* BX0Parser::Globalvar_initContext::BOOL() {
  return getToken(BX0Parser::BOOL, 0);
}


size_t BX0Parser::Globalvar_initContext::getRuleIndex() const {
  return BX0Parser::RuleGlobalvar_init;
}

void BX0Parser::Globalvar_initContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<BX0Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterGlobalvar_init(this);
}

void BX0Parser::Globalvar_initContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<BX0Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitGlobalvar_init(this);
}

BX0Parser::Globalvar_initContext* BX0Parser::globalvar_init() {
  Globalvar_initContext *_localctx = _tracker.createInstance<Globalvar_initContext>(_ctx, getState());
  enterRule(_localctx, 4, BX0Parser::RuleGlobalvar_init);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(61);
    match(BX0Parser::VAR);
    setState(64);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == BX0Parser::T__4) {
      setState(62);
      match(BX0Parser::T__4);
      setState(63);
      _la = _input->LA(1);
      if (!(_la == BX0Parser::BOOL

      || _la == BX0Parser::NUM)) {
      _errHandler->recoverInline(this);
      }
      else {
        _errHandler->reportMatch(this);
        consume();
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

//----------------- FunctionContext ------------------------------------------------------------------

BX0Parser::FunctionContext::FunctionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* BX0Parser::FunctionContext::VAR() {
  return getToken(BX0Parser::VAR, 0);
}

BX0Parser::TypeContext* BX0Parser::FunctionContext::type() {
  return getRuleContext<BX0Parser::TypeContext>(0);
}

BX0Parser::BlockContext* BX0Parser::FunctionContext::block() {
  return getRuleContext<BX0Parser::BlockContext>(0);
}

BX0Parser::Parameter_groupsContext* BX0Parser::FunctionContext::parameter_groups() {
  return getRuleContext<BX0Parser::Parameter_groupsContext>(0);
}


size_t BX0Parser::FunctionContext::getRuleIndex() const {
  return BX0Parser::RuleFunction;
}

void BX0Parser::FunctionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<BX0Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFunction(this);
}

void BX0Parser::FunctionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<BX0Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFunction(this);
}

BX0Parser::FunctionContext* BX0Parser::function() {
  FunctionContext *_localctx = _tracker.createInstance<FunctionContext>(_ctx, getState());
  enterRule(_localctx, 6, BX0Parser::RuleFunction);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(66);
    match(BX0Parser::T__5);
    setState(67);
    match(BX0Parser::VAR);
    setState(68);
    match(BX0Parser::T__6);
    setState(70);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == BX0Parser::VAR) {
      setState(69);
      parameter_groups();
    }
    setState(72);
    match(BX0Parser::T__7);
    setState(73);
    match(BX0Parser::T__2);
    setState(74);
    type();
    setState(75);
    block();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ProcedureContext ------------------------------------------------------------------

BX0Parser::ProcedureContext::ProcedureContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

BX0Parser::BlockContext* BX0Parser::ProcedureContext::block() {
  return getRuleContext<BX0Parser::BlockContext>(0);
}

BX0Parser::Parameter_groupsContext* BX0Parser::ProcedureContext::parameter_groups() {
  return getRuleContext<BX0Parser::Parameter_groupsContext>(0);
}


size_t BX0Parser::ProcedureContext::getRuleIndex() const {
  return BX0Parser::RuleProcedure;
}

void BX0Parser::ProcedureContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<BX0Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterProcedure(this);
}

void BX0Parser::ProcedureContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<BX0Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitProcedure(this);
}

BX0Parser::ProcedureContext* BX0Parser::procedure() {
  ProcedureContext *_localctx = _tracker.createInstance<ProcedureContext>(_ctx, getState());
  enterRule(_localctx, 8, BX0Parser::RuleProcedure);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(77);
    match(BX0Parser::T__8);
    setState(78);
    match(BX0Parser::T__6);
    setState(80);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == BX0Parser::VAR) {
      setState(79);
      parameter_groups();
    }
    setState(82);
    match(BX0Parser::T__7);
    setState(83);
    block();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Parameter_groupsContext ------------------------------------------------------------------

BX0Parser::Parameter_groupsContext::Parameter_groupsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<BX0Parser::Parameter_groupContext *> BX0Parser::Parameter_groupsContext::parameter_group() {
  return getRuleContexts<BX0Parser::Parameter_groupContext>();
}

BX0Parser::Parameter_groupContext* BX0Parser::Parameter_groupsContext::parameter_group(size_t i) {
  return getRuleContext<BX0Parser::Parameter_groupContext>(i);
}


size_t BX0Parser::Parameter_groupsContext::getRuleIndex() const {
  return BX0Parser::RuleParameter_groups;
}

void BX0Parser::Parameter_groupsContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<BX0Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterParameter_groups(this);
}

void BX0Parser::Parameter_groupsContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<BX0Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitParameter_groups(this);
}

BX0Parser::Parameter_groupsContext* BX0Parser::parameter_groups() {
  Parameter_groupsContext *_localctx = _tracker.createInstance<Parameter_groupsContext>(_ctx, getState());
  enterRule(_localctx, 10, BX0Parser::RuleParameter_groups);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(85);
    parameter_group();
    setState(88);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == BX0Parser::T__1) {
      setState(86);
      match(BX0Parser::T__1);
      setState(87);
      parameter_group();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Parameter_groupContext ------------------------------------------------------------------

BX0Parser::Parameter_groupContext::Parameter_groupContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<tree::TerminalNode *> BX0Parser::Parameter_groupContext::VAR() {
  return getTokens(BX0Parser::VAR);
}

tree::TerminalNode* BX0Parser::Parameter_groupContext::VAR(size_t i) {
  return getToken(BX0Parser::VAR, i);
}

BX0Parser::TypeContext* BX0Parser::Parameter_groupContext::type() {
  return getRuleContext<BX0Parser::TypeContext>(0);
}


size_t BX0Parser::Parameter_groupContext::getRuleIndex() const {
  return BX0Parser::RuleParameter_group;
}

void BX0Parser::Parameter_groupContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<BX0Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterParameter_group(this);
}

void BX0Parser::Parameter_groupContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<BX0Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitParameter_group(this);
}

BX0Parser::Parameter_groupContext* BX0Parser::parameter_group() {
  Parameter_groupContext *_localctx = _tracker.createInstance<Parameter_groupContext>(_ctx, getState());
  enterRule(_localctx, 12, BX0Parser::RuleParameter_group);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(90);
    match(BX0Parser::VAR);
    setState(95);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == BX0Parser::T__1) {
      setState(91);
      match(BX0Parser::T__1);
      setState(92);
      match(BX0Parser::VAR);
      setState(97);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(98);
    match(BX0Parser::T__2);
    setState(99);
    type();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- StmtContext ------------------------------------------------------------------

BX0Parser::StmtContext::StmtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

BX0Parser::VardeclContext* BX0Parser::StmtContext::vardecl() {
  return getRuleContext<BX0Parser::VardeclContext>(0);
}

BX0Parser::BlockContext* BX0Parser::StmtContext::block() {
  return getRuleContext<BX0Parser::BlockContext>(0);
}

BX0Parser::ExpressContext* BX0Parser::StmtContext::express() {
  return getRuleContext<BX0Parser::ExpressContext>(0);
}

BX0Parser::MoveContext* BX0Parser::StmtContext::move() {
  return getRuleContext<BX0Parser::MoveContext>(0);
}

BX0Parser::PrintContext* BX0Parser::StmtContext::print() {
  return getRuleContext<BX0Parser::PrintContext>(0);
}

BX0Parser::IfelseContext* BX0Parser::StmtContext::ifelse() {
  return getRuleContext<BX0Parser::IfelseContext>(0);
}

BX0Parser::WhileLoopContext* BX0Parser::StmtContext::whileLoop() {
  return getRuleContext<BX0Parser::WhileLoopContext>(0);
}

BX0Parser::ReturnStmtContext* BX0Parser::StmtContext::returnStmt() {
  return getRuleContext<BX0Parser::ReturnStmtContext>(0);
}


size_t BX0Parser::StmtContext::getRuleIndex() const {
  return BX0Parser::RuleStmt;
}

void BX0Parser::StmtContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<BX0Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterStmt(this);
}

void BX0Parser::StmtContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<BX0Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitStmt(this);
}

BX0Parser::StmtContext* BX0Parser::stmt() {
  StmtContext *_localctx = _tracker.createInstance<StmtContext>(_ctx, getState());
  enterRule(_localctx, 14, BX0Parser::RuleStmt);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(109);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 8, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(101);
      vardecl();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(102);
      block();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(103);
      express();
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(104);
      move();
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
      setState(105);
      print();
      break;
    }

    case 6: {
      enterOuterAlt(_localctx, 6);
      setState(106);
      ifelse();
      break;
    }

    case 7: {
      enterOuterAlt(_localctx, 7);
      setState(107);
      whileLoop();
      break;
    }

    case 8: {
      enterOuterAlt(_localctx, 8);
      setState(108);
      returnStmt();
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

//----------------- VardeclContext ------------------------------------------------------------------

BX0Parser::VardeclContext::VardeclContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<BX0Parser::VarinitContext *> BX0Parser::VardeclContext::varinit() {
  return getRuleContexts<BX0Parser::VarinitContext>();
}

BX0Parser::VarinitContext* BX0Parser::VardeclContext::varinit(size_t i) {
  return getRuleContext<BX0Parser::VarinitContext>(i);
}

BX0Parser::TypeContext* BX0Parser::VardeclContext::type() {
  return getRuleContext<BX0Parser::TypeContext>(0);
}


size_t BX0Parser::VardeclContext::getRuleIndex() const {
  return BX0Parser::RuleVardecl;
}

void BX0Parser::VardeclContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<BX0Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterVardecl(this);
}

void BX0Parser::VardeclContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<BX0Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitVardecl(this);
}

BX0Parser::VardeclContext* BX0Parser::vardecl() {
  VardeclContext *_localctx = _tracker.createInstance<VardeclContext>(_ctx, getState());
  enterRule(_localctx, 16, BX0Parser::RuleVardecl);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(111);
    match(BX0Parser::T__0);
    setState(112);
    varinit();
    setState(117);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == BX0Parser::T__1) {
      setState(113);
      match(BX0Parser::T__1);
      setState(114);
      varinit();
      setState(119);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(120);
    match(BX0Parser::T__2);
    setState(121);
    type();
    setState(122);
    match(BX0Parser::T__3);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- VarinitContext ------------------------------------------------------------------

BX0Parser::VarinitContext::VarinitContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* BX0Parser::VarinitContext::VAR() {
  return getToken(BX0Parser::VAR, 0);
}

BX0Parser::ExprContext* BX0Parser::VarinitContext::expr() {
  return getRuleContext<BX0Parser::ExprContext>(0);
}


size_t BX0Parser::VarinitContext::getRuleIndex() const {
  return BX0Parser::RuleVarinit;
}

void BX0Parser::VarinitContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<BX0Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterVarinit(this);
}

void BX0Parser::VarinitContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<BX0Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitVarinit(this);
}

BX0Parser::VarinitContext* BX0Parser::varinit() {
  VarinitContext *_localctx = _tracker.createInstance<VarinitContext>(_ctx, getState());
  enterRule(_localctx, 18, BX0Parser::RuleVarinit);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(124);
    match(BX0Parser::VAR);
    setState(127);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == BX0Parser::T__4) {
      setState(125);
      match(BX0Parser::T__4);
      setState(126);
      expr(0);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- TypeContext ------------------------------------------------------------------

BX0Parser::TypeContext::TypeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t BX0Parser::TypeContext::getRuleIndex() const {
  return BX0Parser::RuleType;
}

void BX0Parser::TypeContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<BX0Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterType(this);
}

void BX0Parser::TypeContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<BX0Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitType(this);
}

BX0Parser::TypeContext* BX0Parser::type() {
  TypeContext *_localctx = _tracker.createInstance<TypeContext>(_ctx, getState());
  enterRule(_localctx, 20, BX0Parser::RuleType);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(129);
    _la = _input->LA(1);
    if (!(_la == BX0Parser::T__9

    || _la == BX0Parser::T__10)) {
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

//----------------- BlockContext ------------------------------------------------------------------

BX0Parser::BlockContext::BlockContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<BX0Parser::StmtContext *> BX0Parser::BlockContext::stmt() {
  return getRuleContexts<BX0Parser::StmtContext>();
}

BX0Parser::StmtContext* BX0Parser::BlockContext::stmt(size_t i) {
  return getRuleContext<BX0Parser::StmtContext>(i);
}


size_t BX0Parser::BlockContext::getRuleIndex() const {
  return BX0Parser::RuleBlock;
}

void BX0Parser::BlockContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<BX0Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterBlock(this);
}

void BX0Parser::BlockContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<BX0Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitBlock(this);
}

BX0Parser::BlockContext* BX0Parser::block() {
  BlockContext *_localctx = _tracker.createInstance<BlockContext>(_ctx, getState());
  enterRule(_localctx, 22, BX0Parser::RuleBlock);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(131);
    match(BX0Parser::T__11);
    setState(135);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << BX0Parser::T__0)
      | (1ULL << BX0Parser::T__6)
      | (1ULL << BX0Parser::T__11)
      | (1ULL << BX0Parser::T__13)
      | (1ULL << BX0Parser::T__14)
      | (1ULL << BX0Parser::T__16)
      | (1ULL << BX0Parser::T__17)
      | (1ULL << BX0Parser::T__18)
      | (1ULL << BX0Parser::T__19)
      | (1ULL << BX0Parser::T__20)
      | (1ULL << BX0Parser::BOOL)
      | (1ULL << BX0Parser::VAR)
      | (1ULL << BX0Parser::NUM))) != 0)) {
      setState(132);
      stmt();
      setState(137);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(138);
    match(BX0Parser::T__12);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ExpressContext ------------------------------------------------------------------

BX0Parser::ExpressContext::ExpressContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

BX0Parser::ExprContext* BX0Parser::ExpressContext::expr() {
  return getRuleContext<BX0Parser::ExprContext>(0);
}


size_t BX0Parser::ExpressContext::getRuleIndex() const {
  return BX0Parser::RuleExpress;
}

void BX0Parser::ExpressContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<BX0Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterExpress(this);
}

void BX0Parser::ExpressContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<BX0Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitExpress(this);
}

BX0Parser::ExpressContext* BX0Parser::express() {
  ExpressContext *_localctx = _tracker.createInstance<ExpressContext>(_ctx, getState());
  enterRule(_localctx, 24, BX0Parser::RuleExpress);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(140);
    expr(0);
    setState(141);
    match(BX0Parser::T__3);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- MoveContext ------------------------------------------------------------------

BX0Parser::MoveContext::MoveContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* BX0Parser::MoveContext::VAR() {
  return getToken(BX0Parser::VAR, 0);
}

BX0Parser::ExprContext* BX0Parser::MoveContext::expr() {
  return getRuleContext<BX0Parser::ExprContext>(0);
}


size_t BX0Parser::MoveContext::getRuleIndex() const {
  return BX0Parser::RuleMove;
}

void BX0Parser::MoveContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<BX0Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterMove(this);
}

void BX0Parser::MoveContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<BX0Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitMove(this);
}

BX0Parser::MoveContext* BX0Parser::move() {
  MoveContext *_localctx = _tracker.createInstance<MoveContext>(_ctx, getState());
  enterRule(_localctx, 26, BX0Parser::RuleMove);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(143);
    match(BX0Parser::VAR);
    setState(144);
    match(BX0Parser::T__4);
    setState(145);
    expr(0);
    setState(146);
    match(BX0Parser::T__3);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- PrintContext ------------------------------------------------------------------

BX0Parser::PrintContext::PrintContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

BX0Parser::ExprContext* BX0Parser::PrintContext::expr() {
  return getRuleContext<BX0Parser::ExprContext>(0);
}


size_t BX0Parser::PrintContext::getRuleIndex() const {
  return BX0Parser::RulePrint;
}

void BX0Parser::PrintContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<BX0Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterPrint(this);
}

void BX0Parser::PrintContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<BX0Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitPrint(this);
}

BX0Parser::PrintContext* BX0Parser::print() {
  PrintContext *_localctx = _tracker.createInstance<PrintContext>(_ctx, getState());
  enterRule(_localctx, 28, BX0Parser::RulePrint);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(148);
    match(BX0Parser::T__13);
    setState(149);
    expr(0);
    setState(150);
    match(BX0Parser::T__3);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- IfelseContext ------------------------------------------------------------------

BX0Parser::IfelseContext::IfelseContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

BX0Parser::ExprContext* BX0Parser::IfelseContext::expr() {
  return getRuleContext<BX0Parser::ExprContext>(0);
}

BX0Parser::BlockContext* BX0Parser::IfelseContext::block() {
  return getRuleContext<BX0Parser::BlockContext>(0);
}

BX0Parser::IfContContext* BX0Parser::IfelseContext::ifCont() {
  return getRuleContext<BX0Parser::IfContContext>(0);
}


size_t BX0Parser::IfelseContext::getRuleIndex() const {
  return BX0Parser::RuleIfelse;
}

void BX0Parser::IfelseContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<BX0Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterIfelse(this);
}

void BX0Parser::IfelseContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<BX0Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitIfelse(this);
}

BX0Parser::IfelseContext* BX0Parser::ifelse() {
  IfelseContext *_localctx = _tracker.createInstance<IfelseContext>(_ctx, getState());
  enterRule(_localctx, 30, BX0Parser::RuleIfelse);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(152);
    match(BX0Parser::T__14);
    setState(153);
    match(BX0Parser::T__6);
    setState(154);
    expr(0);
    setState(155);
    match(BX0Parser::T__7);
    setState(156);
    block();
    setState(159);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == BX0Parser::T__15) {
      setState(157);
      match(BX0Parser::T__15);
      setState(158);
      ifCont();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- IfContContext ------------------------------------------------------------------

BX0Parser::IfContContext::IfContContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

BX0Parser::IfelseContext* BX0Parser::IfContContext::ifelse() {
  return getRuleContext<BX0Parser::IfelseContext>(0);
}

BX0Parser::BlockContext* BX0Parser::IfContContext::block() {
  return getRuleContext<BX0Parser::BlockContext>(0);
}


size_t BX0Parser::IfContContext::getRuleIndex() const {
  return BX0Parser::RuleIfCont;
}

void BX0Parser::IfContContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<BX0Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterIfCont(this);
}

void BX0Parser::IfContContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<BX0Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitIfCont(this);
}

BX0Parser::IfContContext* BX0Parser::ifCont() {
  IfContContext *_localctx = _tracker.createInstance<IfContContext>(_ctx, getState());
  enterRule(_localctx, 32, BX0Parser::RuleIfCont);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(163);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case BX0Parser::T__14: {
        enterOuterAlt(_localctx, 1);
        setState(161);
        ifelse();
        break;
      }

      case BX0Parser::T__11: {
        enterOuterAlt(_localctx, 2);
        setState(162);
        block();
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

//----------------- WhileLoopContext ------------------------------------------------------------------

BX0Parser::WhileLoopContext::WhileLoopContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

BX0Parser::ExprContext* BX0Parser::WhileLoopContext::expr() {
  return getRuleContext<BX0Parser::ExprContext>(0);
}

BX0Parser::BlockContext* BX0Parser::WhileLoopContext::block() {
  return getRuleContext<BX0Parser::BlockContext>(0);
}


size_t BX0Parser::WhileLoopContext::getRuleIndex() const {
  return BX0Parser::RuleWhileLoop;
}

void BX0Parser::WhileLoopContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<BX0Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterWhileLoop(this);
}

void BX0Parser::WhileLoopContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<BX0Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitWhileLoop(this);
}

BX0Parser::WhileLoopContext* BX0Parser::whileLoop() {
  WhileLoopContext *_localctx = _tracker.createInstance<WhileLoopContext>(_ctx, getState());
  enterRule(_localctx, 34, BX0Parser::RuleWhileLoop);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(165);
    match(BX0Parser::T__16);
    setState(166);
    match(BX0Parser::T__6);
    setState(167);
    expr(0);
    setState(168);
    match(BX0Parser::T__7);
    setState(169);
    block();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ReturnStmtContext ------------------------------------------------------------------

BX0Parser::ReturnStmtContext::ReturnStmtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

BX0Parser::ExprContext* BX0Parser::ReturnStmtContext::expr() {
  return getRuleContext<BX0Parser::ExprContext>(0);
}


size_t BX0Parser::ReturnStmtContext::getRuleIndex() const {
  return BX0Parser::RuleReturnStmt;
}

void BX0Parser::ReturnStmtContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<BX0Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterReturnStmt(this);
}

void BX0Parser::ReturnStmtContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<BX0Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitReturnStmt(this);
}

BX0Parser::ReturnStmtContext* BX0Parser::returnStmt() {
  ReturnStmtContext *_localctx = _tracker.createInstance<ReturnStmtContext>(_ctx, getState());
  enterRule(_localctx, 36, BX0Parser::RuleReturnStmt);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(171);
    match(BX0Parser::T__17);
    setState(173);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << BX0Parser::T__6)
      | (1ULL << BX0Parser::T__18)
      | (1ULL << BX0Parser::T__19)
      | (1ULL << BX0Parser::T__20)
      | (1ULL << BX0Parser::BOOL)
      | (1ULL << BX0Parser::VAR)
      | (1ULL << BX0Parser::NUM))) != 0)) {
      setState(172);
      expr(0);
    }
    setState(175);
    match(BX0Parser::T__3);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ExprContext ------------------------------------------------------------------

BX0Parser::ExprContext::ExprContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t BX0Parser::ExprContext::getRuleIndex() const {
  return BX0Parser::RuleExpr;
}

void BX0Parser::ExprContext::copyFrom(ExprContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- ParensContext ------------------------------------------------------------------

BX0Parser::ExprContext* BX0Parser::ParensContext::expr() {
  return getRuleContext<BX0Parser::ExprContext>(0);
}

BX0Parser::ParensContext::ParensContext(ExprContext *ctx) { copyFrom(ctx); }

void BX0Parser::ParensContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<BX0Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterParens(this);
}
void BX0Parser::ParensContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<BX0Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitParens(this);
}
//----------------- InequationContext ------------------------------------------------------------------

std::vector<BX0Parser::ExprContext *> BX0Parser::InequationContext::expr() {
  return getRuleContexts<BX0Parser::ExprContext>();
}

BX0Parser::ExprContext* BX0Parser::InequationContext::expr(size_t i) {
  return getRuleContext<BX0Parser::ExprContext>(i);
}

BX0Parser::InequationContext::InequationContext(ExprContext *ctx) { copyFrom(ctx); }

void BX0Parser::InequationContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<BX0Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterInequation(this);
}
void BX0Parser::InequationContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<BX0Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitInequation(this);
}
//----------------- BitOrContext ------------------------------------------------------------------

std::vector<BX0Parser::ExprContext *> BX0Parser::BitOrContext::expr() {
  return getRuleContexts<BX0Parser::ExprContext>();
}

BX0Parser::ExprContext* BX0Parser::BitOrContext::expr(size_t i) {
  return getRuleContext<BX0Parser::ExprContext>(i);
}

BX0Parser::BitOrContext::BitOrContext(ExprContext *ctx) { copyFrom(ctx); }

void BX0Parser::BitOrContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<BX0Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterBitOr(this);
}
void BX0Parser::BitOrContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<BX0Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitBitOr(this);
}
//----------------- ShiftContext ------------------------------------------------------------------

std::vector<BX0Parser::ExprContext *> BX0Parser::ShiftContext::expr() {
  return getRuleContexts<BX0Parser::ExprContext>();
}

BX0Parser::ExprContext* BX0Parser::ShiftContext::expr(size_t i) {
  return getRuleContext<BX0Parser::ExprContext>(i);
}

BX0Parser::ShiftContext::ShiftContext(ExprContext *ctx) { copyFrom(ctx); }

void BX0Parser::ShiftContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<BX0Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterShift(this);
}
void BX0Parser::ShiftContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<BX0Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitShift(this);
}
//----------------- EquationContext ------------------------------------------------------------------

std::vector<BX0Parser::ExprContext *> BX0Parser::EquationContext::expr() {
  return getRuleContexts<BX0Parser::ExprContext>();
}

BX0Parser::ExprContext* BX0Parser::EquationContext::expr(size_t i) {
  return getRuleContext<BX0Parser::ExprContext>(i);
}

BX0Parser::EquationContext::EquationContext(ExprContext *ctx) { copyFrom(ctx); }

void BX0Parser::EquationContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<BX0Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterEquation(this);
}
void BX0Parser::EquationContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<BX0Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitEquation(this);
}
//----------------- MultiplicativeContext ------------------------------------------------------------------

std::vector<BX0Parser::ExprContext *> BX0Parser::MultiplicativeContext::expr() {
  return getRuleContexts<BX0Parser::ExprContext>();
}

BX0Parser::ExprContext* BX0Parser::MultiplicativeContext::expr(size_t i) {
  return getRuleContext<BX0Parser::ExprContext>(i);
}

BX0Parser::MultiplicativeContext::MultiplicativeContext(ExprContext *ctx) { copyFrom(ctx); }

void BX0Parser::MultiplicativeContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<BX0Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterMultiplicative(this);
}
void BX0Parser::MultiplicativeContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<BX0Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitMultiplicative(this);
}
//----------------- UnopContext ------------------------------------------------------------------

BX0Parser::ExprContext* BX0Parser::UnopContext::expr() {
  return getRuleContext<BX0Parser::ExprContext>(0);
}

BX0Parser::UnopContext::UnopContext(ExprContext *ctx) { copyFrom(ctx); }

void BX0Parser::UnopContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<BX0Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterUnop(this);
}
void BX0Parser::UnopContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<BX0Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitUnop(this);
}
//----------------- AdditiveContext ------------------------------------------------------------------

std::vector<BX0Parser::ExprContext *> BX0Parser::AdditiveContext::expr() {
  return getRuleContexts<BX0Parser::ExprContext>();
}

BX0Parser::ExprContext* BX0Parser::AdditiveContext::expr(size_t i) {
  return getRuleContext<BX0Parser::ExprContext>(i);
}

BX0Parser::AdditiveContext::AdditiveContext(ExprContext *ctx) { copyFrom(ctx); }

void BX0Parser::AdditiveContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<BX0Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAdditive(this);
}
void BX0Parser::AdditiveContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<BX0Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAdditive(this);
}
//----------------- CallContext ------------------------------------------------------------------

tree::TerminalNode* BX0Parser::CallContext::VAR() {
  return getToken(BX0Parser::VAR, 0);
}

std::vector<BX0Parser::ExprContext *> BX0Parser::CallContext::expr() {
  return getRuleContexts<BX0Parser::ExprContext>();
}

BX0Parser::ExprContext* BX0Parser::CallContext::expr(size_t i) {
  return getRuleContext<BX0Parser::ExprContext>(i);
}

BX0Parser::CallContext::CallContext(ExprContext *ctx) { copyFrom(ctx); }

void BX0Parser::CallContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<BX0Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterCall(this);
}
void BX0Parser::CallContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<BX0Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitCall(this);
}
//----------------- NumberContext ------------------------------------------------------------------

tree::TerminalNode* BX0Parser::NumberContext::NUM() {
  return getToken(BX0Parser::NUM, 0);
}

BX0Parser::NumberContext::NumberContext(ExprContext *ctx) { copyFrom(ctx); }

void BX0Parser::NumberContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<BX0Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterNumber(this);
}
void BX0Parser::NumberContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<BX0Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitNumber(this);
}
//----------------- BitAndContext ------------------------------------------------------------------

std::vector<BX0Parser::ExprContext *> BX0Parser::BitAndContext::expr() {
  return getRuleContexts<BX0Parser::ExprContext>();
}

BX0Parser::ExprContext* BX0Parser::BitAndContext::expr(size_t i) {
  return getRuleContext<BX0Parser::ExprContext>(i);
}

BX0Parser::BitAndContext::BitAndContext(ExprContext *ctx) { copyFrom(ctx); }

void BX0Parser::BitAndContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<BX0Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterBitAnd(this);
}
void BX0Parser::BitAndContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<BX0Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitBitAnd(this);
}
//----------------- BooleanContext ------------------------------------------------------------------

tree::TerminalNode* BX0Parser::BooleanContext::BOOL() {
  return getToken(BX0Parser::BOOL, 0);
}

BX0Parser::BooleanContext::BooleanContext(ExprContext *ctx) { copyFrom(ctx); }

void BX0Parser::BooleanContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<BX0Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterBoolean(this);
}
void BX0Parser::BooleanContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<BX0Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitBoolean(this);
}
//----------------- BitXorContext ------------------------------------------------------------------

std::vector<BX0Parser::ExprContext *> BX0Parser::BitXorContext::expr() {
  return getRuleContexts<BX0Parser::ExprContext>();
}

BX0Parser::ExprContext* BX0Parser::BitXorContext::expr(size_t i) {
  return getRuleContext<BX0Parser::ExprContext>(i);
}

BX0Parser::BitXorContext::BitXorContext(ExprContext *ctx) { copyFrom(ctx); }

void BX0Parser::BitXorContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<BX0Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterBitXor(this);
}
void BX0Parser::BitXorContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<BX0Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitBitXor(this);
}
//----------------- VariableContext ------------------------------------------------------------------

tree::TerminalNode* BX0Parser::VariableContext::VAR() {
  return getToken(BX0Parser::VAR, 0);
}

BX0Parser::VariableContext::VariableContext(ExprContext *ctx) { copyFrom(ctx); }

void BX0Parser::VariableContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<BX0Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterVariable(this);
}
void BX0Parser::VariableContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<BX0Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitVariable(this);
}
//----------------- BoolOrContext ------------------------------------------------------------------

std::vector<BX0Parser::ExprContext *> BX0Parser::BoolOrContext::expr() {
  return getRuleContexts<BX0Parser::ExprContext>();
}

BX0Parser::ExprContext* BX0Parser::BoolOrContext::expr(size_t i) {
  return getRuleContext<BX0Parser::ExprContext>(i);
}

BX0Parser::BoolOrContext::BoolOrContext(ExprContext *ctx) { copyFrom(ctx); }

void BX0Parser::BoolOrContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<BX0Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterBoolOr(this);
}
void BX0Parser::BoolOrContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<BX0Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitBoolOr(this);
}
//----------------- BoolAndContext ------------------------------------------------------------------

std::vector<BX0Parser::ExprContext *> BX0Parser::BoolAndContext::expr() {
  return getRuleContexts<BX0Parser::ExprContext>();
}

BX0Parser::ExprContext* BX0Parser::BoolAndContext::expr(size_t i) {
  return getRuleContext<BX0Parser::ExprContext>(i);
}

BX0Parser::BoolAndContext::BoolAndContext(ExprContext *ctx) { copyFrom(ctx); }

void BX0Parser::BoolAndContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<BX0Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterBoolAnd(this);
}
void BX0Parser::BoolAndContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<BX0Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitBoolAnd(this);
}

BX0Parser::ExprContext* BX0Parser::expr() {
   return expr(0);
}

BX0Parser::ExprContext* BX0Parser::expr(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  BX0Parser::ExprContext *_localctx = _tracker.createInstance<ExprContext>(_ctx, parentState);
  BX0Parser::ExprContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 38;
  enterRecursionRule(_localctx, 38, BX0Parser::RuleExpr, precedence);

    size_t _la = 0;

  auto onExit = finally([=] {
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(200);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 17, _ctx)) {
    case 1: {
      _localctx = _tracker.createInstance<VariableContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;

      setState(178);
      match(BX0Parser::VAR);
      break;
    }

    case 2: {
      _localctx = _tracker.createInstance<NumberContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(179);
      match(BX0Parser::NUM);
      break;
    }

    case 3: {
      _localctx = _tracker.createInstance<BooleanContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(180);
      match(BX0Parser::BOOL);
      break;
    }

    case 4: {
      _localctx = _tracker.createInstance<UnopContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(181);
      dynamic_cast<UnopContext *>(_localctx)->op = _input->LT(1);
      _la = _input->LA(1);
      if (!((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & ((1ULL << BX0Parser::T__18)
        | (1ULL << BX0Parser::T__19)
        | (1ULL << BX0Parser::T__20))) != 0))) {
        dynamic_cast<UnopContext *>(_localctx)->op = _errHandler->recoverInline(this);
      }
      else {
        _errHandler->reportMatch(this);
        consume();
      }
      setState(182);
      expr(13);
      break;
    }

    case 5: {
      _localctx = _tracker.createInstance<CallContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(183);
      match(BX0Parser::VAR);
      setState(184);
      match(BX0Parser::T__6);
      setState(193);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & ((1ULL << BX0Parser::T__6)
        | (1ULL << BX0Parser::T__18)
        | (1ULL << BX0Parser::T__19)
        | (1ULL << BX0Parser::T__20)
        | (1ULL << BX0Parser::BOOL)
        | (1ULL << BX0Parser::VAR)
        | (1ULL << BX0Parser::NUM))) != 0)) {
        setState(185);
        expr(0);
        setState(190);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while (_la == BX0Parser::T__1) {
          setState(186);
          match(BX0Parser::T__1);
          setState(187);
          expr(0);
          setState(192);
          _errHandler->sync(this);
          _la = _input->LA(1);
        }
      }
      setState(195);
      match(BX0Parser::T__7);
      break;
    }

    case 6: {
      _localctx = _tracker.createInstance<ParensContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(196);
      match(BX0Parser::T__6);
      setState(197);
      expr(0);
      setState(198);
      match(BX0Parser::T__7);
      break;
    }

    }
    _ctx->stop = _input->LT(-1);
    setState(234);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 19, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(232);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 18, _ctx)) {
        case 1: {
          auto newContext = _tracker.createInstance<MultiplicativeContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(202);

          if (!(precpred(_ctx, 12))) throw FailedPredicateException(this, "precpred(_ctx, 12)");
          setState(203);
          dynamic_cast<MultiplicativeContext *>(_localctx)->op = _input->LT(1);
          _la = _input->LA(1);
          if (!((((_la & ~ 0x3fULL) == 0) &&
            ((1ULL << _la) & ((1ULL << BX0Parser::T__21)
            | (1ULL << BX0Parser::T__22)
            | (1ULL << BX0Parser::T__23))) != 0))) {
            dynamic_cast<MultiplicativeContext *>(_localctx)->op = _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(204);
          expr(13);
          break;
        }

        case 2: {
          auto newContext = _tracker.createInstance<AdditiveContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(205);

          if (!(precpred(_ctx, 11))) throw FailedPredicateException(this, "precpred(_ctx, 11)");
          setState(206);
          dynamic_cast<AdditiveContext *>(_localctx)->op = _input->LT(1);
          _la = _input->LA(1);
          if (!(_la == BX0Parser::T__19

          || _la == BX0Parser::T__24)) {
            dynamic_cast<AdditiveContext *>(_localctx)->op = _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(207);
          expr(12);
          break;
        }

        case 3: {
          auto newContext = _tracker.createInstance<ShiftContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(208);

          if (!(precpred(_ctx, 10))) throw FailedPredicateException(this, "precpred(_ctx, 10)");
          setState(209);
          dynamic_cast<ShiftContext *>(_localctx)->op = _input->LT(1);
          _la = _input->LA(1);
          if (!(_la == BX0Parser::T__25

          || _la == BX0Parser::T__26)) {
            dynamic_cast<ShiftContext *>(_localctx)->op = _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(210);
          expr(11);
          break;
        }

        case 4: {
          auto newContext = _tracker.createInstance<InequationContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(211);

          if (!(precpred(_ctx, 9))) throw FailedPredicateException(this, "precpred(_ctx, 9)");
          setState(212);
          dynamic_cast<InequationContext *>(_localctx)->op = _input->LT(1);
          _la = _input->LA(1);
          if (!((((_la & ~ 0x3fULL) == 0) &&
            ((1ULL << _la) & ((1ULL << BX0Parser::T__27)
            | (1ULL << BX0Parser::T__28)
            | (1ULL << BX0Parser::T__29)
            | (1ULL << BX0Parser::T__30))) != 0))) {
            dynamic_cast<InequationContext *>(_localctx)->op = _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(213);
          expr(10);
          break;
        }

        case 5: {
          auto newContext = _tracker.createInstance<EquationContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(214);

          if (!(precpred(_ctx, 8))) throw FailedPredicateException(this, "precpred(_ctx, 8)");
          setState(215);
          dynamic_cast<EquationContext *>(_localctx)->op = _input->LT(1);
          _la = _input->LA(1);
          if (!(_la == BX0Parser::T__31

          || _la == BX0Parser::T__32)) {
            dynamic_cast<EquationContext *>(_localctx)->op = _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(216);
          expr(9);
          break;
        }

        case 6: {
          auto newContext = _tracker.createInstance<BitAndContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(217);

          if (!(precpred(_ctx, 7))) throw FailedPredicateException(this, "precpred(_ctx, 7)");
          setState(218);
          match(BX0Parser::T__33);
          setState(219);
          expr(8);
          break;
        }

        case 7: {
          auto newContext = _tracker.createInstance<BitXorContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(220);

          if (!(precpred(_ctx, 6))) throw FailedPredicateException(this, "precpred(_ctx, 6)");
          setState(221);
          match(BX0Parser::T__34);
          setState(222);
          expr(7);
          break;
        }

        case 8: {
          auto newContext = _tracker.createInstance<BitOrContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(223);

          if (!(precpred(_ctx, 5))) throw FailedPredicateException(this, "precpred(_ctx, 5)");
          setState(224);
          match(BX0Parser::T__35);
          setState(225);
          expr(6);
          break;
        }

        case 9: {
          auto newContext = _tracker.createInstance<BoolAndContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(226);

          if (!(precpred(_ctx, 4))) throw FailedPredicateException(this, "precpred(_ctx, 4)");
          setState(227);
          match(BX0Parser::T__36);
          setState(228);
          expr(5);
          break;
        }

        case 10: {
          auto newContext = _tracker.createInstance<BoolOrContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(229);

          if (!(precpred(_ctx, 3))) throw FailedPredicateException(this, "precpred(_ctx, 3)");
          setState(230);
          match(BX0Parser::T__37);
          setState(231);
          expr(4);
          break;
        }

        } 
      }
      setState(236);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 19, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

bool BX0Parser::sempred(RuleContext *context, size_t ruleIndex, size_t predicateIndex) {
  switch (ruleIndex) {
    case 19: return exprSempred(dynamic_cast<ExprContext *>(context), predicateIndex);

  default:
    break;
  }
  return true;
}

bool BX0Parser::exprSempred(ExprContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 0: return precpred(_ctx, 12);
    case 1: return precpred(_ctx, 11);
    case 2: return precpred(_ctx, 10);
    case 3: return precpred(_ctx, 9);
    case 4: return precpred(_ctx, 8);
    case 5: return precpred(_ctx, 7);
    case 6: return precpred(_ctx, 6);
    case 7: return precpred(_ctx, 5);
    case 8: return precpred(_ctx, 4);
    case 9: return precpred(_ctx, 3);

  default:
    break;
  }
  return true;
}

// Static vars and initialization.
std::vector<dfa::DFA> BX0Parser::_decisionToDFA;
atn::PredictionContextCache BX0Parser::_sharedContextCache;

// We own the ATN which in turn owns the ATN states.
atn::ATN BX0Parser::_atn;
std::vector<uint16_t> BX0Parser::_serializedATN;

std::vector<std::string> BX0Parser::_ruleNames = {
  "program", "globalvar", "globalvar_init", "function", "procedure", "parameter_groups", 
  "parameter_group", "stmt", "vardecl", "varinit", "type", "block", "express", 
  "move", "print", "ifelse", "ifCont", "whileLoop", "returnStmt", "expr"
};

std::vector<std::string> BX0Parser::_literalNames = {
  "", "'var'", "','", "':'", "';'", "'='", "'fun'", "'('", "')'", "'proc'", 
  "'int64'", "'bool'", "'{'", "'}'", "'print'", "'if'", "'else'", "'while'", 
  "'return'", "'~'", "'-'", "'!'", "'*'", "'/'", "'%'", "'+'", "'<<'", "'>>'", 
  "'<'", "'<='", "'>'", "'>='", "'=='", "'!='", "'&'", "'^'", "'|'", "'&&'", 
  "'||'"
};

std::vector<std::string> BX0Parser::_symbolicNames = {
  "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", 
  "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", 
  "", "", "", "BOOL", "VAR", "NUM", "LINECOMMENT", "WS"
};

dfa::Vocabulary BX0Parser::_vocabulary(_literalNames, _symbolicNames);

std::vector<std::string> BX0Parser::_tokenNames;

BX0Parser::Initializer::Initializer() {
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
    0x3, 0x2d, 0xf0, 0x4, 0x2, 0x9, 0x2, 0x4, 0x3, 0x9, 0x3, 0x4, 0x4, 0x9, 
    0x4, 0x4, 0x5, 0x9, 0x5, 0x4, 0x6, 0x9, 0x6, 0x4, 0x7, 0x9, 0x7, 0x4, 
    0x8, 0x9, 0x8, 0x4, 0x9, 0x9, 0x9, 0x4, 0xa, 0x9, 0xa, 0x4, 0xb, 0x9, 
    0xb, 0x4, 0xc, 0x9, 0xc, 0x4, 0xd, 0x9, 0xd, 0x4, 0xe, 0x9, 0xe, 0x4, 
    0xf, 0x9, 0xf, 0x4, 0x10, 0x9, 0x10, 0x4, 0x11, 0x9, 0x11, 0x4, 0x12, 
    0x9, 0x12, 0x4, 0x13, 0x9, 0x13, 0x4, 0x14, 0x9, 0x14, 0x4, 0x15, 0x9, 
    0x15, 0x3, 0x2, 0x3, 0x2, 0x3, 0x2, 0x7, 0x2, 0x2e, 0xa, 0x2, 0xc, 0x2, 
    0xe, 0x2, 0x31, 0xb, 0x2, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x7, 
    0x3, 0x37, 0xa, 0x3, 0xc, 0x3, 0xe, 0x3, 0x3a, 0xb, 0x3, 0x3, 0x3, 0x3, 
    0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x5, 0x4, 0x43, 
    0xa, 0x4, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x5, 0x5, 0x49, 0xa, 
    0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x6, 0x3, 
    0x6, 0x3, 0x6, 0x5, 0x6, 0x53, 0xa, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 
    0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x5, 0x7, 0x5b, 0xa, 0x7, 0x3, 0x8, 0x3, 
    0x8, 0x3, 0x8, 0x7, 0x8, 0x60, 0xa, 0x8, 0xc, 0x8, 0xe, 0x8, 0x63, 0xb, 
    0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 
    0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x5, 0x9, 0x70, 0xa, 0x9, 
    0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x7, 0xa, 0x76, 0xa, 0xa, 0xc, 
    0xa, 0xe, 0xa, 0x79, 0xb, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 
    0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x5, 0xb, 0x82, 0xa, 0xb, 0x3, 0xc, 0x3, 
    0xc, 0x3, 0xd, 0x3, 0xd, 0x7, 0xd, 0x88, 0xa, 0xd, 0xc, 0xd, 0xe, 0xd, 
    0x8b, 0xb, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 
    0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 0x10, 0x3, 0x10, 0x3, 
    0x10, 0x3, 0x10, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 
    0x3, 0x11, 0x3, 0x11, 0x5, 0x11, 0xa2, 0xa, 0x11, 0x3, 0x12, 0x3, 0x12, 
    0x5, 0x12, 0xa6, 0xa, 0x12, 0x3, 0x13, 0x3, 0x13, 0x3, 0x13, 0x3, 0x13, 
    0x3, 0x13, 0x3, 0x13, 0x3, 0x14, 0x3, 0x14, 0x5, 0x14, 0xb0, 0xa, 0x14, 
    0x3, 0x14, 0x3, 0x14, 0x3, 0x15, 0x3, 0x15, 0x3, 0x15, 0x3, 0x15, 0x3, 
    0x15, 0x3, 0x15, 0x3, 0x15, 0x3, 0x15, 0x3, 0x15, 0x3, 0x15, 0x3, 0x15, 
    0x7, 0x15, 0xbf, 0xa, 0x15, 0xc, 0x15, 0xe, 0x15, 0xc2, 0xb, 0x15, 0x5, 
    0x15, 0xc4, 0xa, 0x15, 0x3, 0x15, 0x3, 0x15, 0x3, 0x15, 0x3, 0x15, 0x3, 
    0x15, 0x5, 0x15, 0xcb, 0xa, 0x15, 0x3, 0x15, 0x3, 0x15, 0x3, 0x15, 0x3, 
    0x15, 0x3, 0x15, 0x3, 0x15, 0x3, 0x15, 0x3, 0x15, 0x3, 0x15, 0x3, 0x15, 
    0x3, 0x15, 0x3, 0x15, 0x3, 0x15, 0x3, 0x15, 0x3, 0x15, 0x3, 0x15, 0x3, 
    0x15, 0x3, 0x15, 0x3, 0x15, 0x3, 0x15, 0x3, 0x15, 0x3, 0x15, 0x3, 0x15, 
    0x3, 0x15, 0x3, 0x15, 0x3, 0x15, 0x3, 0x15, 0x3, 0x15, 0x3, 0x15, 0x3, 
    0x15, 0x7, 0x15, 0xeb, 0xa, 0x15, 0xc, 0x15, 0xe, 0x15, 0xee, 0xb, 0x15, 
    0x3, 0x15, 0x2, 0x3, 0x28, 0x16, 0x2, 0x4, 0x6, 0x8, 0xa, 0xc, 0xe, 
    0x10, 0x12, 0x14, 0x16, 0x18, 0x1a, 0x1c, 0x1e, 0x20, 0x22, 0x24, 0x26, 
    0x28, 0x2, 0xa, 0x4, 0x2, 0x29, 0x29, 0x2b, 0x2b, 0x3, 0x2, 0xc, 0xd, 
    0x3, 0x2, 0x15, 0x17, 0x3, 0x2, 0x18, 0x1a, 0x4, 0x2, 0x16, 0x16, 0x1b, 
    0x1b, 0x3, 0x2, 0x1c, 0x1d, 0x3, 0x2, 0x1e, 0x21, 0x3, 0x2, 0x22, 0x23, 
    0x2, 0x102, 0x2, 0x2f, 0x3, 0x2, 0x2, 0x2, 0x4, 0x32, 0x3, 0x2, 0x2, 
    0x2, 0x6, 0x3f, 0x3, 0x2, 0x2, 0x2, 0x8, 0x44, 0x3, 0x2, 0x2, 0x2, 0xa, 
    0x4f, 0x3, 0x2, 0x2, 0x2, 0xc, 0x57, 0x3, 0x2, 0x2, 0x2, 0xe, 0x5c, 
    0x3, 0x2, 0x2, 0x2, 0x10, 0x6f, 0x3, 0x2, 0x2, 0x2, 0x12, 0x71, 0x3, 
    0x2, 0x2, 0x2, 0x14, 0x7e, 0x3, 0x2, 0x2, 0x2, 0x16, 0x83, 0x3, 0x2, 
    0x2, 0x2, 0x18, 0x85, 0x3, 0x2, 0x2, 0x2, 0x1a, 0x8e, 0x3, 0x2, 0x2, 
    0x2, 0x1c, 0x91, 0x3, 0x2, 0x2, 0x2, 0x1e, 0x96, 0x3, 0x2, 0x2, 0x2, 
    0x20, 0x9a, 0x3, 0x2, 0x2, 0x2, 0x22, 0xa5, 0x3, 0x2, 0x2, 0x2, 0x24, 
    0xa7, 0x3, 0x2, 0x2, 0x2, 0x26, 0xad, 0x3, 0x2, 0x2, 0x2, 0x28, 0xca, 
    0x3, 0x2, 0x2, 0x2, 0x2a, 0x2e, 0x5, 0x4, 0x3, 0x2, 0x2b, 0x2e, 0x5, 
    0x8, 0x5, 0x2, 0x2c, 0x2e, 0x5, 0xa, 0x6, 0x2, 0x2d, 0x2a, 0x3, 0x2, 
    0x2, 0x2, 0x2d, 0x2b, 0x3, 0x2, 0x2, 0x2, 0x2d, 0x2c, 0x3, 0x2, 0x2, 
    0x2, 0x2e, 0x31, 0x3, 0x2, 0x2, 0x2, 0x2f, 0x2d, 0x3, 0x2, 0x2, 0x2, 
    0x2f, 0x30, 0x3, 0x2, 0x2, 0x2, 0x30, 0x3, 0x3, 0x2, 0x2, 0x2, 0x31, 
    0x2f, 0x3, 0x2, 0x2, 0x2, 0x32, 0x33, 0x7, 0x3, 0x2, 0x2, 0x33, 0x38, 
    0x5, 0x6, 0x4, 0x2, 0x34, 0x35, 0x7, 0x4, 0x2, 0x2, 0x35, 0x37, 0x5, 
    0x6, 0x4, 0x2, 0x36, 0x34, 0x3, 0x2, 0x2, 0x2, 0x37, 0x3a, 0x3, 0x2, 
    0x2, 0x2, 0x38, 0x36, 0x3, 0x2, 0x2, 0x2, 0x38, 0x39, 0x3, 0x2, 0x2, 
    0x2, 0x39, 0x3b, 0x3, 0x2, 0x2, 0x2, 0x3a, 0x38, 0x3, 0x2, 0x2, 0x2, 
    0x3b, 0x3c, 0x7, 0x5, 0x2, 0x2, 0x3c, 0x3d, 0x5, 0x16, 0xc, 0x2, 0x3d, 
    0x3e, 0x7, 0x6, 0x2, 0x2, 0x3e, 0x5, 0x3, 0x2, 0x2, 0x2, 0x3f, 0x42, 
    0x7, 0x2a, 0x2, 0x2, 0x40, 0x41, 0x7, 0x7, 0x2, 0x2, 0x41, 0x43, 0x9, 
    0x2, 0x2, 0x2, 0x42, 0x40, 0x3, 0x2, 0x2, 0x2, 0x42, 0x43, 0x3, 0x2, 
    0x2, 0x2, 0x43, 0x7, 0x3, 0x2, 0x2, 0x2, 0x44, 0x45, 0x7, 0x8, 0x2, 
    0x2, 0x45, 0x46, 0x7, 0x2a, 0x2, 0x2, 0x46, 0x48, 0x7, 0x9, 0x2, 0x2, 
    0x47, 0x49, 0x5, 0xc, 0x7, 0x2, 0x48, 0x47, 0x3, 0x2, 0x2, 0x2, 0x48, 
    0x49, 0x3, 0x2, 0x2, 0x2, 0x49, 0x4a, 0x3, 0x2, 0x2, 0x2, 0x4a, 0x4b, 
    0x7, 0xa, 0x2, 0x2, 0x4b, 0x4c, 0x7, 0x5, 0x2, 0x2, 0x4c, 0x4d, 0x5, 
    0x16, 0xc, 0x2, 0x4d, 0x4e, 0x5, 0x18, 0xd, 0x2, 0x4e, 0x9, 0x3, 0x2, 
    0x2, 0x2, 0x4f, 0x50, 0x7, 0xb, 0x2, 0x2, 0x50, 0x52, 0x7, 0x9, 0x2, 
    0x2, 0x51, 0x53, 0x5, 0xc, 0x7, 0x2, 0x52, 0x51, 0x3, 0x2, 0x2, 0x2, 
    0x52, 0x53, 0x3, 0x2, 0x2, 0x2, 0x53, 0x54, 0x3, 0x2, 0x2, 0x2, 0x54, 
    0x55, 0x7, 0xa, 0x2, 0x2, 0x55, 0x56, 0x5, 0x18, 0xd, 0x2, 0x56, 0xb, 
    0x3, 0x2, 0x2, 0x2, 0x57, 0x5a, 0x5, 0xe, 0x8, 0x2, 0x58, 0x59, 0x7, 
    0x4, 0x2, 0x2, 0x59, 0x5b, 0x5, 0xe, 0x8, 0x2, 0x5a, 0x58, 0x3, 0x2, 
    0x2, 0x2, 0x5a, 0x5b, 0x3, 0x2, 0x2, 0x2, 0x5b, 0xd, 0x3, 0x2, 0x2, 
    0x2, 0x5c, 0x61, 0x7, 0x2a, 0x2, 0x2, 0x5d, 0x5e, 0x7, 0x4, 0x2, 0x2, 
    0x5e, 0x60, 0x7, 0x2a, 0x2, 0x2, 0x5f, 0x5d, 0x3, 0x2, 0x2, 0x2, 0x60, 
    0x63, 0x3, 0x2, 0x2, 0x2, 0x61, 0x5f, 0x3, 0x2, 0x2, 0x2, 0x61, 0x62, 
    0x3, 0x2, 0x2, 0x2, 0x62, 0x64, 0x3, 0x2, 0x2, 0x2, 0x63, 0x61, 0x3, 
    0x2, 0x2, 0x2, 0x64, 0x65, 0x7, 0x5, 0x2, 0x2, 0x65, 0x66, 0x5, 0x16, 
    0xc, 0x2, 0x66, 0xf, 0x3, 0x2, 0x2, 0x2, 0x67, 0x70, 0x5, 0x12, 0xa, 
    0x2, 0x68, 0x70, 0x5, 0x18, 0xd, 0x2, 0x69, 0x70, 0x5, 0x1a, 0xe, 0x2, 
    0x6a, 0x70, 0x5, 0x1c, 0xf, 0x2, 0x6b, 0x70, 0x5, 0x1e, 0x10, 0x2, 0x6c, 
    0x70, 0x5, 0x20, 0x11, 0x2, 0x6d, 0x70, 0x5, 0x24, 0x13, 0x2, 0x6e, 
    0x70, 0x5, 0x26, 0x14, 0x2, 0x6f, 0x67, 0x3, 0x2, 0x2, 0x2, 0x6f, 0x68, 
    0x3, 0x2, 0x2, 0x2, 0x6f, 0x69, 0x3, 0x2, 0x2, 0x2, 0x6f, 0x6a, 0x3, 
    0x2, 0x2, 0x2, 0x6f, 0x6b, 0x3, 0x2, 0x2, 0x2, 0x6f, 0x6c, 0x3, 0x2, 
    0x2, 0x2, 0x6f, 0x6d, 0x3, 0x2, 0x2, 0x2, 0x6f, 0x6e, 0x3, 0x2, 0x2, 
    0x2, 0x70, 0x11, 0x3, 0x2, 0x2, 0x2, 0x71, 0x72, 0x7, 0x3, 0x2, 0x2, 
    0x72, 0x77, 0x5, 0x14, 0xb, 0x2, 0x73, 0x74, 0x7, 0x4, 0x2, 0x2, 0x74, 
    0x76, 0x5, 0x14, 0xb, 0x2, 0x75, 0x73, 0x3, 0x2, 0x2, 0x2, 0x76, 0x79, 
    0x3, 0x2, 0x2, 0x2, 0x77, 0x75, 0x3, 0x2, 0x2, 0x2, 0x77, 0x78, 0x3, 
    0x2, 0x2, 0x2, 0x78, 0x7a, 0x3, 0x2, 0x2, 0x2, 0x79, 0x77, 0x3, 0x2, 
    0x2, 0x2, 0x7a, 0x7b, 0x7, 0x5, 0x2, 0x2, 0x7b, 0x7c, 0x5, 0x16, 0xc, 
    0x2, 0x7c, 0x7d, 0x7, 0x6, 0x2, 0x2, 0x7d, 0x13, 0x3, 0x2, 0x2, 0x2, 
    0x7e, 0x81, 0x7, 0x2a, 0x2, 0x2, 0x7f, 0x80, 0x7, 0x7, 0x2, 0x2, 0x80, 
    0x82, 0x5, 0x28, 0x15, 0x2, 0x81, 0x7f, 0x3, 0x2, 0x2, 0x2, 0x81, 0x82, 
    0x3, 0x2, 0x2, 0x2, 0x82, 0x15, 0x3, 0x2, 0x2, 0x2, 0x83, 0x84, 0x9, 
    0x3, 0x2, 0x2, 0x84, 0x17, 0x3, 0x2, 0x2, 0x2, 0x85, 0x89, 0x7, 0xe, 
    0x2, 0x2, 0x86, 0x88, 0x5, 0x10, 0x9, 0x2, 0x87, 0x86, 0x3, 0x2, 0x2, 
    0x2, 0x88, 0x8b, 0x3, 0x2, 0x2, 0x2, 0x89, 0x87, 0x3, 0x2, 0x2, 0x2, 
    0x89, 0x8a, 0x3, 0x2, 0x2, 0x2, 0x8a, 0x8c, 0x3, 0x2, 0x2, 0x2, 0x8b, 
    0x89, 0x3, 0x2, 0x2, 0x2, 0x8c, 0x8d, 0x7, 0xf, 0x2, 0x2, 0x8d, 0x19, 
    0x3, 0x2, 0x2, 0x2, 0x8e, 0x8f, 0x5, 0x28, 0x15, 0x2, 0x8f, 0x90, 0x7, 
    0x6, 0x2, 0x2, 0x90, 0x1b, 0x3, 0x2, 0x2, 0x2, 0x91, 0x92, 0x7, 0x2a, 
    0x2, 0x2, 0x92, 0x93, 0x7, 0x7, 0x2, 0x2, 0x93, 0x94, 0x5, 0x28, 0x15, 
    0x2, 0x94, 0x95, 0x7, 0x6, 0x2, 0x2, 0x95, 0x1d, 0x3, 0x2, 0x2, 0x2, 
    0x96, 0x97, 0x7, 0x10, 0x2, 0x2, 0x97, 0x98, 0x5, 0x28, 0x15, 0x2, 0x98, 
    0x99, 0x7, 0x6, 0x2, 0x2, 0x99, 0x1f, 0x3, 0x2, 0x2, 0x2, 0x9a, 0x9b, 
    0x7, 0x11, 0x2, 0x2, 0x9b, 0x9c, 0x7, 0x9, 0x2, 0x2, 0x9c, 0x9d, 0x5, 
    0x28, 0x15, 0x2, 0x9d, 0x9e, 0x7, 0xa, 0x2, 0x2, 0x9e, 0xa1, 0x5, 0x18, 
    0xd, 0x2, 0x9f, 0xa0, 0x7, 0x12, 0x2, 0x2, 0xa0, 0xa2, 0x5, 0x22, 0x12, 
    0x2, 0xa1, 0x9f, 0x3, 0x2, 0x2, 0x2, 0xa1, 0xa2, 0x3, 0x2, 0x2, 0x2, 
    0xa2, 0x21, 0x3, 0x2, 0x2, 0x2, 0xa3, 0xa6, 0x5, 0x20, 0x11, 0x2, 0xa4, 
    0xa6, 0x5, 0x18, 0xd, 0x2, 0xa5, 0xa3, 0x3, 0x2, 0x2, 0x2, 0xa5, 0xa4, 
    0x3, 0x2, 0x2, 0x2, 0xa6, 0x23, 0x3, 0x2, 0x2, 0x2, 0xa7, 0xa8, 0x7, 
    0x13, 0x2, 0x2, 0xa8, 0xa9, 0x7, 0x9, 0x2, 0x2, 0xa9, 0xaa, 0x5, 0x28, 
    0x15, 0x2, 0xaa, 0xab, 0x7, 0xa, 0x2, 0x2, 0xab, 0xac, 0x5, 0x18, 0xd, 
    0x2, 0xac, 0x25, 0x3, 0x2, 0x2, 0x2, 0xad, 0xaf, 0x7, 0x14, 0x2, 0x2, 
    0xae, 0xb0, 0x5, 0x28, 0x15, 0x2, 0xaf, 0xae, 0x3, 0x2, 0x2, 0x2, 0xaf, 
    0xb0, 0x3, 0x2, 0x2, 0x2, 0xb0, 0xb1, 0x3, 0x2, 0x2, 0x2, 0xb1, 0xb2, 
    0x7, 0x6, 0x2, 0x2, 0xb2, 0x27, 0x3, 0x2, 0x2, 0x2, 0xb3, 0xb4, 0x8, 
    0x15, 0x1, 0x2, 0xb4, 0xcb, 0x7, 0x2a, 0x2, 0x2, 0xb5, 0xcb, 0x7, 0x2b, 
    0x2, 0x2, 0xb6, 0xcb, 0x7, 0x29, 0x2, 0x2, 0xb7, 0xb8, 0x9, 0x4, 0x2, 
    0x2, 0xb8, 0xcb, 0x5, 0x28, 0x15, 0xf, 0xb9, 0xba, 0x7, 0x2a, 0x2, 0x2, 
    0xba, 0xc3, 0x7, 0x9, 0x2, 0x2, 0xbb, 0xc0, 0x5, 0x28, 0x15, 0x2, 0xbc, 
    0xbd, 0x7, 0x4, 0x2, 0x2, 0xbd, 0xbf, 0x5, 0x28, 0x15, 0x2, 0xbe, 0xbc, 
    0x3, 0x2, 0x2, 0x2, 0xbf, 0xc2, 0x3, 0x2, 0x2, 0x2, 0xc0, 0xbe, 0x3, 
    0x2, 0x2, 0x2, 0xc0, 0xc1, 0x3, 0x2, 0x2, 0x2, 0xc1, 0xc4, 0x3, 0x2, 
    0x2, 0x2, 0xc2, 0xc0, 0x3, 0x2, 0x2, 0x2, 0xc3, 0xbb, 0x3, 0x2, 0x2, 
    0x2, 0xc3, 0xc4, 0x3, 0x2, 0x2, 0x2, 0xc4, 0xc5, 0x3, 0x2, 0x2, 0x2, 
    0xc5, 0xcb, 0x7, 0xa, 0x2, 0x2, 0xc6, 0xc7, 0x7, 0x9, 0x2, 0x2, 0xc7, 
    0xc8, 0x5, 0x28, 0x15, 0x2, 0xc8, 0xc9, 0x7, 0xa, 0x2, 0x2, 0xc9, 0xcb, 
    0x3, 0x2, 0x2, 0x2, 0xca, 0xb3, 0x3, 0x2, 0x2, 0x2, 0xca, 0xb5, 0x3, 
    0x2, 0x2, 0x2, 0xca, 0xb6, 0x3, 0x2, 0x2, 0x2, 0xca, 0xb7, 0x3, 0x2, 
    0x2, 0x2, 0xca, 0xb9, 0x3, 0x2, 0x2, 0x2, 0xca, 0xc6, 0x3, 0x2, 0x2, 
    0x2, 0xcb, 0xec, 0x3, 0x2, 0x2, 0x2, 0xcc, 0xcd, 0xc, 0xe, 0x2, 0x2, 
    0xcd, 0xce, 0x9, 0x5, 0x2, 0x2, 0xce, 0xeb, 0x5, 0x28, 0x15, 0xf, 0xcf, 
    0xd0, 0xc, 0xd, 0x2, 0x2, 0xd0, 0xd1, 0x9, 0x6, 0x2, 0x2, 0xd1, 0xeb, 
    0x5, 0x28, 0x15, 0xe, 0xd2, 0xd3, 0xc, 0xc, 0x2, 0x2, 0xd3, 0xd4, 0x9, 
    0x7, 0x2, 0x2, 0xd4, 0xeb, 0x5, 0x28, 0x15, 0xd, 0xd5, 0xd6, 0xc, 0xb, 
    0x2, 0x2, 0xd6, 0xd7, 0x9, 0x8, 0x2, 0x2, 0xd7, 0xeb, 0x5, 0x28, 0x15, 
    0xc, 0xd8, 0xd9, 0xc, 0xa, 0x2, 0x2, 0xd9, 0xda, 0x9, 0x9, 0x2, 0x2, 
    0xda, 0xeb, 0x5, 0x28, 0x15, 0xb, 0xdb, 0xdc, 0xc, 0x9, 0x2, 0x2, 0xdc, 
    0xdd, 0x7, 0x24, 0x2, 0x2, 0xdd, 0xeb, 0x5, 0x28, 0x15, 0xa, 0xde, 0xdf, 
    0xc, 0x8, 0x2, 0x2, 0xdf, 0xe0, 0x7, 0x25, 0x2, 0x2, 0xe0, 0xeb, 0x5, 
    0x28, 0x15, 0x9, 0xe1, 0xe2, 0xc, 0x7, 0x2, 0x2, 0xe2, 0xe3, 0x7, 0x26, 
    0x2, 0x2, 0xe3, 0xeb, 0x5, 0x28, 0x15, 0x8, 0xe4, 0xe5, 0xc, 0x6, 0x2, 
    0x2, 0xe5, 0xe6, 0x7, 0x27, 0x2, 0x2, 0xe6, 0xeb, 0x5, 0x28, 0x15, 0x7, 
    0xe7, 0xe8, 0xc, 0x5, 0x2, 0x2, 0xe8, 0xe9, 0x7, 0x28, 0x2, 0x2, 0xe9, 
    0xeb, 0x5, 0x28, 0x15, 0x6, 0xea, 0xcc, 0x3, 0x2, 0x2, 0x2, 0xea, 0xcf, 
    0x3, 0x2, 0x2, 0x2, 0xea, 0xd2, 0x3, 0x2, 0x2, 0x2, 0xea, 0xd5, 0x3, 
    0x2, 0x2, 0x2, 0xea, 0xd8, 0x3, 0x2, 0x2, 0x2, 0xea, 0xdb, 0x3, 0x2, 
    0x2, 0x2, 0xea, 0xde, 0x3, 0x2, 0x2, 0x2, 0xea, 0xe1, 0x3, 0x2, 0x2, 
    0x2, 0xea, 0xe4, 0x3, 0x2, 0x2, 0x2, 0xea, 0xe7, 0x3, 0x2, 0x2, 0x2, 
    0xeb, 0xee, 0x3, 0x2, 0x2, 0x2, 0xec, 0xea, 0x3, 0x2, 0x2, 0x2, 0xec, 
    0xed, 0x3, 0x2, 0x2, 0x2, 0xed, 0x29, 0x3, 0x2, 0x2, 0x2, 0xee, 0xec, 
    0x3, 0x2, 0x2, 0x2, 0x16, 0x2d, 0x2f, 0x38, 0x42, 0x48, 0x52, 0x5a, 
    0x61, 0x6f, 0x77, 0x81, 0x89, 0xa1, 0xa5, 0xaf, 0xc0, 0xc3, 0xca, 0xea, 
    0xec, 
  };

  atn::ATNDeserializer deserializer;
  _atn = deserializer.deserialize(_serializedATN);

  size_t count = _atn.getNumberOfDecisions();
  _decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    _decisionToDFA.emplace_back(_atn.getDecisionState(i), i);
  }
}

BX0Parser::Initializer BX0Parser::_init;
