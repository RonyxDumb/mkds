#include "Main/Unknown/code_021108bc.h"
#include "Main/Unknown/code_020c70ec.h"
#include "Main/Unknown/code_02108e38.h"
#include "Main/Unknown/code_0210d590.h"
#include "Main/Unknown/unk_0217d000.h"
#include "Main/Unknown/unk_0217d068.h"
#include "Main/Unknown/unk_021759c0.h"
#include "Main/Unknown/code_02105ec0.h"
#include "Main/Unknown/code_02108000.h"
#include "Main/Unknown/code_0203c000.h"
#include "Main/Unknown/code_020c7000.h"
#include "Main/Unknown/code_0210d000.h"
#include "Main/Unknown/code_02108e6c.h"
#include "Main/Unknown/code_021059e0.h"
#include "code_0212bcac.h"
#include "code_0212df7c.h"
#include "Main/Unknown/code_0203c8dc.h"

void UpdateRaceEndSeq(void) {
    s32 resultKind;
    s32 callCount;
    s32 callLimit;
    u32 seqId;
    u32 *seqRow;
    if (gRaceEndSeqStarted == 0) {
        return;
    }
    if (data_0217d070.mSeqPlayer != NULL) {
        return;
    }
    resultKind = GetRaceEndResultKind();
    callLimit = (resultKind == 2) ? 0x91 : 0x82;
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
        case 0:
        case 1:
            seqId = seqRow[3];
            break;
        case 2:
            seqId = seqRow[4];
            break;
    }
    StartScenePlayersSeqNo(&data_0217d070, seqId, NULL);
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
        case 5:
            switch (gSeqRowState.mFinishResult) {
                case 0:
                    if (GetKartRank((u16) raceSetup->mEntryIndex) - 1 == 0) {
                        candidateKind = 0;
                    } else {
                        candidateKind = 1;
                    }
                    break;
                case 1:
                case 2:
                    candidateKind = 2;
                    break;
            }
            resultKind = candidateKind;
            break;
        case MODE_VS:
            if (raceSetup->mRuleKind == 1) {
                resultKind = (gSeqRowState.mFinishResult == 0) ? 0 : 2;
            } else {
                switch (gSeqRowState.mFinishResult) {
                    case 0:
                        if (GetKartRank((u16) raceSetup->mEntryIndex) - 1 == 0) {
                            candidateKind = 0;
                        } else {
                            candidateKind = 1;
                        }
                        break;
                    case 1:
                    case 2:
                        candidateKind = 2;
                        break;
                }
                resultKind = candidateKind;
            }
            break;
        case MODE_MISSION_RUN:
            resultKind = (gSeqRowState.mFinishResult == 0) ? 0 : 2;
            break;
        case MODE_BATTLE:
            resultKind = (gSeqRowState.mFinishResult == 0) ? 0 : 2;
            break;
        case MODE_TIME_ATTACK:
            resultKind = (gSeqRowState.mFinishResult == 0) ? 1 : 2;
            if (resultKind == IsRaceNewRecordTaFinishRecordFirst()) {
                resultKind = 0;
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
    u32 c;
    u32 *seqRow;
    seqId = -1;
    c = gRaceSetup->mRaceKind;
    if (c != 2 && c != RACE_KIND_NORMAL) {
        return;
    }
    if (data_0217d084.mMode != 2) {
        return;
    }
    EndRaceSounds();
    resultKind = GetRaceEndResultKind();
    seqRow = gSeqRowState.mSeqRow;
    c = 0xff;
    switch (resultKind) {
        case 0:
            c = seqRow[0];
            break;
        case 1:
            c = seqRow[1];
            break;
        case 2:
            c = seqRow[2];
            break;
    }
    StartScenePlayersSeqNo(&data_0217d070, c, NULL);
    gRaceEndSeqStarted = 1;
    gRaceEndNextSeqPending = 1;
    switch (gRaceSetup->mCourseId) {
        case COURSE_ID_STADIUM:
            switch (resultKind) {
                case 0:
                case 1:
                    seqId = 0x1bd;
                    break;
                default:
                    seqId = 0x1be;
                    break;
            }
            break;
        case COURSE_ID_CROSS:
            switch (resultKind) {
                case 0:
                case 1:
                    seqId = 0x105;
                    break;
                default:
                    seqId = 0x106;
                    break;
            }
            break;
        case COURSE_ID_MARIO:
            switch (resultKind) {
                case 0:
                case 1:
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
    func_02108e38();
    NNS_SndArcPlayerStartSeqArc(&data_0217d068, 0, (u16) seqId);
}

s32 GetLastLapCourseSoundId(void) {
    s32 seqId;
    s32 resultKind;
    resultKind = GetRaceEndResultKind();
    seqId = -1;
    switch (gRaceSetup->mCourseId) {
        case COURSE_ID_CROSS:
            switch (resultKind) {
                case 0:
                case 1:
                    seqId = 0x104;
                    break;
                default:
                    seqId = 0x107;
                    break;
            }
            break;
        case COURSE_ID_MARIO:
            switch (resultKind) {
                case 0:
                case 1:
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
