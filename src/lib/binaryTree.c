#include "../../include/lists.h"
#include "../../include/memory.h"
#include "../../include/trees.h"

BinaryTree *btree_new() {
  BinaryTree *tree = malloc(sizeof(BinaryTree));
  check_allocated(tree, "Memory allocation failed during Initilizing.\n");

  tree->root = NULL;
  tree->total = 0;

  return tree;
}

void add_sorted(BinaryNode *node, BinaryNode *new_node, char value) {
  if (value < node->data) {
    if (node->left != NULL) {
      add_sorted(node->left, new_node, value);
    } else {
      printf("insert left: %c\n", value);
      node->left = new_node;
    }
  } else if (value > node->data) {
    if (node->right != NULL) {
      add_sorted(node->right, new_node, value);
    } else {
      printf("insert right: %c\n", value);
      node->right = new_node;
    }
  }
}

BinaryNode *btree_insert(BinaryTree *tree, char value) {
  BinaryNode *new_node = malloc(sizeof(BinaryNode));
  check_allocated(new_node,
                  "Memory allocation failed while inserting new Node.\n");
  new_node->data = value;
  new_node->left = NULL;
  new_node->right = NULL;

  if (tree->root == NULL) {
    tree->root = new_node;
    tree->total++;
    return new_node;
  }

  BinaryNode *root = tree->root;
  add_sorted(root, new_node, value);
  return new_node;
}

void btree_delete(BinaryTree *tree, char value) {}

DynamicList *btree_traverse_depth_first(BinaryTree *tree) {
  DynamicList *result = dlist_new(sizeof(BinaryNode));
  if (tree->root == NULL) {
    return result;
  }

  DynamicList *stack = dlist_new(sizeof(BinaryNode));
  dlist_append(stack, tree->root);

  while (stack->count > 0) {
    BinaryNode *current = (BinaryNode *)dlist_pop(stack);
    dlist_append(result, current);

    if (current->right) {
      dlist_append(stack, current->right);
    }
    if (current->left) {
      dlist_append(stack, current->left);
    }

    free(current);
    current = NULL;
  }
  dlist_kill(stack);
  return result;
}

LinkedList *traverse_depth_first_R(BinaryNode *root) {
  LinkedList *result = llist_new(sizeof(BinaryNode));
  if (root == NULL) {
    return result;
  }

  llist_insert_end(result, root);
  LinkedList *left = traverse_depth_first_R(root->left);
  LinkedList *right = traverse_depth_first_R(root->right);

  llist_add_all(result, left);
  llist_add_all(result, right);
  llist_kill(left);
  llist_kill(right);

  return result;
}

LinkedList *btree_traverse_depth_first_R(BinaryTree *tree) {
  LinkedList *result = traverse_depth_first_R(tree->root);
  return result;
}

void btree_kill(BinaryTree *tree) { free(tree); }

void print_binary_node(void *data) {
  BinaryNode *node = (BinaryNode *)data;
  printf("%p Value: %c, Left: %p, Right: %p}\n", node, node->data, node->left,
         node->right);
}

void print_tree(BinaryTree *tree) {}
