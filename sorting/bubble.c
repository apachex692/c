/*
 * Author: Sakthi Santhosh
 * Created on: 21/07/2022
 *
 * Bubble Sort
 */
#include <stdio.h>
#include <stdlib.h>

void bubble_sort(int *array, int size) {
  int counter1, counter2, temp;
  short is_swapped;

  for (counter1 = 0; counter1 < size; counter1++) {
    is_swapped = 0;
    for (counter2 = 0; counter2 < size - counter1 - 1; counter2++) {
      if (array[counter2] > array[counter2 + 1]) {
        temp = array[counter2];
        array[counter2] = array[counter2 + 1];
        array[counter2 + 1] = temp;
        is_swapped = 1;
      }
    }
    if (!is_swapped) break;
  }
}

int main() {
  int size, counter1;

  printf("Enter size: ");
  scanf("%d", &size);

  int array[size];

  printf("Enter array: ");
  for (counter1 = 0; counter1 < size; counter1++)
    scanf("%d", &array[counter1]);

  printf("\nSorted array: ");
  bubble_sort(array, size);
  for (counter1 = 0; counter1 < size; counter1++)
    printf("%d ", array[counter1]);
  printf("\n");
  return 0;
}
