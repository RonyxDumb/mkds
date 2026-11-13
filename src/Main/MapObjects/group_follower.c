#include "Main/MapObjects/group_follower.h"
#include "Main/MapObjects/woodbox.h"

#include "Main/System/heap.h"
#include "Main/System/heap_call.h"
#include "Main/Race/race.h"
#include "Main/Kart/kart_drift.h"
#include "Main/Menu/choises_s.h"
#include "Main/MapObjects/view_frustum.h"
#include "Main/MapObjects/update_list_slot.h"
#include "Main/MapObjects/data_02156000.h"
#include "Main/Kart/code_0208fd8c.h"
#include "Main/Menu/second_menu_scene.h"
#include "Main/MapObjects/choropu.h"
#include "Main/Sound/data_0210b000.h"
#include "Main/MapObjects/data_0217b000.h"
#include "Main/Race/data_021759c0.h"
#include "tp.h"
#include "01/Race/mission_run_state.h"
#include "fx_mtx33.h"
#include "code_02147cd8.h"
#include "Main/MapObjects/code_020d6dc0.h"
#include "Main/MapObjects/group_paths.h"
#include "Main/MapObjects/group_follower_init.h"
#include "Main/MapObjects/group_follower_advance.h"
#include "code_02148538.h"
#include "registers.h"
#include "code_0201c528.h"
#include "Main/MapObjects/rock_kind_data.h"

const Vec3 gRockMatrixRow0 = {0x1000, 0, 0};
const Vec3 gRockMatrixRow1 = {0, 0x1000, 0};
const Vec3 gRockMatrixRow2 = {0, 0, 0x1000};
const struct MapObjectList gRockUpdateListData = {NULL, 0, {0, 0}, NULL, NULL, UpdateRock, NULL, 0, NULL, 0, NULL};
const struct RockDrawList gRock2DrawListData = {{NULL, 0, {0, 0}, (void (*)(MapObjectList *)) CreateRock2, (void (*)(MapObjectList *)) SetupDrawRock, DrawRock, NULL, 1, NULL, 0, NULL}, NULL, {{{{0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}}}}};
const struct RockDrawList gRockDrawListData = {{NULL, 0, {0, 0}, (void (*)(MapObjectList *)) CreateRock, (void (*)(MapObjectList *)) SetupDrawRock, DrawRock, NULL, 1, NULL, 0, NULL}, NULL, {{{{0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}}}}};
struct RockDrawList *gRockDrawList;
struct Nsbmd *gRock;
struct MapObjectList *gRockUpdateList;
struct Quaternion gViewYawQuaternion;
struct ShadowModel *gRockShadow;

RockDrawList *CreateRockDrawList(void) {
    RockDrawList *drawList = HeapAlloc(GetHeap(GetCurrentHeapCall()), 0x5c);
    gRockDrawList = drawList;
    *drawList = gRockDrawListData;
    SetDrawListSlot(&gRockDrawList);
    return gRockDrawList;
}

RockDrawList *CreateRock2DrawList(void) {
    RockDrawList *drawList = HeapAlloc(GetHeap(GetCurrentHeapCall()), 0x5c);
    gRockDrawList = drawList;
    *drawList = gRock2DrawListData;
    SetDrawListSlot(&gRockDrawList);
    return gRockDrawList;
}

MapObjectList *CreateRockUpdateList(void) {
    MapObjectList *updateList = HeapAlloc(GetHeap(GetCurrentHeapCall()), 0x28);
    gRockUpdateList = updateList;
    *updateList = gRockUpdateListData;
    SetUpdateListSlot(&gRockUpdateList);
    return gRockUpdateList;
}

void SetupDrawRock(void) {
    s32 pairIndex = (s32) (GetRaceUpdateFrames() << 25 >> 16) >> 4;
    MTX_RotY33_(&gRockDrawList->mShadowMatrix.mAxes, FX_SinCosTable_[pairIndex * 2],
                FX_SinCosTable_[pairIndex * 2 + 1]);
}

void DrawRock(void *unused0, RockObject *rock, void *unused1, s32 alpha) {
    Vec3 tiltAxis;
    Vec3 crossProduct;
    Vec3 xAxis;
    Vec3 yAxis;
    MtxFx43 *shadowMatrix;
    s32 dot;
    if (GetChoisesSOpenDuringRace() == 0) {
        xAxis = rock->mMapObject.mMatrix.mRows[0];
        yAxis = rock->mMapObject.mMatrix.mRows[1];
        tiltAxis.x = MUL_FIXED12_NO_ROUND(rock->mMapObject.mPosStep.z, rock->mBottomOffsetReciprocal);
        tiltAxis.z = -MUL_FIXED12_NO_ROUND(rock->mMapObject.mPosStep.x, rock->mBottomOffsetReciprocal);
        tiltAxis.y = 0;
        Vec3CrossUnrounded(&tiltAxis, &xAxis, &crossProduct);
        VEC_Add(&xAxis, &crossProduct, &xAxis);
        Vec3NormalizeAndGetLengthUnchecked(&xAxis, &rock->mMapObject.mMatrix.mRows[0]);
        Vec3CrossUnrounded(&tiltAxis, &yAxis, &crossProduct);
        VEC_Add(&yAxis, &crossProduct, &yAxis);
        dot = VEC_DotProduct(&rock->mMapObject.mMatrix.mRows[0], &yAxis);
        yAxis.x = yAxis.x - MUL_FIXED12_NO_ROUND(rock->mMapObject.mMatrix.mRows[0].x, dot);
        yAxis.y = yAxis.y - MUL_FIXED12_NO_ROUND(rock->mMapObject.mMatrix.mRows[0].y, dot);
        yAxis.z = yAxis.z - MUL_FIXED12_NO_ROUND(rock->mMapObject.mMatrix.mRows[0].z, dot);
        Vec3NormalizeAndGetLengthUnchecked(&yAxis, &rock->mMapObject.mMatrix.mRows[1]);
        Vec3CrossUnrounded(&rock->mMapObject.mMatrix.mRows[0], &rock->mMapObject.mMatrix.mRows[1],
                           &rock->mMapObject.mMatrix.mRows[2]);
    }
    rock->mMapObject.mMatrix.mRows[3].x = rock->mMapObject.mPos.x >> 4;
    rock->mMapObject.mMatrix.mRows[3].y = rock->mMapObject.mPos.y >> 4;
    rock->mMapObject.mMatrix.mRows[3].z = rock->mMapObject.mPos.z >> 4;
    DrawNsbmdWithMatrixAndMaxAlpha(gRock, &rock->mMapObject.mMatrix, &rock->mMapObject.mScale, alpha);
    shadowMatrix = &gRockDrawList->mShadowMatrix;
    shadowMatrix->mRows[3].x = rock->mMapObject.mPos.x >> 4;
    shadowMatrix->mRows[3].y = rock->mMapObject.mPos.y >> 4;
    shadowMatrix->mRows[3].z = rock->mMapObject.mPos.z >> 4;
    DrawShadowWithMaxAlpha(gRockShadow, &gRockDrawList->mShadowMatrix, &rock->mMapObject.mScale, alpha);
}

void CopyEmitterParams(ParticleEmitter *emitter, EmitterParams *params) {
    emitter->mRadius = params->mUnk_00;
    emitter->mDirectionSpeed = params->mUnk_04;
    emitter->mAxisSpeed = params->mUnk_06;
    emitter->mSizeScale = params->mUnk_08;
}
