#include "01/code_021932e4.h"
#include "code_0214a390.h"
#include "registers.h"

#include "01/code_02195000.h"
#include "01/code_0219e824.h"
#include "01/unk_021a6000.h"
#include "01/unk_021a8000.h"
#include "01/unk_021a9000.h"
#include "Main/System/Heap.h"
#include "Main/Unknown/code_02056d54.h"
#include "Main/Unknown/code_02057000.h"
#include "Main/Unknown/code_021059e0.h"
#include "Main/Unknown/code_02125000.h"
#include "Main/Unknown/code_02125ebc.h"
#include "Main/Unknown/code_02125f6c.h"
#include "Main/Unknown/code_02126000.h"
#include "Main/Unknown/code_02125f54.h"
#include "code_0201ea58.h"
#include "Main/Unknown/code_02111488.h"
#include "Main/Unknown/code_02126230.h"
#include "Main/Unknown/code_02126248.h"

OptionTopMenu *gOptionTopMenu;

void InitOptionTopMenu(void *heap) {
    s32 i;
    s32 j;

    gOptionTopMenu = heap_alloc(heap, 0x40);
    gOptionTopMenu->mUnk_1c = heap;
    gOptionTopMenu->mState = 0;
    gOptionTopMenu->mNextState = 0;
    switch (GetOptionPrevState()) {
        case 1:
        case 4:
            gOptionTopMenu->mIndex = 0;
            break;
        case 2:
            gOptionTopMenu->mIndex = 1;
            break;
    }
    gOptionTopMenu->mStateFrames = 0;
    gOptionTopMenu->mUnk_14 = TRUE;
    gOptionTopMenu->mOptionMessages = arc_getSceneArcFile(aOptionBmg);
    gOptionTopMenu->mCommonMessages = arc_get2dArcFile(aCommonBmg);
    if (GetOptionPrevState() == 1) {
        gOptionTopMenu->mBg0Offset = 0x32;
    } else {
        gOptionTopMenu->mBg0Offset = 0;
    }
    LocateAndQueueOptionTopMenu();
    for (i = 0; i < 3; i++) {
        jn_ui_setCellIsTranslucent(data_ov001_021a65dc[i], 1, gOptionTopMenu->mOptionTopMenuSNcer,
                      gOptionTopMenu->mOptionTopMenuSBncl);
    }
    oam_clearResetBuffers(GetOptionFirstBuffer(), GetOptionSecondBuffer());
    jn_ui_initLayout(heap, gOptionTopMenu->mOptionTopMenuSBncl, NULL, &gOptionTopMenu->mOptionTopMenuSTable);
    for (i = 0; i < 3; i++) {
        for (j = 0; j < data_ov001_021a65e4[i]; j++) {
            if (i == 1) {
                gOptionTopMenu->mOptionTopMenuSTable[data_ov001_021a65f0[i][j]].mOffsetX = 250;
            } else {
                gOptionTopMenu->mOptionTopMenuSTable[data_ov001_021a65f0[i][j]].mOffsetX = -250;
            }
        }
    }
    gmenu_setSeqArcIndex(0xf);
}

void ReleaseOptionTopMenu(void) {
    gOptionTopMenu = NULL;
}

void LocateAndQueueOptionTopMenu(void) {
    Ncgr *a;
    Nscr *b;
    Nclr *c;

    g2du_getCharacterDataBG(&a, arc_getSceneArcFile(aOptionTopMenuM));
    g2du_getScreenData(&b, arc_getSceneArcFile(aOptionTopMenuM_0));
    g2du_getPaletteData(&c, arc_getSceneArcFile(aOptionTopMenuM_1));
    gOptionTopMenu->mOptionTopMenuSBncl = arc_getSceneArcFile(aOptionTopMenuS);
    gOptionTopMenu->mOptionTopMenuSBnbl = arc_getSceneArcFile(aOptionTopMenuS_0);
    g2du_getCharacterData(&gOptionTopMenu->mOptionTopMenuSNcgr, arc_getSceneArcFile(aOptionTopMenuS_1));
    g2du_getCellBankData(&gOptionTopMenu->mOptionTopMenuSNcer, arc_getSceneArcFile(aOptionTopMenuS_2));
    g2du_getPaletteData(&gOptionTopMenu->mOptionTopMenuSONclr, arc_getSceneArcFile(aOptionTopMenuS_3));
    NNS_GfdRegisterNewVramTransferTask(4, 0, a->mData, a->mDataSize);
    NNS_GfdRegisterNewVramTransferTask(8, 0, b->mData, b->mDataSize);
    NNS_GfdRegisterNewVramTransferTask(15, 0, c->mData, 0x100);
    NNS_GfdRegisterNewVramTransferTask(0x23, 0, gOptionTopMenu->mOptionTopMenuSNcgr->mData,
                    gOptionTopMenu->mOptionTopMenuSNcgr->mDataSize);
    NNS_GfdRegisterNewVramTransferTask(0x1e, 0, gOptionTopMenu->mOptionTopMenuSONclr->mData,
                    gOptionTopMenu->mOptionTopMenuSONclr->mDataSize);
}

void AdvanceOptionTopMenuState0(void) {
    int v1;
    v1 = mbright_isFadedIn();
    if (v1 != 0) {
        gOptionTopMenu->mNextState = 1;
    }
}

void AdvanceOptionTopMenuState1(void) {
    s32 amount;
    s32 i;
    s32 j;

    gOptionTopMenu->mStateFrames++;
    amount = mutil_interpolate(1, 250, 0, gOptionTopMenu->mStateFrames, 10);
    for (i = 0; i < 3; i++) {
        for (j = 0; j < data_ov001_021a65e4[i]; j++) {
            if (i == 1) {
                gOptionTopMenu->mOptionTopMenuSTable[data_ov001_021a65f0[i][j]].mOffsetX = amount;
            } else {
                gOptionTopMenu->mOptionTopMenuSTable[data_ov001_021a65f0[i][j]].mOffsetX = -amount;
            }
        }
    }
    if (GetOptionPrevState() == 1 && gOptionTopMenu->mIndex != 2) {
        gOptionTopMenu->mBg0Offset = mutil_interpolate(1, 50, 0, gOptionTopMenu->mStateFrames, 10);
    }
    if (gOptionTopMenu->mStateFrames >= 10) {
        gOptionTopMenu->mNextState = 2;
        gOptionTopMenu->mStateFrames = 0;
        RequestSelectReturnState1();
    }
}

void AdvanceOptionTopMenuState2(void) {
    int v1;
    v1 = IsSelectReturnState2NoState3Or4Request();
    if (v1 != 0) {
        gOptionTopMenu->mNextState = 3;
    }
}

void AdvanceOptionTopMenuState3(void) {
    InputSlotIndex idx = UNK_02175628_INDEX_8;
    u32 result = -1;
    BOOL b = FALSE;
    BOOL a = FALSE;
    u16 flagA;
    s32 old;
    s32 flagB;

    if (gInputUnits[idx].mHasPair == 0 && gInputUnits[idx].mNoPairCount < 5) {
        a = TRUE;
    }
    if (a == FALSE && gInputUnits[idx].mPrevHasPair == 0 && gInputUnits[idx].mHasPair != 0) {
        b = TRUE;
    }
    if (b != FALSE) {
        result = jn_ui_checkTouch(gOptionTopMenu->mOptionTopMenuSBnbl, gInputUnits[idx].mPairX,
                                         gInputUnits[idx].mPairY);
    }
    flagA = gInputUnits[idx].mPressedBits & PAD_KEY_B;
    if (flagA == 0) {
        BOOL b2 = FALSE;
        BOOL a2 = FALSE;
        if (gInputUnits[idx].mHasPair == 0 && gInputUnits[idx].mNoPairCount < 5) {
            a2 = TRUE;
        }
        if (a2 == FALSE && gInputUnits[idx].mPrevHasPair == 0 && gInputUnits[idx].mHasPair != 0) {
            b2 = TRUE;
        }
        if (b2 != FALSE && gmenu_checkSelectReturnTouch(gInputUnits[idx].mPairX,
                                                                           gInputUnits[idx].mPairY) != FALSE) {
            goto leave;
        }
    } else {
    leave:
        gOptionTopMenu->mNextState = 5;
        gOptionTopMenu->mNextOptionState = 4;
        RequestSelectReturnState3WithSound(1);
        return;
    }
    flagB = gInputUnits[idx].mPressedBits & PAD_KEY_A;
    if ((u16) flagB != 0 || result <= 2) {
        old = gOptionTopMenu->mIndex;
        if ((u16) flagB == 0) {
            switch (result) {
                case 0:
                    gOptionTopMenu->mIndex = 0;
                    break;
                case 1:
                    gOptionTopMenu->mIndex = 1;
                    break;
                case 2:
                    gOptionTopMenu->mIndex = 2;
                    break;
            }
        }
        gOptionTopMenu->mNextState = 4;
        switch (gOptionTopMenu->mIndex) {
            case 0:
                gOptionTopMenu->mNextOptionState = 1;
                break;
            case 1:
                gOptionTopMenu->mNextOptionState = 2;
                break;
            case 2:
                break;
        }
        if (gOptionTopMenu->mIndex == old) {
            gOptionTopMenu->mUnk_14 = FALSE;
        }
        sfx_2105AC0(5);
    } else if (mutil_checkKeys(8, PAD_KEY_UP) != 0) {
        gOptionTopMenu->mIndex--;
        if (gOptionTopMenu->mIndex < 0) {
            gOptionTopMenu->mIndex = 2;
        }
        sfx_2105AC0(0);
    } else if (mutil_checkKeys(8, PAD_KEY_DOWN) != 0) {
        gOptionTopMenu->mIndex++;
        if (gOptionTopMenu->mIndex > 2) {
            gOptionTopMenu->mIndex = 0;
        }
        sfx_2105AC0(0);
    }
}

void AdvanceOptionTopMenuState4(void) {
    gOptionTopMenu->mStateFrames++;
    if (gOptionTopMenu->mStateFrames >= 10) {
        gOptionTopMenu->mNextState = 5;
        gOptionTopMenu->mStateFrames = 0;
        if (gOptionTopMenu->mIndex == 2) {
            RequestSelectReturnState4();
        }
    } else if (gOptionTopMenu->mStateFrames >= 5) {
        gOptionTopMenu->mUnk_14 = TRUE;
    }
}

void AdvanceOptionTopMenuState5(void) {
    s32 amount;
    s32 i;
    s32 j;

    if (func_ov001_02192e84() == -1 && gOptionTopMenu->mNextOptionState == 4) {
        func_ov001_02192e78(0);
    }
    gOptionTopMenu->mStateFrames++;
    if (gOptionTopMenu->mStateFrames <= 10) {
        amount = mutil_interpolate(1, 0, 250, gOptionTopMenu->mStateFrames, 10);
    } else {
        amount = 250;
    }
    for (i = 0; i < 3; i++) {
        for (j = 0; j < data_ov001_021a65e4[i]; j++) {
            if (i == 1) {
                gOptionTopMenu->mOptionTopMenuSTable[data_ov001_021a65f0[i][j]].mOffsetX = amount;
            } else {
                gOptionTopMenu->mOptionTopMenuSTable[data_ov001_021a65f0[i][j]].mOffsetX = -amount;
            }
        }
    }
    if (gOptionTopMenu->mNextOptionState == 1) {
        gOptionTopMenu->mBg0Offset = mutil_interpolate(1, 0, 50, gOptionTopMenu->mStateFrames, 10);
    }
    if (gOptionTopMenu->mStateFrames >= 10 &&
        (gOptionTopMenu->mIndex != 2 || IsSelectReturnState0NoState1Request() != 0) && func_ov001_02192e84() == -1) {
        if (gOptionTopMenu->mIndex == 2) {
            gOptionTopMenu->mNextState = 6;
            gOptionTopMenu->mStateFrames = 0;
            SetupTxtSystemSubTextTwoButtons(jn_msg_getMessage(gOptionTopMenu->mOptionMessages, 3),
                                            jn_msg_getMessage(gOptionTopMenu->mCommonMessages, 0),
                                            jn_msg_getMessage(gOptionTopMenu->mCommonMessages, 1), 1);
        } else {
            RequestOptionState(gOptionTopMenu->mNextOptionState);
        }
    }
}

void AdvanceOptionTopMenuState6(void) {
    if (GetTxtSystemDone() != 0) {
        RequestTxtSystemClose();
        return;
    }
    if (IsTxtSystemState0NoOpenRequest() != 0) {
        if (GetTxtSystemSelectedIndex() == 0) {
            SetupTxtSystemSubTextTwoButtons(jn_msg_getMessage(gOptionTopMenu->mOptionMessages, 4),
                                            jn_msg_getMessage(gOptionTopMenu->mCommonMessages, 0),
                                            jn_msg_getMessage(gOptionTopMenu->mCommonMessages, 1), 1);
            gOptionTopMenu->mNextState = 7;
        } else {
            gOptionTopMenu->mNextState = 1;
        }
    }
}

void AdvanceOptionTopMenuState7(void) {
    if (GetTxtSystemDone() != 0) {
        RequestTxtSystemClose();
        return;
    }
    if (IsTxtSystemState0NoOpenRequest() != 0) {
        if (GetTxtSystemSelectedIndex() == 0) {
            savd_eraseAllAsync();
            gOptionTopMenu->mNextState = 8;
            SetupTxtSystemSubTextEx(jn_msg_getMessage(gOptionTopMenu->mOptionMessages, 5), 1, 1, 1, 0, 1);
        } else {
            gOptionTopMenu->mNextState = 1;
        }
    }
}

void AdvanceOptionTopMenuState8(void) {
    s32 flag;

    if (IsTxtSystemState2AfterState1() != 0) {
        NNS_SndArcPlayerStartSeqArc(&data_0217d068, 0, 0x22);
    }
    if (gSaveData->mBusy == 0) {
        if (gSaveCore->mBackupEnabled != 0) {
            flag = gSaveCore->mCommandRunning;
        } else {
            flag = 0;
        }
    } else {
        flag = 1;
    }
    if (flag == 0 && IsTxtSystemState2NoCloseRequest() != 0) {
        gOptionTopMenu->mNextState = 9;
        SetTxtSystemOpenSoundId(0x21);
        SetupTxtSystemSubTextButton(jn_msg_getMessage(gOptionTopMenu->mOptionMessages, 6),
                                    jn_msg_getMessage(gOptionTopMenu->mCommonMessages, 4));
    }
}

void AdvanceOptionTopMenuState9(void) {
    int v1;
    v1 = func_ov001_02192e84();
    if ((v1 == -1) && (gOptionTopMenu->mNextOptionState == 4)) {
        func_ov001_02192e78(0);
    }
    v1 = GetTxtSystemDone();
    if (v1 != 0) {
        SetTxtSystemOpenSoundId(0x23);
        RequestTxtSystemClose();
        gOptionTopMenu->mNextOptionState = 4;
    }
}

void func_ov001_021933dc(void) {
    int i;
    BOOL zero = FALSE;

    for (i = 0; i < 3; i++) {
        if (i == gOptionTopMenu->mIndex && gOptionTopMenu->mUnk_14 != FALSE) {
            gOptionTopMenu->mOptionTopMenuSTable[data_ov001_021a65e0[i]].mVisible = 1;
            jn_ui_setCellCparam(data_ov001_021a65d8[i], 14, gOptionTopMenu->mOptionTopMenuSNcer,
                                gOptionTopMenu->mOptionTopMenuSBncl);
        } else {
            gOptionTopMenu->mOptionTopMenuSTable[data_ov001_021a65e0[i]].mVisible = zero;
            jn_ui_setCellCparam(data_ov001_021a65d8[i], 15, gOptionTopMenu->mOptionTopMenuSNcer,
                                gOptionTopMenu->mOptionTopMenuSBncl);
        }
    }
}

void AdvanceOptionTopMenu(void) {
    OptionTopMenu *obj;

    gOptionTopMenu->mState = gOptionTopMenu->mNextState;
    switch (gOptionTopMenu->mState) {
        case 0:
            AdvanceOptionTopMenuState0();
            break;
        case 1:
            AdvanceOptionTopMenuState1();
            break;
        case 2:
            AdvanceOptionTopMenuState2();
            break;
        case 3:
            AdvanceOptionTopMenuState3();
            break;
        case 4:
            AdvanceOptionTopMenuState4();
            break;
        case 5:
            AdvanceOptionTopMenuState5();
            break;
        case 6:
            AdvanceOptionTopMenuState6();
            break;
        case 7:
            AdvanceOptionTopMenuState7();
            break;
        case 8:
            AdvanceOptionTopMenuState8();
            break;
        case 9:
            AdvanceOptionTopMenuState9();
            break;
    }
    func_ov001_021933dc();
    obj = gOptionTopMenu;
    jn_ui_renderElements(obj->mOptionTopMenuSBncl, obj->mOptionTopMenuSNcer, NULL, GetOptionSecondBuffer(),
                    obj->mOptionTopMenuSTable);
}

void func_ov001_02193308(void) {
    G2x_SetBlendAlpha_(&reg_G2S_DB_BLDCNT, 0, 2, 6, 10);
    reg_G2_BG0OFS = gOptionTopMenu->mBg0Offset << 0x10 & (0x01ff0000u);
}

void RegisterOptionTopMenuCallbacks(void) {
    OptionStateCallbacks callbacks = gOptionTopMenuCallbacks;

    SetOptionStateCallbacks((UnkFunc **) &callbacks);
}
