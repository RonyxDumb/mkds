#pragma avoid_byte all

#include "code_0213c94c.h"

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
    if (stream == 0 || stream->mUnk_04_7 == 0) {
        return 0;
    }
    switch (stream->mUnk_04_10) {
        case 0:
            if (mode > 0) {
                stream->mUnk_04_10 = 2;
            } else if (mode < 0) {
                stream->mUnk_04_10 = 1;
            }
            break;
        case 1:
            mode = -1;
            break;
        case 2:
            mode = 1;
            break;
    }
    return mode;
}
