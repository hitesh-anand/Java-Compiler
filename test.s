.text
.globl add
add:
pushq %rbp
movq %rsp, %rbp
subq $128, %rsp
movq %rsi, -64(%rbp)
movq %rdx, -72(%rbp)
movq %rcx, -80(%rbp)
movq %r8, -88(%rbp)
movq %r9, -96(%rbp)
movq 32(%rbp), %rdx
movq %rdx, -104(%rbp)
movq 24(%rbp), %rdx
movq %rdx, -112(%rbp)
movq 16(%rbp), %rdx
movq %rdx, -120(%rbp)
movq    -120(%rbp), %rbx
movq    -112(%rbp), %rcx
addq    %rbx, %rcx
movq    %rcx, -16(%rbp)
movq    -16(%rbp), %rbx
movq $1, %rax
salq $3, %rax
movq -96(%rbp), %rdi
addq %rax, %rdi
movq (%rdi), %rcx
addq    %rbx, %rcx
movq    %rcx, -24(%rbp)
movq    -24(%rbp), %rbx
movq    -88(%rbp), %rcx
addq    %rbx, %rcx
movq    %rcx, -32(%rbp)
movq    -32(%rbp), %rbx
movq    -80(%rbp), %rcx
addq    %rbx, %rcx
movq    %rcx, -40(%rbp)
movq    -40(%rbp), %rbx
movq    -72(%rbp), %rcx
addq    %rbx, %rcx
movq    %rcx, -48(%rbp)
movq    -48(%rbp), %rbx
movq    -64(%rbp), %rcx
addq    %rbx, %rcx
movq    %rcx, -56(%rbp)
movq    -56(%rbp), %rbx
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
subq $72, %rsp
movq $5,%rdi
salq $3,%rdi
call    malloc
movq    %rax, -8(%rbp)
movq $2, %rdx
movq $1, %rax
salq $3, %rax
movq -8(%rbp), %rdi
addq %rax, %rdi
movq %rdx, (%rdi)
movq  $5, %rdx
pushq  %rdx
movq  $6, %rdx
pushq  %rdx
movq  $7, %rdx
pushq  %rdx
movq  $1, %rsi
movq  $2, %rdx
movq  -8(%rbp), %rcx
movq  $5, %r8
movq  $4, %r9
call add
leave
ret
movq $60, %rax
xorq %rbx, %rbx
syscall
printfmt: 
.string "%d"