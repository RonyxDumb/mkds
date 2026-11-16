#include "Main/Unknown/code_0209f650.h"
#include "Main/Unknown/code_020364e0.h"
#include "Main/System/Heap.h"
#include "Main/Unknown/code_0209b634.h"
#include "Main/Unknown/code_0209b000.h"
#include "Main/Unknown/code_0209bef0.h"
#include "ITCM/code_01ff8000.h"
#include "ITCM/code_01ff9000.h"
#include "Main/Unknown/code_0203c8c0.h"
#include "Main/Unknown/code_020d22c0.h"
#include "Main/Unknown/code_020d4c28.h"
#include "Main/Unknown/code_020d8bc0.h"
#include "Main/Unknown/code_020d8cac.h"
#include "Main/Unknown/code_020e6b58.h"
#include "Main/Unknown/code_0210b760.h"
#include "Main/Unknown/code_0210bafc.h"
#include "Main/Unknown/code_0210f744.h"
#include "Main/Unknown/unk_021759c0.h"
#include "Main/Unknown/unk_0217b000.h"
#include "Main/Unknown/unk_0217c000.h"
#include "Main/Unknown/code_0209bf70.h"

u16 FX_Atan2Idx(s32 a, s32 b);

static inline u16 func_0209f800_inline(u32 n) {
    RandomState64 *mapObjectRandom;
    u32 m;
    u32 r;

    if (n == 0x10000) {
        mapObjectRandom = mobj_getRng1();
        mapObjectRandom->mValue = mapObjectRandom->mMultiplier * mapObjectRandom->mValue + mapObjectRandom->mIncrement;
        return ((mapObjectRandom->mValue >> 32) * 0x10000) >> 32;
    } else {
        mapObjectRandom = mobj_getRng1();
        m = (u16) n;
        if (m == 0) {
            r = 0;
        } else {
            mapObjectRandom->mValue =
                mapObjectRandom->mMultiplier * mapObjectRandom->mValue + mapObjectRandom->mIncrement;
            if (m == 0) {
                r = mapObjectRandom->mValue >> 32;
            } else {
                r = ((mapObjectRandom->mValue >> 32) * m) >> 32;
            }
        }
    }
    return r;
}

static inline void func_0209f6d8_inline(TownMonte *townMonte) {
    townMonte->fieldA4 += townMonte->fieldA8;
    townMonte->fieldA8 += 0x4000;
    if (townMonte->fieldA4 == 0) {
        townMonte->fieldA4 += townMonte->fieldA8;
        townMonte->fieldA8 += 0x4000;
    } else if (townMonte->fieldA4 >= 0x16c000) {
        townMonte->fieldA8 = 0x4000 - townMonte->fieldA8;
        townMonte->mMirror = townMonte->mMirror == 0 ? 1 : 0;
    }
}

static inline void func_0209fdb4_inline(Airship *airship) {
    s32 t;

    airship->mWobbleAngle = (u16) airship->mWobbleAngle + airship->mWobbleAnglePerFrame;
    airship->fieldB0 =
        airship->mWobbleMid +
        aship_FX_MulInline(airship->mWobbleAmplitude / 2, 0x1000 - aship_FX_CosIdx((u16) airship->mWobbleAngle)) -
        airship->mWobbleOffset;
    airship->mWobbleOffset += airship->fieldB0;
    if (airship->mWobbleAmplitude > 0) {
        t = airship->mWobbleAmplitude + airship->mWobbleAmplitudePerFrame;
        if (t <= 0) {
            t = 0;
        }
        airship->mWobbleAmplitude = t;
    } else if (airship->mWobbleAmplitude < 0) {
        t = airship->mWobbleAmplitude + airship->mWobbleAmplitudePerFrame;
        if (t >= 0) {
            t = 0;
        }
        airship->mWobbleAmplitude = t;
    }
    if (airship->mWobbleAnglePerFrame > 0) {
        t = airship->mWobbleAnglePerFrame + airship->fieldC4;
        if (t <= 0) {
            t = 0;
        }
        airship->mWobbleAnglePerFrame = t;
    } else if (airship->mWobbleAnglePerFrame < 0) {
        t = airship->mWobbleAnglePerFrame + airship->fieldC4;
        if (t >= 0) {
            t = 0;
        }
        airship->mWobbleAnglePerFrame = t;
    }
}

static inline BOOL func_0209fdb4_inline_b(void) {
    s32 i;

    for (i = 0; i < gRaceMultiConfig->mKartCount; i++) {
        if (rstat_getDriverHighestReachedLap((u16) i) >= 2) {
            return TRUE;
        }
    }
    return FALSE;
}

void aship_update(void *a, Airship *airship) {
    switch (airship->mState) {
        case 0:
            if (func_0209fdb4_inline_b() != FALSE) {
                airship->mState = 1;
            }
            break;
        case 1:
            airship->fieldA0 += 0x1000;
            if (airship->fieldA0 >= 0) {
                airship->fieldA0 = 0;
                airship->mState = 2;
            }
            func_0209fdb4_inline(airship);
            break;
        case 2:
            pw_update(&airship->fieldC8);
            pw_20D8BF8_XYZ(&airship->fieldC8, &airship->field0.mPos, &airship->field0.field10);
            func_0209fdb4_inline(airship);
            break;
    }
    airship->field0.mAngle = FX_Atan2Idx(airship->field0.field10.x, airship->field0.field10.z);
}

void *aship_setupRenderPart(void) {
    return mobj_createRenderPart3d(aship_loadModel, aship_render, NULL);
}

void *aship_setupLogicPart(void) {
    return mobj_createLogicPart(aship_globalLogicInit, aship_update, NULL);
}

void pole_init(MapObject *mapObject) {
    s32 i;

    i = mapObject->mCourseMapRow->field28;
    if (pole_sConfigs[i] == NULL) {
        pole_sConfigs[i] = heap_alloc(proc_getHeap(proc_getCurrent()), 0x40);
        *pole_sConfigs[i] = *pole_sConfigs[0];
    }
    switch (i) {
        case 0x10:
            pole_sConfigs[i]->field24 = 0x127;
            break;
        case 0x11:
            pole_sConfigs[i]->field24 = 0x100;
            break;
        case 0x12:
            pole_sConfigs[i]->field24 = 0x1da;
            break;
        default:
            pole_sConfigs[i]->field24 = csfx_getWallSfx(0, 8, i);
            break;
    }
    mapObject->mKindData = pole_sConfigs[i];
}

void pole_setupConfig(void) {
    s32 i;

    for (i = 0; i < 19; i++) {
        pole_sConfigs[i] = NULL;
    }
    pole_sConfigs[0] = (MapObjectKindData *) mobj_createDummyConfig();
}

void tmon_globalPostRender(void) {
    bbm_20E6C0C();
}

void tmon_loadModel(MapObjectModel *mapObjectModel) {
    mapObjectModel->mShadowModel = (void *) tmon_globalPostRender;
    mobj_setModelPolygonIdAll(
        tmon_sModel = mobj_loadTexAnimBillboardModel(mapObjectModel, aTownmonte_nsbm, aTownmonte_nsbt), 0x3f);
}

void tmon_render(void *a, TownMonte *townMonte) {
    s32 v;
    s32 d;
    MtxFx43 *h;

    d = (0x16c000 - townMonte->fieldA4) >> 12;
    v = 0x1e;
    NNS_G3dGeBufferOP_N(0x14, &v, 1);
    if (townMonte->mMirror != 0) {
        h = bbm_getYBillboardAtPosTransformed(&townMonte->field0.mPos, -d, d);
        NNS_G3dGeBufferOP_N(0x19, h, 0xc);
    } else {
        h = bbm_getYBillboardAtPosTransformed(&townMonte->field0.mPos, d, d);
        NNS_G3dGeBufferOP_N(0x19, h, 0xc);
    }
    NNS_G3dGeBufferOP_N(0x1b, &townMonte->field0.mScale, 3);
    mobj_setModelNsbtpFrame(tmon_sModel, townMonte->mNsbtpFrameIndex);
    mobj_bbModelApplyMaterial(a, tmon_sModel);
    mobj_renderModel(a, tmon_sModel, townMonte);
}

void tmon_globalInitLogic(Unk0209f800 *a) {
    TownMonte *townMonte;
    RandomState64 *mapObjectRandom;
    s32 i;
    s32 j;
    u32 nsbtpFrameCount;
    u16 m;

    if (a == NULL) {
        return;
    }
    for (i = 0; i < a->field4 && (townMonte = a->field0[i]) != NULL; i++) {
        townMonte->fieldA4 = 0;
        townMonte->fieldA8 = 0;
        nsbtpFrameCount = mobj_getModelNsbtpFrameCount(tmon_sModel);
        townMonte->mNsbtpFrameIndex = func_0209f800_inline(nsbtpFrameCount);
        mapObjectRandom = mobj_getRng1();
        mapObjectRandom->mValue = mapObjectRandom->mMultiplier * mapObjectRandom->mValue + mapObjectRandom->mIncrement;
        m = ((mapObjectRandom->mValue >> 32) * 0x1a) >> 32;
        for (j = 0; j < m; j++) {
            func_0209f6d8_inline(townMonte);
        }
        if (townMonte->field0.mCourseMapRow->field28 != 0) {
            if (townMonte->mNsbtpFrameIndex == 0) {
                townMonte->mSoundId = 0x1a7;
            } else if (townMonte->mNsbtpFrameIndex == 1) {
                townMonte->mSoundId = 0x1a8;
            } else if (townMonte->mNsbtpFrameIndex == 2) {
                mapObjectRandom = mobj_getRng1();
                mapObjectRandom->mValue =
                    mapObjectRandom->mMultiplier * mapObjectRandom->mValue + mapObjectRandom->mIncrement;
                townMonte->mSoundId = (u16) (((mapObjectRandom->mValue >> 32) * 2) >> 32) != 0 ? 0x1a7 : 0x1a8;
            }
        }
    }
}

void tmon_update(void *a, TownMonte *townMonte) {
    Unk0210b7a8 s;
    s32 t;
    u16 w;

    func_0209f6d8_inline(townMonte);
    if (townMonte->mSoundId == 0) {
        return;
    }
    if (townMonte->field0.mCourseMapRow->field28 != sndvar_getVarField4(0)) {
        return;
    }
    w = townMonte->mSoundId;
    if (townMonte->field0.mDistanceSquaredAndFlags & 4) {
        return;
    }
    if (townMonte->field0.mFarDistanceSquared == gSfxParams[2].field20) {
        t = 2;
    } else if (townMonte->field0.mFarDistanceSquared == gSfxParams[3].field20) {
        t = 3;
    } else {
        t = 4;
    }
    s.mSoundId = w;
    s.mPositionSource = &townMonte->field0.mPos;
    s.field8 = t;
    s.mDistanceSquared = mobj_calcXZCamDist(&townMonte->field0.mPos);
    func_0210b7a8(&s);
}

void *tmon_setupRenderPart(void) {
    return mobj_createRenderPart2d(tmon_loadModel, tmon_render, NULL);
}

void *tmon_setupLogicPart(void) {
    return mobj_createLogicPart(tmon_globalInitLogic, tmon_update, NULL);
}

void chnd_loadModel(void *a) {
    mobj_loadNsbcaAnim(chnd_sModel = mobj_loadModel(a, aChandelier_nsb),
                                       aChandelier_n_1);
    mobj_setModelPolygonIdAll(chnd_sModel, 0x3f);
}
