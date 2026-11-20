#pragma once

#include "types.h"
#include "matrix_3x3_basic.h"
#include "Main/MapObjects/attractor.h" // MapObject
#include "Main/MapObjects/wanwan_chain.h"
#include "Main/MapObjects/earthen_pipe_create.h"
#include "Main/MapObjects/send_obj_shadow.h"
#include "Main/Item/item_koura_w.h"
#include "particle_instance.h" // ParticleEmitter
#include "Main/Menu/second_menu_scene.h"

// A bubble effect map object: delay frames, bottom and initial height, angle, shadow matrix, kart mask and two particle
// effects.
typedef struct MkdEfBubbleObject {
    /* 00 */ MapObject mMapObject;
    /* a0 */ s32 mDelayFrameCount;
    /* a4 */ s32 mBottomY;
    /* a8 */ u16 mAngleZ;
    /* aa */ u8 mUnk_aa[2];
    /* ac */ s32 mInitialY;
    /* b0 */ ShadowMatrix mShadowMatrix;
    /* e4 */ u8 mKartMask;
    /* e5 */ u8 mUnk_e5[3];
    /* e8 */ ParticleEmitter *mFirstEffect;
    /* ec */ ParticleEmitter *mSecondEffect;
    /* f0 */ s32 mEffectMissing;
} MkdEfBubbleObject;

void CreateMkdEfBubble(void);
void InitMkdEfBubble(MkdEfBubbleObject *bubble, CourseMapRow *row);
MapObjectKindData *CreateGroupItemBoxKindData(void);
MapObjectList *CreateGroupItemBoxUpdateList(void);
void UpdateGroupItemBoxHeightOffset(void);
void UpdateGroupItemBox(void *unused, ItemBox *itemBox);

extern const u16 gGroupItemBoxEntryFlag;
extern const MapObjectList gGroupItemBoxUpdateListData;
extern const MapObjectKindData gGroupItemBoxKindData;
extern StateCallbacks gMkdEfBubbleStateTable[2];

extern u16 gGroupItemBoxHeightAngle;
extern MapObjectList *gGroupItemBoxUpdateList;
extern s32 gGroupItemBoxShadowScaleWord;
extern s32 gGroupItemBoxHeightOffset;
extern Vec3 gGroupItemBoxShadowScale;

