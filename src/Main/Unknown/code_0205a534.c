#include "Main/Unknown/code_0205a534.h"
#include "Main/Unknown/unk_0217a000.h"

void CopySlotResultToPending(SlotResultSyncState *syncState) {
    syncState->mPendingItemInfoIndex = (u32) (((u32) syncState->mItemInfoIndex));
    syncState->mState = SLOT_RESULT_SYNC_STATE_WAIT_FOR_END;
}
