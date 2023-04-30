/*
 * Author: Sakthi Santhosh
 * Created on: 04/03/2023
 *
 * Website: https://leetcode.com/problems/3sum/
 *
 * 3Sum
 */
#include <stdio.h>
#include <stdlib.h>

#define MAX_TRIPLETS 5

int comparator(const void *value1, const void *value2) {
  return (*(int *) value1 - *(int *) value2);
}

void add_triplet(int **triplets, int *size, int a, int b, int c) {
  *(triplets + *size) = (int *) malloc(sizeof(int) * 3);
  **(triplets + *size) = a;
  *(*(triplets + *size) + 1) = b;
  *(*(triplets + *size) + 2) = c;
  (*size)++;
}

void exit_handler(int **triplets, int size) {
  for (int counter1 = 0; counter1 < size; counter1++)
    free(*(triplets + counter1));
}

int main() {
  int size, counter1, left, right;
  int *triplets[MAX_TRIPLETS];
  int tsize = 0;

  printf("Enter size: ");
  scanf("%d", &size);

  if (size < 3) {
    printf("\n\033[31;01mError:\033[00m Minimum size or array must be 3.\n");
    return 1;
  }

  int array[size];

  printf("Enter array: ");
  for (counter1 = 0; counter1 < size; counter1++)
    scanf("%d", array + counter1);

  qsort(array, size, sizeof(int), comparator);

  for (counter1 = 0; counter1 < size - 2; counter1++) {
    if (counter1 && array[counter1] == array[counter1 - 1])
      continue;

    left = counter1 + 1;
    right = size - 1;
    while (left < right) {
      if (array[counter1] + array[left] + array[right] == 0) {
        if (tsize >= MAX_TRIPLETS) {
          printf("\n\033[31;01mError:\033[00m Overflow detected, aborting program.\n");
          exit_handler(triplets, size);
          return 1;
        }

        add_triplet(triplets, &tsize, array[counter1], array[left], array[right]);
        left++;
        while (array[left] == array[left - 1] && left < right) left++;
      } else if (array[counter1] + array[left] + array[right] < 0) {
        left++;
      } else {
        right--;
      }
    }
  }

  printf("\nTriplets:\n");
  for (counter1 = 0; counter1 < tsize; counter1++) {
    printf("  %d %d %d\n",
      *(*(triplets + counter1)),
      *(*(triplets + counter1) + 1),
      *(*(triplets + counter1) + 2)
    );
  }
  exit_handler(triplets, tsize);
  return 0;
}
