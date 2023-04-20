	.file	"test1.c"
	.text
	.globl	getarray
	.type	getarray, @function
getarray:
	endbr64
	pushq	%rbp
	movq	%rsp, %rbp
	subq	$16, %rsp
	movl	$20, %edi
	call	malloc@PLT
	movq	%rax, -8(%rbp)
	movq	-8(%rbp), %rax
	movl	$1, (%rax)
	movq	-8(%rbp), %rax
	addq	$4, %rax
	movl	$1, (%rax)
	movq	-8(%rbp), %rax
	addq	$8, %rax
	movl	$2, (%rax)
	movq	-8(%rbp), %rax
	addq	$12, %rax
	movl	$3, (%rax)
	movq	-8(%rbp), %rax
	addq	$16, %rax
	movl	$1, (%rax)
	movq	-8(%rbp), %rax
	leave
<<<<<<< HEAD
	ret
=======
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE6:
>>>>>>> 304fbf65210c6f6df5d3bc49b1ef0b694d5e3b39
	.size	getarray, .-getarray
	.globl	main
	.type	main, @function
main:
<<<<<<< HEAD
	endbr64
	pushq	%rbp
	movq	%rsp, %rbp
=======
.LFB7:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
>>>>>>> 304fbf65210c6f6df5d3bc49b1ef0b694d5e3b39
	subq	$16, %rsp
	movl	$0, %eax
	call	getarray
	movq	%rax, -8(%rbp)
	movl	$0, %eax
	leave
<<<<<<< HEAD
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
=======
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE7:
	.size	main, .-main
	.ident	"GCC: (GNU) 12.2.1 20221121 (Red Hat 12.2.1-4)"
	.section	.note.GNU-stack,"",@progbits
>>>>>>> 304fbf65210c6f6df5d3bc49b1ef0b694d5e3b39
