#pragma once

#include <iostream>
#include <string>

#include "antlr4-runtime.h"

namespace bx {

////////////////////////////////////////////////////////////////////////////////
// Source AST

namespace source {

using Dest = std::string;

enum class Binop { Add, Subtract, Multiply, Divide, Modulus,
                  BitAnd, BitOr, BitXor, Lshift, Rshift };
std::ostream& operator<<(std::ostream&, const Binop);

enum class BoolBinop { Inf, Sup, InfEqua, SupEqua, Equal, NotEqual,
                  And, Or };
std::ostream& operator<<(std::ostream&, const BoolBinop);

enum class Unop { Negate, BitNot };
std::ostream& operator<<(std::ostream& out, const Unop);

enum class BoolUnop { BoolNeg };
std::ostream& operator<<(std::ostream& out, const BoolUnop);

enum class Type { INT, BOOL, ERROR };
std::ostream& operator<<(std::ostream& out, const Type);

////////////////////////////////////////////////////////////////////////////////
// AST Nodes

class ASTNode {
public:
  virtual std::ostream& print(std::ostream &out) const = 0;
};
std::ostream& operator<<(std::ostream& out, ASTNode& e);

////////////////////////////////////////////////////////////////////////////////
// Expressions

class Expr : public ASTNode {
public:
  virtual Type gettype() const;
};

class Variable : public Expr {
public:
  const std::string label;
  const Type type;
  Variable(std::string label, Type type) : label(label) , type(type){ }
  std::ostream& print(std::ostream& out) const override;
  Type gettype() const override;
};

class Immediate : public Expr {
public:
  const int value;
  Immediate(int value) : value(value) { }
  std::ostream& print(std::ostream& out) const override;
  Type gettype() const override;
};

class Bool : public Expr {
public:
  const bool boo;
  Bool(bool boo) : boo(boo) { }
  std::ostream& print(std::ostream& out) const override;
  Type gettype() const override;
};

class UnopApp : public Expr {
public:
  const Unop op;
  const Expr* arg;
  UnopApp(Unop op, Expr* arg) : op(op), arg(arg) { }
  std::ostream& print(std::ostream& out) const override;
  Type gettype() const override;
};

class BinopApp : public Expr {
public:
  const Binop op;
  const Expr* left_arg;
  const Expr* right_arg;
  BinopApp(Expr *left_arg, Binop op, Expr* right_arg) :
    left_arg(left_arg), op(op), right_arg(right_arg) { }
  std::ostream& print(std::ostream& out) const override;
  Type gettype() const override;
};

class BoolUnopApp : public Expr {
public:
  const BoolUnop op;
  const Expr* arg;
  BoolUnopApp(BoolUnop op, Expr* arg) : op(op), arg(arg) { }
  std::ostream& print(std::ostream& out) const override;
  Type gettype() const override;
};

class BoolBinopApp : public Expr {
public:
  const BoolBinop op;
  const Expr* left_arg;
  const Expr* right_arg;
  BoolBinopApp(Expr *left_arg, BoolBinop op, Expr* right_arg) :
    left_arg(left_arg), op(op), right_arg(right_arg) { }
  std::ostream& print(std::ostream& out) const override;
  Type gettype() const override;
};


////////////////////////////////////////////////////////////////////////////////
// Statements

class Stmt : public ASTNode { 
  virtual std::ostream& print(std::ostream& out) const override;
};

class Print : public Stmt {
public:
  const Expr* arg;
  Print(Expr* arg) : arg(arg) { }
  std::ostream& print(std::ostream& out) const override;
};

class Move : public Stmt {
public:
  const Variable* dest;
  const Expr* source;
  Move(Variable* dest, Expr* source) : dest(dest), source(source) { }
  std::ostream& print(std::ostream& out) const override;
};

class Block : public Stmt {
public:
  const std::list<Stmt*> arg;
  Block(std::list<Stmt*> arg) : arg(arg) { }
  std::ostream& print(std::ostream& out) const override;
};

class Ifelse : public Stmt {
public:
  const Expr* expression;
  const Block* blocky;
  const std::list<Stmt*> arg;
  Ifelse(Expr* expression, Block* blocky,std::list<Stmt*> arg) : expression(expression), blocky(blocky), arg(arg) { }
  std::ostream& print(std::ostream& out) const override;
};

class Whilee : public Stmt {
public:
  const Expr* expression;
  const Block* blocky;
  Whilee(Expr* expression, Block* blocky) : expression(expression), blocky(blocky) { }
  std::ostream& print(std::ostream& out) const override;
};

////////////////////////////////////////////////////////////////////////////////
// vardecl

class Vardecl {
public:
  const Variable* var;
  const Expr* expression;
  Vardecl(Variable* var, Expr* expression): var(var), expression(expression) { }
  std::ostream& print(std::ostream& out) const override;
};

// using Prog = std::list<Stmt*>;

class Prog{
public:
  std::list<Vardecl*> varia;
  std::list<Stmt*> statem;
  std::ostream& print(std::ostream& out) const override;
};

////////////////////////////////////////////////////////////////////////////////
// Parsing

source::Prog read_program(std::string file);

} // bx::source


namespace target {

using Dest = int;

class Instr {
public:
  virtual std::ostream& print(std::ostream &out) const = 0;
};
std::ostream& operator<<(std::ostream& out, Instr& i);

class MoveImm : public Instr {
public:
  const Dest dest;
  const int imm;
  MoveImm(Dest dest, int imm) : dest(dest), imm(imm) { }
  std::ostream& print(std::ostream &out) const override;
};

class MoveCp : public Instr {
public:
  const Dest dest, source;
  MoveCp(Dest dest, Dest source) : dest(dest), source(source) { }
  std::ostream& print(std::ostream &out) const override; 
};

class MoveBinop : public Instr {
public:
  const source::Binop op;
  const Dest dest;
  const Dest left_source, right_source;
  MoveBinop(Dest dest, Dest left_source, source::Binop op, Dest right_source)
    : dest(dest), left_source(left_source), op(op), right_source(right_source) { }
  std::ostream& print(std::ostream &out) const override;  
};

class MoveUnop : public Instr {
public:
  const source::Unop op;
  const Dest dest;
  const Dest source;
  MoveUnop(Dest dest, source::Unop op, Dest source)
    : dest(dest), op(op), source(source) { }
  std::ostream& print(std::ostream &out) const override;
};

class MoveBoolBinop : public Instr {
public:
  const source::BoolBinop op;
  const Dest dest;
  const Dest left_source, right_source;
  MoveBoolBinop(Dest dest, Dest left_source, source::BoolBinop op, Dest right_source)
    : dest(dest), left_source(left_source), op(op), right_source(right_source) { }
  std::ostream& print(std::ostream &out) const override;  
};

class MoveBoolUnop : public Instr {
public:
  const source::BoolUnop op;
  const Dest dest;
  const Dest source;
  MoveBoolUnop(Dest dest, source::BoolUnop op, Dest source)
    : dest(dest), op(op), source(source) { }
  std::ostream& print(std::ostream &out) const override;
};

class Print : public Instr {
public:
  const Dest source;
  Print(Dest source) : source(source) { }
  std::ostream& print(std::ostream &out) const override;
};

class Comment : public Instr {
public:
  const std::string comment;
  Comment(std::string comment) : comment(comment) { }
  std::ostream& print(std::ostream &out) const override;
};

class Prog {
public:
  const std::list<Dest> symbol_table;
  const std::list<Instr*> body;
  Prog(std::list<Dest> symbol_table,
       std::list<Instr*> body) :
    symbol_table(symbol_table), body(body) { }
};
std::ostream& operator<<(std::ostream& out, Prog &prog);

} // bx::target

target::Prog target_program(const bx::source::Prog prog);
void topdown_much_expr(const bx::source::Expr* e, const bx::target::Dest d);

} // bx
