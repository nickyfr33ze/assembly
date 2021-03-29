    .text
    .global main
   

main:
    sub sp, sp, #4
    str lr, [sp, #0]

# Prompt For An Input
    ldr r0, =prompt
    bl  printf

#Scanf
    ldr r0, =format
    sub sp, sp, #4
    mov r1, sp
    bl  scanf
    ldr r2, [sp, #0]
    add sp, sp, #4

# Printing The Message
    mov r1, r2
    bl  scanf

    ldr lr, [sp, #0]
    add sp, sp, #4
    mov pc, lr

    .data

format:
    .asciz "Your Number Is %d \n"

prompt:
    .asciz "Enter A Number\n" 
    
inputformat:   
    .asciz  "%d"