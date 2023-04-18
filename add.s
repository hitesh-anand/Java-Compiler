
sumFmt:
    .ascii "The sum is: %d\n\0" # null-terminated format string for output message

.section .text
.globl main

main:
    # Load the values to be added into registers
    #movq $1, %rax # 1st number
    movq $2, %rbx # 2nd number

    # Add the values and store the result in %rax
    #addq %rbx, %rax

    # Call printf to print the sum
    movq $0, %rax # system call for printf
    movq $sumFmt, %rdi # format string
    movq %rbx, %rsi # pass the sum as the second argument
    #movq %rax, %rdx # pass the sum as the first argument
    call printf

    # Exit program
    movq $60, %rax # system call for exit
    xorq %rbx, %rbx # exit status 0
    syscall # invoke system call
