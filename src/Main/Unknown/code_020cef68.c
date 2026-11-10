#include "Main/Unknown/code_020cef68.h"
#include "Main/Unknown/code_0214d000.h"
#include "code_0214d018.h"

void MenuFillMemoryFast(void *dest, u32 value, u32 size) {
    volatile u32 valueCopy = value;
    MIi_CpuClearFast(valueCopy, dest, size);
}

void MenuClearMemoryFast(void *dest, u32 size) {
    MenuFillMemoryFast(dest, 0, size);
}
