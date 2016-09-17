#include "queue.h"

typedef struct Queue Queue;
typedef struct Node Node;
  
Queue* queue_new() {
  Queue* queue = malloc(sizeof(Queue));
  queue->head = NULL;
  queue->last = NULL;
  return queue;
}

void queue_enqueue(Queue* queue, void* data) {
  Node* node = malloc(sizeof(Node));
  node->data = data;
  node->next = NULL;
  node->prev = NULL;
  if (queue->head == NULL) {
    queue->head = node;
    queue->last = node;
  } else {
    Node* currentLast = queue->last;
    node->prev = currentLast;
    currentLast->next = node;
    queue->last = node;
  }
}

void* queue_dequeue(Queue* queue) {
  Node* head = queue->head;
  void* data = head->data;
  
  if (head == queue->last) {
    queue->head = NULL;
    queue->last = NULL;
    free(head);
    return data;
  }
  
  queue->head = head->next;
  if (queue->head != NULL) {
    queue->head->prev = NULL;
  }
  free(head);
  return data;
}

void* queue_peek(Queue* queue) {
  return queue->head->data;
}

bool queue_is_empty(Queue* queue) {
  return queue->head == NULL;
}
