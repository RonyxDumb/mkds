#include "Main/Unknown/code_020ca820.h"

#pragma thumb on
void func_020ca83c(void) {
    u32 value3;
    value3 = (u32) &func_020cab8c;
    func_020cab8c();
    return;
}
#pragma thumb off

u32 func_020ca820(void) {
    u32 value0;
    value0 = (u32) func_020364e8();
    value0 = (u32) func_020364e0((void *) value0);
    return (u32) value0;
}
