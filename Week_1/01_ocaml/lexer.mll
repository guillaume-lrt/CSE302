{
  open Parser

  exception Error of string
}

let number = ['0'-'9'] +

(* Initial characters for variables *)
let ichar = ['A'-'Z' 'a'-'z' '_']

(* Characters allowed only in the body of variables. *)
let bchar = ['0'-'9']

let name = ichar (ichar|bchar)*
let blank = ' ' | '\t' | '\r'

rule token = parse
| eof
    { ENDOFSTREAM }
| blank
    { token lexbuf }
| '\n'
    { Lexing.new_line lexbuf ; token lexbuf }
| "print"
    { PRINT }
| name as n
    { IDENT n }
| number as i
    { INT (int_of_string i) }
| '+'
    { PLUS }
| '-'
    { MINUS }
| '*'
    { ASTERISK }
| '/'
    { SLASH }
| '%'
    { PERCENT }
| '|'
    { BAR }
| '&'
    { AMPERSAND }
| '^'
    { CARET }
| '~'
    { TILDE }
| "<<"
    { LTLT }
| ">>"
    { GTGT }
| '='
    { EQUAL }
| '('
    { LPAREN }
| ')'
    { RPAREN }
| ';'
    { SEMICOLON }
| _
    { raise (Error (Printf.sprintf "At offset %d: unexpected character.\n" (Lexing.lexeme_start lexbuf))) }
