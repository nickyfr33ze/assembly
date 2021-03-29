        .data
array:  .word   894, 437, 694, 788, 302, 189, 842, 557, 257, 222
ofmt:   .asciz  "the average is %d\n"
        .align  2
        .text
        .global main

avg:    stmfd   sp!, {lr}
        // your implementation goes here
        
        mov     r2, =array      @ moves the array in to r2
        mov     r3, #10         @ this moves the value 10 into r3
        div     [r3]            @ divides r2 by r3
        ldr     r0, r3          @ loads our retrun register (r0) with the answer in r3
        bl      avg             @ finishes the program

        // remember to set r0 to the return result
        ldmfd   sp!, {lr}
        mov     pc, lr

main:   stmfd   sp!, {lr}

        ldr     r0, =array
        mov     r1, #10
        bl      avg

        mov     r1, r0
        ldr     r0, =ofmt
        bl      printf

