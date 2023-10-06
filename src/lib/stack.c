#include "../../include/lists.h"
#include "../../include/memory.h"

Stack *stack_new(size_t typeSize) {
  Stack *stack = malloc(sizeof(Stack));
  check_allocated(stack, "Error allocating Memory during Initializing.\n");

  stack->length = 0;
  stack->typeSize = typeSize;
  stack->list = DynList_new(typeSize);

  return stack;
}

void *stack_pop(Stack *stack) {
  stack->length--;
  return DynList_pop(stack->list);
}

void stack_push(Stack *stack, void *value) {
  stack->length++;
  DynList_append(stack->list, value);
}

void stack_print(Stack *stack, callback_func printer) {
  DynList_print(stack->list, printer);
}

void stack_kill(Stack *stack) {
  DynList_kill(stack->list);
  free(stack);
}
