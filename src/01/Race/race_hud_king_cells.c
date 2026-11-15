#include "01/Race/race_hud_king_cells.h"
#include "01/MapObjects/map_object_animation.h"
#include "01/code_02187000.h"
#include "Main/Race/code_020b1dbc.h"
#include "Main/Kart/point_link_cursor.h"
#include "Main/Race/race_hud_sub_screen_course_id.h"
#include "code_02012b30.h"
#include "tp.h"
#include "Main/Race/followed_kart_or.h"
#include "Main/Race/race_hud_sub_screen_min_max.h"
#include "Main/Kart/code_0207a880.h"
#include "Main/Race/race_hud_sub_screen_projection.h"
#include "Main/Race/data_020b837c.h"
#include "g2d_Animation.h"
#include "Main/Race/race_hud_sub_screen_cells.h"
#include "Main/Graphics/font_and_player_character.h"
#include "code_02147cd8.h"
#include "Main/MapObjects/map_object_kind_update_list.h"

RaceHudSubScreenCells *gRaceHudSubScreenKingIceDonketuCells;
RaceHudSubScreenCells *gRaceHudSubScreenKingTeresaCells;

#pragma thumb off

s32 CreateRaceHudSubScreenKingIceDonketuCells(void) {
    return CreateRaceHudSubScreenCells(&gRaceHudSubScreenKingIceDonketuCells, MAP_OBJECT_KIND_KING_ICE_DONKETU);
}

void ClearRaceHudSubScreenKingIceDonketuCells(void) {
    ClearRaceHudSubScreenCells(&gRaceHudSubScreenKingIceDonketuCells);
}

void UpdateRaceHudSubScreenKingIceDonketuCells(void) {
    s32 objectIndex;
    s32 cellCount = 0;
    u32 raceHudSubScreenScale = GetRaceHudSubScreenScale();
    MapObject *object;
    Vec3 *pos;

    for (objectIndex = 0; objectIndex < gRaceHudSubScreenKingIceDonketuCells->mObjectCount; objectIndex++) {
        object = gRaceHudSubScreenKingIceDonketuCells->mObjects[objectIndex];
        if (!(object->mFlags & 1)) {
            pos = &object->mPos;
            if (ComputeRaceHudSubScreenPosition(pos, &gRaceHudSubScreenKingIceDonketuCells->mCells[cellCount].mDrawPos,
                                                raceHudSubScreenScale, 1, 1) != FALSE) {
                gRaceHudSubScreenKingIceDonketuCells->mCells[cellCount].mCell = GetRaceSNcerEntry(0xc5);
                gRaceHudSubScreenKingIceDonketuCells->mCells[cellCount].mPriority =
                    IsPositionOutsideBox(pos) ? RACE_HUD_PRIORITY_OUTSIDE_BOX : RACE_HUD_PRIORITY_INSIDE_BOX;
                gRaceHudSubScreenKingIceDonketuCells->mCells[cellCount].mXlu = object->mFlags & 0x20;
                gRaceHudSubScreenKingIceDonketuCells->mCells[cellCount].mAngle = object->mAngle;
                cellCount++;
            }
        }
    }
    gRaceHudSubScreenKingIceDonketuCells->mCellCount = cellCount;
}

void DrawRaceHudSubScreenKingIceDonketuCells(RaceHudOamBuffer *oamBuffer) {
    DrawRaceHudSubScreenCells(oamBuffer, gRaceHudSubScreenKingIceDonketuCells, 0);
}

BOOL CreateRaceHudSubScreenKingTeresaCells(void) {
    return CreateRaceHudSubScreenCells(&gRaceHudSubScreenKingTeresaCells, 0x1fd);
}

void ClearRaceHudSubScreenKingTeresaCells(void) {
    ClearRaceHudSubScreenCells(&gRaceHudSubScreenKingTeresaCells);
}

void UpdateRaceHudSubScreenKingTeresaCells(void) {
    s32 objectIndex;
    s32 cellCount = 0;
    u32 raceHudSubScreenScale = GetRaceHudSubScreenScale();
    MapObject *object;
    Vec3 *pos;

    for (objectIndex = 0; objectIndex < gRaceHudSubScreenKingTeresaCells->mObjectCount; objectIndex++) {
        object = gRaceHudSubScreenKingTeresaCells->mObjects[objectIndex];
        if (!(object->mFlags & 1)) {
            pos = &object->mPos;
            if (ComputeRaceHudSubScreenPosition(pos, &gRaceHudSubScreenKingTeresaCells->mCells[cellCount].mDrawPos,
                                                raceHudSubScreenScale, 1, 1) != FALSE) {
                gRaceHudSubScreenKingTeresaCells->mCells[cellCount].mCell = GetRaceSNcerEntry(0xc5);
                gRaceHudSubScreenKingTeresaCells->mCells[cellCount].mPriority =
                    IsPositionOutsideBox(pos) ? RACE_HUD_PRIORITY_OUTSIDE_BOX : RACE_HUD_PRIORITY_INSIDE_BOX;
                gRaceHudSubScreenKingTeresaCells->mCells[cellCount].mXlu = object->mFlags & 0x20;
                gRaceHudSubScreenKingTeresaCells->mCells[cellCount].mAngle = object->mAngle;
                cellCount++;
            }
        }
    }
    gRaceHudSubScreenKingTeresaCells->mCellCount = cellCount;
}

void DrawRaceHudSubScreenKingTeresaCells(RaceHudOamBuffer *oamBuffer) {
    DrawRaceHudSubScreenCells(oamBuffer, gRaceHudSubScreenKingTeresaCells, 0);
}

#pragma thumb on

BOOL IsWithinXzDistanceOfPoint(MissionRunMapObject *mapObject, Vec3 *point, s32 radius) {
    Vec3 unusedOffset;
    s32 dx;
    s32 dz;
    float radiusAsFloat;
    float radiusAsFloatCopy;

    if (point != NULL) {
        VEC_Subtract(point, &mapObject->mUnk_000.mPos, &unusedOffset);
        dx = mapObject->mUnk_000.mPos.x - point->x;
        dz = mapObject->mUnk_000.mPos.z - point->z;
        if (radius > 0) {
            radiusAsFloat = 0.5f + TO_FIXED12(radius);
        } else {
            radiusAsFloat = TO_FIXED12(radius) - 0.5f;
        }
        if (radius > 0) {
            radiusAsFloatCopy = 0.5f + TO_FIXED12(radius);
        } else {
            radiusAsFloatCopy = TO_FIXED12(radius) - 0.5f;
        }
        if (SQUARE_SUM2(dx, dz) < (s64) (s32) radiusAsFloatCopy * (s32) radiusAsFloat) {
            return 1;
        }
        return 0;
    }
    return 0;
}

BOOL IsDirectionToPointWithinAngle(MissionRunMapObject *mapObject, s32 angle, Vec3 *point, s32 halfAngle) {
    s32 angleDifference;

    if (point != NULL) {
        angleDifference =
            (u16) (FX_Atan2Idx(point->x - mapObject->mUnk_000.mPos.x, point->z - mapObject->mUnk_000.mPos.z) - angle);
        if (angleDifference > 0x8000) {
            angleDifference -= 0x10000;
        }
        if (-halfAngle <= angleDifference && angleDifference <= halfAngle) {
            return 1;
        }
        return 0;
    }
    return 0;
}

void ClearAndRunCallback(MissionRunMapObject *mapObject, void (**callbackSlot)()) {
    void (*callback)() = *callbackSlot;

    *callbackSlot = NULL;
    if (callback != NULL) {
        callback(mapObject, callbackSlot, 0);
    }
}

void StopMapObjectState(MissionRunMapObject *mapObject) {
    StartMapObjectState(mapObject, 0, (s32(*)(MissionRunMapObject *))(0));
}
