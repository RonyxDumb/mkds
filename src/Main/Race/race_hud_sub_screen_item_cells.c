#include "Main/Race/race_hud_sub_screen_item_cells.h"

#include "Main/Race/race_hud_sub_screen_cells.h"
#include "Main/Graphics/font_and_player_character.h"
#include "Main/Race/race_hud_sub_screen_frames.h"
#include "Main/Kart/point_link_cursor.h"
#include "Main/Race/race_hud_sub_screen_course_id.h"
#include "model_material_set.h"
#include "Main/Race/race_setup_block.h"
#include "touch_panel_sampling.h"
#include "Main/Race/graphic_file_loaders_and_matrix2x2.h"
#include "Main/Race/race_hud_sub_screen_min_max.h"
#include "Main/Kart/kart_heading_item_effect.h"
#include "Main/Race/race_hud_sub_screen_projection.h"
#include "Main/Race/race_ncer_entry_getters.h"
#include "sprite_animation_control.h"
#include "Main/MapObjects/item_box.h"
#include "Main/MapObjects/choropu.h"
#include "Main/MapObjects/map_object_kind_update_list.h"
#include "Main/Race/race_hud_keyboard_map_object_work.h"
#include "Main/MapObjects/dossun.h"
#include "Main/Graphics/oam.h"
#include "Main/System/heap_call.h"
#include "Main/MapObjects/map_objects_get.h"
#include "Main/MapObjects/pooled_tail_count.h"
#include "cell_animation.h"
#include "fixed_arctangent.h"
#include "Main/System/heap.h"
#include "Main/Kart/shadow_model_draw.h"
#include "Main/Race/race_hud_sub_screen_mode.h"
#include "Main/MapObjects/view_frustum.h"
#include "Main/Item/item_pool.h"
#include "Main/Item/item_objects_and_race_progress.h"
#include "Main/Item/item_object.h"
#include "Main/Item/item_bomb.h"
#include "Main/Item/item_teresa_offset.h"
#include "Main/Item/kart_items_collision_hits.h"
#include "Main/Race/race_clock.h"
#include "Main/Kart/karts.h"
#include "fixed_vector_math.h"
#include "Main/Race/race_hud_sub_screen_item_box_cells.h"

s32 gRaceHudSubScreenItemPoolIndices[10] = {0, 1, 2, 3, 4, 5, 9, 7, 8, 11};
struct RaceHudSubScreenCells *gRaceHudSubScreenChoropuCells;
struct RaceHudSubScreenCells *gRaceHudSubScreenKoopaBlockCells;
struct RaceHudSubScreenCells *gRaceHudSubScreenWanwanCells;
RaceHudSubScreenCells *gRaceHudSubScreenCrabCells;
struct RaceHudSubScreenCells *gRaceHudSubScreenSmanCells;
struct RaceHudSubScreenCells *gRaceHudSubScreenMoveTreeCells;
struct RaceHudSubScreenCells *gRaceHudSubScreenPukupukuCells;
struct RaceHudSubScreenCells *gRaceHudSubScreenEarthenPipeCells;
struct RaceHudSubScreenCells *gRaceHudSubScreenDossunCells;
struct RaceHudSubScreenCells *gRaceHudSubScreenCarCells;
struct RaceHudSubScreenSecondHand *gRaceHudSubScreenSecondHand;
struct RaceHudSubScreenKarts *gRaceHudSubScreenKarts;
struct RaceHudSubScreenCells *gRaceHudSubScreenItemCells;

// Indices into gItemKinds and gItemPools.

void UpdateRaceHudSubScreenCrabCells(void) {
    s32 objectIndex;
    s32 cellCount;
    u32 scale;

    cellCount = 0;
    scale = GetRaceHudSubScreenScale();
    for (objectIndex = 0; objectIndex < gRaceHudSubScreenCrabCells->mObjectCount; objectIndex++) {
        MapObject *object;

        object = gRaceHudSubScreenCrabCells->mObjects[objectIndex];
        if (!(object->mFlags & 1)) {
            if (ComputeRaceHudSubScreenPosition(&object->mPos, &gRaceHudSubScreenCrabCells->mCells[cellCount].mDrawPos,
                                                scale, 1, 1)) {
                gRaceHudSubScreenCrabCells->mCells[cellCount].mCell = GetRaceSNcerEntry(0x8a);
                gRaceHudSubScreenCrabCells->mCells[cellCount].mPriority = RACE_HUD_PRIORITY_MIDDLE;
                cellCount++;
            }
        }
    }
    gRaceHudSubScreenCrabCells->mCellCount = cellCount;
}

void DrawRaceHudSubScreenCrabCells(RaceHudOamBuffer *oamBuffer) {
    DrawRaceHudSubScreenCells(oamBuffer, gRaceHudSubScreenCrabCells, 0);
}

s32 CreateRaceHudSubScreenItemCells(void) {
    s32 objectCount;
    s32 kindIndex;

    objectCount = 0;
    for (kindIndex = 0; kindIndex < 10; kindIndex++) {
        objectCount += gItemKinds[gRaceHudSubScreenItemPoolIndices[kindIndex]].mObjectCount;
    }
    return CreateRaceHudSubScreenCellsWithCount(&gRaceHudSubScreenItemCells, objectCount);
}

void ClearRaceHudSubScreenItemCells(void) {
    ClearRaceHudSubScreenCells(&gRaceHudSubScreenItemCells);
}

void UpdateRaceHudSubScreenItemCells(void) {
    enum { POOL_INDEX_FIRST } poolIndex;
    s32 cellCount;
    s32 scale;
    s32 tableIndex;
    s32 objectIndex;
    ItemPool *pool;
    ItemObject **objects;
    s32 activeCount;
    NNSG2dCellDataWithBR *cell;
    ItemObject *object;
    Vec3 *position;
    s32 teresaOffsetY;

    cellCount = 0;
    scale = GetRaceHudSubScreenScale();
    for (tableIndex = 0; tableIndex < 10; tableIndex++) {
        poolIndex = gRaceHudSubScreenItemPoolIndices[tableIndex];
        pool = &gItemPools[poolIndex];
        objects = pool->mObjects;
        activeCount = pool->mActiveCount;
        {
            s32 cellIndices[10] = {0x4c, 0x4d, 0x4b, 0x4f, 0x50, 0x56, 0x55, 0x54, 0x4e, 0x57};

            cell = GetRaceSNcerEntry(cellIndices[tableIndex]);
        }
        for (objectIndex = 0; objectIndex < activeCount; objectIndex++) {
            object = objects[objectIndex];
            if ((object->mFlags & ITEM_OBJECT_FLAG_ENDED) != 0) {
                position = NULL;
            } else {
                position = &object->mPos;
            }
            if (tableIndex == 9) {
                if (position != NULL) {
                    if (ComputeRaceHudSubScreenPosition(
                            position, &gRaceHudSubScreenItemCells->mCells[cellCount].mDrawPos, scale, 1, 1) != FALSE) {
                        if (object->mAlpha > 0) {
                            teresaOffsetY = ((ItemTeresa *) object)->mOffsetY;
                            gRaceHudSubScreenItemCells->mCells[cellCount].mDrawPos.mSecond -=
                                0x88 * teresaOffsetY / GetTeresaOffsetYDivisor();
                            if (gRaceHudSubScreenItemCells->mCells[cellCount].mDrawPos.mSecond > 0) {
                                gRaceHudSubScreenItemCells->mCells[cellCount].mCell = cell;
                                gRaceHudSubScreenItemCells->mCells[cellCount].mPriority =
                                    IsPositionOutsideBox(position) != 0 ? RACE_HUD_PRIORITY_MIDDLE
                                                                        : RACE_HUD_PRIORITY_BACK;
                                gRaceHudSubScreenItemCells->mCells[cellCount].mXlu = 0;
                                cellCount++;
                            }
                        }
                    }
                }
            } else if (tableIndex == 6) {
                if (((ItemBomb *) object)->mVisible != FALSE && position != NULL) {
                    if (ComputeRaceHudSubScreenPosition(
                            position, &gRaceHudSubScreenItemCells->mCells[cellCount].mDrawPos, scale, 1, 1) != FALSE) {
                        if (IsFarBelowWaterEfct(position->y) == 0) {
                            gRaceHudSubScreenItemCells->mCells[cellCount].mCell = cell;
                            gRaceHudSubScreenItemCells->mCells[cellCount].mPriority =
                                IsPositionOutsideBox(position) != 0 ? RACE_HUD_PRIORITY_MIDDLE : RACE_HUD_PRIORITY_BACK;
                            gRaceHudSubScreenItemCells->mCells[cellCount].mXlu =
                                (object->mFlags & ITEM_OBJECT_FLAG_COURSE_HIT_ATTRIBUTE) != 0 ? 1 : 0;
                            cellCount++;
                        }
                    }
                }
            } else {
                if (position != NULL) {
                    if (ComputeRaceHudSubScreenPosition(
                            position, &gRaceHudSubScreenItemCells->mCells[cellCount].mDrawPos, scale, 1, 1) != FALSE) {
                        if (IsFarBelowWaterEfct(position->y) == 0) {
                            gRaceHudSubScreenItemCells->mCells[cellCount].mCell = cell;
                            gRaceHudSubScreenItemCells->mCells[cellCount].mPriority =
                                IsPositionOutsideBox(position) != 0 ? RACE_HUD_PRIORITY_MIDDLE : RACE_HUD_PRIORITY_BACK;
                            gRaceHudSubScreenItemCells->mCells[cellCount].mXlu =
                                (object->mFlags & ITEM_OBJECT_FLAG_COURSE_HIT_ATTRIBUTE) != 0 ? 1 : 0;
                            cellCount++;
                        }
                    }
                }
            }
        }
    }
    gRaceHudSubScreenItemCells->mCellCount = cellCount;
}

void DrawRaceHudSubScreenItemCells(RaceHudOamBuffer *oamBuffer) {
    DrawRaceHudSubScreenCells(oamBuffer, gRaceHudSubScreenItemCells, 0);
}

s32 CreateRaceHudSubScreenKarts(void) {
    s32 kartIndex;

    gRaceHudSubScreenKarts = HeapAlloc(GetHeap(GetCurrentHeapCall()), sizeof(*gRaceHudSubScreenKarts));
    CreateRaceHudSubScreenCellsWithCount(&gRaceHudSubScreenKarts->mCells, 0x18);
    for (kartIndex = 0; kartIndex < 8; kartIndex++) {
        gRaceHudSubScreenKarts->mVisible[kartIndex] = 0;
        gRaceHudSubScreenKarts->mSpriteHidden[kartIndex] = 0;
        gRaceHudSubScreenKarts->mScreenPos[kartIndex].mFirst = 0;
        gRaceHudSubScreenKarts->mScreenPos[kartIndex].mSecond = 0;
        gRaceHudSubScreenKarts->mAngle[kartIndex] = 0;
        gRaceHudSubScreenKarts->mDrawOrder[kartIndex] = 0;
    }
    return 1;
}

void ClearRaceHudSubScreenKarts(void) {
    ClearRaceHudSubScreenCells(&gRaceHudSubScreenKarts->mCells);
    gRaceHudSubScreenKarts = NULL;
}

void UpdateRaceHudSubScreenKarts(void) {
    s32 sortKeys[8];
    u32 scale;
    u16 kartIndex;
    Vec3 kartPosition;
    Vec3 cellPosition;
    Vec3 linePoint;
    ItemObject **objects;
    s32 objectCount;
    s32 cellCount;
    s32 objectIndex;
    s32 atSetupSize;
    ItemObject *object;
    Vec3 *position;
    u32 objectScale;
    ItemInUse *itemInUse;
    s32 screenX;
    s32 screenY;

    scale = GetRaceHudSubScreenScale();
    for (kartIndex = 0; kartIndex < (u32) gRaceSetup->mKartCount; kartIndex++) {
        gRaceHudSubScreenKarts->mVisible[kartIndex] = 0;
        gRaceHudSubScreenKarts->mDrawOrder[kartIndex] = kartIndex;
        sortKeys[kartIndex] = GetKartRank(kartIndex & 0xff);
    }
    switch (GetRaceHudSubScreenState()) {
        case RACE_HUD_SUB_SCREEN_KART_ICONS:
            for (kartIndex = 0; kartIndex < (u32) gRaceSetup->mKartCount; kartIndex++) {
                ComputeSubScreenKartIconsKartPosition(kartIndex, &gRaceHudSubScreenKarts->mScreenPos[kartIndex]);
                screenX = gRaceHudSubScreenKarts->mScreenPos[kartIndex].mFirst;
                screenY = gRaceHudSubScreenKarts->mScreenPos[kartIndex].mSecond;
                if (screenX > -0x10 && screenX < 0x110 && screenY > -0x10 && screenY < 0xd0 &&
                    IsKartRemovedWrapper(kartIndex) == 0) {
                    gRaceHudSubScreenKarts->mVisible[kartIndex] = 1;
                    if (gRaceSetup->mMode == MODE_TIME_ATTACK &&
                        gRaceSetup->mCurrentEntries[kartIndex].mPlayer.mKind == PLAYER_KIND_GHOST) {
                        gRaceHudSubScreenKarts->mXlu[kartIndex] = 1;
                    } else {
                        gRaceHudSubScreenKarts->mXlu[kartIndex] = 0;
                    }
                    GetKartScale(&gRaceHudSubScreenKarts->mScale[kartIndex], kartIndex);
                    if (GetKart(kartIndex)->mState != KART_STATE_NORMAL) {
                        gRaceHudSubScreenKarts->mNonNormalStateFrames[kartIndex]++;
                        gRaceHudSubScreenKarts->mAngle[kartIndex] =
                            TO_FIXED12(gRaceHudSubScreenKarts->mNonNormalStateFrames[kartIndex]) % 0x10000;
                    } else {
                        gRaceHudSubScreenKarts->mAngle[kartIndex] = 0;
                        gRaceHudSubScreenKarts->mNonNormalStateFrames[kartIndex] = 0;
                    }
                }
            }
            break;
        case RACE_HUD_SUB_SCREEN_MAP_TURNING:
        case RACE_HUD_SUB_SCREEN_MAP_FIXED_SCROLL:
        case RACE_HUD_SUB_SCREEN_MAP_VIEW:
            gRaceHudSubScreenKarts->mCells->mCellCount = 0;
            for (kartIndex = 0; kartIndex < (u32) gRaceSetup->mKartCount; kartIndex++) {
                GetKartPos(&kartPosition, kartIndex & 0xff);
                ComputeRaceHudSubScreenKartPosition(kartIndex, &gRaceHudSubScreenKarts->mScreenPos[kartIndex], scale);
                screenX = gRaceHudSubScreenKarts->mScreenPos[kartIndex].mFirst;
                screenY = gRaceHudSubScreenKarts->mScreenPos[kartIndex].mSecond;
                if (screenX > -0x10 && screenX < 0x110 && screenY > -0x10 && screenY < 0xd0 &&
                    IsKartRemovedWrapper(kartIndex) == 0) {
                    gRaceHudSubScreenKarts->mVisible[kartIndex] = 1;
                    gRaceHudSubScreenKarts->mXlu[kartIndex] = GetKartCourseHitAttributeBitOrGhost(kartIndex);
                    GetKartScale(&gRaceHudSubScreenKarts->mScale[kartIndex], kartIndex);
                    if (GetKart(kartIndex)->mState != KART_STATE_NORMAL) {
                        gRaceHudSubScreenKarts->mNonNormalStateFrames[kartIndex]++;
                        gRaceHudSubScreenKarts->mAngle[kartIndex] =
                            TO_FIXED12(gRaceHudSubScreenKarts->mNonNormalStateFrames[kartIndex]) % 0x10000;
                    } else {
                        gRaceHudSubScreenKarts->mAngle[kartIndex] = 0;
                        gRaceHudSubScreenKarts->mNonNormalStateFrames[kartIndex] = 0;
                    }
                    gRaceHudSubScreenKarts->mPriority[kartIndex] =
                        IsPositionOutsideBox(&kartPosition) != 0 ? RACE_HUD_PRIORITY_MIDDLE : RACE_HUD_PRIORITY_BACK;
                    itemInUse = &gKartItems[kartIndex].mItemInUse;
                    objects = itemInUse->mObjects;
                    objectCount = itemInUse->mObjectCount;
                    cellCount = gRaceHudSubScreenKarts->mCells->mCellCount;
                    objectScale = GetRaceHudSubScreenScale();
                    for (objectIndex = 0; objectIndex < objectCount; objectIndex++) {
                        object = objects[objectIndex];
                        if ((object->mFlags & ITEM_OBJECT_FLAG_ENDED) != 0) {
                            position = NULL;
                        } else {
                            position = &object->mPos;
                        }
                        atSetupSize = IsItemObjectScaleAtSetupSize(object);
                        if (position != NULL && atSetupSize != 0) {
                            ComputePointAlongLine(&linePoint, &kartPosition, position);
                            cellPosition = linePoint;
                            if (ComputeRaceHudSubScreenPosition(
                                    &cellPosition, &gRaceHudSubScreenKarts->mCells->mCells[cellCount].mDrawPos,
                                    objectScale, 0, 1) != FALSE) {
                                switch (object->mKind) {
                                    case ITEM_OBJECT_KIND_KOURA_G:
                                        gRaceHudSubScreenKarts->mCells->mCells[cellCount].mCell =
                                            GetRaceSNcerEntry(0x4c);
                                        break;
                                    case ITEM_OBJECT_KIND_KOURA_R:
                                        gRaceHudSubScreenKarts->mCells->mCells[cellCount].mCell =
                                            GetRaceSNcerEntry(0x4d);
                                        break;
                                    case ITEM_OBJECT_KIND_BANANA:
                                        gRaceHudSubScreenKarts->mCells->mCells[cellCount].mCell =
                                            GetRaceSNcerEntry(0x4b);
                                        break;
                                    case ITEM_OBJECT_KIND_KOURA_W:
                                        gRaceHudSubScreenKarts->mCells->mCells[cellCount].mCell =
                                            GetRaceSNcerEntry(0x56);
                                        break;
                                    case ITEM_OBJECT_KIND_BOMB:
                                        gRaceHudSubScreenKarts->mCells->mCells[cellCount].mCell =
                                            GetRaceSNcerEntry(0x55);
                                        break;
                                    case ITEM_OBJECT_KIND_F_BOX:
                                        gRaceHudSubScreenKarts->mCells->mCells[cellCount].mCell =
                                            GetRaceSNcerEntry(0x54);
                                        break;
                                    case ITEM_OBJECT_KIND_BOUNCING_ITEM_BOX:
                                        gRaceHudSubScreenKarts->mCells->mCells[cellCount].mCell =
                                            GetRaceSNcerEntry(0x4e);
                                        break;
                                    default:
                                        gRaceHudSubScreenKarts->mCells->mCells[cellCount].mCell =
                                            GetRaceSNcerEntry(0x4c);
                                        break;
                                }
                                gRaceHudSubScreenKarts->mCells->mCells[cellCount].mPriority =
                                    IsPositionOutsideBox(&cellPosition) != 0 ? RACE_HUD_PRIORITY_MIDDLE
                                                                             : RACE_HUD_PRIORITY_BACK;
                                gRaceHudSubScreenKarts->mCells->mCells[cellCount].mXlu =
                                    (object->mFlags & ITEM_OBJECT_FLAG_COURSE_HIT_ATTRIBUTE) != 0 ? 1 : 0;
                                cellCount++;
                            }
                        }
                    }
                    gRaceHudSubScreenKarts->mCells->mCellCount = cellCount;
                }
            }
            break;
    }
    for (kartIndex = 0; kartIndex < (u32) gRaceSetup->mKartCount; kartIndex++) {
        if (GetKartItemEffect(kartIndex) == 1) {
            gRaceHudSubScreenKarts->mStarFrames[kartIndex]++;
        } else {
            gRaceHudSubScreenKarts->mStarFrames[kartIndex] = 0;
        }
        if (kartIndex != GetFollowedKartOrEntryIndex() &&
            (GetKart(kartIndex)->mEntryFlags & KART_ENTRY_TERESA_OR_PARKED) != 0) {
            gRaceHudSubScreenKarts->mSpriteHidden[kartIndex] = 1;
        } else {
            gRaceHudSubScreenKarts->mSpriteHidden[kartIndex] = 0;
        }
    }
    for (kartIndex = 0; kartIndex < (u32) gRaceSetup->mKartCount; kartIndex++) {
        if (gRaceHudSubScreenKarts->mXlu[kartIndex] == 0) {
            sortKeys[kartIndex] -= 0x20;
        }
        if (kartIndex == GetFollowedKartOrEntryIndex()) {
            sortKeys[kartIndex] -= 0x10;
        }
    }
    if (gRaceSetup->mMode == MODE_TIME_ATTACK) {
        return;
    }
    SortIndicesByKey(gRaceHudSubScreenKarts->mDrawOrder, sortKeys, gRaceSetup->mKartCount);
}

static inline void AddRaceHudSubScreenCellOams(RaceHudOamBuffer *oamBuffer, NNSG2dCellDataWithBR *cell, MtxFx22 *matrix,
                                               s32 screenX, s32 screenY, u16 matrixIndex, s32 xlu, s32 priority) {
    s32 position[2];
    s32 oamIndex;
    RaceHudOamBits *oam;

    oamIndex = oamBuffer->mOamCount;
    position[0] = TO_FIXED12(screenX);
    position[1] = TO_FIXED12(screenY);
    oam = &oamBuffer->mOamBits[oamIndex];
    oamBuffer->mOamCount +=
        NNS_G2dMakeCellToOams(&oamBuffer->mOams[oamIndex], 0x80 - oamIndex, cell, matrix, position, matrixIndex, 1);
    for (; oamIndex < oamBuffer->mOamCount; oamIndex++) {
        if (xlu != -1) {
            oam->mObjMode = xlu;
        }
        if (priority != -1) {
            oam->mPriority = priority;
        }
        oam++;
    }
}

static inline void AddRaceHudSubScreenCellOamsNoMatrix(RaceHudOamBuffer *oamBuffer, NNSG2dCellDataWithBR *cell,
                                                       s32 screenX, s32 screenY) {
    s32 position[2];
    s32 oamIndex;

    position[0] = TO_FIXED12(screenX);
    position[1] = TO_FIXED12(screenY);
    oamIndex = oamBuffer->mOamCount;
    oamBuffer->mOamCount +=
        NNS_G2dMakeCellToOams(&oamBuffer->mOams[oamIndex], 0x80 - oamIndex, cell, NULL, position, 0, 1);
}

static inline void AddRaceHudSubScreenKartStarCells(RaceHudOamBuffer *oamBuffer, s32 kartIndex, s32 frame) {
    s32 starIndex;
    s32 angle;
    s32 offsetX;
    s32 offsetY;
    NNSG2dCellDataWithBR *cell;

    for (starIndex = 0; starIndex < 3; starIndex++) {
        angle = (u16) (((frame + 12 - starIndex * 4) << 16) / 64);
        offsetX = (s16) COS_OF_ANGLE(angle) * 11 >> 12;
        offsetY = (s16) SIN_OF_ANGLE(angle) * 11 >> 12;
        cell = GetRaceSNcerEntry(frame % 12 < 6 ? 93 + starIndex * 2 : 94 + starIndex * 2);
        AddRaceHudSubScreenCellOamsNoMatrix(oamBuffer, cell,
                                            gRaceHudSubScreenKarts->mScreenPos[kartIndex].mFirst + offsetX,
                                            gRaceHudSubScreenKarts->mScreenPos[kartIndex].mSecond + offsetY);
    }
}

void DrawRaceHudSubScreenKarts(RaceHudOamBuffer *oamBuffer) {
    s32 kartIndex;
    s32 translucent;
    NNSG2dCellDataWithBR *cell;
    MtxFx22 rotationMatrix;
    MtxFx22 rotationMatrix2;
    s32 drawOrderIndex;
    s32 priority;
    s32 translucent2;
    u16 firstPassRotationSlot;
    u16 angle;
    s32 minDrawValue;
    u16 priorityPassRotationSlot;
    s32 screenX;
    s32 screenY;

    switch (GetRaceHudSubScreenState()) {
        case RACE_HUD_SUB_SCREEN_KART_ICONS:
            for (drawOrderIndex = 0; drawOrderIndex < gRaceSetup->mKartCount; drawOrderIndex++) {
                kartIndex = gRaceHudSubScreenKarts->mDrawOrder[drawOrderIndex];
                if (gRaceHudSubScreenKarts->mVisible[kartIndex] != 0) {
                    translucent = gRaceHudSubScreenKarts->mXlu[kartIndex];
                    if (gRaceHudSubScreenKarts->mSpriteHidden[kartIndex] == 0) {
                        if (gRaceHudSubScreenKarts->mScale[kartIndex].y != 0x1000 ||
                            gRaceHudSubScreenKarts->mNonNormalStateFrames[kartIndex] != 0) {
                            firstPassRotationSlot = AllocOamMatrixIndex(oamBuffer);
                            Matrix2x2RotationReciprocalScale(&rotationMatrix,
                                                             gRaceHudSubScreenKarts->mScale[kartIndex].y,
                                                             gRaceHudSubScreenKarts->mAngle[kartIndex]);
                            if (GetKartItemEffect((u16) kartIndex) == 3) {
                                cell = GetRaceSNcerEntry(0x10);
                            } else {
                                cell = GetRaceSNcerEntry(kartIndex);
                            }
                            AddRaceHudSubScreenCellOams(oamBuffer, cell, &rotationMatrix,
                                                        gRaceHudSubScreenKarts->mScreenPos[kartIndex].mFirst,
                                                        gRaceHudSubScreenKarts->mScreenPos[kartIndex].mSecond,
                                                        firstPassRotationSlot, translucent != 0 ? 1 : -1, -1);
                            oamBuffer->mMatrices[firstPassRotationSlot].mPA = rotationMatrix.mElements[0] >> 4;
                            oamBuffer->mMatrices[firstPassRotationSlot].mPB = rotationMatrix.mElements[1] >> 4;
                            oamBuffer->mMatrices[firstPassRotationSlot].mPC = rotationMatrix.mElements[2] >> 4;
                            oamBuffer->mMatrices[firstPassRotationSlot].mPD = rotationMatrix.mElements[3] >> 4;
                        } else {
                            if (GetKartItemEffect((u16) kartIndex) == 3) {
                                cell = GetRaceSNcerEntry(0x10);
                            } else {
                                cell = GetRaceSNcerEntry(kartIndex);
                            }
                            AddRaceHudSubScreenCellOams(oamBuffer, cell, NULL,
                                                        gRaceHudSubScreenKarts->mScreenPos[kartIndex].mFirst,
                                                        gRaceHudSubScreenKarts->mScreenPos[kartIndex].mSecond, 0,
                                                        translucent != 0 ? 1 : -1, -1);
                        }
                    }
                    if (gRaceHudSubScreenKarts->mStarFrames[kartIndex] != 0) {
                        AddRaceHudSubScreenKartStarCells(oamBuffer, kartIndex,
                                                         gRaceHudSubScreenKarts->mStarFrames[kartIndex]);
                    }
                }
            }
            break;
        case RACE_HUD_SUB_SCREEN_MAP_TURNING:
        case RACE_HUD_SUB_SCREEN_MAP_FIXED_SCROLL:
        case RACE_HUD_SUB_SCREEN_MAP_VIEW:
            minDrawValue = GetRaceHudSubScreenMinDrawValue();
            for (drawOrderIndex = 0; drawOrderIndex < gRaceSetup->mKartCount; drawOrderIndex++) {
                kartIndex = gRaceHudSubScreenKarts->mDrawOrder[drawOrderIndex];
                priority = gRaceHudSubScreenKarts->mPriority[kartIndex];
                if (gRaceHudSubScreenKarts->mVisible[kartIndex] != 0 && minDrawValue <= priority) {
                    if (gRaceHudSubScreenKarts->mSpriteHidden[kartIndex] == 0) {
                        screenX = gRaceHudSubScreenKarts->mScreenPos[kartIndex].mFirst;
                        screenY = gRaceHudSubScreenKarts->mScreenPos[kartIndex].mSecond;
                        translucent2 = gRaceHudSubScreenKarts->mXlu[kartIndex];
                        if (gRaceHudSubScreenKarts->mScale[kartIndex].y != 0x1000 ||
                            gRaceHudSubScreenKarts->mNonNormalStateFrames[kartIndex] != 0) {
                            priorityPassRotationSlot = AllocOamMatrixIndex(oamBuffer);
                            if (gRaceHudSubScreenKarts->mNonNormalStateFrames[kartIndex] != 0) {
                                angle =
                                    gRaceHudSubScreenKarts->mAngle[kartIndex] + GetSubScreenAngleAndClearScrollTimer();
                            } else {
                                angle = 0;
                            }
                            Matrix2x2RotationReciprocalScale(&rotationMatrix2,
                                                             gRaceHudSubScreenKarts->mScale[kartIndex].y, angle);
                            if (GetKartItemEffect((u16) kartIndex) == 3) {
                                cell = GetRaceSNcerEntry(0x10);
                            } else {
                                cell = GetRaceSNcerEntry(kartIndex);
                            }
                            AddRaceHudSubScreenCellOams(oamBuffer, cell, &rotationMatrix2, screenX, screenY,
                                                        priorityPassRotationSlot, translucent2 != 0 ? 1 : -1, priority);
                            oamBuffer->mMatrices[priorityPassRotationSlot].mPA = rotationMatrix2.mElements[0] >> 4;
                            oamBuffer->mMatrices[priorityPassRotationSlot].mPB = rotationMatrix2.mElements[1] >> 4;
                            oamBuffer->mMatrices[priorityPassRotationSlot].mPC = rotationMatrix2.mElements[2] >> 4;
                            oamBuffer->mMatrices[priorityPassRotationSlot].mPD = rotationMatrix2.mElements[3] >> 4;
                        } else {
                            if (GetKartItemEffect((u16) kartIndex) == 3) {
                                cell = GetRaceSNcerEntry(0x10);
                            } else {
                                cell = GetRaceSNcerEntry(kartIndex);
                            }
                            AddRaceHudSubScreenCellOams(oamBuffer, cell, NULL, screenX, screenY, 0,
                                                        translucent2 != 0 ? 1 : -1, priority);
                        }
                    }
                    if (gRaceHudSubScreenKarts->mStarFrames[kartIndex] != 0) {
                        AddRaceHudSubScreenKartStarCells(oamBuffer, kartIndex,
                                                         gRaceHudSubScreenKarts->mStarFrames[kartIndex]);
                    }
                }
            }
            DrawRaceHudSubScreenCells(oamBuffer, gRaceHudSubScreenKarts->mCells, 0);
            break;
    }
}

BOOL CreateRaceHudSubScreenSecondHand(void) {
    MapObjectList *kindEntry;
    s32 objectCount;

    kindEntry = FindMapObjectKindDrawList0(MAP_OBJECT_KIND_SECOND_HAND);
    if (kindEntry == NULL) {
        return FALSE;
    }
    objectCount = CountMapObjectsBeforePooledTail(kindEntry);
    if (objectCount == 0) {
        return FALSE;
    }
    gRaceHudSubScreenSecondHand = HeapAlloc(GetHeap(GetCurrentHeapCall()), sizeof(*gRaceHudSubScreenSecondHand));
    gRaceHudSubScreenSecondHand->mObjects = RaceHudSubScreenGetMapObjects(kindEntry);
    gRaceHudSubScreenSecondHand->mCreatedObjectCount = objectCount;
    gRaceHudSubScreenSecondHand->mObjectCount = objectCount;
    return TRUE;
}

void ClearRaceHudSubScreenSecondHandPointer(void) {
    gRaceHudSubScreenSecondHand = NULL;
}

void UpdateRaceHudSubScreenSecondHand(void) {
    s32 objectIndex;
    u32 scale;
    Vehicle *object;
    s32 extentZ;
    Vec3 *position;
    s32 deltaX;
    s32 deltaZ;
    Vec3 endPosition;

    scale = GetRaceHudSubScreenScale();
    for (objectIndex = 0; objectIndex < gRaceHudSubScreenSecondHand->mObjectCount; objectIndex++) {
        object = gRaceHudSubScreenSecondHand->mObjects[objectIndex];
        extentZ = object->mMapObject.mExtent.z;
        position = &object->mMapObject.mPos;
        deltaX = MUL_FIXED12_NO_ROUND(object->mMapObject.mMatrix.mRows[2].x, extentZ);
        deltaZ = MUL_FIXED12_NO_ROUND(object->mMapObject.mMatrix.mRows[2].z, extentZ);
        if (gRaceSetup->mMirrorMode != 0) {
            gRaceHudSubScreenSecondHand->mAngles[objectIndex] = FX_Atan2Idx(-deltaZ, deltaX) + 0x8000;
        } else {
            gRaceHudSubScreenSecondHand->mAngles[objectIndex] = FX_Atan2Idx(deltaZ, deltaX);
        }
        ComputeRaceHudSubScreenPosition(position, &gRaceHudSubScreenSecondHand->mDrawPositions[objectIndex], scale, 0,
                                        0);
        endPosition.x = position->x + deltaX;
        endPosition.z = position->z + deltaZ;
        ComputeRaceHudSubScreenPosition(&endPosition, &gRaceHudSubScreenSecondHand->mEndPositions[objectIndex], scale,
                                        0, 0);
    }
}

void DrawRaceHudSubScreenSecondHand(RaceHudOamBuffer *oamBuffer) {
    NNSG2dCellDataWithBR *cell;
    MtxFx22 rotationMatrix;
    u32 minDrawValue;
    u16 rotationSlot0;
    u16 rotationSlot1;
    u16 rotationSlot2;
    u16 angle0;
    s32 screenX0;
    s32 screenY0;
    s32 trailDeltaX0;
    s32 trailDeltaY0;
    s32 trailSumX0;
    s32 trailSumY0;
    s32 trailStep0;
    u16 angle2;
    s32 screenX2;
    s32 screenY2;
    s32 trailDeltaX2;
    s32 trailDeltaY2;
    s32 trailSumX2;
    s32 trailSumY2;
    s32 trailStep2;
    u16 angle1;
    s32 screenX1;
    s32 screenY1;
    s32 trailDeltaX1;
    s32 trailDeltaY1;
    s32 trailSumX1;
    s32 trailSumY1;
    s32 trailStep1;
    s32 endPosition0[2];
    s32 middlePosition0[2];
    s32 drawPosition0[2];
    s32 endPosition2[2];
    s32 middlePosition2[2];
    s32 drawPosition2[2];
    s32 endPosition1[2];
    s32 middlePosition1[2];
    s32 drawPosition1[2];

    minDrawValue = GetRaceHudSubScreenMinDrawValue();
    if (gRaceHudSubScreenSecondHand->mCreatedObjectCount <= 0) {
        return;
    }
    if (minDrawValue == 0) {
        if (gRaceSetup->mMirrorMode != 0) {
            angle0 = gRaceHudSubScreenSecondHand->mAngles[0] - GetSubScreenAngleAndClearScrollTimer();
        } else {
            angle0 = gRaceHudSubScreenSecondHand->mAngles[0] + GetSubScreenAngleAndClearScrollTimer();
        }
        rotationSlot0 = AllocOamMatrixIndex(oamBuffer);
        Matrix2x2Rotation(&rotationMatrix, angle0);
        screenX0 = gRaceHudSubScreenSecondHand->mEndPositions[0].mFirst;
        screenY0 = gRaceHudSubScreenSecondHand->mEndPositions[0].mSecond;
        if (screenX0 > -32 && screenX0 < 288 && screenY0 > -32 && screenY0 < 224) {
            cell = GetRaceSNcerEntry(156);
            endPosition0[0] = TO_FIXED12(screenX0);
            endPosition0[1] = TO_FIXED12(screenY0);
            oamBuffer->mOamCount +=
                NNS_G2dMakeCellToOams(&oamBuffer->mOams[oamBuffer->mOamCount], 0x80 - oamBuffer->mOamCount, cell,
                                      &rotationMatrix, endPosition0, rotationSlot0, 1);
        }
        trailDeltaX0 = gRaceHudSubScreenSecondHand->mDrawPositions[0].mFirst -
                       gRaceHudSubScreenSecondHand->mEndPositions[0].mFirst;
        trailDeltaY0 = gRaceHudSubScreenSecondHand->mDrawPositions[0].mSecond -
                       gRaceHudSubScreenSecondHand->mEndPositions[0].mSecond;
        for (trailStep0 = 0, trailSumX0 = 0, trailSumY0 = 0; trailStep0 < 3; trailStep0++) {
            screenX0 = gRaceHudSubScreenSecondHand->mEndPositions[0].mFirst + (trailSumX0 + trailDeltaX0) / 4;
            screenY0 = gRaceHudSubScreenSecondHand->mEndPositions[0].mSecond + (trailSumY0 + trailDeltaY0) / 4;
            if (screenX0 > -32 && screenX0 < 288 && screenY0 > -32 && screenY0 < 224) {
                cell = GetRaceSNcerEntry(155);
                middlePosition0[0] = TO_FIXED12(screenX0);
                middlePosition0[1] = TO_FIXED12(screenY0);
                oamBuffer->mOamCount +=
                    NNS_G2dMakeCellToOams(&oamBuffer->mOams[oamBuffer->mOamCount], 0x80 - oamBuffer->mOamCount, cell,
                                          &rotationMatrix, middlePosition0, rotationSlot0, 1);
            }
            trailSumX0 += trailDeltaX0;
            trailSumY0 += trailDeltaY0;
        }
        screenX0 = gRaceHudSubScreenSecondHand->mDrawPositions[0].mFirst;
        screenY0 = gRaceHudSubScreenSecondHand->mDrawPositions[0].mSecond;
        if (screenX0 > -32 && screenX0 < 288 && screenY0 > -32 && screenY0 < 224) {
            cell = GetRaceSNcerEntry(154);
            drawPosition0[0] = TO_FIXED12(screenX0);
            drawPosition0[1] = TO_FIXED12(screenY0);
            oamBuffer->mOamCount +=
                NNS_G2dMakeCellToOams(&oamBuffer->mOams[oamBuffer->mOamCount], 0x80 - oamBuffer->mOamCount, cell,
                                      &rotationMatrix, drawPosition0, rotationSlot0, 1);
        }
        oamBuffer->mMatrices[rotationSlot0].mPA = rotationMatrix.mElements[0] >> 4;
        oamBuffer->mMatrices[rotationSlot0].mPB = rotationMatrix.mElements[1] >> 4;
        oamBuffer->mMatrices[rotationSlot0].mPC = rotationMatrix.mElements[2] >> 4;
        oamBuffer->mMatrices[rotationSlot0].mPD = rotationMatrix.mElements[3] >> 4;
    }
    if (gRaceHudSubScreenSecondHand->mObjectCount == 3 && minDrawValue == 0) {
        if (gRaceSetup->mMirrorMode != 0) {
            angle2 = gRaceHudSubScreenSecondHand->mAngles[2] - GetSubScreenAngleAndClearScrollTimer();
        } else {
            angle2 = gRaceHudSubScreenSecondHand->mAngles[2] + GetSubScreenAngleAndClearScrollTimer();
        }
        rotationSlot2 = AllocOamMatrixIndex(oamBuffer);
        Matrix2x2Rotation(&rotationMatrix, angle2);
        screenX2 = gRaceHudSubScreenSecondHand->mEndPositions[2].mFirst;
        screenY2 = gRaceHudSubScreenSecondHand->mEndPositions[2].mSecond;
        if (screenX2 > -32 && screenX2 < 288 && screenY2 > -32 && screenY2 < 224) {
            cell = GetRaceSNcerEntry(156);
            endPosition2[0] = TO_FIXED12(screenX2);
            endPosition2[1] = TO_FIXED12(screenY2);
            oamBuffer->mOamCount +=
                NNS_G2dMakeCellToOams(&oamBuffer->mOams[oamBuffer->mOamCount], 0x80 - oamBuffer->mOamCount, cell,
                                      &rotationMatrix, endPosition2, rotationSlot2, 1);
        }
        trailDeltaX2 = gRaceHudSubScreenSecondHand->mDrawPositions[2].mFirst -
                       gRaceHudSubScreenSecondHand->mEndPositions[2].mFirst;
        trailDeltaY2 = gRaceHudSubScreenSecondHand->mDrawPositions[2].mSecond -
                       gRaceHudSubScreenSecondHand->mEndPositions[2].mSecond;
        for (trailStep2 = 0, trailSumX2 = 0, trailSumY2 = 0; trailStep2 < 2; trailStep2++) {
            screenX2 = gRaceHudSubScreenSecondHand->mEndPositions[2].mFirst + (trailSumX2 + trailDeltaX2) / 3;
            screenY2 = gRaceHudSubScreenSecondHand->mEndPositions[2].mSecond + (trailSumY2 + trailDeltaY2) / 3;
            if (screenX2 > -32 && screenX2 < 288 && screenY2 > -32 && screenY2 < 224) {
                cell = GetRaceSNcerEntry(155);
                middlePosition2[0] = TO_FIXED12(screenX2);
                middlePosition2[1] = TO_FIXED12(screenY2);
                oamBuffer->mOamCount +=
                    NNS_G2dMakeCellToOams(&oamBuffer->mOams[oamBuffer->mOamCount], 0x80 - oamBuffer->mOamCount, cell,
                                          &rotationMatrix, middlePosition2, rotationSlot2, 1);
            }
            trailSumX2 += trailDeltaX2;
            trailSumY2 += trailDeltaY2;
        }
        screenX2 = gRaceHudSubScreenSecondHand->mDrawPositions[2].mFirst;
        screenY2 = gRaceHudSubScreenSecondHand->mDrawPositions[2].mSecond;
        if (screenX2 > -32 && screenX2 < 288 && screenY2 > -32 && screenY2 < 224) {
            cell = GetRaceSNcerEntry(154);
            drawPosition2[0] = TO_FIXED12(screenX2);
            drawPosition2[1] = TO_FIXED12(screenY2);
            oamBuffer->mOamCount +=
                NNS_G2dMakeCellToOams(&oamBuffer->mOams[oamBuffer->mOamCount], 0x80 - oamBuffer->mOamCount, cell,
                                      &rotationMatrix, drawPosition2, rotationSlot2, 1);
        }
        oamBuffer->mMatrices[rotationSlot2].mPA = rotationMatrix.mElements[0] >> 4;
        oamBuffer->mMatrices[rotationSlot2].mPB = rotationMatrix.mElements[1] >> 4;
        oamBuffer->mMatrices[rotationSlot2].mPC = rotationMatrix.mElements[2] >> 4;
        oamBuffer->mMatrices[rotationSlot2].mPD = rotationMatrix.mElements[3] >> 4;
    }
    if (gRaceSetup->mMirrorMode != 0) {
        angle1 = gRaceHudSubScreenSecondHand->mAngles[1] - GetSubScreenAngleAndClearScrollTimer();
    } else {
        angle1 = gRaceHudSubScreenSecondHand->mAngles[1] + GetSubScreenAngleAndClearScrollTimer();
    }
    rotationSlot1 = AllocOamMatrixIndex(oamBuffer);
    Matrix2x2Rotation(&rotationMatrix, angle1);
    screenX1 = gRaceHudSubScreenSecondHand->mEndPositions[1].mFirst;
    screenY1 = gRaceHudSubScreenSecondHand->mEndPositions[1].mSecond;
    if (screenX1 > -16 && screenX1 < 272 && screenY1 > -16 && screenY1 < 208) {
        cell = GetRaceSNcerEntry(159);
        endPosition1[0] = TO_FIXED12(screenX1);
        endPosition1[1] = TO_FIXED12(screenY1);
        oamBuffer->mOamCount +=
            NNS_G2dMakeCellToOams(&oamBuffer->mOams[oamBuffer->mOamCount], 0x80 - oamBuffer->mOamCount, cell,
                                  &rotationMatrix, endPosition1, rotationSlot1, 1);
    }
    trailDeltaX1 =
        gRaceHudSubScreenSecondHand->mDrawPositions[1].mFirst - gRaceHudSubScreenSecondHand->mEndPositions[1].mFirst;
    trailDeltaY1 =
        gRaceHudSubScreenSecondHand->mDrawPositions[1].mSecond - gRaceHudSubScreenSecondHand->mEndPositions[1].mSecond;
    for (trailStep1 = 0, trailSumX1 = 0, trailSumY1 = 0; trailStep1 < 3; trailStep1++) {
        screenX1 = gRaceHudSubScreenSecondHand->mEndPositions[1].mFirst + (trailSumX1 + trailDeltaX1) / 4;
        screenY1 = gRaceHudSubScreenSecondHand->mEndPositions[1].mSecond + (trailSumY1 + trailDeltaY1) / 4;
        if (screenX1 > -16 && screenX1 < 272 && screenY1 > -16 && screenY1 < 208) {
            cell = GetRaceSNcerEntry(158);
            middlePosition1[0] = TO_FIXED12(screenX1);
            middlePosition1[1] = TO_FIXED12(screenY1);
            oamBuffer->mOamCount +=
                NNS_G2dMakeCellToOams(&oamBuffer->mOams[oamBuffer->mOamCount], 0x80 - oamBuffer->mOamCount, cell,
                                      &rotationMatrix, middlePosition1, rotationSlot1, 1);
        }
        trailSumX1 += trailDeltaX1;
        trailSumY1 += trailDeltaY1;
    }
    screenX1 = gRaceHudSubScreenSecondHand->mDrawPositions[1].mFirst;
    screenY1 = gRaceHudSubScreenSecondHand->mDrawPositions[1].mSecond;
    if (screenX1 > -16 && screenX1 < 272 && screenY1 > -16 && screenY1 < 208) {
        cell = GetRaceSNcerEntry(157);
        drawPosition1[0] = TO_FIXED12(screenX1);
        drawPosition1[1] = TO_FIXED12(screenY1);
        oamBuffer->mOamCount +=
            NNS_G2dMakeCellToOams(&oamBuffer->mOams[oamBuffer->mOamCount], 0x80 - oamBuffer->mOamCount, cell,
                                  &rotationMatrix, drawPosition1, rotationSlot1, 1);
    }
    oamBuffer->mMatrices[rotationSlot1].mPA = rotationMatrix.mElements[0] >> 4;
    oamBuffer->mMatrices[rotationSlot1].mPB = rotationMatrix.mElements[1] >> 4;
    oamBuffer->mMatrices[rotationSlot1].mPC = rotationMatrix.mElements[2] >> 4;
    oamBuffer->mMatrices[rotationSlot1].mPD = rotationMatrix.mElements[3] >> 4;
}

BOOL CreateRaceHudSubScreenCarCells(void) {
    u16 kinds[3] = {MAP_OBJECT_KIND_CAR_A, MAP_OBJECT_KIND_BUS_A, MAP_OBJECT_KIND_TRUCK_A};
    u16 kindIndex;
    u16 kind;

    for (kindIndex = 0; kindIndex < 3; kindIndex++) {
        kind = kinds[kindIndex];
        if (FindMapObjectKindDrawList0(kind) != NULL) {
            return CreateRaceHudSubScreenCells(&gRaceHudSubScreenCarCells, kind);
        }
    }
    return FALSE;
}

void ClearRaceHudSubScreenCarCells(void) {
    ClearRaceHudSubScreenCells(&gRaceHudSubScreenCarCells);
}

void UpdateRaceHudSubScreenCarCells(void) {
    s32 objectIndex;
    s32 cellCount;
    Vehicle *object;
    Vec3 *position;
    u32 scale;
    u16 kind;
    u16 angle;

    cellCount = 0;
    scale = GetRaceHudSubScreenScale();
    for (objectIndex = 0; objectIndex < gRaceHudSubScreenCarCells->mObjectCount; objectIndex++) {
        object = (Vehicle *) gRaceHudSubScreenCarCells->mObjects[objectIndex];
        position = &object->mMapObject.mPos;
        if (ComputeRaceHudSubScreenPosition(&object->mMapObject.mPos,
                                            &gRaceHudSubScreenCarCells->mCells[cellCount].mDrawPos, scale, 1,
                                            1) != FALSE) {
            kind = object->mMapObject.mKind;
            angle = object->mMapObject.mAngle;
            switch (kind) {
                case MAP_OBJECT_KIND_CAR_A:
                    gRaceHudSubScreenCarCells->mCells[cellCount].mCell =
                        GetRaceSNcerEntry(object->mAnimationFrame + 0x95);
                    break;
                case MAP_OBJECT_KIND_BUS_A:
                    gRaceHudSubScreenCarCells->mCells[cellCount].mCell = GetRaceSNcerEntry(0x93);
                    break;
                case MAP_OBJECT_KIND_TRUCK_A:
                    gRaceHudSubScreenCarCells->mCells[cellCount].mCell = GetRaceSNcerEntry(0x94);
                    break;
            }
            gRaceHudSubScreenCarCells->mCells[cellCount].mPriority =
                IsPositionOutsideBox((Vec3 *) &position) != 0 ? RACE_HUD_PRIORITY_MIDDLE : RACE_HUD_PRIORITY_BACK;
            gRaceHudSubScreenCarCells->mCells[cellCount].mAngle = angle;
            cellCount++;
        }
    }
    gRaceHudSubScreenCarCells->mCellCount = cellCount;
}

void DrawRaceHudSubScreenCarCells(RaceHudOamBuffer *oamBuffer) {
    DrawRaceHudSubScreenCells(oamBuffer, gRaceHudSubScreenCarCells, 1);
}

s32 CreateRaceHudSubScreenKoopaBlockCells(void) {
    return CreateRaceHudSubScreenCells(&gRaceHudSubScreenKoopaBlockCells, MAP_OBJECT_KIND_KOOPA_BLOCK);
}

void ClearRaceHudSubScreenKoopaBlockCells(void) {
    ClearRaceHudSubScreenCells(&gRaceHudSubScreenKoopaBlockCells);
}

void UpdateRaceHudSubScreenKoopaBlockCells(void) {
    s32 objectIndex;
    s32 cellCount;
    u32 scale;

    cellCount = 0;
    scale = GetRaceHudSubScreenScale();
    for (objectIndex = 0; objectIndex < gRaceHudSubScreenKoopaBlockCells->mObjectCount; objectIndex++) {
        if (ComputeRaceHudSubScreenPosition(&gRaceHudSubScreenKoopaBlockCells->mObjects[objectIndex]->mPos,
                                            &gRaceHudSubScreenKoopaBlockCells->mCells[cellCount].mDrawPos, scale, 1,
                                            0) != FALSE) {
            gRaceHudSubScreenKoopaBlockCells->mCells[cellCount].mCell = GetRaceSNcerEntry(0x25);
            gRaceHudSubScreenKoopaBlockCells->mCells[cellCount].mPriority = RACE_HUD_PRIORITY_MIDDLE;
            cellCount++;
        }
    }
    gRaceHudSubScreenKoopaBlockCells->mCellCount = cellCount;
}

void DrawRaceHudSubScreenKoopaBlockCells(RaceHudOamBuffer *oamBuffer) {
    DrawRaceHudSubScreenCells(oamBuffer, gRaceHudSubScreenKoopaBlockCells, 0);
}

s32 CreateRaceHudSubScreenChoropuCells(void) {
    return CreateRaceHudSubScreenCells(&gRaceHudSubScreenChoropuCells, MAP_OBJECT_KIND_CHOROPU);
}

void ClearRaceHudSubScreenChoropuCells(void) {
    ClearRaceHudSubScreenCells(&gRaceHudSubScreenChoropuCells);
}

void UpdateRaceHudSubScreenChoropuCells(void) {
    s32 objectIndex;
    s32 cellCount;
    MapObject *object;
    u32 scale;
    s32 height;
    s32 isPositiveHeight;

    cellCount = 0;
    scale = GetRaceHudSubScreenScale();
    for (objectIndex = 0; objectIndex < gRaceHudSubScreenChoropuCells->mObjectCount; objectIndex++) {
        if (IsRaceHudSubScreenPairNearCenter(&gRaceHudSubScreenChoropuCells->mObjectPairs[objectIndex]) != FALSE) {
            object = gRaceHudSubScreenChoropuCells->mObjects[objectIndex];
            if (ComputeRaceHudSubScreenPosition(
                    &object->mPos, &gRaceHudSubScreenChoropuCells->mCells[cellCount].mDrawPos, scale, 0, 0) != FALSE) {
                height = object->mPos.y - ((Choropu *) object)->mInitialY;
                if (height >= -0x9000) {
                    isPositiveHeight = height > 0 ? 1 : 0;
                    gRaceHudSubScreenChoropuCells->mCells[cellCount].mCell =
                        GetRaceSNcerEntry(isPositiveHeight != 0 ? 0xa7 : 0xa8);
                    gRaceHudSubScreenChoropuCells->mCells[cellCount].mPriority =
                        isPositiveHeight != 0 ? RACE_HUD_PRIORITY_FRONT : RACE_HUD_PRIORITY_MIDDLE;
                    gRaceHudSubScreenChoropuCells->mCells[cellCount + 1].mDrawPos =
                        gRaceHudSubScreenChoropuCells->mCells[cellCount].mDrawPos;
                    gRaceHudSubScreenChoropuCells->mCells[cellCount + 1].mCell = GetRaceSNcerEntry(0xa9);
                    gRaceHudSubScreenChoropuCells->mCells[cellCount + 1].mPriority = RACE_HUD_PRIORITY_MIDDLE;
                    cellCount += 2;
                    gRaceHudSubScreenChoropuCells->mCells[cellCount - 2].mDrawPos.mSecond -= height >> 14;
                } else {
                    gRaceHudSubScreenChoropuCells->mCells[cellCount].mCell = GetRaceSNcerEntry(0xa9);
                    gRaceHudSubScreenChoropuCells->mCells[cellCount].mPriority = RACE_HUD_PRIORITY_MIDDLE;
                    cellCount++;
                }
            }
        }
    }
    gRaceHudSubScreenChoropuCells->mCellCount = cellCount;
}

void DrawRaceHudSubScreenChoropuCells(RaceHudOamBuffer *oamBuffer) {
    DrawRaceHudSubScreenCells(oamBuffer, gRaceHudSubScreenChoropuCells, 0);
}

s32 CreateRaceHudSubScreenPukupukuCells(void) {
    return CreateRaceHudSubScreenCells(&gRaceHudSubScreenPukupukuCells, MAP_OBJECT_KIND_PUKUPUKU);
}

void ClearRaceHudSubScreenPukupukuCells(void) {
    ClearRaceHudSubScreenCells(&gRaceHudSubScreenPukupukuCells);
}

void UpdateRaceHudSubScreenPukupukuCells(void) {
    s32 objectIndex;
    s32 cellCount;
    MapObject *object;
    u32 scale;

    cellCount = 0;
    scale = GetRaceHudSubScreenScale();
    for (objectIndex = 0; objectIndex < gRaceHudSubScreenPukupukuCells->mObjectCount; objectIndex++) {
        if (IsRaceHudSubScreenPairNearCenter(&gRaceHudSubScreenPukupukuCells->mObjectPairs[objectIndex]) != FALSE) {
            object = gRaceHudSubScreenPukupukuCells->mObjects[objectIndex];
            if ((object->mFlags & MAP_OBJECT_FLAG_INVISIBLE) == 0) {
                if (ComputeRaceHudSubScreenPosition(&object->mPos,
                                                    &gRaceHudSubScreenPukupukuCells->mCells[cellCount].mDrawPos, scale,
                                                    0, 0) != FALSE) {
                    gRaceHudSubScreenPukupukuCells->mCells[cellCount].mCell = GetRaceSNcerEntry(0x89);
                    gRaceHudSubScreenPukupukuCells->mCells[cellCount].mPriority = RACE_HUD_PRIORITY_MIDDLE;
                    cellCount++;
                }
            }
        }
    }
    gRaceHudSubScreenPukupukuCells->mCellCount = cellCount;
}

void DrawRaceHudSubScreenPukupukuCells(RaceHudOamBuffer *oamBuffer) {
    DrawRaceHudSubScreenCells(oamBuffer, gRaceHudSubScreenPukupukuCells, 0);
}

s32 CreateRaceHudSubScreenMoveTreeCells(void) {
    return CreateRaceHudSubScreenCells(&gRaceHudSubScreenMoveTreeCells, MAP_OBJECT_KIND_MOVE_TREE);
}

void ClearRaceHudSubScreenMoveTreeCells(void) {
    ClearRaceHudSubScreenCells(&gRaceHudSubScreenMoveTreeCells);
}

void UpdateRaceHudSubScreenMoveTreeCells(void) {
    s32 objectIndex;
    s32 cellCount;
    u32 scale;

    cellCount = 0;
    scale = GetRaceHudSubScreenScale();
    for (objectIndex = 0; objectIndex < gRaceHudSubScreenMoveTreeCells->mObjectCount; objectIndex++) {
        if (ComputeRaceHudSubScreenPosition(&gRaceHudSubScreenMoveTreeCells->mObjects[objectIndex]->mPos,
                                            &gRaceHudSubScreenMoveTreeCells->mCells[cellCount].mDrawPos, scale, 1,
                                            1) != FALSE) {
            gRaceHudSubScreenMoveTreeCells->mCells[cellCount].mCell = GetRaceSNcerEntry(0x8b);
            gRaceHudSubScreenMoveTreeCells->mCells[cellCount].mPriority = RACE_HUD_PRIORITY_MIDDLE;
            cellCount++;
        }
    }
    gRaceHudSubScreenMoveTreeCells->mCellCount = cellCount;
}

void DrawRaceHudSubScreenMoveTreeCells(RaceHudOamBuffer *oamBuffer) {
    DrawRaceHudSubScreenCells(oamBuffer, gRaceHudSubScreenMoveTreeCells, 0);
}

s32 CreateRaceHudSubScreenSmanCells(void) {
    return CreateRaceHudSubScreenCells(&gRaceHudSubScreenSmanCells, MAP_OBJECT_KIND_SMAN);
}

void ClearRaceHudSubScreenSmanCells(void) {
    ClearRaceHudSubScreenCells(&gRaceHudSubScreenSmanCells);
}

void UpdateRaceHudSubScreenSmanCells(void) {
    s32 objectIndex;
    s32 cellCount;
    MapObject *object;
    u32 scale;

    cellCount = 0;
    scale = GetRaceHudSubScreenScale();
    for (objectIndex = 0; objectIndex < gRaceHudSubScreenSmanCells->mObjectCount; objectIndex++) {
        if (IsRaceHudSubScreenPairNearCenter(&gRaceHudSubScreenSmanCells->mObjectPairs[objectIndex]) != FALSE) {
            object = gRaceHudSubScreenSmanCells->mObjects[objectIndex];
            if ((object->mFlags & 1) == 0) {
                if (ComputeRaceHudSubScreenPosition(
                        &object->mPos, &gRaceHudSubScreenSmanCells->mCells[cellCount].mDrawPos, scale, 0, 0) != FALSE) {
                    gRaceHudSubScreenSmanCells->mCells[cellCount].mCell = GetRaceSNcerEntry(0x98);
                    gRaceHudSubScreenSmanCells->mCells[cellCount].mPriority = RACE_HUD_PRIORITY_MIDDLE;
                    cellCount++;
                }
            }
        }
    }
    gRaceHudSubScreenSmanCells->mCellCount = cellCount;
}

void DrawRaceHudSubScreenSmanCells(RaceHudOamBuffer *oamBuffer) {
    DrawRaceHudSubScreenCells(oamBuffer, gRaceHudSubScreenSmanCells, 0);
}

s32 CreateRaceHudSubScreenDossunCells(void) {
    return CreateRaceHudSubScreenCells(&gRaceHudSubScreenDossunCells, MAP_OBJECT_KIND_DOSSUN);
}

void ClearRaceHudSubScreenDossunCells(void) {
    ClearRaceHudSubScreenCells(&gRaceHudSubScreenDossunCells);
}

void UpdateRaceHudSubScreenDossunCells(void) {
    s32 objectIndex;
    s32 cellCount;
    MapObject *object;
    u32 scale;
    s32 offset;

    cellCount = 0;
    scale = GetRaceHudSubScreenScale();
    for (objectIndex = 0; objectIndex < gRaceHudSubScreenDossunCells->mObjectCount; objectIndex++) {
        if (IsRaceHudSubScreenPairNearCenter(&gRaceHudSubScreenDossunCells->mObjectPairs[objectIndex]) != FALSE) {
            object = gRaceHudSubScreenDossunCells->mObjects[objectIndex];
            if (ComputeRaceHudSubScreenPosition(
                    &object->mPos, &gRaceHudSubScreenDossunCells->mCells[cellCount].mDrawPos, scale, 0, 0) != FALSE) {
                gRaceHudSubScreenDossunCells->mCells[cellCount].mCell = GetRaceSNcerEntry(0xaf);
                gRaceHudSubScreenDossunCells->mCells[cellCount].mPriority = RACE_HUD_PRIORITY_FRONT;
                gRaceHudSubScreenDossunCells->mCells[cellCount + 1].mDrawPos =
                    GetRaceHudSubScreenDossunCell(cellCount)->mDrawPos;
                gRaceHudSubScreenDossunCells->mCells[cellCount + 1].mCell = GetRaceSNcerEntry(0xb0);
                gRaceHudSubScreenDossunCells->mCells[cellCount + 1].mPriority = RACE_HUD_PRIORITY_MIDDLE;
                cellCount += 2;
                offset = GetDossunMapDotOffset((Dossun *) object) * 16 >> 12;
                gRaceHudSubScreenDossunCells->mCells[cellCount - 2].mDrawPos.mSecond -= offset;
            }
        }
    }
    gRaceHudSubScreenDossunCells->mCellCount = cellCount;
}

void DrawRaceHudSubScreenDossunCells(RaceHudOamBuffer *oamBuffer) {
    DrawRaceHudSubScreenCells(oamBuffer, gRaceHudSubScreenDossunCells, 0);
}

BOOL CreateRaceHudSubScreenWanwanCells(void) {
    u16 kinds[2] = {0x196, 0x1a5};
    u16 kindIndex;
    u16 kind;

    for (kindIndex = 0; kindIndex < 2; kindIndex++) {
        kind = kinds[kindIndex];
        if (FindMapObjectKindDrawList0(kind) != NULL) {
            return CreateRaceHudSubScreenCells(&gRaceHudSubScreenWanwanCells, kind);
        }
    }
    return FALSE;
}

void ClearRaceHudSubScreenWanwanCells(void) {
    ClearRaceHudSubScreenCells(&gRaceHudSubScreenWanwanCells);
}

void UpdateRaceHudSubScreenWanwanCells(void) {
    s32 objectIndex;
    s32 cellCount;
    u32 scale;

    cellCount = 0;
    scale = GetRaceHudSubScreenScale();
    for (objectIndex = 0; objectIndex < gRaceHudSubScreenWanwanCells->mObjectCount; objectIndex++) {
        if (ComputeRaceHudSubScreenPosition(&gRaceHudSubScreenWanwanCells->mObjects[objectIndex]->mPos,
                                            &gRaceHudSubScreenWanwanCells->mCells[cellCount].mDrawPos, scale, 1,
                                            0) != FALSE) {
            gRaceHudSubScreenWanwanCells->mCells[cellCount].mCell = GetRaceSNcerEntry(0xac);
            gRaceHudSubScreenWanwanCells->mCells[cellCount].mPriority = RACE_HUD_PRIORITY_FRONT;
            cellCount++;
        }
    }
    gRaceHudSubScreenWanwanCells->mCellCount = cellCount;
}

void DrawRaceHudSubScreenWanwanCells(RaceHudOamBuffer *oamBuffer) {
    DrawRaceHudSubScreenCells(oamBuffer, gRaceHudSubScreenWanwanCells, 0);
}

s32 CreateRaceHudSubScreenEarthenPipeCells(void) {
    return CreateRaceHudSubScreenCells(&gRaceHudSubScreenEarthenPipeCells, MAP_OBJECT_KIND_EARTHEN_PIPE);
}

void ClearRaceHudSubScreenEarthenPipeCells(void) {
    ClearRaceHudSubScreenCells(&gRaceHudSubScreenEarthenPipeCells);
}

void UpdateRaceHudSubScreenEarthenPipeCells(void) {
    s32 objectIndex;
    s32 cellCount;
    MapObject *object;
    Vec3 *position;
    u32 scale;

    cellCount = 0;
    scale = GetRaceHudSubScreenScale();
    for (objectIndex = 0; objectIndex < gRaceHudSubScreenEarthenPipeCells->mObjectCount; objectIndex++) {
        if (IsRaceHudSubScreenPairNearCenter(&gRaceHudSubScreenEarthenPipeCells->mObjectPairs[objectIndex]) != FALSE) {
            object = gRaceHudSubScreenEarthenPipeCells->mObjects[objectIndex];
            if ((object->mFlags & 1) == 0) {
                position = &object->mPos;
                if (ComputeRaceHudSubScreenPosition(position,
                                                    &gRaceHudSubScreenEarthenPipeCells->mCells[cellCount].mDrawPos,
                                                    scale, 0, 0) != FALSE) {
                    gRaceHudSubScreenEarthenPipeCells->mCells[cellCount].mCell = GetRaceSNcerEntry(0x8c);
                    gRaceHudSubScreenEarthenPipeCells->mCells[cellCount].mPriority =
                        IsPositionOutsideBox(position) != 0 ? RACE_HUD_PRIORITY_MIDDLE : RACE_HUD_PRIORITY_BACK;
                    cellCount++;
                }
            }
        }
    }
    gRaceHudSubScreenEarthenPipeCells->mCellCount = cellCount;
}

void DrawRaceHudSubScreenEarthenPipeCells(RaceHudOamBuffer *oamBuffer) {
    DrawRaceHudSubScreenCells(oamBuffer, gRaceHudSubScreenEarthenPipeCells, 0);
}

s32 CreateRaceHudSubScreenItemBoxCells(void) {
    u16 kinds[2] = {MAP_OBJECT_KIND_ITEM_BOX, 0xc9};
    u16 kindIndex;
    u16 kind;
    s32 created;
    s32 highest;
    s32 objectIndex;

    for (kindIndex = 0; kindIndex < 2; kindIndex++) {
        kind = kinds[kindIndex];
        if (FindMapObjectKindDrawList0(kind) != NULL) {
            created = CreateRaceHudSubScreenCells(&gRaceHudSubScreenItemBoxCells, kind);
            highest = 0;
            for (objectIndex = 0; objectIndex < gRaceHudSubScreenItemBoxCells->mObjectCount; objectIndex++) {
                s32 groupDistance =
                    GetItemBoxMaxGroupDistance((ItemBox *) gRaceHudSubScreenItemBoxCells->mObjects[objectIndex]);
                if (groupDistance > highest) {
                    highest = groupDistance;
                }
            }
            if (highest < 0x3e8000) {
                gRaceHudSubScreenItemBoxNearOnly = 1;
            } else {
                gRaceHudSubScreenItemBoxNearOnly = 0;
            }
            return created;
        }
    }
    return 0;
}
