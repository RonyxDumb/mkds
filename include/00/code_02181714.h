#pragma once

#include "types.h"

extern u8 gWiFiTopMenuOffsetTableIndices[][5];

#include "Main/Unknown/code_0201ea58.h"
#include "Main/Unknown/code_02124094.h"

struct Unk02021dc8;
struct Ncgr;
struct Nclr;

// Object behind gWiFiTopMenu; LocateAndQueueWiFiTopMenu fills 0x20 to 0x30.
typedef struct WiFiTopMenu {
    /* 00 */ s32 mState;
    /* 04 */ u32 mNextState;
    /* 08 */ s32 mIndex;
    /* 0c */ s32 mStateFrames;
    /* 10 */ s32 mPendingWiFiState;
    /* 14 */ void *mHeap;
    /* 18 */ BOOL mHighlightVisible;
    // Table of cells built from the Bncl / Bnll by InitLayoutTable.
    /* 1c */ LayoutTableEntry *mWiFiTopMenuTable;
    /* 20 */ struct Unk02021dc8 *mWiFiTopMenuSNcer;
    /* 24 */ struct Ncgr *mWiFiTopMenuSNcgr;
    /* 28 */ struct Nclr *mWiFiTopMenuSONclr;
    /* 2c */ struct LayoutEntryTable *mWiFiTopMenuBncl;
    /* 30 */ LayoutEntryTable *mWiFiTopMenuBnbl;
    /* 34 */ u8 pad_34[4];
    /* 38 */ void *mWiFiMessages;
    /* 3c */ void *mCommonMessages;
} WiFiTopMenu;

#include "00/code_02180608.h"
#include "00/unk_021b4000.h"
#include "00/code_02181f98.h"
#include "g2d_NAN_load.h"
#include "Main/Unknown/code_020b4000.h"
#include "Main/Unknown/code_02047104.h"

// Objects whose layout isn't known yet.
extern u8 gWiFiTopMenuXluCellIndices[];
extern const u8 gWiFiTopMenuSTableIndices[];
extern const u8 gWiFiTopMenuCellIndices[];
// Objects whose layout isn't known yet.
extern s32 gWiFiTopMenuOffsetCellCounts[];
extern WiFiStateCallbacks gWiFiTopMenuCallbacks;
extern WiFiTopMenu *gWiFiTopMenu;

void RegisterWiFiTopMenuCallbacks(void);
void WriteWiFiTopMenuRegisters(void);
void AdvanceWiFiTopMenu(void);
void UpdateWiFiTopMenuHighlight(void);
void AdvanceWiFiTopMenuState8(void);
void AdvanceWiFiTopMenuState7(void);
void AdvanceWiFiTopMenuState6(void);
void AdvanceWiFiTopMenuState5(void);
void AdvanceWiFiTopMenuState4(void);
void AdvanceWiFiTopMenuState3(void);
void AdvanceWiFiTopMenuState2(void);
void AdvanceWiFiTopMenuState1(void);
void AdvanceWiFiTopMenuState0(void);
s32 IsUserDataFriendKeyNonZeroWrapper(void);
void LocateAndQueueWiFiTopMenu(void);
void ClearWiFiTopMenuPointer(void);
void InitWiFiTopMenu(void *heap);

#include "00/code_021832d8.h"
