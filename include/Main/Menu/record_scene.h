#pragma once

#include "types.h"

typedef struct SceneNumbers SceneNumbers;

void UpdateRecordScene(SceneNumbers *sceneNumbers);
void *GetRecordMainOam(void);
void *GetRecordSubOam(void);

void WriteRecordSceneRegistersCallback(void);
// Slot mRelease: calls the state's undo functions and clears the globals; frees nothing itself (the
// scene heap goes with the scene).
void ReleaseRecordScene(void);

void InitRecordScene(s16 *sceneNumbers);

extern void *gRecordSubOam;
extern void *gRecordMainOam;
