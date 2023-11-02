// Microsoft Visual Studio Compiler
// Clang support
// GCC support
//
#ifndef BASE_H
#define BASE_H

// Determine which compiler is available
#if defined(_MSC_VER)
# define COMPILER_CL 1
#elif defined(__clang__)
# define COMPILER_CLANG 1
#elif defined(__GNUC__)
# define COMPILER_GCC 1
#else
# error no context cracking found for this computer
#endif

// Determine which OS is being used
#if defined(_WIN32)
# define OS_WINDOWS 1
# elif defined(__gnu_linux__)
# define OS_LINUX 1
#elif defined(__APPLE__) && defined(__MACH__)
# define OS_MAC 1
#else 
# error missing OS detection
#endif

// Determine which architecture is used
#if defined(__amd64)
# define ARCH_X64 1
#elif defined(__i386__)
# define ARCH_X86 1
#elif defined(__arm__)
# define ARCH_ARM 1
#elif defined(__aarch64__)
# define ARCH_ARM64 1
# else 
#  error missing ARCH detection
#endif

// Zero fill missing context macros
#if !defined(COMPILER_CL)
# define COMPILER_CL 0
#endif
#if !defined(COMPILER_CLANG)
# define COMPILER_CLANG 0
#endif
#if !defined(COMPILER_GCC)
# define COMPILER_GCC 0
#endif
#if !defined(OS_WINDOWS)
# define OS_WINDOWS 0
#endif
#if !defined(OS_LINUX)
# define OS_LINUX 0
#endif
#if !defined(OS_MAC)
# define OS_MAC 0
#endif
#if !defined(ARCH_X64)
# define ARCH_X64 0
#endif
#if !defined(ARCH_X86)
# define ARCH_X86 0
#endif
#if !defined(ARCH_ARM)
# define ARCH_ARM 0
#endif
#if !defined(ARCH_ARM64)
# define ARCH_ARM64 0
#endif

// Basic Types
typedef signed char i8;
typedef signed short i16;
typedef signed int i32;
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef float f32;
typedef double f64;

// 64 bit ints
#include <limits.h>

#if LONG_MAX == 9223372036854775807L
    // On platforms where 'long' is 64 bits (common on many modern systems)
    typedef long i64;
    typedef unsigned long u64;
#elif INT_MAX == 9223372036854775807L
    // On platforms where 'int' is 64 bits
    typedef int i64;
    typedef unsigned int u64;
#else
    #error "No 64-bit integer type available on this platform."
#endif

// Boolean defined
typedef int bool;
#define True 1
#define False 0

#define STACK

// Struct for a node in the stack 
struct Node {
  int data;          // data stored in node
  struct Node* next; // Pointer to next node
};

// Struct for the stack
struct Stack {
  struct Node* top; // Pointer to top of stack 
};

// Create an empty stack
struct Stack* new_stack();

// Push an element onto stack
void push(struct Stack* stack, int data);

// Pop an element from stack
int pop(struct Stack* stack);

// Check if stack is empty
int is_empty(struct Stack* stack);

// Print elements in the stack
void print_stack(struct Stack* stack);

// Free memory allocated for the stack
void free_stack(struct Stack* stack);

#define QUEUE

// Struct for empty queue 
struct Queue {
  struct Node* front; // Front of queue
  struct Node* rear; // Rear of queue
}

// Create an empty queue
struct Queue* init_queue();

// Enqueue element at rear of queue
void enqueue(struct Queue* queue, int data);

// Dequeue element from front of queue
int dequeue(struct Queue* queue);

// Check if queue is empty
int is_empty(struct Queue* queue);

// Print queue
void print_queue(struct Queue* queue);

// Free memory allocated for queue
void free_queue(struct Queue* queue);

#define DOUBLE_LINKED_LIST

// Struct for node for DLL
struct DLLNode {
  int data;
  struct Node* next;
  struct Node* prev;
};

// Create a new node with given data
struct DLLNode* new_node(int data);

// Insert node at beginning of list
void insert_beginning(struct DLLNode** head, int data);

// Insert at end of list
void insert_end(struct DLLNode** head, int data);

// Print list forward
void print_forward(struct DLLNode* head);

// Print list backward
void print_backward(struct DLLNode* head);

// Free memory alocated for list
void free_linkedlist(struct DLLNode* head);

#endif //BASE_H
