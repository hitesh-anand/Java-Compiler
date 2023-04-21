.text


<<<<<<< HEAD
.globl hello_f
hello_f:
pushq %rbp
movq %rsp, %rbp
subq $48, %rsp
movq	%rdi, -40(%rbp)
movq %rsi, -8(%rbp)
movq %rdx, -16(%rbp)
movq	-16(%rbp), %rbx
movq	-8(%rbp), %rcx
movq    %rbx, %eax
cqo               
idiv     %rcx
movq     %rax, %rcx
idiv	%rbx, %rcx
movq	%rcx, -32(%rbp)
movq	-32(%rbp), %rbx
movq	%rbx, -24(%rbp)
=======
.globl main
main:
pushq %rbp
movq %rsp, %rbp
subq $56, %rsp
movq	%rdi, -48(%rbp)
movq $3,%rdi
imulq $3,%rdi
salq $3,%rdi
movq $3,%r8
movq %r8,-16(%rbp)
movq $3,%r8
movq %r8,-24(%rbp)
call	malloc
movq	%rax, -8(%rbp)
movq	$2, -32(%rbp)
movq	-32(%rbp), %rbx
movq	$2, %rcx
addq	%rcx, %rbx
movq	%rbx, -40(%rbp)
movq	-40(%rbp), %rbx
movq %rbx, %rdx
movq $2, %rax
movq $2, %rdi
movq -24(%rbp), %rsi
imulq %rsi, %rax
addq %rsi, %rax
salq $3, %rax
movq -8(%rbp), %rdi
addq %rax, %rdi
movq %rdx, (%rdi)
movq $2, %rax
movq $2, %rdi
movq -24(%rbp), %rsi
imulq %rsi, %rax
addq %rsi, %rax
salq $3, %rax
movq -8(%rbp), %rdi
addq %rax, %rdi
movq (%rdi), %rsi
movq	$0, %rax
movq	$printfmt, %rdi
call printf
movq	$0, %rax
>>>>>>> 3f1d021f2667cecbc2440951f528fba9a2431530
leave
ret
movq $60, %rax
xorq %rbx, %rbx
syscall
printfmt: 
.string "%d"