	.file	"test2.c"
	.text
	.def	printf;	.scl	3;	.type	32;	.endef
	.seh_proc	printf
printf:
	pushq	%rbp
	.seh_pushreg	%rbp
	pushq	%rbx
	.seh_pushreg	%rbx
	subq	$56, %rsp
	.seh_stackalloc	56
	leaq	48(%rsp), %rbp
	.seh_setframe	%rbp, 48
	.seh_endprologue
	movq	%rcx, 32(%rbp)
	movq	%rdx, 40(%rbp)
	movq	%r8, 48(%rbp)
	movq	%r9, 56(%rbp)
	leaq	40(%rbp), %rax
	movq	%rax, -16(%rbp)
	movq	-16(%rbp), %rbx
	movl	$1, %ecx
	movq	__imp___acrt_iob_func(%rip), %rax
	call	*%rax
	movq	%rbx, %r8
	movq	32(%rbp), %rdx
	movq	%rax, %rcx
	call	__mingw_vfprintf
	movl	%eax, -4(%rbp)
	movl	-4(%rbp), %eax
	addq	$56, %rsp
	popq	%rbx
	popq	%rbp
	ret
	.seh_endproc
	.globl	a
	.data
	.align 4
a:
	.long	1
	.globl	bb
	.bss
	.align 4
bb:
	.space 4
	.section .rdata,"dr"
.LC0:
	.ascii "%d\12\0"
	.text
	.globl	proc
	.def	proc;	.scl	2;	.type	32;	.endef
	.seh_proc	proc
proc:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	subq	$48, %rsp
	.seh_stackalloc	48
	.seh_endprologue
	movl	a(%rip), %eax
	leal	5(%rax), %edx
	movl	bb(%rip), %eax
	addl	%edx, %eax
	movl	%eax, -4(%rbp)
	movl	a(%rip), %eax
	testl	%eax, %eax
	jg	.L5
	movl	a(%rip), %eax
	addl	$3, %eax
	movl	%eax, -8(%rbp)
	movl	-8(%rbp), %eax
	movl	%eax, %edx
	leaq	.LC0(%rip), %rax
	movq	%rax, %rcx
	call	printf
.L5:
	nop
	addq	$48, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.def	__main;	.scl	2;	.type	32;	.endef
	.globl	main
	.def	main;	.scl	2;	.type	32;	.endef
	.seh_proc	main
main:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	subq	$64, %rsp
	.seh_stackalloc	64
	.seh_endprologue
	call	__main
	movl	$1, -4(%rbp)
	movl	$3, -8(%rbp)
	movl	$4, -12(%rbp)
	movl	$5, -16(%rbp)
	movl	-8(%rbp), %eax
	cltd
	idivl	-12(%rbp)
	movl	%eax, %edx
	movl	-4(%rbp), %eax
	addl	%eax, %edx
	movl	-8(%rbp), %eax
	imull	-16(%rbp), %eax
	leal	(%rdx,%rax), %ecx
	movl	-8(%rbp), %eax
	cltd
	idivl	-16(%rbp)
	movl	%edx, %eax
	addl	%ecx, %eax
	movl	%eax, -20(%rbp)
	call	proc
	movl	$0, %eax
	addq	$64, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.ident	"GCC: (Rev1, Built by MSYS2 project) 11.3.0"
	.def	__mingw_vfprintf;	.scl	2;	.type	32;	.endef
