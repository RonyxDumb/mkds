#pragma once

#include "types.h"

// Halfwords of Bg23Cnt after the mode.
typedef struct Bg23CntFields {
    /* 00 */ u16 mBgCntLow2;
    /* 02 */ u16 mBgCntBit6;
    /* 04 */ u16 mBgCntVal14;
    /* 06 */ u16 field6;
    /* 08 */ u16 mBgCntVal8;
    /* 0a */ u16 mBgCntVal2;
} Bg23CntFields;

// Argument of setupBg3 and setupBg2.
typedef struct Bg23Cnt {
    /* 00 */ s32 mMode;
    /* 04 */ Bg23CntFields mFields;
} Bg23Cnt;

typedef struct DisplaySettings DisplaySettings;

// The 0xdc-byte object dc_createDisplayConfig returns is an DisplaySettings (unk_02175000.h). Member 0x28 and member
// 0x70 of it are each followed by 0x44 bytes of the layout below.
typedef struct DisplayBgRecords {
    /* 00 */ u16 mBg0CntLow2;
    /* 02 */ u16 mBg0CntBit6;
    /* 04 */ u16 mBg0CntVal14;
    /* 06 */ u16 mBg0CntVal7;
    /* 08 */ u16 mBg0CntVal8;
    /* 0a */ u16 mBg0CntVal2;
    /* 0c */ u16 mBg0CntVal13;
    /* 0e */ u16 fieldE;
    /* 10 */ u16 mBg1CntLow2;
    /* 12 */ u16 mBg1CntBit6;
    /* 14 */ u16 mBg1CntVal14;
    /* 16 */ u16 mBg1CntVal7;
    /* 18 */ u16 mBg1CntVal8;
    /* 1a */ u16 mBg1CntVal2;
    /* 1c */ u16 mBg1CntVal13;
    /* 1e */ u16 field1E;
    /* 20 */ u32 mBg2Mode;
    /* 24 */ u16 mBg2CntLow2;
    /* 26 */ u16 mBg2CntBit6;
    /* 28 */ u16 mBg2CntVal14;
    /* 2a */ u16 field2A;
    /* 2c */ u16 mBg2CntVal8;
    /* 2e */ u16 mBg2CntVal2;
    /* 30 */ u32 mBg3Mode;
    /* 34 */ u16 mBg3CntLow2;
    /* 36 */ u16 mBg3CntBit6;
    /* 38 */ u16 mBg3CntVal14;
    /* 3a */ u16 field3A;
    /* 3c */ u16 mBg3CntVal8;
    /* 3e */ u16 mBg3CntVal2;
    /* 40 */ u16 field40;
    /* 42 */ u16 field42;
} DisplayBgRecords;

// The 0x28 bytes initializeDisplayConfigFromBaseConfig copies to the start of an DisplaySettings.
typedef struct DisplaySettingsDesc {
    /* 00 */ u16 field0[4];
    /* 08 */ u16 mMainBgMode;
    /* 0a */ u16 fieldA;
    /* 0c */ u16 mSubBgMode;
    /* 0e */ u16 fieldE[13];
} DisplaySettingsDesc;

// Two of these sit at gBottomMasterBright and gTopMasterBright; updateMasterBright steps one.
typedef struct BrightnessFade {
    /* 00 */ u16 mState;
    /* 02 */ u16 mPositive;
    /* 04 */ s16 mFadeFrames;
    /* 06 */ s16 mFadeFrameCount;
    /* 08 */ s16 mBrightness;
    /* 0a */ u16 fieldA;
} BrightnessFade;

extern BrightnessFade gBottomMasterBright;
extern BrightnessFade gTopMasterBright;

u32 mbright_isFadedIn(void);
void SetBrightnessFadesClear(void);
u32 mbright_isFadedOut(void);
void mbright_fadeToWhite(s16 frameCount);
void StartFadeToFadedPositiveOneScreen(s16 frameCount, s32 isMainScreen);
void mbright_fadeToBlack(s16 frameCount);
void mbright_fadeFromBlackSingle(s32 frameCount, s32 isMainScreen);
void StartFadeToClearNegative(s16 frameCount);
void mbright_fadeToBlackSingle(s32 frameCount, s32 isMainScreen);
void mbright_fadeIn(s16 frameCount);
void StartFadeToClearOneScreen(s16 frameCount, s32 isMainScreen);
void dc_handleEndOfFrame(void);
void dc_2037498(s32 doSwap);
void dc_2037658(s32 a);
void dc_2037850(void);
u32 dc_clearFlagsBit0(void);
u32 dc_getFlagsBit1(void);
void dc_handleStartOfFrame(void);
void dc_unsetDisplayConfig(void);
void dc_setDisplayConfig(void *settingsPtr);
void setupBg3(Bg23Cnt *cnt, s32 isMainScreen);
void setupBg2(Bg23Cnt *cnt, s32 isMainScreen);
void dc_setSubObjBmpMode(DisplaySettings *settings, unsigned int value);
u32 dc_set3DSwapConfig(DisplaySettings *settings, u32 swapBit0, u32 swapBit1);
void dc_setBg2ConfigMode5(void *recordsBase, u32 cntLow2, u32 cntBit6, u32 cntVal14, u32 e, u32 cntVal8);
void dc_setBg3Config(void *recordsBase, u32 cntLow2, u32 cntBit6, u32 cntVal14, u32 e, u32 cntVal8, u32 cntVal2);
void dc_setBg2Config(void *recordsBase, u32 cntLow2, u32 cntBit6, u32 cntVal14, u32 e, u32 cntVal8, u32 cntVal2);
void dc_setBg1Config(void *recordsBase, u32 cntLow2, u32 cntBit6, u32 cntVal14, u32 cntVal7, u32 cntVal8, u32 cntVal2,
                  u32 cntVal13);
void dc_setBg0Config(void *recordsBase, u32 cntLow2, u32 cntBit6, u32 cntVal14, u32 cntVal7, u32 cntVal8, u32 cntVal2,
                  u32 cntVal13);
void *dc_createDisplayConfig(void *heap, void *descriptor);
void initializeDisplayConfigFromBaseConfig(DisplaySettings *settings, void *descriptorBase);
void initializeDisplayConfigBg(void *recordsBase, u32 bgMode);
void dc_enableDisplay(void);
void dc_initMasterBright(void);
void updateMasterBright(BrightnessFade *fade);
