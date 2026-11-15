#include "Main/MapObjects/pukupuku.h"
#include "Main/System/heap.h"
#include "Main/Menu/second_menu_scene.h"
#include "Main/MapObjects/view_frustum.h"

#include "Main/MapObjects/send_obj_shadow.h"
#include "Main/MapObjects/code_020e66e4.h"
#include "Main/MapObjects/code_020e6a74.h"
#include "Main/MapObjects/data_02158000.h"
#include "Main/Item/pooled_map_object.h"
#include "Main/Item/item_in_use.h"
#include "fx_mtx33.h"
#include "Main/MapObjects/attractor.h"
#include "Main/Race/data_020f36d8.h"
#include "Main/MapObjects/does_map_object.h"
#include "Main/MapObjects/map_object_sound.h"
#include "Main/MapObjects/while_requested_full_volume_wrapper.h"
#include "Main/MapObjects/map_object_park.h"
#include "Main/MapObjects/sound_if_kart_star_or.h"
#include "Main/MapObjects/map_object_scale_sound_source.h"
#include "Main/MapObjects/map_object_list.h"
#include "Main/MapObjects/map_object.h"
#include "Main/Item/item_koura_w.h"
#include "Main/Sound/data_0210b000.h"
#include "Main/Sound/data_0216c000.h"
#include "Main/MapObjects/data_0217c000.h"
#include "player.h"
#include "code_0212d214.h"
#include "code_021479b4.h"
#include "Main/Item/code_021035ac.h"
#include "Main/Sound/surface_sound_ids.h"
#include "Main/Sound/sound_source_list.h"
#include "Main/MapObjects/choropu_state.h"
#include "code_02147cd8.h"
#include "Main/MapObjects/shadow_position_raised.h"
#include "Main/MapObjects/data_02159000.h"
#include "Main/MapObjects/ob_pakkun_sf.h"
#include "Main/MapObjects/code_020e6b58.h"
#include "Main/System/heap_call.h"
#include "Main/MapObjects/update_list_slot.h"
#include "Main/MapObjects/data_0217b000.h"

MapObjectKindData *CreatePukupukuKindData(void) {
    MapObjectKindData *kindData;
    kindData = HeapAlloc(GetHeap(GetCurrentHeapCall()), sizeof(MapObjectKindData));
    *kindData = gPukupukuKindData;
    return kindData;
}

MapObjectList *CreatePukupukuDrawList(void) {
    MapObjectDrawList *drawList;
    drawList = HeapAlloc(GetHeap(GetCurrentHeapCall()), sizeof(MapObjectDrawList));
    gPukupukuDrawList = drawList;
    *drawList = gPukupukuDrawListData;
    SetDrawListSlot(&gPukupukuDrawList);
    return &gPukupukuDrawList->mList;
}

MapObjectList *CreatePukupukuShadowDrawList(void) {
    MapObjectDrawList *shadowDrawList;
    shadowDrawList = HeapAlloc(GetHeap(GetCurrentHeapCall()), sizeof(MapObjectDrawList));
    gPukupukuShadowDrawList = shadowDrawList;
    *shadowDrawList = gPukupukuShadowDrawListData;
    SetDrawListSlot(&gPukupukuShadowDrawList);
    return &gPukupukuShadowDrawList->mList;
}

MapObjectList *CreatePukupukuUpdateList(void) {
    MapObjectList *updateList;
    updateList = HeapAlloc(GetHeap(GetCurrentHeapCall()), sizeof(MapObjectList));
    gPukupukuUpdateList = updateList;
    *updateList = gPukupukuUpdateListData;
    SetUpdateListSlot(&gPukupukuUpdateList);
    return gPukupukuUpdateList;
}

void SetupDrawPukupuku(void) {
    QueueNsbmdModelMaterial(gPukupuku);
}

void DrawPukupuku(u32 unused, Pukupuku *pukupuku, u32 unusedArg, u16 alpha) {
    NsbmdModel *model;
    s32 mirrored;
    u32 motionAngle;

    if (pukupuku->mPushedObject.mMapObject.mStateMachine.mState == PUKUPUKU_STATE_HOP) {
        MtxFx43 *matrix;
        mirrored = pukupuku->mPushedObject.mMapObject.mCollisionSlotIndex & 1;
        matrix = SetViewTransposeMatrixPos(&pukupuku->mPushedObject.mMapObject.mPos);
        model = gPukupuku;
        model->mPolygonAttributes = model->mPolygonAttributes | 0xc0;
        gPukupukuDrawScale = pukupuku->mPushedObject.mMapObject.mScale;
        if (mirrored) {
            gPukupukuDrawScale.x = -gPukupukuDrawScale.x;
        }
        DrawNsbmdModelWithMatrixAndMaxAlpha(model, matrix, &gPukupukuDrawScale, 0, alpha);
    } else {
        MtxFx43 *matrix;
        mirrored = pukupuku->mPushedObject.mMapObject.mCollisionSlotIndex & 1;
        motionAngle = pukupuku->mPushedObject.mMotion.mAngle;
        matrix = SetViewTransposeMatrixPos(&pukupuku->mPushedObject.mMapObject.mPos);
        model = gPukupuku;
        model->mPolygonAttributes = model->mPolygonAttributes | 0xc0;
        gPukupukuDrawScale = pukupuku->mPushedObject.mMapObject.mScale;
        if (mirrored) {
            gPukupukuDrawScale.x = -gPukupukuDrawScale.x;
        }
        DrawNsbmdModelWithMatrixAndAngle(model, matrix, motionAngle, &gPukupukuDrawScale, 0, alpha);
    }
}

void SetupDrawPukupukuShadow(void) {
    u32 unused;
    SendObjShadowMaterial();
}

void DrawPukupukuShadow(u32 unused, Pukupuku *pukupuku, u32 unusedArg, u32 alpha) {
    PukupukuShadowParams shadowParams;

    if (pukupuku->mPushedObject.mMapObject.mStateMachine.mState != PUKUPUKU_STATE_HOP &&
        pukupuku->mPushedObject.mMapObject.mStateMachine.mState != PUKUPUKU_STATE_PUSHED) {
        return;
    }
    shadowParams.mScale = pukupuku->mPushedObject.mMapObject.mPos.y - pukupuku->mInitialPos.y;
    shadowParams.mScale = 0x1000 - (shadowParams.mScale >> 6);
    shadowParams.mPos = pukupuku->mPushedObject.mMapObject.mPos;
    shadowParams.mPos.y = pukupuku->mInitialGroundY + pukupuku->mGroundYOffset;
    SetShadowPositionRaised(&pukupuku->mShadowMatrix, &shadowParams.mPos);
    DrawObjShadowAfterMaterial(&pukupuku->mShadowMatrix, &shadowParams, 0, alpha);
}

void UpdatePukupuku(u32 unused, Pukupuku *pukupuku) {
    AdvanceStateMachine(&pukupuku->mPushedObject.mMapObject.mStateMachine);
}

void EnterPukupukuHop(void *stateObject) {
    Pukupuku *pukupuku = stateObject;
    pukupuku->mPushedObject.mMotion.mAngle = 0x0u;
}

static inline u32 PukupukuNextRandomBelow(RandomState64 *random, u32 range) {
    random->mValue = random->mMultiplier * random->mValue + random->mIncrement;
    if (range == 0) {
        return random->mValue >> 32;
    } else {
        return ((random->mValue >> 32) * range) >> 32;
    }
}

void UpdatePukupukuHop(void *stateObject) {
    Pukupuku *pukupuku = stateObject;
    s32 groundY;

    pukupuku->mPushedObject.mMapObject.mPosStep.y -= 0x385;
    VEC_Add(&pukupuku->mPushedObject.mMapObject.mPos, &pukupuku->mPushedObject.mMapObject.mPosStep,
            &pukupuku->mPushedObject.mMapObject.mPos);
    groundY = 0;
    groundY += MUL_FIXED12_NO_ROUND(pukupuku->mGroundSlopeX,
                                    pukupuku->mPushedObject.mMapObject.mPos.x - pukupuku->mInitialPos.x);
    groundY += MUL_FIXED12_NO_ROUND(pukupuku->mGroundSlopeZ,
                                    pukupuku->mPushedObject.mMapObject.mPos.z - pukupuku->mInitialPos.z);
    pukupuku->mGroundYOffset = groundY;
    groundY = pukupuku->mInitialPos.y + pukupuku->mGroundYOffset;
    if (pukupuku->mPushedObject.mMapObject.mPos.y >= groundY) {
        return;
    }
    if (!(pukupuku->mPushedObject.mMapObject.mDistanceSquaredAndFlags & MAP_OBJECT_VIEW_BEYOND_FAR_DISTANCE)) {
        SoundStartParams soundRequest;
        u32 falloffIndex;

        if (pukupuku->mPushedObject.mMapObject.mFarDistanceSquared == gSoundFalloffs[2].mFarDistanceSquared) {
            falloffIndex = 2;
        } else if (pukupuku->mPushedObject.mMapObject.mFarDistanceSquared == gSoundFalloffs[3].mFarDistanceSquared) {
            falloffIndex = 3;
        } else {
            falloffIndex = 4;
        }
        soundRequest.mSoundId = PUKUPUKU_HOP_SOUND_ID;
        soundRequest.mPositionSource = &pukupuku->mPushedObject.mMapObject.mPos;
        soundRequest.mFalloffIndex = falloffIndex;
        soundRequest.mDistanceSquared = GetHorizontalCameraDistanceSquared(&pukupuku->mPushedObject.mMapObject.mPos);
        StartSoundFromParams(&soundRequest);
    }
    pukupuku->mPushedObject.mMapObject.mPos.y = groundY;
    pukupuku->mJumpsUntilHighJump = pukupuku->mJumpsUntilHighJump - 1;
    if (pukupuku->mJumpsUntilHighJump == 0) {
        RandomState64 *random;

        pukupuku->mPushedObject.mMapObject.mPosStep.y = 0x3199;
        random = GetMapObjectRandom();
        pukupuku->mJumpsUntilHighJump = (u16) PukupukuNextRandomBelow(random, 3) + 4;
    } else {
        RandomState64 *random;

        pukupuku->mPushedObject.mMapObject.mPosStep.y = 0x2000;
        random = GetMapObjectRandom();
        pukupuku->mPushedObject.mMapObject.mPosStep.y =
            pukupuku->mPushedObject.mMapObject.mPosStep.y + PukupukuNextRandomBelow(random, 0x800);
    }
    if (pukupuku->mPushedObject.mMapObject.mPos.x > pukupuku->mInitialPos.x + 0x14000) {
        pukupuku->mPushedObject.mMapObject.mPosStep.x = -0xccc;
    } else if (pukupuku->mPushedObject.mMapObject.mPos.x < pukupuku->mInitialPos.x - 0x14000) {
        pukupuku->mPushedObject.mMapObject.mPosStep.x = 0xccc;
    } else {
        RandomState64 *random;

        random = GetMapObjectRandom();
        pukupuku->mPushedObject.mMapObject.mPosStep.x = PukupukuNextRandomBelow(random, 0x1998) - 0xccc;
    }
    if (pukupuku->mPushedObject.mMapObject.mPos.z > pukupuku->mInitialPos.z + 0x14000) {
        pukupuku->mPushedObject.mMapObject.mPosStep.z = -0xccc;
        return;
    }
    if (pukupuku->mPushedObject.mMapObject.mPos.z < pukupuku->mInitialPos.z - 0x14000) {
        pukupuku->mPushedObject.mMapObject.mPosStep.z = 0xccc;
        return;
    }
    {
        RandomState64 *random;

        random = GetMapObjectRandom();
        pukupuku->mPushedObject.mMapObject.mPosStep.z = PukupukuNextRandomBelow(random, 0x1998) - 0xccc;
    }
}

void EnterPukupukuPushed(void *stateObject) {
    Pukupuku *pukupuku = stateObject;
    pukupuku->mPushedObject.mMapObject.mFlags =
        (((pukupuku->mPushedObject.mMapObject.mFlags)) | ((gPukupukuPushedFlag)));
}

void UpdatePukupukuPushed(void *stateObject) {
    Pukupuku *pukupuku = stateObject;
    if (AdvancePushedMotion(&pukupuku->mPushedObject) == FALSE) {
        return;
    }
    if (pukupuku->mPushedObject.mMapObject.mCourseMapRow->mSettings[0] == 0) {
        pukupuku->mPushedObject.mMapObject.mStateMachine.mNextState = PUKUPUKU_STATE_WAIT_RESPAWN;
        pukupuku->mPushedObject.mMapObject.mStateMachine.mNextStateRequested = 1;
        return;
    }
    ParkMapObject(&pukupuku->mPushedObject.mMapObject);
}

void EnterPukupukuWaitRespawn(void *stateObject) {
    Pukupuku *pukupuku = stateObject;
    pukupuku->mPushedObject.mMapObject.mFlags |= gPukupukuWaitRespawnFlag;
    pukupuku->mPushedObject.mMapObject.mFlags |= gPukupukuWaitRespawnSecondFlag;
}

void UpdatePukupukuWaitRespawn(void *stateObject) {
    Pukupuku *pukupuku = stateObject;
    if (pukupuku->mPushedObject.mMapObject.mStateMachine.mStateFrames > PUKUPUKU_WAIT_FRAMES) {
        pukupuku->mPushedObject.mMapObject.mStateMachine.mNextState = PUKUPUKU_STATE_RESPAWN;
        pukupuku->mPushedObject.mMapObject.mStateMachine.mNextStateRequested = 1;
    }
}

void EnterPukupukuRespawn(void *stateObject) {
    Pukupuku *pukupuku = stateObject;
    pukupuku->mPushedObject.mMapObject.mPos.x = pukupuku->mInitialPos.x;
    pukupuku->mPushedObject.mMapObject.mPos.z = pukupuku->mInitialPos.z;
    pukupuku->mPushedObject.mMapObject.mPosStep.x = 0x0u;
    pukupuku->mPushedObject.mMapObject.mPosStep.y = 0x3199u;
    pukupuku->mPushedObject.mMapObject.mPosStep.z = 0x0u;
    pukupuku->mPushedObject.mMapObject.mFlags = (((pukupuku->mPushedObject.mMapObject.mFlags)) & ~(0x2u));
    pukupuku->mPushedObject.mMapObject.mFlags = (((pukupuku->mPushedObject.mMapObject.mFlags)) & ~(0x8u));
    pukupuku->mPushedObject.mMapObject.mAlpha = MAP_OBJECT_ALPHA_MAX;
    pukupuku->mPushedObject.mMapObject.mFlags = (((pukupuku->mPushedObject.mMapObject.mFlags)) & ~(0x1u));
}

void UpdatePukupukuRespawn(void *stateObject) {
    Pukupuku *pukupuku = stateObject;
    pukupuku->mPushedObject.mMapObject.mPos.y =
        pukupuku->mPushedObject.mMapObject.mPos.y + pukupuku->mPushedObject.mMapObject.mPosStep.y;
    if (pukupuku->mPushedObject.mMapObject.mPos.y > pukupuku->mInitialPos.y) {
        pukupuku->mPushedObject.mMapObject.mStateMachine.mNextState = PUKUPUKU_STATE_HOP;
        pukupuku->mPushedObject.mMapObject.mStateMachine.mNextStateRequested = 1;
    }
}

u8 CollideKartWithPukupuku(Pukupuku *pukupuku, Kart *kart, u8 *firstResponse, u8 *response) {
    if (*firstResponse == 1) {
        SetPushedMotionFromKart(&pukupuku->mPushedObject, kart);
        pukupuku->mPushedObject.mMapObject.mStateMachine.mNextState = PUKUPUKU_STATE_PUSHED;
        pukupuku->mPushedObject.mMapObject.mStateMachine.mNextStateRequested = 1;
        pukupuku->mPushedObject.mMapObject.mFlags = pukupuku->mPushedObject.mMapObject.mFlags | (gPukupukuPushedFlag);
        StartSoundIfKartStarOrKiller(&pukupuku->mPushedObject.mMapObject, kart);
    }
    return *response;
}

s32 CollideItemObjectWithPukupuku(Pukupuku *pukupuku, void *itemObject, u8 *firstResponse, u8 *response) {
    if (*firstResponse == 1) {
        SetPushedMotionFromItemObject(&pukupuku->mPushedObject, itemObject);
        pukupuku->mPushedObject.mMapObject.mFlags |= gPukupukuPushedFlag;
        pukupuku->mPushedObject.mMapObject.mStateMachine.mNextState = PUKUPUKU_STATE_PUSHED;
        pukupuku->mPushedObject.mMapObject.mStateMachine.mNextStateRequested = 1;
    }
    return *response;
}

#pragma thumb on

void CreatePukupuku(void) {
    void *nsbmdFile;
    nsbmdFile = FindCourseMapObjFile("pukupuku.nsbmd");
    CreateNsbmdModel(&gPukupuku, nsbmdFile, 0, 0);
    SetNsbmdModelFixedAttributes(gPukupuku);
}

#pragma thumb off

const u16 gPukupukuWaitRespawnFlag = 2;
const u16 gPukupukuWaitRespawnSecondFlag = 8;
const struct MapObjectList gPukupukuUpdateListData = {NULL, 0, {0, 0}, NULL, NULL, UpdatePukupuku,
                                                      NULL, 0, NULL,   0,    NULL};
const MapObjectDrawList gPukupukuShadowDrawListData = {{NULL,
                                                        0,
                                                        {0, 0},
                                                        NULL,
                                                        (void (*)(MapObjectList *)) SetupDrawPukupukuShadow,
                                                        DrawPukupukuShadow,
                                                        NULL,
                                                        1,
                                                        0,
                                                        1,
                                                        NULL},
                                                       0};
const MapObjectDrawList gPukupukuDrawListData = {{NULL,
                                                  0,
                                                  {0, 0},
                                                  (void (*)(MapObjectList *)) CreatePukupuku,
                                                  (void (*)(MapObjectList *)) SetupDrawPukupuku,
                                                  (MapObjectForEachCallback) DrawPukupuku,
                                                  NULL,
                                                  2,
                                                  0,
                                                  0,
                                                  NULL},
                                                 0};
const u16 gPukupukuPushedFlag = 1;
const struct MapObjectKindData gPukupukuKindData = {
    (s32(*)(MapObject *, void *, s32 *, s32 *)) CollideKartWithPukupuku,
    (s32(*)(MapObject *, void *, void *, void *)) CollideItemObjectWithPukupuku,
    1,
    0xa000,
    0,
    0,
    NULL,
    1,
    1,
    0x10c,
    0x10d,
    0,
    0,
    0,
    0,
    0};
NsbmdModel *gPukupuku;
MapObjectDrawList *gPukupukuShadowDrawList;
MapObjectList *gPukupukuUpdateList;
Vec3 gPukupukuDrawScale;
MapObjectDrawList *gPukupukuDrawList;
