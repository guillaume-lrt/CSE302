(** Transform the source program (Ast.Source) into the target
    language (Ast.Target) *)

type compilation_result = {
  symbol_table : Ast.Target.dest list ;
  (** All the variables used in the compiled program *)
  program : Ast.Target.prog ;
  (** The compiled program body *)
}

val compile : Ast.Source.prog -> compilation_result
