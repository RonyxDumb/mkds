#pragma once

#include "Main/Unknown/code_020b1dbc.h"
#include "Main/Unknown/code_020b4e5c.h"
#include "Main/Unknown/unk_0217b000.h"

#include "types.h"
#include "Main/Unknown/code_02039860.h"
#include "Main/Unknown/code_02147000.h"
#include "Main/Unknown/unk_0215d000.h"
#include "Main/Unknown/unk_02175628.h"
#include "Main/Unknown/unk_021759c0.h"

// Two words (the elements at member 0xc of Unk0217b498).
typedef Unk0217b498_0c UnkPair020b502c;

// Object returned by func_020b57e4.
typedef struct {
    /* 00 */ Vec3 mUnk_00;
    /* 0c */ u8 mUnk_0c[4];
    /* 10 */ s32 mUnk_10;
} Unk020b57e4;

// One entry of the table at Unk02175620::mUnk_08.
typedef struct {
    /* 00 */ u8 mUnk_00[1];
    /* 01 */ u8 mUnk_01;
    /* 02 */ u16 mUnk_02;
} Unk02175620_08;

// Object behind Unk02175620::mUnk_018.
typedef struct {
    /* 00 */ u8 mUnk_00[2];
    /* 02 */ u16 mUnk_02;
    /* 04 */ u8 mUnk_04;
    /* 05 */ u8 mUnk_05;
    /* 06 */ u8 mUnk_06;
    /* 07 */ u8 mUnk_07;
    /* 08 */ u8 mUnk_08[8];
    /* 10 */ s32 mUnk_10;
    /* 14 */ s32 mUnk_14;
    /* 18 */ u16 mUnk_18[4];
    /* 20 */ s32 mUnk_20;
} Unk02175620_18;

// 0x48-byte entries of the table at Unk02175620::mUnk_74 (func_020423fc returns one).
typedef struct {
    /* 00 */ u8 mUnk_00[0x44];
    /* 44 */ u8 mUnk_44;
    /* 45 */ u8 mUnk_45[3];
} Unk02175620_74;

// 0x18-byte entries of the table at Unk02175620::mUnk_84 (func_020a0f0c returns one).
typedef struct {
    /* 00 */ Vec3 mUnk_00;
    /* 0c */ s32 mUnk_0c;
    /* 10 */ u8 mUnk_10[8];
} Unk02175620_84;

// 0x30-byte entries of the table at Unk02175620::mUnk_bc (func_02080908 searches it).
typedef struct Unk02175620_bc {
    /* 00 */ struct Unk02175620_bc *mUnk_00[3];
    /* 0c */ struct Unk02175620_bc *mUnk_0c;
    /* 10 */ u8 mUnk_10[8];
    /* 18 */ Vec3 *mUnk_18;
    /* 1c */ u8 mUnk_1c[4];
    /* 20 */ Vec3 *mUnk_20;
    /* 24 */ s32 mUnk_24;
    /* 28 */ s16 *mUnk_28;
    /* 2c */ u16 mUnk_2c;
    /* 2e */ u8 mUnk_2e;
    /* 2f */ u8 mUnk_2f;
} Unk02175620_bc;

struct Unk020fa294;

// Object behind data_02175620.
typedef struct {
    /* 00 */ struct Unk020fa294 *mUnk_00;
    /* 04 */ u16 mUnk_04;
    /* 06 */ u8 mUnk_06[2];
    /* 08 */ Unk02175620_08 *mUnk_08;
    /* 0c */ u16 mUnk_0c;
    /* 00e */ u8 mUnk_00e[0x2];
    /* 010 */ s32 mUnk_010;
    /* 014 */ u16 mUnk_014;
    /* 016 */ u8 mUnk_016[0x2];
    /* 018 */ Unk02175620_18 *mUnk_018;
    /* 01c */ s32 mUnk_01c;
    /* 020 */ u16 mUnk_020;
    /* 022 */ u8 mUnk_022[0x2];
    /* 024 */ s32 mUnk_024;
    /* 028 */ u16 mUnk_028;
    /* 02a */ u8 mUnk_02a[0x2];
    /* 2c */ Unk020b57e4 *mUnk_2c;
    /* 30 */ u16 mUnk_30;
    /* 32 */ u8 mUnk_32[0x2];
    /* 34 */ void *mUnk_34;
    /* 38 */ u16 mUnk_38;
    /* 3a */ u8 mUnk_3a[0x2];
    /* 3c */ void *mUnk_3c;
    /* 40 */ u16 mUnk_40;
    /* 42 */ u8 mUnk_42[0x2];
    /* 44 */ void *mUnk_44;
    /* 48 */ u16 mUnk_48;
    /* 4a */ u8 mUnk_4a[0x2];
    /* 4c */ void *mUnk_4c;
    /* 50 */ u16 mUnk_50;
    /* 52 */ u8 mUnk_52[0x2];
    /* 54 */ s32 mUnk_54;
    /* 58 */ u16 mUnk_58;
    /* 5a */ u8 mUnk_5a[0x2];
    /* 5c */ void *mUnk_5c;
    /* 60 */ u16 mUnk_60;
    /* 62 */ u8 mUnk_62[0x2];
    /* 64 */ s32 mUnk_64;
    /* 68 */ u16 mUnk_68;
    /* 6a */ u8 mUnk_6a[0x2];
    /* 6c */ void *mUnk_6c;
    /* 70 */ u16 mUnk_70;
    /* 72 */ u8 mUnk_72[0x2];
    /* 74 */ Unk02175620_74 *mUnk_74;
    /* 78 */ u16 mUnk_78;
    /* 7a */ u8 mUnk_7a[0x2];
    /* 7c */ s32 mUnk_7c;
    /* 80 */ u16 mUnk_80;
    /* 82 */ u8 mUnk_82[0x2];
    /* 84 */ Unk02175620_84 *mUnk_84;
    /* 88 */ u16 mUnk_88;
    /* 8a */ u8 mUnk_8a[2];
    /* 8c */ void *mUnk_8c;
    /* 90 */ u16 mUnk_90;
    /* 92 */ u8 mUnk_92[2];
    /* 94 */ void *mUnk_94;
    /* 98 */ u16 mUnk_98;
    /* 9a */ u16 mUnk_9a;
    /* 9c */ u16 mUnk_9c;
    /* 9e */ u8 mUnk_9e[2];
    /* a0 */ void *mUnk_a0;
    /* a4 */ Unk02175620_bc *mUnk_a4;
    /* a8 */ s32 mUnk_a8;
    /* ac */ struct Unk020f371c *mUnk_ac;
    /* b0 */ s32 mUnk_b0;
    /* b4 */ s32 mUnk_b4;
    /* b8 */ void *mUnk_b8;
    /* bc */ Unk02175620_bc *mUnk_bc;
    /* c0 */ s32 mUnk_c0;
    /* c4 */ s32 mUnk_c4;
    /* c8 */ s32 mUnk_c8;
    /* cc */ s32 mUnk_cc;
    /* d0 */ s32 mUnk_d0;
    /* d4 */ s32 mUnk_d4;
    /* d8 */ s32 mUnk_d8;
    /* dc */ u8 mUnk_dc[0x1c];
    /* f8 */ void *mUnk_f8;
    /* fc */ void *mUnk_fc;
    /* 100 */ u16 mUnk_100;
    /* 102 */ u16 mUnk_102;
    /* 104 */ u32 mUnk_104;
    /* 108 */ s32 mUnk_108;
    /* 10c */ u16 mUnk_10c;
    /* 10e */ u8 mUnk_10e;
    /* 10f */ u8 mUnk_10f;
} Unk02175620;

// Eight words.
typedef struct {
    /* 00 */ s32 mUnk_00;
    /* 04 */ s32 mUnk_04;
    /* 08 */ s32 mUnk_08;
    /* 0c */ s32 mUnk_0c;
    /* 10 */ s32 mUnk_10;
    /* 14 */ s32 mUnk_14;
    /* 18 */ s32 mUnk_18;
    /* 1c */ s32 mUnk_1c;
} Unk020b503c;

// Object behind data_0217b3c0.
typedef struct {
    /* 00 */ UnkPair020b502c mUnk_00;
    /* 08 */ s32 mUnk_08;
    /* 0c */ s32 mUnk_0c;
    /* 10 */ UnkPair020b502c mUnk_10;
    /* 18 */ s32 mUnk_18;
    /* 1c */ s16 mUnk_1c;
    /* 1e */ s16 mUnk_1e;
    /* 20 */ s32 mUnk_20;
    /* 24 */ s32 mUnk_24;
    /* 28 */ s32 mUnk_28;
    /* 2c */ UnkPair020b502c mUnk_2c;
    /* 34 */ UnkPair020b502c mUnk_34;
    /* 3c */ s64 mUnk_3c;
    /* 44 */ s64 mUnk_44;
    /* 4c */ UnkPair020b502c mUnk_4c;
    /* 54 */ UnkPair020b502c mUnk_54;
    /* 5c */ s64 mUnk_5c;
    /* 64 */ s64 mUnk_64;
    /* 6c */ UnkPair020b502c mUnk_6c;
    /* 74 */ UnkPair020b502c mUnk_74;
    /* 7c */ s64 mUnk_7c;
    /* 84 */ s64 mUnk_84;
    /* 8c */ s32 mUnk_8c;
    /* 90 */ Vec3 mUnk_90;
} Unk0217b3c0;

extern Unk0217b3c0 *data_0217b3c0;
extern Unk02175620 *data_02175620;

extern void func_0207a91c(Vec3 *dst, u8 idx);
extern void func_0207a948(Vec3 *dst, s32 idx);
extern u16 func_020435bc(void);
#include "Main/Unknown/code_020b47d8.h"
#include "Main/Unknown/code_020b6368.h"
#include "Main/Unknown/code_020b6a18.h"

s32 func_020b502c(s32 a, s32 b);
void func_020b503c(Unk020b503c *p, s32 scale);
s32 func_020b523c(void);
s32 func_020b5250(s32 x);
s32 func_020b5258(s32 x);
s32 func_020b5270(s32 x);
void func_020b5290(void);
u16 func_020b5628(s32 idx, s32 mask);
u16 func_020b5644(Unk02175628 *p, s32 mask);
void func_020b5658(Unk020b503c *out);
s32 func_020b57b4(s32 a, s64 k);
Unk020b57e4 *func_020b57e4(void);
void func_020b57f8(Unk020b503c *out);
void func_020b58f8(Unk020b503c *out);
s32 func_020b5ae8(const Vec3 *pos, UnkPair020b502c *out, s32 unk, s32 flag, s32 flag2);
void func_020b5dcc(s32 idx, UnkPair020b502c *out, s32);
s32 func_020b5f68(const UnkPair020b502c *p);
void func_020b5fe4(const Vec3 *pos, UnkPair020b502c *out);
void func_020b6078(s32 idx, UnkPair020b502c *out);
u16 func_020b6338(s32 idx);

#include "Main/Unknown/code_0207a880.h"
