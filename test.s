.text
.globl bark
bark:
pushq %rbp
movq %rsp, %rbp
subq $24, %rsp
movq    %rdi, -16(%rbp)
movq %rsi, -8(%rbp)
movq    $0, %rax
movq    $printfmt, %rdi
movq    -8(%rbp), %rsi
call printf
leave
ret
.globl main
main:
pushq %rbp
movq %rsp, %rbp
subq $40, %rsp
movq    %rdi, -32(%rbp)
movq    $0, %rdi
call    malloc
movq    %rax, -8(%rbp)
movq    -8(%rbp), %rdi
movq    $1, %rbx
movq    $2, %rcx
imulq   %rbx, %rcx
movq    %rcx, -16(%rbp)
movq    -16(%rbp), %rbx
movq    $3, %rcx
addq    %rbx, %rcx
movq    %rcx, -24(%rbp)
movq  -24(%rbp), %rsi
call bark
leave
ret
movq $60, %rax
xorq %rbx, %rbx
syscall
printfmt: 
.string "%d\n"