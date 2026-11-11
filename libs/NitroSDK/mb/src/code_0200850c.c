#include "code_0200850c.h"
#include "code_0214d018.h"

#pragma thumb on

void MBi_ReadSegmentHeader(u32 *segmentHeader, u32 offsetStart, u32 offsetEnd, int fillFlag) {
    u32 rangeStart;
    if (offsetStart < (0x00004000u)) {
        offsetStart = (0x00004000u);
    }
    if ((0x00008000u) < offsetEnd) {
        offsetEnd = (0x00008000u);
    }
    rangeStart = *segmentHeader;
    if (offsetStart < rangeStart) {
        offsetStart = rangeStart;
    }
    if (offsetEnd > rangeStart + segmentHeader[3]) {
        offsetEnd = rangeStart + segmentHeader[3];
    }
    if (offsetStart < offsetEnd) {
        if (fillFlag != 0) {
            MI_CpuFill8(((u32 *) (u32) (segmentHeader[2] + offsetStart)), 0, offsetEnd - offsetStart);
            return;
        }
        MI_CpuCopy8(((u16 *) (u32) (segmentHeader[1] + offsetStart)), ((u32 *) (u32) (segmentHeader[2] + offsetStart)),
                    offsetEnd - offsetStart);
    }
}

#pragma thumb off
