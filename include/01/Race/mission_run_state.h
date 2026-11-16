#pragma once

// The count MissionRunData.mSinceHitCallbackFrames must exceed before the hit callback of the entry's own eliminated
// kart runs again (every 16th frame), once the winner is decided and while that kart still has balloons or shines.
#define MISSION_RUN_SELF_HIT_CALLBACK_FRAMES 0xf

#include "types.h"
#include "Main/MapObjects/balloon.h" // Balloon

#include "01/Menu/menu_screen_states_and_file_names.h"
#include "touch_panel_sampling.h"
#include "Main/System/heap_call.h"
#include "Main/Race/race.h"
#include "Main/Kart/kart_drift.h"
#include "Main/Item/item_objects_and_race_progress.h"
#include "01/MapObjects/mission_run_map_object.h"
#include "Main/Race/standings_balloons.h"

void AddMissionRunPendingCountUpFromBoss(s32 stepCount);
void AddMissionRunPendingCountUp(s32 stepCount);
void AddMissionRunBossCount(short amount);
void AddMissionRunPendingBossTransfer(u16 amount);
void AddMissionRunPendingDrop(u32 amount);
void SetMissionRunBossTransferCallback(MissionRunEventCallback callback);
void SetMissionRunDropCallback(MissionRunEventCallback callback);
void SetMissionRunCountUpCallback(MissionRunEventCallback callback);
BOOL IsAnyBalloonUnparked(void);
void AddMissionRunCountForShapeEntry(void);
void AddMissionRunCountForMiniTurbo(void);
void AddMissionRunPendingDropOnKartHit(void);
void AddMissionRunCountForMapObjectKind(s32 mapObjectKind);
void AddMissionRunCountForHit(void);
s32 GetMissionRunBossCount(void);
u32 GetMissionRunCountLimit(void);
unsigned int GetMissionRunCount(void);
void SetMissionRunTimer(u16 timer);
s32 GetMissionRunTimer(void);
void SetMissionRunTimerValues(u16 startTimer, u16 maxTimer, u16 countUpTimerAdd, u16 bossTransferTimerAdd);
void UpdateMissionRunData(void);
void CreateMissionRunData(void);
u16 GetMissionRunPrevKartHeadingAngle(void);
u16 GetMissionRunKartHeadingAngle(void);
Vec3 *GetMissionRunPrevKartPos(void);
Vec3 *GetMissionRunKartPos(void);
void AddMissionRunCount(void);
u16 GetMissionRunMapObjectLastIndex(void);
u8 MissionRunGetCurrentKartCount(void);
MissionRunMapObject *GetMissionRunMapObject(int entryIndex);
void AddMissionRunMapObject(MissionRunMapObject *mapObject);
