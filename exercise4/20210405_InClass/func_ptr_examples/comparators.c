//
// Created by Aaron Benner on 4/5/21.
//

#include <string.h>
#include "comparators.h"


int compare_int(void *a, void *b) {
    // type a and b
    int *p_a = (int *)a;
    int *p_b = (int *)b;

    // perform the comparison, if these were complex structures this is where we'd implement the logic
    // for comparing them.
    return *p_a - *p_b;
}


int compare_float(void *a, void *b) {
    float *p_a = (float*)a;
    float *p_b = (float*)b;

    return *p_a - *p_b;
}



int compare_string(void *a, void *b) {
    char *p_a = (char *)a;
    char *p_b = (char *)b;

    return strcmp(a,b);
}