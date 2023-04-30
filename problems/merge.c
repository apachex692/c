/*
 * Author: Sakthi Santhosh
 * Created on: 21/07/2022
 *
 * Reference: https://www.youtube.com/6pV2IF0fgKY
 *
 * Two Way Merge
 */
#include <stdio.h>
#include <stdlib.h>

int *two_way_merge(int *array_1, int *array_2, int size1, int size2) {
  int *result = (int *) malloc(sizeof(int) *(size1 + size2));
  int counter1 = 0;
  int counter2 = 0;
  int counter3 = 0;

  while (counter1 < size1 && counter2 < size2) {
    if (array_1[counter1] <= array_2[counter2]) {
      result[counter3] = array_1[counter1++];
    } else {
      result[counter3] = array_2[counter2++];
    }
    counter3++;
  }
  // Merge remaining elements.
  while (counter1 < size1)
    result[counter3++] = array_1[counter1++];
  while (counter2 < size2)
    result[counter3++] = array_2[counter2++];
  return result;
}

int main() {
  int counter1, size1, size2;

  printf("Enter sizes: ");
  scanf("%d %d", & size1, & size2);

  int array_1[size1], array_2[size2];

  printf("Enter array-1: ");
  for (counter1 = 0; counter1 < size1; counter1++)
    scanf("%d", & array_1[counter1]);
  printf("Enter array-2: ");
  for (counter1 = 0; counter1 < size2; counter1++)
    scanf("%d", & array_2[counter1]);

  int *result = two_way_merge(array_1, array_2, size1, size2);

  printf("\nMerged array: ");
  for (counter1 = 0; counter1 < size1 + size2; counter1++)
    printf("%d ", result[counter1]);
  printf("\n");
  free(result);
  return 0;
}
