#include "00/code_0219a01c.h"

void func_ov000_0219a01c(u8 *buffer, s32 offset, u16 value) {
    buffer[offset] = value >> 8;
    buffer[offset + 1] = value;
}
