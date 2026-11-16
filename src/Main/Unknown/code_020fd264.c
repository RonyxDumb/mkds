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
#include "Main/Item/ItemInUse.h"
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
void itbomb_initInstance(ItemBomb *bomb) {
    u32 initialDistanceSquared;
    MTX_Identity43_((MtxFx43 *) bomb->field13C);
    sm_init(bomb->field184, (UnkFunc *const *) &itbomb_sStates, 4, bomb);
    sm_gotoState(bomb->field184, 0);
    bomb->mTimer = 300;
    bomb->field174 = 0;
    initialDistanceSquared = 0x05f592e1u;
    bomb->mNearestKartIndex = 8;
    bomb->mNearestKartDistanceSquared = initialDistanceSquared;
    bomb->field180 = 0;
    bomb->field16C = FALSE;
    bomb->mVisible = TRUE;
    bomb->mPooledMapObject = NULL;
}

s32 itbomb_20FE268(ItemInUse *inUse, ItemBomb *bomb) {
    sub_20F9114(bomb);
    bomb->field0.mItemObject.field78 |= data_02159f3c;
    bomb->field134 = (s32) (((s64) inUse->mKartVelocityLength * 0x1ec) >> 12) + 0x333;
    if (bomb->field134 > 0xccd) {
        bomb->field134 = 0xccd;
    }
    if (inUse->mKartItems->mFlags & 0x20) {
        ThrowBouncingItem(&bomb->field0, inUse, 2, 0, 0x7800, 0x5000, 0x219a);
        bomb->mTimer = 0x5a;
        bomb->field130 = 0;
        return bomb->field130;
    }
    if (inUse->mKartItems->mFlags & KART_ITEMS_THROW_FORWARD) {
        ThrowBouncingItem(&bomb->field0, inUse, 3, 1, 0x9800, 0x5000, 0x59a);
    } else {
        ThrowBouncingItem(&bomb->field0, inUse, 3, 1, 0x6000, 0x5000, 0x59a);
    }
    sfx_21090C4(&bomb->field0.mItemObject.mSoundSource, 0xda, 0x7f, 0);
    bomb->field130 = 1;
    return bomb->field130;
}

u32 func_020fe264(u32 value) {
    return value;
}

void itbomb_20FE16C(ItemBomb *bomb) {
    s32 v;

    if (bomb->field130 != 0) {
        AdvanceBouncingItem(&bomb->field0, 0x385, 0xff8, 0x733, (u32 *) &v);
    } else {
        AdvanceBouncingItem(&bomb->field0, 0x47b, 0xf91, bomb->field134, (u32 *) &v);
    }
    if (bomb->field0.mItemObject.mFlags & KART_ITEMS_THROW_FORWARD) {
        it_20F91FC(bomb, 0xe5);
    }
    if ((bomb->field0.mItemObject.mFlags & 0x8) == 0) {
        return;
    }
    if (bomb->field0.mItemObject.mFlags & 0x3) {
        return;
    }
    if (bomb->field130 != 0) {
        bomb->field0.mItemObject.mVelocity.y *= 2;
    }
    StopSound(&bomb->field0.mItemObject.mSoundSource, 0xda);
    StartRestingItemObject(&bomb->field0.mItemObject, &v);
    if ((bomb->field0.mItemObject.mFlags & 0x180000) == 0) {
        bomb->field0.mItemObject.mAdvance = (void (*)(ItemObject *)) AdvanceItemBomb;
    }
    bomb->mNextState = 1;
    bomb->mNextStateRequested = 1;
}

u32 func_020fe168(u32 value) {
    return value;
}

void itbomb_20FE120(ItemBomb *bomb) {
    u32 flags;

    flags = bomb->field0.mItemObject.mFlags;
    if (flags & 0x8000) {
        AdvanceRestingItemObject(&bomb->field0.mItemObject);
        return;
    }
    if (flags & 0x4000) {
        AdvanceFallingItemObject(&bomb->field0.mItemObject);
        bomb->mTimer = 0x5a;
        bomb->field174 = 0;
    }
}

void itbomb_20FE00C(ItemBomb *bomb) {
    NNSSndSeqPlayer **seqPlayerPointer;
    ModelEffect *modelEffect;

    bomb->field0.mItemObject.mFlags |= 0x800000;
    bomb->field0.mItemObject.field100 = 0;
    bomb->field0.mItemObject.mScale = data_02159f30;
    bomb->mModelEffect =
        expl_spawnEffect(0, &bomb->field0.mItemObject.mPos, sub_20F9160(&bomb->field0.mItemObject) == 0 ? 1 : 0);
    modelEffect = bomb->mModelEffect;
    if (modelEffect != NULL) {
        s32 *t;

        t = modelEffect->mScale;
        t[0] = 0xccd;
        t[1] = 0xccd;
        t[2] = 0xccd;
    }
    it_20F91FC(bomb, 0xe4);
    if (data_0217c780 & 1) {
        seqPlayerPointer = sp_acquireElement(sound_getPoolById(0));
        if (SoundHandle_217D084.fieldC != 0) {
            if (seqPlayerPointer[0] != NULL) {
                NNS_SndPlayerStopSeq(seqPlayerPointer, 0);
            }
            if (seqPlayerPointer[0] != NULL) {
                NNS_SndPlayerStopSeq(seqPlayerPointer, 0);
            }
            NNS_SndArcPlayerStartSeqArc(seqPlayerPointer, 0, 0xe0);
        }
    }
    cam_tryImpactShakePlayerCamera(bomb->field0.mItemObject.mDistanceSquaredAndFlags & ~0xc000001f, 0x1000);
}

void itbomb_20FDF64(ItemBomb *bomb) {
    s32 stateFrames;

    stateFrames = bomb->mStateFrames;
    if (GrowItemObjectScale(bomb, data_0217bd50, data_0217bd54) != 0) {
        sub_20F9FA8(&bomb->field0.mItemObject);
    }
    if (stateFrames < 0x16) {
        return;
    }
    if (stateFrames == 0x16) {
        bomb->field16C = TRUE;
    } else if (stateFrames == 0x2a) {
        FreeItemObjectCollisionSlot((s32) bomb);
    }
    if (stateFrames <= 0x55) {
        return;
    }
    it_itemsetDestroyItem(it_sItemsets + bomb->field0.mItemObject.mKind, &bomb->field0.mItemObject);
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

    candidateKartIndex = (u16) race_getFrameCounterModulo8();
    if (candidateKartIndex >= gRaceMultiConfig->mKartCount) {
        return;
    }
    skippedKartIndex =
        (bomb->field0.mItemObject.field78 & 0x8000) == 0 ? (u16) (bomb->field0.mItemObject.field78 & ~0xff00) : 8;
    if (candidateKartIndex == skippedKartIndex) {
        return;
    }
    kart = driver_getById(candidateKartIndex);
    if (StructMQRacerEntry_SomeFn_86(kart) != 0) {
        return;
    }
    if (bomb->mNearestKartDistanceSquared < 8) {
        driver_getPosition(&kartPosition, bomb->mNearestKartIndex);
        deltaX = (bomb->field0.mItemObject.mPos.x - kartPosition.x) >> 12;
        deltaY = (bomb->field0.mItemObject.mPos.y - kartPosition.y) >> 12;
        deltaZ = (bomb->field0.mItemObject.mPos.z - kartPosition.z) >> 12;
        distanceSquared = deltaX * deltaX + deltaY * deltaY + deltaZ * deltaZ;
        bomb->mNearestKartDistanceSquared = distanceSquared;
    }
    kartPosition = kart->mDrawMatrixPos;
    deltaX = (bomb->field0.mItemObject.mPos.x - kartPosition.x) >> 12;
    deltaY = (bomb->field0.mItemObject.mPos.y - kartPosition.y) >> 12;
    deltaZ = (bomb->field0.mItemObject.mPos.z - kartPosition.z) >> 12;
    distanceSquared = deltaX * deltaX + deltaY * deltaY + deltaZ * deltaZ;
    if (distanceSquared < bomb->mNearestKartDistanceSquared) {
        bomb->mNearestKartIndex = candidateKartIndex;
        bomb->mNearestKartDistanceSquared = distanceSquared;
    }
}

void ClampItemBombTimerByDistance(ItemBomb *bomb) {
    if (bomb->mNearestKartDistanceSquared > (data_0217bd58 << 6)) {
        return;
    }
    if (bomb->mNearestKartDistanceSquared > (data_0217bd58 << 4)) {
        if (bomb->mTimer > data_0217bd4c) {
            bomb->mTimer = data_0217bd4c;
        }
        return;
    }
    if (bomb->mNearestKartDistanceSquared > (data_0217bd58 << 2)) {
        if (bomb->mTimer > (data_0217bd4c >> 1)) {
            bomb->mTimer = data_0217bd4c >> 1;
        }
        return;
    }
    if (bomb->mNearestKartDistanceSquared > data_0217bd58) {
        if (bomb->mTimer > (data_0217bd4c >> 2)) {
            bomb->mTimer = data_0217bd4c >> 2;
        }
        return;
    }
    if (bomb->mTimer > 4) {
        bomb->mTimer = 4;
        bomb->field174 = 3;
    }
}

void AdvanceItemBombWithMapObject(ItemBomb *bomb, ItemBomb *bombAlias, PooledMapObject *pooledMapObject) {
    PooledMapObject *mapObjectToPark;

    bombAlias->field0.mItemObject.mDistanceSquaredAndFlags |= data_02159f2c;
    sm_execute(&bomb->field184);
    if (pooledMapObject->field0.mFlags & 0x100) {
        bomb->mPooledMapObject = NULL;
        it_itemsetDestroyItem(it_sItemsets + bomb->field0.mItemObject.mKind, &bomb->field0.mItemObject);
        return;
    }
    if ((bombAlias->field0.mItemObject.mFlags & 0x8000) == 0) {
        pooledMapObject->field0.mPos = bombAlias->field0.mItemObject.mPos;
        pooledMapObject->field0.mPos.y += bomb->mMapObjectOffsetY - bombAlias->field0.mItemObject.fieldDC;
    }
    if (bomb->mTimer <= 0) {
        if ((bombAlias->field0.mItemObject.mFlags & 0x8000) == 0) {
            return;
        }
        bomb->mPooledMapObject = NULL;
        it_itemsetDestroyItem(it_sItemsets + bomb->field0.mItemObject.mKind, &bomb->field0.mItemObject);
        return;
    }
    bomb->mTimer--;
    if (bomb->mTimer < pooledMapObject->field0.mAlpha) {
        pooledMapObject->field0.mAlpha = bomb->mTimer;
    }
    if (bomb->mTimer < 0x10) {
        pooledMapObject->field0.mFlags |= data_02159f18;
    }
    if (bomb->mTimer == 0) {
        mapObjectToPark = bomb->mPooledMapObject;
        mapObjectToPark->field0.mFlags &= ~1;
        mobj_setInvisible(&mapObjectToPark->field0);
        bomb->mPooledMapObject = NULL;
        it_itemsetDestroyItem(it_sItemsets + bomb->field0.mItemObject.mKind, &bomb->field0.mItemObject);
    }
}

void AdvanceItemBomb(ItemBomb *bomb) {
    if (bomb->mPooledMapObject != NULL) {
        AdvanceItemBombWithMapObject(bomb, bomb, bomb->mPooledMapObject);
        return;
    }
    sm_execute(&bomb->field184);
    if ((bomb->field0.mItemObject.mFlags & 0x80000) || bomb->mTimer < 0) {
        sub_20F7104(&bomb->field0.mItemObject, 1);
    }
    bomb->mTimer--;
    if (bomb->field180 > 0) {
        bomb->field180--;
        if (bomb->mTimer == 0) {
            bomb->mTimer = 0x10;
        }
    }
    if (bomb->field0.mBouncesRemaining >= 3) {
        return;
    }
    if (bomb->field130 == 0 && bomb->field0.mBouncesRemaining >= 2) {
        return;
    }
    if ((bomb->field0.mItemObject.field78 & 0x8000) == 0) {
        AdvanceItemBombNearestKart(bomb);
        if (bomb->field180 == 0) {
            ClampItemBombTimerByDistance(bomb);
        }
    }
    if (bomb->mTimer >= 0xd2) {
        return;
    }
    bomb->field174--;
    if (bomb->field174 > 0) {
        return;
    }
    bomb->field174 = bomb->mTimer >> 2;
    if (bomb->field174 < 8) {
        bomb->field174 = 8;
    }
}

void *itbomb_20FDA50(void *cursor, ItemBomb *bomb, void *toData) {
    void *nextCursor;

    if (bomb != NULL && toData != NULL) {
        func_020ff1b8(bomb->field130, &bomb->field0.mItemObject.mVelocity.y);
    }
    nextCursor = CopyItemObjectData(cursor, bomb, toData);
    nextCursor = func_020fefe8(nextCursor, bomb != NULL ? &bomb->field134 : 0, toData);
    if (bomb != NULL && toData == NULL) {
        func_020ff1a0(bomb->field0.mItemObject.mVelocity.y, &bomb->field130);
    }
    if (bomb != NULL && toData != NULL) {
        return sub_20FE8AC(bomb->field0.mItemObject.mKind);
    }
    return nextCursor;
}

void itbomb_20FD9D8(ItemBomb *bomb) {
    sub_20F8E78(bomb);
    StartItemObjectBouncing(&bomb->field0, bomb->field130 != 0 ? 3 : 2);
    sm_init(&bomb->field184, (UnkFunc *const *) itbomb_sStates, 4, bomb);
    if (!(bomb->field0.mItemObject.mFlags & 0x10000000)) {
        return;
    }
    if (bomb->field130 == 0) {
        return;
    }
    sfx_21090C4(&bomb->field0.mItemObject.mSoundSource, 0xda, 0x7f, 0);
}

void itbomb_20FD938(ItemBomb *bomb, Vec3 *a, NsbmdModel *model) {
    if (bomb->mVisible == FALSE) {
        return;
    }
    if (bomb->mState != 2) {
        if (bomb->field174 != 0 && bomb->field174 < 6) {
            model->mFrameIndex = 1;
        } else {
            model->mFrameIndex = 0;
        }
        DrawItemObjectModel(&bomb->field0.mItemObject, model, a);
        return;
    }
    if (bomb->mModelEffect == NULL) {
        return;
    }
    bomb->mModelEffect->mVisible = (bomb->field0.mItemObject.mFlags & 0x10000) == 0;
}

int itbomb_20FD8B0(ItemBomb *bomb) {
    if (bomb->mState != 2) {
        sm_init(&bomb->field184, (UnkFunc *const *) itbomb_sStates, 4, bomb);
        bomb->mNextState = 2;
        bomb->mNextStateRequested = 1;
        if ((bomb->field0.mItemObject.mFlags & 0x180000) == 0) {
            bomb->field0.mItemObject.mAdvance = (void (*)(ItemObject *)) AdvanceItemBomb;
        }
        bomb->field0.mItemObject.mFlags &= ~0x8000;
        bomb->field0.mItemObject.mFlags |= 0x80000;
        bomb->field0.mItemObject.field78 &= ~0x4000;
    }
    return 1;
}

void itbomb_20FD83C(ItemBomb *bomb) {
    if (bomb->field0.mItemObject.mFlags & 0x80000) {
        return;
    }
    sm_init(&bomb->field184, (UnkFunc *const *) itbomb_sStates, 4, bomb);
    if ((bomb->field0.mItemObject.mFlags & 0x180000) == 0) {
        bomb->field0.mItemObject.mAdvance = (void (*)(ItemObject *)) AdvanceItemBomb;
    }
    bomb->mNextState = 1;
    bomb->mNextStateRequested = 1;
    bomb->field180 = 0x10e;
    bomb->field130 = 0;
    bomb->field0.mBouncesRemaining = 0;
}

// Release hook of the bomb kind: parks its map object, if it has one.
void itbomb_destroyInstance(u32 bomb) {
    u32 value0 = bomb;
    u32 flags;
    u32 compareLeft0;
    u32 zero;
    value0 = *(const u32 *) ((value0) + (408));
    compareLeft0 = value0;
    zero = 0u;
    if (compareLeft0 == zero) {
    }
    if (compareLeft0 == zero) {
    }
    if (compareLeft0 == zero) {
        return;
    }
    flags = *(const u16 *) ((value0) + (2));
    flags = (flags) & ~(1u);
    *(u16 *) ((value0) + (2)) = flags;
    mobj_setInvisible((void *) value0);
}

u32 GetItemBombActiveCount(void) {
    return it_sItemsets[9].mActiveCount;
}

#pragma thumb off

ItemBomb *func_020fd7a4(int index) {
    ItemBomb *bomb;
    u32 flags;

    bomb = (ItemBomb *) it_sItemsets[9].mObjects[index];
    flags = bomb->field0.mItemObject.mFlags;
    if ((flags & 0x8000) && (flags & 0x180000) == 0 && bomb->mState != 3 && bomb->mPooledMapObject == NULL) {
        return bomb;
    }
    return NULL;
}

void func_020fd754(void *object) {
    ItemBomb *bomb;

    bomb = object;
    bomb->field0.mItemObject.mFlags &= ~0x8000;
    if ((bomb->field0.mItemObject.mFlags & 0x180000) == 0) {
        bomb->field0.mItemObject.mAdvance = NULL;
    }
    FreeItemObjectCollisionSlot((s32) bomb);
    bomb->mVisible = FALSE;
    sm_gotoState(&bomb->field184, 3);
    bomb->field174 = 0;
}

void func_020fd684(void *object, Vec3 *d, Vec3 *f) {
    ItemBomb *bomb;
    Vec3 *a;
    Vec3 *b;
    PooledMapObject *pooledMapObject;

    bomb = object;
    a = d;
    b = f;
    if (bomb->mPooledMapObject == NULL) {
        bomb->mVisible = TRUE;
        light_setToKclColor(&bomb->field0.mItemObject.mColorBlend, 1);
    }
    if (a != NULL) {
        bomb->field0.mItemObject.mNormal = *a;
        bomb->field0.mItemObject.mFlags |= 0x80;
    }
    if (b == NULL) {
        return;
    }
    bomb->field0.mItemObject.mPos = *b;
    VEC_Subtract(&bomb->field0.mItemObject.mPos, &bomb->field0.mItemObject.mPrevPos,
                 &bomb->field0.mItemObject.mVelocity);
    if (bomb->mPooledMapObject == NULL) {
        return;
    }
    bomb->mPooledMapObject->field0.mPos = *b;
    bomb->mPooledMapObject->field0.mPos.y += bomb->mMapObjectOffsetY;
    pooledMapObject = bomb->mPooledMapObject;
    pooledMapObject->field0.mFlags &= ~2;
    pooledMapObject->field0.mFlags &= ~8;
    pooledMapObject->field0.mAlpha = 0x1f;
}

void func_020fd540(void **bombSlot, Vec3 *v, s32 timerStart) {
    ItemBomb *bomb;
    PooledMapObject *pooledMapObject;

    bomb = *bombSlot;
    pooledMapObject = bomb->mPooledMapObject;
    bomb->field0.mItemObject.field78 |= data_02159f28;
    if (pooledMapObject == NULL) {
        CreateItemObjectCollisionSlot(bomb);
        bomb->mVisible = TRUE;
    }
    sub_20F9114(bomb);
    sm_init(&bomb->field184, (UnkFunc *const *) itbomb_sStates, 4, bomb);
    sm_gotoState(&bomb->field184, 0);
    bomb->mTimer = 0x12c;
    bomb->field174 = 0;
    bomb->mNearestKartIndex = 8;
    bomb->mNearestKartDistanceSquared = 0x5f592e1;
    bomb->field180 = 0;
    bomb->field16C = FALSE;
    bomb->field134 = 0xccd;
    bomb->mTimer = timerStart;
    bomb->field130 = 1;
    InitBouncingItem(&bomb->field0, 3, v);
    if ((bomb->field0.mItemObject.mFlags & 0x180000) == 0) {
        bomb->field0.mItemObject.mAdvance = (void (*)(ItemObject *)) AdvanceItemBomb;
    }
    if (pooledMapObject != NULL) {
        pooledMapObject->field0.mFlags &= ~2;
        pooledMapObject->field0.mFlags &= ~8;
        pooledMapObject->field0.mAlpha = 0x1f;
        pooledMapObject->field0.mFlags &= ~4;
        if (pooledMapObject->field0.mKind != MAP_OBJECT_KIND_KURIBO) {
            pooledMapObject->field0.mFlags &= ~1;
        }
    }
    *bombSlot = NULL;
}

BOOL IsItemBombState2(ItemObject *object) {
    ItemBomb *bomb;

    bomb = (ItemBomb *) object;
    return bomb->mState == 2;
}

void ReleaseItemBomb(void **bombSlot) {
    ItemBomb *bomb;
    PooledMapObject *pooledMapObject;

    bomb = *bombSlot;
    sm_gotoState(&bomb->field184, 0);
    pooledMapObject = bomb->mPooledMapObject;
    if (pooledMapObject != NULL) {
        pooledMapObject->field0.mFlags &= ~1;
        mobj_setInvisible(&pooledMapObject->field0);
        bomb->mPooledMapObject = NULL;
        it_itemsetDestroyItem(it_sItemsets + bomb->field0.mItemObject.mKind, &bomb->field0.mItemObject);
    } else {
        it_itemsetDestroyItem(it_sItemsets + bomb->field0.mItemObject.mKind, &bomb->field0.mItemObject);
    }
    *bombSlot = NULL;
}

void *itbomb_20FD428(void) {
    ItemBomb *bomb;

    bomb = it_spawnItem(9, 8, data_02159f40, data_02159f40);
    if (bomb == NULL) {
        return NULL;
    }
    if ((bomb->field0.mItemObject.mFlags & 0x180000) == 0) {
        bomb->field0.mItemObject.mAdvance = NULL;
    }
    FreeItemObjectCollisionSlot((s32) bomb);
    bomb->mVisible = FALSE;
    sm_gotoState(&bomb->field184, 3);
    bomb->field174 = 0;
    return bomb;
}

void *itbomb_20FD338(void *mapObject, s32 offsetY) {
    ItemBomb *bomb;
    PooledMapObject *pooledMapObject;

    pooledMapObject = mapObject;
    bomb = it_spawnItem(9, 8, data_02159f40, data_02159f40);
    if (bomb == NULL) {
        bomb = NULL;
    } else {
        if ((bomb->field0.mItemObject.mFlags & 0x180000) == 0) {
            bomb->field0.mItemObject.mAdvance = NULL;
        }
        FreeItemObjectCollisionSlot((s32) bomb);
        bomb->mVisible = FALSE;
        sm_gotoState(&bomb->field184, 3);
        bomb->field174 = 0;
    }
    if (bomb == NULL) {
        return NULL;
    }
    mobj_setVisible(&pooledMapObject->field0);
    pooledMapObject->field0.mFlags |= data_02159f18;
    pooledMapObject->field0.mFlags |= data_02159f1c;
    pooledMapObject->field0.mFlags |= data_02159f20;
    pooledMapObject->field0.mFlags |= data_02159f24;
    bomb->mPooledMapObject = pooledMapObject;
    bomb->mMapObjectOffsetY = offsetY;
    return bomb;
}

Vec3 *sub_20FD308(ItemBomb *bomb, s32 *stateFrames, s32 *scaledScaleZ) {
    *stateFrames = bomb->mStateFrames;
    *scaledScaleZ = ((s64) bomb->field0.mItemObject.mScale.z * data_0217bd48) >> 12;
    return &bomb->field0.mItemObject.mPos;
}

#pragma thumb on

void itbomb_load(void) {
    s32 engineIndex;

    data_0217bd50 = 0x18006;
    data_0217bd48 = FX_Div(0x1000, 0x18006);
    data_0217bd54 = 0x2148;
    data_0217bd58 = ((s64) data_0217bd50 * it_sItemParams[9].field6C) >> 12;
    data_0217bd58 >>= 12;
    data_0217bd58 *= data_0217bd58;
    engineIndex = gRaceMultiConfig->mEngineIndex;
    switch (engineIndex) {
        case 0:
            data_0217bd4c = 0xb4;
            break;
        case 1:
            data_0217bd4c = 0x96;
            break;
        default:
            data_0217bd4c = 0x78;
            break;
    }
}

#pragma thumb off
