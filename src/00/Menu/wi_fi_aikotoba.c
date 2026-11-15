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

    gWiFiAikotoba = HeapAlloc(heap, 0x40);
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
        SetCellOamModeXlu(gWiFiAikotobaXluCellIndices[index], 1, gWiFiAikotoba->mWiFiAikotobaSNcer,
                          gWiFiAikotoba->mWiFiAikotobaBncl);
    }
    oamList = GetWiFiMenuMainOamList();
    ResetOamLists(oamList, GetWiFiMenuSubOamList());
    InitLayoutTable(heap, gWiFiAikotoba->mWiFiAikotobaBncl, NULL, &gWiFiAikotoba->mWiFiAikotobaTable);
    gWiFiAikotoba->mWiFiMessages = FindSceneFile("wifi.bmg");
    gWiFiAikotoba->mCommonMessages = FindFileInLoadedArchives("common.bmg");
    for (index = 0; index < 2; index++) {
        for (cellIndex = 0; cellIndex < gWiFiAikotobaOffsetCellCounts[index]; cellIndex++) {
            gWiFiAikotoba->mWiFiAikotobaTable[gWiFiAikotobaOffsetTableIndices[index][cellIndex]].mOffsetX = 0xfa;
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

void AdvanceWiFiAikotobaWaitFade(void) {
    int fadesClear;
    fadesClear = AreBrightnessFadesClear();
    if (fadesClear != 0) {
        gWiFiAikotoba->mNextState = WIFI_AIKOTOBA_STATE_SLIDE_IN;
    }
}

void AdvanceWiFiAikotobaSlideIn(void) {
    s32 offsetX;
    s32 rowIndex;
    s32 cellIndex;

    gWiFiAikotoba->mStateFrames = gWiFiAikotoba->mStateFrames + 1;
    offsetX = InterpolateS16(1, 0xfa, 0, gWiFiAikotoba->mStateFrames, 10);
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
    if (gWiFiAikotoba->mStateFrames >= 10) {
        gWiFiAikotoba->mNextState = WIFI_AIKOTOBA_STATE_WAIT_SELECT_RETURN;
        gWiFiAikotoba->mStateFrames = 0;
        RequestSelectReturnSlideIn();
    }
}

void AdvanceWiFiAikotobaWaitSelectReturn(void) {
    int returnState2NoRequest;
    returnState2NoRequest = IsSelectReturnShownNoRequest();
    if (returnState2NoRequest != 0) {
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
            IsSelectReturnShownNoRequestAndInRect(gInputSlots[slotIndex].mPair.mPairX,
                                                  gInputSlots[slotIndex].mPair.mPairY) == FALSE) {
            goto next;
        }
    }
    gWiFiAikotoba->mNextState = WIFI_AIKOTOBA_STATE_SLIDE_OUT;
    gWiFiAikotoba->mPendingWiFiState = WIFI_STATE_TOP_MENU;
    RequestSelectReturnPressWithSound(0);
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

void AdvanceWiFiAikotobaPress(void) {
    gWiFiAikotoba->mStateFrames = gWiFiAikotoba->mStateFrames + 1;
    if (gWiFiAikotoba->mStateFrames >= 10) {
        gWiFiAikotoba->mNextState = WIFI_AIKOTOBA_STATE_SLIDE_OUT;
        if (gWiFiAikotoba->mPendingWiFiState == WIFI_STATE_SCENE_KEYBOARD) {
            RequestSelectReturnSlideOut();
        }
        gWiFiAikotoba->mStateFrames = 0;
    } else if (gWiFiAikotoba->mStateFrames >= 5) {
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
    if (gWiFiAikotoba->mStateFrames <= 10) {
        offsetX = InterpolateS16(1, 0, 0xfa, gWiFiAikotoba->mStateFrames, 10);
    } else {
        offsetX = 0xfa;
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
    if (gWiFiAikotoba->mStateFrames >= 10) {
        if (IsBuddyRecordBlockFull() != 0 && gWiFiAikotoba->mPendingWiFiState == WIFI_STATE_SCENE_KEYBOARD) {
            gWiFiAikotoba->mNextState = WIFI_AIKOTOBA_STATE_BUDDY_FULL_NOTICE;
            gWiFiAikotoba->mPendingWiFiState = WIFI_STATE_NONE;
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

void AdvanceWiFiAikotobaBuddyFullNotice(void) {
    void *questionText;
    void *yesText;

    if (IsTxtSystemClosedNoOpenRequest() != 0 && IsSelectReturnHiddenNoRequest() != 0) {
        gWiFiAikotoba->mNextState = WIFI_AIKOTOBA_STATE_BUDDY_FULL_ASK;
        questionText = GetBmgEntry(gWiFiAikotoba->mWiFiMessages, 0x10);
        yesText = GetBmgEntry(gWiFiAikotoba->mCommonMessages, 0);
        SetupTxtSystemMainTextTwoButtons(questionText, yesText, GetBmgEntry(gWiFiAikotoba->mCommonMessages, 1), 0);
        return;
    }
    if (GetTxtSystemDone() != 0) {
        RequestTxtSystemClose();
    }
}

void AdvanceWiFiAikotobaBuddyFullAsk(void) {
    if (IsTxtSystemClosedNoOpenRequest() != 0) {
        if (GetTxtSystemSelectedIndex() == 0) {
            gWiFiAikotoba->mPendingWiFiState = WIFI_STATE_SCENE_RECORD;
            if (GetWiFiNextScene() == -1) {
                SetWiFiNextScene(8);
            }
            gMenuShared->mWiFiScene8StartKind = 1;
            return;
        }
        gWiFiAikotoba->mNextState = WIFI_AIKOTOBA_STATE_SLIDE_IN;
        gWiFiAikotoba->mPendingWiFiState = WIFI_STATE_NONE;
        return;
    }
    if (GetTxtSystemDone() != 0) {
        RequestTxtSystemClose();
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
