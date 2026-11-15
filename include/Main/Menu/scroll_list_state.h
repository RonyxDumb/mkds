#pragma once

#include "types.h"
#include "Main/System/interpolation_value.h"
#include "Main/System/heap_call.h"
#include "code_02022aa8.h"
#include "Main/Graphics/cell_file_set.h"
#include "Main/Graphics/font_and_player_character.h"
#include "Main/Graphics/layout_entry_angle.h"
#include "Main/Graphics/locate_bmg_sections.h"
#include "Main/Menu/multi_select_member_group.h"
#include "tp.h"
#include "Main/Save/buddy_record_time.h"
#include "g2d_CellTransferManager.h"
#include "Main/Menu/select_kart_ghost_work.h"

unsigned int IsScrollListPickStarted(void);
unsigned int IsScrollListPickFinished(void);
void SetScrollListEnabled(unsigned int enabled);
unsigned int GetScrollListSelectedRow(void);

void AdvanceScrollList(void);
void InitScrollList(void *heap, s32 groupCount, const void *groupFirstEntries, u16 cursorEntry, u16 scrollEntry,
                    s32 scrollOffsetRange, LayoutTableEntry *entries, void *rects, const void *screenMap,
                    s32 upRectIndex, s32 downRectIndex, s32 firstRowRectIndex, s32 rowCount,
                    void (*callback)(int heap, int groupCount, int groupFirstEntries, int cursorEntry));

void ScrollListMI_CpuCopy16(const void *src, void *dst, u32 size);

typedef struct InputSlot InputSlot;

void ScrollListMI_CpuClearFast(void *dest, u32 size);
void ScrollListMI_CpuFillFast(void *dest, u32 value, u32 size);
void AdvanceScrollListPick(void);
void AdvanceScrollListScrollDown(void);
void AdvanceScrollListScrollUp(void);
void AdvanceScrollListSelectDown(void);
void AdvanceScrollListSelectUp(void);
void AdvanceScrollListIdle(void);
u16 ScrollListGetDownBits(u32 slotIndex, u32 mask);
u16 GetSlotDownBits(InputSlot *slot, u32 mask);

u32 ScrollListStartSeqArcWrapper(u32 index);
u32 ScrollListStartSeqArc(u32 index, u32 archiveNo);

u16 ScrollListGetNewBits(u32 slotIndex, u32 mask);
u16 ScrollListGetInputSlotNewBits(InputSlot *slot, u32 mask);
void AdvanceScrollListRightColumnTimer(void);
void SetScrollListRightColumnHighBits(s32 highBits);
void PlaceScrollListCursor(void);

u32 GetScrollListSelectedSlot(void);
unsigned int GetScrollListPositionYDifference(unsigned int first, unsigned int second);

void SetScrollListSlotVisible(s32 slot, s32 visible);

u32 GetScrollListHiddenBottomSlot(void);

typedef struct InputSlotPair InputSlotPair;

void PlaceScrollListScrollEntry(void);
void AdvanceScrollListInput(void);
u32 ScrollListSlotHasPairOrLost(u32 slotIndex);
u32 ScrollListHasPairOrLost(InputSlotPair *pair);

unsigned int ScrollListGetPairHasPair(InputSlotPair *pair);

u32 ScrollListIsPairRecentlyLost(InputSlotPair *pair);

u32 ScrollListGetSlotPairY(u32 slot);
unsigned int ScrollListGetPairY(InputSlotPair *pair);
u32 ScrollListGetSlotPairX(u32 slot);
unsigned int ScrollListGetPairX(InputSlotPair *pair);

u32 ScrollListIsSlotPairNew(u32 slotIndex);
u32 ScrollListIsPairNewUnlessLost(InputSlotPair *pair);
u32 ScrollListIsPairNew(InputSlotPair *pair);
void CallScrollListCallback(s32 action, s32 slot, s32 row, s32 selectedSlot);

extern struct ScrollList *gScrollList;
