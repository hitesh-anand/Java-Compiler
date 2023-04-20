.text
.globl main
main:
pushq %rbp
movq %rsp, %rbp
subq $128, %rsp
movq    $0, -88(%rbp)
movq    $10, -96(%rbp)
movq    $0, -104(%rbp)
movq    $0, -88(%rbp)
.L6:
movq    -88(%rbp), %rax
movq    -96(%rbp), %rcx
cmpq    %rcx, %rax
jl .L8
jmp .L14
.L8:
movq    -88(%rbp), %rbx
movq    $1, %rcx
addq    %rbx, %rcx
movq %rcx, %rdx
movq i, %rax
movq %rdx,-8(%rbp,%rax,8)
movq i, %rax
movq -8(%rbp,%rax,8), %rbx
movq    $0, %rcx
addq    %rbx, %rcx
movq    %rcx, 0(%rbp)
movq    0(%rbp), %rbx
movq    %rbx, -104(%rbp)
movq    $0, %rax
movq    $printfmt, %rdi
movq    -104(%rbp), %rsi
call printf
movq    -88(%rbp), %rbx
movq    $1, %rcx
addq    %rbx, %rcx
movq    %rcx, -88(%rbp)
jmp .L6
.L14:
movq 2, %rax
movq -8(%rbp,%rax,8), %rbx
movq 3, %rax
movq -8(%rbp,%rax,8), %rbx
addq    %rbx, %rcx
movq    %rcx, 0(%rbp)
movq    0(%rbp), %rbx
movq    %rbx, -104(%rbp)
movq    $0, %rax
movq    $printfmt, %rdi
movq    -104(%rbp), %rsi
call printf
leave
ret
movq $60, %rax
xorq %rbx, %rbx
syscall
printfmt: 
.string "%d"