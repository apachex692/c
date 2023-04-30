/*
 * Author: Sakthi Santhosh
 * Created on: 04/10/2022
 *
 * Left Right Odd Count
 */
#include <stdio.h>
#include <stdlib.h>

int main(){
  int counter1, size;
  int left_count = 0;
  int right_count = 0;

  printf("Enter size: ");
  scanf("%d", &size);

  int array[size];

  printf("Enter array: ");
  for (counter1 = 0; counter1 < size; counter1++) {
    scanf("%d", &array[counter1]);
    right_count += (array[counter1] % 2);
  }

  printf("\nResult: ");
  for (counter1 = 0; counter1 < size; counter1++) {
    right_count -= (array[counter1] % 2);
    printf("%d ", (left_count == right_count) ? array[counter1] : 0);
    left_count += (array[counter1] % 2);
  }
  printf("\n");
  return 0;
}
