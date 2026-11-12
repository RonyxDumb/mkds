#include "Main/Race/race_goal_s_draw.h"
#include "Main/Race/race_goal_s.h"

void DrawRaceGoalS(RaceHudOamBuffer *oamBuffer) {
    int state;
    state = GetRaceHudSubScreenState();
    if (state != 5) {
        DrawRaceGoalSKarts(oamBuffer);
        return;
    }
    DrawRaceGoalSTeams(oamBuffer);
}
