#include "Main/Unknown/code_020cefc0.h"
#include "Main/Unknown/code_020ade08.h"
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
#include "Main/Unknown/code_020ae4c0.h"
#include "Main/Unknown/code_020c0000.h"
#include "Main/Unknown/code_020c0d9c.h"
#include "Main/Unknown/code_020f36d8.h"
#include "code_02012b30.h"
#include "Main/Unknown/code_020f9c6c.h"
#include "Main/Unknown/code_020fd264.h"
#include "Main/Unknown/code_020cf2fc.h"

void mpicn_destroyExplosionIcon(void) {
    u32 address;
    u32 unused;
    address = (u32) &mpicn_sExplosionIcon;
    mpicn_destroyMObjIcon((RaceHudSubScreenCells **) address);
}

void mpicn_updateExplosionIcon(void) {
    s32 i;
    s32 cellCount;
    s32 v;
    s32 activeCount;
    s32 bombStateFrames;
    s32 y;
    ItemPool *pool;
    ItemObject **objects;
    ItemObject *bomb;
    Vec3 *bombPosition;
    s32 kouraStateFrames;
    s32 y2;
    ItemObject *kouraW;
    Vec3 *kouraPosition;

    cellCount = 0;
    v = mpicn_20C0DB0();
    pool = &it_sItemsets[9];
    activeCount = pool->mActiveCount;
    objects = pool->mObjects;
    for (i = 0; i < activeCount; i++) {
        bomb = objects[i];
        if (IsItemBombState2(bomb) != FALSE) {
            bombPosition = sub_20FD308((ItemBomb *) bomb, &bombStateFrames, &y);
            if (lmap_20B5AE8(
                    bombPosition, &mpicn_sExplosionIcon->mCells[cellCount].mDrawPos, v, 1, 1) != FALSE) {
                mpicn_sExplosionIcon->mCells[cellCount].mCell = r2d_getRaceSCell(0x63);
                mpicn_sExplosionIcon->mCells[cellCount].fieldC =
                    m2d_isPointOnLowerMap(bombPosition) != 0 ? 2 : 3;
                mpicn_sExplosionIcon->mCells[cellCount].field10 = bombStateFrames;
                mpicn_sExplosionIcon->mCells[cellCount].fieldE = bombStateFrames >= 0x16 ? 1 : 0;
                if (bombStateFrames >= 0x16) {
                    y = mutil_interpolate(1, 0x1000, 10, bombStateFrames - 0x16, 0x22);
                }
                mpicn_sExplosionIcon->fieldC[cellCount].field0 = y;
                cellCount++;
            }
        }
    }
    pool = &it_sItemsets[5];
    activeCount = pool->mActiveCount;
    objects = pool->mObjects;
    for (i = 0; i < activeCount; i++) {
        kouraW = objects[i];
        if (IsItemKouraWState7((ItemKouraW *) kouraW) != FALSE) {
            kouraPosition = GetItemKouraWState7Info((ItemKouraW *) kouraW, &kouraStateFrames, &y2);
            if (lmap_20B5AE8(
                    kouraPosition, &mpicn_sExplosionIcon->mCells[cellCount].mDrawPos, v, 1, 1) != FALSE) {
                mpicn_sExplosionIcon->mCells[cellCount].mCell = r2d_getRaceSCell(0x64);
                mpicn_sExplosionIcon->mCells[cellCount].fieldC =
                    m2d_isPointOnLowerMap(kouraPosition) != 0 ? 2 : 3;
                mpicn_sExplosionIcon->mCells[cellCount].field10 = kouraStateFrames;
                mpicn_sExplosionIcon->mCells[cellCount].fieldE = kouraStateFrames >= 0x16 ? 1 : 0;
                if (kouraStateFrames >= 0x16) {
                    y2 = mutil_interpolate(1, 0x1000, 10, kouraStateFrames - 0x16, 0x22);
                }
                mpicn_sExplosionIcon->fieldC[cellCount].field0 = y2;
                cellCount++;
            }
        }
    }
    mpicn_sExplosionIcon->mCellCount = cellCount;
}

void mpicn_renderExplosionIcon(RaceHudOamBuffer *oamBuffer) {
    mpicn_20C06C4(oamBuffer, mpicn_sExplosionIcon, 0);
}
