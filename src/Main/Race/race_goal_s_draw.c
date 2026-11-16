#include "Main/Race/race_goal_s_draw.h"
#include "Main/Race/race_goal_s.h"

void DrawRaceGoalS(RaceHudOamBuffer *oamBuffer) {
    int state;
    state = GetRaceHudSubScreenState();
    if (state != RACE_HUD_SUB_SCREEN_GOAL_TEAMS) {
        DrawRaceGoalSKarts(oamBuffer);
        return;
    }
    DrawRaceGoalSTeams(oamBuffer);
}
