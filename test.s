.text
.globl add
add:
pushq %rbp
movq %rsp, %rbp
subq $136, %rsp
movq %rsi, -8(%rbp)
movq %rdx, -16(%rbp)
movq %rcx, -24(%rbp)
movq %r8, -32(%rbp)
movq %r9, -48(%rbp)
movq 32(%rbp), %rdx
movq %rdx, -56(%rbp)
movq 24(%rbp), %rdx
movq %rdx, -64(%rbp)
movq 16(%rbp), %rdx
movq %rdx, -72(%rbp)
movq    -8(%rbp), %rbx
movq    -16(%rbp), %rcx
addq    %rbx, %rcx
movq    %rcx, -80(%rbp)
movq    -80(%rbp), %rbx
movq $1, %rax
salq $3, %rax
movq -24(%rbp), %rdi
addq %rax, %rdi
movq (%rdi), %rcx
addq    %rbx, %rcx
movq    %rcx, -88(%rbp)
movq    -88(%rbp), %rbx
movq    -48(%rbp), %rcx
addq    %rbx, %rcx
movq    %rcx, -96(%rbp)
movq    -96(%rbp), %rbx
movq    -56(%rbp), %rcx
addq    %rbx, %rcx
movq    %rcx, -104(%rbp)
movq    -104(%rbp), %rbx
movq    -64(%rbp), %rcx
addq    %rbx, %rcx
movq    %rcx, -112(%rbp)
movq    -112(%rbp), %rbx
movq    -72(%rbp), %rcx
addq    %rbx, %rcx
movq    %rcx, -120(%rbp)
movq    -120(%rbp), %rbx
movq    %rbx, -40(%rbp)
movq    $0, %rax
movq    $printfmt, %rdi
movq    -40(%rbp), %rsi
call printf
leave
ret
.globl main
main:
pushq %rbp
movq %rsp, %rbp
subq $80, %rsp
movq $5,%rdi
salq $3,%rdi
movq $5,%r8
movq %r8,-16(%rbp)
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
movq  -16(%rbp), %r8
movq  $4, %r9
call add
leave
ret
movq $60, %rax
xorq %rbx, %rbx
syscall
printfmt: 
.string "%d\n"