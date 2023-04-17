.text
.globl main
main:
pushq   %rbp
movq    %rsp,%rbp
subq    $8,%rsp
movq    $2, 0(%rbp)
movq    0(%rbp), %rax
movq    $4, %rcx
cmpq    %rcx, %rax
jl .L5
jmp .L8
.L5:
movq    0(%rbp), %rbx
movq    0(%rbp), %rcx
addq    %rbx, %rcx
movq    %rcx, 0(%rbp)
movq    0(%rbp), %rbx
movq    %rbx, 0(%rbp
jmp .L10
.L8:
movq    0(%rbp), %rbx
movq    0(%rbp), %rcx
addq    %rbx, %rcx
movq    %rcx, 0(%rbp)
movq    0(%rbp), %rbx
movq    %rbx, 0(%rbp
.L10:
leave
ret
movq $60, %rax
xorq %rbx, %rbx
syscall
printfmt: 
.string "%d"