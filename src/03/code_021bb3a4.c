#include "03/code_021bb3a4.h"

void func_ov003_021bb3a4(void *buffer, s32 value, u32 count) {
    s8 *p = buffer;
    u32 i = 0;
    for (i = 0; i < count; i++) {
        *p++ = value;
    }
}
