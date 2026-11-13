#include "Main/Scene/display_settings.h"
#include "01/code_021a5140.h"
#include "os_thread.h"
#include "Main/Menu/data_02175000.h"
#include "code_020182c0.h"
#include "frameheap.h"
#include "Main/MapObjects/map_object_park.h"
#include "pm.h"
#include "Main/Sound/sound_seq.h"
#include "code_0200eddc.h"
#include "os_tick.h"
#include "os_irqHandler.h"
#include "gx.h"
#include "Main/System/wvr_state.h"
#include "code_0214a748.h"
#include "g3x.h"
#include "code_02148950.h"
#include "code_0214d018.h"
#include "registers.h"
#include "g2.h"
#include "Main/System/heap.h"
#include "Main/System/startup.h"
#include "Main/Scene/scene_run_forever.h"

void (*gFrameCallback)(s32);
BrightnessFade gMainBrightnessFade;
BrightnessFade gSubBrightnessFade;

void InitDisplaySettingsDesc(DisplaySettingsDesc *p0) {
    p0->mUnk_00[0] = 0x1u;
    p0->mUnk_00[1] = 0x0u;
    p0->mUnk_00[2] = 0x0u;
    p0->mUnk_00[3] = 0x1u;
    p0->mMainBgMode = 0x0u;
    p0->mUnk_0a = 0x0u;
    p0->mSubBgMode = 0x0u;
    p0->mUnk_0e[0] = 0x0u;
    p0->mUnk_0e[1] = 0x0u;
    p0->mUnk_0e[2] = 0x0u;
    p0->mUnk_0e[3] = 0x0u;
    p0->mUnk_0e[4] = 0x0u;
    p0->mUnk_0e[5] = 0x0u;
    p0->mUnk_0e[6] = 0x0u;
    p0->mUnk_0e[7] = 0x0u;
    p0->mUnk_0e[8] = 0x0u;
    p0->mUnk_0e[9] = 0x0u;
    p0->mUnk_0e[10] = 0x0u;
    p0->mUnk_0e[11] = 0x0u;
    p0->mUnk_0e[12] = 0x0u;
}

void UpdateBrightnessFade(BrightnessFade *fade) {
    switch (fade->mState) {
        case 0:
            break;
        case 1:
            fade->mFadeFrames++;
            if (fade->mFadeFrames >= fade->mFadeFrameCount) {
                fade->mState = 2;
                fade->mBrightness = 0;
            } else {
                fade->mBrightness = 0x10 - (fade->mFadeFrames << 4) / fade->mFadeFrameCount;
            }
            if (fade->mPositive == 0) {
                fade->mBrightness = -fade->mBrightness;
            }
            break;
        case 2:
            fade->mBrightness = 0;
            break;
        case 3:
            fade->mFadeFrames++;
            if (fade->mFadeFrames >= fade->mFadeFrameCount) {
                fade->mState = 0;
                fade->mBrightness = 0x10;
            } else {
                fade->mBrightness = (fade->mFadeFrames << 4) / fade->mFadeFrameCount;
            }
            if (fade->mPositive == 0) {
                fade->mBrightness = -fade->mBrightness;
            }
            break;
    }
}

void InitBrightnessFades(void) {
    gMainBrightnessFade.mState = 0;
    gMainBrightnessFade.mPositive = 1;
    gMainBrightnessFade.mFadeFrames = 0;
    gMainBrightnessFade.mFadeFrameCount = 0;
    gMainBrightnessFade.mBrightness = 0x10;
    gSubBrightnessFade.mState = 0;
    gSubBrightnessFade.mPositive = 1;
    gSubBrightnessFade.mFadeFrames = 0;
    gSubBrightnessFade.mFadeFrameCount = 0;
    gSubBrightnessFade.mBrightness = 0x10;
    GXx_SetMasterBrightness_(&reg_GX_MASTER_BRIGHT, gMainBrightnessFade.mBrightness);
    GXx_SetMasterBrightness_(&reg_GXS_DB_MASTER_BRIGHT, gSubBrightnessFade.mBrightness);
}

void WaitIrqAndTurnOnDisplays(void) {
    OS_WaitIrq(1, 1);
    GX_DispOn();
    reg_GXS_DB_DISPCNT = reg_GXS_DB_DISPCNT | 0x10000;
}

void InitDisplayBgRecords(DisplayBgRecords *records, u32 bgMode) {
    u32 bgCntMode;
    records->mBg0.mBgCntLow2 = 0;
    records->mBg0.mBgCntBit6 = 0;
    records->mBg0.mBgCntVal14 = 0;
    records->mBg0.mBgCntVal7 = 0;
    records->mBg0.mBgCntVal8 = 0;
    records->mBg0.mBgCntVal2 = 0;
    records->mBg0.mBgCntVal13 = 0;
    records->mBg1.mBgCntLow2 = 1;
    records->mBg1.mBgCntVal14 = 0;
    records->mBg1.mBgCntVal7 = 0;
    records->mBg1.mBgCntBit6 = 0;
    records->mBg1.mBgCntVal8 = 0;
    records->mBg1.mBgCntVal2 = 0;
    records->mBg1.mBgCntVal13 = 0;
    bgCntMode = 6;
    switch (bgMode) {
        case 0:
        case 1:
        case 3:
            bgCntMode = 1;
            break;
        case 2:
        case 4:
            bgCntMode = 2;
            break;
        case 5:
            bgCntMode = 3;
            break;
        case 6:
            break;
    }
    records->mBg2.mMode = bgCntMode;
    switch (bgCntMode) {
        case 1:
            records->mBg2.mFields.mBgCntLow2 = 2;
            records->mBg2.mFields.mBgCntVal14 = 0;
            records->mBg2.mFields.mBgCntVal7Or13 = 0;
            records->mBg2.mFields.mBgCntBit6 = 0;
            records->mBg2.mFields.mBgCntVal8 = 0;
            records->mBg2.mFields.mBgCntVal2 = 0;
            break;
        case 2:
            records->mBg2.mFields.mBgCntLow2 = 2;
            records->mBg2.mFields.mBgCntVal14 = 0;
            records->mBg2.mFields.mBgCntBit6 = 0;
            records->mBg2.mFields.mBgCntVal7Or13 = 0;
            records->mBg2.mFields.mBgCntVal8 = 0;
            records->mBg2.mFields.mBgCntVal2 = 0;
            break;
        case 3:
            records->mBg2.mFields.mBgCntLow2 = 2;
            records->mBg2.mFields.mBgCntBit6 = 0;
            records->mBg2.mFields.mBgCntVal14 = 0;
            records->mBg2.mFields.mBgCntVal7Or13 = 0;
            records->mBg2.mFields.mBgCntVal8 = 0;
            break;
    }
    bgCntMode = 6;
    switch (bgMode) {
        case 0:
            bgCntMode = 1;
            break;
        case 1:
        case 2:
            bgCntMode = 2;
            break;
        case 3:
        case 4:
        case 5:
            bgCntMode = 3;
            break;
        case 6:
            break;
    }
    records->mBg3.mMode = bgCntMode;
    switch (bgCntMode) {
        case 1:
            records->mBg3.mFields.mBgCntLow2 = 2;
            records->mBg3.mFields.mBgCntVal14 = 0;
            records->mBg3.mFields.mBgCntVal7Or13 = 0;
            records->mBg3.mFields.mBgCntBit6 = 0;
            records->mBg3.mFields.mBgCntVal8 = 0;
            records->mBg3.mFields.mBgCntVal2 = 0;
            break;
        case 2:
            records->mBg3.mFields.mBgCntLow2 = 2;
            records->mBg3.mFields.mBgCntVal14 = 0;
            records->mBg3.mFields.mBgCntBit6 = 0;
            records->mBg3.mFields.mBgCntVal7Or13 = 0;
            records->mBg3.mFields.mBgCntVal8 = 0;
            records->mBg3.mFields.mBgCntVal2 = 0;
            break;
        case 3:
            records->mBg3.mFields.mBgCntLow2 = 2;
            records->mBg3.mFields.mBgCntBit6 = 0;
            records->mBg3.mFields.mBgCntVal14 = 0;
            records->mBg3.mFields.mBgCntVal7Or13 = 0;
            records->mBg3.mFields.mBgCntVal8 = 0;
            break;
    }
    records->mObjVRamModeChar = 0;
    records->mObjVRamModeBmp = 0;
}

void InitDisplaySettings(DisplaySettings *settings, void *descriptorBase) {
    DisplaySettingsDesc *descriptor = descriptorBase;
    *(DisplaySettingsDesc *) settings = *descriptor;
    InitDisplayBgRecords(&settings->mMainBgRecords, descriptor->mMainBgMode);
    InitDisplayBgRecords(&settings->mSubBgRecords, descriptor->mSubBgMode);
    settings->mG3xParams = NULL;
    settings->mFrameStartTick = 0;
    settings->mWaitEndTick = 0;
    settings->mTimeBeforeWait = 0;
    settings->mTimeSinceWaitEnd = 0;
    settings->mTimeSinceFrameStart = 0;
    settings->mUnk_b4 = 0;
    settings->mIrqCallback = NULL;
    settings->mFrameFlags = 0;
}

DisplaySettings *CreateDisplaySettings(void *heap, void *descriptor) {
    DisplaySettings *settings = HeapAlloc(heap, 0xdc);
    G3xParams *g3xParams;
    InitDisplaySettings(settings, descriptor);
    if (settings->mBg0As == 1) {
        g3xParams = HeapAlloc(heap, 8);
        g3xParams->mClearColor = 0x5000;
        g3xParams->mSwapBit0 = 1;
        g3xParams->mSwapBit1 = 1;
        settings->mG3xParams = g3xParams;
    }
    return settings;
}

void SetBg0Record(DisplayBgRecords *records, u32 cntLow2, u32 cntBit6, u32 cntVal14, u32 cntVal7, u32 cntVal8,
                  u32 cntVal2, u32 cntVal13) {
    records->mBg0.mBgCntLow2 = cntLow2;
    records->mBg0.mBgCntVal14 = cntVal14;
    records->mBg0.mBgCntVal7 = cntVal7;
    records->mBg0.mBgCntBit6 = cntBit6;
    records->mBg0.mBgCntVal8 = cntVal8;
    records->mBg0.mBgCntVal2 = cntVal2;
    records->mBg0.mBgCntVal13 = cntVal13;
}

void SetBg1Record(DisplayBgRecords *records, u32 cntLow2, u32 cntBit6, u32 cntVal14, u32 cntVal7, u32 cntVal8,
                  u32 cntVal2, u32 cntVal13) {
    records->mBg1.mBgCntLow2 = cntLow2;
    records->mBg1.mBgCntVal14 = cntVal14;
    records->mBg1.mBgCntVal7 = cntVal7;
    records->mBg1.mBgCntBit6 = cntBit6;
    records->mBg1.mBgCntVal8 = cntVal8;
    records->mBg1.mBgCntVal2 = cntVal2;
    records->mBg1.mBgCntVal13 = cntVal13;
}

void SetBg2RecordParams(DisplayBgRecords *records, u32 cntLow2, u32 cntBit6, u32 cntVal14, u32 cntVal7Or13, u32 cntVal8,
                        u32 cntVal2) {
    records->mBg2.mFields.mBgCntLow2 = cntLow2;
    records->mBg2.mFields.mBgCntBit6 = cntBit6;
    records->mBg2.mFields.mBgCntVal14 = cntVal14;
    records->mBg2.mFields.mBgCntVal7Or13 = cntVal7Or13;
    records->mBg2.mFields.mBgCntVal8 = cntVal8;
    records->mBg2.mFields.mBgCntVal2 = cntVal2;
}

void SetBg3RecordParams(DisplayBgRecords *records, u32 cntLow2, u32 cntBit6, u32 cntVal14, u32 cntVal7Or13, u32 cntVal8,
                        u32 cntVal2) {
    records->mBg3.mFields.mBgCntLow2 = cntLow2;
    records->mBg3.mFields.mBgCntBit6 = cntBit6;
    records->mBg3.mFields.mBgCntVal14 = cntVal14;
    records->mBg3.mFields.mBgCntVal7Or13 = cntVal7Or13;
    records->mBg3.mFields.mBgCntVal8 = cntVal8;
    records->mBg3.mFields.mBgCntVal2 = cntVal2;
}

void SetBg2RecordMode5(DisplayBgRecords *records, u32 cntLow2, u32 cntBit6, u32 cntVal14, u32 cntVal7Or13,
                       u32 cntVal8) {
    records->mBg2.mMode = 5;
    records->mBg2.mFields.mBgCntLow2 = cntLow2;
    records->mBg2.mFields.mBgCntBit6 = cntBit6;
    records->mBg2.mFields.mBgCntVal14 = cntVal14;
    records->mBg2.mFields.mBgCntVal7Or13 = cntVal7Or13;
    records->mBg2.mFields.mBgCntVal8 = cntVal8;
}

void SetG3xSwapBits(DisplaySettings *settings, u32 swapBit0, u32 swapBit1) {
    settings->mG3xParams->mSwapBit0 = swapBit0;
    settings->mG3xParams->mSwapBit1 = swapBit1;
}

void SetSubObjVRamModeBmp(DisplaySettings *settings, u32 value) {
    settings->mSubBgRecords.mObjVRamModeBmp = value;
}

// Enum-typed parameters of the inlines below: their values are read before the register.
typedef enum { UNK_0203810C_ARG_0 } Unk0203810c_Arg;

// Sets the low two bits of the halfword register cntReg and its bit 6 from the first two halfwords of fields.
static inline void SetBg3PriorityAndMosaic(vu16 *cntReg, Bg23CntFields *fields) {
    *cntReg = (*cntReg & ~3) | fields->mBgCntLow2;
    if (fields->mBgCntBit6 != 0) {
        *cntReg |= 0x40;
    } else {
        *cntReg &= ~0x40;
    }
}

// Keeps bits 0, 1 and 6 of the halfword register cntReg and sets the rest from four values.
static inline void SetBg3ControlText(vu16 *cntReg, Unk0203810c_Arg val14, Unk0203810c_Arg val7, Unk0203810c_Arg val8,
                                     Unk0203810c_Arg val2) {
    *cntReg = (*cntReg & 0x43) | (val14 << 14) | (val7 << 7) | (val8 << 8) | (val2 << 2);
}

// Keeps bits 0, 1 and 6 of the halfword register cntReg and sets the rest from four values.
static inline void SetBg3ControlAffine(vu16 *cntReg, Unk0203810c_Arg val14, Unk0203810c_Arg val8, Unk0203810c_Arg val2,
                                       Unk0203810c_Arg val13) {
    *cntReg = (*cntReg & 0x43) | (val14 << 14) | (val8 << 8) | (val2 << 2) | (val13 << 13);
}

// Keeps bits 0, 1 and 6 of the halfword register cntReg and sets the rest from three values.
static inline void SetBg3ControlWithoutCharBase(vu16 *cntReg, Unk0203810c_Arg val14, Unk0203810c_Arg val13,
                                                Unk0203810c_Arg val8) {
    *cntReg = (*cntReg & 0x43) | (val14 << 14) | (val8 << 8) | (val13 << 13);
}

// Keeps bits 0, 1 and 6 of the halfword register cntReg, sets bit 7 and the rest from three values.
static inline void SetBg3Control256Bmp(vu16 *cntReg, Unk0203810c_Arg val14, Unk0203810c_Arg val13,
                                       Unk0203810c_Arg val8) {
    *cntReg = (*cntReg & 0x43) | (val14 << 14) | 0x80 | (val8 << 8) | (val13 << 13);
}

// Keeps bits 0, 1 and 6 of the halfword register cntReg, sets bits 2 and 7 and the rest from three values.
static inline void SetBg3ControlDCBmp(vu16 *cntReg, Unk0203810c_Arg val14, Unk0203810c_Arg val13,
                                      Unk0203810c_Arg val8) {
    *cntReg = (*cntReg & 0x43) | (val14 << 14) | 0x84 | (val8 << 8) | (val13 << 13);
}

// Sets the low two bits of the halfword register cntReg and its bit 6 from the first two halfwords of fields.
static inline void SetBg2PriorityAndMosaic(vu16 *cntReg, Bg23CntFields *fields) {
    *cntReg = (*cntReg & ~3) | fields->mBgCntLow2;
    if (fields->mBgCntBit6 != 0) {
        *cntReg |= 0x40;
    } else {
        *cntReg &= ~0x40;
    }
}

// Keeps bits 0, 1 and 6 of the halfword register cntReg and sets the rest from four values.
static inline void SetBg2ControlText(vu16 *cntReg, Unk0203810c_Arg val14, Unk0203810c_Arg val7, Unk0203810c_Arg val8,
                                     Unk0203810c_Arg val2) {
    *cntReg = (*cntReg & 0x43) | (val14 << 14) | (val7 << 7) | (val8 << 8) | (val2 << 2);
}

// Keeps bits 0, 1 and 6 of the halfword register cntReg and sets the rest from four values.
static inline void SetBg2ControlAffine(vu16 *cntReg, Unk0203810c_Arg val14, Unk0203810c_Arg val8, Unk0203810c_Arg val2,
                                       Unk0203810c_Arg val13) {
    *cntReg = (*cntReg & 0x43) | (val14 << 14) | (val8 << 8) | (val2 << 2) | (val13 << 13);
}

// Keeps bits 0, 1 and 6 of the halfword register cntReg and sets the rest from three values.
static inline void SetBg2ControlWithoutCharBase(vu16 *cntReg, Unk0203810c_Arg val14, Unk0203810c_Arg val13,
                                                Unk0203810c_Arg val8) {
    *cntReg = (*cntReg & 0x43) | (val14 << 14) | (val8 << 8) | (val13 << 13);
}

// Keeps bits 0, 1 and 6 of the halfword register cntReg, sets bit 7 and the rest from three values.
static inline void SetBg2Control256Bmp(vu16 *cntReg, Unk0203810c_Arg val14, Unk0203810c_Arg val13,
                                       Unk0203810c_Arg val8) {
    *cntReg = (*cntReg & 0x43) | (val14 << 14) | 0x80 | (val8 << 8) | (val13 << 13);
}

// Keeps bits 0, 1 and 6 of the halfword register cntReg, sets bits 2 and 7 and the rest from three values.
static inline void SetBg2ControlDCBmp(vu16 *cntReg, Unk0203810c_Arg val14, Unk0203810c_Arg val13,
                                      Unk0203810c_Arg val8) {
    *cntReg = (*cntReg & 0x43) | (val14 << 14) | 0x84 | (val8 << 8) | (val13 << 13);
}

void ApplyBg2Cnt(Bg23Cnt *cnt, s32 isMainScreen) {
    s32 matrix[4];
    Bg23CntFields *fields;

    matrix[1] = 0;
    matrix[2] = 0;
    matrix[0] = 0x1000;
    matrix[3] = 0x1000;
    fields = &cnt->mFields;
    switch (cnt->mMode) {
        case 1:
            if (isMainScreen != 0) {
                reg_G2_BG2OFS = 0;
                SetBg2PriorityAndMosaic(&reg_G2_BG2CNT, fields);
                SetBg2ControlText(&reg_G2_BG2CNT, (Unk0203810c_Arg) fields->mBgCntVal14,
                                  (Unk0203810c_Arg) fields->mBgCntVal7Or13, (Unk0203810c_Arg) fields->mBgCntVal8,
                                  (Unk0203810c_Arg) fields->mBgCntVal2);
            } else {
                reg_G2S_DB_BG2OFS = 0;
                SetBg2PriorityAndMosaic(&reg_G2S_DB_BG2CNT, fields);
                SetBg2ControlText(&reg_G2S_DB_BG2CNT, (Unk0203810c_Arg) fields->mBgCntVal14,
                                  (Unk0203810c_Arg) fields->mBgCntVal7Or13, (Unk0203810c_Arg) fields->mBgCntVal8,
                                  (Unk0203810c_Arg) fields->mBgCntVal2);
            }
            break;
        case 2:
            if (isMainScreen != 0) {
                G2x_SetBGyAffine_(&reg_G2_BG2PA, matrix, 0, 0, 0, 0);
                SetBg2PriorityAndMosaic(&reg_G2_BG2CNT, fields);
                SetBg2ControlAffine(&reg_G2_BG2CNT, (Unk0203810c_Arg) fields->mBgCntVal14,
                                    (Unk0203810c_Arg) fields->mBgCntVal8, (Unk0203810c_Arg) fields->mBgCntVal2,
                                    (Unk0203810c_Arg) fields->mBgCntVal7Or13);
            } else {
                G2x_SetBGyAffine_(&reg_G2S_DB_BG2PA, matrix, 0, 0, 0, 0);
                SetBg2PriorityAndMosaic(&reg_G2S_DB_BG2CNT, fields);
                SetBg2ControlAffine(&reg_G2S_DB_BG2CNT, (Unk0203810c_Arg) fields->mBgCntVal14,
                                    (Unk0203810c_Arg) fields->mBgCntVal8, (Unk0203810c_Arg) fields->mBgCntVal2,
                                    (Unk0203810c_Arg) fields->mBgCntVal7Or13);
            }
            break;
        case 3:
            if (isMainScreen != 0) {
                G2x_SetBGyAffine_(&reg_G2_BG2PA, matrix, 0, 0, 0, 0);
                SetBg2PriorityAndMosaic(&reg_G2_BG2CNT, fields);
                SetBg2ControlWithoutCharBase(&reg_G2_BG2CNT, (Unk0203810c_Arg) fields->mBgCntVal14,
                                             (Unk0203810c_Arg) fields->mBgCntVal7Or13,
                                             (Unk0203810c_Arg) fields->mBgCntVal8);
            } else {
                G2x_SetBGyAffine_(&reg_G2S_DB_BG2PA, matrix, 0, 0, 0, 0);
                SetBg2PriorityAndMosaic(&reg_G2S_DB_BG2CNT, fields);
                SetBg2ControlWithoutCharBase(&reg_G2S_DB_BG2CNT, (Unk0203810c_Arg) fields->mBgCntVal14,
                                             (Unk0203810c_Arg) fields->mBgCntVal7Or13,
                                             (Unk0203810c_Arg) fields->mBgCntVal8);
            }
            break;
        case 4:
            if (isMainScreen != 0) {
                G2x_SetBGyAffine_(&reg_G2_BG2PA, matrix, 0, 0, 0, 0);
                SetBg2PriorityAndMosaic(&reg_G2_BG2CNT, fields);
                SetBg2Control256Bmp(&reg_G2_BG2CNT, (Unk0203810c_Arg) fields->mBgCntVal14,
                                    (Unk0203810c_Arg) fields->mBgCntVal7Or13, (Unk0203810c_Arg) fields->mBgCntVal8);
            } else {
                G2x_SetBGyAffine_(&reg_G2S_DB_BG2PA, matrix, 0, 0, 0, 0);
                SetBg2PriorityAndMosaic(&reg_G2S_DB_BG2CNT, fields);
                SetBg2Control256Bmp(&reg_G2S_DB_BG2CNT, (Unk0203810c_Arg) fields->mBgCntVal14,
                                    (Unk0203810c_Arg) fields->mBgCntVal7Or13, (Unk0203810c_Arg) fields->mBgCntVal8);
            }
            break;
        case 5:
            if (isMainScreen != 0) {
                G2x_SetBGyAffine_(&reg_G2_BG2PA, matrix, 0, 0, 0, 0);
                SetBg2PriorityAndMosaic(&reg_G2_BG2CNT, fields);
                SetBg2ControlDCBmp(&reg_G2_BG2CNT, (Unk0203810c_Arg) fields->mBgCntVal14,
                                   (Unk0203810c_Arg) fields->mBgCntVal7Or13, (Unk0203810c_Arg) fields->mBgCntVal8);
            } else {
                G2x_SetBGyAffine_(&reg_G2S_DB_BG2PA, matrix, 0, 0, 0, 0);
                SetBg2PriorityAndMosaic(&reg_G2S_DB_BG2CNT, fields);
                SetBg2ControlDCBmp(&reg_G2S_DB_BG2CNT, (Unk0203810c_Arg) fields->mBgCntVal14,
                                   (Unk0203810c_Arg) fields->mBgCntVal7Or13, (Unk0203810c_Arg) fields->mBgCntVal8);
            }
            break;
        default:
            break;
    }
}

void ApplyBg3Cnt(Bg23Cnt *cnt, s32 isMainScreen) {
    s32 matrix[4];
    Bg23CntFields *fields;

    matrix[1] = 0;
    matrix[2] = 0;
    matrix[0] = 0x1000;
    matrix[3] = 0x1000;
    fields = &cnt->mFields;
    switch (cnt->mMode) {
        case 1:
            if (isMainScreen != 0) {
                reg_G2_BG3OFS = 0;
                SetBg3PriorityAndMosaic(&reg_G2_BG3CNT, fields);
                SetBg3ControlText(&reg_G2_BG3CNT, (Unk0203810c_Arg) fields->mBgCntVal14,
                                  (Unk0203810c_Arg) fields->mBgCntVal7Or13, (Unk0203810c_Arg) fields->mBgCntVal8,
                                  (Unk0203810c_Arg) fields->mBgCntVal2);
            } else {
                reg_G2S_DB_BG3OFS = 0;
                SetBg3PriorityAndMosaic(&reg_G2S_DB_BG3CNT, fields);
                SetBg3ControlText(&reg_G2S_DB_BG3CNT, (Unk0203810c_Arg) fields->mBgCntVal14,
                                  (Unk0203810c_Arg) fields->mBgCntVal7Or13, (Unk0203810c_Arg) fields->mBgCntVal8,
                                  (Unk0203810c_Arg) fields->mBgCntVal2);
            }
            break;
        case 2:
            if (isMainScreen != 0) {
                G2x_SetBGyAffine_(&reg_G2_BG3PA, matrix, 0, 0, 0, 0);
                SetBg3PriorityAndMosaic(&reg_G2_BG3CNT, fields);
                SetBg3ControlAffine(&reg_G2_BG3CNT, (Unk0203810c_Arg) fields->mBgCntVal14,
                                    (Unk0203810c_Arg) fields->mBgCntVal8, (Unk0203810c_Arg) fields->mBgCntVal2,
                                    (Unk0203810c_Arg) fields->mBgCntVal7Or13);
            } else {
                G2x_SetBGyAffine_(&reg_G2S_DB_BG3PA, matrix, 0, 0, 0, 0);
                SetBg3PriorityAndMosaic(&reg_G2S_DB_BG3CNT, fields);
                SetBg3ControlAffine(&reg_G2S_DB_BG3CNT, (Unk0203810c_Arg) fields->mBgCntVal14,
                                    (Unk0203810c_Arg) fields->mBgCntVal8, (Unk0203810c_Arg) fields->mBgCntVal2,
                                    (Unk0203810c_Arg) fields->mBgCntVal7Or13);
            }
            break;
        case 3:
            if (isMainScreen != 0) {
                G2x_SetBGyAffine_(&reg_G2_BG3PA, matrix, 0, 0, 0, 0);
                SetBg3PriorityAndMosaic(&reg_G2_BG3CNT, fields);
                SetBg3ControlWithoutCharBase(&reg_G2_BG3CNT, (Unk0203810c_Arg) fields->mBgCntVal14,
                                             (Unk0203810c_Arg) fields->mBgCntVal7Or13,
                                             (Unk0203810c_Arg) fields->mBgCntVal8);
            } else {
                G2x_SetBGyAffine_(&reg_G2S_DB_BG3PA, matrix, 0, 0, 0, 0);
                SetBg3PriorityAndMosaic(&reg_G2S_DB_BG3CNT, fields);
                SetBg3ControlWithoutCharBase(&reg_G2S_DB_BG3CNT, (Unk0203810c_Arg) fields->mBgCntVal14,
                                             (Unk0203810c_Arg) fields->mBgCntVal7Or13,
                                             (Unk0203810c_Arg) fields->mBgCntVal8);
            }
            break;
        case 4:
            if (isMainScreen != 0) {
                G2x_SetBGyAffine_(&reg_G2_BG3PA, matrix, 0, 0, 0, 0);
                SetBg3PriorityAndMosaic(&reg_G2_BG3CNT, fields);
                SetBg3Control256Bmp(&reg_G2_BG3CNT, (Unk0203810c_Arg) fields->mBgCntVal14,
                                    (Unk0203810c_Arg) fields->mBgCntVal7Or13, (Unk0203810c_Arg) fields->mBgCntVal8);
            } else {
                G2x_SetBGyAffine_(&reg_G2S_DB_BG3PA, matrix, 0, 0, 0, 0);
                SetBg3PriorityAndMosaic(&reg_G2S_DB_BG3CNT, fields);
                SetBg3Control256Bmp(&reg_G2S_DB_BG3CNT, (Unk0203810c_Arg) fields->mBgCntVal14,
                                    (Unk0203810c_Arg) fields->mBgCntVal7Or13, (Unk0203810c_Arg) fields->mBgCntVal8);
            }
            break;
        case 5:
            if (isMainScreen != 0) {
                G2x_SetBGyAffine_(&reg_G2_BG3PA, matrix, 0, 0, 0, 0);
                SetBg3PriorityAndMosaic(&reg_G2_BG3CNT, fields);
                SetBg3ControlDCBmp(&reg_G2_BG3CNT, (Unk0203810c_Arg) fields->mBgCntVal14,
                                   (Unk0203810c_Arg) fields->mBgCntVal7Or13, (Unk0203810c_Arg) fields->mBgCntVal8);
            } else {
                G2x_SetBGyAffine_(&reg_G2S_DB_BG3PA, matrix, 0, 0, 0, 0);
                SetBg3PriorityAndMosaic(&reg_G2S_DB_BG3CNT, fields);
                SetBg3ControlDCBmp(&reg_G2S_DB_BG3CNT, (Unk0203810c_Arg) fields->mBgCntVal14,
                                   (Unk0203810c_Arg) fields->mBgCntVal7Or13, (Unk0203810c_Arg) fields->mBgCntVal8);
            }
            break;
        default:
            break;
    }
}

// Enum-typed parameters of the inlines below: their values are read before the register.
typedef enum { UNK_02037ABC_ARG_0 } Unk02037abc_Arg;

// Calls MIi_CpuClearFast with the value read from a volatile copy.
static inline void DisplayFillMemoryFast(u32 fillValue, void *destination, u32 size) {
    volatile u32 fillValueCopy = fillValue;
    MIi_CpuClearFast(fillValueCopy, destination, size);
}

// Sets the low two bits of the halfword register cntReg and its bit 6 from the first two halfwords of q.
static inline void SetBg01PriorityAndMosaic(vu16 *cntReg, Bg01Cnt *cnt) {
    *cntReg = (*cntReg & ~3) | cnt->mBgCntLow2;
    if (cnt->mBgCntBit6 != 0) {
        *cntReg |= 0x40;
    } else {
        *cntReg &= ~0x40;
    }
}

// Sets bits 4, 20 and 21 of the word register r.
static inline void SetDispcntObjVRamModeChar(vu32 *reg, Unk02037abc_Arg bits) {
    *reg = (*reg & 0xffcfffef) | bits;
}

// Sets bits 5, 6 and 22 of the word at 0x04000000.
static inline void DisplayGX_SetOBJVRamModeBmp(Unk02037abc_Arg bits) {
    reg_GX_DISPCNT = (reg_GX_DISPCNT & 0xffbfff9f) | bits;
}

// Sets bits 5 and 6 of the word at 0x04001000.
static inline void DisplayGXS_SetOBJVRamModeBmp(Unk02037abc_Arg bits) {
    reg_GXS_DB_DISPCNT = (reg_GXS_DB_DISPCNT & ~0x60) | bits;
}

// Keeps bits 0, 1 and 6 of the halfword register cntReg and sets the rest from five values.
static inline void SetBg01Control(vu16 *cntReg, Unk02037abc_Arg val14, Unk02037abc_Arg val7, Unk02037abc_Arg val8,
                                  Unk02037abc_Arg val2, Unk02037abc_Arg val13) {
    *cntReg = (*cntReg & 0x43) | (val14 << 14) | (val7 << 7) | (val8 << 8) | (val2 << 2) | (val13 << 13);
}

void InitDisplayFromSettings(DisplaySettings *settings) {
    Bg01Cnt *cnt;
    u16 clearColor;

    gDisplaySettings = settings;
    ClearLcdcBanksByState();
    DisplayFillMemoryFast(0xc0, HW_OAM, 0x400);
    DisplayFillMemoryFast(0xc0, HW_DB_OAM, 0x400);
    DisplayFillMemoryFast(0, HW_BG_PLTT, 0x400);
    DisplayFillMemoryFast(0, HW_DB_BG_PLTT, 0x400);
    if (gDisplaySettings->mBankForBG != 0) {
        GX_SetBankForBG(gDisplaySettings->mBankForBG);
    }
    if (gDisplaySettings->mBankForOBJ != 0) {
        GX_SetBankForOBJ(gDisplaySettings->mBankForOBJ);
    }
    if (gDisplaySettings->mBankForBGExtPltt != 0) {
        GX_SetBankForBGExtPltt(gDisplaySettings->mBankForBGExtPltt);
    }
    if (gDisplaySettings->mBankForOBJExtPltt != 0) {
        GX_SetBankForOBJExtPltt(gDisplaySettings->mBankForOBJExtPltt);
    }
    if (gDisplaySettings->mBankForTex != 0) {
        GX_SetBankForTex(gDisplaySettings->mBankForTex);
    }
    if (gDisplaySettings->mBankForTexPltt != 0) {
        GX_SetBankForTexPltt(gDisplaySettings->mBankForTexPltt);
    }
    if (gDisplaySettings->mBankForClearImage != 0) {
        GX_SetBankForClearImage(gDisplaySettings->mBankForClearImage);
    }
    if (gDisplaySettings->mBankForSubBG != 0) {
        GX_SetBankForSubBG(gDisplaySettings->mBankForSubBG);
    }
    if (gDisplaySettings->mBankForSubOBJ != 0) {
        GX_SetBankForSubOBJ(gDisplaySettings->mBankForSubOBJ);
    }
    if (gDisplaySettings->mBankForSubBGExtPltt != 0) {
        GX_SetBankForSubBGExtPltt(gDisplaySettings->mBankForSubBGExtPltt);
    }
    if (gDisplaySettings->mBankForSubOBJExtPltt != 0) {
        GX_SetBankForSubOBJExtPltt(gDisplaySettings->mBankForSubOBJExtPltt);
    }
    if (gDisplaySettings->mBankForARM7 != 0) {
        SetBankForARM7ByState(gDisplaySettings->mBankForARM7);
    }
    if (gDisplaySettings->mBankForLCDC != 0) {
        GX_SetBankForLCDC(gDisplaySettings->mBankForLCDC);
    }
    gWvrState.mState;
    GX_SetGraphicsMode(settings->mDispMode, settings->mMainBgMode, settings->mBg0As);
    reg_GX_DISPCNT = (reg_GX_DISPCNT & ~0x1f00) | (settings->mMainDisplayMask << 8);
    GXS_SetGraphicsMode(settings->mSubBgMode);
    reg_GXS_DB_DISPCNT = (reg_GXS_DB_DISPCNT & ~0x1f00) | (settings->mSubDisplayMask << 8);
    if (settings->mBg0As == 1) {
        G3X_Init();
        G3X_InitTable();
        G3X_InitMtxStack();
        reg_G3X_DISP3DCNT &= 0xffffcffd;
        reg_G3X_DISP3DCNT = (reg_G3X_DISP3DCNT & ~0x3000) | 0x10;
        reg_G3X_DISP3DCNT = (reg_G3X_DISP3DCNT & ~0x3000) | 4;
        reg_G3X_ALPHA_TEST_REF = 0;
        reg_G3X_DISP3DCNT = (reg_G3X_DISP3DCNT & ~0x3000) | 8;
        reg_G2_BLDCNT = 0;
        reg_G3_SWAP_BUFFERS = (settings->mG3xParams->mSwapBit1 << 1) | settings->mG3xParams->mSwapBit0;
        clearColor = settings->mG3xParams->mClearColor;
        G3X_SetClearColor((u16) (clearColor & 0x7fff), (u8) ((clearColor & 0x8000) >> 15), 0x7fff, 0x3f, 0);
    }
    if (settings->mMainDisplayMask & 1) {
        cnt = &settings->mMainBgRecords.mBg0;
        SetBg01PriorityAndMosaic(&reg_G2_BG0CNT, cnt);
        if (settings->mBg0As == 1) {
            G2Bg0OfsWrite(0);
        } else {
            reg_G2_BG0OFS = 0;
            SetBg01Control(&reg_G2_BG0CNT, (Unk02037abc_Arg) cnt->mBgCntVal14, (Unk02037abc_Arg) cnt->mBgCntVal7,
                           (Unk02037abc_Arg) cnt->mBgCntVal8, (Unk02037abc_Arg) cnt->mBgCntVal2,
                           (Unk02037abc_Arg) cnt->mBgCntVal13);
        }
    }
    if (settings->mSubDisplayMask & 1) {
        reg_G2S_DB_BG0OFS = 0;
        cnt = &settings->mSubBgRecords.mBg0;
        SetBg01PriorityAndMosaic(&reg_G2S_DB_BG0CNT, cnt);
        SetBg01Control(&reg_G2S_DB_BG0CNT, (Unk02037abc_Arg) cnt->mBgCntVal14, (Unk02037abc_Arg) cnt->mBgCntVal7,
                       (Unk02037abc_Arg) cnt->mBgCntVal8, (Unk02037abc_Arg) cnt->mBgCntVal2,
                       (Unk02037abc_Arg) cnt->mBgCntVal13);
    }
    if (settings->mMainDisplayMask & 2) {
        reg_G2_BG1OFS = 0;
        cnt = &settings->mMainBgRecords.mBg1;
        SetBg01PriorityAndMosaic(&reg_G2_BG1CNT, cnt);
        SetBg01Control(&reg_G2_BG1CNT, (Unk02037abc_Arg) cnt->mBgCntVal14, (Unk02037abc_Arg) cnt->mBgCntVal7,
                       (Unk02037abc_Arg) cnt->mBgCntVal8, (Unk02037abc_Arg) cnt->mBgCntVal2,
                       (Unk02037abc_Arg) cnt->mBgCntVal13);
    }
    if (settings->mSubDisplayMask & 2) {
        reg_G2S_DB_BG1OFS = 0;
        cnt = &settings->mSubBgRecords.mBg1;
        SetBg01PriorityAndMosaic(&reg_G2S_DB_BG1CNT, cnt);
        SetBg01Control(&reg_G2S_DB_BG1CNT, (Unk02037abc_Arg) cnt->mBgCntVal14, (Unk02037abc_Arg) cnt->mBgCntVal7,
                       (Unk02037abc_Arg) cnt->mBgCntVal8, (Unk02037abc_Arg) cnt->mBgCntVal2,
                       (Unk02037abc_Arg) cnt->mBgCntVal13);
    }
    if (settings->mMainDisplayMask & 4) {
        ApplyBg2Cnt(&settings->mMainBgRecords.mBg2, 1);
    }
    if (settings->mSubDisplayMask & 4) {
        ApplyBg2Cnt(&settings->mSubBgRecords.mBg2, 0);
    }
    if (settings->mMainDisplayMask & 8) {
        ApplyBg3Cnt(&settings->mMainBgRecords.mBg3, 1);
    }
    if (settings->mSubDisplayMask & 8) {
        ApplyBg3Cnt(&settings->mSubBgRecords.mBg3, 0);
    }
    if (settings->mMainDisplayMask & 0x10) {
        SetDispcntObjVRamModeChar(&reg_GX_DISPCNT, (Unk02037abc_Arg) settings->mMainBgRecords.mObjVRamModeChar);
        DisplayGX_SetOBJVRamModeBmp((Unk02037abc_Arg) settings->mMainBgRecords.mObjVRamModeBmp);
    }
    if (settings->mSubDisplayMask & 0x10) {
        SetDispcntObjVRamModeChar(&reg_GXS_DB_DISPCNT, (Unk02037abc_Arg) settings->mSubBgRecords.mObjVRamModeChar);
        DisplayGXS_SetOBJVRamModeBmp((Unk02037abc_Arg) settings->mSubBgRecords.mObjVRamModeBmp);
    }
    reg_GX_POWCNT |= 0x8000;
}

void DisableAllBanksAndNullDisplaySettings(void) {
    DisableAllBanks();
    gDisplaySettings = NULL;
}

void PrepareDisplayFrame(void) {
    DisplaySettings *settings;
    u64 tick;
    settings = gDisplaySettings;
    tick = OS_GetTick();
    settings->mFrameStartTick = tick;
    if (settings->mBg0As == 1) {
        G3X_Reset();
    }
    if (gFrameCallback != NULL) {
        gFrameCallback(0);
    }
}

u32 IsFrameSpanningVBlank(void) {
    return (gDisplaySettings->mFrameFlags & 2) ? 1 : 0;
}

void ClearFrameFinishedFlag(void) {
    u32 frameFlags;
    frameFlags = gDisplaySettings->mFrameFlags;
    frameFlags = (frameFlags) & ~(1u);
    gDisplaySettings->mFrameFlags = frameFlags;
}

static inline void StartBrightnessFadeToFadedPositive(BrightnessFade *fade, s16 frameCount) {
    if (fade->mState == 0 || (fade->mState == 3 && fade->mPositive == 1)) {
        return;
    }
    fade->mPositive = 1;
    if (fade->mState != 1) {
        fade->mFadeFrames = 0;
    } else {
        fade->mFadeFrames = (frameCount * fade->mBrightness) / 16;
    }
    fade->mState = 3;
    fade->mFadeFrameCount = frameCount;
}

static inline void StartBrightnessFadeToFadedNegative(BrightnessFade *fade, s16 frameCount) {
    if (fade->mState == 0 || (fade->mState == 3 && fade->mPositive == 0)) {
        return;
    }
    fade->mPositive = 0;
    if (fade->mState != 1) {
        fade->mFadeFrames = 0;
    } else {
        fade->mFadeFrames = (frameCount * fade->mBrightness) / 16;
    }
    fade->mState = 3;
    fade->mFadeFrameCount = frameCount;
}

static inline void StartBrightnessFadeToClearNegative(BrightnessFade *fade, s16 frameCount) {
    if (fade->mState == 2 || fade->mState == 1) {
        return;
    }
    fade->mPositive = 0;
    if (fade->mState == 2 || fade->mState == 1) {
        return;
    }
    if (fade->mState != 3) {
        fade->mFadeFrames = 0;
    } else {
        fade->mFadeFrames = (frameCount * fade->mBrightness) / 16;
    }
    fade->mState = 1;
    fade->mFadeFrameCount = frameCount;
}

static inline void StartBrightnessFadeToClear(BrightnessFade *fade, s16 frameCount) {
    if (fade->mState == 2 || fade->mState == 1) {
        return;
    }
    if (fade->mState != 3) {
        fade->mFadeFrames = 0;
    } else {
        fade->mFadeFrames = (frameCount * fade->mBrightness) / 16;
    }
    fade->mState = 1;
    fade->mFadeFrameCount = frameCount;
}

void FinishDisplayFrame(void) {
    DisplaySettings *settings;
    u64 tick;
    s16 prevMainBrightness;
    s16 prevSubBrightness;
    u16 waitIndex;
    prevMainBrightness = gMainBrightnessFade.mBrightness;
    prevSubBrightness = gSubBrightnessFade.mBrightness;
    if (gFrameCallback != NULL) {
        gFrameCallback(1);
    }
    UpdateBrightnessFade(&gMainBrightnessFade);
    UpdateBrightnessFade(&gSubBrightnessFade);
    DC_StoreAll();
    settings = gDisplaySettings;
    if (settings->mBg0As == 1) {
        reg_G3_SWAP_BUFFERS = (settings->mG3xParams->mSwapBit1 << 1) | settings->mG3xParams->mSwapBit0;
    }
    if ((gDisplaySettings->mFrameFlags & 1) == 0) {
        gDisplaySettings->mFrameFlags |= 2;
    } else {
        gDisplaySettings->mFrameFlags &= ~2;
        gDisplaySettings->mFrameFlags &= ~1;
    }
    settings = gDisplaySettings;
    tick = OS_GetTick();
    settings->mTimeBeforeWait = (tick - settings->mFrameStartTick) * 0xfa00 / 0x82ea;
    for (waitIndex = 0; waitIndex < gDisplaySettings->mWaitIrqCount; waitIndex++) {
        OS_WaitIrq(1, 1);
    }
    gDisplaySettings->mFrameFlags |= 1;
    gDisplaySettings->mWaitEndTick = OS_GetTick();
    if (prevMainBrightness != gMainBrightnessFade.mBrightness) {
        GXx_SetMasterBrightness_(&reg_GX_MASTER_BRIGHT, gMainBrightnessFade.mBrightness);
    }
    if (prevSubBrightness != gSubBrightnessFade.mBrightness) {
        GXx_SetMasterBrightness_(&reg_GXS_DB_MASTER_BRIGHT, gSubBrightnessFade.mBrightness);
    }
    if (gFrameCallback != NULL) {
        gFrameCallback(2);
    }
}

void FinishDisplayFrameUnlessSpanned(s32 skipWhenSpanned) {
    u64 tick;
    s16 prevMainBrightness;
    s16 prevSubBrightness;
    u16 waitIndex;
    BOOL swapAndWait;
    DisplaySettings *settings;
    prevMainBrightness = gMainBrightnessFade.mBrightness;
    prevSubBrightness = gSubBrightnessFade.mBrightness;
    if (gFrameCallback != NULL) {
        gFrameCallback(1);
    }
    UpdateBrightnessFade(&gMainBrightnessFade);
    UpdateBrightnessFade(&gSubBrightnessFade);
    DC_StoreAll();
    if ((gDisplaySettings->mFrameFlags & 1) == 0) {
        gDisplaySettings->mFrameFlags |= 2;
    } else {
        gDisplaySettings->mFrameFlags &= ~2;
        gDisplaySettings->mFrameFlags &= ~1;
    }
    if (skipWhenSpanned == 0 || (gDisplaySettings->mFrameFlags & 2) == 0) {
        swapAndWait = TRUE;
    } else {
        swapAndWait = FALSE;
    }
    settings = gDisplaySettings;
    if (settings->mBg0As == 1 && swapAndWait != FALSE) {
        reg_G3_SWAP_BUFFERS = (settings->mG3xParams->mSwapBit1 << 1) | settings->mG3xParams->mSwapBit0;
    }
    settings = gDisplaySettings;
    tick = OS_GetTick();
    settings->mTimeBeforeWait = (tick - settings->mFrameStartTick) * 0xfa00 / 0x82ea;
    if (swapAndWait != FALSE) {
        for (waitIndex = 0; waitIndex < gDisplaySettings->mWaitIrqCount; waitIndex++) {
            OS_WaitIrq(1, 1);
        }
    }
    gDisplaySettings->mFrameFlags |= 1;
    gDisplaySettings->mWaitEndTick = OS_GetTick();
    if (prevMainBrightness != gMainBrightnessFade.mBrightness) {
        GXx_SetMasterBrightness_(&reg_GX_MASTER_BRIGHT, gMainBrightnessFade.mBrightness);
    }
    if (prevSubBrightness != gSubBrightnessFade.mBrightness) {
        GXx_SetMasterBrightness_(&reg_GXS_DB_MASTER_BRIGHT, gSubBrightnessFade.mBrightness);
    }
    if (gFrameCallback != NULL) {
        gFrameCallback(2);
    }
}

void FinishDisplayFrameSwapIf(s32 doSwap) {
    DisplaySettings *settings;
    u64 tick;
    s16 prevMainBrightness;
    s16 prevSubBrightness;
    u16 waitIndex;
    prevMainBrightness = gMainBrightnessFade.mBrightness;
    prevSubBrightness = gSubBrightnessFade.mBrightness;
    if (gFrameCallback != NULL) {
        gFrameCallback(1);
    }
    UpdateBrightnessFade(&gMainBrightnessFade);
    UpdateBrightnessFade(&gSubBrightnessFade);
    DC_StoreAll();
    if ((gDisplaySettings->mFrameFlags & 1) == 0) {
        gDisplaySettings->mFrameFlags |= 2;
    } else {
        gDisplaySettings->mFrameFlags &= ~2;
        gDisplaySettings->mFrameFlags &= ~1;
    }
    settings = gDisplaySettings;
    if (settings->mBg0As == 1 && doSwap != 0) {
        reg_G3_SWAP_BUFFERS = (settings->mG3xParams->mSwapBit1 << 1) | settings->mG3xParams->mSwapBit0;
    }
    settings = gDisplaySettings;
    tick = OS_GetTick();
    settings->mTimeBeforeWait = (tick - settings->mFrameStartTick) * 0xfa00 / 0x82ea;
    for (waitIndex = 0; waitIndex < gDisplaySettings->mWaitIrqCount; waitIndex++) {
        OS_WaitIrq(1, 1);
    }
    gDisplaySettings->mFrameFlags |= 1;
    gDisplaySettings->mWaitEndTick = OS_GetTick();
    if (prevMainBrightness != gMainBrightnessFade.mBrightness) {
        GXx_SetMasterBrightness_(&reg_GX_MASTER_BRIGHT, gMainBrightnessFade.mBrightness);
    }
    if (prevSubBrightness != gSubBrightnessFade.mBrightness) {
        GXx_SetMasterBrightness_(&reg_GXS_DB_MASTER_BRIGHT, gSubBrightnessFade.mBrightness);
    }
    if (gFrameCallback != NULL) {
        gFrameCallback(2);
    }
}

void RecordFrameTimes(void) {
    u64 tick;
    DisplaySettings *settings;
    tick = OS_GetTick();
    if (gFrameCallback != NULL) {
        gFrameCallback(3);
    }
    settings = gDisplaySettings;
    settings->mTimeSinceWaitEnd = (tick - settings->mWaitEndTick) * 0xfa00 / 0x82ea;
    settings = gDisplaySettings;
    settings->mTimeSinceFrameStart = (tick - settings->mFrameStartTick) * 0xfa00 / 0x82ea;
}

void StartFadeToClearOneScreen(s16 frameCount, s32 isMainScreen) {
    if (isMainScreen != 0) {
        StartBrightnessFadeToClear(&gMainBrightnessFade, frameCount);
    } else {
        StartBrightnessFadeToClear(&gSubBrightnessFade, frameCount);
    }
}

void StartFadeToClear(s16 frameCount) {
    StartBrightnessFadeToClear(&gMainBrightnessFade, frameCount);
    StartBrightnessFadeToClear(&gSubBrightnessFade, frameCount);
}

void StartFadeToClearNegativeOneScreen(s32 frameCount, s32 isMainScreen) {
    if (isMainScreen != 0) {
        StartBrightnessFadeToClearNegative(&gMainBrightnessFade, frameCount);
    } else {
        StartBrightnessFadeToClearNegative(&gSubBrightnessFade, frameCount);
    }
}

void StartFadeToClearNegative(s16 frameCount) {
    StartBrightnessFadeToClearNegative(&gMainBrightnessFade, frameCount);
    StartBrightnessFadeToClearNegative(&gSubBrightnessFade, frameCount);
}

void StartFadeToFadedNegativeOneScreen(s32 frameCount, s32 isMainScreen) {
    if (isMainScreen != 0) {
        StartBrightnessFadeToFadedNegative(&gMainBrightnessFade, frameCount);
    } else {
        StartBrightnessFadeToFadedNegative(&gSubBrightnessFade, frameCount);
    }
}

void StartFadeToFadedNegative(s16 frameCount) {
    StartBrightnessFadeToFadedNegative(&gMainBrightnessFade, frameCount);
    StartBrightnessFadeToFadedNegative(&gSubBrightnessFade, frameCount);
}

void StartFadeToFadedPositiveOneScreen(s16 frameCount, s32 isMainScreen) {
    if (isMainScreen != 0) {
        StartBrightnessFadeToFadedPositive(&gMainBrightnessFade, frameCount);
    } else {
        StartBrightnessFadeToFadedPositive(&gSubBrightnessFade, frameCount);
    }
}

void StartFadeToFadedPositive(s16 frameCount) {
    StartBrightnessFadeToFadedPositive(&gMainBrightnessFade, frameCount);
    StartBrightnessFadeToFadedPositive(&gSubBrightnessFade, frameCount);
}

u32 AreBrightnessFadesFaded(void) {
    if (gMainBrightnessFade.mState == 0 && gSubBrightnessFade.mState == 0) {
        return 1;
    }
    return 0;
}

void SetBrightnessFadesClear(void) {
    gMainBrightnessFade.mState = 2;
    gMainBrightnessFade.mPositive = 0;
    gMainBrightnessFade.mFadeFrames = 0;
    gMainBrightnessFade.mFadeFrameCount = 0;
    gMainBrightnessFade.mBrightness = 0;
    gSubBrightnessFade.mState = 2;
    gSubBrightnessFade.mPositive = 0;
    gSubBrightnessFade.mFadeFrames = 0;
    gSubBrightnessFade.mFadeFrameCount = 0;
    gSubBrightnessFade.mBrightness = 0;
    GXx_SetMasterBrightness_(&reg_GX_MASTER_BRIGHT, gMainBrightnessFade.mBrightness);
    GXx_SetMasterBrightness_(&reg_GXS_DB_MASTER_BRIGHT, gSubBrightnessFade.mBrightness);
}

u32 AreBrightnessFadesClear(void) {
    if ((gMainBrightnessFade.mState == 2) && (gSubBrightnessFade.mState == 2)) {
        return 1;
    }
    return 0;
}
