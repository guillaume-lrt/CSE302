
// Generated from BX0.g4 by ANTLR 4.7.2

#pragma once


#include "antlr4-runtime.h"
#include "BX0Listener.h"


namespace bx {

/**
 * This class provides an empty implementation of BX0Listener,
 * which can be extended to create a listener which only needs to handle a subset
 * of the available methods.
 */
class  BX0BaseListener : public BX0Listener {
public:

  virtual void enterProgram(BX0Parser::ProgramContext * /*ctx*/) override { }
  virtual void exitProgram(BX0Parser::ProgramContext * /*ctx*/) override { }

  virtual void enterMove(BX0Parser::MoveContext * /*ctx*/) override { }
  virtual void exitMove(BX0Parser::MoveContext * /*ctx*/) override { }

  virtual void enterPrint(BX0Parser::PrintContext * /*ctx*/) override { }
  virtual void exitPrint(BX0Parser::PrintContext * /*ctx*/) override { }

  virtual void enterAdd(BX0Parser::AddContext * /*ctx*/) override { }
  virtual void exitAdd(BX0Parser::AddContext * /*ctx*/) override { }

  virtual void enterNumber(BX0Parser::NumberContext * /*ctx*/) override { }
  virtual void exitNumber(BX0Parser::NumberContext * /*ctx*/) override { }

  virtual void enterParens(BX0Parser::ParensContext * /*ctx*/) override { }
  virtual void exitParens(BX0Parser::ParensContext * /*ctx*/) override { }

  virtual void enterOr(BX0Parser::OrContext * /*ctx*/) override { }
  virtual void exitOr(BX0Parser::OrContext * /*ctx*/) override { }

  virtual void enterMul(BX0Parser::MulContext * /*ctx*/) override { }
  virtual void exitMul(BX0Parser::MulContext * /*ctx*/) override { }

  virtual void enterAnd(BX0Parser::AndContext * /*ctx*/) override { }
  virtual void exitAnd(BX0Parser::AndContext * /*ctx*/) override { }

  virtual void enterShift(BX0Parser::ShiftContext * /*ctx*/) override { }
  virtual void exitShift(BX0Parser::ShiftContext * /*ctx*/) override { }

  virtual void enterVariable(BX0Parser::VariableContext * /*ctx*/) override { }
  virtual void exitVariable(BX0Parser::VariableContext * /*ctx*/) override { }

  virtual void enterXor(BX0Parser::XorContext * /*ctx*/) override { }
  virtual void exitXor(BX0Parser::XorContext * /*ctx*/) override { }

  virtual void enterUnop(BX0Parser::UnopContext * /*ctx*/) override { }
  virtual void exitUnop(BX0Parser::UnopContext * /*ctx*/) override { }


  virtual void enterEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void exitEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void visitTerminal(antlr4::tree::TerminalNode * /*node*/) override { }
  virtual void visitErrorNode(antlr4::tree::ErrorNode * /*node*/) override { }

};

}  // namespace bx
