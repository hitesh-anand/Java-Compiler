	.file	"test1.c"
	.text
	.globl	proc
	.type	proc, @function
proc:
	endbr64
	pushq	%rbp
	movq	%rsp, %rbp
	movq	%rdi, -8(%rbp)
	movq	%rsi, -16(%rbp)
	movl	%edx, -20(%rbp)
	movq	%rcx, -32(%rbp)
	movl	%r8d, %eax
	movq	%r9, -40(%rbp)
	movl	16(%rbp), %edx
	movw	%ax, -24(%rbp)
	movl	%edx, %eax
	movb	%al, -44(%rbp)
	movq	-16(%rbp), %rax
	movq	(%rax), %rdx
	movq	-8(%rbp), %rax
	addq	%rax, %rdx
	movq	-16(%rbp), %rax
	movq	%rdx, (%rax)
	movq	-32(%rbp), %rax
	movl	(%rax), %edx
	movl	-20(%rbp), %eax
	addl	%eax, %edx
	movq	-32(%rbp), %rax
	movl	%edx, (%rax)
	movq	-40(%rbp), %rax
	movzwl	(%rax), %eax
	movl	%eax, %edx
	movzwl	-24(%rbp), %eax
	addl	%edx, %eax
	movl	%eax, %edx
	movq	-40(%rbp), %rax
	movw	%dx, (%rax)
	movq	24(%rbp), %rax
	movzbl	(%rax), %eax
	movl	%eax, %edx
	movzbl	-44(%rbp), %eax
	addl	%edx, %eax
	movl	%eax, %edx
	movq	24(%rbp), %rax
	movb	%dl, (%rax)
	nop
	popq	%rbp
	ret
	.size	proc, .-proc
	.globl	f
	.type	f, @function
f:
	endbr64
	pushq	%rbp
	movq	%rsp, %rbp
	subq	$48, %rsp
	movl	%edi, -36(%rbp)
	movq	%fs:40, %rax
	movq	%rax, -8(%rbp)
	xorl	%eax, %eax
	movq	$12224, -16(%rbp)
	movl	$3243, -20(%rbp)
	movw	$12, -22(%rbp)
	movb	$97, -23(%rbp)
	movzbl	-23(%rbp), %eax
	movsbl	%al, %edi
	movzwl	-22(%rbp), %eax
	movswl	%ax, %r10d
	movl	-20(%rbp), %edx
	movq	-16(%rbp), %rax
	leaq	-22(%rbp), %r9
	leaq	-20(%rbp), %rcx
	leaq	-16(%rbp), %rsi
	leaq	-23(%rbp), %r8
	pushq	%r8
	pushq	%rdi
	movl	%r10d, %r8d
	movq	%rax, %rdi
	call	proc
	addq	$16, %rsp
	movl	$1, %eax
	movq	-8(%rbp), %rdx
	xorq	%fs:40, %rdx
	je	.L4
	call	__stack_chk_fail@PLT
.L4:
	leave
	ret
	.size	f, .-f
	.ident	"GCC: (Ubuntu 9.4.0-1ubuntu1~20.04.1) 9.4.0"
	.section	.note.GNU-stack,"",@progbits
	.section	.note.gnu.property,"a"
	.align 8
	.long	 1f - 0f
	.long	 4f - 1f
	.long	 5
0:
	.string	 "GNU"
1:
	.align 8
	.long	 0xc0000002
	.long	 3f - 2f
2:
	.long	 0x3
3:
	.align 8
4:
