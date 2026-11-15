#include "code_02148950.h"

#include "Main/Net/data_0216f000.h"
#include "os_thread.h"
#include "mb_data.h"
#include "data_02180000.h"
#include "os_spinLock.h"
#include "code_0200fc8c.h"
#include "code_0214c778.h"
#include "00/Lib/DWC/code_02188720.h"
#include "code_0200fe74.h"
#include "registers.h"

u16 gDispOn[2] = {1, 0};
u32 GXi_DmaId = 3;
s32 sDayOfYear[12] = {0, 0x1f, 0x3b, 0x5a, 0x78, 0x97, 0xb5, 0xd4, 0xf3, 0x111, 0x130, 0x14e};
u16 gVramLockId = 0;
u16 gSavedDispMode = 0;
u16 gVramBankGroups[13] = {0};

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
    gVramBankGroups[0] = (gVramBankGroups[0] | gVramBankGroups[1]) & ~bg;
    gVramBankGroups[1] = bg;
    switch (bg) {
        case GX_VRAM_BANK_D:
            reg_GX_VRAMCNT_D = 0x81;
            break;
        case GX_VRAM_BANK_C | GX_VRAM_BANK_D:
            reg_GX_VRAMCNT_D = 0x89;
        case GX_VRAM_BANK_C:
            reg_GX_VRAMCNT_C = 0x81;
            break;
        case GX_VRAM_BANK_B | GX_VRAM_BANK_C | GX_VRAM_BANK_D:
            reg_GX_VRAMCNT_D = 0x91;
        case GX_VRAM_BANK_B | GX_VRAM_BANK_C:
            reg_GX_VRAMCNT_C = 0x89;
        case GX_VRAM_BANK_B:
            reg_GX_VRAMCNT_B = 0x81;
            break;
        case GX_VRAM_BANK_A | GX_VRAM_BANK_B | GX_VRAM_BANK_C | GX_VRAM_BANK_D:
            reg_GX_VRAMCNT_D = 0x99;
        case GX_VRAM_BANK_A | GX_VRAM_BANK_B | GX_VRAM_BANK_C:
            reg_GX_VRAMCNT_C = 0x91;
        case GX_VRAM_BANK_A | GX_VRAM_BANK_B:
            reg_GX_VRAMCNT_B = 0x89;
        case GX_VRAM_BANK_A:
            reg_GX_VRAMCNT_A = 0x81;
            break;
        case GX_VRAM_BANK_A | GX_VRAM_BANK_B | GX_VRAM_BANK_D:
            reg_GX_VRAMCNT_A = 0x81;
            reg_GX_VRAMCNT_B = 0x89;
            reg_GX_VRAMCNT_D = 0x91;
            break;
        case GX_VRAM_BANK_A | GX_VRAM_BANK_C | GX_VRAM_BANK_D:
            reg_GX_VRAMCNT_D = 0x91;
        case GX_VRAM_BANK_A | GX_VRAM_BANK_C:
            reg_GX_VRAMCNT_A = 0x81;
            reg_GX_VRAMCNT_C = 0x89;
            break;
        case GX_VRAM_BANK_A | GX_VRAM_BANK_D:
            reg_GX_VRAMCNT_A = 0x81;
            reg_GX_VRAMCNT_D = 0x89;
            break;
        case GX_VRAM_BANK_B | GX_VRAM_BANK_D:
            reg_GX_VRAMCNT_B = 0x81;
            reg_GX_VRAMCNT_D = 0x89;
            break;
        case GX_VRAM_BANK_E | GX_VRAM_BANK_F | GX_VRAM_BANK_G:
            reg_GX_VRAMCNT_G = 0x99;
        case GX_VRAM_BANK_E | GX_VRAM_BANK_F:
            reg_GX_VRAMCNT_F = 0x91;
        case GX_VRAM_BANK_E:
            reg_GX_VRAMCNT_E = 0x81;
            break;
        case GX_VRAM_BANK_E | GX_VRAM_BANK_G:
            reg_GX_VRAMCNT_G = 0x91;
            reg_GX_VRAMCNT_E = 0x81;
            break;
        case GX_VRAM_BANK_F | GX_VRAM_BANK_G:
            reg_GX_VRAMCNT_G = 0x89;
        case GX_VRAM_BANK_F:
            reg_GX_VRAMCNT_F = 0x81;
            break;
        case GX_VRAM_BANK_G:
            reg_GX_VRAMCNT_G = 0x81;
            break;
    }
    GX_VRAMCNT_SetLCDC_(gVramBankGroups[0]);
}

void GX_SetBankForOBJ(s32 obj) {
    gVramBankGroups[0] = (gVramBankGroups[0] | gVramBankGroups[2]) & ~obj;
    gVramBankGroups[2] = obj;
    switch (obj) {
        case GX_VRAM_BANK_G:
            reg_GX_VRAMCNT_G = 0x82;
            break;
        case 0:
            break;
        case GX_VRAM_BANK_A | GX_VRAM_BANK_B:
            reg_GX_VRAMCNT_B = 0x8a;
        case GX_VRAM_BANK_A:
            reg_GX_VRAMCNT_A = 0x82;
            break;
        case GX_VRAM_BANK_B:
            reg_GX_VRAMCNT_B = 0x82;
            break;
        case GX_VRAM_BANK_E | GX_VRAM_BANK_F | GX_VRAM_BANK_G:
            reg_GX_VRAMCNT_G = 0x9a;
        case GX_VRAM_BANK_E | GX_VRAM_BANK_F:
            reg_GX_VRAMCNT_F = 0x92;
        case GX_VRAM_BANK_E:
            reg_GX_VRAMCNT_E = 0x82;
            break;
        case GX_VRAM_BANK_E | GX_VRAM_BANK_G:
            reg_GX_VRAMCNT_G = 0x92;
            reg_GX_VRAMCNT_E = 0x82;
            break;
        case GX_VRAM_BANK_F | GX_VRAM_BANK_G:
            reg_GX_VRAMCNT_G = 0x8a;
        case GX_VRAM_BANK_F:
            reg_GX_VRAMCNT_F = 0x82;
            break;
    }
    GX_VRAMCNT_SetLCDC_(gVramBankGroups[0]);
}

void GX_SetBankForBGExtPltt(s32 bgExtPltt) {
    gVramBankGroups[0] = (gVramBankGroups[0] | gVramBankGroups[7]) & ~bgExtPltt;
    gVramBankGroups[7] = bgExtPltt;
    switch (bgExtPltt) {
        case 0:
            reg_GX_DISPCNT &= ~0x40000000;
            break;
        case GX_VRAM_BANK_E:
            reg_GX_DISPCNT |= 0x40000000;
            reg_GX_VRAMCNT_E = 0x84;
            break;
        case GX_VRAM_BANK_G:
            reg_GX_DISPCNT |= 0x40000000;
            reg_GX_VRAMCNT_G = 0x8c;
            break;
        case GX_VRAM_BANK_F | GX_VRAM_BANK_G:
            reg_GX_VRAMCNT_G = 0x8c;
        case GX_VRAM_BANK_F:
            reg_GX_VRAMCNT_F = 0x84;
            reg_GX_DISPCNT |= 0x40000000;
            break;
    }
    GX_VRAMCNT_SetLCDC_(gVramBankGroups[0]);
}

void GX_SetBankForOBJExtPltt(u32 objExtPltt) {
    gVramBankGroups[0] = (gVramBankGroups[0] | gVramBankGroups[8]) & ~objExtPltt;
    gVramBankGroups[8] = objExtPltt;
    switch (objExtPltt) {
        case GX_VRAM_BANK_F:
            reg_GX_DISPCNT |= 0x80000000;
            reg_GX_VRAMCNT_F = 0x85;
            break;
        case GX_VRAM_BANK_G:
            reg_GX_DISPCNT |= 0x80000000;
            reg_GX_VRAMCNT_G = 0x85;
            break;
        case 0:
            reg_GX_DISPCNT &= ~0x80000000;
            break;
    }
    GX_VRAMCNT_SetLCDC_(gVramBankGroups[0]);
}

void GX_SetBankForTex(u32 tex) {
    gVramBankGroups[0] = (gVramBankGroups[0] | gVramBankGroups[4]) & ~tex;
    gVramBankGroups[4] = tex;
    if (tex == 0) {
        reg_G3X_DISP3DCNT &=
            (u16) ~(REG_G3X_DISP3DCNT_GO_MASK | REG_G3X_DISP3DCNT_RO_MASK | REG_G3X_DISP3DCNT_TME_MASK);
    } else {
        reg_G3X_DISP3DCNT = (reg_G3X_DISP3DCNT & ~(REG_G3X_DISP3DCNT_GO_MASK | REG_G3X_DISP3DCNT_RO_MASK)) | 0x1;
        switch (tex) {
            case GX_VRAM_BANK_A | GX_VRAM_BANK_C:
                reg_GX_VRAMCNT_A = 0x83;
                reg_GX_VRAMCNT_C = 0x8b;
                break;
            case GX_VRAM_BANK_A | GX_VRAM_BANK_D:
                reg_GX_VRAMCNT_A = 0x83;
                reg_GX_VRAMCNT_D = 0x8b;
                break;
            case GX_VRAM_BANK_B | GX_VRAM_BANK_D:
                reg_GX_VRAMCNT_B = 0x83;
                reg_GX_VRAMCNT_D = 0x8b;
                break;
            case GX_VRAM_BANK_A | GX_VRAM_BANK_B | GX_VRAM_BANK_D:
                reg_GX_VRAMCNT_A = 0x83;
                reg_GX_VRAMCNT_B = 0x8b;
                reg_GX_VRAMCNT_D = 0x93;
                break;
            case GX_VRAM_BANK_A | GX_VRAM_BANK_C | GX_VRAM_BANK_D:
                reg_GX_VRAMCNT_A = 0x83;
                reg_GX_VRAMCNT_C = 0x8b;
                reg_GX_VRAMCNT_D = 0x93;
                break;
            case GX_VRAM_BANK_D:
                reg_GX_VRAMCNT_D = 0x83;
                break;
            case GX_VRAM_BANK_C | GX_VRAM_BANK_D:
                reg_GX_VRAMCNT_D = 0x8b;
            case GX_VRAM_BANK_C:
                reg_GX_VRAMCNT_C = 0x83;
                break;
            case GX_VRAM_BANK_B | GX_VRAM_BANK_C | GX_VRAM_BANK_D:
                reg_GX_VRAMCNT_D = 0x93;
            case GX_VRAM_BANK_B | GX_VRAM_BANK_C:
                reg_GX_VRAMCNT_C = 0x8b;
            case GX_VRAM_BANK_B:
                reg_GX_VRAMCNT_B = 0x83;
                break;
            case GX_VRAM_BANK_A | GX_VRAM_BANK_B | GX_VRAM_BANK_C | GX_VRAM_BANK_D:
                reg_GX_VRAMCNT_D = 0x9b;
            case GX_VRAM_BANK_A | GX_VRAM_BANK_B | GX_VRAM_BANK_C:
                reg_GX_VRAMCNT_C = 0x93;
            case GX_VRAM_BANK_A | GX_VRAM_BANK_B:
                reg_GX_VRAMCNT_B = 0x8b;
            case GX_VRAM_BANK_A:
                reg_GX_VRAMCNT_A = 0x83;
                break;
        }
    }
    GX_VRAMCNT_SetLCDC_(gVramBankGroups[0]);
}

void GX_SetBankForTexPltt(s32 texPltt) {
    gVramBankGroups[0] = (gVramBankGroups[0] | gVramBankGroups[5]) & ~texPltt;
    gVramBankGroups[5] = texPltt;
    switch (texPltt) {
        case 0:
            break;
        case GX_VRAM_BANK_G:
            reg_GX_VRAMCNT_G = 0x83;
            break;
        case GX_VRAM_BANK_F | GX_VRAM_BANK_G:
            reg_GX_VRAMCNT_G = 0x8b;
        case GX_VRAM_BANK_F:
            reg_GX_VRAMCNT_F = 0x83;
            break;
        case GX_VRAM_BANK_E | GX_VRAM_BANK_F | GX_VRAM_BANK_G:
            reg_GX_VRAMCNT_G = 0x9b;
        case GX_VRAM_BANK_E | GX_VRAM_BANK_F:
            reg_GX_VRAMCNT_F = 0x93;
        case GX_VRAM_BANK_E:
            reg_GX_VRAMCNT_E = 0x83;
            break;
    }
    GX_VRAMCNT_SetLCDC_(gVramBankGroups[0]);
}

void GX_SetBankForClearImage(u32 clrImg) {
    gVramBankGroups[0] = (gVramBankGroups[0] | gVramBankGroups[6]) & ~clrImg;
    gVramBankGroups[6] = clrImg;
    switch (clrImg) {
        case GX_VRAM_BANK_A | GX_VRAM_BANK_B:
            reg_GX_VRAMCNT_A = 0x93;
        case GX_VRAM_BANK_B:
            reg_GX_VRAMCNT_B = 0x9b;
            reg_G3X_DISP3DCNT |= REG_G3X_DISP3DCNT_PRI_MASK;
            break;
        case GX_VRAM_BANK_C | GX_VRAM_BANK_D:
            reg_GX_VRAMCNT_C = 0x93;
        case GX_VRAM_BANK_D:
            reg_GX_VRAMCNT_D = 0x9b;
            reg_G3X_DISP3DCNT |= REG_G3X_DISP3DCNT_PRI_MASK;
            break;
        case 0:
            reg_G3X_DISP3DCNT &= ~REG_G3X_DISP3DCNT_PRI_MASK;
            break;
        case GX_VRAM_BANK_A:
            reg_GX_VRAMCNT_A = 0x9b;
            reg_G3X_DISP3DCNT |= REG_G3X_DISP3DCNT_PRI_MASK;
            break;
        case GX_VRAM_BANK_C:
            reg_GX_VRAMCNT_C = 0x9b;
            reg_G3X_DISP3DCNT |= REG_G3X_DISP3DCNT_PRI_MASK;
            break;
    }
    GX_VRAMCNT_SetLCDC_(gVramBankGroups[0]);
}

void GX_SetBankForARM7(s32 arm7) {
    gVramBankGroups[0] = (gVramBankGroups[0] | gVramBankGroups[3]) & ~arm7;
    gVramBankGroups[3] = arm7;
    switch (arm7) {
        case 0:
            break;
        case GX_VRAM_BANK_C | GX_VRAM_BANK_D:
            reg_GX_VRAMCNT_D = 0x8a;
            reg_GX_VRAMCNT_C = 0x82;
            break;
        case GX_VRAM_BANK_C:
            reg_GX_VRAMCNT_C = 0x82;
            break;
        case GX_VRAM_BANK_D:
            reg_GX_VRAMCNT_D = 0x82;
            break;
    }
    GX_VRAMCNT_SetLCDC_(gVramBankGroups[0]);
}

void GX_SetBankForLCDC(u32 lcdc) {
    gVramBankGroups[0] = gVramBankGroups[0] | lcdc;
    GX_VRAMCNT_SetLCDC_(lcdc);
}

void GX_SetBankForSubBG(s32 subBg) {
    gVramBankGroups[0] = (gVramBankGroups[0] | gVramBankGroups[9]) & ~subBg;
    gVramBankGroups[9] = subBg;
    switch (subBg) {
        case 0:
            break;
        case GX_VRAM_BANK_C:
            reg_GX_VRAMCNT_C = 0x84;
            break;
        case GX_VRAM_BANK_H | GX_VRAM_BANK_I:
            reg_GX_VRAMCNT_I = 0x81;
        case GX_VRAM_BANK_H:
            reg_GX_VRAMCNT_H = 0x81;
            break;
    }
    GX_VRAMCNT_SetLCDC_(gVramBankGroups[0]);
}

void GX_SetBankForSubOBJ(u32 subObj) {
    gVramBankGroups[0] = (gVramBankGroups[0] | gVramBankGroups[10]) & ~subObj;
    gVramBankGroups[10] = subObj;
    if (subObj != 0) {
        switch (subObj) {
            case GX_VRAM_BANK_I:
                reg_GX_VRAMCNT_I = 0x82;
                break;
            case GX_VRAM_BANK_D:
                reg_GX_VRAMCNT_D = 0x84;
                break;
        }
    }
    GX_VRAMCNT_SetLCDC_(gVramBankGroups[0]);
}

void GX_SetBankForSubBGExtPltt(u32 subBgExtPltt) {
    gVramBankGroups[0] = (gVramBankGroups[0] | gVramBankGroups[11]) & ~subBgExtPltt;
    gVramBankGroups[11] = subBgExtPltt;
    if (subBgExtPltt != 0) {
        if (subBgExtPltt == 0x80) {
            reg_GXS_DB_DISPCNT |= 0x40000000;
            reg_GX_VRAMCNT_H = 0x82;
        }
    } else {
        reg_GXS_DB_DISPCNT &= ~0x40000000;
    }
    GX_VRAMCNT_SetLCDC_(gVramBankGroups[0]);
}

void GX_SetBankForSubOBJExtPltt(u32 subObjExtPltt) {
    gVramBankGroups[0] = (gVramBankGroups[0] | gVramBankGroups[12]) & ~subObjExtPltt;
    gVramBankGroups[12] = subObjExtPltt;
    if (subObjExtPltt != 0) {
        if (subObjExtPltt == 0x100) {
            reg_GXS_DB_DISPCNT |= 0x80000000;
            reg_GX_VRAMCNT_I = 0x83;
        }
    } else {
        reg_GXS_DB_DISPCNT &= ~0x80000000;
    }
    GX_VRAMCNT_SetLCDC_(gVramBankGroups[0]);
}

u16 resetBankForX_(u16 *group) {
    u16 mask;

    mask = *group;
    *group = 0;
    gVramBankGroups[0] = gVramBankGroups[0] | mask;
    GX_VRAMCNT_SetLCDC_(mask);
    return mask;
}

u16 GX_ResetBankForBGExtPltt(void) {
    reg_GX_DISPCNT &= ~0x40000000;
    return resetBankForX_(&gVramBankGroups[7]);
}

u16 GX_ResetBankForOBJExtPltt(void) {
    reg_GX_DISPCNT &= ~0x80000000;
    return resetBankForX_(&gVramBankGroups[8]);
}

u16 GX_ResetBankForTex(void) {
    return resetBankForX_(&gVramBankGroups[4]);
}

u16 GX_ResetBankForTexPltt(void) {
    return resetBankForX_(&gVramBankGroups[5]);
}

u16 GX_ResetBankForClearImage(void) {
    return resetBankForX_(&gVramBankGroups[6]);
}

u16 GX_ResetBankForSubBG(void) {
    return resetBankForX_(&gVramBankGroups[9]);
}

u16 GX_ResetBankForSubOBJ(void) {
    return resetBankForX_(&gVramBankGroups[10]);
}

u16 GX_ResetBankForSubBGExtPltt(void) {
    reg_GXS_DB_DISPCNT &= ~0x40000000;
    return resetBankForX_(&gVramBankGroups[11]);
}

u16 GX_ResetBankForSubOBJExtPltt(void) {
    reg_GXS_DB_DISPCNT &= ~0x80000000;
    return resetBankForX_(&gVramBankGroups[12]);
}

u32 disableBankForX_(u16 *group) {
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
    OSi_UnlockVram((u16) mask, gVramLockId);
    return mask;
}

u32 GX_DisableBankForBG(void) {
    return disableBankForX_(&gVramBankGroups[1]);
}

u32 GX_DisableBankForOBJ(void) {
    return disableBankForX_(&gVramBankGroups[2]);
}

u32 GX_DisableBankForBGExtPltt(void) {
    reg_GX_DISPCNT &= ~0x40000000;
    return disableBankForX_(&gVramBankGroups[7]);
}

u32 GX_DisableBankForOBJExtPltt(void) {
    reg_GX_DISPCNT &= ~0x80000000;
    return disableBankForX_(&gVramBankGroups[8]);
}

u32 GX_DisableBankForTex(void) {
    return disableBankForX_(&gVramBankGroups[4]);
}

u32 GX_DisableBankForTexPltt(void) {
    return disableBankForX_(&gVramBankGroups[5]);
}

u32 GX_DisableBankForClearImage(void) {
    return disableBankForX_(&gVramBankGroups[6]);
}

u32 GX_DisableBankForARM7(void) {
    return disableBankForX_(&gVramBankGroups[3]);
}

u32 GX_DisableBankForLCDC(void) {
    return disableBankForX_(gVramBankGroups);
}

u32 GX_DisableBankForSubBG(void) {
    return disableBankForX_(&gVramBankGroups[9]);
}

u32 GX_DisableBankForSubOBJ(void) {
    return disableBankForX_(&gVramBankGroups[10]);
}

u32 GX_DisableBankForSubBGExtPltt(void) {
    reg_GXS_DB_DISPCNT &= ~0x40000000;
    return disableBankForX_(&gVramBankGroups[11]);
}

u32 GX_DisableBankForSubOBJExtPltt(void) {
    reg_GXS_DB_DISPCNT &= ~0x80000000;
    return disableBankForX_(&gVramBankGroups[12]);
}

u32 GX_GetBankForTex(void) {
    return gVramBankGroups[4];
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
    return GX_GetSizeOfX_(gVramBankGroups[2]);
}

u32 GX_GetSizeOfSubOBJ(void) {
    return GX_GetSizeOfX_(gVramBankGroups[10]);
}

void GX_InitGXState(void) {
    gVramBankGroups[0] = 0;
    gVramBankGroups[1] = 0;
    gVramBankGroups[2] = 0;
    gVramBankGroups[3] = 0;
    gVramBankGroups[4] = 0;
    gVramBankGroups[5] = 0;
    gVramBankGroups[6] = 0;
    gVramBankGroups[7] = 0;
    gVramBankGroups[8] = 0;
    gVramBankGroups[9] = 0;
    gVramBankGroups[10] = 0;
    gVramBankGroups[11] = 0;
    gVramBankGroups[12] = 0;
    *(vu32 *) 0x4000240 = 0;
    reg_GX_VRAMCNT_E = 0;
    reg_GX_VRAMCNT_F = 0;
    reg_GX_VRAMCNT_G = 0;
    *(vu16 *) 0x4000248 = 0;
}

void GX_Init(void) {
    s32 newLockId;

    reg_GX_POWCNT |= 0x8000;
    reg_GX_POWCNT = (reg_GX_POWCNT & ~0x20e) | 0x20e;
    reg_GX_POWCNT |= 0x1;
    GX_InitGXState();
    while (gVramLockId == 0) {
        newLockId = OS_GetLockID();
        if (newLockId == -3) {
            OS_Terminate();
        }
        gVramLockId = newLockId;
    }
    reg_GX_DISPSTAT = 0;
    reg_GX_DISPCNT = 0;
    if (GXi_DmaId != -1) {
        MI_DmaFill32(GXi_DmaId, (void *) 0x4000008, 0, 0x60);
        reg_GX_MASTER_BRIGHT = 0;
        MI_DmaFill32(GXi_DmaId, (void *) 0x4001000, 0, 0x70);
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

void GX_DispOff(void) {
    u32 cnt = reg_GX_DISPCNT;

    gDispOn[0] = 0;
    gSavedDispMode = (cnt & 0x30000) >> 16;
    reg_GX_DISPCNT = cnt & ~0x30000;
}

void GX_DispOn(void) {
    u32 mode;

    gDispOn[0] = 1;
    mode = gSavedDispMode;
    if (mode != 0) {
        reg_GX_DISPCNT = (reg_GX_DISPCNT & ~0x30000) | (mode << 16);
    } else {
        reg_GX_DISPCNT |= 0x10000;
    }
}

void GX_SetGraphicsMode(u16 dispMode, u32 bgMode, s32 bg0As) {
    u32 isDispOn;
    u32 dispCtrl;

    dispCtrl = reg_GX_DISPCNT;
    isDispOn = gDispOn[0];
    gSavedDispMode = dispMode;
    if (isDispOn == 0) {
        dispMode = 0;
    }
    reg_GX_DISPCNT = ((dispCtrl & 0xfff0fff0) | (dispMode << 16) | bgMode) | (bg0As << 3);
    if (gSavedDispMode == 0) {
        gDispOn[0] = 0;
    }
}
