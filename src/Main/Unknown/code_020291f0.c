#include "Main/Unknown/code_020291f0.h"
#include "Main/Unknown/code_02025e28.h"
#include "Main/Unknown/code_02025000.h"
#include "Main/Unknown/code_02025bb4.h"
#include "Main/Unknown/code_02025df4.h"
#include "Main/Unknown/code_02028774.h"
#include "Main/Unknown/code_0202881c.h"
#include "Main/Unknown/code_02027e78.h"
#include "Main/Unknown/code_0202b000.h"
#include "Main/Unknown/code_0205ee14.h"
#include "Main/Unknown/unk_02174000.h"
#include "Main/Unknown/code_02025da4.h"
#include "Main/Unknown/code_0202a820.h"
#include "Main/Unknown/code_0202b604.h"

#pragma optimize_for_size on

#pragma thumb on

void StartSelectKartEntryListKindIfUsed(s32 kind) {
    if (gSelectKart->mEntryListUsed != FALSE) {
        StartPlayerEntryListKind(kind);
    }
}

void SetSelectKartPositionDigits(void) {
    s32 kartPosition;
    s32 kartCount;
    SelectKart *selectKart;
    CellFileSet *gpMParts;
    if (func_020280dc() == 0) {
        selectKart = gSelectKart;
        kartPosition = GetKartPositionWithinAppearLimit(selectKart->mKartAppear, selectKart->mCharacterIndex,
                                                        selectKart->mKartIndex);
        kartCount = CountKartsWithinAppearLimit(gSelectKart->mKartAppear, gSelectKart->mCharacterIndex);
        selectKart = gSelectKart;
        if (selectKart->mEntryListUsed != FALSE) {
            WriteKartPositionAndCount(kartPosition, kartCount);
        } else {
            gpMParts = &selectKart->mSelectCharacterGpMParts;
            gpMParts->mCellTable[5].mVisible = (kartPosition >= 10);
            CopyCellLayoutEntryCellIndex(5, kartPosition / 10 % 10 + 10, gpMParts->mCellLayout);
            CopyCellLayoutEntryCellIndex(6, kartPosition % 10 + 10, gpMParts->mCellLayout);
            if (kartCount >= 10) {
                CopyCellLayoutEntryCellIndex(8, kartCount / 10 % 10 + 20, gpMParts->mCellLayout);
                CopyCellLayoutEntryCellIndex(9, kartCount % 10 + 20, gpMParts->mCellLayout);
            } else {
                gpMParts->mCellTable[9].mVisible = 0;
                CopyCellLayoutEntryCellIndex(8, kartCount % 10 + 20, gpMParts->mCellLayout);
            }
        }
    }
}

void MoveSelectKartNext(void) {
    SelectKart *d;
    s32 index;
    index = gSelectKart->mKartTableIndex + 1;
    if (index >= 0x24) {
        index = 0;
    }
    while (d = gSelectKart, index != d->mKartTableIndex) {
        if (IsKartAppearWithinLimit(d->mKartAppear, d->mCharacterIndex, GetKartIndexAtTableIndex(index)) != 0) {
            gSelectKart->mKartTableIndex = index;
            gSelectKart->mKartIndex = GetKartIndexAtTableIndex(gSelectKart->mKartTableIndex);
        } else {
            index++;
            if (index >= 0x24) {
                index = 0;
            }
        }
    }
    SetSelectKartPositionDigits();
}

void MoveSelectKartPrev(void) {
    SelectKart *d;
    s32 index;
    index = gSelectKart->mKartTableIndex - 1;
    if (index < 0) {
        index = 0x23;
    }
    while (d = gSelectKart, index != d->mKartTableIndex) {
        if (IsKartAppearWithinLimit(d->mKartAppear, d->mCharacterIndex, GetKartIndexAtTableIndex(index)) != 0) {
            gSelectKart->mKartTableIndex = index;
            gSelectKart->mKartIndex = GetKartIndexAtTableIndex(gSelectKart->mKartTableIndex);
        } else {
            index--;
            if (index < 0) {
                index = 0x23;
            }
        }
    }
    SetSelectKartPositionDigits();
}

#pragma thumb off

u32 SelectKartHasPairOrLost(InputSlotPair *pair) {
    u32 result;

    if (SelectKartIsPairRecentlyLost(pair) != 0 || SelectKartGetPairHasPair(pair) != 0) {
        result = 1;
    } else {
        result = 0;
    }
    return result;
}

u32 SelectKartSlotHasPairOrLost(u32 slot) {
    return SelectKartHasPairOrLost(&gInputSlots[slot].mPair);
}
