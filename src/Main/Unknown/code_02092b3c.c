#include "Main/Unknown/code_02092b3c.h"
#include "Main/Unknown/code_020918a8.h"
#include "Main/Unknown/code_020ac000.h"

#include "Main/Unknown/code_0209219c.h"
#include "Main/Unknown/code_02046000.h"
#include "Main/Unknown/code_020ac524.h"
#include "Main/Unknown/unk_0217a000.h"
#include "Main/Unknown/code_02061654.h"
#include "Main/Unknown/code_0206bcb0.h"
#include "Main/Unknown/code_020f36d8.h"
#include "Main/Unknown/code_0209bef0.h"
#include "Main/Unknown/code_020d22c0.h"
#include "Main/Unknown/unk_0215d000.h"
#include "Main/Unknown/unk_021759c0.h"
#include "code_02147cd8.h"
#include "code_02148538.h"
#include "Main/Unknown/code_02045874.h"
#include "Main/Unknown/code_02077bc0.h"
#include "Main/Unknown/code_021000d0.h"

void InitBasabasaBurst(u32 mapObject) {
    u32 value0 = mapObject;
    u32 parkedCount;
    u32 sourceMapObject;
    u32 value12;
    sourceMapObject = value0;
    value0 = MAP_OBJECT_KIND_BASABASA;
    parkedCount = 8u;
    CreateParkedMapObjects(value0, parkedCount, (void *) sourceMapObject);
}

static inline u32 func_02092b5c_inline(u32 n) {
    RandomState64 *mapObjectRandom;

    mapObjectRandom = GetMapObjectRandom();
    mapObjectRandom->mValue = mapObjectRandom->mMultiplier * mapObjectRandom->mValue + mapObjectRandom->mIncrement;
    return ((mapObjectRandom->mValue >> 32) * n) >> 32;
}

static inline u16 func_02092b5c_inline_2(u32 n) {
    RandomState64 *mapObjectRandom;

    mapObjectRandom = GetMapObjectRandom();
    mapObjectRandom->mValue = mapObjectRandom->mMultiplier * mapObjectRandom->mValue + mapObjectRandom->mIncrement;
    return (u32) (((mapObjectRandom->mValue >> 32) * n) >> 32);
}

void InitBasabasaBurstObjects(MapObjectList *mapObjectList) {
    s32 i;
    BasabasaBurst *burstObject;

    if (mapObjectList == NULL) {
        return;
    }
    for (i = 0; i < mapObjectList->mMapObjectCount && (burstObject = mapObjectList->mMapObjects[i]) != NULL; i++) {
        if (burstObject->mMapObject.mFlags & 0x800) {
            burstObject->mTimer = (u16) (func_02092b5c_inline_2(25) + 200);
        }
    }
}

static inline s64 func_02092b5c_inline_4(const Vec3 *a, const Vec3 *b) {
    s32 v1;
    s32 v2;

    v1 = a->x - b->x;
    v2 = a->z - b->z;
    return (s64) v1 * v1 + (s64) v2 * v2;
}

static inline BOOL func_02092b5c_inline_3(BasabasaBurst *p, s32 k) {
    s32 i;
    BOOL f;
    s32 d;
    Kart *kart;

    for (i = 0; i < gRaceSetup->mKartCount; i++) {
        f = FALSE;
        if (gRaceSetup->mCurrentEntries[(u16) i].mPlayer.mKind <= 3 &&
            ((1 << gRaceSetup->mCurrentEntries[(u16) i].mPlayer.mKind) & PLAYER_KIND_MASK_HUMAN_GHOST_PEER)) {
            f = TRUE;
        }
        if (f == FALSE && i != gRaceSetup->mEntryIndex) {
            continue;
        }
        kart = GetKart((u16) i);
        if (func_02092b5c_inline_4(&kart->mPos, &p->mMapObject.mPos) >= 0x15f900000000LL) {
            continue;
        }
        d = FX_Atan2Idx(kart->mPos.x - p->mMapObject.mPos.x, kart->mPos.z - p->mMapObject.mPos.z) - k;
        if (d < -0x1f40) {
            continue;
        }
        if (d <= 0x1f40) {
            return TRUE;
        }
    }
    return FALSE;
}

static inline void func_02092b5c_inline_5(Vec3 *v, s32 x, s32 y, s32 z) {
    v->x = x - 0x5000 + func_02092b5c_inline(0xa000);
    v->y = y - 0x5000 + func_02092b5c_inline(0xa000);
    v->z = z - 0x28000 + func_02092b5c_inline(0x50000);
}

s16 BasabasaBurstFX_SinIdx(s32 angle) {
    return FX_SinIdx(angle);
}

s32 BasabasaBurstMulFixed12NoRound(s32 multiplicand, s32 multiplier) {
    return MUL_FIXED12_NO_ROUND(multiplicand, multiplier);
}

s16 BasabasaBurstFX_CosIdx(s32 angle) {
    return FX_CosIdx(angle);
}

void UpdateBasabasaBurst(void *mapObjectList, BasabasaBurst *burstObject) {
    s32 i;
    s32 horizontalSpeed;
    u16 angle;
    s32 nextCycleFrames;
    Vec3 basabasaPos;
    Vec3 basabasaVelocity;

    switch (burstObject->mState) {
        case 0:
            if (GetCurrentCameraKind() == 2) {
                burstObject->mState = 1;
                return;
            }
            if (burstObject->mMapObject.mFlags & 0x800) {
                if (burstObject->mTimer-- <= 0) {
                    burstObject->mTimer = 4;
                    burstObject->mState = 1;
                }
                return;
            }
            if (func_02092b5c_inline_3(burstObject, burstObject->mMapObject.mAngle) != FALSE) {
                burstObject->mTimer = 4;
                burstObject->mState = 1;
            }
            return;
        case 1:
            break;
        default:
            return;
    }
    if (burstObject->mCycleFrames == 0x14) {
        for (i = 0; i < 2; i++) {
            func_02092b5c_inline_5(&basabasaPos, burstObject->mMapObject.mPos.x,
                                   burstObject->mMapObject.mPos.y + 0x23000, burstObject->mMapObject.mPos.z);
            angle = burstObject->mMapObject.mAngle;
            horizontalSpeed = NextRandomBelow(GetMapObjectRandom(), 0x1000) + 0x2000;
            angle = angle - 0xbb8 + NextRandomBelowU16(GetMapObjectRandom(), 0x1770);
            basabasaVelocity.x = BasabasaBurstMulFixed12NoRound(horizontalSpeed, BasabasaBurstFX_SinIdx(angle));
            basabasaVelocity.y = NextRandomBelow(GetMapObjectRandom(), 0x400) - 0xa00;
            basabasaVelocity.z = BasabasaBurstMulFixed12NoRound(horizontalSpeed, BasabasaBurstFX_CosIdx(angle));
            if (i == 0 && burstObject->mBurstCount == 0) {
                StartBasabasa(0x8c, &basabasaPos, &basabasaVelocity, 0xf, 1, i == 0 ? 2 : 0);
            } else {
                StartBasabasa(0x8c, &basabasaPos, &basabasaVelocity, 0xf, 0, i == 0 ? 2 : 0);
            }
        }
        burstObject->mBurstCount += 1;
        if (burstObject->mBurstCount >= 3) {
            burstObject->mBurstCount = 0;
        }
    }
    nextCycleFrames = burstObject->mCycleFrames + 1;
    if (nextCycleFrames >= 0x32) {
        nextCycleFrames = 0;
    }
    burstObject->mCycleFrames = nextCycleFrames;
    if (burstObject->mCycleFrames != 0) {
        return;
    }
    if (burstObject->mTimer-- > 0) {
        return;
    }
    burstObject->mBurstCount = 0;
    burstObject->mState = 0;
    if (burstObject->mMapObject.mFlags & 0x800) {
        burstObject->mTimer = (u16) (func_02092b5c_inline_2(25) + 200);
    }
}

void CreateBasabasaBurstUpdateList(void) {
    CreateMapObjectUpdateList(InitBasabasaBurstObjects, UpdateBasabasaBurst, NULL);
}
