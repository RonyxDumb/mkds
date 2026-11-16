#pragma once

#include "types.h"

double nan(const char *a);
int FflushAll(void);

u32 Abs(u32 arg0);

typedef int (*Unk0213c94cFunc)(u32 a, u8 *b, u32 *c, u32 d);

// 0x4c bytes. Bit fields of the words at 0x04 and 0x08 are read and written by fwide, FwriteBody and
// fflush; FileFlushBuffer calls mWriteFunc with field0, mBuffer, &mBufferRemaining and field48.
typedef struct FILE {
    /* 00 */ u32 field0;
    /* 04 */ u32 field4_0 : 2;
    /* 04 */ u32 field4_2 : 3;
    /* 04 */ u32 field4_5 : 2;
    /* 04 */ u32 field4_7 : 3;
    /* 04 */ u32 field4_10 : 2;
    /* 04 */ u32 field4_12 : 1;
    /* 04 */ u32 field4_13 : 19;
    /* 08 */ u32 field8_0 : 3;
    /* 08 */ u32 field8_3 : 29;
    /* 0c */ u8 fieldC;
    /* 0d */ u8 mFailed;
    /* 0e */ u8 fieldE[10];
    /* 18 */ u32 field18;
    /* 1c */ u8 *mBuffer;
    /* 20 */ u32 mBufferSize;
    /* 24 */ u8 *mBufferNext;
    /* 28 */ u32 mBufferRemaining;
    /* 2c */ u32 field2C;
    /* 30 */ u32 field30;
    /* 34 */ u32 field34;
    /* 38 */ u32 field38;
    /* 3c */ Unk0213c94cFunc field3C;
    /* 40 */ Unk0213c94cFunc mWriteFunc;
    /* 44 */ Unk0213c94cFunc field44;
    /* 48 */ u32 field48;
} FILE;

void AssertionFailed(const char *a, const char *b, const char *c, int d);
int FileFlushBuffer(FILE *a, u32 *b);
void FileResetBuffer(FILE *a);
u32 FwriteBody(const char *a, u32 b, u32 c, FILE *d);

int memcmp(const void *a, const void *b, u32 n);
void *MemChrBackward(const void *a, int v, u32 n);
void *memchr(const void *p, int c, u32 n);
void *memmove(void *a, const void *b, u32 n);
void *memcpy(void *dst, const void *src, u32 n);
void MemsetBody(u8 *p, int c, u32 n);

// 12 bytes. Filled by vsnprintf and read by FormatPutBuffer: output buffer, its length, and the count written.
typedef struct FormatPutTarget {
    /* 00 */ char *mBuffer;
    /* 04 */ u32 mSize;
    /* 08 */ u32 mWrittenCount;
} FormatPutTarget;

int sprintf(char *buf, const char *fmt, ...);
int snprintf(char *buf, u32 n, const char *fmt, ...);
int vsnprintf(char *buf, u32 n, const char *fmt, char *va);
int printf(const char *fmt, ...);
void *FormatPutBuffer(void *p, const char *b, u32 n);
void *FormatPutFwrite(void *a, const char *b, u32 n);

void func_0213453c(u8 *a, u32 *b);
void func_02135010(void);
