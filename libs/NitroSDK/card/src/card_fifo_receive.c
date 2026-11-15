#include "card_fifo_receive.h"
#include "thread_scheduler.h"
#include "card_enable_and_lock.h"
#include "card_rom_backup_access.h"

// Tag 11 callback: when a reply arrives, clears the request bit of CARDiCommon.mFlag and wakes CARDiCommon.mCurTh.
void CARDi_OnFifoRecv(u32 tag, u32 data, u32 err) {
    CARDiCommon *common;
    u32 value;

    if (tag != 0xb) {
        return;
    }
    if (err == 0) {
        return;
    }
    common = (CARDiCommon *) &gAccessState;
    value = common->mFlag;
    value = value & ~BACKUP_ACCESS_FLAG_REQUEST_PENDING;
    common->mFlag = value;
    OS_WakeupThreadDirect(common->mCurTh);
}
