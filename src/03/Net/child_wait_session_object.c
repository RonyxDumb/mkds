#include "03/Net/child_wait_session_object.h"
#include "03/Net/child_wait_session.h"

#include "03/System/exp_heap.h"
#include "03/System/tasks.h"
#include "cpu_copy_clear_16.h"
#include "03/System/application.h"
#include "03/Graphics/message_pool.h"
#include "03/Menu/menu_pair_loading.h"
#include "03/Graphics/text_canvas.h"
#include "03/Menu/wifi_menu_shared.h"
#include "03/Menu/sub_screen_message.h"
#include "reset_interrupt_enable.h"
#include "03/Menu/main_menu.h"

ChildWaitParams gChildWaitParams = {"dwc:/move/child.srl",  NULL,  NULL, "dwc:/move/banner.char",
                                    "dwc:/move/banner.plt", 0x159, 0,    {0, 0, 0}};
ChildWaitSession *gChildWaitSession;

void CreateChildWaitSession(void (*callback)(s32)) {
    ChildWaitParams params;
    gChildWaitSession = AllocExpHeapBlock(sizeof(ChildWaitSession), HEAP_ALIGN_CACHE_LINE);
    gChildWaitSession->mCallback = callback;
    gChildWaitSession->mEventPending = 0;
    gChildWaitSession->mStopRequested = 0;
    params = gChildWaitParams;
    params.mGameNamep = GetMessageEntry(gMessages, 0xf);
    params.mGameIntroductionp = GetMessageEntry(gMessages, 0x10);
    params.mHandshakeByte = GetLanguageIndex() + 0x31;
    InitChildWaitSession(&gChildWaitSession->mSession, &params);
    if (StartChildWaitSession() == 0) {
        OS_Terminate();
    }
    gChildWaitSession->mStepTask = AddTask(0, AdvanceChildWaitSession, NULL, 0x78);
}

void StartChildWaitStop(void) {
    AddTask(0, &AdvanceChildWaitStop, NULL, 0x78);
}

void AdvanceChildWaitStop(TaskEntry *task, void *arg) {
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
    gChildWaitSession->mCallback = callback;
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

void AdvanceChildWaitSession(TaskEntry *task, void *arg) {
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
        case CHILD_WAIT_STATE_IDLE:
        case CHILD_WAIT_STATE_WH_START:
        case CHILD_WAIT_STATE_MULTIBOOT_START:
        case CHILD_WAIT_STATE_MULTIBOOT_WAIT:
            break;
        case CHILD_WAIT_STATE_CHILD_JOINED:
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
        case CHILD_WAIT_STATE_CHILD_LEFT:
            if (stateInfo[1] == 0) {
                break;
            }
            if (gChildWaitSession->mCallback != NULL) {
                gChildWaitSession->mCallback(1);
            } else {
                gChildWaitSession->mEventPending = 1;
            }
            break;
        case CHILD_WAIT_STATE_END_DONE:
        case CHILD_WAIT_STATE_CLOSE_NO_RESTART_DONE:
            if (stateInfo[1] == 0) {
                break;
            }
            if (gChildWaitSession->mCallback != NULL) {
                gChildWaitSession->mCallback(3);
            } else {
                gChildWaitSession->mEventPending = 1;
            }
            break;
        case CHILD_WAIT_STATE_CLOSE_RESTARTABLE_DONE:
        case CHILD_WAIT_STATE_ABORT_DONE:
            if (stateInfo[1] == 0) {
                break;
            }
            if (gChildWaitSession->mCallback != NULL) {
                gChildWaitSession->mCallback(4);
            } else {
                gChildWaitSession->mEventPending = 1;
            }
            break;
        case CHILD_WAIT_STATE_FINAL_REPLY_DONE:
            if (stateInfo[1] == 0) {
                break;
            }
            if (gChildWaitSession->mCallback != NULL) {
                gChildWaitSession->mCallback(2);
            } else {
                gChildWaitSession->mEventPending = 1;
            }
            break;
        case CHILD_WAIT_STATE_ENDED:
            RequestTaskRemoval(0, task);
            FreeExpHeapBlockAndClearPointer(&gChildWaitSession);
            break;
    }
}
