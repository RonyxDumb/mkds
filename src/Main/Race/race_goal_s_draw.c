#include "Main/Race/race_goal_s_draw.h"
#include "Main/Race/race_goal_s.h"

void StructRA_SomeFn_1(RaceHudOamBuffer *oamBuffer) {
    int state;
    state = GetRaceHudSubScreenState();
    if (state != RACE_HUD_SUB_SCREEN_GOAL_TEAMS) {
        StructRA_SomeFn_3(oamBuffer);
        return;
    }
    StructRA_SomeFn_2(oamBuffer);
}
