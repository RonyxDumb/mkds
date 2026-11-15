#include "Main/Kart/kart_ai_item_throw.h"

#include "code_0212d214.h"
#include "Main/Kart/kart_drift.h"
#include "Main/Item/item_in_use.h"
#include "Main/Race/data_020f36d8.h"
#include "Main/MapObjects/data_02166000.h"
#include "Main/MapObjects/data_02165000.h"
#include "Main/Menu/second_menu_scene.h"
#include "Main/Scene/display_settings.h"
#include "code_020182c0.h"
#include "frameheap.h"
#include "os_thread.h"
#include "Main/MapObjects/map_object_park.h"
#include "pm.h"
#include "Main/Sound/sound_seq.h"
#include "Main/Kart/kart_name_tags.h"
#include "Main/Graphics/nsbmd_render_obj.h"
#include "Main/Sound/data_0210b000.h"
#include "Main/Race/data_021759c0.h"
#include "tp.h"
#include "code_020172d0.h"
#include "code_02147cd8.h"
#include "Main/Graphics/model_effects.h"
#include "Main/MapObjects/data_0217b000.h"
#include "Main/System/heap.h"
#include "Main/Kart/kart_ai_battle.h"
#include "Main/Item/item_pool.h"
#include "Main/Kart/data_0207b000.h"
#include "Main/Kart/kart_ai.h"
#include "Main/System/result_archive_path.h"
#include "code_0201750c.h"
#include "Main/Item/data_027e0000.h"
#include "Main/MapObjects/data_0217a000.h"
#include "Main/Kart/code_0208fd8c.h"
#include "Main/Kart/code_0208ffe4.h"
#include "Main/Kart/code_02090088.h"
#include "Main/Kart/karts.h"
#include "registers.h"
#include "Main/Race/gp_records_killer.h"
#include "Main/Save/ghost_record_file.h"

u8 gPosStripFirstPolygonId = 0xe;
u8 gPosStripAlphaDecreasePerFrame = 3;
u16 gPosStripMaxAgeFrames = 8;
u16 gPosStripPointsPerStrip = 0xc;
PosStripTexture gPosStripTexture = {0x38100000, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, 0, 0, 0};
s32 gPosStripDrawEnabled = 1;
s32 (*gSetPosStripPointFunction)() = (s32(*)()) SetPosStripPointFromPos;
s32 gPosStripHeightDecreasePerFrame = 0x4d;
s32 gAwardStripCharacterYOffsets[13][2] = {
    {0x7000, 0},     {0xa000, 0x333}, {0x7000, -819}, {0xd000, 0},    {0x5800, 0x4cd}, {0x8000, 0x333}, {0x7000, -1843},
    {0x6800, -2458}, {0x6800, 0},     {0x5b33, -410}, {0x5ccd, -819}, {0xa000, 0},     {0x7000, 0}};
s32 gAwardStripKartYOffsets[37] = {0x11f, 0x30a, 0x19a, 0x11f, 0x19a, 0x19a, 0x11f, 0x30a, 0x214, 0x11f,
                                   0x30a, 0x266, 0x11f, 0x2cd, 0x214, 0x11f, 0x1ec, 0x333, 0x11f, 0x2b8,
                                   0x148, 0x11f, 0x11f, 0x19a, 0x11f, 0x1ec, 0x51f, 0x11f, 0x214, 0x214,
                                   0x11f, 0x1ec, 0x2e1, 0x11f, 0x148, 0x7ae, 0x11f};
PosStrips *gPosStrips;

void HardSetItemBitsEveryCall(KartAiItemUse *itemUse, struct KartAi *kartAi) {
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
        if (kartAi->mTargetDistanceSquared >= KART_AI_ITEM_RANGE_SQUARED) {
            return;
        }
        if (kartAi->mTargetAhead != 0 && kartAi->mTargetForwardDot > KART_AI_AHEAD_DOT) {
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

void SetItemBitsEveryCall(KartAiItemUse *itemUse, struct KartAi *kartAi) {
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
        if (kartAi->mTargetDistanceSquared >= KART_AI_ITEM_RANGE_SQUARED) {
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
    if (kartAi->mTurnAngleDegrees >= KART_AI_ITEM_TURN_ANGLE_LIMIT) {
        return;
    }
    UseItemAndResetHeldTimer(itemUse, kartAi);
}

void SetupBattleItemInUseEntry(KartAiItemUse *itemUse, struct KartAi *kartAi) {
    enum { OBJECT_KIND_FIRST } objectKind = (gKartItems)[kartAi->mIndex].mItemInUse.mObjectKind;
    const KartAiItemUseEntry *itemInUseEntry = &gBattleItemInUseEntries[objectKind];

    itemUse->mItemInUseEntry = itemInUseEntry;
    ResetItemInUseTimer(itemUse, itemInUseEntry);
}

void BattleItemInUseNop(KartAiItemUse *itemUse, struct KartAi *kartAi) {}

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
    if (kartAi->mTargetDistanceSquared >= KART_AI_ITEM_RANGE_SQUARED) {
        return;
    }
    if (kartAi->mTargetAhead != 0 && kartAi->mTargetForwardDot > KART_AI_AHEAD_DOT) {
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
        if (kartAi->mTargetDistanceSquared >= KART_AI_ITEM_RANGE_SQUARED) {
            return;
        }
        if (kartAi->mTargetAhead != 0 && kartAi->mTargetForwardDot > KART_AI_AHEAD_DOT) {
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
    if (kartAi->mTargetDistanceSquared >= KART_AI_ITEM_RANGE_SQUARED) {
        return;
    }
    if (kartAi->mTargetAhead != 0 && kartAi->mTargetForwardDot > KART_AI_AHEAD_DOT) {
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
    if (kartAi->mTargetDistanceSquared >= KART_AI_ITEM_RANGE_SQUARED) {
        return;
    }
    if (kartAi->mTargetAhead == 0) {
        return;
    }
    if (kartAi->mTargetForwardDot <= KART_AI_AHEAD_DOT_LOOSE) {
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
    if (kartAi->mTargetDistanceSquared >= KART_AI_ITEM_RANGE_SQUARED) {
        return;
    }
    if (kartAi->mTargetAhead == 0) {
        return;
    }
    if (kartAi->mTargetForwardDot <= KART_AI_AHEAD_DOT_LOOSE) {
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
    if (kartAi->mTargetDistanceSquared >= KART_AI_ITEM_RANGE_SQUARED) {
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
    if (kartAi->mTargetDistanceSquared >= KART_AI_ITEM_RANGE_SQUARED) {
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
    if (kartAi->mTargetDistanceSquared >= KART_AI_ITEM_RANGE_SQUARED) {
        return;
    }
    if (kartAi->mTargetAhead != 0) {
        if (kartAi->mTargetForwardDot <= KART_AI_AHEAD_DOT) {
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
        if (kartAi->mTargetDistanceSquared >= KART_AI_ITEM_RANGE_SQUARED) {
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
    if (kartAi->mTargetDistanceSquared >= KART_AI_ITEM_RANGE_SQUARED) {
        return;
    }
    if (kartAi->mTargetAhead != 0) {
        if (kartAi->mTargetForwardDot <= KART_AI_AHEAD_DOT) {
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
        if (kartAi->mTargetDistanceSquared >= KART_AI_ITEM_RANGE_SQUARED) {
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
        gRaceSetup->mRaceKind == RACE_KIND_AWARD ? "/effect/award_track.nsbtx" : "/effect/hanegame.nsbtx");
    gPosStripHeightDecreasePerFrame = 0x4d;
    gPosStripMaxAgeFrames = 8;
    gPosStripAlphaDecreasePerFrame = 3;
    gPosStripPointsPerStrip = 0xc;
    gSetPosStripPointFunction = (s32(*)()) SetPosStripPointFromPos;
    gPosStripFirstPolygonId = 0xe;
    gPosStripDrawEnabled = 1;
    stripCount = 1;
    if (gRaceSetup->mMode == MODE_WIFI) {
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
        heap = gOverlayLoader->mExpHeap;
    }
    gPosStrips = HeapAlloc(heap, sizeof(*gPosStrips));
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
            reg_G3X_DISP3DCNT = (reg_G3X_DISP3DCNT & ~(REG_G3X_DISP3DCNT_GO_MASK | REG_G3X_DISP3DCNT_RO_MASK)) | 8;
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
    kartVector = &kart->mRotationRow0;
    stripOffset = posStrip->mOffsetX;
    offsetVectorX.x = MUL_FIXED12_NO_ROUND(kartVector->x, stripOffset);
    offsetVectorX.y = MUL_FIXED12_NO_ROUND(kartVector->y, stripOffset);
    offsetVectorX.z = MUL_FIXED12_NO_ROUND(kartVector->z, stripOffset);
    kartVector = &kart->mRotationRow1;
    stripOffset = posStrip->mOffsetY;
    offsetVectorY.x = MUL_FIXED12_NO_ROUND(kartVector->x, stripOffset);
    offsetVectorY.y = MUL_FIXED12_NO_ROUND(kartVector->y, stripOffset);
    offsetVectorY.z = MUL_FIXED12_NO_ROUND(kartVector->z, stripOffset);
    kartVector = &kart->mRotationRow2;
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
            strip->mOffsetZ = gAwardStripCharacterYOffsets[kartModelsEntry->mCharacterIndex][1] +(kartOffset.z << 4);
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
