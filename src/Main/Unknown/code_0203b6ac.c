#include "Main/Unknown/code_0203b6ac.h"
#include "Main/Unknown/code_0203b000.h"
#include "Main/Unknown/code_0203ba70.h"
#include "Main/Unknown/code_0203be48.h"
#include "Main/Unknown/code_02046000.h"
#include "Main/Unknown/code_020467a0.h"
#include "Main/Unknown/code_020467d0.h"
#include "Main/Unknown/code_02056d54.h"
#include "Main/Unknown/code_020d22c0.h"
#include "Main/Unknown/unk_02154000.h"
#include "Main/Unknown/unk_021759c0.h"
#include "code_0200f5ac.h"
#include "code_02133048.h"
#include "code_0214d93c.h"

#pragma thumb on

BOOL func_0203b96c(s32 cupIndex) {
    if (cupIndex == 9) {
        return FALSE;
    }
    switch (cupIndex) {
        case 0:
        case 1:
        case 4:
        case 5:
            return TRUE;
        case 2:
            if (savd_isUnlockBitSet(0) != 0 || savd_isUnlockBitSet(1) != 0 || savd_isUnlockBitSet(2) != 0 ||
                savd_isUnlockBitSet(3) != 0) {
                return TRUE;
            }
            break;
        case 3:
            if (savd_isUnlockBitSet(4) != 0 || savd_isUnlockBitSet(5) != 0 || savd_isUnlockBitSet(6) != 0 ||
                savd_isUnlockBitSet(7) != 0) {
                return TRUE;
            }
            break;
        case 6:
            if (savd_isUnlockBitSet(8) != 0 || savd_isUnlockBitSet(9) != 0 || savd_isUnlockBitSet(10) != 0 ||
                savd_isUnlockBitSet(11) != 0) {
                return TRUE;
            }
            break;
        case 7:
            if (savd_isUnlockBitSet(12) != 0 || savd_isUnlockBitSet(13) != 0 || savd_isUnlockBitSet(14) != 0 ||
                savd_isUnlockBitSet(15) != 0) {
                return TRUE;
            }
            break;
    }
    return FALSE;
}

u32 func_0203b8e4(RandomState64 *random) {
    u8 passingCupCount;
    u8 cupIndex;
    u16 seenCount;
    u16 pickedPosition;
    u32 randomPosition;

    passingCupCount = 0;
    seenCount = 0;
    for (cupIndex = 0; cupIndex < 8; cupIndex++) {
        if (func_0203b96c(cupIndex) != FALSE) {
            passingCupCount++;
        }
    }
    if (passingCupCount == 0) {
        randomPosition = 0;
    } else {
        random->mValue = _ll_mul(random->mMultiplier, random->mValue) + random->mIncrement;
        if (passingCupCount == 0) {
            randomPosition = random->mValue >> 32;
        } else {
            randomPosition = (u64) (u32) (random->mValue >> 32) * (u32) passingCupCount >> 32;
        }
    }
    pickedPosition = randomPosition;
    for (cupIndex = 0; cupIndex < 8; cupIndex++) {
        if (func_0203b96c(cupIndex) != FALSE) {
            seenCount++;
            if (seenCount > pickedPosition) {
                break;
            }
        }
    }
    return cupIndex;
}

void SetNextDemoRace(u8 *picks) {
    RandomState64 random;
    RTCTime time;
    u16 otherKartIndices[2];
    u32 characterIndex;
    u32 kartIndex;
    u16 shuffledIndices[8];
    u16 cupIndex;
    u16 courseIndexInCup;
    u16 swapIndex;
    u16 g;
    u16 i;
    u16 j;
    u16 k;
    u16 followedKartIndex;
    u32 swapTemp;
    u32 l;

    if (RTC_GetTime(&time) != 0) {
        time.mHour = 0;
        time.mMinute = 0;
        time.mSecond = 0;
    }
    random.mValue = (u32) ((time.mHour * 60 + time.mMinute) * 60 + time.mSecond + OS_GetTick());
    random.mMultiplier = 0x5d588b656c078965ULL;
    random.mIncrement = 0x269ec3;
    gRaceMultiConfig->mNextHeader.mMode = MODE_GRAND_PRIX;
    gRaceMultiConfig->mNextHeader.mRaceKind = RACE_KIND_DEMO;
    gRaceMultiConfig->mNextHeader.mEngineIndex = 2;
    gRaceMultiConfig->mNextHeader.mUseTeams = 0;
    gRaceMultiConfig->mNextHeader.mRuleKind = 0;
    gRaceMultiConfig->mNextHeader.mCourseListMode = 0;
    gRaceMultiConfig->mNextHeader.mMirrorMode = 0;
    gRaceMultiConfig->mNextHeader.mLapCount = -1;
    gRaceMultiConfig->mNextHeader.mCpuDifficulty = 2;
    random.mValue = _ll_mul(random.mMultiplier, random.mValue) + random.mIncrement;
    courseIndexInCup = (u64) (u32) (random.mValue >> 32) * 4 >> 32;
    cupIndex = func_0203b8e4(&random);
    gRaceMultiConfig->mNextHeader.mCourseId = sCupDefs[cupIndex][courseIndexInCup];
    random.mValue = _ll_mul(random.mMultiplier, random.mValue) + random.mIncrement;
    followedKartIndex = (u64) (u32) (random.mValue >> 32) * 8 >> 32;
    gRaceMultiConfig->mNextHeader.mFollowedKartIndex = followedKartIndex;
    for (k = 0; k < 2; k++) {
        for (j = 0; j < 8; j++) {
            if (j != followedKartIndex) {
                otherKartIndices[k] = j;
                break;
            }
        }
    }
    for (i = 0; i < 8; i++) {
        shuffledIndices[i] = i;
    }
    for (g = 0; g < 1000; g++) {
        random.mValue = _ll_mul(random.mMultiplier, random.mValue) + random.mIncrement;
        swapIndex = (u64) (u32) (random.mValue >> 32) * 7 >> 32;
        random.mValue = _ll_mul(random.mMultiplier, random.mValue) + random.mIncrement;
        swapTemp = shuffledIndices[swapIndex];
        shuffledIndices[swapIndex] = shuffledIndices[(u16) ((u64) (u32) (random.mValue >> 32) * 7 >> 32)];
        shuffledIndices[(u16) ((u64) (u32) (random.mValue >> 32) * 7 >> 32)] = swapTemp;
    }
    SetGivenCharacterAndKart(picks, 0, 0, 0);
    PickRandomCharactersAndKarts(picks);
    for (i = 0; i < 8; i++) {
        l = 3;
        if (otherKartIndices[0] == i) {
            l = 0;
        }
        if (otherKartIndices[1] == i) {
            l = 1;
        }
        GetEntryCharacterAndKart(picks, i, &characterIndex, &kartIndex);
        rconf_setDriverConfigNext(i, characterIndex, kartIndex, PLAYER_KIND_CPU, -1, l);
    }
    rconf_resetMatch();
}

#pragma thumb off
