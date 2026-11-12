#include "00/Lib/GameSpy/code_02197ddc.h"
#include "00/Lib/GameSpy/code_02197e58.h"
#include "00/Lib/DWC/dwc_memfunc.h"
#include "00/unk_021b3000.h"
#include "code_02134398.h"

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
        AssertionFailed("buffer->len < buffer->size", gGt2BufferFileName, NULL, 0x23);
    }
    v1 = buffer->mLength;
    buffer->mLength = v1 + 1;
    buffer->mData[v1] = b;
}

void AppendBufferU16(Gt2Buffer *buffer, s32 b) {
    int v1;
    if (buffer->mLength + 2 > buffer->mSize) {
        AssertionFailed("(buffer->len + 2) <= buffer->size", gGt2BufferFileName, NULL, 0x2e);
    }
    v1 = buffer->mLength;
    buffer->mLength = v1 + 1;
    buffer->mData[v1] = b >> 8;
    v1 = buffer->mLength;
    buffer->mLength = v1 + 1;
    buffer->mData[v1] = (s8) b;
}
