/*
 * Author: Sakthi Santhosh
 * Created on: 23/27/2022
 *
 * List Implementation - Array
 */
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 5

int array[MAX_SIZE];
int end = -1;

int is_empty() {
  return end == -1;
}

int is_full() {
  return end == MAX_SIZE - 1;
}

int out_range(int position) {
  return position <= 0 || position > end + 1;
}

int read(int position) {
  if (is_empty()) {
    printf("\033[31;01mError:\033[00m Array is empty.\n");
    return -1;
  }
  if (out_range(position)) {
    printf("\033[31;01mError:\033[00m Invalid read position.\n");
    return -1;
  }

  return array[position - 1];
}

void write(int position, int data) {
  if (is_empty()) {
    printf("\033[31;01mError:\033[00m Array is empty.\n");
    return;
  }
  if (out_range(position)) {
    printf("\033[31;01mError:\033[00m Invalid write position.\n");
    return;
  }

  array[position - 1] = data;
}

void insert(int position, int data) {
  if (is_full()) {
    printf("\033[31;01mError:\033[00m Array overflow.\n");
    return;
  }
  // out_range() logic is broken for insert operation.
  if (position != end + 2 && out_range(position)) {
    printf("\033[31;01mError:\033[00m Invalid insert position.\n");
    return;
  }

  int index;

  for (index = end; index >= position - 1; index--) {
    array[index + 1] = array[index];
  }
  array[position - 1] = data;
  end++;
}

int delete(int position) {
  if (is_empty()) {
    printf("\033[31;01mError:\033[00m Array underflow.\n");
    return -1;
  }
  if (out_range(position)) {
    printf("\033[31;01mError:\033[00m Invalid remove position.\n");
    return -1;
  }

  int index;
  int temp = array[position - 1];

  printf("\n");
  for (index = position; index <= end; index++) {
    array[index - 1] = array[index];
  }
  end--;
  return temp;
}

void display() {
  if (is_empty()) {
    printf("\033[31;01mError:\033[00m Array empty.\n");
    return;
  }

  int index;

  printf("Display: ");
  for (index = 0; index <= end; index++) {
    printf("%d ", array[index]);
  }
  printf("\n");
  return;
}

int main() {
  int data, option, position;

  printf("\033[35;01mArray Operations\033[00m\n1 - Read\n2 - Write\n3 - Insert\n4 - Remove\n5 - Display\n6 - Exit\n");
  while (1) {
    printf("\nEnter option: ");
    scanf("%d", &option);

    switch (option) {
      case 1:
        printf("Enter position: ");
        scanf("%d", &position);

        printf("Read: %d\n", read(position));
        break;
      case 2:
        printf("Enter position: ");
        scanf("%d", &position);

        printf("Enter data: ");
        scanf("%d", &data);

        write(position, data);
        break;
      case 3:
        printf("Enter position: ");
        scanf("%d", &position);

        printf("Enter data: ");
        scanf("%d", &data);

        insert(position, data);
        break;
      case 4:
        printf("Enter position: ");
        scanf("%d", &position);

        printf("Delete: %d\n", delete(position));
        break;
      case 5:
        display();
        break;
      case 6:
        printf("Exit\n");
        return 0;
      default:
        printf("\033[31;01mError:\033[31;00m Invalid option.\n");
    }
  }
}
