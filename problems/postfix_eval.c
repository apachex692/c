/*
 * Author: Sakthi Santhosh
 * Created on: 18/09/2022
 *
 * Postfix Expression Evaluator
 */
#include <stdio.h>
#include <ctype.h>

#define MAX_SIZE 20

struct Stack {
  int array[MAX_SIZE];
  int top;
} stack;

int main() {
  char expression[MAX_SIZE];
  char *pointer = expression;

  printf("Enter expression: ");
  scanf("%s", expression);

  stack.top = -1;
  while (*pointer != '\0') {
    if (isdigit(*pointer)) {
      stack.array[++stack.top] = *pointer - '0';
    } else {
      if (*pointer == '+') {
        stack.array[stack.top - 1] += stack.array[stack.top];
      } else if (*pointer == '-') {
        stack.array[stack.top - 1] -= stack.array[stack.top];
      } else if (*pointer == '*') {
        stack.array[stack.top - 1] *= stack.array[stack.top];
      } else if (*pointer == '/') {
        stack.array[stack.top - 1] /= stack.array[stack.top];
      } else {
        printf("\n\033[31;01mError:\033[00m Encountered invalid character '%c'.\n", *pointer);
        return 1;
      }
      stack.top--;
    }
    pointer++;
  }
  printf("\nResult: %d\n", stack.array[stack.top]);
  return 0;
}
