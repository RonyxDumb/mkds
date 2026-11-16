#include "Main/Race/random_pick.h"
#include "Main/Save/buddy_record_time.h"
#include "Main/MapObjects/map_object_park.h"
#include "Main/System/backup_net_camera_work.h"
#include "tick_counter.h"
#include "bit_count.h"

#pragma thumb on

void PickRandomKarts(CharacterKartPicks *picks) {
    RandomState64 localRandom;
    u32 givenBits;
    u8 entry;
    RandomState64 *random;
    u8 i;
    u8 candidateBits;
    u8 seen;
    s32 kart;
    s32 character;
    s32 firstKart;
    u32 candidateCount;
    s32 pick;
    BOOL useSharedRandom;
    u64 firstTick;
    u64 secondTick;

    givenBits = picks->mKartGivenBits;
    useSharedRandom = FALSE;
    if ((gConnectionWork == NULL ? CONNECTION_MODE_NONE : gConnectionWork->mConnectionMode) != CONNECTION_MODE_NONE &&
        gConnectionWork->mState != CONNECTION_STATE_ENDED) {
        useSharedRandom = TRUE;
    }
    if (useSharedRandom != FALSE) {
        random = &gConnectionWork->mRandomState;
    } else {
        firstTick = OS_GetTick();
        secondTick = OS_GetTick();
        localRandom.mValue = ((u32) firstTick << 24) + (u32) (secondTick >> 8);
        localRandom.mMultiplier = RANDOM_STATE64_MULTIPLIER;
        localRandom.mIncrement = RANDOM_STATE64_INCREMENT;
        random = &localRandom;
    }
    for (entry = 0; entry < 8; entry++) {
        kart = -1;
        character = picks->mCharacterIndices[entry];
        candidateBits = 0;
        if ((givenBits & (1 << entry)) == 0) {
            picks->mKartIndices[entry] = -1;
            i = 0;
            firstKart = character * 3;
            for (; i < 3; i++) {
                if (IsKartAppearWithinParticipantLimit(picks->mKartAppear, character, i + firstKart) !=
                    FALSE) {
                    candidateBits = candidateBits | (1 << i);
                }
            }
            for (i = 0; i < 8; i++) {
                if (BIT_IS_SET(givenBits, i) && picks->mKartIndices[i] >= firstKart &&
                    picks->mKartIndices[i] < (character + 1) * 3) {
                    candidateBits = candidateBits & ~(1 << (picks->mKartIndices[i] - firstKart));
                }
            }
            if (candidateBits == 0) {
                for (i = 0; i < 3; i++) {
                    if (IsKartAppearWithinParticipantLimit(picks->mKartAppear, character, i + firstKart) !=
                        FALSE) {
                        candidateBits = candidateBits | (1 << i);
                    }
                }
            }
            candidateCount = CountSetBits(candidateBits);
            if (candidateCount == 0) {
                pick = 0;
            } else {
                random->mValue = random->mMultiplier * random->mValue + random->mIncrement;
                if (candidateCount == 0) {
                    pick = random->mValue >> 32;
                } else {
                    pick = ((random->mValue >> 32) * candidateCount) >> 32;
                }
            }
            seen = 0;
            for (i = 0; i < 3 && kart == -1; i++) {
                if (BIT_IS_SET(candidateBits, i)) {
                    if (seen == (u16) pick) {
                        kart = i + firstKart;
                    } else {
                        seen = seen + 1;
                    }
                }
            }
            picks->mKartIndices[entry] = kart;
        }
    }
}

void PickRandomCharacters(CharacterKartPicks *picks) {
    RandomState64 localRandom;
    u16 availableBits;
    BOOL useSharedRandom;
    s32 connectionMode;
    u32 givenBits;
    RandomState64 *random;
    u8 character;
    u8 entry;
    u32 availableCount;
    u8 seen;
    u32 givenCharacter;
    s32 checkId;
    s32 pickedCharacter;
    s32 pick;
    u8 candidate;
    u64 firstTick;
    u64 secondTick;

    availableBits = 0;
    givenBits = picks->mCharacterGivenBits;
    useSharedRandom = FALSE;
    if (gConnectionWork == NULL) {
        connectionMode = CONNECTION_MODE_NONE;
    } else {
        connectionMode = gConnectionWork->mConnectionMode;
    }
    if (connectionMode != CONNECTION_MODE_NONE && gConnectionWork->mState != CONNECTION_STATE_ENDED) {
        useSharedRandom = TRUE;
    }
    if (useSharedRandom != FALSE) {
        random = &gConnectionWork->mRandomState;
    } else {
        firstTick = OS_GetTick();
        secondTick = OS_GetTick();
        localRandom.mValue = ((u32) firstTick << 24) + (u32) (secondTick >> 8);
        localRandom.mMultiplier = RANDOM_STATE64_MULTIPLIER;
        localRandom.mIncrement = RANDOM_STATE64_INCREMENT;
        random = &localRandom;
    }
    for (character = 0; character < 0xd; character++) {
        checkId = -1;
        if (character != CHARACTER_HEYHO) {
            switch (character) {
                case CHARACTER_KARON:
                    checkId = 0x14;
                    break;
                case CHARACTER_DAISY:
                    checkId = 0x15;
                    break;
                case CHARACTER_WALUIGI:
                    checkId = 0x16;
                    break;
                case CHARACTER_ROBO:
                    checkId = 0x17;
                    break;
            }
            if (checkId == -1 || IsBitSetInAllParticipants(checkId) != 0) {
                availableBits = availableBits | (1 << character);
            }
        }
    }
    for (entry = 0; entry < 8; entry++) {
        givenCharacter = picks->mCharacterIndices[entry];
        if (givenCharacter != -1 && BIT_IS_SET(givenBits, entry)) {
            availableBits = availableBits & ~(1 << givenCharacter);
        }
    }
    for (entry = 0; entry < 8; entry++) {
        pickedCharacter = -1;
        availableCount = CountSetBits(availableBits);
        seen = 0;
        if ((givenBits & (1 << entry)) == 0) {
            picks->mCharacterIndices[entry] = -1;
            if (availableCount == 0) {
                pick = seen;
            } else {
                random->mValue = random->mMultiplier * random->mValue + random->mIncrement;
                if (availableCount == 0) {
                    pick = random->mValue >> 32;
                } else {
                    pick = ((random->mValue >> 32) * availableCount) >> 32;
                }
            }
            for (candidate = 0; candidate < 0xd && pickedCharacter == -1; candidate++) {
                if (BIT_IS_SET(availableBits, candidate)) {
                    if (seen == (u16) pick) {
                        availableBits = availableBits & ~(1 << candidate);
                        pickedCharacter = candidate;
                    } else {
                        seen++;
                    }
                }
            }
            picks->mCharacterIndices[entry] = pickedCharacter;
        }
    }
}

#pragma thumb off

#pragma thumb on

void PickRandomCharactersAndKarts(CharacterKartPicks *picks) {
    PickRandomCharacters(picks);
    PickRandomKarts(picks);
}

#pragma thumb off
