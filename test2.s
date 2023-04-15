	.file	"test2.c"
	.text
	.globl	a
	.bss
	.align 4
	.type	a, @object
	.size	a, 4
a:
	.zero	4
	.globl	bb
	.align 4
	.type	bb, @object
	.size	bb, 4
bb:
	.zero	4
	.section	.rodata
.LC0:
	.string	"%d\n"
	.text
	.globl	proc
	.type	proc, @function
proc:
.LFB0:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movl	a(%rip), %eax
	leal	5(%rax), %edx
	movl	bb(%rip), %eax
	addl	%edx, %eax
	movl	%eax, -4(%rbp)
	movl	a(%rip), %eax
	cmpl	$1, %eax
	jne	.L3
	movl	a(%rip), %eax
	addl	$3, %eax
	movl	%eax, -8(%rbp)
	movl	-8(%rbp), %eax
	movl	%eax, %esi
	movl	$.LC0, %edi
	movl	$0, %eax
	call	printf
.L3:
	nop
	leave
	.cfi_restore 6
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE0:
	.size	proc, .-proc
	.globl	main
	.type	main, @function
main:
.LFB1:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$48, %rsp
	movq	$1, -8(%rbp)
	movq	$3, -16(%rbp)
	movq	$4, -24(%rbp)
	movq	$5, -32(%rbp)
	movq	-16(%rbp), %rax
	cqto
	idivq	-24(%rbp)
	movq	%rax, %rdx
	movq	-8(%rbp), %rax
	addq	%rax, %rdx
	movq	-16(%rbp), %rax
	imulq	-32(%rbp), %rax
	leaq	(%rdx,%rax), %rcx
	movq	-16(%rbp), %rax
	cqto
	idivq	-32(%rbp)
	movq	%rdx, %rax
	addq	%rcx, %rax
	movq	%rax, -40(%rbp)
	movl	$0, %eax
	leave
	.cfi_restore 6
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1:
	.size	main, .-main
	.ident	"GCC: (GNU) 12.2.1 20220819 (Red Hat 12.2.1-2)"
	.section	.note.GNU-stack,"",@progbits
