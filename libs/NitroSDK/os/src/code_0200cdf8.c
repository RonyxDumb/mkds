#include "code_0200cdf8.h"
#include "code_0200ce60.h"
#include "code_0200cdc8.h"

s32 OS_LockCard(u16 lockID) {
    return OS_LockByWord(lockID, HW_CARD_LOCK_BUF, OSi_AllocateCardBus);
}

s32 OS_UnlockCard(u16 lockID) {
    return OS_UnlockByWord(lockID, HW_CARD_LOCK_BUF, OSi_FreeCardBus);
}
