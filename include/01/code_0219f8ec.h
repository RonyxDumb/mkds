#pragma once

#include "types.h"

void WriteMissionRunMSselBgOffsets(void);
s32 AdvanceMissionRunMSsel(void);
void AdvanceMissionRunMSselState8(void);
void AdvanceMissionRunMSselState7(void);
void AdvanceMissionRunMSselState6(void);
void AdvanceMissionRunMSselState5(void);
void AdvanceMissionRunMSselState4(void);
void AdvanceMissionRunMSselState3(void);
void AdvanceMissionRunMSselState2(void);
void AdvanceMissionRunMSselState1(void);
void AdvanceMissionRunMSselState0(void);
void ReleaseMissionRunMSsel(void);
void InitMissionRunMSsel(void *parentHeap, void *mainOamList, void *subOamList);
void RequestMissionRunMSselState8(void);
void RequestMissionRunMSselState7(void);
void RequestMissionRunMSselState6(void);
void RequestMissionRunMSselState5(void);
s32 RequestMissionRunMSselState4(void);
void RequestMissionRunMSselState3(void);
void RequestMissionRunMSselState2(void);
void RequestMissionRunMSselState1(void);
void ResetMissionRunMSselOffsets(void);
void AdvanceMissionRunMSselIndexChange(void);
BOOL IsMissionRunMSselIndexChangeRunning(void);
void SetMissionFromMissionRunMSsel(void);
void RefreshMissionRunMSselMCells(void);
void UpdateMissionRunMSselIndexCells(void);
void AdvanceMissionRunMSselPaletteBlend(void);
void InitMissionRunMSselCells(void);
void FormatMissionRunMissionNumber(s32 missionIndex, u16 *text);
void SetMissionRunMSselAllRecorded(void);
void LocateAndQueueMissionRunMSsel(void);
void LoadMissionRunMSselAndBossIconData(void);
