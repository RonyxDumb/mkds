#include "01/code_02188e88.h"
#include "01/code_02185ef4.h"
#include "01/code_02187000.h"
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
#include "Main/Unknown/code_020c06c4.h"
#include "Main/Unknown/code_020c0b84.h"
#include "Main/Unknown/code_020c0ba8.h"
#include "Main/Unknown/code_020c0d9c.h"
#include "Main/Unknown/code_020b4000.h"
#include "Main/Unknown/code_020c0000.h"
#include "code_02147cd8.h"
#include "Main/Unknown/code_021000d0.h"

RaceHudSubScreenCells *mpicn_sKingIceDonketuIcon;
RaceHudSubScreenCells *mpicn_sKingTeresaIcon;

#pragma thumb off

s32 mpicn_createKingIceDonketuIcon(void) {
    return mpicn_createMapObjIcon(&mpicn_sKingIceDonketuIcon, MAP_OBJECT_KIND_KING_ICE_DONKETU);
}

void mpicn_destroyKingIceDonketuIcon(void) {
    mpicn_destroyMObjIcon(&mpicn_sKingIceDonketuIcon);
}

void mpicn_updateKingIceDonketuIcon(void) {
    s32 i;
    s32 cellCount = 0;
    u32 v = mpicn_20C0DB0();
    Unk0217b498_00 *object;
    Vec3 *pos;

    for (i = 0; i < mpicn_sKingIceDonketuIcon->mObjectCount; i++) {
        object = mpicn_sKingIceDonketuIcon->mObjects[i];
        if (!(object->mFlags & 1)) {
            pos = &object->mPos;
            if (lmap_20B5AE8(pos, &mpicn_sKingIceDonketuIcon->mCells[cellCount].mDrawPos,
                                                v, 1, 1) != FALSE) {
                mpicn_sKingIceDonketuIcon->mCells[cellCount].mCell = r2d_getRaceSCell(0xc5);
                mpicn_sKingIceDonketuIcon->mCells[cellCount].fieldC = m2d_isPointOnLowerMap(pos) ? 2 : 3;
                mpicn_sKingIceDonketuIcon->mCells[cellCount].fieldE = object->mFlags & 0x20;
                mpicn_sKingIceDonketuIcon->mCells[cellCount].field10 = object->mAngle;
                cellCount++;
            }
        }
    }
    mpicn_sKingIceDonketuIcon->mCellCount = cellCount;
}

void mpicn_renderKingIceDonketuIcon(void *oamBuffer) {
    mpicn_renderMObjIcon(oamBuffer, mpicn_sKingIceDonketuIcon, 0);
}

BOOL mpicn_createKingTeresaIcon(void) {
    return mpicn_createMapObjIcon(&mpicn_sKingTeresaIcon, 0x1fd);
}

void mpicn_destroyKingTeresaIcon(void) {
    mpicn_destroyMObjIcon(&mpicn_sKingTeresaIcon);
}

void mpicn_updateKingTeresaIcon(void) {
    s32 i;
    s32 cellCount = 0;
    u32 v = mpicn_20C0DB0();
    Unk0217b498_00 *object;
    Vec3 *pos;

    for (i = 0; i < mpicn_sKingTeresaIcon->mObjectCount; i++) {
        object = mpicn_sKingTeresaIcon->mObjects[i];
        if (!(object->mFlags & 1)) {
            pos = &object->mPos;
            if (lmap_20B5AE8(pos, &mpicn_sKingTeresaIcon->mCells[cellCount].mDrawPos, v, 1, 1) !=
                FALSE) {
                mpicn_sKingTeresaIcon->mCells[cellCount].mCell = r2d_getRaceSCell(0xc5);
                mpicn_sKingTeresaIcon->mCells[cellCount].fieldC = m2d_isPointOnLowerMap(pos) ? 2 : 3;
                mpicn_sKingTeresaIcon->mCells[cellCount].fieldE = object->mFlags & 0x20;
                mpicn_sKingTeresaIcon->mCells[cellCount].field10 = object->mAngle;
                cellCount++;
            }
        }
    }
    mpicn_sKingTeresaIcon->mCellCount = cellCount;
}

void mpicn_renderKingTeresaIcon(void *oamBuffer) {
    mpicn_renderMObjIcon(oamBuffer, mpicn_sKingTeresaIcon, 0);
}

#pragma thumb on

BOOL IsWithinXzDistanceOfPoint(Unk02188950 *mapObject, Vec3 *point, s32 radius) {
    Vec3 unusedOffset;
    s32 dx;
    s32 dz;
    float radiusAsFloat;
    float radiusAsFloatCopy;

    if (point != NULL) {
        VEC_Subtract(point, &mapObject->field0.mPos, &unusedOffset);
        dx = mapObject->field0.mPos.x - point->x;
        dz = mapObject->field0.mPos.z - point->z;
        if (radius > 0) {
            radiusAsFloat = 0.5f + (radius << 12);
        } else {
            radiusAsFloat = (radius << 12) - 0.5f;
        }
        if (radius > 0) {
            radiusAsFloatCopy = 0.5f + (radius << 12);
        } else {
            radiusAsFloatCopy = (radius << 12) - 0.5f;
        }
        if ((s64) dx * dx + (s64) dz * dz < (s64) (s32) radiusAsFloatCopy * (s32) radiusAsFloat) {
            return 1;
        }
        return 0;
    }
    return 0;
}

BOOL IsDirectionToPointWithinAngle(Unk02188950 *mapObject, s32 angle, Vec3 *point, s32 halfAngle) {
    s32 angleDifference;

    if (point != NULL) {
        angleDifference =
            (u16) (FX_Atan2Idx(point->x - mapObject->field0.mPos.x, point->z - mapObject->field0.mPos.z) - angle);
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

void ClearAndRunCallback(Unk02188950 *mapObject, void (**callbackSlot)()) {
    void (*callback)() = *callbackSlot;

    *callbackSlot = NULL;
    if (callback != NULL) {
        callback(mapObject, callbackSlot, 0);
    }
}

void func_ov001_02188e88(Unk02188950 *mapObject) {
    func_ov001_02187218(mapObject, 0, (s32(*)(Unk02188950 *))(0));
}
