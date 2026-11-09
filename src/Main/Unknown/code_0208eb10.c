#include "Main/Unknown/code_0208eb10.h"

#include "Main/Unknown/code_02017000.h"
#include "Main/Unknown/code_0206bcb0.h"
#include "Main/Unknown/code_020ed5c0.h"
#include "Main/Unknown/code_020f36d8.h"
#include "Main/Unknown/unk_02166000.h"
#include "Main/Unknown/unk_021759c0.h"
#include "code_020172d0.h"
#include "code_02147cd8.h"
#include "Main/Unknown/code_0208d978.h"
#include "Main/Unknown/unk_0217b000.h"
#include "Main/Unknown/code_02036820.h"
#include "Main/Unknown/code_020888b4.h"
#include "Main/Unknown/code_020ee684.h"
#include "Main/Unknown/code_0207b000.h"
#include "Main/Unknown/code_0207c000.h"
#include "Main/Unknown/code_0208537c.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_02047000.h"
#include "Main/Unknown/unk_02164000.h"
#include "Main/Unknown/code_02047104.h"
#include "code_0201750c.h"
#include "Main/Unknown/unk_027e0000.h"
#include "Main/Unknown/unk_0217a000.h"
#include "Main/Unknown/code_0208fd8c.h"
#include "Main/Unknown/code_0208ffd8.h"
#include "Main/Unknown/code_0208ffe4.h"
#include "Main/Unknown/code_02090088.h"
#include "Main/Unknown/code_02090194.h"
#include "Main/Unknown/code_02077bc0.h"
#include "registers.h"

void HardSetItemBitsEveryCall(KartAiItemUse *itemUse) {
    itemUse->mItemBitsEveryCall = 0x1u;
}

void ThrowItemRandomAfterHeldOrAtNearTarget(KartAiItemUse *itemUse, KartAi *kartAi) {
    RandomState64 *kartAiRandom;
    s32 randomValue;

    if (DecrementHeldItemTimer(itemUse) != 0) {
        kartAiRandom = GetKartAiRandom();
        kartAiRandom->mValue = kartAiRandom->mMultiplier * kartAiRandom->mValue + kartAiRandom->mIncrement;
        randomValue = (s16) (u16) (kartAiRandom->mValue >> 52);
        if (randomValue < 0xb33) {
            UseItemForwardAndResetInUseTimer(itemUse, kartAi);
        } else {
            UseItemBehindAndResetInUseTimer(itemUse, kartAi);
        }
    } else {
        if (kartAi->mTargetKart == NULL) {
            return;
        }
        if (kartAi->mTargetDistanceSquared >= 0x15f90) {
            return;
        }
        if (kartAi->mTargetAhead != 0 && kartAi->mTargetForwardDot > 0xb33) {
            UseItemForwardAndResetInUseTimer(itemUse, kartAi);
        } else {
            UseItemBehindAndResetInUseTimer(itemUse, kartAi);
        }
    }
}

void ThrowItemRandomAfterHeld(KartAiItemUse *itemUse, KartAi *kartAi) {
    RandomState64 *kartAiRandom;
    s32 randomValue;

    if (DecrementHeldItemTimer(itemUse) == 0) {
        return;
    }
    kartAiRandom = GetKartAiRandom();
    kartAiRandom->mValue = kartAiRandom->mMultiplier * kartAiRandom->mValue + kartAiRandom->mIncrement;
    randomValue = (s16) (u16) (kartAiRandom->mValue >> 52);
    if (randomValue < 0xb33) {
        UseItemForwardAndResetInUseTimer(itemUse, kartAi);
    } else {
        UseItemBehindAndResetInUseTimer(itemUse, kartAi);
    }
}

void SetItemBitsEveryCall(KartAiItemUse *itemUse) {
    itemUse->mItemBitsEveryCall = 0x1u;
}

void ThrowItemRandomAfterHeldOrBehindNearTarget(KartAiItemUse *itemUse, struct KartAi *kartAi) {
    RandomState64 *kartAiRandom;
    s32 randomValue;

    if (DecrementHeldItemTimer(itemUse) != 0) {
        kartAiRandom = GetKartAiRandom();
        kartAiRandom->mValue = kartAiRandom->mMultiplier * kartAiRandom->mValue + kartAiRandom->mIncrement;
        randomValue = (s16) (u16) (kartAiRandom->mValue >> 52);
        if (randomValue > 0xccd) {
            UseItemBehindAndResetInUseTimer(itemUse, kartAi);
        } else {
            UseItemForwardAndResetInUseTimer(itemUse, kartAi);
        }
    } else {
        if (kartAi->mTargetKart == NULL) {
            return;
        }
        if (kartAi->mTargetDistanceSquared >= 0x15f90) {
            return;
        }
        UseItemBehindAndResetInUseTimer(itemUse, kartAi);
    }
}

void ThrowItemRandomMoreForwardAfterHeld(KartAiItemUse *itemUse, struct KartAi *kartAi) {
    RandomState64 *kartAiRandom;
    s32 randomValue;

    if (DecrementHeldItemTimer(itemUse) == 0) {
        return;
    }
    kartAiRandom = GetKartAiRandom();
    kartAiRandom->mValue = kartAiRandom->mMultiplier * kartAiRandom->mValue + kartAiRandom->mIncrement;
    randomValue = (s16) (u16) (kartAiRandom->mValue >> 52);
    if (randomValue > 0xccd) {
        UseItemBehindAndResetInUseTimer(itemUse, kartAi);
    } else {
        UseItemForwardAndResetInUseTimer(itemUse, kartAi);
    }
}

void BattleUseItemAfterHeld(KartAiItemUse *itemUse, struct KartAi *kartAi) {
    if (DecrementHeldItemTimer(itemUse) == 0) {
        return;
    }
    UseItemAndResetInUseTimer(itemUse, kartAi);
}

void UseItemAndResetHeldTimerAfterHeldIfTurnUnder10(KartAiItemUse *itemUse, struct KartAi *kartAi) {
    if (DecrementHeldItemTimer(itemUse) == 0) {
        return;
    }
    if (kartAi->mTurnAngleDegrees >= 0xa000) {
        return;
    }
    UseItemAndResetHeldTimer(itemUse, kartAi);
}

void SetupBattleItemInUseEntry(KartAiItemUse *itemUse, struct KartAi *kartAi) {
    enum { K0 } objectKind = (gKartItems)[kartAi->mIndex].mItemInUse.mObjectKind;
    KartAiItemUseEntry *itemInUseEntry = &gBattleItemInUseEntries[objectKind];

    itemUse->mItemInUseEntry = itemInUseEntry;
    ResetItemInUseTimer(itemUse, itemInUseEntry);
}

u32 BattleItemInUseReturnArgument(u32 value) {
    return value;
}

void ThrowItemByCircleKind(KartAiItemUse *itemUse, struct KartAi *kartAi) {
    if (gKartItems[kartAi->mIndex].mItemInUse.mUseKind == ITEM_USE_KIND_CIRCLE) {
        gThrowItemCircleKindCallback(itemUse, kartAi);
    } else {
        gThrowItemNotCircleKindCallback(itemUse, kartAi);
    }
}

void ThrowItemAtNearTarget(KartAiItemUse *itemUse, struct KartAi *kartAi) {
    if (kartAi->mTargetKart == NULL) {
        return;
    }
    if (kartAi->mTargetDistanceSquared >= 0x15f90) {
        return;
    }
    if (kartAi->mTargetAhead != 0 && kartAi->mTargetForwardDot > 0xb33) {
        UseItemForwardAndResetInUseTimer(itemUse, kartAi);
    } else {
        UseItemBehindAndResetInUseTimer(itemUse, kartAi);
    }
}

void ThrowItemRandomAfterInUseOrAtNearTarget(KartAiItemUse *itemUse, struct KartAi *kartAi) {
    RandomState64 *kartAiRandom;
    s32 randomValue;

    if (DecrementItemInUseTimer(itemUse) != 0) {
        kartAiRandom = GetKartAiRandom();
        kartAiRandom->mValue = kartAiRandom->mMultiplier * kartAiRandom->mValue + kartAiRandom->mIncrement;
        randomValue = (s16) (u16) (kartAiRandom->mValue >> 52);
        if (randomValue < 0xb33) {
            UseItemForwardAndResetInUseTimer(itemUse, kartAi);
        } else {
            UseItemBehindAndResetInUseTimer(itemUse, kartAi);
        }
    } else {
        if (kartAi->mTargetKart == NULL) {
            return;
        }
        if (kartAi->mTargetDistanceSquared >= 0x15f90) {
            return;
        }
        if (kartAi->mTargetAhead != 0 && kartAi->mTargetForwardDot > 0xb33) {
            UseItemForwardAndResetInUseTimer(itemUse, kartAi);
        } else {
            UseItemBehindAndResetInUseTimer(itemUse, kartAi);
        }
    }
}

void EasyThrowItemRandomAfterInUse(KartAiItemUse *itemUse, struct KartAi *kartAi) {
    RandomState64 *kartAiRandom;
    s32 randomValue;

    if (DecrementItemInUseTimer(itemUse) == 0) {
        return;
    }
    kartAiRandom = GetKartAiRandom();
    kartAiRandom->mValue = kartAiRandom->mMultiplier * kartAiRandom->mValue + kartAiRandom->mIncrement;
    randomValue = (s16) (u16) (kartAiRandom->mValue >> 52);
    if (randomValue < 0xb33) {
        UseItemForwardAndResetInUseTimer(itemUse, kartAi);
    } else {
        UseItemBehindAndResetInUseTimer(itemUse, kartAi);
    }
}

void ThrowItemAtNearTargetAfterInUseEveryCall(KartAiItemUse *itemUse, struct KartAi *kartAi) {
    itemUse->mItemBitsEveryCall = 1;
    if (DecrementItemInUseTimer(itemUse) == 0) {
        return;
    }
    if (kartAi->mTargetKart == NULL) {
        return;
    }
    if (kartAi->mTargetDistanceSquared >= 0x15f90) {
        return;
    }
    if (kartAi->mTargetAhead != 0 && kartAi->mTargetForwardDot > 0xb33) {
        UseItemForwardAndResetInUseTimer(itemUse, kartAi);
    } else {
        UseItemBehindAndResetInUseTimer(itemUse, kartAi);
    }
}

void ThrowItemRandomAfterInUse(KartAiItemUse *itemUse, struct KartAi *kartAi) {
    RandomState64 *kartAiRandom;
    s32 randomValue;

    if (DecrementItemInUseTimer(itemUse) == 0) {
        return;
    }
    kartAiRandom = GetKartAiRandom();
    kartAiRandom->mValue = kartAiRandom->mMultiplier * kartAiRandom->mValue + kartAiRandom->mIncrement;
    randomValue = (s16) (u16) (kartAiRandom->mValue >> 52);
    if (randomValue < 0xb33) {
        UseItemForwardAndResetInUseTimer(itemUse, kartAi);
    } else {
        UseItemBehindAndResetInUseTimer(itemUse, kartAi);
    }
}

void UseItemByCircleKind(KartAiItemUse *itemUse, struct KartAi *kartAi) {
    if (gKartItems[kartAi->mIndex].mItemInUse.mUseKind == ITEM_USE_KIND_CIRCLE) {
        gUseItemCircleKindCallback(itemUse, kartAi);
    } else {
        gUseItemNotCircleKindCallback(itemUse, kartAi);
    }
}

void UseItemAfterInUseAtNearTargetAheadDot(KartAiItemUse *itemUse, struct KartAi *kartAi) {
    if (DecrementItemInUseTimer(itemUse) == 0) {
        return;
    }
    if (kartAi->mTargetKart == NULL) {
        return;
    }
    if (kartAi->mTargetDistanceSquared >= 0x15f90) {
        return;
    }
    if (kartAi->mTargetAhead == 0) {
        return;
    }
    if (kartAi->mTargetForwardDot <= 0x666) {
        return;
    }
    UseItemAndResetInUseTimer(itemUse, kartAi);
}

void NormalUseItemAfterInUseAtNearTargetAheadDot(KartAiItemUse *itemUse, struct KartAi *kartAi) {
    if (DecrementItemInUseTimer(itemUse) == 0) {
        return;
    }
    if (kartAi->mTargetKart == NULL) {
        return;
    }
    if (kartAi->mTargetDistanceSquared >= 0x15f90) {
        return;
    }
    if (kartAi->mTargetAhead == 0) {
        return;
    }
    if (kartAi->mTargetForwardDot <= 0x666) {
        return;
    }
    UseItemAndResetInUseTimer(itemUse, kartAi);
}

void UseItemAfterInUse(KartAiItemUse *itemUse, struct KartAi *kartAi) {
    if (DecrementItemInUseTimer(itemUse) == 0) {
        return;
    }
    UseItemAndResetInUseTimer(itemUse, kartAi);
}

void HardUseItemAfterInUseAtNearTargetAhead(KartAiItemUse *itemUse, struct KartAi *kartAi) {
    if (DecrementItemInUseTimer(itemUse) == 0) {
        return;
    }
    if (kartAi->mTargetKart == NULL) {
        return;
    }
    if (kartAi->mTargetDistanceSquared >= 0x15f90) {
        return;
    }
    if (kartAi->mTargetAhead == 0) {
        return;
    }
    UseItemAndResetInUseTimer(itemUse, kartAi);
}

void UseItemAfterInUseAtNearTargetAhead(KartAiItemUse *itemUse, struct KartAi *kartAi) {
    if (DecrementItemInUseTimer(itemUse) == 0) {
        return;
    }
    if (kartAi->mTargetKart == NULL) {
        return;
    }
    if (kartAi->mTargetDistanceSquared >= 0x15f90) {
        return;
    }
    if (kartAi->mTargetAhead == 0) {
        return;
    }
    UseItemAndResetInUseTimer(itemUse, kartAi);
}

void ThrowItemByTrailKind(KartAiItemUse *itemUse, struct KartAi *kartAi) {
    if (gKartItems[kartAi->mIndex].mItemInUse.mUseKind == ITEM_USE_KIND_TRAIL) {
        gThrowItemTrailKindCallback(itemUse, kartAi);
    } else {
        gThrowItemNotTrailKindCallback(itemUse, kartAi);
    }
}

void ThrowItemAtNearTargetAheadDotAfterInUse(KartAiItemUse *itemUse, struct KartAi *kartAi) {
    if (DecrementItemInUseTimer(itemUse) == 0) {
        return;
    }
    if (kartAi->mTargetKart == NULL) {
        return;
    }
    if (kartAi->mTargetDistanceSquared >= 0x15f90) {
        return;
    }
    if (kartAi->mTargetAhead != 0) {
        if (kartAi->mTargetForwardDot <= 0xb33) {
            return;
        }
        UseItemForwardAndResetInUseTimer(itemUse, kartAi);
    } else {
        UseItemBehindAndResetInUseTimer(itemUse, kartAi);
    }
}

void ThrowItemRandomAfterInUseOrBehindNearTarget(KartAiItemUse *itemUse, struct KartAi *kartAi) {
    RandomState64 *kartAiRandom;
    s32 randomValue;

    if (DecrementItemInUseTimer(itemUse) != 0) {
        kartAiRandom = GetKartAiRandom();
        kartAiRandom->mValue = kartAiRandom->mMultiplier * kartAiRandom->mValue + kartAiRandom->mIncrement;
        randomValue = (s16) (u16) (kartAiRandom->mValue >> 52);
        if (randomValue > 0xb33) {
            UseItemBehindAndResetInUseTimer(itemUse, kartAi);
        } else {
            UseItemForwardAndResetInUseTimer(itemUse, kartAi);
        }
    } else {
        if (kartAi->mTargetKart == NULL) {
            return;
        }
        if (kartAi->mTargetDistanceSquared >= 0x15f90) {
            return;
        }
        UseItemBehindAndResetInUseTimer(itemUse, kartAi);
    }
}

void ThrowItemBehindNearTargetAfterInUseEveryCall(KartAiItemUse *itemUse, struct KartAi *kartAi) {
    itemUse->mItemBitsEveryCall = 1;
    if (DecrementItemInUseTimer(itemUse) == 0) {
        return;
    }
    if (kartAi->mTargetKart == NULL) {
        return;
    }
    if (kartAi->mTargetDistanceSquared >= 0x15f90) {
        return;
    }
    if (kartAi->mTargetAhead != 0) {
        if (kartAi->mTargetForwardDot <= 0xb33) {
            return;
        }
        UseItemBehindAndResetInUseTimer(itemUse, kartAi);
    } else {
        UseItemBehindAndResetInUseTimer(itemUse, kartAi);
    }
}

void UseItemBehindAfterInUseOrNearTarget(KartAiItemUse *itemUse, struct KartAi *kartAi) {
    if (DecrementItemInUseTimer(itemUse) == 0) {
        if (kartAi->mTargetKart == NULL) {
            return;
        }
        if (kartAi->mTargetDistanceSquared >= 0x15f90) {
            return;
        }
    }
    UseItemBehindAndResetInUseTimer(itemUse, kartAi);
}

// Allocates the strips and their points, loads the texture they are drawn with and sets the values for a race or the
// award scene.
void InitPosStrips(void *heap) {
    void *mainRaceOrMainEffectFile;
    PosStrip *strips;
    PosStripPoint *points;
    u16 index;
    u16 stripCount;
    u16 pointCount;
    NNSG3dResTex *effectTexture;
    s32 textureVramOffset;

    mainRaceOrMainEffectFile = FindMainRaceOrMainEffectFile(
        gRaceSetup->mRaceKind == RACE_KIND_AWARD ? gAwardTrackNsbtxName : gHanegameNsbtxName);
    gPosStripHeightDecreasePerFrame = 0x4d;
    gPosStripMaxAgeFrames = 8;
    gPosStripAlphaDecreasePerFrame = 3;
    gPosStripPointsPerStrip = 0xc;
    gSetPosStripPointFunction = (s32(*)()) SetPosStripPointFromPos;
    gPosStripFirstPolygonId = 0xe;
    gPosStripDrawEnabled = 1;
    stripCount = 1;
    if (gRaceSetup->mMode == 5) {
        stripCount += 3;
    } else if (gRaceSetup->mRaceKind == RACE_KIND_AWARD) {
        gPosStripHeightDecreasePerFrame = 0;
        gPosStripMaxAgeFrames = 0xe;
        gPosStripAlphaDecreasePerFrame = 2;
        gPosStripPointsPerStrip = 0x1e;
        gSetPosStripPointFunction = (s32(*)()) SetPosStripPointFromKart;
        gPosStripFirstPolygonId = 4;
        gPosStripDrawEnabled = 0;
        stripCount = 6;
    }
    pointCount = gPosStripPointsPerStrip * stripCount;
    if (gRaceSetup->mMode == MODE_MISSION_RUN) {
        heap = data_0217aa10->mExpHeap;
    }
    gPosStrips = HeapAlloc(heap, 0x38);
    strips = HeapAlloc(heap, stripCount * 0x30);
    points = HeapAlloc(heap, pointCount * 0x1c);
    NNS_FndInitList(&gPosStrips->mLists[0], 0);
    NNS_FndInitList(&gPosStrips->mLists[1], 0);
    NNS_FndInitList(&gPosStrips->mLists[2], 0);
    for (index = 0; index < stripCount; index++) {
        NNS_FndInitList(&strips[index].mPoints, 0);
        NNS_FndAppendListObject(&gPosStrips->mLists[1], &strips[index]);
    }
    for (index = 0; index < pointCount; index++) {
        NNS_FndAppendListObject(&gPosStrips->mLists[2], &points[index]);
    }
    AddResFileEntry(&gPosStrips->mEffectFileEntry, mainRaceOrMainEffectFile, mainRaceOrMainEffectFile);
    effectTexture = gPosStrips->mEffectFileEntry.mTexture;
    textureVramOffset = (effectTexture->mTexInfo.mVramKey & 0xffff) << 3;
    gPosStripTexture.mTexImageParam = gPosStripTexture.mTexImageParam & 0xffff0000;
    gPosStripTexture.mTexImageParam = gPosStripTexture.mTexImageParam | (((u32) textureVramOffset >> 3) & 0xffff);
    gPosStripTexture.mPlttBase = (effectTexture->mPlttInfo.mVramKey & 0xffff) << 3;
    gPosStripTexture.mLowHalfTexCoord = 0x10000;
    gPosStripTexture.mHighHalfTexCoord = 0x8000;
    gPosStrips->mPolygonAttrBits = gRaceSetup->mCourseId == COURSE_ID_RAINBOW ? 0 : 0x8000;
}

void UpdatePosStrips(void) {
    void *strip;
    strip = NNS_FndGetNextListObject(&gPosStrips->mLists[0], NULL);
    while (strip != NULL) {
        UpdatePosStrip(strip);
        strip = NNS_FndGetNextListObject(&gPosStrips->mLists[0], strip);
    }
}

void DrawPosStrips(const MtxFx43 *matrix) {
    PosStrip *strip;
    PosStripPoint *nextPoint;
    PosStripPoint *point;
    s32 polygonAlpha;
    u8 polygonId;
    BOOL isDrawStateSet;

    polygonId = gPosStripFirstPolygonId;
    isDrawStateSet = FALSE;
    strip = NNS_FndGetNextListObject(&gPosStrips->mLists[0], NULL);
    if (strip == NULL) {
        return;
    }
    do {
        if (isDrawStateSet == FALSE) {
            reg_G3X_DISP3DCNT = (reg_G3X_DISP3DCNT & ~0x3000) | 8;
            reg_G3_SPE_EMI = 0x7c004210;
            reg_G3_DIF_AMB = 0x42100000;
            reg_G3_MTX_MODE = 3;
            reg_G3_MTX_IDENTITY = 0;
            reg_G3_MTX_MODE = 2;
            reg_G3_TEXIMAGE_PARAM = gPosStripTexture.mTexImageParam;
            reg_G3_PLTT_BASE = gPosStripTexture.mPlttBase >> (4 - ((gPosStripTexture.mTexImageParam >> 26 & 7) == 2));
            isDrawStateSet = TRUE;
        }
        reg_G3_COLOR = 0x7fff;
        point = NNS_FndGetNextListObject(&strip->mPoints, NULL);
        if (point != NULL && gPosStripDrawEnabled != 0) {
            nextPoint = NNS_FndGetNextListObject(&strip->mPoints, NULL);
            if (nextPoint != NULL) {
                do {
                    polygonAlpha = 0x1f - point->mSinceAddedFrames * gPosStripAlphaDecreasePerFrame;
                    reg_G3_POLYGON_ATTR = polygonId << 24 | (gPosStrips->mPolygonAttrBits | 0xc0) | polygonAlpha << 16;
                    DrawPosStripQuad(matrix, point, nextPoint, &gPosStripTexture);
                    point = nextPoint;
                    nextPoint = NNS_FndGetNextListObject(&strip->mPoints, nextPoint);
                } while (nextPoint != NULL);
            }
        }
        polygonId = polygonId + 1;
        strip = NNS_FndGetNextListObject(&gPosStrips->mLists[0], strip);
    } while (strip != NULL);
}

void SetPosStripPointFromPos(PosStripPoint *stripPoint, PosStrip *strip) {
    const Vec3 *followedPos = strip->mFollowedPos;
    s32 stripHeight = strip->mHeight;
    stripPoint->mHeight = stripHeight;
    stripPoint->mSinceAddedFrames = 0;
    stripPoint->mPos.x = followedPos->x >> 4;
    stripPoint->mPos.y = followedPos->y >> 4;
    stripPoint->mPos.z = followedPos->z >> 4;
}

void SetPosStripPointFromKart(PosStripPoint *posStripPoint, PosStrip *posStrip) {
    Kart *kart;
    Vec3 position;
    Vec3 offsetVectorX;
    Vec3 offsetVectorY;
    Vec3 offsetVectorZ;
    Vec3 *kartVector;
    s32 stripOffset;

    kart = GetKart(posStrip->mKartIndex);
    position = kart->mPos;
    kartVector = &kart->mUnk_120;
    stripOffset = posStrip->mOffsetX;
    offsetVectorX.x = MUL_FIXED12_NO_ROUND(kartVector->x, stripOffset);
    offsetVectorX.y = MUL_FIXED12_NO_ROUND(kartVector->y, stripOffset);
    offsetVectorX.z = MUL_FIXED12_NO_ROUND(kartVector->z, stripOffset);
    kartVector = &kart->mUnk_12c;
    stripOffset = posStrip->mOffsetY;
    offsetVectorY.x = MUL_FIXED12_NO_ROUND(kartVector->x, stripOffset);
    offsetVectorY.y = MUL_FIXED12_NO_ROUND(kartVector->y, stripOffset);
    offsetVectorY.z = MUL_FIXED12_NO_ROUND(kartVector->z, stripOffset);
    kartVector = &kart->mUnk_138;
    stripOffset = posStrip->mOffsetZ;
    offsetVectorZ.x = MUL_FIXED12_NO_ROUND(kartVector->x, stripOffset);
    offsetVectorZ.y = MUL_FIXED12_NO_ROUND(kartVector->y, stripOffset);
    offsetVectorZ.z = MUL_FIXED12_NO_ROUND(kartVector->z, stripOffset);
    VEC_Add(&position, &offsetVectorX, &position);
    VEC_Add(&position, &offsetVectorY, &position);
    VEC_Add(&position, &offsetVectorZ, &position);
    posStripPoint->mHeight = posStrip->mHeight;
    posStripPoint->mSinceAddedFrames = 0;
    posStripPoint->mPos.x = position.x >> 4;
    posStripPoint->mPos.y = position.y >> 4;
    posStripPoint->mPos.z = position.z >> 4;
}

// Starts a strip that follows the position a points to; returns the strip, or 0 when none is free.
PosStrip *StartPosStrip(const Vec3 *followedPos) {
    PosStrip *strip;
    strip = NNS_FndGetNthListObject(&gPosStrips->mLists[1], 0);
    if (strip != NULL) {
        strip->mFollowedPos = followedPos;
        strip->mStopped = 0;
        strip->mHeight = 0x400;
        NNS_FndRemoveListObject(&gPosStrips->mLists[1], strip);
        NNS_FndAppendListObject(&gPosStrips->mLists[0], strip);
    }
    return strip;
}

// Award scene only: starts a strip that follows kart a.
PosStrip *StartAwardKartPosStrip(s32 kartIndex) {
    PosStrip *strip;
    Kart *kart;
    KartModelsEntry *kartModelsEntry;
    Vec3 kartOffset;
    s32 stripHeight;

    if (gRaceSetup->mRaceKind == RACE_KIND_AWARD) {
        strip = NNS_FndGetNthListObject(&gPosStrips->mLists[1], 0);
        if (strip != NULL) {
            kart = GetKart(kartIndex);
            kartModelsEntry = kart->mKartModelsEntry;
            kartOffset = kartModelsEntry->mKartOffsetData->mCharacterOffsets[kartModelsEntry->mCharacterIndex];
            strip->mFollowedPos = &kart->mPos;
            strip->mStopped = 0;
            strip->mHeight = 0x400;
            strip->mKartIndex = kartIndex;
            stripHeight = (kartOffset.y + (gAwardStripCharacterYOffsets[kartModelsEntry->mCharacterIndex][0] >> 4) -
                           gAwardStripKartYOffsets[kartModelsEntry->mKartIndex]) /
                          2;
            strip->mHeight = stripHeight;
            strip->mOffsetX = kartOffset.x << 4;
            strip->mOffsetY = (gAwardStripKartYOffsets[kartModelsEntry->mKartIndex] + stripHeight) << 4;
            strip->mOffsetZ = gAwardStripCharacterZOffsets[kartModelsEntry->mCharacterIndex][0] + (kartOffset.z << 4);
            NNS_FndRemoveListObject(&gPosStrips->mLists[1], strip);
            NNS_FndAppendListObject(&gPosStrips->mLists[0], strip);
        }
        return strip;
    }
    return NULL;
}

// Adds no more points to the strip; it goes back to the pool once its points have gone.
void StopPosStrip(PosStrip *strip) {
    strip->mStopped = 1;
}
