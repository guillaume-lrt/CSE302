#include <iostream>
#include <cstdlib>

#include "antlr4-runtime.h"

#include "ast.h"

using namespace bx;

void display_source_program(source::Prog prog) {
  std::cout << "--- START OF AST ---\n";
  for (auto stmt : prog) {
    std::cout << *stmt << std::endl;
  }
  std::cout << "--- END OF AST ---\n";
}

int main(int argc, char **argv) {
  if (argc >= 2) {
    std::string bx_file{argv[1]};

    if (bx_file.size() < 3 ||
        bx_file.substr(bx_file.size() - 3, 3) != ".bx") {
      std::cerr << "Bad file name: " << bx_file << std::endl;
      std::exit(1);
    }

    auto prog = source::read_program(bx_file);
    std::cout << bx_file << " parsed.\n";

    // TODO: comment the following line of code out before submitting; it's only
    // meant for help with debuggin
    display_source_program(prog);

    auto file_root = bx_file.substr(0, bx_file.size() - 3);
    auto c_file = file_root + ".s";
    auto exe_file = file_root + ".exe";

    // TODO: convert a bx::source::Prog to a bx::target::Prog using
    // maximal munch. Note: the line below is bogus. It is there just
    // to get it to compile, and represents the empty target program.

    target::Prog target_prog = target_program(prog);

    int n = 4;  // temporary value, suppose to be the number of temparies that prog needs
    int res = n * 8;   // = number of bytes to allocate

    std::ofstream c_out;
    c_out.open(c_file);
    c_out << "    .file \" "<< file_root << ".bx\"\n    .section .text\n    .globl main\n";
    c_out << "main:\n";
    c_out << "    pushq %rbp		# save the old value of RBP\n";
    c_out << "    movq %rsp, %rbp	# make RSP (stack top) a copy of RBP\n\n";
    c_out << "    #allocation of n stack slots\n";
    c_out << "    subq $" <<res<< ", %rsp	# res = n * 8\n\n";
    c_out << "    movq $12, %rdi		# test\n";
    c_out << "    callq bx0_print		# test\n";
    c_out << "    #############################\n/*\n";
    c_out << target_prog;
    c_out << "    #############################\n*/\n";
    c_out << "    movq %rbp, %rsp	# restore the old RSP (deallocate temps)\n";
    c_out << "    popq %rbp		# restore the old RBP\n";
    c_out << "    movq $0, %rax		# return code 0 stored in RAX\n";
    c_out << "    retq			# return to the C runtime, which exits the program\n";
    //c_out << "int main(){\n";
    // TODO: fill in the print() implementations in ast.cpp
    //c_out << target_prog;
    //c_out << "}\n";
    c_out.close();
    std::cout << c_file << " written.\n";

    std::string cmd = "gcc -o " + exe_file + " " + c_file + " bx0_rt.c";
    std::cout << "Running: " << cmd << std::endl;
    if (std::system(cmd.c_str()) != 0) {
      std::cerr << "Could not run gcc successfully!\n";
      std::exit(2);
    }
    std::cout << exe_file << " created.\n";
    std::string cmd2 = "./" + exe_file;
    std::cout << cmd2 << std::endl;
  }
}
