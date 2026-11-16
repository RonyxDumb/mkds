#include "Main/Net/multiboot_parent_finish.h"
#include "Main/Net/disconnect.h"
#include "Main/System/backup_net_camera_work.h"

void FinishMultiBootParentSetup(void) {
    g_GlobalZE->mState = CONNECTION_STATE_MULTIBOOT_PARENT_READY;
    g_GlobalZE->mChildren.mNameSendIndex = 0;
    g_GlobalZE->mStatusFlags &= ~CONNECTION_STATUS_CHILDREN_CHANGED;
}

void DisconnectRemovedChildren(void) {
    u8 removedChildMask;
    removedChildMask = g_GlobalZE->mRemovedChildMask;
    if (removedChildMask == 0) {
        return;
    }
    if (QueueMPDataHalfwordAndWord(MP_MESSAGE_REMOVE_CHILDREN, g_GlobalZE->mChildren.mChildMask,
                                   removedChildMask) == FALSE) {
        return;
    }
    DisconnectChildren(removedChildMask);
}
