#include "00/Menu/wi_fi_vs_setting.h"

#include "00/Scene/wi_fi_menu_scene.h"
#include "Main/Graphics/font_glyph_text.h"
#include "Main/Graphics/layout_entry_angle.h"
#include "Main/Graphics/layout_table_entry.h"
#include "Main/Graphics/palette_blend.h"
#include "g2.h"
#include "01/Menu/record_time_attack.h"
#include "00/unk_021b4000.h"
#include "Main/Menu/txt_system.h"
#include "Main/Menu/select_return.h"
#include "Main/Graphics/oam.h"
#include "code_0212df7c.h"
#include "Main/Graphics/layout_rect_table.h"
#include "Main/Graphics/locate_bmg_sections.h"
#include "Main/Sound/sound_seq.h"
#include "Main/Menu/data_02175628.h"
#include "Main/Menu/data_0217d000.h"
#include "player.h"
#include "code_0212c7a0.h"
#include "stream.h"
#include "code_0212c9d4.h"
#include "Main/Race/race_hud_sub_screen_cells.h"
#include "code_0212d214.h"
#include "Main/Item/item_pool.h"
#include "00/code_02180608.h"
#include "Main/Scene/display_settings.h"
#include "Main/Net/wifi_connection_lost.h"
#include "Main/Net/wifi_session_karts.h"
#include "Main/Net/wifi_session_login.h"
#include "code_02148950.h"
#include "registers.h"
#include "Main/System/heap.h"
#include "Main/Menu/data_0217d068.h"

BOOL HasBuddyRecords(void) {
    if (CountEmblemEntries() != 0) {
        return TRUE;
    }
    return FALSE;
}

void InitWiFiVSSetting(void *heap) {
    s32 i;

    gWiFiVSSetting = HeapAlloc(heap, 0x1060);
    gWiFiVSSetting->mHeap = heap;
    gWiFiVSSetting->mState = 0;
    gWiFiVSSetting->mNextState = 0;
    gWiFiVSSetting->mRow = 1;
    gWiFiVSSetting->mPendingWiFiState = -1;
    gWiFiVSSetting->mStateFrames = 0;
    gWiFiVSSetting->mHighlightVisible = TRUE;
    SetWiFiVSSettingFlag(0);
    LocateAndQueueWiFiVSSetting();
    InitPaletteBlend(heap, gWiFiVSSetting->mWiFiVSSettingSONclr, 3);
    for (i = 0; i < 2; i++) {
        SetCellOamModeXlu(gWiFiVSSettingOffsetTableIndices[i][0], 1, gWiFiVSSetting->mWiFiVSSettingSNcer,
                          gWiFiVSSetting->mWiFiVSSettingBncl);
    }
    ResetOamLists(GetWiFiMenuMainOamList(), GetWiFiMenuSubOamList());
    InitLayoutTable(heap, gWiFiVSSetting->mWiFiVSSettingBncl, gWiFiVSSetting->mWiFiVSSettingBnll,
                    &gWiFiVSSetting->mWiFiVSSettingTable);
    gWiFiVSSetting->mWiFiMessages = FindSceneFile("wifi.bmg");
    gWiFiVSSetting->mCommonMessages = FindFileInLoadedArchives("common.bmg");
    {
        s32 subObjSizeLeft = GX_GetSizeOfSubOBJ();
        u8 headerLabelIndices[1] = {1};
        u8 headerLabelSizes[1][2] = {{0xc8, 0x10}};
        u32 headerMessageIndices[1] = {1};

        for (i = 0; i < 1; i++) {
            subObjSizeLeft -= InitLabelCanvas(
                heap, headerLabelIndices[i], gWiFiVSSetting->mWiFiVSSettingBnll, headerLabelSizes[i][0],
                headerLabelSizes[i][1], gWiFiVSSettingOffsetTableIndices[i][11], gWiFiVSSetting->mWiFiVSSettingSNcer,
                gWiFiVSSetting->mWiFiVSSettingBncl, gWiFiVSSetting->mWiFiVSSettingTable, subObjSizeLeft);
            PrintLabelLayoutTextNoFixedAdvance(1, headerLabelIndices[i], gWiFiVSSetting->mWiFiVSSettingBnll,
                                               GetBmgEntry(gWiFiVSSetting->mWiFiMessages, headerMessageIndices[i]),
                                               gWiFiVSSetting->mWiFiVSSettingBncl, gWiFiVSSetting->mWiFiVSSettingTable);
        }
        {
            u8 labelSizes[3][2] = {{0x80, 0x10}, {0xa0, 0x10}, {0x32, 0x10}};
            s32 messageColumn;
            void *bmgEntry;

            for (i = 0; i < 3; i++) {
                messageColumn = 0;
                if (i == 1) {
                    gWiFiVSSetting->mSettingIndex = gWiFiVSSettingIndexByKartType[gMenuShared->mWiFiVSSettingKartType];
                    if (gWiFiVSSetting->mSettingIndex == 0 && !HasBuddyRecords()) {
                        gWiFiVSSetting->mSettingIndex = 2;
                    }
                    messageColumn = gWiFiVSSetting->mSettingIndex;
                }
                subObjSizeLeft -= InitLabelCanvas(
                    heap, gWiFiVSSettingLabelIndices[i], gWiFiVSSetting->mWiFiVSSettingBnll, labelSizes[i][0],
                    labelSizes[i][1], gWiFiVSSettingOffsetTableIndices[i][1], gWiFiVSSetting->mWiFiVSSettingSNcer,
                    gWiFiVSSetting->mWiFiVSSettingBncl, gWiFiVSSetting->mWiFiVSSettingTable, subObjSizeLeft);
                if (i == 2) {
                    bmgEntry =
                        GetBmgEntry(gWiFiVSSetting->mCommonMessages, gWiFiVSSettingMessageIndices[i][messageColumn]);
                } else if (i == 1) {
                    bmgEntry = GetBmgEntry(gWiFiVSSetting->mWiFiMessages,
                                           LookupWiFiVSSettingMessageIndex(gWiFiVSSetting->mSettingIndex));
                } else {
                    bmgEntry =
                        GetBmgEntry(gWiFiVSSetting->mWiFiMessages, gWiFiVSSettingMessageIndices[i][messageColumn]);
                }
                PrintLabelLayoutTextNoFixedAdvance(1, gWiFiVSSettingLabelIndices[i], gWiFiVSSetting->mWiFiVSSettingBnll,
                                                   bmgEntry, gWiFiVSSetting->mWiFiVSSettingBncl,
                                                   gWiFiVSSetting->mWiFiVSSettingTable);
            }
        }
    }
    for (i = 0; i < 3; i++) {
        if (i == 2) {
            gWiFiVSSetting->mRowOffsets[i][0] = 0;
            gWiFiVSSetting->mRowOffsets[i][1] = 0x28;
        } else if (i == 1) {
            gWiFiVSSetting->mRowOffsets[i][0] = -0x100;
            gWiFiVSSetting->mRowOffsets[i][1] = 0;
        } else {
            gWiFiVSSetting->mRowOffsets[i][0] = 0x100;
            gWiFiVSSetting->mRowOffsets[i][1] = 0;
        }
    }
    gWiFiVSSetting->mIndexDecrementTimer = 0;
    gWiFiVSSetting->mIndexIncrementTimer = 0;
    SetLinkLevelIconEnabled(1, 1);
    SetSelectReturnSoundId(0xe);
}

void ReleaseWiFiVSSetting(void) {
    u32 a;

    a = (reg_GXS_DB_DISPCNT & 0x1f00) >> 8;
    a &= ~8;
    reg_GXS_DB_DISPCNT = (reg_GXS_DB_DISPCNT & 0xffffe0ff) | (a << 8);
    reg_G2S_DB_BG3CNT = (reg_G2S_DB_BG3CNT & 0x43) | 0xf00;
    ClearPaletteBlendPointer();
    gWiFiVSSetting = NULL;
}

void LocateAndQueueWiFiVSSetting(void) {
    Ncgr *chr;
    Nscr *scrn;
    Nclr *pltt;
    vu16 zero;

    LocateNcgr(&chr, FindSceneFile("WiFi_VS_setting_s_b.ncgr"));
    LocateNscr(&scrn, FindSceneFile("WiFi_VS_s_setting.nscr"));
    LocateNclr(&pltt, FindSceneFile("WiFi_VS_setting_s_b.nclr"));
    gWiFiVSSetting->mWiFiVSSettingBncl = FindSceneFile("WiFi_VS_setting.bncl");
    gWiFiVSSetting->mWiFiVSSettingBnbl = FindSceneFile("WiFi_VS_setting.bnbl");
    gWiFiVSSetting->mWiFiVSSettingBnll = FindSceneFile("WiFi_VS_setting.bnll");
    LocateNcgr2(&gWiFiVSSetting->mWiFiVSSettingSNcgr, FindSceneFile("WiFi_VS_setting_s.nce.ncgr"));
    LocateNcer(&gWiFiVSSetting->mWiFiVSSettingSNcer, FindSceneFile("WiFi_VS_setting_s.nce.ncer"));
    LocateNclr(&gWiFiVSSetting->mWiFiVSSettingSONclr, FindSceneFile("WiFi_VS_setting_s_o.nclr"));
    reg_G2S_DB_BG3CNT = (reg_G2S_DB_BG3CNT & 0x43) | 0x4400;
    zero = 0;
    MIi_CpuClear16(zero, gWiFiVSSetting->mNscrCopy, 0x1000);
    MIi_CpuCopy16(scrn->mData, gWiFiVSSetting->mNscrCopy, 0x800);
    NNS_GfdRegisterNewVramTransferTask(0x17, 0, chr->mData, chr->mDataSize);
    NNS_GfdRegisterNewVramTransferTask(0x1b, 0, gWiFiVSSetting->mNscrCopy, 0x1000);
    NNS_GfdRegisterNewVramTransferTask(0x1f, 0, pltt->mData, 0x80);
    NNS_GfdRegisterNewVramTransferTask(0x23, 0, gWiFiVSSetting->mWiFiVSSettingSNcgr->mData,
                                       gWiFiVSSetting->mWiFiVSSettingSNcgr->mDataSize);
    NNS_GfdRegisterNewVramTransferTask(0x1e, 0, gWiFiVSSetting->mWiFiVSSettingSONclr->mData,
                                       gWiFiVSSetting->mWiFiVSSettingSONclr->mDataSize);
}

void SetupWiFiVSSettingText(void) {
    void *bmgEntry;
    bmgEntry = GetBmgEntry(gWiFiVSSetting->mWiFiMessages, 0);
    SetupTxtSystemMainTextEx(bmgEntry, 0, 0, 1, 0, 0, 0);
}

void AdvanceWiFiVSSettingState0(void) {
    if (AreBrightnessFadesFaded() != 0) {
        StartFadeToClear(10);
    }
    if (AreBrightnessFadesClear() != 0) {
        if (IsWiFiConnectionLost() != 0) {
            gWiFiVSSetting->mNextState = 1;
            SetupTxtSystemMainTextEx(GetBmgEntry(gWiFiVSSetting->mWiFiMessages, 0x1b), 0, 0, 1, 0, 0, 0);
            ResetWiFiConnectionLost();
            WriteChangedWiFiBuddies();
            return;
        }
        gWiFiVSSetting->mNextState = 2;
        SetupWiFiVSSettingText();
        WriteChangedWiFiBuddies();
    }
}

void AdvanceWiFiVSSettingState1(void) {
    int v1;
    gWiFiVSSetting->mStateFrames = gWiFiVSSetting->mStateFrames + 1;
    v1 = IsTxtSystemState2NoCloseRequest();
    if ((v1 != 0) && (0x78 < gWiFiVSSetting->mStateFrames)) {
        RequestTxtSystemClose();
    }
    v1 = IsTxtSystemState0NoOpenRequest();
    if (v1 != 0) {
        gWiFiVSSetting->mNextState = 2;
        SetupWiFiVSSettingText();
        gWiFiVSSetting->mStateFrames = 0;
    }
}

void AdvanceWiFiVSSettingState2(void) {
    s32 offsetX;
    s32 i;

    gWiFiVSSetting->mStateFrames = gWiFiVSSetting->mStateFrames + 1;
    offsetX = InterpolateS16(1, 0x100, 0, gWiFiVSSetting->mStateFrames, 10);
    for (i = 0; i < 2; i++) {
        if (i == 0) {
            gWiFiVSSetting->mRowOffsets[i][0] = offsetX;
        } else {
            gWiFiVSSetting->mRowOffsets[i][0] = -offsetX;
        }
    }
    if (gWiFiVSSetting->mStateFrames >= 10) {
        gWiFiVSSetting->mNextState = 3;
        gWiFiVSSetting->mStateFrames = 0;
        RequestSelectReturnState1();
    }
}

void AdvanceWiFiVSSettingState3(void) {
    s16 rowOffsetY;

    gWiFiVSSetting->mStateFrames = gWiFiVSSetting->mStateFrames + 1;
    if (gWiFiVSSetting->mStateFrames < 3) {
        rowOffsetY = -LookupSelectReturnState1Bg2Offset(0);
    } else {
        rowOffsetY = -LookupSelectReturnState1Bg2Offset(gWiFiVSSetting->mStateFrames - 3);
    }
    gWiFiVSSetting->mRowOffsets[2][1] = rowOffsetY;
    if (gWiFiVSSetting->mStateFrames >= 10 && gWiFiVSSetting->mStateFrames >= 13) {
        gWiFiVSSetting->mNextState = 4;
        gWiFiVSSetting->mStateFrames = 0;
    }
}

void AdvanceWiFiVSSettingState4(void) {
    s32 previousRow = gWiFiVSSetting->mRow;
    s32 prevSettingIndex = gWiFiVSSetting->mSettingIndex;
    InputSlotIndex slotIndex = UNK_02175628_INDEX_8;
    BOOL pairNewUnlessRecentlyLost = FALSE;
    u32 hitIndex = -1;
    BOOL pairRecentlyLost = FALSE;
    BOOL backPairNewUnlessRecentlyLost;
    s32 backPairRecentlyLost;
    s32 pressedKeys;
    InputSlot *inputSlot;
    u32 messageIndex;

    if (gInputSlots[slotIndex].mPair.mHasPair == 0 && gInputSlots[slotIndex].mPair.mNoPairCount < 5) {
        pairRecentlyLost = TRUE;
    }
    if (pairRecentlyLost == FALSE && gInputSlots[slotIndex].mPair.mPrevHasPair == 0 &&
        gInputSlots[slotIndex].mPair.mHasPair != 0) {
        pairNewUnlessRecentlyLost = TRUE;
    }
    if (pairNewUnlessRecentlyLost != FALSE) {
        hitIndex = RectTableFindContaining(gWiFiVSSetting->mWiFiVSSettingBnbl, gInputSlots[slotIndex].mPair.mPairX,
                                           gInputSlots[slotIndex].mPair.mPairY);
    }
    inputSlot = &gInputSlots[slotIndex];
    pressedKeys = inputSlot->mPressedBits & PAD_KEY_B;
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
    gWiFiVSSetting->mNextState = 6;
    gWiFiVSSetting->mPendingWiFiState = 1;
    RequestSelectReturnState3WithSound(1);
    gWiFiVSSetting->mSelectReturnPending = TRUE;
    RequestTxtSystemClose();
    goto end;
next:
    pressedKeys = inputSlot->mPressedBits & PAD_KEY_A;
    if (((u16) pressedKeys != 0 && gWiFiVSSetting->mRow == 2) || hitIndex == 2) {
        gWiFiVSSetting->mNextState = 5;
        if (gWiFiVSSetting->mRow == 2) {
            gWiFiVSSetting->mHighlightVisible = FALSE;
        }
        gWiFiVSSetting->mPendingWiFiState = 3;
        gWiFiVSSetting->mRow = 2;
        gMenuShared->mWiFiVSSettingKartType = gWiFiVSSettingKartTypes[gWiFiVSSetting->mSettingIndex];
        if ((u16) (gInputSlots[slotIndex].mBits & PAD_KEY_R) != 0) {
            SetWiFiVSSettingFlag(1);
        }
        SetWiFiVSSettingIndex(gWiFiVSSetting->mSettingIndex);
        StartSoundOncePerFrame(5);
    } else if (((u16) pressedKeys != 0 && gWiFiVSSetting->mRow == 0) || hitIndex == 0) {
        gWiFiVSSetting->mNextState = 5;
        if (gWiFiVSSetting->mRow == 0) {
            gWiFiVSSetting->mHighlightVisible = FALSE;
        }
        gWiFiVSSetting->mPendingWiFiState = 14;
        gWiFiVSSetting->mRow = 0;
        gMenuShared->mWiFiScene8StartKind = 0;
        RequestTxtSystemClose();
        StartSoundOncePerFrame(5);
        gMenuShared->mWiFiVSSettingKartType = gWiFiVSSettingKartTypes[gWiFiVSSetting->mSettingIndex];
        WriteChangedWiFiBuddies();
    } else if (hitIndex == 1) {
        gWiFiVSSetting->mRow = 1;
        gWiFiVSSetting->mSettingIndex = gWiFiVSSetting->mSettingIndex + 1;
        StartSoundOncePerFrame(1);
    } else if (GetNewOrRepeatBits(8, PAD_KEY_UP) != 0) {
        gWiFiVSSetting->mRow = gWiFiVSSetting->mRow - 1;
        if (gWiFiVSSetting->mRow < 0) {
            gWiFiVSSetting->mRow = 2;
        }
        StartSoundOncePerFrame(0);
    } else if (GetNewOrRepeatBits(8, PAD_KEY_DOWN) != 0 ||
               (gWiFiVSSetting->mRow == 1 && (u16) (inputSlot->mPressedBits & PAD_KEY_A) != 0)) {
        gWiFiVSSetting->mRow = gWiFiVSSetting->mRow + 1;
        if (gWiFiVSSetting->mRow > 2) {
            gWiFiVSSetting->mRow = 0;
        }
        StartSoundOncePerFrame(0);
    } else if (gWiFiVSSetting->mRow == 1 && GetNewOrRepeatBits(8, PAD_KEY_LEFT) != 0) {
        gWiFiVSSetting->mSettingIndex = gWiFiVSSetting->mSettingIndex - 1;
        gWiFiVSSetting->mIndexDecrementTimer = 6;
        StartSoundOncePerFrame(1);
    } else if (gWiFiVSSetting->mRow == 1 && GetNewOrRepeatBits(8, PAD_KEY_RIGHT) != 0) {
        gWiFiVSSetting->mSettingIndex = gWiFiVSSetting->mSettingIndex + 1;
        if (GetNewOrRepeatBits(8, PAD_KEY_RIGHT) != 0) {
            gWiFiVSSetting->mIndexIncrementTimer = 6;
        }
        StartSoundOncePerFrame(1);
    } else if (hitIndex == 3) {
        gWiFiVSSetting->mRow = 1;
        gWiFiVSSetting->mSettingIndex = gWiFiVSSetting->mSettingIndex - 1;
        gWiFiVSSetting->mIndexDecrementTimer = 6;
        StartSoundOncePerFrame(1);
    } else if (hitIndex == 4) {
        gWiFiVSSetting->mRow = 1;
        gWiFiVSSetting->mSettingIndex = gWiFiVSSetting->mSettingIndex + 1;
        gWiFiVSSetting->mIndexIncrementTimer = 6;
        StartSoundOncePerFrame(1);
    }
end:
    if (gWiFiVSSetting->mSettingIndex < 0) {
        gWiFiVSSetting->mSettingIndex = 3;
    }
    if (gWiFiVSSetting->mSettingIndex > 3) {
        gWiFiVSSetting->mSettingIndex = 0;
    }
    if (prevSettingIndex != gWiFiVSSetting->mSettingIndex) {
        messageIndex = LookupWiFiVSSettingMessageIndex(gWiFiVSSetting->mSettingIndex);
        PrintLabelLayoutTextNoFixedAdvance(1, gWiFiVSSettingLabelIndices[1], gWiFiVSSetting->mWiFiVSSettingBnll,
                                           GetBmgEntry(gWiFiVSSetting->mWiFiMessages, messageIndex),
                                           gWiFiVSSetting->mWiFiVSSettingBncl, gWiFiVSSetting->mWiFiVSSettingTable);
    }
    if (gWiFiVSSetting->mRow == 2 && previousRow != 2) {
        ResetPaletteBlendCycle();
    }
}

void AdvanceWiFiVSSettingState5(void) {
    gWiFiVSSetting->mStateFrames = gWiFiVSSetting->mStateFrames + 1;
    if (gWiFiVSSetting->mStateFrames >= 10) {
        gWiFiVSSetting->mNextState = 6;
        gWiFiVSSetting->mStateFrames = 0;
        RequestTxtSystemClose();
        if (HasBuddyRecords() != FALSE ||
            (gWiFiVSSetting->mPendingWiFiState == 3 && gWiFiVSSetting->mSettingIndex != 0)) {
            RequestSelectReturnState4();
            gWiFiVSSetting->mSelectReturnPending = TRUE;
            return;
        }
        gWiFiVSSetting->mSelectReturnPending = FALSE;
    } else if (gWiFiVSSetting->mStateFrames >= 5) {
        gWiFiVSSetting->mHighlightVisible = TRUE;
    }
}

void AdvanceWiFiVSSettingState6(void) {
    s32 offsetX;
    s16 rowOffsetY;
    s32 i;

    if (GetWiFiNextScene() == -1 && gWiFiVSSetting->mPendingWiFiState == 14 && HasBuddyRecords() != FALSE) {
        SetWiFiNextScene(8);
    }
    gWiFiVSSetting->mStateFrames = gWiFiVSSetting->mStateFrames + 1;
    if (gWiFiVSSetting->mStateFrames <= 10) {
        offsetX = InterpolateS16(1, 0, 0x100, gWiFiVSSetting->mStateFrames, 10);
    } else {
        offsetX = 0x100;
    }
    for (i = 0; i < 2; i++) {
        if (i == 0) {
            gWiFiVSSetting->mRowOffsets[i][0] = offsetX;
        } else {
            gWiFiVSSetting->mRowOffsets[i][0] = -offsetX;
        }
    }
    if (gWiFiVSSetting->mStateFrames < 3) {
        rowOffsetY = -LookupRowOffset(0);
    } else {
        rowOffsetY = -LookupSelectReturnState4Bg2Offset(gWiFiVSSetting->mStateFrames - 3);
    }
    for (i = 0; i < gWiFiVSSettingOffsetCellCounts[2]; i++) {
        gWiFiVSSetting->mRowOffsets[2][1] = rowOffsetY;
    }
    if (gWiFiVSSetting->mStateFrames >= 10 && gWiFiVSSetting->mStateFrames >= 13 &&
        IsTxtSystemState0NoOpenRequest() != 0 &&
        ((gWiFiVSSetting->mSelectReturnPending != FALSE && IsSelectReturnState0NoState1Request() != 0) ||
         IsSelectReturnState2NoState3Or4Request() != 0) &&
        GetWiFiNextScene() == -1) {
        if (gWiFiVSSetting->mPendingWiFiState == 14 && HasBuddyRecords() == FALSE) {
            gWiFiVSSetting->mNextState = 7;
            gWiFiVSSetting->mPendingWiFiState = -1;
            SetupTxtSystemMainText(GetBmgEntry(gWiFiVSSetting->mCommonMessages, 0x76));
            gWiFiVSSetting->mStateFrames = 0;
            return;
        }
        if (gWiFiVSSetting->mPendingWiFiState == 3 && gWiFiVSSetting->mSettingIndex == 0 &&
            HasBuddyRecords() == FALSE) {
            gWiFiVSSetting->mNextState = 8;
            gWiFiVSSetting->mPendingWiFiState = -1;
            SetupTxtSystemMainText(GetBmgEntry(gWiFiVSSetting->mWiFiMessages, 14));
            gWiFiVSSetting->mStateFrames = 0;
            return;
        }
        if (gWiFiVSSetting->mPendingWiFiState == 1) {
            void *questionText;
            void *yesText;
            void *noText;

            gWiFiVSSetting->mNextState = 9;
            gWiFiVSSetting->mStateFrames = 0;
            gWiFiVSSetting->mConnectionReleased = FALSE;
            questionText = GetBmgEntry(gWiFiVSSetting->mWiFiMessages, 0x17);
            yesText = GetBmgEntry(gWiFiVSSetting->mCommonMessages, 0);
            noText = GetBmgEntry(gWiFiVSSetting->mCommonMessages, 1);
            SetupTxtSystemMainTextTwoButtons(questionText, yesText, noText, 0);
            return;
        }
        RequestWiFiState(gWiFiVSSetting->mPendingWiFiState);
    }
}

void AdvanceWiFiVSSettingState7(void) {
    InputSlotIndex slotIndex = UNK_02175628_INDEX_8;
    BOOL pairNewUnlessRecentlyLost;
    BOOL pairRecentlyLost;
    u16 hasPair;

    if (IsTxtSystemState2AfterState1() != 0) {
        NNS_SndArcPlayerStartSeqArc(&gSharedSeqHandle, 0, 0x15);
    }
    if (IsTxtSystemState0NoOpenRequest() != 0 && IsSelectReturnState2NoState3Or4Request() != 0) {
        gWiFiVSSetting->mNextState = 2;
        SetupWiFiVSSettingText();
        gWiFiVSSetting->mRow = 1;
        return;
    }
    if (IsTxtSystemState2NoCloseRequest() != 0 && IsSelectReturnState2NoState3Or4Request() != 0) {
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
            if (IsSelectReturnState2NoState3Or4RequestAndInRect(gInputSlots[slotIndex].mPair.mPairX,
                                                                gInputSlots[slotIndex].mPair.mPairY) == FALSE) {
                return;
            }
        }
        RequestTxtSystemClose();
        RequestSelectReturnState3WithSound(0);
    }
}

void AdvanceWiFiVSSettingState8(void) {
    InputSlotIndex slotIndex = UNK_02175628_INDEX_8;
    BOOL pairNewUnlessRecentlyLost;
    BOOL pairRecentlyLost;
    u16 hasPair;

    if (IsTxtSystemState2AfterState1() != 0) {
        NNS_SndArcPlayerStartSeqArc(&gSharedSeqHandle, 0, 0x15);
    }
    if (IsTxtSystemState0NoOpenRequest() != 0 && IsSelectReturnState2NoState3Or4Request() != 0) {
        gWiFiVSSetting->mNextState = 2;
        SetupWiFiVSSettingText();
        gWiFiVSSetting->mRow = 1;
        return;
    }
    if (IsTxtSystemState2NoCloseRequest() != 0 && IsSelectReturnState2NoState3Or4Request() != 0) {
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
            if (IsSelectReturnState2NoState3Or4RequestAndInRect(gInputSlots[slotIndex].mPair.mPairX,
                                                                gInputSlots[slotIndex].mPair.mPairY) == FALSE) {
                return;
            }
        }
        RequestTxtSystemClose();
        RequestSelectReturnState3WithSound(0);
    }
}

void AdvanceWiFiVSSettingState9(void) {
    if (GetTxtSystemDone() != 0) {
        RequestTxtSystemClose();
        return;
    }
    if (IsTxtSystemState0NoOpenRequest() != 0) {
        if (GetTxtSystemSelectedIndex() == 0) {
            gWiFiVSSetting->mNextState = 10;
            SetupTxtSystemMainTextEx(GetBmgEntry(gWiFiVSSetting->mWiFiMessages, 0x18), 1, 1, 1, 0, 1, 0);
            return;
        }
        gWiFiVSSetting->mNextState = 2;
        SetupWiFiVSSettingText();
        gWiFiVSSetting->mRow = 1;
    }
}

void AdvanceWiFiVSSettingState10(void) {
    gWiFiVSSetting->mStateFrames = gWiFiVSSetting->mStateFrames + 1;
    if (IsTxtSystemState2NoCloseRequest() != 0 && gWiFiVSSetting->mConnectionReleased == FALSE) {
        gWiFiVSSetting->mConnectionReleased = TRUE;
        ReleaseWiFiConnectionWrapper();
    }
    if (gWiFiVSSetting->mConnectionReleased != FALSE && UpdateWiFiSessionRelease() != 0 &&
        gWiFiVSSetting->mStateFrames > 90 && IsTxtSystemState2NoCloseRequest() != 0) {
        void *bmgEntry;

        gWiFiVSSetting->mNextState = 11;
        bmgEntry = GetBmgEntry(gWiFiVSSetting->mWiFiMessages, 0x19);
        SetupTxtSystemMainTextButton(bmgEntry, GetBmgEntry(gWiFiVSSetting->mCommonMessages, 4));
        gWiFiVSSetting->mStateFrames = 0;
    }
}

void AdvanceWiFiVSSettingState11(void) {
    int v1;
    v1 = GetTxtSystemDone();
    if (v1 != 0) {
        RequestTxtSystemClose();
        return;
    }
    v1 = IsTxtSystemState0NoOpenRequest();
    if (v1 != 0) {
        RequestWiFiState(gWiFiVSSetting->mPendingWiFiState);
    }
}

void UpdateWiFiVSSettingOffsets(void) {
    s32 i;
    s32 j;
    s32 k;
    s32 v;

    v = gWiFiVSSetting->mWiFiVSSettingBncl->mCount;
    for (i = 0; i < 3; i++) {
        for (j = 0; j < gWiFiVSSettingOffsetCellCounts[i]; j++) {
            gWiFiVSSetting->mWiFiVSSettingTable[gWiFiVSSettingOffsetTableIndices[i][j]].mOffsetX =
                gWiFiVSSetting->mRowOffsets[i][0];
            gWiFiVSSetting->mWiFiVSSettingTable[gWiFiVSSettingOffsetTableIndices[i][j]].mOffsetY =
                gWiFiVSSetting->mRowOffsets[i][1];
        }
    }
    for (i = 0; i < 3; i++) {
        (gWiFiVSSetting->mWiFiVSSettingTable + v)[gWiFiVSSettingLabelIndices[i]].mOffsetX =
            gWiFiVSSetting->mRowOffsets[i][0];
        (gWiFiVSSetting->mWiFiVSSettingTable + v)[gWiFiVSSettingLabelIndices[i]].mOffsetY =
            gWiFiVSSetting->mRowOffsets[i][1];
    }
    for (k = 0; k < 3; k++) {
        (gWiFiVSSetting->mWiFiVSSettingTable + v)[1].mOffsetX = gWiFiVSSetting->mRowOffsets[1][0];
        (gWiFiVSSetting->mWiFiVSSettingTable + v)[1].mOffsetY = gWiFiVSSetting->mRowOffsets[1][1];
    }
    for (i = 0; i < 3; i++) {
        gWiFiVSSetting->mWiFiVSSettingTable[gWiFiVSSettingTimerTableIndices[i][0]].mOffsetX -=
            LookupFrameOffset(6 - gWiFiVSSetting->mIndexDecrementTimer);
        gWiFiVSSetting->mWiFiVSSettingTable[gWiFiVSSettingTimerTableIndices[i][1]].mOffsetX +=
            LookupFrameOffset(6 - gWiFiVSSetting->mIndexIncrementTimer);
    }
}

void UpdateWiFiVSSettingHighlight(void) {
    s32 i;
    BOOL z = FALSE;

    for (i = 0; i < 3; i++) {
        if (i == gWiFiVSSetting->mRow && gWiFiVSSetting->mHighlightVisible != FALSE) {
            gWiFiVSSetting->mWiFiVSSettingTable[gWiFiVSSettingOffsetTableIndices[i][1]].mVisible = 1;
            SetLabelPaletteIndex(gWiFiVSSettingLabelIndices[i], 14, gWiFiVSSetting->mWiFiVSSettingBnll,
                                 gWiFiVSSetting->mWiFiVSSettingTable, gWiFiVSSetting->mWiFiVSSettingBncl);
        } else {
            gWiFiVSSetting->mWiFiVSSettingTable[gWiFiVSSettingOffsetTableIndices[i][1]].mVisible = z;
            SetLabelPaletteIndex(gWiFiVSSettingLabelIndices[i], 15, gWiFiVSSetting->mWiFiVSSettingBnll,
                                 gWiFiVSSetting->mWiFiVSSettingTable, gWiFiVSSetting->mWiFiVSSettingBncl);
        }
    }
}

void AdvanceWiFiVSSettingIndexTimers(void) {
    s32 i;
    BOOL z = FALSE;
    BOOL y = FALSE;

    for (i = 0; i < 2; i++) {
        if (gWiFiVSSetting->mRow == 1) {
            if ((&gWiFiVSSetting->mIndexDecrementTimer)[i] > 0) {
                gWiFiVSSetting->mWiFiVSSettingTable[gWiFiVSSettingTimerTableIndices[0][i]].mVisible = 1;
                gWiFiVSSetting->mWiFiVSSettingTable[gWiFiVSSettingTimerTableIndices[1][i]].mVisible = 1;
                (&gWiFiVSSetting->mIndexDecrementTimer)[i]--;
            } else {
                gWiFiVSSetting->mWiFiVSSettingTable[gWiFiVSSettingTimerTableIndices[0][i]].mVisible = y;
                gWiFiVSSetting->mWiFiVSSettingTable[gWiFiVSSettingTimerTableIndices[1][i]].mVisible = 1;
            }
        } else {
            gWiFiVSSetting->mWiFiVSSettingTable[gWiFiVSSettingTimerTableIndices[0][i]].mVisible = z;
            gWiFiVSSetting->mWiFiVSSettingTable[gWiFiVSSettingTimerTableIndices[1][i]].mVisible = z;
        }
    }
}

void AdvanceWiFiVSSetting(void) {
    gWiFiVSSetting->mState = gWiFiVSSetting->mNextState;
    switch (gWiFiVSSetting->mState) {
        case 0:
            AdvanceWiFiVSSettingState0();
            break;
        case 1:
            AdvanceWiFiVSSettingState1();
            break;
        case 2:
            AdvanceWiFiVSSettingState2();
            break;
        case 3:
            AdvanceWiFiVSSettingState3();
            break;
        case 4:
            AdvanceWiFiVSSettingState4();
            break;
        case 5:
            AdvanceWiFiVSSettingState5();
            break;
        case 6:
            AdvanceWiFiVSSettingState6();
            break;
        case 7:
            AdvanceWiFiVSSettingState7();
            break;
        case 8:
            AdvanceWiFiVSSettingState8();
            break;
        case 9:
            AdvanceWiFiVSSettingState9();
            break;
        case 10:
            AdvanceWiFiVSSettingState10();
            break;
        case 11:
            AdvanceWiFiVSSettingState11();
            break;
    }
    AdvancePaletteBlend();
    UpdateWiFiVSSettingOffsets();
    UpdateWiFiVSSettingHighlight();
    AdvanceWiFiVSSettingIndexTimers();
    DrawLayoutTable(gWiFiVSSetting->mWiFiVSSettingBncl, gWiFiVSSetting->mWiFiVSSettingSNcer,
                    gWiFiVSSetting->mWiFiVSSettingBnll, GetWiFiMenuSubOamList(), gWiFiVSSetting->mWiFiVSSettingTable);
}

void WriteWiFiVSSettingRegisters(void) {
    u32 a;
    u32 b;
    s32 v;

    a = (reg_GX_DISPCNT & 0x1f00) >> 8;
    a |= 4;
    reg_GX_DISPCNT = (reg_GX_DISPCNT & 0xffffe0ff) | (a << 8);
    b = (reg_GXS_DB_DISPCNT & 0x1f00) >> 8;
    b |= 9;
    reg_GXS_DB_DISPCNT = (reg_GXS_DB_DISPCNT & 0xffffe0ff) | (b << 8);
    G2x_SetBlendAlpha_(&reg_G2_BLDCNT, 0, 2, 6, 10);
    v = -gWiFiVSSetting->mRowOffsets[1][0];
    if (v <= -256) {
        v = -256;
    }
    if (v >= 0x100) {
        v = 0x100;
    }
    reg_G2S_DB_BG3OFS = v & 0x1ff;
}

WiFiStateCallbacks gWiFiVSSettingCallbacks = {InitWiFiVSSetting, ReleaseWiFiVSSetting, AdvanceWiFiVSSetting,
                                              WriteWiFiVSSettingRegisters};

void RegisterWiFiVSSettingCallbacks(void) {
    WiFiStateCallbacks callbacks = gWiFiVSSettingCallbacks;
    SetWiFiStateCallbacks(&callbacks);
}
