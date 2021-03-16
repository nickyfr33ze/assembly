        .data 
array:  .word   894, 437, 694, 788, 302, 189, 842, 557, 257, 222
ofmt:   .asciz "the average is %d\n"
        .align 2
        .text 
        .global main

average:stmfd   sp!, {r4, r5, r6, lr}
        mov     r4, r0
        mov     r5, r1
        mov     r6, #0

        mov     r0, #0
lp1:    cmp     r0, r5
        bge     elp1

        ldr     r1, {r4, r0, lsl #2}
        add     r6, r6, r1

        add     r0, r0, #1
        b       lp1

elp1:   sdiv    r0, r6, r0
        ldmfd   sp!, {r4, r5, r6, lr} 
        mov     pc, lr

main:   stmfd   sp!, {lr}

        ldr     r0, =array
        mov     r1, #10
        bl      average

        mov     r1, r0
        ldr     r0, =ofmt
        bl      printf

        mov     r0, #0
        ldmfd   sp!, {lr}
        mov     pc, lr