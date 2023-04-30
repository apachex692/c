/*
 * Author: Sakthi Santhosh
 * Created on: 09/09/2022
 *
 * Circular Singly Linked List Implementation
 */
#include <stdio.h>
#include <stdlib.h>

struct Node {
  int data;
  struct Node *next;
};

struct Node *traverse_node, *new_node, *previous_node;
struct Node *head_node = NULL;
int size = 0;

int is_empty() {
  return head_node == NULL;
}

void insert(int data, int location) {
  if (location < 1 || location > size + 1) {
    printf("\033[31;01mError:\033[00m Location of out bounds.\n");
    return;
  }

  if (is_empty()) {
    head_node = (struct Node *) malloc(sizeof(struct Node));
    head_node->data = data;
    head_node->next = head_node;
  } else {
    new_node = (struct Node *) malloc(sizeof(struct Node));
    new_node->data = data;
    traverse_node = head_node;
    if (location == 1) {
      while (traverse_node->next != head_node) traverse_node = traverse_node->next;
      new_node->next = head_node;
      traverse_node->next = new_node;
      head_node = new_node;
    } else {
      while (location > 2) {
        traverse_node = traverse_node->next;
        location--;
      }
      new_node->next = traverse_node->next;
      traverse_node->next = new_node;
    }
  }
  size++;
}

void delete(int location) {
  if (is_empty()) {
    printf("\033[31;01mError:\033[00m Linked list is empty.\n");
    return;
  }
  if (location < 1 || location > size) {
    printf("\033[31;01mError:\033[00m Location of out bounds.\n");
    return;
  }

  traverse_node = head_node;
  if (location == 1 && size > 1) {
    while (traverse_node->next != head_node) traverse_node = traverse_node->next;
    traverse_node->next = head_node->next;
    traverse_node = head_node;
    head_node = head_node->next;
  } else {
    while (location > 1) {
      previous_node = traverse_node;
      traverse_node = traverse_node->next;
      location--;
    }
    previous_node->next = traverse_node->next;
  }
  free(traverse_node);
  size--;
}

struct Node *search(int data) {
  traverse_node = head_node;
  while (traverse_node->next != head_node && traverse_node->data != data)
    traverse_node  = traverse_node->next;
  return traverse_node;
}

void display() {
  if (is_empty()) {
    printf("\033[31;01mError:\033[00m Linked list is empty.\n");
    return;
  }

  printf("Display:\n");
  traverse_node = head_node;
  do {
    printf("  %d (%p->%p)\n", traverse_node->data, traverse_node, traverse_node->next);
    traverse_node = traverse_node->next;
  } while (traverse_node != head_node);
}

void reverse() {
  if (is_empty()) {
    printf("\033[31;01mError:\033[00m Linked list is empty.\n");
    return;
  }

  struct Node *next_node;

  traverse_node = head_node;
  previous_node = head_node;
  while (previous_node->next != head_node) previous_node = previous_node->next;
  do {
    next_node = traverse_node->next;
    traverse_node->next = previous_node;
    previous_node = traverse_node;
    traverse_node = next_node;
  } while (traverse_node != head_node);
  traverse_node->next = previous_node;
  head_node = previous_node;
  display();
}

void exit_handler() {
  if (is_empty()) return;

  traverse_node = head_node;
  printf("Delete:\n");
  do {
    previous_node = traverse_node;
    traverse_node = traverse_node->next;
    printf("  %d (%p)\n", previous_node->data, previous_node);
    free(previous_node);
  } while (traverse_node != head_node);
}

int main() {
  int option, data, location;

  printf("\033[35;01mCircular Singly Linked List\033[00m\n1 - Insert\n2 - Delete\n3 - Search\n4 - Display\n5 - Reverse\n6 - Exit\n");
  while (1) {
    printf("\nEnter option: ");
    scanf("%d", &option);

    switch (option) {
      case 1:
        printf("Enter data and location (%d): ", size + 1);
        scanf("%d %d", &data, &location);

        insert(data, location);
        break;
      case 2:
        printf("Enter location (%d): ", size);
        scanf("%d", &location);

        delete(location);
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
        reverse();
        break;
      case 6:
        exit_handler();
        printf("Exit\n");
        return 0;
      default:
        printf("\033[31;01mError:\033[00m Invalid option.\n");
    }
  }
}
