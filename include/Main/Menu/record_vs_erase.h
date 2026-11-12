#pragma once

#include "types.h"
#include "Main/Menu/data_0217d000.h"

void AdvanceRecordVSEraseState9(void);
void AdvanceRecordVSEraseState10(void);
void AdvanceRecordVSEraseState11(void);
void AdvanceRecordVSEraseState12(void);
void AdvanceRecordVSErase(void);
void WriteRecordVSEraseBgOffsets(void);
void WriteRecordVSEraseRegisters(void);
void RegisterRecordVSEraseCallbacks(void);

void AdvanceRecordVSEraseState8(void);

void AdvanceRecordVSEraseState3(void);
void AdvanceRecordVSEraseState4(void);
void AdvanceRecordVSEraseState5(void);
void AdvanceRecordVSEraseState6(void);
void AdvanceRecordVSEraseState7(void);

void AdvanceRecordVSEraseState2(void);
void AdvanceRecordVSEraseState1(void);
void AdvanceRecordVSEraseState0(void);

void AdvanceRecordVSEraseIndexChange(void);
void RequestRecordVSEraseState0(void);
void RequestRecordVSEraseState1(void);
void RequestRecordVSEraseState2(void);
void RequestRecordVSEraseState3(void);
void RequestRecordVSEraseState4(void);
void RequestRecordVSEraseState5(void);
void RequestRecordVSEraseState6(void);
void RequestRecordVSEraseState7(void);
void RequestRecordVSEraseState8(void);
void RequestRecordVSEraseState9(void);
void RequestRecordVSEraseState10(void);
void RequestRecordVSEraseState11(void);
void RequestRecordVSEraseState12(void);
void InitRecordVSErase(void *heap);
void ReleaseRecordVSErase(void);

u32 IsRecordVSEraseIndexChangeRunning(void);

void AdvanceRecordVSEraseOffsetTimers(void);

void DecrementRecordVSEraseIndex(void);
void IncrementRecordVSEraseIndex(void);

u32 DecrementRecordVSErasePageIndex(void);
u32 IncrementRecordVSErasePageIndex(void);

void UpdateRecordVSEraseRows(void);
void PrintRecordVSEraseShownRecord(void);
void RefreshRecordVSErasePage(void);

BOOL IsRecordVSEraseRowFilled(int row);

u16 GetRecordVSEraseFirstRecordIndex(void);

void LocateAndQueueRecordVSErase(void);

extern const u16 gRecordVSEraseRow0MessageIndices[4];
extern const u16 gRecordVSEraseGridLabelWidths[3][3];
extern char *gRecordVSSEraseBnblName;
extern char *gRecordVSSEraseBnllName;
extern const u16 gRecordVSEraseOffsetCellIndices[2];
extern const u16 gRecordVSEraseRowLabelWidths[6];
extern const s16 gRecordVSEraseRectInputSlots[6];
extern char *gRecordVSSEraseNscrName;
extern const u16 gRecordVSEraseFriendKeyLabelIndices[12];
extern const u16 gRecordVSEraseHighlightIndices[6];
extern char *gRecordVSSBNclrName;
extern const u16 gRecordVSEraseFriendKeyWidths[12];
extern const u16 gRecordVSEraseUnflaggedObjectIndices[6];
extern const u16 gRecordVSEraseFlaggedObjectIndices[6];
extern const u16 gRecordVSEraseGridLabelHeights[3][3];
extern char *gRecordVSSBNcgrName;
extern const u16 gRecordVSEraseGridLabelIndices[3][3];
extern const u16 gRecordVSEraseRowLabelHeights[6];
extern const u16 gRecordVSEraseFlaggedRowIndices[6];
extern char *gRecordVSSEraseBnclName;
extern const u16 gRecordVSEraseRowLabelIndices[6];
extern const u16 gRecordVSEraseNoOffsetCellIndices[2];
extern const u16 gRecordVSEraseUnhighlightedIndices[6];
extern const u16 gRecordVSEraseFlaggedHighlightIndices[6];
extern const u16 gRecordVSEraseFriendKeyHeights[12];
extern struct RecordVSErase *gRecordVSErase;
