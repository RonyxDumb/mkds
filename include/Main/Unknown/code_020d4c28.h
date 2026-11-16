#pragma once

#include "types.h"
#include "Main/Unknown/code_020e6b58.h"
#include "Main/Unknown/code_020f36d8.h"
#include "code_02146d78.h"
#include "Main/Unknown/code_020e6fd4.h"

// Object mobj_updateCameraVectors reads: a vector at 0x24.
typedef struct Unk020d4f94 {
    /* 00 */ u8 field0[0x24];
    /* 24 */ Vec3 field24;
} Unk020d4f94;

void mobj_updateCameraVectors(Unk020d4f94 *viewMatrix);
u32 mobj_20D4F34(Vec3 *position, s32 b, s32 c, s32 distanceLimitSquared);
s32 mobj_calcXZCamDist(Vec3 *position);
void StructMQRacerEntry_SomeFn_91(ItemObject *itemObject, Vec3 *position, u32 distanceAndFlags);
BOOL mobj_isInaudible(MapObject *mapObject);
BOOL mobj_calcInaudible(MapObject *mapObject, s32 distanceSquared);
void mobj_20D4D44(MtxFx43 *viewMatrix);
void mobj_renderRenderPart(MapObjectList *list, MtxFx43 *viewMatrix);
