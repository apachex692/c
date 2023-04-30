/*
 * Author: Sakthi Santhosh
 * Created on: 24/09/2022
 *
 * Binary Search Implementation
 */
#include <stdio.h>

int search(int *array, int size, int key) {
  int start = 0;
  int end = size - 1;
  int mid;

  while (start <= end) {
    mid = start + (end - start) / 2; // Prevents integer overflow.
    if (array[mid] == key) {
      return mid;
    } else if (array[mid] < key) {
      start = mid + 1;
    } else {
      end = mid - 1;
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
