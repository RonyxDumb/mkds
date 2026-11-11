#include "01/code_0218547c.h"
#include "00/code_02181f98.h"

#pragma thumb off

void SelectCupGridSetMenuEntryKind(u32 value) {
    gMenuShared->mMenuEntryKind = value;
}

void SelectCupGridSetRaceSetupRequested(u32 value) {
    gMenuShared->mRaceSetupRequested = value;
}

#pragma thumb on
