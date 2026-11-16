#pragma once

#include "types.h"
#include "code_02146d78.h"
#include "Main/Unknown/code_020e6fd4.h"

// Object of AdvancePooledMapObject (AllocPooledMapObject allocates them): the shared MapObject part, then counters that
// run and wrap and whose three fixed-point words follow the vector at fieldFC.
typedef struct PooledMapObject {
    /* 00 */ MapObject field0;
    /* a0 */ u16 fieldA0;
    /* a2 */ u16 fieldA2;
    /* a4 */ u16 fieldA4;
    /* a6 */ u8 fieldA6[0xa];
    /* b0 */ u16 fieldB0;
    /* b2 */ u8 fieldB2[0x4a];
    /* fc */ Vec3 *fieldFC;
    /* 100 */ void *field100;
    /* 104 */ void *field104;
} PooledMapObject;

void SetPooledMapObjectFromItem(PooledMapObject *object, s32 alpha, Vec3 *scale);
void AdvancePooledMapObject(PooledMapObject *object);
