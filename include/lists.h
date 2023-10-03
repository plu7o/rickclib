#ifndef rickclib_lists_h
#define rickclib_lists_h

#include "../include/common.h"

// --- Dynamic List ---
typedef struct DynamicList {
  int count;
  int capacity;
  int *data;
} DynamicList;

DynamicList *dlist_new();
int dlist_get(DynamicList *list, int index);
int dlist_pop(DynamicList *list);
void dlist_push(DynamicList *list, int value);
void dlist_insert_array(DynamicList *list, int *values, int size);
void dlist_reverse(DynamicList *list);
void dlist_remove(DynamicList *list, int index);
void dlist_print(DynamicList *list);
void dlist_print_items(DynamicList *list);
void dlist_kill(DynamicList *list);

// --- Linked DynamicList ---
typedef struct Node {
  void *data;
  struct Node *next;
} Node;

typedef void (*print_func)(void *);
typedef struct LinkedList {
  Node *head;
  Node *tail;
  int length;
  size_t typeSize;
  print_func printData;
} LinkedList;

LinkedList *llist_new(size_t typeSize);
void *llist_pop(LinkedList *list);
void llist_push(LinkedList *list, void *value);
void llist_insert_after(LinkedList *list, Node *node, void *value);
void llist_insert_start(LinkedList *list, void *value);
void llist_insert_sorted(LinkedList *list, void *value);
void llist_reverse(LinkedList *list);
void llist_remove(LinkedList *list, void *value);
void llist_print(LinkedList *list, print_func printer);
void llist_kill(LinkedList *list);

#endif
