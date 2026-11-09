#include "Main/Unknown/code_020cb224.h"

#include "Main/Unknown/code_020cb22c.h"
#include "Main/Unknown/code_020cb3e4.h"

#pragma thumb on
void WriteSinglePlaySelect1Registers(void) {
    u32 unusedValue;
    SetupSinglePlaySelectGraphics();
}
#pragma thumb off

u32 GetMenuInputSlot(void) {
    return 0x8u;
}
