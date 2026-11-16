#include "Main/Unknown/code_020b1dbc.h"
#include "Main/Unknown/unk_0217b000.h"

// No NULL check: only valid while r2d_sStatus exists (race code only).
s32 r2d_20B1DD0(void) {
    u32 value0;
    value0 = r2d_sStatus->mUpdateFrames;
    return value0;
}

// No NULL check: only valid while r2d_sStatus exists (race code only).
s32 r2d_getMapMode(void) {
    u32 value0;
    value0 = r2d_sStatus->mSubScreenState;
    return value0;
}
