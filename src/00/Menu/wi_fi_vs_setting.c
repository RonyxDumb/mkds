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
#include "Main/Sound/sound_seq.h"
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

    gWiFiVSSetting = Mem_AllocateHeap(heap, sizeof(WiFiVSSetting));
    gWiFiVSSetting->mHeap = heap;
    gWiFiVSSetting->mState = WIFI_VS_SETTING_STATE_WAIT_FADE_IN;
    gWiFiVSSetting->mNextState = WIFI_VS_SETTING_STATE_WAIT_FADE_IN;
    gWiFiVSSetting->mRow = WIFI_VS_SETTING_ROW_SETTING;
    gWiFiVSSetting->mPendingWiFiState = WIFI_STATE_NONE;
    gWiFiVSSetting->mStateFrames = 0;
    gWiFiVSSetting->mHighlightVisible = TRUE;
    SetWiFiVSSettingFlag(0);
    LocateAndQueueWiFiVSSetting();
    InitPaletteBlend(heap, gWiFiVSSetting->mWiFiVSSettingSONclr, 3);
    for (index = 0; index < 2; index++) {
        CellBank_ResetSomeMetatileObjectsMode_from_thumb(gWiFiVSSettingOffsetTableIndices[index][0], 1, gWiFiVSSetting->mWiFiVSSettingSNcer,
                          gWiFiVSSetting->mWiFiVSSettingBncl);
    }
    OamBuffer_SomeFn_from_thumb(GetWiFiMenuMainOamList(), GetWiFiMenuSubOamList());
    InitLayoutTable(heap, gWiFiVSSetting->mWiFiVSSettingBncl, gWiFiVSSetting->mWiFiVSSettingBnll,
                    &gWiFiVSSetting->mWiFiVSSettingTable);
    gWiFiVSSetting->mWiFiMessages = FindFileBuffer_K2D_LOC_R2D_R2L_from_thumb("wifi.bmg");
    gWiFiVSSetting->mCommonMessages = FindFileBuffer_G2L_GE2_CKL_CKS_S2D_M2L_MA2_from_thumb("common.bmg");
    {
        s32 subObjSizeLeft = GX_GetSizeOfSubOBJ();
        u8 headerLabelIndices[1] = {1};
        u8 headerLabelSizes[1][2] = {{0xc8, 0x10}};
        u32 headerMessageIndices[1] = {1};

        for (index = 0; index < 1; index++) {
            subObjSizeLeft -= InitLabelCanvas(heap, headerLabelIndices[index], gWiFiVSSetting->mWiFiVSSettingBnll,
                                              headerLabelSizes[index][0], headerLabelSizes[index][1],
                                              gWiFiVSSettingOffsetTableIndices[index][11],
                                              gWiFiVSSetting->mWiFiVSSettingSNcer, gWiFiVSSetting->mWiFiVSSettingBncl,
                                              gWiFiVSSetting->mWiFiVSSettingTable, subObjSizeLeft);
            PrintLabelLayoutTextNoFixedAdvance(1, headerLabelIndices[index], gWiFiVSSetting->mWiFiVSSettingBnll,
                                               Bmg_GetRawStringPointer_from_thumb(gWiFiVSSetting->mWiFiMessages, headerMessageIndices[index]),
                                               gWiFiVSSetting->mWiFiVSSettingBncl, gWiFiVSSetting->mWiFiVSSettingTable);
        }
        {
            u8 labelSizes[3][2] = {{0x80, 0x10}, {0xa0, 0x10}, {0x32, 0x10}};
            s32 messageColumn;
            void *bmgEntry;

            for (index = 0; index < 3; index++) {
                messageColumn = 0;
                if (index == 1) {
                    gWiFiVSSetting->mSettingIndex = gWiFiVSSettingIndexByKartType[g_GlobalB488->mWiFiVSSettingKartType];
                    if (gWiFiVSSetting->mSettingIndex == WIFI_VS_SETTING_INDEX_BUDDIES && !HasBuddyRecords()) {
                        gWiFiVSSetting->mSettingIndex = WIFI_VS_SETTING_INDEX_NO_BUDDY_DEFAULT;
                    }
                    messageColumn = gWiFiVSSetting->mSettingIndex;
                }
                subObjSizeLeft -= InitLabelCanvas(
                    heap, gWiFiVSSettingLabelIndices[index], gWiFiVSSetting->mWiFiVSSettingBnll, labelSizes[index][0],
                    labelSizes[index][1], gWiFiVSSettingOffsetTableIndices[index][1],
                    gWiFiVSSetting->mWiFiVSSettingSNcer, gWiFiVSSetting->mWiFiVSSettingBncl,
                    gWiFiVSSetting->mWiFiVSSettingTable, subObjSizeLeft);
                if (index == 2) {
                    bmgEntry = Bmg_GetRawStringPointer_from_thumb(gWiFiVSSetting->mCommonMessages,
                                           gWiFiVSSettingMessageIndices[index][messageColumn]);
                } else if (index == 1) {
                    bmgEntry = Bmg_GetRawStringPointer_from_thumb(gWiFiVSSetting->mWiFiMessages,
                                           LookupWiFiVSSettingMessageIndex(gWiFiVSSetting->mSettingIndex));
                } else {
                    bmgEntry =
                        Bmg_GetRawStringPointer_from_thumb(gWiFiVSSetting->mWiFiMessages, gWiFiVSSettingMessageIndices[index][messageColumn]);
                }
                PrintLabelLayoutTextNoFixedAdvance(
                    1, gWiFiVSSettingLabelIndices[index], gWiFiVSSetting->mWiFiVSSettingBnll, bmgEntry,
                    gWiFiVSSetting->mWiFiVSSettingBncl, gWiFiVSSetting->mWiFiVSSettingTable);
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

    MaybeReadCharBlock_1(&chr, FindFileBuffer_K2D_LOC_R2D_R2L_from_thumb("WiFi_VS_setting_s_b.ncgr"));
    MaybeReadScreenBlock(&scrn, FindFileBuffer_K2D_LOC_R2D_R2L_from_thumb("WiFi_VS_s_setting.nscr"));
    Gfx_ReadPaletteRelative(&pltt, FindFileBuffer_K2D_LOC_R2D_R2L_from_thumb("WiFi_VS_setting_s_b.nclr"));
    gWiFiVSSetting->mWiFiVSSettingBncl = FindFileBuffer_K2D_LOC_R2D_R2L_from_thumb("WiFi_VS_setting.bncl");
    gWiFiVSSetting->mWiFiVSSettingBnbl = FindFileBuffer_K2D_LOC_R2D_R2L_from_thumb("WiFi_VS_setting.bnbl");
    gWiFiVSSetting->mWiFiVSSettingBnll = FindFileBuffer_K2D_LOC_R2D_R2L_from_thumb("WiFi_VS_setting.bnll");
    Gfx_ReadCharGraphicsRelative(&gWiFiVSSetting->mWiFiVSSettingSNcgr, FindFileBuffer_K2D_LOC_R2D_R2L_from_thumb("WiFi_VS_setting_s.nce.ncgr"));
    LocateNcer(&gWiFiVSSetting->mWiFiVSSettingSNcer, FindFileBuffer_K2D_LOC_R2D_R2L_from_thumb("WiFi_VS_setting_s.nce.ncer"));
    Gfx_ReadPaletteRelative(&gWiFiVSSetting->mWiFiVSSettingSONclr, FindFileBuffer_K2D_LOC_R2D_R2L_from_thumb("WiFi_VS_setting_s_o.nclr"));
    reg_G2S_DB_BG3CNT =
        (reg_G2S_DB_BG3CNT & (REG_G2S_DB_BG3CNT_PRIORITY_MASK | REG_G2S_DB_BG3CNT_MOSAIC_MASK)) | 0x4400;
    zero = 0;
    Mem_CpuFill16(zero, gWiFiVSSetting->mNscrCopy, 0x1000);
    CopyMemory16(scrn->mData, gWiFiVSSetting->mNscrCopy, 0x800);
    AllocateReserveTEQSub(0x17, 0, chr->mData, chr->mDataSize);
    AllocateReserveTEQSub(0x1b, 0, gWiFiVSSetting->mNscrCopy, 0x1000);
    AllocateReserveTEQSub(0x1f, 0, pltt->mData, 0x80);
    AllocateReserveTEQSub(0x23, 0, gWiFiVSSetting->mWiFiVSSettingSNcgr->mData,
                                       gWiFiVSSetting->mWiFiVSSettingSNcgr->mDataSize);
    AllocateReserveTEQSub(0x1e, 0, gWiFiVSSetting->mWiFiVSSettingSONclr->mData,
                                       gWiFiVSSetting->mWiFiVSSettingSONclr->mDataSize);
}

void SetupWiFiVSSettingText(void) {
    void *bmgEntry;
    bmgEntry = Bmg_GetRawStringPointer_from_thumb(gWiFiVSSetting->mWiFiMessages, 0);
    TextSystem_DisplayProgressDialog_TopScreen_from_thumb(bmgEntry, 0, 0, 1, 0, 0, 0);
}

void AdvanceWiFiVSSettingWaitFadeIn(void) {
    if (Bright_IsBothScreensFadedOut() != 0) {
        BrightCtx_SomeFnTopBottom(10);
    }
    if (Bright_IsBothScreensFadedIn() != 0) {
        if (IsWiFiConnectionLost() != 0) {
            gWiFiVSSetting->mNextState = WIFI_VS_SETTING_STATE_WAIT_CONNECTION_LOST_TEXT;
            TextSystem_DisplayProgressDialog_TopScreen_from_thumb(Bmg_GetRawStringPointer_from_thumb(gWiFiVSSetting->mWiFiMessages, 0x1b), 0, 0, 1, 0, 0, 0);
            ResetWiFiConnectionLost();
            WriteSaveFriendCodes();
            return;
        }
        gWiFiVSSetting->mNextState = WIFI_VS_SETTING_STATE_SLIDE_IN;
        SetupWiFiVSSettingText();
        WriteSaveFriendCodes();
    }
}

void AdvanceWiFiVSSettingWaitConnectionLostText(void) {
    int queryResult;
    gWiFiVSSetting->mStateFrames = gWiFiVSSetting->mStateFrames + 1;
    queryResult = TextSystem_IsDialogIdle_from_thumb();
    if ((queryResult != 0) && (0x78 < gWiFiVSSetting->mStateFrames)) {
        TextSystem_CloseDialog_from_thumb();
    }
    queryResult = TextSystem_IsDialogFinished_from_thumb();
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
        ComputeValueInterpolation_from_thumb(1, WIFI_VS_SETTING_OFFSET_HIDDEN, 0, gWiFiVSSetting->mStateFrames, WIFI_VS_SETTING_SLIDE_FRAMES);
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
    BOOL backPairNewUnlessRecentlyLost;
    s32 backPairRecentlyLost;
    s32 pressedKeys;
    InputSlot *inputSlot;
    u32 messageIndex;

    if (g_GlobalCYT[slotIndex].mPair.mHasPair == 0 &&
        g_GlobalCYT[slotIndex].mPair.mNoPairCount < INPUT_NO_PAIR_BRIEF_FRAMES) {
        pairRecentlyLost = TRUE;
    }
    if (pairRecentlyLost == FALSE && g_GlobalCYT[slotIndex].mPair.mPrevHasPair == 0 &&
        g_GlobalCYT[slotIndex].mPair.mHasPair != 0) {
        pairNewUnlessRecentlyLost = TRUE;
    }
    if (pairNewUnlessRecentlyLost != FALSE) {
        hitIndex = RectTableFindContaining(gWiFiVSSetting->mWiFiVSSettingBnbl, g_GlobalCYT[slotIndex].mPair.mPairX,
                                           g_GlobalCYT[slotIndex].mPair.mPairY);
    }
    inputSlot = &g_GlobalCYT[slotIndex];
    pressedKeys = inputSlot->mPressedBits & PAD_KEY_B;
    if ((u16) pressedKeys == 0) {
        backPairRecentlyLost = backPairNewUnlessRecentlyLost = FALSE;
        if (g_GlobalCYT[slotIndex].mPair.mHasPair == 0 &&
            g_GlobalCYT[slotIndex].mPair.mNoPairCount < INPUT_NO_PAIR_BRIEF_FRAMES) {
            backPairRecentlyLost = 1;
        }
        if (backPairRecentlyLost == 0 && g_GlobalCYT[slotIndex].mPair.mPrevHasPair == 0 &&
            g_GlobalCYT[slotIndex].mPair.mHasPair != 0) {
            backPairNewUnlessRecentlyLost = TRUE;
        }
        if (backPairNewUnlessRecentlyLost == FALSE ||
            IsSelectReturnShownNoRequestAndInRect(g_GlobalCYT[slotIndex].mPair.mPairX,
                                                  g_GlobalCYT[slotIndex].mPair.mPairY) == FALSE) {
            goto next;
        }
    }
    gWiFiVSSetting->mNextState = WIFI_VS_SETTING_STATE_SLIDE_OUT;
    gWiFiVSSetting->mPendingWiFiState = WIFI_STATE_TOP_MENU;
    RequestSelectReturnPressWithSound(1);
    gWiFiVSSetting->mSelectReturnPending = TRUE;
    TextSystem_CloseDialog_from_thumb();
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
        g_GlobalB488->mWiFiVSSettingKartType = gWiFiVSSettingKartTypes[gWiFiVSSetting->mSettingIndex];
        if ((u16) (g_GlobalCYT[slotIndex].mBits & PAD_KEY_R) != 0) {
            SetWiFiVSSettingFlag(1);
        }
        SetWiFiVSSettingIndex(gWiFiVSSetting->mSettingIndex);
        MaybePlaySomeSseqFromSarc0(5);
    } else if (((u16) pressedKeys != 0 && gWiFiVSSetting->mRow == WIFI_VS_SETTING_ROW_BUDDY_LIST) || hitIndex == 0) {
        gWiFiVSSetting->mNextState = WIFI_VS_SETTING_STATE_PRESS_BUTTON;
        if (gWiFiVSSetting->mRow == WIFI_VS_SETTING_ROW_BUDDY_LIST) {
            gWiFiVSSetting->mHighlightVisible = FALSE;
        }
        gWiFiVSSetting->mPendingWiFiState = WIFI_STATE_SCENE_RECORD;
        gWiFiVSSetting->mRow = WIFI_VS_SETTING_ROW_BUDDY_LIST;
        g_GlobalB488->mWiFiScene8StartKind = 0;
        TextSystem_CloseDialog_from_thumb();
        MaybePlaySomeSseqFromSarc0(5);
        g_GlobalB488->mWiFiVSSettingKartType = gWiFiVSSettingKartTypes[gWiFiVSSetting->mSettingIndex];
        WriteSaveFriendCodes();
    } else if (hitIndex == 1) {
        gWiFiVSSetting->mRow = WIFI_VS_SETTING_ROW_SETTING;
        gWiFiVSSetting->mSettingIndex = gWiFiVSSetting->mSettingIndex + 1;
        MaybePlaySomeSseqFromSarc0(1);
    } else if (GetNewOrRepeatBits(8, PAD_KEY_UP) != 0) {
        gWiFiVSSetting->mRow = gWiFiVSSetting->mRow - 1;
        if (gWiFiVSSetting->mRow < 0) {
            gWiFiVSSetting->mRow = WIFI_VS_SETTING_ROW_MATCHING;
        }
        MaybePlaySomeSseqFromSarc0(0);
    } else if (GetNewOrRepeatBits(8, PAD_KEY_DOWN) != 0 || (gWiFiVSSetting->mRow == WIFI_VS_SETTING_ROW_SETTING &&
                                                            (u16) (inputSlot->mPressedBits & PAD_KEY_A) != 0)) {
        gWiFiVSSetting->mRow = gWiFiVSSetting->mRow + 1;
        if (gWiFiVSSetting->mRow > WIFI_VS_SETTING_ROW_MATCHING) {
            gWiFiVSSetting->mRow = WIFI_VS_SETTING_ROW_BUDDY_LIST;
        }
        MaybePlaySomeSseqFromSarc0(0);
    } else if (gWiFiVSSetting->mRow == WIFI_VS_SETTING_ROW_SETTING && GetNewOrRepeatBits(8, PAD_KEY_LEFT) != 0) {
        gWiFiVSSetting->mSettingIndex = gWiFiVSSetting->mSettingIndex - 1;
        gWiFiVSSetting->mIndexDecrementTimer = WIFI_VS_SETTING_INDEX_TIMER_FRAMES;
        MaybePlaySomeSseqFromSarc0(1);
    } else if (gWiFiVSSetting->mRow == WIFI_VS_SETTING_ROW_SETTING && GetNewOrRepeatBits(8, PAD_KEY_RIGHT) != 0) {
        gWiFiVSSetting->mSettingIndex = gWiFiVSSetting->mSettingIndex + 1;
        if (GetNewOrRepeatBits(8, PAD_KEY_RIGHT) != 0) {
            gWiFiVSSetting->mIndexIncrementTimer = WIFI_VS_SETTING_INDEX_TIMER_FRAMES;
        }
        MaybePlaySomeSseqFromSarc0(1);
    } else if (hitIndex == 3) {
        gWiFiVSSetting->mRow = WIFI_VS_SETTING_ROW_SETTING;
        gWiFiVSSetting->mSettingIndex = gWiFiVSSetting->mSettingIndex - 1;
        gWiFiVSSetting->mIndexDecrementTimer = WIFI_VS_SETTING_INDEX_TIMER_FRAMES;
        MaybePlaySomeSseqFromSarc0(1);
    } else if (hitIndex == 4) {
        gWiFiVSSetting->mRow = WIFI_VS_SETTING_ROW_SETTING;
        gWiFiVSSetting->mSettingIndex = gWiFiVSSetting->mSettingIndex + 1;
        gWiFiVSSetting->mIndexIncrementTimer = WIFI_VS_SETTING_INDEX_TIMER_FRAMES;
        MaybePlaySomeSseqFromSarc0(1);
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
        PrintLabelLayoutTextNoFixedAdvance(1, gWiFiVSSettingLabelIndices[1], gWiFiVSSetting->mWiFiVSSettingBnll,
                                           Bmg_GetRawStringPointer_from_thumb(gWiFiVSSetting->mWiFiMessages, messageIndex),
                                           gWiFiVSSetting->mWiFiVSSettingBncl, gWiFiVSSetting->mWiFiVSSettingTable);
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
        TextSystem_CloseDialog_from_thumb();
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
        offsetX = ComputeValueInterpolation_from_thumb(1, 0, WIFI_VS_SETTING_OFFSET_HIDDEN, gWiFiVSSetting->mStateFrames,
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
        TextSystem_IsDialogFinished_from_thumb() != 0 &&
        ((gWiFiVSSetting->mSelectReturnPending != FALSE && IsSelectReturnHiddenNoRequest() != 0) ||
         IsSelectReturnShownNoRequest() != 0) &&
        GetWiFiNextScene() == -1) {
        if (gWiFiVSSetting->mPendingWiFiState == WIFI_STATE_SCENE_RECORD && HasBuddyRecords() == FALSE) {
            gWiFiVSSetting->mNextState = WIFI_VS_SETTING_STATE_WAIT_NO_BUDDY_LIST_TEXT;
            gWiFiVSSetting->mPendingWiFiState = WIFI_STATE_NONE;
            SetupTxtSystemMainText(Bmg_GetRawStringPointer_from_thumb(gWiFiVSSetting->mCommonMessages, 0x76));
            gWiFiVSSetting->mStateFrames = 0;
            return;
        }
        if (gWiFiVSSetting->mPendingWiFiState == WIFI_STATE_VS_MATCHING &&
            gWiFiVSSetting->mSettingIndex == WIFI_VS_SETTING_INDEX_BUDDIES && HasBuddyRecords() == FALSE) {
            gWiFiVSSetting->mNextState = WIFI_VS_SETTING_STATE_WAIT_NO_BUDDY_SETTING_TEXT;
            gWiFiVSSetting->mPendingWiFiState = WIFI_STATE_NONE;
            SetupTxtSystemMainText(Bmg_GetRawStringPointer_from_thumb(gWiFiVSSetting->mWiFiMessages, 14));
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
            questionText = Bmg_GetRawStringPointer_from_thumb(gWiFiVSSetting->mWiFiMessages, 0x17);
            yesText = Bmg_GetRawStringPointer_from_thumb(gWiFiVSSetting->mCommonMessages, 0);
            noText = Bmg_GetRawStringPointer_from_thumb(gWiFiVSSetting->mCommonMessages, 1);
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

    if (TextSystem_JustFadedIn_from_thumb() != 0) {
        PlaySseqFromSarc(&gSharedSeqHandle, 0, 0x15);
    }
    if (TextSystem_IsDialogFinished_from_thumb() != 0 && IsSelectReturnShownNoRequest() != 0) {
        gWiFiVSSetting->mNextState = WIFI_VS_SETTING_STATE_SLIDE_IN;
        SetupWiFiVSSettingText();
        gWiFiVSSetting->mRow = WIFI_VS_SETTING_ROW_SETTING;
        return;
    }
    if (TextSystem_IsDialogIdle_from_thumb() != 0 && IsSelectReturnShownNoRequest() != 0) {
        if ((u16) (g_GlobalCYT[slotIndex].mPressedBits & PAD_KEY_B) == 0) {
            pairNewUnlessRecentlyLost = FALSE;
            pairRecentlyLost = FALSE;
            hasPair = g_GlobalCYT[slotIndex].mPair.mHasPair;
            if (hasPair == 0 && g_GlobalCYT[slotIndex].mPair.mNoPairCount < INPUT_NO_PAIR_BRIEF_FRAMES) {
                pairRecentlyLost = TRUE;
            }
            if (pairRecentlyLost == FALSE && g_GlobalCYT[slotIndex].mPair.mPrevHasPair == 0 && hasPair != 0) {
                pairNewUnlessRecentlyLost = TRUE;
            }
            if (pairNewUnlessRecentlyLost == FALSE) {
                return;
            }
            if (IsSelectReturnShownNoRequestAndInRect(g_GlobalCYT[slotIndex].mPair.mPairX,
                                                      g_GlobalCYT[slotIndex].mPair.mPairY) == FALSE) {
                return;
            }
        }
        TextSystem_CloseDialog_from_thumb();
        RequestSelectReturnPressWithSound(0);
    }
}

void AdvanceWiFiVSSettingWaitNoBuddySettingText(void) {
    InputSlotIndex slotIndex = INPUT_SLOT_PAD_OR_PARTICIPANT;
    BOOL pairNewUnlessRecentlyLost;
    BOOL pairRecentlyLost;
    u16 hasPair;

    if (TextSystem_JustFadedIn_from_thumb() != 0) {
        PlaySseqFromSarc(&gSharedSeqHandle, 0, 0x15);
    }
    if (TextSystem_IsDialogFinished_from_thumb() != 0 && IsSelectReturnShownNoRequest() != 0) {
        gWiFiVSSetting->mNextState = WIFI_VS_SETTING_STATE_SLIDE_IN;
        SetupWiFiVSSettingText();
        gWiFiVSSetting->mRow = WIFI_VS_SETTING_ROW_SETTING;
        return;
    }
    if (TextSystem_IsDialogIdle_from_thumb() != 0 && IsSelectReturnShownNoRequest() != 0) {
        if ((u16) (g_GlobalCYT[slotIndex].mPressedBits & PAD_KEY_B) == 0) {
            pairNewUnlessRecentlyLost = FALSE;
            pairRecentlyLost = FALSE;
            hasPair = g_GlobalCYT[slotIndex].mPair.mHasPair;
            if (hasPair == 0 && g_GlobalCYT[slotIndex].mPair.mNoPairCount < INPUT_NO_PAIR_BRIEF_FRAMES) {
                pairRecentlyLost = TRUE;
            }
            if (pairRecentlyLost == FALSE && g_GlobalCYT[slotIndex].mPair.mPrevHasPair == 0 && hasPair != 0) {
                pairNewUnlessRecentlyLost = TRUE;
            }
            if (pairNewUnlessRecentlyLost == FALSE) {
                return;
            }
            if (IsSelectReturnShownNoRequestAndInRect(g_GlobalCYT[slotIndex].mPair.mPairX,
                                                      g_GlobalCYT[slotIndex].mPair.mPairY) == FALSE) {
                return;
            }
        }
        TextSystem_CloseDialog_from_thumb();
        RequestSelectReturnPressWithSound(0);
    }
}

void AdvanceWiFiVSSettingWaitDisconnectAnswer(void) {
    if (TextSystem_WasAnyDialogButtonPressed_from_thumb() != 0) {
        TextSystem_CloseDialog_from_thumb();
        return;
    }
    if (TextSystem_IsDialogFinished_from_thumb() != 0) {
        if (TextSystem_IsButton2Focused_from_thumb() == 0) {
            gWiFiVSSetting->mNextState = WIFI_VS_SETTING_STATE_WAIT_DISCONNECT_TEXT;
            TextSystem_DisplayProgressDialog_TopScreen_from_thumb(Bmg_GetRawStringPointer_from_thumb(gWiFiVSSetting->mWiFiMessages, 0x18), 1, 1, 1, 0, 1, 0);
            return;
        }
        gWiFiVSSetting->mNextState = WIFI_VS_SETTING_STATE_SLIDE_IN;
        SetupWiFiVSSettingText();
        gWiFiVSSetting->mRow = WIFI_VS_SETTING_ROW_SETTING;
    }
}

void AdvanceWiFiVSSettingWaitDisconnectText(void) {
    gWiFiVSSetting->mStateFrames = gWiFiVSSetting->mStateFrames + 1;
    if (TextSystem_IsDialogIdle_from_thumb() != 0 && gWiFiVSSetting->mConnectionReleased == FALSE) {
        gWiFiVSSetting->mConnectionReleased = TRUE;
        ReleaseWiFiConnectionWrapper();
    }
    if (gWiFiVSSetting->mConnectionReleased != FALSE && UpdateWiFiSessionRelease() != 0 &&
        gWiFiVSSetting->mStateFrames > WIFI_VS_SETTING_DISCONNECT_MIN_FRAMES && TextSystem_IsDialogIdle_from_thumb() != 0) {
        void *bmgEntry;

        gWiFiVSSetting->mNextState = WIFI_VS_SETTING_STATE_WAIT_DISCONNECTED_TEXT;
        bmgEntry = Bmg_GetRawStringPointer_from_thumb(gWiFiVSSetting->mWiFiMessages, 0x19);
        SetupTxtSystemMainTextButton(bmgEntry, Bmg_GetRawStringPointer_from_thumb(gWiFiVSSetting->mCommonMessages, 4));
        gWiFiVSSetting->mStateFrames = 0;
    }
}

void AdvanceWiFiVSSettingWaitDisconnectedText(void) {
    int queryResult;
    queryResult = TextSystem_WasAnyDialogButtonPressed_from_thumb();
    if (queryResult != 0) {
        TextSystem_CloseDialog_from_thumb();
        return;
    }
    queryResult = TextSystem_IsDialogFinished_from_thumb();
    if (queryResult != 0) {
        RequestWiFiState(gWiFiVSSetting->mPendingWiFiState);
    }
}

void UpdateWiFiVSSettingOffsets(void) {
    s32 rowIndex;
    s32 entryIndex;
    s32 copyIndex;
    s32 layoutCount;

    layoutCount = gWiFiVSSetting->mWiFiVSSettingBncl->mCount;
    for (rowIndex = 0; rowIndex < 3; rowIndex++) {
        for (entryIndex = 0; entryIndex < gWiFiVSSettingOffsetCellCounts[rowIndex]; entryIndex++) {
            gWiFiVSSetting->mWiFiVSSettingTable[gWiFiVSSettingOffsetTableIndices[rowIndex][entryIndex]].mOffsetX =
                gWiFiVSSetting->mRowOffsets[rowIndex][0];
            gWiFiVSSetting->mWiFiVSSettingTable[gWiFiVSSettingOffsetTableIndices[rowIndex][entryIndex]].mOffsetY =
                gWiFiVSSetting->mRowOffsets[rowIndex][1];
        }
    }
    for (rowIndex = 0; rowIndex < 3; rowIndex++) {
        (gWiFiVSSetting->mWiFiVSSettingTable + layoutCount)[gWiFiVSSettingLabelIndices[rowIndex]].mOffsetX =
            gWiFiVSSetting->mRowOffsets[rowIndex][0];
        (gWiFiVSSetting->mWiFiVSSettingTable + layoutCount)[gWiFiVSSettingLabelIndices[rowIndex]].mOffsetY =
            gWiFiVSSetting->mRowOffsets[rowIndex][1];
    }
    for (copyIndex = 0; copyIndex < 3; copyIndex++) {
        (gWiFiVSSetting->mWiFiVSSettingTable + layoutCount)[1].mOffsetX = gWiFiVSSetting->mRowOffsets[1][0];
        (gWiFiVSSetting->mWiFiVSSettingTable + layoutCount)[1].mOffsetY = gWiFiVSSetting->mRowOffsets[1][1];
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
    BOOL hidden = FALSE;

    for (rowIndex = 0; rowIndex < 3; rowIndex++) {
        if (rowIndex == gWiFiVSSetting->mRow && gWiFiVSSetting->mHighlightVisible != FALSE) {
            gWiFiVSSetting->mWiFiVSSettingTable[gWiFiVSSettingOffsetTableIndices[rowIndex][1]].mVisible = 1;
            SetLabelPaletteIndex(gWiFiVSSettingLabelIndices[rowIndex], 14, gWiFiVSSetting->mWiFiVSSettingBnll,
                                 gWiFiVSSetting->mWiFiVSSettingTable, gWiFiVSSetting->mWiFiVSSettingBncl);
        } else {
            gWiFiVSSetting->mWiFiVSSettingTable[gWiFiVSSettingOffsetTableIndices[rowIndex][1]].mVisible = hidden;
            SetLabelPaletteIndex(gWiFiVSSettingLabelIndices[rowIndex], 15, gWiFiVSSetting->mWiFiVSSettingBnll,
                                 gWiFiVSSetting->mWiFiVSSettingTable, gWiFiVSSetting->mWiFiVSSettingBncl);
        }
    }
}

void AdvanceWiFiVSSettingIndexTimers(void) {
    s32 timerIndex;
    BOOL hiddenOtherRow = FALSE;
    BOOL hiddenTimerDone = FALSE;

    for (timerIndex = 0; timerIndex < 2; timerIndex++) {
        if (gWiFiVSSetting->mRow == WIFI_VS_SETTING_ROW_SETTING) {
            if ((&gWiFiVSSetting->mIndexDecrementTimer)[timerIndex] > 0) {
                gWiFiVSSetting->mWiFiVSSettingTable[gWiFiVSSettingTimerTableIndices[0][timerIndex]].mVisible = 1;
                gWiFiVSSetting->mWiFiVSSettingTable[gWiFiVSSettingTimerTableIndices[1][timerIndex]].mVisible = 1;
                (&gWiFiVSSetting->mIndexDecrementTimer)[timerIndex]--;
            } else {
                gWiFiVSSetting->mWiFiVSSettingTable[gWiFiVSSettingTimerTableIndices[0][timerIndex]].mVisible =
                    hiddenTimerDone;
                gWiFiVSSetting->mWiFiVSSettingTable[gWiFiVSSettingTimerTableIndices[1][timerIndex]].mVisible = 1;
            }
        } else {
            gWiFiVSSetting->mWiFiVSSettingTable[gWiFiVSSettingTimerTableIndices[0][timerIndex]].mVisible =
                hiddenOtherRow;
            gWiFiVSSetting->mWiFiVSSettingTable[gWiFiVSSettingTimerTableIndices[1][timerIndex]].mVisible =
                hiddenOtherRow;
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
    DrawLayoutTable(gWiFiVSSetting->mWiFiVSSettingBncl, gWiFiVSSetting->mWiFiVSSettingSNcer,
                    gWiFiVSSetting->mWiFiVSSettingBnll, GetWiFiMenuSubOamList(), gWiFiVSSetting->mWiFiVSSettingTable);
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
