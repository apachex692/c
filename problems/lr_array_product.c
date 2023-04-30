/*
 * Author: Sakthi Santhosh
 * Created on: 03/12/2022
 *
 * Array Elements Product Except Current Position
 */
#include <stdio.h>

int main() {
  int size, counter1;

  printf("Enter size: ");
  scanf("%d", &size);

  int array[size], lconsecutive_product[size], rconsecutive_product[size];

  printf("Enter array: ");
  for (counter1 = 0; counter1 < size; counter1++)
    scanf("%d", &array[counter1]);

  lconsecutive_product[0] = array[0];
  for (counter1 = 1; counter1 < size; counter1++)
    lconsecutive_product[counter1] = lconsecutive_product[counter1 - 1] * array[counter1];

  rconsecutive_product[size - 1] = array[size - 1];
  for (counter1 = size - 2; counter1 >= 0; counter1--)
    rconsecutive_product[counter1] = rconsecutive_product[counter1 + 1] * array[counter1];

  printf("\nResult: %d ", rconsecutive_product[1]);
  for (counter1 = 1; counter1 < size - 1; counter1++)
    printf("%d ", lconsecutive_product[counter1 - 1] * rconsecutive_product[counter1 + 1]);
  printf("%d\n", lconsecutive_product[size - 2]);
  return 0;
}
