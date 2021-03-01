/* 
Need to write out structure

What you need:
- A cluster of chars (a string)
- Pass that into a function that will determine if palindrome
- Pass 'palindrome' into a main function
  - Make sure main() returns a true or false

*/ 
        .data
arry1:  .word   1,2,3,4,5
str1:   .asciz  "MADAM"
arry2:  .skip   80      @20 element array

        @ r0 = *word    // M
        @ r1 = *word    // A
        @ r2 = *word    // D
        @ r3 = *word    // A
        @ r4 = *word    // M
        @ r5 = word     //"MADAM str
        @ r6 = word     //"MADAM str
        @ r8 = i        //pointer 1
        @ r9 = i        //pointer 2

main:   ldr r5, [r0,r1,r2,r3,r4]        //stores r0 -> r4 into r5
        ldr r6, r5                      //stores r5 into r6

loop1:  cmp r0, r4
        bge end1OA

