	.file	"test1.c"
	.text
	.globl	main
	.type	main, @function
main:
.LFB0:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movl	$3, -4(%rbp)
	movl	$4, -8(%rbp)
	movl	$5, -12(%rbp)
	movl	$10, -16(%rbp)
	movl	-8(%rbp), %edx
	movl	-4(%rbp), %eax
	movl	%edx, %esi
	movl	%eax, %edi
	call	printName
	nop
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE0:
	.size	main, .-main
	.section	.rodata
.LC0:
	.string	"Javatpoint"
.LC1:
	.string	"%s"
.LC2:
	.string	"%d\n"
	.text
	.globl	printName
	.type	printName, @function
printName:
.LFB1:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$96, %rsp
	movl	%edi, -84(%rbp)
	movl	%esi, -88(%rbp)
	movl	$.LC0, %edi
	movl	$0, %eax
	call	printf
	movl	-84(%rbp), %edx
	movl	-88(%rbp), %eax
	addl	%edx, %eax
	movl	%eax, -4(%rbp)
	movabsq	$2336652919000361044, %rax
	movabsq	$7738436977810240361, %rdx
	movq	%rax, -80(%rbp)
	movq	%rdx, -72(%rbp)
	movabsq	$2336923043636736878, %rax
	movabsq	$2336923344185028203, %rdx
	movq	%rax, -64(%rbp)
	movq	%rdx, -56(%rbp)
	movabsq	$7311424809486677867, %rax
	movabsq	$8606218790523859307, %rdx
	movq	%rax, -48(%rbp)
	movq	%rdx, -40(%rbp)
	movabsq	$8605365612633727082, %rax
	movabsq	$7956852780729067118, %rdx
	movq	%rax, -32(%rbp)
	movq	%rdx, -24(%rbp)
	movl	$2105453, -16(%rbp)
	leaq	-80(%rbp), %rax
	movq	%rax, %rsi
	movl	$.LC1, %edi
	movl	$0, %eax
	call	printf
	movl	-4(%rbp), %eax
	movl	%eax, %esi
	movl	$.LC2, %edi
	movl	$0, %eax
	call	printf
	nop
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1:
	.size	printName, .-printName
	.ident	"GCC: (GNU) 12.2.1 20220819 (Red Hat 12.2.1-2)"
	.section	.note.GNU-stack,"",@progbits
