#include "00/code_0219a01c.h"

void gti2UShortToBuffer(u8 *buffer, s32 offset, u16 value) {
    buffer[offset] = value >> 8;
    buffer[offset + 1] = value;
}
