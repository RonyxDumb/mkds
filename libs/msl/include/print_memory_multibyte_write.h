#pragma once

#include "types.h"

double nan(const char *tag);
int FflushAll(void);

u32 Abs(u32 value);

// Function slots of a FILE; FileFlushBuffer calls the write one with a buffer and a count pointer.
typedef int (*FileReadFunc)(s32 fileHandle, u8 *buffer, u32 *countPtr);
typedef int (*FileWriteFunc)(s32 fileHandle, const u8 *buffer, const u32 *countPtr, u32 lastArg);
typedef int (*FileCloseFunc)(void);

// mWideMode values: not set yet, set by a negative fwide mode, set by a positive fwide mode.
typedef enum FileWideMode {
    FILE_WIDE_MODE_UNSET = 0,
    FILE_WIDE_MODE_NEGATIVE = 1,
    FILE_WIDE_MODE_POSITIVE = 2,
} FileWideMode;

// FILE.mWriteMode bits: the stream may be read, the stream may be written.
#define FILE_MODE_READ 0x1
#define FILE_MODE_WRITE 0x2

// FILE.mBufferMode values: flush after every write, flush at a newline, flush when the buffer is full.
#define FILE_BUFFER_MODE_NONE 0
#define FILE_BUFFER_MODE_LINE 1
#define FILE_BUFFER_MODE_FULL 2

// FILE.mKind values: not usable, and the kind whose writes call NopWriteHook first.
#define FILE_KIND_NONE 0
#define FILE_KIND_WITH_WRITE_HOOK 2

// FILE.mWriteState values: nothing pending, writing, reading; fflush treats every state from the third on
// as reading.
#define FILE_STATE_IDLE 0
#define FILE_STATE_WRITING 1
#define FILE_STATE_READING 2
#define FILE_STATE_READING_EXTRA_FIRST 3

// A C stdio stream: mode bits, the buffer and its position, and mWriteFunc which writes it out.
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
    /* 3c */ FileReadFunc mUnk_3c;
    /* 40 */ FileWriteFunc mWriteFunc;
    /* 44 */ FileCloseFunc mUnk_44;
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

// The output target of vsnprintf: the buffer, its size and the count written.
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
