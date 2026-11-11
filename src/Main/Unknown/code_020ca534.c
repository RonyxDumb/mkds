#include "Main/Unknown/code_020ca534.h"
#include "Main/Unknown/code_020c06c4.h"
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
#include "Main/Unknown/code_020c0b84.h"
#include "Main/Unknown/code_020c0ba8.h"
#include "Main/Unknown/code_020c0d9c.h"
#include "Main/Unknown/code_021000d0.h"

void UpdateRaceHudSubScreenShine16Cells(void) {
    s32 objectIndex;
    s32 cellCount;
    u32 scale;

    cellCount = 0;
    scale = GetRaceHudSubScreenScale();
    for (objectIndex = 0; objectIndex < gRaceHudSubScreenShine16Cells->mObjectCount; objectIndex++) {
        MapObject *mapObject;

        mapObject = gRaceHudSubScreenShine16Cells->mObjects[objectIndex];
        if (!(mapObject->mFlags & 1)) {
            if (ComputeRaceHudSubScreenPosition(
                    &mapObject->mPos, &gRaceHudSubScreenShine16Cells->mCells[cellCount].mDrawPos, scale, 1, 1)) {
                gRaceHudSubScreenShine16Cells->mCells[cellCount].mCell = GetRaceSNcerEntry(0xb6);
                gRaceHudSubScreenShine16Cells->mCells[cellCount].mPriority = (mapObject->mFlags & 0x20) ? 2 : 1;
                gRaceHudSubScreenShine16Cells->mCells[cellCount].mXlu = mapObject->mFlags & 0x20;
                cellCount++;
            }
        }
    }
    gRaceHudSubScreenShine16Cells->mCellCount = cellCount;
}

void DrawRaceHudSubScreenShine16Cells(RaceHudOamBuffer *oamBuffer) {
    DrawRaceHudSubScreenCells(oamBuffer, gRaceHudSubScreenShine16Cells, 0);
}

s32 CreateRaceHudSubScreenCrabCells(void) {
    return CreateRaceHudSubScreenCells(&gRaceHudSubScreenCrabCells, MAP_OBJECT_KIND_CRAB);
}
