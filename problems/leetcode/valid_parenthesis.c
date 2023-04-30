/*
 * Author: Sakthi Santhosh
 * Created on: 16/12/2022
 *
 * Website: https://leetcode.com/problems/valid-parentheses/
 *
 * Valid Parenthesis
 */
#include <stdio.h>

int is_matching_pair(char c1, char c2) {
  return (
    (c1 == '(' && c2 == ')')
    || (c1 == '{' && c2 == '}')
    || (c1 == '[' && c2 == ']')
  );
}

int main() {
  char string[101], stack[101];
  char *pointer = string;
  int top = -1;

  printf("Enter string: ");
  scanf("%s", string);

  printf("\nBalanced: ");
  while (*pointer != '\0') {
    if (*pointer == '(' || *pointer == '{' || *pointer == '[') {
      stack[++top] = *pointer;
    } else if (*pointer == ')' || *pointer == '}' || *pointer == ']') {
      if (top == -1 || !is_matching_pair(stack[top], *pointer)) break;
      top--;
    } else {
      break;
    }
    pointer++;
  }
  if (*pointer == '\0' && top == -1) {
    printf("True\n");
  } else {
    printf("False\n");
  }
  return 0;
}
