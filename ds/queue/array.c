/*
 * Author: Sakthi Santhosh
 * Created on: 09/01/2023
 *
 * Queue Implementation - Array
 */
#include <stdio.h>

#define MAX_SIZE 5

int array[MAX_SIZE];
int pointers[2] = {-1, -1};

int is_empty() {
  return pointers[0] == -1 || pointers[0] > pointers[1];
}

int is_full() {
  return pointers[1] == MAX_SIZE - 1;
}

void reset() {
  pointers[0] = -1;
  pointers[1] = -1;
}

void enqueue(int data) {
  if (pointers[0] == MAX_SIZE) {
    printf("\033[32;01mInfo:\033[00m Resetting queue.\n");
    reset();
  }
  if (is_full()) {
    printf("\033[31;01mError:\033[00m Queue overflow.\n");
    return;
  }

  pointers[0] += (pointers[0] == -1);
  array[++pointers[1]] = data;
}

int dequeue() {
  if (is_empty()) {
    printf("\033[31;01mError:\033[00m Queue underflow.\n");
    return -1;
  }

  return array[pointers[0]++];
}

void display() {
  if (is_empty()) {
    printf("\033[31;01mError:\033[00m Queue is empty.\n");
    return;
  }

  int index = pointers[0];

  printf("Display: ");
  while (index <= pointers[1])
    printf("%d ", array[index++]);
  printf("\n");
}

int search(int data) {
  if (is_empty()) {
    printf("\033[31;01mError:\033[00m Queue is empty.\n");
    return -1;
  }

  int index = pointers[0];

  while (index <= pointers[1]) {
    if (array[index] == data)
      return index;
    index++;
  }
  return -1;
}

int main() {
  int option, data;

  printf("\033[35;01mQueue\033[00m\n1 - Enqueue\n2 - Dequeue\n3 - Search\n4 - Display\n5 - Exit\n");
  while (1) {
    printf("\nEnter option: ");
    scanf("%d", &option);

    switch(option) {
      case 1:
        printf("Enter data: ");
        scanf("%d", &data);

        enqueue(data);
        break;
      case 2:
        printf("Dequeue: %d\n", dequeue());
        break;
      case 3:
        printf("Enter search key: ");
        scanf("%d", &data);

        printf("Found at: %d\n", search(data));
        break;
      case 4:
        display();
        break;
      case 5:
        printf("Exit\n");
        return 0;
      default:
        printf("\033[31;01mError:\033[31;00m Invalid option.\n");
    }
  }
}
