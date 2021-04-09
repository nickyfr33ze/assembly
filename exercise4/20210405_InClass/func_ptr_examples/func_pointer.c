//
// Created by Aaron Benner on 4/5/21.
//

#include "func_pointer.h"
#include <string.h>
#include <stdio.h>

void swap(void *a, void *b, size_t width) {
    void *temp = malloc(width);
    memcpy(temp, a, width);
    memcpy(a, b, width);
    memcpy(b, temp, width);
    free(temp);
}

void insertion_sort_array_with_comparator(void *base, size_t num_elt, size_t width, int (*comp)(void *a, void *b)) {
    void *temp = malloc(width);  // the element currently being inserted
    void *i;                     // an index into the array, marks the bounds between sorted / not
    void *j;                     // an index into the array, used to find insertion point
    for(i=(base + width); i < (base + (width * num_elt)); i+=width) {
        memcpy(temp, i, width);
        for(j = (i - width); j >= base && (comp(j, temp)) > 0; j -= width) {
            swap(j, (j + width), width);
        }
        swap((j + width), temp, width);
    }
}