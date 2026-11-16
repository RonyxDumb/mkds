#pragma once

#include "types.h"
#include "Main/Graphics/text_canvas.h"
#include "Main/Menu/wl_menu_scene.h"
#include "Main/Scene/run_scene_connection.h"

// Values of WLMenuMessage.mState; the multiboot child flow runs SETUP_MULTI_BOOT to WAIT_BACKUP, the others run
// RUN_MP_STATE_MACHINE to SET_NEXT_SCENE.
enum {
    WL_MENU_MESSAGE_STATE_SETUP_MULTI_BOOT = 0,
    WL_MENU_MESSAGE_STATE_CONNECT_MULTI_BOOT = 2,
    WL_MENU_MESSAGE_STATE_RUN_MP_WITH_OWN_INDEX = 4,
    WL_MENU_MESSAGE_STATE_WAIT_BACKUP = 6,
    WL_MENU_MESSAGE_STATE_RUN_MP_STATE_MACHINE = 9,
    WL_MENU_MESSAGE_STATE_SET_NEXT_SCENE = 10,
    WL_MENU_MESSAGE_STATE_DONE = 11,
};

// The WL menu message box: its font, char canvas, text canvas, screen map, message files, BG3 offset, state and heap.
typedef struct WLMenuMessage {
    /* 000 */ void *mFont;
    /* 004 */ u8 mCharCanvas[0x20];
    /* 024 */ TextCanvas mTextCanvas;
    /* 034 */ u16 mScreenMap[0x300];
    /* 634 */ void *mCommonMessages;
    /* 638 */ struct Bmg *mMBChildMessages;
    /* 63c */ u8 mUnk_63c[4];
    /* 640 */ s32 mBg3Offset;
    /* 644 */ u8 mUnk_644[8];
    /* 64c */ s32 mState;
    /* 650 */ void *mHeap;
} WLMenuMessage;

void WriteWLMenuMessageRegistersWrapper(void);
void WriteWLMenuMessageRegisters(void);
void WLMenuMessageG2S_SetBG3Offset(u32 offsetX, int offsetY);
void WLMenuMessageGXS_SetVisiblePlane(int bits);
void ReleaseWLMenuMessage(void);
s32 AdvanceWLMenuMessageToMenu(SceneNumbers *sceneNumbers);
void SetNextScene(SceneNumbers *sceneNumbers, unsigned int nextScene);
void StopSeqZeroLoopWrapper(void);
u32 HasGroupSendMask(void);
s32 AdvanceWLMenuMessageToResult(SceneNumbers *sceneNumbers);
s32 AdvanceWLMenuMessageToRace(SceneNumbers *sceneNumbers);
s32 AdvanceWLMenuMBChildMessage(SceneNumbers *sceneNumbers);
void WLMenuSetMenuEntryKind(unsigned int value);
void WLMenuSetRaceSetupRequested(unsigned int value);

extern struct WLMenuCallbacks gWLMenuMessageToResultCallbacks;
extern struct WLMenuCallbacks gWLMenuMBChildMessageCallbacks;
extern struct WLMenuCallbacks gWLMenuMessageToMenuCallbacks;
extern struct WLMenuCallbacks gWLMenuMessageToRaceCallbacks;
