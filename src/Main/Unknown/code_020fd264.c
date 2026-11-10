#include "Main/Unknown/code_020fd264.h"
#include "Main/Unknown/code_020467d0.h"
#include "Main/Unknown/code_0208ab98.h"

#include "Main/Unknown/code_020f36d8.h"
#include "Main/Unknown/code_020fa000.h"
#include "Main/Unknown/code_020f9c40.h"
#include "Main/Unknown/code_02046000.h"
#include "Main/Unknown/code_02046be8.h"
#include "Main/Unknown/code_020d2000.h"
#include "Main/Unknown/code_020fd83c.h"
#include "Main/Unknown/code_02109054.h"
#include "Main/Unknown/unk_021759c0.h"
#include "Main/Unknown/unk_0216c000.h"
#include "code_02147cd8.h"
#include "Main/Unknown/code_0208a000.h"
#include "Main/Unknown/code_020f2dac.h"
#include "Main/Unknown/code_020f9000.h"
#include "Main/Unknown/unk_02159000.h"
#include "Main/Unknown/code_020ee684.h"
#include "Main/Unknown/code_020fd7f0.h"
#include "Main/Unknown/code_020fd804.h"
#include "Main/Unknown/code_020f2d98.h"
#include "Main/Unknown/code_02109000.h"
#include "Main/Unknown/code_0208d978.h"
#include "Main/Unknown/code_0206bcb0.h"
#include "Main/Unknown/code_02073000.h"
#include "Main/Unknown/code_02108ea0.h"
#include "Main/Unknown/code_02061654.h"
#include "Main/Unknown/code_020b1dbc.h"
#include "Main/Unknown/code_0207b960.h"
#include "Main/Unknown/code_020b4e5c.h"
#include "Main/Unknown/code_02039860.h"
#include "Main/Unknown/code_02147000.h"
#include "Main/Unknown/unk_0215d000.h"
#include "Main/Unknown/code_020b47d8.h"
#include "Main/Unknown/code_020b6a18.h"
#include "Main/Unknown/code_0207a880.h"
#include "Main/Unknown/code_020b502c.h"
#include "Main/Unknown/unk_0217c000.h"
#include "Main/Unknown/unk_0217d000.h"
#include "code_0212bcac.h"
#include "code_0212df7c.h"
#include "Main/Unknown/code_020ed5c0.h"
#include "Main/Unknown/code_020f49bc.h"
#include "Main/Unknown/code_020f7000.h"
#include "Main/Unknown/code_020f8000.h"
#include "Main/Unknown/code_0210e000.h"
#include "Main/Unknown/code_020fe4b4.h"
#include "Main/Unknown/unk_027e0000.h"
#include "Main/Unknown/code_020fe168.h"
#include "Main/Unknown/code_020fe16c.h"
#include "Main/Unknown/code_020fe264.h"
#include "Main/Unknown/code_020fe268.h"
#include "Main/Unknown/code_020fe3d8.h"
#include "Main/Unknown/code_02077bc0.h"
#include "code_021471bc.h"
#include "Main/Unknown/code_021000d0.h"

// Reset hook of the bomb kind.
void ResetItemBomb(ItemBomb *bomb) {
    u32 initialDistanceSquared;
    MTX_Identity43_(&bomb->mUnk_13c);
    InitStateMachine(&bomb->mStateMachine, gItemBombStateTable, 4, bomb);
    SetStateMachineState(&bomb->mStateMachine, 0);
    bomb->mTimer = 300;
    bomb->mModelFrameTimer = 0;
    initialDistanceSquared = 0x05f592e1u;
    bomb->mNearestKartIndex = 8;
    bomb->mNearestKartDistanceSquared = initialDistanceSquared;
    bomb->mTimerEndBlockTimer = 0;
    bomb->mHitSpinsKart = FALSE;
    bomb->mVisible = TRUE;
    bomb->mPooledMapObject = NULL;
}

s32 InitItemBomb(ItemInUse *inUse, ItemBomb *bomb) {
    StartItemObjectSoundSource(&bomb->mUnk_000.mItemObject);
    bomb->mUnk_000.mItemObject.mOwnerKartIndexAndFlags |= data_02159f3c;
    bomb->mReflectFactor = MUL_FIXED12_NO_ROUND(inUse->mKartVelocityLength, 0x1ec) + 0x333;
    if (bomb->mReflectFactor > 0xccd) {
        bomb->mReflectFactor = 0xccd;
    }
    if (inUse->mKartItems->mFlags & 0x20) {
        ThrowBouncingItem(&bomb->mUnk_000, inUse, 2, 0, 0x7800, 0x5000, 0x219a);
        bomb->mTimer = 0x5a;
        bomb->mUnk_130 = 0;
        return bomb->mUnk_130;
    }
    if (inUse->mKartItems->mFlags & KART_ITEMS_THROW_FORWARD) {
        ThrowBouncingItem(&bomb->mUnk_000, inUse, 3, 1, 0x9800, 0x5000, 0x59a);
    } else {
        ThrowBouncingItem(&bomb->mUnk_000, inUse, 3, 1, 0x6000, 0x5000, 0x59a);
    }
    StartSound(&bomb->mUnk_000.mItemObject.mSoundSource, 0xda, 0x7f, 0);
    bomb->mUnk_130 = 1;
    return bomb->mUnk_130;
}

u32 ItemBombState0ReturnArgument(u32 value) {
    return value;
}

void UpdateItemBombState0(ItemBomb *bomb) {
    u32 v;

    if (bomb->mUnk_130 != 0) {
        AdvanceBouncingItem(&bomb->mUnk_000, 0x385, 0xff8, 0x733, &v);
    } else {
        AdvanceBouncingItem(&bomb->mUnk_000, 0x47b, 0xf91, bomb->mReflectFactor, &v);
    }
    if (bomb->mUnk_000.mItemObject.mFlags & 0x10) {
        StartItemObjectSoundIfNear(&bomb->mUnk_000.mItemObject, 0xe5);
    }
    if ((bomb->mUnk_000.mItemObject.mFlags & 0x8) == 0) {
        return;
    }
    if (bomb->mUnk_000.mItemObject.mFlags & 0x3) {
        return;
    }
    if (bomb->mUnk_130 != 0) {
        bomb->mUnk_000.mItemObject.mVelocity.y *= 2;
    }
    StopSound(&bomb->mUnk_000.mItemObject.mSoundSource, 0xda);
    StartRestingItemObject(&bomb->mUnk_000.mItemObject, &v);
    if ((bomb->mUnk_000.mItemObject.mFlags & 0x180000) == 0) {
        bomb->mUnk_000.mItemObject.mAdvance = (void (*)(ItemObject *)) AdvanceItemBomb;
    }
    bomb->mStateMachine.mNextState = 1;
    bomb->mStateMachine.mNextStateRequested = 1;
}

u32 ItemBombState1ReturnArgument(u32 value) {
    return value;
}

void UpdateItemBombState1(ItemBomb *bomb) {
    u32 flags;

    flags = bomb->mUnk_000.mItemObject.mFlags;
    if (flags & 0x8000) {
        AdvanceRestingItemObject(&bomb->mUnk_000.mItemObject);
        return;
    }
    if (flags & 0x4000) {
        AdvanceFallingItemObject(&bomb->mUnk_000.mItemObject);
        bomb->mTimer = 0x5a;
        bomb->mModelFrameTimer = 0;
    }
}

void EnterItemBombState2(ItemBomb *bomb) {
    NNSSndSeqPlayer **seqPlayerPointer;
    ModelEffect *modelEffect;

    bomb->mUnk_000.mItemObject.mFlags |= 0x800000;
    bomb->mUnk_000.mItemObject.mUnk_100 = 0;
    bomb->mUnk_000.mItemObject.mScale = gItemBombState2StartScale;
    bomb->mModelEffect = StartModelEffect(0, &bomb->mUnk_000.mItemObject.mPos,
                                          IsItemObjectTooFarForEffects(&bomb->mUnk_000.mItemObject) == 0 ? 1 : 0);
    modelEffect = bomb->mModelEffect;
    if (modelEffect != NULL) {
        s32 *effectScale;

        effectScale = modelEffect->mScale;
        effectScale[0] = 0xccd;
        effectScale[1] = 0xccd;
        effectScale[2] = 0xccd;
    }
    StartItemObjectSoundIfNear(&bomb->mUnk_000.mItemObject, 0xe4);
    if (data_0217c780 & 1) {
        seqPlayerPointer = TakeSoundHandleEntry(GetSoundHandlePool(0));
        if (data_0217d084.mUnk_0c != 0) {
            if (seqPlayerPointer[0] != NULL) {
                NNS_SndPlayerStopSeq(seqPlayerPointer, 0);
            }
            if (seqPlayerPointer[0] != NULL) {
                NNS_SndPlayerStopSeq(seqPlayerPointer, 0);
            }
            NNS_SndArcPlayerStartSeqArc(seqPlayerPointer, 0, 0xe0);
        }
    }
    StartCameraWobbleAtDistance(bomb->mUnk_000.mItemObject.mDistanceSquaredAndFlags & ~0xc000001f, 0x1000);
}

void UpdateItemBombState2(ItemBomb *bomb) {
    s32 stateFrames;

    stateFrames = bomb->mStateMachine.mStateFrames;
    if (GrowItemObjectScale(&bomb->mUnk_000.mItemObject, gItemBombState2ScaleLimit, gItemBombState2ScaleStep) != 0) {
        RefreshItemObjectScaleExact(&bomb->mUnk_000.mItemObject);
    }
    if (stateFrames < 0x16) {
        return;
    }
    if (stateFrames == 0x16) {
        bomb->mHitSpinsKart = TRUE;
    } else if (stateFrames == 0x2a) {
        FreeItemObjectCollisionSlot(&bomb->mUnk_000.mItemObject);
    }
    if (stateFrames <= 0x55) {
        return;
    }
    ReleaseItemPoolObject(gItemPools + bomb->mUnk_000.mItemObject.mKind, &bomb->mUnk_000.mItemObject);
}

void AdvanceItemBombNearestKart(ItemBomb *bomb) {
    u32 candidateKartIndex;
    u16 skippedKartIndex;
    Kart *kart;
    Vec3 kartPosition;
    s32 distanceSquared;
    s32 deltaX;
    s32 deltaY;
    s32 deltaZ;

    candidateKartIndex = (u16) GetRaceUpdateFramesMod8();
    if (candidateKartIndex >= gRaceSetup->mKartCount) {
        return;
    }
    skippedKartIndex = (bomb->mUnk_000.mItemObject.mOwnerKartIndexAndFlags & 0x8000) == 0
                           ? (u16) (bomb->mUnk_000.mItemObject.mOwnerKartIndexAndFlags & ~0xff00)
                           : 8;
    if (candidateKartIndex == skippedKartIndex) {
        return;
    }
    kart = GetKart(candidateKartIndex);
    if (func_0206c0e0(kart) != 0) {
        return;
    }
    if (bomb->mNearestKartDistanceSquared < 8) {
        GetKartPos(&kartPosition, bomb->mNearestKartIndex);
        deltaX = (bomb->mUnk_000.mItemObject.mPos.x - kartPosition.x) >> 12;
        deltaY = (bomb->mUnk_000.mItemObject.mPos.y - kartPosition.y) >> 12;
        deltaZ = (bomb->mUnk_000.mItemObject.mPos.z - kartPosition.z) >> 12;
        distanceSquared = deltaX * deltaX + deltaY * deltaY + deltaZ * deltaZ;
        bomb->mNearestKartDistanceSquared = distanceSquared;
    }
    kartPosition = kart->mDrawMatrixPos;
    deltaX = (bomb->mUnk_000.mItemObject.mPos.x - kartPosition.x) >> 12;
    deltaY = (bomb->mUnk_000.mItemObject.mPos.y - kartPosition.y) >> 12;
    deltaZ = (bomb->mUnk_000.mItemObject.mPos.z - kartPosition.z) >> 12;
    distanceSquared = deltaX * deltaX + deltaY * deltaY + deltaZ * deltaZ;
    if (distanceSquared < bomb->mNearestKartDistanceSquared) {
        bomb->mNearestKartIndex = candidateKartIndex;
        bomb->mNearestKartDistanceSquared = distanceSquared;
    }
}

void ClampItemBombTimerByDistance(ItemBomb *bomb) {
    if (bomb->mNearestKartDistanceSquared > (gItemBombState2MaxRadiusSquared << 6)) {
        return;
    }
    if (bomb->mNearestKartDistanceSquared > (gItemBombState2MaxRadiusSquared << 4)) {
        if (bomb->mTimer > gItemBombTimerLimit) {
            bomb->mTimer = gItemBombTimerLimit;
        }
        return;
    }
    if (bomb->mNearestKartDistanceSquared > (gItemBombState2MaxRadiusSquared << 2)) {
        if (bomb->mTimer > (gItemBombTimerLimit >> 1)) {
            bomb->mTimer = gItemBombTimerLimit >> 1;
        }
        return;
    }
    if (bomb->mNearestKartDistanceSquared > gItemBombState2MaxRadiusSquared) {
        if (bomb->mTimer > (gItemBombTimerLimit >> 2)) {
            bomb->mTimer = gItemBombTimerLimit >> 2;
        }
        return;
    }
    if (bomb->mTimer > 4) {
        bomb->mTimer = 4;
        bomb->mModelFrameTimer = 3;
    }
}

void AdvanceItemBombWithMapObject(ItemBomb *bomb, ItemBomb *bombAlias, ItemBox *pooledMapObject) {
    ItemBox *mapObjectToPark;

    bombAlias->mUnk_000.mItemObject.mDistanceSquaredAndFlags |= gItemObjectDistanceSquaredMask;
    AdvanceStateMachine(&bomb->mStateMachine);
    if (pooledMapObject->mUnk_000.mFlags & 0x100) {
        bomb->mPooledMapObject = NULL;
        ReleaseItemPoolObject(gItemPools + bomb->mUnk_000.mItemObject.mKind, &bomb->mUnk_000.mItemObject);
        return;
    }
    if ((bombAlias->mUnk_000.mItemObject.mFlags & 0x8000) == 0) {
        pooledMapObject->mUnk_000.mPos = bombAlias->mUnk_000.mItemObject.mPos;
        pooledMapObject->mUnk_000.mPos.y += bomb->mMapObjectOffsetY - bombAlias->mUnk_000.mItemObject.mCourseRadius;
    }
    if (bomb->mTimer <= 0) {
        if ((bombAlias->mUnk_000.mItemObject.mFlags & 0x8000) == 0) {
            return;
        }
        bomb->mPooledMapObject = NULL;
        ReleaseItemPoolObject(gItemPools + bomb->mUnk_000.mItemObject.mKind, &bomb->mUnk_000.mItemObject);
        return;
    }
    bomb->mTimer--;
    if (bomb->mTimer < pooledMapObject->mUnk_000.mAlpha) {
        pooledMapObject->mUnk_000.mAlpha = bomb->mTimer;
    }
    if (bomb->mTimer < 0x10) {
        pooledMapObject->mUnk_000.mFlags |= data_02159f18;
    }
    if (bomb->mTimer == 0) {
        mapObjectToPark = bomb->mPooledMapObject;
        mapObjectToPark->mUnk_000.mFlags &= ~1;
        ParkMapObject(&mapObjectToPark->mUnk_000);
        bomb->mPooledMapObject = NULL;
        ReleaseItemPoolObject(gItemPools + bomb->mUnk_000.mItemObject.mKind, &bomb->mUnk_000.mItemObject);
    }
}

void AdvanceItemBomb(ItemBomb *bomb) {
    if (bomb->mPooledMapObject != NULL) {
        AdvanceItemBombWithMapObject(bomb, bomb, bomb->mPooledMapObject);
        return;
    }
    AdvanceStateMachine(&bomb->mStateMachine);
    if ((bomb->mUnk_000.mItemObject.mFlags & 0x80000) || bomb->mTimer < 0) {
        FadeOutEndedItemObject(&bomb->mUnk_000.mItemObject, 1);
    }
    bomb->mTimer--;
    if (bomb->mTimerEndBlockTimer > 0) {
        bomb->mTimerEndBlockTimer--;
        if (bomb->mTimer == 0) {
            bomb->mTimer = 0x10;
        }
    }
    if (bomb->mUnk_000.mBouncesRemaining >= 3) {
        return;
    }
    if (bomb->mUnk_130 == 0 && bomb->mUnk_000.mBouncesRemaining >= 2) {
        return;
    }
    if ((bomb->mUnk_000.mItemObject.mOwnerKartIndexAndFlags & 0x8000) == 0) {
        AdvanceItemBombNearestKart(bomb);
        if (bomb->mTimerEndBlockTimer == 0) {
            ClampItemBombTimerByDistance(bomb);
        }
    }
    if (bomb->mTimer >= 0xd2) {
        return;
    }
    bomb->mModelFrameTimer--;
    if (bomb->mModelFrameTimer > 0) {
        return;
    }
    bomb->mModelFrameTimer = bomb->mTimer >> 2;
    if (bomb->mModelFrameTimer < 8) {
        bomb->mModelFrameTimer = 8;
    }
}

void *CopyItemBombData(void *cursor, ItemBomb *bomb, void *toData) {
    void *nextCursor;

    if (bomb != NULL && toData != NULL) {
        StoreItemDataFlagBit(bomb->mUnk_130, &bomb->mUnk_000.mItemObject.mVelocity.y);
    }
    nextCursor = CopyItemObjectData(cursor, bomb, toData);
    nextCursor = CopyItemShiftedByte(nextCursor, bomb != NULL ? &bomb->mReflectFactor : 0, toData);
    if (bomb != NULL && toData == NULL) {
        LoadItemDataFlagBit(bomb->mUnk_000.mItemObject.mVelocity.y, &bomb->mUnk_130);
    }
    if (bomb != NULL && toData != NULL) {
        return AddItemDataSizedByKind(bomb->mUnk_000.mItemObject.mKind);
    }
    return nextCursor;
}

void InitItemBombFromData(ItemBomb *bomb) {
    SetupItemObjectFromData(&bomb->mUnk_000.mItemObject);
    StartItemObjectBouncing(&bomb->mUnk_000, bomb->mUnk_130 != 0 ? 3 : 2);
    InitStateMachine(&bomb->mStateMachine, gItemBombStateTable, 4, bomb);
    if (!(bomb->mUnk_000.mItemObject.mFlags & 0x10000000)) {
        return;
    }
    if (bomb->mUnk_130 == 0) {
        return;
    }
    StartSound(&bomb->mUnk_000.mItemObject.mSoundSource, 0xda, 0x7f, 0);
}

void DrawItemBomb(ItemBomb *bomb, Vec3 *viewAxis, NsbmdModel *model) {
    if (bomb->mVisible == FALSE) {
        return;
    }
    if (bomb->mStateMachine.mState != 2) {
        if (bomb->mModelFrameTimer != 0 && bomb->mModelFrameTimer < 6) {
            model->mFrameIndex = 1;
        } else {
            model->mFrameIndex = 0;
        }
        DrawItemObjectModel(&bomb->mUnk_000.mItemObject, model, viewAxis);
        return;
    }
    if (bomb->mModelEffect == NULL) {
        return;
    }
    bomb->mModelEffect->mVisible = (bomb->mUnk_000.mItemObject.mFlags & 0x10000) == 0;
}

int RequestItemBombState2(ItemBomb *bomb) {
    if (bomb->mStateMachine.mState != 2) {
        InitStateMachine(&bomb->mStateMachine, gItemBombStateTable, 4, bomb);
        bomb->mStateMachine.mNextState = 2;
        bomb->mStateMachine.mNextStateRequested = 1;
        if ((bomb->mUnk_000.mItemObject.mFlags & 0x180000) == 0) {
            bomb->mUnk_000.mItemObject.mAdvance = (void (*)(ItemObject *)) AdvanceItemBomb;
        }
        bomb->mUnk_000.mItemObject.mFlags &= ~0x8000;
        bomb->mUnk_000.mItemObject.mFlags |= 0x80000;
        bomb->mUnk_000.mItemObject.mOwnerKartIndexAndFlags &= ~0x4000;
    }
    return 1;
}

void RequestItemBombState1(ItemBomb *bomb) {
    if (bomb->mUnk_000.mItemObject.mFlags & 0x80000) {
        return;
    }
    InitStateMachine(&bomb->mStateMachine, gItemBombStateTable, 4, bomb);
    if ((bomb->mUnk_000.mItemObject.mFlags & 0x180000) == 0) {
        bomb->mUnk_000.mItemObject.mAdvance = (void (*)(ItemObject *)) AdvanceItemBomb;
    }
    bomb->mStateMachine.mNextState = 1;
    bomb->mStateMachine.mNextStateRequested = 1;
    bomb->mTimerEndBlockTimer = 0x10e;
    bomb->mUnk_130 = 0;
    bomb->mUnk_000.mBouncesRemaining = 0;
}

// Release hook of the bomb kind: parks its map object, if it has one.
void ParkItemBombMapObject(ItemBomb *bomb) {
    ItemBox *pooledMapObject = bomb->mPooledMapObject;
    if (pooledMapObject == NULL) {
        return;
    }
    pooledMapObject->mUnk_000.mFlags &= ~1;
    ParkMapObject(&pooledMapObject->mUnk_000);
}

u32 GetItemBombActiveCount(void) {
    return gItemPools[9].mActiveCount;
}

#pragma thumb off

ItemBomb *GetRestingItemBomb(int index) {
    ItemBomb *bomb;
    u32 flags;

    bomb = (ItemBomb *) gItemPools[9].mObjects[index];
    flags = bomb->mUnk_000.mItemObject.mFlags;
    if ((flags & 0x8000) && (flags & 0x180000) == 0 && bomb->mStateMachine.mState != 3 &&
        bomb->mPooledMapObject == NULL) {
        return bomb;
    }
    return NULL;
}

void ParkItemBomb(void *object) {
    ItemBomb *bomb;

    bomb = object;
    bomb->mUnk_000.mItemObject.mFlags &= ~0x8000;
    if ((bomb->mUnk_000.mItemObject.mFlags & 0x180000) == 0) {
        bomb->mUnk_000.mItemObject.mAdvance = NULL;
    }
    FreeItemObjectCollisionSlot(&bomb->mUnk_000.mItemObject);
    bomb->mVisible = FALSE;
    SetStateMachineState(&bomb->mStateMachine, 3);
    bomb->mModelFrameTimer = 0;
}

void PlaceItemBomb(void *object, Vec3 *normal, Vec3 *position) {
    ItemBomb *bomb;
    Vec3 *normalAlias;
    Vec3 *positionAlias;
    ItemBox *pooledMapObject;

    bomb = object;
    normalAlias = normal;
    positionAlias = position;
    if (bomb->mPooledMapObject == NULL) {
        bomb->mVisible = TRUE;
        SetCourseColorBlendColor(&bomb->mUnk_000.mItemObject.mColorBlend, 1);
    }
    if (normalAlias != NULL) {
        bomb->mUnk_000.mItemObject.mNormal = *normalAlias;
        bomb->mUnk_000.mItemObject.mFlags |= 0x80;
    }
    if (positionAlias == NULL) {
        return;
    }
    bomb->mUnk_000.mItemObject.mPos = *positionAlias;
    VEC_Subtract(&bomb->mUnk_000.mItemObject.mPos, &bomb->mUnk_000.mItemObject.mPrevPos,
                 &bomb->mUnk_000.mItemObject.mVelocity);
    if (bomb->mPooledMapObject == NULL) {
        return;
    }
    bomb->mPooledMapObject->mUnk_000.mPos = *positionAlias;
    bomb->mPooledMapObject->mUnk_000.mPos.y += bomb->mMapObjectOffsetY;
    pooledMapObject = bomb->mPooledMapObject;
    pooledMapObject->mUnk_000.mFlags &= ~2;
    pooledMapObject->mUnk_000.mFlags &= ~8;
    pooledMapObject->mUnk_000.mAlpha = 0x1f;
}

void ThrowItemBombFromSlot(void **bombSlot, Vec3 *velocity, s32 timerStart) {
    ItemBomb *bomb;
    ItemBox *pooledMapObject;

    bomb = *bombSlot;
    pooledMapObject = bomb->mPooledMapObject;
    bomb->mUnk_000.mItemObject.mOwnerKartIndexAndFlags |= gItemBombNoOwnerBit;
    if (pooledMapObject == NULL) {
        CreateItemObjectCollisionSlot(&bomb->mUnk_000.mItemObject);
        bomb->mVisible = TRUE;
    }
    StartItemObjectSoundSource(&bomb->mUnk_000.mItemObject);
    InitStateMachine(&bomb->mStateMachine, gItemBombStateTable, 4, bomb);
    SetStateMachineState(&bomb->mStateMachine, 0);
    bomb->mTimer = 0x12c;
    bomb->mModelFrameTimer = 0;
    bomb->mNearestKartIndex = 8;
    bomb->mNearestKartDistanceSquared = 0x5f592e1;
    bomb->mTimerEndBlockTimer = 0;
    bomb->mHitSpinsKart = FALSE;
    bomb->mReflectFactor = 0xccd;
    bomb->mTimer = timerStart;
    bomb->mUnk_130 = 1;
    InitBouncingItem(&bomb->mUnk_000, 3, velocity);
    if ((bomb->mUnk_000.mItemObject.mFlags & 0x180000) == 0) {
        bomb->mUnk_000.mItemObject.mAdvance = (void (*)(ItemObject *)) AdvanceItemBomb;
    }
    if (pooledMapObject != NULL) {
        pooledMapObject->mUnk_000.mFlags &= ~2;
        pooledMapObject->mUnk_000.mFlags &= ~8;
        pooledMapObject->mUnk_000.mAlpha = 0x1f;
        pooledMapObject->mUnk_000.mFlags &= ~4;
        if (pooledMapObject->mUnk_000.mKind != MAP_OBJECT_KIND_KURIBO) {
            pooledMapObject->mUnk_000.mFlags &= ~1;
        }
    }
    *bombSlot = NULL;
}

BOOL IsItemBombState2(ItemObject *object) {
    ItemBomb *bomb;

    bomb = (ItemBomb *) object;
    return bomb->mStateMachine.mState == 2;
}

void ReleaseItemBomb(void **bombSlot) {
    ItemBomb *bomb;
    ItemBox *pooledMapObject;

    bomb = *bombSlot;
    SetStateMachineState(&bomb->mStateMachine, 0);
    pooledMapObject = bomb->mPooledMapObject;
    if (pooledMapObject != NULL) {
        pooledMapObject->mUnk_000.mFlags &= ~1;
        ParkMapObject(&pooledMapObject->mUnk_000);
        bomb->mPooledMapObject = NULL;
        ReleaseItemPoolObject(gItemPools + bomb->mUnk_000.mItemObject.mKind, &bomb->mUnk_000.mItemObject);
    } else {
        ReleaseItemPoolObject(gItemPools + bomb->mUnk_000.mItemObject.mKind, &bomb->mUnk_000.mItemObject);
    }
    *bombSlot = NULL;
}

void *StartItemBomb(void) {
    ItemBomb *bomb;

    bomb = StartItemObjectOrZero(9, 8, gItemBombVec3UnitY, gItemBombVec3UnitY);
    if (bomb == NULL) {
        return NULL;
    }
    if ((bomb->mUnk_000.mItemObject.mFlags & 0x180000) == 0) {
        bomb->mUnk_000.mItemObject.mAdvance = NULL;
    }
    FreeItemObjectCollisionSlot(&bomb->mUnk_000.mItemObject);
    bomb->mVisible = FALSE;
    SetStateMachineState(&bomb->mStateMachine, 3);
    bomb->mModelFrameTimer = 0;
    return bomb;
}

void *StartItemBombWithMapObject(void *mapObject, s32 offsetY) {
    ItemBomb *bomb;
    ItemBox *pooledMapObject;

    pooledMapObject = mapObject;
    bomb = StartItemObjectOrZero(9, 8, gItemBombVec3UnitY, gItemBombVec3UnitY);
    if (bomb == NULL) {
        bomb = NULL;
    } else {
        if ((bomb->mUnk_000.mItemObject.mFlags & 0x180000) == 0) {
            bomb->mUnk_000.mItemObject.mAdvance = NULL;
        }
        FreeItemObjectCollisionSlot(&bomb->mUnk_000.mItemObject);
        bomb->mVisible = FALSE;
        SetStateMachineState(&bomb->mStateMachine, 3);
        bomb->mModelFrameTimer = 0;
    }
    if (bomb == NULL) {
        return NULL;
    }
    UnparkMapObject(&pooledMapObject->mUnk_000);
    pooledMapObject->mUnk_000.mFlags |= data_02159f18;
    pooledMapObject->mUnk_000.mFlags |= data_02159f1c;
    pooledMapObject->mUnk_000.mFlags |= data_02159f20;
    pooledMapObject->mUnk_000.mFlags |= data_02159f24;
    bomb->mPooledMapObject = pooledMapObject;
    bomb->mMapObjectOffsetY = offsetY;
    return bomb;
}

Vec3 *GetItemBombState2Info(ItemBomb *bomb, s32 *stateFrames, s32 *scaledScaleZ) {
    *stateFrames = bomb->mStateMachine.mStateFrames;
    *scaledScaleZ = MUL_FIXED12_NO_ROUND(bomb->mUnk_000.mItemObject.mScale.z, gItemBombState2InverseLimit);
    return &bomb->mUnk_000.mItemObject.mPos;
}

#pragma thumb on

void SetupItemBombKind(void) {
    s32 engineIndex;

    gItemBombState2ScaleLimit = 0x18006;
    gItemBombState2InverseLimit = FX_Div(0x1000, 0x18006);
    gItemBombState2ScaleStep = 0x2148;
    gItemBombState2MaxRadiusSquared = MUL_FIXED12_NO_ROUND(gItemBombState2ScaleLimit, gItemKinds[9].mRadius);
    gItemBombState2MaxRadiusSquared >>= 12;
    gItemBombState2MaxRadiusSquared *= gItemBombState2MaxRadiusSquared;
    engineIndex = gRaceSetup->mEngineIndex;
    switch (engineIndex) {
        case 0:
            gItemBombTimerLimit = 0xb4;
            break;
        case 1:
            gItemBombTimerLimit = 0x96;
            break;
        default:
            gItemBombTimerLimit = 0x78;
            break;
    }
}

#pragma thumb off
