#pragma once

#include "types.h"

// 12 bytes. Filled by vswprintf and read by FormatPutWideBuffer: output buffer, its length in u16 units, and the
// count written.
typedef struct FormatPutWideTarget {
    /* 00 */ u16 *mBuffer;
    /* 04 */ u32 mSize;
    /* 08 */ u32 mWrittenCount;
} FormatPutWideTarget;

int vswprintf(u16 *buf, u32 maxCount, const u16 *fmt, char *va);
int swprintf(u16 *buf, u32 maxCount, const u16 *fmt, ...);
void *FormatPutWideBuffer(void *context, const u16 *source, u32 count);
