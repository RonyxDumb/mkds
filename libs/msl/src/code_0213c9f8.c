#pragma avoid_byte all

#include "code_0213c9f8.h"
#include "code_0213c9e8.h"
#include "code_0213cae0.h"

void *FormatPutWideBuffer(void *context, const u16 *source, u32 count) {
    FormatPutWideTarget *target = context;
    void *copyResult;

    if (target->mWrittenCount + count > target->mSize) {
        count = target->mSize - target->mWrittenCount;
    }
    copyResult = wmemcpy(target->mBuffer + target->mWrittenCount, source, count);
    target->mWrittenCount += count;
    return copyResult;
}

int swprintf(u16 *buf, u32 maxCount, const u16 *fmt, ...) {
    return vswprintf(buf, maxCount, fmt, (char *) (((int) &fmt & ~3) + 4));
}

int vswprintf(u16 *buf, u32 maxCount, const u16 *fmt, char *va) {
    FormatPutWideTarget st;
    int writtenCount;

    st.mBuffer = buf;
    st.mSize = maxCount;
    st.mWrittenCount = 0;
    writtenCount = FormatWideWithPutFunc(FormatPutWideBuffer, &st, fmt, va);
    if (writtenCount < 0) {
        return writtenCount;
    }
    if (writtenCount < maxCount) {
        buf[writtenCount] = 0;
    } else {
        *(buf + maxCount - 1) = 0;
        return -1;
    }
    return writtenCount;
}
