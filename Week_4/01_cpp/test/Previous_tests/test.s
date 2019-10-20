    .file " test/test.bx"
    .section .text
    .globl main
main:
    pushq %rbp		# save the old value of RBP
    movq %rsp, %rbp	# make RSP (stack top) a copy of RBP

    #allocation of n stack slots
    subq $288, %rsp	# res = n * 8 with n = 35

    #############################

// symbol table
// code
    movq $20, 16(%rsp)
    movq 16(%rsp), %R11
    negq %R11
    movq %R11, 8(%rsp)
    movq $30, 32(%rsp)
    movq 32(%rsp), %R11
    negq %R11
    movq %R11, 24(%rsp)
    movq 8(%rsp), %R11
    movq %R11, 48(%rsp)
    movq 24(%rsp), %R11
    movq %R11, 56(%rsp)
    movq 48(%rsp), %R11
    addq 56(%rsp), %R11
    movq %R11, 40(%rsp)
    movq 40(%rsp),%rdi
    callq bx0_print
    movq 8(%rsp), %R11
    movq %R11, 64(%rsp)
    movq $10, 72(%rsp)
    movq 64(%rsp), %rax
    imulq 72(%rsp)
    movq %rax, 8(%rsp)
    movq 24(%rsp), %R11
    movq %R11, 80(%rsp)
    movq $10, 88(%rsp)
    movq 80(%rsp), %rax
    imulq 88(%rsp)
    movq %rax, 24(%rsp)
    movq 8(%rsp), %R11
    movq %R11, 104(%rsp)
    movq 24(%rsp), %R11
    movq %R11, 112(%rsp)
    movq 104(%rsp), %R11
    addq 112(%rsp), %R11
    movq %R11, 96(%rsp)
    movq 96(%rsp),%rdi
    callq bx0_print
    movq $7, 144(%rsp)
    movq 144(%rsp), %R11
    negq %R11
    movq %R11, 128(%rsp)
    movq $3, 136(%rsp)
    movq 128(%rsp), %rax
    cqo
    idivq 136(%rsp)
    movq %rax, 120(%rsp)
    movq 120(%rsp),%rdi
    callq bx0_print
    movq $7, 176(%rsp)
    movq 176(%rsp), %R11
    negq %R11
    movq %R11, 160(%rsp)
    movq $3, 168(%rsp)
    movq 160(%rsp), %rax
    cqo
    idivq 168(%rsp)
    movq %rdx, 152(%rsp)
    movq 152(%rsp),%rdi
    callq bx0_print
    movq $7, 192(%rsp)
    movq $3, 208(%rsp)
    movq 208(%rsp), %R11
    negq %R11
    movq %R11, 200(%rsp)
    movq 192(%rsp), %rax
    cqo
    idivq 200(%rsp)
    movq %rax, 184(%rsp)
    movq 184(%rsp),%rdi
    callq bx0_print
    movq $7, 224(%rsp)
    movq $3, 240(%rsp)
    movq 240(%rsp), %R11
    negq %R11
    movq %R11, 232(%rsp)
    movq 224(%rsp), %rax
    cqo
    idivq 232(%rsp)
    movq %rdx, 216(%rsp)
    movq 216(%rsp),%rdi
    callq bx0_print
    movq $6, 256(%rsp)
    movq $3, 272(%rsp)
    movq 272(%rsp), %R11
    negq %R11
    movq %R11, 264(%rsp)
    movq 256(%rsp), %rax
    cqo
    idivq 264(%rsp)
    movq %rdx, 248(%rsp)
    movq 248(%rsp),%rdi
    callq bx0_print
    #############################

    movq %rbp, %rsp	# restore the old RSP (deallocate temps)
    popq %rbp		# restore the old RBP
    movq $0, %rax		# return code 0 stored in RAX
    retq			# return to the C runtime, which exits the program
