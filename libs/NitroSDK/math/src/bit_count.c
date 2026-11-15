#include "bit_count.h"

u32 CountSetBits(u32 value) {
    value = value - ((value >> 1) & 0x55555555);
    value = (value & 0x33333333) + ((value >> 2) & 0x33333333);
    value = (value + (value >> 4)) & 0x0f0f0f0f;
    value = value + (value >> 8);
    value = value + (value >> 16);
    return value & 0xff;
}
