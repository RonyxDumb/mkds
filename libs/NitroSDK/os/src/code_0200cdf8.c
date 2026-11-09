#include "code_0200cdf8.h"
#include "code_0200ce60.h"
#include "code_0200cdc8.h"
#include "code_0200fc8c.h"

s32 OS_LockCard(u16 lockID) {
    return OS_LockByWord(lockID, &SYSTEM_WORK->mLockCard, OSi_AllocateCardBus);
}

s32 OS_UnlockCard(u16 lockID) {
    return OS_UnlockByWord(lockID, &SYSTEM_WORK->mLockCard, OSi_FreeCardBus);
}
