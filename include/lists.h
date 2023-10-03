#ifndef rickclib_lists_h
#define rickclib_lists_h

#include "../include/common.h"

// Function Pointer for custom printing function for printing items
typedef void (*print_func)(void *);

// --------------------- Dynamic List ---------------------

typedef struct DynamicList {
  size_t count;
  size_t capacity;
  void *data;
  size_t typeSize;
} DynamicList;

// Init
DynamicList *dlist_new(size_t typeSize);

// Operations
void *dlist_get(DynamicList *list, int index);
void *dlist_pop(DynamicList *list);
void dlist_remove(DynamicList *list, int index);
void dlist_append(DynamicList *list, void *value);
void dlist_reverse(DynamicList *list);

// Printing
void dlist_print(DynamicList *list, print_func printer);

// Freeing
void dlist_kill(DynamicList *list);

// --------------------- Linked List ---------------------

typedef struct Node {
  void *data;
  struct Node *next;
} Node;

typedef struct LinkedList {
  Node *head;
  Node *tail;
  int length;
  size_t typeSize;
} LinkedList;

// Init
LinkedList *llist_new(size_t typeSize);

// Operations
void *llist_pop(LinkedList *list);
void llist_remove(LinkedList *list, void *value);
void llist_insert_end(LinkedList *list, void *value);
void llist_insert_start(LinkedList *list, void *value);
void llist_insert_after(LinkedList *list, Node *node, void *value);
void llist_insert_sorted(LinkedList *list, void *value);
void llist_add_all(LinkedList *result, LinkedList *add);
void llist_reverse(LinkedList *list);

// Printing
void llist_print(LinkedList *list, print_func printer);

// Freeing
void llist_kill(LinkedList *list);

// --------------------- Stack ---------------------

typedef struct Stack {
  int length;
  size_t typeSize;
  DynamicList *list;
} Stack;

// Init
Stack *stack_new(size_t typeSize);

// Operations
void *stack_pop(Stack *stack);
void stack_push(Stack *stack, void *value);

// Printing
void stack_print(Stack *stack, print_func printer);

// Freeing
void stack_kill(Stack *stack);

// --------------------- Queue ---------------------

typedef struct Queue {
  int length;
  size_t typeSize;
  LinkedList *list;
} Queue;

// Init
Queue *queue_new(size_t typeSize);

// Operations
void *queue_dequeue(Queue *queue);
void queue_enqueue(Queue *queue, void *value);
bool queue_empty(Queue *queue);

// Printing
void queue_print(Queue *queue, print_func printer);

// Freeing
void queue_kill(Queue *queue);

#endif
