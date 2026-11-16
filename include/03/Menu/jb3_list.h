#pragma once

#include "types.h"
#include "03/System/tasks.h"
#include "03/System/touch_key_input.h"
#include "03/Menu/wifi_menu_strings.h"
#include "03/Menu/wifi_menu_shared.h"

typedef struct Rect Rect;

// Ids of what can be hit or selected in the list (gJb3ListSelectedId, Jb3List.mChosenId). The IP and DNS rows each
// have two ids; the first one is the choice that clears the addresses.
#define JB3_ID_SSID 0
#define JB3_ID_KEY 1
#define JB3_ID_IP_AUTO 2
#define JB3_ID_IP_MANUAL 3
#define JB3_ID_IP_ADDRESS 4
#define JB3_ID_NETMASK 5
#define JB3_ID_GATEWAY 6
#define JB3_ID_DNS_AUTO 7
#define JB3_ID_DNS_MANUAL 8
#define JB3_ID_DNS_FIRST 9
#define JB3_ID_DNS_SECOND 10
#define JB3_ID_CONNECT 11
#define JB3_ID_SAVE 12
#define JB3_ID_BACK 13
#define JB3_ID_NONE 14

// Rows of the list (entry index).
#define JB3_ENTRY_SSID 0
#define JB3_ENTRY_WEP_KEY 1
#define JB3_ENTRY_IP_MODE 2
#define JB3_ENTRY_IP_ADDRESS 3
#define JB3_ENTRY_NETMASK 4
#define JB3_ENTRY_GATEWAY 5
#define JB3_ENTRY_DNS_MODE 6
#define JB3_ENTRY_DNS_FIRST 7
#define JB3_ENTRY_DNS_SECOND 8

// Frames a dragged scroll bar waits between redraws, and frames a hit IP or DNS choice stays highlighted.
#define JB3_LIST_SCROLL_TIMER_FRAMES 4
#define JB3_LIST_ID_PRESSED_FRAMES 0x14

// Table of bytes PlaceJb3ListSelectionPair reads.
typedef struct Jb3ListSelectionRectIndices {
    /* 00 */ u8 mRectIndices[0xe];
} Jb3ListSelectionRectIndices;

void SetJb3ListMode(u8 mode);
void UpdateJb3ListMessageClose(void);
void UpdateJb3ListMessageResult(void);
BOOL IsJb3ListRecordValid(void);
void StartJb3ListIdTimer(void);
void AdvanceJb3ListIdTimers(TaskEntry *task, void *arg);
void RequestJb3ListPaletteRowCopy(void);
void MoveJb3ListSelection(s32 direction);
void SetJb3ListSelectedId(u32 listId);
void SetJb3ListSelectedIdFromRow(void);
void PlaceJb3ListSelectionPair(void);
void WriteJb3ListBgOffset(TaskEntry *task, void *arg);
void AdvanceJb3ListScrollYIncrease(TaskEntry *taskEntry, void *arg);
void AdvanceJb3ListScrollYDecrease(TaskEntry *taskEntry, void *arg);
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
extern const OriginSizeRect gJb3ListCellRect;
extern const OriginSizeRect gJb3ListLeftButtonRect;
extern const OriginSizeRect gJb3ListRightButtonRect;
extern const Rect gJb3ListFixedRects[3];
extern u16 gDotSeparatedBytesFormat[15];
extern const u8 gJb3ListCellImageIds[5][3];
extern const u16 gJb3ListBackNscOffsets[9];
extern const s8 gJb3ListDigitColumns[6];

extern u8 gJb3ListSelectedId;
extern u8 gJb3ListMode;
extern u16 gJb3ListScrollY;
extern u8 gJb3ListSelectedRow;
extern struct Jb3List *gJb3List;
