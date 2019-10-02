
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

  virtual void enterVardecl(BX0Parser::VardeclContext * /*ctx*/) override { }
  virtual void exitVardecl(BX0Parser::VardeclContext * /*ctx*/) override { }

  virtual void enterInteger(BX0Parser::IntegerContext * /*ctx*/) override { }
  virtual void exitInteger(BX0Parser::IntegerContext * /*ctx*/) override { }

  virtual void enterBoole(BX0Parser::BooleContext * /*ctx*/) override { }
  virtual void exitBoole(BX0Parser::BooleContext * /*ctx*/) override { }

  virtual void enterVarinit(BX0Parser::VarinitContext * /*ctx*/) override { }
  virtual void exitVarinit(BX0Parser::VarinitContext * /*ctx*/) override { }

  virtual void enterStatement(BX0Parser::StatementContext * /*ctx*/) override { }
  virtual void exitStatement(BX0Parser::StatementContext * /*ctx*/) override { }

  virtual void enterMove(BX0Parser::MoveContext * /*ctx*/) override { }
  virtual void exitMove(BX0Parser::MoveContext * /*ctx*/) override { }

  virtual void enterPrint(BX0Parser::PrintContext * /*ctx*/) override { }
  virtual void exitPrint(BX0Parser::PrintContext * /*ctx*/) override { }

  virtual void enterBlock(BX0Parser::BlockContext * /*ctx*/) override { }
  virtual void exitBlock(BX0Parser::BlockContext * /*ctx*/) override { }

  virtual void enterIfelse(BX0Parser::IfelseContext * /*ctx*/) override { }
  virtual void exitIfelse(BX0Parser::IfelseContext * /*ctx*/) override { }

  virtual void enterIfelse_bis(BX0Parser::Ifelse_bisContext * /*ctx*/) override { }
  virtual void exitIfelse_bis(BX0Parser::Ifelse_bisContext * /*ctx*/) override { }

  virtual void enterWhilee(BX0Parser::WhileeContext * /*ctx*/) override { }
  virtual void exitWhilee(BX0Parser::WhileeContext * /*ctx*/) override { }

  virtual void enterAdd(BX0Parser::AddContext * /*ctx*/) override { }
  virtual void exitAdd(BX0Parser::AddContext * /*ctx*/) override { }

  virtual void enterParens(BX0Parser::ParensContext * /*ctx*/) override { }
  virtual void exitParens(BX0Parser::ParensContext * /*ctx*/) override { }

  virtual void enterOr(BX0Parser::OrContext * /*ctx*/) override { }
  virtual void exitOr(BX0Parser::OrContext * /*ctx*/) override { }

  virtual void enterMul(BX0Parser::MulContext * /*ctx*/) override { }
  virtual void exitMul(BX0Parser::MulContext * /*ctx*/) override { }

  virtual void enterBoolor(BX0Parser::BoolorContext * /*ctx*/) override { }
  virtual void exitBoolor(BX0Parser::BoolorContext * /*ctx*/) override { }

  virtual void enterShift(BX0Parser::ShiftContext * /*ctx*/) override { }
  virtual void exitShift(BX0Parser::ShiftContext * /*ctx*/) override { }

  virtual void enterUnop(BX0Parser::UnopContext * /*ctx*/) override { }
  virtual void exitUnop(BX0Parser::UnopContext * /*ctx*/) override { }

  virtual void enterNumber(BX0Parser::NumberContext * /*ctx*/) override { }
  virtual void exitNumber(BX0Parser::NumberContext * /*ctx*/) override { }

  virtual void enterInequality(BX0Parser::InequalityContext * /*ctx*/) override { }
  virtual void exitInequality(BX0Parser::InequalityContext * /*ctx*/) override { }

  virtual void enterBoolean(BX0Parser::BooleanContext * /*ctx*/) override { }
  virtual void exitBoolean(BX0Parser::BooleanContext * /*ctx*/) override { }

  virtual void enterAnd(BX0Parser::AndContext * /*ctx*/) override { }
  virtual void exitAnd(BX0Parser::AndContext * /*ctx*/) override { }

  virtual void enterBooland(BX0Parser::BoolandContext * /*ctx*/) override { }
  virtual void exitBooland(BX0Parser::BoolandContext * /*ctx*/) override { }

  virtual void enterVariable(BX0Parser::VariableContext * /*ctx*/) override { }
  virtual void exitVariable(BX0Parser::VariableContext * /*ctx*/) override { }

  virtual void enterXor(BX0Parser::XorContext * /*ctx*/) override { }
  virtual void exitXor(BX0Parser::XorContext * /*ctx*/) override { }

  virtual void enterEquality(BX0Parser::EqualityContext * /*ctx*/) override { }
  virtual void exitEquality(BX0Parser::EqualityContext * /*ctx*/) override { }


  virtual void enterEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void exitEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void visitTerminal(antlr4::tree::TerminalNode * /*node*/) override { }
  virtual void visitErrorNode(antlr4::tree::ErrorNode * /*node*/) override { }

};

}  // namespace bx
