#include "Main/Race/race_hud_kart_removed.h"
#include "Main/Race/race_hud_sub_screen_frames.h"
#include "Main/Race/race_hud_keyboard_map_object_work.h"
#include "Main/Race/race_hud_accessors.h"
#include "Main/Race/race_hud_draw.h"

s32 GetB350_T5(void) {
    u32 updateFrames;
    updateFrames = g_GlobalB350->mUpdateFrames;
    return updateFrames;
}

// No NULL check: only valid while g_GlobalB350 exists (race code only).
s32 GetRaceHudSubScreenState(void) {
    u32 subScreenState;
    subScreenState = g_GlobalB350->mSubScreenState;
    return subScreenState;
}

void RequestRaceHudSubScreenGoalTeams(void) {
    g_GlobalB350->mSubScreenState = RACE_HUD_SUB_SCREEN_GOAL_TEAMS;
    g_GlobalB350->mSubScreenEnabled = TRUE;
    g_GlobalB350->mSubScreenGoalTeamsLoadPending = TRUE;
}

void RequestRaceHudSubScreenNewRecord(void) {
    g_GlobalB350->mSubScreenState = RACE_HUD_SUB_SCREEN_NEW_RECORD;
    g_GlobalB350->mSubScreenEnabled = TRUE;
    g_GlobalB350->mSubScreenNewRecordLoadPending = TRUE;
}

s32 GetRaceHudSubScreenCourseScale(void) {
    return (g_GlobalB350->mSubScreenCourseScale);
}

RaceHudSubScreenBgAffine *GetRaceHudSubScreenBgAffine(void) {
    return g_GlobalB350->mSubScreenBgAffines;
}

BOOL IsRaceHudGoalMUploaded(void) {
    return (g_GlobalB350->mGoalMUploaded);
}

BOOL IsRaceHudGoalMEnabled(void) {
    return (g_GlobalB350->mGoalMEnabled);
}

u32 GetRaceHudKartRemoved(u32 kartIndex) {
    return (g_GlobalB350->mKartRemoved[kartIndex]);
}

void SetRaceHudKartRemoved(u32 kartIndex, u32 removed) {
    g_GlobalB350->mKartRemoved[kartIndex] = removed;
}
