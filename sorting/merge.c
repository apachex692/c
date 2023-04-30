/*
 * Author: Sakthi Santhosh
 * Created on: 21/07/2022
 *
 * Merge Sort
 */
#include <stdio.h>
#include <stdlib.h>

int *array; // Global declaration to save space during recursion.

void merge(int start, int mid, int end) {
  int counter1, counter2, counter3;
  int left_array[mid - start + 1];
  int right_array[end - mid];

  for (counter1 = 0; counter1 <= mid - start; counter1++)
    left_array[counter1] = array[start + counter1];
  for (counter1 = 0; counter1 < end - mid; counter1++)
    right_array[counter1] = array[mid + counter1 + 1];

  counter1 = start;
  counter2 = 0;
  counter3 = 0;
  while (counter2 <= mid - start && counter3 < end - mid) {
    if (left_array[counter2] <= right_array[counter3]) {
      array[counter1] = left_array[counter2++];
    } else {
      array[counter1] = right_array[counter3++];
    }
    counter1++;
  }
  while (counter2 <= mid - start)
    array[counter1++] = left_array[counter2++];
  while (counter3 < end - mid)
    array[counter1++] = right_array[counter3++];
}

void merge_sort(int start, int end) {
  if (start < end) {
    int mid = start + (end - start) / 2;

    merge_sort(start, mid);
    merge_sort(mid + 1, end);
    merge(start, mid, end);
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

  printf("\nSorted array: ");
  merge_sort(0, size - 1);
  for (counter1 = 0; counter1 < size; counter1++)
    printf("%d ", array[counter1]);
  printf("\n");
  free(array);
  return 0;
}
