#pragma once

#include "types.h"

typedef struct Kart Kart;

// Object read by driver_tryStartBackwardFlip: vectors at 0x04, 0x28, 0x34 and 0x40.
typedef struct Unk0206b020 {
    /* 00 */ u8 mUnk_00[4];
    /* 04 */ Vec3 mUnk_04;
    /* 10 */ u8 mUnk_10[0x18];
    /* 28 */ Vec3 mUnk_28;
    /* 34 */ Vec3 mUnk_34;
    /* 40 */ Vec3 mUnk_40;
} Unk0206b020;

extern const s16 driver_sThunderShrinkTimes[];
extern const s16 data_021654c4;
extern const s32 data_021654d0;
extern const s32 data_021654d4;
extern const s32 data_021654e0;
extern const s32 data_021654e4;
extern const s32 data_021654e8;
extern const s32 data_021654f0;
extern const s32 data_02165508;
extern const s32 data_0216550c;
extern const Vec4 data_0216556c;

void driver_updateThunderShrinkEffect(Kart *p);
void driver_startThunderShrinkEffect(Kart *p);
void driver_updateDoubleBackwardFlip(Kart *p);
s32 driver_startDoubleBackwardFlip(Kart *p, const Vec3 *a, s32 b);
void driver_updateBackwardFlip(Kart *p);
void driver_startBackwardFlip(Kart *p, const Vec3 *a, s32 b);
BOOL driver_tryStartBackwardFlip(Kart *p, Unk0206b020 *a);
void driver_updateForwardFlip(Kart *p);
void driver_startForwardFlip(Kart *p);
BOOL driver_tryStartForwardFlip(Kart *p);
void driver_updateThrowUp(Kart *p);
void driver_throwUp(Kart *p);
BOOL driver_tryThrowUp(Kart *p);
void driver_updateSpinOut(Kart *p);
void driver_startSpinOut(Kart *p, int a, int b);
