#include "../include/lists.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

LinkedList *llist_new(size_t typeSize) {
  LinkedList *list = (LinkedList *)malloc(sizeof(LinkedList));
  check_allocated(list);

  list->head = NULL;
  list->tail = NULL;
  list->length = 0;
  list->typeSize = typeSize;

  return list;
}

void llist_kill(LinkedList *list) {
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
  printf("[FREEING MEMORY]\n");
}

void llist_insert_end(LinkedList *list, void *value) {
  Node *new_node = (Node *)malloc(sizeof(Node));
  check_allocated(new_node);

  new_node->data = malloc(list->typeSize);
  check_allocated(new_node->data);
  memcpy(new_node->data, value, list->typeSize);

  new_node->next = NULL;

  if (list->head == NULL) {
    list->head = new_node;
    list->tail = new_node;
    list->length++;
    return;
  }

  list->tail->next = new_node;
  list->tail = new_node;
  list->length++;
}

void llist_insert_after(LinkedList *list, Node *node, void *value) {
  Node *new_node = (Node *)malloc(sizeof(Node));
  check_allocated(new_node);

  new_node->data = malloc(list->typeSize);
  check_allocated(new_node->data);
  memcpy(new_node->data, value, list->typeSize);

  new_node->next = node->next;
  node->next = new_node;

  if (new_node->next == NULL) {
    list->tail = new_node;
  }
  list->length++;
}

void llist_insert_start(LinkedList *list, void *value) {
  Node *new_node = (Node *)malloc(sizeof(Node));
  check_allocated(new_node);

  new_node->data = malloc(list->typeSize);
  check_allocated(new_node->data);
  memcpy(new_node->data, value, list->typeSize);

  new_node->next = list->head;

  list->head = new_node;
  list->length++;
}

void llist_insert_sorted(LinkedList *list, void *value) {
  if (list->head == NULL || list->head->data >= value) {
    llist_insert_start(list, value);
    return;
  }

  Node *current = list->head;
  while (current->next != NULL) {
    if (current->next->data >= value) {
      break;
    }
    current = current->next;
  }
  llist_insert_after(list, current, value);
}

void llist_reverse(LinkedList *list) {
  Node *prev = NULL;
  Node *current = list->head;
  list->tail = list->head;

  while (current != NULL) {
    Node *next = current->next;
    current->next = prev;
    prev = current;
    current = next;
  }
  list->head = prev;
}

void llist_remove(LinkedList *list, void *value) {
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

void *llist_pop(LinkedList *list) {
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

void llist_print(LinkedList *list) {
  printf("[length: %d head: %p tail: %p]\n", list->length, list->head,
         list->tail);

  if (list->head == NULL) {
    printf("[]\n");
    return;
  }

  printf("|   %p, data: %p, next: %p\n", list->head, list->head->data,
         list->head->next);

  for (Node *curr = list->head->next; curr != NULL; curr = curr->next) {
    printf("|-> %p, data: %p, next: %p\n", curr, curr->data, curr->next);
  }
  printf("\n");
}
