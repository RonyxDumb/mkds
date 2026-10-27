#include "00/code_0219a028.h"

u32 func_ov000_0219a028(const u8 *buffer, s32 offset) {
    u16 value = (buffer[offset] << 8) & 0xff00;
    return value | buffer[offset + 1];
}
