#include "00/Lib/GameSpy/byte_buffer.h"
#include "00/Lib/GameSpy/connection_events.h"
#include "00/Lib/DWC/memory_allocator.h"
#include "string.h"
#include "print_memory_multibyte_write.h"
#include "scan_text_random.h"
#include "narrow_string_functions.h"

u32 InitBuffer(Gt2Buffer *buffer, int size) {
    u8 *data;
    data = DWCi_GsMalloc(size);
    buffer->mData = data;
    if (buffer->mData == 0) {
        return 0;
    }
    buffer->mSize = size;
    return 1;
}

int GetBufferUnusedSize(Gt2Buffer *buffer) {
    return buffer->mSize - buffer->mLength;
}

void AppendBufferByte(Gt2Buffer *buffer, u8 byteValue) {
    int writeIndex;
    if (buffer->mLength >= buffer->mSize) {
        AssertionFailed("buffer->len < buffer->size", "gt2Buffer.c", NULL, 0x23);
    }
    writeIndex = buffer->mLength;
    buffer->mLength = writeIndex + 1;
    buffer->mData[writeIndex] = byteValue;
}

void AppendBufferU16(Gt2Buffer *buffer, s32 value) {
    int writeIndex;
    if (buffer->mLength + 2 > buffer->mSize) {
        AssertionFailed("(buffer->len + 2) <= buffer->size", "gt2Buffer.c", NULL, 0x2e);
    }
    writeIndex = buffer->mLength;
    buffer->mLength = writeIndex + 1;
    buffer->mData[writeIndex] = value >> 8;
    writeIndex = buffer->mLength;
    buffer->mLength = writeIndex + 1;
    buffer->mData[writeIndex] = (s8) value;
}

void AppendBufferBytes(Gt2Buffer *buffer, const u8 *data, int len) {
    if (data != NULL && len != 0) {
        if (len == -1) {
            len = strlen((const char *) data);
        }
        if (buffer->mLength + len > buffer->mSize) {
            AssertionFailed("(buffer->len + len) <= buffer->size", "gt2Buffer.c", NULL, 0x40);
        }
        memcpy(buffer->mData + buffer->mLength, data, len);
        buffer->mLength = buffer->mLength + len;
    }
}

void RemoveBufferBytes(Gt2Buffer *buffer, int start, int shortenBy) {
    if (start == -1) {
        start = buffer->mLength - shortenBy;
    }
    if (start > buffer->mLength) {
        AssertionFailed("start <= buffer->len", "gt2Buffer.c", NULL, 0x4f);
    }
    if (shortenBy > buffer->mLength - start) {
        AssertionFailed("shortenBy <= (buffer->len - start)", "gt2Buffer.c", NULL, 0x50);
    }
    memmove(buffer->mData + start, buffer->mData + start + shortenBy, buffer->mLength - start - shortenBy);
    buffer->mLength = buffer->mLength - shortenBy;
}
