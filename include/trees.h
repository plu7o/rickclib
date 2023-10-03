#ifndef rickclib_trees_h
#define rickclib_trees_h

#include "../include/common.h"
#include "../include/lists.h"

// --------------------- Binary Tree ---------------------

typedef struct BinaryNode {
  struct BinaryNode *left;
  struct BinaryNode *right;
  char data;
} BinaryNode;

typedef struct BinaryTree {
  BinaryNode *root;
  int total;
} BinaryTree;


// Init
BinaryTree *btree_new();

// Operations
BinaryNode *btree_insert(BinaryTree *tree, char value);
DynamicList *btree_traverse_depth_first(BinaryTree *tree);
LinkedList *btree_traverse_depth_first_R(BinaryTree *tree);
void btree_delete(BinaryTree *tree, char value);

// Printing
void print_tree(BinaryTree *tree);
void print_binary_node(void *data);

// Freeing
void btree_kill(BinaryTree *tree);

#endif
