/*
 * Author: Sakthi Santhosh
 * Created on: 07/09/2022
 *
 * GCD Recursive (Euclidian Method)
 */
#include <stdio.h>
#include <stdlib.h>

int gcd(int value1, int value2) {
  if (!value2)
    return value1;

  return gcd(value2, value1 % value2);
}

int main() {
  int value1, value2;

  printf("Enter values: ");
  scanf("%d %d", &value1, &value2);

  printf("GCD: %d\n", gcd(value1, value2));
  return 0;
}
