grammar BX0 ;

program: (globalvar | function | procedure)* ;

globalvar: 'var' globalvar_init (',' globalvar_init)* ':' type ';' ;
globalvar_init: VAR '=' (NUM | BOOL) ;

function: 'fun' VAR '(' (parameter_groups)? ')' ':' type block ;

procedure: 'proc' '(' (parameter_groups)? ')' block ;

parameter_groups: parameter_group (',' parameter_group)? ;
parameter_group: VAR (',' VAR)* ':' type ;

stmt: vardecl 
    | block 
    | express 
    | move 
    | print 
    | ifelse 
    | whileLoop
    | returnStmt
    ;

vardecl: 'var' varinit (',' varinit)* ':' type ';' ;
varinit: VAR ('=' expr)? ;
type: 'int64' | 'bool' ;

block: '{' (stmt)* '}' ;

express: expr ';' ;

move: VAR '=' expr ';';

print: 'print' expr ';' ;

ifelse: 'if' '(' expr ')' block ('else' ifCont)? ;
ifCont: ifelse | block ;

whileLoop: 'while' '(' expr ')' block ;

returnStmt: 'return' expr? ';' ;


expr: VAR                                # variable
    | NUM                                # number
    | BOOL                               # boolean
    | op=('~'|'-'|'!') expr              # unop
    | expr op=('*'|'/'|'%') expr         # multiplicative
    | expr op=('+'|'-') expr             # additive
    | expr op=('<<'|'>>') expr           # shift
    | expr op=('<'|'<='|'>'|'>=') expr   # inequation
    | expr op=('=='|'!=') expr           # equation
    | expr '&' expr                      # bitAnd
    | expr '^' expr                      # bitXor
    | expr '|' expr                      # bitOr
    | expr '&&' expr                     # BoolAnd
    | expr '||' expr                     # BoolOr
    | VAR '(' (expr (',' expr)*)? ')'    # call
    | '(' expr ')'                       # parens
    ;

BOOL: 'true' | 'false' ;
VAR: [A-Za-z_][A-Za-z0-9_]* ;
NUM: [0-9]+ ;

LINECOMMENT: '//' ~[\r\n]* '\r'? '\n' -> skip;
WS: [ \t\r\n]+ -> skip ;