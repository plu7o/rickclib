#include "../include/lists.h"
#include "../include/trees.h"

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

void btree_link(BinaryTree *tree, BinaryNode *parent, BinaryNode *child) {
  add(parent, child, child->data);
}

BinaryNode *btree_insert(BinaryTree *tree, char value) {
  BinaryNode *new_node = malloc(sizeof(BinaryNode));
  check_allocated(new_node);
  new_node->data = value;
  new_node->left = NULL;
  new_node->right = NULL;

  if (tree->root == NULL) {
    tree->root = new_node;
    tree->total++;
    return new_node;
  }

  BinaryNode *root = tree->root;
  add(root, new_node, value);
  return new_node;
}

void btree_delete(BinaryTree *tree, char value) {}

void print_binary_node(void *data) {
  BinaryNode *node = (BinaryNode *)data;
  printf("%p Value: %c, Left: %p, Right: %p}\n", node, node->data, node->left,
         node->right);
}

LinkedList *btree_depthf_traverse(BinaryTree *tree) {
  if (tree->root == NULL) {
    return NULL;
  }

  LinkedList *result = llist_new(sizeof(BinaryNode));
  LinkedList *stack = llist_new(sizeof(BinaryNode));
  llist_push(stack, tree->root);

  while (stack->length > 0) {
    BinaryNode *current = (BinaryNode *)llist_pop(stack);
    llist_push(result, current);

    if (current->right) {
      llist_push(stack, current->right);
    }
    if (current->left) {
      llist_push(stack, current->left);
    }

    free(current);
    current = NULL;
  }
  llist_kill(stack);
  return result;
}

void btree_kill(BinaryTree *tree) { free(tree); }
void print_tree(BinaryTree *tree) {}
