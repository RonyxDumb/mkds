#include "Main/Unknown/code_02036c5c.h"

#include "Main/Unknown/code_02039000.h"
#include "Main/Unknown/code_0200e000.h"
#include "Main/Unknown/unk_02175000.h"
#include "code_0200eddc.h"
#include "code_0200f5ac.h"
#include "os_irqHandler.h"
#include "gx.h"
#include "Main/Unknown/code_02039774.h"
#include "code_0214a748.h"
#include "Main/Unknown/code_02038000.h"
#include "code_0214a5e0.h"
#include "Main/Unknown/code_0214d000.h"
#include "code_02148950.h"
#include "code_0214a5f0.h"
#include "code_0214d018.h"
#include "registers.h"
#include "code_0214a390.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/System/Heap.h"

void updateMasterBright(BrightnessFade *fade) {
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

void dc_initMasterBright(void) {
    gTopMasterBright.mState = 0;
    gTopMasterBright.mPositive = 1;
    gTopMasterBright.mFadeFrames = 0;
    gTopMasterBright.mFadeFrameCount = 0;
    gTopMasterBright.mBrightness = 0x10;
    gBottomMasterBright.mState = 0;
    gBottomMasterBright.mPositive = 1;
    gBottomMasterBright.mFadeFrames = 0;
    gBottomMasterBright.mFadeFrameCount = 0;
    gBottomMasterBright.mBrightness = 0x10;
    GXx_SetMasterBrightness_(&reg_GX_MASTER_BRIGHT, gTopMasterBright.mBrightness);
    GXx_SetMasterBrightness_(&reg_GXS_DB_MASTER_BRIGHT, gBottomMasterBright.mBrightness);
}

void dc_enableDisplay(void) {
    OS_WaitIrq(1, 1);
    GX_DispOn();
    reg_GXS_DB_DISPCNT = reg_GXS_DB_DISPCNT | 0x10000;
}

void initializeDisplayConfigBg(void *recordsBase, u32 bgMode) {
    DisplayBgRecords *records = recordsBase;
    u32 bgCntMode;
    records->mBg0CntLow2 = 0;
    records->mBg0CntBit6 = 0;
    records->mBg0CntVal14 = 0;
    records->mBg0CntVal7 = 0;
    records->mBg0CntVal8 = 0;
    records->mBg0CntVal2 = 0;
    records->mBg0CntVal13 = 0;
    records->mBg1CntLow2 = 1;
    records->mBg1CntVal14 = 0;
    records->mBg1CntVal7 = 0;
    records->mBg1CntBit6 = 0;
    records->mBg1CntVal8 = 0;
    records->mBg1CntVal2 = 0;
    records->mBg1CntVal13 = 0;
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
    records->mBg2Mode = bgCntMode;
    switch (bgCntMode) {
        case 1:
            records->mBg2CntLow2 = 2;
            records->mBg2CntVal14 = 0;
            records->field2A = 0;
            records->mBg2CntBit6 = 0;
            records->mBg2CntVal8 = 0;
            records->mBg2CntVal2 = 0;
            break;
        case 2:
            records->mBg2CntLow2 = 2;
            records->mBg2CntVal14 = 0;
            records->mBg2CntBit6 = 0;
            records->field2A = 0;
            records->mBg2CntVal8 = 0;
            records->mBg2CntVal2 = 0;
            break;
        case 3:
            records->mBg2CntLow2 = 2;
            records->mBg2CntBit6 = 0;
            records->mBg2CntVal14 = 0;
            records->field2A = 0;
            records->mBg2CntVal8 = 0;
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
    records->mBg3Mode = bgCntMode;
    switch (bgCntMode) {
        case 1:
            records->mBg3CntLow2 = 2;
            records->mBg3CntVal14 = 0;
            records->field3A = 0;
            records->mBg3CntBit6 = 0;
            records->mBg3CntVal8 = 0;
            records->mBg3CntVal2 = 0;
            break;
        case 2:
            records->mBg3CntLow2 = 2;
            records->mBg3CntVal14 = 0;
            records->mBg3CntBit6 = 0;
            records->field3A = 0;
            records->mBg3CntVal8 = 0;
            records->mBg3CntVal2 = 0;
            break;
        case 3:
            records->mBg3CntLow2 = 2;
            records->mBg3CntBit6 = 0;
            records->mBg3CntVal14 = 0;
            records->field3A = 0;
            records->mBg3CntVal8 = 0;
            break;
    }
    records->field40 = 0;
    records->field42 = 0;
}

void initializeDisplayConfigFromBaseConfig(DisplaySettings *settings, void *descriptorBase) {
    DisplaySettingsDesc *descriptor = descriptorBase;
    *(DisplaySettingsDesc *) settings = *descriptor;
    initializeDisplayConfigBg(&settings->mMainBg0, descriptor->mMainBgMode);
    initializeDisplayConfigBg(&settings->mSubBg0, descriptor->mSubBgMode);
    settings->mG3xParams = NULL;
    settings->mFrameStartTick = 0;
    settings->mWaitEndTick = 0;
    settings->mTimeBeforeWait = 0;
    settings->mTimeSinceWaitEnd = 0;
    settings->mTimeSinceFrameStart = 0;
    settings->fieldB4 = 0;
    settings->mIrqCallback = NULL;
    settings->mFrameFlags = 0;
}

void *dc_createDisplayConfig(void *heap, void *descriptor) {
    DisplaySettings *settings = heap_alloc(heap, 0xdc);
    G3xParams *g3xParams;
    initializeDisplayConfigFromBaseConfig(settings, descriptor);
    if (settings->mBg0As == 1) {
        g3xParams = heap_alloc(heap, 8);
        g3xParams->mClearColor = 0x5000;
        g3xParams->mSwapBit0 = 1;
        g3xParams->mSwapBit1 = 1;
        settings->mG3xParams = g3xParams;
    }
    return settings;
}

void dc_setBg0Config(void *recordsBase, u32 cntLow2, u32 cntBit6, u32 cntVal14, u32 cntVal7, u32 cntVal8, u32 cntVal2,
                  u32 cntVal13) {
    DisplayBgRecords *records = recordsBase;
    records->mBg0CntLow2 = cntLow2;
    records->mBg0CntVal14 = cntVal14;
    records->mBg0CntVal7 = cntVal7;
    records->mBg0CntBit6 = cntBit6;
    records->mBg0CntVal8 = cntVal8;
    records->mBg0CntVal2 = cntVal2;
    records->mBg0CntVal13 = cntVal13;
}

void dc_setBg1Config(void *recordsBase, u32 cntLow2, u32 cntBit6, u32 cntVal14, u32 cntVal7, u32 cntVal8, u32 cntVal2,
                  u32 cntVal13) {
    DisplayBgRecords *records = recordsBase;
    records->mBg1CntLow2 = cntLow2;
    records->mBg1CntVal14 = cntVal14;
    records->mBg1CntVal7 = cntVal7;
    records->mBg1CntBit6 = cntBit6;
    records->mBg1CntVal8 = cntVal8;
    records->mBg1CntVal2 = cntVal2;
    records->mBg1CntVal13 = cntVal13;
}

void dc_setBg2Config(void *recordsBase, u32 cntLow2, u32 cntBit6, u32 cntVal14, u32 e, u32 cntVal8, u32 cntVal2) {
    DisplayBgRecords *records = recordsBase;
    records->mBg2CntLow2 = cntLow2;
    records->mBg2CntBit6 = cntBit6;
    records->mBg2CntVal14 = cntVal14;
    records->field2A = e;
    records->mBg2CntVal8 = cntVal8;
    records->mBg2CntVal2 = cntVal2;
}

void dc_setBg3Config(void *recordsBase, u32 cntLow2, u32 cntBit6, u32 cntVal14, u32 e, u32 cntVal8, u32 cntVal2) {
    DisplayBgRecords *records = recordsBase;
    records->mBg3CntLow2 = cntLow2;
    records->mBg3CntBit6 = cntBit6;
    records->mBg3CntVal14 = cntVal14;
    records->field3A = e;
    records->mBg3CntVal8 = cntVal8;
    records->mBg3CntVal2 = cntVal2;
}

void dc_setBg2ConfigMode5(void *recordsBase, u32 cntLow2, u32 cntBit6, u32 cntVal14, u32 e, u32 cntVal8) {
    DisplayBgRecords *records = recordsBase;
    records->mBg2Mode = 5;
    records->mBg2CntLow2 = cntLow2;
    records->mBg2CntBit6 = cntBit6;
    records->mBg2CntVal14 = cntVal14;
    records->field2A = e;
    records->mBg2CntVal8 = cntVal8;
}

u32 dc_set3DSwapConfig(DisplaySettings *settings, u32 swapBit0, u32 swapBit1) {
    u32 value0 = (u32) settings;
    u32 swapBit0Copy = swapBit0;
    u32 swapBit1Copy = swapBit1;
    u32 g3xParams;
    g3xParams = *(const u32 *) ((value0) + (108));
    settings->mG3xParams->mSwapBit0 = swapBit0Copy;
    value0 = *(const u32 *) ((value0) + (108));
    *(u8 *) ((value0) + (3)) = swapBit1Copy;
    return value0;
}

void dc_setSubObjBmpMode(DisplaySettings *settings, u32 value) {
    settings->fieldB2 = value;
}

// Enum-typed parameters of the inlines below: the original reads their values before the register.
typedef enum { UNK_0203810C_ARG_0 } Unk0203810c_Arg;

// Sets the low two bits of the halfword register r and its bit 6 from the first two halfwords of q.
static inline void func_0203810c_inline(vu16 *cntReg, Bg23CntFields *fields) {
    *cntReg = (*cntReg & ~3) | fields->mBgCntLow2;
    if (fields->mBgCntBit6 != 0) {
        *cntReg |= 0x40;
    } else {
        *cntReg &= ~0x40;
    }
}

// Keeps bits 0, 1 and 6 of the halfword register r and sets the rest from four values.
static inline void func_0203810c_inline2(vu16 *cntReg, Unk0203810c_Arg val14, Unk0203810c_Arg val7,
                                         Unk0203810c_Arg val8, Unk0203810c_Arg val2) {
    *cntReg = (*cntReg & 0x43) | (val14 << 14) | (val7 << 7) | (val8 << 8) | (val2 << 2);
}

// Keeps bits 0, 1 and 6 of the halfword register r and sets the rest from four values.
static inline void func_0203810c_inline3(vu16 *cntReg, Unk0203810c_Arg val14, Unk0203810c_Arg val8,
                                         Unk0203810c_Arg val2, Unk0203810c_Arg val13) {
    *cntReg = (*cntReg & 0x43) | (val14 << 14) | (val8 << 8) | (val2 << 2) | (val13 << 13);
}

// Keeps bits 0, 1 and 6 of the halfword register r and sets the rest from three values.
static inline void func_0203810c_inline4(vu16 *cntReg, Unk0203810c_Arg val14, Unk0203810c_Arg val13,
                                         Unk0203810c_Arg val8) {
    *cntReg = (*cntReg & 0x43) | (val14 << 14) | (val8 << 8) | (val13 << 13);
}

// Keeps bits 0, 1 and 6 of the halfword register r, sets bit 7 and the rest from three values.
static inline void func_0203810c_inline5(vu16 *cntReg, Unk0203810c_Arg val14, Unk0203810c_Arg val13,
                                         Unk0203810c_Arg val8) {
    *cntReg = (*cntReg & 0x43) | (val14 << 14) | 0x80 | (val8 << 8) | (val13 << 13);
}

// Keeps bits 0, 1 and 6 of the halfword register r, sets bits 2 and 7 and the rest from three values.
static inline void func_0203810c_inline6(vu16 *cntReg, Unk0203810c_Arg val14, Unk0203810c_Arg val13,
                                         Unk0203810c_Arg val8) {
    *cntReg = (*cntReg & 0x43) | (val14 << 14) | 0x84 | (val8 << 8) | (val13 << 13);
}

// Sets the low two bits of the halfword register r and its bit 6 from the first two halfwords of q.
static inline void func_020386d0_inline(vu16 *cntReg, Bg23CntFields *fields) {
    *cntReg = (*cntReg & ~3) | fields->mBgCntLow2;
    if (fields->mBgCntBit6 != 0) {
        *cntReg |= 0x40;
    } else {
        *cntReg &= ~0x40;
    }
}

// Keeps bits 0, 1 and 6 of the halfword register r and sets the rest from four values.
static inline void func_020386d0_inline2(vu16 *cntReg, Unk0203810c_Arg val14, Unk0203810c_Arg val7,
                                         Unk0203810c_Arg val8, Unk0203810c_Arg val2) {
    *cntReg = (*cntReg & 0x43) | (val14 << 14) | (val7 << 7) | (val8 << 8) | (val2 << 2);
}

// Keeps bits 0, 1 and 6 of the halfword register r and sets the rest from four values.
static inline void func_020386d0_inline3(vu16 *cntReg, Unk0203810c_Arg val14, Unk0203810c_Arg val8,
                                         Unk0203810c_Arg val2, Unk0203810c_Arg val13) {
    *cntReg = (*cntReg & 0x43) | (val14 << 14) | (val8 << 8) | (val2 << 2) | (val13 << 13);
}

// Keeps bits 0, 1 and 6 of the halfword register r and sets the rest from three values.
static inline void func_020386d0_inline4(vu16 *cntReg, Unk0203810c_Arg val14, Unk0203810c_Arg val13,
                                         Unk0203810c_Arg val8) {
    *cntReg = (*cntReg & 0x43) | (val14 << 14) | (val8 << 8) | (val13 << 13);
}

// Keeps bits 0, 1 and 6 of the halfword register r, sets bit 7 and the rest from three values.
static inline void func_020386d0_inline5(vu16 *cntReg, Unk0203810c_Arg val14, Unk0203810c_Arg val13,
                                         Unk0203810c_Arg val8) {
    *cntReg = (*cntReg & 0x43) | (val14 << 14) | 0x80 | (val8 << 8) | (val13 << 13);
}

// Keeps bits 0, 1 and 6 of the halfword register r, sets bits 2 and 7 and the rest from three values.
static inline void func_020386d0_inline6(vu16 *cntReg, Unk0203810c_Arg val14, Unk0203810c_Arg val13,
                                         Unk0203810c_Arg val8) {
    *cntReg = (*cntReg & 0x43) | (val14 << 14) | 0x84 | (val8 << 8) | (val13 << 13);
}

void setupBg2(Bg23Cnt *cnt, s32 isMainScreen) {
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
                func_020386d0_inline(&reg_G2_BG2CNT, fields);
                func_020386d0_inline2(&reg_G2_BG2CNT, (Unk0203810c_Arg) fields->mBgCntVal14,
                                      (Unk0203810c_Arg) fields->field6, (Unk0203810c_Arg) fields->mBgCntVal8,
                                      (Unk0203810c_Arg) fields->mBgCntVal2);
            } else {
                reg_G2S_DB_BG2OFS = 0;
                func_020386d0_inline(&reg_G2S_DB_BG2CNT, fields);
                func_020386d0_inline2(&reg_G2S_DB_BG2CNT, (Unk0203810c_Arg) fields->mBgCntVal14,
                                      (Unk0203810c_Arg) fields->field6, (Unk0203810c_Arg) fields->mBgCntVal8,
                                      (Unk0203810c_Arg) fields->mBgCntVal2);
            }
            break;
        case 2:
            if (isMainScreen != 0) {
                G2x_SetBGyAffine_(&reg_G2_BG2PA, matrix, 0, 0, 0, 0);
                func_020386d0_inline(&reg_G2_BG2CNT, fields);
                func_020386d0_inline3(&reg_G2_BG2CNT, (Unk0203810c_Arg) fields->mBgCntVal14,
                                      (Unk0203810c_Arg) fields->mBgCntVal8, (Unk0203810c_Arg) fields->mBgCntVal2,
                                      (Unk0203810c_Arg) fields->field6);
            } else {
                G2x_SetBGyAffine_(&reg_G2S_DB_BG2PA, matrix, 0, 0, 0, 0);
                func_020386d0_inline(&reg_G2S_DB_BG2CNT, fields);
                func_020386d0_inline3(&reg_G2S_DB_BG2CNT, (Unk0203810c_Arg) fields->mBgCntVal14,
                                      (Unk0203810c_Arg) fields->mBgCntVal8, (Unk0203810c_Arg) fields->mBgCntVal2,
                                      (Unk0203810c_Arg) fields->field6);
            }
            break;
        case 3:
            if (isMainScreen != 0) {
                G2x_SetBGyAffine_(&reg_G2_BG2PA, matrix, 0, 0, 0, 0);
                func_020386d0_inline(&reg_G2_BG2CNT, fields);
                func_020386d0_inline4(&reg_G2_BG2CNT, (Unk0203810c_Arg) fields->mBgCntVal14,
                                      (Unk0203810c_Arg) fields->field6, (Unk0203810c_Arg) fields->mBgCntVal8);
            } else {
                G2x_SetBGyAffine_(&reg_G2S_DB_BG2PA, matrix, 0, 0, 0, 0);
                func_020386d0_inline(&reg_G2S_DB_BG2CNT, fields);
                func_020386d0_inline4(&reg_G2S_DB_BG2CNT, (Unk0203810c_Arg) fields->mBgCntVal14,
                                      (Unk0203810c_Arg) fields->field6, (Unk0203810c_Arg) fields->mBgCntVal8);
            }
            break;
        case 4:
            if (isMainScreen != 0) {
                G2x_SetBGyAffine_(&reg_G2_BG2PA, matrix, 0, 0, 0, 0);
                func_020386d0_inline(&reg_G2_BG2CNT, fields);
                func_020386d0_inline5(&reg_G2_BG2CNT, (Unk0203810c_Arg) fields->mBgCntVal14,
                                      (Unk0203810c_Arg) fields->field6, (Unk0203810c_Arg) fields->mBgCntVal8);
            } else {
                G2x_SetBGyAffine_(&reg_G2S_DB_BG2PA, matrix, 0, 0, 0, 0);
                func_020386d0_inline(&reg_G2S_DB_BG2CNT, fields);
                func_020386d0_inline5(&reg_G2S_DB_BG2CNT, (Unk0203810c_Arg) fields->mBgCntVal14,
                                      (Unk0203810c_Arg) fields->field6, (Unk0203810c_Arg) fields->mBgCntVal8);
            }
            break;
        case 5:
            if (isMainScreen != 0) {
                G2x_SetBGyAffine_(&reg_G2_BG2PA, matrix, 0, 0, 0, 0);
                func_020386d0_inline(&reg_G2_BG2CNT, fields);
                func_020386d0_inline6(&reg_G2_BG2CNT, (Unk0203810c_Arg) fields->mBgCntVal14,
                                      (Unk0203810c_Arg) fields->field6, (Unk0203810c_Arg) fields->mBgCntVal8);
            } else {
                G2x_SetBGyAffine_(&reg_G2S_DB_BG2PA, matrix, 0, 0, 0, 0);
                func_020386d0_inline(&reg_G2S_DB_BG2CNT, fields);
                func_020386d0_inline6(&reg_G2S_DB_BG2CNT, (Unk0203810c_Arg) fields->mBgCntVal14,
                                      (Unk0203810c_Arg) fields->field6, (Unk0203810c_Arg) fields->mBgCntVal8);
            }
            break;
        default:
            break;
    }
}

void setupBg3(Bg23Cnt *cnt, s32 isMainScreen) {
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
                func_0203810c_inline(&reg_G2_BG3CNT, fields);
                func_0203810c_inline2(&reg_G2_BG3CNT, (Unk0203810c_Arg) fields->mBgCntVal14,
                                      (Unk0203810c_Arg) fields->field6, (Unk0203810c_Arg) fields->mBgCntVal8,
                                      (Unk0203810c_Arg) fields->mBgCntVal2);
            } else {
                reg_G2S_DB_BG3OFS = 0;
                func_0203810c_inline(&reg_G2S_DB_BG3CNT, fields);
                func_0203810c_inline2(&reg_G2S_DB_BG3CNT, (Unk0203810c_Arg) fields->mBgCntVal14,
                                      (Unk0203810c_Arg) fields->field6, (Unk0203810c_Arg) fields->mBgCntVal8,
                                      (Unk0203810c_Arg) fields->mBgCntVal2);
            }
            break;
        case 2:
            if (isMainScreen != 0) {
                G2x_SetBGyAffine_(&reg_G2_BG3PA, matrix, 0, 0, 0, 0);
                func_0203810c_inline(&reg_G2_BG3CNT, fields);
                func_0203810c_inline3(&reg_G2_BG3CNT, (Unk0203810c_Arg) fields->mBgCntVal14,
                                      (Unk0203810c_Arg) fields->mBgCntVal8, (Unk0203810c_Arg) fields->mBgCntVal2,
                                      (Unk0203810c_Arg) fields->field6);
            } else {
                G2x_SetBGyAffine_(&reg_G2S_DB_BG3PA, matrix, 0, 0, 0, 0);
                func_0203810c_inline(&reg_G2S_DB_BG3CNT, fields);
                func_0203810c_inline3(&reg_G2S_DB_BG3CNT, (Unk0203810c_Arg) fields->mBgCntVal14,
                                      (Unk0203810c_Arg) fields->mBgCntVal8, (Unk0203810c_Arg) fields->mBgCntVal2,
                                      (Unk0203810c_Arg) fields->field6);
            }
            break;
        case 3:
            if (isMainScreen != 0) {
                G2x_SetBGyAffine_(&reg_G2_BG3PA, matrix, 0, 0, 0, 0);
                func_0203810c_inline(&reg_G2_BG3CNT, fields);
                func_0203810c_inline4(&reg_G2_BG3CNT, (Unk0203810c_Arg) fields->mBgCntVal14,
                                      (Unk0203810c_Arg) fields->field6, (Unk0203810c_Arg) fields->mBgCntVal8);
            } else {
                G2x_SetBGyAffine_(&reg_G2S_DB_BG3PA, matrix, 0, 0, 0, 0);
                func_0203810c_inline(&reg_G2S_DB_BG3CNT, fields);
                func_0203810c_inline4(&reg_G2S_DB_BG3CNT, (Unk0203810c_Arg) fields->mBgCntVal14,
                                      (Unk0203810c_Arg) fields->field6, (Unk0203810c_Arg) fields->mBgCntVal8);
            }
            break;
        case 4:
            if (isMainScreen != 0) {
                G2x_SetBGyAffine_(&reg_G2_BG3PA, matrix, 0, 0, 0, 0);
                func_0203810c_inline(&reg_G2_BG3CNT, fields);
                func_0203810c_inline5(&reg_G2_BG3CNT, (Unk0203810c_Arg) fields->mBgCntVal14,
                                      (Unk0203810c_Arg) fields->field6, (Unk0203810c_Arg) fields->mBgCntVal8);
            } else {
                G2x_SetBGyAffine_(&reg_G2S_DB_BG3PA, matrix, 0, 0, 0, 0);
                func_0203810c_inline(&reg_G2S_DB_BG3CNT, fields);
                func_0203810c_inline5(&reg_G2S_DB_BG3CNT, (Unk0203810c_Arg) fields->mBgCntVal14,
                                      (Unk0203810c_Arg) fields->field6, (Unk0203810c_Arg) fields->mBgCntVal8);
            }
            break;
        case 5:
            if (isMainScreen != 0) {
                G2x_SetBGyAffine_(&reg_G2_BG3PA, matrix, 0, 0, 0, 0);
                func_0203810c_inline(&reg_G2_BG3CNT, fields);
                func_0203810c_inline6(&reg_G2_BG3CNT, (Unk0203810c_Arg) fields->mBgCntVal14,
                                      (Unk0203810c_Arg) fields->field6, (Unk0203810c_Arg) fields->mBgCntVal8);
            } else {
                G2x_SetBGyAffine_(&reg_G2S_DB_BG3PA, matrix, 0, 0, 0, 0);
                func_0203810c_inline(&reg_G2S_DB_BG3CNT, fields);
                func_0203810c_inline6(&reg_G2S_DB_BG3CNT, (Unk0203810c_Arg) fields->mBgCntVal14,
                                      (Unk0203810c_Arg) fields->field6, (Unk0203810c_Arg) fields->mBgCntVal8);
            }
            break;
        default:
            break;
    }
}

// Enum-typed parameters of the inlines below: the original reads their values before the register.
typedef enum { UNK_02037ABC_ARG_0 } Unk02037abc_Arg;

// Calls MIi_CpuClearFast with v, passed through a stack offset of its own.
static inline void func_02037abc_inline(u32 fillValue, void *destination, u32 size) {
    volatile u32 fillValueCopy = fillValue;
    MIi_CpuClearFast(fillValueCopy, destination, size);
}

// Sets the low two bits of the halfword register r and its bit 6 from the first two halfwords of q.
static inline void func_02037abc_inline2(vu16 *cntReg, Bg01Cnt *cnt) {
    *cntReg = (*cntReg & ~3) | cnt->mBgCntLow2;
    if (cnt->mBgCntBit6 != 0) {
        *cntReg |= 0x40;
    } else {
        *cntReg &= ~0x40;
    }
}

// Sets bits 4, 20 and 21 of the word register r.
static inline void func_02037abc_inline3(vu32 *reg, Unk02037abc_Arg bits) {
    *reg = (*reg & 0xffcfffef) | bits;
}

// Sets bits 5, 6 and 22 of the word at 0x04000000.
static inline void func_02037abc_inline4(Unk02037abc_Arg bits) {
    reg_GX_DISPCNT = (reg_GX_DISPCNT & 0xffbfff9f) | bits;
}

// Sets bits 5 and 6 of the word at 0x04001000.
static inline void func_02037abc_inline5(Unk02037abc_Arg bits) {
    reg_GXS_DB_DISPCNT = (reg_GXS_DB_DISPCNT & ~0x60) | bits;
}

// Keeps bits 0, 1 and 6 of the halfword register r and sets the rest from five values.
static inline void func_02037abc_inline6(vu16 *cntReg, Unk02037abc_Arg val14, Unk02037abc_Arg val7,
                                         Unk02037abc_Arg val8, Unk02037abc_Arg val2, Unk02037abc_Arg val13) {
    *cntReg = (*cntReg & 0x43) | (val14 << 14) | (val7 << 7) | (val8 << 8) | (val2 << 2) | (val13 << 13);
}

void dc_setDisplayConfig(void *settingsPtr) {
    DisplaySettings *settings;
    Bg01Cnt *cnt;
    u16 clearColor;

    settings = settingsPtr;
    gCurDisplayConfig = settings;
    vram_clearDisableAll();
    func_02037abc_inline(0xc0, (void *) 0x07000000, 0x400);
    func_02037abc_inline(0xc0, (void *) 0x07000400, 0x400);
    func_02037abc_inline(0, (void *) 0x05000000, 0x400);
    func_02037abc_inline(0, (void *) 0x05000400, 0x400);
    if (gCurDisplayConfig->mBankForBG != 0) {
        GX_SetBankForBG(gCurDisplayConfig->mBankForBG);
    }
    if (gCurDisplayConfig->mBankForOBJ != 0) {
        GX_SetBankForOBJ(gCurDisplayConfig->mBankForOBJ);
    }
    if (gCurDisplayConfig->mBankForBGExtPltt != 0) {
        GX_SetBankForBGExtPltt(gCurDisplayConfig->mBankForBGExtPltt);
    }
    if (gCurDisplayConfig->mBankForOBJExtPltt != 0) {
        GX_SetBankForOBJExtPltt(gCurDisplayConfig->mBankForOBJExtPltt);
    }
    if (gCurDisplayConfig->mBankForTex != 0) {
        GX_SetBankForTex(gCurDisplayConfig->mBankForTex);
    }
    if (gCurDisplayConfig->mBankForTexPltt != 0) {
        GX_SetBankForTexPltt(gCurDisplayConfig->mBankForTexPltt);
    }
    if (gCurDisplayConfig->mBankForClearImage != 0) {
        GX_SetBankForClearImage(gCurDisplayConfig->mBankForClearImage);
    }
    if (gCurDisplayConfig->mBankForSubBG != 0) {
        GX_SetBankForSubBG(gCurDisplayConfig->mBankForSubBG);
    }
    if (gCurDisplayConfig->mBankForSubOBJ != 0) {
        GX_SetBankForSubOBJ(gCurDisplayConfig->mBankForSubOBJ);
    }
    if (gCurDisplayConfig->mBankForSubBGExtPltt != 0) {
        GX_SetBankForSubBGExtPltt(gCurDisplayConfig->mBankForSubBGExtPltt);
    }
    if (gCurDisplayConfig->mBankForSubOBJExtPltt != 0) {
        GX_SetBankForSubOBJExtPltt(gCurDisplayConfig->mBankForSubOBJExtPltt);
    }
    if (gCurDisplayConfig->mBankForARM7 != 0) {
        vram_setBankForARM7(gCurDisplayConfig->mBankForARM7);
    }
    if (gCurDisplayConfig->mBankForLCDC != 0) {
        GX_SetBankForLCDC(gCurDisplayConfig->mBankForLCDC);
    }
    gVramWvrStatus.field0;
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
        cnt = &settings->mMainBg0;
        func_02037abc_inline2(&reg_G2_BG0CNT, cnt);
        if (settings->mBg0As == 1) {
            G3X_SetHOffset(0);
        } else {
            reg_G2_BG0OFS = 0;
            func_02037abc_inline6(&reg_G2_BG0CNT, (Unk02037abc_Arg) cnt->mBgCntVal14, (Unk02037abc_Arg) cnt->mBgCntVal7,
                                  (Unk02037abc_Arg) cnt->mBgCntVal8, (Unk02037abc_Arg) cnt->mBgCntVal2,
                                  (Unk02037abc_Arg) cnt->mBgCntVal13);
        }
    }
    if (settings->mSubDisplayMask & 1) {
        reg_G2S_DB_BG0OFS = 0;
        cnt = &settings->mSubBg0;
        func_02037abc_inline2(&reg_G2S_DB_BG0CNT, cnt);
        func_02037abc_inline6(&reg_G2S_DB_BG0CNT, (Unk02037abc_Arg) cnt->mBgCntVal14, (Unk02037abc_Arg) cnt->mBgCntVal7,
                              (Unk02037abc_Arg) cnt->mBgCntVal8, (Unk02037abc_Arg) cnt->mBgCntVal2,
                              (Unk02037abc_Arg) cnt->mBgCntVal13);
    }
    if (settings->mMainDisplayMask & 2) {
        reg_G2_BG1OFS = 0;
        cnt = &settings->mMainBg1;
        func_02037abc_inline2(&reg_G2_BG1CNT, cnt);
        func_02037abc_inline6(&reg_G2_BG1CNT, (Unk02037abc_Arg) cnt->mBgCntVal14, (Unk02037abc_Arg) cnt->mBgCntVal7,
                              (Unk02037abc_Arg) cnt->mBgCntVal8, (Unk02037abc_Arg) cnt->mBgCntVal2,
                              (Unk02037abc_Arg) cnt->mBgCntVal13);
    }
    if (settings->mSubDisplayMask & 2) {
        reg_G2S_DB_BG1OFS = 0;
        cnt = &settings->mSubBg1;
        func_02037abc_inline2(&reg_G2S_DB_BG1CNT, cnt);
        func_02037abc_inline6(&reg_G2S_DB_BG1CNT, (Unk02037abc_Arg) cnt->mBgCntVal14, (Unk02037abc_Arg) cnt->mBgCntVal7,
                              (Unk02037abc_Arg) cnt->mBgCntVal8, (Unk02037abc_Arg) cnt->mBgCntVal2,
                              (Unk02037abc_Arg) cnt->mBgCntVal13);
    }
    if (settings->mMainDisplayMask & 4) {
        setupBg2(&settings->mMainBg2, 1);
    }
    if (settings->mSubDisplayMask & 4) {
        setupBg2(&settings->mSubBg2, 0);
    }
    if (settings->mMainDisplayMask & 8) {
        setupBg3(&settings->mMainBg3, 1);
    }
    if (settings->mSubDisplayMask & 8) {
        setupBg3(&settings->mSubBg3, 0);
    }
    if (settings->mMainDisplayMask & 0x10) {
        func_02037abc_inline3(&reg_GX_DISPCNT, (Unk02037abc_Arg) settings->field68);
        func_02037abc_inline4((Unk02037abc_Arg) settings->field6A);
    }
    if (settings->mSubDisplayMask & 0x10) {
        func_02037abc_inline3(&reg_GXS_DB_DISPCNT, (Unk02037abc_Arg) settings->fieldB0);
        func_02037abc_inline5((Unk02037abc_Arg) settings->fieldB2);
    }
    reg_GX_POWCNT |= 0x8000;
}

void dc_unsetDisplayConfig(void) {
    vram_disableAll();
    gCurDisplayConfig = NULL;
}

void dc_handleStartOfFrame(void) {
    DisplaySettings *settings;
    u64 tick;
    settings = gCurDisplayConfig;
    tick = OS_GetTick();
    settings->mFrameStartTick = tick;
    if (settings->mBg0As == 1) {
        G3X_Reset();
    }
    if (gFrameCallback != NULL) {
        gFrameCallback(0);
    }
}

u32 dc_getFlagsBit1(void) {
    return (gCurDisplayConfig->mFrameFlags & 2) ? 1 : 0;
}

u32 dc_clearFlagsBit0(void) {
    u32 value0;
    u32 settings;
    value0 = (u32) &gCurDisplayConfig;
    settings = *(const u32 *) ((value0) + (0));
    value0 = gCurDisplayConfig->mFrameFlags;
    value0 = (value0) & ~(1u);
    gCurDisplayConfig->mFrameFlags = value0;
    return value0;
}

static inline void func_02036d3c_inline(BrightnessFade *fade, s16 frameCount) {
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

static inline void func_02036f10_inline(BrightnessFade *fade, s16 frameCount) {
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

static inline void func_020370d4_inline(BrightnessFade *fade, s16 frameCount) {
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

static inline void func_02037288_inline(BrightnessFade *fade, s16 frameCount) {
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

void dc_2037850(void) {
    DisplaySettings *settings;
    u64 tick;
    s16 prevMainBrightness;
    s16 prevSubBrightness;
    u16 i;
    prevMainBrightness = gTopMasterBright.mBrightness;
    prevSubBrightness = gBottomMasterBright.mBrightness;
    if (gFrameCallback != NULL) {
        gFrameCallback(1);
    }
    updateMasterBright(&gTopMasterBright);
    updateMasterBright(&gBottomMasterBright);
    DC_StoreAll();
    settings = gCurDisplayConfig;
    if (settings->mBg0As == 1) {
        reg_G3_SWAP_BUFFERS = (settings->mG3xParams->mSwapBit1 << 1) | settings->mG3xParams->mSwapBit0;
    }
    if ((gCurDisplayConfig->mFrameFlags & 1) == 0) {
        gCurDisplayConfig->mFrameFlags |= 2;
    } else {
        gCurDisplayConfig->mFrameFlags &= ~2;
        gCurDisplayConfig->mFrameFlags &= ~1;
    }
    settings = gCurDisplayConfig;
    tick = OS_GetTick();
    settings->mTimeBeforeWait = (tick - settings->mFrameStartTick) * 0xfa00 / 0x82ea;
    for (i = 0; i < gCurDisplayConfig->mWaitIrqCount; i++) {
        OS_WaitIrq(1, 1);
    }
    gCurDisplayConfig->mFrameFlags |= 1;
    gCurDisplayConfig->mWaitEndTick = OS_GetTick();
    if (prevMainBrightness != gTopMasterBright.mBrightness) {
        GXx_SetMasterBrightness_(&reg_GX_MASTER_BRIGHT, gTopMasterBright.mBrightness);
    }
    if (prevSubBrightness != gBottomMasterBright.mBrightness) {
        GXx_SetMasterBrightness_(&reg_GXS_DB_MASTER_BRIGHT, gBottomMasterBright.mBrightness);
    }
    if (gFrameCallback != NULL) {
        gFrameCallback(2);
    }
}

void dc_2037658(s32 a) {
    u64 tick;
    s16 prevMainBrightness;
    s16 prevSubBrightness;
    u16 i;
    BOOL swapAndWait;
    DisplaySettings *settings;
    prevMainBrightness = gTopMasterBright.mBrightness;
    prevSubBrightness = gBottomMasterBright.mBrightness;
    if (gFrameCallback != NULL) {
        gFrameCallback(1);
    }
    updateMasterBright(&gTopMasterBright);
    updateMasterBright(&gBottomMasterBright);
    DC_StoreAll();
    if ((gCurDisplayConfig->mFrameFlags & 1) == 0) {
        gCurDisplayConfig->mFrameFlags |= 2;
    } else {
        gCurDisplayConfig->mFrameFlags &= ~2;
        gCurDisplayConfig->mFrameFlags &= ~1;
    }
    if (a == 0 || (gCurDisplayConfig->mFrameFlags & 2) == 0) {
        swapAndWait = TRUE;
    } else {
        swapAndWait = FALSE;
    }
    settings = gCurDisplayConfig;
    if (settings->mBg0As == 1 && swapAndWait != FALSE) {
        reg_G3_SWAP_BUFFERS = (settings->mG3xParams->mSwapBit1 << 1) | settings->mG3xParams->mSwapBit0;
    }
    settings = gCurDisplayConfig;
    tick = OS_GetTick();
    settings->mTimeBeforeWait = (tick - settings->mFrameStartTick) * 0xfa00 / 0x82ea;
    if (swapAndWait != FALSE) {
        for (i = 0; i < gCurDisplayConfig->mWaitIrqCount; i++) {
            OS_WaitIrq(1, 1);
        }
    }
    gCurDisplayConfig->mFrameFlags |= 1;
    gCurDisplayConfig->mWaitEndTick = OS_GetTick();
    if (prevMainBrightness != gTopMasterBright.mBrightness) {
        GXx_SetMasterBrightness_(&reg_GX_MASTER_BRIGHT, gTopMasterBright.mBrightness);
    }
    if (prevSubBrightness != gBottomMasterBright.mBrightness) {
        GXx_SetMasterBrightness_(&reg_GXS_DB_MASTER_BRIGHT, gBottomMasterBright.mBrightness);
    }
    if (gFrameCallback != NULL) {
        gFrameCallback(2);
    }
}

void dc_2037498(s32 doSwap) {
    DisplaySettings *settings;
    u64 tick;
    s16 prevMainBrightness;
    s16 prevSubBrightness;
    u16 i;
    prevMainBrightness = gTopMasterBright.mBrightness;
    prevSubBrightness = gBottomMasterBright.mBrightness;
    if (gFrameCallback != NULL) {
        gFrameCallback(1);
    }
    updateMasterBright(&gTopMasterBright);
    updateMasterBright(&gBottomMasterBright);
    DC_StoreAll();
    if ((gCurDisplayConfig->mFrameFlags & 1) == 0) {
        gCurDisplayConfig->mFrameFlags |= 2;
    } else {
        gCurDisplayConfig->mFrameFlags &= ~2;
        gCurDisplayConfig->mFrameFlags &= ~1;
    }
    settings = gCurDisplayConfig;
    if (settings->mBg0As == 1 && doSwap != 0) {
        reg_G3_SWAP_BUFFERS = (settings->mG3xParams->mSwapBit1 << 1) | settings->mG3xParams->mSwapBit0;
    }
    settings = gCurDisplayConfig;
    tick = OS_GetTick();
    settings->mTimeBeforeWait = (tick - settings->mFrameStartTick) * 0xfa00 / 0x82ea;
    for (i = 0; i < gCurDisplayConfig->mWaitIrqCount; i++) {
        OS_WaitIrq(1, 1);
    }
    gCurDisplayConfig->mFrameFlags |= 1;
    gCurDisplayConfig->mWaitEndTick = OS_GetTick();
    if (prevMainBrightness != gTopMasterBright.mBrightness) {
        GXx_SetMasterBrightness_(&reg_GX_MASTER_BRIGHT, gTopMasterBright.mBrightness);
    }
    if (prevSubBrightness != gBottomMasterBright.mBrightness) {
        GXx_SetMasterBrightness_(&reg_GXS_DB_MASTER_BRIGHT, gBottomMasterBright.mBrightness);
    }
    if (gFrameCallback != NULL) {
        gFrameCallback(2);
    }
}

void dc_handleEndOfFrame(void) {
    u64 tick;
    DisplaySettings *settings;
    tick = OS_GetTick();
    if (gFrameCallback != NULL) {
        gFrameCallback(3);
    }
    settings = gCurDisplayConfig;
    settings->mTimeSinceWaitEnd = (tick - settings->mWaitEndTick) * 0xfa00 / 0x82ea;
    settings = gCurDisplayConfig;
    settings->mTimeSinceFrameStart = (tick - settings->mFrameStartTick) * 0xfa00 / 0x82ea;
}

void StartFadeToClearOneScreen(s16 frameCount, s32 isMainScreen) {
    if (isMainScreen != 0) {
        func_02037288_inline(&gTopMasterBright, frameCount);
    } else {
        func_02037288_inline(&gBottomMasterBright, frameCount);
    }
}

void mbright_fadeIn(s16 frameCount) {
    func_02037288_inline(&gTopMasterBright, frameCount);
    func_02037288_inline(&gBottomMasterBright, frameCount);
}

void mbright_fadeToBlackSingle(s32 frameCount, s32 isMainScreen) {
    if (isMainScreen != 0) {
        func_020370d4_inline(&gTopMasterBright, frameCount);
    } else {
        func_020370d4_inline(&gBottomMasterBright, frameCount);
    }
}

void StartFadeToClearNegative(s16 frameCount) {
    func_020370d4_inline(&gTopMasterBright, frameCount);
    func_020370d4_inline(&gBottomMasterBright, frameCount);
}

void mbright_fadeFromBlackSingle(s32 frameCount, s32 isMainScreen) {
    if (isMainScreen != 0) {
        func_02036f10_inline(&gTopMasterBright, frameCount);
    } else {
        func_02036f10_inline(&gBottomMasterBright, frameCount);
    }
}

void mbright_fadeToBlack(s16 frameCount) {
    func_02036f10_inline(&gTopMasterBright, frameCount);
    func_02036f10_inline(&gBottomMasterBright, frameCount);
}

void StartFadeToFadedPositiveOneScreen(s16 frameCount, s32 isMainScreen) {
    if (isMainScreen != 0) {
        func_02036d3c_inline(&gTopMasterBright, frameCount);
    } else {
        func_02036d3c_inline(&gBottomMasterBright, frameCount);
    }
}

void mbright_fadeToWhite(s16 frameCount) {
    func_02036d3c_inline(&gTopMasterBright, frameCount);
    func_02036d3c_inline(&gBottomMasterBright, frameCount);
}

u32 mbright_isFadedOut(void) {
    if (gTopMasterBright.mState == 0 && gBottomMasterBright.mState == 0) {
        return 1;
    }
    return 0;
}

void SetBrightnessFadesClear(void) {
    gTopMasterBright.mState = 2;
    gTopMasterBright.mPositive = 0;
    gTopMasterBright.mFadeFrames = 0;
    gTopMasterBright.mFadeFrameCount = 0;
    gTopMasterBright.mBrightness = 0;
    gBottomMasterBright.mState = 2;
    gBottomMasterBright.mPositive = 0;
    gBottomMasterBright.mFadeFrames = 0;
    gBottomMasterBright.mFadeFrameCount = 0;
    gBottomMasterBright.mBrightness = 0;
    GXx_SetMasterBrightness_(&reg_GX_MASTER_BRIGHT, gTopMasterBright.mBrightness);
    GXx_SetMasterBrightness_(&reg_GXS_DB_MASTER_BRIGHT, gBottomMasterBright.mBrightness);
}

u32 mbright_isFadedIn(void) {
    if ((gTopMasterBright.mState == 2) && (gBottomMasterBright.mState == 2)) {
        return 1;
    }
    return 0;
}
