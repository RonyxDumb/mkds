#include "Main/Unknown/code_020be950.h"
#include "Main/Unknown/code_02036820.h"
#include "Main/Unknown/code_020ade08.h"
#include "Main/Unknown/code_020ae730.h"

#include "Main/Unknown/code_020b1cf4.h"
#include "Main/Unknown/code_020b1dbc.h"
#include "Main/Unknown/code_020b4000.h"
#include "Main/Unknown/code_0207b960.h"
#include "Main/Unknown/code_020b4e5c.h"
#include "Main/Unknown/code_02039860.h"
#include "Main/Unknown/code_02147000.h"
#include "Main/Unknown/unk_0215d000.h"
#include "Main/Unknown/unk_021759c0.h"
#include "Main/Unknown/code_020b47d8.h"
#include "Main/Unknown/code_020b6a18.h"
#include "Main/Unknown/code_0207a880.h"
#include "Main/Unknown/code_020b502c.h"
#include "Main/Unknown/code_020c7464.h"
#include "Main/Unknown/code_020c8000.h"
#include "Main/Unknown/code_020c9000.h"
#include "code_02147cd8.h"
#include "Main/Unknown/code_020ca534.h"
#include "Main/Unknown/code_020ca670.h"
#include "Main/Unknown/code_020cccd8.h"
#include "Main/Unknown/code_020ce6a8.h"
#include "Main/Unknown/code_020cee0c.h"
#include "Main/Unknown/code_020cf310.h"
#include "Main/Unknown/code_020ae000.h"
#include "Main/Unknown/code_020cffd0.h"
#include "Main/Unknown/code_020d0e3c.h"
#include "Main/Unknown/unk_0217b000.h"
#include "Main/Unknown/code_020beb9c.h"
#include "Main/Unknown/code_020c7000.h"
#include "Main/Unknown/code_020ca000.h"
#include "Main/Unknown/code_020cc000.h"
#include "Main/Unknown/code_020cd000.h"
#include "Main/Unknown/code_020ce000.h"
#include "Main/Unknown/code_020cf000.h"
#include "Main/Unknown/code_020d0000.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_020364e0.h"
#include "Main/Unknown/unk_02169000.h"
#include "01/code_021892ac.h"
#include "01/code_02188e88.h"
#include "Main/Unknown/code_020c06c4.h"
#include "code_020222ec.h"
#include "Main/Unknown/code_020c0b84.h"
#include "Main/Unknown/code_020c0ba8.h"
#include "Main/Unknown/code_02100084.h"
#include "Main/Unknown/code_02100094.h"
#include "Main/Unknown/code_021000c8.h"
#include "Main/Unknown/code_021000d0.h"
#include "Main/Unknown/code_020c0d9c.h"
#include "01/code_021813f4.h"
#include "Main/Unknown/code_02077bc0.h"

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
    *outCells = HeapAlloc(GetHeap(GetCurrentHeapCall()), 0x14);
    if (fromUpdateList != FALSE) {
        (*outCells)->mObjects = (MapObject **) GetMapObjects(updateList);
    } else {
        (*outCells)->mObjects = RaceHudSubScreenGetMapObjects(drawList);
    }
    (*outCells)->mCellCount = 0;
    (*outCells)->mObjectCount = objectCount;
    (*outCells)->mUnk_0c = HeapAlloc(GetHeap(GetCurrentHeapCall()), objectCount * 8);
    for (objectIndex = 0; objectIndex < objectCount; objectIndex++) {
        ComputeRaceHudSubScreenCoursePosition(&(*outCells)->mObjects[objectIndex]->mPos,
                                              &(*outCells)->mUnk_0c[objectIndex]);
    }
    (*outCells)->mCells = AllocArrayFromCurrentHeap(objectCount * 2, 0x14);
    return TRUE;
}

BOOL CreateRaceHudSubScreenCellsWithCount(RaceHudSubScreenCells **outCells, s32 objectCount) {
    if (objectCount == 0) {
        return FALSE;
    }
    *outCells = HeapAlloc(GetHeap(GetCurrentHeapCall()), 0x14);
    (*outCells)->mCellCount = 0;
    (*outCells)->mObjectCount = objectCount;
    (*outCells)->mUnk_0c = HeapAlloc(GetHeap(GetCurrentHeapCall()), objectCount * 8);
    (*outCells)->mCells = AllocArrayFromCurrentHeap(objectCount, 0x14);
    return TRUE;
}

void ClearRaceHudSubScreenCells(RaceHudSubScreenCells **cellsPointerAddress) {
    (*cellsPointerAddress)->mObjects = NULL;
    (*cellsPointerAddress)->mUnk_0c = NULL;
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
            flag = cells->mCells[cellIndex].mUnk_0e;
            matrixIndex = 0;
            if (useRotation != 0) {
                if (gRaceSetup->mMirrorMode != 0) {
                    Matrix2x2Rotation(&rotationMatrix, (u16) (cells->mCells[cellIndex].mAngle + 0x8000 - angle));
                } else {
                    Matrix2x2Rotation(&rotationMatrix, (u16) (angle + (0x8000 - cells->mCells[cellIndex].mAngle)));
                }
                matrixIndex = AllocOamMatrixIndex(oamBuffer);
                oamBuffer->mMatrices[matrixIndex].mPA = rotationMatrix.mUnk_00[0] >> 4;
                oamBuffer->mMatrices[matrixIndex].mPB = rotationMatrix.mUnk_00[1] >> 4;
                oamBuffer->mMatrices[matrixIndex].mPC = rotationMatrix.mUnk_00[2] >> 4;
                oamBuffer->mMatrices[matrixIndex].mPD = rotationMatrix.mUnk_00[3] >> 4;
            }
            cell = &cells->mCells[cellIndex];
            screenX = cell->mDrawPos.mFirst;
            cellData = cell->mCell;
            screenY = cell->mDrawPos.mSecond;
            oamIndex = oamBuffer->mOamCount;
            drawPosition[0] = screenX << 12;
            drawPosition[1] = screenY << 12;
            oamBuffer->mOamCount +=
                NNS_G2dMakeCellToOams(&oamBuffer->mOams[oamIndex], 0x80 - oamIndex, cellData,
                                      useRotation != 0 ? &rotationMatrix : 0, drawPosition, matrixIndex, 1);
            oam = &oamBuffer->mOamBits[oamIndex];
            for (; oamIndex < oamBuffer->mOamCount; oamIndex++, oam++) {
                if ((flag != 0 ? 1 : -1) != -1) {
                    oam->mUnk_0a = flag != 0 ? 1 : -1;
                }
                if (priority != -1) {
                    oam->mUnk_0e = priority;
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
            flag = cells->mCells[cellIndex].mUnk_0e;
            if (useRotation != 0) {
                if (gRaceSetup->mMirrorMode != 0) {
                    Matrix2x2RotationReciprocalScale(&matrix, cells->mUnk_0c[cellIndex].mFirst,
                                                     (u16) (cells->mCells[cellIndex].mAngle - angle));
                } else {
                    Matrix2x2RotationReciprocalScale(&matrix, cells->mUnk_0c[cellIndex].mFirst,
                                                     (u16) (angle - cells->mCells[cellIndex].mAngle));
                }
            } else {
                Matrix2x2ReciprocalScale(&matrix, cells->mUnk_0c[cellIndex].mFirst);
            }
            matrixIndex = AllocOamMatrixIndex(oamBuffer);
            oamBuffer->mMatrices[matrixIndex].mPA = matrix.mUnk_00[0] >> 4;
            oamBuffer->mMatrices[matrixIndex].mPB = matrix.mUnk_00[1] >> 4;
            oamBuffer->mMatrices[matrixIndex].mPC = matrix.mUnk_00[2] >> 4;
            oamBuffer->mMatrices[matrixIndex].mPD = matrix.mUnk_00[3] >> 4;
            cell = &cells->mCells[cellIndex];
            screenX = cell->mDrawPos.mFirst;
            cellData = cell->mCell;
            screenY = cell->mDrawPos.mSecond;
            oamIndex = oamBuffer->mOamCount;
            drawPosition[0] = screenX << 12;
            drawPosition[1] = screenY << 12;
            oamBuffer->mOamCount += NNS_G2dMakeCellToOams(&oamBuffer->mOams[oamIndex], 0x80 - oamIndex, cellData,
                                                          &matrix, drawPosition, matrixIndex, 1);
            oam = &oamBuffer->mOamBits[oamIndex];
            for (; oamIndex < oamBuffer->mOamCount; oamIndex++, oam++) {
                if ((flag != 0 ? 1 : -1) != -1) {
                    oam->mUnk_0a = flag != 0 ? 1 : -1;
                }
                if (priority != -1) {
                    oam->mUnk_0e = priority;
                }
            }
        }
    }
}

void InitRaceHudSubScreenCellGroups(void) {
    gRaceHudSubScreenCellGroups = HeapAlloc(GetHeap(GetCurrentHeapCall()), 0x25c);
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
    if (func_ov001_02189128()) {
        s32 groupIndex;
        s32 tableIndex;

        groupIndex = gRaceHudSubScreenCellGroups->mGroupCount++;
        for (tableIndex = 0;
             gRaceHudSubScreenCellGroupFunctions[tableIndex].mCreate != func_ov001_02189128 && tableIndex < 49;
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
        case 0:
            UpdateRaceHudSubScreenKarts();
            break;
        case 1:
        case 2:
        case 3:
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

void DrawRaceHudSubScreenCellGroups(void *oamBuffer) {
    s32 groupIndex;

    switch (GetRaceHudSubScreenState()) {
        case 0:
            DrawRaceHudSubScreenKarts(oamBuffer);
            break;
        case 1:
        case 2:
        case 3:
            for (groupIndex = 0; groupIndex < gRaceHudSubScreenCellGroups->mGroupCount; groupIndex++) {
                gRaceHudSubScreenCellGroups->mDrawFunctions[groupIndex](oamBuffer);
            }
            break;
    }
}
