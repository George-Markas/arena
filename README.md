# Arena

Implementation of a fixed-capacity arena allocator

## Example usage:
```C
#include "arena.h"
#include <string.h>

int main(void) {
    arena_t arena = arena_create(32);

    char* str = arena_alloc(&arena, sizeof("Hello, World!"));
    strcpy(str, "Hello, World!");

    int* inum = arena_alloc(&arena, sizeof(int));
    *inum = 42;

    float* fnum = arena_alloc(&arena, sizeof(float));
    *fnum = 3.14f;

    printf("%s\n%d\n%g\n", str, *inum, *fnum);

    arena_destroy(&arena);

    return 0;
}
```