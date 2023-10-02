#include "../include/lists.h"
#include "../include/trees.h"
#include <stdio.h>

BinaryTree *btree_new() {
  BinaryTree *tree = malloc(sizeof(BinaryTree));
  check_allocated(tree);

  tree->root = NULL;
  tree->total = 0;

  return tree;
}

void add(BinaryNode *node, BinaryNode *new_node, char value) {
  if (value < node->data) {
    if (node->left != NULL) {
      add(node->left, new_node, value);
    } else {
      printf("insert left: %c\n", value);
      node->left = new_node;
    }
  } else if (value > node->data) {
    if (node->right != NULL) {
      add(node->right, new_node, value);
    } else {
      printf("insert right: %c\n", value);
      node->right = new_node;
    }
  }
}

void btree_insert(BinaryTree *tree, char value) {
  BinaryNode *new_node = malloc(sizeof(BinaryNode));
  check_allocated(new_node);
  new_node->data = value;
  new_node->left = NULL;
  new_node->right = NULL;

  if (tree->root == NULL) {
    tree->root = new_node;
    tree->total++;
    return;
  }

  BinaryNode *root = tree->root;
  add(root, new_node, value);
}

void btree_delete(BinaryTree *tree, char value) {}

void btree_depthf_traverse(BinaryTree *tree) {
  LinkedList *stack = llist_new(sizeof(BinaryNode));
  llist_insert_end(stack, tree->root);

  while (stack->length > 0) {
    BinaryNode *current = (BinaryNode *)llist_pop(stack);
    printf("{%c, node: %p, left: %p, right: %p}\n", current->data, current, current->left,
           current->right);

    if (current->right) {
      llist_insert_end(stack, current->right);
    }

    if (current->left) {
      llist_insert_end(stack, current->left);
    }
    free(current);
  }
  llist_kill(stack);
}

void btree_kill(BinaryTree *tree) { free(tree); }
void print_tree(BinaryTree *tree) {}
