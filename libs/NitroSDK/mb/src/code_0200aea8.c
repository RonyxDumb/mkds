#include "code_0200aea8.h"
#include "code_0214d018.h"

#pragma thumb on
void MBi_InitCache(MBiCacheList *table) {
    MBiCacheList *address = table;
    u32 fillValue;
    u32 byteCount;
    u32 unusedValue;
    fillValue = 0u;
    byteCount = sizeof(MBiCacheList);
    MI_CpuFill8(address, fillValue, byteCount);
}
#pragma thumb off
