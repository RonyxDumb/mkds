#include "Main/Net/request_id.h"
#include "code_02007624.h"
#include "Main/Unknown/unk_0216f000.h"
#include "Main/Unknown/code_02007000.h"

#pragma thumb on

u32 IsChildAidValid(u32 aid) {
    if ((aid >= 1) && (aid <= 15)) {
        return 1;
    }
    return 0;
}

void MBi_CommCallParentError(u32 aid, u16 errcode) {
    u16 errorStatus[1];
    errorStatus[0] = errcode;
    MBi_CommChangeParentStateCallbackOnly(aid, 0xd, errorStatus);
}

u32 GetRequestId(void) {
    return gRequestId[0];
}

#pragma thumb off

#pragma thumb on

void AdvanceRequestId(void) {
    gRequestId[0]++;
    if (gRequestId[0] == 0) {
        gRequestId[0]++;
    }
}

void ResetRequestId(void) {
    gRequestId[0] = 0;
}

#pragma thumb off
