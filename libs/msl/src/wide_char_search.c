#pragma avoid_byte all

#include "wide_char_search.h"

u16 *wmemchr(const u16 *buffer, int wideChar, u32 count) {
    while (count != 0) {
        if (*buffer == wideChar) {
            return (u16 *) buffer;
        }
        buffer++;
        count--;
    }
    return 0;
}

int fwide(FILE *stream, int mode) {
    if (stream == 0 || stream->mKind == FILE_KIND_NONE) {
        return 0;
    }
    switch (stream->mWideMode) {
        case FILE_WIDE_MODE_UNSET:
            if (mode > 0) {
                stream->mWideMode = FILE_WIDE_MODE_POSITIVE;
            } else if (mode < 0) {
                stream->mWideMode = FILE_WIDE_MODE_NEGATIVE;
            }
            break;
        case FILE_WIDE_MODE_NEGATIVE:
            mode = -1;
            break;
        case FILE_WIDE_MODE_POSITIVE:
            mode = 1;
            break;
    }
    return mode;
}
