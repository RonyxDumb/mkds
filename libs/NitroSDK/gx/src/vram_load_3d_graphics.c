#include "vram_load_3d_graphics.h"
#include "dma_copy_fill_wait.h"
#include "vram_bank_display_setup.h"
#include "bg_screen_char_pointers.h"
#include "cpu_copy_fill.h"
#include "Main/Graphics/animation_function_pointers.h"
#include "Main/Net/block_transfer_and_thread_globals.h"
#include "thread_scheduler.h"
#include "multiboot_piece_buffers.h"
#include "overlay_section_symbols.h"

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
            if (g_GfxDmaChannel != -1 && firstCount > 0x30) {
                MI_DmaCopy32(g_GfxDmaChannel, src, dest, firstCount);
            } else {
                Mem_CpuCopy32(src, dest, firstCount);
            }
            if (g_GfxDmaChannel != -1) {
                MI_DmaCopy32Async(g_GfxDmaChannel, (const u8 *) src + firstCount, second, size - firstCount, 0, 0);
            } else {
                Mem_CpuCopy32((const u8 *) src + firstCount, second, size - firstCount);
            }
            return;
        }
    }
    if (g_GfxDmaChannel != -1) {
        MI_DmaCopy32Async(g_GfxDmaChannel, src, dest, size, 0, 0);
    } else {
        Mem_CpuCopy32(src, dest, size);
    }
}

void GX_EndLoadTex(void) {
    if (g_GfxDmaChannel != -1) {
        MI_WaitDma(g_GfxDmaChannel);
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

void SomeDmaCopy_0(const void *src, u32 offset, u32 size) {
    u8 *dest = gTexturePaletteLoadBase + offset;
    if (g_GfxDmaChannel != -1) {
        MI_DmaCopy32Async(g_GfxDmaChannel, src, dest, size, 0, 0);
    } else {
        Mem_CpuCopy32(src, dest, size);
    }
}

void GX_EndLoadTexPltt(void) {
    if (g_GfxDmaChannel != -1) {
        MI_WaitDma(g_GfxDmaChannel);
    }
    GX_SetBankForTexPltt(gTexturePaletteLoadBankMask);
    gTexturePaletteLoadBankMask = 0;
    gTexturePaletteLoadBase = 0;
}

void GX_BeginLoadClearImage(void) {
    u32 mask = GX_ResetBankForClearImage();
    gClearImageLoadBankMask = mask;
    switch (mask) {
        case VRAM_BANK_B:
        case VRAM_BANK_A | VRAM_BANK_B:
            gClearImageLoadBase = (u8 *) 0x6800000;
            break;
        case VRAM_BANK_D:
        case VRAM_BANK_C | VRAM_BANK_D:
            gClearImageLoadBase = (u8 *) 0x6840000;
            break;
        case VRAM_BANK_A:
            gClearImageLoadBase = (u8 *) 0x67e0000;
            break;
        case VRAM_BANK_C:
            gClearImageLoadBase = (u8 *) 0x6820000;
            break;
    }
}

void GX_LoadClearImageColor(const void *src, u32 size) {
    u8 *dest = gClearImageLoadBase;
    if (g_GfxDmaChannel != -1) {
        MI_DmaCopy32Async(g_GfxDmaChannel, src, dest, size, 0, 0);
    } else {
        Mem_CpuCopy32(src, dest, size);
    }
}

void GX_LoadClearImageDepth(const void *src, u32 size) {
    u8 *dest = gClearImageLoadBase + 0x20000;
    if (g_GfxDmaChannel != -1) {
        MI_DmaCopy32Async(g_GfxDmaChannel, src, dest, size, 0, 0);
    } else {
        Mem_CpuCopy32(src, dest, size);
    }
}

void GX_EndLoadClearImage(void) {
    if (g_GfxDmaChannel != -1) {
        MI_WaitDma(g_GfxDmaChannel);
    }
    GX_SetBankForClearImage(gClearImageLoadBankMask);
    gClearImageLoadBankMask = 0;
    gClearImageLoadBase = 0;
}
