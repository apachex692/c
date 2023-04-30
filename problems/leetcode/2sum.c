/*
 * Author: Sakthi Santhosh
 * Created on: 04/12/2022
 *
 * Website: https://leetcode.com/problems/two-sum/
 *
 * Two Sum
 */
#include <stdio.h>

int main() {
  // XXX: Elements range from 1 to 100.
  int size, counter1, counter2, target, map[101];

  printf("Enter size: ");
  scanf("%d", &size);

  int array[size];

  printf("Enter array: ");
  for (counter1 = 0; counter1 < size; counter1++)
    scanf("%d", array + counter1);

  printf("Enter target: ");
  scanf("%d", &target);

  for (counter1 = 0; counter1 < 100; counter1++)
    map[counter1] = -1;

  printf("\nResult: ");
  for (counter1 = 0; counter1 < size; counter1++) {
    map[array[counter1]] = counter1;
    counter2 = target - array[counter1];
    if (counter2 >= 0 && map[counter2] != -1) {
      printf("%d %d\n", counter1, map[counter2]);
      return 0;
    }
  }
  printf("(null)\n");
  return 0;
}
