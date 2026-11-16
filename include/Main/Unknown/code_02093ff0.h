#pragma once

#include "types.h"
#include "code_02146d78.h"
#include "Main/Unknown/code_020e6fd4.h"

// 0x20-byte wobble of Teresa at 0xbc and 0xdc (written by tesa_spawn), of Crab at 0xb0 and 0xd0 and of the trophy
// at 0x08. For Teresa and the trophy, mAmplitudePerFrame and mUnk_1c are always 0 in this build; Crab's body wobble
// sets mAmplitudePerFrame.
typedef struct TeresaWobble {
    /* 00 */ u16 mAngle;
    /* 02 */ u8 mUnk_02[2];
    /* 04 */ s32 mValue;
    /* 08 */ s32 mUnk_08;
    /* 0c */ s32 mMid;
    /* 10 */ s32 mAmplitude;
    /* 14 */ s32 mAmplitudePerFrame;
    /* 18 */ s32 mAnglePerFrame;
    /* 1c */ s32 mUnk_1c;
} TeresaWobble;

// Object of kind 0x13b (Teresa), returned by mobj_acquireFreeObject for mobj_getLogicPartForObjectId(0x13b), filled
// by tesa_spawn. The pool objects are made by another kind's init (tsacnt_init in code_02094e1c.c); Unk02094db4 is a
// view of the draw group record, not of this object.
typedef struct Teresa {
    /* 000 */ MapObject mUnk_00;
    /* 0a0 */ Vec3 mStartPos;
    /* 0ac */ u16 mModelAlpha;
    /* 0ae */ u16 mNsbtpFrameIndex;
    /* 0b0 */ u16 mMirror;
    /* 0b2 */ u8 mUnk_b2[2];
    /* 0b4 */ s32 mState1Timer;
    /* 0b8 */ s32 mState0Timer;
    /* 0bc */ TeresaWobble mAngleWobble;
    /* 0dc */ TeresaWobble mYWobble;
    /* 0fc */ s32 mAlphaFixed12;
    /* 100 */ s32 mAlphaFixed12PerFrame;
    /* 104 */ s32 mAlphaFixed12Min;
    /* 108 */ s32 mAlphaFixed12Max;
    /* 10c */ s32 mUnk_10c;
    /* State number of this kind's own per-frame switch in tesa_update; this object does not use
       MapObject.mUnk_80's state machine */
    /* 110 */ s32 mState;
} Teresa;

// Object of tesa_loadModel: the word at 0x1c is set.
typedef struct Unk02094db4 {
    /* 00 */ u8 mUnk_00[0x1c];
    /* 1c */ s32 mUnk_1c;
} Unk02094db4;

s32 tesa_getActiveInstanceCount(void);
void tesa_spawn(Vec3 *startPos);
void tesa_20946B8(void);
void tesa_setupLogicPart(void);
void tesa_setupRenderPart(void);
void tesa_update(void *a, Teresa *teresa); /* skipped for objects with mFlags & 4 (parked pool objects) */
s16 tesa_FX_CosIdx(s32 angle);
s32 tesa_FX_MulInline(s32 a, s32 b);
s16 tesa_FX_SinIdx(s32 angle);
void tesa_globalLogicInit(MapObjectList *mapObjectList);
void tesa_render(void *a, Teresa *teresa);
void tesa_applyMaterial(void *a);
void tesa_loadModel(Unk02094db4 *a); /* also sets word +0x1c of the group record to 1 */
u32 tesa_init(
    u32 arg0); /* parks the pooled object (mobj_setInvisible) and zeroes the live-Teresa count tesa_sActiveInstanceCount */
