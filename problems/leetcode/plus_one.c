/*
 * Author: Sakthi Santhosh
 * Created on: 17/12/2022
 *
 * Website: https://leetcode.com/problems/plus-one/
 *
 * Plus One
 */
#include <stdio.h>
#include <stdlib.h>

int *plus_one(int *array, int size) {
  int counter1;

  for (counter1 = size - 1; counter1 > -1; counter1--) {
    if (++array[counter1] == 10) {
      array[counter1] = 0;
    } else {
      return NULL;
    }
  }

  int *result = (int *) malloc(sizeof(int) * (size + 1));

  *result = 1;
  for (counter1 = 1; counter1 <= size; counter1++)
    result[counter1] = array[counter1 - 1];
  return result;
}

int main() {
  int size, counter1;

  printf("Enter size: ");
  scanf("%d", &size);

  int array[size];

  printf("Enter array: ");
  for (counter1 = 0; counter1 < size; counter1++)
    scanf("%d", array + counter1);

  int *result = plus_one(array, size);

  printf("\nResult: ");
  if (result) {
    for (counter1 = 0; counter1 <= size; counter1++)
      printf("%d ", result[counter1]);
    free(result);
  } else {
    for (counter1 = 0; counter1 < size; counter1++)
      printf("%d ", array[counter1]);
  }
  printf("\n");
  return 0;
}
