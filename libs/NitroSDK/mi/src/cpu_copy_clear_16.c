#include "cpu_copy_clear_16.h"

// Copies size bytes from srcp to destp, a halfword at a time.
void CopyMemory16(const void *srcp, void *destp, s32 size) {
    s32 offset;

    offset = 0;
    do {
        if (offset >= size) {
            break;
        }
        *(u16 *) ((u32) destp + offset) = *(const u16 *) ((u32) srcp + offset);
        offset += 2;
    } while (1);
}

// Stores data at destp, a halfword at a time, for size bytes.
void Mem_CpuFill16(u16 data, void *destp, s32 size) {
    s32 offset;

    offset = 0;
    do {
        if (offset >= size) {
            break;
        }
        *(u16 *) ((u32) destp + offset) = data;
        offset += 2;
    } while (1);
}
