	.file	"test1.c"
	.text
	.globl	fib
	.type	fib, @function
fib:
	endbr64
	pushq	%rbp
	movq	%rsp, %rbp
	subq	$8, %rsp
	movq	%rdi, -8(%rbp)
	movq	-8(%rbp), %rax
	addq	$4, %rax
	movl	(%rax), %eax
	leal	1(%rax), %edx
	movq	-8(%rbp), %rax
	movl	%edx, (%rax)
	nop
	leave
	ret
	.size	fib, .-fib
	.globl	main
	.type	main, @function
main:
	endbr64
	pushq	%rbp
	movq	%rsp, %rbp
	subq	$144, %rsp
	movq	%fs:40, %rax
	movq	%rax, -8(%rbp)
	xorl	%eax, %eax
	movl	$1, -128(%rbp)
	movl	$2, -124(%rbp)
	movl	$3, -120(%rbp)
	movl	$4, -116(%rbp)
	movl	$5, -112(%rbp)
	movl	$6, -108(%rbp)
	movl	$7, -104(%rbp)
	movl	$8, -100(%rbp)
	movl	$9, -96(%rbp)
	movl	$10, -92(%rbp)
	movl	$4, -136(%rbp)
	movl	$3, -132(%rbp)
	movl	-136(%rbp), %eax
	cltq
	movl	$10, -128(%rbp,%rax,4)
	movl	$1, -80(%rbp)
	movl	$1, -76(%rbp)
	movl	$1, -72(%rbp)
	movl	$1, -68(%rbp)
	movl	$1, -64(%rbp)
	movl	$1, -60(%rbp)
	movl	$1, -56(%rbp)
	movl	$1, -52(%rbp)
	movl	$1, -48(%rbp)
	movl	$1, -44(%rbp)
	movl	$1, -40(%rbp)
	movl	$1, -36(%rbp)
	movl	$1, -32(%rbp)
	movl	$1, -28(%rbp)
	movl	$1, -24(%rbp)
	movl	$5, -28(%rbp)
	leaq	-128(%rbp), %rax
	movq	%rax, %rdi
	call	fib
	movl	$0, %eax
	movq	-8(%rbp), %rdx
	subq	%fs:40, %rdx
	je	.L4
	call	__stack_chk_fail@PLT
.L4:
	leave
	ret
	.size	main, .-main
	.ident	"GCC: (Ubuntu 11.3.0-1ubuntu1~22.04) 11.3.0"
	.section	.note.GNU-stack,"",@progbits
	.section	.note.gnu.property,"a"
	.align 8
	.long	1f - 0f
	.long	4f - 1f
	.long	5
0:
	.string	"GNU"
1:
	.align 8
	.long	0xc0000002
	.long	3f - 2f
2:
	.long	0x3
3:
	.align 8
4:
