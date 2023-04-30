/*
 * Author: Sakthi Santhosh
 * Created on: 29/01/2023
 *
 * Header File - Binary Tree
 */
#ifndef TREE_H
# define TREE_H

typedef struct Node {
  int data;
  struct Node *left;
  struct Node *right;
} Node;

struct Node *bst_insert(struct Node *, int);

struct Node *bst_search(struct Node *, int);

struct Node *bst_delete(struct Node *, int);

void bst_inorder(struct Node *);

void bst_preorder(struct Node *);

void bst_postorder(struct Node *);

void bst_exit_handler(struct Node *);

#endif // TREE_H
