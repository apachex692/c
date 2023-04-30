/*
 * Author: Sakthi Santhosh
 * Created on: 05/10/2022
 *
 * GCD of N Numbers
 */
#include <stdio.h>
#include <limits.h>

// Returns the smallest number in an array except zero.
int helper(int *array, int size) {
  int smallest = INT_MAX;
  int counter1 = 0;

  while (counter1 < size) {
    if (array[counter1] && array[counter1] < smallest)
      smallest = array[counter1];
    counter1++;
  }
  return smallest;
}

int gcd(int *array, int size) {
  int counter1;
  int smallest = helper(array, size);

  if (smallest == INT_MAX) return 0;

  for (counter1 = 0; counter1 < size; counter1++)
    if (array[counter1] % smallest) break;
  if (counter1 == size) return smallest;

  int counter2;

  for (counter1 = smallest / 2; counter1; counter1--) {
    for (counter2 = 0; counter2 < size; counter2++)
      if (array[counter2] % counter1) break;
    if (counter2 == size) return counter1;
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

  printf("\nGCD: %d\n", gcd(array, size));
  return 0;
}
