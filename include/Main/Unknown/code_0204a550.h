#pragma once

#include "types.h"

// Object read at 0x00 and written at 0x04 by emblem_update.
typedef struct EmblemSceneNumbersView {
    /* 00 */ s16 field0;
    /* 02 */ u8 field2[0x2];
    /* 04 */ s16 field4;
} EmblemSceneNumbersView;

#include "Main/Unknown/unk_02175000.h"

// Scene function of scproc_sSceneTable[3] (scene 'Emblem' in sSceneDefs): copies the callbacks and calls
// scene_runScene. Returns 0.
s32 emblem_run(void *sceneNumbers);
void emblem_update(EmblemSceneNumbersView *sceneNumbers);
void emblem_vblank(void);
unsigned int emblem_finalize(unsigned int value);
// Calls vram_terminateWifiVram, input_initUnits and InitEmblem through func_ov001_021a23f4 (InitEmblem also
// calls echoi_init).
void emblem_init(void);
BOOL irec_isAlmostAtPlayBufferEnd(KeyRecording *keyRecording);
BOOL irec_isBufferFull(KeyRecording *keyRecording);
u16 irec_playKeys(KeyRecording *keyRecording);
void irec_recordKeys(KeyRecording *keyRecording, u16 keys);
