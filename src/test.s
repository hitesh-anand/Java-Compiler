.text
movq $60, %rax
xorq %rbx, %rbx
syscall
printfmt: 
.string "%d"