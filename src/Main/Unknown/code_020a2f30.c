#include "Main/Unknown/code_020a2f30.h"
#include "Main/Unknown/code_02024974.h"
#include "Main/Unknown/code_0209b634.h"

#include "Main/Unknown/code_020a36a8.h"
#include "Main/Unknown/code_020a3690.h"
#include "Main/Unknown/code_020a392c.h"
#include "Main/Unknown/code_020a3948.h"
#include "Main/Unknown/code_0209bef0.h"
#include "Main/Unknown/code_0209b000.h"
#include "Main/Unknown/code_020e6fd4.h"
#include "Main/Unknown/code_021000d0.h"
#include "Main/Unknown/code_020d22c0.h"
#include "Main/Unknown/unk_0217a000.h"
#include "Main/Unknown/code_02061654.h"
#include "Main/Unknown/code_0206bcb0.h"
#include "Main/Unknown/code_020f36d8.h"
#include "Main/Unknown/code_02024000.h"
#include "Main/Unknown/code_020d4c28.h"
#include "Main/Unknown/code_0210b870.h"
#include "Main/Unknown/unk_021759c0.h"
#include "Main/Unknown/unk_0215d000.h"
#include "code_02146cbc.h"
#include "code_02147cd8.h"
#include "code_0201c528.h"
#include "code_02148538.h"
#include "ITCM/code_01ff8000.h"
#include "ITCM/code_01ff9000.h"
#include "Main/Unknown/code_020d3b10.h"
#include "Main/Unknown/code_020e6b58.h"
#include "Main/Unknown/code_02146000.h"
#include "Main/Unknown/unk_02156000.h"
#include "Main/Unknown/unk_02167000.h"
#include "Main/Unknown/unk_0217b000.h"
#include "Main/Unknown/code_020a3f18.h"
#include "Main/Unknown/code_02077bc0.h"

void InitBalloon(Balloon *balloon) {
    balloon->mKartIndex = -1;
    ParkMapObject(&balloon->mMapObject);
}

void CreateBalloon(MapObjectList *mapObjectList) {
    gBalloon = CreateMapObjectModelNsbmdNsbtp(mapObjectList, gBalloonNsbmdName, gBalloonNsbtpName);
    SetMapObjectModelPolygonId(gBalloon, 0x3f);
    SetMapObjectModelAlpha(gBalloon, 0x1a);
    SetMapObjectModelFogEnabled(gBalloon, 0);
    mapObjectList->mSortByDistance = 1;
}

void SetupDrawBalloon(void *mapObjectList) {
    Camera *currentCamera;

    currentCamera = GetCurrentCamera();
    data_0217b214.x = currentCamera->mPos.x >> 1;
    data_0217b214.y = currentCamera->mPos.y >> 1;
    data_0217b214.z = currentCamera->mPos.z >> 1;
    data_0217b208.x = currentCamera->mPos.x >> 3;
    data_0217b208.y = currentCamera->mPos.y >> 3;
    data_0217b208.z = currentCamera->mPos.z >> 3;
    QueueMapObjectModelMaterial(mapObjectList, gBalloon);
}

void DrawBalloon(void *mapObjectList, Balloon *balloon) {
    s32 drawListIndex;
    s32 drawCount;
    s32 i;
    s32 rotateZAngle;
    s32 drawScale;
    u32 distanceSquared;
    s32 scaleFactor;
    s32 w0;
    s32 w1;
    s32 w2;
    MtxFx33 rotateZMatrix;
    MtxFx33 listRotateZMatrix;
    s32 drawScaleVector[3];
    s32 scaleFactorVector[3];
    s32 listDrawScaleVector[3];
    s32 listScaleFactorVector[3];
    s32 translation[3];
    Balloon *listBalloon;

    if (balloon->mKartIndex >= 0) {
        if (GetKart(balloon->mKartIndex)->mVisible == 0) {
            return;
        }
    }
    drawCount = balloon->mDrawCount;
    if (drawCount == 1 && balloon->mDrawList == NULL) {
        distanceSquared = balloon->mMapObject.mDistanceSquaredAndFlags & ~0xc000001f;
        if (distanceSquared < 0x2710) {
            balloon->mDrawPos.x = data_0217b214.x + (balloon->mMapObject.mPos.x >> 1);
            balloon->mDrawPos.y = data_0217b214.y + (balloon->mMapObject.mPos.y >> 1);
            balloon->mDrawPos.z = data_0217b214.z + (balloon->mMapObject.mPos.z >> 1);
            balloon->mDrawScale = 0x800;
        } else if (distanceSquared < 0x9c40) {
            balloon->mDrawPos.x = data_0217b208.x + balloon->mMapObject.mPos.x - (balloon->mMapObject.mPos.x >> 3);
            balloon->mDrawPos.y = data_0217b208.y + balloon->mMapObject.mPos.y - (balloon->mMapObject.mPos.y >> 3);
            balloon->mDrawPos.z = data_0217b208.z + balloon->mMapObject.mPos.z - (balloon->mMapObject.mPos.z >> 3);
            balloon->mDrawScale = 0xe00;
        } else {
            balloon->mDrawPos = balloon->mMapObject.mPos;
            balloon->mDrawScale = 0x1000;
        }
        w0 = 0x1e;
        NNS_G3dGeBufferOP_N(0x14, &w0, 1);
        NNS_G3dGeBufferOP_N(0x19, SetViewTransposeMatrixPos(&balloon->mDrawPos), 12);
        if (balloon->mMapObject.mAngle != 0) {
            i = (balloon->mMapObject.mAngle >> 4) * 2;
            MTX_RotZ33_(&rotateZMatrix, FX_SinCosTable_[i + 1], FX_SinCosTable_[i]);
            NNS_G3dGeBufferOP_N(0x1a, &rotateZMatrix, 9);
        }
        drawScale = balloon->mDrawScale;
        drawScaleVector[0] = drawScale;
        drawScaleVector[1] = drawScale;
        drawScaleVector[2] = drawScale;
        NNS_G3dGeBufferOP_N(0x1b, drawScaleVector, 3);
        scaleFactor = balloon->mScaleFactor + balloon->mScaleSwing;
        if (scaleFactor != 0x1000) {
            scaleFactorVector[0] = scaleFactor;
            scaleFactorVector[1] = scaleFactor;
            scaleFactorVector[2] = scaleFactor;
            NNS_G3dGeBufferOP_N(0x1b, scaleFactorVector, 3);
        }
        SetMapObjectModelPolygonId(gBalloon, AllocPolygonIdWrapping());
        SetMapObjectModelNsbtpFrameIndex(gBalloon, balloon->mNsbtpFrameIndex);
        DrawMapObjectModel(mapObjectList, gBalloon, balloon);
    } else if (drawCount > 0) {
        distanceSquared = balloon->mMapObject.mDistanceSquaredAndFlags & ~0xc000001f;
        if (distanceSquared < 0x2710) {
            balloon->mDrawPos.x = data_0217b214.x + (balloon->mTargetPos.x >> 1);
            balloon->mDrawPos.y = data_0217b214.y + (balloon->mTargetPos.y >> 1);
            balloon->mDrawPos.z = data_0217b214.z + (balloon->mTargetPos.z >> 1);
            balloon->mDrawScale = 0x800;
        } else if (distanceSquared < 0x9c40) {
            balloon->mDrawPos.x = data_0217b208.x + balloon->mTargetPos.x - (balloon->mTargetPos.x >> 3);
            balloon->mDrawPos.y = data_0217b208.y + balloon->mTargetPos.y - (balloon->mTargetPos.y >> 3);
            balloon->mDrawPos.z = data_0217b208.z + balloon->mTargetPos.z - (balloon->mTargetPos.z >> 3);
            balloon->mDrawScale = 0xe00;
        } else {
            balloon->mDrawPos = balloon->mTargetPos;
            balloon->mDrawScale = 0x1000;
        }
        w1 = 0x1e;
        NNS_G3dGeBufferOP_N(0x14, &w1, 1);
        NNS_G3dGeBufferOP_N(0x19, SetViewRotatedMatrixPos(&balloon->mDrawPos), 12);
        drawScale = balloon->mDrawScale;
        listDrawScaleVector[0] = drawScale;
        listDrawScaleVector[1] = drawScale;
        listDrawScaleVector[2] = drawScale;
        NNS_G3dGeBufferOP_N(0x1b, listDrawScaleVector, 3);
        for (drawListIndex = 0; drawListIndex < drawCount; drawListIndex++) {
            i = data_02156720[drawCount - 1][drawListIndex];
            listBalloon = balloon->mDrawList[i];
            NNS_G3dGeBufferOP_N(0x11, NULL, 0);
            rotateZAngle = data_02156700[drawCount - 1][i];
            MTX_RotZ33_(&listRotateZMatrix, FX_CosIdx(rotateZAngle), FX_SinIdx(rotateZAngle));
            NNS_G3dGeBufferOP_N(0x1a, &listRotateZMatrix, 9);
            scaleFactor = listBalloon->mScaleFactor;
            if (scaleFactor != 0x1000) {
                listScaleFactorVector[0] = scaleFactor;
                listScaleFactorVector[1] = scaleFactor;
                listScaleFactorVector[2] = scaleFactor;
                NNS_G3dGeBufferOP_N(0x1b, listScaleFactorVector, 3);
            }
            translation[0] = 0;
            translation[1] = 0xf66;
            translation[2] = 0;
            NNS_G3dGeBufferOP_N(0x1c, translation, 3);
            SetMapObjectModelPolygonId(gBalloon, AllocPolygonIdWrapping());
            SetMapObjectModelNsbtpFrameIndex(gBalloon, listBalloon->mNsbtpFrameIndex);
            DrawMapObjectModel(mapObjectList, gBalloon, balloon);
            w2 = 1;
            NNS_G3dGeBufferOP_N(0x12, &w2, 1);
        }
    }
}

void SetBalloonEffectColor(Unk0201ca6c *effect, Balloon *balloon) {
    effect->mUnk_72 = GetKartPaletteColorFromTable(balloon->mNsbtpFrameIndex);
}

void FollowBalloonTarget(Balloon *balloon) {
    Kart *kart;
    Vec3 *q;
    Vec3 pullOffset;
    s32 pullRatio;
    s32 distanceLimit;
    s32 offsetX;
    s32 offsetY;
    s32 offsetZ;
    s32 absOffsetX;
    s32 absOffsetY;
    s32 absOffsetZ;
    s32 offsetDistance;

    if (balloon->mKartIndex < 0) {
        balloon->mMapObject.mPosStep.y = balloon->mMapObject.mPosStep.y + 0x1800;
    } else {
        kart = GetKart((u16) balloon->mKartIndex);
        q = &kart->mUnk_12c;
        balloon->mMapObject.mPosStep.x = balloon->mMapObject.mPosStep.x + (q->x + (q->x >> 1));
        balloon->mMapObject.mPosStep.y = balloon->mMapObject.mPosStep.y + (q->y + (q->y >> 1));
        balloon->mMapObject.mPosStep.z = balloon->mMapObject.mPosStep.z + (q->z + (q->z >> 1));
    }
    offsetX = (balloon->mMapObject.mPos.x + balloon->mMapObject.mPosStep.x) -
              (balloon->mTargetPos.x + balloon->mTargetVelocity.x);
    offsetZ = (balloon->mMapObject.mPos.z + balloon->mMapObject.mPosStep.z) -
              (balloon->mTargetPos.z + balloon->mTargetVelocity.z);
    distanceLimit = MUL_FIXED12_NO_ROUND(0xa000, balloon->mScaleFactor + balloon->mScaleSwing);
    absOffsetZ = offsetZ < 0 ? -offsetZ : offsetZ;
    absOffsetX = offsetX < 0 ? -offsetX : offsetX;
    offsetDistance = absOffsetX / 2 + absOffsetZ / 2;
    if (offsetDistance <= distanceLimit) {
        balloon->mHorizontalPullEnabled = 1;
    } else if (balloon->mHorizontalPullEnabled != 0) {
        if (offsetDistance > distanceLimit) {
            pullRatio = FX_Div(offsetDistance - distanceLimit, offsetDistance);
            pullOffset.x = MUL_FIXED12_NO_ROUND(offsetX, pullRatio);
            pullOffset.y = 0;
            pullOffset.z = MUL_FIXED12_NO_ROUND(offsetZ, pullRatio);
            VEC_Subtract(&balloon->mMapObject.mPos, &pullOffset, &balloon->mMapObject.mPos);
        }
    }
    offsetX = (balloon->mMapObject.mPos.x + balloon->mMapObject.mPosStep.x) -
              (balloon->mTargetPos.x + balloon->mTargetVelocity.x);
    offsetY = (balloon->mMapObject.mPos.y + balloon->mMapObject.mPosStep.y) -
              (balloon->mTargetPos.y + balloon->mTargetVelocity.y);
    offsetZ = (balloon->mMapObject.mPos.z + balloon->mMapObject.mPosStep.z) -
              (balloon->mTargetPos.z + balloon->mTargetVelocity.z);
    distanceLimit = (balloon->mScaleFactor + balloon->mScaleSwing) << 4;
    absOffsetY = offsetY < 0 ? -offsetY : offsetY;
    absOffsetX = offsetX < 0 ? -offsetX : offsetX;
    absOffsetZ = offsetZ < 0 ? -offsetZ : offsetZ;
    offsetDistance = absOffsetY + (absOffsetX >> 2) + (absOffsetZ >> 2);
    if (offsetDistance > distanceLimit) {
        pullRatio = FX_Div(offsetDistance - distanceLimit, offsetDistance);
        pullOffset.x = MUL_FIXED12_NO_ROUND(offsetX, pullRatio);
        pullOffset.y = MUL_FIXED12_NO_ROUND(offsetY, pullRatio);
        pullOffset.z = MUL_FIXED12_NO_ROUND(offsetZ, pullRatio);
        if (balloon->mKartIndex >= 0) {
            VEC_Subtract(&balloon->mMapObject.mPosStep, &pullOffset, &balloon->mMapObject.mPosStep);
        } else {
            VEC_Add(&balloon->mTargetVelocity, &pullOffset, &balloon->mTargetVelocity);
        }
    }
    VEC_Add(&balloon->mMapObject.mPos, &balloon->mMapObject.mPosStep, &balloon->mMapObject.mPos);
    VEC_Add(&balloon->mTargetPos, &balloon->mTargetVelocity, &balloon->mTargetPos);
}

u32 GetBalloonFlagBits(Balloon *balloon) {
    return balloon->mMapObject.mFlags & 0x12;
}

u32 GetBalloonDistanceSquared(Balloon *balloon) {
    return balloon->mMapObject.mDistanceSquaredAndFlags & ~0xc000001fu;
}

void UpdateBalloonAngle(Balloon *balloon) {
    Camera *currentCamera;
    Vec3 cameraOffset;
    u16 cameraAngle;
    s32 pairFirst;
    s32 pairSecond;
    s32 x;
    s32 y;
    s32 u;
    s32 w;

    currentCamera = GetCurrentCamera();
    cameraAngle = FX_Atan2Idx(currentCamera->mForward.x, currentCamera->mForward.z) - 0x4000;
    VEC_Subtract(&balloon->mMapObject.mPos, &currentCamera->mPos, &cameraOffset);
    pairFirst = SIN_OF_ANGLE(cameraAngle);
    pairSecond = COS_OF_ANGLE(cameraAngle);
    x = MUL_FIXED12_NO_ROUND(cameraOffset.z, pairSecond);
    y = MUL_FIXED12_NO_ROUND(cameraOffset.x, pairFirst);
    u = cameraOffset.y;
    VEC_Subtract(&balloon->mTargetPos, &currentCamera->mPos, &cameraOffset);
    w = MUL_FIXED12_NO_ROUND(cameraOffset.x, pairFirst) + MUL_FIXED12_NO_ROUND(cameraOffset.z, pairSecond);
    balloon->mMapObject.mAngle = FX_Atan2Idx(u - cameraOffset.y, -(y + x - w));
}

void UpdateBalloon(void *mapObjectList, Balloon *balloon) {
    Kart *kart;

    if (balloon->mKartIndex >= 0) {
        switch (balloon->mState) {
            case 0:
                balloon->mScaleSwing = balloon->mScaleSwing + balloon->mScaleSwingPerFrame;
                if (balloon->mScaleSwing >= 0) {
                    if (balloon->mScaleSwingPerFrame < 0) {
                        balloon->mScaleSwingPerFrame = -50;
                    } else {
                        balloon->mScaleSwingPerFrame = balloon->mScaleSwingPerFrame - 10;
                    }
                } else {
                    if (balloon->mScaleSwingPerFrame >= 0) {
                        balloon->mScaleSwingPerFrame = 50;
                    } else {
                        balloon->mScaleSwingPerFrame = balloon->mScaleSwingPerFrame + 10;
                    }
                }
                if (balloon->mKartIndex == gRaceSetup->mEntryIndex) {
                    if (IsRaceStarted() == 1) {
                        kart = GetKart((u16) balloon->mKartIndex);
                        StartBalloonScaleSound(kart, balloon->mScaleFactor + balloon->mScaleSwing,
                                               balloon->mScaleFactorPerFrame);
                    }
                }
                if (balloon->mDrawCount == 1 && balloon->mDrawList == NULL) {
                    FollowBalloonTarget(balloon);
                    if (GetBalloonFlagBits(balloon) != 0) {
                        return;
                    }
                    if (GetBalloonDistanceSquared(balloon) >= 0x9c40) {
                        return;
                    }
                    UpdateBalloonAngle(balloon);
                } else {
                    balloon->mMapObject.mPos.x = balloon->mTargetPos.x;
                    balloon->mMapObject.mPos.y = balloon->mTargetPos.y + 0xf666;
                    balloon->mMapObject.mPos.z = balloon->mTargetPos.z;
                }
                break;
            case 1:
                balloon->mScaleSwing = 0;
                balloon->mScaleFactor = balloon->mScaleFactor + balloon->mScaleFactorPerFrame;
                if (balloon->mScaleFactor >= 0x1000) {
                    balloon->mScaleFactorPerFrame = balloon->mScaleFactorPerFrame - 200;
                }
                if (balloon->mScaleFactorPerFrame < 0) {
                    if (balloon->mScaleFactor <= 0x1000) {
                        balloon->mScaleFactor = 0x1000;
                        balloon->mState = 2;
                    }
                }
                if (balloon->mDrawCount == 1 && balloon->mDrawList == NULL) {
                    FollowBalloonTarget(balloon);
                    if (GetBalloonFlagBits(balloon) != 0) {
                        return;
                    }
                    if (GetBalloonDistanceSquared(balloon) >= 0x9c40) {
                        return;
                    }
                    UpdateBalloonAngle(balloon);
                } else {
                    balloon->mMapObject.mPos.x = balloon->mTargetPos.x;
                    balloon->mMapObject.mPos.y = balloon->mTargetPos.y + 0xf666;
                    balloon->mMapObject.mPos.z = balloon->mTargetPos.z;
                }
                break;
            case 2:
                balloon->mScaleSwing = 0;
                balloon->mScaleFactor = 0x1000;
                if (balloon->mDrawCount == 1 && balloon->mDrawList == NULL) {
                    FollowBalloonTarget(balloon);
                    if (GetBalloonFlagBits(balloon) != 0) {
                        return;
                    }
                    if (GetBalloonDistanceSquared(balloon) >= 0x9c40) {
                        return;
                    }
                    UpdateBalloonAngle(balloon);
                } else {
                    balloon->mMapObject.mPos.x = balloon->mTargetPos.x;
                    balloon->mMapObject.mPos.y = balloon->mTargetPos.y + 0xf666;
                    balloon->mMapObject.mPos.z = balloon->mTargetPos.z;
                }
                break;
            default:
                return;
        }
    } else {
        balloon->mScaleSwing = 0;
        balloon->mScaleFactor = 0x1000;
        if (balloon->mNoKartTimer-- <= 0) {
            StartEffectWithCallback(0x5b, &balloon->mMapObject.mPos, balloon, SetBalloonEffectColor);
            StartEffectWithCallback(0x5c, &balloon->mMapObject.mPos, balloon, SetBalloonEffectColor);
            StartEffectWithCallback(0x5d, &balloon->mMapObject.mPos, balloon, SetBalloonEffectColor);
            QueueBalloonSound(&balloon->mMapObject.mPos, GetHorizontalCameraDistanceSquared(&balloon->mMapObject.mPos));
            ParkMapObject(&balloon->mMapObject);
        } else {
            balloon->mSwingAngle = balloon->mSwingAngle + balloon->mSwingAnglePerFrame;
            if (balloon->mSwingAngle >= 0) {
                if (balloon->mSwingAnglePerFrame < 0) {
                    balloon->mSwingAnglePerFrame = -0x640;
                } else {
                    balloon->mSwingAnglePerFrame = balloon->mSwingAnglePerFrame - 200;
                }
            } else {
                if (balloon->mSwingAnglePerFrame >= 0) {
                    balloon->mSwingAnglePerFrame = 0x640;
                } else {
                    balloon->mSwingAnglePerFrame = balloon->mSwingAnglePerFrame + 200;
                }
            }
        }
        balloon->mMapObject.mAngle = balloon->mSwingAngle + 0x4000;
        balloon->mMapObject.mPosStep.y = balloon->mMapObject.mPosStep.y + 0x59a;
        balloon->mTargetVelocity.y = balloon->mTargetVelocity.y - 0x2000;
        balloon->mMapObject.mPosStep.x = MUL_FIXED12_NO_ROUND(balloon->mMapObject.mPosStep.x, 0xc00);
        balloon->mMapObject.mPosStep.y = MUL_FIXED12_NO_ROUND(balloon->mMapObject.mPosStep.y, 0xc00);
        balloon->mMapObject.mPosStep.z = MUL_FIXED12_NO_ROUND(balloon->mMapObject.mPosStep.z, 0xc00);
        VEC_Add(&balloon->mMapObject.mPos, &balloon->mMapObject.mPosStep, &balloon->mMapObject.mPos);
        VEC_Add(&balloon->mTargetPos, &balloon->mTargetVelocity, &balloon->mTargetPos);
    }
}

void *CreateBalloonDrawList(void) {
    return CreateMapObjectDrawList2(CreateBalloon, DrawBalloon, SetupDrawBalloon);
}

void *CreateBalloonUpdateList(void) {
    return CreateMapObjectUpdateList(NULL, UpdateBalloon, NULL);
}

void ResetBalloons(void) {
    s32 i;
    MapObjectList *mapObjectList;
    Balloon *balloon;

    mapObjectList = FindMapObjectKindUpdateList(MAP_OBJECT_KIND_BALLOON);
    if (mapObjectList == NULL) {
        return;
    }
    for (i = 0; i < mapObjectList->mMapObjectCount && (balloon = mapObjectList->mMapObjects[i]) != NULL; i++) {
        if (balloon->mKartIndex >= 0) {
            balloon->mKartIndex = (u16) gRaceSetup->mEntryIndex;
            balloon->mScaleFactor = 0x1000;
            balloon->mScaleFactorPerFrame = 0;
            balloon->mScaleSwing = 0;
            balloon->mScaleSwingPerFrame = 0;
            balloon->mState = 2;
        } else if ((balloon->mMapObject.mFlags & 0x100) == 0) {
            ParkMapObject(&balloon->mMapObject);
        }
    }
}

Balloon *StartBalloon(u16 nsbtpFrameIndex, Vec3 *targetPos) {
    Balloon *balloon;

    balloon = UnparkFirstParkedMapObject(FindMapObjectKindUpdateList(MAP_OBJECT_KIND_BALLOON));
    if (balloon == NULL) {
        return NULL;
    }
    balloon->mTargetPos = *targetPos;
    balloon->mMapObject.mPos = balloon->mTargetPos;
    balloon->mScaleFactor = 0;
    balloon->mScaleFactorPerFrame = 0;
    balloon->mScaleSwing = 0;
    balloon->mScaleSwingPerFrame = 0;
    balloon->mHorizontalPullEnabled = 0;
    balloon->mNsbtpFrameIndex = nsbtpFrameIndex;
    balloon->mState = 0;
    return balloon;
}

void UpdateBalloonInflating(Balloon *balloon, u16 kartIndex, s32 scaleStep) {
    balloon->mKartIndex = kartIndex;
    balloon->mScaleFactorPerFrame = scaleStep;
    balloon->mScaleFactor = balloon->mScaleFactor + balloon->mScaleFactorPerFrame;
    balloon->mScaleSwing = 0;
    balloon->mScaleSwingPerFrame = 0;
    balloon->mState = 0;
    if (balloon->mScaleFactor >= 0x1000) {
        balloon->mScaleSwing = 0;
        balloon->mScaleFactorPerFrame = 0x258;
        balloon->mState = 1;
    }
}

void UpdateBalloonShrinking(Balloon *balloon, u16 kartIndex, s32 scaleStep) {
    balloon->mKartIndex = kartIndex;
    balloon->mScaleFactorPerFrame = -scaleStep;
    balloon->mScaleFactor = balloon->mScaleFactor + balloon->mScaleFactorPerFrame;
    balloon->mState = 0;
    if (balloon->mScaleFactor > 0) {
        return;
    }
    balloon->mScaleSwing = 0;
    balloon->mScaleFactor = 0;
    balloon->mKartIndex = -1;
    balloon->mDrawCount = 1;
    balloon->mDrawList = NULL;
    ParkMapObject(&balloon->mMapObject);
}
