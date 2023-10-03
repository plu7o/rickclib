#include "../../include/lists.h"
#include "../../include/memory.h"
#include "../../include/trees.h"
#include <stdbool.h>

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

DynamicList *btree_depth_first(BinaryTree *tree) {
  DynamicList *result = dlist_new(sizeof(BinaryNode));
  if (tree->root == NULL) {
    return result;
  }

  Stack *stack = stack_new(sizeof(BinaryNode));
  stack_push(stack, tree->root);

  while (stack->length > 0) {
    BinaryNode *current = (BinaryNode *)stack_pop(stack);
    dlist_append(result, current);

    if (current->right) {
      stack_push(stack, current->right);
    }
    if (current->left) {
      stack_push(stack, current->left);
    }

    free(current);
    current = NULL;
  }
  stack_kill(stack);
  return result;
}

LinkedList *recursive_depth_first(BinaryNode *root) {
  LinkedList *result = llist_new(sizeof(BinaryNode));
  if (root == NULL) {
    return result;
  }

  llist_insert_end(result, root);
  LinkedList *left = recursive_depth_first(root->left);
  LinkedList *right = recursive_depth_first(root->right);

  llist_add_all(result, left);
  llist_add_all(result, right);
  llist_kill(left);
  llist_kill(right);

  return result;
}

LinkedList *btree_depth_first_recursive(BinaryTree *tree) {
  LinkedList *result = recursive_depth_first(tree->root);
  return result;
}

DynamicList *btree_bredth_first(BinaryTree *tree) {
  DynamicList *result = dlist_new(sizeof(BinaryNode));
  if (tree->root == NULL) {
    return result;
  }

  Queue *queue = queue_new(sizeof(BinaryNode));
  queue_enqueue(queue, tree->root);

  while (queue->length > 0) {
    BinaryNode *current = (BinaryNode *)queue_dequeue(queue);
    dlist_append(result, current);

    if (current->left != NULL) {
      queue_enqueue(queue, current->left);
    }
    if (current->right != NULL) {
      queue_enqueue(queue, current->right);
    }
    free(current);
  }
  queue_kill(queue);

  return result;
}

bool btree_includes(BinaryTree *tree, char letter) {
  if (tree->root == NULL) {
    return false;
  }

  Queue *queue = queue_new(sizeof(BinaryNode));
  queue_enqueue(queue, tree->root);

  while (queue->length > 0) {
    BinaryNode *current = (BinaryNode *)queue_dequeue(queue);
    if (letter == current->data) {
      free(current);
      queue_kill(queue);
      return true;
    }

    if (current->left != NULL) {
      queue_enqueue(queue, current->left);
    }
    if (current->right != NULL) {
      queue_enqueue(queue, current->right);
    }
    free(current);
  }
  queue_kill(queue);

  return false;
}

bool recursive_includes(BinaryNode *root, char target) {
  bool result;

  if (root == NULL) {
    return false;
  }

  if (root->data == target) {
    return true;
  }

  bool left = recursive_includes(root->left, target);
  bool right = recursive_includes(root->right, target);

  return left || right;
}

bool btree_include_recursive(BinaryTree *tree, char target) {
  bool result = recursive_includes(tree->root, target);
  return result;
}

void btree_kill(BinaryTree *tree) {
  free(tree->root);
  free(tree);
  tree = NULL;
}

void print_binary_node(void *data) {
  BinaryNode *node = (BinaryNode *)data;
  printf("%p Value: %c, Left: %p, Right: %p}\n", node, node->data, node->left,
         node->right);
}

void print_tree(BinaryTree *tree) {}
