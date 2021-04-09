#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "array_list.h"

void print1d(int array[], int count) {
  // print out the elements in array from 0 .. count
  int i;
  printf("[ ");
  for(i = 0; i<count -1; i++ ) {
    printf("%d, ", array[i]);
  }
  printf("%d ]", array[i]);
}

int main() {
  srand(time(NULL)); // initialize the PRNG

#ifdef ASM_MODE
  struct array_list *my_list = al_init(5);
#else
  struct array_list *my_list = array_list_init(5);
#endif

  for(int i=0; i<15; i++) {

#ifdef ASM_MODE
    al_add(my_list, (((int)random() % 1000) + 1));
#else
    array_list_add(my_list, (((int)random() % 1000) + 1));
#endif

    print1d(my_list->storage, my_list->next);
    printf("\n");
  }

  return 0;
}
