#pragma once

#include "types.h"
#include "code_02146d78.h"
#include "Main/Unknown/code_020e6fd4.h" // MapObject
#include "Main/Unknown/code_020e0680.h"

// Block of eleven words.
typedef struct Unk020e039c {
    /* 00 */ u32 mUnk_00[11];
} Unk020e039c;

extern const Unk020e039c data_0215887c;
extern const Unk020e039c data_02158be4;
extern const Unk020e039c data_02158c10;

// Object of kind 0xcc (Bridge) that InitBridge fills. Its draw callback DrawBridge is typed Unk020e3ef4 (the family
// layout of kinds 0xcb, 0xce, 0xd0 and 0xd1); the model pointer at +0x140, written by SetMapObjectsModel, lies inside
// mUnk_13c.
typedef struct Bridge {
    /* 000 */ MapObject mMapObject;
    /* 0a0 */ Unk020e005c_a0 mUnk_a0;
    /* 13c */ u8 mUnk_13c[0x8];
    /* 144 */ u16 mSwingAmplitude;
    /* 146 */ u16 mSwingAnglePerFrame;
    /* 148 */ u16 mSwingAngle;
    /* 14a */ u16 mAngleX;
    /* 14c */ u16 mPeakPauseFrameCount;
    /* 14e */ u16 mTroughPauseFrameCount;
    /* 150 */ u16 mPauseTimer;
    /* 152 */ u8 mUnk_152[0x2];
    /* 154 */ s32 mAnimationFrameIndex;
} Bridge;

BOOL IsBridgeKind(u32 kind);
void CreateBridge(void); /* no argument; also gives the model to the registered objects (SetMapObjectsModel) */
void InitBridge(Bridge *bridge, struct CourseMapRow *courseRow);
void *CreateChoropuKindData(void);
void *CreateChoropuDrawList(void);
void *CreateChoropuShadowDrawList(void);
void *CreateChoropuUpdateList(void);
void SetupDrawChoropu(void);
void DrawChoropu(s32 a, Unk020e1e98 *choropu, s32 c, u16 alpha);
