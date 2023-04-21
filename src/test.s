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
subq $16, %rsp
movq	%rdi, -8(%rbp)
movq	$1, %r10
movq	$0, %rax
movq	$printfmt, %rdi
movq	%r10, %rsi
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