#if defined __x86_64__
#define __WORD_SIZE 64
#else
#define __WORD_SIZE 32
#define __WORD_SIZE32_SIZE_ULONG 0
#define __WORD_SIZE32_PTRDIFF_LONG 0
#endif

#ifdef __x86_64__
#define __WORD_SIZE_TIME_64_COMPAT_32 1
#define __SYSCALL_WORD_SIZE 64
#else
#define __WORD_SIZE_TIME_64_COMPAT_32 0
#endif
