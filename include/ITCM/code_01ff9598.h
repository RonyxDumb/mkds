#pragma once

#include "types.h"

typedef struct Kart Kart;

// Six words of a table written by texmtxCalc_flagT_ and the functions after it, at 0x00, 0x04, 0x10, 0x14, 0x30 and 0x34.
typedef struct Unk01ff9598_A {
    /* 00 */ s32 mUnk_00;
    /* 04 */ s32 mUnk_04;
    /* 08 */ u8 mUnk_08[8];
    /* 10 */ s32 mUnk_10;
    /* 14 */ s32 mUnk_14;
    /* 18 */ u8 mUnk_18[0x18];
    /* 30 */ s32 mUnk_30;
    /* 34 */ s32 mUnk_34;
} Unk01ff9598_A;

// Read by texmtxCalc_flagT_, texmtxCalc_flagRS_, texmtxCalc_flagR_, texmtxCalc_flagS_ and texmtxCalc_flag_.
typedef struct Unk01ff9598 {
    /* 00 */ u8 mUnk_00[0x18];
    /* 18 */ s32 mUnk_18;
    /* 1c */ s32 mUnk_1c;
    /* 20 */ s16 mUnk_20;
    /* 22 */ s16 mUnk_22;
    /* 24 */ s32 mUnk_24;
    /* 28 */ s32 mUnk_28;
    /* 2c */ u16 mUnk_2c;
    /* 2e */ u16 mUnk_2e;
} Unk01ff9598;

// Object with a flag word at 0x00, vectors at 0x04 and 0x10, and blocks at 0x28 and 0x4c passed to NNS_G3dGeBufferOP_N.
typedef struct Unk01ff9940 {
    /* 00 */ u32 mUnk_00;
    /* 04 */ Vec3 mUnk_04;
    /* 10 */ Vec3 mUnk_10;
    /* 1c */ u8 mUnk_1c[0xc];
    /* 28 */ u8 mUnk_28[0x24];
    /* 4c */ u8 mUnk_4c[0xc];
} Unk01ff9940;

typedef struct Unk01ff9940_B {
    /* 00 */ Vec3 mUnk_00;
    /* 0c */ Vec3 mUnk_0c;
} Unk01ff9940_B;

typedef struct Unk01ff9940_C {
    /* 00 */ u8 mUnk_00;
    /* 01 */ u8 mUnk_01;
    /* 02 */ u8 mUnk_02;
    /* 03 */ u8 mUnk_03;
} Unk01ff9940_C;

void texmtxCalc_flagT_(Unk01ff9598_A *a, Unk01ff9598 *b);
void texmtxCalc_flagRS_(Unk01ff9598_A *a, Unk01ff9598 *b);
void texmtxCalc_flagR_(Unk01ff9598_A *a, Unk01ff9598 *b);
void texmtxCalc_flagS_(Unk01ff9598_A *a, Unk01ff9598 *b);
void texmtxCalc_flag_(Unk01ff9598_A *a, Unk01ff9598 *b);
void func_01ff9940(Unk01ff9940 *a, Unk01ff9940_B *b, Unk01ff9940_C *c, u32 d);
void NNSi_G3dSendJointSRTMaya(Unk01ff9940 *a);
void driver_updateDriftEffects(Kart *p);
void AdvanceKartHop(Kart *p);
void driver_updateMap2DShadowFlag(Kart *p, u32 a);
void func_01ff9cb0(Kart *p);
void driver_handleSpecialBoosts(Kart *p);
void driver_handleFloorCollision(Kart *p);
void AdvanceKartOrientation(Kart *p, Vec3 *a);
void UpdateKartAirborne(Kart *p);
void AdvanceKartQuaternionBlendFactor(Kart *p, const Vec3 *a);
BOOL driver_handleFallBelow0(Kart *p);
void driver_1FFA350(Kart *p, u32 a);
BOOL func_01ffa380(Kart *p, u32 a, Vec3 *b);
BOOL func_01ffa41c(Kart *p, u32 a, Vec3 *b);
BOOL func_01ffa478(Kart *p, u32 a, Vec3 *b);
