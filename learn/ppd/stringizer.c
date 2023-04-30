/*
 * Author: Sakthi Santhosh
 * Created on: 08/10/2022
 *
 * Preprocessor Directive: Token Stringizer Operator #
 */
#include <stdio.h>

#define STRINGIZE(A) #A

int main() {
  printf("%s\n", STRINGIZE(hello_world));
  return 0;
}
