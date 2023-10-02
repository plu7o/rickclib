#ifndef rickclib_trees_h
#define rickclib_trees_h

#include "../include/common.h"

typedef struct BinaryNode {
  struct BinaryNode *left;
  struct BinaryNode *right;
  char data;
} BinaryNode;

typedef struct BinaryTree {
  struct BinaryNode *root;
  int total;
} BinaryTree;

BinaryTree *btree_new();
void btree_insert(BinaryTree *tree, char value);
void btree_delete(BinaryTree *tree, char value);
void btree_depthf_traverse(BinaryTree *tree);
void btree_kill(BinaryTree *tree);
void print_tree(BinaryTree *tree);

#endif
