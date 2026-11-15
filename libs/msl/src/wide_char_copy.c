#include "wide_char_copy.h"
#include "string.h"
#include "print_memory_functions.h"

void *wmemcpy(u16 *dst, const u16 *src, u32 count) {
    return memcpy(dst, src, count * 2);
}
