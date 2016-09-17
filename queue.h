struct Node {
  void* data;
  struct Node* prev;
  struct Node* next;
};
typedef struct Node Node;
  
struct Queue {
  Node* head;
  Node* last;
};
typedef struct Queue Queue;
  
extern Queue* queue_new();

extern void queue_enqueue(Queue* queue, void* data);

extern void* queue_dequeue(Queue* queue);

extern void* queue_peek(Queue* queue);

extern bool queue_is_empty(Queue* queue);
