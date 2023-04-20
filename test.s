.text
.globl main
main:
pushq %rbp
movq %rsp, %rbp
subq $128, %rsp
movq    $0, -8(%rbp)
movq    $0, -96(%rbp)
movq    $0, -96(%rbp)
.L11:
movq    -96(%rbp), %rax
movq    $10, %rcx
cmpq    %rcx, %rax
jl .L13
jmp .L20
.L13:
movq    -96(%rbp), %rbx
movq    $1, %rcx
addq    %rbx, %rcx
movq    %rcx, -112(%rbp)
movq    -112(%rbp), %rbx
movq    $1, %rcx
addq    %rbx, %rcx
movq %rcx, %rdx
movq -96(%rbp), %rax
salq $3, %rax
movq -16(%rbp), %rdi
subq %rax, %rdi
movq %rdx, (%rdi)
movq -96(%rbp), %rax
salq $3, %rax
movq -16(%rbp), %rdi
subq %rax, %rdi
movq (%rdi), %rbx
movq    $1, %rcx
addq    %rbx, %rcx
movq    %rcx, -120(%rbp)
movq    -120(%rbp), %rbx
movq    %rbx, -104(%rbp)
movq    $0, %rax
movq    $printfmt, %rdi
movq    -104(%rbp), %rsi
call printf
movq    -96(%rbp), %rbx
movq    $1, %rcx
addq    %rbx, %rcx
movq    %rcx, -96(%rbp)
jmp .L11
.L20:
leave
ret
movq $60, %rax
xorq %rbx, %rbx
syscall
printfmt: 
.string "%d\n"