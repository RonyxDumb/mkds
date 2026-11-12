#include "03/Net/child_wait_session_object.h"
#include "03/Net/child_wait_session.h"
#include "03/code_021d1000.h"
#include "03/code_021d3000.h"

#include "03/System/exp_heap.h"
#include "03/System/tasks.h"
#include "code_0214cfe4.h"
#include "03/System/application.h"
#include "03/code_021c2530.h"
#include "03/Menu/menu_pair_loading.h"
#include "03/Graphics/text_canvas.h"
#include "03/unk_021d5000.h"
#include "03/unk_021da000.h"
#include "03/Menu/sub_screen_message.h"
#include "code_0200fc8c.h"
#include "03/Menu/main_menu.h"

ChildWaitParams gChildWaitParams = {"dwc:/move/child.srl", NULL, NULL, "dwc:/move/banner.char", "dwc:/move/banner.plt", 0x159, 0, {0, 0, 0}};
ChildWaitSession *gChildWaitSession;

void CreateChildWaitSession(u32 callback) {
    ChildWaitParams params;
    gChildWaitSession = AllocExpHeapBlock(0x1e2a4, 0x20);
    gChildWaitSession->mCallback = (void (*)(s32)) callback;
    gChildWaitSession->mEventPending = 0;
    gChildWaitSession->mStopRequested = 0;
    params = gChildWaitParams;
    params.mGameNamep = GetMessageEntry(gMessages, 0xf);
    params.mGameIntroductionp = GetMessageEntry(gMessages, 0x10);
    params.mHandshakeByte = GetLanguageIndex() + 0x31;
    InitChildWaitSession((ChildWaitSessionView *) gChildWaitSession, (ChildWaitParamsView *) &params);
    if (StartChildWaitSession() == 0) {
        OS_Terminate();
    }
    gChildWaitSession->mStepTask = AddTask(0, AdvanceChildWaitSession, NULL, 0x78);
}

void StartChildWaitStop(void) {
    AddTask(0, &AdvanceChildWaitStop, NULL, 0x78);
}

void AdvanceChildWaitStop(u32 task) {
    int result;
    result = StopChildWaitSession();
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
    functionAddress = (u32) &StartChildWaitDownload;
    result = StartChildWaitDownload();
    return result;
}

u8 *GetChildUserBuffer(void) {
    return gChildWaitSession->mChildUser;
}

static inline void MI_CpuCopy16(const void *source, void *destination, s32 size) {
    MIi_CpuCopy16(source, destination, size);
}

void AdvanceChildWaitSession(u32 task) {
    u8 stateInfo[2];
    ChildWaitSession *object;
    AdvanceChildWaitState();
    object = gChildWaitSession;
    if (object->mEventPending != 0 && object->mStopRequested == 0) {
        if (object->mCallback == NULL) {
            return;
        }
        object->mCallback(0);
        return;
    }
    GetChildWaitStateChange(&stateInfo[0], &stateInfo[1]);
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
            MI_CpuCopy16(GetChildWaitChildUser(), gChildWaitSession->mChildUser, 0x16);
            if (gChildWaitSession->mCallback != NULL) {
                gChildWaitSession->mCallback(0);
            } else {
                gChildWaitSession->mEventPending = 1;
            }
            break;
        case 13:
            if (stateInfo[1] == 0) {
                break;
            }
            if (gChildWaitSession->mCallback != NULL) {
                gChildWaitSession->mCallback(1);
            } else {
                gChildWaitSession->mEventPending = 1;
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
                gChildWaitSession->mEventPending = 1;
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
                gChildWaitSession->mEventPending = 1;
            }
            break;
        case 12:
            if (stateInfo[1] == 0) {
                break;
            }
            if (gChildWaitSession->mCallback != NULL) {
                gChildWaitSession->mCallback(2);
            } else {
                gChildWaitSession->mEventPending = 1;
            }
            break;
        case 34:
            RequestTaskRemoval(0, task);
            FreeExpHeapBlockAndClearPointer(&gChildWaitSession);
            break;
    }
}
