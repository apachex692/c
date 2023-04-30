/*
 * Author: Sakthi Santhosh
 * Created on: 09/10/2022
 *
 * Fermat's Primality Test
 */
#include <stdio.h>

#define SAMPLE_SIZE 20

int isprime(int number, int samples) {

}

int main() {
  int number;

  printf("Enter number: ");
  scanf("%d", &number);

  printf("\nPrime: %d\n", isprime(number, SAMPLE_SIZE));
  return 0;
}
