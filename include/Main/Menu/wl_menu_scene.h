#pragma once

#include "types.h"

struct WLMenuScene;

// The four functions of a Wi-Fi menu screen: init, advance, release and write registers.
typedef struct WLMenuCallbacks {
    /* 00 */ void (*mInit)();
    /* 04 */ s32 (*mAdvance)();
    /* 08 */ void (*mRelease)(void);
    /* 0c */ void (*mWriteRegisters)(void);
} WLMenuCallbacks;

// The text of one scan slot: ten characters and a terminator.
typedef struct ScanSlotText {
    /* 00 */ u16 mText[0xa];
    /* 14 */ u16 mTerminator;
} ScanSlotText;

// The scan slot picked in the WiFi menu: mSlotIndex and the text of each of the four slots (mSlotTexts).
typedef struct WLMenuScanSlotPick {
    /* 00 */ s32 mSlotIndex;
    /* 04 */ ScanSlotText mSlotTexts[4];
} WLMenuScanSlotPick;

// Indices of gWLMenuCallbacks, which WLMenuScene.mRequestedCallbacksIndex holds.
#define WL_MENU_CALLBACKS_MEMBER_GROUP 0
#define WL_MENU_CALLBACKS_MULTI_SELECT_NS 1
#define WL_MENU_CALLBACKS_MEMBER_KEY_START 2
#define WL_MENU_CALLBACKS_MEMBER_NO_KEY_START 3
#define WL_MENU_CALLBACKS_MB_CHILD_MESSAGE 4
#define WL_MENU_CALLBACKS_MESSAGE_TO_RACE 5
#define WL_MENU_CALLBACKS_MESSAGE_TO_RESULT 6
#define WL_MENU_CALLBACKS_MESSAGE_TO_MENU 7
#define WL_MENU_CALLBACKS_COUNT 8

// The Wi-Fi menu scene: its two OAM buffers, heap, the callbacks of the current screen and the scan slot pick.
typedef struct WLMenuScene {
    /* 000 */ u8 mMainOam[0x404];
    /* 404 */ u8 mSubOam[0x404];
    /* 808 */ void *mHeap;
    /* 80c */ WLMenuCallbacks *mCurrentCallbacks;
    /* 810 */ s32 mRequestedCallbacksIndex;
    /* 814 */ s32 mCurrentCallbacksIndex;
    /* 818 */ WLMenuScanSlotPick mScanSlotPick;
} WLMenuScene;

WLMenuScanSlotPick *GetWLMenuSceneScanSlotPick(void);
void WriteWLMenuSceneRegisters(void);
u32 WLMenuMB_IsMultiBootChildWrapper(void);
u32 WLMenuMB_IsMultiBootChild(void);
u16 *WLMenuMB_GetMultiBootParam(void);
void ReleaseWLMenuScene(void);
void AdvanceWLMenuScene(void *sceneNumbers);
void InitWLMenuScene(void *heap);
void WLMenuGXS_SetOBJVRamModeChar(u32 bits);
void WLMenuGX_SetOBJVRamModeChar(u32 bits);

extern struct WLMenuCallbacks *gWLMenuCallbacks[WL_MENU_CALLBACKS_COUNT];
extern struct WLMenuScene *gWLMenuScene;

