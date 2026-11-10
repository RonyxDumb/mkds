#include "Main/Unknown/code_02116ec0.h"

#include "Main/Unknown/code_0203ba84.h"
#include "Main/Unknown/code_0203be88.h"
#include "Main/Unknown/unk_0215c000.h"
#include "Main/Unknown/code_02029000.h"
#include "Main/Unknown/code_02029440.h"
#include "Main/Unknown/code_0203b000.h"
#include "Main/Unknown/code_0203be48.h"
#include "Main/Unknown/unk_02175000.h"
#include "Main/Unknown/unk_0217a000.h"
#include "Main/Unknown/unk_0217d000.h"
#include "code_0202056c.h"
#include "Main/Unknown/code_02036820.h"

#pragma thumb on

void CreatePicksHolder(void *heap) {
    u32 v1;
    v1 = ((u32) HeapAlloc(heap, 4));
    *(u32 *) &gPicksHolder = v1;
    v1 = (u32) CreateCharacterKartPicks(heap);
    *(u32 *) (*(u32 *) &gPicksHolder) = v1;
}

#pragma thumb off

#pragma thumb on

void ClearPicksHolderPointer(void) {
    gPicksHolder = NULL;
}

// Resets the picks and clears the character index of every entry from the participant count up.
void ClearNonParticipantCharacterIndices(void) {
    int n;
    BOOL isEightOrNine;
    u32 zeroValue, noIndex;

    InitCharacterKartPicks(gPicksHolder->mPicks);
    if (data_021759d0->mConnectionKind == 0) {
        n = 1;
    } else {
        isEightOrNine = TRUE;
        if (gConnectionWork->mUnk_0004 != 8 && gConnectionWork->mUnk_0004 != 9) {
            isEightOrNine = FALSE;
        }
        n = (u8) (isEightOrNine != FALSE ? CountSetBits(gConnectionWork->mParticipantMask) : 0);
    }
    zeroValue = 0;
    noIndex = ~0;
    for (; n < 8; n++) {
        SetCharacterIndex(n, noIndex);
        func_020294ac(n, zeroValue);
    }
}

// Resets the picks, copies the characters in and clears the kart index of entries from the participant count up.
void ClearNonParticipantKartIndices(void) {
    int i;
    int n;
    BOOL isEightOrNine;
    u32 zeroValue, noIndex;

    InitCharacterKartPicks(gPicksHolder->mPicks);
    if (data_021759d0->mConnectionKind == 0) {
        n = 1;
    } else {
        isEightOrNine = TRUE;
        if (gConnectionWork->mUnk_0004 != 8 && gConnectionWork->mUnk_0004 != 9) {
            isEightOrNine = FALSE;
        }
        n = (u8) (isEightOrNine != FALSE ? CountSetBits(gConnectionWork->mParticipantMask) : 0);
    }
    for (i = 0; i < 8; i++) {
        SetGivenCharacter(gPicksHolder->mPicks, (u8) i, GetCharacterIndex(i));
    }
    zeroValue = 0;
    noIndex = ~0;
    for (; n < 8; n++) {
        SetKartIndex(n, noIndex);
        func_020294ac(n, zeroValue);
    }
}

void FillRandomCharacterIndices(void) {
    int i;
    int n;
    BOOL isEightOrNine;
    u32 pickedIndex;

    pickedIndex = ~0;
    if (data_021759d0->mConnectionKind == 0) {
        n = 1;
    } else {
        isEightOrNine = TRUE;
        if (gConnectionWork->mUnk_0004 != 8 && gConnectionWork->mUnk_0004 != 9) {
            isEightOrNine = FALSE;
        }
        n = (u8) (isEightOrNine != FALSE ? CountSetBits(gConnectionWork->mParticipantMask) : 0);
    }
    for (i = 0; i < n; i++) {
        SetGivenCharacter(gPicksHolder->mPicks, (u8) i, GetCharacterIndex(i));
    }
    PickRandomCharacters(gPicksHolder->mPicks);
    for (; n < 8; n++) {
        GetEntryCharacterAndKart(gPicksHolder->mPicks, n, &pickedIndex, NULL);
        SetCharacterIndex(n, pickedIndex);
    }
}

void FillRandomKartIndices(void) {
    int i;
    int n;
    BOOL isEightOrNine;
    u32 pickedIndex;

    pickedIndex = ~0;
    if (data_021759d0->mConnectionKind == 0) {
        n = 1;
    } else {
        isEightOrNine = TRUE;
        if (gConnectionWork->mUnk_0004 != 8 && gConnectionWork->mUnk_0004 != 9) {
            isEightOrNine = FALSE;
        }
        n = (u8) (isEightOrNine != FALSE ? CountSetBits(gConnectionWork->mParticipantMask) : 0);
    }
    for (i = 0; i < n; i++) {
        SetGivenKart(gPicksHolder->mPicks, (u8) i, GetKartIndex(i));
    }
    PickRandomKarts(gPicksHolder->mPicks);
    for (; n < 8; n++) {
        GetEntryCharacterAndKart(gPicksHolder->mPicks, n, NULL, &pickedIndex);
        SetKartIndex(n, pickedIndex);
        func_020294ac(n, 1);
    }
}

void SetKartIndicesFromCharacters(void) {
    int i;

    for (i = 0; i < 8; i++) {
        SetKartIndex(i, gCharacterKartIndices[GetCharacterIndex(i)]);
        func_020294ac(i, 1);
    }
}

#pragma thumb off
