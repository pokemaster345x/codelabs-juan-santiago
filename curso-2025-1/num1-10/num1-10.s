.data
mensaje: .asciz "%ld \n"

.text
.global main
.extern printf

main:
	subq $8, %rsp
	xorq %rbx, %rbx

dowhile:
	incq %rbx
	movq $mensaje, %rdi
	movq %rbx, %rsi
	xorq %rax, %rax
	call printf
	cmpq $10, %rbx
	JB dowhile

	addq $8, %rsp
	mov $60, %rax
	xor %rdi, %rdi
	syscall

