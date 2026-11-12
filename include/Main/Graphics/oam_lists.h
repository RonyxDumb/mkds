#pragma once

#include "types.h"

// Element of 8 bytes of OamEntryList.mUnk_00.
typedef struct OamListEntry {
    /* 00 */ union {
        u32 mUnk_00;
        u8 mYPos;
    };
    /* 04 */ u32 mUnk_04;
} OamListEntry;

// Object of 0x404 bytes: 0x80 elements of 8 bytes, then two halfwords.
typedef struct OamEntryList {
    /* 000 */ OamListEntry mEntries[0x80];
    /* 400 */ u16 mOamCount;
    /* 402 */ u16 mMatrixCount;
} OamEntryList;

void HideUnusedOams(void *mainOam, void *subOam);
void ClearOamListCounts(void *mainOam, void *subOam);
void ResetOamLists(void *mainOam, void *subOam);
