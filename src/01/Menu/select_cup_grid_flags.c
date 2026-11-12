#include "01/Menu/select_cup_grid_flags.h"
#include "00/Menu/wi_fi_vs_setting.h"

#pragma thumb off

void SelectCupGridSetMenuEntryKind(u32 value) {
    gMenuShared->mMenuEntryKind = value;
}

void SelectCupGridSetRaceSetupRequested(u32 value) {
    gMenuShared->mRaceSetupRequested = value;
}

#pragma thumb on
