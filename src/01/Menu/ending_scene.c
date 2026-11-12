#include "01/Menu/ending_scene.h"
#include "registers.h"
#include "01/code_0219e000.h"
#include "01/code_0219f000.h"
#include "01/unk_021a6000.h"
#include "01/unk_021ca000.h"
#include "Main/System/heap.h"
#include "Main/Scene/display_settings.h"
#include "Main/Graphics/oam_upload.h"
#include "Main/Race/data_021759c0.h"
#include "tp.h"

const u16 gEndingSceneStateTable[8] = {0, 0xf0, 0x78, 0x1e, 0x3c, 0xb4, 0x78, 0x3c};
EndingScene *gEndingScene;

void CreateEndingScene(void *heap) {
    void *bmgEntry;

    gEndingScene = HeapAlloc(heap, 0x470);
    gEndingScene->mHeap = heap;
    gEndingScene->mUnk_01c = CreateSceneDisplaySettings(heap);
    gEndingScene->mNextScene = -1;
    gEndingScene->mState = 0;
    gEndingScene->mNextState = gEndingScene->mState;
    gEndingScene->mStateFrames = 0;
    if (gRaceSetup->mCourseId == COURSE_ID_STAFFROLLTRUE) {
        gEndingScene->mKind = 1;
    } else {
        gEndingScene->mKind = 0;
    }
    gEndingScene->mIndex1Queued = FALSE;
    gEndingScene->mCommonMessages = FindFileInLoadedArchives("common.bmg");
    InitEndingSceneDisplay();
    LoadAndQueueEndingSceneData();
    ResetOamLists(gEndingScene->mMainOam, NULL);
    InitLayoutTable(gEndingScene->mHeap, gEndingScene->mEndingThanksBncl, gEndingScene->mEndingThanksBnll,
                    &gEndingScene->mEndingThanksTable);
    bmgEntry = NULL;
    gEndingScene->mEndingThanksTable->mVisible = 0;
    {
        u16 table[2][2] = {{200, 24}, {200, 24}};

        switch (gEndingScene->mKind) {
            case 0:
                bmgEntry = GetBmgEntry(gEndingScene->mCommonMessages, 0x77);
                break;
            case 1:
                bmgEntry = GetBmgEntry(gEndingScene->mCommonMessages, 0x78);
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
    reg_GX_DISPCNT = (reg_GX_DISPCNT & 0xffffe0ff) | 0x100;
    reg_GXS_DB_DISPCNT = (reg_GXS_DB_DISPCNT & 0xffffe0ff) | 0x100;
    reg_G2_BG0CNT = (reg_G2_BG0CNT & ~3) | 3;
    reg_G2_BG0CNT = (reg_G2_BG0CNT & 0x43) | 0x1f00;
    reg_G2S_DB_BG0CNT = (reg_G2S_DB_BG0CNT & 0x43) | 0x1000;
    reg_G2_BG2OFS = 0;
    reg_G2S_DB_BG0OFS = 0;
    *(vu16 *) 0x5000000 = 0;
    *(vu16 *) 0x5000400 = 0;
}

void QueueEndingSceneNcgrNscrNclr(int i) {
    NNS_GfdRegisterNewVramTransferTask(4, 0, gEndingScene->mLogoEndMarioKartMBAndThanksYouMBNcgrs[i]->mData,
                                       gEndingScene->mLogoEndMarioKartMBAndThanksYouMBNcgrs[i]->mDataSize);
    NNS_GfdRegisterNewVramTransferTask(8, 0, gEndingScene->mLogoEndMarioKartMBgAndThanksYouMBgNscrs[i]->mData,
                                       gEndingScene->mLogoEndMarioKartMBgAndThanksYouMBgNscrs[i]->mDataSize);
    NNS_GfdRegisterNewVramTransferTask(0xf, 0, gEndingScene->mLogoEndMarioKartMBAndThanksYouMBNclrs[i]->mData,
                                       gEndingScene->mLogoEndMarioKartMBAndThanksYouMBNclrs[i]->mDataSize);
    NNS_GfdRegisterNewVramTransferTask(0x14, 0,
                                       gEndingScene->mEndAllRightsReservedSBAndLogoEndNintendoSBNcgrs[i]->mData,
                                       gEndingScene->mEndAllRightsReservedSBAndLogoEndNintendoSBNcgrs[i]->mDataSize);
    NNS_GfdRegisterNewVramTransferTask(0x18, 0,
                                       gEndingScene->mEndAllRightsReservedSBgAndLogoEndNintendoSBgNscrs[i]->mData,
                                       gEndingScene->mEndAllRightsReservedSBgAndLogoEndNintendoSBgNscrs[i]->mDataSize);
    NNS_GfdRegisterNewVramTransferTask(0x1f, 0,
                                       gEndingScene->mEndAllRightsReservedSBAndLogoEndNintendoSBNclrs[i]->mData,
                                       gEndingScene->mEndAllRightsReservedSBAndLogoEndNintendoSBNclrs[i]->mDataSize);
}

void QueueEndingSceneIndex1Data(void) {
    reg_G2_BG0CNT = reg_G2_BG0CNT & 0x43 | 0x00001f80u;
    QueueEndingSceneNcgrNscrNclr(1);
    gEndingScene->mIndex1Queued = TRUE;
}

void LoadAndQueueEndingSceneData(void) {
#ifdef version_EUR
    LoadNcgrData(&gEndingScene->mUnk_038[0], FindSceneFile("logo_end_marioKart_m_b_02.ncgr"));
    LoadNscrData(&gEndingScene->mUnk_040[0], FindSceneFile("logo_end_marioKart_m_bg_02.nscr"));
#else
    LoadNcgrData(&gEndingScene->mLogoEndMarioKartMBAndThanksYouMBNcgrs[0],
                 FindSceneFile("logo_end_marioKart_m_b_01.ncgr"));
    LoadNscrData(&gEndingScene->mLogoEndMarioKartMBgAndThanksYouMBgNscrs[0],
                 FindSceneFile("logo_end_marioKart_m_bg_01.nscr"));
#endif
    LoadNclrData(&gEndingScene->mLogoEndMarioKartMBAndThanksYouMBNclrs[0],
                 FindSceneFile("logo_end_marioKart_m_b.nclr"));
    switch (gEndingScene->mKind) {
        case 0:
            LoadNcgrData(&gEndingScene->mLogoEndMarioKartMBAndThanksYouMBNcgrs[1],
                         FindSceneFile("thanksYou_m_b_00.ncgr"));
            LoadNscrData(&gEndingScene->mLogoEndMarioKartMBgAndThanksYouMBgNscrs[1],
                         FindSceneFile("thanksYou_m_bg_00.nscr"));
            LoadNclrData(&gEndingScene->mLogoEndMarioKartMBAndThanksYouMBNclrs[1],
                         FindSceneFile("thanksYou_m_b_00.nclr"));
            break;
        case 1:
            LoadNcgrData(&gEndingScene->mLogoEndMarioKartMBAndThanksYouMBNcgrs[1],
                         FindSceneFile("thanksYou_m_b_01_2.ncgr"));
            LoadNscrData(&gEndingScene->mLogoEndMarioKartMBgAndThanksYouMBgNscrs[1],
                         FindSceneFile("thanksYou_m_bg_01_2.nscr"));
            LoadNclrData(&gEndingScene->mLogoEndMarioKartMBAndThanksYouMBNclrs[1],
                         FindSceneFile("thanksYou_m_b_01.nclr"));
            break;
    }
    LoadNcgrData(&gEndingScene->mEndAllRightsReservedSBAndLogoEndNintendoSBNcgrs[0],
                 FindSceneFile("end_allRightsReserved_s_b.ncgr"));
    LoadNscrData(&gEndingScene->mEndAllRightsReservedSBgAndLogoEndNintendoSBgNscrs[0],
                 FindSceneFile("end_allRightsReserved_s_bg.nscr"));
    LoadNclrData(&gEndingScene->mEndAllRightsReservedSBAndLogoEndNintendoSBNclrs[0],
                 FindSceneFile("end_allRightsReserved_s_b.nclr"));
    LoadNcgrData(&gEndingScene->mEndAllRightsReservedSBAndLogoEndNintendoSBNcgrs[1],
                 FindSceneFile("logo_end_Nintendo_s_b.ncgr"));
    LoadNscrData(&gEndingScene->mEndAllRightsReservedSBgAndLogoEndNintendoSBgNscrs[1],
                 FindSceneFile("logo_end_Nintendo_s_bg.nscr"));
    LoadNclrData(&gEndingScene->mEndAllRightsReservedSBAndLogoEndNintendoSBNclrs[1],
                 FindSceneFile("logo_end_Nintendo_s_b.nclr"));
    LoadNcerData(&gEndingScene->mThanksYouMNcer, FindSceneFile("thanksYou_m.nce.ncer"));
    LoadNclrData(&gEndingScene->mThanksYouMO00Nclr, FindSceneFile("thanksYou_m_o_00.nclr"));
    switch (gEndingScene->mKind) {
        case 0:
            gEndingScene->mEndingThanksBncl = FindSceneFile("ending_thanks_00.bncl");
            gEndingScene->mEndingThanksBnll = FindSceneFile("ending_thanks_00.bnll");
            break;
        case 1:
            gEndingScene->mEndingThanksBncl = FindSceneFile("ending_thanks_01.bncl");
            gEndingScene->mEndingThanksBnll = FindSceneFile("ending_thanks_01.bnll");
            break;
    }
    if (gMenuShared->mStaffRollEndedEarly != 0) {
        QueueEndingSceneIndex1Data();
    } else {
        QueueEndingSceneNcgrNscrNclr(0);
    }
    NNS_GfdRegisterNewVramTransferTask(0xe, 0, gEndingScene->mThanksYouMO00Nclr->mData,
                                       gEndingScene->mThanksYouMO00Nclr->mDataSize);
}

void AdvanceEndingSceneState0(void) {
    if (AreBrightnessFadesClear() != 0) {
        if (gMenuShared->mStaffRollEndedEarly != 0) {
            gEndingScene->mNextState = 5;
            gMenuShared->mStaffRollEndedEarly = 0;
            return;
        }
        gEndingScene->mNextState = 1;
    }
}

void AdvanceEndingSceneState1(void) {
    gEndingScene->mStateFrames++;
    if (gEndingScene->mStateFrames > gEndingSceneStateTable[gEndingScene->mState]) {
        gEndingScene->mNextState = 2;
        gEndingScene->mStateFrames = 0;
        StartFadeToFadedNegative(gEndingSceneStateTable[2]);
    }
}

void AdvanceEndingSceneState2(void) {
    int fadesFaded;
    fadesFaded = AreBrightnessFadesFaded();
    if (fadesFaded != 0) {
        gEndingScene->mNextState = 3;
    }
}

void AdvanceEndingSceneState3(void) {
    EndingScene *endingScene;

    gEndingScene->mStateFrames++;
    endingScene = gEndingScene;
    if (endingScene->mStateFrames > gEndingSceneStateTable[3]) {
        endingScene->mNextState = 4;
        gEndingScene->mStateFrames = 0;
        StartFadeToClearNegative(gEndingSceneStateTable[4]);
        QueueEndingSceneIndex1Data();
    }
}

void AdvanceEndingSceneState4(void) {
    int fadesClear;
    fadesClear = AreBrightnessFadesClear();
    if (fadesClear != 0) {
        gEndingScene->mNextState = 5;
    }
}

void AdvanceEndingSceneState5(void) {
    InputSlotIndex slotIndex = UNK_02175628_INDEX_8;
    u16 keyPressed;
    BOOL touchBegan;
    BOOL recentlyLost;
    u16 hasPair;

    gEndingScene->mStateFrames++;
    if (gEndingScene->mStateFrames > gEndingSceneStateTable[gEndingScene->mState]) {
        gEndingScene->mStateFrames = gEndingSceneStateTable[gEndingScene->mState];
        keyPressed = gInputSlots[slotIndex].mPressedBits & 0xc0f;
        if (keyPressed == 0) {
            touchBegan = FALSE;
            recentlyLost = FALSE;
            hasPair = gInputSlots[slotIndex].mPair.mHasPair;
            if (hasPair == 0 && gInputSlots[slotIndex].mPair.mNoPairCount < 5) {
                recentlyLost = TRUE;
            }
            if (recentlyLost == FALSE && gInputSlots[slotIndex].mPair.mPrevHasPair == 0 && hasPair != 0) {
                touchBegan = TRUE;
            }
            if (touchBegan == FALSE) {
                return;
            }
        }
        gEndingScene->mNextState = 6;
        gEndingScene->mStateFrames = 0;
        StartFadeToFadedNegative(gEndingSceneStateTable[6]);
    }
}

void AdvanceEndingSceneState6(void) {
    if (AreBrightnessFadesFaded() != 0) {
        gEndingScene->mNextState = 7;
        gEndingScene->mStateFrames = 0;
    }
}

void AdvanceEndingSceneState7(void) {
    gEndingScene->mStateFrames++;
    if (gEndingScene->mStateFrames > gEndingSceneStateTable[7]) {
        gEndingScene->mNextScene = 0;
    }
}

void AdvanceEndingScene(void) {
    gEndingScene->mState = gEndingScene->mNextState;
    ClearOamListCounts(gEndingScene->mMainOam, NULL);
    switch (gEndingScene->mState) {
        case 0:
            AdvanceEndingSceneState0();
            break;
        case 1:
            AdvanceEndingSceneState1();
            break;
        case 2:
            AdvanceEndingSceneState2();
            break;
        case 3:
            AdvanceEndingSceneState3();
            break;
        case 4:
            AdvanceEndingSceneState4();
            break;
        case 5:
            AdvanceEndingSceneState5();
            break;
        case 6:
            AdvanceEndingSceneState6();
            break;
        case 7:
            AdvanceEndingSceneState7();
            break;
    }
    DrawLayoutTable(gEndingScene->mEndingThanksBncl, gEndingScene->mThanksYouMNcer, gEndingScene->mEndingThanksBnll,
                    gEndingScene->mMainOam, gEndingScene->mEndingThanksTable);
    HideUnusedOams(gEndingScene->mMainOam, NULL);
}

void WriteEndingSceneRegisters(void) {
    u32 displayBits;

    if (gEndingScene->mIndex1Queued != FALSE) {
        displayBits = (reg_GX_DISPCNT & 0x1f00) >> 8;
        reg_GX_DISPCNT = (reg_GX_DISPCNT & 0xffffe0ff) | ((displayBits | 0x10) << 8);
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
