#include "Main/MapObjects/sun_fireball.h"
#include "Main/Sound/sound_ortho_quad_and_item_box_timer_globals.h"
#include "Main/MapObjects/map_object_model_frame.h"
#include "matrix_3x3_basic.h"
#include "Main/Course/course_map_group_entry.h"
#include "touch_panel_sampling.h"
#include "Main/MapObjects/bound.h"

#include "Main/Graphics/emitters.h"
#include "Main/Graphics/effects.h"
#include "ITCM/sphere_collision.h"
#include "Main/MapObjects/map_object_park.h"
#include "Main/MapObjects/map_object_scale_sound_source.h"
#include "Main/MapObjects/view_frustum.h"
#include "Main/MapObjects/map_object_kind_update_list.h"
#include "Main/Sound/start_sound_from_params.h"
#include "fixed_vector_math.h"
#include "Main/MapObjects/star_or_killer_hit_sound.h"
#include "Main/Menu/keyboard_cursor_targets.h"
#include "Main/Kart/kart_ai_item_use.h"
#include "Main/MapObjects/fireball2.h"

const u32 gSunFireballSkipSoundFlag = 0x40000000;
const u16 gSunFireballSecondHitFlag = 8;
const u16 gSunFireballHitFlag = 1;
const u16 gBoundInitMapObjectFlag = 0x200;

MapObjectKindDescriptor gSunFireballKindDescriptor = {0,
                                             {0, 0},
                                             0xc4,
                                             InitSunFireball,
                                             CreateSunFireballKindData,
                                             0,
                                             0,
                                             0,
                                             CreateSunFireballUpdateList};

void InitSunFireball(MapObject *mapObject) {
    u32 flags = mapObject->mFlags;
    u32 flagBits = gSunFireballInitMapObjectFlag;
    u32 newFlags = ((flags) | (flagBits));
    mapObject->mFlags = newFlags;
    ParkMapObject(mapObject);
    CreateMapObjectSoundSourceFalloff2(mapObject);
}

u8 CollideKartWithSunFireball(SunFireball *sunFireball, Kart *kart, u8 *hitFlag, u8 *passedValue) {
    u8 hitFlagValue;
    u32 passedOnValue;

    hitFlagValue = *hitFlag;
    passedOnValue = *passedValue;
    if (hitFlagValue == 1 && sunFireball->mState <= SUN_FIREBALL_STATE_ARC) {
        sunFireball->mMapObject.mFlags |= gSunFireballHitFlag;
        sunFireball->mMapObject.mFlags |= gSunFireballSecondHitFlag;
        sunFireball->mState = SUN_FIREBALL_STATE_HIT_RISE;
        sunFireball->mTimer = SUN_FIREBALL_HIT_FRAMES;
        sunFireball->mMapObject.mPosStep.x = 0;
        sunFireball->mMapObject.mPosStep.y = 0x3000;
        sunFireball->mMapObject.mPosStep.z = 0;
        sunFireball->mEmitterA->mLife = SUN_FIREBALL_MEDIUM_LIFE_FRAMES;
        sunFireball->mEmitterB->mLife = SUN_FIREBALL_MEDIUM_LIFE_FRAMES;
        sunFireball->mEmitterA->mEmitInterval = SUN_FIREBALL_MEDIUM_EMIT_INTERVAL;
        sunFireball->mEmitterB->mEmitInterval = SUN_FIREBALL_MEDIUM_EMIT_INTERVAL;
        if (kart->mItemEffect == KART_ITEM_EFFECT_STAR || kart->mItemEffect == KART_ITEM_EFFECT_KILLER) {
            sunFireball->mMapObject.mDistanceSquaredAndFlags |= gSunFireballSkipSoundFlag;
        }
        StartSoundIfKartStarOrKiller(&sunFireball->mMapObject, kart);
    }
    return passedOnValue;
}

u8 CollideItemObjectWithSunFireball(SunFireball *sunFireball, ItemObject *itemObject, u8 *hitFlag, u8 *passedValue) {
    u8 hitFlagValue;
    u32 passedOnValue;

    hitFlagValue = *hitFlag;
    passedOnValue = *passedValue;
    if (hitFlagValue == 1 && sunFireball->mState <= SUN_FIREBALL_STATE_ARC) {
        sunFireball->mMapObject.mFlags |= gSunFireballHitFlag;
        sunFireball->mMapObject.mFlags |= gSunFireballSecondHitFlag;
        sunFireball->mState = SUN_FIREBALL_STATE_HIT_RISE;
        sunFireball->mTimer = SUN_FIREBALL_HIT_FRAMES;
        sunFireball->mMapObject.mPosStep.x = 0;
        sunFireball->mMapObject.mPosStep.y = 0x3000;
        sunFireball->mMapObject.mPosStep.z = 0;
        sunFireball->mEmitterA->mLife = SUN_FIREBALL_MEDIUM_LIFE_FRAMES;
        sunFireball->mEmitterB->mLife = SUN_FIREBALL_MEDIUM_LIFE_FRAMES;
        sunFireball->mEmitterA->mEmitInterval = SUN_FIREBALL_MEDIUM_EMIT_INTERVAL;
        sunFireball->mEmitterB->mEmitInterval = SUN_FIREBALL_MEDIUM_EMIT_INTERVAL;
    }
    return passedOnValue;
}

void SunFireballInitNop(void) {}

static inline u32 SunFireballNextRandomU32(RandomState64 *randomState64) {
    randomState64->mValue = randomState64->mMultiplier * randomState64->mValue + randomState64->mIncrement;
    return RANDOM_HIGH32(randomState64);
}

void UpdateSunFireball(void *mapObjectList, SunFireball *sunFireball) {
    Vec3 pushOut;
    SoundStartParams soundRequest;
    u32 collisionFlags;
    s32 stepValue;
    s32 tableIndex;
    s32 randomValue;

    switch (sunFireball->mState) {
        case SUN_FIREBALL_STATE_WAIT:
            if (sunFireball->mWaitFrames-- <= 0) {
                sunFireball->mState = SUN_FIREBALL_STATE_ARC;
                soundRequest.mSoundId = SUN_FIREBALL_SOUND_ID;
                soundRequest.mPositionSource = &sunFireball->mMapObject.mPos;
                soundRequest.mFalloffIndex = SOUND_FALLOFF_SHORT_RANGE;
                soundRequest.mDistanceSquared = GetHorizontalCameraDistanceSquared(&sunFireball->mMapObject.mPos);
                StartSoundFromParams(&soundRequest);
            }
            break;
        case SUN_FIREBALL_STATE_ARC:
            if (sunFireball->mTimer-- != 0) {
                stepValue = sunFireball->mMapObject.mPosStep.y - 0x19a;
                if (stepValue <= -0x8000) {
                    stepValue = -0x8000;
                }
                sunFireball->mMapObject.mPosStep.y = stepValue;
                VEC_Add(&sunFireball->mMapObject.mPos, &sunFireball->mMapObject.mPosStep,
                        &sunFireball->mMapObject.mPos);
                if (sunFireball->mTimer > SUN_FIREBALL_NO_BOUNCE_FRAMES && sunFireball->mMapObject.mPosStep.y < 0) {
                    if (CollideSphereWithCourse(&sunFireball->mMapObject.mPos, NULL, 0,
                                                sunFireball->mMapObject.mExtent.x, 8, -2, &pushOut, NULL, NULL,
                                                &collisionFlags, NULL, NULL, NULL, NULL) != 0 &&
                        (collisionFlags & 0x3f77ef) != 0) {
                        VEC_Add(&sunFireball->mMapObject.mPos, &pushOut, &sunFireball->mMapObject.mPos);
                        stepValue = sunFireball->mMapObject.mPos.x - sunFireball->mStartPos.x;
                        tableIndex = sunFireball->mMapObject.mPos.z - sunFireball->mStartPos.z;
                        if (SQUARE_SUM2(stepValue, tableIndex) < 0x2710000000LL) {
                            randomValue =
                                (u16) (((u64) SunFireballNextRandomU32(GetMapObjectRandom()) * 0x10000) >> 32);
                            sunFireball->mMapObject.mPosStep.x =
                                MUL_FIXED12_NO_ROUND(SIN_OF_ANGLE(randomValue), 0x1800);
                            sunFireball->mMapObject.mPosStep.z =
                                MUL_FIXED12_NO_ROUND(COS_OF_ANGLE(randomValue), 0x1800);
                        } else {
                            sunFireball->mMapObject.mPosStep.x = -sunFireball->mMapObject.mPosStep.x;
                            sunFireball->mMapObject.mPosStep.z = -sunFireball->mMapObject.mPosStep.z;
                        }
                        sunFireball->mMapObject.mPosStep.y = 0x2c00;
                        sunFireball->mWaitFrames += 0x3c;
                        sunFireball->mState = SUN_FIREBALL_STATE_WAIT;
                        sunFireball->mEmitterA->mLife = SUN_FIREBALL_LONG_LIFE_FRAMES;
                        sunFireball->mEmitterB->mLife = SUN_FIREBALL_LONG_LIFE_FRAMES;
                        sunFireball->mEmitterA->mEmitInterval = SUN_FIREBALL_LONG_EMIT_INTERVAL;
                        sunFireball->mEmitterB->mEmitInterval = SUN_FIREBALL_LONG_EMIT_INTERVAL;
                    }
                }
            } else {
                ParkMapObject(&sunFireball->mMapObject);
                if (sunFireball->mEmitterA != NULL) {
                    StopEffectAndClearPointer((void **) &sunFireball->mEmitterA);
                }
                if (sunFireball->mEmitterB != NULL) {
                    StopEffectAndClearPointer((void **) &sunFireball->mEmitterB);
                }
            }
            break;
        case SUN_FIREBALL_STATE_HIT_RISE:
            stepValue = sunFireball->mMapObject.mPosStep.y - 0xcd;
            if (stepValue <= -0x2000) {
                stepValue = -0x2000;
            }
            sunFireball->mMapObject.mPosStep.y = stepValue;
            sunFireball->mMapObject.mPos.y = sunFireball->mMapObject.mPos.y + sunFireball->mMapObject.mPosStep.y;
            if (sunFireball->mMapObject.mPosStep.y < 0) {
                sunFireball->mMoveAngle
                    = ((u64) SunFireballNextRandomU32(GetMapObjectRandom()) * ANGLE_FULL_TURN) >> 32;
                sunFireball->mState = SUN_FIREBALL_STATE_HIT_SPIRAL;
            }
            break;
        case SUN_FIREBALL_STATE_HIT_SPIRAL:
            if (sunFireball->mTimer-- != 0) {
                stepValue = sunFireball->mMapObject.mPosStep.y - 0xcd;
                if (stepValue <= -0x2000) {
                    stepValue = -0x2000;
                }
                sunFireball->mMapObject.mPosStep.y = stepValue;
                sunFireball->mMoveAngle += 0xe39;
                sunFireball->mMapObject.mPos.x =
                    sunFireball->mMapObject.mPos.x + MUL_FIXED12_NO_ROUND(FX_SinIdx(sunFireball->mMoveAngle), 0x2000);
                sunFireball->mMapObject.mPos.z =
                    sunFireball->mMapObject.mPos.z + MUL_FIXED12_NO_ROUND(FX_CosIdx(sunFireball->mMoveAngle), 0x2000);
                sunFireball->mMapObject.mPos.y = sunFireball->mMapObject.mPos.y + sunFireball->mMapObject.mPosStep.y;
            } else {
                ParkMapObject(&sunFireball->mMapObject);
                if (sunFireball->mEmitterA != NULL) {
                    StopEffectAndClearPointer((void **) &sunFireball->mEmitterA);
                }
                if (sunFireball->mEmitterB != NULL) {
                    StopEffectAndClearPointer((void **) &sunFireball->mEmitterB);
                }
            }
            break;
    }
    if ((sunFireball->mMapObject.mFlags & MAP_OBJECT_FLAGS_NOT_DRAWN) == 0) {
        if (sunFireball->mEmitterA != NULL) {
            PlaceEffect(sunFireball->mEmitterA, &sunFireball->mMapObject.mPos);
            sunFireball->mEmitterA->mFlags.mEmissionStopped = 0;
        }
        if (sunFireball->mEmitterB != NULL) {
            PlaceEffect(sunFireball->mEmitterB, &sunFireball->mMapObject.mPos);
            sunFireball->mEmitterB->mFlags.mEmissionStopped = 0;
        }
    } else {
        if (sunFireball->mEmitterA != NULL) {
            sunFireball->mEmitterA->mFlags.mEmissionStopped = 1;
        }
        if (sunFireball->mEmitterB != NULL) {
            sunFireball->mEmitterB->mFlags.mEmissionStopped = 1;
        }
    }
}

MapObjectKindData *CreateSunFireballKindData(void) {
    MapObjectKindData *kindData;

    kindData = CreateMapObjectKindDataWithSound(&CollideKartWithSunFireball, &CollideItemObjectWithSunFireball, NULL, 1,
                                                0, 0x18d);
    kindData->mCollideItemObjectSoundId = SUN_FIREBALL_ITEM_HIT_SOUND_ID;
    return kindData;
}

MapObjectList *CreateSunFireballUpdateList(void) {
    return CreateMapObjectUpdateList(&SunFireballInitNop, &UpdateSunFireball, NULL);
}

void StartSunFireball(Vec3 *startPos, Vec3 *direction) {
    SunFireball *sunFireball;

    sunFireball = UnparkFirstParkedMapObject(FindMapObjectKindUpdateList(MAP_OBJECT_KIND_SUN_FIREBALL));
    if (sunFireball == NULL) {
        return;
    }
    sunFireball->mTimer = SUN_FIREBALL_LIFE_FRAMES;
    sunFireball->mStartPos = *startPos;
    sunFireball->mMapObject.mPos = sunFireball->mStartPos;
    sunFireball->mMapObject.mMatrix.mRows[2] = *direction;
    sunFireball->mMapObject.mPosStep.x = MUL_FIXED12_NO_ROUND(direction->x, 0x2000);
    sunFireball->mMapObject.mPosStep.y = MUL_FIXED12_NO_ROUND(direction->y, 0x2000);
    sunFireball->mMapObject.mPosStep.z = MUL_FIXED12_NO_ROUND(direction->z, 0x2000);
    sunFireball->mWaitFrames = 0;
    sunFireball->mState = SUN_FIREBALL_STATE_WAIT;
    sunFireball->mEmitterA = StartEffect(0x35, &sunFireball->mMapObject.mPos);
    sunFireball->mEmitterB = StartEffect(0x34, &sunFireball->mMapObject.mPos);
    sunFireball->mEmitterA->mLife = SUN_FIREBALL_SHORT_LIFE_FRAMES;
    sunFireball->mEmitterB->mLife = SUN_FIREBALL_SHORT_LIFE_FRAMES;
    sunFireball->mEmitterA->mEmitInterval = SUN_FIREBALL_SHORT_EMIT_INTERVAL;
    sunFireball->mEmitterB->mEmitInterval = SUN_FIREBALL_SHORT_EMIT_INTERVAL;
    sunFireball->mMapObject.mFlags &= ~MAP_OBJECT_FLAG_DISABLED;
    sunFireball->mMapObject.mFlags &= ~MAP_OBJECT_FLAG_SKIP_LIST_CALLBACK;
    sunFireball->mMapObject.mFlags &= ~MAP_OBJECT_FLAG_NO_VIEW_TEST;
    sunFireball->mMapObject.mFlags &= ~MAP_OBJECT_FLAG_SKIP_LIST_CALLBACK;
    sunFireball->mMapObject.mAlpha = MAP_OBJECT_ALPHA_MAX;
}
