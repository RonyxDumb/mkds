#pragma once

#include "types.h"

typedef struct SceneNumbers SceneNumbers;

#include "Main/Unknown/unk_02175000.h"

// Scene function of gSceneFuncs[3] (scene 'Emblem' in gSceneNames): copies the callbacks and calls
// RunScene. Returns 0.
s32 RunEmblemScene(void *sceneNumbers);
void UpdateEmblemScene(SceneNumbers *sceneNumbers);
void WriteEmblemSceneRegistersCallback(void);
unsigned int EmblemSceneReturnArgument(unsigned int value);
// Calls StopWvrAndWait, ResetInputSlots and InitEmblem through InitEmblemAndAdvanceKartList (InitEmblem also
// calls InitEmblemChoises).
void InitEmblemScene(void);
BOOL IsKeyRecordingPlaybackNearBufferEnd(KeyRecording *keyRecording);
BOOL IsKeyRecordingFull(KeyRecording *keyRecording);
u16 ReadKeysFromKeyRecording(KeyRecording *keyRecording);
void AppendKeysToKeyRecording(KeyRecording *keyRecording, u16 keys);
