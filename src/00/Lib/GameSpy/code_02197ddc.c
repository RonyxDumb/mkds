#include "00/Lib/GameSpy/code_02197ddc.h"
#include "00/Lib/GameSpy/code_02197e58.h"
#include "00/Lib/DWC/dwc_memfunc.h"
#include "00/unk_021b3000.h"
#include "string.h"
#include "code_02134398.h"
#include "code_021384cc.h"
#include "code_02139f70.h"

u32 InitBuffer(Gt2Buffer *a, int b) {
    u8 *v1;
    v1 = DWCi_GsMalloc(b);
    a->mData = v1;
    if (a->mData == 0) {
        return 0;
    }
    a->mSize = b;
    return 1;
}

int GetBufferUnusedSize(Gt2Buffer *a) {
    return a->mSize - a->mLength;
}

void AppendBufferByte(Gt2Buffer *buffer, u8 b) {
    int v1;
    if (buffer->mLength >= buffer->mSize) {
        AssertionFailed("buffer->len < buffer->size", "gt2Buffer.c", NULL, 0x23);
    }
    v1 = buffer->mLength;
    buffer->mLength = v1 + 1;
    buffer->mData[v1] = b;
}

void AppendBufferU16(Gt2Buffer *buffer, s32 b) {
    int v1;
    if (buffer->mLength + 2 > buffer->mSize) {
        AssertionFailed("(buffer->len + 2) <= buffer->size", "gt2Buffer.c", NULL, 0x2e);
    }
    v1 = buffer->mLength;
    buffer->mLength = v1 + 1;
    buffer->mData[v1] = b >> 8;
    v1 = buffer->mLength;
    buffer->mLength = v1 + 1;
    buffer->mData[v1] = (s8) b;
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
