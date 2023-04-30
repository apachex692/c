/*
 * Author: Sakthi Santhosh
 * Created on: 07/09/2022
 *
 * GCD Recursive - Euclidian Method
 */
#include <stdio.h>
#include <stdlib.h>

int gcd(int number1, int number2) {
  if (!number2) return number1;

  return gcd(number2, number1 % number2);
}

int main() {
  int number1, number2;

  printf("Enter two numbers: ");
  scanf("%d %d", &number1, &number2);

  printf("\nGCD: %d\n", gcd(number1, number2));
  return 0;
}
