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

void ClearRaceHudSubScreenBombKouraWCells(void) {
    ClearRaceHudSubScreenCells(&gRaceHudSubScreenBombKouraWCells);
}

void UpdateRaceHudSubScreenBombKouraWCells(void) {
    s32 objectIndex;
    s32 cellCount;
    s32 scale;
    s32 activeCount;
    s32 bombStateFrames;
    s32 bombValue;
    ItemPool *pool;
    ItemObject **objects;
    ItemObject *bomb;
    Vec3 *bombPosition;
    s32 kouraStateFrames;
    s32 kouraValue;
    ItemObject *kouraW;
    Vec3 *kouraPosition;

    cellCount = 0;
    scale = GetRaceHudSubScreenScale();
    pool = &gItemPools[9];
    activeCount = pool->mActiveCount;
    objects = pool->mObjects;
    for (objectIndex = 0; objectIndex < activeCount; objectIndex++) {
        bomb = objects[objectIndex];
        if (IsItemBombState2(bomb) != FALSE) {
            bombPosition = GetItemBombState2Info((ItemBomb *) bomb, &bombStateFrames, &bombValue);
            if (ComputeRaceHudSubScreenPosition(bombPosition,
                                                &gRaceHudSubScreenBombKouraWCells->mCells[cellCount].mDrawPos, scale, 1,
                                                1) != FALSE) {
                gRaceHudSubScreenBombKouraWCells->mCells[cellCount].mCell = GetRaceSNcerEntry(0x63);
                gRaceHudSubScreenBombKouraWCells->mCells[cellCount].mPriority = IsPositionOutsideBox(bombPosition) != 0
                                                                                    ? RACE_HUD_PRIORITY_OUTSIDE_BOX
                                                                                    : RACE_HUD_PRIORITY_INSIDE_BOX;
// Frame count, not an angle: this list is drawn without rotation.
                gRaceHudSubScreenBombKouraWCells->mCells[cellCount].mAngle = bombStateFrames;
                gRaceHudSubScreenBombKouraWCells->mCells[cellCount].mXlu = bombStateFrames >= 0x16 ? 1 : 0;
                if (bombStateFrames >= 0x16) {
                    bombValue = InterpolateS16(1, 0x1000, 10, bombStateFrames - 0x16, 0x22);
                }
                gRaceHudSubScreenBombKouraWCells->mObjectPairs[cellCount].mFirst = bombValue;
                cellCount++;
            }
        }
    }
    pool = &gItemPools[5];
    activeCount = pool->mActiveCount;
    objects = pool->mObjects;
    for (objectIndex = 0; objectIndex < activeCount; objectIndex++) {
        kouraW = objects[objectIndex];
        if (IsItemKouraWState7((ItemKouraW *) kouraW) != FALSE) {
            kouraPosition = GetItemKouraWState7Info((ItemKouraW *) kouraW, &kouraStateFrames, &kouraValue);
            if (ComputeRaceHudSubScreenPosition(kouraPosition,
                                                &gRaceHudSubScreenBombKouraWCells->mCells[cellCount].mDrawPos, scale, 1,
                                                1) != FALSE) {
                gRaceHudSubScreenBombKouraWCells->mCells[cellCount].mCell = GetRaceSNcerEntry(0x64);
                gRaceHudSubScreenBombKouraWCells->mCells[cellCount].mPriority = IsPositionOutsideBox(kouraPosition) != 0
                                                                                    ? RACE_HUD_PRIORITY_OUTSIDE_BOX
                                                                                    : RACE_HUD_PRIORITY_INSIDE_BOX;
// Frame count, not an angle: this list is drawn without rotation.
                gRaceHudSubScreenBombKouraWCells->mCells[cellCount].mAngle = kouraStateFrames;
                gRaceHudSubScreenBombKouraWCells->mCells[cellCount].mXlu = kouraStateFrames >= 0x16 ? 1 : 0;
                if (kouraStateFrames >= 0x16) {
                    kouraValue = InterpolateS16(1, 0x1000, 10, kouraStateFrames - 0x16, 0x22);
                }
                gRaceHudSubScreenBombKouraWCells->mObjectPairs[cellCount].mFirst = kouraValue;
                cellCount++;
            }
        }
    }
    gRaceHudSubScreenBombKouraWCells->mCellCount = cellCount;
}

void DrawRaceHudSubScreenBombKouraWCells(RaceHudOamBuffer *oamBuffer) {
    DrawRaceHudSubScreenCellsScaled(oamBuffer, gRaceHudSubScreenBombKouraWCells, 0);
}
