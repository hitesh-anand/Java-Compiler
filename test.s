.data
strCR: 
	.asciiz "\n"
strPromptFirst:
	.asciiz "Enter the first no: "
strPromptSecond:
	.asciiz "Enter the second no: "
strResultAdd:
	.asciiz "Sum is = "
.text
.globl main
main:	
	li $v0, 4
	la $a0, strPromptFirst
	syscall
	
	li $v0, 5
	syscall
	move $s0, $v0

	li $v0, 4
	la $a0, strPromptSecond
	syscall

	li $v0, 5
	syscall
	move $s1, $v0

	li $v0, 4
	la $a0, strResultAdd
	syscall
	
	li $v0, 1
	add $a0, $s0, $s1
	syscall

	li $v0, 4
	la $a0, strCR
	syscall

	li $v0, 10
	syscall
	