/*
 * Auhor: Sakthi Santhosh
 * Created on: 21/07/2022
 *
 * Selection Sort
 */
#include <stdio.h>
#include <stdlib.h>

void selection_sort(int *array, int size) {
  int counter1, counter2, min_index, temp;

  for (counter1 = 0; counter1 < size - 1; counter1++) {
    min_index = counter1;
    for (counter2 = counter1 + 1; counter2 < size; counter2++)
      if (array[counter2] < array[min_index])
        min_index = counter2;
    if (min_index != counter1) {
      temp = array[counter1];
      array[counter1] = array[min_index];
      array[min_index] = temp;
    }
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
  selection_sort(array, size);
  for (counter1 = 0; counter1 < size; counter1++)
    printf("%d ", array[counter1]);
  printf("\n");
  return 0;
}
