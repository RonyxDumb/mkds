#include "Main/Menu/choises_s_screen_map.h"
#include "Main/Menu/choises_s_course.h"
#include "Main/Race/entry_index.h"
#include "Main/Menu/choises_s_list_chars.h"
#include "Main/Graphics/chars_block.h"
#include "Main/Race/race_goal_s_rule.h"
#include "Main/Race/data_020f36d8.h"
#include "Main/Menu/choises_s.h"
#include "Main/Race/kart.h"
#include "Main/Menu/choises_s_tiles.h"
#include "Main/Menu/choises_s_select.h"
#include "01/Menu/record_time_attack.h"
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
#include "Main/Race/data_021759c0.h"
#include "tp.h"
#include "Main/Menu/data_02175000.h"
#include "Main/Scene/display_settings.h"
#include "code_020182c0.h"
#include "frameheap.h"
#include "os_thread.h"
#include "Main/MapObjects/map_object_park.h"
#include "pm.h"
#include "Main/Sound/sound_seq.h"
#include "Main/Menu/title_scene.h"
#include "Main/Graphics/oam.h"
#include "Main/System/heap_call.h"

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
