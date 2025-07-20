#include "arena.h"

#ifndef ARENA_ALLOC
void* alloc(const size_t size) {
    void* ptr = malloc(size * sizeof(uint8_t));
    if(ptr == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    return ptr;
}
#define ARENA_ALLOC alloc
#endif // ARENA_ALLOC

arena_t arena_create(const size_t capacity) {
    const arena_t new_arena = {
        .capacity = capacity,
        .size = 0,
        .data = ARENA_ALLOC(capacity)
    };
    return new_arena;
}

void* arena_alloc(arena_t* arena, const size_t size) {
    if(arena->size + size > arena->capacity) {
        return NULL;
    }
    void* ptr = arena->data + arena->size;
    arena->size += size;
    return ptr;
}

void arena_destroy(arena_t* arena) {
    free(arena->data);
    arena->data = NULL;
    arena->size = 0;
    arena->capacity = 0;
}