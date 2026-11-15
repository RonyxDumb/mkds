#pragma once

#include "types.h"
#include "Main/Menu/data_0217d000.h"

void AdvanceRecordVSEraseWaitConfirmAnswer(void);
void AdvanceRecordVSEraseCloseConfirmSlideOutMain(void);
void AdvanceRecordVSEraseSlideInAfterConfirm(void);
void AdvanceRecordVSEraseSubSlideOutToScreen(void);
void AdvanceRecordVSErase(void);
void WriteRecordVSEraseBgOffsets(void);
void WriteRecordVSEraseRegisters(void);
void RegisterRecordVSEraseCallbacks(void);

void AdvanceRecordVSEraseOpenConfirmText(void);

void AdvanceRecordVSEraseSlideInSub(void);
void AdvanceRecordVSEraseBrowse(void);
void AdvanceRecordVSErasePageSlideOut(void);
void AdvanceRecordVSErasePageSlideIn(void);
void AdvanceRecordVSEraseSubSlideOut(void);

void AdvanceRecordVSEraseCloseIntroText(void);
void AdvanceRecordVSEraseWaitIntroText(void);
void AdvanceRecordVSEraseOpenIntroText(void);

void AdvanceRecordVSEraseIndexChange(void);
void RequestRecordVSEraseOpenIntroText(void);
void RequestRecordVSEraseWaitIntroText(void);
void RequestRecordVSEraseCloseIntroText(void);
void RequestRecordVSEraseSlideInSub(void);
void RequestRecordVSEraseBrowse(void);
void RequestRecordVSErasePageSlideOut(void);
void RequestRecordVSErasePageSlideIn(void);
void RequestRecordVSEraseSubSlideOut(void);
void RequestRecordVSEraseOpenConfirmText(void);
void RequestRecordVSEraseWaitConfirmAnswer(void);
void RequestRecordVSEraseCloseConfirmSlideOutMain(void);
void RequestRecordVSEraseSlideInAfterConfirm(void);
void RequestRecordVSEraseSubSlideOutToScreen(void);
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
