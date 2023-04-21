.text
.global fibonacci_fib
fibonacci_fib:
pushq %rbp
movq %rsp, %rbp
subq $56, %rsp
movq	%rdi, -48(%rbp)
movq %rsi, -8(%rbp)
movq	$0, -16(%rbp)
movq	-8(%rbp), %rax
movq	$1, %rcx
.L3:
cmpq	%rcx, %rax
jle .L5
jmp .L7
.L5:
movq	$1, -16(%rbp)
jmp .L15
.L7:
movq	-8(%rbp), %rbx
movq	$1, %rcx
subq	%rbx, %rcx
movq	%rcx, -24(%rbp)
movq  -24(%rbp), %rsi
call fibonacci_fib
movq	%rax, -32(%rbp)
movq	-32(%rbp), %rbx
movq	%rbx, -16(%rbp)
movq	-16(%rbp), %rbx
movq	-8(%rbp), %rcx
addq	%rbx, %rcx
movq	%rcx, -40(%rbp)
movq	-40(%rbp), %rbx
movq	%rbx, -16(%rbp)
.L15:
movq	-16(%rbp), %rax
leave
ret
.globl main
main:
pushq %rbp
movq %rsp, %rbp
subq $64, %rsp
movq	%rdi, -56(%rbp)
movq	$14, -8(%rbp)
movq  -8(%rbp), %rsi
call fibonacci_fib
movq	%rax, -24(%rbp)
movq	-24(%rbp), %rbx
movq	%rbx, -16(%rbp)
movq	$0, %rax
movq	$printfmt, %rdi
movq	-16(%rbp), %rsi
call printf
leave
ret
movq $60, %rax
xorq %rbx, %rbx
syscall
printfmt: 
.string "%d"