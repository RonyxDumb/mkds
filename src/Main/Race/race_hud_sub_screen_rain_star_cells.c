#include "Main/Race/race_hud_sub_screen_rain_star_cells.h"

#include "Main/Race/race_hud_sub_screen_cells.h"
#include "Main/Graphics/font_and_player_character.h"
#include "Main/Race/race_hud_sub_screen_frames.h"
#include "Main/Kart/point_link_cursor.h"
#include "Main/Race/race_hud_sub_screen_course_id.h"
#include "model_material_set.h"
#include "Main/Race/race_setup_block.h"
#include "touch_panel_sampling.h"
#include "Main/Race/followed_kart_or.h"
#include "Main/Race/race_hud_sub_screen_min_max.h"
#include "Main/Kart/kart_heading_item_effect.h"
#include "Main/Race/race_hud_sub_screen_projection.h"
#include "Main/Race/race_ncer_entry_getters.h"
#include "sprite_animation_control.h"
#include "Main/Race/race_hud_keyboard_map_object_work.h"
#include "Main/Graphics/oam.h"
#include "cell_animation.h"
#include "Main/MapObjects/cover_poo_hole_cover_height.h"
#include "Main/MapObjects/mkd_ef_burner.h"
#include "Main/MapObjects/basabasa_hud_cell_kind.h"
#include "Main/MapObjects/basabasa.h" // Basabasa
#include "Main/MapObjects/group_item_box.h" // MkdEfBubbleObject
#include "Main/MapObjects/ob_pakkun_sf.h" // ObPakkunSf
#include "Main/MapObjects/map_object_kind_update_list.h"

RaceHudSubScreenCells *gRaceHudSubScreenRainStarCells;
RaceHudSubScreenCells *gRaceHudSubScreenPendulumCells;
RaceHudSubScreenCells *gRaceHudSubScreenNsKiller2Cells;
RaceHudSubScreenCells *gRaceHudSubScreenFlipperCells;
RaceHudSubScreenCells *gRaceHudSubScreenWoodbox1Cells;
RaceHudSubScreenCells *gRaceHudSubScreenRockCells;
RaceHudSubScreenCells *gRaceHudSubScreenSanboCells;
RaceHudSubScreenCells *gRaceHudSubScreenRock2Cells;
RaceHudSubScreenCells *gRaceHudSubScreenCoverPooHoleCells;
RaceHudSubScreenCells *gRaceHudSubScreenObPakkunSfCells;
RaceHudSubScreenCells *gRaceHudSubScreenKuriboCells;
RaceHudSubScreenCells *gRaceHudSubScreenIronBallCells;
RaceHudSubScreenCells *gRaceHudSubScreenSunFireballCells;
RaceHudSubScreenCells *gRaceHudSubScreenMkdEfBurnerCells;
RaceHudSubScreenCells *gRaceHudSubScreenBoundCells;
RaceHudSubScreenCells *gRaceHudSubScreenMkdEfBubbleCells;
RaceHudSubScreenCells *gRaceHudSubScreenBasabasaCells;

void ClearRaceHudSubScreenRainStarCells(void) {
    ClearRaceHudSubScreenCells(&gRaceHudSubScreenRainStarCells);
}

void UpdateRaceHudSubScreenRainStarCells(void) {
    s32 objectIndex;
    s32 cellCount;
    u32 scale;
    MapObject *object;
    Vec3 *position;

    cellCount = 0;
    scale = GetRaceHudSubScreenScale();
    for (objectIndex = 0; objectIndex < gRaceHudSubScreenRainStarCells->mObjectCount; objectIndex++) {
        object = gRaceHudSubScreenRainStarCells->mObjects[objectIndex];
        position = &object->mPos;
        if (ComputeRaceHudSubScreenPosition(position, &gRaceHudSubScreenRainStarCells->mCells[cellCount].mDrawPos,
                                            scale, 1, 1) != FALSE) {
            gRaceHudSubScreenRainStarCells->mCells[cellCount].mCell = GetRaceSNcerEntry(0xb3);
            gRaceHudSubScreenRainStarCells->mCells[cellCount].mPriority =
                IsPositionOutsideBox(position) != 0 ? RACE_HUD_PRIORITY_MIDDLE : RACE_HUD_PRIORITY_BACK;
            gRaceHudSubScreenRainStarCells->mCells[cellCount].mXlu = 0;
            gRaceHudSubScreenRainStarCells->mCells[cellCount].mAngle = object->mAngle;
            cellCount++;
        }
    }
    gRaceHudSubScreenRainStarCells->mCellCount = cellCount;
}

void DrawRaceHudSubScreenRainStarCells(RaceHudOamBuffer *oamBuffer) {
    DrawRaceHudSubScreenCells(oamBuffer, gRaceHudSubScreenRainStarCells, 1);
}

s32 CreateRaceHudSubScreenBasabasaCells(void) {
    return CreateRaceHudSubScreenCells(&gRaceHudSubScreenBasabasaCells, MAP_OBJECT_KIND_BASABASA);
}

void ClearRaceHudSubScreenBasabasaCells(void) {
    ClearRaceHudSubScreenCells(&gRaceHudSubScreenBasabasaCells);
}

void UpdateRaceHudSubScreenBasabasaCells(void) {
    s32 objectIndex;
    s32 cellCount;
    u32 scale;
    u32 cellKind;
    MapObject *object;
    Vec3 *position;
    void *cell;

    cellCount = 0;
    scale = GetRaceHudSubScreenScale();
    for (objectIndex = 0; objectIndex < gRaceHudSubScreenBasabasaCells->mObjectCount; objectIndex++) {
        object = gRaceHudSubScreenBasabasaCells->mObjects[objectIndex];
        if ((object->mFlags & 1) == 0) {
            cellKind = GetBasabasaRaceHudSubScreenCellKind((Basabasa *) object);
            if (cellKind != 0) {
                position = &object->mPos;
                if (ComputeRaceHudSubScreenPosition(
                        position, &gRaceHudSubScreenBasabasaCells->mCells[cellCount].mDrawPos, scale, 1, 1) != FALSE) {
                    if (cellKind == 2) {
                        cell = GetRaceSNcerEntry(0xb5);
                    } else {
                        cell = GetRaceSNcerEntry(0xb4);
                    }
                    gRaceHudSubScreenBasabasaCells->mCells[cellCount].mCell = cell;
                    gRaceHudSubScreenBasabasaCells->mCells[cellCount].mPriority =
                        IsPositionOutsideBox(position) != 0 ? RACE_HUD_PRIORITY_MIDDLE : RACE_HUD_PRIORITY_BACK;
                    cellCount++;
                }
            }
        }
    }
    gRaceHudSubScreenBasabasaCells->mCellCount = cellCount;
}

void DrawRaceHudSubScreenBasabasaCells(RaceHudOamBuffer *oamBuffer) {
    DrawRaceHudSubScreenCells(oamBuffer, gRaceHudSubScreenBasabasaCells, 0);
}

s32 CreateRaceHudSubScreenMkdEfBubbleCells(void) {
    return CreateRaceHudSubScreenCells(&gRaceHudSubScreenMkdEfBubbleCells, MAP_OBJECT_KIND_MKD_EF_BUBBLE);
}

void ClearRaceHudSubScreenMkdEfBubbleCells(void) {
    ClearRaceHudSubScreenCells(&gRaceHudSubScreenMkdEfBubbleCells);
}

void UpdateRaceHudSubScreenMkdEfBubbleCells(void) {
    s32 objectIndex;
    s32 cellCount;
    u32 scale;
    MapObject *object;
    s32 riseHeight;
    Vec3 *position;

    cellCount = 0;
    scale = GetRaceHudSubScreenScale();
    for (objectIndex = 0; objectIndex < gRaceHudSubScreenMkdEfBubbleCells->mObjectCount; objectIndex++) {
        if (IsRaceHudSubScreenPairNearCenter(&gRaceHudSubScreenMkdEfBubbleCells->mObjectPairs[objectIndex]) != FALSE) {
            object = gRaceHudSubScreenMkdEfBubbleCells->mObjects[objectIndex];
            riseHeight = object->mPos.y - ((MkdEfBubbleObject *) object)->mInitialY;
            if (riseHeight >= 0) {
                position = &object->mPos;
                if (ComputeRaceHudSubScreenPosition(position,
                                                    &gRaceHudSubScreenMkdEfBubbleCells->mCells[cellCount].mDrawPos,
                                                    scale, 0, 1) != FALSE) {
                    gRaceHudSubScreenMkdEfBubbleCells->mCells[cellCount].mDrawPos.mSecond -= riseHeight >> 14;
                    gRaceHudSubScreenMkdEfBubbleCells->mCells[cellCount].mCell = GetRaceSNcerEntry(0xb1);
                    gRaceHudSubScreenMkdEfBubbleCells->mCells[cellCount].mPriority =
                        IsPositionOutsideBox(position) != 0 ? RACE_HUD_PRIORITY_MIDDLE : RACE_HUD_PRIORITY_BACK;
                    cellCount++;
                }
            }
        }
    }
    gRaceHudSubScreenMkdEfBubbleCells->mCellCount = cellCount;
}

void DrawRaceHudSubScreenMkdEfBubbleCells(RaceHudOamBuffer *oamBuffer) {
    DrawRaceHudSubScreenCells(oamBuffer, gRaceHudSubScreenMkdEfBubbleCells, 0);
}

s32 CreateRaceHudSubScreenBoundCells(void) {
    return CreateRaceHudSubScreenCells(&gRaceHudSubScreenBoundCells, MAP_OBJECT_KIND_BOUND);
}

void ClearRaceHudSubScreenBoundCells(void) {
    ClearRaceHudSubScreenCells(&gRaceHudSubScreenBoundCells);
}

void UpdateRaceHudSubScreenBoundCells(void) {
    s32 objectIndex;
    s32 cellCount;
    u32 scale;
    MapObject *object;
    Vec3 *position;

    cellCount = 0;
    scale = GetRaceHudSubScreenScale();
    for (objectIndex = 0; objectIndex < gRaceHudSubScreenBoundCells->mObjectCount; objectIndex++) {
        object = gRaceHudSubScreenBoundCells->mObjects[objectIndex];
        position = &object->mPos;
        if (ComputeRaceHudSubScreenPosition(position, &gRaceHudSubScreenBoundCells->mCells[cellCount].mDrawPos, scale,
                                            1, 1) != FALSE) {
            gRaceHudSubScreenBoundCells->mCells[cellCount].mCell = GetRaceSNcerEntry(0x91);
            gRaceHudSubScreenBoundCells->mCells[cellCount].mPriority =
                IsPositionOutsideBox(position) != 0 ? RACE_HUD_PRIORITY_MIDDLE : RACE_HUD_PRIORITY_BACK;
            gRaceHudSubScreenBoundCells->mCells[cellCount].mAngle = object->mAngle;
            gRaceHudSubScreenBoundCells->mObjectPairs[cellCount].mFirst = object->mScale.x / 6;
            cellCount++;
        }
    }
    gRaceHudSubScreenBoundCells->mCellCount = cellCount;
}

void DrawRaceHudSubScreenBoundCells(RaceHudOamBuffer *oamBuffer) {
    DrawRaceHudSubScreenCellsScaled(oamBuffer, gRaceHudSubScreenBoundCells, 1);
}

s32 CreateRaceHudSubScreenMkdEfBurnerCells(void) {
    return CreateRaceHudSubScreenCells(&gRaceHudSubScreenMkdEfBurnerCells, MAP_OBJECT_KIND_MKD_EF_BURNER);
}

void ClearRaceHudSubScreenMkdEfBurnerCells(void) {
    ClearRaceHudSubScreenCells(&gRaceHudSubScreenMkdEfBurnerCells);
}

void UpdateRaceHudSubScreenMkdEfBurnerCells(void) {
    s32 objectIndex;
    s32 cellCount;
    s32 inFirstHalf;
    u32 scale;
    MapObject *object;
    Vec3 *position;

    cellCount = 0;
    scale = GetRaceHudSubScreenScale();
    gRaceHudSubScreenMkdEfBurnerCells->mObjectPairs[0].mSecond++;
    if (gRaceHudSubScreenMkdEfBurnerCells->mObjectPairs[0].mSecond < 0 ||
        gRaceHudSubScreenMkdEfBurnerCells->mObjectPairs[0].mSecond >= RACE_HUD_BURNER_CYCLE_FRAMES) {
        gRaceHudSubScreenMkdEfBurnerCells->mObjectPairs[0].mSecond = 0;
    }
    inFirstHalf = gRaceHudSubScreenMkdEfBurnerCells->mObjectPairs[0].mSecond < RACE_HUD_BURNER_HALF_FRAMES ? 1 : 0;
    for (objectIndex = 0; objectIndex < gRaceHudSubScreenMkdEfBurnerCells->mObjectCount; objectIndex++) {
        object = gRaceHudSubScreenMkdEfBurnerCells->mObjects[objectIndex];
        if ((object->mFlags & 1) == 0 && CountMkdEfBurnerScaleThresholds((MkdEfBurner *) object) != 0) {
            position = &object->mPos;
            if (ComputeRaceHudSubScreenPosition(
                    position, &gRaceHudSubScreenMkdEfBurnerCells->mCells[cellCount].mDrawPos, scale, 0, 0) != FALSE) {
                gRaceHudSubScreenMkdEfBurnerCells->mCells[cellCount].mCell =
                    GetRaceSNcerEntry(gRaceSetup->mCourseId == COURSE_ID_AIRSHIP ? 0xae : 0xb2);
                gRaceHudSubScreenMkdEfBurnerCells->mCells[cellCount].mPriority =
                    IsPositionOutsideBox(position) != 0 ? RACE_HUD_PRIORITY_MIDDLE : RACE_HUD_PRIORITY_BACK;
                gRaceHudSubScreenMkdEfBurnerCells->mObjectPairs[cellCount].mFirst = inFirstHalf != 0 ? 0x1000 : 0xccd;
                cellCount++;
            }
        }
    }
    gRaceHudSubScreenMkdEfBurnerCells->mCellCount = cellCount;
}

void DrawRaceHudSubScreenMkdEfBurnerCells(RaceHudOamBuffer *oamBuffer) {
    DrawRaceHudSubScreenCellsScaled(oamBuffer, gRaceHudSubScreenMkdEfBurnerCells, 0);
}

BOOL CreateRaceHudSubScreenSunFireballCells(void) {
    return CreateRaceHudSubScreenCells(&gRaceHudSubScreenSunFireballCells, MAP_OBJECT_KIND_SUN_FIREBALL);
}

void ClearRaceHudSubScreenSunFireballCells(void) {
    ClearRaceHudSubScreenCells(&gRaceHudSubScreenSunFireballCells);
}

void UpdateRaceHudSubScreenSunFireballCells(void) {
    s32 objectIndex;
    s32 cellCount;
    u32 scale;
    MapObject *object;
    Vec3 *position;

    cellCount = 0;
    scale = GetRaceHudSubScreenScale();
    for (objectIndex = 0; objectIndex < gRaceHudSubScreenSunFireballCells->mObjectCount; objectIndex++) {
        object = gRaceHudSubScreenSunFireballCells->mObjects[objectIndex];
        if ((object->mFlags & 1) == 0) {
            position = &object->mPos;
            if (ComputeRaceHudSubScreenPosition(
                    position, &gRaceHudSubScreenSunFireballCells->mCells[cellCount].mDrawPos, scale, 1, 1) != FALSE) {
                gRaceHudSubScreenSunFireballCells->mCells[cellCount].mCell = GetRaceSNcerEntry(0x8d);
                gRaceHudSubScreenSunFireballCells->mCells[cellCount].mPriority =
                    IsPositionOutsideBox(position) != 0 ? RACE_HUD_PRIORITY_MIDDLE : RACE_HUD_PRIORITY_BACK;
                cellCount++;
            }
        }
    }
    gRaceHudSubScreenSunFireballCells->mCellCount = cellCount;
}

void DrawRaceHudSubScreenSunFireballCells(RaceHudOamBuffer *oamBuffer) {
    DrawRaceHudSubScreenCells(oamBuffer, gRaceHudSubScreenSunFireballCells, 0);
}

s32 CreateRaceHudSubScreenIronBallCells(void) {
    return CreateRaceHudSubScreenCells(&gRaceHudSubScreenIronBallCells, MAP_OBJECT_KIND_IRON_BALL);
}

void ClearRaceHudSubScreenIronBallCells(void) {
    ClearRaceHudSubScreenCells(&gRaceHudSubScreenIronBallCells);
}

void UpdateRaceHudSubScreenIronBallCells(void) {
    s32 objectIndex;
    s32 cellCount;
    u32 scale;
    MapObject *object;
    Vec3 *position;

    cellCount = 0;
    scale = GetRaceHudSubScreenScale();
    for (objectIndex = 0; objectIndex < gRaceHudSubScreenIronBallCells->mObjectCount; objectIndex++) {
        object = gRaceHudSubScreenIronBallCells->mObjects[objectIndex];
        if ((object->mFlags & MAP_OBJECT_FLAG_INVISIBLE) == 0) {
            position = &object->mPos;
            if (ComputeRaceHudSubScreenPosition(position, &gRaceHudSubScreenIronBallCells->mCells[cellCount].mDrawPos,
                                                scale, 1, 1) != FALSE) {
                gRaceHudSubScreenIronBallCells->mCells[cellCount].mCell = GetRaceSNcerEntry(0x92);
                gRaceHudSubScreenIronBallCells->mCells[cellCount].mPriority =
                    IsPositionOutsideBox(position) != 0 ? RACE_HUD_PRIORITY_MIDDLE : RACE_HUD_PRIORITY_BACK;
                gRaceHudSubScreenIronBallCells->mCells[cellCount].mXlu = object->mFlags & MAP_OBJECT_FLAG_HUD_XLU;
                cellCount++;
            }
        }
    }
    gRaceHudSubScreenIronBallCells->mCellCount = cellCount;
}

void DrawRaceHudSubScreenIronBallCells(RaceHudOamBuffer *oamBuffer) {
    DrawRaceHudSubScreenCells(oamBuffer, gRaceHudSubScreenIronBallCells, 0);
}

s32 CreateRaceHudSubScreenKuriboCells(void) {
    return CreateRaceHudSubScreenCells(&gRaceHudSubScreenKuriboCells, MAP_OBJECT_KIND_KURIBO);
}

void ClearRaceHudSubScreenKuriboCells(void) {
    ClearRaceHudSubScreenCells(&gRaceHudSubScreenKuriboCells);
}

void UpdateRaceHudSubScreenKuriboCells(void) {
    s32 objectIndex;
    s32 cellCount;
    u32 scale;
    MapObject *object;
    Vec3 *position;

    cellCount = 0;
    scale = GetRaceHudSubScreenScale();
    for (objectIndex = 0; objectIndex < gRaceHudSubScreenKuriboCells->mObjectCount; objectIndex++) {
        object = gRaceHudSubScreenKuriboCells->mObjects[objectIndex];
        position = &object->mPos;
        if ((object->mFlags & MAP_OBJECT_FLAG_INVISIBLE) == 0) {
            if (ComputeRaceHudSubScreenPosition(position, &gRaceHudSubScreenKuriboCells->mCells[cellCount].mDrawPos,
                                                scale, 0, 1) != FALSE) {
                gRaceHudSubScreenKuriboCells->mCells[cellCount].mCell = GetRaceSNcerEntry(0xa3);
                gRaceHudSubScreenKuriboCells->mCells[cellCount].mPriority =
                    IsPositionOutsideBox(position) != 0 ? RACE_HUD_PRIORITY_MIDDLE : RACE_HUD_PRIORITY_BACK;
                cellCount++;
            }
        }
    }
    gRaceHudSubScreenKuriboCells->mCellCount = cellCount;
}

void DrawRaceHudSubScreenKuriboCells(RaceHudOamBuffer *oamBuffer) {
    DrawRaceHudSubScreenCells(oamBuffer, gRaceHudSubScreenKuriboCells, 0);
}

s32 CreateRaceHudSubScreenObPakkunSfCells(void) {
    return CreateRaceHudSubScreenCells(&gRaceHudSubScreenObPakkunSfCells, MAP_OBJECT_KIND_OB_PAKKUN_SF);
}

void ClearRaceHudSubScreenObPakkunSfCells(void) {
    ClearRaceHudSubScreenCells(&gRaceHudSubScreenObPakkunSfCells);
}

void UpdateRaceHudSubScreenObPakkunSfCells(void) {
    s32 objectIndex;
    s32 cellCount;
    u32 scale;
    MapObject *object;
    Vec3 *position;

    cellCount = 0;
    scale = GetRaceHudSubScreenScale();
    for (objectIndex = 0; objectIndex < gRaceHudSubScreenObPakkunSfCells->mObjectCount; objectIndex++) {
        if (IsRaceHudSubScreenPairNearCenter(&gRaceHudSubScreenObPakkunSfCells->mObjectPairs[objectIndex]) != FALSE) {
            object = gRaceHudSubScreenObPakkunSfCells->mObjects[objectIndex];
            if ((object->mFlags & 1) == 0) {
                position = &object->mPos;
                if (ComputeRaceHudSubScreenPosition(position,
                                                    &gRaceHudSubScreenObPakkunSfCells->mCells[cellCount].mDrawPos,
                                                    scale, 0, 0) != FALSE) {
                    gRaceHudSubScreenObPakkunSfCells->mCells[cellCount].mCell = GetRaceSNcerEntry(
                        ((((ObPakkunSf *) object)->mFramesSinceInit & RACE_HUD_PAKKUN_SF_SWAP_FRAME_BIT) >> 4) != 0
                            ? 0xa2
                            : 0xa1);
                    gRaceHudSubScreenObPakkunSfCells->mCells[cellCount].mPriority =
                        IsPositionOutsideBox(position) != 0 ? RACE_HUD_PRIORITY_MIDDLE : RACE_HUD_PRIORITY_BACK;
                    cellCount++;
                }
            }
        }
    }
    gRaceHudSubScreenObPakkunSfCells->mCellCount = cellCount;
}

void DrawRaceHudSubScreenObPakkunSfCells(RaceHudOamBuffer *oamBuffer) {
    DrawRaceHudSubScreenCells(oamBuffer, gRaceHudSubScreenObPakkunSfCells, 0);
}

s32 CreateRaceHudSubScreenCoverPooHoleCells(void) {
    return CreateRaceHudSubScreenCells(&gRaceHudSubScreenCoverPooHoleCells, MAP_OBJECT_KIND_COVER_POO_HOLE);
}

void ClearRaceHudSubScreenCoverPooHoleCells(void) {
    ClearRaceHudSubScreenCells(&gRaceHudSubScreenCoverPooHoleCells);
}

void UpdateRaceHudSubScreenCoverPooHoleCells(void) {
    s32 objectIndex;
    s32 cellCount;
    u32 scale;
    MapObject *object;
    Vec3 *position;

    cellCount = 0;
    scale = GetRaceHudSubScreenScale();
    for (objectIndex = 0; objectIndex < gRaceHudSubScreenCoverPooHoleCells->mObjectCount; objectIndex++) {
        if (IsRaceHudSubScreenPairNearCenter(&gRaceHudSubScreenCoverPooHoleCells->mObjectPairs[objectIndex]) != FALSE) {
            object = gRaceHudSubScreenCoverPooHoleCells->mObjects[objectIndex];
            if ((object->mFlags & 1) == 0) {
                position = &object->mPos;
                if (ComputeRaceHudSubScreenPosition(position,
                                                    &gRaceHudSubScreenCoverPooHoleCells->mCells[cellCount].mDrawPos,
                                                    scale, 0, 0) != FALSE) {
                    gRaceHudSubScreenCoverPooHoleCells->mCells[cellCount].mDrawPos.mSecond -=
                        GetCoverPooHoleHitCoverHeight((CoverPooHole *) object) >> 14;
                    gRaceHudSubScreenCoverPooHoleCells->mCells[cellCount].mCell =
                        GetRaceSNcerEntry(IsCoverPooHoleRaising((CoverPooHole *) object) != FALSE ? 0xab : 0xaa);
                    gRaceHudSubScreenCoverPooHoleCells->mCells[cellCount].mPriority =
                        IsPositionOutsideBox(position) != 0 ? RACE_HUD_PRIORITY_MIDDLE : RACE_HUD_PRIORITY_BACK;
                    cellCount++;
                }
            }
        }
    }
    gRaceHudSubScreenCoverPooHoleCells->mCellCount = cellCount;
}

void DrawRaceHudSubScreenCoverPooHoleCells(RaceHudOamBuffer *oamBuffer) {
    DrawRaceHudSubScreenCells(oamBuffer, gRaceHudSubScreenCoverPooHoleCells, 0);
}

s32 CreateRaceHudSubScreenRock2Cells(void) {
    return CreateRaceHudSubScreenCells(&gRaceHudSubScreenRock2Cells, MAP_OBJECT_KIND_ROCK2);
}

void ClearRaceHudSubScreenRock2Cells(void) {
    ClearRaceHudSubScreenCells(&gRaceHudSubScreenRock2Cells);
}

void UpdateRaceHudSubScreenRock2Cells(void) {
    s32 objectIndex;
    s32 cellCount;
    u32 scale;
    MapObject *object;
    Vec3 *position;

    cellCount = 0;
    scale = GetRaceHudSubScreenScale();
    for (objectIndex = 0; objectIndex < gRaceHudSubScreenRock2Cells->mObjectCount; objectIndex++) {
        object = gRaceHudSubScreenRock2Cells->mObjects[objectIndex];
        if ((object->mFlags & MAP_OBJECT_FLAG_INVISIBLE) == 0) {
            position = &object->mPos;
            if (ComputeRaceHudSubScreenPosition(position, &gRaceHudSubScreenRock2Cells->mCells[cellCount].mDrawPos,
                                                scale, 1, 1) != FALSE) {
                gRaceHudSubScreenRock2Cells->mCells[cellCount].mCell = GetRaceSNcerEntry(0x8f);
                gRaceHudSubScreenRock2Cells->mCells[cellCount].mPriority =
                    IsPositionOutsideBox(position) != 0 ? RACE_HUD_PRIORITY_MIDDLE : RACE_HUD_PRIORITY_BACK;
                gRaceHudSubScreenRock2Cells->mCells[cellCount].mAngle += 0x400;
                cellCount++;
            }
        }
    }
    gRaceHudSubScreenRock2Cells->mCellCount = cellCount;
}

void DrawRaceHudSubScreenRock2Cells(RaceHudOamBuffer *oamBuffer) {
    DrawRaceHudSubScreenCells(oamBuffer, gRaceHudSubScreenRock2Cells, 1);
}

s32 CreateRaceHudSubScreenSanboCells(void) {
    return CreateRaceHudSubScreenCells(&gRaceHudSubScreenSanboCells, MAP_OBJECT_KIND_SANBO);
}

void ClearRaceHudSubScreenSanboCells(void) {
    ClearRaceHudSubScreenCells(&gRaceHudSubScreenSanboCells);
}

void UpdateRaceHudSubScreenSanboCells(void) {
    s32 objectIndex;
    s32 cellCount;
    u32 scale;
    MapObject *object;
    Vec3 *position;

    cellCount = 0;
    scale = GetRaceHudSubScreenScale();
    for (objectIndex = 0; objectIndex < gRaceHudSubScreenSanboCells->mObjectCount; objectIndex++) {
        if (IsRaceHudSubScreenPairNearCenter(&gRaceHudSubScreenSanboCells->mObjectPairs[objectIndex]) != FALSE) {
            object = gRaceHudSubScreenSanboCells->mObjects[objectIndex];
            if ((object->mFlags & 1) == 0) {
                position = &object->mPos;
                if (ComputeRaceHudSubScreenPosition(position, &gRaceHudSubScreenSanboCells->mCells[cellCount].mDrawPos,
                                                    scale, 0, 0) != FALSE) {
                    gRaceHudSubScreenSanboCells->mCells[cellCount].mCell = GetRaceSNcerEntry(0x8e);
                    gRaceHudSubScreenSanboCells->mCells[cellCount].mPriority =
                        IsPositionOutsideBox(position) != 0 ? RACE_HUD_PRIORITY_MIDDLE : RACE_HUD_PRIORITY_BACK;
                    cellCount++;
                }
            }
        }
    }
    gRaceHudSubScreenSanboCells->mCellCount = cellCount;
}

void DrawRaceHudSubScreenSanboCells(RaceHudOamBuffer *oamBuffer) {
    DrawRaceHudSubScreenCells(oamBuffer, gRaceHudSubScreenSanboCells, 0);
}

s32 CreateRaceHudSubScreenRockCells(void) {
    return CreateRaceHudSubScreenCells(&gRaceHudSubScreenRockCells, MAP_OBJECT_KIND_ROCK);
}

void ClearRaceHudSubScreenRockCells(void) {
    ClearRaceHudSubScreenCells(&gRaceHudSubScreenRockCells);
}

void UpdateRaceHudSubScreenRockCells(void) {
    s32 objectIndex;
    s32 cellCount;
    u32 scale;
    MapObject *object;
    Vec3 *position;

    cellCount = 0;
    scale = GetRaceHudSubScreenScale();
    for (objectIndex = 0; objectIndex < gRaceHudSubScreenRockCells->mObjectCount; objectIndex++) {
        object = gRaceHudSubScreenRockCells->mObjects[objectIndex];
        if ((object->mFlags & MAP_OBJECT_FLAG_INVISIBLE) == 0) {
            position = &object->mPos;
            if (ComputeRaceHudSubScreenPosition(position, &gRaceHudSubScreenRockCells->mCells[cellCount].mDrawPos,
                                                scale, 1, 1) != FALSE) {
                gRaceHudSubScreenRockCells->mCells[cellCount].mCell = GetRaceSNcerEntry(0x99);
                gRaceHudSubScreenRockCells->mCells[cellCount].mPriority =
                    IsPositionOutsideBox(position) != 0 ? RACE_HUD_PRIORITY_MIDDLE : RACE_HUD_PRIORITY_BACK;
                gRaceHudSubScreenRockCells->mCells[cellCount].mAngle += 0x400;
                cellCount++;
            }
        }
    }
    gRaceHudSubScreenRockCells->mCellCount = cellCount;
}

void DrawRaceHudSubScreenRockCells(RaceHudOamBuffer *oamBuffer) {
    DrawRaceHudSubScreenCells(oamBuffer, gRaceHudSubScreenRockCells, 1);
}

s32 CreateRaceHudSubScreenWoodbox1Cells(void) {
    return CreateRaceHudSubScreenCells(&gRaceHudSubScreenWoodbox1Cells, MAP_OBJECT_KIND_WOODBOX1);
}

void ClearRaceHudSubScreenWoodbox1Cells(void) {
    ClearRaceHudSubScreenCells(&gRaceHudSubScreenWoodbox1Cells);
}

void UpdateRaceHudSubScreenWoodbox1Cells(void) {
    s32 objectIndex;
    s32 cellCount;
    u32 scale;
    MapObject *object;
    Vec3 *position;

    cellCount = 0;
    scale = GetRaceHudSubScreenScale();
    for (objectIndex = 0; objectIndex < gRaceHudSubScreenWoodbox1Cells->mObjectCount; objectIndex++) {
        if (IsRaceHudSubScreenPairNearCenter(&gRaceHudSubScreenWoodbox1Cells->mObjectPairs[objectIndex]) != FALSE) {
            object = gRaceHudSubScreenWoodbox1Cells->mObjects[objectIndex];
            if ((object->mFlags & 1) == 0) {
                position = &object->mPos;
                if (ComputeRaceHudSubScreenPosition(
                        position, &gRaceHudSubScreenWoodbox1Cells->mCells[cellCount].mDrawPos, scale, 0, 0) != FALSE) {
                    gRaceHudSubScreenWoodbox1Cells->mCells[cellCount].mCell = GetRaceSNcerEntry(0x5c);
                    gRaceHudSubScreenWoodbox1Cells->mCells[cellCount].mPriority =
                        IsPositionOutsideBox(position) != 0 ? RACE_HUD_PRIORITY_MIDDLE : RACE_HUD_PRIORITY_BACK;
                    cellCount++;
                }
            }
        }
    }
    gRaceHudSubScreenWoodbox1Cells->mCellCount = cellCount;
}

void DrawRaceHudSubScreenWoodbox1Cells(RaceHudOamBuffer *oamBuffer) {
    DrawRaceHudSubScreenCells(oamBuffer, gRaceHudSubScreenWoodbox1Cells, 0);
}

s32 CreateRaceHudSubScreenFlipperCells(void) {
    return CreateRaceHudSubScreenCells(&gRaceHudSubScreenFlipperCells, MAP_OBJECT_KIND_FLIPPER);
}

void ClearRaceHudSubScreenFlipperCells(void) {
    ClearRaceHudSubScreenCells(&gRaceHudSubScreenFlipperCells);
}

void UpdateRaceHudSubScreenFlipperCells(void) {
    s32 objectIndex;
    s32 cellCount;
    u32 scale;
    MapObject *object;
    Vec3 *position;

    cellCount = 0;
    scale = GetRaceHudSubScreenScale();
    for (objectIndex = 0; objectIndex < gRaceHudSubScreenFlipperCells->mObjectCount; objectIndex++) {
        object = gRaceHudSubScreenFlipperCells->mObjects[objectIndex];
        if ((object->mFlags & MAP_OBJECT_FLAG_INVISIBLE) == 0) {
            position = &object->mPos;
            if (ComputeRaceHudSubScreenPosition(position, &gRaceHudSubScreenFlipperCells->mCells[cellCount].mDrawPos,
                                                scale, 1, 1) != FALSE) {
                gRaceHudSubScreenFlipperCells->mCells[cellCount].mCell = GetRaceSNcerEntry(0x90);
                gRaceHudSubScreenFlipperCells->mCells[cellCount].mPriority =
                    IsPositionOutsideBox(position) != 0 ? RACE_HUD_PRIORITY_MIDDLE : RACE_HUD_PRIORITY_BACK;
                gRaceHudSubScreenFlipperCells->mCells[cellCount].mXlu = object->mFlags & MAP_OBJECT_FLAG_FLIPPER_MIRROR;
                gRaceHudSubScreenFlipperCells->mCells[cellCount].mAngle = object->mAngle;
                cellCount++;
            }
        }
    }
    gRaceHudSubScreenFlipperCells->mCellCount = cellCount;
}

void DrawRaceHudSubScreenFlipperCells(RaceHudOamBuffer *oamBuffer) {
    s32 cellIndex;
    s32 minDrawValue;
    u16 screenAngle;
    u16 priority;
    s32 oamIndex;
    u16 matrixIndex;
    RaceHudSubScreenCell *cell;
    MtxFx22 matrix;
    s32 position[2];
    s32 drawX;
    struct NNSG2dCellDataWithBR *ncerEntry;
    s32 drawY;

    minDrawValue = GetRaceHudSubScreenMinDrawValue();
    screenAngle = GetSubScreenAngleAndClearScrollTimer();
    for (cellIndex = 0; cellIndex < gRaceHudSubScreenFlipperCells->mCellCount; cellIndex++) {
        priority = gRaceHudSubScreenFlipperCells->mCells[cellIndex].mPriority;
        if (minDrawValue <= priority) {
            if (gRaceHudSubScreenFlipperCells->mCells[cellIndex].mXlu != 0) {
                if (gRaceSetup->mMirrorMode != 0) {
                    Matrix2x2ReflectedRotation(
                        &matrix,
                        (u16) (screenAngle + (gRaceHudSubScreenFlipperCells->mCells[cellIndex].mAngle + 0x4000)));
                } else {
                    Matrix2x2ReflectedRotation(
                        &matrix,
                        (u16) (0x4000 - gRaceHudSubScreenFlipperCells->mCells[cellIndex].mAngle - screenAngle));
                }
            } else {
                if (gRaceSetup->mMirrorMode != 0) {
                    Matrix2x2Rotation(&matrix, (u16) (gRaceHudSubScreenFlipperCells->mCells[cellIndex].mAngle + 0x4000 -
                                                      screenAngle));
                } else {
                    Matrix2x2Rotation(
                        &matrix,
                        (u16) (screenAngle + (0x4000 - gRaceHudSubScreenFlipperCells->mCells[cellIndex].mAngle)));
                }
            }
            matrixIndex = AllocOamMatrixIndex(oamBuffer);
            oamBuffer->mMatrices[matrixIndex].mPA = matrix.mElements[0] >> 4;
            oamBuffer->mMatrices[matrixIndex].mPB = matrix.mElements[1] >> 4;
            oamBuffer->mMatrices[matrixIndex].mPC = matrix.mElements[2] >> 4;
            oamBuffer->mMatrices[matrixIndex].mPD = matrix.mElements[3] >> 4;
            oamIndex = oamBuffer->mOamCount;
            cell = &gRaceHudSubScreenFlipperCells->mCells[cellIndex];
            drawX = cell->mDrawPos.mFirst;
            ncerEntry = cell->mCell;
            drawY = cell->mDrawPos.mSecond;
            position[0] = TO_FIXED12(drawX);
            position[1] = TO_FIXED12(drawY);
            oamBuffer->mOamCount += NNS_G2dMakeCellToOams(&oamBuffer->mOams[oamIndex], 0x80 - oamIndex, ncerEntry,
                                                          &matrix, position, matrixIndex, 1);
            for (; oamIndex < oamBuffer->mOamCount; oamIndex++) {
                if (priority != -1) {
                    oamBuffer->mOamBits[oamIndex].mPriority = priority;
                }
            }
        }
    }
}

s32 CreateRaceHudSubScreenNsKiller2Cells(void) {
    return CreateRaceHudSubScreenCells(&gRaceHudSubScreenNsKiller2Cells, MAP_OBJECT_KIND_NS_KILLER2);
}

void ClearRaceHudSubScreenNsKiller2Cells(void) {
    ClearRaceHudSubScreenCells(&gRaceHudSubScreenNsKiller2Cells);
}

void UpdateRaceHudSubScreenNsKiller2Cells(void) {
    s32 objectIndex;
    s32 cellCount;
    u32 scale;
    MapObject *object;

    cellCount = 0;
    scale = GetRaceHudSubScreenScale();
    for (objectIndex = 0; objectIndex < gRaceHudSubScreenNsKiller2Cells->mObjectCount; objectIndex++) {
        object = gRaceHudSubScreenNsKiller2Cells->mObjects[objectIndex];
        if ((object->mFlags & 1) == 0 && (object->mFlags & MAP_OBJECT_FLAG_INVISIBLE) == 0) {
            if (ComputeRaceHudSubScreenPosition(&object->mPos,
                                                &gRaceHudSubScreenNsKiller2Cells->mCells[cellCount].mDrawPos, scale, 1,
                                                1) != FALSE) {
                gRaceHudSubScreenNsKiller2Cells->mCells[cellCount].mCell = GetRaceSNcerEntry(0xad);
                gRaceHudSubScreenNsKiller2Cells->mCells[cellCount].mPriority = RACE_HUD_PRIORITY_BACK;
                gRaceHudSubScreenNsKiller2Cells->mCells[cellCount].mXlu = 0;
                gRaceHudSubScreenNsKiller2Cells->mCells[cellCount].mAngle = object->mAngle;
                cellCount++;
            }
        }
    }
    gRaceHudSubScreenNsKiller2Cells->mCellCount = cellCount;
}

void DrawRaceHudSubScreenNsKiller2Cells(RaceHudOamBuffer *oamBuffer) {
    DrawRaceHudSubScreenCells(oamBuffer, gRaceHudSubScreenNsKiller2Cells, 1);
}

s32 CreateRaceHudSubScreenPendulumCells(void) {
    return CreateRaceHudSubScreenCells(&gRaceHudSubScreenPendulumCells, MAP_OBJECT_KIND_PENDULUM);
}

void ClearRaceHudSubScreenPendulumCells(void) {
    ClearRaceHudSubScreenCells(&gRaceHudSubScreenPendulumCells);
}

void UpdateRaceHudSubScreenPendulumCells(void) {
    s32 objectIndex;
    s32 cellCount;
    u32 scale;
    MapObject *object;
    Vec3 *position;

    cellCount = 0;
    scale = GetRaceHudSubScreenScale();
    for (objectIndex = 0; objectIndex < gRaceHudSubScreenPendulumCells->mObjectCount; objectIndex++) {
        object = gRaceHudSubScreenPendulumCells->mObjects[objectIndex];
        if ((object->mFlags & MAP_OBJECT_FLAG_INVISIBLE) == 0) {
            position = &object->mPos;
            if (ComputeRaceHudSubScreenPosition(position, &gRaceHudSubScreenPendulumCells->mCells[cellCount].mDrawPos,
                                                scale, 1, 1) != FALSE) {
                gRaceHudSubScreenPendulumCells->mCells[cellCount].mCell = GetRaceSNcerEntry(0xa0);
                gRaceHudSubScreenPendulumCells->mCells[cellCount].mPriority =
                    IsPositionOutsideBox(position) != 0 ? RACE_HUD_PRIORITY_MIDDLE : RACE_HUD_PRIORITY_BACK;
                gRaceHudSubScreenPendulumCells->mCells[cellCount].mXlu = 0;
                gRaceHudSubScreenPendulumCells->mCells[cellCount].mAngle = object->mAngle;
                cellCount++;
            }
        }
    }
    gRaceHudSubScreenPendulumCells->mCellCount = cellCount;
}

void DrawRaceHudSubScreenPendulumCells(RaceHudOamBuffer *oamBuffer) {
    DrawRaceHudSubScreenCells(oamBuffer, gRaceHudSubScreenPendulumCells, 1);
}
