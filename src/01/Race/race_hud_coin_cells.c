#include "01/Race/race_hud_coin_cells.h"

#include "01/Race/mission_run_state.h"
#include "01/code_02188950.h"
#include "01/Race/race_hud_king_cells.h"
#include "01/unk_021a9000.h"
#include "01/code_02181000.h"
#include "03/Net/essid_packet_steps.h"
#include "Main/System/heap_call.h"
#include "Main/Graphics/font_and_player_character.h"
#include "Main/Race/code_020b1dbc.h"
#include "Main/Kart/point_link_cursor.h"
#include "Main/Race/race_hud_sub_screen_course_id.h"
#include "code_02012b30.h"
#include "Main/Race/data_021759c0.h"
#include "tp.h"
#include "Main/Race/followed_kart_or.h"
#include "Main/Race/race_hud_sub_screen_min_max.h"
#include "Main/Kart/code_0207a880.h"
#include "Main/Race/race_hud_sub_screen_projection.h"
#include "Main/Race/data_020b837c.h"
#include "g2d_Animation.h"
#include "Main/Race/race_hud_sub_screen_cells.h"

RaceHudSubScreenCells *gRaceHudSubScreenCoinCells;

s32 GetMissionRunMapObjectAlphaLimit(void) {
    MissionRunMapObject *mapObject;

    if (gRaceSetup->mMode == MODE_MISSION_RUN) {
        mapObject = GetMissionRunMapObject(gRaceSetup->mMode == MODE_MISSION_RUN ? MissionRunGetCurrentKartCount() : 0);
    } else {
        mapObject = NULL;
    }
    return mapObject->mAlphaLimit;
}

#pragma thumb off

s32 CreateRaceHudSubScreenCoinCells(void) {
    return CreateRaceHudSubScreenCells(&gRaceHudSubScreenCoinCells, 0x68);
}

void ClearRaceHudSubScreenCoinCells(void) {
    ClearRaceHudSubScreenCells(&gRaceHudSubScreenCoinCells);
}

void UpdateRaceHudSubScreenCoinCells(void) {
    s32 objectIndex;
    s32 cellCount;
    MapObject *object;
    Vec3 *position;
    u32 raceHudSubScreenScale;

    cellCount = 0;
    raceHudSubScreenScale = GetRaceHudSubScreenScale();
    for (objectIndex = 0; objectIndex < gRaceHudSubScreenCoinCells->mObjectCount; objectIndex++) {
        object = gRaceHudSubScreenCoinCells->mObjects[objectIndex];
        if ((object->mFlags & 1) == 0) {
            position = &object->mPos;
            if (ComputeRaceHudSubScreenPosition(position, &gRaceHudSubScreenCoinCells->mCells[cellCount].mDrawPos,
                                                raceHudSubScreenScale, 1, 1)) {
                gRaceHudSubScreenCoinCells->mCells[cellCount].mCell = GetRaceSNcerEntry(0x58);
                gRaceHudSubScreenCoinCells->mCells[cellCount].mPriority =
                    IsPositionOutsideBox(position) != 0 ? RACE_HUD_PRIORITY_OUTSIDE_BOX : RACE_HUD_PRIORITY_INSIDE_BOX;
                cellCount++;
            }
        }
    }
    gRaceHudSubScreenCoinCells->mCellCount = cellCount;
}

void DrawRaceHudSubScreenCoinCells(void *oamBuffer) {
    DrawRaceHudSubScreenCells(oamBuffer, gRaceHudSubScreenCoinCells, 0);
}

#pragma thumb on
