#include "Main/Race/race_hud_sub_screen_bomb_koura_w_cells.h"
#include "registers.h"
#include "Main/System/heap_call.h"
#include "Main/System/heap.h"
#include "Main/Race/race_hud_keyboard_map_object_work.h"
#include "Main/Kart/course_models.h"
#include "thread_scheduler.h"
#include "Main/Race/race_hud_sub_screen_cells.h"
#include "Main/MapObjects/view_frustum.h"
#include "Main/MapObjects/koopa_block.h"
#include "Main/MapObjects/bridge_animation_frame.h"
#include "Main/Item/item_objects_and_race_progress.h"
#include "Main/MapObjects/map_objects_get.h"
#include "Main/MapObjects/map_object_kind_update_list.h"
#include "Main/Race/race_setup_block.h"
#include "touch_panel_sampling.h"
#include "arena_cache_init.h"
#include "vram_load_2d_graphics.h"
#include "Main/Graphics/oam.h"
#include "Main/Graphics/font_and_player_character.h"
#include "Main/Race/race_hud_sub_screen_frames.h"
#include "Main/Kart/point_link_cursor.h"
#include "Main/Race/race_hud_sub_screen_course_id.h"
#include "model_material_set.h"
#include "Main/Race/graphic_file_loaders_and_matrix2x2.h"
#include "Main/Race/race_hud_sub_screen_min_max.h"
#include "Main/Kart/kart_heading_item_effect.h"
#include "Main/Race/race_hud_sub_screen_projection.h"
#include "Main/Race/race_ncer_entry_getters.h"
#include "sprite_animation_control.h"
#include "Main/Item/item_koura_w.h"
#include "Main/Item/item_bomb.h"
#include "Main/Item/item_pool.h"

RaceHudSubScreenCells *gRaceHudSubScreenBombKouraWCells;
RaceHudSubScreenBgColors *gRaceHudSubScreenBgColors;

void InitRaceHudSubScreenBgColors(void) {
    gRaceHudSubScreenBgColors = HeapAlloc(GetHeap(GetCurrentHeapCall()), sizeof(*gRaceHudSubScreenBgColors));
}

u8 gRaceHudSubScreenBgColorsOrderPad[24];

void CopyRaceHudSubScreenBgColors(void) {
    s32 index;
    s32 columnIndex;

    switch (gRaceSetup->mCourseId) {
        case COURSE_ID_OLD_NOKO_SFC:
            for (index = 0; index < 9; index++) {
                for (columnIndex = 0; columnIndex < 3; columnIndex++) {
                    gRaceHudSubScreenBgColors->mColors.mFrameColors[index][columnIndex] =
                        HW_DB_BG_PLTT[index * 16 + columnIndex + 0x40];
                }
            }
            break;
        case COURSE_ID_CLOCK: {
            s32 rowOffsets[5] = {0, 5, 10, 16, 21};

            for (index = 0; index < 5; index++) {
                for (columnIndex = 0; columnIndex < 4; columnIndex++) {
                    gRaceHudSubScreenBgColors->mColors.mGearColors[index][columnIndex] =
                        HW_DB_BG_PLTT[rowOffsets[index] + columnIndex + 0x80];
                }
            }
            break;
        }
        case COURSE_ID_TOWN:
            for (index = 0; index < 20; index++) {
                gRaceHudSubScreenBgColors->mColors.mColorList[index] = HW_DB_BG_PLTT[0x78 + index];
            }
            gRaceHudSubScreenBgColors->mColors.mColorList[20] = HW_DB_BG_PLTT[0];
            break;
        case COURSE_ID_BEACH:
            for (index = 0; index < 3; index++) {
                gRaceHudSubScreenBgColors->mColors.mColorList[index] = HW_DB_BG_PLTT[0x46 + index];
            }
            break;
        case COURSE_ID_KOOPA:
            for (index = 0; index < 6; index++) {
                gRaceHudSubScreenBgColors->mColors.mKoopaColors.mSecondObjectColors[index] =
                    HW_DB_BG_PLTT[0x54 + index];
            }
            for (index = 0; index < 2; index++) {
                for (columnIndex = 0; columnIndex < 3; columnIndex++) {
                    gRaceHudSubScreenBgColors->mColors.mKoopaColors.mFirstObjectColors[index][columnIndex] =
                        HW_DB_BG_PLTT[index * 3 + columnIndex + 0x5a];
                }
            }
            for (index = 0; index < 2; index++) {
                gRaceHudSubScreenBgColors->mColors.mKoopaColors.mKoopaBlockColors[index] = HW_DB_BG_PLTT[index];
            }
            break;
        case COURSE_ID_MINI_STAGE3:
            for (index = 0; index < 5; index++) {
                gRaceHudSubScreenBgColors->mColors.mColorList[index] = HW_DB_BG_PLTT[0xfb + index];
            }
            break;
    }
    gRaceHudSubScreenBgColors->mUnk_00 = 0;
}

void UpdateRaceHudSubScreenBgPalette(u16 *palette) {
    s32 index;
    s32 colorIndex;
    s32 shift;
    s32 limit;
    s32 offset;
    s32 value;
    u32 waterAngle;
    float threshold;

    switch (gRaceSetup->mCourseId) {
        case COURSE_ID_OLD_NOKO_SFC:
            value = GetCourseModelNsbtpFrame();
            for (index = 0; index < 3; index++) {
                palette[index + 0x40] = gRaceHudSubScreenBgColors->mColors.mFrameColors[value / 10][index];
            }
            DC_FlushRange(&palette[0x40], 6);
            GXS_BeginLoadBGExtPltt();
            GXS_LoadBGExtPltt(&palette[0x40], 0x4080, 6);
            if (IsCourseWithMap2DLocal3() != 0) {
                GXS_LoadBGExtPltt(&palette[0x40], 0x6080, 6);
            }
            GXS_EndLoadBGExtPltt();
            break;
        case COURSE_ID_CLOCK: {
            s32 rowOffsets[5] = {0, 5, 10, 16, 21};
            MapObject **objects;
            void *kindDrawList;
            u16 angle;

            kindDrawList = FindMapObjectKindDrawList0(MAP_OBJECT_KIND_ROTARY_GEAR);
            if (kindDrawList != NULL) {
                objects = RaceHudSubScreenGetMapObjects(kindDrawList);
                for (index = 0; index < 5; index++) {
                    angle = objects[index]->mAngle;
                    if (index == 4) {
                        shift = (angle * 0xb4) >> 16;
                    } else {
                        shift = (angle * 0x48) >> 16;
                    }
                    for (colorIndex = 0; colorIndex < 4; colorIndex++) {
                        palette[rowOffsets[index] + colorIndex + 0x80] =
                            gRaceHudSubScreenBgColors->mColors.mGearColors[index][(colorIndex + shift) % 4];
                    }
                }
            }
            DC_FlushRange(&palette[0x80], 0x34);
            GXS_BeginLoadBGExtPltt();
            GXS_LoadBGExtPltt(&palette[0x80], 0x4100, 0x34);
            if (IsCourseWithMap2DLocal3() != 0) {
                GXS_LoadBGExtPltt(&palette[0x80], 0x6100, 0x34);
            }
            GXS_EndLoadBGExtPltt();
            break;
        }
        case COURSE_ID_TOWN: {
            u8 colorIndexRows[6][20] = {{0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19},
                                        {20, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19},
                                        {20, 20, 1, 2, 3, 4, 5, 6, 7, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19},
                                        {20, 20, 20, 1, 2, 3, 4, 5, 6, 7, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18},
                                        {20, 20, 20, 20, 1, 2, 3, 4, 5, 6, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18},
                                        {20, 20, 20, 20, 20, 1, 2, 3, 4, 5, 6, 9, 10, 11, 12, 13, 14, 15, 16, 17}};
            u8 *colorIndexCursor;

            value = GetFirstBridgeAnimationFrame();
            if (value < 0x13) {
                colorIndex = 0;
            } else if (value < 0x2c) {
                colorIndex = 1;
            } else if (value < 0x38) {
                colorIndex = 2;
            } else if (value < 0x43) {
                colorIndex = 3;
            } else if (value < 0x4c) {
                colorIndex = 4;
            } else {
                colorIndex = 5;
            }
            colorIndexCursor = colorIndexRows[colorIndex];
            for (index = 0; index < 20; index++) {
                palette[index + 0x78] = gRaceHudSubScreenBgColors->mColors.mColorList[*colorIndexCursor];
                colorIndexCursor++;
            }
            DC_FlushRange(&palette[0x78], 0x28);
            GXS_BeginLoadBGExtPltt();
            GXS_LoadBGExtPltt(&palette[0x78], 0x40f0, 0x28);
            if (IsCourseWithMap2DLocal3() != 0) {
                GXS_LoadBGExtPltt(&palette[0x78], 0x60f0, 0x28);
            }
            GXS_EndLoadBGExtPltt();
            break;
        }
        case COURSE_ID_BEACH:
            if (IsWaterPresent() != FALSE) {
                limit = GetWaterHeightFactor();
                for (offset = 7; offset > 0; offset--) {
                    threshold = (7 - offset) * 0.286f + -0.858f;
                    value = threshold > 0.0f ? threshold * 4096.0f + 0.5f : threshold * 4096.0f - 0.5f;
                    if (limit < value) {
                        break;
                    }
                }
                for (colorIndex = 0; colorIndex < offset; colorIndex++) {
                    palette[colorIndex + 0x50] = gRaceHudSubScreenBgColors->mColors.mColorList[0];
                }
                for (colorIndex = offset; colorIndex == offset; colorIndex++) {
                    palette[colorIndex + 0x50] = gRaceHudSubScreenBgColors->mColors.mColorList[1];
                }
                for (colorIndex = offset + 1; colorIndex < 8; colorIndex++) {
                    palette[colorIndex + 0x50] = gRaceHudSubScreenBgColors->mColors.mColorList[2];
                }
            }
            DC_FlushRange(&palette[0x50], 0x10);
            GXS_BeginLoadBGExtPltt();
            GXS_LoadBGExtPltt(&palette[0x50], 0x40a0, 0x10);
            if (IsCourseWithMap2DLocal3() != 0) {
                GXS_LoadBGExtPltt(&palette[0x50], 0x60a0, 0x10);
            }
            GXS_EndLoadBGExtPltt();
            break;
        case COURSE_ID_KOOPA: {
            void *kindDrawList;
            MapObject **objects;
            KoopaBlock **blocks;

            kindDrawList = FindMapObjectKindDrawList0(0xd0);
            if (kindDrawList != NULL) {
                objects = RaceHudSubScreenGetMapObjects(kindDrawList);
                value = (objects[1]->mAngle * 0x48) >> 16;
                for (index = 0; index < 6; index++) {
                    palette[index + 0x54] = gRaceHudSubScreenBgColors->mColors.mKoopaColors
                                                   .mSecondObjectColors[(index + 0x48 - value) % 6];
                }
                offset = (objects[0]->mAngle << 5) >> 16;
                for (index = 0; index < 2; index++) {
                    for (colorIndex = 0; colorIndex < 3; colorIndex++) {
                        palette[colorIndex + index * 3 + 0x5a] =
                            gRaceHudSubScreenBgColors->mColors.mKoopaColors
                                .mFirstObjectColors[index][(colorIndex + 0x20 - offset) % 3];
                    }
                }
            }
            kindDrawList = FindMapObjectKindDrawList0(MAP_OBJECT_KIND_KOOPA_BLOCK);
            if (kindDrawList != NULL) {
                blocks = RaceHudSubScreenGetMapObjects(kindDrawList);
                for (index = 0; index < 4; index++) {
                    value = GetKoopaBlockProgress(blocks[index]);
                    if (index % 2 != 0) {
                        limit = (value << 3) >> 12;
                    } else {
                        limit = 8 - ((value << 3) >> 12);
                    }
                    for (colorIndex = 0; colorIndex < limit; colorIndex++) {
                        palette[index * 16 + colorIndex + 0x60] =
                            gRaceHudSubScreenBgColors->mColors.mKoopaColors.mKoopaBlockColors[0];
                    }
                    for (colorIndex = limit; colorIndex < limit + 8; colorIndex++) {
                        palette[index * 16 + colorIndex + 0x60] =
                            gRaceHudSubScreenBgColors->mColors.mKoopaColors.mKoopaBlockColors[1];
                    }
                    for (colorIndex = limit + 8; colorIndex < 16; colorIndex++) {
                        palette[index * 16 + colorIndex + 0x60] =
                            gRaceHudSubScreenBgColors->mColors.mKoopaColors.mKoopaBlockColors[0];
                    }
                }
            }
            DC_FlushRange(&palette[0x54], 0x98);
            GXS_BeginLoadBGExtPltt();
            GXS_LoadBGExtPltt(&palette[0x54], 0x40a8, 0x98);
            if (IsCourseWithMap2DLocal3() != 0) {
                GXS_LoadBGExtPltt(&palette[0x54], 0x60a8, 0x98);
            }
            GXS_EndLoadBGExtPltt();
            break;
        }
        case COURSE_ID_MINI_STAGE3:
            if (IsWaterPresent() != FALSE) {
                limit = GetWaterHeightFactor();
                waterAngle = GetWaterHeightAngle();
                for (offset = 0; offset < 0x13; offset++) {
                    threshold = offset * 0.105f + -0.945f;
                    value = threshold > 0.0f ? threshold * 4096.0f + 0.5f : threshold * 4096.0f - 0.5f;
                    if (limit < value) {
                        break;
                    }
                }
                offset += 2;
                for (colorIndex = 0; colorIndex < offset - 2; colorIndex++) {
                    palette[colorIndex + 0xe0] = gRaceHudSubScreenBgColors->mColors.mColorList[0];
                }
                for (colorIndex = offset - 4; colorIndex < offset - 2; colorIndex++) {
                    if (colorIndex >= 0) {
                        palette[colorIndex + 0xe0] = gRaceHudSubScreenBgColors->mColors.mColorList[1];
                    }
                }
                for (colorIndex = offset - 2; colorIndex <= offset; colorIndex++) {
                    palette[colorIndex + 0xe0] = gRaceHudSubScreenBgColors->mColors.mColorList[2];
                }
                if (waterAngle >= 0x4000 && waterAngle < 0xc000) {
                    for (colorIndex = offset + 1; colorIndex <= offset + 2 && colorIndex < 0x15; colorIndex++) {
                        palette[colorIndex + 0xe0] = gRaceHudSubScreenBgColors->mColors.mColorList[3];
                    }
                    offset += 2;
                }
                for (colorIndex = offset + 1; colorIndex < 0x15; colorIndex++) {
                    palette[colorIndex + 0xe0] = gRaceHudSubScreenBgColors->mColors.mColorList[4];
                }
            }
            DC_FlushRange(&palette[0xe0], 0x2c);
            GXS_BeginLoadBGExtPltt();
            GXS_LoadBGExtPltt(&palette[0xe0], 0x41c0, 0x2c);
            if (IsCourseWithMap2DLocal3() != 0) {
                GXS_LoadBGExtPltt(&palette[0xe0], 0x61c0, 0x2c);
            }
            GXS_EndLoadBGExtPltt();
            break;
    }
}

s32 CreateRaceHudSubScreenBombKouraWCells(void) {
    s32 itemCount;

    itemCount = 0;
    itemCount += gItemKinds[5].mObjectCount;
    itemCount += gItemKinds[9].mObjectCount;
    return CreateRaceHudSubScreenCellsWithCount(&gRaceHudSubScreenBombKouraWCells, itemCount);
}

void ClearRaceHudSubScreenBombKouraWCells(void) {
    ClearRaceHudSubScreenCells(&gRaceHudSubScreenBombKouraWCells);
}

void UpdateRaceHudSubScreenBombKouraWCells(void) {
    s32 objectIndex;
    s32 cellCount;
    s32 scale;
    s32 activeCount;
    s32 bombStateFrames;
    s32 bombValue;
    ItemPool *pool;
    ItemObject **objects;
    ItemObject *bomb;
    Vec3 *bombPosition;
    s32 kouraStateFrames;
    s32 kouraValue;
    ItemObject *kouraW;
    Vec3 *kouraPosition;

    cellCount = 0;
    scale = GetRaceHudSubScreenScale();
    pool = &gItemPools[ITEM_OBJECT_KIND_BOMB];
    activeCount = pool->mActiveCount;
    objects = pool->mObjects;
    for (objectIndex = 0; objectIndex < activeCount; objectIndex++) {
        bomb = objects[objectIndex];
        if (IsItemBombGrowing(bomb) != FALSE) {
            bombPosition = GetItemBombGrowInfo((ItemBomb *) bomb, &bombStateFrames, &bombValue);
            if (ComputeRaceHudSubScreenPosition(bombPosition,
                                                &gRaceHudSubScreenBombKouraWCells->mCells[cellCount].mDrawPos, scale, 1,
                                                1) != FALSE) {
                gRaceHudSubScreenBombKouraWCells->mCells[cellCount].mCell = GetRaceSNcerEntry(0x63);
                gRaceHudSubScreenBombKouraWCells->mCells[cellCount].mPriority =
                    IsPositionOutsideBox(bombPosition) != 0 ? RACE_HUD_PRIORITY_MIDDLE : RACE_HUD_PRIORITY_BACK;
// Frame count, not an angle: this list is drawn without rotation.
                gRaceHudSubScreenBombKouraWCells->mCells[cellCount].mAngle = bombStateFrames;
                gRaceHudSubScreenBombKouraWCells->mCells[cellCount].mXlu = bombStateFrames >= 0x16 ? 1 : 0;
                if (bombStateFrames >= 0x16) {
                    bombValue = InterpolateS16(1, 0x1000, 10, bombStateFrames - 0x16, 0x22);
                }
                gRaceHudSubScreenBombKouraWCells->mObjectPairs[cellCount].mFirst = bombValue;
                cellCount++;
            }
        }
    }
    pool = &gItemPools[ITEM_OBJECT_KIND_KOURA_W];
    activeCount = pool->mActiveCount;
    objects = pool->mObjects;
    for (objectIndex = 0; objectIndex < activeCount; objectIndex++) {
        kouraW = objects[objectIndex];
        if (IsItemKouraWGrowing((ItemKouraW *) kouraW) != FALSE) {
            kouraPosition = GetItemKouraWGrowInfo((ItemKouraW *) kouraW, &kouraStateFrames, &kouraValue);
            if (ComputeRaceHudSubScreenPosition(kouraPosition,
                                                &gRaceHudSubScreenBombKouraWCells->mCells[cellCount].mDrawPos, scale, 1,
                                                1) != FALSE) {
                gRaceHudSubScreenBombKouraWCells->mCells[cellCount].mCell = GetRaceSNcerEntry(0x64);
                gRaceHudSubScreenBombKouraWCells->mCells[cellCount].mPriority =
                    IsPositionOutsideBox(kouraPosition) != 0 ? RACE_HUD_PRIORITY_MIDDLE : RACE_HUD_PRIORITY_BACK;
// Frame count, not an angle: this list is drawn without rotation.
                gRaceHudSubScreenBombKouraWCells->mCells[cellCount].mAngle = kouraStateFrames;
                gRaceHudSubScreenBombKouraWCells->mCells[cellCount].mXlu = kouraStateFrames >= 0x16 ? 1 : 0;
                if (kouraStateFrames >= 0x16) {
                    kouraValue = InterpolateS16(1, 0x1000, 10, kouraStateFrames - 0x16, 0x22);
                }
                gRaceHudSubScreenBombKouraWCells->mObjectPairs[cellCount].mFirst = kouraValue;
                cellCount++;
            }
        }
    }
    gRaceHudSubScreenBombKouraWCells->mCellCount = cellCount;
}

void DrawRaceHudSubScreenBombKouraWCells(RaceHudOamBuffer *oamBuffer) {
    DrawRaceHudSubScreenCellsScaled(oamBuffer, gRaceHudSubScreenBombKouraWCells, 0);
}
