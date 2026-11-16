#pragma once

#include "types.h"
#include "fixed_point_graphics_setup.h"

// Values of Bg23Cnt.mMode, the kind of background 2 or 3: a tile map, an affine map, an affine map without a
// character base, a 256-colour bitmap, a direct-colour bitmap. NONE leaves the register alone (large bitmap mode).
typedef enum {
    BG23_MODE_TEXT = 1,
    BG23_MODE_AFFINE,
    BG23_MODE_AFFINE_NO_CHAR_BASE,
    BG23_MODE_256_BMP,
    BG23_MODE_DC_BMP,
    BG23_MODE_NONE
} Bg23Mode;

// Background priority (the low two bits of the control halfword) DisplayEngineConfig_SomeClearFn starts each background with.
#define DISPLAY_BG0_DEFAULT_PRIORITY 0
#define DISPLAY_BG1_DEFAULT_PRIORITY 1
#define DISPLAY_BG23_DEFAULT_PRIORITY 2

// Halfwords of Bg23Cnt after the mode.
typedef struct Bg23CntFields {
    /* 00 */ u16 mBgCntLow2;
    /* 02 */ u16 mBgCntMosaic;
    /* 04 */ u16 mBgCntVal14;
    /* 06 */ u16 mBgCntVal7Or13;
    /* 08 */ u16 mBgCntVal8;
    /* 0a */ u16 mBgCntVal2;
} Bg23CntFields;

// Argument of SetGlobalDisplayConfig_Bg3 and SetGlobalDisplayConfig_Bg2.
typedef struct Bg23Cnt {
    /* 00 */ s32 mMode;
    /* 04 */ Bg23CntFields mFields;
} Bg23Cnt;

typedef struct DisplaySettings DisplaySettings;

// Seven halfwords of a background control record (the first two backgrounds).
typedef struct Bg01Cnt {
    /* 00 */ u16 mBgCntLow2;
    /* 02 */ u16 mBgCntMosaic;
    /* 04 */ u16 mBgCntVal14;
    /* 06 */ u16 mBgCntVal7;
    /* 08 */ u16 mBgCntVal8;
    /* 0a */ u16 mBgCntVal2;
    /* 0c */ u16 mBgCntVal13;
    /* 0e */ u8 mUnk_0e[0x2];
} Bg01Cnt;

// The background control records of one screen: BG0 to BG3 and the object VRAM modes.
typedef struct DisplayBgRecords {
    /* 00 */ Bg01Cnt mBg0;
    /* 10 */ Bg01Cnt mBg1;
    /* 20 */ Bg23Cnt mBg2;
    /* 30 */ Bg23Cnt mBg3;
    /* 40 */ u16 mObjVRamModeChar;
    /* 42 */ u16 mObjVRamModeBmp;
} DisplayBgRecords;

// The description DisplayConfig_SomeFn copies into the display settings: masks, modes and VRAM banks.
typedef struct DisplaySettingsDesc {
    /* 00 */ u16 mWaitIrqCount;
    /* 02 */ u16 mMainDisplayMask;
    /* 04 */ u16 mSubDisplayMask;
    /* 06 */ u16 mDispMode;
    /* 08 */ u16 mMainBgMode;
    /* 0a */ u16 mBg0As;
    /* 0c */ u16 mSubBgMode;
    /* 0e */ u16 mBankForBG;
    /* 10 */ u16 mBankForOBJ;
    /* 12 */ u16 mBankForBGExtPltt;
    /* 14 */ u16 mBankForOBJExtPltt;
    /* 16 */ u16 mBankForTex;
    /* 18 */ u16 mBankForTexPltt;
    /* 1a */ u16 mBankForClearImage;
    /* 1c */ u16 mBankForSubBG;
    /* 1e */ u16 mBankForSubOBJ;
    /* 20 */ u16 mBankForSubBGExtPltt;
    /* 22 */ u16 mBankForSubOBJExtPltt;
    /* 24 */ u16 mBankForARM7;
    /* 26 */ u16 mBankForLCDC;
} DisplaySettingsDesc;

// Values of BrightnessFade.mState: fully faded and still, fading toward clear, clear, fading toward faded.
enum { BRIGHTNESS_FADE_FADED, BRIGHTNESS_FADE_TO_CLEAR, BRIGHTNESS_FADE_CLEAR, BRIGHTNESS_FADE_TO_FADED };

// BrightnessFade.mBrightness when the screen is clear and when it is fully faded (the top of the 0 to 16 range).
#define BRIGHTNESS_LEVEL_CLEAR 0
#define BRIGHTNESS_LEVEL_FADED 0x10

// Two of these sit at g_BottomBrightnessContext and g_TopBrightnessContext; Bright_UpdateContext steps one.
typedef struct BrightnessFade {
    /* 00 */ u16 mState;
    /* 02 */ u16 mPositive;
    /* 04 */ s16 mFadeFrames;
    /* 06 */ s16 mFadeFrameCount;
    /* 08 */ s16 mBrightness;
    /* 0a */ u16 mUnk_0a;
} BrightnessFade;

u32 Bright_IsBothScreensFadedIn(void);
void Bright_ResetBlackBothScreens(void);
u32 Bright_IsBothScreensFadedOut(void);
void Bright_FadeOutWhite(s16 frameCount);
void StartFadeToFadedPositiveOneScreen(s16 frameCount, s32 isMainScreen);
void Bright_FadeOutBlack(s16 frameCount);
void BrightCtx_SomeFn_0(s32 frameCount, s32 isMainScreen);
void StartFadeToClearNegative(s16 frameCount);
void BrightCtx_SomeFn_1(s32 frameCount, s32 isMainScreen);
void BrightCtx_SomeFnTopBottom(s16 frameCount);
void StartFadeToClearOneScreen(s16 frameCount, s32 isMainScreen);
void LoopFn_DisplayConfig(void);
void UpdateBrightnessContextsAndMore(s32 doSwap);
void FinishDisplayFrameUnlessSpanned(s32 skipWhenSpanned);
void LoopFn_Brightness(void);
void ClearFrameFinishedFlag(void);
u32 IsFrameSpanningVBlank(void);
void LoopFn_Some3D(void);
void ResetDisplayConfig(void);
void SetGlobalDisplayConfig(DisplaySettings *settings);
void SetGlobalDisplayConfig_Bg3(Bg23Cnt *cnt, s32 isMainScreen);
void SetGlobalDisplayConfig_Bg2(Bg23Cnt *cnt, s32 isMainScreen);
void DisplayConfig_SetBottomEngineObjVramModeBmp(DisplaySettings *settings, unsigned int value);
void DisplayConfig_SetSwapBufferValues(DisplaySettings *settings, u32 sortMode, u32 bufferMode);
void DisplayEngineConfig_SetBg2Config(DisplayBgRecords *records, u32 cntLow2, u32 cntMosaic, u32 cntVal14, u32 cntVal7Or13,
                       u32 cntVal8);
void DisplayEngineConfig_SetBg3Config(DisplayBgRecords *records, u32 cntLow2, u32 cntMosaic, u32 cntVal14, u32 cntVal7Or13,
                        u32 cntVal8, u32 cntVal2);
void DisplayEngineConfig_SetBg2Config2(DisplayBgRecords *records, u32 cntLow2, u32 cntMosaic, u32 cntVal14, u32 cntVal7Or13,
                        u32 cntVal8, u32 cntVal2);
void DisplayEngineConfig_SetBg1Config(DisplayBgRecords *records, u32 cntLow2, u32 cntMosaic, u32 cntVal14, u32 cntVal7, u32 cntVal8,
                  u32 cntVal2, u32 cntVal13);
void DisplayEngineConfig_SetBg0Config(DisplayBgRecords *records, u32 cntLow2, u32 cntMosaic, u32 cntVal14, u32 cntVal7, u32 cntVal8,
                  u32 cntVal2, u32 cntVal13);
DisplaySettings *CreateDisplayConfig(void *heap, void *descriptor);
void DisplayConfig_SomeFn(DisplaySettings *settings, void *descriptorBase);
void DisplayEngineConfig_SomeClearFn(DisplayBgRecords *records, u32 bgMode);
void EnableGreenSwap(void);
void InitializeBrightnessContexts(void);
void Bright_UpdateContext(BrightnessFade *fade);

void InitDisplaySettingsDesc(DisplaySettingsDesc *displaySettingsDesc);

extern BrightnessFade g_TopBrightnessContext;
extern BrightnessFade g_BottomBrightnessContext;
