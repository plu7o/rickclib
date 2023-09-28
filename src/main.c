#include "../include/lists.h"

int main(int argc, const char *argv[]) {
  printf("--- LIST ---\n");

  List *list = newList();

  printList(list);
  int values[] = {1, 2, 3, 4, 5};
  int array_size = sizeof(values) / sizeof(int);

  addAllList(list, values, array_size);
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
  return 0;
}
