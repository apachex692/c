/*
 * Author: Sakthi Santhosh
 * Created on: 24/01/2023
 *
 * Website: https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/
 *
 * Two Sum II - Input Array Is Sorted
 */
#include <stdio.h>

int main() {
  int size, counter1, counter2, target;

  printf("Enter size: ");
  scanf("%d", &size);

  int array[size];

  printf("Enter array: ");
  for (counter1 = 0; counter1 < size; counter1++)
    scanf("%d", array + counter1);

  printf("Enter target: ");
  scanf("%d", &target);

  printf("\nResult: ");
  for (counter1 = 0, counter2 = size - 1; counter1 < counter2; ) {
    if (array[counter1] + array[counter2] == target) {
      printf("%d %d\n", counter1, counter2);
      return 0;
    } else if (array[counter1] + array[counter2] > target) {
      counter2--;
    } else {
      counter1++;
    }
  }
  printf("(null)\n");
  return 0;
}
