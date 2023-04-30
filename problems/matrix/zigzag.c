/*
 * Author: Sakthi Santhosh
 * Created on: 27/04/2023
 *
 * Matrix Zig-Zag Pattern Printer
 */
#include <stdio.h>

int main() {
  int size, counter1, counter2;
  int direction = 1;

  printf("Enter size: ");
  scanf("%d", &size);

  int matrix[size][size];

  printf("Enter matrix: ");
  for (counter1 = 0; counter1 < size; counter1++)
    for (counter2 = 0; counter2 < size; counter2++)
      scanf("%d", *(matrix + counter1) + counter2);

  for (counter1 = 3; counter1 >= 0; counter1--) {
    if (direction) {

    }
  }
  return 0;
}
