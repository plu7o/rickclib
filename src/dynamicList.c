#include "../include/lists.h"

int *realloc_list(int *data, int capacity) {
  int *new_data = realloc(data, capacity * sizeof(int));
  check_allocated(new_data);

  return new_data;
}

bool index_bounds(DynamicList *list, int index) {
  if (index < 0 || list->count < index) {
    return true;
  }
  return false;
}

DynamicList *dlist_new(size_t typeSize) {
  DynamicList *list = malloc(sizeof(DynamicList));
  check_allocated((void *)list);

  list->count = 0;
  list->capacity = 8;
  list->data = calloc(list->capacity, sizeof(int));
  check_allocated(list->data);

  return list;
}

int dlist_get(DynamicList *list, int index) {
  if (index_bounds(list, index)) {
    fprintf(stderr, "Index out of bounds\n");
    exit(2);
  }
  int value = list->data[index];
  return value;
}

void dlist_push(DynamicList *list, int value) {
  if (list->count + 1 > list->capacity) {
    list->capacity = GROW_CAPACITY(list->capacity);
    list->data = realloc_list(list->data, list->capacity);
  }
  list->data[list->count] = value;
  list->count++;
}

void dlist_insert_array(DynamicList *list, int *values, int size) {
  for (int i = 0; i < size; i++) {
    dlist_push(list, values[i]);
  }
}

int dlist_pop(DynamicList *list) {
  int item = list->data[0];
  for (int i = 1; i < list->count; i++) {
    list->data[i - 1] = list->data[i];
  }
  list->count -= 1;
  list->data = realloc_list(list->data, list->capacity - 1);
  return item;
}

void dlist_remove(DynamicList *list, int index) {
  if (index_bounds(list, index)) {
    fprintf(stderr, "Index out of bounds");
    exit(2);
  }
  int item = list->data[index];
  for (int i = index + 1; i < list->count; i++) {
    list->data[i - 1] = list->data[i];
  }
  list->count -= 1;
  list->data = realloc_list(list->data, list->capacity - 1);
}

void dlist_kill(DynamicList *list) {
  printf("[Freeing DynmicList]\n");
  free(list->data);
  free(list);
}

void dlist_print_items(DynamicList *list) {
  printf("Items: [ ");
  for (int i = 0; i < list->count; i++) {
    printf("%d ", *(list->data + i));
  }
  printf("]\n");
}

void dlist_print(DynamicList *list) {
  printf("{count: %d capacity: %d data: %p}\n", list->count, list->capacity,
         list->data);
  dlist_print_items(list);
}
