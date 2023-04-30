/*
 * Author: Sakthi Santhosh
 * Created on: 24/01/2023
 *
 * Website: https://leetcode.com/problems/maximum-subarray/
 *
 * Maximum Subarray (Kadane's Algorithm)
 */
#include <limits.h>
#include <stdio.h>

int main() {
  int size, counter1;
  int maximum = INT_MIN;
  int sum = 0;

  printf("Enter size: ");
  scanf("%d", &size);

  int array[size];

  printf("Enter array: ");
  for (counter1 = 0; counter1 < size; counter1++)
    scanf("%d", array + counter1);

  for (counter1 = 0; counter1 < size; counter1++) {
    sum += array[counter1];
    if (sum > maximum) maximum = sum;
    if (sum < 0) sum = 0;
  }
  printf("\nMax subarray sum: %d\n", maximum);
  return 0;
}
