#include "g3x.h"
#include "code_0214cfe4.h"
#include "code_0214c778.h"
#include "Main/Net/data_0216f000.h"
#include "os_thread.h"
#include "mb_data.h"
#include "00/Lib/DWC/code_02188720.h"
#include "registers.h"

void G3X_SetToonTable(const u16 *toonTable) {
    MIi_CpuCopy16(toonTable, (void *) 0x4000380, 0x40);
}

void G3X_SetClearColor(u32 rgb, u32 alpha, u16 depth, u32 polygonID, s32 fog) {
    u32 value;

    value = rgb | (alpha << 16) | (polygonID << 24);
    if (fog != 0) {
        value |= 0x8000;
    }
    reg_G3X_CLEAR_COLOR = value;
    reg_G3X_CLEAR_DEPTH = depth;
}

// Zeroes the edge color table (16 bytes at 0x4000330) and the fog table (96 bytes at 0x4000360), by DMA when
// GXi_DmaId is not -1 and by CPU otherwise, then writes 0 to the shininess command 32 times.
void G3X_InitTable(void) {
    volatile u32 zero0;
    volatile u32 zero1;
    s32 writeIndex;

    if (GXi_DmaId != -1) {
        MI_DmaFill32Async(GXi_DmaId, (void *) 0x4000330, 0, 0x10, 0, 0);
        MI_DmaFill32(GXi_DmaId, (void *) 0x4000360, 0, 0x60);
    } else {
        zero0 = 0;
        MIi_CpuClear32(zero0, (void *) 0x4000330, 0x10);
        zero1 = 0;
        MIi_CpuClear32(zero1, (void *) 0x4000360, 0x60);
    }
    for (writeIndex = 0; writeIndex < 32; writeIndex++) {
        *(vu32 *) 0x40004d0 = 0;
    }
}

// Reads the position/vector matrix stack level (GXSTAT bits 8-12) into *level. Returns -1 while the stack is busy
// (GXSTAT bit 14 set).
s32 G3X_GetMtxStackLevelPV(s32 *level) {
    if (reg_G3X_GXSTAT & 0x4000) {
        return -1;
    }
    *level = (reg_G3X_GXSTAT & 0x1f00) >> 8;
    return 0;
}

// Reads the projection matrix stack level (GXSTAT bit 13) into *level. Returns -1 while the stack is busy
// (GXSTAT bit 14 set).
s32 G3X_GetMtxStackLevelPJ(s32 *level) {
    if (reg_G3X_GXSTAT & 0x4000) {
        return -1;
    }
    *level = (reg_G3X_GXSTAT & 0x2000) >> 13;
    return 0;
}

void G2Bg0OfsWrite(u32 offset) {
    reg_G2_BG0OFS = offset;
}

asm void GXi_NopClearFifo128_(void *dest) {
    mov r1, #0
    mov r2, #0
    mov r3, #0
    mov ip, #0
    stmia r0, {r1, r2, r3, ip}
    stmia r0, {r1, r2, r3, ip}
    stmia r0, {r1, r2, r3, ip}
    stmia r0, {r1, r2, r3, ip}
    stmia r0, {r1, r2, r3, ip}
    stmia r0, {r1, r2, r3, ip}
    stmia r0, {r1, r2, r3, ip}
    stmia r0, {r1, r2, r3, ip}
    stmia r0, {r1, r2, r3, ip}
    stmia r0, {r1, r2, r3, ip}
    stmia r0, {r1, r2, r3, ip}
    stmia r0, {r1, r2, r3, ip}
    stmia r0, {r1, r2, r3, ip}
    stmia r0, {r1, r2, r3, ip}
    stmia r0, {r1, r2, r3, ip}
    stmia r0, {r1, r2, r3, ip}
    stmia r0, {r1, r2, r3, ip}
    stmia r0, {r1, r2, r3, ip}
    stmia r0, {r1, r2, r3, ip}
    stmia r0, {r1, r2, r3, ip}
    stmia r0, {r1, r2, r3, ip}
    stmia r0, {r1, r2, r3, ip}
    stmia r0, {r1, r2, r3, ip}
    stmia r0, {r1, r2, r3, ip}
    stmia r0, {r1, r2, r3, ip}
    stmia r0, {r1, r2, r3, ip}
    stmia r0, {r1, r2, r3, ip}
    stmia r0, {r1, r2, r3, ip}
    stmia r0, {r1, r2, r3, ip}
    stmia r0, {r1, r2, r3, ip}
    stmia r0, {r1, r2, r3, ip}
    stmia r0, {r1, r2, r3, ip}
    bx lr
}
// clang-format on
