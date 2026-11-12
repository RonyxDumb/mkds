#include "Main/Unknown/code_02095f18.h"
#include "Main/Unknown/code_020d7da8.h"
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

void InitMoveTree(MoveTree *moveTree) {
    InitGroupFollower(&moveTree->mFollower, moveTree->mMapObject.mCourseMapRow, 0);
}

u8 CollideKartWithMoveTree(MoveTree *moveTree, Kart *kart, u8 *firstResponse, u8 *response) {
    u8 responseValue;

    responseValue = *response;
    if (moveTree->mState <= 1) {
        moveTree->mUnk_a4 = 30;
    }
    return responseValue;
}

void CreateMoveTree(void *mapObjectList) {
    gMoveTree = CreateMapObjectModelAnimated(mapObjectList, gMoveTreeNsbmdName);
    CreateMapObjectModelNsbcaAnimation(gMoveTree, gMoveTreeNsbcaName);
    SetMapObjectModelPolygonId(gMoveTree, 0x3f);
}

void DrawMoveTree(void *mapObjectList, MoveTree *moveTree, u32 unused, u32 alpha) {
    s32 gxParam;

    gxParam = 0x1e;
    NNS_G3dGeBufferOP_N(0x14, &gxParam, 1);
    NNS_G3dGeBufferOP_N(0x19, SetViewRotatedMatrixPos(&moveTree->mMapObject.mPos), 12);
    NNS_G3dGeBufferOP_N(0x1b, &moveTree->mMapObject.mScale, 3);
    if ((s32) (moveTree->mMapObject.mDistanceSquaredAndFlags & ~0xc000001f) < 0xc5c10) {
        SetMapObjectModelNsbcaFrameIndex(gMoveTree, moveTree->mNsbcaFrameIndex);
        DrawMapObjectModel(mapObjectList, gMoveTree, moveTree);
    } else {
        DrawMapObjectModel1Mat1Shp(mapObjectList, gMoveTree, moveTree);
    }
    if ((s32) (moveTree->mMapObject.mDistanceSquaredAndFlags & ~0xc000001f) >= 0x27100) {
        return;
    }
    SetShadowPositionXZ(&moveTree->mUnk_dc, &moveTree->mMapObject.mPos);
    DrawObjShadow(&moveTree->mUnk_dc, NULL, unused, alpha);
}

void InitMoveTreeObjects(MapObjectList *mapObjectList) {
    s32 mapObjectIndex;
    MoveTree *moveTree;

    if (mapObjectList == NULL) {
        return;
    }
    for (mapObjectIndex = 0; mapObjectIndex < mapObjectList->mMapObjectCount &&
                             (moveTree = mapObjectList->mMapObjects[mapObjectIndex]) != NULL;
         mapObjectIndex++) {
        moveTree->mUnk_a8 = TO_FIXED12(moveTree->mMapObject.mCourseMapRow->mSettings[0]) / 100;
        RefreshShadowMatrix(&moveTree->mUnk_dc, &moveTree->mMapObject.mPos, 0x54666, 14);
    }
}

void UpdateMoveTree(void *mapObjectList, MoveTree *moveTree) {
    SoundStartParams firstSoundParams;
    SoundStartParams secondSoundParams;
    u32 falloffIndex;
    s32 speed;

    switch (moveTree->mState) {
        case 0:
            moveTree->mFollower.mSpeed = 0;
            moveTree->mFollower.mProgressStep = 0;
            if (moveTree->mState0Timer-- <= 0) {
                moveTree->mState = 1;
            }
            if ((s32) (moveTree->mMapObject.mDistanceSquaredAndFlags & ~0xc000001f) >= 0xc5c10) {
                return;
            }
            if (moveTree->mUnk_a4-- > 0) {
                moveTree->mNsbcaFrameStep = 2;
                moveTree->mNsbcaFrameIndex += moveTree->mNsbcaFrameStep;
                if (moveTree->mNsbcaFrameIndex >= GetMapObjectModelNsbcaFrameCount(gMoveTree)) {
                    moveTree->mNsbcaFrameIndex = 0;
                }
                return;
            }
            if (moveTree->mNsbcaFrameIndex == 0) {
                return;
            }
            moveTree->mNsbcaFrameIndex += moveTree->mNsbcaFrameStep;
            if (moveTree->mNsbcaFrameIndex >= GetMapObjectModelNsbcaFrameCount(gMoveTree)) {
                moveTree->mNsbcaFrameIndex = 0;
            }
            if (moveTree->mNsbcaFrameIndex != 0 && moveTree->mNsbcaFrameIndex != 0x1e) {
                return;
            }
            if ((moveTree->mMapObject.mDistanceSquaredAndFlags & 4) != 0) {
                return;
            }
            if (moveTree->mMapObject.mFarDistanceSquared == gSoundFalloffs[2].mFarDistanceSquared) {
                falloffIndex = 2;
            } else if (moveTree->mMapObject.mFarDistanceSquared == gSoundFalloffs[3].mFarDistanceSquared) {
                falloffIndex = 3;
            } else {
                falloffIndex = 4;
            }
            firstSoundParams.mSoundId = 0x11f;
            firstSoundParams.mPositionSource = &moveTree->mMapObject.mPos;
            firstSoundParams.mFalloffIndex = falloffIndex;
            firstSoundParams.mDistanceSquared = GetHorizontalCameraDistanceSquared(&moveTree->mMapObject.mPos);
            StartSoundFromParams(&firstSoundParams);
            break;
        case 1:
            speed = moveTree->mUnk_a8;
            moveTree->mFollower.mSpeed = speed;
            moveTree->mFollower.mProgressStep = MUL_FIXED12_NO_ROUND(
                speed, moveTree->mFollower.mPath->mSegments[moveTree->mFollower.mSegmentIndex].mInverseProgressLength);
            if (AdvanceGroupFollower(&moveTree->mFollower) != FALSE) {
                moveTree->mState0Timer = (u16) moveTree->mFollower.mFromEntry->mUnk_0e;
                moveTree->mState = 0;
            }
            GetGroupFollowerLinearXz(&moveTree->mFollower, &moveTree->mMapObject.mPos);
            if ((s32) (moveTree->mMapObject.mDistanceSquaredAndFlags & ~0xc000001f) >= 0xc5c10) {
                return;
            }
            if (moveTree->mUnk_a4-- > 0) {
                moveTree->mNsbcaFrameStep = 2;
            } else {
                moveTree->mNsbcaFrameStep = 1;
            }
            moveTree->mNsbcaFrameIndex += moveTree->mNsbcaFrameStep;
            if (moveTree->mNsbcaFrameIndex >= GetMapObjectModelNsbcaFrameCount(gMoveTree)) {
                moveTree->mNsbcaFrameIndex = 0;
            }
            if (moveTree->mNsbcaFrameIndex != 0 && moveTree->mNsbcaFrameIndex != 0x1e) {
                return;
            }
            if ((moveTree->mMapObject.mDistanceSquaredAndFlags & 4) != 0) {
                return;
            }
            if (moveTree->mMapObject.mFarDistanceSquared == gSoundFalloffs[2].mFarDistanceSquared) {
                falloffIndex = 2;
            } else if (moveTree->mMapObject.mFarDistanceSquared == gSoundFalloffs[3].mFarDistanceSquared) {
                falloffIndex = 3;
            } else {
                falloffIndex = 4;
            }
            secondSoundParams.mSoundId = 0x11f;
            secondSoundParams.mPositionSource = &moveTree->mMapObject.mPos;
            secondSoundParams.mFalloffIndex = falloffIndex;
            secondSoundParams.mDistanceSquared = GetHorizontalCameraDistanceSquared(&moveTree->mMapObject.mPos);
            StartSoundFromParams(&secondSoundParams);
    }
}

void CreateMoveTreeKindData(void) {
    CreateMapObjectKindDataWithSound(CollideKartWithMoveTree, NULL, NULL, 2, 1, 0x125);
}

void CreateMoveTreeDrawList(void) {
    CreateMapObjectDrawList1(CreateMoveTree, DrawMoveTree, NULL);
}

void CreateMoveTreeUpdateList(void) {
    CreateMapObjectUpdateList(InitMoveTreeObjects, UpdateMoveTree, NULL);
}
