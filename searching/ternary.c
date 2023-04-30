/*
 * Author: Sakthi Santhosh
 * Created on: 24/09/2022
 *
 * Ternary Search Implementation
 */
#include <stdio.h>

int search(int *array, int size, int key) {
  int start = 0;
  int end = size - 1;
  int mid1, mid2;

  while (start <= end) {
    mid1 = start + (end - start) / 3;
    mid2 = end - (end - start) / 3;
    if (array[mid1] == key) {
      return mid1;
    } else if (array[mid2] == key) {
      return mid2;
    } else if (array[mid1] > key) {
      end = mid1 - 1;
    } else if (array[mid2] < key) {
      start = mid2 + 1;
    } else {
      start = mid1 + 1;
      end = mid2 - 1;
    }
  }
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
