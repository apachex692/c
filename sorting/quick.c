/*
 * Author: Sakthi Santhosh
 * Created on: 15/11/2022
 *
 * Quick Sort
 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int *array, size; // Global declaration to save space during recursion.

void swap(int *x, int *y) {
  int temp = *x;
  *x = *y;
  *y = temp;
}

int partition(int start, int end) {
  int counter1, counter2;
  int pivot_index = start + rand() % (end - start); // Randomizing pivot index improves efficiency.

  if (pivot_index != end)
    swap(&array[pivot_index], &array[end]);

  for (counter1 = start, counter2 = start; counter2 < end; counter2++)
    if (array[counter2] <= array[end]) { // array[end] is the pivot value.
      swap(&array[counter2], &array[counter1]);
      counter1++;
    }
  swap(&array[counter1], &array[end]);
  return counter1;
}

void quick_sort(int start, int end) {
  if (start < end) {
    int pivot_index = partition(start, end);

    quick_sort(start, pivot_index - 1);
    quick_sort(pivot_index + 1, end);
  }
}

int main() {
  int size, counter1;

  printf("Enter size: ");
  scanf("%d", &size);

  printf("Enter array: ");
  array = (int *) malloc(sizeof(int) * size);
  for (counter1 = 0; counter1 < size; counter1++)
    scanf("%d", &array[counter1]);

  srand(time(NULL)); // Set seed for rand().

  printf("\nSorted array: ");
  quick_sort(0, size - 1);
  for (counter1 = 0; counter1 < size; counter1++)
    printf("%d ", array[counter1]);
  printf("\n");
  free(array);
  return 0;
}
