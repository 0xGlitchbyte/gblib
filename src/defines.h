// Microsoft Visual Studio Compiler
// Clang support
// GCC support
//
#ifndef DEFINES_H
#define DEFINES_H

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
