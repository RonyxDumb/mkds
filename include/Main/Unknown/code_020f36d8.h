#pragma once

#include "types.h"
#include "Main/Unknown/code_020b502c.h"
#include "Main/Unknown/code_0206bcb0.h"
#include "Main/Unknown/unk_021759c0.h"

// Object whose first word is compared with a stored value.
typedef struct {
    /* 00 */ s32 mUnk_00;
} Unk020f36d8;

// Node with two lists of node pointers and a position pointer.
typedef struct Unk020f371c {
    /* 00 */ struct Unk020f371c *mUnk_00[3];
    /* 0c */ struct Unk020f371c *mUnk_0c[3];
    /* 18 */ Vec3 *mUnk_18;
    /* 1c */ u8 mUnk_1c[8];
    /* 24 */ u16 mUnk_24;
    /* 26 */ u16 mUnk_26;
} Unk020f371c;

// A node and which of its two lists is used.
typedef struct {
    /* 00 */ Unk020f371c *mUnk_00;
    /* 04 */ s32 mUnk_04;
} Unk020f371c_Ref;

// Nine halfwords moved together.
typedef struct {
    /* 00 */ u16 mUnk_00[9];
} Unk020f41c4_C;

// Element returned through data_027e00cc.
typedef struct {
    /* 00 */ u8 mUnk_00[0x44];
    /* 44 */ s32 mUnk_44;
    /* 48 */ u32 mUnk_48;
    /* 4c */ u8 mUnk_4c[2];
    /* 4e */ s16 mUnk_4e;
    /* 50 */ u8 mUnk_50[0xc];
    /* 5c */ Vec3 mUnk_5c;
    /* 68 */ s32 mUnk_68;
    /* 6c */ s32 mUnk_6c;
    /* 70 */ s32 mUnk_70;
    /* 74 */ u32 mUnk_74;
    /* 78 */ u16 mUnk_78;
    /* 7a */ u16 mUnk_7a;
    /* 7c */ Unk020f41c4_C mUnk_7c;
    /* 8e */ u8 mUnk_8e[2];
    /* 90 */ u8 mUnk_90[0x40];
    /* d0 */ Vec3 *mUnk_d0;
    /* d4 */ u8 mUnk_d4[0xc];
    /* e0 */ s32 mUnk_e0;
    /* e4 */ u8 mUnk_e4[0x18];
    /* fc */ u32 mUnk_fc;
    /* 100 */ u8 mUnk_100[0x1c];
    /* 11c */ s32 mUnk_11c;
} Unk020f41c4_A;

// Three 64-bit words: x, a and c of x = x * a + c.
typedef struct {
    /* 00 */ u64 mUnk_00;
    /* 08 */ u64 mUnk_08;
    /* 10 */ u64 mUnk_10;
} Unk020f41c4_B;

// Object behind data_0217561c.
typedef struct {
    /* 000 */ u8 mUnk_000[0x47c];
    /* 47c */ Unk020f41c4_B mUnk_47c;
    /* 494 */ u8 mUnk_494[4];
    /* 498 */ Unk020f41c4_B mUnk_498;
} Unk0217561c;

// Entry of the table behind data_0217bc34.
typedef struct {
    /* 00 */ s32 mUnk_00;
    /* 04 */ s32 mUnk_04;
    /* 08 */ u8 mUnk_08[4];
    /* 0c */ s32 mUnk_0c;
    /* 10 */ s32 mUnk_10;
    /* 14 */ u8 mUnk_14[8];
    /* 1c */ void (*mUnk_1c)(void *);
    /* 20 */ void (*mUnk_20)(void *, void *);
    /* 24 */ s32 (*mUnk_24)(void *, void *);
    /* 28 */ s32 mUnk_28;
    /* 2c */ s32 mUnk_2c;
    /* 30 */ s32 (*mUnk_30)(void *, s32, s32, s32, s32);
    /* 34 */ u8 mUnk_34[4];
    /* 38 */ void (*mUnk_38)(void *);
    /* 3c */ u8 mUnk_3c[0xc];
    /* 48 */ void (*mUnk_48)(void *, void *, s32);
    /* 4c */ u8 mUnk_4c[4];
    /* 50 */ void (*mUnk_50)(void *);
    /* 54 */ u8 mUnk_54[8];
    /* 5c */ s32 mUnk_5c;
    /* 60 */ u8 mUnk_60[8];
    /* 68 */ s32 mUnk_68;
    /* 6c */ s32 mUnk_6c;
    /* 70 */ s32 mUnk_70;
    /* 74 */ s32 mUnk_74;
    /* 78 */ s32 mUnk_78;
    /* 7c */ u8 mUnk_7c[4];
    /* 80 */ s32 mUnk_80;
    /* 84 */ u8 mUnk_84[0x20];
    /* a4 */ s32 mUnk_a4;
} Unk0217bc34;

// Two words of a row of data_0215961c.
typedef struct {
    /* 00 */ s32 mUnk_00;
    /* 04 */ s32 mUnk_04;
} Unk020f41c4_Pair;

// Row of data_0215961c.
typedef struct {
    /* 00 */ Unk020f41c4_Pair mUnk_00[3];
} Unk020f41c4_Row;

// Four positions and pointers to them.
typedef struct {
    /* 00 */ u8 mUnk_00[0x60];
    /* 60 */ s32 mUnk_60;
    /* 64 */ Vec3 *mUnk_64[4];
    /* 74 */ Vec3 mUnk_74[4];
} Unk020f3fa8;

// Entry of the table behind data_0217bc48.
typedef struct {
    /* 00 */ u8 mUnk_00[8];
    /* 08 */ s32 mUnk_08;
    /* 0c */ s32 mUnk_0c;
    /* 10 */ s32 mUnk_10;
    /* 14 */ s32 mUnk_14;
    /* 18 */ void (*mUnk_18)(void *, void *);
} Unk0217bc48;

// Entry of the table behind data_027e00cc.
typedef struct {
    /* 00 */ s32 mUnk_00;
    /* 04 */ Unk020f41c4_A **mUnk_04;
    /* 08 */ s32 mUnk_08;
    /* 0c */ u8 mUnk_0c[4];
    /* 10 */ s32 mUnk_10;
    /* 14 */ s32 mUnk_14;
    /* 18 */ s32 mUnk_18;
    /* 1c */ s32 mUnk_1c;
    /* 20 */ s32 mUnk_20;
    /* 24 */ void (*mUnk_24)(void *, void *, void *);
    /* 28 */ u8 mUnk_28[0x1c];
} Unk027e00cc;

// Object with a u16 at 0x1f8 and a pointer at 0x1fc.
typedef struct {
    /* 000 */ u8 mUnk_000[0x1f8];
    /* 1f8 */ u16 mUnk_1f8;
    /* 1fa */ u8 mUnk_1fa[2];
    /* 1fc */ Unk0206bcb0 *mUnk_1fc;
} Unk020f40dc_Owner;

// Value of the first word of Unk020f40dc.
typedef enum { UNK_020F40DC_KIND_0 } Unk020f40dc_Kind;

// Object handled by func_020f40dc and the functions after it.
typedef struct {
    /* 00 */ s32 mUnk_00;
    /* 04 */ Unk020f40dc_Owner *mUnk_04;
    /* 08 */ s32 mUnk_08;
    /* 0c */ s32 mUnk_0c;
    /* 10 */ s16 mUnk_10;
    /* 12 */ s16 mUnk_12;
    /* 14 */ Unk020f41c4_A *mUnk_14[3];
    /* 20 */ s32 mUnk_20;
    /* 24 */ s32 mUnk_24;
} Unk020f40dc;

extern Unk0206bcb0 *func_0207a974(s32 idx);
extern s32 func_020d7c84(Unk020f3fa8 *p, s32 mode, Vec3 **path);
extern void func_020d7d18(Unk020f3fa8 *p, s32 mode, Vec3 **path, s32 scale);
extern void *func_020fe828(s32 idx);
extern void *func_020fe958(s32 idx);
#include "Main/Unknown/code_020ee684.h"
extern void func_020f49bc(Unk020f40dc *rec);

extern s32 data_0217bc38[];
extern Unk0217bc34 *data_0217bc34;
extern Unk0217561c *data_0217561c;
extern Unk020f41c4_Row data_0215961c[];
extern Unk0217bc48 *data_0217bc48;
extern Unk027e00cc *data_027e00cc;

u8 func_020f36d8(Unk020f36d8 *p);
void func_020f371c(Unk020f371c_Ref *in, Unk020f371c_Ref *out, u32 idx, s32 flag);
s32 func_020f3a58(Unk020f371c_Ref *in, Unk020f371c_Ref *out, Vec3 *pos);
s32 func_020f3bb4(Unk020f371c_Ref *a, Unk020f371c_Ref *b, Unk020f371c_Ref *out, Vec3 *pos);
s32 func_020f3c54(Unk020f371c_Ref *in, Unk020f371c_Ref *out, Vec3 *pos);
s32 func_020f3fa8(Unk020f3fa8 *p, Vec3 *v);
void func_020f4020(Unk020f3fa8 *p, Vec3 *points, s32 scale);
s32 func_020f4090(s32 idx);
void func_020f40a0(s32 idx, s32 amount);
void func_020f40dc(Unk020f40dc *rec, s32 kind, s32 count);
void func_020f413c(Unk020f40dc *rec, s32 *kind, s32 *count);
void func_020f4188(Unk020f40dc *rec, s32 v);
s32 func_020f4198(Unk020f40dc *rec, s32 v);
void func_020f41b0(Unk020f40dc *rec);
void func_020f41c4(Unk020f40dc *rec);
void func_020f45f0(Unk020f40dc *rec, s32 keep);
void func_020f4718(Unk020f40dc *rec);
void func_020f4754(Unk020f40dc *rec, s32 n);
void func_020f47e4(Unk020f40dc *rec, s32 kind);
void func_020f4884(Unk020f40dc *rec);
