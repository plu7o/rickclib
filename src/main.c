#include "../include/lists.h"
#include "../include/trees.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

void print_int(void *data) {
  int num = *(int *)data;
  printf("%d ", num);
}

void test_dynamic_list() {
  printf("\n--- LIST ---\n");

  printf("INIT\n");
  DynamicList *list = DynList_new(sizeof(int));
  DynList_print(list, print_int);

  printf("APPEDNING ITEMS\n");
  for (int i = 0; i < 30; i++) {
    DynList_append(list, &i);
  }
  DynList_print(list, print_int);
  assert(list->length == 30);

  printf("GETTING ITEM\n");
  int *result = (int *)DynList_get(list, 0);
  printf("= %d\n", *result);
  DynList_print(list, print_int);
  assert(*result == 0);

  printf("POPPING ITEM\n");
  int *num = (int *)DynList_pop(list);
  printf("= %d\n", *num);
  DynList_print(list, print_int);
  assert(*num == 29);
  free(num);

  printf("SETTING ITEM\n");
  int number = 100;
  DynList_set(list, 0, &number);
  DynList_print(list, print_int);
  assert(*(int *)DynList_get(list, 0) == number);

  printf("REMOVING ITEMS\n");
  for (int i = 0; i < 25; i++) {
    DynList_remove(list, 0);
  }
  DynList_print(list, print_int);
  assert(list->length == 4);

  printf("REVERSING LIST\n");
  DynList_reverse(list);
  DynList_print(list, print_int);

  printf("IS EMPTY?\n");
  bool yesorno = DynList_is_empty(list);
  printf("= %s\n", yesorno ? "TRUE" : "FALSE");
  assert(yesorno == false);

  printf("FREEING MEMORY\n");
  DynList_kill(list);
  printf("\n");
}

void test_linked_list() {

  printf("\n--- LINKED LIST ---\n");

  LinkedList *list = LinkList_new(sizeof(int));

  printf("Empty List\n");
  LinkList_print(list, print_int);

  printf("Inserting at End\n");
  for (int i = 0; i < 15; i++) {
    LinkList_insert_end(list, &i);
  }
  LinkList_print(list, print_int);

  printf("Inserting at Start\n");
  for (int i = 16; i < 30; i++) {
    LinkList_insert_start(list, &i);
  }
  // LinkList_insert_sorted(list, &values[2]);
  LinkList_print(list, print_int);

  printf("Poppinng Value\n");
  int *value = (int *)LinkList_pop(list);
  printf("%d\n", *value);
  free(value);
  LinkList_print(list, print_int);

  printf("Reversed\n");
  LinkList_reverse(list);
  LinkList_print(list, print_int);

  printf("Freeing memory\n");
  LinkList_kill(list);

  printf("\n");
}

void test_binary_tree() {
  printf("\n--- Binary Tree ---\n");

  BinaryTree *tree = btree_new();

  BinaryNode *a = malloc(sizeof(BinaryNode));
  a->data.charValue = 'a';
  a->right = NULL;
  a->left = NULL;
  a->type = TYPE_CHAR;

  BinaryNode *b = malloc(sizeof(BinaryNode));
  b->data.charValue = 'b';
  b->right = NULL;
  b->left = NULL;
  b->type = TYPE_CHAR;

  BinaryNode *c = malloc(sizeof(BinaryNode));
  c->data.charValue = 'c';
  c->right = NULL;
  c->left = NULL;
  c->type = TYPE_CHAR;

  BinaryNode *d = malloc(sizeof(BinaryNode));
  d->data.charValue = 'd';
  d->right = NULL;
  d->left = NULL;
  d->type = TYPE_CHAR;

  BinaryNode *e = malloc(sizeof(BinaryNode));
  e->data.charValue = 'e';
  e->right = NULL;
  e->left = NULL;
  e->type = TYPE_CHAR;

  BinaryNode *f = malloc(sizeof(BinaryNode));
  f->data.charValue = 'f';
  f->right = NULL;
  f->left = NULL;
  f->type = TYPE_CHAR;

  a->left = b;
  a->right = c;
  b->left = d;
  b->right = e;
  c->right = f;

  tree->root = a;

  DynamicList *result = (DynamicList *)btree_depth_first(tree);
  DynList_print(result, print_binary_node);
  DynList_kill(result);

  LinkedList *result1 = (LinkedList *)btree_depth_first_recursive(tree);
  LinkList_print(result1, print_binary_node);
  LinkList_kill(result1);

  DynamicList *result2 = (DynamicList *)btree_bredth_first(tree);
  DynList_print(result2, print_binary_node);
  DynList_kill(result2);

  char probe = 'a';
  bool result3 = btree_includes(tree, probe);
  printf("Is letter: %c in TREE ?: %s\n", probe, result3 ? "True" : "False");
  bool result4 = btree_include_recursive(tree, probe);
  printf("Is letter: %c in TREE ?: %s\n", probe, result3 ? "True" : "False");

  a->data.intValue = 3;
  a->type = TYPE_INT;
  b->data.intValue = 9;
  b->type = TYPE_INT;
  c->data.intValue = 2;
  c->type = TYPE_INT;
  d->data.intValue = 4;
  d->type = TYPE_INT;
  e->data.intValue = 5;
  e->type = TYPE_INT;
  f->data.intValue = 2;
  f->type = TYPE_INT;

  int result5 = btree_sum(tree);
  printf("sum: %d\n", result5);
  int result6 = btree_sum_recursive(tree);
  printf("sum: %d\n", result6);

  int result7 = btree_minimum(tree);
  printf("minimum: %d\n", result7);
  int result8 = btree_minimum_recursive(tree);
  printf("minimum: %d\n", result8);
  int result9 = btree_max_rl_path_recursive(tree);
  printf("Max Path: %d\n", result9);

  btree_print(tree);
  btree_kill(tree);

  printf("\n");
}

int main(int argc, const char *argv[]) {
  test_dynamic_list();
  test_linked_list();
  test_binary_tree();
  return 0;
}
