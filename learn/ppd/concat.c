/*
 * Author: Sakthi Santhosh
 * Created on: 08/10/2022
 *
 * Preprocessor Directive: Token Concatenating Operator ##
 */
#include <stdio.h>

#define CONCAT(A, B) A##B

int main() {
  int xy = 10;

  printf("%d\n", CONCAT(x, y));
  return 0;
}
