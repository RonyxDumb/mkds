#include "Main/Unknown/code_020ec8bc.h"
#include "Main/Unknown/code_02036820.h"
#include "Main/Unknown/code_020d7db4.h"
#include "Main/Unknown/code_020f6be8.h"
#include "Main/Unknown/unk_0216c000.h"
#include "Main/Unknown/code_020d8000.h"
#include "Main/Unknown/code_020e6000.h"
#include "Main/Unknown/code_020ea000.h"
#include "Main/Unknown/code_020f1000.h"
#include "Main/Unknown/code_020f2000.h"
#include "Main/Unknown/code_020f6000.h"
#include "Main/Unknown/code_020f7000.h"
#include "ITCM/code_01ffd000.h"
#include "Main/Unknown/code_020364e0.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_02039860.h"
#include "Main/Unknown/code_02047000.h"
#include "Main/Unknown/unk_02164000.h"
#include "Main/Unknown/code_02047104.h"
#include "Main/Unknown/code_0206bcb0.h"
#include "Main/Unknown/code_02084000.h"
#include "Main/Unknown/code_020d8474.h"
#include "Main/Unknown/code_020f36d8.h"
#include "Main/Unknown/unk_021759c0.h"
#include "Main/Unknown/unk_0217b000.h"
#include "code_02134398.h"
#include "code_02147cd8.h"
#include "Main/Unknown/code_020ee684.h"
#include "Main/Unknown/code_02077bc0.h"

#pragma thumb on
#pragma optimize_for_size on

void *FindItemFile(u8 *fileName) {
    char buf[0x100];

    if (fileName == NULL) {
        return NULL;
    }
    snprintf(buf, 0x100, gItemFileFormat, fileName);
    return FindMainRaceOrMainEffectFile(buf);
}

NsbmdModel *CreateItemModel(u8 *modelName, u8 *animationName, u8 *textureName) {
    NsbmdModel *model;
    void *modelFile;
    void *animationFile;

    model = HeapAlloc(GetHeap(GetCurrentHeapCall()), 0x2c);
    modelFile = FindItemFile(modelName);
    animationFile = FindItemFile(animationName);
    InitNsbmdModel(model, modelFile, animationFile, 0);
    model->mPolygonAttributes &= 0xc0ffffff;
    model->mPolygonAttributes |= 0x04000000;
    model->mPolygonAttributes &= ~0xf;
    model->mPolygonAttributes |= 0x2;
    model->mSpecEmi &= 0x8000ffff;
    model->mSpecEmi |= 0x10840000;
    return model;
}

void *CreateItemNsbmd(u8 *modelName, u8 *textureName) {
    void *model;
    void *modelFile;

    model = HeapAlloc(GetHeap(GetCurrentHeapCall()), 0x6c);
    modelFile = FindItemFile(modelName);
    InitNsbmd(model, modelFile);
    SetNsbmdPolygonIdLightEmiAll(model, 4, 2, 0x294a);
    return model;
}

void CreateItemModels(void) {
    enum { K0 } i;
    ItemKind *itemKind;
    BOOL isRainbowCourse;

    i = 0;
    while (i < 0xe) {
        gItemModels[i] = NULL;
        i++;
    }
    gItemModels[0] = CreateItemModel(gItemKouraGNsbmdName, NULL, gItemKouraGNsbtxName);
    gItemModels[1] = CreateItemModel(gItemKouraRNsbmdName, NULL, gItemKouraRNsbtxName);
    gItemModels[2] = CreateItemModel(gItemBananaNsbmdName, NULL, gItemBananaNsbtxName);
    gItemModels[3] = CreateItemModel(gItemKinokoNsbmdName, NULL, gItemKinokoNsbtxName);
    gItemModels[4] = CreateItemModel(gItemStarNsbmdName, NULL, gItemStarNsbtxName);
    gItemModels[5] = CreateItemModel(gItemKouraWNsbmdName, NULL, gItemKouraWNsbtxName);
    gItemModels[6] = CreateItemModel(gItemThunderNsbmdName, NULL, gItemThunderNsbtxName);
    gItemModels[7] = CreateItemModel(gItemFBoxNsbmdName, NULL, gItemFBoxNsbtxName);
    gItemModels[9] = CreateItemModel(gItemBombNsbmdName, gItemBombNsbtpName, gItemBombNsbtxName);
    gItemModels[10] = CreateItemModel(gItemGessoNsbmdName, NULL, gItemGessoNsbtxName);
    gItemModels[11] = CreateItemModel(gItemTeresaNsbmdName, NULL, gItemTeresaNsbtxName);
    gItemModels[12] = CreateItemModel(gItemKinokoPNsbmdName, NULL, gItemKinokoPNsbtxName);
    gItemModels[13] = CreateItemModel(gItemKillerNsbmdName, NULL, gItemKillerNsbtxName);
    gItemModels[8] = gItemModels[7];
    isRainbowCourse = (gRaceSetup->mCourseId == COURSE_ID_RAINBOW);
    i = 0;
    while (i < 0xe) {
        itemKind = &gItemKinds[i];
        if (itemKind->mSetup != NULL) {
            itemKind->mSetup();
        }
        if (isRainbowCourse != FALSE) {
            gItemModels[i]->mPolygonAttributes &= 0xffff7fff;
        }
        i++;
    }
}

#pragma optimize_for_size off
#pragma thumb off

void InitLinkFollowingItemFromInUse(LinkFollowingItemObject *follower, ItemInUse *inUse, s32 rampCount,
                                    s32 rampWeightPerCount, s32 throwForward, s32 d, s32 endsOnFirstHit, s32 baseSpeed,
                                    u16 targetKartIndex, s32 flag) {
    InitItemObjectThrow(follower, inUse, (endsOnFirstHit == 0) ? -1 : 0, throwForward, d, baseSpeed);
    follower->mRampTimer = rampCount;
    follower->mRampWeightPerCount = rampWeightPerCount;
    follower->mPreviousLink = inUse->mKartItems->mItemLink;
    PickNextItemPointLink(&follower->mPreviousLink, &follower->mTargetLink, targetKartIndex, flag);
    follower->mLinkWasBehind = 0;
}

BOOL TryInitLinkFollowingSegments(LinkFollowingItemObject *follower) {
    Vec3 vectors[6];
    Vec3 *direction;
    Vec3 *pos;
    s32 alignment;
    s32 alongDirection;

    pos = &follower->mDirectedItemObject.mItemObject.mPos;
    direction = &follower->mDirectedItemObject.mDirection;
    VEC_Subtract(follower->mTargetLink.mLink->mPointPos, pos, &vectors[0]);
    if (LENGTH_SQUARED(vectors[0]) >= 0x10) {
        Vec3NormalizeAndGetLengthUnchecked(&vectors[0], &vectors[1]);
    }
    alignment = Vec3DotUnrounded(direction, &vectors[1]);
    if (alignment > 0xddb || follower->mDirectedItemObject.mUnk_158 != 0) {
        vectors[0].x >>= 2;
        vectors[0].y >>= 2;
        vectors[0].z >>= 2;
        alongDirection = VEC_DotProduct(direction, &vectors[0]);
        vectors[1].x = MUL_FIXED12_NO_ROUND(direction->x, alongDirection);
        vectors[1].y = MUL_FIXED12_NO_ROUND(direction->y, alongDirection);
        vectors[1].z = MUL_FIXED12_NO_ROUND(direction->z, alongDirection);
        VEC_Add(&vectors[0], &vectors[1], &vectors[0]);
        VEC_Subtract(pos, &vectors[1], &vectors[2]);
        vectors[3] = *pos;
        VEC_Add(pos, &vectors[0], &vectors[4]);
        vectors[5] = *follower->mTargetLink.mLink->mPointPos;
        InitSegmentPoints(&follower->mSegmentPoints, &vectors[2], follower->mDirectedItemObject.mSpeed);
        return TRUE;
    }
    return FALSE;
}

void SteerLinkFollowingItemToLink(LinkFollowingItemObject *follower, s32 targetSpeed, s32 targetKartIndex, s32 flag) {
    Vec3 toLink;
    Vec3 *direction;
    Vec3 *surfaceDirection;
    Vec3 *sideDirection;
    s32 value;
    s32 scalar;

    AdvanceItemObjectMotion(&follower->mDirectedItemObject, targetSpeed);
    if (follower->mDirectedItemObject.mUnk_158 != 0 &&
        (follower->mDirectedItemObject.mItemObject.mFlags & 0x20000) != 0) {
        value = GetKart((u16) (follower->mDirectedItemObject.mItemObject.mOwnerKartIndexAndFlags & ~0xff00))
                    ->mDrawMatrixPos.y +
                0x1e000;
        if (follower->mDirectedItemObject.mItemObject.mPos.y < value) {
            follower->mDirectedItemObject.mItemObject.mPos.y = value;
        }
    }
    if (follower->mDirectedItemObject.mItemObject.mFlags & 1) {
        return;
    }
    if (follower->mDirectedItemObject.mUnk_158 == 0) {
        if (follower->mDirectedItemObject.mItemObject.mFlags & 0x20000) {
            return;
        }
    }
    direction = &follower->mDirectedItemObject.mDirection;
    surfaceDirection = &follower->mDirectedItemObject.mSurfaceDirection;
    if (CopyCloserItemPointLinkRef(&follower->mPreviousLink, &follower->mTargetLink, &follower->mPreviousLink,
                                   &follower->mDirectedItemObject.mItemObject.mPos) != FALSE) {
        PickNextItemPointLink(&follower->mPreviousLink, &follower->mTargetLink, targetKartIndex, flag);
    }
    VEC_Subtract(follower->mTargetLink.mLink->mPointPos, &follower->mDirectedItemObject.mItemObject.mPos, &toLink);
    if (follower->mDirectedItemObject.mItemObject.mFlags & 0x40000000) {
        scalar = VEC_DotProduct(surfaceDirection, &toLink);
        toLink.x -= MUL_FIXED12_NO_ROUND(surfaceDirection->x, scalar);
        toLink.y -= MUL_FIXED12_NO_ROUND(surfaceDirection->y, scalar);
        toLink.z -= MUL_FIXED12_NO_ROUND(surfaceDirection->z, scalar);
        scalar = VEC_DotProduct(&follower->mDirectedItemObject.mItemObject.mNormal, &toLink);
        toLink.x -= MUL_FIXED12_NO_ROUND(follower->mDirectedItemObject.mItemObject.mNormal.x, scalar);
        toLink.y -= MUL_FIXED12_NO_ROUND(follower->mDirectedItemObject.mItemObject.mNormal.y, scalar);
        toLink.z -= MUL_FIXED12_NO_ROUND(follower->mDirectedItemObject.mItemObject.mNormal.z, scalar);
        VEC_MultAdd(0x29, &toLink, &follower->mDirectedItemObject.mItemObject.mPos,
                    &follower->mDirectedItemObject.mItemObject.mPos);
        VEC_MultAdd(0x3, &toLink, surfaceDirection, surfaceDirection);
        return;
    }
    if (Vec3DotUnrounded(surfaceDirection, &toLink) < 0) {
        sideDirection = &follower->mDirectedItemObject.mSideDirection;
        Vec3CrossUnrounded(surfaceDirection, &follower->mDirectedItemObject.mItemObject.mNormal, sideDirection);
        if (Vec3DotUnrounded(sideDirection, &toLink) > 0) {
            toLink = *sideDirection;
        } else {
            toLink.x = -sideDirection->x;
            toLink.y = -sideDirection->y;
            toLink.z = -sideDirection->z;
        }
        follower->mLinkWasBehind = 1;
    }
    if (LENGTH_SQUARED(toLink) >= 0x10) {
        Vec3NormalizeAndGetLengthUnchecked(&toLink, &toLink);
    }
    scalar = 0x1000 - follower->mRampTimer * follower->mRampWeightPerCount;
    value = (follower->mLinkWasBehind != 0) ? 0x266 : 0x148;
    BlendDirectionTowardVector(direction, MUL_FIXED12_NO_ROUND(value, scalar), &toLink, &toLink);
    SetItemObjectDirection(follower, &toLink);
}

void AdvanceLinkFollowingItemSegments(LinkFollowingItemObject *follower, s32 targetSpeed, s32 speedEase,
                                      s32 targetKartIndex, s32 flag) {
    SegmentPoints *segmentPoints;
    Vec3 *pos;
    Vec3 *velocity;
    Vec3 vector;
    Vec3 hitNormal;
    Vec3 wallNormal;
    Vec3 prevPos;
    s32 value;
    BOOL hasFlag40000000;
    s32 alongNormal;

    segmentPoints = &follower->mSegmentPoints;
    pos = &follower->mDirectedItemObject.mItemObject.mPos;
    velocity = &follower->mDirectedItemObject.mItemObject.mVelocity;
    hasFlag40000000 = (follower->mDirectedItemObject.mItemObject.mFlags & 0x40000000) != 0;
    targetSpeed -= follower->mDirectedItemObject.mSpeed;
    follower->mDirectedItemObject.mSpeed =
        follower->mDirectedItemObject.mSpeed + MUL_FIXED12_NO_ROUND(targetSpeed, speedEase);
    SetSegmentProgressRate(&segmentPoints->mSegmentProgress, follower->mDirectedItemObject.mSpeed);
    if (AdvanceSegmentProgress(&segmentPoints->mSegmentProgress) != FALSE) {
        do {
            follower->mPreviousLink = follower->mTargetLink;
            PickNextItemPointLink(&follower->mPreviousLink, &follower->mTargetLink, targetKartIndex, flag);
        } while (PushSegmentPoint(segmentPoints, follower->mTargetLink.mLink->mPointPos) != 0);
    }
    if (hasFlag40000000) {
        prevPos = *pos;
        GetSegmentProgressPoint(segmentPoints, pos);
        velocity->y = 0;
        if (follower->mDirectedItemObject.mUnk_158 == 0) {
            VEC_Subtract(pos, &prevPos, &prevPos);
            alongNormal = Vec3DotUnrounded(&prevPos, &follower->mDirectedItemObject.mItemObject.mNormal);
            if (alongNormal > 0) {
                VEC_MultAdd(-alongNormal, &follower->mDirectedItemObject.mItemObject.mNormal, pos, pos);
            }
        }
    } else {
        if (follower->mDirectedItemObject.mUnk_158 != 0 &&
            (follower->mDirectedItemObject.mItemObject.mFlags & 0x20000) != 0) {
            vector.y = pos->y;
            GetSegmentProgressPointXzLinearY(&segmentPoints->mSegmentProgress, pos);
            if (pos->y < vector.y) {
                pos->y = vector.y;
            }
        } else {
            GetSegmentProgressPointXz(&segmentPoints->mSegmentProgress, pos);
        }
        pos->y = pos->y + velocity->y;
    }
    if (CollideSphereWithCourse(pos, &follower->mDirectedItemObject.mItemObject.mPrevPos, 0,
                                follower->mDirectedItemObject.mItemObject.mCourseRadius, 4,
                                follower->mDirectedItemObject.mItemObject.mCollisionSlotIndex, &vector, &hitNormal,
                                &wallNormal, &follower->mDirectedItemObject.mItemObject.mCollisionBits, NULL, NULL,
                                NULL, NULL) != 0) {
        if (follower->mDirectedItemObject.mUnk_158 != 0) {
            if (vector.y > 0) {
                pos->y = pos->y + vector.y;
            }
        } else {
            VEC_Add(&vector, pos, pos);
        }
        if (follower->mDirectedItemObject.mItemObject.mCollisionBits & 0x1e34ef) {
            value = VEC_DotProduct(&hitNormal, velocity);
            velocity->x -= MUL_FIXED12_NO_ROUND(hitNormal.x, value);
            velocity->y -= MUL_FIXED12_NO_ROUND(hitNormal.y, value);
            velocity->z -= MUL_FIXED12_NO_ROUND(hitNormal.z, value);
            value = (hitNormal.x == follower->mDirectedItemObject.mItemObject.mNormal.x &&
                     hitNormal.y == follower->mDirectedItemObject.mItemObject.mNormal.y &&
                     hitNormal.z == follower->mDirectedItemObject.mItemObject.mNormal.z)
                        ? 1
                        : 0;
            if (value == 0) {
                follower->mDirectedItemObject.mItemObject.mNormal = hitNormal;
                follower->mDirectedItemObject.mItemObject.mFlags |= 0x100;
            }
        }
        if ((follower->mDirectedItemObject.mItemObject.mCollisionBits & 0x214300) != 0 &&
            follower->mDirectedItemObject.mHasHitLimit != FALSE) {
            value = VEC_DotProduct(&wallNormal, velocity);
            vector.x = MUL_FIXED12_NO_ROUND(wallNormal.x, value);
            vector.y = MUL_FIXED12_NO_ROUND(wallNormal.y, value);
            vector.z = MUL_FIXED12_NO_ROUND(wallNormal.z, value);
            velocity->x -= vector.x;
            velocity->y -= vector.y;
            velocity->z -= vector.z;
            VEC_Subtract(velocity, &vector, velocity);
            velocity->x = MUL_FIXED12_NO_ROUND(velocity->x, 0x23d);
            velocity->y = MUL_FIXED12_NO_ROUND(velocity->y, 0x23d);
            velocity->z = MUL_FIXED12_NO_ROUND(velocity->z, 0x23d);
            FadeOutUsedUpItemObject(&follower->mDirectedItemObject.mItemObject, 1);
            return;
        }
        if (follower->mDirectedItemObject.mItemObject.mCollisionBits & 0x8000) {
            if (follower->mDirectedItemObject.mItemObject.mKind != 5) {
                FadeOutItemObjectNoCallback(&follower->mDirectedItemObject.mItemObject, 1);
                return;
            }
        }
    }
    ApplyItemObjectGravity(follower);
    velocity->x = pos->x - follower->mDirectedItemObject.mItemObject.mPrevPos.x;
    velocity->z = pos->z - follower->mDirectedItemObject.mItemObject.mPrevPos.z;
}

void AdvanceLinkFollowingItem(LinkFollowingItemObject *follower, s32 targetSpeed, s32 speedEase, s32 targetKartIndex,
                              s32 flag) {
    if (follower->mRampTimer >= 0) {
        SteerLinkFollowingItemToLink(follower, targetSpeed, targetKartIndex, flag);
        if (follower->mRampTimer == 0) {
            if (TryInitLinkFollowingSegments(follower) != FALSE) {
                follower->mRampTimer = -1;
            }
            return;
        }
        if (follower->mDirectedItemObject.mItemObject.mFlags & 0x40020000) {
            if (follower->mDirectedItemObject.mUnk_158 == 0) {
                return;
            }
        }
        follower->mRampTimer -= 1;
    } else {
        AdvanceLinkFollowingItemSegments(follower, targetSpeed, speedEase, targetKartIndex, flag);
    }
}

void InitLinkFollowingItem(LinkFollowingItemObject *follower, s32 rampCount, s32 rampWeightPerCount, s32 unused,
                           s32 endsOnFirstHit, s32 reverse, u16 targetKartIndex, s32 flag) {
    InitItemObjectMotion(follower, (endsOnFirstHit == 0) ? -1 : 0, reverse, unused);
    follower->mRampTimer = rampCount;
    follower->mRampWeightPerCount = rampWeightPerCount;
    PickNextItemPointLink(&follower->mPreviousLink, &follower->mTargetLink, targetKartIndex, flag);
    follower->mLinkWasBehind = 0;
}
