#pragma once

#include "types.h"
#include "code_02142eac.h" // WirelessMessage
#include "Main/Menu/second_menu_scene.h" // StateCallbacks

typedef struct SceneNumbers SceneNumbers;

void InitMPStateMachine(void);
void ProcessMPChunk(u8 *chunk);
u32 IsAllMPChunksReceived(u32 slot);
// Scene function of gSceneFuncs[10] (scene 'Result' in gSceneNames): copies the callbacks and calls
// RunScene. Returns 0.
s32 RunResultScene(SceneNumbers *sceneNumbers);

void MPChunkPortCallback(void *portMessage);

// States of gConnectionWork->mMPStateMachine, in the order of gMPStateTable.
enum {
    MP_STATE_FILL_OWN_RECORD,
    MP_STATE_WAIT_ROM_ARCHIVE,
    MP_STATE_LOAD_OVERLAY,
    MP_STATE_LOAD_DL_ARCHIVES,
    MP_STATE_LOAD_SOUND_DATA,
    MP_STATE_SEND_PARTICIPANT_MASK,
    MP_STATE_SEND_GROUP_SEND_MASK,
    MP_STATE_START_EXCHANGE,
    MP_STATE_EXCHANGE_OWN_RECORDS,
    MP_STATE_SEND_ALL_RECORDS,
    MP_STATE_SEND_ROM_ARCHIVE,
    MP_STATE_SEND_PLAYER_NAMES,
    MP_STATE_START_DATA_SHARING,
    MP_STATE_EXCHANGE_PLAYER_BITS,
    MP_STATE_SEND_PLAYER_BITS,
    MP_STATE_READY,
    MP_STATE_WAIT_RACE_ARCHIVES,
    MP_STATE_LOAD_COURSE_SOUND,
    MP_STATE_WAIT_RESULT_ARCHIVES,
    MP_STATE_LOAD_RESULT_SOUND,
    MP_STATE_WAIT_REQUEST_DONE,
    MP_STATE_WAIT_MENU_ARCHIVES,
    MP_STATE_CHILD_DELAY,
    MP_STATE_COUNT
};

extern StateCallbacks gMPStateTable[MP_STATE_COUNT];
