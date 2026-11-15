#include "Main/Sound/race_end_seq.h"
#include "Main/Race/race_hud_sub_screen_item_box_cells.h"
#include "Main/Sound/snd_handle_slots.h"
#include "Main/Sound/scene_players_release.h"
#include "Main/Menu/menu_screens_work.h"
#include "player.h"
#include "sound_player_type.h"
#include "stream.h"
#include "sound_capture_effect.h"
#include "Main/Graphics/layout_rect_table.h"
#include "Main/Graphics/layout_entry_angle.h"
#include "Main/Graphics/layout_table_entry.h"
#include "Main/Race/race_hud_sub_screen_cells.h"
#include "sound_archive_load.h"
#include "Main/Sound/sound_seq.h"
#include "Main/Sound/sound_mode.h"
#include "Main/Race/race_setup_block.h"
#include "tp.h"
#include "Main/Sound/sound_set_load.h"
#include "Main/Sound/sound_handle_pool.h"
#include "sound_archive_load_result.h"
#include "Main/Race/race_clock.h"
#include "Main/Sound/seq_queue.h"
#include "Main/Sound/sound_system.h"
#include "Main/Race/results_battle_frame_limit.h"

s32 gRaceEndSeqCallCount;
s32 gRaceEndNextSeqPending;
s32 gRaceEndSeqStarted;
SeqRowState gSeqRowState;

void UpdateRaceEndSeq(void) {
    s32 resultKind;
    s32 callCount;
    s32 callLimit;
    u32 seqId;
    u32 *seqRow;
    if (gRaceEndSeqStarted == 0) {
        return;
    }
    if (gScenePlayers.mSeqPlayer != NULL) {
        return;
    }
    resultKind = GetRaceEndResultKind();
    callLimit = (resultKind == RACE_END_RESULT_LOST) ? RACE_END_NEXT_SEQ_CALLS_LOST : RACE_END_NEXT_SEQ_CALLS;
    callCount = gRaceEndSeqCallCount + 1;
    gRaceEndSeqCallCount = callCount;
    if (callCount <= callLimit) {
        return;
    }
    if (gRaceEndNextSeqPending == 0) {
        return;
    }
    seqRow = gSeqRowState.mSeqRow;
    seqId = 0xff;
    switch (resultKind) {
        case RACE_END_RESULT_BEST:
        case RACE_END_RESULT_WON:
            seqId = seqRow[3];
            break;
        case RACE_END_RESULT_LOST:
            seqId = seqRow[4];
            break;
    }
    StartScenePlayersSeqNo(&gScenePlayers, seqId, NULL);
    gRaceEndNextSeqPending = 0;
    gRaceEndSeqStarted = 0;
    gRaceEndSeqCallCount = 0;
}

s32 GetKartSeqArcSoundOffsetByRank(s32 kartRank) {
    s32 result;
    result = 0xb;
    if (kartRank == 1) {
        result = 9;
    } else {
        switch (gRaceSetup->mKartCount) {
            case 4:
            case 5:
                if (kartRank < 3) {
                    result = 0xa;
                }
                break;
            case 6:
            case 7:
            case 8:
                if (kartRank < 4) {
                    result = 0xa;
                }
                break;
        }
    }
    return result;
}

// Result kind 0, 1 or 2 (-1 for none) from the mode, the entry kart's rank and its finish result.
s32 GetRaceEndResultKind(void) {
    s32 resultKind;
    s32 candidateKind;
    RaceSetup *raceSetup;
    resultKind = -1;
    raceSetup = gRaceSetup;
    switch (raceSetup->mMode) {
        case MODE_GRAND_PRIX:
        case MODE_WIFI:
            switch (gSeqRowState.mFinishResult) {
                case FINISH_RESULT_WON:
                    if (GetKartRank((u16) raceSetup->mEntryIndex) - 1 == 0) {
                        candidateKind = RACE_END_RESULT_BEST;
                    } else {
                        candidateKind = RACE_END_RESULT_WON;
                    }
                    break;
                case FINISH_RESULT_NEITHER:
                case FINISH_RESULT_LOST:
                    candidateKind = RACE_END_RESULT_LOST;
                    break;
            }
            resultKind = candidateKind;
            break;
        case MODE_VS:
            if (raceSetup->mRuleKind == RULE_KIND_WIN_COUNT) {
                resultKind =
                    (gSeqRowState.mFinishResult == FINISH_RESULT_WON) ? RACE_END_RESULT_BEST : RACE_END_RESULT_LOST;
            } else {
                switch (gSeqRowState.mFinishResult) {
                    case FINISH_RESULT_WON:
                        if (GetKartRank((u16) raceSetup->mEntryIndex) - 1 == 0) {
                            candidateKind = RACE_END_RESULT_BEST;
                        } else {
                            candidateKind = RACE_END_RESULT_WON;
                        }
                        break;
                    case FINISH_RESULT_NEITHER:
                    case FINISH_RESULT_LOST:
                        candidateKind = RACE_END_RESULT_LOST;
                        break;
                }
                resultKind = candidateKind;
            }
            break;
        case MODE_MISSION_RUN:
            resultKind =
                (gSeqRowState.mFinishResult == FINISH_RESULT_WON) ? RACE_END_RESULT_BEST : RACE_END_RESULT_LOST;
            break;
        case MODE_BATTLE:
            resultKind =
                (gSeqRowState.mFinishResult == FINISH_RESULT_WON) ? RACE_END_RESULT_BEST : RACE_END_RESULT_LOST;
            break;
        case MODE_TIME_ATTACK:
            resultKind = (gSeqRowState.mFinishResult == FINISH_RESULT_WON) ? RACE_END_RESULT_WON : RACE_END_RESULT_LOST;
            if (resultKind == IsRaceNewRecordTaFinishRecordFirst()) {
                resultKind = RACE_END_RESULT_BEST;
            }
            break;
    }
    return resultKind;
}

// When the race kind is 0 or 2 and the sound mode is 2, starts the race end seq for the result kind and arms
// UpdateRaceEndSeq to start the follow-up seq.
void StartRaceEndSeq(s32 unused) {
    s32 seqId;
    s32 resultKind;
    u32 value;
    u32 *seqRow;
    seqId = -1;
    value = gRaceSetup->mRaceKind;
    if (value != RACE_KIND_REPLAY && value != RACE_KIND_NORMAL) {
        return;
    }
    if (gSoundModeHolder.mMode != SCENE_SOUND_MODE_PLAYING) {
        return;
    }
    EndRaceSounds();
    resultKind = GetRaceEndResultKind();
    seqRow = gSeqRowState.mSeqRow;
    value = 0xff;
    switch (resultKind) {
        case RACE_END_RESULT_BEST:
            value = seqRow[0];
            break;
        case RACE_END_RESULT_WON:
            value = seqRow[1];
            break;
        case RACE_END_RESULT_LOST:
            value = seqRow[2];
            break;
    }
    StartScenePlayersSeqNo(&gScenePlayers, value, NULL);
    gRaceEndSeqStarted = 1;
    gRaceEndNextSeqPending = 1;
    switch (gRaceSetup->mCourseId) {
        case COURSE_ID_STADIUM:
            switch (resultKind) {
                case RACE_END_RESULT_BEST:
                case RACE_END_RESULT_WON:
                    seqId = 0x1bd;
                    break;
                default:
                    seqId = 0x1be;
                    break;
            }
            break;
        case COURSE_ID_CROSS:
            switch (resultKind) {
                case RACE_END_RESULT_BEST:
                case RACE_END_RESULT_WON:
                    seqId = 0x105;
                    break;
                default:
                    seqId = 0x106;
                    break;
            }
            break;
        case COURSE_ID_MARIO:
            switch (resultKind) {
                case RACE_END_RESULT_BEST:
                case RACE_END_RESULT_WON:
                    seqId = 0x19d;
                    break;
                default:
                    seqId = 0x19e;
                    break;
            }
            break;
    }
    if (seqId <= -1) {
        return;
    }
    StopSndHandleSlots7To11();
    NNS_SndArcPlayerStartSeqArc(&gSharedSeqHandle, 0, (u16) seqId);
}

s32 GetLastLapCourseSoundId(void) {
    s32 seqId;
    s32 resultKind;
    resultKind = GetRaceEndResultKind();
    seqId = -1;
    switch (gRaceSetup->mCourseId) {
        case COURSE_ID_CROSS:
            switch (resultKind) {
                case RACE_END_RESULT_BEST:
                case RACE_END_RESULT_WON:
                    seqId = 0x104;
                    break;
                default:
                    seqId = 0x107;
                    break;
            }
            break;
        case COURSE_ID_MARIO:
            switch (resultKind) {
                case RACE_END_RESULT_BEST:
                case RACE_END_RESULT_WON:
                    seqId = 0x19c;
                    break;
                default:
                    seqId = 0x19f;
                    break;
            }
            break;
    }
    return seqId;
}

// Stops the slot for 0xffff, otherwise restarts it with seqId unless that seq already plays on it.
static inline void SetHandleSlotSeq(NNSSndSeqPlayer **handleSlot, u32 seqId) {
    NNSSndSeqPlayer *currentPlayer;
    u32 sameSeq;
    if (seqId != 0xffff) {
        currentPlayer = *handleSlot;
        if (currentPlayer != NULL && currentPlayer->mSeqArcIndex == seqId && currentPlayer->mSeqNo == 0) {
            sameSeq = 1;
        } else {
            sameSeq = 0;
        }
        if (sameSeq == 0) {
            NNS_SndPlayerStopSeq(handleSlot, 0);
            if (*handleSlot != NULL) {
                NNS_SndPlayerStopSeq(handleSlot, 0);
            }
            NNS_SndArcPlayerStartSeqArc(handleSlot, 0, seqId);
        }
    } else if (*handleSlot != NULL) {
        NNS_SndPlayerStopSeq(handleSlot, 0);
    }
}

void SetKartModelMenuInputSeqs(s32 firstSeqChoice, s32 secondSeqEnabled) {
    NNSSndSeqPlayer **handleSlot;
    u32 firstSeqId;
    u32 secondSeqId;
    handleSlot = GetSndHandleSlot(1);
    if (firstSeqChoice == 0) {
        firstSeqId = 0x1ff;
    } else if (firstSeqChoice == 1) {
        firstSeqId = 0x200;
    } else {
        firstSeqId = 0xffff;
    }
    SetHandleSlotSeq(handleSlot, firstSeqId);
    handleSlot = GetSndHandleSlot(2);
    secondSeqId = (secondSeqEnabled != 0) ? 0x201 : 0xffff;
    if (firstSeqId != 0xffff) {
        secondSeqId = 0xffff;
    }
    SetHandleSlotSeq(handleSlot, secondSeqId);
}

void ResetEmblemSoundCounters(void) {
    gEmblemSoundCallsSincePlay = 0;
    gEmblemSoundPlayCount = 0;
    gEmblemSoundPitchCounter = 0;
    gEmblemSoundValue = 7;
}

void StartEmblemSound(s32 soundValue) {
    s32 seqId;
    s32 pitch;
    u8 pitchCounter;
    u32 callsSincePlay;
    NNSSndSeqPlayer **handleSlot;
    if (soundValue <= 2) {
        seqId = 0x1f7;
    } else if (soundValue <= 5) {
        seqId = 0x1f8;
    } else {
        seqId = -1;
    }
    pitchCounter = gEmblemSoundPitchCounter + 1;
    callsSincePlay = gEmblemSoundCallsSincePlay + 1;
    gEmblemSoundPitchCounter = pitchCounter;
    gEmblemSoundCallsSincePlay = callsSincePlay;
    if (seqId == -1) {
        return;
    }
    if (callsSincePlay < 2) {
        return;
    }
    handleSlot = GetSndHandleSlot((gEmblemSoundPlayCount & 1) ? 2 : 3);
    if (gEmblemSoundCallsSincePlay >= 0x14) {
        gEmblemSoundPitchCounter = 0;
    }
    if (*handleSlot != NULL) {
        NNS_SndPlayerStopSeq(handleSlot, 0);
    }
    NNS_SndArcPlayerStartSeqArc(handleSlot, 0, (u16) seqId);
    gEmblemSoundPlayCount = gEmblemSoundPlayCount + 1;
    if (handleSlot != NULL) {
        switch (gEmblemSoundPitchCounter % 3) {
            case 0:
                pitch = 0;
                break;
            case 1:
                pitch = (soundValue <= 2) ? 0x40 : -0x40;
                break;
            case 2:
                pitch = (soundValue <= 2) ? 0x80 : -0x80;
                break;
        }
        if (soundValue == 1 || soundValue == 4) {
            pitch -= 0x100;
        } else if (soundValue == 2 || soundValue == 5) {
            pitch -= 0x200;
        }
        SetSndHandleTrackPitch(handleSlot, pitch);
    }
    gEmblemSoundCallsSincePlay = 0;
}
