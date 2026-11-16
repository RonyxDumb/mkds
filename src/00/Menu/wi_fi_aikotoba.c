#include "00/Menu/wi_fi_aikotoba.h"
#include "registers.h"
#include "Main/System/heap.h"
#include "00/Lib/NitroWiFi/access_point_search_defaults.h"
#include "Main/Scene/display_settings.h"
#include "display_blend_affine_setup.h"
#include "vram_load_2d_graphics.h"

#include "00/Menu/wi_fi_state_machine.h"
#include "00/Lib/wifi_library_globals.h"
#include "00/Scene/wi_fi_menu_scene.h"
#include "Main/Graphics/layout_entry_angle.h"
#include "Main/Graphics/layout_table_entry.h"
#include "Main/Menu/txt_system.h"
#include "Main/Menu/select_return.h"
#include "Main/Graphics/oam.h"
#include "Main/Sound/sound_seq.h"
#include "Main/System/input_slots.h"
#include "Main/Graphics/layout_rect_table.h"
#include "Main/System/result_archive_path.h"
#include "Main/Menu/menu_shared_clear.h"
#include "Main/System/init_after_startup.h"

const u8 gWiFiAikotobaCellIndices[2] = {6, 7};
const u8 gWiFiAikotobaSTableIndices[2] = {4, 5};
const s32 gWiFiAikotobaOffsetCellCounts[2] = {4, 4};
const u8 gWiFiAikotobaOffsetTableIndices[2][4] = {{0, 2, 4, 6}, {1, 3, 5, 7}};
const u8 gWiFiAikotobaXluCellIndices[2] = {0, 1};
WiFiStateCallbacks gWiFiAikotobaCallbacks = {InitWiFiAikotoba, ClearWiFiAikotobaPointer, AdvanceWiFiAikotoba,
                                             WriteWiFiAikotobaRegisters};
WiFiAikotoba *gWiFiAikotoba;

void InitWiFiAikotoba(void *heap) {
    s32 index;
    s32 cellIndex;
    u32 wiFiPrevState;
    void *oamList;

    gWiFiAikotoba = Mem_AllocateHeap(heap, sizeof(WiFiAikotoba));
    gWiFiAikotoba->mHeap = heap;
    gWiFiAikotoba->mState = WIFI_AIKOTOBA_STATE_WAIT_FADE;
    gWiFiAikotoba->mNextState = WIFI_AIKOTOBA_STATE_WAIT_FADE;
    gWiFiAikotoba->mPendingWiFiState = WIFI_STATE_NONE;
    wiFiPrevState = GetWiFiPrevState();
    switch (wiFiPrevState) {
        case WIFI_STATE_TOP_MENU:
        case WIFI_STATE_SCENE_KEYBOARD:
            gWiFiAikotoba->mSelectedIndex = 0;
            break;
        case WIFI_STATE_AIKOTOBA_CHECK:
            gWiFiAikotoba->mSelectedIndex = 1;
            break;
    }
    gWiFiAikotoba->mStateFrames = 0;
    gWiFiAikotoba->mHighlightVisible = TRUE;
    LocateAndUploadWiFiAikotoba();
    for (index = 0; index < 2; index++) {
        CellBank_ResetSomeMetatileObjectsMode_from_thumb(gWiFiAikotobaXluCellIndices[index], 1, gWiFiAikotoba->mWiFiAikotobaSNcer,
                          gWiFiAikotoba->mWiFiAikotobaBncl);
    }
    oamList = GetWiFiMenuMainOamList();
    OamBuffer_SomeFn_from_thumb(oamList, GetWiFiMenuSubOamList());
    InitLayoutTable(heap, gWiFiAikotoba->mWiFiAikotobaBncl, NULL, &gWiFiAikotoba->mWiFiAikotobaTable);
    gWiFiAikotoba->mWiFiMessages = FindFileBuffer_K2D_LOC_R2D_R2L_from_thumb("wifi.bmg");
    gWiFiAikotoba->mCommonMessages = FindFileBuffer_G2L_GE2_CKL_CKS_S2D_M2L_MA2_from_thumb("common.bmg");
    for (index = 0; index < 2; index++) {
        for (cellIndex = 0; cellIndex < gWiFiAikotobaOffsetCellCounts[index]; cellIndex++) {
            gWiFiAikotoba->mWiFiAikotobaTable[gWiFiAikotobaOffsetTableIndices[index][cellIndex]].mOffsetX =
                WIFI_AIKOTOBA_OFFSET_HIDDEN;
        }
    }
    SetSelectReturnSoundId(SELECT_RETURN_SOUND_ID);
}

void ClearWiFiAikotobaPointer(void) {
    gWiFiAikotoba = NULL;
}

void LocateAndUploadWiFiAikotoba(void) {
    void *sceneFile;
    sceneFile = FindFileBuffer_K2D_LOC_R2D_R2L_from_thumb("WiFi_aikotoba.bncl");
    gWiFiAikotoba->mWiFiAikotobaBncl = sceneFile;
    sceneFile = FindFileBuffer_K2D_LOC_R2D_R2L_from_thumb("WiFi_aikotoba.bnbl");
    gWiFiAikotoba->mWiFiAikotobaBnbl = sceneFile;
    sceneFile = FindFileBuffer_K2D_LOC_R2D_R2L_from_thumb("WiFi_aikotoba_s.nce.ncgr");
    Gfx_ReadCharGraphicsRelative(&gWiFiAikotoba->mWiFiAikotobaSNcgr, sceneFile);
    sceneFile = FindFileBuffer_K2D_LOC_R2D_R2L_from_thumb("WiFi_aikotoba_s.nce.ncer");
    LocateNcer(&gWiFiAikotoba->mWiFiAikotobaSNcer, sceneFile);
    sceneFile = FindFileBuffer_K2D_LOC_R2D_R2L_from_thumb("WiFi_aikotoba_s_o.nclr");
    Gfx_ReadPaletteRelative(&gWiFiAikotoba->mWiFiAikotobaSONclr, sceneFile);
    TEQSub_Fn35Impl(gWiFiAikotoba->mWiFiAikotobaSNcgr->mData, 0, gWiFiAikotoba->mWiFiAikotobaSNcgr->mDataSize);
    TEQSub_Fn30Impl(gWiFiAikotoba->mWiFiAikotobaSONclr->mData, 0, gWiFiAikotoba->mWiFiAikotobaSONclr->mDataSize);
}

BOOL IsBuddyRecordBlockFull(void) {
    u32 recordCount;
    recordCount = CountEmblemEntries();
    if (60 <= recordCount) {
        return 1;
    }
    return 0;
}

void AdvanceWiFiAikotobaWaitFade(void) {
    int fadesClear;
    fadesClear = Bright_IsBothScreensFadedIn();
    if (fadesClear != 0) {
        gWiFiAikotoba->mNextState = WIFI_AIKOTOBA_STATE_SLIDE_IN;
    }
}

void AdvanceWiFiAikotobaSlideIn(void) {
    s32 offsetX;
    s32 rowIndex;
    s32 cellIndex;

    gWiFiAikotoba->mStateFrames = gWiFiAikotoba->mStateFrames + 1;
    offsetX =
        ComputeValueInterpolation_from_thumb(1, WIFI_AIKOTOBA_OFFSET_HIDDEN, 0, gWiFiAikotoba->mStateFrames, WIFI_AIKOTOBA_SLIDE_FRAMES);
    for (rowIndex = 0; rowIndex < 2; rowIndex++) {
        for (cellIndex = 0; cellIndex < gWiFiAikotobaOffsetCellCounts[rowIndex]; cellIndex++) {
            if (rowIndex == 1) {
                gWiFiAikotoba->mWiFiAikotobaTable[gWiFiAikotobaOffsetTableIndices[rowIndex][cellIndex]].mOffsetX =
                    offsetX;
            } else {
                gWiFiAikotoba->mWiFiAikotobaTable[gWiFiAikotobaOffsetTableIndices[rowIndex][cellIndex]].mOffsetX =
                    -offsetX;
            }
        }
    }
    if (gWiFiAikotoba->mStateFrames >= WIFI_AIKOTOBA_SLIDE_FRAMES) {
        gWiFiAikotoba->mNextState = WIFI_AIKOTOBA_STATE_WAIT_SELECT_RETURN;
        gWiFiAikotoba->mStateFrames = 0;
        RequestSelectReturnSlideIn();
    }
}

void AdvanceWiFiAikotobaWaitSelectReturn(void) {
    int isReturnShown;
    isReturnShown = IsSelectReturnShownNoRequest();
    if (isReturnShown != 0) {
        gWiFiAikotoba->mNextState = WIFI_AIKOTOBA_STATE_INPUT;
    }
}

void AdvanceWiFiAikotobaInput(void) {
    InputSlotIndex slotIndex = INPUT_SLOT_PAD_OR_PARTICIPANT;
    u32 hitIndex = -1;
    BOOL pairNewUnlessRecentlyLost;
    BOOL pairRecentlyLost;
    u16 hasPair;
    s32 previousIndex;
    u32 pressedKeys;
    WiFiAikotoba *wiFiAikotoba;

    pairNewUnlessRecentlyLost = FALSE;
    pairRecentlyLost = FALSE;
    hasPair = g_GlobalCYT[slotIndex].mPair.mHasPair;
    if (hasPair == 0 && g_GlobalCYT[slotIndex].mPair.mNoPairCount < INPUT_NO_PAIR_BRIEF_FRAMES) {
        pairRecentlyLost = TRUE;
    }
    if (pairRecentlyLost == FALSE && g_GlobalCYT[slotIndex].mPair.mPrevHasPair == 0 && hasPair != 0) {
        pairNewUnlessRecentlyLost = TRUE;
    }
    if (pairNewUnlessRecentlyLost != FALSE) {
        hitIndex = RectTableFindContaining(gWiFiAikotoba->mWiFiAikotobaBnbl, g_GlobalCYT[slotIndex].mPair.mPairX,
                                           g_GlobalCYT[slotIndex].mPair.mPairY);
    }
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
        if (pairNewUnlessRecentlyLost == FALSE ||
            IsSelectReturnShownNoRequestAndInRect(g_GlobalCYT[slotIndex].mPair.mPairX,
                                                  g_GlobalCYT[slotIndex].mPair.mPairY) == FALSE) {
            goto next;
        }
    }
    gWiFiAikotoba->mNextState = WIFI_AIKOTOBA_STATE_SLIDE_OUT;
    gWiFiAikotoba->mPendingWiFiState = WIFI_STATE_TOP_MENU;
    RequestSelectReturnPressWithSound(0);
    return;
next:
    pressedKeys = g_GlobalCYT[slotIndex].mPressedBits & PAD_KEY_A;
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
        gWiFiAikotoba->mNextState = WIFI_AIKOTOBA_STATE_PRESS;
        switch (gWiFiAikotoba->mSelectedIndex) {
            case 0:
                gWiFiAikotoba->mPendingWiFiState = WIFI_STATE_SCENE_KEYBOARD;
                break;
            case 1:
                gWiFiAikotoba->mPendingWiFiState = WIFI_STATE_AIKOTOBA_CHECK;
                break;
        }
        if (gWiFiAikotoba->mSelectedIndex == previousIndex) {
            gWiFiAikotoba->mHighlightVisible = FALSE;
        }
        MaybePlaySomeSseqFromSarc0(5);
        return;
    }
    if (GetNewOrRepeatBits(8, PAD_KEY_UP) != 0 && gWiFiAikotoba->mSelectedIndex > 0) {
        gWiFiAikotoba->mSelectedIndex = gWiFiAikotoba->mSelectedIndex - 1;
        MaybePlaySomeSseqFromSarc0(0);
        return;
    }
    if (GetNewOrRepeatBits(8, PAD_KEY_DOWN) != 0 && gWiFiAikotoba->mSelectedIndex < 1) {
        gWiFiAikotoba->mSelectedIndex = gWiFiAikotoba->mSelectedIndex + 1;
        MaybePlaySomeSseqFromSarc0(0);
    }
}

void AdvanceWiFiAikotobaPress(void) {
    gWiFiAikotoba->mStateFrames = gWiFiAikotoba->mStateFrames + 1;
    if (gWiFiAikotoba->mStateFrames >= WIFI_AIKOTOBA_PRESS_FRAMES) {
        gWiFiAikotoba->mNextState = WIFI_AIKOTOBA_STATE_SLIDE_OUT;
        if (gWiFiAikotoba->mPendingWiFiState == WIFI_STATE_SCENE_KEYBOARD) {
            RequestSelectReturnSlideOut();
        }
        gWiFiAikotoba->mStateFrames = 0;
    } else if (gWiFiAikotoba->mStateFrames >= WIFI_AIKOTOBA_PRESS_HIGHLIGHT_FRAMES) {
        gWiFiAikotoba->mHighlightVisible = TRUE;
    }
}

void AdvanceWiFiAikotobaSlideOut(void) {
    s32 offsetX;
    s32 rowIndex;
    s32 cellIndex;
    s32 unusedValue;
    void *bmgEntry;

    if (GetWiFiNextScene() == -1 && IsBuddyRecordBlockFull() == 0 &&
        gWiFiAikotoba->mPendingWiFiState == WIFI_STATE_SCENE_KEYBOARD) {
        SetWiFiNextScene(0xe);
    }
    gWiFiAikotoba->mStateFrames = gWiFiAikotoba->mStateFrames + 1;
    if (gWiFiAikotoba->mStateFrames <= WIFI_AIKOTOBA_SLIDE_FRAMES) {
        offsetX =
            ComputeValueInterpolation_from_thumb(1, 0, WIFI_AIKOTOBA_OFFSET_HIDDEN, gWiFiAikotoba->mStateFrames, WIFI_AIKOTOBA_SLIDE_FRAMES);
    } else {
        offsetX = WIFI_AIKOTOBA_OFFSET_HIDDEN;
    }
    for (rowIndex = 0; rowIndex < 2; rowIndex++) {
        for (cellIndex = 0; cellIndex < gWiFiAikotobaOffsetCellCounts[rowIndex]; cellIndex++) {
            if (rowIndex == 1) {
                gWiFiAikotoba->mWiFiAikotobaTable[gWiFiAikotobaOffsetTableIndices[rowIndex][cellIndex]].mOffsetX =
                    offsetX;
            } else {
                gWiFiAikotoba->mWiFiAikotobaTable[gWiFiAikotobaOffsetTableIndices[rowIndex][cellIndex]].mOffsetX =
                    -offsetX;
            }
        }
    }
    if (gWiFiAikotoba->mStateFrames >= WIFI_AIKOTOBA_SLIDE_FRAMES) {
        if (IsBuddyRecordBlockFull() != 0 && gWiFiAikotoba->mPendingWiFiState == WIFI_STATE_SCENE_KEYBOARD) {
            gWiFiAikotoba->mNextState = WIFI_AIKOTOBA_STATE_BUDDY_FULL_NOTICE;
            gWiFiAikotoba->mPendingWiFiState = WIFI_STATE_NONE;
            bmgEntry = Bmg_GetRawStringPointer_from_thumb(gWiFiAikotoba->mWiFiMessages, 0xf);
            SetupTxtSystemMainTextButton(bmgEntry, Bmg_GetRawStringPointer_from_thumb(gWiFiAikotoba->mCommonMessages, 6));
            gWiFiAikotoba->mStateFrames = 0;
            return;
        }
        if (GetWiFiNextScene() == -1) {
            RequestWiFiState(gWiFiAikotoba->mPendingWiFiState);
        }
    }
}

void AdvanceWiFiAikotobaBuddyFullNotice(void) {
    void *questionText;
    void *yesText;

    if (TextSystem_IsDialogFinished_from_thumb() != 0 && IsSelectReturnHiddenNoRequest() != 0) {
        gWiFiAikotoba->mNextState = WIFI_AIKOTOBA_STATE_BUDDY_FULL_ASK;
        questionText = Bmg_GetRawStringPointer_from_thumb(gWiFiAikotoba->mWiFiMessages, 0x10);
        yesText = Bmg_GetRawStringPointer_from_thumb(gWiFiAikotoba->mCommonMessages, 0);
        SetupTxtSystemMainTextTwoButtons(questionText, yesText, Bmg_GetRawStringPointer_from_thumb(gWiFiAikotoba->mCommonMessages, 1), 0);
        return;
    }
    if (TextSystem_WasAnyDialogButtonPressed_from_thumb() != 0) {
        TextSystem_CloseDialog_from_thumb();
    }
}

void AdvanceWiFiAikotobaBuddyFullAsk(void) {
    if (TextSystem_IsDialogFinished_from_thumb() != 0) {
        if (TextSystem_IsButton2Focused_from_thumb() == 0) {
            gWiFiAikotoba->mPendingWiFiState = WIFI_STATE_SCENE_RECORD;
            if (GetWiFiNextScene() == -1) {
                SetWiFiNextScene(8);
            }
            g_GlobalB488->mWiFiScene8StartKind = 1;
            return;
        }
        gWiFiAikotoba->mNextState = WIFI_AIKOTOBA_STATE_SLIDE_IN;
        gWiFiAikotoba->mPendingWiFiState = WIFI_STATE_NONE;
        return;
    }
    if (TextSystem_WasAnyDialogButtonPressed_from_thumb() != 0) {
        TextSystem_CloseDialog_from_thumb();
    }
}

void UpdateWiFiAikotobaHighlight(void) {
    s32 rowIndex;

    for (rowIndex = 0; rowIndex < 2; rowIndex++) {
        if (rowIndex == gWiFiAikotoba->mSelectedIndex && gWiFiAikotoba->mHighlightVisible != FALSE) {
            gWiFiAikotoba->mWiFiAikotobaTable[gWiFiAikotobaSTableIndices[rowIndex]].mVisible = 1;
            SetCellPaletteIndex(gWiFiAikotobaCellIndices[rowIndex], 0xe, gWiFiAikotoba->mWiFiAikotobaSNcer,
                                gWiFiAikotoba->mWiFiAikotobaBncl);
        } else {
            gWiFiAikotoba->mWiFiAikotobaTable[gWiFiAikotobaSTableIndices[rowIndex]].mVisible = 0;
            SetCellPaletteIndex(gWiFiAikotobaCellIndices[rowIndex], 0xf, gWiFiAikotoba->mWiFiAikotobaSNcer,
                                gWiFiAikotoba->mWiFiAikotobaBncl);
        }
    }
}

void AdvanceWiFiAikotoba(void) {
    WiFiAikotoba *wiFiAikotoba;

    gWiFiAikotoba->mState = gWiFiAikotoba->mNextState;
    switch (gWiFiAikotoba->mState) {
        case WIFI_AIKOTOBA_STATE_WAIT_FADE:
            AdvanceWiFiAikotobaWaitFade();
            break;
        case WIFI_AIKOTOBA_STATE_SLIDE_IN:
            AdvanceWiFiAikotobaSlideIn();
            break;
        case WIFI_AIKOTOBA_STATE_WAIT_SELECT_RETURN:
            AdvanceWiFiAikotobaWaitSelectReturn();
            break;
        case WIFI_AIKOTOBA_STATE_INPUT:
            AdvanceWiFiAikotobaInput();
            break;
        case WIFI_AIKOTOBA_STATE_PRESS:
            AdvanceWiFiAikotobaPress();
            break;
        case WIFI_AIKOTOBA_STATE_SLIDE_OUT:
            AdvanceWiFiAikotobaSlideOut();
            break;
        case WIFI_AIKOTOBA_STATE_BUDDY_FULL_NOTICE:
            AdvanceWiFiAikotobaBuddyFullNotice();
            break;
        case WIFI_AIKOTOBA_STATE_BUDDY_FULL_ASK:
            AdvanceWiFiAikotobaBuddyFullAsk();
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
