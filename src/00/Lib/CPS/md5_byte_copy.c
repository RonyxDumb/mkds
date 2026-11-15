#include "00/Lib/CPS/md5_byte_copy.h"
#include "cpu_copy_fill.h"

void Md5ResultCopyBytes(u32 destination, u32 source, u32 size) {
    u32 addressA = destination;
    u32 addressB = source;
    u32 byteCount = size;
    u32 addressC;
    addressC = (addressA) + (0u);
    addressA = (addressB) + (0u);
    addressB = (addressC) + (0u);
    MI_CpuCopy8((const void *) addressA, (void *) addressB, byteCount);
}

void Md5BlockCopyBytes(void *destination, const void *source, u32 size) {
    MI_CpuCopy8(source, destination, size);
}
