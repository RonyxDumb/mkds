#include "Main/Unknown/code_020be950.h"
#include "Main/System/Heap.h"
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
#include "Main/Race/RaceHudSubScreen.h"
#include "Main/Unknown/code_020c8000.h"
#include "Main/Unknown/code_020c9000.h"
#include "code_02147cd8.h"
#include "Main/Unknown/code_020ca534.h"
#include "Main/Unknown/code_020ca670.h"
#include "Main/Race/RaceHudSubScreenObjects.h"
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
#include "01/RaceHudSubScreenMissionObjects.h"
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

u32 mpicn_getMinPriority(void) {
    return (mpicn_sIconData->field0);
}

u32 mpicn_20C0DB0(void) {
    return (mpicn_sIconData->mScale);
}

u32 mpicn_20C0D9C(void) {
    return (mpicn_sIconData->field8);
}

BOOL mpicn_createMapObjIcon(RaceHudSubScreenCells **outCells, s32 kind) {
    BOOL fromUpdateList;
    void *drawList;
    void *updateList;
    s32 i;
    s32 objectCount;

    fromUpdateList = FALSE;
    drawList = mobj_getRenderPart0ForObjectId(kind);
    updateList = mobj_getLogicPartForObjectId(kind);
    if (kind == MAP_OBJECT_KIND_SUN_FIREBALL || kind == 0x1ab) {
        fromUpdateList = TRUE;
    }
    if (fromUpdateList != FALSE) {
        if (updateList == NULL) {
            return FALSE;
        }
        objectCount = mobj_logicPartGetInstanceCount(updateList);
        if (objectCount == 0) {
            return FALSE;
        }
    } else {
        if (drawList == NULL) {
            return FALSE;
        }
        objectCount = func_02100094(drawList);
        if (objectCount == 0) {
            return FALSE;
        }
    }
    *outCells = heap_alloc(proc_getHeap(proc_getCurrent()), 0x14);
    if (fromUpdateList != FALSE) {
        (*outCells)->mObjects = (Unk0217b498_00 **) mobj_logicPartGetInstanceList(updateList);
    } else {
        (*outCells)->mObjects = mobj_renderPartGetInstanceList(drawList);
    }
    (*outCells)->mCellCount = 0;
    (*outCells)->mObjectCount = objectCount;
    (*outCells)->fieldC = heap_alloc(proc_getHeap(proc_getCurrent()), objectCount * 8);
    for (i = 0; i < objectCount; i++) {
        ComputeRaceHudSubScreenCoursePosition(&(*outCells)->mObjects[i]->mPos, &(*outCells)->fieldC[i]);
    }
    (*outCells)->mCells = AllocArrayFromCurrentHeap(objectCount * 2, 0x14);
    return TRUE;
}

BOOL mpicn_20C0BA8(RaceHudSubScreenCells **outCells, s32 objectCount) {
    if (objectCount == 0) {
        return FALSE;
    }
    *outCells = heap_alloc(proc_getHeap(proc_getCurrent()), 0x14);
    (*outCells)->mCellCount = 0;
    (*outCells)->mObjectCount = objectCount;
    (*outCells)->fieldC = heap_alloc(proc_getHeap(proc_getCurrent()), objectCount * 8);
    (*outCells)->mCells = AllocArrayFromCurrentHeap(objectCount, 0x14);
    return TRUE;
}

void mpicn_destroyMObjIcon(RaceHudSubScreenCells **cellsPointerAddress) {
    (*cellsPointerAddress)->mObjects = NULL;
    (*cellsPointerAddress)->fieldC = NULL;
    (*cellsPointerAddress)->mCells = NULL;
    *cellsPointerAddress = NULL;
}

void mpicn_renderMObjIcon(RaceHudOamBuffer *oamBuffer, RaceHudSubScreenCells *cells, s32 useRotation) {
    s32 i;
    s32 l;
    u16 angle;
    u16 matrixIndex;
    s32 rotationMatrix[4];
    s32 drawPosition[2];
    s32 p;
    s32 q;
    s32 oamIndex;
    RaceHudOamBits *oam;
    RaceHudSubScreenCell *cell;
    s32 screenX;
    s32 screenY;
    void *cellData;

    l = mpicn_sIconData->field0;
    if (useRotation != 0) {
        angle = m2d_20B6368();
    }
    for (i = 0; i < cells->mCellCount; i++) {
        p = cells->mCells[i].fieldC;
        if (l <= p) {
            q = cells->mCells[i].fieldE;
            matrixIndex = 0;
            if (useRotation != 0) {
                if (gRaceMultiConfig->mMirrorMode != 0) {
                    lmap_rotMtx22(rotationMatrix, (u16) (cells->mCells[i].field10 + 0x8000 - angle));
                } else {
                    lmap_rotMtx22(rotationMatrix, (u16) (angle + (0x8000 - cells->mCells[i].field10)));
                }
                matrixIndex = oam_getAffineId(oamBuffer);
                oamBuffer->mMatrices[matrixIndex].field6 = rotationMatrix[0] >> 4;
                oamBuffer->mMatrices[matrixIndex].fieldE = rotationMatrix[1] >> 4;
                oamBuffer->mMatrices[matrixIndex].field16 = rotationMatrix[2] >> 4;
                oamBuffer->mMatrices[matrixIndex].field1E = rotationMatrix[3] >> 4;
            }
            cell = &cells->mCells[i];
            screenX = cell->mDrawPos.field0;
            cellData = cell->mCell;
            screenY = cell->mDrawPos.field4;
            oamIndex = oamBuffer->mOamCount;
            drawPosition[0] = screenX << 12;
            drawPosition[1] = screenY << 12;
            oamBuffer->mOamCount +=
                NNS_G2dMakeCellToOams(&oamBuffer->mOams[oamIndex], 0x80 - oamIndex, cellData,
                                      useRotation != 0 ? rotationMatrix : 0, drawPosition, matrixIndex, 1);
            oam = &oamBuffer->mOamBits[oamIndex];
            for (; oamIndex < oamBuffer->mOamCount; oamIndex++, oam++) {
                if ((q != 0 ? 1 : -1) != -1) {
                    oam->fieldA = q != 0 ? 1 : -1;
                }
                if (p != -1) {
                    oam->fieldE = p;
                }
            }
        }
    }
}

void mpicn_20C06C4(RaceHudOamBuffer *oamBuffer, RaceHudSubScreenCells *cells, s32 useRotation) {
    s32 i;
    s32 l;
    u16 angle;
    s32 matrix[4];
    s32 drawPosition[2];
    s32 p;
    s32 q;
    s32 oamIndex;
    u16 matrixIndex;
    RaceHudOamBits *oam;
    RaceHudSubScreenCell *cell;
    s32 screenX;
    s32 screenY;
    void *cellData;

    l = mpicn_sIconData->field0;
    if (useRotation != 0) {
        angle = m2d_20B6368();
    }
    for (i = 0; i < cells->mCellCount; i++) {
        p = cells->mCells[i].fieldC;
        if (l <= p) {
            q = cells->mCells[i].fieldE;
            if (useRotation != 0) {
                if (gRaceMultiConfig->mMirrorMode != 0) {
                    lmap_rotScaleMtx22(matrix, cells->fieldC[i].field0,
                                                     (u16) (cells->mCells[i].field10 - angle));
                } else {
                    lmap_rotScaleMtx22(matrix, cells->fieldC[i].field0,
                                                     (u16) (angle - cells->mCells[i].field10));
                }
            } else {
                lmap_scaleMtx22(matrix, cells->fieldC[i].field0);
            }
            matrixIndex = oam_getAffineId(oamBuffer);
            oamBuffer->mMatrices[matrixIndex].field6 = matrix[0] >> 4;
            oamBuffer->mMatrices[matrixIndex].fieldE = matrix[1] >> 4;
            oamBuffer->mMatrices[matrixIndex].field16 = matrix[2] >> 4;
            oamBuffer->mMatrices[matrixIndex].field1E = matrix[3] >> 4;
            cell = &cells->mCells[i];
            screenX = cell->mDrawPos.field0;
            cellData = cell->mCell;
            screenY = cell->mDrawPos.field4;
            oamIndex = oamBuffer->mOamCount;
            drawPosition[0] = screenX << 12;
            drawPosition[1] = screenY << 12;
            oamBuffer->mOamCount += NNS_G2dMakeCellToOams(&oamBuffer->mOams[oamIndex], 0x80 - oamIndex, cellData,
                                                          matrix, drawPosition, matrixIndex, 1);
            oam = &oamBuffer->mOamBits[oamIndex];
            for (; oamIndex < oamBuffer->mOamCount; oamIndex++, oam++) {
                if ((q != 0 ? 1 : -1) != -1) {
                    oam->fieldA = q != 0 ? 1 : -1;
                }
                if (p != -1) {
                    oam->fieldE = p;
                }
            }
        }
    }
}

void mpicn_init(void) {
    mpicn_sIconData = heap_alloc(proc_getHeap(proc_getCurrent()), 0x25c);
    mpicn_sIconData->field0 = 0;
    mpicn_sIconData->mScale = 0;
    mpicn_sIconData->field8 = 0;
    mpicn_sIconData->mGroupCount = 0;
    if (mpicn_createDriverIcon()) {
        s32 groupIndex;
        s32 i;

        groupIndex = mpicn_sIconData->mGroupCount++;
        for (i = 0; mpicn_sIconDefs[i].mCreate != mpicn_createDriverIcon && i < 49; i++) {
        }
        if (i < 49) {
            mpicn_sIconData->mClearFunctions[groupIndex] = mpicn_sIconDefs[i].mClear;
            mpicn_sIconData->mUpdateFunctions[groupIndex] = mpicn_sIconDefs[i].mUpdate;
            mpicn_sIconData->mDrawFunctions[groupIndex] = mpicn_sIconDefs[i].mDraw;
        }
    }
    if (mpicn_createItemIcon()) {
        s32 groupIndex;
        s32 i;

        groupIndex = mpicn_sIconData->mGroupCount++;
        for (i = 0; mpicn_sIconDefs[i].mCreate != mpicn_createItemIcon && i < 49; i++) {
        }
        if (i < 49) {
            mpicn_sIconData->mClearFunctions[groupIndex] = mpicn_sIconDefs[i].mClear;
            mpicn_sIconData->mUpdateFunctions[groupIndex] = mpicn_sIconDefs[i].mUpdate;
            mpicn_sIconData->mDrawFunctions[groupIndex] = mpicn_sIconDefs[i].mDraw;
        }
    }
    if (mpicn_createExplosionIcon()) {
        s32 groupIndex;
        s32 i;

        groupIndex = mpicn_sIconData->mGroupCount++;
        for (i = 0; mpicn_sIconDefs[i].mCreate != mpicn_createExplosionIcon && i < 49;
             i++) {
        }
        if (i < 49) {
            mpicn_sIconData->mClearFunctions[groupIndex] = mpicn_sIconDefs[i].mClear;
            mpicn_sIconData->mUpdateFunctions[groupIndex] = mpicn_sIconDefs[i].mUpdate;
            mpicn_sIconData->mDrawFunctions[groupIndex] = mpicn_sIconDefs[i].mDraw;
        }
    }
    if (mpicn_createItemboxIcon()) {
        s32 groupIndex;
        s32 i;

        groupIndex = mpicn_sIconData->mGroupCount++;
        for (i = 0; mpicn_sIconDefs[i].mCreate != mpicn_createItemboxIcon && i < 49;
             i++) {
        }
        if (i < 49) {
            mpicn_sIconData->mClearFunctions[groupIndex] = mpicn_sIconDefs[i].mClear;
            mpicn_sIconData->mUpdateFunctions[groupIndex] = mpicn_sIconDefs[i].mUpdate;
            mpicn_sIconData->mDrawFunctions[groupIndex] = mpicn_sIconDefs[i].mDraw;
        }
    }
    if (mpicn_createEarthenPipeIcon()) {
        s32 groupIndex;
        s32 i;

        groupIndex = mpicn_sIconData->mGroupCount++;
        for (i = 0; mpicn_sIconDefs[i].mCreate != mpicn_createEarthenPipeIcon && i < 49;
             i++) {
        }
        if (i < 49) {
            mpicn_sIconData->mClearFunctions[groupIndex] = mpicn_sIconDefs[i].mClear;
            mpicn_sIconData->mUpdateFunctions[groupIndex] = mpicn_sIconDefs[i].mUpdate;
            mpicn_sIconData->mDrawFunctions[groupIndex] = mpicn_sIconDefs[i].mDraw;
        }
    }
    if (mpicn_createWanwanIcon()) {
        s32 groupIndex;
        s32 i;

        groupIndex = mpicn_sIconData->mGroupCount++;
        for (i = 0; mpicn_sIconDefs[i].mCreate != mpicn_createWanwanIcon && i < 49;
             i++) {
        }
        if (i < 49) {
            mpicn_sIconData->mClearFunctions[groupIndex] = mpicn_sIconDefs[i].mClear;
            mpicn_sIconData->mUpdateFunctions[groupIndex] = mpicn_sIconDefs[i].mUpdate;
            mpicn_sIconData->mDrawFunctions[groupIndex] = mpicn_sIconDefs[i].mDraw;
        }
    }
    if (mpicn_createDossunIcon()) {
        s32 groupIndex;
        s32 i;

        groupIndex = mpicn_sIconData->mGroupCount++;
        for (i = 0; mpicn_sIconDefs[i].mCreate != mpicn_createDossunIcon && i < 49;
             i++) {
        }
        if (i < 49) {
            mpicn_sIconData->mClearFunctions[groupIndex] = mpicn_sIconDefs[i].mClear;
            mpicn_sIconData->mUpdateFunctions[groupIndex] = mpicn_sIconDefs[i].mUpdate;
            mpicn_sIconData->mDrawFunctions[groupIndex] = mpicn_sIconDefs[i].mDraw;
        }
    }
    if (mpicn_createCrabIcon()) {
        s32 groupIndex;
        s32 i;

        groupIndex = mpicn_sIconData->mGroupCount++;
        for (i = 0; mpicn_sIconDefs[i].mCreate != mpicn_createCrabIcon && i < 49; i++) {
        }
        if (i < 49) {
            mpicn_sIconData->mClearFunctions[groupIndex] = mpicn_sIconDefs[i].mClear;
            mpicn_sIconData->mUpdateFunctions[groupIndex] = mpicn_sIconDefs[i].mUpdate;
            mpicn_sIconData->mDrawFunctions[groupIndex] = mpicn_sIconDefs[i].mDraw;
        }
    }
    if (mpicn_createSmanIcon()) {
        s32 groupIndex;
        s32 i;

        groupIndex = mpicn_sIconData->mGroupCount++;
        for (i = 0; mpicn_sIconDefs[i].mCreate != mpicn_createSmanIcon && i < 49; i++) {
        }
        if (i < 49) {
            mpicn_sIconData->mClearFunctions[groupIndex] = mpicn_sIconDefs[i].mClear;
            mpicn_sIconData->mUpdateFunctions[groupIndex] = mpicn_sIconDefs[i].mUpdate;
            mpicn_sIconData->mDrawFunctions[groupIndex] = mpicn_sIconDefs[i].mDraw;
        }
    }
    if (mpicn_createMoveTreeIcon()) {
        s32 groupIndex;
        s32 i;

        groupIndex = mpicn_sIconData->mGroupCount++;
        for (i = 0; mpicn_sIconDefs[i].mCreate != mpicn_createMoveTreeIcon && i < 49;
             i++) {
        }
        if (i < 49) {
            mpicn_sIconData->mClearFunctions[groupIndex] = mpicn_sIconDefs[i].mClear;
            mpicn_sIconData->mUpdateFunctions[groupIndex] = mpicn_sIconDefs[i].mUpdate;
            mpicn_sIconData->mDrawFunctions[groupIndex] = mpicn_sIconDefs[i].mDraw;
        }
    }
    if (mpicn_createPukupukuIcon()) {
        s32 groupIndex;
        s32 i;

        groupIndex = mpicn_sIconData->mGroupCount++;
        for (i = 0; mpicn_sIconDefs[i].mCreate != mpicn_createPukupukuIcon && i < 49;
             i++) {
        }
        if (i < 49) {
            mpicn_sIconData->mClearFunctions[groupIndex] = mpicn_sIconDefs[i].mClear;
            mpicn_sIconData->mUpdateFunctions[groupIndex] = mpicn_sIconDefs[i].mUpdate;
            mpicn_sIconData->mDrawFunctions[groupIndex] = mpicn_sIconDefs[i].mDraw;
        }
    }
    if (mpicn_createChoropuIcon()) {
        s32 groupIndex;
        s32 i;

        groupIndex = mpicn_sIconData->mGroupCount++;
        for (i = 0; mpicn_sIconDefs[i].mCreate != mpicn_createChoropuIcon && i < 49;
             i++) {
        }
        if (i < 49) {
            mpicn_sIconData->mClearFunctions[groupIndex] = mpicn_sIconDefs[i].mClear;
            mpicn_sIconData->mUpdateFunctions[groupIndex] = mpicn_sIconDefs[i].mUpdate;
            mpicn_sIconData->mDrawFunctions[groupIndex] = mpicn_sIconDefs[i].mDraw;
        }
    }
    if (mpicn_createCarTruckBusIcon()) {
        s32 groupIndex;
        s32 i;

        groupIndex = mpicn_sIconData->mGroupCount++;
        for (i = 0; mpicn_sIconDefs[i].mCreate != mpicn_createCarTruckBusIcon && i < 49; i++) {
        }
        if (i < 49) {
            mpicn_sIconData->mClearFunctions[groupIndex] = mpicn_sIconDefs[i].mClear;
            mpicn_sIconData->mUpdateFunctions[groupIndex] = mpicn_sIconDefs[i].mUpdate;
            mpicn_sIconData->mDrawFunctions[groupIndex] = mpicn_sIconDefs[i].mDraw;
        }
    }
    if (mpicn_createSecondHandIcon()) {
        s32 groupIndex;
        s32 i;

        groupIndex = mpicn_sIconData->mGroupCount++;
        for (i = 0; mpicn_sIconDefs[i].mCreate != mpicn_createSecondHandIcon && i < 49; i++) {
        }
        if (i < 49) {
            mpicn_sIconData->mClearFunctions[groupIndex] = mpicn_sIconDefs[i].mClear;
            mpicn_sIconData->mUpdateFunctions[groupIndex] = mpicn_sIconDefs[i].mUpdate;
            mpicn_sIconData->mDrawFunctions[groupIndex] = mpicn_sIconDefs[i].mDraw;
        }
    }
    if (mpicn_createShine16Icon()) {
        s32 groupIndex;
        s32 i;

        groupIndex = mpicn_sIconData->mGroupCount++;
        for (i = 0; mpicn_sIconDefs[i].mCreate != mpicn_createShine16Icon && i < 49;
             i++) {
        }
        if (i < 49) {
            mpicn_sIconData->mClearFunctions[groupIndex] = mpicn_sIconDefs[i].mClear;
            mpicn_sIconData->mUpdateFunctions[groupIndex] = mpicn_sIconDefs[i].mUpdate;
            mpicn_sIconData->mDrawFunctions[groupIndex] = mpicn_sIconDefs[i].mDraw;
        }
    }
    if (mpicn_createPendulumIcon()) {
        s32 groupIndex;
        s32 i;

        groupIndex = mpicn_sIconData->mGroupCount++;
        for (i = 0; mpicn_sIconDefs[i].mCreate != mpicn_createPendulumIcon && i < 49;
             i++) {
        }
        if (i < 49) {
            mpicn_sIconData->mClearFunctions[groupIndex] = mpicn_sIconDefs[i].mClear;
            mpicn_sIconData->mUpdateFunctions[groupIndex] = mpicn_sIconDefs[i].mUpdate;
            mpicn_sIconData->mDrawFunctions[groupIndex] = mpicn_sIconDefs[i].mDraw;
        }
    }
    if (mpicn_createNsKiller2Icon()) {
        s32 groupIndex;
        s32 i;

        groupIndex = mpicn_sIconData->mGroupCount++;
        for (i = 0; mpicn_sIconDefs[i].mCreate != mpicn_createNsKiller2Icon && i < 49;
             i++) {
        }
        if (i < 49) {
            mpicn_sIconData->mClearFunctions[groupIndex] = mpicn_sIconDefs[i].mClear;
            mpicn_sIconData->mUpdateFunctions[groupIndex] = mpicn_sIconDefs[i].mUpdate;
            mpicn_sIconData->mDrawFunctions[groupIndex] = mpicn_sIconDefs[i].mDraw;
        }
    }
    if (mpicn_createFlipperIcon()) {
        s32 groupIndex;
        s32 i;

        groupIndex = mpicn_sIconData->mGroupCount++;
        for (i = 0; mpicn_sIconDefs[i].mCreate != mpicn_createFlipperIcon && i < 49;
             i++) {
        }
        if (i < 49) {
            mpicn_sIconData->mClearFunctions[groupIndex] = mpicn_sIconDefs[i].mClear;
            mpicn_sIconData->mUpdateFunctions[groupIndex] = mpicn_sIconDefs[i].mUpdate;
            mpicn_sIconData->mDrawFunctions[groupIndex] = mpicn_sIconDefs[i].mDraw;
        }
    }
    if (mpicn_createMkdEfBubbleIcon()) {
        s32 groupIndex;
        s32 i;

        groupIndex = mpicn_sIconData->mGroupCount++;
        for (i = 0; mpicn_sIconDefs[i].mCreate != mpicn_createMkdEfBubbleIcon && i < 49;
             i++) {
        }
        if (i < 49) {
            mpicn_sIconData->mClearFunctions[groupIndex] = mpicn_sIconDefs[i].mClear;
            mpicn_sIconData->mUpdateFunctions[groupIndex] = mpicn_sIconDefs[i].mUpdate;
            mpicn_sIconData->mDrawFunctions[groupIndex] = mpicn_sIconDefs[i].mDraw;
        }
    }
    if (mpicn_createKuriboIcon()) {
        s32 groupIndex;
        s32 i;

        groupIndex = mpicn_sIconData->mGroupCount++;
        for (i = 0; mpicn_sIconDefs[i].mCreate != mpicn_createKuriboIcon && i < 49;
             i++) {
        }
        if (i < 49) {
            mpicn_sIconData->mClearFunctions[groupIndex] = mpicn_sIconDefs[i].mClear;
            mpicn_sIconData->mUpdateFunctions[groupIndex] = mpicn_sIconDefs[i].mUpdate;
            mpicn_sIconData->mDrawFunctions[groupIndex] = mpicn_sIconDefs[i].mDraw;
        }
    }
    if (mpicn_createObPakkunSfIcon()) {
        s32 groupIndex;
        s32 i;

        groupIndex = mpicn_sIconData->mGroupCount++;
        for (i = 0; mpicn_sIconDefs[i].mCreate != mpicn_createObPakkunSfIcon && i < 49;
             i++) {
        }
        if (i < 49) {
            mpicn_sIconData->mClearFunctions[groupIndex] = mpicn_sIconDefs[i].mClear;
            mpicn_sIconData->mUpdateFunctions[groupIndex] = mpicn_sIconDefs[i].mUpdate;
            mpicn_sIconData->mDrawFunctions[groupIndex] = mpicn_sIconDefs[i].mDraw;
        }
    }
    if (mpicn_createRock2Icon()) {
        s32 groupIndex;
        s32 i;

        groupIndex = mpicn_sIconData->mGroupCount++;
        for (i = 0; mpicn_sIconDefs[i].mCreate != mpicn_createRock2Icon && i < 49; i++) {
        }
        if (i < 49) {
            mpicn_sIconData->mClearFunctions[groupIndex] = mpicn_sIconDefs[i].mClear;
            mpicn_sIconData->mUpdateFunctions[groupIndex] = mpicn_sIconDefs[i].mUpdate;
            mpicn_sIconData->mDrawFunctions[groupIndex] = mpicn_sIconDefs[i].mDraw;
        }
    }
    if (mpicn_createRockIcon()) {
        s32 groupIndex;
        s32 i;

        groupIndex = mpicn_sIconData->mGroupCount++;
        for (i = 0; mpicn_sIconDefs[i].mCreate != mpicn_createRockIcon && i < 49; i++) {
        }
        if (i < 49) {
            mpicn_sIconData->mClearFunctions[groupIndex] = mpicn_sIconDefs[i].mClear;
            mpicn_sIconData->mUpdateFunctions[groupIndex] = mpicn_sIconDefs[i].mUpdate;
            mpicn_sIconData->mDrawFunctions[groupIndex] = mpicn_sIconDefs[i].mDraw;
        }
    }
    if (mpicn_createWoodbox1Icon()) {
        s32 groupIndex;
        s32 i;

        groupIndex = mpicn_sIconData->mGroupCount++;
        for (i = 0; mpicn_sIconDefs[i].mCreate != mpicn_createWoodbox1Icon && i < 49;
             i++) {
        }
        if (i < 49) {
            mpicn_sIconData->mClearFunctions[groupIndex] = mpicn_sIconDefs[i].mClear;
            mpicn_sIconData->mUpdateFunctions[groupIndex] = mpicn_sIconDefs[i].mUpdate;
            mpicn_sIconData->mDrawFunctions[groupIndex] = mpicn_sIconDefs[i].mDraw;
        }
    }
    if (mpicn_createRainStarIcon()) {
        s32 groupIndex;
        s32 i;

        groupIndex = mpicn_sIconData->mGroupCount++;
        for (i = 0; mpicn_sIconDefs[i].mCreate != mpicn_createRainStarIcon && i < 49;
             i++) {
        }
        if (i < 49) {
            mpicn_sIconData->mClearFunctions[groupIndex] = mpicn_sIconDefs[i].mClear;
            mpicn_sIconData->mUpdateFunctions[groupIndex] = mpicn_sIconDefs[i].mUpdate;
            mpicn_sIconData->mDrawFunctions[groupIndex] = mpicn_sIconDefs[i].mDraw;
        }
    }
    if (mpicn_createMkdEfBurnerIcon()) {
        s32 groupIndex;
        s32 i;

        groupIndex = mpicn_sIconData->mGroupCount++;
        for (i = 0; mpicn_sIconDefs[i].mCreate != mpicn_createMkdEfBurnerIcon && i < 49;
             i++) {
        }
        if (i < 49) {
            mpicn_sIconData->mClearFunctions[groupIndex] = mpicn_sIconDefs[i].mClear;
            mpicn_sIconData->mUpdateFunctions[groupIndex] = mpicn_sIconDefs[i].mUpdate;
            mpicn_sIconData->mDrawFunctions[groupIndex] = mpicn_sIconDefs[i].mDraw;
        }
    }
    if (mpicn_createPooIcon()) {
        s32 groupIndex;
        s32 i;

        groupIndex = mpicn_sIconData->mGroupCount++;
        for (i = 0; mpicn_sIconDefs[i].mCreate != mpicn_createPooIcon && i < 49;
             i++) {
        }
        if (i < 49) {
            mpicn_sIconData->mClearFunctions[groupIndex] = mpicn_sIconDefs[i].mClear;
            mpicn_sIconData->mUpdateFunctions[groupIndex] = mpicn_sIconDefs[i].mUpdate;
            mpicn_sIconData->mDrawFunctions[groupIndex] = mpicn_sIconDefs[i].mDraw;
        }
    }
    if (mpicn_createBoundIcon()) {
        s32 groupIndex;
        s32 i;

        groupIndex = mpicn_sIconData->mGroupCount++;
        for (i = 0; mpicn_sIconDefs[i].mCreate != mpicn_createBoundIcon && i < 49; i++) {
        }
        if (i < 49) {
            mpicn_sIconData->mClearFunctions[groupIndex] = mpicn_sIconDefs[i].mClear;
            mpicn_sIconData->mUpdateFunctions[groupIndex] = mpicn_sIconDefs[i].mUpdate;
            mpicn_sIconData->mDrawFunctions[groupIndex] = mpicn_sIconDefs[i].mDraw;
        }
    }
    if (mpicn_createSunFireSnakeIcon()) {
        s32 groupIndex;
        s32 i;

        groupIndex = mpicn_sIconData->mGroupCount++;
        for (i = 0; mpicn_sIconDefs[i].mCreate != mpicn_createSunFireSnakeIcon && i < 49;
             i++) {
        }
        if (i < 49) {
            mpicn_sIconData->mClearFunctions[groupIndex] = mpicn_sIconDefs[i].mClear;
            mpicn_sIconData->mUpdateFunctions[groupIndex] = mpicn_sIconDefs[i].mUpdate;
            mpicn_sIconData->mDrawFunctions[groupIndex] = mpicn_sIconDefs[i].mDraw;
        }
    }
    if (mpicn_createFireball2Icon()) {
        s32 groupIndex;
        s32 i;

        groupIndex = mpicn_sIconData->mGroupCount++;
        for (i = 0; mpicn_sIconDefs[i].mCreate != mpicn_createFireball2Icon && i < 49;
             i++) {
        }
        if (i < 49) {
            mpicn_sIconData->mClearFunctions[groupIndex] = mpicn_sIconDefs[i].mClear;
            mpicn_sIconData->mUpdateFunctions[groupIndex] = mpicn_sIconDefs[i].mUpdate;
            mpicn_sIconData->mDrawFunctions[groupIndex] = mpicn_sIconDefs[i].mDraw;
        }
    }
    if (mpicn_createIronBallIcon()) {
        s32 groupIndex;
        s32 i;

        groupIndex = mpicn_sIconData->mGroupCount++;
        for (i = 0; mpicn_sIconDefs[i].mCreate != mpicn_createIronBallIcon && i < 49;
             i++) {
        }
        if (i < 49) {
            mpicn_sIconData->mClearFunctions[groupIndex] = mpicn_sIconDefs[i].mClear;
            mpicn_sIconData->mUpdateFunctions[groupIndex] = mpicn_sIconDefs[i].mUpdate;
            mpicn_sIconData->mDrawFunctions[groupIndex] = mpicn_sIconDefs[i].mDraw;
        }
    }
    if (mpicn_createSanboIcon()) {
        s32 groupIndex;
        s32 i;

        groupIndex = mpicn_sIconData->mGroupCount++;
        for (i = 0; mpicn_sIconDefs[i].mCreate != mpicn_createSanboIcon && i < 49; i++) {
        }
        if (i < 49) {
            mpicn_sIconData->mClearFunctions[groupIndex] = mpicn_sIconDefs[i].mClear;
            mpicn_sIconData->mUpdateFunctions[groupIndex] = mpicn_sIconDefs[i].mUpdate;
            mpicn_sIconData->mDrawFunctions[groupIndex] = mpicn_sIconDefs[i].mDraw;
        }
    }
    if (mpicn_createBasabasaIcon()) {
        s32 groupIndex;
        s32 i;

        groupIndex = mpicn_sIconData->mGroupCount++;
        for (i = 0; mpicn_sIconDefs[i].mCreate != mpicn_createBasabasaIcon && i < 49;
             i++) {
        }
        if (i < 49) {
            mpicn_sIconData->mClearFunctions[groupIndex] = mpicn_sIconDefs[i].mClear;
            mpicn_sIconData->mUpdateFunctions[groupIndex] = mpicn_sIconDefs[i].mUpdate;
            mpicn_sIconData->mDrawFunctions[groupIndex] = mpicn_sIconDefs[i].mDraw;
        }
    }
    if (mpicn_createPakkunFireIcon()) {
        s32 groupIndex;
        s32 i;

        groupIndex = mpicn_sIconData->mGroupCount++;
        for (i = 0; mpicn_sIconDefs[i].mCreate != mpicn_createPakkunFireIcon && i < 49; i++) {
        }
        if (i < 49) {
            mpicn_sIconData->mClearFunctions[groupIndex] = mpicn_sIconDefs[i].mClear;
            mpicn_sIconData->mUpdateFunctions[groupIndex] = mpicn_sIconDefs[i].mUpdate;
            mpicn_sIconData->mDrawFunctions[groupIndex] = mpicn_sIconDefs[i].mDraw;
        }
    }
    if (mpicn_createBerryIcon()) {
        s32 groupIndex;
        s32 i;

        groupIndex = mpicn_sIconData->mGroupCount++;
        for (i = 0; mpicn_sIconDefs[i].mCreate != mpicn_createBerryIcon && i < 49; i++) {
        }
        if (i < 49) {
            mpicn_sIconData->mClearFunctions[groupIndex] = mpicn_sIconDefs[i].mClear;
            mpicn_sIconData->mUpdateFunctions[groupIndex] = mpicn_sIconDefs[i].mUpdate;
            mpicn_sIconData->mDrawFunctions[groupIndex] = mpicn_sIconDefs[i].mDraw;
        }
    }
    if (mpicn_createCreamIcon()) {
        s32 groupIndex;
        s32 i;

        groupIndex = mpicn_sIconData->mGroupCount++;
        for (i = 0; mpicn_sIconDefs[i].mCreate != mpicn_createCreamIcon && i < 49; i++) {
        }
        if (i < 49) {
            mpicn_sIconData->mClearFunctions[groupIndex] = mpicn_sIconDefs[i].mClear;
            mpicn_sIconData->mUpdateFunctions[groupIndex] = mpicn_sIconDefs[i].mUpdate;
            mpicn_sIconData->mDrawFunctions[groupIndex] = mpicn_sIconDefs[i].mDraw;
        }
    }
    if (gRaceMultiConfig->mMode != MODE_MISSION_RUN) {
        return;
    }
    if (mpicn_createCoinIcon()) {
        s32 groupIndex;
        s32 i;

        groupIndex = mpicn_sIconData->mGroupCount++;
        for (i = 0; mpicn_sIconDefs[i].mCreate != mpicn_createCoinIcon && i < 49; i++) {
        }
        if (i < 49) {
            mpicn_sIconData->mClearFunctions[groupIndex] = mpicn_sIconDefs[i].mClear;
            mpicn_sIconData->mUpdateFunctions[groupIndex] = mpicn_sIconDefs[i].mUpdate;
            mpicn_sIconData->mDrawFunctions[groupIndex] = mpicn_sIconDefs[i].mDraw;
        }
    }
    if (mpicn_createMissionGateIcon()) {
        s32 groupIndex;
        s32 i;

        groupIndex = mpicn_sIconData->mGroupCount++;
        for (i = 0; mpicn_sIconDefs[i].mCreate != mpicn_createMissionGateIcon && i < 49;
             i++) {
        }
        if (i < 49) {
            mpicn_sIconData->mClearFunctions[groupIndex] = mpicn_sIconDefs[i].mClear;
            mpicn_sIconData->mUpdateFunctions[groupIndex] = mpicn_sIconDefs[i].mUpdate;
            mpicn_sIconData->mDrawFunctions[groupIndex] = mpicn_sIconDefs[i].mDraw;
        }
    }
    if (mpicn_createStopSignIcon()) {
        s32 groupIndex;
        s32 i;

        groupIndex = mpicn_sIconData->mGroupCount++;
        for (i = 0; mpicn_sIconDefs[i].mCreate != mpicn_createStopSignIcon && i < 49;
             i++) {
        }
        if (i < 49) {
            mpicn_sIconData->mClearFunctions[groupIndex] = mpicn_sIconDefs[i].mClear;
            mpicn_sIconData->mUpdateFunctions[groupIndex] = mpicn_sIconDefs[i].mUpdate;
            mpicn_sIconData->mDrawFunctions[groupIndex] = mpicn_sIconDefs[i].mDraw;
        }
    }
    if (mpicn_createBossDonketuIcon()) {
        s32 groupIndex;
        s32 i;

        groupIndex = mpicn_sIconData->mGroupCount++;
        for (i = 0; mpicn_sIconDefs[i].mCreate != mpicn_createBossDonketuIcon && i < 49;
             i++) {
        }
        if (i < 49) {
            mpicn_sIconData->mClearFunctions[groupIndex] = mpicn_sIconDefs[i].mClear;
            mpicn_sIconData->mUpdateFunctions[groupIndex] = mpicn_sIconDefs[i].mUpdate;
            mpicn_sIconData->mDrawFunctions[groupIndex] = mpicn_sIconDefs[i].mDraw;
        }
    }
    if (mpicn_createKingIceDonketuIcon()) {
        s32 groupIndex;
        s32 i;

        groupIndex = mpicn_sIconData->mGroupCount++;
        for (i = 0;
             mpicn_sIconDefs[i].mCreate != mpicn_createKingIceDonketuIcon && i < 49;
             i++) {
        }
        if (i < 49) {
            mpicn_sIconData->mClearFunctions[groupIndex] = mpicn_sIconDefs[i].mClear;
            mpicn_sIconData->mUpdateFunctions[groupIndex] = mpicn_sIconDefs[i].mUpdate;
            mpicn_sIconData->mDrawFunctions[groupIndex] = mpicn_sIconDefs[i].mDraw;
        }
    }
    if (mpicn_createKurikingIcon()) {
        s32 groupIndex;
        s32 i;

        groupIndex = mpicn_sIconData->mGroupCount++;
        for (i = 0; mpicn_sIconDefs[i].mCreate != mpicn_createKurikingIcon && i < 49;
             i++) {
        }
        if (i < 49) {
            mpicn_sIconData->mClearFunctions[groupIndex] = mpicn_sIconDefs[i].mClear;
            mpicn_sIconData->mUpdateFunctions[groupIndex] = mpicn_sIconDefs[i].mUpdate;
            mpicn_sIconData->mDrawFunctions[groupIndex] = mpicn_sIconDefs[i].mDraw;
        }
    }
    if (mpicn_createBombKingIcon()) {
        s32 groupIndex;
        s32 i;

        groupIndex = mpicn_sIconData->mGroupCount++;
        for (i = 0; mpicn_sIconDefs[i].mCreate != mpicn_createBombKingIcon && i < 49;
             i++) {
        }
        if (i < 49) {
            mpicn_sIconData->mClearFunctions[groupIndex] = mpicn_sIconDefs[i].mClear;
            mpicn_sIconData->mUpdateFunctions[groupIndex] = mpicn_sIconDefs[i].mUpdate;
            mpicn_sIconData->mDrawFunctions[groupIndex] = mpicn_sIconDefs[i].mDraw;
        }
    }
    if (mpicn_createIwanteLIcon()) {
        s32 groupIndex;
        s32 i;

        groupIndex = mpicn_sIconData->mGroupCount++;
        for (i = 0; mpicn_sIconDefs[i].mCreate != mpicn_createIwanteLIcon && i < 49;
             i++) {
        }
        if (i < 49) {
            mpicn_sIconData->mClearFunctions[groupIndex] = mpicn_sIconDefs[i].mClear;
            mpicn_sIconData->mUpdateFunctions[groupIndex] = mpicn_sIconDefs[i].mUpdate;
            mpicn_sIconData->mDrawFunctions[groupIndex] = mpicn_sIconDefs[i].mDraw;
        }
    }
    if (mpicn_createHanachanIcon()) {
        s32 groupIndex;
        s32 i;

        groupIndex = mpicn_sIconData->mGroupCount++;
        for (i = 0; mpicn_sIconDefs[i].mCreate != mpicn_createHanachanIcon && i < 49;
             i++) {
        }
        if (i < 49) {
            mpicn_sIconData->mClearFunctions[groupIndex] = mpicn_sIconDefs[i].mClear;
            mpicn_sIconData->mUpdateFunctions[groupIndex] = mpicn_sIconDefs[i].mUpdate;
            mpicn_sIconData->mDrawFunctions[groupIndex] = mpicn_sIconDefs[i].mDraw;
        }
    }
    if (mpicn_createKingTeresaIcon()) {
        s32 groupIndex;
        s32 i;

        groupIndex = mpicn_sIconData->mGroupCount++;
        for (i = 0; mpicn_sIconDefs[i].mCreate != mpicn_createKingTeresaIcon && i < 49; i++) {
        }
        if (i < 49) {
            mpicn_sIconData->mClearFunctions[groupIndex] = mpicn_sIconDefs[i].mClear;
            mpicn_sIconData->mUpdateFunctions[groupIndex] = mpicn_sIconDefs[i].mUpdate;
            mpicn_sIconData->mDrawFunctions[groupIndex] = mpicn_sIconDefs[i].mDraw;
        }
    }
}

void mpicn_finalize(void) {
    s32 i;

    for (i = 0; i < mpicn_sIconData->mGroupCount; i++) {
        mpicn_sIconData->mClearFunctions[i]();
    }
    mpicn_sIconData = NULL;
}

void mpicn_update(void) {
    Vec3 followedKartPosition;
    s32 i;
    s32 n;
    float f;

    switch (r2d_getMapMode()) {
        case 0:
            mpicn_updateDriverIcon();
            break;
        case 1:
        case 2:
        case 3:
            if (GetRaceHudSubScreenCourseScale() * 3 > 0) {
                f = 0.5f + (GetRaceHudSubScreenCourseScale() * 0x3000);
            } else {
                f = (GetRaceHudSubScreenCourseScale() * 0x3000) - 0.5f;
            }
            n = f;
            mpicn_sIconData->mScale = ((s64) n * 20) >> 12;
            mpicn_sIconData->field8 = FX_Div(0x2400, mpicn_sIconData->mScale);
            RefreshLocalMap(GetRaceHudSubScreenBgAffine(),
                                                        mpicn_sIconData->mScale);
            GetKartPosFromPosSourceCopy(&followedKartPosition, Race_GetPlayerId());
            mpicn_sIconData->field0 = m2d_isPointOnLowerMap(&followedKartPosition) != 0 ? 0 : 3;
            for (i = 0; i < mpicn_sIconData->mGroupCount; i++) {
                mpicn_sIconData->mUpdateFunctions[i]();
            }
            break;
    }
}

void mpicn_render(void *oamBuffer) {
    s32 i;

    switch (r2d_getMapMode()) {
        case 0:
            mpicn_renderDriverIcon(oamBuffer);
            break;
        case 1:
        case 2:
        case 3:
            for (i = 0; i < mpicn_sIconData->mGroupCount; i++) {
                mpicn_sIconData->mDrawFunctions[i](oamBuffer);
            }
            break;
    }
}
