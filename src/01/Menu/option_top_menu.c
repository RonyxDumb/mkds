#include "01/Menu/option_top_menu.h"
#include "g2.h"
#include "registers.h"

#include "01/code_02195000.h"
#include "01/Menu/option_nickname_scenes.h"
#include "01/unk_021a6000.h"
#include "01/unk_021a8000.h"
#include "01/unk_021a9000.h"
#include "Main/System/heap.h"
#include "Main/Save/backup_reset.h"
#include "Main/Sound/sound_seq.h"
#include "Main/Menu/txt_system.h"
#include "Main/Graphics/layout_rect_table.h"
#include "Main/Menu/record_vs.h"
#include "Main/Sound/sound_system.h"
#include "Main/Save/ghost_record_file.h"
#include "Main/System/init_after_startup.h"

const u8 gOptionTopMenuOffsetTableIndices[3][4] = {{0, 3, 6, 9}, {1, 4, 7, 0xa}, {2, 5, 8, 0xb}};
const s32 gOptionTopMenuOffsetCellCounts[3] = {4, 4, 4};
OptionStateCallbacks gOptionTopMenuCallbacks = {InitOptionTopMenu, ReleaseOptionTopMenu, AdvanceOptionTopMenu,
                                                WriteOptionTopMenuRegisters};
const u8 gOptionTopMenuSTableIndices[3] = {6, 7, 8};
const u8 gOptionTopMenuXluCellIndices[3] = {0, 1, 2};
const u8 gOptionTopMenuCellIndices[3] = {9, 0xa, 0xb};
OptionTopMenu *gOptionTopMenu;

void InitOptionTopMenu(void *heap) {
    s32 index;
    s32 cellIndex;

    gOptionTopMenu = HeapAlloc(heap, sizeof(OptionTopMenu));
    gOptionTopMenu->mHeap = heap;
    gOptionTopMenu->mState = OPTION_TOP_STATE_WAIT_FADE;
    gOptionTopMenu->mNextState = OPTION_TOP_STATE_WAIT_FADE;
    switch (GetOptionPrevState()) {
        case 1:
        case 4:
            gOptionTopMenu->mIndex = OPTION_TOP_ROW_SETTINGS;
            break;
        case 2:
            gOptionTopMenu->mIndex = OPTION_TOP_ROW_EDIT;
            break;
    }
    gOptionTopMenu->mStateFrames = 0;
    gOptionTopMenu->mHighlightVisible = TRUE;
    gOptionTopMenu->mOptionMessages = FindSceneFile("option.bmg");
    gOptionTopMenu->mCommonMessages = FindFileInLoadedArchives("common.bmg");
    if (GetOptionPrevState() == 1) {
        gOptionTopMenu->mBg0Offset = 0x32;
    } else {
        gOptionTopMenu->mBg0Offset = 0;
    }
    LocateAndQueueOptionTopMenu();
    for (index = 0; index < 3; index++) {
        SetCellOamModeXlu(gOptionTopMenuXluCellIndices[index], 1, gOptionTopMenu->mOptionTopMenuSNcer,
                          gOptionTopMenu->mOptionTopMenuSBncl);
    }
    ResetOamLists(GetOptionFirstBuffer(), GetOptionSecondBuffer());
    InitLayoutTable(heap, gOptionTopMenu->mOptionTopMenuSBncl, NULL, &gOptionTopMenu->mOptionTopMenuSTable);
    for (index = 0; index < 3; index++) {
        for (cellIndex = 0; cellIndex < gOptionTopMenuOffsetCellCounts[index]; cellIndex++) {
            if (index == 1) {
                gOptionTopMenu->mOptionTopMenuSTable[gOptionTopMenuOffsetTableIndices[index][cellIndex]].mOffsetX = 250;
            } else {
                gOptionTopMenu->mOptionTopMenuSTable[gOptionTopMenuOffsetTableIndices[index][cellIndex]].mOffsetX =
                    -250;
            }
        }
    }
    SetSelectReturnSoundId(0xf);
}

void ReleaseOptionTopMenu(void) {
    gOptionTopMenu = NULL;
}

void LocateAndQueueOptionTopMenu(void) {
    Ncgr *ncgr;
    Nscr *nscr;
    Nclr *nclr;

    LocateNcgr(&ncgr, FindSceneFile("Option_top_menu_m_b.ncgr"));
    LocateNscr(&nscr, FindSceneFile("Option_top_menu_m.nscr"));
    LocateNclr(&nclr, FindSceneFile("Option_top_menu_m_b.nclr"));
    gOptionTopMenu->mOptionTopMenuSBncl = FindSceneFile("Option_top_menu_s.bncl");
    gOptionTopMenu->mOptionTopMenuSBnbl = FindSceneFile("Option_top_menu_s.bnbl");
    LocateNcgr2(&gOptionTopMenu->mOptionTopMenuSNcgr, FindSceneFile("Option_top_menu_s.nce.ncgr"));
    LocateNcer(&gOptionTopMenu->mOptionTopMenuSNcer, FindSceneFile("Option_top_menu_s.nce.ncer"));
    LocateNclr(&gOptionTopMenu->mOptionTopMenuSONclr, FindSceneFile("Option_top_menu_s_o.nclr"));
    NNS_GfdRegisterNewVramTransferTask(4, 0, ncgr->mData, ncgr->mDataSize);
    NNS_GfdRegisterNewVramTransferTask(8, 0, nscr->mData, nscr->mDataSize);
    NNS_GfdRegisterNewVramTransferTask(15, 0, nclr->mData, 0x100);
    NNS_GfdRegisterNewVramTransferTask(0x23, 0, gOptionTopMenu->mOptionTopMenuSNcgr->mData,
                                       gOptionTopMenu->mOptionTopMenuSNcgr->mDataSize);
    NNS_GfdRegisterNewVramTransferTask(0x1e, 0, gOptionTopMenu->mOptionTopMenuSONclr->mData,
                                       gOptionTopMenu->mOptionTopMenuSONclr->mDataSize);
}

void AdvanceOptionTopMenuWaitFade(void) {
    int fadesClear;
    fadesClear = AreBrightnessFadesClear();
    if (fadesClear != 0) {
        gOptionTopMenu->mNextState = OPTION_TOP_STATE_SLIDE_IN;
    }
}

void AdvanceOptionTopMenuSlideIn(void) {
    s32 amount;
    s32 rowIndex;
    s32 cellIndex;

    gOptionTopMenu->mStateFrames++;
    amount = InterpolateS16(1, 250, 0, gOptionTopMenu->mStateFrames, 10);
    for (rowIndex = 0; rowIndex < 3; rowIndex++) {
        for (cellIndex = 0; cellIndex < gOptionTopMenuOffsetCellCounts[rowIndex]; cellIndex++) {
            if (rowIndex == 1) {
                gOptionTopMenu->mOptionTopMenuSTable[gOptionTopMenuOffsetTableIndices[rowIndex][cellIndex]].mOffsetX =
                    amount;
            } else {
                gOptionTopMenu->mOptionTopMenuSTable[gOptionTopMenuOffsetTableIndices[rowIndex][cellIndex]].mOffsetX =
                    -amount;
            }
        }
    }
    if (GetOptionPrevState() == 1 && gOptionTopMenu->mIndex != OPTION_TOP_ROW_ERASE_DATA) {
        gOptionTopMenu->mBg0Offset = InterpolateS16(1, 50, 0, gOptionTopMenu->mStateFrames, 10);
    }
    if (gOptionTopMenu->mStateFrames >= 10) {
        gOptionTopMenu->mNextState = OPTION_TOP_STATE_WAIT_SELECT_RETURN;
        gOptionTopMenu->mStateFrames = 0;
        RequestSelectReturnSlideIn();
    }
}

void AdvanceOptionTopMenuWaitSelectReturn(void) {
    int returnShownNoRequest;
    returnShownNoRequest = IsSelectReturnShownNoRequest();
    if (returnShownNoRequest != 0) {
        gOptionTopMenu->mNextState = OPTION_TOP_STATE_INPUT;
    }
}

void AdvanceOptionTopMenuInput(void) {
    InputSlotIndex slotIndex = INPUT_SLOT_PAD_OR_PARTICIPANT;
    u32 touchedRect = -1;
    BOOL touchBegan = FALSE;
    BOOL recentlyLost = FALSE;
    u16 keyBPressed;
    s32 previousIndex;
    s32 keyAPressed;

    if (gInputSlots[slotIndex].mPair.mHasPair == 0 && gInputSlots[slotIndex].mPair.mNoPairCount < 5) {
        recentlyLost = TRUE;
    }
    if (recentlyLost == FALSE && gInputSlots[slotIndex].mPair.mPrevHasPair == 0 &&
        gInputSlots[slotIndex].mPair.mHasPair != 0) {
        touchBegan = TRUE;
    }
    if (touchBegan != FALSE) {
        touchedRect = RectTableFindContaining(gOptionTopMenu->mOptionTopMenuSBnbl, gInputSlots[slotIndex].mPair.mPairX,
                                              gInputSlots[slotIndex].mPair.mPairY);
    }
    keyBPressed = gInputSlots[slotIndex].mPressedBits & PAD_KEY_B;
    if (keyBPressed == 0) {
        BOOL touchBeganAgain = FALSE;
        BOOL recentlyLostAgain = FALSE;
        if (gInputSlots[slotIndex].mPair.mHasPair == 0 && gInputSlots[slotIndex].mPair.mNoPairCount < 5) {
            recentlyLostAgain = TRUE;
        }
        if (recentlyLostAgain == FALSE && gInputSlots[slotIndex].mPair.mPrevHasPair == 0 &&
            gInputSlots[slotIndex].mPair.mHasPair != 0) {
            touchBeganAgain = TRUE;
        }
        if (touchBeganAgain != FALSE &&
            IsSelectReturnShownNoRequestAndInRect(gInputSlots[slotIndex].mPair.mPairX,
                                                  gInputSlots[slotIndex].mPair.mPairY) != FALSE) {
            goto leave;
        }
    } else {
    leave:
        gOptionTopMenu->mNextState = OPTION_TOP_STATE_SLIDE_OUT;
        gOptionTopMenu->mNextOptionState = OPTION_STATE_SCENE_TITLE;
        RequestSelectReturnPressWithSound(1);
        return;
    }
    keyAPressed = gInputSlots[slotIndex].mPressedBits & PAD_KEY_A;
    if ((u16) keyAPressed != 0 || touchedRect <= 2) {
        previousIndex = gOptionTopMenu->mIndex;
        if ((u16) keyAPressed == 0) {
            switch (touchedRect) {
                case OPTION_TOP_ROW_SETTINGS:
                    gOptionTopMenu->mIndex = OPTION_TOP_ROW_SETTINGS;
                    break;
                case OPTION_TOP_ROW_EDIT:
                    gOptionTopMenu->mIndex = OPTION_TOP_ROW_EDIT;
                    break;
                case OPTION_TOP_ROW_ERASE_DATA:
                    gOptionTopMenu->mIndex = OPTION_TOP_ROW_ERASE_DATA;
                    break;
            }
        }
        gOptionTopMenu->mNextState = OPTION_TOP_STATE_PRESS;
        switch (gOptionTopMenu->mIndex) {
            case OPTION_TOP_ROW_SETTINGS:
                gOptionTopMenu->mNextOptionState = OPTION_STATE_SELECT_MENU;
                break;
            case OPTION_TOP_ROW_EDIT:
                gOptionTopMenu->mNextOptionState = OPTION_STATE_HENSYU_MENU;
                break;
            case OPTION_TOP_ROW_ERASE_DATA:
                break;
        }
        if (gOptionTopMenu->mIndex == previousIndex) {
            gOptionTopMenu->mHighlightVisible = FALSE;
        }
        StartSoundOncePerFrame(5);
    } else if (GetNewOrRepeatBits(8, PAD_KEY_UP) != 0) {
        gOptionTopMenu->mIndex--;
        if (gOptionTopMenu->mIndex < 0) {
            gOptionTopMenu->mIndex = OPTION_TOP_ROW_ERASE_DATA;
        }
        StartSoundOncePerFrame(0);
    } else if (GetNewOrRepeatBits(8, PAD_KEY_DOWN) != 0) {
        gOptionTopMenu->mIndex++;
        if (gOptionTopMenu->mIndex > OPTION_TOP_ROW_ERASE_DATA) {
            gOptionTopMenu->mIndex = OPTION_TOP_ROW_SETTINGS;
        }
        StartSoundOncePerFrame(0);
    }
}

void AdvanceOptionTopMenuPress(void) {
    gOptionTopMenu->mStateFrames++;
    if (gOptionTopMenu->mStateFrames >= 10) {
        gOptionTopMenu->mNextState = OPTION_TOP_STATE_SLIDE_OUT;
        gOptionTopMenu->mStateFrames = 0;
        if (gOptionTopMenu->mIndex == OPTION_TOP_ROW_ERASE_DATA) {
            RequestSelectReturnSlideOut();
        }
    } else if (gOptionTopMenu->mStateFrames >= 5) {
        gOptionTopMenu->mHighlightVisible = TRUE;
    }
}

void AdvanceOptionTopMenuSlideOut(void) {
    s32 amount;
    s32 rowIndex;
    s32 cellIndex;

    if (GetOptionNextScene() == -1 && gOptionTopMenu->mNextOptionState == OPTION_STATE_SCENE_TITLE) {
        RequestOptionNextScene(0);
    }
    gOptionTopMenu->mStateFrames++;
    if (gOptionTopMenu->mStateFrames <= 10) {
        amount = InterpolateS16(1, 0, 250, gOptionTopMenu->mStateFrames, 10);
    } else {
        amount = 250;
    }
    for (rowIndex = 0; rowIndex < 3; rowIndex++) {
        for (cellIndex = 0; cellIndex < gOptionTopMenuOffsetCellCounts[rowIndex]; cellIndex++) {
            if (rowIndex == 1) {
                gOptionTopMenu->mOptionTopMenuSTable[gOptionTopMenuOffsetTableIndices[rowIndex][cellIndex]].mOffsetX =
                    amount;
            } else {
                gOptionTopMenu->mOptionTopMenuSTable[gOptionTopMenuOffsetTableIndices[rowIndex][cellIndex]].mOffsetX =
                    -amount;
            }
        }
    }
    if (gOptionTopMenu->mNextOptionState == OPTION_STATE_SELECT_MENU) {
        gOptionTopMenu->mBg0Offset = InterpolateS16(1, 0, 50, gOptionTopMenu->mStateFrames, 10);
    }
    if (gOptionTopMenu->mStateFrames >= 10 &&
        (gOptionTopMenu->mIndex != OPTION_TOP_ROW_ERASE_DATA || IsSelectReturnHiddenNoRequest() != 0) &&
        GetOptionNextScene() == -1) {
        if (gOptionTopMenu->mIndex == OPTION_TOP_ROW_ERASE_DATA) {
            gOptionTopMenu->mNextState = OPTION_TOP_STATE_ASK_RESET;
            gOptionTopMenu->mStateFrames = 0;
            SetupTxtSystemSubTextTwoButtons(GetBmgEntry(gOptionTopMenu->mOptionMessages, 3),
                                            GetBmgEntry(gOptionTopMenu->mCommonMessages, 0),
                                            GetBmgEntry(gOptionTopMenu->mCommonMessages, 1), 1);
        } else {
            RequestOptionState(gOptionTopMenu->mNextOptionState);
        }
    }
}

void AdvanceOptionTopMenuAskReset(void) {
    if (GetTxtSystemDone() != 0) {
        RequestTxtSystemClose();
        return;
    }
    if (IsTxtSystemClosedNoOpenRequest() != 0) {
        if (GetTxtSystemSelectedIndex() == 0) {
            SetupTxtSystemSubTextTwoButtons(GetBmgEntry(gOptionTopMenu->mOptionMessages, 4),
                                            GetBmgEntry(gOptionTopMenu->mCommonMessages, 0),
                                            GetBmgEntry(gOptionTopMenu->mCommonMessages, 1), 1);
            gOptionTopMenu->mNextState = OPTION_TOP_STATE_ASK_RESET_AGAIN;
        } else {
            gOptionTopMenu->mNextState = OPTION_TOP_STATE_SLIDE_IN;
        }
    }
}

void AdvanceOptionTopMenuAskResetAgain(void) {
    if (GetTxtSystemDone() != 0) {
        RequestTxtSystemClose();
        return;
    }
    if (IsTxtSystemClosedNoOpenRequest() != 0) {
        if (GetTxtSystemSelectedIndex() == 0) {
            ResetBackupAndStartWrite();
            gOptionTopMenu->mNextState = OPTION_TOP_STATE_WAIT_RESET_WRITE;
            SetupTxtSystemSubTextEx(GetBmgEntry(gOptionTopMenu->mOptionMessages, 5), 1, 1, 1, 0, 1);
        } else {
            gOptionTopMenu->mNextState = OPTION_TOP_STATE_SLIDE_IN;
        }
    }
}

void AdvanceOptionTopMenuWaitResetWrite(void) {
    s32 flag;

    if (IsTxtSystemOpenAfterOpening() != 0) {
        NNS_SndArcPlayerStartSeqArc(&gSharedSeqHandle, 0, 0x22);
    }
    if (gBackupBuffers->mBusy == 0) {
        if (gBackupAccess->mBackupEnabled != 0) {
            flag = gBackupAccess->mCommandRunning;
        } else {
            flag = 0;
        }
    } else {
        flag = 1;
    }
    if (flag == 0 && IsTxtSystemOpenNoCloseRequest() != 0) {
        gOptionTopMenu->mNextState = OPTION_TOP_STATE_RESET_DONE;
        SetTxtSystemOpenSoundId(0x21);
        SetupTxtSystemSubTextButton(GetBmgEntry(gOptionTopMenu->mOptionMessages, 6),
                                    GetBmgEntry(gOptionTopMenu->mCommonMessages, 4));
    }
}

void AdvanceOptionTopMenuResetDone(void) {
    int queryResult;
    queryResult = GetOptionNextScene();
    if ((queryResult == -1) && (gOptionTopMenu->mNextOptionState == OPTION_STATE_SCENE_TITLE)) {
        RequestOptionNextScene(0);
    }
    queryResult = GetTxtSystemDone();
    if (queryResult != 0) {
        SetTxtSystemOpenSoundId(0x23);
        RequestTxtSystemClose();
        gOptionTopMenu->mNextOptionState = OPTION_STATE_SCENE_TITLE;
    }
}

void UpdateOptionTopMenuHighlight(void) {
    int rowIndex;
    BOOL zero = FALSE;

    for (rowIndex = 0; rowIndex < 3; rowIndex++) {
        if (rowIndex == gOptionTopMenu->mIndex && gOptionTopMenu->mHighlightVisible != FALSE) {
            gOptionTopMenu->mOptionTopMenuSTable[gOptionTopMenuSTableIndices[rowIndex]].mVisible = 1;
            SetCellPaletteIndex(gOptionTopMenuCellIndices[rowIndex], 14, gOptionTopMenu->mOptionTopMenuSNcer,
                                gOptionTopMenu->mOptionTopMenuSBncl);
        } else {
            gOptionTopMenu->mOptionTopMenuSTable[gOptionTopMenuSTableIndices[rowIndex]].mVisible = zero;
            SetCellPaletteIndex(gOptionTopMenuCellIndices[rowIndex], 15, gOptionTopMenu->mOptionTopMenuSNcer,
                                gOptionTopMenu->mOptionTopMenuSBncl);
        }
    }
}

void AdvanceOptionTopMenu(void) {
    OptionTopMenu *optionTopMenu;

    gOptionTopMenu->mState = gOptionTopMenu->mNextState;
    switch (gOptionTopMenu->mState) {
        case OPTION_TOP_STATE_WAIT_FADE:
            AdvanceOptionTopMenuWaitFade();
            break;
        case OPTION_TOP_STATE_SLIDE_IN:
            AdvanceOptionTopMenuSlideIn();
            break;
        case OPTION_TOP_STATE_WAIT_SELECT_RETURN:
            AdvanceOptionTopMenuWaitSelectReturn();
            break;
        case OPTION_TOP_STATE_INPUT:
            AdvanceOptionTopMenuInput();
            break;
        case OPTION_TOP_STATE_PRESS:
            AdvanceOptionTopMenuPress();
            break;
        case OPTION_TOP_STATE_SLIDE_OUT:
            AdvanceOptionTopMenuSlideOut();
            break;
        case OPTION_TOP_STATE_ASK_RESET:
            AdvanceOptionTopMenuAskReset();
            break;
        case OPTION_TOP_STATE_ASK_RESET_AGAIN:
            AdvanceOptionTopMenuAskResetAgain();
            break;
        case OPTION_TOP_STATE_WAIT_RESET_WRITE:
            AdvanceOptionTopMenuWaitResetWrite();
            break;
        case OPTION_TOP_STATE_RESET_DONE:
            AdvanceOptionTopMenuResetDone();
            break;
    }
    UpdateOptionTopMenuHighlight();
    optionTopMenu = gOptionTopMenu;
    DrawLayoutTable(optionTopMenu->mOptionTopMenuSBncl, optionTopMenu->mOptionTopMenuSNcer, NULL,
                    GetOptionSecondBuffer(), optionTopMenu->mOptionTopMenuSTable);
}

void WriteOptionTopMenuRegisters(void) {
    G2x_SetBlendAlpha_(&reg_G2S_DB_BLDCNT, 0, 2, 6, 10);
    reg_G2_BG0OFS = gOptionTopMenu->mBg0Offset << 0x10 & (0x01ff0000u);
}

void RegisterOptionTopMenuCallbacks(void) {
    OptionStateCallbacks callbacks = gOptionTopMenuCallbacks;

    SetOptionStateCallbacks(&callbacks);
}
