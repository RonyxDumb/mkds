#include "Main/Scene/display_settings.h"
#include "01/Menu/emblem_state_and_lld.h"
#include "thread_scheduler.h"
#include "Main/Scene/scene_display_archive_work.h"
#include "archive_memory_load.h"
#include "heap_frame_allocator.h"
#include "Main/MapObjects/map_object_park.h"
#include "power_management_commands.h"
#include "Main/Sound/sound_init_scene_sounds_and_screen_seqs.h"
#include "arena_cache_init.h"
#include "tick_counter.h"
#include "irq_wait_handler.h"
#include "fixed_point_graphics_setup.h"
#include "Main/System/wireless_vram_state.h"
#include "geometry_engine_setup.h"
#include "geometry_render_state.h"
#include "vram_bank_display_setup.h"
#include "cpu_copy_fill.h"
#include "registers.h"
#include "display_blend_affine_setup.h"
#include "Main/System/heap.h"
#include "Main/System/startup.h"
#include "Main/Scene/scene_run_forever.h"

void (*gFrameCallback)(s32);
BrightnessFade gMainBrightnessFade;
BrightnessFade gSubBrightnessFade;

void InitDisplaySettingsDesc(DisplaySettingsDesc *displaySettingsDesc) {
    displaySettingsDesc->mWaitIrqCount = 0x1u;
    displaySettingsDesc->mMainDisplayMask = 0x0u;
    displaySettingsDesc->mSubDisplayMask = 0x0u;
    displaySettingsDesc->mDispMode = 0x1u;
    displaySettingsDesc->mMainBgMode = GX_BGMODE_0;
    displaySettingsDesc->mBg0As = 0x0u;
    displaySettingsDesc->mSubBgMode = GX_BGMODE_0;
    displaySettingsDesc->mBankForBG = 0x0u;
    displaySettingsDesc->mBankForOBJ = 0x0u;
    displaySettingsDesc->mBankForBGExtPltt = 0x0u;
    displaySettingsDesc->mBankForOBJExtPltt = 0x0u;
    displaySettingsDesc->mBankForTex = 0x0u;
    displaySettingsDesc->mBankForTexPltt = 0x0u;
    displaySettingsDesc->mBankForClearImage = 0x0u;
    displaySettingsDesc->mBankForSubBG = 0x0u;
    displaySettingsDesc->mBankForSubOBJ = 0x0u;
    displaySettingsDesc->mBankForSubBGExtPltt = 0x0u;
    displaySettingsDesc->mBankForSubOBJExtPltt = 0x0u;
    displaySettingsDesc->mBankForARM7 = 0x0u;
    displaySettingsDesc->mBankForLCDC = 0x0u;
}

void UpdateBrightnessFade(BrightnessFade *fade) {
    switch (fade->mState) {
        case BRIGHTNESS_FADE_FADED:
            break;
        case BRIGHTNESS_FADE_TO_CLEAR:
            fade->mFadeFrames++;
            if (fade->mFadeFrames >= fade->mFadeFrameCount) {
                fade->mState = BRIGHTNESS_FADE_CLEAR;
                fade->mBrightness = BRIGHTNESS_LEVEL_CLEAR;
            } else {
                fade->mBrightness = BRIGHTNESS_LEVEL_FADED - (fade->mFadeFrames << 4) / fade->mFadeFrameCount;
            }
            if (fade->mPositive == FALSE) {
                fade->mBrightness = -fade->mBrightness;
            }
            break;
        case BRIGHTNESS_FADE_CLEAR:
            fade->mBrightness = BRIGHTNESS_LEVEL_CLEAR;
            break;
        case BRIGHTNESS_FADE_TO_FADED:
            fade->mFadeFrames++;
            if (fade->mFadeFrames >= fade->mFadeFrameCount) {
                fade->mState = BRIGHTNESS_FADE_FADED;
                fade->mBrightness = BRIGHTNESS_LEVEL_FADED;
            } else {
                fade->mBrightness = (fade->mFadeFrames << 4) / fade->mFadeFrameCount;
            }
            if (fade->mPositive == FALSE) {
                fade->mBrightness = -fade->mBrightness;
            }
            break;
    }
}

void InitBrightnessFades(void) {
    gMainBrightnessFade.mState = BRIGHTNESS_FADE_FADED;
    gMainBrightnessFade.mPositive = TRUE;
    gMainBrightnessFade.mFadeFrames = 0;
    gMainBrightnessFade.mFadeFrameCount = 0;
    gMainBrightnessFade.mBrightness = BRIGHTNESS_LEVEL_FADED;
    gSubBrightnessFade.mState = BRIGHTNESS_FADE_FADED;
    gSubBrightnessFade.mPositive = TRUE;
    gSubBrightnessFade.mFadeFrames = 0;
    gSubBrightnessFade.mFadeFrameCount = 0;
    gSubBrightnessFade.mBrightness = BRIGHTNESS_LEVEL_FADED;
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
    records->mBg0.mBgCntLow2 = DISPLAY_BG0_DEFAULT_PRIORITY;
    records->mBg0.mBgCntMosaic = 0;
    records->mBg0.mBgCntVal14 = 0;
    records->mBg0.mBgCntVal7 = 0;
    records->mBg0.mBgCntVal8 = 0;
    records->mBg0.mBgCntVal2 = 0;
    records->mBg0.mBgCntVal13 = 0;
    records->mBg1.mBgCntLow2 = DISPLAY_BG1_DEFAULT_PRIORITY;
    records->mBg1.mBgCntVal14 = 0;
    records->mBg1.mBgCntVal7 = 0;
    records->mBg1.mBgCntMosaic = 0;
    records->mBg1.mBgCntVal8 = 0;
    records->mBg1.mBgCntVal2 = 0;
    records->mBg1.mBgCntVal13 = 0;
    bgCntMode = BG23_MODE_NONE;
    switch (bgMode) {
        case GX_BGMODE_0:
        case GX_BGMODE_1:
        case GX_BGMODE_3:
            bgCntMode = BG23_MODE_TEXT;
            break;
        case GX_BGMODE_2:
        case GX_BGMODE_4:
            bgCntMode = BG23_MODE_AFFINE;
            break;
        case GX_BGMODE_5:
            bgCntMode = BG23_MODE_AFFINE_NO_CHAR_BASE;
            break;
        case GX_BGMODE_6:
            break;
    }
    records->mBg2.mMode = bgCntMode;
    switch (bgCntMode) {
        case BG23_MODE_TEXT:
            records->mBg2.mFields.mBgCntLow2 = DISPLAY_BG23_DEFAULT_PRIORITY;
            records->mBg2.mFields.mBgCntVal14 = 0;
            records->mBg2.mFields.mBgCntVal7Or13 = 0;
            records->mBg2.mFields.mBgCntMosaic = 0;
            records->mBg2.mFields.mBgCntVal8 = 0;
            records->mBg2.mFields.mBgCntVal2 = 0;
            break;
        case BG23_MODE_AFFINE:
            records->mBg2.mFields.mBgCntLow2 = DISPLAY_BG23_DEFAULT_PRIORITY;
            records->mBg2.mFields.mBgCntVal14 = 0;
            records->mBg2.mFields.mBgCntMosaic = 0;
            records->mBg2.mFields.mBgCntVal7Or13 = 0;
            records->mBg2.mFields.mBgCntVal8 = 0;
            records->mBg2.mFields.mBgCntVal2 = 0;
            break;
        case BG23_MODE_AFFINE_NO_CHAR_BASE:
            records->mBg2.mFields.mBgCntLow2 = DISPLAY_BG23_DEFAULT_PRIORITY;
            records->mBg2.mFields.mBgCntMosaic = 0;
            records->mBg2.mFields.mBgCntVal14 = 0;
            records->mBg2.mFields.mBgCntVal7Or13 = 0;
            records->mBg2.mFields.mBgCntVal8 = 0;
            break;
    }
    bgCntMode = BG23_MODE_NONE;
    switch (bgMode) {
        case GX_BGMODE_0:
            bgCntMode = BG23_MODE_TEXT;
            break;
        case GX_BGMODE_1:
        case GX_BGMODE_2:
            bgCntMode = BG23_MODE_AFFINE;
            break;
        case GX_BGMODE_3:
        case GX_BGMODE_4:
        case GX_BGMODE_5:
            bgCntMode = BG23_MODE_AFFINE_NO_CHAR_BASE;
            break;
        case GX_BGMODE_6:
            break;
    }
    records->mBg3.mMode = bgCntMode;
    switch (bgCntMode) {
        case BG23_MODE_TEXT:
            records->mBg3.mFields.mBgCntLow2 = DISPLAY_BG23_DEFAULT_PRIORITY;
            records->mBg3.mFields.mBgCntVal14 = 0;
            records->mBg3.mFields.mBgCntVal7Or13 = 0;
            records->mBg3.mFields.mBgCntMosaic = 0;
            records->mBg3.mFields.mBgCntVal8 = 0;
            records->mBg3.mFields.mBgCntVal2 = 0;
            break;
        case BG23_MODE_AFFINE:
            records->mBg3.mFields.mBgCntLow2 = DISPLAY_BG23_DEFAULT_PRIORITY;
            records->mBg3.mFields.mBgCntVal14 = 0;
            records->mBg3.mFields.mBgCntMosaic = 0;
            records->mBg3.mFields.mBgCntVal7Or13 = 0;
            records->mBg3.mFields.mBgCntVal8 = 0;
            records->mBg3.mFields.mBgCntVal2 = 0;
            break;
        case BG23_MODE_AFFINE_NO_CHAR_BASE:
            records->mBg3.mFields.mBgCntLow2 = DISPLAY_BG23_DEFAULT_PRIORITY;
            records->mBg3.mFields.mBgCntMosaic = 0;
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
    DisplaySettings *settings = HeapAlloc(heap, sizeof(DisplaySettings));
    G3xParams *g3xParams;
    InitDisplaySettings(settings, descriptor);
    if (settings->mBg0As == GX_BG0_AS_3D) {
        g3xParams = HeapAlloc(heap, 8);
        g3xParams->mClearColor = DISPLAY_3D_CLEAR_COLOR;
        g3xParams->mSortMode = 1;
        g3xParams->mBufferMode = 1;
        settings->mG3xParams = g3xParams;
    }
    return settings;
}

void SetBg0Record(DisplayBgRecords *records, u32 cntLow2, u32 cntMosaic, u32 cntVal14, u32 cntVal7, u32 cntVal8,
                  u32 cntVal2, u32 cntVal13) {
    records->mBg0.mBgCntLow2 = cntLow2;
    records->mBg0.mBgCntVal14 = cntVal14;
    records->mBg0.mBgCntVal7 = cntVal7;
    records->mBg0.mBgCntMosaic = cntMosaic;
    records->mBg0.mBgCntVal8 = cntVal8;
    records->mBg0.mBgCntVal2 = cntVal2;
    records->mBg0.mBgCntVal13 = cntVal13;
}

void SetBg1Record(DisplayBgRecords *records, u32 cntLow2, u32 cntMosaic, u32 cntVal14, u32 cntVal7, u32 cntVal8,
                  u32 cntVal2, u32 cntVal13) {
    records->mBg1.mBgCntLow2 = cntLow2;
    records->mBg1.mBgCntVal14 = cntVal14;
    records->mBg1.mBgCntVal7 = cntVal7;
    records->mBg1.mBgCntMosaic = cntMosaic;
    records->mBg1.mBgCntVal8 = cntVal8;
    records->mBg1.mBgCntVal2 = cntVal2;
    records->mBg1.mBgCntVal13 = cntVal13;
}

void SetBg2RecordParams(DisplayBgRecords *records, u32 cntLow2, u32 cntMosaic, u32 cntVal14, u32 cntVal7Or13,
                        u32 cntVal8, u32 cntVal2) {
    records->mBg2.mFields.mBgCntLow2 = cntLow2;
    records->mBg2.mFields.mBgCntMosaic = cntMosaic;
    records->mBg2.mFields.mBgCntVal14 = cntVal14;
    records->mBg2.mFields.mBgCntVal7Or13 = cntVal7Or13;
    records->mBg2.mFields.mBgCntVal8 = cntVal8;
    records->mBg2.mFields.mBgCntVal2 = cntVal2;
}

void SetBg3RecordParams(DisplayBgRecords *records, u32 cntLow2, u32 cntMosaic, u32 cntVal14, u32 cntVal7Or13,
                        u32 cntVal8, u32 cntVal2) {
    records->mBg3.mFields.mBgCntLow2 = cntLow2;
    records->mBg3.mFields.mBgCntMosaic = cntMosaic;
    records->mBg3.mFields.mBgCntVal14 = cntVal14;
    records->mBg3.mFields.mBgCntVal7Or13 = cntVal7Or13;
    records->mBg3.mFields.mBgCntVal8 = cntVal8;
    records->mBg3.mFields.mBgCntVal2 = cntVal2;
}

void SetBg2RecordMode5(DisplayBgRecords *records, u32 cntLow2, u32 cntMosaic, u32 cntVal14, u32 cntVal7Or13,
                       u32 cntVal8) {
    records->mBg2.mMode = BG23_MODE_DC_BMP;
    records->mBg2.mFields.mBgCntLow2 = cntLow2;
    records->mBg2.mFields.mBgCntMosaic = cntMosaic;
    records->mBg2.mFields.mBgCntVal14 = cntVal14;
    records->mBg2.mFields.mBgCntVal7Or13 = cntVal7Or13;
    records->mBg2.mFields.mBgCntVal8 = cntVal8;
}

void SetG3xSwapBits(DisplaySettings *settings, u32 sortMode, u32 bufferMode) {
    settings->mG3xParams->mSortMode = sortMode;
    settings->mG3xParams->mBufferMode = bufferMode;
}

void SetSubObjVRamModeBmp(DisplaySettings *settings, u32 value) {
    settings->mSubBgRecords.mObjVRamModeBmp = value;
}

// Enum-typed parameters of the inlines below: their values are read before the register.
typedef enum { BG3_CONTROL_FIELD_0 } Bg3ControlField;

// Sets the low two bits of the halfword register cntReg and its bit 6 from the first two halfwords of fields.
static inline void SetBg3PriorityAndMosaic(vu16 *cntReg, Bg23CntFields *fields) {
    *cntReg = (*cntReg & ~3) | fields->mBgCntLow2;
    if (fields->mBgCntMosaic != 0) {
        *cntReg |= 0x40;
    } else {
        *cntReg &= ~0x40;
    }
}

// Keeps bits 0, 1 and 6 of the halfword register cntReg and sets the rest from four values.
static inline void SetBg3ControlText(vu16 *cntReg, Bg3ControlField screenSize, Bg3ControlField colorMode,
                                     Bg3ControlField screenBase, Bg3ControlField charBase) {
    *cntReg = (*cntReg & 0x43) | (screenSize << 14) | (colorMode << 7) | (screenBase << 8) | (charBase << 2);
}

// Keeps bits 0, 1 and 6 of the halfword register cntReg and sets the rest from four values.
static inline void SetBg3ControlAffine(vu16 *cntReg, Bg3ControlField screenSize, Bg3ControlField screenBase,
                                       Bg3ControlField charBase, Bg3ControlField overflowMode) {
    *cntReg = (*cntReg & 0x43) | (screenSize << 14) | (screenBase << 8) | (charBase << 2) | (overflowMode << 13);
}

// Keeps bits 0, 1 and 6 of the halfword register cntReg and sets the rest from three values.
static inline void SetBg3ControlWithoutCharBase(vu16 *cntReg, Bg3ControlField screenSize, Bg3ControlField overflowMode,
                                                Bg3ControlField screenBase) {
    *cntReg = (*cntReg & 0x43) | (screenSize << 14) | (screenBase << 8) | (overflowMode << 13);
}

// Keeps bits 0, 1 and 6 of the halfword register cntReg, sets bit 7 and the rest from three values.
static inline void SetBg3Control256Bmp(vu16 *cntReg, Bg3ControlField screenSize, Bg3ControlField overflowMode,
                                       Bg3ControlField screenBase) {
    *cntReg = (*cntReg & 0x43) | (screenSize << 14) | 0x80 | (screenBase << 8) | (overflowMode << 13);
}

// Keeps bits 0, 1 and 6 of the halfword register cntReg, sets bits 2 and 7 and the rest from three values.
static inline void SetBg3ControlDCBmp(vu16 *cntReg, Bg3ControlField screenSize, Bg3ControlField overflowMode,
                                      Bg3ControlField screenBase) {
    *cntReg = (*cntReg & 0x43) | (screenSize << 14) | 0x84 | (screenBase << 8) | (overflowMode << 13);
}

// Sets the low two bits of the halfword register cntReg and its bit 6 from the first two halfwords of fields.
static inline void SetBg2PriorityAndMosaic(vu16 *cntReg, Bg23CntFields *fields) {
    *cntReg = (*cntReg & ~3) | fields->mBgCntLow2;
    if (fields->mBgCntMosaic != 0) {
        *cntReg |= 0x40;
    } else {
        *cntReg &= ~0x40;
    }
}

// Keeps bits 0, 1 and 6 of the halfword register cntReg and sets the rest from four values.
static inline void SetBg2ControlText(vu16 *cntReg, Bg3ControlField screenSize, Bg3ControlField colorMode,
                                     Bg3ControlField screenBase, Bg3ControlField charBase) {
    *cntReg = (*cntReg & 0x43) | (screenSize << 14) | (colorMode << 7) | (screenBase << 8) | (charBase << 2);
}

// Keeps bits 0, 1 and 6 of the halfword register cntReg and sets the rest from four values.
static inline void SetBg2ControlAffine(vu16 *cntReg, Bg3ControlField screenSize, Bg3ControlField screenBase,
                                       Bg3ControlField charBase, Bg3ControlField overflowMode) {
    *cntReg = (*cntReg & 0x43) | (screenSize << 14) | (screenBase << 8) | (charBase << 2) | (overflowMode << 13);
}

// Keeps bits 0, 1 and 6 of the halfword register cntReg and sets the rest from three values.
static inline void SetBg2ControlWithoutCharBase(vu16 *cntReg, Bg3ControlField screenSize, Bg3ControlField overflowMode,
                                                Bg3ControlField screenBase) {
    *cntReg = (*cntReg & 0x43) | (screenSize << 14) | (screenBase << 8) | (overflowMode << 13);
}

// Keeps bits 0, 1 and 6 of the halfword register cntReg, sets bit 7 and the rest from three values.
static inline void SetBg2Control256Bmp(vu16 *cntReg, Bg3ControlField screenSize, Bg3ControlField overflowMode,
                                       Bg3ControlField screenBase) {
    *cntReg = (*cntReg & 0x43) | (screenSize << 14) | 0x80 | (screenBase << 8) | (overflowMode << 13);
}

// Keeps bits 0, 1 and 6 of the halfword register cntReg, sets bits 2 and 7 and the rest from three values.
static inline void SetBg2ControlDCBmp(vu16 *cntReg, Bg3ControlField screenSize, Bg3ControlField overflowMode,
                                      Bg3ControlField screenBase) {
    *cntReg = (*cntReg & 0x43) | (screenSize << 14) | 0x84 | (screenBase << 8) | (overflowMode << 13);
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
        case BG23_MODE_TEXT:
            if (isMainScreen != 0) {
                reg_G2_BG2OFS = 0;
                SetBg2PriorityAndMosaic(&reg_G2_BG2CNT, fields);
                SetBg2ControlText(&reg_G2_BG2CNT, (Bg3ControlField) fields->mBgCntVal14,
                                  (Bg3ControlField) fields->mBgCntVal7Or13, (Bg3ControlField) fields->mBgCntVal8,
                                  (Bg3ControlField) fields->mBgCntVal2);
            } else {
                reg_G2S_DB_BG2OFS = 0;
                SetBg2PriorityAndMosaic(&reg_G2S_DB_BG2CNT, fields);
                SetBg2ControlText(&reg_G2S_DB_BG2CNT, (Bg3ControlField) fields->mBgCntVal14,
                                  (Bg3ControlField) fields->mBgCntVal7Or13, (Bg3ControlField) fields->mBgCntVal8,
                                  (Bg3ControlField) fields->mBgCntVal2);
            }
            break;
        case BG23_MODE_AFFINE:
            if (isMainScreen != 0) {
                G2x_SetBGyAffine_(&reg_G2_BG2PA, matrix, 0, 0, 0, 0);
                SetBg2PriorityAndMosaic(&reg_G2_BG2CNT, fields);
                SetBg2ControlAffine(&reg_G2_BG2CNT, (Bg3ControlField) fields->mBgCntVal14,
                                    (Bg3ControlField) fields->mBgCntVal8, (Bg3ControlField) fields->mBgCntVal2,
                                    (Bg3ControlField) fields->mBgCntVal7Or13);
            } else {
                G2x_SetBGyAffine_(&reg_G2S_DB_BG2PA, matrix, 0, 0, 0, 0);
                SetBg2PriorityAndMosaic(&reg_G2S_DB_BG2CNT, fields);
                SetBg2ControlAffine(&reg_G2S_DB_BG2CNT, (Bg3ControlField) fields->mBgCntVal14,
                                    (Bg3ControlField) fields->mBgCntVal8, (Bg3ControlField) fields->mBgCntVal2,
                                    (Bg3ControlField) fields->mBgCntVal7Or13);
            }
            break;
        case BG23_MODE_AFFINE_NO_CHAR_BASE:
            if (isMainScreen != 0) {
                G2x_SetBGyAffine_(&reg_G2_BG2PA, matrix, 0, 0, 0, 0);
                SetBg2PriorityAndMosaic(&reg_G2_BG2CNT, fields);
                SetBg2ControlWithoutCharBase(&reg_G2_BG2CNT, (Bg3ControlField) fields->mBgCntVal14,
                                             (Bg3ControlField) fields->mBgCntVal7Or13,
                                             (Bg3ControlField) fields->mBgCntVal8);
            } else {
                G2x_SetBGyAffine_(&reg_G2S_DB_BG2PA, matrix, 0, 0, 0, 0);
                SetBg2PriorityAndMosaic(&reg_G2S_DB_BG2CNT, fields);
                SetBg2ControlWithoutCharBase(&reg_G2S_DB_BG2CNT, (Bg3ControlField) fields->mBgCntVal14,
                                             (Bg3ControlField) fields->mBgCntVal7Or13,
                                             (Bg3ControlField) fields->mBgCntVal8);
            }
            break;
        case BG23_MODE_256_BMP:
            if (isMainScreen != 0) {
                G2x_SetBGyAffine_(&reg_G2_BG2PA, matrix, 0, 0, 0, 0);
                SetBg2PriorityAndMosaic(&reg_G2_BG2CNT, fields);
                SetBg2Control256Bmp(&reg_G2_BG2CNT, (Bg3ControlField) fields->mBgCntVal14,
                                    (Bg3ControlField) fields->mBgCntVal7Or13, (Bg3ControlField) fields->mBgCntVal8);
            } else {
                G2x_SetBGyAffine_(&reg_G2S_DB_BG2PA, matrix, 0, 0, 0, 0);
                SetBg2PriorityAndMosaic(&reg_G2S_DB_BG2CNT, fields);
                SetBg2Control256Bmp(&reg_G2S_DB_BG2CNT, (Bg3ControlField) fields->mBgCntVal14,
                                    (Bg3ControlField) fields->mBgCntVal7Or13, (Bg3ControlField) fields->mBgCntVal8);
            }
            break;
        case BG23_MODE_DC_BMP:
            if (isMainScreen != 0) {
                G2x_SetBGyAffine_(&reg_G2_BG2PA, matrix, 0, 0, 0, 0);
                SetBg2PriorityAndMosaic(&reg_G2_BG2CNT, fields);
                SetBg2ControlDCBmp(&reg_G2_BG2CNT, (Bg3ControlField) fields->mBgCntVal14,
                                   (Bg3ControlField) fields->mBgCntVal7Or13, (Bg3ControlField) fields->mBgCntVal8);
            } else {
                G2x_SetBGyAffine_(&reg_G2S_DB_BG2PA, matrix, 0, 0, 0, 0);
                SetBg2PriorityAndMosaic(&reg_G2S_DB_BG2CNT, fields);
                SetBg2ControlDCBmp(&reg_G2S_DB_BG2CNT, (Bg3ControlField) fields->mBgCntVal14,
                                   (Bg3ControlField) fields->mBgCntVal7Or13, (Bg3ControlField) fields->mBgCntVal8);
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
        case BG23_MODE_TEXT:
            if (isMainScreen != 0) {
                reg_G2_BG3OFS = 0;
                SetBg3PriorityAndMosaic(&reg_G2_BG3CNT, fields);
                SetBg3ControlText(&reg_G2_BG3CNT, (Bg3ControlField) fields->mBgCntVal14,
                                  (Bg3ControlField) fields->mBgCntVal7Or13, (Bg3ControlField) fields->mBgCntVal8,
                                  (Bg3ControlField) fields->mBgCntVal2);
            } else {
                reg_G2S_DB_BG3OFS = 0;
                SetBg3PriorityAndMosaic(&reg_G2S_DB_BG3CNT, fields);
                SetBg3ControlText(&reg_G2S_DB_BG3CNT, (Bg3ControlField) fields->mBgCntVal14,
                                  (Bg3ControlField) fields->mBgCntVal7Or13, (Bg3ControlField) fields->mBgCntVal8,
                                  (Bg3ControlField) fields->mBgCntVal2);
            }
            break;
        case BG23_MODE_AFFINE:
            if (isMainScreen != 0) {
                G2x_SetBGyAffine_(&reg_G2_BG3PA, matrix, 0, 0, 0, 0);
                SetBg3PriorityAndMosaic(&reg_G2_BG3CNT, fields);
                SetBg3ControlAffine(&reg_G2_BG3CNT, (Bg3ControlField) fields->mBgCntVal14,
                                    (Bg3ControlField) fields->mBgCntVal8, (Bg3ControlField) fields->mBgCntVal2,
                                    (Bg3ControlField) fields->mBgCntVal7Or13);
            } else {
                G2x_SetBGyAffine_(&reg_G2S_DB_BG3PA, matrix, 0, 0, 0, 0);
                SetBg3PriorityAndMosaic(&reg_G2S_DB_BG3CNT, fields);
                SetBg3ControlAffine(&reg_G2S_DB_BG3CNT, (Bg3ControlField) fields->mBgCntVal14,
                                    (Bg3ControlField) fields->mBgCntVal8, (Bg3ControlField) fields->mBgCntVal2,
                                    (Bg3ControlField) fields->mBgCntVal7Or13);
            }
            break;
        case BG23_MODE_AFFINE_NO_CHAR_BASE:
            if (isMainScreen != 0) {
                G2x_SetBGyAffine_(&reg_G2_BG3PA, matrix, 0, 0, 0, 0);
                SetBg3PriorityAndMosaic(&reg_G2_BG3CNT, fields);
                SetBg3ControlWithoutCharBase(&reg_G2_BG3CNT, (Bg3ControlField) fields->mBgCntVal14,
                                             (Bg3ControlField) fields->mBgCntVal7Or13,
                                             (Bg3ControlField) fields->mBgCntVal8);
            } else {
                G2x_SetBGyAffine_(&reg_G2S_DB_BG3PA, matrix, 0, 0, 0, 0);
                SetBg3PriorityAndMosaic(&reg_G2S_DB_BG3CNT, fields);
                SetBg3ControlWithoutCharBase(&reg_G2S_DB_BG3CNT, (Bg3ControlField) fields->mBgCntVal14,
                                             (Bg3ControlField) fields->mBgCntVal7Or13,
                                             (Bg3ControlField) fields->mBgCntVal8);
            }
            break;
        case BG23_MODE_256_BMP:
            if (isMainScreen != 0) {
                G2x_SetBGyAffine_(&reg_G2_BG3PA, matrix, 0, 0, 0, 0);
                SetBg3PriorityAndMosaic(&reg_G2_BG3CNT, fields);
                SetBg3Control256Bmp(&reg_G2_BG3CNT, (Bg3ControlField) fields->mBgCntVal14,
                                    (Bg3ControlField) fields->mBgCntVal7Or13, (Bg3ControlField) fields->mBgCntVal8);
            } else {
                G2x_SetBGyAffine_(&reg_G2S_DB_BG3PA, matrix, 0, 0, 0, 0);
                SetBg3PriorityAndMosaic(&reg_G2S_DB_BG3CNT, fields);
                SetBg3Control256Bmp(&reg_G2S_DB_BG3CNT, (Bg3ControlField) fields->mBgCntVal14,
                                    (Bg3ControlField) fields->mBgCntVal7Or13, (Bg3ControlField) fields->mBgCntVal8);
            }
            break;
        case BG23_MODE_DC_BMP:
            if (isMainScreen != 0) {
                G2x_SetBGyAffine_(&reg_G2_BG3PA, matrix, 0, 0, 0, 0);
                SetBg3PriorityAndMosaic(&reg_G2_BG3CNT, fields);
                SetBg3ControlDCBmp(&reg_G2_BG3CNT, (Bg3ControlField) fields->mBgCntVal14,
                                   (Bg3ControlField) fields->mBgCntVal7Or13, (Bg3ControlField) fields->mBgCntVal8);
            } else {
                G2x_SetBGyAffine_(&reg_G2S_DB_BG3PA, matrix, 0, 0, 0, 0);
                SetBg3PriorityAndMosaic(&reg_G2S_DB_BG3CNT, fields);
                SetBg3ControlDCBmp(&reg_G2S_DB_BG3CNT, (Bg3ControlField) fields->mBgCntVal14,
                                   (Bg3ControlField) fields->mBgCntVal7Or13, (Bg3ControlField) fields->mBgCntVal8);
            }
            break;
        default:
            break;
    }
}

// Enum-typed parameters of the inlines below: their values are read before the register.
typedef enum { DISPLAY_REGISTER_FIELD_0 } DisplayRegisterField;

// Calls MIi_CpuClearFast with the value read from a volatile copy.
static inline void DisplayFillMemoryFast(u32 fillValue, void *destination, u32 size) {
    volatile u32 fillValueCopy = fillValue;
    MIi_CpuClearFast(fillValueCopy, destination, size);
}

// Sets the low two bits of the halfword register cntReg and its bit 6 from the first two halfwords of q.
static inline void SetBg01PriorityAndMosaic(vu16 *cntReg, Bg01Cnt *cnt) {
    *cntReg = (*cntReg & ~3) | cnt->mBgCntLow2;
    if (cnt->mBgCntMosaic != 0) {
        *cntReg |= 0x40;
    } else {
        *cntReg &= ~0x40;
    }
}

// Sets bits 4, 20 and 21 of the word register r.
static inline void SetDispcntObjVRamModeChar(vu32 *reg, DisplayRegisterField bits) {
    *reg = (*reg & 0xffcfffef) | bits;
}

// Sets bits 5, 6 and 22 of the word at 0x04000000.
static inline void DisplayGX_SetOBJVRamModeBmp(DisplayRegisterField bits) {
    reg_GX_DISPCNT = (reg_GX_DISPCNT & 0xffbfff9f) | bits;
}

// Sets bits 5 and 6 of the word at 0x04001000.
static inline void DisplayGXS_SetOBJVRamModeBmp(DisplayRegisterField bits) {
    reg_GXS_DB_DISPCNT = (reg_GXS_DB_DISPCNT & ~0x60) | bits;
}

// Keeps bits 0, 1 and 6 of the halfword register cntReg and sets the rest from five values.
static inline void SetBg01Control(vu16 *cntReg, DisplayRegisterField screenSize, DisplayRegisterField colorMode,
                                  DisplayRegisterField screenBase, DisplayRegisterField charBase,
                                  DisplayRegisterField overflowMode) {
    *cntReg = (*cntReg & 0x43) | (screenSize << 14) | (colorMode << 7) | (screenBase << 8) | (charBase << 2) |
              (overflowMode << 13);
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
    reg_GX_DISPCNT = (reg_GX_DISPCNT & ~REG_GX_DISPCNT_DISPLAY_MASK) | (settings->mMainDisplayMask << 8);
    GXS_SetGraphicsMode(settings->mSubBgMode);
    reg_GXS_DB_DISPCNT = (reg_GXS_DB_DISPCNT & ~REG_GXS_DB_DISPCNT_DISPLAY_MASK) | (settings->mSubDisplayMask << 8);
    if (settings->mBg0As == GX_BG0_AS_3D) {
        G3X_Init();
        G3X_InitTable();
        G3X_InitMtxStack();
        reg_G3X_DISP3DCNT &= ~(REG_G3X_DISP3DCNT_GO_MASK | REG_G3X_DISP3DCNT_RO_MASK | REG_G3X_DISP3DCNT_THS_MASK);
        reg_G3X_DISP3DCNT = (reg_G3X_DISP3DCNT & ~(REG_G3X_DISP3DCNT_GO_MASK | REG_G3X_DISP3DCNT_RO_MASK)) | 0x10;
        reg_G3X_DISP3DCNT = (reg_G3X_DISP3DCNT & ~(REG_G3X_DISP3DCNT_GO_MASK | REG_G3X_DISP3DCNT_RO_MASK)) | 4;
        reg_G3X_ALPHA_TEST_REF = 0;
        reg_G3X_DISP3DCNT = (reg_G3X_DISP3DCNT & ~(REG_G3X_DISP3DCNT_GO_MASK | REG_G3X_DISP3DCNT_RO_MASK)) | 8;
        reg_G2_BLDCNT = 0;
        reg_G3_SWAP_BUFFERS = (settings->mG3xParams->mBufferMode << 1) | settings->mG3xParams->mSortMode;
        clearColor = settings->mG3xParams->mClearColor;
        G3X_SetClearColor((u16) (clearColor & 0x7fff), (u8) ((clearColor & 0x8000) >> 15), 0x7fff, 0x3f, 0);
    }
    if (settings->mMainDisplayMask & GX_PLANEMASK_BG0) {
        cnt = &settings->mMainBgRecords.mBg0;
        SetBg01PriorityAndMosaic(&reg_G2_BG0CNT, cnt);
        if (settings->mBg0As == GX_BG0_AS_3D) {
            G2Bg0OfsWrite(0);
        } else {
            reg_G2_BG0OFS = 0;
            SetBg01Control(&reg_G2_BG0CNT, (DisplayRegisterField) cnt->mBgCntVal14,
                           (DisplayRegisterField) cnt->mBgCntVal7, (DisplayRegisterField) cnt->mBgCntVal8,
                           (DisplayRegisterField) cnt->mBgCntVal2, (DisplayRegisterField) cnt->mBgCntVal13);
        }
    }
    if (settings->mSubDisplayMask & GX_PLANEMASK_BG0) {
        reg_G2S_DB_BG0OFS = 0;
        cnt = &settings->mSubBgRecords.mBg0;
        SetBg01PriorityAndMosaic(&reg_G2S_DB_BG0CNT, cnt);
        SetBg01Control(&reg_G2S_DB_BG0CNT, (DisplayRegisterField) cnt->mBgCntVal14,
                       (DisplayRegisterField) cnt->mBgCntVal7, (DisplayRegisterField) cnt->mBgCntVal8,
                       (DisplayRegisterField) cnt->mBgCntVal2, (DisplayRegisterField) cnt->mBgCntVal13);
    }
    if (settings->mMainDisplayMask & GX_PLANEMASK_BG1) {
        reg_G2_BG1OFS = 0;
        cnt = &settings->mMainBgRecords.mBg1;
        SetBg01PriorityAndMosaic(&reg_G2_BG1CNT, cnt);
        SetBg01Control(&reg_G2_BG1CNT, (DisplayRegisterField) cnt->mBgCntVal14, (DisplayRegisterField) cnt->mBgCntVal7,
                       (DisplayRegisterField) cnt->mBgCntVal8, (DisplayRegisterField) cnt->mBgCntVal2,
                       (DisplayRegisterField) cnt->mBgCntVal13);
    }
    if (settings->mSubDisplayMask & GX_PLANEMASK_BG1) {
        reg_G2S_DB_BG1OFS = 0;
        cnt = &settings->mSubBgRecords.mBg1;
        SetBg01PriorityAndMosaic(&reg_G2S_DB_BG1CNT, cnt);
        SetBg01Control(&reg_G2S_DB_BG1CNT, (DisplayRegisterField) cnt->mBgCntVal14,
                       (DisplayRegisterField) cnt->mBgCntVal7, (DisplayRegisterField) cnt->mBgCntVal8,
                       (DisplayRegisterField) cnt->mBgCntVal2, (DisplayRegisterField) cnt->mBgCntVal13);
    }
    if (settings->mMainDisplayMask & GX_PLANEMASK_BG2) {
        ApplyBg2Cnt(&settings->mMainBgRecords.mBg2, 1);
    }
    if (settings->mSubDisplayMask & GX_PLANEMASK_BG2) {
        ApplyBg2Cnt(&settings->mSubBgRecords.mBg2, 0);
    }
    if (settings->mMainDisplayMask & GX_PLANEMASK_BG3) {
        ApplyBg3Cnt(&settings->mMainBgRecords.mBg3, 1);
    }
    if (settings->mSubDisplayMask & GX_PLANEMASK_BG3) {
        ApplyBg3Cnt(&settings->mSubBgRecords.mBg3, 0);
    }
    if (settings->mMainDisplayMask & GX_PLANEMASK_OBJ) {
        SetDispcntObjVRamModeChar(&reg_GX_DISPCNT, (DisplayRegisterField) settings->mMainBgRecords.mObjVRamModeChar);
        DisplayGX_SetOBJVRamModeBmp((DisplayRegisterField) settings->mMainBgRecords.mObjVRamModeBmp);
    }
    if (settings->mSubDisplayMask & GX_PLANEMASK_OBJ) {
        SetDispcntObjVRamModeChar(&reg_GXS_DB_DISPCNT, (DisplayRegisterField) settings->mSubBgRecords.mObjVRamModeChar);
        DisplayGXS_SetOBJVRamModeBmp((DisplayRegisterField) settings->mSubBgRecords.mObjVRamModeBmp);
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
    if (settings->mBg0As == GX_BG0_AS_3D) {
        G3X_Reset();
    }
    if (gFrameCallback != NULL) {
        gFrameCallback(0);
    }
}

u32 IsFrameSpanningVBlank(void) {
    return (gDisplaySettings->mFrameFlags & DISPLAY_FRAME_FLAG_SPANNED_VBLANK) ? 1 : 0;
}

void ClearFrameFinishedFlag(void) {
    u32 frameFlags;
    frameFlags = gDisplaySettings->mFrameFlags;
    frameFlags = (frameFlags) & ~(u32) DISPLAY_FRAME_FLAG_FINISHED;
    gDisplaySettings->mFrameFlags = frameFlags;
}

static inline void StartBrightnessFadeToFadedPositive(BrightnessFade *fade, s16 frameCount) {
    if (fade->mState == BRIGHTNESS_FADE_FADED ||
        (fade->mState == BRIGHTNESS_FADE_TO_FADED && fade->mPositive == TRUE)) {
        return;
    }
    fade->mPositive = TRUE;
    if (fade->mState != BRIGHTNESS_FADE_TO_CLEAR) {
        fade->mFadeFrames = 0;
    } else {
        fade->mFadeFrames = (frameCount * fade->mBrightness) / 16;
    }
    fade->mState = BRIGHTNESS_FADE_TO_FADED;
    fade->mFadeFrameCount = frameCount;
}

static inline void StartBrightnessFadeToFadedNegative(BrightnessFade *fade, s16 frameCount) {
    if (fade->mState == BRIGHTNESS_FADE_FADED ||
        (fade->mState == BRIGHTNESS_FADE_TO_FADED && fade->mPositive == FALSE)) {
        return;
    }
    fade->mPositive = FALSE;
    if (fade->mState != BRIGHTNESS_FADE_TO_CLEAR) {
        fade->mFadeFrames = 0;
    } else {
        fade->mFadeFrames = (frameCount * fade->mBrightness) / 16;
    }
    fade->mState = BRIGHTNESS_FADE_TO_FADED;
    fade->mFadeFrameCount = frameCount;
}

static inline void StartBrightnessFadeToClearNegative(BrightnessFade *fade, s16 frameCount) {
    if (fade->mState == BRIGHTNESS_FADE_CLEAR || fade->mState == BRIGHTNESS_FADE_TO_CLEAR) {
        return;
    }
    fade->mPositive = FALSE;
    if (fade->mState == BRIGHTNESS_FADE_CLEAR || fade->mState == BRIGHTNESS_FADE_TO_CLEAR) {
        return;
    }
    if (fade->mState != BRIGHTNESS_FADE_TO_FADED) {
        fade->mFadeFrames = 0;
    } else {
        fade->mFadeFrames = (frameCount * fade->mBrightness) / 16;
    }
    fade->mState = BRIGHTNESS_FADE_TO_CLEAR;
    fade->mFadeFrameCount = frameCount;
}

static inline void StartBrightnessFadeToClear(BrightnessFade *fade, s16 frameCount) {
    if (fade->mState == BRIGHTNESS_FADE_CLEAR || fade->mState == BRIGHTNESS_FADE_TO_CLEAR) {
        return;
    }
    if (fade->mState != BRIGHTNESS_FADE_TO_FADED) {
        fade->mFadeFrames = 0;
    } else {
        fade->mFadeFrames = (frameCount * fade->mBrightness) / 16;
    }
    fade->mState = BRIGHTNESS_FADE_TO_CLEAR;
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
    if (settings->mBg0As == GX_BG0_AS_3D) {
        reg_G3_SWAP_BUFFERS = (settings->mG3xParams->mBufferMode << 1) | settings->mG3xParams->mSortMode;
    }
    if ((gDisplaySettings->mFrameFlags & DISPLAY_FRAME_FLAG_FINISHED) == 0) {
        gDisplaySettings->mFrameFlags |= DISPLAY_FRAME_FLAG_SPANNED_VBLANK;
    } else {
        gDisplaySettings->mFrameFlags &= ~DISPLAY_FRAME_FLAG_SPANNED_VBLANK;
        gDisplaySettings->mFrameFlags &= ~DISPLAY_FRAME_FLAG_FINISHED;
    }
    settings = gDisplaySettings;
    tick = OS_GetTick();
    settings->mTimeBeforeWait = (tick - settings->mFrameStartTick) * 0xfa00 / 0x82ea;
    for (waitIndex = 0; waitIndex < gDisplaySettings->mWaitIrqCount; waitIndex++) {
        OS_WaitIrq(1, 1);
    }
    gDisplaySettings->mFrameFlags |= DISPLAY_FRAME_FLAG_FINISHED;
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
    if ((gDisplaySettings->mFrameFlags & DISPLAY_FRAME_FLAG_FINISHED) == 0) {
        gDisplaySettings->mFrameFlags |= DISPLAY_FRAME_FLAG_SPANNED_VBLANK;
    } else {
        gDisplaySettings->mFrameFlags &= ~DISPLAY_FRAME_FLAG_SPANNED_VBLANK;
        gDisplaySettings->mFrameFlags &= ~DISPLAY_FRAME_FLAG_FINISHED;
    }
    if (skipWhenSpanned == 0 || (gDisplaySettings->mFrameFlags & DISPLAY_FRAME_FLAG_SPANNED_VBLANK) == 0) {
        swapAndWait = TRUE;
    } else {
        swapAndWait = FALSE;
    }
    settings = gDisplaySettings;
    if (settings->mBg0As == GX_BG0_AS_3D && swapAndWait != FALSE) {
        reg_G3_SWAP_BUFFERS = (settings->mG3xParams->mBufferMode << 1) | settings->mG3xParams->mSortMode;
    }
    settings = gDisplaySettings;
    tick = OS_GetTick();
    settings->mTimeBeforeWait = (tick - settings->mFrameStartTick) * 0xfa00 / 0x82ea;
    if (swapAndWait != FALSE) {
        for (waitIndex = 0; waitIndex < gDisplaySettings->mWaitIrqCount; waitIndex++) {
            OS_WaitIrq(1, 1);
        }
    }
    gDisplaySettings->mFrameFlags |= DISPLAY_FRAME_FLAG_FINISHED;
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
    if ((gDisplaySettings->mFrameFlags & DISPLAY_FRAME_FLAG_FINISHED) == 0) {
        gDisplaySettings->mFrameFlags |= DISPLAY_FRAME_FLAG_SPANNED_VBLANK;
    } else {
        gDisplaySettings->mFrameFlags &= ~DISPLAY_FRAME_FLAG_SPANNED_VBLANK;
        gDisplaySettings->mFrameFlags &= ~DISPLAY_FRAME_FLAG_FINISHED;
    }
    settings = gDisplaySettings;
    if (settings->mBg0As == GX_BG0_AS_3D && doSwap != 0) {
        reg_G3_SWAP_BUFFERS = (settings->mG3xParams->mBufferMode << 1) | settings->mG3xParams->mSortMode;
    }
    settings = gDisplaySettings;
    tick = OS_GetTick();
    settings->mTimeBeforeWait = (tick - settings->mFrameStartTick) * 0xfa00 / 0x82ea;
    for (waitIndex = 0; waitIndex < gDisplaySettings->mWaitIrqCount; waitIndex++) {
        OS_WaitIrq(1, 1);
    }
    gDisplaySettings->mFrameFlags |= DISPLAY_FRAME_FLAG_FINISHED;
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
    if (gMainBrightnessFade.mState == BRIGHTNESS_FADE_FADED && gSubBrightnessFade.mState == BRIGHTNESS_FADE_FADED) {
        return 1;
    }
    return 0;
}

void SetBrightnessFadesClear(void) {
    gMainBrightnessFade.mState = BRIGHTNESS_FADE_CLEAR;
    gMainBrightnessFade.mPositive = FALSE;
    gMainBrightnessFade.mFadeFrames = 0;
    gMainBrightnessFade.mFadeFrameCount = 0;
    gMainBrightnessFade.mBrightness = BRIGHTNESS_LEVEL_CLEAR;
    gSubBrightnessFade.mState = BRIGHTNESS_FADE_CLEAR;
    gSubBrightnessFade.mPositive = FALSE;
    gSubBrightnessFade.mFadeFrames = 0;
    gSubBrightnessFade.mFadeFrameCount = 0;
    gSubBrightnessFade.mBrightness = BRIGHTNESS_LEVEL_CLEAR;
    GXx_SetMasterBrightness_(&reg_GX_MASTER_BRIGHT, gMainBrightnessFade.mBrightness);
    GXx_SetMasterBrightness_(&reg_GXS_DB_MASTER_BRIGHT, gSubBrightnessFade.mBrightness);
}

u32 AreBrightnessFadesClear(void) {
    if ((gMainBrightnessFade.mState == BRIGHTNESS_FADE_CLEAR) && (gSubBrightnessFade.mState == BRIGHTNESS_FADE_CLEAR)) {
        return 1;
    }
    return 0;
}
