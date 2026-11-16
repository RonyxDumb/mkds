#include "Main/Race/RaceHudSubScreen.h"

#include "Main/Unknown/code_020c06c4.h"
#include "Main/Unknown/code_020c0ba8.h"
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
#include "Main/Unknown/code_020c0b84.h"
#include "Main/Unknown/code_020c0d9c.h"
#include "Main/Unknown/code_020de9f8.h"
#include "Main/Unknown/code_020e0680.h"
#include "Main/Unknown/code_021000d0.h"
#include "Main/Unknown/unk_0217b000.h"
#include "Main/Unknown/code_020daf20.h"
#include "Main/Unknown/code_020ade08.h"
#include "Main/Unknown/code_020364e0.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_020ae000.h"
#include "Main/Unknown/code_02100084.h"
#include "Main/Unknown/code_02100094.h"
#include "code_020222ec.h"
#include "code_02148538.h"
#include "Main/System/Heap.h"
#include "Main/Unknown/code_0207a000.h"
#include "Main/Unknown/code_0203c000.h"
#include "Main/Unknown/code_020b4dc4.h"
#include "Main/Unknown/code_020d3c94.h"
#include "Main/Unknown/code_020ee684.h"
#include "Main/Unknown/code_020f36d8.h"
#include "Main/Unknown/code_020f8e78.h"
#include "Main/Unknown/code_020fd83c.h"
#include "Main/Unknown/code_021001a0.h"
#include "Main/Unknown/code_02100de4.h"
#include "Main/Unknown/unk_02169000.h"
#include "Main/Unknown/unk_027e0000.h"
#include "Main/Unknown/code_0203c8dc.h"
#include "Main/Unknown/code_02077bc0.h"

// Indices into it_sItemParams and it_sItemsets.
s32 mpicn_sIconItems[10] = {0, 1, 2, 3, 4, 5, 9, 7, 8, 11};

void mpicn_updateCrabIcon(void) {
    s32 i;
    s32 cellCount;
    u32 v;

    cellCount = 0;
    v = mpicn_20C0DB0();
    for (i = 0; i < mpicn_sCrabIcon->mObjectCount; i++) {
        Unk0217b498_00 *object;

        object = mpicn_sCrabIcon->mObjects[i];
        if (!(object->mFlags & 1)) {
            if (lmap_20B5AE8(&object->mPos, &mpicn_sCrabIcon->mCells[cellCount].mDrawPos,
                                                v, 1, 1)) {
                mpicn_sCrabIcon->mCells[cellCount].mCell = r2d_getRaceSCell(0x8a);
                mpicn_sCrabIcon->mCells[cellCount].mUnk_0c = 2;
                cellCount++;
            }
        }
    }
    mpicn_sCrabIcon->mCellCount = cellCount;
}

void mpicn_renderCrabIcon(RaceHudOamBuffer *oamBuffer) {
    mpicn_renderMObjIcon(oamBuffer, mpicn_sCrabIcon, 0);
}

s32 mpicn_createItemIcon(void) {
    s32 objectCount;
    s32 i;

    objectCount = 0;
    for (i = 0; i < 10; i++) {
        objectCount += it_sItemParams[mpicn_sIconItems[i]].mObjectCount;
    }
    return mpicn_20C0BA8(&mpicn_sItemIcon, objectCount);
}

void mpicn_destroyItemIcon(void) {
    mpicn_destroyMObjIcon(&mpicn_sItemIcon);
}

void mpicn_updateItemIcon(void) {
    enum { K0 } poolIndex;
    s32 cellCount;
    s32 a;
    s32 tableIndex;
    s32 j;
    ItemPool *pool;
    ItemObject **objects;
    s32 activeCount;
    Unk020224e0_c *cell;
    ItemObject *object;
    Vec3 *position;
    s32 v;

    cellCount = 0;
    a = mpicn_20C0DB0();
    for (tableIndex = 0; tableIndex < 10; tableIndex++) {
        poolIndex = mpicn_sIconItems[tableIndex];
        pool = &it_sItemsets[poolIndex];
        objects = pool->mObjects;
        activeCount = pool->mActiveCount;
        {
            s32 cellIndices[10] = {0x4c, 0x4d, 0x4b, 0x4f, 0x50, 0x56, 0x55, 0x54, 0x4e, 0x57};

            cell = r2d_getRaceSCell(cellIndices[tableIndex]);
        }
        for (j = 0; j < activeCount; j++) {
            object = objects[j];
            if ((object->mFlags & 0x80000) != 0) {
                position = NULL;
            } else {
                position = &object->mPos;
            }
            if (tableIndex == 9) {
                if (position != NULL) {
                    if (lmap_20B5AE8(
                            position, &mpicn_sItemIcon->mCells[cellCount].mDrawPos, a, 1, 1) != FALSE) {
                        if (object->mAlpha > 0) {
                            v = ((ItemTeresa *) object)->mOffsetY;
                            mpicn_sItemIcon->mCells[cellCount].mDrawPos.mUnk_04 -=
                                0x88 * v / getFrameRate();
                            if (mpicn_sItemIcon->mCells[cellCount].mDrawPos.mUnk_04 > 0) {
                                mpicn_sItemIcon->mCells[cellCount].mCell = cell;
                                mpicn_sItemIcon->mCells[cellCount].mUnk_0c =
                                    m2d_isPointOnLowerMap(position) != 0 ? 2 : 3;
                                mpicn_sItemIcon->mCells[cellCount].mUnk_0e = 0;
                                cellCount++;
                            }
                        }
                    }
                }
            } else if (tableIndex == 6) {
                if (((ItemBomb *) object)->mVisible != FALSE && position != NULL) {
                    if (lmap_20B5AE8(
                            position, &mpicn_sItemIcon->mCells[cellCount].mDrawPos, a, 1, 1) != FALSE) {
                        if (mobj_20D3D10(position->y) == 0) {
                            mpicn_sItemIcon->mCells[cellCount].mCell = cell;
                            mpicn_sItemIcon->mCells[cellCount].mUnk_0c =
                                m2d_isPointOnLowerMap(position) != 0 ? 2 : 3;
                            mpicn_sItemIcon->mCells[cellCount].mUnk_0e =
                                (object->mFlags & 0x40000) != 0 ? 1 : 0;
                            cellCount++;
                        }
                    }
                }
            } else {
                if (position != NULL) {
                    if (lmap_20B5AE8(
                            position, &mpicn_sItemIcon->mCells[cellCount].mDrawPos, a, 1, 1) != FALSE) {
                        if (mobj_20D3D10(position->y) == 0) {
                            mpicn_sItemIcon->mCells[cellCount].mCell = cell;
                            mpicn_sItemIcon->mCells[cellCount].mUnk_0c =
                                m2d_isPointOnLowerMap(position) != 0 ? 2 : 3;
                            mpicn_sItemIcon->mCells[cellCount].mUnk_0e =
                                (object->mFlags & 0x40000) != 0 ? 1 : 0;
                            cellCount++;
                        }
                    }
                }
            }
        }
    }
    mpicn_sItemIcon->mCellCount = cellCount;
}

void mpicn_renderItemIcon(RaceHudOamBuffer *oamBuffer) {
    mpicn_renderMObjIcon(oamBuffer, mpicn_sItemIcon, 0);
}

s32 mpicn_createDriverIcon(void) {
    s32 i;

    gRaceHudSubScreenKarts = heap_alloc(proc_getHeap(proc_getCurrent()), 0x194);
    mpicn_20C0BA8(&gRaceHudSubScreenKarts->mUnk_190, 0x18);
    for (i = 0; i < 8; i++) {
        gRaceHudSubScreenKarts->mUnk_000[i] = 0;
        gRaceHudSubScreenKarts->mUnk_020[i] = 0;
        gRaceHudSubScreenKarts->mUnk_060[i].mUnk_00 = 0;
        gRaceHudSubScreenKarts->mUnk_060[i].mUnk_04 = 0;
        gRaceHudSubScreenKarts->mUnk_100[i] = 0;
        gRaceHudSubScreenKarts->mUnk_130[i] = 0;
    }
    return 1;
}

void mpicn_destroyDriverIcon(void) {
    mpicn_destroyMObjIcon(&gRaceHudSubScreenKarts->mUnk_190);
    gRaceHudSubScreenKarts = NULL;
}

void mpicn_updateDriverIcon(void) {
    s32 sortKeys[8];
    u32 a;
    u16 i;
    Vec3 kartPosition;
    Vec3 w;
    Vec3 t;
    ItemObject **objects;
    s32 objectCount;
    s32 cellCount;
    s32 j;
    s32 f;
    ItemObject *object;
    Vec3 *position;
    u32 b;
    ItemInUse *itemInUse;
    s32 screenX;
    s32 screenY;

    a = mpicn_20C0DB0();
    for (i = 0; i < (u32) gRaceMultiConfig->mKartCount; i++) {
        gRaceHudSubScreenKarts->mUnk_000[i] = 0;
        gRaceHudSubScreenKarts->mUnk_130[i] = i;
        sortKeys[i] = rstat_getPlace(i & 0xff);
    }
    switch (r2d_getMapMode()) {
        case 0:
            for (i = 0; i < (u32) gRaceMultiConfig->mKartCount; i++) {
                RefreshGlobalMapPosition(i, &gRaceHudSubScreenKarts->mUnk_060[i]);
                screenX = gRaceHudSubScreenKarts->mUnk_060[i].mUnk_00;
                screenY = gRaceHudSubScreenKarts->mUnk_060[i].mUnk_04;
                if (screenX > -0x10 && screenX < 0x110 && screenY > -0x10 && screenY < 0xd0 && func_0207a84c(i) == 0) {
                    gRaceHudSubScreenKarts->mUnk_000[i] = 1;
                    if (gRaceMultiConfig->mMode == MODE_TIME_ATTACK &&
                        gRaceMultiConfig->mCurrentEntries[i].mPlayer.mKind == PLAYER_KIND_GHOST) {
                        gRaceHudSubScreenKarts->mUnk_040[i] = 1;
                    } else {
                        gRaceHudSubScreenKarts->mUnk_040[i] = 0;
                    }
                    driver_getScale(&gRaceHudSubScreenKarts->mUnk_0a0[i], i);
                    if (driver_getById(i)->mState != KART_STATE_NORMAL) {
                        gRaceHudSubScreenKarts->mUnk_110[i]++;
                        gRaceHudSubScreenKarts->mUnk_100[i] = (gRaceHudSubScreenKarts->mUnk_110[i] << 12) % 0x10000;
                    } else {
                        gRaceHudSubScreenKarts->mUnk_100[i] = 0;
                        gRaceHudSubScreenKarts->mUnk_110[i] = 0;
                    }
                }
            }
            break;
        case 1:
        case 2:
        case 3:
            gRaceHudSubScreenKarts->mUnk_190->mCellCount = 0;
            for (i = 0; i < (u32) gRaceMultiConfig->mKartCount; i++) {
                driver_getPosition(&kartPosition, i & 0xff);
                ComputeRaceHudSubScreenKartPosition(i, &gRaceHudSubScreenKarts->mUnk_060[i], a);
                screenX = gRaceHudSubScreenKarts->mUnk_060[i].mUnk_00;
                screenY = gRaceHudSubScreenKarts->mUnk_060[i].mUnk_04;
                if (screenX > -0x10 && screenX < 0x110 && screenY > -0x10 && screenY < 0xd0 && func_0207a84c(i) == 0) {
                    gRaceHudSubScreenKarts->mUnk_000[i] = 1;
                    gRaceHudSubScreenKarts->mUnk_040[i] = func_020b4dc4(i);
                    driver_getScale(&gRaceHudSubScreenKarts->mUnk_0a0[i], i);
                    if (driver_getById(i)->mState != KART_STATE_NORMAL) {
                        gRaceHudSubScreenKarts->mUnk_110[i]++;
                        gRaceHudSubScreenKarts->mUnk_100[i] = (gRaceHudSubScreenKarts->mUnk_110[i] << 12) % 0x10000;
                    } else {
                        gRaceHudSubScreenKarts->mUnk_100[i] = 0;
                        gRaceHudSubScreenKarts->mUnk_110[i] = 0;
                    }
                    gRaceHudSubScreenKarts->mUnk_150[i] = m2d_isPointOnLowerMap(&kartPosition) != 0 ? 2 : 3;
                    itemInUse = &it_sDriverItemStatus[i].mItemInUse;
                    objects = itemInUse->mObjects;
                    objectCount = itemInUse->mObjectCount;
                    cellCount = gRaceHudSubScreenKarts->mUnk_190->mCellCount;
                    b = mpicn_20C0DB0();
                    for (j = 0; j < objectCount; j++) {
                        object = objects[j];
                        if ((object->mFlags & 0x80000) != 0) {
                            position = NULL;
                        } else {
                            position = &object->mPos;
                        }
                        f = func_020f91e0(object);
                        if (position != NULL && f != 0) {
                            ComputePointAlongLine(&t, &kartPosition, position);
                            w = t;
                            if (lmap_20B5AE8(
                                    &w, &gRaceHudSubScreenKarts->mUnk_190->mCells[cellCount].mDrawPos, b, 0, 1) !=
                                FALSE) {
                                switch (object->mKind) {
                                    case 0:
                                        gRaceHudSubScreenKarts->mUnk_190->mCells[cellCount].mCell =
                                            r2d_getRaceSCell(0x4c);
                                        break;
                                    case 1:
                                        gRaceHudSubScreenKarts->mUnk_190->mCells[cellCount].mCell =
                                            r2d_getRaceSCell(0x4d);
                                        break;
                                    case 2:
                                        gRaceHudSubScreenKarts->mUnk_190->mCells[cellCount].mCell =
                                            r2d_getRaceSCell(0x4b);
                                        break;
                                    case 5:
                                        gRaceHudSubScreenKarts->mUnk_190->mCells[cellCount].mCell =
                                            r2d_getRaceSCell(0x56);
                                        break;
                                    case 9:
                                        gRaceHudSubScreenKarts->mUnk_190->mCells[cellCount].mCell =
                                            r2d_getRaceSCell(0x55);
                                        break;
                                    case 7:
                                        gRaceHudSubScreenKarts->mUnk_190->mCells[cellCount].mCell =
                                            r2d_getRaceSCell(0x54);
                                        break;
                                    case 8:
                                        gRaceHudSubScreenKarts->mUnk_190->mCells[cellCount].mCell =
                                            r2d_getRaceSCell(0x4e);
                                        break;
                                    default:
                                        gRaceHudSubScreenKarts->mUnk_190->mCells[cellCount].mCell =
                                            r2d_getRaceSCell(0x4c);
                                        break;
                                }
                                gRaceHudSubScreenKarts->mUnk_190->mCells[cellCount].mUnk_0c =
                                    m2d_isPointOnLowerMap(&w) != 0 ? 2 : 3;
                                gRaceHudSubScreenKarts->mUnk_190->mCells[cellCount].mUnk_0e =
                                    (object->mFlags & 0x40000) != 0 ? 1 : 0;
                                cellCount++;
                            }
                        }
                    }
                    gRaceHudSubScreenKarts->mUnk_190->mCellCount = cellCount;
                }
            }
            break;
    }
    for (i = 0; i < (u32) gRaceMultiConfig->mKartCount; i++) {
        if (driver_getCollisionMode(i) == 1) {
            gRaceHudSubScreenKarts->mUnk_170[i]++;
        } else {
            gRaceHudSubScreenKarts->mUnk_170[i] = 0;
        }
        if (i != Race_GetPlayerId() && (driver_getById(i)->mUnk_7c & 0x402000) != 0) {
            gRaceHudSubScreenKarts->mUnk_020[i] = 1;
        } else {
            gRaceHudSubScreenKarts->mUnk_020[i] = 0;
        }
    }
    for (i = 0; i < (u32) gRaceMultiConfig->mKartCount; i++) {
        if (gRaceHudSubScreenKarts->mUnk_040[i] == 0) {
            sortKeys[i] -= 0x20;
        }
        if (i == Race_GetPlayerId()) {
            sortKeys[i] -= 0x10;
        }
    }
    if (gRaceMultiConfig->mMode == MODE_TIME_ATTACK) {
        return;
    }
    SortIndicesByKey(gRaceHudSubScreenKarts->mUnk_130, sortKeys, gRaceMultiConfig->mKartCount);
}

static inline void func_020c8dbc_inline(RaceHudOamBuffer *oamBuffer, Unk020224e0_c *cell, s32 *matrix, s32 x, s32 y,
                                        u16 v, s32 s, s32 g) {
    s32 position[2];
    s32 oamIndex;
    RaceHudOamBits *oam;

    oamIndex = oamBuffer->mOamCount;
    position[0] = x << 12;
    position[1] = y << 12;
    oam = &oamBuffer->mOamBits[oamIndex];
    oamBuffer->mOamCount += NNS_G2dMakeCellToOams((GXOamAttr *) oam, 0x80 - oamIndex, cell, matrix, position, v, 1);
    for (; oamIndex < oamBuffer->mOamCount; oamIndex++) {
        if (s != -1) {
            oam->mUnk_0a = s;
        }
        if (g != -1) {
            oam->mUnk_0e = g;
        }
        oam++;
    }
}

static inline void func_020c8dbc_inline2(RaceHudOamBuffer *oamBuffer, Unk020224e0_c *cell, s32 x, s32 y) {
    s32 position[2];
    s32 oamIndex;

    position[0] = x << 12;
    position[1] = y << 12;
    oamIndex = oamBuffer->mOamCount;
    oamBuffer->mOamCount +=
        NNS_G2dMakeCellToOams(&oamBuffer->mOams[oamIndex], 0x80 - oamIndex, cell, NULL, position, 0, 1);
}

static inline void func_020c8dbc_inline3(RaceHudOamBuffer *oamBuffer, s32 kartIndex, s32 frame) {
    s32 j;
    s32 angleIndex;
    s32 offsetX;
    s32 offsetY;
    Unk020224e0_c *cell;

    for (j = 0; j < 3; j++) {
        angleIndex = (u16) (((frame + 12 - j * 4) << 16) / 64) >> 4;
        offsetX = (s16) FX_SinCosTable_[angleIndex * 2 + 1] * 11 >> 12;
        offsetY = (s16) FX_SinCosTable_[angleIndex * 2] * 11 >> 12;
        cell = r2d_getRaceSCell(frame % 12 < 6 ? 93 + j * 2 : 94 + j * 2);
        func_020c8dbc_inline2(oamBuffer, cell, gRaceHudSubScreenKarts->mUnk_060[kartIndex].mUnk_00 + offsetX,
                              gRaceHudSubScreenKarts->mUnk_060[kartIndex].mUnk_04 + offsetY);
    }
}

void mpicn_renderDriverIcon(RaceHudOamBuffer *oamBuffer) {
    s32 kartIndex;
    s32 f;
    Unk020224e0_c *cell;
    s32 rotationMatrix[4];
    s32 r1[4];
    s32 drawOrderIndex;
    s32 g;
    s32 b;
    u16 rotationSlot;
    u16 angle;
    s32 a;
    u16 n;
    s32 screenX;
    s32 screenY;

    switch (r2d_getMapMode()) {
        case 0:
            for (drawOrderIndex = 0; drawOrderIndex < gRaceMultiConfig->mKartCount; drawOrderIndex++) {
                kartIndex = gRaceHudSubScreenKarts->mUnk_130[drawOrderIndex];
                if (gRaceHudSubScreenKarts->mUnk_000[kartIndex] != 0) {
                    f = gRaceHudSubScreenKarts->mUnk_040[kartIndex];
                    if (gRaceHudSubScreenKarts->mUnk_020[kartIndex] == 0) {
                        if (gRaceHudSubScreenKarts->mUnk_0a0[kartIndex].y != 0x1000 ||
                            gRaceHudSubScreenKarts->mUnk_110[kartIndex] != 0) {
                            rotationSlot = oam_getAffineId(oamBuffer);
                            lmap_rotScaleMtx22(rotationMatrix,
                                                             gRaceHudSubScreenKarts->mUnk_0a0[kartIndex].y,
                                                             gRaceHudSubScreenKarts->mUnk_100[kartIndex]);
                            if (driver_getCollisionMode((u16) kartIndex) == 3) {
                                cell = r2d_getRaceSCell(0x10);
                            } else {
                                cell = r2d_getRaceSCell(kartIndex);
                            }
                            func_020c8dbc_inline(
                                oamBuffer, cell, rotationMatrix, gRaceHudSubScreenKarts->mUnk_060[kartIndex].mUnk_00,
                                gRaceHudSubScreenKarts->mUnk_060[kartIndex].mUnk_04, rotationSlot, f != 0 ? 1 : -1, -1);
                            oamBuffer->mMatrices[rotationSlot].mUnk_06 = rotationMatrix[0] >> 4;
                            oamBuffer->mMatrices[rotationSlot].mUnk_0e = rotationMatrix[1] >> 4;
                            oamBuffer->mMatrices[rotationSlot].mUnk_16 = rotationMatrix[2] >> 4;
                            oamBuffer->mMatrices[rotationSlot].mUnk_1e = rotationMatrix[3] >> 4;
                        } else {
                            if (driver_getCollisionMode((u16) kartIndex) == 3) {
                                cell = r2d_getRaceSCell(0x10);
                            } else {
                                cell = r2d_getRaceSCell(kartIndex);
                            }
                            func_020c8dbc_inline(
                                oamBuffer, cell, NULL, gRaceHudSubScreenKarts->mUnk_060[kartIndex].mUnk_00,
                                gRaceHudSubScreenKarts->mUnk_060[kartIndex].mUnk_04, 0, f != 0 ? 1 : -1, -1);
                        }
                    }
                    if (gRaceHudSubScreenKarts->mUnk_170[kartIndex] != 0) {
                        func_020c8dbc_inline3(oamBuffer, kartIndex, gRaceHudSubScreenKarts->mUnk_170[kartIndex]);
                    }
                }
            }
            break;
        case 1:
        case 2:
        case 3:
            a = mpicn_getMinPriority();
            for (drawOrderIndex = 0; drawOrderIndex < gRaceMultiConfig->mKartCount; drawOrderIndex++) {
                kartIndex = gRaceHudSubScreenKarts->mUnk_130[drawOrderIndex];
                g = gRaceHudSubScreenKarts->mUnk_150[kartIndex];
                if (gRaceHudSubScreenKarts->mUnk_000[kartIndex] != 0 && a <= g) {
                    if (gRaceHudSubScreenKarts->mUnk_020[kartIndex] == 0) {
                        screenX = gRaceHudSubScreenKarts->mUnk_060[kartIndex].mUnk_00;
                        screenY = gRaceHudSubScreenKarts->mUnk_060[kartIndex].mUnk_04;
                        b = gRaceHudSubScreenKarts->mUnk_040[kartIndex];
                        if (gRaceHudSubScreenKarts->mUnk_0a0[kartIndex].y != 0x1000 ||
                            gRaceHudSubScreenKarts->mUnk_110[kartIndex] != 0) {
                            n = oam_getAffineId(oamBuffer);
                            if (gRaceHudSubScreenKarts->mUnk_110[kartIndex] != 0) {
                                angle = gRaceHudSubScreenKarts->mUnk_100[kartIndex] +
                                        m2d_20B6368();
                            } else {
                                angle = 0;
                            }
                            lmap_rotScaleMtx22(r1, gRaceHudSubScreenKarts->mUnk_0a0[kartIndex].y, angle);
                            if (driver_getCollisionMode((u16) kartIndex) == 3) {
                                cell = r2d_getRaceSCell(0x10);
                            } else {
                                cell = r2d_getRaceSCell(kartIndex);
                            }
                            func_020c8dbc_inline(oamBuffer, cell, r1, screenX, screenY, n, b != 0 ? 1 : -1, g);
                            oamBuffer->mMatrices[n].mUnk_06 = r1[0] >> 4;
                            oamBuffer->mMatrices[n].mUnk_0e = r1[1] >> 4;
                            oamBuffer->mMatrices[n].mUnk_16 = r1[2] >> 4;
                            oamBuffer->mMatrices[n].mUnk_1e = r1[3] >> 4;
                        } else {
                            if (driver_getCollisionMode((u16) kartIndex) == 3) {
                                cell = r2d_getRaceSCell(0x10);
                            } else {
                                cell = r2d_getRaceSCell(kartIndex);
                            }
                            func_020c8dbc_inline(oamBuffer, cell, NULL, screenX, screenY, 0, b != 0 ? 1 : -1, g);
                        }
                    }
                    if (gRaceHudSubScreenKarts->mUnk_170[kartIndex] != 0) {
                        func_020c8dbc_inline3(oamBuffer, kartIndex, gRaceHudSubScreenKarts->mUnk_170[kartIndex]);
                    }
                }
            }
            mpicn_renderMObjIcon(oamBuffer, gRaceHudSubScreenKarts->mUnk_190, 0);
            break;
    }
}

BOOL mpicn_createSecondHandIcon(void) {
    MapObjectList *kindEntry;
    s32 objectCount;

    kindEntry = mobj_getRenderPart0ForObjectId(MAP_OBJECT_KIND_SECOND_HAND);
    if (kindEntry == NULL) {
        return FALSE;
    }
    objectCount = func_02100094(kindEntry);
    if (objectCount == 0) {
        return FALSE;
    }
    mpicn_sSecondHandIcon = heap_alloc(proc_getHeap(proc_getCurrent()), 0x44);
    mpicn_sSecondHandIcon->mObjects = mobj_renderPartGetInstanceList(kindEntry);
    mpicn_sSecondHandIcon->mUnk_04 = objectCount;
    mpicn_sSecondHandIcon->mObjectCount = objectCount;
    return TRUE;
}

u32 mpicn_destroySecondHandIcon(void) {
    u32 address;
    u32 zero;
    address = (u32) &mpicn_sSecondHandIcon;
    zero = 0u;
    *(u32 *) ((address) + (0)) = zero;
    return address;
}

void mpicn_updateSecondHandIcon(void) {
    s32 i;
    u32 a;
    Unk020e1e98 *object;
    s32 extentZ;
    Vec3 *position;
    s32 deltaX;
    s32 deltaZ;
    Vec3 endPosition;

    a = mpicn_20C0DB0();
    for (i = 0; i < mpicn_sSecondHandIcon->mObjectCount; i++) {
        object = mpicn_sSecondHandIcon->mObjects[i];
        extentZ = object->mUnk_000.mExtent.z;
        position = &object->mUnk_000.mPos;
        deltaX = (s64) object->mUnk_000.mMatrix.mUnk_00[2].x * extentZ >> 12;
        deltaZ = (s64) object->mUnk_000.mMatrix.mUnk_00[2].z * extentZ >> 12;
        if (gRaceMultiConfig->mMirrorMode != 0) {
            mpicn_sSecondHandIcon->mAngles[i] = FX_Atan2Idx(-deltaZ, deltaX) + 0x8000;
        } else {
            mpicn_sSecondHandIcon->mAngles[i] = FX_Atan2Idx(deltaZ, deltaX);
        }
        lmap_20B5AE8(position, &mpicn_sSecondHandIcon->mDrawPositions[i], a, 0, 0);
        endPosition.x = position->x + deltaX;
        endPosition.z = position->z + deltaZ;
        lmap_20B5AE8(&endPosition, &mpicn_sSecondHandIcon->mUnk_2c[i], a, 0, 0);
    }
}

void mpicn_renderSecondHandIcon(RaceHudOamBuffer *oamBuffer) {
    Unk020224e0_c *cell;
    s32 rotationMatrix[4];
    u32 a;
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

    a = mpicn_getMinPriority();
    if (mpicn_sSecondHandIcon->mUnk_04 <= 0) {
        return;
    }
    if (a == 0) {
        if (gRaceMultiConfig->mMirrorMode != 0) {
            angle0 = mpicn_sSecondHandIcon->mAngles[0] - m2d_20B6368();
        } else {
            angle0 = mpicn_sSecondHandIcon->mAngles[0] + m2d_20B6368();
        }
        rotationSlot0 = oam_getAffineId(oamBuffer);
        lmap_rotMtx22(rotationMatrix, angle0);
        screenX0 = mpicn_sSecondHandIcon->mUnk_2c[0].mUnk_00;
        screenY0 = mpicn_sSecondHandIcon->mUnk_2c[0].mUnk_04;
        if (screenX0 > -32 && screenX0 < 288 && screenY0 > -32 && screenY0 < 224) {
            cell = r2d_getRaceSCell(156);
            endPosition0[0] = screenX0 << 12;
            endPosition0[1] = screenY0 << 12;
            oamBuffer->mOamCount +=
                NNS_G2dMakeCellToOams(&oamBuffer->mOams[oamBuffer->mOamCount], 0x80 - oamBuffer->mOamCount, cell,
                                      rotationMatrix, endPosition0, rotationSlot0, 1);
        }
        trailDeltaX0 =
            mpicn_sSecondHandIcon->mDrawPositions[0].mUnk_00 - mpicn_sSecondHandIcon->mUnk_2c[0].mUnk_00;
        trailDeltaY0 =
            mpicn_sSecondHandIcon->mDrawPositions[0].mUnk_04 - mpicn_sSecondHandIcon->mUnk_2c[0].mUnk_04;
        for (trailStep0 = 0, trailSumX0 = 0, trailSumY0 = 0; trailStep0 < 3; trailStep0++) {
            screenX0 = mpicn_sSecondHandIcon->mUnk_2c[0].mUnk_00 + (trailSumX0 + trailDeltaX0) / 4;
            screenY0 = mpicn_sSecondHandIcon->mUnk_2c[0].mUnk_04 + (trailSumY0 + trailDeltaY0) / 4;
            if (screenX0 > -32 && screenX0 < 288 && screenY0 > -32 && screenY0 < 224) {
                cell = r2d_getRaceSCell(155);
                middlePosition0[0] = screenX0 << 12;
                middlePosition0[1] = screenY0 << 12;
                oamBuffer->mOamCount +=
                    NNS_G2dMakeCellToOams(&oamBuffer->mOams[oamBuffer->mOamCount], 0x80 - oamBuffer->mOamCount, cell,
                                          rotationMatrix, middlePosition0, rotationSlot0, 1);
            }
            trailSumX0 += trailDeltaX0;
            trailSumY0 += trailDeltaY0;
        }
        screenX0 = mpicn_sSecondHandIcon->mDrawPositions[0].mUnk_00;
        screenY0 = mpicn_sSecondHandIcon->mDrawPositions[0].mUnk_04;
        if (screenX0 > -32 && screenX0 < 288 && screenY0 > -32 && screenY0 < 224) {
            cell = r2d_getRaceSCell(154);
            drawPosition0[0] = screenX0 << 12;
            drawPosition0[1] = screenY0 << 12;
            oamBuffer->mOamCount +=
                NNS_G2dMakeCellToOams(&oamBuffer->mOams[oamBuffer->mOamCount], 0x80 - oamBuffer->mOamCount, cell,
                                      rotationMatrix, drawPosition0, rotationSlot0, 1);
        }
        oamBuffer->mMatrices[rotationSlot0].mUnk_06 = rotationMatrix[0] >> 4;
        oamBuffer->mMatrices[rotationSlot0].mUnk_0e = rotationMatrix[1] >> 4;
        oamBuffer->mMatrices[rotationSlot0].mUnk_16 = rotationMatrix[2] >> 4;
        oamBuffer->mMatrices[rotationSlot0].mUnk_1e = rotationMatrix[3] >> 4;
    }
    if (mpicn_sSecondHandIcon->mObjectCount == 3 && a == 0) {
        if (gRaceMultiConfig->mMirrorMode != 0) {
            angle2 = mpicn_sSecondHandIcon->mAngles[2] - m2d_20B6368();
        } else {
            angle2 = mpicn_sSecondHandIcon->mAngles[2] + m2d_20B6368();
        }
        rotationSlot2 = oam_getAffineId(oamBuffer);
        lmap_rotMtx22(rotationMatrix, angle2);
        screenX2 = mpicn_sSecondHandIcon->mUnk_2c[2].mUnk_00;
        screenY2 = mpicn_sSecondHandIcon->mUnk_2c[2].mUnk_04;
        if (screenX2 > -32 && screenX2 < 288 && screenY2 > -32 && screenY2 < 224) {
            cell = r2d_getRaceSCell(156);
            endPosition2[0] = screenX2 << 12;
            endPosition2[1] = screenY2 << 12;
            oamBuffer->mOamCount +=
                NNS_G2dMakeCellToOams(&oamBuffer->mOams[oamBuffer->mOamCount], 0x80 - oamBuffer->mOamCount, cell,
                                      rotationMatrix, endPosition2, rotationSlot2, 1);
        }
        trailDeltaX2 =
            mpicn_sSecondHandIcon->mDrawPositions[2].mUnk_00 - mpicn_sSecondHandIcon->mUnk_2c[2].mUnk_00;
        trailDeltaY2 =
            mpicn_sSecondHandIcon->mDrawPositions[2].mUnk_04 - mpicn_sSecondHandIcon->mUnk_2c[2].mUnk_04;
        for (trailStep2 = 0, trailSumX2 = 0, trailSumY2 = 0; trailStep2 < 2; trailStep2++) {
            screenX2 = mpicn_sSecondHandIcon->mUnk_2c[2].mUnk_00 + (trailSumX2 + trailDeltaX2) / 3;
            screenY2 = mpicn_sSecondHandIcon->mUnk_2c[2].mUnk_04 + (trailSumY2 + trailDeltaY2) / 3;
            if (screenX2 > -32 && screenX2 < 288 && screenY2 > -32 && screenY2 < 224) {
                cell = r2d_getRaceSCell(155);
                middlePosition2[0] = screenX2 << 12;
                middlePosition2[1] = screenY2 << 12;
                oamBuffer->mOamCount +=
                    NNS_G2dMakeCellToOams(&oamBuffer->mOams[oamBuffer->mOamCount], 0x80 - oamBuffer->mOamCount, cell,
                                          rotationMatrix, middlePosition2, rotationSlot2, 1);
            }
            trailSumX2 += trailDeltaX2;
            trailSumY2 += trailDeltaY2;
        }
        screenX2 = mpicn_sSecondHandIcon->mDrawPositions[2].mUnk_00;
        screenY2 = mpicn_sSecondHandIcon->mDrawPositions[2].mUnk_04;
        if (screenX2 > -32 && screenX2 < 288 && screenY2 > -32 && screenY2 < 224) {
            cell = r2d_getRaceSCell(154);
            drawPosition2[0] = screenX2 << 12;
            drawPosition2[1] = screenY2 << 12;
            oamBuffer->mOamCount +=
                NNS_G2dMakeCellToOams(&oamBuffer->mOams[oamBuffer->mOamCount], 0x80 - oamBuffer->mOamCount, cell,
                                      rotationMatrix, drawPosition2, rotationSlot2, 1);
        }
        oamBuffer->mMatrices[rotationSlot2].mUnk_06 = rotationMatrix[0] >> 4;
        oamBuffer->mMatrices[rotationSlot2].mUnk_0e = rotationMatrix[1] >> 4;
        oamBuffer->mMatrices[rotationSlot2].mUnk_16 = rotationMatrix[2] >> 4;
        oamBuffer->mMatrices[rotationSlot2].mUnk_1e = rotationMatrix[3] >> 4;
    }
    if (gRaceMultiConfig->mMirrorMode != 0) {
        angle1 = mpicn_sSecondHandIcon->mAngles[1] - m2d_20B6368();
    } else {
        angle1 = mpicn_sSecondHandIcon->mAngles[1] + m2d_20B6368();
    }
    rotationSlot1 = oam_getAffineId(oamBuffer);
    lmap_rotMtx22(rotationMatrix, angle1);
    screenX1 = mpicn_sSecondHandIcon->mUnk_2c[1].mUnk_00;
    screenY1 = mpicn_sSecondHandIcon->mUnk_2c[1].mUnk_04;
    if (screenX1 > -16 && screenX1 < 272 && screenY1 > -16 && screenY1 < 208) {
        cell = r2d_getRaceSCell(159);
        endPosition1[0] = screenX1 << 12;
        endPosition1[1] = screenY1 << 12;
        oamBuffer->mOamCount +=
            NNS_G2dMakeCellToOams(&oamBuffer->mOams[oamBuffer->mOamCount], 0x80 - oamBuffer->mOamCount, cell,
                                  rotationMatrix, endPosition1, rotationSlot1, 1);
    }
    trailDeltaX1 =
        mpicn_sSecondHandIcon->mDrawPositions[1].mUnk_00 - mpicn_sSecondHandIcon->mUnk_2c[1].mUnk_00;
    trailDeltaY1 =
        mpicn_sSecondHandIcon->mDrawPositions[1].mUnk_04 - mpicn_sSecondHandIcon->mUnk_2c[1].mUnk_04;
    for (trailStep1 = 0, trailSumX1 = 0, trailSumY1 = 0; trailStep1 < 3; trailStep1++) {
        screenX1 = mpicn_sSecondHandIcon->mUnk_2c[1].mUnk_00 + (trailSumX1 + trailDeltaX1) / 4;
        screenY1 = mpicn_sSecondHandIcon->mUnk_2c[1].mUnk_04 + (trailSumY1 + trailDeltaY1) / 4;
        if (screenX1 > -16 && screenX1 < 272 && screenY1 > -16 && screenY1 < 208) {
            cell = r2d_getRaceSCell(158);
            middlePosition1[0] = screenX1 << 12;
            middlePosition1[1] = screenY1 << 12;
            oamBuffer->mOamCount +=
                NNS_G2dMakeCellToOams(&oamBuffer->mOams[oamBuffer->mOamCount], 0x80 - oamBuffer->mOamCount, cell,
                                      rotationMatrix, middlePosition1, rotationSlot1, 1);
        }
        trailSumX1 += trailDeltaX1;
        trailSumY1 += trailDeltaY1;
    }
    screenX1 = mpicn_sSecondHandIcon->mDrawPositions[1].mUnk_00;
    screenY1 = mpicn_sSecondHandIcon->mDrawPositions[1].mUnk_04;
    if (screenX1 > -16 && screenX1 < 272 && screenY1 > -16 && screenY1 < 208) {
        cell = r2d_getRaceSCell(157);
        drawPosition1[0] = screenX1 << 12;
        drawPosition1[1] = screenY1 << 12;
        oamBuffer->mOamCount +=
            NNS_G2dMakeCellToOams(&oamBuffer->mOams[oamBuffer->mOamCount], 0x80 - oamBuffer->mOamCount, cell,
                                  rotationMatrix, drawPosition1, rotationSlot1, 1);
    }
    oamBuffer->mMatrices[rotationSlot1].mUnk_06 = rotationMatrix[0] >> 4;
    oamBuffer->mMatrices[rotationSlot1].mUnk_0e = rotationMatrix[1] >> 4;
    oamBuffer->mMatrices[rotationSlot1].mUnk_16 = rotationMatrix[2] >> 4;
    oamBuffer->mMatrices[rotationSlot1].mUnk_1e = rotationMatrix[3] >> 4;
}

BOOL mpicn_createCarTruckBusIcon(void) {
    u16 kinds[3] = {MAP_OBJECT_KIND_CAR_A, MAP_OBJECT_KIND_BUS_A, MAP_OBJECT_KIND_TRUCK_A};
    u16 i;
    u16 kind;

    for (i = 0; i < 3; i++) {
        kind = kinds[i];
        if (mobj_getRenderPart0ForObjectId(kind) != NULL) {
            return mpicn_createMapObjIcon(&mpicn_sCarTruckBusIcon, kind);
        }
    }
    return FALSE;
}

void mpicn_destroyCarTruckBusIcon(void) {
    mpicn_destroyMObjIcon(&mpicn_sCarTruckBusIcon);
}

void mpicn_updateCarTruckBusIcon(void) {
    s32 i;
    s32 cellCount;
    Unk020e1e98 *object;
    Vec3 *position;
    u32 a;
    u16 kind;
    u16 angle;

    cellCount = 0;
    a = mpicn_20C0DB0();
    for (i = 0; i < mpicn_sCarTruckBusIcon->mObjectCount; i++) {
        object = (Unk020e1e98 *) mpicn_sCarTruckBusIcon->mObjects[i];
        position = &object->mUnk_000.mPos;
        if (lmap_20B5AE8(&object->mUnk_000.mPos,
                                            &mpicn_sCarTruckBusIcon->mCells[cellCount].mDrawPos, a, 1, 1) != FALSE) {
            kind = object->mUnk_000.mKind;
            angle = object->mUnk_000.mAngle;
            switch (kind) {
                case MAP_OBJECT_KIND_CAR_A:
                    mpicn_sCarTruckBusIcon->mCells[cellCount].mCell = r2d_getRaceSCell(object->mUnk_130 + 0x95);
                    break;
                case MAP_OBJECT_KIND_BUS_A:
                    mpicn_sCarTruckBusIcon->mCells[cellCount].mCell = r2d_getRaceSCell(0x93);
                    break;
                case MAP_OBJECT_KIND_TRUCK_A:
                    mpicn_sCarTruckBusIcon->mCells[cellCount].mCell = r2d_getRaceSCell(0x94);
                    break;
            }
            mpicn_sCarTruckBusIcon->mCells[cellCount].mUnk_0c =
                m2d_isPointOnLowerMap((Vec3 *) &position) != 0 ? 2 : 3;
            mpicn_sCarTruckBusIcon->mCells[cellCount].mUnk_10 = angle;
            cellCount++;
        }
    }
    mpicn_sCarTruckBusIcon->mCellCount = cellCount;
}

void mpicn_renderCarTruckBusIcon(RaceHudOamBuffer *oamBuffer) {
    mpicn_renderMObjIcon(oamBuffer, mpicn_sCarTruckBusIcon, 1);
}

s32 mpicn_createKoopaBlockIcon(void) {
    return mpicn_createMapObjIcon(&mpicn_sKoopaBlockIcon, MAP_OBJECT_KIND_KOOPA_BLOCK);
}

void mpicn_destroyKoopaBlockIcon(void) {
    mpicn_destroyMObjIcon(&mpicn_sKoopaBlockIcon);
}

void mpicn_updateKoopaBlockIcon(void) {
    s32 i;
    s32 cellCount;
    u32 a;

    cellCount = 0;
    a = mpicn_20C0DB0();
    for (i = 0; i < mpicn_sKoopaBlockIcon->mObjectCount; i++) {
        if (lmap_20B5AE8(&mpicn_sKoopaBlockIcon->mObjects[i]->mPos,
                                            &mpicn_sKoopaBlockIcon->mCells[cellCount].mDrawPos, a, 1,
                                            0) != FALSE) {
            mpicn_sKoopaBlockIcon->mCells[cellCount].mCell = r2d_getRaceSCell(0x25);
            mpicn_sKoopaBlockIcon->mCells[cellCount].mUnk_0c = 2;
            cellCount++;
        }
    }
    mpicn_sKoopaBlockIcon->mCellCount = cellCount;
}

void mpicn_renderKoopaBlockIcon(RaceHudOamBuffer *oamBuffer) {
    mpicn_renderMObjIcon(oamBuffer, mpicn_sKoopaBlockIcon, 0);
}

s32 mpicn_createChoropuIcon(void) {
    return mpicn_createMapObjIcon(&mpicn_sChoropuIcon, MAP_OBJECT_KIND_CHOROPU);
}

void mpicn_destroyChoropuIcon(void) {
    mpicn_destroyMObjIcon(&mpicn_sChoropuIcon);
}

void mpicn_updateChoropuIcon(void) {
    s32 i;
    s32 cellCount;
    Unk0217b498_00 *object;
    u32 a;
    s32 height;
    s32 isPositiveHeight;

    cellCount = 0;
    a = mpicn_20C0DB0();
    for (i = 0; i < mpicn_sChoropuIcon->mObjectCount; i++) {
        if (IsRaceHudSubScreenPairNearCenter(&mpicn_sChoropuIcon->mUnk_0c[i]) != FALSE) {
            object = mpicn_sChoropuIcon->mObjects[i];
            if (lmap_20B5AE8(
                    &object->mPos, &mpicn_sChoropuIcon->mCells[cellCount].mDrawPos, a, 0, 0) != FALSE) {
                height = object->mPos.y - object->mUnk_a8;
                if (height >= -0x9000) {
                    isPositiveHeight = height > 0 ? 1 : 0;
                    mpicn_sChoropuIcon->mCells[cellCount].mCell =
                        r2d_getRaceSCell(isPositiveHeight != 0 ? 0xa7 : 0xa8);
                    mpicn_sChoropuIcon->mCells[cellCount].mUnk_0c = isPositiveHeight != 0 ? 1 : 2;
                    mpicn_sChoropuIcon->mCells[cellCount + 1].mDrawPos =
                        mpicn_sChoropuIcon->mCells[cellCount].mDrawPos;
                    mpicn_sChoropuIcon->mCells[cellCount + 1].mCell = r2d_getRaceSCell(0xa9);
                    mpicn_sChoropuIcon->mCells[cellCount + 1].mUnk_0c = 2;
                    cellCount += 2;
                    mpicn_sChoropuIcon->mCells[cellCount - 2].mDrawPos.mUnk_04 -= height >> 14;
                } else {
                    mpicn_sChoropuIcon->mCells[cellCount].mCell = r2d_getRaceSCell(0xa9);
                    mpicn_sChoropuIcon->mCells[cellCount].mUnk_0c = 2;
                    cellCount++;
                }
            }
        }
    }
    mpicn_sChoropuIcon->mCellCount = cellCount;
}

void mpicn_renderChoropuIcon(RaceHudOamBuffer *oamBuffer) {
    mpicn_renderMObjIcon(oamBuffer, mpicn_sChoropuIcon, 0);
}

s32 mpicn_createPukupukuIcon(void) {
    return mpicn_createMapObjIcon(&mpicn_sPukupukuIcon, MAP_OBJECT_KIND_PUKUPUKU);
}

void mpicn_destroyPukupukuIcon(void) {
    mpicn_destroyMObjIcon(&mpicn_sPukupukuIcon);
}

void mpicn_updatePukupukuIcon(void) {
    s32 i;
    s32 cellCount;
    Unk0217b498_00 *object;
    u32 a;

    cellCount = 0;
    a = mpicn_20C0DB0();
    for (i = 0; i < mpicn_sPukupukuIcon->mObjectCount; i++) {
        if (IsRaceHudSubScreenPairNearCenter(&mpicn_sPukupukuIcon->mUnk_0c[i]) != FALSE) {
            object = mpicn_sPukupukuIcon->mObjects[i];
            if ((object->mFlags & 2) == 0) {
                if (lmap_20B5AE8(
                        &object->mPos, &mpicn_sPukupukuIcon->mCells[cellCount].mDrawPos, a, 0, 0) != FALSE) {
                    mpicn_sPukupukuIcon->mCells[cellCount].mCell = r2d_getRaceSCell(0x89);
                    mpicn_sPukupukuIcon->mCells[cellCount].mUnk_0c = 2;
                    cellCount++;
                }
            }
        }
    }
    mpicn_sPukupukuIcon->mCellCount = cellCount;
}

void mpicn_renderPukupukuIcon(RaceHudOamBuffer *oamBuffer) {
    mpicn_renderMObjIcon(oamBuffer, mpicn_sPukupukuIcon, 0);
}

s32 mpicn_createMoveTreeIcon(void) {
    return mpicn_createMapObjIcon(&mpicn_sMoveTreeIcon, MAP_OBJECT_KIND_MOVE_TREE);
}

void mpicn_destroyMoveTreeIcon(void) {
    mpicn_destroyMObjIcon(&mpicn_sMoveTreeIcon);
}

void mpicn_updateMoveTreeIcon(void) {
    s32 i;
    s32 cellCount;
    u32 a;

    cellCount = 0;
    a = mpicn_20C0DB0();
    for (i = 0; i < mpicn_sMoveTreeIcon->mObjectCount; i++) {
        if (lmap_20B5AE8(&mpicn_sMoveTreeIcon->mObjects[i]->mPos,
                                            &mpicn_sMoveTreeIcon->mCells[cellCount].mDrawPos, a, 1,
                                            1) != FALSE) {
            mpicn_sMoveTreeIcon->mCells[cellCount].mCell = r2d_getRaceSCell(0x8b);
            mpicn_sMoveTreeIcon->mCells[cellCount].mUnk_0c = 2;
            cellCount++;
        }
    }
    mpicn_sMoveTreeIcon->mCellCount = cellCount;
}

void mpicn_renderMoveTreeIcon(RaceHudOamBuffer *oamBuffer) {
    mpicn_renderMObjIcon(oamBuffer, mpicn_sMoveTreeIcon, 0);
}

s32 mpicn_createSmanIcon(void) {
    return mpicn_createMapObjIcon(&mpicn_sSmanIcon, MAP_OBJECT_KIND_SMAN);
}

void mpicn_destroySmanIcon(void) {
    mpicn_destroyMObjIcon(&mpicn_sSmanIcon);
}

void mpicn_updateSmanIcon(void) {
    s32 i;
    s32 cellCount;
    Unk0217b498_00 *object;
    u32 a;

    cellCount = 0;
    a = mpicn_20C0DB0();
    for (i = 0; i < mpicn_sSmanIcon->mObjectCount; i++) {
        if (IsRaceHudSubScreenPairNearCenter(&mpicn_sSmanIcon->mUnk_0c[i]) != FALSE) {
            object = mpicn_sSmanIcon->mObjects[i];
            if ((object->mFlags & 1) == 0) {
                if (lmap_20B5AE8(
                        &object->mPos, &mpicn_sSmanIcon->mCells[cellCount].mDrawPos, a, 0, 0) != FALSE) {
                    mpicn_sSmanIcon->mCells[cellCount].mCell = r2d_getRaceSCell(0x98);
                    mpicn_sSmanIcon->mCells[cellCount].mUnk_0c = 2;
                    cellCount++;
                }
            }
        }
    }
    mpicn_sSmanIcon->mCellCount = cellCount;
}

void mpicn_renderSmanIcon(RaceHudOamBuffer *oamBuffer) {
    mpicn_renderMObjIcon(oamBuffer, mpicn_sSmanIcon, 0);
}

s32 mpicn_createDossunIcon(void) {
    return mpicn_createMapObjIcon(&mpicn_sDossunIcon, MAP_OBJECT_KIND_DOSSUN);
}

void mpicn_destroyDossunIcon(void) {
    mpicn_destroyMObjIcon(&mpicn_sDossunIcon);
}

void mpicn_updateDossunIcon(void) {
    s32 i;
    s32 cellCount;
    Unk0217b498_00 *object;
    u32 a;
    s32 offset;

    cellCount = 0;
    a = mpicn_20C0DB0();
    for (i = 0; i < mpicn_sDossunIcon->mObjectCount; i++) {
        if (IsRaceHudSubScreenPairNearCenter(&mpicn_sDossunIcon->mUnk_0c[i]) != FALSE) {
            object = mpicn_sDossunIcon->mObjects[i];
            if (lmap_20B5AE8(
                    &object->mPos, &mpicn_sDossunIcon->mCells[cellCount].mDrawPos, a, 0, 0) != FALSE) {
                mpicn_sDossunIcon->mCells[cellCount].mCell = r2d_getRaceSCell(0xaf);
                mpicn_sDossunIcon->mCells[cellCount].mUnk_0c = 1;
                mpicn_sDossunIcon->mCells[cellCount + 1].mDrawPos =
                    mpicn_sDossunIcon->mCells[(u32) cellCount].mDrawPos;
                mpicn_sDossunIcon->mCells[cellCount + 1].mCell = r2d_getRaceSCell(0xb0);
                mpicn_sDossunIcon->mCells[cellCount + 1].mUnk_0c = 2;
                cellCount += 2;
                offset = dossun_getMapElevation((Dossun *) object) * 16 >> 12;
                mpicn_sDossunIcon->mCells[cellCount - 2].mDrawPos.mUnk_04 -= offset;
            }
        }
    }
    mpicn_sDossunIcon->mCellCount = cellCount;
}

void mpicn_renderDossunIcon(RaceHudOamBuffer *oamBuffer) {
    mpicn_renderMObjIcon(oamBuffer, mpicn_sDossunIcon, 0);
}

BOOL mpicn_createWanwanIcon(void) {
    u16 kinds[2] = {0x196, 0x1a5};
    u16 i;
    u16 kind;

    for (i = 0; i < 2; i++) {
        kind = kinds[i];
        if (mobj_getRenderPart0ForObjectId(kind) != NULL) {
            return mpicn_createMapObjIcon(&mpicn_sWanwanIcon, kind);
        }
    }
    return FALSE;
}

void mpicn_destroyWanwanIcon(void) {
    mpicn_destroyMObjIcon(&mpicn_sWanwanIcon);
}

void mpicn_updateWanwanIcon(void) {
    s32 i;
    s32 cellCount;
    u32 a;

    cellCount = 0;
    a = mpicn_20C0DB0();
    for (i = 0; i < mpicn_sWanwanIcon->mObjectCount; i++) {
        if (lmap_20B5AE8(&mpicn_sWanwanIcon->mObjects[i]->mPos,
                                            &mpicn_sWanwanIcon->mCells[cellCount].mDrawPos, a, 1,
                                            0) != FALSE) {
            mpicn_sWanwanIcon->mCells[cellCount].mCell = r2d_getRaceSCell(0xac);
            mpicn_sWanwanIcon->mCells[cellCount].mUnk_0c = 1;
            cellCount++;
        }
    }
    mpicn_sWanwanIcon->mCellCount = cellCount;
}

void mpicn_renderWanwanIcon(RaceHudOamBuffer *oamBuffer) {
    mpicn_renderMObjIcon(oamBuffer, mpicn_sWanwanIcon, 0);
}

s32 mpicn_createEarthenPipeIcon(void) {
    return mpicn_createMapObjIcon(&mpicn_sEarthenPipeIcon, MAP_OBJECT_KIND_EARTHEN_PIPE);
}

void mpicn_destroyEarthenPipeIcon(void) {
    mpicn_destroyMObjIcon(&mpicn_sEarthenPipeIcon);
}

void mpicn_updateEarthenPipeIcon(void) {
    s32 i;
    s32 cellCount;
    Unk0217b498_00 *object;
    Vec3 *position;
    u32 a;

    cellCount = 0;
    a = mpicn_20C0DB0();
    for (i = 0; i < mpicn_sEarthenPipeIcon->mObjectCount; i++) {
        if (IsRaceHudSubScreenPairNearCenter(&mpicn_sEarthenPipeIcon->mUnk_0c[i]) != FALSE) {
            object = mpicn_sEarthenPipeIcon->mObjects[i];
            if ((object->mFlags & 1) == 0) {
                position = &object->mPos;
                if (lmap_20B5AE8(
                        position, &mpicn_sEarthenPipeIcon->mCells[cellCount].mDrawPos, a, 0, 0) != FALSE) {
                    mpicn_sEarthenPipeIcon->mCells[cellCount].mCell = r2d_getRaceSCell(0x8c);
                    mpicn_sEarthenPipeIcon->mCells[cellCount].mUnk_0c =
                        m2d_isPointOnLowerMap(position) != 0 ? 2 : 3;
                    cellCount++;
                }
            }
        }
    }
    mpicn_sEarthenPipeIcon->mCellCount = cellCount;
}

void mpicn_renderEarthenPipeIcon(RaceHudOamBuffer *oamBuffer) {
    mpicn_renderMObjIcon(oamBuffer, mpicn_sEarthenPipeIcon, 0);
}

s32 mpicn_createItemboxIcon(void) {
    u16 kinds[2] = {MAP_OBJECT_KIND_ITEM_BOX, 0xc9};
    u16 i;
    u16 kind;
    s32 created;
    s32 highest;
    s32 j;

    for (i = 0; i < 2; i++) {
        kind = kinds[i];
        if (mobj_getRenderPart0ForObjectId(kind) != NULL) {
            created = mpicn_createMapObjIcon(&mpicn_sItemboxIcon, kind);
            highest = 0;
            for (j = 0; j < mpicn_sItemboxIcon->mObjectCount; j++) {
                s32 v = func_020de9f8((ItemBox *) mpicn_sItemboxIcon->mObjects[j]);
                if (v > highest) {
                    highest = v;
                }
            }
            if (highest < 0x3e8000) {
                data_0217b3f8 = 1;
            } else {
                data_0217b3f8 = 0;
            }
            return created;
        }
    }
    return 0;
}
