#include "fx_mtx22.h"

#pragma thumb on
// Sets the four words at dst to the 2x2 rotation matrix (cosVal, sinVal, -sinVal, cosVal).
void MTX_Rot22_(MtxFx22 *dst, s32 sinVal, s32 cosVal) {
    dst->a[0] = cosVal;
    dst->a[1] = sinVal;
    dst->a[2] = -sinVal;
    dst->a[3] = cosVal;
}
#pragma thumb off

asm void MTX_Identity22_(MtxFx22 *dst) {
    mov r1, #0
    mov r2, #0x1000
    mov r3, #0
    stmia r0!, {r2, r3}
    stmia r0!, {r1, r2}
    bx lr
}
// clang-format on
