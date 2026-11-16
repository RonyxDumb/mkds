#pragma once

#include "types.h"
#include "Main/Unknown/code_0206bcb0.h"
#include "Main/Unknown/code_020e5d0c.h"
#include "Main/Unknown/code_020f36d8.h"

// Object of item kind 10, element of it_sItemsets[10].
typedef struct ItemGesso {
    /* 000 */ ItemObject field0;
    /* 12c */ Kart *mKart;
    /* 130 */ u8 mOrthoQuadCounts[0x8];
    /* 138 */ s32 mStepIndex;
    /* 13c */ Vec3 mViewOffset;
    /* 148 */ s32 mVelocityX;
    /* 14c */ s32 mVelocityY;
    /* 150 */ s32 field150;
    /* 154 */ s32 mTargetVelocityX;
    /* 158 */ s32 mTargetVelocityY;
    /* 15c */ s32 field15C;
    /* 160 */ BOOL field160;
    /* 164 */ s32 mApproachRate;
    /* 168 */ s32 mDamping;
    /* 16c */ s32 mStepTimer;
    /* 170 */ s32 field170;
    /* 174 */ s32 field174;
    /* 178 */ s32 field178;
    /* 17c */ s32 field17C;
    /* 180 */ s32 field180;
    /* 184 */ Vec3 field184;
    /* 190 */ u8 field190[0x4];
    /* 194 */ s32 field194;
    /* 198 */ BOOL mVisible;
    /* 19c */ s32 field19C;
    /* 1a0 */ u8 field1A0[0x14];
} ItemGesso;

// Row of the 0xc-byte table behind gItemGessoSteps.
typedef struct ItemGessoStep {
    /* 00 */ s16 mTargetVelocityX;
    /* 02 */ s16 mTargetVelocityY;
    /* 04 */ s16 mApproachRate;
    /* 06 */ s16 mDamping;
    /* 08 */ u16 field8;
    /* 0a */ u16 fieldA;
} ItemGessoStep;

extern ItemGessoStep gItemGessoSteps[];

void CreateItemTeresaFrameScaleTable(void);
void itgsso_2102718(void);
void itgsso_2102744(ItemGesso *gesso);
void itgsso_2102764(void *data, ItemGesso *gesso, void *toData);
void itgsso_21027AC(ItemGesso *p, s32 param_2, NsbmdModel *t);
void itgsso_210298C(ItemGesso *p);
