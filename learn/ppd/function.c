/*
 * Author: Sakthi Santhosh
 * Created on: 08/10/2022
 *
 * Preprocessor Directive: Function Macros
 */
#include <stdio.h>

#define SUM(A, B) A + B

int main() {
  printf("%d\n", SUM(A, B));
  return 0;
}
