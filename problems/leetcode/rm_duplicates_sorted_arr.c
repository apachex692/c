/*
 * Author: Sakthi Santhosh
 * Created on: 16/12/2022
 *
 * Website: https://leetcode.com/problems/remove-duplicates-from-sorted-array/
 *
 * Remove Duplicates from Sorted Array
 */
#include <stdio.h>

int rm_duplicates(int *array, int size) {
  int counter1, counter2;

  for (counter1 = 1, counter2 = 1; counter1 < size; counter1++)
    if (array[counter1] != array[counter1 - 1])
      array[counter2++] = array[counter1];
  return counter2;
}

int main() {
  int size, counter1;

  printf("Enter size: ");
  scanf("%d", &size);

  int array[size];

  printf("Enter array (sorted): ");
  for (counter1 = 0; counter1 < size; counter1++)
      scanf("%d", array + counter1);

  size = rm_duplicates(array, size);
  printf("\nResult: ");
  for (counter1 = 0; counter1 < size; counter1++)
    printf("%d ", array[counter1]);
  printf("\n");
  return 0;
}
