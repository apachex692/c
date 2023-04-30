/*
 * Author: Sakthi Santhosh
 * Created on: 17/09/2022
 *
 * Prime Number Checker
*/
#include <stdio.h>
#include <math.h>

int main() {
  int number, counter1;
  int flag = 1;

  printf("Enter number: ");
  scanf("%d", &number);

  for (counter1 = 2; counter1 <= (int) sqrt(number); counter1++)
    if (number % counter1 == 0) {
      flag = 0;
      break;
    }
  printf("\nPrime: %d\n", flag);
  return 0;
}
