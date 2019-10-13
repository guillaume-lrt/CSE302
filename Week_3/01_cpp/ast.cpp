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
  case Type::INT: return out << "int64";
  case Type::BOOL: return out << "bool";
  case Type::ERROR: return out << "ERROR";
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
  return Type::INT;
}

Type Bool::gettype() const {
  return Type::BOOL;
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
  return this->arg->print(out) << ";\n";
}

std::ostream& Move::print(std::ostream& out) const {
  this->dest->print(out);
  out << " = ";
  return this->source->print(out) << ';';
}

std::ostream& Block::print(std::ostream& out) const {
  out << "{";

  for (auto stmt: this->arg){
    out << "\n";
    out << "  ";
    stmt->print(out);
  }

  return out << "\n}";
}

std::ostream& Ifelse::print(std::ostream& out) const {
  out << "if ( ";
  this->expression->print(out);
  out << " ) ";
  this->blocky->print(out);
  out << "else ";
  this->block_else->print(out);
  return out << ';';
}

std::ostream& Whilee::print(std::ostream& out) const {
  out << "while ";
  this->expression->print(out);
  out << " ";
  return this->blocky->print(out);
}

std::ostream& Vardecl::print(std::ostream& out) const {
  out << this->var->type;
  out << " ";
  out << this->var->label;
  if (this->expression != NULL){
    out << " = ";
    this->expression->print(out);
  }
  return out << '\n';
}

std::ostream& Prog::print(std::ostream& out) {
  for (auto vary: this->varia){
    vary->print(out);
  }
  for (auto stat: this->statem){
    stat->print(out);
  }
  return out;
}


class SourceReader : public BX0BaseListener {
private:
  Prog prog;
  std::list<Expr*> expr_stack;
  std::list<Stmt*> stmt_stack;
  std::map<std::string, Type> type_map;
  std::list<Vardecl* > vardec_stack;
public:
  Prog get_prog() { return this->prog; }
  void exitProgram(BX0Parser::ProgramContext* ctx) override{ 
    this->prog.statem = stmt_stack;
  }
  void exitMove(BX0Parser::MoveContext* ctx) override {
    auto dest = new Variable(ctx->VAR()->getText(),type_map[ctx->VAR()->getText()]);
    auto source = this->expr_stack.back();
    this->expr_stack.pop_back();
    auto stmt = new Move(dest, source);
    this->stmt_stack.push_back(stmt);
  }
  void exitPrint(BX0Parser::PrintContext* ctx) override {
    auto dest = this->expr_stack.back();
    this->expr_stack.pop_back();
    auto stmt = new Print(dest);
    this->stmt_stack.push_back(stmt);
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
  void exitVardecl(BX0Parser::VardeclContext* ctx) override {
    for (auto vardec : this->vardec_stack){
      Type tp = ctx->type()->getText() == "int64" ? Type::INT : Type::BOOL;
      vardec->var->type = tp;
      type_map[vardec->var->label] = vardec->var->type;
    }
    vardec_stack.clear();
  }
  void exitVarinit(BX0Parser::VarinitContext* ctx) override {
    if (ctx->expr() == nullptr){
      auto dest = new Variable(ctx->VAR()->getText(),Type::ERROR);
      Vardecl* vardec = new Vardecl(dest,NULL);
      this->vardec_stack.push_back(vardec);
      this->prog.varia.push_back(vardec);
    }
    else{
      auto expression = expr_stack.back();
      expr_stack.pop_back();
      auto dest = new Variable(ctx->VAR()->getText(),Type::ERROR);
      Vardecl* vardec = new Vardecl(dest,expression);
      this->vardec_stack.push_back(vardec);
      this->prog.varia.push_back(vardec);
    }
  }
  
  void exitBlock(BX0Parser::BlockContext* ctx) override {
    std::list<Stmt* > blocky;
    int length = ctx->statement().size();
    while (length-->0){
      auto arg = stmt_stack.back();
      this->stmt_stack.pop_back();
      blocky.push_front(arg);
    }
    this->stmt_stack.push_back(new Block(blocky));
  }

  void exitIfelse(BX0Parser::IfelseContext* ctx) override {
    auto condi = this->expr_stack.back();
    this->expr_stack.pop_back();
    Block* thenBlock;
    Block* elseBlock;
    if (ctx->ifelse_bis() == nullptr){                // if no second if else block
      Stmt* thenstate = this->stmt_stack.back();
      this->stmt_stack.pop_back();
      thenBlock = dynamic_cast<Block* >(thenstate);
      elseBlock = new Block(std::list<Stmt *>());       // list of empty statements
      stmt_stack.push_back(new Ifelse(condi,thenBlock,elseBlock));
    }
    else{
      auto elsestate = this->stmt_stack.back();
      this->stmt_stack.pop_back();
      auto thenstate = this->stmt_stack.back();
      this->stmt_stack.pop_back();
      elseBlock = dynamic_cast<Block* >(elsestate);
      thenBlock = dynamic_cast<Block* >(thenstate);
      stmt_stack.push_back(new Ifelse(condi,thenBlock,elseBlock));
    }
    
  }
  void exitWhilee(BX0Parser::WhileeContext* ctx) override {
    auto condi = this->expr_stack.back();
    this->expr_stack.pop_back();
    auto statem = this->stmt_stack.back();
    this->stmt_stack.pop_back();
    auto blocky = dynamic_cast<Block* >(statem);
    this->stmt_stack.push_back(new Whilee(condi,blocky));
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
    auto temp_var = ctx->VAR()->getText();
    if (type_map.find(temp_var) == type_map.end()){
      this->expr_stack.push_back(new Variable(temp_var, Type::ERROR));   // not suppose to happen if the code is well typed
    }
    else{
      auto temp_type = type_map[temp_var];
      this->expr_stack.push_back(new Variable(ctx->VAR()->getText(),type_map[temp_var]));
    }
  }
  void exitNumber(BX0Parser::NumberContext* ctx) override {
    this->expr_stack.push_back(new Immediate(std::stoi(ctx->NUM()->getText())));
  }
  void exitBoolean(BX0Parser::BooleanContext* ctx) override {
    this->expr_stack.push_back(new Bool(ctx->BOOL()->getText() == "true" ? true : false));
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
  // out << "    movq $" << this->imm << ", " << 8*(this->dest) << "(%rsp)";
  return out;
}

std::ostream& MoveCp::print(std::ostream& out) const {
  // out << "    movq " << 8*this->source << "(%rsp), %R11\n    " << "movq %R11, " << 8*this->dest << "(%rsp)";
  return out;
}

std::ostream& MoveBool::print(std::ostream& out) const {
  out << "TODO";
  return out;
}

std::ostream& MoveBinop::print(std::ostream& out) const {    // separate mult, divi, modu and the rest
  if (source::Binop::Add == this->op || source::Binop::Subtract == this->op || source::Binop::BitAnd == this->op
    || source::Binop::BitOr == this->op || source::Binop::BitXor == this->op || source::Binop::Lshift == this->op
    || source::Binop::Rshift == this->op){
    // out << "    movq " << 8*this->left_source << "(%rsp), %R11\n";

    // if (source::Binop::Add == this->op){out << "    addq " << 8*this->right_source << "(%rsp), %R11\n";}
    // else if (source::Binop::Subtract == this->op){out << "    subq " << 8*this->right_source << "(%rsp), %R11\n";}
    // else if (source::Binop::BitAnd == this->op){out << "    andq " << 8*this->right_source << "(%rsp), %R11\n";}
    // else if (source::Binop::BitOr == this->op){out << "    orq " << 8*this->right_source << "(%rsp), %R11\n";}
    // else if (source::Binop::BitXor == this->op){out << "    xorq " << 8*this->right_source << "(%rsp), %R11\n";}
    // else if (source::Binop::Lshift == this->op){
    //   out << "    movq " << 8*this->right_source << "(%rsp), %rcx\n";   // put right source in rcx, thus in cl necessary for salq/sarq
    //   out << "    salq %cl, %R11\n";}
    // else if (source::Binop::Rshift == this->op){
    //   out << "    movq " << 8*this->right_source << "(%rsp), %rcx\n";
    //   out << "    sarq %cl, %R11\n";}

    // out << "    movq %R11, " << 8*this->dest << "(%rsp)";
    return out;
  }
  else{
    // out << "    movq " << 8*this->left_source << "(%rsp), %rax\n";      // store direclty the left source in rax
    if (source::Binop::Multiply == this->op){
      // out << "    imulq " << 8*this->right_source << "(%rsp)\n    movq %rax, " << 8*this->dest << "(%rsp)";     // multiply RAX and R8 and store in RDX:RAX
    }
    else{
      // out << "    cqo\n    idivq " << 8*this->right_source << "(%rsp)\n";    // extend rax to rdx:rax, divide rdx:rax by R8 (right source) and store in rdx:rax
      // if (source::Binop::Divide == this->op){out << "    movq %rax, " << 8*this->dest << "(%rsp)";}
      // else if (source::Binop::Modulus == this->op){out << "    movq %rdx, " << 8*this->dest << "(%rsp)";}
    }
    return out;
  }
}

std::ostream& MoveUnop::print(std::ostream& out) const {
  // out << "    movq " << 8*this->source << "(%rsp), %R11\n";
  // if (this->op == source::Unop::Negate){out << "    negq %R11\n";}
  // if (this->op == source::Unop::BitNot){out << "    notq %R11\n";}
  // out << "    movq %R11, " << 8*this->dest << "(%rsp)";
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
  // out << "    movq " << 8*this->source << "(%rsp),%rdi\n    callq bx0_print";
  return out;
}

std::ostream& Ubranch::print(std::ostream& out) const {
  out << "TODO";
  return out;
}

std::ostream& Bbranch::print(std::ostream& out) const {
  out << "TODO";
  return out;
}

// std::ostream& Comment::print(std::ostream& out) const {
//   out << "# " << this->comment << ";";
//   return out;
// }

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
int instruction_counter = 0;

target::Prog target_program(const source::Prog prog){
  for (auto stmt : prog.statem){
    if (auto move = dynamic_cast<source::Move*>(stmt)){

      // topdown_much_expr(move->source, table[move->dest->label]);
    }
    if (auto prnt = dynamic_cast<source::Print*>(stmt)){
      // target::Dest fresh = ++var_counter;
      // topdown_much_expr(prnt->arg,fresh);
      // instruction.push_back(new target::Print(fresh));
    }
  }
  for (int i = 0; i <= var_counter; i++){
    // symbol_table.push_back(i);
  }
  return target::Prog(symbol_table, instruction);
}

int topdown_much_expr_int(const source::Expr* e, target::Dest* dest, int Lo){
  if (auto imm = dynamic_cast<const source::Immediate*>(e)){
    instruction_counter++;
    int Li = instruction_counter;
    auto instrct = new target::MoveImm(dest,imm->value,Li,Lo);
    instruction.push_back(instrct);
    return Li;
  }
  else if (auto var= dynamic_cast<const source::Variable*>(e)){
    if (var->gettype() == source::Type::INT){
      instruction_counter++;
      int Li = instruction_counter;
      // auto instrct = new target::MoveCp(dest,table[var->label],Li,Lo);
      // instruction.push_back(instrct);
      return Li;
    }
  }
  else if (auto uno = dynamic_cast<const source::UnopApp*>(e)){
    target::Dest* source = new target::Dest(uno->gettype(),++var_counter);
    // symbol_table.push_back(source);
    instruction_counter++;
    int L1 = instruction_counter;
    // topdown_much_expr(uno->arg,source);
    auto instrct = new target::MoveUnop(dest,uno->op,source,L1,Lo);
    instruction.push_back(instrct);
    int Li = topdown_much_expr_int(uno->arg,source,L1);
    return Li;
  }
  else if (auto bino = dynamic_cast<const source::BinopApp*>(e)){
    target::Dest* source_1 = new target::Dest(bino->gettype(),++var_counter);
    // symbol_table.push_back(source_1);
    target::Dest* source_2 = new target::Dest(bino->gettype(),++var_counter);
    // symbol_table.push_back(source_2);
    instruction_counter++;
    int L2 = instruction_counter;
    // topdown_much_expr(uno->arg,source);
    auto instrct = new target::MoveBinop(dest,source_1,bino->op,source_2,L2,Lo);
    instruction.push_back(instrct);
    int L1 = topdown_much_expr_int(bino->right_arg,source_2,L2);
    int Li = topdown_much_expr_int(bino->left_arg,source_1,L1);
    return Li;
  }
  return -1;
}

int topdown_much_expr_bool(const source::Expr* e, int Lt, int Lf){
  if (auto boo = dynamic_cast<const source::Bool*>(e)){
    if (boo->boo){
      return Lt;
    }
    return Lf;
  }
  else if (auto var= dynamic_cast<const source::Variable*>(e)){
    instruction_counter++;
    int Li = instruction_counter;
    // auto instrct = new target::Ubranch(table[var->label],Li,Lt,Lf);
    // instruction.push_back(instrct);
    return Li;
  }
  else if (auto booluno = dynamic_cast<const source::BoolUnopApp*>(e)){
    return topdown_much_expr_bool(booluno->arg, Lf, Lt);
  }
  else if (auto bino = dynamic_cast<const source::BoolBinopApp*>(e)){
    if (bino->op == source::BoolBinop::And){
      int L1 = topdown_much_expr_bool(bino->right_arg, Lt, Lf);
      return topdown_much_expr_bool(bino->left_arg, L1, Lf);
    }
    else if (bino->op == source::BoolBinop::Or){
      int L1 = topdown_much_expr_bool(bino->right_arg, Lt, Lf);
      return topdown_much_expr_bool(bino->left_arg, Lt, L1);
    }
    else if (bino->left_arg->gettype() == source::Type::INT){
      instruction_counter++;
      int L2 = instruction_counter;
      target::Dest* source_1 = new target::Dest(source::Type::INT,++var_counter);
      // symbol_table.push_back(source_1);
      target::Dest* source_2 = new target::Dest(source::Type::INT,++var_counter);
      // symbol_table.push_back(source_2);
      
      // topdown_much_expr(uno->arg,source);
      // auto instrct = new target::Bbranch(source_1,source_2,bino->op,L2,Lt,Lf);
      // instruction.push_back(instrct);
      int L1 = topdown_much_expr_int(bino->right_arg,source_2,L2);
      int Li = topdown_much_expr_int(bino->left_arg,source_1,L1);
      return Li;
    }
    // else if (bino->op == source::BoolBinop::Equal){
    //   const source::Expr* expr_1 = bino->left_arg;
    //   const source::Expr* expr_2 = bino->right_arg;
    //   source::Expr* expr_1_bis = new source::BoolBinopApp(expr_1, source::BoolBinop::And,expr_2);
    //   source::Expr* expr_2_bis = new source::BoolBinopApp(expr_1, source::BoolBinop::Or,expr_2);
    //   source::Expr* expr_2_tri = new source::BoolUnopApp(source::BoolUnop::boolNot,expr_2_bis);
    //   source::Expr* expr_3 = new source::BoolBinopApp(expr_1_bis, source::BoolBinop::Or,expr_2_tri);
    //   return topdown_much_expr_bool(expr_3, Lt, Lf);      
    // }
    // else {        // if (bino->op == source::bino::NotEqual){
    //   const source::Expr* expr_1 = bino->left_arg;
    //   const source::Expr* expr_2 = bino->right_arg;
    //   source::Expr* expr_1_bis = new source::BoolBinopApp(expr_1, source::BoolBinop::And,expr_2);
    //   source::Expr* expr_2_bis = new source::BoolBinopApp(expr_1, source::BoolBinop::Or,expr_2);
    //   source::Expr* expr_1_tri = new source::BoolUnopApp(source::BoolUnop::boolNot,expr_1_bis);
    //   source::Expr* expr_3 = new source::BoolBinopApp(expr_1_tri, source::BoolBinop::Or,expr_2_bis);
    //   return topdown_much_expr_bool(expr_3, Lt, Lf); 
    // }
  }
  return -1;
}

void topdown_much_statem(const source::Stmt* s, int Lo){
  if (auto move = dynamic_cast<const source::Move *>(s)){
    // TODO
  }
  else if (auto print = dynamic_cast<const source::Print *>(s)){
    // TODO
  }
  else if (auto block = dynamic_cast<const source::Block *>(s)){
    // TODO
  }
  else if (auto ifelse = dynamic_cast<const source::Ifelse *>(s)){
    // TODO
  }
  else if (auto whilee = dynamic_cast<const source::Whilee *>(s)){
    // TODO
  }
}


} // bx
