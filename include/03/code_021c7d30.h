#pragma once

#include "types.h"
#include "03/types_021d299c.h"

typedef struct Rect Rect;

// Table of bytes PlaceJb3ListSelectionPair reads.
typedef struct Jb3ListSelectionRectIndices {
    /* 00 */ u8 mUnk_00[0xe];
} Jb3ListSelectionRectIndices;

extern u8 gJb3ListPaletteRows[];
extern u8 gJb3ListBg2OffsetByEntry[];
extern Rect gJb3ListFixedRects[];
extern Rect gJb3ListSelectionRects[];
extern u8 gJb3ListTimerIds[];
extern Jb3ListSelectionRectIndices gJb3ListSelectionRectIndices;

void SetJb3ListMode(u8 mode);
void UpdateJb3ListMessageClose(void);
void UpdateJb3ListMessageResult(void);
BOOL IsJb3ListRecordValid(void);
void StartJb3ListIdTimer(void);
void AdvanceJb3ListIdTimers(void);
void RequestJb3ListPaletteRowCopy(void);
void MoveJb3ListSelection(s32 direction);
void SetJb3ListSelectedId(u32 listId);
void SetJb3ListSelectedIdFromRow(void);
void PlaceJb3ListSelectionPair(void);
void WriteJb3ListBgOffset(void);
void AdvanceJb3ListScrollYIncrease(u32 taskEntry);
void AdvanceJb3ListScrollYDecrease(u32 taskEntry);
int GetJb3ListEntryIndexOfRow(int row);
int GetJb3ListRowOfEntryIndex(int entryIndex);
u32 GetJb3ListHitId(void);
void RefreshJb3ListRowPositions(void);
void PrintJb3ListEntryBytes(const u8 *bytes, int row);
void PrintJb3ListEntryString(const u8 *bytes, int row);
void SetupJb3ListCell(int cellKind, int cellState, int row);
BOOL IsJb3ListIdEnabled(u32 listId);
void SetupJb3ListEntryCells(u32 entryIndex, int row);
void PrintJb3ListEntryText(u32 entryIndex, int row);
void RefreshJb3List(void);
void UpdateJb3ListRelease(void);
void UpdateJb3ListFadeOut(void);
void StartJb3ListClose(void);
void UpdateJb3ListScrollInput(void);
void func_ov003_021c9058(u32 newValue);
void func_ov003_021c9084(u32 newValue);
void StartJb3ListIdAction(u32 listId);
BOOL UpdateJb3ListHit(void);
void UpdateJb3ListInput(void);
void UpdateJb3List(void);
void UpdateJb3ListFadeIn(void);
void StartJb3ListFadeIn(void);
void ResetJb3ListScrollAndSelection(void);
void LoadJb3ListFilesAndSetBgCnt(void);
void CreateJb3List(void);
