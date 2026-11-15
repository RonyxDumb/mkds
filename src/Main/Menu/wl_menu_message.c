#include "Main/Menu/wl_menu_message.h"
#include "Main/Menu/wl_menu_mb_child_message.h"

#include "registers.h"
#include "Main/System/heap.h"
#include "Main/Sound/sound_seq.h"
#include "Main/Net/mp_state_machine.h"
#include "Main/Menu/data_02174000.h"
#include "Main/System/interpolation_value.h"
#include "Main/System/heap_call.h"
#include "code_02022aa8.h"
#include "Main/Graphics/cell_file_set.h"
#include "Main/Graphics/font_and_player_character.h"
#include "Main/Graphics/layout_entry_angle.h"
#include "Main/Graphics/locate_bmg_sections.h"
#include "Main/Menu/multi_select_member_group.h"
#include "tp.h"
#include "Main/Save/buddy_record_time.h"
#include "g2d_CellTransferManager.h"
#include "Main/Save/backup_command.h"
#include "Main/Menu/wl_menu_common_message.h"
#include "Main/Graphics/disp_cap.h"
#include "Main/Net/mp_states_connection.h"
#include "Main/MapObjects/data_0217a000.h"
#include "Main/Net/mp_state.h"
#include "Main/System/key_recording_buffer.h"
#include "Main/Save/emblem_block.h"
#include "00/Menu/wi_fi_vs_setting.h"
#include "Main/Menu/time_attack_ghost_get_scan.h"
#include "Main/Menu/menu_shared_clear.h"

struct WLMenuCallbacks gWLMenuMessageToResultCallbacks = {SetupWLMenuCommonMessage, AdvanceWLMenuMessageToResult,
                                                          ReleaseWLMenuMessage, WriteWLMenuMessageRegisters};
struct WLMenuCallbacks gWLMenuMBChildMessageCallbacks = {SetupWLMenuMBChildMessage, AdvanceWLMenuMBChildMessage,
                                                         ReleaseWLMenuMessage, WriteWLMenuMessageRegistersWrapper};
struct WLMenuCallbacks gWLMenuMessageToMenuCallbacks = {SetupWLMenuCommonMessage, AdvanceWLMenuMessageToMenu,
                                                        ReleaseWLMenuMessage, WriteWLMenuMessageRegisters};
struct WLMenuCallbacks gWLMenuMessageToRaceCallbacks = {SetupWLMenuCommonMessage, AdvanceWLMenuMessageToRace,
                                                        ReleaseWLMenuMessage, WriteWLMenuMessageRegisters};

void WLMenuSetRaceSetupRequested(u32 value) {
    gMenuShared->mRaceSetupRequested = value;
}

void WLMenuSetMenuEntryKind(u32 value) {
    gMenuShared->mMenuEntryKind = value;
}

#pragma thumb on

s32 AdvanceWLMenuMBChildMessage(SceneNumbers *sceneNumbers) {
    s32 result;
    WLMenuMessage *wlMenuMessage;

    switch (gWLMenuMessage->mState) {
        case WL_MENU_MESSAGE_STATE_SETUP_MULTI_BOOT:
            if (AdvanceSetupByMultiBoot(0, 1) == 1) {
                gWLMenuMessage->mState = WL_MENU_MESSAGE_STATE_CONNECT_MULTI_BOOT;
            }
            break;
        case WL_MENU_MESSAGE_STATE_CONNECT_MULTI_BOOT:
            result = AdvanceConnectByMultiBoot(0);
            switch (result) {
                case 1:
                    SetMultiSimple(WLMenuIsMultiBootSetupStarted());
                    gWLMenuMessage->mState = WL_MENU_MESSAGE_STATE_RUN_MP_WITH_OWN_INDEX;
                    break;
                case 2:
                    break;
            }
            break;
        case WL_MENU_MESSAGE_STATE_RUN_MP_WITH_OWN_INDEX:
            result = AdvanceMPStateMachineWithOwnIndex();
            switch (result) {
                case 1:
                    if (HasGroupSendMask() != 0) {
                        StopSeqZeroLoopWrapper();
                    }
                    StartCopyOtherEmblems(1);
                    gWLMenuMessage->mState = WL_MENU_MESSAGE_STATE_WAIT_BACKUP;
                    break;
                case 2:
                    break;
            }
            break;
        case WL_MENU_MESSAGE_STATE_WAIT_BACKUP:
            if (IsBackupBusy() == 0) {
                WLMenuSetRaceSetupRequested(1);
                WLMenuSetMenuEntryKind(4);
                if (sceneNumbers != 0) {
                    SetNextScene(sceneNumbers, 1);
                }
                gWLMenuMessage->mState = WL_MENU_MESSAGE_STATE_DONE;
            }
            break;
    }
    wlMenuMessage = gWLMenuMessage;
    wlMenuMessage->mBg3Offset = (wlMenuMessage->mBg3Offset + 1) % 0x100;
    return -1;
}

s32 AdvanceWLMenuMessageToRace(SceneNumbers *sceneNumbers) {
    s32 result;
    WLMenuMessage *wlMenuMessage;

    switch (gWLMenuMessage->mState) {
        case WL_MENU_MESSAGE_STATE_RUN_MP_STATE_MACHINE:
            result = WLMenuToRaceAdvanceMPStateMachineWrapper();
            switch (result) {
                case 1:
                    if (HasGroupSendMask() != 0) {
                        StopSeqZeroLoopWrapper();
                    }
                    gWLMenuMessage->mState = WL_MENU_MESSAGE_STATE_SET_NEXT_SCENE;
                    break;
                case 2:
                    break;
            }
            break;
        case WL_MENU_MESSAGE_STATE_SET_NEXT_SCENE:
            if (sceneNumbers != 0) {
                SetNextScene(sceneNumbers, 2);
            }
            gWLMenuMessage->mState = WL_MENU_MESSAGE_STATE_DONE;
            break;
    }
    wlMenuMessage = gWLMenuMessage;
    wlMenuMessage->mBg3Offset = (wlMenuMessage->mBg3Offset + 1) % 0x100;
    return -1;
}

s32 AdvanceWLMenuMessageToResult(SceneNumbers *sceneNumbers) {
    s32 result;
    WLMenuMessage *wlMenuMessage;

    switch (gWLMenuMessage->mState) {
        case WL_MENU_MESSAGE_STATE_RUN_MP_STATE_MACHINE:
            result = WLMenuToResultAdvanceMPStateMachineWrapper();
            switch (result) {
                case 1:
                    if (HasGroupSendMask() != 0) {
                        StopSeqZeroLoopWrapper();
                    }
                    gWLMenuMessage->mState = WL_MENU_MESSAGE_STATE_SET_NEXT_SCENE;
                    break;
                case 2:
                    break;
            }
            break;
        case WL_MENU_MESSAGE_STATE_SET_NEXT_SCENE:
            if (sceneNumbers != 0) {
                SetNextScene(sceneNumbers, 10);
            }
            gWLMenuMessage->mState = WL_MENU_MESSAGE_STATE_DONE;
            break;
    }
    wlMenuMessage = gWLMenuMessage;
    wlMenuMessage->mBg3Offset = (wlMenuMessage->mBg3Offset + 1) % 0x100;
    return -1;
}

#pragma thumb off

u32 HasGroupSendMask(void) {
    return gConnectionWork->mGroupSendMask != 0;
}

void StopSeqZeroLoopWrapper(void) {
    u32 unusedScratch;
    StopSeqZeroLoop();
}

void SetNextScene(SceneNumbers *sceneNumbers, u32 nextScene) {
    sceneNumbers->mNextScene = nextScene;
}

#pragma thumb on

s32 AdvanceWLMenuMessageToMenu(SceneNumbers *sceneNumbers) {
    s32 result;
    WLMenuMessage *wlMenuMessage;

    switch (gWLMenuMessage->mState) {
        case WL_MENU_MESSAGE_STATE_RUN_MP_STATE_MACHINE:
            result = WLMenuToMenuAdvanceMPStateMachineWrapper();
            switch (result) {
                case 1:
                    if (HasGroupSendMask() != 0) {
                        StopSeqZeroLoopWrapper();
                    }
                    gWLMenuMessage->mState = WL_MENU_MESSAGE_STATE_SET_NEXT_SCENE;
                    break;
                case 2:
                    break;
            }
            break;
        case WL_MENU_MESSAGE_STATE_SET_NEXT_SCENE:
            if (sceneNumbers != 0) {
                SetNextScene(sceneNumbers, 1);
            }
            gWLMenuMessage->mState = WL_MENU_MESSAGE_STATE_DONE;
            break;
    }
    wlMenuMessage = gWLMenuMessage;
    wlMenuMessage->mBg3Offset = (wlMenuMessage->mBg3Offset + 1) % 0x100;
    return -1;
}

#pragma thumb off

#pragma thumb on

void ReleaseWLMenuMessage(void) {
    HeapDestroy(gWLMenuMessage->mHeap);
    gWLMenuMessage = NULL;
}

#pragma thumb off

void WLMenuMessageGXS_SetVisiblePlane(int bits) {
    reg_GXS_DB_DISPCNT = (reg_GXS_DB_DISPCNT & ~REG_GXS_DB_DISPCNT_DISPLAY_MASK) | (bits << 8);
}

void WLMenuMessageG2S_SetBG3Offset(u32 offsetX, int offsetY) {
    reg_G2S_DB_BG3OFS = (offsetX & 0x1ff) | ((offsetY << 16) & 0x01ff0000);
}

#pragma thumb on

void WriteWLMenuMessageRegisters(void) {
    WLMenuMessageGXS_SetVisiblePlane(10);
    WLMenuMessageG2S_SetBG3Offset(-gWLMenuMessage->mBg3Offset, 0);
}

#pragma thumb off

#pragma thumb on
void WriteWLMenuMessageRegistersWrapper(void) {
    u32 unusedScratch;
    WriteWLMenuMessageRegisters();
}
#pragma thumb off
