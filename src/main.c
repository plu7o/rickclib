#include "../include/lists.h"
#include "../include/trees.h"
#include <stdio.h>
#include <stdlib.h>

void test_dynamic_list() {
  printf("\n--- LIST ---\n");

  DynamicList *list = dlist_new();
  // dlist_print(list);

  // int values[] = {13, 14, 15, 16, 17};
  // int size = sizeof(values) / sizeof(int);

  // dlist_insert_array(list, values, size);
  // dlist_push(list, 1);
  // dlist_push(list, 2);
  // dlist_push(list, 3);
  // dlist_push(list, 4);
  // dlist_push(list, 5);
  // dlist_print(list);

  // dlist_pop(list);
  // dlist_print(list);

  // dlist_remove(list, 5);
  // dlist_print(list);

  // dlist_get(list, 0);

  // dlist_kill(list);
  printf("\n--- --- ---\n");
}

void print_int(void *data) {
  int num = *(int *)data;
  printf("%d\n", num);
}
void test_linked_list() {

  printf("\n--- LINKED LIST ---\n");
  LinkedList *list = llist_new(sizeof(int));

  int values[] = {1, 2, 3, 4, 5};

  llist_push(list, &values[0]);
  llist_push(list, &values[1]);
  llist_push(list, &values[2]);
  llist_push(list, &values[3]);
  llist_push(list, &values[4]);

  // llist_insert_sorted(list, &values[2]);
  // llist_remove(list, &values[1]);
  llist_print(list, print_int);

  int *value = (int *)llist_pop(list);
  printf("%d\n", *value);
  free(value);
  llist_print(list, NULL);

  llist_reverse(list);
  llist_print(list, NULL);

  llist_kill(list);

  printf("\n--- --- ---\n");
}

void test_binary_tree() {
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

  LinkedList *result = btree_depthf_traverse(tree);
  llist_print(result, print_binary_node);
  
  llist_kill(result);
  btree_kill(tree);
}

int main(int argc, const char *argv[]) {
  // test_dynamic_list();
  // test_linked_list();
  test_binary_tree();
  return 0;
}
