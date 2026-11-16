#include "01/Race/race_hud_boss_cells.h"

#include "01/Race/race_hud_king_cells.h"
#include "01/MapObjects/mission_run_map_object.h"
#include "01/Menu/mission_run_screen_registers.h"
#include "01/MapObjects/map_object_nsbtp_frame.h"
#include "01/Menu/menu_screen_states_and_file_names.h"
#include "Main/MapObjects/map_object_kind_update_list.h"
#include "Main/Graphics/font_and_player_character.h"
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
#include "Main/Race/race_hud_sub_screen_cells.h"
#include "01/MapObjects/bomb_king_sound_and_jump_collision.h"
#include "01/MapObjects/king_teresa_show_and_kart_collision.h"
#include "01/MapObjects/mission_run_map_object_flags.h"
#include "Main/MapObjects/map_object_model_frame.h"
#include "Main/System/file_in_loaded.h"
#include "Main/Race/race_nclr_ncgr.h"
#include "Main/Race/race_ncer_tables.h"
#include "00/Menu/wi_fi_vs_setting.h"
#include "arena_cache_init.h"

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
                    entryIndex = (object->mFlags & MAP_OBJECT_FLAG_MIRRORED) ? 0xc8 : 0xc6;
                } else {
                    entryIndex = (object->mFlags & MAP_OBJECT_FLAG_MIRRORED) ? 0xc7 : 0xc5;
                }
                gRaceHudSubScreenIwanteCells->mCells[cellCount].mCell = GetB3C4_Cell_RaceS(entryIndex);
                gRaceHudSubScreenIwanteCells->mCells[cellCount].mPriority =
                    CheckVectorBounds_Clock_Airship(position) ? RACE_HUD_PRIORITY_MIDDLE : RACE_HUD_PRIORITY_BACK;
                gRaceHudSubScreenIwanteCells->mCells[cellCount].mXlu = object->mFlags & MAP_OBJECT_FLAG_HUD_XLU;
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
                racePalette = GetRacePaletteBlock(RACE_NCER_PAIR_RACE_S)->mNclr->mData;
                nclr = NULL;
                Gfx_ReadPaletteRelative((&nclr), (j_FindFileBuffer_K2D_LOC_R2D_R2L("race_transfer_map_mr_s_o.NCLR")));
                for (colorIndex = 0; colorIndex < 16; colorIndex++) {
                    racePalette[0x50 + colorIndex] = nclr->mData[(row + 2) * 16 + colorIndex];
                }
                Arm_FlushRange(GetRacePaletteBlock(RACE_NCER_PAIR_RACE_S)->mNclr->mData,
                              GetRacePaletteBlock(RACE_NCER_PAIR_RACE_S)->mNclr->mDataSize);
                gRaceHudSubScreenKurikingCells->mCells[cellCount].mCell = GetB3C4_Cell_RaceS(0xc5);
                gRaceHudSubScreenKurikingCells->mCells[cellCount].mPriority =
                    CheckVectorBounds_Clock_Airship(position) ? RACE_HUD_PRIORITY_MIDDLE : RACE_HUD_PRIORITY_BACK;
                gRaceHudSubScreenKurikingCells->mCells[cellCount].mXlu = object->mFlags & MAP_OBJECT_FLAG_HUD_XLU;
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
    u32 subScreenScale;
    MapObject *object;
    Vec3 *position;

    cellCount = 0;
    subScreenScale = GetRaceHudSubScreenScale();
    for (objectIndex = 0; objectIndex < gRaceHudSubScreenBombKingCells->mObjectCount; objectIndex++) {
        object = gRaceHudSubScreenBombKingCells->mObjects[objectIndex];
        if (object->mFlags & 1) {
            continue;
        }
        position = &object->mPos;
        if (ComputeRaceHudSubScreenPosition(position, &gRaceHudSubScreenBombKingCells->mCells[cellCount].mDrawPos,
                                            subScreenScale, 1, 1)) {
            gRaceHudSubScreenBombKingCells->mCells[cellCount].mCell = GetB3C4_Cell_RaceS(0xc5);
            gRaceHudSubScreenBombKingCells->mCells[cellCount].mPriority =
                CheckVectorBounds_Clock_Airship(position) ? RACE_HUD_PRIORITY_MIDDLE : RACE_HUD_PRIORITY_BACK;
            gRaceHudSubScreenBombKingCells->mCells[cellCount].mXlu = object->mFlags & MAP_OBJECT_FLAG_HUD_XLU;
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
    u32 subScreenScale;
    MapObject *object;
    Vec3 *position;

    cellCount = 0;
    subScreenScale = GetRaceHudSubScreenScale();
    for (objectIndex = 0; objectIndex < gRaceHudSubScreenBossDonketuCells->mObjectCount; objectIndex++) {
        object = gRaceHudSubScreenBossDonketuCells->mObjects[objectIndex];
        if (object->mFlags & 1) {
            continue;
        }
        position = &object->mPos;
        if (ComputeRaceHudSubScreenPosition(position, &gRaceHudSubScreenBossDonketuCells->mCells[cellCount].mDrawPos,
                                            subScreenScale, 1, 1)) {
            gRaceHudSubScreenBossDonketuCells->mCells[cellCount].mCell = GetB3C4_Cell_RaceS(0xc5);
            gRaceHudSubScreenBossDonketuCells->mCells[cellCount].mPriority =
                CheckVectorBounds_Clock_Airship(position) ? RACE_HUD_PRIORITY_MIDDLE : RACE_HUD_PRIORITY_BACK;
            gRaceHudSubScreenBossDonketuCells->mCells[cellCount].mXlu = object->mFlags & MAP_OBJECT_FLAG_HUD_XLU;
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
    u32 subScreenScale;
    MapObject *object;
    Vec3 *position;

    cellCount = 0;
    subScreenScale = GetRaceHudSubScreenScale();
    for (objectIndex = 0; objectIndex < gRaceHudSubScreenStopSignCells->mObjectCount; objectIndex++) {
        object = gRaceHudSubScreenStopSignCells->mObjects[objectIndex];
        position = &object->mPos;
        if (ComputeRaceHudSubScreenPosition(position, &gRaceHudSubScreenStopSignCells->mCells[cellCount].mDrawPos,
                                            subScreenScale, 1, 1)) {
            gRaceHudSubScreenStopSignCells->mCells[cellCount].mCell = GetB3C4_Cell_RaceS(0x5b);
            gRaceHudSubScreenStopSignCells->mCells[cellCount].mPriority =
                CheckVectorBounds_Clock_Airship(position) ? RACE_HUD_PRIORITY_MIDDLE : RACE_HUD_PRIORITY_BACK;
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
    u32 subScreenScale;
    MapObject *object;
    Vec3 *position;

    cellCount = 0;
    subScreenScale = GetRaceHudSubScreenScale();
    for (objectIndex = 0; objectIndex < gRaceHudSubScreenMissionGateCells->mObjectCount; objectIndex++) {
        object = gRaceHudSubScreenMissionGateCells->mObjects[objectIndex];
        position = &object->mPos;
        if (ComputeRaceHudSubScreenPosition(position, &gRaceHudSubScreenMissionGateCells->mCells[cellCount].mDrawPos,
                                            subScreenScale, 1, 1)) {
            gRaceHudSubScreenMissionGateCells->mCells[cellCount].mCell =
                GetB3C4_Cell_RaceS(IsMissionGateFrameAdvanced((MissionGateObject *) object) ? 0x5a : 0x59);
            gRaceHudSubScreenMissionGateCells->mCells[cellCount].mPriority =
                CheckVectorBounds_Clock_Airship(position) ? RACE_HUD_PRIORITY_MIDDLE : RACE_HUD_PRIORITY_BACK;
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
    u32 subScreenScale;
    MapObject *object;
    Vec3 *position;

    cellCount = 0;
    subScreenScale = GetRaceHudSubScreenScale();
    for (objectIndex = 0; objectIndex < gRaceHudSubScreenHanachanCells->mObjectCount; objectIndex++) {
        object = gRaceHudSubScreenHanachanCells->mObjects[objectIndex];
        if (object->mFlags & 1) {
            continue;
        }
        position = &object->mPos;
        if (ComputeRaceHudSubScreenPosition(position, &gRaceHudSubScreenHanachanCells->mCells[cellCount].mDrawPos,
                                            subScreenScale, 1, 1)) {
            gRaceHudSubScreenHanachanCells->mCells[cellCount].mCell =
                GetB3C4_Cell_RaceS(GetMapObjectNsbtpFrameIndex((MissionRunMapObject *) object) >= 2 ? 0xc6 : 0xc5);
            gRaceHudSubScreenHanachanCells->mCells[cellCount].mPriority =
                CheckVectorBounds_Clock_Airship(position) ? RACE_HUD_PRIORITY_MIDDLE : RACE_HUD_PRIORITY_BACK;
            gRaceHudSubScreenHanachanCells->mCells[cellCount].mXlu = object->mFlags & MAP_OBJECT_FLAG_HUD_XLU;
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
