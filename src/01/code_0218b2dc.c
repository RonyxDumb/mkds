#include "01/code_0218b2dc.h"
#include "01/code_021882b8.h"
#include "01/code_02188cd8.h"
#include "Main/Unknown/code_02042044.h"
#include "Main/Unknown/code_0210b000.h"

#include "Main/System/Heap.h"
#include "Main/Unknown/code_0208b484.h"
#include "Main/Unknown/code_0209b60c.h"
#include "Main/Unknown/code_0209b634.h"
#include "Main/Unknown/code_0209bef0.h"
#include "01/code_0218b9b4.h"
#include "01/unk_021a6000.h"
#include "01/code_02188000.h"
#include "01/code_0218c000.h"
#include "Main/Unknown/code_020a100c.h"
#include "Main/Unknown/code_020a126c.h"
#include "Main/Course/ShineBalloon.h"
#include "Main/Unknown/code_020d4000.h"
#include "01/code_02185ef4.h"
#include "01/code_02187d14.h"
#include "Main/Unknown/code_020d4c28.h"
#include "Main/Unknown/code_020f4000.h"
#include "Main/Unknown/code_02109110.h"
#include "Main/Unknown/unk_0217c000.h"
#include "01/code_02188158.h"
#include "Main/Unknown/code_020364e0.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_02073000.h"
#include "Main/Unknown/code_020ac000.h"
#include "Main/Unknown/code_020b1dbc.h"
#include "Main/Unknown/code_0207b960.h"
#include "Main/Unknown/code_020b4e5c.h"
#include "Main/Unknown/code_02039860.h"
#include "Main/Unknown/code_02147000.h"
#include "Main/Unknown/unk_0215d000.h"
#include "Main/Unknown/unk_021759c0.h"
#include "Main/Unknown/code_020b47d8.h"
#include "Main/Unknown/code_020b6a18.h"
#include "Main/Unknown/code_0207a880.h"
#include "Main/Unknown/code_020b502c.h"
#include "Main/Unknown/code_020d2000.h"
#include "Main/Unknown/code_02109000.h"
#include "01/unk_021a9000.h"
#include "Main/Unknown/code_020b4000.h"
#include "Main/Unknown/code_020f9c6c.h"
#include "Main/Unknown/code_021000d0.h"

Unk021a7b64 gKurikingMObjDef = {
    0, 0x30c, kking_init, kking_setupCollision, kking_setupRenderPart, 0, 0, kking_setupLogicPart, {0, 0, 0, 0, 0},
};

void func_ov001_0218b928(Unk02188950 *mapObject) {
    func_ov001_02187218(mapObject, 8, (s32(*)(Unk02188950 *))(0));
    ptcm_createEmitter(0x418, &mapObject->mUnk_000.mPos);
    ptcm_createEmitter(0x417, &mapObject->mUnk_000.mPos);
    ptcm_createEmitter(0x416, &mapObject->mUnk_000.mPos);
    {
        Unk0210b7a8 soundRequest = {0x225, 0, 0xf, 0};

        soundRequest.mPositionSource = &mapObject->mUnk_000.mPos;
        soundRequest.mDistanceSquared = mobj_calcXZCamDist(soundRequest.mPositionSource);
        func_0210b734(&soundRequest, func_02108e7c());
    }
    mapObject->mUnk_000.mFlags |= data_ov001_021a659c;
    mapObject->mUnk_000.mFlags |= data_ov001_021a65a0;
    mapObject->mUnk_000.mFlags |= data_ov001_021a65a4;
}

void func_ov001_0218b8f8(Unk02188950 *mapObject) {
    func_ov001_02187218(mapObject, 8, (s32(*)(Unk02188950 *))(0));
    StartAnimationNoEndCallback(mapObject, mapObject->mPrm->mUnk_070, mapObject->mPrm->mUnk_074);
    StartStateFrameCountCallback(mapObject, 0x3c, &func_ov001_0218b928);
}

void func_ov001_0218b8f0(void) {
    func_ov001_021882b8();
}

s32 func_ov001_0218b8d4(Unk02188950 *mapObject) {
    int raceStarted;
    raceStarted = race_getState();
    if (raceStarted == 1) {
        func_ov001_02188e88(mapObject);
    }
    return 0;
}

s32 func_ov001_0218b850(Unk02188950 *mapObject) {
    int nsbcaFrameIndex;
    nsbcaFrameIndex = mobj_getModelCurNsbcaFrame(mapObject->mNsbmd);
    if (nsbcaFrameIndex == 0x4d) {
        ReleaseEffects(mapObject);
        StartEffectAtRowHeight(mapObject, (0xfffff99au), 0, (0xfffff99au), (0x0000042bu), 0);
        mobj_emitSfxFromEmitter2(&mapObject->mUnk_000, (0x0000021eu));
    } else {
        nsbcaFrameIndex = mobj_getModelCurNsbcaFrame(mapObject->mNsbmd);
        if (nsbcaFrameIndex == 0x68) {
            ReleaseEffects(mapObject);
            StartEffectAtRowHeight(mapObject, (0xfffff99au), 0, (0xfffff99au), (0x0000042cu), 0);
            mobj_emitSfxFromEmitter2(&mapObject->mUnk_000, (0x0000021fu));
        }
    }
    return 0;
}

void func_ov001_0218b828(Unk02188950 *mapObject) {
    func_ov001_02187218(mapObject, 8, func_ov001_0218b8d4);
    StartAnimationNoEndCallback(mapObject, mapObject->mPrm->mUnk_064, mapObject->mPrm->mUnk_068);
}

void func_ov001_0218b7fc(Unk02188950 *mapObject) {
    func_ov001_02187218(mapObject, 8, func_ov001_0218b850);
    StartAnimationWithEndCallback(mapObject, mapObject->mPrm->mUnk_058, mapObject->mPrm->mUnk_05c,
                                  &func_ov001_0218b828);
}

void func_ov001_0218b7c8(Unk02188950 *mapObject) {
    func_ov001_02187218(mapObject, 8, (s32(*)(Unk02188950 *))(0));
    StartAnimationNoEndCallback(mapObject, mapObject->mPrm->mUnk_04c, mapObject->mPrm->mUnk_050);
    StartStateFrameCountCallback(mapObject, mapObject->mPrm->mUnk_054, &func_ov001_0218b7fc);
}

void func_ov001_0218b7a4(Unk02188950 *mapObject) {
    func_ov001_02187218(mapObject, 8, (s32(*)(Unk02188950 *))(0));
    StartAnimationNoEndCallback(mapObject, mapObject->mPrm->mUnk_040, mapObject->mPrm->mUnk_044);
}

void func_ov001_0218b770(Unk02188950 *mapObject) {
    func_ov001_02187218(mapObject, 8, (s32(*)(Unk02188950 *))(0));
    StartAnimationNoEndCallback(mapObject, mapObject->mPrm->mUnk_034, mapObject->mPrm->mUnk_038);
    StartStateFrameCountCallback(mapObject, mapObject->mPrm->mUnk_03c, &func_ov001_0218b7a4);
}

void kking_init(Unk02188950 *mapObject) {
    mobj_createSubObjects(MAP_OBJECT_KIND_KURIBO, 0x32, mapObject);
    mapObject->mUnk_000.mSound = heap_alloc(proc_getHeap(proc_getCurrent()), 0x44);
    InitSoundSource(&mapObject->mUnk_000.mSound->mSoundSource, 0xf, &mapObject->mUnk_000.mPos);
    mapObject->mUnk_000.mFarDistanceSquared = data_0217cc6c[15];
}

void func_ov001_0218b6f8(Unk02188950 *mapObject, void *kart) {
    SetKartCollisionCallback(mapObject, func_ov001_0218b6f8);
    if (mapObject->mTimer == 0) {
        mobj_driverEmitSfx2(kart, 0x224);
    }
}

void func_ov001_0218b640(Unk02188950 *mapObject, void *kart) {
    mapObject->mUnk_000.mUnk_10.x =
        (s64) mapObject->mPrm->mUnk_130 * FX_SinCosTable_[((u16) mapObject->mMoveAngle >> 4) * 2] >> 12;
    mapObject->mUnk_000.mUnk_10.y = 0;
    mapObject->mUnk_000.mUnk_10.z =
        (s64) mapObject->mPrm->mUnk_130 * FX_SinCosTable_[((u16) mapObject->mMoveAngle >> 4) * 2 + 1] >> 12;
    mapObject->mUnk_2d8 = 0xd;
    cam_tryImpactShakePlayerCamera(mapObject->mUnk_000.mDistanceSquaredAndFlags & 0x3fffffe0, 0x1000);
    SetKartCollisionCallback(mapObject, func_ov001_0218b6f8);
    if (mapObject->mTimer == 0) {
        mobj_driverEmitSfx2(kart, 0x224);
    }
}

void InitKurikingObjects(Unk0218d87c *mapObjectList) {
    s32 i;
    Unk02188950 *obj;

    if (mapObjectList != NULL) {
        for (i = 0; i < mapObjectList->mUnk_04 && (obj = mapObjectList->mUnk_00[i]) != NULL; i++) {
            func_ov001_0219b1c4(obj->mNsbmd, obj->mPrm->mUnk_080, obj->mPrm->mUnk_050, 0);
            if (race_isCamAnimMode()) {
                func_ov001_0218b770(obj);
            } else {
                func_ov001_0218b7c8(obj);
            }
        }
    }
    mgcnt_setOnEndFunc((void (*)(void)) func_ov001_0218b8f0);
}

void UpdateKuriking(u32 a, Unk02188950 *mapObject) {
    s32 var;

    if (gRaceMultiConfig->mMode == MODE_MISSION_RUN ? mgcnt_hasWinnerBeenDecided() : 0) {
        if (func_ov001_021871f8(mapObject, 1)) {
            if (gRaceMultiConfig->mMode == MODE_MISSION_RUN ? mgcnt_isDriverDead((u16) gRaceMultiConfig->mEntryIndex) : 0) {
                func_ov001_0218b9b4(mapObject);
            } else {
                func_ov001_0218b8f8(mapObject);
            }
        }
    } else {
        if (IsPointInRange(mapObject, &GetCurrentGroupEntry(mapObject)->mPos, mapObject->mPrm->mUnk_0b4, 0)) {
            var = func_ov001_02187f7c(mapObject);
            if (var >= 200) {
                if (func_ov001_021871f8(mapObject, 8)) {
                    func_ov001_0218ba34(mapObject);
                    SetKartCollisionCallback(mapObject, func_ov001_0218b6f8);
                }
            } else if (var >= 100) {
                if (func_ov001_021871f8(mapObject, 7)) {
                    func_ov001_0218bbac(mapObject);
                    SetKartCollisionCallback(mapObject, func_ov001_0218b6f8);
                }
            } else if (var >= 1) {
                if (func_ov001_021871f8(mapObject, 1)) {
                    func_ov001_0218bde8(mapObject);
                    SetKartCollisionCallback(mapObject, func_ov001_0218b6f8);
                }
            }
            IncrementEntryIndex(mapObject);
            if (mapObject->mEntryIndex == 0) {
                IncrementEntryGroupIndex(mapObject, 3);
            }
        }
        if (func_ov001_021871f8(mapObject, 2)) {
            if (GetEntryKartInRange(mapObject, mapObject->mPrm->mUnk_124, mapObject->mPrm->mUnk_128)) {
                func_ov001_0218c490(mapObject);
                SetKartCollisionCallback(mapObject, func_ov001_0218b640);
            }
        }
        if (func_ov001_021871f8(mapObject, 1)) {
            func_ov001_0218c354(mapObject);
            SetKartCollisionCallback(mapObject, func_ov001_0218b640);
        }
        mapObject->mUnk_2b8 = 1;
    }
    boss_update(a, mapObject);
    func_ov001_0219b1fc(mapObject->mNsbmd);
    var = mapObject->mUnk_134 + 1;
    if (var >= func_ov001_02188220(mapObject) * 30) {
        var = func_ov001_02188220(mapObject) * 30;
    }
    mapObject->mUnk_134 = var;
    var = mapObject->mUnk_134;
    if (var >= mobj_getModelNsbmaFrameCount(mapObject->mNsbmd) - 1) {
        var = mobj_getModelNsbmaFrameCount(mapObject->mNsbmd) - 1;
    }
    mapObject->mUnk_134 = var;
    mobj_setModelNsbmaFrame(mapObject->mNsbmd, (u16) mapObject->mUnk_134);
}

void LoadKuriking(Unk0218d87c *mapObjectList) {
    s32 i;
    Unk02188950 *obj;

    if (mapObjectList != NULL) {
        for (i = 0; i < mapObjectList->mUnk_04 && (obj = mapObjectList->mUnk_00[i]) != NULL; i++) {
            if (gRaceMultiConfig->mMode == MODE_MISSION_RUN) {
                AddMissionRunMapObject(obj);
            }
            boss_21870E4(mapObjectList, obj, ("kuriking.nsbmd"), ("kuriking.nsbca"), ("kuriking.prm"));
            LoadMissionRunMapObjectShadow(mapObjectList, obj, ("sh_circle.nsbmd"));
            LoadMapObjectModelNsbtaAnimation(obj->mNsbmd, "kuriking.nsbta");
            LoadMapObjectModelNsbtpAnimation(obj->mNsbmd, "kuriking.nsbtp");
            LoadMapObjectModelNsbmaAnimation(obj->mNsbmd, "kuriking.nsbma");
            SetKurikingCollisionAndShadow(obj);
            SetKartCollisionCallback(obj, func_ov001_0218b6f8);
        }
    }
}

void RenderKuriking(void *mapObjectList, Unk02188950 *mapObject) {
    boss_render(mapObjectList, mapObject);
    boss_renderShadow(mapObjectList, mapObject, 0);
}

void kking_setupCollision(void) {
    void *kartCollision = &boss_onDriverCollide;
    void *itemCollision = &boss_onItemCollide;
    void *sphereHit = &boss_collide;
    void *kindData = func_ov001_0219b510(kartCollision, itemCollision, sphereHit, 0x2u, 0x1u, 0x0u, 0x0u);
}

void *kking_setupRenderPart(void) {
    return mobj_createRenderPart3d(LoadKuriking, RenderKuriking, ktesa_globalPreRender);
}

void *kking_setupLogicPart(void) {
    return mobj_createLogicPart(InitKurikingObjects, UpdateKuriking, NULL);
}
