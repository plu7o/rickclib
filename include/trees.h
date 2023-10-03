#ifndef rickclib_trees_h
#define rickclib_trees_h

#include "../include/common.h"
#include "../include/lists.h"

typedef struct BinaryNode {
  struct BinaryNode *left;
  struct BinaryNode *right;
  char data;
} BinaryNode;

typedef struct BinaryTree {
  BinaryNode *root;
  int total;
} BinaryTree;

BinaryTree *btree_new();
BinaryNode *btree_insert(BinaryTree *tree, char value);
LinkedList *btree_depthf_traverse(BinaryTree *tree);
void btree_delete(BinaryTree *tree, char value);
void btree_link(BinaryTree *tree, BinaryNode *parent, BinaryNode *child);
void btree_kill(BinaryTree *tree);
void print_tree(BinaryTree *tree);
void print_binary_node(void *data);
#endif
