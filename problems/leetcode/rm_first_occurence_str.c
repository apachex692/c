/*
 * Author: Sakthi Santhosh
 * Created on: 16/12/2022
 *
 * Website: https://leetcode.com/problems/find-the-index-of-the-first-occurrence-in-a-string/
 *
 * Find the Index of the First Occurrence in a String
 */
#include <stdio.h>
#include <string.h>

int main() {
  char haystack[101], needle[51];
  int counter1, counter2;

  printf("Enter string: ");
  scanf("%s", haystack);

  printf("Enter substring: ");
  scanf("%s", needle);

  int haystack_len = strlen(haystack);
  int needle_len = strlen(needle);

  printf("\nFirst occurence: ");
  for (counter1 = 0, counter2 = 0; counter1 <= haystack_len - needle_len; counter1++) {
    for (
      counter2 = 0;
      counter2 < needle_len && haystack[counter1 + counter2] == needle[counter2];
      counter2++
    );
    if (counter2 == needle_len) break;
  }
  if (counter1 == haystack_len - needle_len) {
    printf("(null)\n");
  } else {
    printf("%d\n", counter1);
  }
  return 0;
}
