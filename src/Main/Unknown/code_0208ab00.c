#include "Main/Unknown/code_0208ab00.h"
#include "ITCM/code_01ff8000.h"

void SendLight01Color(u16 *colorPtr) {
    u32 color;
    u32 colorWithBit30;
    color = *colorPtr;
    NNS_G3dGeBufferOP_N(0x33, (void *) ((u32) (&color)), 1);
    colorWithBit30 = *colorPtr | 0x40000000;
    NNS_G3dGeBufferOP_N(0x33, (void *) ((u32) (&colorWithBit30)), 1);
}

void SendWhiteLight01Color(void) {
    u32 color;
    u32 colorWithBit30[1];
    color = (0x00007fffu);
    NNS_G3dGeBufferOP_N(0x33, (void *) ((u32) (&color)), 1);
    colorWithBit30[0] = (0x40007fffu);
    NNS_G3dGeBufferOP_N(0x33, colorWithBit30, 1);
}
