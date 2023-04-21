.text


.globl main
main:
pushq %rbp
movq %rsp, %rbp
subq $16, %rsp
movq	%rdi, -8(%rbp)
movq	$1, %r10
movq	$0, %rax
movq	$printfmt, %rdi
movq	%r10, %rsi
call printf
movq	$0, %rax
leave
ret
movq $60, %rax
xorq %rbx, %rbx
syscall
printfmt: 
.string "%d"