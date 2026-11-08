#pragma once

#include "types.h"
#include "code_0214d93c.h" // RTCTime

typedef struct Vec3 Vec3;

typedef struct SceneNumbers SceneNumbers;

typedef struct GhostRecord GhostRecord;

void SetGivenKart(u8 *rawPicks, u32 entryIndex, u32 kartIndex);
void SetGivenCharacter(u8 *rawPicks, u32 entryIndex, u32 characterIndex);
void InitCharacterKartPicks(u8 *rawPicks);
u8 *func_0203bedc(void *heap);
void func_0203bf04(GhostRecord *courseGhost, GhostRecord *slotGhost);
void GetClockTimeOrZero(RTCTime *time);
void GetClockDateOrDefault(s32 *date);
// Scene function of gSceneFuncs[0] (scene 'Title' in gSceneNames): copies the callbacks and calls
// RunScene. Returns 0.
u32 RunTitleScene(SceneNumbers *sceneNumbers);
void UpdateTitleScene(s32 a);
void func_0203c07c(void);
void ReleaseTitleScene(void);
void InitTitleScene(void);
u32 func_0203c0bc(void);
BOOL IsFramesSinceFinishPastWait(void);
void func_0203c1a8(Vec3 *position, u32 kartIndex);
