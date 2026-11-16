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

    gEndingScene = HeapAlloc(heap, sizeof(EndingScene));
    gEndingScene->mHeap = heap;
    gEndingScene->mSceneDisplaySettings = CreateSceneDisplaySettings(heap);
    gEndingScene->mNextScene = -1;
    gEndingScene->mState = ENDING_SCENE_STATE_WAIT_FADE_IN;
    gEndingScene->mNextState = gEndingScene->mState;
    gEndingScene->mStateFrames = 0;
    if (gRaceSetup->mCourseId == COURSE_ID_STAFFROLLTRUE) {
        gEndingScene->mKind = ENDING_KIND_STAFFROLL_TRUE;
    } else {
        gEndingScene->mKind = ENDING_KIND_STAFFROLL;
    }
    gEndingScene->mIndex1Queued = FALSE;
    gEndingScene->mCommonMessages = FindFileInLoadedArchives("common.bmg");
    InitEndingSceneDisplay();
    LoadAndQueueEndingSceneData();
    ResetOamLists(gEndingScene->mMainOam, NULL);
    InitLayoutTable(gEndingScene->mHeap, gEndingScene->mEndingThanksCellLayout, gEndingScene->mEndingThanksLabelLayout,
                    &gEndingScene->mEndingThanksTable);
    bmgEntry = NULL;
    gEndingScene->mEndingThanksTable->mVisible = 0;
    {
        u16 canvasSizes[2][2] = {{200, 24}, {200, 24}};

        switch (gEndingScene->mKind) {
            case ENDING_KIND_STAFFROLL:
                bmgEntry = GetBmgEntry(gEndingScene->mCommonMessages, 0x77);
                break;
            case ENDING_KIND_STAFFROLL_TRUE:
                bmgEntry = GetBmgEntry(gEndingScene->mCommonMessages, 0x78);
                break;
        }
        InitLabelCanvas(gEndingScene->mHeap, 0, gEndingScene->mEndingThanksLabelLayout, canvasSizes[gEndingScene->mKind][0],
                        canvasSizes[gEndingScene->mKind][1], 0, gEndingScene->mThanksYouMCells,
                        gEndingScene->mEndingThanksCellLayout, gEndingScene->mEndingThanksTable, 0x8000);
        PrintLabelLayoutTextNoFixedAdvance(0, 0, gEndingScene->mEndingThanksLabelLayout, bmgEntry,
                                           gEndingScene->mEndingThanksCellLayout, gEndingScene->mEndingThanksTable);
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
    NNS_GfdRegisterNewVramTransferTask(4, 0, gEndingScene->mLogoAndThanksYouMBChars[i]->mData,
                                       gEndingScene->mLogoAndThanksYouMBChars[i]->mDataSize);
    NNS_GfdRegisterNewVramTransferTask(8, 0, gEndingScene->mLogoAndThanksYouMBgScreenMaps[i]->mData,
                                       gEndingScene->mLogoAndThanksYouMBgScreenMaps[i]->mDataSize);
    NNS_GfdRegisterNewVramTransferTask(0xf, 0, gEndingScene->mLogoAndThanksYouMBPalettes[i]->mData,
                                       gEndingScene->mLogoAndThanksYouMBPalettes[i]->mDataSize);
    NNS_GfdRegisterNewVramTransferTask(0x14, 0,
                                       gEndingScene->mAllRightsAndNintendoSBChars[i]->mData,
                                       gEndingScene->mAllRightsAndNintendoSBChars[i]->mDataSize);
    NNS_GfdRegisterNewVramTransferTask(0x18, 0,
                                       gEndingScene->mAllRightsAndNintendoSBgScreenMaps[i]->mData,
                                       gEndingScene->mAllRightsAndNintendoSBgScreenMaps[i]->mDataSize);
    NNS_GfdRegisterNewVramTransferTask(0x1f, 0,
                                       gEndingScene->mAllRightsAndNintendoSBPalettes[i]->mData,
                                       gEndingScene->mAllRightsAndNintendoSBPalettes[i]->mDataSize);
}

void QueueEndingSceneIndex1Data(void) {
    reg_G2_BG0CNT = reg_G2_BG0CNT & (REG_G2_BG0CNT_PRIORITY_MASK | REG_G2_BG0CNT_MOSAIC_MASK) | 0x00001f80u;
    QueueEndingSceneNcgrNscrNclr(1);
    gEndingScene->mIndex1Queued = TRUE;
}

void LoadAndQueueEndingSceneData(void) {
#ifdef version_EUR
    LoadNcgrData(&gEndingScene->mLogoEndMarioKartMBAndThanksYouMBNcgrs[0],
                 FindSceneFile("logo_end_marioKart_m_b_02.ncgr"));
    LoadNscrData(&gEndingScene->mLogoEndMarioKartMBgAndThanksYouMBgNscrs[0],
                 FindSceneFile("logo_end_marioKart_m_bg_02.nscr"));
#else
    LoadNcgrData(&gEndingScene->mLogoAndThanksYouMBChars[0],
                 FindSceneFile("logo_end_marioKart_m_b_01.ncgr"));
    LoadNscrData(&gEndingScene->mLogoAndThanksYouMBgScreenMaps[0],
                 FindSceneFile("logo_end_marioKart_m_bg_01.nscr"));
#endif
    LoadNclrData(&gEndingScene->mLogoAndThanksYouMBPalettes[0],
                 FindSceneFile("logo_end_marioKart_m_b.nclr"));
    switch (gEndingScene->mKind) {
        case ENDING_KIND_STAFFROLL:
            LoadNcgrData(&gEndingScene->mLogoAndThanksYouMBChars[1],
                         FindSceneFile("thanksYou_m_b_00.ncgr"));
            LoadNscrData(&gEndingScene->mLogoAndThanksYouMBgScreenMaps[1],
                         FindSceneFile("thanksYou_m_bg_00.nscr"));
            LoadNclrData(&gEndingScene->mLogoAndThanksYouMBPalettes[1],
                         FindSceneFile("thanksYou_m_b_00.nclr"));
            break;
        case ENDING_KIND_STAFFROLL_TRUE:
            LoadNcgrData(&gEndingScene->mLogoAndThanksYouMBChars[1],
                         FindSceneFile("thanksYou_m_b_01_2.ncgr"));
            LoadNscrData(&gEndingScene->mLogoAndThanksYouMBgScreenMaps[1],
                         FindSceneFile("thanksYou_m_bg_01_2.nscr"));
            LoadNclrData(&gEndingScene->mLogoAndThanksYouMBPalettes[1],
                         FindSceneFile("thanksYou_m_b_01.nclr"));
            break;
    }
    LoadNcgrData(&gEndingScene->mAllRightsAndNintendoSBChars[0],
                 FindSceneFile("end_allRightsReserved_s_b.ncgr"));
    LoadNscrData(&gEndingScene->mAllRightsAndNintendoSBgScreenMaps[0],
                 FindSceneFile("end_allRightsReserved_s_bg.nscr"));
    LoadNclrData(&gEndingScene->mAllRightsAndNintendoSBPalettes[0],
                 FindSceneFile("end_allRightsReserved_s_b.nclr"));
    LoadNcgrData(&gEndingScene->mAllRightsAndNintendoSBChars[1],
                 FindSceneFile("logo_end_Nintendo_s_b.ncgr"));
    LoadNscrData(&gEndingScene->mAllRightsAndNintendoSBgScreenMaps[1],
                 FindSceneFile("logo_end_Nintendo_s_bg.nscr"));
    LoadNclrData(&gEndingScene->mAllRightsAndNintendoSBPalettes[1],
                 FindSceneFile("logo_end_Nintendo_s_b.nclr"));
    LoadNcerData(&gEndingScene->mThanksYouMCells, FindSceneFile("thanksYou_m.nce.ncer"));
    LoadNclrData(&gEndingScene->mThanksYouMO00Palette, FindSceneFile("thanksYou_m_o_00.nclr"));
    switch (gEndingScene->mKind) {
        case ENDING_KIND_STAFFROLL:
            gEndingScene->mEndingThanksCellLayout = FindSceneFile("ending_thanks_00.bncl");
            gEndingScene->mEndingThanksLabelLayout = FindSceneFile("ending_thanks_00.bnll");
            break;
        case ENDING_KIND_STAFFROLL_TRUE:
            gEndingScene->mEndingThanksCellLayout = FindSceneFile("ending_thanks_01.bncl");
            gEndingScene->mEndingThanksLabelLayout = FindSceneFile("ending_thanks_01.bnll");
            break;
    }
    if (gMenuShared->mStaffRollEndedEarly != 0) {
        QueueEndingSceneIndex1Data();
    } else {
        QueueEndingSceneNcgrNscrNclr(0);
    }
    NNS_GfdRegisterNewVramTransferTask(0xe, 0, gEndingScene->mThanksYouMO00Palette->mData,
                                       gEndingScene->mThanksYouMO00Palette->mDataSize);
}

void AdvanceEndingSceneWaitFirstFadeIn(void) {
    if (AreBrightnessFadesClear() != 0) {
        if (gMenuShared->mStaffRollEndedEarly != 0) {
            gEndingScene->mNextState = ENDING_SCENE_STATE_WAIT_INPUT;
            gMenuShared->mStaffRollEndedEarly = 0;
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
        StartFadeToFadedNegative(gEndingSceneStateTable[ENDING_SCENE_STATE_FADE_OUT]);
    }
}

void AdvanceEndingSceneFadeOut(void) {
    int fadesFaded;
    fadesFaded = AreBrightnessFadesFaded();
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
    fadesClear = AreBrightnessFadesClear();
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
        keyPressed = gInputSlots[slotIndex].mPressedBits & PAD_KEYS_A_B_X_Y_SELECT_START;
        if (keyPressed == 0) {
            touchBegan = FALSE;
            recentlyLost = FALSE;
            hasPair = gInputSlots[slotIndex].mPair.mHasPair;
            if (hasPair == 0 && gInputSlots[slotIndex].mPair.mNoPairCount < INPUT_NO_PAIR_BRIEF_FRAMES) {
                recentlyLost = TRUE;
            }
            if (recentlyLost == FALSE && gInputSlots[slotIndex].mPair.mPrevHasPair == 0 && hasPair != 0) {
                touchBegan = TRUE;
            }
            if (touchBegan == FALSE) {
                return;
            }
        }
        gEndingScene->mNextState = ENDING_SCENE_STATE_FADE_OUT_TO_LEAVE;
        gEndingScene->mStateFrames = 0;
        StartFadeToFadedNegative(gEndingSceneStateTable[ENDING_SCENE_STATE_FADE_OUT_TO_LEAVE]);
    }
}

void AdvanceEndingSceneFadeOutToLeave(void) {
    if (AreBrightnessFadesFaded() != 0) {
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
    ClearOamListCounts(gEndingScene->mMainOam, NULL);
    switch (gEndingScene->mState) {
        case ENDING_SCENE_STATE_WAIT_FADE_IN:
            AdvanceEndingSceneWaitFirstFadeIn();
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
    DrawLayoutTable(gEndingScene->mEndingThanksCellLayout, gEndingScene->mThanksYouMCells, gEndingScene->mEndingThanksLabelLayout,
                    gEndingScene->mMainOam, gEndingScene->mEndingThanksTable);
    HideUnusedOams(gEndingScene->mMainOam, NULL);
}

void WriteEndingSceneRegisters(void) {
    u32 displayBits;

    if (gEndingScene->mIndex1Queued != FALSE) {
        displayBits = (reg_GX_DISPCNT & REG_GX_DISPCNT_DISPLAY_MASK) >> 8;
        reg_GX_DISPCNT = (reg_GX_DISPCNT & ~REG_GX_DISPCNT_DISPLAY_MASK) | ((displayBits | 0x10) << 8);
    }
    UploadOamLists(gEndingScene->mMainOam, NULL);
}

void SetStaffRollEndedEarly(void) {
    gMenuShared->mStaffRollEndedEarly = 1;
}

s32 GetStaffRollEndedEarly(void) {
    return gMenuShared->mStaffRollEndedEarly;
}

int GetEndingSceneNextScene(void) {
    return gEndingScene->mNextScene;
}
