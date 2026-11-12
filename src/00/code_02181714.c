#include "00/code_02181714.h"
#include "registers.h"
#include "Main/Save/ghost_file_records.h"
#include "Main/Unknown/code_0214a000.h"
#include "01/code_021956dc.h"
#include "Main/Unknown/code_0211f000.h"
#include "Main/Unknown/code_02125f88.h"
#include "Main/Unknown/code_020ae408.h"
#include "Main/Unknown/code_021059e0.h"
#include "Main/Scene/display_settings.h"
#include "00/unk_021b0000.h"
#include "Main/System/result_archive_path.h"
#include "Main/System/heap.h"
#include "Main/Graphics/oam_lists.h"
#include "Main/Net/led_pattern.h"
#include "Main/Menu/message_screen.h"

#include "00/code_02180608.h"
#include "00/code_ov000_021804e0.h"
#include "Main/Graphics/layout_entry_angle.h"
#include "Main/Unknown/code_02124bf0.h"
#include "Main/Unknown/code_02125f54.h"
#include "Main/Unknown/code_02125f6c.h"
#include "Main/Unknown/code_02128210.h"
#include "Main/Unknown/code_02128274.h"
#include "Main/Unknown/unk_02175628.h"
#include "Main/Unknown/unk_0217d068.h"
#include "code_0212df7c.h"
#include "code_0214a390.h"
#include "00/unk_021b4000.h"
#include "Main/Graphics/oam.h"
#include "Main/Graphics/locate_bmg_sections.h"
#include "Main/Net/wifi_session_login.h"
#include "Main/Unknown/code_021266e4.h"
#include "Main/Menu/select_return.h"
#include "Main/Unknown/unk_02175000.h"
#include "Main/Unknown/code_02061250.h"

void InitWiFiTopMenu(void *heap) {
    s32 i;
    s32 j;
    s32 k;

    gWiFiTopMenu = HeapAlloc(heap, 0x40);
    gWiFiTopMenu->mHeap = heap;
    gWiFiTopMenu->mState = 0;
    gWiFiTopMenu->mNextState = 0;
    gWiFiTopMenu->mPendingWiFiState = -1;
    switch (GetWiFiPrevState()) {
        case 0:
        case 2:
            gWiFiTopMenu->mIndex = 0;
            break;
        case 8:
            gWiFiTopMenu->mIndex = 1;
            break;
        case 13:
            gWiFiTopMenu->mIndex = 2;
            break;
    }
    gWiFiTopMenu->mStateFrames = 0;
    gWiFiTopMenu->mHighlightVisible = TRUE;
    gWiFiTopMenu->mWiFiMessages = FindSceneFile("wifi.bmg");
    gWiFiTopMenu->mCommonMessages = FindFileInLoadedArchives("common.bmg");
    LocateAndQueueWiFiTopMenu();
    for (i = 0; i < 3; i++) {
        SetCellOamModeXlu(gWiFiTopMenuXluCellIndices[i], 1, gWiFiTopMenu->mWiFiTopMenuSNcer,
                          gWiFiTopMenu->mWiFiTopMenuBncl);
    }
    ResetOamLists(GetWiFiMenuMainOamList(), GetWiFiMenuSubOamList());
    InitLayoutTable(heap, gWiFiTopMenu->mWiFiTopMenuBncl, NULL, &gWiFiTopMenu->mWiFiTopMenuTable);
    for (j = 0; j < 3; j++) {
        for (k = 0; k < gWiFiTopMenuOffsetCellCounts[j]; k++) {
            gWiFiTopMenu->mWiFiTopMenuTable[gWiFiTopMenuOffsetTableIndices[j][k]].mOffsetX = 0xdc;
        }
    }
    SetLinkLevelIconEnabled(1, 0);
    SetSelectReturnSoundId(0xf);
    SendLedPatternNone();
}

void ClearWiFiTopMenuPointer(void) {
    gWiFiTopMenu = NULL;
}

void LocateAndQueueWiFiTopMenu(void) {
    void *sceneFile;
    sceneFile = FindSceneFile(gWiFiTopMenuSBnclName);
    gWiFiTopMenu->mWiFiTopMenuBncl = sceneFile;
    sceneFile = FindSceneFile(gWiFiTopMenuSBnblName);
    gWiFiTopMenu->mWiFiTopMenuBnbl = sceneFile;
    sceneFile = FindSceneFile(gWiFiTopMenuSNcgrName);
    LocateNcgr2(&gWiFiTopMenu->mWiFiTopMenuSNcgr, sceneFile);
    sceneFile = FindSceneFile(gWiFiTopMenuSNcerName);
    LocateNcer(&gWiFiTopMenu->mWiFiTopMenuSNcer, sceneFile);
    sceneFile = FindSceneFile(gWiFiTopMenuSONclrName);
    LocateNclr(&gWiFiTopMenu->mWiFiTopMenuSONclr, sceneFile);
    NNS_GfdRegisterNewVramTransferTask(0x23, 0, (gWiFiTopMenu->mWiFiTopMenuSNcgr->mData),
                                       gWiFiTopMenu->mWiFiTopMenuSNcgr->mDataSize);
    NNS_GfdRegisterNewVramTransferTask(0x1e, 0, (gWiFiTopMenu->mWiFiTopMenuSONclr->mData),
                                       gWiFiTopMenu->mWiFiTopMenuSONclr->mDataSize);
}

s32 IsUserDataFriendKeyNonZeroWrapper(void) {
    return IsUserDataFriendKeyNonZero();
}

void AdvanceWiFiTopMenuState0(void) {
    int fadesClear;
    fadesClear = AreBrightnessFadesClear();
    if (fadesClear != 0) {
        gWiFiTopMenu->mNextState = 1;
    }
}

void AdvanceWiFiTopMenuState1(void) {
    s32 offsetX = 0;
    s32 i;
    s32 j;

    gWiFiTopMenu->mStateFrames = gWiFiTopMenu->mStateFrames + 1;
    if (gWiFiTopMenu->mStateFrames >= 20) {
        gWiFiTopMenu->mNextState = 2;
        gWiFiTopMenu->mStateFrames = offsetX;
        RequestSelectReturnState1();
    } else if (gWiFiTopMenu->mStateFrames >= 10) {
        offsetX = GetSelectedPressOffset(gWiFiTopMenu->mStateFrames - 10);
    } else {
        offsetX = InterpolateS16(1, 0xdc, offsetX, gWiFiTopMenu->mStateFrames, 10);
    }
    for (i = 0; i < 3; i++) {
        for (j = 0; j < gWiFiTopMenuOffsetCellCounts[i]; j++) {
            gWiFiTopMenu->mWiFiTopMenuTable[gWiFiTopMenuOffsetTableIndices[i][j]].mOffsetX = offsetX;
        }
    }
}

void AdvanceWiFiTopMenuState2(void) {
    int returnState2NoRequest;
    returnState2NoRequest = IsSelectReturnState2NoState3Or4Request();
    if (returnState2NoRequest != 0) {
        gWiFiTopMenu->mNextState = 3;
        SetSelectReturnSoundId(0xf);
    }
}

void AdvanceWiFiTopMenuState3(void) {
    InputSlotIndex slotIndex = UNK_02175628_INDEX_8;
    BOOL pairNewUnlessRecentlyLost = FALSE;
    u32 hitIndex = -1;
    BOOL pairRecentlyLost = FALSE;
    s32 previousIndex;
    s32 pressedKeys;
    BOOL backPairNewUnlessRecentlyLost;
    s32 backPairRecentlyLost;

    if (gInputSlots[slotIndex].mPair.mHasPair == 0 && gInputSlots[slotIndex].mPair.mNoPairCount < 5) {
        pairRecentlyLost = TRUE;
    }
    if (pairRecentlyLost == FALSE && gInputSlots[slotIndex].mPair.mPrevHasPair == 0 &&
        gInputSlots[slotIndex].mPair.mHasPair != 0) {
        pairNewUnlessRecentlyLost = TRUE;
    }
    if (pairNewUnlessRecentlyLost != FALSE) {
        hitIndex = RectTableFindContaining(gWiFiTopMenu->mWiFiTopMenuBnbl, gInputSlots[slotIndex].mPair.mPairX,
                                           gInputSlots[slotIndex].mPair.mPairY);
    }
    pressedKeys = gInputSlots[slotIndex].mPressedBits & PAD_KEY_B;
    if ((u16) pressedKeys == 0) {
        backPairRecentlyLost = backPairNewUnlessRecentlyLost = FALSE;
        if (gInputSlots[slotIndex].mPair.mHasPair == 0 && gInputSlots[slotIndex].mPair.mNoPairCount < 5) {
            backPairRecentlyLost = 1;
        }
        if (backPairRecentlyLost == 0 && gInputSlots[slotIndex].mPair.mPrevHasPair == 0 &&
            gInputSlots[slotIndex].mPair.mHasPair != 0) {
            backPairNewUnlessRecentlyLost = TRUE;
        }
        if (backPairNewUnlessRecentlyLost == FALSE ||
            IsSelectReturnState2NoState3Or4RequestAndInRect(gInputSlots[slotIndex].mPair.mPairX,
                                                            gInputSlots[slotIndex].mPair.mPairY) == FALSE) {
            goto next;
        }
    }
    gWiFiTopMenu->mNextState = 5;
    gWiFiTopMenu->mPendingWiFiState = 10;
    if (gWiFiTopMenu->mPendingWiFiState == 10) {
        RequestSelectReturnState3WithSound(1);
    }
    return;
next:
    pressedKeys = gInputSlots[slotIndex].mPressedBits & PAD_KEY_A;
    if ((u16) pressedKeys != 0 || hitIndex <= 2) {
        previousIndex = gWiFiTopMenu->mIndex;
        if ((u16) pressedKeys == 0) {
            switch (hitIndex) {
                case 0:
                    gWiFiTopMenu->mIndex = 0;
                    break;
                case 1:
                    gWiFiTopMenu->mIndex = 1;
                    break;
                case 2:
                    gWiFiTopMenu->mIndex = 2;
                    break;
            }
        }
        if (gWiFiTopMenu->mIndex == previousIndex) {
            gWiFiTopMenu->mHighlightVisible = FALSE;
        }
        gWiFiTopMenu->mNextState = 4;
        switch (gWiFiTopMenu->mIndex) {
            case 0:
                if (GetWiFiSessionLoginResult() == 1) {
                    gWiFiTopMenu->mPendingWiFiState = 2;
                } else {
                    gWiFiTopMenu->mPendingWiFiState = 0;
                }
                break;
            case 1:
                gWiFiTopMenu->mPendingWiFiState = 8;
                break;
            case 2:
                gWiFiTopMenu->mPendingWiFiState = 13;
                break;
        }
        StartSoundOncePerFrame(5);
    } else {
        if (GetNewOrRepeatBits(8, PAD_KEY_UP) != 0) {
            gWiFiTopMenu->mIndex--;
            if (gWiFiTopMenu->mIndex < 0) {
                gWiFiTopMenu->mIndex = 2;
            }
            StartSoundOncePerFrame(0);
        } else if (GetNewOrRepeatBits(8, PAD_KEY_DOWN) != 0) {
            gWiFiTopMenu->mIndex++;
            if (gWiFiTopMenu->mIndex > 2) {
                gWiFiTopMenu->mIndex = 0;
            }
            StartSoundOncePerFrame(0);
        }
    }
}

void AdvanceWiFiTopMenuState4(void) {
    s32 i;
    s32 selectedPressOffset;

    gWiFiTopMenu->mStateFrames = gWiFiTopMenu->mStateFrames + 1;
    selectedPressOffset = GetSelectedPressOffset(gWiFiTopMenu->mStateFrames);
    for (i = 0; i < gWiFiTopMenuOffsetCellCounts[gWiFiTopMenu->mIndex]; i++) {
        gWiFiTopMenu->mWiFiTopMenuTable[gWiFiTopMenuOffsetTableIndices[gWiFiTopMenu->mIndex][i]].mOffsetX =
            selectedPressOffset;
    }
    if (gWiFiTopMenu->mStateFrames >= 10) {
        gWiFiTopMenu->mNextState = 5;
        if (gWiFiTopMenu->mIndex == 0 || gWiFiTopMenu->mIndex == 2) {
            RequestSelectReturnState4();
        }
        gWiFiTopMenu->mStateFrames = 0;
    } else if (gWiFiTopMenu->mStateFrames >= 5) {
        gWiFiTopMenu->mHighlightVisible = TRUE;
    }
}

void AdvanceWiFiTopMenuState5(void) {
    s32 i;
    s32 j;
    s32 v;
    if (GetWiFiNextScene() == -1) {
        if (gWiFiTopMenu->mPendingWiFiState == 10 && GetWiFiSessionLoginResult() != 1) {
            SetWiFiNextScene(0);
        } else if (gWiFiTopMenu->mPendingWiFiState == 13) {
            gStartupWork->mConnectionKind = 4;
            SetWiFiNextScene(12);
        }
    }
    gWiFiTopMenu->mStateFrames++;
    v = gWiFiTopMenu->mStateFrames;
    if (v <= 10) {
        v = InterpolateS16(1, 0xdc, 0, 10 - v, 10);
    } else {
        v = 0xdc;
    }
    for (i = 0; i < 3; i++) {
        for (j = 0; j < gWiFiTopMenuOffsetCellCounts[i]; j++) {
            gWiFiTopMenu->mWiFiTopMenuTable[gWiFiTopMenuOffsetTableIndices[i][j]].mOffsetX = v;
        }
    }
    if (gWiFiTopMenu->mStateFrames >= 10) {
        if ((gWiFiTopMenu->mPendingWiFiState == 10 || gWiFiTopMenu->mPendingWiFiState == 13) &&
            IsSelectReturnState0NoState1Request() == 0) {
            return;
        }
        if (GetWiFiNextScene() == -1) {
            if (gWiFiTopMenu->mPendingWiFiState == 8 && IsUserDataFriendKeyNonZeroWrapper() == 0) {
                gWiFiTopMenu->mNextState = 8;
                gWiFiTopMenu->mPendingWiFiState = -1;
                SetupTxtSystemMainText(GetBmgEntry(gWiFiTopMenu->mWiFiMessages, 0x12));
                gWiFiTopMenu->mStateFrames = 0;
                SetSelectReturnSoundId(0xe);
                return;
            }
            RequestWiFiState(gWiFiTopMenu->mPendingWiFiState);
        }
    }
}

void AdvanceWiFiTopMenuState6(void) {
    int v1;
    v1 = GetTxtSystemDone();
    if (v1 != 0) {
        RequestTxtSystemClose();
        return;
    }
    v1 = IsTxtSystemState0NoOpenRequest();
    if (v1 != 0) {
        v1 = GetTxtSystemSelectedIndex();
        if (v1 == 0) {
            ReleaseWiFiSession();
            gWiFiTopMenu->mNextState = 7;
            return;
        }
        gWiFiTopMenu->mNextState = 1;
    }
}

void AdvanceWiFiTopMenuState7(void) {
    int v1;
    v1 = GetWiFiNextScene();
    if ((v1 == -1) && (gWiFiTopMenu->mPendingWiFiState == 10)) {
        SetWiFiNextScene(0);
    }
    v1 = GetWiFiSessionLoginResult();
    if (v1 != 1) {
        gWiFiTopMenu->mPendingWiFiState = 10;
    }
}

void AdvanceWiFiTopMenuState8(void) {
    InputSlotIndex slotIndex = UNK_02175628_INDEX_8;
    s32 pairRecentlyLost;
    BOOL pairNewUnlessRecentlyLost;
    u32 hasPair;
    if (IsTxtSystemState2AfterState1() != 0) {
        NNS_SndArcPlayerStartSeqArc(&gSharedSeqHandle, 0, 0x15);
    }
    if (IsTxtSystemState2NoCloseRequest() != 0 && IsSelectReturnState2NoState3Or4Request() != 0) {
        if ((u16) (gInputSlots[slotIndex].mPressedBits & PAD_KEY_B) == 0) {
            pairRecentlyLost = pairNewUnlessRecentlyLost = FALSE;
            hasPair = gInputSlots[slotIndex].mPair.mHasPair;
            if (hasPair == 0 && gInputSlots[slotIndex].mPair.mNoPairCount < 5) {
                pairRecentlyLost = 1;
            }
            if (pairRecentlyLost == 0 && gInputSlots[slotIndex].mPair.mPrevHasPair == 0 && hasPair != 0) {
                pairNewUnlessRecentlyLost = TRUE;
            }
            if (pairNewUnlessRecentlyLost == FALSE ||
                IsSelectReturnState2NoState3Or4RequestAndInRect(gInputSlots[slotIndex].mPair.mPairX,
                                                                gInputSlots[slotIndex].mPair.mPairY) == FALSE) {
                return;
            }
        }
        gWiFiTopMenu->mNextState = 1;
        RequestSelectReturnState3WithSound(0);
        RequestTxtSystemClose();
    }
}

void UpdateWiFiTopMenuHighlight(void) {
    s32 i = 0;
    BOOL hidden = FALSE;
    const u8 *tableIndexPointer = gWiFiTopMenuSTableIndices;
    const u8 *cellIndexPointer = gWiFiTopMenuCellIndices;
    for (; i < 3; i++) {
        if (i == gWiFiTopMenu->mIndex && gWiFiTopMenu->mHighlightVisible != FALSE) {
            gWiFiTopMenu->mWiFiTopMenuTable[*tableIndexPointer].mVisible = 1;
            SetCellPaletteIndex(*cellIndexPointer, 0xe, gWiFiTopMenu->mWiFiTopMenuSNcer,
                                gWiFiTopMenu->mWiFiTopMenuBncl);
        } else {
            gWiFiTopMenu->mWiFiTopMenuTable[*tableIndexPointer].mVisible = hidden;
            SetCellPaletteIndex(*cellIndexPointer, 0xf, gWiFiTopMenu->mWiFiTopMenuSNcer,
                                gWiFiTopMenu->mWiFiTopMenuBncl);
        }
        tableIndexPointer++;
        cellIndexPointer++;
    }
}

void AdvanceWiFiTopMenu(void) {
    WiFiTopMenu *wiFiTopMenu;
    gWiFiTopMenu->mState = gWiFiTopMenu->mNextState;
    switch (gWiFiTopMenu->mState) {
        case 0:
            AdvanceWiFiTopMenuState0();
            break;
        case 1:
            AdvanceWiFiTopMenuState1();
            break;
        case 2:
            AdvanceWiFiTopMenuState2();
            break;
        case 3:
            AdvanceWiFiTopMenuState3();
            break;
        case 4:
            AdvanceWiFiTopMenuState4();
            break;
        case 5:
            AdvanceWiFiTopMenuState5();
            break;
        case 6:
            AdvanceWiFiTopMenuState6();
            break;
        case 7:
            AdvanceWiFiTopMenuState7();
            break;
        case 8:
            AdvanceWiFiTopMenuState8();
            break;
    }
    UpdateWiFiTopMenuHighlight();
    wiFiTopMenu = gWiFiTopMenu;
    DrawLayoutTable(wiFiTopMenu->mWiFiTopMenuBncl, wiFiTopMenu->mWiFiTopMenuSNcer, NULL, GetWiFiMenuSubOamList(),
                    wiFiTopMenu->mWiFiTopMenuTable);
}

void WriteWiFiTopMenuRegisters(void) {
    G2x_SetBlendAlpha_(&reg_G2S_DB_BLDCNT, 0, 2, 6, 10);
}

void RegisterWiFiTopMenuCallbacks(void) {
    WiFiStateCallbacks callbacks = gWiFiTopMenuCallbacks;
    SetWiFiStateCallbacks(&callbacks);
}
