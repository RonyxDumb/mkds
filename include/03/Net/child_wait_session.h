#pragma once

#include "types.h"
#include "03/Net/child_wait_session_object.h"

typedef struct ChildWaitSessionView ChildWaitSessionView;

// Calls of the step in CHILD_WAIT_STATE_MULTIBOOT_WAIT (ChildWaitSessionView.mMultiBootInitFrames) that must have run
// before a stop request is accepted in that state.
#define CHILD_WAIT_MULTIBOOT_INIT_FRAME_COUNT 6

// mStallCount value above which the session aborts, and the number of blocks mBlockNumber counts
// before it wraps (ChildWaitSessionView).
#define CHILD_WAIT_STALL_ABORT_LIMIT 0x1e0
#define CHILD_WAIT_BLOCK_COUNT 0x24


#include "wireless_link_control.h"
#include "03/Menu/wifi_menu_shared.h"

u16 GetChildWaitReplyCode(void);
void ReadChildWaitReply(void);
void ExchangeChildWaitSharedEntries(u16 code, u16 value, u8 *payload);
void ClearChildWaitSharedEntries(void);
u32 AcceptMatchingWhChild(WirelessMessage *event);
BOOL EndChildWaitWh(void);
void AdvanceChildWaitAfterReply(void);
void AdvanceChildWaitDataSharing(void);
void StartChildWaitDataConnect(void);
void AdvanceChildWaitMultiBoot(void);
void *GetChildWaitChildUser(void);
void GetChildWaitStateChange(u8 *stateOut, u8 *changedOut);
void AdvanceChildWaitState(void);
BOOL StartChildWaitDownload(void);
BOOL StartChildWaitSession(void);
void ResetChildWaitSessionState(void);
BOOL StopChildWaitSession(void);
void InitChildWaitSession(ChildWaitSessionView *session, ChildWaitParams *params);

extern ChildWaitSessionView *gChildWaitSessionView;
