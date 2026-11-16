#pragma once

#include "types.h"
#include "code_02146d78.h"
#include "Main/Unknown/code_020e6fd4.h" // MapObject
#include "Main/Unknown/code_0206bcb0.h"
#include "Main/Course/WaterEfct.h"
#include "Main/Unknown/code_020da414.h"
#include "Main/Unknown/code_020e005c.h"
#include "Main/Unknown/code_020e6b58.h"
#include "Main/Unknown/code_020f9c6c.h"
#include "Main/Unknown/code_020d6dc0.h"
#include "Main/Unknown/code_020d849c.h"
#include "Main/Unknown/code_020dc474.h"

// Object with the GroupFollower base at 0xc8 and its own fields from 0xec.
typedef struct Dossun {
    /* 00 */ MapObject field0;
    /* a0 */ s32 mState;
    /* a4 */ s32 mTimer;
    /* a8 */ s32 fieldA8;
    /* ac */ s32 fieldAC;
    /* b0 */ BOOL mEnteredState5;
    /* b4 */ s32 fieldB4;
    /* b8 */ s16 fieldB8;
    /* ba */ s16 fieldBA;
    /* bc */ u32 fieldBC;
    /* c0 */ u16 fieldC0;
    /* c2 */ u16 fieldC2;
    /* c4 */ s32 fieldC4;
    /* c8 */ GroupFollower mFollower;
    /* ec */ u16 mStartEntryIndex;
    /* ee */ u8 fieldEE[2];
    /* f0 */ s32 fieldF0;
    /* f4 */ s32 fieldF4;
    /* f8 */ s32 mHeightOffset;
    /* fc */ s32 fieldFC;
    /* 100 */ s32 field100;
    /* 104 */ s32 field104;
    /* 108 */ s32 field108;
} Dossun;

// 0x28 bytes: a function at 0x10.
typedef struct Unk020db1b0 {
    /* 00 */ u8 field0[0x10];
    /* 10 */ void (*field10)(void *a, Kuribo *p);
    /* 14 */ u8 field14[0x14];
} Unk020db1b0;

// 0x2c bytes: three functions at 0x08, 0x0c and 0x10.
typedef struct Unk020db20c {
    /* 00 */ u8 field0[8];
    /* 08 */ void (*field8)(void);
    /* 0c */ void (*fieldC)(void);
    /* 10 */ void (*field10)(void *a, Kuribo *p, void *c, u16 d);
    /* 14 */ u8 field14[0x18];
} Unk020db20c;

// 0x40 bytes: two functions at 0x00 and 0x04.
typedef struct Unk020db268 {
    /* 00 */ u32 (*field0)(Kuribo *p, Kart *a, u8 *b, u8 *c);
    /* 04 */ u32 (*field4)(Kuribo *p, Kart *a, u8 *b, u8 *c);
    /* 08 */ u8 field8[0x38];
} Unk020db268;

// 0x28 bytes: a function at 0x10.
typedef struct Unk020dbe74 {
    /* 00 */ u8 field0[0x10];
    /* 10 */ void (*field10)(void *a, Dossun *p);
    /* 14 */ u8 field14[0x14];
} Unk020dbe74;

// 0x2c bytes: functions at 0x08 and 0x10.
typedef struct Unk020dbed0 {
    /* 00 */ u8 field0[8];
    /* 08 */ void (*field8)(void);
    /* 0c */ u8 fieldC[4];
    /* 10 */ void (*field10)(void *a, Dossun *p, void *c, s32 d);
    /* 14 */ u8 field14[0x18];
} Unk020dbed0;

// 0x40 bytes: a function at 0x00.
typedef struct Unk020dbf2c {
    /* 00 */ u32 (*field0)(Dossun *p, Kart *a, u8 *b, u8 *c);
    /* 04 */ u8 field4[0x3c];
} Unk020dbf2c;

Unk020dbf2c *dossun_setupConfig(void);
Unk020dbed0 *dossun_setupRenderPart(void);
Unk020dbe74 *dossun_setupLogicPart(void);
Unk020db268 *kuribo_setupConfig(void);
Unk020db20c *kuribo_setupRenderPart(void);
Unk020db1b0 *kuribo_setupLogicPart(void);
s32 dossun_getMapElevation(Dossun *dossun);
void dossun_initState(Dossun *dossun);
void dossun_loadModels(void);
void dossun_init(Dossun *dossun, CourseMapRow *row);
void kuribo_globalPreRender(void);
void kuribo_render(void *unused0, Kuribo *kuribo, void *unused1, u16 d);
void kuribo_update(void *unused, Kuribo *kuribo); /* skipped for objects with mFlags & 4 (parked pool objects) */
void dossun_render(void *unused0, Dossun *dossun, void *unused1, s32 maxAlpha);
u32 dossun_onDriverCollide(Dossun *dossun, Kart *kart, u8 *b, u8 *c);
void dossun_update(void *unused, Dossun *dossun); /* skipped for objects with mFlags & 4 (parked pool objects) */
