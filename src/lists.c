#include "../include/lists.h"

int *reallocList(int *data, int capacity) {
  int *new_data = realloc(data, capacity * sizeof(int));
  if (!new_data) {
    printf("Error reallocating memory!\n");
    exit(-1);
  }
  return new_data;
}

bool index_bounds(List *list, int index) {
  if (index < 0 || list->count < index) {
    return true;
  }
  return false;
}

List *newList() {
  List *list = (List *)malloc(sizeof(List));
  if (!list) {
    fprintf(stderr, "Error allocating memory!\n");
    exit(-1);
  }

  list->count = 0;
  list->capacity = 8;
  list->data = calloc(list->capacity, sizeof(int));
  if (!list->data) {
    printf("Error allocating memory!\n");
    exit(-1);
  }

  return list;
}

int getList(List *list, int index) {
  if (index_bounds(list, index)) {
    fprintf(stderr, "Index out of bounds\n");
    exit(-1);
  }
  int value = list->data[index];
  printf("Value: %d\n", value);
  return value;
}

void addList(List *list, int value) {
  if (list->count + 1 > list->capacity) {
    printf("Capacity reached\n");
    list->capacity = GROW_CAPACITY(list->capacity);
    printf("Growing List to capacity: %d\n", list->capacity);
    list->data = reallocList(list->data, list->capacity);
  }
  printf("Added new Item: %d\n", value);
  list->data[list->count] = value;
  list->count++;
}

void addAllList(List *list, int *values, int size) {
  for (int i = 0; i < size; i++) {
    addList(list, values[i]);
  }
}

int popList(List *list) {
  int item = list->data[0];
  for (int i = 1; i < list->count; i++) {
    list->data[i - 1] = list->data[i];
  }
  list->count -= 1;
  list->data = reallocList(list->data, list->capacity - 1);
  printf("Popping Item: %d\n", item);
  return item;
}

void removeList(List *list, int index) {
  if (index_bounds(list, index)) {
    printf("Index out of bounds");
    exit(-1);
  }
  int item = list->data[index];
  for (int i = index + 1; i < list->count; i++) {
    list->data[i - 1] = list->data[i];
  }
  list->count -= 1;
  list->data = reallocList(list->data, list->capacity - 1);
  printf("Removing Item: %d\n", item);
}

void killList(List *list) {
  printf("[Freeing memory]\n");
  free(list->data);
  free(list);
}

void printItems(List *list) {
  printf("Items: [");
  for (int i = 0; i < list->count; i++) {
    printf("%d, ", *(list->data + i));
  }
  printf("]\n");
}

void printList(List *list) {
  printf("{count: %d capacity: %d data: %p}\n", list->count, list->capacity,
         list->data);
  printItems(list);
}
