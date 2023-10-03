#include "../include/lists.h"
#include "../include/trees.h"
#include <stdio.h>
#include <stdlib.h>

void print_int(void *data) {
  int num = *(int *)data;
  printf("%d ", num);
}

void test_dynamic_list() {
  printf("\n--- LIST ---\n");

  DynamicList *list = dlist_new(sizeof(int));
  dlist_print(list, print_int);

  for (int i = 0; i < 30; i++) {
    dlist_append(list, &i);
  }
  dlist_print(list, print_int);

  int *num = (int *)dlist_pop(list);
  printf("pop: %d\n", *num);
  free(num);
  dlist_print(list, print_int);

  for (int i = 0; i < 25; i++) {
    dlist_remove(list, 0);
  }
  dlist_print(list, print_int);

  dlist_reverse(list);
  dlist_print(list, print_int);

  int result = *(int *)dlist_get(list, 0);

  dlist_kill(list);
  printf("\n");
}

void test_linked_list() {

  printf("\n--- LINKED LIST ---\n");

  LinkedList *list = llist_new(sizeof(int));

  printf("Empty List\n");
  llist_print(list, print_int);

  printf("Inserting at End\n");
  for (int i = 0; i < 15; i++) {
    llist_insert_end(list, &i);
  }
  llist_print(list, print_int);

  printf("Inserting at Start\n");
  for (int i = 16; i < 30; i++) {
    llist_insert_start(list, &i);
  }
  // llist_insert_sorted(list, &values[2]);
  llist_print(list, print_int);

  printf("Poppinng Value\n");
  int *value = (int *)llist_pop(list);
  printf("%d\n", *value);
  free(value);
  llist_print(list, print_int);

  printf("Reversed\n");
  llist_reverse(list);
  llist_print(list, print_int);

  printf("Freeing memory\n");
  llist_kill(list);

  printf("\n");
}

void test_binary_tree() {
  printf("\n--- Binary Tree ---\n");

  BinaryTree *tree = btree_new();

  BinaryNode *a = malloc(sizeof(BinaryNode));
  a->data = 'a';
  a->right = NULL;
  a->left = NULL;

  BinaryNode *b = malloc(sizeof(BinaryNode));
  b->data = 'b';
  b->right = NULL;
  b->left = NULL;

  BinaryNode *c = malloc(sizeof(BinaryNode));
  c->data = 'c';
  c->right = NULL;
  c->left = NULL;

  BinaryNode *d = malloc(sizeof(BinaryNode));
  d->data = 'd';
  d->right = NULL;
  d->left = NULL;

  BinaryNode *e = malloc(sizeof(BinaryNode));
  e->data = 'e';
  e->right = NULL;
  e->left = NULL;

  BinaryNode *f = malloc(sizeof(BinaryNode));
  f->data = 'f';
  f->right = NULL;
  f->left = NULL;

  a->left = b;
  a->right = c;
  b->left = d;
  b->right = e;
  c->right = f;

  tree->root = a;

  DynamicList *result = (DynamicList *)btree_depth_first(tree);
  dlist_print(result, print_binary_node);
  dlist_kill(result);

  LinkedList *result1 = (LinkedList *)btree_depth_first_recursive(tree);
  llist_print(result1, print_binary_node);
  llist_kill(result1);

  DynamicList *result2 = (DynamicList *)btree_bredth_first(tree);
  dlist_print(result2, print_binary_node);
  dlist_kill(result2);

  char probe = 'a';
  bool result3 = btree_includes(tree, probe);
  printf("Is letter: %c in TREE ?: %s\n", probe, result3 ? "True" : "False");
  bool result4 = btree_include_recursive(tree, probe);
  printf("Is letter: %c in TREE ?: %s\n", probe, result3 ? "True" : "False");

  btree_kill(tree);

  printf("\n");
}

int main(int argc, const char *argv[]) {
  test_dynamic_list();
  test_linked_list();
  test_binary_tree();
  return 0;
}
