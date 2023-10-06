#include "../../include/lists.h"
#include "../../include/memory.h"
#include "../../include/trees.h"
#include <stdbool.h>
#include <stdlib.h>

BinaryTree *btree_new() {
  BinaryTree *tree = malloc(sizeof(BinaryTree));
  check_allocated(tree, "Memory allocation failed during Initilizing.\n");

  tree->root = NULL;
  tree->total = 0;

  return tree;
}

void traverse_before_tree(BinaryNode *root, callback_func func) {
  if (root == NULL) {
    return;
  }

  func(root);
  traverse_before_tree(root->left, func);
  traverse_before_tree(root->right, func);

  return;
}

void traverse_after_tree(BinaryNode *root, callback_func func) {
  if (root == NULL) {
    return;
  }

  traverse_after_tree(root->left, func);
  traverse_after_tree(root->right, func);
  return func(root);
}

int sum_nodes(BinaryNode *node) {
  return node->data.intValue + node->left->data.intValue +
         node->right->data.intValue;
}

void print_binary_node(void *data) {
  BinaryNode *node = (BinaryNode *)data;
  switch (node->type) {
  case TYPE_CHAR:
    printf("{TYPE: %d CHAR ", node->type);
    printf("%p Value: %c, Left: %p, Right: %p}\n", node, node->data.charValue,
           node->left, node->right);
    break;
  case TYPE_INT:
    printf("{TYPE: %d INT ", node->type);
    printf("%p Value: %d, Left: %p, Right: %p}\n", node, node->data.intValue,
           node->left, node->right);
    break;
  case TYPE_STRING:
    printf("{TYPE: %d STRING ", node->type);
    printf("%p Value: %s, Left: %p, Right: %p}\n", node, node->data.stringValue,
           node->left, node->right);
    break;
  default:
    printf("{TYPE: %d NULL ", node->type);
    printf("%p Value: %p, Left: %p, Right: %p}\n", node, NULL, node->left,
           node->right);
    break;
  }
}
void add_sorted(BinaryNode *node, BinaryNode *new_node, char value) {
  if (value < node->data.charValue) {
    if (node->left != NULL) {
      add_sorted(node->left, new_node, value);
    } else {
      printf("insert left: %c\n", value);
      node->left = new_node;
    }
  } else if (value > node->data.charValue) {
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
  new_node->data.charValue = value;
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
  DynamicList *result = DynList_new(sizeof(BinaryNode));
  if (tree->root == NULL) {
    return result;
  }

  Stack *stack = stack_new(sizeof(BinaryNode));
  stack_push(stack, tree->root);

  while (stack->length > 0) {
    BinaryNode *current = (BinaryNode *)stack_pop(stack);
    DynList_append(result, current);

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
  DynamicList *result = DynList_new(sizeof(BinaryNode));
  if (tree->root == NULL) {
    return result;
  }

  Queue *queue = queue_new(sizeof(BinaryNode));
  queue_enqueue(queue, tree->root);

  while (queue->length > 0) {
    BinaryNode *current = (BinaryNode *)queue_dequeue(queue);
    DynList_append(result, current);

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
    if (letter == current->data.charValue) {
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

  if (root->data.charValue == target) {
    return true;
  }

  return recursive_includes(root->left, target) || recursive_includes(root->right, target);

}

bool btree_include_recursive(BinaryTree *tree, char target) {
  bool result = recursive_includes(tree->root, target);
  return result;
}

int btree_sum(BinaryTree *tree) {
  if (tree->root == NULL) {
    return 0;
  }

  int sum;
  Queue *queue = queue_new(sizeof(BinaryNode));
  queue_enqueue(queue, tree->root);

  sum = 0;
  while (queue->length > 0) {
    BinaryNode *current = (BinaryNode *)queue_dequeue(queue);
    sum += current->data.intValue;

    if (current->left != NULL) {
      queue_enqueue(queue, current->left);
    }
    if (current->right != NULL) {
      queue_enqueue(queue, current->right);
    }
    free(current);
  }
  queue_kill(queue);
  return sum;
}

int depth_sum_recursive(BinaryNode *root) {
  if (root == NULL) {
    return 0;
  }

  return root->data.intValue + depth_sum_recursive(root->left) +
         depth_sum_recursive(root->right);
}

int btree_sum_recursive(BinaryTree *tree) {
  int result = depth_sum_recursive(tree->root);
  return result;
}

void btree_kill(BinaryTree *tree) {
  traverse_after_tree(tree->root, free);
  free(tree);
  tree = NULL;
}

void btree_print(BinaryTree *tree) {
  traverse_before_tree(tree->root, print_binary_node);
}
