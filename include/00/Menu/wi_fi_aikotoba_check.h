#pragma once

#include "types.h"
#include "Main/Graphics/layout_entry_angle.h" // LayoutTableEntry, LayoutEntryTable

struct NNSG2dCellDataBank;
struct Ncgr;
struct Nclr;

// States of WiFiAikotobaCheck.mState and mNextState, in the order of the AdvanceWiFiAikotobaCheckStateN calls.
enum {
    WIFI_AIKOTOBA_CHECK_STATE_SLIDE_IN,
    WIFI_AIKOTOBA_CHECK_STATE_WAIT_INPUT,
    WIFI_AIKOTOBA_CHECK_STATE_SLIDE_OUT,
};

// Frames the digits panel takes to slide in or out, and WiFiAikotobaCheck.mOffset while it is off screen.
#define WIFI_AIKOTOBA_CHECK_SLIDE_FRAMES 15
#define WIFI_AIKOTOBA_CHECK_OFFSET_HIDDEN 0x50

// Object behind gWiFiAikotobaCheck; LocateAndUploadWiFiAikotobaCheck fills 0x34 to 0x48.
typedef struct WiFiAikotobaCheck {
    /* 00 */ s32 mState;
    /* 04 */ s32 mNextState;
    /* 08 */ s32 mStateFrames;
    /* 0c */ s16 mOffset;
    /* 0e */ u16 mDigits[12];
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
void AdvanceWiFiAikotobaCheckSlideOut(void);
void AdvanceWiFiAikotobaCheckWaitInput(void);
void AdvanceWiFiAikotobaCheckSlideIn(void);
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
