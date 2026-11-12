#include "Main/MapObjects/picture_puddle.h"
#include "Main/Unknown/code_0209b634.h"
#include "ITCM/code_01ff8000.h"
#include "ITCM/code_01ff9000.h"
#include "Main/Unknown/code_0209b000.h"
#include "Main/Unknown/code_0209bef0.h"
#include "Main/MapObjects/map_object_park.h"
#include "Main/Unknown/code_020d4c28.h"
#include "Main/Unknown/code_0210b000.h"
#include "Main/Unknown/code_0210b760.h"
#include "Main/Unknown/code_020f36d8.h"
#include "Main/Unknown/unk_0217b000.h"
#include "Main/Unknown/unk_0217c000.h"
#include "Main/Unknown/unk_02167000.h"

void CreatePicture1AndPicture2(void *mapObjectList) {
    gPicture1 = CreateMapObjectModelAnimated(mapObjectList, gPicture1NsbmdName);
    CreateMapObjectModelNsbcaAnimation(gPicture1, gPicture1NsbcaName);
    gPicture2 = CreateMapObjectModelAnimated(mapObjectList, gPicture2NsbmdName);
    CreateMapObjectModelNsbcaAnimation(gPicture2, gPicture2NsbcaName);
    SetMapObjectModelPolygonId(gPicture1, 0x3f);
    SetMapObjectModelPolygonId(gPicture2, 0x3f);
}

void DrawPicture(void *mapObjectList, Picture *picture) {
    s32 commandParam;

    commandParam = 0x1e;
    NNS_G3dGeBufferOP_N(0x14, &commandParam, 1);
    picture->mMapObject.mMatrix.mRows[3].x = picture->mMapObject.mPos.x >> 4;
    picture->mMapObject.mMatrix.mRows[3].y = picture->mMapObject.mPos.y >> 4;
    picture->mMapObject.mMatrix.mRows[3].z = picture->mMapObject.mPos.z >> 4;
    NNS_G3dGeBufferOP_N(0x19, &picture->mMapObject.mMatrix, 0xc);
    NNS_G3dGeBufferOP_N(0x1b, &picture->mMapObject.mScale, 3);
    switch (picture->mPictureIndex) {
        case 0:
            SetMapObjectModelNsbcaFrameIndex(gPicture1, picture->mNsbcaFrameIndex);
            DrawMapObjectModel(mapObjectList, gPicture1, picture);
            break;
        case 1:
            SetMapObjectModelNsbcaFrameIndex(gPicture2, picture->mNsbcaFrameIndex);
            DrawMapObjectModel(mapObjectList, gPicture2, picture);
            break;
    }
}

// mState stays 0: nothing in the code sets state 1.
void UpdatePicture(void *mapObjectList, Picture *picture) {
    SoundStartParams firstSoundParams;
    SoundStartParams secondSoundParams;
    SoundStartParams thirdSoundParams;
    SoundStartParams fourthSoundParams;
    RandomState64 *randomState64;
    s32 nextFrameIndex;
    s32 falloffIndex;

    switch (picture->mState) {
        case 1:
            if (picture->mState1Timer-- <= 0) {
                picture->mState = 2;
            }
            break;
        case 2:
            if (picture->mPictureIndex == 0) {
                nextFrameIndex = picture->mNsbcaFrameIndex + 1;
                if (nextFrameIndex >= GetMapObjectModelNsbcaFrameCount(gPicture1)) {
                    nextFrameIndex = 0;
                }
                picture->mNsbcaFrameIndex = nextFrameIndex;
                if (picture->mNsbcaFrameIndex == 0 || picture->mNsbcaFrameIndex == 0xf ||
                    picture->mNsbcaFrameIndex == 0x1f || picture->mNsbcaFrameIndex == 0x37 ||
                    picture->mNsbcaFrameIndex == 0x51) {
                    if (IsMapObjectOutOfRange(&picture->mMapObject) == FALSE) {
                        if (picture->mMapObject.mFarDistanceSquared == gSoundFalloffs[2].mFarDistanceSquared) {
                            falloffIndex = 2;
                        } else if (picture->mMapObject.mFarDistanceSquared == gSoundFalloffs[3].mFarDistanceSquared) {
                            falloffIndex = 3;
                        } else {
                            falloffIndex = 4;
                        }
                        firstSoundParams.mSoundId = 0x116;
                        firstSoundParams.mPositionSource = &picture->mMapObject.mPos;
                        firstSoundParams.mFalloffIndex = falloffIndex;
                        firstSoundParams.mDistanceSquared =
                            GetHorizontalCameraDistanceSquared(&picture->mMapObject.mPos);
                        StartSoundFromParams(&firstSoundParams);
                    }
                } else if (picture->mNsbcaFrameIndex == 8 || picture->mNsbcaFrameIndex == 0x14 ||
                           picture->mNsbcaFrameIndex == 0x2c || picture->mNsbcaFrameIndex == 0x44) {
                    if (IsMapObjectOutOfRange(&picture->mMapObject) == FALSE) {
                        if (picture->mMapObject.mFarDistanceSquared == gSoundFalloffs[2].mFarDistanceSquared) {
                            falloffIndex = 2;
                        } else if (picture->mMapObject.mFarDistanceSquared == gSoundFalloffs[3].mFarDistanceSquared) {
                            falloffIndex = 3;
                        } else {
                            falloffIndex = 4;
                        }
                        secondSoundParams.mSoundId = 0x117;
                        secondSoundParams.mPositionSource = &picture->mMapObject.mPos;
                        secondSoundParams.mFalloffIndex = falloffIndex;
                        secondSoundParams.mDistanceSquared =
                            GetHorizontalCameraDistanceSquared(&picture->mMapObject.mPos);
                        StartSoundFromParams(&secondSoundParams);
                    }
                } else if (picture->mNsbcaFrameIndex == 0x78) {
                    if (IsMapObjectOutOfRange(&picture->mMapObject) == FALSE) {
                        if (picture->mMapObject.mFarDistanceSquared == gSoundFalloffs[2].mFarDistanceSquared) {
                            falloffIndex = 2;
                        } else if (picture->mMapObject.mFarDistanceSquared == gSoundFalloffs[3].mFarDistanceSquared) {
                            falloffIndex = 3;
                        } else {
                            falloffIndex = 4;
                        }
                        thirdSoundParams.mSoundId = 0x115;
                        thirdSoundParams.mPositionSource = &picture->mMapObject.mPos;
                        thirdSoundParams.mFalloffIndex = falloffIndex;
                        thirdSoundParams.mDistanceSquared =
                            GetHorizontalCameraDistanceSquared(&picture->mMapObject.mPos);
                        StartSoundFromParams(&thirdSoundParams);
                    }
                }
            } else if (picture->mPictureIndex == 1) {
                nextFrameIndex = picture->mNsbcaFrameIndex + 1;
                if (nextFrameIndex >= GetMapObjectModelNsbcaFrameCount(gPicture2)) {
                    nextFrameIndex = 0;
                }
                picture->mNsbcaFrameIndex = nextFrameIndex;
                if (picture->mNsbcaFrameIndex == 0) {
                    if (IsMapObjectOutOfRange(&picture->mMapObject) == FALSE) {
                        if (picture->mMapObject.mFarDistanceSquared == gSoundFalloffs[2].mFarDistanceSquared) {
                            falloffIndex = 2;
                        } else if (picture->mMapObject.mFarDistanceSquared == gSoundFalloffs[3].mFarDistanceSquared) {
                            falloffIndex = 3;
                        } else {
                            falloffIndex = 4;
                        }
                        fourthSoundParams.mSoundId = 0x118;
                        fourthSoundParams.mPositionSource = &picture->mMapObject.mPos;
                        fourthSoundParams.mFalloffIndex = falloffIndex;
                        fourthSoundParams.mDistanceSquared =
                            GetHorizontalCameraDistanceSquared(&picture->mMapObject.mPos);
                        StartSoundFromParams(&fourthSoundParams);
                    }
                }
            }
            if (picture->mNsbcaFrameIndex != 0) {
                return;
            }
            randomState64 = &gRaceProgress->mLocalRandom;
            randomState64->mValue = randomState64->mMultiplier * randomState64->mValue + randomState64->mIncrement;
            picture->mState1Timer = (u16) (((randomState64->mValue >> 32) * 0x78) >> 32) + 0x3c;
            picture->mState = 1;
            break;
    }
}

void *CreatePictureDrawList(void) {
    return CreateMapObjectDrawList1(CreatePicture1AndPicture2, DrawPicture, NULL);
}

void *CreatePictureUpdateList(void) {
    return CreateMapObjectUpdateList(NULL, UpdatePicture, NULL);
}
