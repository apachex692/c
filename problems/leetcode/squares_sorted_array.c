/*
 * Author: Sakthi Santhosh
 * Created on: 24/01/2023
 *
 * Website: https://leetcode.com/problems/squares-of-a-sorted-array
 *
 * Squares of a Sorted Array
 */
#include <stdio.h>
#include <stdlib.h>

int main() {
  int size, counter1, start, end;

  printf("Enter size: ");
  scanf("%d", &size);

  int array[size], result[size];

  printf("Enter array: ");
  for (counter1 = 0; counter1 < size; counter1++)
    scanf("%d", array + counter1);

  for (
    start = 0, end = size - 1, counter1 = size - 1;
    counter1 >= 0;
    counter1--
  ) {
    if (abs(array[start]) > abs(array[end])) {
      result[counter1] = array[start] * array[start++];
    } else {
      result[counter1] = array[end] * array[end--];
    }
  }

  printf("\nResult: ");
  for (counter1 = 0; counter1 < size; counter1++) {
    printf("%d ", result[counter1]);
  }
  printf("\n");
  return 0;
}
