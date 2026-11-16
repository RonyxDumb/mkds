#pragma once

#include "types.h"

typedef struct RaceProgressKart RaceProgressKart;

// How the race of the local entry ended (the endKind of FinishRaceProgressKartWithEndKind, RaceProgress.mEntryEndKind).
// Only the goal ends it as won; the others end its wait as a failure.
#define RACE_END_KIND_GOAL 0
#define RACE_END_KIND_TIME_UP 1
// Mission run end checks: the entry kart is not normal, has the scale table effect, or is falling to a respawn; or is
// in contact.
#define RACE_END_KIND_KART_STATE 2
#define RACE_END_KIND_CONTACT 3
// The mission failed: its settings were not met at the end, the shape map object counts failed, or the entry lost the
// balloon standings.
#define RACE_END_KIND_FAILED 4
// No code ends a race with this kind; it is only a case label of the end kind switch.
#define RACE_END_KIND_UNUSED 5
// Value of mEntryEndKind until the entry has ended; also the kind FinishKartInCourseMapMissionEndShape ends a kart
// with when the shape flag is 0.
#define RACE_END_KIND_NOT_ENDED 6

void FinishMissionRunKartAtGoal(u16 kartIndex);
// Ends the kart kartIndex with endKind (RACE_END_KIND_GOAL reached the goal, the others the other ends) unless it has
// already ended or its end wait (RACE_PROGRESS_KART_FLAG_GOAL_WAIT or FAILURE_WAIT) runs: stops the race clock, stores
// the time of mElapsedFrames in the kart's lap time slot 5, for the entry flagged RACE_PROGRESS_KART_FLAG_LOCAL_ENTRY
// records endKind and starts its end wait (GOAL_WAIT for RACE_END_KIND_GOAL, FAILURE_WAIT otherwise), calls
// FinishRaceProgressKart(kart, endKind == RACE_END_KIND_GOAL) and runs the end handler of the mode when
// IsRaceEndConditionMet holds.
void FinishRaceProgressKartWithEndKind(s32 kartIndex, s32 endKind);
// Ends the entry of raceProgressKart: finished non-zero ends the kart at the goal (status GOAL_REACHED), 0 ends it
// without the goal (ENDED_NO_GOAL); also finishes the key recording of its input slot, sets mFinishTimeMs, adds one to
// the finished count and, in Grand Prix and Mission Run, scores the local entry.
void FinishRaceProgressKart(RaceProgressKart *raceProgressKart, s32 finished);
void FinishRemainingMissionRunKarts(void);
void FinishRemainingWiFiRaceKarts(void);
// Finishes every kart that has neither ended nor been removed, without the goal, with its time from the race clock
// (scaled by its race progress in Grand Prix), and sets the finished count to the kart count; the end handler of the
// modes without their own.
void FinishRemainingRaceProgressKarts(void);
// Returns non-zero when the end condition of the current mode holds: Grand Prix when every entry of the kinds in
// PLAYER_KIND_MASK_HUMAN_GHOST_PEER has status 1 to 3; Time Attack when entry 0 has ended; Battle when every such entry
// is eliminated; Versus when finished plus removed karts reach the kart count minus one or every non-CPU kart has ended
// or been removed, or, with RULE_KIND_WIN_COUNT, when the leading kart has ended; WiFi (MODE_WIFI) only while more than
// one kart is not removed and then by finished plus removed karts against the kart count minus one (own kart not ended)
// or the kart count (own kart ended); mission run when RaceSetup.mMissionKind is MISSION_KIND_LAPS_FIRST_PLACE and a
// kart has finished; changes nothing.
s32 IsRaceEndConditionMet(void);

// RaceProgressKart.mFinishTimeMs of a kart that ends without the goal, except in a Wi-Fi race: 100 minutes.
#define RACE_FINISH_TIME_NONE_MS 0x5b8d80
