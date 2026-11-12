#pragma once

#include "types.h"

void AdvanceRecordVSIndexChange(void);
void RequestRecordVSState0(void);
void RequestRecordVSState1(void);
void RequestRecordVSState2AndRefreshPage(void);
void RequestRecordVSState3(void);
void RequestRecordVSState4(void);
void RequestRecordVSState5(void);
void RequestRecordVSState6AndChangePage(void);
void RequestRecordVSState7(void);
void RequestRecordVSState8(void);
void RequestRecordVSState9(void);
void RequestRecordVSState10(void);
void RequestRecordVSState11AndRefreshPage(void);
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
typedef struct EmblemData {
    /* 000 */ u8 mPixels[0x200];
    /* 200 */ u8 mHasPixels;
} EmblemData;

void BuildRecordList(void);
u16 GetRecordCount(void);
s32 IsRecordFlagged(u16 listIndex);
s32 GetRecordMatchKind0FirstCount(u16 listIndex);
s32 GetRecordMatchKind1FirstCount(u16 listIndex);
s32 GetRecordMatchKind2FirstCount(u16 listIndex);
s32 GetRecordMatchKind0SecondCount(u16 listIndex);
s32 GetRecordMatchKind1SecondCount(u16 listIndex);
s32 GetRecordMatchKind2SecondCount(u16 listIndex);
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
