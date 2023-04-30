/*
 * Author: Sakthi Santhosh
 * Created on: 08/10/2022
 *
 * Preprocessor Directive: Conditional
 */
#include <stdio.h>

#define B 20

#ifndef A
# define A 10
#endif

#ifdef B
# warning "Error: Macro B is already defined."
#else
# define B 20
#endif

int main() {
  printf("%d %d\n", A, B);
  return 0;
}
