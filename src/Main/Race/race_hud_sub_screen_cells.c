#include "Main/Race/race_hud_sub_screen_cells.h"
#include "Main/System/heap.h"
#include "Main/Graphics/oam.h"
#include "Main/System/heap_array_alloc.h"

#include "Main/Race/race_hud_accessors.h"
#include "Main/Race/race_hud_sub_screen_frames.h"
#include "Main/Graphics/font_and_player_character.h"
#include "Main/Kart/point_link_cursor.h"
#include "Main/Race/race_hud_sub_screen_course_id.h"
#include "model_material_set.h"
#include "Main/Race/race_setup_block.h"
#include "touch_panel_sampling.h"
#include "Main/Race/graphic_file_loaders_and_matrix2x2.h"
#include "Main/Race/race_hud_sub_screen_min_max.h"
#include "Main/Kart/kart_heading_item_effect.h"
#include "Main/Race/race_hud_sub_screen_projection.h"
#include "Main/Race/race_hud_sub_screen_item_cells.h"
#include "fixed_vector_math.h"
#include "Main/Race/race_hud_sub_screen_shine16_cells.h"
#include "Main/Menu/emblem_choises_shown.h"
#include "Main/Race/race_hud_sub_screen_rain_star_cells.h"
#include "Main/Menu/vs_select_cup_m.h"
#include "Main/Menu/shuffled_indices.h"
#include "Main/Race/race_hud_sub_screen_bomb_koura_w_cells.h"
#include "Main/Race/race_goal_times.h"
#include "Main/Menu/cup_picture.h"
#include "Main/Race/race_hud_keyboard_map_object_work.h"
#include "Main/System/heap_call.h"
#include "Main/Race/race_hud_cell_group_functions.h"
#include "01/Race/race_hud_boss_cells.h"
#include "01/Race/race_hud_king_cells.h"
#include "cell_animation.h"
#include "Main/MapObjects/map_objects_get.h"
#include "Main/MapObjects/pooled_tail_count.h"
#include "Main/MapObjects/map_object_list_count_get.h"
#include "Main/MapObjects/map_object_kind_update_list.h"
#include "01/Race/race_hud_coin_cells.h"
#include "Main/Kart/karts.h"
#include "Main/Race/race_hud_sub_screen_item_box_cells_clear.h"
#include "Main/Race/race_hud_sub_screen_item_box_cells.h"
#include "Main/Race/race_hud_sub_screen_crab_cells_clear.h"
#include "Main/Race/race_hud_sub_screen_shine16_cells_clear.h"
#include "Main/Race/race_hud_sub_screen_pakkun_spit_cells.h"

RaceHudSubScreenCellGroupFunctions gRaceHudSubScreenCellGroupFunctions[49] = {
    {CreateRaceHudSubScreenKarts, ClearRaceHudSubScreenKarts, UpdateRaceHudSubScreenKarts, DrawRaceHudSubScreenKarts},
    {CreateRaceHudSubScreenItemCells, ClearRaceHudSubScreenItemCells, UpdateRaceHudSubScreenItemCells,
     DrawRaceHudSubScreenItemCells},
    {CreateRaceHudSubScreenBombKouraWCells, ClearRaceHudSubScreenBombKouraWCells, UpdateRaceHudSubScreenBombKouraWCells,
     DrawRaceHudSubScreenBombKouraWCells},
    {CreateRaceHudSubScreenItemBoxCells, ClearRaceHudSubScreenItemBoxCells, UpdateRaceHudSubScreenItemBoxCells,
     DrawRaceHudSubScreenItemBoxCells},
    {CreateRaceHudSubScreenEarthenPipeCells, ClearRaceHudSubScreenEarthenPipeCells,
     UpdateRaceHudSubScreenEarthenPipeCells, DrawRaceHudSubScreenEarthenPipeCells},
    {CreateRaceHudSubScreenWanwanCells, ClearRaceHudSubScreenWanwanCells, UpdateRaceHudSubScreenWanwanCells,
     DrawRaceHudSubScreenWanwanCells},
    {CreateRaceHudSubScreenDossunCells, ClearRaceHudSubScreenDossunCells, UpdateRaceHudSubScreenDossunCells,
     DrawRaceHudSubScreenDossunCells},
    {CreateRaceHudSubScreenCrabCells, ClearRaceHudSubScreenCrabCells, UpdateRaceHudSubScreenCrabCells,
     DrawRaceHudSubScreenCrabCells},
    {CreateRaceHudSubScreenSmanCells, ClearRaceHudSubScreenSmanCells, UpdateRaceHudSubScreenSmanCells,
     DrawRaceHudSubScreenSmanCells},
    {CreateRaceHudSubScreenMoveTreeCells, ClearRaceHudSubScreenMoveTreeCells, UpdateRaceHudSubScreenMoveTreeCells,
     DrawRaceHudSubScreenMoveTreeCells},
    {CreateRaceHudSubScreenPukupukuCells, ClearRaceHudSubScreenPukupukuCells, UpdateRaceHudSubScreenPukupukuCells,
     DrawRaceHudSubScreenPukupukuCells},
    {CreateRaceHudSubScreenChoropuCells, ClearRaceHudSubScreenChoropuCells, UpdateRaceHudSubScreenChoropuCells,
     DrawRaceHudSubScreenChoropuCells},
    {CreateRaceHudSubScreenKoopaBlockCells, ClearRaceHudSubScreenKoopaBlockCells, UpdateRaceHudSubScreenKoopaBlockCells,
     DrawRaceHudSubScreenKoopaBlockCells},
    {CreateRaceHudSubScreenCarCells, ClearRaceHudSubScreenCarCells, UpdateRaceHudSubScreenCarCells,
     DrawRaceHudSubScreenCarCells},
    {CreateRaceHudSubScreenSecondHand, ClearRaceHudSubScreenSecondHandPointer, UpdateRaceHudSubScreenSecondHand,
     DrawRaceHudSubScreenSecondHand},
    {CreateRaceHudSubScreenShine16Cells, ClearRaceHudSubScreenShine16Cells, UpdateRaceHudSubScreenShine16Cells,
     DrawRaceHudSubScreenShine16Cells},
    {CreateRaceHudSubScreenPendulumCells, ClearRaceHudSubScreenPendulumCells, UpdateRaceHudSubScreenPendulumCells,
     DrawRaceHudSubScreenPendulumCells},
    {CreateRaceHudSubScreenNsKiller2Cells, ClearRaceHudSubScreenNsKiller2Cells, UpdateRaceHudSubScreenNsKiller2Cells,
     DrawRaceHudSubScreenNsKiller2Cells},
    {CreateRaceHudSubScreenFlipperCells, ClearRaceHudSubScreenFlipperCells, UpdateRaceHudSubScreenFlipperCells,
     DrawRaceHudSubScreenFlipperCells},
    {CreateRaceHudSubScreenMkdEfBubbleCells, ClearRaceHudSubScreenMkdEfBubbleCells,
     UpdateRaceHudSubScreenMkdEfBubbleCells, DrawRaceHudSubScreenMkdEfBubbleCells},
    {CreateRaceHudSubScreenKuriboCells, ClearRaceHudSubScreenKuriboCells, UpdateRaceHudSubScreenKuriboCells,
     DrawRaceHudSubScreenKuriboCells},
    {CreateRaceHudSubScreenObPakkunSfCells, ClearRaceHudSubScreenObPakkunSfCells, UpdateRaceHudSubScreenObPakkunSfCells,
     DrawRaceHudSubScreenObPakkunSfCells},
    {CreateRaceHudSubScreenRock2Cells, ClearRaceHudSubScreenRock2Cells, UpdateRaceHudSubScreenRock2Cells,
     DrawRaceHudSubScreenRock2Cells},
    {CreateRaceHudSubScreenRockCells, ClearRaceHudSubScreenRockCells, UpdateRaceHudSubScreenRockCells,
     DrawRaceHudSubScreenRockCells},
    {CreateRaceHudSubScreenWoodbox1Cells, ClearRaceHudSubScreenWoodbox1Cells, UpdateRaceHudSubScreenWoodbox1Cells,
     DrawRaceHudSubScreenWoodbox1Cells},
    {CreateRaceHudSubScreenRainStarCells, ClearRaceHudSubScreenRainStarCells, UpdateRaceHudSubScreenRainStarCells,
     DrawRaceHudSubScreenRainStarCells},
    {CreateRaceHudSubScreenMkdEfBurnerCells, ClearRaceHudSubScreenMkdEfBurnerCells,
     UpdateRaceHudSubScreenMkdEfBurnerCells, DrawRaceHudSubScreenMkdEfBurnerCells},
    {CreateRaceHudSubScreenCoverPooHoleCells, ClearRaceHudSubScreenCoverPooHoleCells,
     UpdateRaceHudSubScreenCoverPooHoleCells, DrawRaceHudSubScreenCoverPooHoleCells},
    {CreateRaceHudSubScreenBoundCells, ClearRaceHudSubScreenBoundCells, UpdateRaceHudSubScreenBoundCells,
     DrawRaceHudSubScreenBoundCells},
    {CreateRaceHudSubScreenSunFireballCells, ClearRaceHudSubScreenSunFireballCells,
     UpdateRaceHudSubScreenSunFireballCells, DrawRaceHudSubScreenSunFireballCells},
    {CreateRaceHudSubScreenFireball2Cells, ClearRaceHudSubScreenFireball2Cells, UpdateRaceHudSubScreenFireball2Cells,
     DrawRaceHudSubScreenFireball2Cells},
    {CreateRaceHudSubScreenIronBallCells, ClearRaceHudSubScreenIronBallCells, UpdateRaceHudSubScreenIronBallCells,
     DrawRaceHudSubScreenIronBallCells},
    {CreateRaceHudSubScreenSanboCells, ClearRaceHudSubScreenSanboCells, UpdateRaceHudSubScreenSanboCells,
     DrawRaceHudSubScreenSanboCells},
    {CreateRaceHudSubScreenBasabasaCells, ClearRaceHudSubScreenBasabasaCells, UpdateRaceHudSubScreenBasabasaCells,
     DrawRaceHudSubScreenBasabasaCells},
    {CreateRaceHudSubScreenPakkunSpitCells, ClearRaceHudSubScreenPakkunSpitCells, UpdateRaceHudSubScreenPakkunSpitCells,
     DrawRaceHudSubScreenPakkunSpitCells},
    {CreateRaceHudSubScreenBerryCells, ClearRaceHudSubScreenBerryCells, UpdateRaceHudSubScreenBerryCells,
     DrawRaceHudSubScreenBerryCells},
    {CreateRaceHudSubScreenCreamCells, ClearRaceHudSubScreenCreamCells, UpdateRaceHudSubScreenCreamCells,
     DrawRaceHudSubScreenCreamCells},
    {CreateRaceHudSubScreenCoinCells, ClearRaceHudSubScreenCoinCells, UpdateRaceHudSubScreenCoinCells,
     DrawRaceHudSubScreenCoinCells},
    {CreateRaceHudSubScreenMissionGateCells, ClearRaceHudSubScreenMissionGateCells,
     UpdateRaceHudSubScreenMissionGateCells, DrawRaceHudSubScreenMissionGateCells},
    {CreateRaceHudSubScreenStopSignCells, ClearRaceHudSubScreenStopSignCells, UpdateRaceHudSubScreenStopSignCells,
     DrawRaceHudSubScreenStopSignCells},
    {CreateRaceHudSubScreenBossDonketuCells, ClearRaceHudSubScreenBossDonketuCells,
     UpdateRaceHudSubScreenBossDonketuCells, DrawRaceHudSubScreenBossDonketuCells},
    {CreateRaceHudSubScreenKingIceDonketuCells, ClearRaceHudSubScreenKingIceDonketuCells,
     UpdateRaceHudSubScreenKingIceDonketuCells, DrawRaceHudSubScreenKingIceDonketuCells},
    {CreateRaceHudSubScreenKurikingCells, ClearRaceHudSubScreenKurikingCells, UpdateRaceHudSubScreenKurikingCells,
     DrawRaceHudSubScreenKurikingCells},
    {CreateRaceHudSubScreenBombKingCells, ClearRaceHudSubScreenBombKingCells, UpdateRaceHudSubScreenBombKingCells,
     DrawRaceHudSubScreenBombKingCells},
    {CreateRaceHudSubScreenIwanteCells, ClearRaceHudSubScreenIwanteCells, UpdateRaceHudSubScreenIwanteCells,
     DrawRaceHudSubScreenIwanteCells},
    {CreateRaceHudSubScreenHanachanCells, ClearRaceHudSubScreenHanachanCells, UpdateRaceHudSubScreenHanachanCells,
     DrawRaceHudSubScreenHanachanCells},
    {CreateRaceHudSubScreenKingTeresaCells, ClearRaceHudSubScreenKingTeresaCells, UpdateRaceHudSubScreenKingTeresaCells,
     DrawRaceHudSubScreenKingTeresaCells},
    {NULL, NULL, NULL, NULL},
    {NULL, NULL, NULL, NULL},
};
RaceHudSubScreenCellGroups *gRaceHudSubScreenCellGroups;

u32 GetRaceHudSubScreenMinDrawValue(void) {
    return (gRaceHudSubScreenCellGroups->mMinDrawValue);
}

u32 GetRaceHudSubScreenScale(void) {
    return (gRaceHudSubScreenCellGroups->mScale);
}

u32 GetRaceHudSubScreenInverseScale(void) {
    return (gRaceHudSubScreenCellGroups->mInverseScale);
}

BOOL CreateRaceHudSubScreenCells(RaceHudSubScreenCells **outCells, s32 kind) {
    BOOL fromUpdateList;
    void *drawList;
    void *updateList;
    s32 objectIndex;
    s32 objectCount;

    fromUpdateList = FALSE;
    drawList = FindMapObjectKindDrawList0(kind);
    updateList = FindMapObjectKindUpdateList(kind);
    if (kind == MAP_OBJECT_KIND_SUN_FIREBALL || kind == 0x1ab) {
        fromUpdateList = TRUE;
    }
    if (fromUpdateList != FALSE) {
        if (updateList == NULL) {
            return FALSE;
        }
        objectCount = GetMapObjectListCount(updateList);
        if (objectCount == 0) {
            return FALSE;
        }
    } else {
        if (drawList == NULL) {
            return FALSE;
        }
        objectCount = CountMapObjectsBeforePooledTail(drawList);
        if (objectCount == 0) {
            return FALSE;
        }
    }
    *outCells = HeapAlloc(GetHeap(GetCurrentHeapCall()), sizeof(**outCells));
    if (fromUpdateList != FALSE) {
        (*outCells)->mObjects = (MapObject **) GetMapObjects(updateList);
    } else {
        (*outCells)->mObjects = RaceHudSubScreenGetMapObjects(drawList);
    }
    (*outCells)->mCellCount = 0;
    (*outCells)->mObjectCount = objectCount;
    (*outCells)->mObjectPairs = HeapAlloc(GetHeap(GetCurrentHeapCall()), objectCount * 8);
    for (objectIndex = 0; objectIndex < objectCount; objectIndex++) {
        ComputeRaceHudSubScreenCoursePosition(&(*outCells)->mObjects[objectIndex]->mPos,
                                              &(*outCells)->mObjectPairs[objectIndex]);
    }
    (*outCells)->mCells = AllocArrayFromCurrentHeap(objectCount * 2, sizeof(*(*outCells)->mCells));
    return TRUE;
}

BOOL CreateRaceHudSubScreenCellsWithCount(RaceHudSubScreenCells **outCells, s32 objectCount) {
    if (objectCount == 0) {
        return FALSE;
    }
    *outCells = HeapAlloc(GetHeap(GetCurrentHeapCall()), sizeof(**outCells));
    (*outCells)->mCellCount = 0;
    (*outCells)->mObjectCount = objectCount;
    (*outCells)->mObjectPairs = HeapAlloc(GetHeap(GetCurrentHeapCall()), objectCount * 8);
    (*outCells)->mCells = AllocArrayFromCurrentHeap(objectCount, sizeof(*(*outCells)->mCells));
    return TRUE;
}

void ClearRaceHudSubScreenCells(RaceHudSubScreenCells **cellsPointerAddress) {
    (*cellsPointerAddress)->mObjects = NULL;
    (*cellsPointerAddress)->mObjectPairs = NULL;
    (*cellsPointerAddress)->mCells = NULL;
    *cellsPointerAddress = NULL;
}

void DrawRaceHudSubScreenCells(RaceHudOamBuffer *oamBuffer, RaceHudSubScreenCells *cells, s32 useRotation) {
    s32 cellIndex;
    s32 minDrawValue;
    u16 angle;
    u16 matrixIndex;
    MtxFx22 rotationMatrix;
    s32 drawPosition[2];
    s32 priority;
    s32 flag;
    s32 oamIndex;
    RaceHudOamBits *oam;
    RaceHudSubScreenCell *cell;
    s32 screenX;
    s32 screenY;
    void *cellData;

    minDrawValue = gRaceHudSubScreenCellGroups->mMinDrawValue;
    if (useRotation != 0) {
        angle = GetSubScreenAngleAndClearScrollTimer();
    }
    for (cellIndex = 0; cellIndex < cells->mCellCount; cellIndex++) {
        priority = cells->mCells[cellIndex].mPriority;
        if (minDrawValue <= priority) {
            flag = cells->mCells[cellIndex].mXlu;
            matrixIndex = 0;
            if (useRotation != 0) {
                if (gRaceSetup->mMirrorMode != 0) {
                    Matrix2x2Rotation(&rotationMatrix, (cells->mCells[cellIndex].mAngle + ANGLE_HALF_TURN - angle));
                } else {
                    Matrix2x2Rotation(&rotationMatrix, (angle + (ANGLE_HALF_TURN - cells->mCells[cellIndex].mAngle)));
                }
                matrixIndex = AllocOamMatrixIndex(oamBuffer);
                oamBuffer->mMatrices[matrixIndex].mPA = rotationMatrix.mElements[0] >> 4;
                oamBuffer->mMatrices[matrixIndex].mPB = rotationMatrix.mElements[1] >> 4;
                oamBuffer->mMatrices[matrixIndex].mPC = rotationMatrix.mElements[2] >> 4;
                oamBuffer->mMatrices[matrixIndex].mPD = rotationMatrix.mElements[3] >> 4;
            }
            cell = &cells->mCells[cellIndex];
            screenX = cell->mDrawPos.mFirst;
            cellData = cell->mCell;
            screenY = cell->mDrawPos.mSecond;
            oamIndex = oamBuffer->mOamCount;
            drawPosition[0] = TO_FIXED12(screenX);
            drawPosition[1] = TO_FIXED12(screenY);
            oamBuffer->mOamCount +=
                NNS_G2dMakeCellToOams(&oamBuffer->mOams[oamIndex], 0x80 - oamIndex, cellData,
                                      useRotation != 0 ? &rotationMatrix : 0, drawPosition, matrixIndex, 1);
            oam = &oamBuffer->mOamBits[oamIndex];
            for (; oamIndex < oamBuffer->mOamCount; oamIndex++, oam++) {
                if ((flag != 0 ? RACE_HUD_OBJ_MODE_TRANSLUCENT : -1) != -1) {
                    oam->mObjMode = flag != 0 ? RACE_HUD_OBJ_MODE_TRANSLUCENT : -1;
                }
                if (priority != -1) {
                    oam->mPriority = priority;
                }
            }
        }
    }
}

void DrawRaceHudSubScreenCellsScaled(RaceHudOamBuffer *oamBuffer, RaceHudSubScreenCells *cells, s32 useRotation) {
    s32 cellIndex;
    s32 minDrawValue;
    u16 angle;
    MtxFx22 matrix;
    s32 drawPosition[2];
    s32 priority;
    s32 flag;
    s32 oamIndex;
    u16 matrixIndex;
    RaceHudOamBits *oam;
    RaceHudSubScreenCell *cell;
    s32 screenX;
    s32 screenY;
    void *cellData;

    minDrawValue = gRaceHudSubScreenCellGroups->mMinDrawValue;
    if (useRotation != 0) {
        angle = GetSubScreenAngleAndClearScrollTimer();
    }
    for (cellIndex = 0; cellIndex < cells->mCellCount; cellIndex++) {
        priority = cells->mCells[cellIndex].mPriority;
        if (minDrawValue <= priority) {
            flag = cells->mCells[cellIndex].mXlu;
            if (useRotation != 0) {
                if (gRaceSetup->mMirrorMode != 0) {
                    Matrix2x2RotationReciprocalScale(&matrix, cells->mObjectPairs[cellIndex].mFirst,
                                                     (u16) (cells->mCells[cellIndex].mAngle - angle));
                } else {
                    Matrix2x2RotationReciprocalScale(&matrix, cells->mObjectPairs[cellIndex].mFirst,
                                                     (u16) (angle - cells->mCells[cellIndex].mAngle));
                }
            } else {
                Matrix2x2ReciprocalScale(&matrix, cells->mObjectPairs[cellIndex].mFirst);
            }
            matrixIndex = AllocOamMatrixIndex(oamBuffer);
            oamBuffer->mMatrices[matrixIndex].mPA = matrix.mElements[0] >> 4;
            oamBuffer->mMatrices[matrixIndex].mPB = matrix.mElements[1] >> 4;
            oamBuffer->mMatrices[matrixIndex].mPC = matrix.mElements[2] >> 4;
            oamBuffer->mMatrices[matrixIndex].mPD = matrix.mElements[3] >> 4;
            cell = &cells->mCells[cellIndex];
            screenX = cell->mDrawPos.mFirst;
            cellData = cell->mCell;
            screenY = cell->mDrawPos.mSecond;
            oamIndex = oamBuffer->mOamCount;
            drawPosition[0] = TO_FIXED12(screenX);
            drawPosition[1] = TO_FIXED12(screenY);
            oamBuffer->mOamCount += NNS_G2dMakeCellToOams(&oamBuffer->mOams[oamIndex], 0x80 - oamIndex, cellData,
                                                          &matrix, drawPosition, matrixIndex, 1);
            oam = &oamBuffer->mOamBits[oamIndex];
            for (; oamIndex < oamBuffer->mOamCount; oamIndex++, oam++) {
                if ((flag != 0 ? RACE_HUD_OBJ_MODE_TRANSLUCENT : -1) != -1) {
                    oam->mObjMode = flag != 0 ? RACE_HUD_OBJ_MODE_TRANSLUCENT : -1;
                }
                if (priority != -1) {
                    oam->mPriority = priority;
                }
            }
        }
    }
}

void InitRaceHudSubScreenCellGroups(void) {
    gRaceHudSubScreenCellGroups = HeapAlloc(GetHeap(GetCurrentHeapCall()), sizeof(*gRaceHudSubScreenCellGroups));
    gRaceHudSubScreenCellGroups->mMinDrawValue = 0;
    gRaceHudSubScreenCellGroups->mScale = 0;
    gRaceHudSubScreenCellGroups->mInverseScale = 0;
    gRaceHudSubScreenCellGroups->mGroupCount = 0;
    if (CreateRaceHudSubScreenKarts()) {
        s32 groupIndex;
        s32 functionIndex;

        groupIndex = gRaceHudSubScreenCellGroups->mGroupCount++;
        for (functionIndex = 0;
             gRaceHudSubScreenCellGroupFunctions[functionIndex].mCreate != CreateRaceHudSubScreenKarts &&
             functionIndex < 49;
             functionIndex++) {
        }
        if (functionIndex < 49) {
            gRaceHudSubScreenCellGroups->mClearFunctions[groupIndex] =
                gRaceHudSubScreenCellGroupFunctions[functionIndex].mClear;
            gRaceHudSubScreenCellGroups->mUpdateFunctions[groupIndex] =
                gRaceHudSubScreenCellGroupFunctions[functionIndex].mUpdate;
            gRaceHudSubScreenCellGroups->mDrawFunctions[groupIndex] =
                gRaceHudSubScreenCellGroupFunctions[functionIndex].mDraw;
        }
    }
    if (CreateRaceHudSubScreenItemCells()) {
        s32 groupIndex;
        s32 functionIndex;

        groupIndex = gRaceHudSubScreenCellGroups->mGroupCount++;
        for (functionIndex = 0;
             gRaceHudSubScreenCellGroupFunctions[functionIndex].mCreate != CreateRaceHudSubScreenItemCells &&
             functionIndex < 49;
             functionIndex++) {
        }
        if (functionIndex < 49) {
            gRaceHudSubScreenCellGroups->mClearFunctions[groupIndex] =
                gRaceHudSubScreenCellGroupFunctions[functionIndex].mClear;
            gRaceHudSubScreenCellGroups->mUpdateFunctions[groupIndex] =
                gRaceHudSubScreenCellGroupFunctions[functionIndex].mUpdate;
            gRaceHudSubScreenCellGroups->mDrawFunctions[groupIndex] =
                gRaceHudSubScreenCellGroupFunctions[functionIndex].mDraw;
        }
    }
    if (CreateRaceHudSubScreenBombKouraWCells()) {
        s32 groupIndex;
        s32 functionIndex;

        groupIndex = gRaceHudSubScreenCellGroups->mGroupCount++;
        for (functionIndex = 0;
             gRaceHudSubScreenCellGroupFunctions[functionIndex].mCreate != CreateRaceHudSubScreenBombKouraWCells &&
             functionIndex < 49;
             functionIndex++) {
        }
        if (functionIndex < 49) {
            gRaceHudSubScreenCellGroups->mClearFunctions[groupIndex] =
                gRaceHudSubScreenCellGroupFunctions[functionIndex].mClear;
            gRaceHudSubScreenCellGroups->mUpdateFunctions[groupIndex] =
                gRaceHudSubScreenCellGroupFunctions[functionIndex].mUpdate;
            gRaceHudSubScreenCellGroups->mDrawFunctions[groupIndex] =
                gRaceHudSubScreenCellGroupFunctions[functionIndex].mDraw;
        }
    }
    if (CreateRaceHudSubScreenItemBoxCells()) {
        s32 groupIndex;
        s32 functionIndex;

        groupIndex = gRaceHudSubScreenCellGroups->mGroupCount++;
        for (functionIndex = 0;
             gRaceHudSubScreenCellGroupFunctions[functionIndex].mCreate != CreateRaceHudSubScreenItemBoxCells &&
             functionIndex < 49;
             functionIndex++) {
        }
        if (functionIndex < 49) {
            gRaceHudSubScreenCellGroups->mClearFunctions[groupIndex] =
                gRaceHudSubScreenCellGroupFunctions[functionIndex].mClear;
            gRaceHudSubScreenCellGroups->mUpdateFunctions[groupIndex] =
                gRaceHudSubScreenCellGroupFunctions[functionIndex].mUpdate;
            gRaceHudSubScreenCellGroups->mDrawFunctions[groupIndex] =
                gRaceHudSubScreenCellGroupFunctions[functionIndex].mDraw;
        }
    }
    if (CreateRaceHudSubScreenEarthenPipeCells()) {
        s32 groupIndex;
        s32 functionIndex;

        groupIndex = gRaceHudSubScreenCellGroups->mGroupCount++;
        for (functionIndex = 0;
             gRaceHudSubScreenCellGroupFunctions[functionIndex].mCreate != CreateRaceHudSubScreenEarthenPipeCells &&
             functionIndex < 49;
             functionIndex++) {
        }
        if (functionIndex < 49) {
            gRaceHudSubScreenCellGroups->mClearFunctions[groupIndex] =
                gRaceHudSubScreenCellGroupFunctions[functionIndex].mClear;
            gRaceHudSubScreenCellGroups->mUpdateFunctions[groupIndex] =
                gRaceHudSubScreenCellGroupFunctions[functionIndex].mUpdate;
            gRaceHudSubScreenCellGroups->mDrawFunctions[groupIndex] =
                gRaceHudSubScreenCellGroupFunctions[functionIndex].mDraw;
        }
    }
    if (CreateRaceHudSubScreenWanwanCells()) {
        s32 groupIndex;
        s32 functionIndex;

        groupIndex = gRaceHudSubScreenCellGroups->mGroupCount++;
        for (functionIndex = 0;
             gRaceHudSubScreenCellGroupFunctions[functionIndex].mCreate != CreateRaceHudSubScreenWanwanCells &&
             functionIndex < 49;
             functionIndex++) {
        }
        if (functionIndex < 49) {
            gRaceHudSubScreenCellGroups->mClearFunctions[groupIndex] =
                gRaceHudSubScreenCellGroupFunctions[functionIndex].mClear;
            gRaceHudSubScreenCellGroups->mUpdateFunctions[groupIndex] =
                gRaceHudSubScreenCellGroupFunctions[functionIndex].mUpdate;
            gRaceHudSubScreenCellGroups->mDrawFunctions[groupIndex] =
                gRaceHudSubScreenCellGroupFunctions[functionIndex].mDraw;
        }
    }
    if (CreateRaceHudSubScreenDossunCells()) {
        s32 groupIndex;
        s32 functionIndex;

        groupIndex = gRaceHudSubScreenCellGroups->mGroupCount++;
        for (functionIndex = 0;
             gRaceHudSubScreenCellGroupFunctions[functionIndex].mCreate != CreateRaceHudSubScreenDossunCells &&
             functionIndex < 49;
             functionIndex++) {
        }
        if (functionIndex < 49) {
            gRaceHudSubScreenCellGroups->mClearFunctions[groupIndex] =
                gRaceHudSubScreenCellGroupFunctions[functionIndex].mClear;
            gRaceHudSubScreenCellGroups->mUpdateFunctions[groupIndex] =
                gRaceHudSubScreenCellGroupFunctions[functionIndex].mUpdate;
            gRaceHudSubScreenCellGroups->mDrawFunctions[groupIndex] =
                gRaceHudSubScreenCellGroupFunctions[functionIndex].mDraw;
        }
    }
    if (CreateRaceHudSubScreenCrabCells()) {
        s32 groupIndex;
        s32 functionIndex;

        groupIndex = gRaceHudSubScreenCellGroups->mGroupCount++;
        for (functionIndex = 0;
             gRaceHudSubScreenCellGroupFunctions[functionIndex].mCreate != CreateRaceHudSubScreenCrabCells &&
             functionIndex < 49;
             functionIndex++) {
        }
        if (functionIndex < 49) {
            gRaceHudSubScreenCellGroups->mClearFunctions[groupIndex] =
                gRaceHudSubScreenCellGroupFunctions[functionIndex].mClear;
            gRaceHudSubScreenCellGroups->mUpdateFunctions[groupIndex] =
                gRaceHudSubScreenCellGroupFunctions[functionIndex].mUpdate;
            gRaceHudSubScreenCellGroups->mDrawFunctions[groupIndex] =
                gRaceHudSubScreenCellGroupFunctions[functionIndex].mDraw;
        }
    }
    if (CreateRaceHudSubScreenSmanCells()) {
        s32 groupIndex;
        s32 functionIndex;

        groupIndex = gRaceHudSubScreenCellGroups->mGroupCount++;
        for (functionIndex = 0;
             gRaceHudSubScreenCellGroupFunctions[functionIndex].mCreate != CreateRaceHudSubScreenSmanCells &&
             functionIndex < 49;
             functionIndex++) {
        }
        if (functionIndex < 49) {
            gRaceHudSubScreenCellGroups->mClearFunctions[groupIndex] =
                gRaceHudSubScreenCellGroupFunctions[functionIndex].mClear;
            gRaceHudSubScreenCellGroups->mUpdateFunctions[groupIndex] =
                gRaceHudSubScreenCellGroupFunctions[functionIndex].mUpdate;
            gRaceHudSubScreenCellGroups->mDrawFunctions[groupIndex] =
                gRaceHudSubScreenCellGroupFunctions[functionIndex].mDraw;
        }
    }
    if (CreateRaceHudSubScreenMoveTreeCells()) {
        s32 groupIndex;
        s32 functionIndex;

        groupIndex = gRaceHudSubScreenCellGroups->mGroupCount++;
        for (functionIndex = 0;
             gRaceHudSubScreenCellGroupFunctions[functionIndex].mCreate != CreateRaceHudSubScreenMoveTreeCells &&
             functionIndex < 49;
             functionIndex++) {
        }
        if (functionIndex < 49) {
            gRaceHudSubScreenCellGroups->mClearFunctions[groupIndex] =
                gRaceHudSubScreenCellGroupFunctions[functionIndex].mClear;
            gRaceHudSubScreenCellGroups->mUpdateFunctions[groupIndex] =
                gRaceHudSubScreenCellGroupFunctions[functionIndex].mUpdate;
            gRaceHudSubScreenCellGroups->mDrawFunctions[groupIndex] =
                gRaceHudSubScreenCellGroupFunctions[functionIndex].mDraw;
        }
    }
    if (CreateRaceHudSubScreenPukupukuCells()) {
        s32 groupIndex;
        s32 functionIndex;

        groupIndex = gRaceHudSubScreenCellGroups->mGroupCount++;
        for (functionIndex = 0;
             gRaceHudSubScreenCellGroupFunctions[functionIndex].mCreate != CreateRaceHudSubScreenPukupukuCells &&
             functionIndex < 49;
             functionIndex++) {
        }
        if (functionIndex < 49) {
            gRaceHudSubScreenCellGroups->mClearFunctions[groupIndex] =
                gRaceHudSubScreenCellGroupFunctions[functionIndex].mClear;
            gRaceHudSubScreenCellGroups->mUpdateFunctions[groupIndex] =
                gRaceHudSubScreenCellGroupFunctions[functionIndex].mUpdate;
            gRaceHudSubScreenCellGroups->mDrawFunctions[groupIndex] =
                gRaceHudSubScreenCellGroupFunctions[functionIndex].mDraw;
        }
    }
    if (CreateRaceHudSubScreenChoropuCells()) {
        s32 groupIndex;
        s32 functionIndex;

        groupIndex = gRaceHudSubScreenCellGroups->mGroupCount++;
        for (functionIndex = 0;
             gRaceHudSubScreenCellGroupFunctions[functionIndex].mCreate != CreateRaceHudSubScreenChoropuCells &&
             functionIndex < 49;
             functionIndex++) {
        }
        if (functionIndex < 49) {
            gRaceHudSubScreenCellGroups->mClearFunctions[groupIndex] =
                gRaceHudSubScreenCellGroupFunctions[functionIndex].mClear;
            gRaceHudSubScreenCellGroups->mUpdateFunctions[groupIndex] =
                gRaceHudSubScreenCellGroupFunctions[functionIndex].mUpdate;
            gRaceHudSubScreenCellGroups->mDrawFunctions[groupIndex] =
                gRaceHudSubScreenCellGroupFunctions[functionIndex].mDraw;
        }
    }
    if (CreateRaceHudSubScreenCarCells()) {
        s32 groupIndex;
        s32 functionIndex;

        groupIndex = gRaceHudSubScreenCellGroups->mGroupCount++;
        for (functionIndex = 0;
             gRaceHudSubScreenCellGroupFunctions[functionIndex].mCreate != CreateRaceHudSubScreenCarCells &&
             functionIndex < 49;
             functionIndex++) {
        }
        if (functionIndex < 49) {
            gRaceHudSubScreenCellGroups->mClearFunctions[groupIndex] =
                gRaceHudSubScreenCellGroupFunctions[functionIndex].mClear;
            gRaceHudSubScreenCellGroups->mUpdateFunctions[groupIndex] =
                gRaceHudSubScreenCellGroupFunctions[functionIndex].mUpdate;
            gRaceHudSubScreenCellGroups->mDrawFunctions[groupIndex] =
                gRaceHudSubScreenCellGroupFunctions[functionIndex].mDraw;
        }
    }
    if (CreateRaceHudSubScreenSecondHand()) {
        s32 groupIndex;
        s32 functionIndex;

        groupIndex = gRaceHudSubScreenCellGroups->mGroupCount++;
        for (functionIndex = 0;
             gRaceHudSubScreenCellGroupFunctions[functionIndex].mCreate != CreateRaceHudSubScreenSecondHand &&
             functionIndex < 49;
             functionIndex++) {
        }
        if (functionIndex < 49) {
            gRaceHudSubScreenCellGroups->mClearFunctions[groupIndex] =
                gRaceHudSubScreenCellGroupFunctions[functionIndex].mClear;
            gRaceHudSubScreenCellGroups->mUpdateFunctions[groupIndex] =
                gRaceHudSubScreenCellGroupFunctions[functionIndex].mUpdate;
            gRaceHudSubScreenCellGroups->mDrawFunctions[groupIndex] =
                gRaceHudSubScreenCellGroupFunctions[functionIndex].mDraw;
        }
    }
    if (CreateRaceHudSubScreenShine16Cells()) {
        s32 groupIndex;
        s32 functionIndex;

        groupIndex = gRaceHudSubScreenCellGroups->mGroupCount++;
        for (functionIndex = 0;
             gRaceHudSubScreenCellGroupFunctions[functionIndex].mCreate != CreateRaceHudSubScreenShine16Cells &&
             functionIndex < 49;
             functionIndex++) {
        }
        if (functionIndex < 49) {
            gRaceHudSubScreenCellGroups->mClearFunctions[groupIndex] =
                gRaceHudSubScreenCellGroupFunctions[functionIndex].mClear;
            gRaceHudSubScreenCellGroups->mUpdateFunctions[groupIndex] =
                gRaceHudSubScreenCellGroupFunctions[functionIndex].mUpdate;
            gRaceHudSubScreenCellGroups->mDrawFunctions[groupIndex] =
                gRaceHudSubScreenCellGroupFunctions[functionIndex].mDraw;
        }
    }
    if (CreateRaceHudSubScreenPendulumCells()) {
        s32 groupIndex;
        s32 functionIndex;

        groupIndex = gRaceHudSubScreenCellGroups->mGroupCount++;
        for (functionIndex = 0;
             gRaceHudSubScreenCellGroupFunctions[functionIndex].mCreate != CreateRaceHudSubScreenPendulumCells &&
             functionIndex < 49;
             functionIndex++) {
        }
        if (functionIndex < 49) {
            gRaceHudSubScreenCellGroups->mClearFunctions[groupIndex] =
                gRaceHudSubScreenCellGroupFunctions[functionIndex].mClear;
            gRaceHudSubScreenCellGroups->mUpdateFunctions[groupIndex] =
                gRaceHudSubScreenCellGroupFunctions[functionIndex].mUpdate;
            gRaceHudSubScreenCellGroups->mDrawFunctions[groupIndex] =
                gRaceHudSubScreenCellGroupFunctions[functionIndex].mDraw;
        }
    }
    if (CreateRaceHudSubScreenNsKiller2Cells()) {
        s32 groupIndex;
        s32 functionIndex;

        groupIndex = gRaceHudSubScreenCellGroups->mGroupCount++;
        for (functionIndex = 0;
             gRaceHudSubScreenCellGroupFunctions[functionIndex].mCreate != CreateRaceHudSubScreenNsKiller2Cells &&
             functionIndex < 49;
             functionIndex++) {
        }
        if (functionIndex < 49) {
            gRaceHudSubScreenCellGroups->mClearFunctions[groupIndex] =
                gRaceHudSubScreenCellGroupFunctions[functionIndex].mClear;
            gRaceHudSubScreenCellGroups->mUpdateFunctions[groupIndex] =
                gRaceHudSubScreenCellGroupFunctions[functionIndex].mUpdate;
            gRaceHudSubScreenCellGroups->mDrawFunctions[groupIndex] =
                gRaceHudSubScreenCellGroupFunctions[functionIndex].mDraw;
        }
    }
    if (CreateRaceHudSubScreenFlipperCells()) {
        s32 groupIndex;
        s32 functionIndex;

        groupIndex = gRaceHudSubScreenCellGroups->mGroupCount++;
        for (functionIndex = 0;
             gRaceHudSubScreenCellGroupFunctions[functionIndex].mCreate != CreateRaceHudSubScreenFlipperCells &&
             functionIndex < 49;
             functionIndex++) {
        }
        if (functionIndex < 49) {
            gRaceHudSubScreenCellGroups->mClearFunctions[groupIndex] =
                gRaceHudSubScreenCellGroupFunctions[functionIndex].mClear;
            gRaceHudSubScreenCellGroups->mUpdateFunctions[groupIndex] =
                gRaceHudSubScreenCellGroupFunctions[functionIndex].mUpdate;
            gRaceHudSubScreenCellGroups->mDrawFunctions[groupIndex] =
                gRaceHudSubScreenCellGroupFunctions[functionIndex].mDraw;
        }
    }
    if (CreateRaceHudSubScreenMkdEfBubbleCells()) {
        s32 groupIndex;
        s32 functionIndex;

        groupIndex = gRaceHudSubScreenCellGroups->mGroupCount++;
        for (functionIndex = 0;
             gRaceHudSubScreenCellGroupFunctions[functionIndex].mCreate != CreateRaceHudSubScreenMkdEfBubbleCells &&
             functionIndex < 49;
             functionIndex++) {
        }
        if (functionIndex < 49) {
            gRaceHudSubScreenCellGroups->mClearFunctions[groupIndex] =
                gRaceHudSubScreenCellGroupFunctions[functionIndex].mClear;
            gRaceHudSubScreenCellGroups->mUpdateFunctions[groupIndex] =
                gRaceHudSubScreenCellGroupFunctions[functionIndex].mUpdate;
            gRaceHudSubScreenCellGroups->mDrawFunctions[groupIndex] =
                gRaceHudSubScreenCellGroupFunctions[functionIndex].mDraw;
        }
    }
    if (CreateRaceHudSubScreenKuriboCells()) {
        s32 groupIndex;
        s32 functionIndex;

        groupIndex = gRaceHudSubScreenCellGroups->mGroupCount++;
        for (functionIndex = 0;
             gRaceHudSubScreenCellGroupFunctions[functionIndex].mCreate != CreateRaceHudSubScreenKuriboCells &&
             functionIndex < 49;
             functionIndex++) {
        }
        if (functionIndex < 49) {
            gRaceHudSubScreenCellGroups->mClearFunctions[groupIndex] =
                gRaceHudSubScreenCellGroupFunctions[functionIndex].mClear;
            gRaceHudSubScreenCellGroups->mUpdateFunctions[groupIndex] =
                gRaceHudSubScreenCellGroupFunctions[functionIndex].mUpdate;
            gRaceHudSubScreenCellGroups->mDrawFunctions[groupIndex] =
                gRaceHudSubScreenCellGroupFunctions[functionIndex].mDraw;
        }
    }
    if (CreateRaceHudSubScreenObPakkunSfCells()) {
        s32 groupIndex;
        s32 functionIndex;

        groupIndex = gRaceHudSubScreenCellGroups->mGroupCount++;
        for (functionIndex = 0;
             gRaceHudSubScreenCellGroupFunctions[functionIndex].mCreate != CreateRaceHudSubScreenObPakkunSfCells &&
             functionIndex < 49;
             functionIndex++) {
        }
        if (functionIndex < 49) {
            gRaceHudSubScreenCellGroups->mClearFunctions[groupIndex] =
                gRaceHudSubScreenCellGroupFunctions[functionIndex].mClear;
            gRaceHudSubScreenCellGroups->mUpdateFunctions[groupIndex] =
                gRaceHudSubScreenCellGroupFunctions[functionIndex].mUpdate;
            gRaceHudSubScreenCellGroups->mDrawFunctions[groupIndex] =
                gRaceHudSubScreenCellGroupFunctions[functionIndex].mDraw;
        }
    }
    if (CreateRaceHudSubScreenRock2Cells()) {
        s32 groupIndex;
        s32 functionIndex;

        groupIndex = gRaceHudSubScreenCellGroups->mGroupCount++;
        for (functionIndex = 0;
             gRaceHudSubScreenCellGroupFunctions[functionIndex].mCreate != CreateRaceHudSubScreenRock2Cells &&
             functionIndex < 49;
             functionIndex++) {
        }
        if (functionIndex < 49) {
            gRaceHudSubScreenCellGroups->mClearFunctions[groupIndex] =
                gRaceHudSubScreenCellGroupFunctions[functionIndex].mClear;
            gRaceHudSubScreenCellGroups->mUpdateFunctions[groupIndex] =
                gRaceHudSubScreenCellGroupFunctions[functionIndex].mUpdate;
            gRaceHudSubScreenCellGroups->mDrawFunctions[groupIndex] =
                gRaceHudSubScreenCellGroupFunctions[functionIndex].mDraw;
        }
    }
    if (CreateRaceHudSubScreenRockCells()) {
        s32 groupIndex;
        s32 functionIndex;

        groupIndex = gRaceHudSubScreenCellGroups->mGroupCount++;
        for (functionIndex = 0;
             gRaceHudSubScreenCellGroupFunctions[functionIndex].mCreate != CreateRaceHudSubScreenRockCells &&
             functionIndex < 49;
             functionIndex++) {
        }
        if (functionIndex < 49) {
            gRaceHudSubScreenCellGroups->mClearFunctions[groupIndex] =
                gRaceHudSubScreenCellGroupFunctions[functionIndex].mClear;
            gRaceHudSubScreenCellGroups->mUpdateFunctions[groupIndex] =
                gRaceHudSubScreenCellGroupFunctions[functionIndex].mUpdate;
            gRaceHudSubScreenCellGroups->mDrawFunctions[groupIndex] =
                gRaceHudSubScreenCellGroupFunctions[functionIndex].mDraw;
        }
    }
    if (CreateRaceHudSubScreenWoodbox1Cells()) {
        s32 groupIndex;
        s32 functionIndex;

        groupIndex = gRaceHudSubScreenCellGroups->mGroupCount++;
        for (functionIndex = 0;
             gRaceHudSubScreenCellGroupFunctions[functionIndex].mCreate != CreateRaceHudSubScreenWoodbox1Cells &&
             functionIndex < 49;
             functionIndex++) {
        }
        if (functionIndex < 49) {
            gRaceHudSubScreenCellGroups->mClearFunctions[groupIndex] =
                gRaceHudSubScreenCellGroupFunctions[functionIndex].mClear;
            gRaceHudSubScreenCellGroups->mUpdateFunctions[groupIndex] =
                gRaceHudSubScreenCellGroupFunctions[functionIndex].mUpdate;
            gRaceHudSubScreenCellGroups->mDrawFunctions[groupIndex] =
                gRaceHudSubScreenCellGroupFunctions[functionIndex].mDraw;
        }
    }
    if (CreateRaceHudSubScreenRainStarCells()) {
        s32 groupIndex;
        s32 functionIndex;

        groupIndex = gRaceHudSubScreenCellGroups->mGroupCount++;
        for (functionIndex = 0;
             gRaceHudSubScreenCellGroupFunctions[functionIndex].mCreate != CreateRaceHudSubScreenRainStarCells &&
             functionIndex < 49;
             functionIndex++) {
        }
        if (functionIndex < 49) {
            gRaceHudSubScreenCellGroups->mClearFunctions[groupIndex] =
                gRaceHudSubScreenCellGroupFunctions[functionIndex].mClear;
            gRaceHudSubScreenCellGroups->mUpdateFunctions[groupIndex] =
                gRaceHudSubScreenCellGroupFunctions[functionIndex].mUpdate;
            gRaceHudSubScreenCellGroups->mDrawFunctions[groupIndex] =
                gRaceHudSubScreenCellGroupFunctions[functionIndex].mDraw;
        }
    }
    if (CreateRaceHudSubScreenMkdEfBurnerCells()) {
        s32 groupIndex;
        s32 functionIndex;

        groupIndex = gRaceHudSubScreenCellGroups->mGroupCount++;
        for (functionIndex = 0;
             gRaceHudSubScreenCellGroupFunctions[functionIndex].mCreate != CreateRaceHudSubScreenMkdEfBurnerCells &&
             functionIndex < 49;
             functionIndex++) {
        }
        if (functionIndex < 49) {
            gRaceHudSubScreenCellGroups->mClearFunctions[groupIndex] =
                gRaceHudSubScreenCellGroupFunctions[functionIndex].mClear;
            gRaceHudSubScreenCellGroups->mUpdateFunctions[groupIndex] =
                gRaceHudSubScreenCellGroupFunctions[functionIndex].mUpdate;
            gRaceHudSubScreenCellGroups->mDrawFunctions[groupIndex] =
                gRaceHudSubScreenCellGroupFunctions[functionIndex].mDraw;
        }
    }
    if (CreateRaceHudSubScreenCoverPooHoleCells()) {
        s32 groupIndex;
        s32 functionIndex;

        groupIndex = gRaceHudSubScreenCellGroups->mGroupCount++;
        for (functionIndex = 0;
             gRaceHudSubScreenCellGroupFunctions[functionIndex].mCreate != CreateRaceHudSubScreenCoverPooHoleCells &&
             functionIndex < 49;
             functionIndex++) {
        }
        if (functionIndex < 49) {
            gRaceHudSubScreenCellGroups->mClearFunctions[groupIndex] =
                gRaceHudSubScreenCellGroupFunctions[functionIndex].mClear;
            gRaceHudSubScreenCellGroups->mUpdateFunctions[groupIndex] =
                gRaceHudSubScreenCellGroupFunctions[functionIndex].mUpdate;
            gRaceHudSubScreenCellGroups->mDrawFunctions[groupIndex] =
                gRaceHudSubScreenCellGroupFunctions[functionIndex].mDraw;
        }
    }
    if (CreateRaceHudSubScreenBoundCells()) {
        s32 groupIndex;
        s32 functionIndex;

        groupIndex = gRaceHudSubScreenCellGroups->mGroupCount++;
        for (functionIndex = 0;
             gRaceHudSubScreenCellGroupFunctions[functionIndex].mCreate != CreateRaceHudSubScreenBoundCells &&
             functionIndex < 49;
             functionIndex++) {
        }
        if (functionIndex < 49) {
            gRaceHudSubScreenCellGroups->mClearFunctions[groupIndex] =
                gRaceHudSubScreenCellGroupFunctions[functionIndex].mClear;
            gRaceHudSubScreenCellGroups->mUpdateFunctions[groupIndex] =
                gRaceHudSubScreenCellGroupFunctions[functionIndex].mUpdate;
            gRaceHudSubScreenCellGroups->mDrawFunctions[groupIndex] =
                gRaceHudSubScreenCellGroupFunctions[functionIndex].mDraw;
        }
    }
    if (CreateRaceHudSubScreenSunFireballCells()) {
        s32 groupIndex;
        s32 functionIndex;

        groupIndex = gRaceHudSubScreenCellGroups->mGroupCount++;
        for (functionIndex = 0;
             gRaceHudSubScreenCellGroupFunctions[functionIndex].mCreate != CreateRaceHudSubScreenSunFireballCells &&
             functionIndex < 49;
             functionIndex++) {
        }
        if (functionIndex < 49) {
            gRaceHudSubScreenCellGroups->mClearFunctions[groupIndex] =
                gRaceHudSubScreenCellGroupFunctions[functionIndex].mClear;
            gRaceHudSubScreenCellGroups->mUpdateFunctions[groupIndex] =
                gRaceHudSubScreenCellGroupFunctions[functionIndex].mUpdate;
            gRaceHudSubScreenCellGroups->mDrawFunctions[groupIndex] =
                gRaceHudSubScreenCellGroupFunctions[functionIndex].mDraw;
        }
    }
    if (CreateRaceHudSubScreenFireball2Cells()) {
        s32 groupIndex;
        s32 functionIndex;

        groupIndex = gRaceHudSubScreenCellGroups->mGroupCount++;
        for (functionIndex = 0;
             gRaceHudSubScreenCellGroupFunctions[functionIndex].mCreate != CreateRaceHudSubScreenFireball2Cells &&
             functionIndex < 49;
             functionIndex++) {
        }
        if (functionIndex < 49) {
            gRaceHudSubScreenCellGroups->mClearFunctions[groupIndex] =
                gRaceHudSubScreenCellGroupFunctions[functionIndex].mClear;
            gRaceHudSubScreenCellGroups->mUpdateFunctions[groupIndex] =
                gRaceHudSubScreenCellGroupFunctions[functionIndex].mUpdate;
            gRaceHudSubScreenCellGroups->mDrawFunctions[groupIndex] =
                gRaceHudSubScreenCellGroupFunctions[functionIndex].mDraw;
        }
    }
    if (CreateRaceHudSubScreenIronBallCells()) {
        s32 groupIndex;
        s32 functionIndex;

        groupIndex = gRaceHudSubScreenCellGroups->mGroupCount++;
        for (functionIndex = 0;
             gRaceHudSubScreenCellGroupFunctions[functionIndex].mCreate != CreateRaceHudSubScreenIronBallCells &&
             functionIndex < 49;
             functionIndex++) {
        }
        if (functionIndex < 49) {
            gRaceHudSubScreenCellGroups->mClearFunctions[groupIndex] =
                gRaceHudSubScreenCellGroupFunctions[functionIndex].mClear;
            gRaceHudSubScreenCellGroups->mUpdateFunctions[groupIndex] =
                gRaceHudSubScreenCellGroupFunctions[functionIndex].mUpdate;
            gRaceHudSubScreenCellGroups->mDrawFunctions[groupIndex] =
                gRaceHudSubScreenCellGroupFunctions[functionIndex].mDraw;
        }
    }
    if (CreateRaceHudSubScreenSanboCells()) {
        s32 groupIndex;
        s32 functionIndex;

        groupIndex = gRaceHudSubScreenCellGroups->mGroupCount++;
        for (functionIndex = 0;
             gRaceHudSubScreenCellGroupFunctions[functionIndex].mCreate != CreateRaceHudSubScreenSanboCells &&
             functionIndex < 49;
             functionIndex++) {
        }
        if (functionIndex < 49) {
            gRaceHudSubScreenCellGroups->mClearFunctions[groupIndex] =
                gRaceHudSubScreenCellGroupFunctions[functionIndex].mClear;
            gRaceHudSubScreenCellGroups->mUpdateFunctions[groupIndex] =
                gRaceHudSubScreenCellGroupFunctions[functionIndex].mUpdate;
            gRaceHudSubScreenCellGroups->mDrawFunctions[groupIndex] =
                gRaceHudSubScreenCellGroupFunctions[functionIndex].mDraw;
        }
    }
    if (CreateRaceHudSubScreenBasabasaCells()) {
        s32 groupIndex;
        s32 functionIndex;

        groupIndex = gRaceHudSubScreenCellGroups->mGroupCount++;
        for (functionIndex = 0;
             gRaceHudSubScreenCellGroupFunctions[functionIndex].mCreate != CreateRaceHudSubScreenBasabasaCells &&
             functionIndex < 49;
             functionIndex++) {
        }
        if (functionIndex < 49) {
            gRaceHudSubScreenCellGroups->mClearFunctions[groupIndex] =
                gRaceHudSubScreenCellGroupFunctions[functionIndex].mClear;
            gRaceHudSubScreenCellGroups->mUpdateFunctions[groupIndex] =
                gRaceHudSubScreenCellGroupFunctions[functionIndex].mUpdate;
            gRaceHudSubScreenCellGroups->mDrawFunctions[groupIndex] =
                gRaceHudSubScreenCellGroupFunctions[functionIndex].mDraw;
        }
    }
    if (CreateRaceHudSubScreenPakkunSpitCells()) {
        s32 groupIndex;
        s32 functionIndex;

        groupIndex = gRaceHudSubScreenCellGroups->mGroupCount++;
        for (functionIndex = 0;
             gRaceHudSubScreenCellGroupFunctions[functionIndex].mCreate != CreateRaceHudSubScreenPakkunSpitCells &&
             functionIndex < 49;
             functionIndex++) {
        }
        if (functionIndex < 49) {
            gRaceHudSubScreenCellGroups->mClearFunctions[groupIndex] =
                gRaceHudSubScreenCellGroupFunctions[functionIndex].mClear;
            gRaceHudSubScreenCellGroups->mUpdateFunctions[groupIndex] =
                gRaceHudSubScreenCellGroupFunctions[functionIndex].mUpdate;
            gRaceHudSubScreenCellGroups->mDrawFunctions[groupIndex] =
                gRaceHudSubScreenCellGroupFunctions[functionIndex].mDraw;
        }
    }
    if (CreateRaceHudSubScreenBerryCells()) {
        s32 groupIndex;
        s32 functionIndex;

        groupIndex = gRaceHudSubScreenCellGroups->mGroupCount++;
        for (functionIndex = 0;
             gRaceHudSubScreenCellGroupFunctions[functionIndex].mCreate != CreateRaceHudSubScreenBerryCells &&
             functionIndex < 49;
             functionIndex++) {
        }
        if (functionIndex < 49) {
            gRaceHudSubScreenCellGroups->mClearFunctions[groupIndex] =
                gRaceHudSubScreenCellGroupFunctions[functionIndex].mClear;
            gRaceHudSubScreenCellGroups->mUpdateFunctions[groupIndex] =
                gRaceHudSubScreenCellGroupFunctions[functionIndex].mUpdate;
            gRaceHudSubScreenCellGroups->mDrawFunctions[groupIndex] =
                gRaceHudSubScreenCellGroupFunctions[functionIndex].mDraw;
        }
    }
    if (CreateRaceHudSubScreenCreamCells()) {
        s32 groupIndex;
        s32 functionIndex;

        groupIndex = gRaceHudSubScreenCellGroups->mGroupCount++;
        for (functionIndex = 0;
             gRaceHudSubScreenCellGroupFunctions[functionIndex].mCreate != CreateRaceHudSubScreenCreamCells &&
             functionIndex < 49;
             functionIndex++) {
        }
        if (functionIndex < 49) {
            gRaceHudSubScreenCellGroups->mClearFunctions[groupIndex] =
                gRaceHudSubScreenCellGroupFunctions[functionIndex].mClear;
            gRaceHudSubScreenCellGroups->mUpdateFunctions[groupIndex] =
                gRaceHudSubScreenCellGroupFunctions[functionIndex].mUpdate;
            gRaceHudSubScreenCellGroups->mDrawFunctions[groupIndex] =
                gRaceHudSubScreenCellGroupFunctions[functionIndex].mDraw;
        }
    }
    if (gRaceSetup->mMode != MODE_MISSION_RUN) {
        return;
    }
    if (CreateRaceHudSubScreenCoinCells()) {
        s32 groupIndex;
        s32 functionIndex;

        groupIndex = gRaceHudSubScreenCellGroups->mGroupCount++;
        for (functionIndex = 0;
             gRaceHudSubScreenCellGroupFunctions[functionIndex].mCreate != CreateRaceHudSubScreenCoinCells &&
             functionIndex < 49;
             functionIndex++) {
        }
        if (functionIndex < 49) {
            gRaceHudSubScreenCellGroups->mClearFunctions[groupIndex] =
                gRaceHudSubScreenCellGroupFunctions[functionIndex].mClear;
            gRaceHudSubScreenCellGroups->mUpdateFunctions[groupIndex] =
                gRaceHudSubScreenCellGroupFunctions[functionIndex].mUpdate;
            gRaceHudSubScreenCellGroups->mDrawFunctions[groupIndex] =
                gRaceHudSubScreenCellGroupFunctions[functionIndex].mDraw;
        }
    }
    if (CreateRaceHudSubScreenMissionGateCells()) {
        s32 groupIndex;
        s32 functionIndex;

        groupIndex = gRaceHudSubScreenCellGroups->mGroupCount++;
        for (functionIndex = 0;
             gRaceHudSubScreenCellGroupFunctions[functionIndex].mCreate != CreateRaceHudSubScreenMissionGateCells &&
             functionIndex < 49;
             functionIndex++) {
        }
        if (functionIndex < 49) {
            gRaceHudSubScreenCellGroups->mClearFunctions[groupIndex] =
                gRaceHudSubScreenCellGroupFunctions[functionIndex].mClear;
            gRaceHudSubScreenCellGroups->mUpdateFunctions[groupIndex] =
                gRaceHudSubScreenCellGroupFunctions[functionIndex].mUpdate;
            gRaceHudSubScreenCellGroups->mDrawFunctions[groupIndex] =
                gRaceHudSubScreenCellGroupFunctions[functionIndex].mDraw;
        }
    }
    if (CreateRaceHudSubScreenStopSignCells()) {
        s32 groupIndex;
        s32 functionIndex;

        groupIndex = gRaceHudSubScreenCellGroups->mGroupCount++;
        for (functionIndex = 0;
             gRaceHudSubScreenCellGroupFunctions[functionIndex].mCreate != CreateRaceHudSubScreenStopSignCells &&
             functionIndex < 49;
             functionIndex++) {
        }
        if (functionIndex < 49) {
            gRaceHudSubScreenCellGroups->mClearFunctions[groupIndex] =
                gRaceHudSubScreenCellGroupFunctions[functionIndex].mClear;
            gRaceHudSubScreenCellGroups->mUpdateFunctions[groupIndex] =
                gRaceHudSubScreenCellGroupFunctions[functionIndex].mUpdate;
            gRaceHudSubScreenCellGroups->mDrawFunctions[groupIndex] =
                gRaceHudSubScreenCellGroupFunctions[functionIndex].mDraw;
        }
    }
    if (CreateRaceHudSubScreenBossDonketuCells()) {
        s32 groupIndex;
        s32 functionIndex;

        groupIndex = gRaceHudSubScreenCellGroups->mGroupCount++;
        for (functionIndex = 0;
             gRaceHudSubScreenCellGroupFunctions[functionIndex].mCreate != CreateRaceHudSubScreenBossDonketuCells &&
             functionIndex < 49;
             functionIndex++) {
        }
        if (functionIndex < 49) {
            gRaceHudSubScreenCellGroups->mClearFunctions[groupIndex] =
                gRaceHudSubScreenCellGroupFunctions[functionIndex].mClear;
            gRaceHudSubScreenCellGroups->mUpdateFunctions[groupIndex] =
                gRaceHudSubScreenCellGroupFunctions[functionIndex].mUpdate;
            gRaceHudSubScreenCellGroups->mDrawFunctions[groupIndex] =
                gRaceHudSubScreenCellGroupFunctions[functionIndex].mDraw;
        }
    }
    if (CreateRaceHudSubScreenKingIceDonketuCells()) {
        s32 groupIndex;
        s32 functionIndex;

        groupIndex = gRaceHudSubScreenCellGroups->mGroupCount++;
        for (functionIndex = 0;
             gRaceHudSubScreenCellGroupFunctions[functionIndex].mCreate != CreateRaceHudSubScreenKingIceDonketuCells &&
             functionIndex < 49;
             functionIndex++) {
        }
        if (functionIndex < 49) {
            gRaceHudSubScreenCellGroups->mClearFunctions[groupIndex] =
                gRaceHudSubScreenCellGroupFunctions[functionIndex].mClear;
            gRaceHudSubScreenCellGroups->mUpdateFunctions[groupIndex] =
                gRaceHudSubScreenCellGroupFunctions[functionIndex].mUpdate;
            gRaceHudSubScreenCellGroups->mDrawFunctions[groupIndex] =
                gRaceHudSubScreenCellGroupFunctions[functionIndex].mDraw;
        }
    }
    if (CreateRaceHudSubScreenKurikingCells()) {
        s32 groupIndex;
        s32 functionIndex;

        groupIndex = gRaceHudSubScreenCellGroups->mGroupCount++;
        for (functionIndex = 0;
             gRaceHudSubScreenCellGroupFunctions[functionIndex].mCreate != CreateRaceHudSubScreenKurikingCells &&
             functionIndex < 49;
             functionIndex++) {
        }
        if (functionIndex < 49) {
            gRaceHudSubScreenCellGroups->mClearFunctions[groupIndex] =
                gRaceHudSubScreenCellGroupFunctions[functionIndex].mClear;
            gRaceHudSubScreenCellGroups->mUpdateFunctions[groupIndex] =
                gRaceHudSubScreenCellGroupFunctions[functionIndex].mUpdate;
            gRaceHudSubScreenCellGroups->mDrawFunctions[groupIndex] =
                gRaceHudSubScreenCellGroupFunctions[functionIndex].mDraw;
        }
    }
    if (CreateRaceHudSubScreenBombKingCells()) {
        s32 groupIndex;
        s32 functionIndex;

        groupIndex = gRaceHudSubScreenCellGroups->mGroupCount++;
        for (functionIndex = 0;
             gRaceHudSubScreenCellGroupFunctions[functionIndex].mCreate != CreateRaceHudSubScreenBombKingCells &&
             functionIndex < 49;
             functionIndex++) {
        }
        if (functionIndex < 49) {
            gRaceHudSubScreenCellGroups->mClearFunctions[groupIndex] =
                gRaceHudSubScreenCellGroupFunctions[functionIndex].mClear;
            gRaceHudSubScreenCellGroups->mUpdateFunctions[groupIndex] =
                gRaceHudSubScreenCellGroupFunctions[functionIndex].mUpdate;
            gRaceHudSubScreenCellGroups->mDrawFunctions[groupIndex] =
                gRaceHudSubScreenCellGroupFunctions[functionIndex].mDraw;
        }
    }
    if (CreateRaceHudSubScreenIwanteCells()) {
        s32 groupIndex;
        s32 functionIndex;

        groupIndex = gRaceHudSubScreenCellGroups->mGroupCount++;
        for (functionIndex = 0;
             gRaceHudSubScreenCellGroupFunctions[functionIndex].mCreate != CreateRaceHudSubScreenIwanteCells &&
             functionIndex < 49;
             functionIndex++) {
        }
        if (functionIndex < 49) {
            gRaceHudSubScreenCellGroups->mClearFunctions[groupIndex] =
                gRaceHudSubScreenCellGroupFunctions[functionIndex].mClear;
            gRaceHudSubScreenCellGroups->mUpdateFunctions[groupIndex] =
                gRaceHudSubScreenCellGroupFunctions[functionIndex].mUpdate;
            gRaceHudSubScreenCellGroups->mDrawFunctions[groupIndex] =
                gRaceHudSubScreenCellGroupFunctions[functionIndex].mDraw;
        }
    }
    if (CreateRaceHudSubScreenHanachanCells()) {
        s32 groupIndex;
        s32 tableIndex;

        groupIndex = gRaceHudSubScreenCellGroups->mGroupCount++;
        for (tableIndex = 0;
             gRaceHudSubScreenCellGroupFunctions[tableIndex].mCreate != CreateRaceHudSubScreenHanachanCells &&
             tableIndex < 49;
             tableIndex++) {
        }
        if (tableIndex < 49) {
            gRaceHudSubScreenCellGroups->mClearFunctions[groupIndex] =
                gRaceHudSubScreenCellGroupFunctions[tableIndex].mClear;
            gRaceHudSubScreenCellGroups->mUpdateFunctions[groupIndex] =
                gRaceHudSubScreenCellGroupFunctions[tableIndex].mUpdate;
            gRaceHudSubScreenCellGroups->mDrawFunctions[groupIndex] =
                gRaceHudSubScreenCellGroupFunctions[tableIndex].mDraw;
        }
    }
    if (CreateRaceHudSubScreenKingTeresaCells()) {
        s32 groupIndex;
        s32 tableIndex;

        groupIndex = gRaceHudSubScreenCellGroups->mGroupCount++;
        for (tableIndex = 0;
             gRaceHudSubScreenCellGroupFunctions[tableIndex].mCreate != CreateRaceHudSubScreenKingTeresaCells &&
             tableIndex < 49;
             tableIndex++) {
        }
        if (tableIndex < 49) {
            gRaceHudSubScreenCellGroups->mClearFunctions[groupIndex] =
                gRaceHudSubScreenCellGroupFunctions[tableIndex].mClear;
            gRaceHudSubScreenCellGroups->mUpdateFunctions[groupIndex] =
                gRaceHudSubScreenCellGroupFunctions[tableIndex].mUpdate;
            gRaceHudSubScreenCellGroups->mDrawFunctions[groupIndex] =
                gRaceHudSubScreenCellGroupFunctions[tableIndex].mDraw;
        }
    }
}

void ClearRaceHudSubScreenCellGroups(void) {
    s32 groupIndex;

    for (groupIndex = 0; groupIndex < gRaceHudSubScreenCellGroups->mGroupCount; groupIndex++) {
        gRaceHudSubScreenCellGroups->mClearFunctions[groupIndex]();
    }
    gRaceHudSubScreenCellGroups = NULL;
}

void UpdateRaceHudSubScreenCellGroups(void) {
    Vec3 followedKartPosition;
    s32 groupIndex;
    s32 roundedProduct;
    float productWithHalf;

    switch (GetRaceHudSubScreenState()) {
        case RACE_HUD_SUB_SCREEN_KART_ICONS:
            UpdateRaceHudSubScreenKarts();
            break;
        case RACE_HUD_SUB_SCREEN_MAP_TURNING:
        case RACE_HUD_SUB_SCREEN_MAP_FIXED_SCROLL:
        case RACE_HUD_SUB_SCREEN_MAP_VIEW:
            if (GetRaceHudSubScreenCourseScale() * 3 > 0) {
                productWithHalf = 0.5f + (GetRaceHudSubScreenCourseScale() * 0x3000);
            } else {
                productWithHalf = (GetRaceHudSubScreenCourseScale() * 0x3000) - 0.5f;
            }
            roundedProduct = productWithHalf;
            gRaceHudSubScreenCellGroups->mScale = MUL_FIXED12_NO_ROUND(roundedProduct, 20);
            gRaceHudSubScreenCellGroups->mInverseScale = FX_Div(0x2400, gRaceHudSubScreenCellGroups->mScale);
            UpdateRaceHudSubScreenProjectionAndBgAffine(GetRaceHudSubScreenBgAffine(),
                                                        gRaceHudSubScreenCellGroups->mScale);
            GetKartPosFromPosSourceCopy(&followedKartPosition, GetFollowedKartOrEntryIndex());
            gRaceHudSubScreenCellGroups->mMinDrawValue = IsPositionOutsideBox(&followedKartPosition) != 0 ? 0 : 3;
            for (groupIndex = 0; groupIndex < gRaceHudSubScreenCellGroups->mGroupCount; groupIndex++) {
                gRaceHudSubScreenCellGroups->mUpdateFunctions[groupIndex]();
            }
            break;
    }
}

void DrawRaceHudSubScreenCellGroups(RaceHudOamBuffer *oamBuffer) {
    s32 groupIndex;

    switch (GetRaceHudSubScreenState()) {
        case RACE_HUD_SUB_SCREEN_KART_ICONS:
            DrawRaceHudSubScreenKarts(oamBuffer);
            break;
        case RACE_HUD_SUB_SCREEN_MAP_TURNING:
        case RACE_HUD_SUB_SCREEN_MAP_FIXED_SCROLL:
        case RACE_HUD_SUB_SCREEN_MAP_VIEW:
            for (groupIndex = 0; groupIndex < gRaceHudSubScreenCellGroups->mGroupCount; groupIndex++) {
                gRaceHudSubScreenCellGroups->mDrawFunctions[groupIndex](oamBuffer);
            }
            break;
    }
}
