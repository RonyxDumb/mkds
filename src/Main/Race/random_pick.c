#include "Main/Race/random_pick.h"
#include "Main/Save/buddy_record_time.h"
#include "Main/MapObjects/map_object_park.h"
#include "Main/MapObjects/data_0217a000.h"
#include "os_tick.h"
#include "code_0202056c.h"

#pragma thumb on

void PickRandomKarts(CharacterKartPicks *picks) {
    RandomState64 localRandom;
    u32 givenBits;
    u8 entry;
    RandomState64 *random;
    u8 kartOffset;
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
        localRandom.mMultiplier = 0x5d588b656c078965;
        localRandom.mIncrement = 0x269ec3;
        random = &localRandom;
    }
    for (entry = 0; entry < 8; entry++) {
        kart = -1;
        character = picks->mCharacterIndices[entry];
        candidateBits = 0;
        if ((givenBits & (1 << entry)) == 0) {
            picks->mKartIndices[entry] = -1;
            kartOffset = 0;
            firstKart = character * 3;
            for (; kartOffset < 3; kartOffset++) {
                if (IsKartAppearWithinParticipantLimit(picks->mKartAppear, character, kartOffset + firstKart) !=
                    FALSE) {
                    candidateBits = candidateBits | (1 << kartOffset);
                }
            }
            for (kartOffset = 0; kartOffset < 8; kartOffset++) {
                if ((givenBits & (1 << kartOffset)) != 0 && picks->mKartIndices[kartOffset] >= firstKart &&
                    picks->mKartIndices[kartOffset] < (character + 1) * 3) {
                    candidateBits = candidateBits & ~(1 << (picks->mKartIndices[kartOffset] - firstKart));
                }
            }
            if (candidateBits == 0) {
                for (kartOffset = 0; kartOffset < 3; kartOffset++) {
                    if (IsKartAppearWithinParticipantLimit(picks->mKartAppear, character, kartOffset + firstKart) !=
                        FALSE) {
                        candidateBits = candidateBits | (1 << kartOffset);
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
            for (kartOffset = 0; kartOffset < 3 && kart == -1; kartOffset++) {
                if ((candidateBits & (1 << kartOffset)) != 0) {
                    if (seen == (u16) pick) {
                        kart = kartOffset + firstKart;
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
        localRandom.mMultiplier = 0x5d588b656c078965;
        localRandom.mIncrement = 0x269ec3;
        random = &localRandom;
    }
    for (character = 0; character < 0xd; character++) {
        checkId = -1;
        if (character != 0xc) {
            switch (character) {
                case 8:
                    checkId = 0x14;
                    break;
                case 9:
                    checkId = 0x15;
                    break;
                case 10:
                    checkId = 0x16;
                    break;
                case 11:
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
        if (givenCharacter != -1 && (givenBits & (1 << entry)) != 0) {
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
                if ((availableBits & (1 << candidate)) != 0) {
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
