#include "../../include/common.h"

void *reallocate(void *pointer, size_t oldSize, size_t newSize) {
  if (newSize == 0) {
    free(pointer);
    return NULL;
  }
  void *result = realloc(pointer, newSize);
  if (result == NULL)
    exit(1);
  return result;
}

void check_allocated(void *pointer, char *chars) {
  if (!pointer) {
    fprintf(stderr, "%s\n", chars);
    exit(1);
  }
}










