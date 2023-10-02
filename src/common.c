#include "../include/common.h"

void check_allocated(void *pointer) {
  if (!pointer) {
    fprintf(stderr, "Error allocating memory!\n");
    exit(1);
  }
}
