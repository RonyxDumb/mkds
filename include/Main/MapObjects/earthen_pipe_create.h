#pragma once

#include "types.h"
#include "fx_mtx33.h"
#include "Main/MapObjects/attractor.h" // MapObject
#include "Main/MapObjects/wanwan_chain.h"
#include "Main/MapObjects/pendulum.h"
#include "Main/MapObjects/group_follower_advance.h"
#include "Main/MapObjects/send_obj_shadow.h"
#include "Main/Item/item_koura_w.h" // CourseMapRow
#include "Main/MapObjects/data_02158000.h"

struct ItemFBox;

// Object of 0x108 or more bytes handled by InitItemBox.
typedef struct ItemBox {
    /* 000 */ MapObject mMapObject;
    /* 0a0 */ u16 mBoxRotationIndex;
    /* 0a2 */ u16 mQuestionRotationIndex;
    /* 0a4 */ u16 mFramesSinceHit;
    /* 0a6 */ u8 mUnk_0a6[2];
    /* 0a8 */ s32 mUsesGroupShadow;
    /* 0ac */ s32 mShortSpin;
    /* 0b0 */ s16 mShadowMode;
    /* 0b2 */ u8 mUnk_0b2[2];
    /* 0b4 */ ShadowMatrix mUnk_0b4;
    /* 0e8 */ s32 mBoxAlpha;
    /* 0ec */ s32 mQuestionAlpha;
    /* 0f0 */ u16 mPolygonId;
    /* 0f2 */ u16 mForcedRowHumanGhostPeer;
    /* 0f4 */ u16 mForcedRowCpu;
    /* 0f6 */ u8 mUnk_0f6[2];
    /* 0f8 */ s32 mNoCourseRow;
    /* 0fc */ Vec3 *mPositionSource;
    /* 100 */ void (*mDrawMatrixCallback)(struct ItemFBox *owner, MtxFx43 *out);
    /* 104 */ struct ItemFBox *mDrawMatrixCallbackOwner;
    /* 108 */ GroupFollowerWithSpeeds mFollower;
} ItemBox;

void CreateBoxAndQuestion(void);
void InitItemBox(ItemBox *itemBox, CourseMapRow *row);
MapObjectKindData *CreateEarthenPipeKindData(void);
MapObjectDrawList *CreateEarthenPipeDrawList(void);
MapObjectList *CreateEarthenPipeUpdateList(void);
void SetupDrawEarthenPipe(void);

extern const MapObjectList gEarthenPipeUpdateListData;
extern const MapObjectDrawList gEarthenPipeDrawListData;
extern const MapObjectKindData gEarthenPipeKindData;
extern struct NsbmdModel *gEarthenPipe2;
