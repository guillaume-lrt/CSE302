%token <string> IDENT
%token <int> INT
%token PLUS MINUS ASTERISK SLASH PERCENT
%token AMPERSAND BAR CARET LTLT GTGT
%token UMINUS TILDE
%token EQUAL PRINT
%token SEMICOLON LPAREN RPAREN
%token ENDOFSTREAM

%left BAR
%left CARET
%left AMPERSAND
%left LTLT GTGT
%left PLUS MINUS
%left ASTERISK SLASH PERCENT
%nonassoc UMINUS

%start <Ast.Source.prog> prog

%%

prog:
| prg=list(stmt) ENDOFSTREAM
{ Ast.Source.(Prog prg) }

expr:
| n=INT
{ Ast.Source.(Immediate n) }
| d=dest
{ Ast.Source.(Read d) }
| e1=expr PLUS e2=expr
{ Ast.Source.(Binop (Add, e1, e2)) }
| e1=expr MINUS e2=expr
{ Ast.Source.(Binop (Subtract, e1, e2)) }
| e1=expr ASTERISK e2=expr
{ Ast.Source.(Binop (Multiply, e1, e2)) }
| e1=expr SLASH e2=expr
{ Ast.Source.(Binop (Divide, e1, e2)) }
| e1=expr PERCENT e2=expr
{ Ast.Source.(Binop (Modulus, e1, e2)) }
| e1=expr LTLT e2=expr
{ Ast.Source.(Binop (Lshift, e1, e2)) }
| e1=expr GTGT e2=expr
{ Ast.Source.(Binop (Rshift, e1, e2)) }
| e1=expr AMPERSAND e2=expr
{ Ast.Source.(Binop (BitAnd, e1, e2)) }
| e1=expr BAR e2=expr
{ Ast.Source.(Binop (BitOr, e1, e2)) }
| e1=expr CARET e2=expr
{ Ast.Source.(Binop (BitXor, e1, e2)) }
| MINUS e=expr %prec UMINUS
{ Ast.Source.(Unop (Negate, e)) }
| TILDE e=expr %prec UMINUS
{ Ast.Source.(Unop (BitNot, e)) }
| LPAREN e=expr RPAREN
{ e }

stmt:
| d=dest EQUAL e=expr SEMICOLON
{ Ast.Source.(Move (d, e)) }
| PRINT e=expr SEMICOLON
{ Ast.Source.(Print e) }

dest:
| id=IDENT
{ Ast.Source.(Var id) }
