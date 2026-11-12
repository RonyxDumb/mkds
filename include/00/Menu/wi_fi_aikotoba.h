#pragma once

#include "types.h"

extern u8 gWiFiAikotobaOffsetTableIndices[2][4];

#include "Main/Graphics/layout_entry_angle.h" // LayoutTableEntry

struct Unk02021dc8;
struct Ncgr;
struct Nclr;

// Object behind gWiFiAikotoba; LocateAndUploadWiFiAikotoba fills 0x20 to 0x30.
typedef struct WiFiAikotoba {
    /* 00 */ s32 mState;
    /* 04 */ s32 mNextState;
    /* 08 */ s32 mSelectedIndex;
    /* 0c */ s32 mStateFrames;
    /* 10 */ s32 mPendingWiFiState;
    /* 14 */ BOOL mHighlightVisible;
    /* 18 */ void *mHeap;
    // Table of cells built from the Bncl by InitLayoutTable.
    /* 1c */ LayoutTableEntry *mWiFiAikotobaTable;
    /* 20 */ struct Unk02021dc8 *mWiFiAikotobaSNcer;
    /* 24 */ struct Ncgr *mWiFiAikotobaSNcgr;
    /* 28 */ struct Nclr *mWiFiAikotobaSONclr;
    /* 2c */ struct LayoutEntryTable *mWiFiAikotobaBncl;
    /* 30 */ void *mWiFiAikotobaBnbl;
    /* 34 */ u8 pad_34[4];
    /* 38 */ struct Bmg *mWiFiMessages;
    /* 3c */ struct Bmg *mCommonMessages;
} WiFiAikotoba;

#include "00/code_02180608.h"
#include "00/Menu/wi_fi_vs_setting.h"
#include "Main/System/result_archive_path.h"

extern u8 gWiFiAikotobaCellIndices[2];
extern u8 gWiFiAikotobaXluCellIndices[2];
extern u8 gWiFiAikotobaSTableIndices[2];
extern s32 gWiFiAikotobaOffsetCellCounts[2];
extern u8 gWiFiAikotobaCheckOffsetIndices[2];
extern u8 gWiFiAikotobaCheckDigitLabelIndices[12];
extern WiFiStateCallbacks gWiFiAikotobaCallbacks;
extern char data_ov000_021b0ee8[];
extern char data_ov000_021b0ef4[];
extern WiFiAikotoba *gWiFiAikotoba;

void RegisterWiFiAikotobaCallbacks(void);
void WriteWiFiAikotobaRegisters(void);
void AdvanceWiFiAikotoba(void);
void UpdateWiFiAikotobaHighlight(void);
void AdvanceWiFiAikotobaState7(void);
void AdvanceWiFiAikotobaState6(void);
void AdvanceWiFiAikotobaState5(void);
void AdvanceWiFiAikotobaState4(void);
void AdvanceWiFiAikotobaState3(void);
void AdvanceWiFiAikotobaState2(void);
void AdvanceWiFiAikotobaState1(void);
void AdvanceWiFiAikotobaState0(void);
BOOL IsBuddyRecordBlockFull(void);
void LocateAndUploadWiFiAikotoba(void);
void ClearWiFiAikotobaPointer(void);
void InitWiFiAikotoba(void *heap);

#include "00/Menu/wi_fi_vs_matching.h"
