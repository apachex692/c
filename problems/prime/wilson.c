/*
 * Author: Sakthi Santhosh
 * Created on: 05/10/2022
 *
 * Prime Number Checker - Wilson Theorem
*/
#include <stdio.h>
#include <stdint.h>

int isprime(int number) {
  if (number < 2) return 0;

  int counter1;
  uint64_t factorial = 1;

  for (
    counter1 = number;
    counter1 > 1;
    counter1--, factorial *= counter1
  );
  return (factorial + 1) % number == 0;
}

// XXX: Implementation works only upto number < 23.
int main() {
  int number;

  printf("Enter number: ");
  scanf("%d", &number);

  printf("\nPrime: %d\n", isprime(number));
  return 0;
}
