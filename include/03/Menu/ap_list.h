#pragma once

#include "types.h"
#include "03/System/tasks.h"
#include "03/System/touch_key_input.h"
#include "03/Net/ap_scan_types.h"

typedef struct OamEntry OamEntry;
typedef struct BgTextCanvas BgTextCanvas;
typedef struct Rect Rect;

// Rows of the list that show at once (the row after them is the button row), the entry count up to which the scroll bar
// offset maximum is the smaller one (up to the visible rows it is 0), and the calls a dragged scroll bar waits between
// redraws.
#define AP_LIST_VISIBLE_ROWS 4
#define AP_LIST_SMALL_ENTRY_COUNT_MAX 8
#define AP_LIST_SCROLL_TIMER_FRAMES 4

// Values of gApListSelectedRow.
#define AP_LIST_ROW_FIRST_VISIBLE 0
#define AP_LIST_ROW_SECOND_VISIBLE 1
#define AP_LIST_ROW_THIRD_VISIBLE 2
#define AP_LIST_ROW_LAST_VISIBLE 3
#define AP_LIST_ROW_BUTTON 4

// The list of scanned access points: its entries, text canvas, row objects, scroll and background offset tasks, hit row
// and chosen entry.
typedef struct ApList {
    /* 00 */ ApScanEntry *mEntries;
    /* 04 */ void *mXb4ApListBackNsc;
    /* 08 */ void *mYbBgStep31Ncl;
    /* 0c */ BgTextCanvas *mTextCanvas;
    /* 10 */ OamEntry *mRowLeftOamEntries[5];
    /* 24 */ OamEntry *mRowRightOamEntries[5];
    /* 38 */ TaskEntry *mScrollTask;
    /* 3c */ TaskEntry *mBgOffsetTask;
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
void WriteApListBgOffset(TaskEntry *task, void *arg);
void AdvanceApListScrollYIncrease(TaskEntry *task, void *arg);
void AdvanceApListScrollYDecrease(TaskEntry *task, void *arg);
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
