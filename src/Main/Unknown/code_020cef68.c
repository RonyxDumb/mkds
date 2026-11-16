#include "Main/Unknown/code_020cef68.h"
#include "Main/Unknown/code_0214d000.h"
#include "code_0214d018.h"

void struct217B488_MI_CpuFillFast(void *dest, u32 value, u32 size) {
    volatile u32 valueCopy = value;
    MIi_CpuClearFast(valueCopy, dest, size);
}

void struct217B488_MI_CpuClearFast(void *dest, u32 size) {
    struct217B488_MI_CpuFillFast(dest, 0, size);
}
