#include "gblib.h"

#include <stdio.h>

int main(){
  printf("cl      = %d\n", COMPILER_CL);
  printf("clang   = %d\n", COMPILER_CLANG);
  printf("gcc     = %d\n", COMPILER_GCC);
  printf("windows = %d\n", OS_WINDOWS);
  printf("linux   = %d\n", OS_LINUX);
  printf("mac     = %d\n", OS_MAC);
  printf("x64     = %d\n", ARCH_X64);
  printf("x86     = %d\n", ARCH_X86);
  printf("arm     = %d\n", ARCH_ARM);
  printf("arm64   = %d\n", ARCH_ARM64);

  struct Stack* stack = new_stack();

  push(stack, 1);
  push(stack, 2);
  push(stack, 3);
  
  print_stack(stack);

  int popped_value = pop(stack);
  printf("Popped value: %d\n", popped_value);

  print_stack(stack);

  free_stack(stack);

  return 0;
}
