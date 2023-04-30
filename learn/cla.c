/*
 * Author: Sakthi Santhosh
 * Created on: 25/03/2023
 *
 * Command Line Arguments
 */
#include <stdio.h>

int main(int argc, char **argv) {
  int counter1;

  printf("Arguments passed:\n");
  for (counter1 = 0; counter1 < argc; counter1++)
    printf("  %s\n", *(argv + counter1));
  return 0;
}
