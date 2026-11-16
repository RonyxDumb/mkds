#include "Main/Race/demo_race.h"
#include "Main/Race/random_pick.h"
#include "Main/Race/entry_character_kart.h"
#include "Main/Race/cup_reset.h"
#include "Main/Menu/second_menu_scene.h"
#include "Main/Save/backup_reset.h"
#include "Main/MapObjects/map_object_park.h"
#include "Main/Kart/kart_scale_surface_tables.h"
#include "Main/Race/race_setup_block.h"
#include "touch_panel_sampling.h"
#include "tick_counter.h"
#include "signed_int_divide.h"
#include "float_subtract_int64_muldiv.h"
#include "clock_chip_access.h"
#include "Main/Race/race_setup_input.h"

#pragma thumb on

BOOL IsCupAlwaysOrSecretMessageFlagSet(s32 cupIndex) {
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
            if (CheckSavedSecretFlag_from_thumb(0) != 0 || CheckSavedSecretFlag_from_thumb(1) != 0 || CheckSavedSecretFlag_from_thumb(2) != 0 ||
                CheckSavedSecretFlag_from_thumb(3) != 0) {
                return TRUE;
            }
            break;
        case 3:
            if (CheckSavedSecretFlag_from_thumb(4) != 0 || CheckSavedSecretFlag_from_thumb(5) != 0 || CheckSavedSecretFlag_from_thumb(6) != 0 ||
                CheckSavedSecretFlag_from_thumb(7) != 0) {
                return TRUE;
            }
            break;
        case 6:
            if (CheckSavedSecretFlag_from_thumb(8) != 0 || CheckSavedSecretFlag_from_thumb(9) != 0 || CheckSavedSecretFlag_from_thumb(10) != 0 ||
                CheckSavedSecretFlag_from_thumb(11) != 0) {
                return TRUE;
            }
            break;
        case 7:
            if (CheckSavedSecretFlag_from_thumb(12) != 0 || CheckSavedSecretFlag_from_thumb(13) != 0 || CheckSavedSecretFlag_from_thumb(14) != 0 ||
                CheckSavedSecretFlag_from_thumb(15) != 0) {
                return TRUE;
            }
            break;
    }
    return FALSE;
}

u32 PickRandomCupIndex(RandomState64 *random) {
    u8 passingCupCount;
    u8 cupIndex;
    u16 seenCount;
    u16 pickedPosition;
    u32 randomPosition;

    passingCupCount = 0;
    seenCount = 0;
    for (cupIndex = 0; cupIndex < 8; cupIndex++) {
        if (IsCupAlwaysOrSecretMessageFlagSet(cupIndex) != FALSE) {
            passingCupCount++;
        }
    }
    if (passingCupCount == 0) {
        randomPosition = 0;
    } else {
        random->mValue = Multiply64(random->mMultiplier, random->mValue) + random->mIncrement;
        if (passingCupCount == 0) {
            randomPosition = random->mValue >> 32;
        } else {
            randomPosition = (u64) (u32) (random->mValue >> 32) * (u32) passingCupCount >> 32;
        }
    }
    pickedPosition = randomPosition;
    for (cupIndex = 0; cupIndex < 8; cupIndex++) {
        if (IsCupAlwaysOrSecretMessageFlagSet(cupIndex) != FALSE) {
            seenCount++;
            if (seenCount > pickedPosition) {
                break;
            }
        }
    }
    return cupIndex;
}

void SetNextDemoRace(CharacterKartPicks *picks) {
    RandomState64 random;
    RTCTime time;
    u16 otherKartIndices[2];
    u32 characterIndex;
    u32 kartIndex;
    u16 shuffledIndices[8];
    u16 cupIndex;
    u16 courseIndexInCup;
    u16 swapIndex;
    u16 shuffleIndex;
    u16 entryIndex;
    u16 candidateIndex;
    u16 otherIndex;
    u16 followedKartIndex;
    u32 swapTemp;
    u32 listedCpuSlot;

    if (Rtc_GetTime(&time) != 0) {
        time.mHour = 0;
        time.mMinute = 0;
        time.mSecond = 0;
    }
    random.mValue = (u32) ((time.mHour * 60 + time.mMinute) * 60 + time.mSecond + Os_GetTick());
    random.mMultiplier = RANDOM_STATE64_MULTIPLIER;
    random.mIncrement = RANDOM_STATE64_INCREMENT;
    g_GlobalCO->mNextHeader.mMode = MODE_GRAND_PRIX;
    g_GlobalCO->mNextHeader.mRaceKind = RACE_KIND_DEMO;
    g_GlobalCO->mNextHeader.mEngineIndex = ENGINE_CLASS_FAST;
    g_GlobalCO->mNextHeader.mUseTeams = 0;
    g_GlobalCO->mNextHeader.mRuleKind = RULE_KIND_FREE;
    g_GlobalCO->mNextHeader.mCourseListMode = 0;
    g_GlobalCO->mNextHeader.mMirrorMode = 0;
    g_GlobalCO->mNextHeader.mLapCount = -1;
    g_GlobalCO->mNextHeader.mCpuDifficulty = CPU_DIFFICULTY_NORMAL;
    random.mValue = Multiply64(random.mMultiplier, random.mValue) + random.mIncrement;
    courseIndexInCup = (u64) (u32) (random.mValue >> 32) * 4 >> 32;
    cupIndex = PickRandomCupIndex(&random);
    g_GlobalCO->mNextHeader.mCourseId = g_InternalCourseIdOrderedTable[cupIndex][courseIndexInCup];
    random.mValue = Multiply64(random.mMultiplier, random.mValue) + random.mIncrement;
    followedKartIndex = (u64) (u32) (random.mValue >> 32) * 8 >> 32;
    g_GlobalCO->mNextHeader.mFollowedKartIndex = followedKartIndex;
    for (otherIndex = 0; otherIndex < 2; otherIndex++) {
        for (candidateIndex = 0; candidateIndex < 8; candidateIndex++) {
            if (candidateIndex != followedKartIndex) {
                otherKartIndices[otherIndex] = candidateIndex;
                break;
            }
        }
    }
    for (entryIndex = 0; entryIndex < 8; entryIndex++) {
        shuffledIndices[entryIndex] = entryIndex;
    }
    for (shuffleIndex = 0; shuffleIndex < 1000; shuffleIndex++) {
        random.mValue = Multiply64(random.mMultiplier, random.mValue) + random.mIncrement;
        swapIndex = (u64) (u32) (random.mValue >> 32) * 7 >> 32;
        random.mValue = Multiply64(random.mMultiplier, random.mValue) + random.mIncrement;
        swapTemp = shuffledIndices[swapIndex];
        shuffledIndices[swapIndex] = shuffledIndices[(u16) ((u64) (u32) (random.mValue >> 32) * 7 >> 32)];
        shuffledIndices[(u16) ((u64) (u32) (random.mValue >> 32) * 7 >> 32)] = swapTemp;
    }
    SetGivenCharacterAndKart(picks, 0, 0, 0);
    PickRandomCharactersAndKarts(picks);
    for (entryIndex = 0; entryIndex < 8; entryIndex++) {
        listedCpuSlot = 3;
        if (otherKartIndices[0] == entryIndex) {
            listedCpuSlot = 0;
        }
        if (otherKartIndices[1] == entryIndex) {
            listedCpuSlot = 1;
        }
        GetEntryCharacterAndKart(picks, entryIndex, &characterIndex, &kartIndex);
        StructCO_ConfigureRacerDefault(entryIndex, characterIndex, kartIndex, PLAYER_KIND_CPU, -1, listedCpuSlot);
    }
    ResetCupToFirstCourse();
}

#pragma thumb off
