#include "card_request.h"
#include "os_thread.h"
#include "card_common.h"
#include "code_021458c4.h"

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
    value = value & ~0x20;
    common->mFlag = value;
    OS_WakeupThreadDirect(common->mCurTh);
}
