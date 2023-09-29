#include "../include/lists.h"

LinkedList *llist_new() {
  LinkedList *list = malloc(sizeof(LinkedList));
  if (!list) {
    fprintf(stderr, "Error allocating memory!\n");
    exit(1);
  }

  list->head = NULL;
  list->tail = NULL;
  list->length = 0;

  return list;
}

void llist_kill(LinkedList *list) {
  Node *current = list->head;
  while (current != NULL) {
    Node *temp = current;
    current = current->next;
    free(temp);
  }
  free(list);
  printf("[FREEING MEMORY]\n");
}

void llist_insert_end(LinkedList *list, int value) {
  Node *new_node = malloc(sizeof(Node));
  if (!new_node) {
    fprintf(stderr, "Error allocating memory!\n");
    exit(1);
  }
  new_node->data = value;
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

void llist_insert_after(LinkedList *list, Node *node, int value) {
  Node *new_node = malloc(sizeof(Node));
  if (!new_node) {
    fprintf(stderr, "Error allocating memory!\n");
    exit(1);
  }

  new_node->data = value;
  new_node->next = node->next;
  node->next = new_node;

  if (new_node->next == NULL) {
    list->tail = new_node;
  }
  list->length++;
}

void llist_insert_start(LinkedList *list, int value) {
  Node *new_node = malloc(sizeof(Node));
  if (!new_node) {
    fprintf(stderr, "Error allocating memory!\n");
    exit(1);
  }
  new_node->data = value;
  new_node->next = list->head;

  list->head = new_node;
  list->length++;
}

void llist_insert_sorted(LinkedList *list, int value) {
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

void llist_remove(LinkedList *list, int value) {
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

void llist_print(LinkedList *list) {
  if (list->head == NULL) {
    printf("[]");
    return;
  }
  printf("[length: %d head: %d tail: %d]\n", list->length, list->head->data,
         list->tail->data);

  printf("|   %d, next: %p \n", list->head->data, list->head->next);
  for (Node *curr = list->head->next; curr != NULL; curr = curr->next) {
    printf("|-> %d, next: %p \n", curr->data, curr->next);
  }
  printf("\n");
}
