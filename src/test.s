.text


.globl test6_printnum
test6_printnum:
pushq %rbp
movq %rsp, %rbp
subq $16, %rsp
movq	%rdi, -8(%rbp)
movq	$3, %r10
movq	$0, %rax
movq	$printfmt, %rdi
movq	%r10, %rsi
call printf
movq	$1, %rax
leave
ret


.globl test6_printchar
test6_printchar:
pushq %rbp
movq %rsp, %rbp
subq $16, %rsp
movq	%rdi, -8(%rbp)
movq	$4, %r10
movq	$0, %rax
movq	$printfmt, %rdi
movq	%r10, %rsi
call printf
movq	$2, %rax
leave
ret


.globl test6_printdouble
test6_printdouble:
pushq %rbp
movq %rsp, %rbp
subq $16, %rsp
movq	%rdi, -8(%rbp)
movq	$1, %r10
movq	$0, %rax
movq	$printfmt, %rdi
movq	%r10, %rsi
call printf
movq	$3, %rax
leave
ret


.globl main
main:
pushq %rbp
movq %rsp, %rbp
subq $64, %rsp
movq	%rdi, -56(%rbp)
call test6_printchar
movq	%rax, -8(%rbp)
movq	-8(%rbp), %rax
movq	$3, %rcx
.L15:
cmpq	%rcx, %rax
jl .L23
jmp .L17
.L17:
call test6_printnum
movq	%rax, -16(%rbp)
movq	-16(%rbp), %rax
movq	$2, %rcx
.L18:
cmpq	%rcx, %rax
jg .L23
jmp .L20
.L20:
call test6_printdouble
movq	%rax, -24(%rbp)
movq	-24(%rbp), %rax
movq	$1, %rcx
.L21:
cmpq	%rcx, %rax
jg .L23
jmp .L25
.L23:
movq	$1, %rax
jmp .L35
.L25:
call test6_printchar
movq	%rax, -32(%rbp)
movq	-32(%rbp), %rax
movq	$3, %rcx
.L26:
cmpq	%rcx, %rax
jl .L31
jmp .L28
.L28:
call test6_printnum
movq	%rax, -40(%rbp)
movq	-40(%rbp), %rax
movq	$2, %rcx
.L29:
cmpq	%rcx, %rax
jg .L31
jmp .L35
.L31:
call test6_printdouble
movq	%rax, -48(%rbp)
movq	-48(%rbp), %rax
movq	$1, %rcx
.L32:
cmpq	%rcx, %rax
jg .L34
jmp .L35
.L34:
movq	$2, %rax
.L35:
movq	$5, %rax
leave
ret
movq $60, %rax
xorq %rbx, %rbx
syscall
printfmt: 
.string "%d"