#include "../include/lists.h"
#include "../include/trees.h"
#include <stdio.h>

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

void test_linked_list() {
  printf("\n--- LINKED LIST ---\n");
  LinkedList *list = llist_new(sizeof(int));

  int values[] = {1, 2, 3, 4, 5};

  llist_insert_end(list, &values[0]);
  llist_insert_end(list, &values[1]);
  llist_insert_end(list, &values[2]);
  llist_insert_end(list, &values[3]);
  llist_insert_end(list, &values[4]);

  // llist_insert_sorted(list, &values[2]);
  // llist_remove(list, &values[1]);
  llist_print(list);

  int *value = (int *)llist_pop(list);
  printf("%d\n", *value);
  free(value);
  llist_print(list);

  llist_reverse(list);
  llist_print(list);

  llist_kill(list);

  printf("\n--- --- ---\n");
}

void test_binary_tree() {
  BinaryTree *tree = btree_new();
  btree_insert(tree, 'a');
  btree_insert(tree, 'b');
  btree_insert(tree, 'c');
  btree_insert(tree, 'd');
  btree_insert(tree, 'e');
  btree_insert(tree, 'f');

  btree_depthf_traverse(tree);
}

int main(int argc, const char *argv[]) {
  // test_dynamic_list();
  // test_linked_list();
  test_binary_tree();
  return 0;
}
