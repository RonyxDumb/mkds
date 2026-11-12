#pragma once

#include "types.h"
#include "03/types_021d299c.h"

typedef struct OamEntry OamEntry;
typedef struct BgTextCanvas BgTextCanvas;
typedef struct Rect Rect;

// 0x5c bytes.
typedef struct ApList {
    /* 00 */ u8 *mEntries;
    /* 04 */ void *mXb4ApListBackNsc;
    /* 08 */ void *mYbBgStep31Ncl;
    /* 0c */ BgTextCanvas *mTextCanvas;
    /* 10 */ OamEntry *mRowLeftOamEntries[5];
    /* 24 */ OamEntry *mRowRightOamEntries[5];
    /* 38 */ u32 mScrollTask;
    /* 3c */ u32 mBgOffsetTask;
    /* 40 */ u16 mScrollYMax;
    /* 42 */ u16 mRowLeftTiles[3];
    /* 48 */ u16 mRowRightTiles[4];
    /* 50 */ s8 mHitRow;
    /* 51 */ u8 mEntryCount;
    /* 52 */ u8 mEntryIndex;
    /* 53 */ u8 mScrollBarOffsetMax;
    /* 54 */ u8 mSelectionMade;
    /* 55 */ u8 mScrollTimer;
    /* 56 */ u8 mBgOffsetPending;
    /* 57 */ u8 mScrollBarDragging;
    /* 58 */ u8 mBarBlockedSoundPlayed;
    /* 59 */ u8 mKeyBlockedSoundPlayed;
} ApList;

void RequestApListPaletteRowCopy(void);
void StartApListScrollYIncrease(void);
void StartApListScrollYDecrease(void);
void MoveApListSelectedRow(int direction);
void PlaceApListSelection(void);
void WriteApListBgOffset(void);
void AdvanceApListScrollYIncrease(u32 task);
void AdvanceApListScrollYDecrease(u32 task);
void RefreshApListRowPositions(void);
void SetApListRowTiles(int entryIndex, int rowSlot);
void PrintApListEntryText(int entryIndex, int yPos);
void RefreshApList(void);
void UpdateApListRelease(void);
void UpdateApListFadeOut(void);
void StartApListClose(void);
void UpdateApListResult(void);
void UpdateApListScroll(void);
void UpdateApListInput(void);
void UpdateApList(void);
void UpdateApListButtonsIn(void);
void UpdateApListFadeIn(void);
void StartApListFadeIn(void);
void CreateApListRowObjects(void);
void SetupApListScroll(void);
void LoadApListFilesAndSetBgCnt(void);
void CreateApList(void);

extern const u8 gApListRowLeftImageIndices[3];
extern const u8 gApListRowRightImageIndices[4];
extern const Rect gApListRowRects[5];
extern const Rect gApListSelectionRects[5];
extern u8 gApListPaletteRow[1];
extern u8 gApListSelectedRow;
extern u16 gApListScrollY;
extern struct ApList *gApList;
