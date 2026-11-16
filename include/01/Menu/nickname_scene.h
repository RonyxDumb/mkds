#pragma once

#include "types.h"
#include "01/Menu/record_time_attack.h"
#include "01/Menu/record_time_attack_requests.h"
#include "Main/System/backup_net_camera_work.h"
#include "00/Menu/wi_fi_vs_setting.h"
#include "01/Menu/menu_screen_states_and_file_names.h"
#include "Main/Graphics/scene_text_init.h"
#include "01/Menu/option_select_menu.h"
#include "Main/Graphics/scene_text.h"
#include "Main/Graphics/locate_bmg_sections.h"
#include "Main/Scene/display_settings.h"
#include "archive_memory_load.h"
#include "heap_frame_allocator.h"
#include "thread_scheduler.h"
#include "Main/MapObjects/map_object_park.h"
#include "power_management_commands.h"
#include "Main/Sound/sound_seq.h"
#include "03/Net/essid_packet_steps.h"

// States of NicknameScene.mState and mNextState: wait for the
// fade, then three message boxes in a row.
enum {
    NICKNAME_SCENE_STATE_WAIT_FADE,
    NICKNAME_SCENE_STATE_FIRST_MESSAGE,
    NICKNAME_SCENE_STATE_SECOND_MESSAGE,
    NICKNAME_SCENE_STATE_THIRD_MESSAGE,
};

// NicknameScene.mNextScene while no scene is requested.
#define NICKNAME_SCENE_NEXT_NONE (-1)

// The nickname scene: its state, heap, previous and next scene and display settings.
typedef struct NicknameScene {
    /* 00 */ s32 mState;
    /* 04 */ s32 mNextState;
    /* 08 */ void *mHeap;
    /* 0c */ s16 mPreviousScene;
    /* 0e */ s16 mNextScene;
    /* 10 */ void *mSceneDisplaySettings;
    /* 14 */ struct Bmg *mCommonMessages;
} NicknameScene;

int GetNicknameSceneNextScene(void);
void NicknameWriteSceneTextRegistersWrapper(void);
void AdvanceNicknameScene(void);
void AdvanceNicknameSceneThirdMessage(void);
void AdvanceNicknameSceneSecondMessage(void);
void AdvanceNicknameSceneFirstMessage(void);
void AdvanceNicknameSceneWaitFade(void);
void ReleaseNicknameSceneObject(void);
void InitNicknameSceneObject(void *heap, s16 previousScene);

#include "00/Menu/wi_fi_vs_matching.h"
