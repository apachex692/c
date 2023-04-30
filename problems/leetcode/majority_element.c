/*
 * Author: Sakthi Santhosh
 * Created on: 23/09/2022
 *
 * Reference: https://youtu.be/7pnhv842keE
 *
 * Majority Element - Moore's Voting Theorem
 */
#include <stdio.h>

int helper(int *array, int size) {
  int counter1;
  int count = 0;
  int candidate = 0;

  for (counter1 = 0; counter1 < size; counter1++) {
    if (! count) candidate = array[counter1];
    count += ((array[counter1] == candidate) ? 1 : -1);
  }

  for (count = 0, counter1 = 0; counter1 < size; counter1++)
    if (array[counter1] == candidate) count++;

  if (count > size / 2) {
    return candidate;
  } else {
    return -1;
  }
}

int main() {
  int size, counter1;

  printf("Enter size: ");
  scanf("%d", &size);

  int array[size];

  printf("Enter array: ");
  for (counter1 = 0; counter1 < size; counter1++)
    scanf("%d", &array[counter1]);

  printf("\nMajority element: %d\n", helper(array, size));
  return 0;
}
