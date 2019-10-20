grammar BX0 ;

program: vardecl* statement* ;

vardecl: 'var'varinit (','varinit)*':'type';' ;

type: 'int64'		# integer
    |'bool'		  # boole
    ;

varinit: VAR ('='expr)? ;

statement: move | print | block | ifelse | whilee;

move: VAR '=' expr ';';
print: 'print' expr ';';
block: '{'(statement)*'}';
ifelse: 'if' '('expr')'block ('else'ifelse_bis)?;
ifelse_bis: (ifelse|block);
whilee: 'while''('expr')'block;


expr: BOOL                              # boolean
    | VAR                               # variable
    | NUM                               # number
    | op=('~'|'-'|'!') expr             # unop
    | expr op=('*'|'/'|'%') expr        # mul
    | expr op=('+'|'-') expr            # add
    | expr op=('<<'|'>>') expr          # shift
    | expr op=('<'|'<='|'>'|'>=') expr	# inequality
    | expr op=('=='|'!=') expr    	    # equality
    | expr '&' expr                     # and
    | expr '^' expr                     # xor
    | expr '|' expr                     # or
    | expr '&&' expr		            # booland
    | expr '||' expr		            # boolor
    | '(' expr ')'                      # parens
    ;

BOOL: 'true' | 'false' ;
VAR: [A-Za-z_][A-Za-z0-9_]* ;
NUM: [0-9]+ ;

COMMENT: '//' ~[\r\n]* '\r'? '\n' -> skip ;
WS: [ \t\r\n]+ -> skip ;
