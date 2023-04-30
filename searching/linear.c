/*
 * Author: Sakthi Santhosh
 * Created on: 24/09/2022
 *
 * Linear Search Implementation
 */
#include <stdio.h>

int search(int *array, int size, int key) {
  int counter1;

  for (counter1 = 0; counter1 < size; counter1++)
    if (array[counter1] == key) return counter1;
  return -1;
}

int main() {
  int size, counter1, key;

  printf("Enter size: ");
  scanf("%d", &size);

  int array[size];

  printf("Enter array: ");
  for (counter1 = 0; counter1 < size; counter1++)
    scanf("%d", &array[counter1]);

  printf("Enter key: ");
  scanf("%d", &key);

  printf("\nSearch: %d\n", search(array, size, key));
  return 0;
}
