#pragma once

// memset lives here, with a size_t size, so that small memset(p, 0, n) calls are written out inline as stores or a
// byte loop.
typedef unsigned long size_t;

void *memset(void *dst, int value, size_t count);
