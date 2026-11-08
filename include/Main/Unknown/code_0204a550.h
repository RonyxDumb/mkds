#pragma once

#include "types.h"

typedef struct SceneNumbers SceneNumbers;

#include "Main/Unknown/unk_02175000.h"

// Scene function of gSceneFuncs[3] (scene 'Emblem' in gSceneNames): copies the callbacks and calls
// RunScene. Returns 0.
s32 RunEmblemScene(void *sceneNumbers);
void UpdateEmblemScene(SceneNumbers *sceneNumbers);
void func_0204a5e8(void);
unsigned int func_0204a5f4(unsigned int value);
// Calls StopWvrAndWait, ResetInputSlots and InitEmblem through func_ov001_021a23f4 (InitEmblem also
// calls InitEmblemChoises).
void InitEmblemScene(void);
BOOL func_0204a620(KeyRecording *keyRecording);
BOOL IsKeyRecordingFull(KeyRecording *keyRecording);
u16 ReadKeysFromKeyRecording(KeyRecording *keyRecording);
void AppendKeysToKeyRecording(KeyRecording *keyRecording, u16 keys);
