#pragma once

#include "types.h"
#include "Main/Unknown/code_0206bcb0.h" // Kart
#include "code_02146d78.h"
#include "Main/Unknown/code_020e6fd4.h" // MapObject, MapObjectList

// Element of 0x10 bytes: a position, then two halfwords.
typedef struct Unk0209df84_c4 {
    /* 00 */ Vec3 field0;
    /* 0c */ u16 fieldC;
    /* 0e */ u16 fieldE;
} Unk0209df84_c4;

// Object of kind 0x1af (Fireball2); Unk0209e950 is a view of the draw group record (word +0x1c), not of this
// object. After the shared part, the counts at 0xa0 and 0xa2, a grid of elements from 0xc4 (rows of
// 0x140 bytes, 0xa0 rows of 0xa2 elements) and the words from 0x19c4.
typedef struct Fireball2 {
    /* 0000 */ MapObject field0;
    /* 00a0 */ u16 fieldA0;
    /* 00a2 */ u16 fieldA2;
    /* 00a4 */ u16 fieldA4;
    /* 00a6 */ u8 fieldA6[2];
    /* 00a8 */ s32 fieldA8;
    /* 00ac */ s32 fieldAC;
    /* 00b0 */ u16 fieldB0;
    /* 00b2 */ u16 fieldB2;
    /* 00b4 */ Vec3 fieldB4;
    /* 00c0 */ u8 fieldC0[2];
    /* 00c2 */ u16 fieldC2;
    /* 00c4 */ Unk0209df84_c4 fieldC4[20][20];
    /* 19c4 */ s32 field19C4[8];
    /* 19e4 */ s32 field19E4;
} Fireball2;

// Object given to fbal2_loadModel, which sets the word at 0x1c.
typedef struct Unk0209e950 {
    /* 00 */ u8 field0[0x1c];
    /* 1c */ s32 field1C;
} Unk0209e950;

void *fbal2_setupLogicPart(void);
void *fbal2_setupRenderPart(void);
void fbal2_setupConfig(void);
void fbal2_update(void *a, Fireball2 *b); /* skipped for objects with mFlags & 4 (parked pool objects) */
void fbal2_globalLogicInit(MapObjectList *p);
void fbal2_render(void *a, Fireball2 *b);
void fbal2_applyMaterial(void *a);
void fbal2_loadModel(Unk0209e950 *a); /* also sets word +0x1c of the group record to 1 */
BOOL fbal2_collide(Fireball2 *a, Vec3 *b, s32 c);
u8 fbal2_onDriverCollide(Fireball2 *a, Kart *b, u8 *c, u8 *d);
void fbal2_init(Fireball2 *a);
void *pud_setupRenderPart(void);
