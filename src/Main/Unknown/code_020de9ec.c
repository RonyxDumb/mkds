#include "Main/Unknown/code_020de9ec.h"
#include "Main/Unknown/code_02036820.h"
#include "Main/Unknown/code_02081618.h"
#include "Main/Unknown/code_0208b484.h"
#include "Main/Unknown/code_020d3b10.h"
#include "Main/Unknown/code_020d8c74.h"

#include "Main/Unknown/code_020de9f8.h"
#include "Main/Unknown/code_0206bcb0.h"
#include "Main/Unknown/code_020d2000.h"
#include "Main/Unknown/code_020d8654.h"
#include "Main/Unknown/code_020deb2c.h"
#include "code_02012b30.h"
#include "Main/Unknown/code_020f9c6c.h"
#include "Main/Unknown/unk_021759c0.h"
#include "Main/Unknown/code_020debec.h"
#include "Main/Unknown/code_020364e0.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_0203c5e4.h"
#include "Main/Unknown/code_020b2ec0.h"
#include "Main/Unknown/code_020d3000.h"
#include "Main/Unknown/code_020d49d8.h"
#include "Main/Unknown/code_020e516c.h"
#include "Main/Unknown/code_020e55b4.h"
#include "Main/Unknown/code_020e66e4.h"
#include "Main/Unknown/code_020e6b58.h"
#include "Main/Unknown/code_020e6f50.h"
#include "Main/Unknown/unk_0215d000.h"
#include "Main/Unknown/unk_0217b000.h"
#include "Main/Unknown/code_020df428.h"
#include "code_021471bc.h"

#pragma thumb on

void InitGroupItemBox(ItemBox *itemBox, CourseMapRow *row) {
    InitItemBox(itemBox, row);
    if (itemBox->mUnk_0f8 != 0) {
        itemBox->mFollower.mUnk_00.mGroupIndex = (0x0000ffffu);
        return;
    }
    func_020d7d4c(&itemBox->mFollower, row, *&data_02158908, row->mUnk_28);
    SetupGroupFollowerWithSpeeds(&itemBox->mFollower, row->mUnk_30, 1);
    GetGroupFollowerCurvePosition(&itemBox->mFollower.mUnk_00, &itemBox->mUnk_000.mPos);
}

#pragma thumb off

#pragma thumb on
void func_020df3f8(void) {
    data_0217b750 = 0;
    data_0217b754 = 0;
    data_0217b75c = 0x1000;
    data_0217b760.x = 0x1000;
    data_0217b760.y = 0x1000;
    data_0217b760.z = 0x1000;
}
#pragma thumb off

MapObjectKindData *CreateItemBoxKindData(void) {
    MapObjectKindData *kindData;

    kindData = HeapAlloc(GetHeap(GetCurrentHeapCall()), 0x40);
    *kindData = data_02158654;
    return kindData;
}

MapObjectDrawList *CreateBoxDrawList(void) {
    gBoxDrawList = HeapAlloc(GetHeap(GetCurrentHeapCall()), 0x2c);
    *gBoxDrawList = data_02158628;
    SetDrawListSlot(&gBoxDrawList);
    return gBoxDrawList;
}

MapObjectDrawList *CreateQuestionDrawList(void) {
    gQuestionDrawList = HeapAlloc(GetHeap(GetCurrentHeapCall()), 0x2c);
    *gQuestionDrawList = data_021585fc;
    SetDrawListSlot(&gQuestionDrawList);
    return gQuestionDrawList;
}

MapObjectDrawList *func_020df294(void) {
    data_0217b714 = HeapAlloc(GetHeap(GetCurrentHeapCall()), 0x2c);
    *data_0217b714 = data_021585d0;
    SetDrawListSlot(&data_0217b714);
    return data_0217b714;
}

MapObjectList *CreateItemBoxUpdateList(void) {
    gItemBoxUpdateList = HeapAlloc(GetHeap(GetCurrentHeapCall()), 0x28);
    *gItemBoxUpdateList = data_021585a8;
    SetUpdateListSlot(&gItemBoxUpdateList);
    return gItemBoxUpdateList;
}

void SetupDrawBox(void) {
    QueueNsbmdModelMaterial(gBox);
}

void DrawBox(void *unused0, ItemBox *itemBox, void *unused1, u16 d) {
    MtxFx43 matrix;
    NsbmdModel *model;
    Vec3 *position;
    s32 cosine;
    s32 sine;
    s32 negatedProduct;
    u16 x;
    u16 polygonId;
    u16 newPolygonId;
    BoxRotation *rotation;

    if (itemBox->mUnk_0e8 < 1) {
        return;
    }
    if (itemBox->mDrawMatrixCallback != NULL) {
        itemBox->mDrawMatrixCallback(itemBox->mDrawMatrixCallbackOwner, &matrix);
        newPolygonId = AllocPolygonIdWrapping();
        model = gBox;
        model->mPolygonAttributes = model->mPolygonAttributes & 0xc0ffffff;
        model->mPolygonAttributes = model->mPolygonAttributes | newPolygonId << 24;
    } else {
        rotation = &gBoxRotations[itemBox->mBoxRotationIndex];
        cosine = rotation->mCosine;
        matrix.mUnk_00[0].x = cosine;
        sine = rotation->mSine;
        matrix.mUnk_00[0].y = sine;
        matrix.mUnk_00[0].z = 0;
        negatedProduct = -rotation->mCosineSineProduct;
        matrix.mUnk_00[1].x = negatedProduct;
        matrix.mUnk_00[1].y = rotation->mCosineSquared;
        matrix.mUnk_00[1].z = sine;
        matrix.mUnk_00[2].x = rotation->mSineSquared;
        matrix.mUnk_00[2].y = negatedProduct;
        matrix.mUnk_00[2].z = cosine;
        position = itemBox->mPositionSource;
        matrix.mUnk_00[3].x = position->x >> 4;
        matrix.mUnk_00[3].y = position->y >> 4;
        matrix.mUnk_00[3].z = position->z >> 4;
        polygonId = itemBox->mPolygonId;
        model = gBox;
        model->mPolygonAttributes = model->mPolygonAttributes & 0xc0ffffff;
        model->mPolygonAttributes = model->mPolygonAttributes | polygonId << 24;
    }
    x = itemBox->mUnk_0e8;
    model = gBox;
    model->mPolygonAttributes = model->mPolygonAttributes & 0xffe0ffff;
    model->mPolygonAttributes = model->mPolygonAttributes | x << 16;
    if (itemBox->mPositionSource != NULL) {
        if (itemBox->mUnk_000.mScale.z < 0x29) {
            return;
        }
        DrawNsbmdModelWithMatrixAndMaxAlpha(gBox, &matrix, &itemBox->mUnk_000.mScale, 0, d);
    } else {
        DrawNsbmdModelWithMatrixAndMaxAlpha(gBox, &matrix, NULL, 0, d);
    }
}

void SetupDrawQuestion(void) {
    QueueNsbmdModelMaterial(gQuestion);
}

void DrawQuestion(void *unused0, ItemBox *itemBox, void *unused1, u16 d) {
    MtxFx43 matrix;
    s32 cosine;
    s32 negatedSine;
    QuestionRotation *rotation;
    NsbmdModel *p;
    Vec3 *position;
    s32 x;
    NsbmdModel *p2;
    u16 polygonId;

    itemBox->mPolygonId = AllocPolygonIdWrapping();
    if (itemBox->mDrawMatrixCallback != NULL) {
        return;
    }
    if ((s32) (itemBox->mUnk_000.mDistanceSquaredAndFlags & 0x3fffffe0) > 0x27100) {
        if (func_0203c5e4() == 0) {
            return;
        }
    }
    if (itemBox->mUnk_0ec < 1) {
        return;
    }
    rotation = &gQuestionRotations[itemBox->mQuestionRotationIndex];
    cosine = rotation->mCosine;
    matrix.mUnk_00[0].x = cosine;
    matrix.mUnk_00[0].y = 0;
    negatedSine = -rotation->mSine;
    matrix.mUnk_00[0].z = negatedSine;
    matrix.mUnk_00[1].x = 0;
    matrix.mUnk_00[1].y = 0x1000;
    matrix.mUnk_00[1].z = 0;
    matrix.mUnk_00[2].x = -negatedSine;
    matrix.mUnk_00[2].y = 0;
    matrix.mUnk_00[2].z = cosine;
    position = itemBox->mPositionSource;
    matrix.mUnk_00[3].x = position->x >> 4;
    matrix.mUnk_00[3].y = position->y >> 4;
    matrix.mUnk_00[3].z = position->z >> 4;
    p = gQuestion;
    x = itemBox->mUnk_0ec;
    p->mPolygonAttributes &= 0xffe0ffff;
    p->mPolygonAttributes |= (u16) x << 16;
    polygonId = itemBox->mPolygonId;
    p2 = gQuestion;
    p2->mPolygonAttributes &= 0xc0ffffff;
    p2->mPolygonAttributes |= polygonId << 24;
    DrawNsbmdModelWithMatrixAndMaxAlpha(gQuestion, &matrix,
                                        itemBox->mPositionSource != NULL ? &itemBox->mUnk_000.mScale : 0, 0, d);
}

void func_020dee8c(void) {
    s32 angleIndex;

    func_020e55b4();
    if (GetChoisesSOpenDuringRace() != 0) {
        return;
    }
    data_0217b6fc += 0xca;
    angleIndex = data_0217b6fc >> 4;
    MTX_RotY43_(&data_0217b720, gPairsByAngle[angleIndex * 2], gPairsByAngle[angleIndex * 2 + 1]);
}

void func_020dec4c(void *unused, ItemBox *itemBox, u32 c, u32 d) {
    Vec3 shadowScale;
    Vec3 *position;
    s32 n;
    s32 x;
    s32 y;
    MtxFx43 *matrix;

    n = itemBox->mFramesSinceHit - 0x40;
    if (n >= 0x40) {
        itemBox->mUnk_0e8 = 0x1a;
        itemBox->mUnk_0ec = 0x14;
        n = 0xd;
    } else {
        x = n * 0x1a >> 6;
        y = n * 0x14 >> 6;
        n = n * 0xd >> 6;
        if (x > 0) {
            if (y < 1) {
                y = 1;
            }
            if (n < 1) {
                n = 1;
            }
        }
        itemBox->mUnk_0e8 = x;
        itemBox->mUnk_0ec = y;
    }
    if ((s32) (itemBox->mUnk_000.mDistanceSquaredAndFlags & ~0xc000001f) > 0x27100) {
        if (func_0203c5e4() == 0) {
            return;
        }
    }
    if (n < 1) {
        return;
    }
    if (itemBox->mShadowMode == 0) {
        itemBox->mUnk_0b4.mAlphaCap = n;
        func_020e54e4(&itemBox->mUnk_0b4, itemBox->mUnk_0a8 != 0 ? &data_0217b75c : 0, c, d);
        return;
    }
    if (itemBox->mShadowMode != 1) {
        return;
    }
    if (itemBox->mUnk_0a8 != 0) {
        position = itemBox->mPositionSource;
        data_0217b720.mUnk_00[3].x = position->x >> 4;
        data_0217b720.mUnk_00[3].y = position->y >> 4;
        data_0217b720.mUnk_00[3].z = position->z >> 4;
        DrawJgShadowWithMatrix(&data_0217b760, &data_0217b720, (u16) n, d);
        return;
    }
    shadowScale.x = ((s64) itemBox->mUnk_000.mScale.x * 0x1666) >> 12;
    shadowScale.y = ((s64) itemBox->mUnk_000.mScale.y * 0x1666) >> 12;
    shadowScale.z = ((s64) itemBox->mUnk_000.mScale.z * 0x1666) >> 12;
    if (itemBox->mDrawMatrixCallback != NULL) {
        matrix = SetTranslationMatrixPos(itemBox->mPositionSource);
    } else {
        position = itemBox->mPositionSource;
        data_0217b720.mUnk_00[3].x = position->x >> 4;
        data_0217b720.mUnk_00[3].y = position->y >> 4;
        data_0217b720.mUnk_00[3].z = position->z >> 4;
        matrix = &data_0217b720;
    }
    DrawJgShadowWithMatrix(&shadowScale, matrix, (u16) n, d);
}

void UpdateItemBox(void *unused, ItemBox *itemBox) {
    u32 framesSinceHit;

    itemBox->mBoxRotationIndex++;
    if (itemBox->mBoxRotationIndex >= 0x12c) {
        itemBox->mBoxRotationIndex = 0;
    }
    itemBox->mQuestionRotationIndex++;
    if (itemBox->mQuestionRotationIndex >= 0x82) {
        itemBox->mQuestionRotationIndex = 0;
    }
    framesSinceHit = itemBox->mFramesSinceHit;
    if (framesSinceHit >= 0x80) {
        return;
    }
    itemBox->mFramesSinceHit = framesSinceHit + 1;
    if (framesSinceHit > 0x60) {
        itemBox->mUnk_000.mFlags = itemBox->mUnk_000.mFlags & ~1;
    }
}

void func_020deb2c(Vec3 *position, void *kart, u32 c, int d, u32 e) {
    void *effect;
    u32 kartIndex;
    kartIndex = *OFFSET_PTR(u16, kart, 0x74);
    if (d == 0) {
        if (kartIndex == gRaceSetup->mEntryIndex) {
            effect = StartEffect(0x2d, position);
            if (effect != NULL) {
                SetupKartFollowEffect(effect, kartIndex, 0x1e);
            }
            effect = StartEffect(0x2e, position);
            if (effect != NULL) {
                SetupKartFollowEffect(effect, kartIndex, 0x1e);
            }
        }
        effect = StartEffect(0x2f, position);
        if (effect != NULL) {
            SetupKartFollowEffect(effect, kartIndex, 0x1e);
        }
    }
    func_020d26ec(kart, 0xd4);
    StartItemSlotForKart(kartIndex, c, e);
}

u8 CollideKartWithItemBox(ItemBox *itemBox, Kart *kart, void *c, u8 *d) {
    s32 playerKind;
    BOOL kindInMask;
    u32 distanceBits;

    if ((kart->mUnk_7c & 0x400000) != 0) {
        return 0;
    }
    kindInMask = FALSE;
    itemBox->mFramesSinceHit = 0;
    itemBox->mUnk_000.mFlags |= data_021585a4;
    distanceBits = itemBox->mUnk_000.mDistanceSquaredAndFlags & 3;
    playerKind = gRaceSetup->mCurrentEntries[kart->mIndex].mPlayer.mKind;
    if ((u32) playerKind <= 3) {
        if (((1 << playerKind) & PLAYER_KIND_MASK_HUMAN_GHOST_PEER) != 0) {
            kindInMask = TRUE;
        }
    }
    func_020deb2c(&itemBox->mUnk_000.mPos, kart, kindInMask != FALSE ? itemBox->mUnk_0f2 : itemBox->mUnk_0f4,
                  distanceBits, itemBox->mUnk_0ac);
    if (itemBox->mUnk_0f8 != 0 || itemBox->mUnk_000.mCourseMapRow->mUnk_32 != 0) {
        itemBox->mFramesSinceHit = 0x80;
        ParkMapObject(&itemBox->mUnk_000);
    }
    return *d;
}

u32 func_020de9f8(ItemBox *itemBox) {
    if (itemBox->mUnk_0f8 != 0) {
        return 0x270f000;
    }
    if (itemBox->mUnk_0a8 == 0) {
        return 0;
    }
    return GetMaxXzDistanceToGroup(&itemBox->mFollower.mUnk_00, &itemBox->mUnk_000.mPos);
}

void func_020de9ec(ItemBox *itemBox) {
    itemBox->mFramesSinceHit = 0x80;
}
