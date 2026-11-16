#pragma once

#include "types.h"
#include "code_02146d78.h"
#include "Main/Unknown/code_020e6fd4.h" // MapObject, MapObjectList

typedef struct ItemObject ItemObject;

// Object up to 0x109 bytes.
typedef struct CoverPooHole {
    /* 00 */ MapObject field0;
    /* a0 */ s32 fieldA0;
    /* a4 */ s32 fieldA4;
    /* a8 */ s32 fieldA8;
    /* ac */ s32 mTimer;
    /* b0 */ s32 mState;
    /* b4 */ s32 fieldB4;
    /* b8 */ s32 fieldB8;
    /* bc */ s32 fieldBC;
    /* c0 */ s32 fieldC0;
    /* c4 */ u16 fieldC4;
    /* c6 */ u8 fieldC6[2];
    /* c8 */ s32 fieldC8;
    /* cc */ s32 fieldCC;
    /* d0 */ s32 fieldD0;
    /* d4 */ s32 fieldD4;
    /* d8 */ s32 fieldD8;
    /* dc */ s32 fieldDC;
    /* e0 */ s32 fieldE0;
    /* e4 */ u16 fieldE4;
    /* e6 */ u8 fieldE6[2];
    /* e8 */ s32 fieldE8;
    /* ec */ s32 fieldEC;
    /* f0 */ s32 fieldF0;
    /* f4 */ s32 fieldF4;
    /* f8 */ s32 fieldF8;
    /* fc */ s32 fieldFC;
    /* 100 */ s32 field100;
    /* 104 */ s32 field104;
    /* 108 */ u8 field108;
} CoverPooHole;

#include "Main/Unknown/unk_0217b000.h" // Unk0217b498_00
#include "Main/Unknown/code_0206bcb0.h" // Kart

BOOL poo_2095F38(Unk0217b498_00 *a);
void *poo_setupLogicPart(void);
void *poo_setupRenderPart(void);
void poo_setupConfig(void);
void poo_update(void *a,
                        CoverPooHole *coverPooHole); /* skipped for objects with mFlags & 4 (parked pool objects) */
s32 poo_FX_MulInline(s32 a, s32 b);
s32 poo_FX_SinIdx(s32 a);
void poo_globalLogicInit(MapObjectList *mapObjectList);
void poo_render(void *a, CoverPooHole *coverPooHole);
void poo_loadModels(void *a);
BOOL poo_collide(CoverPooHole *coverPooHole, const Vec3 *position, s32 radius, Vec3 *pushOut);
u32 poo_onItemCollide(CoverPooHole *coverPooHole, ItemObject *a, u8 *b, u8 *c);
u32 poo_onDriverCollide(CoverPooHole *coverPooHole, Kart *kart, u8 *b, u8 *c);
void poo_init(MapObject *mapObject);
u32 flip_handleBallHit(u32 a);
