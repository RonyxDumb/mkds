#include "Main/Unknown/code_020b1d64.h"
#include "Main/Unknown/unk_0217b000.h"

void RequestRaceHudSubScreenState5(void) {
    r2d_sStatus->mSubScreenState = 5;
    r2d_sStatus->mSubScreenEnabled = TRUE;
    r2d_sStatus->mSubScreenState5LoadPending = TRUE;
}

void RequestRaceHudSubScreenState6(void) {
    r2d_sStatus->mSubScreenState = 6;
    r2d_sStatus->mSubScreenEnabled = TRUE;
    r2d_sStatus->mSubScreenState6LoadPending = TRUE;
}
