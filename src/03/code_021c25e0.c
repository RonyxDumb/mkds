#include "03/code_021c25e0.h"
#include "03/code_021d083c.h"
#include "03/code_021d1000.h"
#include "03/code_021d3000.h"

#include "03/code_021d27d8.h"
#include "03/code_021d3488.h"
#include "code_0214cfe4.h"
#include "03/code_021c209c.h"
#include "03/code_021c2530.h"
#include "03/code_021bf4dc.h"
#include "03/code_021d1fd0.h"
#include "03/unk_021d5000.h"
#include "03/unk_021da000.h"
#include "03/code_021bf410.h"
#include "code_0200fc8c.h"

void CreateChildWaitSession(u32 callback) {
    ChildWaitParams params;
    gChildWaitSession = AllocExpHeapBlock(0x1e2a4, 0x20);
    gChildWaitSession->mCallback = (void (*)(s32)) callback;
    gChildWaitSession->mUnk_1e2a0 = 0;
    gChildWaitSession->mStopRequested = 0;
    params = gChildWaitParams;
    params.mUnk_04 = GetMessageEntry(gMessages, 0xf);
    params.mUnk_08 = GetMessageEntry(gMessages, 0x10);
    params.mUnk_18 = GetLanguageIndex() + 0x31;
    func_ov003_021d1358((Unk021da2ac *) gChildWaitSession, (Unk021d1358 *) &params);
    if (func_ov003_021d11d4() == 0) {
        OS_Terminate();
    }
    gChildWaitSession->mStepTask = AddTask(0, AdvanceChildWaitSession, NULL, 0x78);
}

void StartChildWaitStop(void) {
    AddTask(0, &AdvanceChildWaitStop, NULL, 0x78);
}

void AdvanceChildWaitStop(u32 task) {
    int result;
    result = func_ov003_021d1290();
    if (result != 0) {
        gChildWaitSession->mStopRequested = 1;
        RequestTaskRemoval(0, task);
    }
}

BOOL IsChildWaitSessionReleased(void) {
    if (gChildWaitSession == NULL) {
        return 1;
    }
    return 0;
}

void SetChildWaitCallback(void *callback) {
    gChildWaitSession->mCallback = (void (*)(s32)) callback;
}

u32 ConfirmChildWaitUser(void) {
    u32 result;
    u32 functionAddress;
    functionAddress = (u32) &func_ov003_021d11a0;
    result = func_ov003_021d11a0();
    return result;
}

u8 *GetChildUserBuffer(void) {
    return gChildWaitSession->mChildUser;
}

static inline void func_ov003_021c25e0_inline(const void *source, void *destination, s32 size) {
    MIi_CpuCopy16(source, destination, size);
}

void AdvanceChildWaitSession(u32 task) {
    u8 stateInfo[2];
    ChildWaitSession *object;
    func_ov003_021d0ee0();
    object = gChildWaitSession;
    if (object->mUnk_1e2a0 != 0 && object->mStopRequested == 0) {
        if (object->mCallback == NULL) {
            return;
        }
        object->mCallback(0);
        return;
    }
    func_ov003_021d0e9c(&stateInfo[0], &stateInfo[1]);
    switch (stateInfo[0]) {
        case 1:
        case 2:
        case 3:
        case 4:
            break;
        case 5:
            if (stateInfo[1] == 0) {
                break;
            }
            func_ov003_021c25e0_inline(func_ov003_021d0e90(), gChildWaitSession->mChildUser, 0x16);
            if (gChildWaitSession->mCallback != NULL) {
                gChildWaitSession->mCallback(0);
            } else {
                gChildWaitSession->mUnk_1e2a0 = 1;
            }
            break;
        case 13:
            if (stateInfo[1] == 0) {
                break;
            }
            if (gChildWaitSession->mCallback != NULL) {
                gChildWaitSession->mCallback(1);
            } else {
                gChildWaitSession->mUnk_1e2a0 = 1;
            }
            break;
        case 20:
        case 23:
            if (stateInfo[1] == 0) {
                break;
            }
            if (gChildWaitSession->mCallback != NULL) {
                gChildWaitSession->mCallback(3);
            } else {
                gChildWaitSession->mUnk_1e2a0 = 1;
            }
            break;
        case 26:
        case 29:
            if (stateInfo[1] == 0) {
                break;
            }
            if (gChildWaitSession->mCallback != NULL) {
                gChildWaitSession->mCallback(4);
            } else {
                gChildWaitSession->mUnk_1e2a0 = 1;
            }
            break;
        case 12:
            if (stateInfo[1] == 0) {
                break;
            }
            if (gChildWaitSession->mCallback != NULL) {
                gChildWaitSession->mCallback(2);
            } else {
                gChildWaitSession->mUnk_1e2a0 = 1;
            }
            break;
        case 34:
            RequestTaskRemoval(0, task);
            FreeExpHeapBlockAndClearPointer(&gChildWaitSession);
            break;
    }
}
