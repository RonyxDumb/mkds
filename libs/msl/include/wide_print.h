#pragma once

#include "types.h"

// The output target of vswprintf: the wide buffer, its size and the count written.
typedef struct FormatPutWideTarget {
    /* 00 */ u16 *mBuffer;
    /* 04 */ u32 mSize;
    /* 08 */ u32 mWrittenCount;
} FormatPutWideTarget;

int vswprintf(u16 *buf, u32 maxCount, const u16 *fmt, char *va);
int ParticularSnprintf16(u16 *buf, u32 maxCount, const u16 *fmt, ...);
void *FormatPutWideBuffer(void *context, const u16 *source, u32 count);
