/*
 * Author: Sakthi Santhosh
 * Created on: 11/10/2022
 *
 * Reference: https://youtu.be/uCsD3ZGzMgE
 *
 * Josephus Problem Special Case - Step Size 2
 */
#include <stdio.h>
#include <math.h>

int main() {
  int size;

  printf("Enter size: ");
  scanf("%d", &size);

  printf("\nResult: %d\n", 2 * (size - (int) pow(2, (int) log2(size))) + 1);
  return 0;
}
