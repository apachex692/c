/*
 * Author: Sakthi Santhosh
 * Created on: 11/10/2022
 *
 * Reference: https://youtu.be/fZ3p2Iw-O2I
 *
 * Josephus Problem
 */
#include <stdio.h>

int josephus(int size, int step) {
  if (size == 1) return 0;

  return (josephus(size - 1, step) + step) % size;
}

int main() {
  int size, step;

  printf("Enter size: ");
  scanf("%d", &size);

  printf("Enter step: ");
  scanf("%d", &step);

  printf("\nResult: %d\n", josephus(size, step) + 1);
  return 0;
}
