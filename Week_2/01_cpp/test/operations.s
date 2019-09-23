    .file " test/operations.bx"
    .section .text
    .globl main
main:
    pushq %rbp		# save the old value of RBP
    movq %rsp, %rbp	# make RSP (stack top) a copy of RBP

    #allocation of n stack slots
    subq $408, %rsp	# res = n * 8 with n = 51

    movq $12, %rdi		# test
    callq bx0_print		# test
    #############################
/*
// symbol table
// code
$10, 16(%rsp)
movq 16(%rsp), %R11
    movq %R11, 24(%rsp)
movq 24(%rsp),rdi
    callq bx0_print
$2, 40(%rsp)
movq 16(%rsp), %R11
    movq %R11, 48(%rsp)
x_4 = x_5*x_6;
movq 32(%rsp), %R11
    movq %R11, 56(%rsp)
movq 56(%rsp),rdi
    callq bx0_print
movq 32(%rsp), %R11
    movq %R11, 72(%rsp)
$2, 80(%rsp)
x_8 = x_9/x_10;
movq 64(%rsp), %R11
    movq %R11, 88(%rsp)
movq 88(%rsp),rdi
    callq bx0_print
movq 64(%rsp), %R11
    movq %R11, 120(%rsp)
movq 16(%rsp), %R11
    movq %R11, 128(%rsp)
x_13 = x_15-x_16;
movq 32(%rsp), %R11
    movq %R11, 112(%rsp)
x_12 = x_13-x_14;
movq 96(%rsp), %R11
    movq %R11, 136(%rsp)
movq 136(%rsp),rdi
    callq bx0_print
movq 96(%rsp), %R11
    movq %R11, 152(%rsp)
movq 96(%rsp), %R11
    movq %R11, 160(%rsp)
x_18 = x_19+x_20;
movq 144(%rsp), %R11
    movq %R11, 168(%rsp)
movq 168(%rsp),rdi
    callq bx0_print
movq 144(%rsp), %R11
    movq %R11, 184(%rsp)
x_22 = -x_23;
movq 176(%rsp), %R11
    movq %R11, 192(%rsp)
movq 192(%rsp),rdi
    callq bx0_print
movq 16(%rsp), %R11
    movq %R11, 208(%rsp)
movq 32(%rsp), %R11
    movq %R11, 224(%rsp)
$2, 232(%rsp)
x_27 = x_28*x_29;
x_25 = x_26+x_27;
movq 200(%rsp), %R11
    movq %R11, 240(%rsp)
movq 240(%rsp),rdi
    callq bx0_print
movq 16(%rsp), %R11
    movq %R11, 272(%rsp)
movq 32(%rsp), %R11
    movq %R11, 280(%rsp)
x_32 = x_34+x_35;
$2, 264(%rsp)
x_31 = x_32*x_33;
movq 248(%rsp), %R11
    movq %R11, 288(%rsp)
movq 288(%rsp),rdi
    callq bx0_print
movq 248(%rsp), %R11
    movq %R11, 304(%rsp)
x_37 = ~x_38;
movq 296(%rsp), %R11
    movq %R11, 312(%rsp)
movq 312(%rsp),rdi
    callq bx0_print
movq 296(%rsp), %R11
    movq %R11, 328(%rsp)
$2, 336(%rsp)
x_40 = x_41>>x_42;
movq 320(%rsp), %R11
    movq %R11, 344(%rsp)
movq 344(%rsp),rdi
    callq bx0_print
movq 296(%rsp), %R11
    movq %R11, 376(%rsp)
movq 320(%rsp), %R11
    movq %R11, 384(%rsp)
x_45 = x_47&x_48;
movq 248(%rsp), %R11
    movq %R11, 392(%rsp)
movq 200(%rsp), %R11
    movq %R11, 400(%rsp)
x_46 = x_49^x_50;
x_44 = x_45%x_46;
movq 352(%rsp), %R11
    movq %R11, 408(%rsp)
movq 408(%rsp),rdi
    callq bx0_print
    #############################
*/
    movq %rbp, %rsp	# restore the old RSP (deallocate temps)
    popq %rbp		# restore the old RBP
    movq $0, %rax		# return code 0 stored in RAX
    retq			# return to the C runtime, which exits the program
