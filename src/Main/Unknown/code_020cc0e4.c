#include "Main/Unknown/code_020cc0e4.h"

#include "Main/Unknown/code_020cc134.h"
#include "00/code_02181f98.h"
#include "registers.h"

u32 MenuWriteMainWinEnableBits(u32 bits) {
    u32 value0 = bits;
    u32 registerValue;
    registerValue = reg_GX_DISPCNT;
    registerValue = (registerValue) & ~(0xe000u);
    value0 = (registerValue) | ((value0 << 13));
    reg_GX_DISPCNT = value0;
    return value0;
}

u32 MenuWriteSubWinEnableBits(u32 bits) {
    u32 value0 = bits;
    u32 registerValue;
    registerValue = reg_GXS_DB_DISPCNT;
    registerValue = (registerValue) & ~(0xe000u);
    value0 = (registerValue) | ((value0 << 13));
    reg_GXS_DB_DISPCNT = value0;
    return value0;
}

u32 GetMenuEntryKind(void) {
    return (data_0217b488->mMenuEntryKind);
}

void SetRaceSetupRequested(u32 requested) {
    data_0217b488->mRaceSetupRequested = requested;
}

u32 GetUnfilledNotEliminated(void) {
    return (data_0217b488->mUnfilledNotEliminated);
}

u32 GetLVselIndex6Requested(void) {
    return (data_0217b488->mLVselIndex6Requested);
}
