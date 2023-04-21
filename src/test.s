.text
.globl hello_f
hello_f:
pushq %rbp
movq %rsp, %rbp
subq $32, %rsp
movq	%rdi, -24(%rbp)
movq %rsi, -8(%rbp)
movq %rdx, -16(%rbp)
.L3:
movq	-8(%rbp), %rax
movq	$1, %rcx
cmpq	%rcx, %rax
je .L5
jmp .L6
.L5:
movq	-16(%rbp), %rbx
movq	$1, %rcx
addq	%rbx, %rcx
movq	%rcx, -16(%rbp)
.L6:
movq	-8(%rbp), %rax
movq	-8(%rbp), %rbx
movq	$1, %rcx
addq	%rbx, %rcx
movq	%rcx, -8(%rbp)
leave
ret
.globl hi_T
hi_T:
pushq %rbp
movq %rsp, %rbp
subq $96, %rsp
movq	%rdi, -88(%rbp)
movq %rsi, -8(%rbp)
movq %rdx, -16(%rbp)
movq	-8(%rbp), %rbx
movq	-16(%rbp), %rcx
addq	%rbx, %rcx
movq	%rcx, -64(%rbp)
movq	-64(%rbp), %rbx
movq	%rbx, -56(%rbp)
movq	-8(%rbp), %rbx
movq	-16(%rbp), %rcx
subq	%rbx, %rcx
movq	%rcx, -72(%rbp)
movq	-72(%rbp), %rbx
movq	%rbx, -40(%rbp)
movq	$0, %rdi
call	malloc
movq	%rax, -32(%rbp)
movq	-32(%rbp), %rdi
movq  -56(%rbp), %rsi
movq  -40(%rbp), %rdx
call hello_f
movq	%rax, -80(%rbp)
movq	-80(%rbp), %rbx
movq	%rbx, -48(%rbp)
movq	-48(%rbp), %rax
leave
ret
.globl main
main:
pushq %rbp
movq %rsp, %rbp
subq $56, %rsp
movq	%rdi, -48(%rbp)
movq  $1, %rsi
movq  $0, %rdx
call hi_T
movq	%rax, -16(%rbp)
movq	-16(%rbp), %rbx
movq	%rbx, -8(%rbp)
movq	$0, %rax
movq	$printfmt, %rdi
movq	-8(%rbp), %rsi
call printf
leave
ret
movq $60, %rax
xorq %rbx, %rbx
syscall
printfmt: 
.string "%d"