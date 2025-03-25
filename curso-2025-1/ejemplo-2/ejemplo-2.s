
.data
mensaje: .asciz "%ld  \n"
.text
.global main
.extern printf  #indico que quiero utilizar la funcion printf de la libreria de lenguaje c 
main:
    mov $4, %rax
    mov $5, %rbx
    add %rbx, %rax #rax=rax+rbx
    

    #bloque de impresion
    mov $mensaje, %rdi
    mov %rax, %rsi
    call printf
    mov $60, %rax #indico que vamos a usar la funcion sis exit
    mov $0, %rdi  #indico que el argumento tiene un valor de 0  
    syscall       #lama a las funciones del sistema 
