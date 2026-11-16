#include "00/Menu/wi_fi_vs_setting.h"

#include "00/Scene/wi_fi_menu_scene.h"
#include "Main/Graphics/font_glyph_text.h"
#include "Main/Graphics/layout_entry_angle.h"
#include "Main/Graphics/layout_table_entry.h"
#include "Main/Graphics/palette_blend.h"
#include "display_blend_affine_setup.h"
#include "01/Menu/record_time_attack.h"
#include "01/Menu/record_time_attack_requests.h"
#include "00/Lib/wifi_library_globals.h"
#include "Main/Menu/txt_system.h"
#include "Main/Menu/select_return.h"
#include "Main/Graphics/oam.h"
#include "sound_archive_load_result.h"
#include "Main/Graphics/layout_rect_table.h"
#include "Main/Graphics/locate_bmg_sections.h"
#include "Main/Sound/sound_init_scene_sounds_and_screen_seqs.h"
#include "Main/System/input_slots.h"
#include "Main/Menu/menu_screens_work.h"
#include "sound_player_control.h"
#include "sound_player_type.h"
#include "sound_stream_control.h"
#include "sound_capture_effect.h"
#include "Main/Race/race_hud_sub_screen_cells.h"
#include "sound_archive_load.h"
#include "Main/Item/item_pool.h"
#include "00/Menu/wi_fi_state_machine.h"
#include "Main/Scene/display_settings.h"
#include "Main/Net/wifi_connection_lost.h"
#include "Main/Net/wifi_session_karts.h"
#include "Main/Net/wifi_session_login.h"
#include "vram_bank_display_setup.h"
#include "registers.h"
#include "Main/System/heap.h"
#include "Main/Sound/sound_system.h"
#include "Main/Menu/menu_shared_clear.h"
#include "Main/System/init_after_startup.h"

WiFiStateCallbacks gWiFiVSSettingCallbacks = {InitWiFiVSSetting, ReleaseWiFiVSSetting, AdvanceWiFiVSSetting,
                                              WriteWiFiVSSettingRegisters};
const u8 gWiFiVSSettingTimerTableIndices[3][2] = {{0xc, 0xd}, {0xa, 0xb}, {8, 9}};
const u8 gWiFiVSSettingLabelIndices[3] = {0, 2, 3};
const u8 gWiFiVSSettingOffsetTableIndices[3][9] = {
    {0, 5, 2, 0, 0, 0, 0, 0, 0}, {1, 6, 3, 8, 9, 0xc, 0xd, 0xa, 0xb}, {4, 7, 0, 0, 0, 0, 0, 0, 0}};
const s32 gWiFiVSSettingOffsetCellCounts[3] = {3, 9, 2};
const u8 gWiFiVSSettingKartTypes[4] = {0, 1, 3, 4};
const u8 gWiFiVSSettingIndexByKartType[5] = {0, 1, 0xff, 2, 3};
const s32 gWiFiVSSettingMessageIndices[3][4] = {{7, 0, 0, 0}, {-1, -1, -1, -1}, {4, 0, 0, 0}};
WiFiVSSetting *gWiFiVSSetting;

BOOL HasBuddyRecords(void) {
    if (CountEmblemEntries() != 0) {
        return TRUE;
    }
    return FALSE;
}

void InitWiFiVSSetting(void *heap) {
    s32 index;

    gWiFiVSSetting = HeapAlloc(heap, sizeof(WiFiVSSetting));
    gWiFiVSSetting->mHeap = heap;
    gWiFiVSSetting->mState = WIFI_VS_SETTING_STATE_WAIT_FADE_IN;
    gWiFiVSSetting->mNextState = WIFI_VS_SETTING_STATE_WAIT_FADE_IN;
    gWiFiVSSetting->mRow = WIFI_VS_SETTING_ROW_SETTING;
    gWiFiVSSetting->mPendingWiFiState = WIFI_STATE_NONE;
    gWiFiVSSetting->mStateFrames = 0;
    gWiFiVSSetting->mHighlightVisible = TRUE;
    SetWiFiVSSettingFlag(0);
    LocateAndQueueWiFiVSSetting();
    InitPaletteBlend(heap, gWiFiVSSetting->mWiFiVSSettingSOPalette, 3);
    for (index = 0; index < 2; index++) {
        SetCellOamModeXlu(gWiFiVSSettingOffsetTableIndices[index][0], 1, gWiFiVSSetting->mWiFiVSSettingSCells,
                          gWiFiVSSetting->mWiFiVSSettingCellLayout);
    }
    ResetOamLists(GetWiFiMenuMainOamList(), GetWiFiMenuSubOamList());
    InitLayoutTable(heap, gWiFiVSSetting->mWiFiVSSettingCellLayout, gWiFiVSSetting->mWiFiVSSettingLabelLayout,
                    &gWiFiVSSetting->mWiFiVSSettingTable);
    gWiFiVSSetting->mWiFiMessages = FindSceneFile("wifi.bmg");
    gWiFiVSSetting->mCommonMessages = FindFileInLoadedArchives("common.bmg");
    {
        s32 subObjSizeLeft = GX_GetSizeOfSubOBJ();
        u8 headerLabelIndices[1] = {1};
        u8 headerLabelSizes[1][2] = {{0xc8, 0x10}};
        u32 headerMessageIndices[1] = {1};

        for (index = 0; index < 1; index++) {
            subObjSizeLeft -= InitLabelCanvas(heap, headerLabelIndices[index], gWiFiVSSetting->mWiFiVSSettingLabelLayout,
                                              headerLabelSizes[index][0], headerLabelSizes[index][1],
                                              gWiFiVSSettingOffsetTableIndices[index][11],
                                              gWiFiVSSetting->mWiFiVSSettingSCells, gWiFiVSSetting->mWiFiVSSettingCellLayout,
                                              gWiFiVSSetting->mWiFiVSSettingTable, subObjSizeLeft);
            PrintLabelLayoutTextNoFixedAdvance(1, headerLabelIndices[index], gWiFiVSSetting->mWiFiVSSettingLabelLayout,
                                               GetBmgEntry(gWiFiVSSetting->mWiFiMessages, headerMessageIndices[index]),
                                               gWiFiVSSetting->mWiFiVSSettingCellLayout, gWiFiVSSetting->mWiFiVSSettingTable);
        }
        {
            u8 labelSizes[3][2] = {{0x80, 0x10}, {0xa0, 0x10}, {0x32, 0x10}};
            s32 messageColumn;
            void *bmgEntry;

            for (index = 0; index < 3; index++) {
                messageColumn = 0;
                if (index == 1) {
                    gWiFiVSSetting->mSettingIndex = gWiFiVSSettingIndexByKartType[gMenuShared->mWiFiVSSettingKartType];
                    if (gWiFiVSSetting->mSettingIndex == WIFI_VS_SETTING_INDEX_BUDDIES && !HasBuddyRecords()) {
                        gWiFiVSSetting->mSettingIndex = WIFI_VS_SETTING_INDEX_NO_BUDDY_DEFAULT;
                    }
                    messageColumn = gWiFiVSSetting->mSettingIndex;
                }
                subObjSizeLeft -= InitLabelCanvas(
                    heap, gWiFiVSSettingLabelIndices[index], gWiFiVSSetting->mWiFiVSSettingLabelLayout, labelSizes[index][0],
                    labelSizes[index][1], gWiFiVSSettingOffsetTableIndices[index][1],
                    gWiFiVSSetting->mWiFiVSSettingSCells, gWiFiVSSetting->mWiFiVSSettingCellLayout,
                    gWiFiVSSetting->mWiFiVSSettingTable, subObjSizeLeft);
                if (index == 2) {
                    bmgEntry = GetBmgEntry(gWiFiVSSetting->mCommonMessages,
                                           gWiFiVSSettingMessageIndices[index][messageColumn]);
                } else if (index == 1) {
                    bmgEntry = GetBmgEntry(gWiFiVSSetting->mWiFiMessages,
                                           LookupWiFiVSSettingMessageIndex(gWiFiVSSetting->mSettingIndex));
                } else {
                    bmgEntry =
                        GetBmgEntry(gWiFiVSSetting->mWiFiMessages, gWiFiVSSettingMessageIndices[index][messageColumn]);
                }
                PrintLabelLayoutTextNoFixedAdvance(
                    1, gWiFiVSSettingLabelIndices[index], gWiFiVSSetting->mWiFiVSSettingLabelLayout, bmgEntry,
                    gWiFiVSSetting->mWiFiVSSettingCellLayout, gWiFiVSSetting->mWiFiVSSettingTable);
            }
        }
    }
    for (index = 0; index < 3; index++) {
        if (index == 2) {
            gWiFiVSSetting->mRowOffsets[index][0] = 0;
            gWiFiVSSetting->mRowOffsets[index][1] = 0x28;
        } else if (index == 1) {
            gWiFiVSSetting->mRowOffsets[index][0] = -WIFI_VS_SETTING_OFFSET_HIDDEN;
            gWiFiVSSetting->mRowOffsets[index][1] = 0;
        } else {
            gWiFiVSSetting->mRowOffsets[index][0] = WIFI_VS_SETTING_OFFSET_HIDDEN;
            gWiFiVSSetting->mRowOffsets[index][1] = 0;
        }
    }
    gWiFiVSSetting->mIndexDecrementTimer = 0;
    gWiFiVSSetting->mIndexIncrementTimer = 0;
    SetLinkLevelIconEnabled(1, 1);
    SetSelectReturnSoundId(SELECT_RETURN_SOUND_ID);
}

void ReleaseWiFiVSSetting(void) {
    u32 displayBits;

    displayBits = (reg_GXS_DB_DISPCNT & REG_GXS_DB_DISPCNT_DISPLAY_MASK) >> 8;
    displayBits &= ~8;
    reg_GXS_DB_DISPCNT = (reg_GXS_DB_DISPCNT & ~REG_GXS_DB_DISPCNT_DISPLAY_MASK) | (displayBits << 8);
    reg_G2S_DB_BG3CNT = (reg_G2S_DB_BG3CNT & (REG_G2S_DB_BG3CNT_PRIORITY_MASK | REG_G2S_DB_BG3CNT_MOSAIC_MASK)) | 0xf00;
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
    gWiFiVSSetting->mWiFiVSSettingCellLayout = FindSceneFile("WiFi_VS_setting.bncl");
    gWiFiVSSetting->mWiFiVSSettingRects = FindSceneFile("WiFi_VS_setting.bnbl");
    gWiFiVSSetting->mWiFiVSSettingLabelLayout = FindSceneFile("WiFi_VS_setting.bnll");
    LocateNcgr2(&gWiFiVSSetting->mWiFiVSSettingSChars, FindSceneFile("WiFi_VS_setting_s.nce.ncgr"));
    LocateNcer(&gWiFiVSSetting->mWiFiVSSettingSCells, FindSceneFile("WiFi_VS_setting_s.nce.ncer"));
    LocateNclr(&gWiFiVSSetting->mWiFiVSSettingSOPalette, FindSceneFile("WiFi_VS_setting_s_o.nclr"));
    reg_G2S_DB_BG3CNT =
        (reg_G2S_DB_BG3CNT & (REG_G2S_DB_BG3CNT_PRIORITY_MASK | REG_G2S_DB_BG3CNT_MOSAIC_MASK)) | 0x4400;
    zero = 0;
    MIi_CpuClear16(zero, gWiFiVSSetting->mNscrCopy, 0x1000);
    MIi_CpuCopy16(scrn->mData, gWiFiVSSetting->mNscrCopy, 0x800);
    NNS_GfdRegisterNewVramTransferTask(0x17, 0, chr->mData, chr->mDataSize);
    NNS_GfdRegisterNewVramTransferTask(0x1b, 0, gWiFiVSSetting->mNscrCopy, 0x1000);
    NNS_GfdRegisterNewVramTransferTask(0x1f, 0, pltt->mData, 0x80);
    NNS_GfdRegisterNewVramTransferTask(0x23, 0, gWiFiVSSetting->mWiFiVSSettingSChars->mData,
                                       gWiFiVSSetting->mWiFiVSSettingSChars->mDataSize);
    NNS_GfdRegisterNewVramTransferTask(0x1e, 0, gWiFiVSSetting->mWiFiVSSettingSOPalette->mData,
                                       gWiFiVSSetting->mWiFiVSSettingSOPalette->mDataSize);
}

void SetupWiFiVSSettingText(void) {
    void *bmgEntry;
    bmgEntry = GetBmgEntry(gWiFiVSSetting->mWiFiMessages, 0);
    SetupTxtSystemMainTextEx(bmgEntry, 0, 0, 1, 0, 0, 0);
}

void AdvanceWiFiVSSettingWaitFadeIn(void) {
    if (AreBrightnessFadesFaded() != 0) {
        StartFadeToClear(10);
    }
    if (AreBrightnessFadesClear() != 0) {
        if (IsWiFiConnectionLost() != 0) {
            gWiFiVSSetting->mNextState = WIFI_VS_SETTING_STATE_WAIT_CONNECTION_LOST_TEXT;
            SetupTxtSystemMainTextEx(GetBmgEntry(gWiFiVSSetting->mWiFiMessages, 0x1b), 0, 0, 1, 0, 0, 0);
            ResetWiFiConnectionLost();
            WriteChangedWiFiBuddies();
            return;
        }
        gWiFiVSSetting->mNextState = WIFI_VS_SETTING_STATE_SLIDE_IN;
        SetupWiFiVSSettingText();
        WriteChangedWiFiBuddies();
    }
}

void AdvanceWiFiVSSettingWaitConnectionLostText(void) {
    int queryResult;
    gWiFiVSSetting->mStateFrames = gWiFiVSSetting->mStateFrames + 1;
    queryResult = IsTxtSystemOpenNoCloseRequest();
    if ((queryResult != 0) && (0x78 < gWiFiVSSetting->mStateFrames)) {
        RequestTxtSystemClose();
    }
    queryResult = IsTxtSystemClosedNoOpenRequest();
    if (queryResult != 0) {
        gWiFiVSSetting->mNextState = WIFI_VS_SETTING_STATE_SLIDE_IN;
        SetupWiFiVSSettingText();
        gWiFiVSSetting->mStateFrames = 0;
    }
}

void AdvanceWiFiVSSettingSlideIn(void) {
    s32 offsetX;
    s32 rowIndex;

    gWiFiVSSetting->mStateFrames = gWiFiVSSetting->mStateFrames + 1;
    offsetX =
        InterpolateS16(1, WIFI_VS_SETTING_OFFSET_HIDDEN, 0, gWiFiVSSetting->mStateFrames, WIFI_VS_SETTING_SLIDE_FRAMES);
    for (rowIndex = 0; rowIndex < 2; rowIndex++) {
        if (rowIndex == 0) {
            gWiFiVSSetting->mRowOffsets[rowIndex][0] = offsetX;
        } else {
            gWiFiVSSetting->mRowOffsets[rowIndex][0] = -offsetX;
        }
    }
    if (gWiFiVSSetting->mStateFrames >= WIFI_VS_SETTING_SLIDE_FRAMES) {
        gWiFiVSSetting->mNextState = WIFI_VS_SETTING_STATE_SLIDE_IN_RETURN_BUTTON;
        gWiFiVSSetting->mStateFrames = 0;
        RequestSelectReturnSlideIn();
    }
}

void AdvanceWiFiVSSettingSlideInReturnButton(void) {
    s16 rowOffsetY;

    gWiFiVSSetting->mStateFrames = gWiFiVSSetting->mStateFrames + 1;
    if (gWiFiVSSetting->mStateFrames < WIFI_VS_SETTING_RETURN_DELAY_FRAMES) {
        rowOffsetY = -LookupSelectReturnSlideInBg2Offset(0);
    } else {
        rowOffsetY =
            -LookupSelectReturnSlideInBg2Offset(gWiFiVSSetting->mStateFrames - WIFI_VS_SETTING_RETURN_DELAY_FRAMES);
    }
    gWiFiVSSetting->mRowOffsets[2][1] = rowOffsetY;
    if (gWiFiVSSetting->mStateFrames >= WIFI_VS_SETTING_SLIDE_FRAMES &&
        gWiFiVSSetting->mStateFrames >= WIFI_VS_SETTING_RETURN_SLIDE_END_FRAMES) {
        gWiFiVSSetting->mNextState = WIFI_VS_SETTING_STATE_WAIT_INPUT;
        gWiFiVSSetting->mStateFrames = 0;
    }
}

void AdvanceWiFiVSSettingWaitInput(void) {
    s32 previousRow = gWiFiVSSetting->mRow;
    s32 prevSettingIndex = gWiFiVSSetting->mSettingIndex;
    InputSlotIndex slotIndex = INPUT_SLOT_PAD_OR_PARTICIPANT;
    BOOL pairNewUnlessRecentlyLost = FALSE;
    u32 hitIndex = -1;
    BOOL pairRecentlyLost = FALSE;
    BOOL returnPairNewUnlessRecentlyLost;
    s32 returnPairRecentlyLost;
    s32 pressedKeys;
    InputSlot *inputSlot;
    u32 messageIndex;

    if (gInputSlots[slotIndex].mPair.mHasPair == 0 &&
        gInputSlots[slotIndex].mPair.mNoPairCount < INPUT_NO_PAIR_BRIEF_FRAMES) {
        pairRecentlyLost = TRUE;
    }
    if (pairRecentlyLost == FALSE && gInputSlots[slotIndex].mPair.mPrevHasPair == 0 &&
        gInputSlots[slotIndex].mPair.mHasPair != 0) {
        pairNewUnlessRecentlyLost = TRUE;
    }
    if (pairNewUnlessRecentlyLost != FALSE) {
        hitIndex = RectTableFindContaining(gWiFiVSSetting->mWiFiVSSettingRects, gInputSlots[slotIndex].mPair.mPairX,
                                           gInputSlots[slotIndex].mPair.mPairY);
    }
    inputSlot = &gInputSlots[slotIndex];
    pressedKeys = inputSlot->mPressedBits & PAD_KEY_B;
    if ((u16) pressedKeys == 0) {
        returnPairRecentlyLost = returnPairNewUnlessRecentlyLost = FALSE;
        if (gInputSlots[slotIndex].mPair.mHasPair == 0 &&
            gInputSlots[slotIndex].mPair.mNoPairCount < INPUT_NO_PAIR_BRIEF_FRAMES) {
            returnPairRecentlyLost = 1;
        }
        if (returnPairRecentlyLost == 0 && gInputSlots[slotIndex].mPair.mPrevHasPair == 0 &&
            gInputSlots[slotIndex].mPair.mHasPair != 0) {
            returnPairNewUnlessRecentlyLost = TRUE;
        }
        if (returnPairNewUnlessRecentlyLost == FALSE ||
            IsSelectReturnShownNoRequestAndInRect(gInputSlots[slotIndex].mPair.mPairX,
                                                  gInputSlots[slotIndex].mPair.mPairY) == FALSE) {
            goto next;
        }
    }
    gWiFiVSSetting->mNextState = WIFI_VS_SETTING_STATE_SLIDE_OUT;
    gWiFiVSSetting->mPendingWiFiState = WIFI_STATE_TOP_MENU;
    RequestSelectReturnPressWithSound(1);
    gWiFiVSSetting->mSelectReturnPending = TRUE;
    RequestTxtSystemClose();
    goto end;
next:
    pressedKeys = inputSlot->mPressedBits & PAD_KEY_A;
    if (((u16) pressedKeys != 0 && gWiFiVSSetting->mRow == WIFI_VS_SETTING_ROW_MATCHING) || hitIndex == 2) {
        gWiFiVSSetting->mNextState = WIFI_VS_SETTING_STATE_PRESS_BUTTON;
        if (gWiFiVSSetting->mRow == WIFI_VS_SETTING_ROW_MATCHING) {
            gWiFiVSSetting->mHighlightVisible = FALSE;
        }
        gWiFiVSSetting->mPendingWiFiState = WIFI_STATE_VS_MATCHING;
        gWiFiVSSetting->mRow = WIFI_VS_SETTING_ROW_MATCHING;
        gMenuShared->mWiFiVSSettingKartType = gWiFiVSSettingKartTypes[gWiFiVSSetting->mSettingIndex];
        if ((u16) (gInputSlots[slotIndex].mBits & PAD_KEY_R) != 0) {
            SetWiFiVSSettingFlag(1);
        }
        SetWiFiVSSettingIndex(gWiFiVSSetting->mSettingIndex);
        StartSoundOncePerFrame(5);
    } else if (((u16) pressedKeys != 0 && gWiFiVSSetting->mRow == WIFI_VS_SETTING_ROW_BUDDY_LIST) || hitIndex == 0) {
        gWiFiVSSetting->mNextState = WIFI_VS_SETTING_STATE_PRESS_BUTTON;
        if (gWiFiVSSetting->mRow == WIFI_VS_SETTING_ROW_BUDDY_LIST) {
            gWiFiVSSetting->mHighlightVisible = FALSE;
        }
        gWiFiVSSetting->mPendingWiFiState = WIFI_STATE_SCENE_RECORD;
        gWiFiVSSetting->mRow = WIFI_VS_SETTING_ROW_BUDDY_LIST;
        gMenuShared->mWiFiScene8StartKind = 0;
        RequestTxtSystemClose();
        StartSoundOncePerFrame(5);
        gMenuShared->mWiFiVSSettingKartType = gWiFiVSSettingKartTypes[gWiFiVSSetting->mSettingIndex];
        WriteChangedWiFiBuddies();
    } else if (hitIndex == 1) {
        gWiFiVSSetting->mRow = WIFI_VS_SETTING_ROW_SETTING;
        gWiFiVSSetting->mSettingIndex = gWiFiVSSetting->mSettingIndex + 1;
        StartSoundOncePerFrame(1);
    } else if (GetNewOrRepeatBits(8, PAD_KEY_UP) != 0) {
        gWiFiVSSetting->mRow = gWiFiVSSetting->mRow - 1;
        if (gWiFiVSSetting->mRow < 0) {
            gWiFiVSSetting->mRow = WIFI_VS_SETTING_ROW_MATCHING;
        }
        StartSoundOncePerFrame(0);
    } else if (GetNewOrRepeatBits(8, PAD_KEY_DOWN) != 0 || (gWiFiVSSetting->mRow == WIFI_VS_SETTING_ROW_SETTING &&
                                                            (u16) (inputSlot->mPressedBits & PAD_KEY_A) != 0)) {
        gWiFiVSSetting->mRow = gWiFiVSSetting->mRow + 1;
        if (gWiFiVSSetting->mRow > WIFI_VS_SETTING_ROW_MATCHING) {
            gWiFiVSSetting->mRow = WIFI_VS_SETTING_ROW_BUDDY_LIST;
        }
        StartSoundOncePerFrame(0);
    } else if (gWiFiVSSetting->mRow == WIFI_VS_SETTING_ROW_SETTING && GetNewOrRepeatBits(8, PAD_KEY_LEFT) != 0) {
        gWiFiVSSetting->mSettingIndex = gWiFiVSSetting->mSettingIndex - 1;
        gWiFiVSSetting->mIndexDecrementTimer = WIFI_VS_SETTING_INDEX_TIMER_FRAMES;
        StartSoundOncePerFrame(1);
    } else if (gWiFiVSSetting->mRow == WIFI_VS_SETTING_ROW_SETTING && GetNewOrRepeatBits(8, PAD_KEY_RIGHT) != 0) {
        gWiFiVSSetting->mSettingIndex = gWiFiVSSetting->mSettingIndex + 1;
        if (GetNewOrRepeatBits(8, PAD_KEY_RIGHT) != 0) {
            gWiFiVSSetting->mIndexIncrementTimer = WIFI_VS_SETTING_INDEX_TIMER_FRAMES;
        }
        StartSoundOncePerFrame(1);
    } else if (hitIndex == 3) {
        gWiFiVSSetting->mRow = WIFI_VS_SETTING_ROW_SETTING;
        gWiFiVSSetting->mSettingIndex = gWiFiVSSetting->mSettingIndex - 1;
        gWiFiVSSetting->mIndexDecrementTimer = WIFI_VS_SETTING_INDEX_TIMER_FRAMES;
        StartSoundOncePerFrame(1);
    } else if (hitIndex == 4) {
        gWiFiVSSetting->mRow = WIFI_VS_SETTING_ROW_SETTING;
        gWiFiVSSetting->mSettingIndex = gWiFiVSSetting->mSettingIndex + 1;
        gWiFiVSSetting->mIndexIncrementTimer = WIFI_VS_SETTING_INDEX_TIMER_FRAMES;
        StartSoundOncePerFrame(1);
    }
end:
    if (gWiFiVSSetting->mSettingIndex < 0) {
        gWiFiVSSetting->mSettingIndex = WIFI_VS_SETTING_INDEX_LAST;
    }
    if (gWiFiVSSetting->mSettingIndex > WIFI_VS_SETTING_INDEX_LAST) {
        gWiFiVSSetting->mSettingIndex = 0;
    }
    if (prevSettingIndex != gWiFiVSSetting->mSettingIndex) {
        messageIndex = LookupWiFiVSSettingMessageIndex(gWiFiVSSetting->mSettingIndex);
        PrintLabelLayoutTextNoFixedAdvance(1, gWiFiVSSettingLabelIndices[1], gWiFiVSSetting->mWiFiVSSettingLabelLayout,
                                           GetBmgEntry(gWiFiVSSetting->mWiFiMessages, messageIndex),
                                           gWiFiVSSetting->mWiFiVSSettingCellLayout, gWiFiVSSetting->mWiFiVSSettingTable);
    }
    if (gWiFiVSSetting->mRow == WIFI_VS_SETTING_ROW_MATCHING && previousRow != WIFI_VS_SETTING_ROW_MATCHING) {
        ResetPaletteBlendCycle();
    }
}

void AdvanceWiFiVSSettingPressButton(void) {
    gWiFiVSSetting->mStateFrames = gWiFiVSSetting->mStateFrames + 1;
    if (gWiFiVSSetting->mStateFrames >= WIFI_VS_SETTING_PRESS_FRAMES) {
        gWiFiVSSetting->mNextState = WIFI_VS_SETTING_STATE_SLIDE_OUT;
        gWiFiVSSetting->mStateFrames = 0;
        RequestTxtSystemClose();
        if (HasBuddyRecords() != FALSE || (gWiFiVSSetting->mPendingWiFiState == WIFI_STATE_VS_MATCHING &&
                                           gWiFiVSSetting->mSettingIndex != WIFI_VS_SETTING_INDEX_BUDDIES)) {
            RequestSelectReturnSlideOut();
            gWiFiVSSetting->mSelectReturnPending = TRUE;
            return;
        }
        gWiFiVSSetting->mSelectReturnPending = FALSE;
    } else if (gWiFiVSSetting->mStateFrames >= WIFI_VS_SETTING_PRESS_HIGHLIGHT_FRAMES) {
        gWiFiVSSetting->mHighlightVisible = TRUE;
    }
}

void AdvanceWiFiVSSettingSlideOut(void) {
    s32 offsetX;
    s16 rowOffsetY;
    s32 rowIndex;

    if (GetWiFiNextScene() == -1 && gWiFiVSSetting->mPendingWiFiState == WIFI_STATE_SCENE_RECORD &&
        HasBuddyRecords() != FALSE) {
        SetWiFiNextScene(8);
    }
    gWiFiVSSetting->mStateFrames = gWiFiVSSetting->mStateFrames + 1;
    if (gWiFiVSSetting->mStateFrames <= WIFI_VS_SETTING_SLIDE_FRAMES) {
        offsetX = InterpolateS16(1, 0, WIFI_VS_SETTING_OFFSET_HIDDEN, gWiFiVSSetting->mStateFrames,
                                 WIFI_VS_SETTING_SLIDE_FRAMES);
    } else {
        offsetX = WIFI_VS_SETTING_OFFSET_HIDDEN;
    }
    for (rowIndex = 0; rowIndex < 2; rowIndex++) {
        if (rowIndex == 0) {
            gWiFiVSSetting->mRowOffsets[rowIndex][0] = offsetX;
        } else {
            gWiFiVSSetting->mRowOffsets[rowIndex][0] = -offsetX;
        }
    }
    if (gWiFiVSSetting->mStateFrames < WIFI_VS_SETTING_RETURN_DELAY_FRAMES) {
        rowOffsetY = -LookupRowOffset(0);
    } else {
        rowOffsetY =
            -LookupSelectReturnSlideOutBg2Offset(gWiFiVSSetting->mStateFrames - WIFI_VS_SETTING_RETURN_DELAY_FRAMES);
    }
    for (rowIndex = 0; rowIndex < gWiFiVSSettingOffsetCellCounts[2]; rowIndex++) {
        gWiFiVSSetting->mRowOffsets[2][1] = rowOffsetY;
    }
    if (gWiFiVSSetting->mStateFrames >= WIFI_VS_SETTING_SLIDE_FRAMES &&
        gWiFiVSSetting->mStateFrames >= WIFI_VS_SETTING_RETURN_SLIDE_END_FRAMES &&
        IsTxtSystemClosedNoOpenRequest() != 0 &&
        ((gWiFiVSSetting->mSelectReturnPending != FALSE && IsSelectReturnHiddenNoRequest() != 0) ||
         IsSelectReturnShownNoRequest() != 0) &&
        GetWiFiNextScene() == -1) {
        if (gWiFiVSSetting->mPendingWiFiState == WIFI_STATE_SCENE_RECORD && HasBuddyRecords() == FALSE) {
            gWiFiVSSetting->mNextState = WIFI_VS_SETTING_STATE_WAIT_NO_BUDDY_LIST_TEXT;
            gWiFiVSSetting->mPendingWiFiState = WIFI_STATE_NONE;
            SetupTxtSystemMainText(GetBmgEntry(gWiFiVSSetting->mCommonMessages, 0x76));
            gWiFiVSSetting->mStateFrames = 0;
            return;
        }
        if (gWiFiVSSetting->mPendingWiFiState == WIFI_STATE_VS_MATCHING &&
            gWiFiVSSetting->mSettingIndex == WIFI_VS_SETTING_INDEX_BUDDIES && HasBuddyRecords() == FALSE) {
            gWiFiVSSetting->mNextState = WIFI_VS_SETTING_STATE_WAIT_NO_BUDDY_SETTING_TEXT;
            gWiFiVSSetting->mPendingWiFiState = WIFI_STATE_NONE;
            SetupTxtSystemMainText(GetBmgEntry(gWiFiVSSetting->mWiFiMessages, 14));
            gWiFiVSSetting->mStateFrames = 0;
            return;
        }
        if (gWiFiVSSetting->mPendingWiFiState == WIFI_STATE_TOP_MENU) {
            void *questionText;
            void *yesText;
            void *noText;

            gWiFiVSSetting->mNextState = WIFI_VS_SETTING_STATE_WAIT_DISCONNECT_ANSWER;
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

void AdvanceWiFiVSSettingWaitNoBuddyListText(void) {
    InputSlotIndex slotIndex = INPUT_SLOT_PAD_OR_PARTICIPANT;
    BOOL pairNewUnlessRecentlyLost;
    BOOL pairRecentlyLost;
    u16 hasPair;

    if (IsTxtSystemOpenAfterOpening() != 0) {
        NNS_SndArcPlayerStartSeqArc(&gSharedSeqHandle, 0, 0x15);
    }
    if (IsTxtSystemClosedNoOpenRequest() != 0 && IsSelectReturnShownNoRequest() != 0) {
        gWiFiVSSetting->mNextState = WIFI_VS_SETTING_STATE_SLIDE_IN;
        SetupWiFiVSSettingText();
        gWiFiVSSetting->mRow = WIFI_VS_SETTING_ROW_SETTING;
        return;
    }
    if (IsTxtSystemOpenNoCloseRequest() != 0 && IsSelectReturnShownNoRequest() != 0) {
        if ((u16) (gInputSlots[slotIndex].mPressedBits & PAD_KEY_B) == 0) {
            pairNewUnlessRecentlyLost = FALSE;
            pairRecentlyLost = FALSE;
            hasPair = gInputSlots[slotIndex].mPair.mHasPair;
            if (hasPair == 0 && gInputSlots[slotIndex].mPair.mNoPairCount < INPUT_NO_PAIR_BRIEF_FRAMES) {
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
        RequestTxtSystemClose();
        RequestSelectReturnPressWithSound(0);
    }
}

void AdvanceWiFiVSSettingWaitNoBuddySettingText(void) {
    InputSlotIndex slotIndex = INPUT_SLOT_PAD_OR_PARTICIPANT;
    BOOL pairNewUnlessRecentlyLost;
    BOOL pairRecentlyLost;
    u16 hasPair;

    if (IsTxtSystemOpenAfterOpening() != 0) {
        NNS_SndArcPlayerStartSeqArc(&gSharedSeqHandle, 0, 0x15);
    }
    if (IsTxtSystemClosedNoOpenRequest() != 0 && IsSelectReturnShownNoRequest() != 0) {
        gWiFiVSSetting->mNextState = WIFI_VS_SETTING_STATE_SLIDE_IN;
        SetupWiFiVSSettingText();
        gWiFiVSSetting->mRow = WIFI_VS_SETTING_ROW_SETTING;
        return;
    }
    if (IsTxtSystemOpenNoCloseRequest() != 0 && IsSelectReturnShownNoRequest() != 0) {
        if ((u16) (gInputSlots[slotIndex].mPressedBits & PAD_KEY_B) == 0) {
            pairNewUnlessRecentlyLost = FALSE;
            pairRecentlyLost = FALSE;
            hasPair = gInputSlots[slotIndex].mPair.mHasPair;
            if (hasPair == 0 && gInputSlots[slotIndex].mPair.mNoPairCount < INPUT_NO_PAIR_BRIEF_FRAMES) {
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
        RequestTxtSystemClose();
        RequestSelectReturnPressWithSound(0);
    }
}

void AdvanceWiFiVSSettingWaitDisconnectAnswer(void) {
    if (GetTxtSystemDone() != 0) {
        RequestTxtSystemClose();
        return;
    }
    if (IsTxtSystemClosedNoOpenRequest() != 0) {
        if (GetTxtSystemSelectedIndex() == 0) {
            gWiFiVSSetting->mNextState = WIFI_VS_SETTING_STATE_WAIT_DISCONNECT_TEXT;
            SetupTxtSystemMainTextEx(GetBmgEntry(gWiFiVSSetting->mWiFiMessages, 0x18), 1, 1, 1, 0, 1, 0);
            return;
        }
        gWiFiVSSetting->mNextState = WIFI_VS_SETTING_STATE_SLIDE_IN;
        SetupWiFiVSSettingText();
        gWiFiVSSetting->mRow = WIFI_VS_SETTING_ROW_SETTING;
    }
}

void AdvanceWiFiVSSettingWaitDisconnectText(void) {
    gWiFiVSSetting->mStateFrames = gWiFiVSSetting->mStateFrames + 1;
    if (IsTxtSystemOpenNoCloseRequest() != 0 && gWiFiVSSetting->mConnectionReleased == FALSE) {
        gWiFiVSSetting->mConnectionReleased = TRUE;
        ReleaseWiFiConnectionWrapper();
    }
    if (gWiFiVSSetting->mConnectionReleased != FALSE && UpdateWiFiSessionRelease() != 0 &&
        gWiFiVSSetting->mStateFrames > WIFI_VS_SETTING_DISCONNECT_MIN_FRAMES && IsTxtSystemOpenNoCloseRequest() != 0) {
        void *bmgEntry;

        gWiFiVSSetting->mNextState = WIFI_VS_SETTING_STATE_WAIT_DISCONNECTED_TEXT;
        bmgEntry = GetBmgEntry(gWiFiVSSetting->mWiFiMessages, 0x19);
        SetupTxtSystemMainTextButton(bmgEntry, GetBmgEntry(gWiFiVSSetting->mCommonMessages, 4));
        gWiFiVSSetting->mStateFrames = 0;
    }
}

void AdvanceWiFiVSSettingWaitDisconnectedText(void) {
    int queryResult;
    queryResult = GetTxtSystemDone();
    if (queryResult != 0) {
        RequestTxtSystemClose();
        return;
    }
    queryResult = IsTxtSystemClosedNoOpenRequest();
    if (queryResult != 0) {
        RequestWiFiState(gWiFiVSSetting->mPendingWiFiState);
    }
}

void UpdateWiFiVSSettingOffsets(void) {
    s32 rowIndex;
    s32 entryIndex;
    s32 copyIndex;
    s32 cellCount;

    cellCount = gWiFiVSSetting->mWiFiVSSettingCellLayout->mCount;
    for (rowIndex = 0; rowIndex < 3; rowIndex++) {
        for (entryIndex = 0; entryIndex < gWiFiVSSettingOffsetCellCounts[rowIndex]; entryIndex++) {
            gWiFiVSSetting->mWiFiVSSettingTable[gWiFiVSSettingOffsetTableIndices[rowIndex][entryIndex]].mOffsetX =
                gWiFiVSSetting->mRowOffsets[rowIndex][0];
            gWiFiVSSetting->mWiFiVSSettingTable[gWiFiVSSettingOffsetTableIndices[rowIndex][entryIndex]].mOffsetY =
                gWiFiVSSetting->mRowOffsets[rowIndex][1];
        }
    }
    for (rowIndex = 0; rowIndex < 3; rowIndex++) {
        (gWiFiVSSetting->mWiFiVSSettingTable + cellCount)[gWiFiVSSettingLabelIndices[rowIndex]].mOffsetX =
            gWiFiVSSetting->mRowOffsets[rowIndex][0];
        (gWiFiVSSetting->mWiFiVSSettingTable + cellCount)[gWiFiVSSettingLabelIndices[rowIndex]].mOffsetY =
            gWiFiVSSetting->mRowOffsets[rowIndex][1];
    }
    for (copyIndex = 0; copyIndex < 3; copyIndex++) {
        (gWiFiVSSetting->mWiFiVSSettingTable + cellCount)[1].mOffsetX = gWiFiVSSetting->mRowOffsets[1][0];
        (gWiFiVSSetting->mWiFiVSSettingTable + cellCount)[1].mOffsetY = gWiFiVSSetting->mRowOffsets[1][1];
    }
    for (rowIndex = 0; rowIndex < 3; rowIndex++) {
        gWiFiVSSetting->mWiFiVSSettingTable[gWiFiVSSettingTimerTableIndices[rowIndex][0]].mOffsetX -=
            LookupFrameOffset(6 - gWiFiVSSetting->mIndexDecrementTimer);
        gWiFiVSSetting->mWiFiVSSettingTable[gWiFiVSSettingTimerTableIndices[rowIndex][1]].mOffsetX +=
            LookupFrameOffset(6 - gWiFiVSSetting->mIndexIncrementTimer);
    }
}

void UpdateWiFiVSSettingHighlight(void) {
    s32 rowIndex;
    BOOL visible = FALSE;

    for (rowIndex = 0; rowIndex < 3; rowIndex++) {
        if (rowIndex == gWiFiVSSetting->mRow && gWiFiVSSetting->mHighlightVisible != FALSE) {
            gWiFiVSSetting->mWiFiVSSettingTable[gWiFiVSSettingOffsetTableIndices[rowIndex][1]].mVisible = 1;
            SetLabelPaletteIndex(gWiFiVSSettingLabelIndices[rowIndex], 14, gWiFiVSSetting->mWiFiVSSettingLabelLayout,
                                 gWiFiVSSetting->mWiFiVSSettingTable, gWiFiVSSetting->mWiFiVSSettingCellLayout);
        } else {
            gWiFiVSSetting->mWiFiVSSettingTable[gWiFiVSSettingOffsetTableIndices[rowIndex][1]].mVisible = visible;
            SetLabelPaletteIndex(gWiFiVSSettingLabelIndices[rowIndex], 15, gWiFiVSSetting->mWiFiVSSettingLabelLayout,
                                 gWiFiVSSetting->mWiFiVSSettingTable, gWiFiVSSetting->mWiFiVSSettingCellLayout);
        }
    }
}

void AdvanceWiFiVSSettingIndexTimers(void) {
    s32 timerIndex;
    BOOL otherRowVisible = FALSE;
    BOOL timerDoneVisible = FALSE;

    for (timerIndex = 0; timerIndex < 2; timerIndex++) {
        if (gWiFiVSSetting->mRow == WIFI_VS_SETTING_ROW_SETTING) {
            if ((&gWiFiVSSetting->mIndexDecrementTimer)[timerIndex] > 0) {
                gWiFiVSSetting->mWiFiVSSettingTable[gWiFiVSSettingTimerTableIndices[0][timerIndex]].mVisible = 1;
                gWiFiVSSetting->mWiFiVSSettingTable[gWiFiVSSettingTimerTableIndices[1][timerIndex]].mVisible = 1;
                (&gWiFiVSSetting->mIndexDecrementTimer)[timerIndex]--;
            } else {
                gWiFiVSSetting->mWiFiVSSettingTable[gWiFiVSSettingTimerTableIndices[0][timerIndex]].mVisible =
                    timerDoneVisible;
                gWiFiVSSetting->mWiFiVSSettingTable[gWiFiVSSettingTimerTableIndices[1][timerIndex]].mVisible = 1;
            }
        } else {
            gWiFiVSSetting->mWiFiVSSettingTable[gWiFiVSSettingTimerTableIndices[0][timerIndex]].mVisible =
                otherRowVisible;
            gWiFiVSSetting->mWiFiVSSettingTable[gWiFiVSSettingTimerTableIndices[1][timerIndex]].mVisible =
                otherRowVisible;
        }
    }
}

void AdvanceWiFiVSSetting(void) {
    gWiFiVSSetting->mState = gWiFiVSSetting->mNextState;
    switch (gWiFiVSSetting->mState) {
        case WIFI_VS_SETTING_STATE_WAIT_FADE_IN:
            AdvanceWiFiVSSettingWaitFadeIn();
            break;
        case WIFI_VS_SETTING_STATE_WAIT_CONNECTION_LOST_TEXT:
            AdvanceWiFiVSSettingWaitConnectionLostText();
            break;
        case WIFI_VS_SETTING_STATE_SLIDE_IN:
            AdvanceWiFiVSSettingSlideIn();
            break;
        case WIFI_VS_SETTING_STATE_SLIDE_IN_RETURN_BUTTON:
            AdvanceWiFiVSSettingSlideInReturnButton();
            break;
        case WIFI_VS_SETTING_STATE_WAIT_INPUT:
            AdvanceWiFiVSSettingWaitInput();
            break;
        case WIFI_VS_SETTING_STATE_PRESS_BUTTON:
            AdvanceWiFiVSSettingPressButton();
            break;
        case WIFI_VS_SETTING_STATE_SLIDE_OUT:
            AdvanceWiFiVSSettingSlideOut();
            break;
        case WIFI_VS_SETTING_STATE_WAIT_NO_BUDDY_LIST_TEXT:
            AdvanceWiFiVSSettingWaitNoBuddyListText();
            break;
        case WIFI_VS_SETTING_STATE_WAIT_NO_BUDDY_SETTING_TEXT:
            AdvanceWiFiVSSettingWaitNoBuddySettingText();
            break;
        case WIFI_VS_SETTING_STATE_WAIT_DISCONNECT_ANSWER:
            AdvanceWiFiVSSettingWaitDisconnectAnswer();
            break;
        case WIFI_VS_SETTING_STATE_WAIT_DISCONNECT_TEXT:
            AdvanceWiFiVSSettingWaitDisconnectText();
            break;
        case WIFI_VS_SETTING_STATE_WAIT_DISCONNECTED_TEXT:
            AdvanceWiFiVSSettingWaitDisconnectedText();
            break;
    }
    AdvancePaletteBlend();
    UpdateWiFiVSSettingOffsets();
    UpdateWiFiVSSettingHighlight();
    AdvanceWiFiVSSettingIndexTimers();
    DrawLayoutTable(gWiFiVSSetting->mWiFiVSSettingCellLayout, gWiFiVSSetting->mWiFiVSSettingSCells,
                    gWiFiVSSetting->mWiFiVSSettingLabelLayout, GetWiFiMenuSubOamList(), gWiFiVSSetting->mWiFiVSSettingTable);
}

void WriteWiFiVSSettingRegisters(void) {
    u32 mainDisplayBits;
    u32 subDisplayBits;
    s32 bgOffsetX;

    mainDisplayBits = (reg_GX_DISPCNT & REG_GX_DISPCNT_DISPLAY_MASK) >> 8;
    mainDisplayBits |= 4;
    reg_GX_DISPCNT = (reg_GX_DISPCNT & ~REG_GX_DISPCNT_DISPLAY_MASK) | (mainDisplayBits << 8);
    subDisplayBits = (reg_GXS_DB_DISPCNT & REG_GXS_DB_DISPCNT_DISPLAY_MASK) >> 8;
    subDisplayBits |= 9;
    reg_GXS_DB_DISPCNT = (reg_GXS_DB_DISPCNT & ~REG_GXS_DB_DISPCNT_DISPLAY_MASK) | (subDisplayBits << 8);
    G2x_SetBlendAlpha_(&reg_G2_BLDCNT, 0, 2, 6, 10);
    bgOffsetX = -gWiFiVSSetting->mRowOffsets[1][0];
    if (bgOffsetX <= -256) {
        bgOffsetX = -256;
    }
    if (bgOffsetX >= 0x100) {
        bgOffsetX = 0x100;
    }
    reg_G2S_DB_BG3OFS = bgOffsetX & 0x1ff;
}

void RegisterWiFiVSSettingCallbacks(void) {
    WiFiStateCallbacks callbacks = gWiFiVSSettingCallbacks;
    SetWiFiStateCallbacks(&callbacks);
}
