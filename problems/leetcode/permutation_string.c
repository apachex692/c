/*
 * Author: Sakthi Santhosh
 * Created on: 27/01/2023
 *
 * Website: https://leetcode.com/permutation-in-string/
 *
 * Permutation in String
 */
#include <stdio.h>
#include <string.h>

int main() {
  char string1[21], string2[21];

  printf("Enter two strings: ");
  scanf("%s %s", string1, string2);

  int length1 = strlen(string1);
  int length2 = strlen(string2);

  printf("\nResult: ");
  if (length1 > length2) {
    printf("False\n");
    return 0;
  }

  int index, left, right;
  int matches = 0;
  int map1[26] = {0};
  int map2[26] = {0};

  for (index = 0; index < length1; index++) {
    map1[string1[index] - 'a']++;
    map2[string2[index] - 'a']++;
  }

  for (index = 0; index < 26; index++)
    matches += (map1[index] == map2[index]);

  for (index = 0; index < length2 - length1; index++) {
    left = string2[index] - 'a';
    right = string2[index + length1] - 'a';

    if (matches == 26) {
      printf("True\n");
      return 0;
    }

    map2[right]++;
    if (map1[right] == map2[right]) {
      matches++;
    } else if (map1[right] + 1 == map2[right]) {
      matches--;
    }

    map2[left]--;
    if (map1[left] == map2[left]) {
      matches++;
    } else if (map1[left] - 1 == map2[left]) {
      matches--;
    }
  }
  if (matches == 26) {
    printf("True\n");
  } else {
    printf("False\n");
  }
  return 0;
}
