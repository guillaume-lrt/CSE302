
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

std::vector<BX0Parser::VardeclContext *> BX0Parser::ProgramContext::vardecl() {
  return getRuleContexts<BX0Parser::VardeclContext>();
}

BX0Parser::VardeclContext* BX0Parser::ProgramContext::vardecl(size_t i) {
  return getRuleContext<BX0Parser::VardeclContext>(i);
}

std::vector<BX0Parser::StatementContext *> BX0Parser::ProgramContext::statement() {
  return getRuleContexts<BX0Parser::StatementContext>();
}

BX0Parser::StatementContext* BX0Parser::ProgramContext::statement(size_t i) {
  return getRuleContext<BX0Parser::StatementContext>(i);
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
    setState(27);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == BX0Parser::T__0) {
      setState(24);
      vardecl();
      setState(29);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(33);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << BX0Parser::T__7)
      | (1ULL << BX0Parser::T__8)
      | (1ULL << BX0Parser::T__10)
      | (1ULL << BX0Parser::T__14)
      | (1ULL << BX0Parser::VAR))) != 0)) {
      setState(30);
      statement();
      setState(35);
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
  enterRule(_localctx, 2, BX0Parser::RuleVardecl);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(36);
    match(BX0Parser::T__0);
    setState(37);
    varinit();
    setState(42);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == BX0Parser::T__1) {
      setState(38);
      match(BX0Parser::T__1);
      setState(39);
      varinit();
      setState(44);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(45);
    match(BX0Parser::T__2);
    setState(46);
    type();
    setState(47);
    match(BX0Parser::T__3);
   
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

void BX0Parser::TypeContext::copyFrom(TypeContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- BooleContext ------------------------------------------------------------------

BX0Parser::BooleContext::BooleContext(TypeContext *ctx) { copyFrom(ctx); }

void BX0Parser::BooleContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<BX0Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterBoole(this);
}
void BX0Parser::BooleContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<BX0Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitBoole(this);
}
//----------------- IntegerContext ------------------------------------------------------------------

BX0Parser::IntegerContext::IntegerContext(TypeContext *ctx) { copyFrom(ctx); }

void BX0Parser::IntegerContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<BX0Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterInteger(this);
}
void BX0Parser::IntegerContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<BX0Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitInteger(this);
}
BX0Parser::TypeContext* BX0Parser::type() {
  TypeContext *_localctx = _tracker.createInstance<TypeContext>(_ctx, getState());
  enterRule(_localctx, 4, BX0Parser::RuleType);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(51);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case BX0Parser::T__4: {
        _localctx = dynamic_cast<TypeContext *>(_tracker.createInstance<BX0Parser::IntegerContext>(_localctx));
        enterOuterAlt(_localctx, 1);
        setState(49);
        match(BX0Parser::T__4);
        break;
      }

      case BX0Parser::T__5: {
        _localctx = dynamic_cast<TypeContext *>(_tracker.createInstance<BX0Parser::BooleContext>(_localctx));
        enterOuterAlt(_localctx, 2);
        setState(50);
        match(BX0Parser::T__5);
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
  enterRule(_localctx, 6, BX0Parser::RuleVarinit);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(53);
    match(BX0Parser::VAR);
    setState(56);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == BX0Parser::T__6) {
      setState(54);
      match(BX0Parser::T__6);
      setState(55);
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

//----------------- StatementContext ------------------------------------------------------------------

BX0Parser::StatementContext::StatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

BX0Parser::MoveContext* BX0Parser::StatementContext::move() {
  return getRuleContext<BX0Parser::MoveContext>(0);
}

BX0Parser::PrintContext* BX0Parser::StatementContext::print() {
  return getRuleContext<BX0Parser::PrintContext>(0);
}

BX0Parser::BlockContext* BX0Parser::StatementContext::block() {
  return getRuleContext<BX0Parser::BlockContext>(0);
}

BX0Parser::IfelseContext* BX0Parser::StatementContext::ifelse() {
  return getRuleContext<BX0Parser::IfelseContext>(0);
}

BX0Parser::WhileeContext* BX0Parser::StatementContext::whilee() {
  return getRuleContext<BX0Parser::WhileeContext>(0);
}


size_t BX0Parser::StatementContext::getRuleIndex() const {
  return BX0Parser::RuleStatement;
}

void BX0Parser::StatementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<BX0Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterStatement(this);
}

void BX0Parser::StatementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<BX0Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitStatement(this);
}

BX0Parser::StatementContext* BX0Parser::statement() {
  StatementContext *_localctx = _tracker.createInstance<StatementContext>(_ctx, getState());
  enterRule(_localctx, 8, BX0Parser::RuleStatement);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(63);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case BX0Parser::VAR: {
        enterOuterAlt(_localctx, 1);
        setState(58);
        move();
        break;
      }

      case BX0Parser::T__7: {
        enterOuterAlt(_localctx, 2);
        setState(59);
        print();
        break;
      }

      case BX0Parser::T__8: {
        enterOuterAlt(_localctx, 3);
        setState(60);
        block();
        break;
      }

      case BX0Parser::T__10: {
        enterOuterAlt(_localctx, 4);
        setState(61);
        ifelse();
        break;
      }

      case BX0Parser::T__14: {
        enterOuterAlt(_localctx, 5);
        setState(62);
        whilee();
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
  enterRule(_localctx, 10, BX0Parser::RuleMove);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(65);
    match(BX0Parser::VAR);
    setState(66);
    match(BX0Parser::T__6);
    setState(67);
    expr(0);
   
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
  enterRule(_localctx, 12, BX0Parser::RulePrint);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(69);
    match(BX0Parser::T__7);
    setState(70);
    expr(0);
   
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

std::vector<BX0Parser::StatementContext *> BX0Parser::BlockContext::statement() {
  return getRuleContexts<BX0Parser::StatementContext>();
}

BX0Parser::StatementContext* BX0Parser::BlockContext::statement(size_t i) {
  return getRuleContext<BX0Parser::StatementContext>(i);
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
  enterRule(_localctx, 14, BX0Parser::RuleBlock);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(72);
    match(BX0Parser::T__8);
    setState(76);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << BX0Parser::T__7)
      | (1ULL << BX0Parser::T__8)
      | (1ULL << BX0Parser::T__10)
      | (1ULL << BX0Parser::T__14)
      | (1ULL << BX0Parser::VAR))) != 0)) {
      setState(73);
      statement();
      setState(78);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(79);
    match(BX0Parser::T__9);
   
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

BX0Parser::Ifelse_bisContext* BX0Parser::IfelseContext::ifelse_bis() {
  return getRuleContext<BX0Parser::Ifelse_bisContext>(0);
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
  enterRule(_localctx, 16, BX0Parser::RuleIfelse);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(81);
    match(BX0Parser::T__10);
    setState(82);
    match(BX0Parser::T__11);
    setState(83);
    expr(0);
    setState(84);
    match(BX0Parser::T__12);
    setState(85);
    block();
    setState(88);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == BX0Parser::T__13) {
      setState(86);
      match(BX0Parser::T__13);
      setState(87);
      ifelse_bis();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Ifelse_bisContext ------------------------------------------------------------------

BX0Parser::Ifelse_bisContext::Ifelse_bisContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

BX0Parser::IfelseContext* BX0Parser::Ifelse_bisContext::ifelse() {
  return getRuleContext<BX0Parser::IfelseContext>(0);
}

BX0Parser::BlockContext* BX0Parser::Ifelse_bisContext::block() {
  return getRuleContext<BX0Parser::BlockContext>(0);
}


size_t BX0Parser::Ifelse_bisContext::getRuleIndex() const {
  return BX0Parser::RuleIfelse_bis;
}

void BX0Parser::Ifelse_bisContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<BX0Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterIfelse_bis(this);
}

void BX0Parser::Ifelse_bisContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<BX0Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitIfelse_bis(this);
}

BX0Parser::Ifelse_bisContext* BX0Parser::ifelse_bis() {
  Ifelse_bisContext *_localctx = _tracker.createInstance<Ifelse_bisContext>(_ctx, getState());
  enterRule(_localctx, 18, BX0Parser::RuleIfelse_bis);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(92);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case BX0Parser::T__10: {
        setState(90);
        ifelse();
        break;
      }

      case BX0Parser::T__8: {
        setState(91);
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

//----------------- WhileeContext ------------------------------------------------------------------

BX0Parser::WhileeContext::WhileeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

BX0Parser::ExprContext* BX0Parser::WhileeContext::expr() {
  return getRuleContext<BX0Parser::ExprContext>(0);
}

BX0Parser::BlockContext* BX0Parser::WhileeContext::block() {
  return getRuleContext<BX0Parser::BlockContext>(0);
}


size_t BX0Parser::WhileeContext::getRuleIndex() const {
  return BX0Parser::RuleWhilee;
}

void BX0Parser::WhileeContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<BX0Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterWhilee(this);
}

void BX0Parser::WhileeContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<BX0Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitWhilee(this);
}

BX0Parser::WhileeContext* BX0Parser::whilee() {
  WhileeContext *_localctx = _tracker.createInstance<WhileeContext>(_ctx, getState());
  enterRule(_localctx, 20, BX0Parser::RuleWhilee);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(94);
    match(BX0Parser::T__14);
    setState(95);
    match(BX0Parser::T__11);
    setState(96);
    expr(0);
    setState(97);
    match(BX0Parser::T__12);
    setState(98);
    block();
   
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

//----------------- AddContext ------------------------------------------------------------------

std::vector<BX0Parser::ExprContext *> BX0Parser::AddContext::expr() {
  return getRuleContexts<BX0Parser::ExprContext>();
}

BX0Parser::ExprContext* BX0Parser::AddContext::expr(size_t i) {
  return getRuleContext<BX0Parser::ExprContext>(i);
}

BX0Parser::AddContext::AddContext(ExprContext *ctx) { copyFrom(ctx); }

void BX0Parser::AddContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<BX0Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAdd(this);
}
void BX0Parser::AddContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<BX0Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAdd(this);
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
//----------------- OrContext ------------------------------------------------------------------

std::vector<BX0Parser::ExprContext *> BX0Parser::OrContext::expr() {
  return getRuleContexts<BX0Parser::ExprContext>();
}

BX0Parser::ExprContext* BX0Parser::OrContext::expr(size_t i) {
  return getRuleContext<BX0Parser::ExprContext>(i);
}

BX0Parser::OrContext::OrContext(ExprContext *ctx) { copyFrom(ctx); }

void BX0Parser::OrContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<BX0Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterOr(this);
}
void BX0Parser::OrContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<BX0Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitOr(this);
}
//----------------- MulContext ------------------------------------------------------------------

std::vector<BX0Parser::ExprContext *> BX0Parser::MulContext::expr() {
  return getRuleContexts<BX0Parser::ExprContext>();
}

BX0Parser::ExprContext* BX0Parser::MulContext::expr(size_t i) {
  return getRuleContext<BX0Parser::ExprContext>(i);
}

BX0Parser::MulContext::MulContext(ExprContext *ctx) { copyFrom(ctx); }

void BX0Parser::MulContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<BX0Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterMul(this);
}
void BX0Parser::MulContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<BX0Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitMul(this);
}
//----------------- BoolorContext ------------------------------------------------------------------

std::vector<BX0Parser::ExprContext *> BX0Parser::BoolorContext::expr() {
  return getRuleContexts<BX0Parser::ExprContext>();
}

BX0Parser::ExprContext* BX0Parser::BoolorContext::expr(size_t i) {
  return getRuleContext<BX0Parser::ExprContext>(i);
}

BX0Parser::BoolorContext::BoolorContext(ExprContext *ctx) { copyFrom(ctx); }

void BX0Parser::BoolorContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<BX0Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterBoolor(this);
}
void BX0Parser::BoolorContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<BX0Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitBoolor(this);
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
//----------------- InequalityContext ------------------------------------------------------------------

std::vector<BX0Parser::ExprContext *> BX0Parser::InequalityContext::expr() {
  return getRuleContexts<BX0Parser::ExprContext>();
}

BX0Parser::ExprContext* BX0Parser::InequalityContext::expr(size_t i) {
  return getRuleContext<BX0Parser::ExprContext>(i);
}

BX0Parser::InequalityContext::InequalityContext(ExprContext *ctx) { copyFrom(ctx); }

void BX0Parser::InequalityContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<BX0Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterInequality(this);
}
void BX0Parser::InequalityContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<BX0Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitInequality(this);
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
//----------------- AndContext ------------------------------------------------------------------

std::vector<BX0Parser::ExprContext *> BX0Parser::AndContext::expr() {
  return getRuleContexts<BX0Parser::ExprContext>();
}

BX0Parser::ExprContext* BX0Parser::AndContext::expr(size_t i) {
  return getRuleContext<BX0Parser::ExprContext>(i);
}

BX0Parser::AndContext::AndContext(ExprContext *ctx) { copyFrom(ctx); }

void BX0Parser::AndContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<BX0Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAnd(this);
}
void BX0Parser::AndContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<BX0Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAnd(this);
}
//----------------- BoolandContext ------------------------------------------------------------------

std::vector<BX0Parser::ExprContext *> BX0Parser::BoolandContext::expr() {
  return getRuleContexts<BX0Parser::ExprContext>();
}

BX0Parser::ExprContext* BX0Parser::BoolandContext::expr(size_t i) {
  return getRuleContext<BX0Parser::ExprContext>(i);
}

BX0Parser::BoolandContext::BoolandContext(ExprContext *ctx) { copyFrom(ctx); }

void BX0Parser::BoolandContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<BX0Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterBooland(this);
}
void BX0Parser::BoolandContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<BX0Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitBooland(this);
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
//----------------- XorContext ------------------------------------------------------------------

std::vector<BX0Parser::ExprContext *> BX0Parser::XorContext::expr() {
  return getRuleContexts<BX0Parser::ExprContext>();
}

BX0Parser::ExprContext* BX0Parser::XorContext::expr(size_t i) {
  return getRuleContext<BX0Parser::ExprContext>(i);
}

BX0Parser::XorContext::XorContext(ExprContext *ctx) { copyFrom(ctx); }

void BX0Parser::XorContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<BX0Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterXor(this);
}
void BX0Parser::XorContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<BX0Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitXor(this);
}
//----------------- EqualityContext ------------------------------------------------------------------

std::vector<BX0Parser::ExprContext *> BX0Parser::EqualityContext::expr() {
  return getRuleContexts<BX0Parser::ExprContext>();
}

BX0Parser::ExprContext* BX0Parser::EqualityContext::expr(size_t i) {
  return getRuleContext<BX0Parser::ExprContext>(i);
}

BX0Parser::EqualityContext::EqualityContext(ExprContext *ctx) { copyFrom(ctx); }

void BX0Parser::EqualityContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<BX0Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterEquality(this);
}
void BX0Parser::EqualityContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<BX0Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitEquality(this);
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
  size_t startState = 22;
  enterRecursionRule(_localctx, 22, BX0Parser::RuleExpr, precedence);

    size_t _la = 0;

  auto onExit = finally([=] {
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(110);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case BX0Parser::VAR: {
        _localctx = _tracker.createInstance<VariableContext>(_localctx);
        _ctx = _localctx;
        previousContext = _localctx;

        setState(101);
        match(BX0Parser::VAR);
        break;
      }

      case BX0Parser::NUM: {
        _localctx = _tracker.createInstance<NumberContext>(_localctx);
        _ctx = _localctx;
        previousContext = _localctx;
        setState(102);
        match(BX0Parser::NUM);
        break;
      }

      case BX0Parser::BOOL: {
        _localctx = _tracker.createInstance<BooleanContext>(_localctx);
        _ctx = _localctx;
        previousContext = _localctx;
        setState(103);
        match(BX0Parser::BOOL);
        break;
      }

      case BX0Parser::T__15:
      case BX0Parser::T__16:
      case BX0Parser::T__17: {
        _localctx = _tracker.createInstance<UnopContext>(_localctx);
        _ctx = _localctx;
        previousContext = _localctx;
        setState(104);
        dynamic_cast<UnopContext *>(_localctx)->op = _input->LT(1);
        _la = _input->LA(1);
        if (!((((_la & ~ 0x3fULL) == 0) &&
          ((1ULL << _la) & ((1ULL << BX0Parser::T__15)
          | (1ULL << BX0Parser::T__16)
          | (1ULL << BX0Parser::T__17))) != 0))) {
          dynamic_cast<UnopContext *>(_localctx)->op = _errHandler->recoverInline(this);
        }
        else {
          _errHandler->reportMatch(this);
          consume();
        }
        setState(105);
        expr(12);
        break;
      }

      case BX0Parser::T__11: {
        _localctx = _tracker.createInstance<ParensContext>(_localctx);
        _ctx = _localctx;
        previousContext = _localctx;
        setState(106);
        match(BX0Parser::T__11);
        setState(107);
        expr(0);
        setState(108);
        match(BX0Parser::T__12);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    _ctx->stop = _input->LT(-1);
    setState(144);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 11, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(142);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 10, _ctx)) {
        case 1: {
          auto newContext = _tracker.createInstance<MulContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(112);

          if (!(precpred(_ctx, 11))) throw FailedPredicateException(this, "precpred(_ctx, 11)");
          setState(113);
          dynamic_cast<MulContext *>(_localctx)->op = _input->LT(1);
          _la = _input->LA(1);
          if (!((((_la & ~ 0x3fULL) == 0) &&
            ((1ULL << _la) & ((1ULL << BX0Parser::T__18)
            | (1ULL << BX0Parser::T__19)
            | (1ULL << BX0Parser::T__20))) != 0))) {
            dynamic_cast<MulContext *>(_localctx)->op = _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(114);
          expr(12);
          break;
        }

        case 2: {
          auto newContext = _tracker.createInstance<AddContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(115);

          if (!(precpred(_ctx, 10))) throw FailedPredicateException(this, "precpred(_ctx, 10)");
          setState(116);
          dynamic_cast<AddContext *>(_localctx)->op = _input->LT(1);
          _la = _input->LA(1);
          if (!(_la == BX0Parser::T__16

          || _la == BX0Parser::T__21)) {
            dynamic_cast<AddContext *>(_localctx)->op = _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(117);
          expr(11);
          break;
        }

        case 3: {
          auto newContext = _tracker.createInstance<ShiftContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(118);

          if (!(precpred(_ctx, 9))) throw FailedPredicateException(this, "precpred(_ctx, 9)");
          setState(119);
          dynamic_cast<ShiftContext *>(_localctx)->op = _input->LT(1);
          _la = _input->LA(1);
          if (!(_la == BX0Parser::T__22

          || _la == BX0Parser::T__23)) {
            dynamic_cast<ShiftContext *>(_localctx)->op = _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(120);
          expr(10);
          break;
        }

        case 4: {
          auto newContext = _tracker.createInstance<InequalityContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(121);

          if (!(precpred(_ctx, 8))) throw FailedPredicateException(this, "precpred(_ctx, 8)");
          setState(122);
          dynamic_cast<InequalityContext *>(_localctx)->op = _input->LT(1);
          _la = _input->LA(1);
          if (!((((_la & ~ 0x3fULL) == 0) &&
            ((1ULL << _la) & ((1ULL << BX0Parser::T__24)
            | (1ULL << BX0Parser::T__25)
            | (1ULL << BX0Parser::T__26)
            | (1ULL << BX0Parser::T__27))) != 0))) {
            dynamic_cast<InequalityContext *>(_localctx)->op = _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(123);
          expr(9);
          break;
        }

        case 5: {
          auto newContext = _tracker.createInstance<EqualityContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(124);

          if (!(precpred(_ctx, 7))) throw FailedPredicateException(this, "precpred(_ctx, 7)");
          setState(125);
          dynamic_cast<EqualityContext *>(_localctx)->op = _input->LT(1);
          _la = _input->LA(1);
          if (!(_la == BX0Parser::T__28

          || _la == BX0Parser::T__29)) {
            dynamic_cast<EqualityContext *>(_localctx)->op = _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(126);
          expr(8);
          break;
        }

        case 6: {
          auto newContext = _tracker.createInstance<AndContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(127);

          if (!(precpred(_ctx, 6))) throw FailedPredicateException(this, "precpred(_ctx, 6)");
          setState(128);
          match(BX0Parser::T__30);
          setState(129);
          expr(7);
          break;
        }

        case 7: {
          auto newContext = _tracker.createInstance<XorContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(130);

          if (!(precpred(_ctx, 5))) throw FailedPredicateException(this, "precpred(_ctx, 5)");
          setState(131);
          match(BX0Parser::T__31);
          setState(132);
          expr(6);
          break;
        }

        case 8: {
          auto newContext = _tracker.createInstance<OrContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(133);

          if (!(precpred(_ctx, 4))) throw FailedPredicateException(this, "precpred(_ctx, 4)");
          setState(134);
          match(BX0Parser::T__32);
          setState(135);
          expr(5);
          break;
        }

        case 9: {
          auto newContext = _tracker.createInstance<BoolandContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(136);

          if (!(precpred(_ctx, 3))) throw FailedPredicateException(this, "precpred(_ctx, 3)");
          setState(137);
          match(BX0Parser::T__33);
          setState(138);
          expr(4);
          break;
        }

        case 10: {
          auto newContext = _tracker.createInstance<BoolorContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(139);

          if (!(precpred(_ctx, 2))) throw FailedPredicateException(this, "precpred(_ctx, 2)");
          setState(140);
          match(BX0Parser::T__34);
          setState(141);
          expr(3);
          break;
        }

        } 
      }
      setState(146);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 11, _ctx);
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
    case 11: return exprSempred(dynamic_cast<ExprContext *>(context), predicateIndex);

  default:
    break;
  }
  return true;
}

bool BX0Parser::exprSempred(ExprContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 0: return precpred(_ctx, 11);
    case 1: return precpred(_ctx, 10);
    case 2: return precpred(_ctx, 9);
    case 3: return precpred(_ctx, 8);
    case 4: return precpred(_ctx, 7);
    case 5: return precpred(_ctx, 6);
    case 6: return precpred(_ctx, 5);
    case 7: return precpred(_ctx, 4);
    case 8: return precpred(_ctx, 3);
    case 9: return precpred(_ctx, 2);

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
  "program", "vardecl", "type", "varinit", "statement", "move", "print", 
  "block", "ifelse", "ifelse_bis", "whilee", "expr"
};

std::vector<std::string> BX0Parser::_literalNames = {
  "", "'var'", "','", "':'", "';'", "'int64'", "'bool'", "'='", "'print'", 
  "'{'", "'}'", "'if'", "'('", "')'", "'else'", "'while'", "'~'", "'-'", 
  "'!'", "'*'", "'/'", "'%'", "'+'", "'<<'", "'>>'", "'<'", "'<='", "'>'", 
  "'>='", "'=='", "'!='", "'&'", "'^'", "'|'", "'&&'", "'||'"
};

std::vector<std::string> BX0Parser::_symbolicNames = {
  "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", 
  "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", 
  "VAR", "NUM", "BOOL", "COMMENT", "WS"
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
    0x3, 0x2a, 0x96, 0x4, 0x2, 0x9, 0x2, 0x4, 0x3, 0x9, 0x3, 0x4, 0x4, 0x9, 
    0x4, 0x4, 0x5, 0x9, 0x5, 0x4, 0x6, 0x9, 0x6, 0x4, 0x7, 0x9, 0x7, 0x4, 
    0x8, 0x9, 0x8, 0x4, 0x9, 0x9, 0x9, 0x4, 0xa, 0x9, 0xa, 0x4, 0xb, 0x9, 
    0xb, 0x4, 0xc, 0x9, 0xc, 0x4, 0xd, 0x9, 0xd, 0x3, 0x2, 0x7, 0x2, 0x1c, 
    0xa, 0x2, 0xc, 0x2, 0xe, 0x2, 0x1f, 0xb, 0x2, 0x3, 0x2, 0x7, 0x2, 0x22, 
    0xa, 0x2, 0xc, 0x2, 0xe, 0x2, 0x25, 0xb, 0x2, 0x3, 0x3, 0x3, 0x3, 0x3, 
    0x3, 0x3, 0x3, 0x7, 0x3, 0x2b, 0xa, 0x3, 0xc, 0x3, 0xe, 0x3, 0x2e, 0xb, 
    0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x4, 0x3, 0x4, 0x5, 
    0x4, 0x36, 0xa, 0x4, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x5, 0x5, 0x3b, 0xa, 
    0x5, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x5, 0x6, 0x42, 
    0xa, 0x6, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x8, 0x3, 0x8, 
    0x3, 0x8, 0x3, 0x9, 0x3, 0x9, 0x7, 0x9, 0x4d, 0xa, 0x9, 0xc, 0x9, 0xe, 
    0x9, 0x50, 0xb, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 
    0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x5, 0xa, 0x5b, 0xa, 0xa, 0x3, 
    0xb, 0x3, 0xb, 0x5, 0xb, 0x5f, 0xa, 0xb, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 
    0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 
    0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x5, 0xd, 
    0x71, 0xa, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 
    0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 
    0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 
    0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 
    0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x7, 0xd, 0x91, 0xa, 0xd, 0xc, 0xd, 
    0xe, 0xd, 0x94, 0xb, 0xd, 0x3, 0xd, 0x2, 0x3, 0x18, 0xe, 0x2, 0x4, 0x6, 
    0x8, 0xa, 0xc, 0xe, 0x10, 0x12, 0x14, 0x16, 0x18, 0x2, 0x8, 0x3, 0x2, 
    0x12, 0x14, 0x3, 0x2, 0x15, 0x17, 0x4, 0x2, 0x13, 0x13, 0x18, 0x18, 
    0x3, 0x2, 0x19, 0x1a, 0x3, 0x2, 0x1b, 0x1e, 0x3, 0x2, 0x1f, 0x20, 0x2, 
    0xa3, 0x2, 0x1d, 0x3, 0x2, 0x2, 0x2, 0x4, 0x26, 0x3, 0x2, 0x2, 0x2, 
    0x6, 0x35, 0x3, 0x2, 0x2, 0x2, 0x8, 0x37, 0x3, 0x2, 0x2, 0x2, 0xa, 0x41, 
    0x3, 0x2, 0x2, 0x2, 0xc, 0x43, 0x3, 0x2, 0x2, 0x2, 0xe, 0x47, 0x3, 0x2, 
    0x2, 0x2, 0x10, 0x4a, 0x3, 0x2, 0x2, 0x2, 0x12, 0x53, 0x3, 0x2, 0x2, 
    0x2, 0x14, 0x5e, 0x3, 0x2, 0x2, 0x2, 0x16, 0x60, 0x3, 0x2, 0x2, 0x2, 
    0x18, 0x70, 0x3, 0x2, 0x2, 0x2, 0x1a, 0x1c, 0x5, 0x4, 0x3, 0x2, 0x1b, 
    0x1a, 0x3, 0x2, 0x2, 0x2, 0x1c, 0x1f, 0x3, 0x2, 0x2, 0x2, 0x1d, 0x1b, 
    0x3, 0x2, 0x2, 0x2, 0x1d, 0x1e, 0x3, 0x2, 0x2, 0x2, 0x1e, 0x23, 0x3, 
    0x2, 0x2, 0x2, 0x1f, 0x1d, 0x3, 0x2, 0x2, 0x2, 0x20, 0x22, 0x5, 0xa, 
    0x6, 0x2, 0x21, 0x20, 0x3, 0x2, 0x2, 0x2, 0x22, 0x25, 0x3, 0x2, 0x2, 
    0x2, 0x23, 0x21, 0x3, 0x2, 0x2, 0x2, 0x23, 0x24, 0x3, 0x2, 0x2, 0x2, 
    0x24, 0x3, 0x3, 0x2, 0x2, 0x2, 0x25, 0x23, 0x3, 0x2, 0x2, 0x2, 0x26, 
    0x27, 0x7, 0x3, 0x2, 0x2, 0x27, 0x2c, 0x5, 0x8, 0x5, 0x2, 0x28, 0x29, 
    0x7, 0x4, 0x2, 0x2, 0x29, 0x2b, 0x5, 0x8, 0x5, 0x2, 0x2a, 0x28, 0x3, 
    0x2, 0x2, 0x2, 0x2b, 0x2e, 0x3, 0x2, 0x2, 0x2, 0x2c, 0x2a, 0x3, 0x2, 
    0x2, 0x2, 0x2c, 0x2d, 0x3, 0x2, 0x2, 0x2, 0x2d, 0x2f, 0x3, 0x2, 0x2, 
    0x2, 0x2e, 0x2c, 0x3, 0x2, 0x2, 0x2, 0x2f, 0x30, 0x7, 0x5, 0x2, 0x2, 
    0x30, 0x31, 0x5, 0x6, 0x4, 0x2, 0x31, 0x32, 0x7, 0x6, 0x2, 0x2, 0x32, 
    0x5, 0x3, 0x2, 0x2, 0x2, 0x33, 0x36, 0x7, 0x7, 0x2, 0x2, 0x34, 0x36, 
    0x7, 0x8, 0x2, 0x2, 0x35, 0x33, 0x3, 0x2, 0x2, 0x2, 0x35, 0x34, 0x3, 
    0x2, 0x2, 0x2, 0x36, 0x7, 0x3, 0x2, 0x2, 0x2, 0x37, 0x3a, 0x7, 0x26, 
    0x2, 0x2, 0x38, 0x39, 0x7, 0x9, 0x2, 0x2, 0x39, 0x3b, 0x5, 0x18, 0xd, 
    0x2, 0x3a, 0x38, 0x3, 0x2, 0x2, 0x2, 0x3a, 0x3b, 0x3, 0x2, 0x2, 0x2, 
    0x3b, 0x9, 0x3, 0x2, 0x2, 0x2, 0x3c, 0x42, 0x5, 0xc, 0x7, 0x2, 0x3d, 
    0x42, 0x5, 0xe, 0x8, 0x2, 0x3e, 0x42, 0x5, 0x10, 0x9, 0x2, 0x3f, 0x42, 
    0x5, 0x12, 0xa, 0x2, 0x40, 0x42, 0x5, 0x16, 0xc, 0x2, 0x41, 0x3c, 0x3, 
    0x2, 0x2, 0x2, 0x41, 0x3d, 0x3, 0x2, 0x2, 0x2, 0x41, 0x3e, 0x3, 0x2, 
    0x2, 0x2, 0x41, 0x3f, 0x3, 0x2, 0x2, 0x2, 0x41, 0x40, 0x3, 0x2, 0x2, 
    0x2, 0x42, 0xb, 0x3, 0x2, 0x2, 0x2, 0x43, 0x44, 0x7, 0x26, 0x2, 0x2, 
    0x44, 0x45, 0x7, 0x9, 0x2, 0x2, 0x45, 0x46, 0x5, 0x18, 0xd, 0x2, 0x46, 
    0xd, 0x3, 0x2, 0x2, 0x2, 0x47, 0x48, 0x7, 0xa, 0x2, 0x2, 0x48, 0x49, 
    0x5, 0x18, 0xd, 0x2, 0x49, 0xf, 0x3, 0x2, 0x2, 0x2, 0x4a, 0x4e, 0x7, 
    0xb, 0x2, 0x2, 0x4b, 0x4d, 0x5, 0xa, 0x6, 0x2, 0x4c, 0x4b, 0x3, 0x2, 
    0x2, 0x2, 0x4d, 0x50, 0x3, 0x2, 0x2, 0x2, 0x4e, 0x4c, 0x3, 0x2, 0x2, 
    0x2, 0x4e, 0x4f, 0x3, 0x2, 0x2, 0x2, 0x4f, 0x51, 0x3, 0x2, 0x2, 0x2, 
    0x50, 0x4e, 0x3, 0x2, 0x2, 0x2, 0x51, 0x52, 0x7, 0xc, 0x2, 0x2, 0x52, 
    0x11, 0x3, 0x2, 0x2, 0x2, 0x53, 0x54, 0x7, 0xd, 0x2, 0x2, 0x54, 0x55, 
    0x7, 0xe, 0x2, 0x2, 0x55, 0x56, 0x5, 0x18, 0xd, 0x2, 0x56, 0x57, 0x7, 
    0xf, 0x2, 0x2, 0x57, 0x5a, 0x5, 0x10, 0x9, 0x2, 0x58, 0x59, 0x7, 0x10, 
    0x2, 0x2, 0x59, 0x5b, 0x5, 0x14, 0xb, 0x2, 0x5a, 0x58, 0x3, 0x2, 0x2, 
    0x2, 0x5a, 0x5b, 0x3, 0x2, 0x2, 0x2, 0x5b, 0x13, 0x3, 0x2, 0x2, 0x2, 
    0x5c, 0x5f, 0x5, 0x12, 0xa, 0x2, 0x5d, 0x5f, 0x5, 0x10, 0x9, 0x2, 0x5e, 
    0x5c, 0x3, 0x2, 0x2, 0x2, 0x5e, 0x5d, 0x3, 0x2, 0x2, 0x2, 0x5f, 0x15, 
    0x3, 0x2, 0x2, 0x2, 0x60, 0x61, 0x7, 0x11, 0x2, 0x2, 0x61, 0x62, 0x7, 
    0xe, 0x2, 0x2, 0x62, 0x63, 0x5, 0x18, 0xd, 0x2, 0x63, 0x64, 0x7, 0xf, 
    0x2, 0x2, 0x64, 0x65, 0x5, 0x10, 0x9, 0x2, 0x65, 0x17, 0x3, 0x2, 0x2, 
    0x2, 0x66, 0x67, 0x8, 0xd, 0x1, 0x2, 0x67, 0x71, 0x7, 0x26, 0x2, 0x2, 
    0x68, 0x71, 0x7, 0x27, 0x2, 0x2, 0x69, 0x71, 0x7, 0x28, 0x2, 0x2, 0x6a, 
    0x6b, 0x9, 0x2, 0x2, 0x2, 0x6b, 0x71, 0x5, 0x18, 0xd, 0xe, 0x6c, 0x6d, 
    0x7, 0xe, 0x2, 0x2, 0x6d, 0x6e, 0x5, 0x18, 0xd, 0x2, 0x6e, 0x6f, 0x7, 
    0xf, 0x2, 0x2, 0x6f, 0x71, 0x3, 0x2, 0x2, 0x2, 0x70, 0x66, 0x3, 0x2, 
    0x2, 0x2, 0x70, 0x68, 0x3, 0x2, 0x2, 0x2, 0x70, 0x69, 0x3, 0x2, 0x2, 
    0x2, 0x70, 0x6a, 0x3, 0x2, 0x2, 0x2, 0x70, 0x6c, 0x3, 0x2, 0x2, 0x2, 
    0x71, 0x92, 0x3, 0x2, 0x2, 0x2, 0x72, 0x73, 0xc, 0xd, 0x2, 0x2, 0x73, 
    0x74, 0x9, 0x3, 0x2, 0x2, 0x74, 0x91, 0x5, 0x18, 0xd, 0xe, 0x75, 0x76, 
    0xc, 0xc, 0x2, 0x2, 0x76, 0x77, 0x9, 0x4, 0x2, 0x2, 0x77, 0x91, 0x5, 
    0x18, 0xd, 0xd, 0x78, 0x79, 0xc, 0xb, 0x2, 0x2, 0x79, 0x7a, 0x9, 0x5, 
    0x2, 0x2, 0x7a, 0x91, 0x5, 0x18, 0xd, 0xc, 0x7b, 0x7c, 0xc, 0xa, 0x2, 
    0x2, 0x7c, 0x7d, 0x9, 0x6, 0x2, 0x2, 0x7d, 0x91, 0x5, 0x18, 0xd, 0xb, 
    0x7e, 0x7f, 0xc, 0x9, 0x2, 0x2, 0x7f, 0x80, 0x9, 0x7, 0x2, 0x2, 0x80, 
    0x91, 0x5, 0x18, 0xd, 0xa, 0x81, 0x82, 0xc, 0x8, 0x2, 0x2, 0x82, 0x83, 
    0x7, 0x21, 0x2, 0x2, 0x83, 0x91, 0x5, 0x18, 0xd, 0x9, 0x84, 0x85, 0xc, 
    0x7, 0x2, 0x2, 0x85, 0x86, 0x7, 0x22, 0x2, 0x2, 0x86, 0x91, 0x5, 0x18, 
    0xd, 0x8, 0x87, 0x88, 0xc, 0x6, 0x2, 0x2, 0x88, 0x89, 0x7, 0x23, 0x2, 
    0x2, 0x89, 0x91, 0x5, 0x18, 0xd, 0x7, 0x8a, 0x8b, 0xc, 0x5, 0x2, 0x2, 
    0x8b, 0x8c, 0x7, 0x24, 0x2, 0x2, 0x8c, 0x91, 0x5, 0x18, 0xd, 0x6, 0x8d, 
    0x8e, 0xc, 0x4, 0x2, 0x2, 0x8e, 0x8f, 0x7, 0x25, 0x2, 0x2, 0x8f, 0x91, 
    0x5, 0x18, 0xd, 0x5, 0x90, 0x72, 0x3, 0x2, 0x2, 0x2, 0x90, 0x75, 0x3, 
    0x2, 0x2, 0x2, 0x90, 0x78, 0x3, 0x2, 0x2, 0x2, 0x90, 0x7b, 0x3, 0x2, 
    0x2, 0x2, 0x90, 0x7e, 0x3, 0x2, 0x2, 0x2, 0x90, 0x81, 0x3, 0x2, 0x2, 
    0x2, 0x90, 0x84, 0x3, 0x2, 0x2, 0x2, 0x90, 0x87, 0x3, 0x2, 0x2, 0x2, 
    0x90, 0x8a, 0x3, 0x2, 0x2, 0x2, 0x90, 0x8d, 0x3, 0x2, 0x2, 0x2, 0x91, 
    0x94, 0x3, 0x2, 0x2, 0x2, 0x92, 0x90, 0x3, 0x2, 0x2, 0x2, 0x92, 0x93, 
    0x3, 0x2, 0x2, 0x2, 0x93, 0x19, 0x3, 0x2, 0x2, 0x2, 0x94, 0x92, 0x3, 
    0x2, 0x2, 0x2, 0xe, 0x1d, 0x23, 0x2c, 0x35, 0x3a, 0x41, 0x4e, 0x5a, 
    0x5e, 0x70, 0x90, 0x92, 
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
