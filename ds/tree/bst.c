/*
 * Author: Sakthi Santhosh
 * Created on: 23/09/2022
 *
 * Binary Search Tree Implementation
 */
#include <stdio.h>
#include <stdlib.h>

#define STACK_SIZE 20
#define QUEUE_SIZE 20

struct Node {
  int data;
  struct Node *left;
  struct Node *right;
};

struct Stack {
  struct Node *array[STACK_SIZE];
  int top;
};

struct Node *new_node, *traverse_node, *parent_node, *temp_node;
struct Node *root_node = NULL;

int is_empty() {
  return root_node == NULL;
}

void insert(int data) {
  if (is_empty()) {
    root_node = (struct Node *) malloc(sizeof(struct Node));
    root_node->data = data;
    root_node->left = NULL;
    root_node->right = NULL;
  } else {
    new_node = (struct Node *) malloc(sizeof(struct Node));
    new_node->data = data;
    new_node->left = NULL;
    new_node->right = NULL;
    traverse_node = root_node;
    while (traverse_node != NULL) {
      parent_node = traverse_node;
      if (data < traverse_node->data) {
        traverse_node = traverse_node->left;
      } else {
        traverse_node = traverse_node->right;
      }
    }
    if (data < parent_node->data) {
      parent_node->left = new_node;
    } else {
      parent_node->right = new_node;
    }
  }
}

void delete(int data) {
  if (is_empty()) {
    printf("\033[31;01mError:\033[00m Empty tree.\n");
    return;
  }

  traverse_node = root_node;
  parent_node == NULL;
  while (traverse_node != NULL && traverse_node->data != data) {
    parent_node = traverse_node;
    if (data < traverse_node->data) {
      traverse_node = traverse_node->left;
    } else {
      traverse_node = traverse_node->right;
    }
  }
  if (traverse_node == NULL) {
    printf("\033[31;01mError:\033[00m Key not found.\n");
    return;
  }

  if (traverse_node->left == NULL && traverse_node->right == NULL) {
    if (traverse_node == root_node) {
      root_node = NULL;
    } else {
      if (traverse_node = parent_node->left) {
        parent_node->left = NULL;
      } else {
        parent_node->right = NULL;
      }
    }
  } else if (traverse_node->left == NULL || traverse_node->right == NULL) {
    temp_node = (traverse_node->left == NULL) ? traverse_node->right : traverse_node->left;
    if (traverse_node == root_node) {
      root_node = temp_node;
    } else {
      if (traverse_node == parent_node->left) {
        parent_node->left = temp_node;
      } else {
        parent_node->right = temp_node;
      }
    }
  } else {
    temp_node = traverse_node;
    parent_node = traverse_node;
    traverse_node = traverse_node->left;
    while (traverse_node->right != NULL) {
      parent_node = traverse_node;
      traverse_node = traverse_node->right;
    }
    temp_node->data = traverse_node->data;
    if (parent_node == temp_node) {
      parent_node->left = traverse_node->left;
    } else {
      parent_node->right = traverse_node->left;
    }
  }
  free(traverse_node);
}

// left->root->right
void inorder() {
  if(is_empty()) {
    printf("\033[31;01mError:\033[00m Empty tree.\n");
    return;
  }

  struct Stack trace;

  trace.top = -1;
  traverse_node = root_node;
  printf("Display (in-order):\n");
  while (traverse_node != NULL || trace.top != -1) {
    if (traverse_node != NULL) {
      trace.array[++trace.top] = traverse_node;
      traverse_node = traverse_node->left;
    } else {
      traverse_node = trace.array[trace.top--];
      printf("  %d (%p<-%p->%p)\n",
        traverse_node->data,
        traverse_node->left,
        traverse_node,
        traverse_node->right
      );
      traverse_node = traverse_node->right;
    }
  }
}

// root->left->right
void preorder() {
  if(is_empty()) {
    printf("\033[31;01mError:\033[00m Empty tree.\n");
    return;
  }

  struct Stack trace;

  trace.top = -1;
  traverse_node = root_node;
  printf("Display (pre-order):\n");
  while (traverse_node != NULL || trace.top != -1) {
    if (traverse_node != NULL) {
      trace.array[++trace.top] = traverse_node;
      printf("  %d (%p<-%p->%p)\n",
        traverse_node->data,
        traverse_node->left,
        traverse_node,
        traverse_node->right
      );
      traverse_node = traverse_node->left;
    } else {
      traverse_node = trace.array[trace.top--];
      traverse_node = traverse_node->right;
    }
  }
}

// left->right->root
void postorder() {
  if(is_empty()) {
    printf("\033[31;01mError:\033[00m Empty tree.\n");
    return;
  }

  struct Stack trace;

  trace.top = -1;
  traverse_node = root_node;
  temp_node = NULL;
  printf("Display (post-order):\n");
  while (traverse_node != NULL || trace.top != -1) {
    if (traverse_node != NULL) {
      trace.array[++trace.top] = traverse_node;
      traverse_node = traverse_node->left;
    } else {
      traverse_node = trace.array[trace.top];
      if (traverse_node->right == NULL || traverse_node->right == temp_node) {
        printf("  %d (%p<-%p->%p)\n",
          traverse_node->data,
          traverse_node->left,
          traverse_node,
          traverse_node->right
        );
        trace.top--;
        temp_node = traverse_node;
        traverse_node = NULL;
      } else {
        traverse_node = traverse_node->right;
      }
    }
  }
}

void levelorder() {
  if (is_empty()) {
    printf("\033[31;01mError:\033[00m Empty tree.\n");
    return;
  }

  printf("\033[34;01mInfo:\033[00m Under development.\n");
}

struct Node *search(int data) {
  traverse_node = root_node;
  while (traverse_node != NULL && traverse_node->data != data)
    if (data < traverse_node->data) {
      traverse_node = traverse_node->left;
    } else {
      traverse_node = traverse_node->right;
    }
  return traverse_node;
}

void exit_handler() {
  if (is_empty()) return;

  struct Stack trace;

  trace.top = -1;
  traverse_node = root_node;
  parent_node = NULL;
  printf("Delete:\n");
  while (traverse_node != NULL || trace.top != -1) {
    if (traverse_node != NULL) {
      trace.array[++trace.top] = traverse_node;
      traverse_node = traverse_node->left;
    } else {
      traverse_node = trace.array[trace.top];
      if (traverse_node->right == NULL || traverse_node->right == parent_node) {
        printf("  %d (%p)\n",
          traverse_node->data,
          traverse_node
        );
        trace.top--;
        parent_node = traverse_node;
        free(traverse_node);
        traverse_node = NULL;
      } else {
        traverse_node = traverse_node->right;
      }
    }
  }
}

int main() {
  int data, option, sub_option;

  printf("\033[35;01mBinary Search Tree\033[00m\n1 - Insert\n2 - Delete\n3 - Search\n4 - Display\n\
  1 - In-order\n  2 - Pre-order\n  3 - Post-order\n  4 - Level-order\n5 - Exit\n");
  while (1) {
    printf("\nEnter option: ");
    scanf("%d", &option);

    switch (option) {
      case 1:
        printf("Enter data: ");
        scanf("%d", &data);

        insert(data);
        break;
      case 2:
        printf("Enter data: ");
        scanf("%d", &data);

        delete(data);
        break;
      case 3:
        printf("Enter search key: ");
        scanf("%d", &data);

        printf("Found at: %p\n", search(data));
        break;
      case 4:
        printf("Enter sub-option: ");
        scanf("%d", &sub_option);

        switch (sub_option) {
          case 1:
            inorder();
            break;
          case 2:
            preorder();
            break;
          case 3:
            postorder();
            break;
          case 4:
            levelorder();
            break;
          default:
            printf("\033[31;01mError:\033[00m Invalid sub-option.\n");
        }
        break;
      case 5:
        exit_handler();
        printf("Exit\n");
        return 0;
      default:
        printf("\033[31;01mError:\033[00m Invalid option.\n");
    }
  }
}
