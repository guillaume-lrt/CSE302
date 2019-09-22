    .file " test/fib.bx"
    .section .text
    .globl main
main:
    pushq %rbp		# save the old value of RBP
    movq %rsp, %rbp	# make RSP (stack top) a copy of RBP

    #allocation of n stack slots
    subq $32, %rsp	# res = n * 8

    movq $12, %rdi		# test
    callq bx0_print		# test
    #############################
/*
// symbol table
int64_t x_2;int64_t x_3;int64_t x_4;int64_t x_5;int64_t x_6;int64_t x_7;int64_t x_8;int64_t x_9;int64_t x_10;int64_t x_11;int64_t x_12;int64_t x_13;int64_t x_14;int64_t x_15;int64_t x_16;int64_t x_17;int64_t x_18;int64_t x_19;int64_t x_20;int64_t x_21;int64_t x_22;int64_t x_23;int64_t x_24;int64_t x_25;int64_t x_26;int64_t x_27;int64_t x_28;int64_t x_29;int64_t x_30;int64_t x_31;int64_t x_32;int64_t x_33;int64_t x_34;int64_t x_35;int64_t x_36;
// code
x_3 = 0;
x_4 = 1;
x_5 = x_3;
PRINT(x_5);
x_6 = x_3;
x_3 = x_4;
x_7 = x_4;
x_8 = x_6;
x_4 = x_7+x_8;
x_9 = x_3;
PRINT(x_9);
x_6 = x_3;
x_3 = x_4;
x_10 = x_4;
x_11 = x_6;
x_4 = x_10+x_11;
x_12 = x_3;
PRINT(x_12);
x_6 = x_3;
x_3 = x_4;
x_13 = x_4;
x_14 = x_6;
x_4 = x_13+x_14;
x_15 = x_3;
PRINT(x_15);
x_6 = x_3;
x_3 = x_4;
x_16 = x_4;
x_17 = x_6;
x_4 = x_16+x_17;
x_18 = x_3;
PRINT(x_18);
x_6 = x_3;
x_3 = x_4;
x_19 = x_4;
x_20 = x_6;
x_4 = x_19+x_20;
x_21 = x_3;
PRINT(x_21);
x_6 = x_3;
x_3 = x_4;
x_22 = x_4;
x_23 = x_6;
x_4 = x_22+x_23;
x_24 = x_3;
PRINT(x_24);
x_6 = x_3;
x_3 = x_4;
x_25 = x_4;
x_26 = x_6;
x_4 = x_25+x_26;
x_27 = x_3;
PRINT(x_27);
x_6 = x_3;
x_3 = x_4;
x_28 = x_4;
x_29 = x_6;
x_4 = x_28+x_29;
x_30 = x_3;
PRINT(x_30);
x_6 = x_3;
x_3 = x_4;
x_31 = x_4;
x_32 = x_6;
x_4 = x_31+x_32;
x_33 = x_3;
PRINT(x_33);
x_6 = x_3;
x_3 = x_4;
x_34 = x_4;
x_35 = x_6;
x_4 = x_34+x_35;
x_36 = x_3;
PRINT(x_36);
    #############################
*/
    movq %rbp, %rsp	# restore the old RSP (deallocate temps)
    popq %rbp		# restore the old RBP
    movq $0, %rax		# return code 0 stored in RAX
    retq			# return to the C runtime, which exits the program
