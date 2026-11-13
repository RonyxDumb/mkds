#include "Main/Menu/choises_s.h"
#include "Main/Save/buddy_record_time.h"
#include "Main/Graphics/oam.h"
#include "Main/Graphics/locate_bmg_sections.h"
#include "Main/Menu/choises_s_list_chars.h"
#include "Main/System/file_in_loaded.h"
#include "Main/Sound/sound_seq.h"
#include "Main/Race/data_021759c0.h"
#include "tp.h"
#include "Main/Race/race_goal_s_rule.h"
#include "Main/Graphics/chars_block.h"
#include "Main/Race/data_020f36d8.h"
#include "Main/Race/kart.h"
#include "01/Menu/record_time_attack.h"
#include "01/Menu/code_02196d58.h"
#include "Main/Race/race_hud_draw.h"
#include "Main/Race/race_start_sequence.h"
#include "Main/Race/race_goal_s_running.h"
#include "Main/Race/race_goal_m.h"
#include "Main/Race/race_new_record_ta.h"
#include "Main/MapObjects/data_0217a000.h"
#include "Main/Menu/data_02175628.h"
#include "00/Menu/wi_fi_vs_setting.h"
#include "Main/Graphics/disp_cap.h"
#include "Main/Race/standings_balloons.h"
#include "Main/Menu/data_02175000.h"
#include "Main/Scene/display_settings.h"
#include "code_020182c0.h"
#include "frameheap.h"
#include "os_thread.h"
#include "Main/MapObjects/map_object_park.h"
#include "pm.h"
#include "Main/Menu/title_scene.h"
#include "Main/System/heap_call.h"
#include "Main/Menu/menu_shared_clear.h"
#include "Main/System/heap.h"
#include "Main/Graphics/font_glyph_text.h"
#include "g2d_CharCanvas.h"
#include "Main/Save/ghost_record_file.h"

char gChoisesSNscr4Name[] = "choises_s_4.NSCR";
char gChoisesSNscr1Name[] = "choises_s_1.NSCR";
char gChoisesSNscr5Name[] = "choises_s_5.NSCR";
char gChoisesSNscr6Name[] = "choises_s_6.NSCR";
char gChoisesSNscr2Name[] = "choises_s_2.NSCR";
char gChoisesSNscr3Name[] = "choises_s_3.NSCR";

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

u32 GetEntryIndex(void) {
    return (gRaceSetup->mEntryIndex);
}

s32 GetEntryEndKind(void) {
    if (IsKartEnded((u16) GetEntryIndex()) != 0) {
        return gRaceProgress->mEntryEndKind;
    }
    return 6;
}

#pragma thumb on
#pragma optimize_for_size on
u32 GetChoisesSListIndex(void) {
    if (ChoisesSGetCurrentRaceKind() == RACE_KIND_REPLAY && GetRaceDone() == 0) {
        return 3;
    }
    if (GetRaceDone() != 0) {
        if (ChoisesSGetCurrentMode() == MODE_MISSION_RUN) {
            if (GetEntryEndKind() == 0) {
                return 2;
            }
            return 1;
        }
        if (IsRaceGoalSRuleCourseCountReached() != 0) {
            return 2;
        }
        return 1;
    }
    return 0;
}

void WriteChoisesSSelectedValueTiles(s32 selectedIndex) {
    s32 valueCount;
    s32 row;
    u16 *screenMap;

    valueCount = gChoisesS->mLists[GetChoisesSListIndex()].mValueCount;
    screenMap = GetChoisesSListScreenMapData();
    if (screenMap != NULL) {
        if (gChoisesS->mPickStartedOnSelected == FALSE || gChoisesS->mPickFrames >= 5) {
            row = 0xd - valueCount * 2 + selectedIndex * 4;
            if (gChoisesS->mCycleFrames < 0x1e) {
                SetScreenMapBlockLowBits(screenMap, 2, row, 1, 1, 0x21);
                SetScreenMapBlockLowBits(screenMap, 2, row + 1, 1, 1, 0x41);
            }
            SetScreenMapBlockTopBits(screenMap, 0, row - 1, 0x20, 4, 0xe);
        }
    }
}
#pragma thumb off

#pragma thumb on

void WriteChoisesSListScreenMap(void) {
    WriteChoisesSListTiles();
    WriteChoisesSSelectedValueTiles(MoveChoisesSSelectedValue(0));
}

#pragma thumb off

u32 ChoisesSIsBackupEnabled(void) {
    return (gBackupAccess->mBackupEnabled);
}

#pragma optimize_for_size on
s32 ChoisesSIsBackupCommandRunning(void) {
    if (ChoisesSIsBackupEnabled() != 0) {
        return gBackupAccess->mCommandRunning;
    }
    return 0;
}

s32 ChoisesSIsBackupBusy(void) {
    if (gBackupBuffers->mBusy != 0) {
        return 1;
    }
    return ChoisesSIsBackupCommandRunning();
}

#pragma thumb on
u32 IsRaceDoneOrReplayPastStartFrames(void) {
    if (GetRaceDone() != 0 ||
        (ChoisesSGetCurrentRaceKind() == RACE_KIND_REPLAY && GetRaceStartSequenceFrames() > 0xf0)) {
        return 1;
    }
    return 0;
}

u32 IsChoisesSOpenAllowedAfterRace(void) {
    if (IsRaceStartSequenceDone() != 0 && IsRaceDoneOrReplayPastStartFrames() != 0 && IsRaceGoalMReady() != 0 &&
        IsRaceGoalSRunning() == 0 && IsRaceNewRecordTaSaving() == 0 && IsRaceNewRecordTaRunning() == 0 &&
        GetShowLapTime() == 0 && (GetChoisesSOpenDuringRace() != 0 || IsSharedDispCapFadeFlagSet() == FALSE)) {
        return 1;
    }
    return 0;
}
#pragma thumb off

u32 ChoisesSGetUnfilledNotEliminated(void) {
    return (gMenuShared->mUnfilledNotEliminated);
}

u32 GetChoisesSInputSlot(void) {
    return 0x8u;
}

u16 ChoisesSGetInputSlotNewBits(InputSlot *slot, u32 mask) {
    return slot->mPressedBits & mask;
}

u16 ChoisesSGetNewBits(s32 slotIndex, u32 mask) {
    return ChoisesSGetInputSlotNewBits(&gInputSlots[slotIndex], mask);
}

u32 ChoisesSGetPairHasPair(const void *inputSlotPair) {
    return (*OFFSET_PTR(const u16, inputSlotPair, 4));
}

#pragma optimize_for_size on
u32 ChoisesSIsPairRecentlyLost(InputSlotPair *inputSlotPair) {
    if (ChoisesSGetPairHasPair(inputSlotPair) == 0 && inputSlotPair->mNoPairCount < 5) {
        return 1;
    }
    return 0;
}

u32 ChoisesSIsPairNew(InputSlotPair *inputSlotPair) {
    if (inputSlotPair->mPrevHasPair == 0 && inputSlotPair->mHasPair != 0) {
        return 1;
    }
    return 0;
}

u32 ChoisesSIsPairNewUnlessRecentlyLost(InputSlotPair *inputSlotPair) {
    if (ChoisesSIsPairRecentlyLost(inputSlotPair) == 0 && ChoisesSIsPairNew(inputSlotPair) != 0) {
        return 1;
    }
    return 0;
}

u32 ChoisesSIsSlotPairNew(s32 slotIndex) {
    return ChoisesSIsPairNewUnlessRecentlyLost(&gInputSlots[slotIndex].mPair);
}

void ChoisesSSetLVselIndex6Requested(u32 value) {
    gMenuShared->mLVselIndex6Requested = value;
}

u32 GetRaceDone(void) {
    return (gRaceProgress->mRaceDone);
}

#pragma thumb on
#pragma optimize_for_size on
BOOL IsChoisesSOpenAllowedDuringRace(void) {
    u32 result = 0;
    u32 modeAllowsOpen = 0;
    u32 raceInProgress = 0;
    u32 noMissionWinner;

    if (IsRaceStartSequenceDone() != 0 && GetRaceStartSequenceFrames() > 0xf0 && GetRaceDone() == 0 &&
        (ChoisesSGetCurrentMode() != MODE_BATTLE || IsWinnerDecided() == FALSE)) {
        noMissionWinner = 1;
        if (ChoisesSGetCurrentMode() == MODE_MISSION_RUN) {
            if ((ChoisesSGetCurrentMode() == MODE_MISSION_RUN ? IsWinnerDecided() : 0) != FALSE) {
                noMissionWinner = 0;
            }
        }
        if (noMissionWinner != 0) {
            raceInProgress = 1;
        }
    }
    if (raceInProgress != 0) {
        if (ChoisesSGetCurrentMode() != 5) {
            modeAllowsOpen = 1;
        }
    }
    if (modeAllowsOpen != 0) {
        if (GetChoisesSOpenDuringRace() != 0 || IsSharedDispCapFadeFlagSet() == FALSE) {
            result = 1;
        }
    }
    return result;
}
#pragma thumb off

u32 ChoisesSGetConnectionKind(void) {
    return (gStartupWork->mConnectionKind);
}

#pragma thumb on
#pragma optimize_for_size on
void UpdateChoisesS(void) {
    s32 frames;

    gChoisesS->mPrevOpenDuringRace = gChoisesS->mOpenDuringRace;
    gChoisesS->mCycleFrames = gChoisesS->mCycleFrames + 1;
    if (gChoisesS->mCycleFrames >= 0x32) {
        gChoisesS->mCycleFrames = 0;
    }
    if (ChoisesSIsBackupBusy() != 0) {
        return;
    }
    if ((ChoisesSGetCurrentMode() == MODE_GRAND_PRIX || ChoisesSGetCurrentMode() == MODE_TIME_ATTACK) &&
        ChoisesSGetCurrentRaceKind() == RACE_KIND_REPLAY && ShouldEndReplayRace() != 0) {
        return;
    }
    if (gChoisesS->mPickFrames == 0 && gChoisesS->mCloseFrames == 0 && IsChoisesSPickLocked() == 0) {
        if (IsRaceDoneOrReplayPastStartFrames() != 0) {
            if (IsChoisesSOpenAllowedAfterRace() != 0) {
                if (ChoisesSGetCurrentMode() == MODE_MISSION_RUN && ChoisesSGetUnfilledNotEliminated() != 0 &&
                    IsMissionRunTableRow6Or7Column9() != 0) {
                    if (ChoisesSGetNewBits(GetChoisesSInputSlot(), PAD_KEY_A) != 0 ||
                        ChoisesSIsSlotPairNew(GetChoisesSInputSlot()) != 0) {
                        gChoisesS->mPickedValue = 10;
                        gChoisesS->mSelectedValue = gChoisesS->mPickedValue;
                        gChoisesS->mPickLocked = 1;
                        StartChoisesSSelectedValueSeq();
                    }
                } else if (ChoisesSGetCurrentMode() == MODE_MISSION_RUN && IsAllMissionRecords5To7AtEndKind0() != 0) {
                    if (ChoisesSGetNewBits(GetChoisesSInputSlot(), PAD_KEY_A) != 0 ||
                        ChoisesSIsSlotPairNew(GetChoisesSInputSlot()) != 0) {
                        gChoisesS->mPickedValue = 6;
                        gChoisesS->mSelectedValue = gChoisesS->mPickedValue;
                        gChoisesS->mPickLocked = 1;
                        StartChoisesSSelectedValueSeq();
                        ChoisesSSetLVselIndex6Requested(1);
                    }
                } else if (ChoisesSGetCurrentMode() == MODE_MISSION_RUN && ChoisesSGetUnfilledNotEliminated() != 0) {
                    if (ChoisesSGetNewBits(GetChoisesSInputSlot(), PAD_KEY_A) != 0 ||
                        ChoisesSIsSlotPairNew(GetChoisesSInputSlot()) != 0) {
                        gChoisesS->mPickedValue = 6;
                        gChoisesS->mSelectedValue = gChoisesS->mPickedValue;
                        gChoisesS->mPickLocked = 1;
                        StartChoisesSSelectedValueSeq();
                    }
                } else if (ChoisesSGetNewBits(GetChoisesSInputSlot(), 8) != 0) {
                    if (IsChoisesSOpen() != 0) {
                        RaiseSndHandleVolumes();
                        gChoisesS->mCloseFrames = 1;
                    } else {
                        LowerSndHandleVolumes();
                        SetChoisesSOpen(1);
                    }
                } else if (MoveChoisesSSelectedValueByTouch() != 0) {
                    gChoisesS->mPickFrames = 1;
                } else if (ChoisesSGetNewBits(GetChoisesSInputSlot(), PAD_KEY_A) != 0) {
                    if (IsChoisesSOpen() != 0) {
                        if (gChoisesS->mSelectedValue == 0) {
                            RaiseSndHandleVolumes();
                        } else {
                            StartChoisesSSelectedValueSeq();
                        }
                        gChoisesS->mPickFrames = 1;
                        gChoisesS->mPickStartedOnSelected = TRUE;
                    } else {
                        LowerSndHandleVolumes();
                        SetChoisesSOpen(1);
                    }
                } else if (ChoisesSGetNewBits(GetChoisesSInputSlot(), PAD_KEY_B) != 0) {
                    if (IsChoisesSOpen() != 0) {
                        RaiseSndHandleVolumes();
                        gChoisesS->mCloseFrames = 1;
                    }
                } else if (GetNewOrRepeatBits(GetChoisesSInputSlot(), PAD_KEY_UP) != 0) {
                    MoveChoisesSSelectedValue(-1);
                } else if (GetNewOrRepeatBits(GetChoisesSInputSlot(), PAD_KEY_DOWN) != 0) {
                    MoveChoisesSSelectedValue(1);
                }
            }
        } else if (IsChoisesSOpenAllowedDuringRace() != 0) {
            if (ChoisesSGetNewBits(GetChoisesSInputSlot(), 8) != 0) {
                if (IsChoisesSOpen() != 0) {
                    RaiseSndHandleVolumes();
                    gChoisesS->mCloseFrames = 1;
                } else {
                    LowerSndHandleVolumes();
                    SetChoisesSOpen(1);
                }
            } else if (MoveChoisesSSelectedValueByTouch() != 0) {
                gChoisesS->mPickFrames = 1;
            } else if (ChoisesSGetNewBits(GetChoisesSInputSlot(), PAD_KEY_A) != 0) {
                if (IsChoisesSOpen() != 0) {
                    if (gChoisesS->mSelectedValue == 0) {
                        RaiseSndHandleVolumes();
                    } else {
                        StartChoisesSSelectedValueSeq();
                    }
                    gChoisesS->mPickFrames = 1;
                    gChoisesS->mPickStartedOnSelected = TRUE;
                }
            } else if (ChoisesSGetNewBits(GetChoisesSInputSlot(), PAD_KEY_B) != 0) {
                if (IsChoisesSOpen() != 0) {
                    RaiseSndHandleVolumes();
                    gChoisesS->mCloseFrames = 1;
                }
            } else if (GetNewOrRepeatBits(GetChoisesSInputSlot(), PAD_KEY_UP) != 0) {
                MoveChoisesSSelectedValue(-1);
            } else if (GetNewOrRepeatBits(GetChoisesSInputSlot(), PAD_KEY_DOWN) != 0) {
                MoveChoisesSSelectedValue(1);
            }
        }
    }
    frames = gChoisesS->mPickFrames;
    if (frames != 0) {
        gChoisesS->mPickFrames = frames + 1;
        if (gChoisesS->mPickFrames > 0xf) {
            if (IsRaceDoneOrReplayPastStartFrames() != 0) {
                if (IsChoisesSOpen() != 0) {
                    gChoisesS->mPickedValue = gChoisesS->mSelectedValue;
                    SetChoisesSOpen(0);
                } else {
                    SetChoisesSOpen(1);
                }
            } else if (IsChoisesSOpen() != 0) {
                gChoisesS->mPickedValue = gChoisesS->mSelectedValue;
                SetChoisesSOpen(0);
            }
            gChoisesS->mPickFrames = 0;
            gChoisesS->mPickStartedOnSelected = FALSE;
        }
    }
    frames = gChoisesS->mCloseFrames;
    if (frames != 0) {
        gChoisesS->mCloseFrames = frames + 1;
        if (gChoisesS->mCloseFrames > 4) {
            if (IsRaceDoneOrReplayPastStartFrames() != 0) {
                if (IsChoisesSOpen() != 0) {
                    SetChoisesSOpen(0);
                } else {
                    SetChoisesSOpen(1);
                }
            } else if (IsChoisesSOpen() != 0) {
                SetChoisesSOpen(0);
            }
            gChoisesS->mCloseFrames = 0;
        }
    }
    if (ChoisesSGetConnectionKind() != 0 && ChoisesSGetCurrentMode() == 5 && IsRaceDoneOrReplayPastStartFrames() != 0) {
        gChoisesS->mAutoPickFrames = gChoisesS->mAutoPickFrames + 1;
        if (gChoisesS->mAutoPickFrames > 0x384) {
            gChoisesS->mPickedValue = GetCourseNumber() != 4 ? 2 : 7;
        }
    }
    if (GetChoisesSOpenDuringRace() != 0) {
        frames = gChoisesS->mUnk_030;
        gChoisesS->mUnk_030 = frames + 1;
        if (frames >= 1) {
            gChoisesS->mUnk_02c = 2;
            gChoisesS->mUnk_030 = 1;
        }
    } else {
        gChoisesS->mUnk_02c = 0;
        gChoisesS->mUnk_030 = 0;
    }
}
#pragma thumb off

#pragma thumb on

void UpdateChoisesSScreenMap(void) {
    int isOpen;
    isOpen = IsChoisesSOpen();
    if (isOpen != 0) {
        WriteChoisesSListScreenMap();
    }
}

#pragma thumb off

void *ChoisesSGetCurrentHeap(void) {
    return GetHeap(GetCurrentHeapCall());
}

u32 ChoisesSGetCurrentMode(void) {
    return (gRaceSetup->mMode);
}

#pragma thumb on
#pragma optimize_for_size on
BOOL IsGrandPrixLastCourse(void) {
    return ChoisesSGetCurrentMode() == MODE_GRAND_PRIX && GetCourseNumber() == 4;
}
#pragma thumb off

u32 GetCourseNumber(void) {
    return (gRaceSetup->mCourseNumber);
}

u32 ChoisesSGetCurrentRaceKind(void) {
    return gRaceSetup->mRaceKind;
}

struct ChoisesS *gChoisesS;

void ChoisesSInitTextCanvas(TextCanvas *textCanvas, void *charCanvas, void *font, s32 charSpacing, s32 lineSpacing) {
    textCanvas->mCharCanvas = charCanvas;
    textCanvas->mFont = font;
    textCanvas->mCharSpacing = charSpacing;
    textCanvas->mLineSpacing = lineSpacing;
}

u32 ChoisesSDrawTextOnCanvas(TextCanvas *textCanvas, s32 textX, s32 textY, u32 color, u32 flags, void *text) {
    return NNSi_G2dTextCanvasDrawText(textCanvas, textX, textY, color, flags, text);
}

#pragma thumb on
#pragma optimize_for_size on

void InitChoisesS(void) {
    ChoisesS *choisesS;
    u32 charCount;
    s32 index;

    gChoisesS = HeapAlloc(ChoisesSGetCurrentHeap(), 0x1a4);
    gChoisesS->mOpenDuringRace = 0;
    gChoisesS->mPrevOpenDuringRace = 0;
    gChoisesS->mOpenAfterRace = 0;
    gChoisesS->mPickLocked = 0;
    gChoisesS->mPickFrames = 0;
    gChoisesS->mPickStartedOnSelected = FALSE;
    gChoisesS->mAutoPickFrames = 0;
    if (ChoisesSGetCurrentMode() == MODE_MISSION_RUN) {
        gChoisesS->mOtherMissionRecordsFilled5To7 = AreOtherMissionRecordsFilled5To7();
    } else {
        gChoisesS->mOtherMissionRecordsFilled5To7 = FALSE;
    }
    gChoisesS->mUnk_02c = 0;
    gChoisesS->mUnk_030 = 0;
    ResetChoisesSSelection();
    ClearChoisesSListValueCounts();
    switch (ChoisesSGetCurrentMode()) {
        case MODE_GRAND_PRIX:
            AppendChoisesSListValue(0, 0);
            AppendChoisesSListValue(0, 9);
            if (IsGrandPrixLastCourse() != FALSE) {
                AppendChoisesSListValue(1, 7);
                AppendChoisesSListValue(1, 8);
            } else {
                AppendChoisesSListValue(1, 2);
                AppendChoisesSListValue(1, 8);
                AppendChoisesSListValue(1, 9);
            }
            if (IsGrandPrixLastCourse() != FALSE) {
                AppendChoisesSListValue(3, 0);
                AppendChoisesSListValue(3, 7);
                AppendChoisesSListValue(3, 8);
            } else {
                AppendChoisesSListValue(3, 0);
                AppendChoisesSListValue(3, 2);
                AppendChoisesSListValue(3, 8);
                AppendChoisesSListValue(3, 9);
            }
            break;
        case MODE_TIME_ATTACK:
            AppendChoisesSListValue(0, 0);
            AppendChoisesSListValue(0, 3);
            AppendChoisesSListValue(0, 4);
            AppendChoisesSListValue(0, 5);
            AppendChoisesSListValue(0, 9);
            AppendChoisesSListValue(1, 1);
            AppendChoisesSListValue(1, 4);
            AppendChoisesSListValue(1, 5);
            AppendChoisesSListValue(1, 8);
            AppendChoisesSListValue(1, 9);
            AppendChoisesSListValue(3, 0);
            AppendChoisesSListValue(3, 1);
            AppendChoisesSListValue(3, 4);
            AppendChoisesSListValue(3, 5);
            AppendChoisesSListValue(3, 8);
            AppendChoisesSListValue(3, 9);
            break;
        case MODE_BATTLE:
            AppendChoisesSListValue(0, 0);
            AppendChoisesSListValue(0, 9);
            AppendChoisesSListValue(1, 2);
            AppendChoisesSListValue(1, 9);
            AppendChoisesSListValue(2, 7);
            break;
        case MODE_VS:
            AppendChoisesSListValue(0, 0);
            AppendChoisesSListValue(0, 9);
            AppendChoisesSListValue(1, 2);
            AppendChoisesSListValue(1, 9);
            AppendChoisesSListValue(2, 7);
            break;
        case MODE_MISSION_RUN:
            AppendChoisesSListValue(0, 0);
            AppendChoisesSListValue(0, 3);
            AppendChoisesSListValue(0, 6);
            AppendChoisesSListValue(0, 9);
            if (IsMissionRunTableRow6Or7Column9() != 0) {
                if (IsMissionRunRecordFilled() != 0) {
                    AppendChoisesSListValue(1, 1);
                    AppendChoisesSListValue(1, 6);
                    AppendChoisesSListValue(1, 9);
                    AppendChoisesSListValue(2, 6);
                    AppendChoisesSListValue(2, 1);
                    AppendChoisesSListValue(2, 10);
                    AppendChoisesSListValue(2, 9);
                } else {
                    AppendChoisesSListValue(1, 1);
                    AppendChoisesSListValue(1, 6);
                    AppendChoisesSListValue(1, 9);
                    AppendChoisesSListValue(2, 6);
                    AppendChoisesSListValue(2, 1);
                    AppendChoisesSListValue(2, 9);
                }
            } else {
                AppendChoisesSListValue(1, 1);
                AppendChoisesSListValue(1, 6);
                AppendChoisesSListValue(1, 9);
                AppendChoisesSListValue(2, 6);
                AppendChoisesSListValue(2, 1);
                AppendChoisesSListValue(2, 9);
            }
            break;
        case 5:
            AppendChoisesSListValue(0, 0);
            if (GetCourseNumber() != 4) {
                AppendChoisesSListValue(1, 2);
            } else {
                AppendChoisesSListValue(1, 7);
            }
            break;
    }
    if (ChoisesSGetCurrentRaceKind() != RACE_KIND_START_GP && ChoisesSGetCurrentRaceKind() != RACE_KIND_STAFF_ROLL) {
        const char *nscrNames[6] = {
            gChoisesSNscr1Name, gChoisesSNscr2Name, gChoisesSNscr3Name,
            gChoisesSNscr4Name, gChoisesSNscr5Name, gChoisesSNscr6Name,
        };

        LoadNclrData(&gChoisesS->mChoisesSBNclr, FindSceneFileWrapper("choises_s_b.NCLR"));
        LoadNcgrData(&gChoisesS->mChoisesSBNcgr, FindSceneFileWrapper("choises_s_b.NCGR"));
        for (index = 0; index < 6; index++) {
            LoadNscrData(&gChoisesS->mChoisesSNscrs[index], FindSceneFileWrapper(nscrNames[index]));
        }
        gChoisesS->mList0Nscr = gChoisesS->mChoisesSNscrs[gChoisesS->mLists[0].mValueCount - 1];
        gChoisesS->mList1Nscr = gChoisesS->mChoisesSNscrs[gChoisesS->mLists[1].mValueCount - 1];
        gChoisesS->mList2Nscr = gChoisesS->mChoisesSNscrs[gChoisesS->mLists[2].mValueCount - 1];
        gChoisesS->mList3Nscr = gChoisesS->mChoisesSNscrs[gChoisesS->mLists[3].mValueCount - 1];
        gChoisesS->mList1Chars =
            HeapAlloc(ChoisesSGetCurrentHeap(), GetChoisesSListCharsSize(gChoisesS->mLists[1].mValueCount));
        switch (ChoisesSGetCurrentMode()) {
            case MODE_BATTLE:
            case MODE_VS:
            case MODE_MISSION_RUN:
                gChoisesS->mList2Chars =
                    HeapAlloc(ChoisesSGetCurrentHeap(), GetChoisesSListCharsSize(gChoisesS->mLists[2].mValueCount));
                break;
        }
        gChoisesS->mFont = GetFontByIndex(2);
        NNS_G2dCharCanvasInitForBG(gChoisesS->mCharCanvases[0], GetChoisesSBNcgrWithListChars()->mData, 0x20, 0xc, 4);
        choisesS = gChoisesS;
        ChoisesSInitTextCanvas(&choisesS->mTextCanvases[0], choisesS->mCharCanvases[0], choisesS->mFont, IsLanguageJa(),
                               0);
        NNS_G2dCharCanvasInitForBG(gChoisesS->mCharCanvases[1], gChoisesS->mList1Chars, 0x20, 0xc, 4);
        choisesS = gChoisesS;
        ChoisesSInitTextCanvas(&choisesS->mTextCanvases[1], choisesS->mCharCanvases[1], choisesS->mFont, IsLanguageJa(),
                               0);
        charCount = GetChoisesSListCharsSize(gChoisesS->mLists[1].mValueCount) >> 1;
        for (index = 0; index < charCount; index++) {
            gChoisesS->mList1Chars[index] = GetChoisesSBNcgrWithListChars()->mData[index];
        }
        if (gChoisesS->mList2Chars != NULL) {
            NNS_G2dCharCanvasInitForBG(gChoisesS->mCharCanvases[2], gChoisesS->mList2Chars, 0x20, 0xc, 4);
            choisesS = gChoisesS;
            ChoisesSInitTextCanvas(&choisesS->mTextCanvases[2], choisesS->mCharCanvases[2], choisesS->mFont,
                                   IsLanguageJa(), 0);
            charCount = GetChoisesSListCharsSize(gChoisesS->mLists[2].mValueCount) >> 1;
            for (index = 0; index < charCount; index++) {
                gChoisesS->mList2Chars[index] = GetChoisesSBNcgrWithListChars()->mData[index];
            }
        }
        NNS_G2dCharCanvasInitForBG(gChoisesS->mCharCanvases[3], GetChoisesSBNcgrWithListChars()->mData, 0x20, 0xc, 4);
        choisesS = gChoisesS;
        ChoisesSInitTextCanvas(&choisesS->mTextCanvases[3], choisesS->mCharCanvases[3], choisesS->mFont, IsLanguageJa(),
                               0);
        if (ChoisesSGetCurrentRaceKind() != RACE_KIND_REPLAY) {
            for (index = 0; index < gChoisesS->mLists[0].mValueCount; index++) {
                ChoisesSDrawTextOnCanvas(&gChoisesS->mTextCanvases[0], 0x90, index * 16 + 9, 0xc, 0x412,
                                         GetChoisesSValueMessage(0, gChoisesS->mLists[0].mValues[index]));
            }
        } else {
            for (index = 0; index < gChoisesS->mLists[3].mValueCount; index++) {
                ChoisesSDrawTextOnCanvas(&gChoisesS->mTextCanvases[3], 0x90, index * 16 + 9, 0xc, 0x412,
                                         GetChoisesSValueMessage(3, gChoisesS->mLists[3].mValues[index]));
            }
        }
        for (index = 0; index < gChoisesS->mLists[1].mValueCount; index++) {
            ChoisesSDrawTextOnCanvas(&gChoisesS->mTextCanvases[1], 0x90, index * 16 + 9, 0xc, 0x412,
                                     GetChoisesSValueMessage(1, gChoisesS->mLists[1].mValues[index]));
        }
        for (index = 0; index < gChoisesS->mLists[2].mValueCount; index++) {
            ChoisesSDrawTextOnCanvas(&gChoisesS->mTextCanvases[2], 0x90, index * 16 + 9, 0xc, 0x412,
                                     GetChoisesSValueMessage(2, gChoisesS->mLists[2].mValues[index]));
        }
    } else {
        gChoisesS->mChoisesSBNclr = NULL;
        gChoisesS->mChoisesSBNcgr = NULL;
        gChoisesS->mList1Chars = NULL;
        gChoisesS->mList2Chars = NULL;
        gChoisesS->mList0Nscr = NULL;
        gChoisesS->mList1Nscr = NULL;
        gChoisesS->mList2Nscr = NULL;
        gChoisesS->mList3Nscr = NULL;
    }
}

void ClearChoisesSPointer(void) {
    gChoisesS = NULL;
}

#pragma thumb off
