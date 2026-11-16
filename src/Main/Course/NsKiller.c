#include "Main/Course/NsKiller.h"
#include "ITCM/code_01ff8000.h"
#include "ITCM/code_01ff9000.h"
#include "Main/Unknown/code_0207a780.h"
#include "Main/Unknown/code_0206bcb0.h"
#include "Main/Unknown/code_0208aea8.h"
#include "Main/Unknown/code_0208b484.h"
#include "Main/Unknown/code_0209b000.h"
#include "Main/Unknown/code_0209b634.h"
#include "Main/Unknown/code_0209bef0.h"
#include "code_02146d78.h"
#include "Main/Unknown/code_02042044.h"
#include "Main/Unknown/unk_021759c0.h"
#include "Main/Unknown/code_0209bf70.h"
#include "Main/Unknown/code_020d22c0.h"
#include "Main/Unknown/code_020d26f8.h"
#include "Main/Unknown/code_020d275c.h"
#include "Main/Unknown/code_020d278c.h"
#include "Main/Unknown/code_020d4c28.h"
#include "Main/Unknown/code_020d8654.h"
#include "Main/Unknown/code_020d8cac.h"
#include "Main/Unknown/code_02100084.h"
#include "Main/Unknown/code_02108e6c.h"
#include "Main/Unknown/code_0210a67c.h"
#include "Main/Unknown/code_0210b708.h"
#include "Main/Unknown/code_0210b760.h"
#include "Main/Unknown/code_0210b850.h"
#include "Main/Unknown/code_020e6b58.h"
#include "Main/Unknown/code_021000d0.h"
#include "Main/Unknown/code_02146000.h"
#include "Main/Unknown/unk_02156000.h"
#include "Main/Unknown/unk_02166000.h"
#include "Main/Unknown/unk_0215d000.h"
#include "Main/Unknown/unk_0217b000.h"
#include "code_02146cbc.h"
#include "code_02147cd8.h"
#include "code_0212bcac.h"

void nsk1_loadModel(void *a) {
    nsk1_sModel = mobj_loadModel(a, aNskiller1_nsbm);
}

void nsk1_render(void *a, NsKiller1 *nsKiller1) {
    s32 t;

    t = 0x1e;
    NNS_G3dGeBufferOP_N(0x14, &t, 1);
    NNS_G3dGeBufferOP_N(0x1b, &nsKiller1->field0.mScale, 3);
    nsKiller1->field0.mMatrix.field0[3].x = nsKiller1->field0.mPos.x >> 4;
    nsKiller1->field0.mMatrix.field0[3].y = nsKiller1->field0.mPos.y >> 4;
    nsKiller1->field0.mMatrix.field0[3].z = nsKiller1->field0.mPos.z >> 4;
    NNS_G3dGeBufferOP_N(0x19, &nsKiller1->field0.mMatrix, 12);
    mobj_renderModel(a, nsk1_sModel, nsKiller1);
}

void nsk1_globalLogicInit(MapObjectList *mapObjectList) {
    s32 i;
    NsKiller1 *nsKiller1;

    if (mapObjectList == NULL) {
        return;
    }
    for (i = 0; i < mapObjectList->mMapObjectCount && (nsKiller1 = mapObjectList->mMapObjects[i]) != NULL; i++) {
        nsKiller1->mStateTimer = 0;
    }
}

void nsk1_update(void *a, NsKiller1 *nsKiller1) {
    Unk0210b7a8 s;

    switch (nsKiller1->mState) {
        case 0:
            if (nsKiller1->mStateTimer-- > 0) {
                return;
            }
            nsKiller1->mFollower.mSpeed = 0x2000;
            nsKiller1->mFollower.mProgressStep =
                ((s64) nsKiller1->mFollower.mPath->mSegments[nsKiller1->mFollower.mSegmentIndex].mInverseProgressLength
                 << 13) >>
                12;
            nsKiller1->mState = 1;
            break;
        case 1:
            if (pw_update(&nsKiller1->mFollower) != FALSE) {
                nsKiller1->mStateTimer = 0x2d;
                nsKiller1->mState = 2;
            }
            GetGroupFollowerLinearXz(&nsKiller1->mFollower, &nsKiller1->field0.mPos);
            break;
        case 2:
            if (nsKiller1->mStateTimer == 0x2d) {
                if ((nsKiller1->field0.mDistanceSquaredAndFlags & 4) == 0) {
                    NNS_SndPlayerStopSeq(GetSndHandleSlot(8), 0);
                    s = data_0216676c;
                    s.mPositionSource = &nsKiller1->field0.mPos;
                    s.mDistanceSquared = mobj_calcXZCamDist(&nsKiller1->field0.mPos);
                    sub_210B708(&s, GetSndHandleSlot(8));
                }
            } else if (nsKiller1->mStateTimer <= 0) {
                nsKiller1->mStateTimer = 0;
                nsKiller1->mState = 3;
            }
            nsKiller1->mStateTimer--;
            break;
        case 3:
            nsk2_spawn(&nsKiller1->field0.mPos, &nsKiller1->field0.mMatrix.field0[2], nsKiller1->field0.mAngle);
            if ((nsKiller1->field0.mFlags & 0x12) == 0) {
                ptcm_createEmitter(0x4b, &nsKiller1->field0.mPos);
                ptcm_createEmitter(0x4c, &nsKiller1->field0.mPos);
                ptcm_createEmitter(0x4d, &nsKiller1->field0.mPos);
            }
            nsKiller1->mStateTimer = 0x4b;
            nsKiller1->mState = 0;
            break;
    }
}

void nsk1_setupRenderPart(void) {
    mobj_createRenderPart3d(nsk1_loadModel, nsk1_render, NULL);
}

void nsk1_setupLogicPart(void) {
    mobj_createLogicPart(nsk1_globalLogicInit, nsk1_update, NULL);
}

void nsk2_init(NsKiller2 *nsKiller2) {
    nsKiller2->field0.mFlags |= data_021564b4;
    mobj_setInvisible(&nsKiller2->field0);
    nsKiller2->mSoundDistanceSquaredChange = mobj_initSoundEmitterExForObjectSfxParam2(&nsKiller2->field0);
    sfx_210B850(nsKiller2->mSoundDistanceSquaredChange);
    nsKiller2->field0.mSound->mSoundSource.mTrackParamsFunction = (void (*)(void *, void *, void *)) func_0210a6b4;
}

u8 nsk2_onDriverCollide(NsKiller2 *nsKiller2, Kart *kart, u8 *c, u8 *d) {
    u8 x;
    u8 v;

    x = *c;
    v = *d;
    if (x == 1) {
        nsKiller2->mParkTimer = 0x78;
        nsKiller2->mMode = 1;
        nsKiller2->field0.field10.x = ((s64) nsKiller2->field0.field10.x << 10) >> 12;
        nsKiller2->field0.field10.y = ((s64) nsKiller2->field0.field10.y << 10) >> 12;
        nsKiller2->field0.field10.z = ((s64) nsKiller2->field0.field10.z << 10) >> 12;
        nsKiller2->field0.field10.y = 0x4000;
        nsKiller2->field0.mFlags |= data_021564ac;
        if (kart->mItemEffect == 1 || kart->mItemEffect == 3) {
            nsKiller2->field0.mDistanceSquaredAndFlags |= data_021564b0;
        }
        mobj_tryDestroyByDriver(&nsKiller2->field0, kart);
    }
    return v;
}

void nsk2_loadModels(void *a) {
    nsk2_sModel = mobj_loadModel(a, aNskiller2_nsbm);
    nsk2_sShadowModel = mobj_loadShadowModel(a, aNskiller2_s_ns);
    mobj_setModelPolygonIdAll(nsk2_sShadowModel, 0x3f);
}

void nsk2_render(void *a, NsKiller2 *nsKiller2) {
    s32 t;
    s32 rotationMatrix[9];
    s32 angleIndex;

    if (nsKiller2->mParkTimer <= 0) {
        return;
    }
    t = 0x1e;
    NNS_G3dGeBufferOP_N(0x14, &t, 1);
    NNS_G3dGeBufferOP_N(0x19, bbm_20E6B58(&nsKiller2->field0.mPos), 12);
    angleIndex = nsKiller2->field0.mAngle >> 4;
    MTX_RotY33_(rotationMatrix, FX_SinCosTable_[angleIndex * 2], FX_SinCosTable_[angleIndex * 2 + 1]);
    NNS_G3dGeBufferOP_N(0x1a, rotationMatrix, 9);
    NNS_G3dGeBufferOP_N(0x1b, &nsKiller2->field0.mScale, 3);
    mobj_renderModel(a, nsk2_sShadowModel, nsKiller2);
    mobj_renderModel(a, nsk2_sModel, nsKiller2);
}

void nsk2_update(void *a, NsKiller2 *nsKiller2) {
    if ((driver_getClipAreaMask() & nsKiller2->field0.mDigitMask) != 0) {
        nsKiller2->field0.mFlags |= data_021564a8;
    } else {
        nsKiller2->field0.mFlags &= ~2;
    }
    switch (nsKiller2->mMode) {
        case 0:
            if (nsKiller2->mParkTimer-- > 0) {
                if ((nsKiller2->field0.mFlags & 2) == 0 && (nsKiller2->field0.mDistanceSquaredAndFlags & 8) != 0) {
                    AdvanceSoundDistanceSquaredChange(nsKiller2->mSoundDistanceSquaredChange,
                                                      nsKiller2->field0.mDistanceSquaredAndFlags & ~0xc000001f);
                } else {
                    AdvanceSoundDistanceSquaredChange(nsKiller2->mSoundDistanceSquaredChange,
                                                      mobj_calcXZCamDist(&nsKiller2->field0.mPos));
                }
                VEC_Add(&nsKiller2->field0.mPos, &nsKiller2->field0.field10, &nsKiller2->field0.mPos);
                if (nsKiller2->mParkTimer < 0x24e) {
                    mobj_emitSfxFromEmitter(&nsKiller2->field0, 0x17d);
                }
            } else {
                mobj_setInvisible(&nsKiller2->field0);
            }
            break;
        case 1:
            if (nsKiller2->mParkTimer-- > 0) {
                nsKiller2->field0.field10.y -= 0x400;
                VEC_Add(&nsKiller2->field0.mPos, &nsKiller2->field0.field10, &nsKiller2->field0.mPos);
            } else {
                mobj_setInvisible(&nsKiller2->field0);
            }
            break;
    }
}

void nsk2_setupConfig(void) {
    MapObjectKindData *o;

    o = mobj_createConfigEx(nsk2_onDriverCollide, NULL, NULL, 1, 1, 0x17b);
    o->field38 = 0x32000;
    o->field3C = -0x64000;
}

void nsk2_setupRenderPart(void) {
    mobj_createRenderPart3d(nsk2_loadModels, nsk2_render, NULL);
}

void nsk2_setupLogicPart(void) {
    mobj_createLogicPart(NULL, nsk2_update, NULL);
}

// Starts a parked NsKiller2 at a (raised), flying along b with angle c.
void nsk2_spawn(Vec3 *startPos, Vec3 *b, u16 angle) {
    NsKiller2 *nsKiller2;

    nsKiller2 = mobj_acquireFreeObject(mobj_getLogicPartForObjectId(MAP_OBJECT_KIND_NS_KILLER2));
    if (nsKiller2 == NULL) {
        return;
    }
    nsKiller2->mParkTimer = 600;
    nsKiller2->field0.mPos.x = startPos->x;
    nsKiller2->field0.mPos.y = startPos->y + 0x2a000;
    nsKiller2->field0.mPos.z = startPos->z;
    nsKiller2->field0.mMatrix.field0[2].x = b->x;
    nsKiller2->field0.mMatrix.field0[2].y = 0;
    nsKiller2->field0.mMatrix.field0[2].z = b->z;
    nsKiller2->field0.field10.x = ((s64) b->x * 0x6000) >> 12;
    nsKiller2->field0.field10.y = 0;
    nsKiller2->field0.field10.z = ((s64) b->z * 0x6000) >> 12;
    nsKiller2->field0.mAngle = angle;
    nsKiller2->mMode = 0;
}
