/*
 * Author: Sakthi Santhosh
 * Created on: 21/07/2022
 *
 * Insertion Sort
 */
#include <stdio.h>
#include <stdlib.h>

void insertion_sort(int *array, int size) {
  int counter1, counter2, key;

  for (counter1 = 1; counter1 < size; counter1++) {
    key = array[counter1];
    for (counter2 = counter1 - 1; counter2 > -1 && array[counter2] > key; counter2--)
      array[counter2 + 1] = array[counter2];
    array[counter2 + 1] = key;
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
  insertion_sort(array, size);
  for (counter1 = 0; counter1 < size; counter1++)
    printf("%d ", array[counter1]);
  printf("\n");
  return 0;
}
