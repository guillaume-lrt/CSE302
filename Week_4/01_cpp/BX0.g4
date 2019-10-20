grammar BX ;

program: (globalvar | function | procedure)* ;

globalvar: 'var' globalvar_init (',' globalvar_init)* ':' type ';' ;
globalvar_init: VAR ('=' expr)? ;

function: 'fun' VAR '(' (parameter_groups)? ')' ':' type block ;

procedure: 'proc' '(' (parameter_groups)? ')' block ;

parameter_groups: parameter_group (',' parameter_group)? ;
parameter_group: VAR (',' VAR)* ':' type ;

stmt: varDecl
    | block                          # stmtGroup
    | expr ';'                       # result
    |  VAR '=' expr ';'              # move
    | 'print' expr ';'               # print
    | ifElse                         # if
    | whileLoop                      # while
    | 'return' (expr)? ','             # return
    ;

varDecl: 'var' varInit (',' varInit)* ':' type ';' ;
varInit: VAR ('=' expr)? ;

type: 'int64' | 'bool' ;

ifElse: 'if' '(' expr ')' block ('else' ifCont)? ;
ifCont: ifElse                       # elseIf
      | block                        # else
      ;

whileLoop: 'while' '(' expr ')' block ;

block: '{' stmt* '}' ;

expr: VAR                                # variable
    | NUM                                # number
    | BOOL                               # bool
    | op=('~'|'-'|'!') expr              # unop
    | expr op=('*'|'/'|'%') expr         # multiplicative
    | expr op=('+'|'-') expr             # additive
    | expr op=('<<'|'>>') expr           # shift
    | expr op=('<'|'<='|'>'|'>=') expr   # inequation
    | expr op=('=='|'!=') expr           # equation
    | expr '&' expr                      # bitAnd
    | expr '^' expr                      # bitXor
    | expr '|' expr                      # bitOr
    | expr '&&' expr                     # logAnd
    | expr '||' expr                     # logOr
    | VAR '(' (expr (',' expr)*)? ')'    # call
    | '(' expr ')'                       # parens
    ;

BOOL: 'true' | 'false' ;
VAR: [A-Za-z_][A-Za-z0-9_]* ;
NUM: [0-9]+ ;

LINECOMMENT: '//' ~[\r\n]* '\r'? '\n' -> skip;
WS: [ \t\r\n]+ -> skip ;