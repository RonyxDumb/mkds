#pragma once

#include "types.h"
#include "03/types_021d299c.h"
#include "03/unk_021d7000.h"
#include "03/unk_021da000.h"

typedef struct Rect Rect;

// Table of bytes PlaceJb3ListSelectionPair reads.
typedef struct Jb3ListSelectionRectIndices {
    /* 00 */ u8 mRectIndices[0xe];
} Jb3ListSelectionRectIndices;

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
void SetJb3ListDnsNone(u32 newValue);
void SetJb3ListIpNone(u32 newValue);
void StartJb3ListIdAction(u32 listId);
BOOL UpdateJb3ListHit(void);
void UpdateJb3ListInput(void);
void UpdateJb3List(void);
void UpdateJb3ListFadeIn(void);
void StartJb3ListFadeIn(void);
void ResetJb3ListScrollAndSelection(void);
void LoadJb3ListFilesAndSetBgCnt(void);
void CreateJb3List(void);

extern u8 gJb3ListTimerIds[4];
extern const u8 gJb3ListPaletteRows[3];
extern const u8 gJb3ListEntryIndexById[11];
extern const u8 gJb3ListIdByEntryIndex[9];
extern const Rect gJb3ListSelectionRects[6];
extern Jb3ListSelectionRectIndices gJb3ListSelectionRectIndices;
extern const u8 gJb3ListBg2OffsetByEntry[9];
extern const Rect gJb3ListCellRect;
extern const Rect gJb3ListLeftButtonRect;
extern const Rect gJb3ListRightButtonRect;
extern const Rect gJb3ListFixedRects[3];
extern u16 gDotSeparatedBytesFormat[15];
extern const u8 gJb3ListCellImageIds[5][3];
extern const u16 gJb3ListBackNscOffsets[9];
// Objects whose layout isn't known yet.
extern const s8 gJb3ListDigitColumns[6];

extern u8 gJb3ListSelectedId;
extern u8 gJb3ListMode;
extern u16 gJb3ListScrollY;
extern u8 gJb3ListSelectedRow;
extern struct Jb3List *gJb3List;
