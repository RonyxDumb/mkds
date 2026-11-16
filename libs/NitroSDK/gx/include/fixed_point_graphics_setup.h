#pragma once

#include "types.h"

s32 FX_MulFunc(s32 factorA, s32 factorB);
void FX_Initialize(void);
void SetBrightness(vu16 *reg, s32 brightness);
void SetDispcntSubBgMode(u32 bgMode);

// Display mode and background mode values of the display register (ConfigureDispcntDisplay, SetDispcntSubBgMode).
enum { GX_DISPMODE_GRAPHICS = 1 };
typedef enum { GX_BGMODE_0, GX_BGMODE_1, GX_BGMODE_2, GX_BGMODE_3, GX_BGMODE_4, GX_BGMODE_5, GX_BGMODE_6 } GXBGMode;

// One bit per VRAM bank (A to I) in the bank masks of GX_SetBankFor... and GX_ResetBankFor...
enum {
    VRAM_BANK_A = 0x1,
    VRAM_BANK_B = 0x2,
    VRAM_BANK_C = 0x4,
    VRAM_BANK_D = 0x8,
    VRAM_BANK_E = 0x10,
    VRAM_BANK_F = 0x20,
    VRAM_BANK_G = 0x40,
    VRAM_BANK_H = 0x80,
    VRAM_BANK_I = 0x100
};

// Plane bits of the display register (DisplaySettings.mMainDisplayMask / mSubDisplayMask).
enum {
    GX_PLANEMASK_BG0 = 1,
    GX_PLANEMASK_BG1 = 2,
    GX_PLANEMASK_BG2 = 4,
    GX_PLANEMASK_BG3 = 8,
    GX_PLANEMASK_OBJ = 0x10
};

// First background shows tiles or the 3D engine (DisplaySettings.mBg0As).
enum { GX_BG0_AS_2D, GX_BG0_AS_3D };
