#include "Main/Race/standings_balloons.h"
#include "Main/MapObjects/bound.h"

#include "Main/System/heap.h"
#include "Main/Kart/kart_participant_record.h"
#include "Main/MapObjects/map_object_model_frame.h"
#include "Main/Sound/sound_handle_accessors_and_mission_count_seq.h"
#include "Main/MapObjects/view_frustum.h"
#include "Main/Sound/start_sound_from_params.h"
#include "Main/Sound/sound_init_scene_sounds_and_screen_seqs.h"
#include "Main/System/backup_net_camera_work.h"
#include "Main/Race/race.h"
#include "Main/Kart/kart_drift.h"
#include "ITCM/kart_motion.h"
#include "Main/System/heap_call.h"
#include "Main/Item/item_objects_and_race_progress.h"
#include "Main/Race/race_hud_keyboard_map_object_work.h"
#include "Main/Race/race_setup_block.h"
#include "touch_panel_sampling.h"
#include "Main/System/input_slots.h"
#include "Main/Sound/sound_handle_pool_request_queue_and_set_player.h"
#include "Main/Sound/sound_ortho_quad_and_item_box_timer_globals.h"
#include "sound_player_control.h"
#include "sound_archive_load.h"
#include "matrix44_concat.h"
#include "Main/Graphics/ortho_quad_corners.h"
#include "Main/Sound/surface_sound_ids_on_memory_sdat_and_list_links.h"
#include "Main/Sound/sound_source_types_and_handle_sound_start.h"
#include "Main/Menu/menu_screens_work.h"
#include "sound_player_type.h"
#include "sound_stream_control.h"
#include "sound_capture_effect.h"
#include "Main/Graphics/layout_rect_table.h"
#include "Main/Graphics/layout_entry_angle.h"
#include "Main/Graphics/layout_table_entry.h"
#include "Main/Race/race_hud_sub_screen_cells.h"
#include "Main/Menu/keyboard_cursor_targets.h"
#include "Main/Kart/kart_ai_item_use.h"
#include "sound_archive_load_result.h"
#include "Main/Race/race_end_condition.h"
#include "Main/Kart/kart_heading_item_effect.h"
#include "Main/Race/kart_standing_rank.h"
#include "Main/Kart/karts.h"
#include "Main/Sound/sound_system.h"
#include "Main/Menu/keyboard_cursor_targets.h"
#include "Main/System/init_after_startup.h"

const u32 gShineBattleTimeLimits[4] = {0xffff, 0x1e, 0x1e, 0x1e};
const s32 gCharacterBalloonOrShineHeights[16] = {0x11000, 0x16000, 0x11000, 0x17000, 0x11800, 0x12000, 0x11000, 0x11000,
                                                 0x10800, 0x11000, 0x13000, 0x15000, 0x10800, 0,       0,       0};
Standings *gStandings;

MapObjectKindDescriptor gDistanceSoundKindDescriptor = {
    0, {0, 0}, 0xcc, InitDistanceSound, CreateEmptyMapObjectKindData, 0, 0, 0, CreateDistanceSoundUpdateList};

void SetStandingsKartBalloons(KartBalloons *kartBalloons) {
    gStandings->mKartBalloons = kartBalloons;
}

KartBalloons *GetStandingsKartBalloons(void) {
    return gStandings->mKartBalloons;
}

void SetStandingsKartHitByKartCallback(s32 (*callback)(s32, s32)) {
    gStandings->mKartHitByKartCallback = callback;
}

void SetStandingsKartsHitEachOtherCallback(void (*callback)(s32, s32)) {
    gStandings->mKartsHitEachOtherCallback = callback;
}

void SetStandingsKartHitCallback(s32 (*callback)(u16 kartIndex, u16 hitByKartIndex)) {
    gStandings->mKartHitCallback = callback;
}

void SetStandingsKartEliminatedCallback(void (*callback)(u16 kartIndex)) {
    gStandings->mKartEliminatedCallback = callback;
}

void SetStandingsEndCallback(void (*callback)(void)) {
    gStandings->mEndCallback = callback;
}

void SetStandingsKartOffsetCallback(void (*callback)(u16, Vec3 *)) {
    gStandings->mKartOffsetCallback = callback;
}

void StartKartMicInflate(u16 kartIndex) {
    if (IsRaceStarted() != 1) {
        return;
    }
    if (IsKartNotNormalOrFlagged(GetKart(kartIndex)) != FALSE) {
        return;
    }
    gStandings->mKarts[kartIndex].mMicInflateTimer = STANDINGS_MIC_INFLATE_FRAMES;
}

void StopKartMicInflate(int kartIndex) {
    gStandings->mKarts[kartIndex].mMicInflateTimer = STANDINGS_MIC_INFLATE_STOPPED;
}

s32 GetKartMicInflateTimer(u16 kartIndex) {
    if (gStandings->mWinnerTeamId >= 0) {
        return -1;
    }
    return gStandings->mKarts[kartIndex].mMicInflateTimer;
}

s32 GetKartSelectKeyInflate(u16 kartIndex) {
    if (gStandings->mWinnerTeamId >= 0) {
        return -1;
    }
    return gStandings->mKarts[kartIndex].mSelectKeyInflate;
}

void SetKartInflatingBalloon(u16 kartIndex, u32 inflating) {
    gStandings->mKarts[kartIndex].mInflatingBalloon = inflating;
}

u32 IsKartInflatingBalloon(u16 kartIndex) {
    return gStandings->mKarts[kartIndex].mInflatingBalloon;
}

void CallStandingsKartOffsetCallback(u16 kartIndex, Vec3 *offset) {
    if (offset == 0) {
        return;
    }
    if (gStandings->mKartOffsetCallback != NULL) {
        gStandings->mKartOffsetCallback(kartIndex, offset);
    }
}

s32 CallKartCollisionCallbacks(s32 firstKartIndex, s32 secondKartIndex) {
    Kart *firstKart;
    Kart *secondKart;
    KartStanding *firstStanding;
    KartStanding *secondStanding;
    BOOL firstHitsSecond;
    s32 result;
    BOOL firstGuarded;
    BOOL secondGuarded;

    if (gStandings->mWinnerTeamId >= 0) {
        return 0;
    }
    firstKart = GetKart(firstKartIndex);
    secondKart = GetKart(secondKartIndex);
    secondStanding = &gStandings->mKarts[secondKartIndex];
    firstStanding = &gStandings->mKarts[firstKartIndex];
    firstHitsSecond = FALSE;
    if (secondStanding->mHitSeenFromKart[firstKartIndex] == 0) {
        if ((firstKart->mDriveFlags & KART_DRIVE_KINOKO_BOOST) != 0) {
            firstHitsSecond = TRUE;
        }
    }
    result = 0;
    if (firstStanding->mHitSeenFromKart[secondKartIndex] == 0) {
        if ((secondKart->mDriveFlags & KART_DRIVE_KINOKO_BOOST) != 0) {
            result = 1;
        }
    }
    firstGuarded = TRUE;
    if ((firstKart->mEffectFlags & KART_EFFECT_BLINK_GUARD) == 0) {
        if (GetKartItemEffect(firstKartIndex) != 1) {
            firstGuarded = FALSE;
        }
    }
    secondGuarded = TRUE;
    if ((secondKart->mEffectFlags & KART_EFFECT_BLINK_GUARD) == 0) {
        if (GetKartItemEffect(secondKartIndex) != 1) {
            secondGuarded = FALSE;
        }
    }
    if (result != 0) {
        firstStanding->mHitSeenFromKart[secondKartIndex] = 1;
    }
    if (firstHitsSecond != FALSE) {
        secondStanding->mHitSeenFromKart[firstKartIndex] = 1;
    }
    if (firstGuarded == FALSE && secondGuarded == FALSE && firstHitsSecond != FALSE && result != 0) {
        if (gStandings->mKartsHitEachOtherCallback != NULL) {
            gStandings->mKartsHitEachOtherCallback(firstKartIndex, secondKartIndex);
            return 1;
        }
    } else if (firstGuarded == FALSE && result != 0) {
        result = 0;
        if (GetKartItemEffect(secondKartIndex) == 1) {
            firstStanding->mSkipNotNormalEnd = TRUE;
            if (gStandings->mKartHitByKartCallback != NULL) {
                result = gStandings->mKartHitByKartCallback(firstKartIndex, secondKartIndex);
                if ((firstKart->mEffectFlags & KART_EFFECT_BLINK_GUARD) == 0) {
                    StartKartBlink(firstKart);
                }
            }
        } else if (gStandings->mKartHitByKartCallback != NULL) {
            result = gStandings->mKartHitByKartCallback(firstKartIndex, secondKartIndex);
            if ((firstKart->mEffectFlags & KART_EFFECT_BLINK_GUARD) == 0) {
                StartKartBlink(firstKart);
            }
        }
        return result;
    } else if (secondGuarded == FALSE && firstHitsSecond != FALSE) {
        result = 0;
        if (GetKartItemEffect(firstKartIndex) == 1) {
            secondStanding->mSkipNotNormalEnd = TRUE;
            if (gStandings->mKartHitByKartCallback != NULL) {
                result = gStandings->mKartHitByKartCallback(secondKartIndex, firstKartIndex);
                if ((secondKart->mEffectFlags & KART_EFFECT_BLINK_GUARD) == 0) {
                    StartKartBlink(secondKart);
                }
            }
        } else if (gStandings->mKartHitByKartCallback != NULL) {
            result = gStandings->mKartHitByKartCallback(secondKartIndex, firstKartIndex);
            if ((secondKart->mEffectFlags & KART_EFFECT_BLINK_GUARD) == 0) {
                StartKartBlink(secondKart);
            }
        }
        return result;
    }
    return 0;
}

void SetKartHitByKartIndexFromItem(s32 kartIndex, ItemObject *itemObject) {
    u16 ownerKartIndexAndFlags;

    if (gStandings->mWinnerTeamId >= 0) {
        return;
    }
    if (GetKart(kartIndex)->mState == KART_STATE_NORMAL) {
        return;
    }
    if (itemObject->mKind != ITEM_OBJECT_KIND_KOURA_G && itemObject->mKind != ITEM_OBJECT_KIND_KOURA_R &&
        itemObject->mKind != ITEM_OBJECT_KIND_BOMB) {
        return;
    }
    ownerKartIndexAndFlags = itemObject->mOwnerKartIndexAndFlags;
    if ((ownerKartIndexAndFlags & ITEM_OWNER_NO_OWNER) != 0) {
        return;
    }
    gStandings->mKarts[kartIndex].mHitByKartIndex = ownerKartIndexAndFlags & ~ITEM_OWNER_FLAGS_MASK;
}

void StandingsNop(s32 entryIndex) {}

void ClearStandingsHitSeenFromKart(s32 kartIndex) {
    s32 i;
    s32 kartCount;

    kartCount = gRaceSetup->mKartCount;
    for (i = 0; i < kartCount; i++) {
        gStandings->mKarts[i].mHitSeenFromKart[kartIndex] = 0;
    }
}

static inline u16 FindStandingsKartIndexByRankIndex(Standings *standings, s32 rankIndex) {
    s32 kartIndex;

    for (kartIndex = 0; kartIndex < 8; kartIndex++) {
        if ((u16) rankIndex == standings->mKarts[kartIndex].mRankIndex) {
            return kartIndex;
        }
    }
    return 0;
}

u16 GetBattleItemRank(s32 kartIndex) {
    s32 rank;
    s32 i;
    s32 highestCount;

    if (gRaceSetup->mMode == MODE_BATTLE) {
        if (gRaceSetup->mBattleKind == BATTLE_KIND_BALLOON) {
            rank = 3 - gStandings->mKarts[kartIndex].mBalloonOrShineCount;
            rank += 1;
        } else if (gRaceSetup->mBattleKind == BATTLE_KIND_SHINE) {
            highestCount = 1;
            for (i = 0; i < gRaceSetup->mKartCount; i++) {
                if (gStandings->mKarts[i].mBalloonOrShineCount > highestCount) {
                    highestCount = gStandings->mKarts[i].mBalloonOrShineCount;
                }
            }
            rank = (highestCount + 1 - gStandings->mKarts[kartIndex].mBalloonOrShineCount) / 2 + 1;
        } else {
            rank = kartIndex;
        }
    } else {
        rank = 3 - gStandings->mKarts[kartIndex].mBalloonOrShineCount;
        rank += 1;
    }
    if (rank < 1) {
        rank = 1;
    } else if (rank > 3) {
        rank = 3;
    }
    return rank;
}

void MoveKartTowardFirstRank(u16 kartIndex) {
    s32 rankIndex;
    s32 i;
    s32 kartCount;
    s32 count;
    KartStanding *ownStanding;
    u16 otherRankIndex;
    u16 ownRankIndex;
    KartStanding *otherStanding;

    for (rankIndex = gStandings->mKarts[kartIndex].mRankIndex - 1; rankIndex >= 0; rankIndex--) {
        otherStanding = &gStandings->mKarts[FindStandingsKartIndexByRankIndex(gStandings, rankIndex)];
        otherRankIndex = otherStanding->mRankIndex;
        ownRankIndex = gStandings->mKarts[kartIndex].mRankIndex;
        ownStanding = &gStandings->mKarts[kartIndex];
        if (ownRankIndex > otherRankIndex) {
            if (ownStanding->mBalloonOrShineCount > otherStanding->mBalloonOrShineCount ||
                (ownStanding->mEliminationStatus == KART_STANDING_IN_PLAY &&
                 otherStanding->mEliminationStatus != KART_STANDING_IN_PLAY)) {
                otherStanding->mRankIndex = ownRankIndex;
                gStandings->mKarts[kartIndex].mRankIndex = otherRankIndex;
            }
        }
    }
    kartCount = gRaceSetup->mKartCount;
    gStandings->mLowestBalloonOrShineCount = STANDINGS_LOWEST_COUNT_START;
    gStandings->mHighestBalloonOrShineCount = 0;
    for (i = 0; i < kartCount; i++) {
        count = gStandings->mKarts[i].mBalloonOrShineCount;
        gStandings->mLowestBalloonOrShineCount = (count < gStandings->mLowestBalloonOrShineCount && count >= 0)
                                                     ? count
                                                     : gStandings->mLowestBalloonOrShineCount;
        count = gStandings->mKarts[i].mBalloonOrShineCount;
        gStandings->mHighestBalloonOrShineCount =
            (count > gStandings->mHighestBalloonOrShineCount) ? count : gStandings->mHighestBalloonOrShineCount;
    }
}

void MoveKartTowardLastRank(u16 kartIndex) {
    s32 rankIndex;
    s32 i;
    s32 kartCount;
    s32 count;
    KartStanding *ownStanding;
    u16 otherRankIndex;
    u16 ownRankIndex;
    KartStanding *otherStanding;

    for (rankIndex = gStandings->mKarts[kartIndex].mRankIndex + 1; rankIndex < 8; rankIndex++) {
        otherStanding = &gStandings->mKarts[FindStandingsKartIndexByRankIndex(gStandings, rankIndex)];
        otherRankIndex = otherStanding->mRankIndex;
        ownRankIndex = gStandings->mKarts[kartIndex].mRankIndex;
        ownStanding = &gStandings->mKarts[kartIndex];
        if (ownRankIndex < otherRankIndex) {
            if (ownStanding->mBalloonOrShineCount < otherStanding->mBalloonOrShineCount ||
                (ownStanding->mEliminationStatus != KART_STANDING_IN_PLAY &&
                 otherStanding->mEliminationStatus == KART_STANDING_IN_PLAY)) {
                otherStanding->mRankIndex = ownRankIndex;
                gStandings->mKarts[kartIndex].mRankIndex = otherRankIndex;
            }
        }
    }
    kartCount = gRaceSetup->mKartCount;
    gStandings->mLowestBalloonOrShineCount = STANDINGS_LOWEST_COUNT_START;
    gStandings->mHighestBalloonOrShineCount = 0;
    for (i = 0; i < kartCount; i++) {
        count = gStandings->mKarts[i].mBalloonOrShineCount;
        gStandings->mLowestBalloonOrShineCount = (count < gStandings->mLowestBalloonOrShineCount && count >= 0)
                                                     ? count
                                                     : gStandings->mLowestBalloonOrShineCount;
        count = gStandings->mKarts[i].mBalloonOrShineCount;
        gStandings->mHighestBalloonOrShineCount =
            (count > gStandings->mHighestBalloonOrShineCount) ? count : gStandings->mHighestBalloonOrShineCount;
    }
}

// Takes one kart out of play: calls the kart-eliminated callback and sets its status to KART_STANDING_JUST_ELIMINATED;
// in MODE_BATTLE it also sets mBalloonOrShineCount to -1 and mBalloonsLeftToMake to 0. For a kart below mKartCount it
// then moves the kart toward the last rank, and calls StartBattleKartRemoval in MODE_BATTLE or sets
// KART_DRIVE_SLOWING_STOP and KART_ENTRY_ENDED in MODE_MISSION_RUN.
void EliminateKart(u16 kartIndex) {
    Kart *kart;

    if (gStandings->mKartEliminatedCallback != NULL) {
        gStandings->mKartEliminatedCallback(kartIndex);
    }
    gStandings->mKarts[kartIndex].mEliminationStatus = KART_STANDING_JUST_ELIMINATED;
    if (gRaceSetup->mMode == MODE_BATTLE) {
        gStandings->mKarts[kartIndex].mBalloonOrShineCount = -1;
        gStandings->mKarts[kartIndex].mBalloonsLeftToMake = 0;
    }
    if ((u32) kartIndex >= gRaceSetup->mKartCount) {
        return;
    }
    MoveKartTowardLastRank(kartIndex);
    if (gRaceSetup->mMode == MODE_BATTLE) {
        StartBattleKartRemoval(GetKart(kartIndex));
    } else if (gRaceSetup->mMode == MODE_MISSION_RUN) {
        kart = GetKart(kartIndex);
        kart->mDriveFlags |= KART_DRIVE_SLOWING_STOP;
        kart->mEntryFlags |= KART_ENTRY_ENDED;
    }
}

void SetWinnerIfOneTeamLeft(void) {
    s32 kartCount;
    s32 teamId;
    s32 kartIndex;
    s32 standingIndex;
    s32 entryIndex;
    s32 scanIndex;
    u16 firstRankKartIndex;
    Standings *standings;
    KartStanding *kartStanding;
    Kart *kart;

    kartCount = gRaceSetup->mKartCount;
    standings = gStandings;
    for (scanIndex = 0; scanIndex < 8; scanIndex++) {
        if (standings->mKarts[scanIndex].mRankIndex == 0) {
            firstRankKartIndex = scanIndex;
            goto found;
        }
    }
    firstRankKartIndex = 0;
found:
    teamId = standings->mKarts[firstRankKartIndex].mTeamId;
    kartStanding = standings->mKarts;
    for (standingIndex = 0; standingIndex < 8; standingIndex++, kartStanding++) {
        if (kartStanding->mEliminationStatus == KART_STANDING_IN_PLAY) {
            if (teamId != kartStanding->mTeamId) {
                return;
            }
        }
    }
    for (kartIndex = 0; kartIndex < kartCount; kartIndex++) {
        kart = GetKart((u16) kartIndex);
        kart->mDriveFlags |= KART_DRIVE_SLOWING_STOP;
        kart->mEntryFlags |= KART_ENTRY_ENDED;
    }
    gStandings->mWinnerTeamId = teamId;
    if (gRaceSetup->mMode == MODE_BATTLE) {
        if (gRaceSetup->mBattleKind == BATTLE_KIND_SHINE) {
            NNS_SndArcPlayerStartSeqArc(&gSharedSeqHandle, 0, 0x4a);
        }
        gStandings->mEndTimer = STANDINGS_END_FRAMES;
    } else if (gRaceSetup->mMode == MODE_MISSION_RUN) {
        entryIndex = gRaceSetup->mEntryIndex;
        if (gStandings->mWinnerTeamId == entryIndex) {
            FinishMissionRunKartAtGoal(entryIndex);
        } else {
            FinishRaceProgressKartMissionFailed(entryIndex);
        }
        gStandings->mEndTimer = 0;
    }
}

void CallKartHitCallbackForSelf(u16 kartIndex) {
    KartStanding *kartStanding;

    kartStanding = &gStandings->mKarts[kartIndex];
    kartStanding->mObjectsSkipEndPending = KART_STANDING_HIT_END_NONE;
    kartStanding->mNotNormalEndPending = KART_STANDING_HIT_END_NONE;
    kartStanding->mHitByKartIndex = kartIndex;
    gStandings->mKartHitCallback(kartIndex, kartIndex);
}

void ClearStandingEliminationStatus(int kartIndex) {
    gStandings->mKarts[kartIndex].mEliminationStatus = KART_STANDING_IN_PLAY;
}

static inline u16 FindKartIndexByRankIndex(s32 rankIndex) {
    s32 kartIndex;

    for (kartIndex = 0; kartIndex < 8; kartIndex++) {
        if ((u16) rankIndex == gStandings->mKarts[kartIndex].mRankIndex) {
            return kartIndex;
        }
    }
    return 0;
}

void EliminateKartAndCheckWinner(u16 kartIndex) {
    if (gStandings->mWinnerTeamId >= 0) {
        return;
    }
    if (gStandings->mKarts[kartIndex].mEliminationStatus != KART_STANDING_IN_PLAY) {
        return;
    }
    EliminateKart(kartIndex);
    SetWinnerIfOneTeamLeft();
}

// Steps to the next time limit, eliminates the karts with the lowest shine count (none when all counts are equal) and
// returns the new limit in seconds; 0 when a winner is decided.
u16 AdvanceShineBattleTimeLimit(void) {
    NNSSndSeqPlayer **seqPlayerHandle;
    s32 timeLimitIndex;
    u16 kartIndex;
    s32 rankIndex;
    s32 targetCount;
    s32 kartCount;
    s32 lowestCount;

    if (gStandings->mWinnerTeamId >= 0) {
        return 0;
    }
    timeLimitIndex = gStandings->mTimeLimitIndex + 1;
    if (timeLimitIndex >= 3) {
        timeLimitIndex = 3;
    }
    gStandings->mTimeLimitIndex = timeLimitIndex;
    gStandings->mTimeLimitSeconds = gShineBattleTimeLimits[gStandings->mTimeLimitIndex];
    lowestCount = gStandings->mLowestBalloonOrShineCount;
    if (lowestCount != gStandings->mHighestBalloonOrShineCount) {
        kartCount = gRaceSetup->mKartCount;
        for (targetCount = 0; targetCount <= lowestCount; targetCount++) {
            for (rankIndex = kartCount - 1; rankIndex >= 0; rankIndex--) {
                kartIndex = FindKartIndexByRankIndex(rankIndex);
                if (targetCount == gStandings->mKarts[kartIndex].mBalloonOrShineCount) {
                    EliminateKart(kartIndex);
                }
            }
            SetWinnerIfOneTeamLeft();
            if (gStandings->mWinnerTeamId >= 0) {
                return 0;
            }
        }
    }
    if (gRaceSoundKind & 1) {
        seqPlayerHandle = TakeSoundHandleEntry(GetSoundHandlePool(0));
        if (gSoundModeHolder.mSeqStartEnabled != 0) {
            if (seqPlayerHandle[0] != NULL) {
                NNS_SndPlayerStopSeq(seqPlayerHandle, 0);
            }
            if (seqPlayerHandle[0] != NULL) {
                NNS_SndPlayerStopSeq(seqPlayerHandle, 0);
            }
            NNS_SndArcPlayerStartSeqArc(seqPlayerHandle, 0, 0x4b);
        }
    }
    return gStandings->mTimeLimitSeconds;
}

void EliminateKartsUntilWinnerDecided(void) {
    s32 kartCount;
    s32 rankIndex;
    u16 kartIndex;
    s32 randomKartIndex;
    u16 randomLimit;
    RandomState64 *randomState;

    if (gStandings->mWinnerTeamId >= 0) {
        return;
    }
    if (gRaceSetup->mMode == MODE_BATTLE) {
        kartCount = gRaceSetup->mKartCount;
        if (gRaceSetup->mBattleKind == BATTLE_KIND_BALLOON) {
            if (gStandings->mWinnerTeamId >= 0) {
                return;
            }
            randomLimit = kartCount;
            do {
                randomState = &gRaceProgress->mRandom;
                if ((u16) kartCount == 0) {
                    randomKartIndex = 0;
                } else {
                    RANDOM_ADVANCE(randomState);
                    if (randomLimit == 0) {
                        randomKartIndex = (u32) RANDOM_HIGH32(randomState);
                    } else {
                        randomKartIndex = (u32) RANDOM_BELOW_U64(randomState, (u64) randomLimit);
                    }
                }
                kartIndex = randomKartIndex;
                if (gStandings->mKarts[kartIndex].mEliminationStatus == KART_STANDING_IN_PLAY) {
                    EliminateKartAndCheckWinner(kartIndex);
                    gStandings->mKarts[kartIndex].mEliminationStatus = KART_STANDING_ELIMINATED;
                }
            } while (gStandings->mWinnerTeamId < 0);
        } else if (gRaceSetup->mBattleKind == BATTLE_KIND_SHINE) {
            for (rankIndex = kartCount - 1; rankIndex >= 0; rankIndex--) {
                if (gStandings->mWinnerTeamId < 0) {
                    kartIndex = FindKartIndexByRankIndex(rankIndex);
                    if (gStandings->mKarts[kartIndex].mEliminationStatus == KART_STANDING_IN_PLAY) {
                        EliminateKartAndCheckWinner(kartIndex);
                        gStandings->mKarts[kartIndex].mEliminationStatus = KART_STANDING_ELIMINATED;
                    }
                }
            }
        }
    } else if (gRaceSetup->mMode == MODE_MISSION_RUN) {
        for (rankIndex = 7; rankIndex >= 0; rankIndex--) {
            kartIndex = FindKartIndexByRankIndex(rankIndex);
            if (kartIndex != gRaceSetup->mEntryIndex && gStandings->mWinnerTeamId < 0) {
                EliminateKartAndCheckWinner(kartIndex);
            }
        }
    }
}

u32 IsWinnerDecidedAndEndReached(void) {
    u32 result = 0u;
    if (gStandings->mWinnerTeamId < 0) {
        return result;
    }
    if (gStandings->mEndTimer < 0) {
        result = 1u;
    }
    return result;
}

// TRUE when mWinnerTeamId is not negative.
BOOL IsWinnerDecided(void) {
    if (gStandings->mWinnerTeamId >= 0) {
        return TRUE;
    }
    return FALSE;
}

u16 GetKartStandingRankIndex(int kartIndex) {
    return gStandings->mKarts[kartIndex].mRankIndex;
}

u32 GetShineCount(void) {
    return (gStandings->mShineCount);
}

// Adds its argument to mShineCount (+1 when a shine is placed, -1 when one is finished).
void AddShineCount(short amount) {
    Standings *standings;
    standings = gStandings;
    standings->mShineCount = standings->mShineCount + amount;
}

u16 GetTotalBalloonOrShineCount(void) {
    s32 kartIndex;
    s32 total;
    s32 kartCount;
    s32 count;

    total = 0;
    kartCount = gRaceSetup->mKartCount;
    for (kartIndex = 0; kartIndex < kartCount; kartIndex++) {
        count = GetKartStanding(kartIndex)->mBalloonOrShineCount;
        if (count <= 0) {
            count = 0;
        }
        total += (u16) count;
    }
    return total;
}

u16 GetHighestBalloonOrShineCount(void) {
    return gStandings->mHighestBalloonOrShineCount;
}

// Returns the kart's count, 0 when it is negative.
u16 GetBalloonOrShineCount(u16 kartIndex) {
    s32 count;

    count = gStandings->mKarts[kartIndex].mBalloonOrShineCount;
    if (count <= 0) {
        count = 0;
    }
    return count;
}

void AddBalloonOrShineCountAndMoveRank(u16 kartIndex, s32 amount) {
    gStandings->mKarts[kartIndex].mBalloonOrShineCount += amount;
    if (amount > 0) {
        MoveKartTowardFirstRank(kartIndex);
    } else if (amount < 0) {
        MoveKartTowardLastRank(kartIndex);
    }
}

u16 GetBalloonsLeftToMake(u16 kartIndex) {
    return gStandings->mKarts[kartIndex].mBalloonsLeftToMake;
}

void AddBalloonsLeftToMake(u16 kartIndex, s32 amount) {
    gStandings->mKarts[kartIndex].mBalloonsLeftToMake += amount;
}

// TRUE when the kart's mEliminationStatus is not KART_STANDING_IN_PLAY.
BOOL IsKartEliminated(int kartIndex) {
    if (gStandings->mKarts[kartIndex].mEliminationStatus != KART_STANDING_IN_PLAY) {
        return TRUE;
    }
    return FALSE;
}

// TRUE when the kart has the lowest balloon or shine count (ties count) and not every kart has it.
BOOL IsKartLastByBalloonOrShineCount(u16 kartIndex) {
    Standings *standings;
    BOOL result;
    s32 count;

    standings = gStandings;
    result = FALSE;
    count = standings->mKarts[kartIndex].mBalloonOrShineCount;
    if (standings->mLowestBalloonOrShineCount == count) {
        if (standings->mHighestBalloonOrShineCount != count) {
            result = TRUE;
        }
    }
    return result;
}

BOOL IsKartOnWinningTeamAtEnd(s32 kartIndex) {
    KartStanding *kartStanding;
    BOOL result;

    kartStanding = &gStandings->mKarts[kartIndex];
    result = FALSE;
    if (gStandings->mWinnerTeamId == kartStanding->mTeamId) {
        if (gStandings->mEndTimer < 0) {
            result = TRUE;
        }
    }
    return result;
}

// Returns the address of the position Standings keeps for the kart (mKarts[kartIndex].mPos).
Vec3 *GetKartStandingPos(int kartIndex) {
    return &gStandings->mKarts[kartIndex].mPos;
}

CourseMapPoint *MoveToRandomForwardBattlePoint(void) {
    RandomState64 *randomState;
    u16 pointStep;
    s32 pointIndex;

    randomState = &gRaceProgress->mRandom;
    RANDOM_ADVANCE(randomState);
    pointStep = (u16) RANDOM_BELOW_U64(randomState, 5) + 1;
    pointIndex = gStandings->mBattlePointIndex + pointStep;
    if (pointIndex >= gCourseMap->mBattlePointCount) {
        pointIndex = 0;
    }
    gStandings->mBattlePointIndex = pointIndex;
    return &gCourseMap->mBattlePoints[gStandings->mBattlePointIndex];
}

// Allocates the Standings object and sets every entry (rank = own index, team id, elimination status, counts; the real
// karts first, then the unused slots, which start eliminated) and the winner to -1. Called from InitRace in MODE_BATTLE
// and MODE_MISSION_RUN.
void InitStandings(void) {
    s32 kartIndex;
    KartStanding *kartStanding;

    gStandings = HeapAlloc(GetHeap(GetCurrentHeapCall()), sizeof(Standings));
    for (kartIndex = 0; kartIndex < 8; kartIndex++) {
        kartStanding = &gStandings->mKarts[kartIndex];
        kartStanding->mObjectsSkipEndPending = KART_STANDING_HIT_END_NONE;
        kartStanding->mNotNormalEndPending = KART_STANDING_HIT_END_NONE;
        kartStanding->mHitByKartIndex = kartIndex;
        kartStanding->mRankIndex = kartIndex;
        if (kartIndex < gRaceSetup->mKartCount) {
            switch (GetCurrentEntry(kartIndex)->mPlayer.mTeamIndex) {
                case 0:
                    kartStanding->mTeamId = STANDINGS_TEAM_ID_FIRST_TEAM;
                    break;
                case 1:
                    kartStanding->mTeamId = STANDINGS_TEAM_ID_SECOND_TEAM;
                    break;
                default:
                    kartStanding->mTeamId = kartIndex;
                    break;
            }
            kartStanding->mEliminationStatus = KART_STANDING_IN_PLAY;
            kartStanding->mBalloonOrShineCount = 0;
            kartStanding->mBalloonsLeftToMake = 0;
        } else {
            kartStanding->mEliminationStatus = KART_STANDING_ELIMINATED;
            kartStanding->mBalloonOrShineCount = -1;
            kartStanding->mBalloonsLeftToMake = 0;
            kartStanding->mTeamId = gRaceSetup->mKartCount;
        }
    }
    gStandings->mWinnerTeamId = -1;
}

void FinishStandings(void) {
    gStandings->mEndTimer = -1;
    if (gStandings->mEndCallback != NULL) {
        gStandings->mEndCallback();
    }
}

void UpdateStandings(void) {
    Kart *kart;
    BOOL objectsSkipSet;
    BOOL notNormalOrFlagged;
    s32 nextMicInflateTimer;
    u32 kartFlags;
    s32 kartIndex;
    s32 kartCount;
    KartStanding *kartStanding = gStandings->mKarts;

    kartCount = gRaceSetup->mKartCount;
    if (gStandings->mWinnerTeamId >= 0) {
        if (gStandings->mEndTimer > 0) {
            gStandings->mEndTimer = gStandings->mEndTimer - 1;
            if (gStandings->mEndTimer <= 0) {
                gStandings->mEndTimer = -1;
                if (gStandings->mEndCallback != NULL) {
                    gStandings->mEndCallback();
                }
            }
        }
        for (kartIndex = 0; kartIndex < kartCount; kartIndex++) {
            if (gStandings->mKarts[kartIndex].mEliminationStatus == KART_STANDING_JUST_ELIMINATED) {
                if (kartIndex != gRaceSetup->mEntryIndex) {
                    QueueKartOwnSoundIndex(GetKart((u16) kartIndex));
                }
                gStandings->mKarts[kartIndex].mEliminationStatus = KART_STANDING_ELIMINATED;
            }
        }
        return;
    }
    for (kartIndex = kartCount - 1; kartIndex >= 0; kartIndex--) {
        kartStanding = &gStandings->mKarts[kartIndex];
        if (kartStanding->mEliminationStatus == KART_STANDING_JUST_ELIMINATED) {
            QueueKartOwnSoundIndex(GetKart((u16) kartIndex));
            gStandings->mKarts[kartIndex].mEliminationStatus = KART_STANDING_ELIMINATED;
        } else if (gStandings->mWinnerTeamId < 0 && kartStanding->mBalloonOrShineCount > 0) {
            kart = GetKart((u16) kartIndex);
            kartStanding = &gStandings->mKarts[kartIndex];
            nextMicInflateTimer = kartStanding->mMicInflateTimer - 1;
            if (nextMicInflateTimer <= 0) {
                nextMicInflateTimer = 0;
            }
            kartStanding->mMicInflateTimer = nextMicInflateTimer;
            gStandings->mKarts[kartIndex].mSelectKeyInflate = -(gStandings->mKarts[kartIndex].mSelectKeyInflate <= 0);
            if (IsKartNotNormalOrFlagged(kart) != FALSE ||
                (u16) (gInputSlots[kart->mEntryIndex].mBits & (PAD_KEY_A | PAD_KEY_B)) != 0) {
                gStandings->mKarts[kartIndex].mSelectKeyInflate = -1;
                gStandings->mKarts[kartIndex].mMicInflateTimer = STANDINGS_MIC_INFLATE_STOPPED;
            } else if (IsRaceStarted() == 1) {
                if ((u16) (GetInputSlot(kart->mEntryIndex)->mBits & PAD_KEY_SELECT) != 0) {
                    gStandings->mKarts[kartIndex].mSelectKeyInflate = 1;
                } else if (gInputSlots[kart->mEntryIndex].mPair.mMicOverThreshold[0] != 0) {
                    gStandings->mKarts[kartIndex].mMicInflateTimer = STANDINGS_MIC_INFLATE_FRAMES;
                }
            }
            if (gStandings->mKartHitCallback != NULL) {
                notNormalOrFlagged = TRUE;
                kartFlags = kart->mDriveFlags;
                objectsSkipSet = (kartFlags & KART_DRIVE_OBJECTS_SKIP) != 0;
                if (kart->mState == KART_STATE_NORMAL && (kartFlags & KART_DRIVE_SCALE_TABLE_EFFECT) == 0) {
                    notNormalOrFlagged = FALSE;
                }
                if (kartStanding->mObjectsSkipSeen == FALSE && objectsSkipSet != FALSE &&
                    (kart->mEffectFlags & KART_EFFECT_BLINK_GUARD) == 0) {
                    kartStanding->mObjectsSkipSeen = TRUE;
                    kartStanding->mNotNormalOrFlaggedSeen = FALSE;
                    kartStanding->mNotNormalEndPending = KART_STANDING_HIT_END_NONE;
                    kartStanding->mHitByKartIndex = kartIndex;
                    kartStanding->mSkipNotNormalEnd = FALSE;
                    if (kartStanding->mBalloonOrShineCount <= 1) {
                        if ((gRaceSetup->mMode == MODE_BATTLE && gRaceSetup->mBattleKind == BATTLE_KIND_BALLOON) ||
                            gRaceSetup->mMode == MODE_MISSION_RUN) {
                            kart->mEntryFlags |= KART_ENTRY_OUT_OF_ROUND;
                            kart->mDriveFlags &= ~KART_DRIVE_RESPAWN_LANDING;
                        }
                    }
                } else if (kartStanding->mObjectsSkipSeen == TRUE && (kart->mMotionFlags & KART_MOTION_LANDED) != 0) {
                    kartStanding->mObjectsSkipSeen = FALSE;
                    kartStanding->mObjectsSkipEndPending = 0;
                    if ((kart->mEffectFlags & KART_EFFECT_BLINK_GUARD) == 0) {
                        StartKartBlink(kart);
                    }
                }
                if (kartStanding->mObjectsSkipEndPending == 0) {
                    kartStanding->mObjectsSkipEndPending = KART_STANDING_HIT_END_NONE;
                    gStandings->mKartHitCallback(kartIndex, 8);
                    kartStanding->mHitByKartIndex = kartIndex;
                } else if (kartStanding->mObjectsSkipEndPending >= 0) {
                    kartStanding->mObjectsSkipEndPending = kartStanding->mObjectsSkipEndPending + 1;
                }
                if (kartStanding->mNotNormalOrFlaggedSeen == FALSE && notNormalOrFlagged != FALSE &&
                    (kart->mEffectFlags & KART_EFFECT_BLINK_GUARD) == 0) {
                    kartStanding->mNotNormalOrFlaggedSeen = TRUE;
                    if (kartStanding->mBalloonOrShineCount <= 1) {
                        if ((gRaceSetup->mMode == MODE_BATTLE && gRaceSetup->mBattleKind == BATTLE_KIND_BALLOON) ||
                            gRaceSetup->mMode == MODE_MISSION_RUN) {
                            kart->mEntryFlags |= KART_ENTRY_OUT_OF_ROUND;
                        }
                    }
                } else if (kartStanding->mNotNormalOrFlaggedSeen == TRUE && notNormalOrFlagged == FALSE &&
                           (kart->mDriveFlags & KART_DRIVE_NOT_NORMAL) == 0) {
                    kartStanding->mNotNormalOrFlaggedSeen = FALSE;
                    if (kartStanding->mSkipNotNormalEnd == FALSE) {
                        kartStanding->mNotNormalEndPending = 0;
                        if ((kart->mEffectFlags & KART_EFFECT_BLINK_GUARD) == 0) {
                            StartKartBlink(kart);
                        }
                    } else {
                        kartStanding->mSkipNotNormalEnd = FALSE;
                    }
                }
                if (kartStanding->mNotNormalEndPending == 0) {
                    kartStanding->mNotNormalEndPending = KART_STANDING_HIT_END_NONE;
                    gStandings->mKartHitCallback(kartIndex, kartStanding->mHitByKartIndex);
                    kartStanding->mHitByKartIndex = kartIndex;
                } else if (kartStanding->mNotNormalEndPending >= 0) {
                    kartStanding->mNotNormalEndPending = kartStanding->mNotNormalEndPending + 1;
                }
            }
            kartStanding->mPos = kart->mPos;
        }
    }
}

void InitDistanceSound(DistanceSound *mapObject) {
    s32 courseId;

    courseId = gRaceSetup->mCourseId;
    if (courseId == COURSE_ID_MANSION) {
        mapObject->mSoundId = DISTANCE_SOUND_ID_MANSION;
    } else if (courseId == COURSE_ID_BEACH) {
        mapObject->mSoundId = DISTANCE_SOUND_ID_BEACH;
        mapObject->mSecondSoundId = DISTANCE_SOUND_ID_BEACH_SECOND;
    } else {
        mapObject->mSoundId = DISTANCE_SOUND_ID_DEFAULT;
    }
}

void InitDistanceSoundObjects(MapObjectList *mapObjectList) {
    s32 objectIndex;
    DistanceSound *mapObject;
    RandomState64 *randomState;

    if (mapObjectList == NULL) {
        return;
    }
    for (objectIndex = 0;
         objectIndex < mapObjectList->mMapObjectCount && (mapObject = mapObjectList->mMapObjects[objectIndex]) != NULL;
         objectIndex++) {
        if (gRaceSetup->mCourseId == COURSE_ID_MANSION) {
            mapObject->mRadius = DISTANCE_SOUND_RADIUS_WIDE;
            mapObject->mCenterX = mapObject->mMapObject.mPos.x + 0x73a000;
            mapObject->mCenterY = mapObject->mMapObject.mPos.y;
            mapObject->mCenterZ = mapObject->mMapObject.mPos.z - 0x1400000;
            mapObject->mDistanceLevelInverted = TRUE;
        } else if (gRaceSetup->mCourseId == COURSE_ID_BEACH) {
            mapObject->mRadius = DISTANCE_SOUND_RADIUS_BEACH;
            mapObject->mCenterX = mapObject->mMapObject.mPos.x + 0x28a000;
            mapObject->mCenterY = mapObject->mMapObject.mPos.y;
            mapObject->mCenterZ = mapObject->mMapObject.mPos.z - 0x32000;
            mapObject->mDistanceLevelInverted = FALSE;
        } else {
            mapObject->mRadius = DISTANCE_SOUND_RADIUS_WIDE;
            mapObject->mCenterX = mapObject->mMapObject.mPos.x;
            mapObject->mCenterY = mapObject->mMapObject.mPos.y;
            mapObject->mCenterZ = mapObject->mMapObject.mPos.z;
            mapObject->mDistanceLevelInverted = FALSE;
        }
        randomState = &gRaceProgress->mLocalRandom;
        RANDOM_ADVANCE(randomState);
        mapObject->mSoundTimer = (u16) RANDOM_BELOW_U64(randomState, 0x3c) + 0x258;
        mapObject->mDistanceVolumeFixed12 = TO_FIXED12(SOUND_VOLUME_MAX);
        randomState = &gRaceProgress->mLocalRandom;
        RANDOM_ADVANCE(randomState);
        mapObject->mDistanceLevelTimer = (u16) RANDOM_BELOW_U64(randomState, 0xf);
    }
}

void UpdateDistanceSound(void *mapObjectList, DistanceSound *mapObject) {
    Kart *kart;
    NNSSndSeqPlayer **sndHandleSlot;
    RandomState64 *randomState;
    SoundStartParams slot8Request;
    SoundStartParams slot9Request;
    s32 value;
    s32 halfRadius;
    s32 radius;
    s32 deltaZ;
    s32 deltaX;
    s64 distanceSquared;

    if (mapObject->mDistanceLevelTimer-- <= 0) {
        mapObject->mDistanceLevelTimer = DISTANCE_SOUND_LEVEL_FRAMES;
        radius = mapObject->mRadius;
        halfRadius = radius / 2;
        kart = GetKart((u16) gRaceSetup->mEntryIndex);
        deltaX = kart->mPos.x - mapObject->mCenterX;
        deltaZ = kart->mPos.z - mapObject->mCenterZ;
        distanceSquared = SQUARE_SUM2(deltaX, deltaZ);
        if (distanceSquared < (s64) halfRadius * halfRadius) {
            value = 2;
        } else if (distanceSquared < (s64) TO_FIXED12(radius) * TO_FIXED12(radius)) {
            value = 1;
        } else {
            value = 0;
        }
        mapObject->mDistanceLevel = value;
        if (mapObject->mDistanceLevelInverted != FALSE) {
            mapObject->mDistanceLevel = mapObject->mDistanceLevel == 0;
        }
    }
    if (mapObject->mDistanceLevel > 1) {
        mapObject->mDistanceVolumeFixed12 = TO_FIXED12(SOUND_VOLUME_MAX) + 1;
    } else if (mapObject->mDistanceLevel > 0) {
        mapObject->mDistanceVolumeFixed12 = mapObject->mDistanceVolumeFixed12 + 0x4000;
        if (mapObject->mDistanceVolumeFixed12 > TO_FIXED12(SOUND_VOLUME_MAX)) {
            mapObject->mDistanceVolumeFixed12 = TO_FIXED12(SOUND_VOLUME_MAX);
        }
    } else {
        mapObject->mDistanceVolumeFixed12 = mapObject->mDistanceVolumeFixed12 - 0x4000;
        if (mapObject->mDistanceVolumeFixed12 < 0) {
            mapObject->mDistanceVolumeFixed12 = 0;
        }
    }
    if (mapObject->mSoundId != 0) {
        if (mapObject->mDistanceLevel != 0) {
            if (*GetSndHandleSlot(8) != NULL) {
                kart = GetKart((u16) gRaceSetup->mEntryIndex);
                mapObject->mSoundVolumeFixed12 =
                    mapObject->mSoundVolumeFixed12 - MUL_FIXED12_NO_ROUND(kart->mVelocityLengthRatio, TO_FIXED12(1));
                if (mapObject->mSoundVolumeFixed12 < DISTANCE_SOUND_SOUND_VOLUME_MIN) {
                    mapObject->mSoundVolumeFixed12 = DISTANCE_SOUND_SOUND_VOLUME_MIN;
                }
            } else if (mapObject->mSoundTimer-- <= 0) {
                sndHandleSlot = GetSndHandleSlot(8);
                slot8Request.mSoundId = mapObject->mSoundId;
                slot8Request.mPositionSource = NULL;
                slot8Request.mFalloffIndex = SOUND_FALLOFF_LONG_RANGE;
                slot8Request.mDistanceSquared = GetHorizontalCameraDistanceSquared(NULL);
                StartSndHandleSound(&slot8Request, sndHandleSlot);
                randomState = &gRaceProgress->mLocalRandom;
                RANDOM_ADVANCE(randomState);
                mapObject->mSoundTimer = (u16) RANDOM_BELOW_U64(randomState, 0x3c) + 0x78;
                mapObject->mSoundVolumeFixed12 = TO_FIXED12(SOUND_VOLUME_MAX);
            }
        } else if (mapObject->mSoundTimer > 0) {
            mapObject->mSoundTimer = mapObject->mSoundTimer - 1;
        }
        if (*GetSndHandleSlot(8) != NULL) {
            value = mapObject->mDistanceVolumeFixed12 < mapObject->mSoundVolumeFixed12
                        ? mapObject->mDistanceVolumeFixed12
                        : mapObject->mSoundVolumeFixed12;
            SetSndHandleTrackVolume(GetSndHandleSlot(8), FROM_FIXED12(value));
        }
    }
    if (mapObject->mSecondSoundId == 0) {
        return;
    }
    if (mapObject->mDistanceLevel != 0) {
        if (*GetSndHandleSlot(9) == NULL) {
            sndHandleSlot = GetSndHandleSlot(9);
            slot9Request.mSoundId = mapObject->mSecondSoundId;
            slot9Request.mPositionSource = NULL;
            slot9Request.mFalloffIndex = SOUND_FALLOFF_LONG_RANGE;
            slot9Request.mDistanceSquared = GetHorizontalCameraDistanceSquared(NULL);
            StartSndHandleSound(&slot9Request, sndHandleSlot);
        }
    }
    if (*GetSndHandleSlot(9) == NULL) {
        return;
    }
    SetSndHandleTrackVolume(GetSndHandleSlot(9), FROM_FIXED12(mapObject->mDistanceVolumeFixed12));
}

MapObjectList *CreateDistanceSoundUpdateList(void) {
    return CreateMapObjectUpdateList(InitDistanceSoundObjects, UpdateDistanceSound, NULL);
}
