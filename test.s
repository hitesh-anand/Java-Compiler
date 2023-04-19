.text
.globl main
main:
pushq %rbp
movq %rsp, %rbp
subq $64, %rsp
movq    $0, 0(%rbp)
movq    $0, 0(%rbp)
movq    0(%rbp), %rax
movq    $5, %rcx
cmpq    %rcx, %rax
jl .L8
jmp .L12
movq    0(%rbp), %rbx
movq    $1, %rcx
addq    %rbx, %rcx
movq    %rcx, 0(%rbp)
movq    0(%rbp), %rbx
movq    %rbx, 0(%rbp
movq    0(%rbp), %rbx
movq    $1, %rcx
addq    %rbx, %rcx
movq    %rcx, 0(%rbp)
.L8:
jmp .L6
leave
ret
movq $60, %rax
xorq %rbx, %rbx
syscall
printfmt: 
.string "%d"