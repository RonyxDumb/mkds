#include "Main/Unknown/code_020918a8.h"
#include "ITCM/code_01ff8000.h"
#include "ITCM/code_01ff9000.h"
#include "Main/Unknown/code_0209219c.h"
#include "Main/Unknown/code_02046000.h"
#include "Main/Unknown/code_0209b634.h"
#include "Main/Unknown/unk_0217a000.h"
#include "Main/Unknown/code_02061654.h"
#include "Main/Unknown/code_0206bcb0.h"
#include "Main/Unknown/code_0209b000.h"
#include "Main/Unknown/code_0209bef0.h"
#include "Main/Unknown/code_020d22c0.h"
#include "Main/Unknown/code_020d4c28.h"
#include "Main/Unknown/code_020e6b58.h"
#include "Main/Unknown/code_020f36d8.h"
#include "Main/Unknown/code_020f9c6c.h"
#include "Main/Unknown/code_0210b760.h"
#include "Main/Unknown/unk_02156000.h"
#include "Main/Unknown/unk_0215d000.h"
#include "Main/Unknown/unk_02166000.h"
#include "Main/Unknown/unk_021759c0.h"
#include "Main/Unknown/unk_0217b000.h"
#include "Main/Unknown/unk_0217c000.h"
#include "code_02147cd8.h"
#include "code_02148538.h"
#include "Main/Unknown/code_02045874.h"
#include "Main/Unknown/code_02077bc0.h"

static inline u32 func_020919e8_inline(u32 limit) {
    RandomState64 *mapObjectRandom;

    mapObjectRandom = GetMapObjectRandom();
    mapObjectRandom->mValue = mapObjectRandom->mMultiplier * mapObjectRandom->mValue + mapObjectRandom->mIncrement;
    return ((mapObjectRandom->mValue >> 32) * limit) >> 32;
}

static inline u16 func_020919e8_inline_2(u32 limit) {
    RandomState64 *mapObjectRandom;

    mapObjectRandom = GetMapObjectRandom();
    mapObjectRandom->mValue = mapObjectRandom->mMultiplier * mapObjectRandom->mValue + mapObjectRandom->mIncrement;
    return (u32) (((mapObjectRandom->mValue >> 32) * limit) >> 32);
}

static inline void func_020919e8_inline_3(Kanoke64 *kanoke64, s32 soundId) {
    SoundStartParams soundRequest;
    s32 falloffIndex;

    if (kanoke64->mMapObject.mDistanceSquaredAndFlags & 4) {
        return;
    }
    if (kanoke64->mMapObject.mFarDistanceSquared == gSoundFalloffs[2].mUnk_20) {
        falloffIndex = 2;
    } else if (kanoke64->mMapObject.mFarDistanceSquared == gSoundFalloffs[3].mUnk_20) {
        falloffIndex = 3;
    } else {
        falloffIndex = 4;
    }
    soundRequest.mSoundId = soundId;
    soundRequest.mPositionSource = &kanoke64->mMapObject.mPos;
    soundRequest.mFalloffIndex = falloffIndex;
    soundRequest.mDistanceSquared = GetHorizontalCameraDistanceSquared(&kanoke64->mMapObject.mPos);
    StartSoundFromParams(&soundRequest);
}

void CreateKanoke64(void *mapObjectList) {
    gKanoke64 = CreateMapObjectModelAnimated(mapObjectList, gKanoke64NsbmdName);
    CreateMapObjectModelNsbcaAnimation(gKanoke64, gKanoke64NsbcaName);
}

void DrawKanoke64(void *mapObjectList, Kanoke64 *kanoke64) {
    s32 commandArg;

    SetMapObjectModelNsbcaFrameIndex(gKanoke64, kanoke64->mNsbcaFrameIndex);
    commandArg = 0x1e;
    NNS_G3dGeBufferOP_N(0x14, &commandArg, 1);
    kanoke64->mMapObject.mMatrix.mUnk_00[3].x = kanoke64->mMapObject.mPos.x >> 4;
    kanoke64->mMapObject.mMatrix.mUnk_00[3].y = kanoke64->mMapObject.mPos.y >> 4;
    kanoke64->mMapObject.mMatrix.mUnk_00[3].z = kanoke64->mMapObject.mPos.z >> 4;
    NNS_G3dGeBufferOP_N(0x19, &kanoke64->mMapObject.mMatrix, 0xc);
    NNS_G3dGeBufferOP_N(0x1b, &kanoke64->mMapObject.mScale, 3);
    DrawMapObjectModel(mapObjectList, gKanoke64, kanoke64);
}

void InitKanoke64Objects(MapObjectList *mapObjectList) {
    s32 i;
    Kanoke64 *kanoke64;

    if (mapObjectList == NULL) {
        return;
    }
    for (i = 0; i < mapObjectList->mMapObjectCount && (kanoke64 = mapObjectList->mMapObjects[i]) != NULL; i++) {
        if (kanoke64->mMapObject.mFlags & 0x800) {
            kanoke64->mTimer = (u16) (func_020919e8_inline_2(25) + 200);
        }
    }
}

// Returns a random value below b (0 when b is 0), advancing the generator a.
u32 NextRandomBelow(RandomState64 *randomState64, u32 limit) {
    if (limit == 0) {
        return 0;
    }
    randomState64->mValue = randomState64->mMultiplier * randomState64->mValue + randomState64->mIncrement;
    if (limit == 0) {
        return randomState64->mValue >> 32;
    }
    return ((randomState64->mValue >> 32) * limit) >> 32;
}

s16 Kanoke64GetAnglePairFirst(s32 angle) {
    return gPairsByAngle[(angle >> 4) * 2];
}

s32 Kanoke64MulFixed12NoRound(s32 multiplicand, s32 multiplier) {
    return MUL_FIXED12_NO_ROUND(multiplicand, multiplier);
}

static inline s64 func_020919e8_inline_5(const Vec3 *firstPos, const Vec3 *secondPos) {
    s32 deltaX;
    s32 deltaZ;

    deltaX = firstPos->x - secondPos->x;
    deltaZ = firstPos->z - secondPos->z;
    return (s64) deltaX * deltaX + (s64) deltaZ * deltaZ;
}

static inline BOOL func_020919e8_inline_4(Kanoke64 *kanoke64, s32 objectAngle) {
    s32 i;
    BOOL isHumanGhostOrPeer;
    s32 angleDifference;
    Kart *kart;

    for (i = 0; i < gRaceSetup->mKartCount; i++) {
        isHumanGhostOrPeer = FALSE;
        if (gRaceSetup->mCurrentEntries[(u16) i].mPlayer.mKind <= 3 &&
            ((1 << gRaceSetup->mCurrentEntries[(u16) i].mPlayer.mKind) & PLAYER_KIND_MASK_HUMAN_GHOST_PEER)) {
            isHumanGhostOrPeer = TRUE;
        }
        if (isHumanGhostOrPeer == FALSE && i != gRaceSetup->mEntryIndex) {
            continue;
        }
        kart = GetKart((u16) i);
        if (func_020919e8_inline_5(&kart->mPos, &kanoke64->mMapObject.mPos) >= 0x225510000000LL) {
            continue;
        }
        angleDifference =
            FX_Atan2Idx(kart->mPos.x - kanoke64->mMapObject.mPos.x, kart->mPos.z - kanoke64->mMapObject.mPos.z) -
            objectAngle;
        if (angleDifference < -0x1f40) {
            continue;
        }
        if (angleDifference <= 0x1f40) {
            return TRUE;
        }
    }
    return FALSE;
}

static inline void func_020919e8_inline_6(Vec3 *outPos, s32 baseX, s32 baseY, s32 baseZ) {
    outPos->x = baseX - 0x5000 + func_020919e8_inline(0xa000);
    GetMapObjectRandom();
    outPos->y = baseY;
    outPos->z = baseZ - 0x28000 + func_020919e8_inline(0x50000);
}

s16 Kanoke64GetAnglePairSecond(s32 angle) {
    return gPairsByAngle[(angle >> 4) * 2 + 1];
}

void UpdateKanoke64(void *mapObjectList, Kanoke64 *kanoke64) {
    s32 i;
    s32 horizontalSpeed;
    u16 angle;
    s32 nextFrameIndex;
    Vec3 basabasaPos;
    Vec3 basabasaVelocity;

    switch (kanoke64->mState) {
        case 0:
            if (GetCurrentCameraKind() == 2) {
                kanoke64->mState = 1;
                return;
            }
            if (kanoke64->mMapObject.mFlags & 0x800) {
                if (kanoke64->mTimer-- <= 0) {
                    kanoke64->mTimer = 8;
                    kanoke64->mState = 1;
                }
                return;
            }
            if (func_020919e8_inline_4(kanoke64, kanoke64->mMapObject.mAngle) != FALSE) {
                kanoke64->mTimer = 8;
                kanoke64->mState = 1;
            }
            return;
        case 1:
            break;
        default:
            return;
    }
    if (kanoke64->mNsbcaFrameIndex == 10) {
        for (i = 0; i < 3; i++) {
            func_020919e8_inline_6(&basabasaPos, kanoke64->mMapObject.mPos.x, kanoke64->mMapObject.mPos.y + 0x19000,
                                   kanoke64->mMapObject.mPos.z);
            angle = kanoke64->mMapObject.mAngle;
            horizontalSpeed = NextRandomBelow(GetMapObjectRandom(), 0x1000) + 0x800;
            angle = angle - 0x3e8 + NextRandomBelowU16(GetMapObjectRandom(), 0x7d0);
            basabasaVelocity.x = Kanoke64MulFixed12NoRound(horizontalSpeed, Kanoke64GetAnglePairFirst(angle));
            basabasaVelocity.y = NextRandomBelow(GetMapObjectRandom(), 0x400) + 0x2200;
            basabasaVelocity.z = Kanoke64MulFixed12NoRound(horizontalSpeed, Kanoke64GetAnglePairSecond(angle));
            if (i == 0 && kanoke64->mBurstCount == 0) {
                StartBasabasa(0x50, &basabasaPos, &basabasaVelocity, 0x28, 1, i == 0 ? 3 : 0);
            } else {
                StartBasabasa(0x50, &basabasaPos, &basabasaVelocity, 0x28, 0, i == 0 ? 3 : 0);
            }
        }
        kanoke64->mBurstCount += 1;
        if (kanoke64->mBurstCount >= 3) {
            kanoke64->mBurstCount = 0;
        }
    }
    nextFrameIndex = kanoke64->mNsbcaFrameIndex + 1;
    if (nextFrameIndex >= GetMapObjectModelNsbcaFrameCount(gKanoke64)) {
        nextFrameIndex = 0;
    }
    kanoke64->mNsbcaFrameIndex = nextFrameIndex;
    if (kanoke64->mNsbcaFrameIndex == 0) {
        if (kanoke64->mTimer-- <= 0) {
            kanoke64->mBurstCount = 0;
            kanoke64->mState = 0;
            if (kanoke64->mMapObject.mFlags & 0x800) {
                kanoke64->mTimer = (u16) (func_020919e8_inline_2(25) + 200);
            }
        }
    }
    if (kanoke64->mNsbcaFrameIndex != 0) {
        return;
    }
    func_020919e8_inline_3(kanoke64, 0x188);
}

void CreateKanoke64DrawList(void) {
    CreateMapObjectDrawList1(CreateKanoke64, DrawKanoke64, NULL);
}

void CreateKanoke64UpdateList(void) {
    CreateMapObjectUpdateList(InitKanoke64Objects, UpdateKanoke64, NULL);
}

void CreateCow(void *mapObjectList) {
    gCow = CreateMapObjectModelNsbmdNsbtp(mapObjectList, gCowNsbmdName, gCowNsbtpName);
    SetMapObjectModelPolygonId(gCow, 0x3f);
}

void SetupDrawCow(void *mapObjectList) {
    QueueMapObjectModelMaterial(mapObjectList, gCow);
}

void DrawCow(void *mapObjectList, MapObject *mapObject) {
    s32 commandArg;

    commandArg = 0x1e;
    NNS_G3dGeBufferOP_N(0x14, &commandArg, 1);
    NNS_G3dGeBufferOP_N(0x19, SetViewRotatedMatrixPos(&mapObject->mPos), 0xc);
    NNS_G3dGeBufferOP_N(0x1b, &mapObject->mScale, 3);
    SetMapObjectModelNsbtpFrameIndex(gCow, mapObject->mCourseMapRow->mUnk_28);
    DrawMapObjectModel(mapObjectList, gCow, mapObject);
}

void CreateCowDrawList(void) {
    CreateMapObjectDrawList2(CreateCow, DrawCow, SetupDrawCow);
}
