#include "Main/Menu/menu_mi_fill.h"
#include "cpu_copy_fill.h"

void SpecialMemoryMemsetV2(void *dest, u32 value, u32 size) {
    volatile u32 valueCopy = value;
    Mem_CpuFastMemorySet(valueCopy, dest, size);
}

void SpecialMemoryZero_0(void *dest, u32 size) {
    SpecialMemoryMemsetV2(dest, 0, size);
}
