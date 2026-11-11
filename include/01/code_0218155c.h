#pragma once

#include "types.h"
#include "Main/Unknown/code_020a2e4c.h" // Balloon

#include "01/code_02181000.h"
#include "01/unk_021a9000.h"
#include "Main/Unknown/code_02100000.h"
#include "Main/Unknown/unk_021759c0.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_020364e0.h"
#include "Main/Unknown/code_02061654.h"
#include "Main/Unknown/code_0206bcb0.h"
#include "Main/Unknown/code_020a1000.h"
#include "Main/Unknown/code_020f36d8.h"
#include "01/code_02188950.h"
#include "Main/Unknown/code_020a1728.h"

void AddMissionRunPendingCountUpFromBoss(s32 stepCount);
void AddMissionRunPendingCountUp(s32 stepCount);
void AddMissionRunBossCount(short param_1);
void AddMissionRunPendingBossTransfer(u16 amount);
void AddMissionRunPendingDrop(u32 amount);
void SetMissionRunBossTransferCallback(UnkFunc *callback);
void SetMissionRunDropCallback(UnkFunc *callback);
void SetMissionRunCountUpCallback(UnkFunc *callback);
BOOL IsAnyBalloonUnparked(void);
void AddMissionRunCountForKind0(void);
void AddMissionRunCountForKind4(void);
void AddMissionRunPendingDropOnKartHit(void);
void AddMissionRunCountForMapObjectKind(s32 mapObjectKind);
void AddMissionRunCountForKind7(void);
s32 GetMissionRunBossCount(void);
u32 GetMissionRunCountLimit(void);
unsigned int GetMissionRunCount(void);
void SetMissionRunTimer(unsigned int timer);
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
Unk02188950 *GetMissionRunMapObject(int entryIndex);
void AddMissionRunMapObject(Unk02188950 *mapObject);
