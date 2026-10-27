#pragma once

#include "Main/Unknown/code_02074854.h"
#include "Main/Unknown/code_0207a104.h"
#include "Main/Unknown/code_02086080.h"
#include "Main/Unknown/code_0210a578.h"

#include "types.h"
#include "code_02148538.h"
#include "Main/Unknown/code_02039860.h"
#include "Main/Unknown/unk_02175628.h"
#include "Main/Unknown/unk_021759c0.h"

typedef struct UnkVec16 {
    s16 x;
    s16 y;
    s16 z;
} UnkVec16;

typedef struct Unk0206c1ac_B {
    /* 0 */ u32 mUnk_00;
    /* 4 */ Vec3 mUnk_04;
} Unk0206c1ac_B;

typedef struct Unk0206c1ac_A {
    /* 0 */ Unk0206c1ac_B *mUnk_00;
} Unk0206c1ac_A;

typedef struct Unk0206c1ac {
    /* 0 */ u8 mUnk_00[0x20];
    /* 20 */ Unk0206c1ac_A *mUnk_20;
    /* 24 */ u8 mUnk_24[4];
    /* 28 */ Vec3 mUnk_28;
    /* 34 */ u8 mUnk_34[0xc];
    /* 40 */ Vec3 mUnk_40;
    /* 4c */ u8 mUnk_4c[4];
    /* 50 */ UnkVec16 mUnk_50;
    /* 56 */ u8 mUnk_56[0x16];
    /* 6c */ s32 mUnk_6c;
} Unk0206c1ac;

typedef struct Unk0208c5b8 {
    /* 0 */ u8 mUnk_00[0x3c];
    /* 3c */ u32 mUnk_3c;
} Unk0208c5b8;

typedef struct Unk0206cdd4_A {
    /* 0 */ s32 mUnk_00;
    /* 4 */ s32 mUnk_04;
    /* 8 */ s32 mUnk_08;
    /* c */ u8 mUnk_0c[2];
    /* e */ s16 mUnk_0e;
    /* 10 */ s32 mUnk_10;
} Unk0206cdd4_A;

typedef struct Unk0206cdd4_B {
    /* 0 */ u8 mUnk_00[4];
    /* 4 */ s32 mUnk_04;
} Unk0206cdd4_B;

typedef struct Unk0217d26c {
    /* 0 */ s32 mUnk_00;
    /* 4 */ void *mUnk_04;
} Unk0217d26c;

extern Unk0217d26c data_0217d294;

typedef struct Unk0206ceb4 {
    /* 0 */ s16 mUnk_00;
    /* 2 */ u8 mUnk_02[0x1a];
    /* 1c */ s16 mUnk_1c;
} Unk0206ceb4;

typedef struct Unk0206bcb0_514 {
    /* 0 */ u8 mUnk_00[0x2c];
    /* 2c */ u32 mUnk_2c;
} Unk0206bcb0_514;

typedef struct Unk0206c5e4_208 {
    /* 0 */ s32 mUnk_00;
} Unk0206c5e4_208;

typedef struct Unk0206bcb0 {
    /* 0 */ u8 mUnk_00[0x30];
    /* 30 */ void (*mUnk_30)(void);
    /* 34 */ u8 mUnk_34[0x10];
    /* 44 */ vu32 mUnk_44;
    /* 48 */ vu32 mUnk_48;
    /* 4c */ vu32 mUnk_4c;
    /* 50 */ Vec3 mUnk_50;
    /* 05c */ Vec3 mUnk_05c;
    /* 68 */ Vec3 mUnk_68;
    /* 74 */ u16 mUnk_74;
    /* 76 */ u8 mUnk_76[0x2];
    /* 78 */ s32 mUnk_78;
    /* 7c */ vu32 mUnk_7c;
    /* 80 */ Vec3 mUnk_80;
    /* 8c */ Vec3 mUnk_8c;
    /* 98 */ Vec3 mUnk_98;
    /* a4 */ Vec3 mUnk_a4;
    /* 0b0 */ u8 mUnk_0b0[0x10];
    /* c0 */ s32 mUnk_c0;
    /* c4 */ s32 mUnk_c4;
    /* c8 */ u8 mUnk_c8[0xc];
    /* d4 */ u32 mUnk_d4;
    /* d8 */ s32 mUnk_d8;
    /* dc */ s32 mUnk_dc;
    /* e0 */ s32 mUnk_e0;
    /* e4 */ Vec3 mUnk_e4;
    /* f0 */ Vec3 mUnk_f0;
    /* fc */ u32 mUnk_fc;
    /* 100 */ s32 mUnk_100;
    /* 104 */ struct Unk020e04b0 *mUnk_104;
    /* 108 */ Vec3 mUnk_108;
    /* 114 */ u8 mUnk_114[6];
    /* 11a */ s16 mUnk_11a;
    /* 11c */ s32 mUnk_11c;
    /* 120 */ void (*mUnk_120)(struct Unk0206bcb0 *);
    /* 124 */ void (*mUnk_124)(struct Unk0206bcb0 *, Vec3 *, Vec3 *);
    /* 128 */ u8 mUnk_128[4];
    /* 12c */ Vec3 mUnk_12c;
    /* 138 */ Vec3 mUnk_138;
    /* 144 */ u8 mUnk_144[0xc];
    /* 150 */ Vec3 mUnk_150;
    /* 15c */ Vec3 mUnk_15c;
    /* 168 */ Vec3 mUnk_168;
    /* 174 */ u8 mUnk_174[0xc];
    /* 180 */ vs32 mUnk_180;
    /* 184 */ u8 mUnk_184[0x34];
    /* 1b8 */ Vec3 mUnk_1b8;
    /* 1c4 */ u8 mUnk_1c4[0xc];
    /* 1d0 */ s32 mUnk_1d0;
    /* 1d4 */ u8 mUnk_1d4[4];
    /* 1d8 */ s32 mUnk_1d8;
    /* 1dc */ u8 mUnk_1dc[4];
    /* 1e0 */ s32 mUnk_1e0;
    /* 1e4 */ u8 mUnk_1e4[0x18];
    /* 1fc */ Vec3 mUnk_1fc;
    /* 208 */ Unk0206c5e4_208 *mUnk_208;
    /* 20c */ u8 mUnk_20c[0x10];
    /* 21c */ s32 mUnk_21c;
    /* 220 */ s32 mUnk_220;
    /* 224 */ u8 mUnk_224[4];
    /* 228 */ struct Unk020f40dc_Owner *mUnk_228;
    /* 22c */ u8 mUnk_22c[0xa];
    /* 236 */ u16 mUnk_236;
    /* 238 */ s16 mUnk_238;
    /* 23a */ u8 mUnk_23a[0x2];
    /* 23c */ s16 mUnk_23c;
    /* 23e */ u8 mUnk_23e[2];
    /* 240 */ u32 mUnk_240;
    /* 244 */ Vec3 mUnk_244;
    /* 250 */ s32 mUnk_250;
    /* 254 */ s32 mUnk_254;
    /* 258 */ u8 mUnk_258[8];
    /* 260 */ s32 mUnk_260;
    /* 264 */ u8 mUnk_264[0x20];
    /* 284 */ Vec3 mUnk_284;
    /* 290 */ Vec3 mUnk_290;
    /* 29c */ s32 mUnk_29c;
    /* 2a0 */ u8 mUnk_2a0[4];
    /* 2a4 */ s32 mUnk_2a4;
    /* 2a8 */ s32 mUnk_2a8;
    /* 2ac */ u8 mUnk_2ac[0xc];
    /* 2b8 */ s32 mUnk_2b8;
    /* 2bc */ s32 mUnk_2bc;
    /* 2c0 */ u8 mUnk_2c0[0x4];
    /* 2c4 */ s32 mUnk_2c4;
    /* 2c8 */ u8 mUnk_2c8[0x4];
    /* 2cc */ Unk0206cdd4_A *mUnk_2cc;
    /* 2d0 */ u8 mUnk_2d0[0x2c];
    /* 2fc */ s32 mUnk_2fc;
    /* 300 */ u16 mUnk_300;
    /* 302 */ u16 mUnk_302;
    /* 304 */ u16 *mUnk_304;
    /* 308 */ u16 *mUnk_308;
    /* 30c */ s32 mUnk_30c;
    /* 310 */ u32 mUnk_310;
    /* 314 */ u8 mUnk_314[0x52];
    /* 366 */ u16 mUnk_366;
    /* 368 */ s32 mUnk_368;
    /* 36c */ u8 mUnk_36c[0x14];
    /* 380 */ u32 mUnk_380;
    /* 384 */ u8 mUnk_384[0x4];
    /* 388 */ s16 mUnk_388;
    /* 38a */ s16 mUnk_38a;
    /* 38c */ u8 mUnk_38c[0x24];
    /* 3b0 */ Vec3 mUnk_3b0;
    /* 3bc */ u8 mUnk_3bc[0x10];
    /* 3cc */ s32 mUnk_3cc;
    /* 3d0 */ u8 mUnk_3d0[0x10];
    /* 3e0 */ s32 mUnk_3e0;
    /* 3e4 */ s32 mUnk_3e4;
    /* 3e8 */ u8 mUnk_3e8[0x34];
    /* 41c */ Vec3 mUnk_41c;
    /* 428 */ Vec3 mUnk_428;
    /* 434 */ u8 mUnk_434[0x8c];
    /* 4c0 */ s32 mUnk_4c0;
    /* 4c4 */ u8 mUnk_4c4[0x40];
    /* 504 */ u16 mUnk_504;
    /* 506 */ u16 mUnk_506;
    /* 508 */ u8 mUnk_508[0xc];
    /* 514 */ Unk0206bcb0_514 *mUnk_514;
    /* 518 */ u8 mUnk_518[0x20];
    /* 538 */ Unk0206ceb4 mUnk_538;
    /* 556 */ u8 mUnk_556[0x3a];
    /* 590 */ void *mUnk_590;
} Unk0206bcb0;

extern Unk0206bcb0 *data_0217b8c8;

extern int data_02154f10[];

void func_0206bf88(Unk0206bcb0 *p, int mode);
int func_0206c094(Unk0206bcb0 *p);
int func_0206c0a8(Unk0206bcb0 *p);
int func_0206c0b0(Unk0206bcb0 *p);
int func_0206c0e0(Unk0206bcb0 *p);
void func_0206c11c(Unk0206bcb0 *p);
void func_0206c14c(Unk0206bcb0 *p);
void func_0206c17c(Unk0206bcb0 *p);
void func_0206c1ac(Unk0206c1ac *obj, Unk0206bcb0 *p);
void func_0206c2b4(Unk0206c1ac *obj, Unk0206bcb0 *p);
int func_0206c354(Unk0206bcb0 *p, const Vec3 *a, int flag);
void func_0206c450(Unk0206c1ac *obj, Unk0206bcb0 *p);
void func_0206c488(Unk0206c1ac *obj, Unk0206bcb0 *p);

void func_02055c5c(void);
void func_02068a64(Unk0206bcb0 *p, int a, int b);
void func_0207b0d0(Unk0206bcb0 *p);
void func_02080ee4(Unk0206bcb0 *p);
void func_02080e88(Unk0206c1ac *obj, Unk0206bcb0 *p);
Unk0208c5b8 *func_0208c5b8(int idx);
void func_0208c534(Unk0208c5b8 *p);
void func_0208c188(u32 arg);
void func_0208c1ac(u32 arg);
void func_0208b748(u32 idx, const Vec3 *pos, void *p, void (*cb)());
int func_0206c494(Unk0206bcb0 *p);
void func_0206cc60(Unk0206bcb0 *p, int arg);
void func_0208ccf0(Unk0208c5b8 *p);
void func_0208d6b0(Unk0208c5b8 *p);
void func_0208d650(Unk0208c5b8 *p);
void func_0210b4e0(Unk0206bcb0 *p, int dir, s32 a, s32 b);
void func_0206cdd4(Unk0206bcb0 *p);
void func_0206ceb4(s32 *out, Unk0206bcb0 *p);
extern Unk0217d26c data_0217d26c;
extern Unk0217d26c data_0217d284;
Unk0206cdd4_B *func_0207a6b0(void);
void func_0206d020(Unk0206bcb0 *p, int a, int b);
void func_01ffc9e8(Unk0206bcb0 *p, int a);
void func_020681f0(Unk0206bcb0 *p);
void func_02109078(Unk0206bcb0 *p, int a, int b, int c);
void func_0210ddf4(Unk0217d26c *queue, int key, void (*cb)(Unk0206bcb0 *, int), Unk0206bcb0 *p, int arg);
void func_020718c8(Unk0206bcb0 *p, int arg);
void func_02071944(Unk0206bcb0 *p, int arg);
#include "Main/Unknown/code_021035ac.h"
void func_02079f70(void *obj, u16 a, u16 b, u16 c);
int func_0206bcb0(Unk0206bcb0 *p, int a, int b);
int func_0206be54(Unk0206bcb0 *p, int a);
void func_0206bbb4(Unk0206bcb0 *p, int a, int b);
void func_0206c5e4(Unk0206bcb0 *p);
void func_020397a8(const Vec3 *a, const Vec3 *b, Vec3 *axb);
s32 func_02039828(const Vec3 *a, const Vec3 *b);
void func_02063b10(const Unk0206bcb0 *p, Vec3 *out);
void func_02063b30(const Unk0206bcb0 *p, Vec3 *out);

