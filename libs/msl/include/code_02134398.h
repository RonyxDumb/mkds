#pragma once

#include "types.h"

double nan(const char *tag);
int FflushAll(void);

u32 Abs(u32 value);

// Function slot of a FILE; FileFlushBuffer calls the write one with a buffer and a count pointer.
typedef int (*FileIoFunc)(u32 a, u8 *b, u32 *c, u32 d);

// mWideMode values: not set yet, set by a negative fwide mode, set by a positive fwide mode.
typedef enum FileWideMode {
    FILE_WIDE_MODE_UNSET = 0,
    FILE_WIDE_MODE_NEGATIVE = 1,
    FILE_WIDE_MODE_POSITIVE = 2,
} FileWideMode;

// 0x4c bytes. Bit fields of the words at 0x04 and 0x08 are read and written by fwide, FwriteBody and
// fflush; FileFlushBuffer calls mWriteFunc with mWriteFuncFirstArg, mBuffer, &mBufferRemaining and mWriteFuncLastArg.
typedef struct FILE {
    /* 00 */ u32 mWriteFuncFirstArg;
    /* 04 */ u32 mUnk_04_0 : 2;
    /* 04 */ u32 mWriteMode : 3;
    /* 04 */ u32 mBufferMode : 2;
    /* 04 */ u32 mKind : 3;
    /* 04 */ u32 mWideMode : 2;
    /* 04 */ u32 mNoNewlineConversion : 1;
    /* 04 */ u32 mUnk_04_13 : 19;
    /* 08 */ u32 mWriteState : 3;
    /* 08 */ u32 mUnk_08_3 : 29;
    /* 0c */ u8 mUnk_0c;
    /* 0d */ u8 mFailed;
    /* 0e */ u8 mUnk_0e[10];
    /* 18 */ u32 mPosition;
    /* 1c */ u8 *mBuffer;
    /* 20 */ u32 mBufferSize;
    /* 24 */ u8 *mBufferNext;
    /* 28 */ u32 mBufferRemaining;
    /* 2c */ u32 mPositionMask;
    /* 30 */ u32 mUnk_30;
    /* 34 */ u32 mBufferStartPosition;
    /* 38 */ u32 mUnk_38;
    /* 3c */ FileIoFunc mUnk_3c;
    /* 40 */ FileIoFunc mWriteFunc;
    /* 44 */ FileIoFunc mUnk_44;
    /* 48 */ u32 mWriteFuncLastArg;
} FILE;

void AssertionFailed(const char *expression, const char *fileName, const char *functionName, int lineNumber);
int FileFlushBuffer(FILE *stream, u32 *writtenOut);
void FileResetBuffer(FILE *stream);
u32 FwriteBody(const char *data, u32 itemSize, u32 itemCount, FILE *stream);

int memcmp(const void *left, const void *right, u32 count);
void *MemChrBackward(const void *buffer, int value, u32 count);
void *memchr(const void *buffer, int value, u32 count);
void *memmove(void *dst, const void *src, u32 count);
void *memcpy(void *dst, const void *src, u32 count);
void MemsetBody(u8 *dst, int fill, u32 count);

// 12 bytes. Filled by vsnprintf and read by FormatPutBuffer: output buffer, its length, and the count written.
typedef struct FormatPutTarget {
    /* 00 */ char *mBuffer;
    /* 04 */ u32 mSize;
    /* 08 */ u32 mWrittenCount;
} FormatPutTarget;

int sprintf(char *buf, const char *fmt, ...);
int snprintf(char *buf, u32 size, const char *fmt, ...);
int vsnprintf(char *buf, u32 size, const char *fmt, char *va);
int printf(const char *fmt, ...);
void *FormatPutBuffer(void *arg, const char *text, u32 count);
void *FormatPutFwrite(void *file, const char *text, u32 count);

void ConvertTextNewlinesNop(u8 *buffer, u32 *length);
void NopWriteHook(void);
