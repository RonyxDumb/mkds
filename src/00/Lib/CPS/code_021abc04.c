#include "00/Lib/CPS/code_021abc04.h"
#include "code_0214d018.h"

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
