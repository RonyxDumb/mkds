#include "00/Menu/wi_fi_aikotoba.h"
#include "registers.h"
#include "Main/System/heap.h"
#include "00/unk_021b0000.h"
#include "Main/Scene/display_settings.h"
#include "g2.h"
#include "gx_load2d.h"

#include "00/code_02180608.h"
#include "00/unk_021b4000.h"
#include "00/Scene/wi_fi_menu_scene.h"
#include "Main/Graphics/layout_entry_angle.h"
#include "Main/Graphics/layout_table_entry.h"
#include "Main/Menu/txt_system.h"
#include "Main/Menu/select_return.h"
#include "Main/Graphics/oam.h"
#include "Main/Sound/sound_seq.h"
#include "Main/Menu/data_02175628.h"
#include "Main/Graphics/layout_rect_table.h"
#include "Main/System/result_archive_path.h"

const u8 gWiFiAikotobaCellIndices[2] = {6, 7};
const u8 gWiFiAikotobaSTableIndices[2] = {4, 5};
const s32 gWiFiAikotobaOffsetCellCounts[2] = {4, 4};
const u8 gWiFiAikotobaOffsetTableIndices[2][4] = {{0, 2, 4, 6}, {1, 3, 5, 7}};
const u8 gWiFiAikotobaXluCellIndices[2] = {0, 1};
WiFiStateCallbacks gWiFiAikotobaCallbacks = {InitWiFiAikotoba, ClearWiFiAikotobaPointer, AdvanceWiFiAikotoba, WriteWiFiAikotobaRegisters};
WiFiAikotoba *gWiFiAikotoba;

void InitWiFiAikotoba(void *heap) {
    s32 i;
    s32 j;
    u32 wiFiPrevState;
    void *oamList;

    gWiFiAikotoba = HeapAlloc(heap, 0x40);
    gWiFiAikotoba->mHeap = heap;
    gWiFiAikotoba->mState = 0;
    gWiFiAikotoba->mNextState = 0;
    gWiFiAikotoba->mPendingWiFiState = -1;
    wiFiPrevState = GetWiFiPrevState();
    switch (wiFiPrevState) {
        case 1:
        case 11:
            gWiFiAikotoba->mSelectedIndex = 0;
            break;
        case 9:
            gWiFiAikotoba->mSelectedIndex = 1;
            break;
    }
    gWiFiAikotoba->mStateFrames = 0;
    gWiFiAikotoba->mHighlightVisible = TRUE;
    LocateAndUploadWiFiAikotoba();
    for (i = 0; i < 2; i++) {
        SetCellOamModeXlu(gWiFiAikotobaXluCellIndices[i], 1, gWiFiAikotoba->mWiFiAikotobaSNcer,
                          gWiFiAikotoba->mWiFiAikotobaBncl);
    }
    oamList = GetWiFiMenuMainOamList();
    ResetOamLists(oamList, GetWiFiMenuSubOamList());
    InitLayoutTable(heap, gWiFiAikotoba->mWiFiAikotobaBncl, NULL, &gWiFiAikotoba->mWiFiAikotobaTable);
    gWiFiAikotoba->mWiFiMessages = FindSceneFile("wifi.bmg");
    gWiFiAikotoba->mCommonMessages = FindFileInLoadedArchives("common.bmg");
    for (i = 0; i < 2; i++) {
        for (j = 0; j < gWiFiAikotobaOffsetCellCounts[i]; j++) {
            gWiFiAikotoba->mWiFiAikotobaTable[gWiFiAikotobaOffsetTableIndices[i][j]].mOffsetX = 0xfa;
        }
    }
    SetSelectReturnSoundId(0xe);
}

void ClearWiFiAikotobaPointer(void) {
    gWiFiAikotoba = NULL;
}

void LocateAndUploadWiFiAikotoba(void) {
    void *sceneFile;
    sceneFile = FindSceneFile("WiFi_aikotoba.bncl");
    gWiFiAikotoba->mWiFiAikotobaBncl = sceneFile;
    sceneFile = FindSceneFile("WiFi_aikotoba.bnbl");
    gWiFiAikotoba->mWiFiAikotobaBnbl = sceneFile;
    sceneFile = FindSceneFile("WiFi_aikotoba_s.nce.ncgr");
    LocateNcgr2(&gWiFiAikotoba->mWiFiAikotobaSNcgr, sceneFile);
    sceneFile = FindSceneFile("WiFi_aikotoba_s.nce.ncer");
    LocateNcer(&gWiFiAikotoba->mWiFiAikotobaSNcer, sceneFile);
    sceneFile = FindSceneFile("WiFi_aikotoba_s_o.nclr");
    LocateNclr(&gWiFiAikotoba->mWiFiAikotobaSONclr, sceneFile);
    GXS_LoadOBJ(gWiFiAikotoba->mWiFiAikotobaSNcgr->mData, 0, gWiFiAikotoba->mWiFiAikotobaSNcgr->mDataSize);
    GXS_LoadOBJPltt(gWiFiAikotoba->mWiFiAikotobaSONclr->mData, 0, gWiFiAikotoba->mWiFiAikotobaSONclr->mDataSize);
}

BOOL IsBuddyRecordBlockFull(void) {
    u32 recordCount;
    recordCount = CountEmblemEntries();
    if (60 <= recordCount) {
        return 1;
    }
    return 0;
}

void AdvanceWiFiAikotobaState0(void) {
    int fadesClear;
    fadesClear = AreBrightnessFadesClear();
    if (fadesClear != 0) {
        gWiFiAikotoba->mNextState = 1;
    }
}

void AdvanceWiFiAikotobaState1(void) {
    s32 offsetX;
    s32 i;
    s32 j;

    gWiFiAikotoba->mStateFrames = gWiFiAikotoba->mStateFrames + 1;
    offsetX = InterpolateS16(1, 0xfa, 0, gWiFiAikotoba->mStateFrames, 10);
    for (i = 0; i < 2; i++) {
        for (j = 0; j < gWiFiAikotobaOffsetCellCounts[i]; j++) {
            if (i == 1) {
                gWiFiAikotoba->mWiFiAikotobaTable[gWiFiAikotobaOffsetTableIndices[i][j]].mOffsetX = offsetX;
            } else {
                gWiFiAikotoba->mWiFiAikotobaTable[gWiFiAikotobaOffsetTableIndices[i][j]].mOffsetX = -offsetX;
            }
        }
    }
    if (gWiFiAikotoba->mStateFrames >= 10) {
        gWiFiAikotoba->mNextState = 2;
        gWiFiAikotoba->mStateFrames = 0;
        RequestSelectReturnState1();
    }
}

void AdvanceWiFiAikotobaState2(void) {
    int returnState2NoRequest;
    returnState2NoRequest = IsSelectReturnState2NoState3Or4Request();
    if (returnState2NoRequest != 0) {
        gWiFiAikotoba->mNextState = 3;
    }
}

void AdvanceWiFiAikotobaState3(void) {
    InputSlotIndex slotIndex = UNK_02175628_INDEX_8;
    u32 hitIndex = -1;
    BOOL pairNewUnlessRecentlyLost;
    BOOL pairRecentlyLost;
    u16 hasPair;
    s32 previousIndex;
    u32 pressedKeys;
    WiFiAikotoba *wiFiAikotoba;

    pairNewUnlessRecentlyLost = FALSE;
    pairRecentlyLost = FALSE;
    hasPair = gInputSlots[slotIndex].mPair.mHasPair;
    if (hasPair == 0 && gInputSlots[slotIndex].mPair.mNoPairCount < 5) {
        pairRecentlyLost = TRUE;
    }
    if (pairRecentlyLost == FALSE && gInputSlots[slotIndex].mPair.mPrevHasPair == 0 && hasPair != 0) {
        pairNewUnlessRecentlyLost = TRUE;
    }
    if (pairNewUnlessRecentlyLost != FALSE) {
        hitIndex = RectTableFindContaining(gWiFiAikotoba->mWiFiAikotobaBnbl, gInputSlots[slotIndex].mPair.mPairX,
                                           gInputSlots[slotIndex].mPair.mPairY);
    }
    if ((u16) (gInputSlots[slotIndex].mPressedBits & PAD_KEY_B) == 0) {
        pairNewUnlessRecentlyLost = FALSE;
        pairRecentlyLost = FALSE;
        hasPair = gInputSlots[slotIndex].mPair.mHasPair;
        if (hasPair == 0 && gInputSlots[slotIndex].mPair.mNoPairCount < 5) {
            pairRecentlyLost = TRUE;
        }
        if (pairRecentlyLost == FALSE && gInputSlots[slotIndex].mPair.mPrevHasPair == 0 && hasPair != 0) {
            pairNewUnlessRecentlyLost = TRUE;
        }
        if (pairNewUnlessRecentlyLost == FALSE ||
            IsSelectReturnState2NoState3Or4RequestAndInRect(gInputSlots[slotIndex].mPair.mPairX,
                                                            gInputSlots[slotIndex].mPair.mPairY) == FALSE) {
            goto next;
        }
    }
    gWiFiAikotoba->mNextState = 5;
    gWiFiAikotoba->mPendingWiFiState = 1;
    RequestSelectReturnState3WithSound(0);
    return;
next:
    pressedKeys = gInputSlots[slotIndex].mPressedBits & PAD_KEY_A;
    if ((u16) pressedKeys != 0 || hitIndex <= 1) {
        wiFiAikotoba = gWiFiAikotoba;
        previousIndex = wiFiAikotoba->mSelectedIndex;
        if ((u16) pressedKeys == 0) {
            switch (hitIndex) {
                case 0:
                    wiFiAikotoba->mSelectedIndex = 0;
                    break;
                case 1:
                    wiFiAikotoba->mSelectedIndex = 1;
                    break;
            }
        }
        gWiFiAikotoba->mNextState = 4;
        switch (gWiFiAikotoba->mSelectedIndex) {
            case 0:
                gWiFiAikotoba->mPendingWiFiState = 11;
                break;
            case 1:
                gWiFiAikotoba->mPendingWiFiState = 9;
                break;
        }
        if (gWiFiAikotoba->mSelectedIndex == previousIndex) {
            gWiFiAikotoba->mHighlightVisible = FALSE;
        }
        StartSoundOncePerFrame(5);
        return;
    }
    if (GetNewOrRepeatBits(8, PAD_KEY_UP) != 0 && gWiFiAikotoba->mSelectedIndex > 0) {
        gWiFiAikotoba->mSelectedIndex = gWiFiAikotoba->mSelectedIndex - 1;
        StartSoundOncePerFrame(0);
        return;
    }
    if (GetNewOrRepeatBits(8, PAD_KEY_DOWN) != 0 && gWiFiAikotoba->mSelectedIndex < 1) {
        gWiFiAikotoba->mSelectedIndex = gWiFiAikotoba->mSelectedIndex + 1;
        StartSoundOncePerFrame(0);
    }
}

void AdvanceWiFiAikotobaState4(void) {
    gWiFiAikotoba->mStateFrames = gWiFiAikotoba->mStateFrames + 1;
    if (gWiFiAikotoba->mStateFrames >= 10) {
        gWiFiAikotoba->mNextState = 5;
        if (gWiFiAikotoba->mPendingWiFiState == 11) {
            RequestSelectReturnState4();
        }
        gWiFiAikotoba->mStateFrames = 0;
    } else if (gWiFiAikotoba->mStateFrames >= 5) {
        gWiFiAikotoba->mHighlightVisible = TRUE;
    }
}

void AdvanceWiFiAikotobaState5(void) {
    s32 offsetX;
    s32 i;
    s32 j;
    s32 b;
    void *bmgEntry;

    if (GetWiFiNextScene() == -1 && IsBuddyRecordBlockFull() == 0 && gWiFiAikotoba->mPendingWiFiState == 11) {
        SetWiFiNextScene(0xe);
    }
    gWiFiAikotoba->mStateFrames = gWiFiAikotoba->mStateFrames + 1;
    if (gWiFiAikotoba->mStateFrames <= 10) {
        offsetX = InterpolateS16(1, 0, 0xfa, gWiFiAikotoba->mStateFrames, 10);
    } else {
        offsetX = 0xfa;
    }
    for (i = 0; i < 2; i++) {
        for (j = 0; j < gWiFiAikotobaOffsetCellCounts[i]; j++) {
            if (i == 1) {
                gWiFiAikotoba->mWiFiAikotobaTable[gWiFiAikotobaOffsetTableIndices[i][j]].mOffsetX = offsetX;
            } else {
                gWiFiAikotoba->mWiFiAikotobaTable[gWiFiAikotobaOffsetTableIndices[i][j]].mOffsetX = -offsetX;
            }
        }
    }
    if (gWiFiAikotoba->mStateFrames >= 10) {
        if (IsBuddyRecordBlockFull() != 0 && gWiFiAikotoba->mPendingWiFiState == 11) {
            gWiFiAikotoba->mNextState = 6;
            gWiFiAikotoba->mPendingWiFiState = -1;
            bmgEntry = GetBmgEntry(gWiFiAikotoba->mWiFiMessages, 0xf);
            SetupTxtSystemMainTextButton(bmgEntry, GetBmgEntry(gWiFiAikotoba->mCommonMessages, 6));
            gWiFiAikotoba->mStateFrames = 0;
            return;
        }
        if (GetWiFiNextScene() == -1) {
            RequestWiFiState(gWiFiAikotoba->mPendingWiFiState);
        }
    }
}

void AdvanceWiFiAikotobaState6(void) {
    void *questionText;
    void *yesText;

    if (IsTxtSystemState0NoOpenRequest() != 0 && IsSelectReturnState0NoState1Request() != 0) {
        gWiFiAikotoba->mNextState = 7;
        questionText = GetBmgEntry(gWiFiAikotoba->mWiFiMessages, 0x10);
        yesText = GetBmgEntry(gWiFiAikotoba->mCommonMessages, 0);
        SetupTxtSystemMainTextTwoButtons(questionText, yesText, GetBmgEntry(gWiFiAikotoba->mCommonMessages, 1), 0);
        return;
    }
    if (GetTxtSystemDone() != 0) {
        RequestTxtSystemClose();
    }
}

void AdvanceWiFiAikotobaState7(void) {
    if (IsTxtSystemState0NoOpenRequest() != 0) {
        if (GetTxtSystemSelectedIndex() == 0) {
            gWiFiAikotoba->mPendingWiFiState = 0xe;
            if (GetWiFiNextScene() == -1) {
                SetWiFiNextScene(8);
            }
            gMenuShared->mWiFiScene8StartKind = 1;
            return;
        }
        gWiFiAikotoba->mNextState = 1;
        gWiFiAikotoba->mPendingWiFiState = -1;
        return;
    }
    if (GetTxtSystemDone() != 0) {
        RequestTxtSystemClose();
    }
}

void UpdateWiFiAikotobaHighlight(void) {
    s32 i;

    for (i = 0; i < 2; i++) {
        if (i == gWiFiAikotoba->mSelectedIndex && gWiFiAikotoba->mHighlightVisible != FALSE) {
            gWiFiAikotoba->mWiFiAikotobaTable[gWiFiAikotobaSTableIndices[i]].mVisible = 1;
            SetCellPaletteIndex(gWiFiAikotobaCellIndices[i], 0xe, gWiFiAikotoba->mWiFiAikotobaSNcer,
                                gWiFiAikotoba->mWiFiAikotobaBncl);
        } else {
            gWiFiAikotoba->mWiFiAikotobaTable[gWiFiAikotobaSTableIndices[i]].mVisible = 0;
            SetCellPaletteIndex(gWiFiAikotobaCellIndices[i], 0xf, gWiFiAikotoba->mWiFiAikotobaSNcer,
                                gWiFiAikotoba->mWiFiAikotobaBncl);
        }
    }
}

void AdvanceWiFiAikotoba(void) {
    WiFiAikotoba *wiFiAikotoba;

    gWiFiAikotoba->mState = gWiFiAikotoba->mNextState;
    switch (gWiFiAikotoba->mState) {
        case 0:
            AdvanceWiFiAikotobaState0();
            break;
        case 1:
            AdvanceWiFiAikotobaState1();
            break;
        case 2:
            AdvanceWiFiAikotobaState2();
            break;
        case 3:
            AdvanceWiFiAikotobaState3();
            break;
        case 4:
            AdvanceWiFiAikotobaState4();
            break;
        case 5:
            AdvanceWiFiAikotobaState5();
            break;
        case 6:
            AdvanceWiFiAikotobaState6();
            break;
        case 7:
            AdvanceWiFiAikotobaState7();
            break;
    }
    UpdateWiFiAikotobaHighlight();
    wiFiAikotoba = gWiFiAikotoba;
    DrawLayoutTable(wiFiAikotoba->mWiFiAikotobaBncl, wiFiAikotoba->mWiFiAikotobaSNcer, NULL, GetWiFiMenuSubOamList(),
                    wiFiAikotoba->mWiFiAikotobaTable);
}

void WriteWiFiAikotobaRegisters(void) {
    G2x_SetBlendAlpha_(&reg_G2S_DB_BLDCNT, 0, 2, 6, 10);
}

void RegisterWiFiAikotobaCallbacks(void) {
    WiFiStateCallbacks callbacks = gWiFiAikotobaCallbacks;
    SetWiFiStateCallbacks(&callbacks);
}
