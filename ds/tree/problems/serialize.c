/*
 * Author: Sakthi Santhosh
 * Created on: 29/01/2023
 *
 * Binary Tree Serializer
 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "./lib/tree.h"

#define NODE_COUNT 5
#define RESULT_SIZE 30
#define STACK_SIZE 20

struct Stack {
  struct Node *array[STACK_SIZE];
  int top;
};

struct Node *traverse_node, *temp_node;
struct Node *root_node = NULL;

int *preorder_serialize() {
  struct Stack trace;
  int *result = (int *) malloc(sizeof(int) * RESULT_SIZE);
  int r_index = 0;

  trace.top = -1;
  traverse_node = root_node;
  while (traverse_node != NULL || trace.top != -1) {
    if (traverse_node != NULL) {
      trace.array[++trace.top] = traverse_node;
      result[r_index++] = traverse_node->data;
      traverse_node = traverse_node->left;
    } else {
      result[r_index++] = -1;
      traverse_node = trace.array[trace.top--];
      traverse_node = traverse_node->right;
    }
  }
  result[r_index] = -1;
  return result;
}

int *inorder_serialize() {
  struct Stack trace;
  int *result = (int *) malloc(sizeof(int) * RESULT_SIZE);
  int r_index = 0;

  trace.top = -1;
  traverse_node = root_node;
  while (traverse_node != NULL || trace.top != -1) {
    if (traverse_node != NULL) {
      trace.array[++trace.top] = traverse_node;
      traverse_node = traverse_node->left;
    } else {
      result[r_index++] = -1;
      traverse_node = trace.array[trace.top--];
      result[r_index++] = traverse_node->data;
      traverse_node = traverse_node->right;
    }
  }
  result[r_index] = -1;
  return result;
}

// FIXME
int *postorder_serialize() {
  struct Stack trace;
  int *result = (int *) malloc(sizeof(int) * RESULT_SIZE);
  int r_index = 0;

  trace.top = -1;
  traverse_node = root_node;
  temp_node = NULL;
  while (traverse_node != NULL || trace.top != -1) {
    if (traverse_node != NULL) {
      trace.array[++trace.top] = traverse_node;
      traverse_node = traverse_node->left;
    } else {
      traverse_node = trace.array[trace.top];
      if (traverse_node->right == NULL || traverse_node->right == temp_node) {
        result[r_index++] = traverse_node->data;
        trace.top--;
        temp_node = traverse_node;
        traverse_node = NULL;
      } else {
        traverse_node = traverse_node->right;
      }
    }
  }
  return result;
}

// TODO
void level_order_serialize() {
  return;
}

int main() {
  int index;
  int sequence[NODE_COUNT];

  srand(time(0));
  printf("Sequence: ");
  for (index = 0; index < NODE_COUNT; index++) {
    sequence[index] = rand() % 100;
    printf("%d ", sequence[index]);
  }
  printf("\n");

  for (index = 0; index < NODE_COUNT; index++)
    root_node = insert(root_node, sequence[index]);

  printf("Display (in-order):\n");
  inorder(root_node);

  int *array = inorder_serialize();

  printf("Serialized tree (in-order): ");
  for (index = 0; index < RESULT_SIZE; index++)
    printf("%d ", array[index]);
  printf("\n");

  exit_handler(root_node);
  free(array);
  return 0;
}
