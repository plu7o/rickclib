#include "../../include/lists.h"
#include "../../include/memory.h"

#include <string.h>

DLinkedList *DLinkList_new(size_t typeSize) {
  DLinkedList *list = (DLinkedList *)malloc(sizeof(DLinkedList));
  check_allocated(list, "Memory allocation failed during Initiliting\n");

  list->head = NULL;
  list->tail = NULL;
  list->length = 0;
  list->typeSize = typeSize;

  return list;
}

bool DLinkList_find_loop(DLinkedList *list) {
  DNode *slow = list->head;
  DNode *fast = list->head;

  while (slow != NULL && fast != NULL && fast->next != NULL) {
    slow = slow->next;
    fast = fast->next->next;

    if (slow == fast) {
      return true;
    }
  }

  return false;
}

int LinkList_count_iter(LinkedList *list) {
  int c = 0;
  for (Node *curr = list->head; curr != NULL; curr = curr->next) {
    c++;
  }
  return c;
}

int LinkList_count(Node *node) {
  if (node == NULL) {
    return 0;
  }

  return 1 + LinkList_count(node->next);
}

void *LinkList_pop(LinkedList *list) {
  if (list->head == NULL) {
    return NULL;
  }
  // Handle the case when there's only one node
  if (list->head->next == NULL) {
    void *data = list->head->data;
    free(list->head);
    list->head = NULL;
    list->tail = NULL;
    list->length--;
    return data;
  }

  Node *current = list->head;
  while (current->next && current->next->next != NULL) {
    current = current->next;
  }

  Node *to_remove = current->next;
  current->next = NULL;
  list->tail = current;
  list->length--;

  void *data = to_remove->data;
  free(to_remove);
  return data;
}

void LinkList_remove(LinkedList *list, void *value) {
  if (list->head == NULL) {
    return;
  }

  if (list->head->data == value) {
    Node *to_remove = list->head;
    list->head = list->head->next;
    list->length--;
    free(to_remove);
    return;
  }

  Node *current = list->head;
  while (current->next != NULL) {
    if (current->next->data == value) {
      Node *to_remove = current->next;
      current->next = current->next->next;
      list->length--;
      free(to_remove);
      return;
    }
    current = current->next;
  }
}

void DLinkList_insert_end(DLinkedList *list, void *value) {
  DNode *new_node = (DNode *)malloc(sizeof(DNode));
  check_allocated(new_node,
                  "Memory allocation failed during allocating new Node\n");

  new_node->data = malloc(list->typeSize);
  check_allocated(new_node->data,
                  "Memory allocation failed during allocating Data\n");
  memcpy(new_node->data, value, list->typeSize);

  new_node->next = NULL;

  if (list->head == NULL) {
    new_node->prev = NULL;
    list->head = new_node;
    list->tail = new_node;
    list->length++;
    return;
  }

  new_node->prev = list->tail;
  list->tail->next = new_node;
  list->tail = new_node;
  list->length++;
}

void DLinkList_insert_start(DLinkedList *list, void *value) {
  DNode *new_node = (DNode *)malloc(sizeof(DNode));
  check_allocated(new_node,
                  "Memory allocation failed during allocating new Node\n");

  new_node->data = malloc(list->typeSize);
  check_allocated(new_node->data,
                  "Memory allocation failed during allocating Data\n");
  memcpy(new_node->data, value, list->typeSize);

  list->head->prev = new_node;
  new_node->next = list->head;
  new_node->prev = NULL;
  list->head = new_node;
  list->length++;
}

void DLinkList_insert_after(DLinkedList *list, DNode *node, void *value) {
  DNode *new_node = (DNode *)malloc(sizeof(DNode));
  check_allocated(new_node,
                  "Memory allocation failed during allocating new Node\n");

  new_node->data = malloc(list->typeSize);
  check_allocated(new_node->data,
                  "Memory allocation failed during allocating Data\n");
  memcpy(new_node->data, value, list->typeSize);

  new_node->next = node->next;
  new_node->prev = node;
  node->next = new_node;

  if (new_node->next == NULL) {
    list->tail = new_node;
  }
  list->length++;
}

void DLinkList_add_all(DLinkedList *result, DLinkedList *add) {
  DNode *current = add->head;
  while (current != NULL) {
    DLinkList_insert_end(result, current->data);
    current = current->next;
  }
}

void DLinkList_insert_sorted(DLinkedList *list, void *value,
                             operation_func comparitor) {
  if (list->head == NULL || comparitor(list->head->data, value)) {
    DLinkList_insert_start(list, value);
    return;
  }

  DNode *current = list->head;
  while (current->next != NULL) {
    if (comparitor(current->next->data, value)) {
      break;
    }
    current = current->next;
  }
  DLinkList_insert_after(list, current, value);
}

void DLinkList_reverse(DLinkedList *list) {
  DNode *prev = NULL;
  DNode *current = list->head;
  list->tail = list->head;

  while (current != NULL) {
    DNode *next = current->next;
    current->next = prev;
    prev = current;
    current = next;
  }
  list->head = prev;
}

void DLinkList_print(DLinkedList *list, callback_func printer) {
  printf("[length: %d head: %p tail: %p]\n", list->length, list->head,
         list->tail);

  if (list->head == NULL) {
    printf("EMPTY []\n");
    return;
  }

  printf("Items: [ ");
  for (DNode *curr = list->head; curr != NULL; curr = curr->next) {
    if (printer != NULL) {
      printer(curr->data);
    } else {
      printf("{ %p, Data: %p | <- Prev: %p | -> Next: %p }\n", curr, curr->data,
             curr->prev, curr->next);
    }
  }
  printf("]\n");
}

void DLinkList_kill(LinkedList *list) {
  Node *current = list->head;
  while (current != NULL) {
    Node *temp = current;
    current = current->next;
    free(temp->data);
    free(temp);
    list->length--;
    list->head = current;
  }
  free(list);
  list = NULL;
}
