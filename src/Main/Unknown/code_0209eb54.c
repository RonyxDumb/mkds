#include "Main/Unknown/code_0209eb54.h"
#include "Main/Unknown/code_0209b634.h"
#include "ITCM/code_01ff8000.h"
#include "ITCM/code_01ff9000.h"
#include "Main/Unknown/code_0209b000.h"
#include "Main/Unknown/code_0209bef0.h"
#include "Main/Unknown/code_020d22c0.h"
#include "Main/Unknown/code_020d4c28.h"
#include "Main/Unknown/code_0210b000.h"
#include "Main/Unknown/code_0210b760.h"
#include "Main/Unknown/code_020f36d8.h"
#include "Main/Unknown/unk_0217b000.h"
#include "Main/Unknown/unk_0217c000.h"
#include "Main/Unknown/unk_02167000.h"

void CreatePicture1AndPicture2(void *a) {
    gPicture1 = CreateMapObjectModelAnimated(a, gPicture1NsbmdName);
    CreateMapObjectModelNsbcaAnimation(gPicture1, gPicture1NsbcaName);
    gPicture2 = CreateMapObjectModelAnimated(a, gPicture2NsbmdName);
    CreateMapObjectModelNsbcaAnimation(gPicture2, gPicture2NsbcaName);
    SetMapObjectModelPolygonId(gPicture1, 0x3f);
    SetMapObjectModelPolygonId(gPicture2, 0x3f);
}

void DrawPicture(void *a, Picture *b) {
    s32 s;

    s = 0x1e;
    NNS_G3dGeBufferOP_N(0x14, &s, 1);
    b->mMapObject.mMatrix.mUnk_00[3].x = b->mMapObject.mPos.x >> 4;
    b->mMapObject.mMatrix.mUnk_00[3].y = b->mMapObject.mPos.y >> 4;
    b->mMapObject.mMatrix.mUnk_00[3].z = b->mMapObject.mPos.z >> 4;
    NNS_G3dGeBufferOP_N(0x19, &b->mMapObject.mMatrix, 0xc);
    NNS_G3dGeBufferOP_N(0x1b, &b->mMapObject.mScale, 3);
    switch (b->mPictureIndex) {
        case 0:
            SetMapObjectModelNsbcaFrameIndex(gPicture1, b->mNsbcaFrameIndex);
            DrawMapObjectModel(a, gPicture1, b);
            break;
        case 1:
            SetMapObjectModelNsbcaFrameIndex(gPicture2, b->mNsbcaFrameIndex);
            DrawMapObjectModel(a, gPicture2, b);
            break;
    }
}

// mState stays 0: nothing in the code sets state 1.
void UpdatePicture(void *a, Picture *b) {
    SoundStartParams s1;
    SoundStartParams s2;
    SoundStartParams s3;
    SoundStartParams s4;
    RandomState64 *randomState64;
    s32 nextFrameIndex;
    s32 t;

    switch (b->mState) {
        case 1:
            if (b->mState1Timer-- <= 0) {
                b->mState = 2;
            }
            break;
        case 2:
            if (b->mPictureIndex == 0) {
                nextFrameIndex = b->mNsbcaFrameIndex + 1;
                if (nextFrameIndex >= GetMapObjectModelNsbcaFrameCount(gPicture1)) {
                    nextFrameIndex = 0;
                }
                b->mNsbcaFrameIndex = nextFrameIndex;
                if (b->mNsbcaFrameIndex == 0 || b->mNsbcaFrameIndex == 0xf || b->mNsbcaFrameIndex == 0x1f ||
                    b->mNsbcaFrameIndex == 0x37 || b->mNsbcaFrameIndex == 0x51) {
                    if (IsMapObjectOutOfRange(&b->mMapObject) == FALSE) {
                        if (b->mMapObject.mFarDistanceSquared == gSoundFalloffs[2].mUnk_20) {
                            t = 2;
                        } else if (b->mMapObject.mFarDistanceSquared == gSoundFalloffs[3].mUnk_20) {
                            t = 3;
                        } else {
                            t = 4;
                        }
                        s1.mSoundId = 0x116;
                        s1.mPositionSource = &b->mMapObject.mPos;
                        s1.mFalloffIndex = t;
                        s1.mDistanceSquared = GetHorizontalCameraDistanceSquared(&b->mMapObject.mPos);
                        StartSoundFromParams(&s1);
                    }
                } else if (b->mNsbcaFrameIndex == 8 || b->mNsbcaFrameIndex == 0x14 || b->mNsbcaFrameIndex == 0x2c ||
                           b->mNsbcaFrameIndex == 0x44) {
                    if (IsMapObjectOutOfRange(&b->mMapObject) == FALSE) {
                        if (b->mMapObject.mFarDistanceSquared == gSoundFalloffs[2].mUnk_20) {
                            t = 2;
                        } else if (b->mMapObject.mFarDistanceSquared == gSoundFalloffs[3].mUnk_20) {
                            t = 3;
                        } else {
                            t = 4;
                        }
                        s2.mSoundId = 0x117;
                        s2.mPositionSource = &b->mMapObject.mPos;
                        s2.mFalloffIndex = t;
                        s2.mDistanceSquared = GetHorizontalCameraDistanceSquared(&b->mMapObject.mPos);
                        StartSoundFromParams(&s2);
                    }
                } else if (b->mNsbcaFrameIndex == 0x78) {
                    if (IsMapObjectOutOfRange(&b->mMapObject) == FALSE) {
                        if (b->mMapObject.mFarDistanceSquared == gSoundFalloffs[2].mUnk_20) {
                            t = 2;
                        } else if (b->mMapObject.mFarDistanceSquared == gSoundFalloffs[3].mUnk_20) {
                            t = 3;
                        } else {
                            t = 4;
                        }
                        s3.mSoundId = 0x115;
                        s3.mPositionSource = &b->mMapObject.mPos;
                        s3.mFalloffIndex = t;
                        s3.mDistanceSquared = GetHorizontalCameraDistanceSquared(&b->mMapObject.mPos);
                        StartSoundFromParams(&s3);
                    }
                }
            } else if (b->mPictureIndex == 1) {
                nextFrameIndex = b->mNsbcaFrameIndex + 1;
                if (nextFrameIndex >= GetMapObjectModelNsbcaFrameCount(gPicture2)) {
                    nextFrameIndex = 0;
                }
                b->mNsbcaFrameIndex = nextFrameIndex;
                if (b->mNsbcaFrameIndex == 0) {
                    if (IsMapObjectOutOfRange(&b->mMapObject) == FALSE) {
                        if (b->mMapObject.mFarDistanceSquared == gSoundFalloffs[2].mUnk_20) {
                            t = 2;
                        } else if (b->mMapObject.mFarDistanceSquared == gSoundFalloffs[3].mUnk_20) {
                            t = 3;
                        } else {
                            t = 4;
                        }
                        s4.mSoundId = 0x118;
                        s4.mPositionSource = &b->mMapObject.mPos;
                        s4.mFalloffIndex = t;
                        s4.mDistanceSquared = GetHorizontalCameraDistanceSquared(&b->mMapObject.mPos);
                        StartSoundFromParams(&s4);
                    }
                }
            }
            if (b->mNsbcaFrameIndex != 0) {
                return;
            }
            randomState64 = &gRaceProgress->mLocalRandom;
            randomState64->mValue = randomState64->mMultiplier * randomState64->mValue + randomState64->mIncrement;
            b->mState1Timer = (u16) (((randomState64->mValue >> 32) * 0x78) >> 32) + 0x3c;
            b->mState = 1;
            break;
    }
}

void *CreatePictureDrawList(void) {
    return CreateMapObjectDrawList1(CreatePicture1AndPicture2, DrawPicture, NULL);
}

void *CreatePictureUpdateList(void) {
    return CreateMapObjectUpdateList(NULL, UpdatePicture, NULL);
}

void CreatePuddle(void *a) {
    gPuddle = CreateMapObjectModelNsbmd(a, gPuddleNsbmdName);
}

void SetupDrawPuddle(void *a) {
    QueueMapObjectModelMaterial(a, gPuddle);
}

void DrawPuddle(void *a, MapObject *b) {
    s32 s;
    s32 x;
    s32 y;
    s32 z;
    Vec3 v;

    s = 0x1e;
    NNS_G3dGeBufferOP_N(0x14, &s, 1);
    z = b->mPos.z >> 4;
    y = (b->mPos.y + 0x1ccd) >> 4;
    x = b->mPos.x >> 4;
    v.x = x;
    v.y = y;
    v.z = z;
    NNS_G3dGeBufferOP_N(0x1c, &v, 3);
    NNS_G3dGeBufferOP_N(0x1b, &b->mScale, 3);
    NNS_G3dGeBufferOP_N(0x1a, &b->mMatrix, 9);
    DrawMapObjectModel(a, gPuddle, b);
}
