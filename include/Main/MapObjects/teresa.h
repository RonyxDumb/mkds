#pragma once

#include "types.h"
#include "matrix_3x3_basic.h"
#include "Main/MapObjects/attractor.h"
#include "01/MapObjects/map_object_model.h"

#define TERESA_ALPHA_FIXED12_MIN 0x2000
#define TERESA_NEVER_FRAMES 0xffff

// A wobble of an angle and a value that swings around mMid by mAmplitude; Teresa, Crab and the trophy use it.
typedef struct TeresaWobble {
    /* 00 */ u16 mAngle;
    /* 02 */ u8 mUnk_02[2];
    /* 04 */ s32 mValue;
    /* 08 */ s32 mValueDelta;
    /* 0c */ s32 mMid;
    /* 10 */ s32 mAmplitude;
    /* 14 */ s32 mAmplitudePerFrame;
    /* 18 */ s32 mAnglePerFrame;
    /* 1c */ s32 mAnglePerFrameDelta;
} TeresaWobble;

// Object of kind 0x13b (Teresa), returned by UnparkFirstParkedMapObject for FindMapObjectKindUpdateList(0x13b), filled
// by StartTeresa. The pool objects are made by another kind's init (InitTeresaSpawner).
typedef struct Teresa {
    /* 000 */ MapObject mMapObject;
    /* 0a0 */ Vec3 mStartPos;
    /* 0ac */ u16 mModelAlpha;
    /* 0ae */ u16 mNsbtpFrameIndex;
    /* 0b0 */ u16 mMirror;
    /* 0b2 */ u8 mUnk_b2[2];
    /* 0b4 */ s32 mFadeInDelayFrames;
    /* 0b8 */ s32 mFadeOutDelayFrames;
    /* 0bc */ TeresaWobble mAngleWobble;
    /* 0dc */ TeresaWobble mYWobble;
    /* 0fc */ s32 mAlphaFixed12;
    /* 100 */ s32 mAlphaFixed12PerFrame;
    /* 104 */ s32 mAlphaFixed12Min;
    /* 108 */ s32 mAlphaFixed12Max;
    /* 10c */ s32 mRadius;
    /* State number of this kind's own per-frame switch in UpdateTeresa; this object does not use
       MapObject.mUnk_80's state machine */
    /* 110 */ s32 mState;
} Teresa;

s32 GetUnparkedTeresaCount(void);
void StartTeresa(Vec3 *startPos);
void ClearTeresaTimers(void);
MapObjectList *CreateTeresaUpdateList(void);
MapObjectList *CreateTeresaDrawList(void);
void UpdateTeresa(void *mapObjectList, Teresa *teresa); /* skipped for objects with mFlags & 4 (parked pool objects) */
s16 TeresaFX_CosIdx(s32 angle);
s32 TeresaFX_MulInline(s32 multiplicand, s32 multiplier);
s16 TeresaFX_SinIdx(s32 angle);
void InitTeresaObjects(MapObjectList *mapObjectList);
void DrawTeresa(void *mapObjectList, Teresa *teresa);
void SetupDrawTeresa(void *mapObjectList);
void CreateTeresa(MapObjectList *mapObjectList); /* also sets word +0x1c of the group record to 1 */
void InitTeresa(MapObject *mapObject); /* parks the pooled object (ParkMapObject) and zeroes the live-Teresa count
                                          gUnparkedTeresaCount */

extern struct MapObjectModel *gTeresa;
extern u32 gUnparkedTeresaCount;
