#ifndef rickclib_lists_h
#define rickclib_lists_h

#include "../include/common.h"

// --- Dynamic List ---
typedef struct List {
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

// --- Linked List ---
typedef struct Node {
  int data;
  struct Node *next;
} Node;

typedef struct LinkedList {
  Node *head;
  Node *tail;
  int length;
} LinkedList;

LinkedList *llist_new();
void llist_insert_end(LinkedList *list, int value);
void llist_insert_after(LinkedList *list, Node *node, int value);
void llist_insert_start(LinkedList *list, int value);
void llist_insert_sorted(LinkedList *list, int value);
void llist_reverse(LinkedList *list);
void llist_remove(LinkedList *list, int value);
void llist_print(LinkedList *list);
void llist_kill(LinkedList *list);

#endif
