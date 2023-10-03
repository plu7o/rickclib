#include "../../include/lists.h"
#include "../../include/memory.h"

Queue *queue_new(size_t typeSize) {
  Queue *queue = malloc(sizeof(Stack));
  check_allocated(queue, "Error allocating Memory during Initializing.\n");

  queue->length = 0;
  queue->typeSize = typeSize;
  queue->list = llist_new(typeSize);

  return queue;
}

void *queue_dequeue(Queue *queue) { return llist_pop(queue->list); }

void queue_enqueue(Queue *queue, void *value) {
  llist_insert_start(queue->list, value);
}

void queue_print(Queue *queue, print_func printer) {
  llist_print(queue->list, printer);
}

void queue_kill(Queue *queue) {
  llist_kill(queue->list);
  free(queue);
}
