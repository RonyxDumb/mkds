#include "Main/MapObjects/group_follower.h"
#include "Main/MapObjects/woodbox.h"

#include "Main/System/heap.h"
#include "Main/System/heap_call.h"
#include "Main/Race/race.h"
#include "Main/Kart/kart_drift.h"
#include "Main/Menu/choises_s.h"
#include "Main/MapObjects/view_frustum.h"
#include "Main/MapObjects/update_list_slot.h"
#include "Main/Menu/keyboard_cursor_targets.h"
#include "Main/Kart/kart_ai_item_use.h"
#include "Main/Menu/second_menu_scene.h"
#include "Main/MapObjects/choropu.h"
#include "Main/Sound/sound_distance_squared_change.h"
#include "Main/Race/race_hud_keyboard_map_object_work.h"
#include "Main/Race/race_setup_block.h"
#include "touch_panel_sampling.h"
#include "01/Race/mission_run_state.h"
#include "matrix_3x3_basic.h"
#include "fixed_vector_math.h"
#include "Main/MapObjects/map_object_response_and_quaternion_math.h"
#include "Main/MapObjects/group_paths.h"
#include "Main/MapObjects/group_follower_init.h"
#include "Main/MapObjects/group_follower_advance.h"
#include "fixed_arctangent.h"
#include "registers.h"
#include "particle_instance.h"
#include "Main/MapObjects/rock_kind_data.h"

const Vec3 gRockMatrixRow0 = {0x1000, 0, 0};
const Vec3 gRockMatrixRow1 = {0, 0x1000, 0};
const Vec3 gRockMatrixRow2 = {0, 0, 0x1000};
const struct MapObjectList gRockUpdateListData = {NULL, 0, {0, 0}, NULL, NULL, UpdateRock, NULL, 0, NULL, 0, NULL};
const struct RockDrawList gRock2DrawListData = {{NULL,
                                                 0,
                                                 {0, 0},
                                                 (void (*)(MapObjectList *)) CreateRock2,
                                                 (void (*)(MapObjectList *)) SetupDrawRock,
                                                 DrawRock,
                                                 NULL,
                                                 1,
                                                 NULL,
                                                 0,
                                                 NULL},
                                                NULL,
                                                {{{{0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}}}}};
const struct RockDrawList gRockDrawListData = {{NULL,
                                                0,
                                                {0, 0},
                                                (void (*)(MapObjectList *)) CreateRock,
                                                (void (*)(MapObjectList *)) SetupDrawRock,
                                                DrawRock,
                                                NULL,
                                                1,
                                                NULL,
                                                0,
                                                NULL},
                                               NULL,
                                               {{{{0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}}}}};
struct RockDrawList *gRockDrawList;
struct Nsbmd *gRock;
struct MapObjectList *gRockUpdateList;
struct Quaternion gViewYawQuaternion;
struct ShadowModel *gRockShadow;

MapObjectList *CreateRockDrawList(void) {
    RockDrawList *drawList = Mem_AllocateHeap(ExecutionContext_GetHeapHandle(GetActiveExecutionContext()), sizeof(RockDrawList));
    gRockDrawList = drawList;
    *drawList = gRockDrawListData;
    SetDrawListSlot(&gRockDrawList);
    return &gRockDrawList->mMapObjectList;
}

MapObjectList *CreateRock2DrawList(void) {
    RockDrawList *drawList = Mem_AllocateHeap(ExecutionContext_GetHeapHandle(GetActiveExecutionContext()), sizeof(RockDrawList));
    gRockDrawList = drawList;
    *drawList = gRock2DrawListData;
    SetDrawListSlot(&gRockDrawList);
    return &gRockDrawList->mMapObjectList;
}

MapObjectList *CreateRockUpdateList(void) {
    MapObjectList *updateList = Mem_AllocateHeap(ExecutionContext_GetHeapHandle(GetActiveExecutionContext()), sizeof(MapObjectList));
    gRockUpdateList = updateList;
    *updateList = gRockUpdateListData;
    SetUpdateListSlot(&gRockUpdateList);
    return gRockUpdateList;
}

void SetupDrawRock(void) {
    s32 pairIndex = (s32) (GetSomeTimeOrDuration() << 25 >> 16) >> 4;
    MTX_RotY33__from_thumb(&gRockDrawList->mShadowMatrix.mAxes, g_SinFx16Table_AndCos[pairIndex * 2],
                g_SinFx16Table_AndCos[pairIndex * 2 + 1]);
}

void DrawRock(void *unused0, RockObject *rock, void *unused1, s32 alpha) {
    Vec3 tiltAxis;
    Vec3 crossProduct;
    Vec3 xAxis;
    Vec3 yAxis;
    MtxFx43 *shadowMatrix;
    s32 dot;
    if (IsRaceOptionMenuOn_from_thumb() == 0) {
        xAxis = rock->mMapObject.mMatrix.mRows[0];
        yAxis = rock->mMapObject.mMatrix.mRows[1];
        tiltAxis.x = MUL_FIXED12_NO_ROUND(rock->mMapObject.mPosStep.z, rock->mBottomOffsetReciprocal);
        tiltAxis.z = -MUL_FIXED12_NO_ROUND(rock->mMapObject.mPosStep.x, rock->mBottomOffsetReciprocal);
        tiltAxis.y = 0;
        Vector3_Cross(&tiltAxis, &xAxis, &crossProduct);
        VecFx32_Add(&xAxis, &crossProduct, &xAxis);
        Vector3_MaybeNormalize(&xAxis, &rock->mMapObject.mMatrix.mRows[0]);
        Vector3_Cross(&tiltAxis, &yAxis, &crossProduct);
        VecFx32_Add(&yAxis, &crossProduct, &yAxis);
        dot = Vector3_DotProduct(&rock->mMapObject.mMatrix.mRows[0], &yAxis);
        yAxis.x = yAxis.x - MUL_FIXED12_NO_ROUND(rock->mMapObject.mMatrix.mRows[0].x, dot);
        yAxis.y = yAxis.y - MUL_FIXED12_NO_ROUND(rock->mMapObject.mMatrix.mRows[0].y, dot);
        yAxis.z = yAxis.z - MUL_FIXED12_NO_ROUND(rock->mMapObject.mMatrix.mRows[0].z, dot);
        Vector3_MaybeNormalize(&yAxis, &rock->mMapObject.mMatrix.mRows[1]);
        Vector3_Cross(&rock->mMapObject.mMatrix.mRows[0], &rock->mMapObject.mMatrix.mRows[1],
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
    emitter->mRadius = params->mRadius;
    emitter->mDirectionSpeed = params->mDirectionSpeed;
    emitter->mAxisSpeed = params->mAxisSpeed;
    emitter->mSizeScale = params->mSizeScale;
}
