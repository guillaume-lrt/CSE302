    .file " test/test.bx"
    .section .text
    .globl main
main:
    pushq %rbp		# save the old value of RBP
    movq %rsp, %rbp	# make RSP (stack top) a copy of RBP

    #allocation of n stack slots
    subq $48, %rsp	# res = n * 8 with n = 5

    #############################

// symbol table
// code
    movq $20, 8(%rsp)
    movq 8(%rsp), %R11
    movq %R11, 16(%rsp)
    movq $22, 24(%rsp)
    movq 24(%rsp), %R8
    movq 16(%rsp), %R9
    addq %R8, %R9
    movq %R9, 8(%rsp)
    movq 8(%rsp), %R11
    movq %R11, 32(%rsp)
    movq 32(%rsp),%rdi
    callq bx0_print
    #############################

    movq %rbp, %rsp	# restore the old RSP (deallocate temps)
    popq %rbp		# restore the old RBP
    movq $0, %rax		# return code 0 stored in RAX
    retq			# return to the C runtime, which exits the program
