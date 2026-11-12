#include "Main/Unknown/code_020b2da4.h"
#include "Main/Unknown/code_020b2ec0.h"
#include "Main/Unknown/code_020b1de4.h"
#include "Main/Unknown/code_020b2e98.h"
#include "Main/Unknown/code_020b2e34.h"
#include "Main/Unknown/code_020b2000.h"
#include "Main/Unknown/code_020b29c4.h"
#include "Main/Unknown/code_020c3db4.h"
#include "Main/Unknown/code_021059e0.h"
#include "Main/Unknown/code_020b2ecc.h"
#include "Main/Unknown/code_020b2c80.h"
#include "Main/Unknown/code_020b32ec.h"
#include "Main/Unknown/code_020b41e8.h"

#pragma thumb on

u32 GetChoisesSOpenDuringRace(void) {
    return (gChoisesS->mOpenDuringRace);
}

#pragma thumb off

#pragma thumb on
#pragma optimize_for_size on
u32 IsChoisesSOpen(void) {
    if (GetChoisesSOpenDuringRace() != 0 || gChoisesS->mOpenAfterRace != 0) {
        return 1;
    }
    return 0;
}
#pragma thumb off

#pragma thumb on

void SetChoisesSOpenDuringRace(u32 openFlag) {
    int wasOpen;
    int v2;
    wasOpen = GetChoisesSOpenDuringRace();
    v2 = IsChoisesSOpenAllowedDuringRace();
    if (v2 != 0) {
        SetChoisesSOpen(openFlag);
    }
    v2 = GetChoisesSOpenDuringRace();
    if ((wasOpen == 0) && (v2 != 0)) {
        LowerSndHandleVolumes();
    }
}

u32 GetChoisesSPrevOpenDuringRace(void) {
    return (gChoisesS->mPrevOpenDuringRace);
}

int GetChoisesSPickedValue(void) {
    int courseCountReached;
    int pickedValue;
    pickedValue = gChoisesS->mPickedValue;
    if ((pickedValue == 2) && (courseCountReached = IsRaceGoalSRuleCourseCountReached(), courseCountReached != 0)) {
        pickedValue = 7;
    }
    return pickedValue;
}

#pragma thumb off

#pragma thumb on
#pragma optimize_for_size on
void WriteChoisesSValueTiles(u16 *screenMap, s32 column, s32 row) {
    SetScreenMapBlockLowBits(screenMap, column, row, 1, 1, 4);
    SetScreenMapBlockLowBits(screenMap, column, row + 1, 1, 1, 0x24);
}

void WriteChoisesSListTiles(void) {
    s32 valueCount;
    s32 valueIndex;
    s32 firstRow;
    u16 *screenMap;

    valueCount = gChoisesS->mLists[GetChoisesSListIndex()].mValueCount;
    screenMap = GetChoisesSListScreenMapData();
    if (screenMap != NULL) {
        for (valueIndex = 0, firstRow = 0xd - valueCount * 2; valueIndex < valueCount; valueIndex++) {
            WriteChoisesSValueTiles(screenMap, 2, firstRow + valueIndex * 4);
        }
        SetScreenMapBlockTopBits(screenMap, 0, 0, 0x20, 0x18, 0xf);
    }
}
#pragma thumb off
