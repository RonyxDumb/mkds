#pragma once

#include "types.h"

// How HideUnusedOams parks an entry: the x position bits of the first word (the second halfword) are replaced with an
// x that is right of the screen, and the y position goes below it.
#define OAM_ENTRY_X_MASK 0x1ff0000
#define OAM_ENTRY_HIDDEN_X 0x1800000
#define OAM_ENTRY_HIDDEN_Y 0xe0

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
