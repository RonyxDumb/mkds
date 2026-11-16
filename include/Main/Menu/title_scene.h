#pragma once

#include "types.h"
#include "clock_chip_access.h" // RTCTime
#include "Main/Scene/scene_display_archive_work.h"

// A replay race ends once the race clock reaches this minute.
#define REPLAY_END_CLOCK_MINUTE 7

typedef struct Vec3 Vec3;

typedef struct SceneNumbers SceneNumbers;

typedef struct GhostRecord GhostRecord;
typedef struct SlotGhostRecord SlotGhostRecord;

typedef struct CharacterKartPicks CharacterKartPicks;

void SetGivenKart(CharacterKartPicks *picks, u32 entryIndex, u32 kartIndex);
void SetGivenCharacter(CharacterKartPicks *picks, u32 entryIndex, u32 characterIndex);
void StructKTB_SomeFn_from_thumb(CharacterKartPicks *picks);
CharacterKartPicks *AllocateKartAppearTableData_from_thumb(void *heap);
void CopyCourseGhostToSlotGhost(GhostRecord *courseGhost, SlotGhostRecord *slotGhost);
void GetCurrentTime(RTCTime *time);
void GetCurrentDate(s32 *date);
// Scene function of g_SceneFnTable[0] (scene 'Title' in g_SceneArchiveNameTable): copies the callbacks and calls
// OnSceneLoop. Returns 0.
u32 SceneFn_Title(SceneNumbers *sceneNumbers);
void Scene_Title_Update(s32 flag);
void Scene_Title_VBlank(void);
void Scene_Title_Finalize(void);
void Scene_Title_Initialize(void);
u32 ShouldEndReplayRace(void);
BOOL IsFramesSinceFinishPastWait(void);
void FinishKartInCourseMapMissionEndShape(Vec3 *position, u32 kartIndex);

extern SceneCallbacks g_Scene_Title;
