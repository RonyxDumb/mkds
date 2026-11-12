#include "gx_load3d.h"
#include "code_0214c778.h"
#include "code_02148950.h"
#include "gx_bgcnt.h"
#include "code_0214d018.h"
#include "Main/Kart/data_02161000.h"
#include "Main/Net/data_0216f000.h"
#include "os_thread.h"
#include "mb_data.h"
#include "data_02180000.h"

u32 gTextureLoadFirstBase = 0;
u32 gTextureLoadFirstSize = 0;
u32 gTextureLoadSecondBase = 0;
u32 gTextureLoadBankMask = 0;

const u16 gTextureBlockTable[16][3] = {
    {0x0000, 0x0000, 0x0000},
    {0x6800, 0x0000, 0x0000},
    {0x6820, 0x0000, 0x0000},
    {0x6800, 0x0000, 0x0000},
    {0x6840, 0x0000, 0x0000},
    {0x6800, 0x6840, 0x0020},
    {0x6820, 0x0000, 0x0000},
    {0x6800, 0x0000, 0x0000},
    {0x6860, 0x0000, 0x0000},
    {0x6800, 0x6860, 0x0020},
    {0x6820, 0x6860, 0x0020},
    {0x6800, 0x6860, 0x0040},
    {0x6840, 0x0000, 0x0000},
    {0x6800, 0x6840, 0x0020},
    {0x6820, 0x0000, 0x0000},
    {0x6800, 0x0000, 0x0000},
};

s32 gTexturePaletteLoadBankMask = 0;
u8 *gTexturePaletteLoadBase = 0;

const u16 gTexturePaletteBaseTable[8] = {0x0000, 0x6880, 0x6890, 0x6880, 0x6894, 0x0000, 0x6890, 0x6880};

u32 gClearImageLoadBankMask = 0;
u8 *gClearImageLoadBase = 0;

void GX_BeginLoadTex(void) {
    u32 mask;

    mask = GX_ResetBankForTex();
    gTextureLoadBankMask = mask;
    gTextureLoadFirstBase = gTextureBlockTable[mask][0] << 12;
    gTextureLoadSecondBase = gTextureBlockTable[mask][1] << 12;
    gTextureLoadFirstSize = gTextureBlockTable[mask][2] << 12;
}

void GX_LoadTex(const void *src, u32 offset, u32 size) {
    u8 *second;
    u32 firstSize;
    u32 firstCount;
    u8 *dest;

    second = (u8 *) gTextureLoadSecondBase;
    if (second == 0) {
        dest = (u8 *) gTextureLoadFirstBase + offset;
    } else {
        firstSize = gTextureLoadFirstSize;
        if (offset + size < firstSize) {
            dest = (u8 *) gTextureLoadFirstBase + offset;
        } else if (offset >= firstSize) {
            dest = second + offset - firstSize;
        } else {
            firstCount = firstSize - offset;
            dest = (u8 *) gTextureLoadFirstBase + offset;
            if (GXi_DmaId != -1 && firstCount > 0x30) {
                MI_DmaCopy32(GXi_DmaId, src, dest, firstCount);
            } else {
                MIi_CpuCopy32(src, dest, firstCount);
            }
            if (GXi_DmaId != -1) {
                MI_DmaCopy32Async(GXi_DmaId, (const u8 *) src + firstCount, second, size - firstCount, 0, 0);
            } else {
                MIi_CpuCopy32((const u8 *) src + firstCount, second, size - firstCount);
            }
            return;
        }
    }
    if (GXi_DmaId != -1) {
        MI_DmaCopy32Async(GXi_DmaId, src, dest, size, 0, 0);
    } else {
        MIi_CpuCopy32(src, dest, size);
    }
}

void GX_EndLoadTex(void) {
    if (GXi_DmaId != -1) {
        MI_WaitDma(GXi_DmaId);
    }
    GX_SetBankForTex(gTextureLoadBankMask);
    gTextureLoadFirstSize = 0;
    gTextureLoadSecondBase = 0;
    gTextureLoadFirstBase = 0;
    gTextureLoadBankMask = 0;
}

void GX_BeginLoadTexPltt(void) {
    s32 mask = GX_ResetBankForTexPltt();
    gTexturePaletteLoadBankMask = mask;
    gTexturePaletteLoadBase = (u8 *) (gTexturePaletteBaseTable[mask >> 4] << 12);
}

void GX_LoadTexPltt(const void *src, u32 offset, u32 size) {
    u8 *dest = gTexturePaletteLoadBase + offset;
    if (GXi_DmaId != -1) {
        MI_DmaCopy32Async(GXi_DmaId, src, dest, size, 0, 0);
    } else {
        MIi_CpuCopy32(src, dest, size);
    }
}

void GX_EndLoadTexPltt(void) {
    if (GXi_DmaId != -1) {
        MI_WaitDma(GXi_DmaId);
    }
    GX_SetBankForTexPltt(gTexturePaletteLoadBankMask);
    gTexturePaletteLoadBankMask = 0;
    gTexturePaletteLoadBase = 0;
}

void GX_BeginLoadClearImage(void) {
    u32 mask = GX_ResetBankForClearImage();
    gClearImageLoadBankMask = mask;
    switch (mask) {
        case 2:
        case 3:
            gClearImageLoadBase = (u8 *) 0x6800000;
            break;
        case 8:
        case 12:
            gClearImageLoadBase = (u8 *) 0x6840000;
            break;
        case 1:
            gClearImageLoadBase = (u8 *) 0x67e0000;
            break;
        case 4:
            gClearImageLoadBase = (u8 *) 0x6820000;
            break;
    }
}

void GX_LoadClearImageColor(const void *src, u32 size) {
    u8 *dest = gClearImageLoadBase;
    if (GXi_DmaId != -1) {
        MI_DmaCopy32Async(GXi_DmaId, src, dest, size, 0, 0);
    } else {
        MIi_CpuCopy32(src, dest, size);
    }
}

void GX_LoadClearImageDepth(const void *src, u32 size) {
    u8 *dest = gClearImageLoadBase + 0x20000;
    if (GXi_DmaId != -1) {
        MI_DmaCopy32Async(GXi_DmaId, src, dest, size, 0, 0);
    } else {
        MIi_CpuCopy32(src, dest, size);
    }
}

void GX_EndLoadClearImage(void) {
    if (GXi_DmaId != -1) {
        MI_WaitDma(GXi_DmaId);
    }
    GX_SetBankForClearImage(gClearImageLoadBankMask);
    gClearImageLoadBankMask = 0;
    gClearImageLoadBase = 0;
}
