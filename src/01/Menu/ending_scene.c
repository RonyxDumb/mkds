#include "01/Menu/ending_scene.h"
#include "registers.h"
#include "01/MapObjects/mission_run_map_object_flags.h"
#include "01/Menu/menu_screen_work_structs.h"
#include "Main/System/heap.h"
#include "Main/Scene/display_settings.h"
#include "Main/Graphics/oam_upload.h"
#include "Main/Race/race_setup_block.h"
#include "touch_panel_sampling.h"
#include "Main/Menu/menu_shared_clear.h"
#include "Main/System/init_after_startup.h"

const u16 gEndingSceneStateTable[8] = {0, 0xf0, 0x78, 0x1e, 0x3c, 0xb4, 0x78, 0x3c};
EndingScene *gEndingScene;

void CreateEndingScene(void *heap) {
    void *bmgEntry;

    gEndingScene = Mem_AllocateHeap(heap, sizeof(EndingScene));
    gEndingScene->mHeap = heap;
    gEndingScene->mSceneDisplaySettings = CreateLoadSomeDisplayConfig_from_thumb(heap);
    gEndingScene->mNextScene = -1;
    gEndingScene->mState = ENDING_SCENE_STATE_WAIT_FADE_IN;
    gEndingScene->mNextState = gEndingScene->mState;
    gEndingScene->mStateFrames = 0;
    if (g_GlobalCO->mCourseId == COURSE_ID_STAFFROLLTRUE) {
        gEndingScene->mKind = ENDING_KIND_STAFFROLL_TRUE;
    } else {
        gEndingScene->mKind = ENDING_KIND_STAFFROLL;
    }
    gEndingScene->mIndex1Queued = FALSE;
    gEndingScene->mCommonMessages = FindFileBuffer_G2L_GE2_CKL_CKS_S2D_M2L_MA2_from_thumb("common.bmg");
    InitEndingSceneDisplay();
    LoadAndQueueEndingSceneData();
    OamBuffer_SomeFn_from_thumb(gEndingScene->mMainOam, NULL);
    InitLayoutTable(gEndingScene->mHeap, gEndingScene->mEndingThanksBncl, gEndingScene->mEndingThanksBnll,
                    &gEndingScene->mEndingThanksTable);
    bmgEntry = NULL;
    gEndingScene->mEndingThanksTable->mVisible = 0;
    {
        u16 table[2][2] = {{200, 24}, {200, 24}};

        switch (gEndingScene->mKind) {
            case ENDING_KIND_STAFFROLL:
                bmgEntry = Bmg_GetRawStringPointer_from_thumb(gEndingScene->mCommonMessages, 0x77);
                break;
            case ENDING_KIND_STAFFROLL_TRUE:
                bmgEntry = Bmg_GetRawStringPointer_from_thumb(gEndingScene->mCommonMessages, 0x78);
                break;
        }
        InitLabelCanvas(gEndingScene->mHeap, 0, gEndingScene->mEndingThanksBnll, table[gEndingScene->mKind][0],
                        table[gEndingScene->mKind][1], 0, gEndingScene->mThanksYouMNcer,
                        gEndingScene->mEndingThanksBncl, gEndingScene->mEndingThanksTable, 0x8000);
        PrintLabelLayoutTextNoFixedAdvance(0, 0, gEndingScene->mEndingThanksBnll, bmgEntry,
                                           gEndingScene->mEndingThanksBncl, gEndingScene->mEndingThanksTable);
    }
}

void ClearEndingScenePointer(void) {
    *&gEndingScene = 0;
}

void InitEndingSceneDisplay(void) {
    reg_GX_DISPCNT = (reg_GX_DISPCNT & ~REG_GX_DISPCNT_DISPLAY_MASK) | 0x100;
    reg_GXS_DB_DISPCNT = (reg_GXS_DB_DISPCNT & ~REG_GXS_DB_DISPCNT_DISPLAY_MASK) | 0x100;
    reg_G2_BG0CNT = (reg_G2_BG0CNT & ~REG_G2_BG0CNT_PRIORITY_MASK) | 3;
    reg_G2_BG0CNT = (reg_G2_BG0CNT & (REG_G2_BG0CNT_PRIORITY_MASK | REG_G2_BG0CNT_MOSAIC_MASK)) | 0x1f00;
    reg_G2S_DB_BG0CNT =
        (reg_G2S_DB_BG0CNT & (REG_G2S_DB_BG0CNT_PRIORITY_MASK | REG_G2S_DB_BG0CNT_MOSAIC_MASK)) | 0x1000;
    reg_G2_BG2OFS = 0;
    reg_G2S_DB_BG0OFS = 0;
    *(vu16 *) 0x5000000 = 0;
    *(vu16 *) 0x5000400 = 0;
}

void QueueEndingSceneNcgrNscrNclr(int i) {
    AllocateReserveTEQSub(4, 0, gEndingScene->mLogoEndMarioKartMBAndThanksYouMBNcgrs[i]->mData,
                                       gEndingScene->mLogoEndMarioKartMBAndThanksYouMBNcgrs[i]->mDataSize);
    AllocateReserveTEQSub(8, 0, gEndingScene->mLogoEndMarioKartMBgAndThanksYouMBgNscrs[i]->mData,
                                       gEndingScene->mLogoEndMarioKartMBgAndThanksYouMBgNscrs[i]->mDataSize);
    AllocateReserveTEQSub(0xf, 0, gEndingScene->mLogoEndMarioKartMBAndThanksYouMBNclrs[i]->mData,
                                       gEndingScene->mLogoEndMarioKartMBAndThanksYouMBNclrs[i]->mDataSize);
    AllocateReserveTEQSub(0x14, 0,
                                       gEndingScene->mEndAllRightsReservedSBAndLogoEndNintendoSBNcgrs[i]->mData,
                                       gEndingScene->mEndAllRightsReservedSBAndLogoEndNintendoSBNcgrs[i]->mDataSize);
    AllocateReserveTEQSub(0x18, 0,
                                       gEndingScene->mEndAllRightsReservedSBgAndLogoEndNintendoSBgNscrs[i]->mData,
                                       gEndingScene->mEndAllRightsReservedSBgAndLogoEndNintendoSBgNscrs[i]->mDataSize);
    AllocateReserveTEQSub(0x1f, 0,
                                       gEndingScene->mEndAllRightsReservedSBAndLogoEndNintendoSBNclrs[i]->mData,
                                       gEndingScene->mEndAllRightsReservedSBAndLogoEndNintendoSBNclrs[i]->mDataSize);
}

void QueueEndingSceneIndex1Data(void) {
    reg_G2_BG0CNT = reg_G2_BG0CNT & (REG_G2_BG0CNT_PRIORITY_MASK | REG_G2_BG0CNT_MOSAIC_MASK) | 0x00001f80u;
    QueueEndingSceneNcgrNscrNclr(1);
    gEndingScene->mIndex1Queued = TRUE;
}

void LoadAndQueueEndingSceneData(void) {
#ifdef version_EUR
    Gfx_ReadCharGraphicsV2(&gEndingScene->mLogoEndMarioKartMBAndThanksYouMBNcgrs[0],
                 FindFileBuffer_K2D_LOC_R2D_R2L_from_thumb("logo_end_marioKart_m_b_02.ncgr"));
    MaybeReadScreenBlock_0(&gEndingScene->mLogoEndMarioKartMBgAndThanksYouMBgNscrs[0],
                 FindFileBuffer_K2D_LOC_R2D_R2L_from_thumb("logo_end_marioKart_m_bg_02.nscr"));
#else
    Gfx_ReadCharGraphicsV2(&gEndingScene->mLogoEndMarioKartMBAndThanksYouMBNcgrs[0],
                 FindFileBuffer_K2D_LOC_R2D_R2L_from_thumb("logo_end_marioKart_m_b_01.ncgr"));
    MaybeReadScreenBlock_0(&gEndingScene->mLogoEndMarioKartMBgAndThanksYouMBgNscrs[0],
                 FindFileBuffer_K2D_LOC_R2D_R2L_from_thumb("logo_end_marioKart_m_bg_01.nscr"));
#endif
    Gfx_ReadPalette(&gEndingScene->mLogoEndMarioKartMBAndThanksYouMBNclrs[0],
                 FindFileBuffer_K2D_LOC_R2D_R2L_from_thumb("logo_end_marioKart_m_b.nclr"));
    switch (gEndingScene->mKind) {
        case ENDING_KIND_STAFFROLL:
            Gfx_ReadCharGraphicsV2(&gEndingScene->mLogoEndMarioKartMBAndThanksYouMBNcgrs[1],
                         FindFileBuffer_K2D_LOC_R2D_R2L_from_thumb("thanksYou_m_b_00.ncgr"));
            MaybeReadScreenBlock_0(&gEndingScene->mLogoEndMarioKartMBgAndThanksYouMBgNscrs[1],
                         FindFileBuffer_K2D_LOC_R2D_R2L_from_thumb("thanksYou_m_bg_00.nscr"));
            Gfx_ReadPalette(&gEndingScene->mLogoEndMarioKartMBAndThanksYouMBNclrs[1],
                         FindFileBuffer_K2D_LOC_R2D_R2L_from_thumb("thanksYou_m_b_00.nclr"));
            break;
        case ENDING_KIND_STAFFROLL_TRUE:
            Gfx_ReadCharGraphicsV2(&gEndingScene->mLogoEndMarioKartMBAndThanksYouMBNcgrs[1],
                         FindFileBuffer_K2D_LOC_R2D_R2L_from_thumb("thanksYou_m_b_01_2.ncgr"));
            MaybeReadScreenBlock_0(&gEndingScene->mLogoEndMarioKartMBgAndThanksYouMBgNscrs[1],
                         FindFileBuffer_K2D_LOC_R2D_R2L_from_thumb("thanksYou_m_bg_01_2.nscr"));
            Gfx_ReadPalette(&gEndingScene->mLogoEndMarioKartMBAndThanksYouMBNclrs[1],
                         FindFileBuffer_K2D_LOC_R2D_R2L_from_thumb("thanksYou_m_b_01.nclr"));
            break;
    }
    Gfx_ReadCharGraphicsV2(&gEndingScene->mEndAllRightsReservedSBAndLogoEndNintendoSBNcgrs[0],
                 FindFileBuffer_K2D_LOC_R2D_R2L_from_thumb("end_allRightsReserved_s_b.ncgr"));
    MaybeReadScreenBlock_0(&gEndingScene->mEndAllRightsReservedSBgAndLogoEndNintendoSBgNscrs[0],
                 FindFileBuffer_K2D_LOC_R2D_R2L_from_thumb("end_allRightsReserved_s_bg.nscr"));
    Gfx_ReadPalette(&gEndingScene->mEndAllRightsReservedSBAndLogoEndNintendoSBNclrs[0],
                 FindFileBuffer_K2D_LOC_R2D_R2L_from_thumb("end_allRightsReserved_s_b.nclr"));
    Gfx_ReadCharGraphicsV2(&gEndingScene->mEndAllRightsReservedSBAndLogoEndNintendoSBNcgrs[1],
                 FindFileBuffer_K2D_LOC_R2D_R2L_from_thumb("logo_end_Nintendo_s_b.ncgr"));
    MaybeReadScreenBlock_0(&gEndingScene->mEndAllRightsReservedSBgAndLogoEndNintendoSBgNscrs[1],
                 FindFileBuffer_K2D_LOC_R2D_R2L_from_thumb("logo_end_Nintendo_s_bg.nscr"));
    Gfx_ReadPalette(&gEndingScene->mEndAllRightsReservedSBAndLogoEndNintendoSBNclrs[1],
                 FindFileBuffer_K2D_LOC_R2D_R2L_from_thumb("logo_end_Nintendo_s_b.nclr"));
    LoadCellBankFrom(&gEndingScene->mThanksYouMNcer, FindFileBuffer_K2D_LOC_R2D_R2L_from_thumb("thanksYou_m.nce.ncer"));
    Gfx_ReadPalette(&gEndingScene->mThanksYouMO00Nclr, FindFileBuffer_K2D_LOC_R2D_R2L_from_thumb("thanksYou_m_o_00.nclr"));
    switch (gEndingScene->mKind) {
        case ENDING_KIND_STAFFROLL:
            gEndingScene->mEndingThanksBncl = FindFileBuffer_K2D_LOC_R2D_R2L_from_thumb("ending_thanks_00.bncl");
            gEndingScene->mEndingThanksBnll = FindFileBuffer_K2D_LOC_R2D_R2L_from_thumb("ending_thanks_00.bnll");
            break;
        case ENDING_KIND_STAFFROLL_TRUE:
            gEndingScene->mEndingThanksBncl = FindFileBuffer_K2D_LOC_R2D_R2L_from_thumb("ending_thanks_01.bncl");
            gEndingScene->mEndingThanksBnll = FindFileBuffer_K2D_LOC_R2D_R2L_from_thumb("ending_thanks_01.bnll");
            break;
    }
    if (g_GlobalB488->mStaffRollEndedEarly != 0) {
        QueueEndingSceneIndex1Data();
    } else {
        QueueEndingSceneNcgrNscrNclr(0);
    }
    AllocateReserveTEQSub(0xe, 0, gEndingScene->mThanksYouMO00Nclr->mData,
                                       gEndingScene->mThanksYouMO00Nclr->mDataSize);
}

void AdvanceEndingSceneWaitFadeIn(void) {
    if (Bright_IsBothScreensFadedIn() != 0) {
        if (g_GlobalB488->mStaffRollEndedEarly != 0) {
            gEndingScene->mNextState = ENDING_SCENE_STATE_WAIT_INPUT;
            g_GlobalB488->mStaffRollEndedEarly = 0;
            return;
        }
        gEndingScene->mNextState = ENDING_SCENE_STATE_SHOW_LOGO;
    }
}

void AdvanceEndingSceneShowLogo(void) {
    gEndingScene->mStateFrames++;
    if (gEndingScene->mStateFrames > gEndingSceneStateTable[gEndingScene->mState]) {
        gEndingScene->mNextState = ENDING_SCENE_STATE_FADE_OUT;
        gEndingScene->mStateFrames = 0;
        Bright_FadeOutBlack(gEndingSceneStateTable[ENDING_SCENE_STATE_FADE_OUT]);
    }
}

void AdvanceEndingSceneFadeOut(void) {
    int fadesFaded;
    fadesFaded = Bright_IsBothScreensFadedOut();
    if (fadesFaded != 0) {
        gEndingScene->mNextState = ENDING_SCENE_STATE_HOLD_FADED;
    }
}

void AdvanceEndingSceneHoldFaded(void) {
    EndingScene *endingScene;

    gEndingScene->mStateFrames++;
    endingScene = gEndingScene;
    if (endingScene->mStateFrames > gEndingSceneStateTable[ENDING_SCENE_STATE_HOLD_FADED]) {
        endingScene->mNextState = ENDING_SCENE_STATE_FADE_IN;
        gEndingScene->mStateFrames = 0;
        StartFadeToClearNegative(gEndingSceneStateTable[ENDING_SCENE_STATE_FADE_IN]);
        QueueEndingSceneIndex1Data();
    }
}

void AdvanceEndingSceneFadeIn(void) {
    int fadesClear;
    fadesClear = Bright_IsBothScreensFadedIn();
    if (fadesClear != 0) {
        gEndingScene->mNextState = ENDING_SCENE_STATE_WAIT_INPUT;
    }
}

void AdvanceEndingSceneWaitInput(void) {
    InputSlotIndex slotIndex = INPUT_SLOT_PAD_OR_PARTICIPANT;
    u16 keyPressed;
    BOOL touchBegan;
    BOOL recentlyLost;
    u16 hasPair;

    gEndingScene->mStateFrames++;
    if (gEndingScene->mStateFrames > gEndingSceneStateTable[gEndingScene->mState]) {
        gEndingScene->mStateFrames = gEndingSceneStateTable[gEndingScene->mState];
        keyPressed = g_GlobalCYT[slotIndex].mPressedBits & PAD_KEYS_NO_DIRECTION_OR_SHOULDER;
        if (keyPressed == 0) {
            touchBegan = FALSE;
            recentlyLost = FALSE;
            hasPair = g_GlobalCYT[slotIndex].mPair.mHasPair;
            if (hasPair == 0 && g_GlobalCYT[slotIndex].mPair.mNoPairCount < INPUT_NO_PAIR_BRIEF_FRAMES) {
                recentlyLost = TRUE;
            }
            if (recentlyLost == FALSE && g_GlobalCYT[slotIndex].mPair.mPrevHasPair == 0 && hasPair != 0) {
                touchBegan = TRUE;
            }
            if (touchBegan == FALSE) {
                return;
            }
        }
        gEndingScene->mNextState = ENDING_SCENE_STATE_FADE_OUT_TO_LEAVE;
        gEndingScene->mStateFrames = 0;
        Bright_FadeOutBlack(gEndingSceneStateTable[ENDING_SCENE_STATE_FADE_OUT_TO_LEAVE]);
    }
}

void AdvanceEndingSceneFadeOutToLeave(void) {
    if (Bright_IsBothScreensFadedOut() != 0) {
        gEndingScene->mNextState = ENDING_SCENE_STATE_HOLD_THEN_LEAVE;
        gEndingScene->mStateFrames = 0;
    }
}

void AdvanceEndingSceneHoldThenLeave(void) {
    gEndingScene->mStateFrames++;
    if (gEndingScene->mStateFrames > gEndingSceneStateTable[ENDING_SCENE_STATE_HOLD_THEN_LEAVE]) {
        gEndingScene->mNextScene = 0;
    }
}

void AdvanceEndingScene(void) {
    gEndingScene->mState = gEndingScene->mNextState;
    OamBuffer_ResetValues16_from_thumb(gEndingScene->mMainOam, NULL);
    switch (gEndingScene->mState) {
        case ENDING_SCENE_STATE_WAIT_FADE_IN:
            AdvanceEndingSceneWaitFadeIn();
            break;
        case ENDING_SCENE_STATE_SHOW_LOGO:
            AdvanceEndingSceneShowLogo();
            break;
        case ENDING_SCENE_STATE_FADE_OUT:
            AdvanceEndingSceneFadeOut();
            break;
        case ENDING_SCENE_STATE_HOLD_FADED:
            AdvanceEndingSceneHoldFaded();
            break;
        case ENDING_SCENE_STATE_FADE_IN:
            AdvanceEndingSceneFadeIn();
            break;
        case ENDING_SCENE_STATE_WAIT_INPUT:
            AdvanceEndingSceneWaitInput();
            break;
        case ENDING_SCENE_STATE_FADE_OUT_TO_LEAVE:
            AdvanceEndingSceneFadeOutToLeave();
            break;
        case ENDING_SCENE_STATE_HOLD_THEN_LEAVE:
            AdvanceEndingSceneHoldThenLeave();
            break;
    }
    DrawLayoutTable(gEndingScene->mEndingThanksBncl, gEndingScene->mThanksYouMNcer, gEndingScene->mEndingThanksBnll,
                    gEndingScene->mMainOam, gEndingScene->mEndingThanksTable);
    OamBuffer_SomeFn2_from_thumb(gEndingScene->mMainOam, NULL);
}

void WriteEndingSceneRegisters(void) {
    u32 displayBits;

    if (gEndingScene->mIndex1Queued != FALSE) {
        displayBits = (reg_GX_DISPCNT & REG_GX_DISPCNT_DISPLAY_MASK) >> 8;
        reg_GX_DISPCNT = (reg_GX_DISPCNT & ~REG_GX_DISPCNT_DISPLAY_MASK) | ((displayBits | 0x10) << 8);
    }
    CopyOamBuffersToMemory_from_thumb(gEndingScene->mMainOam, NULL);
}

void SetStaffRollEndedEarly(void) {
    g_GlobalB488->mStaffRollEndedEarly = 1;
}

s32 GetStaffRollEndedEarly(void) {
    return g_GlobalB488->mStaffRollEndedEarly;
}

int GetEndingSceneNextScene(void) {
    return gEndingScene->mNextScene;
}
