#include "00/code_0218a018.h"

u32 ConvAddress(const u8 *bytes) {
    u32 value0 = (u32) bytes;
    u32 word;
    u32 value2;
    u32 value3;
    u32 value4;
    word = 0u;
    value2 = *(const u8 *) ((value0) + 0u);
    value2 = (value2 << 24);
    word = (word) | (value2);
    value2 = *(const u8 *) ((value0) + 1u);
    value2 = (value2 << 16);
    word = (word) | (value2);
    value2 = *(const u8 *) ((value0) + 2u);
    value2 = (value2 << 8);
    word = (word) | (value2);
    value0 = *(const u8 *) ((value0) + 3u);
    word = (word) | (value0);
    value0 = (word << 24);
    value2 = 0xff000000u;
    value0 = (value0) & (value2);
    value4 = (word << 8);
    value2 = 0xff0000u;
    value4 = (value4) & (value2);
    value3 = (word >> 24);
    value2 = 255u;
    value3 = (value3) & (value2);
    value2 = (word >> 8);
    word = 0xff00u;
    value2 = (value2) & (word);
    value3 = (value3) | (value2);
    value4 = (value4) | (value3);
    value0 = (value0) | (value4);
    return value0;
}
