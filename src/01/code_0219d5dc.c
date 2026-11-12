#include "01/code_0219d5dc.h"
#include "registers.h"

#include "01/code_0219d000.h"
#include "01/unk_021a6000.h"
#include "Main/System/heap.h"
#include "Main/Unknown/code_021059e0.h"
#include "Main/Unknown/code_02125f54.h"
#include "Main/Save/backup_first_block_write_wrapper.h"
#include "Main/Graphics/layout_rect_table.h"
#include "code_0214a390.h"
#include "Main/Unknown/code_02037000.h"
#include "Main/Unknown/code_02125f6c.h"

OptionEmbremSelect *gOptionEmbremSelect;

void InitOptionEmbremSelect(void *heap) {
    s32 i;
    OptionEmbremSelect *optionEmbremSelect;
    void *bmgEntry;

    gOptionEmbremSelect = HeapAlloc(heap, 0x58);
    gOptionEmbremSelect->mUnk_30 = heap;
    gOptionEmbremSelect->mState = 0;
    gOptionEmbremSelect->mNextState = 0;
    gOptionEmbremSelect->mSelectedRow = 0;
    gOptionEmbremSelect->mStateFrames = 0;
    gOptionEmbremSelect->mHighlightVisible = TRUE;
    LocateAndQueueOptionEmbremSelect();
    for (i = 0; i < 2; i++) {
        SetCellOamModeXlu(gOptionEmbremSelectSTableIndices[i][0], 1, gOptionEmbremSelect->mOptionEmbremSelectSNcer,
                          gOptionEmbremSelect->mOptionEmbremSelectSBncl);
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
    for (i = 0; i < 2; i++) {
        gOptionEmbremSelect->mCellGroupOffsets[i].mOffsetX = 250;
        gOptionEmbremSelect->mCellGroupOffsets[i].mOffsetY = 0;
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

    LocateNcgr(&ncgr, FindSceneFile(gOptionTopMenuMBNcgrName));
    LocateNscr(&nscr, FindSceneFile(gOptionTopMenuMNscrName));
    LocateNclr(&nclr, FindSceneFile(gOptionTopMenuMBNclrName));
    gOptionEmbremSelect->mOptionEmbremSelectSBncl = FindSceneFile(gOptionEmbremSelectSBnclName);
    gOptionEmbremSelect->mOptionEmbremSelectSBnbl = FindSceneFile(gOptionEmbremSelectSBnblName);
    gOptionEmbremSelect->mOptionEmbremSelectSBnll = FindSceneFile(gOptionEmbremSelectSBnllName);
    LocateNcgr2(&gOptionEmbremSelect->mOptionEmbremSelectSNcgr, FindSceneFile(gOptionEmbremSelectSNcgrName));
    LocateNcer(&gOptionEmbremSelect->mOptionEmbremSelectSNcer, FindSceneFile(gOptionEmbremSelectSNcerName));
    LocateNclr(&gOptionEmbremSelect->mOptionEmbremSelectSONclr, FindSceneFile(gOptionEmbremSelectSONclrName));
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
        gOptionEmbremSelect->mNextState = 1;
    }
}

void AdvanceOptionEmbremSelectState1(void) {
    s32 i;
    s32 j;
    s16 offsetX;

    gOptionEmbremSelect->mStateFrames++;
    offsetX = InterpolateS16(1, 250, 0, gOptionEmbremSelect->mStateFrames, 10);
    for (i = 0; i < 2; i++) {
        for (j = 0; j < gOptionEmbremSelectSTableCounts[i]; j++) {
            if (i == 1) {
                gOptionEmbremSelect->mCellGroupOffsets[i].mOffsetX = offsetX;
            } else {
                gOptionEmbremSelect->mCellGroupOffsets[i].mOffsetX = -offsetX;
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
    int returnState2NoRequest;
    returnState2NoRequest = IsSelectReturnState2NoState3Or4Request();
    if (returnState2NoRequest != 0) {
        gOptionEmbremSelect->mNextState = 3;
    }
}

void AdvanceOptionEmbremSelectState3(void) {
    InputSlotIndex slotIndex = UNK_02175628_INDEX_8;
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
    if (touchBegan != FALSE && IsSelectReturnState2NoState3Or4RequestAndInRect(
                                   gInputSlots[slotIndex].mPair.mPairX, gInputSlots[slotIndex].mPair.mPairY) != FALSE) {
    next:
        gOptionEmbremSelect->mNextState = 5;
        gOptionEmbremSelect->mNextOptionState = 2;
        if (gOptionEmbremSelect->mEmblemOffChoice != gOptionEmbremSelect->mEmblemOffAtOpen) {
            RequestSelectReturnState3WithSound(1);
        } else {
            RequestSelectReturnState3WithSound(0);
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
            gOptionEmbremSelect->mNextState = 4;
            gOptionEmbremSelect->mNextOptionState = 6;
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
        optionEmbremSelect->mNextState = 5;
        gOptionEmbremSelect->mStateFrames = 0;
        RequestSelectReturnState4();
        return;
    }
    if (5 <= optionEmbremSelect->mStateFrames) {
        optionEmbremSelect->mHighlightVisible = TRUE;
    }
}

void AdvanceOptionEmbremSelectState5(void) {
    s32 i;
    s32 j;
    s32 offsetX;

    if (GetOptionNextScene() == -1 && gOptionEmbremSelect->mNextOptionState == 6) {
        RequestOptionNextScene(3);
    }
    gOptionEmbremSelect->mStateFrames++;
    offsetX = InterpolateS16(1, 0, 250, gOptionEmbremSelect->mStateFrames, 10);
    for (i = 0; i < 2; i++) {
        for (j = 0; j < gOptionEmbremSelectSTableCounts[i]; j++) {
            if (i == 0) {
                gOptionEmbremSelect->mCellGroupOffsets[i].mOffsetX = -offsetX;
            } else {
                gOptionEmbremSelect->mCellGroupOffsets[i].mOffsetX = offsetX;
            }
        }
    }
    if (gOptionEmbremSelect->mStateFrames >= 10) {
        if (gOptionEmbremSelect->mStateFrames >= 10 &&
            (IsSelectReturnState2NoState3Or4Request() != 0 || IsSelectReturnState0NoState1Request() != 0)) {
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
                obj->mNextState = 6;
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
    s32 i;
    s32 j;
    s32 subLayoutCount;
    s32 k;

    subLayoutCount = gOptionEmbremSelect->mOptionEmbremSelectSBncl->mCount;
    for (i = 0; i < 2; i++) {
        for (j = 0; j < gOptionEmbremSelectSTableCounts[i]; j++) {
            gOptionEmbremSelect->mOptionEmbremSelectSTable[gOptionEmbremSelectSTableIndices[i][j]].mOffsetX =
                gOptionEmbremSelect->mCellGroupOffsets[i].mOffsetX;
            gOptionEmbremSelect->mOptionEmbremSelectSTable[gOptionEmbremSelectSTableIndices[i][j]].mOffsetY =
                gOptionEmbremSelect->mCellGroupOffsets[i].mOffsetY;
        }
    }
    gOptionEmbremSelect->mOptionEmbremSelectSTable[subLayoutCount].mOffsetX =
        gOptionEmbremSelect->mCellGroupOffsets[1].mOffsetX;
    gOptionEmbremSelect->mOptionEmbremSelectSTable[subLayoutCount].mOffsetY =
        gOptionEmbremSelect->mCellGroupOffsets[1].mOffsetY;
    for (k = 0; k < 3; k++) {
        gOptionEmbremSelect->mOptionEmbremSelectSTable[gOptionEmbremSelectTimerCellIndices[k][0]].mOffsetX -=
            LookupFrameOffset(6 - gOptionEmbremSelect->mOffsetTimers[0]);
        gOptionEmbremSelect->mOptionEmbremSelectSTable[gOptionEmbremSelectTimerCellIndices[k][1]].mOffsetX +=
            LookupFrameOffset(6 - gOptionEmbremSelect->mOffsetTimers[1]);
    }
}

void UpdateOptionEmbremSelectIndexCells(void) {
    s32 i;

    for (i = 0; i < gOptionEmbremSelectCellCounts[1]; i++) {
        if (i == gOptionEmbremSelect->mEmblemOffChoice) {
            gOptionEmbremSelect->mOptionEmbremSelectSTable[gOptionEmbremSelectCellIndices[1][i]].mVisible = 1;
        } else {
            gOptionEmbremSelect->mOptionEmbremSelectSTable[gOptionEmbremSelectCellIndices[1][i]].mVisible = 0;
        }
    }
}

void UpdateOptionEmbremSelectHighlight(void) {
    s32 i;
    s32 j;

    for (i = 0; i < 2; i++) {
        if (i == gOptionEmbremSelect->mSelectedRow && gOptionEmbremSelect->mHighlightVisible != FALSE) {
            gOptionEmbremSelect->mOptionEmbremSelectSTable[gOptionEmbremSelectSTableIndices[i][1]].mVisible = 1;
            if (i == 1) {
                SetLabelPaletteIndex(0, 14, gOptionEmbremSelect->mOptionEmbremSelectSBnll,
                                     gOptionEmbremSelect->mOptionEmbremSelectSTable,
                                     gOptionEmbremSelect->mOptionEmbremSelectSBncl);
            }
            for (j = 0; j < gOptionEmbremSelectCellCounts[i]; j++) {
                SetCellPaletteIndex(gOptionEmbremSelectCellIndices[i][j], 14,
                                    gOptionEmbremSelect->mOptionEmbremSelectSNcer,
                                    gOptionEmbremSelect->mOptionEmbremSelectSBncl);
            }
        } else {
            gOptionEmbremSelect->mOptionEmbremSelectSTable[gOptionEmbremSelectSTableIndices[i][1]].mVisible = 0;
            if (i == 1) {
                SetLabelPaletteIndex(0, 15, gOptionEmbremSelect->mOptionEmbremSelectSBnll,
                                     gOptionEmbremSelect->mOptionEmbremSelectSTable,
                                     gOptionEmbremSelect->mOptionEmbremSelectSBncl);
            }
            for (j = 0; j < gOptionEmbremSelectCellCounts[i]; j++) {
                SetCellPaletteIndex(gOptionEmbremSelectCellIndices[i][j], 15,
                                    gOptionEmbremSelect->mOptionEmbremSelectSNcer,
                                    gOptionEmbremSelect->mOptionEmbremSelectSBncl);
            }
        }
    }
}

void AdvanceOptionEmbremSelectTimers(void) {
    s32 i;

    for (i = 0; i < 2; i++) {
        if (gOptionEmbremSelect->mSelectedRow == 1) {
            if (gOptionEmbremSelect->mOffsetTimers[i] > 0) {
                gOptionEmbremSelect->mOptionEmbremSelectSTable[gOptionEmbremSelectTimerCellIndices[0][i]].mVisible = 1;
                gOptionEmbremSelect->mOptionEmbremSelectSTable[gOptionEmbremSelectTimerCellIndices[1][i]].mVisible = 1;
                gOptionEmbremSelect->mOffsetTimers[i]--;
            } else {
                gOptionEmbremSelect->mOptionEmbremSelectSTable[gOptionEmbremSelectTimerCellIndices[0][i]].mVisible = 0;
                gOptionEmbremSelect->mOptionEmbremSelectSTable[gOptionEmbremSelectTimerCellIndices[1][i]].mVisible = 1;
            }
        } else {
            gOptionEmbremSelect->mOptionEmbremSelectSTable[gOptionEmbremSelectTimerCellIndices[0][i]].mVisible = 0;
            gOptionEmbremSelect->mOptionEmbremSelectSTable[gOptionEmbremSelectTimerCellIndices[1][i]].mVisible = 0;
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
    OptionStateCallbackTable local = gOptionEmbremSelectCallbacks;

    SetOptionStateCallbacks(local.mCallbacks);
}
