#include "01/Race/race_hud_boss_cells.h"

#include "01/Race/race_hud_king_cells.h"
#include "01/code_02188950.h"
#include "01/Menu/mission_run_screen_registers.h"
#include "01/MapObjects/map_object_nsbtp_frame.h"
#include "01/unk_021a9000.h"
#include "Main/MapObjects/map_object_kind_update_list.h"
#include "Main/Graphics/font_and_player_character.h"
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
#include "01/code_0218c000.h"
#include "01/code_0218b298.h"
#include "01/code_0218f900.h"
#include "01/unk_021a6000.h"
#include "Main/MapObjects/map_object_model_frame.h"
#include "Main/System/file_in_loaded.h"
#include "Main/Race/data_020b85f0.h"
#include "Main/Race/race_ncer_tables.h"
#include "00/Menu/wi_fi_vs_setting.h"
#include "code_0200eddc.h"

RaceHudSubScreenCells *gRaceHudSubScreenIwanteCells;

#pragma thumb off

s32 CreateRaceHudSubScreenIwanteCells(void) {
    return CreateRaceHudSubScreenCells(&gRaceHudSubScreenIwanteCells, MAP_OBJECT_KIND_IWANTE);
}

void ClearRaceHudSubScreenIwanteCells(void) {
    ClearRaceHudSubScreenCells(&gRaceHudSubScreenIwanteCells);
}

void UpdateRaceHudSubScreenIwanteCells(void) {
    u32 var;
    s32 objectIndex;
    s32 cellCount = 0;
    u32 entryIndex;
    MapObject *object;
    Vec3 *position;

    var = GetRaceHudSubScreenScale();
    for (objectIndex = 0; objectIndex < gRaceHudSubScreenIwanteCells->mObjectCount; objectIndex++) {
        object = gRaceHudSubScreenIwanteCells->mObjects[objectIndex];
        if (!(object->mFlags & 1)) {
            position = &object->mPos;
            if (ComputeRaceHudSubScreenPosition(position, &gRaceHudSubScreenIwanteCells->mCells[cellCount].mDrawPos,
                                                var, 1, 1)) {
                if (IsIwanteWalkB((MissionRunMapObject *) object)) {
                    entryIndex = (object->mFlags & 0x400) ? 0xc8 : 0xc6;
                } else {
                    entryIndex = (object->mFlags & 0x400) ? 0xc7 : 0xc5;
                }
                gRaceHudSubScreenIwanteCells->mCells[cellCount].mCell = GetRaceSNcerEntry(entryIndex);
                gRaceHudSubScreenIwanteCells->mCells[cellCount].mPriority =
                    IsPositionOutsideBox(position) ? RACE_HUD_PRIORITY_OUTSIDE_BOX : RACE_HUD_PRIORITY_INSIDE_BOX;
                gRaceHudSubScreenIwanteCells->mCells[cellCount].mXlu = object->mFlags & 0x20;
                gRaceHudSubScreenIwanteCells->mCells[cellCount].mAngle = object->mAngle;
                cellCount++;
            }
        }
    }
    gRaceHudSubScreenIwanteCells->mCellCount = cellCount;
}

void DrawRaceHudSubScreenIwanteCells(RaceHudOamBuffer *oamBuffer) {
    DrawRaceHudSubScreenCells(oamBuffer, gRaceHudSubScreenIwanteCells, 0);
}

s32 CreateRaceHudSubScreenKurikingCells(void) {
    return CreateRaceHudSubScreenCells(&gRaceHudSubScreenKurikingCells, MAP_OBJECT_KIND_KURIKING);
}

void ClearRaceHudSubScreenKurikingCells(void) {
    ClearRaceHudSubScreenCells(&gRaceHudSubScreenKurikingCells);
}

// Also copies one row of the race_transfer_map_mr_s_o palette into the race palette for each object.
void UpdateRaceHudSubScreenKurikingCells(void) {
    u32 var;
    s32 objectIndex;
    s32 cellCount = 0;
    s32 row;
    s32 colorIndex;
    MapObject *object;
    u16 *racePalette;
    Nclr *nclr;
    Vec3 *position;

    var = GetRaceHudSubScreenScale();
    for (objectIndex = 0; objectIndex < gRaceHudSubScreenKurikingCells->mObjectCount; objectIndex++) {
        object = gRaceHudSubScreenKurikingCells->mObjects[objectIndex];
        if (!(object->mFlags & 1)) {
            position = &object->mPos;
            if (ComputeRaceHudSubScreenPosition(position, &gRaceHudSubScreenKurikingCells->mCells[cellCount].mDrawPos,
                                                var, 1, 1)) {
                row = GetAbsoluteCounterWrapper((MissionRunMapObject *) object);
                racePalette = GetRaceNclrNcgr(RACE_NCER_PAIR_RACE_S)->mNclr->mData;
                nclr = NULL;
                LocateNclr((&nclr), (FindSceneFileWrapper("race_transfer_map_mr_s_o.NCLR")));
                for (colorIndex = 0; colorIndex < 16; colorIndex++) {
                    racePalette[0x50 + colorIndex] = nclr->mData[(row + 2) * 16 + colorIndex];
                }
                DC_FlushRange(GetRaceNclrNcgr(RACE_NCER_PAIR_RACE_S)->mNclr->mData,
                              GetRaceNclrNcgr(RACE_NCER_PAIR_RACE_S)->mNclr->mDataSize);
                gRaceHudSubScreenKurikingCells->mCells[cellCount].mCell = GetRaceSNcerEntry(0xc5);
                gRaceHudSubScreenKurikingCells->mCells[cellCount].mPriority =
                    IsPositionOutsideBox(position) ? RACE_HUD_PRIORITY_OUTSIDE_BOX : RACE_HUD_PRIORITY_INSIDE_BOX;
                gRaceHudSubScreenKurikingCells->mCells[cellCount].mXlu = object->mFlags & 0x20;
                gRaceHudSubScreenKurikingCells->mCells[cellCount].mAngle = object->mAngle;
                cellCount++;
            }
        }
    }
    gRaceHudSubScreenKurikingCells->mCellCount = cellCount;
}

#pragma thumb on

RaceHudSubScreenCells *gRaceHudSubScreenHanachanCells;
RaceHudSubScreenCells *gRaceHudSubScreenMissionGateCells;
RaceHudSubScreenCells *gRaceHudSubScreenStopSignCells;
RaceHudSubScreenCells *gRaceHudSubScreenBossDonketuCells;
RaceHudSubScreenCells *gRaceHudSubScreenBombKingCells;
RaceHudSubScreenCells *gRaceHudSubScreenKurikingCells;

#pragma thumb off

void DrawRaceHudSubScreenKurikingCells(RaceHudOamBuffer *oamBuffer) {
    DrawRaceHudSubScreenCells(oamBuffer, gRaceHudSubScreenKurikingCells, 0);
}

s32 CreateRaceHudSubScreenBombKingCells(void) {
    return CreateRaceHudSubScreenCells(&gRaceHudSubScreenBombKingCells, MAP_OBJECT_KIND_BOMB_KING);
}

void ClearRaceHudSubScreenBombKingCells(void) {
    ClearRaceHudSubScreenCells(&gRaceHudSubScreenBombKingCells);
}

void UpdateRaceHudSubScreenBombKingCells(void) {
    s32 objectIndex;
    s32 cellCount;
    u32 unk;
    MapObject *object;
    Vec3 *position;

    cellCount = 0;
    unk = GetRaceHudSubScreenScale();
    for (objectIndex = 0; objectIndex < gRaceHudSubScreenBombKingCells->mObjectCount; objectIndex++) {
        object = gRaceHudSubScreenBombKingCells->mObjects[objectIndex];
        if (object->mFlags & 1) {
            continue;
        }
        position = &object->mPos;
        if (ComputeRaceHudSubScreenPosition(position, &gRaceHudSubScreenBombKingCells->mCells[cellCount].mDrawPos, unk,
                                            1, 1)) {
            gRaceHudSubScreenBombKingCells->mCells[cellCount].mCell = GetRaceSNcerEntry(0xc5);
            gRaceHudSubScreenBombKingCells->mCells[cellCount].mPriority =
                IsPositionOutsideBox(position) ? RACE_HUD_PRIORITY_OUTSIDE_BOX : RACE_HUD_PRIORITY_INSIDE_BOX;
            gRaceHudSubScreenBombKingCells->mCells[cellCount].mXlu = object->mFlags & 0x20;
            gRaceHudSubScreenBombKingCells->mCells[cellCount].mAngle = object->mAngle;
            cellCount++;
        }
    }
    gRaceHudSubScreenBombKingCells->mCellCount = cellCount;
}

void DrawRaceHudSubScreenBombKingCells(RaceHudOamBuffer *oamBuffer) {
    DrawRaceHudSubScreenCells(oamBuffer, gRaceHudSubScreenBombKingCells, 0);
}

s32 CreateRaceHudSubScreenBossDonketuCells(void) {
    return CreateRaceHudSubScreenCells(&gRaceHudSubScreenBossDonketuCells, MAP_OBJECT_KIND_BOSS_DONKETU);
}

void ClearRaceHudSubScreenBossDonketuCells(void) {
    ClearRaceHudSubScreenCells(&gRaceHudSubScreenBossDonketuCells);
}

void UpdateRaceHudSubScreenBossDonketuCells(void) {
    s32 objectIndex;
    s32 cellCount;
    u32 unk;
    MapObject *object;
    Vec3 *position;

    cellCount = 0;
    unk = GetRaceHudSubScreenScale();
    for (objectIndex = 0; objectIndex < gRaceHudSubScreenBossDonketuCells->mObjectCount; objectIndex++) {
        object = gRaceHudSubScreenBossDonketuCells->mObjects[objectIndex];
        if (object->mFlags & 1) {
            continue;
        }
        position = &object->mPos;
        if (ComputeRaceHudSubScreenPosition(position, &gRaceHudSubScreenBossDonketuCells->mCells[cellCount].mDrawPos,
                                            unk, 1, 1)) {
            gRaceHudSubScreenBossDonketuCells->mCells[cellCount].mCell = GetRaceSNcerEntry(0xc5);
            gRaceHudSubScreenBossDonketuCells->mCells[cellCount].mPriority =
                IsPositionOutsideBox(position) ? RACE_HUD_PRIORITY_OUTSIDE_BOX : RACE_HUD_PRIORITY_INSIDE_BOX;
            gRaceHudSubScreenBossDonketuCells->mCells[cellCount].mXlu = object->mFlags & 0x20;
            gRaceHudSubScreenBossDonketuCells->mCells[cellCount].mAngle = object->mAngle;
            cellCount++;
        }
    }
    gRaceHudSubScreenBossDonketuCells->mCellCount = cellCount;
}

void DrawRaceHudSubScreenBossDonketuCells(RaceHudOamBuffer *oamBuffer) {
    DrawRaceHudSubScreenCells(oamBuffer, gRaceHudSubScreenBossDonketuCells, 0);
}

s32 CreateRaceHudSubScreenStopSignCells(void) {
    return CreateRaceHudSubScreenCells(&gRaceHudSubScreenStopSignCells, MAP_OBJECT_KIND_STOP_SIGN);
}

void ClearRaceHudSubScreenStopSignCells(void) {
    ClearRaceHudSubScreenCells(&gRaceHudSubScreenStopSignCells);
}

void UpdateRaceHudSubScreenStopSignCells(void) {
    s32 objectIndex;
    s32 cellCount;
    u32 unk;
    MapObject *object;
    Vec3 *position;

    cellCount = 0;
    unk = GetRaceHudSubScreenScale();
    for (objectIndex = 0; objectIndex < gRaceHudSubScreenStopSignCells->mObjectCount; objectIndex++) {
        object = gRaceHudSubScreenStopSignCells->mObjects[objectIndex];
        position = &object->mPos;
        if (ComputeRaceHudSubScreenPosition(position, &gRaceHudSubScreenStopSignCells->mCells[cellCount].mDrawPos, unk,
                                            1, 1)) {
            gRaceHudSubScreenStopSignCells->mCells[cellCount].mCell = GetRaceSNcerEntry(0x5b);
            gRaceHudSubScreenStopSignCells->mCells[cellCount].mPriority =
                IsPositionOutsideBox(position) ? RACE_HUD_PRIORITY_OUTSIDE_BOX : RACE_HUD_PRIORITY_INSIDE_BOX;
            gRaceHudSubScreenStopSignCells->mCells[cellCount].mXlu = 0;
            gRaceHudSubScreenStopSignCells->mCells[cellCount].mAngle = object->mAngle;
            cellCount++;
        }
    }
    gRaceHudSubScreenStopSignCells->mCellCount = cellCount;
}

void DrawRaceHudSubScreenStopSignCells(RaceHudOamBuffer *oamBuffer) {
    DrawRaceHudSubScreenCells(oamBuffer, gRaceHudSubScreenStopSignCells, 1);
}

s32 CreateRaceHudSubScreenMissionGateCells(void) {
    return CreateRaceHudSubScreenCells(&gRaceHudSubScreenMissionGateCells, MAP_OBJECT_KIND_MISSION_GATE);
}

void ClearRaceHudSubScreenMissionGateCells(void) {
    ClearRaceHudSubScreenCells(&gRaceHudSubScreenMissionGateCells);
}

void UpdateRaceHudSubScreenMissionGateCells(void) {
    s32 objectIndex;
    s32 cellCount;
    u32 unk;
    MapObject *object;
    Vec3 *position;

    cellCount = 0;
    unk = GetRaceHudSubScreenScale();
    for (objectIndex = 0; objectIndex < gRaceHudSubScreenMissionGateCells->mObjectCount; objectIndex++) {
        object = gRaceHudSubScreenMissionGateCells->mObjects[objectIndex];
        position = &object->mPos;
        if (ComputeRaceHudSubScreenPosition(position, &gRaceHudSubScreenMissionGateCells->mCells[cellCount].mDrawPos,
                                            unk, 1, 1)) {
            gRaceHudSubScreenMissionGateCells->mCells[cellCount].mCell =
                GetRaceSNcerEntry(IsMissionGateFrameAdvanced((MissionGateObject *) object) ? 0x5a : 0x59);
            gRaceHudSubScreenMissionGateCells->mCells[cellCount].mPriority =
                IsPositionOutsideBox(position) ? RACE_HUD_PRIORITY_OUTSIDE_BOX : RACE_HUD_PRIORITY_INSIDE_BOX;
            gRaceHudSubScreenMissionGateCells->mCells[cellCount].mXlu = 0;
            gRaceHudSubScreenMissionGateCells->mCells[cellCount].mAngle = object->mAngle;
            cellCount++;
        }
    }
    gRaceHudSubScreenMissionGateCells->mCellCount = cellCount;
}

void DrawRaceHudSubScreenMissionGateCells(RaceHudOamBuffer *oamBuffer) {
    DrawRaceHudSubScreenCells(oamBuffer, gRaceHudSubScreenMissionGateCells, 1);
}

s32 CreateRaceHudSubScreenHanachanCells(void) {
    return CreateRaceHudSubScreenCells(&gRaceHudSubScreenHanachanCells, MAP_OBJECT_KIND_HANACHAN);
}

void ClearRaceHudSubScreenHanachanCells(void) {
    ClearRaceHudSubScreenCells(&gRaceHudSubScreenHanachanCells);
}

void UpdateRaceHudSubScreenHanachanCells(void) {
    s32 objectIndex;
    s32 cellCount;
    u32 unk;
    MapObject *object;
    Vec3 *position;

    cellCount = 0;
    unk = GetRaceHudSubScreenScale();
    for (objectIndex = 0; objectIndex < gRaceHudSubScreenHanachanCells->mObjectCount; objectIndex++) {
        object = gRaceHudSubScreenHanachanCells->mObjects[objectIndex];
        if (object->mFlags & 1) {
            continue;
        }
        position = &object->mPos;
        if (ComputeRaceHudSubScreenPosition(position, &gRaceHudSubScreenHanachanCells->mCells[cellCount].mDrawPos, unk,
                                            1, 1)) {
            gRaceHudSubScreenHanachanCells->mCells[cellCount].mCell =
                GetRaceSNcerEntry(GetMapObjectNsbtpFrameIndex((MissionRunMapObject *) object) >= 2 ? 0xc6 : 0xc5);
            gRaceHudSubScreenHanachanCells->mCells[cellCount].mPriority =
                IsPositionOutsideBox(position) ? RACE_HUD_PRIORITY_OUTSIDE_BOX : RACE_HUD_PRIORITY_INSIDE_BOX;
            gRaceHudSubScreenHanachanCells->mCells[cellCount].mXlu = object->mFlags & 0x20;
            gRaceHudSubScreenHanachanCells->mCells[cellCount].mAngle = object->mAngle;
            cellCount++;
        }
    }
    gRaceHudSubScreenHanachanCells->mCellCount = cellCount;
}

void DrawRaceHudSubScreenHanachanCells(RaceHudOamBuffer *oamBuffer) {
    DrawRaceHudSubScreenCells(oamBuffer, gRaceHudSubScreenHanachanCells, 0);
}

#pragma thumb on
