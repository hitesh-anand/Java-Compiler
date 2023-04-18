	.file	"test1.c"
	.text
<<<<<<< HEAD
	.globl	fib
	.type	fib, @function
fib:
.LFB0:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	pushq	%rbx
	subq	$24, %rsp
	.cfi_offset 3, -24
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
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE0:
	.size	fib, .-fib
	.globl	main
	.type	main, @function
main:
.LFB1:
	.cfi_startproc
=======
	.globl	printName
	.type	printName, @function
printName:
	endbr64
>>>>>>> 161f81a91e7a9a9dcb7b28eb7da1694bda157cba
	pushq	%rbp
	movq	%rsp, %rbp
<<<<<<< HEAD
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movl	$5, %edi
	call	fib
	movl	%eax, -4(%rbp)
	movl	$0, %eax
=======
	subq	$32, %rsp
	movq	%rdi, -8(%rbp)
	movl	%esi, -12(%rbp)
	movl	%edx, -16(%rbp)
	movl	%ecx, -20(%rbp)
	movl	%r8d, -24(%rbp)
	movl	%r9d, -28(%rbp)
	movq	-8(%rbp), %rax
	movl	$1, (%rax)
	movl	-12(%rbp), %r9d
	movl	-12(%rbp), %r8d
	movl	-12(%rbp), %ecx
	movl	-16(%rbp), %edx
	movl	-12(%rbp), %esi
	movq	-8(%rbp), %rax
	movl	24(%rbp), %edi
	pushq	%rdi
	movl	16(%rbp), %edi
	pushq	%rdi
	movq	%rax, %rdi
	call	printName
	addq	$16, %rsp
	nop
>>>>>>> 161f81a91e7a9a9dcb7b28eb7da1694bda157cba
	leave
	ret
<<<<<<< HEAD
	.cfi_endproc
.LFE1:
	.size	main, .-main
	.ident	"GCC: (GNU) 12.2.1 20221121 (Red Hat 12.2.1-4)"
=======
	.size	printName, .-printName
	.globl	main
	.type	main, @function
main:
	endbr64
	pushq	%rbp
	movq	%rsp, %rbp
	subq	$48, %rsp
	movq	%fs:40, %rax
	movq	%rax, -8(%rbp)
	xorl	%eax, %eax
	movl	$7, -40(%rbp)
	movl	$8, -36(%rbp)
	movl	$1, -32(%rbp)
	movl	$2, -28(%rbp)
	movl	$3, -24(%rbp)
	movl	$4, -20(%rbp)
	movl	$5, -16(%rbp)
	movl	-40(%rbp), %r9d
	movl	-40(%rbp), %r8d
	movl	-40(%rbp), %ecx
	movl	-36(%rbp), %edx
	movl	-40(%rbp), %esi
	leaq	-32(%rbp), %rax
	movl	-40(%rbp), %edi
	pushq	%rdi
	movl	-40(%rbp), %edi
	pushq	%rdi
	movq	%rax, %rdi
	call	printName
	addq	$16, %rsp
	nop
	movq	-8(%rbp), %rax
	subq	%fs:40, %rax
	je	.L5
	call	__stack_chk_fail@PLT
.L5:
	leave
	ret
	.size	main, .-main
	.ident	"GCC: (Ubuntu 11.3.0-1ubuntu1~22.04) 11.3.0"
>>>>>>> 161f81a91e7a9a9dcb7b28eb7da1694bda157cba
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
