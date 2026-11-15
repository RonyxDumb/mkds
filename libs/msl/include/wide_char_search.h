#pragma once

#include "types.h"
#include "print_memory_functions.h"

int fwide(FILE *stream, int mode);
u16 *wmemchr(const u16 *buffer, int wideChar, u32 count);
