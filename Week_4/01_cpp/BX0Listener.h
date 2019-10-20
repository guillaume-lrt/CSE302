
// Generated from BX0.g4 by ANTLR 4.7.2

#pragma once


#include "antlr4-runtime.h"
#include "BX0Parser.h"


namespace bx {

/**
 * This interface defines an abstract listener for a parse tree produced by BX0Parser.
 */
class  BX0Listener : public antlr4::tree::ParseTreeListener {
public:

  virtual void enterProgram(BX0Parser::ProgramContext *ctx) = 0;
  virtual void exitProgram(BX0Parser::ProgramContext *ctx) = 0;

  virtual void enterGlobalvar(BX0Parser::GlobalvarContext *ctx) = 0;
  virtual void exitGlobalvar(BX0Parser::GlobalvarContext *ctx) = 0;

  virtual void enterGlobalvar_init(BX0Parser::Globalvar_initContext *ctx) = 0;
  virtual void exitGlobalvar_init(BX0Parser::Globalvar_initContext *ctx) = 0;

  virtual void enterFunction(BX0Parser::FunctionContext *ctx) = 0;
  virtual void exitFunction(BX0Parser::FunctionContext *ctx) = 0;

  virtual void enterProcedure(BX0Parser::ProcedureContext *ctx) = 0;
  virtual void exitProcedure(BX0Parser::ProcedureContext *ctx) = 0;

  virtual void enterParameter_groups(BX0Parser::Parameter_groupsContext *ctx) = 0;
  virtual void exitParameter_groups(BX0Parser::Parameter_groupsContext *ctx) = 0;

  virtual void enterParameter_group(BX0Parser::Parameter_groupContext *ctx) = 0;
  virtual void exitParameter_group(BX0Parser::Parameter_groupContext *ctx) = 0;

  virtual void enterStmt(BX0Parser::StmtContext *ctx) = 0;
  virtual void exitStmt(BX0Parser::StmtContext *ctx) = 0;

  virtual void enterVardecl(BX0Parser::VardeclContext *ctx) = 0;
  virtual void exitVardecl(BX0Parser::VardeclContext *ctx) = 0;

  virtual void enterVarinit(BX0Parser::VarinitContext *ctx) = 0;
  virtual void exitVarinit(BX0Parser::VarinitContext *ctx) = 0;

  virtual void enterType(BX0Parser::TypeContext *ctx) = 0;
  virtual void exitType(BX0Parser::TypeContext *ctx) = 0;

  virtual void enterBlock(BX0Parser::BlockContext *ctx) = 0;
  virtual void exitBlock(BX0Parser::BlockContext *ctx) = 0;

  virtual void enterExpress(BX0Parser::ExpressContext *ctx) = 0;
  virtual void exitExpress(BX0Parser::ExpressContext *ctx) = 0;

  virtual void enterMove(BX0Parser::MoveContext *ctx) = 0;
  virtual void exitMove(BX0Parser::MoveContext *ctx) = 0;

  virtual void enterPrint(BX0Parser::PrintContext *ctx) = 0;
  virtual void exitPrint(BX0Parser::PrintContext *ctx) = 0;

  virtual void enterIfelse(BX0Parser::IfelseContext *ctx) = 0;
  virtual void exitIfelse(BX0Parser::IfelseContext *ctx) = 0;

  virtual void enterIfCont(BX0Parser::IfContContext *ctx) = 0;
  virtual void exitIfCont(BX0Parser::IfContContext *ctx) = 0;

  virtual void enterWhileLoop(BX0Parser::WhileLoopContext *ctx) = 0;
  virtual void exitWhileLoop(BX0Parser::WhileLoopContext *ctx) = 0;

  virtual void enterReturnStmt(BX0Parser::ReturnStmtContext *ctx) = 0;
  virtual void exitReturnStmt(BX0Parser::ReturnStmtContext *ctx) = 0;

  virtual void enterParens(BX0Parser::ParensContext *ctx) = 0;
  virtual void exitParens(BX0Parser::ParensContext *ctx) = 0;

  virtual void enterInequation(BX0Parser::InequationContext *ctx) = 0;
  virtual void exitInequation(BX0Parser::InequationContext *ctx) = 0;

  virtual void enterBitOr(BX0Parser::BitOrContext *ctx) = 0;
  virtual void exitBitOr(BX0Parser::BitOrContext *ctx) = 0;

  virtual void enterShift(BX0Parser::ShiftContext *ctx) = 0;
  virtual void exitShift(BX0Parser::ShiftContext *ctx) = 0;

  virtual void enterEquation(BX0Parser::EquationContext *ctx) = 0;
  virtual void exitEquation(BX0Parser::EquationContext *ctx) = 0;

  virtual void enterMultiplicative(BX0Parser::MultiplicativeContext *ctx) = 0;
  virtual void exitMultiplicative(BX0Parser::MultiplicativeContext *ctx) = 0;

  virtual void enterUnop(BX0Parser::UnopContext *ctx) = 0;
  virtual void exitUnop(BX0Parser::UnopContext *ctx) = 0;

  virtual void enterAdditive(BX0Parser::AdditiveContext *ctx) = 0;
  virtual void exitAdditive(BX0Parser::AdditiveContext *ctx) = 0;

  virtual void enterCall(BX0Parser::CallContext *ctx) = 0;
  virtual void exitCall(BX0Parser::CallContext *ctx) = 0;

  virtual void enterNumber(BX0Parser::NumberContext *ctx) = 0;
  virtual void exitNumber(BX0Parser::NumberContext *ctx) = 0;

  virtual void enterBitAnd(BX0Parser::BitAndContext *ctx) = 0;
  virtual void exitBitAnd(BX0Parser::BitAndContext *ctx) = 0;

  virtual void enterBoolean(BX0Parser::BooleanContext *ctx) = 0;
  virtual void exitBoolean(BX0Parser::BooleanContext *ctx) = 0;

  virtual void enterBitXor(BX0Parser::BitXorContext *ctx) = 0;
  virtual void exitBitXor(BX0Parser::BitXorContext *ctx) = 0;

  virtual void enterVariable(BX0Parser::VariableContext *ctx) = 0;
  virtual void exitVariable(BX0Parser::VariableContext *ctx) = 0;

  virtual void enterBoolOr(BX0Parser::BoolOrContext *ctx) = 0;
  virtual void exitBoolOr(BX0Parser::BoolOrContext *ctx) = 0;

  virtual void enterBoolAnd(BX0Parser::BoolAndContext *ctx) = 0;
  virtual void exitBoolAnd(BX0Parser::BoolAndContext *ctx) = 0;


};

}  // namespace bx
