#include "03/code_021b7ed0.h"

void func_ov003_021b7ed0(const s8 *key, u8 *buffer, s32 size) {
    s32 half = size / 2;
    s32 i;
    for (i = 0; i < half; i++) {
        buffer[half + i] ^= key[i];
    }
}
