/*
 * Author: Sakthi Santhosh
 * Created on: 29/01/2023
 *
 * Binary Search Tree Implementation
 */
#include <stdio.h>
#include <stdlib.h>

#include "./bst.h"

Node *bst_insert(Node *root_node, int data) {
  if (root_node == NULL) {
    root_node = (Node *) malloc(sizeof(struct Node));
    root_node->data = data;
    root_node->left = NULL;
    root_node->right = NULL;
    return root_node;
  }

  if (data > root_node->data) {
    root_node->right = bst_insert(root_node->right, data);
  } else {
    root_node->left = bst_insert(root_node->left, data);
  }
  return root_node;
}

static Node *bst_get_inorder_successor(Node *root_node) {
  if (root_node == NULL)
    return NULL;

  Node *temp_node = root_node->right;

  while (temp_node->left != NULL) {
    temp_node = temp_node->left;
  }
  return temp_node;
}

Node *bst_delete(Node *root_node, int data) {
  if (root_node == NULL)
    return NULL;

  if (data > root_node->data) {
    root_node->right = bst_delete(root_node->right, data);
  } else if (data < root_node->data) {
    root_node->left = bst_delete(root_node->left, data);
  } else {
    Node *temp_node;

    if (root_node->left == NULL) {
      temp_node = root_node->right;
      free(root_node);
      return temp_node;
    } else if (root_node->right == NULL) {
      temp_node = root_node->left;
      free(root_node);
      return temp_node;
    }

    temp_node = bst_get_inorder_successor(root_node);
    root_node->data = temp_node->data;
    root_node->right = bst_delete(root_node->right, temp_node->data);
  }
  return root_node;
}

void bst_inorder(Node *root_node) {
  if (root_node == NULL)
      return;

  bst_inorder(root_node->left);
  printf("%d ", root_node->data);
  bst_inorder(root_node->right);
}

void bst_preorder(Node *root_node) {
  if (root_node == NULL)
    return;

  printf("%d ", root_node->data);
  bst_preorder(root_node->left);
  bst_preorder(root_node->right);
}

void bst_postorder(Node *root_node) {
  if (root_node == NULL)
    return;

  bst_postorder(root_node->left);
  bst_postorder(root_node->right);
  printf("%d ", root_node->data);
}

Node *bst_search(Node *root_node, int data) {
  if (root_node == NULL || root_node->data == data)
    return root_node;

  if (data > root_node->data) {
    return bst_search(root_node->right, data);
  } else {
    return bst_search(root_node->left, data);
  }
}

void bst_exit_handler(Node *root_node) {
  if (root_node == NULL)
    return;

  bst_exit_handler(root_node->left);
  bst_exit_handler(root_node->right);
  free(root_node);
}
