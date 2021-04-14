#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "array_list.h"

void print1d(int array[]) { // now only passes one variable due to the modification in 'array_list.c'
  // print out the elements in array from 0 .. count
  int i;
  printf("[ ");
  /*   NOW NOT NEEDED DUE TO 'count' NO LONGER BEING PART OF THE FUNCTION
   * for(i = 0; i<count -1; i++ ) {
   *  printf("%d, ", array[i]);
   * }
   */
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

    print1d(my_list->storage); // took away the second variable due to the 'print1d' 
                               // function being modifed to only get passed one variable
    printf("#### Now going to remove 2 indexes. ####"); // visual prompt to the user of what is happening on cli
    array_list_remove(my_list->storage, 2); // removes the 3rd index of 'my_list'
    array_list_remove(my_list->storage, 3); // removes the 4th index of 'my_list'
    print1d(my_list->storage); // prints the array a second time to prove the 
                               // remove function worked.
    printf("\n");
  }

  return 0;
}
