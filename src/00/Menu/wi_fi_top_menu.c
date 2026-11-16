#include "00/Menu/wi_fi_top_menu.h"
#include "registers.h"
#include "Main/Save/ghost_file_records.h"
#include "01/Menu/record_time_attack.h"
#include "01/Menu/record_time_attack_requests.h"
#include "Main/Graphics/oam.h"
#include "Main/Sound/sound_init_scene_sounds_and_screen_seqs.h"
#include "Main/Scene/display_settings.h"
#include "00/Lib/NitroWiFi/access_point_search_defaults.h"
#include "Main/System/result_archive_path.h"
#include "Main/System/heap.h"
#include "Main/Graphics/oam_lists.h"
#include "Main/Net/led_pattern.h"
#include "Main/Menu/message_screen.h"

#include "00/Menu/wi_fi_state_machine.h"
#include "00/Scene/wi_fi_menu_scene.h"
#include "Main/Graphics/layout_entry_angle.h"
#include "Main/Graphics/layout_table_entry.h"
#include "Main/Menu/txt_system.h"
#include "Main/Menu/select_return.h"
#include "Main/System/input_slots.h"
#include "sound_player_control.h"
#include "sound_archive_load_result.h"
#include "display_blend_affine_setup.h"
#include "00/Lib/wifi_library_globals.h"
#include "Main/Graphics/locate_bmg_sections.h"
#include "Main/Net/wifi_session_login.h"
#include "Main/Scene/scene_display_archive_work.h"
#include "archive_memory_load.h"
#include "heap_frame_allocator.h"
#include "thread_scheduler.h"
#include "Main/MapObjects/map_object_park.h"
#include "power_management_commands.h"
#include "Main/Sound/sound_system.h"
#include "Main/System/init_after_startup.h"

const u8 gWiFiTopMenuSTableIndices[3] = {6, 7, 8};
const u8 gWiFiTopMenuCellIndices[3] = {9, 0xa, 0xb};
const u8 gWiFiTopMenuXluCellIndices[3] = {0, 1, 2};
const s32 gWiFiTopMenuOffsetCellCounts[3] = {5, 4, 5};
const u8 gWiFiTopMenuOffsetTableIndices[3][5] = {{0, 3, 6, 9, 0xc}, {1, 4, 7, 0xa, 0}, {2, 5, 8, 0xb, 0xd}};
WiFiStateCallbacks gWiFiTopMenuCallbacks = {InitWiFiTopMenu, ClearWiFiTopMenuPointer, AdvanceWiFiTopMenu,
                                            WriteWiFiTopMenuRegisters};
WiFiTopMenu *gWiFiTopMenu;

void InitWiFiTopMenu(void *heap) {
    s32 index;
    s32 rowIndex;
    s32 cellIndex;

    gWiFiTopMenu = HeapAlloc(heap, sizeof(WiFiTopMenu));
    gWiFiTopMenu->mHeap = heap;
    gWiFiTopMenu->mState = WIFI_TOP_MENU_STATE_WAIT_FADE;
    gWiFiTopMenu->mNextState = WIFI_TOP_MENU_STATE_WAIT_FADE;
    gWiFiTopMenu->mPendingWiFiState = WIFI_STATE_NONE;
    switch (GetWiFiPrevState()) {
        case WIFI_STATE_LOGIN_MENU:
        case WIFI_STATE_VS_SETTING:
            gWiFiTopMenu->mIndex = WIFI_TOP_MENU_ITEM_VS;
            break;
        case WIFI_STATE_AIKOTOBA:
            gWiFiTopMenu->mIndex = WIFI_TOP_MENU_ITEM_AIKOTOBA;
            break;
        case WIFI_STATE_SCENE_WIFI_MENU:
            gWiFiTopMenu->mIndex = WIFI_TOP_MENU_ITEM_DWC_UTILITY;
            break;
    }
    gWiFiTopMenu->mStateFrames = 0;
    gWiFiTopMenu->mHighlightVisible = TRUE;
    gWiFiTopMenu->mWiFiMessages = FindSceneFile("wifi.bmg");
    gWiFiTopMenu->mCommonMessages = FindFileInLoadedArchives("common.bmg");
    LocateAndQueueWiFiTopMenu();
    for (index = 0; index < 3; index++) {
        SetCellOamModeXlu(gWiFiTopMenuXluCellIndices[index], 1, gWiFiTopMenu->mWiFiTopMenuSNcer,
                          gWiFiTopMenu->mWiFiTopMenuBncl);
    }
    ResetOamLists(GetWiFiMenuMainOamList(), GetWiFiMenuSubOamList());
    InitLayoutTable(heap, gWiFiTopMenu->mWiFiTopMenuBncl, NULL, &gWiFiTopMenu->mWiFiTopMenuTable);
    for (rowIndex = 0; rowIndex < 3; rowIndex++) {
        for (cellIndex = 0; cellIndex < gWiFiTopMenuOffsetCellCounts[rowIndex]; cellIndex++) {
            gWiFiTopMenu->mWiFiTopMenuTable[gWiFiTopMenuOffsetTableIndices[rowIndex][cellIndex]].mOffsetX =
                WIFI_TOP_MENU_OFFSET_HIDDEN;
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
    sceneFile = FindSceneFile("WiFi_top_menu_s.bncl");
    gWiFiTopMenu->mWiFiTopMenuBncl = sceneFile;
    sceneFile = FindSceneFile("WiFi_top_menu_s.bnbl");
    gWiFiTopMenu->mWiFiTopMenuBnbl = sceneFile;
    sceneFile = FindSceneFile("WiFi_top_menu_s.nce.ncgr");
    LocateNcgr2(&gWiFiTopMenu->mWiFiTopMenuSNcgr, sceneFile);
    sceneFile = FindSceneFile("WiFi_top_menu_s.nce.ncer");
    LocateNcer(&gWiFiTopMenu->mWiFiTopMenuSNcer, sceneFile);
    sceneFile = FindSceneFile("WiFi_top_menu_s_o.nclr");
    LocateNclr(&gWiFiTopMenu->mWiFiTopMenuSONclr, sceneFile);
    NNS_GfdRegisterNewVramTransferTask(0x23, 0, (gWiFiTopMenu->mWiFiTopMenuSNcgr->mData),
                                       gWiFiTopMenu->mWiFiTopMenuSNcgr->mDataSize);
    NNS_GfdRegisterNewVramTransferTask(0x1e, 0, (gWiFiTopMenu->mWiFiTopMenuSONclr->mData),
                                       gWiFiTopMenu->mWiFiTopMenuSONclr->mDataSize);
}

s32 IsUserDataFriendKeyNonZeroWrapper(void) {
    return IsUserDataFriendKeyNonZero();
}

void AdvanceWiFiTopMenuWaitFade(void) {
    int fadesClear;
    fadesClear = AreBrightnessFadesClear();
    if (fadesClear != 0) {
        gWiFiTopMenu->mNextState = WIFI_TOP_MENU_STATE_SLIDE_IN;
    }
}

void AdvanceWiFiTopMenuSlideIn(void) {
    s32 offsetX = 0;
    s32 rowIndex;
    s32 cellIndex;

    gWiFiTopMenu->mStateFrames = gWiFiTopMenu->mStateFrames + 1;
    if (gWiFiTopMenu->mStateFrames >= WIFI_TOP_MENU_SLIDE_IN_FRAMES) {
        gWiFiTopMenu->mNextState = WIFI_TOP_MENU_STATE_WAIT_RETURN_BUTTON;
        gWiFiTopMenu->mStateFrames = offsetX;
        RequestSelectReturnSlideIn();
    } else if (gWiFiTopMenu->mStateFrames >= WIFI_TOP_MENU_SLIDE_FRAMES) {
        offsetX = GetSelectedPressOffset(gWiFiTopMenu->mStateFrames - WIFI_TOP_MENU_SLIDE_FRAMES);
    } else {
        offsetX = InterpolateS16(1, WIFI_TOP_MENU_OFFSET_HIDDEN, offsetX, gWiFiTopMenu->mStateFrames,
                                 WIFI_TOP_MENU_SLIDE_FRAMES);
    }
    for (rowIndex = 0; rowIndex < 3; rowIndex++) {
        for (cellIndex = 0; cellIndex < gWiFiTopMenuOffsetCellCounts[rowIndex]; cellIndex++) {
            gWiFiTopMenu->mWiFiTopMenuTable[gWiFiTopMenuOffsetTableIndices[rowIndex][cellIndex]].mOffsetX = offsetX;
        }
    }
}

void AdvanceWiFiTopMenuWaitReturnButton(void) {
    int returnShownNoRequest;
    returnShownNoRequest = IsSelectReturnShownNoRequest();
    if (returnShownNoRequest != 0) {
        gWiFiTopMenu->mNextState = WIFI_TOP_MENU_STATE_BROWSE;
        SetSelectReturnSoundId(0xf);
    }
}

void AdvanceWiFiTopMenuWaitInput(void) {
    InputSlotIndex slotIndex = INPUT_SLOT_PAD_OR_PARTICIPANT;
    BOOL pairNewUnlessRecentlyLost = FALSE;
    u32 hitIndex = -1;
    BOOL pairRecentlyLost = FALSE;
    s32 previousIndex;
    s32 pressedKeys;
    BOOL returnPairNewUnlessRecentlyLost;
    s32 returnPairRecentlyLost;

    if (gInputSlots[slotIndex].mPair.mHasPair == 0 &&
        gInputSlots[slotIndex].mPair.mNoPairCount < INPUT_NO_PAIR_BRIEF_FRAMES) {
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
    gWiFiTopMenu->mNextState = WIFI_TOP_MENU_STATE_SLIDE_OUT;
    gWiFiTopMenu->mPendingWiFiState = WIFI_STATE_SCENE_TITLE;
    if (gWiFiTopMenu->mPendingWiFiState == WIFI_STATE_SCENE_TITLE) {
        RequestSelectReturnPressWithSound(1);
    }
    return;
next:
    pressedKeys = gInputSlots[slotIndex].mPressedBits & PAD_KEY_A;
    if ((u16) pressedKeys != 0 || hitIndex <= 2) {
        previousIndex = gWiFiTopMenu->mIndex;
        if ((u16) pressedKeys == 0) {
            switch (hitIndex) {
                case WIFI_TOP_MENU_ITEM_VS:
                    gWiFiTopMenu->mIndex = WIFI_TOP_MENU_ITEM_VS;
                    break;
                case WIFI_TOP_MENU_ITEM_AIKOTOBA:
                    gWiFiTopMenu->mIndex = WIFI_TOP_MENU_ITEM_AIKOTOBA;
                    break;
                case WIFI_TOP_MENU_ITEM_DWC_UTILITY:
                    gWiFiTopMenu->mIndex = WIFI_TOP_MENU_ITEM_DWC_UTILITY;
                    break;
            }
        }
        if (gWiFiTopMenu->mIndex == previousIndex) {
            gWiFiTopMenu->mHighlightVisible = FALSE;
        }
        gWiFiTopMenu->mNextState = WIFI_TOP_MENU_STATE_PRESS_ITEM;
        switch (gWiFiTopMenu->mIndex) {
            case WIFI_TOP_MENU_ITEM_VS:
                if (GetWiFiSessionLoginResult() == 1) {
                    gWiFiTopMenu->mPendingWiFiState = WIFI_STATE_VS_SETTING;
                } else {
                    gWiFiTopMenu->mPendingWiFiState = WIFI_STATE_LOGIN_MENU;
                }
                break;
            case WIFI_TOP_MENU_ITEM_AIKOTOBA:
                gWiFiTopMenu->mPendingWiFiState = WIFI_STATE_AIKOTOBA;
                break;
            case WIFI_TOP_MENU_ITEM_DWC_UTILITY:
                gWiFiTopMenu->mPendingWiFiState = WIFI_STATE_SCENE_WIFI_MENU;
                break;
        }
        StartSoundOncePerFrame(5);
    } else {
        if (GetNewOrRepeatBits(8, PAD_KEY_DIRECTION_UP) != 0) {
            gWiFiTopMenu->mIndex--;
            if (gWiFiTopMenu->mIndex < 0) {
                gWiFiTopMenu->mIndex = WIFI_TOP_MENU_ITEM_DWC_UTILITY;
            }
            StartSoundOncePerFrame(0);
        } else if (GetNewOrRepeatBits(8, PAD_KEY_DIRECTION_DOWN) != 0) {
            gWiFiTopMenu->mIndex++;
            if (gWiFiTopMenu->mIndex > WIFI_TOP_MENU_ITEM_DWC_UTILITY) {
                gWiFiTopMenu->mIndex = WIFI_TOP_MENU_ITEM_VS;
            }
            StartSoundOncePerFrame(0);
        }
    }
}

void AdvanceWiFiTopMenuPressItem(void) {
    s32 cellIndex;
    s32 selectedPressOffset;

    gWiFiTopMenu->mStateFrames = gWiFiTopMenu->mStateFrames + 1;
    selectedPressOffset = GetSelectedPressOffset(gWiFiTopMenu->mStateFrames);
    for (cellIndex = 0; cellIndex < gWiFiTopMenuOffsetCellCounts[gWiFiTopMenu->mIndex]; cellIndex++) {
        gWiFiTopMenu->mWiFiTopMenuTable[gWiFiTopMenuOffsetTableIndices[gWiFiTopMenu->mIndex][cellIndex]].mOffsetX =
            selectedPressOffset;
    }
    if (gWiFiTopMenu->mStateFrames >= WIFI_TOP_MENU_PRESS_FRAMES) {
        gWiFiTopMenu->mNextState = WIFI_TOP_MENU_STATE_SLIDE_OUT;
        if (gWiFiTopMenu->mIndex == WIFI_TOP_MENU_ITEM_VS || gWiFiTopMenu->mIndex == WIFI_TOP_MENU_ITEM_DWC_UTILITY) {
            RequestSelectReturnSlideOut();
        }
        gWiFiTopMenu->mStateFrames = 0;
    } else if (gWiFiTopMenu->mStateFrames >= WIFI_TOP_MENU_PRESS_HIGHLIGHT_FRAMES) {
        gWiFiTopMenu->mHighlightVisible = TRUE;
    }
}

void AdvanceWiFiTopMenuSlideOut(void) {
    s32 rowIndex;
    s32 cellIndex;
    s32 offsetX;
    if (GetWiFiNextScene() == -1) {
        if (gWiFiTopMenu->mPendingWiFiState == WIFI_STATE_SCENE_TITLE && GetWiFiSessionLoginResult() != 1) {
            SetWiFiNextScene(0);
        } else if (gWiFiTopMenu->mPendingWiFiState == WIFI_STATE_SCENE_WIFI_MENU) {
            gStartupWork->mConnectionKind = CONNECTION_KIND_WIFI_TOP_MENU;
            SetWiFiNextScene(12);
        }
    }
    gWiFiTopMenu->mStateFrames++;
    offsetX = gWiFiTopMenu->mStateFrames;
    if (offsetX <= WIFI_TOP_MENU_SLIDE_FRAMES) {
        offsetX = InterpolateS16(1, WIFI_TOP_MENU_OFFSET_HIDDEN, 0, WIFI_TOP_MENU_SLIDE_FRAMES - offsetX,
                                 WIFI_TOP_MENU_SLIDE_FRAMES);
    } else {
        offsetX = WIFI_TOP_MENU_OFFSET_HIDDEN;
    }
    for (rowIndex = 0; rowIndex < 3; rowIndex++) {
        for (cellIndex = 0; cellIndex < gWiFiTopMenuOffsetCellCounts[rowIndex]; cellIndex++) {
            gWiFiTopMenu->mWiFiTopMenuTable[gWiFiTopMenuOffsetTableIndices[rowIndex][cellIndex]].mOffsetX = offsetX;
        }
    }
    if (gWiFiTopMenu->mStateFrames >= WIFI_TOP_MENU_SLIDE_FRAMES) {
        if ((gWiFiTopMenu->mPendingWiFiState == WIFI_STATE_SCENE_TITLE ||
             gWiFiTopMenu->mPendingWiFiState == WIFI_STATE_SCENE_WIFI_MENU) &&
            IsSelectReturnHiddenNoSlideInRequest() == 0) {
            return;
        }
        if (GetWiFiNextScene() == -1) {
            if (gWiFiTopMenu->mPendingWiFiState == WIFI_STATE_AIKOTOBA && IsUserDataFriendKeyNonZeroWrapper() == 0) {
                gWiFiTopMenu->mNextState = WIFI_TOP_MENU_STATE_WAIT_MESSAGE;
                gWiFiTopMenu->mPendingWiFiState = WIFI_STATE_NONE;
                SetupTxtSystemMainText(GetBmgEntry(gWiFiTopMenu->mWiFiMessages, 0x12));
                gWiFiTopMenu->mStateFrames = 0;
                SetSelectReturnSoundId(0xe);
                return;
            }
            RequestWiFiState(gWiFiTopMenu->mPendingWiFiState);
        }
    }
}

void AdvanceWiFiTopMenuWaitChoice(void) {
    int queryResult;
    queryResult = GetTxtSystemDone();
    if (queryResult != 0) {
        RequestTxtSystemClose();
        return;
    }
    queryResult = IsTxtSystemClosedNoOpenRequest();
    if (queryResult != 0) {
        queryResult = GetTxtSystemSelectedIndex();
        if (queryResult == 0) {
            ReleaseWiFiSession();
            gWiFiTopMenu->mNextState = WIFI_TOP_MENU_STATE_WAIT_NOT_LOGGED_IN_THEN_TITLE;
            return;
        }
        gWiFiTopMenu->mNextState = WIFI_TOP_MENU_STATE_SLIDE_IN;
    }
}

void AdvanceWiFiTopMenuWaitNextScene(void) {
    int queryResult;
    queryResult = GetWiFiNextScene();
    if ((queryResult == -1) && (gWiFiTopMenu->mPendingWiFiState == WIFI_STATE_SCENE_TITLE)) {
        SetWiFiNextScene(0);
    }
    queryResult = GetWiFiSessionLoginResult();
    if (queryResult != 1) {
        gWiFiTopMenu->mPendingWiFiState = WIFI_STATE_SCENE_TITLE;
    }
}

void AdvanceWiFiTopMenuWaitMessage(void) {
    InputSlotIndex slotIndex = INPUT_SLOT_PAD_OR_PARTICIPANT;
    s32 pairRecentlyLost;
    BOOL pairNewUnlessRecentlyLost;
    u32 hasPair;
    if (IsTxtSystemOpenAfterOpening() != 0) {
        NNS_SndArcPlayerStartSeqArc(&gSharedSeqHandle, 0, 0x15);
    }
    if (IsTxtSystemOpenNoCloseRequest() != 0 && IsSelectReturnShownNoRequest() != 0) {
        if ((u16) (gInputSlots[slotIndex].mPressedBits & PAD_KEY_B) == 0) {
            pairRecentlyLost = pairNewUnlessRecentlyLost = FALSE;
            hasPair = gInputSlots[slotIndex].mPair.mHasPair;
            if (hasPair == 0 && gInputSlots[slotIndex].mPair.mNoPairCount < INPUT_NO_PAIR_BRIEF_FRAMES) {
                pairRecentlyLost = 1;
            }
            if (pairRecentlyLost == 0 && gInputSlots[slotIndex].mPair.mPrevHasPair == 0 && hasPair != 0) {
                pairNewUnlessRecentlyLost = TRUE;
            }
            if (pairNewUnlessRecentlyLost == FALSE ||
                IsSelectReturnShownNoRequestAndInRect(gInputSlots[slotIndex].mPair.mPairX,
                                                      gInputSlots[slotIndex].mPair.mPairY) == FALSE) {
                return;
            }
        }
        gWiFiTopMenu->mNextState = WIFI_TOP_MENU_STATE_SLIDE_IN;
        RequestSelectReturnPressWithSound(0);
        RequestTxtSystemClose();
    }
}

void UpdateWiFiTopMenuHighlight(void) {
    s32 rowIndex = 0;
    BOOL hidden = FALSE;
    const u8 *tableIndexPointer = gWiFiTopMenuSTableIndices;
    const u8 *cellIndexPointer = gWiFiTopMenuCellIndices;
    for (; rowIndex < 3; rowIndex++) {
        if (rowIndex == gWiFiTopMenu->mIndex && gWiFiTopMenu->mHighlightVisible != FALSE) {
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
        case WIFI_TOP_MENU_STATE_WAIT_FADE:
            AdvanceWiFiTopMenuWaitFade();
            break;
        case WIFI_TOP_MENU_STATE_SLIDE_IN:
            AdvanceWiFiTopMenuSlideIn();
            break;
        case WIFI_TOP_MENU_STATE_WAIT_RETURN_BUTTON:
            AdvanceWiFiTopMenuWaitReturnButton();
            break;
        case WIFI_TOP_MENU_STATE_BROWSE:
            AdvanceWiFiTopMenuWaitInput();
            break;
        case WIFI_TOP_MENU_STATE_PRESS_ITEM:
            AdvanceWiFiTopMenuPressItem();
            break;
        case WIFI_TOP_MENU_STATE_SLIDE_OUT:
            AdvanceWiFiTopMenuSlideOut();
            break;
        case WIFI_TOP_MENU_STATE_WAIT_CHOICE:
            AdvanceWiFiTopMenuWaitChoice();
            break;
        case WIFI_TOP_MENU_STATE_WAIT_NOT_LOGGED_IN_THEN_TITLE:
            AdvanceWiFiTopMenuWaitNextScene();
            break;
        case WIFI_TOP_MENU_STATE_WAIT_MESSAGE:
            AdvanceWiFiTopMenuWaitMessage();
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
