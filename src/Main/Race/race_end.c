#include "Main/Race/race_end.h"
#include "Main/Race/race_end_condition.h"
#include "Main/System/heap.h"
#include "Main/Race/cup_records.h"
#include "Main/Save/buddy_record_time.h"
#include "Main/Graphics/stem_sets.h"

#include "Main/Race/code_020b1dbc.h"
#include "Main/Kart/point_link_cursor.h"
#include "Main/Race/race_hud_sub_screen_course_id.h"
#include "code_02012b30.h"
#include "Main/Race/data_021759c0.h"
#include "tp.h"
#include "Main/Race/followed_kart_or.h"
#include "Main/Race/race_hud_sub_screen_min_max.h"
#include "Main/Kart/code_0207a880.h"
#include "Main/Race/race_hud_sub_screen_projection.h"
#include "Main/Race/race_hud_sub_screen_item_box_cells.h"
#include "Main/Race/data_020f36d8.h"
#include "Main/Race/data_0217b35c.h"
#include "Main/Menu/data_0217d000.h"
#include "player.h"
#include "code_0212c7a0.h"
#include "stream.h"
#include "code_0212c9d4.h"
#include "Main/Graphics/layout_rect_table.h"
#include "Main/Graphics/layout_entry_angle.h"
#include "Main/Graphics/layout_table_entry.h"
#include "Main/Race/race_hud_sub_screen_cells.h"
#include "code_0212d214.h"
#include "Main/Sound/sound_seq.h"
#include "code_0212df7c.h"
#include "Main/System/heap_call.h"
#include "Main/System/low_byte.h"
#include "Main/MapObjects/data_0217a000.h"
#include "Main/Race/kart.h"
#include "Main/Race/race_clock.h"
#include "Main/Kart/karts.h"
#include "Main/Sound/sound_system.h"
#include "Main/Save/ghost_record_file.h"
#include "Main/System/init_after_startup.h"

RaceEnd *gRaceEnd;

void RequestRaceEndStemSet(void) {
    gRaceEnd->mStemSetRequested = TRUE;
}

void SetKartCupRanks(void) {
    RaceSetup *raceSetup = gRaceSetup;
    s32 sortKeys[8];
    s32 sortedIndices[8];
    u16 kartIndex;
    u16 rankIndex;
    s32 keySign = -1;
    s32 humanGhostOrPeerBit;
    s32 lowByte;
    s32 courseIndexInCup;
    s32 cupScore;
    BOOL isHumanGhostOrPeer;
    KartCourseResult *courseResult;

    if (raceSetup->mMode == MODE_TIME_ATTACK) {
        return;
    }
    if (raceSetup->mMode == MODE_MISSION_RUN) {
        return;
    }
    for (kartIndex = 0; kartIndex < (u32) gRaceSetup->mKartCount; kartIndex++) {
        if (gRaceSetup->mRuleKind == RULE_KIND_WIN_COUNT || gRaceSetup->mMode == MODE_BATTLE) {
            isHumanGhostOrPeer = FALSE;
            if (gRaceSetup->mCurrentEntries[kartIndex].mPlayer.mKind <= 3) {
                if ((1 << gRaceSetup->mCurrentEntries[kartIndex].mPlayer.mKind) & PLAYER_KIND_MASK_HUMAN_GHOST_PEER) {
                    isHumanGhostOrPeer = TRUE;
                }
            }
            humanGhostOrPeerBit = isHumanGhostOrPeer != FALSE ? 1 : 0;
            lowByte = GetLowByte(kartIndex);
            courseIndexInCup = GetCourseIndexInCup();
            cupScore = gCupRecords->mKartResults[courseIndexInCup][GetLowByte(lowByte)].mWinCount;
            sortKeys[kartIndex] = (cupScore << 4) + (humanGhostOrPeerBit << 3) + 8 - GetKartRank(kartIndex);
        } else {
            isHumanGhostOrPeer = FALSE;
            if (gRaceSetup->mCurrentEntries[kartIndex].mPlayer.mKind <= 3) {
                if ((1 << gRaceSetup->mCurrentEntries[kartIndex].mPlayer.mKind) & PLAYER_KIND_MASK_HUMAN_GHOST_PEER) {
                    isHumanGhostOrPeer = TRUE;
                }
            }
            humanGhostOrPeerBit = isHumanGhostOrPeer != FALSE ? 1 : 0;
            lowByte = GetLowByte(kartIndex);
            courseIndexInCup = GetCourseIndexInCup();
            courseResult = &gCupRecords->mKartResults[courseIndexInCup][GetLowByte(lowByte)];
            cupScore = courseResult->mTotalPoints;
            sortKeys[kartIndex] = (cupScore << 4) + (humanGhostOrPeerBit << 3) + 8 - GetKartRank(kartIndex);
        }
    }
    for (kartIndex = 0; kartIndex < (u32) gRaceSetup->mKartCount; kartIndex++) {
        sortedIndices[kartIndex] = kartIndex;
        sortKeys[kartIndex] = sortKeys[kartIndex] * keySign;
    }
    SortIndicesByKey(sortedIndices, sortKeys, gRaceSetup->mKartCount);
    for (kartIndex = 0; kartIndex < (u32) gRaceSetup->mKartCount; kartIndex++) {
        for (rankIndex = 0; rankIndex < (u32) gRaceSetup->mKartCount; rankIndex++) {
            if (kartIndex == sortedIndices[rankIndex]) {
                SetKartCupRank(kartIndex, rankIndex + 1);
                break;
            }
        }
    }
}

static inline CourseTeamResult *RaceEndGetCourseTeamResult(s32 teamIndex) {
    return &gCupRecords->mTeamResults[GetCourseIndexInCup()].mTeams[teamIndex];
}

static inline CourseTeamResults *RaceEndGetCourseTeamResults(void) {
    return &gCupRecords->mTeamResults[GetCourseIndexInCup()];
}

void SetCupWinningTeamFromRecords(void) {
    RaceSetup *raceSetup = gRaceSetup;
    s32 firstTeamScore;
    s32 secondTeamScore;
    BOOL isWinCountOrBattle;
    u16 kartIndex;
    CourseTeamResult *firstTeamRecord;

    if (raceSetup->mUseTeams == 0) {
        return;
    }
    if (raceSetup->mRuleKind == RULE_KIND_WIN_COUNT || raceSetup->mMode == MODE_BATTLE) {
        firstTeamScore = RaceEndGetCourseTeamResult(0)->mWinCount;
    } else {
        firstTeamRecord = &gCupRecords->mTeamResults[GetCourseIndexInCup()].mTeams[0];
        firstTeamScore = firstTeamRecord->mTotalPoints;
    }
    raceSetup = gRaceSetup;
    isWinCountOrBattle = TRUE;
    if (raceSetup->mRuleKind != RULE_KIND_WIN_COUNT && raceSetup->mMode != MODE_BATTLE) {
        isWinCountOrBattle = FALSE;
    }
    if (isWinCountOrBattle) {
        secondTeamScore = RaceEndGetCourseTeamResult(1)->mWinCount;
    } else {
        secondTeamScore = RaceEndGetCourseTeamResults()->mTeams[1].mTotalPoints;
    }
    if (firstTeamScore > secondTeamScore) {
        SetCupWinningTeam(0);
        return;
    }
    if (secondTeamScore > firstTeamScore) {
        SetCupWinningTeam(1);
        return;
    }
    for (kartIndex = 0; kartIndex < (u32) gRaceSetup->mKartCount; kartIndex++) {
        if (GetKartRank(kartIndex) == 1) {
            break;
        }
    }
    SetCupWinningTeam(gRaceSetup->mCurrentEntries[kartIndex].mPlayer.mTeamIndex);
}

void InitRaceEnd(void) {
    gRaceEnd = HeapAlloc(GetHeap(GetCurrentHeapCall()), 0x10);
    gRaceEnd->mEndFrames = 0;
    gRaceEnd->mStemSetRequested = FALSE;
    gRaceEnd->mStemSetRequestFrames = 0;
    gRaceEnd->mResultsSet = FALSE;
}

void ClearRaceEndPointer(void) {
    gRaceEnd = NULL;
}

void ResetRaceEndFrames(void) {
    gRaceEnd->mEndFrames = 0;
}

void UpdateRaceEnd(void) {
    RaceSetup *raceSetup;
    s32 frames;
    s32 followedKartStatus;
    BOOL playsRaceEndSound;
    u16 followedKartIndex;

    if (gRaceProgress->mRaceDone != 0 && gRaceEnd->mResultsSet == FALSE) {
        SetKartCupRanks();
        SetCupWinningTeamFromRecords();
        SetRaceResultRecords();
        gRaceEnd->mResultsSet = TRUE;
    }
    followedKartIndex = GetFollowedKartOrEntryIndex();
    if (gRaceProgress->mKarts[followedKartIndex].mStatus != RACE_PROGRESS_KART_STATUS_GOAL_REACHED &&
        gRaceProgress->mRaceDone == 0) {
        return;
    }
    frames = gRaceEnd->mEndFrames;
    if (frames < 11) {
        gRaceEnd->mEndFrames = frames + 1;
        if (frames == 0) {
            raceSetup = gRaceSetup;
            switch (raceSetup->mMode) {
                case MODE_GRAND_PRIX:
                case MODE_TIME_ATTACK:
                    SetStemSet(STEM_SET_GOAL);
                    break;
                case MODE_VS:
                case MODE_WIFI:
                    if (raceSetup->mRuleKind != RULE_KIND_WIN_COUNT) {
                        if (gRaceProgress->mKarts[GetFollowedKartOrEntryIndex()].mStatus ==
                            RACE_PROGRESS_KART_STATUS_GOAL_REACHED) {
                            SetStemSet(STEM_SET_GOAL);
                        }
                    }
                    break;
            }
            if ((gSoundModeHolder.mMode - 2) <= 1 && gRaceSetup->mMode != MODE_BATTLE) {
                raceSetup = gRaceSetup;
                playsRaceEndSound = TRUE;
                if (raceSetup->mRaceKind == RACE_KIND_DEMO) {
                    playsRaceEndSound = FALSE;
                } else if (raceSetup->mMode == MODE_MISSION_RUN) {
                    switch (raceSetup->mMissionKind) {
                        case MISSION_KIND_LAPS:
                        case MISSION_KIND_LAPS_MINI_TURBO_COUNT:
                        case MISSION_KIND_LAPS_FIRST_PLACE:
                        case MISSION_KIND_LAPS_NO_LAP_PROGRESS:
                            if ((IsKartEnded((u16) raceSetup->mEntryIndex) ? gRaceProgress->mEntryEndKind
                                                                           : RACE_END_KIND_NOT_ENDED) != 0) {
                                playsRaceEndSound = FALSE;
                            }
                            break;
                        default:
                            playsRaceEndSound = FALSE;
                            break;
                    }
                }
                if (playsRaceEndSound != FALSE) {
                    if (IsRaceNewRecordTaFinishRecord() != 0 || IsRaceNewRecordTaBestLapRecord() != 0) {
                        NNS_SndArcPlayerStartSeqArc(&gSharedSeqHandle, 0, 0x44);
                    } else {
                        followedKartStatus = gRaceProgress->mKarts[GetFollowedKartOrEntryIndex()].mStatus;
                        if (followedKartStatus == RACE_PROGRESS_KART_STATUS_ENDED_NO_GOAL) {
                            NNS_SndArcPlayerStartSeqArc(&gSharedSeqHandle, 0, 0x43);
                        } else {
                            NNS_SndArcPlayerStartSeqArc(&gSharedSeqHandle, 0, 0x42);
                        }
                    }
                }
            }
        } else if (frames == 10) {
            raceSetup = gRaceSetup;
            switch (raceSetup->mMode) {
                case MODE_VS:
                    if (raceSetup->mRuleKind == RULE_KIND_WIN_COUNT) {
                        SetStemSet((GetKart(raceSetup->mEntryIndex)->mEntryFlags & KART_ENTRY_WINNER) ? STEM_SET_WIN
                                                                                                      : STEM_SET_LOSE);
                    }
                    break;
                case MODE_BATTLE:
                    SetStemSet((GetKart(raceSetup->mEntryIndex)->mEntryFlags & KART_ENTRY_WINNER) ? STEM_SET_WIN
                                                                                                  : STEM_SET_LOSE);
                    break;
                case MODE_MISSION_RUN:
                    if ((IsKartEnded((u16) raceSetup->mEntryIndex) ? gRaceProgress->mEntryEndKind
                                                                   : RACE_END_KIND_NOT_ENDED) != 0) {
                        SetStemSet(STEM_SET_FAILED);
                    }
                    break;
                case MODE_GRAND_PRIX:
                case MODE_TIME_ATTACK:
                case MODE_WIFI:
                    break;
            }
        }
    }
    if (gRaceEnd->mStemSetRequested == FALSE) {
        return;
    }
    frames = gRaceEnd->mStemSetRequestFrames;
    gRaceEnd->mStemSetRequestFrames = frames + 1;
    if (frames != 10) {
        return;
    }
    raceSetup = gRaceSetup;
    switch (raceSetup->mMode) {
        case MODE_MISSION_RUN:
            if ((IsKartEnded((u16) raceSetup->mEntryIndex) ? gRaceProgress->mEntryEndKind : RACE_END_KIND_NOT_ENDED) ==
                0) {
                SetStemSet(STEM_SET_COMPLETE);
            }
            break;
        case MODE_GRAND_PRIX:
        case MODE_TIME_ATTACK:
        case MODE_BATTLE:
        case MODE_VS:
        case MODE_WIFI:
            break;
    }
    gRaceEnd->mStemSetRequested = FALSE;
}
