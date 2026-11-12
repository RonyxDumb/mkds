#include "Main/Net/multiboot_parent_finish.h"
#include "Main/Net/disconnect.h"
#include "Main/Unknown/unk_0217a000.h"

void FinishMultiBootParentSetup(void) {
    gConnectionWork->mState = 2;
    gConnectionWork->mChildren.mNameSendIndex = 0;
    gConnectionWork->mStatusFlags &= ~CONNECTION_STATUS_CHILDREN_CHANGED;
}

void DisconnectRemovedChildren(void) {
    u8 removedChildMask;
    removedChildMask = gConnectionWork->mRemovedChildMask;
    if (removedChildMask == 0) {
        return;
    }
    if (QueueMPDataHalfwordAndWord(7, gConnectionWork->mChildren.mChildMask, removedChildMask) == FALSE) {
        return;
    }
    DisconnectChildren(removedChildMask);
}
