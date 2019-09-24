
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

  virtual void enterMove(BX0Parser::MoveContext *ctx) = 0;
  virtual void exitMove(BX0Parser::MoveContext *ctx) = 0;

  virtual void enterPrint(BX0Parser::PrintContext *ctx) = 0;
  virtual void exitPrint(BX0Parser::PrintContext *ctx) = 0;

  virtual void enterAdd(BX0Parser::AddContext *ctx) = 0;
  virtual void exitAdd(BX0Parser::AddContext *ctx) = 0;

  virtual void enterNumber(BX0Parser::NumberContext *ctx) = 0;
  virtual void exitNumber(BX0Parser::NumberContext *ctx) = 0;

  virtual void enterParens(BX0Parser::ParensContext *ctx) = 0;
  virtual void exitParens(BX0Parser::ParensContext *ctx) = 0;

  virtual void enterOr(BX0Parser::OrContext *ctx) = 0;
  virtual void exitOr(BX0Parser::OrContext *ctx) = 0;

  virtual void enterMul(BX0Parser::MulContext *ctx) = 0;
  virtual void exitMul(BX0Parser::MulContext *ctx) = 0;

  virtual void enterAnd(BX0Parser::AndContext *ctx) = 0;
  virtual void exitAnd(BX0Parser::AndContext *ctx) = 0;

  virtual void enterShift(BX0Parser::ShiftContext *ctx) = 0;
  virtual void exitShift(BX0Parser::ShiftContext *ctx) = 0;

  virtual void enterVariable(BX0Parser::VariableContext *ctx) = 0;
  virtual void exitVariable(BX0Parser::VariableContext *ctx) = 0;

  virtual void enterXor(BX0Parser::XorContext *ctx) = 0;
  virtual void exitXor(BX0Parser::XorContext *ctx) = 0;

  virtual void enterUnop(BX0Parser::UnopContext *ctx) = 0;
  virtual void exitUnop(BX0Parser::UnopContext *ctx) = 0;


};

}  // namespace bx
