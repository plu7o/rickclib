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
DynamicList *btree_depth_first(BinaryTree *tree);
DynamicList *btree_bredth_first(BinaryTree *tree);
LinkedList *btree_depth_first_recursive(BinaryTree *tree);
bool btree_includes(BinaryTree *tree, char letter);
bool btree_include_recursive(BinaryTree *tree, char target);
void btree_delete(BinaryTree *tree, char value);

// Printing
void print_tree(BinaryTree *tree);
void print_binary_node(void *data);

// Freeing
void btree_kill(BinaryTree *tree);

#endif
