type compilation_result = {
  symbol_table : Ast.Target.dest list ;
  program : Ast.Target.prog ;
}

(* TODO *)
let compile (Ast.Source.Prog _prog) =
  failwith "Compile.compile: not implemented"
