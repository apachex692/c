/*
 * Author: Sakthi Santhosh
 * Created on: 11/10/2022
 *
 * Pendulum Problem
 */
#include <stdio.h>
#include <stdlib.h>

int comparator(const void *value1, const void *value2) {
  return (*(int *) value2 - *(int *) value1);
}

int main() {
  int size, counter1;

  printf("Enter size: ");
  scanf("%d", &size);

  int array[size];
  int start = 0;
  int end = size - 1;

  printf("Enter elements: ");
  for (counter1 = 0; counter1 < size; counter1++) {
    scanf("%d", array + counter1);
  }

  printf("\nResult: ");
  qsort(array, size, sizeof(int), comparator);
  while (start < end) {
    printf("(%d %d) ", array[start++], array[end--]);
  }
  if (size % 2) printf("%d", array[start]);
  printf("\n");
  return 0;
}
