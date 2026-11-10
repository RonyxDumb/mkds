#pragma once

#include "types.h"

// Halfwords of Bg23Cnt after the mode.
typedef struct Bg23CntFields {
    /* 00 */ u16 mBgCntLow2;
    /* 02 */ u16 mBgCntBit6;
    /* 04 */ u16 mBgCntVal14;
    /* 06 */ u16 mUnk_06;
    /* 08 */ u16 mBgCntVal8;
    /* 0a */ u16 mBgCntVal2;
} Bg23CntFields;

// Argument of ApplyBg3Cnt and ApplyBg2Cnt.
typedef struct Bg23Cnt {
    /* 00 */ s32 mMode;
    /* 04 */ Bg23CntFields mFields;
} Bg23Cnt;

typedef struct DisplaySettings DisplaySettings;

// Seven halfwords of a background control record (the first two backgrounds).
typedef struct Bg01Cnt {
    /* 00 */ u16 mBgCntLow2;
    /* 02 */ u16 mBgCntBit6;
    /* 04 */ u16 mBgCntVal14;
    /* 06 */ u16 mBgCntVal7;
    /* 08 */ u16 mBgCntVal8;
    /* 0a */ u16 mBgCntVal2;
    /* 0c */ u16 mBgCntVal13;
    /* 0e */ u8 mUnk_0e[0x2];
} Bg01Cnt;

// The 0x44 bytes at DisplaySettings.mMainBgRecords and mSubBgRecords (unk_02175000.h).
typedef struct DisplayBgRecords {
    /* 00 */ Bg01Cnt mBg0;
    /* 10 */ Bg01Cnt mBg1;
    /* 20 */ Bg23Cnt mBg2;
    /* 30 */ Bg23Cnt mBg3;
    /* 40 */ u16 mObjVRamModeChar;
    /* 42 */ u16 mObjVRamModeBmp;
} DisplayBgRecords;

// The 0x28 bytes InitDisplaySettings copies to the start of an DisplaySettings.
typedef struct DisplaySettingsDesc {
    /* 00 */ u16 mUnk_00[4];
    /* 08 */ u16 mMainBgMode;
    /* 0a */ u16 mUnk_0a;
    /* 0c */ u16 mSubBgMode;
    /* 0e */ u16 mUnk_0e[13];
} DisplaySettingsDesc;

// Two of these sit at gSubBrightnessFade and gMainBrightnessFade; UpdateBrightnessFade steps one.
typedef struct BrightnessFade {
    /* 00 */ u16 mState;
    /* 02 */ u16 mPositive;
    /* 04 */ s16 mFadeFrames;
    /* 06 */ s16 mFadeFrameCount;
    /* 08 */ s16 mBrightness;
    /* 0a */ u16 mUnk_0a;
} BrightnessFade;

extern BrightnessFade gSubBrightnessFade;
extern BrightnessFade gMainBrightnessFade;

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
void SetG3xSwapBits(DisplaySettings *settings, u32 swapBit0, u32 swapBit1);
void SetBg2RecordMode5(DisplayBgRecords *records, u32 cntLow2, u32 cntBit6, u32 cntVal14, u32 e, u32 cntVal8);
void SetBg3RecordParams(DisplayBgRecords *records, u32 cntLow2, u32 cntBit6, u32 cntVal14, u32 e, u32 cntVal8,
                        u32 cntVal2);
void SetBg2RecordParams(DisplayBgRecords *records, u32 cntLow2, u32 cntBit6, u32 cntVal14, u32 e, u32 cntVal8,
                        u32 cntVal2);
void SetBg1Record(DisplayBgRecords *records, u32 cntLow2, u32 cntBit6, u32 cntVal14, u32 cntVal7, u32 cntVal8,
                  u32 cntVal2, u32 cntVal13);
void SetBg0Record(DisplayBgRecords *records, u32 cntLow2, u32 cntBit6, u32 cntVal14, u32 cntVal7, u32 cntVal8,
                  u32 cntVal2, u32 cntVal13);
DisplaySettings *CreateDisplaySettings(void *heap, void *descriptor);
void InitDisplaySettings(DisplaySettings *settings, void *descriptorBase);
void InitDisplayBgRecords(DisplayBgRecords *records, u32 bgMode);
void WaitIrqAndTurnOnDisplays(void);
void InitBrightnessFades(void);
void UpdateBrightnessFade(BrightnessFade *fade);
