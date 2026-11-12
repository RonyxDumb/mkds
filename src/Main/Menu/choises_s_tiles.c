#include "Main/Menu/choises_s_tiles.h"
#include "Main/Menu/choises_s.h"
#include "Main/Menu/choises_s_screen_map.h"
#include "Main/Race/race_goal_s_rule.h"
#include "Main/Sound/sound_seq.h"
#include "Main/Menu/choises_s_select.h"
#include "Main/Menu/choises_s_list_chars.h"
#include "Main/Graphics/chars_block.h"

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
