#include "03/code_021bb408.h"

void func_ov003_021bb408(u8 *output, const u32 *input, u32 size) {
    u32 i;
    for (i = 0; i < size; i += 4) {
        output[i] = *input;
        output[i + 1] = *input >> 8;
        output[i + 2] = *input >> 16;
        output[i + 3] = *input >> 24;
        input++;
    }
}
