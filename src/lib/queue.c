#include "../../include/lists.h"
#include "../../include/memory.h"

Queue *queue_new(size_t typeSize) {
  Queue *queue = malloc(sizeof(Stack));
  check_allocated(queue, "Error allocating Memory during Initializing.\n");

  queue->length = 0;
  queue->typeSize = typeSize;
  queue->list = LinkList_new(typeSize);

  return queue;
}

void *queue_dequeue(Queue *queue) {
  queue->length--;
  return LinkList_pop(queue->list);
}

void queue_enqueue(Queue *queue, void *value) {
  queue->length++;
  LinkList_insert_start(queue->list, value);
}

void queue_print(Queue *queue, callback_func printer) {
  LinkList_print(queue->list, printer);
}

bool queue_empty(Queue *queue) {
  if (queue->length == 0) {
    return true;
  }
  return false;
}

void queue_kill(Queue *queue) {
  LinkList_kill(queue->list);
  free(queue);
}
