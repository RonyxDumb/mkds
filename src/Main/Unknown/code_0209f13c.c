#include "Main/Unknown/code_0209f13c.h"
#include "Main/Unknown/code_0209f650.h"
#include "Main/Unknown/code_0209b634.h"
#include "Main/Unknown/code_0209b000.h"
#include "Main/Unknown/code_0209bef0.h"
#include "Main/Unknown/code_0209f5cc.h"
#include "ITCM/code_01ff8000.h"
#include "ITCM/code_01ff9000.h"
#include "Main/Unknown/code_020d4c28.h"
#include "Main/Unknown/code_0210b760.h"
#include "Main/Unknown/unk_0215d000.h"
#include "Main/Unknown/unk_0217b000.h"
#include "Main/Unknown/unk_0217c000.h"
#include "Main/Unknown/unk_021759c0.h"
#include "Main/Unknown/code_020f36d8.h"
#include "code_02146cbc.h"
#include "code_02147cd8.h"

void InitChandelierObjects(MapObjectList *objectList) {
    s32 objectIndex;
    Chandelier *chandelier;
    RandomState64 *random;

    if (objectList == NULL) {
        return;
    }
    for (objectIndex = 0;
         objectIndex < objectList->mMapObjectCount && (chandelier = objectList->mMapObjects[objectIndex]) != NULL;
         objectIndex++) {
        random = &gRaceProgress->mLocalRandom;
        random->mValue = random->mMultiplier * random->mValue + random->mIncrement;
        chandelier->mTimer = (u16) (((u64) (u32) (random->mValue >> 32) * 0x3c) >> 32) + 0x3c;
    }
}

void UpdateChandelier(void *mapObjectList, Chandelier *chandelier) {
    SoundStartParams firstSoundParams;
    SoundStartParams secondSoundParams;
    SoundStartParams thirdSoundParams;
    s32 falloffIndex;
    s32 nextFrameIndex;

    switch (chandelier->mState) {
        case 0:
            if (chandelier->mTimer-- <= 0) {
                chandelier->mState = 1;
            }
            return;
        case 1:
            break;
        default:
            return;
    }
    if (chandelier->mFrameIndex == 0 || chandelier->mFrameIndex == 0x7d) {
        if ((chandelier->mMapObject.mDistanceSquaredAndFlags & 4) == 0) {
            if (chandelier->mMapObject.mFarDistanceSquared == gSoundFalloffs[2].mFarDistanceSquared) {
                falloffIndex = 2;
            } else if (chandelier->mMapObject.mFarDistanceSquared == gSoundFalloffs[3].mFarDistanceSquared) {
                falloffIndex = 3;
            } else {
                falloffIndex = 4;
            }
            firstSoundParams.mSoundId = 0x11a;
            firstSoundParams.mPositionSource = &chandelier->mMapObject.mPos;
            firstSoundParams.mFalloffIndex = falloffIndex;
            firstSoundParams.mDistanceSquared = GetHorizontalCameraDistanceSquared(&chandelier->mMapObject.mPos);
            StartSoundFromParams(&firstSoundParams);
        }
    } else if (chandelier->mFrameIndex == 0x46 || chandelier->mFrameIndex == 0xaf) {
        if ((chandelier->mMapObject.mDistanceSquaredAndFlags & 4) == 0) {
            if (chandelier->mMapObject.mFarDistanceSquared == gSoundFalloffs[2].mFarDistanceSquared) {
                falloffIndex = 2;
            } else if (chandelier->mMapObject.mFarDistanceSquared == gSoundFalloffs[3].mFarDistanceSquared) {
                falloffIndex = 3;
            } else {
                falloffIndex = 4;
            }
            secondSoundParams.mSoundId = 0x11b;
            secondSoundParams.mPositionSource = &chandelier->mMapObject.mPos;
            secondSoundParams.mFalloffIndex = falloffIndex;
            secondSoundParams.mDistanceSquared = GetHorizontalCameraDistanceSquared(&chandelier->mMapObject.mPos);
            StartSoundFromParams(&secondSoundParams);
        }
    } else if (chandelier->mFrameIndex == 0xfa) {
        if ((chandelier->mMapObject.mDistanceSquaredAndFlags & 4) == 0) {
            if (chandelier->mMapObject.mFarDistanceSquared == gSoundFalloffs[2].mFarDistanceSquared) {
                falloffIndex = 2;
            } else if (chandelier->mMapObject.mFarDistanceSquared == gSoundFalloffs[3].mFarDistanceSquared) {
                falloffIndex = 3;
            } else {
                falloffIndex = 4;
            }
            thirdSoundParams.mSoundId = 0x119;
            thirdSoundParams.mPositionSource = &chandelier->mMapObject.mPos;
            thirdSoundParams.mFalloffIndex = falloffIndex;
            thirdSoundParams.mDistanceSquared = GetHorizontalCameraDistanceSquared(&chandelier->mMapObject.mPos);
            StartSoundFromParams(&thirdSoundParams);
        }
    }
    nextFrameIndex = chandelier->mFrameIndex + 1;
    if (nextFrameIndex >= GetMapObjectModelNsbcaFrameCount(gChandelier)) {
        nextFrameIndex = 0;
    }
    chandelier->mFrameIndex = nextFrameIndex;
    if (chandelier->mFrameIndex == 0) {
        chandelier->mState = 0;
    }
}

void *CreateChandelierDrawList(void) {
    return CreateMapObjectDrawList1(CreateChandelier, DrawChandelier, NULL);
}

void *CreateChandelierUpdateList(void) {
    return CreateMapObjectUpdateList(InitChandelierObjects, UpdateChandelier, NULL);
}

void CreateRainStar(void *mapObjectList) {
    CreateMapObjectModelNsbtaAnimation(gRainStar = CreateMapObjectModelAnimated(mapObjectList, gRainStarNsbmdName),
                                       gRainStarNsbtaName);
    SetMapObjectModelPolygonId(gRainStar, 0x3f);
}

void DrawRainStar(void *mapObjectList, RainStar *rainStar) {
    u32 commandParam;
    MtxFx33 rotationMatrix;

    commandParam = 0x1e;
    NNS_G3dGeBufferOP_N(0x14, &commandParam, 1);
    rainStar->mMapObject.mMatrix.mRows[3].x = rainStar->mMapObject.mPos.x >> 4;
    rainStar->mMapObject.mMatrix.mRows[3].y = rainStar->mMapObject.mPos.y >> 4;
    rainStar->mMapObject.mMatrix.mRows[3].z = rainStar->mMapObject.mPos.z >> 4;
    NNS_G3dGeBufferOP_N(0x19, &rainStar->mMapObject.mMatrix, 0xc);
    if (rainStar->mMapObject.mAngle != 0) {
        MTX_RotY33_(&rotationMatrix, SIN_OF_ANGLE(rainStar->mMapObject.mAngle),
                    COS_OF_ANGLE(rainStar->mMapObject.mAngle));
        NNS_G3dGeBufferOP_N(0x1a, &rotationMatrix, 9);
    }
    NNS_G3dGeBufferOP_N(0x1b, &rainStar->mMapObject.mScale, 3);
    SetMapObjectModelNsbtaFrameIndex(gRainStar, rainStar->mFrameIndex);
    DrawMapObjectModel(mapObjectList, gRainStar, rainStar);
}

void UpdateRainStar(void *mapObjectList, RainStar *rainStar) {
    u16 frameCount;

    frameCount = GetMapObjectModelNsbtaFrameCount(gRainStar);
    rainStar->mFrameIndex += 1;
    if (rainStar->mFrameIndex >= frameCount) {
        rainStar->mFrameIndex = 0;
    }
    rainStar->mMapObject.mAngle += 0x111;
}

void *CreateRainStarDrawList(void) {
    return CreateMapObjectDrawList1(CreateRainStar, DrawRainStar, NULL);
}

void *CreateRainStarUpdateList(void) {
    return CreateMapObjectUpdateList(NULL, UpdateRainStar, NULL);
}
