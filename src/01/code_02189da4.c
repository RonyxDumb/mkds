#include "01/code_02189da4.h"
#include "01/code_02187c60.h"
#include "01/code_021882b8.h"
#include "01/code_02188cd8.h"

#include "Main/System/Heap.h"
#include "Main/Unknown/code_0209bef0.h"
#include "01/code_0218a41c.h"
#include "01/code_0218155c.h"
#include "01/code_02185ef4.h"
#include "01/code_02187c4c.h"
#include "01/code_02188218.h"
#include "01/code_0218a3ec.h"
#include "01/code_0218a568.h"
#include "01/code_02188158.h"
#include "01/code_02188484.h"
#include "Main/Unknown/code_020f36d8.h"
#include "code_0201c528.h"
#include "Main/Unknown/code_02039860.h"
#include "Main/Unknown/code_020a100c.h"
#include "Main/Unknown/code_020a126c.h"
#include "Main/Course/ShineBalloon.h"
#include "Main/Unknown/code_020d4c28.h"
#include "Main/Unknown/code_020fd264.h"
#include "Main/Unknown/code_02109110.h"
#include "Main/Unknown/unk_021759c0.h"
#include "Main/Unknown/unk_0217c000.h"
#include "Main/Unknown/code_020ac000.h"
#include "Main/Unknown/code_020364e0.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_02109000.h"
#include "Main/Unknown/code_020a1000.h"
#include "Main/Unknown/unk_0217a000.h"
#include "Main/Unknown/code_02061654.h"
#include "Main/Unknown/code_020a2300.h"
#include "01/code_02187000.h"
#include "01/code_0218a000.h"
#include "01/code_0218affc.h"
#include "01/code_0218b034.h"
#include "01/code_0218d520.h"
#include "01/unk_021a6000.h"
#include "01/unk_021a7000.h"
#include "Main/Unknown/code_020fd000.h"
#include "01/code_02188000.h"
#include "Main/Unknown/code_020d4000.h"
#include "Main/Unknown/code_02108e6c.h"
#include "Main/Unknown/code_0210b708.h"
#include "Main/Unknown/code_0210b000.h"

void func_ov001_0218a30c(Unk02188950 *mapObject) {
    Unk0210b7a8 soundRequest;

    func_ov001_02187218(mapObject, 8, NULL);
    ReleaseEffects(mapObject);
    StartEffectAtOffset(mapObject, 0, 0x2000, 0, 0x421, 0);
    StartEffectAtOffset(mapObject, 0, 0x2000, 0, 0x40c, 0);
    StartEffectAtOffset(mapObject, 0, 0x2000, 0, 0x40e, 0);
    StartEffectAtOffset(mapObject, 0, 0x2000, 0, 0x40d, 0);
    StartEffectAtOffset(mapObject, 0, 0x2000, 0, 0x40f, 0);
    soundRequest = data_ov001_021a7ad0;
    soundRequest.mPositionSource = &mapObject->field0.mPos;
    soundRequest.mDistanceSquared = mobj_calcXZCamDist(&mapObject->field0.mPos);
    sub_210B734(&soundRequest, func_02108e7c());
    mapObject->field0.mFlags |= data_ov001_021a6588;
    mapObject->field0.mFlags |= data_ov001_021a658c;
    mapObject->field0.mFlags |= data_ov001_021a6590;
}

void func_ov001_0218a2dc(Unk02188950 *mapObject) {
    func_ov001_02187218(mapObject, 8, NULL);
    StartAnimationNoEndCallback(mapObject, mapObject->mPrm->field70, mapObject->mPrm->field74);
    StartStateFrameCountCallback(mapObject, 0x3c, &func_ov001_0218a30c);
}

void func_ov001_0218a2d4(void) {
    func_ov001_021882b8();
}

s32 func_ov001_0218a2b8(Unk02188950 *mapObject) {
    int raceStarted;
    raceStarted = race_getState();
    if (raceStarted == 1) {
        func_ov001_02188e88(mapObject);
    }
    return 0;
}

void StartBombKingWaitForRaceStart(Unk02188950 *mapObject) {
    func_ov001_02187218(mapObject, 8, func_ov001_0218a2b8);
    StartAnimationNoEndCallback(mapObject, mapObject->mPrm->field64, mapObject->mPrm->field68);
}

void func_ov001_0218a250(Unk02188950 *mapObject) {
    func_ov001_02187218(mapObject, 8, NULL);
    StartAnimationWithEndCallback(mapObject, mapObject->mPrm->field58, mapObject->mPrm->field5C,
                                  (UnkFunc *) &StartBombKingWaitForRaceStart);
    SetAnimationFrameCallback(mapObject, ((u32) mapObject->mPrm->field148), func_ov001_0218b034);
}

void func_ov001_0218a20c(Unk02188950 *mapObject) {
    func_ov001_02187218(mapObject, 8, NULL);
    StartAnimationNoEndCallback(mapObject, mapObject->mPrm->field4C, mapObject->mPrm->field50);
    StartStateFrameCountCallback(mapObject, mapObject->mPrm->field54, &func_ov001_0218a250);
    mobj_emitSfxFromEmitter2(&mapObject->field0, 0x00000235u);
}

void func_ov001_0218a1d0(Unk02188950 *mapObject) {
    func_ov001_02187218(mapObject, 8, NULL);
    StartAnimationNoEndCallback(mapObject, mapObject->mPrm->field40, mapObject->mPrm->field44);
    SetAnimationFrameCallback(mapObject, mapObject->mPrm->field148, func_ov001_0218affc);
}

void func_ov001_0218a19c(Unk02188950 *mapObject) {
    func_ov001_02187218(mapObject, 8, NULL);
    StartAnimationNoEndCallback(mapObject, mapObject->mPrm->field34, mapObject->mPrm->field38);
    StartStateFrameCountCallback(mapObject, mapObject->mPrm->field3C, &func_ov001_0218a1d0);
}

void InitBombKingObjects(Unk0218d87c *list) {
    int i;
    Unk02188950 *mapObject;

    if (list != NULL) {
        for (i = 0; i < list->field4 && (mapObject = list->field0[i]) != NULL; i++) {
            Vec3 offset = {0, 0, 0};
            offset.x = mapObject->mPrm->fieldFC;
            offset.y = mapObject->mPrm->field100;
            func_ov001_02187c88(mapObject, 5, (&offset));
            if (race_isCamAnimMode() != 0) {
                func_ov001_0218a19c(mapObject);
            } else {
                func_ov001_0218a20c(mapObject);
            }
        }
    }
    mgcnt_setOnEndFunc((void (*)(void)) func_ov001_0218a2d4);
}

void UpdateBombKing(u32 a, Unk02188950 *mapObject) {
    int active;

    if (gRaceMultiConfig->mMode == MODE_MISSION_RUN) {
        active = mgcnt_hasWinnerBeenDecided();
    } else {
        active = 0;
    }
    if (active != 0) {
        if (func_ov001_021871f8(mapObject, 1) != 0) {
            if (gRaceMultiConfig->mMode == MODE_MISSION_RUN) {
                active = mgcnt_isDriverDead((u16) gRaceMultiConfig->mEntryIndex);
            } else {
                active = 0;
            }
            if (active != 0) {
                func_ov001_0218a3ec(mapObject);
            } else {
                func_ov001_0218a2dc(mapObject);
            }
        }
    } else {
        if (func_ov001_021871f8(mapObject, 3) != 0) {
            if (func_ov001_02188220(mapObject) >= 2) {
                StartBombKingJumpCycle(mapObject);
            }
        }
        if (func_ov001_021871f8(mapObject, 3) != 0) {
            StartBombKingWalkToBombState(mapObject);
        }
        if (func_ov001_021871f8(mapObject, 2) != 0) {
            StartBombKingWalkState(mapObject);
        }
    }
    boss_update(a, mapObject);
}

void func_ov001_0218a034(Unk02188950 *mapObject) {
    mobj_createSubObjects(0xc9, 0xa, mapObject);
    mapObject->field0.mSound = heap_alloc(proc_getHeap(proc_getCurrent()), 0x44);
    InitSoundSource((SoundSource *) mapObject->field0.mSound, 0xc, &mapObject->field0.mPos);
    mapObject->field0.mFarDistanceSquared = data_0217cbec[0x50 / 4];
}

void func_ov001_0218a028(Unk0201ca6c *emitter) {
    emitter->field6C = 0x2000;
}

void func_ov001_02189fe0(Unk02188950 *mapObject, ItemObject *itemObject) {
    if (itemObject->mKind == 9) {
        if (IsItemBombState2(itemObject) == FALSE) {
            ptcm_createEmitterNoUpdateSkip(0x3a, &itemObject->mPos, NULL, func_ov001_0218a028);
        }
    }
    mapObject->field2E0 = 1;
    SetItemCollisionCallback(mapObject, (UnkFunc *) func_ov001_02189fe0);
}

void BombKingItemHitCallback(Unk02188950 *mapObject, ItemObject *itemObject) {
    Vec3 velocity;
    s64 scale;

    if (IsItemBombStored(mapObject) != 0) {
        func_ov001_02187bfc(mapObject, NULL, 0);
    }
    mapObject->field2E0 = 2;
    SetItemCollisionCallback(mapObject, (UnkFunc *) BombKingItemHitCallback);
    if (func_ov001_021871f8(mapObject, 7) != 0) {
        velocity.x = mapObject->field0.mPos.x - itemObject->mPos.x;
        velocity.y = 0;
        velocity.z = mapObject->field0.mPos.z - itemObject->mPos.z;
        if ((s64) velocity.x * velocity.x + (s64) velocity.y * velocity.y + (s64) velocity.z * velocity.z >= 0x10) {
            vec_normalize(&velocity, &velocity);
        }
        scale = mapObject->mPrm->field16C;
        velocity.x = (s64) velocity.x * scale >> 12;
        velocity.y = (s64) velocity.y * scale >> 12;
        velocity.z = (s64) velocity.z * scale >> 12;
        velocity.y = mapObject->mPrm->field170;
        SetVelocity(mapObject, &velocity);
        func_ov001_0218a41c(mapObject);
    }
}
void LoadBomb_king(Unk0218d87c *list) {
    Unk02188950 *mapObject;
    MissionRunPrm *prm;
    int i;

    if (list != NULL) {
        for (i = 0; i < list->field4 && (mapObject = list->field0[i]) != NULL; i++) {
            if (gRaceMultiConfig->mMode == MODE_MISSION_RUN) {
                AddMissionRunMapObject(mapObject);
            }
            boss_21870E4(list, mapObject, aBomb_king_nsbm, aBomb_king_nsbc, aBomb_king_prm);
            LoadMissionRunMapObjectShadow(list, mapObject, aSh_circle_ns_1);
            prm = mapObject->mPrm;
            SetCollisionOffsetAndExtent(mapObject, prm->field8, prm->fieldC, prm->field20C);
            SetShadowOffsetYAndScale(mapObject, 0, 0x23000);
            SetItemCollisionCallback(mapObject, (UnkFunc *) BombKingItemHitCallback);
        }
    }
}

void func_ov001_02189e0c(void *mapObjectList, Unk02188950 *mapObject) {
    boss_render(mapObjectList, mapObject);
    boss_renderShadow(mapObjectList, mapObject, 0);
}

void func_ov001_02189dd8(void) {
    u32 v4 = 0x23eu;
    void *kartCollisionCallback = &boss_onDriverCollide;
    void *itemCollisionCallback = &boss_onItemCollide;
    void *sphereHitCallback = &boss_collide;
    void *kindData =
        func_ov001_0219b510(kartCollisionCallback, itemCollisionCallback, sphereHitCallback, 0x2u, 0x1u, v4, 0x0u);
}

void *InitBomb_king(void) {
    return mobj_createRenderPart3d(LoadBomb_king, func_ov001_02189e0c, ktesa_globalPreRender);
}

void *CreateBombKingUpdateList(void) {
    return mobj_createLogicPart(InitBombKingObjects, UpdateBombKing, NULL);
}
