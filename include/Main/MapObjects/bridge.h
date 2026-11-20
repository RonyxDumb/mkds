#pragma once

#include "types.h"
#include "matrix_3x3_basic.h"
#include "Main/MapObjects/attractor.h" // MapObject
#include "Main/MapObjects/choropu.h"
#include "Main/MapObjects/map_object_draw_list_flags.h" // MapObjectDrawList
#include "Main/Graphics/nsbmd_render_obj.h"
#include "Main/Graphics/model_animation.h"
#include "Main/MapObjects/pendulum.h"

// A swinging bridge map object: its collision data, swing amplitude and angles, pause frame counts and timer, and
// animation frame index.
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
MapObjectKindData *CreateChoropuKindData(void);
MapObjectList *CreateChoropuDrawList(void);
MapObjectList *CreateChoropuShadowDrawList(void);
MapObjectList *CreateChoropuUpdateList(void);
void SetupDrawChoropu(void);
void DrawChoropu(s32 unused, Choropu *choropu, s32 unusedArg, u16 alpha);

extern const Vec3 gChoropuZeroVector;

extern struct MapObjectList *gChoropuUpdateList;
extern struct MapObjectDrawList *gChoropuDrawList;
extern struct NsbmdModel *gChoropu;
extern struct ModelAnimation *gBridgeNsbca;
extern struct MapObjectDrawList *gChoropuShadowDrawList;
extern struct BridgeDrawList *gBridgeDrawList;
extern struct MapObjectList *gBridgeUpdateList;
extern struct Nsbmd *gRotaryRoom;
extern struct Nsbmd *gBridge;
extern struct Nsbmd *gGearWhite;
extern struct Nsbmd *gGearBlack;
extern struct MapObjectList *gRotaryUpdateList;
extern struct Nsbmd *gRotaryBridge;
extern void *gRotaryDrawList;
extern struct Nsbmd *gTestCylinder;
