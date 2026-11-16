#include "Main/Unknown/code_020ca69c.h"

#include "Main/Unknown/code_020ca6a8.h"
#include "Main/Unknown/code_020ca670.h"
#include "Main/Unknown/unk_0217b000.h"
#include "Main/Unknown/code_020ca6b8.h"

#pragma thumb on
void echoi_finalize(void) {
    u32 pointerAddress;
    u32 zero;
    zero = 0u;
    pointerAddress = (u32) &echoi_sState;
    *(u32 *) ((pointerAddress) + 0u) = zero;
}
#pragma thumb off

#pragma thumb on
void echoi_requestPalCharUpdate(void) {
    echoi_sState->mGraphicsUploadRequested = TRUE;
}
#pragma thumb off

#pragma thumb on

u32 echoi_getActivatedOption(void) {
    return (echoi_sState->mResult);
}

#pragma thumb off
