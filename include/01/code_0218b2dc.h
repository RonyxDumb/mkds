#pragma once

#include "types.h"
#include "01/code_02188950.h"

typedef struct Unk02188950 Unk02188950;
typedef struct Unk021a7b64 Unk021a7b64;
typedef struct Unk0218d87c Unk0218d87c;

extern Unk021a7b64 gKurikingMObjDef;

void *kking_setupLogicPart(void);
void *kking_setupRenderPart(void);
void kking_setupCollision(void);
void RenderKuriking(
    void *mapObjectList,
    Unk02188950 *mapObject); /* only calls the two draw helpers shared with five other ov001 draw callbacks */
void LoadKuriking(Unk0218d87c *mapObjectList);
void UpdateKuriking(u32 a, Unk02188950 *mapObject); /* skipped for objects with mFlags & 4 (parked pool objects) */
void InitKurikingObjects(Unk0218d87c *mapObjectList);
void func_ov001_0218b640(Unk02188950 *mapObject, void *kart);
void func_ov001_0218b6f8(Unk02188950 *mapObject, void *kart);
void kking_init(Unk02188950 *mapObject);
void func_ov001_0218b770(Unk02188950 *mapObject);
void func_ov001_0218b7a4(Unk02188950 *mapObject);
void func_ov001_0218b7c8(Unk02188950 *mapObject);
void func_ov001_0218b7fc(Unk02188950 *mapObject);
void func_ov001_0218b828(Unk02188950 *mapObject);
s32 func_ov001_0218b850(Unk02188950 *mapObject);
s32 func_ov001_0218b8d4(Unk02188950 *mapObject);
void func_ov001_0218b8f0(void);
void func_ov001_0218b8f8(Unk02188950 *mapObject);
void func_ov001_0218b928(Unk02188950 *mapObject);
