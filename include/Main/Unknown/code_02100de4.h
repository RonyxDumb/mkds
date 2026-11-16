#pragma once

#include "types.h"
#include "Main/Unknown/code_0206bcb0.h"
#include "Main/Unknown/code_020f36d8.h"

// Object of item kind 11, element of it_sItemsets[11].
typedef struct ItemTeresa {
    /* 000 */ ItemObject field0;
    /* 12c */ u8 field12C[4];
    /* 130 */ u32 mStateFrames;
    /* 134 */ u8 field134[0x6];
    /* 13a */ u16 mState;
    /* 13c */ u16 mNextState;
    /* 13e */ u16 mNextStateRequested;
    /* 140 */ s32 mPickedKartIndex;
    /* 144 */ BOOL field144;
    /* 148 */ BOOL field148;
    /* 14c */ s32 mSavedOffsetY;
    /* 150 */ s32 mSavedOffsetVelocityY;
    /* 154 */ s32 mItemInfoIndex;
    /* 158 */ s32 mItemCount;
    /* 15c */ BOOL field15C;
    /* 160 */ s32 mItemObjectKind;
    /* 164 */ s16 mItemModelAlpha;
    /* 166 */ u8 field166[0x2];
    /* 168 */ Kart *mKart;
    /* 16c */ s32 mOffsetX;
    /* 170 */ s32 mOffsetY;
    /* 174 */ s32 mOffsetZ;
    /* 178 */ s32 mOffsetVelocityX;
    /* 17c */ s32 mOffsetVelocityY;
    /* 180 */ s32 mOffsetVelocityZ;
    /* 184 */ Vec3 mKartDrawMatrixPos;
    /* 190 */ Vec3 mKartVelocity;
    /* 19c */ s32 field19C;
    /* 1a0 */ s32 field1A0;
    /* 1a4 */ SegmentPoints field1A4;
    /* 248 */ s32 mPointIndex;
    /* 24c */ BOOL field24C;
    /* 250 */ s32 field250;
    /* 254 */ s32 field254;
    /* 258 */ s32 field258;
    /* 25c */ s32 field25C;
    /* 260 */ s32 field260;
    /* 264 */ u32 field264;
    /* 268 */ s32 field268;
    /* 26c */ BOOL field26C;
    /* 270 */ s32 mStallFrames;
} ItemTeresa;

// First argument of ittrsa_2101D18: objects at 0x0c and 0x10.
typedef struct Unk02101d18 {
    /* 00 */ u8 field0[0xc];
    /* 0c */ struct KartItems *fieldC;
    /* 10 */ Kart *field10;
} Unk02101d18;

s32 func_02101014(ItemTeresa *teresa);
void EnterItemTeresaState2(ItemTeresa *teresa);
s32 func_021014a0(ItemTeresa *teresa, s32 param_2, s32 param_3);
BOOL func_02101618(ItemTeresa *teresa, s32 param_2, s32 param_3);
void func_0210174c(ItemTeresa *teresa);
void EnterItemTeresaState0(ItemTeresa *teresa);
void func_02101964(ItemTeresa *teresa, s32 param_2);
void UpdateItemTeresaState0(ItemTeresa *teresa);
void EnterItemTeresaState1(ItemTeresa *teresa);
void UpdateItemTeresaState1(ItemTeresa *teresa);
void PickItemTeresaKartBattle(ItemTeresa *teresa, s32 param_2);
void PickItemTeresaKartByRank(ItemTeresa *teresa, s32 param_2);
void UpdateItemTeresaState2(ItemTeresa *teresa);
void ittrsa_2101C84(ItemTeresa *teresa);
void ittrsa_2101D18(Unk02101d18 *inUse, ItemTeresa *teresa);
