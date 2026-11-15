#pragma once

#include "types.h"
#include "03/System/tasks.h"

typedef struct ChildWaitSession {
    /* 00000 */ u8 pad_00000[0x1e280];
    /* 1e280 */ u8 mChildUser[0x18];
    /* 1e298 */ void (*mCallback)(s32 a);
    /* 1e29c */ TaskEntry *mStepTask;
    /* 1e2a0 */ u8 mEventPending;
    /* 1e2a1 */ u8 mStopRequested;
} ChildWaitSession;

typedef struct ChildWaitParams {
    /* 00 */ void *mRomFilePathp;
    /* 04 */ void *mGameNamep;
    /* 08 */ void *mGameIntroductionp;
    /* 0c */ void *mBannerCharFilePathp;
    /* 10 */ void *mBannerPaletteFilePathp;
    /* 14 */ u32 mUnk_14;
    /* 18 */ u8 mHandshakeByte;
    /* 19 */ u8 pad_19[3];
} ChildWaitParams;

#include "03/unk_021da000.h"

void AdvanceChildWaitSession(TaskEntry *task, void *arg);
u8 *GetChildUserBuffer(void);
u32 ConfirmChildWaitUser(void);
void SetChildWaitCallback(void *callback);
BOOL IsChildWaitSessionReleased(void);
void AdvanceChildWaitStop(TaskEntry *task, void *arg);
void StartChildWaitStop(void);
void CreateChildWaitSession(void (*callback)(s32));

extern ChildWaitParams gChildWaitParams;
extern ChildWaitSession *gChildWaitSession;
