/*
 * Author: Sakthi Santhosh
 * Created on: 26/02/2023
 *
 * Print Matrix Zig-Zag
*/
#include <stdio.h>

int main() {
  int size, counter1, counter2;
  int value = 1;
  int increment = 1;

  printf("Enter size: ");
  scanf("%d", &size);

  printf("\nResult:\n");
  for (counter1 = 0; counter1 < size; counter1++) {
    printf("  ");
    for (counter2 = 0; counter2 < size; counter2++) {
      printf("%d ", value);
      value += increment;
    }
    if (counter1 % 2) {
      value += size + 1;
      increment = 1;
    } else {
      value += size - 1;
      increment = -1;
    }
    printf("\n");
  }
  return 0;
}
