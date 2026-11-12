#include "00/Menu/wi_fi_aikotoba_check.h"
#include "00/unk_021b0000.h"
#include "gx_load2d.h"

#include "00/code_02180608.h"
#include "00/Menu/wi_fi_aikotoba.h"
#include "00/unk_021b4000.h"
#include "00/Scene/wi_fi_menu_scene.h"
#include "Main/System/heap.h"
#include "Main/Graphics/layout_table_entry.h"
#include "Main/Menu/txt_system.h"
#include "Main/Menu/select_return.h"
#include "Main/Graphics/oam.h"
#include "Main/Menu/data_02175628.h"
#include "Main/Graphics/locate_bmg_sections.h"
#include "Main/Save/ghost_file_records.h"
#include "Main/System/result_archive_path.h"

void SetWiFiAikotobaCheckDigits(void) {
    u8 friendKeyText[20];
    s32 i;

    FormatUserDataFriendKey((u32) friendKeyText);
    for (i = 0; i < 12; i++) {
        gWiFiAikotobaCheck->mDigits[i] = friendKeyText[i];
    }
}

void InitWiFiAikotobaCheckDigits(void) {
    s32 subObjSizeLeft = 0x4000;
    u8 entryIndices[12] = {0, 0, 1, 2, 3, 4, 1, 6, 7, 8, 9, 10};
    u8 entryIsCell[12] = {1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0};
    u16 cellCount;
    s32 i;
    s16 digitText[2];

    cellCount = gWiFiAikotobaCheck->mWiFiAikotobaCheckBncl->mCount;
    SetWiFiAikotobaCheckDigits();
    for (i = 0; i < 12; i++) {
        if (entryIsCell[i] == 0) {
            entryIndices[i] = entryIndices[i] + cellCount;
        }
    }
    for (i = 0; i < 12; i++) {
        subObjSizeLeft -=
            InitLabelCanvas(gWiFiAikotobaCheck->mHeap, gWiFiAikotobaCheckDigitLabelIndices[i],
                            gWiFiAikotobaCheck->mWiFiAikotobaCheckBnll, 8, 0x10, entryIndices[i],
                            gWiFiAikotobaCheck->mWiFiAikotobaCheckMNcer, gWiFiAikotobaCheck->mWiFiAikotobaCheckBncl,
                            gWiFiAikotobaCheck->mWiFiAikotobaCheckTable, subObjSizeLeft);
        digitText[0] = 0;
        digitText[1] = 0;
        digitText[0] = gWiFiAikotobaCheck->mDigits[i];
        PrintLabelLayoutTextNoFixedAdvance(
            0, gWiFiAikotobaCheckDigitLabelIndices[i], gWiFiAikotobaCheck->mWiFiAikotobaCheckBnll, digitText,
            gWiFiAikotobaCheck->mWiFiAikotobaCheckBncl, gWiFiAikotobaCheck->mWiFiAikotobaCheckTable);
    }
}

void InitWiFiAikotobaCheck(void *heap) {
    void *oamList;

    gWiFiAikotobaCheck = HeapAlloc(heap, 0x54);
    gWiFiAikotobaCheck->mHeap = heap;
    gWiFiAikotobaCheck->mState = 0;
    gWiFiAikotobaCheck->mNextState = 0;
    gWiFiAikotobaCheck->mPendingWiFiState = -1;
    gWiFiAikotobaCheck->mStateFrames = 0;
    gWiFiAikotobaCheck->mWiFiMessages = FindSceneFile(data_ov000_021b0fc0);
    gWiFiAikotobaCheck->mCommonMessages = FindFileInLoadedArchives(data_ov000_021b0fcc);
    LocateAndUploadWiFiAikotobaCheck();
    oamList = GetWiFiMenuMainOamList();
    ResetOamLists(oamList, GetWiFiMenuSubOamList());
    InitLayoutTable(heap, gWiFiAikotobaCheck->mWiFiAikotobaCheckBncl, gWiFiAikotobaCheck->mWiFiAikotobaCheckBnll,
                    &gWiFiAikotobaCheck->mWiFiAikotobaCheckTable);
    gWiFiAikotobaCheck->mOffset = 0x50;
    UpdateWiFiAikotobaCheckOffsets();
    InitWiFiAikotobaCheckDigits();
    SetupTxtSystemMainTextEx(GetBmgEntry(gWiFiAikotobaCheck->mWiFiMessages, 0x11), 0, 1, 0, 0, 0, 0);
}

void ClearWiFiAikotobaCheckPointer(void) {
    gWiFiAikotobaCheck = NULL;
}

void LocateAndUploadWiFiAikotobaCheck(void) {
    void *sceneFile;
    sceneFile = FindSceneFile(gWiFiAikotobaCheckBnclName);
    gWiFiAikotobaCheck->mWiFiAikotobaCheckBncl = sceneFile;
    sceneFile = FindSceneFile(gWiFiAikotobaCheckBnllName);
    gWiFiAikotobaCheck->mWiFiAikotobaCheckBnll = sceneFile;
    sceneFile = FindSceneFile(gWiFiAikotobaCheckMNcgrName);
    LocateNcgr2(&gWiFiAikotobaCheck->mWiFiAikotobaCheckMNcgr, sceneFile);
    sceneFile = FindSceneFile(gWiFiAikotobaCheckMNcerName);
    LocateNcer(&gWiFiAikotobaCheck->mWiFiAikotobaCheckMNcer, sceneFile);
    sceneFile = FindSceneFile(gWiFiAikotobaCheckMONclrName);
    LocateNclr(&gWiFiAikotobaCheck->mWiFiAikotobaCheckMONclr, sceneFile);
    GX_LoadOBJ(gWiFiAikotobaCheck->mWiFiAikotobaCheckMNcgr->mData, 0,
               gWiFiAikotobaCheck->mWiFiAikotobaCheckMNcgr->mDataSize);
    GX_LoadOBJPltt(gWiFiAikotobaCheck->mWiFiAikotobaCheckMONclr->mData, 0, 0x1a0);
    GX_LoadOBJPltt(gWiFiAikotobaCheck->mWiFiAikotobaCheckMONclr->mData + 0xe0, 0x1c0, 0x40);
}

void UpdateWiFiAikotobaCheckOffsets(void) {
    s32 i;

    for (i = 0; i < 2; i++) {
        gWiFiAikotobaCheck->mWiFiAikotobaCheckTable[gWiFiAikotobaCheckOffsetIndices[i]].mOffsetY =
            gWiFiAikotobaCheck->mOffset;
    }
    for (i = 0; i < 12; i++) {
        gWiFiAikotobaCheck
            ->mWiFiAikotobaCheckTable[gWiFiAikotobaCheckDigitLabelIndices[i] +
                                      gWiFiAikotobaCheck->mWiFiAikotobaCheckBncl->mCount]
            .mOffsetY = gWiFiAikotobaCheck->mOffset;
    }
}

void AdvanceWiFiAikotobaCheckState0(void) {
    gWiFiAikotobaCheck->mStateFrames = gWiFiAikotobaCheck->mStateFrames + 1;
    gWiFiAikotobaCheck->mOffset = InterpolateS16(1, 0x50, 0, gWiFiAikotobaCheck->mStateFrames, 15);
    if (gWiFiAikotobaCheck->mStateFrames >= 15 && IsTxtSystemState2NoCloseRequest() != 0) {
        gWiFiAikotobaCheck->mNextState = 1;
        gWiFiAikotobaCheck->mStateFrames = 0;
    }
}

void AdvanceWiFiAikotobaCheckState1(void) {
    InputSlotIndex slotIndex = UNK_02175628_INDEX_8;
    BOOL pairNewUnlessRecentlyLost;
    BOOL pairRecentlyLost;
    u16 hasPair;

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
            return;
        }
    }
    gWiFiAikotobaCheck->mNextState = 2;
    gWiFiAikotobaCheck->mPendingWiFiState = 8;
    RequestSelectReturnState3WithSound(0);
    RequestTxtSystemClose();
}

void AdvanceWiFiAikotobaCheckState2(void) {
    gWiFiAikotobaCheck->mStateFrames = gWiFiAikotobaCheck->mStateFrames + 1;
    gWiFiAikotobaCheck->mOffset = InterpolateS16(1, 0, 0x50, gWiFiAikotobaCheck->mStateFrames, 15);
    if (gWiFiAikotobaCheck->mStateFrames >= 15 && IsTxtSystemState0NoOpenRequest() != 0 &&
        IsSelectReturnState2NoState3Or4Request() != 0) {
        RequestWiFiState(gWiFiAikotobaCheck->mPendingWiFiState);
    }
}

void AdvanceWiFiAikotobaCheck(void) {
    WiFiAikotobaCheck *wiFiAikotobaCheck;

    gWiFiAikotobaCheck->mState = gWiFiAikotobaCheck->mNextState;
    switch (gWiFiAikotobaCheck->mState) {
        case 0:
            AdvanceWiFiAikotobaCheckState0();
            break;
        case 1:
            AdvanceWiFiAikotobaCheckState1();
            break;
        case 2:
            AdvanceWiFiAikotobaCheckState2();
            break;
    }
    UpdateWiFiAikotobaCheckOffsets();
    wiFiAikotobaCheck = gWiFiAikotobaCheck;
    DrawLayoutTable(wiFiAikotobaCheck->mWiFiAikotobaCheckBncl, wiFiAikotobaCheck->mWiFiAikotobaCheckMNcer,
                    wiFiAikotobaCheck->mWiFiAikotobaCheckBnll, GetWiFiMenuMainOamList(),
                    wiFiAikotobaCheck->mWiFiAikotobaCheckTable);
}

void WriteWiFiAikotobaCheckRegistersNop(void) {}

void RegisterWiFiAikotobaCheckCallbacks(void) {
    WiFiStateCallbacks callbacks = gWiFiAikotobaCheckCallbacks;
    SetWiFiStateCallbacks(&callbacks);
}
