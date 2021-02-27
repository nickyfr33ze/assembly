#include <stdio.h>

/**
* Check if word is a palindrome
* @param word
* @return 0 iff word is palindrome, nonzero otherwise.
*/
int palindrome(char *word) {
   char *a = word;
   char *b = word;
   while(*(b + 1) != 0) b++;
   while (*a == *b && a < b) {
       a++;
       b--;
   }
   return *a - *b;
}

int main() {
   if (palindrome("racecar") == 0) {
       printf("racecar is a palindrome.\n");
   }
   return 0;
}
