#include "Main/Menu/picks_holder.h"

#include "Main/Unknown/code_0203ba84.h"
#include "Main/Menu/title_scene.h"
#include "Main/Unknown/unk_0215c000.h"
#include "Main/Unknown/code_02029000.h"
#include "Main/Race/race_setup.h"
#include "Main/Unknown/code_0203b000.h"
#include "Main/Race/entry_character_kart.h"
#include "Main/Unknown/unk_02175000.h"
#include "Main/Unknown/unk_0217a000.h"
#include "Main/Unknown/unk_0217d000.h"
#include "code_0202056c.h"
#include "Main/System/heap.h"

#pragma thumb on

void CreatePicksHolder(void *heap) {
    u32 value;
    value = ((u32) HeapAlloc(heap, 4));
    *(u32 *) &gPicksHolder = value;
    value = (u32) CreateCharacterKartPicks(heap);
    *(u32 *) (*(u32 *) &gPicksHolder) = value;
}

#pragma thumb off

#pragma thumb on

void ClearPicksHolderPointer(void) {
    gPicksHolder = NULL;
}

// Resets the picks and clears the character index of every entry from the participant count up.
void ClearNonParticipantCharacterIndices(void) {
    int participantCount;
    BOOL isEightOrNine;
    u32 zeroValue, noIndex;

    InitCharacterKartPicks(gPicksHolder->mPicks);
    if (gStartupWork->mConnectionKind == 0) {
        participantCount = 1;
    } else {
        isEightOrNine = TRUE;
        if (gConnectionWork->mState != 8 && gConnectionWork->mState != 9) {
            isEightOrNine = FALSE;
        }
        participantCount = (u8) (isEightOrNine != FALSE ? CountSetBits(gConnectionWork->mParticipantMask) : 0);
    }
    zeroValue = 0;
    noIndex = ~0;
    for (; participantCount < 8; participantCount++) {
        SetCharacterIndex(participantCount, noIndex);
        SetKartStored(participantCount, zeroValue);
    }
}

// Resets the picks, copies the characters in and clears the kart index of entries from the participant count up.
void ClearNonParticipantKartIndices(void) {
    int entryIndex;
    int participantCount;
    BOOL isEightOrNine;
    u32 zeroValue, noIndex;

    InitCharacterKartPicks(gPicksHolder->mPicks);
    if (gStartupWork->mConnectionKind == 0) {
        participantCount = 1;
    } else {
        isEightOrNine = TRUE;
        if (gConnectionWork->mState != 8 && gConnectionWork->mState != 9) {
            isEightOrNine = FALSE;
        }
        participantCount = (u8) (isEightOrNine != FALSE ? CountSetBits(gConnectionWork->mParticipantMask) : 0);
    }
    for (entryIndex = 0; entryIndex < 8; entryIndex++) {
        SetGivenCharacter(gPicksHolder->mPicks, (u8) entryIndex, GetCharacterIndex(entryIndex));
    }
    zeroValue = 0;
    noIndex = ~0;
    for (; participantCount < 8; participantCount++) {
        SetKartIndex(participantCount, noIndex);
        SetKartStored(participantCount, zeroValue);
    }
}

void FillRandomCharacterIndices(void) {
    int participantIndex;
    int participantCount;
    BOOL isEightOrNine;
    u32 pickedIndex;

    pickedIndex = ~0;
    if (gStartupWork->mConnectionKind == 0) {
        participantCount = 1;
    } else {
        isEightOrNine = TRUE;
        if (gConnectionWork->mState != 8 && gConnectionWork->mState != 9) {
            isEightOrNine = FALSE;
        }
        participantCount = (u8) (isEightOrNine != FALSE ? CountSetBits(gConnectionWork->mParticipantMask) : 0);
    }
    for (participantIndex = 0; participantIndex < participantCount; participantIndex++) {
        SetGivenCharacter(gPicksHolder->mPicks, (u8) participantIndex, GetCharacterIndex(participantIndex));
    }
    PickRandomCharacters(gPicksHolder->mPicks);
    for (; participantCount < 8; participantCount++) {
        GetEntryCharacterAndKart(gPicksHolder->mPicks, participantCount, &pickedIndex, NULL);
        SetCharacterIndex(participantCount, pickedIndex);
    }
}

void FillRandomKartIndices(void) {
    int participantIndex;
    int participantCount;
    BOOL isEightOrNine;
    u32 pickedIndex;

    pickedIndex = ~0;
    if (gStartupWork->mConnectionKind == 0) {
        participantCount = 1;
    } else {
        isEightOrNine = TRUE;
        if (gConnectionWork->mState != 8 && gConnectionWork->mState != 9) {
            isEightOrNine = FALSE;
        }
        participantCount = (u8) (isEightOrNine != FALSE ? CountSetBits(gConnectionWork->mParticipantMask) : 0);
    }
    for (participantIndex = 0; participantIndex < participantCount; participantIndex++) {
        SetGivenKart(gPicksHolder->mPicks, (u8) participantIndex, GetKartIndex(participantIndex));
    }
    PickRandomKarts(gPicksHolder->mPicks);
    for (; participantCount < 8; participantCount++) {
        GetEntryCharacterAndKart(gPicksHolder->mPicks, participantCount, NULL, &pickedIndex);
        SetKartIndex(participantCount, pickedIndex);
        SetKartStored(participantCount, 1);
    }
}

void SetKartIndicesFromCharacters(void) {
    int entryIndex;

    for (entryIndex = 0; entryIndex < 8; entryIndex++) {
        SetKartIndex(entryIndex, gCharacterKartIndices[GetCharacterIndex(entryIndex)]);
        SetKartStored(entryIndex, 1);
    }
}

#pragma thumb off
