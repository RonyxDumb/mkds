#include "Main/Race/race_hud_sub_screen_mode.h"
#include "Main/Kart/karts.h"
#include "Main/Race/race_setup_block.h"
#include "touch_panel_sampling.h"

u32 RaceHudSubScreenGetCurrentMode(void) {
    return (gRaceSetup->mMode);
}

u32 GetKartCourseHitAttributeBitOrGhost(int kartIndex) {
    int currentMode;
    u32 result;
    currentMode = RaceHudSubScreenGetCurrentMode();
    if ((currentMode == MODE_TIME_ATTACK) && (kartIndex != 0)) {
        return 1;
    }
    result = GetKartCourseHitAttributeBitWrapper(kartIndex);
    return result;
}
