#include "Main/Unknown/code_020ff344.h"
#include "Main/Unknown/code_02036820.h"
#include "Main/Unknown/code_020364e0.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_02039860.h"
#include "Main/Unknown/code_02046be8.h"
#include "Main/Unknown/code_020b2ec0.h"
#include "Main/Unknown/code_020d2000.h"
#include "Main/Unknown/code_020ea588.h"
#include "Main/Unknown/code_021052f0.h"
#include "Main/Unknown/code_02109000.h"
#include "Main/Unknown/code_02109054.h"
#include "Main/Unknown/unk_0217b000.h"
#include "code_02146d78.h"
#include "code_02147cd8.h"
#include "Main/Unknown/code_02084000.h"
#include "Main/Unknown/code_020f2dac.h"
#include "Main/Unknown/code_0206bcb0.h"
#include "Main/Unknown/code_020f49bc.h"
#include "Main/Unknown/code_020f9000.h"
#include "Main/Unknown/unk_0217c000.h"
#include "Main/Unknown/unk_0215a000.h"
#include "Main/Unknown/code_020f73fc.h"
#include "Main/Unknown/code_021053e4.h"
#include "Main/Unknown/code_020ee684.h"
#include "01/code_02187d14.h" // gItemFBoxRotation

#pragma thumb on

void CreateDram(void) {
    CreateNsbmd(&gDram, FindCourseMapObjFile(gDramNsbmdName), NULL);
    SetNsbmdPolygonIdLightEmiAll(gDram, 0x3f, 2, 0x294a);
}

void InitDram(Dram *dram, struct CourseMapRow *courseRow) {
    InitStateMachine(&dram->mMapObject.mStateMachine, gDramStateTable, 6, dram);
    dram->mAnglePerFrameChoices[0] = courseRow->mUnk_28 * 0x80 / 100;
    dram->mAnglePerFrameChoices[2] = courseRow->mUnk_30 * 0x80 / 100;
    dram->mAnglePerFrameChoices[1] = (dram->mAnglePerFrameChoices[0] + dram->mAnglePerFrameChoices[2]) / 2;
    dram->mSteadyFrameCount = courseRow->mUnk_2a;
    dram->mRampFrameCount = courseRow->mUnk_2c;
    dram->mDelayFrameCount = courseRow->mUnk_2e;
    dram->mAngleX = 0;
    if (dram->mRampFrameCount != 0) {
        dram->mRampPerFrame = 0x1000 / dram->mRampFrameCount;
    } else {
        dram->mRampPerFrame = 0;
    }
    dram->mRamp = 0;
    dram->mMapObject.mStateMachine.mNextState = 1;
    dram->mMapObject.mStateMachine.mNextStateRequested = 1;
}

#pragma thumb off

MapObjectKindData *CreateMissionRunBoxKindData(void) {
    MapObjectKindData *p;

    p = GetHeap(GetCurrentHeapCall());
    p = HeapAlloc(p, 0x40);
    *p = gMissionRunBoxKindData;
    return p;
}

BOOL IsMissionRunBoxKind(u32 kind) {
    return kind == 0xb;
}

#pragma thumb on

void InitMissionRunBoxMapObject(Unk020ff97c *object) {
    object->mCollisionMapObject.mCollisionData.mPrevMatrix = object->mCollisionMapObject.mMapObject.mMatrix.mAxes;
    object->mCollisionMapObject.mCollisionData.mAngleChangeVector.x = 0;
    object->mCollisionMapObject.mCollisionData.mAngleChangeVector.y = 0;
    object->mCollisionMapObject.mCollisionData.mAngleChangeVector.z = 0;
    object->mCollisionMapObject.mCollisionData.mUnk_130 = 0;
    object->mCollisionMapObject.mCollisionData.mUnk_100 = MUL_FIXED12_NO_ROUND(object->mCollisionMapObject.mMapObject.mScale.x, 0x190000);
    object->mCollisionMapObject.mCollisionData.mHalfSizeY =
        MUL_FIXED12_NO_ROUND(object->mCollisionMapObject.mMapObject.mScale.y, 0x64000) >> 1;
    object->mCollisionMapObject.mCollisionData.mPositiveHalfSizeZ =
        MUL_FIXED12_NO_ROUND(object->mCollisionMapObject.mMapObject.mScale.z, 0xaf000);
    object->mCollisionMapObject.mCollisionData.mNegativeHalfSizeZ =
        MUL_FIXED12_NO_ROUND(object->mCollisionMapObject.mMapObject.mScale.z, 0xaf000);
    object->mCollisionMapObject.mCollisionData.mUnk_110 = 0;
    object->mCollisionMapObject.mCollisionData.mUnk_114.x = 1;
    object->mCollisionMapObject.mCollisionData.mUnk_114.y = 0;
    object->mCollisionMapObject.mCollisionData.mUnk_114.z = 0;
    object->mCollisionMapObject.mCollisionData.mUnk_120 = 0x800;
    object->mCollisionMapObject.mCollisionData.mUnk_e8 = object->mCollisionMapObject.mMapObject.mPos;
    object->mCollisionMapObject.mMapObject.mPosStep.x = 0;
    object->mCollisionMapObject.mMapObject.mPosStep.y = 0;
    object->mCollisionMapObject.mMapObject.mPosStep.z = 0;
    VEC_MultAdd(-object->mCollisionMapObject.mCollisionData.mHalfSizeY, &object->mCollisionMapObject.mMapObject.mMatrix.mRows[1],
                &object->mCollisionMapObject.mMapObject.mPos, &object->mCollisionMapObject.mCollisionData.mCenterPos);
    object->mCollisionMapObject.mCollisionData.mUnk_134 = COLLISION_SHAPE_BOX;
    object->mCollisionMapObject.mCollisionData.mUnk_138 = 0;
    object->mCollisionMapObject.mSkipsFlaggedQueries = 1;
    object->mCollisionMapObject.mMapObject.mFlags |= data_0215a030;
}

#pragma thumb off

void SetItemFBoxDrawMatrix(ItemFBox *fbox, MtxFx43 *out) {
    Vec3 *position;

    position = fbox->mBouncingItemObject.mItemObject.mPosPointer;
    fbox->mBouncingItemObject.mItemObject.mTransformMtx.mRows[3].x = position->x >> 4;
    fbox->mBouncingItemObject.mItemObject.mTransformMtx.mRows[3].y = position->y >> 4;
    fbox->mBouncingItemObject.mItemObject.mTransformMtx.mRows[3].z = position->z >> 4;
    *out = fbox->mBouncingItemObject.mItemObject.mTransformMtx;
    MTX_Concat33(&gItemFBoxRotation.mAxes, &out->mAxes, &out->mAxes);
}

void SetItemFBoxPushedDrawMatrix(ItemFBox *fbox, MtxFx43 *out) {
    s32 scaledX, scaledZ;
    Vec3 *position;

    if ((fbox->mBouncingItemObject.mItemObject.mFlags & 0x80000) && GetChoisesSOpenDuringRace() == 0) {
        s32 row0Dot, row2Dot;

        row0Dot = DOT2_FIXED12(fbox->mBouncingItemObject.mItemObject.mTransformMtx.mRows[0].x, fbox->mPushDirection.x,
                               fbox->mBouncingItemObject.mItemObject.mTransformMtx.mRows[0].z, fbox->mPushDirection.z);
        scaledX = MUL_FIXED12_NO_ROUND(fbox->mPushDirection.x, 0xa4);
        row2Dot = DOT2_FIXED12(fbox->mBouncingItemObject.mItemObject.mTransformMtx.mRows[2].x, fbox->mPushDirection.x,
                               fbox->mBouncingItemObject.mItemObject.mTransformMtx.mRows[2].z, fbox->mPushDirection.z);
        scaledZ = MUL_FIXED12_NO_ROUND(fbox->mPushDirection.z, 0xa4);
        fbox->mBouncingItemObject.mItemObject.mTransformMtx.mRows[1].x =
            (s32) (fbox->mBouncingItemObject.mItemObject.mTransformMtx.mRows[1].x + scaledX);
        fbox->mBouncingItemObject.mItemObject.mTransformMtx.mRows[1].z += scaledZ;
        if ((s64) fbox->mBouncingItemObject.mItemObject.mTransformMtx.mRows[1].x *
                    fbox->mBouncingItemObject.mItemObject.mTransformMtx.mRows[1].x +
                (s64) fbox->mBouncingItemObject.mItemObject.mTransformMtx.mRows[1].y *
                    fbox->mBouncingItemObject.mItemObject.mTransformMtx.mRows[1].y +
                (s64) fbox->mBouncingItemObject.mItemObject.mTransformMtx.mRows[1].z *
                    fbox->mBouncingItemObject.mItemObject.mTransformMtx.mRows[1].z >=
            0x10) {
            Vec3NormalizeAndGetLengthUnchecked(&fbox->mBouncingItemObject.mItemObject.mTransformMtx.mRows[1],
                                               &fbox->mBouncingItemObject.mItemObject.mTransformMtx.mRows[1]);
        }
        if (row0Dot * row0Dot > row2Dot * row2Dot) {
            fbox->mBouncingItemObject.mItemObject.mTransformMtx.mRows[2].x =
                (s32) (fbox->mBouncingItemObject.mItemObject.mTransformMtx.mRows[2].x - scaledX);
            fbox->mBouncingItemObject.mItemObject.mTransformMtx.mRows[2].z -= scaledZ;
            Vec3CrossUnrounded(&fbox->mBouncingItemObject.mItemObject.mTransformMtx.mRows[1],
                               &fbox->mBouncingItemObject.mItemObject.mTransformMtx.mRows[2],
                               &fbox->mBouncingItemObject.mItemObject.mTransformMtx.mRows[0]);
            if ((s64) fbox->mBouncingItemObject.mItemObject.mTransformMtx.mRows[0].x *
                        fbox->mBouncingItemObject.mItemObject.mTransformMtx.mRows[0].x +
                    (s64) fbox->mBouncingItemObject.mItemObject.mTransformMtx.mRows[0].y *
                        fbox->mBouncingItemObject.mItemObject.mTransformMtx.mRows[0].y +
                    (s64) fbox->mBouncingItemObject.mItemObject.mTransformMtx.mRows[0].z *
                        fbox->mBouncingItemObject.mItemObject.mTransformMtx.mRows[0].z >=
                0x10) {
                Vec3NormalizeAndGetLengthUnchecked(&fbox->mBouncingItemObject.mItemObject.mTransformMtx.mRows[0],
                                                   &fbox->mBouncingItemObject.mItemObject.mTransformMtx.mRows[0]);
            }
            Vec3CrossUnrounded(&fbox->mBouncingItemObject.mItemObject.mTransformMtx.mRows[0],
                               &fbox->mBouncingItemObject.mItemObject.mTransformMtx.mRows[1],
                               &fbox->mBouncingItemObject.mItemObject.mTransformMtx.mRows[2]);
        } else {
            fbox->mBouncingItemObject.mItemObject.mTransformMtx.mRows[0].x -= scaledX;
            fbox->mBouncingItemObject.mItemObject.mTransformMtx.mRows[0].z -= scaledZ;
            Vec3CrossUnrounded(&fbox->mBouncingItemObject.mItemObject.mTransformMtx.mRows[0],
                               &fbox->mBouncingItemObject.mItemObject.mTransformMtx.mRows[1],
                               &fbox->mBouncingItemObject.mItemObject.mTransformMtx.mRows[2]);
            if ((s64) fbox->mBouncingItemObject.mItemObject.mTransformMtx.mRows[2].x *
                        fbox->mBouncingItemObject.mItemObject.mTransformMtx.mRows[2].x +
                    (s64) fbox->mBouncingItemObject.mItemObject.mTransformMtx.mRows[2].y *
                        fbox->mBouncingItemObject.mItemObject.mTransformMtx.mRows[2].y +
                    (s64) fbox->mBouncingItemObject.mItemObject.mTransformMtx.mRows[2].z *
                        fbox->mBouncingItemObject.mItemObject.mTransformMtx.mRows[2].z >=
                0x10) {
                Vec3NormalizeAndGetLengthUnchecked(&fbox->mBouncingItemObject.mItemObject.mTransformMtx.mRows[2],
                                                   &fbox->mBouncingItemObject.mItemObject.mTransformMtx.mRows[2]);
            }
            Vec3CrossUnrounded(&fbox->mBouncingItemObject.mItemObject.mTransformMtx.mRows[1],
                               &fbox->mBouncingItemObject.mItemObject.mTransformMtx.mRows[2],
                               &fbox->mBouncingItemObject.mItemObject.mTransformMtx.mRows[0]);
        }
    }
    position = fbox->mBouncingItemObject.mItemObject.mPosPointer;
    fbox->mBouncingItemObject.mItemObject.mTransformMtx.mRows[3].x = position->x >> 4;
    fbox->mBouncingItemObject.mItemObject.mTransformMtx.mRows[3].y = position->y >> 4;
    fbox->mBouncingItemObject.mItemObject.mTransformMtx.mRows[3].z = position->z >> 4;
    *out = fbox->mBouncingItemObject.mItemObject.mTransformMtx;
}

void ResetItemFBox(ItemFBox *fbox) {
    fbox->mBouncingItemObject.mItemObject.mTransformMtx.mAxes = gItemFBoxRotation.mAxes;
    ResetPooledMapObject(fbox->mPooledMapObject);
    fbox->mPooledMapObject->mShadowMode = 2;
    SetPooledMapObjectCallback(fbox->mPooledMapObject, SetItemFBoxDrawMatrix, fbox);
}

void StartItemFBox(ItemFBox *fbox) {
    fbox->mPooledMapObject->mShadowMode = 1;
    SetPooledMapObjectCallback(fbox->mPooledMapObject, SetItemFBoxPushedDrawMatrix, fbox);
}

void AdvanceItemFBoxInUse(ItemInUse *inUse, ItemFBox *fbox) {
    SetPooledMapObjectFromItem(fbox->mPooledMapObject, fbox->mBouncingItemObject.mItemObject.mAlpha,
                               &fbox->mBouncingItemObject.mItemObject.mScale);
}

u32 InitItemFBox(ItemInUse *inUse, ItemFBox *fbox) {
    StartItemObjectSoundSource(&fbox->mBouncingItemObject.mItemObject);
    fbox->mBouncingItemObject.mItemObject.mOwnerKartIndexAndFlags |= gItemObjectExcludedUntilCourseHitBit;
    MTX_Concat33(&gItemFBoxRotation.mAxes, &fbox->mBouncingItemObject.mItemObject.mTransformMtx.mAxes,
                 &fbox->mBouncingItemObject.mItemObject.mTransformMtx.mAxes);
    fbox->mPushDirection.x = 0;
    fbox->mPushDirection.y = 0;
    fbox->mPushDirection.z = 0;
    if ((inUse->mKartItems->mFlags & KART_ITEMS_THROW_FORWARD) != 0) {
        ThrowBouncingItem(&fbox->mBouncingItemObject, inUse, 0, 1, 0x4000, 0x3000, 0x59a);
        StartSound(&fbox->mBouncingItemObject.mItemObject.mSoundSource, 0xda, 0x7f, 0);
        fbox->mThrownForward = 1;
        return fbox->mThrownForward;
    }
    ThrowBouncingItem(&fbox->mBouncingItemObject, inUse, 0, 0, 0x4000, 0x3000, 0x59a);
    fbox->mThrownForward = 0;
    return fbox->mThrownForward;
}

void AdvanceItemFBox(ItemFBox *fbox) {
    s32 unusedOutput;

    if (fbox->mBouncingItemObject.mItemObject.mFlags & 0x180000) {
        if (fbox->mBouncingItemObject.mItemObject.mFlags & 0x80000) {
            AdvanceItemObjectFadeOut(&fbox->mBouncingItemObject.mItemObject);
        } else if (fbox->mBouncingItemObject.mItemObject.mFlags & 0x100000) {
            AdvanceItemObjectReleaseTimer(&fbox->mBouncingItemObject.mItemObject);
        }
    } else if (fbox->mBouncingItemObject.mItemObject.mFlags & 0x8000) {
        AdvanceRestingItemObject(&fbox->mBouncingItemObject.mItemObject);
    } else if (fbox->mBouncingItemObject.mItemObject.mFlags & 0x4000) {
        AdvanceFallingItemObject(&fbox->mBouncingItemObject.mItemObject);
    } else {
        if (fbox->mThrownForward != 0) {
            AdvanceBouncingItem(&fbox->mBouncingItemObject, 0x1ec, 0xfec, 0, (u32 *) &unusedOutput);
        } else {
            AdvanceBouncingItem(&fbox->mBouncingItemObject, 0x2e1, 0xf85, 0, (u32 *) &unusedOutput);
        }
        if ((fbox->mBouncingItemObject.mItemObject.mFlags & 8) && (fbox->mBouncingItemObject.mItemObject.mFlags & 3) == 0) {
            if (fbox->mThrownForward != 0) {
                fbox->mBouncingItemObject.mItemObject.mVelocity.y *= 2;
            }
            StopSound(&fbox->mBouncingItemObject.mItemObject.mSoundSource, 0xda);
            StartRestingItemObject(&fbox->mBouncingItemObject.mItemObject, &unusedOutput);
        }
    }
    SetPooledMapObjectFromItem(fbox->mPooledMapObject, fbox->mBouncingItemObject.mItemObject.mAlpha,
                               &fbox->mBouncingItemObject.mItemObject.mScale);
}

s32 ItemFBoxFadeOutCallback(ItemFBox *fbox) {
    Vec3 *vector;

    vector = gItemPushVector;
    if (LENGTH_SQUARED(*vector) >= 0x10) {
        Vec3NormalizeAndGetLengthUnchecked(vector, &fbox->mPushDirection);
    }
    fbox->mPooledMapObject->mShadowMode = 2;
    if ((fbox->mBouncingItemObject.mItemObject.mFlags & 0x180000) == 0) {
        fbox->mBouncingItemObject.mItemObject.mAdvance = (void (*)(ItemObject *)) AdvanceItemFBox;
    }
    return 2;
}

void SetupItemFBoxAfterLaunch(ItemFBox *fbox) {
    if ((s64) fbox->mBouncingItemObject.mItemObject.mTransformMtx.mRows[0].x *
                fbox->mBouncingItemObject.mItemObject.mTransformMtx.mRows[0].x +
            (s64) fbox->mBouncingItemObject.mItemObject.mTransformMtx.mRows[0].y *
                fbox->mBouncingItemObject.mItemObject.mTransformMtx.mRows[0].y +
            (s64) fbox->mBouncingItemObject.mItemObject.mTransformMtx.mRows[0].z *
                fbox->mBouncingItemObject.mItemObject.mTransformMtx.mRows[0].z >=
        0x10) {
        Vec3NormalizeAndGetLengthUnchecked(&fbox->mBouncingItemObject.mItemObject.mTransformMtx.mRows[0],
                                           &fbox->mBouncingItemObject.mItemObject.mTransformMtx.mRows[0]);
    }
    Vec3CrossUnrounded(&fbox->mBouncingItemObject.mItemObject.mTransformMtx.mRows[0],
                       &fbox->mBouncingItemObject.mItemObject.mTransformMtx.mRows[1],
                       &fbox->mBouncingItemObject.mItemObject.mTransformMtx.mRows[2]);
    MTX_Concat33(&gItemFBoxRotation.mAxes, &fbox->mBouncingItemObject.mItemObject.mTransformMtx.mAxes,
                 &fbox->mBouncingItemObject.mItemObject.mTransformMtx.mAxes);
    if ((fbox->mBouncingItemObject.mItemObject.mFlags & 0x180000) == 0) {
        fbox->mBouncingItemObject.mItemObject.mAdvance = (void (*)(ItemObject *)) AdvanceItemFBox;
    }
}
