/*
 * Author: Sakthi Santhosh
 * Created on: 01/01/2023
 *
 * Website: https://leetcode.com/problems/climbing-stairs/
 *
 * Climbing Stairs
 */
#include <stdio.h>

int main() {
  int steps, c;
  int a = 0;
  int b = 1;

  printf("Enter steps: ");
  scanf("%d", &steps);

  while (steps--) {
      c = a + b;
      a = b;
      b = c;
  }
  printf("\nResult: %d\n", c);
  return 0;
}
