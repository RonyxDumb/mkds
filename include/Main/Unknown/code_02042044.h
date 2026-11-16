#pragma once

#include "types.h"

// One entry of the table returned by mdat_getPathPoint.
typedef struct CourseMapGroupEntry {
    /* 00 */ Vec3 mPos;
    /* 0c */ u8 fieldC;
    /* 0d */ u8 fieldD;
    /* 0e */ s16 fieldE;
    /* 10 */ s16 field10;
    /* 12 */ s16 field12;
} CourseMapGroupEntry;

CourseMapGroupEntry *mdat_getPathPoint(u16 groupIndex, u16 entryIndex);
