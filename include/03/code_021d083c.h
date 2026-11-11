#pragma once

#include "types.h"

typedef struct ChildWaitSessionView ChildWaitSessionView;

typedef struct ChildWaitParamsView {
    /* 00 */ u32 mRomFilePathp;
    /* 04 */ u32 mGameNamep;
    /* 08 */ u32 mGameIntroductionp;
    /* 0c */ u32 mIconCharPathp;
    /* 10 */ u32 mIconPalettePathp;
    /* 14 */ u32 mGgid;
    /* 18 */ u8 mHandshakeByte;
} ChildWaitParamsView;

#include "code_02142eac.h"
#include "03/unk_021da000.h"

u16 GetChildWaitReplyCode(void);
void ReadChildWaitReply(void);
void ExchangeChildWaitSharedEntries(u16 code, u16 value, u8 *payload);
void ClearChildWaitSharedEntries(void);
u32 AcceptMatchingWhChild(Unk021425e8 *event);
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
void InitChildWaitSession(ChildWaitSessionView *session, ChildWaitParamsView *params);
