#include "00/Lib/CPS/code_021abc04.h"
#include "code_0214d018.h"

void Md5ResultCopyBytes(u32 destination, u32 source, u32 size) {
    u32 value0 = destination;
    u32 value1 = source;
    u32 value2 = size;
    u32 value3;
    value3 = (value0) + (0u);
    value0 = (value1) + (0u);
    value1 = (value3) + (0u);
    MI_CpuCopy8((const void *) value0, (void *) value1, value2);
}

void Md5BlockCopyBytes(void *destination, const void *source, u32 size) {
    MI_CpuCopy8(source, destination, size);
}
