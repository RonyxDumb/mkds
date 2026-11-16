#pragma once

#include "types.h"

// Three 64-bit words: x, a and c of x = x * a + c (x = x * [8] + [0x10] in TallyPickedCourse). mobj_getSafeRng and
// mobj_getRng1 return one; ConnectionWork has one at 0x1ee8, RaceProgress three and WiFiSession one at 0x1954.
typedef struct RandomState64 {
    /* 00 */ u64 mValue;
    /* 08 */ u64 mMultiplier;
    /* 10 */ u64 mIncrement;
} RandomState64;

typedef struct MapObject MapObject;

RandomState64 *mobj_getSafeRng(void);
RandomState64 *mobj_getRng1(void);
void mobj_initRng(void);
void mobj_setVisible(MapObject *mapObject);
void mobj_setInvisible(MapObject *mapObject);
