#pragma once
#include <word_size.h>

typedef unsigned char uchar;
typedef unsigned short int ushort;
typedef unsigned int uint;
typedef unsigned long int ulong;

typedef signed char int8_t;
typedef unsigned char uint8_t;
typedef signed short int int16_t;
typedef unsigned short int uint16_t;
typedef signed int int32_t;
typedef unsigned int uint32_t;

#if __WORD_SIZE == 64
typedef signed long int int64_t;
typedef unsigned long int uint64_t;
#else
typedef signed long long int int64_t;
typedef unsigned long long int uint64_t;
#endif

#ifndef SIZE_T
#define SIZE_T
typedef unsigned int size_t;
#endif
