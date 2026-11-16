#include "Main/Menu/menu_mi_fill.h"
#include "cpu_copy_fill.h"

void MenuMI_CpuFillFast(void *dest, u32 value, u32 size) {
    volatile u32 valueCopy = value;
    MIi_CpuClearFast(valueCopy, dest, size);
}

void MenuMI_CpuClearFast(void *dest, u32 size) {
    MenuMI_CpuFillFast(dest, 0, size);
}
