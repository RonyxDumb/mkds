#include "Main/Save/bit_array_byte.h"

#pragma thumb on

// The byte of an array of bits that holds the given bit; only the low 11 bits of the number count.
u8 *GetGhostDataByteByCourse_from_thumb(u32 bitIndex, u8 *bytes) {
    return bytes + ((bitIndex << 21) >> 24);
}

#pragma thumb off
