#pragma once

#include "types.h"
#include "Main/Menu/menu_screens_work.h"
#include "Main/System/backup_net_camera_work.h"

void AdvanceRecordVSIndexChange(void);
void RequestRecordVSWaitFade(void);
void RequestRecordVSSlideInMain(void);
void RequestRecordVSSlideInSubAndRefreshPage(void);
void RequestRecordVSWaitReturnButton(void);
void RequestRecordVSBrowse(void);
void RequestRecordVSPageSlideOut(void);
void RequestRecordVSPageSlideInAndChangePage(void);
void RequestRecordVSSubSlideOut(void);
void RequestRecordVSMainSlideOut(void);
void RequestRecordVSPressButton(void);
void RequestRecordVSSubSlideOutRequestScreen(void);
void RequestRecordVSSubSlideInFromEraseAndRefreshPage(void);
void InitRecordVS(void *heap);
void ReleaseRecordVS(void);

BOOL IsRecordVSIndexChangeRunning(void);

void AdvanceRecordVSOffsetTimers(void);
void ToggleRecordVSRowFlag(s32 row);

void DecrementRecordVSIndex(void);
void IncrementRecordVSIndex(void);

u32 DecrementRecordVSPageIndex(void);
u32 IncrementRecordVSPageIndex(void);

void AdvanceRecordVSRowObjects(void);
void PrintRecordVSShownRecord(void);
void RefreshRecordVSPage(void);

BOOL IsRecordVSRowFilled(int row);

u16 GetRecordVSFirstRecordIndex(void);

void LocateAndQueueRecordVS(void);

// An emblem's 0x200 bytes of pixels and a byte that is 1 once the pixels are filled in.
// An emblem: its pixel bytes and whether they are filled in.
typedef struct EmblemData {
    /* 000 */ u8 mPixels[EMBLEM_PIXEL_BYTES];
    /* 200 */ u8 mHasPixels;
} EmblemData;

void BuildRecordList(void);
u16 GetRecordCount(void);
s32 IsRecordFlagged(u16 listIndex);
s32 GetRecordVsWinCount(u16 listIndex);
s32 GetRecordBattleWinCount(u16 listIndex);
s32 GetRecordWiFiRaceWinCount(u16 listIndex);
s32 GetRecordVsLossCount(u16 listIndex);
s32 GetRecordBattleLossCount(u16 listIndex);
s32 GetRecordWiFiRaceLossCount(u16 listIndex);
s32 GetRecordDate(u16 listIndex, void *dateBytes);
void CopyRecordText(u16 listIndex, void *buffer, u32 bufferSize);
s32 SetRecordFlag(u16 listIndex);
s32 ClearRecordFlag(u16 listIndex);
void ReadRecordEmblem(u16 listIndex, EmblemData *emblem, void *tiles);
void EraseRecord(u16 listIndex);
s32 GetRecordFriendKeyText(u16 listIndex, void *text);

void ClearRecordListPointer(void);

void CreateRecordList(void *heap);

u16 GetRecordSortKey(u16 listIndex);
void SortRecordRange(s32 first, u16 count);

extern struct RecordList *gRecordList;

extern struct RecordVS *gRecordVS;
