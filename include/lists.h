#ifndef rickclib_lists_h
#define rickclib_lists_h

#include "../include/common.h"

#define GROW_CAPACITY(capacity) ((capacity) < 8 ? 8 : (capacity)*2)

typedef struct {
  int count;
  int capacity;
  int *data;
} List;

List *newList();
int getList(List *list, int index);
void addList(List *list, int value);
void addAllList(List *list, int *values, int size);
int popList(List *list);
void removeList(List *list, int index);
void killList(List *list);
void printList(List *list);

#endif
