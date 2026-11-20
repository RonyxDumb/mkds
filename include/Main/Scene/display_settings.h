#pragma once

#include "types.h"
#include "fixed_point_graphics_setup.h"

// Values of Bg23Cnt.mMode, how ApplyBg2Cnt and ApplyBg3Cnt set up background 2 or 3: text, affine, affine without a
// character base, 256 bitmap, DC bitmap. NONE is the start value and the value for BG mode 6; for it they leave the
// control register alone.
typedef enum {
    BG23_MODE_TEXT = 1,
    BG23_MODE_AFFINE,
    BG23_MODE_AFFINE_NO_CHAR_BASE,
    BG23_MODE_256_BMP,
    BG23_MODE_DC_BMP,
    BG23_MODE_NONE
} Bg23Mode;

// Background priority (the low two bits of the control halfword) InitDisplayBgRecords starts each background with.
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

// A background 2 or 3 control record: mMode and mFields; the argument of ApplyBg3Cnt and ApplyBg2Cnt, and what
// DisplayBgRecords holds as mBg2 and mBg3.
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

// The description InitDisplaySettings copies into the display settings: masks, modes and VRAM banks.
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

// BrightnessFade.mBrightness magnitude when the screen is clear and when it is fully faded (the top of the 0 to 16
// range); mBrightness is negated while mPositive is FALSE.
#define BRIGHTNESS_LEVEL_CLEAR 0
#define BRIGHTNESS_LEVEL_FADED 0x10

// The brightness fade of one screen: mState, mPositive, mFadeFrames of mFadeFrameCount, and the resulting mBrightness.
// gMainBrightnessFade and gSubBrightnessFade are two of them; UpdateBrightnessFade steps one.
typedef struct BrightnessFade {
    /* 00 */ u16 mState;
    /* 02 */ u16 mPositive;
    /* 04 */ s16 mFadeFrames;
    /* 06 */ s16 mFadeFrameCount;
    /* 08 */ s16 mBrightness;
    /* 0a */ u16 mUnk_0a;
} BrightnessFade;

u32 AreBrightnessFadesClear(void);
void SetBrightnessFadesClear(void);
u32 AreBrightnessFadesFaded(void);
void StartFadeToFadedPositive(s16 frameCount);
void StartFadeToFadedPositiveOneScreen(s16 frameCount, s32 isMainScreen);
void StartFadeToFadedNegative(s16 frameCount);
void StartFadeToFadedNegativeOneScreen(s32 frameCount, s32 isMainScreen);
void StartFadeToClearNegative(s16 frameCount);
void StartFadeToClearNegativeOneScreen(s32 frameCount, s32 isMainScreen);
void StartFadeToClear(s16 frameCount);
void StartFadeToClearOneScreen(s16 frameCount, s32 isMainScreen);
void RecordFrameTimes(void);
void FinishDisplayFrameSwapIf(s32 doSwap);
void FinishDisplayFrameUnlessSpanned(s32 skipWhenSpanned);
void FinishDisplayFrame(void);
void ClearFrameFinishedFlag(void);
u32 IsFrameSpanningVBlank(void);
void PrepareDisplayFrame(void);
void DisableAllBanksAndNullDisplaySettings(void);
void InitDisplayFromSettings(DisplaySettings *settings);
void ApplyBg3Cnt(Bg23Cnt *cnt, s32 isMainScreen);
void ApplyBg2Cnt(Bg23Cnt *cnt, s32 isMainScreen);
void SetSubObjVRamModeBmp(DisplaySettings *settings, unsigned int value);
void SetG3xSwapBits(DisplaySettings *settings, u32 sortMode, u32 bufferMode);
void SetBg2RecordMode5(DisplayBgRecords *records, u32 cntLow2, u32 cntMosaic, u32 cntVal14, u32 cntVal7Or13,
                       u32 cntVal8);
void SetBg3RecordParams(DisplayBgRecords *records, u32 cntLow2, u32 cntMosaic, u32 cntVal14, u32 cntVal7Or13,
                        u32 cntVal8, u32 cntVal2);
void SetBg2RecordParams(DisplayBgRecords *records, u32 cntLow2, u32 cntMosaic, u32 cntVal14, u32 cntVal7Or13,
                        u32 cntVal8, u32 cntVal2);
void SetBg1Record(DisplayBgRecords *records, u32 cntLow2, u32 cntMosaic, u32 cntVal14, u32 cntVal7, u32 cntVal8,
                  u32 cntVal2, u32 cntVal13);
void SetBg0Record(DisplayBgRecords *records, u32 cntLow2, u32 cntMosaic, u32 cntVal14, u32 cntVal7, u32 cntVal8,
                  u32 cntVal2, u32 cntVal13);
DisplaySettings *CreateDisplaySettings(void *heap, void *descriptor);
void InitDisplaySettings(DisplaySettings *settings, void *descriptorBase);
void InitDisplayBgRecords(DisplayBgRecords *records, u32 bgMode);
void WaitIrqAndTurnOnDisplays(void);
void InitBrightnessFades(void);
void UpdateBrightnessFade(BrightnessFade *fade);

void InitDisplaySettingsDesc(DisplaySettingsDesc *displaySettingsDesc);

extern BrightnessFade gMainBrightnessFade;
extern BrightnessFade gSubBrightnessFade;
