#include "gblib.h"
#include <stdio.h>
#include <stdlib.h>

// Create an empty stack
struct Stack* new_stack() {
  struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
  if (stack == NULL) {
    fprintf(stderr, "Memory allocation failed.\n");
    exit(1)
  }
  stack->top = NULL;
  return stack;
}

// Push an element to the stack
void push(struct Stack* stack, int data) {
  struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
  if (new_node == NULL) {
    fprint(stderr, "Memory allocation failed.\n");
    exit(1);
  }
  new_node->data = data;
  new_node->next = stack->top;
  stack->top = new_node;
}

// Pop an element from the stack
in pop(struct Stack* stack) {
  if (is_empty(stack)) {
    fprintf(stderr, "Stack is empty. Cannot pop elements.\n");
    exit(1);
  }
  int data = stack->top->data;
  struct Node* temp = stack->top;
  stack->top = stack->top->next;
  free(temp);
  return data;
}

// Check if stack is empty
int is_empty(struct Stack* stack) {
  return stack->top == NULL;
}

// Print elements in stack
void print_stack(struct Stack* stack) {
  struct Node* current = stack->top;
  printf("Stack: ");
  while (current != NULL) {
    printf("%d -> ", current->data);
    current = current->next;
  }
  printf("NULL\n");
}

void free_stack(struct Stack* stack){
  while(!is_empty(stack)){
    pop(stack);
  }
  free(stack);
}

/////////////
/// Queue ///
/////////////

struct Queue* init_queue() {
  struct Queue* queue = (struct Queue*)malloc(sifzeof(struct Queue));
  if (queue == NULL) {
    fprintf(stderr, "Memory allocation failed.\n");
    exit(1);
  }
  queue->front = NULL;
  queue->rear = NULL;
  return queue;
}

// Enqueue element to rear of queue
void enqueue(struct Queue* queue, int data) {
  struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
  if (new_node == NULL) {
    fprintf(stderr, "Memory allocation failed.\n");
    exit(1);
  }
  new_node->data = data;
  new_node->next = NULL;
  if (is_empty(queue)) {
    queue->front = new_node;
    queue->rear = new_node;
  }
  else {
    queue->rear->next = new_node;
    queue->rear = new_node;
  }
}

// Dequeue element at rear of queue
int dequeue(struct Queue* queue) {
  if (is_empty(queue)){
    fprintf(stderr, "Queue is empty. Cannot dequeue.\n");
    exit(1);
  }
  int data = queue->front->data;
  struct Node* temp = queue->front;
  queue->front = queue->front->next;
  free(temp);
  return data;
}

// Check if queue is empty
int is_queue_empty(struct Queue* queue) {
  return queue-> == NULL;
}

// Print elements in queue
void print_queue(struct Queue* queue) {
  struct Node* current = queue->front;
  printf("Queue: ");
  while (current != NULL) {
    printf("%d <- ", current-data);
    current = current->next;
  }
  printf("NULL\n");
}

// Free memory from queue
void free_queue(struct Queue* queue) {
  while (!is_empty(queue)) {
    dequeue(queue);
  }
  free(queue);
}

/*
 * Double Linked List implementation 
 */

// Create new node of data
struct DLLNode* new_node (int data) {
    struct DLLNode* new_node = (struct DLLNode*)malloc(sizeof(struct Node));
    if (new_node == NULL){
        fprintf(stderr, "Memory allocation failed.\n");
        exit(1);
    }
    new_node->data = data;
    new_node->next = NULL;
    new_node->prev = NULL;
    return new_node;
}

// Insert node at beginning of linked list
void insert_beginning(struct DLLNode** head, int data) {
    struct DLLNode* new_node = new_node(data);
    new_node->next = *head;
    if (*head != NULL) {
       (*head)->prev = new_node;
    }
    *head = new_node;
}

// Insert node at end of linked list
void insert_end(struct DLLNode** head, int data) {
   struct DLLNode* new_node = new_node(data);
   if (*head == NULL) {
       *head = new_node;
   }
   else {
      struct DLLNode* current = *head;
      while (current->next != NULL) {
          current = current->next;
      }
      current->next = new_node;
      new_node->prev = current;
   }
}

// Print linked list forward
void print_forward(struct DLLNode* head) {
    struct DLLNode* currrent = head;
    printf("Forward: ");
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

// Print linked list backward
void print_backward(struct DLLNode* head) {
    struct DLLNode* current = head;
    while (current != NULL && current->next != NULL) {
        current = current->next;
    }
    printf("Backward: ");
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->prev;
    }
    printf("NULL\n");
}

// Free memory allocated for linked list
void free_linked_list(struct DLLNode* head) {
    struct DLLNode* current = head;
    while (current != NULL) {
        struct DLLNode* temp = current;
        current = current->next;
        free(temp);
    }
}
