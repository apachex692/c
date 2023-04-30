/*
 * Author: Sakthi Santhosh
 * Created on: 25/03/2023
 *
 * Median of Two Sorted Arrays
 */
#include <limits.h>
#include <stdio.h>

int min(int a, int b) {
  return (a <= b) ? a : b;
}

int max(int a, int b) {
  return (a >= b) ? a : b;
}

double median(int *array1, int *array2, int size1, int size2) {
  if (size1 > size2)
    return median(array2, array1, size2, size1);

  int array1_lpmax, array1_rpmin, array2_lpmax, array2_rpmin, mid1, mid2;
  int left = 0;
  int right = size1;

  while (left <= right) {
    mid1 = (left + right) / 2;
    mid2 = (size1 + size2 + 1) / 2 - mid1;

    array1_lpmax = (mid1 == 0) ? INT_MIN : array1[mid1 - 1];
    array2_lpmax = (mid2 == 0) ? INT_MIN : array2[mid2 - 1];
    array1_rpmin = (mid1 == size1) ? INT_MAX : array1[mid1];
    array2_rpmin = (mid2 == size2) ? INT_MAX : array2[mid2];

    if (array1_lpmax <= array2_rpmin && array2_lpmax <= array1_rpmin) {
      if ((size1 + size2) % 2) {
        return max(array1_lpmax, array2_lpmax);
      } else {
        return (
          max(array1_lpmax, array2_lpmax)
          + min(array1_rpmin, array2_rpmin)
        ) / 2.0;
      }
    } else if (array1_lpmax > array2_rpmin) {
      right = mid1 - 1;
    } else {
      left = mid1 + 1;
    }
  }
}

int main() {
  int counter1, size1, size2;

  printf("Enter sizes: ");
  scanf("%d %d", &size1, &size2);

  int array1[size1], array2[size2];

  printf("Enter array1: ");
  for (counter1 = 0; counter1 < size1; counter1++)
    scanf("%d", array1 + counter1);

  printf("Enter array2: ");
  for (counter1 = 0; counter1 < size2; counter1++)
    scanf("%d", array2 + counter1);

  printf("\nMedian: %lf\n", median(array1, array2, size1, size2));
  return 0;
}
