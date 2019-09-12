BX0 to restricted C compiler
----------------------------

This is skeleton code for a compiler from the language BX0 to a
restricted subset of the C compiler.

To complete the assignment, you will need to finish the code for the
following modules:

* `Compile` (file: `compile.ml`)

  This performs the compilation of the source AST (`Ast.Source`) to
  the target AST (`Ast.Target`).

* `Codegen` (file: `codegen.ml`)

  From the target AST, generate the actual text of the C code that
  will then subsequently be compiled using gcc.


Requirements
------------

1. A recent OCaml installation (4.06+), preferably using opam
2. Menhir (`opam install menhir`), the parser generator
3. Dune (`opam install dune`), the build system
