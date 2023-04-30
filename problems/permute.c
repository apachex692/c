/*
 * Author: Sakthi Santhosh
 * Created on: 10/10/2022
 *
 * Permutation of String
 */
#include <stdio.h>
#include <string.h>

void swap(char *char1, char *char2) {
  char temp;

  temp = *char1;
  *char1 = *char2;
  *char2 = temp;
}

void permute(char *string, int start, int end) {
  if (start == end) {
    printf("  %s\n", string);
  } else {
    for (int counter1 = start; counter1 <= end; counter1++) {
      swap(string + start, string + counter1);
      permute(string, start + 1, end);
      swap(string + start, string + counter1);
    }
  }
}

int main() {
  char string[10];

  printf("Enter string: ");
  scanf("%s", string);

  printf("\nPermutations:\n");
  permute(string, 0, strlen(string) - 1);
  return 0;
}
