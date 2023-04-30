/*
 * Author: Sakthi Santhosh
 * Created on: 25/01/2023
 *
 * Reference: https://code.letuscrack.com/maximum-goods-transported/
 *
 * Maximum Goods Transported
 */
#include <limits.h>
#include <stdio.h>

int main() {
  int counter1, counter2, capacity, destination, minimum, source, stations, sum, tracks;
  int destinations[100] = {0};
  int map_source_destination[100] = {0};

  printf("Enter stations: ");
  scanf("%d", &stations);

  int weight_matrix[stations + 1][stations + 1];

  printf("Enter tracks: ");
  scanf("%d", &tracks);

  printf("Enter source, destination and capacity:\n");
  for (counter1 = 0; counter1 < tracks; counter1++) {
    printf("  Track-%d: ", counter1 + 1);
    scanf("%d %d %d", &source, &destination, &capacity);

    destinations[destination] = 1;
    map_source_destination[source] = destination;
    weight_matrix[source][destination] = capacity;
  }

  for (counter1 = 1, sum = 0; counter1 <= stations; counter1++) {
    if (!destinations[counter1]) {
      minimum = INT_MAX;
      counter2 = counter1;
      while (map_source_destination[counter2]) {
        if (weight_matrix[counter2][map_source_destination[counter2]] < minimum)
          minimum = weight_matrix[counter2][map_source_destination[counter2]];
        counter2 = map_source_destination[counter2];
      }
      sum += minimum;
    }
  }

  printf("\nResult: %d\n", sum);
  return 0;
}
