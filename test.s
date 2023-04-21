.text
.globl add
add:
pushq %rbp
movq %rsp, %rbp
subq $48, %rsp
movq    %rdi, -24(%rbp)
movq %rsi, -32(%rbp)
movq %rdx, -40(%rbp)
movq $1, %rax
salq $3, %rax
movq -32(%rbp), %rdi
addq %rax, %rdi
movq (%rdi), %rbx
movq    %rbx, -16(%rbp)
movq    $0, %rax
movq    $printfmt, %rdi
movq    -16(%rbp), %rsi
call printf
leave
ret
.globl main
main:
pushq %rbp
movq %rsp, %rbp
subq $48, %rsp
movq    %rdi, -32(%rbp)
movq $5,%rdi
salq $3,%rdi
movq $5,%r8
movq %r8,-24(%rbp)
call    malloc
movq    %rax, -16(%rbp)
movq $2, %rdx
movq $1, %rax
salq $3, %rax
movq -16(%rbp), %rdi
addq %rax, %rdi
movq %rdx, (%rdi)
movq  -16(%rbp), %rsi
movq  -24(%rbp), %rdx
call add
leave
ret
movq $60, %rax
xorq %rbx, %rbx
syscall
printfmt: 
.string "%d"