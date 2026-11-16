#pragma once

#include "types.h"

#include "Main/Graphics/layout_rect_table.h"
#include "Main/Graphics/layout_entry_angle.h"

struct NNSG2dCellDataBank;
struct Ncgr;
struct Nclr;

// Values of WiFiTopMenu.mState: the menu fades in, slides in, waits for the return button, lets one of the three items
// be picked and slides out; WAIT_MESSAGE shows the message for a missing friend key; WAIT_CHOICE and WAIT_NEXT_SCENE
// are never entered.
enum {
    WIFI_TOP_MENU_STATE_WAIT_FADE,
    WIFI_TOP_MENU_STATE_SLIDE_IN,
    WIFI_TOP_MENU_STATE_WAIT_RETURN_BUTTON,
    WIFI_TOP_MENU_STATE_BROWSE,
    WIFI_TOP_MENU_STATE_PRESS_ITEM,
    WIFI_TOP_MENU_STATE_SLIDE_OUT,
    WIFI_TOP_MENU_STATE_WAIT_CHOICE,
    WIFI_TOP_MENU_STATE_WAIT_NOT_LOGGED_IN_THEN_TITLE,
    WIFI_TOP_MENU_STATE_WAIT_MESSAGE,
};

// Values of WiFiTopMenu.mIndex: the three items; VS leads to the VS setting (the login menu first when not logged in),
// AIKOTOBA to the aikotoba screen (a message instead when there is no friend key), DWC_UTILITY to the DWC utility run
// between two entries of the WiFi menu scene.
enum {
    WIFI_TOP_MENU_ITEM_VS,
    WIFI_TOP_MENU_ITEM_AIKOTOBA,
    WIFI_TOP_MENU_ITEM_DWC_UTILITY,
};

// Frames the three cell rows take to slide, the slide-in state lasts (the slide then settles with the press animation),
// the press state lasts, and the frame of it where the highlight shows again; the x offset of the cells while off
// screen.
#define WIFI_TOP_MENU_SLIDE_FRAMES 10
#define WIFI_TOP_MENU_SLIDE_IN_FRAMES 20
#define WIFI_TOP_MENU_PRESS_FRAMES 10
#define WIFI_TOP_MENU_PRESS_HIGHLIGHT_FRAMES 5
#define WIFI_TOP_MENU_OFFSET_HIDDEN 0xdc

// The Wi-Fi top menu screen: its state, selected index, heap, cell and layout tables and messages.
typedef struct WiFiTopMenu {
    /* 00 */ s32 mState;
    /* 04 */ u32 mNextState;
    /* 08 */ s32 mIndex;
    /* 0c */ s32 mStateFrames;
    /* 10 */ s32 mPendingWiFiState;
    /* 14 */ void *mHeap;
    /* 18 */ BOOL mHighlightVisible;
    // Table of cells built from the Bncl by InitLayoutTable.
    /* 1c */ LayoutTableEntry *mWiFiTopMenuTable;
    /* 20 */ struct NNSG2dCellDataBank *mWiFiTopMenuSNcer;
    /* 24 */ struct Ncgr *mWiFiTopMenuSNcgr;
    /* 28 */ struct Nclr *mWiFiTopMenuSONclr;
    /* 2c */ struct LayoutEntryTable *mWiFiTopMenuBncl;
    /* 30 */ LayoutEntryTable *mWiFiTopMenuBnbl;
    /* 34 */ u8 pad_34[4];
    /* 38 */ void *mWiFiMessages;
    /* 3c */ void *mCommonMessages;
} WiFiTopMenu;

#include "00/Menu/wi_fi_state_machine.h"
#include "00/Lib/wifi_library_globals.h"
#include "00/Menu/wi_fi_vs_setting.h"
#include "animation_data_unpack.h"
#include "Main/Graphics/font_and_player_character.h"
#include "Main/System/result_archive_path.h"

void RegisterWiFiTopMenuCallbacks(void);
void WriteWiFiTopMenuRegisters(void);
void AdvanceWiFiTopMenu(void);
void UpdateWiFiTopMenuHighlight(void);
void AdvanceWiFiTopMenuWaitMessage(void);
void AdvanceWiFiTopMenuWaitNextScene(void);
void AdvanceWiFiTopMenuWaitChoice(void);
void AdvanceWiFiTopMenuSlideOut(void);
void AdvanceWiFiTopMenuPressItem(void);
void AdvanceWiFiTopMenuWaitInput(void);
void AdvanceWiFiTopMenuWaitReturnButton(void);
void AdvanceWiFiTopMenuSlideIn(void);
void AdvanceWiFiTopMenuWaitFade(void);
s32 IsUserDataFriendKeyNonZeroWrapper(void);
void LocateAndQueueWiFiTopMenu(void);
void ClearWiFiTopMenuPointer(void);
void InitWiFiTopMenu(void *heap);

#include "00/Menu/wi_fi_vs_matching.h"

extern const u8 gWiFiTopMenuSTableIndices[3];
extern const u8 gWiFiTopMenuCellIndices[3];
extern const u8 gWiFiTopMenuXluCellIndices[3];
extern const s32 gWiFiTopMenuOffsetCellCounts[3];
extern const u8 gWiFiTopMenuOffsetTableIndices[3][5];
extern WiFiStateCallbacks gWiFiTopMenuCallbacks;
extern WiFiTopMenu *gWiFiTopMenu;
