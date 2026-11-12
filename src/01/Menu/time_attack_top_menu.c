#include "01/Menu/time_attack_top_menu.h"

#include "01/Menu/record_time_attack.h"
#include "00/Menu/wi_fi_vs_setting.h"
#include "Main/System/heap.h"
#include "Main/Graphics/oam.h"
#include "Main/Graphics/font_and_player_character.h"
#include "Main/Menu/second_menu_scene.h"
#include "01/code_02198000.h"
#include "01/unk_021a6000.h"
#include "01/unk_021a9000.h"
#include "Main/Graphics/layout_rect_table.h"
#include "Main/Menu/menu_screen_switch.h"
#include "Main/Menu/data_0217d068.h"
#include "player.h"
#include "01/unk_021a8000.h"
#include "code_0212df7c.h"
#include "Main/System/result_archive_path.h"
#include "registers.h"

char *gTimeAttackTopMenuSNcgrName = "ta/TimeAttack_top_menu_s.nce.ncgr";
char *gTimeAttackTopMenuSNcerName = "ta/TimeAttack_top_menu_s.nce.ncer";
const u16 gTimeAttackTopMenuPaletteCellIndices[3] = {9, 0xa, 0xb};
char *gTimeAttackTopMenuMNscrName = "ta/TimeAttack_top_menu_m.nscr";
char *gTimeAttackTopMenuSBnblName = "ta/TimeAttack_top_menu_s.bnbl";
const u16 gTimeAttackTopMenuOffsetIndices[3] = {3, 4, 5};
char *gTimeAttackTopMenuMBNcgrName = "ta/TimeAttack_top_menu_m_b.ncgr";
char *gTimeAttackTopMenuMBNclrName = "ta/TimeAttack_top_menu_m_b.nclr";
const u16 gTimeAttackTopMenuVisibleTableIndices[3] = {6, 7, 8};
char *gTimeAttackTopMenuSONclrName = "ta/TimeAttack_top_menu_s_o.nclr";
char *gTimeAttackTopMenuSBnclName = "ta/TimeAttack_top_menu_s.bncl";
const u16 gTimeAttackTopMenuXluCellIndices[3] = {0, 1, 2};
TimeAttackTopMenu *gTimeAttackTopMenu;

void LoadTimeAttackTopMenuData(void) {
    Ncgr *sNcgr = NULL;
    Unk02021dc8 *sNcer = NULL;
    Nclr *soNclr = NULL;
    Ncgr *mbNcgr = NULL;
    Nclr *mbNclr = NULL;
    Nscr *mNscr = NULL;

    LoadNcgrData(&mbNcgr, FindSceneFile(gTimeAttackTopMenuMBNcgrName));
    LoadNclrData(&mbNclr, FindSceneFile(gTimeAttackTopMenuMBNclrName));
    LoadNscrData(&mNscr, FindSceneFile(gTimeAttackTopMenuMNscrName));
    LoadNcgrData2(&sNcgr, FindSceneFile(gTimeAttackTopMenuSNcgrName));
    LoadNcerData(&sNcer, FindSceneFile(gTimeAttackTopMenuSNcerName));
    LoadNclrData(&soNclr, FindSceneFile(gTimeAttackTopMenuSONclrName));
}

void LocateAndQueueTimeAttackTopMenu(void) {
    Ncgr *sNcgr = NULL;
    Nclr *soNclr = NULL;
    Ncgr *mbNcgr = NULL;
    Nclr *mbNclr = NULL;
    Nscr *mNscr = NULL;

    LocateNcgr(&mbNcgr, FindSceneFile(gTimeAttackTopMenuMBNcgrName));
    LocateNclr(&mbNclr, FindSceneFile(gTimeAttackTopMenuMBNclrName));
    LocateNscr(&mNscr, FindSceneFile(gTimeAttackTopMenuMNscrName));
    gTimeAttackTopMenu->mSecondScreenMapBuffer = HeapAlloc(gTimeAttackTopMenu->mHeap, 0x800);
    gTimeAttackTopMenu->mTimeAttackTopMenuSBncl = FindSceneFile(gTimeAttackTopMenuSBnclName);
    gTimeAttackTopMenu->mTimeAttackTopMenuSBnbl = FindSceneFile(gTimeAttackTopMenuSBnblName);
    LocateNcgr2(&sNcgr, FindSceneFile(gTimeAttackTopMenuSNcgrName));
    LocateNcer(&gTimeAttackTopMenu->mTimeAttackTopMenuSNcer, FindSceneFile(gTimeAttackTopMenuSNcerName));
    LocateNclr(&soNclr, FindSceneFile(gTimeAttackTopMenuSONclrName));
    NNS_GfdRegisterNewVramTransferTask(4, 0, mbNcgr->mData, mbNcgr->mDataSize);
    NNS_GfdRegisterNewVramTransferTask(0xf, 0, mbNclr->mData, 0x20);
    NNS_GfdRegisterNewVramTransferTask(8, 0, &mNscr->mData, mNscr->mDataSize);
    NNS_GfdRegisterNewVramTransferTask(8, 0x800, gTimeAttackTopMenu->mSecondScreenMapBuffer, 0x800);
    NNS_GfdRegisterNewVramTransferTask(0x23, 0, sNcgr->mData, sNcgr->mDataSize);
    NNS_GfdRegisterNewVramTransferTask(0x1e, 0, soNclr->mData, soNclr->mDataSize);
}

void RequestTimeAttackTopMenuState0(void) {
    gTimeAttackTopMenu->mNextState = 0;
    gTimeAttackTopMenu->mStateFrames = 0;
    gTimeAttackTopMenu->mBg0Offset = -192;
}

// Requests state 1: stores mNextState = 1 and zeroes mStateFrames; the next AdvanceTimeAttackTopMenu call copies it to
// mState and runs AdvanceTimeAttackTopMenuState1.
void RequestTimeAttackTopMenuState1(void) {
    gTimeAttackTopMenu->mNextState = 1;
    gTimeAttackTopMenu->mStateFrames = 0;
}

void RequestTimeAttackTopMenuState2(void) {
    gTimeAttackTopMenu->mNextState = 2;
    gTimeAttackTopMenu->mStateFrames = 0;
    RequestSelectReturnState1();
}

// Requests state 3: stores mNextState = 3 and zeroes mStateFrames; the next AdvanceTimeAttackTopMenu call copies it to
// mState and runs AdvanceTimeAttackTopMenuState3.
void RequestTimeAttackTopMenuState3(void) {
    gTimeAttackTopMenu->mNextState = 3;
    gTimeAttackTopMenu->mStateFrames = 0;
}

void RequestTimeAttackTopMenuState4(void) {
    gTimeAttackTopMenu->mNextState = 4;
    gTimeAttackTopMenu->mStateFrames = 0;
    switch (gTimeAttackTopMenu->mIndex) {
        case 1:
        case 2:
            RequestSelectReturnState4();
            break;
    }
    NNS_SndArcPlayerStartSeqArc(&gSharedSeqHandle, 0, 5);
}

// Requests state 5: stores mNextState = 5 and zeroes mStateFrames; the next AdvanceTimeAttackTopMenu call copies it to
// mState and runs AdvanceTimeAttackTopMenuState5.
void RequestTimeAttackTopMenuState5(void) {
    gTimeAttackTopMenu->mNextState = 5;
    gTimeAttackTopMenu->mStateFrames = 0;
}

void ShowTimeAttackTopMenuHighlight(s32 a) {
    gTimeAttackTopMenu->mTimeAttackTopMenuSTable[gTimeAttackTopMenuVisibleTableIndices[a]].mVisible = 1;
    SetCellPaletteIndex(gTimeAttackTopMenuPaletteCellIndices[a], 0xe, gTimeAttackTopMenu->mTimeAttackTopMenuSNcer,
                        gTimeAttackTopMenu->mTimeAttackTopMenuSBncl);
}

void HideTimeAttackTopMenuHighlight(s32 a) {
    gTimeAttackTopMenu->mTimeAttackTopMenuSTable[gTimeAttackTopMenuVisibleTableIndices[a]].mVisible = 0;
    SetCellPaletteIndex(gTimeAttackTopMenuPaletteCellIndices[a], 0xf, gTimeAttackTopMenu->mTimeAttackTopMenuSNcer,
                        gTimeAttackTopMenu->mTimeAttackTopMenuSBncl);
}

void InitTimeAttackTopMenu(void *parentHeap, void *mainOam, s32 subOam) {
    void *heap;
    s32 i;

    reg_G2_BG0CNT = (reg_G2_BG0CNT & 0x43) | 0x9004;
    heap = CreateFrmHeapFromMaxFree(parentHeap);
    gTimeAttackTopMenu = HeapAlloc(heap, 0x38);
    gTimeAttackTopMenu->mHeap = heap;
    gTimeAttackTopMenu->mState = 0;
    gTimeAttackTopMenu->mMainOamList = mainOam;
    gTimeAttackTopMenu->mSubOamList = subOam;
    gTimeAttackTopMenu->mResult = 0;
    RequestTimeAttackTopMenuState0();
    if (GetPreviousMenuScreenNumber() == 0x1f) {
        if (gMenuShared->mGhostSceneInitialCallbacksIndex == 0) {
            gTimeAttackTopMenu->mIndex = 1;
        } else {
            gTimeAttackTopMenu->mIndex = 2;
        }
    } else {
        gTimeAttackTopMenu->mIndex = 0;
    }
    LocateAndQueueTimeAttackTopMenu();
    for (i = 0; i < 3; i++) {
        SetCellOamModeXlu(gTimeAttackTopMenuXluCellIndices[i], 1, gTimeAttackTopMenu->mTimeAttackTopMenuSNcer,
                          gTimeAttackTopMenu->mTimeAttackTopMenuSBncl);
    }
    ResetOamLists(gTimeAttackTopMenu->mMainOamList, (void *) gTimeAttackTopMenu->mSubOamList);
    InitLayoutTable(gTimeAttackTopMenu->mHeap, gTimeAttackTopMenu->mTimeAttackTopMenuSBncl, NULL,
                    &gTimeAttackTopMenu->mTimeAttackTopMenuSTable);
    for (i = 0; i < 3; i++) {
        gTimeAttackTopMenu->mTimeAttackTopMenuSTable[gTimeAttackTopMenuOffsetIndices[i]].mOffsetX = 0xe0;
        gTimeAttackTopMenu->mTimeAttackTopMenuSTable[gTimeAttackTopMenuXluCellIndices[i]].mOffsetX = 0xe0;
        gTimeAttackTopMenu->mTimeAttackTopMenuSTable[gTimeAttackTopMenuVisibleTableIndices[i]].mOffsetX = 0xe0;
        gTimeAttackTopMenu->mTimeAttackTopMenuSTable[gTimeAttackTopMenuPaletteCellIndices[i]].mOffsetX = 0xe0;
        HideTimeAttackTopMenuHighlight(i);
    }
    gTimeAttackTopMenu->mTimeAttackTopMenuSTable[12].mOffsetX = 0xe0;
    gTimeAttackTopMenu->mTimeAttackTopMenuSTable[13].mOffsetX = 0xe0;
    ShowTimeAttackTopMenuHighlight(gTimeAttackTopMenu->mIndex);
    FrmHeapShrinkInParent(gTimeAttackTopMenu->mHeap);
}

void ReleaseTimeAttackTopMenu(void) {
    HeapDestroy(gTimeAttackTopMenu->mHeap);
    gTimeAttackTopMenu = NULL;
}

void AdvanceTimeAttackTopMenuState0(void) {
    s16 offsetX;
    s32 i;

    gTimeAttackTopMenu->mStateFrames++;
    offsetX = InterpolateS16(1, 0xe0, 0, gTimeAttackTopMenu->mStateFrames, 10);
    gTimeAttackTopMenu->mBg0Offset = InterpolateS16(1, -192, 0, gTimeAttackTopMenu->mStateFrames, 10);
    for (i = 0; i < 3; i++) {
        gTimeAttackTopMenu->mTimeAttackTopMenuSTable[gTimeAttackTopMenuOffsetIndices[i]].mOffsetX = offsetX;
        gTimeAttackTopMenu->mTimeAttackTopMenuSTable[gTimeAttackTopMenuXluCellIndices[i]].mOffsetX = offsetX;
        gTimeAttackTopMenu->mTimeAttackTopMenuSTable[gTimeAttackTopMenuVisibleTableIndices[i]].mOffsetX = offsetX;
        gTimeAttackTopMenu->mTimeAttackTopMenuSTable[gTimeAttackTopMenuPaletteCellIndices[i]].mOffsetX = offsetX;
    }
    gTimeAttackTopMenu->mTimeAttackTopMenuSTable[12].mOffsetX = offsetX;
    gTimeAttackTopMenu->mTimeAttackTopMenuSTable[13].mOffsetX = offsetX;
    if (gTimeAttackTopMenu->mStateFrames >= 10) {
        RequestTimeAttackTopMenuState1();
    }
}

void AdvanceTimeAttackTopMenuState1(void) {
    s16 selectedPressOffset;
    s32 i;

    gTimeAttackTopMenu->mStateFrames++;
    selectedPressOffset = GetSelectedPressOffset(gTimeAttackTopMenu->mStateFrames);
    for (i = 0; i < 3; i++) {
        gTimeAttackTopMenu->mTimeAttackTopMenuSTable[gTimeAttackTopMenuOffsetIndices[i]].mOffsetX = selectedPressOffset;
        gTimeAttackTopMenu->mTimeAttackTopMenuSTable[gTimeAttackTopMenuXluCellIndices[i]].mOffsetX =
            selectedPressOffset;
        gTimeAttackTopMenu->mTimeAttackTopMenuSTable[gTimeAttackTopMenuVisibleTableIndices[i]].mOffsetX =
            selectedPressOffset;
        gTimeAttackTopMenu->mTimeAttackTopMenuSTable[gTimeAttackTopMenuPaletteCellIndices[i]].mOffsetX =
            selectedPressOffset;
    }
    gTimeAttackTopMenu->mTimeAttackTopMenuSTable[12].mOffsetX = selectedPressOffset;
    gTimeAttackTopMenu->mTimeAttackTopMenuSTable[13].mOffsetX = selectedPressOffset;
    if (gTimeAttackTopMenu->mStateFrames >= 10) {
        RequestTimeAttackTopMenuState2();
    }
}

void AdvanceTimeAttackTopMenuState2(void) {
    if (IsSelectReturnState2NoState3Or4Request() != 0) {
        RequestTimeAttackTopMenuState3();
    }
}

void AdvanceTimeAttackTopMenuState3(void) {
    BOOL touchStarted = FALSE;
    u32 tappedRectIndex = -1;
    s32 newIndex = 3;
    InputSlotIndex slotIndex = UNK_02175628_INDEX_8;
    BOOL flag1 = FALSE;
    InputSlot *inputSlot;
    s32 pressedBits;
    BOOL flag4;
    s32 flag3;

    if (gInputSlots[slotIndex].mPair.mHasPair == 0 && gInputSlots[slotIndex].mPair.mNoPairCount < 5) {
        flag1 = TRUE;
    }
    if (flag1 == FALSE && gInputSlots[slotIndex].mPair.mPrevHasPair == 0 &&
        gInputSlots[slotIndex].mPair.mHasPair != 0) {
        touchStarted = TRUE;
    }
    if (touchStarted != FALSE) {
        tappedRectIndex =
            RectTableFindContaining(gTimeAttackTopMenu->mTimeAttackTopMenuSBnbl, gInputSlots[slotIndex].mPair.mPairX,
                                    gInputSlots[slotIndex].mPair.mPairY);
    }
    inputSlot = &gInputSlots[slotIndex];
    pressedBits = inputSlot->mPressedBits & PAD_KEY_B;
    if ((u16) pressedBits == 0) {
        flag3 = flag4 = FALSE;
        if (gInputSlots[slotIndex].mPair.mHasPair == 0 && gInputSlots[slotIndex].mPair.mNoPairCount < 5) {
            flag3 = 1;
        }
        if (flag3 == 0 && gInputSlots[slotIndex].mPair.mPrevHasPair == 0 &&
            gInputSlots[slotIndex].mPair.mHasPair != 0) {
            flag4 = TRUE;
        }
        if (flag4 == FALSE || IsSelectReturnState2NoState3Or4RequestAndInRect(
                                  gInputSlots[slotIndex].mPair.mPairX, gInputSlots[slotIndex].mPair.mPairY) == FALSE) {
            goto next;
        }
    }
    SetSelectReturnSoundId(0xe);
    RequestTimeAttackTopMenuState5();
    gTimeAttackTopMenu->mResult = 4;
    RequestSelectReturnState3WithSound(0);
    return;
next:
    pressedBits = inputSlot->mPressedBits & PAD_KEY_A;
    if ((u16) pressedBits != 0 || tappedRectIndex <= 2) {
        if ((u16) pressedBits == 0) {
            HideTimeAttackTopMenuHighlight(gTimeAttackTopMenu->mIndex);
            switch (tappedRectIndex) {
                case 0:
                    newIndex = 0;
                    break;
                case 1:
                    newIndex = 1;
                    break;
                case 2:
                    newIndex = 2;
                    break;
            }
            if (gTimeAttackTopMenu->mIndex != newIndex) {
                gTimeAttackTopMenu->mIndex = newIndex;
                ShowTimeAttackTopMenuHighlight(gTimeAttackTopMenu->mIndex);
            }
        } else {
            HideTimeAttackTopMenuHighlight(gTimeAttackTopMenu->mIndex);
        }
        switch (gTimeAttackTopMenu->mIndex) {
            case 0:
                gTimeAttackTopMenu->mResult = 1;
                break;
            case 1:
                gTimeAttackTopMenu->mResult = 2;
                break;
            case 2:
                gTimeAttackTopMenu->mResult = 3;
                break;
        }
        RequestTimeAttackTopMenuState4();
    } else {
        if (GetNewOrRepeatBits(8, PAD_KEY_UP) != 0) {
            HideTimeAttackTopMenuHighlight(gTimeAttackTopMenu->mIndex);
            gTimeAttackTopMenu->mIndex--;
            if (gTimeAttackTopMenu->mIndex < 0) {
                gTimeAttackTopMenu->mIndex = 2;
            }
            ShowTimeAttackTopMenuHighlight(gTimeAttackTopMenu->mIndex);
            NNS_SndArcPlayerStartSeqArc(&gSharedSeqHandle, 0, 0);
        } else if (GetNewOrRepeatBits(8, PAD_KEY_DOWN) != 0) {
            HideTimeAttackTopMenuHighlight(gTimeAttackTopMenu->mIndex);
            gTimeAttackTopMenu->mIndex++;
            if (gTimeAttackTopMenu->mIndex >= 3) {
                gTimeAttackTopMenu->mIndex = 0;
            }
            ShowTimeAttackTopMenuHighlight(gTimeAttackTopMenu->mIndex);
            NNS_SndArcPlayerStartSeqArc(&gSharedSeqHandle, 0, 0);
        }
    }
}

void AdvanceTimeAttackTopMenuState4(void) {
    s16 selectedPressOffset;

    gTimeAttackTopMenu->mStateFrames++;
    selectedPressOffset = GetSelectedPressOffset(gTimeAttackTopMenu->mStateFrames);
    gTimeAttackTopMenu->mTimeAttackTopMenuSTable[gTimeAttackTopMenuOffsetIndices[gTimeAttackTopMenu->mIndex]].mOffsetX =
        selectedPressOffset;
    gTimeAttackTopMenu->mTimeAttackTopMenuSTable[gTimeAttackTopMenuXluCellIndices[gTimeAttackTopMenu->mIndex]]
        .mOffsetX = selectedPressOffset;
    gTimeAttackTopMenu->mTimeAttackTopMenuSTable[gTimeAttackTopMenuVisibleTableIndices[gTimeAttackTopMenu->mIndex]]
        .mOffsetX = selectedPressOffset;
    gTimeAttackTopMenu->mTimeAttackTopMenuSTable[gTimeAttackTopMenuPaletteCellIndices[gTimeAttackTopMenu->mIndex]]
        .mOffsetX = selectedPressOffset;
    switch (gTimeAttackTopMenu->mIndex) {
        case 1:
            gTimeAttackTopMenu->mTimeAttackTopMenuSTable[12].mOffsetX = selectedPressOffset;
            break;
        case 2:
            gTimeAttackTopMenu->mTimeAttackTopMenuSTable[13].mOffsetX = selectedPressOffset;
            break;
    }
    if (gTimeAttackTopMenu->mStateFrames == 5) {
        ShowTimeAttackTopMenuHighlight(gTimeAttackTopMenu->mIndex);
    }
    if (gTimeAttackTopMenu->mStateFrames >= 10) {
        RequestTimeAttackTopMenuState5();
    }
}

void AdvanceTimeAttackTopMenuState5(void) {
    s16 offsetX;
    s32 i;

    gTimeAttackTopMenu->mStateFrames++;
    offsetX = InterpolateS16(1, 0, 0xe0, gTimeAttackTopMenu->mStateFrames, 10);
    gTimeAttackTopMenu->mBg0Offset = InterpolateS16(1, 0, -192, gTimeAttackTopMenu->mStateFrames, 10);
    for (i = 0; i < 3; i++) {
        gTimeAttackTopMenu->mTimeAttackTopMenuSTable[gTimeAttackTopMenuOffsetIndices[i]].mOffsetX = offsetX;
        gTimeAttackTopMenu->mTimeAttackTopMenuSTable[gTimeAttackTopMenuXluCellIndices[i]].mOffsetX = offsetX;
        gTimeAttackTopMenu->mTimeAttackTopMenuSTable[gTimeAttackTopMenuVisibleTableIndices[i]].mOffsetX = offsetX;
        gTimeAttackTopMenu->mTimeAttackTopMenuSTable[gTimeAttackTopMenuPaletteCellIndices[i]].mOffsetX = offsetX;
    }
    gTimeAttackTopMenu->mTimeAttackTopMenuSTable[12].mOffsetX = offsetX;
    gTimeAttackTopMenu->mTimeAttackTopMenuSTable[13].mOffsetX = offsetX;
}

s32 AdvanceTimeAttackTopMenu(void) {
    gTimeAttackTopMenu->mState = gTimeAttackTopMenu->mNextState;
    switch (gTimeAttackTopMenu->mState) {
        case 0:
            AdvanceTimeAttackTopMenuState0();
            break;
        case 1:
            AdvanceTimeAttackTopMenuState1();
            break;
        case 2:
            AdvanceTimeAttackTopMenuState2();
            break;
        case 3:
            AdvanceTimeAttackTopMenuState3();
            break;
        case 4:
            AdvanceTimeAttackTopMenuState4();
            break;
        case 5:
            AdvanceTimeAttackTopMenuState5();
            break;
    }
    DrawLayoutTable(gTimeAttackTopMenu->mTimeAttackTopMenuSBncl, gTimeAttackTopMenu->mTimeAttackTopMenuSNcer, NULL,
                    (void *) gTimeAttackTopMenu->mSubOamList, gTimeAttackTopMenu->mTimeAttackTopMenuSTable);
    if (gTimeAttackTopMenu->mState == 5 && gTimeAttackTopMenu->mStateFrames >= 10) {
        return gTimeAttackTopMenu->mResult;
    }
    return 0;
}

void WriteTimeAttackTopMenuBg0Offset(void) {
    reg_G2_BG0OFS = (-gTimeAttackTopMenu->mBg0Offset << 16) & 0x1ff0000;
}
