#include "Main/Unknown/code_0209d694.h"
#include "Main/Unknown/code_0209b634.h"
#include "code_02146d78.h"
#include "Main/Unknown/code_02042044.h"
#include "Main/Unknown/unk_021759c0.h"
#include "Main/Unknown/code_0209bf70.h"

#include "Main/Unknown/code_0208aea8.h"
#include "Main/Unknown/code_0208b484.h"
#include "Main/Unknown/code_0209b000.h"
#include "Main/Unknown/code_0209bef0.h"
#include "Main/Unknown/code_0209dd40.h"
#include "Main/Unknown/code_0209dd44.h"
#include "ITCM/code_01ffdee4.h"
#include "Main/Unknown/code_020d22c0.h"
#include "Main/Unknown/code_020d278c.h"
#include "Main/Unknown/code_020d4c28.h"
#include "Main/Unknown/code_021000d0.h"
#include "Main/Unknown/code_0210b760.h"
#include "Main/Unknown/unk_0215d000.h"
#include "code_02147cd8.h"
#include "Main/Unknown/code_020d26f8.h"
#include "Main/Unknown/unk_02156000.h"
#include "Main/Unknown/code_0209decc.h"

void InitSunFireball(MapObject *mapObject) {
    u32 flags = mapObject->mFlags;
    u32 flagBits = data_021565e4;
    u32 newFlags = ((flags) | (flagBits));
    mapObject->mFlags = newFlags;
    ParkMapObject(mapObject);
    CreateMapObjectSoundSourceFalloff2(mapObject);
}

u8 CollideKartWithSunFireball(SunFireball *sunFireball, Kart *kart, u8 *c, u8 *d) {
    u8 x;
    u32 v;

    x = *c;
    v = *d;
    if (x == 1 && sunFireball->mState <= 1) {
        sunFireball->mMapObject.mFlags |= data_usa_021565d8;
        sunFireball->mMapObject.mFlags |= data_usa_021565dc;
        sunFireball->mState = 2;
        sunFireball->mTimer = 0x168;
        sunFireball->mMapObject.mPosStep.x = 0;
        sunFireball->mMapObject.mPosStep.y = 0x3000;
        sunFireball->mMapObject.mPosStep.z = 0;
        sunFireball->mUnk_bc->mUnk_70 = 0x23;
        sunFireball->mUnk_c0->mUnk_70 = 0x23;
        sunFireball->mUnk_bc->mUnk_80 = 5;
        sunFireball->mUnk_c0->mUnk_80 = 5;
        if (kart->mItemEffect == 1 || kart->mItemEffect == 3) {
            sunFireball->mMapObject.mDistanceSquaredAndFlags |= data_usa_021565e0;
        }
        StartSoundIfKartStarOrKiller(&sunFireball->mMapObject, kart);
    }
    return v;
}

u8 CollideItemObjectWithSunFireball(SunFireball *sunFireball, ItemObject *itemObject, u8 *c, u8 *d) {
    u8 x;
    u32 v;

    x = *c;
    v = *d;
    if (x == 1 && sunFireball->mState <= 1) {
        sunFireball->mMapObject.mFlags |= data_usa_021565d8;
        sunFireball->mMapObject.mFlags |= data_usa_021565dc;
        sunFireball->mState = 2;
        sunFireball->mTimer = 0x168;
        sunFireball->mMapObject.mPosStep.x = 0;
        sunFireball->mMapObject.mPosStep.y = 0x3000;
        sunFireball->mMapObject.mPosStep.z = 0;
        sunFireball->mUnk_bc->mUnk_70 = 0x23;
        sunFireball->mUnk_c0->mUnk_70 = 0x23;
        sunFireball->mUnk_bc->mUnk_80 = 5;
        sunFireball->mUnk_c0->mUnk_80 = 5;
    }
    return v;
}

u32 SunFireballInitReturnArgument(u32 value) {
    return value;
}

static inline u32 func_0209d84c_inline(RandomState64 *randomState64) {
    randomState64->mValue = randomState64->mMultiplier * randomState64->mValue + randomState64->mIncrement;
    return randomState64->mValue >> 32;
}

void UpdateSunFireball(void *a, SunFireball *sunFireball) {
    Vec3 v;
    SoundStartParams soundRequest;
    u32 f;
    s32 t;
    s32 k;
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
                t = sunFireball->mMapObject.mPosStep.y - 0x19a;
                if (t <= -0x8000) {
                    t = -0x8000;
                }
                sunFireball->mMapObject.mPosStep.y = t;
                VEC_Add(&sunFireball->mMapObject.mPos, &sunFireball->mMapObject.mPosStep, &sunFireball->mMapObject.mPos);
                if (sunFireball->mTimer > 0x78 && sunFireball->mMapObject.mPosStep.y < 0) {
                    if (CollideSphereWithCourse(&sunFireball->mMapObject.mPos, NULL, 0, sunFireball->mMapObject.mExtent.x, 8,
                                                -2, &v, NULL, NULL, &f, NULL, NULL, NULL, NULL) != 0 &&
                        (f & 0x3f77ef) != 0) {
                        VEC_Add(&sunFireball->mMapObject.mPos, &v, &sunFireball->mMapObject.mPos);
                        t = sunFireball->mMapObject.mPos.x - sunFireball->mStartPos.x;
                        k = sunFireball->mMapObject.mPos.z - sunFireball->mStartPos.z;
                        if ((s64) t * t + (s64) k * k < 0x2710000000LL) {
                            randomValue = (u16) (((u64) func_0209d84c_inline(GetMapObjectRandom()) * 0x10000) >> 32);
                            k = (randomValue >> 4) * 2;
                            sunFireball->mMapObject.mPosStep.x = MUL_FIXED12_NO_ROUND(gPairsByAngle[k], 0x1800);
                            sunFireball->mMapObject.mPosStep.z = MUL_FIXED12_NO_ROUND(gPairsByAngle[k + 1], 0x1800);
                        } else {
                            sunFireball->mMapObject.mPosStep.x = -sunFireball->mMapObject.mPosStep.x;
                            sunFireball->mMapObject.mPosStep.z = -sunFireball->mMapObject.mPosStep.z;
                        }
                        sunFireball->mMapObject.mPosStep.y = 0x2c00;
                        sunFireball->mState0Timer += 0x3c;
                        sunFireball->mState = 0;
                        sunFireball->mUnk_bc->mUnk_70 = 0x2a;
                        sunFireball->mUnk_c0->mUnk_70 = 0x2a;
                        sunFireball->mUnk_bc->mUnk_80 = 6;
                        sunFireball->mUnk_c0->mUnk_80 = 6;
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
            t = sunFireball->mMapObject.mPosStep.y - 0xcd;
            if (t <= -0x2000) {
                t = -0x2000;
            }
            sunFireball->mMapObject.mPosStep.y = t;
            sunFireball->mMapObject.mPos.y = sunFireball->mMapObject.mPos.y + sunFireball->mMapObject.mPosStep.y;
            if (sunFireball->mMapObject.mPosStep.y < 0) {
                sunFireball->mMoveAngle = ((u64) func_0209d84c_inline(GetMapObjectRandom()) * 0x10000) >> 32;
                sunFireball->mState = 3;
            }
            break;
        case 3:
            if (sunFireball->mTimer-- != 0) {
                t = sunFireball->mMapObject.mPosStep.y - 0xcd;
                if (t <= -0x2000) {
                    t = -0x2000;
                }
                sunFireball->mMapObject.mPosStep.y = t;
                sunFireball->mMoveAngle += 0xe39;
                sunFireball->mMapObject.mPos.x =
                    sunFireball->mMapObject.mPos.x +
                    MUL_FIXED12_NO_ROUND(gPairsByAngle[(sunFireball->mMoveAngle >> 4) * 2], 0x2000);
                sunFireball->mMapObject.mPos.z =
                    sunFireball->mMapObject.mPos.z +
                    MUL_FIXED12_NO_ROUND(gPairsByAngle[(sunFireball->mMoveAngle >> 4) * 2 + 1], 0x2000);
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
            sunFireball->mUnk_bc->mUnk_24 &= ~2;
        }
        if (sunFireball->mUnk_c0 != NULL) {
            PlaceEffect(sunFireball->mUnk_c0, &sunFireball->mMapObject.mPos);
            sunFireball->mUnk_c0->mUnk_24 &= ~2;
        }
    } else {
        if (sunFireball->mUnk_bc != NULL) {
            sunFireball->mUnk_bc->mUnk_24 |= 2;
        }
        if (sunFireball->mUnk_c0 != NULL) {
            sunFireball->mUnk_c0->mUnk_24 |= 2;
        }
    }
}

void CreateSunFireballKindData(void) {
    MapObjectKindData *kindData;

    kindData = CreateMapObjectKindDataWithSound(&CollideKartWithSunFireball, &CollideItemObjectWithSunFireball, NULL, 1,
                                                0, 0x18d);
    kindData->mCollideItemObjectSoundId = 0x196;
}

void CreateSunFireballUpdateList(void) {
    CreateMapObjectUpdateList(&SunFireballInitReturnArgument, &UpdateSunFireball, NULL);
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
    sunFireball->mMapObject.mMatrix.mUnk_00[2] = *direction;
    sunFireball->mMapObject.mPosStep.x = MUL_FIXED12_NO_ROUND(direction->x, 0x2000);
    sunFireball->mMapObject.mPosStep.y = MUL_FIXED12_NO_ROUND(direction->y, 0x2000);
    sunFireball->mMapObject.mPosStep.z = MUL_FIXED12_NO_ROUND(direction->z, 0x2000);
    sunFireball->mState0Timer = 0;
    sunFireball->mState = 0;
    sunFireball->mUnk_bc = StartEffect(0x35, &sunFireball->mMapObject.mPos);
    sunFireball->mUnk_c0 = StartEffect(0x34, &sunFireball->mMapObject.mPos);
    sunFireball->mUnk_bc->mUnk_70 = 0x15;
    sunFireball->mUnk_c0->mUnk_70 = 0x15;
    sunFireball->mUnk_bc->mUnk_80 = 3;
    sunFireball->mUnk_c0->mUnk_80 = 3;
    sunFireball->mMapObject.mFlags &= ~1;
    sunFireball->mMapObject.mFlags &= ~8;
    sunFireball->mMapObject.mFlags &= ~2;
    sunFireball->mMapObject.mFlags &= ~8;
    sunFireball->mMapObject.mAlpha = 0x1f;
}
