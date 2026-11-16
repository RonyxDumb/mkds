#include "vram_bank_display_setup.h"

#include "Main/Net/block_transfer_and_thread_globals.h"
#include "thread_scheduler.h"
#include "multiboot_piece_buffers.h"
#include "overlay_section_symbols.h"
#include "lock_word_and_bus_ownership.h"
#include "reset_interrupts_halt.h"
#include "dma_copy_fill_wait.h"
#include "00/Lib/DWC/access_point_manager.h"
#include "model_texture_bind.h"
#include "registers.h"

u16 gDispOn[2] = {1, 0};
u32 g_GfxDmaChannel = 3;
s32 sDayOfYear[12] = {0, 0x1f, 0x3b, 0x5a, 0x78, 0x97, 0xb5, 0xd4, 0xf3, 0x111, 0x130, 0x14e};
u16 g_Gfx_VramLockId = 0;
u16 g_CurrentDisplayMode = 0;
u16 g_Gfx_State[13] = {0};

void GX_VRAMCNT_SetLCDC_(u32 lcdc) {
    if (lcdc & 0x1) {
        reg_GX_VRAMCNT_A = 0x80;
    }
    if (lcdc & 0x2) {
        reg_GX_VRAMCNT_B = 0x80;
    }
    if (lcdc & 0x4) {
        reg_GX_VRAMCNT_C = 0x80;
    }
    if (lcdc & 0x8) {
        reg_GX_VRAMCNT_D = 0x80;
    }
    if (lcdc & 0x10) {
        reg_GX_VRAMCNT_E = 0x80;
    }
    if (lcdc & 0x20) {
        reg_GX_VRAMCNT_F = 0x80;
    }
    if (lcdc & 0x40) {
        reg_GX_VRAMCNT_G = 0x80;
    }
    if (lcdc & 0x80) {
        reg_GX_VRAMCNT_H = 0x80;
    }
    if (lcdc & 0x100) {
        reg_GX_VRAMCNT_I = 0x80;
    }
}

void GX_SetBankForBG(s32 bg) {
    g_Gfx_State[0] = (g_Gfx_State[0] | g_Gfx_State[1]) & ~bg;
    g_Gfx_State[1] = bg;
    switch (bg) {
        case VRAM_BANK_D:
            reg_GX_VRAMCNT_D = 0x81;
            break;
        case VRAM_BANK_C | VRAM_BANK_D:
            reg_GX_VRAMCNT_D = 0x89;
        case VRAM_BANK_C:
            reg_GX_VRAMCNT_C = 0x81;
            break;
        case VRAM_BANK_B | VRAM_BANK_C | VRAM_BANK_D:
            reg_GX_VRAMCNT_D = 0x91;
        case VRAM_BANK_B | VRAM_BANK_C:
            reg_GX_VRAMCNT_C = 0x89;
        case VRAM_BANK_B:
            reg_GX_VRAMCNT_B = 0x81;
            break;
        case VRAM_BANK_A | VRAM_BANK_B | VRAM_BANK_C | VRAM_BANK_D:
            reg_GX_VRAMCNT_D = 0x99;
        case VRAM_BANK_A | VRAM_BANK_B | VRAM_BANK_C:
            reg_GX_VRAMCNT_C = 0x91;
        case VRAM_BANK_A | VRAM_BANK_B:
            reg_GX_VRAMCNT_B = 0x89;
        case VRAM_BANK_A:
            reg_GX_VRAMCNT_A = 0x81;
            break;
        case VRAM_BANK_A | VRAM_BANK_B | VRAM_BANK_D:
            reg_GX_VRAMCNT_A = 0x81;
            reg_GX_VRAMCNT_B = 0x89;
            reg_GX_VRAMCNT_D = 0x91;
            break;
        case VRAM_BANK_A | VRAM_BANK_C | VRAM_BANK_D:
            reg_GX_VRAMCNT_D = 0x91;
        case VRAM_BANK_A | VRAM_BANK_C:
            reg_GX_VRAMCNT_A = 0x81;
            reg_GX_VRAMCNT_C = 0x89;
            break;
        case VRAM_BANK_A | VRAM_BANK_D:
            reg_GX_VRAMCNT_A = 0x81;
            reg_GX_VRAMCNT_D = 0x89;
            break;
        case VRAM_BANK_B | VRAM_BANK_D:
            reg_GX_VRAMCNT_B = 0x81;
            reg_GX_VRAMCNT_D = 0x89;
            break;
        case VRAM_BANK_E | VRAM_BANK_F | VRAM_BANK_G:
            reg_GX_VRAMCNT_G = 0x99;
        case VRAM_BANK_E | VRAM_BANK_F:
            reg_GX_VRAMCNT_F = 0x91;
        case VRAM_BANK_E:
            reg_GX_VRAMCNT_E = 0x81;
            break;
        case VRAM_BANK_E | VRAM_BANK_G:
            reg_GX_VRAMCNT_G = 0x91;
            reg_GX_VRAMCNT_E = 0x81;
            break;
        case VRAM_BANK_F | VRAM_BANK_G:
            reg_GX_VRAMCNT_G = 0x89;
        case VRAM_BANK_F:
            reg_GX_VRAMCNT_F = 0x81;
            break;
        case VRAM_BANK_G:
            reg_GX_VRAMCNT_G = 0x81;
            break;
    }
    GX_VRAMCNT_SetLCDC_(g_Gfx_State[0]);
}

void GX_SetBankForOBJ(s32 obj) {
    g_Gfx_State[0] = (g_Gfx_State[0] | g_Gfx_State[2]) & ~obj;
    g_Gfx_State[2] = obj;
    switch (obj) {
        case VRAM_BANK_G:
            reg_GX_VRAMCNT_G = 0x82;
            break;
        case 0:
            break;
        case VRAM_BANK_A | VRAM_BANK_B:
            reg_GX_VRAMCNT_B = 0x8a;
        case VRAM_BANK_A:
            reg_GX_VRAMCNT_A = 0x82;
            break;
        case VRAM_BANK_B:
            reg_GX_VRAMCNT_B = 0x82;
            break;
        case VRAM_BANK_E | VRAM_BANK_F | VRAM_BANK_G:
            reg_GX_VRAMCNT_G = 0x9a;
        case VRAM_BANK_E | VRAM_BANK_F:
            reg_GX_VRAMCNT_F = 0x92;
        case VRAM_BANK_E:
            reg_GX_VRAMCNT_E = 0x82;
            break;
        case VRAM_BANK_E | VRAM_BANK_G:
            reg_GX_VRAMCNT_G = 0x92;
            reg_GX_VRAMCNT_E = 0x82;
            break;
        case VRAM_BANK_F | VRAM_BANK_G:
            reg_GX_VRAMCNT_G = 0x8a;
        case VRAM_BANK_F:
            reg_GX_VRAMCNT_F = 0x82;
            break;
    }
    GX_VRAMCNT_SetLCDC_(g_Gfx_State[0]);
}

void GX_SetBankForBGExtPltt(s32 bgExtPltt) {
    g_Gfx_State[0] = (g_Gfx_State[0] | g_Gfx_State[7]) & ~bgExtPltt;
    g_Gfx_State[7] = bgExtPltt;
    switch (bgExtPltt) {
        case 0:
            reg_GX_DISPCNT &= ~0x40000000;
            break;
        case VRAM_BANK_E:
            reg_GX_DISPCNT |= 0x40000000;
            reg_GX_VRAMCNT_E = 0x84;
            break;
        case VRAM_BANK_G:
            reg_GX_DISPCNT |= 0x40000000;
            reg_GX_VRAMCNT_G = 0x8c;
            break;
        case VRAM_BANK_F | VRAM_BANK_G:
            reg_GX_VRAMCNT_G = 0x8c;
        case VRAM_BANK_F:
            reg_GX_VRAMCNT_F = 0x84;
            reg_GX_DISPCNT |= 0x40000000;
            break;
    }
    GX_VRAMCNT_SetLCDC_(g_Gfx_State[0]);
}

void GX_SetBankForOBJExtPltt(u32 objExtPltt) {
    g_Gfx_State[0] = (g_Gfx_State[0] | g_Gfx_State[8]) & ~objExtPltt;
    g_Gfx_State[8] = objExtPltt;
    switch (objExtPltt) {
        case VRAM_BANK_F:
            reg_GX_DISPCNT |= 0x80000000;
            reg_GX_VRAMCNT_F = 0x85;
            break;
        case VRAM_BANK_G:
            reg_GX_DISPCNT |= 0x80000000;
            reg_GX_VRAMCNT_G = 0x85;
            break;
        case 0:
            reg_GX_DISPCNT &= ~0x80000000;
            break;
    }
    GX_VRAMCNT_SetLCDC_(g_Gfx_State[0]);
}

void GX_SetBankForTex(u32 tex) {
    g_Gfx_State[0] = (g_Gfx_State[0] | g_Gfx_State[4]) & ~tex;
    g_Gfx_State[4] = tex;
    if (tex == 0) {
        reg_G3X_DISP3DCNT &=
            (u16) ~(REG_G3X_DISP3DCNT_GO_MASK | REG_G3X_DISP3DCNT_RO_MASK | REG_G3X_DISP3DCNT_TME_MASK);
    } else {
        reg_G3X_DISP3DCNT = (reg_G3X_DISP3DCNT & ~(REG_G3X_DISP3DCNT_GO_MASK | REG_G3X_DISP3DCNT_RO_MASK)) | 0x1;
        switch (tex) {
            case VRAM_BANK_A | VRAM_BANK_C:
                reg_GX_VRAMCNT_A = 0x83;
                reg_GX_VRAMCNT_C = 0x8b;
                break;
            case VRAM_BANK_A | VRAM_BANK_D:
                reg_GX_VRAMCNT_A = 0x83;
                reg_GX_VRAMCNT_D = 0x8b;
                break;
            case VRAM_BANK_B | VRAM_BANK_D:
                reg_GX_VRAMCNT_B = 0x83;
                reg_GX_VRAMCNT_D = 0x8b;
                break;
            case VRAM_BANK_A | VRAM_BANK_B | VRAM_BANK_D:
                reg_GX_VRAMCNT_A = 0x83;
                reg_GX_VRAMCNT_B = 0x8b;
                reg_GX_VRAMCNT_D = 0x93;
                break;
            case VRAM_BANK_A | VRAM_BANK_C | VRAM_BANK_D:
                reg_GX_VRAMCNT_A = 0x83;
                reg_GX_VRAMCNT_C = 0x8b;
                reg_GX_VRAMCNT_D = 0x93;
                break;
            case VRAM_BANK_D:
                reg_GX_VRAMCNT_D = 0x83;
                break;
            case VRAM_BANK_C | VRAM_BANK_D:
                reg_GX_VRAMCNT_D = 0x8b;
            case VRAM_BANK_C:
                reg_GX_VRAMCNT_C = 0x83;
                break;
            case VRAM_BANK_B | VRAM_BANK_C | VRAM_BANK_D:
                reg_GX_VRAMCNT_D = 0x93;
            case VRAM_BANK_B | VRAM_BANK_C:
                reg_GX_VRAMCNT_C = 0x8b;
            case VRAM_BANK_B:
                reg_GX_VRAMCNT_B = 0x83;
                break;
            case VRAM_BANK_A | VRAM_BANK_B | VRAM_BANK_C | VRAM_BANK_D:
                reg_GX_VRAMCNT_D = 0x9b;
            case VRAM_BANK_A | VRAM_BANK_B | VRAM_BANK_C:
                reg_GX_VRAMCNT_C = 0x93;
            case VRAM_BANK_A | VRAM_BANK_B:
                reg_GX_VRAMCNT_B = 0x8b;
            case VRAM_BANK_A:
                reg_GX_VRAMCNT_A = 0x83;
                break;
        }
    }
    GX_VRAMCNT_SetLCDC_(g_Gfx_State[0]);
}

void GX_SetBankForTexPltt(s32 texPltt) {
    g_Gfx_State[0] = (g_Gfx_State[0] | g_Gfx_State[5]) & ~texPltt;
    g_Gfx_State[5] = texPltt;
    switch (texPltt) {
        case 0:
            break;
        case VRAM_BANK_G:
            reg_GX_VRAMCNT_G = 0x83;
            break;
        case VRAM_BANK_F | VRAM_BANK_G:
            reg_GX_VRAMCNT_G = 0x8b;
        case VRAM_BANK_F:
            reg_GX_VRAMCNT_F = 0x83;
            break;
        case VRAM_BANK_E | VRAM_BANK_F | VRAM_BANK_G:
            reg_GX_VRAMCNT_G = 0x9b;
        case VRAM_BANK_E | VRAM_BANK_F:
            reg_GX_VRAMCNT_F = 0x93;
        case VRAM_BANK_E:
            reg_GX_VRAMCNT_E = 0x83;
            break;
    }
    GX_VRAMCNT_SetLCDC_(g_Gfx_State[0]);
}

void GX_SetBankForClearImage(u32 clrImg) {
    g_Gfx_State[0] = (g_Gfx_State[0] | g_Gfx_State[6]) & ~clrImg;
    g_Gfx_State[6] = clrImg;
    switch (clrImg) {
        case VRAM_BANK_A | VRAM_BANK_B:
            reg_GX_VRAMCNT_A = 0x93;
        case VRAM_BANK_B:
            reg_GX_VRAMCNT_B = 0x9b;
            reg_G3X_DISP3DCNT |= REG_G3X_DISP3DCNT_PRI_MASK;
            break;
        case VRAM_BANK_C | VRAM_BANK_D:
            reg_GX_VRAMCNT_C = 0x93;
        case VRAM_BANK_D:
            reg_GX_VRAMCNT_D = 0x9b;
            reg_G3X_DISP3DCNT |= REG_G3X_DISP3DCNT_PRI_MASK;
            break;
        case 0:
            reg_G3X_DISP3DCNT &= ~REG_G3X_DISP3DCNT_PRI_MASK;
            break;
        case VRAM_BANK_A:
            reg_GX_VRAMCNT_A = 0x9b;
            reg_G3X_DISP3DCNT |= REG_G3X_DISP3DCNT_PRI_MASK;
            break;
        case VRAM_BANK_C:
            reg_GX_VRAMCNT_C = 0x9b;
            reg_G3X_DISP3DCNT |= REG_G3X_DISP3DCNT_PRI_MASK;
            break;
    }
    GX_VRAMCNT_SetLCDC_(g_Gfx_State[0]);
}

void GX_SetBankForARM7(s32 arm7) {
    g_Gfx_State[0] = (g_Gfx_State[0] | g_Gfx_State[3]) & ~arm7;
    g_Gfx_State[3] = arm7;
    switch (arm7) {
        case 0:
            break;
        case VRAM_BANK_C | VRAM_BANK_D:
            reg_GX_VRAMCNT_D = 0x8a;
            reg_GX_VRAMCNT_C = 0x82;
            break;
        case VRAM_BANK_C:
            reg_GX_VRAMCNT_C = 0x82;
            break;
        case VRAM_BANK_D:
            reg_GX_VRAMCNT_D = 0x82;
            break;
    }
    GX_VRAMCNT_SetLCDC_(g_Gfx_State[0]);
}

void GX_SetBankForLCDC(u32 lcdc) {
    g_Gfx_State[0] = g_Gfx_State[0] | lcdc;
    GX_VRAMCNT_SetLCDC_(lcdc);
}

void GX_SetBankForSubBG(s32 subBg) {
    g_Gfx_State[0] = (g_Gfx_State[0] | g_Gfx_State[9]) & ~subBg;
    g_Gfx_State[9] = subBg;
    switch (subBg) {
        case 0:
            break;
        case VRAM_BANK_C:
            reg_GX_VRAMCNT_C = 0x84;
            break;
        case VRAM_BANK_H | VRAM_BANK_I:
            reg_GX_VRAMCNT_I = 0x81;
        case VRAM_BANK_H:
            reg_GX_VRAMCNT_H = 0x81;
            break;
    }
    GX_VRAMCNT_SetLCDC_(g_Gfx_State[0]);
}

void GX_SetBankForSubOBJ(u32 subObj) {
    g_Gfx_State[0] = (g_Gfx_State[0] | g_Gfx_State[10]) & ~subObj;
    g_Gfx_State[10] = subObj;
    if (subObj != 0) {
        switch (subObj) {
            case VRAM_BANK_I:
                reg_GX_VRAMCNT_I = 0x82;
                break;
            case VRAM_BANK_D:
                reg_GX_VRAMCNT_D = 0x84;
                break;
        }
    }
    GX_VRAMCNT_SetLCDC_(g_Gfx_State[0]);
}

void GX_SetBankForSubBGExtPltt(u32 subBgExtPltt) {
    g_Gfx_State[0] = (g_Gfx_State[0] | g_Gfx_State[11]) & ~subBgExtPltt;
    g_Gfx_State[11] = subBgExtPltt;
    if (subBgExtPltt != 0) {
        if (subBgExtPltt == 0x80) {
            reg_GXS_DB_DISPCNT |= 0x40000000;
            reg_GX_VRAMCNT_H = 0x82;
        }
    } else {
        reg_GXS_DB_DISPCNT &= ~0x40000000;
    }
    GX_VRAMCNT_SetLCDC_(g_Gfx_State[0]);
}

void GX_SetBankForSubOBJExtPltt(u32 subObjExtPltt) {
    g_Gfx_State[0] = (g_Gfx_State[0] | g_Gfx_State[12]) & ~subObjExtPltt;
    g_Gfx_State[12] = subObjExtPltt;
    if (subObjExtPltt != 0) {
        if (subObjExtPltt == 0x100) {
            reg_GXS_DB_DISPCNT |= 0x80000000;
            reg_GX_VRAMCNT_I = 0x83;
        }
    } else {
        reg_GXS_DB_DISPCNT &= ~0x80000000;
    }
    GX_VRAMCNT_SetLCDC_(g_Gfx_State[0]);
}

u16 resetBankForX_(u16 *group) {
    u16 mask;

    mask = *group;
    *group = 0;
    g_Gfx_State[0] = g_Gfx_State[0] | mask;
    GX_VRAMCNT_SetLCDC_(mask);
    return mask;
}

u16 GX_ResetBankForBGExtPltt(void) {
    reg_GX_DISPCNT &= ~0x40000000;
    return resetBankForX_(&g_Gfx_State[7]);
}

u16 GX_ResetBankForOBJExtPltt(void) {
    reg_GX_DISPCNT &= ~0x80000000;
    return resetBankForX_(&g_Gfx_State[8]);
}

u16 GX_ResetBankForTex(void) {
    return resetBankForX_(&g_Gfx_State[4]);
}

u16 GX_ResetBankForTexPltt(void) {
    return resetBankForX_(&g_Gfx_State[5]);
}

u16 GX_ResetBankForClearImage(void) {
    return resetBankForX_(&g_Gfx_State[6]);
}

u16 GX_ResetBankForSubBG(void) {
    return resetBankForX_(&g_Gfx_State[9]);
}

u16 GX_ResetBankForSubOBJ(void) {
    return resetBankForX_(&g_Gfx_State[10]);
}

u16 GX_ResetBankForSubBGExtPltt(void) {
    reg_GXS_DB_DISPCNT &= ~0x40000000;
    return resetBankForX_(&g_Gfx_State[11]);
}

u16 GX_ResetBankForSubOBJExtPltt(void) {
    reg_GXS_DB_DISPCNT &= ~0x80000000;
    return resetBankForX_(&g_Gfx_State[12]);
}

u32 GX_disableBankForX_(u16 *group) {
    u32 mask;

    mask = *group;
    *group = 0;
    if (mask & 0x1) {
        reg_GX_VRAMCNT_A = 0;
    }
    if (mask & 0x2) {
        reg_GX_VRAMCNT_B = 0;
    }
    if (mask & 0x4) {
        reg_GX_VRAMCNT_C = 0;
    }
    if (mask & 0x8) {
        reg_GX_VRAMCNT_D = 0;
    }
    if (mask & 0x10) {
        reg_GX_VRAMCNT_E = 0;
    }
    if (mask & 0x20) {
        reg_GX_VRAMCNT_F = 0;
    }
    if (mask & 0x40) {
        reg_GX_VRAMCNT_G = 0;
    }
    if (mask & 0x80) {
        reg_GX_VRAMCNT_H = 0;
    }
    if (mask & 0x100) {
        reg_GX_VRAMCNT_I = 0;
    }
    Os_UnlockVram((u16) mask, g_Gfx_VramLockId);
    return mask;
}

u32 GX_DisableBankForBG(void) {
    return GX_disableBankForX_(&g_Gfx_State[1]);
}

u32 GX_DisableBankForOBJ(void) {
    return GX_disableBankForX_(&g_Gfx_State[2]);
}

u32 GX_DisableBankForBGExtPltt(void) {
    reg_GX_DISPCNT &= ~0x40000000;
    return GX_disableBankForX_(&g_Gfx_State[7]);
}

u32 GX_DisableBankForOBJExtPltt(void) {
    reg_GX_DISPCNT &= ~0x80000000;
    return GX_disableBankForX_(&g_Gfx_State[8]);
}

u32 GX_DisableBankForTex(void) {
    return GX_disableBankForX_(&g_Gfx_State[4]);
}

u32 GX_DisableBankForTexPltt(void) {
    return GX_disableBankForX_(&g_Gfx_State[5]);
}

u32 GX_DisableBankForClearImage(void) {
    return GX_disableBankForX_(&g_Gfx_State[6]);
}

u32 GX_DisableBankForARM7(void) {
    return GX_disableBankForX_(&g_Gfx_State[3]);
}

u32 GX_DisableBankForLCDC(void) {
    return GX_disableBankForX_(g_Gfx_State);
}

u32 GX_DisableBankForSubBG(void) {
    return GX_disableBankForX_(&g_Gfx_State[9]);
}

u32 GX_DisableBankForSubOBJ(void) {
    return GX_disableBankForX_(&g_Gfx_State[10]);
}

u32 GX_DisableBankForBGExtPltt(void) {
    reg_GXS_DB_DISPCNT &= ~0x40000000;
    return GX_disableBankForX_(&g_Gfx_State[11]);
}

u32 GX_DisableBankForOBJExtPltt(void) {
    reg_GXS_DB_DISPCNT &= ~0x80000000;
    return GX_disableBankForX_(&g_Gfx_State[12]);
}

u32 GX_GetBankForTex(void) {
    return g_Gfx_State[4];
}

u32 GX_GetSizeOfX_(u32 bits) {
    u32 size = 0;

    if (bits & 0x1) {
        size += 0x20000;
    }
    if (bits & 0x2) {
        size += 0x20000;
    }
    if (bits & 0x4) {
        size += 0x20000;
    }
    if (bits & 0x8) {
        size += 0x20000;
    }
    if (bits & 0x10) {
        size += 0x10000;
    }
    if (bits & 0x20) {
        size += 0x4000;
    }
    if (bits & 0x40) {
        size += 0x4000;
    }
    if (bits & 0x80) {
        size += 0x8000;
    }
    if (bits & 0x100) {
        size += 0x4000;
    }
    return size;
}

u32 GX_GetSizeOfOBJ(void) {
    return GX_GetSizeOfX_(g_Gfx_State[2]);
}

u32 GX_GetSizeOfSubOBJ(void) {
    return GX_GetSizeOfX_(g_Gfx_State[10]);
}

void Gfx_InitializeState(void) {
    g_Gfx_State[0] = 0;
    g_Gfx_State[1] = 0;
    g_Gfx_State[2] = 0;
    g_Gfx_State[3] = 0;
    g_Gfx_State[4] = 0;
    g_Gfx_State[5] = 0;
    g_Gfx_State[6] = 0;
    g_Gfx_State[7] = 0;
    g_Gfx_State[8] = 0;
    g_Gfx_State[9] = 0;
    g_Gfx_State[10] = 0;
    g_Gfx_State[11] = 0;
    g_Gfx_State[12] = 0;
    *(vu32 *) 0x4000240 = 0;
    reg_GX_VRAMCNT_E = 0;
    reg_GX_VRAMCNT_F = 0;
    reg_GX_VRAMCNT_G = 0;
    *(vu16 *) 0x4000248 = 0;
}

void Gfx_Initialize(void) {
    s32 newLockId;

    reg_GX_POWCNT |= 0x8000;
    reg_GX_POWCNT = (reg_GX_POWCNT & ~0x20e) | 0x20e;
    reg_GX_POWCNT |= 0x1;
    Gfx_InitializeState();
    while (g_Gfx_VramLockId == 0) {
        newLockId = Os_AllocateLockId();
        if (newLockId == -3) {
            Os_Terminate();
        }
        g_Gfx_VramLockId = newLockId;
    }
    reg_GX_DISPSTAT = 0;
    reg_GX_DISPCNT = 0;
    if (g_GfxDmaChannel != -1) {
        Mem_DmaFill32(g_GfxDmaChannel, (void *) 0x4000008, 0, 0x60);
        reg_GX_MASTER_BRIGHT = 0;
        Mem_DmaFill32(g_GfxDmaChannel, (void *) 0x4001000, 0, 0x70);
    } else {
        volatile u32 zeroFirst = 0;
        volatile u32 zeroSecond;

        MIi_CpuClear32(zeroFirst, (void *) 0x4000008, 0x60);
        reg_GX_MASTER_BRIGHT = 0;
        zeroSecond = 0;
        MIi_CpuClear32(zeroSecond, (void *) 0x4001000, 0x70);
    }
    reg_G2_BG2PA = 0x100;
    reg_G2_BG2PD = 0x100;
    reg_G2_BG3PA = 0x100;
    reg_G2_BG3PD = 0x100;
    reg_G2S_DB_BG2PA = 0x100;
    reg_G2S_DB_BG2PD = 0x100;
    reg_G2S_DB_BG3PA = 0x100;
    reg_G2S_DB_BG3PD = 0x100;
}

u32 GX_VBlankIntr(s32 enable) {
    u32 previous;

    previous = reg_GX_DISPSTAT & 0x8;
    if (enable != 0) {
        reg_GX_DISPSTAT |= 0x8;
    } else {
        reg_GX_DISPSTAT &= ~0x8;
    }
    return previous;
}

void SomeDispcntInit(void) {
    u32 cnt = reg_GX_DISPCNT;

    gDispOn[0] = 0;
    g_CurrentDisplayMode = (cnt & 0x30000) >> 16;
    reg_GX_DISPCNT = cnt & ~0x30000;
}

void GX_DispOn(void) {
    u32 mode;

    gDispOn[0] = 1;
    mode = g_CurrentDisplayMode;
    if (mode != 0) {
        reg_GX_DISPCNT = (reg_GX_DISPCNT & ~0x30000) | (mode << 16);
    } else {
        reg_GX_DISPCNT |= 0x10000;
    }
}

void ConfigureDispcntDisplay(u16 dispMode, u32 bgMode, s32 bg0As) {
    u32 isDispOn;
    u32 dispCtrl;

    dispCtrl = reg_GX_DISPCNT;
    isDispOn = gDispOn[0];
    g_CurrentDisplayMode = dispMode;
    if (isDispOn == 0) {
        dispMode = 0;
    }
    reg_GX_DISPCNT = ((dispCtrl & 0xfff0fff0) | (dispMode << 16) | bgMode) | (bg0As << 3);
    if (g_CurrentDisplayMode == 0) {
        gDispOn[0] = 0;
    }
}
