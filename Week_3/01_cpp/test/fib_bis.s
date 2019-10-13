    .file " test/fib_bis.bx"
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
    movq 8(%rsp), %R11
    movq %R11, 8(%rsp)
    movq 8(%rsp),%rdi
    callq bx0_print
    movq 24(%rsp), %R11
    movq %R11, 24(%rsp)
    movq 24(%rsp),%rdi
    callq bx0_print
    #############################

    movq %rbp, %rsp	# restore the old RSP (deallocate temps)
    popq %rbp		# restore the old RBP
    movq $0, %rax		# return code 0 stored in RAX
    retq			# return to the C runtime, which exits the program
