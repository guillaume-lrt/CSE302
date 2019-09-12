(** Create the output restricted C file from a compiled program *)

val codegen : Format.formatter -> Compile.compilation_result -> unit
(** [codegen fmt res] would generate the code and write it to the
   output named fmt. Use [Format.fprintf] with [fmt] to perform the
   actual output. *)
