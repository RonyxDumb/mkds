#include "Main/Race/RaceHudSubScreenObjects.h"

#include "Main/Unknown/code_020c06c4.h"
#include "Main/Unknown/code_020c0b84.h"
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
#include "Main/Unknown/code_020c0d9c.h"
#include "Main/Unknown/unk_0217b000.h"
#include "Main/Unknown/code_020cce10.h"
#include "Main/Unknown/code_020c0ba8.h"
#include "Main/Unknown/code_020ade08.h"
#include "code_020222ec.h"
#include "Main/Unknown/code_020ae000.h"
#include "Main/Unknown/code_02095f30.h"
#include "Main/Unknown/code_02095f38.h"
#include "Main/Unknown/code_02095000.h"
#include "Main/Unknown/code_020931ac.h"
#include "Main/Unknown/code_02092194.h"
#include "Main/Unknown/code_021000d0.h"

void mpicn_destroyRainStarIcon(void) {
    mpicn_destroyMObjIcon(&mpicn_sRainStarIcon);
}

void mpicn_updateRainStarIcon(void) {
    s32 i;
    s32 cellCount;
    u32 n;
    Unk0217b498_00 *object;
    Vec3 *position;

    cellCount = 0;
    n = mpicn_20C0DB0();
    for (i = 0; i < mpicn_sRainStarIcon->mObjectCount; i++) {
        object = mpicn_sRainStarIcon->mObjects[i];
        position = &object->mPos;
        if (lmap_20B5AE8(position, &mpicn_sRainStarIcon->mCells[cellCount].mDrawPos, n, 1,
                                            1) != FALSE) {
            mpicn_sRainStarIcon->mCells[cellCount].mCell = r2d_getRaceSCell(0xb3);
            mpicn_sRainStarIcon->mCells[cellCount].fieldC = m2d_isPointOnLowerMap(position) != 0 ? 2 : 3;
            mpicn_sRainStarIcon->mCells[cellCount].fieldE = 0;
            mpicn_sRainStarIcon->mCells[cellCount].field10 = object->mAngle;
            cellCount++;
        }
    }
    mpicn_sRainStarIcon->mCellCount = cellCount;
}

void mpicn_renderRainStarIcon(RaceHudOamBuffer *oamBuffer) {
    mpicn_renderMObjIcon(oamBuffer, mpicn_sRainStarIcon, 1);
}

s32 mpicn_createBasabasaIcon(void) {
    return mpicn_createMapObjIcon(&mpicn_sBasabasaIcon, MAP_OBJECT_KIND_BASABASA);
}

void mpicn_destroyBasabasaIcon(void) {
    mpicn_destroyMObjIcon(&mpicn_sBasabasaIcon);
}

void mpicn_updateBasabasaIcon(void) {
    s32 i;
    s32 cellCount;
    u32 n;
    u32 m;
    Unk0217b498_00 *object;
    Vec3 *position;
    void *cell;

    cellCount = 0;
    n = mpicn_20C0DB0();
    for (i = 0; i < mpicn_sBasabasaIcon->mObjectCount; i++) {
        object = mpicn_sBasabasaIcon->mObjects[i];
        if ((object->mFlags & 1) == 0) {
            m = basa_getMapIconType(object);
            if (m != 0) {
                position = &object->mPos;
                if (lmap_20B5AE8(
                        position, &mpicn_sBasabasaIcon->mCells[cellCount].mDrawPos, n, 1, 1) != FALSE) {
                    if (m == 2) {
                        cell = r2d_getRaceSCell(0xb5);
                    } else {
                        cell = r2d_getRaceSCell(0xb4);
                    }
                    mpicn_sBasabasaIcon->mCells[cellCount].mCell = cell;
                    mpicn_sBasabasaIcon->mCells[cellCount].fieldC =
                        m2d_isPointOnLowerMap(position) != 0 ? 2 : 3;
                    cellCount++;
                }
            }
        }
    }
    mpicn_sBasabasaIcon->mCellCount = cellCount;
}

void mpicn_renderBasabasaIcon(RaceHudOamBuffer *oamBuffer) {
    mpicn_renderMObjIcon(oamBuffer, mpicn_sBasabasaIcon, 0);
}

s32 mpicn_createMkdEfBubbleIcon(void) {
    return mpicn_createMapObjIcon(&mpicn_sMkdEfBubbleIcon, MAP_OBJECT_KIND_MKD_EF_BUBBLE);
}

void mpicn_destroyMkdEfBubbleIcon(void) {
    mpicn_destroyMObjIcon(&mpicn_sMkdEfBubbleIcon);
}

void mpicn_updateMkdEfBubbleIcon(void) {
    s32 i;
    s32 cellCount;
    u32 n;
    Unk0217b498_00 *object;
    s32 d;
    Vec3 *position;

    cellCount = 0;
    n = mpicn_20C0DB0();
    for (i = 0; i < mpicn_sMkdEfBubbleIcon->mObjectCount; i++) {
        if (IsRaceHudSubScreenPairNearCenter(&mpicn_sMkdEfBubbleIcon->fieldC[i]) != FALSE) {
            object = mpicn_sMkdEfBubbleIcon->mObjects[i];
            d = object->mPos.y - object->fieldAC;
            if (d >= 0) {
                position = &object->mPos;
                if (lmap_20B5AE8(
                        position, &mpicn_sMkdEfBubbleIcon->mCells[cellCount].mDrawPos, n, 0, 1) != FALSE) {
                    mpicn_sMkdEfBubbleIcon->mCells[cellCount].mDrawPos.field4 -= d >> 14;
                    mpicn_sMkdEfBubbleIcon->mCells[cellCount].mCell = r2d_getRaceSCell(0xb1);
                    mpicn_sMkdEfBubbleIcon->mCells[cellCount].fieldC =
                        m2d_isPointOnLowerMap(position) != 0 ? 2 : 3;
                    cellCount++;
                }
            }
        }
    }
    mpicn_sMkdEfBubbleIcon->mCellCount = cellCount;
}

void mpicn_renderMkdEfBubbleIcon(RaceHudOamBuffer *oamBuffer) {
    mpicn_renderMObjIcon(oamBuffer, mpicn_sMkdEfBubbleIcon, 0);
}

s32 mpicn_createBoundIcon(void) {
    return mpicn_createMapObjIcon(&mpicn_sBoundIcon, MAP_OBJECT_KIND_BOUND);
}

void mpicn_destroyBoundIcon(void) {
    mpicn_destroyMObjIcon(&mpicn_sBoundIcon);
}

void mpicn_updateBoundIcon(void) {
    s32 i;
    s32 cellCount;
    u32 n;
    Unk0217b498_00 *object;
    Vec3 *position;

    cellCount = 0;
    n = mpicn_20C0DB0();
    for (i = 0; i < mpicn_sBoundIcon->mObjectCount; i++) {
        object = mpicn_sBoundIcon->mObjects[i];
        position = &object->mPos;
        if (lmap_20B5AE8(position, &mpicn_sBoundIcon->mCells[cellCount].mDrawPos, n, 1,
                                            1) != FALSE) {
            mpicn_sBoundIcon->mCells[cellCount].mCell = r2d_getRaceSCell(0x91);
            mpicn_sBoundIcon->mCells[cellCount].fieldC = m2d_isPointOnLowerMap(position) != 0 ? 2 : 3;
            mpicn_sBoundIcon->mCells[cellCount].field10 = object->mAngle;
            mpicn_sBoundIcon->fieldC[cellCount].field0 = object->mScaleX / 6;
            cellCount++;
        }
    }
    mpicn_sBoundIcon->mCellCount = cellCount;
}

void mpicn_renderBoundIcon(RaceHudOamBuffer *oamBuffer) {
    mpicn_20C06C4(oamBuffer, mpicn_sBoundIcon, 1);
}

s32 mpicn_createMkdEfBurnerIcon(void) {
    return mpicn_createMapObjIcon(&mpicn_sMkdEfBurnerIcon, MAP_OBJECT_KIND_MKD_EF_BURNER);
}

void mpicn_destroyMkdEfBurnerIcon(void) {
    mpicn_destroyMObjIcon(&mpicn_sMkdEfBurnerIcon);
}

void mpicn_updateMkdEfBurnerIcon(void) {
    s32 i;
    s32 cellCount;
    s32 inFirstHalf;
    u32 n;
    Unk0217b498_00 *object;
    Vec3 *position;

    cellCount = 0;
    n = mpicn_20C0DB0();
    mpicn_sMkdEfBurnerIcon->fieldC[0].field4++;
    if (mpicn_sMkdEfBurnerIcon->fieldC[0].field4 < 0 ||
        mpicn_sMkdEfBurnerIcon->fieldC[0].field4 >= 8) {
        mpicn_sMkdEfBurnerIcon->fieldC[0].field4 = 0;
    }
    inFirstHalf = mpicn_sMkdEfBurnerIcon->fieldC[0].field4 < 4 ? 1 : 0;
    for (i = 0; i < mpicn_sMkdEfBurnerIcon->mObjectCount; i++) {
        object = mpicn_sMkdEfBurnerIcon->mObjects[i];
        if ((object->mFlags & 1) == 0 && efbnr_getMapIconType(object) != 0) {
            position = &object->mPos;
            if (lmap_20B5AE8(
                    position, &mpicn_sMkdEfBurnerIcon->mCells[cellCount].mDrawPos, n, 0, 0) != FALSE) {
                mpicn_sMkdEfBurnerIcon->mCells[cellCount].mCell =
                    r2d_getRaceSCell(gRaceMultiConfig->mCourseId == COURSE_ID_AIRSHIP ? 0xae : 0xb2);
                mpicn_sMkdEfBurnerIcon->mCells[cellCount].fieldC =
                    m2d_isPointOnLowerMap(position) != 0 ? 2 : 3;
                mpicn_sMkdEfBurnerIcon->fieldC[cellCount].field0 = inFirstHalf != 0 ? 0x1000 : 0xccd;
                cellCount++;
            }
        }
    }
    mpicn_sMkdEfBurnerIcon->mCellCount = cellCount;
}

void mpicn_renderMkdEfBurnerIcon(RaceHudOamBuffer *oamBuffer) {
    mpicn_20C06C4(oamBuffer, mpicn_sMkdEfBurnerIcon, 0);
}

BOOL mpicn_createSunFireSnakeIcon(void) {
    return mpicn_createMapObjIcon(&mpicn_sSunFireSnakeIcon, MAP_OBJECT_KIND_SUN_FIREBALL);
}

void mpicn_destroySunFireSnakeIcon(void) {
    mpicn_destroyMObjIcon(&mpicn_sSunFireSnakeIcon);
}

void mpicn_updateSunFireSnakeIcon(void) {
    s32 i;
    s32 cellCount;
    u32 n;
    Unk0217b498_00 *object;
    Vec3 *position;

    cellCount = 0;
    n = mpicn_20C0DB0();
    for (i = 0; i < mpicn_sSunFireSnakeIcon->mObjectCount; i++) {
        object = mpicn_sSunFireSnakeIcon->mObjects[i];
        if ((object->mFlags & 1) == 0) {
            position = &object->mPos;
            if (lmap_20B5AE8(
                    position, &mpicn_sSunFireSnakeIcon->mCells[cellCount].mDrawPos, n, 1, 1) != FALSE) {
                mpicn_sSunFireSnakeIcon->mCells[cellCount].mCell = r2d_getRaceSCell(0x8d);
                mpicn_sSunFireSnakeIcon->mCells[cellCount].fieldC =
                    m2d_isPointOnLowerMap(position) != 0 ? 2 : 3;
                cellCount++;
            }
        }
    }
    mpicn_sSunFireSnakeIcon->mCellCount = cellCount;
}

void mpicn_renderSunFireSnakeIcon(RaceHudOamBuffer *oamBuffer) {
    mpicn_renderMObjIcon(oamBuffer, mpicn_sSunFireSnakeIcon, 0);
}

s32 mpicn_createIronBallIcon(void) {
    return mpicn_createMapObjIcon(&mpicn_sIronBallIcon, MAP_OBJECT_KIND_IRON_BALL);
}

void mpicn_destroyIronBallIcon(void) {
    mpicn_destroyMObjIcon(&mpicn_sIronBallIcon);
}

void mpicn_updateIronBallIcon(void) {
    s32 i;
    s32 cellCount;
    u32 n;
    Unk0217b498_00 *object;
    Vec3 *position;

    cellCount = 0;
    n = mpicn_20C0DB0();
    for (i = 0; i < mpicn_sIronBallIcon->mObjectCount; i++) {
        object = mpicn_sIronBallIcon->mObjects[i];
        if ((object->mFlags & 2) == 0) {
            position = &object->mPos;
            if (lmap_20B5AE8(position, &mpicn_sIronBallIcon->mCells[cellCount].mDrawPos,
                                                n, 1, 1) != FALSE) {
                mpicn_sIronBallIcon->mCells[cellCount].mCell = r2d_getRaceSCell(0x92);
                mpicn_sIronBallIcon->mCells[cellCount].fieldC = m2d_isPointOnLowerMap(position) != 0 ? 2 : 3;
                mpicn_sIronBallIcon->mCells[cellCount].fieldE = object->mFlags & 0x20;
                cellCount++;
            }
        }
    }
    mpicn_sIronBallIcon->mCellCount = cellCount;
}

void mpicn_renderIronBallIcon(RaceHudOamBuffer *oamBuffer) {
    mpicn_renderMObjIcon(oamBuffer, mpicn_sIronBallIcon, 0);
}

s32 mpicn_createKuriboIcon(void) {
    return mpicn_createMapObjIcon(&mpicn_sKuriboIcon, MAP_OBJECT_KIND_KURIBO);
}

void mpicn_destroyKuriboIcon(void) {
    mpicn_destroyMObjIcon(&mpicn_sKuriboIcon);
}

void mpicn_updateKuriboIcon(void) {
    s32 i;
    s32 cellCount;
    u32 n;
    Unk0217b498_00 *object;
    Vec3 *position;

    cellCount = 0;
    n = mpicn_20C0DB0();
    for (i = 0; i < mpicn_sKuriboIcon->mObjectCount; i++) {
        object = mpicn_sKuriboIcon->mObjects[i];
        position = &object->mPos;
        if ((object->mFlags & 2) == 0) {
            if (lmap_20B5AE8(position, &mpicn_sKuriboIcon->mCells[cellCount].mDrawPos, n,
                                                0, 1) != FALSE) {
                mpicn_sKuriboIcon->mCells[cellCount].mCell = r2d_getRaceSCell(0xa3);
                mpicn_sKuriboIcon->mCells[cellCount].fieldC = m2d_isPointOnLowerMap(position) != 0 ? 2 : 3;
                cellCount++;
            }
        }
    }
    mpicn_sKuriboIcon->mCellCount = cellCount;
}

void mpicn_renderKuriboIcon(RaceHudOamBuffer *oamBuffer) {
    mpicn_renderMObjIcon(oamBuffer, mpicn_sKuriboIcon, 0);
}

s32 mpicn_createObPakkunSfIcon(void) {
    return mpicn_createMapObjIcon(&mpicn_sObPakkunSfIcon, MAP_OBJECT_KIND_OB_PAKKUN_SF);
}

void mpicn_destroyObPakkunSfIcon(void) {
    mpicn_destroyMObjIcon(&mpicn_sObPakkunSfIcon);
}

void mpicn_updateObPakkunSfIcon(void) {
    s32 i;
    s32 cellCount;
    u32 n;
    Unk0217b498_00 *object;
    Vec3 *position;

    cellCount = 0;
    n = mpicn_20C0DB0();
    for (i = 0; i < mpicn_sObPakkunSfIcon->mObjectCount; i++) {
        if (IsRaceHudSubScreenPairNearCenter(&mpicn_sObPakkunSfIcon->fieldC[i]) != FALSE) {
            object = mpicn_sObPakkunSfIcon->mObjects[i];
            if ((object->mFlags & 1) == 0) {
                position = &object->mPos;
                if (lmap_20B5AE8(
                        position, &mpicn_sObPakkunSfIcon->mCells[cellCount].mDrawPos, n, 0, 0) != FALSE) {
                    mpicn_sObPakkunSfIcon->mCells[cellCount].mCell =
                        r2d_getRaceSCell(((object->fieldB8 & 0x10) >> 4) != 0 ? 0xa2 : 0xa1);
                    mpicn_sObPakkunSfIcon->mCells[cellCount].fieldC =
                        m2d_isPointOnLowerMap(position) != 0 ? 2 : 3;
                    cellCount++;
                }
            }
        }
    }
    mpicn_sObPakkunSfIcon->mCellCount = cellCount;
}

void mpicn_renderObPakkunSfIcon(RaceHudOamBuffer *oamBuffer) {
    mpicn_renderMObjIcon(oamBuffer, mpicn_sObPakkunSfIcon, 0);
}

s32 mpicn_createPooIcon(void) {
    return mpicn_createMapObjIcon(&mpicn_sPooIcon, MAP_OBJECT_KIND_COVER_POO_HOLE);
}

void mpicn_destroyPooIcon(void) {
    mpicn_destroyMObjIcon(&mpicn_sPooIcon);
}

void mpicn_updatePooIcon(void) {
    s32 i;
    s32 cellCount;
    u32 n;
    Unk0217b498_00 *object;
    Vec3 *position;

    cellCount = 0;
    n = mpicn_20C0DB0();
    for (i = 0; i < mpicn_sPooIcon->mObjectCount; i++) {
        if (IsRaceHudSubScreenPairNearCenter(&mpicn_sPooIcon->fieldC[i]) != FALSE) {
            object = mpicn_sPooIcon->mObjects[i];
            if ((object->mFlags & 1) == 0) {
                position = &object->mPos;
                if (lmap_20B5AE8(
                        position, &mpicn_sPooIcon->mCells[cellCount].mDrawPos, n, 0, 0) != FALSE) {
                    mpicn_sPooIcon->mCells[cellCount].mDrawPos.field4 -=
                        poo_2095F30(object) >> 14;
                    mpicn_sPooIcon->mCells[cellCount].mCell =
                        r2d_getRaceSCell(poo_2095F38(object) != FALSE ? 0xab : 0xaa);
                    mpicn_sPooIcon->mCells[cellCount].fieldC =
                        m2d_isPointOnLowerMap(position) != 0 ? 2 : 3;
                    cellCount++;
                }
            }
        }
    }
    mpicn_sPooIcon->mCellCount = cellCount;
}

void mpicn_renderPooIcon(RaceHudOamBuffer *oamBuffer) {
    mpicn_renderMObjIcon(oamBuffer, mpicn_sPooIcon, 0);
}

s32 mpicn_createRock2Icon(void) {
    return mpicn_createMapObjIcon(&mpicn_sRock2Icon, MAP_OBJECT_KIND_ROCK2);
}

void mpicn_destroyRock2Icon(void) {
    mpicn_destroyMObjIcon(&mpicn_sRock2Icon);
}

void mpicn_updateRock2Icon(void) {
    s32 i;
    s32 cellCount;
    u32 n;
    Unk0217b498_00 *object;
    Vec3 *position;

    cellCount = 0;
    n = mpicn_20C0DB0();
    for (i = 0; i < mpicn_sRock2Icon->mObjectCount; i++) {
        object = mpicn_sRock2Icon->mObjects[i];
        if ((object->mFlags & 2) == 0) {
            position = &object->mPos;
            if (lmap_20B5AE8(position, &mpicn_sRock2Icon->mCells[cellCount].mDrawPos, n,
                                                1, 1) != FALSE) {
                mpicn_sRock2Icon->mCells[cellCount].mCell = r2d_getRaceSCell(0x8f);
                mpicn_sRock2Icon->mCells[cellCount].fieldC = m2d_isPointOnLowerMap(position) != 0 ? 2 : 3;
                mpicn_sRock2Icon->mCells[cellCount].field10 += 0x400;
                cellCount++;
            }
        }
    }
    mpicn_sRock2Icon->mCellCount = cellCount;
}

void mpicn_renderRock2Icon(RaceHudOamBuffer *oamBuffer) {
    mpicn_renderMObjIcon(oamBuffer, mpicn_sRock2Icon, 1);
}

s32 mpicn_createSanboIcon(void) {
    return mpicn_createMapObjIcon(&mpicn_sSanboIcon, MAP_OBJECT_KIND_SANBO);
}

void mpicn_destroySanboIcon(void) {
    mpicn_destroyMObjIcon(&mpicn_sSanboIcon);
}

void mpicn_updateSanboIcon(void) {
    s32 i;
    s32 cellCount;
    u32 n;
    Unk0217b498_00 *object;
    Vec3 *position;

    cellCount = 0;
    n = mpicn_20C0DB0();
    for (i = 0; i < mpicn_sSanboIcon->mObjectCount; i++) {
        if (IsRaceHudSubScreenPairNearCenter(&mpicn_sSanboIcon->fieldC[i]) != FALSE) {
            object = mpicn_sSanboIcon->mObjects[i];
            if ((object->mFlags & 1) == 0) {
                position = &object->mPos;
                if (lmap_20B5AE8(position, &mpicn_sSanboIcon->mCells[cellCount].mDrawPos,
                                                    n, 0, 0) != FALSE) {
                    mpicn_sSanboIcon->mCells[cellCount].mCell = r2d_getRaceSCell(0x8e);
                    mpicn_sSanboIcon->mCells[cellCount].fieldC =
                        m2d_isPointOnLowerMap(position) != 0 ? 2 : 3;
                    cellCount++;
                }
            }
        }
    }
    mpicn_sSanboIcon->mCellCount = cellCount;
}

void mpicn_renderSanboIcon(RaceHudOamBuffer *oamBuffer) {
    mpicn_renderMObjIcon(oamBuffer, mpicn_sSanboIcon, 0);
}

s32 mpicn_createRockIcon(void) {
    return mpicn_createMapObjIcon(&mpicn_sRockIcon, MAP_OBJECT_KIND_ROCK);
}

void mpicn_destroyRockIcon(void) {
    mpicn_destroyMObjIcon(&mpicn_sRockIcon);
}

void mpicn_updateRockIcon(void) {
    s32 i;
    s32 cellCount;
    u32 n;
    Unk0217b498_00 *object;
    Vec3 *position;

    cellCount = 0;
    n = mpicn_20C0DB0();
    for (i = 0; i < mpicn_sRockIcon->mObjectCount; i++) {
        object = mpicn_sRockIcon->mObjects[i];
        if ((object->mFlags & 2) == 0) {
            position = &object->mPos;
            if (lmap_20B5AE8(position, &mpicn_sRockIcon->mCells[cellCount].mDrawPos, n, 1,
                                                1) != FALSE) {
                mpicn_sRockIcon->mCells[cellCount].mCell = r2d_getRaceSCell(0x99);
                mpicn_sRockIcon->mCells[cellCount].fieldC = m2d_isPointOnLowerMap(position) != 0 ? 2 : 3;
                mpicn_sRockIcon->mCells[cellCount].field10 += 0x400;
                cellCount++;
            }
        }
    }
    mpicn_sRockIcon->mCellCount = cellCount;
}

void mpicn_renderRockIcon(RaceHudOamBuffer *oamBuffer) {
    mpicn_renderMObjIcon(oamBuffer, mpicn_sRockIcon, 1);
}

s32 mpicn_createWoodbox1Icon(void) {
    return mpicn_createMapObjIcon(&mpicn_sWoodbox1Icon, MAP_OBJECT_KIND_WOODBOX1);
}

void mpicn_destroyWoodbox1Icon(void) {
    mpicn_destroyMObjIcon(&mpicn_sWoodbox1Icon);
}

void mpicn_updateWoodbox1Icon(void) {
    s32 i;
    s32 cellCount;
    u32 n;
    Unk0217b498_00 *object;
    Vec3 *position;

    cellCount = 0;
    n = mpicn_20C0DB0();
    for (i = 0; i < mpicn_sWoodbox1Icon->mObjectCount; i++) {
        if (IsRaceHudSubScreenPairNearCenter(&mpicn_sWoodbox1Icon->fieldC[i]) != FALSE) {
            object = mpicn_sWoodbox1Icon->mObjects[i];
            if ((object->mFlags & 1) == 0) {
                position = &object->mPos;
                if (lmap_20B5AE8(
                        position, &mpicn_sWoodbox1Icon->mCells[cellCount].mDrawPos, n, 0, 0) != FALSE) {
                    mpicn_sWoodbox1Icon->mCells[cellCount].mCell = r2d_getRaceSCell(0x5c);
                    mpicn_sWoodbox1Icon->mCells[cellCount].fieldC =
                        m2d_isPointOnLowerMap(position) != 0 ? 2 : 3;
                    cellCount++;
                }
            }
        }
    }
    mpicn_sWoodbox1Icon->mCellCount = cellCount;
}

void mpicn_renderWoodbox1Icon(RaceHudOamBuffer *oamBuffer) {
    mpicn_renderMObjIcon(oamBuffer, mpicn_sWoodbox1Icon, 0);
}

s32 mpicn_createFlipperIcon(void) {
    return mpicn_createMapObjIcon(&mpicn_sFlipperIcon, MAP_OBJECT_KIND_FLIPPER);
}

void mpicn_destroyFlipperIcon(void) {
    mpicn_destroyMObjIcon(&mpicn_sFlipperIcon);
}

void mpicn_updateFlipperIcon(void) {
    s32 i;
    s32 cellCount;
    u32 n;
    Unk0217b498_00 *object;
    Vec3 *position;

    cellCount = 0;
    n = mpicn_20C0DB0();
    for (i = 0; i < mpicn_sFlipperIcon->mObjectCount; i++) {
        object = mpicn_sFlipperIcon->mObjects[i];
        if ((object->mFlags & 2) == 0) {
            position = &object->mPos;
            if (lmap_20B5AE8(position, &mpicn_sFlipperIcon->mCells[cellCount].mDrawPos, n,
                                                1, 1) != FALSE) {
                mpicn_sFlipperIcon->mCells[cellCount].mCell = r2d_getRaceSCell(0x90);
                mpicn_sFlipperIcon->mCells[cellCount].fieldC = m2d_isPointOnLowerMap(position) != 0 ? 2 : 3;
                mpicn_sFlipperIcon->mCells[cellCount].fieldE = object->mFlags & 0x400;
                mpicn_sFlipperIcon->mCells[cellCount].field10 = object->mAngle;
                cellCount++;
            }
        }
    }
    mpicn_sFlipperIcon->mCellCount = cellCount;
}

void mpicn_renderFlipperIcon(RaceHudOamBuffer *oamBuffer) {
    s32 i;
    s32 c;
    u16 d;
    u16 h;
    s32 oamIndex;
    u16 matrixIndex;
    RaceHudSubScreenCell *cell;
    s32 matrix[4];
    s32 position[2];
    s32 drawX;
    struct Unk020224e0_c *ncerEntry;
    s32 drawY;

    c = mpicn_getMinPriority();
    d = m2d_20B6368();
    for (i = 0; i < mpicn_sFlipperIcon->mCellCount; i++) {
        h = mpicn_sFlipperIcon->mCells[i].fieldC;
        if (c <= h) {
            if (mpicn_sFlipperIcon->mCells[i].fieldE != 0) {
                if (gRaceMultiConfig->mMirrorMode != 0) {
                    lmap_rotMtx22FlipX(matrix,
                                               (u16) (d + (mpicn_sFlipperIcon->mCells[i].field10 + 0x4000)));
                } else {
                    lmap_rotMtx22FlipX(matrix,
                                               (u16) (0x4000 - mpicn_sFlipperIcon->mCells[i].field10 - d));
                }
            } else {
                if (gRaceMultiConfig->mMirrorMode != 0) {
                    lmap_rotMtx22(matrix, (u16) (mpicn_sFlipperIcon->mCells[i].field10 + 0x4000 - d));
                } else {
                    lmap_rotMtx22(matrix, (u16) (d + (0x4000 - mpicn_sFlipperIcon->mCells[i].field10)));
                }
            }
            matrixIndex = oam_getAffineId(oamBuffer);
            oamBuffer->mMatrices[matrixIndex].field6 = matrix[0] >> 4;
            oamBuffer->mMatrices[matrixIndex].fieldE = matrix[1] >> 4;
            oamBuffer->mMatrices[matrixIndex].field16 = matrix[2] >> 4;
            oamBuffer->mMatrices[matrixIndex].field1E = matrix[3] >> 4;
            oamIndex = oamBuffer->mOamCount;
            cell = &mpicn_sFlipperIcon->mCells[i];
            drawX = cell->mDrawPos.field0;
            ncerEntry = cell->mCell;
            drawY = cell->mDrawPos.field4;
            position[0] = drawX << 12;
            position[1] = drawY << 12;
            oamBuffer->mOamCount += NNS_G2dMakeCellToOams(&oamBuffer->mOams[oamIndex], 0x80 - oamIndex, ncerEntry,
                                                          matrix, position, matrixIndex, 1);
            for (; oamIndex < oamBuffer->mOamCount; oamIndex++) {
                if (h != -1) {
                    oamBuffer->mOamBits[oamIndex].fieldE = h;
                }
            }
        }
    }
}

s32 mpicn_createNsKiller2Icon(void) {
    return mpicn_createMapObjIcon(&mpicn_sNsKiller2Icon, MAP_OBJECT_KIND_NS_KILLER2);
}

void mpicn_destroyNsKiller2Icon(void) {
    mpicn_destroyMObjIcon(&mpicn_sNsKiller2Icon);
}

void mpicn_updateNsKiller2Icon(void) {
    s32 i;
    s32 cellCount;
    u32 n;
    Unk0217b498_00 *object;

    cellCount = 0;
    n = mpicn_20C0DB0();
    for (i = 0; i < mpicn_sNsKiller2Icon->mObjectCount; i++) {
        object = mpicn_sNsKiller2Icon->mObjects[i];
        if ((object->mFlags & 1) == 0 && (object->mFlags & 2) == 0) {
            if (lmap_20B5AE8(
                    &object->mPos, &mpicn_sNsKiller2Icon->mCells[cellCount].mDrawPos, n, 1, 1) != FALSE) {
                mpicn_sNsKiller2Icon->mCells[cellCount].mCell = r2d_getRaceSCell(0xad);
                mpicn_sNsKiller2Icon->mCells[cellCount].fieldC = 3;
                mpicn_sNsKiller2Icon->mCells[cellCount].fieldE = 0;
                mpicn_sNsKiller2Icon->mCells[cellCount].field10 = object->mAngle;
                cellCount++;
            }
        }
    }
    mpicn_sNsKiller2Icon->mCellCount = cellCount;
}

void mpicn_renderNsKiller2Icon(RaceHudOamBuffer *oamBuffer) {
    mpicn_renderMObjIcon(oamBuffer, mpicn_sNsKiller2Icon, 1);
}

s32 mpicn_createPendulumIcon(void) {
    return mpicn_createMapObjIcon(&mpicn_sPendulumIcon, MAP_OBJECT_KIND_PENDULUM);
}

void mpicn_destroyPendulumIcon(void) {
    mpicn_destroyMObjIcon(&mpicn_sPendulumIcon);
}

void mpicn_updatePendulumIcon(void) {
    s32 i;
    s32 cellCount;
    u32 n;
    Unk0217b498_00 *object;
    Vec3 *position;

    cellCount = 0;
    n = mpicn_20C0DB0();
    for (i = 0; i < mpicn_sPendulumIcon->mObjectCount; i++) {
        object = mpicn_sPendulumIcon->mObjects[i];
        if ((object->mFlags & 2) == 0) {
            position = &object->mPos;
            if (lmap_20B5AE8(position, &mpicn_sPendulumIcon->mCells[cellCount].mDrawPos,
                                                n, 1, 1) != FALSE) {
                mpicn_sPendulumIcon->mCells[cellCount].mCell = r2d_getRaceSCell(0xa0);
                mpicn_sPendulumIcon->mCells[cellCount].fieldC = m2d_isPointOnLowerMap(position) != 0 ? 2 : 3;
                mpicn_sPendulumIcon->mCells[cellCount].fieldE = 0;
                mpicn_sPendulumIcon->mCells[cellCount].field10 = object->mAngle;
                cellCount++;
            }
        }
    }
    mpicn_sPendulumIcon->mCellCount = cellCount;
}

void mpicn_renderPendulumIcon(RaceHudOamBuffer *oamBuffer) {
    mpicn_renderMObjIcon(oamBuffer, mpicn_sPendulumIcon, 1);
}
