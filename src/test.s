.text


.globl test2_f
test2_f:
pushq %rbp
movq %rsp, %rbp
subq $64, %rsp
movq	%rdi, -56(%rbp)
movq %rsi, -8(%rbp)
movq %rdx, -16(%rbp)
movq	-8(%rbp), %rax
movq	-16(%rbp), %rcx
.L2:
cmpq	%rcx, %rax
jg .L4
jmp .L15
.L4:
movq	$0, -24(%rbp)
movq	-8(%rbp), %rax
movq	$0, %rcx
.L5:
cmpq	%rcx, %rax
jg .L7
jmp .L10
.L7:
movq	-8(%rbp), %rbx
movq	$1, %rcx
addq	%rcx, %rbx
movq	%rbx, -32(%rbp)
movq	-32(%rbp), %rbx
movq	%rbx, -8(%rbp)
jmp .L12
.L10:
movq	-8(%rbp), %rbx
movq	$1, %rcx
subq	%rcx, %rbx
movq	%rbx, -40(%rbp)
movq	-40(%rbp), %rbx
movq	%rbx, -24(%rbp)
.L12:
movq	-8(%rbp), %rbx
movq	$1, %rcx
addq	%rcx, %rbx
movq	%rbx, -48(%rbp)
movq	-48(%rbp), %rbx
movq	%rbx, -8(%rbp)
jmp .L2
.L15:
movq	-8(%rbp), %rax
movq	-8(%rbp), %rbx
movq	$1, %rcx
addq	%rcx, %rbx
movq	%rbx, -8(%rbp)
leave
ret


.globl main
main:
pushq %rbp
movq %rsp, %rbp
subq $64, %rsp
movq	%rdi, -56(%rbp)
movq	$0, %rdi
call	malloc
movq	%rax, -8(%rbp)
movq	-8(%rbp), %rdi
movq  $1, %rsi
movq  $5, %rdx
call test2_f
movq	%rax, -24(%rbp)
movq	-24(%rbp), %rbx
movq	%rbx, -16(%rbp)
movq	-16(%rbp), %r10
movq	$0, %rax
movq	$printfmt, %rdi
movq	%r10, %rsi
call printf
leave
ret
movq $60, %rax
xorq %rbx, %rbx
syscall
printfmt: 
.string "%d"