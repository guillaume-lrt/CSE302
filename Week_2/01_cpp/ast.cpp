#include "ast.h"

#include "BX0Lexer.h"
#include "BX0Parser.h"
#include "BX0BaseListener.h"

namespace bx {

namespace source {

std::ostream& operator<<(std::ostream& out, const Binop op) {
  switch(op) {
  case Binop::Add: return out << '+';
  case Binop::Subtract: return out << '-';
  case Binop::Multiply: return out << '*';
  case Binop::Divide: return out << '/';
  case Binop::Modulus: return out << '%';
  case Binop::BitAnd: return out << '&';
  case Binop::BitOr: return out << '|';
  case Binop::BitXor: return out << '^';
  case Binop::Lshift: return out << "<<";
  case Binop::Rshift: return out << ">>";
  default: return out << "<?>";
  }
}

std::ostream& operator<<(std::ostream& out, const Unop op) {
  switch(op) {
  case Unop::Negate: return out << '-';
  case Unop::BitNot: return out << "~";
  default: return out << "<?>";
  }
}

std::ostream& operator<<(std::ostream& out, ASTNode& node) {
  return node.print(out);
}

std::ostream& Variable::print(std::ostream& out) const {
  out << this->label;
  return out;
}

std::ostream& Immediate::print(std::ostream& out) const {
  out << this->value;
  return out;
}

std::ostream& UnopApp::print(std::ostream& out) const {
  out << '(' << this->op << ' ';
  this->arg->print(out);
  return out << ')';
}

std::ostream& BinopApp::print(std::ostream& out) const {
  out << '(';
  this->left_arg->print(out);
  out << ' ' << this->op << ' ';
  this->right_arg->print(out);
  return out << ')';
}

std::ostream& Print::print(std::ostream& out) const {
  out << "print ";
  return this->arg->print(out) << ';';
}

std::ostream& Move::print(std::ostream& out) const {
  this->dest->print(out);
  out << " = ";
  return this->source->print(out) << ';';
}

class SourceReader : public BX0BaseListener {
private:
  Prog prog;
  std::list<Expr*> expr_stack;
public:
  Prog get_prog() { return this->prog; }
  void exitMove(BX0Parser::MoveContext* ctx) override {
    auto dest = new Variable(ctx->VAR()->getText());
    auto source = this->expr_stack.back();
    this->expr_stack.pop_back();
    auto stmt = new Move(dest, source);
    this->prog.push_back(stmt);
  }
  void exitPrint(BX0Parser::PrintContext* ctx) override {
    auto dest = this->expr_stack.back();
    this->expr_stack.pop_back();
    auto stmt = new Print(dest);
    this->prog.push_back(stmt);
  }
  void exitUnop(BX0Parser::UnopContext* ctx) override {
    Unop op(ctx->op->getText()[0] == '-' ?
                    Unop::Negate :
                    Unop::BitNot);
    auto arg = this->expr_stack.back();
    this->expr_stack.pop_back();
    this->expr_stack.push_back(new UnopApp(op, arg));
  }
private:
  void processBinop(Binop op) {
    auto right = this->expr_stack.back();
    this->expr_stack.pop_back();
    auto left = this->expr_stack.back();
    this->expr_stack.pop_back();
    this->expr_stack.push_back(new BinopApp(left, op, right));
  }
public:
  void exitAdd(BX0Parser::AddContext* ctx) override {
    this->processBinop(ctx->op->getText()[0] == '+' ?
                       Binop::Add :
                       Binop::Subtract);
  }
  void exitMul(BX0Parser::MulContext* ctx) override {
    std::string op = ctx->op->getText();
    this->processBinop(op[0] == '*' ? Binop::Multiply :
                       op[0] == '/' ? Binop::Divide :
                       Binop::Modulus);
  }
  void exitShift(BX0Parser::ShiftContext *ctx) override {
    this->processBinop(ctx->op->getText()[0] == '<' ?
                       Binop::Lshift :
                       Binop::Rshift);
  }
  void exitAnd(BX0Parser::AndContext* ctx) override {
    this->processBinop(Binop::BitAnd);
  }
  void exitOr(BX0Parser::OrContext* ctx) override {
    this->processBinop(Binop::BitOr);
  }
  void exitXor(BX0Parser::XorContext* ctx) override {
    this->processBinop(Binop::BitXor);
  }
  void exitVariable(BX0Parser::VariableContext* ctx) override {
    this->expr_stack.push_back(new Variable(ctx->VAR()->getText()));
  }
  void exitNumber(BX0Parser::NumberContext* ctx) override {
    this->expr_stack.push_back(new Immediate(std::stoi(ctx->NUM()->getText())));
  }
};

Prog read_program(std::string file) {
  std::ifstream stream;
  stream.open(file);
  antlr4::ANTLRInputStream input(stream);
  BX0Lexer lexer(&input);
  antlr4::CommonTokenStream tokens(&lexer);
  BX0Parser parser(&tokens);
  antlr4::tree::ParseTree *tree = parser.program();
  SourceReader source_reader;
  antlr4::tree::ParseTreeWalker::DEFAULT.walk(&source_reader, tree);
  return source_reader.get_prog();
}

} // bx::source

namespace target {

std::ostream& operator<<(std::ostream& out, Instr& i) {
  return i.print(out);
}

std::ostream& MoveImm::print(std::ostream& out) const {
  out << "    movq $" << this->imm << ", " << 8*(this->dest) << "(%rsp)";
  return out;
}

std::ostream& MoveCp::print(std::ostream& out) const {
  out << "    movq " << 8*this->source << "(%rsp), %R11\n    " << "movq %R11, " << 8*this->dest << "(%rsp)";
  return out;
}

std::ostream& MoveBinop::print(std::ostream& out) const {    // separate mult, divi, modu and the rest
  if (source::Binop::Add == this->op || source::Binop::Subtract == this->op || source::Binop::BitAnd == this->op 
    || source::Binop::BitOr == this->op || source::Binop::BitXor == this->op || source::Binop::Lshift == this->op 
    || source::Binop::Rshift == this->op){
    out << "    movq " << 8*this->right_source << "(%rsp), %R8\n    movq " << 8*this->left_source << "(%rsp), %R9\n";

    if (source::Binop::Add == this->op){out << "    addq %R8, %R9\n";}
    else if (source::Binop::Subtract == this->op){out << "    subq %R8, %R9\n";}
    else if (source::Binop::BitAnd == this->op){out << "    andq %R8, %R9\n";}
    else if (source::Binop::BitOr == this->op){out << "    orq %R8, %R9\n";}
    else if (source::Binop::BitXor == this->op){out << "    xorq %R8, %R9\n";}
    else if (source::Binop::Lshift == this->op){
      out << "    movq %R8, %rcx\n";   // put R8 in rcx, thus in cl necessary for salq/sarq
      out << "    salq %cl, %R9\n";}
    else if (source::Binop::Rshift == this->op){
      out << "    movq %R8, %rcx\n";
      out << "    sarq %cl, %R9\n";}

    out << "    movq %R9, " << 8*this->dest << "(%rsp)";
    return out;
  }
  else{
    out << "    movq " << 8*this->right_source << "(%rsp), %R8\n    movq " << 8*this->left_source << "(%rsp), %rax\n";      // store direclty the left source in rax
    if (source::Binop::Multiply == this->op){
      out << "    imulq %R8\n    movq %rax, " << 8*this->dest << "(%rsp)";     // multiply RAX and R8 and store in RDX:RAX
    }
    else{   
      out << "    cqo\n    idivq %R8\n";    // extend rax to rdx:rax, divide rdx:rax by R8 (right source) and store in rdx:rax
      if (source::Binop::Divide == this->op){out << "    movq %rax, " << 8*this->dest << "(%rsp)";}  
      else if (source::Binop::Modulus == this->op){out << "    movq %rdx, " << 8*this->dest << "(%rsp)";}
    }
    return out;
  }
}

std::ostream& MoveUnop::print(std::ostream& out) const {
  out << "    movq " << 8*this->source << "(%rsp), %R8\n";
  if (this->op == source::Unop::Negate){out << "    negq %R8\n";}
  if (this->op == source::Unop::BitNot){out << "    notq %R8\n";}
  out << "    movq %R8, " << 8*this->dest << "(%rsp)";
  return out;
}

std::ostream& Print::print(std::ostream& out) const {
  out << "    movq " << 8*this->source << "(%rsp),%rdi\n    callq bx0_print";
  return out;
}

std::ostream& Comment::print(std::ostream& out) const {
  out << "# " << this->comment << ";";
  return out;
}

std::ostream& operator<<(std::ostream &out, Prog& prog) {
  if (prog.symbol_table.size() > 0) {
    out << "// symbol table\n";

    //for (auto d : prog.symbol_table)
      //out << "int64_t " << "x_" << d << ';';
    //out << "\n";
  }
  out << "// code\n";
  for (auto i : prog.body)
    out << *i << std::endl;
  return out;
}

} // bx::target

std::list<target::Instr*> instruction;
std::list<target::Dest> symbol_table;
std::map<std::string,target::Dest> table;
int var_counter = 0;

target::Prog target_program(const source::Prog prog){
  for (auto stmt : prog){
    if (auto move = dynamic_cast<source::Move*>(stmt)){
      if (table.find(move->dest->label) == table.end()){
        table[move->dest->label] = ++var_counter;
      }
      topdown_much_expr(move->source, table[move->dest->label]);
    }
    if (auto prnt = dynamic_cast<source::Print*>(stmt)){
      target::Dest fresh = ++var_counter;
      topdown_much_expr(prnt->arg,fresh);
      instruction.push_back(new target::Print(fresh));
    }
  }
  for (int i = 0; i <= var_counter; i++){
    symbol_table.push_back(i);
  }
  return target::Prog(symbol_table, instruction);
}

void topdown_much_expr(const source::Expr* e, const target::Dest d){
  if (auto imm = dynamic_cast<const source::Immediate*>(e)){
    auto instrct = new target::MoveImm(d,imm->value);
    instruction.push_back(instrct);
  }
  else if (auto var= dynamic_cast<const source::Variable*>(e)){
    if (table.find(var->label) == table.end()){
      table[var->label] = var_counter ++;
    }
    auto instrct = new target::MoveCp(d,table[var->label]);
    instruction.push_back(instrct);
  }
  else if (auto uno = dynamic_cast<const source::UnopApp*>(e)){
    target::Dest fresh = ++var_counter;
    topdown_much_expr(uno->arg,fresh);
    auto instrct = new target::MoveUnop(d,uno->op,fresh);
    instruction.push_back(instrct);
  }
  else if (auto bino = dynamic_cast<const source::BinopApp*>(e)){
    target::Dest fresh = ++var_counter;
    target::Dest fresh_bis = ++var_counter;
    topdown_much_expr(bino->left_arg,fresh);
    topdown_much_expr(bino->right_arg,fresh_bis);
    auto instrct = new target::MoveBinop(d,fresh,bino->op,fresh_bis);
    instruction.push_back(instrct);
  }
}

} // bx
