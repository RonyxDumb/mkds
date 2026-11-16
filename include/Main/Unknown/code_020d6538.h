#pragma once

#include "types.h"

// Object func_020d6538 fills from 0x5c on; only the words it writes are seen.
typedef struct Unk020d6538_a {
    /* 00 */ u8 pad_00[0x5c];
    /* 5c */ u32 field5C;
    /* 60 */ u8 pad_60[4];
    /* 64 */ u32 field64;
    /* 68 */ u32 field68;
    /* 6c */ u32 field6C;
} Unk020d6538_a;

#include "Main/Unknown/code_020f36d8.h"
#include "code_02146d78.h"
#include "Main/Unknown/code_020e6fd4.h"

// Second half of the 0x5c-byte object behind data_0217b650: the words from 0x2c, then three more.
typedef struct RockShadowMatrix {
    /* 00 */ s32 field0[9];
    /* 24 */ Vec3 field24;
} RockShadowMatrix;

// 0x5c-byte object that rock_setupRock2RenderPart and rock_setupRockRenderPart allocate and fill from a table; mobj_renderPartSetThisPointer stores
// the address of its pointer at 0x28.
typedef struct RockDrawList {
    /* 00 */ u8 field0[0x28];
    /* 28 */ struct RockDrawList **field28;
    /* 2c */ RockShadowMatrix field2C;
} RockDrawList;

// 0x28-byte object that rock_setupLogicPart allocates and fills from a table; mobj_logicPartSetThisPointer stores the address of
// its pointer at 0x24.
typedef struct RockUpdateList {
    /* 00 */ u8 field0[0x24];
    /* 24 */ struct RockUpdateList **field24;
} RockUpdateList;

#include "Main/Unknown/code_020d50ec.h" // EmitterParams, RockObject

void func_020d6538(Unk020d6538_a *emitter, EmitterParams *params);
void rock_render(void *a, RockObject *rock, void *c, s32 alpha);
void roak_globalPreRender(void);
RockUpdateList *rock_setupLogicPart(void);
RockDrawList *rock_setupRock2RenderPart(void);
RockDrawList *rock_setupRockRenderPart(void);
MapObjectKindData *rock_setupConfig(void);
s32 mobj_getItemHitObjResponseForMObj(s32 itemKind, MapObject *mapObject);
// 1 when the ItemObject kind a has a response to the map object b, else 0.
s32 mobj_getCollidesWithItem(s32 itemKind, MapObject *mapObject);
// 1 when the Kart item effect a has a response to the map object b, else 0.
s32 mobj_getCollidesWithDriver(s32 itemEffect, MapObject *mapObject);
// Response code for the ItemObject a and the map object b; the kind's own callback may change it; the second value goes
// to *c.
s32 mobj_handleItemCollision(ItemObject *itemObject, MapObject *mapObject, s32 *firstResponseOut);
// Index into driver_sColReactionInitTable of the Kart a response to the map object b; the kind's own callback may
// change it.
s32 mobj_handleDriverCollision(Kart *kart, MapObject *mapObject);
u32 mobj_getItemHitResponse(s32 flagBit, s32 itemKind, s32 kindHundreds, s32 kindRemainder, s32 kindDataValue);
u32 mobj_getItemHitObjResponse(u32 zeroResultFlag, u32 itemKind, u32 kindHundreds, u32 kindRemainder);
