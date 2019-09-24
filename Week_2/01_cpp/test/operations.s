    .file " test/operations.bx"
    .section .text
    .globl main
main:
    pushq %rbp		# save the old value of RBP
    movq %rsp, %rbp	# make RSP (stack top) a copy of RBP

    #allocation of n stack slots
    subq $528, %rsp	# res = n * 8 with n = 65

    #############################

// symbol table
// code
    movq $10, 8(%rsp)
    movq 8(%rsp), %R11
    movq %R11, 16(%rsp)
    movq 16(%rsp),%rdi
    callq bx0_print
    movq $2, 32(%rsp)
    movq 8(%rsp), %R11
    movq %R11, 40(%rsp)
    movq 40(%rsp), %R8
    movq 32(%rsp), %rax
    imulq %R8
    movq %rax, 24(%rsp)
    movq 24(%rsp), %R11
    movq %R11, 48(%rsp)
    movq 48(%rsp),%rdi
    callq bx0_print
    movq 24(%rsp), %R11
    movq %R11, 64(%rsp)
    movq $2, 72(%rsp)
    movq 72(%rsp), %R8
    movq 64(%rsp), %rax
    cqo
    idivq %R8
    movq %rax, 56(%rsp)
    movq 56(%rsp), %R11
    movq %R11, 80(%rsp)
    movq 80(%rsp),%rdi
    callq bx0_print
    movq 56(%rsp), %R11
    movq %R11, 112(%rsp)
    movq 8(%rsp), %R11
    movq %R11, 120(%rsp)
    movq 120(%rsp), %R8
    movq 112(%rsp), %R9
    subq %R8, %R9
    movq %R9, 96(%rsp)
    movq 24(%rsp), %R11
    movq %R11, 104(%rsp)
    movq 104(%rsp), %R8
    movq 96(%rsp), %R9
    subq %R8, %R9
    movq %R9, 88(%rsp)
    movq 88(%rsp), %R11
    movq %R11, 128(%rsp)
    movq 128(%rsp),%rdi
    callq bx0_print
    movq 88(%rsp), %R11
    movq %R11, 144(%rsp)
    movq 88(%rsp), %R11
    movq %R11, 152(%rsp)
    movq 152(%rsp), %R8
    movq 144(%rsp), %R9
    addq %R8, %R9
    movq %R9, 136(%rsp)
    movq 136(%rsp), %R11
    movq %R11, 160(%rsp)
    movq 160(%rsp),%rdi
    callq bx0_print
    movq 136(%rsp), %R11
    movq %R11, 176(%rsp)
    movq 176(%rsp), %R8
    negq %R8
    movq %R8, 168(%rsp)
    movq 168(%rsp), %R11
    movq %R11, 184(%rsp)
    movq 184(%rsp),%rdi
    callq bx0_print
    movq 8(%rsp), %R11
    movq %R11, 200(%rsp)
    movq 24(%rsp), %R11
    movq %R11, 216(%rsp)
    movq $2, 224(%rsp)
    movq 224(%rsp), %R8
    movq 216(%rsp), %rax
    imulq %R8
    movq %rax, 208(%rsp)
    movq 208(%rsp), %R8
    movq 200(%rsp), %R9
    addq %R8, %R9
    movq %R9, 192(%rsp)
    movq 192(%rsp), %R11
    movq %R11, 232(%rsp)
    movq 232(%rsp),%rdi
    callq bx0_print
    movq 8(%rsp), %R11
    movq %R11, 264(%rsp)
    movq 24(%rsp), %R11
    movq %R11, 272(%rsp)
    movq 272(%rsp), %R8
    movq 264(%rsp), %R9
    addq %R8, %R9
    movq %R9, 248(%rsp)
    movq $2, 256(%rsp)
    movq 256(%rsp), %R8
    movq 248(%rsp), %rax
    imulq %R8
    movq %rax, 240(%rsp)
    movq 240(%rsp), %R11
    movq %R11, 280(%rsp)
    movq 280(%rsp),%rdi
    callq bx0_print
    movq 240(%rsp), %R11
    movq %R11, 296(%rsp)
    movq 296(%rsp), %R8
    notq %R8
    movq %R8, 288(%rsp)
    movq 288(%rsp), %R11
    movq %R11, 304(%rsp)
    movq 304(%rsp),%rdi
    callq bx0_print
    movq 288(%rsp), %R11
    movq %R11, 336(%rsp)
    movq $2, 344(%rsp)
    movq 344(%rsp), %R8
    movq 336(%rsp), %R9
    movq %R8, %rcx
    sarq %cl, %R9
    movq %R9, 320(%rsp)
    movq $2, 328(%rsp)
    movq 328(%rsp), %R8
    movq 320(%rsp), %R9
    movq %R8, %rcx
    salq %cl, %R9
    movq %R9, 312(%rsp)
    movq 312(%rsp), %R11
    movq %R11, 352(%rsp)
    movq 352(%rsp),%rdi
    callq bx0_print
    movq 288(%rsp), %R11
    movq %R11, 368(%rsp)
    movq 312(%rsp), %R11
    movq %R11, 376(%rsp)
    movq 376(%rsp), %R8
    movq 368(%rsp), %R9
    andq %R8, %R9
    movq %R9, 360(%rsp)
    movq 360(%rsp), %R11
    movq %R11, 384(%rsp)
    movq 384(%rsp),%rdi
    callq bx0_print
    movq 360(%rsp), %R11
    movq %R11, 400(%rsp)
    movq 312(%rsp), %R11
    movq %R11, 408(%rsp)
    movq 408(%rsp), %R8
    movq 400(%rsp), %rax
    cqo
    idivq %R8
    movq %rax, 392(%rsp)
    movq 392(%rsp), %R11
    movq %R11, 416(%rsp)
    movq 416(%rsp),%rdi
    callq bx0_print
    movq 392(%rsp), %R11
    movq %R11, 432(%rsp)
    movq 360(%rsp), %R11
    movq %R11, 440(%rsp)
    movq 440(%rsp), %R8
    movq 432(%rsp), %R9
    orq %R8, %R9
    movq %R9, 424(%rsp)
    movq 424(%rsp), %R11
    movq %R11, 448(%rsp)
    movq 448(%rsp),%rdi
    callq bx0_print
    movq 192(%rsp), %R11
    movq %R11, 464(%rsp)
    movq 168(%rsp), %R11
    movq %R11, 472(%rsp)
    movq 472(%rsp), %R8
    movq 464(%rsp), %rax
    cqo
    idivq %R8
    movq %rdx, 456(%rsp)
    movq 456(%rsp), %R11
    movq %R11, 480(%rsp)
    movq 480(%rsp),%rdi
    callq bx0_print
    movq 168(%rsp), %R11
    movq %R11, 496(%rsp)
    movq 88(%rsp), %R11
    movq %R11, 504(%rsp)
    movq 504(%rsp), %R8
    movq 496(%rsp), %R9
    xorq %R8, %R9
    movq %R9, 488(%rsp)
    movq 488(%rsp), %R11
    movq %R11, 512(%rsp)
    movq 512(%rsp),%rdi
    callq bx0_print
    #############################

    movq %rbp, %rsp	# restore the old RSP (deallocate temps)
    popq %rbp		# restore the old RBP
    movq $0, %rax		# return code 0 stored in RAX
    retq			# return to the C runtime, which exits the program
