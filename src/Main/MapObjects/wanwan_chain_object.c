#include "Main/MapObjects/wanwan_chain_object.h"
#include "Main/MapObjects/view_frustum.h"

#include "Main/MapObjects/wanwan_chain_flag.h"
#include "Main/Item/pooled_map_object.h"
#include "Main/Item/item_in_use.h"
#include "matrix_3x3_basic.h"
#include "Main/MapObjects/attractor.h"
#include "Main/Item/item_objects_and_race_progress.h"
#include "Main/MapObjects/does_map_object.h"
#include "Main/MapObjects/map_object_sound.h"
#include "Main/MapObjects/while_requested_full_volume_wrapper.h"
#include "Main/MapObjects/map_object_park.h"
#include "Main/MapObjects/sound_if_kart_star_or.h"
#include "Main/MapObjects/map_object_scale_sound_source.h"
#include "Main/MapObjects/map_object_list.h"
#include "Main/MapObjects/map_object.h"
#include "Main/MapObjects/pendulum.h"
#include "Main/MapObjects/view_matrix_queue.h"
#include "Main/MapObjects/view_matrix_setters.h"
#include "Main/Scene/display_settings.h"
#include "archive_memory_load.h"
#include "heap_frame_allocator.h"
#include "thread_scheduler.h"
#include "power_management_commands.h"
#include "Main/Sound/sound_seq.h"
#include "Main/System/result_archive_path.h"
#include "vector_math.h"
#include "Main/Race/race_hud_keyboard_map_object_work.h"
#include "Main/MapObjects/wanwan_chain.h"

const MapObjectKindDescriptor gWanwanChainKindDescriptor = {0,
                                                            {0, 0},
                                                            0xf8,
                                                            InitWanwanChainObject,
                                                            CreateWanwanChainKindData,
                                                            (MapObjectList * (*) (void) ) CreateWanwanChainDrawList,
                                                            NULL,
                                                            NULL,
                                                            CreateWanwanChainUpdateList,
                                                            NULL,
                                                            {NULL, NULL, NULL, NULL}};

u32 CollideKartWithWanwanChain(u32 unused0, u32 unused1, u32 unused2, const u8 *bytePointer) {
    return *bytePointer;
}

u32 CollideItemObjectWithWanwanChain(u32 unused0, u32 unused1, u32 unused2, const u8 *bytePointer) {
    return *bytePointer;
}

const u16 gWanwanChainMapObjectFlag = 1;

void ResetWanwanChainPoints(WanwanChainObject *chainObject) {
    Wanwan *wanwan;
    Vec3 startPoint;
    Vec3 endPoint;

    wanwan = chainObject->mWanwan;
    VEC_MultAdd(-wanwan->mScaledLength, &wanwan->mMapObject.mMatrix.mRows[2], &wanwan->mMapObject.mPos, &endPoint);
    startPoint = wanwan->mCenterPos;
    startPoint.y -= wanwan->mScaledLength >> 1;
    SetWanwanChainPointsEvenly(&chainObject->mChain, &startPoint, &endPoint);
    if (chainObject->mHasKui != FALSE) {
        return;
    }
    ClearWanwanChainFirstLinkFlag(&chainObject->mChain);
}

#pragma thumb on

void CreateWanwanChainAndWanwanKui(void) {
    void *kuiFile;

    CreateNsbmdModel(&gWanwanChain, FindCourseMapObjFile("wanwan_chain.nsbmd"), 0, 0);
    SetNsbmdModelFixedAttributes(gWanwanChain);
    kuiFile = FindCourseFile("MapObj/wanwan_kui.nsbmd");
    if (kuiFile != NULL) {
        CreateNsbmdModel(&gWanwanKui, kuiFile, 0, 0);
        SetNsbmdModelFixedAttributes(gWanwanKui);
    }
}

void InitWanwanChainObject(WanwanChainObject *chainObject, void *unused, Wanwan *wanwan) {
    s32 distance;

    chainObject->mPos = wanwan->mCenterPos;
    chainObject->mHasKui = wanwan->mFollowsPath == 0;
    if (chainObject->mHasKui != FALSE) {
        distance = wanwan->mMaxRadius;
    } else {
        distance = 0x55000;
    }
    InitWanwanChain(&chainObject->mChain, &chainObject->mPos, &chainObject->mPos, distance - wanwan->mScaledLength,
                    wanwan->mFollowsPath != 0 ? 4 : 7, 0x6000, &chainObject->mScale);
    if (chainObject->mHasKui == FALSE) {
        ClearWanwanChainFirstLinkFlag(&chainObject->mChain);
        chainObject->mChain.mDownwardStep -= 0xcd;
        chainObject->mChain.mDamping -= 0x3d;
        chainObject->mChain.mPullScale.x += 0x52;
        chainObject->mChain.mPullScale.y += 0x35c;
        chainObject->mChain.mPullScale.z += 0x52;
        chainObject->mChain.mMinY = 0;
        chainObject->mFlags |= gWanwanChainMapObjectFlag;
    }
    chainObject->mWanwan = wanwan;
    if (chainObject->mHasKui != FALSE) {
        distance = wanwan->mRadiusLimit;
    } else {
        distance = 0xc8000;
    }
    chainObject->mViewRadius = 1.2f * (distance + wanwan->mScaledLength);
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
    Vec3 delta;
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
    damping = chain->mDamping;
    pullScale = chain->mPullScale;
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
        VEC_Subtract(&points[reversePointIndex - 1], current, &delta);
        excessSquared =
            SQUARE_SUM3(delta.x, delta.y, delta.z) - chain->mLinkLengthSquared;
        excess = excessSquared < 0 ? 0 : (s32) FROM_FIXED12(excessSquared);
        if (excess != 0) {
            Vec3NormalizeAndGetLengthUnchecked(&delta, &offset);
            linkLength = chain->mLinkLength;
            offset.x = MUL_FIXED12_NO_ROUND(offset.x, linkLength);
            offset.y = MUL_FIXED12_NO_ROUND(offset.y, linkLength);
            offset.z = MUL_FIXED12_NO_ROUND(offset.z, linkLength);
            VEC_Add(current, &offset, &points[reversePointIndex - 1]);
            VEC_Subtract(&offset, &delta, &delta);
            delta.x = MUL_FIXED12_NO_ROUND(delta.x, pullScale.x);
            delta.y = MUL_FIXED12_NO_ROUND(delta.y, pullScale.y);
            delta.z = MUL_FIXED12_NO_ROUND(delta.z, pullScale.z);
            weight = chain->mStepFraction * reversePointIndex;
            delta.x = MUL_FIXED12_NO_ROUND(delta.x, weight);
            delta.y = MUL_FIXED12_NO_ROUND(delta.y, weight);
            delta.z = MUL_FIXED12_NO_ROUND(delta.z, weight);
            VEC_Add(&velocities[reversePointIndex - 1], &delta, &velocities[reversePointIndex - 1]);
        }
        current--;
    }
    if (chain->mFirstLinkConstrained != 0) {
        pullIndex = 1;
    } else {
        pullIndex = 2;
    }
    for (; pullIndex < pointCount; pullIndex++) {
        VEC_Subtract(&points[pullIndex], &points[pullIndex - 1], &delta);
        excessSquared =
            SQUARE_SUM3(delta.x, delta.y, delta.z) - chain->mLinkLengthSquared;
        excess = excessSquared < 0 ? 0 : (s32) FROM_FIXED12(excessSquared);
        if (excess != 0) {
            Vec3NormalizeAndGetLengthUnchecked(&delta, &offset);
            linkLength = chain->mLinkLength;
            offset.x = MUL_FIXED12_NO_ROUND(offset.x, linkLength);
            offset.y = MUL_FIXED12_NO_ROUND(offset.y, linkLength);
            offset.z = MUL_FIXED12_NO_ROUND(offset.z, linkLength);
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

void DrawWanwanChainLinks(WanwanChain *chain, NsbmdModel *model, s32 unused, u16 maxAlpha) {
    s32 pointIndex;
    u32 polygonId;

    QueueNsbmdModelMaterial(model);
    for (pointIndex = 1; pointIndex < chain->mPointCount; pointIndex++) {
        polygonId = AllocPolygonIdWrapping();
        model->mPolygonAttributes &= ~0x3f000000;
        model->mPolygonAttributes |= polygonId << 24;
        DrawNsbmdModelWithMatrixAndMaxAlpha(model, SetViewTransposeMatrixPos(&chain->mPoints[pointIndex]),
                                            &chain->mModelScale, 1, maxAlpha);
    }
}

void DrawWanwanChainKui(WanwanChain *chain, NsbmdModel *model, Vec3 *position, s32 unused, u16 maxAlpha) {
    u32 polygonId;

    QueueNsbmdModelMaterial(model);
    polygonId = AllocPolygonIdWrapping();
    model->mPolygonAttributes &= ~0x3f000000;
    model->mPolygonAttributes |= polygonId << 24;
    DrawNsbmdModelWithMatrixAndMaxAlpha(model, SetViewRotatedMatrixPos(position), &chain->mModelScale, 1, maxAlpha);
}
