#include "Main/Race/race_goal_s_sb.h"
#include "Main/MapObjects/data_0217b000.h"

PaletteAndChars *GetRaceGoalSBPaletteAndChars(u32 index) {
    return (PaletteAndChars *) &gRaceGoalS->mRaceGoalSBNclr + index;
}

Nscr *GetRaceGoalSNscr(u32 index) {
    return (gRaceGoalS->mRaceGoalSNscrs[index]);
}

s32 GetRaceGoalSOffsetX(void) {
    return gRaceGoalS->mOffsetX;
}
