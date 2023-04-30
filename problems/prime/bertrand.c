/*
 * Author: Sakthi Santhosh
 * Created on: 05/10/2022
 *
 * Prime Number Checker - Bertrand's Postulate
*/
#include <stdio.h>

int isprime(int number) {
  if (number < 2) return 0;
  if (number < 4) return 1;
  if (number % 2 == 0 || number % 3 == 0) return 0;

  int counter1;

  for (counter1 = 5; counter1 * counter1 <= number; counter1 += 6)
    if (number % counter1 == 0 || number % (counter1 + 2) == 0) return 0;
  return 1;
}

int main() {
  int number;

  printf("Enter number: ");
  scanf("%d", &number);

  printf("\nPrime: %d\n", isprime(number));
  return 0;
}
