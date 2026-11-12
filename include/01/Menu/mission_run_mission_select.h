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

extern const u16 gMissionRunMSselValueMTableIndices[6];
extern const s16 gMissionRunMSselRightSteps[9];
extern const u16 gMissionRunMSselLabelWidths[9][2];
extern const u16 gMissionRunMSselIndexMTableIndices[9];
extern const u16 gMissionRunMSselLabelHeights[9][2];
extern const s16 gMissionRunMSselUpSteps[9];
extern const s16 gMissionRunMSselLeftSteps[9];
extern const s16 gMissionRunMSselDownSteps[9];
extern const u16 gMissionRunMSselIndexSTableIndices[9][9];
extern const u16 gMissionRunMSselRowMTableIndices[7];
extern const u16 gMissionRunMSselLabelSTableIndices[9][2];
extern const s16 gMissionRunMSselRectIndices[9];
