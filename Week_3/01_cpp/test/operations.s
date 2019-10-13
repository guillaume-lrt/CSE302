    .file " test/operations.bx"
    .section .text
    .globl main
main:
    pushq %rbp		# save the old value of RBP
    movq %rsp, %rbp	# make RSP (stack top) a copy of RBP

    #allocation of n stack slots
    subq $336, %rsp	# res = n * 8 with n = 41

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
    movq 40(%rsp), %R11
    movq %R11, 40(%rsp)
    movq 40(%rsp),%rdi
    callq bx0_print
    movq 56(%rsp), %R11
    movq %R11, 56(%rsp)
    movq 56(%rsp),%rdi
    callq bx0_print
    movq 72(%rsp), %R11
    movq %R11, 72(%rsp)
    movq 72(%rsp),%rdi
    callq bx0_print
    movq 88(%rsp), %R11
    movq %R11, 88(%rsp)
    movq 88(%rsp),%rdi
    callq bx0_print
    movq 104(%rsp), %R11
    movq %R11, 104(%rsp)
    movq 104(%rsp),%rdi
    callq bx0_print
    movq 120(%rsp), %R11
    movq %R11, 120(%rsp)
    movq 120(%rsp),%rdi
    callq bx0_print
    movq 136(%rsp), %R11
    movq %R11, 136(%rsp)
    movq 136(%rsp),%rdi
    callq bx0_print
    movq 152(%rsp), %R11
    movq %R11, 152(%rsp)
    movq 152(%rsp),%rdi
    callq bx0_print
    movq 168(%rsp), %R11
    movq %R11, 168(%rsp)
    movq 168(%rsp),%rdi
    callq bx0_print
    movq 184(%rsp), %R11
    movq %R11, 184(%rsp)
    movq 184(%rsp),%rdi
    callq bx0_print
    movq 200(%rsp), %R11
    movq %R11, 200(%rsp)
    movq 200(%rsp),%rdi
    callq bx0_print
    movq 216(%rsp), %R11
    movq %R11, 216(%rsp)
    movq 216(%rsp),%rdi
    callq bx0_print
    movq 232(%rsp), %R11
    movq %R11, 232(%rsp)
    movq 232(%rsp),%rdi
    callq bx0_print
    movq 248(%rsp), %R11
    movq %R11, 248(%rsp)
    movq 248(%rsp),%rdi
    callq bx0_print
    movq 264(%rsp), %R11
    movq %R11, 264(%rsp)
    movq 264(%rsp),%rdi
    callq bx0_print
    movq 280(%rsp), %R11
    movq %R11, 280(%rsp)
    movq 280(%rsp),%rdi
    callq bx0_print
    movq 296(%rsp), %R11
    movq %R11, 296(%rsp)
    movq 296(%rsp),%rdi
    callq bx0_print
    movq 312(%rsp), %R11
    movq %R11, 312(%rsp)
    movq 312(%rsp),%rdi
    callq bx0_print
    #############################

    movq %rbp, %rsp	# restore the old RSP (deallocate temps)
    popq %rbp		# restore the old RBP
    movq $0, %rax		# return code 0 stored in RAX
    retq			# return to the C runtime, which exits the program
