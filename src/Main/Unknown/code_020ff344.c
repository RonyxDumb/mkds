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
#include "01/code_02187d14.h" // data_0217c600

#pragma thumb on

void CreateDram(void) {
    CreateNsbmd(&gDram, FindCourseMapObjFile(gDramNsbmdName), NULL);
    SetNsbmdPolygonIdLightEmiAll(gDram, 0x3f, 2, 0x294a);
}

void InitDram(Dram *dram, struct CourseMapRow *courseRow) {
    InitStateMachine(&dram->mMapObject.mStateMachine, data_0216c740, 6, dram);
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

Unk02100004 *func_020ffacc(void) {
    Unk02100004 *p;

    p = GetHeap(GetCurrentHeapCall());
    p = HeapAlloc(p, 0x40);
    *p = data_0215a068;
    return p;
}

BOOL func_020ffabc(u32 kind) {
    return kind == 0xb;
}

#pragma thumb on

void func_020ff97c(Unk020ff97c *object) {
    object->mUnk_000.mCollisionData.mPrevMatrix = object->mUnk_000.mMapObject.mMatrix.mUnk_00_m;
    object->mUnk_000.mCollisionData.mAngleChangeVector.x = 0;
    object->mUnk_000.mCollisionData.mAngleChangeVector.y = 0;
    object->mUnk_000.mCollisionData.mAngleChangeVector.z = 0;
    object->mUnk_000.mCollisionData.mUnk_130 = 0;
    object->mUnk_000.mCollisionData.mUnk_100 = ((s64) object->mUnk_000.mMapObject.mScale.x * 0x190000) >> 12;
    object->mUnk_000.mCollisionData.mHalfSizeY =
        (s32) (((s64) object->mUnk_000.mMapObject.mScale.y * 0x64000) >> 12) >> 1;
    object->mUnk_000.mCollisionData.mPositiveHalfSizeZ = ((s64) object->mUnk_000.mMapObject.mScale.z * 0xaf000) >> 12;
    object->mUnk_000.mCollisionData.mNegativeHalfSizeZ = ((s64) object->mUnk_000.mMapObject.mScale.z * 0xaf000) >> 12;
    object->mUnk_000.mCollisionData.mUnk_110 = 0;
    object->mUnk_000.mCollisionData.mUnk_114.x = 1;
    object->mUnk_000.mCollisionData.mUnk_114.y = 0;
    object->mUnk_000.mCollisionData.mUnk_114.z = 0;
    object->mUnk_000.mCollisionData.mUnk_120 = 0x800;
    object->mUnk_000.mCollisionData.mUnk_e8 = object->mUnk_000.mMapObject.mPos;
    object->mUnk_000.mMapObject.mUnk_10.x = 0;
    object->mUnk_000.mMapObject.mUnk_10.y = 0;
    object->mUnk_000.mMapObject.mUnk_10.z = 0;
    VEC_MultAdd(-object->mUnk_000.mCollisionData.mHalfSizeY, &object->mUnk_000.mMapObject.mMatrix.mUnk_00[1],
                &object->mUnk_000.mMapObject.mPos, &object->mUnk_000.mCollisionData.mCenterPos);
    object->mUnk_000.mCollisionData.mUnk_134 = COLLISION_SHAPE_BOX;
    object->mUnk_000.mCollisionData.mUnk_138 = 0;
    object->mUnk_000.mUnk_13c = 1;
    object->mUnk_000.mMapObject.mFlags |= data_0215a030;
}

#pragma thumb off

void SetItemFBoxDrawMatrix(ItemFBox *fbox, MtxFx43 *out) {
    Vec3 *position;

    position = fbox->mUnk_000.mItemObject.mUnk_d0;
    fbox->mUnk_000.mItemObject.mUnk_94.mUnk_00[3].x = position->x >> 4;
    fbox->mUnk_000.mItemObject.mUnk_94.mUnk_00[3].y = position->y >> 4;
    fbox->mUnk_000.mItemObject.mUnk_94.mUnk_00[3].z = position->z >> 4;
    *out = fbox->mUnk_000.mItemObject.mUnk_94;
    MTX_Concat33(&data_0217c600.mUnk_00_m, &out->mUnk_00_m, &out->mUnk_00_m);
}

void func_020ff6d8(ItemFBox *fbox, MtxFx43 *out) {
    s32 scaledX, scaledZ;
    Vec3 *position;

    if ((fbox->mUnk_000.mItemObject.mFlags & 0x80000) && GetChoisesSOpenDuringRace() == 0) {
        s32 row0Dot, row2Dot;

        row0Dot = ((s64) fbox->mUnk_000.mItemObject.mUnk_94.mUnk_00[0].x * fbox->mUnk_130.x +
                   (s64) fbox->mUnk_000.mItemObject.mUnk_94.mUnk_00[0].z * fbox->mUnk_130.z) >>
                  12;
        scaledX = ((s64) fbox->mUnk_130.x * 0xa4) >> 12;
        row2Dot = ((s64) fbox->mUnk_000.mItemObject.mUnk_94.mUnk_00[2].x * fbox->mUnk_130.x +
                   (s64) fbox->mUnk_000.mItemObject.mUnk_94.mUnk_00[2].z * fbox->mUnk_130.z) >>
                  12;
        scaledZ = ((s64) fbox->mUnk_130.z * 0xa4) >> 12;
        fbox->mUnk_000.mItemObject.mUnk_94.mUnk_00[1].x =
            (s32) (fbox->mUnk_000.mItemObject.mUnk_94.mUnk_00[1].x + scaledX);
        fbox->mUnk_000.mItemObject.mUnk_94.mUnk_00[1].z += scaledZ;
        if ((s64) fbox->mUnk_000.mItemObject.mUnk_94.mUnk_00[1].x * fbox->mUnk_000.mItemObject.mUnk_94.mUnk_00[1].x +
                (s64) fbox->mUnk_000.mItemObject.mUnk_94.mUnk_00[1].y *
                    fbox->mUnk_000.mItemObject.mUnk_94.mUnk_00[1].y +
                (s64) fbox->mUnk_000.mItemObject.mUnk_94.mUnk_00[1].z *
                    fbox->mUnk_000.mItemObject.mUnk_94.mUnk_00[1].z >=
            0x10) {
            Vec3NormalizeAndGetLengthUnchecked(&fbox->mUnk_000.mItemObject.mUnk_94.mUnk_00[1],
                                               &fbox->mUnk_000.mItemObject.mUnk_94.mUnk_00[1]);
        }
        if (row0Dot * row0Dot > row2Dot * row2Dot) {
            fbox->mUnk_000.mItemObject.mUnk_94.mUnk_00[2].x =
                (s32) (fbox->mUnk_000.mItemObject.mUnk_94.mUnk_00[2].x - scaledX);
            fbox->mUnk_000.mItemObject.mUnk_94.mUnk_00[2].z -= scaledZ;
            Vec3CrossUnrounded(&fbox->mUnk_000.mItemObject.mUnk_94.mUnk_00[1],
                               &fbox->mUnk_000.mItemObject.mUnk_94.mUnk_00[2],
                               &fbox->mUnk_000.mItemObject.mUnk_94.mUnk_00[0]);
            if ((s64) fbox->mUnk_000.mItemObject.mUnk_94.mUnk_00[0].x *
                        fbox->mUnk_000.mItemObject.mUnk_94.mUnk_00[0].x +
                    (s64) fbox->mUnk_000.mItemObject.mUnk_94.mUnk_00[0].y *
                        fbox->mUnk_000.mItemObject.mUnk_94.mUnk_00[0].y +
                    (s64) fbox->mUnk_000.mItemObject.mUnk_94.mUnk_00[0].z *
                        fbox->mUnk_000.mItemObject.mUnk_94.mUnk_00[0].z >=
                0x10) {
                Vec3NormalizeAndGetLengthUnchecked(&fbox->mUnk_000.mItemObject.mUnk_94.mUnk_00[0],
                                                   &fbox->mUnk_000.mItemObject.mUnk_94.mUnk_00[0]);
            }
            Vec3CrossUnrounded(&fbox->mUnk_000.mItemObject.mUnk_94.mUnk_00[0],
                               &fbox->mUnk_000.mItemObject.mUnk_94.mUnk_00[1],
                               &fbox->mUnk_000.mItemObject.mUnk_94.mUnk_00[2]);
        } else {
            fbox->mUnk_000.mItemObject.mUnk_94.mUnk_00[0].x -= scaledX;
            fbox->mUnk_000.mItemObject.mUnk_94.mUnk_00[0].z -= scaledZ;
            Vec3CrossUnrounded(&fbox->mUnk_000.mItemObject.mUnk_94.mUnk_00[0],
                               &fbox->mUnk_000.mItemObject.mUnk_94.mUnk_00[1],
                               &fbox->mUnk_000.mItemObject.mUnk_94.mUnk_00[2]);
            if ((s64) fbox->mUnk_000.mItemObject.mUnk_94.mUnk_00[2].x *
                        fbox->mUnk_000.mItemObject.mUnk_94.mUnk_00[2].x +
                    (s64) fbox->mUnk_000.mItemObject.mUnk_94.mUnk_00[2].y *
                        fbox->mUnk_000.mItemObject.mUnk_94.mUnk_00[2].y +
                    (s64) fbox->mUnk_000.mItemObject.mUnk_94.mUnk_00[2].z *
                        fbox->mUnk_000.mItemObject.mUnk_94.mUnk_00[2].z >=
                0x10) {
                Vec3NormalizeAndGetLengthUnchecked(&fbox->mUnk_000.mItemObject.mUnk_94.mUnk_00[2],
                                                   &fbox->mUnk_000.mItemObject.mUnk_94.mUnk_00[2]);
            }
            Vec3CrossUnrounded(&fbox->mUnk_000.mItemObject.mUnk_94.mUnk_00[1],
                               &fbox->mUnk_000.mItemObject.mUnk_94.mUnk_00[2],
                               &fbox->mUnk_000.mItemObject.mUnk_94.mUnk_00[0]);
        }
    }
    position = fbox->mUnk_000.mItemObject.mUnk_d0;
    fbox->mUnk_000.mItemObject.mUnk_94.mUnk_00[3].x = position->x >> 4;
    fbox->mUnk_000.mItemObject.mUnk_94.mUnk_00[3].y = position->y >> 4;
    fbox->mUnk_000.mItemObject.mUnk_94.mUnk_00[3].z = position->z >> 4;
    *out = fbox->mUnk_000.mItemObject.mUnk_94;
}

void ResetItemFBox(ItemFBox *fbox) {
    fbox->mUnk_000.mItemObject.mUnk_94.mUnk_00_m = data_0217c600.mUnk_00_m;
    ResetPooledMapObject(fbox->mPooledMapObject);
    fbox->mPooledMapObject->mShadowMode = 2;
    SetPooledMapObjectCallback(fbox->mPooledMapObject, SetItemFBoxDrawMatrix, fbox);
}

void StartItemFBox(ItemFBox *fbox) {
    fbox->mPooledMapObject->mShadowMode = 1;
    SetPooledMapObjectCallback(fbox->mPooledMapObject, func_020ff6d8, fbox);
}

void AdvanceItemFBoxInUse(ItemInUse *inUse, ItemFBox *fbox) {
    SetPooledMapObjectFromItem(fbox->mPooledMapObject, fbox->mUnk_000.mItemObject.mAlpha,
                               &fbox->mUnk_000.mItemObject.mScale);
}

u32 InitItemFBox(ItemInUse *inUse, ItemFBox *fbox) {
    func_020f9114(fbox);
    fbox->mUnk_000.mItemObject.mUnk_78 |= data_0215a02c;
    MTX_Concat33(&data_0217c600.mUnk_00_m, &fbox->mUnk_000.mItemObject.mUnk_94.mUnk_00_m,
                 &fbox->mUnk_000.mItemObject.mUnk_94.mUnk_00_m);
    fbox->mUnk_130.x = 0;
    fbox->mUnk_130.y = 0;
    fbox->mUnk_130.z = 0;
    if ((inUse->mKartItems->mFlags & KART_ITEMS_THROW_FORWARD) != 0) {
        ThrowBouncingItem(&fbox->mUnk_000, inUse, 0, 1, 0x4000, 0x3000, 0x59a);
        StartSound(&fbox->mUnk_000.mItemObject.mSoundSource, 0xda, 0x7f, 0);
        fbox->mThrownForward = 1;
        return fbox->mThrownForward;
    }
    ThrowBouncingItem(&fbox->mUnk_000, inUse, 0, 0, 0x4000, 0x3000, 0x59a);
    fbox->mThrownForward = 0;
    return fbox->mThrownForward;
}

void AdvanceItemFBox(ItemFBox *fbox) {
    s32 unusedOutput;

    if (fbox->mUnk_000.mItemObject.mFlags & 0x180000) {
        if (fbox->mUnk_000.mItemObject.mFlags & 0x80000) {
            func_020f6e58(&fbox->mUnk_000.mItemObject);
        } else if (fbox->mUnk_000.mItemObject.mFlags & 0x100000) {
            AdvanceItemObjectReleaseTimer(&fbox->mUnk_000.mItemObject);
        }
    } else if (fbox->mUnk_000.mItemObject.mFlags & 0x8000) {
        AdvanceRestingItemObject(&fbox->mUnk_000.mItemObject);
    } else if (fbox->mUnk_000.mItemObject.mFlags & 0x4000) {
        AdvanceFallingItemObject(&fbox->mUnk_000.mItemObject);
    } else {
        if (fbox->mThrownForward != 0) {
            AdvanceBouncingItem(&fbox->mUnk_000, 0x1ec, 0xfec, 0, (u32 *) &unusedOutput);
        } else {
            AdvanceBouncingItem(&fbox->mUnk_000, 0x2e1, 0xf85, 0, (u32 *) &unusedOutput);
        }
        if ((fbox->mUnk_000.mItemObject.mFlags & 8) && (fbox->mUnk_000.mItemObject.mFlags & 3) == 0) {
            if (fbox->mThrownForward != 0) {
                fbox->mUnk_000.mItemObject.mVelocity.y *= 2;
            }
            StopSound(&fbox->mUnk_000.mItemObject.mSoundSource, 0xda);
            StartRestingItemObject(&fbox->mUnk_000.mItemObject, &unusedOutput);
        }
    }
    SetPooledMapObjectFromItem(fbox->mPooledMapObject, fbox->mUnk_000.mItemObject.mAlpha,
                               &fbox->mUnk_000.mItemObject.mScale);
}

s32 func_020ff3c4(ItemFBox *fbox) {
    Vec3 *vector;

    vector = gItemPushVector;
    if ((s64) vector->x * vector->x + (s64) vector->y * vector->y + (s64) vector->z * vector->z >= 0x10) {
        Vec3NormalizeAndGetLengthUnchecked(vector, &fbox->mUnk_130);
    }
    fbox->mPooledMapObject->mShadowMode = 2;
    if ((fbox->mUnk_000.mItemObject.mFlags & 0x180000) == 0) {
        fbox->mUnk_000.mItemObject.mAdvance = (void (*)(ItemObject *)) AdvanceItemFBox;
    }
    return 2;
}

void func_020ff344(ItemFBox *fbox) {
    if ((s64) fbox->mUnk_000.mItemObject.mUnk_94.mUnk_00[0].x * fbox->mUnk_000.mItemObject.mUnk_94.mUnk_00[0].x +
            (s64) fbox->mUnk_000.mItemObject.mUnk_94.mUnk_00[0].y * fbox->mUnk_000.mItemObject.mUnk_94.mUnk_00[0].y +
            (s64) fbox->mUnk_000.mItemObject.mUnk_94.mUnk_00[0].z * fbox->mUnk_000.mItemObject.mUnk_94.mUnk_00[0].z >=
        0x10) {
        Vec3NormalizeAndGetLengthUnchecked(&fbox->mUnk_000.mItemObject.mUnk_94.mUnk_00[0],
                                           &fbox->mUnk_000.mItemObject.mUnk_94.mUnk_00[0]);
    }
    Vec3CrossUnrounded(&fbox->mUnk_000.mItemObject.mUnk_94.mUnk_00[0], &fbox->mUnk_000.mItemObject.mUnk_94.mUnk_00[1],
                       &fbox->mUnk_000.mItemObject.mUnk_94.mUnk_00[2]);
    MTX_Concat33(&data_0217c600.mUnk_00_m, &fbox->mUnk_000.mItemObject.mUnk_94.mUnk_00_m,
                 &fbox->mUnk_000.mItemObject.mUnk_94.mUnk_00_m);
    if ((fbox->mUnk_000.mItemObject.mFlags & 0x180000) == 0) {
        fbox->mUnk_000.mItemObject.mAdvance = (void (*)(ItemObject *)) AdvanceItemFBox;
    }
}
