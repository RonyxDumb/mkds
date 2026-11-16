#include "Main/Unknown/code_020cc0e4.h"

#include "Main/Unknown/code_020cc134.h"
#include "00/code_02181f98.h"

u32 menu_GX_SetVisibleWnd(u32 bits) {
    u32 value0 = bits;
    u32 registerValue;
    u32 registerAddress;
    registerAddress = 0x4000000u;
    registerValue = *(const u32 *) ((registerAddress) + (0));
    registerValue = (registerValue) & ~(0xe000u);
    value0 = (registerValue) | ((value0 << 13));
    *(u32 *) ((registerAddress) + (0)) = value0;
    return value0;
}

u32 menu_GXS_SetVisibleWnd(u32 bits) {
    u32 value0 = bits;
    u32 registerValue;
    u32 registerAddress;
    registerAddress = 0x4001000u;
    registerValue = *(const u32 *) ((registerAddress) + (0));
    registerValue = (registerValue) & ~(0xe000u);
    value0 = (registerValue) | ((value0 << 13));
    *(u32 *) ((registerAddress) + (0)) = value0;
    return value0;
}

u32 func_020cc120(void) {
    return (gStruct217B488->field8);
}

void func_020cc10c(u32 value) {
    gStruct217B488->field4 = value;
}

u32 func_020cc0f8(void) {
    return (gStruct217B488->field10);
}

u32 func_020cc0e4(void) {
    return (gStruct217B488->field14);
}
