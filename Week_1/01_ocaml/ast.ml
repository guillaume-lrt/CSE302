(* The abstract syntax trees *)

module Source = struct
  (** Source syntax *)

  (** Destinations *)
  type dest =
    | Var of string
    (** Only variables for now *)

  (** Binary operators *)
  type binop =
    | Add | Subtract | Multiply | Divide | Modulus
    | BitAnd | BitOr | BitXor | Lshift | Rshift

  (** Unary operators *)
  type unop =
    | Negate
    | BitNot

  (** Expressions *)
  type expr =
    | Immediate of int
    (** Literal value *)
    | Read of dest
    (** Load a value *)
    | Unop of unop * expr
    (** Unary operator *)
    | Binop of binop * expr * expr
    (** Binary operator *)

  (** Statements *)
  type stmt =
    | Move of dest * expr
    (** Evaluate expression and store in dest *)
    | Print of expr
    (** Print the value in dest *)

  (** A program is a list of statements *)
  type prog = Prog of stmt list
end

module Target = struct
  (** Target syntax *)

  (** Destinations *)
  type dest =
    | Loc of int
    (** locations in a symbol table *)

  (** Instructions *)
  type instr =
    | MoveImm of dest * int
    (** move immediate *)
    | MoveCp of dest * dest
    (** copy of destination *)
    | MoveBinop of { dest : dest ; arg1 : dest ; arg2 : dest ; op : Source.binop }
    (** Binary operator application *)
    | MoveUnop of { dest : dest ; arg : dest ; op : Source.unop }
    (** Unary operator application *)
    | Print of dest
    (** Print *)
    | Comment of string
    (** Comment *)

  (** Programs are lists of instructions *)
  type prog = Prog of instr list
end
