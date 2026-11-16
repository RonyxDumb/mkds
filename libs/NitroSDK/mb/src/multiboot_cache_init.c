#include "multiboot_cache_init.h"
#include "cpu_copy_fill.h"

#pragma thumb on
void MemsetSomeObject_from_thumb(MBiCacheList *table) {
    MBiCacheList *address = table;
    u32 fillValue;
    u32 byteCount;
    u32 unusedValue;
    fillValue = 0u;
    byteCount = sizeof(MBiCacheList);
    Mem_CpuFill8(address, fillValue, byteCount);
}
#pragma thumb off
