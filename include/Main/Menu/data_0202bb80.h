#pragma once
#include "types.h"

typedef struct CellFileSet CellFileSet;

typedef struct PlayerEntryList PlayerEntryList;

// 6-byte elements of the table behind gEntryCellIndices: three indices into the arrays at member 0x18 of
// CellFileSet.
typedef struct EntryCellIndices {
    /* 00 */ u16 mEntryCellIndex;
    /* 02 */ u16 mCharacterCellIndex;
    /* 04 */ u16 mKartCellIndex;
} EntryCellIndices;

// 8-byte elements of the table behind gEntryLabelTextRows.
typedef struct EntryLabelTextRow {
    /* 00 */ s16 mLabelIndex;
    /* 02 */ u8 mUnk_02[6];
} EntryLabelTextRow;
