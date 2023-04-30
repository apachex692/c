/*
 * Author: Sakthi Santhosh
 * Created on: 26/01/2023
 *
 * Website: https://leetcode.com/problems/longest-substring-without-repeating-characters/
 *
 * Longest Substring Without Repeating Characters
 */
#include <stdio.h>

int main() {
  char string[101];
  int availability_map[256] = {-1};
  int end = 0;
  int max = 0;
  int start = 0;

  printf("Enter string: ");
  scanf("%s", string);

  while (string[end] != '\0') {
    if (availability_map[string[end]] != -1)
      if (availability_map[string[end]] + 1 > start)
        start = availability_map[string[end]] + 1;
    availability_map[string[end]] = end;
    if (end - start + 1 > max)
      max = end - start + 1;
    end++;
  }

  printf("\nResult: %d\n", max);
  return 0;
}
