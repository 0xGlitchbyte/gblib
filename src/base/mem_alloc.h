// TODO: Write an Arena Allocator
//

#ifndef ARENA_H
#define ARENA_H

#include "define.h"

const int MEMORY_POOL_SIZE = 4096;

typdef struct Arena Arena;

struct Arena {
  char data[MEMORY_POOL_SIZE];
  u32 used;
  struct Arena* next;
} 

void arena_init(Arena* arena, u32 size) {
  arena->used=0;
  arena->next=NULL;
}

void* arena_alloc(Arena* arena, u32 size) {
  if (size > MEMORY_POOL_SIZE - arena->used) {
    return NULL;
  }

  void* ptr = arena->data + arena->used;
  arena->used += size;
  return ptr;
}
