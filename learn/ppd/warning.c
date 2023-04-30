/*
 * Author: Sakthi Santhosh
 * Created on: 08/10/2022
 *
 * Preprocessor Directive: Warning
 */
#include <stdio.h>

#ifndef A
# warning "Error: Macro A not defined."
#endif

int main() {
  return 0;
}
