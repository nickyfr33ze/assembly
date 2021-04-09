//
// Created by Aaron Benner on 4/5/21.
//
#include "pretty_print.h"

// pretty print a 1d array
void print_int_array(int *array, int len, int nl) {
    printf("[ ");
    int i;
    for(i=0; i<len-1; i++) {
        printf("%d, ", array[i]);
    }
    printf("%d ]", array[i]);
    if(nl != 0) {
        printf("\n");
    }
}

void print_float_array(float *array, int len, int nl) {
    printf("[ ");
    int i;
    for(i=0; i<len-1; i++) {
        printf("%.05f, ", array[i]);
    }
    printf("%.05f ]", array[i]);
    if(nl != 0) {
        printf("\n");
    }
}
