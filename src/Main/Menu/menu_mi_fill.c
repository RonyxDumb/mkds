#include "Main/Menu/menu_mi_fill.h"
#include "Main/Unknown/code_0214d000.h"
#include "code_0214d018.h"

void MenuMI_CpuFillFast(void *dest, u32 value, u32 size) {
    volatile u32 valueCopy = value;
    MIi_CpuClearFast(valueCopy, dest, size);
}

void MenuMI_CpuClearFast(void *dest, u32 size) {
    MenuMI_CpuFillFast(dest, 0, size);
}
