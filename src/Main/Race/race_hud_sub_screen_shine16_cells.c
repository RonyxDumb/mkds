#include "Main/Race/race_hud_sub_screen_shine16_cells.h"
#include "Main/Race/race_hud_sub_screen_cells.h"
#include "Main/Race/race_hud_sub_screen_frames.h"
#include "Main/Kart/point_link_cursor.h"
#include "Main/Race/race_hud_sub_screen_course_id.h"
#include "model_material_set.h"
#include "touch_panel_sampling.h"
#include "Main/Race/graphic_file_loaders_and_matrix2x2.h"
#include "Main/Race/race_hud_sub_screen_min_max.h"
#include "Main/Kart/kart_heading_item_effect.h"
#include "Main/Race/race_hud_sub_screen_projection.h"
#include "Main/Race/race_ncer_entry_getters.h"
#include "sprite_animation_control.h"
#include "Main/MapObjects/map_object_kind_update_list.h"
#include "Main/Race/race_hud_sub_screen_item_cells.h"

RaceHudSubScreenCells *gRaceHudSubScreenShine16Cells;

void UpdateRaceHudSubScreenShine16Cells(void) {
    s32 objectIndex;
    s32 cellCount;
    u32 scale;

    cellCount = 0;
    scale = GetRaceHudSubScreenScale();
    for (objectIndex = 0; objectIndex < gRaceHudSubScreenShine16Cells->mObjectCount; objectIndex++) {
        MapObject *mapObject;

        mapObject = gRaceHudSubScreenShine16Cells->mObjects[objectIndex];
        if (!(mapObject->mFlags & 1)) {
            if (ComputeRaceHudSubScreenPosition(
                    &mapObject->mPos, &gRaceHudSubScreenShine16Cells->mCells[cellCount].mDrawPos, scale, 1, 1)) {
                gRaceHudSubScreenShine16Cells->mCells[cellCount].mCell = GetRaceSNcerEntry(0xb6);
                gRaceHudSubScreenShine16Cells->mCells[cellCount].mPriority =
                    (mapObject->mFlags & MAP_OBJECT_FLAG_HUD_XLU) ? RACE_HUD_PRIORITY_2 : RACE_HUD_PRIORITY_1;
                gRaceHudSubScreenShine16Cells->mCells[cellCount].mXlu = mapObject->mFlags & MAP_OBJECT_FLAG_HUD_XLU;
                cellCount++;
            }
        }
    }
    gRaceHudSubScreenShine16Cells->mCellCount = cellCount;
}

void DrawRaceHudSubScreenShine16Cells(RaceHudOamBuffer *oamBuffer) {
    DrawRaceHudSubScreenCells(oamBuffer, gRaceHudSubScreenShine16Cells, 0);
}

s32 CreateRaceHudSubScreenCrabCells(void) {
    return CreateRaceHudSubScreenCells(&gRaceHudSubScreenCrabCells, MAP_OBJECT_KIND_CRAB);
}
