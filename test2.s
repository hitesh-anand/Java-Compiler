.text
.globl main
main:
pushq	%rbp
movq	%rsp,%rbp
subq	$24,%rsp
movq	$4, -8(%rbp)
movq	$5, -16(%rbp)
movq	-8(%rbp), %rbx
movq	-16(%rbp), %rcx
addq	%rbx, %rcx
movq	%rcx, -24(%rbp)
movq	-24(%rbp), %rax
movq	$5, %rcx
cmpq	%rcx, %rax
jl .L6
jmp .L8
.L6:
movq	-24(%rbp), %rbx
movq	$1, %rcx
addq	%rbx, %rcx
movq	%rcx, -24(%rbp)
jmp .L9
.L8:
movq	-24(%rbp), %rbx
movq	$2, %rcx
addq	%rbx, %rcx
movq	%rcx, -24(%rbp)
.L9:
movq	$0, %rax
movq	$printfmt, %rdi
movq	-24(%rbp), %rsi
call printf
leave
ret
movq $60, %rax
xorq %rbx, %rbx
syscall
printfmt: 
.string "%d"