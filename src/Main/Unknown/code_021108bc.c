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

void sub_2111024(void) {
    s32 resultKind;
    s32 callCount;
    s32 callLimit;
    u32 seqId;
    u32 *row;
    if (data_0217d324 == 0) {
        return;
    }
    if (data_0217d070.fieldC != NULL) {
        return;
    }
    resultKind = sub_2110E58();
    callLimit = (resultKind == 2) ? 0x91 : 0x82;
    callCount = data_0217d320 + 1;
    data_0217d320 = callCount;
    if (callCount <= callLimit) {
        return;
    }
    if (data_0217d328 == 0) {
        return;
    }
    row = g_GlobalCX.mSeqRow;
    seqId = 0xff;
    switch (resultKind) {
        case 0:
        case 1:
            seqId = row[3];
            break;
        case 2:
            seqId = row[4];
            break;
    }
    MKDS_SND_210D614(&data_0217d070, seqId, NULL);
    data_0217d328 = 0;
    data_0217d324 = 0;
    data_0217d320 = 0;
}

s32 sub_2110FB8(s32 kartRank) {
    s32 b;
    b = 0xb;
    if (kartRank == 1) {
        b = 9;
    } else {
        switch (gRaceMultiConfig->mKartCount) {
            case 4:
            case 5:
                if (kartRank < 3) {
                    b = 0xa;
                }
                break;
            case 6:
            case 7:
            case 8:
                if (kartRank < 4) {
                    b = 0xa;
                }
                break;
        }
    }
    return b;
}

s32 sub_2110E58(void) {
    s32 resultKind;
    s32 candidateKind;
    RaceSetup *raceSetup;
    resultKind = -1;
    raceSetup = gRaceMultiConfig;
    switch (raceSetup->mMode) {
        case MODE_GRAND_PRIX:
        case 5:
            switch (g_GlobalCX.fieldC) {
                case 0:
                    if (rstat_getPlace((u16) raceSetup->mEntryIndex) - 1 == 0) {
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
                resultKind = (g_GlobalCX.fieldC == 0) ? 0 : 2;
            } else {
                switch (g_GlobalCX.fieldC) {
                    case 0:
                        if (rstat_getPlace((u16) raceSetup->mEntryIndex) - 1 == 0) {
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
            resultKind = (g_GlobalCX.fieldC == 0) ? 0 : 2;
            break;
        case MODE_BATTLE:
            resultKind = (g_GlobalCX.fieldC == 0) ? 0 : 2;
            break;
        case MODE_TIME_ATTACK:
            resultKind = (g_GlobalCX.fieldC == 0) ? 1 : 2;
            if (resultKind == IsRaceNewRecordTaFinishRecordFirst()) {
                resultKind = 0;
            }
            break;
    }
    return resultKind;
}

void MaybePlayCrowdAmbientNoise(s32 unused) {
    s32 seqId;
    s32 resultKind;
    u32 c;
    u32 *row;
    seqId = -1;
    c = gRaceMultiConfig->mRaceKind;
    if (c != 2 && c != RACE_KIND_NORMAL) {
        return;
    }
    if (SoundHandle_217D084.mMode != 2) {
        return;
    }
    EndRaceSounds();
    resultKind = sub_2110E58();
    row = g_GlobalCX.mSeqRow;
    c = 0xff;
    switch (resultKind) {
        case 0:
            c = row[0];
            break;
        case 1:
            c = row[1];
            break;
        case 2:
            c = row[2];
            break;
    }
    MKDS_SND_210D614(&data_0217d070, c, NULL);
    data_0217d324 = 1;
    data_0217d328 = 1;
    switch (gRaceMultiConfig->mCourseId) {
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
    sub_2108E38();
    NNS_SndArcPlayerStartSeqArc(&data_0217d068, 0, (u16) seqId);
}

s32 sub_2110C40(void) {
    s32 seqId;
    s32 resultKind;
    resultKind = sub_2110E58();
    seqId = -1;
    switch (gRaceMultiConfig->mCourseId) {
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

// Releases the object when it holds nothing other than the given value, otherwise sets it up with that value.
static inline void func_02110aac_inline(NNSSndSeqPlayer **handleSlot, u32 seqId) {
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

void func_02110aac(s32 a, s32 b) {
    NNSSndSeqPlayer **handleSlot;
    u32 firstSeqId;
    u32 secondSeqId;
    handleSlot = GetSndHandleSlot(1);
    if (a == 0) {
        firstSeqId = 0x1ff;
    } else if (a == 1) {
        firstSeqId = 0x200;
    } else {
        firstSeqId = 0xffff;
    }
    func_02110aac_inline(handleSlot, firstSeqId);
    handleSlot = GetSndHandleSlot(2);
    secondSeqId = (b != 0) ? 0x201 : 0xffff;
    if (firstSeqId != 0xffff) {
        secondSeqId = 0xffff;
    }
    func_02110aac_inline(handleSlot, secondSeqId);
}

void sub_2110A60(void) {
    data_0217d204 = 0;
    data_0217d1e0 = 0;
    data_0217d1e4 = 0;
    data_0217d1f4 = 7;
}

void sub_21108BC(s32 a) {
    s32 seqId;
    s32 pitch;
    u8 m;
    u32 callsSincePlay;
    NNSSndSeqPlayer **handleSlot;
    if (a <= 2) {
        seqId = 0x1f7;
    } else if (a <= 5) {
        seqId = 0x1f8;
    } else {
        seqId = -1;
    }
    m = data_0217d1e4 + 1;
    callsSincePlay = data_0217d204 + 1;
    data_0217d1e4 = m;
    data_0217d204 = callsSincePlay;
    if (seqId == -1) {
        return;
    }
    if (callsSincePlay < 2) {
        return;
    }
    handleSlot = GetSndHandleSlot((data_0217d1e0 & 1) ? 2 : 3);
    if (data_0217d204 >= 0x14) {
        data_0217d1e4 = 0;
    }
    if (*handleSlot != NULL) {
        NNS_SndPlayerStopSeq(handleSlot, 0);
    }
    NNS_SndArcPlayerStartSeqArc(handleSlot, 0, (u16) seqId);
    data_0217d1e0 = data_0217d1e0 + 1;
    if (handleSlot != NULL) {
        switch (data_0217d1e4 % 3) {
            case 0:
                pitch = 0;
                break;
            case 1:
                pitch = (a <= 2) ? 0x40 : -0x40;
                break;
            case 2:
                pitch = (a <= 2) ? 0x80 : -0x80;
                break;
        }
        if (a == 1 || a == 4) {
            pitch -= 0x100;
        } else if (a == 2 || a == 5) {
            pitch -= 0x200;
        }
        SetSndHandleTrackPitch(handleSlot, pitch);
    }
    data_0217d204 = 0;
}
