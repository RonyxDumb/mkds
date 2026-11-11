#include "Main/Unknown/code_020daf20.h"
#include "Main/Unknown/code_02036820.h"
#include "Main/Unknown/code_020467d0.h"
#include "Main/Unknown/code_0208b484.h"
#include "Main/Unknown/code_020d2dec.h"
#include "Main/Unknown/code_020d4c28.h"
#include "Main/Unknown/code_020d50ec.h"
#include "Main/Unknown/code_020d8b88.h"
#include "code_02146cbc.h"
#include "code_02148538.h"
#include "Main/Unknown/code_020ea588.h"
#include "Main/Unknown/code_020ea55c.h"
#include "Main/Unknown/code_02084000.h"
#include "Main/Unknown/code_020d3000.h"
#include "Main/Unknown/code_020d5000.h"
#include "Main/Unknown/code_02046000.h"
#include "Main/Unknown/code_02046be8.h"
#include "Main/Unknown/unk_02158000.h"
#include "Main/Unknown/unk_0216b000.h"
#include "Main/Unknown/code_020dda38.h"
#include "ITCM/code_01ffba68.h"
#include "ITCM/code_01ffc000.h"
#include "code_02147cd8.h"
#include "Main/Unknown/unk_021759c0.h"
#include "Main/Unknown/code_02146000.h"
#include "code_02146d78.h"
#include "Main/Unknown/code_020ea670.h"
#include "Main/Unknown/unk_0215d000.h"
#include "Main/Unknown/code_020d4000.h"
#include "Main/Unknown/code_020d2000.h"
#include "Main/Unknown/code_020d8648.h"
#include "Main/Unknown/code_020d8918.h"
#include "Main/Unknown/code_0208b000.h"
#include "Main/Unknown/code_02073000.h"
#include "Main/Unknown/code_0210b760.h"
#include "Main/Unknown/unk_0217c000.h"
#include "Main/Unknown/code_020d275c.h"
#include "Main/Unknown/code_020d6dc0.h"
#include "Main/Unknown/code_020d849c.h"
#include "Main/Unknown/code_02061654.h"
#include "Main/Unknown/code_0206bcb0.h"
#include "Main/Unknown/code_020d8cac.h"
#include "Main/Unknown/code_020d8000.h"
#include "Main/Unknown/code_020d7da8.h"
#include "Main/Unknown/code_020d49d8.h"
#include "Main/Unknown/code_020e6f50.h"
#include "Main/Unknown/code_020364e0.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_020e66e4.h"
#include "Main/Unknown/unk_0217b000.h"
#include "Main/Unknown/code_020d88fc.h"
#include "Main/Unknown/code_020e6b58.h"
#include "Main/Unknown/code_020f36d8.h"

#pragma thumb off

MapObjectKindData *CreateDossunKindData(void) {
    MapObjectKindData *kindData;
    kindData = HeapAlloc(GetHeap(GetCurrentHeapCall()), 0x40);
    *kindData = data_0215828c;
    return kindData;
}

Unk020dbed0 *CreateDossunDrawList(void) {
    Unk020dbed0 *drawList;
    drawList = HeapAlloc(GetHeap(GetCurrentHeapCall()), 0x2c);
    gDossunDrawList = drawList;
    *drawList = data_02158260;
    SetDrawListSlot(&gDossunDrawList);
    return gDossunDrawList;
}

MapObjectList *CreateDossunUpdateList(void) {
    MapObjectList *updateList;
    updateList = HeapAlloc(GetHeap(GetCurrentHeapCall()), 0x28);
    gDossunUpdateList = updateList;
    *updateList = data_02158238;
    SetUpdateListSlot(&gDossunUpdateList);
    return gDossunUpdateList;
}

void DrawDossun(void *unused0, Dossun *dossun, void *unused1, s32 maxAlpha) {
    MtxFx43 *drawMatrix;
    drawMatrix = &dossun->mMapObject.mMatrix;
    if (dossun->mHitState != 0) {
        drawMatrix = &gDossunDrawMatrix;
        MTX_RotY33_(&gDossunDrawMatrix.mAxes, FX_SinIdx((u16) dossun->mSpinAngle), FX_CosIdx((u16) dossun->mSpinAngle));
        MTX_Concat33(&gDossunDrawMatrix.mAxes, &dossun->mMapObject.mMatrix.mAxes, &gDossunDrawMatrix.mAxes);
    }
    drawMatrix->mRows[3].x = dossun->mMapObject.mPos.x >> 4;
    drawMatrix->mRows[3].y = dossun->mMapObject.mPos.y >> 4;
    drawMatrix->mRows[3].z = dossun->mMapObject.mPos.z >> 4;
    DrawNsbmdWithMatrixAndMaxAlpha(gDossun, drawMatrix, &dossun->mMapObject.mScale, maxAlpha);
    DrawShadowWithMaxAlpha(gDossunShadow, drawMatrix, &dossun->mMapObject.mScale, maxAlpha);
}

void UpdateDossun(void *unused, Dossun *dossun) {
    SoundStartParams soundRequest;
    GroupFollower *follower;
    CourseMapGroupEntry *fromEntry;
    s32 stateValue;
    s32 speed;
    s32 t;
    s32 sine;
    dossun->mEnteredState5 = FALSE;
    follower = &dossun->mFollower;
    if (dossun->mHitState != 0) {
        dossun->mSpinAngle += dossun->mSpinSpeed;
        stateValue = dossun->mSpinSpeed;
        if (stateValue > 0x3e8 || stateValue < -0x3e8) {
            if (dossun->mState < 4) {
                dossun->mSpinSpeed = (stateValue * 0xfa00) >> 16;
            } else {
                dossun->mSpinSpeed = (stateValue * 0xf80c) >> 16;
            }
        } else if (dossun->mHitState == 2) {
            if (stateValue * dossun->mSpinAngle <= 0) {
                return;
            }
            if (stateValue * stateValue <= dossun->mSpinAngle * dossun->mSpinAngle) {
                return;
            }
            dossun->mSpinSpeed = 0;
            dossun->mSpinAngle = dossun->mSpinSpeed;
            dossun->mHitState = 0;
            dossun->mKartMask = 0;
            dossun->mTimer = 0x1e;
            dossun->mState = 0;
            return;
        }
        if (dossun->mHitState != 1) {
            return;
        }
        speed = follower->mSpeed;
        if (dossun->mState < 4) {
            if (speed > 0x4000) {
                t = MUL_FIXED12_NO_ROUND(speed, 0xf85);
                follower->mSpeed = t;
                follower->mProgressStep =
                    MUL_FIXED12_NO_ROUND(t, follower->mPath->mSegments[follower->mSegmentIndex].mInverseProgressLength);
            }
        } else {
            if (speed > 0x800) {
                t = MUL_FIXED12_NO_ROUND(speed, 0xe66);
                follower->mSpeed = t;
                follower->mProgressStep =
                    MUL_FIXED12_NO_ROUND(t, follower->mPath->mSegments[follower->mSegmentIndex].mInverseProgressLength);
            }
        }
        if (AdvanceGroupFollower(follower) != FALSE) {
            dossun->mMapObject.mPos = follower->mFromEntry->mPos;
            dossun->mMapObject.mPos.y += dossun->mHeightOffset;
            if (follower->mForward != 0) {
                follower->mProgress = 0;
            } else {
                ReverseGroupFollower(follower);
                SetGroupFollowerSegmentEnd(follower);
            }
            dossun->mHitState = 2;
            return;
        }
        GetGroupFollowerLinearPosition(follower, &dossun->mMapObject.mPos);
        dossun->mMapObject.mPos.y += dossun->mHeightOffset;
        return;
    }
    switch (dossun->mState) {
        case 0:
            dossun->mTimer--;
            if (dossun->mTimer >= 0) {
                return;
            }
            dossun->mState++;
            t = dossun->mIsSlowVariant != 0 ? 0xc00 : 0x3000;
            follower->mSpeed = t;
            follower->mProgressStep =
                MUL_FIXED12_NO_ROUND(t, follower->mPath->mSegments[follower->mSegmentIndex].mInverseProgressLength);
            return;
        case 1:
            if (dossun->mIsSlowVariant != 0) {
                StartMapObjectSoundWhileRequested(&dossun->mMapObject, 0x18b);
            }
            break;
        case 2:
            dossun->mTimer--;
            if (dossun->mTimer < 0 && dossun->mUnk_c2 < 0x1555) {
                dossun->mState++;
                dossun->mUnk_a8 = -dossun->mUnk_100;
                return;
            }
            dossun->mUnk_c2 += 0x1555;
            dossun->mMapObject.mPos.y = dossun->mUnk_ac;
            sine = FX_SinIdx(dossun->mUnk_c2);
            dossun->mMapObject.mPos.y += MUL_FIXED12_NO_ROUND(sine, dossun->mUnk_c4);
            return;
        case 3:
            dossun->mUnk_a8 += dossun->mUnk_104;
            dossun->mMapObject.mPos.y -= dossun->mUnk_a8;
            if (dossun->mMapObject.mPos.y < dossun->mUnk_ac) {
                dossun->mState++;
            }
            return;
        case 4:
            if (dossun->mUnk_a8 < 0x14000) {
                dossun->mUnk_a8 += 0x1000;
                t = dossun->mUnk_a8;
                follower->mSpeed = t;
                follower->mProgressStep =
                    MUL_FIXED12_NO_ROUND(t, follower->mPath->mSegments[follower->mSegmentIndex].mInverseProgressLength);
            }
            break;
        case 5:
            dossun->mTimer--;
            if (dossun->mTimer >= 0) {
                return;
            }
            dossun->mState++;
            t = dossun->mUnk_108;
            follower->mSpeed = t;
            follower->mProgressStep =
                MUL_FIXED12_NO_ROUND(t, follower->mPath->mSegments[follower->mSegmentIndex].mInverseProgressLength);
            return;
        case 6:
            break;
    }
    if (AdvanceGroupFollower(follower) != FALSE) {
        switch (follower->mFromEntry->mUnk_10) {
            case 0:
                stateValue = 0;
                break;
            case 1:
                stateValue = 2;
                break;
            case 2:
                stateValue = 5;
                break;
            default:
                stateValue = 0;
                break;
        }
        dossun->mState = stateValue;
        if (dossun->mState == 2) {
            dossun->mUnk_ac = dossun->mMapObject.mPos.y;
            dossun->mUnk_c2 = 0;
        }
        if (dossun->mState == 5) {
            fromEntry = follower->mFromEntry;
            if (IsMapObjectOutOfRange(&dossun->mMapObject) == FALSE) {
                if (dossun->mMapObject.mFarDistanceSquared == gSoundFalloffs[2].mFarDistanceSquared) {
                    stateValue = 2;
                } else if (dossun->mMapObject.mFarDistanceSquared == gSoundFalloffs[3].mFarDistanceSquared) {
                    stateValue = 3;
                } else {
                    stateValue = 4;
                }
                soundRequest.mSoundId = 0x166;
                soundRequest.mPositionSource = &dossun->mMapObject.mPos;
                soundRequest.mFalloffIndex = stateValue;
                soundRequest.mDistanceSquared = GetHorizontalCameraDistanceSquared(&dossun->mMapObject.mPos);
                StartSoundFromParams(&soundRequest);
            }
            StartCameraWobbleAtDistance(dossun->mMapObject.mDistanceSquaredAndFlags & ~0xc000001f, 0x1000);
            if ((dossun->mMapObject.mDistanceSquaredAndFlags & 3) == 0) {
                StartEffect(0x59, &fromEntry->mPos);
                StartEffect(0x5a, &fromEntry->mPos);
            }
            dossun->mEnteredState5 = TRUE;
        }
        dossun->mTimer = follower->mFromEntry->mUnk_0e;
        if (dossun->mTimer != 0) {
            dossun->mMapObject.mPos = follower->mPath->mSegments[follower->mSegmentIndex].mPoints[0];
            dossun->mMapObject.mPos.y += dossun->mHeightOffset;
            follower->mProgress = 0;
            return;
        }
    }
    GetGroupFollowerLinearPosition(follower, &dossun->mMapObject.mPos);
    dossun->mMapObject.mPos.y += dossun->mHeightOffset;
}

u32 CollideKartWithDossun(Dossun *dossun, Kart *kart, u8 *firstResponsePtr, u8 *secondResponsePtr) {
    Vec3 kartOffset;
    Vec3 toNextEntry;
    Vec3 centerOffset;
    GroupFollower *follower;
    s32 speed;
    s64 verticalScaledSquared;
    s32 verticalOffset;
    s64 horizontalScaledSquared;
    follower = &dossun->mFollower;
    if (*firstResponsePtr == 1) {
        if ((dossun->mKartMask & (1 << kart->mIndex)) == 0 || dossun->mLastHitFrame + 0xf < GetRaceUpdateFrames()) {
            VEC_Subtract(&kart->mCollisionCenter, &dossun->mMapObject.mPos, &kartOffset);
            VEC_Subtract(&follower->mToEntry->mPos, &dossun->mMapObject.mPos, &toNextEntry);
            toNextEntry.y += dossun->mHeightOffset;
            if (Vec3DotUnrounded(&kartOffset, &toNextEntry) > 0) {
                ReverseGroupFollower(follower);
            }
            if (dossun->mState < 4) {
                speed = 0xa800;
            } else {
                speed = 0x8000;
            }
            speed = speed - MUL_FIXED12_NO_ROUND(0x1000 - dossun->mMapObject.mScale.y, 0x2000);
            follower->mSpeed = speed;
            follower->mProgressStep =
                MUL_FIXED12_NO_ROUND(speed, follower->mPath->mSegments[follower->mSegmentIndex].mInverseProgressLength);
            dossun->mHitState = 1;
            dossun->mSpinSpeed = 0x1b58;
            if ((s64) kartOffset.z * kart->mVelocity.x - (s64) kartOffset.x * kart->mVelocity.z < 0) {
                dossun->mSpinSpeed = -dossun->mSpinSpeed;
            }
            StartSoundIfKartStarOrKiller(&dossun->mMapObject, kart);
            dossun->mKartMask |= 1 << kart->mIndex;
            dossun->mLastHitFrame = GetRaceUpdateFrames();
        }
    }
    if (dossun->mState == 4 || dossun->mEnteredState5 != FALSE) {
        VEC_Subtract(&kart->mCollisionCenter, &dossun->mMapObject.mPos, &centerOffset);
        horizontalScaledSquared = (HORIZONTAL_LENGTH_SQUARED(centerOffset)) * 5;
        verticalOffset = centerOffset.y;
        verticalScaledSquared = ((s64) verticalOffset * verticalOffset) << 2;
        if (verticalOffset < 0 && horizontalScaledSquared < verticalScaledSquared) {
            return GetKartMapObjectResponseByKind(dossun->mMapObject.mFlags & 0x800, kart->mItemEffect, 4, 4);
        }
    }
    return *secondResponsePtr;
}

s32 GetDossunMapDotOffset(Dossun *dossun) {
    s32 progress;
    s32 state;
    progress = GetGroupFollowerProgress(&dossun->mFollower);
    state = dossun->mState;
    if (state < 4) {
        if (dossun->mIsSlowVariant != 0) {
            return 0;
        }
        return 0x1000;
    }
    switch (dossun->mHitState) {
        case 0:
            switch (state) {
                case 4:
                    progress = 0x1000 - progress;
                    break;
                case 5:
                    progress = 0;
                    break;
                case 6:
                    break;
            }
            break;
        case 2:
            progress = 0x1000;
            break;
    }
    return progress;
}

#pragma thumb on
void SetupDossunAtStartEntry(Dossun *dossun) {
    GroupFollower *follower;
    s32 state;
    follower = &dossun->mFollower;
    SetupGroupFollowerAtEntry(follower, dossun->mStartEntryIndex, 1);
    GetGroupFollowerLinearPosition(follower, &dossun->mMapObject.mPos);
    dossun->mMapObject.mPos.y += dossun->mHeightOffset;
    switch (follower->mFromEntry->mUnk_10) {
        case 0:
            state = 0;
            break;
        case 1:
            state = 2;
            break;
        case 2:
            state = 5;
            break;
        default:
            state = 0;
            break;
    }
    dossun->mState = state;
    dossun->mTimer = follower->mFromEntry->mUnk_0e;
    dossun->mHitState = 0;
    dossun->mSpinAngle = 0;
    dossun->mSpinSpeed = dossun->mSpinAngle;
    dossun->mKartMask = 0;
    dossun->mUnk_ac = dossun->mMapObject.mPos.y;
    dossun->mEnteredState5 = FALSE;
}
#pragma thumb off

#pragma thumb on
void CreateDossunAndDossunShadow(void) {
    CreateNsbmd(&gDossun, FindCourseMapObjFile("dossun.nsbmd"), NULL);
    CreateShadowModel(&gDossunShadow, FindCourseMapObjFile("dossun_shadow.nsbmd"), 0x3f);
    SetNsbmdPolygonIdLightEmiAll(gDossun, 0x3f, 2, 0x294a);
}
#pragma thumb off

#pragma thumb on
void InitDossun(Dossun *dossun, CourseMapRow *row) {
    dossun->mIsSlowVariant = row->mUnk_28;
    InitGroupFollower(&dossun->mFollower, row, dossun->mIsSlowVariant != 0 ? 0xc00 : 0x3000);
    dossun->mStartEntryIndex = row->mUnk_2a;
    dossun->mUnk_f4 = MUL_FIXED12_NO_ROUND(dossun->mMapObject.mScale.x, 0x28000);
    dossun->mHeightOffset = MUL_FIXED12_NO_ROUND(dossun->mMapObject.mScale.y, 0x2d000);
    dossun->mUnk_fc = MUL_FIXED12_NO_ROUND(dossun->mMapObject.mScale.z, 0x1e000);
    dossun->mUnk_100 = MUL_FIXED12_NO_ROUND(dossun->mMapObject.mScale.y, 0xf000);
    dossun->mUnk_104 = MUL_FIXED12_NO_ROUND(dossun->mMapObject.mScale.y, 0x1000);
    dossun->mUnk_108 = MUL_FIXED12_NO_ROUND(dossun->mMapObject.mScale.y, 0x2000);
    dossun->mUnk_c4 = MUL_FIXED12_NO_ROUND(dossun->mMapObject.mScale.y, 0x3000);
    SetupDossunAtStartEntry(dossun);
    if (dossun->mIsSlowVariant != 0) {
        CreateMapObjectSoundSourceFalloff3(&dossun->mMapObject);
    } else {
        dossun->mMapObject.mFarDistanceSquared = gSoundFalloffs[3].mFarDistanceSquared;
    }
}
#pragma thumb off

MapObjectKindData *CreateKuriboKindData(void) {
    MapObjectKindData *kindData;
    kindData = HeapAlloc(GetHeap(GetCurrentHeapCall()), 0x40);
    *kindData = data_021581b8;
    return kindData;
}

Unk020db20c *CreateKuriboDrawList(void) {
    Unk020db20c *drawList;
    drawList = HeapAlloc(GetHeap(GetCurrentHeapCall()), 0x2c);
    gKuriboDrawList = drawList;
    *drawList = data_0215818c;
    SetDrawListSlot(&gKuriboDrawList);
    return gKuriboDrawList;
}

MapObjectList *CreateKuriboUpdateList(void) {
    MapObjectList *updateList;
    updateList = HeapAlloc(GetHeap(GetCurrentHeapCall()), 0x28);
    gKuriboUpdateList = updateList;
    *updateList = data_02158164;
    SetUpdateListSlot(&gKuriboUpdateList);
    return gKuriboUpdateList;
}

void SetupDrawKuribo(void) {
    QueueNsbmdModelMaterial(gKuribo);
}

void DrawKuribo(void *unused0, Kuribo *kuribo, void *unused1, u16 maxAlpha) {
    Vec3 scale;
    Quaternion orientation;
    u16 modelAlpha;
    NsbmdModel *model;
    if (kuribo->mFollower.mGroupIndex == 0xffff) {
        QuaternionMultiplyByYawIgnoreY(&kuribo->mOrientation, &gViewYawQuaternion, &orientation);
        Matrix3x3FromQuaternion(&kuribo->mMapObject.mMatrix.mAxes, &orientation);
    } else {
        BuildMatrixFromYAxis(GetGroupFollowerSegmentUp(&kuribo->mFollower), &kuribo->mMapObject.mMatrix);
    }
    scale.z = kuribo->mMapObject.mScale.z;
    scale.y = MUL_FIXED12_NO_ROUND(kuribo->mMapObject.mScale.y, kuribo->mScaleFactorY);
    scale.x = MUL_FIXED12_NO_ROUND(kuribo->mMapObject.mScale.x, ((0x1000 - kuribo->mScaleFactorY) >> 1) + 0x1000);
    kuribo->mMapObject.mMatrix.mRows[3].x = kuribo->mMapObject.mPos.x >> 4;
    kuribo->mMapObject.mMatrix.mRows[3].y = kuribo->mMapObject.mPos.y >> 4;
    kuribo->mMapObject.mMatrix.mRows[3].z = kuribo->mMapObject.mPos.z >> 4;
    if (kuribo->mFrameIndex < 0x14) {
        gKuribo->mFrameIndex = kuribo->mFrameIndex;
    } else {
        scale.x = -scale.x;
        gKuribo->mFrameIndex = kuribo->mFrameIndex - 0x14;
    }
    modelAlpha = kuribo->mModelAlpha;
    model = gKuribo;
    model->mPolygonAttributes &= ~0x1f0000;
    model->mPolygonAttributes |= modelAlpha << 16;
    DrawNsbmdModelWithMatrixAndMaxAlpha(gKuribo, &kuribo->mMapObject.mMatrix, &scale, 0, maxAlpha);
}

void UpdateKuribo(void *unused, Kuribo *kuribo) {
    SoundStartParams soundRequest;
    RandomState64 *random;
    s32 falloffIndex;
    kuribo->mFrameIndex++;
    if (kuribo->mFrameIndex == 0x14 || kuribo->mFrameIndex == 0x28) {
        if ((kuribo->mMapObject.mDistanceSquaredAndFlags & 4) == 0) {
            if (kuribo->mMapObject.mFarDistanceSquared == gSoundFalloffs[2].mFarDistanceSquared) {
                falloffIndex = 2;
            } else if (kuribo->mMapObject.mFarDistanceSquared == gSoundFalloffs[3].mFarDistanceSquared) {
                falloffIndex = 3;
            } else {
                falloffIndex = 4;
            }
            soundRequest.mSoundId = 0x182;
            soundRequest.mPositionSource = &kuribo->mMapObject.mPos;
            soundRequest.mFalloffIndex = falloffIndex;
            soundRequest.mDistanceSquared = GetHorizontalCameraDistanceSquared(&kuribo->mMapObject.mPos);
            StartSoundFromParams(&soundRequest);
        }
    }
    if (kuribo->mFrameIndex >= 0x28) {
        if (kuribo->mFrameRandomized != 0) {
            kuribo->mFrameIndex = 0;
        } else {
            random = &gRaceProgress->mRandom;
            random->mValue = random->mMultiplier * random->mValue + random->mIncrement;
            kuribo->mFrameIndex = ((u64) (u32) (random->mValue >> 32) * 0x28) >> 32;
            kuribo->mFrameRandomized = 1;
        }
    }
    AdvanceStateMachine(&kuribo->mMapObject.mStateMachine);
}
