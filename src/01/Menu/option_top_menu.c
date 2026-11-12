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
#include "Main/Menu/data_0217d068.h"

OptionTopMenu *gOptionTopMenu;

void InitOptionTopMenu(void *heap) {
    s32 i;
    s32 j;

    gOptionTopMenu = HeapAlloc(heap, 0x40);
    gOptionTopMenu->mHeap = heap;
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
    gOptionTopMenu->mHighlightVisible = TRUE;
    gOptionTopMenu->mOptionMessages = FindSceneFile(gOptionBmgName);
    gOptionTopMenu->mCommonMessages = FindFileInLoadedArchives(gOptionTopMenuCommonBmgName);
    if (GetOptionPrevState() == 1) {
        gOptionTopMenu->mBg0Offset = 0x32;
    } else {
        gOptionTopMenu->mBg0Offset = 0;
    }
    LocateAndQueueOptionTopMenu();
    for (i = 0; i < 3; i++) {
        SetCellOamModeXlu(gOptionTopMenuXluCellIndices[i], 1, gOptionTopMenu->mOptionTopMenuSNcer,
                          gOptionTopMenu->mOptionTopMenuSBncl);
    }
    ResetOamLists(GetOptionFirstBuffer(), GetOptionSecondBuffer());
    InitLayoutTable(heap, gOptionTopMenu->mOptionTopMenuSBncl, NULL, &gOptionTopMenu->mOptionTopMenuSTable);
    for (i = 0; i < 3; i++) {
        for (j = 0; j < gOptionTopMenuOffsetCellCounts[i]; j++) {
            if (i == 1) {
                gOptionTopMenu->mOptionTopMenuSTable[gOptionTopMenuOffsetTableIndices[i][j]].mOffsetX = 250;
            } else {
                gOptionTopMenu->mOptionTopMenuSTable[gOptionTopMenuOffsetTableIndices[i][j]].mOffsetX = -250;
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

    LocateNcgr(&ncgr, FindSceneFile(gTopMenuOptionTopMenuMBNcgrName));
    LocateNscr(&nscr, FindSceneFile(gTopMenuOptionTopMenuMNscrName));
    LocateNclr(&nclr, FindSceneFile(gTopMenuOptionTopMenuMBNclrName));
    gOptionTopMenu->mOptionTopMenuSBncl = FindSceneFile(gOptionTopMenuSBnclName);
    gOptionTopMenu->mOptionTopMenuSBnbl = FindSceneFile(gOptionTopMenuSBnblName);
    LocateNcgr2(&gOptionTopMenu->mOptionTopMenuSNcgr, FindSceneFile(gOptionTopMenuSNcgrName));
    LocateNcer(&gOptionTopMenu->mOptionTopMenuSNcer, FindSceneFile(gOptionTopMenuSNcerName));
    LocateNclr(&gOptionTopMenu->mOptionTopMenuSONclr, FindSceneFile(gOptionTopMenuSONclrName));
    NNS_GfdRegisterNewVramTransferTask(4, 0, ncgr->mData, ncgr->mDataSize);
    NNS_GfdRegisterNewVramTransferTask(8, 0, nscr->mData, nscr->mDataSize);
    NNS_GfdRegisterNewVramTransferTask(15, 0, nclr->mData, 0x100);
    NNS_GfdRegisterNewVramTransferTask(0x23, 0, gOptionTopMenu->mOptionTopMenuSNcgr->mData,
                                       gOptionTopMenu->mOptionTopMenuSNcgr->mDataSize);
    NNS_GfdRegisterNewVramTransferTask(0x1e, 0, gOptionTopMenu->mOptionTopMenuSONclr->mData,
                                       gOptionTopMenu->mOptionTopMenuSONclr->mDataSize);
}

void AdvanceOptionTopMenuState0(void) {
    int fadesClear;
    fadesClear = AreBrightnessFadesClear();
    if (fadesClear != 0) {
        gOptionTopMenu->mNextState = 1;
    }
}

void AdvanceOptionTopMenuState1(void) {
    s32 amount;
    s32 i;
    s32 j;

    gOptionTopMenu->mStateFrames++;
    amount = InterpolateS16(1, 250, 0, gOptionTopMenu->mStateFrames, 10);
    for (i = 0; i < 3; i++) {
        for (j = 0; j < gOptionTopMenuOffsetCellCounts[i]; j++) {
            if (i == 1) {
                gOptionTopMenu->mOptionTopMenuSTable[gOptionTopMenuOffsetTableIndices[i][j]].mOffsetX = amount;
            } else {
                gOptionTopMenu->mOptionTopMenuSTable[gOptionTopMenuOffsetTableIndices[i][j]].mOffsetX = -amount;
            }
        }
    }
    if (GetOptionPrevState() == 1 && gOptionTopMenu->mIndex != 2) {
        gOptionTopMenu->mBg0Offset = InterpolateS16(1, 50, 0, gOptionTopMenu->mStateFrames, 10);
    }
    if (gOptionTopMenu->mStateFrames >= 10) {
        gOptionTopMenu->mNextState = 2;
        gOptionTopMenu->mStateFrames = 0;
        RequestSelectReturnState1();
    }
}

void AdvanceOptionTopMenuState2(void) {
    int returnState2NoRequest;
    returnState2NoRequest = IsSelectReturnState2NoState3Or4Request();
    if (returnState2NoRequest != 0) {
        gOptionTopMenu->mNextState = 3;
    }
}

void AdvanceOptionTopMenuState3(void) {
    InputSlotIndex slotIndex = UNK_02175628_INDEX_8;
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
            IsSelectReturnState2NoState3Or4RequestAndInRect(gInputSlots[slotIndex].mPair.mPairX,
                                                            gInputSlots[slotIndex].mPair.mPairY) != FALSE) {
            goto leave;
        }
    } else {
    leave:
        gOptionTopMenu->mNextState = 5;
        gOptionTopMenu->mNextOptionState = 4;
        RequestSelectReturnState3WithSound(1);
        return;
    }
    keyAPressed = gInputSlots[slotIndex].mPressedBits & PAD_KEY_A;
    if ((u16) keyAPressed != 0 || touchedRect <= 2) {
        previousIndex = gOptionTopMenu->mIndex;
        if ((u16) keyAPressed == 0) {
            switch (touchedRect) {
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
        if (gOptionTopMenu->mIndex == previousIndex) {
            gOptionTopMenu->mHighlightVisible = FALSE;
        }
        StartSoundOncePerFrame(5);
    } else if (GetNewOrRepeatBits(8, PAD_KEY_UP) != 0) {
        gOptionTopMenu->mIndex--;
        if (gOptionTopMenu->mIndex < 0) {
            gOptionTopMenu->mIndex = 2;
        }
        StartSoundOncePerFrame(0);
    } else if (GetNewOrRepeatBits(8, PAD_KEY_DOWN) != 0) {
        gOptionTopMenu->mIndex++;
        if (gOptionTopMenu->mIndex > 2) {
            gOptionTopMenu->mIndex = 0;
        }
        StartSoundOncePerFrame(0);
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
        gOptionTopMenu->mHighlightVisible = TRUE;
    }
}

void AdvanceOptionTopMenuState5(void) {
    s32 amount;
    s32 i;
    s32 j;

    if (GetOptionNextScene() == -1 && gOptionTopMenu->mNextOptionState == 4) {
        RequestOptionNextScene(0);
    }
    gOptionTopMenu->mStateFrames++;
    if (gOptionTopMenu->mStateFrames <= 10) {
        amount = InterpolateS16(1, 0, 250, gOptionTopMenu->mStateFrames, 10);
    } else {
        amount = 250;
    }
    for (i = 0; i < 3; i++) {
        for (j = 0; j < gOptionTopMenuOffsetCellCounts[i]; j++) {
            if (i == 1) {
                gOptionTopMenu->mOptionTopMenuSTable[gOptionTopMenuOffsetTableIndices[i][j]].mOffsetX = amount;
            } else {
                gOptionTopMenu->mOptionTopMenuSTable[gOptionTopMenuOffsetTableIndices[i][j]].mOffsetX = -amount;
            }
        }
    }
    if (gOptionTopMenu->mNextOptionState == 1) {
        gOptionTopMenu->mBg0Offset = InterpolateS16(1, 0, 50, gOptionTopMenu->mStateFrames, 10);
    }
    if (gOptionTopMenu->mStateFrames >= 10 &&
        (gOptionTopMenu->mIndex != 2 || IsSelectReturnState0NoState1Request() != 0) && GetOptionNextScene() == -1) {
        if (gOptionTopMenu->mIndex == 2) {
            gOptionTopMenu->mNextState = 6;
            gOptionTopMenu->mStateFrames = 0;
            SetupTxtSystemSubTextTwoButtons(GetBmgEntry(gOptionTopMenu->mOptionMessages, 3),
                                            GetBmgEntry(gOptionTopMenu->mCommonMessages, 0),
                                            GetBmgEntry(gOptionTopMenu->mCommonMessages, 1), 1);
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
            SetupTxtSystemSubTextTwoButtons(GetBmgEntry(gOptionTopMenu->mOptionMessages, 4),
                                            GetBmgEntry(gOptionTopMenu->mCommonMessages, 0),
                                            GetBmgEntry(gOptionTopMenu->mCommonMessages, 1), 1);
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
            ResetBackupAndStartWrite();
            gOptionTopMenu->mNextState = 8;
            SetupTxtSystemSubTextEx(GetBmgEntry(gOptionTopMenu->mOptionMessages, 5), 1, 1, 1, 0, 1);
        } else {
            gOptionTopMenu->mNextState = 1;
        }
    }
}

void AdvanceOptionTopMenuState8(void) {
    s32 flag;

    if (IsTxtSystemState2AfterState1() != 0) {
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
    if (flag == 0 && IsTxtSystemState2NoCloseRequest() != 0) {
        gOptionTopMenu->mNextState = 9;
        SetTxtSystemOpenSoundId(0x21);
        SetupTxtSystemSubTextButton(GetBmgEntry(gOptionTopMenu->mOptionMessages, 6),
                                    GetBmgEntry(gOptionTopMenu->mCommonMessages, 4));
    }
}

void AdvanceOptionTopMenuState9(void) {
    int v1;
    v1 = GetOptionNextScene();
    if ((v1 == -1) && (gOptionTopMenu->mNextOptionState == 4)) {
        RequestOptionNextScene(0);
    }
    v1 = GetTxtSystemDone();
    if (v1 != 0) {
        SetTxtSystemOpenSoundId(0x23);
        RequestTxtSystemClose();
        gOptionTopMenu->mNextOptionState = 4;
    }
}

void UpdateOptionTopMenuHighlight(void) {
    int i;
    BOOL zero = FALSE;

    for (i = 0; i < 3; i++) {
        if (i == gOptionTopMenu->mIndex && gOptionTopMenu->mHighlightVisible != FALSE) {
            gOptionTopMenu->mOptionTopMenuSTable[gOptionTopMenuSTableIndices[i]].mVisible = 1;
            SetCellPaletteIndex(gOptionTopMenuCellIndices[i], 14, gOptionTopMenu->mOptionTopMenuSNcer,
                                gOptionTopMenu->mOptionTopMenuSBncl);
        } else {
            gOptionTopMenu->mOptionTopMenuSTable[gOptionTopMenuSTableIndices[i]].mVisible = zero;
            SetCellPaletteIndex(gOptionTopMenuCellIndices[i], 15, gOptionTopMenu->mOptionTopMenuSNcer,
                                gOptionTopMenu->mOptionTopMenuSBncl);
        }
    }
}

void AdvanceOptionTopMenu(void) {
    OptionTopMenu *optionTopMenu;

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

    SetOptionStateCallbacks((UnkFunc **) &callbacks);
}
