#include "03/code_021bb3d8.h"

void func_ov003_021bb3d8(u32 *output, const u8 *input, u32 size) {
    u32 i;
    for (i = 0; i < size; i += 4) {
        *output++ = ((u32) input[i + 3] << 24) | ((input[i + 2] << 16) | (input[i] | (input[i + 1] << 8)));
    }
}
