//
// Created by Aaron Benner on 3/31/21.
//

#ifndef INC_20210329_INCLASS_ARRAY_LIST_H
#define INC_20210329_INCLASS_ARRAY_LIST_H

#include <limits.h>

struct array_list {
    int next;       // the index of the "next" free element in the array
    int cap;        // the total capacity of the array
    int *storage;   // array pointer
};

/* this is an example of a conditional block of code. this will only
   be included by the pre-processor if the symbol ASM_MODE is defined
   when the compiler is invoked via -DASM_MODE */
#ifdef ASM_MODE
struct array_list *al_init(int capacity);
int al_add(struct array_list *list, int element);
#endif

/**
 * create an empty array list structure with
 * capacity specified.
 * @param capacity - minimum number of elements that this list
 *                   will hold before it is required to grow
 */
struct array_list *array_list_init(int capacity);

/**
 * Given an element and a list, append the element to the end of the list
 * growing the list capacity as needed.
 * @param list
 * @param element
 * @return the index of the element's location in the list. If there's an error
 *         adding element to list return negative.
 */
int array_list_add(struct array_list *list, int element);

/**
 * Given a list and an index return the value at that index.
 * -- there's a very very real problem with this function.
 * @param list
 * @param index
 * @return
 */
int array_list_get(struct array_list *list, int index);

/**
 * One way to fix the problem. We take an out-only pointer that we are
 * going to use to return the value from the list. On success ok_array_list_get
 * stores the value at list[index] in *out and returns true. On failure
 * it does not modify out and returns false.
 * @param list
 * @param index
 * @param out
 * @return
 */
int ok_array_list_get(struct array_list *list, int index, int *out);

/**
 * Another way to solve the problem. Return the _location_ within list
 * storage of the element at list[index] if it exists. Return NULL otherwise.
 * The danger here is that a location in the list once exported may become
 * invalid when the list's storage is "grown."
 * @param list
 * @param index
 * @return
 */
int * also_ok_array_list_get(struct array_list *list, int index);

/**
 * Given a list and an index remove the value at that index. Return the value removed
 * -- same very very real problem here.
 * @param list
 * @param index
 * @return
 */
int array_list_remove(struct array_list *list, int index);

#endif //INC_20210329_INCLASS_ARRAY_LIST_H
