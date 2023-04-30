/*
 * Author: Sakthi Santhosh
 * Created on: 05/12/2022
 *
 * Website: https://leetcode.com/problems/roman-to-integer/
 *
 * Roman Numeral to Integer
 */
#include <stdio.h>

int roman_to_integer(char numeral) {
  switch(numeral) {
    case 'I':
      return 1;
    case 'V':
      return 5;
    case 'X':
      return 10;
    case 'L':
      return 50;
    case 'C':
      return 100;
    case 'D':
      return 500;
    case 'M':
      return 1000;
  }
}

int main() {
  char roman[100];
  int counter1, current, next;
  int result = 0;

  printf("Enter string: ");
  scanf("%s", roman);

  for (counter1 = 0; roman[counter1] != '\0'; counter1++) {
    current = roman_to_integer(roman[counter1]);
    next = roman_to_integer(roman[counter1 + 1]);

    if (current >= next) {
      result += current;
    } else {
      result -= current;
    }
  }
  printf("\nResult: %d\n", result);
  return 0;
}
