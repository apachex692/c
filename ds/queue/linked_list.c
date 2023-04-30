/*
 * Author: Sakthi Santhosh
 * Created on: 01/02/2023
 *
 * Queue Implementation - Linked List
 */
#include <stdio.h>
#include <stdlib.h>

struct Node {
  int data;
  struct Node *next;
};

struct Node *new_node, *previous_node, *traverse_node;
struct Node *head_node = NULL;
struct Node *tail_node = NULL;

int is_empty() {
  return head_node == NULL;
}

void enqueue(int data) {
  if (is_empty()) {
    head_node = (struct Node *) malloc(sizeof(struct Node));
    head_node->data = data;
    head_node->next = NULL;
    tail_node = head_node;
  } else {
    new_node = (struct Node *) malloc(sizeof(struct Node));
    new_node->data = data;
    new_node->next = NULL;
    tail_node->next = new_node;
    tail_node = new_node;
  }
}

void dequeue() {
  if (is_empty()) {
    printf("\033[31;01mError:\033[00m Queue underflow.\n");
    return -1;
  }

  traverse_node = head_node;
  head_node = head_node->next;
  free(traverse_node);
  return temp;
}

struct Node *search(int data) {
  traverse_node = head_node;
  while (traverse_node != NULL && traverse_node->data != data)
    traverse_node  = traverse_node->next;
  return traverse_node;
}

void display() {
  if (is_empty()) {
    printf("\033[31;01mError:\033[00m Queue is empty.\n");
    return;
  }

  traverse_node = head_node;
  printf("Display:\n");
  while (traverse_node != NULL) {
    printf("  %d (%p->%p)\n", traverse_node->data, traverse_node, traverse_node->next);
    traverse_node = traverse_node->next;
  }
}

void exit_handler() {
  if (is_empty()) return;

  traverse_node = head_node;
  printf("Delete:\n");
  while (traverse_node != NULL) {
    previous_node = traverse_node;
    traverse_node = traverse_node->next;
    printf("  %d (%p)\n", previous_node->data, previous_node);
    free(previous_node);
  }
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
        dequeue();
        break;
      case 3:
        printf("Enter search key: ");
        scanf("%d", &data);

        printf("Found at: %p\n", search(data));
        break;
      case 4:
        display();
        break;
      case 5:
        exit_handler();
        printf("Exit\n");
        return 0;
      default:
        printf("\033[31;01mError:\033[31;00m Invalid option.\n");
    }
  }
}
