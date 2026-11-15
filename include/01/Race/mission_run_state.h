#pragma once

#include "types.h"
#include "Main/MapObjects/balloon.h" // Balloon

#include "01/code_02181000.h"
#include "01/unk_021a9000.h"
#include "tp.h"
#include "Main/System/heap_call.h"
#include "Main/Race/race.h"
#include "Main/Kart/kart_drift.h"
#include "Main/Race/data_020f36d8.h"
#include "01/code_02188950.h"
#include "Main/Race/standings_balloons.h"

void AddMissionRunPendingCountUpFromBoss(s32 stepCount);
void AddMissionRunPendingCountUp(s32 stepCount);
void AddMissionRunBossCount(short param_1);
void AddMissionRunPendingBossTransfer(u16 amount);
void AddMissionRunPendingDrop(u32 amount);
void SetMissionRunBossTransferCallback(MissionRunEventCallback callback);
void SetMissionRunDropCallback(MissionRunEventCallback callback);
void SetMissionRunCountUpCallback(MissionRunEventCallback callback);
BOOL IsAnyBalloonUnparked(void);
void AddMissionRunCountForKind0(void);
void AddMissionRunCountForKind4(void);
void AddMissionRunPendingDropOnKartHit(void);
void AddMissionRunCountForMapObjectKind(s32 mapObjectKind);
void AddMissionRunCountForKind7(void);
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
