#include "code_0213c9e8.h"
#include "string.h"
#include "code_02134398.h"

void *wmemcpy(u16 *dst, const u16 *src, u32 count) {
    return memcpy(dst, src, count * 2);
}
