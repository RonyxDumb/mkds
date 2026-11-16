#include "Main/Unknown/code_020e512c.h"
#include "ITCM/code_01ffdee4.h"

#pragma thumb on

u32 oshd_20E512C(Vec3 *position) {
    u32 outValue[1];
    outValue[0] = 0;
    col_collide(((s32 *) position), NULL, 0, 0x0000a000u, 8, 0xfffffffe, NULL, NULL, NULL, outValue, NULL, NULL, NULL,
                  NULL);
    return outValue[0] & (0x01000000u);
}

#pragma thumb off
