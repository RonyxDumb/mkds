#include "01/RaceHudSubScreenMissionObjects.h"

#include "01/code_02188e88.h"
#include "01/code_02188950.h"
#include "01/code_021857a4.h"
#include "01/code_0218c790.h"
#include "01/unk_021a9000.h"
#include "Main/Unknown/code_021000d0.h"
#include "Main/Unknown/code_020b4000.h"
#include "Main/Unknown/code_020b1dbc.h"
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
#include "Main/Unknown/code_020b837c.h"
#include "Main/Unknown/code_020c0000.h"
#include "Main/Unknown/code_020c06c4.h"
#include "Main/Unknown/code_020c0b84.h"
#include "Main/Unknown/code_020c0ba8.h"
#include "Main/Unknown/code_020c0d9c.h"
#include "01/code_0218c000.h"
#include "Main/Unknown/code_020a3000.h"
#include "01/code_0218b298.h"
#include "01/code_0218f900.h"
#include "01/unk_021a6000.h"
#include "Main/Unknown/code_0209bef0.h"
#include "Main/Unknown/code_020b47b4.h"
#include "Main/Unknown/code_020b85f0.h"
#include "Main/Unknown/code_020b8624.h"
#include "00/code_02181f98.h"
#include "code_0200eddc.h"

RaceHudSubScreenCells *mpicn_sIwanteLIcon;

#pragma thumb off

s32 mpicn_createIwanteLIcon(void) {
    return mpicn_createMapObjIcon(&mpicn_sIwanteLIcon, MAP_OBJECT_KIND_IWANTE);
}

void mpicn_destroyIwanteLIcon(void) {
    mpicn_destroyMObjIcon(&mpicn_sIwanteLIcon);
}

void mpicn_updateIwanteLIcon(void) {
    u32 var;
    s32 i;
    s32 cellCount = 0;
    u32 entryIndex;
    Unk0217b498_00 *object;
    Vec3 *position;

    var = mpicn_20C0DB0();
    for (i = 0; i < mpicn_sIwanteLIcon->mObjectCount; i++) {
        object = mpicn_sIwanteLIcon->mObjects[i];
        if (!(object->mFlags & 1)) {
            position = &object->mPos;
            if (lmap_20B5AE8(position, &mpicn_sIwanteLIcon->mCells[cellCount].mDrawPos,
                                                var, 1, 1)) {
                if (func_ov001_0218f9c0((Unk02188950 *) object)) {
                    entryIndex = (object->mFlags & 0x400) ? 0xc8 : 0xc6;
                } else {
                    entryIndex = (object->mFlags & 0x400) ? 0xc7 : 0xc5;
                }
                mpicn_sIwanteLIcon->mCells[cellCount].mCell = r2d_getRaceSCell(entryIndex);
                mpicn_sIwanteLIcon->mCells[cellCount].fieldC = m2d_isPointOnLowerMap(position) ? 2 : 3;
                mpicn_sIwanteLIcon->mCells[cellCount].fieldE = object->mFlags & 0x20;
                mpicn_sIwanteLIcon->mCells[cellCount].field10 = object->mAngle;
                cellCount++;
            }
        }
    }
    mpicn_sIwanteLIcon->mCellCount = cellCount;
}

void mpicn_renderIwanteLIcon(void *oamBuffer) {
    mpicn_renderMObjIcon(oamBuffer, mpicn_sIwanteLIcon, 0);
}

s32 mpicn_createKurikingIcon(void) {
    return mpicn_createMapObjIcon(&mpicn_sKurikingIcon, MAP_OBJECT_KIND_KURIKING);
}

void mpicn_destroyKurikingIcon(void) {
    mpicn_destroyMObjIcon(&mpicn_sKurikingIcon);
}

// Also copies one row of the race_transfer_map_mr_s_o palette into the race palette for each object.
void mpicn_updateKurikingIcon(void) {
    u32 var;
    s32 i;
    s32 cellCount = 0;
    s32 row;
    s32 k;
    Unk0217b498_00 *object;
    u16 *racePalette;
    Nclr *nclr;
    Vec3 *position;

    var = mpicn_20C0DB0();
    for (i = 0; i < mpicn_sKurikingIcon->mObjectCount; i++) {
        object = mpicn_sKurikingIcon->mObjects[i];
        if (!(object->mFlags & 1)) {
            position = &object->mPos;
            if (lmap_20B5AE8(position, &mpicn_sKurikingIcon->mCells[cellCount].mDrawPos,
                                                var, 1, 1)) {
                row = func_ov001_0218b2d4((Unk02188950 *) object);
                racePalette = r2d_getGraphics(6)->mNclr->mData;
                nclr = NULL;
                g2du_getPaletteData((&nclr), (m2d_getSceneArcFile("race_transfer_map_mr_s_o.NCLR")));
                for (k = 0; k < 16; k++) {
                    racePalette[0x50 + k] = nclr->mData[(row + 2) * 16 + k];
                }
                DC_FlushRange(r2d_getGraphics(6)->mNclr->mData, r2d_getGraphics(6)->mNclr->mDataSize);
                mpicn_sKurikingIcon->mCells[cellCount].mCell = r2d_getRaceSCell(0xc5);
                mpicn_sKurikingIcon->mCells[cellCount].fieldC = m2d_isPointOnLowerMap(position) ? 2 : 3;
                mpicn_sKurikingIcon->mCells[cellCount].fieldE = object->mFlags & 0x20;
                mpicn_sKurikingIcon->mCells[cellCount].field10 = object->mAngle;
                cellCount++;
            }
        }
    }
    mpicn_sKurikingIcon->mCellCount = cellCount;
}

#pragma thumb on

RaceHudSubScreenCells *mpicn_sHanachanIcon;
RaceHudSubScreenCells *mpicn_sMissionGateIcon;
RaceHudSubScreenCells *mpicn_sStopSignIcon;
RaceHudSubScreenCells *mpicn_sBossDonketuIcon;
RaceHudSubScreenCells *mpicn_sBombKingIcon;
RaceHudSubScreenCells *mpicn_sKurikingIcon;

#pragma thumb off

void mpicn_renderKurikingIcon(void *oamBuffer) {
    mpicn_renderMObjIcon(oamBuffer, mpicn_sKurikingIcon, 0);
}

s32 mpicn_createBombKingIcon(void) {
    return mpicn_createMapObjIcon(&mpicn_sBombKingIcon, MAP_OBJECT_KIND_BOMB_KING);
}

void mpicn_destroyBombKingIcon(void) {
    mpicn_destroyMObjIcon(&mpicn_sBombKingIcon);
}

void mpicn_updateBombKingIcon(void) {
    s32 i;
    s32 cellCount;
    u32 unk;
    Unk0217b498_00 *object;
    Vec3 *position;

    cellCount = 0;
    unk = mpicn_20C0DB0();
    for (i = 0; i < mpicn_sBombKingIcon->mObjectCount; i++) {
        object = mpicn_sBombKingIcon->mObjects[i];
        if (object->mFlags & 1) {
            continue;
        }
        position = &object->mPos;
        if (lmap_20B5AE8(position, &mpicn_sBombKingIcon->mCells[cellCount].mDrawPos, unk,
                                            1, 1)) {
            mpicn_sBombKingIcon->mCells[cellCount].mCell = r2d_getRaceSCell(0xc5);
            mpicn_sBombKingIcon->mCells[cellCount].fieldC = m2d_isPointOnLowerMap(position) ? 2 : 3;
            mpicn_sBombKingIcon->mCells[cellCount].fieldE = object->mFlags & 0x20;
            mpicn_sBombKingIcon->mCells[cellCount].field10 = object->mAngle;
            cellCount++;
        }
    }
    mpicn_sBombKingIcon->mCellCount = cellCount;
}

void mpicn_renderBombKingIcon(void *oamBuffer) {
    mpicn_renderMObjIcon(oamBuffer, mpicn_sBombKingIcon, 0);
}

s32 mpicn_createBossDonketuIcon(void) {
    return mpicn_createMapObjIcon(&mpicn_sBossDonketuIcon, MAP_OBJECT_KIND_BOSS_DONKETU);
}

void mpicn_destroyBossDonketuIcon(void) {
    mpicn_destroyMObjIcon(&mpicn_sBossDonketuIcon);
}

void mpicn_updateBossDonketuIcon(void) {
    s32 i;
    s32 cellCount;
    u32 unk;
    Unk0217b498_00 *object;
    Vec3 *position;

    cellCount = 0;
    unk = mpicn_20C0DB0();
    for (i = 0; i < mpicn_sBossDonketuIcon->mObjectCount; i++) {
        object = mpicn_sBossDonketuIcon->mObjects[i];
        if (object->mFlags & 1) {
            continue;
        }
        position = &object->mPos;
        if (lmap_20B5AE8(position, &mpicn_sBossDonketuIcon->mCells[cellCount].mDrawPos,
                                            unk, 1, 1)) {
            mpicn_sBossDonketuIcon->mCells[cellCount].mCell = r2d_getRaceSCell(0xc5);
            mpicn_sBossDonketuIcon->mCells[cellCount].fieldC = m2d_isPointOnLowerMap(position) ? 2 : 3;
            mpicn_sBossDonketuIcon->mCells[cellCount].fieldE = object->mFlags & 0x20;
            mpicn_sBossDonketuIcon->mCells[cellCount].field10 = object->mAngle;
            cellCount++;
        }
    }
    mpicn_sBossDonketuIcon->mCellCount = cellCount;
}

void mpicn_renderBossDonketuIcon(void *oamBuffer) {
    mpicn_renderMObjIcon(oamBuffer, mpicn_sBossDonketuIcon, 0);
}

s32 mpicn_createStopSignIcon(void) {
    return mpicn_createMapObjIcon(&mpicn_sStopSignIcon, MAP_OBJECT_KIND_STOP_SIGN);
}

void mpicn_destroyStopSignIcon(void) {
    mpicn_destroyMObjIcon(&mpicn_sStopSignIcon);
}

void mpicn_updateStopSignIcon(void) {
    s32 i;
    s32 cellCount;
    u32 unk;
    Unk0217b498_00 *object;
    Vec3 *position;

    cellCount = 0;
    unk = mpicn_20C0DB0();
    for (i = 0; i < mpicn_sStopSignIcon->mObjectCount; i++) {
        object = mpicn_sStopSignIcon->mObjects[i];
        position = &object->mPos;
        if (lmap_20B5AE8(position, &mpicn_sStopSignIcon->mCells[cellCount].mDrawPos, unk,
                                            1, 1)) {
            mpicn_sStopSignIcon->mCells[cellCount].mCell = r2d_getRaceSCell(0x5b);
            mpicn_sStopSignIcon->mCells[cellCount].fieldC = m2d_isPointOnLowerMap(position) ? 2 : 3;
            mpicn_sStopSignIcon->mCells[cellCount].fieldE = 0;
            mpicn_sStopSignIcon->mCells[cellCount].field10 = object->mAngle;
            cellCount++;
        }
    }
    mpicn_sStopSignIcon->mCellCount = cellCount;
}

void mpicn_renderStopSignIcon(void *oamBuffer) {
    mpicn_renderMObjIcon(oamBuffer, mpicn_sStopSignIcon, 1);
}

s32 mpicn_createMissionGateIcon(void) {
    return mpicn_createMapObjIcon(&mpicn_sMissionGateIcon, MAP_OBJECT_KIND_MISSION_GATE);
}

void mpicn_destroyMissionGateIcon(void) {
    mpicn_destroyMObjIcon(&mpicn_sMissionGateIcon);
}

void mpicn_updateMissionGateIcon(void) {
    s32 i;
    s32 cellCount;
    u32 unk;
    Unk0217b498_00 *object;
    Vec3 *position;

    cellCount = 0;
    unk = mpicn_20C0DB0();
    for (i = 0; i < mpicn_sMissionGateIcon->mObjectCount; i++) {
        object = mpicn_sMissionGateIcon->mObjects[i];
        position = &object->mPos;
        if (lmap_20B5AE8(position, &mpicn_sMissionGateIcon->mCells[cellCount].mDrawPos,
                                            unk, 1, 1)) {
            mpicn_sMissionGateIcon->mCells[cellCount].mCell =
                r2d_getRaceSCell(func_ov001_02185b50((MissionGateObject *) object) ? 0x5a : 0x59);
            mpicn_sMissionGateIcon->mCells[cellCount].fieldC = m2d_isPointOnLowerMap(position) ? 2 : 3;
            mpicn_sMissionGateIcon->mCells[cellCount].fieldE = 0;
            mpicn_sMissionGateIcon->mCells[cellCount].field10 = object->mAngle;
            cellCount++;
        }
    }
    mpicn_sMissionGateIcon->mCellCount = cellCount;
}

void mpicn_renderMissionGateIcon(void *oamBuffer) {
    mpicn_renderMObjIcon(oamBuffer, mpicn_sMissionGateIcon, 1);
}

s32 mpicn_createHanachanIcon(void) {
    return mpicn_createMapObjIcon(&mpicn_sHanachanIcon, MAP_OBJECT_KIND_HANACHAN);
}

void mpicn_destroyHanachanIcon(void) {
    mpicn_destroyMObjIcon(&mpicn_sHanachanIcon);
}

void mpicn_updateHanachanIcon(void) {
    s32 i;
    s32 cellCount;
    u32 unk;
    Unk0217b498_00 *object;
    Vec3 *position;

    cellCount = 0;
    unk = mpicn_20C0DB0();
    for (i = 0; i < mpicn_sHanachanIcon->mObjectCount; i++) {
        object = mpicn_sHanachanIcon->mObjects[i];
        if (object->mFlags & 1) {
            continue;
        }
        position = &object->mPos;
        if (lmap_20B5AE8(position, &mpicn_sHanachanIcon->mCells[cellCount].mDrawPos, unk,
                                            1, 1)) {
            mpicn_sHanachanIcon->mCells[cellCount].mCell =
                r2d_getRaceSCell(GetMapObjectNsbtpFrameIndex((Unk02188950 *) object) >= 2 ? 0xc6 : 0xc5);
            mpicn_sHanachanIcon->mCells[cellCount].fieldC = m2d_isPointOnLowerMap(position) ? 2 : 3;
            mpicn_sHanachanIcon->mCells[cellCount].fieldE = object->mFlags & 0x20;
            mpicn_sHanachanIcon->mCells[cellCount].field10 = object->mAngle;
            cellCount++;
        }
    }
    mpicn_sHanachanIcon->mCellCount = cellCount;
}

void mpicn_renderHanachanIcon(void *oamBuffer) {
    mpicn_renderMObjIcon(oamBuffer, mpicn_sHanachanIcon, 0);
}

#pragma thumb on
