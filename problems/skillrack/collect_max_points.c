/*
 * Author: Sakthi Santhosh
 * Created on: 11/12/2022
 *
 * Reference: https://code.letuscrack.com/collect-max-points/
 *
 * Collect Max Points
 */
#include <stdio.h>

int max(int x, int y, int z) {
  if (x > y && x > z) {
    return x;
  } else if (y > z) {
    return y;
  } else {
    return z;
  }
}

int main() {
  int row, column, counter1, counter2;
  int max_point = 0;

  printf("Enter shape: ");
  scanf("%d %d", &row, &column);

  int matrix[row][column];

  printf("Enter %d elements: ", row * column);
  for (counter1 = 0; counter1 < row; counter1++)
    for (counter2 = 0; counter2 < column; counter2++)
        scanf("%d", *(matrix + counter1) + counter2);

  for (counter1 = 1; counter1 < column; counter1++) {
    matrix[0][counter1] += max(
      0,
      matrix[0][counter1 - 1],
      matrix[1][counter1 - 1]
    );
    for (counter2 = 1; counter2 < row - 1; counter2++) {
      matrix[counter2][counter1] += max(
        matrix[counter2 - 1][counter1 - 1],
        matrix[counter2][counter1 - 1],
        matrix[counter2 + 1][counter1 - 1]
      );
    }
    matrix[counter2][counter1] += max(
      0,
      matrix[counter2 - 1][counter1 - 1],
      matrix[counter2][counter1 - 1]
    );
  }

  printf("\nCummulative matrix:\n");
  for (counter1 = 0; counter1 < row; counter1++) {
    printf("  ");
    for (counter2 = 0; counter2 < column; counter2++)
      printf("%d ", matrix[counter1][counter2]);
    printf("\n");
  }
  for (counter1 = 0, counter2 = column - 1; counter1 < row; counter1++)
    if (matrix[counter1][counter2] > max_point)
      max_point = matrix[counter1][counter2];
  printf("Max point: %d\n", max_point);
  return 0;
}
