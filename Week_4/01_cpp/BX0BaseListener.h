
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

  virtual void enterGlobalvar(BX0Parser::GlobalvarContext * /*ctx*/) override { }
  virtual void exitGlobalvar(BX0Parser::GlobalvarContext * /*ctx*/) override { }

  virtual void enterGlobalvar_init(BX0Parser::Globalvar_initContext * /*ctx*/) override { }
  virtual void exitGlobalvar_init(BX0Parser::Globalvar_initContext * /*ctx*/) override { }

  virtual void enterFunction(BX0Parser::FunctionContext * /*ctx*/) override { }
  virtual void exitFunction(BX0Parser::FunctionContext * /*ctx*/) override { }

  virtual void enterProcedure(BX0Parser::ProcedureContext * /*ctx*/) override { }
  virtual void exitProcedure(BX0Parser::ProcedureContext * /*ctx*/) override { }

  virtual void enterParameter_groups(BX0Parser::Parameter_groupsContext * /*ctx*/) override { }
  virtual void exitParameter_groups(BX0Parser::Parameter_groupsContext * /*ctx*/) override { }

  virtual void enterParameter_group(BX0Parser::Parameter_groupContext * /*ctx*/) override { }
  virtual void exitParameter_group(BX0Parser::Parameter_groupContext * /*ctx*/) override { }

  virtual void enterStmt(BX0Parser::StmtContext * /*ctx*/) override { }
  virtual void exitStmt(BX0Parser::StmtContext * /*ctx*/) override { }

  virtual void enterVardecl(BX0Parser::VardeclContext * /*ctx*/) override { }
  virtual void exitVardecl(BX0Parser::VardeclContext * /*ctx*/) override { }

  virtual void enterVarinit(BX0Parser::VarinitContext * /*ctx*/) override { }
  virtual void exitVarinit(BX0Parser::VarinitContext * /*ctx*/) override { }

  virtual void enterType(BX0Parser::TypeContext * /*ctx*/) override { }
  virtual void exitType(BX0Parser::TypeContext * /*ctx*/) override { }

  virtual void enterBlock(BX0Parser::BlockContext * /*ctx*/) override { }
  virtual void exitBlock(BX0Parser::BlockContext * /*ctx*/) override { }

  virtual void enterExpress(BX0Parser::ExpressContext * /*ctx*/) override { }
  virtual void exitExpress(BX0Parser::ExpressContext * /*ctx*/) override { }

  virtual void enterMove(BX0Parser::MoveContext * /*ctx*/) override { }
  virtual void exitMove(BX0Parser::MoveContext * /*ctx*/) override { }

  virtual void enterPrint(BX0Parser::PrintContext * /*ctx*/) override { }
  virtual void exitPrint(BX0Parser::PrintContext * /*ctx*/) override { }

  virtual void enterIfelse(BX0Parser::IfelseContext * /*ctx*/) override { }
  virtual void exitIfelse(BX0Parser::IfelseContext * /*ctx*/) override { }

  virtual void enterIfCont(BX0Parser::IfContContext * /*ctx*/) override { }
  virtual void exitIfCont(BX0Parser::IfContContext * /*ctx*/) override { }

  virtual void enterWhileLoop(BX0Parser::WhileLoopContext * /*ctx*/) override { }
  virtual void exitWhileLoop(BX0Parser::WhileLoopContext * /*ctx*/) override { }

  virtual void enterReturnStmt(BX0Parser::ReturnStmtContext * /*ctx*/) override { }
  virtual void exitReturnStmt(BX0Parser::ReturnStmtContext * /*ctx*/) override { }

  virtual void enterParens(BX0Parser::ParensContext * /*ctx*/) override { }
  virtual void exitParens(BX0Parser::ParensContext * /*ctx*/) override { }

  virtual void enterInequation(BX0Parser::InequationContext * /*ctx*/) override { }
  virtual void exitInequation(BX0Parser::InequationContext * /*ctx*/) override { }

  virtual void enterBitOr(BX0Parser::BitOrContext * /*ctx*/) override { }
  virtual void exitBitOr(BX0Parser::BitOrContext * /*ctx*/) override { }

  virtual void enterShift(BX0Parser::ShiftContext * /*ctx*/) override { }
  virtual void exitShift(BX0Parser::ShiftContext * /*ctx*/) override { }

  virtual void enterEquation(BX0Parser::EquationContext * /*ctx*/) override { }
  virtual void exitEquation(BX0Parser::EquationContext * /*ctx*/) override { }

  virtual void enterMultiplicative(BX0Parser::MultiplicativeContext * /*ctx*/) override { }
  virtual void exitMultiplicative(BX0Parser::MultiplicativeContext * /*ctx*/) override { }

  virtual void enterUnop(BX0Parser::UnopContext * /*ctx*/) override { }
  virtual void exitUnop(BX0Parser::UnopContext * /*ctx*/) override { }

  virtual void enterAdditive(BX0Parser::AdditiveContext * /*ctx*/) override { }
  virtual void exitAdditive(BX0Parser::AdditiveContext * /*ctx*/) override { }

  virtual void enterCall(BX0Parser::CallContext * /*ctx*/) override { }
  virtual void exitCall(BX0Parser::CallContext * /*ctx*/) override { }

  virtual void enterNumber(BX0Parser::NumberContext * /*ctx*/) override { }
  virtual void exitNumber(BX0Parser::NumberContext * /*ctx*/) override { }

  virtual void enterBitAnd(BX0Parser::BitAndContext * /*ctx*/) override { }
  virtual void exitBitAnd(BX0Parser::BitAndContext * /*ctx*/) override { }

  virtual void enterBoolean(BX0Parser::BooleanContext * /*ctx*/) override { }
  virtual void exitBoolean(BX0Parser::BooleanContext * /*ctx*/) override { }

  virtual void enterBitXor(BX0Parser::BitXorContext * /*ctx*/) override { }
  virtual void exitBitXor(BX0Parser::BitXorContext * /*ctx*/) override { }

  virtual void enterVariable(BX0Parser::VariableContext * /*ctx*/) override { }
  virtual void exitVariable(BX0Parser::VariableContext * /*ctx*/) override { }

  virtual void enterBoolOr(BX0Parser::BoolOrContext * /*ctx*/) override { }
  virtual void exitBoolOr(BX0Parser::BoolOrContext * /*ctx*/) override { }

  virtual void enterBoolAnd(BX0Parser::BoolAndContext * /*ctx*/) override { }
  virtual void exitBoolAnd(BX0Parser::BoolAndContext * /*ctx*/) override { }


  virtual void enterEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void exitEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void visitTerminal(antlr4::tree::TerminalNode * /*node*/) override { }
  virtual void visitErrorNode(antlr4::tree::ErrorNode * /*node*/) override { }

};

}  // namespace bx
