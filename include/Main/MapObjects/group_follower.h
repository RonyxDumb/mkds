#pragma once

#include "types.h"

// Object CopyEmitterParams fills from 0x5c on; only the words it writes are seen.
typedef struct Unk020d6538_a {
    /* 00 */ u8 mUnk_00[0x5c];
    /* 5c */ u32 mUnk_5c;
    /* 60 */ u8 mUnk_60[4];
    /* 64 */ u32 mUnk_64;
    /* 68 */ u32 mUnk_68;
    /* 6c */ u32 mUnk_6c;
} Unk020d6538_a;

#include "Main/Race/data_020f36d8.h"
#include "fx_mtx33.h"
#include "Main/MapObjects/attractor.h"

// 0x5c-byte object that CreateRock2DrawList and CreateRockDrawList allocate and fill from a table; SetDrawListSlot
// stores the address of its pointer at 0x28.
typedef struct RockDrawList {
    /* 00 */ MapObjectList mMapObjectList;
    /* 28 */ struct RockDrawList **mListSlot;
    /* 2c */ MtxFx43 mShadowMatrix;
} RockDrawList;

#include "Main/MapObjects/rock.h" // EmitterParams, RockObject
#include "code_0201c528.h"
#include "Main/Kart/shadow_model.h"
#include "Main/Graphics/nsbmd_render_obj.h"
#include "Main/MapObjects/code_020d6dc0.h"

void CopyEmitterParams(ParticleEmitter *emitter, EmitterParams *params);
void DrawRock(void *unused0, RockObject *rock, void *unused1, s32 alpha);
void SetupDrawRock(void);
MapObjectList *CreateRockUpdateList(void);
MapObjectList *CreateRock2DrawList(void);
MapObjectList *CreateRockDrawList(void);
MapObjectKindData *CreateRockKindData(void);
s32 GetItemObjectFirstResponse(s32 itemKind, MapObject *mapObject);
// 1 when the ItemObject kind a has a response to the map object b, else 0.
s32 DoesItemObjectRespondToMapObject(s32 itemKind, MapObject *mapObject);
// 1 when the Kart item effect a has a response to the map object b, else 0.
s32 DoesKartRespondToMapObject(s32 itemEffect, MapObject *mapObject);
// Response code for the ItemObject a and the map object b; the kind's own callback may change it; the second value goes
// to *c.
s32 CollideItemObjectWithMapObject(ItemObject *itemObject, MapObject *mapObject, s32 *firstResponseOut);
// Index into gCollideKartWithMapObjectResponses of the Kart a response to the map object b; the kind's own callback may
// change it.
s32 CollideKartWithMapObject(Kart *kart, MapObject *mapObject);
u32 GetItemObjectResponseByKind(s32 flagBit, s32 itemKind, s32 kindHundreds, s32 kindRemainder, s32 kindDataValue);
u32 GetItemObjectFirstResponseByKind(u32 zeroResultFlag, u32 itemKind, u32 kindHundreds, u32 kindRemainder);

extern const struct MapObjectList gRockUpdateListData;
extern const struct RockDrawList gRock2DrawListData;
extern const struct RockDrawList gRockDrawListData;
extern struct ShadowModel *gRockShadow;
extern struct Nsbmd *gRock;
extern struct RockDrawList *gRockDrawList;
extern struct Quaternion gViewYawQuaternion;
extern struct MapObjectList *gRockUpdateList;
