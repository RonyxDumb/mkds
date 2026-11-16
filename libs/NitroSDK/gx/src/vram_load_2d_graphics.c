#include "vram_load_2d_graphics.h"
#include "dma_copy_fill_wait.h"
#include "cpu_copy_clear_16.h"
#include "vram_bank_display_setup.h"
#include "bg_screen_char_pointers.h"
#include "cpu_copy_fill.h"
#include "Main/Net/block_transfer_and_thread_globals.h"
#include "thread_scheduler.h"
#include "multiboot_piece_buffers.h"
#include "overlay_section_symbols.h"

u32 gBgExtPaletteLoadBankMask = 0;
u32 gBgExtPaletteLoadBase = 0;
u32 gBgExtPaletteLoadBaseOffset = 0;
u32 g_SomeObjExtPlt = 0;
u32 g_SomeObjExtPltLcdcBlock = 0;
u32 g_SomeSubBgExtPlt = 0;
u32 g_SomeSubObjExtPlt = 0;

void CopyPaletteTop(const void *src, u32 offset, u32 size) {
    if (g_GfxDmaChannel != -1 && size > 0x1c) {
        MI_DmaCopy16(g_GfxDmaChannel, src, (void *) (0x5000000 + offset), size);
    } else {
        CopyMemory16(src, (void *) (0x5000000 + offset), size);
    }
}

void CopyPaletteBottom(const void *src, u32 offset, u32 size) {
    if (g_GfxDmaChannel != -1 && size > 0x1c) {
        MI_DmaCopy16(g_GfxDmaChannel, src, (void *) (0x5000400 + offset), size);
    } else {
        CopyMemory16(src, (void *) (0x5000400 + offset), size);
    }
}

void CopySomePaletteData(const void *src, u32 offset, u32 size) {
    if (g_GfxDmaChannel != -1 && size > 0x1c) {
        MI_DmaCopy16(g_GfxDmaChannel, src, (void *) (0x5000200 + offset), size);
    } else {
        CopyMemory16(src, (void *) (0x5000200 + offset), size);
    }
}

void TEQSub_Fn30Impl(const void *src, u32 offset, u32 size) {
    if (g_GfxDmaChannel != -1 && size > 0x1c) {
        MI_DmaCopy16(g_GfxDmaChannel, src, (void *) (0x5000600 + offset), size);
    } else {
        CopyMemory16(src, (void *) (0x5000600 + offset), size);
    }
}

void CopyToOamA(const void *src, u32 offset, u32 size) {
    if (g_GfxDmaChannel != -1 && size > 0x30) {
        MI_DmaCopy32(g_GfxDmaChannel, src, (void *) (0x7000000 + offset), size);
    } else {
        Mem_CpuCopy32(src, (void *) (0x7000000 + offset), size);
    }
}

void CopyToOamB(const void *src, u32 offset, u32 size) {
    if (g_GfxDmaChannel != -1 && size > 0x30) {
        MI_DmaCopy32(g_GfxDmaChannel, src, (void *) (0x7000400 + offset), size);
    } else {
        Mem_CpuCopy32(src, (void *) (0x7000400 + offset), size);
    }
}

void CopyTileDataTop_0(const void *src, u32 offset, u32 size) {
    enum { OBJ_VRAM_BASE_NONE } base = 0x6400000;

    if (g_GfxDmaChannel != -1 && size > 0x30) {
        MI_DmaCopy32(g_GfxDmaChannel, src, (void *) (base + offset), size);
    } else {
        Mem_CpuCopy32(src, (void *) (base + offset), size);
    }
}

void TEQSub_Fn35Impl(const void *src, u32 offset, u32 size) {
    enum { SUB_OBJ_VRAM_BASE_NONE } base = 0x6600000;

    if (g_GfxDmaChannel != -1 && size > 0x30) {
        MI_DmaCopy32(g_GfxDmaChannel, src, (void *) (base + offset), size);
    } else {
        Mem_CpuCopy32(src, (void *) (base + offset), size);
    }
}

void TEQSub_Fn8Impl(const void *src, u32 offset, u32 size) {
    u32 ptr = G2_GetBG0ScrPtr();
    if (g_GfxDmaChannel != -1 && size > 0x1c) {
        MI_DmaCopy16(g_GfxDmaChannel, src, (void *) (ptr + offset), size);
    } else {
        CopyMemory16(src, (void *) (ptr + offset), size);
    }
}

void TEQSub_Fn24Impl(const void *src, u32 offset, u32 size) {
    u32 ptr = GetAnotherSubEngineBGOffset();
    if (g_GfxDmaChannel != -1 && size > 0x1c) {
        MI_DmaCopy16(g_GfxDmaChannel, src, (void *) (ptr + offset), size);
    } else {
        CopyMemory16(src, (void *) (ptr + offset), size);
    }
}

void TEQSub_Fn9Impl(const void *src, u32 offset, u32 size) {
    u32 ptr = G2_GetBG1ScrPtr();
    if (g_GfxDmaChannel != -1 && size > 0x1c) {
        MI_DmaCopy16(g_GfxDmaChannel, src, (void *) (ptr + offset), size);
    } else {
        CopyMemory16(src, (void *) (ptr + offset), size);
    }
}

void TEQSub_Fn25Impl(const void *src, u32 offset, u32 size) {
    u32 ptr = G2S_GetBG1ScrPtr();
    if (g_GfxDmaChannel != -1 && size > 0x1c) {
        MI_DmaCopy16(g_GfxDmaChannel, src, (void *) (ptr + offset), size);
    } else {
        CopyMemory16(src, (void *) (ptr + offset), size);
    }
}

void TEQSub_Fn10Impl_Fn12Impl(const void *src, u32 offset, u32 size) {
    u32 ptr = G2_GetBG2ScrPtr();
    if (g_GfxDmaChannel != -1 && size > 0x1c) {
        MI_DmaCopy16(g_GfxDmaChannel, src, (void *) (ptr + offset), size);
    } else {
        CopyMemory16(src, (void *) (ptr + offset), size);
    }
}

void TEQSub_Fn26Impl_Fn28Impl(const void *src, u32 offset, u32 size) {
    u32 ptr = G2S_GetBG2ScrPtr();
    if (g_GfxDmaChannel != -1 && size > 0x1c) {
        MI_DmaCopy16(g_GfxDmaChannel, src, (void *) (ptr + offset), size);
    } else {
        CopyMemory16(src, (void *) (ptr + offset), size);
    }
}

void TEQSub_Fn11Impl_Fn13Impl(const void *src, u32 offset, u32 size) {
    u32 ptr = G2_GetBG3ScrPtr();
    if (g_GfxDmaChannel != -1 && size > 0x1c) {
        MI_DmaCopy16(g_GfxDmaChannel, src, (void *) (ptr + offset), size);
    } else {
        CopyMemory16(src, (void *) (ptr + offset), size);
    }
}

void TEQSub_Fn27Impl_Fn29Impl(const void *src, u32 offset, u32 size) {
    u32 ptr = G2S_GetBG3ScrPtr();
    if (g_GfxDmaChannel != -1 && size > 0x1c) {
        MI_DmaCopy16(g_GfxDmaChannel, src, (void *) (ptr + offset), size);
    } else {
        CopyMemory16(src, (void *) (ptr + offset), size);
    }
}

void CopyBgData_Bg0_Top(const void *src, u32 offset, u32 size) {
    u32 ptr = GetVramBg0BaseOffset_Top();
    if (g_GfxDmaChannel != -1 && size > 0x30) {
        MI_DmaCopy32(g_GfxDmaChannel, src, (void *) (ptr + offset), size);
    } else {
        Mem_CpuCopy32(src, (void *) (ptr + offset), size);
    }
}

void CopyBgData_Bg0_Bottom(const void *src, u32 offset, u32 size) {
    u32 ptr = GetVramBg0BaseOffset_Bottom();
    if (g_GfxDmaChannel != -1 && size > 0x30) {
        MI_DmaCopy32(g_GfxDmaChannel, src, (void *) (ptr + offset), size);
    } else {
        Mem_CpuCopy32(src, (void *) (ptr + offset), size);
    }
}

void CopyBgData_Bg1_Top(const void *src, u32 offset, u32 size) {
    u32 ptr = GetVramBg1BaseOffset_Top();
    if (g_GfxDmaChannel != -1 && size > 0x30) {
        MI_DmaCopy32(g_GfxDmaChannel, src, (void *) (ptr + offset), size);
    } else {
        Mem_CpuCopy32(src, (void *) (ptr + offset), size);
    }
}

void CopyBgData_Bg1_Bottom(const void *src, u32 offset, u32 size) {
    u32 ptr = GetVramBg1BaseOffset_Bottom();
    if (g_GfxDmaChannel != -1 && size > 0x30) {
        MI_DmaCopy32(g_GfxDmaChannel, src, (void *) (ptr + offset), size);
    } else {
        Mem_CpuCopy32(src, (void *) (ptr + offset), size);
    }
}

void CopyBgData_Bg2_Top(const void *src, u32 offset, u32 size) {
    u32 ptr = GetVramBg2BaseOffset_Top();
    if (g_GfxDmaChannel != -1 && size > 0x30) {
        MI_DmaCopy32(g_GfxDmaChannel, src, (void *) (ptr + offset), size);
    } else {
        Mem_CpuCopy32(src, (void *) (ptr + offset), size);
    }
}

void CopyBgData_Bg2_Bottom(const void *src, u32 offset, u32 size) {
    u32 ptr = GetVramBg2BaseOffset_Bottom();
    if (g_GfxDmaChannel != -1 && size > 0x30) {
        MI_DmaCopy32(g_GfxDmaChannel, src, (void *) (ptr + offset), size);
    } else {
        Mem_CpuCopy32(src, (void *) (ptr + offset), size);
    }
}

void CopyBgData_Bg3_Top(const void *src, u32 offset, u32 size) {
    u32 ptr = GetVramBg3BaseOffset_Top();
    if (g_GfxDmaChannel != -1 && size > 0x30) {
        MI_DmaCopy32(g_GfxDmaChannel, src, (void *) (ptr + offset), size);
    } else {
        Mem_CpuCopy32(src, (void *) (ptr + offset), size);
    }
}

void CopyBgData_Bg3_Bottom(const void *src, u32 offset, u32 size) {
    u32 ptr = GetVramBg3BaseOffset_Bottom();
    if (g_GfxDmaChannel != -1 && size > 0x30) {
        MI_DmaCopy32(g_GfxDmaChannel, src, (void *) (ptr + offset), size);
    } else {
        Mem_CpuCopy32(src, (void *) (ptr + offset), size);
    }
}

void GX_BeginLoadBGExtPltt(void) {
    s32 mask;

    mask = GX_ResetBankForBGExtPltt();
    gBgExtPaletteLoadBankMask = mask;
    switch (mask) {
        case 0:
            break;
        case VRAM_BANK_E:
            gBgExtPaletteLoadBase = 0x6880000;
            gBgExtPaletteLoadBaseOffset = 0;
            break;
        case VRAM_BANK_G:
            gBgExtPaletteLoadBase = 0x6894000;
            gBgExtPaletteLoadBaseOffset = 0x4000;
            break;
        case VRAM_BANK_F:
        case VRAM_BANK_F | VRAM_BANK_G:
            gBgExtPaletteLoadBase = 0x6890000;
            gBgExtPaletteLoadBaseOffset = 0;
            break;
    }
}

void GX_LoadBGExtPltt(const void *src, u32 offset, u32 size) {
    u32 dest;

    dest = gBgExtPaletteLoadBase + offset - gBgExtPaletteLoadBaseOffset;
    if (g_GfxDmaChannel != -1) {
        MI_DmaCopy32Async(g_GfxDmaChannel, src, (void *) dest, size, 0, 0);
    } else {
        Mem_CpuCopy32(src, (void *) dest, size);
    }
}

void GX_EndLoadBGExtPltt(void) {
    if (g_GfxDmaChannel != -1) {
        MI_WaitDma(g_GfxDmaChannel);
    }
    GX_SetBankForBGExtPltt(gBgExtPaletteLoadBankMask);
    gBgExtPaletteLoadBankMask = 0;
    gBgExtPaletteLoadBase = 0;
    gBgExtPaletteLoadBaseOffset = 0;
}

void GX_BeginLoadOBJExtPltt(void) {
    s32 mask;

    mask = GX_ResetBankForOBJExtPltt();
    g_SomeObjExtPlt = mask;
    if (mask == 0) {
        return;
    }
    switch (mask) {
        case VRAM_BANK_F:
            g_SomeObjExtPltLcdcBlock = 0x6890000;
            break;
        case VRAM_BANK_G:
            g_SomeObjExtPltLcdcBlock = 0x6894000;
            break;
    }
}

void GX_LoadOBJExtPltt(const void *src, u32 offset, u32 size) {
    u32 dest;

    dest = g_SomeObjExtPltLcdcBlock + offset;
    if (g_GfxDmaChannel != -1) {
        MI_DmaCopy32Async(g_GfxDmaChannel, src, (void *) dest, size, 0, 0);
    } else {
        Mem_CpuCopy32(src, (void *) dest, size);
    }
}

void GX_EndLoadOBJExtPltt(void) {
    if (g_GfxDmaChannel != -1) {
        MI_WaitDma(g_GfxDmaChannel);
    }
    GX_SetBankForOBJExtPltt(g_SomeObjExtPlt);
    g_SomeObjExtPlt = 0;
    g_SomeObjExtPltLcdcBlock = 0;
}

void GXS_BeginLoadBGExtPltt(void) {
    g_SomeSubBgExtPlt = GX_ResetBankForSubBGExtPltt();
}

void GXS_LoadBGExtPltt(const void *src, u32 offset, u32 size) {
    if (g_GfxDmaChannel != -1) {
        MI_DmaCopy32Async(g_GfxDmaChannel, src, (void *) (offset + 0x6898000), size, 0, 0);
    } else {
        Mem_CpuCopy32(src, (void *) (offset + 0x6898000), size);
    }
}

void GXS_EndLoadBGExtPltt(void) {
    if (g_GfxDmaChannel != -1) {
        MI_WaitDma(g_GfxDmaChannel);
    }
    GX_SetBankForSubBGExtPltt(g_SomeSubBgExtPlt);
    g_SomeSubBgExtPlt = 0;
}

void GXS_BeginLoadOBJExtPltt(void) {
    g_SomeSubObjExtPlt = GX_ResetBankForSubOBJExtPltt();
}

void GXS_LoadOBJExtPltt(const void *src, u32 offset, u32 size) {
    if (g_GfxDmaChannel != -1) {
        MI_DmaCopy32Async(g_GfxDmaChannel, src, (void *) (offset + 0x68a0000), size, 0, 0);
    } else {
        Mem_CpuCopy32(src, (void *) (offset + 0x68a0000), size);
    }
}

void GXS_EndLoadOBJExtPltt(void) {
    if (g_GfxDmaChannel != -1) {
        MI_WaitDma(g_GfxDmaChannel);
    }
    GX_SetBankForSubOBJExtPltt(g_SomeSubObjExtPlt);
    g_SomeSubObjExtPlt = 0;
}
