#pragma once

#include "types.h"
#include "fx_mtx33.h"
#include "Main/MapObjects/attractor.h" // MapObject

// Object behind StopTurningMoveFollowsAngle and the per-state functions around StartIwanteHandsHitReaction.
typedef struct MissionRunPrm {
    /* 000 */ s32 mCounterLimit;
    /* 004 */ s32 mScale;
    /* 008 */ s32 mCollisionOffsetY;
    /* 00c */ s32 mCollisionExtentXZ;
    /* 010 */ s32 mCourseHitVelocityScale;
    /* 014 */ s32 mFreeVelocityScale;
    /* 018 */ s32 mStopSpeedLimit;
    /* 01c */ s32 mGravity;
    /* 020 */ s32 mBounceScale;
    /* 024 */ s32 mKartPushPosStep;
    /* 028 */ s32 mKartPushVelocity;
    /* 02c */ s32 mItemPushVelocity;
    /* 030 */ s32 mWallPushVelocity;
    /* 034 */ s32 mUnk_034;
    /* 038 */ s32 mUnk_038;
    /* 03c */ s32 mUnk_03c;
    /* 040 */ s32 mUnk_040;
    /* 044 */ s32 mUnk_044;
    /* 048 */ s32 mUnk_048;
    /* 04c */ s32 mUnk_04c;
    /* 050 */ s32 mUnk_050;
    /* 054 */ s32 mUnk_054;
    /* 058 */ s32 mUnk_058;
    /* 05c */ s32 mUnk_05c;
    /* 060 */ s32 mUnk_060;
    /* 064 */ s32 mUnk_064;
    /* 068 */ s32 mUnk_068;
    /* 06c */ s32 mUnk_06c;
    /* 070 */ s32 mUnk_070;
    /* 074 */ s32 mUnk_074;
    /* 078 */ s32 mUnk_078;
    /* 07c */ s32 mUnk_07c;
    /* 080 */ s32 mUnk_080;
    /* 084 */ s32 mUnk_084;
    /* 088 */ s32 mUnk_088;
    /* 08c */ s32 mUnk_08c;
    /* 090 */ s32 mUnk_090;
    /* 094 */ s32 mUnk_094;
    /* 098 */ s32 mUnk_098;
    /* 09c */ s32 mUnk_09c;
    /* 0a0 */ s32 mUnk_0a0;
    /* 0a4 */ s32 mUnk_0a4;
    /* 0a8 */ s32 mUnk_0a8;
    /* 0ac */ s32 mUnk_0ac;
    /* 0b0 */ s32 mUnk_0b0;
    /* 0b4 */ s32 mUnk_0b4;
    /* 0b8 */ s32 mUnk_0b8;
    /* 0bc */ s32 mUnk_0bc;
    /* 0c0 */ s32 mUnk_0c0;
    /* 0c4 */ s32 mUnk_0c4;
    /* 0c8 */ s32 mUnk_0c8;
    /* 0cc */ s32 mUnk_0cc;
    /* 0d0 */ s32 mUnk_0d0;
    /* 0d4 */ s32 mUnk_0d4;
    /* 0d8 */ s32 mUnk_0d8;
    /* 0dc */ s32 mUnk_0dc;
    /* 0e0 */ s32 mUnk_0e0;
    /* 0e4 */ s32 mUnk_0e4;
    /* 0e8 */ s32 mUnk_0e8;
    /* 0ec */ s32 mUnk_0ec;
    /* 0f0 */ s32 mUnk_0f0;
    /* 0f4 */ s32 mUnk_0f4;
    /* 0f8 */ s32 mUnk_0f8;
    /* 0fc */ s32 mUnk_0fc;
    /* 100 */ s32 mUnk_100;
    /* 104 */ s32 mUnk_104;
    /* 108 */ s32 mUnk_108;
    /* 10c */ s32 mUnk_10c;
    /* 110 */ s32 mUnk_110;
    /* 114 */ s32 mUnk_114;
    /* 118 */ s32 mUnk_118;
    /* 11c */ s32 mUnk_11c;
    /* 120 */ s32 mUnk_120;
    /* 124 */ s32 mUnk_124;
    /* 128 */ s32 mUnk_128;
    /* 12c */ s32 mUnk_12c;
    /* 130 */ s32 mUnk_130;
    /* 134 */ s32 mUnk_134;
    /* 138 */ s32 mUnk_138;
    /* 13c */ s32 mUnk_13c;
    /* 140 */ s32 mUnk_140;
    /* 144 */ s32 mUnk_144;
    /* 148 */ s32 mUnk_148;
    /* 14c */ s32 mUnk_14c;
    /* 150 */ s32 mUnk_150;
    /* 154 */ s32 mUnk_154;
    /* 158 */ s32 mUnk_158;
    /* 15c */ s32 mUnk_15c;
    /* 160 */ s32 mUnk_160;
    /* 164 */ s32 mUnk_164;
    /* 168 */ s32 mUnk_168;
    /* 16c */ s32 mUnk_16c;
    /* 170 */ s32 mUnk_170;
    /* 174 */ s32 mUnk_174;
    /* 178 */ s32 mUnk_178;
    /* 17c */ s32 mUnk_17c;
    /* 180 */ s32 mUnk_180;
    /* 184 */ s32 mUnk_184;
    /* 188 */ s32 mUnk_188;
    /* 18c */ s32 mUnk_18c;
    /* 190 */ s32 mUnk_190;
    /* 194 */ s32 mUnk_194;
    /* 198 */ s32 mUnk_198;
    /* 19c */ s32 mUnk_19c;
    /* 1a0 */ s32 mUnk_1a0;
    /* 1a4 */ s32 mUnk_1a4;
    /* 1a8 */ s32 mUnk_1a8;
    /* 1ac */ s32 mUnk_1ac;
    /* 1b0 */ s32 mUnk_1b0;
    /* 1b4 */ s32 mUnk_1b4;
    /* 1b8 */ s32 mUnk_1b8;
    /* 1bc */ s32 mUnk_1bc;
    /* 1c0 */ s32 mUnk_1c0;
    /* 1c4 */ s32 mUnk_1c4;
    /* 1c8 */ s32 mUnk_1c8;
    /* 1cc */ s32 mUnk_1cc;
    /* 1d0 */ s32 mUnk_1d0;
    /* 1d4 */ s32 mUnk_1d4;
    /* 1d8 */ s32 mUnk_1d8;
    /* 1dc */ s32 mUnk_1dc;
    /* 1e0 */ s32 mUnk_1e0;
    /* 1e4 */ s32 mUnk_1e4;
    /* 1e8 */ s32 mUnk_1e8;
    /* 1ec */ u32 mUnk_1ec;
    /* 1f0 */ s32 mUnk_1f0;
    /* 1f4 */ s32 mUnk_1f4;
    /* 1f8 */ s32 mUnk_1f8;
    /* 1fc */ s32 mUnk_1fc;
    /* 200 */ s32 mUnk_200;
    /* 204 */ s32 mUnk_204;
    /* 208 */ s32 mUnk_208;
    /* 20c */ s32 mUnk_20c;
    /* 210 */ s32 mUnk_210;
    /* 214 */ s32 mUnk_214;
    /* 218 */ s32 mUnk_218;
    /* 21c */ s32 mUnk_21c;
    /* 220 */ s32 mUnk_220;
    /* 224 */ s32 mUnk_224;
    /* 228 */ s32 mUnk_228;
    /* 22c */ s32 mUnk_22c;
    /* 230 */ s32 mUnk_230;
    /* 234 */ s32 mUnk_234;
    /* 238 */ s32 mUnk_238;
    /* 23c */ s32 mUnk_23c;
    /* 240 */ s32 mUnk_240;
    /* 244 */ s32 mUnk_244;
    /* 248 */ s32 mUnk_248;
    /* 24c */ s32 mUnk_24c;
    /* 250 */ s32 mUnk_250;
    /* 254 */ s32 mUnk_254;
    /* 258 */ s32 mUnk_258;
    /* 25c */ u8 mUnk_25c[0x10];
    /* 26c */ s32 mUnk_26c;
    /* 270 */ s32 mUnk_270;
    /* 274 */ s32 mUnk_274;
    /* 278 */ s32 mUnk_278;
    /* 27c */ s32 mUnk_27c;
    /* 280 */ s32 mUnk_280;
    /* 284 */ u8 mUnk_284[0x8];
    /* 28c */ s32 mUnk_28c;
    /* 290 */ s32 mUnk_290;
    /* 294 */ s32 mUnk_294;
    /* 298 */ s32 mUnk_298;
    /* 29c */ s32 mUnk_29c;
    /* 2a0 */ s32 mUnk_2a0;
    /* 2a4 */ s32 mUnk_2a4;
    /* 2a8 */ s32 mUnk_2a8;
    /* 2ac */ s32 mUnk_2ac;
    /* 2b0 */ s32 mUnk_2b0;
    /* 2b4 */ s32 mUnk_2b4;
    /* 2b8 */ s32 mUnk_2b8;
    /* 2bc */ u32 mUnk_2bc;
    /* 2c0 */ u32 mUnk_2c0;
    /* 2c4 */ u32 mUnk_2c4;
    /* 2c8 */ s32 mUnk_2c8;
    /* 2cc */ s32 mUnk_2cc;
} MissionRunPrm;

// Values of MissionRunMapObjectEffect.mKind: where ComputeEffectPosition puts the effect. Offsets are turned by the
// angle of the object; MODEL is the effect of a model started at the water height; the camera position is added in
// ROTATED_OFFSET_CAMERA (never set).
enum {
    MAP_OBJECT_EFFECT_MODEL,
    MAP_OBJECT_EFFECT_ROTATED_OFFSET,
    MAP_OBJECT_EFFECT_SCALED_OFFSET,
    MAP_OBJECT_EFFECT_ROTATED_OFFSET_CAMERA,
    MAP_OBJECT_EFFECT_ROW_HEIGHT,
    MAP_OBJECT_EFFECT_WATER_HEIGHT,
};

typedef struct MissionRunMapObjectEffect {
    /* 00 */ s32 mKind;
    /* 04 */ s32 mTimer;
    /* 08 */ Vec3 mOffset;
    /* 14 */ void *mEffect;
} MissionRunMapObjectEffect;

enum {
    MAP_OBJECT_ANGLE_NONE,
    MAP_OBJECT_ANGLE_FOLLOW_MOVE_ANGLE,
    MAP_OBJECT_ANGLE_TURN_TO_POINT,
    MAP_OBJECT_ANGLE_TURN_FROM_POINT,
    MAP_OBJECT_ANGLE_TURN_SIDEWAYS,
    MAP_OBJECT_ANGLE_SPIN,
    MAP_OBJECT_ANGLE_SPIN_CHOOSE_DIRECTION,
    MAP_OBJECT_ANGLE_SPIN_NEGATIVE,
    MAP_OBJECT_ANGLE_SPIN_POSITIVE,
};

// Values of mMoveAngleMode: how mMoveAngle changes. It stays, copies mAngle, or turns toward or away from
// mMoveAnglePoint (or sideways to it) by mMoveAnglePerCall.
enum {
    MAP_OBJECT_MOVE_ANGLE_KEEP,
    MAP_OBJECT_MOVE_ANGLE_FOLLOW_ANGLE,
    MAP_OBJECT_MOVE_ANGLE_TURN_TO_POINT,
    MAP_OBJECT_MOVE_ANGLE_TURN_FROM_POINT,
    MAP_OBJECT_MOVE_ANGLE_TURN_SIDEWAYS,
};

// Values of MissionRunMapObject.mShadowMode: where the shadow is drawn. The first two put it on the course map row of
// the object (the second when no height offset was given), AT_OBJECT at the position of the object, AT_NODE under the
// node position.
enum {
    MAP_OBJECT_SHADOW_COURSE_OFFSET,
    MAP_OBJECT_SHADOW_COURSE,
    MAP_OBJECT_SHADOW_AT_OBJECT,
    MAP_OBJECT_SHADOW_AT_NODE,
};

// Values of MissionRunMapObject.mCollisionShape: the body the kart and item hit tests use.
enum {
    MAP_OBJECT_COLLISION_SPHERE,
    MAP_OBJECT_COLLISION_BOX,
    MAP_OBJECT_COLLISION_CYLINDER,
};

// Values of MissionRunMapObject.mCourseCollisionMode: how the object is moved out of the course. ALT_FILTER uses the
// other course collision filter; PUSH_Y_ONLY moves it only up or down and PUSH_Y_ONLY_NO_BITS also skips the checks of
// the collision bits.
enum {
    MAP_OBJECT_COURSE_COLLISION_PUSH_OUT,
    MAP_OBJECT_COURSE_COLLISION_ALT_FILTER,
    MAP_OBJECT_COURSE_COLLISION_PUSH_Y_ONLY_NO_BITS,
    MAP_OBJECT_COURSE_COLLISION_PUSH_Y_ONLY,
};

// Values of mKartResponse: the index into the kart's collision response table (gCollideKartWithMapObjectResponses).
enum {
    KART_MAP_OBJECT_RESPONSE_NONE = 0,
    KART_MAP_OBJECT_RESPONSE_BUMP = 2,
    KART_MAP_OBJECT_RESPONSE_FLIP_DOUBLE = 10,
    KART_MAP_OBJECT_RESPONSE_SCALE_EFFECT = 11,
    KART_MAP_OBJECT_RESPONSE_CARRY = 12,
    KART_MAP_OBJECT_RESPONSE_CARRY_HALT = 13,
    KART_MAP_OBJECT_RESPONSE_CARRY_SPIN = 14,
};

// Values of mItemResponse, which CollideItemWithMissionRunMapObject returns as the hit type of ApplyItemObjectHitType:
// the item bounces off the object, or is pushed away and fades out.
enum {
    ITEM_MAP_OBJECT_RESPONSE_BOUNCE = 1,
    ITEM_MAP_OBJECT_RESPONSE_PUSH_FADE_OUT = 2,
};

// Layout provisional: functions on objects that share this prefix use different types at 0xa0 and 0xa8.
typedef struct MissionRunMapObject {
    /* 000 */ MapObject mUnk_000;
    /* 0a0 */ MissionRunPrm *mPrm;
    /* 0a4 */ struct MissionRunMapObject *mPreviousObject;
    /* 0a8 */ s32 mUnk_0a8;
    /* 0ac */ s32 mUnk_0ac;
    /* 0b0 */ s32 mStateFrames;
    /* 0b4 */ s32 mRepeatsRemaining;
    /* 0b8 */ s32 mUnk_0b8;
    /* 0bc */ MissionRunMapObjectEffect mEffects[5];
    /* 134 */ s32 mUnk_134;
    /* 138 */ s32 mUnk_138;
    /* 13c */ s32 mUnk_13c;
    /* 140 */ s32 mUnk_140;
    /* 144 */ s32 mUnk_144;
    /* 148 */ s32 mEntryGroupIndex;
    /* 14c */ s32 mEntryIndex;
    /* 150 */ s32 mStateNumber;
    /* 154 */ s32 mUnk_154;
    /* 158 */ s32 (*mStateFunction)(struct MissionRunMapObject *);
    /* 15c */ s32 (*mNextStateFunction)(struct MissionRunMapObject *);
    /* 160 */ s32 mScaleTarget;
    /* 164 */ s32 mScalePerCall;
    /* 168 */ s32 mAlphaLimit;
    /* 16c */ s32 mAlphaLimitTarget;
    /* 170 */ s32 mAlphaLimitPerCall;
    /* 174 */ s32 mSpeed;
    /* 178 */ s32 mSpeedTarget;
    /* 17c */ s32 mSpeedPerCall;
    /* 180 */ s32 mAngleState;
    /* 184 */ s32 mAngle;
    /* 188 */ Vec3 mAnglePoint;
    /* 194 */ s32 mAnglePerCall;
    /* 198 */ s32 mAnglePerCallTarget;
    /* 19c */ s32 mAnglePerCallIncrement;
    /* 1a0 */ s32 mUnk_1a0;
    /* 1a4 */ s32 mMoveAngleMode;
    /* 1a8 */ s32 mMoveAngle;
    /* 1ac */ Vec3 mMoveAnglePoint;
    /* 1b8 */ s32 mMoveAnglePerCall;
    /* 1bc */ s32 mMoveAnglePerCallTarget;
    /* 1c0 */ s32 mMoveAnglePerCallIncrement;
    /* 1c4 */ s32 mUnk_1c4;
    /* 1c8 */ Vec3 mVelocity;
    /* 1d4 */ UnkFunc *mAnimationEndCallback;
    /* 1d8 */ s32 mAnimationFrameCallbackFrameIndex;
    /* 1dc */ UnkFunc *mAnimationFrameCallback;
    /* 1e0 */ s32 mUnk_1e0;
    /* 1e4 */ void (*mUnk_1e4)(struct MissionRunMapObject *);
    /* 1e8 */ s32 mUnk_1e8;
    /* 1ec */ void (*mUnk_1ec)(struct MissionRunMapObject *);
    /* 1f0 */ s32 mStateFrameCount;
    /* 1f4 */ UnkFunc *mStateFrameCountCallback;
    /* 1f8 */ s32 mPointRadius;
    /* 1fc */ s32 mPointHalfAngle;
    /* 200 */ Vec3 mPoint;
    /* 20c */ UnkFunc *mPointInRangeCallback;
    /* 210 */ s32 mUnk_210;
    /* 214 */ s32 mUnk_214;
    /* 218 */ Vec3 mUnk_218;
    /* 224 */ UnkFunc *mUnk_224;
    /* 228 */ UnkFunc *mStoppedCallback;
    /* 22c */ UnkFunc *mCourseCollisionCallback;
    /* 230 */ UnkFunc *mUnk_230;
    /* 234 */ s32 mCollisionShape;
    /* 238 */ Vec3 mPosWithOffset;
    /* 244 */ Vec3 mOffset;
    /* 250 */ s32 mOffsetTargetX;
    /* 254 */ s32 mOffsetTargetY;
    /* 258 */ s32 mOffsetTargetZ;
    /* 25c */ Vec3 mCollisionExtent;
    /* 268 */ s32 mCollisionExtentTargetX;
    /* 26c */ s32 mCollisionExtentTargetY;
    /* 270 */ s32 mCollisionExtentTargetZ;
    /* 274 */ s32 mOffsetPerCall;
    /* 278 */ s32 mCollisionExtentPerCall;
    /* 27c */ u32 mShadowMode;
    /* 280 */ s32 mShadowOffsetX;
    /* 284 */ s32 mShadowOffsetY;
    /* 288 */ s32 mShadowOffsetZ;
    /* 28c */ s32 mShadowOffsetTargetX;
    /* 290 */ s32 mShadowOffsetTargetY;
    /* 294 */ s32 mShadowOffsetTargetZ;
    /* 298 */ s32 mShadowScaleX;
    /* 29c */ s32 mShadowScaleY;
    /* 2a0 */ s32 mShadowScaleZ;
    /* 2a4 */ s32 mShadowScaleTargetX;
    /* 2a8 */ s32 mShadowScaleTargetY;
    /* 2ac */ s32 mShadowScaleTargetZ;
    /* 2b0 */ s32 mShadowOffsetPerCall;
    /* 2b4 */ s32 mShadowScalePerCall;
    /* 2b8 */ s32 mCourseCollisionMode;
    /* 2bc */ BOOL mBounceEnabled;
    /* 2c0 */ BOOL mGravityEnabled;
    /* 2c4 */ BOOL mUnk_2c4;
    /* 2c8 */ u32 mCollisionBits;
    /* 2cc */ u8 mUnk_2cc[0x4];
    /* 2d0 */ s32 mTimer;
    /* 2d4 */ UnkFunc *mKartCollisionCallback;
    /* 2d8 */ s32 mKartResponse;
    /* 2dc */ UnkFunc *mItemCollisionCallback;
    /* 2e0 */ s32 mItemResponse;
    /* 2e4 */ s32 mNodeMatchValue;
    /* 2e8 */ Vec3 mNodePosition;
    /* 2f4 */ Vec3 mBombOffset;
    /* 300 */ void *mItemBomb;
    /* 304 */ struct MapObjectModel *mNsbmd;
    /* 308 */ struct MapObjectModel *mShadowNsbmd;
} MissionRunMapObject;

void SetVelocity(MissionRunMapObject *mapObject, Vec3 *velocity);
void SetAnglePoint(MissionRunMapObject *mapObject, Vec3 *point);
void SetMoveAnglePoint(MissionRunMapObject *mapObject, Vec3 *point);
void SetAnglePointAndMoveAnglePoint(MissionRunMapObject *mapObject, Vec3 *point);
void StopMoveAngleTurning(MissionRunMapObject *mapObject);
void TurnAndMoveToPointOwnRates(MissionRunMapObject *mapObject, s32 anglePerCallTarget, s32 anglePerCallIncrement,
                                s32 moveAnglePerCallTarget, s32 moveAnglePerCallIncrement);
void SpinTowardPointMoveToPoint(MissionRunMapObject *mapObject, s32 anglePerCallTarget, s32 anglePerCallIncrement,
                                s32 moveAnglePerCallTarget, s32 moveAnglePerCallIncrement);
void SpinAngleStopMoveAngle(MissionRunMapObject *mapObject, s32 anglePerCallTarget, s32 anglePerCallIncrement);
void TurnToPointMoveSideways(MissionRunMapObject *mapObject, s32 anglePerCallTarget, s32 anglePerCallIncrement,
                             s32 moveAnglePerCallTarget, s32 moveAnglePerCallIncrement, s32 moveAngleOffset);
void TurnSidewaysMoveFollowsAngle(MissionRunMapObject *mapObject, s32 anglePerCallTarget, s32 anglePerCallIncrement,
                                  s32 angleOffset);
void StopTurningMoveFromPoint(MissionRunMapObject *mapObject, s32 moveAnglePerCallTarget,
                              s32 moveAnglePerCallIncrement);
void TurnFromPointMoveFollowsAngle(MissionRunMapObject *mapObject, s32 anglePerCallTarget, s32 anglePerCallIncrement);
void TurnAndMoveToPointSameRate(MissionRunMapObject *mapObject, s32 perCallTarget, s32 perCallIncrement);
void TurnToPointMoveFollowsAngle(MissionRunMapObject *mapObject, s32 anglePerCallTarget, s32 anglePerCallIncrement);
void StopTurningMoveFollowsAngle(MissionRunMapObject *mapObject);
