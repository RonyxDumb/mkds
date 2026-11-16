#include "01/code_0219e0a8.h"
#include "registers.h"
#include "01/code_0219e000.h"
#include "01/code_0219f000.h"
#include "01/unk_021a6000.h"
#include "01/unk_021ca000.h"
#include "Main/System/Heap.h"
#include "Main/Unknown/code_02036c5c.h"
#include "Main/Unknown/code_020ae5e4.h"
#include "Main/Unknown/code_02105000.h"
#include "Main/Unknown/code_02037000.h"
#include "Main/Unknown/unk_021759c0.h"

const u16 gEndingSceneStateTable[8] = {0, 0xf0, 0x78, 0x1e, 0x3c, 0xb4, 0x78, 0x3c};

EndingScene *gEndingScene;

void CreateEndingScene(void *heap) {
    void *result;

    gEndingScene = heap_alloc(heap, 0x470);
    gEndingScene->mHeap = heap;
    gEndingScene->mUnk_01c = func_021250b0(heap);
    gEndingScene->mNextScene = -1;
    gEndingScene->mState = 0;
    gEndingScene->mNextState = gEndingScene->mState;
    gEndingScene->mUnk_008 = 0;
    if (gRaceMultiConfig->mCourseId == COURSE_ID_STAFFROLLTRUE) {
        gEndingScene->mKind = 1;
    } else {
        gEndingScene->mKind = 0;
    }
    gEndingScene->mIndex1Queued = FALSE;
    gEndingScene->mCommonMessages = arc_get2dArcFile("common.bmg");
    func_ov001_0219e660();
    LoadAndQueueEndingSceneData();
    oam_clearResetBuffers(gEndingScene->mMainOam, NULL);
    jn_ui_initLayout(gEndingScene->mHeap, gEndingScene->mEndingThanksBncl, gEndingScene->mEndingThanksBnll,
                    &gEndingScene->mEndingThanksTable);
    result = NULL;
    gEndingScene->mEndingThanksTable->mVisible = 0;
    {
        u16 table[2][2] = {{200, 24}, {200, 24}};

        switch (gEndingScene->mKind) {
            case 0:
                result = jn_msg_getMessage(gEndingScene->mCommonMessages, 0x77);
                break;
            case 1:
                result = jn_msg_getMessage(gEndingScene->mCommonMessages, 0x78);
                break;
        }
        jn_ui_initLabel(gEndingScene->mHeap, 0, gEndingScene->mEndingThanksBnll, table[gEndingScene->mKind][0],
                        table[gEndingScene->mKind][1], 0, gEndingScene->mThanksYouMNcer,
                        gEndingScene->mEndingThanksBncl, gEndingScene->mEndingThanksTable, 0x8000);
        jn_ui_212426C(0, 0, gEndingScene->mEndingThanksBnll, result, gEndingScene->mEndingThanksBncl,
                      gEndingScene->mEndingThanksTable);
    }
}

void func_ov001_0219e6e0(void) {
    *&gEndingScene = 0;
}

void func_ov001_0219e660(void) {
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
    NNS_GfdRegisterNewVramTransferTask(0x14, 0, gEndingScene->mEndAllRightsReservedSBAndLogoEndNintendoSBNcgrs[i]->mData,
                    gEndingScene->mEndAllRightsReservedSBAndLogoEndNintendoSBNcgrs[i]->mDataSize);
    NNS_GfdRegisterNewVramTransferTask(0x18, 0, gEndingScene->mEndAllRightsReservedSBgAndLogoEndNintendoSBgNscrs[i]->mData,
                    gEndingScene->mEndAllRightsReservedSBgAndLogoEndNintendoSBgNscrs[i]->mDataSize);
    NNS_GfdRegisterNewVramTransferTask(0x1f, 0, gEndingScene->mEndAllRightsReservedSBAndLogoEndNintendoSBNclrs[i]->mData,
                    gEndingScene->mEndAllRightsReservedSBAndLogoEndNintendoSBNclrs[i]->mDataSize);
}

void func_ov001_0219e5a0(void) {
    reg_G2_BG0CNT = reg_G2_BG0CNT & 0x43 | 0x00001f80u;
    QueueEndingSceneNcgrNscrNclr(1);
    gEndingScene->mIndex1Queued = TRUE;
}

void LoadAndQueueEndingSceneData(void) {
#ifdef version_EUR
    g2du_unpackCharacterDataBG(&gEndingScene->mLogoEndMarioKartMBAndThanksYouMBNcgrs[0],
                 arc_getSceneArcFile("logo_end_marioKart_m_b_02.ncgr"));
    g2du_unpackScreenData(&gEndingScene->mLogoEndMarioKartMBgAndThanksYouMBgNscrs[0],
                 arc_getSceneArcFile("logo_end_marioKart_m_bg_02.nscr"));
#else
    g2du_unpackCharacterDataBG(&gEndingScene->mLogoEndMarioKartMBAndThanksYouMBNcgrs[0],
                 arc_getSceneArcFile("logo_end_marioKart_m_b_01.ncgr"));
    g2du_unpackScreenData(&gEndingScene->mLogoEndMarioKartMBgAndThanksYouMBgNscrs[0],
                 arc_getSceneArcFile("logo_end_marioKart_m_bg_01.nscr"));
#endif
    g2du_unpackPaletteData(&gEndingScene->mLogoEndMarioKartMBAndThanksYouMBNclrs[0],
                 arc_getSceneArcFile("logo_end_marioKart_m_b.nclr"));
    switch (gEndingScene->mKind) {
        case 0:
            g2du_unpackCharacterDataBG(&gEndingScene->mLogoEndMarioKartMBAndThanksYouMBNcgrs[1],
                         arc_getSceneArcFile("thanksYou_m_b_00.ncgr"));
            g2du_unpackScreenData(&gEndingScene->mLogoEndMarioKartMBgAndThanksYouMBgNscrs[1],
                         arc_getSceneArcFile("thanksYou_m_bg_00.nscr"));
            g2du_unpackPaletteData(&gEndingScene->mLogoEndMarioKartMBAndThanksYouMBNclrs[1],
                         arc_getSceneArcFile("thanksYou_m_b_00.nclr"));
            break;
        case 1:
            g2du_unpackCharacterDataBG(&gEndingScene->mLogoEndMarioKartMBAndThanksYouMBNcgrs[1],
                         arc_getSceneArcFile("thanksYou_m_b_01_2.ncgr"));
            g2du_unpackScreenData(&gEndingScene->mLogoEndMarioKartMBgAndThanksYouMBgNscrs[1],
                         arc_getSceneArcFile("thanksYou_m_bg_01_2.nscr"));
            g2du_unpackPaletteData(&gEndingScene->mLogoEndMarioKartMBAndThanksYouMBNclrs[1],
                         arc_getSceneArcFile("thanksYou_m_b_01.nclr"));
            break;
    }
    g2du_unpackCharacterDataBG(&gEndingScene->mEndAllRightsReservedSBAndLogoEndNintendoSBNcgrs[0],
                 arc_getSceneArcFile("end_allRightsReserved_s_b.ncgr"));
    g2du_unpackScreenData(&gEndingScene->mEndAllRightsReservedSBgAndLogoEndNintendoSBgNscrs[0],
                 arc_getSceneArcFile("end_allRightsReserved_s_bg.nscr"));
    g2du_unpackPaletteData(&gEndingScene->mEndAllRightsReservedSBAndLogoEndNintendoSBNclrs[0],
                 arc_getSceneArcFile("end_allRightsReserved_s_b.nclr"));
    g2du_unpackCharacterDataBG(&gEndingScene->mEndAllRightsReservedSBAndLogoEndNintendoSBNcgrs[1],
                 arc_getSceneArcFile("logo_end_Nintendo_s_b.ncgr"));
    g2du_unpackScreenData(&gEndingScene->mEndAllRightsReservedSBgAndLogoEndNintendoSBgNscrs[1],
                 arc_getSceneArcFile("logo_end_Nintendo_s_bg.nscr"));
    g2du_unpackPaletteData(&gEndingScene->mEndAllRightsReservedSBAndLogoEndNintendoSBNclrs[1],
                 arc_getSceneArcFile("logo_end_Nintendo_s_b.nclr"));
    g2du_unpackCellBankData(&gEndingScene->mThanksYouMNcer, arc_getSceneArcFile("thanksYou_m.nce.ncer"));
    g2du_unpackPaletteData(&gEndingScene->mThanksYouMO00Nclr, arc_getSceneArcFile("thanksYou_m_o_00.nclr"));
    switch (gEndingScene->mKind) {
        case 0:
            gEndingScene->mEndingThanksBncl = arc_getSceneArcFile("ending_thanks_00.bncl");
            gEndingScene->mEndingThanksBnll = arc_getSceneArcFile("ending_thanks_00.bnll");
            break;
        case 1:
            gEndingScene->mEndingThanksBncl = arc_getSceneArcFile("ending_thanks_01.bncl");
            gEndingScene->mEndingThanksBnll = arc_getSceneArcFile("ending_thanks_01.bnll");
            break;
    }
    if (gStruct217B488->mUnk_70 != 0) {
        func_ov001_0219e5a0();
    } else {
        QueueEndingSceneNcgrNscrNclr(0);
    }
    NNS_GfdRegisterNewVramTransferTask(0xe, 0, gEndingScene->mThanksYouMO00Nclr->mData, gEndingScene->mThanksYouMO00Nclr->mDataSize);
}

void AdvanceEndingSceneState0(void) {
    if (mbright_isFadedIn() != 0) {
        if (gStruct217B488->mUnk_70 != 0) {
            gEndingScene->mNextState = 5;
            gStruct217B488->mUnk_70 = 0;
            return;
        }
        gEndingScene->mNextState = 1;
    }
}

void AdvanceEndingSceneState1(void) {
    gEndingScene->mUnk_008++;
    if (gEndingScene->mUnk_008 > gEndingSceneStateTable[gEndingScene->mState]) {
        gEndingScene->mNextState = 2;
        gEndingScene->mUnk_008 = 0;
        mbright_fadeToBlack(gEndingSceneStateTable[2]);
    }
}

void AdvanceEndingSceneState2(void) {
    int v1;
    v1 = mbright_isFadedOut();
    if (v1 != 0) {
        gEndingScene->mNextState = 3;
    }
}

void AdvanceEndingSceneState3(void) {
    EndingScene *p;

    gEndingScene->mUnk_008++;
    p = gEndingScene;
    if (p->mUnk_008 > gEndingSceneStateTable[3]) {
        p->mNextState = 4;
        gEndingScene->mUnk_008 = 0;
        StartFadeToClearNegative(gEndingSceneStateTable[4]);
        func_ov001_0219e5a0();
    }
}

void AdvanceEndingSceneState4(void) {
    int v1;
    v1 = mbright_isFadedIn();
    if (v1 != 0) {
        gEndingScene->mNextState = 5;
    }
}

void AdvanceEndingSceneState5(void) {
    InputSlotIndex idx = UNK_02175628_INDEX_8;
    u16 flags;
    BOOL a;
    BOOL b;
    u16 x;

    gEndingScene->mUnk_008++;
    if (gEndingScene->mUnk_008 > gEndingSceneStateTable[gEndingScene->mState]) {
        gEndingScene->mUnk_008 = gEndingSceneStateTable[gEndingScene->mState];
        flags = gInputUnits[idx].mPressedBits & 0xc0f;
        if (flags == 0) {
            a = FALSE;
            b = FALSE;
            x = gInputUnits[idx].mHasPair;
            if (x == 0 && gInputUnits[idx].mNoPairCount < 5) {
                b = TRUE;
            }
            if (b == FALSE && gInputUnits[idx].mPrevHasPair == 0 && x != 0) {
                a = TRUE;
            }
            if (a == FALSE) {
                return;
            }
        }
        gEndingScene->mNextState = 6;
        gEndingScene->mUnk_008 = 0;
        mbright_fadeToBlack(gEndingSceneStateTable[6]);
    }
}

void AdvanceEndingSceneState6(void) {
    if (mbright_isFadedOut() != 0) {
        gEndingScene->mNextState = 7;
        gEndingScene->mUnk_008 = 0;
    }
}

void AdvanceEndingSceneState7(void) {
    gEndingScene->mUnk_008++;
    if (gEndingScene->mUnk_008 > gEndingSceneStateTable[7]) {
        gEndingScene->mNextScene = 0;
    }
}

void AdvanceEndingScene(void) {
    gEndingScene->mState = gEndingScene->mNextState;
    oam_resetBuffers(gEndingScene->mMainOam, NULL);
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
    jn_ui_renderElements(gEndingScene->mEndingThanksBncl, gEndingScene->mThanksYouMNcer, gEndingScene->mEndingThanksBnll,
                    gEndingScene->mMainOam, gEndingScene->mEndingThanksTable);
    oam_prepareBuffers(gEndingScene->mMainOam, NULL);
}

void func_ov001_0219e0d4(void) {
    u32 bits;

    if (gEndingScene->mIndex1Queued != FALSE) {
        bits = (reg_GX_DISPCNT & 0x1f00) >> 8;
        reg_GX_DISPCNT = (reg_GX_DISPCNT & 0xffffe0ff) | ((bits | 0x10) << 8);
    }
    oam_applyBuffers(gEndingScene->mMainOam, NULL);
}

void func_ov001_0219e0c4(void) {
    gStruct217B488->mUnk_70 = 1;
}

s32 func_ov001_0219e0b8(void) {
    return gStruct217B488->mUnk_70;
}

int GetEndingSceneNextScene(void) {
    return gEndingScene->mNextScene;
}
