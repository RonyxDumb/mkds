#pragma once

#include "types.h"
#include "code_0214d93c.h" // RTCTime
#include "Main/Menu/data_02175000.h"

typedef struct Vec3 Vec3;

typedef struct SceneNumbers SceneNumbers;

typedef struct GhostRecord GhostRecord;
typedef struct SlotGhostRecord SlotGhostRecord;

typedef struct CharacterKartPicks CharacterKartPicks;

void SetGivenKart(CharacterKartPicks *picks, u32 entryIndex, u32 kartIndex);
void SetGivenCharacter(CharacterKartPicks *picks, u32 entryIndex, u32 characterIndex);
void InitCharacterKartPicks(CharacterKartPicks *picks);
CharacterKartPicks *CreateCharacterKartPicks(void *heap);
void CopyCourseGhostToSlotGhost(GhostRecord *courseGhost, SlotGhostRecord *slotGhost);
void GetClockTimeOrZero(RTCTime *time);
void GetClockDateOrDefault(s32 *date);
// Scene function of gSceneFuncs[0] (scene 'Title' in gSceneNames): copies the callbacks and calls
// RunScene. Returns 0.
u32 RunTitleScene(SceneNumbers *sceneNumbers);
void UpdateTitleScene(s32 flag);
void WriteTitleSceneRegistersCallback(void);
void ReleaseTitleScene(void);
void InitTitleScene(void);
u32 ShouldEndReplayRace(void);
BOOL IsFramesSinceFinishPastWait(void);
void FinishKartInCourseMapKind2Shape(Vec3 *position, u32 kartIndex);

extern SceneCallbacks gTitleSceneCallbacks;
