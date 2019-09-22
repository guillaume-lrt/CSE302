
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
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(6);
    statement();
    setState(11);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 0, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(7);
        match(BX0Parser::T__0);
        setState(8);
        statement(); 
      }
      setState(13);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 0, _ctx);
    }
    setState(15);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == BX0Parser::T__0) {
      setState(14);
      match(BX0Parser::T__0);
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


size_t BX0Parser::StatementContext::getRuleIndex() const {
  return BX0Parser::RuleStatement;
}

void BX0Parser::StatementContext::copyFrom(StatementContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- MoveContext ------------------------------------------------------------------

tree::TerminalNode* BX0Parser::MoveContext::VAR() {
  return getToken(BX0Parser::VAR, 0);
}

BX0Parser::ExprContext* BX0Parser::MoveContext::expr() {
  return getRuleContext<BX0Parser::ExprContext>(0);
}

BX0Parser::MoveContext::MoveContext(StatementContext *ctx) { copyFrom(ctx); }

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
//----------------- PrintContext ------------------------------------------------------------------

BX0Parser::ExprContext* BX0Parser::PrintContext::expr() {
  return getRuleContext<BX0Parser::ExprContext>(0);
}

BX0Parser::PrintContext::PrintContext(StatementContext *ctx) { copyFrom(ctx); }

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
BX0Parser::StatementContext* BX0Parser::statement() {
  StatementContext *_localctx = _tracker.createInstance<StatementContext>(_ctx, getState());
  enterRule(_localctx, 2, BX0Parser::RuleStatement);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(22);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case BX0Parser::VAR: {
        _localctx = dynamic_cast<StatementContext *>(_tracker.createInstance<BX0Parser::MoveContext>(_localctx));
        enterOuterAlt(_localctx, 1);
        setState(17);
        match(BX0Parser::VAR);
        setState(18);
        match(BX0Parser::T__1);
        setState(19);
        expr(0);
        break;
      }

      case BX0Parser::T__2: {
        _localctx = dynamic_cast<StatementContext *>(_tracker.createInstance<BX0Parser::PrintContext>(_localctx));
        enterOuterAlt(_localctx, 2);
        setState(20);
        match(BX0Parser::T__2);
        setState(21);
        expr(0);
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

BX0Parser::ExprContext* BX0Parser::expr() {
   return expr(0);
}

BX0Parser::ExprContext* BX0Parser::expr(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  BX0Parser::ExprContext *_localctx = _tracker.createInstance<ExprContext>(_ctx, parentState);
  BX0Parser::ExprContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 4;
  enterRecursionRule(_localctx, 4, BX0Parser::RuleExpr, precedence);

    size_t _la = 0;

  auto onExit = finally([=] {
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(33);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case BX0Parser::VAR: {
        _localctx = _tracker.createInstance<VariableContext>(_localctx);
        _ctx = _localctx;
        previousContext = _localctx;

        setState(25);
        match(BX0Parser::VAR);
        break;
      }

      case BX0Parser::NUM: {
        _localctx = _tracker.createInstance<NumberContext>(_localctx);
        _ctx = _localctx;
        previousContext = _localctx;
        setState(26);
        match(BX0Parser::NUM);
        break;
      }

      case BX0Parser::T__3:
      case BX0Parser::T__4: {
        _localctx = _tracker.createInstance<UnopContext>(_localctx);
        _ctx = _localctx;
        previousContext = _localctx;
        setState(27);
        dynamic_cast<UnopContext *>(_localctx)->op = _input->LT(1);
        _la = _input->LA(1);
        if (!(_la == BX0Parser::T__3

        || _la == BX0Parser::T__4)) {
          dynamic_cast<UnopContext *>(_localctx)->op = _errHandler->recoverInline(this);
        }
        else {
          _errHandler->reportMatch(this);
          consume();
        }
        setState(28);
        expr(8);
        break;
      }

      case BX0Parser::T__14: {
        _localctx = _tracker.createInstance<ParensContext>(_localctx);
        _ctx = _localctx;
        previousContext = _localctx;
        setState(29);
        match(BX0Parser::T__14);
        setState(30);
        expr(0);
        setState(31);
        match(BX0Parser::T__15);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    _ctx->stop = _input->LT(-1);
    setState(55);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 5, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(53);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 4, _ctx)) {
        case 1: {
          auto newContext = _tracker.createInstance<MulContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(35);

          if (!(precpred(_ctx, 7))) throw FailedPredicateException(this, "precpred(_ctx, 7)");
          setState(36);
          dynamic_cast<MulContext *>(_localctx)->op = _input->LT(1);
          _la = _input->LA(1);
          if (!((((_la & ~ 0x3fULL) == 0) &&
            ((1ULL << _la) & ((1ULL << BX0Parser::T__5)
            | (1ULL << BX0Parser::T__6)
            | (1ULL << BX0Parser::T__7))) != 0))) {
            dynamic_cast<MulContext *>(_localctx)->op = _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(37);
          expr(8);
          break;
        }

        case 2: {
          auto newContext = _tracker.createInstance<AddContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(38);

          if (!(precpred(_ctx, 6))) throw FailedPredicateException(this, "precpred(_ctx, 6)");
          setState(39);
          dynamic_cast<AddContext *>(_localctx)->op = _input->LT(1);
          _la = _input->LA(1);
          if (!(_la == BX0Parser::T__4

          || _la == BX0Parser::T__8)) {
            dynamic_cast<AddContext *>(_localctx)->op = _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(40);
          expr(7);
          break;
        }

        case 3: {
          auto newContext = _tracker.createInstance<ShiftContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(41);

          if (!(precpred(_ctx, 5))) throw FailedPredicateException(this, "precpred(_ctx, 5)");
          setState(42);
          dynamic_cast<ShiftContext *>(_localctx)->op = _input->LT(1);
          _la = _input->LA(1);
          if (!(_la == BX0Parser::T__9

          || _la == BX0Parser::T__10)) {
            dynamic_cast<ShiftContext *>(_localctx)->op = _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(43);
          expr(6);
          break;
        }

        case 4: {
          auto newContext = _tracker.createInstance<AndContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(44);

          if (!(precpred(_ctx, 4))) throw FailedPredicateException(this, "precpred(_ctx, 4)");
          setState(45);
          match(BX0Parser::T__11);
          setState(46);
          expr(5);
          break;
        }

        case 5: {
          auto newContext = _tracker.createInstance<XorContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(47);

          if (!(precpred(_ctx, 3))) throw FailedPredicateException(this, "precpred(_ctx, 3)");
          setState(48);
          match(BX0Parser::T__12);
          setState(49);
          expr(4);
          break;
        }

        case 6: {
          auto newContext = _tracker.createInstance<OrContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(50);

          if (!(precpred(_ctx, 2))) throw FailedPredicateException(this, "precpred(_ctx, 2)");
          setState(51);
          match(BX0Parser::T__13);
          setState(52);
          expr(3);
          break;
        }

        } 
      }
      setState(57);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 5, _ctx);
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
    case 2: return exprSempred(dynamic_cast<ExprContext *>(context), predicateIndex);

  default:
    break;
  }
  return true;
}

bool BX0Parser::exprSempred(ExprContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 0: return precpred(_ctx, 7);
    case 1: return precpred(_ctx, 6);
    case 2: return precpred(_ctx, 5);
    case 3: return precpred(_ctx, 4);
    case 4: return precpred(_ctx, 3);
    case 5: return precpred(_ctx, 2);

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
  "program", "statement", "expr"
};

std::vector<std::string> BX0Parser::_literalNames = {
  "", "';'", "'='", "'print'", "'~'", "'-'", "'*'", "'/'", "'%'", "'+'", 
  "'<<'", "'>>'", "'&'", "'^'", "'|'", "'('", "')'"
};

std::vector<std::string> BX0Parser::_symbolicNames = {
  "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "VAR", 
  "NUM", "WS"
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
    0x3, 0x15, 0x3d, 0x4, 0x2, 0x9, 0x2, 0x4, 0x3, 0x9, 0x3, 0x4, 0x4, 0x9, 
    0x4, 0x3, 0x2, 0x3, 0x2, 0x3, 0x2, 0x7, 0x2, 0xc, 0xa, 0x2, 0xc, 0x2, 
    0xe, 0x2, 0xf, 0xb, 0x2, 0x3, 0x2, 0x5, 0x2, 0x12, 0xa, 0x2, 0x3, 0x3, 
    0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x5, 0x3, 0x19, 0xa, 0x3, 0x3, 
    0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 
    0x4, 0x3, 0x4, 0x5, 0x4, 0x24, 0xa, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 
    0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 
    0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 
    0x3, 0x4, 0x7, 0x4, 0x38, 0xa, 0x4, 0xc, 0x4, 0xe, 0x4, 0x3b, 0xb, 0x4, 
    0x3, 0x4, 0x2, 0x3, 0x6, 0x5, 0x2, 0x4, 0x6, 0x2, 0x6, 0x3, 0x2, 0x6, 
    0x7, 0x3, 0x2, 0x8, 0xa, 0x4, 0x2, 0x7, 0x7, 0xb, 0xb, 0x3, 0x2, 0xc, 
    0xd, 0x2, 0x45, 0x2, 0x8, 0x3, 0x2, 0x2, 0x2, 0x4, 0x18, 0x3, 0x2, 0x2, 
    0x2, 0x6, 0x23, 0x3, 0x2, 0x2, 0x2, 0x8, 0xd, 0x5, 0x4, 0x3, 0x2, 0x9, 
    0xa, 0x7, 0x3, 0x2, 0x2, 0xa, 0xc, 0x5, 0x4, 0x3, 0x2, 0xb, 0x9, 0x3, 
    0x2, 0x2, 0x2, 0xc, 0xf, 0x3, 0x2, 0x2, 0x2, 0xd, 0xb, 0x3, 0x2, 0x2, 
    0x2, 0xd, 0xe, 0x3, 0x2, 0x2, 0x2, 0xe, 0x11, 0x3, 0x2, 0x2, 0x2, 0xf, 
    0xd, 0x3, 0x2, 0x2, 0x2, 0x10, 0x12, 0x7, 0x3, 0x2, 0x2, 0x11, 0x10, 
    0x3, 0x2, 0x2, 0x2, 0x11, 0x12, 0x3, 0x2, 0x2, 0x2, 0x12, 0x3, 0x3, 
    0x2, 0x2, 0x2, 0x13, 0x14, 0x7, 0x13, 0x2, 0x2, 0x14, 0x15, 0x7, 0x4, 
    0x2, 0x2, 0x15, 0x19, 0x5, 0x6, 0x4, 0x2, 0x16, 0x17, 0x7, 0x5, 0x2, 
    0x2, 0x17, 0x19, 0x5, 0x6, 0x4, 0x2, 0x18, 0x13, 0x3, 0x2, 0x2, 0x2, 
    0x18, 0x16, 0x3, 0x2, 0x2, 0x2, 0x19, 0x5, 0x3, 0x2, 0x2, 0x2, 0x1a, 
    0x1b, 0x8, 0x4, 0x1, 0x2, 0x1b, 0x24, 0x7, 0x13, 0x2, 0x2, 0x1c, 0x24, 
    0x7, 0x14, 0x2, 0x2, 0x1d, 0x1e, 0x9, 0x2, 0x2, 0x2, 0x1e, 0x24, 0x5, 
    0x6, 0x4, 0xa, 0x1f, 0x20, 0x7, 0x11, 0x2, 0x2, 0x20, 0x21, 0x5, 0x6, 
    0x4, 0x2, 0x21, 0x22, 0x7, 0x12, 0x2, 0x2, 0x22, 0x24, 0x3, 0x2, 0x2, 
    0x2, 0x23, 0x1a, 0x3, 0x2, 0x2, 0x2, 0x23, 0x1c, 0x3, 0x2, 0x2, 0x2, 
    0x23, 0x1d, 0x3, 0x2, 0x2, 0x2, 0x23, 0x1f, 0x3, 0x2, 0x2, 0x2, 0x24, 
    0x39, 0x3, 0x2, 0x2, 0x2, 0x25, 0x26, 0xc, 0x9, 0x2, 0x2, 0x26, 0x27, 
    0x9, 0x3, 0x2, 0x2, 0x27, 0x38, 0x5, 0x6, 0x4, 0xa, 0x28, 0x29, 0xc, 
    0x8, 0x2, 0x2, 0x29, 0x2a, 0x9, 0x4, 0x2, 0x2, 0x2a, 0x38, 0x5, 0x6, 
    0x4, 0x9, 0x2b, 0x2c, 0xc, 0x7, 0x2, 0x2, 0x2c, 0x2d, 0x9, 0x5, 0x2, 
    0x2, 0x2d, 0x38, 0x5, 0x6, 0x4, 0x8, 0x2e, 0x2f, 0xc, 0x6, 0x2, 0x2, 
    0x2f, 0x30, 0x7, 0xe, 0x2, 0x2, 0x30, 0x38, 0x5, 0x6, 0x4, 0x7, 0x31, 
    0x32, 0xc, 0x5, 0x2, 0x2, 0x32, 0x33, 0x7, 0xf, 0x2, 0x2, 0x33, 0x38, 
    0x5, 0x6, 0x4, 0x6, 0x34, 0x35, 0xc, 0x4, 0x2, 0x2, 0x35, 0x36, 0x7, 
    0x10, 0x2, 0x2, 0x36, 0x38, 0x5, 0x6, 0x4, 0x5, 0x37, 0x25, 0x3, 0x2, 
    0x2, 0x2, 0x37, 0x28, 0x3, 0x2, 0x2, 0x2, 0x37, 0x2b, 0x3, 0x2, 0x2, 
    0x2, 0x37, 0x2e, 0x3, 0x2, 0x2, 0x2, 0x37, 0x31, 0x3, 0x2, 0x2, 0x2, 
    0x37, 0x34, 0x3, 0x2, 0x2, 0x2, 0x38, 0x3b, 0x3, 0x2, 0x2, 0x2, 0x39, 
    0x37, 0x3, 0x2, 0x2, 0x2, 0x39, 0x3a, 0x3, 0x2, 0x2, 0x2, 0x3a, 0x7, 
    0x3, 0x2, 0x2, 0x2, 0x3b, 0x39, 0x3, 0x2, 0x2, 0x2, 0x8, 0xd, 0x11, 
    0x18, 0x23, 0x37, 0x39, 
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
