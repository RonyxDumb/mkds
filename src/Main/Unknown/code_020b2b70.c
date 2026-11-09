#include "Main/Unknown/code_020b2b70.h"
#include "Main/Unknown/code_02055000.h"
#include "Main/Unknown/code_020a1000.h"
#include "Main/Unknown/code_020b19f8.h"
#include "Main/Unknown/code_020b24e4.h"
#include "Main/Unknown/code_020b2a4c.h"
#include "Main/Unknown/code_020b2b54.h"
#include "Main/Unknown/code_020b2c54.h"
#include "Main/Unknown/code_020b2ec0.h"
#include "Main/Unknown/code_020b33d8.h"
#include "Main/Unknown/code_020c3da0.h"
#include "Main/Unknown/code_020c5db0.h"
#include "Main/Unknown/code_020c5e30.h"
#include "Main/Unknown/code_020c7000.h"
#include "Main/Unknown/unk_0217a000.h"
#include "01/code_021956dc.h"

#pragma optimize_for_size on
s32 ChoisesSIsBackupCommandRunning(void) {
    if (ChoisesSIsBackupEnabled() != 0) {
        return gBackupAccess->mCommandRunning;
    }
    return 0;
}

s32 ChoisesSIsBackupBusy(void) {
    if (data_0217aa08->mBusy != 0) {
        return 1;
    }
    return ChoisesSIsBackupCommandRunning();
}

#pragma thumb on
u32 func_020b2bc8(void) {
    if (GetRaceDone() != 0 || (ChoisesSGetCurrentRaceKind() == 2 && GetRaceStartSequenceFrames() > 0xf0)) {
        return 1;
    }
    return 0;
}

u32 IsChoisesSOpenAllowedAfterRace(void) {
    if (IsRaceStartSequenceDone() != 0 && func_020b2bc8() != 0 && IsRaceGoalMReady() != 0 &&
        IsRaceGoalSRunning() == 0 && func_020c70bc() == 0 && func_020c70a0() == 0 && GetShowLapTime() == 0 &&
        (GetChoisesSOpenDuringRace() != 0 || func_02055b1c() == FALSE)) {
        return 1;
    }
    return 0;
}
#pragma thumb off
