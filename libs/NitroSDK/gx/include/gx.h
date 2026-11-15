#pragma once

#include "types.h"

s32 FX_MulFunc(s32 factorA, s32 factorB);
void FX_Init(void);
void GXx_SetMasterBrightness_(vu16 *reg, s32 brightness);
void GXS_SetGraphicsMode(u32 bgMode);

// Display mode and background mode values of the display register (GX_SetGraphicsMode, GXS_SetGraphicsMode).
enum { GX_DISPMODE_GRAPHICS = 1 };
typedef enum { GX_BGMODE_0, GX_BGMODE_1, GX_BGMODE_2, GX_BGMODE_3, GX_BGMODE_4, GX_BGMODE_5, GX_BGMODE_6 } GXBGMode;

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
