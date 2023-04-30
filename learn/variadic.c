/*
 * Author: Sakthi Santhosh
 * Created on: 25/03/2023
 *
 * Variable Argument List
 */
#include <stdarg.h>
#include <stdio.h>

void variadic(int size, ...) {
  int counter1;
  va_list argument_list;

  va_start(argument_list, size);

  for (counter1 = 0; counter1 < size; counter1++)
    printf("%d ", va_arg(argument_list, int));

  printf("\n");
  va_end(argument_list);
}

int main() {
  printf("Result: ");
  variadic(5, 1, 2, 3, 4, 5);
  return 0;
}
