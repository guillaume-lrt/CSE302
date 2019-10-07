    .file " test/fib.bx"
    .section .text
    .globl main
main:
    pushq %rbp		# save the old value of RBP
    movq %rsp, %rbp	# make RSP (stack top) a copy of RBP

    #allocation of n stack slots
    subq $-288, %rsp	# res = n * 8 with n = 35

    #############################

// symbol table
// code
    movq $0, -8(%rsp)
    movq $1, -16(%rsp)
    movq -8(%rsp), %R11
    movq %R11, -24(%rsp)
    movq -24(%rsp),%rdi
    callq bx0_print
    movq -8(%rsp), %R11
    movq %R11, -32(%rsp)
    movq -16(%rsp), %R11
    movq %R11, -8(%rsp)
    movq -16(%rsp), %R11
    movq %R11, -40(%rsp)
    movq -32(%rsp), %R11
    movq %R11, -48(%rsp)
    movq -40(%rsp), %R11
    addq -48(%rsp), %R11
    movq %R11, -16(%rsp)
    movq -8(%rsp), %R11
    movq %R11, -56(%rsp)
    movq -56(%rsp),%rdi
    callq bx0_print
    movq -8(%rsp), %R11
    movq %R11, -32(%rsp)
    movq -16(%rsp), %R11
    movq %R11, -8(%rsp)
    movq -16(%rsp), %R11
    movq %R11, -64(%rsp)
    movq -32(%rsp), %R11
    movq %R11, -72(%rsp)
    movq -64(%rsp), %R11
    addq -72(%rsp), %R11
    movq %R11, -16(%rsp)
    movq -8(%rsp), %R11
    movq %R11, -80(%rsp)
    movq -80(%rsp),%rdi
    callq bx0_print
    movq -8(%rsp), %R11
    movq %R11, -32(%rsp)
    movq -16(%rsp), %R11
    movq %R11, -8(%rsp)
    movq -16(%rsp), %R11
    movq %R11, -88(%rsp)
    movq -32(%rsp), %R11
    movq %R11, -96(%rsp)
    movq -88(%rsp), %R11
    addq -96(%rsp), %R11
    movq %R11, -16(%rsp)
    movq -8(%rsp), %R11
    movq %R11, -104(%rsp)
    movq -104(%rsp),%rdi
    callq bx0_print
    movq -8(%rsp), %R11
    movq %R11, -32(%rsp)
    movq -16(%rsp), %R11
    movq %R11, -8(%rsp)
    movq -16(%rsp), %R11
    movq %R11, -112(%rsp)
    movq -32(%rsp), %R11
    movq %R11, -120(%rsp)
    movq -112(%rsp), %R11
    addq -120(%rsp), %R11
    movq %R11, -16(%rsp)
    movq -8(%rsp), %R11
    movq %R11, -128(%rsp)
    movq -128(%rsp),%rdi
    callq bx0_print
    movq -8(%rsp), %R11
    movq %R11, -32(%rsp)
    movq -16(%rsp), %R11
    movq %R11, -8(%rsp)
    movq -16(%rsp), %R11
    movq %R11, -136(%rsp)
    movq -32(%rsp), %R11
    movq %R11, -144(%rsp)
    movq -136(%rsp), %R11
    addq -144(%rsp), %R11
    movq %R11, -16(%rsp)
    movq -8(%rsp), %R11
    movq %R11, -152(%rsp)
    movq -152(%rsp),%rdi
    callq bx0_print
    movq -8(%rsp), %R11
    movq %R11, -32(%rsp)
    movq -16(%rsp), %R11
    movq %R11, -8(%rsp)
    movq -16(%rsp), %R11
    movq %R11, -160(%rsp)
    movq -32(%rsp), %R11
    movq %R11, -168(%rsp)
    movq -160(%rsp), %R11
    addq -168(%rsp), %R11
    movq %R11, -16(%rsp)
    movq -8(%rsp), %R11
    movq %R11, -176(%rsp)
    movq -176(%rsp),%rdi
    callq bx0_print
    movq -8(%rsp), %R11
    movq %R11, -32(%rsp)
    movq -16(%rsp), %R11
    movq %R11, -8(%rsp)
    movq -16(%rsp), %R11
    movq %R11, -184(%rsp)
    movq -32(%rsp), %R11
    movq %R11, -192(%rsp)
    movq -184(%rsp), %R11
    addq -192(%rsp), %R11
    movq %R11, -16(%rsp)
    movq -8(%rsp), %R11
    movq %R11, -200(%rsp)
    movq -200(%rsp),%rdi
    callq bx0_print
    movq -8(%rsp), %R11
    movq %R11, -32(%rsp)
    movq -16(%rsp), %R11
    movq %R11, -8(%rsp)
    movq -16(%rsp), %R11
    movq %R11, -208(%rsp)
    movq -32(%rsp), %R11
    movq %R11, -216(%rsp)
    movq -208(%rsp), %R11
    addq -216(%rsp), %R11
    movq %R11, -16(%rsp)
    movq -8(%rsp), %R11
    movq %R11, -224(%rsp)
    movq -224(%rsp),%rdi
    callq bx0_print
    movq -8(%rsp), %R11
    movq %R11, -32(%rsp)
    movq -16(%rsp), %R11
    movq %R11, -8(%rsp)
    movq -16(%rsp), %R11
    movq %R11, -232(%rsp)
    movq -32(%rsp), %R11
    movq %R11, -240(%rsp)
    movq -232(%rsp), %R11
    addq -240(%rsp), %R11
    movq %R11, -16(%rsp)
    movq -8(%rsp), %R11
    movq %R11, -248(%rsp)
    movq -248(%rsp),%rdi
    callq bx0_print
    movq -8(%rsp), %R11
    movq %R11, -32(%rsp)
    movq -16(%rsp), %R11
    movq %R11, -8(%rsp)
    movq -16(%rsp), %R11
    movq %R11, -256(%rsp)
    movq -32(%rsp), %R11
    movq %R11, -264(%rsp)
    movq -256(%rsp), %R11
    addq -264(%rsp), %R11
    movq %R11, -16(%rsp)
    movq -8(%rsp), %R11
    movq %R11, -272(%rsp)
    movq -272(%rsp),%rdi
    callq bx0_print
    #############################

    movq %rbp, %rsp	# restore the old RSP (deallocate temps)
    popq %rbp		# restore the old RBP
    movq $0, %rax		# return code 0 stored in RAX
    retq			# return to the C runtime, which exits the program
