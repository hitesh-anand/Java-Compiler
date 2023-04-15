.text
.globl main
main:
pushq   %rbp
movq    %rsp,%rbp
subq    $24,%rsp
movq    $4, -8(%rbp)
movq    $5, -16(%rbp)
movq    -8(%rbp), %rax
movq    -16(%rbp), %rbx
addq    %rax, %rbx
movq    $0, %rax
movq    $printfmt, %rdi
movq    %rbx, %rsi
call printf
leave
ret
movq $60, %rax
xorq %rbx, %rbx
syscall
printfmt:
.string "%d"