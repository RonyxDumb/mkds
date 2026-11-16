#pragma once

#include "types.h"

#include "Main/Graphics/layout_entry_angle.h" // LayoutTableEntry

struct NNSG2dCellDataBank;
struct Ncgr;
struct Nclr;

// Values of WiFiAikotoba.mState and mNextState.
enum {
    WIFI_AIKOTOBA_STATE_WAIT_FADE,
    WIFI_AIKOTOBA_STATE_SLIDE_IN,
    WIFI_AIKOTOBA_STATE_WAIT_SELECT_RETURN,
    WIFI_AIKOTOBA_STATE_INPUT,
    WIFI_AIKOTOBA_STATE_PRESS,
    WIFI_AIKOTOBA_STATE_SLIDE_OUT,
    WIFI_AIKOTOBA_STATE_BUDDY_FULL_NOTICE,
    WIFI_AIKOTOBA_STATE_BUDDY_FULL_ASK,
};

// Frames the two cell rows take to slide in or out, the press state lasts, and the frame of it where the highlight
// shows again; the x offset of the table cells while they are off screen (the first row's cells use the negative of it
// while sliding).
#define WIFI_AIKOTOBA_SLIDE_FRAMES 10
#define WIFI_AIKOTOBA_PRESS_FRAMES 10
#define WIFI_AIKOTOBA_PRESS_HIGHLIGHT_FRAMES 5
#define WIFI_AIKOTOBA_OFFSET_HIDDEN 0xfa

// The Wi-Fi friend key menu: its state, selected index, heap, cell and layout tables and messages.
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
    /* 20 */ struct NNSG2dCellDataBank *mWiFiAikotobaSNcer;
    /* 24 */ struct Ncgr *mWiFiAikotobaSNcgr;
    /* 28 */ struct Nclr *mWiFiAikotobaSONclr;
    /* 2c */ struct LayoutEntryTable *mWiFiAikotobaBncl;
    /* 30 */ void *mWiFiAikotobaBnbl;
    /* 34 */ u8 pad_34[4];
    /* 38 */ struct Bmg *mWiFiMessages;
    /* 3c */ struct Bmg *mCommonMessages;
} WiFiAikotoba;

#include "00/Menu/wi_fi_state_machine.h"
#include "00/Menu/wi_fi_vs_setting.h"
#include "Main/System/result_archive_path.h"

void RegisterWiFiAikotobaCallbacks(void);
void WriteWiFiAikotobaRegisters(void);
void AdvanceWiFiAikotoba(void);
void UpdateWiFiAikotobaHighlight(void);
void AdvanceWiFiAikotobaBuddyFullAsk(void);
void AdvanceWiFiAikotobaBuddyFullNotice(void);
void AdvanceWiFiAikotobaSlideOut(void);
void AdvanceWiFiAikotobaPress(void);
void AdvanceWiFiAikotobaInput(void);
void AdvanceWiFiAikotobaWaitSelectReturn(void);
void AdvanceWiFiAikotobaSlideIn(void);
void AdvanceWiFiAikotobaWaitFade(void);
BOOL IsBuddyRecordBlockFull(void);
void LocateAndUploadWiFiAikotoba(void);
void ClearWiFiAikotobaPointer(void);
void InitWiFiAikotoba(void *heap);

#include "00/Menu/wi_fi_vs_matching.h"

extern const u8 gWiFiAikotobaCellIndices[2];
extern const u8 gWiFiAikotobaSTableIndices[2];
extern const s32 gWiFiAikotobaOffsetCellCounts[2];
extern const u8 gWiFiAikotobaOffsetTableIndices[2][4];
extern const u8 gWiFiAikotobaXluCellIndices[2];
extern WiFiStateCallbacks gWiFiAikotobaCallbacks;
extern WiFiAikotoba *gWiFiAikotoba;
