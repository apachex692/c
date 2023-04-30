/*
 * Author: Sakthi Santhosh
 * Created on: 16/11/2022
 *
 * Radix Sort
 */
#include <stdio.h>
#include <stdlib.h>

int *array, size;

void helper(int place) { // Modified implementation of count sort.
  int counter1, result[size];
  int largest = 0;

  for (counter1 = 0; counter1 < size; counter1++)
    if ((array[counter1] / place) % 10 > largest)
      largest = (array[counter1] / place) % 10;

  int count_map[largest + 1];

  for (counter1 = 0; counter1 <= largest; counter1++)
    count_map[counter1] = 0;

  for (counter1 = 0; counter1 < size; counter1++)
    count_map[(array[counter1] / place) % 10]++;
  for (counter1 = 1; counter1 <= largest; counter1++)
    count_map[counter1] += count_map[counter1 - 1];

  for (counter1 = size - 1; counter1 >= 0; counter1--) // Reversed for stability.
    result[--count_map[(array[counter1] / place) % 10]] = array[counter1];

  for (counter1 = 0; counter1 < size; counter1++)
    array[counter1] = result[counter1];
}

void radix_sort() {
  int counter1;
  int largest = array[0];
  int place = 10;

  for (largest = array[0], counter1 = 1; counter1 < size; counter1++)
    if (array[counter1] > largest) largest = array[counter1];

  for (place = 10; largest / place > 0; place *= 10) helper(place);
}

int main() {
  int counter1;

  printf("Enter size: ");
  scanf("%d", &size);

  printf("Enter array: ");
  array = (int *) malloc(sizeof(int) * size);
  for (counter1 = 0; counter1 < size; counter1++)
    scanf("%d", &array[counter1]);

  printf("\nSorted array: ");
  radix_sort(array, size);
  for (counter1 = 0; counter1 < size; counter1++)
    printf("%d ", array[counter1]);
  printf("\n");
  free(array);
  return 0;
}
