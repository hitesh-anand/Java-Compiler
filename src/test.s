.text


.globl hello_f
hello_f:
pushq %rbp
movq %rsp, %rbp
subq $48, %rsp
movq	%rdi, -40(%rbp)
movq %rsi, -8(%rbp)
movq %rdx, -16(%rbp)
movq	-16(%rbp), %rbx
movq	-8(%rbp), %rcx
movq    %rbx, %eax
cqo               
idiv     %rcx
movq     %rax, %rcx
idiv	%rbx, %rcx
movq	%rcx, -32(%rbp)
movq	-32(%rbp), %rbx
movq	%rbx, -24(%rbp)
leave
ret
movq $60, %rax
xorq %rbx, %rbx
syscall
printfmt: 
.string "%d"