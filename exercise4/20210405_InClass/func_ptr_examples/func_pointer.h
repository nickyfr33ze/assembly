//
// Created by Aaron Benner on 4/5/21.
//
#include <stdlib.h>

#ifndef INC_20210405_INCLASS_FUNC_POINTER_H
#define INC_20210405_INCLASS_FUNC_POINTER_H

/**
 * Given an array of num_elts=(high - low) sort them using the insertion sort algorithm based on the
 * natural ordering function (comp)
 *
 * @param base   - the address of the first element of the array
 * @param width  - the number of bytes each element consists of
 * @param low    - the starting index for sorting
 * @param high   - the (exclusive) end of the sorting range
 * @param comp   - a comparator function that defines the natural ordering of elements
 */
void insertion_sort_array_with_comparator(void *base, size_t num_elt, size_t width, int (*comp)(void *a, void *b));

#endif //INC_20210405_INCLASS_FUNC_POINTER_H
