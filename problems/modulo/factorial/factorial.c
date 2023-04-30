/*
 * Author: Sakthi Santhosh
 * Created on: 05/10/2022
 *
 * Reference: https://youtu.be/-OPohCQqi_E
 *
 * Factorial Under Modulo-N
 */
#include <stdio.h>

int main() {
  int number, modulo;
  int fact_modulo = 1;

  printf("Enter number & modulo: ");
  scanf("%d %d", &number, &modulo);

  while (number && fact_modulo) {
    fact_modulo = (fact_modulo * number) % modulo;
    number--;
  }
  printf("\nResult: %d\n", fact_modulo);
  return 0;
}
