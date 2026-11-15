#include "Main/Race/race_hud_kart_removed.h"
#include "Main/Race/code_020b1dbc.h"
#include "Main/MapObjects/data_0217b000.h"
#include "Main/Race/code_020b1cf4.h"
#include "Main/Race/race_hud_draw.h"

s32 GetRaceHudUpdateFrames(void) {
    u32 updateFrames;
    updateFrames = gRaceHud->mUpdateFrames;
    return updateFrames;
}

// No NULL check: only valid while gRaceHud exists (race code only).
s32 GetRaceHudSubScreenState(void) {
    u32 subScreenState;
    subScreenState = gRaceHud->mSubScreenState;
    return subScreenState;
}

void RequestRaceHudSubScreenGoalTeams(void) {
    gRaceHud->mSubScreenState = RACE_HUD_SUB_SCREEN_GOAL_TEAMS;
    gRaceHud->mSubScreenEnabled = TRUE;
    gRaceHud->mSubScreenGoalTeamsLoadPending = TRUE;
}

void RequestRaceHudSubScreenNewRecord(void) {
    gRaceHud->mSubScreenState = RACE_HUD_SUB_SCREEN_NEW_RECORD;
    gRaceHud->mSubScreenEnabled = TRUE;
    gRaceHud->mSubScreenNewRecordLoadPending = TRUE;
}

s32 GetRaceHudSubScreenCourseScale(void) {
    return (gRaceHud->mSubScreenCourseScale);
}

RaceHudSubScreenBgAffine *GetRaceHudSubScreenBgAffine(void) {
    return gRaceHud->mSubScreenBgAffines;
}

BOOL IsRaceHudGoalMUploaded(void) {
    return (gRaceHud->mGoalMUploaded);
}

BOOL IsRaceHudGoalMEnabled(void) {
    return (gRaceHud->mGoalMEnabled);
}

u32 GetRaceHudKartRemoved(u32 kartIndex) {
    return (gRaceHud->mKartRemoved[kartIndex]);
}

void SetRaceHudKartRemoved(u32 kartIndex, u32 removed) {
    gRaceHud->mKartRemoved[kartIndex] = removed;
}
