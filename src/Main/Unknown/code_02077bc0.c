#include "Main/Unknown/code_02077bc0.h"
#include "Main/Unknown/code_0207ae58.h"
#include "code_02012b30.h" // NNSG3dResFileHeader

#include "Main/System/Heap.h"
#include "code_020169a4.h"
#include "gfd_LinkedListTexVramMan.h"
#include "gfd_LinkedListPlttVramMan.h"
#include "code_020172d0.h"
#include "Main/System/ArchiveFiles.h"
#include "code_020176c0.h"
#include "code_0214a5e0.h"
#include "Main/Unknown/code_02048000.h"
#include "code_02013740.h"
#include "Main/Unknown/code_0207b000.h"
#include "Main/Unknown/code_02084000.h"
#include "Main/Unknown/code_02087000.h"
#include "Main/Unknown/code_02088000.h"
#include "Main/Unknown/unk_02155000.h"
#include "Main/Kart/KartResourcePaths.h"
#include "Main/Unknown/code_0207adf8.h"
#include "Main/Unknown/code_02017000.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_02148000.h"
#include "Main/Unknown/unk_0217a000.h"
#include "gx.h"
#include "Main/Unknown/code_02076cd0.h"
#include "Main/Item/ItemInUse.h"
#include "code_0200eddc.h"
#include "00/code_02181f98.h"
#include "01/code_021a2398.h"
#include "ITCM/code_01ff8000.h"
#include "ITCM/code_01ff9000.h"
#include "Main/Unknown/code_020799a0.h"
#include "Main/Unknown/code_0200e000.h"
#include "Main/Unknown/code_02087d0c.h"
#include "Main/Unknown/code_02108e6c.h"
#include "Main/Unknown/code_021108bc.h"
#include "Main/Unknown/unk_02165000.h"
#include "Main/Unknown/unk_02154000.h"
#include "Main/Unknown/unk_02175628.h"
#include "Main/Unknown/unk_021759c0.h"
#include "Main/Unknown/unk_0217d068.h"
#include "code_0212df7c.h"
#include "gx_load3d.h"
#include "code_0200fe74.h"
#include "code_02010c84.h"
#include "code_02016468.h"
#include "code_02147288.h"
#include "code_0214a748.h"
#include "code_0214d018.h"
#include "code_02146cbc.h"
#include "code_02146d78.h"
#include "code_02147cd8.h"
#include "Main/Unknown/code_02039860.h"
#include "code_020176b0.h"
#include "Main/Unknown/code_020364e0.h"
#include "Main/Unknown/code_02047104.h"
#include "Main/Unknown/code_02061654.h"
#include "Main/Unknown/code_02077000.h"
#include "gecom.h"
#include "Main/Unknown/code_0208533c.h"
#include "Main/Unknown/code_020846c0.h"
#include "Main/Unknown/unk_0215d000.h"
#include "Main/Unknown/unk_02170000.h"
#include "Main/Unknown/unk_02175000.h"
#include "Main/Unknown/code_02079a3c.h"
#include "Main/Unknown/code_0207a000.h"
#include "Main/Unknown/code_02056444.h"
#include "Main/Unknown/code_02047000.h"
#include "Main/Unknown/code_0205e000.h"
#include "Main/Unknown/unk_02164000.h"
#include "Main/Unknown/code_020b4000.h"
#include "Main/Unknown/code_0207a14c.h"
#include "Main/Unknown/code_020638c0.h"
#include "Main/Unknown/code_02079a14.h"
#include "Main/Unknown/code_0208aea8.h"
#include "Main/Unknown/code_0208537c.h"
#include "code_02134398.h"
#include "code_02133048.h"
#include "res_struct_accessor.h"
#include "Main/Unknown/code_02079a04.h"
#include "Main/Unknown/code_02087cd0.h"
#include "Main/Unknown/code_02079b40.h"
#include "Main/Unknown/code_02079b60.h"
#include "Main/Unknown/code_02079b9c.h"
#include "Main/Unknown/code_02079bcc.h"
#include "Main/Unknown/code_02079c0c.h"
#include "Main/Unknown/code_0207a104.h"
#include "Main/Unknown/code_0206bcb0.h"
#include "01/code_0218155c.h"
#include "Main/Unknown/code_0207a30c.h"
#include "Main/Unknown/code_0207a32c.h"
#include "Main/Unknown/code_0203c000.h"
#include "Main/Unknown/code_0207a68c.h"
#include "Main/Unknown/code_0207a6b0.h"
#include "Main/Unknown/code_0207a73c.h"
#include "Main/Unknown/code_0207a74c.h"
#include "Main/Unknown/code_0207a780.h"
#include "Main/Unknown/code_0207a790.h"
#include "Main/Unknown/code_02040de0.h"
#include "Main/Unknown/code_0207a7ec.h"
#include "Main/Unknown/code_02068eac.h"
#include "Main/Unknown/code_0207a7fc.h"
#include "Main/Unknown/code_02066ac0.h"
#include "Main/Unknown/code_02068000.h"
#include "Main/Unknown/code_0207a870.h"
#include "Main/Unknown/code_0207a880.h"
#include "Main/Unknown/code_0207a8c4.h"
#include "Main/Unknown/code_020b1dbc.h"
#include "Main/Unknown/code_0207b960.h"
#include "Main/Unknown/code_020b4e5c.h"
#include "Main/Unknown/code_02147000.h"
#include "Main/Unknown/code_020b47d8.h"
#include "Main/Unknown/code_020b6a18.h"
#include "Main/Unknown/code_020b502c.h"
#include "Main/Unknown/code_02063b70.h"
#include "Main/Unknown/code_020649ec.h"
#include "Main/Unknown/code_02073000.h"
#include "Main/Kart/KartAiCallbacks.h"
#include "Main/Unknown/code_02081618.h"
#include "Main/Unknown/code_02086058.h"
#include "Main/Unknown/code_020733ec.h"
#include "ITCM/code_01ffba68.h"
#include "Main/Unknown/code_0203c8dc.h"
#include "code_021471bc.h"

void func_0207ad88(ShadowModel *shadowModel, u32 b, u32 c) {
    if ((shadowModel->mFlags & 1) != 0) {
        model_configShadowPass1(shadowModel, shadowModel->mAlpha);
        gModelRenderFuncs[shadowModel->mNsbmd.mDrawKind](shadowModel);
        model_configShadowPass2(shadowModel, shadowModel->mAlpha, shadowModel->mPolygonId);
        gModelRenderFuncs[shadowModel->mNsbmd.mDrawKind](shadowModel);
    }
}

void driver_initAll(u32 kartCount) {
    u16 i;
    void *heap = proc_getHeap(proc_getCurrent());
    EntryKartCounters *entryKartCounters;
    sDrivers = heap_alloc(heap, kartCount * 0x5a8);
    driver_sDriverCount = kartCount;
    entryKartCounters = heap_alloc(heap, 0x1c);
    driver_sPlayerStatistics = entryKartCounters;
    gKillerItemKartIndex = 0;
    gMinKartDistanceSquaredPresent = 0;
    gMinKartDistanceSquared = -1;
    entryKartCounters->field0 = 0;
    entryKartCounters->field4 = 0;
    entryKartCounters->field8 = 0;
    entryKartCounters->fieldC = 0;
    entryKartCounters->field10 = 0;
    entryKartCounters->field14 = 0;
    entryKartCounters->field18 = 0;
    data_021658bc = gRaceMultiConfig->mMode == MODE_BATTLE ? 1 : 2;
    driver_initColResponses();
    enmy_setupFunctions();
    rptc_initForDrivers(kartCount);
    driver_sCheckMissionEndArea = 0;
    if (gRaceMultiConfig->mMode == MODE_MISSION_RUN) {
        if (gMapData->mKind2ShapeCountInMode4 != 0) {
            driver_sCheckMissionEndArea = 1;
        }
    }
    for (i = 0; i < kartCount; i++) {
        sDrivers[i].mIndex = i;
        sDrivers[i].mEntryIndex = gRaceMultiConfig->mCurrentEntries[i].mPlayer.mIndex;
        InitKart(&sDrivers[i], gKartDefaultSlotFunctions);
    }
    driver_sClipAreaMask = 0;
}

void UpdateKarts(void) {
    s32 i;
    Kart *kart = sDrivers;
    gMinKartDistanceSquaredPresent = 0;
    gMinKartDistanceSquared = -1;
    for (i = 0; i < driver_sDriverCount; i++) {
        driver_1FFCAC0(kart);
        kart++;
    }
    SetKartNearPlayerRankBits();
    kart = sDrivers;
    for (i = 0; i < driver_sDriverCount; i++) {
        kart->mSlotFunctions[3](kart);
        kart++;
    }
    kart = sDrivers;
    for (i = 0; i < driver_sDriverCount; i++) {
        kart->mSlotFunctions[4](kart);
        kart++;
    }
}

void UpdateKartSoundDistancesSquared(void) {
    Kart *kart = sDrivers;
    s16 i;
    for (i = 0; i < driver_sDriverCount; i++) {
        kart->mSlotFunctions[2](kart);
        kart++;
    }
}

void driver_renderAll(void) {
    s32 i = 0;
    u16 *kartIndices = GetKartIndicesByDistance();
    (sDrivers[gRaceMultiConfig->mEntryIndex].mKartModelsEntry)->field60 = TRUE;
    for (; i < driver_sDriverCount; i++) {
        driver_render(&sDrivers[*kartIndices]);
        kartIndices++;
    }
}

void driver_finalize(void) {
    s32 i;
    for (i = 0; i < driver_sDriverCount; i++) {
        CallKartSlot8(&sDrivers[i]);
    }
    sDrivers = NULL;
}

Kart *driver_getById(s32 kartIndex) {
    return &sDrivers[kartIndex];
}

void driver_getPosition(Vec3 *pos, s32 kartIndex) {
    *pos = *sDrivers[kartIndex].mPosSource;
}

void GetKartPosFromPosSourceCopy(Vec3 *pos, u8 kartIndex) {
    *pos = *sDrivers[kartIndex].mPosSourceCopy;
}

void driver_getKartChassisPosition(Vec3 *pos, s32 kartIndex) {
    *pos = sDrivers[kartIndex].mPrevPos;
}

void driver_getScale(Vec3 *scale, s32 kartIndex) {
    *scale = sDrivers[kartIndex].mScale;
}

u32 driver_getCollisionMode(u32 kartIndex) {
    return sDrivers[kartIndex].mItemEffect;
}

u16 driver_getYRot(s32 kartIndex) {
    return sDrivers[kartIndex].mHeadingAngle;
}

u32 driver_getCheckMissionEndArea(void) {
    return driver_sCheckMissionEndArea;
}

BOOL func_0207a84c(s32 kartIndex) {
    return func_02068eac(&sDrivers[kartIndex]);
}

void func_0207a828(s32 kartIndex) {
    func_02066fe0(&sDrivers[kartIndex]);
}

BOOL driver_getIsOnAntigravity(s32 kartIndex) {
    return (sDrivers[kartIndex].field48 & 1) != 0;
}

u32 GetKartForwardSpeedRatio(void) {
    return gKartForwardSpeedRatio;
}

// Sets bit i when the kart is inside kind 3 shape list i.
void driver_updateClipAreaMask(s32 kartIndex) {
    u16 i;

    driver_sClipAreaMask = 0;
    for (i = 0; i < 8; i++) {
        if (mdat_isDriverInClipArea(kartIndex, i) != 0) {
            driver_sClipAreaMask |= 1 << i;
        }
    }
}

u32 driver_getClipAreaMask(void) {
    return driver_sClipAreaMask;
}

// Stores the forward speed as a part of the speed limit, 0x1000 = 1.0.
void SetKartForwardSpeedRatio(s32 forwardSpeed) {
    gKartForwardSpeedRatio = ((s64) forwardSpeed * gKartSpeedLimitReciprocal + 0x800) >> 12;
}

void SetKartSpeedLimitReciprocal(u32 speedLimitReciprocal) {
    gKartSpeedLimitReciprocal = speedLimitReciprocal;
}

void driver_notifyItemHit(s32 kartIndex) {
    if (kartIndex == gRaceMultiConfig->mEntryIndex) {
        driver_sPlayerStatistics->field8++;
    }
}

void driver_notifyOffRoad(Kart *kart) {
    if (kart->mIndex != gRaceMultiConfig->mEntryIndex) {
        return;
    }
    if (kart->field4C & 0x40) {
        return;
    }
    if (!(kart->field48 & 0x20000000)) {
        driver_sPlayerStatistics->fieldC++;
    }
}

EntryKartCounters *driver_getPlayerStatistics(void) {
    return driver_sPlayerStatistics;
}

u32 func_0207a68c(int kartIndex) {
    return func_0206c0a8(&sDrivers[kartIndex]);
}

void driver_setFogEnableFlags(s32 fogEnableFlag) {
    s32 i;
    Kart *kart = sDrivers;
    KartModelsEntry *entry;
    for (i = 0; i < driver_sDriverCount; i++) {
        entry = kart->mKartModelsEntry;
        NNS_G3dMdlSetMdlFogEnableFlagAll(entry->mModels[1]->mResMdl, fogEnableFlag);
        NNS_G3dMdlSetMdlFogEnableFlagAll(entry->mModels[0]->mResMdl, fogEnableFlag);
        if (entry->mModels[2] != NULL) {
            NNS_G3dMdlSetMdlFogEnableFlagAll(entry->mModels[2]->mResMdl, fogEnableFlag);
        }
        kart++;
    }
}

BOOL driver_isFalling(s32 kartIndex) {
    return (sDrivers[kartIndex].field48 & 0x800) != 0 ? 1 : 0;
}

BOOL driver_isPlayerHit(void) {
    Kart *kart = &sDrivers[gRaceMultiConfig->mEntryIndex];
    if (kart->mState != KART_STATE_NORMAL || (kart->field48 & 0x4000000) != 0) {
        return TRUE;
    }
    return FALSE;
}

BOOL driver_isPlayerHittingWall(void) {
    return (sDrivers[gRaceMultiConfig->mEntryIndex].field44 & 0xc0) != 0 ? 1 : 0;
}

BOOL driver_isPlayerRespawning(void) {
    return (sDrivers[gRaceMultiConfig->mEntryIndex].field48 & 0x1000) != 0 ? 1 : 0;
}

void SetKartNearPlayerRankBits(void) {
    s32 kartIndices[3];
    u32 kartRank = rstat_getPlace((u16) gRaceMultiConfig->mEntryIndex);
    u16 i;
    u16 k;
    s32 kartIndex;
    Kart *kart;
    if (gRaceMultiConfig->mRaceKind == RACE_KIND_AWARD) {
        for (k = 0; k < 3; k++) {
            sDrivers[k].field4C |= KART_4C_NEAR_PLAYER_RANK;
        }
        return;
    }
    kartIndices[0] = gRaceMultiConfig->mEntryIndex;
    if (kartRank == 1) {
        kartIndices[1] = GetKartIndexAtRank(2);
        if (kartIndices[1] >= 0) {
            if ((sDrivers[kartIndices[1]].mKartModelsEntry)->field60 != FALSE) {
                kartIndices[1] = -1;
            }
        }
    } else {
        kartIndices[1] = GetKartIndexAtRank((u16) (kartRank - 1));
        if (kartIndices[1] >= 0) {
            if ((sDrivers[kartIndices[1]].mKartModelsEntry)->field60 != FALSE) {
                kartIndices[1] = -1;
            }
        }
        if (kartRank < gRaceMultiConfig->mKartCount) {
            kartIndex = GetKartIndexAtRank((u16) (kartRank + 1));
            if (kartIndex >= 0) {
                kart = &sDrivers[kartIndex];
                kart->field4C |= KART_4C_ONE_RANK_BEHIND_PLAYER;
            }
        }
    }
    for (i = 0; i < data_021658bc; i++) {
        kartIndex = kartIndices[i];
        if (kartIndex >= 0) {
            kart = &sDrivers[kartIndex];
            if ((kart->field4C & 0x10000000) == 0) {
                kart->field4C |= KART_4C_NEAR_PLAYER_RANK;
            }
        }
    }
}

u32 GetKillerItemKartIndex(void) {
    return (gKillerItemKartIndex);
}

void SetKillerItemKartIndex(u32 kartIndex) {
    gKillerItemKartIndex = kartIndex;
}

// Keeps the smallest value of the frame; UpdateKarts clears it.
void SetMinKartDistanceSquared(s32 distanceSquared) {
    if (gMinKartDistanceSquared < 0 || distanceSquared < gMinKartDistanceSquared) {
        gMinKartDistanceSquared = distanceSquared;
        gMinKartDistanceSquaredPresent = 1;
    }
}

BOOL TryGetMinKartDistanceSquared(s32 *distanceSquared) {
    if (gMinKartDistanceSquaredPresent == 0) {
        return FALSE;
    }
    *distanceSquared = gMinKartDistanceSquared;
    return TRUE;
}

BOOL func_0207a218(void) {
    BOOL result = TRUE;
    s32 mode = gRaceMultiConfig->mMode;
    if (mode == MODE_MISSION_RUN) {
        Kart *kart = &sDrivers[gRaceMultiConfig->mEntryIndex];
        if (kart->mState != KART_STATE_NORMAL || (kart->field48 & 0x2000840) != 0 ||
            (kart->field44 & KART_44_ON_GROUND) == 0 || (mode != MODE_MISSION_RUN ? 0 : func_ov001_021816b4()) != 0) {
            result = FALSE;
        }
    }
    return result;
}

void ConfigureFullNSBMDColors(NNSG3dResMdl *mdl, u32 colorSet) {
    u32 diffColor;
    u32 ambColor;
    u32 specColor;
    u32 emiColor;
    switch (colorSet) {
        case 0: {
            u16 *courseColors = gCharKartData->mCourseColors;
            diffColor = courseColors[0];
            ambColor = courseColors[1];
            specColor = courseColors[2];
            emiColor = courseColors[3];
            break;
        }
        case 2:
            ambColor = 0;
            specColor = 0;
            emiColor = 0;
            diffColor = 0x2108;
            break;
        case 3:
            ambColor = 0;
            specColor = 0;
            diffColor = 0x2108;
            emiColor = 0x4210;
            break;
        case 1:
            diffColor = 0x7fff;
            ambColor = 0x14a5;
            emiColor = 0x2108;
            specColor = 0;
            break;
    }
    NNS_G3dMdlSetMdlDiffAll(mdl, diffColor);
    NNS_G3dMdlSetMdlAmbAll(mdl, ambColor);
    NNS_G3dMdlSetMdlSpecAll(mdl, specColor);
    NNS_G3dMdlSetMdlEmiAll(mdl, emiColor);
}

u16 chkrt_getKartCrsMatDiffuse(void) {
    return gCharKartData->mCourseColors[0];
}

u16 chkrt_getKartCrsMatEmission(void) {
    return gCharKartData->mCourseColors[3];
}

u16 chkrt_getKartCrsMatAmbient(void) {
    return gCharKartData->mCourseColors[1];
}

void chkrt_setTargetColors(struct KartModelsEntry *kartModelsEntry, u16 targetDiffColor, u16 targetEmiColor,
                              u16 targetAmbColor) {
    KartModelColorBlend *blend;

    blend = &kartModelsEntry->mColorBlend;
    blend->field6 = kartModelsEntry->mColorBlend.mDiffColor & 0x1f;
    blend->fieldC = (s16) (targetDiffColor & 0x1f) - blend->field6;
    blend->field8 = (kartModelsEntry->mColorBlend.mDiffColor >> 5) & 0x1f;
    blend->fieldE = (s16) ((targetDiffColor >> 5) & 0x1f) - blend->field8;
    blend->fieldA = (kartModelsEntry->mColorBlend.mDiffColor >> 10) & 0x1f;
    blend->field10 = (s16) ((targetDiffColor >> 10) & 0x1f) - blend->fieldA;
    blend->field12 = blend->mEmiColor & 0x1f;
    blend->field18 = (s16) (targetEmiColor & 0x1f) - blend->field12;
    blend->field14 = (blend->mEmiColor >> 5) & 0x1f;
    blend->field1A = (s16) ((targetEmiColor >> 5) & 0x1f) - blend->field14;
    blend->field16 = (blend->mEmiColor >> 10) & 0x1f;
    blend->field1C = (s16) ((targetEmiColor >> 10) & 0x1f) - blend->field16;
    blend->field1E = blend->mAmbColor & 0x1f;
    blend->field24 = (s16) (targetAmbColor & 0x1f) - blend->field1E;
    blend->field20 = (blend->mAmbColor >> 5) & 0x1f;
    blend->field26 = (s16) ((targetAmbColor >> 5) & 0x1f) - blend->field20;
    blend->field22 = (blend->mAmbColor >> 10) & 0x1f;
    blend->field28 = (s16) ((targetAmbColor >> 10) & 0x1f) - blend->field22;
    blend->mBlendProgress = 0;
}

s32 chkrt_progressColorInterpolation(struct KartModelsEntry *kartModelsEntry, s32 blendAmount) {
    KartModelColorBlend *blend = &kartModelsEntry->mColorBlend;
    BOOL finished = FALSE;

    if (blend->mBlendProgress < 0x1000) {
        blend->mBlendProgress += blendAmount;
        if (blend->mBlendProgress >= 0x1000) {
            blend->mBlendProgress = 0x1000;
            finished = TRUE;
        }
        blend->mDiffColor =
            (s16) (blend->field6 + (s32) (((s64) blend->fieldC * blend->mBlendProgress + 0x800) >> 12)) +
            ((s16) (blend->field8 + (s32) (((s64) blend->fieldE * blend->mBlendProgress + 0x800) >> 12)) << 5) +
            ((s16) (blend->fieldA + (s32) (((s64) blend->field10 * blend->mBlendProgress + 0x800) >> 12)) << 10);
        NNS_G3dMdlSetMdlDiffAll(kartModelsEntry->mModels[0]->mResMdl, blend->mDiffColor);
        NNS_G3dMdlSetMdlDiffAll(kartModelsEntry->mModels[1]->mResMdl, blend->mDiffColor);
        if (kartModelsEntry->mModels[2] != NULL) {
            NNS_G3dMdlSetMdlDiffAll(kartModelsEntry->mModels[2]->mResMdl, blend->mDiffColor);
        }
        blend->mEmiColor =
            (s16) (blend->field12 + (s32) (((s64) blend->field18 * blend->mBlendProgress + 0x800) >> 12)) +
            ((s16) (blend->field14 + (s32) (((s64) blend->field1A * blend->mBlendProgress + 0x800) >> 12)) << 5) +
            ((s16) (blend->field16 + (s32) (((s64) blend->field1C * blend->mBlendProgress + 0x800) >> 12)) << 10);
        NNS_G3dMdlSetMdlEmiAll(kartModelsEntry->mModels[0]->mResMdl, blend->mEmiColor);
        NNS_G3dMdlSetMdlEmiAll(kartModelsEntry->mModels[1]->mResMdl, blend->mEmiColor);
        if (kartModelsEntry->mModels[2] != NULL) {
            NNS_G3dMdlSetMdlEmiAll(kartModelsEntry->mModels[2]->mResMdl, blend->mEmiColor);
        }
        {
            s16 x = blend->field1E + (s32) (((s64) blend->field24 * blend->mBlendProgress + 0x800) >> 12);
            s16 y = blend->field20 + (s32) (((s64) blend->field26 * blend->mBlendProgress + 0x800) >> 12);
            s16 z = blend->field22 + (s32) (((s64) blend->field28 * blend->mBlendProgress + 0x800) >> 12);
            NNS_G3dMdlSetMdlAmbAll(kartModelsEntry->mModels[0]->mResMdl, blend->mAmbColor);
            NNS_G3dMdlSetMdlAmbAll(kartModelsEntry->mModels[1]->mResMdl, blend->mAmbColor);
            if (kartModelsEntry->mModels[2] != NULL) {
                NNS_G3dMdlSetMdlAmbAll(kartModelsEntry->mModels[2]->mResMdl, blend->mAmbColor);
            }
            blend->mAmbColor = x + (y << 5) + (z << 10);
        }
    } else {
        finished = TRUE;
    }
    return finished;
}

void chkrt_applyKartCrsMat(struct KartModelsEntry *kartModelsEntry) {
    u16 *courseColors = gCharKartData->mCourseColors;
    u32 diffColor;
    u32 emiColor;
    u32 ambColor;

    diffColor = courseColors[0];
    emiColor = courseColors[3];
    ambColor = courseColors[1];
    NNS_G3dMdlSetMdlDiffAll(kartModelsEntry->mModels[0]->mResMdl, diffColor);
    NNS_G3dMdlSetMdlDiffAll(kartModelsEntry->mModels[1]->mResMdl, diffColor);
    NNS_G3dMdlSetMdlEmiAll(kartModelsEntry->mModels[0]->mResMdl, emiColor);
    NNS_G3dMdlSetMdlEmiAll(kartModelsEntry->mModels[1]->mResMdl, emiColor);
    NNS_G3dMdlSetMdlAmbAll(kartModelsEntry->mModels[0]->mResMdl, ambColor);
    NNS_G3dMdlSetMdlAmbAll(kartModelsEntry->mModels[1]->mResMdl, ambColor);
    if (kartModelsEntry->mModels[2] != NULL) {
        NNS_G3dMdlSetMdlDiffAll(kartModelsEntry->mModels[2]->mResMdl, diffColor);
        NNS_G3dMdlSetMdlEmiAll(kartModelsEntry->mModels[2]->mResMdl, emiColor);
        NNS_G3dMdlSetMdlAmbAll(kartModelsEntry->mModels[2]->mResMdl, ambColor);
    }
}

KartModelsEntry *chkrt_getCharKart(u32 kartIndex) {
    return &gCharKartData->mKartModelsEntries[kartIndex];
}

void *chkrt_getKartResMdl(u32 kartIndex) {
    return gCharKartData->mKartModelsEntries[kartIndex].mModels[1]->mResMdl;
}

// Shows (b non-zero) or hides the tire material of the kart model.
void chkrt_setKartTireVisibility(struct KartModelsEntry *kartModelsEntry, s32 visible) {
    NNS_G3dMdlSetMdlAlpha(kartModelsEntry->mModels[1]->mResMdl, gCharKartData->mKartTireMaterialIndex,
                          visible != 0 ? 0x1f : 0);
}

void *chkrt_getKillerItemModel(void) {
    return &gCharKartData->mKillerItem;
}

void *chkrt_getKillerItemShadowModel(void) {
    return &gCharKartData->mKillerItemS;
}

void *chkrt_getKillerItemAnim(void) {
    return &gCharKartData->mKillerItemNsbca;
}

u32 chkrt_getKartABC(u32 kartIndex) {
    return gCharKartData->mKartModelsEntries[kartIndex].mVariant;
}

#pragma thumb on
void chkrt_initCharKart(void *entry) {
    u32 value0 = (u32) entry;
    u32 value1;
    u32 value2;
    u32 entryAddress;
    entryAddress = (value0) + (0u);
    value0 = 0u;
    value1 = ~(value0);
    *(u32 *) ((entryAddress) + 0u) = value1;
    *(u32 *) ((entryAddress) + 4u) = value1;
    *(u32 *) ((entryAddress) + 8u) = value0;
    *(u32 *) ((entryAddress) + 12u) = value0;
    *(u32 *) ((entryAddress) + 16u) = value0;
    *(u32 *) ((entryAddress) + 20u) = value0;
    *(u32 *) ((entryAddress) + 24u) = value0;
    *(u32 *) ((entryAddress) + 28u) = value0;
    *(u32 *) ((entryAddress) + 32u) = value0;
    value0 = (entryAddress) + (0u);
    value0 = (value0) + 36u;
    func_02079a04(value0);
    value0 = 0u;
    *(u32 *) ((entryAddress) + 84u) = value0;
    *(u32 *) ((entryAddress) + 88u) = value0;
    *(u32 *) ((entryAddress) + 92u) = value0;
    *(u32 *) ((entryAddress) + 96u) = value0;
    *(u32 *) ((entryAddress) + 100u) = value0;
    value1 = (entryAddress) + (0u);
    value1 = (value1) + 104u;
    *(u16 *) ((value1) + 0u) = value0;
    value1 = (entryAddress) + (0u);
    value1 = (value1) + 172u;
    *(u32 *) ((value1) + 0u) = value0;
    value1 = (entryAddress) + (0u);
    value1 = (value1) + 176u;
    *(u32 *) ((value1) + 0u) = value0;
    value1 = (entryAddress) + (0u);
    value1 = (value1) + 110u;
    *(u16 *) ((value1) + 0u) = value0;
    value1 = (entryAddress) + (0u);
    value1 = (value1) + 110u;
    value2 = *(const u16 *) ((value1) + 0u);
    value1 = (entryAddress) + (0u);
    value1 = (value1) + 108u;
    *(u16 *) ((value1) + 0u) = value2;
    value1 = (entryAddress) + (0u);
    value1 = (value1) + 108u;
    value2 = *(const u16 *) ((value1) + 0u);
    value1 = (entryAddress) + (0u);
    value1 = (value1) + 106u;
    *(u16 *) ((value1) + 0u) = value2;
    value1 = (entryAddress) + (0u);
    value1 = (value1) + 116u;
    *(u16 *) ((value1) + 0u) = value0;
    value1 = 116u;
    value2 = *(const s16 *) ((entryAddress) + (value1));
    value1 = (entryAddress) + (0u);
    value1 = (value1) + 114u;
    *(u16 *) ((value1) + 0u) = value2;
    value1 = 114u;
    value2 = *(const s16 *) ((entryAddress) + (value1));
    value1 = (entryAddress) + (0u);
    value1 = (value1) + 112u;
    *(u16 *) ((value1) + 0u) = value2;
    value1 = (entryAddress) + (0u);
    value1 = (value1) + 122u;
    *(u16 *) ((value1) + 0u) = value0;
    value1 = 122u;
    value2 = *(const s16 *) ((entryAddress) + (value1));
    value1 = (entryAddress) + (0u);
    value1 = (value1) + 120u;
    *(u16 *) ((value1) + 0u) = value2;
    value1 = 120u;
    value2 = *(const s16 *) ((entryAddress) + (value1));
    value1 = (entryAddress) + (0u);
    value1 = (value1) + 118u;
    *(u16 *) ((value1) + 0u) = value2;
    value1 = (entryAddress) + (0u);
    value1 = (value1) + 128u;
    *(u16 *) ((value1) + 0u) = value0;
    value1 = 128u;
    value2 = *(const s16 *) ((entryAddress) + (value1));
    value1 = (entryAddress) + (0u);
    value1 = (value1) + 126u;
    *(u16 *) ((value1) + 0u) = value2;
    value1 = 126u;
    value2 = *(const s16 *) ((entryAddress) + (value1));
    value1 = (entryAddress) + (0u);
    value1 = (value1) + 124u;
    *(u16 *) ((value1) + 0u) = value2;
    value1 = (entryAddress) + (0u);
    value1 = (value1) + 134u;
    *(u16 *) ((value1) + 0u) = value0;
    value1 = 134u;
    value2 = *(const s16 *) ((entryAddress) + (value1));
    value1 = (entryAddress) + (0u);
    value1 = (value1) + 132u;
    *(u16 *) ((value1) + 0u) = value2;
    value1 = 132u;
    value2 = *(const s16 *) ((entryAddress) + (value1));
    value1 = (entryAddress) + (0u);
    value1 = (value1) + 130u;
    *(u16 *) ((value1) + 0u) = value2;
    value1 = (entryAddress) + (0u);
    value1 = (value1) + 140u;
    *(u16 *) ((value1) + 0u) = value0;
    value1 = 140u;
    value2 = *(const s16 *) ((entryAddress) + (value1));
    value1 = (entryAddress) + (0u);
    value1 = (value1) + 138u;
    *(u16 *) ((value1) + 0u) = value2;
    value1 = 138u;
    value2 = *(const s16 *) ((entryAddress) + (value1));
    value1 = (entryAddress) + (0u);
    value1 = (value1) + 136u;
    *(u16 *) ((value1) + 0u) = value2;
    value1 = (entryAddress) + (0u);
    value1 = (value1) + 146u;
    *(u16 *) ((value1) + 0u) = value0;
    value1 = 146u;
    value2 = *(const s16 *) ((entryAddress) + (value1));
    value1 = (entryAddress) + (0u);
    value1 = (value1) + 144u;
    *(u16 *) ((value1) + 0u) = value2;
    value1 = 144u;
    value2 = *(const s16 *) ((entryAddress) + (value1));
    value1 = (entryAddress) + (0u);
    value1 = (value1) + 142u;
    *(u16 *) ((value1) + 0u) = value2;
    entryAddress = (entryAddress) + 148u;
    *(u16 *) ((entryAddress) + 0u) = value0;
}
#pragma thumb off

#pragma thumb on

void func_02079a14(KartModelsEntry *kartModelsEntry) {
    anim_initAnimatorLoop((ModelAnimation *) kartModelsEntry->field98,
                               anim_getAnimLength(&gCharKartData->mKillerItemNsbca));
}

#pragma thumb off

#pragma thumb on
void func_02079a04(u32 animationStateAddress) {
    u32 animationState = animationStateAddress;
    u32 zero;
    zero = 0u;
    *(u32 *) ((animationState) + 0u) = zero;
    *(u32 *) ((animationState) + 20u) = zero;
    *(u16 *) ((animationState) + 24u) = zero;
    *(u32 *) ((animationState) + 4u) = zero;
    *(u16 *) ((animationState) + 16u) = zero;
}
#pragma thumb off

#pragma thumb on

// TRUE when the entry's character files use the P name list.
BOOL chkrt_getIsPlayer(s32 kartIndex) {
    BOOL pNameUsed = TRUE;
    s32 b = pNameUsed;
    s32 c = pNameUsed;
    s32 isEntryOrFollowedKart = pNameUsed;
    if (kartIndex != gRaceMultiConfig->mEntryIndex && kartIndex != gRaceMultiConfig->mFollowedKartIndex) {
        isEntryOrFollowedKart = 0;
    }
    if (isEntryOrFollowedKart == 0 && gRaceMultiConfig->mMode != MODE_MISSION_RUN) {
        c = 0;
    }
    if (c == 0 && race_isAwardStaffRoll() == 0) {
        b = 0;
    }
    if (b == 0 && gRaceMultiConfig->mMode != MODE_TIME_ATTACK) {
        pNameUsed = FALSE;
    }
    if (pNameUsed != FALSE) {
        return 1;
    }
    return 0;
}

#pragma thumb off

#pragma thumb on

// Stores the kart index modulo 3.
void chkrt_setKartABC(KartModelsEntry *kartModelsEntry, int kartIndex) {
    u16 variant;
    variant = kartIndex % 3;
    kartModelsEntry->mVariant = variant;
}

#pragma thumb off

#pragma thumb on

void chkrt_init(void *heap, u32 kartCount) {
    u8 *kartOffsetFile;
    u16 i;
    KartModelsEntry *entry;
    KartModelsEntry *entries;
    kartOffsetFile = arc_getKartModelArcFile("kartoffsetdata.bin");
    cklcr_setLoadFromFolder(0);
    gCharKartSelectState = NULL;
    gCharKartData = heap_alloc(heap, 0x144);
    gCharKartData->mKartModelsEntries = heap_alloc(heap, kartCount * 0xb4);
    gCharKartData->mCourseColors = arc_getKartModelArcFileSafe("kartcrsmat.bin");
    gCharKartData->mCourseColors = gCharKartData->mCourseColors + (gRaceMultiConfig->mCourseId << 2) - 4;
    gCharKartData->mKartAPalette = loadStandardKartPaletteFromKartModelArc();
    gCharKartData->mHeyhoPalettes = NULL;
    gCharKartData->mPFaceanimNsbtpFile = arc_getKartModelArcFileSafe((const char *) cklcr_getFaceAnimPath());
    gCharKartData->mKartCount = kartCount;
    gCharKartData->mKartTireMaterialIndex = 0;
    physp_init(heap, kartCount);
    loadKartAIParams();
    loadKillerItem(heap);
    for (i = 0; i < gCharKartData->mKartCount; i++) {
        entries = gCharKartData->mKartModelsEntries;
        entry = &entries[i];
        chkrt_initCharKart(entry);
        entry->fieldB0 = gRaceMultiConfig->mCurrentEntries[i].mPlayer.field25;
        func_02079a14(entry);
        entries[i].mCharacterIndex = gRaceMultiConfig->mCurrentEntries[i].mCharacterIndex;
        entry->mKartIndex = gRaceMultiConfig->mCurrentEntries[i].mKartIndex;
        chkrt_setKartABC(entry, entry->mKartIndex);
        entry->mKartOffsetData = heap_alloc(heap, 0xe0);
        MI_CpuCopy8(kartOffsetFile + entry->mKartIndex * 0xe0, entry->mKartOffsetData, 0xe0);
        physp_initForDriver(i, (u16) entry->mKartIndex, (u16) entries[i].mCharacterIndex);
    }
    loadDrivers(heap, 1);
    arc_switchKartModelMainAtoB();
    loadDrivers(heap, 0);
    for (i = 0; i < gCharKartData->mKartCount; i++) {
        entry = &gCharKartData->mKartModelsEntries[i];
        PatchROBPalette(entry, chkrt_getIsPlayer(i));
    }
    {
        Nclr *nclr;
        g2du_unpackPaletteData(&nclr, arc_getKartModelArcFileSafe("/character/heyho/HH_color.NCLR"));
        gCharKartData->mHeyhoPalettes = (HeyhoPalette *) nclr->mData;
    }
}

void loadDrivers(void *heap, s32 firstPass) {
    BOOL isVariantZero;
    KartModelsEntry *entry;
    s32 pNameUsed;
    u16 j;
    BOOL f;
    s32 g;
    u16 i;
    s32 characterRangeStart;
    s32 characterRangeEnd;
    s32 kartRangeStart;
    s32 kartRangeEnd;
    Vec3 *dst;
    Vec3 *src;
    if (firstPass != 0) {
        characterRangeStart = 0;
        characterRangeEnd = 7;
        kartRangeStart = characterRangeStart;
        kartRangeEnd = 0x15;
    } else {
        characterRangeStart = 7;
        characterRangeEnd = 0xd;
        kartRangeStart = 0x15;
        kartRangeEnd = 0x25;
    }
    i = 0;
    if (i < gCharKartData->mKartCount) {
        g = (firstPass == 0) ? 1 : i;
        do {
            entry = &gCharKartData->mKartModelsEntries[i];
            pNameUsed = chkrt_getIsPlayer(i);
            if ((u16) entry->mKartIndex % 3 == 0) {
                isVariantZero = TRUE;
            } else {
                isVariantZero = FALSE;
            }
            f = (isVariantZero != FALSE && g != 0) ? TRUE : FALSE;
            if (entry->mCharacterIndex >= characterRangeStart && entry->mCharacterIndex < characterRangeEnd) {
                loadCharacter(entry, heap, pNameUsed);
            }
            if (f == FALSE) {
                if ((isVariantZero != FALSE && firstPass != 0) ||
                    (entry->mKartIndex >= kartRangeStart && entry->mKartIndex < kartRangeEnd)) {
                    loadKart(entry, heap, pNameUsed);
                }
            }
            if (firstPass != 0) {
                if (pNameUsed != 0) {
                    j = 0;
                    entry->field54 = heap_alloc(heap, 0x30);
                    do {
                        dst = &entry->field54->mUnk_v[j];
                        src = &entry->mKartOffsetData->field14[j];
                        dst->x = src->x >> 4;
                        dst->y = src->y >> 4;
                        dst->z = src->z >> 4;
                        j++;
                    } while (j < 4);
                    entry->field54->mUnk_v[1].x =
                        FX_Div(-entry->field54->mUnk_v[0].x * 2, entry->mKartOffsetData->field10);
                    entry->field54->mUnk_v[3].x = -entry->field54->mUnk_v[2].x * 2;
                    loadKartTire(entry, heap);
                }
                loadKartShadow(entry, heap);
            }
            i++;
        } while (i < gCharKartData->mKartCount);
    }
}

void loadCharacter(KartModelsEntry *kartModelsEntry, void *heap, s32 pNameUsed) {
    u16 i;
    u16 characterIndex;
    BOOL hasFirstAnimation;
    void *nsbmdFile;
    NNSG3dResFileHeader *nsbtxFile;
    NNSG3dResMdl *mdl;
    void *animationFile;
    characterIndex = kartModelsEntry->mCharacterIndex;
    nsbmdFile = arc_getKartModelArcFileSafe(cklcr_getCharacterNsbmdPath(characterIndex, pNameUsed));
    nsbtxFile = arc_getKartModelArcFile(cklcr_getCharacterNsbtxPath(characterIndex, pNameUsed));
    kartModelsEntry->mModels[0] = heap_alloc(heap, 0x6c);
    mdl = model_initFromNsbmdNsbtxMetaCopy(heap, kartModelsEntry->mModels[0], nsbmdFile, nsbtxFile);
    model_setPolygonId(kartModelsEntry->mModels[0], 3);
    ConfigureFullNSBMDColors(mdl, 0);
    if (pNameUsed != 0) {
        i = 0;
        hasFirstAnimation = FALSE;
        kartModelsEntry->mCharacterAnimation = heap_alloc(heap, 0x38);
        anim_initManager(0, kartModelsEntry->mCharacterAnimation, kartModelsEntry->mModels[0], 4, heap, NULL);
        do {
            animationFile = arc_getKartModelArcFileSafe(GetCharacterNsbcaPath(characterIndex, i));
            if (animationFile != NULL) {
                void *jointAnimation = NNS_G3dGetJntAnmByIdx(NNS_G3dGetJntAnmSet(animationFile), 0);
                anim_registerAnim(kartModelsEntry->mCharacterAnimation, i, jointAnimation,
                                        GetCharacterAnimationLoopFlag(i), heap);
                if (i == 0) {
                    hasFirstAnimation = TRUE;
                }
            }
            i++;
        } while (i < 4);
        if (hasFirstAnimation != FALSE) {
            anim_setAnim(kartModelsEntry->mCharacterAnimation, 0);
            kartModelsEntry->mMiddleFrame =
                (anim_getAnimLength(kartModelsEntry->mCharacterAnimation) - 0x1000) / 2;
            kartModelsEntry->mMiddleFrameReciprocal = FX_Div(0x1000, kartModelsEntry->mMiddleFrame);
        } else {
            kartModelsEntry->mCharacterAnimation->field18 = 0;
        }
    }
    kartModelsEntry->mFaceAnimation = heap_alloc(heap, 0x38);
    anim_initManager(2, kartModelsEntry->mFaceAnimation, kartModelsEntry->mModels[0], 1, heap, NULL);
    anim_registerAllAnims(kartModelsEntry->mFaceAnimation, gCharKartData->mPFaceanimNsbtpFile, heap);
    anim_setAnim(kartModelsEntry->mFaceAnimation, 0);
}

void loadKart(KartModelsEntry *kartModelsEntry, void *heap, s32 pNameUsed) {
    u16 kartIndex = kartModelsEntry->mKartIndex;
    void *nsbmdFile;
    NNSG3dResFileHeader *nsbtxFile;
    NNSG3dResMdl *mdl;
    s32 tireMaterialIndex;
    nsbmdFile = arc_getKartModelArcFileSafe(cklcr_getKartNsbmdPath(kartIndex));
    nsbtxFile = arc_getKartModelArcFile(cklcr_getKartNsbtxPath(kartIndex));
    kartModelsEntry->mModels[1] = heap_alloc(heap, 0x6c);
    mdl = model_initFromNsbmdNsbtxMetaCopy(heap, kartModelsEntry->mModels[1], nsbmdFile, nsbtxFile);
    model_setPolygonId(kartModelsEntry->mModels[1], 3);
    ConfigureFullNSBMDColors(mdl, 0);
    if (pNameUsed != 0) {
        tireMaterialIndex = NNS_G3dGetResDictIdxByName((u8 *) mdl + mdl->mOfsMat + 4, aKart_tire_1);
        NNS_G3dMdlSetMdlAlpha(mdl, tireMaterialIndex, 0);
        gCharKartData->mKartTireMaterialIndex = tireMaterialIndex;
    }
    UploadKartAPaletteSlice(kartModelsEntry->mModels[1], kartModelsEntry->mKartIndex, gCharKartData->mKartAPalette);
}

u16 *loadStandardKartPaletteFromKartModelArc(void) {
    Nclr *nclr;
    g2du_unpackPaletteData(&nclr, arc_getKartModelArcFileSafe("/kart/palette/kart_a.NCLR"));
    return nclr->mData;
}

u16 *LoadKartPaletteInKartModelMenuFolder(void *heap) {
    void *file;
    Nclr *nclr;
    LoadFileInKartModelMenuFolder(heap, "kart/palette/kart_a.NCLR", &file);
    g2du_unpackPaletteData(&nclr, file);
    return nclr->mData;
}

void UploadKartAPaletteSlice(Nsbmd *nsbmd, s32 kartIndex, void *kartAPalette) {
    u8 *mdlBytes;
    u8 *q;
    u8 *t;
    u8 *paletteSlice;
    s32 materialIndex;
    u32 paletteBase;
    if (kartIndex % 3 == 0) {
        mdlBytes = (u8 *) nsbmd->mResMdl;
        paletteSlice = (u8 *) kartAPalette + kartIndex / 3 * 0x20;
        DC_FlushRange(paletteSlice, 0x10);
        materialIndex = NNS_G3dGetResDictIdxByName(mdlBytes + *(s32 *) (mdlBytes + 8) + 4, aKart_body_1);
        q = mdlBytes + *(s32 *) (mdlBytes + 8);
        t = q + 4 + *OFFSET_PTR(u16, q, 0xa);
        paletteBase = *(u16 *) (q + *(s32 *) (t + *(u16 *) t * materialIndex + 4) + 0x1c) << 4;
        GX_BeginLoadTexPltt();
        GX_LoadTexPltt(paletteSlice, paletteBase, 0x10);
        GX_EndLoadTexPltt();
    }
}

void PatchROBPalette(KartModelsEntry *kartModelsEntry, s32 pNameUsed) {
    u8 *c;
    u32 k;
    u32 m;
    u8 *h;
    u8 *mdlBytes;
    u8 *q;
    u8 *t;
    u8 *e;
    u8 *f;
    u8 *g;
    s32 j;
    s32 i;
    if (kartModelsEntry->fieldB0 != 0) {
        if ((u32) (kartModelsEntry->mKartIndex - 0x22) <= 1) {
            c = NULL;
            mdlBytes = (u8 *) kartModelsEntry->mModels[1]->mResMdl;
            switch (kartModelsEntry->mKartIndex) {
                case 0x22:
                    c = ROB_BLS_Palette;
                    break;
                case 0x23:
                    c = ROB_LGS_Palette;
                    break;
            }
            i = NNS_G3dGetResDictIdxByName(mdlBytes + *(s32 *) (mdlBytes + 8) + 4, aKart_body);
            q = mdlBytes + *(s32 *) (mdlBytes + 8);
            t = q + 4 + *OFFSET_PTR(u16, q, 0xa);
            e = q + *(s32 *) (t + *(u16 *) t * i + 4);
            data_0217ad0c = e;
            k = *OFFSET_PTR(u16, e, 0x1c) << 4;
            GX_BeginLoadTexPltt();
            GX_LoadTexPltt(c, k, 0x20);
            GX_EndLoadTexPltt();
        }
        if (kartModelsEntry->mCharacterIndex == 0xb) {
            mdlBytes = (u8 *) kartModelsEntry->mModels[0]->mResMdl;
            if (pNameUsed != 0) {
                i = NNS_G3dGetResDictIdxByName(mdlBytes + *(s32 *) (mdlBytes + 8) + 4, aP_main);
                j = NNS_G3dGetResDictIdxByName(mdlBytes + *(s32 *) (mdlBytes + 8) + 4, aP_face);
                c = data_02155128;
                h = data_02155148;
                m = 0x40;
            } else {
                i = NNS_G3dGetResDictIdxByName(mdlBytes + *(s32 *) (mdlBytes + 8) + 4, aE_main);
                j = NNS_G3dGetResDictIdxByName(mdlBytes + *(s32 *) (mdlBytes + 8) + 4, aE_face);
                c = data_021550c8;
                h = data_02154fe8;
                m = 0x10;
            }
            q = mdlBytes + *(s32 *) (mdlBytes + 8);
            t = q + 4;
            e = q + *(s32 *) ((t = t + *OFFSET_PTR(u16, q, 0xa)) + *(u16 *) t * j + 4);
            f = q + *(s32 *) (t + *(u16 *) t * i + 4);
            g = (u8 *) (*OFFSET_PTR(u16, f, 0x1c) << 4);
            GX_BeginLoadTexPltt();
            GX_LoadTexPltt(c, (u32) g, 0x20);
            GX_EndLoadTexPltt();
            g = (u8 *) (*OFFSET_PTR(u16, e, 0x1c) << 4);
            GX_BeginLoadTexPltt();
            GX_LoadTexPltt(h, (u32) g, m);
            GX_EndLoadTexPltt();
        }
    }
}

void loadKartTire(KartModelsEntry *kartModelsEntry, void *heap) {
    u16 kartIndex = kartModelsEntry->mKartIndex;
    void *nsbmdFile;
    NNSG3dResMdl *mdl;
    NNSG3dResFileHeader *nsbtxFile;
    nsbmdFile = arc_getKartModelArcFileSafe(cklcr_getTireNsbmdPath(kartIndex, kartModelsEntry->mKartOffsetData->field0));
    nsbtxFile = arc_getKartModelArcFile(cklcr_getTireNsbtxPath(kartIndex, kartModelsEntry->mKartOffsetData->field0));
    kartModelsEntry->mModels[2] = heap_alloc(heap, 0x6c);
    mdl = model_initFromNsbmdNsbtxMetaCopy(heap, kartModelsEntry->mModels[2], nsbmdFile, nsbtxFile);
    model_setPolygonId(kartModelsEntry->mModels[2], 3);
    ConfigureFullNSBMDColors(mdl, 0);
}

void loadKartShadow(KartModelsEntry *kartModelsEntry, void *heap) {
    void *nsbmdFile;
    u8 *mdlSet;
    nsbmdFile = arc_getKartModelArcFileSafe(cklcr_getKartShadowPath(kartModelsEntry->mKartIndex));
    kartModelsEntry->mShadowModel = heap_alloc(heap, 0x74);
    model_resSetNsbmdNsbtx(&kartModelsEntry->mShadowModel->mNsbmd.mResFileEntry, nsbmdFile, nsbmdFile);
    mdlSet = (u8 *) NNS_G3dGetMdlSet(nsbmdFile);
    InitShadowModelFromResMdl(&kartModelsEntry->mShadowModel->mNsbmd,
                              mdlSet + *(s32 *) (mdlSet + *OFFSET_PTR(u16, mdlSet, 0xe) + 0xc), 3);
}

void loadKillerItem(void *heap) {
    void *nsbmdFile = arc_getKartModelArcFileSafe("character/common/KillerItem.nsbmd");
    NNSG3dResFileHeader *nsbtxFile = arc_getKartModelArcFile("character/common/KillerItem.nsbtx");
    void *shadowNsbmdFile = arc_getKartModelArcFileSafe("character/common/KillerItem_s.nsbmd");
    void *nsbcaFile;
    ConfigureFullNSBMDColors(model_initFromNsbmdNsbtxMetaCopy(heap, &gCharKartData->mKillerItem, nsbmdFile, nsbtxFile), 0);
    model_setPolygonId(&gCharKartData->mKillerItem, 3);
    nsbcaFile = arc_getKartModelArcFileSafe("character/common/KillerItem.nsbca");
    anim_initManager(0, &gCharKartData->mKillerItemNsbca, &gCharKartData->mKillerItem, 1, heap, nsbmdFile);
    anim_registerAllAnims(&gCharKartData->mKillerItemNsbca, nsbcaFile, heap);
    anim_setAnim(&gCharKartData->mKillerItemNsbca, 0);
    InitShadowModel(&gCharKartData->mKillerItemS, shadowNsbmdFile, 3);
    driver_setupKillerItemRenderObjCallback(&gCharKartData->mKillerItem);
}

void LoadFileInKartModelMenuFolder(void *heap, const void *fileName, void **file) {
    char path[0x100];
    snprintf(path, 0x100, "/data/KartModelMenu/%s", fileName);
    arc_loadFile(path, heap, file);
}

void func_020790e0(void *heap, s32 createKartAppear) {
    if (createKartAppear != 0) {
        gCharKartSelectState->mUseEmblemTex = FALSE;
        gCharKartSelectState->mKartAppear = CreateKartAppear(heap);
    } else {
        gCharKartSelectState->mUseEmblemTex = TRUE;
    }
    gCharKartSelectState->mKartAPalette = LoadKartPaletteInKartModelMenuFolder(heap);
    gCharKartSelectState->mSelectModel = NULL;
}

#pragma thumb off

#pragma thumb on

void anim_2079078(void *heap, Nsbmd *nsbmd, void *animation, NNSG3dResFileHeader *modelFile,
                                  NNSG3dResFileHeader *textureFile, void *animationFile) {
    NNSG3dResMdl *mdl;
    u32 loopFlag;
    void *jointAnimation;
    mdl = model_initFromNsbmdNsbtx(nsbmd, modelFile, textureFile);
    model_setPolygonId(nsbmd, 3);
    ConfigureFullNSBMDColors(mdl, 1);
    anim_initManager(0, animation, nsbmd, 1, heap, NULL);
    jointAnimation = NNS_G3dGetJntAnmByIdx(NNS_G3dGetJntAnmSet(animationFile), 0);
    loopFlag = GetCharacterAnimationLoopFlag(2);
    anim_registerAnim(animation, 0, jointAnimation, loopFlag, heap);
    anim_setAnim(animation, 0);
}

void CreateKartModelMenuKart(Nsbmd *nsbmd, NNSG3dResFileHeader *modelFile, NNSG3dResFileHeader *textureFile) {
    NNSG3dResMdl *mdl;
    u32 tireMaterialIndex;
    mdl = model_initFromNsbmdNsbtx(nsbmd, modelFile, textureFile);
    model_setPolygonId(nsbmd, 3);
    ConfigureFullNSBMDColors(mdl, 1);
    tireMaterialIndex = NNS_G3dGetResDictIdxByName((u8 *) mdl + mdl->mOfsMat + 4, aKart_tire);
    NNS_G3dMdlSetMdlAlpha(mdl, tireMaterialIndex, 0);
}

void CreateKartModelMenuTire(Nsbmd *nsbmd, NNSG3dResFileHeader *modelFile, NNSG3dResFileHeader *textureFile) {
    NNSG3dResMdl *mdl;
    mdl = model_initFromNsbmdNsbtx(nsbmd, modelFile, textureFile);
    model_setPolygonId(nsbmd, 3);
    ConfigureFullNSBMDColors(mdl, 1);
}

#pragma thumb off

#pragma thumb on

void *CreateKartModelMenuShadow(void *shadowModel, NNSG3dResFileHeader *modelFile) {
    return InitShadowModel(shadowModel, modelFile, 3);
}

void LoadSelectModel(void *heap) {
    void *modelFile;
    void *textureFile;
    LoadFileInKartModelMenuFolder(heap, aKartSelectSele, &modelFile);
    LoadFileInKartModelMenuFolder(heap, aKartSelectSe_0, &textureFile);
    gCharKartSelectState->mSelectModel = heap_alloc(heap, 0x6c);
    model_initFromNsbmdNsbtx(gCharKartSelectState->mSelectModel, modelFile, textureFile);
    model_setPolygonId(gCharKartSelectState->mSelectModel, 2);
    NNS_G3dMdlSetMdlXLDepthUpdateAll(gCharKartSelectState->mSelectModel->mResMdl, 1);
}

#pragma thumb off

#pragma thumb on

void LoadKartModelMenuEmblemTexData(NNSG3dResFileHeader *file) {
    gCharKartSelectState->mEmblemTex = NNS_G3dGetTex(file);
    NNS_G3dResDefaultSetup(file);
}

void InitKartModelMenuSlot(void *heap, KartModelMenuSlot *slot) {
    chkrt_initCharKart(slot);
    slot->fieldB0 = gSystemData->field0;
    slot->mEmblemTex = 0;
    slot->mCharacterNsbmd = heap_alloc(heap, 0x6c);
    slot->mKartNsbmd = heap_alloc(heap, 0x6c);
    slot->mTireNsbmd = heap_alloc(heap, 0x6c);
    slot->mShadowModel = heap_alloc(heap, 0x74);
    slot->mCharacterAnimation = heap_alloc(heap, 0x38);
}

void InitKartModelMenuView(KartModelMenuView *view, int b) {
    u32 bg0Offset;
    bg0Offset = 0;
    view->mCharacterIndex = 0xffffffff;
    view->mKartIndex = 0xffffffff;
    view->mScale = 0x1000;
    view->mYawAngle = 0xeaab;
    view->mSpinAngle = view->mYawAngle;
    view->field18 = 0;
    view->fieldC = 0;
    view->field10 = 0xffffff88;
    if (b != 0) {
        bg0Offset = 0xffffff06;
    }
    view->mBg0Offset = bg0Offset;
    view->mBg0Direction = 0;
}

#pragma thumb off

#pragma thumb on

void QueueKartEmblemTexture(void *emblemData, void *emblemPalette) {
    NNSG3dResMdl *mdl;
    u8 *t;
    u8 *u;
    u8 *w;
    s32 materialIndex;
    s32 paletteBase;
    NNSG3dResMatData *material;
    KartModelMenuData *menu = gCharKartSelectState;
    KartModelMenuFiles *files = &menu->mFiles[menu->mLoadSlotIndex];
    s16 shownSlotIndex = menu->mShownSlotIndex;
    if (shownSlotIndex >= 0 && files->mLoadRequested == FALSE) {
        mdl = menu->mSlots[shownSlotIndex].mKartNsbmd->mResMdl;
        materialIndex = NNS_G3dGetResDictIdxByName((u8 *) mdl + mdl->mOfsMat + 4, aKart_emblem);
        t = (u8 *) mdl + mdl->mOfsMat;
        u = t + 4;
        w = u + *OFFSET_PTR(u16, t, 0xa);
        material = (NNSG3dResMatData *) (t + *(u32 *) (w + *(u16 *) w * materialIndex + 4));
        paletteBase = material->mTexPlttBase << 4;
        NNS_GfdRegisterNewVramTransferTask(0, (material->mTexImageParam & 0xffff) << 3, emblemData, 0x200);
        NNS_GfdRegisterNewVramTransferTask(1, paletteBase, emblemPalette, 0x20);
    }
}

void SPM_InitCharacterKartSelect(void *heap) {
    u32 i;
    arc_setHeapGroupId(1);
    race_initG3d();
    NNS_G3dGeUseFastDma(0);
    gSystemData->field1C &= ~8;
    SPM_InitVramManager(heap);
    model_initResList();
    cklcr_setLoadFromFolder(1);
    InitKartModelMenu(heap);
    func_020790e0(heap, 0);
    LoadFileInKartModelMenuFolder(heap, aCharmenuparam_, (void **) &gCharKartSelectState->mCharMenuParams);
    LoadFileInKartModelMenuFolder(heap, aKartmenuparam_, (void **) &gCharKartSelectState->mKartMenuParams);
    LoadSelectModel(heap);
    for (i = 0; i < 2; i = (u16) (i + 1)) {
        InitKartModelMenuFiles(heap, &gCharKartSelectState->mFiles[i]);
    }
    if (gSaveData->mEmblemRecord->mFilled != 0 && gSaveData->mFirstBlock->field31_3 == 0) {
        gCharKartSelectState->mEmblemData = gSaveData->mEmblemRecord->mEmblemData;
        gCharKartSelectState->mEmblemPalette = GetEmblemSBNclr()->mData;
    }
    arc_setHeapGroupId(9);
}

void func_02078c58(void *heap) {
    u32 i;
    enum { K0 } kartIndex;
    s32 characterIndex;
    arc_setHeapGroupId(1);
    race_initG3d();
    NNS_G3dGeUseFastDma(0);
    gSystemData->field1C &= ~8;
    SPM_InitVramManager(heap);
    model_initResList();
    cklcr_setLoadFromFolder(1);
    InitKartModelMenu(heap);
    func_020790e0(heap, 1);
    kartIndex = 0;
    gCharKartSelectState->mKartIndex = kartIndex;
    gCharKartSelectState->mKartListCount = kartIndex;
    gCharKartSelectState->mKartListPos = kartIndex;
    while (kartIndex < 0x24) {
        if (func_02077a70(&characterIndex, kartIndex) != 0) {
            gCharKartSelectState->mKartListCount++;
        }
        kartIndex++;
    }
    gCharKartSelectState->mView.mScale = data_021656e0;
    for (i = 0; i < 2; i = (u16) (i + 1)) {
        InitKartModelMenuFiles(heap, &gCharKartSelectState->mFiles[i]);
    }
    gCharKartSelectState->mFiles[gCharKartSelectState->mLoadSlotIndex].mLoadRequested = TRUE;
    gCharKartSelectState->mView.mCharacterIndex = 0;
    gCharKartSelectState->mView.mKartIndex = 0;
    gCharKartSelectState->mLoadSlot->mCharacterIndex = 0;
    gCharKartSelectState->mLoadSlot->mKartIndex = 0;
    gCharKartSelectState->mLoadSlot->mKartOffsetData = gCharKartSelectState->mKartOffsetTable;
    SPM_2077D68();
    AdvanceKartModelMenuLoad();
    InitKartModelMenuView(&gCharKartSelectState->mView, 0);
    arc_setHeapGroupId(9);
}

void InitKartModelMenu(void *heap) {
    u32 i;
    gCharKartData = NULL;
    gCharKartSelectState = heap_alloc(heap, 0x26c);
    gCharKartSelectState->mShownSlotIndex = -1;
    gCharKartSelectState->mLoadSlotIndex = 0;
    gCharKartSelectState->mLoadSlot = &gCharKartSelectState->mSlots[gCharKartSelectState->mLoadSlotIndex];
    gCharKartSelectState->mKartAPalette = NULL;
    gCharKartSelectState->field1DC = FALSE;
    gCharKartSelectState->field1D8 = 0;
    gCharKartSelectState->mMirrorMode = 0;
    gCharKartSelectState->mCharMenuParams = NULL;
    gCharKartSelectState->mKartMenuParams = NULL;
    gCharKartSelectState->mCharacterRequested = 0;
    gCharKartSelectState->mKartRequested = 0;
    gCharKartSelectState->mKartAppear = NULL;
    gCharKartSelectState->field1F0 = 0;
    gCharKartSelectState->mEmblemPalette = NULL;
    gCharKartSelectState->mEmblemData = gCharKartSelectState->mEmblemPalette;
    LoadEmblemSBNclr(heap);
    LoadFileInKartModelMenuFolder(heap, aKartoffsetdata, (void **) &gCharKartSelectState->mKartOffsetTable);
    for (i = 0; i < 2; i = (u16) (i + 1)) {
        InitKartModelMenuSlot(heap, &gCharKartSelectState->mSlots[i]);
    }
    InitKartModelMenuView(&gCharKartSelectState->mView, 1);
    arc_setHeapGroupId(9);
}

s16 *spm_LoadCharKartParam(s32 kartIndex, s32 characterIndex) {
    KartModelMenuData *menu = gCharKartSelectState;
    s16 *characterParam = &menu->mCharMenuParams[characterIndex];
    KartMenuParams *kartParams = &menu->mKartMenuParams[kartIndex];
    menu->mMenuParams[0] = kartParams->field0[0];
    menu->mMenuParams[1] = kartParams->field0[1];
    menu->mMenuParams[2] = kartParams->field0[2];
    menu->mMenuParams[3] = kartParams->field0[3];
    menu->mMenuParams[4] = kartParams->field0[4];
    menu->mMenuParams[5] = kartParams->field0[5];
    menu->mMenuParams[2] += *characterParam;
    return gCharKartSelectState->mMenuParams;
}

// Asks for a new character in the menu view; -1 clears it at once.
void RequestKartModelMenuCharacter(s32 characterIndex) {
    KartModelMenuData *menu = gCharKartSelectState;
    KartModelMenuView *view = &menu->mView;
    KartModelMenuFiles *files = &menu->mFiles[menu->mLoadSlotIndex];
    s32 currentCharacterIndex = view->mCharacterIndex;
    s32 c = -1;
    KartModelMenuSlot *slots;
    KartModelMenuSlot *shownSlot;
    if (characterIndex == c) {
        slots = menu->mSlots;
        shownSlot = &slots[menu->mShownSlotIndex];
        view->mCharacterIndex = characterIndex;
        shownSlot->mCharacterIndex = c;
        return;
    }
    if (files->mLoadRequested == FALSE && currentCharacterIndex != characterIndex && characterIndex <= 0xd) {
        view->mCharacterIndex = characterIndex;
        gCharKartSelectState->mCharacterRequested = 1;
    }
}

void RequestKartModelMenuKart(s32 kartIndex) {
    KartModelMenuData *menu = gCharKartSelectState;
    KartModelMenuView *view = &menu->mView;
    KartModelMenuFiles *files = &menu->mFiles[menu->mLoadSlotIndex];
    s32 currentKartIndex = view->mKartIndex;
    s32 c = -1;
    KartModelMenuSlot *slots;
    KartModelMenuSlot *shownSlot;
    if (kartIndex == c) {
        slots = menu->mSlots;
        shownSlot = &slots[menu->mShownSlotIndex];
        view->mKartIndex = kartIndex;
        shownSlot->mKartIndex = c;
        return;
    }
    if (files->mLoadRequested == FALSE && currentKartIndex != kartIndex && kartIndex <= 0x25) {
        view->mKartIndex = kartIndex;
        gCharKartSelectState->mKartRequested = 1;
    }
}

void AdvanceKartModelMenuBg0Offset(void) {
    KartModelMenuView *view = &gCharKartSelectState->mView;
    switch (view->mBg0Direction) {
        case 0:
            view->mBg0Offset += 0x15;
            if (view->mBg0Offset > -0x2e) {
                view->mBg0Offset = -0x2e;
            }
            break;
        case 1:
            view->mBg0Offset -= 0x15;
            if (view->mBg0Offset < -0xfa) {
                view->mBg0Offset = -0xfa;
            }
            break;
    }
}

void StartKartModelMenuBg0Increase(void) {
    gCharKartSelectState->mView.mBg0Direction = 0;
}

void StartKartModelMenuBg0Decrease(void) {
    gCharKartSelectState->mView.mBg0Direction = 1;
}

void SetFrustumProjection(s32 mirrored) {
    s32 e;
    s32 d;
    s32 c;
    s32 b;
    s32 a;
    a = ((s64) FX_Div(0x579, 0xf09) * 0x200) >> 12;
    b = -a;
    c = ((s64) b * 0x1555) >> 12;
    d = -c;
    e = d;
    if (mirrored != 0) {
        e = -d;
        c = d;
    }
    NNS_G3dGeBufferOP_N(0x15, NULL, 0);
    G3i_FrustumW_(a, b, c, e, 0x200, 0x64000, 0x1000, 0, (Unk0214ad4c *) NNS_G3dGlb.mProjMtx);
    NNS_G3dGlb.mFlag &= ~0x50;
    NNS_G3dGlbFlushP();
}

void SetupLightFrustumAndLookAt(s32 param_1, s32 yOffset) {
    Vec3 lightDirection;
    Vec3 e;
    Vec3 d;
    Vec3 b;
    Vec3 c;
    NNS_G3dGlbFlushP();
    lightDirection = data_02165708;
    if ((s64) lightDirection.z * lightDirection.z +
            ((s64) lightDirection.x * lightDirection.x + (s64) lightDirection.y * lightDirection.y) >=
        0x10) {
        vec_normalize(&lightDirection, &lightDirection);
    }
    NNS_G3dGlbLightVector(0, (s16) lightDirection.x, (s16) lightDirection.y, (s16) lightDirection.z);
    NNS_G3dGlbLightColor(0, (u16) (data_021656d8 | (data_021656d8 << 5) | (data_021656d8 << 10)));
    SetFrustumProjection(0);
    b = data_02155188;
    c = data_021656f0;
    c.y += yOffset;
    VEC_Subtract(&c, &data_021656fc, &d);
    VEC_CrossProduct(&b, &d, &e);
    data_021704dc[0] = data_021656fc;
    data_021704dc[1] = e;
    data_021704dc[2] = c;
    G3i_LookAt_(&data_021656fc, &e, &c, 0, &NNS_G3dGlb.mCameraMtx);
    NNS_G3dGlb.mFlag &= ~0xe8;
    NNS_G3dGlbFlushP();
}

void RenderCharacterForMenu(KartModelMenuSlot *slot, KartModelMenuView *view, s32 mirrored) {
    Vec3 scale;
    s32 m1[9];
    s32 m2[9];
    MtxFx43 m3;
    Vec3 t;
    Vec3 u;
    Vec3 w;
    Vec3 *e;
    s32 k;
    u16 i;

    NNS_G3dGlb.mPrmViewPort = 0xbfff0000;
    t.x = data_021656f0.x;
    t.y = data_021656f0.y;
    t.z = data_021656f0.z;
    k = FX_MulFunc(data_021656e4, view->mScale);
    scale.x = k;
    scale.y = k;
    scale.z = k;
    MTX_RotY33_(m1, FX_SinCosTable_[(view->mYawAngle >> 4) * 2], FX_SinCosTable_[(view->mYawAngle >> 4) * 2 + 1]);
    MTX_RotX33_(m2, FX_SinCosTable_[(((u16) (data_021656dc + view->field1A)) >> 4) * 2],
                FX_SinCosTable_[(((u16) (data_021656dc + view->field1A)) >> 4) * 2 + 1]);
    MTX_Concat33(m1, m2, m1);
    if (slot->mKartOffsetData != NULL) {
        MTX_Copy33To43_(m1, &m3.field0[0].x);
        m3.field0[3] = t;
        MTX_ScaleApply43(&m3, &m3, scale.x, scale.y, scale.z);
    } else {
        MTX_Identity43_(&m3);
    }
    NNS_G3dGlbSetBaseScale(&scale);
    NNS_G3dGlbSetBaseTrans(&t);
    MI_Copy36B(m2, NNS_G3dGlb.mPrmBaseRot);
    NNS_G3dGlb.mFlag &= ~0xa4;
    NNS_G3dGlbFlushP();
    if (gCharKartSelectState->mSelectModel != NULL) {
        NNS_G3dDraw(gCharKartSelectState->mSelectModel);
    }
    MI_Copy36B(m1, NNS_G3dGlb.mPrmBaseRot);
    NNS_G3dGlb.mFlag &= ~0xa4;
    NNS_G3dGlbSetBaseTrans(&t);
    NNS_G3dGlbFlushP();
    if (slot->mCharacterIndex != -1 && slot->mKartIndex != -1) {
        SetFrustumProjection(mirrored);
        if (slot->mShadowModel != NULL) {
            if (mirrored != 0) {
                slot->mShadowModel->mNsbmd.mCullModesSwapped = 1;
            } else {
                slot->mShadowModel->mNsbmd.mCullModesSwapped = 0;
            }
            ((void (*)(ShadowModel *)) DrawShadowModel)(slot->mShadowModel);
        }
        if (slot->mKartNsbmd != NULL) {
            if (mirrored != 0) {
                model_setCullFront(slot->mKartNsbmd);
            } else {
                model_setCullBack(slot->mKartNsbmd);
            }
            NNS_G3dDraw(slot->mKartNsbmd);
        }
        if (slot->mTireNsbmd != NULL) {
            for (i = 0; i < 4; i++) {
                if (i < 2) {
                    k = slot->mKartOffsetData->field10;
                    w.x = ((s64) scale.x * k) >> 12;
                    w.y = ((s64) scale.y * k) >> 12;
                    w.z = ((s64) scale.z * k) >> 12;
                } else {
                    w = scale;
                }
                if (i != 1 || slot->mKartOffsetData->field14[0].x != 0) {
                    e = &slot->mKartOffsetData->field14[i];
                    u.x = e->x >> 4;
                    u.y = e->y >> 4;
                    u.z = e->z >> 4;
                    MTX_MultVec43(&u, &m3, &t);
                    NNS_G3dGlbSetBaseScale(&w);
                    NNS_G3dGlbSetBaseTrans(&t);
                    NNS_G3dGlbFlushP();
                    if (mirrored != 0) {
                        model_setCullFront(slot->mTireNsbmd);
                    } else {
                        model_setCullBack(slot->mTireNsbmd);
                    }
                    NNS_G3dDraw(slot->mTireNsbmd);
                }
            }
        }
        if (slot->mCharacterNsbmd != NULL) {
            MTX_MultVec43(&slot->mKartOffsetData->field44[slot->mCharacterIndex], &m3, &t);
            NNS_G3dGlbSetBaseTrans(&t);
            NNS_G3dGlbFlushP();
            if (mirrored != 0) {
                model_setCullFront(slot->mCharacterNsbmd);
            } else {
                model_setCullBack(slot->mCharacterNsbmd);
            }
            NNS_G3dDraw(slot->mCharacterNsbmd);
        }
    }
}

#pragma thumb off

#pragma thumb on

void SPM_UpdateKartEmblem(KartModelMenuSlot *slot) {
    if ((gCharKartSelectState->mUseEmblemTex != FALSE) && (slot->mEmblemTex != NULL)) {
        NNS_G3dReleaseMdlTexEx(slot->mKartNsbmd->mResMdl, aEmblem);
        NNS_G3dReleaseMdlPlttEx(slot->mKartNsbmd->mResMdl, aEmblem_pl);
        NNS_G3dBindMdlTexEx(slot->mKartNsbmd->mResMdl, slot->mEmblemTex, aEmblem);
        NNS_G3dBindMdlPlttEx(slot->mKartNsbmd->mResMdl, slot->mEmblemTex, aEmblem_pl);
    }
}

#pragma thumb off

#pragma thumb on

void SPM_2078420(s32 mirrorMode) {
    KartModelMenuView *view;
    KartModelMenuSlot *shownSlot;
    view = &gCharKartSelectState->mView;
    gCharKartSelectState->mMirrorMode = mirrorMode;
    SPM_2077B3C();
    AdvanceKartModelMenuBg0Offset();
    if (gCharKartSelectState->mShownSlotIndex >= 0) {
        shownSlot = &gCharKartSelectState->mSlots[gCharKartSelectState->mShownSlotIndex];
        if (gCharKartSelectState->field1D8 != 0 || gCharKartSelectState->field1DC != FALSE) {
            AdvanceAngleToward(&view->mSpinAngle, 0xeaab, data_021656e8);
            if (gCharKartSelectState->field1D8 == 0 && gCharKartSelectState->field1DC != FALSE) {
                gCharKartSelectState->field1F0++;
                if (gCharKartSelectState->field1F0 > 0x3c) {
                    gCharKartSelectState->field1DC = FALSE;
                }
            }
        } else {
            view->mSpinAngle += 0x64;
        }
        view->mYawAngle = mirrorMode != 0 ? (u16) -view->mSpinAngle : view->mSpinAngle;
        anim_update(shownSlot->mCharacterAnimation);
        if (gCharKartSelectState->mEmblemData != NULL && gCharKartSelectState->mEmblemPalette != NULL &&
            gCharKartSelectState->mFiles[gCharKartSelectState->mLoadSlotIndex].mLoadRequested == FALSE) {
            QueueKartEmblemTexture(gCharKartSelectState->mEmblemData, gCharKartSelectState->mEmblemPalette);
        }
    }
    ClearKartModelMenuRequests();
}

void AdvanceShownSlotAndQueueEmblem(void) {
    s16 shownSlotIndex = gCharKartSelectState->mShownSlotIndex;
    if (shownSlotIndex >= 0) {
        anim_update(gCharKartSelectState->mSlots[shownSlotIndex].mCharacterAnimation);
        if (gCharKartSelectState->mFiles[gCharKartSelectState->mLoadSlotIndex].mLoadRequested == FALSE) {
            QueueKartEmblemTexture(func_ov001_021a2398(), func_ov001_021a23ac());
        }
    }
}

void AdvanceKartModelMenuInput(void) {
    KartModelMenuView *view = &gCharKartSelectState->mView;
    s32 a = 0;
    BOOL b;
    s32 d;
    s32 characterIndex;
    u16 buttons;
    InputSlotIndex v1;
    s32 v = 2;
    KartModelMenuFiles *files;

    files = &gCharKartSelectState->mFiles[gCharKartSelectState->mLoadSlotIndex];
    if (gBgWkrState->mRunRequested == 0 && files->mLoadRequested == FALSE) {
        characterIndex = ~a;
        v1 = UNK_02175628_INDEX_8;
        buttons = gInputUnits[v1].mPressedBits;
        if ((u16) (buttons & PAD_KEY_R) != 0) {
            d = a;
            do {
                gCharKartSelectState->mKartIndex++;
                if (gCharKartSelectState->mKartIndex > 0x23) {
                    gCharKartSelectState->mKartIndex = a;
                }
                if (func_02077a70(&characterIndex, gCharKartSelectState->mKartIndex) != 0) {
                    RequestKartModelMenuCharacter(characterIndex);
                    RequestKartModelMenuKart(gCharKartSelectState->mKartIndex);
                    d = 1;
                    NNS_SndArcPlayerStartSeqArc(&data_0217d068, a, 0x1fd);
                }
            } while (d == 0);
            gCharKartSelectState->mKartListPos++;
            if (gCharKartSelectState->mKartListPos >= gCharKartSelectState->mKartListCount) {
                gCharKartSelectState->mKartListPos = 0;
            }
        } else if ((u16) (buttons & PAD_KEY_L) != 0) {
            d = a;
            do {
                gCharKartSelectState->mKartIndex--;
                if (gCharKartSelectState->mKartIndex < 0) {
                    gCharKartSelectState->mKartIndex = 0x23;
                }
                if (func_02077a70(&characterIndex, gCharKartSelectState->mKartIndex) != 0) {
                    RequestKartModelMenuCharacter(characterIndex);
                    RequestKartModelMenuKart(gCharKartSelectState->mKartIndex);
                    d = 1;
                    NNS_SndArcPlayerStartSeqArc(&data_0217d068, a, 0x1fe);
                }
            } while (d == 0);
            gCharKartSelectState->mKartListPos--;
            if (gCharKartSelectState->mKartListPos < 0) {
                gCharKartSelectState->mKartListPos = gCharKartSelectState->mKartListCount - 1;
            }
        }
    }
    b = FALSE;
    d = b;
    GetSndHandleSlot(2);
    v1 = UNK_02175628_INDEX_8;
    buttons = gInputUnits[v1].mBits;
    if ((u16) (buttons & PAD_KEY_RIGHT) != 0) {
        view->mYawAngle += 0x1c2;
        b = TRUE;
    } else if ((u16) (buttons & PAD_KEY_LEFT) != 0) {
        view->mYawAngle -= 0x1c2;
        b = TRUE;
    }
    v1 = UNK_02175628_INDEX_8;
    buttons = gInputUnits[v1].mBits;
    if ((u16) (buttons & PAD_KEY_DOWN) != 0) {
        view->field18 += 0x1c2;
        if (view->field18 > 0x1b58) {
            view->field18 = 0x1b58;
        } else {
            d = 1;
        }
    } else if ((u16) (buttons & PAD_KEY_UP) != 0) {
        view->field18 -= 0x1c2;
        if (view->field18 < -0x1388) {
            view->field18 = -0x1388;
        } else {
            d = 1;
        }
    }
    if (d != 0 || b != FALSE) {
        a = 1;
    }
    GetSndHandleSlot(1);
    v1 = UNK_02175628_INDEX_8;
    buttons = gInputUnits[v1].mBits;
    if ((u16) (buttons & PAD_KEY_X) != 0) {
        view->mScale += 0x7b;
        if (view->mScale > data_021656e0) {
            view->mScale = data_021656e0;
        } else {
            v = 0;
        }
    } else {
        v1 = UNK_02175628_INDEX_8;
        buttons = gInputUnits[v1].mBits;
        if ((u16) (buttons & PAD_KEY_B) != 0) {
            view->mScale -= 0x7b;
            if (view->mScale < 0x800) {
                view->mScale = 0x800;
            } else {
                v = 1;
            }
        }
    }
    view->field1A = view->field18;
    func_02110aac(v, a);
    SPM_2077B3C();
    ClearKartModelMenuRequests();
}

void SPM_RenderCharacterSelect3D(void) {
    KartModelMenuSlot *slot;
    KartModelMenuView *view;
    if (gCharKartSelectState->mShownSlotIndex >= 0) {
        slot = &gCharKartSelectState->mSlots[gCharKartSelectState->mShownSlotIndex];
        view = &gCharKartSelectState->mView;
        if (view->mCharacterIndex != -1 && view->mKartIndex != -1) {
            SetupLightFrustumAndLookAt(view->mBg0Offset, data_021656ec);
            RenderCharacterForMenu(slot, &gCharKartSelectState->mView, gCharKartSelectState->mMirrorMode);
            NNS_G3dGeFlushBuffer();
        }
    }
}

void DrawKartModelMenuUnmirrored(void) {
    KartModelMenuSlot *slot;
    if (gCharKartSelectState->mShownSlotIndex >= 0) {
        slot = &gCharKartSelectState->mSlots[gCharKartSelectState->mShownSlotIndex];
        SetupLightFrustumAndLookAt(0, data_021656ec);
        RenderCharacterForMenu(slot, &gCharKartSelectState->mView, 0);
        NNS_G3dGeFlushBuffer();
    }
}

void chkrt_setupHeyhoPaletteRows(void) {
    u16 i;
    for (i = 0; i < 8; i++) {
        gCharKartData->mHeyhoPaletteIndices[i] = gStruct217B488->mShuffledIndices[i];
    }
}

void chkrt_applyAllHeyhoPalettes(void) {
    u32 i;
    if (gCharKartData->mHeyhoPalettes != NULL) {
        chkrt_setupHeyhoPaletteRows();
        for (i = 0; i < gRaceMultiConfig->mKartCount; i = (u16) (i + 1)) {
            if (gCharKartData->mKartModelsEntries[i].mCharacterIndex == 0xc) {
                chkrt_applyHeyhoPalette(i, &gCharKartData->mKartModelsEntries[i], chkrt_getHeyhoPaletteRow(i));
            }
        }
    }
}

void chkrt_applyHeyhoPalette(int kartIndex, struct KartModelsEntry *kartModelsEntry, HeyhoPalette *palette) {
    NNSG3dResMdl *mdl;
    u8 *t;
    u8 *u;
    u8 *w;
    s32 materialIndex;
    s32 paletteBase;
    mdl = kartModelsEntry->mModels[0]->mResMdl;
    DC_FlushRange(palette, 0x20);
    if (chkrt_getIsPlayer(kartIndex) != 0) {
        materialIndex = NNS_G3dGetResDictIdxByName((u8 *) mdl + mdl->mOfsMat + 4, aP_main_1);
    } else {
        materialIndex = NNS_G3dGetResDictIdxByName((u8 *) mdl + mdl->mOfsMat + 4, aE_main_1);
    }
    t = (u8 *) mdl + mdl->mOfsMat;
    u = t + 4;
    w = u + *OFFSET_PTR(u16, t, 0xa);
    paletteBase = ((NNSG3dResMatData *) (t + *(u32 *) (w + *(u16 *) w * materialIndex + 4)))->mTexPlttBase << 4;
    GX_BeginLoadTexPltt();
    GX_LoadTexPltt(palette, paletteBase, 0x20);
    GX_EndLoadTexPltt();
}

HeyhoPalette *chkrt_getHeyhoPaletteRow(int kartIndex) {
    HeyhoPalette *palette = NULL;
    if (gCharKartData->mHeyhoPalettes != NULL) {
        palette = gCharKartData->mHeyhoPalettes + gCharKartData->mHeyhoPaletteIndices[kartIndex];
    }
    return palette;
}

void func_02077f5c(void) {
    gCharKartSelectState->field1DC = TRUE;
    gCharKartSelectState->field1F0 = 0;
}

#pragma thumb off

#pragma thumb on

void func_02077f48(u32 flag) {
    gCharKartSelectState->field1D8 = flag;
}

// Moves *a toward b by a share of the distance plus 100; keeps the old value when the step would reach b.
void AdvanceAngleToward(u16 *angle, int targetAngle, u32 easeFactor) {
    u16 oldAngle;
    int change;
    int difference;
    oldAngle = *angle;
    difference = targetAngle - oldAngle;
    if (difference < 0) {
        difference = 0xffff - difference;
    }
    change = FX_MulFunc(difference, easeFactor);
    *angle = *angle + change;
    if (((*angle + 100) - targetAngle) < 0) {
        *angle = *angle + 100;
        return;
    }
    *angle = oldAngle;
}

#pragma thumb off

#pragma thumb on

Nclr *GetEmblemSBNclr(void) {
    return gEmblemSBNclr;
}

#pragma thumb off

#pragma thumb on

void InitKartModelMenuFiles(void *heap, KartModelMenuFiles *files) {
    void *heapMemory;
    struct NNSiFndHeapHead *expHeap;
    heapMemory = heap_alloc(heap, 0xf000);
    expHeap = NNS_FndCreateExpHeapEx(heapMemory, 0xf000, 0);
    files->mHeap = expHeap;
    files->mHeapMemory = heapMemory;
    files->mEmblemNsbtxFile = NULL;
    files->mCharacterNsbtxFile = files->mEmblemNsbtxFile;
    files->mCharacterNsbmdFile = files->mCharacterNsbtxFile;
    files->mKartNsbtxFile = NULL;
    files->mKartNsbmdFile = files->mKartNsbtxFile;
    files->mCharacterNsbcaFile = files->mKartNsbmdFile;
    files->mKartShadowNsbmdFile = NULL;
    files->mTireNsbtxFile = files->mKartShadowNsbmdFile;
    files->mTireNsbmdFile = files->mTireNsbtxFile;
    files->mLoadRequested = FALSE;
    files->mLoadStep = 0;
}

#pragma thumb off

#pragma thumb on

void SPM_2077D68(void) {
    KartModelMenuFiles *files;
    s32 characterIndex;
    KartModelMenuFiles *loadFiles;
    s32 kartIndex;
    s32 loadSlotIndex;
    char *tireName;

    files = gCharKartSelectState->mFiles;
    loadSlotIndex = gCharKartSelectState->mLoadSlotIndex;
    loadFiles = &files[loadSlotIndex];
    characterIndex = gCharKartSelectState->mLoadSlot->mCharacterIndex;
    kartIndex = gCharKartSelectState->mLoadSlot->mKartIndex;
    loadFiles->mLoadStep = 0;
    NNS_FndDestroyExpHeap(loadFiles->mHeap);
    loadFiles->mHeap = NNS_FndCreateExpHeapEx(loadFiles->mHeapMemory, 0xf000, 0);
    if (characterIndex != -1 && loadFiles->mCharacterNsbmdFile != NULL) {
        NNS_G3dResDefaultRelease(loadFiles->mCharacterNsbmdFile);
        NNS_G3dResDefaultRelease(loadFiles->mCharacterNsbtxFile);
        NNS_G3dResDefaultRelease(loadFiles->mEmblemNsbtxFile);
        NNS_G3dResDefaultRelease(loadFiles->mKartNsbmdFile);
        NNS_G3dResDefaultRelease(loadFiles->mKartNsbtxFile);
        NNS_G3dResDefaultRelease(loadFiles->mTireNsbmdFile);
        NNS_G3dResDefaultRelease(loadFiles->mTireNsbtxFile);
        NNS_G3dResDefaultRelease(loadFiles->mKartShadowNsbmdFile);
    }
    tireName = (char *) &gCharKartSelectState->mKartOffsetTable[kartIndex];
    arc_loadFile(cklcr_getCharacterNsbmdPath(characterIndex, 1), loadFiles->mHeap,
                     (void **) &loadFiles->mCharacterNsbmdFile);
    arc_loadFile(cklcr_getCharacterNsbtxPath(characterIndex, 1), loadFiles->mHeap,
                     (void **) &loadFiles->mCharacterNsbtxFile);
    arc_loadFile(GetCharacterNsbcaPath(characterIndex, 2), loadFiles->mHeap, &loadFiles->mCharacterNsbcaFile);
    arc_loadFile(cklcr_getCharacterEmblemPath(characterIndex), loadFiles->mHeap, (void **) &loadFiles->mEmblemNsbtxFile);
    arc_loadFile(cklcr_getKartNsbmdPath(kartIndex), loadFiles->mHeap, (void **) &loadFiles->mKartNsbmdFile);
    arc_loadFile(cklcr_getKartNsbtxPath(kartIndex), loadFiles->mHeap, (void **) &loadFiles->mKartNsbtxFile);
    arc_loadFile(cklcr_getKartShadowPath(kartIndex), loadFiles->mHeap, (void **) &loadFiles->mKartShadowNsbmdFile);
    arc_loadFile(cklcr_getTireNsbmdPath(kartIndex, tireName), loadFiles->mHeap, (void **) &loadFiles->mTireNsbmdFile);
    arc_loadFile(cklcr_getTireNsbtxPath(kartIndex, tireName), loadFiles->mHeap, (void **) &loadFiles->mTireNsbtxFile);
}

// Builds the slot being loaded over three calls, then shows it and loads into the other slot next.
void AdvanceKartModelMenuLoad(void) {
    KartModelMenuFiles *loadFiles;
    KartModelMenuSlot *loadSlot;
    KartModelMenuSlot *shownSlot;
    KartModelAnimationView *animation;

    G3X_SetHOffset(gCharKartSelectState->mView.mBg0Offset);
    if (gBgWkrState->mRunRequested == 0) {
        loadFiles = &gCharKartSelectState->mFiles[gCharKartSelectState->mLoadSlotIndex];
        if (loadFiles->mLoadRequested != FALSE) {
            loadSlot = gCharKartSelectState->mLoadSlot;
            if (loadFiles->mLoadStep == 0) {
                anim_2079078(loadFiles->mHeap, loadSlot->mCharacterNsbmd, loadSlot->mCharacterAnimation,
                                             loadFiles->mCharacterNsbmdFile, loadFiles->mCharacterNsbtxFile,
                                             loadFiles->mCharacterNsbcaFile);
                loadFiles->mLoadStep++;
                return;
            }
            if (loadFiles->mLoadStep == 1) {
                LoadKartModelMenuEmblemTexData(loadFiles->mEmblemNsbtxFile);
                gCharKartSelectState->mLoadSlot->mEmblemTex = gCharKartSelectState->mEmblemTex;
                CreateKartModelMenuShadow(loadSlot->mShadowModel, loadFiles->mKartShadowNsbmdFile);
                CreateKartModelMenuTire(loadSlot->mTireNsbmd, loadFiles->mTireNsbmdFile, loadFiles->mTireNsbtxFile);
                loadFiles->mLoadStep++;
                return;
            }
            CreateKartModelMenuKart(loadSlot->mKartNsbmd, loadFiles->mKartNsbmdFile, loadFiles->mKartNsbtxFile);
            SPM_UpdateKartEmblem(gCharKartSelectState->mLoadSlot);
            UploadKartAPaletteSlice(loadSlot->mKartNsbmd, loadSlot->mKartIndex, gCharKartSelectState->mKartAPalette);
            PatchROBPalette((struct KartModelsEntry *) loadSlot, 1);
            loadFiles->mLoadRequested = FALSE;
            loadFiles->mLoadStep = 0;
            if (gCharKartSelectState->mShownSlotIndex >= 0) {
                shownSlot = &gCharKartSelectState->mSlots[gCharKartSelectState->mShownSlotIndex];
                if (loadSlot->mCharacterIndex == shownSlot->mCharacterIndex) {
                    animation = loadSlot->mCharacterAnimation;
                    animation->fieldC = shownSlot->mCharacterAnimation->fieldC;
                    *animation->field1C[animation->field1A] = animation->fieldC;
                }
            }
            gCharKartSelectState->mShownSlotIndex = gCharKartSelectState->mLoadSlotIndex;
            gCharKartSelectState->mLoadSlotIndex = gCharKartSelectState->mLoadSlotIndex == 0 ? 1 : 0;
            gCharKartSelectState->mLoadSlot = &gCharKartSelectState->mSlots[gCharKartSelectState->mLoadSlotIndex];
        }
    }
}

#pragma thumb off

#pragma thumb on

void SPM_InitVramManager(void *heap) {
    u32 texWorkSize;
    u32 plttWorkSize;
    RangeEntry *texWork;
    RangeEntry *plttWork;
    texWorkSize = NNS_GfdGetLnkTexVramManagerWorkSize(0x20);
    plttWorkSize = NNS_GfdGetLnkPlttVramManagerWorkSize(0x20);
    texWork = heap_alloc(heap, texWorkSize);
    plttWork = heap_alloc(heap, plttWorkSize);
    NNS_GfdInitLnkTexVramManager(0x00040000u, 0x00020000u, texWork, texWorkSize, 1);
    NNS_GfdInitLnkPlttVramManager(0x00010000u, plttWork, plttWorkSize, 1);
}

#pragma thumb off
