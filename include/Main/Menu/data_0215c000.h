#pragma once
#include "types.h"

typedef struct KartIconRow {
    /* 00 */ u16 mBnclIndex;
    /* 02 */ u16 mUnk_02;
    /* 04 */ u32 mNclrIndex;
    /* 08 */ u16 mNclrStart;
    /* 0a */ u16 mUnk_0a;
} KartIconRow;

extern u16 gSelectCupGridCupCellIndices[4][6];

extern u32 gSelectCupGridCourseIds[8][4];
