#include "Main/Unknown/code_020ceaf8.h"
#include "00/code_02181f98.h"

void BattleStageSetMenuEntryKind(u32 entryKind) {
    gMenuShared->mMenuEntryKind = entryKind;
}

void BattleStageSetRaceSetupRequested(u32 requested) {
    gMenuShared->mRaceSetupRequested = requested;
}
