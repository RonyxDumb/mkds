#include "Main/Unknown/code_020f49bc.h"

#include "Main/System/Heap.h"
#include "Main/Unknown/code_0208ab98.h"
#include "Main/Unknown/code_020f73fc.h"
#include "Main/Unknown/code_02109054.h"
#include "Main/Unknown/unk_02159000.h"
#include "Main/Unknown/unk_021759c0.h"
#include "Main/Unknown/code_0208a000.h"
#include "Main/Unknown/code_020f7000.h"
#include "Main/Unknown/code_020f9000.h"
#include "Main/Unknown/code_020364e0.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_0206bcb0.h"
#include "Main/Item/ItemInUse.h"
#include "Main/Unknown/code_020ee684.h"
#include "Main/Unknown/code_020f2dac.h"
#include "Main/Unknown/code_020f36d8.h"
#include "Main/Unknown/code_02104a0c.h"
#include "Main/Unknown/code_020f4000.h"
#include "Main/Unknown/code_020f6000.h"
#include "Main/Unknown/code_020f9c40.h"
#include "Main/Unknown/code_020fa000.h"
#include "Main/Unknown/code_02109000.h"
#include "code_02147cd8.h"
#include "Main/Unknown/code_02068eac.h"
#include "Main/Unknown/code_020fe4b4.h"
#include "Main/Unknown/code_0210a598.h"
#include "Main/Unknown/code_0210a67c.h"
#include "Main/Unknown/unk_0216c000.h"
#include "Main/Unknown/code_02069000.h"
#include "Main/Unknown/code_020ff000.h"
#include "Main/Unknown/code_0210a000.h"
#include "Main/Unknown/code_020f1d70.h"
#include "Main/Unknown/code_020f1104.h"
#include "Main/Unknown/code_020f1258.h"
#include "Main/Unknown/code_020f1a14.h"
#include "Main/Unknown/code_020f2d98.h"
#include "Main/Unknown/code_0210b850.h"
#include "Main/Unknown/code_02046be8.h"
#include "Main/Unknown/code_020ec8bc.h"
#include "Main/Unknown/code_020fe000.h"
#include "Main/Unknown/code_020f8000.h"
#include "Main/Unknown/code_0203c000.h"
#include "Main/Unknown/code_020467d0.h"
#include "Main/Unknown/code_020f5978.h"
#include "Main/Unknown/code_020f11f0.h"
#include "Main/Unknown/code_020f1180.h"
#include "Main/Unknown/code_020f5b74.h"
#include "Main/Unknown/code_020f5b84.h"
#include "Main/Unknown/code_020f5cc4.h"
#include "Main/Unknown/code_020f5d00.h"
#include "Main/Unknown/code_020f5d5c.h"
#include "Main/Unknown/code_020d3c94.h"
#include "Main/Unknown/code_020d50ec.h"
#include "Main/Unknown/code_020d3000.h"
#include "Main/Unknown/code_020d5000.h"
#include "ITCM/code_01ffd000.h"
#include "Main/Unknown/code_02039860.h"
#include "Main/Unknown/code_02061654.h"
#include "Main/Unknown/code_02108ea0.h"
#include "Main/Unknown/code_0210b000.h"
#include "Main/Unknown/code_0210e000.h"
#include "Main/Unknown/code_020e01f0.h"
#include "Main/Unknown/code_020f1000.h"
#include "Main/Unknown/code_020f82c4.h"
#include "Main/Unknown/code_020f92e8.h"
#include "Main/Unknown/unk_0217c000.h"
#include "Main/Unknown/unk_0217d000.h"
#include "code_0212bcac.h"
#include "code_0212df7c.h"
#include "Main/Unknown/code_0203c8dc.h"
#include "Main/Unknown/code_02077bc0.h"

// The object has landed: it stops and is held at its rest point.
void StartRestingItemObject(ItemObject *item, void *b) {
    s32 fallSpeed;
    enum { K0 } kind;
    s32 k;

    VEC_MultAdd(-item->fieldDC, &item->mNormal, &item->mPos, &item->field108);
    func_020d5aa0(b, item->mCollisionBits, item->field104, &item->field108, &item->mNormal);
    if (item->field104->field0 != NULL && func_020e0448((Unk020e0448 *) item->field104) != 0) {
        item->field11A = 0xe10;
    } else {
        item->field11A = 0;
    }
    item->mFlags |= 0x8000;
    kind = *(vs32 *) &item->mKind;
    if (it_sItemParams[kind].field44 == 0) {
        if (!(item->mFlags & 0x180000)) {
            item->mAdvance = AdvanceRestingItemObject;
        }
    }
    item->mBounce = func_020f6830;
    kind = item->mKind;
    k = it_sItemParams[kind].field7C;
    fallSpeed = item->mVelocity.y;
    if (fallSpeed <= 0) {
        fallSpeed = -fallSpeed;
    }
    item->field100 = -(s32) (((s64) fallSpeed * k) >> 12);
    if (item->field100 < -0x5c3) {
        item->field100 = -0x5c3;
    }
    item->mVelocity.x = 0;
    item->mVelocity.y = 0;
    item->mVelocity.z = 0;
    func_020f90dc(item);
    func_020f0e2c(&it_sItemsets[*(vs32 *) &item->mKind], item);
    kind = *(vs32 *) &item->mKind;
    it_20F91FC(item, it_sItemParams[kind].field9C);
}

void AdvanceRestingItemObject(ItemObject *item) {
    u32 w;

    if (item->field104->field0 != NULL) {
        if (func_020e04b0(item->field104, &item->field108, &item->mNormal) != FALSE) {
            StartFallingItemObject(item);
        }
        if (item->field104->field0->field130 != FALSE) {
            if (item->mNormal.y < 0xff4) {
                item->mFlags |= 0x80;
            }
        }
        VEC_MultAdd(item->fieldDC, &item->mNormal, &item->field108, &item->mPos);
        if (item->field11A > 0) {
            item->field11A -= 1;
            if ((item->field48 & 7) != race_getFrameCounterModulo8()) {
                return;
            }
            if (col_collide(&item->mPos.x, NULL, 0, item->fieldDC, 0x44, item->mCollisionSlotIndex, NULL, NULL, NULL,
                              &item->mCollisionBits, NULL, NULL, NULL, &w) == 0) {
                return;
            }
            if (func_020d5a68(&w, item->mCollisionBits, item->field104) != FALSE) {
                item->mVelocity.x = 0;
                item->mVelocity.y = 0;
                item->mVelocity.z = 0;
                func_020f6fc4(item, 1);
            }
            if (!(item->mCollisionBits & 0x8000)) {
                return;
            }
            func_020f7070(item, 1);
        } else {
            VEC_Subtract(&item->mPos, &item->mPrevPos, &item->mVelocity);
        }
    } else {
        if (!(item->mFlags & 0x40)) {
            return;
        }
        VEC_MultAdd(item->fieldDC, &item->mNormal, &item->field108, &item->mPos);
    }
}

void func_020f6830(ItemObject *item, Vec3 *otherVelocity, Vec3 *normal) {
    s32 scaleDifference;
    s32 dot;
    u32 kind;

    scaleDifference = item->mScale.z - item->mScale.y;
    if (scaleDifference * scaleDifference >= 0x68be1) {
        return;
    }
    dot = vec_dotProduct(otherVelocity, normal);
    if (dot <= 0) {
        dot = -dot;
    }
    kind = *(vs32 *) &item->mKind;
    item->field100 = ((s64) dot * it_sItemParams[kind].field7C) >> 12;
    item->field100 = item->field100 >> 1;
}

void it_startThrowAnim(ItemObject *itemParam, s32 pushStrength, Vec3 *fromPos, Vec3 *fromVelocity, Vec3 *normal) {
    ItemObject *item;
    Vec3 away;
    Vec3 *velocity;
    s32 startsFalling;
    s32 dot;
    u32 kind;

    item = itemParam;
    velocity = &item->mVelocity;
    kind = *(vs32 *) &item->mKind;
    startsFalling = it_sItemParams[kind].field80;
    if (gRaceMultiConfig->mMode == MODE_TIME_ATTACK || (item->mFlags & 0x8000000)) {
        startsFalling = 0;
    }
    item->mFlags |= 0x4000;
    item->field78 |= data_02159b64;
    dot = VEC_DotProduct(normal, velocity);
    velocity->x -= (s32) (((s64) normal->x * dot) >> 12);
    velocity->y -= (s32) (((s64) normal->y * dot) >> 12);
    velocity->z -= (s32) (((s64) normal->z * dot) >> 12);
    dot = vec_dotProduct(fromVelocity, normal);
    if (dot < 0) {
        dot = 0;
    } else if (dot > 0x1333) {
        dot = 0x1333;
    }
    VEC_MultAdd(dot + (startsFalling != 0 ? 0x2800 : 0x3800), normal, velocity, velocity);
    if (pushStrength != 0) {
        VEC_Subtract(&item->mPos, fromPos, &away);
        if ((s64) away.x * away.x + (s64) away.y * away.y + (s64) away.z * away.z >= 0x10) {
            vec_normalize(&away, &away);
        }
        VEC_MultAdd(pushStrength * 0x14cd, &away, velocity, velocity);
    }
    if (startsFalling != 0) {
        if (!(item->mFlags & 0x180000)) {
            item->mAdvance = AdvanceFallingItemObject;
        }
        item->mBounce = func_020f6388;
        item->mFlags &= ~0x7000000;
    } else {
        item->mFlags &= ~0x4000;
        func_020f7070(item, 1);
    }
}

void StartFallingItemObject(ItemObject *item) {
    u32 kind;

    item->mFlags &= ~0x8000;
    item->mFlags |= 0x4000;
    kind = *(vs32 *) &item->mKind;
    if (it_sItemParams[kind].field44 == 0) {
        if (!(item->mFlags & 0x180000)) {
            item->mAdvance = AdvanceFallingItemObject;
        }
    }
    item->mBounce = func_020f6388;
    item->mFlags &= ~0x7000000;
}

void AdvanceFallingItemObject(ItemObject *item) {
    u32 w;
    Vec3 pushOut;
    Vec3 groundNormal;
    Vec3 bounceNormal;
    Vec3 *pos;
    Vec3 *velocity;

    pos = &item->mPos;
    velocity = &item->mVelocity;

    VEC_Add(velocity, pos, pos);
    item->mVelocity.x = ((s64) item->mVelocity.x * 0xfec) >> 12;
    velocity->z = ((s64) velocity->z * 0xfec) >> 12;
    if (col_collide(pos, &item->mPrevPos, 0, item->fieldDC, 0x44, item->mCollisionSlotIndex, &pushOut, &groundNormal,
                      (s32 *) &bounceNormal, &item->mCollisionBits, NULL, NULL, NULL, &w) != 0) {
        VEC_Add(&pushOut, pos, pos);
        if (item->mCollisionBits & 0x1e34ef) {
            func_020f9334(item, pos, velocity, 0x385, &groundNormal);
        }
        if (item->mCollisionBits & 0x214300) {
            item->mFlags |= 0x20;
            BounceItemVelocityOffSurface(velocity, &bounceNormal);
            if (func_020f9290(item, &bounceNormal) != FALSE) {
                return;
            }
        }
        if (item->mCollisionBits & 0x8000) {
            func_020f7070(item, 1);
            return;
        }
    }
    item->mFlags &= ~0x4000000;
    if (!(item->mCollisionBits & 0x1e34ef)) {
        velocity->y -= 0x385;
        if (velocity->y < -0xa000) {
            velocity->y = -0xa000;
        }
    }
    if (!(item->mFlags & 8)) {
        return;
    }
    if (item->mFlags & 3) {
        return;
    }
    StartRestingItemObject(item, &w);
}

void func_020f6388(ItemObject *item, Vec3 *otherVelocity, Vec3 *normal) {
    BounceItemVelocityOffSurface(&item->mVelocity, normal);
    if (item->mFlags & 0x1000000) {
        return;
    }
    item->mFlags |= 0x1000000;
    item->field108.x = 0;
    item->field108.y = 0;
    item->field108.z = 0;
}

void itthun_activate(ItemInUse *itemInUse, HeldItem *heldItem) {
    NNSSndSeqPlayer **seqPlayer;

    if (data_0217c780 & 1) {
        seqPlayer = sp_acquireElement(sound_getPoolById(0));
        if (SoundHandle_217D084.fieldC != 0) {
            if (*seqPlayer != NULL) {
                NNS_SndPlayerStopSeq(seqPlayer, 0);
            }
            if (*seqPlayer != NULL) {
                NNS_SndPlayerStopSeq(seqPlayer, 0);
            }
            NNS_SndArcPlayerStartSeqArc(seqPlayer, 0, 0xde);
        }
    }
    driver_invokeThunder(heldItem->mKartItems->mKart);
    mobj_executeAllThunderLogic();
    func_020f82e8(0);
    it_takeSlotItems(heldItem, 1);
    if (gRaceMultiConfig->mMode != 5) {
        return;
    }
    func_020fe958(6);
}

void itstar_activate(ItemInUse *itemInUse, HeldItem *heldItem) {
    driver_startStarInvincibility(heldItem->mKartItems->mKart);
    it_takeSlotItems(heldItem, 1);
    if (gRaceMultiConfig->mMode != 5) {
        return;
    }
    func_020fe958(4);
}

void StartItemKouraGSound(void *kouraParam, s32 b) {
    ItemKouraG *koura;

    koura = kouraParam;
    if (!(koura->field0.field0.mFlags & 0x400000)) {
        return;
    }
    AdvanceSoundDistanceSquaredChange(&koura->field16C,
                                      koura->field0.field0.mDistanceSquaredAndFlags & ~0xc000001f);
    StartSoundWhileRequested(&koura->field0.field0.mSoundSource, 0xd7, 0x7f, 0);
}

BOOL itkrag_20F6150(ItemInUse *itemInUse, ItemKouraG *koura) {
    BOOL isBattle;

    isBattle = gRaceMultiConfig->mMode == MODE_BATTLE;
    func_020f9114(koura);
    sfx_210B850(&koura->field16C);
    koura->field0.field0.mSoundSource.mTrackParamsFunction = (void (*)(void *, void *, void *)) func_0210a77c;
    if (itemInUse->mKartItems->mFlags & 0x20) {
        InitItemObjectThrow(koura, itemInUse, isBattle != FALSE ? 2 : 4, 0, 0, 0x5000);
        return FALSE;
    }
    InitItemObjectThrow(koura, itemInUse, isBattle != FALSE ? 5 : 9, 1, 0, 0x5000);
    return TRUE;
}

void itkrag_GreenShellRender(ItemKouraG *koura) {
    if (koura->field0.field0.mAgeFrames > 0x258) {
        koura->field0.mHitsRemaining = 0;
    }
    AdvanceItemObjectMotion(&koura->field0, 0x84cd);
    if (koura->field0.field0.mFlags & 1) {
        return;
    }
    AddSoundRequest(&data_0217d294, (koura->field0.field0.mDistanceSquaredAndFlags & ~0xc000001f) + 0x9c40,
                    StartItemKouraGSound, koura, 0);
}

void *itkrag_20F6038(void *buffer, ItemKouraG *koura, void *toBuffer) {
    void *result;

    if (koura != NULL && toBuffer != NULL) {
        func_020ff1b8(vec_dotProduct(&koura->field0.field0.mVelocity, &koura->field0.mDirection) < 0,
                      &koura->field0.field0.mVelocity.y);
    }
    result = CopyItemObjectData(buffer, koura, toBuffer);
    if (koura != NULL && toBuffer == NULL) {
        func_020ff1a0(koura->field0.field0.mVelocity.y, &koura->field168);
    }
    if (koura != NULL && toBuffer != NULL) {
        return func_020fe8ac(koura->field0.field0.mKind);
    }
    return result;
}

void itkrag_20F5FFC(ItemKouraG *koura) {
    func_020f8e78(koura);
    sfx_210B850(&koura->field16C);
    koura->field0.field0.mSoundSource.mTrackParamsFunction = (void (*)(void *, void *, void *)) func_0210a77c;
    InitItemObjectMotion(koura, 9, koura->field168, 0);
}

void StartItemKouraRSound(void *kouraParam, s32 b) {
    ItemKouraR *kouraR;

    kouraR = kouraParam;
    if (!(kouraR->field0.field0.field0.mFlags & 0x400000)) {
        return;
    }
    AdvanceSoundDistanceSquaredChange(&kouraR->field258,
                                      kouraR->field0.field0.field0.mDistanceSquaredAndFlags & ~0xc000001f);
    StartSoundWhileRequested(&kouraR->field0.field0.field0.mSoundSource, 0xd8, 0x7f, 0);
}

void func_020f5f7c(ItemKouraR *kouraR, Vec3 *otherVelocity, Vec3 *normal) {
    func_020f29e8(kouraR);
    DeflectItemObjectOnHit(&kouraR->field0.field0, otherVelocity, normal);
    kouraR->mStateMachine.mNextState = 1;
    kouraR->mStateMachine.mNextStateRequested = 1;
}

// Called when an object is taken off the kart item list: sets up its state machine and first state.
s32 itkrar_20F5D6C(ItemInUse *itemInUse, ItemKouraR *kouraR) {
    u16 ownerKartIndex;
    u16 targetKartIndex;
    u16 rankAhead;

    func_020f9114(kouraR);
    sfx_210B850(&kouraR->field258);
    kouraR->field0.field0.field0.mSoundSource.mTrackParamsFunction =
        (void (*)(void *, void *, void *)) func_0210a77c;
    sm_init(&kouraR->mStateMachine, (UnkFunc *const *) gItemKouraRStateTable, 7, kouraR);
    if (itemInUse->mKartItems->mFlags & 0x20) {
        kouraR->mThrowForward = 0;
        InitItemObjectThrow(kouraR, itemInUse, 0, 0, 0, 0x5000);
        kouraR->mStateMachine.mNextState = 1;
        kouraR->mStateMachine.mNextStateRequested = 1;
        kouraR->field0.mPreviousLink.mLink = NULL;
        kouraR->field0.mPreviousLink.mNextLinksUsed = 1;
    } else {
        kouraR->mThrowForward = 1;
        if (gRaceMultiConfig->mMode != MODE_BATTLE && itemInUse->mKartItems->field1F0.mLink != NULL) {
            ownerKartIndex = !(kouraR->field0.field0.field0.field78 & 0x8000)
                                 ? (u16) (kouraR->field0.field0.field0.field78 & ~0xff00)
                                 : 8;
            if (ownerKartIndex >= 8) {
                targetKartIndex = 8;
            } else {
                rankAhead = rstat_getPlace(ownerKartIndex) - 1;
                if (rankAhead < 1) {
                    rankAhead = gRaceMultiConfig->mKartCount;
                }
                targetKartIndex = gRaceStatus->mKartAtRank[(u8) rankAhead - 1];
            }
            InitLinkFollowingItemFromInUse(&kouraR->field0, itemInUse, 0x2d, 0x5b, 1, 0, 1, 0x5000, targetKartIndex,
                                           0);
            kouraR->mStateMachine.mNextState = 3;
            kouraR->mStateMachine.mNextStateRequested = 1;
        } else {
            InitItemObjectThrow(kouraR, itemInUse, 0, 1, 0, 0x5000);
            kouraR->mStateMachine.mNextState = 2;
            kouraR->mStateMachine.mNextStateRequested = 1;
            kouraR->field0.mPreviousLink.mLink = NULL;
            kouraR->field0.mPreviousLink.mNextLinksUsed = 1;
        }
        kouraR->field0.field0.field0.mFlags |= 0x200000;
    }
    ResetItemKouraRKartItems(kouraR);
    if (kouraR->field0.field0.field0.mFlags & 0x8000000) {
        kouraR->mStateMachine.mNextState = 0;
        kouraR->mStateMachine.mNextStateRequested = 1;
    }
    return kouraR->mThrowForward;
}

void itkrar_20F5D5C(u32 kouraR) {
    u32 value0 = kouraR;
    u32 value12;
    value0 = (value0) + (0x23cu);
    sm_execute((void *) value0);
}

void UpdateItemKouraRState0And1(ItemKouraR *kouraR) {
    AdvanceItemObjectMotion(&kouraR->field0.field0, 0x8800);
    if (kouraR->field0.field0.field0.mFlags & 1) {
        return;
    }
    AddSoundRequest(&data_0217d294, kouraR->field0.field0.field0.mDistanceSquaredAndFlags & ~0xc000001f,
                    StartItemKouraRSound, kouraR, 0);
}

void func_020f5cc4(ItemObject *item, u32 kartIndex) {
    u32 value0 = (u32) item;
    u32 value1 = kartIndex;
    u32 minusOne;
    u32 collisionSlotIndex;
    u32 itemAddress;
    u32 collisionSlotCompared;
    u32 minusOneCompared;
    itemAddress = value0;
    collisionSlotIndex = *(const s16 *) ((itemAddress) + (218));
    minusOne = ~(0u);
    collisionSlotCompared = collisionSlotIndex;
    minusOneCompared = minusOne;
    if (collisionSlotCompared == minusOneCompared) {
    }
    if (collisionSlotCompared == minusOneCompared) {
        return;
    }
    func_020f1150(value0, value1);
    value0 = (itemAddress) + (0x200u);
    value1 = 4u;
    *(u16 *) ((value0) + (76)) = value1;
    value1 = 1u;
    *(u16 *) ((value0) + (78)) = value1;
}

void UpdateItemKouraRState2(ItemKouraR *kouraR) {
    AdvanceItemObjectMotion(&kouraR->field0.field0, 0x8800);
    if (!(kouraR->field0.field0.field0.mFlags & 1)) {
        AddSoundRequest(&data_0217d294, kouraR->field0.field0.field0.mDistanceSquaredAndFlags & ~0xc000001f,
                        StartItemKouraRSound, kouraR, 0);
    }
    if (kouraR->field0.field0.field0.mFlags & 1) {
        return;
    }
    if (kouraR->mStateMachine.mStateFrames > 0x10) {
        if (TrySetItemKouraRKartItemsByFrame(kouraR, 0) == 0) {
            return;
        }
        kouraR->mStateMachine.mNextState = 4;
        kouraR->mStateMachine.mNextStateRequested = 1;
        if (!(kouraR->field0.field0.field0.mFlags & 0x8000000)) {
            return;
        }
        func_020fe71c(1, kouraR->mKartItems->mKartIndex, kouraR->field0.field0.field0.mId);
        return;
    }
    if (kouraR->mStateMachine.mStateFrames > 4) {
        if (TrySetItemKouraRNearestKartItems(kouraR, 0) == FALSE) {
            return;
        }
        kouraR->mStateMachine.mNextState = 4;
        kouraR->mStateMachine.mNextStateRequested = 1;
        if (!(kouraR->field0.field0.field0.mFlags & 0x8000000)) {
            return;
        }
        func_020fe71c(1, kouraR->mKartItems->mKartIndex, kouraR->field0.field0.field0.mId);
    }
}

void EnterItemKouraRState3(ItemKouraR *kouraR) {
    kouraR->field0.field0.field0.mBounce = (void (*)(ItemObject *, Vec3 *, Vec3 *)) func_020f5f7c;
}

void UpdateItemKouraRState3(ItemKouraR *kouraR) {
    u16 ownerKartIndex;
    u16 targetKartIndex;
    u16 rankAhead;

    ownerKartIndex = !(kouraR->field0.field0.field0.field78 & 0x8000)
                         ? (u16) (kouraR->field0.field0.field0.field78 & ~0xff00)
                         : 8;
    if (ownerKartIndex >= 8) {
        targetKartIndex = 8;
    } else {
        rankAhead = rstat_getPlace(ownerKartIndex) - 1;
        if (rankAhead < 1) {
            rankAhead = gRaceMultiConfig->mKartCount;
        }
        targetKartIndex = gRaceStatus->mKartAtRank[(u8) rankAhead - 1];
    }
    AdvanceLinkFollowingItem(&kouraR->field0, 0xd000, 0x29, targetKartIndex, 0);
    if (!(kouraR->field0.field0.field0.mFlags & 1)) {
        AddSoundRequest(&data_0217d294, kouraR->field0.field0.field0.mDistanceSquaredAndFlags & ~0xc000001f,
                        StartItemKouraRSound, kouraR, 0);
    }
    if (kouraR->field0.field0.field0.mFlags & 1) {
        return;
    }
    if (kouraR->mStateMachine.mStateFrames > 0x708) {
        func_020f29e8(kouraR);
        kouraR->mStateMachine.mNextState = 1;
        kouraR->mStateMachine.mNextStateRequested = 1;
        return;
    }
    if (kouraR->mStateMachine.mStateFrames > 0x10) {
        if (TrySetItemKouraRKartItemsByFrame(kouraR, 1) == 0) {
            return;
        }
        kouraR->mStateMachine.mNextState = 4;
        kouraR->mStateMachine.mNextStateRequested = 1;
        if (!(kouraR->field0.field0.field0.mFlags & 0x8000000)) {
            return;
        }
        func_020fe71c(1, kouraR->mKartItems->mKartIndex, kouraR->field0.field0.field0.mId);
        return;
    }
    if (kouraR->mStateMachine.mStateFrames > 4) {
        if (TrySetItemKouraRNearestKartItems(kouraR, 1) == FALSE) {
            return;
        }
        kouraR->mStateMachine.mNextState = 4;
        kouraR->mStateMachine.mNextStateRequested = 1;
        if (!(kouraR->field0.field0.field0.mFlags & 0x8000000)) {
            return;
        }
        func_020fe71c(1, kouraR->mKartItems->mKartIndex, kouraR->field0.field0.field0.mId);
    }
}

void EnterItemKouraRState4(ItemKouraR *kouraR) {
    kouraR->field0.field0.field0.mBounce = (void (*)(ItemObject *, Vec3 *, Vec3 *)) func_020f5f7c;
}

// Runs the two 0x7c/0x4c checks of the object in the 0x1fc word of the 0x1c pointer, then
// one of the four func_020f14a0 calls, and stores the 0x24c/0x24e halfwords it picks.
void UpdateItemKouraRState4(ItemKouraR *kouraR) {
    KartItems *kartItems;
    Kart *kart;
    BOOL d;
    u32 kartBits;
    s32 n;

    kartItems = kouraR->mKartItems;
    kart = kartItems->mKart;
    kartBits = *(u32 *) &kart->field7C;
    d = TRUE;
    if ((kartBits & 0x402020) == 0) {
        if ((kart->field4C & 0x800) == 0) {
            d = FALSE;
        }
    }
    if (d != FALSE) {
        func_020f1104(kouraR);
        kouraR->mStateMachine.mNextState = 6;
        kouraR->mStateMachine.mNextStateRequested = 1;
    } else {
        n = kouraR->field0.field0.field0.mFlags;
        if (n & 0x10000000) {
            if (kartBits & 1) {
                n = func_020f14a0(kouraR, 0x5333, 0x19a, 1);
            } else {
                n = func_020f14a0(kouraR, 0x4b33, 0x19a, 0);
            }
        } else {
            n = func_020f14a0(kouraR, 0x4800, 0x19a, (n & 0x8000000) == 0);
        }
        if (n != 0) {
            func_020f1104(kouraR);
            kouraR->mStateMachine.mNextState = 2;
            kouraR->mStateMachine.mNextStateRequested = 1;
            kouraR->field0.mPreviousLink.mLink = NULL;
            kouraR->field0.mPreviousLink.mNextLinksUsed = 1;
        }
    }
    if (kouraR->field0.field0.field0.mFlags & 1) {
        return;
    }
    AddSoundRequest(&data_0217d294, kouraR->field0.field0.field0.mDistanceSquaredAndFlags & ~0xc000001f,
                    StartItemKouraRSound, kouraR, 0);
}

// Checks func_0206c0e0 of the 0x1fc object, then the 0x240 counter and the sum of the two
// squares of the 0x50/0x54/0x58 differences against the 0x1d0/0x1d4/0x1e0 square.
void UpdateItemKouraRState5(ItemKouraR *kouraR) {
    KartItems *kartItems;
    Kart *kart;
    s32 deltaZ;
    s32 hitRadius;
    s32 deltaX;

    kartItems = kouraR->mKartItems;
    kart = kartItems->mKart;
    if (func_0206c0e0(kart) != FALSE) {
        func_020f6f10(&kouraR->field0.field0.field0, 0, 8);
    } else {
        func_020f14a0(kouraR, 0x10000, 0x333, 0);
    }
    if ((kouraR->field0.field0.field0.mFlags & 1) == 0) {
        AddSoundRequest(&data_0217d294, kouraR->field0.field0.field0.mDistanceSquaredAndFlags & ~0xc000001f,
                        StartItemKouraRSound, kouraR, 0);
    }
    if (kouraR->mStateMachine.mStateFrames <= 0x14) {
        hitRadius = kart->mRadius + ((kouraR->field0.field0.field0.mRadius * 3) >> 1);
        deltaZ = kouraR->field0.field0.field0.mPos.z - kart->mPointAlongUp.z;
        deltaX = kouraR->field0.field0.field0.mPos.x - kart->mPointAlongUp.x;
        if ((s64) deltaX * deltaX + (s64) deltaZ * deltaZ >= (s64) hitRadius * hitRadius) {
            return;
        }
    }
    func_020f6f10(&kouraR->field0.field0.field0, 0, 8);
}

// Runs AdvanceItemObjectMotion and hands StartItemKouraRSound to AddSoundRequest when the 0x74 bit 0 is clear.
void UpdateItemKouraRState6(ItemKouraR *kouraR) {
    AdvanceItemObjectMotion(&kouraR->field0.field0, 0xc000);
    if (kouraR->field0.field0.field0.mFlags & 1) {
        return;
    }
    AddSoundRequest(&data_0217d294, kouraR->field0.field0.field0.mDistanceSquaredAndFlags & ~0xc000001f,
                    StartItemKouraRSound, kouraR, 0);
}

// Runs func_0210a598 with the 0x3bc word of the 0x1fc object when the 0x78 high bits of the
// third parameter match that object's 0x74 halfword and the 0x74/0x78/0xdc tests pass.
void func_020f5614(void *kouraParam, s32 hitType, ItemObject *otherParam) {
    ItemKouraR *kouraR;
    ItemObject *other;
    KartItems *kartItems;
    Kart *kart;
    u16 otherOwnerIndex;
    u32 otherFlags;

    kouraR = kouraParam;
    other = otherParam;
    if ((u32) (hitType - 1) > 1) {
        return;
    }
    kartItems = kouraR->mKartItems;
    otherOwnerIndex = !(other->field78 & 0x8000) ? (u16) (other->field78 & ~0xff00) : 8;
    if (kartItems == NULL) {
        return;
    }
    kart = kartItems->mKart;
    if (otherOwnerIndex != *(u16 *) &kart->mIndex) {
        return;
    }
    otherFlags = other->mFlags;
    if ((otherFlags & 0x1000) == 0) {
        if ((otherFlags & 0x2000) == 0) {
            return;
        }
        if ((other->field78 & 0x1000) == 0) {
            return;
        }
        if (other->mAgeFrames >= 0x78) {
            return;
        }
    }
    func_0210a598(kart, kart->mSoundIndex);
}

// Hands the 0x44 word and the 0x5c/0x130/0x250/0x254/0x60/0x54 addresses of b to
// CopyItemObjectData, CopyItemPointLinkIndex, func_020ff1b8, func_020ff1a0 and func_020fe8ac.
void *itkrar_20F5550(void *buffer, ItemKouraR *kouraR, void *toBuffer) {
    s32 dot;
    void *result;

    if (kouraR != NULL && toBuffer != NULL) {
        dot = vec_dotProduct(&kouraR->field0.field0.field0.mVelocity, &kouraR->field0.field0.mDirection);
        func_020ff1b8(dot < 0, &kouraR->field0.field0.field0.mVelocity.y);
        func_020ff1b8(kouraR->mThrowForward, &kouraR->field0.field0.field0.mPos.y);
    }
    result = CopyItemObjectData(buffer, kouraR, toBuffer);
    result = CopyItemPointLinkIndex(result, kouraR != NULL ? &kouraR->field0.mPreviousLink : 0, toBuffer);
    if (kouraR != NULL && toBuffer == NULL) {
        func_020ff1a0(kouraR->field0.field0.field0.mVelocity.y, &kouraR->field250);
        func_020ff1a0(kouraR->field0.field0.field0.mPos.y, &kouraR->mThrowForward);
    }
    if (kouraR != NULL && toBuffer != NULL) {
        return func_020fe8ac(kouraR->field0.field0.field0.mKind);
    }
    return result;
}

// Stores func_0210a77c in the 0x30 word, moves the seven words of gItemKouraRStateTable to 0x23c,
// then picks one of three calls from the 0x254/0x21c words.
void itkrar_20F53D0(ItemKouraR *kouraR) {
    u16 ownerKartIndex;
    u32 rank;
    u16 targetKartIndex;
    u16 rankAhead;

    func_020f8e78(kouraR);
    sfx_210B850(&kouraR->field258);
    kouraR->field0.field0.field0.mSoundSource.mTrackParamsFunction =
        (void (*)(void *, void *, void *)) func_0210a77c;
    sm_init(&kouraR->mStateMachine, (UnkFunc *const *) gItemKouraRStateTable, 7, kouraR);
    if (kouraR->mThrowForward != 0) {
        if (kouraR->field0.mPreviousLink.mLink != NULL) {
            kouraR->mStateMachine.mNextState = 3;
            kouraR->mStateMachine.mNextStateRequested = 1;
            ownerKartIndex = !(kouraR->field0.field0.field0.field78 & 0x8000)
                                 ? (u16) (kouraR->field0.field0.field0.field78 & ~0xff00)
                                 : 8;
            if (ownerKartIndex >= 8) {
                targetKartIndex = 8;
            } else {
                rank = rstat_getPlace(ownerKartIndex);
                rankAhead = rank - 1;
                if (rankAhead < 1) {
                    rankAhead = gRaceMultiConfig->mKartCount;
                }
                targetKartIndex = gRaceStatus->mKartAtRank[(rankAhead & 0xff) - 1];
            }
            InitLinkFollowingItem(&kouraR->field0, 0x2d, 0x5b, 0, 1, kouraR->field250, targetKartIndex, 0);
        } else {
            kouraR->mStateMachine.mNextState = 2;
            kouraR->mStateMachine.mNextStateRequested = 1;
            InitItemObjectMotion(kouraR, 0, kouraR->field250, 0);
        }
        kouraR->field0.field0.field0.mFlags |= 0x200000;
    } else {
        kouraR->mStateMachine.mNextState = 1;
        kouraR->mStateMachine.mNextStateRequested = 1;
        InitItemObjectMotion(kouraR, 0, kouraR->field250, 0);
    }
    ResetItemKouraRKartItems(kouraR);
}

// Returns 1 while driver_getById(b) is within the 0x1d0/0x1d4 radius of the 0x50/0x54/0x58
// words, or when the 0xda halfword is -1; otherwise sets the 0x24c/0x24e halfwords, returns 0.
BOOL func_020f5324(void *kouraParam, s32 kartIndex) {
    ItemKouraR *kouraR;
    Kart *kart;
    s32 deltaZ;
    s32 hitRadius;
    s32 deltaX;

    kouraR = kouraParam;
    kart = driver_getById(kartIndex);
    hitRadius = kart->mRadius + ((kouraR->field0.field0.field0.mRadius * 3) >> 1);
    deltaZ = kouraR->field0.field0.field0.mPos.z - kart->mPointAlongUp.z;
    deltaX = kouraR->field0.field0.field0.mPos.x - kart->mPointAlongUp.x;
    if ((s64) deltaX * deltaX + (s64) deltaZ * deltaZ < (s64) hitRadius * hitRadius) {
        return TRUE;
    }
    if (kouraR->field0.field0.field0.mCollisionSlotIndex == -1) {
        return TRUE;
    }
    FreeItemObjectCollisionSlot((s32) kouraR);
    kouraR->mStateMachine.mNextState = 5;
    kouraR->mStateMachine.mNextStateRequested = 1;
    SetItemKouraRKartItems(kouraR, kartIndex);
    return FALSE;
}

// Runs func_020f9114, ors data_02159834 into the 0x78 halfword, then makes one of two
// ThrowBouncingItem calls depending on the 0x1ec halfword of the 0x0c pointer, and returns the
// 0x130 word it stores.
s32 itbana_20F5240(ItemInUse *itemInUse, ItemBanana *banana) {
    KartItems *kartItems;
    s32 n;

    func_020f9114(banana);
    banana->field0.mItemObject.field78 |= data_02159834;
    kartItems = itemInUse->mKartItems;
    if (kartItems->mFlags & KART_ITEMS_THROW_FORWARD) {
        ThrowBouncingItem(&banana->field0, itemInUse, 0, 1, 0x4000, 0x3000, 0x59a);
        sfx_21090C4(&banana->field0.mItemObject.mSoundSource, 0xda, 0x7f, 0);
        banana->mThrowForward = 1;
        return banana->mThrowForward;
    }
    ThrowBouncingItem(&banana->field0, itemInUse, 0, 0, 0x4000, 0x3000, 0x59a);
    banana->mThrowForward = 0;
    return banana->mThrowForward;
}

// Calls AdvanceBouncingItem with one of two pairs of numbers, and when the 0x74 bits allow it
// doubles the 0x60 word and runs StopSound and StartRestingItemObject.
void itbana_20F518C(ItemBanana *banana) {
    u32 v;
    u32 flags;

    if (banana->mThrowForward != 0) {
        AdvanceBouncingItem(&banana->field0, 0x1ec, 0xfec, 0, &v);
    } else {
        AdvanceBouncingItem(&banana->field0, 0x2e1, 0xf85, 0, &v);
    }
    flags = banana->field0.mItemObject.mFlags;
    if ((flags & 8) == 0) {
        return;
    }
    if (flags & 3) {
        return;
    }
    if (banana->mThrowForward != 0) {
        banana->field0.mItemObject.mVelocity.y = banana->field0.mItemObject.mVelocity.y * 2;
    }
    StopSound(&banana->field0.mItemObject.mSoundSource, 0xda);
    StartRestingItemObject(&banana->field0.mItemObject, &v);
}

// Hands the 0x130 word and the 0x60 word to func_020ff1b8/func_020ff1a0 around the
// CopyItemObjectData call, and returns func_020fe8ac's value when b and c are both set.
void *itbana_20F5108(void *buffer, ItemBanana *banana, void *toBuffer) {
    void *result;

    if (banana != NULL && toBuffer != NULL) {
        func_020ff1b8(banana->mThrowForward, &banana->field0.mItemObject.mVelocity.y);
    }
    result = CopyItemObjectData(buffer, banana, toBuffer);
    if (banana != NULL && toBuffer == NULL) {
        func_020ff1a0(banana->field0.mItemObject.mVelocity.y, &banana->mThrowForward);
    }
    if (banana != NULL && toBuffer != NULL) {
        return func_020fe8ac(banana->field0.mItemObject.mKind);
    }
    return result;
}

// Runs func_020f8e78 and StartItemObjectBouncing, then sfx_21090C4 when the two 0x74/0x130 tests pass.
void itbana_20F50B4(ItemBanana *banana) {
    func_020f8e78(banana);
    StartItemObjectBouncing(&banana->field0, 0);
    if ((banana->field0.mItemObject.mFlags & 0x10000000) == 0) {
        return;
    }
    if (banana->mThrowForward == 0) {
        return;
    }
    sfx_21090C4(&banana->field0.mItemObject.mSoundSource, 0xda, 0x7f, 0);
}

// Item hook of the mushroom: starts the kart boost, uses up one held object, marks the use,
// and makes the event call when the mode is 5.
void itkino_activate(ItemInUse *itemInUse, HeldItem *heldItem) {
    driver_startShroomBoost(heldItem->mKartItems->mKart);
    it_takeSlotItems(heldItem, 1);
    itemInUse->mKartItems->mKinokoBoostStarted = TRUE;
    if (gRaceMultiConfig->mMode != 5) {
        return;
    }
    func_020fe958(3);
}

void itkino_initInstance(ItemKinoko *kinoko) {
    kinoko->mVisible = TRUE;
}

#pragma thumb off

// Runs DrawItemObjectModel with the last two parameters swapped when the 0x134 word is set.
void itkino_20F5008(ItemKinoko *kinoko, void *b, void *c) {
    if (kinoko->mVisible == FALSE) {
        return;
    }
    DrawItemObjectModel(&kinoko->field0.mItemObject, c, b);
}

// Decreases the 0x130 word by one; when it goes below zero func_020f7658 runs first.
void AdvanceRestingItemKinoko(ItemKinoko *kinoko) {
    kinoko->mTimer--;
    if (kinoko->mTimer < 0) {
        func_020f7658(&kinoko->field0.mItemObject, 0);
    }
    AdvanceRestingItemObject(&kinoko->field0.mItemObject);
}

// Sets the object up through AdvanceBouncingItem when the 0x74 word allows it.
void AdvanceBouncingItemKinoko(ItemKinoko *kinoko) {
    u32 n;

    AdvanceBouncingItem(&kinoko->field0, 0x385, 0xff8, 0x733, &n);
    if ((kinoko->field0.mItemObject.mFlags & 8) == 0) {
        return;
    }
    if ((kinoko->field0.mItemObject.mFlags & 3) != 0) {
        return;
    }
    StopSound(&kinoko->field0.mItemObject.mSoundSource, 0xda);
    StartRestingItemObject(&kinoko->field0.mItemObject, &n);
    if ((kinoko->field0.mItemObject.mFlags & 0x180000) == 0) {
        kinoko->field0.mItemObject.mAdvance = (void (*)(ItemObject *)) AdvanceRestingItemKinoko;
    }
}

// Returns what it_spawnItem gives, with its 0x134 and 0x130 words cleared.
ItemKinoko *itkino_20F4EE8(void) {
    ItemKinoko *kinoko;

    kinoko = it_spawnItem(3, 8, &data_02159764, &data_02159764);
    if (kinoko == NULL) {
        return NULL;
    }
    if ((kinoko->field0.mItemObject.mFlags & 0x180000) == 0) {
        kinoko->field0.mItemObject.mAdvance = NULL;
    }
    FreeItemObjectCollisionSlot((s32) kinoko);
    kinoko->mVisible = FALSE;
    kinoko->mTimer = 0;
    return kinoko;
}

// Stores the two Vec3s in the object and sets the word at 0x80.
void func_020f4e78(ItemKinoko *kinoko, Vec3 *normal, Vec3 *pos) {
    kinoko->mVisible = TRUE;
    light_setToKclColor(&kinoko->field0.mItemObject.mColorBlend, 1);
    if (normal != NULL) {
        kinoko->field0.mItemObject.mNormal = *normal;
        kinoko->field0.mItemObject.mFlags |= 0x80;
    }
    if (pos == NULL) {
        return;
    }
    kinoko->field0.mItemObject.mPos = *pos;
    VEC_Subtract(&kinoko->field0.mItemObject.mPos, &kinoko->field0.mItemObject.mPrevPos,
                 &kinoko->field0.mItemObject.mVelocity);
}

// Runs the object's first word and stores the 0x120 and 0x130 words.
void StartBouncingItemKinoko(void **kinokoSlot, Vec3 *b, s32 timer) {
    ItemKinoko *kinoko;

    kinoko = kinokoSlot[0];
    kinoko->field0.mItemObject.field78 |= data_0215969c;
    CreateItemObjectCollisionSlot(kinoko);
    func_020f9114(kinoko);
    InitBouncingItem(&kinoko->field0, 0, b);
    if ((kinoko->field0.mItemObject.mFlags & 0x180000) == 0) {
        kinoko->field0.mItemObject.mAdvance = (void (*)(ItemObject *)) AdvanceBouncingItemKinoko;
    }
    kinoko->mTimer = timer;
    kinokoSlot[0] = NULL;
}

#pragma thumb on

// Fills a table of eighteen 0x1c-byte objects allocated here.
void it_initItemConfig(void) {
    ItemInfo *infos;
    s32 i;

    infos = heap_alloc(proc_getHeap(proc_getCurrent()), 0x1f8);
    it_sItemConfigs = infos;
    infos[0] = it_sKouraGSingleConfig;
    infos[1] = it_sKouraRSingleConfig;
    infos[2] = it_sBananaSingleConfig;
    infos[3] = it_sFBoxConfig;
    infos[4] = it_sKinokoSingleConfig;
    infos[5] = it_sKinokoTripleConfig;
    infos[6] = it_sBombConfig;
    infos[7] = it_sKouraWConfig;
    infos[8] = it_sThunderConfig;
    infos[9] = it_sKouraGTripleConfig;
    infos[10] = it_sBananaTripleConfig;
    infos[11] = it_sKouraRTripleConfig;
    infos[12] = it_sStarConfig;
    infos[13] = it_sKinokoPConfig;
    infos[14] = it_sKillerConfig;
    infos[15] = it_sGessoConfig;
    infos[16] = it_sTeresaConfig;
    infos[17] = it_sItemBoxConfig;
    switch (gRaceMultiConfig->mMode) {
        case MODE_BATTLE:
            infos[17].mEnabled = TRUE;
            break;
        case 5:
            for (i = 0; i < 0x12; i++) {
                if (it_sItemConfigs[(u32) i].mEnabled != FALSE && it_sItemConfigs[(u32) i].field4 == 0) {
                    it_sItemConfigs[i].mEnabled = FALSE;
                }
            }
            break;
    }
    if (gRaceMultiConfig->mRaceKind == RACE_KIND_DEMO) {
        it_sItemConfigs[15].mEnabled = FALSE;
    }
}

#pragma thumb off

void it_initSlot(HeldItem *heldItem, KartItems *kartItems) {
    s32 i;

    heldItem->mKartItems = kartItems;
    heldItem->mItemInfoIndex = 0x13;
    heldItem->mObjectCount = 0;
    heldItem->mObjectStartFramesLeft = 0;
    heldItem->fieldC = 0;
    heldItem->mTimer = 0;
    heldItem->field12 = 0;
    for (i = 0; i < 3; i++) {
        heldItem->mObjects[i] = NULL;
    }
    heldItem->field24 = gRaceMultiConfig->mCurrentEntries[kartItems->mKartIndex].mPlayer.mKind == PLAYER_KIND_PEER;
}

// Starts one held object at counts 7, 5 and 3 of the countdown that StartHeldItemObjects sets.
void StartNextHeldItemObject(HeldItem *heldItem) {
    ItemObject *item;
    Kart *kart;
    Vec3 *kartDrawPos;
    Vec3 *kartVelocity;
    void (*kindCallback)(void *);
    s32 i;
    enum { K0 } kind;

    if (heldItem->mObjectStartFramesLeft <= 0) {
        return;
    }
    heldItem->mObjectStartFramesLeft--;
    if (heldItem->mObjectStartFramesLeft != 7 && heldItem->mObjectStartFramesLeft != 5 &&
        heldItem->mObjectStartFramesLeft != 3) {
        return;
    }
    kart = heldItem->mKartItems->mKart;
    heldItem->mObjectCount--;
    item = heldItem->mObjects[heldItem->mObjectCount];
    kartDrawPos = &kart->mDrawMatrixPos;
    kartVelocity = &kart->mVelocity;
    it_itemsetAddItem(it_sItemsets + item->mKind, item);
    func_020efd1c(heldItem->mKartItems, item);
    VEC_MultAdd(0xb33, kartVelocity, &item->mVelocity, &item->mVelocity);
    *(Vec3 *) &item->mPos = *kartDrawPos;
    it_startThrowAnim(item, 0, kartDrawPos, kartVelocity, &kart->mGroundNormal);
    kind = item->mKind;
    kindCallback = it_sItemParams[kind].field38;
    if (kindCallback != NULL) {
        kindCallback(item);
    }
    if (heldItem->mObjectCount != 0) {
        return;
    }
    heldItem->mItemInfoIndex = 0x13;
    heldItem->mObjectCount = 0;
    heldItem->mObjectStartFramesLeft = 0;
    heldItem->fieldC = 0;
    heldItem->mTimer = 0;
    heldItem->field12 = 0;
    for (i = 0; i < 3; i++) {
        heldItem->mObjects[i] = NULL;
    }
}
