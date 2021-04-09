#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "func_ptr_examples/func_pointer.h"
#include "func_ptr_examples/comparators.h"
#include "pretty_print.h"

// below is an implementation of the simple insertion sort algorithm
// that will allow us to sort an array of integer values.
void insertion_sort(int *array, int low, int high) {
    int temp;

    for(int i=(low + 1); i<high; i++) {
        temp=array[i];
        int j;
        for(j=i-1; j>=low && array[j] > temp; j--) {
            array[j+1] = array[j];
        }
        array[j+1] = temp;
    }
}

int main() {
    srandom(time(NULL)); // initialize the PRNG

    int array[15];
    for(int i=0; i<15; i++) {
        array[i] = (((int)random() % 1000) + 1);
    }

    printf("before sort:");
    print_int_array(array, 15, 1);
    //insertion_sort(array, 0, 15);
    insertion_sort_array_with_comparator(array, 15, sizeof(int), compare_int);
    printf("after sort:");
    print_int_array(array, 15, 1);

    float farray[15];
    for(int i=0; i<15; i++) {
        farray[i] = (float) (((double)random() / (double)RAND_MAX) * 1000.0);
    }

    printf("before sort:");
    print_float_array(farray, 15, 1);
    //insertion_sort(farray, 0, 15);
    insertion_sort_array_with_comparator(farray, 15, sizeof(float), compare_float);
    printf("after sort:");
    print_float_array(farray, 15, 1);
}