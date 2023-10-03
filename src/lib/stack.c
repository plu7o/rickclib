#include "../../include/lists.h"
#include "../../include/memory.h"

Stack *stack_new(size_t typeSize) {
  Stack *stack = malloc(sizeof(Stack));
  check_allocated(stack, "Error allocating Memory during Initializing.\n");

  stack->length = 0;
  stack->typeSize = typeSize;
  stack->list = dlist_new(typeSize);

  return stack;
}

void *stack_pop(Stack *stack) {
  stack->length--;
  return dlist_pop(stack->list);
}

void stack_push(Stack *stack, void *value) {
  stack->length++;
  dlist_append(stack->list, value);
}

void stack_print(Stack *stack, print_func printer) {
  dlist_print(stack->list, printer);
}

void stack_kill(Stack *stack) {
  dlist_kill(stack->list);
  free(stack);
}
