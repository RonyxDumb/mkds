#pragma once

#include "types.h"
#include "01/Menu/record_time_attack.h"
#include "01/Menu/code_02196d58.h"
#include "Main/MapObjects/data_0217a000.h"
#include "00/Menu/wi_fi_vs_setting.h"
#include "01/unk_021a9000.h"
#include "Main/Graphics/scene_text_init.h"
#include "01/Menu/option_select_menu.h"
#include "Main/Graphics/scene_text.h"
#include "Main/Graphics/locate_bmg_sections.h"
#include "Main/Scene/display_settings.h"
#include "code_020182c0.h"
#include "frameheap.h"
#include "os_thread.h"
#include "Main/MapObjects/map_object_park.h"
#include "pm.h"
#include "Main/Sound/sound_seq.h"
#include "03/Net/essid_packet_steps.h"

// States of NicknameScene.mState and mNextState, in the order of the AdvanceNicknameSceneStateN calls: wait for the
// fade, then three message boxes in a row.
enum {
    NICKNAME_SCENE_STATE_WAIT_FADE,
    NICKNAME_SCENE_STATE_FIRST_MESSAGE,
    NICKNAME_SCENE_STATE_SECOND_MESSAGE,
    NICKNAME_SCENE_STATE_THIRD_MESSAGE,
};

// NicknameScene.mNextScene while no scene is requested.
#define NICKNAME_SCENE_NEXT_NONE (-1)

// Object behind gNicknameScene.
typedef struct NicknameScene {
    /* 00 */ s32 mState;
    /* 04 */ s32 mNextState;
    /* 08 */ void *mHeap;
    /* 0c */ s16 mUnk_0c;
    /* 0e */ s16 mNextScene;
    /* 10 */ void *mSceneDisplaySettings;
    /* 14 */ struct Bmg *mCommonMessages;
} NicknameScene;

int GetNicknameSceneNextScene(void);
void NicknameWriteSceneTextRegistersWrapper(void);
void AdvanceNicknameScene(void);
void AdvanceNicknameSceneState3(void);
void AdvanceNicknameSceneState2(void);
void AdvanceNicknameSceneState1(void);
void AdvanceNicknameSceneState0(void);
void ReleaseNicknameSceneObject(void);
void InitNicknameSceneObject(void *heap, s16 previousScene);

#include "00/Menu/wi_fi_vs_matching.h"
