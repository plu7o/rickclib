#include "../include/lists.h"

void test_dynamic_list() {
  printf("--- LIST ---\n");

  List *list = newList();
  printList(list);

  int values[] = {13, 14, 15, 16, 17};
  int size = sizeof(values) / sizeof(int);

  addAllList(list, values, size);
  addList(list, 1);
  addList(list, 2);
  addList(list, 3);
  addList(list, 4);
  addList(list, 5);
  addList(list, 6);
  addList(list, 7);
  addList(list, 8);
  addList(list, 9);
  addList(list, 10);
  addList(list, 11);
  addList(list, 12);

  printList(list);
  popList(list);
  popList(list);
  popList(list);
  popList(list);
  printList(list);
  removeList(list, 5);
  printList(list);
  getList(list, 5);

  killList(list);
  printf("\n--- --- ---\n");
}

void test_linked_list() {
  printf("--- LINKED LIST ---\n");
  LinkedList *list = llist_new();

  llist_insert_end(list, 7);
  llist_insert_end(list, 8);
  llist_insert_end(list, 9);
  llist_insert_end(list, 10);
  llist_insert_start(list, 3);
  llist_insert_start(list, 2);
  llist_insert_start(list, 1);
  llist_insert_sorted(list, 11);
  llist_remove(list, 3);
  llist_remove(list, 1);
  llist_reverse(list);

  llist_print(list);

  llist_kill(list);
  printf("\n--- --- ---\n");
}

int main(int argc, const char *argv[]) {
  // test_dynamic_list();
  test_linked_list();

  return 0;
}
