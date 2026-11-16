#include "01/code_0219d5dc.h"
#include "registers.h"

#include "01/code_0219d000.h"
#include "01/unk_021a6000.h"
#include "Main/System/Heap.h"
#include "Main/Unknown/code_021059e0.h"
#include "Main/Unknown/code_02125f54.h"
#include "Main/Unknown/code_02056d40.h"
#include "code_0201ea58.h"
#include "code_0214a390.h"
#include "Main/Unknown/code_02037000.h"
#include "Main/Unknown/code_02125f6c.h"

OptionEmbremSelect *gOptionEmbremSelect;

void InitOptionEmbremSelect(void *a) {
    s32 i;
    OptionEmbremSelect *p;
    void *ptr;

    gOptionEmbremSelect = heap_alloc(a, 0x58);
    gOptionEmbremSelect->mUnk_30 = a;
    gOptionEmbremSelect->mState = 0;
    gOptionEmbremSelect->mNextState = 0;
    gOptionEmbremSelect->mUnk_08 = 0;
    gOptionEmbremSelect->mStateFrames = 0;
    gOptionEmbremSelect->mUnk_24 = TRUE;
    LocateAndQueueOptionEmbremSelect();
    for (i = 0; i < 2; i++) {
        jn_ui_setCellIsTranslucent(data_ov001_021a6c38[i][0], 1, gOptionEmbremSelect->mOptionEmbremSelectSNcer,
                      gOptionEmbremSelect->mOptionEmbremSelectSBncl);
    }
    oam_clearResetBuffers(GetOptionFirstBuffer(), GetOptionSecondBuffer());
    jn_ui_initLayout(a, gOptionEmbremSelect->mOptionEmbremSelectSBncl, gOptionEmbremSelect->mOptionEmbremSelectSBnll,
                    &gOptionEmbremSelect->mOptionEmbremSelectSTable);
    gOptionEmbremSelect->mOptionMessages = arc_getSceneArcFile("option.bmg");
    gOptionEmbremSelect->mCommonMessages = arc_get2dArcFile("common.bmg");
    jn_ui_initLabel(a, 0, gOptionEmbremSelect->mOptionEmbremSelectSBnll, 0xa0, 0xe, 9,
                    gOptionEmbremSelect->mOptionEmbremSelectSNcer, gOptionEmbremSelect->mOptionEmbremSelectSBncl,
                    gOptionEmbremSelect->mOptionEmbremSelectSTable, 0x4000);
    p = gOptionEmbremSelect;
    ptr = jn_msg_getMessage(p->mOptionMessages, 8);
    jn_ui_212426C(1, 0, gOptionEmbremSelect->mOptionEmbremSelectSBnll, ptr, p->mOptionEmbremSelectSBncl,
                  p->mOptionEmbremSelectSTable);
    for (i = 0; i < 2; i++) {
        gOptionEmbremSelect->mUnk_18[i].mUnk_00 = 250;
        gOptionEmbremSelect->mUnk_18[i].mUnk_02 = 0;
    }
    gOptionEmbremSelect->mUnk_0c = func_ov001_0219de38();
    gOptionEmbremSelect->mUnk_10 = gOptionEmbremSelect->mUnk_0c;
    func_ov001_0219d858();
    func_ov001_0219d810();
    gOptionEmbremSelect->mOffsetTimers[0] = 0;
    gOptionEmbremSelect->mOffsetTimers[1] = 0;
    gmenu_setSeqArcIndex(0xe);
}

void ReleaseOptionEmbremSelect(void) {
    gOptionEmbremSelect = NULL;
}

void LocateAndQueueOptionEmbremSelect(void) {
    Ncgr *a;
    Nscr *b;
    Nclr *c;

    g2du_getCharacterDataBG(&a, arc_getSceneArcFile(gOptionTopMenuMBNcgrName));
    g2du_getScreenData(&b, arc_getSceneArcFile(gOptionTopMenuMNscrName));
    g2du_getPaletteData(&c, arc_getSceneArcFile(gOptionTopMenuMBNclrName));
    gOptionEmbremSelect->mOptionEmbremSelectSBncl = arc_getSceneArcFile(gOptionEmbremSelectSBnclName);
    gOptionEmbremSelect->mOptionEmbremSelectSBnbl = arc_getSceneArcFile(gOptionEmbremSelectSBnblName);
    gOptionEmbremSelect->mOptionEmbremSelectSBnll = arc_getSceneArcFile(gOptionEmbremSelectSBnllName);
    g2du_getCharacterData(&gOptionEmbremSelect->mOptionEmbremSelectSNcgr, arc_getSceneArcFile(gOptionEmbremSelectSNcgrName));
    g2du_getCellBankData(&gOptionEmbremSelect->mOptionEmbremSelectSNcer, arc_getSceneArcFile(gOptionEmbremSelectSNcerName));
    g2du_getPaletteData(&gOptionEmbremSelect->mOptionEmbremSelectSONclr, arc_getSceneArcFile(gOptionEmbremSelectSONclrName));
    NNS_GfdRegisterNewVramTransferTask(4, 0, a->mData, a->mDataSize);
    NNS_GfdRegisterNewVramTransferTask(8, 0, b->mData, b->mDataSize);
    NNS_GfdRegisterNewVramTransferTask(0xf, 0, c->mData, 0x100);
    NNS_GfdRegisterNewVramTransferTask(0x23, 0, gOptionEmbremSelect->mOptionEmbremSelectSNcgr->mData,
                    gOptionEmbremSelect->mOptionEmbremSelectSNcgr->mDataSize);
    NNS_GfdRegisterNewVramTransferTask(0x1e, 0, gOptionEmbremSelect->mOptionEmbremSelectSONclr->mData,
                    gOptionEmbremSelect->mOptionEmbremSelectSONclr->mDataSize);
}

BOOL func_ov001_0219de38(void) {
    if (gSaveData->mFirstBlock->mUnk_31_3 == 0) {
        return FALSE;
    }
    if (gSaveData->mFirstBlock->mUnk_31_3 != 0) {
        return TRUE;
    }
    return TRUE;
}

void AdvanceOptionEmbremSelectState0(void) {
    int v1;
    v1 = mbright_isFadedIn();
    if (v1 != 0) {
        gOptionEmbremSelect->mNextState = 1;
    }
}

void AdvanceOptionEmbremSelectState1(void) {
    s32 i;
    s32 j;
    s16 v;

    gOptionEmbremSelect->mStateFrames++;
    v = mutil_interpolate(1, 250, 0, gOptionEmbremSelect->mStateFrames, 10);
    for (i = 0; i < 2; i++) {
        for (j = 0; j < data_ov001_021a6c28[i]; j++) {
            if (i == 1) {
                gOptionEmbremSelect->mUnk_18[i].mUnk_00 = v;
            } else {
                gOptionEmbremSelect->mUnk_18[i].mUnk_00 = -v;
            }
        }
    }
    if (gOptionEmbremSelect->mStateFrames >= 10) {
        gOptionEmbremSelect->mNextState = 2;
        gOptionEmbremSelect->mStateFrames = 0;
        RequestSelectReturnState1();
    }
}

void AdvanceOptionEmbremSelectState2(void) {
    int v1;
    v1 = IsSelectReturnState2NoState3Or4Request();
    if (v1 != 0) {
        gOptionEmbremSelect->mNextState = 3;
    }
}

void AdvanceOptionEmbremSelectState3(void) {
    InputSlotIndex index = UNK_02175628_INDEX_8;
    s32 result = -1;
    BOOL cond2 = FALSE;
    BOOL cond1 = FALSE;
    u16 value;
    u16 flags;

    value = gInputUnits[index].mHasPair;
    if (value == 0 && gInputUnits[index].mNoPairCount < 5) {
        cond1 = TRUE;
    }
    if (cond1 == FALSE && gInputUnits[index].mPrevHasPair == 0 && value != 0) {
        cond2 = TRUE;
    }
    if (cond2 != FALSE) {
        result = jn_ui_checkTouch(gOptionEmbremSelect->mOptionEmbremSelectSBnbl, gInputUnits[index].mPairX,
                                         gInputUnits[index].mPairY);
    }
    flags = gInputUnits[index].mPressedBits & PAD_KEY_B;
    if (flags != 0) {
        goto next;
    }
    cond2 = FALSE;
    cond1 = FALSE;
    value = gInputUnits[index].mHasPair;
    if (value == 0 && gInputUnits[index].mNoPairCount < 5) {
        cond1 = TRUE;
    }
    if (cond1 == FALSE && gInputUnits[index].mPrevHasPair == 0 && value != 0) {
        cond2 = TRUE;
    }
    if (cond2 != FALSE && gmenu_checkSelectReturnTouch(gInputUnits[index].mPairX,
                                                                          gInputUnits[index].mPairY) != FALSE) {
    next:
        gOptionEmbremSelect->mNextState = 5;
        gOptionEmbremSelect->mNextOptionState = 2;
        if (gOptionEmbremSelect->mUnk_0c != gOptionEmbremSelect->mUnk_10) {
            RequestSelectReturnState3WithSound(1);
        } else {
            RequestSelectReturnState3WithSound(0);
        }
        if (gOptionEmbremSelect->mUnk_0c == 0) {
            gSaveData->mFirstBlock->mUnk_31_3 = 0;
        } else {
            gSaveData->mFirstBlock->mUnk_31_3 = 1;
        }
        savd_flushNksy();
    } else {
        flags = gInputUnits[index].mPressedBits & PAD_KEY_A;
        if ((flags != 0 && gOptionEmbremSelect->mUnk_08 == 0) || result == 0) {
            if (gOptionEmbremSelect->mUnk_08 == 0) {
                gOptionEmbremSelect->mUnk_24 = FALSE;
            }
            gOptionEmbremSelect->mNextState = 4;
            gOptionEmbremSelect->mNextOptionState = 6;
            gOptionEmbremSelect->mUnk_08 = 0;
            gStruct217B488->mUnk_18 = TRUE;
            sfx_2105AC0(5);
        } else if (result == 1) {
            gOptionEmbremSelect->mUnk_08 = 1;
            gOptionEmbremSelect->mUnk_0c++;
            sfx_2105AC0(1);
        } else if (mutil_checkKeys(8, PAD_KEY_UP) != 0 && gOptionEmbremSelect->mUnk_08 > 0) {
            gOptionEmbremSelect->mUnk_08--;
            sfx_2105AC0(0);
        } else if (mutil_checkKeys(8, PAD_KEY_DOWN) != 0 && gOptionEmbremSelect->mUnk_08 < 1) {
            gOptionEmbremSelect->mUnk_08++;
            sfx_2105AC0(0);
        } else if (gOptionEmbremSelect->mUnk_08 == 1 && mutil_checkKeys(8, PAD_KEY_LEFT) != 0) {
            gOptionEmbremSelect->mUnk_0c--;
            gOptionEmbremSelect->mOffsetTimers[0] = 6;
            sfx_2105AC0(1);
        } else if (gOptionEmbremSelect->mUnk_08 == 1 && mutil_checkKeys(8, PAD_KEY_RIGHT) != 0) {
            gOptionEmbremSelect->mUnk_0c++;
            if (mutil_checkKeys(8, PAD_KEY_RIGHT) != 0) {
                gOptionEmbremSelect->mOffsetTimers[1] = 6;
            }
            sfx_2105AC0(1);
        } else if (result == 2) {
            gOptionEmbremSelect->mUnk_08 = 1;
            gOptionEmbremSelect->mUnk_0c--;
            gOptionEmbremSelect->mOffsetTimers[0] = 6;
            sfx_2105AC0(1);
        } else if (result == 3) {
            gOptionEmbremSelect->mUnk_08 = 1;
            gOptionEmbremSelect->mUnk_0c++;
            gOptionEmbremSelect->mOffsetTimers[1] = 6;
            sfx_2105AC0(1);
        }
    }
    if (gOptionEmbremSelect->mUnk_0c < 0) {
        gOptionEmbremSelect->mUnk_0c = 1;
    }
    if (gOptionEmbremSelect->mUnk_0c > 1) {
        gOptionEmbremSelect->mUnk_0c = 0;
    }
}

void AdvanceOptionEmbremSelectState4(void) {
    OptionEmbremSelect *v1;
    gOptionEmbremSelect->mStateFrames = gOptionEmbremSelect->mStateFrames + 1;
    v1 = gOptionEmbremSelect;
    if (10 <= v1->mStateFrames) {
        v1->mNextState = 5;
        gOptionEmbremSelect->mStateFrames = 0;
        RequestSelectReturnState4();
        return;
    }
    if (5 <= v1->mStateFrames) {
        v1->mUnk_24 = TRUE;
    }
}

void AdvanceOptionEmbremSelectState5(void) {
    s32 i;
    s32 j;
    s32 value;

    if (func_ov001_02192e84() == -1 && gOptionEmbremSelect->mNextOptionState == 6) {
        func_ov001_02192e78(3);
    }
    gOptionEmbremSelect->mStateFrames++;
    value = mutil_interpolate(1, 0, 250, gOptionEmbremSelect->mStateFrames, 10);
    for (i = 0; i < 2; i++) {
        for (j = 0; j < data_ov001_021a6c28[i]; j++) {
            if (i == 0) {
                gOptionEmbremSelect->mUnk_18[i].mUnk_00 = -value;
            } else {
                gOptionEmbremSelect->mUnk_18[i].mUnk_00 = value;
            }
        }
    }
    if (gOptionEmbremSelect->mStateFrames >= 10) {
        if (gOptionEmbremSelect->mStateFrames >= 10 &&
            (IsSelectReturnState2NoState3Or4Request() != 0 || IsSelectReturnState0NoState1Request() != 0)) {
            if (func_ov001_02192e84() == -1) {
                OptionEmbremSelect *obj = gOptionEmbremSelect;
                s32 arg;
                void *first;

                if (obj->mUnk_0c == obj->mUnk_10) {
                    RequestOptionState(obj->mNextOptionState);
                    return;
                }
                arg = 9;
                if (obj->mUnk_0c == 1) {
                    arg = 10;
                }
                obj->mNextState = 6;
                SetTxtSystemOpenSoundId(0x21);
                first = jn_msg_getMessage(gOptionEmbremSelect->mOptionMessages, arg);
                SetupTxtSystemSubTextButton(first, jn_msg_getMessage(gOptionEmbremSelect->mCommonMessages, 4));
                gOptionEmbremSelect->mStateFrames = 0;
            }
        }
    }
}

void AdvanceOptionEmbremSelectState6(void) {
    s32 value;

    if (GetTxtSystemDone() != 0) {
        if (gSaveData->mBusy == 0) {
            if (gSaveCore->mBackupEnabled != 0) {
                value = gSaveCore->mCommandRunning;
            } else {
                value = 0;
            }
        } else {
            value = 1;
        }
        if (value == 0) {
            SetTxtSystemOpenSoundId(0x23);
            RequestTxtSystemClose();
            return;
        }
    }
    if (IsTxtSystemState0NoOpenRequest() != 0) {
        RequestOptionState(gOptionEmbremSelect->mNextOptionState);
    }
}

void func_ov001_0219d858(void) {
    s32 i;
    s32 j;
    s32 index;
    s32 k;

    index = gOptionEmbremSelect->mOptionEmbremSelectSBncl->mUnk_06;
    for (i = 0; i < 2; i++) {
        for (j = 0; j < data_ov001_021a6c28[i]; j++) {
            gOptionEmbremSelect->mOptionEmbremSelectSTable[data_ov001_021a6c38[i][j]].mOffsetX =
                gOptionEmbremSelect->mUnk_18[i].mUnk_00;
            gOptionEmbremSelect->mOptionEmbremSelectSTable[data_ov001_021a6c38[i][j]].mOffsetY =
                gOptionEmbremSelect->mUnk_18[i].mUnk_02;
        }
    }
    gOptionEmbremSelect->mOptionEmbremSelectSTable[index].mOffsetX = gOptionEmbremSelect->mUnk_18[1].mUnk_00;
    gOptionEmbremSelect->mOptionEmbremSelectSTable[index].mOffsetY = gOptionEmbremSelect->mUnk_18[1].mUnk_02;
    for (k = 0; k < 3; k++) {
        gOptionEmbremSelect->mOptionEmbremSelectSTable[data_ov001_021a6c20[k][0]].mOffsetX -=
            func_020adc64(6 - gOptionEmbremSelect->mOffsetTimers[0]);
        gOptionEmbremSelect->mOptionEmbremSelectSTable[data_ov001_021a6c20[k][1]].mOffsetX +=
            func_020adc64(6 - gOptionEmbremSelect->mOffsetTimers[1]);
    }
}

void func_ov001_0219d810(void) {
    s32 i;

    for (i = 0; i < data_ov001_021a6c30[1]; i++) {
        if (i == gOptionEmbremSelect->mUnk_0c) {
            gOptionEmbremSelect->mOptionEmbremSelectSTable[data_ov001_021a6c1c[1][i]].mVisible = 1;
        } else {
            gOptionEmbremSelect->mOptionEmbremSelectSTable[data_ov001_021a6c1c[1][i]].mVisible = 0;
        }
    }
}

void func_ov001_0219d730(void) {
    s32 i;
    s32 j;

    for (i = 0; i < 2; i++) {
        if (i == gOptionEmbremSelect->mUnk_08 && gOptionEmbremSelect->mUnk_24 != FALSE) {
            gOptionEmbremSelect->mOptionEmbremSelectSTable[data_ov001_021a6c38[i][1]].mVisible = 1;
            if (i == 1) {
                jn_ui_setLabelColorParam(0, 14, gOptionEmbremSelect->mOptionEmbremSelectSBnll,
                                     gOptionEmbremSelect->mOptionEmbremSelectSTable,
                                     gOptionEmbremSelect->mOptionEmbremSelectSBncl);
            }
            for (j = 0; j < data_ov001_021a6c30[i]; j++) {
                jn_ui_setCellCparam(data_ov001_021a6c1c[i][j], 14, gOptionEmbremSelect->mOptionEmbremSelectSNcer,
                                    gOptionEmbremSelect->mOptionEmbremSelectSBncl);
            }
        } else {
            gOptionEmbremSelect->mOptionEmbremSelectSTable[data_ov001_021a6c38[i][1]].mVisible = 0;
            if (i == 1) {
                jn_ui_setLabelColorParam(0, 15, gOptionEmbremSelect->mOptionEmbremSelectSBnll,
                                     gOptionEmbremSelect->mOptionEmbremSelectSTable,
                                     gOptionEmbremSelect->mOptionEmbremSelectSBncl);
            }
            for (j = 0; j < data_ov001_021a6c30[i]; j++) {
                jn_ui_setCellCparam(data_ov001_021a6c1c[i][j], 15, gOptionEmbremSelect->mOptionEmbremSelectSNcer,
                                    gOptionEmbremSelect->mOptionEmbremSelectSBncl);
            }
        }
    }
}

void func_ov001_0219d6ac(void) {
    s32 i;

    for (i = 0; i < 2; i++) {
        if (gOptionEmbremSelect->mUnk_08 == 1) {
            if (gOptionEmbremSelect->mOffsetTimers[i] > 0) {
                gOptionEmbremSelect->mOptionEmbremSelectSTable[data_ov001_021a6c20[0][i]].mVisible = 1;
                gOptionEmbremSelect->mOptionEmbremSelectSTable[data_ov001_021a6c20[1][i]].mVisible = 1;
                gOptionEmbremSelect->mOffsetTimers[i]--;
            } else {
                gOptionEmbremSelect->mOptionEmbremSelectSTable[data_ov001_021a6c20[0][i]].mVisible = 0;
                gOptionEmbremSelect->mOptionEmbremSelectSTable[data_ov001_021a6c20[1][i]].mVisible = 1;
            }
        } else {
            gOptionEmbremSelect->mOptionEmbremSelectSTable[data_ov001_021a6c20[0][i]].mVisible = 0;
            gOptionEmbremSelect->mOptionEmbremSelectSTable[data_ov001_021a6c20[1][i]].mVisible = 0;
        }
    }
}

void AdvanceOptionEmbremSelect(void) {
    gOptionEmbremSelect->mState = gOptionEmbremSelect->mNextState;
    switch (gOptionEmbremSelect->mState) {
        case 0:
            AdvanceOptionEmbremSelectState0();
            break;
        case 1:
            AdvanceOptionEmbremSelectState1();
            break;
        case 2:
            AdvanceOptionEmbremSelectState2();
            break;
        case 3:
            AdvanceOptionEmbremSelectState3();
            break;
        case 4:
            AdvanceOptionEmbremSelectState4();
            break;
        case 5:
            AdvanceOptionEmbremSelectState5();
            break;
        case 6:
            AdvanceOptionEmbremSelectState6();
            break;
    }
    func_ov001_0219d858();
    func_ov001_0219d810();
    func_ov001_0219d730();
    func_ov001_0219d6ac();
    jn_ui_renderElements(gOptionEmbremSelect->mOptionEmbremSelectSBncl, gOptionEmbremSelect->mOptionEmbremSelectSNcer,
                    gOptionEmbremSelect->mOptionEmbremSelectSBnll, GetOptionSecondBuffer(),
                    gOptionEmbremSelect->mOptionEmbremSelectSTable);
}

void func_ov001_0219d600(void) {
    G2x_SetBlendAlpha_(&reg_G2S_DB_BLDCNT, 0, 2, 6, 10);
}

void RegisterOptionEmbremSelectCallbacks(void) {
    OptionStateCallbackTable local = gOptionEmbremSelectCallbacks;

    SetOptionStateCallbacks(local.mUnk_00);
}
