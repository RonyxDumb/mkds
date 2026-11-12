#pragma once

#include "types.h"

void WriteMissionRunLVselBg0Offset(void);
s32 AdvanceMissionRunLVsel(void);
void AdvanceMissionRunLVselState5(void);
void AdvanceMissionRunLVselState4(void);
void AdvanceMissionRunLVselState3(void);
void AdvanceMissionRunLVselState2(void);
void AdvanceMissionRunLVselState1(void);
void AdvanceMissionRunLVselState0(void);
void ReleaseMissionRunLVsel(void);
void InitMissionRunLVsel(void *parentHeap, void *mainOam, void *subOam);
void RequestMissionRunLVselState5(void);
void RequestMissionRunLVselState4(void);
void RequestMissionRunLVselState3(void);
void RequestMissionRunLVselState2(void);
void RequestMissionRunLVselState1(void);
void ResetMissionRunLVsel(void);
BOOL IsMissionRunLVselLastRecordMissing(void);
void SetMissionTableToSelectedLevel(void);
void RefreshMissionRunLVselReachedLevel(void);
void UpdateMissionRunLVselHighlight(void);
void RefreshMissionRunLVselLevelCells(void);
u32 IsMissionRunLVselLevelReached(int levelIndex);
s32 GetMissionRunLVselMinRecordValue(s16 levelIndex);
void LocateAndQueueMissionRunLVsel(void);
void LoadMissionRunLVselData(void);

extern const s16 gMissionRunLVselRightIndexOffsets[7];
extern const s16 gMissionRunLVselLeftIndexOffsets[7];
extern const s16 gMissionRunLVselDownIndexOffsets[7];
extern const s16 gMissionRunLVselUpIndexOffsets[7];
extern const u16 gMissionRunLVselGradeLabelIndices[7];
extern const u16 gMissionRunLVselGradeLabelHeights[7];
extern const u16 gMissionRunLVselGradeLabelWidths[7];
extern const u16 gMissionRunLVselLevelCellIndices[7][11];
extern const s16 gMissionRunLVselTouchLevelIndices[7];
