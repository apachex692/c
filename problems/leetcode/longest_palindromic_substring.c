/*
 * Author: Sakthi Santhosh
 * Created on: 04/03/2023
 *
 * Reference: https://youtu.be/QfZvw8_jz1w
 * Website: https://leetcode.com/problems/longest-palindromic-substring/
 *
 * Longest Palindromic Substring
 */
#include <stdio.h>
#include <string.h>

#define MAX(X, Y) (X > Y) ? X : Y

int expand(char *string, int length, int start, int end) {
  while (start >= 0 && end < length && string[start] == string[end]) {
    start--;
    end++;
  }
  return end - start - 1;
}

int main() {
  char string[101];
  int counter1, odd_plen, even_plen;
  int start = 0;
  int end = 0;
  int cmax = 0;

  printf("Enter string: ");
  scanf("%101s", string);

  int length = strlen(string);

  for (counter1 = 0; counter1 < length; counter1++) {
    odd_plen = expand(string, length, counter1, counter1);
    even_plen = expand(string, length, counter1, counter1 + 1);

    cmax = MAX(odd_plen, even_plen);
    if (cmax > end - start) {
      start = counter1 - (cmax - 1) / 2;
      end = counter1 + cmax / 2;
    }
  }

  printf("\nResult: ");
  for (counter1 = start; counter1 <= end; counter1++)
    printf("%c", string[counter1]);
  printf("\n");
  return 0;
}
