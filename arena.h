#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef struct Arena {
    size_t capacity; // Max size
    size_t size;     // Current size
    uint8_t* data;   // Data bytes
} arena_t;

arena_t arena_create(const size_t capacity);
void* arena_alloc(arena_t* arena,  const size_t size);
void arena_destroy(arena_t* arena);