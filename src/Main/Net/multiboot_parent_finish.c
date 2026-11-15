#include "Main/Net/multiboot_parent_finish.h"
#include "Main/Net/disconnect.h"
#include "Main/MapObjects/data_0217a000.h"

void FinishMultiBootParentSetup(void) {
    gConnectionWork->mState = CONNECTION_STATE_MULTIBOOT_PARENT_READY;
    gConnectionWork->mChildren.mNameSendIndex = 0;
    gConnectionWork->mStatusFlags &= ~CONNECTION_STATUS_CHILDREN_CHANGED;
}

void DisconnectRemovedChildren(void) {
    u8 removedChildMask;
    removedChildMask = gConnectionWork->mRemovedChildMask;
    if (removedChildMask == 0) {
        return;
    }
    if (QueueMPDataHalfwordAndWord(MP_MESSAGE_REMOVE_CHILDREN, gConnectionWork->mChildren.mChildMask,
                                   removedChildMask) == FALSE) {
        return;
    }
    DisconnectChildren(removedChildMask);
}
