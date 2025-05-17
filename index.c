#include <stdio.h>
#include <string.h>
#include <stddef.h>
#include <sys/types.h>
#include <unistd.h>

// Apparently modern operating systems have a minimum memory allocation size
#define SYTEM_MIN_MEMORY 135168

void *edu_malloc(size_t size);

int main()
{

    void *initial_brk = sbrk(0);
    printf("Initial program break: %p\n", initial_brk);

    void *ptr = edu_malloc(10);

    void *end_brk = sbrk(0);
    printf("End memory: %p\n", end_brk);

    printf("Final Memory %td \n", ((char *)end_brk - (char *)initial_brk) - SYTEM_MIN_MEMORY);

    return 0;
}

void *edu_malloc(size_t size)
{

    void *ptr = sbrk(size);
    if (ptr == (void *)-1)
    {
        return NULL;
    }

    return ptr;
}
