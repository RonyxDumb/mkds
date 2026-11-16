#include "Main/Unknown/code_02045874.h"
#include "00/code_02181f98.h"
#include "Main/Unknown/code_02029aa0.h"
#include "Main/Unknown/code_02046000.h"
#include "Main/Unknown/code_020467d0.h"
#include "Main/Unknown/code_0204a000.h"
#include "Main/Unknown/code_0204aa60.h"
#include "Main/Unknown/code_0205d0e8.h"
#include "Main/Unknown/code_0205dc7c.h"
#include "Main/Unknown/code_0205ee14.h"
#include "Main/Unknown/unk_02154000.h"
#include "Main/Unknown/unk_02175000.h"
#include "Main/Unknown/unk_021759c0.h"
#include "Main/Unknown/unk_0217a000.h"
#include "Main/Unknown/code_02090354.h"

static inline u32 func_02046524_inline(RandomState64 *randomState64, u32 limit) {
    u64 result;
    if (limit == 0) {
        result = 0;
    } else {
        randomState64->mValue = randomState64->mMultiplier * randomState64->mValue + randomState64->mIncrement;
        if (limit == 0) {
            result = randomState64->mValue >> 32;
        } else {
            result = ((randomState64->mValue >> 32) * limit) >> 32;
        }
    }
    return (u16) result;
}

BOOL func_02046648(s32 a) {
    u32 n;
    n = (u8) gRaceMultiConfig->mNextHeader.mEngineIndex;
    if (gRaceMultiConfig->mNextHeader.mMirrorMode != 0) {
        n = 3;
    }
    switch (a) {
        case 0:
        case 1:
        case 4:
        case 5:
            return TRUE;
        case 2:
            if (IsBitSetInAnyParticipant(n)) {
                return TRUE;
            }
            break;
        case 3:
            if (IsBitSetInAnyParticipant(n + 4)) {
                return TRUE;
            }
            break;
        case 6:
            if (IsBitSetInAnyParticipant(n + 8)) {
                return TRUE;
            }
            break;
        case 7:
            if (IsBitSetInAnyParticipant(n + 12)) {
                return TRUE;
            }
            break;
    }
    return FALSE;
}

void AssignCpuNumbers(void) {
    u8 nextCpuNumber;
    BOOL f;
    u8 i;
    nextCpuNumber = 1;
    f = FALSE;
    switch (gRaceMultiConfig->mNextHeader.mMode) {
        case MODE_GRAND_PRIX:
        case MODE_TIME_ATTACK:
        case MODE_MISSION_RUN:
        case 5:
            f = TRUE;
            break;
    }
    for (i = 0; i < 8; i++) {
        if (f == FALSE && gRaceMultiConfig->mNextEntries[i].mPlayer.mKind == PLAYER_KIND_CPU) {
            gRaceMultiConfig->mNextEntries[i].mPlayer.mNumber = nextCpuNumber;
            nextCpuNumber = nextCpuNumber + 1;
        } else {
            gRaceMultiConfig->mNextEntries[i].mPlayer.mNumber = -1;
        }
    }
    gRaceMultiConfig->mNextCpuNumber = nextCpuNumber;
}

u32 func_02046524(RandomState64 *randomState64, u32 limit) {
    u64 result;
    if (limit == 0) {
        result = 0;
    } else {
        randomState64->mValue = randomState64->mMultiplier * randomState64->mValue + randomState64->mIncrement;
        if (limit == 0) {
            result = randomState64->mValue >> 32;
        } else {
            result = ((randomState64->mValue >> 32) * limit) >> 32;
        }
    }
    return (u16) result;
}

void BuildCourseList(s32 isVersus) {
    s32 f;
    u32 m;
    const u32 *t;
    u32 i;
    u32 n;
    f = 0;
    rres_reset();
    gRaceMultiConfig->mCourseListIndex = 0;
    gRaceMultiConfig->mNextHeader.mCourseNumber = 1;
    if (isVersus != 0) {
        gRaceMultiConfig->mNextHeader.mRaceKind = RACE_KIND_NORMAL;
    } else if (gSystemData->field1C_2) {
        gRaceMultiConfig->mNextHeader.mRaceKind = RACE_KIND_NORMAL;
    } else {
        gRaceMultiConfig->mNextHeader.mRaceKind = 4;
    }
    for (i = 0; i < 0x21; i++) {
        gRaceMultiConfig->mCourseList[i] = 0;
    }
    switch (gSystemData->field20) {
        case 1:
        case 2:
            f = (gStruct217AA00->field454 & 0x40) != 0;
            break;
    }
    switch (gRaceMultiConfig->mNextHeader.mCourseListMode) {
        case 1:
            if (isVersus != 0) {
                u8 p;
                u8 q;
                u32 n;
                s32 e;
                s32 c;
                m = f != 0 ? 2 : 8;
                t = f != 0 ? data_021540c0 : data_02154108;
                e = gRaceMultiConfig->mNextHeader.mCourseId;
                n = m * 4;
                for (f = 0; f < n; f++) {
                    p = f / 4;
                    q = f % 4;
                    if (e == sCupDefs[t[p]][q]) {
                        break;
                    }
                }
                c = 0;
                for (f = 0; f < n; f++) {
                    if (func_02046648(t[p]) != FALSE) {
                        gRaceMultiConfig->mCourseList[c] = sCupDefs[t[p]][q];
                        c = (u8) (c + 1);
                    }
                    q = q + 1;
                    if (q >= 4) {
                        q = 0;
                        p = p + 1;
                        if (p >= m) {
                            p = 0;
                        }
                    }
                }
                return;
            } else {
                s32 e;
                u32 s;
                n = f != 0 ? 3 : 6;
                s = 0;
                t = f != 0 ? data_021540c8 : BattleStageOrder;
                e = gRaceMultiConfig->mNextHeader.mCourseId;
                for (i = 0; i < n; i++) {
                    s = i;
                    if (e == t[i]) {
                        break;
                    }
                }
                for (i = 0; i < n; i++) {
                    gRaceMultiConfig->mCourseList[i] = t[s];
                    s++;
                    if (s >= n) {
                        s = 0;
                    }
                }
                return;
            }
        case 2:
            if (isVersus != 0) {
                RandomState64 *g;
                u32 n;
                s32 k;
                s32 c;
                u8 q;
                u8 p;
                u8 w;
                u8 x;
                u8 y;
                s32 h;
                s32 z;
                g = sysdat_getRandom();
                m = f != 0 ? 2 : 8;
                t = f != 0 ? data_021540c0 : data_02154108;
                n = m * 4;
                c = 0;
                for (k = 0; k < n; k++) {
                    p = k / 4;
                    q = k % 4;
                    if (func_02046648(t[p]) != FALSE) {
                        gRaceMultiConfig->mCourseList[c] = sCupDefs[t[p]][q];
                        c = (u8) (c + 1);
                    }
                }
                h = c * 2;
                for (z = 0; z < h; z++) {
                    w = func_02046524(g, (vu16) (c - 1));
                    x = z % c;
                    y = gRaceMultiConfig->mCourseList[x];
                    if (w >= x) {
                        w = w + 1;
                    }
                    gRaceMultiConfig->mCourseList[x] = gRaceMultiConfig->mCourseList[w];
                    gRaceMultiConfig->mCourseList[w] = y;
                }
            } else {
                s32 k;
                RandomState64 *g;
                g = sysdat_getRandom();
                n = f != 0 ? 3 : 6;
                t = f != 0 ? data_021540c8 : BattleStageOrder;
                for (k = 0; k < n; k++) {
                    gRaceMultiConfig->mCourseList[k] = t[k];
                }
                k = 0;
                if (k < n) {
                    m = (u16) (n - 1);
                    for (; k < n; k++) {
                        u8 w;
                        u8 y;
                        w = func_02046524_inline(g, m);
                        y = gRaceMultiConfig->mCourseList[k];
                        if (w >= k) {
                            w = w + 1;
                        }
                        gRaceMultiConfig->mCourseList[k] = gRaceMultiConfig->mCourseList[w];
                        gRaceMultiConfig->mCourseList[w] = y;
                    }
                }
            }
            gRaceMultiConfig->mNextHeader.mCourseId = gRaceMultiConfig->mCourseList[0];
            break;
    }
}

void rconf_2045ED0(void) {
    u8 i;
    u8 humanIndex;
    AssignCpuNumbers();
    switch (gRaceMultiConfig->mNextHeader.mMode) {
        case MODE_GRAND_PRIX:
            rres_reset();
            gRaceMultiConfig->mNextHeader.mCourseNumber = 1;
            gRaceMultiConfig->mNextHeader.mRaceKind = RACE_KIND_START_GP;
            gRaceMultiConfig->mNextHeader.mCourseId =
                sCupDefs[gRaceMultiConfig->mNextHeader.mCupIndex][gRaceMultiConfig->mNextHeader.mCourseNumber - 1];
            break;
        case MODE_VS:
            BuildCourseList(1);
            break;
        case MODE_BATTLE:
            BuildCourseList(0);
            break;
        case 5:
            humanIndex = 0xff;
            rres_reset();
            gRaceMultiConfig->mNextHeader.mCourseNumber = 1;
            gRaceMultiConfig->mNextHeader.mRaceKind = RACE_KIND_NORMAL;
            for (i = 0; i < 4; i++) {
                if (gRaceMultiConfig->mNextEntries[i].mPlayer.mKind == PLAYER_KIND_HUMAN) {
                    humanIndex = i;
                    break;
                }
            }
            gRaceMultiConfig->mNextHeader.mFollowedKartIndex = humanIndex;
            break;
        case MODE_MISSION_RUN:
            rres_reset();
            if (gRaceMultiConfig->mNextHeader.mMissionTableColumn == 9) {
                gRaceMultiConfig->mNextHeader.mRaceKind = RACE_KIND_START_GP;
            } else {
                gRaceMultiConfig->mNextHeader.mRaceKind = RACE_KIND_NORMAL;
            }
            gRaceMultiConfig->mNextHeader.mCourseNumber = 1;
            break;
    }
}

BOOL rconf_setupAward(void) {
    s8 entryIndex;
    u8 i;
    s8 j;
    u8 courseIndexInCup;
    u32 lowByte;
    s32 rankIndex;
    KartCourseResult *courseResult;
    entryIndex = gRaceMultiConfig->mEntryIndex;
    gStruct217B488->mCupRankIndex = rres_getGlobalRank((u16) entryIndex) - 1;
    gStruct217B488->field80 = rres_calculateGpRank();
    gStruct217B488->mCharacterIndex = gRaceMultiConfig->mCurrentEntries[(u8) entryIndex].mCharacterIndex;
    gStruct217B488->mCupIndex = gRaceMultiConfig->mCupIndex;
    gStruct217B488->mEngineIndex = gRaceMultiConfig->mEngineIndex;
    gStruct217B488->mMirrorMode = gRaceMultiConfig->mMirrorMode;
    lowByte = rres_205DC7C((u8) entryIndex);
    courseIndexInCup = rres_205DB28();
    courseResult = &rres_sRaceResults->mKartResults[courseIndexInCup][rres_205DC7C(lowByte)];
    gStruct217B488->mTotalPoints = courseResult->mTotalPoints;
    gStruct217B488->mKartIndex = gRaceMultiConfig->mCurrentEntries[(u8) entryIndex].mKartIndex;
    for (i = 0; i < 4; i++) {
        Unk0217aa1c_144_00 finishTime;
        rres_getRaceTime(&finishTime, (u16) gRaceMultiConfig->mEntryIndex, i);
        gStruct217B488->mCourseTimes[i] = finishTime;
    }
    if ((u32) rres_getGlobalRank((u16) gRaceMultiConfig->mEntryIndex) > 3) {
        return FALSE;
    }
    gRaceMultiConfig->mNextHeader.mCourseId = COURSE_ID_AWARD;
    gRaceMultiConfig->mNextHeader.mRaceKind = RACE_KIND_AWARD;
    for (i = 0; i < 3; i++) {
        for (j = 0; j < gRaceMultiConfig->mKartCount; j++) {
            if (rres_getGlobalRank((u16) j) == i + 1) {
                break;
            }
        }
        rconf_setDriverConfigNext(i, gRaceMultiConfig->mCurrentEntries[(u16) j].mCharacterIndex,
                         gRaceMultiConfig->mCurrentEntries[(u16) j].mKartIndex, PLAYER_KIND_CPU, -1, 3);
    }
    for (; i < 8; i++) {
        rconf_setDriverConfigNext(i, i, i * 3, PLAYER_KIND_NONE, -1, 3);
    }
    for (i = 0; i < 8; i++) {
        rankIndex = rres_getGlobalRank(i) - 1;
        gStruct217B488->fieldCC[rankIndex] = gRaceMultiConfig->mCurrentEntries[i].mKartIndex;
        gStruct217B488->fieldAC[rankIndex] = gRaceMultiConfig->mCurrentEntries[i].mCharacterIndex;
    }
    gRaceMultiConfig->mNextHeader.mFollowedKartIndex = rres_getGlobalRank((u16) gRaceMultiConfig->mEntryIndex) - 1;
    return TRUE;
}

void rconf_setupStaffRoll(s32 useTrueStaffRoll) {
    u8 i;
    s8 j;
    s32 characterIndex;
    s32 kartIndex;
    if (useTrueStaffRoll != 0) {
        gRaceMultiConfig->mNextHeader.mCourseId = COURSE_ID_STAFFROLLTRUE;
    } else {
        gRaceMultiConfig->mNextHeader.mCourseId = COURSE_ID_STAFFROLL;
    }
    gRaceMultiConfig->mNextHeader.mRaceKind = RACE_KIND_STAFF_ROLL;
    gRaceMultiConfig->mNextHeader.mEngineIndex = 1;
    gRaceMultiConfig->mNextHeader.mFollowedKartIndex = 0;
    for (i = 0; i < 8; i++) {
        for (j = 0; j < gRaceMultiConfig->mKartCount; j++) {
            if (rres_getGlobalRank((u16) j) == i + 1) {
                break;
            }
        }
        if (gRaceMultiConfig->mMode == MODE_MISSION_RUN) {
            if ((gRaceMultiConfig->mMode == MODE_MISSION_RUN ? gRaceMultiConfig->mMissionTableRow : -1) == 6 &&
                (gRaceMultiConfig->mMode == MODE_MISSION_RUN ? gRaceMultiConfig->mMissionTableColumn : -1) == 9) {
                if (i == 0) {
                    characterIndex = 7;
                    kartIndex = 0x15;
                } else if (i == 7) {
                    characterIndex = 0;
                    kartIndex = characterIndex;
                } else {
                    characterIndex = i;
                    kartIndex = i * 3;
                }
            } else {
                characterIndex = i;
                kartIndex = i * 3;
            }
        } else if (gRaceMultiConfig->mMode == MODE_GRAND_PRIX) {
            if (unlock_hasUnlockedTrueStaffRoll() != 2) {
                characterIndex = i;
                kartIndex = i * 3;
            } else {
                characterIndex = gStruct217B488->fieldAC[i];
                kartIndex = gStruct217B488->fieldCC[i];
            }
        } else {
            characterIndex = i;
            kartIndex = i * 3;
        }
        rconf_setDriverConfigNext(i, characterIndex, kartIndex, PLAYER_KIND_CPU, -1, 3);
    }
}

s32 AdvanceToNextCourse(void) {
    BOOL result;
    s32 i;
    s32 v;
    s32 x;
    result = TRUE;
    gRaceMultiConfig->mNextHeader.mCourseNumber++;
    if (gRaceMultiConfig->field3D4 > 1) {
        for (i = 0; i < gRaceMultiConfig->mKartCount; i++) {
            x = gRaceMultiConfig->mCurrentEntries[i].mPlayer.field8;
            v = 3;
            if (x != 0) {
                if (x == 1) {
                    v = 0;
                }
            } else {
                v = 1;
            }
            gRaceMultiConfig->mNextEntries[i].mPlayer.field8 = v;
        }
    }
    switch (gRaceMultiConfig->mCourseListMode) {
        case 0:
            result = FALSE;
            break;
        case 1:
        case 2:
            gRaceMultiConfig->mCourseListIndex++;
            if (gRaceMultiConfig->mCourseList[gRaceMultiConfig->mCourseListIndex] == 0) {
                gRaceMultiConfig->mCourseListIndex = 0;
            }
            gRaceMultiConfig->mNextHeader.mCourseId = gRaceMultiConfig->mCourseList[gRaceMultiConfig->mCourseListIndex];
            break;
    }
    return result;
}

s32 func_02045914(void) {
    return AdvanceToNextCourse();
}

s32 func_020458cc(void) {
    if (gSystemData->field1C_2) {
        gRaceMultiConfig->mNextHeader.mRaceKind = RACE_KIND_NORMAL;
    } else {
        gRaceMultiConfig->mNextHeader.mRaceKind = 4;
    }
    return AdvanceToNextCourse();
}

BOOL race_2045874(void) {
    gStruct217B488->field5C[gRaceMultiConfig->mCourseNumber] = gRaceMultiConfig->mCourseId;
    gRaceMultiConfig->mNextHeader.mCourseNumber++;
    return gRaceMultiConfig->mNextHeader.mCourseNumber <= 4;
}
