BX0 to restricted C compiler
----------------------------

This is skeleton code for a compiler from the language BX0 to a
restricted subset of the C compiler.

This skeleton code is written in C++.

TODO: write the AST representation, instruction selection, and code
generation passes and add the suitable calls to it in bx0.cpp.

The grammar of BX0 is in the file BX0.g4, form which the lexer/parser
combination is automatically generated using Antlr v4 (see below).

Build Requirements
------------------

Things should already work for the lab computers. If you want to
install it on your own computers, do the following:


1. Antlr4 (http://antlr4.org), which is the parser generator
   recommended to use with Java. Specifically, get:
   - https://www.antlr.org/download/antlr-4.7.2-complete.jar
2. A recent Java 8 (at least version 1.8.0_112)
3. To get the Makefile to work, you will need to change the variables
   ANTLR4_JAR at the top of the file to point to where you placed the
   above antlr jar.
4. You also need the C++ runtime for antlr4:
   - https://www.antlr.org/download/antlr4-cpp-runtime-4.7.2-source.zip
   - alternately, install the libantlr4-runtime and libantlr4-runtime-dev
     packages from your package manager if using a Debain/Ubuntu
     Linux distribution or derivative
5. Once you have the Antlr/C++ runtime working, change the
   fields at the CFLAGS field at the top of the Makefile to point
   to the correct location of the header files.


If you don't use Linux, you will have to update the instructions to
fit your setup.
