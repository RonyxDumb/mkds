#pragma once

#include "types.h"
#include "Main/Scene/scene_display_archive_work.h" // SceneCallbacks

typedef struct SlotResultSyncState SlotResultSyncState;
typedef struct SceneNumbers SceneNumbers;

struct MapObjectKindDescriptor;

void Scene_Result_Update(SceneNumbers *sceneNumbers);
void Scene_Result_VBlank(void);
void Scene_Result_Finalize(void);
void Scene_Result_Initialize(void);
u32 IsAddressInOverlayRegion(struct MapObjectKindDescriptor *address);
void DisposeLoadedOverlay(void);
s32 TryFinishOverlayLoad(void);
void DisposeOverlayManagerHeap(void);
void CreateRegionHeapHandleForOverlay1(void);
void WaitOverlayLoadedStarted(void);
void UpdateOverlayStatusWithKind(s32 overlay);
void ResetOverlayManager(void);
void CreateOverlayFrmHeap(void);
void InitializeOverlayManager(void *heap);
s32 GetParticipantSlotResult(s32 participantIndex);
BOOL IsParticipantSlotResultSyncing(s32 participantIndex);
void UpdateSlotResultSyncs(void);
void StartSlotResultSync(SlotResultSyncState *syncState, s32 itemInfoIndex);

extern SceneCallbacks g_Scene_Result;
