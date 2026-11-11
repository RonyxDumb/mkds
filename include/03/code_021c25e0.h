#pragma once

#include "types.h"

typedef struct ChildWaitSession {
    /* 00000 */ u8 pad_00000[0x1e280];
    /* 1e280 */ u8 mChildUser[0x18];
    /* 1e298 */ void (*mCallback)(s32 a);
    /* 1e29c */ u32 mStepTask;
    /* 1e2a0 */ u8 mUnk_1e2a0;
    /* 1e2a1 */ u8 mStopRequested;
} ChildWaitSession;

typedef struct ChildWaitParams {
    /* 00 */ void *mUnk_00;
    /* 04 */ void *mUnk_04;
    /* 08 */ void *mUnk_08;
    /* 0c */ u8 pad_0c[0xc];
    /* 18 */ u8 mUnk_18;
    /* 19 */ u8 pad_19[3];
} ChildWaitParams;

#include "03/unk_021da000.h"

extern ChildWaitParams gChildWaitParams;
extern ChildWaitSession *gChildWaitSession;

void AdvanceChildWaitSession(u32 task);
u8 *GetChildUserBuffer(void);
u32 ConfirmChildWaitUser(void);
void SetChildWaitCallback(void *callback);
BOOL IsChildWaitSessionReleased(void);
void AdvanceChildWaitStop(u32 task);
void StartChildWaitStop(void);
void CreateChildWaitSession(u32 callback);
