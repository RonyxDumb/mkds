#pragma once

#include "types.h"
#include "03/System/tasks.h"

typedef struct ChildWaitSession ChildWaitSession;

// The parameters of a child wait session: file paths, game name and introduction text, game id and handshake byte.
typedef struct ChildWaitParams {
    /* 00 */ void *mRomFilePathp;
    /* 04 */ void *mGameNamep;
    /* 08 */ void *mGameIntroductionp;
    /* 0c */ void *mBannerCharFilePathp;
    /* 10 */ void *mBannerPaletteFilePathp;
    /* 14 */ u32 mGgid;
    /* 18 */ u8 mHandshakeByte;
    /* 19 */ u8 pad_19[3];
} ChildWaitParams;


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
