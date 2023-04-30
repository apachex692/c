/*
 * Author: Sakthi Santhosh
 * Created on: 16/12/2022
 *
 * Website: https://leetcode.com/problems/remove-element/
 *
 * Remove Element
 */
#include <stdio.h>

int rm_element(int *array, int size, int value) {
  int buffer[size], buff_index, counter1;

  for (counter1 = 0, buff_index = 0; counter1 < size; counter1++)
    if (array[counter1] != value)
      buffer[buff_index++] = array[counter1];

  for (counter1 = 0; counter1 < buff_index; counter1++)
    array[counter1] = buffer[counter1];
  return buff_index;
}

int main() {
  int size, counter1, value;

  printf("Enter size: ");
  scanf("%d", &size);

  int array[size];

  printf("Enter array: ");
  for (counter1 = 0; counter1 < size; counter1++)
    scanf("%d", array + counter1);

  printf("Remove element: ");
  scanf("%d", &value);

  size = rm_element(array, size, value);
  printf("\nResult: ");
  for (counter1 = 0; counter1 < size; counter1++)
    printf("%d ", array[counter1]);
  printf("\n");
  return 0;
}
