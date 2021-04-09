	.data
	.equ	AL_SIZE, 12
	.equ	AL_NEXT, 0
	.equ	AL_CAP, 4
	.equ	AL_STR, 8
	.text
	.global	al_init
	.global al_grow
	.global	al_add
	
al_init:
	stmfd	sp!, {r4, r5, lr}
	mov	r5, r0			// r5 is capacity

	mov	r0, #AL_SIZE
	bl	malloc
	mov	r4, r0			// r4 is struct array_list *list
	
	mov	r0, #0
	str	r0, [r4, #AL_NEXT] 	// list->next = 0
	str	r5, [r4, #AL_CAP]	// list->cap = 5

	mov	r0, r5			// capacity (count of ints)
	mov	r1, #2			// shift count
	lsl	r0, r0, r1		// capcity * 4 bytes of integer storage
	bl	malloc
	str	r0, [r4, #AL_STR]

	mov	r0, r4			// return list
	ldmfd	sp!, {r4, r5, lr}
	mov	pc, lr

al_add:
	stmfd	sp!, {r4, r5, lr}
	mov	r4, r0			// r4 is list
	mov	r5, r1			// r5 is elt

	ldr	r0, [r4, #AL_NEXT]
	ldr	r1, [r4, #AL_CAP]
	cmp	r0, r1
	blt	nogro
	mov	r0, r4
	bl	al_grow

nogro:	ldr	r0, [r4, #AL_STR]
	ldr	r1, [r4, #AL_NEXT]
	str	r5, [r0, r1, lsl #2]	// *** was missing the "lsl #2" here
	add	r1, r1, #1
	str	r1, [r4, #AL_NEXT]

	mov	r0, r1
	ldmfd	sp!, {r4, r5, lr}	// had the wrong register list here
	mov	pc, lr

al_grow:
	stmfd	sp!, {r4, r5, r6, lr}
	mov	r4, r0
	
	ldr	r0, [r4, #AL_CAP]	// r0 = capacity
	mov	r1, #2
	mul	r0, r0, r1 		// r0 = capacity * 2
	str	r0, [r4, #AL_CAP]	// list->cap = list->cap * 2

	// *** I missed this initially, keep forgetting malloc is bytes ***
	mov	r1, #4			// sizeof(int)
	mul	r0, r0, r1		// scale for count of bytes
	bl	malloc			// malloc((list->cap * 2)*sizeof(int))
					// r0 is new_storage
	
	ldr	r5, [r4, #AL_NEXT]	// loop termination value
	ldr	r6, [r4, #AL_STR]	// r6 is base of storage array
	
	mov	r1, #0
L1:	cmp	r1, r5
	bge	EL1

	ldr	r2, [r6, r1, lsl #2]	// r2 = list->storage[i]
	str	r2, [r0, r1, lsl #2]	// new_storage[i] = list->storage[i]
	
	add	r1, r1, #1
	b	L1
	
EL1:	mov	r1, r0			// r1 is new_storage
	mov	r0, r6
	str	r1, [r4, #AL_STR]	// list->storage = new_storage
	bl	free

	ldmfd	sp!, {r4, r5, r6, lr}
	mov	pc, lr
