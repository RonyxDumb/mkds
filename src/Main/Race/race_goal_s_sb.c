#include "Main/Race/race_goal_s_sb.h"
#include "Main/Race/race_hud_keyboard_map_object_work.h"

PaletteAndChars *GetRaceGoalSBPaletteAndChars(u32 index) {
    return &gRaceGoalS->mRaceGoalSB + index;
}

Nscr *GetRaceGoalSNscr(u32 index) {
    return (gRaceGoalS->mRaceGoalSNscrs[index]);
}

s32 GetRaceGoalSOffsetX(void) {
    return gRaceGoalS->mOffsetX;
}
