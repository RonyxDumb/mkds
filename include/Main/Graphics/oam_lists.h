#pragma once

#include "types.h"

// How OamBuffer_SomeFn2_from_thumb parks an entry: the x position bits of the first word (the second halfword) are replaced with an
// x that is right of the screen, and the y position goes below it.
#define OAM_ENTRY_X_MASK 0x1ff0000
#define OAM_ENTRY_HIDDEN_X 0x1800000
#define OAM_ENTRY_HIDDEN_Y 0xe0

// One OAM entry of an OamEntryList; mYPos is its y position.
typedef struct OamListEntry {
    /* 00 */ union {
        u32 mUnk_00;
        u8 mYPos;
    };
    /* 04 */ u32 mUnk_04;
} OamListEntry;

// A list of OAM entries with the number of entries and of matrices in use.
typedef struct OamEntryList {
    /* 000 */ OamListEntry mEntries[0x80];
    /* 400 */ u16 mOamCount;
    /* 402 */ u16 mMatrixCount;
} OamEntryList;

void OamBuffer_SomeFn2_from_thumb(void *mainOam, void *subOam);
void OamBuffer_ResetValues16_from_thumb(void *mainOam, void *subOam);
void OamBuffer_SomeFn_from_thumb(void *mainOam, void *subOam);
