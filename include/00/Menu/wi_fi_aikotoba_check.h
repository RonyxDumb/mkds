#pragma once

#include "types.h"
#include "Main/Graphics/layout_entry_angle.h" // LayoutTableEntry, LayoutEntryTable

struct NNSG2dCellDataBank;
struct Ncgr;
struct Nclr;

// Object behind gWiFiAikotobaCheck; LocateAndUploadWiFiAikotobaCheck fills 0x34 to 0x48.
typedef struct WiFiAikotobaCheck {
    /* 00 */ s32 mState;
    /* 04 */ s32 mNextState;
    /* 08 */ s32 mStateFrames;
    /* 0c */ s16 mOffset;
    /* 0e */ u16 mDigits[12];
    /* 26 */ u8 pad_26[2];
    /* 28 */ s32 mPendingWiFiState;
    /* 2c */ void *mHeap;
    // Table of cells built from the Bncl / Bnll by InitLayoutTable.
    /* 30 */ LayoutTableEntry *mWiFiAikotobaCheckTable;
    /* 34 */ struct NNSG2dCellDataBank *mWiFiAikotobaCheckMNcer;
    /* 38 */ struct Ncgr *mWiFiAikotobaCheckMNcgr;
    /* 3c */ struct Nclr *mWiFiAikotobaCheckMONclr;
    /* 40 */ LayoutEntryTable *mWiFiAikotobaCheckBncl;
    /* 44 */ u8 mUnk_44[4];
    /* 48 */ struct LayoutEntryTable *mWiFiAikotobaCheckBnll;
    /* 4c */ void *mWiFiMessages;
    /* 50 */ void *mCommonMessages;
} WiFiAikotobaCheck;

#include "00/code_02180608.h"
#include "00/Menu/wi_fi_vs_setting.h"
#include "Main/System/result_archive_path.h"

void RegisterWiFiAikotobaCheckCallbacks(void);
void WriteWiFiAikotobaCheckRegistersNop(void);
void AdvanceWiFiAikotobaCheck(void);
void AdvanceWiFiAikotobaCheckState2(void);
void AdvanceWiFiAikotobaCheckState1(void);
void AdvanceWiFiAikotobaCheckState0(void);
void UpdateWiFiAikotobaCheckOffsets(void);
void LocateAndUploadWiFiAikotobaCheck(void);
void ClearWiFiAikotobaCheckPointer(void);
void InitWiFiAikotobaCheck(void *heap);
void InitWiFiAikotobaCheckDigits(void);
void SetWiFiAikotobaCheckDigits(void);

#include "00/Menu/wi_fi_vs_matching.h"

extern const u8 gWiFiAikotobaCheckOffsetIndices[2];
extern const u8 gWiFiAikotobaCheckDigitLabelIndices[12];
extern WiFiStateCallbacks gWiFiAikotobaCheckCallbacks;
extern WiFiAikotobaCheck *gWiFiAikotobaCheck;
