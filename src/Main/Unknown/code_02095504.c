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

u8 CollideKartWithMoveTree(MoveTree *moveTree, Kart *kart, u8 *c, u8 *d) {
    u8 v;

    v = *d;
    if (moveTree->mState <= 1) {
        moveTree->mUnk_a4 = 30;
    }
    return v;
}

void CreateMoveTree(void *a) {
    gMoveTree = CreateMapObjectModelAnimated(a, gMoveTreeNsbmdName);
    CreateMapObjectModelNsbcaAnimation(gMoveTree, gMoveTreeNsbcaName);
    SetMapObjectModelPolygonId(gMoveTree, 0x3f);
}

void DrawMoveTree(void *a, MoveTree *moveTree, u32 c, u32 d) {
    s32 t;

    t = 0x1e;
    NNS_G3dGeBufferOP_N(0x14, &t, 1);
    NNS_G3dGeBufferOP_N(0x19, SetViewRotatedMatrixPos(&moveTree->mMapObject.mPos), 12);
    NNS_G3dGeBufferOP_N(0x1b, &moveTree->mMapObject.mScale, 3);
    if ((s32) (moveTree->mMapObject.mDistanceSquaredAndFlags & ~0xc000001f) < 0xc5c10) {
        SetMapObjectModelNsbcaFrameIndex(gMoveTree, moveTree->mNsbcaFrameIndex);
        DrawMapObjectModel(a, gMoveTree, moveTree);
    } else {
        DrawMapObjectModel1Mat1Shp(a, gMoveTree, moveTree);
    }
    if ((s32) (moveTree->mMapObject.mDistanceSquaredAndFlags & ~0xc000001f) >= 0x27100) {
        return;
    }
    SetShadowPositionXZ(&moveTree->mUnk_dc, &moveTree->mMapObject.mPos);
    DrawObjShadow(&moveTree->mUnk_dc, NULL, c, d);
}

void InitMoveTreeObjects(MapObjectList *mapObjectList) {
    s32 i;
    MoveTree *moveTree;

    if (mapObjectList == NULL) {
        return;
    }
    for (i = 0; i < mapObjectList->mMapObjectCount && (moveTree = mapObjectList->mMapObjects[i]) != NULL; i++) {
        moveTree->mUnk_a8 = (moveTree->mMapObject.mCourseMapRow->mUnk_28 << 12) / 100;
        RefreshShadowMatrix(&moveTree->mUnk_dc, &moveTree->mMapObject.mPos, 0x54666, 14);
    }
}

void UpdateMoveTree(void *a, MoveTree *moveTree) {
    SoundStartParams s1;
    SoundStartParams s2;
    u32 k;
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
            if (moveTree->mMapObject.mFarDistanceSquared == gSoundFalloffs[2].mUnk_20) {
                k = 2;
            } else if (moveTree->mMapObject.mFarDistanceSquared == gSoundFalloffs[3].mUnk_20) {
                k = 3;
            } else {
                k = 4;
            }
            s1.mSoundId = 0x11f;
            s1.mPositionSource = &moveTree->mMapObject.mPos;
            s1.mFalloffIndex = k;
            s1.mDistanceSquared = GetHorizontalCameraDistanceSquared(&moveTree->mMapObject.mPos);
            StartSoundFromParams(&s1);
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
            if (moveTree->mMapObject.mFarDistanceSquared == gSoundFalloffs[2].mUnk_20) {
                k = 2;
            } else if (moveTree->mMapObject.mFarDistanceSquared == gSoundFalloffs[3].mUnk_20) {
                k = 3;
            } else {
                k = 4;
            }
            s2.mSoundId = 0x11f;
            s2.mPositionSource = &moveTree->mMapObject.mPos;
            s2.mFalloffIndex = k;
            s2.mDistanceSquared = GetHorizontalCameraDistanceSquared(&moveTree->mMapObject.mPos);
            StartSoundFromParams(&s2);
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

void CreateBakubakuAndBakuShadow(void *a) {
    gBakubaku = CreateMapObjectModelAnimated(a, gBakubakuNsbmdName);
    gBakuShadow = CreateMapObjectModelShadow(a, gBakuShadowNsbmdName);
    SetMapObjectModelPolygonId(gBakubaku, 0x3f);
    SetMapObjectModelPolygonId(gBakuShadow, 0x3f);
}

void DrawBakubaku(void *a, Bakubaku *bakubaku) {
    s32 t;
    MtxFx33 m;
    s32 i;

    if (bakubaku->mState != 2) {
        return;
    }
    t = 0x1e;
    NNS_G3dGeBufferOP_N(0x14, &t, 1);
    bakubaku->mMapObject.mMatrix.mUnk_00[3].x = bakubaku->mMapObject.mPos.x >> 4;
    bakubaku->mMapObject.mMatrix.mUnk_00[3].y = bakubaku->mMapObject.mPos.y >> 4;
    bakubaku->mMapObject.mMatrix.mUnk_00[3].z = bakubaku->mMapObject.mPos.z >> 4;
    NNS_G3dGeBufferOP_N(0x19, &bakubaku->mMapObject.mMatrix, 12);
    NNS_G3dGeBufferOP_N(0x1b, &bakubaku->mMapObject.mScale, 3);
    DrawMapObjectModel(a, gBakuShadow, bakubaku);
    i = (u16) (u32) FX_Atan2Idx(-bakubaku->mMapObject.mPosStep.y, 0xc000) >> 4;
    MTX_RotX33_(&m, gPairsByAngle[i * 2], gPairsByAngle[i * 2 + 1]);
    NNS_G3dGeBufferOP_N(0x1a, &m, 9);
    DrawMapObjectModel(a, gBakubaku, bakubaku);
}

void InitBakubakuObjects(MapObjectList *mapObjectList) {
    s32 i;
    Bakubaku *bakubaku;

    if (mapObjectList == NULL) {
        return;
    }
    for (i = 0; i < mapObjectList->mMapObjectCount && (bakubaku = mapObjectList->mMapObjects[i]) != NULL; i++) {
        VEC_MultAdd(0x320000, &bakubaku->mMapObject.mMatrix.mUnk_00[2], &bakubaku->mMapObject.mCourseMapRow->mUnk_00,
                    &bakubaku->mUnk_a4);
    }
}

void UpdateBakubaku(void *a, Bakubaku *bakubaku) {
    SoundStartParams s1;
    SoundStartParams s2;
    Kart *kart;
    Vec3 *kartPos;
    s64 distanceSquared;
    s32 deltaZ;
    s32 deltaX;

    switch (bakubaku->mState) {
        case 0:
            if (GetCurrentCameraKind() != 2) {
                kart = GetKart((u16) gRaceSetup->mEntryIndex);
                kartPos = &kart->mPos;
                deltaX = kartPos->x - bakubaku->mUnk_a4.x;
                deltaZ = kartPos->z - bakubaku->mUnk_a4.z;
                distanceSquared = (s64) deltaX * deltaX + (s64) deltaZ * deltaZ;
                if (distanceSquared >= (s64) 0x9c4 << 32) {
                    return;
                }
            }
            bakubaku->mMapObject.mPos.x = bakubaku->mMapObject.mCourseMapRow->mUnk_00.x;
            bakubaku->mMapObject.mPos.y = bakubaku->mMapObject.mCourseMapRow->mUnk_00.y - 0x32000;
            bakubaku->mMapObject.mPos.z = bakubaku->mMapObject.mCourseMapRow->mUnk_00.z;
            bakubaku->mMapObject.mPosStep.x = MUL_FIXED12_NO_ROUND(bakubaku->mMapObject.mMatrix.mUnk_00[2].x, 0xc000);
            bakubaku->mMapObject.mPosStep.y = 0xc000;
            bakubaku->mMapObject.mPosStep.z = MUL_FIXED12_NO_ROUND(bakubaku->mMapObject.mMatrix.mUnk_00[2].z, 0xc000);
            bakubaku->mState = 1;
            break;
        case 1:
            bakubaku->mMapObject.mPosStep.y -= 0x400;
            VEC_Add(&bakubaku->mMapObject.mPos, &bakubaku->mMapObject.mPosStep, &bakubaku->mMapObject.mPos);
            if (bakubaku->mMapObject.mPos.y < bakubaku->mMapObject.mCourseMapRow->mUnk_00.y) {
                return;
            }
            StartModelEffect(3, &bakubaku->mMapObject.mPos, 1);
            s1.mSoundId = 0x186;
            s1.mPositionSource = &bakubaku->mMapObject.mPos;
            s1.mFalloffIndex = 4;
            s1.mDistanceSquared = GetHorizontalCameraDistanceSquared(&bakubaku->mMapObject.mPos);
            StartSoundFromParams(&s1);
            bakubaku->mState = 2;
            break;
        case 2:
            bakubaku->mMapObject.mPosStep.y -= 0x400;
            VEC_Add(&bakubaku->mMapObject.mPos, &bakubaku->mMapObject.mPosStep, &bakubaku->mMapObject.mPos);
            if (bakubaku->mMapObject.mPos.y > bakubaku->mMapObject.mCourseMapRow->mUnk_00.y) {
                return;
            }
            StartModelEffect(3, &bakubaku->mMapObject.mPos, 1);
            s2.mSoundId = 0x187;
            s2.mPositionSource = &bakubaku->mMapObject.mPos;
            s2.mFalloffIndex = 2;
            s2.mDistanceSquared = GetHorizontalCameraDistanceSquared(&bakubaku->mMapObject.mPos);
            StartSoundFromParams(&s2);
            bakubaku->mState = 3;
            break;
        case 3:
            bakubaku->mMapObject.mPosStep.y -= 0x400;
            VEC_Add(&bakubaku->mMapObject.mPos, &bakubaku->mMapObject.mPosStep, &bakubaku->mMapObject.mPos);
            if (bakubaku->mMapObject.mPos.y <= bakubaku->mMapObject.mCourseMapRow->mUnk_00.y - 0x32000) {
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

void CreateBakubakuDrawList(void) {
    CreateMapObjectDrawList1(CreateBakubakuAndBakuShadow, DrawBakubaku, NULL);
}

void CreateBakubakuUpdateList(void) {
    CreateMapObjectUpdateList(InitBakubakuObjects, UpdateBakubaku, NULL);
}
