#include "01/code_02199964.h"
#include "registers.h"
#include "01/unk_021a6000.h"
#include "01/OptionSelectMenu.h"
#include "01/code_0219853c.h"
#include "00/code_02181f98.h"
#include "Main/System/Heap.h"
#include "Main/Unknown/code_021059e0.h"
#include "Main/Unknown/code_02128244.h"
#include "Main/Unknown/code_0212b000.h"
#include "01/code_0219e824.h"
#include "01/code_02192000.h"
#include "01/code_02199000.h"
#include "01/unk_021a8000.h"
#include "Main/Unknown/code_02108000.h"
#include "code_0201ea58.h"
#include "code_0214a390.h"

OptionHensyuMenu *gOptionHensyuMenu;

void InitOptionHensyuMenu(void *heap) {
    s32 i;
    s32 j;
    void *a;
    gOptionHensyuMenu = heap_alloc(heap, 0x34);
    gOptionHensyuMenu->field18 = heap;
    gOptionHensyuMenu->mState = 0;
    gOptionHensyuMenu->mNextState = 0;
    switch (GetOptionPrevState()) {
        case 0:
        case 5:
            gOptionHensyuMenu->mIndex = 0;
            break;
        case 3:
        case 6:
            gOptionHensyuMenu->mIndex = 1;
            break;
    }
    gOptionHensyuMenu->mStateFrames = 0;
    gOptionHensyuMenu->field14 = TRUE;
    LocateAndQueueOptionHensyuMenu();
    for (i = 0; i < 2; i++) {
        jn_ui_setCellIsTranslucent(data_ov001_021a6a84[i], 1, gOptionHensyuMenu->mOptionHensyuMenuSNcer,
                      gOptionHensyuMenu->mOptionHensyuMenuSBncl);
    }
    a = GetOptionFirstBuffer();
    oam_clearResetBuffers(a, GetOptionSecondBuffer());
    jn_ui_initLayout(heap, gOptionHensyuMenu->mOptionHensyuMenuSBncl, NULL, &gOptionHensyuMenu->mOptionHensyuMenuSTable);
    for (i = 0; i < 2; i++) {
        for (j = 0; j < data_ov001_021a6a8c[i]; j++) {
            if (i == 1) {
                gOptionHensyuMenu->mOptionHensyuMenuSTable[data_ov001_021a6a94[i][j]].mOffsetX = 0xfa;
            } else {
                gOptionHensyuMenu->mOptionHensyuMenuSTable[data_ov001_021a6a94[i][j]].mOffsetX = -0xfa;
            }
        }
    }
    gmenu_setSeqArcIndex(0xe);
}

void ReleaseOptionHensyuMenu(void) {
    gOptionHensyuMenu = NULL;
}

void LocateAndQueueOptionHensyuMenu(void) {
    Ncgr *a;
    Nscr *b;
    Nclr *c;

    g2du_getCharacterDataBG(&a, arc_getSceneArcFile(aOptionTopMenuM_2));
    g2du_getScreenData(&b, arc_getSceneArcFile(aOptionTopMenuM_3));
    g2du_getPaletteData(&c, arc_getSceneArcFile(aOptionTopMenuM_4));
    gOptionHensyuMenu->mOptionHensyuMenuSBncl = arc_getSceneArcFile(aOptionHensyuMe);
    gOptionHensyuMenu->mOptionHensyuMenuSBnbl = arc_getSceneArcFile(aOptionHensyuMe_0);
    g2du_getCharacterData(&gOptionHensyuMenu->mOptionHensyuMenuSNcgr, arc_getSceneArcFile(aOptionHensyuMe_1));
    g2du_getCellBankData(&gOptionHensyuMenu->mOptionHensyuMenuSNcer, arc_getSceneArcFile(aOptionHensyuMe_2));
    g2du_getPaletteData(&gOptionHensyuMenu->mOptionHensyuMenuSONclr, arc_getSceneArcFile(aOptionHensyuMe_3));
    NNS_GfdRegisterNewVramTransferTask(4, 0, a->mData, a->mDataSize);
    NNS_GfdRegisterNewVramTransferTask(8, 0, b->mData, b->mDataSize);
    NNS_GfdRegisterNewVramTransferTask(15, 0, c->mData, 0x100);
    NNS_GfdRegisterNewVramTransferTask(0x23, 0, gOptionHensyuMenu->mOptionHensyuMenuSNcgr->mData,
                    gOptionHensyuMenu->mOptionHensyuMenuSNcgr->mDataSize);
    NNS_GfdRegisterNewVramTransferTask(0x1e, 0, gOptionHensyuMenu->mOptionHensyuMenuSONclr->mData,
                    gOptionHensyuMenu->mOptionHensyuMenuSONclr->mDataSize);
}

void AdvanceOptionHensyuMenuState0(void) {
    int v1;
    v1 = mbright_isFadedIn();
    if (v1 != 0) {
        gOptionHensyuMenu->mNextState = 1;
    }
}

void AdvanceOptionHensyuMenuState1(void) {
    s32 i;
    s32 j;
    s32 v;
    gOptionHensyuMenu->mStateFrames++;
    v = mutil_interpolate(1, 0xfa, 0, gOptionHensyuMenu->mStateFrames, 10);
    for (i = 0; i < 2; i++) {
        for (j = 0; j < data_ov001_021a6a8c[i]; j++) {
            if (i == 1) {
                gOptionHensyuMenu->mOptionHensyuMenuSTable[data_ov001_021a6a94[i][j]].mOffsetX = v;
            } else {
                gOptionHensyuMenu->mOptionHensyuMenuSTable[data_ov001_021a6a94[i][j]].mOffsetX = -v;
            }
        }
    }
    if (gOptionHensyuMenu->mStateFrames >= 10) {
        gOptionHensyuMenu->mNextState = 2;
        gOptionHensyuMenu->mStateFrames = 0;
        RequestSelectReturnState1();
    }
}

void AdvanceOptionHensyuMenuState2(void) {
    int v1;
    v1 = IsSelectReturnState2NoState3Or4Request();
    if (v1 != 0) {
        gOptionHensyuMenu->mNextState = 3;
    }
}

void AdvanceOptionHensyuMenuState3(void) {
    u32 r;
    BOOL b;
    BOOL a;
    u16 v;
    s32 oldv;
    OptionHensyuMenu *p;
    InputSlotIndex i;

    i = UNK_02175628_INDEX_8;
    r = -1;
    b = FALSE;
    a = FALSE;
    v = gInputUnits[i].mHasPair;
    if (v == 0 && gInputUnits[i].mNoPairCount < 5) {
        a = TRUE;
    }
    if (a == FALSE && gInputUnits[i].mPrevHasPair == 0 && v != 0) {
        b = TRUE;
    }
    if (b != FALSE) {
        r = jn_ui_checkTouch(gOptionHensyuMenu->mOptionHensyuMenuSBnbl, gInputUnits[i].mPairX,
                                    gInputUnits[i].mPairY);
    }
    if ((u16) (gInputUnits[i].mPressedBits & PAD_KEY_B) == 0) {
        b = FALSE;
        a = FALSE;
        v = gInputUnits[i].mHasPair;
        if (v == 0 && gInputUnits[i].mNoPairCount < 5) {
            a = TRUE;
        }
        if (a == FALSE && gInputUnits[i].mPrevHasPair == 0 && v != 0) {
            b = TRUE;
        }
        if (b != FALSE && gmenu_checkSelectReturnTouch(gInputUnits[i].mPairX,
                                                                          gInputUnits[i].mPairY) != FALSE) {
            goto leave;
        }
    } else {
    leave:
        gOptionHensyuMenu->mNextState = 5;
        gOptionHensyuMenu->mNextOptionState = 0;
        RequestSelectReturnState3WithSound(0);
        return;
    }
    if ((u16) (gInputUnits[i].mPressedBits & PAD_KEY_A) != 0 || r <= 1) {
        p = gOptionHensyuMenu;
        oldv = p->mIndex;
        if ((u16) (gInputUnits[i].mPressedBits & PAD_KEY_A) == 0) {
            switch (r) {
                case 0:
                    p->mIndex = 0;
                    break;
                case 1:
                    p->mIndex = 1;
                    break;
            }
        }
        gOptionHensyuMenu->mNextState = 4;
        p = gOptionHensyuMenu;
        switch (p->mIndex) {
            case 0:
                p->mNextOptionState = 5;
                break;
            case 1:
                if (gSaveData->mEmblemRecord->mFilled != 0) {
                    p->mNextOptionState = 3;
                } else {
                    p->mNextOptionState = 6;
                    gStruct217B488->field18 = FALSE;
                }
                break;
        }
        if (gOptionHensyuMenu->mIndex == oldv) {
            gOptionHensyuMenu->field14 = FALSE;
        }
        sfx_2105AC0(5);
        return;
    }
    if (mutil_checkKeys(8, PAD_KEY_UP) != 0) {
        if (gOptionHensyuMenu->mIndex > 0) {
            gOptionHensyuMenu->mIndex--;
            sfx_2105AC0(0);
            return;
        }
    }
    if (mutil_checkKeys(8, PAD_KEY_DOWN) != 0) {
        if (gOptionHensyuMenu->mIndex < 1) {
            gOptionHensyuMenu->mIndex++;
            sfx_2105AC0(0);
        }
    }
}

void AdvanceOptionHensyuMenuState4(void) {
    gOptionHensyuMenu->mStateFrames++;
    if (gOptionHensyuMenu->mStateFrames >= 10) {
        gOptionHensyuMenu->mNextState = 5;
        gOptionHensyuMenu->mStateFrames = 0;
        if (gOptionHensyuMenu->mNextOptionState == 5) {
            RequestSelectReturnState4();
        }
    } else if (gOptionHensyuMenu->mStateFrames >= 5) {
        gOptionHensyuMenu->field14 = TRUE;
    }
}

void AdvanceOptionHensyuMenuState5(void) {
    s32 i;
    s32 j;
    s32 v;
    if (func_ov001_02192e84() == -1) {
        if (gOptionHensyuMenu->mNextOptionState == 5) {
            func_ov001_02192e78(0xe);
        } else if (gOptionHensyuMenu->mNextOptionState == 6) {
            func_ov001_02192e78(3);
        }
    }
    gOptionHensyuMenu->mStateFrames++;
    if (gOptionHensyuMenu->mStateFrames <= 10) {
        v = mutil_interpolate(1, 0, 0xfa, gOptionHensyuMenu->mStateFrames, 10);
    } else {
        v = 0xfa;
    }
    for (i = 0; i < 2; i++) {
        for (j = 0; j < data_ov001_021a6a8c[i]; j++) {
            if (i == 1) {
                gOptionHensyuMenu->mOptionHensyuMenuSTable[data_ov001_021a6a94[i][j]].mOffsetX = v;
            } else {
                gOptionHensyuMenu->mOptionHensyuMenuSTable[data_ov001_021a6a94[i][j]].mOffsetX = -v;
            }
        }
    }
    if (gOptionHensyuMenu->mStateFrames >= 10) {
        if (gOptionHensyuMenu->mNextOptionState == 0 || gOptionHensyuMenu->mNextOptionState == 3 ||
            IsSelectReturnState0NoState1Request() != 0) {
            if (func_ov001_02192e84() == -1) {
                RequestOptionState(gOptionHensyuMenu->mNextOptionState);
            }
        }
    }
}

void func_ov001_02199a20(void) {
    s32 i;
    for (i = 0; i < 2; i++) {
        if (i == gOptionHensyuMenu->mIndex && gOptionHensyuMenu->field14 != FALSE) {
            gOptionHensyuMenu->mOptionHensyuMenuSTable[data_ov001_021a6a88[i]].mVisible = 1;
            jn_ui_setCellCparam(data_ov001_021a6a80[i], 0xe, gOptionHensyuMenu->mOptionHensyuMenuSNcer,
                                gOptionHensyuMenu->mOptionHensyuMenuSBncl);
        } else {
            gOptionHensyuMenu->mOptionHensyuMenuSTable[data_ov001_021a6a88[i]].mVisible = 0;
            jn_ui_setCellCparam(data_ov001_021a6a80[i], 0xf, gOptionHensyuMenu->mOptionHensyuMenuSNcer,
                                gOptionHensyuMenu->mOptionHensyuMenuSBncl);
        }
    }
}

void AdvanceOptionHensyuMenu(void) {
    OptionHensyuMenu *p;
    gOptionHensyuMenu->mState = gOptionHensyuMenu->mNextState;
    switch (gOptionHensyuMenu->mState) {
        case 0:
            AdvanceOptionHensyuMenuState0();
            break;
        case 1:
            AdvanceOptionHensyuMenuState1();
            break;
        case 2:
            AdvanceOptionHensyuMenuState2();
            break;
        case 3:
            AdvanceOptionHensyuMenuState3();
            break;
        case 4:
            AdvanceOptionHensyuMenuState4();
            break;
        case 5:
            AdvanceOptionHensyuMenuState5();
            break;
    }
    func_ov001_02199a20();
    p = gOptionHensyuMenu;
    jn_ui_renderElements(p->mOptionHensyuMenuSBncl, p->mOptionHensyuMenuSNcer, NULL, GetOptionSecondBuffer(),
                    p->mOptionHensyuMenuSTable);
}

void func_ov001_02199988(void) {
    G2x_SetBlendAlpha_(&reg_G2S_DB_BLDCNT, 0, 2, 6, 10);
}

void RegisterOptionHensyuMenuCallbacks(void) {
    UnkFunc *tbl[4] = {InitOptionHensyuMenu, ReleaseOptionHensyuMenu, AdvanceOptionHensyuMenu, func_ov001_02199988};
    SetOptionStateCallbacks(tbl);
}
