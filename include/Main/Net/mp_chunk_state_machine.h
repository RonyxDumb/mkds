#pragma once

#include "types.h"
#include "wireless_link_control.h"
#include "Main/Menu/second_menu_scene.h" // StateCallbacks

typedef struct SceneNumbers SceneNumbers;

void InitMPStateMachine(void);
void ProcessMPChunk(u8 *chunk);
u32 IsAllMPChunksReceived(u32 slot);
// Scene function of gSceneFuncs[10] (scene 'Result' in gSceneNames): copies the callbacks and calls
// RunScene. Returns 0.
s32 RunResultScene(SceneNumbers *sceneNumbers);

void MPChunkPortCallback(void *portMessage);

// Byte 1 of a chunk is its number; these values are control messages, no record data: the parent says a record arrived
// (the child then stops sending its own), says in the size field which records it holds (a mask), the child says it
// holds all records, and a chunk that clears mHasEmblem and finishes the record (nothing in this tree sends it).
#define MP_CHUNK_RECORD_ARRIVED 0xff
#define MP_CHUNK_HELD_RECORDS_MASK 0xfe
#define MP_CHUNK_ALL_RECORDS_HELD 0xfd
#define MP_CHUNK_NO_EMBLEM 0xfc
// Bytes in front of the data of a chunk: player index, chunk number, data size.
#define MP_CHUNK_HEADER_SIZE 4
// Player slots that the record, name and bits states of the exchange walk through.
#define MP_PARTICIPANT_SLOT_COUNT 8

// States of gConnectionWork->mMPStateMachine, in the order of gMPStateTable.
enum {
    MP_STATE_FILL_OWN_RECORD,
    MP_STATE_WAIT_ROM_ARCHIVE,
    MP_STATE_LOAD_OVERLAY,
    MP_STATE_WAIT_MAIN_AND_MENU_ARCHIVES,
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
