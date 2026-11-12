#include "Main/MapObjects/pukupuku.h"
#include "Main/System/heap.h"
#include "Main/Menu/second_menu_scene.h"
#include "Main/Unknown/code_020d4c28.h"

#include "Main/Unknown/code_020e48e0.h"
#include "Main/Unknown/code_020e55b4.h"
#include "Main/Unknown/code_020e66e4.h"
#include "Main/Unknown/code_020e6a74.h"
#include "Main/Unknown/code_020ec000.h"
#include "Main/Unknown/unk_02158000.h"
#include "Main/Unknown/code_020e4934.h"
#include "Main/Unknown/code_020e4990.h"
#include "Main/Unknown/code_020e49c0.h"
#include "Main/Unknown/code_020e4a18.h"
#include "Main/Unknown/code_020e4a34.h"
#include "Main/Unknown/code_020e4a68.h"
#include "Main/Unknown/code_020d2000.h"
#include "Main/Item/item_koura_w.h"
#include "Main/Unknown/code_020e4ab4.h"
#include "Main/Unknown/code_020e4ad0.h"
#include "Main/Unknown/code_020f36d8.h"
#include "Main/MapObjects/map_object_park.h"
#include "Main/Unknown/code_020d4000.h"
#include "Main/Unknown/code_0210b000.h"
#include "Main/Unknown/unk_0216c000.h"
#include "Main/Unknown/unk_0217c000.h"
#include "Main/Unknown/code_020e337c.h"
#include "code_02147cd8.h"
#include "Main/Unknown/code_020e4dec.h"
#include "Main/Unknown/code_020e4df8.h"
#include "Main/Unknown/code_020e4e08.h"
#include "Main/Unknown/code_020e5000.h"
#include "Main/MapObjects/shadow_position_raised.h"
#include "Main/Unknown/code_020e4e9c.h"
#include "Main/Unknown/code_020e4ea8.h"
#include "Main/Unknown/unk_02159000.h"
#include "Main/Unknown/code_020e6b58.h"
#include "Main/System/heap_call.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_020d49d8.h"
#include "Main/Unknown/code_020e6000.h"
#include "Main/MapObjects/update_list_slot.h"
#include "Main/Unknown/unk_0217b000.h"

MapObjectKindData *CreatePukupukuKindData(void) {
    MapObjectKindData *kindData;
    kindData = HeapAlloc(GetHeap(GetCurrentHeapCall()), 0x40);
    *kindData = data_02159070;
    return kindData;
}

PukupukuDrawList *CreatePukupukuDrawList(void) {
    PukupukuDrawList *drawList;
    drawList = HeapAlloc(GetHeap(GetCurrentHeapCall()), 0x2c);
    gPukupukuDrawList = drawList;
    *drawList = data_02159044;
    SetDrawListSlot(&gPukupukuDrawList);
    return gPukupukuDrawList;
}

PukupukuShadowDrawList *CreatePukupukuShadowDrawList(void) {
    PukupukuShadowDrawList *shadowDrawList;
    shadowDrawList = HeapAlloc(GetHeap(GetCurrentHeapCall()), 0x2c);
    gPukupukuShadowDrawList = shadowDrawList;
    *shadowDrawList = data_02159018;
    SetDrawListSlot(&gPukupukuShadowDrawList);
    return gPukupukuShadowDrawList;
}

MapObjectList *CreatePukupukuUpdateList(void) {
    MapObjectList *updateList;
    updateList = HeapAlloc(GetHeap(GetCurrentHeapCall()), 0x28);
    gPukupukuUpdateList = updateList;
    *updateList = data_02158ff0;
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

    if (pukupuku->mPushedObject.mMapObject.mStateMachine.mState == 0) {
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

    if (pukupuku->mPushedObject.mMapObject.mStateMachine.mState != 0 &&
        pukupuku->mPushedObject.mMapObject.mStateMachine.mState != 1) {
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

void EnterPukupukuState0(Pukupuku *pukupuku) {
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

void UpdatePukupukuState0(Pukupuku *pukupuku) {
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
    if (!(pukupuku->mPushedObject.mMapObject.mDistanceSquaredAndFlags & 4)) {
        SoundStartParams soundRequest;
        u32 falloffIndex;

        if (pukupuku->mPushedObject.mMapObject.mFarDistanceSquared == gSoundFalloffs[2].mFarDistanceSquared) {
            falloffIndex = 2;
        } else if (pukupuku->mPushedObject.mMapObject.mFarDistanceSquared == gSoundFalloffs[3].mFarDistanceSquared) {
            falloffIndex = 3;
        } else {
            falloffIndex = 4;
        }
        soundRequest.mSoundId = 0x10b;
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

void EnterPukupukuState1(Pukupuku *pukupuku) {
    pukupuku->mPushedObject.mMapObject.mFlags = (((pukupuku->mPushedObject.mMapObject.mFlags)) | ((data_02158fe4)));
}

void UpdatePukupukuState1(Pukupuku *pukupuku) {
    if (AdvancePushedMotion(&pukupuku->mPushedObject) == FALSE) {
        return;
    }
    if (pukupuku->mPushedObject.mMapObject.mCourseMapRow->mSettings[0] == 0) {
        pukupuku->mPushedObject.mMapObject.mStateMachine.mNextState = 2;
        pukupuku->mPushedObject.mMapObject.mStateMachine.mNextStateRequested = 1;
        return;
    }
    ParkMapObject(&pukupuku->mPushedObject.mMapObject);
}

void EnterPukupukuState2(Pukupuku *pukupuku) {
    pukupuku->mPushedObject.mMapObject.mFlags |= data_02158fe8;
    pukupuku->mPushedObject.mMapObject.mFlags |= data_02158fec;
}

void UpdatePukupukuState2(Pukupuku *pukupuku) {
    if (pukupuku->mPushedObject.mMapObject.mStateMachine.mStateFrames > 0x12c) {
        pukupuku->mPushedObject.mMapObject.mStateMachine.mNextState = 3;
        pukupuku->mPushedObject.mMapObject.mStateMachine.mNextStateRequested = 1;
    }
}

void EnterPukupukuState3(Pukupuku *pukupuku) {
    pukupuku->mPushedObject.mMapObject.mPos.x = pukupuku->mInitialPos.x;
    pukupuku->mPushedObject.mMapObject.mPos.z = pukupuku->mInitialPos.z;
    pukupuku->mPushedObject.mMapObject.mPosStep.x = 0x0u;
    pukupuku->mPushedObject.mMapObject.mPosStep.y = 0x3199u;
    pukupuku->mPushedObject.mMapObject.mPosStep.z = 0x0u;
    pukupuku->mPushedObject.mMapObject.mFlags = (((pukupuku->mPushedObject.mMapObject.mFlags)) & ~(0x2u));
    pukupuku->mPushedObject.mMapObject.mFlags = (((pukupuku->mPushedObject.mMapObject.mFlags)) & ~(0x8u));
    pukupuku->mPushedObject.mMapObject.mAlpha = 0x1fu;
    pukupuku->mPushedObject.mMapObject.mFlags = (((pukupuku->mPushedObject.mMapObject.mFlags)) & ~(0x1u));
}

void UpdatePukupukuState3(Pukupuku *pukupuku) {
    pukupuku->mPushedObject.mMapObject.mPos.y =
        pukupuku->mPushedObject.mMapObject.mPos.y + pukupuku->mPushedObject.mMapObject.mPosStep.y;
    if (pukupuku->mPushedObject.mMapObject.mPos.y > pukupuku->mInitialPos.y) {
        pukupuku->mPushedObject.mMapObject.mStateMachine.mNextState = 0;
        pukupuku->mPushedObject.mMapObject.mStateMachine.mNextStateRequested = 1;
    }
}

u8 CollideKartWithPukupuku(Pukupuku *pukupuku, Kart *kart, u8 *firstResponse, u8 *response) {
    if (*firstResponse == 1) {
        SetPushedMotionFromKart(&pukupuku->mPushedObject, kart);
        pukupuku->mPushedObject.mMapObject.mStateMachine.mNextState = 1;
        pukupuku->mPushedObject.mMapObject.mStateMachine.mNextStateRequested = 1;
        pukupuku->mPushedObject.mMapObject.mFlags = pukupuku->mPushedObject.mMapObject.mFlags | (data_02158fe4);
        StartSoundIfKartStarOrKiller(&pukupuku->mPushedObject.mMapObject, kart);
    }
    return *response;
}

s32 CollideItemObjectWithPukupuku(Pukupuku *pukupuku, void *itemObject, u8 *firstResponse, u8 *response) {
    if (*firstResponse == 1) {
        SetPushedMotionFromItemObject(&pukupuku->mPushedObject, itemObject);
        pukupuku->mPushedObject.mMapObject.mFlags |= data_02158fe4;
        pukupuku->mPushedObject.mMapObject.mStateMachine.mNextState = 1;
        pukupuku->mPushedObject.mMapObject.mStateMachine.mNextStateRequested = 1;
    }
    return *response;
}

#pragma thumb on

void CreatePukupuku(void) {
    void *nsbmdFile;
    nsbmdFile = FindCourseMapObjFile(gPukupukuNsbmdName);
    CreateNsbmdModel(&gPukupuku, nsbmdFile, 0, 0);
    SetNsbmdModelFixedAttributes(gPukupuku);
}

#pragma thumb off
