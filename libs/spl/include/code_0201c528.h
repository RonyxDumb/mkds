#pragma once

#include "types.h"
#include "code_02012b30.h" // MtxFx43
#include "code_02147cd8.h"

// Linked through field0/field4; on the lists at Unk0201ca6c 0x08 and 0x14 and SPLManager 0x1c.
typedef struct Unk0201e3c8 {
    /* 00 */ struct Unk0201e3c8 *field0;
    /* 04 */ struct Unk0201e3c8 *field4;
    /* 08 */ Vec3 field8;
    /* 14 */ Vec3 field14;
    /* 20 */ u16 field20;
    /* 22 */ s16 field22;
    /* 24 */ u16 field24;
    /* 26 */ u16 field26;
    /* 28 */ u16 field28;
    /* 2a */ u16 field2A;
    /* 2c */ u8 field2C;
    /* 2d */ u8 field2D;
    /* 2e */ u16 field2E_0 : 5;
    /* 2e */ u16 field2E_5 : 5;
    /* 2e */ u16 field2E_10 : 6;
    /* 30 */ s32 field30;
    /* 34 */ s16 field34;
    /* 36 */ u16 field36;
    /* 38 */ Vec3 field38;
} Unk0201e3c8;

// Used by SPLList_PushFront, SPLList_Erase and SPLList_PopFront.
typedef struct Unk0201e494 {
    /* 00 */ Unk0201e3c8 *field0;
    /* 04 */ s32 field4;
    /* 08 */ Unk0201e3c8 *field8;
} Unk0201e494;

typedef struct Unk0201ca6c_20_00_00 {
    /* 00 */ u32 field0_0 : 4;
    /* 00 */ u32 field0_4 : 2;
    /* 00 */ u32 field0_6 : 2;
    /* 00 */ u32 field0_8 : 1;
    /* 00 */ u32 field0_9 : 1;
    /* 00 */ u32 field0_10 : 1;
    /* 00 */ u32 field0_11 : 1;
    /* 00 */ u32 field0_12 : 1;
    /* 00 */ u32 field0_13 : 1;
    /* 00 */ u32 field0_14 : 1;
    /* 00 */ u32 field0_15 : 1;
    /* 00 */ u32 field0_16 : 1;
    /* 00 */ u32 field0_17 : 2;
    /* 00 */ u32 field0_19 : 1;
    /* 00 */ u32 field0_20 : 1;
    /* 00 */ u32 field0_21 : 1;
    /* 00 */ u32 field0_22 : 1;
    /* 00 */ u32 field0_23 : 1;
    /* 00 */ u32 field0_24 : 1;
    /* 00 */ u32 field0_25 : 1;
    /* 00 */ u32 field0_26 : 1;
    /* 00 */ u32 field0_27 : 1;
    /* 00 */ u32 field0_28 : 1;
    /* 00 */ u32 field0_29 : 1;
    /* 00 */ u32 field0_30 : 1;
    /* 00 */ u32 field0_31 : 1;
} Unk0201ca6c_20_00_00;

typedef struct Unk0201ca6c_20_00_48 {
    /* 00 */ u32 field0_0 : 8;
    /* 00 */ u32 field0_8 : 16;
    /* 00 */ u32 field0_24 : 2;
    /* 00 */ u32 field0_26 : 2;
    /* 00 */ u32 field0_28 : 3;
    /* 00 */ u32 field0_31 : 1;
} Unk0201ca6c_20_00_48;

typedef struct Unk0201ca6c_20_00 {
    /* 00 */ Unk0201ca6c_20_00_00 field0;
    /* 04 */ Vec3 field4;
    /* 10 */ s32 field10;
    /* 14 */ s32 field14;
    /* 18 */ s32 field18;
    /* 1c */ Vec3s16 field1C;
    /* 22 */ u16 field22;
    /* 24 */ s32 field24;
    /* 28 */ s32 field28;
    /* 2c */ s32 field2C;
    /* 30 */ s16 field30;
    /* 32 */ u16 field32;
    /* 34 */ s16 field34;
    /* 36 */ s16 field36;
    /* 38 */ u16 field38;
    /* 3a */ u8 field3A[2];
    /* 3c */ u16 field3C;
    /* 3e */ u16 field3E;
    /* 40 */ u8 field40;
    /* 41 */ u8 field41;
    /* 42 */ u8 field42;
    /* 43 */ u8 field43;
    /* 44 */ u8 field44;
    /* 45 */ u8 field45;
    /* 46 */ u8 field46;
    /* 47 */ u8 field47;
    /* 48 */ Unk0201ca6c_20_00_48 field48;
    /* 4c */ u32 field4C_0 : 1;
    /* 4c */ u32 field4C_1 : 1;
    /* 4c */ u32 field4C_2 : 30;
    /* 50 */ s16 field50;
    /* 52 */ s16 field52;
    /* 54 */ u8 field54;
} Unk0201ca6c_20_00;

typedef struct Unk0201ca6c_20_04 {
    /* 00 */ s16 field0;
    /* 02 */ s16 field2;
    /* 04 */ s16 field4;
    /* 06 */ u8 field6;
    /* 07 */ u8 field7;
    /* 08 */ u16 field8_0 : 1;
    /* 08 */ u16 field8_1 : 15;
} Unk0201ca6c_20_04;

typedef struct Unk0201ca6c_20_08 {
    /* 00 */ u16 field0;
    /* 02 */ u16 field2;
    /* 04 */ u8 field4;
    /* 05 */ u8 field5;
    /* 06 */ u8 field6;
    /* 07 */ u8 field7;
    /* 08 */ u16 field8_0 : 1;
    /* 08 */ u16 field8_1 : 1;
    /* 08 */ u16 field8_2 : 1;
    /* 08 */ u16 field8_3 : 13;
} Unk0201ca6c_20_08;

typedef struct Unk0201ca6c_20_0c {
    /* 00 */ u16 field0_0 : 5;
    /* 00 */ u16 field0_5 : 5;
    /* 00 */ u16 field0_10 : 5;
    /* 00 */ u16 field0_15 : 1;
    /* 02 */ u16 field2_0 : 8;
    /* 02 */ u16 field2_8 : 1;
    /* 02 */ u16 field2_9 : 7;
    /* 04 */ u8 field4;
    /* 05 */ u8 field5;
    /* 06 */ u8 field6[2];
} Unk0201ca6c_20_0c;

typedef struct Unk0201ca6c_20_10 {
    /* 00 */ u8 field0[8];
    /* 08 */ u32 field8_0 : 8;
    /* 08 */ u32 field8_8 : 8;
    /* 08 */ u32 field8_16 : 1;
    /* 08 */ u32 field8_17 : 1;
    /* 08 */ u32 field8_18 : 14;
} Unk0201ca6c_20_10;

typedef struct Unk0201ca6c_20_14_10 {
    /* 00 */ u32 field0_0 : 2;
    /* 00 */ u32 field0_2 : 2;
    /* 00 */ u32 field0_4 : 1;
    /* 00 */ u32 field0_5 : 1;
    /* 00 */ u32 field0_6 : 1;
    /* 00 */ u32 field0_7 : 25;
} Unk0201ca6c_20_14_10;

typedef struct Unk0201ca6c_20_14 {
    /* 00 */ u16 field0_0 : 1;
    /* 00 */ u16 field0_1 : 1;
    /* 00 */ u16 field0_2 : 1;
    /* 00 */ u16 field0_3 : 2;
    /* 00 */ u16 field0_5 : 1;
    /* 00 */ u16 field0_6 : 1;
    /* 00 */ u16 field0_7 : 2;
    /* 00 */ u16 field0_9 : 2;
    /* 00 */ u16 field0_11 : 1;
    /* 00 */ u16 field0_12 : 4;
    /* 02 */ s16 field2;
    /* 04 */ s16 field4;
    /* 06 */ u16 field6;
    /* 08 */ u8 field8;
    /* 09 */ u8 field9;
    /* 0a */ u16 fieldA;
    /* 0c */ u8 fieldC;
    /* 0d */ u8 fieldD;
    /* 0e */ u8 fieldE;
    /* 0f */ u8 fieldF;
    /* 10 */ Unk0201ca6c_20_14_10 field10;
} Unk0201ca6c_20_14;

typedef struct Unk0201ca6c_24 {
    /* 00 */ u32 field0_0 : 1;
    /* 00 */ u32 field0_1 : 1;
    /* 00 */ u32 field0_2 : 1;
    /* 00 */ u32 field0_3 : 1;
    /* 00 */ u32 field0_4 : 1;
    /* 00 */ u32 field0_5 : 27;
} Unk0201ca6c_24;

typedef struct Unk0201ca6c Unk0201ca6c;
typedef struct Unk0201ca6c_20 Unk0201ca6c_20;

// Entries of the table at Unk0201ca6c_20 0x18 (count at 0x1c).
typedef struct Unk0201ca6c_20_18 {
    /* 00 */ void (*field0)(); // called with four arguments; the type of the first differs per entry
    /* 04 */ void *field4;
} Unk0201ca6c_20_18;

struct Unk0201ca6c_20 {
    /* 00 */ Unk0201ca6c_20_00 *field0;
    /* 04 */ Unk0201ca6c_20_04 *field4;
    /* 08 */ Unk0201ca6c_20_08 *field8;
    /* 0c */ Unk0201ca6c_20_0c *fieldC;
    /* 10 */ Unk0201ca6c_20_10 *field10;
    /* 14 */ Unk0201ca6c_20_14 *field14;
    /* 18 */ Unk0201ca6c_20_18 *field18;
    /* 1c */ u16 field1C;
};

// The four bytes at Unk0201ca6c 0x98.
typedef struct Unk0201ca6c_98 {
    /* 00 */ u8 field0;
    /* 01 */ u8 field1;
    /* 02 */ u8 field2;
    /* 03 */ u8 field3;
} Unk0201ca6c_98;

struct Unk0201ca6c {
    /* 00 */ struct Unk0201ca6c *field0;
    /* 04 */ struct Unk0201ca6c *field4;
    /* 08 */ Unk0201e494 field8;
    /* 14 */ Unk0201e494 field14;
    /* 20 */ Unk0201ca6c_20 *field20;
    /* 24 */ Unk0201ca6c_24 field24;
    /* 28 */ Vec3 field28;
    /* 34 */ Vec3 field34;
    /* 40 */ Vec3 field40;
    /* 4c */ u16 field4C;
    /* 4e */ s16 field4E;
    /* 50 */ Vec3s16 field50;
    /* 56 */ u16 field56;
    /* 58 */ s32 field58;
    /* 5c */ s32 field5C;
    /* 60 */ s32 field60;
    /* 64 */ s32 field64;
    /* 68 */ s32 field68;
    /* 6c */ s32 field6C;
    /* 70 */ u16 field70;
    /* 72 */ u16 field72;
    /* 74 */ s32 field74;
    /* 78 */ s16 field78;
    /* 7a */ s16 field7A;
    /* 7c */ s16 field7C;
    /* 7e */ s16 field7E;
    /* 80 */ u32 field80_0 : 8;
    /* 80 */ u32 field80_8 : 8;
    /* 80 */ u32 field80_16 : 3;
    /* 80 */ u32 field80_19 : 13;
    /* 84 */ Vec3s16 field84;
    /* 8a */ Vec3s16 field8A;
    /* 90 */ void (*field90)(Unk0201ca6c *p, s32 a);
    /* 94 */ union {
        void *field94;
        u32 mUnk_94_u;
    };
    /* 98 */ union {
        u32 field98;
        Unk0201ca6c_98 mUnk_98_b;
        struct {
            u8 field98_0;
            u8 field98_8;
            u8 field98_16;
            u8 field98_24;
        };
    };
};

// Read by SPLBehavior_ApplyMagnet and SPLBehavior_ApplyConvergence.
typedef struct Unk0201e248 {
    /* 00 */ Vec3 field0;
    /* 0c */ s16 fieldC;
} Unk0201e248;

// Read by SPLBehavior_ApplyRandom.
typedef struct Unk0201e2cc {
    /* 00 */ s16 field0;
    /* 02 */ s16 field2;
    /* 04 */ s16 field4;
    /* 06 */ u16 field6;
} Unk0201e2cc;

// Read by SPLBehavior_ApplyCollisionPlane.
typedef struct Unk0201e054 {
    /* 00 */ s32 field0;
    /* 04 */ s16 field4;
    /* 06 */ u16 field6_0 : 2;
    /* 06 */ u16 field6_2 : 14;
} Unk0201e054;

// Read by SPLBehavior_ApplySpin.
typedef struct Unk0201e170 {
    /* 00 */ u16 field0;
    /* 02 */ u16 field2;
} Unk0201e170;

void SPLUtil_RotateXYZ(s32 sinValue, s32 cosValue, MtxFx43 *mtx);
void SPLUtil_DrawXZPlane(u32 a, u32 b, s32 c, s32 d);
void SPLUtil_DrawXYPlane(u32 a, u32 b, s32 c, s32 d);
void SPLEmitter_EmitChildren(Unk0201e3c8 *emtr, Unk0201ca6c *q, Unk0201e494 *r);
void SPLEmitter_EmitParticles(Unk0201ca6c *emtr, Unk0201e494 *r);
void SPLUtil_TiltCoordinates(Vec3 *ptclPos, const Vec3 *pos, Unk0201ca6c *emtr);
void SPLEmitter_ComputeOrthogonalAxes(Unk0201ca6c *emtr);
void SPLAnim_ChildAlpha(Unk0201e3c8 *ptcl, Unk0201ca6c_20 *res, s32 lifeRate);
void SPLAnim_ChildScale(Unk0201e3c8 *ptcl, Unk0201ca6c_20 *res, s32 lifeRate);
void SPLAnim_Texture(Unk0201e3c8 *ptcl, Unk0201ca6c_20 *res, s32 lifeRate);
void SPLAnim_Alpha(Unk0201e3c8 *ptcl, Unk0201ca6c_20 *res, s32 lifeRate);
void SPLAnim_Color(Unk0201e3c8 *ptcl, Unk0201ca6c_20 *res, s32 lifeRate);
void SPLAnim_Scale(Unk0201e3c8 *ptcl, Unk0201ca6c_20 *res, s32 lifeRate);
void SPLBehavior_ApplyConvergence(const Unk0201e248 *conv, Unk0201e3c8 *ptcl, Vec3 *acc, Unk0201ca6c *emtr);
void SPLBehavior_ApplyCollisionPlane(const Unk0201e054 *plane, Unk0201e3c8 *ptcl, Vec3 *acc, Unk0201ca6c *emtr);
void SPLBehavior_ApplySpin(const Unk0201e170 *spin, Unk0201e3c8 *ptcl, Vec3 *acc, Unk0201ca6c *emtr);
void SPLBehavior_ApplyMagnet(const Unk0201e248 *magnet, Unk0201e3c8 *ptcl, Vec3 *acc, Unk0201ca6c *emtr);
void SPLBehavior_ApplyRandom(const Unk0201e2cc *rng, Unk0201e3c8 *ptcl, Vec3 *acc, Unk0201ca6c *emtr);
void SPLBehavior_ApplyGravity(const Vec3s16 *gravity, Unk0201e3c8 *ptcl, Vec3 *acc, Unk0201ca6c *emtr);
Unk0201e3c8 *SPLList_Erase(Unk0201e494 *list, Unk0201e3c8 *node);
Unk0201e3c8 *SPLList_PopFront(Unk0201e494 *list);
void SPLList_PushFront(Unk0201e494 *list, Unk0201e3c8 *node);
void SPLRandom_VecFx32_XY(Vec3 *vec);
void SPLRandom_VecFx32(Vec3 *vec);
