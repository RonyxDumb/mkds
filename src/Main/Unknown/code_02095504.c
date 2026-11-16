#include "Main/Unknown/code_02095504.h"
#include "ITCM/code_01ff8000.h"
#include "ITCM/code_01ff9000.h"
#include "Main/Unknown/code_0209b634.h"
#include "code_02146d78.h"
#include "Main/Unknown/code_02042044.h"
#include "Main/Unknown/unk_021759c0.h"
#include "Main/Unknown/code_0209bf70.h"
#include "Main/Unknown/code_020f9c6c.h"
#include "Main/Unknown/unk_0217a000.h"
#include "Main/Unknown/code_02061654.h"
#include "Main/Unknown/code_0208d978.h"
#include "Main/Unknown/code_0209b000.h"
#include "Main/Unknown/code_0209bef0.h"
#include "Main/Unknown/code_020d4c28.h"
#include "Main/Unknown/code_020d8654.h"
#include "Main/Unknown/code_020d8cac.h"
#include "Main/Unknown/code_020e5668.h"
#include "Main/Unknown/code_020e6b58.h"
#include "Main/Unknown/code_020f36d8.h"
#include "Main/Unknown/code_0210b760.h"
#include "Main/Unknown/code_02146000.h"
#include "Main/Unknown/unk_0215d000.h"
#include "Main/Unknown/unk_02166000.h"
#include "Main/Unknown/unk_0217b000.h"
#include "Main/Unknown/unk_0217c000.h"
#include "code_02146cbc.h"
#include "code_02147cd8.h"
#include "code_02148538.h"
#include "Main/Unknown/code_02077bc0.h"

u8 mtree_onDriverCollide(MoveTree *moveTree, Kart *kart, u8 *c, u8 *d) {
    u8 v;

    v = *d;
    if (moveTree->mState <= 1) {
        moveTree->fieldA4 = 30;
    }
    return v;
}

void mtree_loadModel(void *a) {
    mtree_sModel = mobj_loadModel(a, aMove_tree_nsbm);
    mobj_loadNsbcaAnim(mtree_sModel, aMove_tree_nsbc);
    mobj_setModelPolygonIdAll(mtree_sModel, 0x3f);
}

void mtree_render(void *a, MoveTree *moveTree, u32 c, u32 d) {
    s32 t;

    t = 0x1e;
    NNS_G3dGeBufferOP_N(0x14, &t, 1);
    NNS_G3dGeBufferOP_N(0x19, bbm_getYBillboardAtPos(&moveTree->field0.mPos), 12);
    NNS_G3dGeBufferOP_N(0x1b, &moveTree->field0.mScale, 3);
    if ((s32) (moveTree->field0.mDistanceSquaredAndFlags & ~0xc000001f) < 0xc5c10) {
        mobj_setModelNsbcaFrame(mtree_sModel, moveTree->mNsbcaFrameIndex);
        mobj_renderModel(a, mtree_sModel, moveTree);
    } else {
        mobj_renderModel1Mat1Shp(a, mtree_sModel, moveTree);
    }
    if ((s32) (moveTree->field0.mDistanceSquaredAndFlags & ~0xc000001f) >= 0x27100) {
        return;
    }
    oshd_setPositionXZ(&moveTree->fieldDC, &moveTree->field0.mPos);
    oshd_renderMat(&moveTree->fieldDC, NULL, c, d);
}

void mtree_globalLogicInit(MapObjectList *mapObjectList) {
    s32 i;
    MoveTree *moveTree;

    if (mapObjectList == NULL) {
        return;
    }
    for (i = 0; i < mapObjectList->mMapObjectCount && (moveTree = mapObjectList->mMapObjects[i]) != NULL; i++) {
        moveTree->fieldA8 = (moveTree->field0.mCourseMapRow->field28 << 12) / 100;
        oshd_setParams(&moveTree->fieldDC, &moveTree->field0.mPos, 0x54666, 14);
    }
}

void mtree_update(void *a, MoveTree *moveTree) {
    Unk0210b7a8 s1;
    Unk0210b7a8 s2;
    u32 k;
    s32 speed;

    switch (moveTree->mState) {
        case 0:
            moveTree->mFollower.mSpeed = 0;
            moveTree->mFollower.mProgressStep = 0;
            if (moveTree->mState0Timer-- <= 0) {
                moveTree->mState = 1;
            }
            if ((s32) (moveTree->field0.mDistanceSquaredAndFlags & ~0xc000001f) >= 0xc5c10) {
                return;
            }
            if (moveTree->fieldA4-- > 0) {
                moveTree->mNsbcaFrameStep = 2;
                moveTree->mNsbcaFrameIndex += moveTree->mNsbcaFrameStep;
                if (moveTree->mNsbcaFrameIndex >= mobj_getModelNsbcaFrameCount(mtree_sModel)) {
                    moveTree->mNsbcaFrameIndex = 0;
                }
                return;
            }
            if (moveTree->mNsbcaFrameIndex == 0) {
                return;
            }
            moveTree->mNsbcaFrameIndex += moveTree->mNsbcaFrameStep;
            if (moveTree->mNsbcaFrameIndex >= mobj_getModelNsbcaFrameCount(mtree_sModel)) {
                moveTree->mNsbcaFrameIndex = 0;
            }
            if (moveTree->mNsbcaFrameIndex != 0 && moveTree->mNsbcaFrameIndex != 0x1e) {
                return;
            }
            if ((moveTree->field0.mDistanceSquaredAndFlags & 4) != 0) {
                return;
            }
            if (moveTree->field0.mFarDistanceSquared == gSfxParams[2].field20) {
                k = 2;
            } else if (moveTree->field0.mFarDistanceSquared == gSfxParams[3].field20) {
                k = 3;
            } else {
                k = 4;
            }
            s1.mSoundId = 0x11f;
            s1.mPositionSource = &moveTree->field0.mPos;
            s1.field8 = k;
            s1.mDistanceSquared = mobj_calcXZCamDist(&moveTree->field0.mPos);
            sub_210B7A8(&s1);
            break;
        case 1:
            speed = moveTree->fieldA8;
            moveTree->mFollower.mSpeed = speed;
            moveTree->mFollower.mProgressStep =
                ((s64) speed *
                 moveTree->mFollower.mPath->mSegments[moveTree->mFollower.mSegmentIndex].mInverseProgressLength) >>
                12;
            if (pw_update(&moveTree->mFollower) != FALSE) {
                moveTree->mState0Timer = (u16) moveTree->mFollower.mFromEntry->fieldE;
                moveTree->mState = 0;
            }
            GetGroupFollowerLinearXz(&moveTree->mFollower, &moveTree->field0.mPos);
            if ((s32) (moveTree->field0.mDistanceSquaredAndFlags & ~0xc000001f) >= 0xc5c10) {
                return;
            }
            if (moveTree->fieldA4-- > 0) {
                moveTree->mNsbcaFrameStep = 2;
            } else {
                moveTree->mNsbcaFrameStep = 1;
            }
            moveTree->mNsbcaFrameIndex += moveTree->mNsbcaFrameStep;
            if (moveTree->mNsbcaFrameIndex >= mobj_getModelNsbcaFrameCount(mtree_sModel)) {
                moveTree->mNsbcaFrameIndex = 0;
            }
            if (moveTree->mNsbcaFrameIndex != 0 && moveTree->mNsbcaFrameIndex != 0x1e) {
                return;
            }
            if ((moveTree->field0.mDistanceSquaredAndFlags & 4) != 0) {
                return;
            }
            if (moveTree->field0.mFarDistanceSquared == gSfxParams[2].field20) {
                k = 2;
            } else if (moveTree->field0.mFarDistanceSquared == gSfxParams[3].field20) {
                k = 3;
            } else {
                k = 4;
            }
            s2.mSoundId = 0x11f;
            s2.mPositionSource = &moveTree->field0.mPos;
            s2.field8 = k;
            s2.mDistanceSquared = mobj_calcXZCamDist(&moveTree->field0.mPos);
            sub_210B7A8(&s2);
    }
}

void mtree_setupConfig(void) {
    mobj_createConfigEx(mtree_onDriverCollide, NULL, NULL, 2, 1, 0x125);
}

void mtree_setupRenderPart(void) {
    mobj_createRenderPart3d(mtree_loadModel, mtree_render, NULL);
}

void mtree_setupLogicPart(void) {
    mobj_createLogicPart(mtree_globalLogicInit, mtree_update, NULL);
}

void baku_loadModels(void *a) {
    baku_sModel = mobj_loadModel(a, aBakubaku_nsbmd);
    baku_sShadowModel = mobj_loadShadowModel(a, aBaku_shadow_nsbmd);
    mobj_setModelPolygonIdAll(baku_sModel, 0x3f);
    mobj_setModelPolygonIdAll(baku_sShadowModel, 0x3f);
}

void baku_render(void *a, Bakubaku *bakubaku) {
    s32 t;
    s32 m[9];
    s32 i;

    if (bakubaku->mState != 2) {
        return;
    }
    t = 0x1e;
    NNS_G3dGeBufferOP_N(0x14, &t, 1);
    bakubaku->field0.mMatrix.field0[3].x = bakubaku->field0.mPos.x >> 4;
    bakubaku->field0.mMatrix.field0[3].y = bakubaku->field0.mPos.y >> 4;
    bakubaku->field0.mMatrix.field0[3].z = bakubaku->field0.mPos.z >> 4;
    NNS_G3dGeBufferOP_N(0x19, &bakubaku->field0.mMatrix, 12);
    NNS_G3dGeBufferOP_N(0x1b, &bakubaku->field0.mScale, 3);
    mobj_renderModel(a, baku_sShadowModel, bakubaku);
    i = (u16) (u32) FX_Atan2Idx(-bakubaku->field0.field10.y, 0xc000) >> 4;
    MTX_RotX33_(m, FX_SinCosTable_[i * 2], FX_SinCosTable_[i * 2 + 1]);
    NNS_G3dGeBufferOP_N(0x1a, m, 9);
    mobj_renderModel(a, baku_sModel, bakubaku);
}

void baku_globalLogicInit(MapObjectList *mapObjectList) {
    s32 i;
    Bakubaku *bakubaku;

    if (mapObjectList == NULL) {
        return;
    }
    for (i = 0; i < mapObjectList->mMapObjectCount && (bakubaku = mapObjectList->mMapObjects[i]) != NULL; i++) {
        VEC_MultAdd(0x320000, &bakubaku->field0.mMatrix.field0[2], &bakubaku->field0.mCourseMapRow->field0,
                    &bakubaku->fieldA4);
    }
}

void baku_update(void *a, Bakubaku *bakubaku) {
    Unk0210b7a8 s1;
    Unk0210b7a8 s2;
    Kart *kart;
    Vec3 *kartPos;
    s64 distanceSquared;
    s32 deltaZ;
    s32 deltaX;

    switch (bakubaku->mState) {
        case 0:
            if (race_getCameraField250() != 2) {
                kart = driver_getById((u16) gRaceMultiConfig->mEntryIndex);
                kartPos = &kart->mPos;
                deltaX = kartPos->x - bakubaku->fieldA4.x;
                deltaZ = kartPos->z - bakubaku->fieldA4.z;
                distanceSquared = (s64) deltaX * deltaX + (s64) deltaZ * deltaZ;
                if (distanceSquared >= (s64) 0x9c4 << 32) {
                    return;
                }
            }
            bakubaku->field0.mPos.x = bakubaku->field0.mCourseMapRow->field0.x;
            bakubaku->field0.mPos.y = bakubaku->field0.mCourseMapRow->field0.y - 0x32000;
            bakubaku->field0.mPos.z = bakubaku->field0.mCourseMapRow->field0.z;
            bakubaku->field0.field10.x = ((s64) bakubaku->field0.mMatrix.field0[2].x * 0xc000) >> 12;
            bakubaku->field0.field10.y = 0xc000;
            bakubaku->field0.field10.z = ((s64) bakubaku->field0.mMatrix.field0[2].z * 0xc000) >> 12;
            bakubaku->mState = 1;
            break;
        case 1:
            bakubaku->field0.field10.y -= 0x400;
            VEC_Add(&bakubaku->field0.mPos, &bakubaku->field0.field10, &bakubaku->field0.mPos);
            if (bakubaku->field0.mPos.y < bakubaku->field0.mCourseMapRow->field0.y) {
                return;
            }
            expl_spawnEffect(3, &bakubaku->field0.mPos, 1);
            s1.mSoundId = 0x186;
            s1.mPositionSource = &bakubaku->field0.mPos;
            s1.field8 = 4;
            s1.mDistanceSquared = mobj_calcXZCamDist(&bakubaku->field0.mPos);
            sub_210B7A8(&s1);
            bakubaku->mState = 2;
            break;
        case 2:
            bakubaku->field0.field10.y -= 0x400;
            VEC_Add(&bakubaku->field0.mPos, &bakubaku->field0.field10, &bakubaku->field0.mPos);
            if (bakubaku->field0.mPos.y > bakubaku->field0.mCourseMapRow->field0.y) {
                return;
            }
            expl_spawnEffect(3, &bakubaku->field0.mPos, 1);
            s2.mSoundId = 0x187;
            s2.mPositionSource = &bakubaku->field0.mPos;
            s2.field8 = 2;
            s2.mDistanceSquared = mobj_calcXZCamDist(&bakubaku->field0.mPos);
            sub_210B7A8(&s2);
            bakubaku->mState = 3;
            break;
        case 3:
            bakubaku->field0.field10.y -= 0x400;
            VEC_Add(&bakubaku->field0.mPos, &bakubaku->field0.field10, &bakubaku->field0.mPos);
            if (bakubaku->field0.mPos.y <= bakubaku->field0.mCourseMapRow->field0.y - 0x32000) {
                bakubaku->mState4Timer = 0x708;
                bakubaku->mState = 4;
            }
            break;
        case 4:
            if (bakubaku->mState4Timer-- <= 0) {
                bakubaku->mState = 0;
            }
            break;
    }
}

void baku_setupRenderPart(void) {
    mobj_createRenderPart3d(baku_loadModels, baku_render, NULL);
}

void baku_setupLogicPart(void) {
    mobj_createLogicPart(baku_globalLogicInit, baku_update, NULL);
}
