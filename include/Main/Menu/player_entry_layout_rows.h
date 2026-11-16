#pragma once
#include "types.h"

typedef struct CellFileSet CellFileSet;

typedef struct PlayerEntryList PlayerEntryList;

// The cell indices of one player entry: the entry, its character and its kart, in the table behind gEntryCellIndices.
typedef struct EntryCellIndices {
    /* 00 */ u16 mEntryCellIndex;
    /* 02 */ u16 mCharacterCellIndex;
    /* 04 */ u16 mKartCellIndex;
} EntryCellIndices;

// One label text row of a player entry: its label index, size and entry index, in the table behind gEntryLabelTextRows.
typedef struct EntryLabelTextRow {
    /* 00 */ s16 mLabelIndex;
    /* 02 */ u16 mWidth;
    /* 04 */ u16 mHeight;
    /* 06 */ s16 mEntryIndex;
} EntryLabelTextRow;
