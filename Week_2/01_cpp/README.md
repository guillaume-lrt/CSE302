BX0 to restricted C compiler
----------------------------

This is skeleton code for a compiler from the language BX0 to a
restricted subset of the C compiler.

This skeleton code is written in C++.

TODO: write the AST representation, instruction selection, and code
generation passes and add the suitable calls to it in bx0.cpp.

The grammar of BX0 is in the file BX0.g4, form which the lexer/parser
combination is automatically generated using Antlr v4 (see below).

Indications
------------------

  #if on the main folder (01_cpp)
$ make
$ make test/example.exe # for example fib.exe or operations.exe
			# it will create example.s and example.exe
$ ./test/example.exe	# to run the assembly file example.s
