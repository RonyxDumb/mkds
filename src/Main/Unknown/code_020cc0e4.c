#include "Main/Unknown/code_020cc0e4.h"

#include "Main/Unknown/code_020cc134.h"
#include "00/code_02181f98.h"
#include "registers.h"

u32 func_020cc150(u32 bits) {
    u32 value0 = bits;
    u32 registerValue;
    registerValue = reg_GX_DISPCNT;
    registerValue = (registerValue) & ~(0xe000u);
    value0 = (registerValue) | ((value0 << 13));
    reg_GX_DISPCNT = value0;
    return value0;
}

u32 func_020cc134(u32 bits) {
    u32 value0 = bits;
    u32 registerValue;
    registerValue = reg_GXS_DB_DISPCNT;
    registerValue = (registerValue) & ~(0xe000u);
    value0 = (registerValue) | ((value0 << 13));
    reg_GXS_DB_DISPCNT = value0;
    return value0;
}

u32 func_020cc120(void) {
    return (data_0217b488->mUnk_08);
}

void func_020cc10c(u32 value) {
    data_0217b488->mUnk_04 = value;
}

u32 func_020cc0f8(void) {
    return (data_0217b488->mUnk_10);
}

u32 func_020cc0e4(void) {
    return (data_0217b488->mUnk_14);
}
