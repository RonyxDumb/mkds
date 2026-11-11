#include "00/code_0219a028.h"

u32 gti2UShortFromBuffer(const u8 *buffer, s32 offset) {
    u16 value = (buffer[offset] << 8) & 0xff00;
    return value | buffer[offset + 1];
}
