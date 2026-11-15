#include "gx_load2d.h"
#include "code_0214c778.h"
#include "code_0214cfe4.h"
#include "code_02148950.h"
#include "gx_bgcnt.h"
#include "code_0214d018.h"
#include "Main/Net/data_0216f000.h"
#include "os_thread.h"
#include "mb_data.h"
#include "data_02180000.h"

u32 gBgExtPaletteLoadBankMask = 0;
u32 gBgExtPaletteLoadBase = 0;
u32 gBgExtPaletteLoadBaseOffset = 0;
u32 gObjExtPaletteLoadBankMask = 0;
u32 gObjExtPaletteLoadBase = 0;
u32 gSubBgExtPaletteLoadBankMask = 0;
u32 gSubObjExtPaletteLoadBankMask = 0;

void GX_LoadBGPltt(const void *src, u32 offset, u32 size) {
    if (GXi_DmaId != -1 && size > 0x1c) {
        MI_DmaCopy16(GXi_DmaId, src, (void *) (0x5000000 + offset), size);
    } else {
        MIi_CpuCopy16(src, (void *) (0x5000000 + offset), size);
    }
}

void GXS_LoadBGPltt(const void *src, u32 offset, u32 size) {
    if (GXi_DmaId != -1 && size > 0x1c) {
        MI_DmaCopy16(GXi_DmaId, src, (void *) (0x5000400 + offset), size);
    } else {
        MIi_CpuCopy16(src, (void *) (0x5000400 + offset), size);
    }
}

void GX_LoadOBJPltt(const void *src, u32 offset, u32 size) {
    if (GXi_DmaId != -1 && size > 0x1c) {
        MI_DmaCopy16(GXi_DmaId, src, (void *) (0x5000200 + offset), size);
    } else {
        MIi_CpuCopy16(src, (void *) (0x5000200 + offset), size);
    }
}

void GXS_LoadOBJPltt(const void *src, u32 offset, u32 size) {
    if (GXi_DmaId != -1 && size > 0x1c) {
        MI_DmaCopy16(GXi_DmaId, src, (void *) (0x5000600 + offset), size);
    } else {
        MIi_CpuCopy16(src, (void *) (0x5000600 + offset), size);
    }
}

void GX_LoadOAM(const void *src, u32 offset, u32 size) {
    if (GXi_DmaId != -1 && size > 0x30) {
        MI_DmaCopy32(GXi_DmaId, src, (void *) (0x7000000 + offset), size);
    } else {
        MIi_CpuCopy32(src, (void *) (0x7000000 + offset), size);
    }
}

void GXS_LoadOAM(const void *src, u32 offset, u32 size) {
    if (GXi_DmaId != -1 && size > 0x30) {
        MI_DmaCopy32(GXi_DmaId, src, (void *) (0x7000400 + offset), size);
    } else {
        MIi_CpuCopy32(src, (void *) (0x7000400 + offset), size);
    }
}

void GX_LoadOBJ(const void *src, u32 offset, u32 size) {
    enum { OBJ_VRAM_BASE_NONE } base = 0x6400000;

    if (GXi_DmaId != -1 && size > 0x30) {
        MI_DmaCopy32(GXi_DmaId, src, (void *) (base + offset), size);
    } else {
        MIi_CpuCopy32(src, (void *) (base + offset), size);
    }
}

void GXS_LoadOBJ(const void *src, u32 offset, u32 size) {
    enum { SUB_OBJ_VRAM_BASE_NONE } base = 0x6600000;

    if (GXi_DmaId != -1 && size > 0x30) {
        MI_DmaCopy32(GXi_DmaId, src, (void *) (base + offset), size);
    } else {
        MIi_CpuCopy32(src, (void *) (base + offset), size);
    }
}

void GX_LoadBG0Scr(const void *src, u32 offset, u32 size) {
    u32 ptr = G2_GetBG0ScrPtr();
    if (GXi_DmaId != -1 && size > 0x1c) {
        MI_DmaCopy16(GXi_DmaId, src, (void *) (ptr + offset), size);
    } else {
        MIi_CpuCopy16(src, (void *) (ptr + offset), size);
    }
}

void GXS_LoadBG0Scr(const void *src, u32 offset, u32 size) {
    u32 ptr = G2S_GetBG0ScrPtr();
    if (GXi_DmaId != -1 && size > 0x1c) {
        MI_DmaCopy16(GXi_DmaId, src, (void *) (ptr + offset), size);
    } else {
        MIi_CpuCopy16(src, (void *) (ptr + offset), size);
    }
}

void GX_LoadBG1Scr(const void *src, u32 offset, u32 size) {
    u32 ptr = G2_GetBG1ScrPtr();
    if (GXi_DmaId != -1 && size > 0x1c) {
        MI_DmaCopy16(GXi_DmaId, src, (void *) (ptr + offset), size);
    } else {
        MIi_CpuCopy16(src, (void *) (ptr + offset), size);
    }
}

void GXS_LoadBG1Scr(const void *src, u32 offset, u32 size) {
    u32 ptr = G2S_GetBG1ScrPtr();
    if (GXi_DmaId != -1 && size > 0x1c) {
        MI_DmaCopy16(GXi_DmaId, src, (void *) (ptr + offset), size);
    } else {
        MIi_CpuCopy16(src, (void *) (ptr + offset), size);
    }
}

void GX_LoadBG2Scr(const void *src, u32 offset, u32 size) {
    u32 ptr = G2_GetBG2ScrPtr();
    if (GXi_DmaId != -1 && size > 0x1c) {
        MI_DmaCopy16(GXi_DmaId, src, (void *) (ptr + offset), size);
    } else {
        MIi_CpuCopy16(src, (void *) (ptr + offset), size);
    }
}

void GXS_LoadBG2Scr(const void *src, u32 offset, u32 size) {
    u32 ptr = G2S_GetBG2ScrPtr();
    if (GXi_DmaId != -1 && size > 0x1c) {
        MI_DmaCopy16(GXi_DmaId, src, (void *) (ptr + offset), size);
    } else {
        MIi_CpuCopy16(src, (void *) (ptr + offset), size);
    }
}

void GX_LoadBG3Scr(const void *src, u32 offset, u32 size) {
    u32 ptr = G2_GetBG3ScrPtr();
    if (GXi_DmaId != -1 && size > 0x1c) {
        MI_DmaCopy16(GXi_DmaId, src, (void *) (ptr + offset), size);
    } else {
        MIi_CpuCopy16(src, (void *) (ptr + offset), size);
    }
}

void GXS_LoadBG3Scr(const void *src, u32 offset, u32 size) {
    u32 ptr = G2S_GetBG3ScrPtr();
    if (GXi_DmaId != -1 && size > 0x1c) {
        MI_DmaCopy16(GXi_DmaId, src, (void *) (ptr + offset), size);
    } else {
        MIi_CpuCopy16(src, (void *) (ptr + offset), size);
    }
}

void GX_LoadBG0Char(const void *src, u32 offset, u32 size) {
    u32 ptr = G2_GetBG0CharPtr();
    if (GXi_DmaId != -1 && size > 0x30) {
        MI_DmaCopy32(GXi_DmaId, src, (void *) (ptr + offset), size);
    } else {
        MIi_CpuCopy32(src, (void *) (ptr + offset), size);
    }
}

void GXS_LoadBG0Char(const void *src, u32 offset, u32 size) {
    u32 ptr = G2S_GetBG0CharPtr();
    if (GXi_DmaId != -1 && size > 0x30) {
        MI_DmaCopy32(GXi_DmaId, src, (void *) (ptr + offset), size);
    } else {
        MIi_CpuCopy32(src, (void *) (ptr + offset), size);
    }
}

void GX_LoadBG1Char(const void *src, u32 offset, u32 size) {
    u32 ptr = G2_GetBG1CharPtr();
    if (GXi_DmaId != -1 && size > 0x30) {
        MI_DmaCopy32(GXi_DmaId, src, (void *) (ptr + offset), size);
    } else {
        MIi_CpuCopy32(src, (void *) (ptr + offset), size);
    }
}

void GXS_LoadBG1Char(const void *src, u32 offset, u32 size) {
    u32 ptr = G2S_GetBG1CharPtr();
    if (GXi_DmaId != -1 && size > 0x30) {
        MI_DmaCopy32(GXi_DmaId, src, (void *) (ptr + offset), size);
    } else {
        MIi_CpuCopy32(src, (void *) (ptr + offset), size);
    }
}

void GX_LoadBG2Char(const void *src, u32 offset, u32 size) {
    u32 ptr = G2_GetBG2CharPtr();
    if (GXi_DmaId != -1 && size > 0x30) {
        MI_DmaCopy32(GXi_DmaId, src, (void *) (ptr + offset), size);
    } else {
        MIi_CpuCopy32(src, (void *) (ptr + offset), size);
    }
}

void GXS_LoadBG2Char(const void *src, u32 offset, u32 size) {
    u32 ptr = G2S_GetBG2CharPtr();
    if (GXi_DmaId != -1 && size > 0x30) {
        MI_DmaCopy32(GXi_DmaId, src, (void *) (ptr + offset), size);
    } else {
        MIi_CpuCopy32(src, (void *) (ptr + offset), size);
    }
}

void GX_LoadBG3Char(const void *src, u32 offset, u32 size) {
    u32 ptr = G2_GetBG3CharPtr();
    if (GXi_DmaId != -1 && size > 0x30) {
        MI_DmaCopy32(GXi_DmaId, src, (void *) (ptr + offset), size);
    } else {
        MIi_CpuCopy32(src, (void *) (ptr + offset), size);
    }
}

void GXS_LoadBG3Char(const void *src, u32 offset, u32 size) {
    u32 ptr = G2S_GetBG3CharPtr();
    if (GXi_DmaId != -1 && size > 0x30) {
        MI_DmaCopy32(GXi_DmaId, src, (void *) (ptr + offset), size);
    } else {
        MIi_CpuCopy32(src, (void *) (ptr + offset), size);
    }
}

void GX_BeginLoadBGExtPltt(void) {
    s32 mask;

    mask = GX_ResetBankForBGExtPltt();
    gBgExtPaletteLoadBankMask = mask;
    switch (mask) {
        case 0:
            break;
        case 0x10:
            gBgExtPaletteLoadBase = 0x6880000;
            gBgExtPaletteLoadBaseOffset = 0;
            break;
        case 0x40:
            gBgExtPaletteLoadBase = 0x6894000;
            gBgExtPaletteLoadBaseOffset = 0x4000;
            break;
        case 0x20:
        case 0x60:
            gBgExtPaletteLoadBase = 0x6890000;
            gBgExtPaletteLoadBaseOffset = 0;
            break;
    }
}

void GX_LoadBGExtPltt(const void *src, u32 offset, u32 size) {
    u32 dest;

    dest = gBgExtPaletteLoadBase + offset - gBgExtPaletteLoadBaseOffset;
    if (GXi_DmaId != -1) {
        MI_DmaCopy32Async(GXi_DmaId, src, (void *) dest, size, 0, 0);
    } else {
        MIi_CpuCopy32(src, (void *) dest, size);
    }
}

void GX_EndLoadBGExtPltt(void) {
    if (GXi_DmaId != -1) {
        MI_WaitDma(GXi_DmaId);
    }
    GX_SetBankForBGExtPltt(gBgExtPaletteLoadBankMask);
    gBgExtPaletteLoadBankMask = 0;
    gBgExtPaletteLoadBase = 0;
    gBgExtPaletteLoadBaseOffset = 0;
}

void GX_BeginLoadOBJExtPltt(void) {
    s32 mask;

    mask = GX_ResetBankForOBJExtPltt();
    gObjExtPaletteLoadBankMask = mask;
    if (mask == 0) {
        return;
    }
    switch (mask) {
        case 0x20:
            gObjExtPaletteLoadBase = 0x6890000;
            break;
        case 0x40:
            gObjExtPaletteLoadBase = 0x6894000;
            break;
    }
}

void GX_LoadOBJExtPltt(const void *src, u32 offset, u32 size) {
    u32 dest;

    dest = gObjExtPaletteLoadBase + offset;
    if (GXi_DmaId != -1) {
        MI_DmaCopy32Async(GXi_DmaId, src, (void *) dest, size, 0, 0);
    } else {
        MIi_CpuCopy32(src, (void *) dest, size);
    }
}

void GX_EndLoadOBJExtPltt(void) {
    if (GXi_DmaId != -1) {
        MI_WaitDma(GXi_DmaId);
    }
    GX_SetBankForOBJExtPltt(gObjExtPaletteLoadBankMask);
    gObjExtPaletteLoadBankMask = 0;
    gObjExtPaletteLoadBase = 0;
}

void GXS_BeginLoadBGExtPltt(void) {
    gSubBgExtPaletteLoadBankMask = GX_ResetBankForSubBGExtPltt();
}

void GXS_LoadBGExtPltt(const void *src, u32 offset, u32 size) {
    if (GXi_DmaId != -1) {
        MI_DmaCopy32Async(GXi_DmaId, src, (void *) (offset + 0x6898000), size, 0, 0);
    } else {
        MIi_CpuCopy32(src, (void *) (offset + 0x6898000), size);
    }
}

void GXS_EndLoadBGExtPltt(void) {
    if (GXi_DmaId != -1) {
        MI_WaitDma(GXi_DmaId);
    }
    GX_SetBankForSubBGExtPltt(gSubBgExtPaletteLoadBankMask);
    gSubBgExtPaletteLoadBankMask = 0;
}

void GXS_BeginLoadOBJExtPltt(void) {
    gSubObjExtPaletteLoadBankMask = GX_ResetBankForSubOBJExtPltt();
}

void GXS_LoadOBJExtPltt(const void *src, u32 offset, u32 size) {
    if (GXi_DmaId != -1) {
        MI_DmaCopy32Async(GXi_DmaId, src, (void *) (offset + 0x68a0000), size, 0, 0);
    } else {
        MIi_CpuCopy32(src, (void *) (offset + 0x68a0000), size);
    }
}

void GXS_EndLoadOBJExtPltt(void) {
    if (GXi_DmaId != -1) {
        MI_WaitDma(GXi_DmaId);
    }
    GX_SetBankForSubOBJExtPltt(gSubObjExtPaletteLoadBankMask);
    gSubObjExtPaletteLoadBankMask = 0;
}
