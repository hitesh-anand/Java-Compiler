.globl main
add:
pushq %rbp
movq %rsp, %rbp
subq $40, %rsp
movq %rsi, -8(%rbp)
movq %rdx, -16(%rbp)
movq    -8(%rbp), %rbx
movq    -16(%rbp), %rcx
addq    %rbx, %rcx
movq    %rcx, -16(%rbp)
movq    -16(%rbp), %rbx
movq    %rbx, -8(%rbp)
movq    $0, %rax
movq    $printfmt, %rdi
movq    -8(%rbp), %rsi
call printf
leave
ret
main:
pushq %rbp
movq %rsp, %rbp
subq $24, %rsp
movq    $5, -8(%rbp)
movq    $10, -16(%rbp)
movq  -8(%rbp), %rsi
movq  -16(%rbp), %rdx
call add
leave
ret
movq $60, %rax
xorq %rbx, %rbx
syscall
printfmt: 
.string "%d"