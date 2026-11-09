#pragma once

#include "types.h"

// Object func_020d6538 fills from 0x5c on; only the words it writes are seen.
typedef struct Unk020d6538_a {
    /* 00 */ u8 pad_00[0x5c];
    /* 5c */ u32 mUnk_5c;
    /* 60 */ u8 pad_60[4];
    /* 64 */ u32 mUnk_64;
    /* 68 */ u32 mUnk_68;
    /* 6c */ u32 mUnk_6c;
} Unk020d6538_a;

#include "Main/Unknown/code_020f36d8.h"
#include "code_02146d78.h"
#include "Main/Unknown/code_020e6fd4.h"

// 0x5c-byte object that CreateRock2DrawList and CreateRockDrawList allocate and fill from a table; SetDrawListSlot
// stores the address of its pointer at 0x28.
typedef struct RockDrawList {
    /* 00 */ MapObjectList mUnk_00;
    /* 28 */ struct RockDrawList **mListSlot;
    /* 2c */ MtxFx43 mShadowMatrix;
} RockDrawList;

#include "Main/Unknown/code_020d50ec.h" // EmitterParams, RockObject

void func_020d6538(Unk020d6538_a *emitter, EmitterParams *params);
void func_020d655c(void *a, RockObject *rock, void *c, s32 alpha);
void SetupDrawRock(void);
MapObjectList *CreateRockUpdateList(void);
RockDrawList *CreateRock2DrawList(void);
RockDrawList *CreateRockDrawList(void);
MapObjectKindData *CreateRockKindData(void);
s32 func_020d6910(s32 itemKind, MapObject *mapObject);
// 1 when the ItemObject kind a has a response to the map object b, else 0.
s32 DoesItemObjectRespondToMapObject(s32 itemKind, MapObject *mapObject);
// 1 when the Kart item effect a has a response to the map object b, else 0.
s32 DoesKartRespondToMapObject(s32 itemEffect, MapObject *mapObject);
// Response code for the ItemObject a and the map object b; the kind's own callback may change it; the second value goes
// to *c.
s32 func_020d6a54(ItemObject *itemObject, MapObject *mapObject, s32 *firstResponseOut);
// Index into gCollideKartWithMapObjectResponses of the Kart a response to the map object b; the kind's own callback may
// change it.
s32 func_020d6be0(Kart *kart, MapObject *mapObject);
u32 GetItemObjectResponseByKind(s32 flagBit, s32 itemKind, s32 kindHundreds, s32 kindRemainder, s32 kindDataValue);
u32 func_020d6d8c(u32 zeroResultFlag, u32 itemKind, u32 kindHundreds, u32 kindRemainder);
