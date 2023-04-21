.text
.globl Person
Person:
pushq %rbp
movq %rsp, %rbp
subq $32, %rsp
movq    %rdi, -24(%rbp)
movq %rsi, -8(%rbp)
movq %rdx, -16(%rbp)
movq    -8(%rbp), %rbx
movq    -24(%rbp), %rax
addq    $0, %rax
movq    %rbx, (%rax)
movq    -16(%rbp), %rbx
movq    -24(%rbp), %rax
addq    $8, %rax
movq    %rbx, (%rax)
leave
ret
.globl printDetails
printDetails:
pushq %rbp
movq %rsp, %rbp
subq $16, %rsp
movq    %rdi, -8(%rbp)
movq    $0, %rax
movq    $printfmt, %rdi
movq    -8(%rbp), %rbx
addq    $0, %rbx
movq    (%rbx), %rsi
call printf
movq    $0, %rax
movq    $printfmt, %rdi
movq    -8(%rbp), %rbx
addq    $8, %rbx
movq    (%rbx), %rsi
call printf
leave
ret
.globl main
main:
pushq %rbp
movq %rsp, %rbp
subq $40, %rsp
movq    %rdi, -32(%rbp)
movq    $16, %rdi
call    malloc
movq    %rax, -24(%rbp)
movq    -24(%rbp), %rdi
movq    -24(%rbp), %rdi
movq  $30, %rsi
movq  $123, %rdx
call Person
call printDetails
leave
ret
movq $60, %rax
xorq %rbx, %rbx
syscall
printfmt: 
.string "%d"