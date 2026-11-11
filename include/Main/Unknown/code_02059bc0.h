#pragma once

#include "types.h"

typedef struct SlotResultSyncState SlotResultSyncState;
typedef struct SceneNumbers SceneNumbers;

struct MapObjectKindDescriptor;

void UpdateResultScene(SceneNumbers *sceneNumbers);
void WriteResultSceneRegistersCallback(void);
void ReleaseResultScene(void);
void InitResultScene(void);
u32 IsInOverlayRange(struct MapObjectKindDescriptor *address);
void ReleaseCurrentOverlay(void);
s32 TryFinishOverlayLoad(void);
void FreeOverlayExpHeap(void);
void CreateOverlayExpHeap(void);
void FinishOverlayLoad(void);
void StartLoadOverlay(s32 overlay);
void ResetCurrentOverlay(void);
void CreateOverlayFrmHeap(void);
void InitOverlayTable(void *heap);
s32 GetParticipantSlotResult(s32 participantIndex);
BOOL IsParticipantSlotResultSyncing(s32 participantIndex);
void UpdateSlotResultSyncs(void);
void StartSlotResultSync(SlotResultSyncState *syncState, s32 itemInfoIndex);
