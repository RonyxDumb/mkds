#include "01/code_021813f4.h"

#include "01/code_0218155c.h"
#include "01/code_02188950.h"
#include "01/code_02188e88.h"
#include "01/unk_021a9000.h"
#include "01/code_02181000.h"
#include "03/code_021b94b8.h"
#include "Main/Unknown/code_02036000.h"
#include "Main/Unknown/code_020364e0.h"
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
#include "Main/Unknown/code_0214d000.h"

RaceHudSubScreenCells *mpicn_sCoinIcon;

s32 func_ov001_02181528(void) {
    Unk02188950 *mapObject;

    if (gRaceMultiConfig->mMode == MODE_MISSION_RUN) {
        mapObject = GetMissionRunMapObject(gRaceMultiConfig->mMode == MODE_MISSION_RUN ? func_ov001_02181b54() : 0);
    } else {
        mapObject = NULL;
    }
    return mapObject->mAlphaLimit;
}

#pragma thumb off

s32 mpicn_createCoinIcon(void) {
    return mpicn_createMapObjIcon(&mpicn_sCoinIcon, 0x68);
}

void mpicn_destroyCoinIcon(void) {
    mpicn_destroyMObjIcon(&mpicn_sCoinIcon);
}

void mpicn_updateCoinIcon(void) {
    s32 i;
    s32 cellCount;
    Unk0217b498_00 *object;
    Vec3 *position;
    u32 v;

    cellCount = 0;
    v = mpicn_20C0DB0();
    for (i = 0; i < mpicn_sCoinIcon->mObjectCount; i++) {
        object = mpicn_sCoinIcon->mObjects[i];
        if ((object->mFlags & 1) == 0) {
            position = &object->mPos;
            if (lmap_20B5AE8(position, &mpicn_sCoinIcon->mCells[cellCount].mDrawPos, v, 1,
                                                1)) {
                mpicn_sCoinIcon->mCells[cellCount].mCell = r2d_getRaceSCell(0x58);
                mpicn_sCoinIcon->mCells[cellCount].fieldC = m2d_isPointOnLowerMap(position) != 0 ? 2 : 3;
                cellCount++;
            }
        }
    }
    mpicn_sCoinIcon->mCellCount = cellCount;
}

void mpicn_renderCoinIcon(void *oamBuffer) {
    mpicn_renderMObjIcon(oamBuffer, mpicn_sCoinIcon, 0);
}

#pragma thumb on
