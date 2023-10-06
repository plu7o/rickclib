#ifndef rickclib_trees_h
#define rickclib_trees_h

#include "../include/common.h"
#include "../include/lists.h"
#include <limits.h>

// --------------------- Binary Tree ---------------------

typedef enum uniontype { TYPE_CHAR, TYPE_INT, TYPE_STRING } DataType;

typedef struct BinaryNode {
  union {
    int intValue;
    char charValue;
    char *stringValue;
  } data;
  DataType type;
  struct BinaryNode *left;
  struct BinaryNode *right;
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
int btree_sum_recursive(BinaryTree *tree);
int btree_sum(BinaryTree *tree);
bool btree_includes(BinaryTree *tree, char letter);
bool btree_include_recursive(BinaryTree *tree, char target);
void btree_delete(BinaryTree *tree, char value);

// Printing
void btree_print(BinaryTree *tree);
void print_binary_node(void *data);

// Freeing
void btree_kill(BinaryTree *tree);

#endif
