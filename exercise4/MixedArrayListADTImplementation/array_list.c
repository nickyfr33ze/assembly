#include <stdlib.h>
#include <stdio.h>
#include "array_list.h"

#ifdef ASM_MODE
void al_grow(struct array_list *list); // defined in array_list.s
#endif

/**
 * "private" method to increase the capacity of a list. By excluding this
 * function from the .h file it's signature is less visible to other
 * parts of the program.
 * grow_list will double the capacity of the underlying array and
 * then copy all elements from the old array to the new
 * array. It returns
 * @param list
 */
void grow_list(struct array_list *list) {
  list->cap = list->cap * 2;
  int *new_storage = (int*) malloc((size_t)(sizeof(int) * list->cap));
  for(int i=0; i<list->next; i++) {
    new_storage[i] = list->storage[i];
  }
  free(list->storage);
  list->storage = new_storage;
}

struct array_list *array_list_init(int capacity) {
  struct array_list *list = (struct array_list*)malloc((size_t)(sizeof(struct array_list)));
  list->next=0;
  list->cap=capacity;
  list->storage = (int*)malloc((size_t)(sizeof(int) * list->cap));
  return list;
}

int array_list_add(struct array_list *list, int element) {
  if(list->next >= list->cap) {
    printf("growing list\n");
    grow_list(list);
  }

  list->storage[list->next++] = element;
  return list->next - 1;
}

int array_list_get(struct array_list *list, int index) {
  if(list->next < index && index >= 0) {
    return list->storage[index];
  }

  // uh-oh, what do we return here???
  return INT_MAX;
}

int ok_array_list_get(struct array_list *list, int index, int *out) {
  if(list->next < index && index >= 0) {
    *out = list->storage[index];
    return index;
  }

  return 0;
}

int * also_ok_array_list_get(struct array_list *list, int index) {
  if(list->next < index && index >= 0) {
    return &list->storage[index];
  }
  return NULL;
}

// technically better if we return the element that's been removed,
// but here we're going to go with the number of elements remaining
int array_list_remove(struct array_list *list, int index) {
  if(list->next < index && index >= 0) {
    for(int i=index+1; i<list->next; i++) {
      list->storage[i-1] = list->storage[i];
    }
    return --list->next;
  }

  return 0;
}
