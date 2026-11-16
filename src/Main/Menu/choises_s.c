#include "Main/Menu/choises_s.h"
#include "Main/Save/buddy_record_time.h"
#include "Main/Graphics/oam.h"
#include "Main/Graphics/locate_bmg_sections.h"
#include "Main/Menu/choises_s_list_chars.h"
#include "Main/System/file_in_loaded.h"
#include "Main/Sound/sound_seq.h"
#include "Main/Race/race_setup_block.h"
#include "touch_panel_sampling.h"
#include "Main/Race/race_goal_s_rule.h"
#include "Main/Graphics/chars_block.h"
#include "Main/Item/item_objects_and_race_progress.h"
#include "Main/Race/kart.h"
#include "01/Menu/record_time_attack.h"
#include "01/Menu/record_time_attack_requests.h"
#include "Main/Race/race_hud_draw.h"
#include "Main/Race/race_start_sequence.h"
#include "Main/Race/race_goal_s_running.h"
#include "Main/Race/race_goal_m.h"
#include "Main/Race/race_new_record_ta.h"
#include "Main/System/backup_net_camera_work.h"
#include "Main/System/input_slots.h"
#include "00/Menu/wi_fi_vs_setting.h"
#include "Main/Graphics/disp_cap.h"
#include "Main/Race/standings_balloons.h"
#include "Main/Scene/scene_display_archive_work.h"
#include "Main/Scene/display_settings.h"
#include "archive_memory_load.h"
#include "heap_frame_allocator.h"
#include "thread_scheduler.h"
#include "Main/MapObjects/map_object_park.h"
#include "power_management_commands.h"
#include "Main/Menu/title_scene.h"
#include "Main/System/heap_call.h"
#include "Main/Menu/menu_shared_clear.h"
#include "Main/System/heap.h"
#include "Main/Graphics/font_glyph_text.h"
#include "char_canvas_text_draw.h"
#include "Main/Save/ghost_record_file.h"
#include "Main/System/init_after_startup.h"

char gChoisesSNscr4Name[] = "choises_s_4.NSCR";
char gChoisesSNscr1Name[] = "choises_s_1.NSCR";
char gChoisesSNscr5Name[] = "choises_s_5.NSCR";
char gChoisesSNscr6Name[] = "choises_s_6.NSCR";
char gChoisesSNscr2Name[] = "choises_s_2.NSCR";
char gChoisesSNscr3Name[] = "choises_s_3.NSCR";

#pragma thumb on
#pragma optimize_for_size on

void *GetMenuOptionString_from_thumb(s32 listIndex, s32 value) {
    s32 entryNumbers[11] = {0x5d, 0x67, 0x62, 0x64, 0x65, 0x66, 0x69, 0x62, 0x61, 0x5f, 0x75};

    if (GetDisplayMode_0() == RACE_KIND_REPLAY) {
        entryNumbers[0] = 0x6a;
        entryNumbers[8] = 0x63;
    }
    if (listIndex != 0) {
        entryNumbers[2] = 0x60;
    }
    return Bmg_GetRawStringPointer_from_thumb(j_FindFileBuffer_G2L_GE2_CKL_CKS_S2D_M2L_MA2("common.bmg"), entryNumbers[value]);
}

void ClearRaceOptionMenuEntries_from_thumb(void) {
    s32 listIndex;

    for (listIndex = 0; listIndex < 4; listIndex++) {
        g_RaceOptionMenuManager->mLists[listIndex].mValueCount = 0;
    }
}

void AppendChoisesSListValue(s32 listIndex, s32 value) {
    s32 valueCount;

    valueCount = g_RaceOptionMenuManager->mLists[listIndex].mValueCount;
    g_RaceOptionMenuManager->mLists[listIndex].mValueCount = valueCount + 1;
    g_RaceOptionMenuManager->mLists[listIndex].mValues[valueCount] = value;
}

s32 MaybeOnMenuOptionScroll_from_thumb(s32 step) {
    s32 selectedIndex = 0;
    s32 valueCount;
    s32 listIndex;
    ChoisesS *choisesS;

    if (IsChoisesSOpen() != 0) {
        listIndex = GetCurrentOptionMenuKind_from_thumb();
        valueCount = g_RaceOptionMenuManager->mLists[listIndex].mValueCount;
        for (; selectedIndex < valueCount; selectedIndex++) {
            if (g_RaceOptionMenuManager->mSelectedValue == g_RaceOptionMenuManager->mLists[listIndex].mValues[selectedIndex]) {
                break;
            }
        }
        if (valueCount == 1) {
            step = 0;
        } else if (valueCount == 2) {
            if (step != 0 && selectedIndex + step >= 0 && selectedIndex + step < valueCount) {
                g_RaceOptionMenuManager->mCycleFrames = 0;
                MaybePlaySomeSseqFromSarc0(0);
            } else {
                step = 0;
            }
        } else if (step != 0) {
            g_RaceOptionMenuManager->mCycleFrames = 0;
            MaybePlaySomeSseqFromSarc0(0);
        }
        choisesS = g_RaceOptionMenuManager;
        choisesS->mSelectedValue =
            choisesS->mLists[listIndex].mValues[(valueCount + (selectedIndex + step)) % valueCount];
    }
    return selectedIndex;
}

static inline ChoisesS *GetChoisesS(void) {
    return g_RaceOptionMenuManager;
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
        MaybeOnMenuOptionScroll_from_thumb(0);
        listIndex = GetCurrentOptionMenuKind_from_thumb();
        valueCount = g_RaceOptionMenuManager->mLists[listIndex].mValueCount;
        for (valueIndex = 0, firstRectRow = 0xc - valueCount * 2; valueIndex < valueCount; valueIndex++) {
            top = (firstRectRow + valueIndex * 4) * 8 + 6;
            valueRects[valueIndex].mMinX = CHOISES_S_RECT_MIN_X;
            valueRects[valueIndex].mMaxX = CHOISES_S_RECT_MAX_X;
            valueRects[valueIndex].mMinY = top;
            valueRects[valueIndex].mMaxY = top + 0x16;
        }
        for (valueIndex = 0; valueIndex < valueCount; valueIndex++) {
            if (IsNewPairInRect(Const8_0(), valueRects[valueIndex]) != 0) {
                if (g_RaceOptionMenuManager->mSelectedValue != GetChoisesS()->mLists[listIndex].mValues[valueIndex]) {
                    g_RaceOptionMenuManager->mSelectedValue = g_RaceOptionMenuManager->mLists[listIndex].mValues[valueIndex];
                    MaybeOnMenuOptionScroll_from_thumb(0);
                } else {
                    g_RaceOptionMenuManager->mPickStartedOnSelected = TRUE;
                }
                touched = 1;
            }
        }
        if (touched != 0) {
            if (g_RaceOptionMenuManager->mSelectedValue == CHOISES_S_PICK_CONTINUE) {
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

    g_RaceOptionMenuManager->mPickedValue = CHOISES_S_PICK_NONE;
    choisesS = g_RaceOptionMenuManager;
    choisesS->mSelectedValue = choisesS->mLists[GetCurrentOptionMenuKind_from_thumb()].mValues[0];
}

void SetChoisesSOpen(s32 openFlag) {
    if (g_RaceOptionMenuManager->mPickLocked != 0) {
        return;
    }
    if (openFlag != 0 && IsChoisesSOpen() == 0) {
        if (IsChoisesSOpenAllowedDuringRace() != 0) {
            g_RaceOptionMenuManager->mOpenDuringRace = openFlag;
        } else if (IsChoisesSOpenAllowedAfterRace() != 0) {
            g_RaceOptionMenuManager->mOpenAfterRace = openFlag;
        } else {
            return;
        }
        ResetChoisesSSelection();
    } else if (openFlag == 0 && IsChoisesSOpen() != 0) {
        if (IsChoisesSOpenAllowedDuringRace() != 0) {
            g_RaceOptionMenuManager->mOpenDuringRace = openFlag;
        } else if (IsChoisesSOpenAllowedAfterRace() != 0) {
            g_RaceOptionMenuManager->mOpenAfterRace = openFlag;
        } else {
            return;
        }
    }
    if (g_RaceOptionMenuManager->mPickedValue != CHOISES_S_PICK_NONE) {
        g_RaceOptionMenuManager->mPickLocked = 1;
    }
}

u32 IsCurrentMission_Boss6OrBoss7_from_thumb(void) {
    if ((GetCurrentMissionLevel_0() == 6 && GetCurrentMissionLevelStage_0() == 9) ||
        (GetCurrentMissionLevel_0() == 7 && GetCurrentMissionLevelStage_0() == 9)) {
        return 1;
    }
    return 0;
}
#pragma thumb off

s8 GetCurrentMissionLevel_0(void) {
    RaceSetup *raceSetup = g_GlobalCO;

    if (raceSetup->mMode == MODE_MISSION_RUN) {
        return raceSetup->mMissionTableRow;
    }
    return -1;
}

s8 GetCurrentMissionLevelStage_0(void) {
    RaceSetup *raceSetup = g_GlobalCO;

    if (raceSetup->mMode == MODE_MISSION_RUN) {
        return raceSetup->mMissionTableColumn;
    }
    return -1;
}

#pragma thumb on
// TRUE when the entry ended with kind 0, the other 53 cells held 5 to 7 at the start, and the current cell now holds 5
// to 7.
BOOL IsAllMissionRecords5To7AtGoalEnd(void) {
    s32 recordValue;
    s32 isFilled;

    isFilled = IsMissionStageBeaten(GetCurrentMissionLevel_0(), GetCurrentMissionLevelStage_0(), &recordValue);
    if (GetEntryEndKind() == 0 && g_RaceOptionMenuManager->mOtherMissionRecordsFilled5To7 != FALSE && isFilled != 0 &&
        (u32) (recordValue - 5) <= 2) {
        return 1;
    }
    return 0;
}
#pragma thumb off

#pragma thumb on

u32 IsRaceOptionMenuOn_from_thumb(void) {
    return (g_RaceOptionMenuManager->mOpenDuringRace);
}

#pragma thumb off

#pragma thumb on
#pragma optimize_for_size on
u32 IsChoisesSOpen(void) {
    if (IsRaceOptionMenuOn_from_thumb() != 0 || g_RaceOptionMenuManager->mOpenAfterRace != 0) {
        return 1;
    }
    return 0;
}
#pragma thumb off

#pragma thumb on

void SetChoisesSOpenDuringRace(u32 openFlag) {
    int wasOpen;
    int checkResult;
    wasOpen = IsRaceOptionMenuOn_from_thumb();
    checkResult = IsChoisesSOpenAllowedDuringRace();
    if (checkResult != 0) {
        SetChoisesSOpen(openFlag);
    }
    checkResult = IsRaceOptionMenuOn_from_thumb();
    if ((wasOpen == 0) && (checkResult != 0)) {
        LowerSndHandleVolumes();
    }
}

u32 MaybeIsMenuOn_from_thumb(void) {
    return (g_RaceOptionMenuManager->mPrevOpenDuringRace);
}

int GetChoisesSPickedValue(void) {
    int courseCountReached;
    int pickedValue;
    pickedValue = g_RaceOptionMenuManager->mPickedValue;
    if ((pickedValue == CHOISES_S_PICK_NEXT) &&
        (courseCountReached = IsRaceGoalSRuleCourseCountReached(), courseCountReached != 0)) {
        pickedValue = CHOISES_S_PICK_NEXT_LAST;
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

    valueCount = g_RaceOptionMenuManager->mLists[GetCurrentOptionMenuKind_from_thumb()].mValueCount;
    screenMap = GetChoisesSListScreenMapData();
    if (screenMap != NULL) {
        for (valueIndex = 0, firstRow = 0xd - valueCount * 2; valueIndex < valueCount; valueIndex++) {
            WriteChoisesSValueTiles(screenMap, 2, firstRow + valueIndex * 4);
        }
        SetScreenMapBlockTopBits(screenMap, 0, 0, 0x20, 0x18, 0xf);
    }
}
#pragma thumb off

u32 GetCurrentPlayerRacerId_0(void) {
    return (g_GlobalCO->mEntryIndex);
}

s32 GetEntryEndKind(void) {
    if (IsRacerFinishedRace((u16) GetCurrentPlayerRacerId_0()) != 0) {
        return g_GlobalMV->mEntryEndKind;
    }
    return 6;
}

#pragma thumb on
#pragma optimize_for_size on
u32 GetCurrentOptionMenuKind_from_thumb(void) {
    if (GetDisplayMode_0() == RACE_KIND_REPLAY && IsRaceEnded() == 0) {
        return 3;
    }
    if (IsRaceEnded() != 0) {
        if (GetRaceMode() == MODE_MISSION_RUN) {
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

    valueCount = g_RaceOptionMenuManager->mLists[GetCurrentOptionMenuKind_from_thumb()].mValueCount;
    screenMap = GetChoisesSListScreenMapData();
    if (screenMap != NULL) {
        if (g_RaceOptionMenuManager->mPickStartedOnSelected == FALSE || g_RaceOptionMenuManager->mPickFrames >= CHOISES_S_PICK_START_FRAMES) {
            row = 0xd - valueCount * 2 + selectedIndex * 4;
            if (g_RaceOptionMenuManager->mCycleFrames < CHOISES_S_CYCLE_LIT_FRAMES) {
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
    WriteChoisesSSelectedValueTiles(MaybeOnMenuOptionScroll_from_thumb(0));
}

#pragma thumb off

u32 SaveDataIoManagerIsBusy(void) {
    return (g_SaveDataIoManager->mBackupEnabled);
}

#pragma optimize_for_size on
s32 SaveDataIoManagerIsBusy12(void) {
    if (SaveDataIoManagerIsBusy() != 0) {
        return g_SaveDataIoManager->mCommandRunning;
    }
    return 0;
}

s32 SaveDataHolderIsBusy(void) {
    if (g_SaveDataHolder->mBusy != 0) {
        return 1;
    }
    return SaveDataIoManagerIsBusy12();
}

#pragma thumb on
u32 IsRaceDoneOrReplayPastStartFrames(void) {
    if (IsRaceEnded() != 0 ||
        (GetDisplayMode_0() == RACE_KIND_REPLAY && GetRaceStartCountdown() > 0xf0)) {
        return 1;
    }
    return 0;
}

u32 IsChoisesSOpenAllowedAfterRace(void) {
    if (IsRaceCountdownEnded() != 0 && IsRaceDoneOrReplayPastStartFrames() != 0 && GetB3F0_Beb0() != 0 &&
        IsRaceGoalSRunning() == 0 && IsSavingTimeTrialRecord() == 0 && IsRaceNewRecordTaRunning() == 0 &&
        GetShowLapTime() == 0 && (IsRaceOptionMenuOn_from_thumb() != 0 || IsSharedDispCapFadeFlagSet() == FALSE)) {
        return 1;
    }
    return 0;
}
#pragma thumb off

u32 IsCurrentMissionNotBeaten(void) {
    return (g_GlobalB488->mUnfilledNotEliminated);
}

u32 Const8_0(void) {
    return 0x8u;
}

u16 ChoisesSGetInputSlotNewBits(InputSlot *slot, u32 mask) {
    return slot->mPressedBits & mask;
}

u16 ChoisesSGetNewBits(s32 slotIndex, u32 mask) {
    return ChoisesSGetInputSlotNewBits(&g_GlobalCYT[slotIndex], mask);
}

u32 ChoisesSGetPairHasPair(InputSlotPair *inputSlotPair) {
    return inputSlotPair->mHasPair;
}

#pragma optimize_for_size on
u32 ChoisesSIsPairRecentlyLost(InputSlotPair *inputSlotPair) {
    if (ChoisesSGetPairHasPair(inputSlotPair) == 0 && inputSlotPair->mNoPairCount < INPUT_PAIR_LOSS_SAMPLES) {
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
    return ChoisesSIsPairNewUnlessRecentlyLost(&g_GlobalCYT[slotIndex].mPair);
}

void SetB488_B6(u32 value) {
    g_GlobalB488->mLVselIndex6Requested = value;
}

u32 IsRaceEnded(void) {
    return (g_GlobalMV->mRaceDone);
}

#pragma thumb on
#pragma optimize_for_size on
BOOL IsChoisesSOpenAllowedDuringRace(void) {
    u32 result = 0;
    u32 modeAllowsOpen = 0;
    u32 raceInProgress = 0;
    u32 noMissionWinner;

    if (IsRaceCountdownEnded() != 0 && GetRaceStartCountdown() > 0xf0 && IsRaceEnded() == 0 &&
        (GetRaceMode() != MODE_BATTLE || IsWinnerDecided() == FALSE)) {
        noMissionWinner = 1;
        if (GetRaceMode() == MODE_MISSION_RUN) {
            if ((GetRaceMode() == MODE_MISSION_RUN ? IsWinnerDecided() : 0) != FALSE) {
                noMissionWinner = 0;
            }
        }
        if (noMissionWinner != 0) {
            raceInProgress = 1;
        }
    }
    if (raceInProgress != 0) {
        if (GetRaceMode() != 5) {
            modeAllowsOpen = 1;
        }
    }
    if (modeAllowsOpen != 0) {
        if (IsRaceOptionMenuOn_from_thumb() != 0 || IsSharedDispCapFadeFlagSet() == FALSE) {
            result = 1;
        }
    }
    return result;
}
#pragma thumb off

u32 GetPMaybeState_0(void) {
    return (g_GlobalP->mConnectionKind);
}

#pragma thumb on
#pragma optimize_for_size on
void LoopFn_RaceMenuOptions_from_thumb(void) {
    s32 frames;

    g_RaceOptionMenuManager->mPrevOpenDuringRace = g_RaceOptionMenuManager->mOpenDuringRace;
    g_RaceOptionMenuManager->mCycleFrames = g_RaceOptionMenuManager->mCycleFrames + 1;
    if (g_RaceOptionMenuManager->mCycleFrames >= CHOISES_S_CYCLE_FRAMES) {
        g_RaceOptionMenuManager->mCycleFrames = 0;
    }
    if (SaveDataHolderIsBusy() != 0) {
        return;
    }
    if ((GetRaceMode() == MODE_GRAND_PRIX || GetRaceMode() == MODE_TIME_ATTACK) &&
        GetDisplayMode_0() == RACE_KIND_REPLAY && ShouldEndReplayRace() != 0) {
        return;
    }
    if (g_RaceOptionMenuManager->mPickFrames == 0 && g_RaceOptionMenuManager->mCloseFrames == 0 && IsChoisesSPickLocked() == 0) {
        if (IsRaceDoneOrReplayPastStartFrames() != 0) {
            if (IsChoisesSOpenAllowedAfterRace() != 0) {
                if (GetRaceMode() == MODE_MISSION_RUN && IsCurrentMissionNotBeaten() != 0 &&
                    IsCurrentMission_Boss6OrBoss7_from_thumb() != 0) {
                    if (ChoisesSGetNewBits(Const8_0(), PAD_KEY_A) != 0 ||
                        ChoisesSIsSlotPairNew(Const8_0()) != 0) {
                        g_RaceOptionMenuManager->mPickedValue = CHOISES_S_PICK_STAFF_CREDITS;
                        g_RaceOptionMenuManager->mSelectedValue = g_RaceOptionMenuManager->mPickedValue;
                        g_RaceOptionMenuManager->mPickLocked = 1;
                        StartChoisesSSelectedValueSeq();
                    }
                } else if (GetRaceMode() == MODE_MISSION_RUN && IsAllMissionRecords5To7AtGoalEnd() != 0) {
                    if (ChoisesSGetNewBits(Const8_0(), PAD_KEY_A) != 0 ||
                        ChoisesSIsSlotPairNew(Const8_0()) != 0) {
                        g_RaceOptionMenuManager->mPickedValue = CHOISES_S_PICK_SELECT_MISSION;
                        g_RaceOptionMenuManager->mSelectedValue = g_RaceOptionMenuManager->mPickedValue;
                        g_RaceOptionMenuManager->mPickLocked = 1;
                        StartChoisesSSelectedValueSeq();
                        SetB488_B6(1);
                    }
                } else if (GetRaceMode() == MODE_MISSION_RUN && IsCurrentMissionNotBeaten() != 0) {
                    if (ChoisesSGetNewBits(Const8_0(), PAD_KEY_A) != 0 ||
                        ChoisesSIsSlotPairNew(Const8_0()) != 0) {
                        g_RaceOptionMenuManager->mPickedValue = CHOISES_S_PICK_SELECT_MISSION;
                        g_RaceOptionMenuManager->mSelectedValue = g_RaceOptionMenuManager->mPickedValue;
                        g_RaceOptionMenuManager->mPickLocked = 1;
                        StartChoisesSSelectedValueSeq();
                    }
                } else if (ChoisesSGetNewBits(Const8_0(), 8) != 0) {
                    if (IsChoisesSOpen() != 0) {
                        RaiseSndHandleVolumes();
                        g_RaceOptionMenuManager->mCloseFrames = 1;
                    } else {
                        LowerSndHandleVolumes();
                        SetChoisesSOpen(1);
                    }
                } else if (MoveChoisesSSelectedValueByTouch() != 0) {
                    g_RaceOptionMenuManager->mPickFrames = 1;
                } else if (ChoisesSGetNewBits(Const8_0(), PAD_KEY_A) != 0) {
                    if (IsChoisesSOpen() != 0) {
                        if (g_RaceOptionMenuManager->mSelectedValue == CHOISES_S_PICK_CONTINUE) {
                            RaiseSndHandleVolumes();
                        } else {
                            StartChoisesSSelectedValueSeq();
                        }
                        g_RaceOptionMenuManager->mPickFrames = 1;
                        g_RaceOptionMenuManager->mPickStartedOnSelected = TRUE;
                    } else {
                        LowerSndHandleVolumes();
                        SetChoisesSOpen(1);
                    }
                } else if (ChoisesSGetNewBits(Const8_0(), PAD_KEY_B) != 0) {
                    if (IsChoisesSOpen() != 0) {
                        RaiseSndHandleVolumes();
                        g_RaceOptionMenuManager->mCloseFrames = 1;
                    }
                } else if (GetNewOrRepeatBits(Const8_0(), PAD_KEY_UP) != 0) {
                    MaybeOnMenuOptionScroll_from_thumb(-1);
                } else if (GetNewOrRepeatBits(Const8_0(), PAD_KEY_DOWN) != 0) {
                    MaybeOnMenuOptionScroll_from_thumb(1);
                }
            }
        } else if (IsChoisesSOpenAllowedDuringRace() != 0) {
            if (ChoisesSGetNewBits(Const8_0(), 8) != 0) {
                if (IsChoisesSOpen() != 0) {
                    RaiseSndHandleVolumes();
                    g_RaceOptionMenuManager->mCloseFrames = 1;
                } else {
                    LowerSndHandleVolumes();
                    SetChoisesSOpen(1);
                }
            } else if (MoveChoisesSSelectedValueByTouch() != 0) {
                g_RaceOptionMenuManager->mPickFrames = 1;
            } else if (ChoisesSGetNewBits(Const8_0(), PAD_KEY_A) != 0) {
                if (IsChoisesSOpen() != 0) {
                    if (g_RaceOptionMenuManager->mSelectedValue == CHOISES_S_PICK_CONTINUE) {
                        RaiseSndHandleVolumes();
                    } else {
                        StartChoisesSSelectedValueSeq();
                    }
                    g_RaceOptionMenuManager->mPickFrames = 1;
                    g_RaceOptionMenuManager->mPickStartedOnSelected = TRUE;
                }
            } else if (ChoisesSGetNewBits(Const8_0(), PAD_KEY_B) != 0) {
                if (IsChoisesSOpen() != 0) {
                    RaiseSndHandleVolumes();
                    g_RaceOptionMenuManager->mCloseFrames = 1;
                }
            } else if (GetNewOrRepeatBits(Const8_0(), PAD_KEY_UP) != 0) {
                MaybeOnMenuOptionScroll_from_thumb(-1);
            } else if (GetNewOrRepeatBits(Const8_0(), PAD_KEY_DOWN) != 0) {
                MaybeOnMenuOptionScroll_from_thumb(1);
            }
        }
    }
    frames = g_RaceOptionMenuManager->mPickFrames;
    if (frames != 0) {
        g_RaceOptionMenuManager->mPickFrames = frames + 1;
        if (g_RaceOptionMenuManager->mPickFrames > CHOISES_S_PICK_FRAMES) {
            if (IsRaceDoneOrReplayPastStartFrames() != 0) {
                if (IsChoisesSOpen() != 0) {
                    g_RaceOptionMenuManager->mPickedValue = g_RaceOptionMenuManager->mSelectedValue;
                    SetChoisesSOpen(0);
                } else {
                    SetChoisesSOpen(1);
                }
            } else if (IsChoisesSOpen() != 0) {
                g_RaceOptionMenuManager->mPickedValue = g_RaceOptionMenuManager->mSelectedValue;
                SetChoisesSOpen(0);
            }
            g_RaceOptionMenuManager->mPickFrames = 0;
            g_RaceOptionMenuManager->mPickStartedOnSelected = FALSE;
        }
    }
    frames = g_RaceOptionMenuManager->mCloseFrames;
    if (frames != 0) {
        g_RaceOptionMenuManager->mCloseFrames = frames + 1;
        if (g_RaceOptionMenuManager->mCloseFrames > CHOISES_S_CLOSE_FRAMES) {
            if (IsRaceDoneOrReplayPastStartFrames() != 0) {
                if (IsChoisesSOpen() != 0) {
                    SetChoisesSOpen(0);
                } else {
                    SetChoisesSOpen(1);
                }
            } else if (IsChoisesSOpen() != 0) {
                SetChoisesSOpen(0);
            }
            g_RaceOptionMenuManager->mCloseFrames = 0;
        }
    }
    if (GetPMaybeState_0() != 0 && GetRaceMode() == MODE_WIFI &&
        IsRaceDoneOrReplayPastStartFrames() != 0) {
        g_RaceOptionMenuManager->mAutoPickFrames = g_RaceOptionMenuManager->mAutoPickFrames + 1;
        if (g_RaceOptionMenuManager->mAutoPickFrames > CHOISES_S_AUTO_PICK_FRAMES) {
            g_RaceOptionMenuManager->mPickedValue = GetCourseNumber() != 4 ? CHOISES_S_PICK_NEXT : CHOISES_S_PICK_NEXT_LAST;
        }
    }
    if (IsRaceOptionMenuOn_from_thumb() != 0) {
        frames = g_RaceOptionMenuManager->mOpenDuringRaceFrames;
        g_RaceOptionMenuManager->mOpenDuringRaceFrames = frames + 1;
        if (frames >= 1) {
            g_RaceOptionMenuManager->mOpenDuringRaceState = CHOISES_S_OPEN_DURING_RACE_SETTLED;
            g_RaceOptionMenuManager->mOpenDuringRaceFrames = 1;
        }
    } else {
        g_RaceOptionMenuManager->mOpenDuringRaceState = 0;
        g_RaceOptionMenuManager->mOpenDuringRaceFrames = 0;
    }
}
#pragma thumb off

#pragma thumb on

void LoopFn_RaceMenuOptions2_from_thumb(void) {
    int isOpen;
    isOpen = IsChoisesSOpen();
    if (isOpen != 0) {
        WriteChoisesSListScreenMap();
    }
}

#pragma thumb off

void *GetActiveExecutionContextHeapHandle_3(void) {
    return ExecutionContext_GetHeapHandle(GetActiveExecutionContext());
}

u32 GetRaceMode(void) {
    return (g_GlobalCO->mMode);
}

#pragma thumb on
#pragma optimize_for_size on
BOOL IsGrandPrixLastCourse(void) {
    return GetRaceMode() == MODE_GRAND_PRIX && GetCourseNumber() == 4;
}
#pragma thumb off

u32 GetCourseNumber(void) {
    return (g_GlobalCO->mCourseNumber);
}

u32 GetDisplayMode_0(void) {
    return g_GlobalCO->mRaceKind;
}

struct ChoisesS *g_RaceOptionMenuManager;

void RaceOptionMenuEntryDrawContext_Create(TextCanvas *textCanvas, void *charCanvas, void *font, s32 charSpacing, s32 lineSpacing) {
    textCanvas->mCharCanvas = charCanvas;
    textCanvas->mFont = font;
    textCanvas->mCharSpacing = charSpacing;
    textCanvas->mLineSpacing = lineSpacing;
}

u32 G2d_Text_PrintString3(TextCanvas *textCanvas, s32 textX, s32 textY, u32 color, u32 flags, void *text) {
    return G2d_Text_PrintString(textCanvas, textX, textY, color, flags, text);
}

#pragma thumb on
#pragma optimize_for_size on

void LoadRaceOptionMenus_from_thumb(void) {
    ChoisesS *choisesS;
    u32 charCount;
    s32 index;

    g_RaceOptionMenuManager = Mem_AllocateHeap(GetActiveExecutionContextHeapHandle_3(), sizeof(*g_RaceOptionMenuManager));
    g_RaceOptionMenuManager->mOpenDuringRace = 0;
    g_RaceOptionMenuManager->mPrevOpenDuringRace = 0;
    g_RaceOptionMenuManager->mOpenAfterRace = 0;
    g_RaceOptionMenuManager->mPickLocked = 0;
    g_RaceOptionMenuManager->mPickFrames = 0;
    g_RaceOptionMenuManager->mPickStartedOnSelected = FALSE;
    g_RaceOptionMenuManager->mAutoPickFrames = 0;
    if (GetRaceMode() == MODE_MISSION_RUN) {
        g_RaceOptionMenuManager->mOtherMissionRecordsFilled5To7 = MaybeAllMissionStagesBeatenWithStarRank_from_thumb();
    } else {
        g_RaceOptionMenuManager->mOtherMissionRecordsFilled5To7 = FALSE;
    }
    g_RaceOptionMenuManager->mOpenDuringRaceState = 0;
    g_RaceOptionMenuManager->mOpenDuringRaceFrames = 0;
    ResetChoisesSSelection();
    ClearRaceOptionMenuEntries_from_thumb();
    switch (GetRaceMode()) {
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
            if (IsCurrentMission_Boss6OrBoss7_from_thumb() != 0) {
                if (IsCurrentMissionLevelStageBeaten_from_thumb() != 0) {
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
        case MODE_WIFI:
            AppendChoisesSListValue(0, 0);
            if (GetCourseNumber() != 4) {
                AppendChoisesSListValue(1, 2);
            } else {
                AppendChoisesSListValue(1, 7);
            }
            break;
    }
    if (GetDisplayMode_0() != RACE_KIND_START_GP && GetDisplayMode_0() != RACE_KIND_STAFF_ROLL) {
        const char *nscrNames[6] = {
            gChoisesSNscr1Name, gChoisesSNscr2Name, gChoisesSNscr3Name,
            gChoisesSNscr4Name, gChoisesSNscr5Name, gChoisesSNscr6Name,
        };

        Gfx_ReadPalette(&g_RaceOptionMenuManager->mChoisesSBNclr, j_FindFileBuffer_K2D_LOC_R2D_R2L("choises_s_b.NCLR"));
        Gfx_ReadCharGraphicsV2(&g_RaceOptionMenuManager->mChoisesSBNcgr, j_FindFileBuffer_K2D_LOC_R2D_R2L("choises_s_b.NCGR"));
        for (index = 0; index < 6; index++) {
            MaybeReadScreenBlock_0(&g_RaceOptionMenuManager->mChoisesSNscrs[index], j_FindFileBuffer_K2D_LOC_R2D_R2L(nscrNames[index]));
        }
        g_RaceOptionMenuManager->mList0Nscr = g_RaceOptionMenuManager->mChoisesSNscrs[g_RaceOptionMenuManager->mLists[0].mValueCount - 1];
        g_RaceOptionMenuManager->mList1Nscr = g_RaceOptionMenuManager->mChoisesSNscrs[g_RaceOptionMenuManager->mLists[1].mValueCount - 1];
        g_RaceOptionMenuManager->mList2Nscr = g_RaceOptionMenuManager->mChoisesSNscrs[g_RaceOptionMenuManager->mLists[2].mValueCount - 1];
        g_RaceOptionMenuManager->mList3Nscr = g_RaceOptionMenuManager->mChoisesSNscrs[g_RaceOptionMenuManager->mLists[3].mValueCount - 1];
        g_RaceOptionMenuManager->mList1Chars =
            Mem_AllocateHeap(GetActiveExecutionContextHeapHandle_3(), ComputeSomeMESize_from_thumb(g_RaceOptionMenuManager->mLists[1].mValueCount));
        switch (GetRaceMode()) {
            case MODE_BATTLE:
            case MODE_VS:
            case MODE_MISSION_RUN:
                g_RaceOptionMenuManager->mList2Chars =
                    Mem_AllocateHeap(GetActiveExecutionContextHeapHandle_3(), ComputeSomeMESize_from_thumb(g_RaceOptionMenuManager->mLists[2].mValueCount));
                break;
        }
        g_RaceOptionMenuManager->mFont = GetLoadedFont_from_thumb(2);
        G2d_Sprite_CreateFromTiles(g_RaceOptionMenuManager->mCharCanvases[0], GetSomeBgTileData_from_thumb()->mData, 0x20, 0xc, 4);
        choisesS = g_RaceOptionMenuManager;
        RaceOptionMenuEntryDrawContext_Create(&choisesS->mTextCanvases[0], choisesS->mCharCanvases[0], choisesS->mFont, ComputeSomeInterCharacterWidth(),
                               0);
        G2d_Sprite_CreateFromTiles(g_RaceOptionMenuManager->mCharCanvases[1], g_RaceOptionMenuManager->mList1Chars, 0x20, 0xc, 4);
        choisesS = g_RaceOptionMenuManager;
        RaceOptionMenuEntryDrawContext_Create(&choisesS->mTextCanvases[1], choisesS->mCharCanvases[1], choisesS->mFont, ComputeSomeInterCharacterWidth(),
                               0);
        charCount = ComputeSomeMESize_from_thumb(g_RaceOptionMenuManager->mLists[1].mValueCount) >> 1;
        for (index = 0; index < charCount; index++) {
            g_RaceOptionMenuManager->mList1Chars[index] = GetSomeBgTileData_from_thumb()->mData[index];
        }
        if (g_RaceOptionMenuManager->mList2Chars != NULL) {
            G2d_Sprite_CreateFromTiles(g_RaceOptionMenuManager->mCharCanvases[2], g_RaceOptionMenuManager->mList2Chars, 0x20, 0xc, 4);
            choisesS = g_RaceOptionMenuManager;
            RaceOptionMenuEntryDrawContext_Create(&choisesS->mTextCanvases[2], choisesS->mCharCanvases[2], choisesS->mFont,
                                   ComputeSomeInterCharacterWidth(), 0);
            charCount = ComputeSomeMESize_from_thumb(g_RaceOptionMenuManager->mLists[2].mValueCount) >> 1;
            for (index = 0; index < charCount; index++) {
                g_RaceOptionMenuManager->mList2Chars[index] = GetSomeBgTileData_from_thumb()->mData[index];
            }
        }
        G2d_Sprite_CreateFromTiles(g_RaceOptionMenuManager->mCharCanvases[3], GetSomeBgTileData_from_thumb()->mData, 0x20, 0xc, 4);
        choisesS = g_RaceOptionMenuManager;
        RaceOptionMenuEntryDrawContext_Create(&choisesS->mTextCanvases[3], choisesS->mCharCanvases[3], choisesS->mFont, ComputeSomeInterCharacterWidth(),
                               0);
        if (GetDisplayMode_0() != RACE_KIND_REPLAY) {
            for (index = 0; index < g_RaceOptionMenuManager->mLists[0].mValueCount; index++) {
                G2d_Text_PrintString3(&g_RaceOptionMenuManager->mTextCanvases[0], 0x90, index * 16 + 9, 0xc, 0x412,
                                         GetMenuOptionString_from_thumb(0, g_RaceOptionMenuManager->mLists[0].mValues[index]));
            }
        } else {
            for (index = 0; index < g_RaceOptionMenuManager->mLists[3].mValueCount; index++) {
                G2d_Text_PrintString3(&g_RaceOptionMenuManager->mTextCanvases[3], 0x90, index * 16 + 9, 0xc, 0x412,
                                         GetMenuOptionString_from_thumb(3, g_RaceOptionMenuManager->mLists[3].mValues[index]));
            }
        }
        for (index = 0; index < g_RaceOptionMenuManager->mLists[1].mValueCount; index++) {
            G2d_Text_PrintString3(&g_RaceOptionMenuManager->mTextCanvases[1], 0x90, index * 16 + 9, 0xc, 0x412,
                                     GetMenuOptionString_from_thumb(1, g_RaceOptionMenuManager->mLists[1].mValues[index]));
        }
        for (index = 0; index < g_RaceOptionMenuManager->mLists[2].mValueCount; index++) {
            G2d_Text_PrintString3(&g_RaceOptionMenuManager->mTextCanvases[2], 0x90, index * 16 + 9, 0xc, 0x412,
                                     GetMenuOptionString_from_thumb(2, g_RaceOptionMenuManager->mLists[2].mValues[index]));
        }
    } else {
        g_RaceOptionMenuManager->mChoisesSBNclr = NULL;
        g_RaceOptionMenuManager->mChoisesSBNcgr = NULL;
        g_RaceOptionMenuManager->mList1Chars = NULL;
        g_RaceOptionMenuManager->mList2Chars = NULL;
        g_RaceOptionMenuManager->mList0Nscr = NULL;
        g_RaceOptionMenuManager->mList1Nscr = NULL;
        g_RaceOptionMenuManager->mList2Nscr = NULL;
        g_RaceOptionMenuManager->mList3Nscr = NULL;
    }
}

void ResetRaceMenuOptions_from_thumb(void) {
    g_RaceOptionMenuManager = NULL;
}

#pragma thumb off
