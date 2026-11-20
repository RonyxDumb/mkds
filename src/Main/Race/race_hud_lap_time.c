#include "Main/Race/race_hud_lap_time.h"
#include "Main/Race/race_hud_sub_screen_frames.h"
#include "Main/Kart/point_link_cursor.h"
#include "Main/Race/race_hud_sub_screen_course_id.h"
#include "model_material_set.h"
#include "Main/Race/race_setup_block.h"
#include "touch_panel_sampling.h"
#include "Main/Race/graphic_file_loaders_and_matrix2x2.h"
#include "Main/Race/race_hud_sub_screen_min_max.h"
#include "Main/Kart/kart_heading_item_effect.h"
#include "Main/Race/race_hud_sub_screen_projection.h"
#include "Main/Graphics/font_and_player_character.h"
#include "cpu_copy_fill.h"
#include "Main/Race/kart.h"
#include "Main/Race/race_hud_draw.h"

#pragma opt_arithtransformation off

// Absolute difference of two times (each as minutes, seconds, milliseconds) written to difference; the whole result
// becomes 99:59.999 when it is 100 minutes or more. Returns non-zero when first is not less than second.
s32 ComputeTimeDifference(MinuteSecondMillisecondTotal *first, MinuteSecondMillisecondTotal *second,
                          MinuteSecondMillisecondTime *difference) {
    s32 firstMs;
    s32 secondMs;
    s32 differenceMs;
    BOOL firstNotLess;
    s32 minutes;
    s32 seconds;
    s32 milliseconds;

    firstMs = (first->mMinutes * 60 + first->mSeconds) * 1000 + first->mMilliseconds;
    secondMs = (second->mMinutes * 60 + second->mSeconds) * 1000 + second->mMilliseconds;
    firstNotLess = firstMs >= secondMs;
    if (firstNotLess != FALSE) {
        differenceMs = firstMs - secondMs;
    } else {
        differenceMs = secondMs - firstMs;
    }
    minutes = differenceMs / 60000;
    seconds = (differenceMs - minutes * 60000) / 1000;
    milliseconds = differenceMs % 1000;
    if (minutes < 100) {
        difference->mMinute = minutes;
        difference->mSecond = seconds;
        difference->mMillisecond = milliseconds;
    } else {
        difference->mMinute = RACE_HUD_TIME_DIFFERENCE_MAX_MINUTE;
        difference->mSecond = RACE_HUD_TIME_DIFFERENCE_MAX_SECOND;
        difference->mMillisecond = RACE_HUD_TIME_DIFFERENCE_MAX_MILLISECOND;
    }
    return firstNotLess;
}

// Called when the local entry's kart starts a new lap: sets mShowLapTime in Grand Prix and Time Attack and, when
// mUseTimeDifference is set, fills the time difference sign and digits.
void StartRaceHudLapTimeDisplay(void) {
    MinuteSecondMillisecondTime referenceLap;
    MinuteSecondMillisecondTime kartLap;
    MinuteSecondMillisecondTime difference;
    MinuteSecondMillisecondTotal totals[2];
    TimeDigits digits;
    u8 totalsIndex;
    u8 lap;

    if (gRaceSetup->mMode == MODE_GRAND_PRIX || gRaceSetup->mMode == MODE_TIME_ATTACK) {
        gRaceHud->mShowLapTime = 1;
    }
    if (gRaceHud->mUseTimeDifference == 0) {
        return;
    }
    for (totalsIndex = 0; totalsIndex < 2; totalsIndex++) {
        totals[totalsIndex].mMinutes = 0;
        totals[totalsIndex].mSeconds = 0;
        totals[totalsIndex].mMilliseconds = 0;
    }
    for (lap = 1; lap <= GetFollowedKartLastEndedLap(); lap++) {
        if (gRaceSetup->mMode == MODE_TIME_ATTACK) {
            MI_CpuCopy8(&gRaceSetup->mGhostLapTimes[lap - 1], &referenceLap, 4);
        }
        totals[0].mMinutes += referenceLap.mMinute;
        totals[0].mSeconds += referenceLap.mSecond;
        totals[0].mMilliseconds += referenceLap.mMillisecond;
        GetKartLapTime(GetFollowedKartOrEntryIndex(), lap, &kartLap.mMinute, &kartLap.mSecond, &kartLap.mMillisecond);
        totals[1].mMinutes += kartLap.mMinute;
        totals[1].mSeconds += kartLap.mSecond;
        totals[1].mMilliseconds += kartLap.mMillisecond;
    }
    gRaceHud->mTimeDifferenceSign = ComputeTimeDifference(&totals[1], &totals[0], &difference);
    SplitTimeDigits(difference.mMinute, difference.mSecond, difference.mMillisecond, &digits);
    gRaceHud->mTimeDifferenceDigits = digits;
}
