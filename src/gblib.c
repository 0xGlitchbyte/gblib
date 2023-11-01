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

/*
 * Double Linked List implementation 
 */

// Create new node of data
struct Node* new_node (int data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
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
void insert_beginning(struct Node** head, int data) {
    struct Node* new_node = new_node(data);
    new_node->next = *head;
    if (*head != NULL) {
       (*head)->prev = new_node;
    }
    *head = new_node;
}

// Insert node at end of linked list
void insert_end(struct Node** head, int data) {
   struct Node* new_node = new_node(data);
   if (*head == NULL) {
       *head = new_node;
   }
   else {
      struct Node* current = *head;
      while (current->next != NULL) {
          current = current->next;
      }
      current->next = new_node;
      new_node->prev = current;
   }
}

// Print linked list forward
void print_forward(struct Node* head) {
    struct Node* currrent = head;
    printf("Forward: ");
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

// Print linked list backward
void print_backward(struct Node* head) {
    struct Node* current = head;
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
void free_linked_list(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        struct Node* temp = current;
        current = current->next;
        free(temp);
    }
}
