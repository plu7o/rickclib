#include "../../include/common.h"
#include "../../include/lists.h"
#include "../../include/memory.h"
#include <string.h>

bool not_in_bounds(DynamicList *list, int index) {
  if (index < 0 || ((int)list->count - 1) < index) {
    printf("index: (%d) not in bounds\n", (int)list->count);
    return true;
  }
  return false;
}

void shrink(DynamicList *list) {
  size_t old_size = list->capacity;
  list->capacity /= 2;
  list->data = reallocate(list->data, old_size * list->typeSize,
                          list->capacity * list->typeSize);
  check_allocated(list, "Memory allocation failed while shrinking.\n");
}

void grow(DynamicList *list) {
  size_t old_size = list->capacity;
  list->capacity = old_size < 8 ? 8 : (old_size)*2;
  list->data = reallocate(list->data, old_size * list->typeSize,
                          list->capacity * list->typeSize);
  check_allocated(list, "Memory allocation failed while growing.\n");
}

DynamicList *dlist_new(size_t typeSize) {
  DynamicList *list = malloc(sizeof(DynamicList));
  check_allocated(list, "Memory allocation failed during Initilizing.\n");

  list->count = 0;
  list->capacity = 8;
  list->typeSize = typeSize;
  list->data = NULL;
  return list;
}

void *dlist_get(DynamicList *list, int index) {
  if (not_in_bounds(list, index)) {
    fprintf(stderr, "Index out of bounds\n");
    exit(2);
  }
  return (char *)list->data + index * list->typeSize;
}

void *dlist_pop(DynamicList *list) {
  if (list->count == 0) {
    return NULL;
  }

  void *item = malloc(list->typeSize);
  memcpy(item, list->data + (list->count - 1) * list->typeSize, list->typeSize);

  list->count--;

  if (list->count < list->capacity / 4) {
    shrink(list);
  }
  // USER NEEDS TO FREE ITEM
  return item;
}

void dlist_append(DynamicList *list, void *value) {
  if (list->count == 0) {
    list->data = reallocate(list->data, 0, list->capacity * list->typeSize);
    check_allocated(list->data, "Memory allocation failed during push.\n");
  }

  if (list->count + 1 > list->capacity) {
    grow(list);
  }

  memcpy((char *)list->data + list->count * list->typeSize, value,
         list->typeSize);
  list->count++;
}

void dlist_remove(DynamicList *list, int index) {
  if (list->count == 0) {
    return;
  }

  if (not_in_bounds(list, index)) {
    fprintf(stderr, "Index out of bounds");
    exit(2);
  }

  // free((char *)list->data + index * list->typeSize);
  memmove((char *)list->data + index * list->typeSize,
          (char *)list->data + (index + 1) * list->typeSize,
          (list->count - index - 1) * list->typeSize);

  list->count--;

  if (list->count < list->capacity / 4) {
    shrink(list);
  }
}

void dlist_reverse(DynamicList *list) {
  int start = 0;
  int end = list->count - 1;

  while (start < end) {
    // Swap data at positions 'start' and 'end'

    void *startPtr = dlist_get(list, start);
    void *endPtr = dlist_get(list, end);

    void *temp = malloc(list->typeSize);
    check_allocated(temp, "Memory allocation failed during reverse.\n");

    // Copy data from 'start' to 'temp'
    memcpy(temp, startPtr, list->typeSize);
    // Copy data from 'end' to 'start'
    memcpy(startPtr, endPtr, list->typeSize);
    // Copy data from 'temp' to 'end'
    memcpy(endPtr, temp, list->typeSize);

    // Free the temporary storage
    free(temp);

    start++;
    end--;
  }
}

void dlist_print(DynamicList *list, print_func printer) {
  printf("{count: %zu capacity: %zu data: %p}\n", list->count, list->capacity,
         list->data);

  printf("Items: [ ");
  for (int i = 0; i < (int)list->count; i++) {
    if (printer != NULL) {
      printer(dlist_get(list, i));
    } else {
      printf("%p ", dlist_get(list, i));
    }
  }
  printf("]\n");
}

void dlist_kill(DynamicList *list) {
  free(list->data);
  free(list);
}
