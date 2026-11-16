#include "01/code_ov001_02197b34.h"

#include "01/code_021956dc.h"
#include "00/code_02181f98.h"
#include "Main/System/Heap.h"
#include "Main/Unknown/code_020ae408.h"
#include "Main/Unknown/code_020b4000.h"
#include "Main/Unknown/unk_0216c000.h"
#include "01/code_02198000.h"
#include "01/unk_021a6000.h"
#include "01/unk_021a9000.h"
#include "code_0201ea58.h"
#include "Main/Unknown/code_02036000.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_020ccc9c.h"
#include "Main/Unknown/code_020ae4c0.h"
#include "Main/Unknown/code_0212426c.h"
#include "Main/Unknown/code_02124000.h"
#include "Main/Unknown/unk_0217d068.h"
#include "01/unk_021a8000.h"
#include "Main/Unknown/code_02060000.h"
#include "Main/Unknown/code_02116000.h"
#include "code_0212df7c.h"
#include "Main/Unknown/code_02047104.h"
#include "registers.h"

TimeAttackTopMenu *sMenuTaState;

void LoadTimeAttackTopMenuData(void) {
    Ncgr *a = NULL;
    Unk02021dc8 *b = NULL;
    Nclr *c = NULL;
    Ncgr *d = NULL;
    Nclr *e = NULL;
    Nscr *f = NULL;

    g2du_unpackCharacterDataBG(&d, arc_getSceneArcFile(gTimeAttackTopMenuMBNcgrName));
    g2du_unpackPaletteData(&e, arc_getSceneArcFile(gTimeAttackTopMenuMBNclrName));
    g2du_unpackScreenData(&f, arc_getSceneArcFile(gTimeAttackTopMenuMNscrName));
    g2du_unpackCharacterData(&a, arc_getSceneArcFile(gTimeAttackTopMenuSNcgrName));
    g2du_unpackCellBankData(&b, arc_getSceneArcFile(gTimeAttackTopMenuSNcerName));
    g2du_unpackPaletteData(&c, arc_getSceneArcFile(gTimeAttackTopMenuSONclrName));
}

void menu_ta_loadFiles(void) {
    Ncgr *a = NULL;
    Nclr *b = NULL;
    Ncgr *c = NULL;
    Nclr *d = NULL;
    Nscr *e = NULL;

    g2du_getCharacterDataBG(&c, arc_getSceneArcFile(gTimeAttackTopMenuMBNcgrName));
    g2du_getPaletteData(&d, arc_getSceneArcFile(gTimeAttackTopMenuMBNclrName));
    g2du_getScreenData(&e, arc_getSceneArcFile(gTimeAttackTopMenuMNscrName));
    sMenuTaState->mUnk_10 = heap_alloc(sMenuTaState->mHeap, 0x800);
    sMenuTaState->mTimeAttackTopMenuSBncl = arc_getSceneArcFile(gTimeAttackTopMenuSBnclName);
    sMenuTaState->mTimeAttackTopMenuSBnbl = arc_getSceneArcFile(gTimeAttackTopMenuSBnblName);
    g2du_getCharacterData(&a, arc_getSceneArcFile(gTimeAttackTopMenuSNcgrName));
    g2du_getCellBankData(&sMenuTaState->mTimeAttackTopMenuSNcer, arc_getSceneArcFile(gTimeAttackTopMenuSNcerName));
    g2du_getPaletteData(&b, arc_getSceneArcFile(gTimeAttackTopMenuSONclrName));
    NNS_GfdRegisterNewVramTransferTask(4, 0, c->mData, c->mDataSize);
    NNS_GfdRegisterNewVramTransferTask(0xf, 0, d->mData, 0x20);
    NNS_GfdRegisterNewVramTransferTask(8, 0, &e->mData, e->mDataSize);
    NNS_GfdRegisterNewVramTransferTask(8, 0x800, sMenuTaState->mUnk_10, 0x800);
    NNS_GfdRegisterNewVramTransferTask(0x23, 0, a->mData, a->mDataSize);
    NNS_GfdRegisterNewVramTransferTask(0x1e, 0, b->mData, b->mDataSize);
}

void menu_ta_initFields(void) {
    sMenuTaState->mNextState = 0;
    sMenuTaState->mStateFrames = 0;
    sMenuTaState->mBg0Offset = -192;
}

// Requests state 1: stores mNextState = 1 and zeroes mStateFrames; the next menu_ta_modeSelectRender call copies it to
// mState and runs menu_ta_buttonsBump.
void menu_ta_buttonsFadeInEnd(void) {
    sMenuTaState->mNextState = 1;
    sMenuTaState->mStateFrames = 0;
}

void menu_ta_buttonsBumpEnd(void) {
    sMenuTaState->mNextState = 2;
    sMenuTaState->mStateFrames = 0;
    RequestSelectReturnState1();
}

// Requests state 3: stores mNextState = 3 and zeroes mStateFrames; the next menu_ta_modeSelectRender call copies it to
// mState and runs menu_ta_buttonSelecting.
void menu_ta_waitEnd(void) {
    sMenuTaState->mNextState = 3;
    sMenuTaState->mStateFrames = 0;
}

void menu_ta_buttonSelectingEnd(void) {
    sMenuTaState->mNextState = 4;
    sMenuTaState->mStateFrames = 0;
    switch (sMenuTaState->mIndex) {
        case 1:
        case 2:
            RequestSelectReturnState4();
            break;
    }
    NNS_SndArcPlayerStartSeqArc(&data_0217d068, 0, 5);
}

// Requests state 5: stores mNextState = 5 and zeroes mStateFrames; the next menu_ta_modeSelectRender call copies it to
// mState and runs menu_ta_buttonsFadeOut.
void menu_ta_buttonSelectedEnd(void) {
    sMenuTaState->mNextState = 5;
    sMenuTaState->mStateFrames = 0;
}

void menu_ta_setButtonHighlightVisible(s32 a) {
    sMenuTaState->mTimeAttackTopMenuSTable[sButtonHighlightsTable[a]].mVisible = 1;
    jn_ui_setCellCparam(sElementsTableD[a], 0xe, sMenuTaState->mTimeAttackTopMenuSNcer,
                        sMenuTaState->mTimeAttackTopMenuSBncl);
}

void menu_ta_setButtonHighlightInvisible(s32 a) {
    sMenuTaState->mTimeAttackTopMenuSTable[sButtonHighlightsTable[a]].mVisible = 0;
    jn_ui_setCellCparam(sElementsTableD[a], 0xf, sMenuTaState->mTimeAttackTopMenuSNcer,
                        sMenuTaState->mTimeAttackTopMenuSBncl);
}

void menu_ta_init(void *a, void *b, s32 c) {
    void *heap;
    s32 i;

    reg_G2_BG0CNT = (reg_G2_BG0CNT & 0x43) | 0x9004;
    heap = heap_createSubFrmHeap(a);
    sMenuTaState = heap_alloc(heap, 0x38);
    sMenuTaState->mHeap = heap;
    sMenuTaState->mState = 0;
    sMenuTaState->mUnk_2c = b;
    sMenuTaState->mUnk_30 = c;
    sMenuTaState->mResult = 0;
    menu_ta_initFields();
    if (menu_getPrevState() == 0x1f) {
        if (gStruct217B488->mGhostSceneInitialCallbacksIndex == 0) {
            sMenuTaState->mIndex = 1;
        } else {
            sMenuTaState->mIndex = 2;
        }
    } else {
        sMenuTaState->mIndex = 0;
    }
    menu_ta_loadFiles();
    for (i = 0; i < 3; i++) {
        jn_ui_setCellIsTranslucent(sButtonShadowsTable[i], 1, sMenuTaState->mTimeAttackTopMenuSNcer,
                      sMenuTaState->mTimeAttackTopMenuSBncl);
    }
    oam_clearResetBuffers(sMenuTaState->mUnk_2c, (void *) sMenuTaState->mUnk_30);
    jn_ui_initLayout(sMenuTaState->mHeap, sMenuTaState->mTimeAttackTopMenuSBncl, NULL,
                    &sMenuTaState->mTimeAttackTopMenuSTable);
    for (i = 0; i < 3; i++) {
        sMenuTaState->mTimeAttackTopMenuSTable[sElementsTableA[i]].mOffsetX = 0xe0;
        sMenuTaState->mTimeAttackTopMenuSTable[sButtonShadowsTable[i]].mOffsetX = 0xe0;
        sMenuTaState->mTimeAttackTopMenuSTable[sButtonHighlightsTable[i]].mOffsetX = 0xe0;
        sMenuTaState->mTimeAttackTopMenuSTable[sElementsTableD[i]].mOffsetX = 0xe0;
        menu_ta_setButtonHighlightInvisible(i);
    }
    sMenuTaState->mTimeAttackTopMenuSTable[12].mOffsetX = 0xe0;
    sMenuTaState->mTimeAttackTopMenuSTable[13].mOffsetX = 0xe0;
    menu_ta_setButtonHighlightVisible(sMenuTaState->mIndex);
    heap_adjustSubFrmHeap(sMenuTaState->mHeap);
}

void menu_ta_destroy(void) {
    heap_destroySubHeap(sMenuTaState->mHeap);
    sMenuTaState = NULL;
}

void menu_ta_buttonsFadeIn(void) {
    s16 v;
    s32 i;

    sMenuTaState->mStateFrames++;
    v = mutil_interpolate(1, 0xe0, 0, sMenuTaState->mStateFrames, 10);
    sMenuTaState->mBg0Offset = mutil_interpolate(1, -192, 0, sMenuTaState->mStateFrames, 10);
    for (i = 0; i < 3; i++) {
        sMenuTaState->mTimeAttackTopMenuSTable[sElementsTableA[i]].mOffsetX = v;
        sMenuTaState->mTimeAttackTopMenuSTable[sButtonShadowsTable[i]].mOffsetX = v;
        sMenuTaState->mTimeAttackTopMenuSTable[sButtonHighlightsTable[i]].mOffsetX = v;
        sMenuTaState->mTimeAttackTopMenuSTable[sElementsTableD[i]].mOffsetX = v;
    }
    sMenuTaState->mTimeAttackTopMenuSTable[12].mOffsetX = v;
    sMenuTaState->mTimeAttackTopMenuSTable[13].mOffsetX = v;
    if (sMenuTaState->mStateFrames >= 10) {
        menu_ta_buttonsFadeInEnd();
    }
}

void menu_ta_buttonsBump(void) {
    s16 v;
    s32 i;

    sMenuTaState->mStateFrames++;
    v = mutil_getButtonOutEffectOffset(sMenuTaState->mStateFrames);
    for (i = 0; i < 3; i++) {
        sMenuTaState->mTimeAttackTopMenuSTable[sElementsTableA[i]].mOffsetX = v;
        sMenuTaState->mTimeAttackTopMenuSTable[sButtonShadowsTable[i]].mOffsetX = v;
        sMenuTaState->mTimeAttackTopMenuSTable[sButtonHighlightsTable[i]].mOffsetX = v;
        sMenuTaState->mTimeAttackTopMenuSTable[sElementsTableD[i]].mOffsetX = v;
    }
    sMenuTaState->mTimeAttackTopMenuSTable[12].mOffsetX = v;
    sMenuTaState->mTimeAttackTopMenuSTable[13].mOffsetX = v;
    if (sMenuTaState->mStateFrames >= 10) {
        menu_ta_buttonsBumpEnd();
    }
}

void menu_ta_wait(void) {
    if (IsSelectReturnState2NoState3Or4Request() != 0) {
        menu_ta_waitEnd();
    }
}

void menu_ta_buttonSelecting(void) {
    BOOL flag2 = FALSE;
    u32 sel = -1;
    s32 dir = 3;
    InputSlotIndex i = UNK_02175628_INDEX_8;
    BOOL flag1 = FALSE;
    InputSlot *e;
    s32 bits;
    BOOL flag4;
    s32 flag3;

    if (gInputUnits[i].mHasPair == 0 && gInputUnits[i].mNoPairCount < 5) {
        flag1 = TRUE;
    }
    if (flag1 == FALSE && gInputUnits[i].mPrevHasPair == 0 && gInputUnits[i].mHasPair != 0) {
        flag2 = TRUE;
    }
    if (flag2 != FALSE) {
        sel = jn_ui_checkTouch(sMenuTaState->mTimeAttackTopMenuSBnbl, gInputUnits[i].mPairX,
                                      gInputUnits[i].mPairY);
    }
    e = &gInputUnits[i];
    bits = e->mPressedBits & PAD_KEY_B;
    if ((u16) bits == 0) {
        flag3 = flag4 = FALSE;
        if (gInputUnits[i].mHasPair == 0 && gInputUnits[i].mNoPairCount < 5) {
            flag3 = 1;
        }
        if (flag3 == 0 && gInputUnits[i].mPrevHasPair == 0 && gInputUnits[i].mHasPair != 0) {
            flag4 = TRUE;
        }
        if (flag4 == FALSE || gmenu_checkSelectReturnTouch(gInputUnits[i].mPairX,
                                                                              gInputUnits[i].mPairY) == FALSE) {
            goto next;
        }
    }
    gmenu_setSeqArcIndex(0xe);
    menu_ta_buttonSelectedEnd();
    sMenuTaState->mResult = 4;
    RequestSelectReturnState3WithSound(0);
    return;
next:
    bits = e->mPressedBits & PAD_KEY_A;
    if ((u16) bits != 0 || sel <= 2) {
        if ((u16) bits == 0) {
            menu_ta_setButtonHighlightInvisible(sMenuTaState->mIndex);
            switch (sel) {
                case 0:
                    dir = 0;
                    break;
                case 1:
                    dir = 1;
                    break;
                case 2:
                    dir = 2;
                    break;
            }
            if (sMenuTaState->mIndex != dir) {
                sMenuTaState->mIndex = dir;
                menu_ta_setButtonHighlightVisible(sMenuTaState->mIndex);
            }
        } else {
            menu_ta_setButtonHighlightInvisible(sMenuTaState->mIndex);
        }
        switch (sMenuTaState->mIndex) {
            case 0:
                sMenuTaState->mResult = 1;
                break;
            case 1:
                sMenuTaState->mResult = 2;
                break;
            case 2:
                sMenuTaState->mResult = 3;
                break;
        }
        menu_ta_buttonSelectingEnd();
    } else {
        if (mutil_checkKeys(8, PAD_KEY_UP) != 0) {
            menu_ta_setButtonHighlightInvisible(sMenuTaState->mIndex);
            sMenuTaState->mIndex--;
            if (sMenuTaState->mIndex < 0) {
                sMenuTaState->mIndex = 2;
            }
            menu_ta_setButtonHighlightVisible(sMenuTaState->mIndex);
            NNS_SndArcPlayerStartSeqArc(&data_0217d068, 0, 0);
        } else if (mutil_checkKeys(8, PAD_KEY_DOWN) != 0) {
            menu_ta_setButtonHighlightInvisible(sMenuTaState->mIndex);
            sMenuTaState->mIndex++;
            if (sMenuTaState->mIndex >= 3) {
                sMenuTaState->mIndex = 0;
            }
            menu_ta_setButtonHighlightVisible(sMenuTaState->mIndex);
            NNS_SndArcPlayerStartSeqArc(&data_0217d068, 0, 0);
        }
    }
}

void menu_ta_buttonSelected(void) {
    s16 v;

    sMenuTaState->mStateFrames++;
    v = mutil_getButtonOutEffectOffset(sMenuTaState->mStateFrames);
    sMenuTaState->mTimeAttackTopMenuSTable[sElementsTableA[sMenuTaState->mIndex]].mOffsetX = v;
    sMenuTaState->mTimeAttackTopMenuSTable[sButtonShadowsTable[sMenuTaState->mIndex]].mOffsetX = v;
    sMenuTaState->mTimeAttackTopMenuSTable[sButtonHighlightsTable[sMenuTaState->mIndex]].mOffsetX = v;
    sMenuTaState->mTimeAttackTopMenuSTable[sElementsTableD[sMenuTaState->mIndex]].mOffsetX = v;
    switch (sMenuTaState->mIndex) {
        case 1:
            sMenuTaState->mTimeAttackTopMenuSTable[12].mOffsetX = v;
            break;
        case 2:
            sMenuTaState->mTimeAttackTopMenuSTable[13].mOffsetX = v;
            break;
    }
    if (sMenuTaState->mStateFrames == 5) {
        menu_ta_setButtonHighlightVisible(sMenuTaState->mIndex);
    }
    if (sMenuTaState->mStateFrames >= 10) {
        menu_ta_buttonSelectedEnd();
    }
}

void menu_ta_buttonsFadeOut(void) {
    s16 v;
    s32 i;

    sMenuTaState->mStateFrames++;
    v = mutil_interpolate(1, 0, 0xe0, sMenuTaState->mStateFrames, 10);
    sMenuTaState->mBg0Offset = mutil_interpolate(1, 0, -192, sMenuTaState->mStateFrames, 10);
    for (i = 0; i < 3; i++) {
        sMenuTaState->mTimeAttackTopMenuSTable[sElementsTableA[i]].mOffsetX = v;
        sMenuTaState->mTimeAttackTopMenuSTable[sButtonShadowsTable[i]].mOffsetX = v;
        sMenuTaState->mTimeAttackTopMenuSTable[sButtonHighlightsTable[i]].mOffsetX = v;
        sMenuTaState->mTimeAttackTopMenuSTable[sElementsTableD[i]].mOffsetX = v;
    }
    sMenuTaState->mTimeAttackTopMenuSTable[12].mOffsetX = v;
    sMenuTaState->mTimeAttackTopMenuSTable[13].mOffsetX = v;
}

s32 menu_ta_modeSelectRender(void) {
    sMenuTaState->mState = sMenuTaState->mNextState;
    switch (sMenuTaState->mState) {
        case 0:
            menu_ta_buttonsFadeIn();
            break;
        case 1:
            menu_ta_buttonsBump();
            break;
        case 2:
            menu_ta_wait();
            break;
        case 3:
            menu_ta_buttonSelecting();
            break;
        case 4:
            menu_ta_buttonSelected();
            break;
        case 5:
            menu_ta_buttonsFadeOut();
            break;
    }
    jn_ui_renderElements(sMenuTaState->mTimeAttackTopMenuSBncl, sMenuTaState->mTimeAttackTopMenuSNcer, NULL,
                    (void *) sMenuTaState->mUnk_30, sMenuTaState->mTimeAttackTopMenuSTable);
    if (sMenuTaState->mState == 5 && sMenuTaState->mStateFrames >= 10) {
        return sMenuTaState->mResult;
    }
    return 0;
}

void menu_ta_updateMainText(void) {
    reg_G2_BG0OFS = (-sMenuTaState->mBg0Offset << 16) & 0x1ff0000;
}
