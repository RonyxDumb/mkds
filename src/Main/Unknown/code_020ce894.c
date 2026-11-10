#include "Main/Unknown/code_020ce894.h"
#include "00/code_02181f98.h"

u32 VsSelectCupGetConnectionKind(void) {
    return (data_021759d0->mConnectionKind);
}

void VsSelectCupSetMenuEntryKind(u32 entryKind) {
    gMenuShared->mMenuEntryKind = entryKind;
}

void VsSelectCupSetRaceSetupRequested(u32 requested) {
    gMenuShared->mRaceSetupRequested = requested;
}
