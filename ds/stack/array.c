/*
 * Author: Sakthi Santhosh
 * Created on: 17/07/2022
 *
 * Stack Implementation - Array
 */
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 5

struct Stack {
  int array[MAX_SIZE];
  int top;
} stack;

int is_empty() {
  return stack.top == -1;
}

int is_full() {
  return stack.top == MAX_SIZE - 1;
}

void push(int data) {
  if (is_full()) {
    printf("\033[31;01mError:\033[00m Stack overflow.\n");
    return;
  }

  stack.array[++stack.top] = data;
}

int peek() {
  if (is_empty()) {
    printf("\033[31;01mError:\033[00m Stack empty.\n");
    return -1;
  }

  return stack.array[stack.top];
}

void display() {
  if (is_empty()) {
    printf("\033[31;01mError:\033[00m Stack empty.\n");
    return;
  }

  int index = stack.top;

  printf("Display: ");
  while (index >= 0) printf("%d ", stack.array[index--]);
  printf("\n");
}

int pop() {
  if (is_empty()) {
    printf("\033[31;01mError:\033[00m Stack underflow.\n");
    return -1;
  }

  return stack.array[stack.top--];
}

void size() {
  printf("Total size: %d\nUsed: %d\n", MAX_SIZE, stack.top + 1);
}

int main() {
  int data, option;

  stack.top = -1;
  printf("\033[35;01mStack - Array\033[00m\n1 - Push\n2 - Peek\n3 - Pop\n4 - Display\n5 - Size\n6 - Exit\n");
  while (1) {
    printf("\nEnter option: ");
    scanf("%d", &option);

    switch (option) {
      case 1:
        printf("Push data: ");
        scanf("%d", &data);

        push(data);
        break;
      case 2:
        printf("Peek: %d\n", peek());
        break;
      case 3:
        printf("Pop: %d\n", pop());
        break;
      case 4:
        display();
        break;
      case 5:
        size();
        break;
      case 6:
        printf("Exit\n");
        return 0;
      default:
        printf("\033[31;01mError:\033[00m Invalid option.\n");
    }
  }
}
