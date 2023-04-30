/*
 * Author: Sakthi Santhosh
 * Created on: 17/07/2022
 *
 * Stack Implementation - Linked List
 */
#include <stdio.h>
#include <stdlib.h>

struct Node {
  int data;
  struct Node *next;
};

struct Node *top_node = NULL;
struct Node *temp_node;

int is_empty() {
  return top_node == NULL;
}

void push(int data) {
  if (is_empty()) {
    top_node = (struct Node *) malloc(sizeof(struct Node));
    top_node->data = data;
    top_node->next = NULL;
    return;
  }

  temp_node = (struct Node *) malloc(sizeof(struct Node));
  temp_node->data = data;
  temp_node->next = top_node;
  top_node = temp_node;
}

int peek() {
  if (is_empty()) {
    printf("\033[31;01mError:\033[00m Stack empty.\n");
    return -1;
  }

  return top_node->data;
}

void display() {
  if (is_empty()) {
    printf("\033[31;01mError:\033[00m Stack empty.\n");
    return;
  }

  printf("Display:\n");
  temp_node = top_node;
  while (temp_node != NULL) {
    printf("  %d (%p->%p)\n", temp_node->data, temp_node, temp_node->next);
    temp_node = temp_node->next;
  }
}

int pop() {
  if (is_empty()) {
    printf("\033[31;01mError:\033[00m Stack underflow.\n");
    return -1;
  }

  int temp = top_node->data;

  temp_node = top_node;
  top_node = top_node->next;
  free(temp_node);
  return temp;
}

void exit_handler() {
  printf("Delete:\n");
  while (!is_empty()) {
    temp_node = top_node;
    top_node = top_node->next;
    printf("  %d (%p)\n", temp_node->data, temp_node);
    free(temp_node);
  }
  printf("Exit\n");
}

int main() {
  int data, option;

  printf("\033[35;01mStack - Linked List\033[00m\n1 - Push\n2 - Peek\n3 - Pop\n4 - Display\n5 - Exit\n");
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
        exit_handler();
        return 0;
      default:
        printf("\033[31;01mError:\033[00m Invalid option.\n");
    }
  }
}
