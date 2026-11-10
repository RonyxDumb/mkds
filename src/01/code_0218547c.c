#include "01/code_0218547c.h"
#include "00/code_02181f98.h"

#pragma thumb off

void func_ov001_02185490(u32 value) {
    gMenuShared->mMenuEntryKind = value;
}

void func_ov001_0218547c(u32 value) {
    gMenuShared->mRaceSetupRequested = value;
}

#pragma thumb on
