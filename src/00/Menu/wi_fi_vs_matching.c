#include "00/Menu/wi_fi_vs_matching.h"

#include "code_02148950.h"
#include "registers.h"
#include "Main/System/heap.h"
#include "Main/Graphics/oam.h"
#include "Main/Menu/txt_system.h"
#include "Main/Sound/sound_seq.h"
#include "Main/Race/race_setup.h"
#include "00/unk_021b4000.h"
#include "00/code_02180608.h"
#include "Main/Sound/sound_system.h"
#include "Main/Menu/menu_shared_clear.h"
#include "Main/Net/wifi_session.h"
#include "Main/System/init_after_startup.h"

WiFiVSMatching *gWiFiVSMatching;

const s8 gWiFiVSMatchingNameSlideOffsets[30] = {0xa, 8,  6, 4, 2, 0, -2, -3, -4, -4, -4, -3, -3, -2, -2,
                                                -1,  -1, 0, 0, 0, 0, 0,  0,  0,  0,  0,  0,  0,  0,  0};
const u8 gWiFiVSMatchingOffsetTableIndices[3][5] = {{0, 3, 6, 7, 0xc}, {1, 4, 8, 9, 0xd}, {2, 5, 0xa, 0xb, 0xe}};
const u8 gWiFiVSMatchingTotalCellIndices[3][2] = {{6, 7}, {8, 9}, {0xa, 0xb}};
const u8 gWiFiVSMatchingNameCellIndices[3] = {0, 1, 2};
const u8 gWiFiVSMatchingOtherCellIndices[3] = {3, 4, 5};
const u8 gWiFiVSMatchingEmblemCellIndices[3] = {0xc, 0xd, 0xe};
const u8 gWiFiVSMatchingNameLabelIndices[3] = {0, 1, 2};
const u8 gWiFiVSMatchingTotalLabelIndices[3][2] = {{3, 4}, {5, 6}, {7, 8}};
const u8 gWiFiVSMatchingBlendColorOffsets[2] = {0xb, 6};
const u8 gWiFiVSMatchingSearchLabelIndices[3] = {9, 0xa, 0xb};
const s32 gWiFiVSMatchingResultWaitFrames[3] = {0xf0, 0x12c, 0x168};

void InitWiFiVSMatchingLabels(void) {
    s32 subObjSizeLeft;
    u32 settingMessageIndex;
    s32 otherIndex;

    subObjSizeLeft = GX_GetSizeOfSubOBJ();
    {
        u8 nameLabelSizes[3][2] = {{0x78, 0x10}, {0x78, 0x10}, {0x78, 0x10}};
        u8 *nameSizePointer = &nameLabelSizes[0][0];
        const u8 *nameCellPointer;
        const u8 *nameLabelPointer;

        for (otherIndex = 0, nameCellPointer = gWiFiVSMatchingNameCellIndices,
            nameLabelPointer = gWiFiVSMatchingNameLabelIndices;
             otherIndex < 3; otherIndex++) {
            subObjSizeLeft -= InitLabelCanvas(
                gWiFiVSMatching->mHeap, *nameLabelPointer, gWiFiVSMatching->mWiFiVSMatchingBnll, nameSizePointer[0],
                nameSizePointer[1], *nameCellPointer, gWiFiVSMatching->mWiFiVSMatchingSNcer,
                gWiFiVSMatching->mWiFiVSMatchingBncl, gWiFiVSMatching->mWiFiVSMatchingTable, subObjSizeLeft);
            nameCellPointer++;
            nameSizePointer += 2;
            nameLabelPointer++;
        }
    }
    {
        s32 totalIndex;
        u8 totalLabelSizes[3][2][2] = {
            {{0x30, 0x10}, {0x30, 0x10}}, {{0x30, 0x10}, {0x30, 0x10}}, {{0x30, 0x10}, {0x30, 0x10}}};

        for (otherIndex = 0; otherIndex < 3; otherIndex++) {
            for (totalIndex = 0; totalIndex < 2; totalIndex++) {
                subObjSizeLeft -= InitLabelCanvas(
                    gWiFiVSMatching->mHeap, gWiFiVSMatchingTotalLabelIndices[otherIndex][totalIndex],
                    gWiFiVSMatching->mWiFiVSMatchingBnll, totalLabelSizes[otherIndex][totalIndex][0],
                    totalLabelSizes[otherIndex][totalIndex][1], gWiFiVSMatchingTotalCellIndices[otherIndex][totalIndex],
                    gWiFiVSMatching->mWiFiVSMatchingSNcer, gWiFiVSMatching->mWiFiVSMatchingBncl,
                    gWiFiVSMatching->mWiFiVSMatchingTable, subObjSizeLeft);
            }
        }
    }
    {
        void *bmgEntry;
        WiFiVSMatching *wiFiVSMatching;
        u8 searchLabelSizes[3][2] = {{0x78, 0x20}, {0x78, 0x20}, {0x78, 0x20}};
        u8 *searchSizePointer = &searchLabelSizes[0][0];
        const u8 *emblemCellPointer;
        const u8 *searchLabelPointer;

        for (otherIndex = 0, emblemCellPointer = gWiFiVSMatchingEmblemCellIndices,
            searchLabelPointer = gWiFiVSMatchingSearchLabelIndices;
             otherIndex < 3; otherIndex++) {
            subObjSizeLeft -= InitLabelCanvas(
                gWiFiVSMatching->mHeap, *searchLabelPointer, gWiFiVSMatching->mWiFiVSMatchingBnll, searchSizePointer[0],
                searchSizePointer[1], *emblemCellPointer, gWiFiVSMatching->mWiFiVSMatchingSNcer,
                gWiFiVSMatching->mWiFiVSMatchingBncl, gWiFiVSMatching->mWiFiVSMatchingTable, subObjSizeLeft);
            wiFiVSMatching = gWiFiVSMatching;
            bmgEntry = GetBmgEntry(wiFiVSMatching->mWiFiMessages, 9);
            PrintLabelLayoutTextNoFixedAdvance(1, *searchLabelPointer, gWiFiVSMatching->mWiFiVSMatchingBnll, bmgEntry,
                                               wiFiVSMatching->mWiFiVSMatchingBncl,
                                               wiFiVSMatching->mWiFiVSMatchingTable);
            emblemCellPointer++;
            searchSizePointer += 2;
            searchLabelPointer++;
        }
    }
    {
        u8 settingLabelSize[2] = {0xa0, 0x10};

        settingMessageIndex = LookupWiFiVSSettingMessageIndex(GetWiFiVSSettingIndex());
        InitLabelCanvas(gWiFiVSMatching->mHeap, 0xc, gWiFiVSMatching->mWiFiVSMatchingBnll, settingLabelSize[0],
                        settingLabelSize[1], gWiFiVSMatching->mWiFiVSMatchingBncl->mCount,
                        gWiFiVSMatching->mWiFiVSMatchingSNcer, gWiFiVSMatching->mWiFiVSMatchingBncl,
                        gWiFiVSMatching->mWiFiVSMatchingTable, subObjSizeLeft);
        PrintLabelLayoutTextNoFixedAdvance(1, 0xc, gWiFiVSMatching->mWiFiVSMatchingBnll,
                                           GetBmgEntry(gWiFiVSMatching->mWiFiMessages, settingMessageIndex),
                                           gWiFiVSMatching->mWiFiVSMatchingBncl, gWiFiVSMatching->mWiFiVSMatchingTable);
    }
}

void InitWiFiVSMatchingEntryMatrices(void) {
    s32 otherIndex;
    s32 totalIndex;
    const u8 *totalLabelIndices;
    const u8 *emblemCellIndices;
    s32 cellCount;
    const u8 *totalCellIndices;

    cellCount = gWiFiVSMatching->mWiFiVSMatchingBncl->mCount;
    otherIndex = 0;
    totalCellIndices = &gWiFiVSMatchingTotalCellIndices[0][0];
    totalLabelIndices = &gWiFiVSMatchingTotalLabelIndices[0][0];
    emblemCellIndices = gWiFiVSMatchingEmblemCellIndices;
    for (; otherIndex < 3; otherIndex++) {
        for (totalIndex = 0; totalIndex < 2; totalIndex++) {
            gWiFiVSMatching->mWiFiVSMatchingTable[totalCellIndices[totalIndex]].mUseMatrix = 1;
            gWiFiVSMatching->mWiFiVSMatchingTable[cellCount + totalLabelIndices[totalIndex]].mUseMatrix = 1;
            SetLayoutEntryAngleAndScale(&gWiFiVSMatching->mWiFiVSMatchingTable[totalCellIndices[totalIndex]], 0,
                                        0x1000);
        }
        gWiFiVSMatching->mWiFiVSMatchingTable[*emblemCellIndices].mUseMatrix = 1;
        SetLayoutEntryAngleAndScale(&gWiFiVSMatching->mWiFiVSMatchingTable[*emblemCellIndices], 0, 0x1000);
        totalCellIndices += 2;
        totalLabelIndices += 2;
        emblemCellIndices++;
    }
}

void InitWiFiVSMatching(void *heap) {
    s32 otherIndex;
    s32 entryIndex;
    void *oamList;
    const u8 *offsetTableIndices;
    const u8 *emblemCellIndices;
    const u8 *nameLabelIndices;
    const u8 *totalLabelIndices;
    const u8 *nameCellIndices;
    u8 totalLabelIndex;

    GetRaceSetupCopy();
    gWiFiVSMatching = HeapAlloc(heap, 0x170c);
    gWiFiVSMatching->mHeap = heap;
    gWiFiVSMatching->mState = WIFI_VS_MATCHING_STATE_SLIDE_IN;
    gWiFiVSMatching->mNextState = WIFI_VS_MATCHING_STATE_SLIDE_IN;
    gWiFiVSMatching->mPendingWiFiState = WIFI_STATE_NONE;
    gWiFiVSMatching->mStateFrames = 0;
    gWiFiVSMatching->mBlinkFrames = 0;
    gWiFiVSMatching->mShownEntryCount = 0;
    for (otherIndex = 0; otherIndex < 3; otherIndex++) {
        gWiFiVSMatching->mOtherFound[otherIndex] = 0;
    }
    gWiFiVSMatching->mNoOpponents = FALSE;
    LocateAndQueueWiFiVSMatching();
    oamList = GetWiFiMenuMainOamList();
    ResetOamLists(oamList, GetWiFiMenuSubOamList());
    InitLayoutTable(heap, gWiFiVSMatching->mWiFiVSMatchingBncl, gWiFiVSMatching->mWiFiVSMatchingBnll,
                    &gWiFiVSMatching->mWiFiVSMatchingTable);
    gWiFiVSMatching->mWiFiMessages = FindSceneFile("wifi.bmg");
    gWiFiVSMatching->mCommonMessages = FindFileInLoadedArchives("common.bmg");
    InitWiFiVSMatchingLabels();
    otherIndex = 0;
    offsetTableIndices = &gWiFiVSMatchingOffsetTableIndices[0][0];
    emblemCellIndices = gWiFiVSMatchingEmblemCellIndices;
    nameLabelIndices = gWiFiVSMatchingNameLabelIndices;
    totalLabelIndices = &gWiFiVSMatchingTotalLabelIndices[0][0];
    nameCellIndices = gWiFiVSMatchingNameCellIndices;
    for (; otherIndex < 3; otherIndex++) {
        for (entryIndex = 0; entryIndex < 5; entryIndex++) {
            gWiFiVSMatching->mWiFiVSMatchingTable[offsetTableIndices[entryIndex]].mVisible = 0;
        }
        gWiFiVSMatching->mWiFiVSMatchingTable[*emblemCellIndices].mVisible = 1;
        gWiFiVSMatching->mWiFiVSMatchingTable[*nameLabelIndices + gWiFiVSMatching->mWiFiVSMatchingBncl->mCount]
            .mVisible = 0;
        for (entryIndex = 0; entryIndex < 2; entryIndex++) {
            totalLabelIndex = totalLabelIndices[entryIndex];
            gWiFiVSMatching->mWiFiVSMatchingTable[totalLabelIndex + gWiFiVSMatching->mWiFiVSMatchingBncl->mCount]
                .mVisible = 0;
        }
        gWiFiVSMatching->mWiFiVSMatchingTable[*nameCellIndices].mVisible = 1;
        offsetTableIndices += 5;
        emblemCellIndices++;
        nameLabelIndices++;
        totalLabelIndices += 2;
        nameCellIndices++;
    }
    gWiFiVSMatching->mOffset = 0x100;
    for (otherIndex = 0; otherIndex < 3; otherIndex++) {
        gWiFiVSMatching->mUnk_12[otherIndex] = 0;
        gWiFiVSMatching->mNameSlideOffsets[otherIndex] = 0;
    }
    InitWiFiVSMatchingEntryMatrices();
    if (GetWiFiVSSettingFlag() != 0) {
        SetupTxtSystemMainTextEx(GetBmgEntry(gWiFiVSMatching->mWiFiMessages, 12), 0, 0, 1, 0, 1, 0);
    } else {
        SetupTxtSystemMainTextEx(GetBmgEntry(gWiFiVSMatching->mWiFiMessages, 8), 0, 0, 1, 0, 1, 0);
    }
    gWiFiVSMatching->mBlendFrames = 0;
}

void ReleaseWiFiVSMatching(void) {
    u32 displayPlanes;
    StopBothSeqHandles();
    displayPlanes = (reg_GXS_DB_DISPCNT & REG_GXS_DB_DISPCNT_DISPLAY_MASK) >> 8;
    reg_GXS_DB_DISPCNT = (reg_GXS_DB_DISPCNT & ~REG_GXS_DB_DISPCNT_DISPLAY_MASK) | ((displayPlanes & ~8) << 8);
    reg_G2S_DB_BG3CNT = (reg_G2S_DB_BG3CNT & (REG_G2S_DB_BG3CNT_PRIORITY_MASK | REG_G2S_DB_BG3CNT_MOSAIC_MASK)) | 0xf00;
    gWiFiVSMatching = NULL;
}

void LocateAndQueueWiFiVSMatching(void) {
    Ncgr *chr;
    Nscr *scrn;
    Nclr *pltt;
    vu16 zero;
    u16 paletteColor;
    s32 colorIndex;

    LocateNcgr(&chr, FindSceneFile("WiFi_VS_matching_s_b.ncgr"));
    LocateNscr(&scrn, FindSceneFile("WiFi_VS_matching_s.nscr"));
    LocateNclr(&pltt, FindSceneFile("WiFi_VS_matching_s_b.nclr"));
    gWiFiVSMatching->mWiFiVSMatchingBncl = FindSceneFile("WiFi_VS_matching.bncl");
    gWiFiVSMatching->mWiFiVSMatchingBnbl = FindSceneFile("WiFi_VS_matching.bnbl");
    gWiFiVSMatching->mWiFiVSMatchingBnll = FindSceneFile("WiFi_VS_matching.bnll");
    LocateNcgr2(&gWiFiVSMatching->mWiFiVSMatchingSNcgr, FindSceneFile("WiFi_VS_matching_s.nce.ncgr"));
    LocateNcer(&gWiFiVSMatching->mWiFiVSMatchingSNcer, FindSceneFile("WiFi_VS_matching_s.nce.ncer"));
    LocateNclr(&gWiFiVSMatching->mWiFiVSMatchingSONclr, FindSceneFile("WiFi_VS_matching_s_o.nclr"));
    (reg_G2S_DB_BG3CNT) =
        ((reg_G2S_DB_BG3CNT) & (REG_G2S_DB_BG3CNT_PRIORITY_MASK | REG_G2S_DB_BG3CNT_MOSAIC_MASK)) | 0x4400;
    zero = 0;
    MIi_CpuClear16(zero, gWiFiVSMatching->mNscrCopy, 0x1000);
    MIi_CpuCopy16(scrn->mData, gWiFiVSMatching->mNscrCopy, 0x800);
    NNS_GfdRegisterNewVramTransferTask(0x17, 0, chr->mData, chr->mDataSize);
    NNS_GfdRegisterNewVramTransferTask(0x1b, 0, gWiFiVSMatching->mNscrCopy, 0x1000);
    NNS_GfdRegisterNewVramTransferTask(0x1f, 0, pltt->mData, 0x80);
    NNS_GfdRegisterNewVramTransferTask(0x23, 0, gWiFiVSMatching->mWiFiVSMatchingSNcgr->mData,
                                       gWiFiVSMatching->mWiFiVSMatchingSNcgr->mDataSize);
    NNS_GfdRegisterNewVramTransferTask(0x1e, 0, gWiFiVSMatching->mWiFiVSMatchingSONclr->mData,
                                       gWiFiVSMatching->mWiFiVSMatchingSONclr->mDataSize);
    for (colorIndex = 0; colorIndex < 5; colorIndex++) {
        paletteColor =
            (gWiFiVSMatching->mWiFiVSMatchingSONclr->mData + 0x60 + gWiFiVSMatchingBlendColorOffsets[0])[colorIndex];
        gWiFiVSMatching->mFromChannels[colorIndex][0] = paletteColor & 0x1f;
        gWiFiVSMatching->mFromChannels[colorIndex][1] = (paletteColor & 0x3e0) >> 5;
        gWiFiVSMatching->mFromChannels[colorIndex][2] = (paletteColor & 0x7c00) >> 10;
    }
    for (colorIndex = 0; colorIndex < 5; colorIndex++) {
        paletteColor =
            (gWiFiVSMatching->mWiFiVSMatchingSONclr->mData + 0x60 + gWiFiVSMatchingBlendColorOffsets[1])[colorIndex];
        gWiFiVSMatching->mToChannels[colorIndex][0] = paletteColor & 0x1f;
        gWiFiVSMatching->mToChannels[colorIndex][1] = (paletteColor & 0x3e0) >> 5;
        gWiFiVSMatching->mToChannels[colorIndex][2] = (paletteColor & 0x7c00) >> 10;
    }
}

void PrintWiFiVSMatchingNoOpponents(void) {
    s32 otherIndex;

    for (otherIndex = 0; otherIndex < 3; otherIndex++) {
        if (gWiFiVSMatching->mOtherFound[otherIndex] == 0) {
            PrintLabelLayoutTextNoFixedAdvance(
                1, gWiFiVSMatchingSearchLabelIndices[otherIndex], gWiFiVSMatching->mWiFiVSMatchingBnll,
                GetBmgEntry(gWiFiVSMatching->mWiFiMessages, 10), gWiFiVSMatching->mWiFiVSMatchingBncl,
                gWiFiVSMatching->mWiFiVSMatchingTable);
        }
    }
}

void AdvanceWiFiVSMatchingSlideIn(void) {
    gWiFiVSMatching->mStateFrames = gWiFiVSMatching->mStateFrames + 1;
    gWiFiVSMatching->mStateFrames = gWiFiVSMatching->mStateFrames + 1;
    gWiFiVSMatching->mOffset = InterpolateS16(1, 0x100, 0, gWiFiVSMatching->mStateFrames, 10);
    if (gWiFiVSMatching->mStateFrames >= 10) {
        gWiFiVSMatching->mStateFrames = 10;
    }
    if (gWiFiVSMatching->mStateFrames >= 10) {
        if (IsTxtSystemOpenNoCloseRequest() != 0) {
            gWiFiVSMatching->mNextState = WIFI_VS_MATCHING_STATE_WAIT_MATCHING;
            gWiFiVSMatching->mStateFrames = 0;
            if (GetWiFiVSSettingFlag() != 0) {
                RequestWiFiSessionMatching(gMenuShared->mWiFiVSSettingKartType, 0, 0);
                gWiFiVSMatching->mCheckTimeLimit = FALSE;
            } else {
                RequestWiFiSessionMatching(gMenuShared->mWiFiVSSettingKartType, 1, 0);
                gWiFiVSMatching->mCheckTimeLimit = TRUE;
            }
            StartWiFiSessionMatchingSeq();
        }
    }
}

void AdvanceWiFiVSMatchingWaitMatching(void) {
    InputSlotIndex slotIndex = INPUT_SLOT_PAD_OR_PARTICIPANT;
    BOOL pairNewUnlessRecentlyLost;
    BOOL pairRecentlyLost;
    u16 hasPair;
    u32 secondTotal;
    s32 playerIndex;
    s32 sh;
    s32 otherCount;
    s32 otherIndex;
    BOOL blinkOn;
    u16 nameText[11];
    u16 firstTotalText[10];
    u16 secondTotalText[10];
    u8 *emblemDestination;
    s32 otherSlot;

    if (gWiFiVSMatching->mStateFrames >= 0x78) {
        gWiFiVSMatching->mStateFrames = 0x78;
    }
    gWiFiVSMatching->mStateFrames = gWiFiVSMatching->mStateFrames + 1;
    if (IsWiFiSessionMatchingActive() != FALSE) {
        RequestSelectReturnSlideIn();
    } else {
        RequestSelectReturnSlideOut();
    }
    if (gWiFiVSMatching->mCheckTimeLimit != FALSE) {
        if (IsWiFiMatchingBeforeTimeLimit() == FALSE) {
            gWiFiVSMatching->mCheckTimeLimit = FALSE;
            SetupTxtSystemMainTextEx(GetBmgEntry(gWiFiVSMatching->mWiFiMessages, 12), 0, 0, 1, 0, 1, 0);
        }
    }
    if (IsTxtSystemOpenNoCloseRequest() != 0 && IsSelectReturnShownNoRequest() != 0 &&
        (u16) (gInputSlots[slotIndex].mPressedBits & PAD_KEY_B) != 0) {
        goto hit;
    }
    pairNewUnlessRecentlyLost = FALSE;
    pairRecentlyLost = FALSE;
    hasPair = gInputSlots[slotIndex].mPair.mHasPair;
    if (hasPair == 0 && gInputSlots[slotIndex].mPair.mNoPairCount < 5) {
        pairRecentlyLost = TRUE;
    }
    if (pairRecentlyLost == FALSE && gInputSlots[slotIndex].mPair.mPrevHasPair == 0 && hasPair != 0) {
        pairNewUnlessRecentlyLost = TRUE;
    }
    if (pairNewUnlessRecentlyLost != FALSE &&
        IsSelectReturnShownNoRequestAndInRect(gInputSlots[slotIndex].mPair.mPairX,
                                              gInputSlots[slotIndex].mPair.mPairY) != FALSE &&
        IsWiFiSessionMatchingActive() != FALSE) {
    hit:
        StopWiFiSessionMatching();
        RequestSelectReturnPressWithSound(0);
        gWiFiVSMatching->mNextState = WIFI_VS_MATCHING_STATE_SLIDE_OUT;
        gWiFiVSMatching->mPendingWiFiState = WIFI_STATE_VS_SETTING;
        gWiFiVSMatching->mStateFrames = 0;
        RequestTxtSystemClose();
        StopBothSeqHandles();
        return;
    }
    if (IsTxtSystemOpenNoCloseRequest() != 0 && gWiFiVSMatching->mStateFrames >= 0x78 &&
        CheckWiFiMatchingResult() == -1) {
        PrintWiFiVSMatchingNoOpponents();
        gWiFiVSMatching->mNextState = WIFI_VS_MATCHING_STATE_WAIT_NO_OPPONENTS_BACK;
        gWiFiVSMatching->mNoOpponents = TRUE;
        gWiFiVSMatching->mStateFrames = 0;
        for (otherIndex = 0; otherIndex < 3; otherIndex++) {
            gWiFiVSMatching->mWiFiVSMatchingTable[gWiFiVSMatchingOtherCellIndices[otherIndex]].mVisible = 0;
        }
        RequestTxtSystemClose();
        RequestSelectReturnSlideIn();
        StartSelectReturnState1Seq();
        return;
    }
    if (IsTxtSystemOpenNoCloseRequest() != 0 && CheckWiFiMatchingResult() == 1) {
        otherSlot = 0;
        gWiFiVSMatching->mStateFrames = 0;
        if (gWiFiSession->mKartCount <= 1) {
            PrintWiFiVSMatchingNoOpponents();
            gWiFiVSMatching->mNextState = WIFI_VS_MATCHING_STATE_WAIT_NO_OPPONENTS_BACK;
            gWiFiVSMatching->mNoOpponents = TRUE;
            for (otherIndex = 0; otherIndex < 3; otherIndex++) {
                gWiFiVSMatching->mWiFiVSMatchingTable[gWiFiVSMatchingOtherCellIndices[otherIndex]].mVisible = 0;
            }
            RequestTxtSystemClose();
            RequestSelectReturnSlideIn();
            StartSelectReturnState1Seq();
            return;
        }
        gWiFiVSMatching->mOtherCount = gWiFiSession->mKartCount - 1;
        for (playerIndex = 0; playerIndex < gWiFiSession->mKartCount; playerIndex++) {
            if (playerIndex != DWC_GetMyAID()) {
                gWiFiVSMatching->mOtherIndices[otherSlot] = playerIndex;
                gWiFiVSMatching->mOtherFound[otherSlot] = 1;
                otherSlot++;
            }
        }
        for (otherIndex = 0; otherIndex < gWiFiVSMatching->mOtherCount; otherIndex++) {
            MIi_CpuCopy16(GetPlayerRecordName(gWiFiVSMatching->mOtherIndices[otherIndex]), nameText, 0x14);
            nameText[10] = 0;
            PrintLabelLayoutTextNoFixedAdvance(
                1, gWiFiVSMatchingNameLabelIndices[otherIndex], gWiFiVSMatching->mWiFiVSMatchingBnll, nameText,
                gWiFiVSMatching->mWiFiVSMatchingBncl, gWiFiVSMatching->mWiFiVSMatchingTable);
            secondTotal = GetPlayerRecordSecondTotal(gWiFiVSMatching->mOtherIndices[otherIndex]);
            if (secondTotal > 9999) {
                secondTotal = 9999;
            }
            FormatAsciiNumber(GetPlayerRecordFirstTotal(gWiFiVSMatching->mOtherIndices[otherIndex]), firstTotalText);
            FormatAsciiNumber(secondTotal, secondTotalText);
            PrintLabelLayoutTextNoFixedAdvance(
                1, gWiFiVSMatchingTotalLabelIndices[otherIndex][0], gWiFiVSMatching->mWiFiVSMatchingBnll,
                firstTotalText, gWiFiVSMatching->mWiFiVSMatchingBncl, gWiFiVSMatching->mWiFiVSMatchingTable);
            PrintLabelLayoutTextNoFixedAdvance(
                1, gWiFiVSMatchingTotalLabelIndices[otherIndex][1], gWiFiVSMatching->mWiFiVSMatchingBnll,
                secondTotalText, gWiFiVSMatching->mWiFiVSMatchingBncl, gWiFiVSMatching->mWiFiVSMatchingTable);
            emblemDestination = gWiFiVSMatching->mOtherEmblems[0];
            emblemDestination += otherIndex * 0x200;
            CopyBytesIntoTiles(GetPlayerRecordEmblem(gWiFiVSMatching->mOtherIndices[otherIndex]), emblemDestination,
                               0x20);
            gWiFiVSMatching->mOtherHasEmblem[otherIndex] =
                HasPlayerRecordEmblem(gWiFiVSMatching->mOtherIndices[otherIndex]);
        }
        for (otherIndex = 0; otherIndex < 3; otherIndex++) {
            gWiFiVSMatching->mWiFiVSMatchingTable[gWiFiVSMatchingOtherCellIndices[otherIndex]].mVisible = 0;
        }
        for (otherIndex = 0; otherIndex < gWiFiVSMatching->mOtherCount; otherIndex++) {
            gWiFiVSMatching->mWiFiVSMatchingTable[gWiFiVSMatchingOtherCellIndices[otherIndex]].mVisible = 1;
        }
        gWiFiVSMatching->mNextState = WIFI_VS_MATCHING_STATE_EMBLEM_SCALE_IN;
        RequestSelectReturnSlideOut();
        RequestTxtSystemClose();
        RequestPlayerEntryListSetup();
        StartPlayerEntryListSetupSeq();
        gWiFiVSMatching->mCurrentOtherIndex = 0;
        return;
    }
    otherCount = GetWiFiMatchingParticipantCount() - 1;
    blinkOn = FALSE;
    if (otherCount > 3) {
        otherCount = 3;
    }
    gWiFiVSMatching->mBlinkFrames = gWiFiVSMatching->mBlinkFrames + 1;
    if (gWiFiVSMatching->mBlinkFrames >= 0x50) {
        gWiFiVSMatching->mBlinkFrames = 0;
    }
    if (otherCount > 0) {
        sh = 0x50 >> (otherCount - 1);
        if (gWiFiVSMatching->mBlinkFrames % sh >= sh / 2) {
            blinkOn = TRUE;
        }
    }
    for (otherIndex = 0; otherIndex < 3; otherIndex++) {
        if (otherIndex < otherCount && blinkOn != FALSE) {
            gWiFiVSMatching->mWiFiVSMatchingTable[gWiFiVSMatchingOtherCellIndices[otherIndex]].mVisible = 1;
            if (otherIndex >= gWiFiVSMatching->mShownEntryCount) {
                StartWiFiMatchingEntryShowSeq();
                gWiFiVSMatching->mShownEntryCount = gWiFiVSMatching->mShownEntryCount + 1;
            }
        } else {
            gWiFiVSMatching->mWiFiVSMatchingTable[gWiFiVSMatchingOtherCellIndices[otherIndex]].mVisible = 0;
        }
    }
    sh = gWiFiVSMatching->mShownEntryCount;
    while (otherCount < gWiFiVSMatching->mShownEntryCount) {
        StartWiFiMatchingEntryHideSeq();
        sh--;
        otherCount++;
    }
    gWiFiVSMatching->mShownEntryCount = sh;
}

void AdvanceWiFiVSMatchingEmblemScaleIn(void) {
    s32 frame = gWiFiVSMatching->mStateFrames;
    u16 angle = (frame << 16) / 0x14;
    s32 scale = ((0x13 - frame) * 0xf33) / 0x14 + 0xcd;
    s32 otherIndex;
    Nclr *emblemSBNclr;

    for (otherIndex = 0; otherIndex < 3; otherIndex++) {
        SetLayoutEntryAngleAndScale(
            &gWiFiVSMatching->mWiFiVSMatchingTable[gWiFiVSMatchingEmblemCellIndices[otherIndex]], angle, scale);
    }
    gWiFiVSMatching->mStateFrames = gWiFiVSMatching->mStateFrames + 1;
    if (gWiFiVSMatching->mStateFrames >= 0x14) {
        if (IsTxtSystemClosedNoOpenRequest() != 0) {
            emblemSBNclr = GetEmblemSBNclr();
            for (otherIndex = 0; otherIndex < 3; otherIndex++) {
                gWiFiVSMatching->mWiFiVSMatchingTable[gWiFiVSMatchingEmblemCellIndices[otherIndex]].mVisible = 0;
            }
            PrintWiFiVSMatchingNoOpponents();
            for (otherIndex = 0; otherIndex < gWiFiVSMatching->mOtherCount; otherIndex++) {
                if (gWiFiVSMatching->mOtherHasEmblem[otherIndex] != 0) {
                    NNS_GfdRegisterNewVramTransferTask(0x23,
                                                       GetCellCharIndex(gWiFiVSMatchingEmblemCellIndices[otherIndex],
                                                                        gWiFiVSMatching->mWiFiVSMatchingSNcer,
                                                                        gWiFiVSMatching->mWiFiVSMatchingBncl)
                                                           << 5,
                                                       gWiFiVSMatching->mOtherEmblems[otherIndex], 0x200);
                    NNS_GfdRegisterNewVramTransferTask(0x1e, (otherIndex + 3) << 5, emblemSBNclr->mData, 0x20);
                }
                gWiFiVSMatching
                    ->mWiFiVSMatchingTable[gWiFiVSMatchingSearchLabelIndices[otherIndex] +
                                           gWiFiVSMatching->mWiFiVSMatchingBncl->mCount]
                    .mVisible = 0;
            }
            SetupTxtSystemMainTextEx(GetBmgEntry(gWiFiVSMatching->mWiFiMessages, 11), 0, 0, 1, 0, 0, 0);
            gWiFiVSMatching->mNextState = WIFI_VS_MATCHING_STATE_WAIT_PLAYER_LIST_TEXT;
            gWiFiVSMatching->mStateFrames = 0;
        }
    }
}

void AdvanceWiFiVSMatchingWaitPlayerListText(void) {
    gWiFiVSMatching->mStateFrames = gWiFiVSMatching->mStateFrames + 1;
    if (gWiFiVSMatching->mStateFrames >= 0x28) {
        gWiFiVSMatching->mNextState = WIFI_VS_MATCHING_STATE_SCALE_IN_OTHER;
        gWiFiVSMatching->mStateFrames = 0;
        NNS_SndArcPlayerStartSeqArc(&gSharedSeqHandle, 0, 0x20b);
    }
}

u8 gWiFiVSMatchingTotalScalePercents[30] = {
    0x0a, 0x14, 0x1e, 0x28, 0x32, 0x3c, 0x46, 0x50, 0x5a, 0x64, 0x6e, 0x78, 0x82, 0x82, 0x82,
    0x78, 0x6e, 0x64, 0x5a, 0x5a, 0x64, 0x6e, 0x78, 0x78, 0x78, 0x6e, 0x64, 0x64, 0x64, 0x64,
};

u8 gWiFiVSMatchingEmblemScalePercents[40] = {
    0x0a, 0x14, 0x1e, 0x28, 0x32, 0x3c, 0x46, 0x50, 0x5a, 0x64, 0x6e, 0x78, 0x82, 0x8c,
    0x96, 0x96, 0x96, 0x96, 0x96, 0x96, 0x96, 0x96, 0x96, 0x96, 0x96, 0x91, 0x8c, 0x87,
    0x82, 0x7d, 0x78, 0x73, 0x6e, 0x69, 0x64, 0x64, 0x64, 0x64, 0x64, 0x64,
};

void AdvanceWiFiVSMatchingScaleInOther(void) {
    s32 frame;
    s32 totalFrame;
    s32 emblemFrame;
    s32 otherSlot;
    s32 totalScale;
    s32 emblemScale;
    u32 cellCount;
    u16 emblemAngle;
    s32 totalIndex;
    u32 emblemEntryOffset;

    frame = gWiFiVSMatching->mStateFrames;
    totalFrame = frame;
    emblemFrame = frame;
    otherSlot = gWiFiVSMatching->mCurrentOtherIndex;
    cellCount = gWiFiVSMatching->mWiFiVSMatchingBncl->mCount;
    if (frame >= 0x1e) {
        totalFrame = 0x1d;
    }
    if (frame >= 0x28) {
        emblemFrame = 0x27;
    }
    totalScale = TO_FIXED12(gWiFiVSMatchingTotalScalePercents[totalFrame]) / 100;
    emblemScale = TO_FIXED12(gWiFiVSMatchingEmblemScalePercents[emblemFrame]) / 100;
    if (frame < 0x20) {
        emblemAngle = (emblemFrame << 17) / 0x20;
    } else {
        emblemAngle = 0;
    }
    gWiFiVSMatching->mWiFiVSMatchingTable[cellCount + gWiFiVSMatchingNameLabelIndices[otherSlot]].mVisible = 1;
    for (totalIndex = 0; totalIndex < 2; totalIndex++) {
        gWiFiVSMatching->mWiFiVSMatchingTable[(&gWiFiVSMatchingTotalCellIndices[0][0] + otherSlot * 2)[totalIndex]]
            .mVisible = 1;
        gWiFiVSMatching
            ->mWiFiVSMatchingTable[cellCount + (&gWiFiVSMatchingTotalLabelIndices[0][0] + otherSlot * 2)[totalIndex]]
            .mVisible = 1;
    }
    emblemEntryOffset = gWiFiVSMatchingEmblemCellIndices[otherSlot] << 6;
    ((LayoutTableEntry *) ((u32) gWiFiVSMatching->mWiFiVSMatchingTable + emblemEntryOffset))->mVisible = 1;
    *OFFSET_PTR(s16, gWiFiVSMatching->mNameSlideOffsets, otherSlot * 2) = gWiFiVSMatchingNameSlideOffsets[totalFrame];
    for (totalIndex = 0; totalIndex < 2; totalIndex++) {
        SetLayoutEntryAngleAndScale(
            &gWiFiVSMatching
                 ->mWiFiVSMatchingTable[(&gWiFiVSMatchingTotalCellIndices[0][0] + otherSlot * 2)[totalIndex]],
            0, totalScale);
    }
    SetLayoutEntryAngleAndScale((LayoutTableEntry *) ((u32) gWiFiVSMatching->mWiFiVSMatchingTable + emblemEntryOffset),
                                emblemAngle, emblemScale);
    gWiFiVSMatching->mStateFrames = gWiFiVSMatching->mStateFrames + 1;
    if (gWiFiVSMatching->mStateFrames >= 0x1e && gWiFiVSMatching->mStateFrames >= 0x28) {
        gWiFiVSMatching->mStateFrames = 0;
        if (gWiFiVSMatching->mCurrentOtherIndex == gWiFiVSMatching->mOtherCount - 1) {
            gWiFiVSMatching->mNextState = WIFI_VS_MATCHING_STATE_WAIT_RESULT_SHOWN;
            return;
        }
        gWiFiVSMatching->mCurrentOtherIndex = gWiFiVSMatching->mCurrentOtherIndex + 1;
        gWiFiVSMatching->mNextState = WIFI_VS_MATCHING_STATE_PAUSE_BETWEEN_OTHERS;
    }
}

void AdvanceWiFiVSMatchingPauseBetweenOthers(void) {
    gWiFiVSMatching->mStateFrames = gWiFiVSMatching->mStateFrames + 1;
    if (gWiFiVSMatching->mStateFrames >= 0x50) {
        gWiFiVSMatching->mNextState = WIFI_VS_MATCHING_STATE_SCALE_IN_OTHER;
        gWiFiVSMatching->mStateFrames = 0;
        NNS_SndArcPlayerStartSeqArc(&gSharedSeqHandle, 0, 0x20b);
    }
}

void AdvanceWiFiVSMatchingWaitResultShown(void) {
    gWiFiVSMatching->mStateFrames = gWiFiVSMatching->mStateFrames + 1;
    // mUnk_30 is 1 to 3 here and indexes the table from 1.
    if (gWiFiVSMatching->mStateFrames >= (gWiFiVSMatchingResultWaitFrames - 1)[gWiFiVSMatching->mOtherCount]) {
        if (IsSelectReturnHiddenNoRequest() != 0) {
            gWiFiVSMatching->mNextState = WIFI_VS_MATCHING_STATE_WAIT_FADE_OUT;
            gWiFiVSMatching->mPendingWiFiState = WIFI_STATE_SELECT_CHARACTER;
            gWiFiVSMatching->mStateFrames = 0;
            RequestTxtSystemClose();
            StartFadeToFadedNegative(30);
            NNS_SndArcPlayerStartSeqArc(&gSharedSeqHandle, 0, 0x20c);
        }
    }
}

void AdvanceWiFiVSMatchingWaitNoOpponentsBack(void) {
    BOOL pairNewUnlessRecentlyLost;
    BOOL pairRecentlyLost;
    u16 hasPair;
    InputSlotIndex slotIndex = INPUT_SLOT_PAD_OR_PARTICIPANT;

    if (IsTxtSystemClosedNoOpenRequest() != 0) {
        SetupTxtSystemMainTextEx(GetBmgEntry(gWiFiVSMatching->mWiFiMessages, 13), 0, 0, 1, 0, 0, 0);
    }
    if (IsTxtSystemOpenNoCloseRequest() != 0) {
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
            if (pairNewUnlessRecentlyLost == FALSE) {
                return;
            }
            if (IsSelectReturnShownNoRequestAndInRect(gInputSlots[slotIndex].mPair.mPairX,
                                                      gInputSlots[slotIndex].mPair.mPairY) == FALSE) {
                return;
            }
        }
        gWiFiVSMatching->mNextState = WIFI_VS_MATCHING_STATE_SLIDE_OUT;
        gWiFiVSMatching->mPendingWiFiState = WIFI_STATE_VS_SETTING;
        RequestSelectReturnPressWithSound(0);
        RequestTxtSystemClose();
    }
}

void AdvanceWiFiVSMatchingSlideOut(void) {
    gWiFiVSMatching->mStateFrames = gWiFiVSMatching->mStateFrames + 1;
    gWiFiVSMatching->mOffset = InterpolateS16(1, 0, 0x100, gWiFiVSMatching->mStateFrames, 10);
    if (gWiFiVSMatching->mStateFrames >= 10) {
        gWiFiVSMatching->mStateFrames = 10;
    }
    if (IsTxtSystemClosedNoOpenRequest() != 0 && IsSelectReturnShownNoRequest() != 0 &&
        gWiFiVSMatching->mStateFrames >= 10) {
        if (gWiFiVSMatching->mNoOpponents != FALSE) {
            RequestWiFiState(gWiFiVSMatching->mPendingWiFiState);
            return;
        }
        if (IsKartKeysStartStatus2() != FALSE) {
            RequestWiFiState(gWiFiVSMatching->mPendingWiFiState);
        }
    }
}

void AdvanceWiFiVSMatchingWaitFadeOut(void) {
    if (AreBrightnessFadesFaded() != 0) {
        if (IsTxtSystemClosedNoOpenRequest() != 0) {
            RequestWiFiState(gWiFiVSMatching->mPendingWiFiState);
        }
    }
}

void UpdateWiFiVSMatchingOffsets(void) {
    s32 otherIndex;
    u32 cellCount = gWiFiVSMatching->mWiFiVSMatchingBncl->mCount;
    s32 entryIndex;

    for (otherIndex = 0; otherIndex < 3; otherIndex++) {
        for (entryIndex = 0; entryIndex < 5; entryIndex++) {
            gWiFiVSMatching->mWiFiVSMatchingTable[gWiFiVSMatchingOffsetTableIndices[otherIndex][entryIndex]].mOffsetX =
                gWiFiVSMatching->mOffset;
        }
    }
    for (otherIndex = 0; otherIndex < 3; otherIndex++) {
        (gWiFiVSMatching->mWiFiVSMatchingTable + cellCount)[gWiFiVSMatchingNameLabelIndices[otherIndex]].mOffsetX =
            gWiFiVSMatching->mOffset + gWiFiVSMatching->mNameSlideOffsets[otherIndex];
        (gWiFiVSMatching->mWiFiVSMatchingTable + cellCount)[gWiFiVSMatchingSearchLabelIndices[otherIndex]].mOffsetX =
            gWiFiVSMatching->mOffset;
        for (entryIndex = 0; entryIndex < 2; entryIndex++) {
            (gWiFiVSMatching->mWiFiVSMatchingTable +
             cellCount)[gWiFiVSMatchingTotalLabelIndices[otherIndex][entryIndex]]
                .mOffsetX = gWiFiVSMatching->mOffset - gWiFiVSMatching->mNameSlideOffsets[otherIndex];
        }
    }
    (gWiFiVSMatching->mWiFiVSMatchingTable + cellCount)[12].mOffsetX = gWiFiVSMatching->mOffset;
}

void SetWiFiVSMatchingBlendedColors(s32 weight) {
    s32 colorIndex;

    for (colorIndex = 0; colorIndex < 5; colorIndex++) {
        WiFiVSMatching *wiFiVSMatching = gWiFiVSMatching;

        wiFiVSMatching->mBlendedColors[colorIndex] =
            ((((0x1000 - weight) * wiFiVSMatching->mFromChannels[colorIndex][2] +
               weight * wiFiVSMatching->mToChannels[colorIndex][2]) >>
              12)
             << 10) |
            ((((0x1000 - weight) * wiFiVSMatching->mFromChannels[colorIndex][0] +
               weight * wiFiVSMatching->mToChannels[colorIndex][0]) >>
              12) |
             ((((0x1000 - weight) * wiFiVSMatching->mFromChannels[colorIndex][1] +
                weight * wiFiVSMatching->mToChannels[colorIndex][1]) >>
               12)
              << 5));
    }
    NNS_GfdRegisterNewVramTransferTask(0x1e, 0x36, gWiFiVSMatching->mBlendedColors, 10);
}

void UpdateWiFiVSMatchingPaletteBlend(void) {
    s32 blendFrame;

    if (gWiFiVSMatching->mState == WIFI_VS_MATCHING_STATE_WAIT_RESULT_SHOWN ||
        gWiFiVSMatching->mState == WIFI_VS_MATCHING_STATE_WAIT_FADE_OUT) {
        gWiFiVSMatching->mBlendFrames = gWiFiVSMatching->mBlendFrames + 1;
        if (gWiFiVSMatching->mBlendFrames >= 0x3c) {
            gWiFiVSMatching->mBlendFrames = 0;
        }
        blendFrame = gWiFiVSMatching->mBlendFrames;
        if (blendFrame < 0x14) {
            SetWiFiVSMatchingBlendedColors(TO_FIXED12(blendFrame) / 0x14);
            return;
        }
        if (blendFrame < 0x28) {
            SetWiFiVSMatchingBlendedColors(TO_FIXED12(0x28 - blendFrame) / 0x14);
            return;
        }
        SetWiFiVSMatchingBlendedColors(0);
    }
}

void AdvanceWiFiVSMatching(void) {
    gWiFiVSMatching->mState = gWiFiVSMatching->mNextState;
    switch (gWiFiVSMatching->mState) {
        case WIFI_VS_MATCHING_STATE_SLIDE_IN:
            AdvanceWiFiVSMatchingSlideIn();
            break;
        case WIFI_VS_MATCHING_STATE_WAIT_MATCHING:
            AdvanceWiFiVSMatchingWaitMatching();
            break;
        case WIFI_VS_MATCHING_STATE_EMBLEM_SCALE_IN:
            AdvanceWiFiVSMatchingEmblemScaleIn();
            break;
        case WIFI_VS_MATCHING_STATE_WAIT_PLAYER_LIST_TEXT:
            AdvanceWiFiVSMatchingWaitPlayerListText();
            break;
        case WIFI_VS_MATCHING_STATE_SCALE_IN_OTHER:
            AdvanceWiFiVSMatchingScaleInOther();
            break;
        case WIFI_VS_MATCHING_STATE_PAUSE_BETWEEN_OTHERS:
            AdvanceWiFiVSMatchingPauseBetweenOthers();
            break;
        case WIFI_VS_MATCHING_STATE_WAIT_RESULT_SHOWN:
            AdvanceWiFiVSMatchingWaitResultShown();
            break;
        case WIFI_VS_MATCHING_STATE_WAIT_NO_OPPONENTS_BACK:
            AdvanceWiFiVSMatchingWaitNoOpponentsBack();
            break;
        case WIFI_VS_MATCHING_STATE_SLIDE_OUT:
            AdvanceWiFiVSMatchingSlideOut();
            break;
        case WIFI_VS_MATCHING_STATE_WAIT_FADE_OUT:
            AdvanceWiFiVSMatchingWaitFadeOut();
            break;
    }
    UpdateWiFiVSMatchingOffsets();
    UpdateWiFiVSMatchingPaletteBlend();
    DrawLayoutTable(gWiFiVSMatching->mWiFiVSMatchingBncl, gWiFiVSMatching->mWiFiVSMatchingSNcer,
                    gWiFiVSMatching->mWiFiVSMatchingBnll, GetWiFiMenuSubOamList(),
                    gWiFiVSMatching->mWiFiVSMatchingTable);
}

void WriteWiFiVSMatchingRegisters(void) {
    s32 bgOffset;
    u32 displayPlanes;

    displayPlanes = ((reg_GXS_DB_DISPCNT) & REG_GXS_DB_DISPCNT_DISPLAY_MASK) >> 8;
    (reg_GXS_DB_DISPCNT) = ((reg_GXS_DB_DISPCNT) & ~REG_GXS_DB_DISPCNT_DISPLAY_MASK) | ((displayPlanes | 8) << 8);
    bgOffset = -gWiFiVSMatching->mOffset;
    if (bgOffset <= -0x100) {
        bgOffset = -0x100;
    }
    if (bgOffset >= 0x100) {
        bgOffset = 0x100;
    }
    (reg_G2S_DB_BG3OFS) = bgOffset & 0x1ff;
}

void RegisterWiFiVSMatchingCallbacks(void) {
    WiFiStateCallbacks callbacks = {InitWiFiVSMatching, ReleaseWiFiVSMatching, AdvanceWiFiVSMatching,
                                    WriteWiFiVSMatchingRegisters};

    SetWiFiStateCallbacks(&callbacks);
}
