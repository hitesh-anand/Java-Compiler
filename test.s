.text
.globl add
add:
pushq %rbp
movq %rsp, %rbp
subq $40, %rsp
movq %rsi, -24(%rbp)
movq %rdx, -32(%rbp)
movq $0, %rax
salq $3, %rax
movq -24(%rbp), %rdi
addq %rax, %rdi
movq (%rdi), %rbx
movq $1, %rax
salq $3, %rax
movq -24(%rbp), %rdi
addq %rax, %rdi
movq (%rdi), %rcx
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
.globl main
main:
pushq %rbp
movq %rsp, %rbp
subq $64, %rsp
movq $5,%rdi
salq $3,%rdi
call    malloc
movq %rax, -8(%rbp)
movq    $0, -16(%rbp)
movq    $0, -16(%rbp)
.L10:
movq    -16(%rbp), %rax
movq    $4, %rcx
cmpq    %rcx, %rax
jl .L12
jmp .L18
.L12:
movq    -16(%rbp), %rbx
movq    $1, %rcx
addq    %rbx, %rcx
movq    %rcx, -40(%rbp)
movq    -40(%rbp), %rbx
movq %rbx, %rdx
movq -16(%rbp), %rax
salq $3, %rax
movq -8(%rbp), %rdi
addq %rax, %rdi
movq %rdx, (%rdi)
movq -16(%rbp), %rax
salq $3, %rax
movq -8(%rbp), %rdi
addq %rax, %rdi
movq (%rdi), %rbx
movq    %rbx, -24(%rbp)
movq    $0, %rax
movq    $printfmt, %rdi
movq    -24(%rbp), %rsi
call printf
movq    -16(%rbp), %rbx
movq    $1, %rcx
addq    %rbx, %rcx
movq    %rcx, -16(%rbp)
jmp .L10
.L18:
movq    $1, -32(%rbp)
movq  -8(%rbp), %rsi
movq  $5, %rdx
call add
leave
ret
movq $60, %rax
xorq %rbx, %rbx
syscall
printfmt: 
.string "%d"