#include "../../include/common.h"
#include "../../include/lists.h"
#include "../../include/memory.h"
#include <stdlib.h>
#include <string.h>

bool not_in_bounds(DynamicList *list, size_t index) {
  if ((list->length - 1) < index) {
    printf("index: (%d) not in bounds\n", (int)list->length);
    return true;
  }
  return false;
}

void shrink(DynamicList *list) {
  // Memory Strategy
  list->capacity /= 2;
  list->data = realloc(list->data, list->capacity * list->typeSize);
  check_allocated(list, "Memory allocation failed while shrinking.\n");
}

void grow(DynamicList *list) {
  list->capacity = list->capacity < 8 ? 8 : list->capacity * 2;
  list->data = realloc(list->data, list->capacity * list->typeSize);
  check_allocated(list, "Memory allocation failed while growing.\n");
}

DynamicList *DynList_new(size_t typeSize) {
  DynamicList *list = malloc(sizeof(DynamicList));
  check_allocated(list, "Memory allocation failed during Initilizing.\n");

  list->length = 0;
  list->capacity = 8;
  list->typeSize = typeSize;

  list->data = (void *)calloc(list->capacity, typeSize);
  check_allocated(list->data, "Memory allocation failed during push.\n");

  return list;
}

void *DynList_get(DynamicList *list, size_t index) {
  if (not_in_bounds(list, index)) {
    fprintf(stderr, "Index out of bounds\n");
    exit(2);
  }

  return (char *)list->data + index * list->typeSize;
}

void *DynList_pop(DynamicList *list) {
  if (list->length == 0) {
    return NULL;
  }

  void *item = malloc(list->typeSize);
  memcpy(item, list->data + (list->length - 1) * list->typeSize,
         list->typeSize);
  list->length--;

  if (list->length < list->capacity / 4) {
    shrink(list);
  }

  // USER NEEDS TO FREE ITEM
  return item;
}

void DynList_append(DynamicList *list, void *value) {
  if (list->length + 1 > list->capacity) {
    grow(list);
  }

  memcpy((char *)list->data + list->length * list->typeSize, value,
         list->typeSize);
  list->length++;
}

void DynList_remove(DynamicList *list, size_t index) {
  if (list->length == 0) {
    return;
  }

  if (not_in_bounds(list, index)) {
    fprintf(stderr, "Index out of bounds");
    exit(2);
  }

  memmove((char *)list->data + index * list->typeSize,
          (char *)list->data + (index + 1) * list->typeSize,
          (list->length - index - 1) * list->typeSize);

  list->length--;

  if (list->length < list->capacity / 4) {
    shrink(list);
  }
}

void DynList_set(DynamicList *list, size_t index, void *value) {
  if (list->length == 0) {
    return;
  }

  if (not_in_bounds(list, index)) {
    fprintf(stderr, "Index out of bounds");
    exit(2);
  }

  memcpy(list->data + index * list->typeSize, value, list->typeSize);
}

void DynList_reverse_alt(DynamicList *list) {
  int size = list->length;
  for (int i = 0; i > size / 2; i++) {
    void *item = DynList_get(list, i);
    DynList_set(list, i, DynList_get(list, (size - i - 1)));
    DynList_set(list, (size - i - 1), item);
  }
}

void DynList_reverse(DynamicList *list) {
  int start = 0;
  int end = list->length - 1;

  while (start < end) {
    // Swap data at positions 'start' and 'end'

    void *startPtr = DynList_get(list, start);
    void *endPtr = DynList_get(list, end);

    void *temp = malloc(list->typeSize);
    check_allocated(temp, "Memory allocation failed during reverse.\n");

    memcpy(temp, startPtr, list->typeSize);
    memcpy(startPtr, endPtr, list->typeSize);
    memcpy(endPtr, temp, list->typeSize);

    free(temp);

    start++;
    end--;
  }
}

bool DynList_is_empty(DynamicList *list) { return list->length == 0; }

void DynList_print(DynamicList *list, callback_func printer) {
  printf("{length: %zu capacity: %zu data: %p}\n", list->length, list->capacity,
         list->data);

  printf("Items: [ ");
  for (size_t i = 0; i < list->length; i++) {
    if (printer != NULL) {
      printer(DynList_get(list, i));
    } else {
      printf("%p ", DynList_get(list, i));
    }
  }
  printf("]\n");
}

void DynList_kill(DynamicList *list) {
  free(list->data);
  free(list);
  list = NULL;
}
