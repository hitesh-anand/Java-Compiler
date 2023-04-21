.text
.globl -main
hello-f:
pushq %rbp
movq %rsp, %rbp
subq $80, %rsp
movq	%rdi, -72(%rbp)
movq %rsi, -8(%rbp)
movq %rdx, -16(%rbp)
.L2:
movq	-8(%rbp), %rax
movq	-16(%rbp), %rcx
cmpq	%rcx, %rax
jl .L4
jmp .L24
.L4:
movq	$0, -24(%rbp)
.L5:
movq	-8(%rbp), %rax
movq	$0, %rcx
cmpq	%rcx, %rax
jg .L7
jmp .L19
.L7:
movq	$0, -32(%rbp)
.L8:
movq	-32(%rbp), %rax
movq	$10, %rcx
cmpq	%rcx, %rax
jl .L10
jmp .L21
.L10:
.L10:
movq	-32(%rbp), %rax
movq	$10, %rcx
cmpq	%rcx, %rax
jl .L12
jmp .L16
.L12:
movq	$0, -40(%rbp)
movq	-24(%rbp), %rbx
movq	$1, %rcx
addq	%rbx, %rcx
movq	%rcx, -48(%rbp)
movq	-48(%rbp), %rbx
movq	%rbx, -24(%rbp)
jmp .L10
.L16:
movq	-32(%rbp), %rbx
movq	$1, %rcx
addq	%rbx, %rcx
movq	%rcx, -32(%rbp)
jmp .L8
jmp .L21
.L19:
movq	-8(%rbp), %rbx
movq	$1, %rcx
subq	%rbx, %rcx
movq	%rcx, -56(%rbp)
movq	-56(%rbp), %rbx
movq	%rbx, -24(%rbp)
.L21:
movq	-8(%rbp), %rbx
movq	$1, %rcx
addq	%rbx, %rcx
movq	%rcx, -64(%rbp)
movq	-64(%rbp), %rbx
movq	%rbx, -8(%rbp)
jmp .L2
.L24:
movq	-8(%rbp), %rax
movq	-8(%rbp), %rbx
movq	$1, %rcx
addq	%rbx, %rcx
movq	%rcx, -8(%rbp)
leave
ret
hi-T:
pushq %rbp
movq %rsp, %rbp
subq $80, %rsp
movq	%rdi, -72(%rbp)
movq %rsi, -8(%rbp)
movq %rdx, -24(%rbp)
movq  -8(%rbp), %rsi
movq  -24(%rbp), %rdx
call hi-f, 2
movq	%rax, -48(%rbp)
movq	-8(%rbp), %rbx
movq	-24(%rbp), %rcx
divq	%rbx, %rcx
movq	%rcx, -56(%rbp)
movq	-56(%rbp), %rbx
movq	%rbx, -32(%rbp)
movq	-32(%rbp), %rbx
movq	$1, %rcx
addq	%rbx, %rcx
movq	%rcx, -32(%rbp)
movq	0(%rbp), %rbx
movq	%rbx, 0(%rbp)
jmp .L43
movq	-32(%rbp), %rbx
movq	%rbx, 0(%rbp)
movq	-32(%rbp), %rbx
movq	$1, %rcx
addq	%rbx, %rcx
movq	%rcx, -32(%rbp)
jmp .L45
.L43:
movq	-32(%rbp), %rbx
movq	$1, %rcx
addq	%rbx, %rcx
movq	%rcx, -32(%rbp)
movq	-32(%rbp), %rbx
movq	%rbx, 0(%rbp)
.L45:
movq	$1, -16(%rbp)
movq	-16(%rbp), %rbx
movq	-40(%rbp), %rcx
divq	%rbx, %rcx
movq	%rcx, -64(%rbp)
movq	-64(%rbp), %rbx
movq	%rbx, -16(%rbp)
movq	-16(%rbp), %rax
leave
ret
movq $60, %rax
xorq %rbx, %rbx
syscall
printfmt: 
.string "%d"