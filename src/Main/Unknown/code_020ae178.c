#include "Main/Unknown/code_020ae178.h"
#include "Main/Unknown/code_020b3f7c.h"
#include "Main/Unknown/code_020b47b4.h"
#include "Main/Unknown/unk_02168000.h"

#pragma thumb on

u32 func_020ae1d0(u32 a) {
    return (u8) (a >> 24) + (((u8) (a >> 16) << 8) + (((u8) a << 24) + ((u8) (a >> 8) << 16)));
}

void *func_020ae178(u32 a, u32 b) {
    u32 v[13] = {20, 25, 24, 27, 22, 26, 23, 21, 29, 28, 30, 31, 32};
    u32 t;

    if (b != 0 && a == 1) {
        t = 0x21;
    } else if (b != 0 && a == 8) {
        t = 0x22;
    } else {
        t = v[a];
    }
    return func_020b3f7c(func_020b47cc(data_02168114), t);
}

#pragma thumb off
