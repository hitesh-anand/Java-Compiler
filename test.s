.text
.globl main
main:
pushq %rbp
movq %rsp, %rbp
subq $112, %rsp
movq    $0, -8(%rbp)
movq    $3, -96(%rbp)
movq    $4, %rbx
movq    $5, %rcx
addq    %rbx, %rcx
movq    %rcx, -104(%rbp)
movq    -104(%rbp), %rbx
movq    $1, %rcx
addq    %rbx, %rcx
movq %rcx, %rdx
movq -96(%rbp), %rax
movq %rdx,-16(%rbp,%rax,8)
movq    $0, %rax
movq    $printfmt, %rdi
movq    -8(%rbp), %rsi
call printf
leave
ret
movq $60, %rax
xorq %rbx, %rbx
syscall
printfmt: 
.string "%d"