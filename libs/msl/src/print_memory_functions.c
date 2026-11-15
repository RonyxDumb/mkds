#include "print_memory_functions.h"
#include "string.h"

#pragma avoid_byte all

#include "file_write_flush.h"
#include "number_text_format.h"
#include "wide_char_search.h"
#include "thread_mutex_types.h"
#include "Main/System/stdio_files.h"
#include "output_effect.h"
#include "Main/Net/wbt_os_thread_globals.h"
#include "os_thread.h"
#include "mb_data.h"
#include "Main/System/runtime_locks_stdio_buffers.h"
#include "stream.h"
#include "sound_archive_load.h"
#include "debugger_calls.h"

FILE gStdioFiles[3] = {
    {0,
     0,
     1,
     1,
     2,
     0,
     0,
     0,
     0,
     0,
     0,
     0,
     {0},
     0,
     gStdinBuffer,
     0x100,
     gStdinBuffer,
     0,
     0,
     0,
     0,
     0,
     SwiReadBytes,
     SwiWriteBytes,
     SwiCloseFile,
     0},
    {1,
     0,
     2,
     1,
     2,
     0,
     0,
     0,
     0,
     0,
     0,
     0,
     {0},
     0,
     gStdoutBuffer,
     0x100,
     gStdoutBuffer,
     0,
     0,
     0,
     0,
     0,
     SwiReadBytes,
     SwiWriteBytes,
     SwiCloseFile,
     0},
    {2,
     0,
     2,
     0,
     2,
     0,
     0,
     0,
     0,
     0,
     0,
     0,
     {0},
     0,
     gStderrBuffer,
     0x100,
     gStderrBuffer,
     0,
     0,
     0,
     0,
     0,
     SwiReadBytes,
     SwiWriteBytes,
     SwiCloseFile,
     0},
};

void *FormatPutFwrite(void *file, const char *text, u32 count) {
    if (count != fwrite(text, 1, count, file)) {
        file = 0;
    }
    return file;
}

void *FormatPutBuffer(void *arg, const char *text, u32 count) {
    FormatPutTarget *target = arg;

    if (target->mWrittenCount + count > target->mSize) {
        count = target->mSize - target->mWrittenCount;
    }
    memcpy(target->mBuffer + target->mWrittenCount, text, count);
    target->mWrittenCount += count;
    return (void *) 1;
}

int printf(const char *fmt, ...) {
    int result;

    if (fwide(&gStdioFiles[1], -1) >= 0) {
        return -1;
    }
    if (OS_TryLockMutex((OSMutex *) gLockMutexes[3]) == 0) {
        gLockOwnerThreadIds[3] = OSi_ThreadInfo.mListHead->mId;
        gLockHoldCounts[3] = 1;
    } else if (gLockOwnerThreadIds[3] == OSi_ThreadInfo.mListHead->mId) {
        gLockHoldCounts[3]++;
    } else {
        OS_LockMutex((OSMutex *) gLockMutexes[3]);
        gLockOwnerThreadIds[3] = OSi_ThreadInfo.mListHead->mId;
        gLockHoldCounts[3] = 1;
    }
    result = FormatWithPutFunc(FormatPutFwrite, &gStdioFiles[1], fmt, (char *) (((int) &fmt & ~3) + 4));
    gLockHoldCounts[3]--;
    if (gLockHoldCounts[3] == 0) {
        OS_UnlockMutex((OSMutex *) gLockMutexes[3]);
    }
    return result;
}

int vsnprintf(char *buf, u32 size, const char *fmt, char *va) {
    FormatPutTarget st;
    int result;

    st.mBuffer = buf;
    st.mSize = size;
    st.mWrittenCount = 0;
    result = FormatWithPutFunc(FormatPutBuffer, &st, fmt, va);
    if (buf == 0) {
        return result;
    }
    if (result < size) {
        buf[result] = 0;
    } else if (size != 0) {
        *(buf + size - 1) = 0;
    }
    return result;
}

int snprintf(char *buf, u32 size, const char *fmt, ...) {
    return vsnprintf(buf, size, fmt, (char *) (((int) &fmt & ~3) + 4));
}

int sprintf(char *buf, const char *fmt, ...) {
    return vsnprintf(buf, -1, fmt, (char *) (((int) &fmt & ~3) + 4));
}

#pragma avoid_byte all

void NopWriteHook(void) {}

void MemsetBody(u8 *dst, int fill, u32 count) {
    u32 *wordPtr;
    u32 alignBytes;
    u32 blockCount;

    fill = (u8) fill;
    if (count >= 0x20) {
        alignBytes = -(u32) dst & 3;
        if (alignBytes != 0) {
            count -= alignBytes;
            do {
                *dst++ = fill;
                alignBytes--;
            } while (alignBytes != 0);
        }
        wordPtr = (u32 *) dst;
        if (fill != 0) {
            fill = (fill << 24) | (fill << 16) | (fill << 8) | fill;
        }
        for (blockCount = count >> 5; blockCount != 0; blockCount--) {
            *wordPtr++ = fill;
            *wordPtr++ = fill;
            *wordPtr++ = fill;
            *wordPtr++ = fill;
            *wordPtr++ = fill;
            *wordPtr++ = fill;
            *wordPtr++ = fill;
            *wordPtr++ = fill;
        }
        for (blockCount = (count & 0x1f) >> 2; blockCount != 0; blockCount--) {
            *wordPtr++ = fill;
        }
        count &= 3;
        dst = (u8 *) wordPtr;
    }
    for (; count != 0; count--) {
        *dst++ = fill;
    }
}

void *memcpy(void *dst, const void *src, u32 count) {
    u8 *dstBytes = dst;
    const u8 *srcBytes = src;

    for (; count != 0; count--) {
        *dstBytes++ = *srcBytes++;
    }
    return dst;
}

void *memmove(void *dst, const void *src, u32 count) {
    if (src >= dst) {
        u8 *dstBytes;
        const u8 *srcBytes;

        for (dstBytes = dst, srcBytes = src; count != 0; count--) {
            *dstBytes++ = *srcBytes++;
        }
    } else {
        const u8 *srcBytes;
        u8 *dstBytes;

        for (srcBytes = (const u8 *) src + count, dstBytes = (u8 *) dst + count; count != 0; count--) {
            *--dstBytes = *--srcBytes;
        }
    }
    return dst;
}

void *memset(void *dst, int value, size_t count) {
    MemsetBody(dst, value, count);
    return dst;
}

void *memchr(const void *buffer, int value, u32 count) {
    const u8 *bytes = buffer;
    u8 ch = value;

    for (; count != 0; count--) {
        if (*bytes++ == ch) {
            return (bytes - 1);
        }
    }
    return 0;
}

void *MemChrBackward(const void *buffer, int value, u32 count) {
    u8 target = value;
    const u8 *cursor = (const u8 *) buffer + count;

    for (; count != 0; count--) {
        if (*--cursor == target) {
            return cursor;
        }
    }
    return 0;
}

int memcmp(const void *left, const void *right, u32 count) {
    const u8 *leftBytes = left;
    const u8 *rightBytes = right;

    for (; count != 0; count--) {
        if (*leftBytes++ != *rightBytes++) {
            return leftBytes[-1] < rightBytes[-1] ? -1 : 1;
        }
    }
    return 0;
}

#pragma avoid_byte all

#include "char_conversion.h"
#include "narrow_string_functions.h"

int mbtowc(u16 *dst, const char *src, u32 maxBytes) {
    return gCharConversion.mFunctions->mMbtowc(dst, src, maxBytes);
}

int MbtowcSingleByte(u16 *dst, const char *src, u32 maxBytes) {
    if (src == 0) {
        return 0;
    }
    if (maxBytes == 0) {
        return -1;
    }
    if (dst != 0) {
        *dst = *src;
    }
    if (*src == 0) {
        return 0;
    }
    return 1;
}

int WctombSingleByte(char *dst, u16 wideChar) {
    if (dst == 0) {
        return 0;
    }
    *dst = wideChar;
    return 1;
}

int wctomb(char *dst, u16 wideChar) {
    return gCharConversion.mFunctions->mWctomb(dst, wideChar);
}

int mbstowcs(u16 *dst, const char *src, u32 count) {
    u32 index;
    int len;
    int charLength;

    len = strlen(src);
    if (dst != 0) {
        for (index = 0; index < count; index++) {
            if (*src != 0) {
                charLength = mbtowc(dst, src, len);
                dst++;
                if (charLength > 0) {
                    src += charLength;
                    len -= charLength;
                } else {
                    return -1;
                }
            } else {
                *dst = 0;
                break;
            }
        }
    } else {
        index = 0;
    }
    return index;
}

int wcstombs(char *dst, const u16 *src, u32 count) {
    u32 len;
    u32 written = 0;
    char buf[4];
    char *encoded;

    if (dst == 0 || src == 0) {
        return 0;
    }
    encoded = buf;
    while (1) {
        if (*src == 0) {
            dst[written] = 0;
            break;
        }
        len = wctomb(encoded, *src++);
        if (written + len > count) {
            break;
        }
        strncpy(dst + written, encoded, len);
        written += len;
        if (written > count) {
            break;
        }
    }
    return written;
}

#pragma avoid_byte all

#include "double_digit_math.h"

double LdexpViaFrexp(double value, int exponentDelta) {
    int exponent;

    value = frexp(value, &exponent);
    exponent += exponentDelta;
    return ldexp(value, exponent);
}

int fflush(FILE *stream) {
    if (stream == 0) {
        return FflushAll();
    }
    if (stream->mFailed != 0 || stream->mKind == FILE_KIND_NONE) {
        return -1;
    }
    if (stream->mWriteMode == FILE_MODE_READ) {
        return 0;
    }
    if (stream->mWriteState >= FILE_STATE_READING_EXTRA_FIRST) {
        stream->mWriteState = FILE_STATE_READING;
    }
    if (stream->mWriteState == FILE_STATE_READING) {
        stream->mBufferRemaining = 0;
    }
    if (stream->mWriteState != FILE_STATE_WRITING) {
        stream->mWriteState = FILE_STATE_IDLE;
        return 0;
    }
    if (FileFlushBuffer(stream, 0) != 0) {
        stream->mFailed = 1;
        stream->mBufferRemaining = 0;
        return -1;
    }
    stream->mWriteState = FILE_STATE_IDLE;
    stream->mPosition = 0;
    stream->mBufferRemaining = 0;
    return 0;
}

u32 fwrite(const char *data, u32 itemSize, u32 itemCount, FILE *stream) {
    int lockIndex;
    OSMutex *mutex;
    u32 result;

    if (stream == &gStdioFiles[1]) {
        lockIndex = 3;
    } else if (stream == &gStdioFiles[2]) {
        lockIndex = 4;
    } else {
        lockIndex = 5;
    }
    mutex = (OSMutex *) gLockMutexes[lockIndex];
    if (OS_TryLockMutex(mutex) == 0) {
        gLockOwnerThreadIds[lockIndex] = OSi_ThreadInfo.mListHead->mId;
        gLockHoldCounts[lockIndex] = 1;
    } else {
        u32 ownerId;

        ownerId = gLockOwnerThreadIds[lockIndex];
        if (ownerId == OSi_ThreadInfo.mListHead->mId) {
            gLockHoldCounts[lockIndex]++;
        } else {
            OS_LockMutex(mutex);
            gLockOwnerThreadIds[lockIndex] = OSi_ThreadInfo.mListHead->mId;
            gLockHoldCounts[lockIndex] = 1;
        }
    }
    result = FwriteBody(data, itemSize, itemCount, stream);
    if (--gLockHoldCounts[lockIndex] == 0) {
        OS_UnlockMutex(mutex);
    }
    return result;
}

#pragma avoid_byte all

#include "program_exit.h"

u32 FwriteBody(const char *data, u32 itemSize, u32 itemCount, FILE *stream) {
    u32 remaining;
    u32 written;
    u32 newlineChar;
    u32 chunk;
    int bufferedMode;
    char *newlinePos;
    u8 *savedBuffer;
    u32 savedBufferSize;

    if (fwide(stream, 0) == 0) {
        fwide(stream, -1);
    }
    remaining = itemSize * itemCount;
    if (remaining == 0 || stream->mFailed != 0 || stream->mKind == FILE_KIND_NONE) {
        return 0;
    }
    if (stream->mKind == FILE_KIND_WITH_WRITE_HOOK) {
        NopWriteHook();
    }
    bufferedMode = 1;
    if (stream->mNoNewlineConversion != 0) {
        if (stream->mBufferMode != FILE_BUFFER_MODE_FULL && stream->mBufferMode != FILE_BUFFER_MODE_LINE) {
            bufferedMode = 0;
        }
    }
    if (stream->mWriteState == FILE_STATE_IDLE && (stream->mWriteMode & FILE_MODE_WRITE) != 0) {
        stream->mWriteState = FILE_STATE_WRITING;
        FileResetBuffer(stream);
    }
    if (stream->mWriteState != FILE_STATE_WRITING) {
        stream->mFailed = 1;
        stream->mBufferRemaining = 0;
        return 0;
    }
    written = 0;
    if (remaining != 0 && (stream->mBufferNext != stream->mBuffer || bufferedMode != 0)) {
        stream->mBufferRemaining = stream->mBufferSize - (stream->mBufferNext - stream->mBuffer);
        newlineChar = 10;
        do {
            newlinePos = 0;
            chunk = stream->mBufferRemaining;
            if (chunk > remaining) {
                chunk = remaining;
            }
            if (stream->mBufferMode == FILE_BUFFER_MODE_LINE && chunk != 0) {
                newlinePos = MemChrBackward(data, newlineChar, chunk);
                if (newlinePos != 0) {
                    chunk = newlinePos + 1 - data;
                }
            }
            if (chunk != 0) {
                memcpy(stream->mBufferNext, data, chunk);
                data += chunk;
                remaining -= chunk;
                stream->mBufferNext += chunk;
                stream->mBufferRemaining -= chunk;
            }
            if (stream->mBufferRemaining == 0 || newlinePos != 0 || stream->mBufferMode == FILE_BUFFER_MODE_NONE) {
                if (FileFlushBuffer(stream, 0) != 0) {
                    stream->mFailed = 1;
                    remaining = 0;
                    stream->mBufferRemaining = remaining;
                    break;
                }
            }
            written += chunk;
        } while (remaining != 0 && bufferedMode != 0);
    }
    if (remaining != 0 && bufferedMode == 0) {
        savedBuffer = stream->mBuffer;
        savedBufferSize = stream->mBufferSize;
        stream->mBuffer = (u8 *) data;
        stream->mBufferSize = remaining;
        stream->mBufferNext = (u8 *) data + remaining;
        if (FileFlushBuffer(stream, &chunk) == 0) {
            written += chunk;
        } else {
            stream->mFailed = 1;
            stream->mBufferRemaining = 0;
        }
        stream->mBuffer = savedBuffer;
        stream->mBufferSize = savedBufferSize;
        FileResetBuffer(stream);
        stream->mBufferRemaining = 0;
    }
    if (stream->mBufferMode != FILE_BUFFER_MODE_FULL) {
        stream->mBufferRemaining = 0;
    }
    return written / itemSize;
}

void ConvertTextNewlinesNop(u8 *buffer, u32 *length) {}

void FileResetBuffer(FILE *stream) {
    stream->mBufferNext = stream->mBuffer;
    stream->mBufferRemaining = stream->mBufferSize;
    stream->mBufferRemaining = stream->mBufferRemaining - (stream->mPosition & stream->mPositionMask);
    stream->mBufferStartPosition = stream->mPosition;
}

int FileFlushBuffer(FILE *stream, u32 *writtenOut) {
    int pending;
    int result;

    pending = stream->mBufferNext - stream->mBuffer;
    if (pending != 0) {
        stream->mBufferRemaining = pending;
        if (stream->mNoNewlineConversion == 0) {
            ConvertTextNewlinesNop(stream->mBuffer, &stream->mBufferRemaining);
        }
        result = stream->mWriteFunc(stream->mWriteFuncFirstArg, stream->mBuffer, &stream->mBufferRemaining,
                                    stream->mWriteFuncLastArg);
        if (writtenOut != 0) {
            *writtenOut = stream->mBufferRemaining;
        }
        if (result != 0) {
            return result;
        }
        stream->mPosition = stream->mPosition + stream->mBufferRemaining;
    }
    FileResetBuffer(stream);
    return 0;
}

void AssertionFailed(const char *expression, const char *fileName, const char *functionName, int lineNumber) {
    printf("Assertion (%s) failed in \"%s\", function \"%s\", line %d\n", expression, fileName, functionName,
           lineNumber);
    abort();
}

u32 Abs(u32 value) {
    u32 absValue = value;
    s32 left;
    s32 right;
    left = absValue;
    right = 0u;
    if (left < right) {
        absValue = (0u) - (absValue);
    }
    return absValue;
}

#pragma avoid_byte all

int FflushAll(void) {
    int result;
    int index;
    FILE *stream;

    result = 0;
    index = 1;
    stream = gStdioFiles;
    do {
        if (stream->mKind != FILE_KIND_NONE) {
            if (fflush(stream) != 0) {
                result = -1;
            }
        }
        stream = (index < 3) ? &gStdioFiles[index++] : 0;
    } while (stream != 0);
    return result;
}

double nan(const char *tag) {
    return gFloatQuietNan;
}
