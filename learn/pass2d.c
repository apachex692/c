/*
 * Author: Sakthi Santhosh
 * Created on: 08/10/2022
 *
 * Passing 2D Array to Functions
 */
#include <stdio.h>

void method1(int row, int column, int matrix[][column]) {
  int counter1, counter2;

  for (counter1 = 0; counter1 < row; counter1++) {
    printf("  ");
    for (counter2 = 0; counter2 < column; counter2++)
      printf("%d ", matrix[counter1][counter2]);
    printf("\n");
  }
}

void method2(int row, int column, int *matrix) {
  int counter1, counter2;

  for (counter1 = 0; counter1 < row; counter1++) {
    printf("  ");
    for (counter2 = 0; counter2 < column; counter2++)
      printf("%d ", *(matrix + row * counter1 + counter2));
    printf("\n");
  }
}

void method3(int row, int column, int **matrix) {
 int counter1, counter2;

  for (counter1 = 0; counter1 < row; counter1++) {
    printf("  ");
    for (counter2 = 0; counter2 < column; counter2++)
      printf("%d ", *(matrix + row * counter1 + counter2));
    printf("\n");
  }
}

void method4(int row, int column, int (*matrix)[column]) { // Pointer to an array of size column.
  int counter1, counter2;

  for (counter1 = 0; counter1 < row; counter1++) {
    printf("  ");
    for (counter2 = 0; counter2 < column; counter2++)
      printf("%d ", matrix[counter1][counter2]);
    printf("\n");
  }
}

int main() {
  int row, column, counter1, counter2;

  printf("Enter dimensions: ");
  scanf("%d %d", &row, &column);

  int matrix[row][column];

  printf("Enter %d elements: ", row * column);
  for (counter1 = 0; counter1 < row; counter1++) {
    for (counter2 = 0; counter2 < column; counter2++) {
      scanf("%d", &matrix[counter1][counter2]);
    }
  }

  printf("\nMatrix:\n");
  method2(row, column, matrix[0]);
  return 0;
}
