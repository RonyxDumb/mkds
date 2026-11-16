#pragma once

#include "types.h"
#include "code_02146d78.h"
#include "Main/Unknown/code_020e6fd4.h" // MapObject
#include "Main/Unknown/code_020e005c.h"
#include "Main/Unknown/code_0206bcb0.h" // Kart
#include "Main/Unknown/code_0210b000.h" // SoundDistanceSquaredChange
#include "code_02012b30.h"

// Block of ten words.
typedef struct Unk020e0340 {
    /* 00 */ u32 field0[10];
} Unk020e0340;

extern const Unk020e0340 data_02158a54;

// Block of sixteen words.
typedef struct Unk020e03f8 {
    /* 00 */ u32 field0[16];
} Unk020e03f8;

extern const Unk020e03f8 data_02158a7c;
extern const Unk020e03f8 data_02158abc;
extern const Unk020e03f8 data_02158afc;
extern const Unk020e03f8 data_02158b3c;

// Three vectors of twelve bytes each.
typedef struct Unk020e38a0_28 {
    /* 00 */ Vec3 field0;
    /* 0c */ Vec3 fieldC;
    /* 18 */ Vec3 field18;
} Unk020e38a0_28;

// Object dcol_collideBox and dcol_collideCylinder compare against: seven words and a vector.
typedef struct Unk020e0764 {
    /* 00 */ s32 field0;
    /* 04 */ s32 field4;
    /* 08 */ s32 field8;
    /* 0c */ s32 fieldC;
    /* 10 */ s32 field10;
    /* 14 */ s32 field14;
    /* 18 */ s32 field18;
    /* 1c */ Vec3 field1C;
} Unk020e0764;

// Object with a vector at 0x2c and words at 0x38 and 0x3c.
typedef struct Unk020e20a8 {
    /* 000 */ u8 field0[0x2c];
    /* 02c */ Vec3 field2C;
    /* 038 */ BOOL field38;
    /* 03c */ BOOL field3C;
} Unk020e20a8;

// Object with vectors at 0x50 and 0x80.
typedef struct Unk020e246c {
    /* 000 */ u8 field0[0x50];
    /* 050 */ Vec3 field50;
    /* 05c */ s32 field5C;
    /* 060 */ u8 field60[0x4];
    /* 064 */ s32 field64;
    /* 068 */ u8 field68[0xc];
    /* 074 */ u16 field74;
    /* 076 */ u8 field76[0xa];
    /* 080 */ Vec3 field80;
    /* 08c */ u8 field8C[0x18];
    /* 0a4 */ s32 fieldA4;
    /* 0a8 */ u8 fieldA8[0x4];
    /* 0ac */ s32 fieldAC;
} Unk020e246c;

// Object behind traf_sCarModel, traf_sTruckModel, traf_sBusModel and traf_sCarTireModel.
typedef struct Unk0217b7a0 {
    /* 00 */ u32 field0;
    /* 04 */ NNSG3dResMdl *field4;
} Unk0217b7a0;

// Object a pointer at 0x12c of Unk020e1e98 points to (also behind bridge_sNsbcaAnim).
typedef struct Unk020e1e98_12c {
    /* 00 */ u8 field0[0xc];
    /* 0c */ s32 fieldC;
    /* 10 */ u8 field10[0xa];
    /* 1a */ u16 field1A;
    /* 1c */ s32 **field1C;
} Unk020e1e98_12c;

// Object a pointer at 0x154 of Unk020e1e98 points to.
typedef struct Unk020e1e98_154 {
    /* 00 */ s32 field0;
    /* 04 */ s32 field4;
    /* 08 */ s32 field8;
    /* 0c */ s32 fieldC;
    /* 10 */ s32 field10;
    /* 14 */ s32 field14;
    /* 18 */ s32 field18;
    /* 1c */ s32 field1C;
    /* 20 */ u32 *field20;
    /* 24 */ u32 *field24;
    /* 28 */ Unk020e1e98_12c **field28;
    /* 2c */ s32 field2C;
    /* 30 */ s32 field30;
} Unk020e1e98_154;

// Four words at 0xb4 of Unk020e1e98.
typedef struct Unk020e1e98_0b4 {
    /* 00 */ s32 field0;
    /* 04 */ u16 field4;
    /* 06 */ u8 field6[0x2];
    /* 08 */ s32 field8;
    /* 0c */ s32 fieldC;
} Unk020e1e98_0b4;

// 0x164 bytes.
typedef struct Unk020e1e98 {
    /* 000 */ MapObject field0;
    /* 0a0 */ s32 fieldA0;
    /* 0a4 */ s32 fieldA4;
    /* 0a8 */ s32 fieldA8;
    /* 0ac */ s32 fieldAC;
    /* 0b0 */ s32 fieldB0;
    /* 0b4 */ Unk020e1e98_0b4 fieldB4;
    /* 0c4 */ s32 fieldC4;
    /* 0c8 */ s32 fieldC8;
    /* 0cc */ s32 fieldCC;
    /* 0d0 */ u8 fieldD0[0x4];
    /* 0d4 */ s32 fieldD4;
    /* 0d8 */ GroupFollower fieldD8;
    /* 0fc */ u16 fieldFC;
    /* 0fe */ s16 fieldFE;
    /* 100 */ s32 field100[3];
    /* 10c */ u16 field10C;
    /* 10e */ u8 field10E[0x2];
    /* 110 */ s32 field110;
    /* 114 */ Vec3 field114;
    /* 120 */ s32 field120;
    /* 124 */ u32 field124;
    /* 128 */ u32 field128;
    /* 12c */ Unk020e1e98_12c *field12C;
    /* 130 */ u16 field130;
    /* 132 */ u16 field132;
    /* 134 */ u8 field134[0xc];
    /* 140 */ void *field140;
    /* 144 */ Vec3 field144;
    /* 150 */ u16 field150;
    /* 152 */ u16 field152;
    /* 154 */ Unk020e1e98_154 *field154;
    /* 158 */ SoundDistanceSquaredChange *field158;
    /* 15c */ u32 field15C;
    /* 160 */ u32 field160;
} Unk020e1e98;

// Object behind data_0217b79c and the argument of traf_prepareRoutes.
typedef struct Unk0217b79c {
    /* 00 */ Unk020e1e98 **field0;
    /* 04 */ u16 field4;
} Unk0217b79c;

// Object rotcyl_init fills.
typedef struct Unk020e3ef4 {
    /* 000 */ MapObject field0;
    /* 0a0 */ Unk020e38a0_28 fieldA0;
    /* 0c4 */ Unk020e38a0_28 fieldC4;
    /* 0e8 */ Vec3 fieldE8;
    /* 0f4 */ Vec3 fieldF4;
    /* 100 */ s32 field100;
    /* 104 */ s32 field104;
    /* 108 */ u8 field108[0x8];
    /* 110 */ BOOL field110;
    /* 114 */ Vec3 field114;
    /* 120 */ s32 field120;
    /* 124 */ Vec3 field124;
    /* 130 */ s32 field130;
    /* 134 */ s32 field134;
    /* 138 */ s32 field138;
    /* 13c */ u8 field13C[0x4];
    /* 140 */ struct Nsbmd *mModel;
    /* 144 */ u16 field144;
    /* 146 */ u16 field146;
    /* 148 */ u16 field148;
    /* 14a */ s16 field14A;
    /* 14c */ s32 field14C;
    /* 150 */ s32 field150;
    /* 154 */ s32 field154;
    /* 158 */ s32 field158;
    /* 15c */ s32 field15C;
} Unk020e3ef4;

// Object behind bridge_sRenderPart.
typedef struct Unk020e1dc0 {
    /* 00 */ Unk020e3ef4 **field0;
    /* 04 */ u16 field4;
    /* 06 */ u8 field6[0x26];
    /* 2c */ s32 field2C;
} Unk020e1dc0;

void choro_init(Unk020e1e98 *choropu, struct CourseMapRow *courseRow);
void *traf_setupCarCollision(void);
void *traf_setupTruckCollision(void);
void *traf_setupBusCollision(void);
void *traf_setupRenderPart(void);
void *traf_setupLogicPart(void);
void traf_globalPreRender(Unk020e20a8 *drawList);
void traf_render(Unk020e20a8 *drawList, Unk020e1e98 *vehicle, u32 c, u32 alpha);
void traf_update(u32 a, Unk020e1e98 *vehicle);
void traf_20E24D0(Unk020e1e98 *vehicle, Vec3 *hitterPosition);
u8 traf_onDriverCollide(Unk020e1e98 *vehicle, Kart *kart, u8 *c, u8 *d);
u8 traf_onItemCollide(Unk020e1e98 *vehicle, Unk020e246c *itemObject, u8 *c, u8 *d);
void traf_collide(Unk020e1e98 *vehicle, Vec3 *sphereCenter, s32 sphereRadius, Vec3 *overlapOffset);
void traf_prepareRoutes(Unk0217b79c *updateList);
void traf_loadModels(Unk020e20a8 *drawList);
void traf_init(Unk020e1e98 *vehicle, struct CourseMapRow *courseRow, Unk020e1e98_154 *kindInfo);
void traf_20E1E98(Unk020e1e98 *vehicle);
void dcol_render(Unk020e1dc0 *list, void *viewMatrix, void (*drawObject)(Unk020e3ef4 *, void *, u32));
void dcol_commonRender(Unk020e3ef4 *mapObject, void *viewMatrix, u32 alpha);
void dcol_setModel(Unk020e1dc0 *list, void *model);
s32 dcol_collide(Unk020e005c *object, Vec3 *sphereCenter, s32 sphereRadius, u16 d, Unk020e0764 *e, Unk020e0764 *f,
                  Vec3 *g, u16 *h, Vec3 *i, u16 *j);
void dcol_20E1A80(s32 a, s32 b, s32 c, u32 d, u16 e, u16 *f, s32 v, Unk020e005c *object, Vec3 *g, Vec3 *h,
                   Unk020e0764 *i, Unk020e0764 *j, Vec3 *k, Vec3 *l, u16 *m);
BOOL dcol_20E16DC(s32 a, s32 b, s32 c, u32 d, u16 e, u16 f, u16 *g, u16 h, s32 i, s32 j, Unk020e005c *object, Vec3 *l,
                   Vec3 *m, Vec3 *n, Unk020e0764 *o, Unk020e0764 *p, Vec3 *q, Vec3 *r, u16 *s);
BOOL dcol_collideBox(Unk020e005c *object, Vec3 *sphereCenter, s32 sphereRadius, u16 d, Unk020e0764 *o, Unk020e0764 *p,
                   Vec3 *q, u16 *g, Vec3 *r, u16 *s);
BOOL dcol_collideCylinder(Unk020e005c *object, Vec3 *sphereCenter, s32 sphereRadius, u16 d, Unk020e0764 *o, Unk020e0764 *p,
                   Vec3 *q, u16 *g, Vec3 *r, u16 *s);
void dcol_20E0680(Unk020e005c *object, Vec3 *position, Vec3 *c, Vec3 *d, u16 *e);
