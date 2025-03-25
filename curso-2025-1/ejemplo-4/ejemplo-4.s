# ejemplo de una funcion hecha en assembly

.text 
.global  sumar
.global restar
sumar: # sumar(short a, short b) c: resultado =sumar(int a, int b)

	add %rsi,%rdi
	mov %rsi, %rdi

	ret

restar: # en lenguaje c: resultado=restar (int a, int b)
	sub %rsi, %rdi
	mov %rdi, %rax

	ret



