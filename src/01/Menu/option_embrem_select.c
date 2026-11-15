#include "01/Menu/option_embrem_select.h"
#include "registers.h"

#include "01/code_0219d000.h"
#include "01/unk_021a6000.h"
#include "Main/System/heap.h"
#include "Main/Sound/sound_seq.h"
#include "Main/Menu/txt_system.h"
#include "Main/Save/backup_first_block_write_wrapper.h"
#include "Main/Graphics/layout_rect_table.h"
#include "g2.h"
#include "02/unk_02180500.h"
#include "Main/Menu/menu_shared_clear.h"
#include "Main/Save/ghost_record_file.h"
#include "Main/System/init_after_startup.h"

const s32 gOptionEmbremSelectCellCounts[2] = {1, 2};
const s32 gOptionEmbremSelectSTableCounts[2] = {4, 0xb};
OptionStateCallbacks gOptionEmbremSelectCallbacks = {InitOptionEmbremSelect, ReleaseOptionEmbremSelect,
                                                     AdvanceOptionEmbremSelect, WriteOptionEmbremSelectRegisters};
const u8 gOptionEmbremSelectSTableIndices[2][11] = {{0, 8, 2, 0xc, 0, 0, 0, 0, 0, 0, 0},
                                                    {1, 9, 3, 4, 5, 6, 7, 0xa, 0xb, 0xd, 0xe}};
const u8 gOptionEmbremSelectTimerCellIndices[3][2] = {{0xa, 0xb}, {6, 7}, {4, 5}};
const u8 gOptionEmbremSelectCellIndices[2][2] = {{0xc, 0}, {0xd, 0xe}};
OptionEmbremSelect *gOptionEmbremSelect;
u8 gOverlayExpHeapBuffer[0x20800];

void InitOptionEmbremSelect(void *heap) {
    s32 rowIndex;
    OptionEmbremSelect *optionEmbremSelect;
    void *bmgEntry;

    gOptionEmbremSelect = HeapAlloc(heap, sizeof(OptionEmbremSelect));
    gOptionEmbremSelect->mHeap = heap;
    gOptionEmbremSelect->mState = OPTION_EMBREM_SELECT_STATE_WAIT_FADE;
    gOptionEmbremSelect->mNextState = OPTION_EMBREM_SELECT_STATE_WAIT_FADE;
    gOptionEmbremSelect->mSelectedRow = 0;
    gOptionEmbremSelect->mStateFrames = 0;
    gOptionEmbremSelect->mHighlightVisible = TRUE;
    LocateAndQueueOptionEmbremSelect();
    for (rowIndex = 0; rowIndex < 2; rowIndex++) {
        SetCellOamModeXlu(gOptionEmbremSelectSTableIndices[rowIndex][0], 1,
                          gOptionEmbremSelect->mOptionEmbremSelectSNcer, gOptionEmbremSelect->mOptionEmbremSelectSBncl);
    }
    ResetOamLists(GetOptionFirstBuffer(), GetOptionSecondBuffer());
    InitLayoutTable(heap, gOptionEmbremSelect->mOptionEmbremSelectSBncl, gOptionEmbremSelect->mOptionEmbremSelectSBnll,
                    &gOptionEmbremSelect->mOptionEmbremSelectSTable);
    gOptionEmbremSelect->mOptionMessages = FindSceneFile("option.bmg");
    gOptionEmbremSelect->mCommonMessages = FindFileInLoadedArchives("common.bmg");
    InitLabelCanvas(heap, 0, gOptionEmbremSelect->mOptionEmbremSelectSBnll, 0xa0, 0xe, 9,
                    gOptionEmbremSelect->mOptionEmbremSelectSNcer, gOptionEmbremSelect->mOptionEmbremSelectSBncl,
                    gOptionEmbremSelect->mOptionEmbremSelectSTable, 0x4000);
    optionEmbremSelect = gOptionEmbremSelect;
    bmgEntry = GetBmgEntry(optionEmbremSelect->mOptionMessages, 8);
    PrintLabelLayoutTextNoFixedAdvance(1, 0, gOptionEmbremSelect->mOptionEmbremSelectSBnll, bmgEntry,
                                       optionEmbremSelect->mOptionEmbremSelectSBncl,
                                       optionEmbremSelect->mOptionEmbremSelectSTable);
    for (rowIndex = 0; rowIndex < 2; rowIndex++) {
        gOptionEmbremSelect->mCellGroupOffsets[rowIndex].mOffsetX = 250;
        gOptionEmbremSelect->mCellGroupOffsets[rowIndex].mOffsetY = 0;
    }
    gOptionEmbremSelect->mEmblemOffChoice = IsBackupEmblemOff();
    gOptionEmbremSelect->mEmblemOffAtOpen = gOptionEmbremSelect->mEmblemOffChoice;
    UpdateOptionEmbremSelectCellOffsets();
    UpdateOptionEmbremSelectIndexCells();
    gOptionEmbremSelect->mOffsetTimers[0] = 0;
    gOptionEmbremSelect->mOffsetTimers[1] = 0;
    SetSelectReturnSoundId(0xe);
}

void ReleaseOptionEmbremSelect(void) {
    gOptionEmbremSelect = NULL;
}

void LocateAndQueueOptionEmbremSelect(void) {
    Ncgr *ncgr;
    Nscr *nscr;
    Nclr *nclr;

    LocateNcgr(&ncgr, FindSceneFile("Option_top_menu_m_b.ncgr"));
    LocateNscr(&nscr, FindSceneFile("Option_top_menu_m.nscr"));
    LocateNclr(&nclr, FindSceneFile("Option_top_menu_m_b.nclr"));
    gOptionEmbremSelect->mOptionEmbremSelectSBncl = FindSceneFile("Option_embrem_select_s.bncl");
    gOptionEmbremSelect->mOptionEmbremSelectSBnbl = FindSceneFile("Option_embrem_select_s.bnbl");
    gOptionEmbremSelect->mOptionEmbremSelectSBnll = FindSceneFile("Option_embrem_select_s.bnll");
    LocateNcgr2(&gOptionEmbremSelect->mOptionEmbremSelectSNcgr, FindSceneFile("Option_embrem_select_s.nce.ncgr"));
    LocateNcer(&gOptionEmbremSelect->mOptionEmbremSelectSNcer, FindSceneFile("Option_embrem_select_s.nce.ncer"));
    LocateNclr(&gOptionEmbremSelect->mOptionEmbremSelectSONclr, FindSceneFile("Option_embrem_select_s_o.nclr"));
    NNS_GfdRegisterNewVramTransferTask(4, 0, ncgr->mData, ncgr->mDataSize);
    NNS_GfdRegisterNewVramTransferTask(8, 0, nscr->mData, nscr->mDataSize);
    NNS_GfdRegisterNewVramTransferTask(0xf, 0, nclr->mData, 0x100);
    NNS_GfdRegisterNewVramTransferTask(0x23, 0, gOptionEmbremSelect->mOptionEmbremSelectSNcgr->mData,
                                       gOptionEmbremSelect->mOptionEmbremSelectSNcgr->mDataSize);
    NNS_GfdRegisterNewVramTransferTask(0x1e, 0, gOptionEmbremSelect->mOptionEmbremSelectSONclr->mData,
                                       gOptionEmbremSelect->mOptionEmbremSelectSONclr->mDataSize);
}

BOOL IsBackupEmblemOff(void) {
    if (gBackupBuffers->mFirstBlock->mEmblemOff == 0) {
        return FALSE;
    }
    if (gBackupBuffers->mFirstBlock->mEmblemOff != 0) {
        return TRUE;
    }
    return TRUE;
}

void AdvanceOptionEmbremSelectState0(void) {
    int fadesClear;
    fadesClear = AreBrightnessFadesClear();
    if (fadesClear != 0) {
        gOptionEmbremSelect->mNextState = OPTION_EMBREM_SELECT_STATE_SLIDE_IN;
    }
}

void AdvanceOptionEmbremSelectState1(void) {
    s32 rowIndex;
    s32 cellIndex;
    s16 offsetX;

    gOptionEmbremSelect->mStateFrames++;
    offsetX = InterpolateS16(1, 250, 0, gOptionEmbremSelect->mStateFrames, 10);
    for (rowIndex = 0; rowIndex < 2; rowIndex++) {
        for (cellIndex = 0; cellIndex < gOptionEmbremSelectSTableCounts[rowIndex]; cellIndex++) {
            if (rowIndex == 1) {
                gOptionEmbremSelect->mCellGroupOffsets[rowIndex].mOffsetX = offsetX;
            } else {
                gOptionEmbremSelect->mCellGroupOffsets[rowIndex].mOffsetX = -offsetX;
            }
        }
    }
    if (gOptionEmbremSelect->mStateFrames >= 10) {
        gOptionEmbremSelect->mNextState = OPTION_EMBREM_SELECT_STATE_WAIT_SELECT_RETURN;
        gOptionEmbremSelect->mStateFrames = 0;
        RequestSelectReturnSlideIn();
    }
}

void AdvanceOptionEmbremSelectState2(void) {
    int returnState2NoRequest;
    returnState2NoRequest = IsSelectReturnShownNoRequest();
    if (returnState2NoRequest != 0) {
        gOptionEmbremSelect->mNextState = OPTION_EMBREM_SELECT_STATE_SELECT;
    }
}

void AdvanceOptionEmbremSelectState3(void) {
    InputSlotIndex slotIndex = INPUT_SLOT_PAD_OR_PARTICIPANT;
    s32 touchedRect = -1;
    BOOL touchBegan = FALSE;
    BOOL recentlyLost = FALSE;
    u16 hasPair;
    u16 keyBPressed;

    hasPair = gInputSlots[slotIndex].mPair.mHasPair;
    if (hasPair == 0 && gInputSlots[slotIndex].mPair.mNoPairCount < 5) {
        recentlyLost = TRUE;
    }
    if (recentlyLost == FALSE && gInputSlots[slotIndex].mPair.mPrevHasPair == 0 && hasPair != 0) {
        touchBegan = TRUE;
    }
    if (touchBegan != FALSE) {
        touchedRect = RectTableFindContaining(gOptionEmbremSelect->mOptionEmbremSelectSBnbl,
                                              gInputSlots[slotIndex].mPair.mPairX, gInputSlots[slotIndex].mPair.mPairY);
    }
    keyBPressed = gInputSlots[slotIndex].mPressedBits & PAD_KEY_B;
    if (keyBPressed != 0) {
        goto next;
    }
    touchBegan = FALSE;
    recentlyLost = FALSE;
    hasPair = gInputSlots[slotIndex].mPair.mHasPair;
    if (hasPair == 0 && gInputSlots[slotIndex].mPair.mNoPairCount < 5) {
        recentlyLost = TRUE;
    }
    if (recentlyLost == FALSE && gInputSlots[slotIndex].mPair.mPrevHasPair == 0 && hasPair != 0) {
        touchBegan = TRUE;
    }
    if (touchBegan != FALSE && IsSelectReturnShownNoRequestAndInRect(gInputSlots[slotIndex].mPair.mPairX,
                                                                     gInputSlots[slotIndex].mPair.mPairY) != FALSE) {
    next:
        gOptionEmbremSelect->mNextState = OPTION_EMBREM_SELECT_STATE_SLIDE_OUT;
        gOptionEmbremSelect->mNextOptionState = OPTION_STATE_HENSYU_MENU;
        if (gOptionEmbremSelect->mEmblemOffChoice != gOptionEmbremSelect->mEmblemOffAtOpen) {
            RequestSelectReturnPressWithSound(1);
        } else {
            RequestSelectReturnPressWithSound(0);
        }
        if (gOptionEmbremSelect->mEmblemOffChoice == 0) {
            gBackupBuffers->mFirstBlock->mEmblemOff = 0;
        } else {
            gBackupBuffers->mFirstBlock->mEmblemOff = 1;
        }
        WriteBackupFirstBlockWrapper();
    } else {
        keyBPressed = gInputSlots[slotIndex].mPressedBits & PAD_KEY_A;
        if ((keyBPressed != 0 && gOptionEmbremSelect->mSelectedRow == 0) || touchedRect == 0) {
            if (gOptionEmbremSelect->mSelectedRow == 0) {
                gOptionEmbremSelect->mHighlightVisible = FALSE;
            }
            gOptionEmbremSelect->mNextState = OPTION_EMBREM_SELECT_STATE_HOLD_CHOSEN;
            gOptionEmbremSelect->mNextOptionState = OPTION_STATE_SCENE_EMBLEM;
            gOptionEmbremSelect->mSelectedRow = 0;
            gMenuShared->mOptionReturnsToEmbremSelect = TRUE;
            StartSoundOncePerFrame(5);
        } else if (touchedRect == 1) {
            gOptionEmbremSelect->mSelectedRow = 1;
            gOptionEmbremSelect->mEmblemOffChoice++;
            StartSoundOncePerFrame(1);
        } else if (GetNewOrRepeatBits(8, PAD_KEY_UP) != 0 && gOptionEmbremSelect->mSelectedRow > 0) {
            gOptionEmbremSelect->mSelectedRow--;
            StartSoundOncePerFrame(0);
        } else if (GetNewOrRepeatBits(8, PAD_KEY_DOWN) != 0 && gOptionEmbremSelect->mSelectedRow < 1) {
            gOptionEmbremSelect->mSelectedRow++;
            StartSoundOncePerFrame(0);
        } else if (gOptionEmbremSelect->mSelectedRow == 1 && GetNewOrRepeatBits(8, PAD_KEY_LEFT) != 0) {
            gOptionEmbremSelect->mEmblemOffChoice--;
            gOptionEmbremSelect->mOffsetTimers[0] = 6;
            StartSoundOncePerFrame(1);
        } else if (gOptionEmbremSelect->mSelectedRow == 1 && GetNewOrRepeatBits(8, PAD_KEY_RIGHT) != 0) {
            gOptionEmbremSelect->mEmblemOffChoice++;
            if (GetNewOrRepeatBits(8, PAD_KEY_RIGHT) != 0) {
                gOptionEmbremSelect->mOffsetTimers[1] = 6;
            }
            StartSoundOncePerFrame(1);
        } else if (touchedRect == 2) {
            gOptionEmbremSelect->mSelectedRow = 1;
            gOptionEmbremSelect->mEmblemOffChoice--;
            gOptionEmbremSelect->mOffsetTimers[0] = 6;
            StartSoundOncePerFrame(1);
        } else if (touchedRect == 3) {
            gOptionEmbremSelect->mSelectedRow = 1;
            gOptionEmbremSelect->mEmblemOffChoice++;
            gOptionEmbremSelect->mOffsetTimers[1] = 6;
            StartSoundOncePerFrame(1);
        }
    }
    if (gOptionEmbremSelect->mEmblemOffChoice < 0) {
        gOptionEmbremSelect->mEmblemOffChoice = 1;
    }
    if (gOptionEmbremSelect->mEmblemOffChoice > 1) {
        gOptionEmbremSelect->mEmblemOffChoice = 0;
    }
}

void AdvanceOptionEmbremSelectState4(void) {
    OptionEmbremSelect *optionEmbremSelect;
    gOptionEmbremSelect->mStateFrames = gOptionEmbremSelect->mStateFrames + 1;
    optionEmbremSelect = gOptionEmbremSelect;
    if (10 <= optionEmbremSelect->mStateFrames) {
        optionEmbremSelect->mNextState = OPTION_EMBREM_SELECT_STATE_SLIDE_OUT;
        gOptionEmbremSelect->mStateFrames = 0;
        RequestSelectReturnSlideOut();
        return;
    }
    if (5 <= optionEmbremSelect->mStateFrames) {
        optionEmbremSelect->mHighlightVisible = TRUE;
    }
}

void AdvanceOptionEmbremSelectState5(void) {
    s32 rowIndex;
    s32 cellIndex;
    s32 offsetX;

    if (GetOptionNextScene() == -1 && gOptionEmbremSelect->mNextOptionState == OPTION_STATE_SCENE_EMBLEM) {
        RequestOptionNextScene(3);
    }
    gOptionEmbremSelect->mStateFrames++;
    offsetX = InterpolateS16(1, 0, 250, gOptionEmbremSelect->mStateFrames, 10);
    for (rowIndex = 0; rowIndex < 2; rowIndex++) {
        for (cellIndex = 0; cellIndex < gOptionEmbremSelectSTableCounts[rowIndex]; cellIndex++) {
            if (rowIndex == 0) {
                gOptionEmbremSelect->mCellGroupOffsets[rowIndex].mOffsetX = -offsetX;
            } else {
                gOptionEmbremSelect->mCellGroupOffsets[rowIndex].mOffsetX = offsetX;
            }
        }
    }
    if (gOptionEmbremSelect->mStateFrames >= 10) {
        if (gOptionEmbremSelect->mStateFrames >= 10 &&
            (IsSelectReturnShownNoRequest() != 0 || IsSelectReturnHiddenNoRequest() != 0)) {
            if (GetOptionNextScene() == -1) {
                OptionEmbremSelect *obj = gOptionEmbremSelect;
                s32 arg;
                void *first;

                if (obj->mEmblemOffChoice == obj->mEmblemOffAtOpen) {
                    RequestOptionState(obj->mNextOptionState);
                    return;
                }
                arg = 9;
                if (obj->mEmblemOffChoice == 1) {
                    arg = 10;
                }
                obj->mNextState = OPTION_EMBREM_SELECT_STATE_WAIT_MESSAGE;
                SetTxtSystemOpenSoundId(0x21);
                first = GetBmgEntry(gOptionEmbremSelect->mOptionMessages, arg);
                SetupTxtSystemSubTextButton(first, GetBmgEntry(gOptionEmbremSelect->mCommonMessages, 4));
                gOptionEmbremSelect->mStateFrames = 0;
            }
        }
    }
}

void AdvanceOptionEmbremSelectState6(void) {
    s32 backupBusy;

    if (GetTxtSystemDone() != 0) {
        if (gBackupBuffers->mBusy == 0) {
            if (gBackupAccess->mBackupEnabled != 0) {
                backupBusy = gBackupAccess->mCommandRunning;
            } else {
                backupBusy = 0;
            }
        } else {
            backupBusy = 1;
        }
        if (backupBusy == 0) {
            SetTxtSystemOpenSoundId(0x23);
            RequestTxtSystemClose();
            return;
        }
    }
    if (IsTxtSystemState0NoOpenRequest() != 0) {
        RequestOptionState(gOptionEmbremSelect->mNextOptionState);
    }
}

void UpdateOptionEmbremSelectCellOffsets(void) {
    s32 rowIndex;
    s32 cellIndex;
    s32 subLayoutCount;
    s32 timerCellIndex;

    subLayoutCount = gOptionEmbremSelect->mOptionEmbremSelectSBncl->mCount;
    for (rowIndex = 0; rowIndex < 2; rowIndex++) {
        for (cellIndex = 0; cellIndex < gOptionEmbremSelectSTableCounts[rowIndex]; cellIndex++) {
            gOptionEmbremSelect->mOptionEmbremSelectSTable[gOptionEmbremSelectSTableIndices[rowIndex][cellIndex]]
                .mOffsetX = gOptionEmbremSelect->mCellGroupOffsets[rowIndex].mOffsetX;
            gOptionEmbremSelect->mOptionEmbremSelectSTable[gOptionEmbremSelectSTableIndices[rowIndex][cellIndex]]
                .mOffsetY = gOptionEmbremSelect->mCellGroupOffsets[rowIndex].mOffsetY;
        }
    }
    gOptionEmbremSelect->mOptionEmbremSelectSTable[subLayoutCount].mOffsetX =
        gOptionEmbremSelect->mCellGroupOffsets[1].mOffsetX;
    gOptionEmbremSelect->mOptionEmbremSelectSTable[subLayoutCount].mOffsetY =
        gOptionEmbremSelect->mCellGroupOffsets[1].mOffsetY;
    for (timerCellIndex = 0; timerCellIndex < 3; timerCellIndex++) {
        gOptionEmbremSelect->mOptionEmbremSelectSTable[gOptionEmbremSelectTimerCellIndices[timerCellIndex][0]]
            .mOffsetX -= LookupFrameOffset(6 - gOptionEmbremSelect->mOffsetTimers[0]);
        gOptionEmbremSelect->mOptionEmbremSelectSTable[gOptionEmbremSelectTimerCellIndices[timerCellIndex][1]]
            .mOffsetX += LookupFrameOffset(6 - gOptionEmbremSelect->mOffsetTimers[1]);
    }
}

void UpdateOptionEmbremSelectIndexCells(void) {
    s32 cellIndex;

    for (cellIndex = 0; cellIndex < gOptionEmbremSelectCellCounts[1]; cellIndex++) {
        if (cellIndex == gOptionEmbremSelect->mEmblemOffChoice) {
            gOptionEmbremSelect->mOptionEmbremSelectSTable[gOptionEmbremSelectCellIndices[1][cellIndex]].mVisible = 1;
        } else {
            gOptionEmbremSelect->mOptionEmbremSelectSTable[gOptionEmbremSelectCellIndices[1][cellIndex]].mVisible = 0;
        }
    }
}

void UpdateOptionEmbremSelectHighlight(void) {
    s32 rowIndex;
    s32 cellIndex;

    for (rowIndex = 0; rowIndex < 2; rowIndex++) {
        if (rowIndex == gOptionEmbremSelect->mSelectedRow && gOptionEmbremSelect->mHighlightVisible != FALSE) {
            gOptionEmbremSelect->mOptionEmbremSelectSTable[gOptionEmbremSelectSTableIndices[rowIndex][1]].mVisible = 1;
            if (rowIndex == 1) {
                SetLabelPaletteIndex(0, 14, gOptionEmbremSelect->mOptionEmbremSelectSBnll,
                                     gOptionEmbremSelect->mOptionEmbremSelectSTable,
                                     gOptionEmbremSelect->mOptionEmbremSelectSBncl);
            }
            for (cellIndex = 0; cellIndex < gOptionEmbremSelectCellCounts[rowIndex]; cellIndex++) {
                SetCellPaletteIndex(gOptionEmbremSelectCellIndices[rowIndex][cellIndex], 14,
                                    gOptionEmbremSelect->mOptionEmbremSelectSNcer,
                                    gOptionEmbremSelect->mOptionEmbremSelectSBncl);
            }
        } else {
            gOptionEmbremSelect->mOptionEmbremSelectSTable[gOptionEmbremSelectSTableIndices[rowIndex][1]].mVisible = 0;
            if (rowIndex == 1) {
                SetLabelPaletteIndex(0, 15, gOptionEmbremSelect->mOptionEmbremSelectSBnll,
                                     gOptionEmbremSelect->mOptionEmbremSelectSTable,
                                     gOptionEmbremSelect->mOptionEmbremSelectSBncl);
            }
            for (cellIndex = 0; cellIndex < gOptionEmbremSelectCellCounts[rowIndex]; cellIndex++) {
                SetCellPaletteIndex(gOptionEmbremSelectCellIndices[rowIndex][cellIndex], 15,
                                    gOptionEmbremSelect->mOptionEmbremSelectSNcer,
                                    gOptionEmbremSelect->mOptionEmbremSelectSBncl);
            }
        }
    }
}

void AdvanceOptionEmbremSelectTimers(void) {
    s32 timerIndex;

    for (timerIndex = 0; timerIndex < 2; timerIndex++) {
        if (gOptionEmbremSelect->mSelectedRow == 1) {
            if (gOptionEmbremSelect->mOffsetTimers[timerIndex] > 0) {
                gOptionEmbremSelect->mOptionEmbremSelectSTable[gOptionEmbremSelectTimerCellIndices[0][timerIndex]]
                    .mVisible = 1;
                gOptionEmbremSelect->mOptionEmbremSelectSTable[gOptionEmbremSelectTimerCellIndices[1][timerIndex]]
                    .mVisible = 1;
                gOptionEmbremSelect->mOffsetTimers[timerIndex]--;
            } else {
                gOptionEmbremSelect->mOptionEmbremSelectSTable[gOptionEmbremSelectTimerCellIndices[0][timerIndex]]
                    .mVisible = 0;
                gOptionEmbremSelect->mOptionEmbremSelectSTable[gOptionEmbremSelectTimerCellIndices[1][timerIndex]]
                    .mVisible = 1;
            }
        } else {
            gOptionEmbremSelect->mOptionEmbremSelectSTable[gOptionEmbremSelectTimerCellIndices[0][timerIndex]]
                .mVisible = 0;
            gOptionEmbremSelect->mOptionEmbremSelectSTable[gOptionEmbremSelectTimerCellIndices[1][timerIndex]]
                .mVisible = 0;
        }
    }
}

void AdvanceOptionEmbremSelect(void) {
    gOptionEmbremSelect->mState = gOptionEmbremSelect->mNextState;
    switch (gOptionEmbremSelect->mState) {
        case OPTION_EMBREM_SELECT_STATE_WAIT_FADE:
            AdvanceOptionEmbremSelectState0();
            break;
        case OPTION_EMBREM_SELECT_STATE_SLIDE_IN:
            AdvanceOptionEmbremSelectState1();
            break;
        case OPTION_EMBREM_SELECT_STATE_WAIT_SELECT_RETURN:
            AdvanceOptionEmbremSelectState2();
            break;
        case OPTION_EMBREM_SELECT_STATE_SELECT:
            AdvanceOptionEmbremSelectState3();
            break;
        case OPTION_EMBREM_SELECT_STATE_HOLD_CHOSEN:
            AdvanceOptionEmbremSelectState4();
            break;
        case OPTION_EMBREM_SELECT_STATE_SLIDE_OUT:
            AdvanceOptionEmbremSelectState5();
            break;
        case OPTION_EMBREM_SELECT_STATE_WAIT_MESSAGE:
            AdvanceOptionEmbremSelectState6();
            break;
    }
    UpdateOptionEmbremSelectCellOffsets();
    UpdateOptionEmbremSelectIndexCells();
    UpdateOptionEmbremSelectHighlight();
    AdvanceOptionEmbremSelectTimers();
    DrawLayoutTable(gOptionEmbremSelect->mOptionEmbremSelectSBncl, gOptionEmbremSelect->mOptionEmbremSelectSNcer,
                    gOptionEmbremSelect->mOptionEmbremSelectSBnll, GetOptionSecondBuffer(),
                    gOptionEmbremSelect->mOptionEmbremSelectSTable);
}

void WriteOptionEmbremSelectRegisters(void) {
    G2x_SetBlendAlpha_(&reg_G2S_DB_BLDCNT, 0, 2, 6, 10);
}

void RegisterOptionEmbremSelectCallbacks(void) {
    OptionStateCallbacks callbacks = gOptionEmbremSelectCallbacks;

    SetOptionStateCallbacks(&callbacks);
}
