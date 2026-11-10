#include "Main/Unknown/code_020a71c8.h"

#include "code_02146d78.h"
#include "Main/Unknown/code_02042044.h"
#include "Main/Unknown/unk_021759c0.h"
#include "Main/Unknown/code_0209bf70.h"
#include "Main/Unknown/code_0209bef0.h"
#include "Main/Unknown/code_020a10f0.h"
#include "Main/Unknown/code_020a3f2c.h"
#include "Main/Unknown/code_020a73b0.h"
#include "Main/Unknown/code_020a7eb0.h"
#include "Main/Unknown/code_020a7eb4.h"
#include "Main/Unknown/code_020d22c0.h"
#include "Main/Unknown/code_020f36d8.h"
#include "Main/Unknown/code_021000d0.h"
#include "Main/Unknown/code_020a737c.h"
#include "Main/Unknown/code_0209b634.h"
#include "Main/Unknown/code_0209b000.h"
#include "ITCM/code_01ff8000.h"
#include "ITCM/code_01ff9000.h"
#include "Main/Unknown/code_020d4c28.h"
#include "Main/Unknown/code_020d8918.h"
#include "Main/Unknown/code_020d8bc0.h"
#include "Main/Unknown/code_020d8cac.h"
#include "Main/Unknown/code_020e6b58.h"
#include "Main/Unknown/code_020f9c6c.h"
#include "Main/Unknown/code_0210b760.h"
#include "Main/Unknown/code_02146000.h"
#include "Main/Unknown/unk_0215d000.h"
#include "Main/Unknown/unk_0217b000.h"
#include "code_02146cbc.h"
#include "Main/Unknown/code_020a8098.h"
#include "Main/Unknown/code_020d26f8.h"
#include "Main/Unknown/unk_02156000.h"
#include "Main/Unknown/unk_02167000.h"
#include "Main/Unknown/code_020a8080.h"
#include "Main/Unknown/code_020d7da8.h"
#include "Main/Unknown/code_02077bc0.h"

void InitSanbo(Sanbo *sanbo) {
    InitGroupFollower(&sanbo->mFollower, sanbo->mUnk_000.mCourseMapRow, 0);
}

u8 CollideKartWithSanbo(Sanbo *sanbo, Kart *kart, u8 *b, u8 *c) {
    SoundStartParams soundStartParams;
    u32 d;

    d = *c;
    if (*b == 1) {
        StartSanboLaunch(sanbo);
        sanbo->mUnk_000.mFlags = sanbo->mUnk_000.mFlags | data_021567e4;
        sanbo->mUnk_000.mFlags = sanbo->mUnk_000.mFlags | data_021567e8;
        StartSoundIfKartStarOrKiller(&sanbo->mUnk_000, kart);
    } else {
        if (sanbo->mFastWobbleTimer == 0) {
            soundStartParams.mSoundId = 0x193;
            soundStartParams.mPositionSource = &sanbo->mUnk_000.mPos;
            soundStartParams.mFalloffIndex = 2;
            soundStartParams.mDistanceSquared = GetHorizontalCameraDistanceSquared(&sanbo->mUnk_000.mPos);
            StartSoundFromParams(&soundStartParams);
            sanbo->mSoundTimer = 0x14;
        }
        sanbo->mFastWobbleTimer = 0x3c;
    }
    return d;
}

u8 CollideItemObjectWithSanbo(Sanbo *sanbo, ItemObject *itemObject, u8 *b, u8 *c) {
    SoundStartParams soundStartParams;
    u32 d;

    d = *c;
    if (*b == 1) {
        StartSanboLaunch(sanbo);
        sanbo->mUnk_000.mFlags = sanbo->mUnk_000.mFlags | data_021567e4;
        sanbo->mUnk_000.mFlags = sanbo->mUnk_000.mFlags | data_021567e8;
    } else {
        if (sanbo->mFastWobbleTimer == 0) {
            soundStartParams.mSoundId = 0x193;
            soundStartParams.mPositionSource = &sanbo->mUnk_000.mPos;
            soundStartParams.mFalloffIndex = 2;
            soundStartParams.mDistanceSquared = GetHorizontalCameraDistanceSquared(&sanbo->mUnk_000.mPos);
            StartSoundFromParams(&soundStartParams);
            sanbo->mSoundTimer = 0x14;
        }
        sanbo->mFastWobbleTimer = 0x3c;
    }
    return d;
}

void CreateSanboHAndSanboB(void *a) {
    gSanboH = CreateMapObjectModelNsbmd(a, gSanboHNsbmdName);
    gSanboB = CreateMapObjectModelNsbmd(a, gSanboBNsbmdName);
    SetMapObjectModelPolygonId(gSanboH, 0x3f);
    SetMapObjectModelPolygonId(gSanboB, 0x3f);
}

u32 SanboSetupDrawReturnArgument(u32 p0) {
    return p0;
}

void DrawSanbo(void *a, Sanbo *sanbo) {
    s32 i;
    s32 pairIndex;
    s32 w0;
    s32 w1;
    s32 w2;
    MtxFx33 rotateZMatrix;
    MtxFx33 pieceRotateZMatrix;
    s32 startTranslation[3];
    s32 stackTranslation[3];
    s32 pieceTranslation[3];
    s32 pieceScaleVector[3];
    s32 stackedTranslation[3];
    s32 stackedScaleVector[3];
    s32 drawScale;

    w0 = 0x1e;
    NNS_G3dGeBufferOP_N(0x14, &w0, 1);
    switch (sanbo->mState) {
        case 0:
        case 1:
            NNS_G3dGeBufferOP_N(0x19, SetViewTransposeMatrixPos(&sanbo->mUnk_000.mPos), 12);
            startTranslation[0] = 0;
            startTranslation[1] = 0xa00;
            startTranslation[2] = 0;
            NNS_G3dGeBufferOP_N(0x1c, startTranslation, 3);
            for (i = 0; i < sanbo->mPieceCount; i++) {
                if (sanbo->mPieces[i].mRotateZAngle != 0) {
                    pairIndex = ((u16) sanbo->mPieces[i].mRotateZAngle >> 4) * 2;
                    MTX_RotZ33_(&rotateZMatrix, gPairsByAngle[pairIndex], gPairsByAngle[pairIndex + 1]);
                    NNS_G3dGeBufferOP_N(0x1a, &rotateZMatrix, 9);
                }
                if (i != 0) {
                    stackTranslation[0] = 0;
                    stackTranslation[1] = 0x1400;
                    stackTranslation[2] = 0x80;
                    NNS_G3dGeBufferOP_N(0x1c, stackTranslation, 3);
                }
                if (i == 3) {
                    QueueMapObjectModelMaterial(a, gSanboH);
                    DrawMapObjectModel(a, gSanboH, sanbo);
                } else {
                    QueueMapObjectModelMaterial(a, gSanboB);
                    DrawMapObjectModel(a, gSanboB, sanbo);
                }
            }
            break;
        case 2:
            for (i = 0; i < sanbo->mPieceCount; i++) {
                w1 = 0x1e;
                NNS_G3dGeBufferOP_N(0x14, &w1, 1);
                pieceTranslation[0] = 0;
                pieceTranslation[1] = 0xa00;
                pieceTranslation[2] = 0;
                NNS_G3dGeBufferOP_N(0x1c, pieceTranslation, 3);
                NNS_G3dGeBufferOP_N(0x19, SetViewTransposeMatrixPos(&sanbo->mPieces[i].mPos), 12);
                if ((sanbo->mUnk_000.mFlags & 0x12) == 0 && sanbo->mPieces[i].mRotateZAngle != 0) {
                    pairIndex = ((u16) sanbo->mPieces[i].mRotateZAngle >> 4) * 2;
                    MTX_RotZ33_(&pieceRotateZMatrix, gPairsByAngle[pairIndex], gPairsByAngle[pairIndex + 1]);
                    NNS_G3dGeBufferOP_N(0x1a, &pieceRotateZMatrix, 9);
                }
                drawScale = sanbo->mPieces[i].mDrawScale;
                if (drawScale < 0x1000) {
                    pieceScaleVector[0] = drawScale;
                    pieceScaleVector[1] = drawScale;
                    pieceScaleVector[2] = 0;
                    NNS_G3dGeBufferOP_N(0x1b, pieceScaleVector, 3);
                }
                if (i == 3) {
                    QueueMapObjectModelMaterial(a, gSanboH);
                    DrawMapObjectModel(a, gSanboH, sanbo);
                } else {
                    QueueMapObjectModelMaterial(a, gSanboB);
                    DrawMapObjectModel(a, gSanboB, sanbo);
                }
            }
            break;
        case 3:
            for (i = 0; i < sanbo->mPieceCount; i++) {
                w2 = 0x1e;
                NNS_G3dGeBufferOP_N(0x14, &w2, 1);
                NNS_G3dGeBufferOP_N(0x19, SetViewTransposeMatrixPos(&sanbo->mUnk_000.mPos), 12);
                stackedTranslation[2] = 0x80;
                stackedTranslation[0] = 0;
                stackedTranslation[1] = (i * 0x14000 + 0xa000) >> 4;
                NNS_G3dGeBufferOP_N(0x1c, stackedTranslation, 3);
                drawScale = sanbo->mPieces[i].mDrawScale;
                if (drawScale < 0x1000) {
                    stackedScaleVector[0] = drawScale;
                    stackedScaleVector[1] = drawScale;
                    stackedScaleVector[2] = 0;
                    NNS_G3dGeBufferOP_N(0x1b, stackedScaleVector, 3);
                }
                if (i == 3) {
                    QueueMapObjectModelMaterial(a, gSanboH);
                    DrawMapObjectModel(a, gSanboH, sanbo);
                } else {
                    QueueMapObjectModelMaterial(a, gSanboB);
                    DrawMapObjectModel(a, gSanboB, sanbo);
                }
            }
            break;
    }
}

void InitSanboObjects(MapObjectList *mapObjectList) {
    s32 pieceIndex;
    s32 i;
    Sanbo *sanbo;

    if (mapObjectList == NULL) {
        return;
    }
    for (i = 0; i < mapObjectList->mMapObjectCount && (sanbo = mapObjectList->mMapObjects[i]) != NULL; i++) {
        sanbo->mPathSpeed = (sanbo->mUnk_000.mCourseMapRow->mUnk_28 << 12) / 100;
        sanbo->mPieceCount = 4;
        for (pieceIndex = 0; pieceIndex < sanbo->mPieceCount; pieceIndex++) {
            sanbo->mPieces[pieceIndex].mWobbleAngle = 0;
            sanbo->mPieces[pieceIndex].mWobbleMid = 0;
            sanbo->mPieces[pieceIndex].mWobbleAmplitude = 0x71c;
            sanbo->mPieces[pieceIndex].mWobbleAmplitudePerFrame = 0;
            sanbo->mPieces[pieceIndex].mWobbleAnglePerFrame = 0x2d8;
            sanbo->mPieces[pieceIndex].mUnk_38 = 0;
            sanbo->mPieces[pieceIndex].mDrawScale = 0x1000;
            sanbo->mPieces[pieceIndex].mRotateZAngle = 0;
            sanbo->mPieces[pieceIndex].mWobbleDelayTimer = pieceIndex * 0x14;
        }
    }
}

s32 SanboFX_SinIdx(s32 a) {
    return gPairsByAngle[(a >> 4) * 2];
}

s32 SanboFX_MulInline(s32 a, s32 b) {
    return MUL_FIXED12_ROUNDED(a, b);
}

void UpdateSanbo(void *a, Sanbo *sanbo) {
    SoundStartParams soundStartParams;
    s32 m;
    s32 k;
    s32 i;
    s32 j;
    s32 t;
    s32 v;

    if (sanbo->mPathWaitTimer-- <= 0) {
        t = sanbo->mPathSpeed;
        sanbo->mFollower.mSpeed = t;
        sanbo->mFollower.mProgressStep = MUL_FIXED12_NO_ROUND(
            t, sanbo->mFollower.mPath->mSegments[sanbo->mFollower.mSegmentIndex].mInverseProgressLength);
        if (AdvanceGroupFollower(&sanbo->mFollower) != FALSE) {
            sanbo->mPathWaitTimer = (u16) sanbo->mFollower.mFromEntry->mUnk_0e;
        } else {
            sanbo->mPathWaitTimer = 0;
        }
        if (sanbo->mFollower.mPath->mWraps != 0) {
            GetGroupFollowerCurvePosStep(&sanbo->mFollower, &sanbo->mUnk_000.mPos, &sanbo->mUnk_000.mUnk_10);
        } else {
            GetGroupFollowerLinearPosStep(&sanbo->mFollower, &sanbo->mUnk_000.mPos, &sanbo->mUnk_000.mUnk_10);
        }
    } else {
        sanbo->mFollower.mSpeed = 0;
        sanbo->mFollower.mProgressStep = 0;
        sanbo->mUnk_000.mUnk_10.x = 0;
        sanbo->mUnk_000.mUnk_10.y = 0;
        sanbo->mUnk_000.mUnk_10.z = 0;
    }
    switch (sanbo->mState) {
        case 0:
            if ((sanbo->mUnk_000.mFlags & 0x12) != 0) {
                return;
            }
            for (i = 0; i < sanbo->mPieceCount; i++) {
                if (sanbo->mFastWobbleTimer > 0) {
                    sanbo->mPieces[i].mWobbleAnglePerFrame = 0xb61;
                } else if (sanbo->mPieces[i].mWobbleAnglePerFrame > 0x38e) {
                    sanbo->mPieces[i].mWobbleAnglePerFrame = sanbo->mPieces[i].mWobbleAnglePerFrame - 0xb6;
                } else {
                    sanbo->mPieces[i].mWobbleAnglePerFrame = 0x2d8;
                }
                if (sanbo->mPieces[i].mWobbleDelayTimer-- <= 0) {
                    sanbo->mPieces[i].mWobbleDelayTimer = 0;
                    sanbo->mPieces[i].mWobbleAngle =
                        sanbo->mPieces[i].mWobbleAngle + sanbo->mPieces[i].mWobbleAnglePerFrame;
                    sanbo->mPieces[i].mUnk_24 = sanbo->mPieces[i].mWobbleMid +
                                                SanboFX_MulInline(sanbo->mPieces[i].mWobbleAmplitude,
                                                                  SanboFX_SinIdx(sanbo->mPieces[i].mWobbleAngle)) -
                                                sanbo->mPieces[i].mWobbleValue;
                    sanbo->mPieces[i].mWobbleValue = sanbo->mPieces[i].mWobbleValue + sanbo->mPieces[i].mUnk_24;
                    t = sanbo->mPieces[i].mWobbleAmplitude;
                    if (t > 0) {
                        v = t + sanbo->mPieces[i].mWobbleAmplitudePerFrame;
                        if (v <= 0) {
                            v = 0;
                        }
                        sanbo->mPieces[i].mWobbleAmplitude = v;
                    } else if (t < 0) {
                        v = t + sanbo->mPieces[i].mWobbleAmplitudePerFrame;
                        if (v >= 0) {
                            v = 0;
                        }
                        sanbo->mPieces[i].mWobbleAmplitude = v;
                    }
                    t = sanbo->mPieces[i].mWobbleAnglePerFrame;
                    if (t > 0) {
                        v = t + sanbo->mPieces[i].mUnk_38;
                        if (v <= 0) {
                            v = 0;
                        }
                        sanbo->mPieces[i].mWobbleAnglePerFrame = v;
                    } else if (t < 0) {
                        v = t + sanbo->mPieces[i].mUnk_38;
                        if (v >= 0) {
                            v = 0;
                        }
                        sanbo->mPieces[i].mWobbleAnglePerFrame = v;
                    }
                    sanbo->mPieces[i].mRotateZAngle = (u16) sanbo->mPieces[i].mWobbleValue;
                }
            }
            if (sanbo->mFastWobbleTimer <= 0) {
                return;
            }
            sanbo->mFastWobbleTimer = sanbo->mFastWobbleTimer - 1;
            if (sanbo->mSoundTimer > 0) {
                sanbo->mSoundTimer = sanbo->mSoundTimer - 1;
                return;
            }
            if (sanbo->mPieces[0].mWobbleAngle <= 0x8000) {
                return;
            }
            if (sanbo->mPieces[0].mWobbleAngle >= 0xc000) {
                return;
            }
            soundStartParams.mSoundId = 0x194;
            soundStartParams.mPositionSource = &sanbo->mUnk_000.mPos;
            soundStartParams.mFalloffIndex = 2;
            soundStartParams.mDistanceSquared = GetHorizontalCameraDistanceSquared(&sanbo->mUnk_000.mPos);
            StartSoundFromParams(&soundStartParams);
            sanbo->mSoundTimer = 0x14;
            break;
        case 2:
            for (j = 0; j < sanbo->mPieceCount; j++) {
                if (sanbo->mPieces[j].mPos.y > 0) {
                    sanbo->mPieces[j].mPos.x = sanbo->mPieces[j].mPos.x + sanbo->mPieces[j].mVelocity.x;
                    sanbo->mPieces[j].mPos.y = sanbo->mPieces[j].mPos.y + sanbo->mPieces[j].mVelocity.y;
                    sanbo->mPieces[j].mPos.z = sanbo->mPieces[j].mPos.z + sanbo->mPieces[j].mVelocity.z;
                    sanbo->mPieces[j].mVelocity.y = sanbo->mPieces[j].mVelocity.y - 0x400;
                }
            }
            if ((sanbo->mUnk_000.mFlags & 0x12) == 0) {
                for (m = 0; m < sanbo->mPieceCount; m++) {
                    sanbo->mPieces[m].mRotateZAngle =
                        sanbo->mPieces[m].mRotateZAngle + sanbo->mPieces[m].mRotateZAnglePerFrame;
                }
            }
            if (sanbo->mUnk_000.mCourseMapRow->mUnk_2a != 0) {
                return;
            }
            if (sanbo->mState2Timer-- > 0) {
                return;
            }
            for (k = 0; k < sanbo->mPieceCount; k++) {
                sanbo->mPieces[k].mWobbleAngle = 0;
                sanbo->mPieces[k].mDrawScale = 0;
                sanbo->mPieces[k].mRotateZAngle = 0;
                sanbo->mPieces[k].mWobbleDelayTimer = k * 0x14;
            }
            sanbo->mPieceCount = 1;
            sanbo->mState = 3;
            sanbo->mUnk_000.mFlags = sanbo->mUnk_000.mFlags & ~1;
            sanbo->mUnk_000.mFlags = sanbo->mUnk_000.mFlags & ~8;
            break;
        case 3:
            sanbo->mPieces[sanbo->mPieceCount - 1].mDrawScale =
                sanbo->mPieces[sanbo->mPieceCount - 1].mDrawScale + 0xcd;
            if (sanbo->mPieces[sanbo->mPieceCount - 1].mDrawScale < 0x1000) {
                return;
            }
            sanbo->mPieces[sanbo->mPieceCount - 1].mDrawScale = 0x1000;
            sanbo->mPieceCount = sanbo->mPieceCount + 1;
            if (sanbo->mPieceCount > 4) {
                sanbo->mPieceCount = 4;
                sanbo->mState = 0;
            }
            break;
    }
}

void CreateSanboKindData(void) {
    CreateMapObjectKindData(&CollideKartWithSanbo, &CollideItemObjectWithSanbo, NULL, 1, 1);
}

void *CreateSanboDrawList(void) {
    return CreateMapObjectDrawList2(CreateSanboHAndSanboB, DrawSanbo, SanboSetupDrawReturnArgument);
}

void *CreateSanboUpdateList(void) {
    return CreateMapObjectUpdateList(InitSanboObjects, UpdateSanbo, NULL);
}

BOOL ShineKartHitCallback(u16 kartIndex, u16 hitByKartIndex) {
    if (GetBalloonOrShineCount(kartIndex) != 0) {
        AddBalloonOrShineCountAndMoveRank(kartIndex, -1);
        if (hitByKartIndex >= 8) {
            hitByKartIndex = kartIndex;
        }
        StartShine16FromKart(GetKart(kartIndex), GetKart(hitByKartIndex));
        return TRUE;
    }
    return FALSE;
}

void ShineKartEliminatedCallback(u16 kartIndex) {
    if (GetBalloonOrShineCount(kartIndex) == 0) {
        return;
    }
    AddBalloonOrShineCountAndMoveRank(kartIndex, -1);
    StartShine16FromKart(GetKart(kartIndex), GetKart(kartIndex));
}

void ShineEndCallback(void) {
    s32 i;
    MapObject *mapObject;
    MapObjectList *mapObjectList;

    mapObjectList = FindMapObjectKindUpdateList(0x6b);
    if (mapObjectList != NULL) {
        for (i = 0; i < mapObjectList->mMapObjectCount && (mapObject = mapObjectList->mMapObjects[i]) != NULL; i++) {
            if ((mapObject->mFlags & 0x100) == 0) {
                ParkMapObject(mapObject);
            }
        }
    }
    mapObjectList = FindMapObjectKindUpdateList(MAP_OBJECT_KIND_SHINE_BALLOON);
    if (mapObjectList != NULL) {
        for (i = 0; i < mapObjectList->mMapObjectCount && (mapObject = mapObjectList->mMapObjects[i]) != NULL; i++) {
            if ((mapObject->mFlags & 0x100) == 0) {
                ParkMapObject(mapObject);
            }
        }
    }
    ParkShine16Objects();
}
