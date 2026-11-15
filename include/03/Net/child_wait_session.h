#pragma once

#include "types.h"
#include "03/Net/child_wait_session_object.h"

typedef struct ChildWaitSessionView ChildWaitSessionView;

// Frames the multiboot parent has to run before the session may stop it (ChildWaitSessionView.mMultiBootInitFrames).
#define CHILD_WAIT_MULTIBOOT_MIN_RUN_FRAMES 6

// mStallCount value above which the session aborts, and the number of blocks mBlockNumber counts
// before it wraps (ChildWaitSessionView).
#define CHILD_WAIT_STALL_ABORT_LIMIT 0x1e0
#define CHILD_WAIT_BLOCK_COUNT 0x24


#include "code_02142eac.h"
#include "03/unk_021da000.h"

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
