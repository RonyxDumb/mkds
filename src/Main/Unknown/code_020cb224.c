#include "Main/Unknown/code_020cb224.h"

#include "Main/Unknown/code_020cb22c.h"
#include "Main/Unknown/code_020cb3e4.h"

#pragma thumb on
void menu_modeSelectStateVblank(void) {
    u32 unusedValue;
    modeSelectVblank();
}
#pragma thumb off

u32 menu_input_getDefaultInputId(void) {
    return 0x8u;
}
