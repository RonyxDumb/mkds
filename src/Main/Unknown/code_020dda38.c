#include "Main/Unknown/code_020dda38.h"
#include "Main/Unknown/code_020d3b10.h"

#include "Main/Unknown/code_020dda2c.h"
#include "Main/Unknown/code_020d2000.h"
#include "Main/Unknown/code_020d3000.h"
#include "Main/Unknown/code_020e5d0c.h"
#include "Main/Unknown/code_020e6a74.h"
#include "Main/Unknown/code_020e6b58.h"
#include "Main/Unknown/code_02047000.h"
#include "Main/Unknown/code_0205e000.h"
#include "Main/Unknown/unk_02164000.h"
#include "Main/Unknown/code_02047104.h"
#include "Main/Unknown/code_02039860.h"
#include "code_02147cd8.h"
#include "Main/Unknown/unk_0217b000.h"
#include "Main/Unknown/code_020de204.h"

u32 wwchn_onDriverCollide(u32 unused0, u32 unused1, u32 unused2, u32 bytePointer) {
    return (*OFFSET_PTR(const u8, bytePointer, 0));
}

u32 wwchn_onItemCollide(u32 unused0, u32 unused1, u32 unused2, u32 bytePointer) {
    return (*OFFSET_PTR(const u8, bytePointer, 0));
}

const u16 data_021583d4 = 1;

void ResetWanwanChainPoints(WanwanChainObject *chainObject) {
    Wanwan *wanwan;
    Vec3 startPoint;
    Vec3 endPoint;

    wanwan = chainObject->mWanwan;
    VEC_MultAdd(-wanwan->fieldF0, &wanwan->field0.mMatrix.field0[2], &wanwan->field0.mPos, &endPoint);
    startPoint = wanwan->mCenterPos;
    startPoint.y -= wanwan->fieldF0 >> 1;
    SetWanwanChainPointsEvenly(&chainObject->mChain, &startPoint, &endPoint);
    if (chainObject->mHasKui != FALSE) {
        return;
    }
    sub_20DDA2C(&chainObject->mChain);
}

#pragma thumb on

void wwchn_loadModels(void) {
    void *kuiFile;

    bbm_createFromNsbmd(&wwchn_sChainModel, mobj_getMapObjFile("wanwan_chain.nsbmd"), 0, 0);
    bbm_setDefaultMatParams(wwchn_sChainModel);
    kuiFile = arc_getCourseArcFile("MapObj/wanwan_kui.nsbmd");
    if (kuiFile != NULL) {
        bbm_createFromNsbmd(&wwchn_sKuiModel, kuiFile, 0, 0);
        bbm_setDefaultMatParams(wwchn_sKuiModel);
    }
}

void wwchn_init(WanwanChainObject *chainObject, void *unused, Wanwan *wanwan) {
    s32 d;

    chainObject->mPos = wanwan->mCenterPos;
    chainObject->mHasKui = wanwan->fieldFC == 0;
    if (chainObject->mHasKui != FALSE) {
        d = wanwan->mMaxRadius;
    } else {
        d = 0x55000;
    }
    InitWanwanChain(&chainObject->mChain, &chainObject->mPos, &chainObject->mPos, d - wanwan->fieldF0,
                    wanwan->fieldFC != 0 ? 4 : 7, 0x6000, &chainObject->field1C);
    if (chainObject->mHasKui == FALSE) {
        sub_20DDA2C(&chainObject->mChain);
        chainObject->mChain.mDownwardStep -= 0xcd;
        chainObject->mChain.field10 -= 0x3d;
        chainObject->mChain.field14.x += 0x52;
        chainObject->mChain.field14.y += 0x35c;
        chainObject->mChain.field14.z += 0x52;
        chainObject->mChain.mMinY = 0;
        chainObject->field2 |= data_021583d4;
    }
    chainObject->mWanwan = wanwan;
    if (chainObject->mHasKui != FALSE) {
        d = wanwan->fieldF8;
    } else {
        d = 0xc8000;
    }
    chainObject->field68 = 1.2f * (d + wanwan->fieldF0);
}

#pragma thumb off

void UpdateWanwanChainPoints(WanwanChain *chain, Vec3 *endPoint, Vec3 *unused) {
    Vec3 *velocities;
    s32 pointCount;
    s32 reversePointIndex;
    s32 pullIndex;
    s32 minY;
    Vec3 *points;
    s32 downwardStep;
    s32 damping;
    Vec3 t;
    Vec3 offset;
    Vec3 pullScale;
    Vec3 *current;
    s32 pointIndex;
    s32 linkLength;
    s32 weight;
    s32 excess;
    s64 excessSquared;

    velocities = chain->mVelocities;
    pointCount = chain->mPointCount;
    minY = chain->mMinY;
    points = chain->mPoints;
    downwardStep = chain->mDownwardStep;
    damping = chain->field10;
    pullScale = chain->field14;
    reversePointIndex = pointCount - 1;
    for (pointIndex = 1; pointIndex < pointCount; pointIndex++) {
        velocities[pointIndex].y -= downwardStep;
    }
    for (pointIndex = 1; pointIndex < pointCount; pointIndex++) {
        VEC_MultAdd((pointCount - pointIndex) * -damping, &velocities[pointIndex], &velocities[pointIndex],
                    &velocities[pointIndex]);
    }
    for (pointIndex = 1; pointIndex < pointCount; pointIndex++) {
        VEC_Add(&points[pointIndex], &velocities[pointIndex], &points[pointIndex]);
    }
    current = &points[reversePointIndex];
    *current = *endPoint;
    for (; reversePointIndex > 1; reversePointIndex--) {
        VEC_Subtract(&points[reversePointIndex - 1], current, &t);
        excessSquared = (s64) t.x * t.x + (s64) t.y * t.y + (s64) t.z * t.z - chain->mLinkLengthSquared;
        excess = excessSquared < 0 ? 0 : (s32) (excessSquared >> 12);
        if (excess != 0) {
            vec_normalize(&t, &offset);
            linkLength = chain->mLinkLength;
            offset.x = ((s64) offset.x * linkLength) >> 12;
            offset.y = ((s64) offset.y * linkLength) >> 12;
            offset.z = ((s64) offset.z * linkLength) >> 12;
            VEC_Add(current, &offset, &points[reversePointIndex - 1]);
            VEC_Subtract(&offset, &t, &t);
            t.x = ((s64) t.x * pullScale.x) >> 12;
            t.y = ((s64) t.y * pullScale.y) >> 12;
            t.z = ((s64) t.z * pullScale.z) >> 12;
            weight = chain->mStepFraction * reversePointIndex;
            t.x = ((s64) t.x * weight) >> 12;
            t.y = ((s64) t.y * weight) >> 12;
            t.z = ((s64) t.z * weight) >> 12;
            VEC_Add(&velocities[reversePointIndex - 1], &t, &velocities[reversePointIndex - 1]);
        }
        current--;
    }
    if (chain->field8 != 0) {
        pullIndex = 1;
    } else {
        pullIndex = 2;
    }
    for (; pullIndex < pointCount; pullIndex++) {
        VEC_Subtract(&points[pullIndex], &points[pullIndex - 1], &t);
        excessSquared = (s64) t.x * t.x + (s64) t.y * t.y + (s64) t.z * t.z - chain->mLinkLengthSquared;
        excess = excessSquared < 0 ? 0 : (s32) (excessSquared >> 12);
        if (excess != 0) {
            vec_normalize(&t, &offset);
            linkLength = chain->mLinkLength;
            offset.x = ((s64) offset.x * linkLength) >> 12;
            offset.y = ((s64) offset.y * linkLength) >> 12;
            offset.z = ((s64) offset.z * linkLength) >> 12;
            VEC_Add(&points[pullIndex - 1], &offset, &points[pullIndex]);
        }
    }
    for (pointIndex = 1; pointIndex < pointCount - 2; pointIndex++) {
        if (points[pointIndex].y - minY < 0) {
            points[pointIndex].y = minY;
            if (velocities[pointIndex].y < 0) {
                velocities[pointIndex].y = 0;
            }
            velocities[pointIndex].x = velocities[pointIndex].x * 7 >> 3;
            velocities[pointIndex].z = velocities[pointIndex].z * 7 >> 3;
        }
    }
}

void DrawWanwanChainLinks(WanwanChain *chain, NsbmdModel *model, s32 unused, u16 e) {
    s32 pointIndex;
    u32 polygonId;

    bbm_applyMaterial(model);
    for (pointIndex = 1; pointIndex < chain->mPointCount; pointIndex++) {
        polygonId = mobj_getCyclicPolygonId();
        model->field14 &= ~0x3f000000;
        model->field14 |= polygonId << 24;
        bbm_renderTransformedScaled(model, bbm_getBillboardAtPos(&chain->mPoints[pointIndex]), &chain->field34, 1, e);
    }
}

void DrawWanwanChainKui(WanwanChain *chain, NsbmdModel *model, Vec3 *position, s32 unused, u16 e) {
    u32 polygonId;

    bbm_applyMaterial(model);
    polygonId = mobj_getCyclicPolygonId();
    model->field14 &= ~0x3f000000;
    model->field14 |= polygonId << 24;
    bbm_renderTransformedScaled(model, bbm_getYBillboardAtPos(position), &chain->field34, 1, e);
}
