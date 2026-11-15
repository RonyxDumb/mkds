#include "Main/Race/race_hud_sub_screen_pakkun_spit_cells.h"
#include "Main/Race/race_hud_sub_screen_cells.h"

#include "Main/Race/race_hud_sub_screen_frames.h"
#include "Main/Kart/point_link_cursor.h"
#include "Main/Race/race_hud_sub_screen_course_id.h"
#include "code_02012b30.h"
#include "tp.h"
#include "Main/Race/followed_kart_or.h"
#include "Main/Race/race_hud_sub_screen_min_max.h"
#include "Main/Kart/kart_heading_item_effect.h"
#include "Main/Race/race_hud_sub_screen_projection.h"
#include "Main/Race/race_ncer_entry_getters.h"
#include "g2d_Animation.h"

RaceHudSubScreenCells *gRaceHudSubScreenPakkunSpitCells;

void ClearRaceHudSubScreenPakkunSpitCells(void) {
    ClearRaceHudSubScreenCells(&gRaceHudSubScreenPakkunSpitCells);
}

void UpdateRaceHudSubScreenPakkunSpitCells(void) {
    s32 objectIndex;
    s32 cellCount;
    s32 raceHudSubScreenScale;
    MapObject *object;

    cellCount = 0;
    raceHudSubScreenScale = GetRaceHudSubScreenScale();
    for (objectIndex = 0; objectIndex < gRaceHudSubScreenPakkunSpitCells->mObjectCount; objectIndex++) {
        object = gRaceHudSubScreenPakkunSpitCells->mObjects[objectIndex];
        if ((object->mFlags & 1) == 0) {
            if (ComputeRaceHudSubScreenPosition(&object->mPos,
                                                &gRaceHudSubScreenPakkunSpitCells->mCells[cellCount].mDrawPos,
                                                raceHudSubScreenScale, 1, 1) != FALSE) {
                gRaceHudSubScreenPakkunSpitCells->mCells[cellCount].mCell = GetRaceSNcerEntry(0xa4);
                gRaceHudSubScreenPakkunSpitCells->mCells[cellCount].mPriority = RACE_HUD_PRIORITY_MIDDLE;
                cellCount++;
            }
        }
    }
    gRaceHudSubScreenPakkunSpitCells->mCellCount = cellCount;
}

void DrawRaceHudSubScreenPakkunSpitCells(RaceHudOamBuffer *oamBuffer) {
    DrawRaceHudSubScreenCells(oamBuffer, gRaceHudSubScreenPakkunSpitCells, 0);
}
