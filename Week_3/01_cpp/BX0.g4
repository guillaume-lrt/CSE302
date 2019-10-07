grammar BX0 ;

program: vardecl* statement* ;

vardecl: 'var'varinit (','varinit)*':'type';' ;

type: 'int64'		# integer
    |'bool'		  # boole
    ;

varinit: VAR ('='expr)? ;

statement: move | print | block | ifelse | whilee;

move: VAR '=' expr;
print: 'print' expr;
block: '{'(statement)*'}';
ifelse: 'if' '('expr')'block ('else'(ifelse_bis|block))?;
ifelse_bis: ifelse;
whilee: 'while''('expr')'block;


expr: VAR                               # variable
    | NUM                               # number
    | BOOL                              # boolean
    | op=('~'|'-'|'!') expr             # unop
    | expr op=('*'|'/'|'%') expr        # mul
    | expr op=('+'|'-') expr            # add
    | expr op=('<<'|'>>') expr          # shift
    | expr op=('<'|'<='|'>'|'>=') expr	# inequality
    | expr op=('=='|'!=') expr    	    # equality
    | expr '&' expr                     # and
    | expr '^' expr                     # xor
    | expr '|' expr                     # or
    | expr '&&' expr		                # booland
    | expr '||' expr		                # boolor
    | '(' expr ')'                      # parens
    ;

VAR: [A-Za-z_][A-Za-z0-9_]* ;
NUM: [0-9]+ ;
BOOL: 'true' | 'false' ;

COMMENT: '//' ~[\r\n]* '\r'? '\n' -> skip ;
WS: [ \t\r\n]+ -> skip ;
