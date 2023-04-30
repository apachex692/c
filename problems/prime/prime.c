/*
 * Author: Sakthi Santhosh
 * Created on: 17/09/2022
 *
 * Prime Number Checker
*/
#include <stdio.h>
#include <math.h>

int isprime(int number) {
  if (number < 2) return 0;

  int counter1;

  for (counter1 = 2; counter1 <= (int) sqrt(number); counter1++)
    if (number % counter1 == 0) return 0;
  return 1;
}

int main() {
  int number;

  printf("Enter number: ");
  scanf("%d", &number);

  printf("\nPrime: %d\n", isprime(number));
  return 0;
}
