#include "01/code_0218a568.h"
#include "01/code_02185ef4.h"
#include "01/code_02187c4c.h"
#include "01/code_02187c60.h"
#include "01/code_02187e78.h"
#include "01/code_02187eb0.h"
#include "01/code_02188158.h"
#include "01/code_02188cd8.h"
#include "01/code_02188de0.h"
#include "01/code_02187000.h"
#include "01/code_0218a000.h"
#include "01/code_0218ac04.h"
#include "01/code_0218b000.h"
#include "01/code_0218b034.h"
#include "01/code_0218b278.h"
#include "Main/Unknown/code_020d22c0.h"
#include "Main/Unknown/code_020d275c.h"
#include "Main/Unknown/code_02042044.h"
#include "Main/Unknown/code_0206bcb0.h"
#include "Main/Unknown/code_020fd83c.h"
#include "Main/Unknown/code_020fd000.h"
#include "Main/Unknown/code_020fd264.h"

void func_ov001_0218aba0(Unk02188950 *mapObject) {
    func_ov001_02187218(mapObject, 3, NULL);
    StartAnimationNoEndCallback(mapObject, mapObject->mPrm->field198, mapObject->mPrm->field19C);
    func_ov001_02188c90(mapObject);
    SetSpeedAndClearTarget(mapObject, 0);
    StartStateFrameCountCallback(mapObject, mapObject->mPrm->field1A0, &func_ov001_0218ac04);
    mobj_emitSfxFromEmitter2(&mapObject->field0, 0x238);
}

void StartBombKingJumpCycle(Unk02188950 *mapObject) {
    IncrementEntryIndex(mapObject);
    func_ov001_02187218(mapObject, 3, NULL);
    StartAnimationNoEndCallback(mapObject, mapObject->mPrm->field17C, mapObject->mPrm->field180);
    func_ov001_02188c48(mapObject, mapObject->mPrm->field18C, mapObject->mPrm->field190);
    SetAnglePointAndMoveAnglePoint(mapObject, &GetCurrentGroupEntry(mapObject)->mPos);
    SetSpeedTargetAndPerCall(mapObject, mapObject->mPrm->field184, mapObject->mPrm->field188);
    StartStateFrameCountCallback(mapObject, mapObject->mPrm->field194, &func_ov001_0218aba0);
    func_ov001_0218b278(mapObject);
}

void StartBombKingThrowBombsState(Unk02188950 *mapObject) {
    func_ov001_02187218(mapObject, 3, NULL);
    StartAnimationWithEndCallback(mapObject, mapObject->mPrm->field140, mapObject->mPrm->field144, NULL);
    func_ov001_02188c90(mapObject);
    SetSpeedAndClearTarget(mapObject, 0);
    SetAnimationFrameCallback(mapObject, mapObject->mPrm->field148, func_ov001_0218b034);
}

void func_ov001_0218aa34(Unk02188950 *mapObject) {
    void *bomb;

    if (IsItemBombStored(mapObject) == 0) {
        bomb = itbomb_20FD428();
        if (bomb != NULL) {
            ReleaseAndSetItemBomb(mapObject, (bomb));
        }
    }
    if (IsItemBombStored(mapObject) != 0) {
        func_ov001_02187218(mapObject, 3, NULL);
        StartAnimationWithEndCallback(mapObject, mapObject->mPrm->fieldD4, mapObject->mPrm->fieldD8, 0);
        SetSpeedAndClearTarget(mapObject, 0);
        SetAnimationFrameCallback(mapObject, mapObject->mPrm->fieldDC, ThrowStoredItemBomb);
    }
    mobj_emitSfxFromEmitter2(&mapObject->field0, 0x23c);
}

void StartBombKingChaseState(Unk02188950 *mapObject) {
    Kart *kart;

    kart = GetEntryKartInRange(mapObject, mapObject->mPrm->fieldC0, mapObject->mPrm->fieldC4);
    if (kart != NULL) {
        func_ov001_02187218(mapObject, 3, NULL);
        StartAnimationNoEndCallback(mapObject, mapObject->mPrm->field104, mapObject->mPrm->field108);
        func_ov001_02188c48(mapObject, mapObject->mPrm->fieldBC, mapObject->mPrm->fieldBC);
        SetAnglePointAndMoveAnglePoint(mapObject, &kart->mPos);
        SetSpeedAndClearTarget(mapObject, mapObject->mPrm->fieldB8);
        SetPointInRangeCallback(mapObject, mapObject->mPrm->fieldCC, mapObject->mPrm->fieldD0, &kart->mPos,
                                &func_ov001_0218aa34);
        StartStateFrameCountCallback(mapObject, mapObject->mPrm->fieldC8, 0);
        func_ov001_0218b278(mapObject);
    } else {
        func_ov001_02188e88(mapObject);
    }
}

void StartItemBombThrow(Unk02188950 *mapObject) {
    if (IsItemBombStored(mapObject) != 0) {
        func_ov001_02187218(mapObject, 3, NULL);
        StartAnimationWithEndCallback(mapObject, mapObject->mPrm->fieldD4, mapObject->mPrm->fieldD8, 0);
        SetSpeedAndClearTarget(mapObject, 0);
        SetAnimationFrameCallback(mapObject, mapObject->mPrm->fieldDC, ThrowStoredItemBomb);
        mobj_emitSfxFromEmitter2(&mapObject->field0, 0x23c);
    }
}

void func_ov001_0218a828(Unk02188950 *mapObject) {
    ItemBomb *bomb;
    Kart *kart;

    bomb = FindItemBombInRange(mapObject, mapObject->mPrm->field11C, mapObject->mPrm->field120);
    if (bomb != NULL) {
        kart = GetEntryKartInRange(mapObject, mapObject->mPrm->fieldC0, mapObject->mPrm->fieldC4);
        if (kart != NULL) {
            func_020fd754(bomb);
            ReleaseAndSetItemBomb(mapObject, bomb);
            func_ov001_02187218(mapObject, 3, NULL);
            StartAnimationNoEndCallback(mapObject, mapObject->mPrm->fieldEC, mapObject->mPrm->fieldF0);
            func_ov001_02188c48(mapObject, mapObject->mPrm->fieldF8, mapObject->mPrm->fieldF8);
            SetAnglePointAndMoveAnglePoint(mapObject, &kart->mPos);
            SetSpeedAndClearTarget(mapObject, mapObject->mPrm->fieldF4);
            SetPointInRangeCallback(mapObject, mapObject->mPrm->fieldCC, mapObject->mPrm->fieldD0, &kart->mPos,
                                    &StartItemBombThrow);
            func_ov001_0218b278(mapObject);
        } else {
            func_020fd754(bomb);
            ReleaseAndSetItemBomb(mapObject, bomb);
            StartItemBombThrow(mapObject);
        }
    }
}

void StartBombKingWalkToBombState(Unk02188950 *mapObject) {
    ItemBomb *bomb;

    bomb = FindItemBombInRange(mapObject, mapObject->mPrm->field114, mapObject->mPrm->field118);
    if (bomb != NULL) {
        func_ov001_02187218(mapObject, 3, NULL);
        StartAnimationNoEndCallback(mapObject, mapObject->mPrm->field104, mapObject->mPrm->field108);
        func_ov001_02188c48(mapObject, mapObject->mPrm->field110, mapObject->mPrm->field110);
        SetAnglePointAndMoveAnglePoint(mapObject, &bomb->field0.mItemObject.mPos);
        SetSpeedAndClearTarget(mapObject, mapObject->mPrm->field10C);
        SetPointInRangeCallback(mapObject, mapObject->mPrm->field11C, mapObject->mPrm->field120,
                                &bomb->field0.mItemObject.mPos, &func_ov001_0218a828);
        StartStateFrameCountCallback(mapObject, mapObject->mPrm->field124, 0);
        func_ov001_0218b278(mapObject);
    }
}

void StartBombKingRandomState(Unk02188950 *mapObject) {
    u32 randomLimit;
    RandomState64 *rng;
    u32 randomValue;

    randomLimit = (u16) mapObject->mPrm->field208;
    if (randomLimit == 0x10000) {
        rng = mobj_getRng1();
        rng->mValue = rng->mMultiplier * rng->mValue + rng->mIncrement;
        randomValue = (u16) (((rng->mValue >> 32) * 0x10000) >> 32);
    } else {
        rng = mobj_getRng1();
        if ((u16) randomLimit == 0) {
            randomValue = 0;
        } else {
            rng->mValue = rng->mMultiplier * rng->mValue + rng->mIncrement;
            if ((u16) randomLimit == 0) {
                randomValue = rng->mValue >> 32;
            } else {
                randomValue = ((rng->mValue >> 32) * (s64) (u16) randomLimit) >> 32;
            }
        }
        randomValue = (u16) randomValue;
    }
    if (randomValue != 0) {
        StartBombKingThrowBombsState(mapObject);
    } else {
        StartBombKingChaseState(mapObject);
    }
}

void StartBombKingWalkState(Unk02188950 *mapObject) {
    MissionRunPrm *prm;

    IncrementEntryIndex(mapObject);
    func_ov001_02187218(mapObject, 2, NULL);
    StartAnimationNoEndCallback(mapObject, mapObject->mPrm->field84, mapObject->mPrm->field88);
    func_ov001_02188c48(mapObject, mapObject->mPrm->field90, mapObject->mPrm->field90);
    SetAnglePointAndMoveAnglePoint(mapObject, &GetCurrentGroupEntry(mapObject)->mPos);
    SetSpeedAndClearTarget(mapObject, mapObject->mPrm->field8C);
    StartStateFrameCountCallback(mapObject, mapObject->mPrm->field9C, &StartBombKingRandomState);
    prm = mapObject->mPrm;
    SetPointInRangeCallback(mapObject, prm->field94, prm->field98, &GetCurrentGroupEntry(mapObject)->mPos,
                            &StartBombKingThrowBombsState);
    func_ov001_0218b278(mapObject);
}

int StartBombKingBounceEffects(Unk02188950 *mapObject) {
    if ((mapObject->mCollisionBits & 0x1e34ef) != 0) {
        if (mapObject->mVelocity.y > 0x3333) {
            ReleaseEffects(mapObject);
            StartEffectAtRowHeight(mapObject, 0, 0, 0, 0x411, 0);
            StartEffectAtRowHeight(mapObject, 0, 0, 0, 0x412, 0);
        }
        if (mapObject->mVelocity.y > 0) {
            mobj_emitSfxFromEmitter2(&mapObject->field0, 0x23b);
        }
    }
    return 0;
}

int func_ov001_0218a568(Unk02188950 *mapObject) {
    if ((mapObject->mCollisionBits & 0x1e34ef) != 0) {
        mapObject->field158 = StartBombKingBounceEffects;
    }
    return 0;
}
