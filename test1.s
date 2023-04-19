	.file	"test1.c"
	.text
	.globl	fib
	.type	fib, @function
fib:
	endbr64
	pushq	%rbp
	movq	%rsp, %rbp
	pushq	%rbx
	subq	$24, %rsp
	movl	%edi, -20(%rbp)
	cmpl	$0, -20(%rbp)
	jne	.L2
	movl	$0, %eax
	jmp	.L3
.L2:
	cmpl	$1, -20(%rbp)
	jne	.L4
	movl	$1, %eax
	jmp	.L3
.L4:
	movl	-20(%rbp), %eax
	subl	$1, %eax
	movl	%eax, %edi
	call	fib
	movl	%eax, %ebx
	movl	-20(%rbp), %eax
	subl	$2, %eax
	movl	%eax, %edi
	call	fib
	addl	%ebx, %eax
.L3:
	movq	-8(%rbp), %rbx
	leave
	ret
	.size	fib, .-fib
	.globl	main
	.type	main, @function
main:
	endbr64
	pushq	%rbp
	movq	%rsp, %rbp
	subq	$176, %rsp
	movq	%fs:40, %rax
	movq	%rax, -8(%rbp)
	xorl	%eax, %eax
	movl	$1, -160(%rbp)
	movl	$2, -156(%rbp)
	movl	$3, -152(%rbp)
	movl	$4, -148(%rbp)
	movl	$5, -144(%rbp)
	movl	$6, -140(%rbp)
	movl	$7, -136(%rbp)
	movl	$8, -132(%rbp)
	movl	$9, -128(%rbp)
	movl	$10, -124(%rbp)
	movl	$4, -168(%rbp)
	movl	$3, -164(%rbp)
	movl	-168(%rbp), %eax
	cltq
	movl	$10, -160(%rbp,%rax,4)
	movl	$1, -112(%rbp)
	movl	$1, -108(%rbp)
	movl	$1, -104(%rbp)
	movl	$1, -100(%rbp)
	movl	$1, -96(%rbp)
	movl	$1, -92(%rbp)
	movl	$1, -88(%rbp)
	movl	$1, -84(%rbp)
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
	movl	$1, -20(%rbp)
	movl	$1, -16(%rbp)
	movl	-164(%rbp), %eax
	movslq	%eax, %rcx
	movl	-168(%rbp), %eax
	movslq	%eax, %rdx
	movq	%rdx, %rax
	salq	$2, %rax
	addq	%rdx, %rax
	addq	%rcx, %rax
	movl	$5, -112(%rbp,%rax,4)
	movl	$0, %eax
	movq	-8(%rbp), %rdx
	subq	%fs:40, %rdx
	je	.L7
	call	__stack_chk_fail@PLT
.L7:
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
