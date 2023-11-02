#ifndef rickclib_lists_h
#define rickclib_lists_h

#include "../include/common.h"

// Function Pointer for custom printing function for printing items
typedef void (*callback_func)(void *);
typedef bool (*operation_func)(void *, void *);

// --------------------- Dynamic List ---------------------

typedef struct DynamicList {
  size_t length;
  size_t capacity;
  size_t typeSize;
  void *data;
} DynamicList;

// Init
DynamicList *DynList_new(size_t typeSize);

// Operations
void *DynList_get(DynamicList *list, size_t index);
void *DynList_pop(DynamicList *list);
void DynList_set(DynamicList *list, size_t index, void *value);
void DynList_remove(DynamicList *list, size_t index);
void DynList_append(DynamicList *list, void *value);
bool DynList_is_empty(DynamicList *list);
void DynList_reverse(DynamicList *list);

// Printing
void DynList_print(DynamicList *list, callback_func printer);

// Freeing
void DynList_kill(DynamicList *list);

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
LinkedList *LinkList_new(size_t typeSize);

// Operations
void *LinkList_pop(LinkedList *list);
void LinkList_remove(LinkedList *list, void *value);
void LinkList_insert_end(LinkedList *list, void *value);
void LinkList_insert_start(LinkedList *list, void *value);
void LinkList_insert_after(LinkedList *list, Node *node, void *value);
void LinkList_insert_sorted(LinkedList *list, void *value,
                            operation_func comparitor);
void LinkList_add_all(LinkedList *result, LinkedList *add);
void LinkList_reverse(LinkedList *list);
bool LinkList_find_loop(LinkedList *list);
int LinkList_count_iter(LinkedList *list);
int LinkList_count(Node *node);

// Printing
void LinkList_print(LinkedList *list, callback_func printer);

// Freeing
void LinkList_kill(LinkedList *list);

// --------------------- Double Linked List ---------------------

typedef struct DNode {
  void *data;
  struct DNode *next;
  struct DNode *prev;
} DNode;

typedef struct DLinkedList {
  DNode *head;
  DNode *tail;
  int length;
  size_t typeSize;
} DLinkedList;

// Init
DLinkedList *DLinkList_new(size_t typeSize);

// Operations
void *DLinkList_pop(DLinkedList *list);
void DLinkList_remove(DLinkedList *list, void *value);
void DLinkList_insert_end(DLinkedList *list, void *value);
void DLinkList_insert_start(DLinkedList *list, void *value);
void DLinkList_insert_after(DLinkedList *list, DNode *node, void *value);
void DLinkList_insert_sorted(DLinkedList *list, void *value,
                             operation_func comparitor);
void DLinkList_add_all(DLinkedList *result, DLinkedList *add);
void DLinkList_reverse(DLinkedList *list);
bool DLinkList_find_loop(DLinkedList *list);
int DLinkList_count_iter(DLinkedList *list);
int DLinkList_count(Node *node);

// Printing
void LinkList_print(LinkedList *list, callback_func printer);

// Freeing
void LinkList_kill(LinkedList *list);

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
void stack_print(Stack *stack, callback_func printer);

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
void queue_print(Queue *queue, callback_func printer);

// Freeing
void queue_kill(Queue *queue);

#endif
