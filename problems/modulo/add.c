/*
 * Author: Sakthi Santhosh
 * Created on: 05/10/2022
 *
 * Reference: https://youtu.be/-OPohCQqi_E
 *
 * Addition Under Modulo-N
 */

#include <stdio.h>

int main() {
  int number1, number2, modulo;

  printf("Enter two numbers: ");
  scanf("%d %d", &number1, &number2);

  printf("Enter modulo: ");
  scanf("%d", &modulo);

  printf("\nResult: %d", number1 % modulo + number2 % modulo);
  return 0;
}
