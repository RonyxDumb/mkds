#pragma once

#include "types.h"
#include "fx_mtx33.h"
#include "Main/MapObjects/attractor.h" // MapObject
#include "Main/MapObjects/choropu.h"
#include "Main/Unknown/unk_02158000.h" // MapObjectDrawList

extern const MapObjectDrawList data_0215887c;
extern const MapObjectDrawList data_02158be4;
extern const MapObjectDrawList data_02158c10;

// Object of kind 0xcc (Bridge) that InitBridge fills.
typedef struct Bridge {
    /* 000 */ CollisionMapObject mCollisionMapObject;
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
void DrawChoropu(s32 unused, Choropu *choropu, s32 unusedArg, u16 alpha);
