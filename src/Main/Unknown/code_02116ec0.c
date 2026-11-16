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
#include "Main/System/Heap.h"

#pragma thumb on

void AllocSinglePlayerMenuInfo(void *heap) {
    u32 v1;
    v1 = ((u32) heap_alloc(heap, 4));
    *(u32 *) &SinglePlayerMenuInfoPointer = v1;
    v1 = (u32) func_0203bedc(heap);
    *(u32 *) (*(u32 *) &SinglePlayerMenuInfoPointer) = v1;
}

#pragma thumb off

#pragma thumb on

void FreeSinglePlayerMenuInfo(void) {
    SinglePlayerMenuInfoPointer = NULL;
}

void func_021170f8(void) {
    int n;
    BOOL isEightOrNine;
    u32 zeroValue, noIndex;

    InitCharacterKartPicks(SinglePlayerMenuInfoPointer->mPicks);
    if (gSystemData->mUnk_20 == 0) {
        n = 1;
    } else {
        isEightOrNine = TRUE;
        if (gStruct217AA00->mUnk_0004 != 8 && gStruct217AA00->mUnk_0004 != 9) {
            isEightOrNine = FALSE;
        }
        n = (u8) (isEightOrNine != FALSE ? MATH_CountPopulation(gStruct217AA00->mParticipantMask) : 0);
    }
    zeroValue = 0;
    noIndex = ~0;
    for (; n < 8; n++) {
        SPM_SetDriverXCharacterID(n, noIndex);
        func_020294ac(n, zeroValue);
    }
}

void func_02117060(void) {
    int i;
    int n;
    BOOL isEightOrNine;
    u32 zeroValue, noIndex;

    InitCharacterKartPicks(SinglePlayerMenuInfoPointer->mPicks);
    if (gSystemData->mUnk_20 == 0) {
        n = 1;
    } else {
        isEightOrNine = TRUE;
        if (gStruct217AA00->mUnk_0004 != 8 && gStruct217AA00->mUnk_0004 != 9) {
            isEightOrNine = FALSE;
        }
        n = (u8) (isEightOrNine != FALSE ? MATH_CountPopulation(gStruct217AA00->mParticipantMask) : 0);
    }
    for (i = 0; i < 8; i++) {
        SetGivenCharacter(SinglePlayerMenuInfoPointer->mPicks, (u8) i, SPM_GetDriverXCharacterID(i));
    }
    zeroValue = 0;
    noIndex = ~0;
    for (; n < 8; n++) {
        SPM_SetDriverXKartID(n, noIndex);
        func_020294ac(n, zeroValue);
    }
}

void SPM_2116FB0(void) {
    int i;
    int n;
    BOOL isEightOrNine;
    u32 pickedIndex;

    pickedIndex = ~0;
    if (gSystemData->mUnk_20 == 0) {
        n = 1;
    } else {
        isEightOrNine = TRUE;
        if (gStruct217AA00->mUnk_0004 != 8 && gStruct217AA00->mUnk_0004 != 9) {
            isEightOrNine = FALSE;
        }
        n = (u8) (isEightOrNine != FALSE ? MATH_CountPopulation(gStruct217AA00->mParticipantMask) : 0);
    }
    for (i = 0; i < n; i++) {
        SetGivenCharacter(SinglePlayerMenuInfoPointer->mPicks, (u8) i, SPM_GetDriverXCharacterID(i));
    }
    PickRandomCharacters(SinglePlayerMenuInfoPointer->mPicks);
    for (; n < 8; n++) {
        GetEntryCharacterAndKart(SinglePlayerMenuInfoPointer->mPicks, n, &pickedIndex, NULL);
        SPM_SetDriverXCharacterID(n, pickedIndex);
    }
}

void FillRandomKartIndices(void) {
    int i;
    int n;
    BOOL isEightOrNine;
    u32 pickedIndex;

    pickedIndex = ~0;
    if (gSystemData->mUnk_20 == 0) {
        n = 1;
    } else {
        isEightOrNine = TRUE;
        if (gStruct217AA00->mUnk_0004 != 8 && gStruct217AA00->mUnk_0004 != 9) {
            isEightOrNine = FALSE;
        }
        n = (u8) (isEightOrNine != FALSE ? MATH_CountPopulation(gStruct217AA00->mParticipantMask) : 0);
    }
    for (i = 0; i < n; i++) {
        SetGivenKart(SinglePlayerMenuInfoPointer->mPicks, (u8) i, SPM_GetDriverXKartID(i));
    }
    PickRandomKarts(SinglePlayerMenuInfoPointer->mPicks);
    for (; n < 8; n++) {
        GetEntryCharacterAndKart(SinglePlayerMenuInfoPointer->mPicks, n, NULL, &pickedIndex);
        SPM_SetDriverXKartID(n, pickedIndex);
        func_020294ac(n, 1);
    }
}

void SetKartIndicesFromCharacters(void) {
    int i;

    for (i = 0; i < 8; i++) {
        SPM_SetDriverXKartID(i, data_0215c5d8[SPM_GetDriverXCharacterID(i)]);
        func_020294ac(i, 1);
    }
}

#pragma thumb off
