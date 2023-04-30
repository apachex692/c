/*
 * Author: Sakthi Santhosh
 * Created on: 05/10/2022
 *
 * GCD of Two Numbers
 */
#include <stdio.h>

int gcd(int number1, int number2) {
  if (!number1) return number2;
  if (!number2) return number1;

  int counter1;
  int smallest = (number1 < number2) ? number1 : number2;

  if (number1 % smallest == 0 && number2 % smallest == 0) return smallest;

  for (counter1 = smallest / 2; counter1; counter1--)
      if (
        number1 % counter1 == 0 &&
        number2 % counter1 == 0) return counter1;
}

int main() {
  int number1, number2;

  printf("Enter two numbers: ");
  scanf("%d %d", &number1, &number2);

  printf("\nGCD: %d\n", gcd(number1, number2));
  return 0;
}
