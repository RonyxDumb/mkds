#pragma once

#include "types.h"
#include "Main/Graphics/layout_entry_angle.h" // LayoutTableEntry, LayoutEntryTable

typedef struct RecordTopMenu {
    /* 0x00 */ struct Unk02021dc8 *mRecordTopMenuMNcer;
    /* 0x04 */ LayoutEntryTable *mRecordTopMenuMBncl;
    /* 0x08 */ struct LayoutEntryTable *mRecordTopMenuMBnll;
    /* 0x0c */ struct Unk02021dc8 *mRecordTopMenuSNcer;
    /* 0x10 */ struct LayoutEntryTable *mRecordTopMenuSBncl;
    /* 0x14 */ struct LayoutEntryTable *mRecordTopMenuSBnbl;
    // one 0x40-byte record per cell of the Bncl (plus Bnll) members, built by InitLayoutTable
    /* 0x18 */ LayoutTableEntry *mRecordTopMenuMTable;
    // one 0x40-byte record per cell of the Bncl (plus Bnll) members, built by InitLayoutTable
    /* 0x1c */ LayoutTableEntry *mRecordTopMenuSTable;
    /* 0x20 */ void *mUnk_20;
    /* 0x24 */ struct Bmg *mRecordMessages;
    /* 0x28 */ void *mSecondScreenMapBuffer;
    /* 0x2c */ void *mHeap;
    /* 0x30 */ s32 mState;
    /* 0x34 */ s32 mNextState;
    /* 0x38 */ s32 mStateFrames; /* counted only in states 1, 2, 5, 6, 7, 11 */
    /* 0x3c */ s32 mBg0Offset;
    /* 0x40 */ s32 mIndex;
    /* 0x44 */ s32 mRecordScreen;
} RecordTopMenu;

#include "01/unk_021a6000.h"
#include "01/Menu/record_time_attack.h"
#include "01/Menu/code_02196d58.h"
#include "00/Menu/wi_fi_vs_setting.h"
#include "01/code_0219a000.h"
#include "Main/Menu/select_return.h"
#include "Main/Scene/display_settings.h"
#include "01/unk_021a9000.h"
#include "Main/Menu/second_menu_scene.h"
#include "Main/System/result_archive_path.h"

void RegisterRecordTopMenuCallbacks(void);
void WriteRecordTopMenuRegisters(void);
void WriteRecordTopMenuBgOffsets(void);
void AdvanceRecordTopMenu(void);
void AdvanceRecordTopMenuState11(void);
void AdvanceRecordTopMenuState10(void);
void AdvanceRecordTopMenuState9(void);
void AdvanceRecordTopMenuState8(void);
void AdvanceRecordTopMenuState7(void);
void AdvanceRecordTopMenuState6(void);
void AdvanceRecordTopMenuState5(void);
void AdvanceRecordTopMenuState4(void);
void AdvanceRecordTopMenuState3(void);
void AdvanceRecordTopMenuState2(void);
void AdvanceRecordTopMenuState1(void);
void AdvanceRecordTopMenuState0(void);
void ReleaseRecordTopMenu(void);
void InitRecordTopMenu(void *heap);
void RefreshRecordTopMenuGradeCells(void);
void DecrementRecordTopMenuIndex(void);
void IncrementRecordTopMenuIndex(void);
void RequestRecordTopMenuState11(void);
void RequestRecordTopMenuState10(void);
void RequestRecordTopMenuState9(void);
void RequestRecordTopMenuState8(void);
void RequestRecordTopMenuState7(void);
void RequestRecordTopMenuState6(void);
void RequestRecordTopMenuState5(void);
void RequestRecordTopMenuState4(void);
void RequestRecordTopMenuState3(void);
void RequestRecordTopMenuState2(void);
void RequestRecordTopMenuState1(void);
void ResetRecordTopMenu(void);
void SetRecordTopMenuRowOff(s32 row);
void SetRecordTopMenuRowOn(s32 row);
void LocateAndQueueRecordTopMenu(void);

#include "00/Menu/wi_fi_vs_matching.h"

extern const u16 gRecordTopMenuGradeSTableIndices[3];
extern const u16 gRecordTopMenuRowCellIndices[3];
extern const u16 gRecordTopMenuLabelWidths[3][3];
extern const s32 gRecordTopMenuTouchRowIndices[3];
extern const u16 gRecordTopMenuLabelHeights[3][3];
extern const s32 gRecordTopMenuRowRecordScreens[3];
extern const u16 gRecordTopMenuRecordMessageIndices[3];
extern const u16 gRecordTopMenuOffsetSTableIndices[3];
extern const u16 gRecordTopMenuRowSTableIndices[3];
extern const u16 gRecordTopMenuXluCellIndices[3];
extern const u16 gRecordTopMenuLabelIndices[3][3];
