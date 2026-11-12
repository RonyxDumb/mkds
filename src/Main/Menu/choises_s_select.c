#include "Main/Menu/choises_s_select.h"
#include "Main/Save/buddy_record_time.h"
#include "Main/Graphics/oam.h"
#include "Main/Menu/choises_s_course.h"
#include "Main/Menu/choises_s_screen_map.h"
#include "Main/Menu/choises_s_tiles.h"
#include "Main/Graphics/locate_bmg_sections.h"
#include "Main/Menu/choises_s_list_chars.h"
#include "Main/System/file_in_loaded.h"
#include "Main/Sound/sound_seq.h"
#include "Main/Race/data_021759c0.h"
#include "tp.h"
#include "Main/Menu/choises_s.h"

#pragma thumb on
#pragma optimize_for_size on

void *GetChoisesSValueMessage(s32 listIndex, s32 value) {
    s32 entryNumbers[11] = {0x5d, 0x67, 0x62, 0x64, 0x65, 0x66, 0x69, 0x62, 0x61, 0x5f, 0x75};

    if (ChoisesSGetCurrentRaceKind() == RACE_KIND_REPLAY) {
        entryNumbers[0] = 0x6a;
        entryNumbers[8] = 0x63;
    }
    if (listIndex != 0) {
        entryNumbers[2] = 0x60;
    }
    return GetBmgEntry(FindFileInLoadedArchivesWrapper("common.bmg"), entryNumbers[value]);
}

void ClearChoisesSListValueCounts(void) {
    s32 listIndex;

    for (listIndex = 0; listIndex < 4; listIndex++) {
        gChoisesS->mLists[listIndex].mValueCount = 0;
    }
}

void AppendChoisesSListValue(s32 listIndex, s32 value) {
    s32 valueCount;

    valueCount = gChoisesS->mLists[listIndex].mValueCount;
    gChoisesS->mLists[listIndex].mValueCount = valueCount + 1;
    gChoisesS->mLists[listIndex].mValues[valueCount] = value;
}

s32 MoveChoisesSSelectedValue(s32 step) {
    s32 selectedIndex = 0;
    s32 valueCount;
    s32 listIndex;
    ChoisesS *choisesS;

    if (IsChoisesSOpen() != 0) {
        listIndex = GetChoisesSListIndex();
        valueCount = gChoisesS->mLists[listIndex].mValueCount;
        for (; selectedIndex < valueCount; selectedIndex++) {
            if (gChoisesS->mSelectedValue == gChoisesS->mLists[listIndex].mValues[selectedIndex]) {
                break;
            }
        }
        if (valueCount == 1) {
            step = 0;
        } else if (valueCount == 2) {
            if (step != 0 && selectedIndex + step >= 0 && selectedIndex + step < valueCount) {
                gChoisesS->mCycleFrames = 0;
                StartSoundOncePerFrame(0);
            } else {
                step = 0;
            }
        } else if (step != 0) {
            gChoisesS->mCycleFrames = 0;
            StartSoundOncePerFrame(0);
        }
        choisesS = gChoisesS;
        choisesS->mSelectedValue =
            choisesS->mLists[listIndex].mValues[(valueCount + (selectedIndex + step)) % valueCount];
    }
    return selectedIndex;
}

static inline ChoisesS *GetChoisesS(void) {
    return gChoisesS;
}

u32 MoveChoisesSSelectedValueByTouch(void) {
    u32 touched = 0;
    s32 valueCount;
    s32 listIndex;
    s32 valueIndex;
    PairRect valueRects[6];
    s32 firstRectRow;
    s32 top;

    if (IsChoisesSOpen() != 0) {
        MoveChoisesSSelectedValue(0);
        listIndex = GetChoisesSListIndex();
        valueCount = gChoisesS->mLists[listIndex].mValueCount;
        for (valueIndex = 0, firstRectRow = 0xc - valueCount * 2; valueIndex < valueCount; valueIndex++) {
            top = (firstRectRow + valueIndex * 4) * 8 + 6;
            valueRects[valueIndex].mMinX = 8;
            valueRects[valueIndex].mMaxX = 0xf8;
            valueRects[valueIndex].mMinY = top;
            valueRects[valueIndex].mMaxY = top + 0x16;
        }
        for (valueIndex = 0; valueIndex < valueCount; valueIndex++) {
            if (IsNewPairInRect(GetChoisesSInputSlot(), valueRects[valueIndex]) != 0) {
                if (gChoisesS->mSelectedValue != GetChoisesS()->mLists[listIndex].mValues[valueIndex]) {
                    gChoisesS->mSelectedValue = gChoisesS->mLists[listIndex].mValues[valueIndex];
                    MoveChoisesSSelectedValue(0);
                } else {
                    gChoisesS->mPickStartedOnSelected = TRUE;
                }
                touched = 1;
            }
        }
        if (touched != 0) {
            if (gChoisesS->mSelectedValue == 0) {
                RaiseSndHandleVolumes();
            } else {
                StartChoisesSSelectedValueSeq();
            }
        }
    }
    return touched;
}

void ResetChoisesSSelection(void) {
    ChoisesS *choisesS;

    gChoisesS->mPickedValue = 0;
    choisesS = gChoisesS;
    choisesS->mSelectedValue = choisesS->mLists[GetChoisesSListIndex()].mValues[0];
}

void SetChoisesSOpen(s32 openFlag) {
    if (gChoisesS->mPickLocked != 0) {
        return;
    }
    if (openFlag != 0 && IsChoisesSOpen() == 0) {
        if (IsChoisesSOpenAllowedDuringRace() != 0) {
            gChoisesS->mOpenDuringRace = openFlag;
        } else if (IsChoisesSOpenAllowedAfterRace() != 0) {
            gChoisesS->mOpenAfterRace = openFlag;
        } else {
            return;
        }
        ResetChoisesSSelection();
    } else if (openFlag == 0 && IsChoisesSOpen() != 0) {
        if (IsChoisesSOpenAllowedDuringRace() != 0) {
            gChoisesS->mOpenDuringRace = openFlag;
        } else if (IsChoisesSOpenAllowedAfterRace() != 0) {
            gChoisesS->mOpenAfterRace = openFlag;
        } else {
            return;
        }
    }
    if (gChoisesS->mPickedValue != 0) {
        gChoisesS->mPickLocked = 1;
    }
}

u32 IsMissionRunTableRow6Or7Column9(void) {
    if ((GetMissionRunTableRow() == 6 && GetMissionRunTableColumn() == 9) ||
        (GetMissionRunTableRow() == 7 && GetMissionRunTableColumn() == 9)) {
        return 1;
    }
    return 0;
}
#pragma thumb off

s8 GetMissionRunTableRow(void) {
    RaceSetup *raceSetup = gRaceSetup;

    if (raceSetup->mMode == MODE_MISSION_RUN) {
        return raceSetup->mMissionTableRow;
    }
    return -1;
}

s8 GetMissionRunTableColumn(void) {
    RaceSetup *raceSetup = gRaceSetup;

    if (raceSetup->mMode == MODE_MISSION_RUN) {
        return raceSetup->mMissionTableColumn;
    }
    return -1;
}

#pragma thumb on
// TRUE when the entry ended with kind 0, the other 53 cells held 5 to 7 at the start, and the current cell now holds 5
// to 7.
BOOL IsAllMissionRecords5To7AtEndKind0(void) {
    s32 recordValue;
    s32 isFilled;

    isFilled = GetMissionRecordValue(GetMissionRunTableRow(), GetMissionRunTableColumn(), &recordValue);
    if (GetEntryEndKind() == 0 && gChoisesS->mOtherMissionRecordsFilled5To7 != FALSE && isFilled != 0 &&
        (u32) (recordValue - 5) <= 2) {
        return 1;
    }
    return 0;
}
#pragma thumb off
