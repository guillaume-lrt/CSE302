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

std::ostream& operator<<(std::ostream& out, const BoolBinop op){
  switch(op){
    case BoolBinop::Inf: return out << '<';
    case BoolBinop::Sup: return out << '>';
    case BoolBinop::InfEqua: return out << "<=";
    case BoolBinop::SupEqua: return out << ">=";
    case BoolBinop::Equal: return out << "==";
    case BoolBinop::NotEqual: return out << "!=";
    case BoolBinop::And: return out << "&&";
    case BoolBinop::Or: return out << "||";
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

std::ostream& operator<<(std::ostream& out, const BoolUnop op) {
  switch(op) {
  case BoolUnop::BoolNeg: return out << '!';
  default: return out << "<?>";
  }
}

std::ostream& operator<<(std::ostream& out, const Type tipi) {
  switch(tipi) {
  case Type::INT: return out << 'int64';
  case Type::BOOL: return out << 'bool';
  case Type::ERROR: return out << 'ERROR';
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

std::ostream& Bool::print(std::ostream& out) const {
  out << this->boo;
  return out;
}

Type Variable::gettype() const {
  return this->type;
}

Type Immediate::gettype() const {
  return type::INT;
}

Type Bool::gettype() const {
  return type::BOOL;
}

Type Expr::gettype() const {
  return Type::ERROR;
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

std::ostream& BoolBinopApp::print(std::ostream& out) const {
  out << '(';
  this->left_arg->print(out);
  out << ' ' << this->op << ' ';
  this->right_arg->print(out);
  return out << ')';
}

std::ostream& BoolUnopApp::print(std::ostream& out) const {
  out << '(' << this->op << ' ';
  this->arg->print(out);
  return out << ')';
}

Type UnopApp::gettype() const{
  if (this->arg->gettype() == Type::INT){
    return Type::INT;
  }
  return Type::ERROR;
}

Type BoolUnopApp::gettype() const{
  if (this->arg->gettype() == Type::BOOL){
    return Type::BOOL;
  }
  return Type::ERROR;
}

Type BinopApp::gettype() const{
  if (this->left_arg->gettype() == this->right_arg->gettype()){
    if (this->left_arg->gettype() == Type::INT){
      return Type::INT;
    }
  }
  return Type::ERROR;
}

Type BoolBinopApp::gettype() const{
  if (this->left_arg->gettype() == this->right_arg->gettype()){
    if (this->left_arg->gettype() == Type::BOOL){
      return Type::BOOL;
    }
  }
  return Type::ERROR;
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

std::ostream& Block::print(std::ostream& out) const {
  out << "{ \n";

  for (auto stmt: this->arg){
    out << '  ';
    stmt->print(out);
  }

  return out << '} \n';
}

std::ostream& Ifelse::print(std::ostream& out) const {
  out << "if ( ";
  this->expression->print(out);
  out << " ) ";
  this->blocky->print(out);
  out << "else ";
  return this->arg->print(out) << ';';
}

std::ostream& Whilee::print(std::ostream& out) const {
  out << "while ( ";
  this->expression->print(out);
  out << " ) ";
  return this->blocky->print(out) << ';';
}

std::ostream& Vardecl::print(std::ostream& out) const {
  this->var->type->print(out);
  out << " ";
  this->var->label->print(out);
  if (this->expression != NULL){
    out << " = ";
    this->expression->print(out);
  }
  return out << '\n';
}

std::ostream& Prog::print(std::ostream& out) const {
  for (auto vary: this->var){
    vary->print(out);
  }
  for (auto stat: this->statem){
    statem->print(out);
  }
  return out;
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
    std::string opy = ctx->op->getText();
    if (opy[0] == '!'){
      BoolUnop op(BoolUnop::BoolNeg);
      auto arg = this->expr_stack.back();
      this->expr_stack.pop_back();
      this->expr_stack.push_back(new BoolUnopApp(op, arg));
    }
    else {
      Unop op(opy[0] == '-' ? 
                Unop::Negate :
                Unop::BitNot);
      auto arg = this->expr_stack.back();
      this->expr_stack.pop_back();
      this->expr_stack.push_back(new UnopApp(op, arg));
    }
  }
  void exitVarinit(BX0Parser::VarinitContext* ctx) override {
    if (ctx->expr() == nullptr){

    }
    else {

    }
  }
  void exitVardecl(BX0Parser::VardeclContext* ctx) override {
    
  }
  void exitBoole(BX0Parser::BooleContext* ctx) override {

  }
  void exitInteger(BX0Parser::IntegerContext* ctx) override {
    
  }
  void exitStatement(BX0Parser::StatementContext* ctx) override {

  }
  void exitBlock(BX0Parser::BlockContext* ctx) override {
    
    auto stmt = new block(arg);
    this->expr_stack.push_back(stmt)
  }
  void exitIfelse(BX0Parser::IfelseContext* ctx) override {

  }
  void exitWhilee(BX0Parser::WhileeContext* ctx) override {

  }

private:
  void processBinop(Binop op) {
    auto right = this->expr_stack.back();
    this->expr_stack.pop_back();
    auto left = this->expr_stack.back();
    this->expr_stack.pop_back();
    this->expr_stack.push_back(new BinopApp(left, op, right));
  }
  void processBoolBinop(BoolBinop op) {
    auto right = this->expr_stack.back();
    this->expr_stack.pop_back();
    auto left = this->expr_stack.back();
    this->expr_stack.pop_back();
    this->expr_stack.push_back(new BoolBinopApp(left, op, right));
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
    std::string opy =ctx->op->getText();
    this->processBinop(opy[0] == '<' ? Binop::Lshift :
                       Binop::Rshift);
  }
  void exitInequality(BX0Parser::InequalityContext *ctx) override {
    std::string opy =ctx->op->getText();
    std::string temp_inf, temp_sup;
    temp_inf.push_back('<');
    temp_sup.push_back('>');
    this->processBoolBinop(opy == temp_inf ? BoolBinop::Inf :
                           opy == temp_sup ? BoolBinop::Sup :
                           opy == "<=" ? BoolBinop::InfEqua :
                       BoolBinop::SupEqua);
  }
  void exitEquality(BX0Parser::EqualityContext *ctx) override {
    std::string opy =ctx->op->getText();
    this->processBoolBinop(opy[0] == '=' ? BoolBinop::Equal :
                       BoolBinop::NotEqual);
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
  void exitBooland(BX0Parser::BoolandContext* ctx) override {
    this->processBoolBinop(BoolBinop::And);
  }
  void exitBoolor(BX0Parser::BoolorContext* ctx) override {
    this->processBoolBinop(BoolBinop::Or);
  }
  void exitVariable(BX0Parser::VariableContext* ctx) override {
    this->expr_stack.push_back(new Variable(ctx->VAR()->getText()));
  }
  void exitNumber(BX0Parser::NumberContext* ctx) override {
    this->expr_stack.push_back(new Immediate(std::stoi(ctx->NUM()->getText())));
  }
  void exitBoolean(BX0Parser::BooleanContext* ctx) override {
    this->expr_stack.push_back(new Bool(ctx->BOOL()->getText()));
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
    out << "    movq " << 8*this->left_source << "(%rsp), %R11\n";

    if (source::Binop::Add == this->op){out << "    addq " << 8*this->right_source << "(%rsp), %R11\n";}
    else if (source::Binop::Subtract == this->op){out << "    subq " << 8*this->right_source << "(%rsp), %R11\n";}
    else if (source::Binop::BitAnd == this->op){out << "    andq " << 8*this->right_source << "(%rsp), %R11\n";}
    else if (source::Binop::BitOr == this->op){out << "    orq " << 8*this->right_source << "(%rsp), %R11\n";}
    else if (source::Binop::BitXor == this->op){out << "    xorq " << 8*this->right_source << "(%rsp), %R11\n";}
    else if (source::Binop::Lshift == this->op){
      out << "    movq " << 8*this->right_source << "(%rsp), %rcx\n";   // put right source in rcx, thus in cl necessary for salq/sarq
      out << "    salq %cl, %R11\n";}
    else if (source::Binop::Rshift == this->op){
      out << "    movq " << 8*this->right_source << "(%rsp), %rcx\n";
      out << "    sarq %cl, %R11\n";}

    out << "    movq %R11, " << 8*this->dest << "(%rsp)";
    return out;
  }
  else{
    out << "    movq " << 8*this->left_source << "(%rsp), %rax\n";      // store direclty the left source in rax
    if (source::Binop::Multiply == this->op){
      out << "    imulq " << 8*this->right_source << "(%rsp)\n    movq %rax, " << 8*this->dest << "(%rsp)";     // multiply RAX and R8 and store in RDX:RAX
    }
    else{
      out << "    cqo\n    idivq " << 8*this->right_source << "(%rsp)\n";    // extend rax to rdx:rax, divide rdx:rax by R8 (right source) and store in rdx:rax
      if (source::Binop::Divide == this->op){out << "    movq %rax, " << 8*this->dest << "(%rsp)";}
      else if (source::Binop::Modulus == this->op){out << "    movq %rdx, " << 8*this->dest << "(%rsp)";}
    }
    return out;
  }
}

std::ostream& MoveUnop::print(std::ostream& out) const {
  out << "    movq " << 8*this->source << "(%rsp), %R11\n";
  if (this->op == source::Unop::Negate){out << "    negq %R11\n";}
  if (this->op == source::Unop::BitNot){out << "    notq %R11\n";}
  out << "    movq %R11, " << 8*this->dest << "(%rsp)";
  return out;
}

std::ostream& MoveBoolBinop::print(std::ostream& out) const {    // separate mult, divi, modu and the rest
  // if (source::BoolBinop::Inf == this->op || source::BoolBinop::Sup == this->op || source::BoolBinop::InfEqua == this->op
  //   || source::BoolBinop::SupEqua == this->op || source::BoolBinop::Equal == this->op || source::BoolBinop::NotEqual == this->op
  //   || source::BoolBinop::Rshift == this->op){
  //   out << "    movq " << 8*this->left_source << "(%rsp), %R11\n";

  //   if (source::BoolBinop::Add == this->op){out << "    addq " << 8*this->right_source << "(%rsp), %R11\n";}
  //   else if (source::BoolBinop::Subtract == this->op){out << "    subq " << 8*this->right_source << "(%rsp), %R11\n";}
  //   else if (source::BoolBinop::BitAnd == this->op){out << "    andq " << 8*this->right_source << "(%rsp), %R11\n";}
  //   else if (source::BoolBinop::BitOr == this->op){out << "    orq " << 8*this->right_source << "(%rsp), %R11\n";}
  //   else if (source::BoolBinop::BitXor == this->op){out << "    xorq " << 8*this->right_source << "(%rsp), %R11\n";}
  //   else if (source::BoolBinop::Lshift == this->op){
  //     out << "    movq " << 8*this->right_source << "(%rsp), %rcx\n";   // put right source in rcx, thus in cl necessary for salq/sarq
  //     out << "    salq %cl, %R11\n";}
  //   else if (source::BoolBinop::Rshift == this->op){
  //     out << "    movq " << 8*this->right_source << "(%rsp), %rcx\n";
  //     out << "    sarq %cl, %R11\n";}

  //   out << "    movq %R11, " << 8*this->dest << "(%rsp)";
  //   return out;
  // }
  // else{
  //   out << "    movq " << 8*this->left_source << "(%rsp), %rax\n";      // store direclty the left source in rax
  //   if (source::BoolBinop::Multiply == this->op){
  //     out << "    imulq " << 8*this->right_source << "(%rsp)\n    movq %rax, " << 8*this->dest << "(%rsp)";     // multiply RAX and R8 and store in RDX:RAX
  //   }
  //   else{
  //     out << "    cqo\n    idivq " << 8*this->right_source << "(%rsp)\n";    // extend rax to rdx:rax, divide rdx:rax by R8 (right source) and store in rdx:rax
  //     if (source::BoolBinop::Divide == this->op){out << "    movq %rax, " << 8*this->dest << "(%rsp)";}
  //     else if (source::BoolBinop::Modulus == this->op){out << "    movq %rdx, " << 8*this->dest << "(%rsp)";}
  //   }
  //   return out;
  // }
  return out;
}

std::ostream& MoveBoolUnop::print(std::ostream& out) const {
  // out << "    movq " << 8*this->source << "(%rsp), %R11\n";
  // if (this->op == source::BoolUnop::Negate){out << "    negq %R11\n";}
  // if (this->op == source::BoolUnop::BitNot){out << "    notq %R11\n";}
  // out << "    movq %R11, " << 8*this->dest << "(%rsp)";
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
  else if (auto booluno = dynamic_cast<const source::BoolUnopApp*>(e)){
    target::Dest fresh = ++var_counter;
    topdown_much_expr(booluno->arg,fresh);
    auto instrct = new target::BoolMoveUnop(d,booluno->op,fresh);
    instruction.push_back(instrct);
  }
  else if (auto boolbino = dynamic_cast<const source::BoolBinopApp*>(e)){
    target::Dest fresh = ++var_counter;
    target::Dest fresh_bis = ++var_counter;
    topdown_much_expr(boolbino->left_arg,fresh);
    topdown_much_expr(boolbino->right_arg,fresh_bis);
    auto instrct = new target::BoolMoveBinop(d,fresh,boolbino->op,fresh_bis);
    instruction.push_back(instrct);
  }
}

} // bx
