#include "Main/Race/grand_prix_next_course.h"
#include "Main/Kart/kart_scale_surface_tables.h"
#include "Main/Race/race_setup_block.h"
#include "touch_panel_sampling.h"
#include "Main/Race/race_setup_input.h"

void PrepareForCourseIntro(void) {
    g_GlobalCO->mNextHeader.mCourseNumber = g_GlobalCO->mCourseNumber + 1;
    if (g_GlobalCO->mNextHeader.mCourseNumber <= COURSES_PER_CUP) {
        g_GlobalCO->mNextHeader.mCourseId =
            g_InternalCourseIdOrderedTable[g_GlobalCO->mNextHeader.mCupIndex][g_GlobalCO->mNextHeader.mCourseNumber - 1];
    }
    g_GlobalCO->mNextHeader.mRaceKind = RACE_KIND_START_GP;
}
