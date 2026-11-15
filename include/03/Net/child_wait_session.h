#pragma once

#include "types.h"
#include "03/Net/child_wait_session_object.h"

typedef struct ChildWaitSessionView ChildWaitSessionView;


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
