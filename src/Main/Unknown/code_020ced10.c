#include "Main/Unknown/code_020ced10.h"
#include "Main/Unknown/code_020c06c4.h"
#include "Main/Unknown/code_020c0b84.h"

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
#include "Main/Unknown/code_020c0d9c.h"
#include "Main/Unknown/code_020cedf8.h"

void ClearRaceHudSubScreenPakkunSpitCells(void) {
    ClearRaceHudSubScreenCells(&gRaceHudSubScreenPakkunSpitCells);
}

void UpdateRaceHudSubScreenPakkunSpitCells(void) {
    s32 objectIndex;
    s32 cellCount;
    s32 raceHudSubScreenScale;
    MapObject *object;

    cellCount = 0;
    raceHudSubScreenScale = GetRaceHudSubScreenScale();
    for (objectIndex = 0; objectIndex < gRaceHudSubScreenPakkunSpitCells->mObjectCount; objectIndex++) {
        object = gRaceHudSubScreenPakkunSpitCells->mObjects[objectIndex];
        if ((object->mFlags & 1) == 0) {
            if (ComputeRaceHudSubScreenPosition(&object->mPos,
                                                &gRaceHudSubScreenPakkunSpitCells->mCells[cellCount].mDrawPos,
                                                raceHudSubScreenScale, 1, 1) != FALSE) {
                gRaceHudSubScreenPakkunSpitCells->mCells[cellCount].mCell = GetRaceSNcerEntry(0xa4);
                gRaceHudSubScreenPakkunSpitCells->mCells[cellCount].mPriority = 2;
                cellCount++;
            }
        }
    }
    gRaceHudSubScreenPakkunSpitCells->mCellCount = cellCount;
}

void DrawRaceHudSubScreenPakkunSpitCells(RaceHudOamBuffer *oamBuffer) {
    DrawRaceHudSubScreenCells(oamBuffer, gRaceHudSubScreenPakkunSpitCells, 0);
}
