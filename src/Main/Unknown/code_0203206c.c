#include "Main/Unknown/code_0203206c.h"
#include "Main/Unknown/code_0202578c.h"
#include "Main/Unknown/code_02025000.h"
#include "Main/Unknown/code_02029890.h"
#include "Main/Unknown/code_0202b604.h"
#include "Main/Unknown/code_02036000.h"
#include "Main/System/Heap.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_02047104.h"
#include "Main/Unknown/code_02050080.h"
#include "Main/Unknown/code_02054f58.h"
#include "Main/Unknown/code_020ae408.h"
#include "Main/Unknown/code_020ade08.h"
#include "Main/Unknown/code_020b3f7c.h"
#include "Main/Unknown/code_020b47d8.h"
#include "Main/Unknown/code_020cee0c.h"
#include "Main/Unknown/code_0211d4a8.h"
#include "Main/Unknown/code_0212775c.h"
#include "Main/Unknown/code_021277ac.h"
#include "Main/Unknown/code_02124094.h"
#include "Main/Unknown/code_02124bf0.h"
#include "Main/Unknown/code_02128210.h"
#include "Main/Unknown/code_02128274.h"
#include "code_02148950.h"
#include "Main/Unknown/code_0214d000.h"
#include "Main/Unknown/unk_02175000.h"
#include "Main/Unknown/unk_02175628.h"
#include "Main/Unknown/unk_0217a000.h"
#include "Main/Unknown/unk_0217d068.h"
#include "00/code_02181f98.h"
#include "code_0201ea58.h"
#include "code_0212df7c.h"
#include "code_0214d018.h"
#include "registers.h"

#pragma thumb on

void func_02032a20(void) {
    BOOL battleKind;

    if (gSelectGame->mMode == 0) {
        menu_getRaceConfig()->mMode = 2;
        switch (gSelectGame->mSelectedIndex) {
            case 0:
                battleKind = FALSE;
                break;
            default:
                battleKind = TRUE;
                break;
        }
        menu_getRaceConfig()->mBattleKind = battleKind;
    } else if (gSelectGame->mSelectedIndex == 0) {
        menu_getRaceConfig()->mMode = 3;
    } else {
        menu_getRaceConfig()->mMode = 2;
        switch (gSelectGame->mSelectedIndex) {
            case 1:
                battleKind = FALSE;
                break;
            default:
                battleKind = TRUE;
                break;
        }
        menu_getRaceConfig()->mBattleKind = battleKind;
    }
    gSelectGame->mResult = 1;
    gSelectGame->mState = 5;
    NNS_SndArcPlayerStartSeqArc(&data_0217d068, 0, 5);
}

void SetSelectGameRowCellsVisible(s32 visible) {
    s32 i;
    CellFileSet *subFileSet;

    if (((Unk027ffc40 *) 0x027ffc40)->mUnk_00 != 2) {
        subFileSet = &gSelectGame->mCellFileSets[1];
        for (i = 0; i < gSelectGame->mTableCount; i++) {
            subFileSet->mCellTable[gSelectGame->mTable[i].mCellIndex].mVisible = visible;
        }
    }
}

void SetSelectGameRowOffsetX(void) {
    s32 i;
    CellFileSet *subFileSet;

    subFileSet = &gSelectGame->mCellFileSets[1];
    for (i = 0; i < gSelectGame->mTableCount; i++) {
        subFileSet->mCellTable[gSelectGame->mTable[i].mSelectedCellIndex].mOffsetX = gSelectGame->mSubOffsetX;
    }
}

void SetSelectGameCellTableOffsets(void) {
    CellFileSet *subFileSet;
    s32 i;
    s32 mainCellCount;
    s32 m;
    SelectGame *selectGame;

    if (((Unk027ffc40 *) 0x027ffc40)->mUnk_00 != 2) {
        selectGame = gSelectGame;
        mainCellCount = selectGame->mCellFileSets[0].mCellLayout->mUnk_06;
        m = selectGame->mCellFileSets[0].mLabelLayout->mUnk_06;
        for (i = 0; i < m; i++) {
            selectGame->mCellFileSets[0].mCellTable[i + mainCellCount].mOffsetY = gSelectGame->mMainOffsetY;
        }
    }
    subFileSet = &gSelectGame->mCellFileSets[1];
    m = subFileSet->mCellLayout->mUnk_06;
    for (i = 0; i < m; i++) {
        subFileSet->mCellTable[i].mOffsetX = gSelectGame->mSubOffsetX;
    }
}

void SetSelectGameSelectedRowVisible(s32 showSelected) {
    BOOL visible;
    s32 i;
    CellFileSet *subFileSet;

    subFileSet = &gSelectGame->mCellFileSets[1];
    for (i = 0; i < gSelectGame->mTableCount; i++) {
        if (i == gSelectGame->mSelectedIndex && showSelected != 0) {
            visible = TRUE;
        } else {
            visible = FALSE;
        }
        subFileSet->mCellTable[gSelectGame->mTable[i].mSelectedCellIndex].mVisible = visible;
    }
}

void SetSelectGameSubCellsVisible(s32 visible) {
    s32 i;
    CellFileSet *subFileSet;

    subFileSet = &gSelectGame->mCellFileSets[1];
    for (i = 0; i < subFileSet->mCellLayout->mUnk_06; i++) {
        subFileSet->mCellTable[i].mVisible = visible;
    }
}

void SPM_LoadBattleMenu(void *parentHeap, s32 mode, void *mainOam, void *subOam) {
    void *heap;
    SelectGame *selectGame;
    CellFileSet *subFileSet;
    u8 screenMapFileSet[0x28];
    u32 mainObjSizeLeft;
    s32 i;
    s32 mainCellCount;
    s32 mainLabelCount;
    s32 j;
    s32 hiddenLabelStart;
    s32 hiddenLabelCount;
    LabelMessageRow *canvasRow;
    LabelMessageRow *printRow;

    heap = heap_createSubFrmHeap(parentHeap);
    gSelectGame = heap_alloc(heap, 0x6c);
    MemFillWordsByBlock_inline(gSelectGame, 0x6c);
    gSelectGame->mHeap = heap;
    gSelectGame->mMode = mode;
    gSelectGame->mMainOam = mainOam;
    gSelectGame->mSubOam = subOam;
    gSelectGame->mSubOffsetX = 0xee;
    gSelectGame->mMainOffsetY = -0xc0;
    if (((Unk027ffc40 *) 0x027ffc40)->mUnk_00 != 2) {
        gSelectGame->mMenuMessages = arc_getSceneArcFile(aMenu_bmg_0);
    }
    switch (gSelectGame->mMode) {
        case 0:
            gSelectGame->mState = 3;
            gSelectGame->mTableCount = 2;
            gSelectGame->mTable = data_02153de8;
            break;
        case 1:
            gSelectGame->mState = 3;
            gSelectGame->mTableCount = 3;
            gSelectGame->mTable = data_02153df4;
            func_02050080();
            break;
    }
    if (((Unk027ffc40 *) 0x027ffc40)->mUnk_00 != 2) {
        mutil2_initBgGraphics(0, screenMapFileSet, aCommonSelect_game_m_b_ncgr_0, aCommonSelect_game_m_b_nclr_0,
                      data_02153e10[gSelectGame->mMode].mUnk_00, 1, arc_getSceneArcFile);
    }
    if (((Unk027ffc40 *) 0x027ffc40)->mUnk_00 != 2) {
        mainObjSizeLeft = GX_GetSizeOfOBJ();
        selectGame = gSelectGame;
        mutil2_loadLayout(selectGame, aCommonSelect_game_m_nce_ncgr_0, aCommonSelect_game_m_nce_ncer_0, aCommonSelect_game_m_o_nclr_0,
                          aCommonSelect_game_m_bncl, aCommonSelect_game_m_bnll, NULL, arc_getSceneArcFile);
        mutil2_initLayout(0, gSelectGame->mHeap, selectGame);
        mainCellCount = selectGame->mCellFileSets[0].mCellLayout->mUnk_06;
        mainLabelCount = selectGame->mCellFileSets[0].mLabelLayout->mUnk_06;
        i = 0;
        if (mainLabelCount > 0) {
            canvasRow = gSelectGameLabelMessageRows;
            printRow = canvasRow;
            do {
                mainObjSizeLeft -= mutil2_initLabel(0, gSelectGame->mHeap, selectGame, canvasRow, mainObjSizeLeft);
                jn_ui_212426C(0, printRow->mLabelIndex, selectGame->mCellFileSets[0].mLabelLayout,
                              jn_msg_getMessage(gSelectGame->mMenuMessages, printRow->mMessageIndex),
                              selectGame->mCellFileSets[0].mCellLayout, selectGame->mCellFileSets[0].mCellTable);
                canvasRow++;
                printRow++;
                i++;
            } while (i < mainLabelCount);
        }
        if (gSelectGame->mMode == 0) {
            hiddenLabelStart = 4;
            hiddenLabelCount = 6;
        } else {
            hiddenLabelStart = 0;
            hiddenLabelCount = 4;
        }
        for (j = hiddenLabelStart; j < hiddenLabelStart + hiddenLabelCount; j++) {
            selectGame->mCellFileSets[0].mCellTable[j + mainCellCount].mVisible = 0;
        }
    }
    subFileSet = &gSelectGame->mCellFileSets[1];
    mutil2_loadLayout(subFileSet, aCommonSelect_game_s_nce_ncgr_0, aCommonSelect_game_s_nce_ncer_0, aCommonSelect_game_s_o_nclr_0,
                      data_02153e08[gSelectGame->mMode].mUnk_00, NULL, data_02153e0c[gSelectGame->mMode].mUnk_00,
                      arc_getSceneArcFile);
    mutil2_initLayout(1, gSelectGame->mHeap, subFileSet);
    SetSelectGameSubCellsVisible(0);
    if (((Unk027ffc40 *) 0x027ffc40)->mUnk_00 == 2) {
        gmenu_setSeqArcIndex(-1);
    } else {
        gmenu_setSeqArcIndex(0xe);
    }
    RequestSelectReturnState1();
    if (gSelectGame->mMode == 1) {
        SetSelectChoisesSoundId(0, 5);
        SetSelectChoisesSoundId(1, 0xf);
    }
    gStruct217B488->mUnk_08 = 0;
    heap_adjustSubFrmHeap(gSelectGame->mHeap);
}

s32 AdvanceSelectGame(void) {
    s32 a;
    InputSlotIndex slotIndex;
    SelectGame *selectGame;
    CellFileSet *subFileSet;
    s32 previousSelectedIndex;
    s32 touchInReturnRect;
    s32 d;
    BOOL pairIsNew;
    BOOL pairRecentlyGone;
    s32 pairY;
    s32 h;
    u32 hasPair;
    s32 i;
    const void *firstChoiceText;
    const void *secondChoiceText;

    a = 0;
    slotIndex = UNK_02175628_INDEX_8;
    selectGame = gSelectGame;
    subFileSet = &selectGame->mCellFileSets[1];
    switch (selectGame->mState) {
        case 3:
            SetSelectGameSubCellsVisible(1);
            SetSelectGameSelectedRowVisible(1);
            gSelectGame->mStateFrames = gSelectGame->mStateFrames + 1;
            if (gSelectGame->mStateFrames < 10) {
                gSelectGame->mSubOffsetX = mutil_interpolate(1, 0xee, a, gSelectGame->mStateFrames, 10);
                gSelectGame->mMainOffsetY = mutil_interpolate(1, -0xc0, a, gSelectGame->mStateFrames, 10);
            } else {
                gSelectGame->mStateFrames = a;
                gSelectGame->mSubOffsetX = a;
                gSelectGame->mMainOffsetY = a;
                gSelectGame->mState = 4;
            }
            SetSelectGameCellTableOffsets();
            break;
        case 4:
            previousSelectedIndex = selectGame->mSelectedIndex;
            d = ~a;
            touchInReturnRect = 0;
            pairIsNew = FALSE;
            pairRecentlyGone = FALSE;
            hasPair = gInputUnits[slotIndex].mHasPair;
            if (hasPair == 0 && gInputUnits[slotIndex].mNoPairCount < 5) {
                pairRecentlyGone = TRUE;
            }
            if (pairRecentlyGone == FALSE && gInputUnits[slotIndex].mPrevHasPair == 0 && hasPair != 0) {
                pairIsNew = TRUE;
            }
            if (pairIsNew != FALSE) {
                d = gInputUnits[slotIndex].mPairX;
                pairY = gInputUnits[slotIndex].mPairY;
                touchInReturnRect = gmenu_checkSelectReturnTouch(d, pairY);
                d = jn_ui_checkTouch(subFileSet->mRects, d, pairY);
            }
            if ((u16) (gInputUnits[slotIndex].mPressedBits & PAD_KEY_A) != 0) {
                SetSelectGameSelectedRowVisible(0);
                func_02032a20();
            } else if (d >= 0) {
                for (i = 0; i < gSelectGame->mTableCount; i++) {
                    if (d == gSelectGame->mTable[i].mRectEntryId) {
                        SetSelectGameSelectedRowVisible(gSelectGame->mSelectedIndex != i ? 1 : 0);
                        gSelectGame->mSelectedIndex = i;
                        func_02032a20();
                        break;
                    }
                }
            } else if ((u16) (gInputUnits[slotIndex].mPressedBits & PAD_KEY_B) != 0 || touchInReturnRect != 0) {
                if (gSelectGame->mMode == 0) {
                    gSelectGame->mResult = 2;
                    gSelectGame->mState = 9;
                } else {
                    firstChoiceText = data_02163aec;
                    secondChoiceText = data_02163af0;
                    if (((Unk027ffc40 *) 0x027ffc40)->mUnk_00 != 2) {
                        firstChoiceText = jn_msg_getMessage(gSelectGame->mMenuMessages, 0x14);
                        secondChoiceText = jn_msg_getMessage(gSelectGame->mMenuMessages, 0x16);
                    }
                    gmenu_startSelectChoices(firstChoiceText, secondChoiceText, 0);
                    gSelectGame->mState = 7;
                    SetSelectGameRowCellsVisible(0);
                }
                RequestSelectReturnState3WithSound(0);
            } else if (mutil_checkKeys(8, PAD_KEY_UP) != 0) {
                if (gSelectGame->mSelectedIndex == 0) {
                    if (gSelectGame->mMode == 1) {
                        gSelectGame->mSelectedIndex = gSelectGame->mTableCount - 1;
                    }
                } else {
                    gSelectGame->mSelectedIndex = gSelectGame->mSelectedIndex - 1;
                }
            } else if (mutil_checkKeys(8, PAD_KEY_DOWN) != 0) {
                if (gSelectGame->mSelectedIndex == gSelectGame->mTableCount - 1) {
                    if (gSelectGame->mMode == 1) {
                        gSelectGame->mSelectedIndex = 0;
                    }
                } else {
                    gSelectGame->mSelectedIndex = gSelectGame->mSelectedIndex + 1;
                }
            }
            if (d < 0 && previousSelectedIndex != gSelectGame->mSelectedIndex) {
                SetSelectGameSelectedRowVisible(1);
                NNS_SndArcPlayerStartSeqArc(&data_0217d068, 0, 0);
            }
            break;
        case 7:
            if (GetSelectChoisesDone() != 0) {
                if (GetSelectChoisesIndex() == 0 || GetSelectChoisesIndex() == ~a) {
                    gSelectGame->mState = 4;
                } else {
                    gStruct217AA00->mUnk_0454 |= 0x80;
                    gSelectGame->mResult = 3;
                    gSelectGame->mState = 8;
                }
                SetSelectGameRowCellsVisible(1);
                RequestSelectChoisesState0();
            }
            break;
        case 8:
            if (func_02054f58() == 1) {
                a = gSelectGame->mResult;
                gSelectGame->mState = 11;
            }
            break;
        case 5:
            selectGame->mStateFrames = selectGame->mStateFrames + 1;
            if (gSelectGame->mStateFrames >= 5) {
                gSelectGame->mStateFrames = a;
                gSelectGame->mState = 6;
                SetSelectGameSelectedRowVisible(1);
            }
            break;
        case 6:
            selectGame->mStateFrames = selectGame->mStateFrames + 1;
            if (gSelectGame->mStateFrames < 10) {
                gSelectGame->mSubOffsetX = mutil_getButtonOutEffectOffset(gSelectGame->mStateFrames);
            } else {
                gSelectGame->mStateFrames = a;
                gSelectGame->mState = 9;
                if (gSelectGame->mMode != 0) {
                    RequestSelectReturnState4();
                }
            }
            SetSelectGameRowOffsetX();
            break;
        case 9:
            selectGame->mStateFrames = selectGame->mStateFrames + 1;
            if (gSelectGame->mStateFrames < 10) {
                gSelectGame->mSubOffsetX = mutil_interpolate(1, a, 0xee, gSelectGame->mStateFrames, 10);
                gSelectGame->mMainOffsetY = mutil_interpolate(1, a, -0xc0, gSelectGame->mStateFrames, 10);
            } else {
                gSelectGame->mSubOffsetX = a;
                gSelectGame->mMainOffsetY = a;
                gSelectGame->mState = 10;
            }
            SetSelectGameCellTableOffsets();
            break;
        case 10:
            a = selectGame->mResult;
            break;
    }
    if (gSelectGame->mState != 10) {
        if (((Unk027ffc40 *) 0x027ffc40)->mUnk_00 != 2) {
            jn_ui_renderElements(selectGame->mCellFileSets[0].mCellLayout, selectGame->mCellFileSets[0].mCells,
                            selectGame->mCellFileSets[0].mLabelLayout, gSelectGame->mMainOam,
                            selectGame->mCellFileSets[0].mCellTable);
        }
        jn_ui_renderElements(subFileSet->mCellLayout, subFileSet->mCells, subFileSet->mLabelLayout, gSelectGame->mSubOam,
                        subFileSet->mCellTable);
    }
    return a;
}

void ReleaseSelectGame(void) {
    if (gSelectGame->mMode == 1) {
        RequestPlayerEntryListSetup();
        if (gSystemData->mUnk_1c_2 != 0) {
            FillShuffledIndices();
        }
    }
    heap_destroySubHeap(gSelectGame->mHeap);
    gSelectGame = NULL;
}

void func_02032138(void) {
    u32 displayBits;
    u32 bgControlBits;
    s32 windowEndY;

    displayBits = 0x18;
    bgControlBits = 0;
    if (gSelectGame->mState != 10) {
        displayBits |= 2;
        bgControlBits = 3;
    }
    reg_GX_DISPCNT = (reg_GX_DISPCNT & 0xffffe0ff) | (displayBits << 8);
    reg_G2_BG1CNT = (reg_G2_BG1CNT & ~3) | bgControlBits;
    reg_G2_BG1OFS = (-gSelectGame->mMainOffsetY << 16) & 0x1ff0000;
    if (gSelectGame->mMainOffsetY != 0) {
        reg_GX_DISPCNT = (reg_GX_DISPCNT & 0xffff1fff) | 0x6000;
        reg_G2_WININ = (u32) ((reg_G2_WININ & ~0x3f) | 0x1f) | 0x20;
        reg_G2_WININ = (u32) ((reg_G2_WININ & 0xffffc0ff) | 0x1f00) | 0x2000;
        reg_G2_WINOUT = (u32) ((reg_G2_WINOUT & ~0x3f) | 0xd) | 0x20;
        windowEndY = gSelectGame->mMainOffsetY + 0xc0;
        reg_G2_WIN0H = 0xff;
        reg_G2_WIN0V = windowEndY & 0xff;
        windowEndY = gSelectGame->mMainOffsetY + 0xc0;
        reg_G2_WIN1H = 0xff00;
        reg_G2_WIN1V = windowEndY & 0xff;
    } else {
        reg_GX_DISPCNT = reg_GX_DISPCNT & 0xffff1fff;
    }
}

void LoadSelectGameData(void) {
    Ncgr *chars;
    Nclr *palette;
    Unk02021dc8 *cells;
    Nscr *screenMap;

    if (((Unk027ffc40 *) 0x027ffc40)->mUnk_00 != 2) {
        g2du_unpackCharacterDataBG(&chars, arc_getSceneArcFile(aCommonSelect_game_m_b_ncgr));
        g2du_unpackCharacterData(&chars, arc_getSceneArcFile(aCommonSelect_game_m_nce_ncgr));
        g2du_unpackCellBankData(&cells, arc_getSceneArcFile(aCommonSelect_game_m_nce_ncer));
        g2du_unpackPaletteData(&palette, arc_getSceneArcFile(aCommonSelect_game_m_b_nclr));
        g2du_unpackPaletteData(&palette, arc_getSceneArcFile(aCommonSelect_game_m_o_nclr));
        g2du_unpackScreenData(&screenMap, arc_getSceneArcFile(aCommonSelect_game_m_multi_nscr));
        g2du_unpackScreenData(&screenMap, arc_getSceneArcFile(aCommonSelect_game_m_single_nscr));
    }
    g2du_unpackCharacterData(&chars, arc_getSceneArcFile(aCommonSelect_game_s_nce_ncgr));
    g2du_unpackCellBankData(&cells, arc_getSceneArcFile(aCommonSelect_game_s_nce_ncer));
    g2du_unpackPaletteData(&palette, arc_getSceneArcFile(aCommonSelect_game_s_o_nclr));
}

#pragma thumb off
