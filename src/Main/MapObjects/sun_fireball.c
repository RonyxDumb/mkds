#include "Main/MapObjects/sun_fireball.h"
#include "Main/MapObjects/map_object_model_frame.h"
#include "fx_mtx33.h"
#include "Main/Course/code_02042044.h"
#include "tp.h"
#include "Main/MapObjects/bound.h"

#include "Main/Graphics/emitters.h"
#include "Main/Graphics/effects.h"
#include "ITCM/sphere_collision.h"
#include "Main/MapObjects/map_object_park.h"
#include "Main/MapObjects/map_object_scale_sound_source.h"
#include "Main/MapObjects/view_frustum.h"
#include "Main/MapObjects/map_object_kind_update_list.h"
#include "Main/Sound/code_0210b760.h"
#include "code_02147cd8.h"
#include "Main/MapObjects/sound_if_kart_star_or.h"
#include "Main/MapObjects/data_02156000.h"
#include "Main/Kart/code_0208fd8c.h"
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
    if (hitFlagValue == 1 && sunFireball->mState <= 1) {
        sunFireball->mMapObject.mFlags |= gSunFireballHitFlag;
        sunFireball->mMapObject.mFlags |= gSunFireballSecondHitFlag;
        sunFireball->mState = 2;
        sunFireball->mTimer = 0x168;
        sunFireball->mMapObject.mPosStep.x = 0;
        sunFireball->mMapObject.mPosStep.y = 0x3000;
        sunFireball->mMapObject.mPosStep.z = 0;
        sunFireball->mUnk_bc->mLife = 0x23;
        sunFireball->mUnk_c0->mLife = 0x23;
        sunFireball->mUnk_bc->mEmitInterval = 5;
        sunFireball->mUnk_c0->mEmitInterval = 5;
        if (kart->mItemEffect == 1 || kart->mItemEffect == 3) {
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
    if (hitFlagValue == 1 && sunFireball->mState <= 1) {
        sunFireball->mMapObject.mFlags |= gSunFireballHitFlag;
        sunFireball->mMapObject.mFlags |= gSunFireballSecondHitFlag;
        sunFireball->mState = 2;
        sunFireball->mTimer = 0x168;
        sunFireball->mMapObject.mPosStep.x = 0;
        sunFireball->mMapObject.mPosStep.y = 0x3000;
        sunFireball->mMapObject.mPosStep.z = 0;
        sunFireball->mUnk_bc->mLife = 0x23;
        sunFireball->mUnk_c0->mLife = 0x23;
        sunFireball->mUnk_bc->mEmitInterval = 5;
        sunFireball->mUnk_c0->mEmitInterval = 5;
    }
    return passedOnValue;
}

u32 SunFireballInitReturnArgument(u32 value) {
    return value;
}

static inline u32 SunFireballNextRandomU32(RandomState64 *randomState64) {
    randomState64->mValue = randomState64->mMultiplier * randomState64->mValue + randomState64->mIncrement;
    return randomState64->mValue >> 32;
}

void UpdateSunFireball(void *mapObjectList, SunFireball *sunFireball) {
    Vec3 pushOut;
    SoundStartParams soundRequest;
    u32 collisionFlags;
    s32 stepValue;
    s32 tableIndex;
    s32 randomValue;

    switch (sunFireball->mState) {
        case 0:
            if (sunFireball->mState0Timer-- <= 0) {
                sunFireball->mState = 1;
                soundRequest.mSoundId = 0x195;
                soundRequest.mPositionSource = &sunFireball->mMapObject.mPos;
                soundRequest.mFalloffIndex = 2;
                soundRequest.mDistanceSquared = GetHorizontalCameraDistanceSquared(&sunFireball->mMapObject.mPos);
                StartSoundFromParams(&soundRequest);
            }
            break;
        case 1:
            if (sunFireball->mTimer-- != 0) {
                stepValue = sunFireball->mMapObject.mPosStep.y - 0x19a;
                if (stepValue <= -0x8000) {
                    stepValue = -0x8000;
                }
                sunFireball->mMapObject.mPosStep.y = stepValue;
                VEC_Add(&sunFireball->mMapObject.mPos, &sunFireball->mMapObject.mPosStep,
                        &sunFireball->mMapObject.mPos);
                if (sunFireball->mTimer > 0x78 && sunFireball->mMapObject.mPosStep.y < 0) {
                    if (CollideSphereWithCourse(&sunFireball->mMapObject.mPos, NULL, 0,
                                                sunFireball->mMapObject.mExtent.x, 8, -2, &pushOut, NULL, NULL,
                                                &collisionFlags, NULL, NULL, NULL, NULL) != 0 &&
                        (collisionFlags & 0x3f77ef) != 0) {
                        VEC_Add(&sunFireball->mMapObject.mPos, &pushOut, &sunFireball->mMapObject.mPos);
                        stepValue = sunFireball->mMapObject.mPos.x - sunFireball->mStartPos.x;
                        tableIndex = sunFireball->mMapObject.mPos.z - sunFireball->mStartPos.z;
                        if ((s64) stepValue * stepValue + (s64) tableIndex * tableIndex < 0x2710000000LL) {
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
                        sunFireball->mState0Timer += 0x3c;
                        sunFireball->mState = 0;
                        sunFireball->mUnk_bc->mLife = 0x2a;
                        sunFireball->mUnk_c0->mLife = 0x2a;
                        sunFireball->mUnk_bc->mEmitInterval = 6;
                        sunFireball->mUnk_c0->mEmitInterval = 6;
                    }
                }
            } else {
                ParkMapObject(&sunFireball->mMapObject);
                if (sunFireball->mUnk_bc != NULL) {
                    StopEffectAndClearPointer((void **) &sunFireball->mUnk_bc);
                }
                if (sunFireball->mUnk_c0 != NULL) {
                    StopEffectAndClearPointer((void **) &sunFireball->mUnk_c0);
                }
            }
            break;
        case 2:
            stepValue = sunFireball->mMapObject.mPosStep.y - 0xcd;
            if (stepValue <= -0x2000) {
                stepValue = -0x2000;
            }
            sunFireball->mMapObject.mPosStep.y = stepValue;
            sunFireball->mMapObject.mPos.y = sunFireball->mMapObject.mPos.y + sunFireball->mMapObject.mPosStep.y;
            if (sunFireball->mMapObject.mPosStep.y < 0) {
                sunFireball->mMoveAngle = ((u64) SunFireballNextRandomU32(GetMapObjectRandom()) * 0x10000) >> 32;
                sunFireball->mState = 3;
            }
            break;
        case 3:
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
                if (sunFireball->mUnk_bc != NULL) {
                    StopEffectAndClearPointer((void **) &sunFireball->mUnk_bc);
                }
                if (sunFireball->mUnk_c0 != NULL) {
                    StopEffectAndClearPointer((void **) &sunFireball->mUnk_c0);
                }
            }
            break;
    }
    if ((sunFireball->mMapObject.mFlags & 0x12) == 0) {
        if (sunFireball->mUnk_bc != NULL) {
            PlaceEffect(sunFireball->mUnk_bc, &sunFireball->mMapObject.mPos);
            sunFireball->mUnk_bc->mFlags.mEmissionStopped = 0;
        }
        if (sunFireball->mUnk_c0 != NULL) {
            PlaceEffect(sunFireball->mUnk_c0, &sunFireball->mMapObject.mPos);
            sunFireball->mUnk_c0->mFlags.mEmissionStopped = 0;
        }
    } else {
        if (sunFireball->mUnk_bc != NULL) {
            sunFireball->mUnk_bc->mFlags.mEmissionStopped = 1;
        }
        if (sunFireball->mUnk_c0 != NULL) {
            sunFireball->mUnk_c0->mFlags.mEmissionStopped = 1;
        }
    }
}

MapObjectKindData *CreateSunFireballKindData(void) {
    MapObjectKindData *kindData;

    kindData = CreateMapObjectKindDataWithSound(&CollideKartWithSunFireball, &CollideItemObjectWithSunFireball, NULL, 1,
                                                0, 0x18d);
    kindData->mCollideItemObjectSoundId = 0x196;
    return kindData;
}

MapObjectList *CreateSunFireballUpdateList(void) {
    return CreateMapObjectUpdateList(&SunFireballInitReturnArgument, &UpdateSunFireball, NULL);
}

void StartSunFireball(Vec3 *startPos, Vec3 *direction) {
    SunFireball *sunFireball;

    sunFireball = UnparkFirstParkedMapObject(FindMapObjectKindUpdateList(MAP_OBJECT_KIND_SUN_FIREBALL));
    if (sunFireball == NULL) {
        return;
    }
    sunFireball->mTimer = 0x1c2;
    sunFireball->mStartPos = *startPos;
    sunFireball->mMapObject.mPos = sunFireball->mStartPos;
    sunFireball->mMapObject.mMatrix.mRows[2] = *direction;
    sunFireball->mMapObject.mPosStep.x = MUL_FIXED12_NO_ROUND(direction->x, 0x2000);
    sunFireball->mMapObject.mPosStep.y = MUL_FIXED12_NO_ROUND(direction->y, 0x2000);
    sunFireball->mMapObject.mPosStep.z = MUL_FIXED12_NO_ROUND(direction->z, 0x2000);
    sunFireball->mState0Timer = 0;
    sunFireball->mState = 0;
    sunFireball->mUnk_bc = StartEffect(0x35, &sunFireball->mMapObject.mPos);
    sunFireball->mUnk_c0 = StartEffect(0x34, &sunFireball->mMapObject.mPos);
    sunFireball->mUnk_bc->mLife = 0x15;
    sunFireball->mUnk_c0->mLife = 0x15;
    sunFireball->mUnk_bc->mEmitInterval = 3;
    sunFireball->mUnk_c0->mEmitInterval = 3;
    sunFireball->mMapObject.mFlags &= ~1;
    sunFireball->mMapObject.mFlags &= ~8;
    sunFireball->mMapObject.mFlags &= ~2;
    sunFireball->mMapObject.mFlags &= ~8;
    sunFireball->mMapObject.mAlpha = 0x1f;
}
